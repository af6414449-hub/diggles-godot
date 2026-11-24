# Справочник проекта Diggles — для постановки точных задач ИИ

**Обновлено:** 21.11.2026. **Назначение:** рабочий словарь проекта: термины,
навигация по карте, имена веток/подсистем и правила оформления задачи.
Перед выдачей указания ИИ вставьте нужный раздел в промпт или сошлитесь на этот
файл — агент читает `docs/` в дереве проекта.

**Файл не содержит** и не заменяет: источник правды об очереди
(`docs/plan/queue-2026-11-19.md`), разборы по адресам EXE
(`docs/reverse-engineering/answer-osveshchenie-*.md`), отчёты агентов
(`docs/reverse-engineering/agent-result-*.md`). Здесь только сжатый словарь —
чтобы задание формулировалось терминами проекта, а не общими словами.

---

## 0. О проекте в четырёх строках

1. **Что:** реимплементация *Diggles The Myth of Fenris* (2001–2002, движок C++ + слой Tcl) на **Godot 4.7.2** с исходной механикой, а не с придуманной логикой.
2. **Цель:** самостоятельная Android-реализация — игрок проходит главу целиком, глава собрана так же, как в оригинале. Критерий: APK с первой главой, 30 FPS на Vivo.
3. **Куда писать:** основной проект — `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot`. Дерево `C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot` — **только чтение** (оттуда читаем и копируем, туда ничего не пишем и не дублируем).
4. **Главное правило проекта:** **ФАКТ / ИНЖЕНЕРНЫЙ АДАПТЕР / НЕИЗВЕСТНО** — раздельно. Факт = есть ссылка на оригинал (EXE-адрес, строка Tcl/3DB). Адаптер = наше решение там, где оригинал неизвестен. Неизвестно = так и пишем, не выдумываем. В коде это оформляется комментарием `## ADAPTER:` или `## SOURCE:`.

---

## 1. Карта каталогов

| Путь | Что это | Правило |
|---|---|---|
| `godot/` | **основной проект** (Godot 4.7.2) | единственное место правки кода |
| `godot/scripts/` | GDScript-модули, префикс `native_*` = порт оригинала | — |
| `godot/tools/` | self-тесты (`*_self_test.gd`) и зонды (`*_probe.gd`) | сюда кладутся тесты блока |
| `godot/models/` | выгруженные данные (JSON) | `native_*.json` — по коду, `*.json` прочее |
| `godot/scenes/`, `godot/shaders/`, `godot/textures/`, `godot/assets/` | сцены, шейдеры, текстуры | — |
| `docs/plan/` | планы и очередь | `queue-2026-11-19.md` — **единственный источник правды об очереди** |
| `docs/reverse-engineering/` | разборы оригинала, отчёты агентов | `agent-result-*.md` — отчёт блока, `agent-task-*.md` — промпт-задание |
| `docs/research/` | внешнее исследование (публичные источники) | уровень уверенности В/С/Н/? |
| `docs/review/` | ревью интеграций | — |
| `tools/` | Python-инструменты проекта | `export_campaign_chapter.py`, `build_ground_field.py` и т.п. |
| `scripts/` | Python-скрипты сверки/сборки/патчей | `run_all_suites.py` — прогон всех self-тестов |
| `work/` | рабочие артефакты, в т.ч. `work/campaign/` (декомпиляция, Ghidra) | `work/campaign/ref/ghidra-out/typed2/` — типизация глобалов |
| `workbench/` | стенд для измерений (walkmap-бенчмарк) | снимок, не для правок |
| `baseline/`, `repro/`, `trial/`, `review-tmp/`, `boss/` | снимки, воспроизводители, временные деревья | **не править** |
| `out/` | патчи и результаты прогонов | сюда кладутся артефакты блока |

---

## 2. Ветки проекта

### 2.1. Шаги A–F (порядок работы, из §0.8 очереди)

| Шаг | Что значит «готово» | Состояние (20.11.2026) |
|---|---|---|
| **A. Генератор уровня кампании** | глава собирается из оригинальных шаблонов детерминированно по seed | закрыт; осталось свести `native_campaign_*` и `diggles_campaign_*` в одну реализацию |
| **B. Гном как самостоятельный агент** | гном без приказов сам занимается делом, спит, ест, ходит на работу | **не начат** (M7) |
| **C. Экономика и фермы** | ферма производит, гномы едят и носят | частично (ферма червя есть, объект Farm её не вызывает) |
| **D. Бой и враги** | бой идёт по исходной боевой таблице | **не начат** (M6) |
| **E. Сюжет и постановка** | сюжетная сцена играется, босс появляется в сцене | движок есть, не хватает диалогов/квестов |
| **F. Android-релиз** | APK с первой главой, 30 FPS на Vivo | **не начат** |

