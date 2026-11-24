import sys
from PIL import Image, ImageChops
import numpy as np
a = Image.open(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots\v115-mine.png").convert("RGB")
b = Image.open(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots\v124-ramp-only.png").convert("RGB")
print("size", a.size, b.size)
if a.size != b.size:
    sys.exit("size differs")
d = np.asarray(ImageChops.difference(a,b)).sum(axis=2)
ys,xs = np.nonzero(d>6)
print("diff pixels:", len(xs))
if len(xs):
    print("bbox x", xs.min(), xs.max(), "y", ys.min(), ys.max())
    # cluster rows
    rows = sorted(set(ys.tolist()))
    print("rows with diff:", rows[:80])
