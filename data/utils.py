import os
import json
import numpy as np
import soundfile as sf
import warnings

from io import BytesIO



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


def write_decfile(filename, data, rewrite_wav=False):

    ext = _determine_ext(data)
    filename += ext

    if ext == '.json':
        data = _format_json(data)

    os.makedirs(os.path.dirname(filename), exist_ok=True)

    with open(filename, 'wb') as fout:
        fout.write(data)

    if rewrite_wav and ext == '.wav':
        _rewrite_wav(filename)

    return filename


def _determine_ext(data):

    try:
        _ = json.loads(data.decode('utf-8'))
        return '.json'
    except UnicodeDecodeError or json.JSONDecodeError:

        try:
            _ = sf.read(BytesIO(data))
            return '.wav'
        except sf.LibsndfileError:

            warnings.warn('Unrecognized format')
            return '.bin'


def _format_json(data):

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


def _rewrite_wav(filename):

    data, sr = sf.read(filename)
    if data.shape[0] != 16384:
        if data[16384:].max() == 0:
            data = data[:16384]
        else:
            warnings.warn('Unexpected pikes in high frequencies')

    info = sf.info(filename)
    sf.write(filename, data, sr, format='WAV', subtype=info.subtype)
