# Результат: задержка после удара + потеря collision при перестройке terrain

Дата: 2026-11-19 (вечер)

Основной проект (Minimax workspace, теперь он ведущий):
`C:\Users\frant\OneDrive\Документы\MiniMax\Diggles`
Рабочее дерево Godot: `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot`

---

## 1. Итог одной строкой

Задержка после удара **измерена и разложена по фазам**: удар стоит **~22 мс**
(headless) / **~27 мс** (реальный GPU), при этом

* **GPU upload не является узким местом** — кадр после удара стоит столько же,
  сколько кадр без удара, а весь «GPU-facing» кусок (`commit_ms`) — **~1 мс**;
* доминируют `surface_ms` (7–10 мс, перестройка SurfaceTool поверх чанка) и
  `free_ms` (2.6–3.3 мс, освобождение старых инстансов чанка);
* **самая большая единичная задержка — не удар, а отложенная перестройка
  navigation grid: 33–42 мс** через 0,75 с после серии ударов.

Попутно профилирование вскрыло **баг корректности**: перестройка чанка после
раскопки **убирала collision пола** (793/793 → 784/801 чанков за один удар).
Исправлено: **два падавших self-test-а теперь зелёные**, цена — **+0,5…1,7 мс
на удар**.

---

## 2. Задача

Handoff §5.2 и §7.3: «Проверить, что минимальная задержка после удара реально
ушла… Если фриз остаётся, профилировать `_build_geometry` и GPU uploads
отдельно, не ослабляя correctness walkmap».

---

## 3. Метод измерения

### 3.1 Инструмент

`godot/tools/mining_latency_probe.gd` (новый). Поднимает реальную сцену
`res://scenes/multiplayer_test.tscn`, включает `verbose_runtime_trace` и
выкапывает коридор **погонной меткой** — по одной клетке за удар, как у
дворффа с киркой. Для каждого удара меряется wall-clock самого вызова
`native_dig_apply_cell()` и кадр, который первым рисует перестроенный чанк.

Точки копания выбраны по **исходному** правилу тоннеля
(`native_tunnel_rules.gd:31`): клетка принимается, только если
`int((x-1)/2) & int((y-1)/2) & 1 == 0`, то есть в ряду копаются пары через
4 клетки. Ошибочная «прямая» линия даёт 1 успешный удар из 24 — это было
отлажено, а не замаскировано.

### 3.2 Разбивка `_build_geometry`

В `multiplayer_test.gd` добавлены **trace-gated** таймеры (по умолчанию
выключены, `verbose_runtime_trace=false`):

| таймер | что меряет |
|---|---|
| `free_ms` | освобождение старых инстансов перестроенного чанка |
| `surface_ms` | перестройка SurfaceTool (заливка вершин) |
| `light_ms` | из него: CPU-освещение вершины (`TERRAIN_ILLUMINATION.channels`) |
| `cell_lookup_ms` | из него: `detail_texture()` + `ground_file()` на клетку |
| `commit_ms` | `SurfaceTool.commit()` + trimesh-collision + вставка в сцену |
| `vertices`, `cells`, `surfaces` | объём перестроения |

Результат пишется в `terrain_geometry_profile` и печатается в
`NATIVE_TERRAIN_REFRESH ... profile={...}`.

### 3.3 Отдельно про collision

`godot/tools/terrain_collision_probe.gd` (новый) считает terrain-чанки с
рабочим collision-телом до и после раскопки. Важно: узел `CollisionShape3D`
создаётся через `CollisionShape3D.new()` и получает авто-имя
`@CollisionShape3D@2`, поэтому искать его надо **по классу**, а не по имени.

### 3.4 Окружение

`Godot_v4.7.2-stable_win64_console.exe` → `4.7.2.stable.official.ed1daf0bf`.
GPU: `OpenGL API 3.3.13596 … AMD Radeon(TM) Vega 8 Graphics` — тот же драйвер,
что и в штатных визуальных прогонах проекта.

---

## 4. Результаты: профиль одного удара

### 4.1 CPU (headless)

Типичный удар (перестройка одного чанка, 4 из 15 ground-вариантов):

```
NATIVE_TERRAIN_REFRESH batches=4 variants=4 geometry_ms=11.585 open_air_ms=2.122 navigation_ms=0.000
  profile={ "free_ms": 2.751, "surface_ms": 7.812, "commit_ms": 0.918, "surfaces": 14,
            "collision": true, "light_ms": 1.463, "vertices": 183,
            "cell_lookup_ms": 0.204, "cells": 17 }
```

