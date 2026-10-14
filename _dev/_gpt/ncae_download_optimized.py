"""Bounded-memory NCAE downloader and streaming decryptor.

Requires: requests, tqdm
Reads the same effects_parsed.json and devices_parsed.json as ncae.py.
"""

import json
import os
import re
import time
import zlib
from concurrent.futures import ThreadPoolExecutor, as_completed
from email.utils import parsedate_to_datetime
from pathlib import Path
from threading import local

import requests
from tqdm import tqdm

BASE = Path(__file__).resolve().parent
CATALOG_DIR = BASE / "ncae_catalog"
OBJECT_DIR = BASE / "ncae_objects"
OBJECT_DIR_DECRYPTED = BASE / "ncae_objects_decrypted"
MAX_WORKERS = 8
CHUNK_SIZE = 64 * 1024
MAX_OUTPUT_BYTES = 256 * 1024 * 1024  # Safety limit per decompressed file
REQ_TIMEOUT = (5, 30)
MAX_ATTEMPTS = 3
_thread = local()


def session() -> requests.Session:
    # A Session is not shared between threads; each worker reuses its own pool.
    if not hasattr(_thread, "session"):
        _thread.session = requests.Session()
    return _thread.session


def safe_component(value: str) -> str:
    """Make one filename component, never a path, on Windows or Unix."""
    value = re.sub(r'[<>:"/\\|?*\x00-\x1f]', "_", value).strip().rstrip(".")
    if not value:
        raise ValueError("Empty filename component")
    if value.split(".", 1)[0].upper() in {
        "CON",
        "PRN",
        "AUX",
        "NUL",
        *(f"COM{i}" for i in range(1, 10)),
        *(f"LPT{i}" for i in range(1, 10)),
    }:
        value = "_" + value
    return value


def is_cached_ncae(path: Path, expected_size: int) -> bool:
    if not path.is_file() or path.stat().st_size != expected_size:
        return False
    with path.open("rb") as file:
        return file.read(4) == b"NCAE"


def download(url: str, path: Path, expected_size: int) -> None:
    if is_cached_ncae(path, expected_size):
        return

    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + ".part")
    for attempt in range(MAX_ATTEMPTS):
        try:
            with session().get(url, stream=True, timeout=REQ_TIMEOUT) as response:
                response.raise_for_status()
                modified = response.headers.get("Last-Modified")
                received = 0
                with temp.open("wb") as file:
                    for chunk in response.iter_content(CHUNK_SIZE):
                        if chunk:
                            received += len(chunk)
                            if received > expected_size:
                                raise ValueError(
                                    f"Response exceeds declared size: {url}"
                                )
                            file.write(chunk)

            if received != expected_size:
                raise ValueError(
                    f"Expected {expected_size} bytes, received {received}: {url}"
                )
            with temp.open("rb") as file:
                if file.read(4) != b"NCAE":
                    raise ValueError(f"Not an NCAE file: {url}")

            temp.replace(path)  # A failed transfer never becomes a cached file.
            if modified:
                try:
                    timestamp = parsedate_to_datetime(modified).timestamp()
                    os.utime(path, (timestamp, timestamp))
                except (ValueError, TypeError, OverflowError):
                    pass
            return

        except (requests.RequestException, OSError, ValueError) as exc:
            temp.unlink(missing_ok=True)
            # Authentication and missing-object failures aren't transient.
            if isinstance(exc, requests.HTTPError) and exc.response is not None:
                if exc.response.status_code in (400, 401, 403, 404):
                    raise
            if attempt == MAX_ATTEMPTS - 1:
                raise
            time.sleep(2**attempt)


def read_exact(file, size: int) -> bytes:
    data = file.read(size)
    if len(data) != size:
        raise ValueError("Truncated NCAE file")
    return data


