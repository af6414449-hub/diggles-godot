#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Insert the recovered technique id -> name table into z28.md and report.md."""
from __future__ import annotations

import io
from pathlib import Path

ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")

TABLE = """
7. **Полный реестр: 37 техник, id = порядок регистрации** (`FUN_00457b90`).
   Извлечено скриптом `techniques_extract.py` из декомпиляции (имя объекта собрано из
   dword-непосредственных значений, которые компилятор записал прямо в коде):

   | id | техника | id | техника | id | техника |
   |---:|---|---:|---|---:|---|
   | 0 | `default` | 13 | `model_blend_envmap` | 26 | `shadow_blend` |
   | 1 | `interface_blend` | 14 | `model_additive_envmap` | 27 | `mouse_blend` |
   | 2 | `interface_additive` | 15 | `particle_blend` | 28 | `water_blend` |
   | 3 | `interface_blendq` | 16 | `particle_additive` | 29 | `sulfur_blend` |
   | 4 | `interface_additiveq` | 17 | `scape_fow` | 30 | `lava_blend` |
   | 5 | `interface_additive_filtered` | 18 | `scape_solid` | 31 | `interface_glow` |
   | 6 | `model_blend` | 19 | `scape_blend` | 32 | `obj_glow` |
   | 7 | `model_solid` | 20 | `scape_multi_urw` | 33 | `alpha_light` |
   | 8 | `model_solid_nozwrite` | 21 | `scape_multi_lav` | 34 | `model_solid_invalpha` |
   | 9 | `model_additive` | 22 | `scape_multi_lav_fow` | 35 | `nolight_noalpha` |
   | 10 | `model_additive_glow` | 23 | `sky_blend` | 36 | `interface_blend_filter` |
   | 11 | `model_blend_glow` | 24 | `sky_blend_multi` | — | — |
   | 12 | `model_blend_nozwrite` | 25 | `ground_blend` | — | — |

   (в реестре 37 записей: id 0…36.)
   ⇒ **Подстановки из п.6 получают смысл:** 7 = `model_solid` → 6 = `model_blend`;
   18 = `scape_solid` → 19 = `scape_blend`; 33 = `alpha_light` → 7 = `model_solid`.
   То есть «недоступная в этом контексте техника» заменяется на ближайшую «мягкую»:
   solid → blend, а `alpha_light` → `model_solid`.
   Evidence: `techniques_extract.py` (вывод), `FUN_00457b90_00457b90.c` (37 коммитов).
8. **Имена `water_mt0/mt1`, `lava_mt0/mt1`, `sulfur_m/mt1` в этот реестр НЕ входят** —
   они встречаются в коде exe отдельно (как строки), т.е. это другая таблица
   (вероятно, варианты материала жидкости, а не техники рендера). Не сопоставлены.
"""

OLD_ITEM6 = """6. **В потребителе (`FUN_00483d80`) та же таблица, но с тремя подстановками:**"""
ANCHOR = """   Evidence: `FUN_00483d80_00483d80.c:264-277`.
"""

for name in ("z28.md", "report.md"):
    p = ZONE / name
    txt = p.read_text(encoding="utf-8")
    if txt.count(ANCHOR) != 1:
        raise SystemExit(f"FAIL {name}: anchor count {txt.count(ANCHOR)}")
    txt = txt.replace(ANCHOR, ANCHOR + TABLE, 1)
    with io.open(p, "w", encoding="utf-8", newline="\n") as f:
        f.write(txt)
    print(f"{name}: patched, {len(txt.encode('utf-8'))} bytes")