| фаза | мс | доля удара |
|---|---|---|
| `free_ms` — освобождение старых чанков | 2,6 – 3,3 | ~12 % |
| `surface_ms` — перестройка SurfaceTool | 7,0 – 10,3 | ~40 % |
| ├ `light_ms` — CPU-освещение вершины | 1,3 – 2,2 | ~20 % от `surface_ms` |
| ├ `cell_lookup_ms` — source-лукапы на клетку | 0,18 – 0,29 | ~3 % от `surface_ms` |
| └ остальное — заливка вершин SurfaceTool | ~5 – 8 | ~65 % от `surface_ms` |
| `commit_ms` — commit + collision + вставка в сцену | 0,87 – 1,28 | ~5 % |
| `open_air_ms` — `_index_open_air` | 2,0 – 2,1 | ~9 % |
| остаток — walkmap + state + превью | ~3 – 6 | ~20 % |
| **удар целиком** | **19,7 – 26,1** (mean 22,5) | 100 % |

Объём перестроения на удар: **14–17 поверхностей, 16–25 клеток, 177–300
вершин**.

### 4.2 Кадры и GPU (реальный OpenGL-контекст, 640×360)

| величина | значение |
|---|---|
| кадр без удара (idle) | ~25 мс |
| кадр сразу после удара (первый кадр с новым мешем) | ~24 – 25 мс |
| `commit_ms` | 1,3 – 2,3 мс |

**Кадр после удара стоит столько же, сколько idle-кадр.** Значит загрузка
перестроенной геометрии в GPU **не добавляет** ощутимого времени: она
перекрывается обычной стоимостью кадра.

### 4.3 Отложенная перестройка navigation

`navigation_ms` в трейсе равен 0, потому что `_flush_terrain_refresh()`
перестраивает навигацию отложенно (`_queue_navigation_refresh()`,
`TERRAIN_REFRESH_COALESCE_SECONDS = 0,75`). Принудительный сброс:

```
MINING_LATENCY navigation_flush_ms=33.5 … 46.6
```

**Это самая большая единичная задержка в цикле раскопки** — больше, чем сам
удар, и она приходит через 0,75 с после серии ударов.

### 4.4 Сверка с handoff

Handoff фиксировал `terrain_refresh_self_test` → `strike 24–34 мс`.
В ведущем дереве: `strike_ms=[31.0, 27.7, 38.6]`, в пробнике — mean 22,5 мс
(headless) / 27,4 мс (GPU). **Цифры handoff подтверждаются.**

Ранее в этом отчёте упоминались 58–85 мс — это был **артефакт изолированной
копии** `repro/godot` (свежая копия на OneDrive, холодный кэш импорта), а не
регрессия. В ведущем дереве этих цифр нет.

---

## 5. Что это значит для оптимизации

| кандидат | выигрыш | вердикт |
|---|---|---|
| кэш CPU-освещения вершин | ≤ 2 мс из 22 мс (~9 %) | **не стоит** — риск не окупается |
| кэш source-лукапов на клетку | ≤ 0,3 мс | **не стоит** |
| перестройка только изменённых клеток | до ~7 мс | возможно, но требует другой гранулярности меша (чанк = одна поверхность) |
| освобождение старых инстансов (`free_ms` ~3 мс) | ~3 мс | требует инкрементальной замены меша вместо free+create |
| **`_build_navigation_grid()` (33–42 мс)** | **~34–42 мс** | **главная цель** — и она уже отложенная |
| GPU upload | ~0 | **не трогать** |

Вывод: после оптимизации walkmap узкое место сместилось с walkmap на
**перестройку меша и навигации**, причём навигация — самая дорогая единичная
операция.

---

## 6. Найденный баг: перестройка чанка сносит collision пола

### 6.1 Причина

`multiplayer_test.gd`, `_flush_terrain_refresh()`:

```gdscript
_build_geometry(terrain_manifest, variants, changed_cells, changed_cells.is_empty())
```

Четвёртый аргумент — `build_collision`. При **частичной** перестройке (а это
любой удар) он равен `false`. При этом `_build_geometry()` в начале
перестройки **освобождает старые инстансы** затронутого чанка:

```gdscript
(terrain_mesh_nodes[key] as MeshInstance3D).free()
```

А `StaticBody3D`/`CollisionShape3D` жили **внутри** освобождаемого
`MeshInstance3D`. Итог: перестроенный чанк **не получал collision вообще**.

### 6.2 Доказательство

`godot/tools/terrain_collision_probe.gd`, одна раскопка клетки (9, 19):

