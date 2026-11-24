from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
Image.open(base + r"\v146-wide-meadow.png").convert("RGB").crop((0,0,1280,240)).save(base + r"\zz-v146-top.png")
print("ok")