**Порядок работ:** B → C → E → D → F. M-подзадачи встроены: M7 внутрь B, M4/M5 внутрь C, M6 внутрь D, M2/M3 нужны в любой главе, M1 (босс) — поздняя глава, ждёт мира Kristall.

### 2.2. M-блоки (карточки задач, §3 очереди)

| Блок | Суть |
|---|---|
| **M1** | Riesenhamster: геометрия, актёр, узел сцены — **отложен** до мира Kristall и движка сцен |
| **M2** | Исходные тайминги клипов и скорость поворота (12 fps и 90°/с — адаптеры) |
| **M3** | Звук хомяка (`ham_drehen` и прочие `Hamster/*.wav`) |
| **M4** | Хомяк как предмет и еда (`Pilz`, `Grillpilz`) |
| **M5** | Путь, место, размножение (`get_place`, настоящий поиск пути, `recreate_hamster`) |
| **M6** | Общий бой (`fight_dispatch` из `genericfight.tcl`) |
| **M7** | Машина состояний досуга гнома (future/history/emergency hysteresis, place registry, `rotate_toangle`/`stop_prod`, `state_work_*`) |
| **M8** | Мелкие блоки (`prod_anim`, `elf_action`, звук по кадрам, `mann`→`frau`) |

### 2.3. Разделы очереди `docs/plan/queue-2026-11-19.md`

`§0.1` что в работе · `§0.2` сводка по сессиям · `§0.3`–`§0.7` интеграция и вердикты ·
`§0.8` план проекта целиком · `§0.9` карта главы (камера, порода, грани) ·
`§0.10` сюжетная зона и базовый слой · `§0.11` материалы, текстуры, управление, зум, свет ·
`§0.12` шесть замечаний к карте · `§0.13` нативный свет и план породы ·
`§0.14` блок M7 · `§0.15` механика клетки/выемки/высоты по декомпиляции ·
`§0.16` кромка карты (`-border`/`-funnel`) и разделение сеток ·
`§0.17` материал земли, стена вдоль кромки, свет объектов ·
`§0.18` рендер поверхности · `§0.19` типизация глобалов в Ghidra ·
`§1` состояние двух проектов · `§2` очередь · `§3` карточки M1–M8 ·
`§4` белые пятна → кто закрывает · `§5` правила для MCode-сессий · `§6` связанные файлы.

### 2.4. Именованные ветки = подсистемы в коде

Это «ветки» в практическом смысле: каждая — свой набор файлов, свой self-тест, свой отчёт.

| Ветка | Файлы | Self-тест |
|---|---|---|
| **Навигация / проходимость** | `native_walkmap.gd`, `native_walk_flags.gd`, `native_walk_pose.gd`, `native_navigation_representative.gd` | `native_walk_flags_self_test`, `navigation_representative_self_test` |
| **Планирование маршрута** | `surface_walk_action.gd`, `floor_walk_action.gd`, `native_fix_dig.gd`, `native_vector_fix.gd` | `native_fix_dig_self_test`, `native_vector_fix_self_test`, `native_surface_walk_self_test` |
| **Копание и выработки** | `native_dig_rules.gd`, `native_dig_next.gd`, `native_dig_pose.gd`, `native_dig_groups.gd`, `native_tunnel_rules.gd`, `native_terrain_state.gd`, `manual_dig_region.gd`, `native_erase_brush.gd` | `native_dig_next_self_test`, `native_dig_groups_self_test`, `native_terrain_state_self_test`, `manual_dig_region_self_test` |
| **Коридор (выборка игроком)** | `native_corridor_selection.gd`, `native_corridor_stroke.gd`, `native_corridor_contour.gd` | `native_corridor_selection_self_test`, `native_corridor_input_self_test`, `native_corridor_contour_self_test` |
| **Рендер грунта и поверхности** | `native_campaign_ground.gd`, `native_level_ground.gd`, `native_campaign_walls.gd`, `native_terrain_illumination.gd`, `shaders/native_campaign_terrain.gdshader` | `native_campaign_ground_self_test`, `native_campaign_walls_self_test`, `native_terrain_render_self_test` |
| **Камера и карта главы** | `native_campaign_camera.gd`, `native_campaign_level.gd`, `native_campaign_scene.gd` | `native_campaign_camera_self_test` |
| **Генератор уровня** | `native_level_generator.gd`, `native_generated_level_preview.gd` | `native_level_generator_self_test` |
| **Гном-агент** | `native_dwarf_sparetime.gd`, `native_dwarf_work_states.gd`, `native_dwarf_place_registry.gd`, `dwarf_sparetime_runtime.gd`, `dwarf_task_runtime.gd`, `native_dwarf_needs.gd` | `dwarf_sparetime_runtime_self_test`, `native_dwarf_sparetime_self_test`, `native_dwarf_work_states_self_test` |
| **Хомяки и звери** | `native_hamster_actor.gd`, `native_hamster_ai.gd`, `native_wild_hamster.gd`, `native_hamster_clips.gd` | `native_hamster_actor_self_test`, `native_hamster_ai_self_test`, `native_wild_hamster_self_test` |
| **Червяк (Raupe) и ферма** | `native_raupe_actor.gd`, `native_raupe_ai.gd`, `native_farm_raupe.gd` | `native_raupe_actor_self_test`, `native_farm_raupe_self_test` |
| **Свет и факелы** | `native_torch_runtime.gd`, `native_torch_placement.gd`, `native_torch_policy.gd`, `native_autolight.gd`, `native_world_model_light.gd` | `native_torch_runtime_self_test`, `native_torch_placement_self_test`, `world_model_light_self_test` |
| **Сюжет** | `native_story_sequencer.gd`, `native_command_dispatcher.gd`, `native_tasklist.gd` | `native_story_sequencer_self_test` |
| **Бой и общий бой** | `native_battle_world.gd` | `native_battle_world_self_test` |

