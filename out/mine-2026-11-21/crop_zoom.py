#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Crop and magnify a region of a frame (used to measure the foreshortening)."""
import sys
from pathlib import Path

from PIL import Image

src = Path(sys.argv[1])
dst = Path(sys.argv[2])
x0, y0, x1, y1 = (int(v) for v in sys.argv[3:7])
scale = float(sys.argv[7]) if len(sys.argv) > 7 else 3.0

image = Image.open(src).convert("RGB")
crop = image.crop((x0, y0, x1, y1))
crop = crop.resize((int(crop.width * scale), int(crop.height * scale)), Image.NEAREST)
dst.parent.mkdir(parents=True, exist_ok=True)
crop.save(dst)
print("%s -> %s  region=%s  scale=%s  size=%s" % (src.name, dst, (x0, y0, x1, y1), scale, crop.size))
