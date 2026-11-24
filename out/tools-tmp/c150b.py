from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
im = Image.open(base + r"\v150-wide-landscape.png").convert("RGB")
im.crop((0,0,1280,240)).save(base + r"\zz-v150-top.png")
im2 = Image.open(base + r"\v149-default-landscape.png").convert("RGB")
im2.crop((0,0,1280,300)).save(base + r"\zz-v149-top.png")
print("ok")
