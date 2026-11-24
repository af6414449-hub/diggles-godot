# -*- coding: utf-8 -*-
"""
Export the male dwarf (mann.3db::mann) animation clips of the Diggles reverse
engineering project into a self-contained HTML viewer.

Sources (read-only, exported by the project):
  godot/models/demo_start_models.json     -> floor locomotion clips
  godot/models/dwarf_surface_walk.json    -> wall / ladder body clips
  godot/models/dwarf_dig_action.json      -> digging clips
  godot/models/native_dig_feedback.json   -> digging accident clips
  godot/models/native_floor_sleep.json    -> sleep clips
  godot/models/dwarf_combat_invent.json   -> combat and invention clips
  godot/models/native_model_material.json -> 256 entry normal table
  godot/models/dwarf_attachments.json     -> right hand socket + spitzhacke asset
  godot/textures/models/ZMann_*.tga       -> body textures
  godot/textures/models/Metall_Werkzeuge_a_128.tga -> pickaxe texture

Geometry layout matches the source export exactly:
  local = Vector3(p.x - 0.5, -(p.y - 0.5), p.z - 0.5) * 16384
  (p is the u16/65536 normalized point of the original .3db model)

Binary layout (little endian):
  "HMSC" | u32 version | u32 clipCount
  per clip: u32 nameLen | name | u32 frameCount | u32 surfaceCount
            f32 fps | f32 scale | f32 center[3] | f32 height
            per surface: u32 pointCount | u32 indexCount | u8 textureIndex
                         | u16 indices[indexCount]
            per frame: per surface: i16 positions[pointCount*3]
                                    | i16 uvs[pointCount*2]
                                    | u8 bright[pointCount]
"""
import base64, collections, hashlib, io, json, math, os, struct, zlib

PROJECT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
MODELS = os.path.join(PROJECT, "godot", "models")
TEXTURES = os.path.join(PROJECT, "godot", "textures", "models")
TEMPLATE = os.path.join(PROJECT, "tools", "dwarf_life_template.html")
OUT = r"C:\Users\frant\Downloads\dwarf_life.html"

POINT_SCALE = 16384.0
UV_SCALE = 32767.0
DISPLAY_HEIGHT = 1.4          # world units of the tallest dwarf pose

CLIP_SOURCES = [
    ("demo_start_models.json", ("objects", "mann.3db::mann", "locomotion"), 10.0, "floor"),
    ("dwarf_surface_walk.json", ("clips",), 10.0, "surface"),
    ("dwarf_dig_action.json", ("clips",), 12.0, "dig"),
    ("native_dig_feedback.json", ("clips",), 12.0, "dig"),
    ("native_floor_sleep.json", ("clips",), 10.0, "sleep"),
    # бой и изобретение: у каждого клипа своя частота кадров (adapter_fps в JSON)
    ("dwarf_combat_invent.json", ("clips",), None, "combat"),
]

DIG_FEEDBACK_ALIASES = {
    "digup": "buddeln_oben_normal",
    "digfront": "buddeln_vorn",
    "digdown": "buddeln_unten",
    "digupaccident": "buddeln_oben_norm_unfall",
    "digdownaccident": "buddeln_unten_unfall",
}

