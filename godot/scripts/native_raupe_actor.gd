extends RefCounted
## Autonomous Raupe actor: the original raupe.tcl control flow as a runtime.
##
## The Raupe is a farm animal: it is bred by a Farm, it roams around the farm
## pen, it waits in the inventory and - when it is loose - it eats the plants
## of the dig site until it dies of its own bite.
##
## Sources (original install, data/Scripts/classes/characters/raupe.tcl):
##   :27-65    obj_init: variant, weight, hitpoints, farm test
##   :67-85    crawl_free
##   :87-115   crawl_farmed
##   :117-146  find_plant
##   :148-164  move and wait
##   :166-178  evt_timer0: the one second farm classification
##   :207-216  state free
##   :218-236  state farmed
##   :238-251  state contained
##   :253-319  state plant_attack
##
## Adapter contract (all optional):
##   actor_pos        Callable() -> Vector3
##   max_fow          Callable() -> float          (get_max_fow)
##   is_contained     Callable() -> bool
##   owner_id         Callable() -> String         (get_owner)
##   query_farm       Callable(Dictionary) -> Dictionary   ({ref, position})
##   farm_state       Callable(String) -> Dictionary        ({valid, buildup})
##   query_dwarf      Callable(Dictionary) -> Dictionary   ({ref, position})
##   query_plant      Callable(Dictionary) -> Dictionary   ({ref, position})
##   plant_state      Callable(String) -> Dictionary        ({valid, position})
##   pick_place       Callable(Dictionary) -> Dictionary    ({code, position})
##   damage_plant     Callable(String, float) -> void
##   emit_particles   Callable(Dictionary) -> void
##   destroy_actor    Callable() -> void
##   move_action      Callable(Dictionary) -> bool
##   move_complete    Callable() -> bool
##   play_clip        Callable(Dictionary) -> bool
##
## ENGINE ADAPTATION: the original triggers the free and the farmed state
## fresh every second. Whether the engine applies that trigger while an action
## runs is not visible in the Tcl sources. The port keeps the classification
## every second but does not let it interrupt a running action, because the
## original waits four seconds in the inventory and the plant attack cycle is
## longer than the one second of the timer. Without that rule the documented
## plant attack could never finish. The classification of the timer is kept
## until the actor is idle again, so a Raupe that walks into a farm is still
## reclassified on the next free moment of the actor.

const RaupeAi = preload("res://scripts/native_raupe_ai.gd")
const DigglesRandom = preload("res://scripts/diggles_irandom.gd")
## The task list of the hamster actor carries the commands of the running
## action. The Raupe uses the same queue for its steps: a wait, an animation
## frame and the bite.
const TaskList = preload("res://scripts/native_tasklist.gd")

const TIMER_INTERVAL: float = 1.0
const YAW_RANGE: float = 6.28
const PLACE_MIN_FREE: int = 0
const PLACE_MIN_FARM: int = 1
const PLACE_MIN_PLANT: int = 1
const ATTACK_HOLD: float = 1.0
const ATTACK_TICK: float = 0.2

var _adapters: Dictionary = {}
var _rng: RefCounted = null
var _steps: RefCounted = null

# --- original instance state (raupe.tcl:31-58) -------------------------------
var _state: String = RaupeAi.STATE_FREE
var _state_enabled: bool = true
var _variant: int = 1
var _attack_type: int = 0
var _attack_counter: int = 0
var _attack_plant: String = ""
var _plant_position: Vector3 = Vector3.ZERO
var _approached: int = 0
var _attack_frame: int = 5
var _hitpoints: float = RaupeAi.HITPOINTS
var _farmed: bool = false
var _farm_id: String = ""
var _farm_position: Vector3 = Vector3.ZERO
var _owner_id: String = ""
var _anim_mode: String = RaupeAi.ANIM_WAIT
var _yaw: float = 0.0
var _particle_direction: Vector3 = Vector3.ZERO
var _particle_position: Vector3 = Vector3.ZERO
var _contained: bool = false

