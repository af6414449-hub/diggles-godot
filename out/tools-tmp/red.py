from PIL import Image
import numpy as np, os
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
p = os.path.join(base, "v168-redtest.png")
print("есть:", os.path.exists(p))
if os.path.exists(p):
    n = np.asarray(Image.open(p).convert("RGB")).astype(int)
    red = ((n[:,:,0] > 120) & (n[:,:,1] < 60) & (n[:,:,2] < 60)).sum()
    print("красных пикселей:", int(red))
    print("образец:", n[300,600].tolist(), n[60,600].tolist())
