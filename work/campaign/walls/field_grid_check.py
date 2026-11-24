#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Is there still a grid of 64 px in the ground field?

The field of the port is built by laying the native tiles over the canvas at
free positions, so no place of the canvas carries a border of a tile. The
signature of the old slot grid is a period of 64 px in the mean profile of the
rows or of the columns. This script looks for a period and measures the
contrast of the boundaries of that period against the rest of the profile - the
same measure as the seam test of the tiles (work/campaign/walls/field_vs_tiles.py).

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image

TILE = 64
FAMILIES = ("A", "B", "C")


def boundary_ratio(profile: np.ndarray, period: int) -> dict:
    difference = np.abs(np.diff(profile))
    index = np.arange(len(difference))
    on = (index % period) == 0
    if not on.any() or (~on).sum() == 0:
        return {"period": period, "on": 0.0, "off": 0.0, "ratio": 0.0}
    on_mean = float(difference[on].mean())
    off_mean = float(difference[~on].mean())
    return {"period": period, "on": on_mean, "off": off_mean,
            "ratio": on_mean / max(off_mean, 1e-6)}


def strongest(profile: np.ndarray, low: int = 8, high: int = 200, count: int = 3) -> list:
    found = []
    for period in range(low, high + 1):
        if len(profile) < period * 3:
            break
        row = boundary_ratio(profile, period)
        found.append((row["ratio"], row))
    found.sort(key=lambda item: item[0], reverse=True)
    return [row for _, row in found[:count]]


def harmonic_amplitude(profile: np.ndarray, period: int) -> float:
    """The amplitude of the component of the profile with the period, in tone."""
    n = len(profile)
    index = np.arange(n)
    wave = np.exp(2j * np.pi * index / float(period))
    return float(2.0 * np.abs((profile * wave).sum()) / n)


def lag_correlation(profile: np.ndarray, lag: int) -> float:
    """Correlation of a profile with its own copy, shifted by the lag."""
    if lag <= 0 or len(profile) <= lag + 8:
        return 0.0
    first = profile[:-lag]
    second = profile[lag:]
    first = first - first.mean()
    second = second - second.mean()
    denominator = float(np.sqrt((first * first).sum() * (second * second).sum()))
    if denominator < 1e-6:
        return 0.0
    return float((first * second).sum() / denominator)


def grid_lag_test(profile: np.ndarray, period: int = TILE) -> dict:
    """Is the period of the tile a special one for the profile?

    A grid of 64 px makes the correlation of the profile with its own copy at
    the lag 64 stand out against the lags around it. A field without a grid
    has no such peak.
    """
    lags = [period - 16, period - 8, period, period + 8, period + 16]
    values = {lag: lag_correlation(profile, lag) for lag in lags}
    neighbours = max(values[period - 16], values[period - 8], values[period + 8], values[period + 16])
    return {"values": values, "peak": values[period] > neighbours,
            "margin": values[period] - neighbours}


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--fields", required=True)
    parser.add_argument("--json", default="")
    arguments = parser.parse_args()
    for family in FAMILIES:
        path = os.path.join(arguments.fields, "ground_field_%s.png" % family)
        if not os.path.isfile(path):
            print("missing: %s" % path)
            continue
        array = np.asarray(Image.open(path).convert("L")).astype(np.float32)
        rows = array.mean(axis=1)
        columns = array.mean(axis=0)
        print("ground_field_%s.png  %dx%d  mean=%.2f" %
              (family, array.shape[1], array.shape[0], float(array.mean())))
        for axis, profile in (("rows", rows), ("columns", columns)):
            grid = boundary_ratio(profile, TILE)
            lag = grid_lag_test(profile)
            print("   %-7s period 64: boundary=%.3f between=%.3f ratio=%.2f  amplitude=%.3f tone" %
                  (axis, grid["on"], grid["off"], grid["ratio"], harmonic_amplitude(profile, TILE)))
            print("           lag correlation: %s  peak_at_64=%s" %
                  (", ".join("%d=%.3f" % (lag_value, value)
                            for lag_value, value in lag["values"].items()), lag["peak"]))
            for row in strongest(profile):
                print("           strongest: period=%3d ratio=%.2f (boundary=%.3f between=%.3f)" %
                      (row["period"], row["ratio"], row["on"], row["off"]))
    if arguments.json and os.path.isfile(arguments.json):
        print()
        print("report of the builder: %s" % arguments.json)
        with open(arguments.json, "r", encoding="utf-8") as handle:
            print(handle.read()[:1200])
    return 0


if __name__ == "__main__":
    sys.exit(main())
