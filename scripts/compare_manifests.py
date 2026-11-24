#!/usr/bin/env python3
"""Compare the live and snapshot scene manifests for the hamster integration.

Read-only. Reports placements of class Hamster / Grillpilz, the hamster model
package entries and whether the live manifest differs from the snapshot one.
"""
from __future__ import annotations

import hashlib
import json
from pathlib import Path

LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot\models\multi_start_010_models.json")
SNAP = Path(
    r"C:\Users\frant\.minimax\sessions\mvs_e213cb8b6788404489ad3b0b5c39827f"
    r"\workspace\Diggles-mcode\work\godot\models\multi_start_010_models.json"
)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1 << 20), b""):
            digest.update(block)
    return digest.hexdigest()


def report(tag: str, path: Path) -> dict:
    print(f"=== {tag}: {path}")
    if not path.is_file():
        print("  MISSING")
        return {}
    print(f"  bytes={path.stat().st_size} sha256={sha256(path)}")
    data = json.loads(path.read_text(encoding="utf-8"))
    print(f"  top-level keys: {sorted(data.keys())}")
    placements = data.get("placements", [])
    print(f"  placements={len(placements)}")
    hamster_placements = [p for p in placements if str(p.get("class", "")) == "Hamster"]
    food_placements = [p for p in placements if str(p.get("class", "")) == "Grillpilz"]
    pilz_placements = [p for p in placements if str(p.get("class", "")) == "Pilz"]
    print(f"  Hamster placements={len(hamster_placements)}")
    for p in hamster_placements:
        print(f"    {p.get('name', '')} model={p.get('model_package', '')}::{p.get('model_object', '')} "
              f"pos={p.get('position')} rot={p.get('rotation')} ordinal={p.get('ordinal')}")
    print(f"  Grillpilz placements={len(food_placements)}")
    for p in food_placements:
        print(f"    {p.get('name', '')} model={p.get('model_package', '')}::{p.get('model_object', '')} "
              f"pos={p.get('position')} ordinal={p.get('ordinal')}")
    print(f"  Pilz placements={len(pilz_placements)}")
    for p in pilz_placements[:8]:
        print(f"    {p.get('name', '')} model={p.get('model_package', '')}::{p.get('model_object', '')} "
              f"pos={p.get('position')} ordinal={p.get('ordinal')}")
    objects = data.get("objects", {})
    hamster_objects = []
    if isinstance(objects, dict):
        for key, value in objects.items():
            if "hamster" in key.lower():
                hamster_objects.append((key, value))
    else:
        for value in objects:
            key = f"{value.get('model_package', '')}::{value.get('model_object', '')}"
            if "hamster" in key.lower():
                hamster_objects.append((key, value))
    print(f"  hamster objects={len(hamster_objects)}")
    for key, value in hamster_objects[:6]:
        surfaces = value.get("surfaces") if isinstance(value, dict) else None
        count = len(surfaces) if isinstance(surfaces, list) else "n/a"
        print(f"    {key} surfaces={count}")
    return {"hash": sha256(path), "hamster": len(hamster_placements), "grillpilz": len(food_placements)}


def main() -> None:
    live = report("LIVE", LIVE)
    snap = report("SNAPSHOT", SNAP)
    print("=== manifest identical:", live.get("hash") == snap.get("hash"))


if __name__ == "__main__":
    main()
