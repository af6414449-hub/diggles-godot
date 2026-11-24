"""Сверка: раскладка пещер в портовой главе против формулы Campaign.tcl::first_level."""
import io
import json
import os

PORT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models\native_campaign_chapter.json"
OUT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp"

with io.open(PORT, "r", encoding="utf-8") as f:
    d = json.load(f)

lines = []
lines.append("КЛЮЧИ: " + ", ".join(sorted(d.keys())))
lines.append("")
lines.append("initial_view = %r" % (d.get("initial_view"),))
lines.append("map_size = %r" % (d.get("map_size"),))
lines.append("source = %r" % (d.get("source"),))
lines.append("")

lines.append("=== placements (%d) ===" % len(d.get("placements", [])))
for p in d.get("placements", []):
    lines.append("  " + json.dumps(p, ensure_ascii=False))

lines.append("")
lines.append("=== story_placements (%d) ===" % len(d.get("story_placements", [])))
for p in d.get("story_placements", []):
    lines.append("  " + json.dumps(p, ensure_ascii=False))

lines.append("")
tpl = d.get("templates", [])
lines.append("=== templates (%d) ===" % len(tpl))
for t in tpl:
    if isinstance(t, dict):
        lines.append("  " + json.dumps(t, ensure_ascii=False)[:300])
    else:
        lines.append("  " + repr(t)[:300])

# сверка с формулой оригинала: std = start + (36, 40), start = (208, 0) => std = (244, 40)
STD = (244, 40)
lines.append("")
lines.append("=== сверка с формулой оригинала (std = (244, 40)) ===")
for p in d.get("placements", []):
    x = p.get("x")
    y = p.get("y")
    if x is None or y is None:
        continue
    dx = x - STD[0]
    dy = y - STD[1]
    lines.append("  %-28s (%s, %s)  →  (std_x%+d, std_y%+d)"
                 % (p.get("name") or p.get("template") or "?", x, y, dx, dy))

txt = "\n".join(lines)
with io.open(os.path.join(OUT, "port_placements_check.txt"), "w", encoding="utf-8", newline="\n") as f:
    f.write(txt)
print(txt[:6000])
