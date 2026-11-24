#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The colours of the pixels of one small patch of a capture.

Prints every pixel of the patch as R,G,B and marks the pixels that are darker
than a limit, so that a flat black area (a hole in the geometry or a plain
background) can be told apart from a dark texture.

Usage:
    python patch_rgb.py FRAME.png --box x0,y0,x1,y1 [--dark 30]

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("image")
    parser.add_argument("--box", required=True)
    parser.add_argument("--dark", type=float, default=30.0)
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.image):
        print("missing: %s" % arguments.image)
        return 1
    array = np.asarray(Image.open(arguments.image).convert("RGB")).astype(np.float32)
    x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
    patch = array[y0:y1, x0:x1]
    luminance = 0.299 * patch[:, :, 0] + 0.587 * patch[:, :, 1] + 0.114 * patch[:, :, 2]
    print("%s patch=%d,%d..%d,%d" % (os.path.basename(arguments.image), x0, y0, x1, y1))
    for row in range(patch.shape[0]):
        cells = []
        for col in range(patch.shape[1]):
            red, green, blue = patch[row, col]
            mark = "*" if luminance[row, col] < arguments.dark else " "
            cells.append("%3d/%3d/%3d%s" % (red, green, blue, mark))
        print("y=%4d  %s" % (y0 + row, "  ".join(cells)))
    dark = luminance < arguments.dark
    print()
    print("pixels darker than %.0f: %d of %d" % (arguments.dark, int(dark.sum()), dark.size))
    if dark.any():
        values = patch[dark]
        print("   their mean RGB: %.2f %.2f %.2f, sd of R %.2f, sd of G %.2f, sd of B %.2f" %
              (values[:, 0].mean(), values[:, 1].mean(), values[:, 2].mean(),
               values[:, 0].std(), values[:, 1].std(), values[:, 2].std()))
        print("   min RGB: %s  max RGB: %s" % (values.min(axis=0), values.max(axis=0)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
