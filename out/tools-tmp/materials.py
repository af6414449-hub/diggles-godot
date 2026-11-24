import json, os
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
W, H = 512, 640
def load_rle(path):
    data = json.load(open(path, encoding="utf-8"))
    out = bytearray(W*H)
    idx = 0
    for value, count in data["runs"]:
        v = int(value) & 3
        for _ in range(int(count)):
            if idx >= len(out): break
            out[idx] = v
            idx += 1
    return out
mat = load_rle(os.path.join(ROOT, "native_campaign_ground_material.json"))
raw = json.load(open(os.path.join(ROOT, "native_campaign_ground_mask.json"), encoding="utf-8"))
mask = bytearray(W*H); idx = 0
for value, count in raw["runs"]:
    for _ in range(int(count)):
        if idx >= len(mask): break
        mask[idx] = int(value); idx += 1
from collections import Counter
print("материалы в сейве:", Counter(mat).most_common())
def has_ground(x, y):
    if x < 0 or y < 0 or x >= W or y >= H: return False
    return mask[y*W+x] != 0
names = {0:"камень", 1:"песок", 2:"земля", 3:"порода"}
# свободные клетки, соседние с островом
around = Counter()
for y in range(1, H-1):
    for x in range(1, W-1):
        if has_ground(x, y): continue
        neigh = any(has_ground(x+dx, y+dy) for dx,dy in ((1,0),(-1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)))
        if neigh:
            around[mat[y*W+x]] += 1
print("свободные клетки у контура острова:", {names[k]: v for k,v in around.most_common()})
# у края карты
edge = Counter()
for y in range(H):
    for x in range(W):
        if has_ground(x, y): continue
        if x < 4 or y < 4 or x >= W-4 or y >= H-4:
            edge[mat[y*W+x]] += 1
print("свободные клетки у края карты:", {names[k]: v for k,v in edge.most_common()})
# карта материала в окне старта (208,0)
print("\nкарта материала, окно старта x=195..235, y=0..14 (1=песок 2=земля 0=камень .=нет земли):")
print("    " + "".join(str((x//10)%10) for x in range(195,236)))
for y in range(0, 15):
    row = ""
    for x in range(195, 236):
        if not has_ground(x, y):
            row += "."
        else:
            row += {0:"#", 1:"s", 2:"e", 3:"r"}[mat[y*W+x]]
    print("%3d %s" % (y, row))
