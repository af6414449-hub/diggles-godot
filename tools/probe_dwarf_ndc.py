# -*- coding: utf-8 -*-
"""
Диагностика WebGL-пути страницы dwarf_life.html.

Разбирает бинарный блок клипов из собранной страницы и считает NDC-габарит
модели тем же кодом матриц, что и в шаблоне, для двух вариантов чтения
центра (как в текущем шаблоне и как «правильный»).

Запуск:  python tools\probe_dwarf_ndc.py
"""
import base64, io, math, os, re, struct

PAGE = r"C:\Users\frant\Downloads\dwarf_life.html"


def load_binary():
    html = io.open(PAGE, encoding="utf-8").read()
    m = re.search(r'const CLIPS_B64 = "([A-Za-z0-9+/=]+)";', html)
    if not m:
        raise SystemExit("CLIPS_B64 not found")
    return base64.b64decode(m.group(1))


def parse(raw):
    """Разбор блока в формате версии 2 (совпадает с шаблоном)."""
    off = 4
    version, clip_count = struct.unpack_from("<II", raw, off); off += 8
    clips = {}
    for _ in range(clip_count):
        nlen = struct.unpack_from("<I", raw, off)[0]; off += 4
        name = raw[off:off + nlen].decode("utf-8"); off += nlen
        frame_count, surface_count = struct.unpack_from("<II", raw, off); off += 8
        fps, scale = struct.unpack_from("<ff", raw, off); off += 8
        # «как в шаблоне»: три чтения с одного смещения
        center_bug = [struct.unpack_from("<f", raw, off)[0]] * 3
        # «как должно быть»: три последовательных float32
        center_ok = list(struct.unpack_from("<fff", raw, off))
        off += 12
        height = struct.unpack_from("<f", raw, off)[0]; off += 4
        surfaces = []
        for _s in range(surface_count):
            pc, ic = struct.unpack_from("<II", raw, off); off += 8
            texture_index = raw[off]; off += 1
            indices = struct.unpack_from("<%dH" % ic, raw, off); off += 2 * ic
            surfaces.append(dict(pc=pc, ic=ic, ti=texture_index, indices=indices))
        frames = []
        for _f in range(frame_count):
            per_surface = []
            for s in surfaces:
                pos = struct.unpack_from("<%dh" % (s["pc"] * 3), raw, off); off += 2 * s["pc"] * 3
                uv = struct.unpack_from("<%dh" % (s["pc"] * 2), raw, off); off += 2 * s["pc"] * 2
                bright = raw[off:off + s["pc"]]; off += s["pc"]
                per_surface.append(dict(pos=pos, uv=uv, bright=bright))
            frames.append(per_surface)
        clips[name] = dict(fps=fps, scale=scale, center_bug=center_bug, center_ok=center_ok,
                           height=height, surfaces=surfaces, frames=frames)
    return version, clips


def mat4_multiply(a, b):
    """Как mat4Multiply в шаблоне: колонко-большинственный массив."""
    o = [0.0] * 16
    for c in range(4):
        for r in range(4):
            o[c * 4 + r] = (a[r] * b[c * 4] + a[4 + r] * b[c * 4 + 1] +
                            a[8 + r] * b[c * 4 + 2] + a[12 + r] * b[c * 4 + 3])
    return o


def perspective(fovy, aspect, near, far):
    f = 1.0 / math.tan(fovy / 2.0)
    o = [0.0] * 16
    o[0] = f / aspect
    o[5] = f
    o[10] = (far + near) / (near - far)
    o[11] = -1.0
    o[14] = 2.0 * far * near / (far - near)
    return o


def look_at(eye, center, up):
    def sub(a, b): return [a[i] - b[i] for i in range(3)]
    def cross(a, b): return [a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]]
    def dot(a, b): return sum(a[i] * b[i] for i in range(3))
    def norm(a):
        l = math.sqrt(dot(a, a))
        return [v / l for v in a] if l > 1e-9 else [0.0, 0.0, 0.0]
    z = norm(sub(eye, center))
    x = norm(cross(up, z))
    y = cross(z, x)
    o = [0.0] * 16
    o[0] = x[0]; o[4] = x[1]; o[8] = x[2]; o[12] = -dot(x, eye)
    o[1] = y[0]; o[5] = y[1]; o[9] = y[2]; o[13] = -dot(y, eye)
    o[2] = z[0]; o[6] = z[1]; o[10] = z[2]; o[14] = -dot(z, eye)
    o[15] = 1.0
    return o


