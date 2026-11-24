from PIL import Image
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a = Image.open(base + r"\v141-default-view.png").convert("RGB")
b = Image.open(base + r"\v143-default-final.png").convert("RGB") if __import__("os").path.exists(base + r"\v143-default-final.png") else None
print("v143 есть:", b is not None)
w = Image.open(base + r"\v142-wide-final.png").convert("RGB")
w.crop((0,0,1280,220)).save(base + r"\zz-v142-top.png")
if b is not None:
    n = np.asarray(b).astype(int); m = np.asarray(a).astype(int)
    print("размытая область (400,150): было", m[150,400].tolist(), "стало", n[150,400].tolist())
    print("размытая область (300,200): было", m[200,300].tolist(), "стало", n[200,300].tolist())
