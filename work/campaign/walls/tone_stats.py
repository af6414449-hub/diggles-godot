#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The tone of the named regions of a capture.

The comparison of the original and of the port needs the same measure on both
pictures, so the tone of every region is printed with the same numbers: the
mean of every channel, the luminance, the difference of the red and the blue
channel (the warmth of the surface) and the spread inside the region.

Usage:
    python tone_stats.py FRAME.png NAME=x0,y0,x1,y1 [NAME=x0,y0,x1,y1 ...]
        [--channel lum]

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image


def stats(region: np.ndarray) -> dict:
    red = region[:, :, 0]
    green = region[:, :, 1]
    blue = region[:, :, 2]
    luminance = 0.299 * red + 0.587 * green + 0.114 * blue
    warmth = red - blue
    return {
        "pixels": int(region.shape[0] * region.shape[1]),
        "r": float(red.mean()),
        "g": float(green.mean()),
        "b": float(blue.mean()),
        "lum": float(luminance.mean()),
        "lum_std": float(luminance.std()),
        "lum_p10": float(np.percentile(luminance, 10)),
        "lum_p90": float(np.percentile(luminance, 90)),
        "rb": float(warmth.mean()),
        "rb_std": float(warmth.std()),
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("image")
    parser.add_argument("regions", nargs="+")
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.image):
        print("missing: %s" % arguments.image)
        return 1
    array = np.asarray(Image.open(arguments.image).convert("RGB")).astype(np.float32)
    print("%s  size=%dx%d" % (os.path.basename(arguments.image), array.shape[1], array.shape[0]))
    rows = {}
    for entry in arguments.regions:
        name, _, box = entry.partition("=")
        x0, y0, x1, y1 = (int(part) for part in box.split(","))
        row = stats(array[y0:y1, x0:x1])
        rows[name] = row
        print("   %-14s box=%-22s px=%-7d R=%6.2f G=%6.2f B=%6.2f  lum=%6.2f (sd %5.2f, p10 %6.2f, p90 %6.2f)  R-B=%+6.2f (sd %5.2f)" %
              (name, "%d,%d,%d,%d" % (x0, y0, x1, y1), row["pixels"], row["r"], row["g"], row["b"],
               row["lum"], row["lum_std"], row["lum_p10"], row["lum_p90"], row["rb"], row["rb_std"]))
    names = list(rows)
    for index, first in enumerate(names):
        for second in names[index + 1:]:
            a = rows[first]
            b = rows[second]
            print("   %-14s minus %-14s : dLum=%+6.2f  dR-B=%+6.2f  ratioLum=%.3f" %
                  (first, second, a["lum"] - b["lum"], a["rb"] - b["rb"],
                   a["lum"] / max(b["lum"], 1e-6)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
