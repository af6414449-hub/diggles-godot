# -*- coding: utf-8 -*-
"""Программный рендер гнома вместе с настоящей киркой (spitzhacke) из данных игры.

Проверяет, как кирка садится в руку: точки кирки берутся из ассета
werkzeuge.3db::spitzhacke, положение — из сокета правой руки
(dwarf_attachments.json), ровно как в игре.

Запуск:  python render_dwarf_tool.py <clip> <frame> [out.png]
"""
import io, json, math, os, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from build_dwarf_life_page import read_tga, png_bytes, POINT_SCALE, collect

BASE = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
TEX = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\models"
W, H = 900, 700

ATT = json.load(io.open(os.path.join(BASE, "dwarf_attachments.json"), encoding="utf-8"))
MODEL = ATT["models"]["mann.3db::mann"]
TOOL = ATT["assets"]["spitzhacke"]["frames"][0]["surfaces"][0]


def sub(a, b): return (a[0] - b[0], a[1] - b[1], a[2] - b[2])
def norm(a):
    l = math.sqrt(sum(c * c for c in a))
    return (a[0] / l, a[1] / l, a[2] / l) if l > 1e-9 else (0.0, 0.0, 0.0)
def cross(a, b): return (a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0])
def dot(a, b): return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]


def socket(clip, frame, slot="0"):
    a = MODEL["clips"].get(clip)
    if not a:
        return None
    idx = frame % len(a["mesh_indices"])
    s = MODEL["meshes"][str(a["mesh_indices"][idx])]["slots"].get(slot)
    if not s:
        return None
    bc = s["basis_columns"]
    cols = [[float(bc[j][i]) for i in range(3)] for j in range(3)]
    M = [[cols[j][i] for j in range(3)] for i in range(3)]   # строки; колонки = basis_columns
    origin = [float(v) * 200.0 for v in s["origin_render"]]  # в единицы 16384-пространства тела
    return M, origin


def apply(M, origin, p):
    """Локальная точка кирки (нормализованная) -> пространство тела."""
    v = ((p[0] - 0.5) * POINT_SCALE, -(p[1] - 0.5) * POINT_SCALE, (p[2] - 0.5) * POINT_SCALE)
    return [sum(M[i][j] * v[j] for j in range(3)) + origin[i] for i in range(3)]


