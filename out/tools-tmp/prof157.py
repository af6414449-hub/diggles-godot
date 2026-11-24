from PIL import Image
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
n = np.asarray(Image.open(base + r"\v157-default-parallax.png").convert("RGB")).astype(int)
print("колонка x=30 (фон слева):")
for y in range(100, 400, 10):
    print(y, n[y,30].tolist())