# --- runtime -----------------------------------------------------------------
var _time: float = 0.0
var _timer_accumulator: float = 0.0
var _next_decision_time: float = 0.0
var _action_kind: String = ""
var _wait_remaining: float = 0.0
var _wait_started: bool = false
var _pending_classification: String = ""
var _trace: Array[String] = []


## Create the actor and draw its type from the seeded random generator.
func setup(adapters: Dictionary = {}, seed_value: int = 0) -> void:
	_adapters = adapters.duplicate()
	_rng = DigglesRandom.new()
	_rng.call("seed_with", seed_value)
	_steps = TaskList.new()
	_variant = 1 + int(_rng.call("irandom", RaupeAi.VARIANT_MAX))
	_attack_type = 1 if RaupeAi.is_predatory(_variant) else 0
	_yaw = _random_float(0.0, YAW_RANGE)
	_hitpoints = RaupeAi.HITPOINTS
	_anim_mode = RaupeAi.ANIM_WAIT
	_trace.clear()
	_trace.append("variant:%d" % _variant)
	_set_anim(RaupeAi.ANIM_WAIT, 0)


## Advance the actor: run the timer event and the state machine.
func tick(delta: float) -> void:
	var step := maxf(0.0, delta)
	_time += step
	_advance_action(step)
	_timer_accumulator += step
	if _timer_accumulator >= TIMER_INTERVAL:
		_timer_accumulator = 0.0
		_timer_event()
	if _state_enabled:
		_state_step()


## The one second classification timer (raupe.tcl:166-178).
##
## The timer recomputes the farm of the Raupe every second and asks for a
## fresh trigger to free or to farmed. The plant attack owns its state until
## it leaves it by itself, so the timer never interrupts the bite.
func _timer_event() -> void:
	_classify_farm()
	_next_decision_time = _time + TIMER_INTERVAL
	if _state == RaupeAi.STATE_PLANT_ATTACK and _attack_plant != "":
		return
	if _state == RaupeAi.STATE_CONTAINED and not _is_contained():
		# The Raupe left the inventory: the timer notices the release at once
		# and cuts the wait of the contained state short.
		_finish_action()
		_trigger(RaupeAi.STATE_FARMED if _farmed else RaupeAi.STATE_FREE)
		return
	# The classification waits for the next free moment of the actor: a
	# running action must not be interrupted, but the classification of the
	# timer must not be lost either.
	_pending_classification = RaupeAi.STATE_FARMED if _farmed else RaupeAi.STATE_FREE


## One state machine step.
func _state_step() -> void:
	_apply_pending()
	if _state == RaupeAi.STATE_FREE:
		_free_proc()
	elif _state == RaupeAi.STATE_FARMED:
		_farmed_proc()
	elif _state == RaupeAi.STATE_CONTAINED:
		_contained_proc()
	else:
		_plant_attack_proc()


## Apply the classification of the timer.
##
## A transition is a fresh trigger of a state, never a fall through: the body
## of the new state starts at its first line in the next step.
func _apply_pending() -> void:
	if _pending_classification == "":
		return
	if _state == RaupeAi.STATE_PLANT_ATTACK:
		# The attack leaves the state only by itself (raupe.tcl:259-273).
		return
	var classification := _pending_classification
	_pending_classification = ""
	_trigger(classification)


## The free state (raupe.tcl:207-216).
func _free_proc() -> void:
	if _is_contained():
		_enter_contained()
		return
	_crawl_free()


