# -*- coding: utf-8 -*-
"""Проверка раскладки суб-клеток .pmp по формуле exe (FUN_00596550, дизасм 0x596731).

Индекс суб-клетки (sx,sy) клетки (cx,cy) в распакованном RLE-буфере:

    idx = (cy*8 + sy) * (w*8) + cx*8 + sx

т.е. плоская сетка (w*8) x (h*8), row-major.
Это ровно формула exe: ((cellY*8 - y0*8) + sy) * (w*8) - x0*8 + cellX*8 + sx
при param_2 = [x0*8, y0*8, (x0+w)*8, (y0+h)*8].
Движок кладёт эти байты в блок карты (8x8 клеток) по адресу block+0x3c
в «cell-major» виде: block+0x3c + subX + subY*8.
"""
import io
import os
import struct
from collections import Counter

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\Templates\pmp"
OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "pmp_subcell_layout.txt")

GLYPH = {0: ".", 1: "-", 2: ":", 3: "#"}
lines = []


def p(s=""):
    lines.append(str(s))


def load_pmp(path):
    data = open(path, "rb").read()
    w, h = struct.unpack_from("<II", data, 0)
    cells = w * h
    off = 8
    flags = data[off:off + cells]
    off += cells
    off += 4 * cells
    tail_count = struct.unpack_from("<I", data, off)[0]
    off += 4
    tail = struct.unpack_from("<%dH" % tail_count, data, off)
    off += 2 * tail_count
    tailbytes = data[off:off + cells]
    buf = bytearray()
    for w16 in tail:
        run = w16 >> 2
        if run == 0:
            run = 0x4000
        buf += bytes([w16 & 3]) * run
    return w, h, flags, buf, tailbytes


def main():
    p("РАСКЛАДКА СУБ-КЛЕТОК .pmp (проверка формулы exe)")
    p("=" * 78)
    for name in ("caves_1.pmp", "hol_001.pmp", "gng_001.pmp"):
        path = os.path.join(GAME, name)
        if not os.path.exists(path):
            p("нет %s" % name)
            continue
        w, h, flags, buf, tailbytes = load_pmp(path)
        p("=" * 78)
        p("%s: w=%d h=%d cells=%d  RLE=%d  ожидается 8*w*8*h=%d  -> %s"
          % (name, w, h, w * h, len(buf), w * h * 64,
             "OK" if len(buf) == w * h * 64 else "MISMATCH"))
        p("  коды суб-клеток: %s" % (sorted(Counter(buf).items()),))
        # полная карта (w*8) x (h*8)
        p("  полная сетка суб-клеток (%dx%d):" % (w * 8, h * 8))
        for r in range(h * 8):
            row = []
            for c in range(w * 8):
                i = r * (w * 8) + c
                row.append(GLYPH.get(buf[i], "?") if i < len(buf) else "?")
            p("    " + "".join(row))
        p()
        # карта по клеткам (8x8 каждая) для первых непустых клеток
        shown = 0
        for cy in range(h):
            for cx in range(w):
                rows = []
                for sy in range(8):
                    r = []
                    for sx in range(8):
                        i = (cy * 8 + sy) * (w * 8) + cx * 8 + sx
                        r.append(buf[i] if i < len(buf) else -1)
                    rows.append(r)
                flat = [v for r_ in rows for v in r]
                if any(flat) and shown < 2:
                    shown += 1
                    p("  клетка (%d,%d) — 8x8 суб-клеток:" % (cx, cy))
                    for r in rows:
                        p("      " + " ".join("%d" % v for v in r))
        p()

    with io.open(OUT, "w", encoding="utf-8", newline="") as f:
        f.write("\n".join(lines) + "\n")
    print("written:", OUT)


if __name__ == "__main__":
    main()
