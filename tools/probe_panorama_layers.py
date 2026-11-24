import os
from PIL import Image

SRC = r"godot\textures\backdrop"

for index in range(7):
    path = os.path.join(SRC, "Panorama_layer_%d.tga" % index)
    img = Image.open(path).convert("RGBA")
    w, h = img.size
    print("layer %d: %dx%d" % (index, w, h))
    for frac in (0.0, 0.15, 0.3, 0.45, 0.6, 0.75, 0.9, 1.0):
        y = min(h - 1, int(frac * h))
        px = [img.getpixel((x, y)) for x in (0, w // 4, w // 2, 3 * w // 4, w - 1)]
        alpha = [p[3] for p in px]
        print("   row %4d (%.2f) rgba: %s" % (y, frac, px))
    # the row where the alpha starts to grow
    first = None
    for y in range(h):
        a = img.getpixel((w // 2, y))[3]
        if a > 8:
            first = y
            break
    print("   first row with alpha>8: %s of %d (content from below %.3f)" % (
        first, h, 1.0 - (first or 0) / h))