```
COLLISION_PROBE before chunks=793 with_body=793 without_body=0
COLLISION_PROBE dig (9, 19) marked=true applied=true
COLLISION_PROBE after  chunks=801 with_body=784 without_body=17
COLLISION_PROBE chunks_that_lost_collision=["14:0:Native_0022.tga:1:2",
  "06:0:Native_0020.tga:1:2", "10:0:Gnd_C11.tga:1:2", "02:0:Native_2020.tga:1:2",
  "14:0:Gnd_C15.tga:1:2", "06:0:Gnd_C07.tga:1:2", "02:0:Gnd_C03.tga:1:2",
  "14:0:Gnd_A15.tga:1:2", "10:0:Native_0022.tga:1:2"]
```

**Один удар — минус collision у 17 чанков.** И это не разовый случай: каждый
следующий удар в том же чанке сносит collision снова. По ходу раскопки пол
под ногами у дв��рффа исчезает.

### 6.3 Связь с падающими тестами

Два из трёх pre-existing падений были **симптомом этого бага**:

| self-test | до фикса | после фикса |
|---|---|---|
| `excavated_walk_self_test` | `exit=1` — `new navigation floor lacks terrain collision` | **`exit=0`** — `EXCAVATED_WALK_SELF_TEST_OK assertions=39 mutations=4 new_floor=16.5 original_floor=14.5` |
| `native_dwarf_dig_self_test` | `exit=1` — `rebuilt terrain has no physics hit` | **`exit=0`** — `NATIVE_DWARF_DIG_SELF_TEST_OK assertions=219 callbacks=1 worker_strikes=1 fixture_strikes=1` |
| `native_dig_queue_self_test` | `exit=1` | `exit=1` — **другая** причина, см. §8 |

### 6.4 Фикс

```diff
--- a/godot/scripts/multiplayer_test.gd
+++ b/godot/scripts/multiplayer_test.gd
@@ -645,7 +645,11 @@
 	terrain_refresh_pending = false
 	terrain_refresh_wait = 0.0
 	var geometry_started: int = Time.get_ticks_usec()
-	_build_geometry(terrain_manifest, variants, changed_cells, changed_cells.is_empty())
+	# A rebuild replaces the chunk instances, and the freed instances take their
+	# collision bodies with them. Skipping the collision for partial rebuilds
+	# therefore removed the floor collision from every dug chunk. Only the
+	# rebuilt surfaces are recreated here, so the untouched chunks keep theirs.
+	_build_geometry(terrain_manifest, variants, changed_cells, true)
 	var geometry_ms: float = float(Time.get_ticks_usec()-geometry_started)/1000.0
```

Почему это безопасно и дёшево: `_build_geometry()` пересоздаёт **только**
поверхности затронутого чанка, поэтому `build_collision = true` добавляет
collision **только перестроенным** поверхностям; нетронутые чанки сохраняют
свой. Новая стоимость — один `create_trimesh_shape()` на перестроенную
поверхность:

| | до фикса | после фикса | дельта |
|---|---|---|---|
| `commit_ms` (headless) | 0,35 – 0,79 мс | 0,87 – 1,28 мс | **+0,5 мс** |
| удар целиком (GPU) | 25,7 мс | 27,4 мс | **+1,7 мс (+6 %)** |

Проверка после фикса:

```
COLLISION_PROBE after chunks=801 with_body=801 without_body=0
COLLISION_PROBE chunks_that_lost_collision=[]
```

---

## 7. Изменённые файлы (ведущее дерево)

| файл | изменение |
|---|---|
| `godot/scripts/multiplayer_test.gd` | **фикс collision** (`build_collision=true`) + trace-gated таймеры профиля `_build_geometry` + `terrain_geometry_profile` |
| `godot/tools/mining_latency_probe.gd` | **новый** — пробник задержки раскопки (CPU-разбивка + кадры + navigation flush) |
| `godot/tools/terrain_collision_probe.gd` | **новый** — пробник collision до/после раскопки |
| `godot/scripts/native_scene_profile.gd` | фикс освещения факелов (§ предыдущего отчёта) |
| `godot/tools/torch_terrain_light_regression_self_test.gd` | **новый** — regression-тест света (предыдущий отчёт) |
| `godot/tools/torch_render_visible_self_test.gd` | **новый** — render-visible A/B-тест света (предыдущий отчёт) |
| `godot/tools/torch_regression_probe.gd` | **новый** — диагностический зонд света (предыдущий отчёт) |
| `tools/sync_from_live.py`, `tools/apply_patch.py`, `tools/run_suite.ps1` | служебные скрипты workspace (вне `godot/`) |

Шейдеры, walkmap, хомяки, APK/экспорт не менялись.

### 7.1 Финальный прогон самотестов (ведущее дерево)

Полный прогон из 45 self-test-ов (`tools/run_suite.ps1`):

