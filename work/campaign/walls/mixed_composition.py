"""Are the mixed Native_* tiles of the project already composed?

FUN_004cd020 of the original builds a mixed tile from two Gnd tiles and one Msk
mask. This checks whether the Native_* tiles of the project are that finished
composition: it rebuilds the tile from the mask and the two base tiles of the
game data and compares the pixels.

It also measures the banding of the continuous ground field, the reason the
field is being questioned: the canvas is 16x16 cells of 64 pixels, and if the
rows of the canvas differ in mean tone, the field shows horizontal stripes at a
far zoom.
"""
from __future__ import annotations

import json
import os

import numpy as np
from PIL import Image

PROJECT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot"
GROUND = os.path.join(PROJECT, "textures", "ground")
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\ground"
TABLE = os.path.join(PROJECT, "models", "native_terrain_render.json")


def load(path: str) -> np.ndarray:
    return np.asarray(Image.open(path).convert("RGB"), dtype=np.float32)


def compose(low: np.ndarray, high: np.ndarray, mask: np.ndarray) -> np.ndarray:
    """Blend two tiles with a mask, as the engine does (FUN_004cd020)."""
    if mask.ndim == 3:
        mask = mask[:, :, 0]
    alpha = (mask / 255.0)[:, :, None]
    return low * (1.0 - alpha) + high * alpha


def main() -> None:
    with open(TABLE, encoding="utf-8") as fh:
        patterns = json.load(fh)["patterns"]

    mixed = {k: v for k, v in patterns.items() if v.get("mixed")}
    print(f"mixed patterns in the table: {len(mixed)}")

    for signature in ("0001", "0011", "1122"):
        pattern = mixed.get(signature)
        if pattern is None:
            continue
        native = os.path.join(GROUND, pattern["file"])
        low = load(os.path.join(GAME, pattern["low"]))
        high = load(os.path.join(GAME, pattern["high"]))
        mask = load(os.path.join(GAME, pattern["mask"]))
        built = compose(low, high, mask)
        stored = load(native)
        diff = float(np.abs(built - stored).mean())
        print(
            f"  {signature}: {pattern['file']} = {pattern['low']} + {pattern['high']} "
            f"via {pattern['mask']} -> mean abs difference {diff:.2f}"
        )

    print("\ncontinuous field banding (mean tone of every 64 pixel row band):")
    for name in ("A", "B", "C"):
        image = load(os.path.join(PROJECT, "textures", "ground_field", f"ground_field_{name}.png"))
        luma = image.mean(axis=2)
        rows = luma.reshape(luma.shape[0] // 64, 64, luma.shape[1]).mean(axis=(1, 2))
        spread = float(rows.max() - rows.min())
        print(f"  ground_field_{name}.png: row means {rows.min():.2f}…{rows.max():.2f} "
              f"(spread {spread:.2f}), per row: {np.round(rows, 1).tolist()}")
        cols = luma[:, :].reshape(luma.shape[0], luma.shape[1] // 64, 64).mean(axis=(0, 2))
        print(f"      column means spread {float(cols.max() - cols.min()):.2f}")


if __name__ == "__main__":
    main()
