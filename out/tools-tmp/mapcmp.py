import json, os
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
W, H = 512, 640
def rle(path, mask=False):
    data = json.load(open(path, encoding="utf-8"))
    out = bytearray(W*H); idx = 0
    for value, count in data["runs"]:
        v = int(value) & (3 if not mask else 255)
        for _ in range(int(count)):
            if idx >= len(out): break
            out[idx] = v; idx += 1
    return out
mat = rle(os.path.join(ROOT, "native_campaign_ground_material.json"))
rock = rle(os.path.join(ROOT, "native_campaign_ground_mask.json"), mask=True)
def hv(x, y):
    h = (x*73856093) ^ (y*19349663) ^ 0x5f356495
    h = ((h ^ (h >> 13)) * 1274126177) & 0xFFFFFFFF
    if h & 0x80000000: h -= 0x100000000
    h = h ^ (h >> 16)
    if h & 0x80000000: h -= 0x100000000
    return h
def hash_edge_band(x, y):
    for dx, dy in ((-1,0),(1,0),(0,-1),(0,1),(-1,-1),(1,-1),(-1,1),(1,1)):
        if 0 <= x+dx < W and 0 <= y+dy < H and rock[(y+dy)*W+(x+dx)]:
            return (hv(x+31, y+17) % 100) < 90
    for dx, dy in ((-1,0),(1,0),(0,-1),(0,1)):
        nx, ny = x+dx, y+dy
        if nx < 0 or ny < 0 or nx >= W or ny >= H or rock[ny*W+nx] == 0:
            return (hv(x+57, y+91) % 100) < 85
    return False
# карта: материал из сейва + хеш-пояс порта
sym = {0:"#", 1:"s", 2:"e", 3:"r"}
print("ОКНО СТАРТА x=196..244, y=0..26")
print("    " + "".join(str((x//10)%10) for x in range(196,245)))
for y in range(0, 27):
    row = ""
    for x in range(196, 245):
        i = y*W+x
        if rock[i] == 0:
            row += "."
        elif hash_edge_band(x, y):
            row += "X"   # хеш-пояс порта поверх материала сейва
        else:
            row += sym[mat[i]]
    print("%3d %s" % (y, row))
print("\nX = камень по хешу порта (выдумка), # = камень из сейва, e = земля, r = порода главы, . = нет земли")
# сколько клеток хеш-пояс меняет материал
changed = 0; blocked = []
for y in range(H):
    for x in range(W):
        i = y*W+x
        if rock[i] == 0: continue
        if hash_edge_band(x, y) and mat[i] != 0:
            changed += 1
            if mat[i] == 2: blocked.append((x,y))
print("хеш-пояс меняет на камень клеток с землёй:", changed, "из них у старта:", [p for p in blocked if 190 <= p[0] <= 250 and p[1] <= 30][:30])
