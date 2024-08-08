import numpy as np
import json
import zlib
import soundfile as sf

from io import BytesIO
from schema import NCAEJsonSchema, NCAEWavSchema



class NCAEDecryptor:


    def __init__(self, key):

        table = np.arange(0x100, dtype=np.uint8)
        byte = 0

        for i in range(0x100):
            byte = table[i] + key[i % len(key)] + byte & 0xFF
            table[i], table[byte] = table[byte], table[i]

        self._table = table


    def decrypt(self, data):

        for j in range(len(data)):
            byte = self._table[(j + 1) & 0xFF]
            data[j] ^= self._table[self._table[(byte + j + 1) & 0xFF] + byte & 0xFF]

        data = zlib.decompress(data, -zlib.MAX_WBITS)

        try:
            dic = json.loads(data.decode('utf-8'))
            return NCAEJsonSchema(data, dic)

        except UnicodeDecodeError or json.JSONDecodeError:
            try:
                io = BytesIO(data)
                wav, sr = sf.read(io)
                io.seek(0)              # forcefully suppress sf.LibsndfileError...
                io.name = '_tmp.wav'    # ...by assigning a filename to the BytesIO object
                info = sf.info(io)
                return NCAEWavSchema(data, wav, meta={
                    'sr': sr,
                    'subtype': info.subtype,
                })

            except sf.LibsndfileError:
                raise ValueError('Unrecognized format')
