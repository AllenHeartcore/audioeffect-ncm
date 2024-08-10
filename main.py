from argparse import ArgumentParser

from dsp import convolve_ir



if __name__ == '__main__':

    parser = ArgumentParser()
    parser.add_argument('clip', type=str)
    parser.add_argument('--efx', type=str)
    parser.add_argument('--out', type=str)
    args = parser.parse_args()

    clip, clip_sr = sf.read(args.clip)
    if args.efx:
        efx, efx_sr = sf.read(args.efx)
        out, out_sr = convolve_ir(clip, clip_sr, efx, efx_sr)
        sf.write(args.out, out, out_sr)
    else:
        sf.write(args.out, clip, clip_sr)
