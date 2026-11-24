from PIL import Image, ImageDraw, ImageFont
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
try:
    font = ImageFont.truetype(r"C:\Windows\Fonts\arialbd.ttf", 22)
except Exception:
    font = ImageFont.load_default()
items = [
  ("BYLO: v obychnom vide tolko lug", Image.open(base + r"\v145-default-meadow.png").convert("RGB").crop((0,0,1280,300))),
  ("STALO: nebo, gory, les, lug", Image.open(base + r"\v149-default-landscape.png").convert("RGB").crop((0,0,1280,300))),
]
sheet = Image.new("RGB", (1280, sum(i[1].size[1]+34 for i in items)+8), (24,24,26))
d = ImageDraw.Draw(sheet); y = 4
for lbl, t in items:
    d.text((6,y), lbl, font=font, fill=(240,200,120)); sheet.paste(t, (0,y+28)); y += t.size[1]+34
sheet.save(base + r"\zz-bg-landscape-default.png"); print("ok")