---

## 3. Навигация по карте

> Это самый часто путаемый участок проекта. Здесь четыре разные сетки, две
> шкалы высот и два разных вида «хода». Смешивать их — главный источник
> неверных правок.

### 3.1. Четыре сетки — не смешивать

| Сетка | Шаг | Где подтверждено |
|---|---|---|
| **Клетка карты** | 1:1 с Tcl (1 клетка = 1 игровая клетка) | `FUN_00592f10(x,y)`, границы `map->0x84..0x90` |
| **Высота / сэмпл** | **8 единиц на клетку** (8×8 на клетку) | `GetHMap` `ROUND(x*8.0)`; `FUN_004093f0` `x>>3`/`&7`; `cell+0x3C` = 64 байта |
| **Рёбра / кромка** | **4 единицы на клетку** | `FUN_005fa510` (`>>2`), `FUN_005fd060` (`>>2`) |
| **Объект карты** | вдвое больше игрового поля (вторая половина — «внешняя» область с кромкой и воронкой) | `map->0x74/0x78` = W/H, `0x7c/0x80` = W*8/H*8 |

> ⚠️ «2048×2560» в проекте — это сетка **рёбер**, а не высоты. Высота для карты 512×640 = **4096×5120** отсчётов.

### 3.2. Высота: уровень ↔ world-Z

- **Уровень (`level`)** — безразмерный байт 0…15, хранится в под-блоке высот (`map->0x24`, шаг `0x59`, байты `+0x00..+0x3F` = 8×8 высот).
- **world-Z = `7.0 + 0.5 × уровень`** (`FUN_004c8220:33,44`). Диапазон **7.0…14.5**. Верхняя плоскость (туман/стены) = **15.0**.
- Уровни-ориентиры: `14.5` = уровень 15 (поверхность главы), `12.5` = уровень 11 (ступень), `7.0` = уровень 0 (дно породы).
- `render_z = 7 + logical_z/2` — то же самое в записи README (`godot/README.md`).
- **Плоский пол карты** = `MAP_GROUND_LEVEL` 14.5 (`native_campaign_ground.gd:51`); **дно породы** = `ROCK_BOTTOM` 0.25; **базовый уровень карты** = 7.0.
- В коде встречается **другая, целочисленная шкала**: `z = clampi(next_height + 6, 1, 14)` в `native_dig_next.gd:66`. Согласование двух шкал **не подтверждено** — не смешивать их в одной формуле.

### 3.3. Walk-флаги — байт проходимости на сэмпл

Флаг лежит в `cell+0x3C` — это **параллельный массив флагов**, а не копия высот (это важное исправление, §0.18 п.5). Формат: 64 байта на клетку, индекс `(y&7)<<3 | (x&7)`.

| Бит | Значение | Источник |
|---|---|---|
| `0x01` | **navigation** — сэмпл проходим | продюсер `0x5A6B40` (`native_walk_flags.gd`) |
| `0x02` | **floor / ступень** — под сэмплом есть пол, шага нет | там же; `native_fix_dig.gd:55` ищет этим битом пол под точкой |
| `0x04` | объект / лестница | только из **object overlay** (`0x5A5DA0`), продюсер грунта его не выставляет |
| `0x08` | не используется | — |

