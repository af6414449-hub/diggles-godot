#!/usr/bin/env python3
"""Вставляет §0.19 в очередь и §7.10 в основной отчёт декомпиляции.

Правка идёт построчно через Python: правка длинных русских фрагментов
инструментом поиска/замены в этом файле не срабатывает.
"""
from __future__ import annotations

from pathlib import Path

ROOT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles")
QUEUE = ROOT / "docs" / "plan" / "queue-2026-11-19.md"
REPORT = ROOT / "docs" / "reverse-engineering" / "diggles-exe-decompilation-2026-11-21.md"

QUEUE_SECTION = """
## 0.19 Типизация глобалов и рендер-кластера в Ghidra (21.11.2026, ночь)

Отчёт: `work/campaign/ref/notes-typing-2026-11-21.md`; таблицы
`work/campaign/ref/ghidra_structs.tsv` (81 класс / 766 полей),
`ghidra_funcs.tsv` (116 классов / 965 функций), `ghidra_globals.tsv` (1 глобал).

**1. Новый headless-проход `ApplyMapTypes.java`.** В отличие от прежнего
`ApplyStructs.java` (типизировал только `this` по RTTI/vtable) проход делает
три вещи: (1) расширенные типы полей (uint/byte/ushort/float/массивы/указатели
на структуры), (2) двухфазное построение структур — указатель может ссылаться на
структуру, объявленную ниже, (3) типизация глобальных синглтонов + выгрузка всех
функций, ссылающихся на типизированные глобалы.
Итог: **81 структура / 766 полей (0 пропущенных), 354 функции с типизированным
`this`, 609 функций выгружено** в `work/campaign/ref/ghidra-out/typed2/`.

**2. Глобал карты `DAT_0077241c` → `CMap *`.** После типизации в декомпиляции видно
`PTR_0077241c->heightBlocks`, `map->cells`, `map->cellCount`.
`FUN_00592f10` (аксессор клетки) — **метод CMap**:
`cell = map->cells + idx * 0x7C` (размер `CMapCell` = 0x7C),
`idx = (clamp(y) * map->mapWidth + clamp(x)) % map->cellCountTotal`,
клампы по `map->cellX0/cellY0/cellX1/cellY1` (`0x84/0x88/0x8C/0x90`).
`FUN_004093f0` (геттер высоты) — тоже метод CMap:
`map->heightBlocks->data[cell->heightBlockIndex]->heights[(y&7)<<3 | (x&7)]`.
Это **прямое подтверждение шкалы сетки 8×8** (логические координаты = мировые / 8).

**3. Раскладка CSceneRenderer исправлена полностью.** Прежняя запись `0x1024 level`
оказалась неверной: `0x1024` — **дефолтная текстура группы 7**. Подтверждено
`_eh_vector_constructor_iterator_((void *)(in_ECX + 8), 0x204, 8, …)`
(`FUN_004c4420:22`) и восемью записями дефолтных текстур
(`0x208 / 0x40C / 0x610 / 0x814 / 0xA18 / 0xC1C / 0xE20 / 0x1024`).
Итоговый размер структуры — **0x17388 байт**; четыре независимые проверки
сходимости буферов: `0x1378 + 0x9000 = 0xA378`, `0xA378 + 0x2000 = 0xC378`,
`0xC380 + 0x9000 = 0x15380`, `0x15380 + 0x2000 = 0x17380`.

**4. Рендерер вложен в сценовый объект по смещению `0x28B0`.**
`lea ecx, [esi + 0x28b0]; call 0x4c4420` (`FUN_00464780:79,83`) и
`lea ecx, [edi + 0x28b0]; call 0x4cde30` (`FUN_004653d0:0x46440B,0x464411`).
Контроль: `0x28B0 + 0x17388 = 0x19C38` — ровно начало полей `CDisplay`.
В `ghidra_structs.tsv` добавлено `CDisplay 0x28b0 renderer CSceneRenderer`.

**5. Таблица масок разобрана (важно для порта).** `FUN_004c4c50`:
группа = `(param_1 >> 5) & 7` (8 групп), база = `this + group * 0x204 + 8`;
в группе 2 варианта по 0x100, в каждом 16 слотов по 0x10; слот = {указатель на
массив номеров текстур, их количество}; `base + 0x200` = дефолтная текстура группы.
`param_1` (ushort): биты 0..4 — случайность (выбор варианта =
`(param_1 & 0x1F) % count`), биты 5..7 — группа, биты 8..15 — 4 уровня углов
по 2 бита (это байт `CHeightBlock + 0x54` = `cornerLevels`).

**6. Выбор текстуры земли (81 текстура).** `FUN_004c4ae0`:
`idx = (((p5&3)*3+(p4&3))*3+(p3&3))*3+(p2&3)` (0..80 = 3^4),
`tex = textures[textureIndex[idx] + ((idx | rand8) >> 8) % variants[idx]]`.
`param_6/param_7` — перестановка параметров (зеркало/поворот),
`param_9 != 0` — детерминированный выбор (без случайности).

**7. Поправлены ошибочные назначения классов.** Дизассемблирование показало, что
`0x00427610`, `0x00427e30`, `0x005763e0`, `0x00595770`, `0x005e9700` — **не** методы
CMap: их собственный `ECX` используется как координата, а в аксессор клетки
передаётся указатель извне (`mov ecx, ebx` / `mov ecx, esi`), либо смещения
уходят за 0x200 (чужой объект). Подтверждённые методы CMap: `0x004093f0`,
`0x00424cc0`, `0x00590410`, `0x00592f10`, `0x005939b0` + RTTI-именованные
`0x00593ec0`, `0x00594160` (Init), `0x005948b0` (Shut).

**8. Добавлено поле `CMapCell +0x07` — базовый свет клетки** (пишет
`FUN_005906a0:404`, обнуляет `CMap::Clear`). Плюс промежутки
`CMap 0x04..0x10, 0x1C, 0x2C..0x34, 0x50..0x6C` — чтобы смещения были видны.

**Что это меняет для порта.** Появились именованные поля, по которым переносится
логика: `map->cells`, `map->cellCount`, `map->mapWidth/Height`,
`map->cellX0/cellY0/cellX1/cellY1` (границы карты), `map->heightBlocks->data[i]->heights[…]`,
`cell->material`, `cell->digMarks`, `cell->light`, `cell->ownerIndex`,
`sub->cornerLevels`, `renderer->textures/textureCount/textureIndex/variants/defaultTexture`,
`renderer->maskGroups`, `renderer->wallVertices/wallIndices`,
`renderer->fogVertices/fogIndices`.

**Открыто.** Смысл 2-битного «уровня угла» (`значение & 3`) в маске;
расхождение двух шкал высоты (логика отдаёт «уровень», рендер считает `7.0 + 0.5*v`);
семантика выбора зоны в `sm_draw_stone -exlimit`.
"""

