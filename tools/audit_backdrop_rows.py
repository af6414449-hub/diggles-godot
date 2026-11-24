#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""The shape of the backdrop on the screen: the runs of colour in the rows of
a capture.

The backdrop of the campaign scene is a set of quads that hang on the camera.
The audit prints the runs of the same colour in the given rows, so that the
area the panorama covers on the screen can be read off the capture instead of
guessed from the code.

Usage:
  python tools/audit_backdrop_rows.py out/mine-2026-11-21/backdrop-before.png
  python tools/audit_backdrop_rows.py image.png --rows=150,250,400 --min-run=8
"""
from __future__ import annotations

import sys
from pathlib import Path

from PIL import Image


def runs_of_row(pixels, width: int, y: int, min_run: int) -> list[tuple[int, int, tuple[int, int, int]]]:
    runs: list[tuple[int, int, tuple[int, int, int]]] = []
    start = 0
    previous = pixels[0, y]
    for x in range(1, width):
        colour = pixels[x, y]
        if colour != previous:
            runs.append((start, x - 1, previous))
            start = x
            previous = colour
    runs.append((start, width - 1, previous))
    return [run for run in runs if run[1] - run[0] >= min_run]


def main(argv: list[str]) -> int:
    args = [a for a in argv[1:] if not a.startswith("--")]
    if not args:
        print(__doc__)
        return 1
    rows: list[int] = []
    min_run = 8
    for arg in argv[1:]:
        if arg.startswith("--rows="):
            rows = [int(value) for value in arg.split("=", 1)[1].split(",")]
        elif arg.startswith("--min-run="):
            min_run = int(arg.split("=", 1)[1])
    for path in args:
        if not Path(path).exists():
            print("!! no such file: %s" % path)
            continue
        image = Image.open(path).convert("RGB")
        width, height = image.size
        pixels = image.load()
        if not rows:
            rows = [int(height * value / 8) for value in range(8)]
        print("== %s  %dx%d" % (path, width, height))
        for y in rows:
            if y < 0 or y >= height:
                continue
            print("   row %4d: %s" % (y, runs_of_row(pixels, width, y, min_run)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
