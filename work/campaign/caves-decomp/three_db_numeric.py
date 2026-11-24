"""Численный разбор .3db: mesh+0x00 = cmap index, mesh+0x04 = shadow index,
mesh+0x08 = shadow quad (4 угла vec3, y=0), AABB mesh+0x44/+0x50."""
import io
import os
import struct

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\3db"
OUT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp"

FILTER = ["urw_caves_", "cave", "gng_", "hol_"]
MAX_MESH_DUMP = 6


class R:
    def __init__(self, d):
        self.d = d
        self.p = 0

    def u8(self):
        v = self.d[self.p]
        self.p += 1
        return v

    def u16(self):
        v = struct.unpack_from("<H", self.d, self.p)[0]
        self.p += 2
        return v

    def u32(self):
        v = struct.unpack_from("<I", self.d, self.p)[0]
        self.p += 4
        return v

    def f32(self):
        v = struct.unpack_from("<f", self.d, self.p)[0]
        self.p += 4
        return v

    def s(self):
        n = self.u32()
        raw = self.d[self.p:self.p + n]
        self.p += n
        return raw.rstrip(b"\x00").decode("latin-1")


def parse(path):
    with open(path, "rb") as f:
        d = f.read()
    r = R(d)
    version = r.s()
    package = r.s()
    mat_count = r.u16()
    materials = []
    for _ in range(mat_count):
        name = r.s()
        path_ = r.s()
        val = r.u32()
        materials.append((name, path_, val))
    mesh_count = r.u32()
    meshes = []
    for _ in range(mesh_count):
        n_links = r.u16()
        links = []
        for _ in range(n_links):
            links.append(tuple(r.u16() for _ in range(6)))
        aabb1 = [r.f32() for _ in range(3)]
        aabb2 = [r.f32() for _ in range(3)]
        attach = [r.u32() for _ in range(32)]
        shadow_idx = r.u16()
        quad = [r.f32() for _ in range(12)]
        cmap_idx = r.u16()
        meshes.append(dict(n=n_links, links=links, aabb=(aabb1, aabb2),
                           attach=attach, shadow=shadow_idx, quad=quad, cmap=cmap_idx))
    return dict(version=version, package=package, materials=materials, meshes=meshes, size=len(d), pos=r.p)


def fmt_quad(q):
    pts = []
    for i in range(4):
        x, y, z = q[i * 3], q[i * 3 + 1], q[i * 3 + 2]
        pts.append("(%.2f, %.2f, %.2f)" % (x, y, z))
    return "  ".join(pts)


def dump(path, out):
    name = os.path.basename(path)
    try:
        info = parse(path)
    except Exception as e:
        out.append("=== %s: ОШИБКА РАЗБОРА: %s" % (name, e))
        return
    out.append("=== %s (%d B) версия=%r пакет=%r  материалов=%d  мешей=%d"
               % (name, info["size"], info["version"], info["package"],
                  len(info["materials"]), len(info["meshes"])))
    picks = []
    for i, m in enumerate(info["meshes"]):
        lbl = "mesh%d" % i
        picks.append((i, lbl, m))
    shown = 0
    for i, lbl, m in picks:
        if shown >= MAX_MESH_DUMP:
            break
        out.append("  %s: links=%d cmap=%d shadow=%d" % (lbl, m["n"], m["cmap"], m["shadow"]))
        out.append("      AABB1=%s" % (["%.2f" % v for v in m["aabb"][0]],))
        out.append("      AABB2=%s" % (["%.2f" % v for v in m["aabb"][1]],))
        out.append("      shadowQuad: %s" % fmt_quad(m["quad"]))
        out.append("      attach[0..7]=%s" % (m["attach"][:8],))
        shown += 1
    out.append("")


out = []
out.append("Численный разбор .3db: cmap/shadow индексы и shadow-quad")
out.append("")

files = ["auskleidung.3db", "mann.3db", "transport.3db"]
for fn in files:
    p = os.path.join(GAME, fn)
    if os.path.isfile(p):
        dump(p, out)

# сводка по всем файлам: сколько мешей с тенью (shadow != 0xFFFF) и с cmap
out.append("=== Сводка по всем 43 файлам ===")
tot = 0
with_shadow = 0
with_cmap = 0
per_file = []
for fn in sorted(os.listdir(GAME)):
    if not fn.lower().endswith(".3db"):
        continue
    try:
        info = parse(os.path.join(GAME, fn))
    except Exception as e:
        per_file.append("%s: ОШИБКА %s" % (fn, e))
        continue
    ms = info["meshes"]
    s = sum(1 for m in ms if m["shadow"] != 0xFFFF)
    c = sum(1 for m in ms if m["cmap"] != 0xFFFF)
    tot += len(ms)
    with_shadow += s
    with_cmap += c
    per_file.append("%-22s мешей=%5d  с тенью=%5d  с cmap=%5d" % (fn, len(ms), s, c))
out.extend(per_file)
out.append("ИТОГО мешей=%d, из них с тенью=%d, с cmap=%d" % (tot, with_shadow, with_cmap))

txt = "\n".join(out)
with io.open(os.path.join(OUT, "3db_numeric_probe.txt"), "w", encoding="utf-8", newline="\n") as f:
    f.write(txt)
print(txt[:5000])
