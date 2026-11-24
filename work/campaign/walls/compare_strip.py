#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Two pictures side by side, for the report and for the owner.

The panels are scaled to the same height and put on one canvas with a gap,
so that the tone of the original and the tone of the port can be compared
without switching between the files.

Usage:
    python compare_strip.py LEFT.png RIGHT.png --out OUT.png [--height 220]
        [--left-label "original"] [--right-label "port"]

Read-only: it only reads PNG files and writes the new picture.
"""
import argparse
import os
import sys

from PIL import Image, ImageDraw


def panel(path: str, height: int, label: str) -> Image.Image:
    image = Image.open(path).convert("RGB")
    width = max(1, int(round(image.size[0] * float(height) / float(image.size[1]))))
    image = image.resize((width, height), Image.LANCZOS)
    if label:
        canvas = Image.new("RGB", (width, height + 22), (16, 16, 16))
        canvas.paste(image, (0, 22))
        draw = ImageDraw.Draw(canvas)
        draw.text((6, 5), label, fill=(235, 235, 235))
        return canvas
    return image


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("left")
    parser.add_argument("right")
    parser.add_argument("--out", required=True)
    parser.add_argument("--height", type=int, default=220)
    parser.add_argument("--gap", type=int, default=10)
    parser.add_argument("--left-label", default="")
    parser.add_argument("--right-label", default="")
    arguments = parser.parse_args()
    for path in (arguments.left, arguments.right):
        if not os.path.isfile(path):
            print("missing: %s" % path)
            return 1
    first = panel(arguments.left, arguments.height, arguments.left_label)
    second = panel(arguments.right, arguments.height, arguments.right_label)
    canvas = Image.new("RGB", (first.size[0] + arguments.gap + second.size[0],
                              max(first.size[1], second.size[1])), (16, 16, 16))
    canvas.paste(first, (0, 0))
    canvas.paste(second, (first.size[0] + arguments.gap, 0))
    canvas.save(arguments.out)
    print("saved %s (%dx%d)" % (arguments.out, canvas.size[0], canvas.size[1]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
