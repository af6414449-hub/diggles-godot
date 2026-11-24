import numpy as np, os
from PIL import Image
s=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
def load(n):
    p=os.path.join(s,n)
    return np.asarray(Image.open(p).convert("RGB")).astype(np.float32) if os.path.isfile(p) else None
names=["v109-wide.png","v109-wide-nofree.png","v109-wide-norock.png"]
fr={n:load(n) for n in names}
def lum(img,x,y): return 0.299*img[y,x,0]+0.587*img[y,x,1]+0.114*img[y,x,2]
for x in (500,530):
    print("column x=%d" % x)
    for y in range(304,313):
        row="   y=%3d" % y
        for n in names:
            if fr[n] is not None: row += "  %-18s %6.2f" % (n.replace(".png",""), lum(fr[n],x,y))
        print(row)