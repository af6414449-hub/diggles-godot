from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
im = Image.open(base + r"\zz-matte-G-groundtile.png").convert("RGB")
im.crop((0, 320, 2048, 1152)).resize((1280, 520), Image.LANCZOS).save(base + r"\zz-matte-G-ground.png")
print("ok")
