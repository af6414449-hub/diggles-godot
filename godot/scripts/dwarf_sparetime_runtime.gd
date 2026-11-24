extends RefCounted
## Host adapter for the sparetime contract.
##
## Bridges three ported modules into the running scene:
##   native_dwarf_sparetime.gd       the leisure decision itself
##   native_dwarf_place_registry.gd  the guest seat bookkeeping
##   native_dwarf_work_states.gd     the work state machine
##
## The runtime owns the per dwarf leisure state that the original keeps in
## globals (z_spare_main.tcl:328-376) and publishes the decision to the host
## model. Everything that needs the engine (food, beds, hospitals, real seats)
## stays an explicit host dependency: the decision is published, the engine
## side effects are not faked here.
##
## Host dependencies:
##   subject.dwarf_life.models[dwarf]  the needs and the time plan
##   subject.actor_tasks                the task runner, a busy dwarf is skipped
##   subject.dwarf_sleep                the sleep runtime, a sleeping dwarf is skipped
##   subject.game_clock.seconds         the game time

const Sparetime: Script = preload("res://scripts/native_dwarf_sparetime.gd")
const PlaceRegistry: Script = preload("res://scripts/native_dwarf_place_registry.gd")
const WorkStates: Script = preload("res://scripts/native_dwarf_work_states.gd")
const Clock: Script = preload("res://scripts/native_work_clock.gd")

## z_spare_main.tcl:54 - the plan is rebuilt when the last visit is older.
const REPLAN_AGE: float = 100.0
## z_spare_main.tcl:398 - the bath desire above this opens an empty plan.
const BATH_OPEN: float = 6.0

var subject: Node3D = null
var places: RefCounted = null
var work: RefCounted = null
## dwarf -> the leisure state of the original globals
var models: Dictionary = {}
## dwarf -> the last decision of the original `sparetime_decide_occup`
var decisions: Dictionary = {}
var enabled: bool = true
var rng: RandomNumberGenerator = RandomNumberGenerator.new()


func configure(scene: Node3D) -> void:
	subject = scene
	places = PlaceRegistry.new()
	work = WorkStates.new()
	models.clear()
	decisions.clear()
	for dwarf: Node3D in subject.dwarf_nodes:
		models[dwarf] = fresh_state()


# --------------------------------------------------------------------------- #
# per dwarf state
# --------------------------------------------------------------------------- #
## z_spare_main.tcl:247-257 and z_spare_main.tcl:328-336.
func fresh_state() -> Dictionary:
	return {
		"sparetime_goal": "",
		"sparetime_mingoal": "",
		"sparetime_goal_reached": 2,
		"sparetime_emergency": 0,
		"sparetime_emchange_initial": 0,
		"sparetime_compare_value": 0.0,
		"sparetime_remembered_scv": 0.0,
		"sparetime_future": [],
		"sparetime_history": [],
		"sparetime_initialize": 2,
		"sparetime_is_on": 0,
		"sparetime_rest": 0.0,
		"sparetime_disappointment": 0.0,
		"sparetime_disapp_rates": 0,
		"spt_fun_ignore": 0,
		"spt_fun_stations": 0,
		"spt_fun_needs": 0,
		"spt_fun_portion": 0.0,
		"spt_bath_desire": 0.0,
		"has_bathed": 0.0,
		"current_wish_occupation": "",
		"last_spareleave": 0.0,
		"phase_start": 0.0,
	}


func model(dwarf: Node3D) -> Dictionary:
	if not models.has(dwarf):
		models[dwarf] = fresh_state()
	return models[dwarf]


func decision(dwarf: Node3D) -> Dictionary:
	if not decisions.has(dwarf):
		return {}
	return decisions[dwarf]


# --------------------------------------------------------------------------- #
# the tick
# --------------------------------------------------------------------------- #
func update() -> void:
	if not enabled or subject == null:
		return
	var now: float = float(subject.game_clock.seconds)
	for dwarf: Node3D in subject.dwarf_nodes:
		if not subject.dwarf_life.models.has(dwarf):
			continue
		var life: Dictionary = subject.dwarf_life.models[dwarf]
		var state: Dictionary = model(dwarf)
		var plan: String = str(life.get("time_plan", ""))
		if plan != "sparetime":
			if int(state.get("sparetime_is_on", 0)) != 0:
				# z_spare_main.tcl:53 - the dwarf left the leisure state.
				state["last_spareleave"] = now
				state["sparetime_is_on"] = 0
			continue
		if int(state.get("sparetime_is_on", 0)) == 0:
			state["phase_start"] = now
			state["sparetime_is_on"] = 1
		if bool(life.get("is_sleeping", false)) or busy(dwarf):
			continue
		decide(dwarf)


## A dwarf that still runs a task or digs is not available for the leisure.
func busy(dwarf: Node3D) -> bool:
	if subject.actor_tasks == null:
		return false
	if subject.actor_tasks.active.has(dwarf):
		return true
	var runner: RefCounted = subject.actor_tasks.runner(dwarf)
	if runner == null:
		return false
	return bool(runner.blocked) or runner.queue.count() > 0


