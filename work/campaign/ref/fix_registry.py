#!/usr/bin/env python3
"""Обновляет строку моей сессии в реестре параллельных сессий."""
from __future__ import annotations

from pathlib import Path

REG = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
           r"\docs\plan\parallel-sessions-2026-11-21.md")

OLD = "| **Реверс `Diggles.exe` (этот чат)** | `mvs_74f998f96a1b4662bec525ed481dd75a` | `docs/reverse-engineering/*`, `work/campaign/ref/*`; правка `docs/plan/queue-2026-11-19.md` §0.11 п.1, §0.15 и §0.18 — по фактам движка | идёт; §0.15 пересмотрен (масштаб высот, «стены = перепад высот» опровергнуто), добавлен §0.18 |"

NEW = ("| **Реверс `Diggles.exe` (этот чат)** | `mvs_74f998f96a1b4662bec525ed481dd75a` | "
       "`docs/reverse-engineering/*`, `work/campaign/ref/*`; правка `docs/plan/queue-2026-11-19.md` "
       "§0.11 п.1, §0.15, §0.18 и §0.19 — по фактам движка | идёт; §0.15 пересмотрен "
       "(масштаб высот, «стены = перепад высот» опровергнуто), §0.18 — рендер поверхности, "
       "§0.19 — типизация глобалов и рендер-кластера (81 структура / 766 полей, 609 функций "
       "выгружено в `work/campaign/ref/ghidra-out/typed2/`) |")


def main() -> int:
    text = REG.read_text(encoding="utf-8")
    if OLD not in text:
        print("row not found")
        return 1
    text = text.replace(OLD, NEW)
    REG.write_text(text, encoding="utf-8", newline="")
    print("registry updated")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
