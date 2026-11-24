import sys
from PIL import Image

path = sys.argv[1] if len(sys.argv) > 1 else r"out\backdrop-2026-11-21\e2-native-view.png"
img = Image.open(path).convert("RGB")
w, h = img.size
print("frame", img.size)

SKY = (215, 230, 252)
GROUND = (105, 108, 19)

def close(px, ref, tol=12):
    return all(abs(px[i] - ref[i]) <= tol for i in range(3))

for x in (60, 300, 640, 1000, 1220):
    sky_rows, ground_rows, other = [], [], []
    for y in range(0, h):
        px = img.getpixel((x, y))
        if close(px, SKY):
            sky_rows.append(y)
        elif close(px, GROUND):
            ground_rows.append(y)
        elif y < 320:
            other.append((y, px))
    def span(rows):
        if not rows:
            return None
        return (rows[0], rows[-1], len(rows))
    print("x=%4d  sky=%s  ground=%s" % (x, span(sky_rows), span(ground_rows)))
    if other and x == 640:
        print("   other rows above 320:", other[:6], "...", other[-4:])
