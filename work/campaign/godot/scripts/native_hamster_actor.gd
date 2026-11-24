## Autonomous hamster actor: the original hamster.tcl control flow as a runtime.
##
## The hamster is a farm animal with its own state machine, its own queue and
## its own animation set. This module is the executable form of that class:
## it decides, queues, executes and plays, so a hamster in the game can act on
## its own instead of being scripted.
##
## Sources (original install, data/Scripts/classes/characters/hamster.tcl):
##   :2         def_class Hamster food material 0 {reproduces lives moves}
##   :89-137    obj_init: tuning values, timers, scan speed
##   :139-179   walk_random, hoppel_random, hoppel_pos, walk_pos, play_anim,
##              loop_anim
##   :181-237   test_escape, do_escape
##   :239-262   wait_time, take_item
##   :267-317   farm flags, paralysis flags
##   :319-344   eat_check
##   :346-369   evt_timer0_proc
##   :371-428   state_idle_proc with both activity tables
##   :430-438   state_task_proc
##   :449-461   evt_timer_wakeup
##   :465-472   the idle and task states
##
## Adapter contract (all optional unless stated):
##   actor_pos        Callable() -> Vector3
##   query_dwarves    Callable(float range) -> Array        (Vector3 positions)
##   query_food       Callable(float range) -> Array        ({ref, position})
##   query_farm       Callable(float range) -> Dictionary   ({ref, position})
##   is_contained     Callable() -> bool
##   is_underwater    Callable() -> bool
##   pick_place       Callable(Dictionary) -> Variant       (get_place)
##   walk_action      Callable(Dictionary) -> bool          (required to walk)
##   walk_complete    Callable() -> bool                   (walk action finished)
##   play_clip        Callable(Dictionary) -> bool          (host visual binding)
##   delete_item      Callable(String) -> void
##   object_position  Callable(String) -> Variant
##   fix_position     Callable(Vector3) -> Variant
##   random_int       Callable(int low, int high) -> int
##   random_float     Callable(float low, float high) -> float
##   now              Callable() -> float
##   walk_result      Callable() -> int                    (get_walkresult)
##   farm_actualize   Callable(Dictionary) -> void
extends RefCounted

const HamsterAi = preload("res://scripts/native_hamster_ai.gd")
const HamsterAnimations = preload("res://scripts/native_hamster_animations.gd")
const TaskList = preload("res://scripts/native_tasklist.gd")
const Dispatcher = preload("res://scripts/native_command_dispatcher.gd")
const Handlers = preload("res://scripts/native_command_handlers.gd")
const SourceAction = preload("res://scripts/source_animation_action.gd")

const CLASS_ID := "Hamster"
const STATE_IDLE := "idle"
const STATE_TASK := "task"
const WALK_RESULT_CORNERED := 2
const TAKE_ITEM_DISTANCE := 0.8

var _adapters: Dictionary = {}
var _queue: RefCounted = null
var _dispatcher: RefCounted = null

# --- original instance state (hamster.tcl:112-124) ---------------------------
var _state: String = STATE_IDLE
var _state_enabled: bool = true
var _nutrition: int = 0
var _last_activity: int = 0
var _escape_pos: Variant = null
var _escape_failed: bool = false
var _rescan: bool = true
var _gnomesensor: int = 0
var _is_paralyzed: bool = false
var _is_farmed: bool = false
var _farm_pos: Vector3 = Vector3.ZERO
var _farm_ref: String = ""
var _scan_speed: String = "fast"
var _wakeup_at: float = -1.0
var _hitpoints: float = 0.02

# --- runtime -----------------------------------------------------------------
var _time: float = 0.0
var _timer_accumulator: float = 0.0
var _action_kind: String = ""
var _action: RefCounted = null
var _wait_remaining: float = 0.0
var _current_alias: String = ""
var _current_clip: String = ""
var _current_frame: int = -1

var _history: Array[String] = []
var _events: Array[Dictionary] = []


## Create the actor and register the hamster command handlers.
func setup(adapters: Dictionary = {}) -> void:
	_adapters = adapters.duplicate()
	_queue = TaskList.new()
	_dispatcher = Dispatcher.new()
	_dispatcher.register("play_anim", func(args: Array) -> bool: return _command_play_anim(args))
	_dispatcher.register("walk_pos", func(args: Array) -> bool: return _command_walk_pos(args))
	_dispatcher.register("walk_random", func(args: Array) -> bool: return _command_walk_random(args))
	_dispatcher.register("take_item", func(args: Array) -> bool: return _command_take_item(args))
	_dispatcher.register("wait_time", func(args: Array) -> bool: return _command_wait_time(args))