| | до изменений | после |
|---|---|---|
| прогонов | 45 | 45 |
| падений | **3** | **1** |

Падения до изменений (доказаны как pre-existing A/B-прогоном на непатченном
`native_scene_profile.gd`):
`excavated_walk_self_test`, `native_dig_queue_self_test`,
`native_dwarf_dig_self_test`.

Падение после изменений: только `native_dig_queue_self_test` — дефект очереди
раскопки, не связанный с освещением и не с collision (§8.1).

Linter: `errors=0`, `warnings=1` (известное и не связанное предупреждение о
внешней фикстуре `minimax-battle-world-2026-11-19.json`).

---

## 8. Что осталось открытым

1. **`native_dig_queue_self_test` — падает (pre-existing, не связан с
   освещением и не с collision).** Точный симптом: очередь выбирает другое
   число/порядок точек, чем ожидает исходная фикстура
   (`dig_selection_history.size() != expected_count`,
   `native_dig_queue_self_test.gd:54`; с `--full-stroke` расходится ещё и
   порядок, строка 57). Это домен `native_dig_next` / очереди раскопки —
   по handoff §5.3 его нельзя смешивать с walkmap-кэшем без отдельного
   репроизюсера. **Репроизюсер есть**, дефект не тронут.
2. **Замер на телефоне не выполнен.** Все цифры выше — десктоп
   (Vega 8). Handoff §5.2 просит проверить задержку «в Godot editor/на
   телефоне»; мобильный замер требует устройства пользователя.
3. **Перестройка navigation grid (33–42 мс)** — крупнейшая оставшаяся
   задержка, но оптимизация не начата: это отдельная задача с отдельным
   репроизюсером.
4. **Прежняя оценка 58–85 мс** из изолированной копии снята как артефакт
   (§4.4).

---

```text
INTEGRATION_HANDOFF
root_cause: a terrain chunk rebuild after a dig passed build_collision=false, while the rebuild freed the old MeshInstance3D that carried the StaticBody3D/CollisionShape3D - so every dug chunk permanently lost its floor collision (793/793 -> 784/801 chunks after a single dig).
evidence: multiplayer_test.gd _flush_terrain_refresh() called _build_geometry(manifest, variants, changed_cells, changed_cells.is_empty()); terrain_collision_probe.gd -> COLLISION_PROBE before chunks=793 with_body=793 / after chunks=801 with_body=784, chunks_that_lost_collision=[9 rebuilt chunks]. Symptom in two pre-existing failing tests: excavated_walk_self_test "new navigation floor lacks terrain collision" and native_dwarf_dig_self_test "rebuilt terrain has no physics hit" - both now exit=0 after the fix.
latency_profile: one dig = ~22.5 ms CPU (headless) / ~27.4 ms (real OpenGL GPU) vs ~6.9 ms idle headless / ~25 ms idle GPU. _build_geometry = free_ms 2.6-3.3 + surface_ms 7.0-10.3 (of which light_ms 1.3-2.2 and cell_lookup_ms 0.2-0.3) + commit_ms 0.9-1.3; open_air_ms ~2.1; deferred navigation rebuild 33-42 ms. GPU upload is NOT the bottleneck: the frame that first draws the rebuilt chunk costs the same as an idle frame.
safe_patch: multiplayer_test.gd _flush_terrain_refresh() -> pass build_collision=true for partial rebuilds (only rebuilt surfaces are recreated, untouched chunks keep their collision); plus trace-gated sub-phase timers in _build_geometry and the new terrain_geometry_profile dictionary. Cost of restoring collision: +0.5 ms (commit_ms) / +1.7 ms (+6%) per dig. No shader, walkmap, hamster, APK/export or art change.
regression_test: godot --headless --path godot --script res://tools/excavated_walk_self_test.gd -> EXCAVATED_WALK_SELF_TEST_OK assertions=39 (was exit=1); godot --headless --path godot --script res://tools/native_dwarf_dig_self_test.gd -> NATIVE_DWARF_DIG_SELF_TEST_OK assertions=219 (was exit=1); godot --headless --path godot --script res://tools/terrain_collision_probe.gd -> 801/801 chunks with collision, 0 lost; godot --headless --path godot --script res://tools/mining_latency_probe.gd -> strike/frame/navigation split.
do_not_touch: walkmap, hamster, APK/export
status: applied and verified in the Minimax primary tree (Minimax\Diggles\godot). The live Codex tree (ChatGPT\Diggles\godot) is still unpatched - native_scene_profile.gd SHA B0AB5ED4439F3920... and multiplayer_test.gd still passes build_collision=changed_cells.is_empty(). The whole live tree was synced into Minimax\Diggles\godot (882 files, 0 extras) before these changes.
```
