from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
im = Image.open(base + r"\v115-mine.png").convert("RGB")
im.crop((430, 400, 1030, 560)).resize((600*3, 160*3), Image.LANCZOS).save(base + r"\zz-v115-corridor.png")
im2 = Image.open(base + r"\v115-mine.png").convert("RGB")
im2.crop((850, 420, 1150, 700)).resize((300*3, 280*3), Image.LANCZOS).save(base + r"\zz-v115-shaft.png")
print("ok")
