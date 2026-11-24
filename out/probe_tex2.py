from PIL import Image
import os
src = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\ground"
names = ["Gnd_A01.tga","Gnd_A05.tga","Gnd_A09.tga","Gnd_A13.tga","Gnd_B01.tga","Gnd_B05.tga",
         "Gnd_B09.tga","Gnd_B13.tga","Gnd_C01.tga","Gnd_C05.tga","Gnd_C09.tga","Gnd_C13.tga"]
ims = [Image.open(os.path.join(src, n)).convert("RGB") for n in names]
tw, th = 128, 64
cols, rows = 4, 3
out = Image.new("RGB", (cols*tw, rows*th), (0,0,0))
for i, im in enumerate(ims):
    out.paste(im.resize((tw, th), Image.NEAREST), ((i % cols)*tw, (i//cols)*th))
out.save(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\ground-variants.png")
print("ok")
