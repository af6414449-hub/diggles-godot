import numpy as np
from PIL import Image
import os
folder = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\Ground"
for name, side in (("Gnd_A15.tga","top"), ("Gnd_A13.tga","top"), ("Gnd_A03.tga","bottom"),
                   ("Gnd_A07.tga","bottom"), ("Gnd_C03.tga","bottom"), ("Gnd_C11.tga","right")):
    a = np.asarray(Image.open(os.path.join(folder, name)).convert("RGB")).astype(np.float32)
    t = 0.299*a[:,:,0] + 0.587*a[:,:,1] + 0.114*a[:,:,2]
    h, w = t.shape
    if side == "top":
        prof = t[:16, :].mean(axis=1)
    elif side == "bottom":
        prof = t[h-16:, :].mean(axis=1)[::-1]
    elif side == "left":
        prof = t[:, :16].mean(axis=0)
    else:
        prof = t[:, w-16:].mean(axis=0)[::-1]
    base = float(t[20:h-20, 20:w-20].mean())
    print("%-14s %-6s tile=%dx%d  base=%.2f" % (name, side, w, h, base))
    print("   profile from the edge: " + " ".join("%.1f" % v for v in prof))
    print("   depth at 1..8 px: %s" % " ".join("%.1f" % (base - v) for v in prof[1:9]))
