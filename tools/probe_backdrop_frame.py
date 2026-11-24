import sys
from PIL import Image

frame_path = sys.argv[1] if len(sys.argv) > 1 else r"out\backdrop-2026-11-21\d1-start.png"
matte_path = sys.argv[2] if len(sys.argv) > 2 else r"godot\textures\backdrop\campaign_panorama.png"

frame = Image.open(frame_path).convert("RGB")
matte = Image.open(matte_path).convert("RGB")
print("frame", frame.size, "matte", matte.size)

def row(img, y, xs):
    return [("%4d" % x, img.getpixel((x, y))) for x in xs]

print("\n-- frame: vertical scan at x=100, 640, 1200 --")
for y in [2, 20, 40, 60, 80, 100, 120, 140, 160, 200, 300, 400, 500, 600, 700, 718]:
    print("y=%4d  x100=%s  x640=%s  x1200=%s" % (
        y, frame.getpixel((100, y)), frame.getpixel((640, y)), frame.getpixel((1200, y))))

print("\n-- matte: vertical scan at its x=100, 1024, 2047 --")
mw, mh = matte.size
for y in [0, 20, 40, 60, 100, 150, 200, 253, 300, 400, 500, 600, 800, 1000, 1151]:
    print("y=%4d  x100=%s  x1024=%s  x2047=%s" % (
        y, matte.getpixel((100, y)), matte.getpixel((1024, y)), matte.getpixel((2047, y))))
