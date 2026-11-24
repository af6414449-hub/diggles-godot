# -*- coding: utf-8 -*-
"""З38: закрыть D26 и пересчитать счётчики инвентаря по фактическим строкам таблицы."""
import io, re
from pathlib import Path

ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")
REPORT = ZONE / "report.md"

txt = io.open(REPORT, encoding="utf-8").read()
lines = txt.split("\n")

# ---- 1. найти главную таблицу D (строки с 5 колонками "| D<num> | ... |") ----
main_rows = []
for i, l in enumerate(lines):
    if re.match(r"^\| D\d+ \|", l):
        cols = [c.strip() for c in l.strip().strip("|").split("|")]
        if len(cols) == 5:
            main_rows.append((i, l, cols))

# строка-дубликат из второй таблицы (колонки "было"/"стало") — исключаем по заголовку
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
main_rows = [(i, l, c) for (i, l, c) in main_rows if start < i < end]
print("строк главной таблицы:", len(main_rows))


def status(cols):
    s = cols[3]
    if "ЧАСТИЧНО" in s:
        return "ЧАСТИЧНО"
    if "ЗАКРЫТО" in s:
        return "ЗАКРЫТО"
    return "ОТКРЫТО"


counts = {"ЗАКРЫТО": 0, "ЧАСТИЧНО": 0, "ОТКРЫТО": 0}
for (i, l, c) in main_rows:
    counts[status(c)] += 1
print("до правки:", counts)

# ---- 2. закрыть D26 ----
d26_old = ("| D26 | Имена `water_mt0/1`, `lava_mt0/1`, `sulfur_m/mt1` | вне реестра 37 | "
           "**ОТКРЫТО** | З28 п.8 |")
d26_new = ("| D26 | Имена `water_mt0/1`, `lava_mt0/1`, `sulfur_mt0/mt1` | "
           "`FUN_004564c0` (текстурные стадии 17–22) | **ЗАКРЫТО** | З28 п.8, З38 |")
if txt.count(d26_old) != 1:
    raise SystemExit("D26 row not found/ambiguous")
txt = txt.replace(d26_old, d26_new, 1)

# ---- 3. буллет D26 в разделе «что осталось неизвестным» ----
b_old = """* **D26 — `water_mt0/1`, `lava_mt0/1`, `sulfur_m/mt1`.** В реестре 37 техник их
  нет ⇒ это другая таблица (вероятно, варианты материала жидкости).
  **Как проверить:** найти их употребление — искать в коде чтение строки,
  где она сравнивается с именем материала."""
b_new = """* **D26 — `water_mt0/1`, `lava_mt0/1`, `sulfur_mt0/mt1`.** **ЗАКРЫТО в З38:** это
  не реестр техник, а реестр **текстурных стадий** (`FUN_004564c0`): `water_mt0`=17,
  `water_mt1`=18, `sulfur_mt0`=19, `sulfur_mt1`=20, `lava_mt0`=21, `lava_mt1`=22 —
  они подставляются в TextStage0/TextStage1 техник `water_blend`(28), `sulfur_blend`(29),
  `lava_blend`(30). Полные таблицы 24 стадий и 37 техник — в З38."""
if txt.count(b_old) != 1:
    raise SystemExit("D26 bullet not found/ambiguous")
txt = txt.replace(b_old, b_new, 1)

# ---- 4. пересчёт счётчиков по фактическим строкам ----
lines2 = txt.split("\n")
for i, l in enumerate(lines2):
    if re.match(r"^\| D\d+ \|", l):
        cols = [c.strip() for c in l.strip().strip("|").split("|")]
        if len(cols) == 5 and start < i < end:
            s = status(cols)
            if s == "ЗАКРЫТО":
                counts["ЗАКРЫТО"] += 1
            elif s == "ЧАСТИЧНО":
                counts["ЧАСТИЧНО"] += 1
            else:
                counts["ОТКРЫТО"] += 1
print("после правки:", counts)

# главный «Итого»
old_tot = "**Итого: 30 точек — ЗАКРЫТО 20, ЧАСТИЧНО 6, ОТКРЫТО 4** (по строкам: закрыто\n67 %, частично 20 %, открыто 13 %)."
tot = counts["ЗАКРЫТО"] + counts["ЧАСТИЧНО"] + counts["ОТКРЫТО"]
pc = lambda k: round(100.0 * counts[k] / tot)
new_tot = ("**Итого: %d точек — ЗАКРЫТО %d, ЧАСТИЧНО %d, ОТКРЫТО %d** (по строкам: закрыто\n"
           "%d %%, частично %d %%, открыто %d %%)."
           % (tot, counts["ЗАКРЫТО"], counts["ЧАСТИЧНО"], counts["ОТКРЫТО"],
              pc("ЗАКРЫТО"), pc("ЧАСТИЧНО"), pc("ОТКРЫТО")))
if txt.count(old_tot) != 1:
    raise SystemExit("Итого line not found")
txt = txt.replace(old_tot, new_tot, 1)

# «Новое покрытие» (28 пунктов = таблица минус D10 и D24)
sub = {"ЗАКРЫТО": 0, "ЧАСТИЧНО": 0, "ОТКРЫТО": 0}
for i, l in enumerate(lines2):
    if re.match(r"^\| D\d+ \|", l):
        cols = [c.strip() for c in l.strip().strip("|").split("|")]
        if len(cols) == 5 and start < i < end:
            num = cols[0]
            if num in ("D10", "D24"):
                continue
            sub[status(cols)] += 1
print("28-пунктовый счётчик:", sub, "всего", sum(sub.values()))
old_cov = """**Новое покрытие: ЗАКРЫТО 21, ЧАСТИЧНО 6, ОТКРЫТО 1** из 28 оставшихся
пунктов (D10 и D24 сняты как ложные следствия; D25 закрыт в З37 —
отсечения пирамидой видимости нет, видимая область = проекция камеры
на z=0 → полигон → список отрезков клеток)."""
new_cov = """**Новое покрытие: ЗАКРЫТО %d, ЧАСТИЧНО %d, ОТКРЫТО %d** из %d оставшихся
пунктов (D10 и D24 сняты как ложные следствия; D25 закрыт в З37 —
отсечения пирамидой видимости нет, видимая область = проекция камеры
на z=0 → полигон → список отрезков клеток; D26 закрыт в З38 — это
id текстурных стадий 17–22, а не имена техник).""" % (
    sub["ЗАКРЫТО"], sub["ЧАСТИЧНО"], sub["ОТКРЫТО"], sum(sub.values()))
if txt.count(old_cov) != 1:
    raise SystemExit("Новое покрытие not found")
txt = txt.replace(old_cov, new_cov, 1)

with io.open(REPORT, "w", encoding="utf-8", newline="\n") as f:
    f.write(txt)
print("report.md обновлён:", len(txt.encode("utf-8")), "байт,", len(txt.splitlines()), "строк")