REPORT_SECTION = """
## 7.10 Типизация глобалов и рендер-кластера (21.11.2026, ночь)

Отчёт: `work/campaign/ref/notes-typing-2026-11-21.md`.

**1. Новый проход `ApplyMapTypes.java`** (headless, `ghidra/ApplyMapTypes.java`):
двухфазное построение структур, расширенные типы полей, типизация глобальных
синглтонов и выгрузка всех функций, ссылающихся на них.
Результат: 81 структура / 766 полей / 0 пропущенных, 354 функции с типизированным
`this`, 609 функций выгружено (`ghidra-out/typed2/`).

**2. Глобал карты `DAT_0077241c` → `CMap *`.** В декомпиляции появились
`map->cells`, `map->cellCount`, `map->mapWidth`, `map->cellX0/cellY0/cellX1/cellY1`,
`map->heightBlocks->count/data`, `cell->material`, `cell->digMarks`,
`sub->heights[(y&7)<<3 | (x&7)]`.
`FUN_00592f10` — аксессор клетки, метод CMap: `cell = map->cells + idx * 0x7C`
(размер `CMapCell` = 0x7C). `FUN_004093f0` — геттер высоты, тоже метод CMap:
`map->heightBlocks->data[cell->heightBlockIndex]->heights[(y&7)<<3 | (x&7)]`.

**3. Раскладка `CSceneRenderer` (0x17388 байт) — исправлена.** Прежнее поле
`0x1024 level` неверно: это **дефолтная текстура группы 7** (восемь записей:
`0x208/0x40C/0x610/0x814/0xA18/0xC1C/0xE20/0x1024`; группы — 8 штук по 0x204 байт,
`_eh_vector_constructor_iterator_((void *)(in_ECX + 8), 0x204, 8, …)`).
Буферы: `vertBufA float[9216]` @`0x1378`, `idxBufA ushort[4096]` @`0xA378`,
`vertBufB float[9216]` @`0xC380`, `idxBufB ushort[4096]` @`0x15380`,
счётчики @`0xC378/0xC37C/0x17380/0x17384`. Четыре проверки сходимости размера.

**4. Рендерер — член сценового объекта по смещению `0x28B0`:**
`lea ecx, [esi + 0x28b0]` перед `call 0x4c4420` (`FUN_00464780`) и
`lea ecx, [edi + 0x28b0]` перед `call 0x4cde30` (`FUN_004653d0`);
`0x28B0 + 0x17388 = 0x19C38` — начало полей `CDisplay`.

**5. Таблица масок и выбор текстуры.** Группа = `(param_1 >> 5) & 7`;
база группы = `this + group * 0x204 + 8`; 2 варианта по 0x100, 16 слотов по 0x10,
слот = {указатель на массив номеров текстур, количество};
`base + 0x200` — дефолтная текстура группы. `param_1`: биты 0..4 — случайность
(`(param_1 & 0x1F) % count`), 5..7 — группа, 8..15 — уровни углов
(байт `CHeightBlock + 0x54`).
Выбор текстуры: `idx = (((p5&3)*3+(p4&3))*3+(p3&3))*3+(p2&3)` (0..80 = 3^4),
`tex = textures[textureIndex[idx] + ((idx | rand8) >> 8) % variants[idx]]`.

**6. Поправлены ошибочные назначения классов CMap** — по дизассемблированию
`0x00427610`, `0x00427e30`, `0x005763e0`, `0x00595770`, `0x005e9700` не являются
методами CMap (их `ECX` — координата, а в аксессор передаётся чужой указатель).
"""


def insert_before(path: Path, marker: str, text: str) -> bool:
    lines = path.read_text(encoding="utf-8").splitlines(keepends=True)
    for i, line in enumerate(lines):
        if line.startswith(marker):
            block = text.strip("\n").splitlines(keepends=True)
            out = []
            for b in block:
                out.append(b if b.endswith("\n") else b + "\n")
            out.append("\n")
            out.append("---\n\n")
            lines[i:i] = out
            path.write_text("".join(lines), encoding="utf-8", newline="")
            return True
    return False


def main() -> int:
    ok_q = insert_before(QUEUE, "## 0.1 ", QUEUE_SECTION)
    print("queue §0.19 inserted:", ok_q)
    ok_r = insert_before(REPORT, "## 8. ", REPORT_SECTION)
    print("report §7.10 inserted:", ok_r)
    return 0 if (ok_q and ok_r) else 1


if __name__ == "__main__":
    raise SystemExit(main())