def dwarf_matrix(pos, heading, scale, center, height):
    c, s = math.cos(heading), math.sin(heading)
    m = [0.0] * 16
    m[0] = c * scale; m[2] = -s * scale
    m[5] = scale
    m[8] = s * scale; m[10] = c * scale
    ax = c * scale * center[0] + s * scale * center[2]
    ay = scale * center[1]
    az = -s * scale * center[0] + c * scale * center[2]
    m[12] = pos[0] - ax
    m[13] = pos[1] - ay + scale * height * 0.5
    m[14] = pos[2] - az
    m[15] = 1.0
    return m


def ndc_bounds(clip, frame_index, center, width=1600, height=900, strip=144):
    yaw, pitch, distance = -0.55, 0.22, 2.35
    target = (0.0, 0.52, 0.0)
    eye = (target[0] + math.sin(yaw) * math.cos(pitch) * distance,
           target[1] + math.sin(pitch) * distance,
           target[2] + math.cos(yaw) * math.cos(pitch) * distance)
    aspect = width / height
    fovy = max(0.75, 2 * math.atan(math.tan(1.02 / 2) / aspect))
    proj = perspective(fovy, aspect, 0.02, 100.0)
    proj[9] = -strip / height
    view = look_at(eye, target, (0.0, 1.0, 0.0))
    vp = mat4_multiply(proj, view)
    model = dwarf_matrix((0.0, 0.0, 0.0), 0.0, clip["scale"], center, clip["height"])
    mvp = mat4_multiply(vp, model)

    xs, ys, zs, front, behind = [], [], [], 0, 0
    for surface in clip["surfaces"]:
        pos = clip["frames"][frame_index][clip["surfaces"].index(surface)]["pos"]
        for i in range(0, len(pos), 3):
            x, y, z = pos[i], pos[i + 1], pos[i + 2]
            w = mvp[3] * x + mvp[7] * y + mvp[11] * z + mvp[15]
            if w <= 1e-6:
                behind += 1
                continue
            front += 1
            xs.append((mvp[0] * x + mvp[4] * y + mvp[8] * z + mvp[12]) / w)
            ys.append((mvp[1] * x + mvp[5] * y + mvp[9] * z + mvp[13]) / w)
            zs.append(w)
    if not xs:
        return None
    return dict(xmin=min(xs), xmax=max(xs), ymin=min(ys), ymax=max(ys),
                zmin=min(zs), zmax=max(zs), front=front, behind=behind)


def main():
    raw = load_binary()
    version, clips = parse(raw)
    print("version", version, "clips", len(clips), "bytes", len(raw))
    for name in ["stand_anim_a", "gehen_start", "buddeln_oben_normal", "schlafen_boden_loop"]:
        clip = clips.get(name)
        if not clip:
            continue
        print("\n=== %s ===" % name)
        print("  scale %.6g  height %.4g" % (clip["scale"], clip["height"]))
        print("  center as-read [%.4g %.4g %.4g]" % tuple(clip["center_bug"]))
        print("  center correct  [%.4g %.4g %.4g]" % tuple(clip["center_ok"]))
        for label, center in (("as-read ", clip["center_bug"]), ("correct ", clip["center_ok"])):
            b = ndc_bounds(clip, 0, center)
            if b is None:
                print("  %s -> все вершины за камерой" % label)
                continue
            print("  %s -> NDC x[%.3f..%.3f] y[%.3f..%.3f] w[%.3f..%.3f] front=%d behind=%d" % (
                label, b["xmin"], b["xmax"], b["ymin"], b["ymax"], b["zmin"], b["zmax"],
                b["front"], b["behind"]))


if __name__ == "__main__":
    main()
