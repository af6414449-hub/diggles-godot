from PIL import Image
import os
root = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
tiles = os.path.join(root, "godot", "textures", "ground_tiles")
names = ["Gnd_A01.png", "Gnd_C01.png", "Gnd_C07.png"]
sheet = Image.new("RGB", (64 * 3, 64))
for index, name in enumerate(names):
    sheet.paste(Image.open(os.path.join(tiles, name)).convert("RGB"), (index * 64, 0))
sheet = sheet.resize((64 * 3 * 4, 64 * 4), Image.NEAREST)
out = os.path.join(root, "out", "campaign-shots", "tile-sample.png")
sheet.save(out)
print("saved", out, names)
