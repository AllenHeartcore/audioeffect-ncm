from typing import Union
import warnings

import numpy as np

import soundfile as sf
from io import BytesIO
from music_tag import load_file



class Audio:


    def __init__(self, file: Union[str, bytes]):

        if isinstance(file, str):
            self.wave, self.sr = sf.read(file)
            self.subtype = sf.info(file).subtype

            tag = load_file(file)
            self.meta = {}
            self.meta['title'] = tag['title'] or None
            self.meta['artist'] = tag['artist'] or None
            self.meta['album'] = tag['album'] or None
            self.meta['tracknumber'] = tag['tracknumber'] or None

        else:
            io = BytesIO(file)
            self.wave, self.sr = sf.read(io)
            io.seek(0)              # forcefully suppress sf.LibsndfileError...
            io.name = '_tmp.wav'    # ...by assigning a filename to the BytesIO object
            self.subtype = sf.info(io).subtype
            self.meta = None        # assume no metadata; load_file() only accepts str argument


    def apply(self, schemes: list): # should be scheme: NCAEScheme, but this creates a circular import

        for scheme in schemes:
            scheme._apply(self)     # in-place operation


    def export(self, file: str, trim=-1, normalize=False):

        wave = self.wave

        if trim > 0:
            if trim > len(wave):
                warnings.warn('Trim length exceeds sample length, ignoring')
            elif trim == len(wave):
                pass    # otherwise, gets ValueError due to zero-size array
            elif wave[trim:].max() != 0:
                warnings.warn('Unexpected spikes in trimmed sample, ignoring')
            else:
                wave = wave[:trim]

        if normalize:
            wave /= np.max(np.abs(wave))

        sf.write(file, wave, self.sr, subtype=self.subtype)

        if self.meta:
            tag = load_file(file)
            tag['title'] = self.meta['title']
            tag['artist'] = self.meta['artist']
            tag['album'] = self.meta['album']
            tag['tracknumber'] = self.meta['tracknumber']
            tag.save()
