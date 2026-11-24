# -*- coding: utf-8 -*-
"""
Полная сверка бинарного блока dwarf_life.html с исходными моделями проекта.

Декодирует блок ровно как шаблон страницы и сравнивает:
  * геометрию (позиции, uv, brightness) каждого кадра каждой поверхности;
  * индексы треугольников;
  * проверяет, что индексы в диапазоне pointCount и треугольники не вырождены.

Запуск:  python tools\verify_dwarf_binary_full.py
"""
import base64, collections, io, json, math, os, re, struct, sys

PROJECT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
MODELS = os.path.join(PROJECT, "godot", "models")
PAGE = r"C:\Users\frant\Downloads\dwarf_life.html"

POINT_SCALE = 16384.0
UV_SCALE = 32767.0

CLIP_SOURCES = [
    ("demo_start_models.json", ("objects", "mann.3db::mann", "locomotion")),
    ("dwarf_surface_walk.json", ("clips",)),
    ("dwarf_dig_action.json", ("clips",)),
    ("native_dig_feedback.json", ("clips",)),
    ("native_floor_sleep.json", ("clips",)),
]
DIG_FEEDBACK_ALIASES = {
    "digup": "buddeln_oben_normal", "digfront": "buddeln_vorn",
    "digdown": "buddeln_unten", "digupaccident": "buddeln_oben_norm_unfall",
    "digdownaccident": "buddeln_unten_unfall",
}


def dig(obj, path):
    for key in path:
        obj = obj[key]
    return obj


def load_json(name):
    with io.open(os.path.join(MODELS, name), encoding="utf-8") as f:
        return json.load(f)


def collect_source():
    """Клипы в том же порядке, что и в экспортере."""
    entries = []
    for filename, path in CLIP_SOURCES:
        data = load_json(filename)
        source = dig(data, path)
        if filename == "native_dig_feedback.json":
            items = [(DIG_FEEDBACK_ALIASES.get(k, k), v) for k, v in source.items()]
        else:
            items = list(source.items())
        for name, clip in items:
            if clip["frames"]:
                entries.append((filename, name, clip))
    return entries


def decode(raw):
    off = 4
    version, clip_count = struct.unpack_from("<II", raw, off); off += 8
    clips = []
    for _ in range(clip_count):
        nlen = struct.unpack_from("<I", raw, off)[0]; off += 4
        name = raw[off:off + nlen].decode("utf-8"); off += nlen
        frame_count, surface_count = struct.unpack_from("<II", raw, off); off += 8
        fps, scale = struct.unpack_from("<ff", raw, off); off += 8
        center = list(struct.unpack_from("<fff", raw, off)); off += 12
        height = struct.unpack_from("<f", raw, off)[0]; off += 4
        surfaces = []
        for _s in range(surface_count):
            pc, ic = struct.unpack_from("<II", raw, off); off += 8
            ti = raw[off]; off += 1
            indices = list(struct.unpack_from("<%dH" % ic, raw, off)); off += 2 * ic
            surfaces.append(dict(pc=pc, ic=ic, ti=ti, indices=indices))
        frames = []
        for _f in range(frame_count):
            per = []
            for s in surfaces:
                pos = list(struct.unpack_from("<%dh" % (s["pc"] * 3), raw, off)); off += 2 * s["pc"] * 3
                uv = list(struct.unpack_from("<%dh" % (s["pc"] * 2), raw, off)); off += 2 * s["pc"] * 2
                bright = list(raw[off:off + s["pc"]]); off += s["pc"]
                per.append(dict(pos=pos, uv=uv, bright=bright))
            frames.append(per)
        clips.append(dict(name=name, fps=fps, scale=scale, center=center, height=height,
                           surfaces=surfaces, frames=frames))
    return version, clips, off, len(raw)


