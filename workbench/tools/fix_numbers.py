# -*- coding: utf-8 -*-
"""Update the measured benchmark numbers in the result report."""
REPORT = (r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\docs"
          r"\reverse-engineering\agent-result-walkmap-performance-2026-11-19.md")

with open(REPORT, "r", encoding="utf-8", newline="") as handle:
    text = handle.read()

OLD_BENCH = """BENCH_COMPARE repeats=3 strikes=273 accepted=273 byte_changing=141
BENCH_COMPARE full    total_us=14186443 avg_us=51964 max_us=135889 height_calls=1804460 gate_calls=294544 cell_calls=0 rebuilt=289114
BENCH_COMPARE cached  total_us=2168763  avg_us=7944  max_us=20504  height_calls=86624   gate_calls=558    cell_calls=0 rebuilt=199840 skipped=89946 speedup=6.54x
BENCH_COMPARE bulk    total_us=2008765  avg_us=7358  max_us=17069  height_calls=0       gate_calls=558    cell_calls=1392 rebuilt=199840 skipped=89946 speedup=7.06x
BENCH_COMPARE_DONE assertions=12 failures=0"""

NEW_BENCH = """BENCH_COMPARE repeats=5 strikes=273 accepted=273 byte_changing=141
BENCH_COMPARE full    total_us=9789464  avg_us=35858 max_us=94158  height_calls=1804460 gate_calls=294544 cell_calls=0    rebuilt=289114
BENCH_COMPARE cached  total_us=1685194  avg_us=6172  max_us=17612  height_calls=86624   gate_calls=1326   cell_calls=0    rebuilt=199840 skipped=89946 speedup=5.81x
BENCH_COMPARE bulk    total_us=1544871  avg_us=5658  max_us=11039  height_calls=0       gate_calls=1326   cell_calls=1392 rebuilt=199840 skipped=89946 speedup=6.34x
BENCH_COMPARE host_call_reduction cached=20.8x bulk=1804460.0x
BENCH_COMPARE_DONE assertions=20 failures=0"""

OLD_SPREAD = ("Разброс между повторами: `full` 12.9\u201315.8 с, `cached` 2.11\u20132.65 с, "
              "`bulk` 1.82\u20132.26 с \u2014 аппаратный шум\n"
              "не влияет на вывод: ускорение 6.5\u20137.1x.")

NEW_SPREAD = ("Разброс между пятью прогонами: `full` 9.29\u201310.56 с, `cached` 1.68\u20131.79 с, "
              "`bulk` 1.45\u20131.65 с. Аппаратный шум\n"
              "меняет отношение незначительно: ускорение в этом прогоне 5.2\u20136.3x; структурные показатели\n"
              "(число вызовов хоста, пересчитанные samples, количество вызовов клетки) от нагрузки не зависят.")

OLD_RECO = ("Рекомендация: **`bulk` как основной режим** (7.06x), `cached` \u2014 как вариант без единой новой строки в\n"
            "`native_terrain_state.gd` (6.54x, изменяются только два файла).")

NEW_RECO = ("Рекомендация: **`bulk` как основной режим** (6.34x), `cached` \u2014 как вариант без единой новой строки в\n"
            "`native_terrain_state.gd` (5.81x, изменяются только два файла).")

PAIRS = [
    ("выигрыш от него \u2014 7.06x против 6.54x.",
     "выигрыш от него \u2014 6.34x против 5.81x."),
    (OLD_BENCH, NEW_BENCH),
    ("* `gate_calls` \u2014 294 544 \u2192 558: gate-\u043a\u043b\u0435\u0442\u043a\u0438 \u0447\u0438\u0442\u0430\u044e\u0442\u0441\u044f \u043e\u0434\u0438\u043d \u0440\u0430\u0437 \u0437\u0430 \u0432\u0441\u044e \u0441\u0435\u0440\u0438\u044e, \u0430 \u043d\u0435 \u043d\u0430 \u043a\u0430\u0436\u0434\u044b\u0439 sample.",
     "* `gate_calls` \u2014 294 544 \u2192 1 326: gate-\u043a\u043b\u0435\u0442\u043a\u0430 \u0447\u0438\u0442\u0430\u0435\u0442\u0441\u044f \u043e\u0434\u0438\u043d \u0440\u0430\u0437 \u0437\u0430 \u0432\u0441\u044e \u0441\u0435\u0440\u0438\u044e \u0438 \u043f\u0435\u0440\u0435\u0447\u0438\u0442\u044b\u0432\u0430\u0435\u0442\u0441\u044f \u0442\u043e\u043b\u044c\u043a\u043e \u0434\u043b\u044f \u0437\u0430\u043c\u0435\u043d\u0451\u043d\u043d\u044b\u0445 \u043a\u043b\u0435\u0442\u043e\u043a (\u043f\u0440\u0438 \u0432\u043e\u0437\u0434\u0443\u0448\u0435\u043d\u043d\u043e\u0439 \u0441\u0442\u0430\u0442\u044c\u0438 \u0433\u0435\u0439\u0442\u0430)."),
    (OLD_SPREAD, NEW_SPREAD),
    (OLD_RECO, NEW_RECO),
    ("Без него остаётся режим `cached` (6.54x)",
     "Без него остаётся режим `cached` (5.81x)"),
]

for old, new in PAIRS:
    count = text.count(old)
    if count != 1:
        raise SystemExit("expected 1 occurrence, got %d for: %r" % (count, old[:70]))
    text = text.replace(old, new)

with open(REPORT, "w", encoding="utf-8", newline="") as handle:
    handle.write(text)
print("REPORT_NUMBERS_UPDATED bytes=%d" % len(text))
