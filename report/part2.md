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
