import numpy as np, os
from PIL import Image
s=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a=np.asarray(Image.open(os.path.join(s,"v115-mine.png")).convert("RGB")).astype(np.float32)
lum=0.299*a[:,:,0]+0.587*a[:,:,1]+0.114*a[:,:,2]
reg=lum[220:290,690:880]
print("min lum in the region: %.2f, pixels < 42: %d" % (reg.min(), (reg<42).sum()))
ys,xs=np.where(reg<42)
if len(ys):
    print("dark rows:", sorted(set((ys+220).tolist()))[:40])
    print("dark cols:", sorted(set((xs+690).tolist()))[:40])
    # the darkest columns
    col=reg.min(axis=0)
    order=np.argsort(col)[:12]
    print("darkest columns (x, min lum):", [(int(i+690), round(float(col[i]),1)) for i in sorted(order)])
    row=reg.min(axis=1)
    order=np.argsort(row)[:12]
    print("darkest rows (y, min lum):", [(int(i+220), round(float(row[i]),1)) for i in sorted(order)])