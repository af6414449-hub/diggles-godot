import sys, os
sys.path.insert(0, r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\tools-tmp")
import importlib.util
spec = importlib.util.spec_from_file_location("bmv", r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\tools-tmp\build_matte_variant.py")
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
from PIL import Image
# Окно кадра в широком виде: горизонт кадра на 0.151 высоты -> строка матки 320-0.151*720
WINDOW_TOP = 320 - int(0.151*720)
print("окно широкого вида: строки матки", WINDOW_TOP, "..", WINDOW_TOP+720)
variants = {
  "D":  [(1, 92), (2, 145), (3, 195), (4, 285)],
  "D2": [(1, 216), (2, 248), (3, 272), (4, 300)],
  "D3": [(1, 200), (2, 235), (3, 265), (4, 298)],
}
paths = {}
for name, strips in variants.items():
    p = m.build(1.0, strips, "zz-matte-%s-fit.png" % name)
    paths[name] = p
strips = []
for name in ("D","D3","D2"):
    im = Image.open(paths[name]).convert("RGB")
    win = im.crop((0, WINDOW_TOP, 2048, WINDOW_TOP+720)).resize((1280, 450), Image.LANCZOS)
    strips.append((name, win))
sheet = Image.new("RGB", (1280, len(strips)*480), (24,24,26))
from PIL import ImageDraw, ImageFont
try:
    font = ImageFont.truetype(r"C:\Windows\Fonts\arialbd.ttf", 22)
except Exception:
    font = ImageFont.load_default()
d = ImageDraw.Draw(sheet)
y = 0
for name, win in strips:
    d.text((6, y+4), name + " (okno shirokogo vida)", font=font, fill=(240,200,120))
    sheet.paste(win, (0, y+28))
    y += 480
out = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots\zz-bandfit-compare.png"
sheet.save(out)
print("ok", out)
