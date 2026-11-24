from PIL import Image, ImageChops
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a = Image.open(base + r"\v135-wide-base.png").convert("RGB")
b = Image.open(base + r"\v134-wide-litex.png").convert("RGB")
box = (370, 400, 900, 620)
a.crop(box).resize((530*2, 220*2), Image.LANCZOS).save(base + r"\zz-AB-base.png")
b.crop(box).resize((530*2, 220*2), Image.LANCZOS).save(base + r"\zz-AB-litex.png")
d = np.asarray(ImageChops.difference(a,b)).sum(axis=2)
ys,xs = np.nonzero(d>6)
print("diff pixels:", len(xs), "bbox", (xs.min(),xs.max(),ys.min(),ys.max()) if len(xs) else None)
