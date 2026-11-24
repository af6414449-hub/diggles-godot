#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Contrast of the cell grid (per-cell tiles) against the horizontal bands of the
continuous ground field, measured in screen space.

Both artefacts are periodic, so the same metric works for both:
  - take a flat region of the map ground,
  - build the mean luminance profile along X and along Y,
  - find the dominant period of the profile (FFT),
  - compare the mean |difference| on the boundaries of that period with the mean
    |difference| between them.

A ratio near 1.0 means the structure is invisible (it is buried in the noise of
the texture), a ratio above 1.5 means the structure stands out.

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image


def detrend(profile: np.ndarray, window: int = 33) -> np.ndarray:
    """Remove the slow drift of the profile, keep the periodic structure."""
    kernel = np.ones(window, dtype=np.float32) / float(window)
    smooth = np.convolve(profile, kernel, mode="same")
    return profile - smooth


def boundary_ratio(profile: np.ndarray, period: float) -> dict:
    """Mean |difference| on the boundaries of the period against the rest."""
    if period < 2.0 or len(profile) < 8:
        return {"period": period, "on": 0.0, "off": 0.0, "ratio": 0.0}
    step = int(round(period))
    difference = np.abs(np.diff(profile))
    index = np.arange(len(difference))
    on = (index % step) == 0
    if not on.any() or (~on).sum() == 0:
        return {"period": period, "on": 0.0, "off": 0.0, "ratio": 0.0}
    on_mean = float(difference[on].mean())
    off_mean = float(difference[~on].mean())
    return {"period": float(period), "on": on_mean, "off": off_mean,
            "ratio": on_mean / max(off_mean, 1e-6)}


def scan_periods(profile: np.ndarray, low: int = 8, high: int = 200, count: int = 3) -> list:
    """The periods with the strongest boundary contrast of a profile."""
    found = []
    for step in range(low, high + 1):
        if len(profile) < step * 3:
            break
        row = boundary_ratio(profile, float(step))
        found.append((row["ratio"], step, row))
    found.sort(key=lambda item: item[0], reverse=True)
    return [row for _, _, row in found[:count]]


def analyse(path: str, box: tuple) -> dict:
    image = Image.open(path).convert("L")
    array = np.asarray(image).astype(np.float32)
    x0, y0, x1, y1 = box
    region = array[y0:y1, x0:x1]
    columns = region.mean(axis=0)
    rows = region.mean(axis=1)
    return {
        "file": os.path.basename(path),
        "region": list(box),
        "mean": round(float(region.mean()), 2),
        "x": scan_periods(columns),
        "y": scan_periods(rows),
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("images", nargs="+")
    parser.add_argument("--box", default="40,390,420,700",
                        help="x0,y0,x1,y1 of the flat region of the map ground")
    arguments = parser.parse_args()
    box = tuple(int(part) for part in arguments.box.split(","))
    for path in arguments.images:
        if not os.path.isfile(path):
            print("missing: %s" % path)
            continue
        result = analyse(path, box)
        print("%s  region=%s mean=%.2f" % (result["file"], result["region"], result["mean"]))
        for axis in ("x", "y"):
            for row in result[axis]:
                print("   %s: period=%3d px  boundary=%.3f  between=%.3f  ratio=%.2f"
                      % (axis, row["period"], row["on"], row["off"], row["ratio"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
