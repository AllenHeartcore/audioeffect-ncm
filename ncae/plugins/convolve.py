import warnings
from io import BytesIO

import numpy as np
import soundfile as sf

from ncae.audio import Audio
from ncae.plugins.utils import ImpulseResponse


class NCAEPluginConvolve:

    def __init__(self, data: bytes):

        with BytesIO(data) as io:
            wave, sr = sf.read(io)
            io.seek(0)  # forcefully suppress sf.LibsndfileError...
            io.name = "_tmp.wav"  # ...by assigning a filename to the BytesIO object
            subtype = sf.info(io).subtype

        self.ir = ImpulseResponse(wave, sr, subtype)

    def applyto(self, audio: Audio):

        self.ir.applyto(audio)