# Клипы, где в руке гнома находится кирка. Положение кирки берётся из игровых
# креплений (dwarf_attachments.json): сокет правой руки на каждый кадр.
TOOL_CLIPS = {
    "werkzeug_raus_a", "werkzeug_raus_b",
    "buddeln_oben_normal", "buddeln_vorn", "buddeln_unten",
    "buddeln_oben_norm_unfall", "buddeln_unten_unfall",
    "werkzeug_weg_a", "werkzeug_weg_b",
    "kletter_hack_oben", "kletter_hack_unten",
    "kletter_hack_links", "kletter_hack_rechts",
}
# У аварийных клипов нет своих креплений — берём сокет одноимённого обычного клипа.
SOCKET_FALLBACK = {
    "buddeln_oben_norm_unfall": "buddeln_oben_normal",
    "buddeln_unten_unfall": "buddeln_unten",
}
ATTACH_MODEL = "mann.3db::mann"
ATTACH_FILE = "dwarf_attachments.json"
TOOL_ASSET = "spitzhacke"           # werkzeuge.3db::spitzhacke — реальная кирка
TOOL_TEXTURE = "Metall_Werkzeuge_a_128.tga"
RENDER_SCALE = 0.005          # нативная единица -> единица рендера (из контракта)
NATIVE_PER_UNIT = 200.0       # обратное преобразование
# Убраны со страницы: «Простой А» и зависание на стене (kletterstand_anim).
# Повороты на 90° (drehen_links/drehen_rechts) и варианты кирки «b» вернулись:
# кнопки поворота чередуют 90° и 180°, а копание вперёд и застревание вниз
# в игре берут кирку «b».
SKIP_CLIPS = {"stand_anim_a", "kletterstand_anim"}


def load_json(name):
    with io.open(os.path.join(MODELS, name), encoding="utf-8") as f:
        return json.load(f)


def dig(obj, path):
    for key in path:
        obj = obj[key]
    return obj


# ---------------------------------------------------------------------------
# TGA -> PNG
# ---------------------------------------------------------------------------
def read_tga(path):
    with open(path, "rb") as f:
        data = f.read()
    id_len, cmap_type, image_type = data[0], data[1], data[2]
    width = struct.unpack_from("<H", data, 12)[0]
    height = struct.unpack_from("<H", data, 14)[0]
    depth, descriptor = data[16], data[17]
    offset = 18 + id_len
    if cmap_type == 1:
        offset += struct.unpack_from("<H", data, 5)[0] * data[7]
    if image_type != 2 or depth not in (24, 32):
        raise ValueError("unsupported TGA %s type=%d depth=%d" % (path, image_type, depth))
    bpp = depth // 8
    raw = data[offset:offset + width * height * bpp]
    top_down = bool(descriptor & 0x20)
    right_to_left = bool(descriptor & 0x10)
    pixels = bytearray(width * height * 4)
    for y in range(height):
        src_row = y if top_down else (height - 1 - y)
        for x in range(width):
            sx = (width - 1 - x) if right_to_left else x
            si = (src_row * width + sx) * bpp
            di = (y * width + x) * 4
            b, g, r = raw[si], raw[si + 1], raw[si + 2]
            pixels[di] = r
            pixels[di + 1] = g
            pixels[di + 2] = b
            pixels[di + 3] = raw[si + 3] if bpp == 4 else 255
    return width, height, bytes(pixels)


def png_bytes(width, height, rgba):
    stride = width * 4
    raw = bytearray()
    for y in range(height):
        raw.append(0)
        raw.extend(rgba[y * stride:(y + 1) * stride])

    def chunk(tag, payload):
        return (struct.pack(">I", len(payload)) + tag + payload +
                struct.pack(">I", zlib.crc32(tag + payload) & 0xFFFFFFFF))

    return (b"\x89PNG\r\n\x1a\n" +
            chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0)) +
            chunk(b"IDAT", zlib.compress(bytes(raw), 9)) +
            chunk(b"IEND", b""))


# ---------------------------------------------------------------------------
# clips
# ---------------------------------------------------------------------------
def surface_points(surface):
    for p in surface["points"]:
        yield ((p[0] - 0.5) * POINT_SCALE,
               -(p[1] - 0.5) * POINT_SCALE,
               (p[2] - 0.5) * POINT_SCALE)


def clip_signature(frames):
    h = hashlib.sha1()
    for frame in frames:
        for s in frame["surfaces"]:
            h.update(s["texture"].encode("utf-8"))
            h.update(repr(s["points"]).encode("utf-8"))
            h.update(repr(s["uvs"]).encode("utf-8"))
            h.update(repr(s["triangles"]).encode("utf-8"))
            h.update(repr(s["brightness"]).encode("utf-8"))
    return h.hexdigest()


