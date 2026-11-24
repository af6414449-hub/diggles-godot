# Исходный запрос стойки и обновляемая доступность — 17.11.2026

В Godot подключены `vector_fixdig`, исходные navigation bytes PMP, terrain-пересчёт этих байтов после принятого удара и явный контекст размещения шаблона в мире. Одно назначение завершает полный штрих 2×2: четыре callback, четыре мутации BDB, ноль оставшихся marks. APK не собирался: пользователь проверяет проект непосредственно в Godot.

Это приращение продолжает `native-dig-queue-integration-2026-11-17.md`. Доказательства world context — `native-multiplayer-world-2026-11-17.md/.json`; производителя байтов — `native-walk-flags-2026-11-17.md/.json`; независимые арифметические fixtures стойки — соседний `native-fix-dig-2026-11-17.json`.

## Исправленные ошибки подхода

1. Размер PMP 44×24 ошибочно использовался как bounds всего мира. `dig_next` исключает двухклеточный край **мира**, поэтому такой adapter терял настоящие задания у края **шаблона**. Теперь исходная математика получает global XY и bounds выбранного исходного контекста, рендер остаётся в local XY.
2. Стойка выбиралась только по длине маршрута на нашем полу. Теперь предпочтение задаёт исходный запрос `vector_fixdig`; финальная проекция на поддерживаемый пол остаётся явно названным adapter.
3. Начальные navigation bytes нельзя считать неизменными после изменения BDB. После удара пересчитывается доказанный dirty region по новым ссылкам. Начальный PMP cache сохраняется до первого dirty update; полный пересчёт при загрузке не добавлен.
4. У обрезка нет данных всего окружающего мира. Неизвестные пробы возвращают `unknown`, их прежние serialized bytes не используются как актуальные. Известный блокирующий probe может независимо доказать нулевую доступность.

## `vector_fixdig`

Установленный `Diggles.exe`, SHA-256 `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`, preferred image base `0x400000`. Tcl wrapper `0x635610` вызывает ядро `0x594E00` в `0x63582C`. Реализация: `godot/scripts/native_fix_dig.gd`.

Логические XYZ — исходные, Y вниз; шаг navigation sample — 1/8 клетки. При расстоянии XY меньше 1 seed берётся из worker XY; иначе из `target + (worker-target)/distance`. Операции с исходными float32 округлениями выполняются **после** перевода в world coordinates. Затем XY умножаются на 8, преобразуются x87 FISTP, seed Y увеличивается на 8.

Если seed не имеет bit0, поиск идёт квадратной спиралью: +X,+Y длиной L, затем −X,−Y длиной L+1. Начальные L=1, limit=50. Выбирается строго меньшая квадратная дистанция; равенство сохраняет ранний результат обхода. После улучшения limit уменьшается до `min(limit, trunc(float32(2*float32(sqrt(float32(d²)))) + 2.1))`.

От выбранного bit0 sample проверяются смещения Y=0..7 на bit1 (значение 2). Первое совпадение становится anchor; смещение 8 не проверяется. Затем Y уменьшается на 5. Z получается из **текущего** BDB height: `min(14.5, max(workerZ, height+1))`; target Z не участвует. При отсутствии bit0 сохранён исходный seed fallback, а не выдуманный sentinel. Runtime использует результат как предпочтение только при `found_navigation=true`.

Reader ограничивает **клетку** world bounds, сохраняя исходные младшие три бита sample; конечный XY не прижимается к границе. Это отличается от обычного clamp всего sample.

Живой x87 control word оригинала не захвачен. Чистое ядро поддерживает nearest-even/floor/ceil/truncate; без указанного режима возвращает unknown. Godot явно выбирает **nearest-even как текущую политику adapter**, без заявления о доказанном live-режиме оригинала.

Контрольный случай на реальном PMP/BDB: local target `(2,15,13)`, worker `(3,14.5,12)` → seed `(23,124)`, result sample `(23,111)`, current block 80, height 11 → запрос `(2.875,13.875,12)`. Pure fixture проверяет local origin; интеграционный тест отдельно проверяет вычисление в обоих исходных world contexts.

## PMP и dirty cache

`tools/export_native_walkmap.py` читает counted-U16 RLE из оригинального PMP: `value=word&3`, `count=word>>2`, ноль count означает 0x4000. Экспорт — `godot/models/multi_start_010_walkmap.json`: **352×192=67584 bytes**, распределение 65544×0, 1473×1, 567×3. SHA-256 экспортированного JSON `c0ddbe2e823becbd0dbf0649d0d6bda778c13a4f6ca8b62a65b00986f4c5bd63`; источник связан хешами PMP/BDB с terrain manifest.

`native_walkmap.gd` хранит bytes и отдельную маску неизвестных samples. После `NativeTerrainState.apply_accepted_step`:

1. Берётся исходная invalidation 0x10000; dispatcher clipping выполняется до и после расширения `(L−8,T−2,R+8,B+16)`.
2. Producer ограничивает её world sample bounds с отступами +24,+16,−24,−24; затем применяется предел импортированных данных.
3. `native_walk_flags.gd` читает gate и 31 исходную пробу текущих 8×8 BDB heights. По исходным порогам/двум slope-веткам заменяет byte на 0/1/3. Отсутствие обязательных входов помечает sample неизвестным.
4. Все bytes вне результата dirty rect остаются прежними. Проверка сравнивает **все 67584 samples**, а не только ожидаемые изменённые точки.

