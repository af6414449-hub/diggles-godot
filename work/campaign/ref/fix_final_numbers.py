#!/usr/bin/env python3
"""Финальная правка чисел в §0.19 очереди, §7.10 отчёта и заметках."""
from __future__ import annotations

from pathlib import Path

ROOT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles")
QUEUE = ROOT / "docs" / "plan" / "queue-2026-11-19.md"
REPORT = ROOT / "docs" / "reverse-engineering" / "diggles-exe-decompilation-2026-11-21.md"
NOTES = ROOT / "work" / "campaign" / "ref" / "notes-typing-2026-11-21.md"

PAIRS = [
    ("349 функций с типизированным", "350 функций с типизированным"),
    ("349 функции с типизированным", "350 функции с типизированным"),
    ("606 функций выгружено", "609 функций выгружено"),
    ("349 функций с типизированным\n`this`, 606 функций", "350 функций с типизированным\n`this`, 609 функций"),
    ("349 функций с типизированным\n`this`, 606 функций выгружено", "350 функций с типизированным\n`this`, 609 функций выгружено"),
    ("349 функций с типизированным\n`this`, 606 функций выгружено (`ghidra-out/typed2/`).",
     "350 функций с типизированным\n`this`, 609 функций выгружено (`ghidra-out/typed2/`)."),
]

EXTRA_QUEUE = """
**10. Проход чистит выходную папку.** После экспорта скрипт удаляет `.c`-файлы,
которые не попали в текущий индекс (`stale removed: 577`), — иначе в выгрузке
копились бы файлы прошлых прогонов с устаревшими типами.
"""

EXTRA_REPORT = """
**8. Проход чистит выходную папку.** После экспорта удаляются `.c`-файлы, не
попавшие в текущий индекс (`stale removed: 577`), — иначе в выгрузке копились бы
файлы прошлых прогонов с устаревшими типами.
"""


def apply(path: Path, extra_after: str | None = None, extra: str = "") -> None:
    text = path.read_text(encoding="utf-8")
    n = 0
    for old, new in PAIRS:
        if old in text:
            text = text.replace(old, new)
            n += 1
    if extra_after and extra_after in text and extra.strip() not in text:
        text = text.replace(extra_after, extra_after + extra)
        n += 1
    path.write_text(text, encoding="utf-8", newline="")
    print("%s: %d replacements" % (path.name, n))


def main() -> int:
    apply(QUEUE, "далее — 0, тип уже снят). Без этого в выгрузке лежали бы файлы с\nневерной сигнатурой.\n", EXTRA_QUEUE)
    apply(REPORT, "далее — 0, тип уже снят). Без этого в выгрузке остались бы файлы с неверной\nсигнатурой.\n", EXTRA_REPORT)
    apply(NOTES)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
