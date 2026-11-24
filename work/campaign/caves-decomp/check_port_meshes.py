"""Проверка утверждений инициатора по экспорту главы (только чтение)."""
import json
import os
from collections import Counter

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
p = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")
d = json.load(open(p, encoding="utf-8"))
print("top-level keys:", list(d.keys()))
meshes = d.get("meshes")
print("meshes type:", type(meshes).__name__, "count:", len(meshes) if meshes is not None else None)
if isinstance(meshes, dict):
    items = list(meshes.items())[:2]
    print("sample mesh keys:", [k for k in meshes][:10])
    for k, v in items:
        print("  mesh", k, "->", type(v).__name__, (list(v.keys()) if isinstance(v, dict) else len(v)))
elif isinstance(meshes, list):
    print("sample:", json.dumps(meshes[0], ensure_ascii=False)[:400])

# z values per block id
zs = {}
if isinstance(meshes, dict):
    for bid, v in meshes.items():
        vals = []
        if isinstance(v, dict):
            for key in ("values", "vertices", "data"):
                if key in v:
                    vals = v[key]
                    break
        if not vals:
            continue
        zz = []
        for i in range(0, len(vals) - 4, 5):
            zz.append(float(vals[i + 2]))
        zs[int(bid)] = (min(zz), max(zz), sorted(set(zz)))
for bid in (81, 1202, 0, 71):
    if bid in zs:
        lo, hi, uniq = zs[bid]
        print(f"  block {bid}: z {lo}..{hi} distinct={uniq}")
    else:
        print(f"  block {bid}: absent")
print("blocks with z:", len(zs))
