from PIL import Image, ImageChops, ImageEnhance
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a = Image.open(base + r"\v135-wide-base.png").convert("RGB")
b = Image.open(base + r"\v134-wide-litex.png").convert("RGB")
d = ImageChops.difference(a,b)
d = ImageEnhance.Brightness(d).enhance(6)
d.crop((370,400,900,620)).resize((1060,440), Image.LANCZOS).save(base + r"\zz-AB-diff.png")
# профиль поперёк вертикальной шахты справа внизу
n = np.asarray(b).astype(int); m = np.asarray(a).astype(int)
print("профиль поперёк шахты, строка 560:")
for x in range(700, 760):
    print(x, m[560,x].tolist(), n[560,x].tolist())
