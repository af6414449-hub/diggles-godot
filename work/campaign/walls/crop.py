#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""A magnified crop of a capture, with an optional profile of the rows.

Usage:
    python crop.py FRAME.png --box x0,y0,x1,y1 [--scale 6] [--out OUT.png]
        [--profile X] [--profile-width 20]

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
    parser.add_argument("--box", required=True, help="x0,y0,x1,y1")
    parser.add_argument("--scale", type=float, default=6.0)
    parser.add_argument("--out", default="")
    parser.add_argument("--profile", type=int, default=-1,
                        help="the column of the profile, -1 for none")
    parser.add_argument("--profile-width", type=int, default=20)
    arguments = parser.parse_args()

    image = Image.open(arguments.image).convert("RGB")
    x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
    crop = image.crop((x0, y0, x1, y1))
    scale = arguments.scale
    big = crop.resize((max(1, int(crop.width * scale)), max(1, int(crop.height * scale))),
                      Image.NEAREST)
    out = arguments.out or os.path.splitext(arguments.image)[0] + "-crop.png"
    big.save(out)
    print("saved %s (%dx%d)" % (out, big.width, big.height))

    if arguments.profile >= 0:
        array = np.asarray(crop).astype(np.float32)
        luminance = 0.299 * array[:, :, 0] + 0.587 * array[:, :, 1] + 0.114 * array[:, :, 2]
        centre = arguments.profile - x0
        half = max(1, arguments.profile_width // 2)
        left = max(0, centre - half)
        right = min(luminance.shape[1], centre + half)
        print("row profile at x=%d (the column of the crop is %d):" %
              (arguments.profile, centre))
        for row in range(luminance.shape[0]):
            values = luminance[row, left:right]
            print("   y=%4d  lum %6.2f  min %6.2f  max %6.2f" %
                  (row + y0, float(values.mean()), float(values.min()),
                   float(values.max())))
    return 0


if __name__ == "__main__":
    sys.exit(main())