Значения, которые выдаёт продюсер грунта: **0** (закрыто), **1** (проходимо), **3** (проходимо + ступень/перепад).

**Gate-байт** (`cell+0x18`, биты 0–1 = материал): если `gate & 0x80 != 0` — сэмпл принудительно закрыт, минуя проверки высот. Gate клетки для сэмпла = `floor((sample + 4) / 8)`.

**Материал клетки** (`get_material` → `CTclGlobalMethods::GroundPos`, `*(ushort *)(cell+0x18) & 3`):
**0 и 3 — порода (не копается)**, **1 и 2 — копаемый материал**. Ранний текст исследования (`docs/research/diggles_world_terrain_navigation.md`, W09) утверждал, что 3 = «состояние выемки» — **это устарело**, выемку несёт высота, отдельного кода/бита выемки нет (§0.11 п.1, §0.15).

### 3.4. Три уровня навигации

1. **Сэмпловая сетка (8×8 на клетку)** — физика проходимости. `native_walkmap.gd`: `sample(point)`, `flags`, `unknown_samples`, `sample_bounds`, `revision`, `stage`.
2. **Клеточная сетка** — `cell_representative(cell)`: представитель клетки = навигабельный сэмпл, выбранный `native_navigation_representative.choose` по 64 байтам клетки. Если хоть один угол клетки не навигабелен — представителя нет.
3. **Сцена / доска** — камера главы и `AStarGrid2D` (`navigation_grid`) для длинных маршрутов, хомяков и игрока.

### 3.5. Walkmap и инкрементальный кэш

`native_walkmap.gd` — «imported initial C+0x3C navigation bytes»: стартовые байты берутся из PMP RLE (`0x599D80..0x599E50`) и **не пересчитываются** на этапе `map_template/0x40000`.

Ключевые поля: `flags`, `unknown_samples`, `sample_bounds`, `surface_heights` (текущая высота поверхности BlockDB), `surface_state` (0 = не читали, 1 = актуально, 2 = устарело), `verified_samples`, `dirty_flag`, `gate_state`/`gate_values`, `cache_stats`.

Пересчёт после удара: `rebuild_after_strike(patch, heights, gates, world_sample_bounds, surface_cells)`.
- Прямоугольник зависимости натива: `(L-8, T-2, R+8, B+16)` — `terrain_dependency_rect` (`native_walk_flags.gd:204`).
- Окно высот, которое натив материализует: `(L-8, T-16, R+8, B+2)` — `WINDOW_LEFT/TOP/RIGHT/BOTTOM`.
- Клип продюсера: `+24, +16, −24, −24` сэмплов.
- Affected-диапазон заменённой клетки: `dx ∈ [−7, 14]`, `dy ∈ [−1, 22]` сэмплов (клетка владеет сэмплами `cx*8..cx*8+7`).
- Инвалидации после выработки: `flags 0x10040` в прямоугольнике 16×16 сэмплов и `flags 0x200` в 8×8 (`native_terrain_state.gd:189`).
- **Правило:** «the original cached flags must never silently survive excavation» — исходный флаг не должен пережить выработку молча.

### 3.6. Планировщики маршрутов — что нативно, что адаптер

| Планировщик | Где | Статус |
|---|---|---|
| `host_cardinal_bfs_over_source_samples` | `surface_walk_action.gd:63` | **адаптер** — BFS по сэмплам, «BFS ordering/cost are not native Calc1» |
| `host_bfs_via_source_cell_representatives` | `surface_walk_action.gd:67` | адаптер — BFS по представителям клеток; каждый соединяющий сэмпл проверяется, «no rounding of an existing path through solid terrain» |
| `AStarGrid2D` (`navigation_grid`) | `multiplayer_test.gd:188,1469`, `terrain_reference.gd:56` | адаптер Godot; перестраивается при изменении мира («A* is only an adapter for long player-directed walks») |
| `native_dig_next.select_next` | `native_dig_next.gd:18` | **нативное ранжирование** (`0x597B20`), но это **не** поиск пути |

**Режимы хода** (`native_walk_pose.mode`, `0x423730`):
- `0` — стена (подъём), глубина из `wall_depth`;
- `1` — маршрут по объекту/лестнице (нужен `use_objects` и лестница);
- `2` — ровный пол, глубина из `floor_depth` (`12.5` при движении влево, `14.5` иначе).

