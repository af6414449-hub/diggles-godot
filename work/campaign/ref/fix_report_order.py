#!/usr/bin/env python3
"""Чинит порядок пунктов 6/7 в §7.10 отчёта: блок 7 попал внутрь блока 6."""
from __future__ import annotations

from pathlib import Path

REPORT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
              r"\docs\reverse-engineering\diggles-exe-decompilation-2026-11-21.md")

BLOCK_7 = """**7. Проход снимает устаревший тип `this`.** Четыре функции, ошибочно отнесённые
к CMap в прошлом проходе, переведены в класс `CUnassigned`; скрипт снимает с них
прежний тип `this` и перевыгружает заново (в проходе, который их снял: `this reset: 5`;
далее — 0, тип уже снят). Без этого в выгрузке остались бы файлы с неверной
сигнатурой.
"""

HEAD_6 = "**6. Поправлены ошибочные назначения классов CMap**"
BODY_6 = """ — по дизассемблированию и по типизированному выводу `0x00427610`,
`0x00427e30`, `0x005763e0`, `0x005e9700` **не являются** методами CMap: они зовут
аксессор с **глобальной** картой (`FUN_00592f10(PTR_0077241c)`), а не со своим
`this`; либо читают `0x20` как байты; либо уходят за 0x200 (чужой объект).
Подтверждённые методы CMap (9): `0x004093f0` (геттер высоты), `0x00424cc0`,
`0x00590410`, `0x00592f10` (аксессор клетки), `0x005939b0`, `0x00595770`
(читает `this->x0_8/x1_8/y0_8/y1_8` и зовёт `FUN_00592f10(this)`),
`0x00593ec0`, `0x00594160` (Init), `0x005948b0` (Shut).
"""


def main() -> int:
    text = REPORT.read_text(encoding="utf-8")
    # убрать блок 7 из текущего места
    text = text.replace(BLOCK_7, "")
    # найти пункт 6 и заменить целиком (заголовок + тело + новый пункт 7)
    start = text.find(HEAD_6)
    if start < 0:
        print("head 6 not found")
        return 1
    end = text.find("\n\n---", start)
    if end < 0:
        end = len(text)
    text = text[:start] + HEAD_6 + BODY_6 + "\n" + BLOCK_7 + text[end:]
    REPORT.write_text(text, encoding="utf-8", newline="")
    print("report fixed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
