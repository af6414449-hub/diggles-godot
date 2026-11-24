"""Extend the Ghidra typing inputs with the map / scene layouts.

Outputs (in work/campaign/ref):
  ghidra_structs.tsv   - existing 77 classes + CMap, CMapCell, CHeightBlockArray,
                         CHeightBlock, CSceneRenderer
  ghidra_funcs.tsv     - existing 935 methods + the 0x4c render cluster (CSceneRenderer)
  ghidra_globals.tsv   - the global map pointer
"""
import io, os, re, glob

REF = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref"
DECOMP = r"C:\diggles-ghidra\out\decomp"

# ---------------------------------------------------------------- new structs
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

C_MAP_CELL = [
    (0x00, "heightBlockIndex", "int"),
    (0x04, "objectIndex", "ushort"),
    (0x08, "digMarks", "uint"),
    (0x0C, "edgeTypes", "uint"),
    (0x13, "flags", "byte"),
    (0x18, "material", "ushort"),
    (0x34, "ownerIndex", "byte[8]"),
    (0x3C, "sampleFlags", "byte[64]"),
]

C_HEIGHT_BLOCK_ARRAY = [
    (0x10, "data", "CHeightBlock *"),
    (0x14, "count", "int"),
    (0x24, "currentBlock", "int"),
]

C_HEIGHT_BLOCK = [
    (0x00, "heights", "byte[64]"),
    (0x40, "digVariants", "int[4]"),
    (0x50, "requiredNibble", "byte[4]"),
    (0x54, "cornerLevels", "byte"),
    (0x55, "tail", "byte[4]"),
]

C_SCENE_RENDERER = [
    (0x08, "textureSlots", "void *"),
    (0x410, "flags", "byte"),
    (0x40E, "maxHeight", "uint"),
    (0x40F, "minHeight", "uint"),
    (0x4BB, "blockTable", "void *"),
    (0x4BC, "blockTableCount", "int"),
    (0x4C0, "sceneId", "uint"),
    (0x4C1, "statCells", "int"),
    (0x4C2, "statCells2", "int"),
    (0x4C3, "statPlain", "int"),
    (0x4C4, "statScenery", "int"),
    (0x1024, "level", "int"),
    (0x1028, "flag1", "byte"),
    (0x1029, "flag2", "byte"),
    (0x1034, "scale", "float"),
    (0x1040, "flag3", "byte"),
    (0x1041, "textures", "void *"),
    (0x1045, "textureCount", "int"),
    (0x104C, "textureIndex", "uint[82]"),
    (0x1194, "variants", "void *"),
    (0x12DC, "defaultTexture", "uint"),
    (0x12E0, "sceneTime", "uint"),
    (0x12E4, "statA", "int"),
    (0x12E8, "statB", "int"),
    (0x12EC, "holes", "void *"),
    (0x12F0, "holeCount", "int"),
    (0x12F4, "holeCapacity", "int"),
    (0x12FC, "flag4", "byte"),
    (0x1358, "fogVertices", "void *"),
    (0x135C, "fogVertexCount", "int"),
    (0x1360, "fogIndices", "void *"),
    (0x1364, "fogIndexCount", "int"),
    (0x1368, "wallVertices", "void *"),
    (0x136C, "wallVertexCount", "int"),
    (0x1370, "wallIndices", "void *"),
    (0x1374, "wallIndexCount", "int"),
]

NEW_STRUCTS = {
    "CMap": C_MAP,
    "CMapCell": C_MAP_CELL,
    "CHeightBlockArray": C_HEIGHT_BLOCK_ARRAY,
    "CHeightBlock": C_HEIGHT_BLOCK,
    "CSceneRenderer": C_SCENE_RENDERER,
}

GLOBALS = [("0x0077241c", "CMap")]   # the global map pointer


def read_lines(path):
    with io.open(path, encoding="utf-8", errors="replace") as f:
        return f.read().split("\n")


def write_lines(path, lines):
    with io.open(path, "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(lines))


# ------------------------------------------------------- 1. extend structs.tsv
sp = os.path.join(REF, "ghidra_structs.tsv")
lines = read_lines(sp)
have = set(l.split("\t")[0] for l in lines if l.strip() and not l.startswith("class\t"))
added = 0
for cls, fields in NEW_STRUCTS.items():
    if cls in have:
        print("struct already present:", cls)
        continue
    for off, name, typ in fields:
        lines.append("\t".join([cls, hex(off), name, typ]))
        added += 1
write_lines(sp, lines)
print("ghidra_structs.tsv: +%d field rows" % added)

# --------------------------------------------- 2. find the 0x4c render cluster
MARKERS = ("0x1041", "0x1045", "0x1194", "0x1358", "0x1368", "0x4bb", "0x12dc",
           "0x12ec", "0x40f", "0x4c1")
cluster = []
for path in glob.glob(os.path.join(DECOMP, "*.c")):
    name = os.path.basename(path)
    m = re.match(r"(?:CScapeRenderer__\w+_|FUN_)([0-9a-f]{8})_\1\.c$", name)
    if not m:
        continue
    addr = m.group(1)
    if not ("004c" <= addr <= "004cff"):
        continue
    with io.open(path, encoding="utf-8", errors="replace") as f:
        txt = f.read()
    if not any(k in txt for k in MARKERS):
        continue
    if "in_ECX" not in txt and "in_ECX" not in txt:
        continue
    cluster.append(addr)

fp = os.path.join(REF, "ghidra_funcs.tsv")
lines = read_lines(fp)
have_addr = set(l.split("\t")[0].strip().lower().lstrip("0") or "0"
                for l in lines if l.strip() and not l.startswith("address\t"))
added = 0
for addr in sorted(cluster):
    if addr in have_addr:
        continue
    lines.append("\t".join(["0x" + addr, "CSceneRenderer"]))
    added += 1
write_lines(fp, lines)
print("ghidra_funcs.tsv: +%d render-cluster methods (cluster=%d)" % (added, len(cluster)))

# ------------------------------------------------------------ 3. globals.tsv
gp = os.path.join(REF, "ghidra_globals.tsv")
gl = ["global\tstruct"]
for addr, cls in GLOBALS:
    gl.append("\t".join([addr, cls]))
write_lines(gp, gl)
print("ghidra_globals.tsv:", len(GLOBALS), "global(s)")
