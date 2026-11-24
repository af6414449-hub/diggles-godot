from PIL import Image
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
im = Image.open(base + r"\v136-mine-default.png").convert("RGB")
im.crop((430, 400, 1030, 560)).resize((1800, 480), Image.LANCZOS).save(base + r"\zz-v136-corridor.png")
n = np.asarray(im).astype(int)
print("пол выработки, ряды 456-476 (x=600):", [n[y,600][0] for y in range(456,477)])
