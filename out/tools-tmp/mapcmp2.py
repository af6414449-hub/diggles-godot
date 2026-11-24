from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a = Image.open(base + r"\zz-mat-no-hash.png").convert("RGB").crop((180,0,340,120)).resize((640,480), Image.NEAREST)
b = Image.open(base + r"\zz-mat-with-hash.png").convert("RGB").crop((180,0,340,120)).resize((640,480), Image.NEAREST)
sheet = Image.new("RGB", (1290, 520), (20,20,20))
sheet.paste(a, (0,30)); sheet.paste(b, (650,30))
from PIL import ImageDraw, ImageFont
f = ImageFont.truetype(r"C:\Windows\Fonts\arialbd.ttf", 20)
d = ImageDraw.Draw(sheet)
d.text((6,4), "BEZ khеш-poyasa: material iz seyva", font=f, fill=(240,200,120))
d.text((656,4), "S khеш-poyasom porta", font=f, fill=(240,200,120))
sheet.save(base + r"\zz-mat-compare.png"); print("ok")
