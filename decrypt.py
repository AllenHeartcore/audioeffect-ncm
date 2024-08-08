import numpy as np
import zlib

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
            return NCAEJsonSchema(data)

        except:
            try:
                return NCAEWavSchema(data)

            except:
                raise ValueError('Unrecognized format')
