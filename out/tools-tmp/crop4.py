from PIL import Image
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
im = Image.open(base + r"\v128-mine-bare.png").convert("RGB")
im.crop((430, 400, 1030, 560)).resize((600*3, 160*3), Image.LANCZOS).save(base + r"\zz-v128-corridor.png")
n = np.asarray(im).astype(int)
print("v128 x=600 rows 448..495")
for y in range(448, 496):
    print(y, n[y,600].tolist())
