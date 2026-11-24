## Behaviour of the hamster class, ported from the original Tcl.
##
## The hamster is a farm animal and a food resource. It has its own state
## machine (idle/task), its own animation set and a small set of rules:
## flee from dwarves, look for food, sleep, groom, mate, and - inside a farm -
## wander around the farm pen.
##
## Sources (original install, data/Scripts/classes/characters/hamster.tcl):
##   :2       def_class Hamster food material 0 {reproduces lives moves}
##   :104-107 scan_range 4, search_range 6, escape_range 2, nutrition 0
##   :128-137 scan_timer: fast = 1 s, slow = 5 s
##   :139-169 walk_random, hoppel_random, hoppel_pos, walk_pos, play_anim
##   :171-179 loop_anim
##   :181-237 test_escape, do_escape
##   :239-248 wait_time
##   :250-262 take_item
##   :267-317 farm and paralysis flags
##   :319-344 eat_check
##   :346-369 evt_timer0_proc
##   :371-428 state_idle_proc (activity tables)
##   :430-438 state_task_proc
##   :449-461 evt_timer_wakeup
##
## Scene dependent parts are left to the host: object queries (dwarves, food,
## farms), get_place, vector_fix and the walk action itself.
extends RefCounted

# --- tuning values (hamster.tcl:104-107) ------------------------------------
const SCAN_RANGE := 4.0          # how far the hamster sees dwarves
const SEARCH_RANGE := 6.0        # how far it looks for food
const ESCAPE_RANGE := 2.0        # distance of the flee target
const NUTRITION_LIMIT := 50      # ticks before the hamster looks for food
const WAKEUP_SECONDS := 1800     # 30 minutes of being paralysed
const TAKE_ITEM_DISTANCE := 0.8  # how close the food has to be
const ESCAPE_CIRCLE := 8.0       # get_place radius of the flee search
const CLIP_BOX := 1.5            # half size of the clip box around a dwarf
const SCAN_TIMER_FAST := 1
const SCAN_TIMER_SLOW := 5

# --- farm pen grid (hamster.tcl:402-405) ------------------------------------
const FARM_GRID_X := 7
const FARM_CELL := 0.5
const FARM_OFFSET_X := -1.5
const FARM_OFFSET_Z := -2.0

# --- animsets (hamster.tcl:42-81) --------------------------------------------
const ANIMSET_WALK := "0"
const ANIMSET_HOPPEL := "1"
const ANIMSET_GALOPP := "2"


## Flee decision of test_escape (hamster.tcl:181-224).
##
## The original queries dwarves in scan_range, averages their positions and
## runs away from that average by escape_range. The clip boxes around every
## dwarf are handed to get_place so the hamster does not path through them.
##
## Returns {found, count, average, target, clipping}.
static func escape_target(own: Vector3, dwarf_positions: Array) -> Dictionary:
	var count := 0
	var sum := Vector3.ZERO
	var clipping: Array = []
	for entry: Variant in dwarf_positions:
		var position: Variant = entry
		if not (position is Vector3):
			continue
		var dwarf := position as Vector3
		var distance := own.distance_to(dwarf)
		if distance > SCAN_RANGE:
			continue
		count += 1
		sum += dwarf
		clipping.append({
			"min_x": dwarf.x - CLIP_BOX,
			"max_x": dwarf.x + CLIP_BOX,
			"min_z": dwarf.z - CLIP_BOX,
			"max_z": dwarf.z + CLIP_BOX,
		})
	if count == 0:
		return {"found": false, "count": 0, "average": own, "target": own, "clipping": clipping}
	var average := sum / float(count)
	var direction := own - average
	if direction.length() > 0.000001:
		direction = direction.normalized() * ESCAPE_RANGE
	else:
		direction = Vector3.ZERO
	return {
		"found": true,
		"count": count,
		"average": average,
		"target": own + direction,
		"clipping": clipping,
	}


## What do_escape does with the flee target (hamster.tcl:226-237).
##
## escape_pos == -1 means get_place found nothing, so the hamster falls back
## to the random path finder and stops rescanning.
static func escape_decision(place_found: bool) -> Dictionary:
	if place_found:
		return {"mode": "escape", "rescan": true, "command": "walk_pos"}
	return {"mode": "random", "rescan": false, "command": "walk_random"}


