import os
import json
import numpy as np
import zlib



def read_parts(filename):

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


def make_swaptable(key):

    table = np.arange(0x100, dtype=np.uint8)
    byte = 0

    for i in range(0x100):
        byte = table[i] + key[i % len(key)] + byte & 0xFF
        table[i], table[byte] = table[byte], table[i]

    return table


def use_swaptable(data, table):

    for j in range(len(data)):
        byte = table[(j + 1) & 0xFF]
        data[j] ^= table[table[(byte + j + 1) & 0xFF] + byte & 0xFF]

    return data


def determine_ext(data):

    import warnings
    import pydub.exceptions
    from pydub import AudioSegment
    from io import BytesIO

    try:
        _ = json.loads(data.decode('utf-8'))
        return '.json'
    except UnicodeDecodeError or json.JSONDecodeError:

        try:
            _ = AudioSegment.from_file(BytesIO(data))
            return '.wav'
        except pydub.exceptions.CouldntDecodeError:

            warnings.warn('Unrecognized format')
            return '.bin'


def format_json(data):

    d = json.loads(data.decode('utf-8'))
    d = {k: d[k] for k in sorted(d) if d[k]['on']}  # 'bt, eq, rvb, se'

    for k in d:
        del d[k]['on']
        d[k] = {k1: d[k][k1] for k1 in sorted(d[k])}
        # bt: 'bass, treble'
        # eq: 'eqs'
        # rvb: 'er, il, ol, rl, rvb, tc'
        # se: 'ambience, presence, sshaper, stereoizer'

    if 'rvb' in d:
        d1 = d['rvb']
        for k in d1:
            try:
                del d1[k]['on']
            except KeyError:
                pass
            if k == 'rl': continue  # keep the order of 'front, rear, center, lfe'
            d1[k] = {k1: d1[k][k1] for k1 in sorted(d1[k])}
        d['rvb'] = d1

    if 'eq' in d:
        d['eq']['eqs'] = str(d['eq']['eqs'])    # don't expand eqs list

    data = json.dumps(d, indent=4)
    data = data.replace('"[', '[').replace(']"', ']')

    return data.encode('utf-8')



src = 'raw'
dst = 'processed'


if __name__ == '__main__':

    if not os.path.exists(dst):
        os.makedirs(dst)

    with open('translate.json', encoding='utf-8') as f:
        translator = json.load(f)

    for file in os.listdir(src):
        if not file.endswith('.ncae'): continue

        key, data = read_parts(os.path.join(src, file))
        table = make_swaptable(key)
        data = use_swaptable(data, table)
        data = zlib.decompress(data, -zlib.MAX_WBITS)
        ext = determine_ext(data)

        file = translator[os.path.splitext(file)[0]] + ext
        if ext == '.json':
            data = format_json(data)
        with open(os.path.join(dst, file), 'wb') as fout:
            fout.write(data)

        print(file)
