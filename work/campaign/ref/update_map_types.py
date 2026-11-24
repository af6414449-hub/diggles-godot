#!/usr/bin/env python3
"""Обновляет ghidra_structs.tsv / ghidra_funcs.tsv перед проходом ApplyMapTypes.

Что делает:
  1. Переписывает раскладку CSceneRenderer на проверенную (маска 8 x 0x204,
     буферы вершин/индексов, счётчики) и добавляет вложенный рендерер в CDisplay.
  2. Убирает дубли в ghidra_funcs.tsv.
  3. Добавляет методы CMap (аксессор клетки, геттер высоты, сброс карты)
     и методы CSceneRenderer (геометрия ям/рёбер/стен/тумана, текстуры).
  4. Снимает ошибочные назначения классов: адрес переводится в CUnassigned,
     чтобы ApplyMapTypes снял старый тип `this` из базы.

Все смещения и принадлежность классов подтверждены дизассемблированием
(см. work/campaign/ref/notes-typing-2026-11-21.md).
"""
from __future__ import annotations

import io
from pathlib import Path

HERE = Path(__file__).parent
STRUCTS = HERE / "ghidra_structs.tsv"
FUNCS = HERE / "ghidra_funcs.tsv"

# --------------------------------------------------------------------------
# CSceneRenderer: проверенная раскладка.
#   0x0008  таблица масок: 8 групп x 0x204 байт (_eh_vector_constructor_iterator_)
#   0x1378  буфер вершин A: 0x400 x 9 float  (0x1378 + 0x9000 = 0xA378)
#   0xA378  буфер индексов A: 0x1000 ushort (0xA378 + 0x2000 = 0xC378)
#   0xC380  буфер вершин B: 0x400 x 9 float  (0xC380 + 0x9000 = 0x15380)
#   0x15380 буфер индексов B: 0x1000 ushort (0x15380 + 0x2000 = 0x17380)
# --------------------------------------------------------------------------
SCENE_RENDERER = [
    (0x0008, "maskGroups", "uint[1032]"),      # 8 групп по 0x204 байт
    (0x1028, "flag1", "byte"),
    (0x1029, "flag2", "byte"),
    (0x1034, "fogScale", "float"),
    (0x103C, "minHeight", "float"),
    (0x1040, "flag3", "byte"),
    (0x1041, "textures", "void *"),
    (0x1045, "textureCount", "int"),
    (0x104C, "textureIndex", "uint[82]"),
    (0x1194, "variants", "uint[82]"),
    (0x12DC, "defaultTexture", "uint"),
    (0x12E0, "sceneTime", "uint"),
    (0x12E4, "statA", "int"),
    (0x12E8, "statB", "int"),
    (0x12EC, "holesData", "void *"),
    (0x12F0, "holeCount", "int"),
    (0x12F4, "holeCapacity", "int"),
    (0x12F8, "holeHead", "int"),
    (0x12FC, "flag4", "byte"),
    (0x1300, "holeTail", "int"),
    (0x1304, "statC", "int"),
    (0x130C, "statD", "int"),
    (0x1310, "statE", "int"),
    (0x1318, "cornerRGBA", "uint[16]"),
    (0x1358, "fogVertices", "void *"),
    (0x135C, "fogVertexCount", "int"),
    (0x1360, "fogIndices", "void *"),
    (0x1364, "fogIndexCount", "int"),
    (0x1368, "wallVertices", "void *"),
    (0x136C, "wallVertexCount", "int"),
    (0x1370, "wallIndices", "void *"),
    (0x1374, "wallIndexCount", "int"),
    (0x1378, "vertBufA", "float[9216]"),
    (0xA378, "idxBufA", "ushort[4096]"),
    (0xC378, "vertCount", "int"),
    (0xC37C, "idxCount", "int"),
    (0xC380, "vertBufB", "float[9216]"),
    (0x15380, "idxBufB", "ushort[4096]"),
    (0x17380, "copiedVertCount", "int"),
    (0x17384, "copiedIdxCount", "int"),
]

# Новые методы (адрес -> класс). Принадлежность подтверждена по this/ECX.
NEW_FUNCS = {
    # CSceneRenderer: геометрия и текстуры
    "0x004c7d80": "CSceneRenderer",   # счётчики 0x12e4/0x12e8
    "0x004c9d50": "CSceneRenderer",   # копирование буферов вершин/индексов
    "0x004ca830": "CSceneRenderer",   # порог 2.0 + цвета углов 0x1318..0x1344
    "0x004cc040": "CSceneRenderer",   # интерполяция цвета по 4 углам
    "0x004cd020": "CSceneRenderer",   # блендинг текстур по маске
    "0x004cde30": "CSceneRenderer",   # пре-компьют 81 текстуры
    # CDisplay (сцена): рендерер лежит по смещению 0x28b0
    "0x00464780": "CDisplay",
    "0x004670d0": "CDisplay",
    # CMap: работа с картой
    "0x004093f0": "CMap",   # геттер высоты (вызывает аксессор клетки, ECX = карта)
    "0x00424cc0": "CMap",   # инициализация карты (обнуляет cells/cellCount/heightBlocks)
    "0x00590410": "CMap",   # сброс карты
    "0x00592f10": "CMap",   # аксессор клетки: cells + idx*0x7C
    "0x005939b0": "CMap",   # сброс карты (cells/cellCount/границы)
    "0x00595770": "CMap",   # читает this->x0_8/x1_8/y0_8/y1_8 и зовёт FUN_00592f10(this)
}

