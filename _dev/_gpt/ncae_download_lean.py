"""Small, corrected NCAE downloader. Requires requests and tqdm.

The 4-byte NCAE payload length is LITTLE-ENDIAN. Reading it as big-endian
can request gigabyte-sized buffers for files that are only a few kilobytes.
"""

from concurrent.futures import ThreadPoolExecutor, as_completed
from email.utils import parsedate_to_datetime
from pathlib import Path
from threading import local
import json
import os
import re
import time
import zlib

import requests
from tqdm import tqdm

BASE = Path(__file__).resolve().parent
CATALOG_DIR = BASE / "ncae_catalog"
OBJECT_DIR = BASE / "ncae_objects"
DECRYPTED_DIR = BASE / "ncae_objects_decrypted"
MAX_WORKERS = 8
_thread = local()


def session() -> requests.Session:
    if not hasattr(_thread, "session"):
        _thread.session = requests.Session()
    return _thread.session


def safe_name(name: str) -> str:
    name = re.sub(r'[<>:"/\\|?*\x00-\x1f]', "_", name).strip().rstrip(".")
    if not name:
        raise ValueError("Empty filename")
    if name.split(".", 1)[0].upper() in {
        "CON", "PRN", "AUX", "NUL", *(f"COM{i}" for i in range(1, 10)),
        *(f"LPT{i}" for i in range(1, 10)),
    }:
        name = "_" + name
    return name


def read_encfile(path: Path) -> tuple[bytes, bytes]:
    with path.open("rb") as file:
        if file.read(4) != b"NCAE":
            raise ValueError(f"Bad NCAE magic: {path}")
        length = int.from_bytes(file.read(4), "little")  # IMPORTANT!
        file.read(8)
        key_length = file.read(1)[0]
        if key_length < 5 or (key_length - 1) % 4:
            raise ValueError(f"Bad NCAE key length: {path}")
        key0 = file.read(key_length)
        if len(key0) != key_length:
            raise ValueError(f"Truncated NCAE key: {path}")
        key = bytes(b ^ key0[4] for b in key0[:4] + key0[5:])
        data = file.read(length)
        if len(data) != length:
            raise ValueError(f"Truncated NCAE payload: {path}")
        return key, data


class NCAEDecryptor:
    def __init__(self, key: bytes):
        perm = list(range(256))
        j = 0
        for i in range(256):
            j = (j + perm[i] + key[i % len(key)]) & 255
            perm[i], perm[j] = perm[j], perm[i]
        self.mask = bytes(
            perm[(perm[(i + perm[(i + 1) & 255] + 1) & 255] + perm[(i + 1) & 255]) & 255]
            for i in range(256)
        )

    def process(self, data: bytes) -> bytes:
        mask = self.mask
        plaintext = bytes(b ^ mask[i & 255] for i, b in enumerate(data))
        return zlib.decompress(plaintext, -zlib.MAX_WBITS)


def download(url: str, path: Path, size: int) -> None:
    if path.is_file() and path.stat().st_size == size:
        with path.open("rb") as file:
            if file.read(4) == b"NCAE":
                return

    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + ".part")
    for attempt in range(3):
        try:
            with session().get(url, timeout=(5, 30)) as response:
                response.raise_for_status()
                blob = response.content  # Catalog files are at most ~34 KB.
                modified = response.headers.get("Last-Modified")
            if len(blob) != size or not blob.startswith(b"NCAE"):
                raise ValueError(f"Unexpected NCAE response: {url}")
            temp.write_bytes(blob)
            temp.replace(path)
            if modified:
                try:
                    ts = parsedate_to_datetime(modified).timestamp()
                    os.utime(path, (ts, ts))
                except (TypeError, ValueError, OverflowError):
                    pass
            return
        except (requests.RequestException, OSError, ValueError) as exc:
            temp.unlink(missing_ok=True)
            if isinstance(exc, requests.HTTPError) and exc.response is not None:
                if exc.response.status_code in (400, 401, 403, 404):
                    raise
            if attempt == 2:
                raise
            time.sleep(2 ** attempt)


def download_one(entry: dict, path: Path) -> None:
    download(entry["url"], path, entry["size"])
    destination = DECRYPTED_DIR / path.relative_to(OBJECT_DIR)
    if destination.is_file() and destination.stat().st_size:
        return
    key, encrypted = read_encfile(path)
    decrypted = NCAEDecryptor(key).process(encrypted)
    destination.parent.mkdir(parents=True, exist_ok=True)
    temp = destination.with_name(destination.name + ".part")
    temp.write_bytes(decrypted)
    temp.replace(destination)


def main() -> None:
    with (CATALOG_DIR / "effects_parsed.json").open(encoding="utf-8") as file:
        effects = json.load(file)
    with (CATALOG_DIR / "devices_parsed.json").open(encoding="utf-8") as file:
        devices = json.load(file)

    jobs = [
        (e, OBJECT_DIR / f"{safe_name(e['name'])}.ncae") for e in effects
    ] + [
        (d, OBJECT_DIR / safe_name(d["brand"]) / f"{safe_name(d['model'])}.ncae")
        for d in devices
    ]
    if len({path for _, path in jobs}) != len(jobs):
        raise ValueError("Sanitized filenames collide")

    errors = []
    with ThreadPoolExecutor(max_workers=MAX_WORKERS) as pool:
        futures = {pool.submit(download_one, entry, path): path for entry, path in jobs}
        for future in tqdm(as_completed(futures), total=len(futures), desc="Downloading", unit="file"):
            try:
                future.result()
            except Exception as exc:
                errors.append((futures[future], exc))
    if errors:
        for path, exc in errors:
            print(f"FAILED: {path}: {exc}")
        raise RuntimeError(f"{len(errors)} downloads failed")


if __name__ == "__main__":
    main()
