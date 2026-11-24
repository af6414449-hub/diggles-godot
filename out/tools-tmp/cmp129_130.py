from PIL import Image, ImageChops
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a = Image.open(base + r"\v129-side.png").convert("RGB")
b = Image.open(base + r"\v130-side-nofree.png").convert("RGB")
d = np.asarray(ImageChops.difference(a,b)).sum(axis=2)
ys,xs = np.nonzero(d>6)
print("diff pixels:", len(xs), "bbox", (xs.min(),xs.max(),ys.min(),ys.max()) if len(xs) else None)
n = np.asarray(b).astype(int)
print("v130 x=600 rows 445..495")
for y in range(445, 496):
    print(y, n[y,600].tolist())
