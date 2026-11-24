# -*- coding: utf-8 -*-
"""З9: уровень поверхности под объектами (по .pmp + BlockDB) против литерала z в шаблоне."""
import struct, os, re, sys

G = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
TPL = os.path.join(G, "Templates")

# ---------- BlockDB ----------
BDB = {}
for db in (0, 1, 2):
    p = os.path.join(G, "BlockDB%d.BDB" % db)
    if not os.path.exists(p):
        continue
    d = open(p, "rb").read()
    u32 = lambda o: struct.unpack_from("<I", d, o)[0]
    hdr = [u32(i * 4) for i in range(7)]
    N = hdr[2]
    mesh_off = 28
    block_off = mesh_off + 18 * N
    for i in range(N):
        o = block_off + i * 0x59
        g = d[o:o + 64]
        BDB.setdefault(i, (min(g), max(g)))
        # дочерние блоки
        for ch in struct.unpack_from("<4i", d, o + 0x40):
            if ch >= 0:
                pass


def pmp_parse(path):
    data = open(path, "rb").read()
    off = 0
    (w,) = struct.unpack_from("<i", data, off); off += 4
    (h,) = struct.unpack_from("<i", data, off); off += 4
    n = w * h
    shape = data[off:off + n]; off += n
    block = list(struct.unpack_from("<%di" % n, data, off)); off += 4 * n
    (cnt,) = struct.unpack_from("<i", data, off); off += 4
    rle = list(struct.unpack_from("<%dH" % cnt, data, off)); off += 2 * cnt
    extra = data[off:off + n]
    return dict(w=w, h=h, block=block, shape=shape, extra=extra)


def parse_tcl_objects(path, only_prefixes=("Dummy_Obw", "Dummy_Urw", "Dummy_Multi_Obw")):
    txt = open(path, encoding="latin-1").read()
    out = []
    for m in re.finditer(r'new\s+(\S+)\s+""\s*"\[expr \{([-\d.]+) \+ \$xoffset\}\]\s*'
                         r'\[expr \{([-\d.]+) \+ \$yoffset\}\]\s*([-\d.]+)"', txt):
        cls, x, y, z = m.group(1), float(m.group(2)), float(m.group(3)), float(m.group(4))
        if cls.startswith(only_prefixes):
            out.append((cls, x, y, z))
    return out


def report(tcl_name, pmp_name):
    tcl = os.path.join(TPL, tcl_name)
    pmp = os.path.join(TPL, pmp_name)
    if not os.path.exists(pmp):
        pmp = os.path.join(TPL, "pmp", pmp_name)
    d = pmp_parse(pmp)
    print("=" * 96)
    print("%s  <- %s   w=%d h=%d" % (tcl_name, os.path.basename(pmp), d["w"], d["h"]))
    objs = parse_tcl_objects(tcl)
    print("объектов Obw/Urw: %d" % len(objs))
    print("%-24s %8s %8s %10s | %-8s %-10s %s" %
          ("class", "x", "y", "z(level)", "cell", "block", "уровни блока"))
    for cls, x, y, z in objs:
        cx, cy = int(x), int(y)
        if 0 <= cx < d["w"] and 0 <= cy < d["h"]:
            bid = d["block"][cy * d["w"] + cx]
            lr = BDB.get(bid)
            txt = "уровни %d..%d" % lr if lr else "нет блока"
        else:
            bid, txt = None, "ВНЕ КАРТЫ"
        print("%-24s %8.3f %8.3f %10.3f | %-8s %-10s %s" %
              (cls, x, y, z, "(%d,%d)" % (cx, cy), bid, txt))


report("urw_unq_start.tcl", "unq_start.pmp")
report("obw_tutorial.tcl", "obw_tutorial.pmp")
report("obw_wettkampf.tcl", "obw_wettkampf.pmp")
report("obw_szene.tcl", "obw_szene.pmp")
