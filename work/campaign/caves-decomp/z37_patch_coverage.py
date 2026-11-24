# -*- coding: utf-8 -*-
"""Обновляет итоговый счётчик покрытия в З32 после закрытия D25 (З37)."""
import io
from pathlib import Path

ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")
REPORT = ZONE / "report.md"
Z32 = ZONE / "z32.md"

OLD = """**Новое покрытие: ЗАКРЫТО 20, ЧАСТИЧНО 6, ОТКРЫТО 2** из 28 оставшихся
пунктов (D10 и D24 сняты как ложные следствия; D25 переформулирован)."""

NEW = """**Новое покрытие: ЗАКРЫТО 21, ЧАСТИЧНО 6, ОТКРЫТО 1** из 28 оставшихся
пунктов (D10 и D24 сняты как ложные следствия; D25 закрыт в З37 —
отсечения пирамидой видимости нет, видимая область = проекция камеры
на z=0 → полигон → список отрезков клеток)."""

for path in (Z32, REPORT):
    txt = io.open(path, encoding="utf-8").read()
    n = txt.count(OLD)
    if n == 0:
        print(f"{path.name}: строка не найдена (возможно, уже обновлена)")
        continue
    if n != 1:
        raise SystemExit(f"{path.name}: неоднозначно ({n})")
    txt = txt.replace(OLD, NEW, 1)
    with io.open(path, "w", encoding="utf-8", newline="\n") as f:
        f.write(txt)
    print(f"{path.name}: счётчик покрытия обновлён")
