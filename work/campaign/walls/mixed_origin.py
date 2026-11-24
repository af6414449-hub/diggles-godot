"""Where do the Native_* tiles come from, and do they need a mask?

Main Chat asks whether the mixed tiles of the project carry their own
transparency or have to be composed with the Msk_* masks of the game data.
This searches the whole game folder for the mixed tiles and the masks, and
tests how the project Native_* tiles relate to the base tiles and the masks:
for every mixed pattern it tries both blend directions and both the mask and
its inverse, and reports the best match.
"""
from __future__ import annotations

import json
import os

import numpy as np
from PIL import Image

PROJECT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot"
GROUND = os.path.join(PROJECT, "textures", "ground")
GAME_ROOT = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
GAME = os.path.join(GAME_ROOT, "data", "ground")
TABLE = os.path.join(PROJECT, "models", "native_terrain_render.json")


def load(path: str) -> np.ndarray:
    return np.asarray(Image.open(path).convert("RGB"), dtype=np.float32)


def find_in_game(prefix: str) -> list[str]:
    hits: list[str] = []
    for root, _dirs, files in os.walk(GAME_ROOT):
        for name in files:
            if name.startswith(prefix) and name.lower().endswith(".tga"):
                hits.append(os.path.join(root, name))
    return hits


def main() -> None:
    native_game = find_in_game("Native_")
    mask_game = find_in_game("Msk_")
    print(f"game folder: Native_* tga {len(native_game)}, Msk_* tga {len(mask_game)}")
    for path in native_game[:6]:
        print("  ", os.path.relpath(path, GAME_ROOT))
    for path in mask_game[:6]:
        print("  ", os.path.relpath(path, GAME_ROOT))

    with open(TABLE, encoding="utf-8") as fh:
        patterns = json.load(fh)["patterns"]
    mixed = {k: v for k, v in patterns.items() if v.get("mixed")}

    print("\nblend test (mean absolute difference, 0 = exact):")
    for signature in ("0001", "0011", "1122", "2201"):
        pattern = mixed.get(signature)
        if pattern is None:
            continue
        stored = load(os.path.join(GROUND, pattern["file"]))
        low = load(os.path.join(GAME, pattern["low"]))
        high = load(os.path.join(GAME, pattern["high"]))
        mask = load(os.path.join(GAME, pattern["mask"]))[:, :, 0] / 255.0

        def blend(a: np.ndarray, b: np.ndarray, weight: np.ndarray) -> np.ndarray:
            w = weight[:, :, None]
            return a * (1.0 - w) + b * w

        options = {
            "low->high by mask": blend(low, high, mask),
            "high->low by mask": blend(high, low, mask),
            "low->high by 1-mask": blend(low, high, 1.0 - mask),
            "high->low by 1-mask": blend(high, low, 1.0 - mask),
        }
        best = min(options.items(), key=lambda kv: float(np.abs(kv[1] - stored).mean()))
        errors = {k: round(float(np.abs(v - stored).mean()), 2) for k, v in options.items()}
        # how well does the stored tile match a single base tile?
        single = {
            "low only": float(np.abs(stored - low).mean()),
            "high only": float(np.abs(stored - high).mean()),
        }
        print(f"  {signature} {pattern['file']}: best '{best[0]}' = {float(np.abs(best[1] - stored).mean()):.2f}"
              f" | {errors} | {single}")


if __name__ == "__main__":
    main()
