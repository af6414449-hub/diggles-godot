import json, os
wb = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\workbench"
tr = json.load(open(os.path.join(wb, "models", "multi_start_010_tunnel_rules.json"), encoding="utf-8"))
cells = tr["cells"]
print("facts width=%s height=%s cells=%d" % (tr.get("width"), tr.get("height"), len(cells)))
print("facts keys:", list(tr.keys())[:10])
ter = json.load(open(os.path.join(wb, "models", "multi_start_010_terrain.json"), encoding="utf-8"))
print("terrain width=%s height=%s" % (ter.get("width"), ter.get("height")))
idx = 8 * ter["width"] + 0
print("index for cell (0,8) =", idx)
if idx < len(cells):
    e = cells[idx]
    print("facts[%d] material_low=%r block=%r keys=%s" % (idx, e.get("material_low"), e.get("block"), sorted(e.keys())))
else:
    print("index out of range")
# find manifest entries around (0,8)
for c in ter["cells"]:
    if c["x"] in (0,1) and c["y"] in (7,8,9):
        print("manifest cell x=%d y=%d flags=%s block=%s" % (c["x"], c["y"], c.get("flags"), c.get("block")))
nulls = sum(1 for e in cells if e.get("material_low") is None)
print("facts cells with material_low null:", nulls)
