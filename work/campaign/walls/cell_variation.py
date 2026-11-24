#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""How much does the free ground jump from one cell to the next?

The colour variation of the ground of the map is a tint of every cell
(Campaign.tcl:6 generate_color_variation 0 0 512 640 0). The original puts it
into the vertices of the polygon of a run of cells (FUN_004cca20), and all four
vertices of that polygon carry the same value, so the tone is flat inside a
run and the structure of the ground is a step per run, not per cell. The port
can sample the variation map per cell (nearest), and then every cell of the
ground jumps.

This script measures the tone of every cell of a region of a capture and
compares the step between the cells with the noise inside a cell.

Usage:
    python cell_variation.py FRAME.png --box x0,y0,x1,y1 [--cell 64] [--phase 0]
      --box    the region of the frame, in pixels; it must lie on the free
               ground and be a multiple of the cell size in both directions
      --cell   the size of a cell on the screen, in pixels (64 for the native
               view of the port, the map is drawn one cell per 64 pixels)
      --phase  the offset of the cell grid inside the box; 0 means "search for
               the phase with the strongest cell structure"

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image


def block_means(region: np.ndarray, cell: int, phase: int) -> np.ndarray:
    """The mean tone of every cell of the region, row by row."""
    height, width = region.shape
    rows = []
    for row in range(phase, height - cell + 1, cell):
        line = []
        for column in range(phase, width - cell + 1, cell):
            line.append(float(region[row:row + cell, column:column + cell].mean()))
        rows.append(line)
    return np.array(rows)


def inside_noise(region: np.ndarray, cell: int, phase: int) -> float:
    """The mean |difference| between neighbouring pixels inside a cell."""
    height, width = region.shape
    values = []
    for row in range(phase, height - cell + 1, cell):
        for column in range(phase, width - cell + 1, cell):
            block = region[row:row + cell, column:column + cell]
            values.append(float(np.abs(np.diff(block, axis=1)).mean()))
    return float(np.mean(values)) if values else 0.0


def measure(path: str, box: tuple, cell: int, phase: int) -> dict:
    array = np.asarray(Image.open(path).convert("L")).astype(np.float32)
    x0, y0, x1, y1 = box
    region = array[y0:y1, x0:x1]
    best = None
    phases = range(cell) if phase <= 0 else [phase]
    for candidate in phases:
        means = block_means(region, cell, candidate)
        if means.size < 2:
            continue
        steps = np.abs(np.diff(means, axis=1)).mean()
        if best is None or steps > best[0]:
            best = (steps, candidate, means)
    if best is None:
        return {"file": os.path.basename(path), "region": list(box), "cells": 0}
    steps_value, best_phase, means = best
    horizontal = np.abs(np.diff(means, axis=1)).ravel()
    vertical = np.abs(np.diff(means, axis=0)).ravel()
    noise = inside_noise(region, cell, best_phase)
    return {
        "file": os.path.basename(path),
        "region": list(box),
        "cell": cell,
        "phase": best_phase,
        "cells": int(means.size),
        "cell_mean": float(means.mean()),
        "cell_spread": float(means.max() - means.min()),
        "cell_std": float(means.std()),
        "inside_noise": noise,
        "step_median": float(np.median(horizontal)) if horizontal.size else 0.0,
        "step_90": float(np.percentile(horizontal, 90)) if horizontal.size else 0.0,
        "step_vertical_median": float(np.median(vertical)) if vertical.size else 0.0,
        "ratio_median": float(np.median(horizontal)) / max(noise, 1e-6) if horizontal.size else 0.0,
        "ratio_90": float(np.percentile(horizontal, 90)) / max(noise, 1e-6) if horizontal.size else 0.0,
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("images", nargs="+")
    parser.add_argument("--box", default="32,576,160,704")
    parser.add_argument("--cell", type=int, default=64)
    parser.add_argument("--phase", type=int, default=0)
    arguments = parser.parse_args()
    box = tuple(int(part) for part in arguments.box.split(","))
    for path in arguments.images:
        if not os.path.isfile(path):
            print("missing: %s" % path)
            continue
        row = measure(path, box, arguments.cell, arguments.phase)
        if not row.get("cells"):
            print("%-20s region=%s: too small" % (row["file"], row["region"]))
            continue
        print("%-20s region=%s cell=%d phase=%d cells=%d" %
              (row["file"], row["region"], row["cell"], row["phase"], row["cells"]))
        print("   tone of a cell: mean=%.2f  spread=%.2f  std=%.2f" %
              (row["cell_mean"], row["cell_spread"], row["cell_std"]))
        print("   step between neighbouring cells: median=%.2f  p90=%.2f  (vertical median=%.2f)" %
              (row["step_median"], row["step_90"], row["step_vertical_median"]))
        print("   noise inside a cell=%.2f  ->  step/noise: median=%.2f  p90=%.2f" %
              (row["inside_noise"], row["ratio_median"], row["ratio_90"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
