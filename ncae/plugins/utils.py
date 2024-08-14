import warnings

import numpy as np
import soundfile as sf
from scipy.signal import resample, convolve
import matplotlib.pyplot as plt

from ncae.audio import Audio


class ImpulseResponse:

    def __init__(self, wave: np.ndarray, sr: int = 48000, subtype: str = "PCM_24"):

        self.wave = wave
        self.sr = sr
        self.subtype = subtype

    def applyto(self, audio: Audio):
        # used to return another Audio object,
        # but switched to in-place operation on 'clip' for memory efficiency

        wc = audio.wave  # pointer
        we = self.wave.copy()  # deepcopy

        if audio.sr != self.sr:
            we = resample(we, int(len(we) * audio.sr / self.sr))

        if len(wc.shape) == 1:
            if len(we.shape) == 1:
                audio.wave = convolve(wc, we)
            else:
                audio.wave = np.array(
                    [convolve(wc, we[:, i]) for i in range(we.shape[1])]
                ).T
        else:
            if len(we.shape) == 1:
                audio.wave = np.array(
                    [convolve(wc[:, i], we) for i in range(wc.shape[1])]
                ).T
            else:
                assert wc.shape[1] == we.shape[1]
                audio.wave = np.array(
                    [convolve(wc[:, i], we[:, i]) for i in range(wc.shape[1])]
                ).T

    def export(self, file: str, trim: int = -1):

        wave = self.wave.copy()

        if trim > 0:
            if trim > len(wave):
                warnings.warn("Trim length exceeds sample length, ignoring")
            elif trim == len(wave):
                pass  # otherwise, gets ValueError due to zero-size array
            elif wave[trim:].max() != 0:
                warnings.warn("Unexpected spikes in trimmed sample, ignoring")
            else:
                wave = wave[:trim]

        sf.write(file, wave, self.sr, subtype=self.subtype)

    def plot(self, ax, title="", show_axis=True, show_ticks=True):

        data = self.wave.copy()
        # deepcopy, so that mono wave remains untouched by the following 'data.reshape'

        n = len(data)
        if len(data.shape) == 1:
            data = data.reshape(-1, 1)

        if show_ticks:
            ticks = {
                31: "31",
                63: "63",
                125: "125",
                250: "250",
                500: "500",
                1000: "1k",
                2000: "2k",
                4000: "4k",
                8000: "8k",
                16000: "16k",
            }
            for freq in ticks.keys():
                ax.axvline(freq, color="#D8D8D8", linestyle="--")

        fft_max = 0
        for i in range(data.shape[1]):
            fft = np.abs(np.fft.fft(data[:, i]))
            freqs = np.fft.fftfreq(n, 1 / self.sr)
            ax.plot(freqs[: n // 2], fft[: n // 2])
            fft_max = max(fft_max, fft.max())

        ax.set_xscale("log")
        ax.set_xlim(0, 24000)
        ax.set_ylim(0, max(fft_max * 1.05, 2))

        if show_ticks:
            ax.set_xticks(list(ticks.keys()))

        if show_axis:
            ax.set_xlabel("Frequency (Hz)")
            ax.set_ylabel("Magnitude")

        ax.set_title(title or "Frequency Response", fontproperties="Microsoft YaHei")
