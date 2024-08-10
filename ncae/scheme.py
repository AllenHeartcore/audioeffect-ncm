import os
import json
import warnings

import soundfile as sf
from io import BytesIO

from ncae.decrypt import read_encfile, NCAEDecryptor



class NCAEScheme:


    def __init__(self, filename):

        self.filename = filename
        self.raw = None
        self.ext = None
        self.data = None

        self._read_and_decrypt()
        try:
            self._parse_json()
        except:
            try:
                self._parse_wav()
            except:
                warnings.warn('Unrecognized format')
                self.ext = '.bin'


    def _read_and_decrypt(self):

        key, data = read_encfile(self.filename)
        decryptor = NCAEDecryptor(key)
        self.raw = decryptor.decrypt(data)


    def _parse_json(self):

        self.data = json.loads(self.raw.decode('utf-8'))
        self.ext = '.json'


    def _parse_wav(self):

        io = BytesIO(self.raw)
        self.data, sr = sf.read(io)

        io.seek(0)              # forcefully suppress sf.LibsndfileError...
        io.name = '_tmp.wav'    # ...by assigning a filename to the BytesIO object
        info = sf.info(io)
        self.meta = {
            'sr': sr,
            'subtype': info.subtype,
        }

        self.ext = '.wav'


    def export(self, filename, fmt=True):

        filename += self.ext
        os.makedirs(os.path.dirname(filename), exist_ok=True)

        if fmt:
            if self.ext == '.json':
                self._export_formatted_json()
                return
            elif self.ext == '.wav':
                self._export_formatted_wav()
                return
            else:
                warnings.warn('Raw binary data cannot be formatted')

        with open(self.filename, 'wb') as fout:
            fout.write(self.raw)


    def _export_formatted_json(self):

        d = self.data
        d = {k: d[k] for k in sorted(d) if d[k]['on']}  # 'bt, eq, rvb, se'

        for k in d:
            del d[k]['on']
            d[k] = {k1: d[k][k1] for k1 in sorted(d[k])}
            # bt: 'bass, treble'
            # eq: 'eqs'
            # rvb: 'er, il, ol, rl, rvb, tc'
            # se: 'ambience, presence, sshaper, stereoizer'

        if 'rvb' in d:
            d1 = d['rvb']
            for k in d1:
                try:
                    del d1[k]['on']
                except KeyError:
                    pass
                if k == 'rl': continue  # keep the order of 'front, rear, center, lfe'
                d1[k] = {k1: d1[k][k1] for k1 in sorted(d1[k])}
            d['rvb'] = d1

        if 'eq' in d:
            d['eq']['eqs'] = str(d['eq']['eqs'])    # don't expand eqs list

        string = json.dumps(d, indent=4)
        string = string.replace('"[', '[').replace(']"', ']')

        with open(self.filename, 'w') as fout:
            fout.write(string)



    def _export_formatted_wav(self):

        data = self.data
        meta = self.meta

        if data.shape[0] != 16384:
            if data[16384:].max() == 0:
                data = data[:16384]
            else:
                warnings.warn('Unexpected spikes in overlength sample')

        sf.write(self.filename, data,
            samplerate=meta['sr'],
            format='WAV',
            subtype=meta['subtype']
        )
