# -*- coding: utf-8 -*-
"""Помечает З31 как исправленную З36 (семантика полей записи техники)."""
import io
from pathlib import Path

ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")
REPORT = ZONE / "report.md"
Z31 = ZONE / "z31.md"

MARK = "<!-- Z31-SUPERSEDED-BY-Z36 -->"

NOTE = """
<!-- Z31-SUPERSEDED-BY-Z36 -->
> **ИСПРАВЛЕНО З36.** Гипотеза «+0x20 = режим смешивания, +0x2C = alpha test,
> +0x44 = класс материала» **неверна**. Имена полей взяты из самого exe —
> из парсера/экспортёра определений техник (`FUN_0045c970`, `FUN_0045b7b0`):
>
> | смещение | настоящее имя |
> |---|---|
> | +0x00 | ZEnable |
> | +0x04 | ZWriteEnable |
> | +0x08 | ZFuncMode (D3DCMP) |
> | +0x0C | AlphaEnable |
> | +0x10 | AlphaTestEnable |
> | +0x14 | AlphaFuncMode (D3DCMP) |
> | +0x18 | AlphaRefValue |
> | +0x1C | **SrcBlendMode** |
> | +0x20 | **DestBlendMode** |
> | +0x24 | SpecularEnable |
> | +0x28 | CullMode |
> | +0x2C | Lighting |
> | +0x30 | GlowEnable |
> | +0x34 | GlowSize |
> | +0x38 | GlowColor |
> | +0x3C | EnvMapEnable |
> | +0x44…+0x60 | TextStage0…TextStage7 (id материала) |
>
> Смешивание задаётся **парой** (Src, Dest): `(2,1)` = opaque, `(5,6)` = alpha-blend,
> `(5,2)` = additive. `+0x44` — не «класс материала», а **ссылка на материал
> текстурной стадии 0** (в игре используются только 2 стадии). Подробности — З36.

"""

OLD_1 = """3. **Поля, которые читает движок, а не порт:**
   `+0x04` (0 ⇒ «шейдера нет», `param_1[2] = 0x15`),
   `+0x0C` (признак настоящего шейдера, влияет на ключ сортировки),
   `+0x20` (значение 1 ⇒ особый порядок отрисовки),"""

NEW_1 = """3. **Поля, которые читает движок, а не порт:**
   `+0x04` (**ZWriteEnable**; 0 ⇒ другая ветка вывода во всех 8 функциях
   применения техники — см. З36),
   `+0x0C` (**AlphaEnable**; 0 ⇒ «настоящего шейдера нет», влияет на ключ
   сортировки),
   `+0x20` (**DestBlendMode**; ≠ 1 (ZERO) ⇒ непрозрачный ⇒ особый порядок
   отрисовки — см. З36),"""

OLD_2 = """1. **Точная семантика полей +0x08, +0x10, +0x14, +0x18, +0x1C, +0x20, +0x24,
   +0x28, +0x2C, +0x44.**"""

NEW_2 = """1. ~~**Точная семантика полей +0x08, +0x10, +0x14, +0x18, +0x1C, +0x20, +0x24,
   +0x28, +0x2C, +0x44.**~~ **РАЗОБРАНО В З36** (имена полей получены из
   парсера/экспортёра определений техник; осталось неясным только поле `+0x40`
   и порядок регистрации имён материалов). Исходный текст гипотезы:"""

for path in (Z31, REPORT):
    txt = io.open(path, encoding="utf-8").read()
    if MARK in txt:
        print(f"{path.name}: уже помечено, пропуск")
        continue
    n1 = txt.count(OLD_1)
    n2 = txt.count(OLD_2)
    if n1 != 1 or n2 != 1:
        raise SystemExit(f"{path.name}: FAIL n1={n1} n2={n2}")
    txt = txt.replace(OLD_1, NEW_1, 1)
    txt = txt.replace(OLD_2, NEW_2, 1)
    # плашка сразу после заголовка "## 9. Что осталось неизвестным (и как проверить)"
    anchor = "## 9. Что осталось неизвестным (и как проверить)"
    if txt.count(anchor) != 1:
        raise SystemExit(f"{path.name}: FAIL anchor")
    txt = txt.replace(anchor, anchor + "\n" + NOTE.rstrip() + "\n", 1)
    with io.open(path, "w", encoding="utf-8", newline="\n") as f:
        f.write(txt)
    print(f"{path.name}: помечено З31-SUPERSEDED-BY-Z36")
