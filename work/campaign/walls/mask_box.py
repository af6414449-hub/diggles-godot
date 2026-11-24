#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The mask of the walls of the module inside one region of a capture.

The mask is the picture that wall_screen.py saves with --save-mask: the pixels
of the capture that the faces of the module cover.  This script prints how much
of a region the mask covers, so that a dark line of the capture can be told
apart from a face of the module.

Usage:
    python mask_box.py MASK.png --box x0,y0,x1,y1 [--image FRAME.png]

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("mask")
    parser.add_argument("--box", required=True)
    parser.add_argument("--image", default="")
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.mask):
        print("missing: %s" % arguments.mask)
        return 1
    mask = np.asarray(Image.open(arguments.mask).convert("L")).astype(np.float32)
    x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
    region = mask[y0:y1, x0:x1]
    print("%s box=%d,%d..%d,%d  covered %d of %d pixels (%.1f %%)" %
          (os.path.basename(arguments.mask), x0, y0, x1, y1,
           int((region > 127).sum()), region.size, 100.0 * (region > 127).mean()))
    if arguments.image:
        picture = np.asarray(Image.open(arguments.image).convert("L")).astype(np.float32)
        tone = picture[y0:y1, x0:x1]
        print("   tone of the covered pixels:  mean %.2f  min %.2f" %
              (float(tone[region > 127].mean()), float(tone[region > 127].min())))
        print("   tone of the open pixels:     mean %.2f  min %.2f" %
              (float(tone[region <= 127].mean()), float(tone[region <= 127].min())))
    print()
    for row in range(region.shape[0]):
        print("%4d %s" % (y0 + row,
                          "".join("#" if value > 127 else "." for value in region[row])))
    return 0


if __name__ == "__main__":
    sys.exit(main())
