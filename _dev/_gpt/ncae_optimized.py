"""Fetch and project NetEase Cloud Music's audio-effect and device catalogs.

Requires: requests, cryptography, tqdm
Raw responses are retained separately from the small, download-oriented projections.
"""

from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
from threading import local

import requests
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from tqdm import tqdm

EAPI_SERVER = "https://interfacepc.music.163.com"
EAPI_KEY = b"e82ckenh8dichen8"
EAPI_SEP = "-36cd479b6b5-"
EAPI_DIGEST = "nobody{}use{}md5forencrypt"

DEVICE_BRANDS_ENDPOINT = "/api/usertool/home/soundeffect/devicebrand/list"
DEVICE_MODELS_ENDPOINT = "/api/usertool/home/soundeffect/devicesound/list"
EFFECTS_ENDPOINT = "/api/usertool/sound/queryAllSound"
EFFECTS_EXPOSE_TYPES = (2, 3, 6, 7)
CLOUD_AUDIO_BRAND_ID = -1

CATALOG_DIR = Path(__file__).resolve().parent / "ncae_catalog"
MAX_WORKERS = 8
REQ_TIMEOUT = (5, 20)
_thread = local()


def session() -> requests.Session:
    """Keep one HTTP connection pool per worker; don't share Session across threads."""
    if not hasattr(_thread, "session"):
        _thread.session = requests.Session()
    return _thread.session


def json_dump(obj: dict | list, path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as file:
        json.dump(obj, file, ensure_ascii=False, indent=4)


def eapi_encrypt(path: str, payload: dict) -> str:
    # Preserve the original serialization and EAPI plaintext byte-for-byte.
    text = json.dumps(payload, separators=(",", ":"))
    digest = hashlib.md5(EAPI_DIGEST.format(path, text).encode()).hexdigest()
    plaintext = f"{path}{EAPI_SEP}{text}{EAPI_SEP}{digest}".encode()

    padder = padding.PKCS7(algorithms.AES.block_size).padder()
    padded = padder.update(plaintext) + padder.finalize()
    encryptor = Cipher(algorithms.AES(EAPI_KEY), modes.ECB()).encryptor()
    return (encryptor.update(padded) + encryptor.finalize()).hex().upper()


def eapi_post(path: str, payload: dict) -> dict:
    url = f"{EAPI_SERVER}/eapi/{path.removeprefix('/api/')}"
    with session().post(url, data={"params": eapi_encrypt(path, payload)}, timeout=REQ_TIMEOUT) as response:
        response.raise_for_status()
        result = response.json()
    if result.get("code") != 200:
        raise ValueError(f"EAPI {path}: {result.get('code')} {result.get('message', '')}")
    return result


def parse_effects(raw: dict[int, list[dict]]) -> list[dict]:
    """One downloadable effect per material MD5; retain the oldest ID.

    Prefer the URL/name/description attached to the highest ID (the newer
    catalog generation). No recursive or field-agnostic dictionary merging.
    """
    grouped = defaultdict(list)
    for entries in raw.values():
        for entry in entries:
            for material in entry.get("soundMaterialList") or ():
                grouped[material["md5"]].append((entry, material))

    effects = []
    for md5, versions in grouped.items():
        if len({material["size"] for _, material in versions}) != 1:
            raise ValueError(f"Conflicting sizes for effect {md5}")

        newest, material = max(versions, key=lambda pair: pair[0]["id"])
        effects.append({
            "id": min(entry["id"] for entry, _ in versions),
            "name": newest["name"],
            "desc": newest["subTitle"],
            "url": material["link"],
            "size": material["size"],
            "md5": md5,
        })

    return sorted(effects, key=lambda effect: (effect["id"], effect["md5"]))


def parse_devices(groups: list[tuple[str, list[dict]]]) -> list[dict]:
    """Merge duplicate sound IDs, checking that their downloadable data agrees."""
    devices = {}
    for brand, models in groups:
        for model in models:
            record = {
                "id": model["soundId"],
                "model": model["deviceModel"],
                "brand": brand,
                "url": model["deviceSoundUrl"],
                "size": model["size"],
                "md5": model["soundMd5"],
            }
            existing = devices.setdefault(record["id"], record)
            if any(existing[k] != record[k] for k in ("model", "url", "size", "md5")):
                raise ValueError(f"Conflicting device soundId={record['id']}")
    return sorted(devices.values(), key=lambda device: device["id"])


def main() -> None:
    raw_effects = {}
    for expose_type in EFFECTS_EXPOSE_TYPES:
        print(f"Fetching effects: exposeType={expose_type}")
        raw_effects[expose_type] = eapi_post(EFFECTS_ENDPOINT, {"exposeType": expose_type})["data"]
    json_dump(raw_effects, CATALOG_DIR / "effects_raw.json")
    json_dump(parse_effects(raw_effects), CATALOG_DIR / "effects_parsed.json")

    brands = eapi_post(DEVICE_BRANDS_ENDPOINT, {})["data"]
    json_dump(brands, CATALOG_DIR / "devices_raw_brands.json")

    jobs = [(brand["deviceManagerId"], brand["deviceName"])
            for brand in brands if brand["deviceManagerId"] != CLOUD_AUDIO_BRAND_ID]
    jobs.append((CLOUD_AUDIO_BRAND_ID, "Cloud Audio"))

    def fetch_models(brand_id: int) -> list[dict]:
        return eapi_post(DEVICE_MODELS_ENDPOINT, {"deviceManagerId": brand_id})["data"]

    with ThreadPoolExecutor(max_workers=MAX_WORKERS) as pool:
        results = list(tqdm(pool.map(fetch_models, (id_ for id_, _ in jobs)),
                            total=len(jobs), desc="Fetching device models"))

    groups = [(name, models) for (_, name), models in zip(jobs, results)]
    raw_models = {f"{id_}_{name}": models
                  for (id_, name), models in zip(jobs, results)
                  if id_ != CLOUD_AUDIO_BRAND_ID}
    json_dump(raw_models, CATALOG_DIR / "devices_raw_models.json")
    json_dump(results[-1], CATALOG_DIR / "devices_raw_models_cloudaudio.json")
    json_dump(parse_devices(groups), CATALOG_DIR / "devices_parsed.json")


if __name__ == "__main__":
    main()