# --------------------------------------------------------------------------- #
# the decision
# --------------------------------------------------------------------------- #
func decide(dwarf: Node3D) -> Dictionary:
	var life: Dictionary = subject.dwarf_life.models[dwarf]
	var state: Dictionary = model(dwarf)
	var needs: Dictionary = life["needs"]
	state["at_Hi"] = float(needs["hitpoints"])
	state["at_Nu"] = float(needs["nutrition"])
	state["at_Al"] = float(needs["alertness"])
	state["at_Mo"] = float(needs["mood"])
	state["current_occupation"] = str(life.get("occupation", "idle"))
	state["remaining_spare"] = remaining_spare(dwarf)
	state["eat_check"] = int(state.get("eat_check", 0))
	state["ill_check"] = int(state.get("ill_check", 0))
	refresh_plan(dwarf, state)
	var result: Dictionary = Sparetime.decide_occup(state)
	store(state, result)
	decisions[dwarf] = result
	publish(dwarf, result)
	return result


## z_spare_main.tcl:53-68 - the leisure sequence is planned once per phase.
func refresh_plan(dwarf: Node3D, state: Dictionary) -> void:
	var phase_start: float = float(state.get("phase_start", 0.0))
	var stale: bool = float(state.get("last_spareleave", 0.0)) < phase_start - REPLAN_AGE
	var empty: bool = (state.get("sparetime_future", []) as Array).is_empty()
	if not stale and not empty:
		return
	state["sparetime_rest"] = remaining_spare(dwarf)
	var future: Array[String] = Sparetime.plan_future(
		float(state["sparetime_rest"]),
		int(state.get("sparetime_initialize", 0)),
		float(state.get("spt_bath_desire", 0.0)),
		rng.randi_range(0, 1))
	state["sparetime_future"] = future
	state["spt_fun_stations"] = 0
	state["spt_fun_fail"] = 0
	state["spt_talk_fail"] = 0
	state["spt_talkfind_counter"] = 0


## The decision returns the whole state, the mutable leisure fields are copied back.
func store(state: Dictionary, result: Dictionary) -> void:
	for key: String in ["sparetime_goal", "sparetime_mingoal", "sparetime_goal_reached",
			"sparetime_emergency", "sparetime_emchange_initial", "sparetime_compare_value",
			"sparetime_remembered_scv", "sparetime_future", "sparetime_history",
			"current_wish_occupation", "spt_fun_ignore", "spt_fun_portion"]:
		if result.has(key):
			state[key] = result[key]


## The decision is published to the host model, the engine still has to act on it.
func publish(dwarf: Node3D, result: Dictionary) -> void:
	var life: Dictionary = subject.dwarf_life.models[dwarf]
	life["sparetime_wish"] = str(result.get("current_wish_occupation", ""))
	life["sparetime_goal"] = str(result.get("sparetime_goal", ""))
	life["sparetime_goal_reached"] = int(result.get("sparetime_goal_reached", 2))
	life["sparetime_emergency"] = int(result.get("sparetime_emergency", 0))
	life["sparetime_future"] = (result.get("sparetime_future", []) as Array).duplicate()
	dwarf.set_meta("current_wish_occupation", life["sparetime_wish"])
	dwarf.set_meta("sparetime_goal", life["sparetime_goal"])


# --------------------------------------------------------------------------- #
# helpers
# --------------------------------------------------------------------------- #
## z_spare_main.tcl:53 - the rest is the remaining leisure of the shift.
func remaining_spare(dwarf: Node3D) -> float:
	var life: Dictionary = subject.dwarf_life.models[dwarf]
	if str(life.get("time_plan", "")) == "work":
		return 0.0
	return Clock.remaining_spare(float(subject.game_clock.seconds),
		float(life.get("shift_start", 0.0)), false)


## z_spare_main.tcl:398 - a strong bath desire fills an empty plan.
func bath_opens_plan(state: Dictionary) -> bool:
	return (state.get("sparetime_future", []) as Array).is_empty() \
		and int(state.get("sparetime_emergency", 0)) == 0 \
		and float(state.get("spt_bath_desire", 0.0)) > BATH_OPEN


## The work state of one dwarf, ready for native_dwarf_work_states.
func work_state(dwarf: Node3D) -> Dictionary:
	var life: Dictionary = subject.dwarf_life.models[dwarf]
	var state: Dictionary = model(dwarf)
	return {
		"current_worktask": str(life.get("work_task", "")),
		"current_workplace": life.get("work_place", 0),
		"current_workitem": life.get("work_item", 0),
		"current_workclass": life.get("work_class", 0),
		"current_digpos": str(life.get("dig_position", "")),
		"current_workpos": str(life.get("work_position", "")),
		"current_worklist": life.get("work_list", []),
		"current_plan": str(life.get("time_plan", "")),
		"current_occupation": str(life.get("occupation", "idle")),
		"current_state": str(life.get("state", "")),
		"current_muetze_name": str(life.get("muetze_name", "")),
		"idletimeout": int(life.get("idletimeout", 0)),
		"prod_failurecount": int(life.get("prod_failurecount", 0)),
		"muetzen_counter": int(life.get("muetzen_counter", 0)),
		"muetzen_counter_start": int(life.get("muetzen_counter_start", 0)),
		"work_strike": bool(life.get("work_strike", false)),
		"sparetime_is_on": int(state.get("sparetime_is_on", 0)),
		"remaining_spare": remaining_spare(dwarf),
		"now": float(subject.game_clock.seconds),
		"last_disturb": float(life.get("last_disturb", -1000.0)),
		"last_event": str(life.get("last_event", "")),
		"event_repeat": int(life.get("event_repeat", 0)),
		"inventory": life.get("inventory", []),
		"item_types": life.get("item_types", {}),
		"workplace_tasklist": life.get("workplace_tasklist", []),
	}