def ncae_mask(key: bytes) -> bytes:
    """The original NCAE cipher has a 256-byte repeating XOR mask."""
    perm = list(range(256))
    j = 0
    for i in range(256):
        j = (j + perm[i] + key[i % len(key)]) & 255
        perm[i], perm[j] = perm[j], perm[i]

    mask = bytearray(256)
    for i in range(256):
        j = perm[(i + 1) & 255]
        mask[i] = perm[(perm[(i + j + 1) & 255] + j) & 255]
    return bytes(mask)


def decrypt_ncae(source: Path, destination: Path) -> None:
    """Stream XOR + raw DEFLATE directly to a temporary output file."""
    destination.parent.mkdir(parents=True, exist_ok=True)
    temp = destination.with_name(destination.name + ".part")

    try:
        with source.open("rb") as fin:
            if read_exact(fin, 4) != b"NCAE":
                raise ValueError(f"Bad NCAE magic: {source}")
            remaining = int.from_bytes(read_exact(fin, 4), "little")
            read_exact(fin, 8)  # Header fields not needed for decoding
            key_length = read_exact(fin, 1)[0]
            if key_length < 5 or (key_length - 1) % 4:
                raise ValueError(f"Invalid NCAE key length: {source}")
            key0 = read_exact(fin, key_length)
            key = bytes(b ^ key0[4] for b in key0[:4] + key0[5:])
            mask = ncae_mask(key)

            inflate = zlib.decompressobj(-zlib.MAX_WBITS)
            offset = 0
            output_size = 0

            with temp.open("wb") as fout:
                while remaining:
                    block = bytearray(read_exact(fin, min(remaining, CHUNK_SIZE)))
                    remaining -= len(block)
                    for i in range(len(block)):
                        block[i] ^= mask[(offset + i) & 255]
                    offset = (offset + len(block)) & 255

                    pending = bytes(block)
                    while pending:
                        chunk = inflate.decompress(pending, CHUNK_SIZE)
                        output_size += len(chunk)
                        if output_size > MAX_OUTPUT_BYTES:
                            raise ValueError(f"Decompressed output too large: {source}")
                        fout.write(chunk)
                        pending = inflate.unconsumed_tail

                if not inflate.eof:
                    raise ValueError(f"Incomplete DEFLATE stream: {source}")

        temp.replace(destination)
    except BaseException:
        temp.unlink(missing_ok=True)
        raise


def download_one(entry: dict, path: Path) -> None:
    download(entry["url"], path, entry["size"])
    decrypted = OBJECT_DIR_DECRYPTED / path.relative_to(OBJECT_DIR)
    if not decrypted.is_file() or decrypted.stat().st_size == 0:
        decrypt_ncae(path, decrypted)


def main() -> None:
    with (CATALOG_DIR / "effects_parsed.json").open(encoding="utf-8") as file:
        effects = json.load(file)
    with (CATALOG_DIR / "devices_parsed.json").open(encoding="utf-8") as file:
        devices = json.load(file)

    jobs = [
        (entry, OBJECT_DIR / f"{safe_component(entry['name'])}.ncae")
        for entry in effects
    ] + [
        (
            entry,
            OBJECT_DIR
            / safe_component(entry["brand"])
            / f"{safe_component(entry['model'])}.ncae",
        )
        for entry in devices
    ]

    paths = [path for _, path in jobs]
    if len(set(paths)) != len(paths):
        raise ValueError("Filename collision after sanitizing catalog names")

    errors = []
    with ThreadPoolExecutor(max_workers=MAX_WORKERS) as pool:
        futures = {pool.submit(download_one, entry, path): path for entry, path in jobs}
        for future in tqdm(
            as_completed(futures), total=len(futures), desc="Downloading", unit="file"
        ):
            try:
                future.result()
            except Exception as exc:
                errors.append((futures[future], exc))

    if errors:
        for path, exc in errors:
            print(f"FAILED: {path}: {exc}")
        raise RuntimeError(f"{len(errors)} NCAE files failed")


if __name__ == "__main__":
    main()
