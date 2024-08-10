import numpy as np



def read_encfile(filename):

    toint = lambda x: int.from_bytes(x, byteorder='big')

    with open(filename, 'rb') as fin:

        magic = fin.read(4)
        assert magic == b'NCAE'

        ldata = toint(fin.read(4))
        fin.read(8)     # unused

        lkey = toint(fin.read(1)) - 1
        assert lkey % 4 == 0
        key0 = bytearray(fin.read(lkey + 1))
        key = np.array(key0[:4] + key0[5:]) ^ key0[4]

        data = bytearray(fin.read(ldata))

    return key, data
