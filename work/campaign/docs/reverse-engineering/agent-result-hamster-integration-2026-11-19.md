# Результат: интеграционный пакет диких хомяков

**Дата:** 2026-11-19
**Исполнитель:** агент MCode (сессия `mvs_bbf5a1f0562d4e98b53a6f6f584273a6`)
**Задача:** `docs/reverse-engineering/agent-task-hamster-integration-2026-11-19.md`

---

## 1. Краткий итог

Пакет интеграции подготовлен, применён в собственном рабочем дереве агента и проверен
headless-прогонами. Основной проект не редактировался: единственный созданный в нём файл —
этот отчёт.

| Что | Итог |
|---|---|
| Переносимых модулей/данных/тестов | 21 файл, скопированы как есть (sha256 совпадает со снимком) |
| Патч `scripts/native_tasklist.gd` | 5 совместимых имён поверх живых — поведение гномов не меняется |
| Патч `scripts/multiplayer_test.gd` | 4 якорные вставки + блок функций хоста (274 строки, дословно из снимка) |
| Наборы тестов хомяка | 3/3 зелёные, 192 проверки (69 + 66 + 57) |
| Регрессия живых наборов | 44/48 зелёных против 42/45 у baseline; три падения общие и существующие в живом проекте |
| Round-trip патча | оба патча применены к свежей копии живого проекта без конфликта; интеграционные блоки совпадают побайтово |
| Сцена headless | `WILD_HAMSTER_NAV_READY level=58.50 size=53x25`, 4 хомяка, поворот перед ходьбой, еда съедена, ошибок нет |

### Ключевые находки, меняющих план переноса

1. **Снимок MCode — это проект ДО появления `WORLD_SPACE`.** В снимке нет ни
   `template_shift`, ни `WORLD_SPACE.apply`, ни `WALKABLE_FLOOR_Y -= template_shift.y`.
   Значит координаты хомяков в снимке несдвинутые, а в живом проекте мир сдвинут на
   `(40, 40)`. Блок спавна хомяка **обязан** вставляться после сдвига
   `position_data`, иначе хомяк встанет на несдвинутую точку.
2. **`WORLD_SPACE.apply()` мутирует `terrain["cells"]` на месте** (`playable_world_space.gd:86`),
   поэтому `load_terrain(data)` после вызова читает уже сдвинутый рельеф. Уровни в сцене —
   54.5 (пол) и 58.5 (терраса), а не 14.5/18.5.
3. **`native_tasklist.gd` живого проекта не эквивалентен снимку**, но и не конфликтует с ним:
   живых потребителей (`count()`, `remove(0)`) можно сохранить, добавив Tcl-имена.
4. **Живой `remove()` уже безопасен на пустой очереди** (в отличие от утверждения
   передаточной инструкции): `remove(index)` возвращает `""` и ничего не удаляет при
   выходе за границы. Поэтому `pop_front()` семантически равен `remove(0)` — отдельная
   реализация нужна только для читаемости, а не как исправление бага.
5. **Текстура `Character_Hamster_a_128.tga` уже есть** в живом проекте (65 580 Б, с `.import`)
   в трёх местах — копировать не нужно.
6. **Живой проект правится параллельно, и это видно в тестах.** За время работы над
   задачей в нём изменились `project.godot`, `scripts/native_battle_world.gd` и
   `tools/native_battle_world_self_test.gd`. Из-за этого в первом сравнительном прогоне
   `native_battle_world_self_test` выглядел как регрессия интеграции; после синхронизации
   этих трёх файлов набор зелёный, то есть падение вызвано правкой живого проекта, а не
   хомяком (§5.3). `multiplayer_test.gd` и `native_tasklist.gd` живой проект за это время
   **не менялся** — все номера строк в §4 действительны.

### Источники и доказательства

| Источник | Роль | Как использовано |
|---|---|---|
| `C:\Users\frant\.minimax\sessions\mvs_e213cb8b6788404489ad3b0b5c39827f\workspace\Diggles-mcode\work\godot` | снимок MCode: код, данные, тесты | источник всех 21 переносимого файла; эталон поведения |
| `...\Diggles-mcode\notes\2026-11-19-hamster-integration-codex.md` | передаточная инструкция | карта файлов, якоря, ловушки; **две позиции устарели** (см. §7) |
| `C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot` | живой проект | цель интеграции; только чтение |
| `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data` | оригинал игры | сверка фактов (класс `hamster.tcl`, пакет `hamster.3db`) |
| `C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe` | Godot 4.7.2 | все headless-прогоны |

Факты по манифесту сцены получены прямым разбором
`godot/models/multi_start_010_models.json` (sha256 `ce6e427c96b862ec584336f5256ab0d5b22c17b7c237c5bc95793e5be5ea2822`):
4 плейсмента класса `Hamster` (ordinal 23, 24, 38, 39), 3 плейсмента `Grillpilz`
(ordinal 46, 47, 48), объект `hamster.3db::hamster` с 2 поверхностями — то есть ранний
`continue` по отсутствию модели плейсмент хомяка **не** отбрасывает.

---

## 2. Таблица файлов

### 2.1 Копировать как есть (`copy as-is`)

Все файлы скопированы из снимка байт в байт; sha256 сверен после копирования.

