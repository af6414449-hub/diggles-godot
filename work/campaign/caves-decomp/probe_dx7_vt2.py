import os, struct, sys, bisect
from pathlib import Path
HERE = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, HERE)
from pe_imports_exports import PE

pe = PE(r"C:\diggles-ghidra\DigglesPort.dll")
base = pe.image_base
print("magic 0x%X (0x10B=PE32, 0x20B=PE32+)" % pe.magic)
text = [s for s in pe.sections if s["name"].startswith(".text")][0]
tlo = base + text["va"]; thi = tlo + max(text["vsize"], text["raw_size"])

funcs = []
for line in Path(r"C:\diggles-ghidra\out_port\index.tsv").read_text(encoding="utf-8", errors="replace").splitlines()[1:]:
    p = line.split("\t")
    if len(p) < 4: continue
    try: entry = int(p[1], 16); size = int(p[2])
    except ValueError: continue
    funcs.append((entry, size, p[0]))
funcs.sort(); starts = [f[0] for f in funcs]
def fname(va):
    i = bisect.bisect_right(starts, va) - 1
    if i >= 0:
        s, sz, n = funcs[i]
        if va == s: return n
        if s <= va < s + max(sz, 1): return "%s+%d" % (n, va - s)
    return "??"

rdata = [s for s in pe.sections if s["name"].startswith(".rdata")][0]
rd = pe.data[rdata["raw_ptr"]:rdata["raw_ptr"] + rdata["raw_size"]]
rdva = base + rdata["va"]

# vtable candidates: runs of 4-byte code pointers
cands = []
i = 0
while i + 4 <= len(rd):
    v = struct.unpack_from("<I", rd, i)[0]
    if tlo <= v < thi:
        j = i; slots = []
        while j + 4 <= len(rd):
            vv = struct.unpack_from("<I", rd, j)[0]
            if not (tlo <= vv < thi): break
            slots.append(vv); j += 4
        if len(slots) >= 8:
            cands.append((rdva + i, slots))
        i = j
    else:
        i += 4

# find referrers: scan .text for 4-byte immediates pointing at candidate addrs
td = pe.data[text["raw_ptr"]:text["raw_ptr"] + text["raw_size"]]
tva0 = base + text["va"]
want = {c[0] for c in cands}
refmap = {w: [] for w in want}
for j in range(len(td) - 4):
    v = struct.unpack_from("<I", td, j)[0]
    if v in refmap:
        refmap[v].append(tva0 + j)

def func_of(va):
    i = bisect.bisect_right(starts, va) - 1
    if i >= 0:
        s, sz, n = funcs[i]
        if s <= va < s + max(sz, 1): return n
    return "??"

print("\n=== vtable candidates in .rdata ===")
for va, slots in cands:
    users = sorted(set(func_of(r) for r in refmap[va]))
    print("VT 0x%08X slots=%3d  refs: %s" % (va, len(slots), ", ".join(users[:10])))

out = []
for va, slots in cands:
    users = sorted(set(func_of(r) for r in refmap[va]))
    out.append("")
    out.append("=== VT 0x%08X  slots=%d  refs: %s" % (va, len(slots), ", ".join(users[:10])))
    for k, s in enumerate(slots):
        out.append("  [%2d] 0x%08X  %s" % (k, s, fname(s)))
Path(os.path.join(HERE, "probe_dx7_vt2.txt")).write_text("\n".join(out), encoding="utf-8")
print("\nwrote probe_dx7_vt2.txt")
