import os
import json
import numpy as np
import zlib

import warnings
import pydub.exceptions
from pydub import AudioSegment
from io import BytesIO



toint = lambda x: int.from_bytes(x, byteorder='big')


def read_parts(filename):
    with open('raw/%s' % filename, 'rb') as fin:
        magic = fin.read(4)
        assert magic == b'NCAE'
        ldata = toint(fin.read(4))
        fin.read(6)     # unused
        short = toint(fin.read(2))
        lkey = toint(fin.read(1)) - 1
        assert lkey % 4 == 0
        key0 = bytearray(fin.read(lkey + 1))
        key = np.array(key0[:4] + key0[5:]) ^ key0[4]
        data = bytearray(fin.read(ldata))
    return lkey, key, data


def make_swaptable(lkey, key):
    arr = np.arange(0x100, dtype=np.uint8)
    byte = 0
    for i in range(0x100):
        byte = arr[i] + key[i % lkey] + byte & 0xFF
        arr[i], arr[byte] = arr[byte], arr[i]
    return arr


def use_swaptable(data, arr):
    for j in range(len(data)):
        byte = arr[(j + 1) & 0xFF]
        data[j] ^= arr[arr[(byte + j + 1) & 0xFF] + byte & 0xFF]
    return data


def determine_ext(data):
    try:
        data = json.loads(data.decode('utf-8'))
        data = json.dumps(data, indent=4).encode('utf-8')
        return '.json'
    except UnicodeDecodeError or json.JSONDecodeError:
        try:
            _ = AudioSegment.from_file(BytesIO(data))
            return '.wav'
        except pydub.exceptions.CouldntDecodeError:
            warnings.warn('Unrecognized format')
            return '.bin'



if __name__ == '__main__':

    if not os.path.exists('processed'):
        os.makedirs('processed')

    for file in os.listdir('raw'):

        lkey, key, data = read_parts(file)
        arr = make_swaptable(lkey, key)
        data = use_swaptable(data, arr)
        data = zlib.decompress(data, -zlib.MAX_WBITS)
        ext = determine_ext(data)

        translator = json.loads(open('translate.json', encoding='utf-8').read())
        file = translator[file[:-5]] + ext
        fout = open('processed/%s' % file, 'wb')
        fout.write(data)
        fout.close()
        print(file)
