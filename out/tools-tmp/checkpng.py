from PIL import Image
import numpy as np, os
d = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\backdrop"
for n in ["sky","mountains","forest","meadow"]:
    im = Image.open(os.path.join(d, "campaign_panorama_%s.png" % n)).convert("RGBA")
    a = np.asarray(im)
    print("---", n, im.size, "alpha макс", a[:,:,3].max())
    for y in (0, 40, 90, 140, 177):
        if y < a.shape[0]:
            print("   строка %3d: rgb %s alpha %d" % (y, a[y,600,:3].tolist(), a[y,600,3]))
