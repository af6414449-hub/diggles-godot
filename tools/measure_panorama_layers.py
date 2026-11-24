import os
from PIL import Image

SRC = r"godot\textures\backdrop"
THRESHOLD = 32

print("layer  size   first_alpha>=32  content_fraction")
for index in range(7):
    path = os.path.join(SRC, "Panorama_layer_%d.tga" % index)
    img = Image.open(path).convert("RGBA")
    w, h = img.size
    first = None
    for y in range(h):
        row = img.crop((0, y, w, y + 1)).getdata()
        if max(p[3] for p in row) >= THRESHOLD:
            first = y
            break
    if first is None:
        print("%d      %dx%d  empty" % (index, w, h))
        continue
    fraction = (h - first) / float(h)
    print("%d      %dx%d  row %4d  %.3f" % (index, w, h, first, fraction))
