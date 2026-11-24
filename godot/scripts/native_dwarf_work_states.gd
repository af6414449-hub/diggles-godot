extends RefCounted
## Work state machine ported from the original Diggles Tcl.
##
## Source of truth (installed game, read only):
##   data/Scripts/classes/zwerg/z_work_states.tcl:80-151   state_work_auto_proc
##   data/Scripts/classes/zwerg/z_work_states.tcl:154-212  state_work_dispatch_proc
##   data/Scripts/classes/zwerg/z_work_states.tcl:215-235  work idle enter/leave
##   data/Scripts/classes/zwerg/z_work_states.tcl:238-301  state_work_idle_proc
##   data/Scripts/classes/zwerg/z_work_states.tcl:304-324  work active/breakable
##   data/Scripts/classes/zwerg/z_dignwalk.tcl:1032-1040  rotate_toangle
##   data/Scripts/classes/zwerg/z_procs.tcl:1213-1264       stop_prod
##
## Every procedure works on a plain dictionary that stands in for the global
## variables of the source. The dictionary is modified in place and the return
## value carries the recorded command sequence, so the self test can compare it
## against res://models/native_dwarf_sparetime.json call by call.
##
## Adapter boundary: the host supplies the task executor and the few values the
## source reads from the engine (`act_when_idle`, `get_gnomeposition`,
## `get_prodautoschedule`, `rand`, the inventory and the item types).

const Sparetime: Script = preload("res://scripts/native_dwarf_sparetime.gd")

## z_work_states.tcl:169 - the pause between two failed production steps.
const WORK_DELAY: int = 2
## z_work_states.tcl:201 - after this many failures the work list is dropped.
const FAILURE_LIMIT: int = 5
## z_work_states.tcl:252 - the idle animation starts after this many ticks.
const IDLE_ANIM_LIMIT: int = 3
## z_work_states.tcl:256 - the sparetime switch happens after this many ticks.
const SPARETIME_LIMIT: int = 5
## z_work_states.tcl:266 - the strike and fill dispatch happen after this many.
const IDLE_LONG_LIMIT: int = 10

## z_procs.tcl:1221-1230 - the mood penalty depends on the interrupted state.
const MOOD_KEY_BY_STATE: Dictionary = {
	"sparetime_dispatch": "stt_dst_spare",
	"reprod": "stt_dst_sex",
	"interaction": "stt_dst_talk",
	"work_dispatch": "stt_dst_work",
}
## z_procs.tcl:1230 - every other state uses the idle penalty.
const MOOD_KEY_DEFAULT: String = "stt_dst_idle"
## z_procs.tcl:1225 - only these sparetime endings are notified.
const SPARETIME_END_OCCUPATIONS: Array[String] = ["eat", "fun", "slp"]
## z_procs.tcl:1239 - only these inventory types are unpacked.
const UNPACKED_ITEM_TYPES: Array[String] = ["production", "elevator", "energy", "store", "protection"]


# --------------------------------------------------------------------------- #
# state_work_auto_proc
# --------------------------------------------------------------------------- #
## z_work_states.tcl:80-151 - the task turns into one production command.
func work_auto(state: Dictionary) -> Dictionary:
	var calls: Array = []
	state["current_occupation"] = "work"
	state["idletimeout"] = 0
	var task: String = str(state.get("current_worktask", ""))
	var workplace: String = _text(state.get("current_workplace", 0))
	var workclass: String = _text(state.get("current_workclass", 0))
	var workitem: String = _text(state.get("current_workitem", 0))
	var digpos: String = str(state.get("current_digpos", ""))
	var workpos: String = str(state.get("current_workpos", ""))
	match task:
		"pickup":
			calls.append(["state_trigger", "work_dispatch"])
			calls.append(["tasklist_add", "prod_getfromanywhere %s" % workclass])
		"pickupitem":
			calls.append(["state_trigger", "work_dispatch"])
			calls.append(["tasklist_add", "pickup %s" % workitem])
		"bringprod":
			calls.append(["state_trigger", "work_dispatch"])
			calls.append(["tasklist_add", "prod_transporttoprodlist { %s } %s" % [workclass, workplace]])
		"transferprod":
			calls.append(["state_trigger", "work_dispatch"])
			calls.append(["tasklist_add", "prod_bringtoprod %s %s" % [workitem, workplace]])
		"work":
			calls.append(["state_trigger", "work_dispatch"])
			calls.append(["tasklist_add", "prod_autobuild %s %s" % [workclass, workplace]])
		"dig":
			calls.append(["state_trigger", "work_dispatch"])
			calls.append(["tasklist_add", "dig_starttask {%s}" % digpos])
		"pack":
			calls.append(["state_trigger", "work_dispatch"])
			calls.append(["tasklist_add", "prod_autopack %s" % workplace])
		"buildup":
			calls.append(["state_trigger", "work_dispatch"])
			calls.append(["tasklist_add", "prod_autobuildup %s" % workplace])
		"unpack":
			calls.append(["state_trigger", "work_dispatch"])
			calls.append(["tasklist_add", "prod_autounpack %s {%s}" % [workplace, workpos]])
		"repair":
			calls.append(["state_trigger", "work_dispatch"])
			calls.append(["tasklist_add", "prod_autorepair %s" % workplace])
		_:
			calls.append(["state_trigger", "work_idle"])
	return {"calls": calls}


