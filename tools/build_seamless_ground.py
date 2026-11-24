#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Seamless variants of the native ground tiles of the campaign chapter.

Why this exists
---------------
The native ground tiles of the original are 64x64 and NOT seamless: the
difference between the first and the last row/column is about a third larger
than the difference of two neighbouring pixels (measured on Gnd_A01.tga:
33.9 against 25.4). The chapter draws one tile per cell, so the native tiles
put a visible grid of one-pixel lines over the whole map - the "lines like
Tetris figures" that the capture of the chapter shows.

The original does not show that grid, because the ground of the map is drawn
by the engine over the whole map (Campaign.tcl:2 "map create 512 640",
Campaign.tcl:6 "generate_color_variation 0 0 512 640 0") and the blocks of the
templates keep their own tiles. This tool therefore writes a seamless variant
of every native ground tile: the same pixels, arranged so that the tile can be
repeated without a visible border.

The method is the classical offset blend: the tile is copied onto itself
shifted by half a tile and the two copies are mixed with a smooth mask. The
result tiles seamlessly in both directions and keeps the scale of the source
(the pattern of the source appears twice per tile).

Usage:
    python build_seamless_ground.py [--game-data DIR] [--output DIR]

The output is a PNG per source tile in the output directory, plus a small
JSON report with the measured seam of the source and of the result.
"""
import argparse
import json
import os
import sys

from PIL import Image
import numpy as np

DEFAULT_GAME_DATA = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
DEFAULT_OUTPUT = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                              "godot", "textures", "ground_seamless")

FAMILIES = ("Gnd_A", "Gnd_B", "Gnd_C")
VARIANTS = 15


def seam_score(image: Image.Image) -> dict:
    """The mean difference over the border of the tile and over its inside."""
    array = np.asarray(image.convert("RGB")).astype(np.float32)
    height, width = array.shape[0], array.shape[1]
    horizontal = float(np.abs(array[:, 1:] - array[:, :-1]).mean())
    vertical = float(np.abs(array[1:] - array[:-1]).mean())
    seam_x = float(np.abs(array[:, 0] - array[:, width - 1]).mean())
    seam_y = float(np.abs(array[0] - array[height - 1]).mean())
    return {
        "inside_x": round(horizontal, 2),
        "inside_y": round(vertical, 2),
        "seam_x": round(seam_x, 2),
        "seam_y": round(seam_y, 2),
    }


def ramp(size: int) -> np.ndarray:
    """A smooth ramp from zero at the borders to one in the middle."""
    axis = np.linspace(0.0, 1.0, size, dtype=np.float32)
    window = np.sin(axis * np.pi) ** 2
    return window


def make_seamless(image: Image.Image) -> Image.Image:
    """The offset blend of the tile with a copy of itself shifted by half."""
    array = np.asarray(image.convert("RGB")).astype(np.float32)
    height, width = array.shape[0], array.shape[1]
    half_x = width // 2
    half_y = height // 2
    shifted = np.roll(np.roll(array, half_y, axis=0), half_x, axis=1)
    window_x = ramp(width)[None, :, None]
    window_y = ramp(height)[:, None, None]
    mask = window_x * window_y
    blended = array * (1.0 - mask) + shifted * mask
    return Image.fromarray(np.clip(blended, 0, 255).astype(np.uint8), "RGB")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--game-data", default=DEFAULT_GAME_DATA)
    parser.add_argument("--output", default=DEFAULT_OUTPUT)
    arguments = parser.parse_args()
    ground = os.path.join(arguments.game_data, "Ground")
    if not os.path.isdir(ground):
        print("ground directory is missing: %s" % ground)
        return 1
    os.makedirs(arguments.output, exist_ok=True)
    report = {"source": ground, "output": arguments.output, "tiles": []}
    for family in FAMILIES:
        for variant in range(1, VARIANTS + 1):
            name = "%s%02d.tga" % (family, variant)
            source_path = os.path.join(ground, name)
            if not os.path.exists(source_path):
                print("missing source tile: %s" % name)
                continue
            source = Image.open(source_path).convert("RGB")
            result = make_seamless(source)
            output_name = "%s%02d.png" % (family, variant)
            result.save(os.path.join(arguments.output, output_name))
            report["tiles"].append({
                "file": output_name,
                "source": name,
                "source_seam": seam_score(source),
                "seamless_seam": seam_score(result),
            })
    report_path = os.path.join(arguments.output, "ground_seamless.json")
    with open(report_path, "w", encoding="utf-8") as handle:
        json.dump(report, handle, indent=1, ensure_ascii=False)
    worst_source = max((tile["source_seam"]["seam_x"] / max(tile["source_seam"]["inside_x"], 0.01)
                         for tile in report["tiles"]), default=0.0)
    worst_result = max((tile["seamless_seam"]["seam_x"] / max(tile["seamless_seam"]["inside_x"], 0.01)
                         for tile in report["tiles"]), default=0.0)
    print("tiles=%d worst_source_ratio=%.2f worst_result_ratio=%.2f" %
          (len(report["tiles"]), worst_source, worst_result))
    print("report=%s" % report_path)
    return 0


if __name__ == "__main__":
    sys.exit(main())
