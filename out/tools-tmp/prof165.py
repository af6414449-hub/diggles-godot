from PIL import Image
import numpy as np, os
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
im = Image.open(os.path.join(base, "v165-diag.png")).convert("RGB")
n = np.asarray(im).astype(int)
print("колонка x=430:")
for y in range(0, 320, 20):
    print("   ", y, n[y,430].tolist())
