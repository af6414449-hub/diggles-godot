from PIL import Image
import numpy as np
p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\ground\Gnd_C01.tga"
im = Image.open(p)
print("size", im.size, "mode", im.mode)
a = np.asarray(im.convert("RGBA"))
print("alpha min/max", a[:,:,3].min(), a[:,:,3].max())
print("rgb mean", a[:,:,:3].reshape(-1,3).mean(axis=0))
for y in (0, 16, 32, 48):
    print(y, [a[y,x].tolist() for x in (0, 16, 32, 48)])