## Advance the actor: run the timer event and the state machine.
##
## The original state machine only runs while the actor is enabled, and the
## timer event is independent of it, so both are kept apart here.
func tick(delta: float) -> void:
	_time += maxf(0.0, delta)
	_advance_action(delta)
	_check_wakeup()
	# The timer event is independent of the state machine: a busy actor still
	# notices that it was contained or that it went under water.
	_timer_accumulator += maxf(0.0, delta)
	var interval := float(HamsterAi.scan_interval(_scan_speed))
	if _timer_accumulator >= interval:
		_timer_accumulator = 0.0
		_timer_event()
	if not _state_enabled:
		return
	_state_step()


## Timer event evt_timer0 (hamster.tcl:346-369).
func _timer_event() -> void:
	if _is_paralyzed:
		return
	if _adapters.has("is_contained") and bool((_adapters["is_contained"] as Callable).call()):
		_do_paralyzed()
		return
	if _adapters.has("is_underwater") and bool((_adapters["is_underwater"] as Callable).call()):
		_do_paralyzed()
		return
	if not _is_farmed and _gnomesensor > 0:
		_gnomesensor -= 1
		if _test_escape():
			_queue.call("clear")
			_trigger_fresh(STATE_IDLE)


## One state machine step.
func _state_step() -> void:
	if _state == STATE_IDLE:
		_idle_proc()
	else:
		_task_proc()


## The idle state (hamster.tcl:371-428).
func _idle_proc() -> void:
	if _is_paralyzed:
		_state_enabled = false
		return
	if int(_queue.call("cnt")) > 0:
		_trigger(STATE_TASK)
		return
	if not _is_farmed and _test_escape():
		_do_escape()
		return
	if _is_farmed:
		_farm_activity()
	else:
		if _eat_check():
			return
		_wild_activity()
	_trigger(STATE_TASK)


## The task state (hamster.tcl:430-438): one queued command per step.
func _task_proc() -> void:
	if int(_queue.call("cnt")) == 0:
		_trigger(STATE_IDLE)
		return
	var command := String(_queue.call("pop_front"))
	_history.append(command)
	var result: Dictionary = _dispatcher.call("dispatch", command)
	_events.append({"event": "command", "command": command, "ok": bool(result.get("ok", false))})


## The farm activity table (hamster.tcl:390-408).
func _farm_activity() -> void:
	var plan := HamsterAi.choose_activity(_last_activity, true, _random_int(0, 4))
	_apply_activity(plan)


## The wild activity table (hamster.tcl:409-426).
func _wild_activity() -> void:
	var plan := HamsterAi.choose_activity(_last_activity, false, _random_int(0, 5))
	_apply_activity(plan)


## Run one chosen activity.
##
## clean and sleep queue a loop_anim sequence, the others are direct actions
## in the original, not queued commands.
func _apply_activity(plan: Dictionary) -> void:
	var kind := String(plan.get("kind", ""))
	_last_activity = int(plan.get("activity", _last_activity))
	_events.append({"event": "activity", "kind": kind, "activity": _last_activity})
	match kind:
		"clean":
			_loop_anim("clean", int(plan.get("min", 2)), int(plan.get("max", 6)))
		"sleep":
			_loop_anim("sleep", int(plan.get("min", 6)), int(plan.get("max", 10)))
		"beg":
			_start_animation("beg")
		"wait":
			_start_wait(_random_float(float(plan.get("seconds_min", 1.5)), float(plan.get("seconds_max", 4.0))))
		"hoppel_farm":
			var cells := int(plan.get("cells", 35))
			_start_hoppel_pos(HamsterAi.farm_cell_position(_farm_pos, _random_int(0, cells - 1)))
		"hoppel_random":
			_start_hoppel_random(_random_int(int(plan.get("min", 2)), int(plan.get("max", 4))))


## loop_anim queues start, loop*reps and stop (hamster.tcl:171-179).
func _loop_anim(anim: String, minimum: int, maximum: int) -> void:
	var span := maximum - minimum
	var draw := 0
	if span > 0:
		draw = _random_int(0, span - 1)
	var repetitions := HamsterAi.loop_anim_repetitions(minimum, maximum, draw)
	for command: String in HamsterAi.loop_anim_commands(anim, repetitions):
		_queue.call("add", command)


