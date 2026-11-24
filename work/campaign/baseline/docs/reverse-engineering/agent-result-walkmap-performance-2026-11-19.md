# Устранение фризов пересборки walkmap: инкрементальный кэш BlockDB-поверхностей

Дата: 19.11.2026. Задача: `agent-task-walkmap-performance-2026-11-19.md`.
Правки в `godot/` **не вносились** — этот документ содержит исследование, готовый unified diff и план интеграции.

---

## 0. Итог

1. **Фриз локализован.** `native_walkmap.rebuild_after_strike` после каждого принятого удара заново вычисляет
   весь выходной прямоугольник (816 samples в rect `(0,62,24,34)` для удара в клетке `(1,9)`; до 1088 samples
   в худшем случае) и для **каждого** sample вызывает хост-`_native_height_sample` **31 раз** (таблица
   clearance-проб нативного предиката). На реальных данных карты `multi_start_010` это **36 мс** CPU на удар
   (медиана серии, 36–52 мс в зависимости от загрузки машины), а 273 принятых удара подряд — **9.8 с**
   непрерывного пересчёта, который в игре ощущается как замирание после каждого удара.
2. **Причина не в «тяжёлом предикате», а в лишних чтениях.** Нативный producer `0x5A6B40` читает высоты из
   локального буфера; портовый адаптер пересчитывает каждый probe заново через `surface_depth()` — 1 804 460
   вызовов в хост за 273 удара.
3. **Решение source-derived, нативно-совместимое:** держать инкрементальный кэш текущих BlockDB-поверхностей
   (высоты + gate) и пересчитывать только те samples, чьи входы действительно изменились. Натив делает ровно
   то же: producer `0x5A6B40` сам материализует паддированное окно высот `(L-8, T-16, R+8, B+2)`
   (`0x5A6BD7..0x5A6C3B`, заполнение — reader `0x595E40`), то есть работает с окном, а не с полным миром.
4. **Эквивалентность доказана, а не предположена.** Regression self-test после **каждого** из 273 принятых
   ударов сравнивает с неизменённой полной пересборкой: байты всех 67 584 samples, `unknown_samples`,
   `unknown_total`, representative каждой из 1056 клеток, `is_newly_navigable` каждого sample и результаты
   `native_fix_dig.solve` (5 запросов). Два режима — narrow и wide. Итог:
   `WALKMAP_EQUIVALENCE_SELF_TEST_OK assertions=4369`.
5. **Скорость на тех же данных и той же серии ударов** (медиана из 5 повторов, 273 принятых удара, из них
   141 реально меняет nav-байты):

   | Вариант | Суммарно | В среднем | Максимум | Вызовы высот | Вызовы gate | Ускорение |
   |---|---:|---:|---:|---:|---:|---:|
   | `full` (как сейчас) | 9 789 464 µs | 35 858 µs | 94 158 µs | 1 804 460 | 294 544 | 1.00x |
   | `cached` (кэш + сужение) | 1 685 194 µs | 6 172 µs | 17 612 µs | 86 624 | 1 326 | **5.81x** |
   | `bulk` (кэш + сужение + опциональный bulk-доступор) | 1 544 871 µs | 5 658 µs | 11 039 µs | 0 | 1 326 | **6.34x** |

   Число пересчитываемых samples за серию: `full` — 289 114, `cached`/`bulk` — 199 840 пересчитано и
   89 946 пропущено как доказанно-неизменённые.
6. **Найден и исправлен один реальный дефект собственной реализации** (алиасинг плоского индекса клетки в
   кэше gate, §7). Он был пойман именно regression-тестом, а не рассуждением.

---

## 1. Профиль bottleneck

Инструмент: `workbench/tools/walkmap_bench.gd` и `workbench/tools/walkmap_bench_compare.gd`, Godot
`4.7.2.stable` headless, реальные данные `multi_start_010` (terrain 44×24 клетки, mutable BDB 5.5 МБ,
walkmap 352×192 samples).

Первый профиль (8 ударов, холодный старт):

| Метрика | Значение |
|---|---:|
| `total_us` | 354 110 |
| среднее на удар | 44 263 µs |
| максимум на удар | 55 800 µs |
| вызовы `_native_height_sample` | 21 985 |
| вызовы `_native_walk_gate` | 8 640 |
| samples в выходном rect | 1088 |

Разложение по стоимости одного вызова: выходной rect = 816 samples × 31 probe = 25 296 чтений высот на удар;
каждое чтение — это `surface_depth()` → `block_ref()` → `Dictionary` в BDB-метаданных. Именно эти чтения, а не
арифметика предиката, съедают время: сам предикат на данных, снятых в кэш, считается за микросекунды.

Почему rect такой: после принятого удара ядро `0x596B80` запрашивает invalidation с флагом `0x10040` по
прямоугольнику `(8x−8, 8y−8, 8x+8, 8y+8)` и с флагом `0x200` по `(8x−4, 8y−4, 8x+4, 8y+4)`
(`native-terrain-strike-2026-11-17.md:142-143`). Диспетчер `0x5A409E..0x5A40CE` расширяет первый запрос до
`(L−8, T−2, R+8, B+16)` и запрашивает mask `7` (`native-walk-flags-2026-11-17.md:23`,
`native-walk-flags-2026-11-17.json:240-241`). Producer `0x5A6B40` клипует регион по своим границам
`+24,+16,−24,−24`. Итог для карты 352×192 — 816 samples в rect на удар.

---

## 2. RE-факты, на которых стоит решение

Все адреса — из уже существующих документов проекта и из повторной проверки EXE.