## Idle activity of the hamster (hamster.tcl:371-428).
##
## farmed: five activities, wild: six. The original never repeats the previous
## activity: a repeat is shifted by one.
##
## roll is the random draw in [0, count).
static func choose_activity(last_activity: int, farmed: bool, roll: int) -> Dictionary:
	var count := 5 if farmed else 6
	var activity := roll % count
	if activity == last_activity:
		activity = (activity + 1) % count
	var kinds := ["clean", "beg", "wait", "sleep"]
	if not farmed:
		kinds.append("hoppel_random")
		kinds.append("hoppel_random")
	else:
		kinds.append("hoppel_farm")
	var kind := String(kinds[activity])
	var plan := {"activity": activity, "kind": kind}
	match kind:
		"clean":
			plan["commands"] = ["loop_anim clean"]
			plan["min"] = 2
			plan["max"] = 6
		"beg":
			plan["commands"] = ["play_anim beg"]
		"wait":
			plan["commands"] = ["wait_time"]
			plan["seconds_min"] = 1.5
			plan["seconds_max"] = 4.0
		"sleep":
			plan["commands"] = ["loop_anim sleep"]
			plan["min"] = 6
			plan["max"] = 10
		"hoppel_farm":
			plan["commands"] = ["hoppel_pos"]
			plan["cells"] = FARM_GRID_X * 5
		_:
			plan["commands"] = ["hoppel_random"]
			plan["min"] = 2
			plan["max"] = 4
	return plan


## Position of one cell of the farm pen (hamster.tcl:402-406).
##
## The pen is a 7 wide grid of 0.5 sized steps, centred on the farm object.
static func farm_cell_position(farm_pos: Vector3, cell: int) -> Vector3:
	var new_x := float(cell % FARM_GRID_X) * FARM_CELL + FARM_OFFSET_X
	@warning_ignore("integer_division")
	var new_z := float(cell / FARM_GRID_X) + FARM_OFFSET_Z
	return farm_pos + Vector3(new_x, 0.0, new_z)


## Nutrition counter of eat_check (hamster.tcl:319-344).
##
## The hamster counts down to zero, then looks for a mushroom hat.
static func nutrition_step(nutrition: int) -> Dictionary:
	if nutrition < NUTRITION_LIMIT:
		return {"nutrition": nutrition + 1, "seek_food": false}
	return {"nutrition": 0, "seek_food": true}


## Command chain of a feeding round (hamster.tcl:332-340).
static func eat_commands(food_position: Vector3, food_reference: String) -> Array:
	var commands: Array = ["walk_pos {%s}" % format_position(food_position)]
	for _index: int in range(5):
		commands.append("play_anim goteaten")
	commands.append("take_item %s" % food_reference)
	return commands


## loop_anim builds start, loop*reps and stop (hamster.tcl:171-179).
static func loop_anim_commands(anim: String, repetitions: int) -> Array:
	var commands: Array = ["play_anim %sstart" % anim]
	for _index: int in range(repetitions):
		commands.append("play_anim %sloop" % anim)
	commands.append("play_anim %sstop" % anim)
	return commands


## Repetition count of loop_anim: irandom(max - min) + min.
static func loop_anim_repetitions(minimum: int, maximum: int, draw: int) -> int:
	if maximum <= minimum:
		return minimum
	return minimum + (draw % (maximum - minimum))


## When the hamster is paralysed (hamster.tcl:346-358).
##
## Being contained in something or being underwater paralyses it.
static func should_paralyze(contained: bool, underwater: bool) -> bool:
	return contained or underwater


## What do_paralyzed does (hamster.tcl:288-299).
##
## The queue is cleared, the hit animation plays and a wake up timer is set.
static func paralysis_plan() -> Dictionary:
	return {
		"clear_queue": true,
		"commands": ["play_anim gothit"],
		"wakeup_seconds": WAKEUP_SECONDS,
		"hitpoints": 0.02,
	}


## Timer interval of the scan timer (hamster.tcl:128-137).
static func scan_interval(scan_speed: String) -> int:
	if scan_speed == "slow":
		return SCAN_TIMER_SLOW
	return SCAN_TIMER_FAST


## Native walk action parameters of the hamster (hamster.tcl:139-163).
##
## kind is "walk_random", "hoppel_random", "walk_pos" or "hoppel_pos".
static func walk_action_params(kind: String, length: float = 0.0, target: Variant = null) -> Dictionary:
	match kind:
		"walk_random":
			return {"animsets": ANIMSET_WALK, "random_z": 4.0, "random_path": length,
					"can_climb": 0, "use_objects": 0}
		"hoppel_random":
			return {"animsets": ANIMSET_HOPPEL, "random_z": 2.0, "random_path": length,
					"can_climb": 0, "use_objects": 0}
		"walk_pos":
			return {"animsets": ANIMSET_WALK, "target": target, "can_climb": 0, "use_objects": 0}
		"hoppel_pos":
			return {"animsets": ANIMSET_HOPPEL, "target": target, "can_climb": 0, "use_objects": 0}
	return {}


## The scan query of test_escape: dwarves in scan range.
static func scan_query() -> Dictionary:
	return {"class": "Zwerg", "range": SCAN_RANGE}


## The food query of eat_check: mushroom hat first, grilled mushroom second.
static func food_query() -> Array:
	return [
		{"class": "Pilzhut", "range": SEARCH_RANGE, "limit": 1, "flagneg": "contained"},
		{"class": "Grillpilz", "range": SEARCH_RANGE, "limit": 1, "flagneg": "contained"},
	]


static func format_position(value: Vector3) -> String:
	return "%s %s %s" % [str(value.x), str(value.y), str(value.z)]
