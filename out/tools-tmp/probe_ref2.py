import numpy as np
from PIL import Image

ref = r"C:\Users\frant\.minimax\v2\assets\2026\11\22\19-11-50-767-asset_20261122-191150-767_2dd8dfdb4050_08710dea-image.png"
data = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\Ground"

im = Image.open(ref).convert("RGB")
a = np.asarray(im).astype(np.float32)
w, h = im.size
tl = a[0:h // 2, 0:w // 2]
tr = a[0:h // 2, w // 2:w]
print("crop size", tl.shape)


def g(t):
    v = t.mean(axis=2)
    v = v - v.mean()
    s = v.std()
    return v / s if s > 0 else v


def corr(refq, tile):
    n = min(refq.shape[0], tile.shape[0]), min(refq.shape[1], tile.shape[1])
    a1 = g(refq[: n[0], : n[1]]).ravel()
    a2 = g(tile[: n[0], : n[1]]).ravel()
    return float(np.corrcoef(a1, a2)[0, 1])


def best(refq, scales):
    out = []
    for fam in ("A", "B", "C"):
        for i in range(1, 16):
            name = "Gnd_%s%02d.tga" % (fam, i)
            t = Image.open(data + "\\" + name).convert("RGB")
            for sc in scales:
                r = t.resize((max(1, int(64 * sc)), max(1, int(64 * sc))), Image.LANCZOS)
                out.append((corr(refq, np.asarray(r).astype(np.float32)), name, sc))
    out.sort(reverse=True)
    return out[:8]


scales = [0.5, 0.75, 1.0, 1.5, 2.0, 2.5]
print("\nTL (want ground) best native tile:")
for c, n, s in best(tl, scales):
    print("   %.3f  %-12s scale %.2f" % (c, n, s))
print("\nTR (want stone) best native tile:")
for c, n, s in best(tr, scales):
    print("   %.3f  %-12s scale %.2f" % (c, n, s))
