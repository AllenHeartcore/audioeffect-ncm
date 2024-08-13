import warnings

import numpy as np
import soundfile as sf
from scipy.signal import resample, convolve

from ncae.audio import Audio



class ImpulseResponse:


    def __init__(self, wave: np.ndarray, sr: int=48000, subtype: str='PCM_24'):

        self.wave = wave
        self.sr = sr
        self.subtype = subtype


    def applyto(self, audio: Audio):
        # used to return another Audio object,
        # but switched to in-place operation on 'clip' for memory efficiency

        wc = audio.wave         # pointer
        we = self.wave.copy()   # deepcopy

        if audio.sr != self.sr:
            we = resample(we, int(len(we) * audio.sr / self.sr))

        if len(wc.shape) == 1:
            if len(we.shape) == 1:
                audio.wave = convolve(wc, we)
            else:
                audio.wave = np.array([convolve(wc, we[:, i]) for i in range(we.shape[1])]).T
        else:
            if len(we.shape) == 1:
                audio.wave = np.array([convolve(wc[:, i], we) for i in range(wc.shape[1])]).T
            else:
                assert wc.shape[1] == we.shape[1]
                audio.wave = np.array([convolve(wc[:, i], we[:, i]) for i in range(wc.shape[1])]).T


    def export(self, file: str, trim: int=-1):

        wave = self.wave.copy()

        if trim > 0:
            if trim > len(wave):
                warnings.warn('Trim length exceeds sample length, ignoring')
            elif trim == len(wave):
                pass    # otherwise, gets ValueError due to zero-size array
            elif wave[trim:].max() != 0:
                warnings.warn('Unexpected spikes in trimmed sample, ignoring')
            else:
                wave = wave[:trim]

        sf.write(file, wave, self.sr, subtype=self.subtype)