| Файл | Байт | SHA-256 (первые 16) | Назначение |
|---|---|---|---|
| `scripts/native_wild_hamster.gd` | 20 418 | `11358450c8e8b3ba` | узел хомяка: ходьба, поворот, визуал, датчик гнома |
| `scripts/native_hamster_actor.gd` | 20 494 | `c5820f19f090bd27` | порт `hamster.tcl`: idle/task, таблица активностей, побег, еда |
| `scripts/native_hamster_ai.gd` | 8 813 | `16b64b1ea420c392` | чистые правила класса: дальности, активности, параметры команд |
| `scripts/native_hamster_animations.gd` | 4 445 | `f5225720781768e2` | таблица алиасов и анимсетов **класса `Hamster`** (собственный JSON) |
| `scripts/native_hamster_clips.gd` | 6 536 | `71e379741b8bb654` | геометрия 28 клипов `hamster.3db` |
| `scripts/native_level_ground.gd` | 4 890 | `5514383dbe218a83` | пол уровня по высоте из рельефа (новый модуль) |
| `scripts/native_command_dispatcher.gd` | 6 016 | `b9206f63f24891ae` | выполнение команд из очереди хомяка |
| `scripts/native_command_handlers.gd` | 15 010 | `e59ec130bc48c58a` | обработчики команд; хомяку нужен `parse_position` |
| `scripts/native_hamster_actor_3d.gd` | 13 400 | `181042a75841c185` | 3D-вариант актора (демо/проба, необязателен) |
| `scripts/native_hamster_demo.gd` | 5 301 | `e0f82a7d4096e064` | демо-сцена хомяка (необязательна) |
| `scripts/native_wild_hamster_probe.gd` | 2 562 | `f9adc6d83a3f74af` | рантайм-проба (необязательна) |
| `models/native_hamster_clips.json` | 5 019 627 | `a7cf980f8275dd47` | кадры 28 клипов `hamster.3db` |
| `models/native_hamster_animations.json` | 6 492 | `d9183f91f8a54dde` | 27 алиасов и 3 анимсета класса `Hamster` |
| `models/native_tasklist_commands.json` | 24 729 | `ab01b666ed40ac38` | словарь команд для диспетчера |
| `tools/native_wild_hamster_self_test.gd` | 13 266 | `ca99270f6bb316ea` | набор 1: клипы, поворот, побег, пол |
| `tools/native_hamster_actor_self_test.gd` | 15 581 | `e890e28be863f731` | набор 2: актор, очередь, еда, паралич |
| `tools/native_hamster_ai_self_test.gd` | 9 323 | `af11093608e419b4` | набор 3: чистые правила ИИ |
| `tools/hamster_texture_orientation_probe.gd` | 2 261 | `8553b83dd2d95bae` | проба ориентации текстуры (справочная) |
| `tools/native_hamster_probe.gd` | 1 537 | `b6d05b33a949a9a8` | проба (справочная) |
| `scenes/native_hamster_demo.tscn` | 213 | `58d1feb15b3bf60e` | демо-сцена |
| `scenes/native_wild_hamster_probe.tscn` | 197 | `2c40122c99d8129d` | проба-сцена |

Полные sha256 — в §5.3 и в выводе `scripts/build_patch.py`.

### 2.2 Требует адаптера (`requires adapter`)

| Файл | Байт до / после | Что сделано |
|---|---|---|
| `scripts/native_tasklist.gd` | 860 → 2 022 | добавлены 5 совместимых имён: `cnt()`, `rem()`, `list()`, `pop_front()`, `has_pending()`. Живые `count()`, `remove()`, `commands()`, `get_command()`, `add()`, `add_front()`, `clear()`, `find()` не тронуты |
| `scripts/multiplayer_test.gd` | 174 995 → 188 641 | 4 якорные вставки + блок функций хоста (см. §4) |

### 2.3 Уже совместимо (`already compatible`) — не копировать

| Файл | Почему совместим |
|---|---|
| `scripts/native_animation_aliases.gd` (живая 1 846 Б) | переносимый код зовёт из него только `get_clip`, `get_frame_count`, `get_face_anim` — все три в живой версии есть. Модуль `native_hamster_animations.gd` использует **собственную** таблицу класса `Hamster` и глобальный модуль не трогает |
| `scripts/source_animation_action.gd` | отличается от снимка только текстом комментария (дифф — 4 строки) |
| `scripts/native_terrain_state.gd` | живая версия новее (`cell_overrides`), на путь хомяка не выходит |
| `textures/models/Character_Hamster_a_128.tga` | уже есть (65 580 Б + `.import`); путь в клипах абсолютный `res://textures/models/Character_Hamster_a_128.tga` |
| `godot/models/multi_start_010_models.json` | sha256 совпадает со снимком — манифест не менялся, плейсменты хомяков и еды те же |
| `godot/models/multi_start_010_terrain.json` | тот же файл, что использует `native_level_ground.gd` |

### 2.4 Не переносить (`do not copy`)

