"""Разбор data/Templates/cave{0..3}.tga: заголовок TGA, содержимое, квантование движка (b+0x20)>>6."""
import io
import os
import struct

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
OUT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp"

TGA_TYPES = {
    0: "нет данных",
    1: "непрокрашенный цветовойMap",
    2: "непрокрашенный true-color",
    3: "непрокрашенный оттенки серого",
    9: "RLE оттенки серого",
    10: "RLE true-color",
    11: "RLE цветовойMap",
}


def parse(path):
    with open(path, "rb") as f:
        d = f.read()
    hdr = d[:18]
    (idlen, cmaptype, imgtype, cmap_first, cmap_len, cmap_bpp,
     x0, y0, w, h, bpp, desc) = struct.unpack("<BBBHHBHHHHBB", hdr)
    out = {
        "file": os.path.basename(path),
        "size": len(d),
        "id_len": idlen,
        "cmap_type": cmaptype,
        "img_type": imgtype,
        "img_type_name": TGA_TYPES.get(imgtype, "?"),
        "cmap_first": cmap_first,
        "cmap_len": cmap_len,
        "cmap_bpp": cmap_bpp,
        "w": w, "h": h, "bpp": bpp,
        "desc": desc,
        "data_offset": 18 + idlen + (cmap_len * ((cmap_bpp + 7) // 8) if cmaptype else 0),
        "raw": d,
    }
    return out


def un_rle_gray(d, off, w, h):
    """Распаковка RLE серого (тип 9)."""
    px = bytearray()
    i = off
    total = w * h
    while i < len(d) and len(px) < total:
        pkt = d[i]
        i += 1
        cnt = (pkt & 0x7F) + 1
        if pkt & 0x80:
            if i >= len(d):
                break
            val = d[i]
            i += 1
            px.extend([val] * cnt)
        else:
            px.extend(d[i:i + cnt])
            i += cnt
    return bytes(px)


def un_rle_true(d, off, w, h, bpp):
    px = bytearray()
    i = off
    total = w * h
    b = bpp // 8
    while i < len(d) and len(px) < total * b:
        pkt = d[i]
        i += 1
        cnt = (pkt & 0x7F) + 1
        if pkt & 0x80:
            if i + b > len(d):
                break
            val = d[i:i + b]
            i += b
            px.extend(val * cnt)
        else:
            px.extend(d[i:i + cnt * b])
            i += cnt * b
    return bytes(px)


def quant(b):
    """Квантование движка: palette[i] = (palette[i] + 0x20) >> 6."""
    return (b + 0x20) >> 6


lines = []
for k in range(4):
    p = os.path.join(GAME, "Templates", f"cave{k}.tga")
    t = parse(p)
    lines.append("=== %s (%d B) ===" % (t["file"], t["size"]))
    lines.append("  img_type=%d (%s)  w=%d h=%d bpp=%d  cmap_type=%d cmap_len=%d cmap_bpp=%d  id_len=%d  desc=0x%02x"
                 % (t["img_type"], t["img_type_name"], t["w"], t["h"], t["bpp"],
                    t["cmap_type"], t["cmap_len"], t["cmap_bpp"], t["id_len"], t["desc"]))
    lines.append("  data_offset=%d, payload=%d B" % (t["data_offset"], t["size"] - t["data_offset"]))

    px = None
    if t["img_type"] == 9:
        px = un_rle_gray(t["raw"], t["data_offset"], t["w"], t["h"])
    elif t["img_type"] == 10:
        px = un_rle_true(t["raw"], t["data_offset"], t["w"], t["h"], t["bpp"])
    elif t["img_type"] == 2:
        px = t["raw"][t["data_offset"]:]

    if px is not None:
        lines.append("  распаковано %d B" % len(px))
        hist = {}
        qhist = {}
        for b in px:
            hist[b] = hist.get(b, 0) + 1
            q = quant(b)
            qhist[q] = qhist.get(q, 0) + 1
        lines.append("  исходная гистограмма (топ-12): %s"
                     % ", ".join("%d:%d" % (v, c) for v, c in sorted(hist.items(), key=lambda kv: -kv[1])[:12]))
        lines.append("  гистограмма ПОСЛЕ квантования: %s"
                     % ", ".join("%d:%d" % (v, c) for v, c in sorted(qhist.items())))
        # ASCII-карта квантованных значений, если это 64x64 по 1 байту
        if len(px) >= 4096 and t["w"] * t["h"] == 4096:
            chars = " .:-=+*#%@"
            lines.append("  ASCII (64x64, квантованные уровни):")
            for row in range(64):
                line = ""
                for col in range(64):
                    q = quant(px[row * 64 + col])
                    line += chars[min(q, len(chars) - 1)]
                lines.append("    |" + line + "|")
    lines.append("")

txt = "\n".join(lines)
with io.open(os.path.join(OUT, "cave_tga_probe.txt"), "w", encoding="utf-8", newline="\n") as f:
    f.write(txt)
print(txt[:4000])
