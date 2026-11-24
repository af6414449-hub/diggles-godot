from PIL import Image, ImageDraw, ImageFont
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
try:
    font = ImageFont.truetype(r"C:\Windows\Fonts\arialbd.ttf", 22)
except Exception:
    font = ImageFont.load_default()
items = [
  ("ORIGINAL: fon igry (boevaya scena)", Image.open(r"C:\Users\frant\.minimax\v2\assets\2026\11\23\03-03-23-418-asset_20261123-030323-418_294487c41522_92cfc8ac-image.png").convert("RGB").crop((330,0,1247,300)).resize((1280,420), Image.LANCZOS)),
  ("PORT: shirokiy vid, fon", Image.open(base + r"\v148-wide-warm.png").convert("RGB").crop((0,0,1280,240))),
]
sheet = Image.new("RGB", (1280, sum(i[1].size[1]+34 for i in items)+8), (24,24,26))
d = ImageDraw.Draw(sheet); y = 4
for lbl, t in items:
    d.text((6,y), lbl, font=font, fill=(240,200,120)); sheet.paste(t, (0,y+28)); y += t.size[1]+34
sheet.save(base + r"\zz-bg-vs-original.png"); print("ok")
