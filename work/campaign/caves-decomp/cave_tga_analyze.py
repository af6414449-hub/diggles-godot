# -*- coding: utf-8 -*-
"""Разбор data/templates/cave{0..3}.tga: заголовок TGA, каналы, квантование.

Контекст (Diggles.exe):
  FUN_005661c0 (конструктор объекта пещеры) грузит cave0..3.tga через FUN_006c0370
  и квантует каждый байт: mask[i] = (byte + 0x20) >> 6  -> 0..4.
  Размер маски 0x1000 = 4096 байт = 32*32*4 (сырые RGBA-байты 32x32 TGA).
"""
import os
import struct
from collections import Counter

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\templates"
OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "cave_tga_analyze.txt")

lines = []


def p(s=""):
    lines.append(str(s))


def dump_map(title, vals, w, h):
    p(title)
    for y in range(h):
        p("  " + " ".join("%2d" % vals[y * w + x] for x in range(w)))
    p()


def main():
    p("=" * 78)
    p("АНАЛИЗ data/templates/cave{0..3}.tga")
    p("=" * 78)
    for i in range(4):
        path = os.path.join(GAME, "cave%d.tga" % i)
        if not os.path.exists(path):
            p("НЕТ ФАЙЛА: %s" % path)
            continue
        data = open(path, "rb").read()
        p("-" * 78)
        p("cave%d.tga  size=%d  (4140 в инвентаре)" % (i, len(data)))
        idlen, cmaptype, imgtype = data[0], data[1], data[2]
        xo, yo, w, h, bpp, desc = struct.unpack_from("<HHHHBB", data, 8)
        p("  TGA hdr: idlen=%d cmaptype=%d imgtype=%d origin=(%d,%d) w=%d h=%d bpp=%d desc=0x%02x"
          % (idlen, cmaptype, imgtype, xo, yo, w, h, bpp, desc))
        p("  header=%d bytes, pixels=%d*%d*%d=%d, tail=%d"
          % (18 + idlen, w, h, bpp // 8, w * h * (bpp // 8), len(data) - 18 - idlen - w * h * (bpp // 8)))
        off = 18 + idlen
        px = data[off:off + w * h * 4]
        p("  pixel bytes=%d" % len(px))
        # каналы
        chans = {"R": [], "G": [], "B": [], "A": []}
        for k in range(0, len(px), 4):
            chans["R"].append(px[k])
            chans["G"].append(px[k + 1])
            chans["B"].append(px[k + 2])
            chans["A"].append(px[k + 3])
        for name in "RGBA":
            c = Counter(chans[name])
            p("  %s: distinct=%d  %s" % (name, len(c), sorted(c.items())))
        # квантование как в exe
        quant = [(b + 0x20) >> 6 for b in px]
        cq = Counter(quant)
        p("  quantized((b+0x20)>>6): %s" % (sorted(cq.items()),))
        # уникальные значения RGB
        rgbs = set(zip(chans["R"], chans["G"], chans["B"]))
        p("  distinct RGB triples: %d -> %s" % (len(rgbs), sorted(rgbs)[:12]))
        # карты каналов 32x32
        for name in "RGBA":
            dump_map("  raw %s 32x32:" % name, chans[name], w, h)
        dump_map("  quantized full 64x64 (как сетка масок в exe):", quant, 64, 64)
        # первая половина (R,G каналы) 32x64
        p("  quant: байты 0..2047 (R,G плоскости), сжато 32x64:")
        half = quant[:2048]
        for y in range(64):
            p("    " + " ".join("%d" % half[y * 32 + x] for x in range(32)))
        p()

    with open(OUT, "w", encoding="utf-8") as f:
        f.write("\n".join(lines) + "\n")
    print("written:", OUT, len(lines), "lines")


if __name__ == "__main__":
    main()
