from PIL import Image
import os
d = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
for n in sorted(os.listdir(d)):
    if n.startswith("owner-") or n.startswith("v98-nw") or n.startswith("v97-start"):
        p = os.path.join(d, n)
        try:
            im = Image.open(p)
            print("%-32s %s" % (n, im.size))
        except Exception as e:
            print(n, "ERR", e)
