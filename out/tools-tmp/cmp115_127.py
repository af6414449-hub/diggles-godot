from PIL import Image, ImageChops
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a = Image.open(base + r"\v115-mine.png").convert("RGB")
b = Image.open(base + r"\v127-mine-novertical.png").convert("RGB")
d = np.asarray(ImageChops.difference(a,b)).sum(axis=2)
ys,xs = np.nonzero(d>6)
print("diff pixels:", len(xs))
if len(xs):
    print("bbox x", xs.min(), xs.max(), "y", ys.min(), ys.max())
# band row profile in v127 at x=600
n = np.asarray(b).astype(int)
print("v127 x=600 rows 445..495")
for y in range(445, 496):
    print(y, n[y,600].tolist(), n[y,700].tolist())
