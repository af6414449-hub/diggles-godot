from PIL import Image
import numpy as np, os
d = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\backdrop"
for n in ["sky","mountains","forest","meadow"]:
    im = Image.open(os.path.join(d, "campaign_panorama_%s.png" % n)).convert("RGBA")
    a = np.asarray(im)
    print("---", n)
    for y in (0, 30, 100, 170, 200, 260, 320, 500, 700):
        if y < a.shape[0]:
            print("   %3d rgb %s alpha %d" % (y, a[y,600,:3].tolist(), a[y,600,3]))
