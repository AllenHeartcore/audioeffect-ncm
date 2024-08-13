import os
from argparse import ArgumentParser

from ncae.audio import Audio
from ncae.scheme import NCAEScheme



if __name__ == '__main__':

    parser = ArgumentParser()
    parser.add_argument('clip', type=str)
    parser.add_argument('-e', '--efx', type=str)
    parser.add_argument('-o', '--out', type=str)
    parser.add_argument('-n', '--norm', action='store_true')
    args = parser.parse_args()

    clip = Audio(args.clip)
    clip.apply([NCAEScheme(f'presets/{e}.ncae') for e in args.efx.split(',')])

    base, ext = os.path.splitext(args.clip)
    clip.export(args.out or f'{base}_{args.efx}{ext}', normalize=args.norm)
