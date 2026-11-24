from PIL import Image
import numpy as np, os
src = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\backdrop"
im = Image.open(os.path.join(src, "Panorama_layer_5.tga")).convert("RGBA")
a = np.asarray(im).astype(int)
h, w = a.shape[:2]
print("слой 5 (луг) %dx%d" % (w, h))
for y in range(h-8, h):
    row = a[y, ::32]
    print(y, "rgb сред", row[:,:3].mean(axis=0).round().tolist(), "alpha", row[:,3].min(), row[:,3].max())
print()
# полосы луга (как в оригинале): нижние 128 строк
bot = a[h-128:h]
print("нижние 128 строк: rgb сред", bot[:,:, :3].reshape(-1,3).mean(axis=0).round().tolist())
for frac in (0.0, 0.25, 0.5, 0.75, 1.0):
    y = h-1-int(frac*127)
    row = a[y, ::32]
    print("строка %d (%.0f%% от низа): rgb %s alpha %d" % (y, frac*100, row[:,:3].mean(axis=0).round().tolist(), row[:,3].min()))