**Глубины:** `wall_depth` — высота стены над точкой (`value+1`; значение 15 → 255 → минимум по четырём углам); `floor_depth(direction_x)` — 12.5 / 14.5.

**Статусы маршрута:** `invalid_input`, `unknown`, `no_navigation`, `unsupported_object_route`, `climbing_disabled`, `no_supported_route`, `ok`.

### 3.7. Привязка точки к проходимому месту

| Функция | Нативная команда | Особенность |
|---|---|---|
| `native_fix_dig.solve` | `vector_fixdig`, `0x635610 → 0x594E00` | квадратная спираль (до 50), **сдвиг `best.y -= 5`**, затем ищет пол битом `0x02` в 8 шагов вниз; `depth = min(14.5, max(worker.z, height+1))` |
| `native_vector_fix.solve` | `vector_fix`, `0x635940 → 0x595770` | **без сдвига Y−5**; «внутренняя» область = границы минус 48 сэмплов (6 клеток) по оси; спираль до 48; высота берётся у соседа **сверху** (`best + UP`) |

Обе: входы `flags` (walk-флаги в 1/8 клетки) и `heights` (высота BlockDB, **не** `Hnext`); неизвестные входы остаются неизвестными; статус `unknown` с полем `missing` (`walk_flags` / `block_height` / `x87_rounding_mode`).

### 3.8. Камера и «навигация взглядом» по карте главы

**Модель: карта главы — это доска.** Плоскость карты — XY, уровень клетки — её высота по Z, камера стоит на нормали доски и смотрит вдоль неё: карта читается **планом**, а высота породы идёт к зрителю, поэтому выкопанный туннель — это углубление в поверхности.

Родная кадрировка: `set_view 246.7 28.8 1.478 -0.29 0.05` (`Campaign.tcl:10`).
- `rx` — наклон камеры **от нормали доски**; `ry` — поворот карты в плане. Глава: `rx = -0.29` рад = **16.6°**.
- Отменённые допущения: «45° + rx» (28.4°) и «вид сбоку» — обе неверны, вид сбоку у оригинала это игровая доска (`steam_01`), а не карта главы.

`native_campaign_camera.gd`: `FOV_DEGREES` 38, `NATIVE_VIEWPORT_HEIGHT` 480, `MIN_DISTANCE` 10, `MAX_DISTANCE` 1400, `DEFAULT_DISTANCE` 25, `MIN_TILT` -0.6, `MAX_TILT` 1.25, `ZOOM_STEP` 0.9, `PAN_SPEED` 0.0017, `ROTATE_SPEED` 0.006, `KEYBOARD_PAN_RATE` 0.35, `GROUND_LEVEL` 14.5.
- `focus`, `yaw`, `tilt`, `distance` — состояние камеры; `camera_position()` = `focus + offset`.
- Панорама идёт **по экранным осям камеры** → WASD/стрелки **не инвертированы**, удержание работает, шага «по нажатию» нет (`Input.get_vector("move_left","move_right","move_up","move_down")`).
- Фокус отражает Y: `focus = Vector3(centre.x, -centre.y, focus.z)`.

### 3.9. Рендер поверхности — чтобы карта читалась правильно

- **Меша по сетке 8×8 в движке НЕТ.** Видимая земля — **один квад (2 треугольника) на клетку**, вершины в углах клеток (`FUN_004c8220:99-104`).
- Сетка 8×8 — **логическая** карта: опора гномов, pathfinding, базовый свет, решение «нужна ли яма». Как геометрия в порте — лишнее.
- Текстура квада: блендинг двух тайлов `ground/Gnd_*.tga` по маске `ground/Msk_XXXX01.tga` по **4 уровням углов** (81 пре-вычисленная комбинация 64×64).
- **Порог ямы/ребра — 2.0 клетки** (≥ 4 уровней), перепад **внутри** клетки, а не между клетками (`FUN_004ca830:399-427`).
- **«Стены = перепад высот» — ОПРОВЕРГНУТО.** Вертикальные стенки строятся из **состояния выемки** (owner-байты `cell+0x34` + различие под-блоков соседей), `FUN_004c6b20:37-145`; высоты лишь задают Z углов. Отдельных 45-граней в движке нет.
- Базовый слой свободных клеток — **адаптер** (в выгрузке этих клеток нет).

### 3.10. Копание: как появляется проходимость

