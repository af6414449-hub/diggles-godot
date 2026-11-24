from PIL import Image, ImageDraw, ImageFont
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
try:
    font = ImageFont.truetype(r"C:\Windows\Fonts\arialbd.ttf", 22)
except Exception:
    font = ImageFont.load_default()
def sheet(items, out, w, h):
    sheet = Image.new("RGB", (w, len(items)*(h+34)+8), (24,24,26))
    d = ImageDraw.Draw(sheet)
    y = 4
    for label, img in items:
        d.text((6, y), label, font=font, fill=(240,200,120))
        sheet.paste(img, (0, y+28))
        y += h+34
    sheet.save(base + "\\" + out)
    print("ok", out)
items1 = [("BYLO: obtyanuty matka (srez 30%, lug rastyanut 6.5x)", Image.open(base + r"\v141-default-view.png").convert("RGB").crop((0,0,640,300))),
          ("STALO: polnaya panorama, 6 sloev, zemlya kartoy", Image.open(base + r"\v143-default-final.png").convert("RGB").crop((0,0,640,300)))]
sheet(items1, "zz-bg-compare-default.png", 640, 300)
items2 = [("BYLO: shirokiy vid", Image.open(base + r"\v137-wide-default.png").convert("RGB").crop((0,0,1280,200))),
          ("STALO: shirokiy vid", Image.open(base + r"\v142-wide-final.png").convert("RGB").crop((0,0,1280,200)))]
sheet(items2, "zz-bg-compare-wide2.png", 1280, 200)
