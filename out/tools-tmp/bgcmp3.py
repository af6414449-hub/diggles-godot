from PIL import Image, ImageDraw, ImageFont
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
try:
    font = ImageFont.truetype(r"C:\Windows\Fonts\arialbd.ttf", 22)
except Exception:
    font = ImageFont.load_default()
def sheet(items, out, w, h):
    s = Image.new("RGB", (w, len(items)*(h+34)+8), (24,24,26))
    d = ImageDraw.Draw(s); y = 4
    for label, img in items:
        d.text((6, y), label, font=font, fill=(240,200,120))
        s.paste(img, (0, y+28)); y += h+34
    s.save(base + "\\" + out); print("ok", out)
items = [("BYLO: mylo za derev'yami", Image.open(base + r"\v143-default-final.png").convert("RGB").crop((0,0,900,330))),
         ("STALO: lug originala, yarkiy", Image.open(base + r"\v145-default-meadow.png").convert("RGB").crop((0,0,900,330)))]
sheet(items, "zz-bg-compare-meadow.png", 900, 330)