**Метки (marks)** — 32-битное слово на клетку: 8 слотов × 4 бита (`shift = 4 * slot`).
- **Маска работы `0xB`** (`0b1011`) = «в этом слоте есть работа» — одинакова для туннеля и пещеры.
- **tunnel mark = 3** — туннельный тип.
- **cave mark** = бит 8 + двухбитный код глубины.
- `native_dig_rules.target_height(nibble)`: `0` → 15 (нет работы); `mark & 8 == 0` → **11**; `mark & 8 != 0` → `4*(mark&3) - 1` ⇒ коды 0/1/2/3 → **0 / 3 / 7 / 11**.

**Правило чётности (coarse index)** — `(index_x & index_y & 1) == 0`, где `coarse_index(c) = int(float(c - 1) / 2.0)`. Применяется в `native_dig_rules.corridor_indices_allowed`, `native_tunnel_rules.point_rule`, `native_corridor_selection.rasterize`. **Исключение:** кисть стирания (`native_erase_brush`, «tool-5 footprint») — **без чётности**.

**Высота до и после:** `current_height` = `support` (сейчас); `next_height` = максимум `heights[corner]` у next-ref блоков (после выработки), `−1` = «выработки не было», `null` = неизвестно. `support_ok` — `true`/`false`/`null`.

**Группы:** 4-битный номер группы рабочего (`worker_group`), упакован в слово клетки; `stamp` вписывает значение, `finish_commit` инкрементирует счётчик слота. Нативная асимметрия: `worker_stamp` **не** маскирует `& 15` — сохранять.

**Применение шага:** `native_terrain_state.apply_accepted_step` — замена `next`-ref блока, углы в порядке NW→SE, `dirty_flags |= 1` (затронутые) и `|= 2` (центр), `revision += 1`. Причины отказа: `bounds`, `policy`, `unknown_cells`, `target_reached`.

**Валидатор туннеля** (`native_tunnel_rules.point_rule`): `UNKNOWN = −1`, `REJECT = 0`, `ACCEPT = 1`; отказ при выходе за границы, при `cave_here`/`cave_below`, при нечётности, при `support_ok == false`; `player_byte` в рантайме **неизвестен** (`−1`).

**Отличие «поверхность» vs «выработка»** в коде выражено не отдельным флагом, а: (а) типом ниббла метки, (б) парой `current_height`/`next_height`, (в) входами `cave_here`/`cave_below`, (г) парами `found_navigation`/`found_floor`. Слова «excavation» в коде копания не встречается — нативные термины: `tunnel`, `cave`, `dig`, `marks`, `next-ref`, `strike`.

---

## 4. Словарь проекта

### 4.1. Форматы и источники

| Термин | Что это |
|---|---|
| **PMP** | формат карт-шаблонов оригинала (`data/Templates/*.pmp`), RLE-навигационные байты читаются оттуда |
| **BlockDB / BDB** | база блоков оригинала; «мы не можем импортировать одноимённый BlockDB из чужих проектов» |
| **3DB** | формат моделей и текстур оригинала (`data/3db/*.3db`) |
| **L2M** | слой деталей (`multi_start_010_layer2.l2m`) |
| **Tcl** | скриптовый слой оригинала (`data/Scripts/**.tcl`) — источник поведения, а не внутренностей C++ |
| **EXE-адрес** | `0x5A6B40`, `0x596B80`, `FUN_005fc9d0` — точная ссылка на оригинал; **обязательна** для факта |
| **под-блок** | блок высот 8×8 внутри клетки, шаг `0x59`; `+0x00..+0x3F` = высоты, `+0x40..+0x4F` = 4 варианта (направления выемки), `+0x50..+0x53` = требуемый ниббл метки, `+0x54` = два 4-битных уровня углов |
| **запись клетки** | `0x7C` байт: `+0x00` индекс под-блока, `+0x04` индекс объекта, `+0x08`/`+0x0C` 8 нибблов **по owner (клан)**, `+0x13` флаги (бит0 «высота изменилась», бит1 «выкопано», бит2 «просмотрено»), `+0x18` материал, `+0x34` 8 байт по owner, `+0x3C` 64 байта флагов |

### 4.2. Игровые термины