def collect():
    entries = []
    for filename, path, fps, group in CLIP_SOURCES:
        data = load_json(filename)
        source = dig(data, path)
        if filename == "native_dig_feedback.json":
            items = [(DIG_FEEDBACK_ALIASES.get(k, k), v) for k, v in source.items()]
        else:
            items = list(source.items())
        for name, clip in items:
            frames = clip["frames"]
            if not frames:
                continue
            # у части источников частота кадров задана в самом клипе
            clip_fps = fps if fps is not None else clip.get("adapter_fps", 12.0)
            entries.append({
                "name": name, "group": group, "fps": clip_fps, "source": filename,
                "frames": frames,
            })
    # drop clips whose full geometry was already exported under another name
    seen = {}
    final = []
    for entry in entries:
        if entry["name"] in SKIP_CLIPS:
            continue
        sig = clip_signature(entry["frames"])
        if sig in seen:
            continue
        seen[sig] = entry["name"]
        final.append(entry)
    return final


def clip_bounds(frames):
    minx = miny = minz = float("inf")
    maxx = maxy = maxz = float("-inf")
    for frame in frames:
        for s in frame["surfaces"]:
            for x, y, z in surface_points(s):
                minx = min(minx, x); maxx = max(maxx, x)
                miny = min(miny, y); maxy = max(maxy, y)
                minz = min(minz, z); maxz = max(maxz, z)
    center = ((minx + maxx) / 2.0, (miny + maxy) / 2.0, (minz + maxz) / 2.0)
    return center, maxy - miny


# ---------------------------------------------------------------------------
# кирка в руке: настоящий ассет игры werkzeuge.3db::spitzhacke + игровые сокеты
# ---------------------------------------------------------------------------
def load_attachments():
    """Данные креплений: модель тела, сокеты рук/головы и ассеты (кирка)."""
    with io.open(os.path.join(MODELS, ATTACH_FILE), encoding="utf-8") as f:
        return json.load(f)


def tool_surface(attach):
    """Настоящая сетка кирки: werkzeuge.3db::spitzhacke (36 точек, 20 треугольников)."""
    asset = attach["assets"][TOOL_ASSET]
    frame = asset["frames"][asset.get("default_frame", 0)]
    return frame["surfaces"][0]


def tool_local_vertices(surface):
    """Вершины кирки в локальном пространстве ассета (с отражением Y, как в игре)."""
    return [((p[0] - 0.5) * POINT_SCALE,
             -(p[1] - 0.5) * POINT_SCALE,
             (p[2] - 0.5) * POINT_SCALE) for p in surface["points"]]


def smooth_normals(verts, tris):
    """Усреднённые нормали граней в локальном пространстве кирки."""
    acc = [[0.0, 0.0, 0.0] for _ in verts]
    for i0, i1, i2 in tris:
        a, b, c = verts[i0], verts[i1], verts[i2]
        e1 = (b[0] - a[0], b[1] - a[1], b[2] - a[2])
        e2 = (c[0] - a[0], c[1] - a[1], c[2] - a[2])
        n = (e1[1] * e2[2] - e1[2] * e2[1],
             e1[2] * e2[0] - e1[0] * e2[2],
             e1[0] * e2[1] - e1[1] * e2[0])
        for i in (i0, i1, i2):
            acc[i][0] += n[0]; acc[i][1] += n[1]; acc[i][2] += n[2]
    out = []
    for n in acc:
        l = math.sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2])
        out.append((n[0] / l, n[1] / l, n[2] / l) if l > 1e-9 else (0.0, 1.0, 0.0))
    return out


def socket_transform(attach, clip_name, frame):
    """Сокет правой руки для кадра: (базис 3x3, начало в единицах тела).

    Игра кладёт ассет на сокет transform = Transform3D(Basis(basis_columns),
    origin_render), а вершины ассета лежат в mesh_point = F*(p-0.5)*16384*0.005,
    где F = diag(1,-1,1). Значит в единицах 16384:
        world = B * F*(p-0.5)*16384 + origin_render * 200
    """
    model = attach["models"][ATTACH_MODEL]
    a = model["clips"].get(clip_name)
    if not a:
        return None
    idx = frame % len(a["mesh_indices"])
    mesh = model["meshes"].get(str(a["mesh_indices"][idx]))
    if not mesh:
        return None
    slot = mesh["slots"].get("0")
    if not slot:
        return None
    bc = slot["basis_columns"]
    cols = [[float(bc[j][i]) for i in range(3)] for j in range(3)]
    basis = [[cols[j][i] for j in range(3)] for i in range(3)]   # строки матрицы
    origin = [float(v) * NATIVE_PER_UNIT for v in slot["origin_render"]]
    return basis, origin


