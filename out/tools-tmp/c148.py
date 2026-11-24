from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
im = Image.open(base + r"\v148-wide-warm.png").convert("RGB")
im.crop((0,0,1280,240)).save(base + r"\zz-v148-top.png")
print("ok")
