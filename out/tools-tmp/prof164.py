from PIL import Image
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
n = np.asarray(Image.open(base + r"\v164-default.png").convert("RGB")).astype(int)
for x in (10, 30, 430):
    print("--- колонка x=%d" % x)
    for y in range(0, 320, 20):
        print("   ", y, n[y,x].tolist())
