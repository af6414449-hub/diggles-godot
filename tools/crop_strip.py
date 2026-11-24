# -*- coding: utf-8 -*-
"""Режет ленту иконок со скриншота и увеличивает её для осмотра."""
import sys
from PIL import Image

src = sys.argv[1]
dst = sys.argv[2]
top = int(sys.argv[3]) if len(sys.argv) > 3 else 740
scale = float(sys.argv[4]) if len(sys.argv) > 4 else 1.6

im = Image.open(src).convert("RGB")
box = (20, top, im.width - 20, im.height)
crop = im.crop(box)
crop = crop.resize((int(crop.width * scale), int(crop.height * scale)), Image.LANCZOS)
crop.save(dst)
print("%s -> %s  %dx%d" % (src, dst, crop.width, crop.height))
