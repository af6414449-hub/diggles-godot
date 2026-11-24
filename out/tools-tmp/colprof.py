from PIL import Image
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
im = Image.open(base + r"\v115-mine.png").convert("RGB")
a = np.asarray(im).astype(int)
print("column x=600, rows 430..500")
for y in range(430, 501):
    print(y, a[y,600].tolist(), a[y,700].tolist(), a[y,900].tolist())
