import json, collections
root = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
m = json.load(open(root + r"\godot\models\native_campaign_ground_material.json", encoding="utf-8"))
total = collections.Counter()
for code, length in m["runs"]:
    total[code] += length
cells = sum(total.values())
names = {0: "stone", 1: "sand", 2: "earth", 3: "untouched rock"}
print("cells in the map: %d" % cells)
for code in sorted(total):
    print("  %-14s %7d  %5.1f %%" % (names.get(code, code), total[code], 100.0 * total[code] / cells))
print()
print("port rule (material -> family): 0/3 -> A (granite), 1 -> B (sand), 2 -> C (earth)")
for code in sorted(total):
    family = {0: "A", 3: "A", 1: "B", 2: "C"}[code]
    print("  %-14s -> family %s : %5.1f %% of the map" % (names.get(code, code), family, 100.0 * total[code] / cells))
