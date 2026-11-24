#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Step of the brightness between two neighbours, in texture space.

Two ways to draw the ground of the map are compared with the same measure:
  - one native tile per cell (the cells of the chapter and, in the port, the
    free ground as well): every cell takes a random variant of its family, so
    the step between two neighbouring cells is the step between two different
    tiles of the same family;
  - one continuous field per family (tools/build_ground_field.py): the canvas
    is 16x16 slots of one tile each, so the step between two neighbouring
    bands of 64 pixels is the step of the means of the slot rows.

Every step is compared with the noise inside a tile (the mean |difference|
between neighbouring pixels), so the numbers say how far the structure stands
out of the texture.

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image

TILE = 64
SLOTS = 16
FAMILIES = ("A", "B", "C")


def load(path: str) -> np.ndarray:
    return np.asarray(Image.open(path).convert("L")).astype(np.float32)


def pixel_noise(array: np.ndarray) -> float:
    """Mean |difference| between neighbouring pixels."""
    return float(np.abs(np.diff(array, axis=1)).mean())


def family_tiles(tiles_dir: str, family: str) -> list:
    found = []
    for index in range(1, 16):
        path = os.path.join(tiles_dir, "Gnd_%s%02d.png" % (family, index))
        if os.path.isfile(path):
            found.append((path, load(path)))
    return found


def tile_steps(tiles_dir: str, family: str) -> dict:
    tiles = family_tiles(tiles_dir, family)
    means = np.array([float(array.mean()) for _, array in tiles])
    noise = float(np.mean([pixel_noise(array) for _, array in tiles]))
    # The step between two different tiles of the same family: the mean of the
    # |difference| over all pairs, and the worst pair.
    steps = [abs(float(means[i]) - float(means[j]))
             for i in range(len(means)) for j in range(i + 1, len(means))]
    return {
        "family": family,
        "tiles": len(tiles),
        "noise": noise,
        "mean_spread": float(means.max() - means.min()),
        "step_mean": float(np.mean(steps)) if steps else 0.0,
        "step_max": float(np.max(steps)) if steps else 0.0,
        "step_ratio_mean": float(np.mean(steps)) / max(noise, 1e-6),
        "step_ratio_max": float(np.max(steps)) / max(noise, 1e-6),
        "means": [round(float(value), 2) for value in means],
    }


def field_steps(field_path: str) -> dict:
    array = load(field_path)
    height, width = array.shape
    rows = []
    for slot in range(SLOTS):
        band = array[slot * TILE:(slot + 1) * TILE, :]
        rows.append(float(band.mean()))
    columns = []
    for slot in range(SLOTS):
        band = array[:, slot * TILE:(slot + 1) * TILE]
        columns.append(float(band.mean()))
    row_steps = [abs(rows[i + 1] - rows[i]) for i in range(len(rows) - 1)]
    column_steps = [abs(columns[i + 1] - columns[i]) for i in range(len(columns) - 1)]
    noise = pixel_noise(array)
    return {
        "file": os.path.basename(field_path),
        "size": [width, height],
        "noise": noise,
        "rows": [round(value, 2) for value in rows],
        "columns": [round(value, 2) for value in columns],
        "row_step_mean": float(np.mean(row_steps)),
        "row_step_max": float(np.max(row_steps)),
        "row_ratio_mean": float(np.mean(row_steps)) / max(noise, 1e-6),
        "row_ratio_max": float(np.max(row_steps)) / max(noise, 1e-6),
        "column_step_mean": float(np.mean(column_steps)),
        "column_step_max": float(np.max(column_steps)),
        "column_ratio_mean": float(np.mean(column_steps)) / max(noise, 1e-6),
        "column_ratio_max": float(np.max(column_steps)) / max(noise, 1e-6),
        "row_spread": float(max(rows) - min(rows)),
        "column_spread": float(max(columns) - min(columns)),
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--tiles", required=True, help="directory with Gnd_XX.png")
    parser.add_argument("--fields", required=True, help="directory with ground_field_X.png")
    arguments = parser.parse_args()

    print("=== one native tile per cell ===")
    for family in FAMILIES:
        row = tile_steps(arguments.tiles, family)
        print("family %s: tiles=%d  noise=%.2f  mean_spread=%.2f" %
              (row["family"], row["tiles"], row["noise"], row["mean_spread"]))
        print("   step between two cells: mean=%.2f (x%.2f of the noise)  max=%.2f (x%.2f)" %
              (row["step_mean"], row["step_ratio_mean"], row["step_max"], row["step_ratio_max"]))
        print("   tile means: %s" % row["means"])

    print()
    print("=== continuous field ===")
    for family in FAMILIES:
        path = os.path.join(arguments.fields, "ground_field_%s.png" % family)
        if not os.path.isfile(path):
            print("missing: %s" % path)
            continue
        row = field_steps(path)
        print("%s  size=%s  noise=%.2f" % (row["file"], row["size"], row["noise"]))
        print("   step between two bands (rows):    mean=%.2f (x%.2f)  max=%.2f (x%.2f)  spread=%.2f" %
              (row["row_step_mean"], row["row_ratio_mean"], row["row_step_max"],
               row["row_ratio_max"], row["row_spread"]))
        print("   step between two bands (columns): mean=%.2f (x%.2f)  max=%.2f (x%.2f)  spread=%.2f" %
              (row["column_step_mean"], row["column_ratio_mean"], row["column_step_max"],
               row["column_ratio_max"], row["column_spread"]))
        print("   row means:    %s" % row["rows"])
        print("   column means: %s" % row["columns"])
    return 0


if __name__ == "__main__":
    sys.exit(main())
