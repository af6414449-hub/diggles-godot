#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Contrast between the day surface and the underground.

The battle scene (the multiplayer map) uses the native light path with the
stored light byte of the cell taken as is. The campaign chapter replaces the
byte zero with the mean of the chapter, so the two scenes have to differ. This
script measures the same regions on both sets of frames, so that the chapter can
be compared with the scene the owner accepted.
"""
import os
import sys

from PIL import Image

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
SHOTS = os.path.join(ROOT, "out")


def mean_rgb(image, box):
    width, height = image.size
    x0, y0, x1, y1 = box
    x0 = max(0, min(width - 1, int(x0 * width)))
    x1 = max(x0 + 1, min(width, int(x1 * width)))
    y0 = max(0, min(height - 1, int(y0 * height)))
    y1 = max(y0 + 1, min(height, int(y1 * height)))
    pixels = list(image.crop((x0, y0, x1, y1)).getdata())
    count = len(pixels)
    return (sum(p[0] for p in pixels) // count,
            sum(p[1] for p in pixels) // count,
            sum(p[2] for p in pixels) // count)


def report(path, regions):
    image = Image.open(path).convert("RGB")
    print("== %s" % os.path.basename(path))
    values = {}
    for name, box in regions.items():
        rgb = mean_rgb(image, box)
        values[name] = rgb
        print("   %-24s rgb=%s" % (name, rgb))
    if "surface" in values and "underground" in values:
        surface = values["surface"]
        underground = values["underground"]
        ratio = (surface[0] + surface[1] + surface[2]) / max(1, underground[0] + underground[1] + underground[2])
        print("   contrast surface/underground = %.2f" % ratio)
    return values


def main():
    battle = os.path.join(SHOTS, "mine-2026-11-21", "battle-ref")
    regions_battle = {
        # the plateau of the cave map on the right, the cave floor on the left
        "surface": (0.72, 0.62, 0.95, 0.78),
        "underground": (0.30, 0.62, 0.55, 0.78),
    }
    for name in ("multi_start_010_native_0.png", "multi_start_010_native_1.png",
                 "multi_start_010_native_2.png"):
        path = os.path.join(battle, name)
        if os.path.exists(path):
            report(path, regions_battle)

    campaign = os.path.join(SHOTS, "campaign-shots")
    regions_campaign = {
        "surface": (0.16, 0.48, 0.30, 0.55),
        "underground": (0.25, 0.70, 0.50, 0.78),
    }
    for name in ("v78-native.png", "v81-wide.png"):
        path = os.path.join(campaign, name)
        if os.path.exists(path):
            report(path, regions_campaign)
    return 0


if __name__ == "__main__":
    sys.exit(main())