## test_escape (hamster.tcl:181-224).
func _test_escape() -> bool:
	if _walk_result() == WALK_RESULT_CORNERED and not _rescan:
		return false
	if _escape_pos != null:
		return true
	var dwarves := _query_dwarves(float(HamsterAi.SCAN_RANGE))
	if dwarves.is_empty():
		_set_scan_speed("slow")
		return false
	_set_scan_speed("fast")
	var escape := HamsterAi.escape_target(_own_position(), dwarves)
	if not bool(escape.get("found", false)):
		return false
	var place: Variant = null
	if _adapters.has("pick_place"):
		place = (_adapters["pick_place"] as Callable).call({
			"center": escape["target"],
			"circle": float(HamsterAi.ESCAPE_CIRCLE),
			"mindist": 0.0,
			"clip": escape["clipping"],
		})
	if place == null or not (place is Vector3):
		_escape_failed = true
		_escape_pos = null
	else:
		var target := place as Vector3
		if target.x < 0.0:
			_escape_failed = true
			_escape_pos = null
		else:
			_escape_failed = false
			_escape_pos = target
	return true


## do_escape (hamster.tcl:226-237).
func _do_escape() -> void:
	var random_path := _escape_failed
	if random_path:
		_rescan = false
		_queue.call("add", "walk_random 5")
	else:
		_rescan = true
		_queue.call("add", "walk_pos {%s}" % HamsterAi.format_position(_escape_pos as Vector3))
	_escape_pos = null
	_escape_failed = false
	_events.append({"event": "escape", "random_path": random_path})
	_trigger_fresh(STATE_TASK)


## eat_check (hamster.tcl:319-344).
func _eat_check() -> bool:
	if _nutrition < int(HamsterAi.NUTRITION_LIMIT):
		_nutrition += 1
		return false
	_nutrition = 0
	var food := _query_food(float(HamsterAi.SEARCH_RANGE))
	if food.is_empty():
		return false
	var entry: Dictionary = food[0]
	var position: Variant = entry.get("position", null)
	if not (position is Vector3):
		return false
	var food_ref := String(entry.get("ref", ""))
	for command: String in HamsterAi.eat_commands(position as Vector3, food_ref):
		_queue.call("add", command)
	_events.append({"event": "food", "ref": food_ref})
	return true


## do_paralyzed (hamster.tcl:288-299).
func _do_paralyzed() -> void:
	if _is_paralyzed:
		return
	_queue.call("clear")
	_state_enabled = false
	_is_paralyzed = true
	_start_animation("gothit")
	_wakeup_at = _now() + float(HamsterAi.WAKEUP_SECONDS)
	_events.append({"event": "paralyzed", "wakeup_at": _wakeup_at})


## evt_timer_wakeup (hamster.tcl:450-461).
func _check_wakeup() -> void:
	if _wakeup_at < 0.0 or _time < _wakeup_at:
		return
	_wakeup_at = -1.0
	if _adapters.has("is_contained") and bool((_adapters["is_contained"] as Callable).call()):
		_wakeup_at = _now() + float(HamsterAi.WAKEUP_SECONDS)
		return
	_state_enabled = true
	_trigger_fresh(STATE_IDLE)
	_hitpoints = 0.02
	_is_paralyzed = false
	_events.append({"event": "wakeup"})


## --- commands ----------------------------------------------------------------

## play_anim (hamster.tcl:165-169) with the class scoped alias table.
func _command_play_anim(args: Array) -> bool:
	if args.is_empty():
		return false
	return _start_animation(String(args[0]))


## walk_pos (hamster.tcl:158-163).
func _command_walk_pos(args: Array) -> bool:
	if args.is_empty():
		return false
	var raw: Variant = Handlers.parse_position(String(args[0]))
	if raw == null:
		return false
	var position: Variant = raw
	if _adapters.has("fix_position"):
		position = (_adapters["fix_position"] as Callable).call(position)
		if position == null:
			return false
	return _start_walk(HamsterAi.walk_action_params("walk_pos", 0.0, position))


