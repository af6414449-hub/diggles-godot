from PIL import Image
import numpy as np
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
a = np.asarray(Image.open(base + r"\zz-matte-final-installed.png").convert("RGB")).astype(int)
b = np.asarray(Image.open(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\backdrop\campaign_panorama.png").convert("RGB")).astype(int)
print("размеры", a.shape, b.shape)
d = np.abs(a-b).sum(axis=2)
print("различающихся пикселей:", int((d>6).sum()))
