from PIL import Image
import numpy as np, os
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
for f in ("v165-diag.png", "v149-default-landscape.png"):
    n = np.asarray(Image.open(os.path.join(base, f)).convert("RGB")).astype(int)
    warm = ((n[:,:,0] - n[:,:,2]) > 8) & (n[:,:,0] < 220)
    ys, xs = np.nonzero(warm)
    print(f, "тёплых пикселей:", len(xs), ("строки %d..%d" % (ys.min(), ys.max())) if len(ys) else "")
