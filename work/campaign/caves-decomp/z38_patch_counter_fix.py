# -*- coding: utf-8 -*-
"""З38 (исправление): пересчитать счётчики инвентаря без двойного счёта."""
import io, re
from pathlib import Path

ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")
REPORT = ZONE / "report.md"
txt = io.open(REPORT, encoding="utf-8").read()
lines = txt.split("\n")

start = None
for i, l in enumerate(lines):
    if l.startswith("| # | Точка решения | Где в движке | Статус | Источник |"):
        start = i
        break
end = start
for i in range(start + 1, len(lines)):
    if lines[i].startswith("**Итого:"):
        end = i
        break


def status(cols):
    s = cols[3]
    if "ЧАСТИЧНО" in s:
        return "ЧАСТИЧНО"
    if "ЗАКРЫТО" in s:
        return "ЗАКРЫТО"
    return "ОТКРЫТО"


all_rows, sub_rows = [], []
for i, l in enumerate(lines):
    if re.match(r"^\| D\d+ \|", l):
        cols = [c.strip() for c in l.strip().strip("|").split("|")]
        if len(cols) == 5 and start < i < end:
            all_rows.append(cols)
            if cols[0] not in ("D10", "D24"):
                sub_rows.append(cols)


def tally(rows):
    c = {"ЗАКРЫТО": 0, "ЧАСТИЧНО": 0, "ОТКРЫТО": 0}
    for cols in rows:
        c[status(cols)] += 1
    return c


c1, c2 = tally(all_rows), tally(sub_rows)
print("30 точек:", c1, "сумма", sum(c1.values()))
print("28 пунктов:", c2, "сумма", sum(c2.values()))

tot = sum(c1.values())
pc = lambda k: round(100.0 * c1[k] / tot)
new_tot = ("**Итого: %d точек — ЗАКРЫТО %d, ЧАСТИЧНО %d, ОТКРЫТО %d** (по строкам: закрыто\n"
           "%d %%, частично %d %%, открыто %d %%)."
           % (tot, c1["ЗАКРЫТО"], c1["ЧАСТИЧНО"], c1["ОТКРЫТО"],
              pc("ЗАКРЫТО"), pc("ЧАСТИЧНО"), pc("ОТКРЫТО")))
txt, n = re.subn(r"\*\*Итого: \d+ точек — ЗАКРЫТО \d+, ЧАСТИЧНО \d+, ОТКРЫТО \d+\*\* \(по строкам: закрыто\n\d+ %, частично \d+ %, открыто \d+ %\)\.",
                 lambda m: new_tot.replace("\\", "\\\\"), txt, count=1)
if n != 1:
    raise SystemExit("Итого не заменён")

new_cov = ("**Новое покрытие: ЗАКРЫТО %d, ЧАСТИЧНО %d, ОТКРЫТО %d** из %d оставшихся\n"
           "пунктов (D10 и D24 сняты как ложные следствия; D25 закрыт в З37 —\n"
           "отсечения пирамидой видимости нет, видимая область = проекция камеры\n"
           "на z=0 → полигон → список отрезков клеток; D26 закрыт в З38 — это\n"
           "id текстурных стадий 17–22, а не имена техник)."
           % (c2["ЗАКРЫТО"], c2["ЧАСТИЧНО"], c2["ОТКРЫТО"], sum(c2.values())))
txt, n = re.subn(r"\*\*Новое покрытие: ЗАКРЫТО \d+, ЧАСТИЧНО \d+, ОТКРЫТО \d+\*\* из \d+ оставшихся\nпунктов \(D10 и D24 сняты как ложные следствия; D25 закрыт в З37 —\nотсечения пирамидой видимости нет, видимая область = проекция камеры\nна z=0 → полигон → список отрезков клеток\)\.",
                 lambda m: new_cov.replace("\\", "\\\\"), txt, count=1)
if n != 1:
    print("Новое покрытие: уже обновлено (пропуск)")

with io.open(REPORT, "w", encoding="utf-8", newline="\n") as f:
    f.write(txt)
print("ok")
