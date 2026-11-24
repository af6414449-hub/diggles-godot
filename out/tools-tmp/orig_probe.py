from PIL import Image
import numpy as np
p = r"C:\Users\frant\.minimax\v2\assets\2026\11\23\03-03-23-418-asset_20261123-030323-418_294487c41522_92cfc8ac-image.png"
im = Image.open(p).convert("RGB")
print("original:", im.size)
a = np.asarray(im).astype(int)
h, w = a.shape[:2]
print("--- вертикальный проход по x=1050 (справа, где видно панораму) ---")
for y in range(0, h, 20):
    print(y, a[y, 1050].tolist())
