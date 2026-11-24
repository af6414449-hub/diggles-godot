from PIL import Image
import numpy as np, os
src = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\backdrop"
for i in (1, 2, 3):
    im = Image.open(os.path.join(src, "Panorama_layer_%d.tga" % i)).convert("RGBA")
    a = np.asarray(im).astype(int)
    h, w = a.shape[:2]
    print("--- слой %d (%dx%d)" % (i, w, h))
    for frac in (0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0):
        y = h-1-int(frac*(h-1))
        row = a[y, ::16]
        print("   строка %3d (%.0f%% сверху): rgb %s alpha %d..%d" % (
            y, frac*100, row[:,:3].mean(axis=0).round().tolist(), row[:,3].min(), row[:,3].max()))
