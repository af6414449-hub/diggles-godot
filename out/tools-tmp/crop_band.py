from PIL import Image
p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots\v112-wide.png"
im = Image.open(p).convert("RGB")
c = im.crop((390, 400, 730, 590)).resize((340*3, 190*3), Image.NEAREST)
c.save(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots\zz-band-crop.png")
print("ok", c.size)
