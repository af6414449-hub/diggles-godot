from PIL import Image
import os
src = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\backdrop"
out = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
tiles = []
for i in range(7):
    im = Image.open(os.path.join(src, "Panorama_layer_%d.tga" % i)).convert("RGBA")
    print("layer", i, im.size)
    bg = Image.new("RGBA", im.size, (215, 230, 252, 255))
    bg.alpha_composite(im)
    tiles.append(bg.convert("RGB").resize((512, 128), Image.LANCZOS))
sheet = Image.new("RGB", (512, 128*7), (20,20,20))
for i, t in enumerate(tiles):
    sheet.paste(t, (0, 128*i))
sheet.save(os.path.join(out, "zz-panorama-layers.png"))
# верх кадра
im = Image.open(os.path.join(out, "v137-wide-default.png")).convert("RGB")
im.crop((0, 0, 1280, 150)).resize((1280, 150), Image.LANCZOS).save(os.path.join(out, "zz-backdrop-top.png"))
print("ok")