| Термин | Значение |
|---|---|
| **Уровень** | в оригинале не файл, а **процедурная сборка из шаблонов** (`first_level`) → бесконечный оригинальный контент по seed |
| **Миры** | Urwald → Schwefel → Metall → Lava → Kristall → 6000 |
| **Шаблоны** | `urw_unq_start` (старт), `urw_hol_*` (пещеры), `urw_gng_*` (переходы), `urw_gng_001…045_` (вудо-шаблоны, варианты букв); точки соединения — `data/Templates/*.ent` |
| **Гном / dwarf / zwerg** | `z_spare_main.tcl`, `z_work_common.tcl`, `z_work_prod.tcl`, `z_work_states.tcl` — источник истины по ИИ |
| **Хомяк / hamster** | `hamster.tcl`, `z_soundinit.tcl`; `Riesenhamster` — босс (M1) |
| **Raupe (червяк)** | ферма; `Pilz`/`Grillpilz` — еда, `Reithamster` — транспорт |
| **`irandom`** | собственный RNG оригинала для выбора шаблонов |
| **`sm_mark_temparea`, `MapTemplateSet`, `sm_add_temp`, `sm_def_temp_group`** | API размещения шаблонов |
| **`sm_draw_stone`** | ровно четыре опции, все без аргументов, кроме одной: `-border` (0x731060), `-funnel` (0x731068), `-exlimit` (0x731088), `-matlist` (0x73109c, единственная со значением). **`-utmat` в бинаре отсутствует** — вызов в `story.tcl:228` мёртвый |
| **Tcl-команды навигации** | `map create`, `map move`, `map getoffset`, `get_map_width/height`, `get_hmap`, `get_material`, `dig_mark`, `is_dig_marked`, `dig_next`, `dig_resetid`, `dig_apply`, `vector_fixdig`, `get_digedge`, `get_pathlength`, `set_pf_influence`, `get_place`, `fight_dispatch`, `prod_gnome_state`, `stop_prod`, `rotate_toangle` |

### 4.3. Проектные термины

| Термин | Значение |
|---|---|
| **ФАКТ** | подтверждено оригиналом — обязательна ссылка (адрес EXE / строка Tcl / файл 3DB) |
| **АДАПТЕР** | наше решение там, где оригинал неизвестен; в коде помечается `## ADAPTER:` |
| **НЕИЗВЕСТНО** | не установлено; так и пишем, не выдумываем |
| **self-test** | `godot/tools/*_self_test.gd`, зелёный маркер `OK assertions=N` |
| **golden** | эталонные значения в тесте |
| **патч** | результат работы чужой сессии; в `out/` |
| **горячий файл** | `godot/scripts/multiplayer_test.gd` (правка — только со сверкой SHA-256 непосредственно перед записью), `docs/plan/queue-2026-11-19.md` (только главный чат), `tools/run_suite.ps1` (по одному списку на сессию) |

---

## 5. Как оформить задачу для ИИ

### 5.1. Обязательные поля

1. **Цель** одним предложением — что должно измениться в поведении.
2. **Файлы во владении** — список. Правило зон: файл принадлежит одной сессии; нужен чужой файл → это явная зависимость в отчёте, а не правка чужого кода.
3. **Модель из оригинала** — ссылка: адрес EXE, `путь:строка` в Tcl, файл 3DB, либо явная пометка «адаптер».
4. **Критерий приёмки** — конкретные проверяемые значения, а не «должно работать».
5. **Что не трогать** — горячие файлы и чужие ветки.

### 5.2. Формат блока (правило §5 очереди)

> модель из оригинала (со ссылками на строки) → порт в GDScript → self-test с golden-значениями → заметка → обновление README/TODO → патч + отчёт

Отчёт блока: `docs/reverse-engineering/agent-result-<тема>-<дата>.md` + список изменившихся файлов.

### 5.3. Типовые ошибки формулировки

| Ошибка | Как правильно |
|---|---|
| «почини навигацию» | «`native_walkmap.rebuild_after_strike` не пересчитывает сэмплы вне прямоугольника зависимости `(L-8,T-2,R+8,B+16)`; добавь проверку в `native_walk_flags_self_test` с ожидаемым числом `rebuilt`» |
| «гном должен ходить по выработкам» | «`surface_walk_action.plan` возвращает `no_supported_route`, когда представитель клетки (`native_navigation_representative.choose`) не выбирается — воспроизведи на карте 512×640 из `models/native_campaign_chapter.json`» |
| «стены должны быть из высот» | так нельзя: стены строятся из **состояния выемки** (`cell+0x34` + различие под-блоков соседей), §0.18 п.4 |
| «поставь 45 fps» | «поставь **10 fps** — контроллер анимаций оригинала отдаёт 10 кадров на игровую секунду (`controller_frames_per_game_second` = 10.0, `0x007373F0`); 12 fps — адаптер» |
| «улучши производительность» | «`native_walkmap` 9.79 с → 1.69 с достигнут инкрементальным кэшем; эквивалентность доказывается `WALKMAP_EQUIVALENCE_SELF_TEST_OK assertions=4369`. Меряй, когда агенты простаивают» |
| «сделай материал 3 состоянием выемки» | код 3 = **нетронутая порода**, выемку несёт высота (§0.11 п.1, §0.15) |

