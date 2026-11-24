"""Alpha in the mixed ground tiles: project Native_* versus game Msk_*.

Main Chat asks whether the mixed tiles of the project carry their own
transparency (alpha) or have to be composed with the Msk_* masks of the game
data. This measures the channels of both sets and checks whether a mixed tile
can be drawn as one texture.

It also answers the second question empirically: a mixed tile of the original is
built from two Gnd tiles and one Msk mask (FUN_004cd020). If the project
Native_* tiles are already that composition, they are opaque and one tile is
enough; if they still carry the mask in alpha, they need the mask.
"""
from __future__ import annotations

import os
from collections import Counter

from PIL import Image

PROJECT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\ground"
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\ground"


def channels(path: str) -> tuple[str, tuple[int, int, int, int]]:
    image = Image.open(path)
    bands = image.split()
    names = ("R", "G", "B", "A")[: len(bands)]
    means = tuple(
        round(sum(b.getdata()) / max(len(list(b.getdata())), 1)) for b in bands
    )
    return f"{image.mode}/{image.size}", means


def alpha_stats(path: str) -> str:
    image = Image.open(path)
    if "A" not in image.mode:
        return "no alpha channel"
    alpha = image.getchannel("A")
    data = list(alpha.getdata())
    hist = Counter(data)
    return f"alpha min={min(data)} max={max(data)} mean={sum(data) / len(data):.1f} distinct={len(hist)}"


def main() -> None:
    project_native = sorted(f for f in os.listdir(PROJECT)
                            if f.startswith("Native_") and f.lower().endswith(".tga"))
    game_masks = sorted(f for f in os.listdir(GAME)
                        if f.startswith("Msk_") and f.lower().endswith(".tga"))
    game_gnd = sorted(f for f in os.listdir(GAME)
                      if f.startswith("Gnd_") and f.lower().endswith(".tga"))

    print(f"project Native_* files: {len(project_native)}")
    with_alpha = 0
    sizes = set()
    for name in project_native:
        path = os.path.join(PROJECT, name)
        info, means = channels(path)
        sizes.add(info)
        if "no alpha channel" not in info:
            with_alpha += 1
            print(f"  {name}: {info} channel means={means}")
    print(f"  files with an alpha channel: {with_alpha} of {len(project_native)}")
    print(f"  formats and sizes: {sorted(sizes)}")
    for name in project_native[:2]:
        path = os.path.join(PROJECT, name)
        print(f"  {name}: {alpha_stats(path)}")

    print(f"\ngame Msk_* files: {len(game_masks)}")
    for name in game_masks[:2]:
        path = os.path.join(GAME, name)
        info, means = channels(path)
        print(f"  {name}: {info} channel means={means}")
        print(f"      {alpha_stats(path)}")

    print("\ngame Gnd_* files (base tiles):")
    for name in game_gnd[:3]:
        path = os.path.join(GAME, name)
        info, means = channels(path)
        print(f"  {name}: {info} channel means={means}")
        print(f"      {alpha_stats(path)}")

    # Are all project mixed tiles opaque and all masks single channel?
    opaque = 0
    not_opaque = 0
    for name in project_native:
        image = Image.open(os.path.join(PROJECT, name))
        if "A" in image.mode and image.getchannel("A").getextrema()[0] < 255:
            not_opaque += 1
        else:
            opaque += 1
    print(f"\nproject mixed tiles: fully opaque {opaque}, with transparency {not_opaque}")

    mask_modes = Counter()
    for name in game_masks:
        mask_modes[Image.open(os.path.join(GAME, name)).mode] += 1
    print("game mask modes:", dict(mask_modes))


if __name__ == "__main__":
    main()
