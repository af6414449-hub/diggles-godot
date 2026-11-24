from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
Image.open(base + r"\v158-wide-parallax.png").convert("RGB").crop((0,0,1280,240)).save(base + r"\zz-v158-top.png")
print("ok")
