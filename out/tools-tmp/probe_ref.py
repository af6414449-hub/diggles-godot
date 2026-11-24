import numpy as np
from PIL import Image

ref = r"C:\Users\frant\.minimax\v2\assets\2026\11\22\19-11-50-767-asset_20261122-191150-767_2dd8dfdb4050_08710dea-image.png"
data = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\Ground"

im = Image.open(ref).convert("RGB")
a = np.asarray(im).astype(np.float32)
w, h = im.size
print("ref", w, h)

tl = a[0:h // 2, 0:w // 2]
tr = a[0:h // 2, w // 2:w]


def norm_gray(t):
    g = t.mean(axis=2)
    g = g - g.mean()
    s = g.std()
    return g / s if s > 0 else g


def corr(refq, tile):
    a1 = norm_gray(refq).ravel()
    a2 = norm_gray(tile).ravel()
    n = min(len(a1), len(a2))
    return float(np.corrcoef(a1[:n], a2[:n])[0, 1])


def period(t):
    prof = t.mean(axis=0)
    prof = prof - prof.mean()
    out = []
    for lag in range(2, min(70, len(prof) - 1)):
        out.append((float(np.corrcoef(prof[:-lag], prof[lag:])[0, 1]), lag))
    out.sort(reverse=True)
    return out[:5]


print("TL ground col periods:", [("%.2f@%d" % (c, l)) for c, l in period(tl)])
print("TR stone col periods:", [("%.2f@%d" % (c, l)) for c, l in period(tr)])

rows = []
for fam in ("A", "B", "C"):
    for i in range(1, 16):
        name = "Gnd_%s%02d.tga" % (fam, i)
        t = np.asarray(Image.open(data + "\\" + name).convert("RGB")).astype(np.float32)
        rows.append((corr(tl, t), corr(tr, t), name))
rows.sort(reverse=True)
print("\nbest match for TL (want ground):")
for c1, c2, n in rows[:6]:
    print("   %-12s ground %.3f  stone %.3f" % (n, c1, c2))
rows2 = sorted(rows, key=lambda r: -r[1])
print("best match for TR (want stone):")
for c1, c2, n in rows2[:6]:
    print("   %-12s ground %.3f  stone %.3f" % (n, c1, c2))
