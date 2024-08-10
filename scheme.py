import os
import json
import numpy as np
import soundfile as sf
import warnings

from io import BytesIO



class NCAEScheme:


    def __init__(self, raw, ext='.bin'):

        self.raw = raw
        self.ext = ext      # "type" collides with a reserved word
        self.data = None


    def export(self, filename):
        # to be overridden by subclasses

        filename += self.ext
        os.makedirs(os.path.dirname(filename), exist_ok=True)

        with open(filename, 'wb') as fout:
            fout.write(self.raw)



class NCAEJsonScheme(NCAEScheme):


    def __init__(self, raw):

        super().__init__(raw, '.json')
        self.data = json.loads(raw.decode('utf-8'))


    def export(self, filename, fmt=True):

        filename += self.ext
        os.makedirs(os.path.dirname(filename), exist_ok=True)

        if fmt:

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

        else:
            string = self.raw.decode('utf-8')

        with open(filename, 'w') as fout:
            fout.write(string)



class NCAEWavScheme(NCAEScheme):


    def __init__(self, raw):

        super().__init__(raw, '.wav')
        io = BytesIO(raw)
        self.data, sr = sf.read(io)

        io.seek(0)              # forcefully suppress sf.LibsndfileError...
        io.name = '_tmp.wav'    # ...by assigning a filename to the BytesIO object
        info = sf.info(io)
        self.meta = {
            'sr': sr,
            'subtype': info.subtype,
        }


    def export(self, filename, fmt=False):

        data = self.data
        meta = self.meta

        filename += self.ext
        os.makedirs(os.path.dirname(filename), exist_ok=True)

        if fmt:

            if data.shape[0] != 16384:
                if data[16384:].max() == 0:
                    data = data[:16384]
                else:
                    warnings.warn('Unexpected spikes in overlength sample')

            sf.write(filename, data,
                samplerate=meta['sr'],
                format='WAV',
                subtype=meta['subtype']
            )

        else:
            with open(filename, 'wb') as fout:
                fout.write(self.raw)
