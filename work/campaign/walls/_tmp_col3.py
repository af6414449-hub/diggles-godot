import numpy as np, os
from PIL import Image
s=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
names=["v106-wide.png","v106-wide-novert.png","v107-wide-nofree.png"]
frames={}
for n in names:
    p=os.path.join(s,n)
    if os.path.isfile(p):
        frames[n]=np.asarray(Image.open(p).convert("RGB")).astype(np.float32)
def lum(img,x,y): return 0.299*img[y,x,0]+0.587*img[y,x,1]+0.114*img[y,x,2]
for x in (470,500,530):
    print("column x=%d" % x)
    for y in range(304,312):
        row="   y=%3d" % y
        for n in names:
            if n in frames:
                row += "  %-14s %6.2f" % (n.replace(".png",""), lum(frames[n],x,y))
        print(row)