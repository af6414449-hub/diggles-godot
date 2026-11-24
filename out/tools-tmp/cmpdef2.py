from PIL import Image
import numpy as np, os
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a = np.asarray(Image.open(base + r"\v141-default-view.png").convert("RGB")).astype(int)
p = base + r"\v143-default-final.png"
print("v143 есть:", os.path.exists(p))
if os.path.exists(p):
    b = np.asarray(Image.open(p).convert("RGB")).astype(int)
    for (x,y) in ((400,150),(300,200),(500,100),(200,250)):
        print("(%d,%d) было %s стало %s" % (x,y,a[y,x].tolist(),b[y,x].tolist()))
