from PIL import Image, ImageDraw, ImageFont
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
try:
    font = ImageFont.truetype(r"C:\Windows\Fonts\arialbd.ttf", 26)
except Exception:
    font = ImageFont.load_default()
before = Image.open(base + r"\zz-v115-corridor.png").convert("RGB")
after  = Image.open(base + r"\zz-v133-corridor.png").convert("RGB")
w, h = before.size
pad = 14
sheet = Image.new("RGB", (w*2 + pad*3, h + pad + 46), (24, 24, 26))
d = ImageDraw.Draw(sheet)
d.text((pad, 12), "BYLO: poly vyRabotki chernaya", font=font, fill=(240, 200, 120))
d.text((w + pad*2, 12), "STALO: flag --lit-excavation", font=font, fill=(150, 220, 140))
sheet.paste(before, (pad, pad + 40))
sheet.paste(after, (w + pad*2, pad + 40))
sheet.save(base + r"\zz-sheet-corridor.png")
print("ok", sheet.size)

wb = Image.open(base + r"\zz-AB-base.png").convert("RGB")
wa = Image.open(base + r"\zz-AB-litex.png").convert("RGB")
w2, h2 = wb.size
sheet2 = Image.new("RGB", (w2*2 + pad*3, h2 + pad + 46), (24, 24, 26))
d2 = ImageDraw.Draw(sheet2)
d2.text((pad, 12), "SHIROKIY VID: BYLO", font=font, fill=(240, 200, 120))
d2.text((w2 + pad*2, 12), "SHIROKIY VID: STALO", font=font, fill=(150, 220, 140))
sheet2.paste(wb, (pad, pad + 40))
sheet2.paste(wa, (w2 + pad*2, pad + 40))
sheet2.save(base + r"\zz-sheet-wide.png")
print("ok2", sheet2.size)