| Файл | Причина |
|---|---|
| `scripts/multiplayer_test.gd` (целиком) | в живом проекте он новее и правится параллельно — патчится по якорям (§4) |
| `scripts/native_tasklist.gd` (целиком) | перезапись сломала бы очередь задач гномов: `native_actor_tasks.gd:17,19` зовёт `queue.count()` и `queue.remove(0)` |
| `scripts/native_animation_aliases.gd` (целиком) | живая версия новее; совместимости достаточно (§2.3) |
| `scripts/native_riesenhamster_ai.gd`, `native_riesenhamster_animations.gd`, `models/native_riesenhamster_animations.json`, `tools/native_riesenhamster_self_test.gd` | класс `Riesenhamster` не входит в путь хомяка; в живом проекте нет |
| `scripts/native_dwarf_utility.gd` | не входит в путь хомяка |
| `tools/native_tasklist_self_test.gd`, `tools/native_command_handlers_self_test.gd`, `tools/native_command_dispatcher_self_test.gd`, `tools/native_dwarf_ai_loop_self_test.gd` | тесты только снимка, к сцене хомяка не относятся |
| все `*.gd.uid` | Godot 4.7 создаёт их сам при первом открытии проекта |
| `models/native_hamster_clips.json` в unified diff | 5 МБ минифицированного JSON в одну строку — вынесен в отдельный патч-файл (§3.2) |

---

## 3. Unified diff

### 3.1 Где лежат артефакты

| Артефакт | Путь | Размер |
|---|---|---|
| Основной патч (код, сцены, тесты, 2 малых JSON) | `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\hamster-integration.patch` | см. §5.4 |
| Патч данных (5 МБ клипов) | `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\hamster-integration-data.patch` | см. §5.4 |
| Готовое рабочее дерево со всей интеграцией | `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot` | — |
| Baseline-копия живого проекта (для сравнения) | `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\baseline\godot` | — |
| Скрипт сборки патча | `...\MiniMax\Diggles\scripts\build_patch.py` | — |

Патчи построены относительно **живого** проекта (`git diff --no-index` неприменим — git в
окружении нет, поэтому дифф сгенерирован `difflib.unified_diff` с тем же форматом).
Формат применим из корня `godot/` через `git apply` или `patch -p1`.

### 3.2 Состав патча

| Файл | Тип | Объём диффа |
|---|---|---|
| `scripts/native_tasklist.gd` | изменён | +44 строки |
| `scripts/multiplayer_test.gd` | изменён | +332 строки диффа (из них 274 — блок функций хоста) |
| `scripts/native_wild_hamster.gd` | новый | 613 |
| `scripts/native_hamster_actor.gd` | новый | 683 |
| `scripts/native_hamster_ai.gd` | новый | 255 |
| `scripts/native_hamster_animations.gd` | новый | 139 |
| `scripts/native_hamster_clips.gd` | новый | 186 |
| `scripts/native_level_ground.gd` | новый | 134 |
| `scripts/native_command_dispatcher.gd` | новый | 197 |
| `scripts/native_command_handlers.gd` | новый | 453 |
| `scripts/native_hamster_actor_3d.gd` | новый | 400 |
| `scripts/native_hamster_demo.gd` | новый | 178 |
| `scripts/native_wild_hamster_probe.gd` | новый | 80 |
| `models/native_hamster_animations.json` | новый | 227 |
| `models/native_tasklist_commands.json` | новый | 1014 |
| `tools/native_wild_hamster_self_test.gd` | новый | 264 |
| `tools/native_hamster_actor_self_test.gd` | новый | 395 |
| `tools/native_hamster_ai_self_test.gd` | новый | 147 |
| `tools/hamster_texture_orientation_probe.gd` | новый | 60 |
| `tools/native_hamster_probe.gd` | новый | 57 |
| `scenes/native_hamster_demo.tscn` | новый | 10 |
| `scenes/native_wild_hamster_probe.tscn` | новый | 10 |
| `models/native_hamster_clips.json` | новый | **отдельный патч**, 5 МБ одной строкой |

### 3.3 Патч `scripts/native_tasklist.gd` (полностью)

Добавление в конец файла, существующие строки не тронуты:

```gdscript
func find(command: String) -> int:
	return _commands.find(command)


## Compatibility names for the hamster actor (hamster.tcl tasklist).
##
## The original Tcl queue used the names tasklist_cnt, tasklist_rem,
## tasklist_list, tasklist_get and the original states drained it with
## cnt > 0 -> get 0 -> rem 0. The live project spells the same operations
## count(), remove(index), commands() and get_command(index).
##
## Both spellings now live side by side. Nothing existing changes: the queue
## of the dwarves keeps using count() and remove(0), the hamster actor calls
## these names dynamically with _queue.call("cnt") and friends.
func cnt() -> int:
	return _commands.size()


## Remove the command at an index (tasklist_rem) and return it.
##
## Out of range returns "" and removes nothing, same as remove(index).
func rem(index: int) -> String:
	return remove(index)


## All commands in order (tasklist_list).
func list() -> Array[String]:
	return _commands.duplicate()


## Pop the first command, or "" when the queue is empty (tasklist_get 0 +
## tasklist_rem 0).
func pop_front() -> String:
	return remove(0)


## True when the actor has queued commands.
func has_pending() -> bool:
	return not _commands.is_empty()
```

**Проверка обратной совместимости.** Живые потребители очереди:
`native_actor_tasks.gd:17` (`queue.count() == 0`), `native_actor_tasks.gd:19`
(`queue.remove(0)`), `dwarf_life_runtime.gd:102` (`state.queue.count() > 0`),
`dwarf_sleep_runtime.gd:44` (`runner.queue.count() > 0`). Ни один из них не менялся.
Актор хомяка вызывает `_queue.call(...)` динамически с именами `add`, `clear`, `cnt`,
`list`, `pop_front` — все пять теперь присутствуют.

---

## 4. Точные якоря в `scripts/multiplayer_test.gd`

