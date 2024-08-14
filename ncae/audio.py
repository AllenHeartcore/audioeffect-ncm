import numpy as np
import soundfile as sf
from music_tag import load_file


class Audio:

    def __init__(self, file: str):

        self.wave, self.sr = sf.read(file)
        self.subtype = sf.info(file).subtype

        tag = load_file(file)
        self.meta = {
            "title": tag["title"] or None,
            "artist": tag["artist"] or None,
            "album": tag["album"] or None,
            "tracknumber": tag["tracknumber"] or None,
        }

    def apply(self, schemes: list):  # list of NCAEScheme's

        for scheme in schemes:
            scheme._applyto(self)  # in-place operation

    def export(self, file: str, normalize=False):

        if normalize:
            sf.write(
                file,
                self.wave / np.max(np.abs(self.wave)),
                self.sr,
                subtype=self.subtype,
            )
            # doesn't motify self.wave in-place
        else:
            sf.write(file, self.wave, self.sr, subtype=self.subtype)

        tag = load_file(file)
        tag["title"] = self.meta["title"]
        tag["artist"] = self.meta["artist"]
        tag["album"] = self.meta["album"]
        tag["tracknumber"] = self.meta["tracknumber"]
        tag.save()