def main():
    html = io.open(PAGE, encoding="utf-8").read()
    m = re.search(r'const CLIPS_B64 = "([A-Za-z0-9+/=]+)";', html)
    raw = base64.b64decode(m.group(1))
    version, clips, consumed, total = decode(raw)
    print("version=%d clips=%d consumed=%d/%d bytes" % (version, len(clips), consumed, total))
    if consumed != total:
        print("!! Блок декодируется не полностью")

    entries = collect_source()
    print("source clips: %d" % len(entries))

    errors = collections.Counter()
    samples = {}

    def fail(tag, detail):
        errors[tag] += 1
        if tag not in samples:
            samples[tag] = detail

    for idx, clip in enumerate(clips):
        cname = clip["name"]
        if idx >= len(entries):
            fail("clip-count", cname)
            continue
        src_file, src_name, src = entries[idx]
        if cname != src_name:
            fail("clip-name", "%s != %s" % (cname, src_name))
            continue
        src_frames = src["frames"]
        if len(src_frames) != len(clip["frames"]):
            fail("frame-count", "%s: %d != %d" % (cname, len(clip["frames"]), len(src_frames)))
            continue
        for f, (sframe, bframe) in enumerate(zip(src_frames, clip["frames"])):
            if len(sframe["surfaces"]) != len(bframe):
                fail("surface-count", "%s f%d" % (cname, f))
                continue
            for s, (ssurf, bsurf) in enumerate(zip(sframe["surfaces"], bframe)):
                pc = clip["surfaces"][s]["pc"]
                if len(ssurf["points"]) != pc:
                    fail("point-count", "%s f%d s%d: %d != %d" % (cname, f, s, len(ssurf["points"]), pc))
                    continue
                # позиции
                for i, p in enumerate(ssurf["points"]):
                    want = (round((p[0] - 0.5) * POINT_SCALE),
                            round(-(p[1] - 0.5) * POINT_SCALE),
                            round((p[2] - 0.5) * POINT_SCALE))
                    got = tuple(bsurf["pos"][i * 3:i * 3 + 3])
                    if want != got:
                        fail("position", "%s f%d s%d v%d: %s != %s" % (cname, f, s, i, want, got))
                        break
                # uv
                for i, u in enumerate(ssurf["uvs"]):
                    want = (round(u[0] * UV_SCALE), round(u[1] * UV_SCALE))
                    got = tuple(bsurf["uv"][i * 2:i * 2 + 2])
                    if want != got:
                        fail("uv", "%s f%d s%d v%d: %s != %s" % (cname, f, s, i, want, got))
                        break
                # brightness
                if list(ssurf["brightness"]) != list(bsurf["bright"]):
                    fail("brightness", "%s f%d s%d" % (cname, f, s))
                    break
        # индексы (топология постоянна между кадрами)
        sframe0 = src_frames[0]["surfaces"]
        for s, (ssurf, bsurf) in enumerate(zip(sframe0, clip["surfaces"])):
            want = list(ssurf["triangles"])
            got = bsurf["indices"]
            if want != got:
                fail("indices", "%s s%d: len %d != %d" % (cname, s, len(want), len(got)))
                continue
            if got and max(got) >= bsurf["pc"]:
                fail("index-range", "%s s%d: max %d >= pc %d" % (cname, s, max(got), bsurf["pc"]))
            if len(got) % 3:
                fail("index-count", "%s s%d: %d not multiple of 3" % (cname, s, len(got)))

    # Статистика по геометрии: площадь треугольников в clip-space.
    c = clips[0]
    s0 = c["frames"][0][0]
    pos = s0["pos"]
    idx = c["surfaces"][0]["indices"]
    areas = []
    for t in range(0, len(idx), 3):
        a, b, cc = idx[t], idx[t + 1], idx[t + 2]
        pa = pos[a * 3:a * 3 + 3]; pb = pos[b * 3:b * 3 + 3]; pc_ = pos[cc * 3:cc * 3 + 3]
        u = [pb[i] - pa[i] for i in range(3)]
        v = [pc_[i] - pa[i] for i in range(3)]
        cr = (u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0])
        areas.append(0.5 * math.sqrt(sum(x * x for x in cr)))
    print("\nclip %s: surface0 triangles=%d, area min=%.3f max=%.3f" % (
        c["name"], len(idx) // 3, min(areas), max(areas)))
    print("position range x[%d..%d] y[%d..%d] z[%d..%d]" % (
        min(pos[0::3]), max(pos[0::3]), min(pos[1::3]), max(pos[1::3]), min(pos[2::3]), max(pos[2::3])))

    print("\n=== ИТОГ ===")
    if not errors:
        print("OK: расхождений нет")
    else:
        for tag, count in errors.most_common():
            print("  %-14s %6d  пример: %s" % (tag, count, samples.get(tag)))
        print("ВСЕГО ошибок: %d" % sum(errors.values()))
    return 0 if not errors else 1


if __name__ == "__main__":
    sys.exit(main())
