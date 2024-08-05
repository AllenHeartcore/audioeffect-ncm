import os
import json

from decrypt import NCAEDecryptor
from utils import read_encfile, write_decfile



src = 'raw'
dst = 'processed'


if __name__ == '__main__':

    if not os.path.exists(dst):
        os.makedirs(dst)

    with open('translate.json', encoding='utf-8') as f:
        translator = json.load(f)

    for file in os.listdir(src):
        if not file.endswith('.ncae'): continue

        key, data = read_encfile(os.path.join(src, file))
        decryptor = NCAEDecryptor(key)
        data = decryptor.decrypt(data)
        file_new = translator[os.path.splitext(file)[0]]
        file_new = write_decfile(os.path.join(dst, file_new), data)

        print(os.path.join(src, file), '->', file_new)
