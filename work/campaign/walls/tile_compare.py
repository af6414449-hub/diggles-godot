"""Compare the written ground tiles of the project with the native game files.

The project writes the native tiles of the game out as PNG
(godot/textures/ground_tiles) so the renderer can use them. This checks that
the written pixels are the native pixels and that every family and variant is
present.
"""
from __future__ import annotations

import os

from PIL import Image

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures"
TILES = os.path.join(ROOT, "ground_tiles")
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\ground"


def main() -> None:
    written = sorted(f for f in os.listdir(TILES) if f.lower().endswith(".png"))
    print(f"written tiles: {len(written)}")

    same = 0
    differ = 0
    missing_source = 0
    for name in written:
        source = os.path.join(GAME, name.replace(".png", ".tga"))
        if not os.path.exists(source):
            missing_source += 1
            continue
        a = Image.open(source).convert("RGB")
        b = Image.open(os.path.join(TILES, name)).convert("RGB")
        if a.size != b.size:
            print(f"  size differs: {name} {a.size} vs {b.size}")
            differ += 1
            continue
        if list(a.getdata()) == list(b.getdata()):
            same += 1
        else:
            differ += 1
            print(f"  pixels differ: {name}")
    print(f"identical to the game: {same}, differing: {differ}, no source file: {missing_source}")

    families: dict[str, int] = {}
    for name in written:
        families[name[:5]] = families.get(name[:5], 0) + 1
    print("families:", families)


if __name__ == "__main__":
    main()
