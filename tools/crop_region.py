# -*- coding: utf-8 -*-
"""Вырезает произвольный прямоугольник со скриншота и увеличивает его.

Использование: python crop_region.py src.png dst.png x y w h [scale]
"""
import sys
from PIL import Image

src = sys.argv[1]
dst = sys.argv[2]
x, y, w, h = (int(v) for v in sys.argv[3:7])
scale = float(sys.argv[7]) if len(sys.argv) > 7 else 3.0

im = Image.open(src).convert("RGB")
crop = im.crop((x, y, x + w, y + h))
crop = crop.resize((int(crop.width * scale), int(crop.height * scale)), Image.LANCZOS)
crop.save(dst)
print("%s [%d,%d %dx%d] -> %s  %dx%d" % (src, x, y, w, h, dst, crop.width, crop.height))