### 5.4. Правила работы сессии

1. Всё пишется в **основной проект** `MiniMax\Diggles\godot`; дерево `ChatGPT\Diggles\godot` — **только чтение**.
2. Каждый блок заканчивается отчётом `docs/reverse-engineering/agent-result-*.md` и списком изменившихся файлов.
3. Факт / адаптер / неизвестное — раздельно.
4. Перед патчем `multiplayer_test.gd` — сверка SHA-256 с живым проектом непосредственно перед записью.
5. Очередь `docs/plan/queue-2026-11-19.md` правит **только главный чат**; реестр параллельных сессий — `docs/plan/parallel-sessions-2026-11-21.md`.

---

## 6. Проверка результата

- **Прогон всех self-тестов:** `python scripts/run_all_suites.py` из корня проекта. Маркер успеха — `OK assertions=N`; ошибки — `checks=N failures=M`.
- **Godot запускать только так** (иначе зависает до `quit()`):
  ```powershell
  $p = Start-Process -FilePath 'C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe' `
        -ArgumentList @('--headless','--path',$project,'--script','res://tools/<имя>.gd') `
        -RedirectStandardOutput $log -RedirectStandardError ($log+'.err') -PassThru -NoNewWindow
  if (-not $p.WaitForExit(120000)) { Stop-Process -Id $p.Id -Force; 'TIMEOUT' }
  ```
- **Производительность мерять только когда агенты простаивают** — иначе цифры завышены конкуренцией CPU.
- **Никаких «тихих» спавнов** в мультиплеерной сцене — только явное производство.

---

## 7. Где искать первоисточник

| Вопрос | Файл |
|---|---|
| Что делать дальше | `docs/plan/queue-2026-11-19.md` |
| Кто что правит сейчас | `docs/plan/parallel-sessions-2026-11-21.md` |
| Клетка/выемка/высота по адресам | `docs/reverse-engineering/answer-osveshchenie-2026-11-21.md` |
| Кромка карты, `-border`/`-funnel` | `docs/reverse-engineering/answer-osveshchenie-edge-2026-11-21.md` |
| Рендер поверхности | `docs/reverse-engineering/answer-osveshchenie-surface-2026-11-21.md` |
| Карта главы, камера, материалы | `docs/reverse-engineering/agent-result-campaign-map-2026-11-20.md` |
| Генератор уровня | `docs/reverse-engineering/agent-result-level-generator-2026-11-21.md`, `docs/plan/level-generator-2026-11-21.md` |
| ИИ гнома (M7) | `docs/reverse-engineering/agent-result-dwarf-sparetime-work-2026-11-21.md` |
| Стены главы | `docs/reverse-engineering/agent-result-campaign-walls-2026-11-21.md` |
| Аудит пещер | `docs/review/caves-audit-2026-11-21.md` |
| Декомпиляция EXE | `docs/reverse-engineering/diggles-exe-decompilation-2026-11-21.md` |
| Типизация глобалов (Ghidra) | `work/campaign/ref/ghidra-out/typed2/`, `work/campaign/ref/notes-typing-2026-11-21.md` |
| Публичное исследование оригинала | `docs/research/diggles_world_terrain_navigation.md` (уровни уверенности В/С/Н/?) |

---

## 8. Что ещё не установлено (не выдумывать)

| № | Белое пятно | Закрывает |
|---|---|---|
| 1 | Тайминги клипов `hamster.3db` (12 fps — адаптер) | M2 |
| 2 | Скорость нативного поворота (90°/с — адаптер) | M2 |
| 3 | Препятствия террасы не попадают в её сетку | C1 |
| 4 | Гномы не берут хомяка как предмет | M4 |
| 5 | Класса `Pilzhut` нет в сцене (в оригинале это не пробел, а факт сцены) | M4 (уточнение) |
| 6 | Звук поворота `ham_drehen` не реализован | M3 |
| 7 | Пакет `hamster.3db` не переэкспортирован под живую сцену | M1 |
| 8 | Босс не существует в сцене | M1 — отложен до мира Kristall |
| 9 | `Character_Hamster_gross.tga` нет в проекте | M1 |

Дополнительно из кода: смысл байта `cell+0x34[owner]`; четыре «типа углов» под-блока
высот; расхождение соглашений «уровень vs world-Z» внутри движка; семантика зоны в
`sm_draw_stone -exlimit`; `player_byte` валидатора туннеля (неизвестен в рантайме);
`mode1` в `native_dig_groups.gd` (термин упомянут, не определён).