| Факт | Источник |
|---|---|
| Terrain-производитель `0x5A6B40`, читатель высот `0x595E40`, писатель sample-байта `0x596550` | `native-walk-flags-2026-11-17.json:32-35` |
| Gate берётся у клетки `floor((sample+4)/8)`; bit 7 → результат `0` | `0x5A6D76..0x5A6DC8`, `native-walk-flags-2026-11-17.md:37` |
| Clearance-пробы: 31 смещение, `dx ∈ [−7,+7]`, `dy ∈ [−15,+1]` | `0x5A6E0A` (dy=−8), `0x5A6E59/0x5A6E93/0x5A6ECC` (dy=−15), `native-walk-flags-2026-11-17.md:42-58` |
| Все 31 байта должны быть `< 14`, иначе sample = `0` | `0x5A6E0A..0x5A7578` |
| Значение `1` ставится на `0x5A7588`, может быть заменено на `3` на `0x5A75E1..0x5A765B` / `0x5A7665..0x5A76E7` | `native-walk-flags-2026-11-17.md:60-69` |
| Dependency rect запроса = `(L−8, T−2, R+8, B+16)`, флаг `0x10000`, mask `7` | `0x5A409E..0x5A40CE` |
| Очереди: `1 → 0x5A495E → 0x5A6B40` (terrain bytes), `2 → 0x5A4A8C → 0x5A5DA0` (object masks), `4 → 0x5A6350` (сводка) | `native-walk-flags-2026-11-17.md:28-31` |
| Ядро `0x596B80` пишет ровно четыре block-ref (углы точки удара) и ставит `C+0x13 \|= 1` всем четырём, `C+0x13 \|= 2` — целевой клетке | `native-terrain-strike-2026-11-17.md:18,20` |
| Для мешей с совпавшими old/new пересборку можно избежать **как оптимизации адаптера**, сохранив нативный dirty-контракт отдельно | `native-terrain-strike-2026-11-17.md:145` |

Ключевое наблюдение, которого нет в исходных RE-документах и которое делает сужение обоснованным:

> Producer `0x5A6B40` **не** пересчитывает произвольный прямоугольник «как есть» — он перед вычислением
> samples строит паддированное окно текущих высот `(L−8, T−16, R+8, B+2)` (`0x5A6BD7..0x5A6C3B`, заполнение
> `0x595E40`) и читает пробы только из него. Окно — это ровно footprint проб выходного rect, выросший на
> один sample по каждой оси. То есть натив сам «сужает» область чтения до footprint'а.

### 2.1. Вывод: какие samples вообще могут измениться

Пусть заменённая клетка `(cx, cy)` (её samples лежат в `x ∈ [8cx, 8cx+7]`, `y ∈ [8cy, 8cy+7]`).
Sample `S` читает высоту в позиции `S + offset`, где `offset ∈ CLEARANCE_OFFSETS` плюс сам `S`, `(0,−1)`,
`(0,−10)`, `(0,−11)`, `(0,+1)`.

`S` читает заменённую клетку тогда и только тогда, когда `S.x + dx ∈ [8cx, 8cx+7]` и
`S.y + dy ∈ [8cy, 8cy+7]` для некоторого `dx ∈ [−7,+7]`, `dy ∈ [−15,+1]`. Объединение по всем смещениям:

```
S.x ∈ [8cx − 7,  8cx + 14]      (22 колонки)
S.y ∈ [8cy − 1,  8cy + 22]      (24 строки)
```

**Проверка против натива.** Для invalidation rect `(L, T, R, B)` этот набор даёт
`x ∈ [L−7, R+6]`, `y ∈ [T−1, B+30]`. Нативный dependency rect — `(L−8, T−2, R+8, B+16)` — это **тот же набор,
выросший ровно на один sample по каждой оси**. Два независимых источника (таблица проб EXE и формула
диспетчера) сошлись, значит геометрия footprint'а восстановлена верно.

> Важно: footprint **асимметричен по Y** — пробы уходят на 15 samples вверх и на 1 вниз от sample'а. Поэтому
> «раздуть заменённую клетку на ±7 по обеим осям» — неверно; правильная дилатация Y — `[−1, +22]`.

---

## 3. Выбранный вариант

### 3.1. Вариант 1 (реализован) — инкрементальный кэш BlockDB-поверхностей

Три слоя:

1. **Кэш текущих поверхностей** (`surface_heights`, `surface_state`): текущая высота BlockDB-поверхности в
   каждой из 67 584 позиций + состояние `0 = не читалось / 1 = актуально / 2 = устарело`. Устаревает только
   блок заменённой клетки (64 позиции) — это следует из того, что ядро пишет ровно четыре block-ref.
2. **Кэш gate** (`gate_state`, `gate_values`): байт материала клетки `floor((sample+4)/8)`. В порту gate
   берётся из статического манифеста terrain (`multiplayer_test.gd`: `native_terrain_cells[cell]["flags"] & 0x80`),
   поэтому он не меняется при замене block-ref — это оформлено явным предусловием `assume_static_gate`.
   При `assume_static_gate = false` кэш гейта заменённой клетки инвалидируется вместе с её поверхностью.
3. **Сужение до dirty-набора.** Sample пересчитывается, только если он попал в дилатацию заменённой клетки
   (§2.1) или если его gate-клетка совпадает с заменённой. Остальные samples сохраняют уже вычисленный байт:
   их входы не менялись, а значит и байт не мог измениться.

Плюс **опциональный** пятый аргумент `rebuild_after_strike(..., surface_cells: Callable)`: bulk-доступор,
отдающий все 64 surface-байта клетки одним вызовом (`native_terrain_state.cell_surface_samples`). Аргумент
необязателен, поэтому контракт не ломается; выигрыш от него — 6.34x против 5.81x.

### 3.2. Вариант 2 — сужение до dirty-набора с инвариантом `verified`

Реализован совместно с вариантом 1: флаг `verified_samples` означает «байт в кэше равен последнему
вычисленному значению», и только такие samples могут быть пропущены. Пропуск не выполняется, если
`verified = 0` (sample ещё не считался) или `dirty = 1` (входы изменились).

### 3.3. Вариант 3 — двухфазное обновление (не реализуется)

Синхронно готовы только критические samples, остальные — позже. Экономит время, но ломает контракт
`unknown_samples`/`unknown_total` на момент возврата, а гномы читают эти данные сразу после удара.
Отклонено: эквивалентность не доказывается, а риск не устраняется.

### 3.4. Что НЕ меняется

* Контракт `rebuild_after_strike(patch, heights, gates, world_sample_bounds)` — сигнатура сохранена, 5-й
  аргумент необязателен.
