#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Do two campaign shots come from the same camera?

The camera of the scene changed more than once (the session "Generation" rebuilt
the layout of the port), so shots of different times must not be compared
pixel by pixel. The mean profile of the rows and of the columns of a frame
follows the camera; the best shift and the correlation of the profiles say
whether two frames were taken from the same point of view.

Read-only: it only reads PNG files.
"""
import argparse
import itertools
import os
import sys

import numpy as np
from PIL import Image


def profile(path: str) -> tuple:
    array = np.asarray(Image.open(path).convert("L")).astype(np.float32)
    return array.mean(axis=1), array.mean(axis=0)


def best_shift(first: np.ndarray, second: np.ndarray, limit: int = 80) -> tuple:
    """The shift of the second profile against the first and its correlation."""
    best = (0, 0.0)
    for shift in range(-limit, limit + 1):
        if shift >= 0:
            left = first[shift:]
            right = second[:len(second) - shift]
        else:
            left = first[:len(first) + shift]
            right = second[-shift:]
        if len(left) < 16:
            continue
        a = left - left.mean()
        b = right - right.mean()
        denominator = float(np.sqrt((a * a).sum() * (b * b).sum()))
        if denominator < 1e-6:
            continue
        correlation = float((a * b).sum() / denominator)
        if correlation > best[1]:
            best = (shift, correlation)
    return best


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("images", nargs="+")
    arguments = parser.parse_args()
    rows = {}
    for path in arguments.images:
        if not os.path.isfile(path):
            print("missing: %s" % path)
            continue
        rows[os.path.basename(path)] = profile(path)
    for first, second in itertools.combinations(rows, 2):
        row_shift, row_correlation = best_shift(rows[first][0], rows[second][0])
        column_shift, column_correlation = best_shift(rows[first][1], rows[second][1])
        verdict = "same camera" if (row_shift == 0 and column_shift == 0
                                    and row_correlation > 0.9 and column_correlation > 0.9) \
            else "different camera"
        print("%-20s vs %-20s  rows: shift=%+d corr=%.3f   columns: shift=%+d corr=%.3f   -> %s" %
              (first, second, row_shift, row_correlation, column_shift, column_correlation, verdict))
    return 0


if __name__ == "__main__":
    sys.exit(main())
