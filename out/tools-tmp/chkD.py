from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
im = Image.open(base + r"\v13D-wide-bg.png").convert("RGB")
im.crop((0, 0, 1280, 260)).save(base + r"\zz-v13D-top.png")
print("ok")