def main():
    clip_name = sys.argv[1] if len(sys.argv) > 1 else "werkzeug_raus_a"
    frame = int(sys.argv[2]) if len(sys.argv) > 2 else 0
    out = sys.argv[3] if len(sys.argv) > 3 else r"C:\Users\frant\Downloads\_dwarf_tool.png"

    clips = {c["name"]: c for c in collect()}
    clip = clips[clip_name]
    f = clip["frames"][frame]

    atlas = {}
    for name in ["ZMann_Koerper_unten.tga", "ZMann_Koerper_oben.tga", "ZMann_Haare.tga",
                 "ZMann_Gesicht_normal.tga", "ZMann_Augen_normal.tga"]:
        w, h, rgba = read_tga(os.path.join(TEX, name))
        atlas[name] = (w, h, rgba)
    tw, th, trgba = read_tga(os.path.join(TEX, "Metall_Werkzeuge_a_128.tga"))
    atlas["Metall_Werkzeuge_a_128.tga"] = (tw, th, trgba)

    points, uvs, tris, tex_of = [], [], [], []
    for surface in f["surfaces"]:
        base = len(points)
        for p in surface["points"]:
            points.append(((p[0] - 0.5) * POINT_SCALE, -(p[1] - 0.5) * POINT_SCALE, (p[2] - 0.5) * POINT_SCALE))
        uvs.extend(surface["uvs"])
        tris.extend([base + t for t in surface["triangles"]])
        tex_of.extend([surface["texture"]] * len(surface["points"]))

    tr = socket(clip_name, frame)
    if tr is None:
        print("нет сокета для", clip_name)
        return
    M, origin = tr
    base = len(points)
    for p, u in zip(TOOL["points"], TOOL["uvs"]):
        points.append(apply(M, origin, p))
        uvs.append(u)
    tris.extend([base + t for t in TOOL["triangles"]])
    tex_of.extend(["Metall_Werkzeuge_a_128.tga"] * len(TOOL["points"]))

    minx = min(p[0] for p in points); maxx = max(p[0] for p in points)
    miny = min(p[1] for p in points); maxy = max(p[1] for p in points)
    minz = min(p[2] for p in points); maxz = max(p[2] for p in points)
    body_only = f["surfaces"]
    bpts = [((p[0] - 0.5) * POINT_SCALE, -(p[1] - 0.5) * POINT_SCALE, (p[2] - 0.5) * POINT_SCALE)
            for s in body_only for p in s["points"]]
    feet = min(p[1] for p in bpts); head = max(p[1] for p in bpts)
    print("clip %s f%d  тело y %.1f..%.1f  кирка y %.1f..%.1f  x %.1f..%.1f  z %.1f..%.1f" % (
        clip_name, frame, feet, head, miny, maxy, minx, maxx, minz, maxz))

    center = ((minx + maxx) / 2, (miny + maxy) / 2, (minz + maxz) / 2)
    height = maxy - miny
    scale = 1.4 / height

    yaw, pitch, dist = -0.55, 0.22, 2.0
    target = (0.0, 0.6, 0.0)
    eye = (target[0] + math.sin(yaw) * math.cos(pitch) * dist,
           target[1] + math.sin(pitch) * dist,
           target[2] + math.cos(yaw) * math.cos(pitch) * dist)
    aspect = W / H
    fovy = max(0.75, 2 * math.atan(math.tan(1.02 / 2) / aspect))
    near, far = 0.02, 100.0
    fk = 1.0 / math.tan(fovy / 2.0)
    proj = [fk / aspect, 0, 0, 0,  0, fk, 0, 0,
            0, 0, (far + near) / (near - far), -1.0,
            0, 0, 2 * far * near / (near - far), 0]
    z = norm(sub(eye, target)); x = norm(cross((0.0, 1.0, 0.0), z)); y = cross(z, x)
    view = [x[0], y[0], z[0], 0,  x[1], y[1], z[1], 0,  x[2], y[2], z[2], 0,
            -dot(x, eye), -dot(y, eye), -dot(z, eye), 1]

    def mul(a, b):
        o = [0.0] * 16
        for c in range(4):
            for r in range(4):
                o[c * 4 + r] = a[r] * b[c * 4] + a[4 + r] * b[c * 4 + 1] + a[8 + r] * b[c * 4 + 2] + a[12 + r] * b[c * 4 + 3]
        return o

    vp = mul(proj, view)
    m = [scale, 0, 0, 0,  0, scale, 0, 0,  0, 0, scale, 0,
         -scale * center[0], -scale * center[1] + scale * height * 0.5, -scale * center[2], 1]
    mvp = mul(vp, m)

    def project(p):
        x, y, z = p
        cx = mvp[0] * x + mvp[4] * y + mvp[8] * z + mvp[12]
        cy = mvp[1] * x + mvp[5] * y + mvp[9] * z + mvp[13]
        cw = mvp[3] * x + mvp[7] * y + mvp[11] * z + mvp[15]
        if cw <= 1e-6:
            return None
        return (cx / cw, cy / cw, cw)

    screen = []
    for p in points:
        q = project(p)
        screen.append(None if q is None else ((q[0] * 0.5 + 0.5) * W, (0.5 - q[1] * 0.5) * H, q[2]))

    color = bytearray(W * H * 3)
    depth = [1e30] * (W * H)
    LIGHT = (-0.42, 0.84, 0.34)
    for t in range(0, len(tris), 3):
        i0, i1, i2 = tris[t], tris[t + 1], tris[t + 2]
        s0, s1, s2 = screen[i0], screen[i1], screen[i2]
        if s0 is None or s1 is None or s2 is None:
            continue
        x0, y0, z0 = s0; x1, y1, z1 = s1; x2, y2, z2 = s2
        area = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)
        if abs(area) < 1e-9:
            continue
        minx2 = max(0, int(min(x0, x1, x2))); maxx2 = min(W - 1, int(max(x0, x1, x2)) + 1)
        miny2 = max(0, int(min(y0, y1, y2))); maxy2 = min(H - 1, int(max(y0, y1, y2)) + 1)
        for py in range(miny2, maxy2 + 1):
            for px in range(minx2, maxx2 + 1):
                fx, fy = px + 0.5, py + 0.5
                w0 = ((x1 - fx) * (y2 - fy) - (x2 - fx) * (y1 - fy)) / area
                w1 = ((x2 - fx) * (y0 - fy) - (x0 - fx) * (y2 - fy)) / area
                w2 = 1.0 - w0 - w1
                if w0 < 0 or w1 < 0 or w2 < 0:
                    continue
                zc = w0 * z0 + w1 * z1 + w2 * z2
                idx = py * W + px
                if zc >= depth[idx]:
                    continue
                depth[idx] = zc
                u = w0 * uvs[i0][0] + w1 * uvs[i1][0] + w2 * uvs[i2][0]
                v = w0 * uvs[i0][1] + w1 * uvs[i1][1] + w2 * uvs[i2][1]
                tex = atlas[tex_of[i0]]
                tw2, th2, rgba = tex
                tx = min(tw2 - 1, max(0, int(u * tw2)))
                ty = min(th2 - 1, max(0, int(v * th2)))
                pi = (ty * tw2 + tx) * 4
                r, g, b, a = rgba[pi], rgba[pi + 1], rgba[pi + 2], rgba[pi + 3]
                if a < 90:
                    continue
                p0, p1, p2 = points[i0], points[i1], points[i2]
                e1 = sub(p1, p0); e2 = sub(p2, p0)
                n = norm(cross(e1, e2))
                dd = max(0.0, dot(n, norm(LIGHT)))
                lit = 0.36 + 0.64 * dd
                o = idx * 3
                color[o] = min(255, int(r * lit)); color[o + 1] = min(255, int(g * lit)); color[o + 2] = min(255, int(b * lit))

    rgba_out = bytearray(W * H * 4)
    for i in range(W * H):
        rgba_out[i * 4] = color[i * 3]; rgba_out[i * 4 + 1] = color[i * 3 + 1]
        rgba_out[i * 4 + 2] = color[i * 3 + 2]; rgba_out[i * 4 + 3] = 255
    with open(out, "wb") as fh:
        fh.write(png_bytes(W, H, bytes(rgba_out)))
    print("written", out)


if __name__ == "__main__":
    main()
