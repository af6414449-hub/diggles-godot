#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The pitch of the structure on the free ground of a capture.

The tint of every cell of the map (the variation map, 512x640 texels) is
sampled per cell, so the ground of the map carries a structure with the pitch
of one cell. This script finds that pitch by the autocorrelation of a region
of a frame: the lags with the strongest correlation are the pitch of the
structure.

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image


def smooth(profile: np.ndarray, window: int = 9) -> np.ndarray:
    """A moving average: the fine noise of the texture goes away, the pitch stays."""
    kernel = np.ones(window, dtype=np.float32) / float(window)
    return np.convolve(profile, kernel, mode="same")


def profile_autocorrelation(profile: np.ndarray, low: int = 12, high: int = 200) -> list:
    """The correlation of a profile with its own copy at every lag."""
    centred = profile - profile.mean()
    result = []
    for lag in range(low, min(high, len(profile) - 2) + 1):
        first = centred[:-lag]
        second = centred[lag:]
        denominator = float(np.sqrt((first * first).sum() * (second * second).sum()))
        if denominator < 1e-6:
            continue
        result.append((lag, float((first * second).sum() / denominator)))
    return result


def local_peaks(values: list) -> list:
    """The local maxima of the correlation, the strongest first."""
    peaks = []
    for index in range(1, len(values) - 1):
        lag, value = values[index]
        if value > values[index - 1][1] and value >= values[index + 1][1]:
            peaks.append((value, lag))
    peaks.sort(reverse=True)
    return [(lag, value) for value, lag in peaks]


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("image")
    parser.add_argument("--box", required=True, help="x0,y0,x1,y1 of the region")
    parser.add_argument("--window", type=int, default=9)
    arguments = parser.parse_args()
    x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
    array = np.asarray(Image.open(arguments.image).convert("L")).astype(np.float32)
    region = array[y0:y1, x0:x1]
    columns = smooth(region.mean(axis=0), arguments.window)
    rows = smooth(region.mean(axis=1), arguments.window)
    for axis, profile in (("columns", columns), ("rows", rows)):
        values = profile_autocorrelation(profile)
        peaks = local_peaks(values)
        print("%-8s peaks: %s" %
              (axis, ", ".join("%d px (%.2f)" % (lag, value) for lag, value in peaks[:6])))
    print("region %s of %s" % (arguments.box, os.path.basename(arguments.image)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
