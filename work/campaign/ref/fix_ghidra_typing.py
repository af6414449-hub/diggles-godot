"""Fix pass: replace the stale CMap rows and re-detect the render cluster."""
import io, os, re, glob

REF = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref"
DECOMP = r"C:\diggles-ghidra\out\decomp"

C_MAP = [
    (0x14, "cells", "CMapCell *"),
    (0x18, "cellCount", "int"),
    (0x20, "ownerBlocks", "void *"),
    (0x24, "heightBlocks", "CHeightBlockArray *"),
    (0x29, "mapFlags", "ushort"),
    (0x38, "mapWidth8", "int"),
    (0x3C, "mapHeight8", "int"),
    (0x40, "mapArea8", "int"),
    (0x44, "mapWidth", "int"),
    (0x48, "mapHeight", "int"),
    (0x4C, "cellCountTotal", "int"),
    (0x70, "scanlineTotal", "int"),
    (0x74, "originX", "int"),
    (0x78, "originY", "int"),
    (0x7C, "originX8", "int"),
    (0x80, "originY8", "int"),
    (0x84, "cellX0", "int"),
    (0x88, "cellY0", "int"),
    (0x8C, "cellX1", "int"),
    (0x90, "cellY1", "int"),
    (0x94, "x0_8", "int"),
    (0x98, "y0_8", "int"),
    (0x9C, "x1_8", "int"),
    (0xA0, "y1_8", "int"),
    (0xA4, "x0f", "float"),
    (0xA8, "y0f", "float"),
    (0xAC, "x1f", "float"),
    (0xB0, "y1f", "float"),
    (0xB4, "x0_8f", "float"),
    (0xB8, "y0_8f", "float"),
    (0xBC, "x1_8f", "float"),
    (0xC0, "y1_8f", "float"),
]


def read(path):
    with io.open(path, encoding="utf-8", errors="replace") as f:
        return f.read().split("\n")


def write(path, lines):
    with io.open(path, "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(lines))


# ------------------------------------------------- 1. replace the CMap rows
sp = os.path.join(REF, "ghidra_structs.tsv")
lines = read(sp)
kept = []
for l in lines:
    if l.startswith("CMap\t"):
        continue
    kept.append(l)
while kept and kept[-1].strip() == "":
    kept.pop()
for off, name, typ in C_MAP:
    kept.append("\t".join(["CMap", hex(off), name, typ]))
write(sp, kept)
print("ghidra_structs.tsv: CMap replaced, %d rows" % len(C_MAP))

# --------------------------------- 2. render cluster (numeric address range)
MARKERS = ("0x1041", "0x1045", "0x1194", "0x1358", "0x1368", "0x4bb", "0x12dc",
           "0x12ec", "0x40f", "0x4c1", "0x4c4")
cluster = []
for path in glob.glob(os.path.join(DECOMP, "*.c")):
    name = os.path.basename(path)
    m = re.match(r"(?:CScapeRenderer__\w+_|FUN_)([0-9a-f]{8})_\1\.c$", name)
    if not m:
        continue
    addr = int(m.group(1), 16)
    if not (0x4C0000 <= addr < 0x4D0000):
        continue
    with io.open(path, encoding="utf-8", errors="replace") as f:
        txt = f.read()
    if "in_ECX" not in txt:
        continue
    if not any(k in txt for k in MARKERS):
        continue
    cluster.append("%08x" % addr)

fp = os.path.join(REF, "ghidra_funcs.tsv")
lines = read(fp)
have = set()
for l in lines:
    if l.strip() and not l.startswith("address\t"):
        have.add(l.split("\t")[0].strip().lower().lstrip("0") or "0")
added = 0
for addr in sorted(cluster):
    if addr in have:
        continue
    lines.append("\t".join(["0x" + addr, "CSceneRenderer"]))
    added += 1
while lines and lines[-1].strip() == "":
    lines.pop()
write(fp, lines)
print("ghidra_funcs.tsv: +%d render-cluster methods (cluster=%d)" % (added, len(cluster)))

# --------------------------------------------------------------- 3. verify
import collections
cnt = collections.Counter()
for l in read(sp):
    if l.strip() and not l.startswith("class\t"):
        cnt[l.split("\t")[0]] += 1
print("struct classes:", len(cnt), "fields:", sum(cnt.values()))
for k in ("CMap", "CMapCell", "CHeightBlockArray", "CHeightBlock", "CSceneRenderer"):
    print("   %-20s %d fields" % (k, cnt.get(k, 0)))
fc = collections.Counter()
for l in read(fp):
    if l.strip() and not l.startswith("address\t"):
        fc[l.split("\t")[1]] += 1
print("func classes:", len(fc), "funcs:", sum(fc.values()))