## crawl_free (raupe.tcl:67-85).
##
## The visibility gate comes first: a Raupe that cannot see enough does
## nothing at all, not even a plant search.
func _crawl_free() -> void:
	if _max_fow() < RaupeAi.FOW_MIN:
		return
	var position := _own_position()
	var turn := RaupeAi.free_turn(_yaw, _random_unit() * 3.0 - 1.5)
	if _find_plant():
		return
	turn = RaupeAi.free_reverse(turn, _random_unit())
	var distance := _random_float(RaupeAi.FREE_DISTANCE_MIN, RaupeAi.FREE_DISTANCE_MAX)
	var candidate := RaupeAi.free_candidate(position, turn, distance)
	var place := _pick_place(RaupeAi.free_place_request(position, candidate))
	if RaupeAi.place_failed(int(place.get("code", -1)), PLACE_MIN_FREE):
		_wait_idle(RaupeAi.WAIT_NO_PLACE)
		return
	var target: Variant = place.get("position", candidate)
	if not (target is Vector3):
		_wait_idle(RaupeAi.WAIT_NO_PLACE)
		return
	_yaw = RaupeAi.yaw_towards(position, target as Vector3)
	_start_move(target as Vector3)


## The farmed state (raupe.tcl:218-236).
func _farmed_proc() -> void:
	if _is_contained():
		_enter_contained()
		return
	if not _farm_is_valid():
		_trigger(RaupeAi.STATE_FREE)
		_trace.append("state:free")
		return
	if RaupeAi.farmed_wait(_random_unit()):
		_wait_idle(RaupeAi.WAIT_FARMED)
		return
	_crawl_farmed()


## crawl_farmed (raupe.tcl:87-115).
func _crawl_farmed() -> void:
	var position := _own_position()
	var dwarf := _query_dwarf()
	var centre := position
	var has_dwarf := false
	if not dwarf.is_empty():
		var dwarf_position: Variant = dwarf.get("position", null)
		if dwarf_position is Vector3:
			centre = dwarf_position as Vector3
			has_dwarf = true
	var place := _pick_place(RaupeAi.farm_place_request(_farm_position, centre, has_dwarf, position))
	if RaupeAi.place_failed(int(place.get("code", -1)), PLACE_MIN_FARM):
		_wait_idle(RaupeAi.WAIT_NO_PLACE)
		return
	var target: Variant = place.get("position", centre)
	if not (target is Vector3):
		_wait_idle(RaupeAi.WAIT_NO_PLACE)
		return
	_yaw = RaupeAi.yaw_towards(position, target as Vector3)
	_start_move(target as Vector3)


## The contained state (raupe.tcl:238-251).
func _contained_proc() -> void:
	if _is_contained():
		_wait_idle(RaupeAi.WAIT_CONTAINED)
		return
	_contained = false
	_classify_farm()
	_trigger(RaupeAi.STATE_FARMED if _farmed else RaupeAi.STATE_FREE)


## find_plant (raupe.tcl:117-146).
##
## The search runs on the eleventh call of a predatory type.
func _find_plant() -> bool:
	if _attack_type == 0:
		return false
	var step := RaupeAi.attack_counter_step(_attack_counter)
	_attack_counter = int(step["counter"])
	if not bool(step["search"]):
		return false
	var owner := _owner()
	if owner == "" or owner == "-1":
		return false
	var plant := _query_plant()
	if plant.is_empty():
		return false
	var reference := String(plant.get("ref", ""))
	if reference == "":
		return false
	var position: Variant = plant.get("position", null)
	if position is Vector3:
		_plant_position = position as Vector3
	var own := _own_position()
	if own.distance_to(_plant_position) > RaupeAi.APPROACH_RANGE:
		# The plant is too far: the Raupe reserves a place around it first.
		var place := _pick_place(RaupeAi.plant_place_request(_plant_position, own))
		if RaupeAi.place_failed(int(place.get("code", -1)), PLACE_MIN_PLANT):
			# No place: the original keeps the old target, the Raupe roams on.
			return false
	_attack_plant = reference
	_trigger(RaupeAi.STATE_PLANT_ATTACK)
	_trace.append("state:plant_attack")
	return true


