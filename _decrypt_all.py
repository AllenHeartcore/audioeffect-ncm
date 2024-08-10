import os
import json

from decrypt import NCAEDecryptor
from utils import read_encfile



src = 'data/raw'
dst = 'data/processed'


def iter_files(src):
    for r, d, f in os.walk(src):
        for file in f:
            if not file.endswith('.ncae'): continue
            yield r, os.path.join(r, file)


if __name__ == '__main__':

    with open('_translate.json', encoding='utf-8') as f:
        translator = json.load(f)

    for root, file in iter_files(src):

        key, data = read_encfile(file)
        decryptor = NCAEDecryptor(key)
        scheme = decryptor.decrypt(data)

        root = root.replace(src, dst)                               # change root
        file_new = os.path.splitext(os.path.basename(file))[0]      # remove extension
        if file_new in translator:                                  # potentially translate name
            scheme.export(os.path.join(root, translator[file_new]))
        else:
            scheme.export(os.path.join(root, file_new), fmt=True)   # device-specific presets
        print(file)
