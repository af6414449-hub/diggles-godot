#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Audit of the white patches of the backdrop of the campaign scene.

The owner of the chapter reported white rectangles in the window of the scene
(v31-native.png): in the lower corners of the frame and through the holes of
the ground plane inside the contour of the map. The audit finds the pixels of
the background that are white, groups them into regions and prints their
bounding boxes, so that a change of the backdrop can be checked by a number
instead of by the eye.

Usage:
  python tools/audit_backdrop_white.py out/campaign-shots/v31-native.png
  python tools/audit_backdrop_white.py before.png after.png
  python tools/audit_backdrop_white.py image.png --sample 0,0 640,300
"""
from __future__ import annotations

import sys
from collections import deque
from pathlib import Path

from PIL import Image

# A pixel counts as background white when it is bright and not coloured: the
# bright grey of the clear colour of the frame is (232, 232, 232), the white of
# an uncovered background is (255, 255, 255).
WHITE_LEVEL = 250
NEAR_WHITE_LEVEL = 244
MIN_CHANNEL_SPREAD = 6


def load(path: str) -> Image.Image:
    return Image.open(path).convert("RGB")


def is_white(pixel: tuple[int, int, int], level: int) -> bool:
    r, g, b = pixel
    if min(r, g, b) < level:
        return False
    spread = max(r, g, b) - min(r, g, b)
    return spread <= MIN_CHANNEL_SPREAD


def mask_of(image: Image.Image, level: int) -> list[list[bool]]:
    width, height = image.size
    pixels = image.load()
    return [
        [is_white(pixels[x, y], level) for x in range(width)]
        for y in range(height)
    ]


def regions(mask: list[list[bool]], min_size: int = 64) -> list[tuple[int, int, int, int, int]]:
    """The bounding boxes of the connected white areas, the biggest first."""
    height = len(mask)
    width = len(mask[0]) if height else 0
    seen = [[False] * width for _ in range(height)]
    found: list[tuple[int, int, int, int, int]] = []
    for y in range(height):
        for x in range(width):
            if not mask[y][x] or seen[y][x]:
                continue
            queue = deque([(x, y)])
            seen[y][x] = True
            x0 = x1 = x
            y0 = y1 = y
            count = 0
            while queue:
                cx, cy = queue.popleft()
                count += 1
                x0 = min(x0, cx)
                x1 = max(x1, cx)
                y0 = min(y0, cy)
                y1 = max(y1, cy)
                for nx, ny in ((cx - 1, cy), (cx + 1, cy), (cx, cy - 1), (cx, cy + 1)):
                    if 0 <= nx < width and 0 <= ny < height and mask[ny][nx] and not seen[ny][nx]:
                        seen[ny][nx] = True
                        queue.append((nx, ny))
            if count >= min_size:
                found.append((x0, y0, x1, y1, count))
    found.sort(key=lambda item: -item[4])
    return found


def report(path: str, level: int = WHITE_LEVEL, min_size: int = 64) -> dict:
    image = load(path)
    width, height = image.size
    mask = mask_of(image, level)
    total = sum(row.count(True) for row in mask)
    boxes = regions(mask, min_size)
    print("== %s" % path)
    print("   size=%dx%d white_level=%d" % (width, height, level))
    print("   white_pixels=%d (%.4f%% of the frame)" % (total, 100.0 * total / (width * height)))
    print("   regions=%d (bigger than %d px)" % (len(boxes), min_size))
    for box in boxes[:12]:
        x0, y0, x1, y1, count = box
        print("   box x=%d..%d y=%d..%d px=%d (%.2f%% of the frame)"
              % (x0, x1, y0, y1, count, 100.0 * count / (width * height)))
    return {"path": path, "total": total, "boxes": boxes, "size": (width, height)}


def sample(path: str, points: list[tuple[int, int]]) -> None:
    image = load(path)
    pixels = image.load()
    print("== samples of %s" % path)
    for x, y in points:
        if 0 <= x < image.size[0] and 0 <= y < image.size[1]:
            print("   (%4d,%4d) = %s" % (x, y, pixels[x, y]))
        else:
            print("   (%4d,%4d) is outside the frame" % (x, y))


def main(argv: list[str]) -> int:
    args = [a for a in argv[1:] if not a.startswith("--")]
    if not args:
        print(__doc__)
        return 1
    level = WHITE_LEVEL
    min_size = 64
    points: list[tuple[int, int]] = []
    for arg in argv[1:]:
        if arg.startswith("--level="):
            level = int(arg.split("=", 1)[1])
        elif arg.startswith("--min-size="):
            min_size = int(arg.split("=", 1)[1])
        elif arg.startswith("--sample="):
            for pair in arg.split("=", 1)[1].split(";"):
                x, y = pair.split(",")
                points.append((int(x), int(y)))
    results = []
    for path in args:
        if not Path(path).exists():
            print("!! no such file: %s" % path)
            continue
        results.append(report(path, level, min_size))
        if points:
            sample(path, points)
    if len(results) == 2:
        first, second = results
        delta = second["total"] - first["total"]
        share = 100.0 * delta / max(1, first["total"]) if first["total"] else 0.0
        print("== delta white_pixels = %+d (%+.2f%% of the first)" % (delta, share))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
