from PIL import Image, ImageDraw, ImageFont
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
try:
    font = ImageFont.truetype(r"C:\Windows\Fonts\arialbd.ttf", 22)
except Exception:
    font = ImageFont.load_default()
names = [("zz-matte-C-current.png", "C: tekushchiy matka"),
         ("zz-matte-A-fullslice.png", "A: polnaya panorama, 3 sloya"),
         ("zz-matte-D-rings.png", "D: oblaka-dymka-gory-les"),
         ("zz-matte-E-rings-nohaze.png", "E: oblaka-gory-les (bez dymki)")]
rows = []
for fn, label in names:
    im = Image.open(base + "\\" + fn).convert("RGB")
    rows.append((label, im.crop((0, 0, 2048, 320)).resize((1280, 200), Image.LANCZOS)))
sheet = Image.new("RGB", (1280, len(rows)*234+8), (24,24,26))
d = ImageDraw.Draw(sheet)
y = 4
for label, strip in rows:
    d.text((6, y), label, font=font, fill=(240,200,120))
    sheet.paste(strip, (0, y+28))
    y += 234
sheet.save(base + r"\zz-matte-compare2.png")
print("ok", sheet.size)