## walk_random (hamster.tcl:139-143).
##
## The original hands a random path length to the native walk action. The
## target selection itself is a pathfinder decision, so it stays an adapter.
func _command_walk_random(args: Array) -> bool:
	if args.is_empty():
		return false
	var length := float(args[0])
	var params := HamsterAi.walk_action_params("walk_random", length)
	if _adapters.has("pick_place"):
		var place: Variant = (_adapters["pick_place"] as Callable).call({
			"center": _own_position(),
			"circle": length,
			"mindist": 0.7,
			"random": length,
			"walldist": 1,
		})
		if place != null and (place is Vector3):
			params["target"] = place
	return _start_walk(params)


## take_item (hamster.tcl:250-262): the food is only removed up close.
func _command_take_item(args: Array) -> bool:
	if args.is_empty():
		return false
	var food_ref := String(args[0])
	if not _adapters.has("object_position"):
		return true
	var item_position: Variant = (_adapters["object_position"] as Callable).call(food_ref)
	if not (item_position is Vector3):
		return true
	if _own_position().distance_to(item_position as Vector3) < TAKE_ITEM_DISTANCE:
		if _adapters.has("delete_item"):
			(_adapters["delete_item"] as Callable).call(food_ref)
		_events.append({"event": "taken", "ref": food_ref})
	return true


## wait_time (hamster.tcl:239-248).
func _command_wait_time(args: Array) -> bool:
	if args.is_empty():
		return false
	_start_wait(float(args[0]))
	return true


## --- actions -----------------------------------------------------------------

## Play one hamster animation and block the state machine until it ends.
func _start_animation(alias_name: String) -> bool:
	var clip := HamsterAnimations.get_clip(CLASS_ID, alias_name)
	if clip == "":
		return false
	var frames := HamsterAnimations.get_frame_count(CLASS_ID, alias_name)
	_current_alias = alias_name
	_current_clip = clip
	_current_frame = 0
	_state_enabled = false
	_action_kind = "anim"
	_action = SourceAction.new()
	(_action as RefCounted).call("begin", maxi(frames, 1), 12.0)
	if _adapters.has("play_clip"):
		(_adapters["play_clip"] as Callable).call({
			"alias": alias_name,
			"clip": clip,
			"frames": frames,
		})
	_events.append({"event": "animation", "alias": alias_name, "clip": clip, "frames": frames})
	return true


## Start a walk action (hamster.tcl:139-163).
func _start_walk(params: Dictionary) -> bool:
	if not _adapters.has("walk_action"):
		return false
	_state_enabled = false
	_action_kind = "walk"
	_action = null
	(_adapters["walk_action"] as Callable).call(params)
	_events.append({"event": "walk", "params": params})
	return true


## hoppel_pos (hamster.tcl:151-156).
func _start_hoppel_pos(position: Vector3) -> void:
	_start_walk(HamsterAi.walk_action_params("hoppel_pos", 0.0, position))


## hoppel_random (hamster.tcl:145-149).
func _start_hoppel_random(length: int) -> void:
	_start_walk(HamsterAi.walk_action_params("hoppel_random", float(length)))


## wait_time: the actor stands still for a while.
func _start_wait(seconds: float) -> void:
	_state_enabled = false
	_action_kind = "wait"
	_wait_remaining = maxf(0.0, seconds)
	_action = null
	_current_clip = "stand_anim"
	_current_alias = "standstill"
	_current_frame = 0
	_events.append({"event": "wait", "seconds": seconds})


## Advance the running action and release the state machine when it ends.
func _advance_action(delta: float) -> void:
	match _action_kind:
		"anim":
			if _action == null:
				_finish_action()
				return
			var result: Dictionary = (_action as RefCounted).call("advance", delta)
			_current_frame = int(result.get("frame", _current_frame))
			if bool(result.get("complete", false)):
				_finish_action()
		"wait":
			_wait_remaining -= maxf(0.0, delta)
			if _wait_remaining <= 0.0:
				_finish_action()
		"walk":
			if _adapters.has("walk_complete"):
				if bool((_adapters["walk_complete"] as Callable).call()):
					_finish_action()
			else:
				_finish_action()


func _finish_action() -> void:
	_action_kind = ""
	_action = null
	_state_enabled = true


## --- public class methods -----------------------------------------------------

