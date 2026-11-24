extends SceneTree
## Work state machine: the port is compared against the original Tcl
## procedures executed by tools/export_dwarf_sparetime_contract.py.
##
## Source of truth:
##   data/Scripts/classes/zwerg/z_work_states.tcl
##   data/Scripts/classes/zwerg/z_dignwalk.tcl:1032-1040
##   data/Scripts/classes/zwerg/z_procs.tcl:1213-1264

const Work: Script = preload("res://scripts/native_dwarf_work_states.gd")
var checks: int = 0
var failures: int = 0


func check(condition: bool, label: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		printerr("FAIL ", label)


func check_equal(actual: Variant, expected: Variant, label: String) -> void:
	checks += 1
	if str(actual) != str(expected):
		failures += 1
		printerr("FAIL ", label, " actual=", str(actual), " expected=", str(expected))


func _init() -> void:
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_dwarf_sparetime.json"))
	check(data["schema"] == "diggles.dwarf_sparetime.v1", "source contract schema")
	_check_work_auto(data)
	_check_work_dispatch(data)
	_check_work_idle(data)
	_check_plan_switch(data)
	_check_enter_leave(data)
	_check_rotate(data)
	_check_stop_prod(data)
	print("NATIVE_DWARF_WORK_STATES_SELF_TEST checks=", checks, " failures=", failures)
	quit(0 if failures == 0 else 1)


func _check_work_auto(data: Dictionary) -> void:
	for row: Dictionary in data["work_auto"]:
		var state: Dictionary = {
			"current_workplace": 17, "current_worktask": row["task"],
			"current_workitem": 42, "current_workclass": 9,
			"current_digpos": "3 4 0", "current_workpos": "5 6",
			"idletimeout": 0, "current_occupation": "idle"}
		var result: Dictionary = Work.new().work_auto(state)
		check_equal(_calls(result["calls"]), row["expected_calls"],
			"work auto calls " + str(row["task"]))
		check_equal(state["current_occupation"], row["expected_occupation"],
			"work auto occupation " + str(row["task"]))
		check_equal(int(state["idletimeout"]), int(row["expected_idletimeout"]),
			"work auto idletimeout " + str(row["task"]))


func _check_work_dispatch(data: Dictionary) -> void:
	for row: Dictionary in data["work_dispatch"]:
		var worklist: Array = (row["worklist"] as Array).duplicate()
		var state: Dictionary = {
			"prod_failurecount": row["failure_count"], "current_workplace": 17,
			"current_worktask": "work", "current_workitem": 42, "current_workclass": 9,
			"current_digpos": "3 4 0", "idletimeout": 0, "current_occupation": "idle",
			"current_worklist": worklist, "current_plan": row["plan"]}
		var result: Dictionary = Work.new().work_dispatch(state, _execute)
		check_equal(_calls(result["calls"]), row["expected_calls"],
			"work dispatch calls " + str(row["name"]))
		check_equal(_worklist_text(state["current_worklist"]), _worklist_text(row["expected_worklist"]),
			"work dispatch worklist " + str(row["name"]))
		check_equal(int(state["current_workplace"]), int(row["expected_workplace"]),
			"work dispatch workplace " + str(row["name"]))
		check_equal(int(state["prod_failurecount"]), int(row["expected_failure_count"]),
			"work dispatch failure count " + str(row["name"]))


func _check_work_idle(data: Dictionary) -> void:
	for row: Dictionary in data["work_idle"]:
		var state: Dictionary = {
			"idletimeout": int(row["idletimeout"]) - 1,
			"current_workplace": 0, "current_plan": row["plan"],
			"current_occupation": "idle", "muetzen_counter": 1,
			"muetzen_counter_start": 100, "current_muetze_name": "fight",
			"muetze_name": "fight", "work_strike": int(row["work_strike"]),
			"sparetime_is_on": int(row["sparetime_is_on"]),
			"remaining_spare": float(row["remaining_spare"]),
			"act_when_idle": false, "prod_autoschedule": false,
			"walk_down_from_wall": false, "rand_value": 0.5,
			"gnome_position": int(row["gnome_position"])}
		var result: Dictionary = Work.new().work_idle(state)
		check_equal(_calls(result["calls"]), row["expected_calls"],
			"work idle calls " + str(row["name"]))
		check_equal(state["current_occupation"], row["expected_occupation"],
			"work idle occupation " + str(row["name"]))
		check_equal(int(state["idletimeout"]), int(row["expected_idletimeout"]),
			"work idle timeout " + str(row["name"]))


func _check_plan_switch(data: Dictionary) -> void:
	for row: Dictionary in data["work_plan_switch"]:
		var state: Dictionary = {"current_plan": row["plan"]}
		var machine: RefCounted = Work.new()
		var result: Dictionary = {}
		if str(row["proc"]) == "state_work_active_proc":
			result = machine.work_active(state)
		else:
			result = machine.work_breakable(state)
		check_equal(_calls(result["calls"]), row["expected_calls"],
			"plan switch " + str(row["proc"]) + " " + str(row["plan"]))


func _check_enter_leave(data: Dictionary) -> void:
	for row: Dictionary in data["work_enter_leave"]:
		var state: Dictionary = {
			"current_worktask": "work", "current_workplace": 17,
			"current_workclass": 9, "last_event": "evt", "event_repeat": 1}
		var machine: RefCounted = Work.new()
		var result: Dictionary = {}
		if str(row["proc"]) == "state_enter_work_idle_proc":
			result = machine.enter_work_idle(state)
		else:
			result = machine.leave_work_idle(state)
		check_equal(_calls(result["calls"]), row["expected_calls"],
			"work idle " + str(row["proc"]))
		if row.has("expected_worktask"):
			check_equal(state["current_worktask"], row["expected_worktask"],
				"work idle task reset")
			check_equal(int(state["current_workclass"]), int(row["expected_workclass"]),
				"work idle class reset")
			check_equal(state["last_event"], row["expected_last_event"],
				"work idle last event reset")
			check_equal(int(state["event_repeat"]), int(row["expected_event_repeat"]),
				"work idle event repeat reset")


func _check_rotate(data: Dictionary) -> void:
	for row: Dictionary in data["rotate"]:
		var result: Dictionary = Work.new().rotate_toangle(float(row["angle"]), str(row["anim"]))
		check_equal(str(result["result"]), str(row["expected_result"]),
			"rotate result " + str(row["angle"]))
		check_equal(_calls(result["calls"]), row["expected_calls"],
			"rotate calls " + str(row["angle"]))


func _check_stop_prod(data: Dictionary) -> void:
	for row: Dictionary in data["stop_prod"]:
		var state: Dictionary = {
			"current_workplace": 0, "current_worklist": "", "walkfail_tasks": "x",
			"last_disturb": 0.0, "myref": 7, "event_repeat": 1,
			"current_occupation": "eat", "current_state": row["state"],
			"now": 1000.0, "inventory": [], "item_types": {},
			"workplace_tasklist": []}
		var result: Dictionary = Work.new().stop_prod(state, int(row["toolchange"]) != 0)
		check_equal(_calls(result["calls"]), row["expected_calls"],
			"stop prod calls " + str(row["state"]))
		check_equal(int(state["event_repeat"]), 0, "stop prod event repeat reset")
		check_equal(_worklist_text(state["current_worklist"]), "",
			"stop prod work list reset")


# --------------------------------------------------------------------------- #
# helpers
# --------------------------------------------------------------------------- #
## The oracle scenarios only run `set ok 1` and `set ok 0`.
func _execute(command: String) -> Variant:
	var parts: PackedStringArray = command.strip_edges().split(" ", false)
	if parts.size() >= 3 and parts[0] == "set":
		return parts[2]
	return null


func _calls(calls: Array) -> Array:
	var result: Array = []
	for call: Array in calls:
		var row: Array = []
		for item: Variant in call:
			row.append(str(item))
		result.append(row)
	return result


## The oracle keeps an empty work list as an empty string and a used one as a
## Tcl list, the port keeps a plain array.
func _worklist_text(worklist: Variant) -> String:
	if worklist is Array:
		var items: Array = []
		for item: Variant in worklist:
			items.append(str(item))
		return " ".join(items)
	return str(worklist)
