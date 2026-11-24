from PIL import Image
import os
src = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\ground"
names = ["Gnd_A01.tga", "Gnd_B01.tga", "Gnd_C01.tga"]
ims = [Image.open(os.path.join(src, n)).convert("RGB") for n in names]
w = sum(i.width for i in ims); h = max(i.height for i in ims)
out = Image.new("RGB", (w, h), (0, 0, 0))
x = 0
for im in ims:
    out.paste(im, (x, 0)); x += im.width
out = out.resize((w*2, h*2), Image.NEAREST)
out.save(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\ground-families.png")
print("ok", out.size)