## method set_farmhamster (hamster.tcl:478-488).
func set_farmhamster(farm: Variant) -> void:
	if farm is Dictionary and not (farm as Dictionary).is_empty():
		_is_farmed = true
		_is_paralyzed = false
		var position: Variant = (farm as Dictionary).get("position", null)
		if position is Vector3:
			_farm_pos = position as Vector3
		_farm_ref = String((farm as Dictionary).get("ref", ""))
	else:
		_is_farmed = false
		_farm_ref = ""
	_trigger_fresh(STATE_IDLE)


## method activate_gnomesensor (hamster.tcl:490-492).
func activate_gnomesensor() -> void:
	_gnomesensor = 10


## method catch_farmhamster (hamster.tcl:494-500).
func catch_farmhamster() -> void:
	if not _is_farmed or _farm_ref == "":
		return
	if _adapters.has("farm_actualize"):
		(_adapters["farm_actualize"] as Callable).call({"ref": _farm_ref})


## method paralyze (hamster.tcl:521-523).
func paralyze() -> void:
	_do_paralyzed()


## method get_scanrange (hamster.tcl:525-527).
func get_scanrange() -> int:
	return int(HamsterAi.SCAN_RANGE)


## --- helpers ------------------------------------------------------------------

## A state trigger only selects the state; the state machine runs the current
## state on every step, like the original scheduler. Running it inline would
## recurse between the idle and the task state.
func _trigger(state_name: String) -> void:
	_state = state_name


func _trigger_fresh(state_name: String) -> void:
	_state = state_name


func _set_scan_speed(speed: String) -> void:
	if speed == _scan_speed:
		return
	_scan_speed = speed
	_timer_accumulator = 0.0


func _own_position() -> Vector3:
	if not _adapters.has("actor_pos"):
		return Vector3.ZERO
	var position: Variant = (_adapters["actor_pos"] as Callable).call()
	if position is Vector3:
		return position as Vector3
	return Vector3.ZERO


func _query_dwarves(scan_range: float) -> Array:
	if not _adapters.has("query_dwarves"):
		return []
	var result: Variant = (_adapters["query_dwarves"] as Callable).call(scan_range)
	if result is Array:
		return result as Array
	return []


func _query_food(search_range: float) -> Array:
	if not _adapters.has("query_food"):
		return []
	var result: Variant = (_adapters["query_food"] as Callable).call(search_range)
	if result is Array:
		return result as Array
	return []


func _walk_result() -> int:
	if not _adapters.has("walk_result"):
		return 0
	return int((_adapters["walk_result"] as Callable).call())


func _now() -> float:
	if not _adapters.has("now"):
		return _time
	return float((_adapters["now"] as Callable).call())


func _random_int(low: int, high: int) -> int:
	if high < low:
		return low
	if _adapters.has("random_int"):
		return int((_adapters["random_int"] as Callable).call(low, high))
	return low


func _random_float(low: float, high: float) -> float:
	if _adapters.has("random_float"):
		return float((_adapters["random_float"] as Callable).call(low, high))
	return low


## --- state readers -------------------------------------------------------------

func get_state_name() -> String:
	return _state


## True while the state machine may run (the original state_enable/disable).
func is_state_enabled() -> bool:
	return _state_enabled


func is_paralyzed() -> bool:
	return _is_paralyzed


func is_farmed() -> bool:
	return _is_farmed


func get_nutrition() -> int:
	return _nutrition


## Set the nutrition counter (the original keeps it as an instance variable,
## hamster.tcl:107). Used by editors and demos that want the hamster to look
## for food right away.
func set_nutrition(value: int) -> void:
	_nutrition = maxi(0, value)


## Game time of the actor in seconds.
func get_time() -> float:
	return _time


func get_queue_size() -> int:
	if _queue == null:
		return 0
	return int(_queue.call("cnt"))


## The queued commands, in execution order.
func get_queue_commands() -> Array[String]:
	if _queue == null:
		return []
	var result: Array[String] = []
	for command: String in _queue.call("list"):
		result.append(command)
	return result


func get_current_alias() -> String:
	return _current_alias


func get_current_clip() -> String:
	return _current_clip


func get_current_frame() -> int:
	return _current_frame


func is_playing_animation() -> bool:
	return _action_kind == "anim"


## The kind of the running action: "", "anim", "wait" or "walk".
func get_action_kind() -> String:
	return _action_kind


## Seconds left of a waiting action.
func get_wait_remaining() -> float:
	return _wait_remaining


func get_history() -> Array[String]:
	return _history.duplicate()


func get_events() -> Array[Dictionary]:
	return _events.duplicate()
