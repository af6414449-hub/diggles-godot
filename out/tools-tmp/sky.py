from PIL import Image
import numpy as np, os
src = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\backdrop"
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
W, H = 2048, 1152
HORIZON = 320
def load(i):
    return Image.open(os.path.join(src, "Panorama_layer_%d.tga" % i)).convert("RGBA")
def content_rows(im):
    w, h = im.size
    for y in range(h):
        row = [im.getpixel((x, y))[3] for x in range(0, w, 4)]
        if max(row) >= 32:
            return y
    return h

def build(name, sky_mode, sky_gain=1.0):
    canvas = Image.new("RGBA", (W, H), (215, 230, 252, 255))
    # --- небо
    if sky_mode == "haze":
        # тёплая дымка оригинала (слой 2) на всю полосу неба + облака (слой 1)
        haze = load(2)
        first = content_rows(haze)
        part = haze.crop((0, first, haze.width, haze.height)).resize((W, HORIZON), Image.LANCZOS)
        arr = np.asarray(part.convert("RGB"), dtype=np.float32) * sky_gain
        part = Image.fromarray(np.clip(arr,0,255).astype(np.uint8), "RGB").convert("RGBA")
        canvas.alpha_composite(part, (0, 0))
        clouds = load(1).resize((W, HORIZON), Image.LANCZOS)
        canvas.alpha_composite(clouds, (0, 0))
    else:
        canvas.alpha_composite(load(0).resize((W, H), Image.LANCZOS))
    # --- полосы ландшафта: горы, лес (слой 5 - луг уходит в землю)
    for index, ridge in ((3, 265), (4, 298)):
        strip = load(index)
        first = content_rows(strip)
        share = 1.0 - float(first)/float(strip.height)
        height = int(round((HORIZON - ridge)/max(share, 0.0001)))
        canvas.alpha_composite(strip.resize((W, height), Image.LANCZOS), (0, HORIZON - height))
    # --- земля: яркий луг оригинала
    meadow = load(5)
    piece = meadow.crop((0, meadow.height-128, meadow.width, meadow.height))
    block = piece.resize((W, 128*(W//meadow.width)), Image.LANCZOS)
    target = H - HORIZON
    ground = Image.new("RGB", (W, target)); y = 0
    while y < target:
        ground.paste(block.convert("RGB"), (0, y)); y += block.size[1]
    ground = ground.crop((0,0,W,target))
    arr = np.asarray(ground, dtype=np.float32) * 1.45
    canvas.alpha_composite(Image.fromarray(np.clip(arr,0,255).astype(np.uint8),"RGB").convert("RGBA"), (0, HORIZON))
    p = os.path.join(base, name)
    canvas.convert("RGB").save(p)
    return p

print(build("zz-matte-S1-haze.png", "haze"))
print(build("zz-matte-S2-haze-dark.png", "haze", 0.72))
# лист: полоса неба S1/S2 + кадр оригинала
orig = Image.open(r"C:\Users\frant\.minimax\v2\assets\2026\11\23\03-03-23-418-asset_20261123-030323-418_294487c41522_92cfc8ac-image.png").convert("RGB")
tiles = []
for nm, lbl in (("zz-matte-S1-haze.png","S1: dymka + oblaka"), ("zz-matte-S2-haze-dark.png","S2: to zhe, temnee")):
    im = Image.open(os.path.join(base, nm)).convert("RGB")
    tiles.append((lbl, im.crop((0,0,2048,320)).resize((1280,200), Image.LANCZOS)))
tiles.append(("ORIGINAL: nebo igry", orig.crop((0,0,1247,240)).resize((1280,246), Image.LANCZOS)))
from PIL import ImageDraw, ImageFont
font = ImageFont.truetype(r"C:\Windows\Fonts\arialbd.ttf", 22)
sheet = Image.new("RGB", (1280, sum(t[1].size[1]+34 for t in tiles)+8), (24,24,26))
d = ImageDraw.Draw(sheet); y = 4
for lbl, t in tiles:
    d.text((6,y), lbl, font=font, fill=(240,200,120)); sheet.paste(t, (0,y+28)); y += t.size[1]+34
sheet.save(os.path.join(base, "zz-sky-compare.png"))
print("ok")
