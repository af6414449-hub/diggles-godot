from PIL import Image
import os
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
p = os.path.join(base, "v164-default.png")
if os.path.exists(p):
    Image.open(p).convert("RGB").crop((0,0,1280,400)).save(os.path.join(base, "zz-v164-top.png"))
    print("ok")