# --------------------------------------------------------------------------- #
# state_work_dispatch_proc
# --------------------------------------------------------------------------- #
## z_work_states.tcl:154-212 - one production command is executed per tick.
##
## The source evaluates a Tcl command, the port asks the host through
## `task_executor` and expects the same boolean answer.
func work_dispatch(state: Dictionary, task_executor: Callable = Callable()) -> Dictionary:
	var calls: Array = []
	state["current_occupation"] = "work"
	state["idletimeout"] = 0
	var worklist: Array = state.get("current_worklist", [])
	if worklist.is_empty():
		state["current_workplace"] = 0
		calls.append(["state_trigger", "work_idle"])
		return {"calls": calls, "warning": false}
	state["current_workdelay"] = WORK_DELAY
	var command: String = str(worklist[0])
	var raw: Variant = null
	if task_executor.is_valid():
		raw = task_executor.call(command)
	var outcome: Variant = _as_boolean(raw)
	if outcome == null:
		# z_work_states.tcl:184-185 - a task that returns no boolean is only
		# logged, the work list stays untouched.
		return {"calls": calls, "warning": true}
	if bool(outcome):
		state["prod_failurecount"] = 0
		state["current_worklist"] = _drop_first(worklist)
		var workplace: Variant = state.get("current_workplace", 0)
		if workplace != 0 and str(workplace) != "dig":
			calls.append(["call_method", "prod_progress"])
		return {"calls": calls, "warning": false}
	if str(state.get("current_plan", "")) == "sparetime":
		# z_work_states.tcl:196-199 - the sparetime plan leaves the work list
		# and the failure counter alone.
		calls.append(["state_triggerfresh", "sparetime_dispatch"])
		return {"calls": calls, "warning": false}
	state["prod_failurecount"] = int(state.get("prod_failurecount", 0)) + 1
	if int(state["prod_failurecount"]) < FAILURE_LIMIT:
		calls.append(["state_disable"])
		calls.append(["action", "wait", str(int(state["current_workdelay"]))])
	else:
		state["prod_failurecount"] = 0
		state["current_worklist"] = _drop_first(worklist)
		calls.append(["state_triggerfresh", "work_idle"])
	return {"calls": calls, "warning": false}


# --------------------------------------------------------------------------- #
# state_enter_work_idle_proc / state_leave_work_idle_proc
# --------------------------------------------------------------------------- #
## z_work_states.tcl:215-227 - entering the idle state resets the work fields.
func enter_work_idle(state: Dictionary) -> Dictionary:
	var calls: Array = []
	calls.append(["stop_prod"])
	state["current_worktask"] = ""
	state["current_workclass"] = 0
	state["last_event"] = ""
	state["event_repeat"] = 0
	calls.append(["gnome_idle", "1"])
	return {"calls": calls}


## z_work_states.tcl:230-235 - leaving the idle state clears the idle flag.
func leave_work_idle(state: Dictionary) -> Dictionary:
	var calls: Array = []
	calls.append(["gnome_idle", "0"])
	return {"calls": calls}


# --------------------------------------------------------------------------- #
# state_work_idle_proc
# --------------------------------------------------------------------------- #
## z_work_states.tcl:238-301 - the idle state counts up and hands over to the
## sparetime dispatcher once the dwarf has been idle long enough.
func work_idle(state: Dictionary) -> Dictionary:
	var calls: Array = []
	calls.append(["prod_gnome_state", "idle"])
	state["idletimeout"] = int(state.get("idletimeout", 0)) + 1
	state["current_occupation"] = "idle"
	var timeout: int = int(state["idletimeout"])
	if timeout > IDLE_ANIM_LIMIT:
		calls.append(["act_when_idle"])
		if bool(state.get("act_when_idle", false)):
			return {"calls": calls}
	if timeout > SPARETIME_LIMIT:
		if float(state.get("remaining_spare", 0.0)) > 0.0:
			calls.append(["state_enable"])
			calls.append(["state_triggerfresh", "sparetime_dispatch"])
			return {"calls": calls}
		elif bool(state.get("sparetime_is_on", false)):
			calls.append(["sparetime_state_end"])
	if timeout > IDLE_LONG_LIMIT:
		if bool(state.get("work_strike", false)):
			calls.append(["state_triggerfresh", "strike"])
		var position: int = int(state.get("gnome_position", 0))
		if position == 0:
			if float(state.get("rand_value", 0.0)) < 0.25:
				calls.append(["state_triggerfresh", "prodfill_dispatch"])
		elif position != 0 and bool(state.get("prod_autoschedule", false)) \
				and not bool(state.get("walk_down_from_wall", false)):
			return {"calls": calls}
	if int(state.get("muetzen_counter", 0)) < 0:
		if not bool(state.get("prod_autoschedule", false)):
			if str(state.get("muetze_name", "")) != str(state.get("current_muetze_name", "")):
				calls.append(["prod_change_muetze", "fight"])
				state["muetzen_counter"] = int(state.get("muetzen_counter_start", 0))
		else:
			if timeout > IDLE_LONG_LIMIT and str(state.get("current_plan", "")) == "work":
				if str(state.get("muetze_name", "")) != str(state.get("current_muetze_name", "")):
					calls.append(["prod_change_muetze", "arbeitslos"])
					state["muetzen_counter"] = int(state.get("muetzen_counter_start", 0))
	state["muetzen_counter"] = int(state.get("muetzen_counter", 0)) - 1
	calls.append(["set_idle_anim"])
	calls.append(["state_disable"])
	calls.append(["action", "wait", "1"])
	return {"calls": calls}


