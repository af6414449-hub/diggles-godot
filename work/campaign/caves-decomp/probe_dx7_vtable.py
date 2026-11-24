#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""probe_dx7_vtable.py - reconstruct DD7/D3D7 port vtables and D3D11 API usage
   from DigglesPort.dll (read-only PE analysis + Ghidra decomp index)."""
import os, struct, sys, bisect
from pathlib import Path

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
from pe_imports_exports import PE

DLL = r"C:\diggles-ghidra\DigglesPort.dll"
IDX = r"C:\diggles-ghidra\out_port\index.tsv"
OUT = os.path.join(HERE, "probe_dx7_out.txt")

out = []
def P(*a):
    out.append(" ".join(str(x) for x in a))

pe = PE(DLL)
base = pe.image_base
P("=== PE", DLL, "image_base 0x%08X" % base)
for s in pe.sections:
    P("  section %-8s va=0x%08X vsize=0x%X raw=0x%X" % (s["name"], base + s["va"], s["vsize"], s["raw_size"]))

text = [s for s in pe.sections if s["name"].startswith(".text")][0]
td = pe.data[text["raw_ptr"]:text["raw_ptr"] + text["raw_size"]]
tva0 = base + text["va"]

funcs = []
for line in Path(IDX).read_text(encoding="utf-8", errors="replace").splitlines()[1:]:
    p = line.split("\t")
    if len(p) < 4:
        continue
    try:
        entry = int(p[1], 16)
        size = int(p[2])
    except ValueError:
        continue
    funcs.append((entry, size, p[0]))
funcs.sort()
starts = [f[0] for f in funcs]

def func_of(va):
    i = bisect.bisect_right(starts, va) - 1
    if i >= 0:
        s, sz, n = funcs[i]
        if s <= va < s + max(sz, 1):
            return n
    return "?"

def fname(va):
    i = bisect.bisect_right(starts, va) - 1
    if i >= 0:
        s, sz, n = funcs[i]
        if va == s:
            return n
        if s <= va < s + max(sz, 1):
            return "%s+%d" % (n, va - s)
    return "?"

text_lo = base + text["va"]
text_hi = text_lo + max(text["vsize"], text["raw_size"])

# ---- scan .text for RIP-relative disp32 -> target VA
refs = {}
for j in range(len(td) - 4):
    disp = struct.unpack_from("<i", td, j)[0]
    t = tva0 + (j + 4) + disp
    refs.setdefault(t, []).append(tva0 + j)

# ---- candidate vtables: runs of qwords pointing into .text
cands = []
for sec in pe.sections:
    if not sec["name"].startswith((".rdata", ".data")):
        continue
    data = pe.data[sec["raw_ptr"]:sec["raw_ptr"] + sec["raw_size"]]
    sec_va0 = base + sec["va"]
    i = 0
    while i + 8 <= len(data):
        q = struct.unpack_from("<Q", data, i)[0]
        if text_lo <= q < text_hi:
            j = i
            slots = []
            while j + 8 <= len(data):
                qq = struct.unpack_from("<Q", data, j)[0]
                if not (text_lo <= qq < text_hi):
                    break
                slots.append(qq)
                j += 8
            if len(slots) >= 4:
                cands.append((sec_va0 + i, slots))
            i = j
        else:
            i += 8

P("")
P("=== candidate vtables (rdata/data runs of .text pointers) ===")
P("total candidates:", len(cands))
for va, slots in cands:
    users = sorted(set(func_of(r) for r in refs.get(va, [])))
    P("VT 0x%08X  slots=%d  referenced_by: %s" % (va, len(slots), ", ".join(users[:8])))

KNOWN = {
    "DirectDrawCreateExPort_10009080.c": "DirectDraw7Port",
    "FUN_10017ff0_10017ff0.c": "DirectDrawSurface7Port",
    "FUN_100183c0_100183c0.c": "DirectDrawSurface7Port(dtor)",
    "FUN_100164b0_100164b0.c": "Direct3DDevice7Port",
    "FUN_100185c0_100185c0.c": "Direct3D7Port",
    "FUN_10018540_10018540.c": "DirectDrawClipperPort",
    "FUN_100165f0_100165f0.c": "Direct3DVertexBuffer7Port",
}
P("")
P("=== vtable dumps for candidates referenced by known ctors ===")
for va, slots in cands:
    users = set(func_of(r) for r in refs.get(va, []))
    tag = None
    for f, label in KNOWN.items():
        fn = f.split("_")[0] if f.startswith("FUN_") else f.split("_")[0]
        # match by function name from index
        for u in users:
            if u + ".c" == f or (u.startswith("FUN_") and f.startswith("FUN_")):
                pass
    # simple mapping by name
    hit = []
    for u in users:
        for f, label in KNOWN.items():
            base_f = f[:-2]
            if u == base_f:
                hit.append(label)
    if not hit:
        continue
    P("")
    P("--- VT 0x%08X  (%s)  slots=%d" % (va, ",".join(sorted(set(hit))), len(slots)))
    for i, s in enumerate(slots):
        P("   [%2d] 0x%08X  %s" % (i, s, fname(s)))

P("")
P("=== imports of d3d11/dxgi/d3dcompiler and their users ===")
for dll, imps in pe.imports():
    if not any(k in dll.lower() for k in ("d3d11", "dxgi", "d3dcompiler", "d3dx")):
        continue
    P("[%s] %d imports" % (dll, len(imps)))
    for nm, iat_rva in imps:
        iat_va = base + iat_rva
        users = sorted(set(func_of(r) for r in refs.get(iat_va, [])))
        P("  %-34s IAT 0x%08X  users: %s" % (nm, iat_va, ", ".join(users[:14])))

Path(OUT).write_text("\n".join(out), encoding="utf-8")
print("WROTE", OUT, len(out), "lines")
