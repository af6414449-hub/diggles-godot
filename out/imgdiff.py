import sys
from PIL import Image
import numpy as np

a = Image.open(sys.argv[1]).convert("RGB")
b = Image.open(sys.argv[2]).convert("RGB")
na = np.asarray(a).astype(np.int16)
nb = np.asarray(b).astype(np.int16)
d = np.abs(na - nb).sum(axis=2)
print("shape", d.shape, "max", d.max(), "mean", round(float(d.mean()), 3))
changed = d > 12
print("pixels changed >12:", int(changed.sum()), "of", d.size)
ys, xs = np.nonzero(changed)
if len(xs):
    print("bbox x", int(xs.min()), int(xs.max()), "y", int(ys.min()), int(ys.max()))
    Image.fromarray((changed * 255).astype(np.uint8)).save(sys.argv[3])
    print("diff mask ->", sys.argv[3])
