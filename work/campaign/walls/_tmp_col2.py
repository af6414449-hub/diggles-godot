import numpy as np
from PIL import Image
s=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a=np.asarray(Image.open(s+r"\v106-wide.png").convert("RGB")).astype(np.float32)
b=np.asarray(Image.open(s+r"\v106-wide-novert.png").convert("RGB")).astype(np.float32)
def lum(img,x,y): return 0.299*img[y,x,0]+0.587*img[y,x,1]+0.114*img[y,x,2]
for x in (440,470,500,530,560):
    print("column x=%d" % x)
    for y in range(302,314):
        print("   y=%3d  full %6.2f   no-vertical %6.2f" % (y, lum(a,x,y), lum(b,x,y)))