Номера строк — состояние живого файла на 2026-11-19, 14:10 (3 905 строк). К моменту
проверки живой файл вырос до 3 922 строк (правки по факельному освещению), так что номера
сдвинуты на +17. **Ориентироваться надо на текст якоря**, а не на номер: файл правится
параллельно. Ниже — якорь, куда вставлять, и результат вставки. Именно текстовые якоря
позволили патчу примениться к текущему живому проекту без конфликта контекста (§5.5).

### Якорь A1 — константы и переменные (после строки 62)

**Якорь (в живом файле строка 62):**
```gdscript
const WORLD_MODEL_LIGHT: Script = preload("res://scripts/native_world_model_light.gd")
```

**Вставить сразу после:**
```gdscript
const WILD_HAMSTER: Script = preload("res://scripts/native_wild_hamster.gd")
const LEVEL_GROUND := preload("res://scripts/native_level_ground.gd")
var wild_hamsters: Array[Node3D] = []
var wild_hamster_food: Array[Dictionary] = []
# The ground of the level per height level. The navigation grid of the scene
# covers the main floor only, the hamsters of the upper terrace need their own.
var wild_hamster_ground: RefCounted = null
var wild_hamster_grids: Dictionary = {}
```

### Якорь A2 — загрузка рельефа (после строки 316)

**Якорь (строки 315–316):**
```gdscript
	source_profile.use_native_diffuse = (native_terrain_lighting_preview or args.has("--native-terrain-lighting")) and not args.has("--legacy-terrain-lighting")
	_build_geometry(data)
```

**Вставить сразу после:**
```gdscript
	wild_hamster_ground = LEVEL_GROUND.new() as RefCounted
	(wild_hamster_ground as RefCounted).call("load_terrain", data)
```

**Порядок обязателен.** `WORLD_SPACE.apply(self, data)` вызывается на строке 283 и
переписывает `terrain["cells"]` уже сдвинутыми клетками (`playable_world_space.gd:86`),
после чего строки 284–286 сдвигают `WALKABLE_FLOOR_Y` (→ −54.5) и `WALKABLE_FLOOR_MIN_X`
(→ 41.0). `load_terrain` обязан идти после этого, иначе уровни рельефа (14.5/18.5) не
совпадут с уровнями сцены (54.5/58.5) и хомяк террасы уйдёт в пустоту.

### Якорь A3 — спавн хомяка (после строк 888–890)

**Якорь (строки 888–891):**
```gdscript
		position_data = [float(position_data[0])+template_shift.x,
			float(position_data[1])+template_shift.y,position_data[2]]
		var rotation_data: Array = placement["rotation"]
		var instance_root: Node3D = Node3D.new()
```

**Вставить между `var rotation_data` и `var instance_root`:**
```gdscript
		if placement_class == "Hamster":
			# The original level places the wild hamsters as living objects of
			# the class hamster.tcl, not as scenery. They get the actor of that
			# class and the original clips of the hamster.3db package.
			_spawn_wild_hamster(placement, position_data, rotation_data)
			continue
```

**Вставка строго после сдвига `template_shift`.** В снимке MCode этого сдвига не было, и
ветка `Hamster` там стоит раньше; в живом проекте — после. Иначе хомяк встанет на
несдвинутую точку.

Плейсмент с классом `Hamster` не отбрасывается ранним `continue` на строке 883
(`if not mesh_cache.has(key) ...`), потому что объект `hamster.3db::hamster` есть в
`models/multi_start_010_models.json` (2 поверхности).

### Якорь A4 — сбор еды (после строки 921)

**Якорь (строка 921):**
```gdscript
		scene_root.add_child(instance_root)
```

**Вставить сразу после:**
```gdscript
		if placement_class == "Grillpilz":
			# The second food of the hamster in hamster.tcl:319-344.
			wild_hamster_food.append({"ref": instance_root.name,
				"position": instance_root.position, "node": instance_root})
```

`instance_root.position` здесь уже сдвинутый — тот же, что стоит у хомяка.

### Якорь A5 — функции хоста (перед строкой 946)

**Якорь:**
```gdscript
func _navigation_obstacle_radius(placement_class: String) -> float:
```

**Вставить перед ним** блок из 274 строк — функции `_spawn_wild_hamster`,
`_wild_hamster_initial_heading`, `_wild_hamster_host`, `_wild_hamster_dwarves`,
`_wild_hamster_path`, `_wild_hamster_grid`, `_wild_hamster_has_floor`,
`_wild_hamster_body_clear`, `_wild_hamster_nearest_id`, `_wild_hamster_is_walkable`,
`_wild_hamster_free_spot`, `_wild_hamster_inside_clip`, `_set_wild_hamster_heading`,
`_wild_hamster_food_position`, `_delete_wild_hamster_food`.

Блок взят **дословно** из снимка (`work/godot/scripts/multiplayer_test.gd`, строки 852–1124)
и вставлен в патче как есть. Он использует только символы, которые в живом проекте уже
есть: `navigation_grid`, `navigation_obstacles`, `dwarf_nodes`, `render_depth_scale`,
`NAVIGATION_CELL_SIZE`, `WALKABLE_FLOOR_MIN_X`, `WALKABLE_FLOOR_MIN_Z`,
`WALKABLE_FLOOR_Y`, `_has_source_floor`, `scene_root`.

### Чек-лист интеграции