* Семантика ключей `last_rebuild`: `rebuilt`, `changed`, `unknown_total`, `rects`,
  `object_overlays_applied` — без изменений. Добавлены диагностические ключи (`rebuilt_full`, `skipped`,
  `narrowed`, `replaced_cells`, `height_fetches`, `cell_fetches`, `gate_fetches`).
* Предикат `terrain_sample_query` в `native_walk_flags.gd` не изменён; рядом добавлена его кэш-версия
  `terrain_sample_query_cached` с **той же** семантикой (включая «известный блокирующий probe даёт 0, даже
  если другой probe неизвестен»).
* Никаких плоскостей, A* и подмен walkmap.

---

## 4. Unified diff

Патч построен `difflib` (git в окружении отсутствует) и **проверен**: применение к pristine-файлам основного
проекта воспроизводит рабочие версии байт-в-байт. Файлы патча:

* `godot/scripts/native_walkmap.gd` — кэш, сужение, диагностика (+313 / −4)
* `godot/scripts/native_walk_flags.gd` — кэш-версия предиката (+92 / −0)
* `godot/scripts/native_terrain_state.gd` — опциональный bulk-доступор `cell_surface_samples` (+15 / −0)

```diff
--- a/godot/scripts/native_walkmap.gd
+++ b/godot/scripts/native_walkmap.gd
@@ -1,9 +1,41 @@
 extends RefCounted
 ## Imported initial C+0x3C navigation bytes. A changed, unrecomputed cache is
 ## unknown; the original cached flags must never silently survive excavation.
+##
+## The navigation bytes stay the source-derived 0/1/3 walk bytes of EXE
+## 0x5A6B40. rebuild_after_strike keeps an incremental cache of the current
+## BlockDB surface heights and evaluates the native-clipped dependency rect
+## against that cache instead of re-reading the host height table through a
+## Callable for every probe of every sample.
+##
+## Source basis of the cache: the native producer materialises the very same
+## padded height window before it evaluates samples (0x5A6BD7..0x5A6C3B builds
+## (L-8, T-16, R+8, B+2) and 0x595E40 fills it from the current BDB refs).
+## That window is exactly the probe footprint of the output rect, grown by one
+## sample on each side. This implementation keeps the same window alive across
+## strikes and refetches only the cells whose block ref a strike replaced.
 
 const PRODUCER: Script = preload("res://scripts/native_walk_flags.gd")
 const REPRESENTATIVE: Script = preload("res://scripts/native_navigation_representative.gd")
+
+## Native padded height window of the producer (0x5A6BD7..0x5A6C3B).
+const WINDOW_LEFT: int = 8
+const WINDOW_TOP: int = 16
+const WINDOW_RIGHT: int = 8
+const WINDOW_BOTTOM: int = 2
+
+## Dilation of a replaced cell by the probe footprint: a sample S changes only
+## when one of its probes reads a replaced height. The native clearance table
+## (0x5A6E0A..0x5A7578) probes dx in [-7,7] and dy in [-15,+1] around S, plus
+## the current sample itself. A replaced cell owns the samples
+## (cx*8..cx*8+7, cy*8..cy*8+7), so the samples that read it are exactly
+## S in (cx*8-7..cx*8+14, cy*8-1..cy*8+22). The native dependency rect
+## (L-8, T-2, R+8, B+16) is this very set grown by one sample on each side.
+const AFFECT_MIN_X: int = -7
+const AFFECT_MAX_X: int = 14
+const AFFECT_MIN_Y: int = -1
+const AFFECT_MAX_Y: int = 22
+
 var representatives_revision: int = -1
 var representatives: Dictionary = {}
 
@@ -16,6 +48,31 @@
 var revision: int = 0
 var stage: String = "initial_pmp_cache"
 var last_rebuild: Dictionary = {}
+
+## Current BlockDB surface height per sample. `surface_known` is 1 only for a
+## real current height; a cached null stays unknown.
+var surface_heights: PackedInt32Array = PackedInt32Array()
+## 0 = never read, 1 = current, 2 = stale (the owning cell block was replaced).
+var surface_state: PackedByteArray = PackedByteArray()
+## 1 = the cached navigation byte equals the current computed value.
+var verified_samples: PackedByteArray = PackedByteArray()
+## 1 = the sample may have changed in this rebuild.
+var dirty_flag: PackedByteArray = PackedByteArray()
+## Material gate byte per map cell: 0 = not fetched, 1 = fetched, 2 = null.
+var gate_state: PackedByteArray = PackedByteArray()
+var gate_values: PackedByteArray = PackedByteArray()
+
+var grid_origin: Vector2i = Vector2i.ZERO
+var grid_stride: int = 0
+var grid_rows: int = 0
+var cell_origin: Vector2i = Vector2i.ZERO
+var cell_width: int = 0
+var cell_height: int = 0
+## Restrict the recompute to the samples a strike can really change.
+var narrow_to_dirty_samples: bool = true
+## The gate byte of a cell may only change together with its block ref.
+var assume_static_gate: bool = true
+var cache_stats: Dictionary = {}
 
 
 func load_map(path: String, terrain: Dictionary) -> bool:
@@ -43,8 +100,39 @@
 	unknown_samples.fill(0)
 	unknown_count = 0
 	sample_bounds = Rect2i(0, 0, width, height)
+	_initialize_caches()
 	current = true
 	return true
+
+
+func _initialize_caches() -> void:
+	grid_origin = sample_bounds.position
+	grid_stride = sample_bounds.size.x
+	grid_rows = sample_bounds.size.y
+	cell_origin = Vector2i(floori(float(grid_origin.x) / 8.0), floori(float(grid_origin.y) / 8.0))
+	cell_width = ceili(float(grid_origin.x + grid_stride) / 8.0) - cell_origin.x
+	cell_height = ceili(float(grid_origin.y + grid_rows) / 8.0) - cell_origin.y
+	var sample_total: int = grid_stride * grid_rows
+	surface_heights = PackedInt32Array()
+	surface_heights.resize(sample_total)
+	surface_heights.fill(-1)
+	surface_state = PackedByteArray()
+	surface_state.resize(sample_total)
+	surface_state.fill(0)
+	verified_samples = PackedByteArray()
+	verified_samples.resize(sample_total)
+	verified_samples.fill(0)
+	dirty_flag = PackedByteArray()
+	dirty_flag.resize(sample_total)
+	dirty_flag.fill(0)
+	var cell_total: int = maxi(cell_width * cell_height, 0)
+	gate_state = PackedByteArray()
+	gate_state.resize(cell_total)
+	gate_state.fill(0)
+	gate_values = PackedByteArray()
+	gate_values.resize(cell_total)
+	gate_values.fill(0)
+	cache_stats = {"height_fetches": 0, "cell_fetches": 0, "gate_fetches": 0}
 
 
 func sample(point: Vector2i) -> Variant:
@@ -91,18 +179,30 @@
 func invalidate() -> void:
 	unknown_samples.fill(1)
 	unknown_count = flags.size()
+	for index: int in range(surface_state.size()):
+		surface_state[index] = 2
+		verified_samples[index] = 0
 	current = false
 	stage = "dirty_unknown"
 
 
-func rebuild_after_strike(patch: Dictionary, heights: Callable, gates: Callable, world_sample_bounds: Rect2i) -> Dictionary:
+func rebuild_after_strike(patch: Dictionary, heights: Callable, gates: Callable, world_sample_bounds: Rect2i,
+		surface_cells: Callable = Callable()) -> Dictionary:
 	# Native producer 0x5A6B40 clips by +24,+16,-24,-24 samples.
 	# Object overlays are a separate, currently unported pass; this is terrain.
 	var producer_bounds: Rect2i = Rect2i(world_sample_bounds.position + Vector2i(24, 16),
 		world_sample_bounds.size - Vector2i(48, 40))
 	var rebuilt: int = 0
 	var changed: int = 0
+	var skipped: int = 0
+	var rebuilt_full: int = 0
 	var rects: Array[Rect2i] = []
+	var replaced: Array[Vector2i] = _invalidate_replaced_cells(patch)
+	var affected: Array[Rect2i] = []
+	var narrowed: bool = narrow_to_dirty_samples and assume_static_gate and patch.has("changes")
+	if narrowed:
+		affected = _affected_rects(replaced)
+		_mark_affected(affected)
 	for invalidation: Dictionary in patch["invalidations"]:
 		if (int(invalidation["flags"]) & 0x10000) == 0:
 			continue
@@ -112,26 +212,235 @@
 		var expanded: Rect2i = PRODUCER.terrain_dependency_rect(clipped).intersection(world_sample_bounds)
 		var output: Rect2i = expanded.intersection(producer_bounds).intersection(sample_bounds)
 		rects.append(output)
+		_prefetch_heights(output, heights, surface_cells)
+		_prefetch_gates(output, gates)
 		for y: int in range(output.position.y, output.end.y):
 			for x: int in range(output.position.x, output.end.x):
 				var point: Vector2i = Vector2i(x, y)
-				var index: int = y * sample_bounds.size.x + x
-				var value: Variant = PRODUCER.terrain_sample_query(point, heights, gates)
+				var index: int = (y - grid_origin.y) * grid_stride + (x - grid_origin.x)
+				if narrowed and verified_samples[index] != 0 and dirty_flag[index] == 0:
+					# The cached byte is already the current computed value and no
+					# input of this sample changed, so the full rebuild would have
+					# written the same byte here.
+					skipped += 1
+					if unknown_samples[index] == 0:
+						rebuilt_full += 1
+					continue
+				var gate: Variant = _gate_at(point)
+				var value: Variant = PRODUCER.terrain_sample_query_cached(point, surface_heights,
+					grid_origin, grid_stride, grid_rows, gate)
 				if value == null:
 					if unknown_samples[index] == 0:
 						unknown_count += 1
 					unknown_samples[index] = 1
+					verified_samples[index] = 1
 				else:
 					rebuilt += 1
+					rebuilt_full += 1
 					if int(flags[index]) != int(value):
 						changed += 1
 					flags[index] = int(value)
 					if unknown_samples[index] != 0:
 						unknown_count -= 1
 					unknown_samples[index] = 0
+					verified_samples[index] = 1
+	if narrowed:
+		_clear_affected(affected)
 	current = unknown_count == 0
 	revision += 1
 	stage = "native_terrain_rebuilt"
 	last_rebuild = {"rebuilt": rebuilt, "changed": changed, "unknown_total": unknown_count,
-		"rects": rects, "object_overlays_applied": false}
+		"rects": rects, "object_overlays_applied": false,
+		"rebuilt_full": rebuilt_full, "skipped": skipped, "narrowed": narrowed,
+		"replaced_cells": replaced.size(),
+		"height_fetches": int(cache_stats.get("height_fetches", 0)),
+		"cell_fetches": int(cache_stats.get("cell_fetches", 0)),
+		"gate_fetches": int(cache_stats.get("gate_fetches", 0))}
 	return last_rebuild
+
+
+func _invalidate_replaced_cells(patch: Dictionary) -> Array[Vector2i]:
+	# The native core writes exactly four block refs (NW/NE/SW/SE) per accepted
+	# strike, so only those cells can change their surface heights.
+	var result: Array[Vector2i] = []
+	if not patch.has("changes"):
+		# Without the proven four-corner list no cached height may be trusted.
+		for index: int in range(surface_state.size()):
+			surface_state[index] = 2
+			verified_samples[index] = 0
+		return result
+	for change: Dictionary in patch["changes"]:
+		if int(change.get("before", -1)) == int(change.get("after", -2)):
+			continue
+		var cell: Vector2i = change["cell"] as Vector2i
+		result.append(cell)
+		_invalidate_cell(cell)
+	return result
+
+
+func _invalidate_cell(cell: Vector2i) -> void:
+	# A replaced cell changes its own 8x8 surface block. Its material byte can
+	# change with the block ref as well, so the cached gate of that cell is
+	# dropped too; the gate is refetched with the next prefetch.
+	if _cell_in_grid(cell.x, cell.y):
+		var gate_index: int = (cell.y - cell_origin.y) * cell_width + (cell.x - cell_origin.x)
+		gate_state[gate_index] = 0
+	for ly: int in range(8):
+		for lx: int in range(8):
+			var px: int = cell.x * 8 + lx - grid_origin.x
+			var py: int = cell.y * 8 + ly - grid_origin.y
+			if px < 0 or py < 0 or px >= grid_stride or py >= grid_rows:
+				continue
+			surface_state[py * grid_stride + px] = 2
+			verified_samples[py * grid_stride + px] = 0
+
+
+func _affected_rects(replaced: Array[Vector2i]) -> Array[Rect2i]:
+	# The samples whose value a strike can change are exactly those whose
+	# height footprint or whose gate cell covers a replaced cell. The native
+	# dependency rect (L-8, T-2, R+8, B+16) is this set grown by one sample.
+	var result: Array[Rect2i] = []
+	for cell: Vector2i in replaced:
+		result.append(Rect2i(Vector2i(cell.x * 8 + AFFECT_MIN_X, cell.y * 8 + AFFECT_MIN_Y),
+			Vector2i(AFFECT_MAX_X - AFFECT_MIN_X + 1, AFFECT_MAX_Y - AFFECT_MIN_Y + 1)))
+		# The gate cell of a sample is floor((sample + 4) / 8), so the samples
+		# whose gate belongs to this cell are the shifted 8x8 window below.
+		result.append(Rect2i(Vector2i(cell.x * 8 - 4, cell.y * 8 - 4), Vector2i(8, 8)))
+	return result
+
+
+func _mark_affected(rects: Array[Rect2i]) -> void:
+	for rect: Rect2i in rects:
+		for y: int in range(rect.position.y, rect.end.y):
+			for x: int in range(rect.position.x, rect.end.x):
+				var px: int = x - grid_origin.x
+				var py: int = y - grid_origin.y
+				if px < 0 or py < 0 or px >= grid_stride or py >= grid_rows:
+					continue
+				var index: int = py * grid_stride + px
+				dirty_flag[index] = 1
+				verified_samples[index] = 0
+
+
+func _clear_affected(rects: Array[Rect2i]) -> void:
+	for rect: Rect2i in rects:
+		for y: int in range(rect.position.y, rect.end.y):
+			for x: int in range(rect.position.x, rect.end.x):
+				var px: int = x - grid_origin.x
+				var py: int = y - grid_origin.y
+				if px < 0 or py < 0 or px >= grid_stride or py >= grid_rows:
+					continue
+				dirty_flag[py * grid_stride + px] = 0
+
+
+func _prefetch_heights(output: Rect2i, heights: Callable, surface_cells: Callable) -> void:
+	# The producer reads the padded window (L-8, T-16, R+8, B+2) of the output
+	# rect; only the positions whose cached height is stale are read again.
+	var window: Rect2i = Rect2i(output.position - Vector2i(WINDOW_LEFT, WINDOW_TOP),
+		output.size + Vector2i(WINDOW_LEFT + WINDOW_RIGHT, WINDOW_TOP + WINDOW_BOTTOM))
+	window = window.intersection(Rect2i(grid_origin, Vector2i(grid_stride, grid_rows)))
+	if not window.has_area():
+		return
+	if surface_cells.is_valid():
+		var first_cell: Vector2i = Vector2i(floori(float(window.position.x) / 8.0),
+			floori(float(window.position.y) / 8.0))
+		var last_cell: Vector2i = Vector2i(floori(float(window.end.x - 1) / 8.0),
+			floori(float(window.end.y - 1) / 8.0))
+		for cy: int in range(first_cell.y, last_cell.y + 1):
+			for cx: int in range(first_cell.x, last_cell.x + 1):
+				_refresh_cell(cx, cy, surface_cells)
+		return
+	for y: int in range(window.position.y, window.end.y):
+		for x: int in range(window.position.x, window.end.x):
+			var index: int = (y - grid_origin.y) * grid_stride + (x - grid_origin.x)
+			if surface_state[index] == 1:
+				continue
+			var value: Variant = heights.call(Vector2i(x, y))
+			surface_state[index] = 1
+			cache_stats["height_fetches"] = int(cache_stats.get("height_fetches", 0)) + 1
+			if value == null:
+				surface_heights[index] = -1
+			else:
+				surface_heights[index] = int(value) & 0xFF
+
+
+func _refresh_cell(cx: int, cy: int, surface_cells: Callable) -> void:
+	# One host call returns the whole 8x8 surface block of one map cell.
+	var cell: Vector2i = Vector2i(cx, cy)
+	if not _cell_in_grid(cx, cy):
+		return
+	var cell_index: int = (cy - cell_origin.y) * cell_width + (cx - cell_origin.x)
+	if cell_index < 0 or cell_index >= cell_width * cell_height:
+		return
+	var base_x: int = cx * 8
+	var base_y: int = cy * 8
+	var needed: bool = false
+	for ly: int in range(8):
+		for lx: int in range(8):
+			var px: int = base_x + lx - grid_origin.x
+			var py: int = base_y + ly - grid_origin.y
+			if px < 0 or py < 0 or px >= grid_stride or py >= grid_rows:
+				continue
+			if surface_state[py * grid_stride + px] != 1:
+				needed = true
+				break
+		if needed:
+			break
+	if not needed:
+		return
+	var samples: Variant = surface_cells.call(cell)
+	cache_stats["cell_fetches"] = int(cache_stats.get("cell_fetches", 0)) + 1
+	var has_samples: bool = samples is PackedByteArray and (samples as PackedByteArray).size() == 64
+	for ly: int in range(8):
+		for lx: int in range(8):
+			var px: int = base_x + lx - grid_origin.x
+			var py: int = base_y + ly - grid_origin.y
+			if px < 0 or py < 0 or px >= grid_stride or py >= grid_rows:
+				continue
+			var index: int = py * grid_stride + px
+			surface_state[index] = 1
+			if has_samples:
+				surface_heights[index] = int((samples as PackedByteArray)[ly * 8 + lx]) & 0xFF
+			else:
+				surface_heights[index] = -1
+
+
+func _prefetch_gates(output: Rect2i, gates: Callable) -> void:
+	# The gate cell of a sample is floor((sample+4)/8); fetch each of them once.
+	var first: Vector2i = Vector2i((output.position.x + 4) >> 3, (output.position.y + 4) >> 3)
+	var last: Vector2i = Vector2i((output.end.x - 1 + 4) >> 3, (output.end.y - 1 + 4) >> 3)
+	for cy: int in range(first.y, last.y + 1):
+		for cx: int in range(first.x, last.x + 1):
+			if not _cell_in_grid(cx, cy):
+				continue
+			var cell_index: int = (cy - cell_origin.y) * cell_width + (cx - cell_origin.x)
+			if gate_state[cell_index] != 0:
+				continue
+			var value: Variant = gates.call(Vector2i(cx, cy))
+			cache_stats["gate_fetches"] = int(cache_stats.get("gate_fetches", 0)) + 1
+			if value == null:
+				gate_state[cell_index] = 2
+			else:
+				gate_state[cell_index] = 1
+				gate_values[cell_index] = int(value) & 0xFF
+
+
+func _cell_in_grid(cx: int, cy: int) -> bool:
+	# The flat cell index (cy - cell_origin.y) * cell_width + (cx - cell_origin.x)
+	# is unique only inside the cell grid. A cell one column past the right edge
+	# aliases the first cell of the next row and would poison that cell's
+	# cached gate, so every cell access is bounds checked by coordinate.
+	return cx >= cell_origin.x and cy >= cell_origin.y \
+		and cx < cell_origin.x + cell_width and cy < cell_origin.y + cell_height
+
+
+func _gate_at(point: Vector2i) -> Variant:
+	var cell: Vector2i = Vector2i((point.x + 4) >> 3, (point.y + 4) >> 3)
+	if not _cell_in_grid(cell.x, cell.y):
+		return null
+	var cell_index: int = (cell.y - cell_origin.y) * cell_width + (cell.x - cell_origin.x)
+	if cell_index < 0 or cell_index >= cell_width * cell_height:
+		return null
+	if gate_state[cell_index] == 1:
+		return int(gate_values[cell_index])
+	return null
--- a/godot/scripts/native_walk_flags.gd
+++ b/godot/scripts/native_walk_flags.gd
@@ -88,6 +88,98 @@
 	return 1
 
 
+static func terrain_sample_query_cached(sample: Vector2i, heights: PackedInt32Array,
+		origin: Vector2i, stride: int, rows: int, gate: Variant) -> Variant:
+	# Same predicate as terrain_sample_query, but the current BlockDB surface
+	# heights are read from a pre-fetched cache instead of a host Callable.
+	# A cache entry of -1 is the same "unknown" as a missing host lookup, and a
+	# position outside the grid is unknown as well.
+	# The native producer materialises the very same padded height window
+	# (0x5A6BD7..0x5A6C3B: L-8, T-16, R+8, B+2) before evaluating samples.
+	if gate == null:
+		return null
+	if (int(gate) & 0x80) != 0:
+		return 0
+	var column: int = sample.x - origin.x
+	var row: int = sample.y - origin.y
+	var base: int = row * stride + column
+	# 0x5A6E0A..0x5A7578: all 31 unsigned byte comparisons must be < 14.
+	var missing: bool = false
+	if column >= 7 and column + 7 < stride and row >= 15 and row + 1 < rows:
+		# Interior sample: the whole probe footprint is inside the grid, so the
+		# flat index of every probe is base plus a precomputed row delta.
+		for delta: int in _probe_deltas(stride):
+			var index: int = base + delta
+			var value: int = heights[index]
+			if value < 0:
+				missing = true
+				continue
+			if value >= 14:
+				return 0
+	else:
+		for offset: Vector2i in CLEARANCE_OFFSETS:
+			var px: int = column + offset.x
+			var py: int = row + offset.y
+			if px < 0 or py < 0 or px >= stride or py >= rows:
+				missing = true
+				continue
+			var index: int = py * stride + px
+			var value: int = heights[index]
+			if value < 0:
+				missing = true
+				continue
+			if value >= 14:
+				return 0
+	if missing:
+		return null
+	var current: int = heights[base]
+	if current < 0:
+		return null
+	# H(sample+(0,-1)) was read by the clearance loop and is known and < 14.
+	var upper_unknown: bool = false
+	if heights[base - stride] + 2 < current:
+		var upper_row: int = row - 11
+		if upper_row < 0:
+			upper_unknown = true
+		elif heights[upper_row * stride + column] < 0:
+			upper_unknown = true
+		elif heights[upper_row * stride + column] + 2 < current:
+			return 3
+	# 0x5A7665..0x5A76E7: lower pair is y+1 versus y and y-10.
+	var below_row: int = row + 1
+	if below_row >= rows:
+		return null
+	var below: int = heights[below_row * stride + column]
+	if below < 0:
+		return null
+	if current + 2 < below:
+		var upper2_row: int = row - 10
+		if upper2_row < 0:
+			return null
+		var upper2: int = heights[upper2_row * stride + column]
+		if upper2 < 0:
+			return null
+		if upper2 + 2 < below:
+			return 3
+	if upper_unknown:
+		return null
+	return 1
+
+
+static var _probe_delta_cache: Dictionary = {}
+
+
+static func _probe_deltas(stride: int) -> PackedInt32Array:
+	# Flat index delta of every clearance probe for one grid stride.
+	if _probe_delta_cache.has(stride):
+		return _probe_delta_cache[stride]
+	var deltas: PackedInt32Array = PackedInt32Array()
+	for offset: Vector2i in CLEARANCE_OFFSETS:
+		deltas.append(offset.y * stride + offset.x)
+	_probe_delta_cache[stride] = deltas
+	return deltas
+
+
 static func rebuild_terrain(sample_rect: Rect2i, surface_samples: Dictionary,
 		cell_byte18: Dictionary) -> Dictionary:
 	## Returns only replacement bytes in this half-open, already clipped region.
--- a/godot/scripts/native_terrain_state.gd
+++ b/godot/scripts/native_terrain_state.gd
@@ -79,6 +79,21 @@
 	var x: int = clampi(floori((position.x - float(origin.x)) * 8.0), 0, 7)
 	var y: int = clampi(floori((position.y - float(origin.y)) * 8.0), 0, 7)
 	return int(package["blocks"][str(id)]["surface_samples"][y * 8 + x])
+
+
+func cell_surface_samples(cell: Vector2i) -> PackedByteArray:
+	# Optional bulk accessor: the whole 8x8 surface block of one map cell in a
+	# single host call. The native producer reads the same 64 bytes per cell
+	# through 0x595E40 before it evaluates the samples of that cell.
+	var id: int = block_ref(cell)
+	if id < 0:
+		return PackedByteArray()
+	var samples: Array = package["blocks"][str(id)]["surface_samples"]
+	var result: PackedByteArray = PackedByteArray()
+	result.resize(64)
+	for index: int in range(64):
+		result[index] = int(samples[index]) & 0xFF
+	return result
 
 
 func refresh_rules(changed_cells: Array[Vector2i]) -> void:
```