# --------------------------------------------------------------------------- #
# state_work_active_proc / state_work_breakable_proc
# --------------------------------------------------------------------------- #
## z_work_states.tcl:304-313 - the active state leaves for the sparetime.
func work_active(state: Dictionary) -> Dictionary:
	var calls: Array = []
	if str(state.get("current_plan", "")) == "sparetime":
		calls.append(["state_triggerfresh", "sparetime_dispatch"])
	return {"calls": calls}


## z_work_states.tcl:315-324 - the breakable state leaves for the sparetime.
func work_breakable(state: Dictionary) -> Dictionary:
	var calls: Array = []
	if str(state.get("current_plan", "")) == "sparetime":
		calls.append(["state_triggerfresh", "sparetime_dispatch"])
	return {"calls": calls}


# --------------------------------------------------------------------------- #
# rotate_toangle
# --------------------------------------------------------------------------- #
## z_dignwalk.tcl:1032-1040 - turn towards an angle.
func rotate_toangle(angle: float, animation: String = "") -> Dictionary:
	var calls: Array = []
	calls.append(["state_disable"])
	var value: String = Sparetime.tcl_double_string(angle)
	if animation.is_empty():
		calls.append(["action", "rotate", value])
	else:
		calls.append(["action", "rotate", "%s %s" % [value, animation]])
	return {"result": true, "calls": calls}


# --------------------------------------------------------------------------- #
# stop_prod
# --------------------------------------------------------------------------- #
## z_procs.tcl:1213-1264 - interrupt the current production.
func stop_prod(state: Dictionary, toolchange: bool = true) -> Dictionary:
	var calls: Array = []
	calls.append(["beam_back"])
	state["event_repeat"] = 0
	var now: float = float(state.get("now", 0.0))
	if now - float(state.get("last_disturb", -1000.0)) > 5.0:
		var current_state: String = str(state.get("current_state", ""))
		var mood_key: String = str(MOOD_KEY_BY_STATE.get(current_state, MOOD_KEY_DEFAULT))
		calls.append(["add_attrib", "atr_Mood",
			Sparetime.tcl_double_string(Sparetime.constant(mood_key, 0.0))])
		if current_state == "sparetime_dispatch":
			var occupation: String = str(state.get("current_occupation", ""))
			if SPARETIME_END_OCCUPATIONS.has(occupation):
				calls.append(["sparetime_%s_end" % occupation])
		state["last_disturb"] = now
	calls.append(["unlock_item"])
	var item_types: Dictionary = state.get("item_types", {})
	for item: Variant in state.get("inventory", []):
		if UNPACKED_ITEM_TYPES.has(str(item_types.get(item, ""))):
			calls.append(["set_prod_unpack"])
	calls.append(["dig_resetid"])
	calls.append(["placelock_rem"])
	calls.append(["placelock_rem"])
	calls.append(["enable_auto_fanim"])
	calls.append(["dig_endanim"])
	calls.append(["sparetime_reset_clothes"])
	if toolchange:
		calls.append(["change_tool", "0"])
		calls.append(["change_tool", "0", "1"])
	state["walkfail_tasks"] = ""
	var workplace: Variant = state.get("current_workplace", 0)
	if workplace != 0:
		if str(workplace) != "dig":
			calls.append(["call_method", "stop_prod_tasklist"])
			for item: Variant in state.get("workplace_tasklist", []):
				calls.append(["tasklist_add", str(item)])
		state["current_workplace"] = 0
	state["current_worklist"] = []
	return {"calls": calls}


# --------------------------------------------------------------------------- #
# helpers
# --------------------------------------------------------------------------- #
## Tcl prints a whole number of a double with a trailing `.0`.
func _text(value: Variant) -> String:
	if value is int:
		return str(value)
	if value is float:
		return Sparetime.tcl_double_string(value)
	return str(value)


func _drop_first(worklist: Array) -> Array:
	var result: Array = worklist.duplicate()
	if not result.is_empty():
		result.remove_at(0)
	return result


## z_work_states.tcl:184 - `string is boolean` accepts these words.
func _as_boolean(value: Variant) -> Variant:
	if value is bool:
		return value
	if value is int:
		if value == 1:
			return true
		if value == 0:
			return false
		return null
	if value is String:
		var text: String = str(value)
		if text in ["1", "true", "yes", "on"]:
			return true
		if text in ["0", "false", "no", "off"]:
			return false
	return null
