#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Measure the light of the port frames and of the original frames.

The port frame and the original frames are compared by region: day surface,
underground rock, and the area around a light source.
"""
import os
import sys

from PIL import Image

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
SHOTS = os.path.join(ROOT, "out")


def sample(path, boxes):
    image = Image.open(path).convert("RGB")
    width, height = image.size
    print("%-44s %dx%d" % (os.path.basename(path), width, height))
    for name, (x0, y0, x1, y1) in boxes.items():
        x0 = max(0, min(width - 1, int(x0 * width)))
        x1 = max(x0 + 1, min(width, int(x1 * width)))
        y0 = max(0, min(height - 1, int(y0 * height)))
        y1 = max(y0 + 1, min(height, int(y1 * height)))
        pixels = list(image.crop((x0, y0, x1, y1)).getdata())
        count = len(pixels)
        r = sum(p[0] for p in pixels) // count
        g = sum(p[1] for p in pixels) // count
        b = sum(p[2] for p in pixels) // count
        print("    %-26s (%4d,%4d)-(%4d,%4d) rgb=(%3d,%3d,%3d) luma=%5.1f" % (
            name, x0, y0, x1, y1, r, g, b, 0.299 * r + 0.587 * g + 0.114 * b))


def main():
    campaign = os.path.join(SHOTS, "campaign-shots", "v78-native.png")
    if os.path.exists(campaign):
        sample(campaign, {
            "grass plateau (day)": (0.16, 0.48, 0.30, 0.55),
            "underground rock": (0.25, 0.70, 0.50, 0.78),
            "tunnel floor (mid)": (0.10, 0.78, 0.25, 0.86),
            "rock rim right": (0.72, 0.10, 0.86, 0.30),
            "backdrop sky": (0.60, 0.02, 0.75, 0.08),
        })
    wide = os.path.join(SHOTS, "campaign-shots", "v81-wide.png")
    if os.path.exists(wide):
        sample(wide, {
            "free ground (map)": (0.45, 0.60, 0.62, 0.70),
            "chapter cells": (0.38, 0.38, 0.44, 0.42),
            "funnel rock": (0.30, 0.72, 0.36, 0.78),
        })
    original = os.path.join(SHOTS, "original-shots")
    for name in sorted(os.listdir(original)) if os.path.isdir(original) else []:
        if not name.lower().endswith(".png"):
            continue
        path = os.path.join(original, name)
        if "contact" in name.lower():
            continue
        sample(path, {
            "centre": (0.35, 0.35, 0.65, 0.65),
            "upper": (0.30, 0.10, 0.70, 0.25),
            "lower": (0.30, 0.75, 0.70, 0.90),
        })
    return 0


if __name__ == "__main__":
    sys.exit(main())
