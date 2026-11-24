from PIL import Image
import numpy as np, os
d = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\backdrop"
out = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
tiles = []
for n in ["sky","mountains","forest","meadow"]:
    im = Image.open(os.path.join(d, "campaign_panorama_%s.png" % n)).convert("RGBA")
    bg = Image.new("RGBA", im.size, (60, 30, 30, 255)); bg.alpha_composite(im)
    tiles.append(bg.convert("RGB").resize((640, 225), Image.LANCZOS))
sheet = Image.new("RGB", (640, 225*4), (0,0,0))
for i, t in enumerate(tiles): sheet.paste(t, (0, 225*i))
sheet.save(os.path.join(out, "zz-layers4b.png"))
print("ok")
