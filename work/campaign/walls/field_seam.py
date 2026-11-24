#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The seams of the ground field texture.

The terrain of the port samples the ground field with continuous coordinates,
so every map cell gets a patch of 64 pixels of the field.  If the patch of a
cell carries a dark border, the picture of the ground shows a dark line at
every cell boundary.  This script measures the tone of the field along a row
and a column and prints it around every boundary of the cells.

Usage:
    python field_seam.py [--folder PATH] [--file ground_field_A.png] [--cells 16]

Read-only: it only reads the PNG files of the ground field.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--folder", default=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\ground_field")
    parser.add_argument("--file", default="ground_field_A.png")
    parser.add_argument("--cells", type=int, default=16)
    parser.add_argument("--row", type=int, default=300)
    parser.add_argument("--column", type=int, default=300)
    parser.add_argument("--span", type=int, default=10)
    arguments = parser.parse_args()
    path = os.path.join(arguments.folder, arguments.file)
    if not os.path.isfile(path):
        print("missing: %s" % path)
        return 1
    array = np.asarray(Image.open(path).convert("RGB")).astype(np.float32)
    tone = 0.299 * array[:, :, 0] + 0.587 * array[:, :, 1] + 0.114 * array[:, :, 2]
    height, width = tone.shape
    step = width // arguments.cells
    print("%s  %dx%d, %d cells of %d px" % (os.path.basename(path), width, height,
                                            arguments.cells, step))
    print("row %d: the tone around every boundary of the cells" % arguments.row)
    for cell in range(arguments.cells):
        edge = cell * step
        values = tone[arguments.row, max(0, edge - arguments.span):edge + arguments.span + 1]
        print("   cell %2d, edge at %4d: %s" %
              (cell, edge, " ".join("%5.1f" % value for value in values)))
    print("column %d: the tone around every boundary of the cells" % arguments.column)
    for cell in range(arguments.cells):
        edge = cell * step
        values = tone[max(0, edge - arguments.span):edge + arguments.span + 1, arguments.column]
        print("   cell %2d, edge at %4d: %s" %
              (cell, edge, " ".join("%5.1f" % value for value in values)))
    inside = tone[4:step - 4, 4:step - 4]
    border = []
    for cell in range(arguments.cells):
        edge = cell * step
        border.append(tone[arguments.row, max(0, edge - 4):edge + 5].mean())
    print()
    print("mean of the field inside the cells: %.2f" % float(inside.mean()))
    print("mean of the tone on the boundaries of the cells: %s" %
          (" ".join("%5.1f" % value for value in border)))
    print("ratio of the boundary to the inside: %.3f" %
          (float(np.mean(border)) / max(float(inside.mean()), 1e-6)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
