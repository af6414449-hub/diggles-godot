from PIL import Image
import numpy as np, os
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
for f in ("v171-default.png", "v172-wide.png"):
    p = os.path.join(base, f)
    if not os.path.exists(p):
        print(f, "нет"); continue
    n = np.asarray(Image.open(p).convert("RGB")).astype(int)
    print(f, "x=430:", [(y, n[y,430].tolist()) for y in range(0, 300, 30)])
    Image.open(p).convert("RGB").crop((0,0,1280,400)).save(os.path.join(base, "zz-" + f.replace(".png","") + "-top.png"))
