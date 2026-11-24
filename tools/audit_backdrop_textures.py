#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""The textures of the panorama of the original: the alpha profile and the
colours of the ground line of every layer.

The backdrop of the port draws the layers of the panorama of the original as
strips of quads. To know what the ground of the world around the dig site
looks like (the part of the frame under the horizon line), the alpha profile
and the colour of the bottom of every layer are measured here.

Usage:
  python tools/audit_backdrop_textures.py
  python tools/audit_backdrop_textures.py godot/textures/backdrop/Panorama_layer_5.tga
"""
from __future__ import annotations

import sys
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
DEFAULT_LAYERS = [
    ROOT / "godot" / "textures" / "backdrop" / f"Panorama_layer_{i}.tga" for i in range(7)
]


def profile(path: Path) -> None:
    image = Image.open(path).convert("RGBA")
    width, height = image.size
    pixels = image.load()
    print("== %s  %dx%d" % (path.name, width, height))
    print("   row   alpha(min..max, mean)   colour of the row (mean over the opaque part)")
    step = max(1, height // 16)
    for y in range(0, height, step):
        alphas = [pixels[x, y][3] for x in range(width)]
        opaque = [pixels[x, y] for x in range(width) if pixels[x, y][3] > 128]
        if opaque:
            mean = tuple(sum(p[i] for p in opaque) // len(opaque) for i in range(3))
        else:
            mean = None
        print("   %4d   %3d..%3d  mean %5.1f   %s"
              % (y, min(alphas), max(alphas), sum(alphas) / len(alphas), mean))
    bottom = [pixels[x, height - 1] for x in range(width)]
    opaque_bottom = [p for p in bottom if p[3] > 128]
    if opaque_bottom:
        mean = tuple(sum(p[i] for p in opaque_bottom) // len(opaque_bottom) for i in range(3))
        print("   bottom row: opaque %d/%d, mean colour %s"
              % (len(opaque_bottom), width, mean))
    else:
        print("   bottom row: fully transparent")


def main(argv: list[str]) -> int:
    paths = [Path(a) for a in argv[1:]] or DEFAULT_LAYERS
    for path in paths:
        if not path.exists():
            print("!! no such file: %s" % path)
            continue
        profile(path)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
