from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
im = Image.open(base + r"\v127-mine-novertical.png").convert("RGB")
im.crop((430, 400, 1030, 560)).resize((600*3, 160*3), Image.LANCZOS).save(base + r"\zz-v127-corridor.png")
print("ok")
