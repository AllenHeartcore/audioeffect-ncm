import os
import warnings
from argparse import ArgumentParser

from ncae.audio import Audio
from ncae.scheme import NCAEScheme



if __name__ == '__main__':

    warnings.filterwarnings('ignore', category=RuntimeWarning)

    parser = ArgumentParser()
    parser.add_argument('clip', type=str)
    parser.add_argument('-e', '--efx', type=str)
    parser.add_argument('-o', '--out', type=str)
    parser.add_argument('-n', '--norm', action='store_true')
    args = parser.parse_args()

    print('Decoding input file:', args.clip)
    clip = Audio(args.clip)

    schemes = []
    for e in args.efx.split(','):
        fsch = f'presets/{e}.ncae'
        print('Decrypting NCAE scheme:', fsch)
        schemes.append(NCAEScheme(fsch))

    print('Applying NCAE schemes:', args.efx)
    clip.apply(schemes)

    base, ext = os.path.splitext(args.clip)
    fout = args.out or f'{base}_{args.efx.replace('/', '-')}{ext}'
    print('Encoding output file:', fout, '[Normalization', 'ON]' if args.norm else 'OFF]')
    clip.export(fout, normalize=args.norm)
