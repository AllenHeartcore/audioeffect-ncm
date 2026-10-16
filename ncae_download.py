import asyncio
import json
import os
import zlib
from email.utils import parsedate_to_datetime
from pathlib import Path

import requests
from tqdm import tqdm

CATALOG_DIR = Path(__file__).parent / "ncae_catalog"
OBJECT_DIR_ENC = Path(__file__).parent / "ncae_objects"
OBJECT_DIR_DEC = Path(__file__).parent / "ncae_objects_dec"
OBJECT_DIR_NORM = Path(__file__).parent / "ncae_objects_norm"
REQ_TIMEOUT = 10

_DROP_MARK = object()  # sentinel for missing values

INVALID_CHARS = r'\/:*?"<>|'
FALLBACK_CHAR = "_"
SAFENAME_TRANS = str.maketrans(INVALID_CHARS, FALLBACK_CHAR * len(INVALID_CHARS))

_safename = lambda s: s.translate(SAFENAME_TRANS).strip().rstrip(".")
toint = lambda x: int.from_bytes(x, byteorder="little")


class NCAEDecryptor:
    # a collection of functions

    @staticmethod
    def make_perm(key: bytearray) -> list[int]:

        perm = list(range(0x100))
        j = 0

        for i in range(0x100):
            j = perm[i] + key[i % len(key)] + j & 0xFF
            perm[i], perm[j] = perm[j], perm[i]

        return perm

    @staticmethod
    def apply_perm(data: bytearray, perm: list[int]) -> bytes:

        for i in range(len(data)):
            j = perm[(i + 1) & 0xFF]
            data[i] ^= perm[perm[(i + j + 1) & 0xFF] + j & 0xFF]

        return zlib.decompress(data, -zlib.MAX_WBITS)

    def process(self, raw: bytes) -> bytes:

        assert raw[:4] == b"NCAE", "Unexpected NCAE file header"

        ldata = toint(raw[4:8])
        lkey = toint(raw[16:17]) - 1
        assert lkey % 4 == 0, "Unexpected NCAE key length"

        _key = bytearray(raw[17 : 18 + lkey])
        key = bytearray(_key[:4] + _key[5:])
        for i in range(len(key)):
            key[i] ^= _key[4]

        data = bytearray(raw[18 + lkey : 18 + lkey + ldata])
        perm = self.make_perm(key)
        return self.apply_perm(data, perm)


def _rget(url: str, **kwargs) -> requests.Response:
    while True:
        try:
            r = requests.get(url, timeout=REQ_TIMEOUT, **kwargs)
            r.raise_for_status()
            return r
        except requests.exceptions.RequestException as e:
            pass


def _clean_json(obj: dict | list) -> dict | list:

    if isinstance(obj, dict):
        if obj.get("on") is False:
            return _DROP_MARK

        cleaned = {}
        for k, v in sorted(obj.items()):
            if k == "on":
                continue
            if (v := _clean_json(v)) is not _DROP_MARK:
                cleaned[k] = v

        return cleaned

    elif isinstance(obj, list):
        cleaned = []
        for v in obj:
            if (v := _clean_json(v)) is not _DROP_MARK:
                cleaned.append(v)
        return cleaned

    else:
        return obj


def probe_and_normalize(raw: bytes) -> tuple[str, bytes]:

    if raw[:4] == b"RIFF":
        assert raw[8:12] == b"WAVE", "Unexpected WAV file header"
        riff_size = toint(raw[4:8])
        return ".wav", raw[: riff_size + 8]

    else:
        try:
            data = json.loads(raw.decode("utf-8"))
            return ".json", json.dumps(_clean_json(data), ensure_ascii=False, indent=4).encode("utf-8")
        except json.JSONDecodeError:
            raise ValueError("Unknown file format")


def download_one(url: str, path: Path, prog: tqdm) -> None:

    enc_p = OBJECT_DIR_ENC / path
    dec_p = OBJECT_DIR_DEC / path
    norm_p = OBJECT_DIR_NORM / path
    if all(p.exists() and p.stat().st_size > 0 for p in (enc_p, dec_p, norm_p)):
        prog.update(1)
        return

    enc_p.parent.mkdir(parents=True, exist_ok=True)
    dec_p.parent.mkdir(parents=True, exist_ok=True)
    norm_p.parent.mkdir(parents=True, exist_ok=True)

    r = _rget(url)
    enc = r.content
    enc_p.write_bytes(enc)

    dec = NCAEDecryptor().process(enc)
    ext, norm = probe_and_normalize(dec)
    dec_p.with_suffix(ext).write_bytes(dec)
    norm_p.with_suffix(ext).write_bytes(norm)

    if mtime := r.headers.get("Last-Modified"):
        ts = parsedate_to_datetime(mtime).timestamp()
        os.utime(enc_p, (ts, ts))
        os.utime(dec_p.with_suffix(ext), (ts, ts))
        os.utime(norm_p.with_suffix(ext), (ts, ts))

    prog.update(1)


async def download_many(urls: list[str], paths: list[Path]) -> None:

    with tqdm(total=len(urls), desc="Downloading", unit="file") as prog:
        await asyncio.gather(*(asyncio.to_thread(download_one, url, path, prog) for url, path in zip(urls, paths)))


if __name__ == "__main__":

    with (CATALOG_DIR / "effects_parsed.json").open("r", encoding="utf-8") as fin:
        effects = json.load(fin)
    with (CATALOG_DIR / "devices_parsed.json").open("r", encoding="utf-8") as fin:
        devices = json.load(fin)

    asyncio.run(
        download_many(
            [e["url"] for e in effects],
            [Path(_safename(e["name"]) + ".ncae") for e in effects],
        )
    )
    asyncio.run(
        download_many(
            [d["url"] for d in devices],
            [Path(_safename(d["brand"])) / (_safename(d["model"]) + ".ncae") for d in devices],
        )
    )
