import os
import json
import numpy as np
import zlib

toint = lambda x: int.from_bytes(x, byteorder='big')
if not os.path.exists('processed'):
    os.makedirs('processed')

for file in os.listdir('raw'):

    fin = open('raw/%s' % file, 'rb')
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
    fin.close()

    byte = 0
    arr = np.arange(0x100, dtype=np.uint8)
    for i in range(0x100):
        byte = arr[i] + key[i % lkey] + byte & 0xFF
        arr[i], arr[byte] = arr[byte], arr[i]
    for j in range(len(data)):
        byte = arr[(j + 1) & 0xFF]
        data[j] ^= arr[arr[(byte + j + 1) & 0xFF] + byte & 0xFF]

    translator = json.loads(open('translate.json', encoding='utf-8').read())
    file = translator[file[:-5]] + '.bin'
    fout = open('processed/%s' % file, 'wb')
    fout.write(zlib.decompress(data, -zlib.MAX_WBITS))
    fout.close()
    print(file)
