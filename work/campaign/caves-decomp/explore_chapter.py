"""Разведка структуры native_campaign_chapter.json: templates, cells, покрытие."""
import json
import os
from collections import Counter

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
p = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")
d = json.load(open(p, encoding="utf-8"))
print("map_size:", d.get("map_size"))
print("source:", d.get("source"))
tpl = d.get("templates")
print("templates type:", type(tpl).__name__, "n:", len(tpl))
if isinstance(tpl, list):
    for t in tpl[:4]:
        print("  ", json.dumps(t, ensure_ascii=False)[:300])
    keys = Counter()
    for t in tpl:
        if isinstance(t, dict):
            keys.update(t.keys())
    print("  template keys:", dict(keys))
    if isinstance(tpl, list) and tpl and isinstance(tpl[0], dict):
        t0 = tpl[0]
        for k, v in t0.items():
            if isinstance(v, list):
                print(f"   {k}: list[{len(v)}] sample={json.dumps(v[:2], ensure_ascii=False)[:200]}")
            elif isinstance(v, dict):
                print(f"   {k}: dict[{len(v)}] sample={json.dumps(list(v.items())[:2], ensure_ascii=False)[:200]}")
            else:
                print(f"   {k}: {v!r}")
cells = d.get("cells")
print("cells type:", type(cells).__name__, "n:", len(cells) if cells is not None else None)
if isinstance(cells, list) and cells:
    print("  cell sample:", json.dumps(cells[0], ensure_ascii=False)[:300])
    print("  cell keys:", Counter(k for c in cells[:1000] if isinstance(c, dict) for k in c.keys()))
    xs = [c["x"] for c in cells if isinstance(c, dict) and "x" in c]
    ys = [c["y"] for c in cells if isinstance(c, dict) and "y" in c]
    if xs:
        print("  x range:", min(xs), max(xs), " y range:", min(ys), max(ys))
        print("  distinct blocks:", len(set(c.get("block") for c in cells if isinstance(c, dict))))
        print("  block id histogram (top10):", Counter(c.get("block") for c in cells if isinstance(c, dict)).most_common(10))
print("summary:", json.dumps(d.get("summary"), ensure_ascii=False)[:600])
