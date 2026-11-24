import numpy as np
from PIL import Image
o1 = r"C:\Users\frant\.minimax\v2\assets\2026\11\22\20-38-07-060-asset_20261122-203807-060_1f9eeace77f8_44ea2e54-image.png"
o2 = r"C:\Users\frant\.minimax\v2\assets\2026\11\22\20-38-07-079-asset_20261122-203807-079_1dc0ce01de3a_fe7bc1c6-image.png"
for p in (o1, o2):
    im = Image.open(p).convert("RGB")
    a = np.asarray(im).astype(float)
    print(p.split("-")[-1], im.size)
    h, w = a.shape[:2]
    print("  средний тон:", a.reshape(-1,3).mean(axis=0).round(1))