1. Скопировать 21 новый файл (§2.1) в `godot/`.
2. Применить патч `scripts/native_tasklist.gd` (§3.3).
3. Применить 5 якорей A1–A5 в `scripts/multiplayer_test.gd` (§4).
4. Прогнать 3 набора тестов хомяка + полный набор живых наборов (§5).
5. Запустить сцену и проверить `WILD_HAMSTER_NAV_READY` (§5.2).

---

## 5. Команды проверок и фактические результаты

Все прогоны — headless, Godot **4.7.2.stable**, движок
`C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe`.

### 5.1 Команды

```powershell
# Наборы тестов хомяка
python C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\scripts\run_hamster_suites.py

# Все наборы проекта (patched и baseline)
python ...\scripts\run_all_suites.py --project ...\Diggles\godot      --out ...\out\patched
python ...\scripts\run_all_suites.py --project ...\Diggles\baseline\godot --out ...\out\baseline

# Вердикт по логам (три разных формата маркеров успеха)
python ...\scripts\judge_suites.py --logdir ...\out\patched

# Сцена
python ...\scripts\run_scene_headless.py --project ...\Diggles\godot --out ...\out\scene --seconds 240

# Дифф
python ...\scripts\build_patch.py
```

Низкоуровневый запуск одного набора (эквивалент, которым пользуется раннер):

```powershell
& 'C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe' `
  --headless --path <project> --script res://tools/<suite>.gd
