from PIL import Image, ImageDraw, ImageFont
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
font = ImageFont.truetype(r"C:\Windows\Fonts\arialbd.ttf", 20)
items = [
  ("ORIGINAL: fon boevoi sceny", Image.open(r"C:\Users\frant\.minimax\v2\assets\2026\11\23\03-08-57-084-asset_20261123-030857-084_f2a8dbbb02f2_0418b33e-image.png").convert("RGB").crop((0,0,1247,300)).resize((1280,308), Image.LANCZOS)),
  ("PORT do: polosy-kartinka (otkloneno)", Image.open(base + r"\v173-final-default.png").convert("RGB").crop((0,0,1280,300))),
  ("PORT seychas: kolca zemli vokrug igroka", Image.open(base + r"\v175-rings-default.png").convert("RGB").crop((0,0,1280,300))),
]
sheet = Image.new("RGB", (1280, sum(i[1].size[1]+34 for i in items)+8), (24,24,26))
d = ImageDraw.Draw(sheet); y = 4
for lbl, t in items:
    d.text((6,y), lbl, font=font, fill=(240,200,120)); sheet.paste(t, (0,y+28)); y += t.size[1]+34
sheet.save(base + r"\zz-bg-rings-vs-bands.png")
print("ok")