## The plant attack (raupe.tcl:253-319).
##
## The attack is self sacrificing: every bite takes more from the Raupe than
## from the plant, so the Raupe dies after its first bite.
func _plant_attack_proc() -> void:
	if _hitpoints < RaupeAi.DEATH_THRESHOLD:
		_destroy()
		return
	if _is_contained():
		_attack_plant = ""
		_approached = 0
		_enter_contained()
		return
	if not _plant_is_valid():
		_attack_plant = ""
		_approached = 0
		_trigger(RaupeAi.STATE_FREE)
		_set_anim(RaupeAi.ANIM_CRAWL, 0)
		_trace.append("state:free")
		return
	var own := _own_position()
	var distance := own.distance_to(_plant_position)
	var angle := RaupeAi.angle_xz(_plant_position, own)
	if _approached == 0:
		if RaupeAi.approach_finished(distance):
			_approached = 1
			_trace.append("approached")
			return
		_yaw = RaupeAi.yaw_towards(own, _plant_position)
		_start_move(RaupeAi.approach_point(_plant_position, angle))
		return
	if _approached == 1:
		_approached = 2
		_attack_frame = RaupeAi.attack_frame(_random_int(0, 1))
		var particle := RaupeAi.attack_particle(_plant_position, angle)
		_particle_direction = particle["direction"] as Vector3
		_particle_position = particle["position"] as Vector3
		_yaw = RaupeAi.yaw_away(_plant_position, own)
		# The windup of the original (raupe.tcl:286-293): the crawl clip is
		# played once, the actor waits half a second or nine tenths of a
		# second, holds the windup frame and waits one second more.
		_set_anim(RaupeAi.ANIM_CRAWL, 0)
		_queue_anim(0)
		_queue_wait(RaupeAi.windup_seconds(_attack_frame))
		_queue_anim(_attack_frame)
		_queue_wait(ATTACK_HOLD)
		_start_steps()
		_trace.append("windup")
		return
	# The bite of the original (raupe.tcl:294-306): the plant takes the damage
	# at once, the actor holds the frame before the bite, the particles and the
	# own hitpoints follow after the short pause.
	_damage_plant(_attack_plant, RaupeAi.PLANT_DAMAGE)
	_set_anim(RaupeAi.ANIM_CRAWL, _attack_frame - 1)
	_queue_anim(_attack_frame - 1)
	_queue_wait(ATTACK_TICK)
	_queue_strike()
	_queue_anim(_attack_frame)
	_queue_wait(ATTACK_HOLD)
	_start_steps()
	_trace.append("damage")


## A state trigger only selects the state, like the original state_triggerfresh.
##
## The state machine runs the current state on every step, so a fresh trigger
## is the same as a plain one here: the body of the new state starts at its
## first line in the next step, it never falls through.
func _trigger(state_name: String) -> void:
	_state = state_name
	_pending_classification = ""


## --- actions -----------------------------------------------------------------

## The move action of the original (raupe.tcl:148-156).
func _start_move(target: Vector3) -> void:
	if _anim_mode != RaupeAi.ANIM_CRAWL:
		_set_anim(RaupeAi.ANIM_CRAWL, 0)
	_state_enabled = false
	_action_kind = "move"
	_clear_steps()
	if _adapters.has("move_action"):
		(_adapters["move_action"] as Callable).call(RaupeAi.move_request(target))
	_trace.append("move")


## The wait action of the original (raupe.tcl:158-164).
##
## The wait is a step of the task list of the actor, like the commands of the
## hamster actor: the queue carries the running action of the Raupe.
func _start_wait(seconds: float) -> void:
	_state_enabled = false
	_action_kind = "steps"
	_clear_steps()
	_queue_wait(seconds)
	_trace.append("wait:%.2f" % seconds)


## A wait that also switches to the still animation of the original.
func _wait_idle(seconds: float) -> void:
	_set_anim(RaupeAi.ANIM_WAIT, 0)
	_start_wait(seconds)


## Start the queued steps of the actor.
func _start_steps() -> void:
	_state_enabled = false
	_action_kind = "steps"


