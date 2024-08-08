import os
import json

from decrypt import NCAEDecryptor
from utils import read_encfile



src = 'data/raw'
dst = 'data/processed'


def iter_files(src):

    for file in os.listdir(src):
        if not file.endswith('.ncae'): continue
        yield os.path.join(src, file)


if __name__ == '__main__':

    with open('translate.json', encoding='utf-8') as f:
        translator = json.load(f)

    for file in iter_files(src):

        key, data = read_encfile(file)
        decryptor = NCAEDecryptor(key)
        schema = decryptor.decrypt(data)

        file_new = translator[os.path.splitext(os.path.basename(file))[0]]
        schema.export(os.path.join(dst, file_new))
        print(file, '->', file_new)

    for file in iter_files(os.path.join(src, 'brand')):

        key, data = read_encfile(file)
        decryptor = NCAEDecryptor(key)
        schema = decryptor.decrypt(data)

        file_new = translator[os.path.splitext(os.path.basename(file))[0]]
        brand = file_new.split()[0]
        schema.export(os.path.join(dst, brand, file_new), fmt=True)
        print(file, '->', file_new)
