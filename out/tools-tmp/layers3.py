from PIL import Image
import numpy as np, os
d = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\backdrop"
out = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
tiles = []
for i in range(6):
    im = Image.open(os.path.join(d, "campaign_panorama_layer_%d.png" % i)).convert("RGBA")
    a = np.asarray(im)
    rows = np.nonzero(a[:, :, 3].max(axis=1) > 8)[0]
    print("layer", i, im.size, "непрозрачные строки:", (rows.min(), rows.max()) if len(rows) else None)
    bg = Image.new("RGBA", im.size, (40, 40, 60, 255))
    bg.alpha_composite(im)
    tiles.append(bg.convert("RGB").resize((512, 180), Image.LANCZOS))
sheet = Image.new("RGB", (512, 180*6), (0,0,0))
for i, t in enumerate(tiles):
    sheet.paste(t, (0, 180*i))
sheet.save(os.path.join(out, "zz-layers-sheet.png"))
print("ok")