def apply_socket(basis, origin, point):
    """Точка сокета -> пространство тела (единицы 16384, как у вершин тела)."""
    return (origin[0] + basis[0][0] * point[0] + basis[0][1] * point[1] + basis[0][2] * point[2],
            origin[1] + basis[1][0] * point[0] + basis[1][1] * point[1] + basis[1][2] * point[2],
            origin[2] + basis[2][0] * point[0] + basis[2][1] * point[1] + basis[2][2] * point[2])


def rotate(basis, vector):
    """Поворот вектора базисом (без переноса)."""
    return (basis[0][0] * vector[0] + basis[0][1] * vector[1] + basis[0][2] * vector[2],
            basis[1][0] * vector[0] + basis[1][1] * vector[1] + basis[1][2] * vector[2],
            basis[2][0] * vector[0] + basis[2][1] * vector[1] + basis[2][2] * vector[2])


def nearest_normal_index(normals, target):
    """Индекс в таблице нормалей, ближайший к направлению (в соглашении шейдера).

    Таблица хранит нормали в исходных координатах модели, а шейдер берёт
    (x, -y, z) — как в игре (godot_local_normals). Поэтому сравниваем с
    отражённой записью таблицы.
    """
    best = -2.0
    index = 0
    for i, n in enumerate(normals):
        d = n[0] * target[0] - n[1] * target[1] + n[2] * target[2]
        if d > best:
            best = d
            index = i
    return index


def build_binary(clips, scale, texture_names, normals, attach):
    texture_index = {n: i for i, n in enumerate(texture_names)}
    tool = tool_surface(attach)
    tool_verts = tool_local_vertices(tool)
    tool_tris = [(tool["triangles"][i], tool["triangles"][i + 1], tool["triangles"][i + 2])
                 for i in range(0, len(tool["triangles"]), 3)]
    tool_normals = smooth_normals(tool_verts, tool_tris)
    tool_uvs = tool["uvs"]
    out = bytearray()
    out += b"HMSC" + struct.pack("<II", 2, len(clips))
    meta = []
    for entry in clips:
        frames = entry["frames"]
        surfaces = frames[0]["surfaces"]
        center, height = clip_bounds(frames)
        name_bytes = entry["name"].encode("utf-8")
        out += struct.pack("<I", len(name_bytes)) + name_bytes
        out += struct.pack("<I", len(frames))
        out += struct.pack("<I", len(surfaces) + (1 if entry["name"] in TOOL_CLIPS else 0))
        out += struct.pack("<f", entry["fps"])
        out += struct.pack("<f", scale)
        out += struct.pack("<fff", *center)
        out += struct.pack("<f", height)
        for s in surfaces:
            out += struct.pack("<I", len(s["points"]))
            out += struct.pack("<I", len(s["triangles"]))
            out += struct.pack("<B", texture_index[s["texture"]])
            out += b"".join(struct.pack("<H", t) for t in s["triangles"])
        has_pick = entry["name"] in TOOL_CLIPS
        if has_pick:
            out += struct.pack("<I", len(tool_verts))
            out += struct.pack("<I", len(tool["triangles"]))
            out += struct.pack("<B", texture_index[TOOL_TEXTURE])
            out += b"".join(struct.pack("<H", t) for t in tool["triangles"])
        for frame_index, frame in enumerate(frames):
            for s in frame["surfaces"]:
                pos = bytearray()
                for p in s["points"]:
                    pos += struct.pack("<hhh",
                                       round((p[0] - 0.5) * POINT_SCALE),
                                       round(-(p[1] - 0.5) * POINT_SCALE),
                                       round((p[2] - 0.5) * POINT_SCALE))
                uv = bytearray()
                for u in s["uvs"]:
                    uv += struct.pack("<hh", round(u[0] * UV_SCALE), round(u[1] * UV_SCALE))
                out += pos + uv + bytes(s["brightness"])
            if has_pick:
                sock_clip = SOCKET_FALLBACK.get(entry["name"], entry["name"])
                tr = socket_transform(attach, sock_clip, frame_index)
                pos = bytearray()
                uvs = bytearray()
                bright = bytearray()
                if tr is None:
                    # сокета нет — прячем кирку в ноль
                    for v in tool_verts:
                        pos += struct.pack("<hhh", 0, 0, 0)
                    for u in tool_uvs:
                        uvs += struct.pack("<hh", round(u[0] * UV_SCALE), round(u[1] * UV_SCALE))
                    bright = bytearray(len(tool_verts))
                else:
                    basis, origin = tr
                    for v, n in zip(tool_verts, tool_normals):
                        wx, wy, wz = apply_socket(basis, origin, v)
                        pos += struct.pack("<hhh", round(wx), round(wy), round(wz))
                        nx, ny, nz = rotate(basis, n)
                        bright.append(nearest_normal_index(normals, (nx, -ny, nz)))
                    for u in tool_uvs:
                        uvs += struct.pack("<hh", round(u[0] * UV_SCALE), round(u[1] * UV_SCALE))
                out += pos + uvs + bytes(bright)
        meta.append({
            "name": entry["name"], "group": entry["group"], "fps": entry["fps"],
            "frames": len(frames), "surfaces": len(surfaces) + (1 if has_pick else 0),
            "height": height, "source": entry["source"],
        })
    return bytes(out), meta


