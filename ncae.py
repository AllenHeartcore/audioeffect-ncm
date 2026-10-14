import asyncio
import hashlib
import json
from pathlib import Path
from urllib.parse import urljoin, urlparse

import requests
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from tqdm import tqdm

EAPI_SERVER = "https://interfacepc.music.163.com/"
EAPI_KEY = b"e82ckenh8dichen8"
EAPI_SEP = "-36cd479b6b5-"
EAPI_DIGEST = "nobody{}use{}md5forencrypt"
EAPI_PLAINTEXT = "{}{}{}{}{}".format("{}", EAPI_SEP, "{}", EAPI_SEP, "{}")

DEVICE_BRANDS_ENDPOINT = "/api/usertool/home/soundeffect/devicebrand/list"
DEVICE_MODELS_ENDPOINT = "/api/usertool/home/soundeffect/devicesound/list"
EFFECTS_ENDPOINT = "/api/usertool/sound/queryAllSound"
EFFECTS_EXPOSE_TYPES = (2, 3, 6, 7)
CLOUD_AUDIO_BRAND_ID = -1

CATALOG_DIR = Path(__file__).parent / "ncae_catalog"
REQ_TIMEOUT = 10


def _rget(url: str, **kwargs) -> requests.Response:
    r = requests.get(url, timeout=REQ_TIMEOUT, **kwargs)
    r.raise_for_status()
    return r


def _rpost(url: str, **kwargs) -> requests.Response:
    r = requests.post(url, timeout=REQ_TIMEOUT, **kwargs)
    r.raise_for_status()
    return r


def json_dump(obj: dict | list, path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as fout:
        json.dump(obj, fout, ensure_ascii=False, indent=4)


def json_compact(obj: dict | list) -> str:
    return json.dumps(obj, separators=(",", ":"))


def eapi_encrypt(path: str, payload: dict) -> str:

    padder = padding.PKCS7(algorithms.AES.block_size).padder()
    encryptor = Cipher(algorithms.AES(EAPI_KEY), modes.ECB()).encryptor()

    text = json_compact(payload)
    digest = hashlib.md5(EAPI_DIGEST.format(path, text).encode("utf-8")).hexdigest()
    dec = EAPI_PLAINTEXT.format(path, text, digest).encode("utf-8")

    enc = padder.update(dec) + padder.finalize()
    enc = encryptor.update(enc) + encryptor.finalize()
    return enc.hex().upper()


def eapi_post(path: str, data: dict) -> dict:
    r = _rpost(
        urljoin(EAPI_SERVER, "/eapi/" + path.removeprefix("/api/")),
        data={"params": eapi_encrypt(path, data)},
    )
    return r.json()


if __name__ == "__main__":

    # ------------ Raw effects
    _effects = {}

    for _type in EFFECTS_EXPOSE_TYPES:
        print(f"Fetching effects for exposeType={_type}...")
        _effects[_type] = eapi_post(EFFECTS_ENDPOINT, {"exposeType": _type})["data"]

    json_dump(_effects, CATALOG_DIR / "effects_raw.json")

    # ------------ Parsed effects
    print("Parsing effects...")

    effects = {}
    for _e in sum(_effects.values(), []):

        _id = _e["id"]
        _name = _e["name"]
        _desc = _e["subTitle"]

        assert len(_e["soundMaterialList"]) == 1
        _sml = _e["soundMaterialList"][0]
        _url = _sml["link"]
        _size = _sml["size"]
        _md5 = _sml["md5"]

        if _md5 not in effects:
            effects[_md5] = {"id": _id, "name": _name, "desc": _desc, "url": _url, "size": _size, "md5": _md5}
        elif effects[_md5]["id"] < _id:
            ptr = effects[_md5]
            assert ptr["size"] == _size
            ptr["name"] = _name
            ptr["desc"] = _desc
            ptr["url"] = _url
            # but keep the smaller id

    effects = list(effects.values())
    effects.sort(key=lambda x: x["id"])
    servers = list(set([urlparse(e["url"]).netloc for e in effects]))
    for e in effects:
        e["url"] = urlparse(e["url"])._replace(netloc=servers[0]).geturl()
    json_dump(effects, CATALOG_DIR / "effects_parsed.json")

    # ----------- Raw device brands
    print("Fetching device brands...")

    _brands = eapi_post(DEVICE_BRANDS_ENDPOINT, {})["data"]
    json_dump(_brands, CATALOG_DIR / "devices_raw_brands.json")

    # ----------- Raw device models

    def fetch_device_model(brand_id: int, prog: tqdm) -> list[dict]:
        ret = eapi_post(DEVICE_MODELS_ENDPOINT, {"deviceManagerId": brand_id})["data"]
        prog.update()
        return ret

    async def fetch_device_models(brand_ids: list[int]) -> list[list[dict]]:
        with tqdm(total=len(brand_ids), desc="Fetching device models") as prog:
            return await asyncio.gather(
                *(asyncio.to_thread(fetch_device_model, brand_id, prog) for brand_id in brand_ids)
            )

    _brands = [b for b in _brands if b["deviceManagerId"] != CLOUD_AUDIO_BRAND_ID]
    _models = asyncio.run(fetch_device_models([b["deviceManagerId"] for b in _brands]))
    json_dump(
        {f"{b['deviceManagerId']}_{b['deviceName']}": ms for b, ms in zip(_brands, _models)},
        CATALOG_DIR / "devices_raw_models.json",
    )

    # "Cloud Audio"
    _models_ca = eapi_post(DEVICE_MODELS_ENDPOINT, {"deviceManagerId": CLOUD_AUDIO_BRAND_ID})["data"]
    json_dump(_models_ca, CATALOG_DIR / "devices_raw_models_cloudaudio.json")

    # ---------- Parsed device models
    print("Parsing device models...")

    _rectify = lambda brand_name, model: {
        "id": model["soundId"],
        "model": model["deviceModel"],
        "brand": brand_name,
        "url": model["deviceSoundUrl"],
        "size": model["size"],
        "md5": model["soundMd5"],
    }
    models = {_m["soundId"]: _rectify(b["deviceName"], _m) for b, ms in zip(_brands, _models) for _m in ms}
    for _m in _models_ca:
        m = _rectify("Cloud Audio", _m)
        if m["id"] not in models:
            models[m["id"]] = m
        else:
            ptr = models[m["id"]]
            assert all(ptr[field] == m[field] for field in ("model", "url", "size", "md5"))

    models = list(models.values())
    servers = list(set([urlparse(m["url"]).netloc for m in models]))
    for m in models:
        m["url"] = urlparse(m["url"])._replace(netloc=servers[0]).geturl()
    json_dump(models, CATALOG_DIR / "devices_parsed.json")
