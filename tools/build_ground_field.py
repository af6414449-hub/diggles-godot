#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The ground field of the campaign map: one seamless texture per native family.

Why this exists
---------------
The native ground tiles of the original are 64x64 and NOT seamless: the
difference between the first and the last row/column is about a third larger
than the difference of two neighbouring pixels (Gnd_A01.tga: 33.9 against
25.4). The chapter draws one tile per cell, so the native tiles put a visible
grid of one-pixel lines over the whole map - the "lines like Tetris figures"
that the capture of the chapter shows.

The original does not show that grid. The ground of the map is drawn by the
engine over the whole map (Campaign.tcl:2 "map create 512 640",
Campaign.tcl:6 "generate_color_variation 0 0 512 640 0") and the colour
variation is a field over the map, not a new texture per cell. So the port
needs one continuous ground texture per native family instead of one tile per
cell.

This tool builds that texture:
  - the canvas is 16x16 cells of 64x64 pixels, so the scale of the native tiles
    is kept (64 pixels per cell);
  - the fifteen native tiles of the family are laid over the canvas at free
    positions, with a random mirror and a soft edge, and every tile is drawn
    at its position and at the wrapped positions around it, so the canvas is
    seamless against itself;
  - no position of the canvas carries a border of a tile, so the field has no
    grid of 64 px: the grid of the slots was the source of the long stripes
    over the ground of the map.

The result tiles over the map without a grid, and the chapter cells and the
free ground use the same texture at the same scale, so the two fit together.

Usage:
    python build_ground_field.py [--game-data DIR] [--output DIR]
