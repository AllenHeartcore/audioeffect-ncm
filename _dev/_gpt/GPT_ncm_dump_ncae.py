#!/usr/bin/env python3
"""Dump NetEase Cloud Music PC audio-effect .ncae assets.

Reconstructed from the PC client snapshot:
  ordinary effects: /api/usertool/sound/mobile/all
  device brands:    /api/usertool/home/soundeffect/devicebrand/list
  device profiles:  /api/usertool/home/soundeffect/devicesound/list

The PC client sends these through EAPI and then downloads the direct URL returned
by the catalog (link / deviceSoundUrl), verifying the supplied MD5.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import secrets
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

import requests
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes


EAPI_KEY = b"e82ckenh8dichen8"
EAPI_SEP = "-36cd479b6b5-"
DEFAULT_HOST = "https://interfacepc.music.163.com"
DEFAULT_APPVER = "3.1.29.205117"  # version in the supplied snapshot

EFFECTS_PATH = "/api/usertool/sound/mobile/all"
DEVICE_BRANDS_PATH = "/api/usertool/home/soundeffect/devicebrand/list"
DEVICE_SOUNDS_PATH = "/api/usertool/home/soundeffect/devicesound/list"


def json_compact(obj: Any) -> str:
    return json.dumps(obj, ensure_ascii=False, separators=(",", ":"))


def eapi_encrypt(path: str, payload: dict[str, Any]) -> str:
    """Return the uppercase hex EAPI `params` value used by the PC client."""
    text = json_compact(payload)
    digest = hashlib.md5(
        f"nobody{path}use{text}md5forencrypt".encode("utf-8")
    ).hexdigest()
    plaintext = f"{path}{EAPI_SEP}{text}{EAPI_SEP}{digest}".encode("utf-8")

    padder = padding.PKCS7(128).padder()
    padded = padder.update(plaintext) + padder.finalize()
    enc = Cipher(algorithms.AES(EAPI_KEY), modes.ECB()).encryptor()
    return (enc.update(padded) + enc.finalize()).hex().upper()


def parse_cookie_header(value: str) -> dict[str, str]:
    out: dict[str, str] = {}
    for part in value.split(";"):
        part = part.strip()
        if not part or "=" not in part:
            continue
        k, v = part.split("=", 1)
        out[k.strip()] = v.strip()
    return out


def make_session(cookie: str | None) -> requests.Session:
    s = requests.Session()
    s.headers.update(
        {
            "User-Agent": (
                "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                "AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120 Safari/537.36"
            ),
            "Referer": "https://music.163.com/",
            "Accept": "application/json, text/plain, */*",
        }
    )
    if cookie:
        s.cookies.update(parse_cookie_header(cookie))
    return s


def eapi_post(
    session: requests.Session,
    host: str,
    path: str,
    data: dict[str, Any] | None,
    *,
    appver: str,
    device_id: str,
    osver: str,
    client_sign: str | None,
    timeout: float,
) -> dict[str, Any]:
    # This mirrors the JS wrapper: request data + a JSON-stringified `header`.
    header: dict[str, Any] = {
        "os": "pc",
        "appver": appver,
        "deviceId": device_id,
        "requestId": 0,
        "osver": osver,
    }
    if client_sign:
        header["clientSign"] = client_sign

    payload = dict(data or {})
    payload["header"] = json_compact(header)

    params = eapi_encrypt(path, payload)
    suffix = path.removeprefix("/api/")
    url = f"{host.rstrip('/')}/eapi/{suffix}"
    r = session.post(
        url,
        data={"params": params},
        headers={"Content-Type": "application/x-www-form-urlencoded"},
        timeout=timeout,
    )
    r.raise_for_status()
    try:
        obj = r.json()
    except ValueError as exc:
        raise RuntimeError(f"non-JSON response from {url}: {r.text[:300]!r}") from exc

    code = obj.get("code")
    if code not in (None, 200, "200"):
        raise RuntimeError(f"NCM API {path} returned code={code}: {obj}")
    return obj


_INVALID_WIN = re.compile(r'[<>:"/\\|?*\x00-\x1f]')


def safe_name(name: Any, fallback: str) -> str:
    s = _INVALID_WIN.sub("_", str(name or "")).strip(" .")
    return (s or fallback)[:160]


def md5_file(path: Path, chunk: int = 1 << 20) -> str:
    h = hashlib.md5()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(chunk), b""):
            h.update(block)
    return h.hexdigest()


def download_asset(
    session: requests.Session,
    item: dict[str, Any],
    out_dir: Path,
    *,
    url_key: str,
    md5_key: str,
    id_key: str,
    name_key: str,
    overwrite: bool,
    timeout: float,
) -> tuple[str, str]:
    url = item.get(url_key)
    if not url:
        return "missing-url", str(item.get(id_key, "?"))

    asset_id = str(item.get(id_key, "unknown"))
    label = safe_name(item.get(name_key), asset_id)
    dest = out_dir / f"{safe_name(asset_id, 'unknown')}_{label}.ncae"
    want_md5 = str(item.get(md5_key) or "").lower()

    if dest.exists() and not overwrite:
        if not want_md5 or md5_file(dest).lower() == want_md5:
            return "skip", dest.name

    out_dir.mkdir(parents=True, exist_ok=True)
    fd, tmp_name = tempfile.mkstemp(prefix=dest.name + ".", suffix=".part", dir=out_dir)
    os.close(fd)
    tmp = Path(tmp_name)
    h = hashlib.md5()
    try:
        with session.get(str(url), stream=True, timeout=timeout) as r:
            r.raise_for_status()
            with tmp.open("wb") as f:
                for block in r.iter_content(1 << 20):
                    if block:
                        f.write(block)
                        h.update(block)
        got_md5 = h.hexdigest().lower()
        if want_md5 and got_md5 != want_md5:
            raise RuntimeError(
                f"MD5 mismatch for {asset_id} {label!r}: "
                f"expected {want_md5}, got {got_md5}"
            )
        tmp.replace(dest)
        return "ok", dest.name
    finally:
        tmp.unlink(missing_ok=True)


def dump_json(path: Path, obj: Any) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(obj, ensure_ascii=False, indent=2), encoding="utf-8")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("-o", "--out", type=Path, default=Path("ncm-ncae"))
    ap.add_argument(
        "--kind", choices=("effects", "devices", "all"), default="all",
        help="which static .ncae catalog(s) to dump",
    )
    ap.add_argument("--catalog-only", action="store_true", help="do not download .ncae files")
    ap.add_argument("--overwrite", action="store_true")
    ap.add_argument("--workers", type=int, default=6, help="parallel CDN downloads")
    ap.add_argument("--host", default=DEFAULT_HOST)
    ap.add_argument("--appver", default=DEFAULT_APPVER)
    ap.add_argument("--osver", default="Windows 11")
    ap.add_argument("--device-id", default=None)
    ap.add_argument("--client-sign", default=None)
    ap.add_argument(
        "--cookie",
        default=os.environ.get("NCM_COOKIE"),
        help="optional Cookie header; or set NCM_COOKIE",
    )
    ap.add_argument("--timeout", type=float, default=30.0)
    args = ap.parse_args()

    args.out.mkdir(parents=True, exist_ok=True)
    device_id_file = args.out / ".device_id"
    if args.device_id:
        device_id = args.device_id
    elif device_id_file.exists():
        device_id = device_id_file.read_text(encoding="ascii").strip()
    else:
        device_id = secrets.token_hex(16)
        device_id_file.write_text(device_id, encoding="ascii")

    session = make_session(args.cookie)
    common = dict(
        appver=args.appver,
        device_id=device_id,
        osver=args.osver,
        client_sign=args.client_sign,
        timeout=args.timeout,
    )

    effects: list[dict[str, Any]] = []
    brands: list[dict[str, Any]] = []
    devices: list[dict[str, Any]] = []

    if args.kind in ("effects", "all"):
        raw = eapi_post(session, args.host, EFFECTS_PATH, {}, **common)
        dump_json(args.out / "catalog-effects.raw.json", raw)
        effects = raw.get("data") or []
        if not isinstance(effects, list):
            raise RuntimeError("unexpected effects response: data is not a list")
        print(f"ordinary effects: {len(effects)}")

    if args.kind in ("devices", "all"):
        raw = eapi_post(session, args.host, DEVICE_BRANDS_PATH, {}, **common)
        dump_json(args.out / "catalog-device-brands.raw.json", raw)
        brands = raw.get("data") or []
        if not isinstance(brands, list):
            raise RuntimeError("unexpected device-brand response: data is not a list")
        print(f"device brands: {len(brands)}")

        for idx, brand in enumerate(brands, 1):
            manager_id = brand.get("deviceManagerId")
            if manager_id is None:
                print(f"[{idx}/{len(brands)}] brand without deviceManagerId: {brand}", file=sys.stderr)
                continue
            raw_models = eapi_post(
                session,
                args.host,
                DEVICE_SOUNDS_PATH,
                {"deviceManagerId": manager_id},
                **common,
            )
            models = raw_models.get("data") or []
            if not isinstance(models, list):
                raise RuntimeError(f"unexpected device response for manager {manager_id}")
            for model in models:
                model.setdefault("_deviceManagerId", manager_id)
                model.setdefault("_deviceName", brand.get("deviceName"))
            devices.extend(models)
            print(f"[{idx}/{len(brands)}] {brand.get('deviceName', manager_id)}: {len(models)}")

        dump_json(args.out / "catalog-devices.json", devices)
        print(f"device profiles: {len(devices)}")

    manifest = {
        "retrievedAt": datetime.now(timezone.utc).isoformat(),
        "apiHost": args.host,
        "appver": args.appver,
        "effectsEndpoint": EFFECTS_PATH,
        "deviceBrandsEndpoint": DEVICE_BRANDS_PATH,
        "deviceSoundsEndpoint": DEVICE_SOUNDS_PATH,
        "effects": effects,
        "deviceBrands": brands,
        "devices": devices,
    }
    dump_json(args.out / "manifest.json", manifest)

    if args.catalog_only:
        return 0

    jobs: list[tuple[dict[str, Any], Path, dict[str, str]]] = []
    if effects:
        for item in effects:
            jobs.append(
                (
                    item,
                    args.out / "effects",
                    dict(url_key="link", md5_key="md5", id_key="id", name_key="name"),
                )
            )
    if devices:
        for item in devices:
            jobs.append(
                (
                    item,
                    args.out / "devices",
                    dict(
                        url_key="deviceSoundUrl",
                        md5_key="soundMd5",
                        id_key="soundId",
                        name_key="deviceModel",
                    ),
                )
            )

    counts: dict[str, int] = {}
    with ThreadPoolExecutor(max_workers=max(1, args.workers)) as pool:
        futs = [
            pool.submit(
                download_asset,
                session,
                item,
                out_dir,
                overwrite=args.overwrite,
                timeout=args.timeout,
                **keys,
            )
            for item, out_dir, keys in jobs
        ]
        for i, fut in enumerate(as_completed(futs), 1):
            try:
                status, name = fut.result()
            except Exception as exc:
                status, name = "error", str(exc)
            counts[status] = counts.get(status, 0) + 1
            print(f"[{i}/{len(futs)}] {status:11} {name}")

    print("summary:", ", ".join(f"{k}={v}" for k, v in sorted(counts.items())))
    return 1 if counts.get("error") else 0


if __name__ == "__main__":
    raise SystemExit(main())
