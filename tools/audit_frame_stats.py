#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Frame statistics for the acceptance audit of a rendered frame.

Prints, for one or more frames:
    - the exact black share (a hole or an unlit surface),
    - the near-black share (sum of the channels below 30),
    - the share of the background colour of the scene (232,232,232),
    - the share of the pure white (>= 250 in every channel).

Usage:
    python tools/audit_frame_stats.py out/campaign-shots/v54-native.png out/campaign-shots/v57-native.png
"""
from __future__ import annotations

import argparse
import sys
from pathlib import Path

from PIL import Image

BACKGROUND = (232, 232, 232)


def measure(path: Path, step: int) -> dict:
    image = Image.open(path).convert("RGB")
    width, height = image.size
    pixels = image.load()
    total = 0
    black = 0
    near_black = 0
    background = 0
    white = 0
    for y in range(0, height, step):
        for x in range(0, width, step):
            colour = pixels[x, y]
            total += 1
            if colour == (0, 0, 0):
                black += 1
            if sum(colour) < 30:
                near_black += 1
            if all(abs(colour[i] - BACKGROUND[i]) <= 3 for i in range(3)):
                background += 1
            if min(colour) >= 250:
                white += 1
    return {
        "size": (width, height),
        "sampled": total,
        "black": black,
        "near_black": near_black,
        "background": background,
        "white": white,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("frames", nargs="+")
    parser.add_argument("--step", type=int, default=2, help="sampling step in pixels")
    args = parser.parse_args()

    print("%-38s %-11s %8s %9s %10s %8s %8s"
          % ("frame", "size", "sampled", "black", "sum<30", "bg(232)", "white"))
    for name in args.frames:
        path = Path(name)
        if not path.is_file():
            print("%-38s  нет файла" % name)
            continue
        data = measure(path, max(1, args.step))
        total = data["sampled"]
        print("%-38s %-11s %8d %6d %4.2f%% %7d %4.2f%% %5d %4.2f%% %5d %4.2f%%"
              % (path.name, "%dx%d" % data["size"], total,
                 data["black"], 100.0 * data["black"] / total,
                 data["near_black"], 100.0 * data["near_black"] / total,
                 data["background"], 100.0 * data["background"] / total,
                 data["white"], 100.0 * data["white"] / total))
    return 0


if __name__ == "__main__":
    sys.exit(main())
