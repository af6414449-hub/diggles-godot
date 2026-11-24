#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The pitch of the cell grid on a surface in a capture.

The surface of the chapter is drawn cell by cell, so the seams of the cells
form a grid of thin dark lines.  The pitch of that grid is the size of a cell
on the screen.  The lines are thin, so the background of the picture is taken
with a median filter and the lines are what stays in the difference.

Usage:
    python grid_pitch.py FRAME.png [--box x0,y0,x1,y1] [--min-lag 6] [--max-lag 80]

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image
from scipy import ndimage


def line_profile(tone_map: np.ndarray, window: int, threshold: float) -> np.ndarray:
    """The sum of the dark lines over every column and over every row."""
    background = ndimage.median_filter(tone_map, size=window, mode="nearest")
    marks = background - tone_map
    mask = marks > threshold
    return mask.sum(axis=0).astype(np.float64), mask.sum(axis=1).astype(np.float64)


def pitch(profile: np.ndarray, min_lag: int, max_lag: int) -> list:
    """The peaks of the autocorrelation of the profile."""
    values = profile - profile.mean()
    if values.size < 4:
        return []
    spectrum = np.fft.rfft(values, n=2 * values.size)
    correlation = np.fft.irfft(spectrum * np.conj(spectrum), n=2 * values.size)[:values.size]
    if correlation[0] > 0:
        correlation = correlation / correlation[0]
    result = []
    for lag in range(max(2, min_lag), min(max_lag, correlation.size - 1)):
        if correlation[lag] > correlation[lag - 1] and correlation[lag] >= correlation[lag + 1]:
            result.append((lag, float(correlation[lag])))
    result.sort(key=lambda item: -item[1])
    return result[:10]


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("image")
    parser.add_argument("--box", default="")
    parser.add_argument("--min-lag", type=int, default=6)
    parser.add_argument("--max-lag", type=int, default=80)
    parser.add_argument("--window", type=int, default=9)
    parser.add_argument("--threshold", type=float, default=2.0)
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.image):
        print("missing: %s" % arguments.image)
        return 1
    array = np.asarray(Image.open(arguments.image).convert("L")).astype(np.float32)
    if arguments.box:
        x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
        array = array[y0:y1, x0:x1]
    columns, rows = line_profile(array, arguments.window, arguments.threshold)
    print("%s region=%s size=%dx%d" % (os.path.basename(arguments.image), arguments.box,
                                      array.shape[1], array.shape[0]))
    print("   pitch of the columns: %s" % (pitch(columns, arguments.min_lag, arguments.max_lag) or "no peak"))
    print("   pitch of the rows:    %s" % (pitch(rows, arguments.min_lag, arguments.max_lag) or "no peak"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
