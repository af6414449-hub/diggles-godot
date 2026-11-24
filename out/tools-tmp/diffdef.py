from PIL import Image, ImageChops
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a = Image.open(base + r"\v141-default-view.png").convert("RGB")
b = Image.open(base + r"\v143-default-final.png").convert("RGB")
d = np.asarray(ImageChops.difference(a,b)).sum(axis=2)
ys,xs = np.nonzero(d>6)
print("различающихся пикселей:", len(xs))
if len(xs): print("bbox x", xs.min(), xs.max(), "y", ys.min(), ys.max())
a.crop((0,0,640,360)).resize((640,360)).save(base + r"\zz-v141-tl.png")
b.crop((0,0,640,360)).resize((640,360)).save(base + r"\zz-v143-tl.png")
print("ok")
