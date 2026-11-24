from PIL import Image
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a = Image.open(base + r"\v115-mine.png").convert("RGB")
b = Image.open(base + r"\v133-mine-litex.png").convert("RGB")
b.crop((430, 400, 1030, 560)).resize((600*3, 160*3), Image.LANCZOS).save(base + r"\zz-v133-corridor.png")
n = np.asarray(b).astype(int)
m = np.asarray(a).astype(int)
print("y   v115(x=600)      v133(x=600)")
for y in range(445, 496):
    print(y, m[y,600].tolist(), n[y,600].tolist())
