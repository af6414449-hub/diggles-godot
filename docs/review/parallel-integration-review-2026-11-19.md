# Параллельная интеграция: аудит ревью-ревью (2026-11-19)

**Роль:** Verifier (read-only аудит). **Дата:** 2026-11-19, 20:0x MSK.
**Объём:** сверка состояния двух деревьев, проверка применимости патчей, независимый
прогон self-test-ов, характеризация остаточного падения, единый план интеграции.

**Все эксперименты** выполнены в `Minimax\Diggles\review-tmp\`.
**Живой проект `ChatGPT\Diggles` не изменялся ревьюером** — только чтение
(проверено по SHA-256 до и после; см. §2.3).

---

## 1. Краткий вердикт

1. **Walkmap-оптимизация УЖЕ в живом проекте** — побайтово, не «не применена», как
   утверждала сводка. `godot/scripts/native_walkmap.gd` в live идентичен
   workbench-версии оптимизации (446 строк). Применять `walkmap-performance.patch`
   **не нужно и нельзя** — он конфликтует (3 файла, все хунки не матчатся).
2. **Хомячий пакет полностью поглощён** живым проектом: 19 из 19 файлов присутствуют,
   изменённых строк 0; `models/native_hamster_clips.json` JSON-эквивалентен патчу
   (различие только в завершающем переводе строки). Повторное применение не нужно.
3. **Фикс факела и фикс collision к моменту отчёта применены в живом проекте**
   (родитель применил в 20:00; подтверждено по SHA-256 и по прогону).
   Torch-фикс и оба torch-теста в live **побайтово совпадают** с деревом Minimax.
4. **Прогон 45 self-test-ов на объединённом дереве: 45 тестов, 1 падение** —
   `native_dig_queue_self_test`. Расхождений с заявленной базой (45/1) нет.
   На pristine-дереве (до правок) — 4 падения, т.е. правки дали −3.
5. **Гипотеза брифа о `native_dig_next` ОПРОВЕРГНУТА.** Порядок раскопок
   **правильный**: (2,15) → (1,15) → (2,16). Ошибка в том, что `dig_selection_history`
   записывает только 1 из 3 выборок: ветка `DWARF_DIG_STANCE_RETAINED`
   (`multiplayer_test.gd:3239-3247`) не вызывает `dig_selection_history.append()`.
   Это баг **инструментации теста**, а не ранжирования.
6. **Патч walkmap не самодостаточен**: он меняет сигнатуру
   `rebuild_after_strike` (4 → 5 аргументов), но не меняет вызывающий код в
   `multiplayer_test.gd:611`. Без этой пары проект не компилируется
   (`Expected 4 argument(s)`). В live уже есть и то, и другое.
7. **Риск «свет в 255 раз ярче» — измерен и НЕ подтверждён как вспышка**:
   в области факела яркость выросла в 1.95× (mean), максимум 219/255 — без клиппинга.
   Регрессионный кадр уже существует (`far_torch_lit.png` vs `far_torch_unpatched_lit.png`).
8. **Бенчмарк walkmap независимо воспроизведён**: 5.80× (cached) и 6.59× (bulk)
   против заявленных 5.81× / 6.34×; вызовы хоста 1 804 460 → 86 624 → 0,
   `assertions=20 failures=0`. **Эквивалентность на живом коде: `assertions=4369`.**
9. **Самокоррекция:** первоначальная интерпретация разницы `strike_ms` как эффекта
   walkmap была **ошибочной** — все три дерева содержат идентичный walkmap-код,
   разница была артефактом конкурентной нагрузки. Исправлено в §5.4; вывод о
   влиянии walkmap на end-to-end задержку удара **не делается**.

**ВЕРДИКТ: PARTIAL** — интеграция проверена и подтверждена; не проверено только то,
что нельзя проверить в этом окружении: реальный GPU-render на Android-устройстве
(все кадры — headless/OpenGL-software на Windows), и поведение на физическом устройстве.

---

## 2. Состояние двух деревьев

### 2.1 Diff по SHA-256 (`scripts/ tools/ models/ shaders/ scenes/`)

Пересчёт выполнен в 20:01:11 и повторно в **20:23**, **после** применения родителем
правок в 20:00 и последующей синхронизации Codex'а. В 20:01 расхождений было 9,
в 20:23 — **12**, но состав изменился: Codex за это время перенёс story-sequencer
в Minimax-дерево, поэтому исчезли 3 «ONLY_LIVE» расхождения и появились 3 `.uid`-файла
story-sequencer'а.

**Финальный пересчёт (20:23): live 297 файлов, Minimax 308 файлов, 12 расхождений.**

| # | Расхождение | Причина |
|---|---|---|
| 1 | `scripts/multiplayer_test.gd` — **DIFFERENT** | в live — только collision-фикс; в Minimax — collision-фикс **+** trace-профилирование (`terrain_geometry_profile`, `perf_*`), 59 строк diff |
| 2-4 | `tools/mining_latency_probe.gd` (+`.uid`) | только Minimax — диагностический зонд |
| 5-6 | `tools/terrain_collision_probe.gd` (+`.uid`) | только Minimax — диагностический зонд |
| 7-8 | `tools/torch_regression_probe.gd` (+`.uid`) | только Minimax — диагностический зонд |
| 9-12 | `tools/torch_render_visible_self_test.gd.uid`, `tools/torch_terrain_light_regression_self_test.gd.uid`, `scripts/native_story_sequencer.gd.uid`, `tools/native_story_sequencer_self_test.gd.uid`, `tools/story_sequencer_test_scene.gd.uid` | `.uid`-файлы Godot — генерируются самим движком при импорте, для интеграции не нужны |

| Файл | Live | Minimax | Статус |
|---|---|---|---|
| `scripts/native_scene_profile.gd` | sha `019CD5C4C6306A83` | sha `019CD5C4C6306A83` | **СОВПАДАЮТ** — torch-фикс применён (live L156: `var gain: float = float(...["gain"])`) |
| `scripts/multiplayer_test.gd` | `changed_cells.is_empty()` → исправлено на `true` (L658) | профилирование + `true` | **РАЗЛИЧАЮТСЯ** — live без trace-профилирования (58 строк diff) |
| `scripts/native_walkmap.gd` | sha `e8c27267eb4e2a40` (446 строк) | sha `e8c27267eb4e2a40` | **СОВПАДАЮТ** — walkmap-оптимизация уже в обоих |
| `scripts/native_walk_flags.gd` | sha `2d53e3be8910ed1b` (216) | sha `2d53e3be8910ed1b` | **СОВПАДАЮТ** |
| `scripts/native_terrain_state.gd` | sha `791921f9390a40ff` (194) | sha `791921f9390a40ff` | **СОВПАДАЮТ** |
| `shaders/native_terrain_pipeline.gdshader` | sha `68aca400ff01a0ab` | sha `68aca400ff01a0ab` | **СОВПАДАЮТ** — шейдер не менялся нигде |
| хомячьи модули (9 scripts + 3 models + 3 tools + 2 scenes) | присутствуют | присутствуют | **СОВПАДАЮТ** побайтово (проверено по 12 файлам) |
| `tools/torch_terrain_light_regression_self_test.gd` | sha `e74736f43214…` | sha `e74736f43214…` | **СОВПАДАЮТ** |
| `tools/torch_render_visible_self_test.gd` | sha `b342c3bade96…` | sha `b342c3bade96…` | **СОВПАДАЮТ** |
| `tools/torch_regression_probe.gd` | **НЕТ** | есть | только Minimax — диагностический зонд |
| `tools/mining_latency_probe.gd` | **НЕТ** | есть | только Minimax — диагностический зонд |
| `tools/terrain_collision_probe.gd` | **НЕТ** | есть | только Minimax — диагностический зонд |
| `tools/*.uid` (2 torch-теста) | **НЕТ** | есть | Godot сгенерирует сам при первом импорте |
| `scripts/native_story_sequencer.gd`, `tools/native_story_sequencer_self_test.gd`, `models/native_story_sequencer_commands.json` | есть | **НЕТ** | **только Live** — работа Codex'а, началась 19:26, не входила в мои снимки |

Итого (20:23): **297 файлов в live, 308 в Minimax, 12 расхождений** — и все 12 объяснены:
профилирование в `multiplayer_test.gd` + 3 диагностических зонда (+ их `.uid`) +
`.uid`-файлы, которые Godot сгенерирует сам.

**Существенное:** расхождение по `scripts/multiplayer_test.gd` — единственное
содержательное. Все функциональные правки (torch-фикс, collision-фикс, walkmap,
хомяки, 2 torch-теста) в обоих деревьях **побайтово совпадают**.

### 2.2 Что именно лежит в каждом дереве

| Артефакт | Live | Minimax | Комментарий |
|---|---|---|---|
| Torch-фикс (снятие `/ 255.0`) | **есть** (с 20:00) | **есть** | `native_scene_profile.gd:156` |
| Collision-фикс (`build_collision=true`) | **есть** (с 20:00, L658) | **есть** | `multiplayer_test.gd:658` |
| Trace-профилирование `_build_geometry` | нет | есть | `terrain_geometry_profile`, `perf_*` — диагностика, можно не переносить |
| Walkmap-оптимизация | **есть** | **есть** | идентична workbench-версии |
| Хомяки | **есть** (Codex доработал) | **есть** | версии в live новее патча |
| 2 torch-теста | **есть** (с 20:00) | **есть** | побайтово равны |
| 3 диагностических зонда | нет | есть | опционально |

### 2.3 Контроль read-only

Хэши живых файлов зафиксированы до и после ревью; в момент 20:01 файл
`native_scene_profile.gd` изменился **самим Codex'ом** (mtime 19:55:09 → правка
родителя в 20:00), а не ревьюером. Ревьюер не создавал и не менял файлов в
`ChatGPT\Diggles` — все записи только в `Minimax\Diggles\review-tmp\` и
`Minimax\Diggles\docs\review\`.

---

## 3. Инвентаризация незакрытых артефактов

| # | Артефакт | Что меняет | К какому дереву относится | Применён? |
|---|---|---|---|---|
| 1 | `workbench\walkmap-performance.patch` (20 853 Б, 512 строк) | 3 файла: `godot/scripts/native_walkmap.gd`, `native_walk_flags.gd`, `native_terrain_state.gd` | к **pristine** upstream (`MM\baseline\godot`) | **НЕ применять** — уже в live; к live конфликтует |
| 2 | `out\torch_regression\torch-terrain-light-gain.patch` (23 714 Б) | `godot/scripts/native_scene_profile.gd` + 2 новых теста | к live | **ДА, применён** (20:00) |
| 3 | `repro\godot\scripts\native_scene_profile.gd` (10 385 Б) | исправленный файл профиля сцены | копия, идентична live | применён через п.2 |
| 4 | `repro\godot\tools\torch_terrain_light_regression_self_test.gd` (11 147 Б) | регрессионный тест света | идентичен live | **ДА, применён** (20:00) |
| 5 | `out\hamster-integration.patch` (175 234 Б) | 19 файлов: 9 scripts + 5 tools + 2 scenes + tasklist + dispatcher | к live | **ДА, применён** (поглощён) |
| 6 | `out\hamster-integration-data.patch` (5 019 850 Б) | `models/native_hamster_clips.json` | к live | **ДА, применён** (JSON эквивалентен) |
| 7 | `docs\reverse-engineering\agent-result-runtime-torch-regression-2026-11-19.md` | отчёт по факелам | есть в обоих | — |
| 8 | `docs\reverse-engineering\agent-result-mining-latency-2026-11-19.md` | отчёт по задержке + collision | есть в обоих | — |
| 9 | `docs\reverse-engineering\agent-result-hamster-integration-2026-11-19.md` | отчёт по хомякам | **только Live** | — |
| 10 | `docs\reverse-engineering\agent-result-walkmap-performance-2026-11-19.md` | отчёт по walkmap | **только Live** | — |
| 11 | `docs\reverse-engineering\agent-result-lighting-architecture-2026-11-19.md` | отчёт по архитектуре света | **только Live** | — |

---

## 4. Проверка применимости патчей

Инструмент: собственный applier `review-tmp\apply_patch.py` (git/patch в окружении
отсутствуют). Первые версии applier'а были некорректны (hunk-body обрезался по
`max(old,new)` вместо раздельного счёта old/new-строк) — исправлено и все результаты
перепроверены; ниже приведены числа **после** исправления.

### 4.1 К live-дереву (`review-tmp\apply-root`, 1530 файлов — снимок live)

| Патч | Результат | Детали |
|---|---|---|
| `torch-terrain-light-gain.patch` | **APPLIED_CLEANLY (3 файла)** | `native_scene_profile.gd` 202→206 строк; 2 теста CREATE |
| `collision-fix.patch` (из отчёта, §6.4) | **APPLIED_CLEANLY (1 файл)** | `multiplayer_test.gd` 4221→4225 строк; контекст сматчился с дрейфом +10 строк |
| `walkmap-performance.patch` | **CONFLICT (3 файла)** | все хунки `native_walkmap.gd` (5 шт.), `native_walk_flags.gd` (1), `native_terrain_state.gd` (1) не совпали: контекст уже содержит оптимизацию |

### 4.2 К pristine upstream (`MM\baseline\godot`)

`walkmap-performance.patch` → **APPLIED_CLEANLY (3 файла)**:
`native_walkmap.gd` 137→446, `native_walk_flags.gd` 124→216, `native_terrain_state.gd` 179→194.
Результат **побайтово равен** workbench-версии оптимизации (native_walkmap.gd и
native_walk_flags.gd — идентичны; native_terrain_state.gd отличается только именем
параметра `cell` vs `map_cell` в `cell_surface_samples`).

### 4.3 Пересечение строк между патчами

**Нет.** Torch-патч трогает `native_scene_profile.gd`; walkmap — `native_walkmap.gd` /
`native_walk_flags.gd` / `native_terrain_state.gd`; collision — `multiplayer_test.gd`.
Непересекающиеся файлы; общий риск только транзитивный (walkmap меняет сигнатуру
`rebuild_after_strike`, которую вызывает `multiplayer_test.gd`).

### 4.4 Существенная находка: walkmap-патч не самодостаточен

`walkmap-performance.patch` меняет сигнатуру
`native_walkmap.rebuild_after_strike(...)` с 4 аргументов на 5
(добавлен `surface_cells: Callable`), но **не** трогает вызывающий код.
Живой вызов — `multiplayer_test.gd:611` — передаёт 5 аргументов
(`_native_cell_surface_samples`).

Проверено экспериментом: дерево `review-tmp\combined-walkmap-reverted`
(всё как в live, но 3 walkmap-файла откачены на pristine) даёт
**SCRIPT ERROR: Invalid call to function 'rebuild_after_strike' … Expected 4 argument(s)**
и `terrain_refresh_self_test` → exit=1, 6 failures из 8.

Вывод: **патч walkmap нельзя применять как отдельный артефакт.** Он валиден только
парой с изменением `multiplayer_test.gd` (которое в живой версии уже есть).

---

## 5. Прогон тестов в объединённом дереве

Метод — тот же, что у сессии «Review»: `Start-Process` + `WaitForExit` (с фиксацией
`$p.Handle`, иначе `ExitCode` пустой — это и стоило одного перезапуска),
`--headless --path <proj> --script res://tools/<t>.gd`. Список — ровно 45 уникальных
тестов из `Minimax\Diggles\tools\run_suite.ps1` (48 записей, 3 дубликата).

Деревья:
* **baseline** — снимок live ДО правок (19:26) + только 2 torch-теста (чтобы список совпал);
* **combined** — baseline + torch-патч + collision-патч;
* **livefinal** — снимок live ПОСЛЕ правок родителя (20:02).

### 5.1 Итог

| Дерево | Тестов | Падений | Отличия |
|---|---|---|---|
| baseline (до правок) | 45 | **4** | torch(12 failures), excavated_walk, native_dig_queue, native_dwarf_dig |
| combined (torch+collision) | 45 | **1** | только native_dig_queue |
| **livefinal (live после 20:00)** | **45** | **1** | только native_dig_queue |

Сравнение `livefinal` с заявленной базой (`out/primary-suite-2026-11-19/suite_final.csv`):
**расхождений нет** — по каждому из 45 тестов exit-код совпадает.

### 5.2 Значимые строки (livefinal)

| Тест | exit | Итог |
|---|---|---|
| torch_terrain_light_regression_self_test | 0 | TORCH_TERRAIN_LIGHT_SELF_TEST torches=4 checks=39 failures=0 |
| automatic_torch_runtime_self_test | 0 | AUTOMATIC_TORCH_RUNTIME_SELF_TEST checks=36 failures=0 |
| native_scene_profile_self_test | 0 | NATIVE_PROFILE_SELF_TEST_OK lights=9 retained_triangles=5302 |
| native_terrain_render_self_test | 0 | NATIVE_TERRAIN_RENDER_SELF_TEST_OK assertions=2431 |
| terrain_refresh_self_test | 0 | TERRAIN_REFRESH_SELF_TEST checks=8 failures=0 |
| native_walk_flags_self_test | 0 | NATIVE_WALK_FLAGS_SELF_TEST_OK assertions=131 |
| native_terrain_state_self_test | 0 | NATIVE_TERRAIN_STATE_SELF_TEST_OK assertions=76 fixtures=7 |
| native_fix_dig_self_test | 0 | NATIVE_FIX_DIG_SELF_TEST_OK assertions=104 |
| native_dig_next_self_test | 0 | NATIVE_DIG_NEXT_SELF_TEST_OK assertions=101 fixtures=22 |
| excavated_walk_self_test | 0 | EXCAVATED_WALK_SELF_TEST_OK assertions=39 mutations=4 |
| native_dwarf_dig_self_test | 0 | NATIVE_DWARF_DIG_SELF_TEST_OK assertions=219 |
| **native_dig_queue_self_test** | **1** | **queue selected an extra or missing point** |
| native_battle_world / native_corridor_* / native_dig_feedback / native_stance / surface_depth_route / wall_branch / native_attachment / native_animation_aliases / native_actor_tasks / dwarf_* / floor_sleep / gesture / manual_dig_region / movement_feedback / native_vector_fix / native_hamster_* / native_flame / native_model_* / native_shader_pipeline / native_torch_* / native_autolight / native_surface_walk | 0 | все зелёные |

Таймаутов: **0**. Parse-error'ов GDScript: **0** (предупреждения GDScript считаются
ошибками — в логах их нет).

### 5.3 Walkmap: эквивалентность и влияние на падающий тест

* **Эквивалентность воспроизведена на ЖИВОМ коде.** Собран стенд
  `review-tmp\equivalence-live`: `scripts/` = файлы из **живого** проекта,
  `baseline/` = pristine upstream, инструмент — `walkmap_equivalence_self_test.gd`
  из workbench. Результат:
  ```
  WALKMAP_EQUIVALENCE_SERIES narrow accepted=273 byte_changing=141
  WALKMAP_EQUIVALENCE_SERIES wide   accepted=273 byte_changing=141
  WALKMAP_EQUIVALENCE_SELF_TEST_OK assertions=4369
  ```
  Совпадает с заявленным `assertions=4369`. Оптимизация в live эквивалентна
  полной перестройке.
* **На статус падающего теста walkmap не влияет.** `native_dig_queue_self_test`
  → exit=1 и в `wmp` (оптимизация есть), и в `wmr` (оптимизация откачена,
  при этом тест падает раньше — на несовместимости API). В **baseline**
  (pristine walkmap, без оптимизации) — exit=1 с **той же** формулировкой.
  Вывод: падение не связано с walkmap.

### 5.4 Измеренное влияние walkmap на задержку удара — САМОПРОВЕРКА И ПРАВКА

**Первоначальная интерпретация автора этого отчёта была ошибочной.** Изолированный
повтор показал, что все три дерева содержат **идентичный** оптимизированный walkmap
(`native_walkmap.gd` sha `E8C27267EB4E`, 446 строк — во всех трёх), поэтому разница
в `strike_ms` между прогонами **не могла** быть вызвана walkmap-оптимизацией.
Первое наблюдение ([37.7, 32.4, 42.7] против [75.1, 85.7, 159.0]) было артефактом
**конкурентной нагрузки** — в момент прогона baseline-parallel работали другие сессии.

Изолированные повторы (3 прогона каждый, без параллельной нагрузки):

| Дерево | walkmap | Прогоны `strike_ms` |
|---|---|---|
| livefinal (live после правок) | оптимизированный | `[85.056, 88.419, 103.661]`, `[77.208, 68.725, 94.761]`, `[77.352, 69.998, 96.704]` |
| baseline (тот же snapshot live) | **тот же** оптимизированный | `[80.069, 70.825, 89.828]`, `[78.103, 70.167, 95.872]`, `[79.940, 67.202, 92.062]` |

Разница между деревьями — **в пределах шума** (накладные расходы ±20 %), как и
ожидалось: walkmap-код у них байт-в-байт одинаков. **Никакого вывода о влиянии
walkmap на end-to-end задержку удара из этих прогонов делать нельзя.**

Корректный источник измерения walkmap — специализированный стенд
(`workbench/tools/walkmap_bench_compare.gd`), который сравнивает **один и тот же**
snapshot-данные в трёх режимах (full / cached / bulk) и считает вызовы к хосту,
а не end-to-end задержку. Его независимое воспроизведение — §5.5.

**Вывод (исправленный):** walkmap-оптимизация уже в live; её выигрыш
(9.79 с → 1.69 с, 5.81×) измеряется на изолированном стенде, а не в
`terrain_refresh_self_test`. End-to-end задержка удара после оптимизации
определяется перестройкой меша и navigation grid (§5.6), а не walkmap.

### 5.5 Независимое воспроизведение бенчмарка walkmap

Стенд `workbench` скопирован в `review-tmp/wb-bench` (оригинал не изменялся) и
запущен независимо. Результат:

```
BENCH_COMPARE repeats=5 strikes=273 accepted=273 byte_changing=141
BENCH_COMPARE full    total_us=28871182 avg_us=105755 max_us=403044 height_calls=1804460 gate_calls=294544 cell_calls=0 rebuilt=289114
BENCH_COMPARE cached  total_us=4979320  avg_us=18239  max_us=88017  height_calls=86624   gate_calls=1326  cell_calls=0 rebuilt=199840 skipped=89946 speedup=5.80x
BENCH_COMPARE bulk    total_us=4380680  avg_us=16046  max_us=29747  height_calls=0       gate_calls=1326  cell_calls=1392 rebuilt=199840 skipped=89946 speedup=6.59x
BENCH_COMPARE host_call_reduction cached=20.8x bulk=1804460.0x
BENCH_COMPARE_DONE assertions=20 failures=0
```

| Режим | total_us (273 удара) | avg_us/удар | вызовы хоста (height) | speedup |
|---|---|---|---|---|
| full (без кэша) | 28 871 182 | 105 755 | **1 804 460** | 1.00× |
| cached | 4 979 320 | 18 239 | 86 624 | **5.80×** |
| bulk | 4 380 680 | 16 046 | **0** | **6.59×** |

**Заявленные производителем цифры воспроизведены:** 5.81× → измерено **5.80×**,
6.34× → измерено **6.59×** (разница в пределах шума повторов; всего 5 повторов,
`repeats=5`). Ключевой инвариант — **число вызовов хоста**: 1 804 460 → 86 624 (×20.8)
→ **0** при bulk-режиме, при этом `rebuilt=199840`, `skipped=89946` и `changed=7387`
совпадают во всех режимах (одинаковый результат). `assertions=20 failures=0`.

### 5.6 Задержка удара после оптимизации

По отчёту «Review» (`agent-result-mining-latency-2026-11-19.md`): удар целиком
~22.5 мс headless / ~27.4 мс GPU, из них отложенная перестройка navigation grid
33–42 мс; **GPU upload не является узким местом**. Это согласуется с тем, что
после оптимизации walkmap остаточная задержка приходится на перестройку меша и
навигации, а не на сам walkmap.

---

## 6. Характеризация остаточного падения `native_dig_queue_self_test`

**Статус:** воспроизводится и на финальном live (20:03, exit=1,
`ERROR: NATIVE_DIG_QUEUE_SELF_TEST_FAILED queue selected an extra or missing point`),
и на baseline, и на combined — **pre-existing**, не связан с правками.

### 6.1 ОПРОВЕРЖЕНИЕ гипотезы брифа

Бриф предполагал: «очередь выбирает другое число/порядок точек, чем исходная фикстура»
(т.е. виноват `native_dig_next`). **Это не так.**

Минимальный репродусер `review-tmp\apply-root\godot\tools\repro_dig_queue_order.gd`
(тот же fixture, но печатает наблюдаемый порядок и содержимое history):

```
REPRO_MARK (1, 15) accepted=true
REPRO_MARK (2, 15) accepted=true
REPRO_MARK (2, 16) accepted=true
DWARF_DIG_ASSIGNED  Zwerg_1106 point=(2, 15)
DWARF_DIG_CALLBACK  Zwerg_1106 point=(2, 15) accepted=true
DWARF_DIG_STANCE_RETAINED Zwerg_1106 point=(1, 15)
DWARF_DIG_CALLBACK  Zwerg_1106 point=(1, 15) accepted=true
DWARF_DIG_STANCE_RETAINED Zwerg_1106 point=(2, 16)
DWARF_DIG_CALLBACK  Zwerg_1106 point=(2, 16) accepted=true
REPRO_EXPECTED_COUNT 3
REPRO_EXPECTED_ORDER [(2, 15), (1, 15), (2, 16)]
REPRO_TERRAIN_REVISION 3
REPRO_DIG_ACTION_COMPLETIONS 3
REPRO_SELECTION_HISTORY_SIZE 1
REPRO_HISTORY_ENTRY 0 point=(2, 15) rank=-1 group=-1 planner=source_request_floor_projection
REPRO_HISTORY_POINTS [(2, 15)]
```

Факты:
* Порядок раскопок **(2,15) → (1,15) → (2,16)** — **точно** совпадает с
  `expected_order` фикстуры. Ранжирование `native_dig_next` корректно.
* Мутаций террейна — 3 (== expected_count), колбэков — 3. Всё, что должно
  произойти, произошло.
* Но `dig_selection_history.size() == 1` вместо 3 → падает ассерт
  `native_dig_queue_self_test.gd:54` («queue selected an extra or missing point»).

Тот же результат на baseline-дереве (без правок) — падение pre-existing.

### 6.2 Локализованная причина

`dig_selection_history.append()` вызывается ровно в двух местах
(`multiplayer_test.gd`):

| Строка | Функция | Путь |
|---|---|---|
| 2963 | `_assign_dwarf_dig_point` | обычное назначение (`DWARF_DIG_ASSIGNED`) |
| 3139 | `_assign_surface_dig` | surface-планировщик |

Ветка «устойчивая стойка» в `_continue_dwarf_dig`
(`multiplayer_test.gd:3239-3247`) **не** вызывает ни одну из них:

```gdscript
if not bool(previous_job.get("surface",false)) \
        and _dwarf_dig_reachable(dwarf.position,point) \
        and _has_source_floor(...):
    dwarf_dig_jobs[dwarf] = {"point":point,"phase":"approach","stance":dwarf.position,
        "rank":retry,"digpoint":digpoint,"planner":"stable_floor_stance"}
    _remember_work_region(dwarf,point)
    print("DWARF_DIG_STANCE_RETAINED %s point=%s stance=%s" % [...])
    _begin_dwarf_dig_action(dwarf)
    return
```

Именно эта ветка обрабатывает 2-й и 3-й пункты очереди (в логе —
`DWARF_DIG_STANCE_RETAINED` для (1,15) и (2,16)), поэтому в history попадает
только первое назначение.

### 6.3 Подтверждение в логе full-stroke

`out/primary-suite-2026-11-19/digqueue_fullstroke.log` (4 точки) показывает
**тот же** механизм, а не иной порядок:
```
DWARF_DIG_ASSIGNED        point=(2, 15)
DWARF_DIG_STANCE_RETAINED point=(1, 15)
DWARF_DIG_STANCE_RETAINED point=(2, 16)
DWARF_DIG_ASSIGNED        point=(1, 16)
```
т.е. фактический порядок раскопок = (2,15),(1,15),(2,16),(1,16) — **ровно**
`expected_order` для 4 точек. В history при этом только 2 записи, и вторая
`(1,16)` приходит «не на своём месте» — из-за пропуска записей, а не из-за
неверного ранга. Ошибка «native next order differs from source fixture»
(строка 57) — **каскад** первой ошибки (сдвиг индексов), а не отдельная проблема.

### 6.4 Рекомендация (не чинил — только характеризовал)

Корень — **несоответствие между тестом и наблюдаемостью**, а не геймплейный баг.
Два корректных варианта (на усмотрение владельца):
1. **Тест:** считать успех по фактическим раскопкам (порядок/число callback'ов
   `DWARF_DIG_CALLBACK`), а не по размеру `dig_selection_history`; либо
   задокументировать, что `dig_selection_history` — это «история *назначений*»,
   а не «история раскопок», и проверять только те назначения, что попали в history.
2. **Продукт:** добавить `dig_selection_history.append(...)` в ветку
   `stable_floor_stance` (`multiplayer_test.gd:3242`), чтобы history отражала
   все 3 выбора. Это меняет только диагностический массив, не логику выбора.

До выбора варианта `native_dig_queue_self_test` следует считать **ожидаемо красным**,
а не регрессией.

---

## 7. Риск «свет станет в 255 раз ярче»

**Механизм (подтверждён по коду).** CPU-путь `native_terrain_illumination.gd:33-38`
считает вклад как `color × factor × visibility`, умножает на `gain` и **делит
результат 0..255 на 255** (`/255.0` в строке 37-38), получая albedo 0..1.
Uniform-путь шейдера (`native_terrain_pipeline.gdshader:41`) складывает
`dynamic_torch_color` **напрямую в albedo** — уже в 0..1. Поэтому uniform обязан
нести `color × gain`; деление на 255 в `native_scene_profile.gd:152` делало
вклад света в **255 раз** слабее. Фикс корректен.

**Измерение «вспышки» (A/B-кадры из `out/torch_regression/verify-2026-11-19/`).**
Область факела — bbox (150,60)-(320,290), 640×360:

| Кадр | mean | p50 | p95 | max |
|---|---|---|---|---|
| `far_torch_dark.png` (факел выключен) | 46.46 | 34.00 | 94.00 | 194.67 |
| `far_torch_unpatched_lit.png` (до фикса) | 46.70 | 34.33 | 94.00 | 194.67 |
| `far_torch_lit.png` (после фикса) | 91.18 | 94.00 | 154.67 | **219.33** |

* Рост в области факела: mean **1.95×**, p50 **2.74×**, p95 **1.65×**.
* **Клиппинга нет:** максимум 219.33 из 255 — запас до пересвета остаётся.
* «dark» и «unpatched_lit» почти неразличимы (46.46 vs 46.70) — то есть до фикса
  факел **не давал видимого вклада** вовсе, что и подтверждает диагноз.

**Вывод:** «×255» относится к **коэффициенту вклада**, а не к видимой яркости:
вклад света был ~0, стал ~0.1 в albedo (gain = 0.1 из `native_terrain_render.json:2765`),
поэтому картинка стала светлее в 2 раза, а не в 255. **Регрессионный кадр уже
существует** (`far_torch_lit.png` vs `far_torch_unpatched_lit.png`) — новый
кадр не обязателен, но полезно сделать один «живой» кадр из тёмного коридора
для регрессии против пересвета.

---

## 8. Единый план интеграции

### 8.1 Уже выполнено (не требует действий)

| # | Действие | Где | Статус |
|---|---|---|---|
| 1 | Torch-фикс: снять `/ 255.0` | `godot/scripts/native_scene_profile.gd:156` | ✅ в live с 20:00 |
| 2 | 2 torch-теста в live | `godot/tools/torch_terrain_light_*.gd` | ✅ в live с 20:00 |
| 3 | Collision-фикс | `godot/scripts/multiplayer_test.gd:658` | ✅ в live с 20:00 |
| 4 | Walkmap-оптимизация | 3 файла `scripts/native_*.gd` | ✅ уже была в live (не применялась повторно) |
| 5 | Хомячий пакет | 19 файлов | ✅ поглощён, Codex'ом доработан |

### 8.2 Осталось (опционально)

| # | Действие | Точка отката | Приоритет |
|---|---|---|---|
| 6 | Перенести 3 диагностических зонда в live: `tools/mining_latency_probe.gd`, `tools/terrain_collision_probe.gd`, `tools/torch_regression_probe.gd` | удалить 3 файла | низкий (нужны для регрессии collision/латентности) |
| 7 | Перенести trace-профилирование `_build_geometry` (`terrain_geometry_profile`, `perf_*`) из Minimax в live `multiplayer_test.gd` | откатить `multiplayer_test.gd` к live-версии | низкий: без него в live нет разбивки задержки по фазам |
| 8 | Решить судьбу `native_dig_queue_self_test` (§6.4): вариант 1 (тест) или 2 (продукт) | откатить одну строку в тесте / одну в `multiplayer_test.gd` | средний: блокирует «зелёный» прогон |
| 9 | Синхронизировать `docs/reverse-engineering/agent-result-*` из live в Minimax (5 отчётов есть только в live) | — | низкий (косметика) |
| 10 | Прогнать `terrain_refresh_self_test` в live **изолированно** (без параллельных прогонов) для честного замера задержки | — | средний (для отчётности). *Ревьюер уже выполнил 3 изолированных прогона в `livefinal` — §5.4; повтор в самом live не обязателен, т.к. walkmap-код идентичен.* |

### 8.3 Порядок и риски

**Порядок (рекомендуемый):**
1. Ничего не применять из `walkmap-performance.patch` — он конфликтует и не самодостаточен (§4.4).
2. Ничего не применять из `hamster-integration*.patch` — уже поглощёны (§3, п.5-6).
3. Точечно перенести 3 зонда (п.6) и, при желании, профилирование (п.7) —
   файлы не конфликтуют с уже применёнными правками.
4. Выбрать и применить вариант фикса `native_dig_queue_self_test` (п.8).
5. Прогнать 45 self-test-ов в live изолированно → ожидается 45/0 (или 45/1,
   если п.8 отложен — это не регрессия).

**Риски:**

| Риск | Оценка | Митигация |
|---|---|---|
| Пересвет от torch-фикса | **Низкий**: 1.95× mean, max 219/255, без клиппинга (§7) | готов A/B-кадр; сделать 1 «живой» кадр тёмного коридора |
| Регресс от collision-фикса | **Низкий**: `build_collision=true` пересоздаёт collision только перестроенным поверхностям; +0.5 мс к `commit_ms`, +1.7 мс к удару | `terrain_collision_probe.gd`: было 784/801 → стало 801/801 (отчёт §6.2) |
| Повторное применение walkmap-патча | **Высокий**: откатит оптимизацию и сломает API (`Expected 4 argument(s)`) | патч помечен «не применять»; при откате — откатывать **3 walkmap-файла + `multiplayer_test.gd` вместе** |
| Повторное применение хомячьего патча | **Средний**: файлы уже созданы → конфликт «already exists», риск отката доработок Codex'а | только точечное копирование, без apply |
| Walkmap-оптимизация без эквивалентности | **Низкий**: эквивалентность воспроизведена на live-коде, `assertions=4369` | стенд `review-tmp/equivalence-live` — готов к повторной проверке |
| Codex продолжает править live параллельно | **Реальный**: за время ревью live менялся 3жды (19:26, 19:55, 20:00) | все сравнения делать по SHA-256 непосредственно перед коммитом; фиксировать время |

**Откат:** каждый пункт п.6-п.8 затрагивает 1-3 файла → откат = восстановление
этих файлов из бэкапа (в live нет git; использовать копию `review-tmp/live-final/godot`
как эталон «до» для п.6-п.8).

---

## 9. Сводка по параллельным блокам

| Блок | Что сделано | Где лежит | Применён? | Статус | Что дальше |
|---|---|---|---|---|---|
| **Факела** | Найдена первопричина «факелы не светят terrain»: лишнее `/ 255.0` в uniform-цвете; patch + регресс-тест | `out/torch_regression/torch-terrain-light-gain.patch`, `repro/godot/…` | ✅ **ДА** (live, 20:00) | **ЗАКРЫТ** | только регресс-кадр тёмного коридора (п.10) |
| **Review** | Синхронизация деревьев; collision-фикс (`build_collision=true`); замер задержки (~22.5 мс headless / ~27.4 мс GPU, навигация 33-42 мс); прогон 45 тестов (3→1) | `out/primary-suite-2026-11-19/`, `agent-result-mining-latency-*.md` | ✅ **ЧАСТИЧНО**: collision-фикс в live (20:00); профилирование — только в Minimax | **ЗАКРЫТ (основное)** | перенести профилирование в live (п.7) — опционально |
| **Производительность** | Инкрементальный кэш BlockDB-поверхностей: заявлено 9.79 с → 1.69 с (5.81×), bulk 6.34×; **воспроизведено ревьюером: 5.80× / 6.59×**, вызовы хоста 1 804 460 → 0; эквивалентность `assertions=4369` | `workbench/walkmap-performance.patch`, `agent-result-walkmap-performance-*.md` | ✅ **ДА, УЖЕ БЫЛ** в live (совпадает с workbench побайтово) | **ЗАКРЫТ** | патч не применять (конфликтует и не самодостаточен); при откате — 3 файла + `multiplayer_test.gd` вместе |
| **Хомяки** | Пакет интеграции диких хомяков: 19 файлов + модель клипов | `out/hamster-integration*.patch`, `agent-result-hamster-integration-*.md` | ✅ **ДА** (поглощён, Codex доработал) | **ЗАКРЫТ** | повторное применение не нужно; версии live новее патча (100 % строк патча присутствуют) |
| **Освещение** | Отчёт по архитектуре освещения | `ChatGPT\Diggles/docs/reverse-engineering/agent-result-lighting-architecture-2026-11-19.md` | отчёт, кода нет | **ОТКРЫТ (только отчёт)** | скопировать отчёт в Minimax (п.9) |
| **Codex (story-sequencer)** | Новый модуль + тест + модель команд | только в `ChatGPT\Diggles/godot` | ✅ в live | **ОТКРЫТ (вне объёма)** | синхронизировать в Minimax (п.9) |
| **Ревью (этот отчёт)** | Аудит, применимость, прогоны, характеризация падения | `docs/review/parallel-integration-review-2026-11-19.md` | — | **ЗАКРЫТ** | см. §8.2 |

---

## 10. Что осталось непроверенным

1. **Реальный GPU-render на Android-устройстве.** Все кадры и замеры — headless /
   OpenGL-software на Windows; поведение шейдера на мобильном GPU не проверено.
2. **Поведение на физическом устройстве** (Android) не проверялось.
3. **Отсутствующие в live 3 диагностических зонда** (`mining_latency_probe.gd`,
   `terrain_collision_probe.gd`, `torch_regression_probe.gd`) не запускались в самом
   live — они работают только в дереве Minimax (там же снимались их логи).
   Проверка collision-фикса в live выполнена косвенно: `excavated_walk_self_test`
   и `native_dwarf_dig_self_test` зелёные в `livefinal` (до правок падали).
4. **Поведение `native_dig_queue_self_test` после выбранного варианта фикса (п.8)**
   не проверялось — вариант не выбран и не применялся (по условию задачи не чинил).
5. **Walkmap-эквивалентность проверена на живом коде**, но на **одном** наборе из
   273 ударов и 5 серий (narrow/wide) — других карт/фикстур не прогонялось.
6. **Патчи не применялись к живому проекту ревьюером** — проверялась применимость
   только на копиях (`review-tmp/apply-root`, `review-tmp/baseline-tree`,
   `review-tmp/walkmap-patch-verify2`).
7. **Не проверено:** целостность APK/экспорта (сборка не выполнялась по условию),
   поведение на реальном touch-устройстве, работа с несколькими игроками по сети.

---

INTEGRATION_HANDOFF: docs/review/parallel-integration-review-2026-11-19.md
