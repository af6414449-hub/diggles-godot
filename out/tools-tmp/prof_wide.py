from PIL import Image
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a = np.asarray(Image.open(base + r"\v135-wide-base.png").convert("RGB")).astype(int)
b = np.asarray(Image.open(base + r"\v134-wide-litex.png").convert("RGB")).astype(int)
for row in (516, 517, 518):
    print("--- row", row)
    for x in range(560, 660, 2):
        print(x, a[row,x].tolist(), b[row,x].tolist())
