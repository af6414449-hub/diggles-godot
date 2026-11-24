import numpy as np, os
from PIL import Image
s=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a=np.asarray(Image.open(os.path.join(s,"v109-wide.png")).convert("RGB")).astype(np.int16)
b=np.asarray(Image.open(os.path.join(s,"v109-wide-norock.png")).convert("RGB")).astype(np.int16)
c=np.asarray(Image.open(os.path.join(s,"v109-wide-nofree.png")).convert("RGB")).astype(np.int16)
d1=np.abs(a-b).max(axis=2); d2=np.abs(a-c).max(axis=2)
print("pixels changed by --hide-rock-body: %d (%.1f %%)" % ((d1>6).sum(), 100.0*(d1>6).mean()))
print("pixels changed by --hide-free-ground: %d (%.1f %%)" % ((d2>6).sum(), 100.0*(d2>6).mean()))
ys,xs=np.where(b.max(axis=2)==0)
print("black pixels in the norock frame: %d, rows %s..%s, cols %s..%s" % (len(ys), ys.min() if len(ys) else '-', ys.max() if len(ys) else '-', xs.min() if len(xs) else '-', xs.max() if len(xs) else '-'))
print("mean lum of the norock frame: %.2f" % (0.299*b[:,:,0]+0.587*b[:,:,1]+0.114*b[:,:,2]).mean())