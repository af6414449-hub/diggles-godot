from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
im = Image.open(base + r"\v137-wide-default.png").convert("RGB")
im.crop((370, 400, 900, 620)).resize((1060, 440), Image.LANCZOS).save(base + r"\zz-v137-crop.png")
print("ok")