В контрольной цепочке `(1,15) → (2,15) → (2,16) → (1,16)` после первого удара пересчитаны 798 известных samples, изменены 18 bytes, 18 samples остались неизвестными из-за отсутствующих соседей. Далее: 1070/56, 1087/3, 815/17 (пересчитано/изменено); unknown_total остаётся 18. Все четыре запроса стойки читают актуальную стадию cache; после первого — `native_terrain_rebuilt`.

**Предел:** подключён terrain pass, без исходного object overlay и summary queues. Операция object overlay исследована и имеет pure tests, но footprints/order/состояние объектов ещё не перенесены. Поле `object_overlays_applied=false` сохраняется в диагностике. Наш floor planner по-прежнему учитывает собственные объектные препятствия; это не доказывает полного совпадения native navigation cache.

## Контекст мира

`tools/export_native_world_context.py` проверяет семь исходных Tcl-хешей и повторно читает размеры/placement. Два **условных тестовых** контекста, оба с world bounds `[0,600)²`:

| ID | Source map | Принятый template offset |
| --- | --- | --- |
| `authored_2p` | `multi_dm_kris_2p_001.tcl` | (92,84) |
| `authored_4p` | `multi_dm_kris_4p_001.tcl` | (200,108) |

Смещение включает доказанное `preset+(16,16)`; повторно прибавлять 16 нельзя. В multiplayer-контроллере Inspector property `source_world_case` по умолчанию `authored_2p`; CLI `--source-world-case authored_4p` выбирает второй. Выбор не утверждает, что именно этот вариант был запущен у пользователя в оригинале. Окружающая generated-карта 600×600 не экспортирована как готовое состояние.

Split wrapper оригинала загружает шесть PMP-частей. Все 1056 flags, refs и trailing attributes собранных частей совпали с монолитом. Поэтому различие размеров шаблона и мира не является свидетельством другой локальной карты. Материалы/geometry loader boundaries требуют отдельных проверок.

## Что реально исполняет Godot

После назначения `query_native_dig_stance` получает запрос исходного ядра на world coordinates. Среди безопасных подходов одного поддерживаемого X/Z-пола предпочитается ближайший по X/Z к запросу; затем сравнивается длина A* маршрута. Будущий source floor после удара остаётся обязательной проверкой. История задания содержит `planner=source_request_floor_projection` либо `floor_adapter`, исходный запрос, выбранный rounding и stage cache.

Native result Y=13.875 — вход для `action_walk`, не доказанная координата подошвы нашей модели. Он не присваивается actor root напрямую. Лазание, смена уровня, native `get_digedge`, полный pathfinding и retry/walk protocol остаются следующей работой. Текущая мутация по окончанию клипа, 12 FPS и один accepted step на callback также остаются adapter policy.

Для диагностики `--show-native-walkmap` рисует один mesh samples: оранжевый — bit0, голубой — bits0+1. Overlay выключен по умолчанию, не имеет collision и перестраивается после удара. Неизвестные samples пропускаются. Это изображение **navigation flags**, а не отметки заданий или готовый граф путей.

## Проверки и артефакты

Godot 4.7.2: `native_fix_dig_self_test` — 104 assertions / 18 независимых арифметических fixtures + 2 реальных PMP/BDB случая; `native_walk_flags_self_test` — 131, включая шесть случаев неполных входов; stance integration — 19 для каждого из двух world contexts. Полная очередь — **37 assertions, одно назначение, четыре callback, четыре мутации** headless и OpenGL. Worker regression — 195; независимая работа — 21; жесты multiplayer — 37. Оба новых exporter `--check` прошли. Lint: 34 scripts, 0 ошибок/предупреждений. Smoke всех трёх сцен: 0 ошибок/предупреждений.

OpenGL: `native-stance-2026-11-17/queue_complete.png`, три `multi_start_010_native_*.png`, `scene_space.json`. Проверены крупный план и все три ракурса: правая пещера открыта, фон и центральные площадки видны; overlay совпадает с импортированными коридорами. Это desktop GL Compatibility, без измерений Android GPU.

Воспроизведение из корня workspace:

```powershell
$engine = 'C:/Users/frant/OneDrive/Рабочий стол/godot/Godot_v4.7.2-stable_win64_console.exe'
& $engine --headless --path godot --script res://tools/native_fix_dig_self_test.gd
& $engine --headless --path godot --script res://tools/native_walk_flags_self_test.gd
& $engine --headless --path godot --script res://tools/native_stance_integration_self_test.gd
& $engine --headless --path godot --script res://tools/native_stance_integration_self_test.gd -- --source-world-case authored_4p
& $engine --headless --path godot --script res://tools/native_dig_queue_self_test.gd -- --full-stroke
python -B tools/export_native_walkmap.py godot/models/multi_start_010_terrain.json godot/models/multi_start_010_walkmap.json --check
python -B tools/export_native_world_context.py docs/reverse-engineering/native-multiplayer-world-2026-11-17.json godot/models/multi_start_010_world_context.json --check
```

Дальнейшая приёмка: прочитать native `action_walk` и связь запроса с actor pose, затем пройти по изменённому проходу на другую высоту с исходными переходами анимаций. Объектные navigation overlays должны иметь отдельные доказанные fixtures до заявления о полном current cache.