def main():
    clips = collect()
    texture_names = []
    for entry in clips:
        for frame in entry["frames"]:
            for s in frame["surfaces"]:
                if s["texture"] not in texture_names:
                    texture_names.append(s["texture"])
    if TOOL_TEXTURE not in texture_names:
        texture_names.append(TOOL_TEXTURE)

    heights = [clip_bounds(e["frames"])[1] for e in clips]
    scale = DISPLAY_HEIGHT / max(heights)

    normals = load_json("native_model_material.json")["normal_table"]
    attach = load_attachments()

    binary, meta = build_binary(clips, scale, texture_names, normals, attach)

    textures = []
    for name in texture_names:
        w, h, rgba = read_tga(os.path.join(TEXTURES, name))
        png = png_bytes(w, h, rgba)
        textures.append({
            "name": name, "width": w, "height": h,
            "png": "data:image/png;base64," + base64.b64encode(png).decode("ascii"),
        })

    payload = {
        "clips": meta,
        "textures": textures,
        "normalTable": normals,
        "scale": scale,
        "modelHeight": max(heights),
        "totalFrames": sum(m["frames"] for m in meta),
        "source": "godot/models (демо-старт, стены, копка, аварии, сон)",
    }

    with io.open(TEMPLATE, encoding="utf-8") as f:
        template = f.read()
    html = (template
             .replace("/*__PAYLOAD__*/", json.dumps(payload, ensure_ascii=False, separators=(",", ":")))
             .replace("/*__CLIPS_B64__*/", base64.b64encode(binary).decode("ascii")))

    with io.open(OUT, "w", encoding="utf-8") as f:
        f.write(html)

    print("clips    : %d" % len(meta))
    print("frames   : %d" % payload["totalFrames"])
    print("textures : %d -> %s" % (len(texture_names), ", ".join(texture_names)))
    print("binary   : %d bytes (base64 %d)" % (len(binary), (len(binary) * 4 + 2) // 3))
    print("html     : %d bytes -> %s" % (len(html), OUT))
    print()
    for m in meta:
        print("  %-28s %2d frames  %d surfaces  h=%7.1f  %s" %
              (m["name"], m["frames"], m["surfaces"], m["height"], m["source"]))


if __name__ == "__main__":
    main()
