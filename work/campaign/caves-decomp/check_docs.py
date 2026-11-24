"""Проверка целостности документов зоны: размеры, U+FFFD, наличие ключевых маркеров."""
import io
import os

Z = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp"

MARKERS = {
    "report.md": ["## З1.", "## З12.", "## З16.", "## З17.", "## З18."],
    "z10-cell-fow-and-subcell-map.md": ["# З10", "Дополнение (2026-11-21): семантика параметра"],
    "z12-quadrants.md": ["NW"],
    "z13-heightmap-and-subcell-map.md": ["FUN_005a6b40"],
    "z15-3db-format.md": ["3db"],
    "z16-verify-beautifier.md": ["99.99"],
}

total_bad = 0
for name in sorted(os.listdir(Z)):
    if not name.endswith(".md"):
        continue
    p = os.path.join(Z, name)
    with io.open(p, "r", encoding="utf-8") as f:
        t = f.read()
    bad = t.count(u"\ufffd")
    total_bad += bad
    mark = ""
    for m in MARKERS.get(name, []):
        mark += ("+" if m in t else "-") + m + " "
    print(f"{name:42s} {os.path.getsize(p):7d} B  {len(t):7d} sym  FFFD={bad}  {mark}")

print()
print("ИТОГО U+FFFD:", total_bad)
