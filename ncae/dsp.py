import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import resample, convolve

from ncae.audio import Audio



def convolve_ir(clip: Audio, efx: Audio):
    # used to return another Audio object,
    # but switched to in-place operation on 'clip' for memory efficiency

    wc = clip.wave          # pointer
    we = efx.wave.copy()    # deepcopy

    if clip.sr != efx.sr:
        we = resample(we, int(len(we) * clip.sr / efx.sr))

    if len(wc.shape) == 1:
        if len(we.shape) == 1:
            clip.wave = convolve(wc, we)
        else:
            clip.wave = np.array([convolve(wc, we[:, i]) for i in range(we.shape[1])]).T
    else:
        if len(we.shape) == 1:
            clip.wave = np.array([convolve(wc[:, i], we) for i in range(wc.shape[1])]).T
        else:
            assert wc.shape[1] == we.shape[1]
            clip.wave = np.array([convolve(wc[:, i], we[:, i]) for i in range(wc.shape[1])]).T
