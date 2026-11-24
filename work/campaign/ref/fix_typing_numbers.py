#!/usr/bin/env python3
"""Правка чисел в §0.19 очереди и §7.10 отчёта по итогам финального прохода."""
from __future__ import annotations

from pathlib import Path

ROOT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles")
QUEUE = ROOT / "docs" / "plan" / "queue-2026-11-19.md"
REPORT = ROOT / "docs" / "reverse-engineering" / "diggles-exe-decompilation-2026-11-21.md"

REPLACEMENTS = [
    ("354 функции с типизированным\n`this`, 609 функций выгружено",
     "349 функций с типизированным\n`this`, 606 функций выгружено"),
    ("81 структура / 766 полей (0 пропущенных), 354 функции",
     "81 структура / 766 полей (0 пропущенных), 349 функций"),
    ("Итог: **81 структура / 766 полей (0 пропущенных), 354 функции с типизированным\n`this`, 609 функций выгружено** в `work/campaign/ref/ghidra-out/typed2/`.",
     "Итог: **81 структура / 766 полей (0 пропущенных), 349 функций с типизированным\n`this`, 606 функций выгружено** в `work/campaign/ref/ghidra-out/typed2/`."),
    ("Результат: 81 структура / 766 полей / 0 пропущенных, 354 функции с типизированным\n`this`, 609 функций выгружено (`ghidra-out/typed2/`).",
     "Результат: 81 структура / 766 полей / 0 пропущенных, 349 функций с типизированным\n`this`, 606 функций выгружено (`ghidra-out/typed2/`)."),
]

EXTRA_QUEUE = """
**9. Проход умеет снимать устаревший тип `this`.** Пять функций, ошибочно
отнесённых к CMap в прошлом проходе, получили класс `CUnassigned`; скрипт
снимает с них прежний тип `this` и перевыгружает их заново
(в логе: `this reset: 5`). Без этого в выгрузке лежали бы файлы с
неверной сигнатурой.
"""

EXTRA_REPORT = """
**7. Проход снимает устаревший тип `this`.** Функции, ошибочно отнесённые к CMap
в прошлом проходе, переведены в класс `CUnassigned`; скрипт снимает с них прежний
тип `this` и перевыгружает заново (`this reset: 5`).
"""


def apply(path: Path, pairs, extra_after: str, extra: str) -> None:
    text = path.read_text(encoding="utf-8")
    changed = 0
    for old, new in pairs:
        if old in text:
            text = text.replace(old, new)
            changed += 1
    if extra_after in text and extra.strip() not in text:
        text = text.replace(extra_after, extra_after + extra)
        changed += 1
    path.write_text(text, encoding="utf-8", newline="")
    print("%s: %d replacements" % (path.name, changed))


def main() -> int:
    apply(QUEUE, REPLACEMENTS,
          "**Открыто.** Смысл 2-битного «уровня угла» (`значение & 3`) в маске;",
          EXTRA_QUEUE)
    apply(REPORT, REPLACEMENTS,
          "**6. Поправлены ошибочные назначения классов CMap**",
          EXTRA_REPORT)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
