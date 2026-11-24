#!/usr/bin/env python3
"""Ставит пункты 9 и 10 в §0.19 очереди на место (после пункта 8)."""
from __future__ import annotations

from pathlib import Path

QUEUE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
             r"\docs\plan\queue-2026-11-19.md")

BLOCK_9 = """**9. Проход умеет снимать устаревший тип `this`.** Четыре функции, ошибочно
отнесённые к CMap в прошлом проходе, получили класс `CUnassigned`; скрипт
снимает с них прежний тип `this` и перевыгружает их заново
(в проходе, который их снял: `this reset: 5`; далее — 0, тип уже снят).
Без этого в выгрузке лежали бы файлы с неверной сигнатурой.

**10. Проход чистит выходную папку.** После экспорта скрипт удаляет `.c`-файлы,
которые не попали в текущий индекс (`stale removed: 577`), — иначе в выгрузке
копились бы файлы прошлых прогонов с устаревшими типами.

"""

MARKER = "**Что это меняет для порта.**"


def main() -> int:
    text = QUEUE.read_text(encoding="utf-8")
    # убрать прежнее (неверно расположенное) вхождение блока 9
    i = text.find("**9. Проход умеет снимать устаревший тип `this`.**")
    if i >= 0:
        j = text.find("неверной сигнатурой.\n", i)
        if j < 0:
            j = text.find("неверной сигнатурой.\n", i)
        j += len("неверной сигнатурой.\n")
        text = text[:i] + text[j:]
    # вставить перед «Что это меняет для порта»
    k = text.find(MARKER)
    if k < 0:
        print("marker not found")
        return 1
    text = text[:k] + BLOCK_9 + text[k:]
    QUEUE.write_text(text, encoding="utf-8", newline="")
    print("queue fixed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
