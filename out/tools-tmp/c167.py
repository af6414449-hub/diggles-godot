from PIL import Image
import numpy as np, os
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
p = os.path.join(base, "v167-test.png")
if os.path.exists(p):
    n = np.asarray(Image.open(p).convert("RGB")).astype(int)
    print("колонка x=430:", [(y, n[y,430].tolist()) for y in range(0, 300, 30)])
    Image.open(p).convert("RGB").crop((0,0,1280,400)).save(os.path.join(base, "zz-v167-top.png"))