## Queue a wait step.
func _queue_wait(seconds: float) -> void:
	_steps.call("add", "wait %s" % str(seconds))


## Queue an animation step of the crawl clip.
func _queue_anim(frame: int) -> void:
	_steps.call("add", "anim %d" % frame)


## Queue the bite: the particles of the original and the own hitpoints.
func _queue_strike() -> void:
	_steps.call("add", "strike")


## Drop the queued steps of the actor.
func _clear_steps() -> void:
	if _steps == null:
		return
	_steps.call("clear")
	_wait_remaining = 0.0
	_wait_started = false


## Advance the running action and release the state machine when it ends.
func _advance_action(delta: float) -> void:
	if _action_kind == "move":
		if not _adapters.has("move_complete"):
			_finish_action()
		elif bool((_adapters["move_complete"] as Callable).call()):
			_finish_action()
		return
	if _action_kind != "steps":
		return
	_run_steps(delta)


## Run the queued steps of the running action.
##
## A wait step keeps its place in the queue until the time is over, so a step
## that follows a wait only starts when the wait is over. The time that a step
## does not use is carried over to the next step.
func _run_steps(delta: float) -> void:
	var remaining := maxf(0.0, delta)
	var guard: int = 0
	while _action_kind == "steps" and guard < 16:
		guard += 1
		var command := String(_steps.call("get_command", 0))
		if command == "":
			_finish_action()
			return
		var parts := command.split(" ")
		var head := String(parts[0])
		if head == "wait":
			if not _wait_started:
				_wait_remaining = float(parts[1]) if parts.size() > 1 else 0.0
				_wait_started = true
			var spent := minf(_wait_remaining, remaining)
			_wait_remaining -= spent
			remaining -= spent
			if _wait_remaining > 0.0:
				return
			_wait_remaining = 0.0
			_wait_started = false
			_steps.call("remove", 0)
			continue
		_steps.call("remove", 0)
		if head == "anim":
			_set_anim(RaupeAi.ANIM_CRAWL, int(parts[1]) if parts.size() > 1 else 0)
		elif head == "strike":
			_emit_particles()
			_hitpoints -= RaupeAi.SELF_DAMAGE


func _finish_action() -> void:
	_action_kind = ""
	_state_enabled = true
	_clear_steps()


## --- world -------------------------------------------------------------------

## test_farmed (raupe.tcl:62-65).
func _classify_farm() -> void:
	var farm := _query_farm()
	if farm.is_empty():
		_farmed = false
		_farm_id = ""
		_farm_position = Vector3.ZERO
		return
	_farmed = true
	_farm_id = String(farm.get("ref", ""))
	var position: Variant = farm.get("position", null)
	if position is Vector3:
		_farm_position = position as Vector3


## The farm handle has to be alive and built up (raupe.tcl:225).
func _farm_is_valid() -> bool:
	if _farm_id == "":
		return false
	if not _adapters.has("farm_state"):
		return true
	var value: Variant = (_adapters["farm_state"] as Callable).call(_farm_id)
	if not (value is Dictionary):
		return false
	var state: Dictionary = value as Dictionary
	return bool(state.get("valid", false)) and bool(state.get("buildup", false))


## The plant has to be alive (raupe.tcl:267).
func _plant_is_valid() -> bool:
	if _attack_plant == "":
		return false
	if not _adapters.has("plant_state"):
		return true
	var value: Variant = (_adapters["plant_state"] as Callable).call(_attack_plant)
	if not (value is Dictionary):
		return false
	var state: Dictionary = value as Dictionary
	var valid := bool(state.get("valid", false))
	var position: Variant = state.get("position", null)
	if valid and position is Vector3:
		_plant_position = position as Vector3
	return valid


func _damage_plant(reference: String, amount: float) -> void:
	if not _adapters.has("damage_plant"):
		return
	(_adapters["damage_plant"] as Callable).call(reference, amount)


