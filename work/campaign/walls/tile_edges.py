#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The edges of the ground tiles of the original.

The original picks the tile of a cell of the surface by its four corners
(FUN_004c4ae0), so a tile can carry a dark edge on the side where the ground
next to it is lower - the dig plan of the excavations would then be drawn by
the tiles themselves.  This script measures every tile of the ground: the tone
of the four edge strips against the tone of the middle of the tile.

Usage:
    python tile_edges.py [--folder PATH] [--width 8]

Read-only: it only reads the TGA and the PNG files of the ground.
"""
import argparse
import glob
import os
import sys

import numpy as np
from PIL import Image


def load(path: str) -> np.ndarray:
    if path.lower().endswith(".tga"):
        return np.asarray(Image.open(path).convert("RGB")).astype(np.float32)
    return np.asarray(Image.open(path).convert("RGB")).astype(np.float32)


def strip(tone: np.ndarray, side: str, width: int) -> np.ndarray:
    height, _ = tone.shape
    if side == "top":
        return tone[:width, :].reshape(-1)
    if side == "bottom":
        return tone[height - width:, :].reshape(-1)
    if side == "left":
        return tone[:, :width].reshape(-1)
    return tone[:, tone.shape[1] - width:].reshape(-1)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--folder", default=r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\Ground")
    parser.add_argument("--width", type=int, default=8)
    parser.add_argument("--pattern", default="Gnd_*")
    arguments = parser.parse_args()
    paths = sorted(glob.glob(os.path.join(arguments.folder, arguments.pattern)))
    if not paths:
        print("no tiles in %s" % arguments.folder)
        return 1
    print("%d tiles, edge strip %d px" % (len(paths), arguments.width))
    print("%-28s %8s %8s %8s %8s %8s %8s" %
          ("tile", "middle", "top", "bottom", "left", "right", "min edge"))
    dark = []
    for path in paths:
        array = load(path)
        tone = 0.299 * array[:, :, 0] + 0.587 * array[:, :, 1] + 0.114 * array[:, :, 2]
        height, width = tone.shape
        middle = tone[arguments.width:height - arguments.width,
                      arguments.width:width - arguments.width]
        if middle.size == 0:
            middle = tone
        values = {"top": 0, "bottom": 0, "left": 0, "right": 0}
        for side in values:
            values[side] = float(strip(tone, side, arguments.width).mean())
        base = float(middle.mean())
        lowest = min(values, key=lambda side: values[side])
        delta = values[lowest] - base
        print("%-28s %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f (%+.2f %s)" %
              (os.path.basename(path), base, values["top"], values["bottom"],
               values["left"], values["right"], values[lowest], delta, lowest))
        if delta < -6.0:
            dark.append((os.path.basename(path), delta, lowest))
    print()
    print("tiles with an edge more than 6 units darker than the middle: %d" % len(dark))
    for name, delta, side in dark:
        print("   %-28s %s edge %+.2f" % (name, side, delta))
    return 0


if __name__ == "__main__":
    sys.exit(main())
