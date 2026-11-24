#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Horizon of the campaign shots: the last row that is still background.

NOT RELIABLE: the background of the scene is a dark yellow-green gradient, and
the threshold of this script misses it on most shots (it reports -1). Use
cam_match.py instead - it compares the profiles of two frames and says whether
they were taken from the same camera.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image


def horizon(path: str) -> dict:
    array = np.asarray(Image.open(path).convert("RGB")).astype(np.int16)
    height = array.shape[0]
    red = array[:, :, 0]
    green = array[:, :, 1]
    blue = array[:, :, 2]
    # The background: bright yellow-green. The rock and the ground are darker
    # and more neutral, the grass is green but darker.
    background = (red > 150) & (green > 150) & (blue < 90)
    share = background.mean(axis=1)
    rows = np.nonzero(share > 0.5)[0]
    last = int(rows.max()) if len(rows) else -1
    # The height of the background in the middle of the frame.
    middle = background[:, int(array.shape[1] * 0.45):int(array.shape[1] * 0.55)].mean(axis=1)
    middle_rows = np.nonzero(middle > 0.5)[0]
    middle_last = int(middle_rows.max()) if len(middle_rows) else -1
    return {
        "file": os.path.basename(path),
        "size": [int(array.shape[1]), int(array.shape[0])],
        "horizon_row": last,
        "horizon_fraction": round(last / float(height), 4),
        "horizon_middle": middle_last,
        "mean": round(float(array.mean()), 2),
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("images", nargs="+")
    arguments = parser.parse_args()
    for path in arguments.images:
        if not os.path.isfile(path):
            print("missing: %s" % path)
            continue
        row = horizon(path)
        print("%-22s size=%s  horizon_row=%d (%.4f)  middle=%d  mean=%.2f" %
              (row["file"], row["size"], row["horizon_row"], row["horizon_fraction"],
               row["horizon_middle"], row["mean"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