# Дополнительные поля, которые нужно назвать/добавить в существующие структуры.
EXTRA_FIELDS = [
    # CMap: промежутки, которые обнуляются при инициализации карты
    # (FUN_00424cc0, FUN_00590410, FUN_005939b0) - без них смещения не видны.
    ("CMap", 0x04, "mapFlags0", "int"),
    ("CMap", 0x08, "mapFlags1", "int"),
    ("CMap", 0x0C, "mapFlags2", "int"),
    ("CMap", 0x10, "mapFlags3", "int"),
    ("CMap", 0x1C, "mapFlags4", "int"),
    # 0x28 пропущен: там уже ushort mapFlags (0x29)
    ("CMap", 0x2C, "mapFlags6", "int"),
    ("CMap", 0x30, "mapFlags7", "int"),
    ("CMap", 0x34, "mapFlags8", "int"),
    ("CMap", 0x50, "mapFlags9", "int"),
    ("CMap", 0x54, "mapFlagsA", "int"),
    ("CMap", 0x58, "mapFlagsB", "int"),
    ("CMap", 0x5C, "mapFlagsC", "int"),
    ("CMap", 0x60, "mapFlagsD", "int"),
    ("CMap", 0x64, "mapFlagsE", "int"),
    ("CMap", 0x68, "mapFlagsF", "int"),
    ("CMap", 0x6C, "mapFlagsG", "int"),
    # CMapCell: байт базового света (пишет FUN_005906a0:404)
    ("CMapCell", 0x07, "light", "byte"),
]

# Класс функции меняется на безструктурный: строка остаётся в таблице, и
# ApplyMapTypes снимает старый тип `this`, оставшийся от прошлого прохода.
#
# Почему они не методы CMap (проверено дизассемблированием):
#   0x00427610 - 0x14/0x18 не используются, 0x20 читается как байты
#   0x00427e30 - 0x20 читается как байт-флаг, а не как указатель
#   0x005763e0 - смещения 0xCAC/0xCB5, чужой большой объект
#   0x005e9700 - mov ecx, esi (esi = глобальная карта); свой ECX - координата
# ПЕРЕПРОВЕРЕНО: 0x00595770 - это МЕТОД CMap (зовёт FUN_00592f10(this) и читает
#   this->x0_8/x1_8/y0_8/y1_8), класс восстановлен.
RECLASS = {
    "0x00427610": "CUnassigned",
    "0x00427e30": "CUnassigned",
    "0x005763e0": "CUnassigned",
    "0x005e9700": "CUnassigned",
}


def read_rows(path: Path):
    rows = []
    for line in path.read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        rows.append(line.split("\t"))
    return rows


def write_rows(path: Path, header: str, rows):
    out = io.StringIO()
    out.write(header + "\n")
    for r in rows:
        out.write("\t".join(r) + "\n")
    path.write_text(out.getvalue(), encoding="utf-8", newline="\n")


def main() -> int:
    # ---- 1. структуры -----------------------------------------------------
    srows = read_rows(STRUCTS)
    head = srows[0]
    body = srows[1:]
    body = [r for r in body if r[0].strip() != "CSceneRenderer"]
    body = [r for r in body if not (r[0].strip() == "CDisplay" and r[1].strip().lower() == "0x28b0")]
    extra_offsets = {(c, o) for c, o, _n, _t in EXTRA_FIELDS}
    body = [r for r in body
            if (r[0].strip(), int(r[1], 0)) not in extra_offsets]

    for off, name, typ in SCENE_RENDERER:
        body.append(["CSceneRenderer", "0x%04X" % off, name, typ])
    # рендерер вложен в сценовый объект по смещению 0x28b0
    body.append(["CDisplay", "0x28b0", "renderer", "CSceneRenderer"])
    for cls, off, name, typ in EXTRA_FIELDS:
        body.append([cls, "0x%02X" % off if off < 0x100 else "0x%04X" % off, name, typ])

    order = {c: i for i, c in enumerate(sorted({r[0] for r in body}))}
    body.sort(key=lambda r: (order[r[0]], int(r[1], 0)))
    write_rows(STRUCTS, "\t".join(head), body)
    print("structs: %d rows, %d classes" % (len(body), len(order)))

    # ---- 2. функции --------------------------------------------------------
    frows = read_rows(FUNCS)
    fhead = frows[0]
    fbody = frows[1:]
    seen = {}
    for r in fbody:
        if len(r) < 2:
            continue
        key = r[0].strip().lower()
        if key in seen:
            continue
        seen[key] = r
    for addr, cls in NEW_FUNCS.items():
        seen[addr.lower()] = [addr, cls]
    for addr, cls in RECLASS.items():
        seen[addr.lower()] = [addr, cls]
    out = sorted(seen.values(), key=lambda r: int(r[0], 0))
    write_rows(FUNCS, "\t".join(fhead), out)
    print("funcs: %d unique rows, %d classes" % (len(out), len({r[1] for r in out})))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
