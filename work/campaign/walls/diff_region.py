#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""What changed between two captures of the scene.

The difference of the two frames shows which part of the picture belongs to the
part that was switched off. The script prints the share of changed pixels per
band of 64 rows and per band of 64 columns, so the area of the part is seen
without looking at the frames.

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image

BAND = 64
THRESHOLD = 6


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("first")
    parser.add_argument("second")
    parser.add_argument("--threshold", type=int, default=THRESHOLD)
    arguments = parser.parse_args()
    first = np.asarray(Image.open(arguments.first).convert("RGB")).astype(np.int16)
    second = np.asarray(Image.open(arguments.second).convert("RGB")).astype(np.int16)
    if first.shape != second.shape:
        print("different size: %s vs %s" % (first.shape, second.shape))
        return 1
    difference = np.abs(first - second).max(axis=2)
    changed = difference > arguments.threshold
    print("%s  vs  %s" % (os.path.basename(arguments.first), os.path.basename(arguments.second)))
    print("changed pixels: %.2f %%  (threshold %d)" % (100.0 * changed.mean(), arguments.threshold))
    rows = np.nonzero(changed.any(axis=1))[0]
    columns = np.nonzero(changed.any(axis=0))[0]
    if len(rows) and len(columns):
        print("changed area: x %d..%d  y %d..%d" %
              (columns.min(), columns.max(), rows.min(), rows.max()))
    print("rows (share of changed pixels per %d px):" % BAND)
    for row in range(0, changed.shape[0], BAND):
        band = changed[row:row + BAND]
        share = 100.0 * band.mean()
        if share > 0.5:
            print("   y %4d..%4d : %5.1f %%  %s" % (row, row + BAND, share,
                                                   "#" * int(share / 2)))
    print("columns (share of changed pixels per %d px):" % BAND)
    for column in range(0, changed.shape[1], BAND):
        band = changed[:, column:column + BAND]
        share = 100.0 * band.mean()
        if share > 0.5:
            print("   x %4d..%4d : %5.1f %%  %s" % (column, column + BAND, share,
                                                   "#" * int(share / 2)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
