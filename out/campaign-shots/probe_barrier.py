import json

root = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot"
msk = json.load(open(root + r"\models\native_campaign_ground_mask.json", encoding="utf-8"))


def expand(doc):
    out = bytearray()
    for v, c in doc["runs"]:
        out.extend([v] * c)
    return out


K = expand(msk)
W, H = 512, 640
ch = json.load(open(root + r"\models\native_campaign_chapter.json", encoding="utf-8"))
cells = set()
for e in ch["cells"]:
    cells.add((int(e["x"]), int(e["y"])))
xs = [c[0] for c in cells]
ys = [c[1] for c in cells]
print("chapter cells", len(cells), "x", min(xs), max(xs), "y", min(ys), max(ys))

bar = []
for (x, y) in cells:
    for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        nx, ny = x + dx, y + dy
        if 0 <= nx < W and 0 <= ny < H and K[ny * W + nx] == 0:
            bar.append((nx, ny))
bar = sorted(set(bar))
bx = [b[0] for b in bar]
by = [b[1] for b in bar]
print("barrier cells next to chapter:", len(bar))
print("barrier bbox x", min(bx), max(bx), "y", min(by), max(by))
print("first barrier cells:", bar[:8])
print("chapter cells sample:", sorted(cells)[:8])
