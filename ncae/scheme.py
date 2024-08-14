import warnings

import os
import json

from ncae.audio import Audio
from ncae.decrypt import read_encfile, NCAEDecryptor
from ncae.plugins.convolve import NCAEPluginConvolve
from ncae.plugins.bt import NCAEPluginBT
from ncae.plugins.eq import NCAEPluginEQ
from ncae.plugins.reverb import NCAEPluginReverb
from ncae.plugins.se import NCAEPluginSE


class NCAEScheme:

    def __init__(self, filename: str):

        self.filename = filename
        self.raw = None
        self.ext = None
        self.plugins = []

        key, data = read_encfile(filename)
        decryptor = NCAEDecryptor(key)
        self.raw = decryptor.decrypt(data)

        try:
            d = json.loads(self.raw.decode("utf-8"))
            if d["bt"]["on"]:
                self.plugins.append(NCAEPluginBT(d["bt"]))
            if d["eq"]["on"]:
                self.plugins.append(NCAEPluginEQ(d["eq"]))
            if d["rvb"]["on"]:
                self.plugins.append(NCAEPluginReverb(d["rvb"]))
            if d["se"]["on"]:
                self.plugins.append(NCAEPluginSE(d["se"]))
            self.ext = ".json"
        except:
            try:
                self.plugins.append(NCAEPluginConvolve(self.raw))
                self.ext = ".wav"
            except:
                warnings.warn("Unrecognized format")
                self.ext = ".bin"

    def _applyto(self, audio: Audio):

        for plugin in self.plugins:
            plugin.applyto(audio)

    def export(self, filename: str = "", fmt=False):

        filename = filename if filename else self.filename
        if os.path.dirname(filename):
            os.makedirs(os.path.dirname(filename), exist_ok=True)

        base, ext = os.path.splitext(filename)
        if ext[-1] != self.ext:
            warnings.warn(
                f"File extension mismatch, fallback to auto-detect ({self.ext})"
            )
        filename = base + self.ext

        if self.ext == ".json":
            self._export_formatted_json(filename)
            return
        if fmt:
            if self.ext == ".wav":
                self._export_formatted_wav(filename)
                return
            else:
                warnings.warn("Raw binary data cannot be formatted")

        with open(filename, "wb") as fout:
            fout.write(self.raw)

    def _export_formatted_json(self, filename: str):

        d = json.loads(self.raw.decode("utf-8"))
        d = {k: d[k] for k in sorted(d) if d[k]["on"]}  # 'bt, eq, rvb, se'

        for k in d:
            del d[k]["on"]
            d[k] = {k1: d[k][k1] for k1 in sorted(d[k])}
            # bt: 'bass, treble'
            # eq: 'eqs'
            # rvb: 'er, il, ol, rl, rvb, tc'
            # se: 'ambience, presence, sshaper, stereoizer'

        if "rvb" in d:
            d1 = d["rvb"]
            for k in d1:
                try:
                    del d1[k]["on"]
                except KeyError:
                    pass
                if k == "rl":
                    continue  # keep the order of 'front, rear, center, lfe'
                d1[k] = {k1: d1[k][k1] for k1 in sorted(d1[k])}
            d["rvb"] = d1

        if "eq" in d:
            d["eq"]["eqs"] = str(d["eq"]["eqs"])  # don't expand eqs list

        string = json.dumps(d, indent=4)
        string = string.replace('"[', "[").replace(']"', "]")

        with open(filename, "w") as fout:
            fout.write(string)

    def _export_formatted_wav(self, filename: str):

        self.plugins[0].ir.export(filename, trim=16384)