"""
import argparse
import json
import os
import sys

from PIL import Image
import numpy as np

DEFAULT_GAME_DATA = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
DEFAULT_OUTPUT = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                              "godot", "textures", "ground_field")
DEFAULT_TILES_OUTPUT = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                              "godot", "textures", "ground_tiles")

FAMILIES = ("Gnd_A", "Gnd_B", "Gnd_C")
VARIANTS = 15
TILE: int = 64
SLOTS: int = 16
CANVAS: int = TILE * SLOTS
## The number of tiles that are laid over the canvas of a family. Every tile
## covers a quarter of the canvas, so 48 of them cover it several times over.
PLACEMENTS: int = 1200
## The width of the soft edge of a tile, as a part of the tile. The edges of
## the tiles are feathered, so that two tiles blend into each other.
FEATHER: float = 0.25
## The width of the band in which a tile is blended with its rolled copy, so
## that the tile matches itself on all four sides.
SEAM_BAND: int = 12
SEED: int = 20261120


def seam_score(array: np.ndarray) -> dict:
    height, width = array.shape[0], array.shape[1]
    inside_x = float(np.abs(array[:, 1:] - array[:, :-1]).mean())
    inside_y = float(np.abs(array[1:] - array[:-1]).mean())
    seam_x = float(np.abs(array[:, 0] - array[:, width - 1]).mean())
    seam_y = float(np.abs(array[0] - array[height - 1]).mean())
    return {
        "inside_x": round(inside_x, 2),
        "inside_y": round(inside_y, 2),
        "seam_x": round(seam_x, 2),
        "seam_y": round(seam_y, 2),
    }


def make_seamless(tile: np.ndarray, band: int) -> np.ndarray:
    """Make a tile seamless against itself.

    The native tiles are 64x64 and their border does not match their inner
    pixels: the difference between the first and the last row is about a third
    larger than the difference of two neighbouring pixels. A field built from
    such tiles keeps the border of every tile, and the ground of the map shows
    a grid of one cell - the "tiled" look. The tile is therefore rolled by half
    and its border is blended with the rolled copy, so the tile matches itself
    on all four sides and the field has no grid.
    """
    size = tile.shape[0]
    half = size // 2
    out = tile.astype(np.float32).copy()
    rolled = np.roll(out, half, axis=0)
    rolled = np.roll(rolled, half, axis=1)
    for offset in range(band):
        weight = 0.5 * (1.0 + np.cos(np.pi * (offset + 0.5) / band))
        last = size - 1 - offset
        out[:, offset, :] = out[:, offset, :] * (1.0 - weight) + rolled[:, offset, :] * weight
        out[:, last, :] = out[:, last, :] * (1.0 - weight) + rolled[:, last, :] * weight
        out[offset, :, :] = out[offset, :, :] * (1.0 - weight) + rolled[offset, :, :] * weight
        out[last, :, :] = out[last, :, :] * (1.0 - weight) + rolled[last, :, :] * weight
    return out


def build_field(ground: str, family: str, rng: np.random.Generator) -> tuple:
    """One seamless field of a family, without a grid of slots.

    The native tiles are 64x64 and not seamless, so a canvas that is built
    from a grid of slots keeps a grid of 64 px: the seams of the slots are
    feathered, but the structure of the grid stays and reads as long stripes
    over the ground of the map. The tiles are therefore laid over the canvas
    at free positions with a soft mask, so that no position of the canvas
    carries a border of a tile. Every tile is drawn at its position and at the
    wrapped positions around it, so the canvas is seamless against itself.
    """
    canvas = np.zeros((CANVAS, CANVAS, 3), dtype=np.float32)
    # The base of the canvas is the mean of the tiles of the family and it
    # counts as one part of the weight, so that a place that no tile covers is
    # not a black hole.
    weight = np.ones((CANVAS, CANVAS), dtype=np.float32)
    tiles: list = []
    for variant in range(VARIANTS):
        source = Image.open(os.path.join(ground, "%s%02d.tga" % (family, variant + 1))).convert("RGB")
        tiles.append(make_seamless(np.asarray(source).astype(np.float32), SEAM_BAND))
    # The base of the canvas is the mean of the tiles of the family, so that a
    # place that no tile covers is not a black hole.
    mean_tile = np.mean(np.stack(tiles), axis=0)
    canvas[:] = np.tile(mean_tile, (SLOTS, SLOTS, 1))
    mask = np.zeros((TILE, TILE), dtype=np.float32)
    for y in range(TILE):
        for x in range(TILE):
            dx = min(x, TILE - 1 - x) / (TILE * 0.5)
            dy = min(y, TILE - 1 - y) / (TILE * 0.5)
            edge = min(dx, dy)
            mask[y, x] = min(1.0, edge / FEATHER)
    for _ in range(PLACEMENTS):
        variant = int(rng.integers(0, VARIANTS))
        source = tiles[variant]
        if rng.integers(0, 2) == 1:
            source = source[:, ::-1, :]
        if rng.integers(0, 2) == 1:
            source = source[::-1, :, :]
        offset_x = int(rng.integers(0, CANVAS))
        offset_y = int(rng.integers(0, CANVAS))
        for shift_y in (-CANVAS, 0, CANVAS):
            for shift_x in (-CANVAS, 0, CANVAS):
                start_x = offset_x + shift_x
                start_y = offset_y + shift_y
                # The part of the tile that lies on the canvas.
                begin_x = max(0, -start_x)
                begin_y = max(0, -start_y)
                end_x = min(TILE, CANVAS - start_x)
                end_y = min(TILE, CANVAS - start_y)
                if end_x <= begin_x or end_y <= begin_y:
                    continue
                target_x = start_x + begin_x
                target_y = start_y + begin_y
                patch = source[begin_y:end_y, begin_x:end_x, :]
                patch_mask = mask[begin_y:end_y, begin_x:end_x]
                canvas[target_y:target_y + patch.shape[0], target_x:target_x + patch.shape[1], :] += \
                    patch * patch_mask[:, :, None]
                weight[target_y:target_y + patch.shape[0], target_x:target_x + patch.shape[1]] += patch_mask
    safe = np.maximum(weight, 1e-5)
    canvas = canvas / safe[:, :, None]
    return np.clip(canvas, 0, 255).astype(np.uint8), canvas


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--game-data", default=DEFAULT_GAME_DATA)
    parser.add_argument("--output", default=DEFAULT_OUTPUT)
    parser.add_argument("--tiles-output", default=DEFAULT_TILES_OUTPUT)
    arguments = parser.parse_args()
    ground = os.path.join(arguments.game_data, "Ground")
    if not os.path.isdir(ground):
        print("ground directory is missing: %s" % ground)
        return 1
    os.makedirs(arguments.output, exist_ok=True)
    os.makedirs(arguments.tiles_output, exist_ok=True)
    report = {"source": ground, "output": arguments.output, "tile": TILE, "slots": SLOTS,
              "placements": PLACEMENTS, "feather": FEATHER, "seed": SEED,
              "fields": [], "tiles": []}
    # The native tiles of the original are written out one by one as well: the
    # cells of the chapter and the faces of the excavations are textured with
    # them, with the own UV of the export (on a tile of a cell u, v are the
    # local coordinates of the cell, on a wall v runs along the depth).
    for family in FAMILIES:
        for variant in range(VARIANTS):
            name = "%s%02d.png" % (family, variant + 1)
            tile = Image.open(os.path.join(ground, "%s%02d.tga" % (family, variant + 1))).convert("RGB")
            tile.save(os.path.join(arguments.tiles_output, name))
            report["tiles"].append({"file": name, "family": family, "variant": variant + 1})
    for index, family in enumerate(FAMILIES):
        rng = np.random.default_rng(SEED + index)
        pixels, _ = build_field(ground, family, rng)
        name = "ground_field_%s.png" % family[-1]
        Image.fromarray(pixels, "RGB").save(os.path.join(arguments.output, name))
        report["fields"].append({"file": name, "family": family, "seam": seam_score(pixels)})
    report_path = os.path.join(arguments.output, "ground_field.json")
    with open(report_path, "w", encoding="utf-8") as handle:
        json.dump(report, handle, indent=1, ensure_ascii=False)
    for field in report["fields"]:
        seam = field["seam"]
        print("%s seam_x=%.2f inside_x=%.2f ratio=%.2f" %
              (field["file"], seam["seam_x"], seam["inside_x"],
               seam["seam_x"] / max(seam["inside_x"], 0.01)))
    print("report=%s" % report_path)
    return 0


if __name__ == "__main__":
    sys.exit(main())
