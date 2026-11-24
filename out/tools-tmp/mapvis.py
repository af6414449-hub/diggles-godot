import json, os
from PIL import Image, ImageDraw
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
MODELS = os.path.join(ROOT, "godot", "models")
W, H = 512, 640
def rle(path, mask=False):
    data = json.load(open(path, encoding="utf-8"))
    out = bytearray(W*H); idx = 0
    for value, count in data["runs"]:
        v = int(value) & (255 if mask else 3)
        for _ in range(int(count)):
            if idx >= len(out): break
            out[idx] = v; idx += 1
    return out
rock = rle(os.path.join(MODELS, "native_campaign_ground_mask.json"), mask=True)
state = rle(os.path.join(MODELS, "native_campaign_ground_material.json"))
def hv(x, y):
    h = (x*73856093) ^ (y*19349663) ^ 0x5f356495
    h = ((h ^ (h >> 13)) * 1274126177) & 0xFFFFFFFF
    if h & 0x80000000: h -= 0x100000000
    h = h ^ (h >> 16)
    if h & 0x80000000: h -= 0x100000000
    return h
def hash_band(x, y):
    for dx, dy in ((-1,0),(1,0),(0,-1),(0,1),(-1,-1),(1,-1),(-1,1),(1,1)):
        if 0 <= x+dx < W and 0 <= y+dy < H and rock[(y+dy)*W+(x+dx)]:
            return (hv(x+31, y+17) % 100) < 90
    for dx, dy in ((-1,0),(1,0),(0,-1),(0,1)):
        nx, ny = x+dx, y+dy
        if nx < 0 or ny < 0 or nx >= W or ny >= H or rock[ny*W+nx] == 0:
            return (hv(x+57, y+91) % 100) < 85
    return False
C = {0:(120,118,112), 1:(196,176,120), 2:(110,84,58)}
def render(name, use_hash):
    im = Image.new("RGB", (W, H), (24,24,28)); d = ImageDraw.Draw(im)
    for y in range(H):
        for x in range(W):
            i = y*W+x
            if rock[i] == 0: continue
            m = state[i]
            if use_hash and m == 2 and hash_band(x, y): m = 0
            d.point((x,y), C.get(m, (200,0,200)))
    im.save(os.path.join(ROOT, "out", "campaign-shots", name))
    print("wrote", name)
render("zz-mat-no-hash.png", False)
render("zz-mat-with-hash.png", True)