func _emit_particles() -> void:
	if not _adapters.has("emit_particles"):
		return
	(_adapters["emit_particles"] as Callable).call({
		"source": RaupeAi.PARTICLE_SOURCE,
		"position": _particle_position,
		"direction": _particle_direction,
		"amount": RaupeAi.PARTICLE_AMOUNT,
		"flag": RaupeAi.PARTICLE_FLAG,
	})


func _destroy() -> void:
	_state_enabled = false
	_clear_steps()
	_trace.append("destroy")
	if _adapters.has("destroy_actor"):
		(_adapters["destroy_actor"] as Callable).call()


func _enter_contained() -> void:
	_contained = true
	_trigger(RaupeAi.STATE_CONTAINED)
	_set_anim(RaupeAi.ANIM_WAIT, 0)
	_trace.append("state:contained")


func _set_anim(mode: String, frame: int = 0) -> void:
	_anim_mode = mode
	if _adapters.has("play_clip"):
		(_adapters["play_clip"] as Callable).call(RaupeAi.anim_clip(_variant, mode, frame))
	_trace.append("anim:%s:%d" % [mode, frame])


## --- adapters ----------------------------------------------------------------

func _own_position() -> Vector3:
	if not _adapters.has("actor_pos"):
		return Vector3.ZERO
	var value: Variant = (_adapters["actor_pos"] as Callable).call()
	if value is Vector3:
		return value as Vector3
	return Vector3.ZERO


func _max_fow() -> float:
	if not _adapters.has("max_fow"):
		return RaupeAi.FOW_MIN
	return float((_adapters["max_fow"] as Callable).call())


func _is_contained() -> bool:
	if not _adapters.has("is_contained"):
		return false
	return bool((_adapters["is_contained"] as Callable).call())


func _owner() -> String:
	if _adapters.has("owner_id"):
		return String((_adapters["owner_id"] as Callable).call())
	return _owner_id


func _query_farm() -> Dictionary:
	if not _adapters.has("query_farm"):
		return {}
	var value: Variant = (_adapters["query_farm"] as Callable).call(RaupeAi.farm_query(_own_position()))
	if value is Dictionary:
		return value as Dictionary
	return {}


func _query_dwarf() -> Dictionary:
	if not _adapters.has("query_dwarf"):
		return {}
	var value: Variant = (_adapters["query_dwarf"] as Callable).call(RaupeAi.dwarf_query(_farm_position))
	if value is Dictionary:
		return value as Dictionary
	return {}


func _query_plant() -> Dictionary:
	if not _adapters.has("query_plant"):
		return {}
	var value: Variant = (_adapters["query_plant"] as Callable).call(RaupeAi.plant_query(_own_position()))
	if value is Dictionary:
		return value as Dictionary
	return {}


func _pick_place(request: Dictionary) -> Dictionary:
	if not _adapters.has("pick_place"):
		return {"code": -1, "position": Vector3.ZERO}
	var value: Variant = (_adapters["pick_place"] as Callable).call(request)
	if value is Dictionary:
		return value as Dictionary
	return {"code": -1, "position": Vector3.ZERO}


## --- random ------------------------------------------------------------------

func _random_unit() -> float:
	var value: int = int(_rng.call("next_u32")) & 0x7FFFFFFF
	return float(value) / 2147483648.0


func _random_float(low: float, high: float) -> float:
	return low + _random_unit() * (high - low)


func _random_int(low: int, high: int) -> int:
	if high < low:
		return low
	return low + int(_rng.call("irandom", high - low + 1))


## --- public class methods -----------------------------------------------------

func get_state() -> String:
	return _state


func get_variant() -> int:
	return _variant


func get_variant_tag() -> String:
	return RaupeAi.variant_tag(_variant)


func get_attack_type() -> int:
	return _attack_type


func get_hitpoints() -> float:
	return _hitpoints


func get_anim_mode() -> String:
	return _anim_mode