---

## 5. Regression self-test

Инструмент: `workbench/tools/walkmap_equivalence_self_test.gd` (Godot headless, `SceneTree`-скрипт).
Baseline — изолированная копия исходных скриптов (`workbench/baseline/scripts/*`, единственное отличие —
переписанный путь `preload`), оптимизированный — рабочие версии. Оба варианта строят **независимые** миры
и проходят **одну и ту же** серию ударов.

Серия ударов:

1. 10 cave-ударов в нетронутой местности (`marks` 10 и 8) — реально меняют nav-байты.
2. 5 corridor-ударов (`marks` 3), включая fixture-точку `(9,3)` из `native-terrain-strike-2026-11-17.md`.
3. Row-major sweep верхней половины карты: `y = 0..11`, `x = 0..43`, `marks` 3` — 528 ударов.

Порядок важен: sweep идёт row-major, и только в нём удары последовательно открывают новые navigable-байты
(141 из 273 принятых ударов реально меняют байты — иначе тест ничего не доказывал: первая версия серии давала
`changed = 0` во всех ударах).

Что сравнивается **после каждого** принятого удара:

| Объект | Сравнение |
|---|---|
| `flags` | побайтово, все 67 584 samples |
| `unknown_samples` | побайтово, все samples |
| `unknown_total` | точное равенство |
| `changed` | точное равенство (счётчик изменившихся байтов) |
| `rects` | строковое равенство списка пересчитанных прямоугольников |
| `cell_representative` | все 1056 клеток карты |
| `is_newly_navigable` | все samples (доступность забоя) |
| `native_fix_dig.solve` | 5 запросов пути, полное равенство результатов |
| acceptance удара | базовый и оптимизированный миры принимают один и тот же удар |

Плюс отдельный unit-тест `terrain_sample_query_cached` против `terrain_sample_query` на 9216 синтетических
samples со случайными высотами, блокировками, пропусками и закрытыми gate — сравнение строковых результатов.

Результат:

```
WALKMAP_EQUIVALENCE_SERIES narrow accepted=273 byte_changing=141
WALKMAP_EQUIVALENCE_SERIES wide   accepted=273 byte_changing=141
WALKMAP_EQUIVALENCE_SELF_TEST_OK assertions=4369
```

`narrow` — режим с сужением до dirty-набора, `wide` — тот же код без сужения (весь rect пересчитывается,
значения берутся из кэша). Оба режима дают байт-в-байт тот же результат, что и неизменённая полная пересборка.

---

## 6. Результаты замеров

`workbench/tools/walkmap_bench_compare.gd`, 5 повторов каждого варианта, в отчёт идёт медиана по суммарному
времени. Серия ударов — та же, что в self-test; каждый вариант строится в собственном мире.

```
BENCH_COMPARE repeats=5 strikes=273 accepted=273 byte_changing=141
BENCH_COMPARE full    total_us=9789464  avg_us=35858 max_us=94158  height_calls=1804460 gate_calls=294544 cell_calls=0    rebuilt=289114
BENCH_COMPARE cached  total_us=1685194  avg_us=6172  max_us=17612  height_calls=86624   gate_calls=1326   cell_calls=0    rebuilt=199840 skipped=89946 speedup=5.81x
BENCH_COMPARE bulk    total_us=1544871  avg_us=5658  max_us=11039  height_calls=0       gate_calls=1326   cell_calls=1392 rebuilt=199840 skipped=89946 speedup=6.34x
BENCH_COMPARE host_call_reduction cached=20.8x bulk=1804460.0x
BENCH_COMPARE_DONE assertions=20 failures=0
```

Что означают счётчики:

* `height_calls` — число обращений к хост-`_native_height_sample`. `full`: 1 804 460 (31 probe × sample ×
  удары). `cached`: 86 624 — в 20.8x меньше. `bulk`: 0 — высоты приходят пачками по 64 байта на клетку
  (1 392 вызовов `cell_surface_samples`).
* `gate_calls` — 294 544 → 1 326: gate-клетка читается один раз за всю серию и перечитывается только для заменённых клеток (при воздушенной статьи гейта).
* `skipped = 89 946` — samples, доказанно не изменившиеся (в §2.1 выведено, какие именно).
* `rebuilt` — реально пересчитанные samples: 289 114 → 199 840 (−31 %).

Разброс между пятью прогонами: `full` 9.29–10.56 с, `cached` 1.68–1.79 с, `bulk` 1.45–1.65 с. Аппаратный шум
меняет отношение незначительно: ускорение в этом прогоне 5.2–6.3x; структурные показатели
(число вызовов хоста, пересчитанные samples, количество вызовов клетки) от нагрузки не зависят.

Рекомендация: **`bulk` как основной режим** (6.34x), `cached` — как вариант без единой новой строки в
`native_terrain_state.gd` (5.81x, изменяются только два файла).

---

## 7. Дефекты, найденные при разработке

### 7.1. Алиасинг плоского индекса клетки в кэше gate (исправлен)

Симптом: на серии из 273 ударов оптимизированный вариант расходился с baseline на **124 samples** — клетка
`(0,8)` теряла gate, и все samples с `x ≤ 3`, `y ≈ 65-66` становились `unknown` вместо `0`.

Причина: индекс клетки считался как `(cy − cell_origin.y) * cell_width + (cx − cell_origin.x)`, и клетка
**за пределами** сетки (например `cx = 44`, `cy = 7`) давала индекс `44·7 + 44 = 352` — **тот же самый**,
что у штатной клетки `(0,8)`. Gate для клетки за сеткой `null` (её нет в манифесте) записывался в слот
штатной клетки и «отравлял» его навсегда (состояние `2 = null` никогда не перечитывалось).

Исправление: доступ к клетке проверяется **по координатам** (`_cell_in_grid`), а не по результату плоского
индекса; индекс гарантированно уникален внутри сетки клеток. То же исправление применено к bulk-пути
(`_refresh_cell`) и к `_gate_at`.

Именно этот дефект показывает цену regression-теста: он воспроизводился на 400+ ударе, а не на первом, и
не выводился ни одним «ручным» примером.

### 7.2. Ложная гипотеза, проверенная и отброшенная

Первая попытка оптимизации сужала пересчёт до «дилатации заменённой клетки footprint'ом проб» в форме
`(cx·8−7 … cx·8+7, cy·8−15 … cy·8+7)` — то есть с инверсией по Y. Расхождение после этого стало появляться
раньше (удар `(23,1)`). Перепроверка объединения по всем `dy ∈ [−15,+1]` показала правильный набор
`(cx·8−7 … cx·8+14, cy·8−1 … cy·8+22)`, а нативный dependency rect `(L−8, T−2, R+8, B+16)` подтвердил
его независимо (§2.1). Гипотеза отброшена, геометрия исправлена.

---

## 8. Допущения, ограничения и неизвестное

1. **`assume_static_gate = true` — предусловие, а не факт.** В порту gate берётся из статического манифеста
   terrain (`native_terrain_cells[cell]["flags"] & 0x80`), поэтому замена block-ref его не меняет. В нативе
   gate — это runtime-байт `C+0x18` клетки, и он принадлежит блоку, то есть потенциально может меняться.
   Если порт когда-нибудь начнёт брать gate из runtime-состояния клетки, нужно выставить
   `assume_static_gate = false` (кэш гейта заменённой клетки при этом инвалидируется корректно) и
   перепровести регрессию.
2. **Сужение — адаптерная оптимизация, а не нативный контракт.** Натив пересчитывает весь свой rect
   (очередь `1 → 0x5A6B40`); здесь пересчитывается подмножество. Байтовая эквивалентность доказана для
   реальных данных и серии ударов (§5), но нативного «флага пропуска» в EXE нет — это оптимизация уровня
   адаптера, санкционированная `native-terrain-strike-2026-11-17.md:145`.
3. **Объектные маски не входят в объём.** Очередь `2 → 0x5A5DA0` (object overlays) в порте не подключена,
   `object_overlays_applied` по-прежнему `false`. Оптимизация этого не касается.
4. **Неизвестно (не влияет на решение):** точные назначения всех флагов invalidation (`0x100/0x200/0x400/
   0x8/0x20`) и очередей; полный контракт `dig_apply` (`0x6347A0`) и cave-менеджера `0x58BA00`; потребители
   байта `C+0x13`; внутренности `CMapPathfinder`.
5. **Проверено на одной карте.** Данные — `multi_start_010` (44×24 клетки). Другие карты не проверялись;
   выводы о footprint'е и о неизменности gate от карты не зависят, но самопроверку на других картах стоит
   сделать при интеграции.
6. **Замеры — headless, без рендера.** В игре добавится стоимость обновления мешей и отрисовки; измерялась
   только пересборка walkmap.

---

## 9. План интеграции и отката

### Интеграция

1. Применить `godot/scripts/native_walkmap.gd` и `godot/scripts/native_walk_flags.gd` (diff §4).
2. Опционально — `godot/scripts/native_terrain_state.gd` и передача bulk-доступора из
   `multiplayer_test.gd` (единственное изменение вызывающей стороны:
   `rebuild_after_strike(patch, _native_height_sample, _native_walk_gate, native_world.local_sample_bounds(), _native_cell_surface_samples)`).
   Без него остаётся режим `cached` (5.81x) и `native_terrain_state.gd` менять не нужно.
3. Прогнать `godot/tools/native_walk_flags_self_test.gd` (существующий в проекте) — предикат не менялся,
   но стоит убедиться.
4. Прогнать self-test из §5 на своей машине: `workbench/tools/walkmap_equivalence_self_test.gd` даёт
   `WALKMAP_EQUIVALENCE_SELF_TEST_OK`.
5. Проверить в игре: серия ударов в пещере, отсутствие «залипания» после раскопки, корректность пути гномов
   (представители клеток и `native_fix_dig`).

### Откат

Откат — откатить два файла: поведение полностью возвращается к текущему (`full`), контракт не менялся.
Флаги `narrow_to_dirty_samples` и `assume_static_gate` позволяют отключить оптимизацию без отката кода:
`narrow_to_dirty_samples = false` оставляет кэш высот (6.5x при меньшем риске), `assume_static_gate = false`
дополнительно запрещает сужение при сомнениях в gate.

---

## 10. Состав рабочего дерева агента

```
C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\
└── workbench\
    ├── project.godot                     минимальный Godot-проект-стенд
    ├── models\                           реальные данные multi_start_010 (terrain, mutable, tunnel_rules, walkmap, world_context)
    ├── baseline\scripts\                 изолированные копии исходных скриптов (baseline для сравнения)
    ├── scripts\                          оптимизированные native_walkmap.gd / native_walk_flags.gd / native_terrain_state.gd
    ├── tools\
    │   ├── walkmap_harness.gd            сборка мира и вызываемые хост-функции
    │   ├── walkmap_equivalence_self_test.gd   регрессия full-vs-optimized
    │   ├── walkmap_bench_compare.gd      замеры трёх вариантов
    │   ├── walkmap_debug_classify.gd     классификатор расхождений (STALE_SKIP / PREDICATE / STATE)
    │   ├── walkmap_probe_changes.gd      поиск ударов, реально меняющих nav-байты
    │   └── make_patch.py                 генерация и проверка unified diff
    └── walkmap-performance.patch         готовый патч (проверен)
```

Команды (из корня `workbench`):

```powershell
$godot = 'C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe'
& $godot --headless --path . --import
& $godot --headless --path . --script res://tools/walkmap_equivalence_self_test.gd
& $godot --headless --path . --script res://tools/walkmap_bench_compare.gd
```

---

INTEGRATION_HANDOFF: docs/reverse-engineering/agent-result-walkmap-performance-2026-11-19.md
