from PIL import Image
import os
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
for n in ("v161-default", "v162-wide"):
    p = os.path.join(base, n + ".png")
    if os.path.exists(p):
        im = Image.open(p).convert("RGB")
        im.crop((0, 0, 1280, 300)).save(os.path.join(base, "zz-%s-top.png" % n))
        print(n, "ok")
