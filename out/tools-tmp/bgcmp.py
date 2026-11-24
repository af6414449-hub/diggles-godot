from PIL import Image, ImageDraw, ImageFont
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
try:
    font = ImageFont.truetype(r"C:\Windows\Fonts\arialbd.ttf", 22)
except Exception:
    font = ImageFont.load_default()
names = [("v137-wide-default.png", "BYLO: srez 30% - razmazannye polosy"),
         ("v13D-wide-bg.png", "D: oblaka-dymka-gory-les"),
         ("v13E-wide-bg.png", "E: oblaka-gory-les (bez dymki)")]
rows = []
for fn, label in names:
    im = Image.open(base + "\\" + fn).convert("RGB")
    rows.append((label, im.crop((0, 0, 1280, 220)).resize((1280, 220), Image.LANCZOS)))
sheet = Image.new("RGB", (1280, len(rows)*254+8), (24,24,26))
d = ImageDraw.Draw(sheet)
y = 4
for label, strip in rows:
    d.text((6, y), label, font=font, fill=(240,200,120))
    sheet.paste(strip, (0, y+28))
    y += 254
sheet.save(base + r"\zz-bg-compare.png")
print("ok", sheet.size)