func get_attack_plant() -> String:
	return _attack_plant


func get_approached() -> int:
	return _approached


func get_yaw() -> float:
	return _yaw


func get_farm_id() -> String:
	return _farm_id


func get_trace() -> Array[String]:
	return _trace.duplicate()


## Set the type of an existing Raupe (raupe.tcl:192-194).
func set_variant(variant: int) -> void:
	_variant = clampi(variant, RaupeAi.VARIANT_MIN, RaupeAi.VARIANT_MAX)
	_attack_type = 1 if RaupeAi.is_predatory(_variant) else 0


## The owner of the Raupe (get_owner this).
func set_owner(owner_id: String) -> void:
	_owner_id = owner_id


## The farm the Raupe belongs to.
func set_farm(reference: String, position: Vector3) -> void:
	_farm_id = reference
	_farm_position = position
	_farmed = reference != ""


## The inventory state of the Raupe.
func set_contained(contained: bool) -> void:
	_contained = contained
	if contained:
		_enter_contained()
		return
	if _state == RaupeAi.STATE_CONTAINED:
		_classify_farm()
		_trigger(RaupeAi.STATE_FARMED if _farmed else RaupeAi.STATE_FREE)


## The time of the next decision of the timer.
func get_next_decision_time() -> float:
	return _next_decision_time


## True while the Raupe sits in an inventory.
func is_contained() -> bool:
	return _contained


## The queued steps of the running action, in execution order.
func get_queue_commands() -> Array[String]:
	if _steps == null:
		return []
	var result: Array[String] = []
	for command: String in _steps.call("list"):
		result.append(command)
	return result


## The serialisable state of the actor, for a multiplayer snapshot.
func get_state_snapshot() -> Dictionary:
	return {
		"variant": _variant,
		"variant_id": RaupeAi.variant_tag(_variant),
		"state": _state,
		"attack_type": _attack_type,
		"attack_counter": _attack_counter,
		"attack_plant": _attack_plant,
		"attack_plant_id": _attack_plant,
		"plant_position": _plant_position,
		"approached": _approached,
		"attack_frame": _attack_frame,
		"hitpoints": _hitpoints,
		"farmed": _farmed,
		"farm_id": _farm_id,
		"farm_position": _farm_position,
		"owner_id": _owner_id,
		"contained": _contained,
		"anim_mode": _anim_mode,
		"yaw": _yaw,
		"time": _time,
		"next_decision_time": _next_decision_time,
		"rng": _rng.call("get_state"),
	}


## Restore an actor from a snapshot.
func restore_from_snapshot(snapshot: Dictionary) -> void:
	_variant = int(snapshot.get("variant", _variant))
	_attack_type = int(snapshot.get("attack_type", _attack_type))
	_state = String(snapshot.get("state", _state))
	_attack_counter = int(snapshot.get("attack_counter", _attack_counter))
	_attack_plant = String(snapshot.get("attack_plant", _attack_plant))
	_plant_position = snapshot.get("plant_position", _plant_position)
	_approached = int(snapshot.get("approached", _approached))
	_attack_frame = int(snapshot.get("attack_frame", _attack_frame))
	_hitpoints = float(snapshot.get("hitpoints", _hitpoints))
	_farmed = bool(snapshot.get("farmed", _farmed))
	_farm_id = String(snapshot.get("farm_id", _farm_id))
	_farm_position = snapshot.get("farm_position", _farm_position)
	_owner_id = String(snapshot.get("owner_id", _owner_id))
	_contained = bool(snapshot.get("contained", _contained))
	_anim_mode = String(snapshot.get("anim_mode", _anim_mode))
	_yaw = float(snapshot.get("yaw", _yaw))
	_time = float(snapshot.get("time", _time))
	_next_decision_time = float(snapshot.get("next_decision_time", _next_decision_time))
	if snapshot.has("rng"):
		_rng.call("set_state", snapshot["rng"])
