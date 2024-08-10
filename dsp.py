import numpy as np
import soundfile as sf
import matplotlib.pyplot as plt
from scipy.signal import resample, convolve



def convolve_ir(clip, clip_sr, efx, efx_sr):

    out_sr = clip_sr

    if efx_sr != out_sr:
        efx = resample(efx, int(len(efx) * out_sr / efx_sr))

    if len(clip.shape) == 1:
        if len(efx.shape) == 1:
            out = convolve(clip, efx)
        else:
            out = np.array([convolve(clip, efx[:, i]) for i in range(efx.shape[1])]).T
    else:
        if len(efx.shape) == 1:
            out = np.array([convolve(clip[:, i], efx) for i in range(clip.shape[1])]).T
        else:
            assert clip.shape[1] == efx.shape[1]
            out = np.array([convolve(clip[:, i], efx[:, i]) for i in range(clip.shape[1])]).T

    out = out / np.max(np.abs(out))
    return out, out_sr



clip, clip_sr = sf.read('data/hajime_48.flac')
efx, efx_sr = sf.read('data/processed/Spatial - Panorama.wav')

out, out_sr = convolve_ir(clip, clip_sr, efx, efx_sr)
sf.write('data/hajime_48_panorama.flac', out, out_sr)
