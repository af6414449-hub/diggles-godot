from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
import os
p = base + r"\v150-wide-landscape.png"
if os.path.exists(p):
    Image.open(p).convert("RGB").crop((0,0,1280,240)).save(base + r"\zz-v150-top.png")
    print("ok")