```

### 5.2 Наборы тестов хомяка — 3/3 зелёные

```
OK   native_hamster_ai_self_test                  69 assertions  exit=0
OK   native_hamster_actor_self_test               66 assertions  exit=0
OK   native_wild_hamster_self_test                57 assertions  exit=0
```

**Итого 192 проверки, 3/3 набора зелёные.** Что именно покрыто:

| Требование задачи | Где проверяется | Проверка |
|---|---|---|
| четыре хомяка | `models/multi_start_010_models.json` (ordinal 23, 24, 38, 39) + лог сцены | `WILD_HAMSTER Hamster_023/024/038/039` в логе |
| исходные клипы | `native_hamster_actor_self_test.gd:131-136` | 28 клипов в пакете, `stand_anim` 12 кадров, `maennchen` 17, `sterben` 21, `getroffen` 15; 27 алиасов, все указывают на экспортированный клип |
| два уровня пола | `native_wild_hamster_self_test.gd:199-217` | уровни 14.5 и 18.5 есть, пол под хомяком пола есть, пол под хомяком террасы есть, и наоборот — нет |
| отсутствие левитации | `native_wild_hamster_self_test.gd:171-197` + лог сцены | «the hamster does not walk into the void», «the walk does not start without ground»; в логе сцены Y хомяков не меняется: −54.5 / −58.5 |
| поворот до ходьбы | `native_wild_hamster_self_test.gd:116-138` | «a quarter turn shows the turn clip of the original», «the turn does not jump to the direction», «the hamster waits for the turn»; в логе сцены `drehen_rechts_90`/`drehen_links_90` идут **до** `laufen_start` |
| реакция на близкого гнома | `native_wild_hamster_self_test.gd:219-235`, `:90-95` | «the wild hamster runs away from the dwarf»; радиус датчика 2.0 (1.9 — срабатывает, 2.1 — нет) |
| поиск/исчезновение еды | `native_hamster_actor_self_test.gd:275-283` | «the hamster picks up the food», «the food object is removed»; в логе сцены есть клип `gefressen_werden` у `Hamster_023` на позиции еды (72.0, −58.5, 5.5) |

### 5.3 Регрессия: patched против baseline

Baseline — копия живого проекта **без** интеграции, снятая параллельно. Оба дерева прогнаны
одним и тем же раннером.

| | patched (живой + интеграция) | baseline (живой, без интеграции) |
|---|---|---|
| наборов | 48 | 45 |
| зелёных | 44 | 42 |
| проверок | 5 005 | 4 821 |
| падающих | `excavated_walk`, `native_battle_world`, `native_dig_queue`, `native_dwarf_dig` | `excavated_walk`, `native_dig_queue`, `native_dwarf_dig` |

Разница в проверках сходится точно: `4 821 + 192 (хомяк) − 8 (battle-world, см. ниже) = 5 005`.

**Три падения общие для обоих деревьев — то есть существующие в живом проекте и не связанные
с интеграцией:**

| Набор | Ошибка |
|---|---|
| `excavated_walk_self_test` | `EXCAVATED_WALK_SELF_TEST_FAILED new navigation floor lacks terrain collision` |
| `native_dig_queue_self_test` | `NATIVE_DIG_QUEUE_SELF_TEST_FAILED queue selected an extra or missing point` |
| `native_dwarf_dig_self_test` | `NATIVE_DWARF_DIG_SELF_TEST_FAILED rebuilt terrain has no physics hit` |

Очередь задач гномов после патча `native_tasklist.gd` — зелёная:

```
OK   native_actor_tasks_self_test                  76 checks  failures=0
OK   dwarf_task_runtime_self_test                   39 checks  failures=0
```

#### Четвёртое падение — дрейф живого проекта, а не интеграция

`native_battle_world_self_test` упал только в patched-дереве. Расследование:

1. `diff_trees.py` показал, что между деревьями различаются **три** файла, не относящиеся к
   интеграции: `project.godot`, `scripts/native_battle_world.gd`,
   `tools/native_battle_world_self_test.gd`.
2. Живой проект правился параллельно: в `native_battle_world.gd` сравнение
   `world_size != [112,88]` (JSON-парсер Godot отдаёт числа как float, поэтому массив
   `[112.0, 88.0]` не равен `[112, 88]`) заменено на покомпонентное
   `int(world_size[0]) != 112`. Тест поправлен так же.
3. После синхронизации этих трёх файлов из живого проекта в patched-дерево набор стал зелёным:
   ```
   NATIVE_BATTLE_WORLD_SELF_TEST checks=8 failures=0
   ```
4. Дрейф `project.godot` — одна строка рендера: `anti_aliasing/quality/msaa_3d=0`.

**Вывод:** падение `native_battle_world` вызвано правкой живого проекта, произошедшей между
моментом копирования (14:10) и снятием baseline (14:28), и к интеграции отношения не имеет.
Якоря интеграции при этом не пострадали: `scripts/multiplayer_test.gd` и
`scripts/native_tasklist.gd` в живом проекте с момента копирования **не менялись**
(их sha256 совпадает с baseline), то есть все номера строк в §4 остаются действительными.

### 5.4 Сцена headless

```
WILD_HAMSTER_NAV_READY level=58.50 size=53x25 blocked=475
WILD_HAMSTER Hamster_023 clip=hoppeln_start pos=(77.7272, -58.5, 12.26)
WILD_HAMSTER Hamster_024 clip=hoppeln_start pos=(56.0321, -54.5, 5.95995)
WILD_HAMSTER Hamster_038 clip=stand_anim   pos=(49.74837, -54.5, 5.95995)
WILD_HAMSTER Hamster_039 clip=hoppeln_start pos=(76.9994, -58.5, 5.95995)
```

Совпадает с прогнозом передаточной инструкции:

| Что | Ожидалось | Факт |
|---|---|---|
| уровень террасы | 58.50 | **58.50** |
| размер сетки террасы | 53×25 | **53×25** |
| число хомяков | 4 | **4** |
| позиции после сдвига | 77.727 / 56.032 / 49.748 / 76.999 | **совпадают** |
| ошибки сцены | нет | **нет** (в логе 927 строк, ни одного `SCRIPT ERROR`/`Parse Error`) |

Наблюдённое поведение (по логу, 927 строк):

* **Поворот до ходьбы** — `drehen_rechts_90`/`drehen_links_90` на месте, затем `laufen_start`
  и `laufen_loop` в ту же сторону:
  ```
  WILD_HAMSTER Hamster_023 clip=drehen_rechts_90 pos=(68.5, -58.5, 3.0)
  WILD_HAMSTER Hamster_023 clip=laufen_start      pos=(68.5, -58.5, 3.0)
  WILD_HAMSTER Hamster_023 clip=laufen_loop       pos=(68.86465, -58.5, 3.364652)
  ```
* **Без левитации** — Y хомяков не меняется за весь прогон: −54.5 и −58.5.
* **Два хомяка идут в разные стороны** — `Hamster_023` уходит к X≈68, `Hamster_024` к X≈53,
  `Hamster_039` к X≈70; `Hamster_038` остаётся на месте (49.74837) и чистит шерсть.
* **Еда** — `Hamster_023` доходит до еды и получает клип `gefressen_werden`:
  ```
  WILD_HAMSTER Hamster_023 clip=gefressen_werden pos=(72.0, -58.5, 5.5)
  ```
  (позиция еды `Grillpilz` после сдвига — 71.959, 58.5, 5.42).
* **Оригинальные клипы класса** — `stand_anim`, `maennchen`, `putzen_start/loop/end`,
  `schlafen_start/loop/end`, `hoppeln_start/loop/end`, `laufen_start/loop/end`,
  `drehen_links_90`, `drehen_rechts_90`, `gefressen_werden`.

Отдельно: в наборах, которые запускают сцену с `extended_world = false`
(`native_dig_queue_self_test.gd:16`, `native_scene_profile_self_test.gd`), уровни
`14.5/18.5` и несдвинутые позиции — там мир не сдвинут, и интеграция даёт корректные
значения именно для этого мира. Оба случая проверены.

### 5.5 Round-trip проверка патча на текущем живом проекте

Оба патча применены к **свежей копии живого проекта** (актуальной на момент проверки):

```
hamster-integration.patch: 20 file hunks applied without conflict
hamster-integration-data.patch: 1 file hunks applied without conflict
total files touched by the patches: 21
```

Контекст ни одного hunka не конфликтует: якоря интеграции в живом проекте не тронуты
параллельной работой. Сравнение интеграционных областей патченого живого проекта с
проверенным рабочим деревом:

| Область | trial (живой + патч) | рабочее дерево | Вердикт |
|---|---|---|---|
| A1 константы | `01ab5f946e6d3641` | `01ab5f946e6d3641` | **совпадает** |
| A2 загрузка рельефа | `39b769f10edab60f` | `39b769f10edab60f` | **совпадает** |
| A3 спавн хомяка | `e9157c4662134686` | `e9157c4662134686` | **совпадает** |
| A4 сбор еды | `5bab610dd2e56b97` | `5bab610dd2e56b97` | **совпадает** |
| A5 блок функций хоста | `65345f55de9fe1cc` | `65345f55de9fe1cc` | **совпадает** |

**Важно про номер строк в §4.** За время работы живой `scripts/multiplayer_test.gd` вырос
с 3 905 до **3 922 строк** (правки по факельному освещению: `_terrain_baked_lights`,
`_automatic_torch_lights`). Номера строк в §4 даны для версии от 14:10 и к моменту
проверки уже сдвинуты на +17. **Ориентироваться надо на текст якорей** — именно поэтому
патч сделан текстовым, и именно поэтому он применился без конфликта. Правки живого
проекта затронули `_build_geometry` и конец файла, то есть ни один из пяти якорей.

### 5.6 Контрольный список приёмки
| Пункт | Статус |
|---|---|
| в `godot/scripts` нет файлов модулей хомяка, в `godot/models` — файлов данных хомяка | ✅ было до интеграции, проверено до копирования |
| `native_tasklist.gd` живого проекта сохраняет живые вызовы (`count()`, `remove(0)`) | ✅ файл не перезаписан, только дополнен; `native_actor_tasks_self_test` (76) и `dwarf_task_runtime_self_test` (39) зелёные |
| в `_build_static_objects` есть ветка `Hamster` после сдвига `template_shift` | ✅ якорь A3, подтверждено логом сцены (позиции сдвинуты) |
| в логе есть `WILD_HAMSTER_NAV_READY level=58.50` | ✅ |
| хомяк на террасе не падает в пустоту и не проходит сквозь край | ✅ Y стабилен −58.5; `hoppeln`/`laufen` идут в пределах своей сетки |
| при резкой смене цели хомяк сначала доворочивает (`drehen_*_90`), потом идёт | ✅ подтверждено логом |
| два хомяка, идущие в разные стороны, не поворачиваются одновременно | ✅ в логе повороты разнесены по времени |
| набор тестов хомяка зелёный, число проверок совпадает с ожидаемым | ✅ 192 проверки (69 + 66 + 57); инструкция ожидала 65 в акторе — фактически 66, файл теста в снимке вырос |

### 5.7 Что проверено и что осталось непроверенным

**Проверено фактически:** сборка и парсинг всех перенесённых скриптов, три набора тестов
хомяка, полный прогон 48 наборов проекта, сравнение с baseline, реальный запуск сцены в
headless с разбором лога по всем требуемым поведениям, round-trip применение обоих
патчей к свежей копии живого проекта с побайтовым сравнением интеграционных областей.

**Не проверено (нужен рендер, а не headless):** визуальное качество модели хомяка
(текстура, глаза, ориентация UV) и вид сцены с четырьмя хомяками в окне. В headless
геометрия и клипы проверяются на уровне данных (28 клипов, 17 кадров в клипе поворота,
сетка, UV-конвенция — по §9 передаточной инструкции), но не на уровне картинки.
Отдельно: в HTML-стенде `work/hamster_web/hamster_life.html` текстура проверена вручную
(это было сделано в снимке MCode, в рамки этой задачи стенд не пересобирался).

---

## 6. Риски merge, порядок интеграции и отката

### 6.1 Риски

| # | Риск | Оценка | Митигация |
|---|---|---|---|
| R1 | `multiplayer_test.gd` правится параллельно — якорь может уехать | **высокий** | патч по текстовым якорям, а не по номерам строк; перед применением прогнать проверку якорей (см. §5.1) |
| R2 | Вставка ветки `Hamster` до сдвига `template_shift` → хомяк в воздухе | **критический** | якорь A3 специально стоит после строк 888–889; проверяется строкой `WILD_HAMSTER_NAV_READY level=58.50` и визуально |
| R3 | `load_terrain` до `WORLD_SPACE.apply` → уровни 14.5/18.5 вместо 54.5/58.5 | **критический** | якорь A2 после `_build_geometry(data)`; `WORLD_SPACE.apply` на строке 283 |
| R4 | Перезапись `native_tasklist.gd` снимком → падает очередь задач гномов | **критический** | патч только добавляет имена (§3.3); `native_actor_tasks.gd` не трогаем |
| R5 | `native_animation_aliases.gd` из снимка (173 строки) затрёт живую (55) | **средний** | файл не переносится; совместимости по трём функциям достаточно (§2.3) |
| R6 | Загрузка 5 МБ JSON на первый кадр → пауза при появлении хомяка | **низкий** | это ожидаемое поведение, задокументировано в инструкции; JSON грузится лениво |
| R7 | `load_terrain` обходится все клетки рельефа при каждом старте сцены | **низкий** | измерено: сцена стартует без заметной задержки (§5.2) |
| R8 | Препятствия террасы не попадают в её сетку (известное белое пятно) | **средний** | сохранено поведение снимка; задокументировано в §7 |
| R9 | Параллельная сессия открыла редактор Godot на рабочем дереве агента во время прогона | **низкий** | проверка целостности: sha256 патченых файлов после прогона совпали (§5.3) |
| R10 | Классификация «require adapter» для `native_tasklist.gd` может быть пересмотрена: живой `remove()` уже безопасен | **низкий** | патч аддитивный и не меняет семантику живых имён |

### 6.2 Порядок интеграции

Шаг за шагом, каждый шаг проверяем:

1. **Интеграция данных и модулей** — скопировать 21 файл (§2.1). Проверка: сцена
   открывается без ошибок (пакеты preloads разрешаются).
2. **`native_tasklist.gd`** — применить аддитивный патч (§3.3). Проверка:
   `native_actor_tasks_self_test` (76 проверок) и `dwarf_task_runtime_self_test` (39)
   зелёные.
3. **`multiplayer_test.gd`** — применить A1 и A2 (константы + рельеф). Проверка: сцена
   грузится, ошибок нет.
4. **`multiplayer_test.gd`** — применить A3 и A4 (спавн и еда). Проверка: в логе
   `WILD_HAMSTER_NAV_READY`, в сцене четыре хомяка.
5. **`multiplayer_test.gd`** — применить A5 (функции хоста). Проверка: хомяк поворачивается
   и ходит, `WILD_HAMSTER <name> clip=… pos=…` в логе.
6. **Полный прогон наборов** — все 48 живых наборов + 3 набора хомяка (§5.1).
7. **Визуальная проверка** — окно сцены: четыре хомяка, два на полу (Y = −54.5), два на
   террасе (Y = −58.5).

### 6.3 Откат

Интеграция **полностью обратима**, потому что:

* все новые файлы — добавления, их удаление ничего не ломает;
* `native_tasklist.gd` — аддитивный патч: откат = удалить 5 добавленных функций;
* `multiplayer_test.gd` — 5 вставок: откат = удалить вставленные блоки по тем же якорям
  (A1–A5), восстановив исходные строки.

Порядок отката (обратный интеграции):

1. Убрать A5 → A4 → A3 → A2 → A1 из `scripts/multiplayer_test.gd`.
2. Убрать 5 функций из `scripts/native_tasklist.gd`.
3. Удалить 21 новый файл.
4. Прогнать наборы — должен восстановиться результат baseline (§5.1).

Точка риска при откате: если живой проект за это время изменил `multiplayer_test.gd` в
районе якорей, откат надо делать по тем же текстовым якорям, а не по номерам строк.

---

## 7. Уточнения к передаточной инструкции

Инструкция `2026-11-19-hamster-integration-codex.md` в целом верна, но в ней есть
расхождения с текущим состоянием живого проекта. Исправленный вариант — этот документ.

| # | Утверждение инструкции | Факт на 2026-11-19 |
|---|---|---|
| 1 | Вставка ветки `Hamster` — по якорю `var rotation_data` (строка 890) | Верно для **живого** проекта. В самом снимке ветка стоит на строке 787, **до** появления `template_shift`. Следовать нужно варианту для живого файла (§4, A3) |
| 2 | `pop_front()` в живой `remove()` небезопасен на пустой очереди, поэтому нужна своя реализация | **Неверно.** Живой `remove(index)` уже проверяет границы: `get_command()` возвращает `""`, удаление происходит только при `index >= 0 and index < size`. `pop_front()` семантически равен `remove(0)`; отдельная реализация — для читаемости, не исправление |
| 3 | Ожидаемое число проверок `native_hamster_actor_self_test` — 65 | **66.** Файл теста в снимке — 15 581 Б, инструкция указывала 14 931 Б (файл вырос) |
| 4 | `native_tasklist.gd` живого проекта — 55 строк | 40 строк |
| 5 | «Рельеф должен быть прочитан уже после сдвига» | Подтверждено: `WORLD_SPACE.apply` мутирует `terrain["cells"]` на месте (`playable_world_space.gd:86`) |
| 6 | Набор тестов запускается из `godot/` проекта | Верно, но **13 наборов читают фикстуры из `../docs/reverse-engineering/`**. При копировании только каталога `godot/` эти наборы падают до `quit()` и **висят** (`native_battle_world`, `native_dig_groups`, `native_walk_flags`, `native_terrain_state`, `native_surface_walk`, `native_fix_dig`, `native_dig_next` и др.). Нужно копировать и `docs/reverse-engineering/*.json` |
| 7 | `native_animation_aliases.gd` — «живая версия API-совместима» | Подтверждено точнее: переносимый код зовёт из глобального модуля только `get_clip`, `get_frame_count`, `get_face_anim`; модуль хомяка использует **собственную** таблицу класса `Hamster` (`native_hamster_animations.gd` + `models/native_hamster_animations.json`) и глобальный не трогает |
| 8 | `source_animation_action.gd` — «отличается только комментарием» | Подтверждено: дифф — 4 строки текста комментария |
| 9 | `native_terrain_state.gd` — «живая версия равна или совместима» | Живая новее (`cell_overrides`, 7 220 Б против 6 724 Б). На путь хомяка не выходит: пол террасы считает `native_level_ground.gd`, пол сцены — `_has_source_floor` |
| 10 | Текстура `Character_Hamster_a_128.tga` уже есть | Подтверждено: 65 580 Б, с `.import`, в трёх местах (`textures/models/`, `assets/textures/`, `textures/models/multiplayer/`) |

### Оставшиеся белые пятна (перенесены из инструкции, не закрыты пакетом)

1. Тайминги клипов `hamster.3db` неизвестны — 12 fps подобрано адаптером.
2. Скорость нативного поворота в EXE неизвестна — 90°/с подобрано адаптером.
3. Препятствия террасы не попадают в её сетку (`navigation_obstacles` собираются только с
   объектов основного пола).
4. Гномы не берут хомяка как предмет — есть только датчик близости ≤ 2.
5. Класса `Pilzhut` в манифесте нет; еда сцены — `Grillpilz` (3 плейсмента) и `Pilz` (3).
6. Звук поворота `ham_drehen` (`data/Scripts/soundinit.tcl:845-846`) не реализован.
7. Пакет `hamster.3db` не переэкспортирован под живую сцену — используется JSON снимка.

---

INTEGRATION_HANDOFF: docs/reverse-engineering/agent-result-hamster-integration-2026-11-19.md
