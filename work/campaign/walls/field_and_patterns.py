"""Ground field resolution, tile pattern table and the ground material map.

Answers three questions for the native tile step:
  1. how many pixels per cell the continuous ground field has today;
  2. how many mixed tiles the shared pattern table references and whether the
     project carries them;
  3. what the per-cell ground material map of the campaign holds.
"""
from __future__ import annotations

import json
import os

from PIL import Image

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot"


def main() -> None:
    for name in ("A", "B", "C"):
        path = os.path.join(ROOT, "textures", "ground_field", f"ground_field_{name}.png")
        image = Image.open(path)
        print(f"ground_field_{name}.png {image.size} {image.mode} "
              f"-> {image.size[0] / 16.0:.1f} px per cell over a 16 cell field")

    with open(os.path.join(ROOT, "models", "native_terrain_render.json"), encoding="utf-8") as fh:
        table = json.load(fh)
    patterns = table["patterns"]
    mixed = [v for v in patterns.values() if v.get("mixed")]
    files = sorted({v["file"] for v in mixed})
    print(f"\npatterns: {len(patterns)} total, {len(mixed)} mixed, {len(patterns) - len(mixed)} single family")
    print(f"mixed files referenced: {len(files)}")
    print("example:", files[:5])

    ground = os.path.join(ROOT, "textures", "ground")
    on_disk = {f for f in os.listdir(ground) if f.lower().endswith(".tga")}
    missing = [f for f in files if f not in on_disk]
    print(f"mixed files missing on disk: {len(missing)} {missing[:5]}")

    masks = sorted({v["mask"] for v in mixed if v.get("mask")})
    print(f"mask files referenced: {len(masks)}")
    missing_masks = [m for m in masks if m not in on_disk]
    print(f"mask files missing on disk: {len(missing_masks)} {missing_masks[:5]}")

    with open(os.path.join(ROOT, "models", "native_campaign_ground_material.json"), encoding="utf-8") as fh:
        gm = json.load(fh)
    print("\nground_material keys:", list(gm.keys())[:8])
    for key, value in list(gm.items())[:6]:
        size = len(value) if hasattr(value, "__len__") else value
        print("  ", key, type(value).__name__, size)


if __name__ == "__main__":
    main()
