extends SceneTree
## Host adapter for the sparetime contract: the adapter has to publish the
## decision of the original `sparetime_decide_occup` to the running scene and
## has to hand the work state machine a usable state.

var checks: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


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


func _run() -> void:
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	subject.set_process(false)
	var runtime: RefCounted = subject.dwarf_sparetime
	check(runtime != null, "the sparetime runtime is part of the scene")
	check(runtime.models.size() == subject.dwarf_nodes.size(),
		"one leisure state per dwarf")
	check(runtime.places != null and runtime.work != null,
		"the place registry and the work states are reachable")
	var first: Node3D = subject.dwarf_nodes[0]
	var life: Dictionary = subject.dwarf_life.models[first]
	# The dwarf has the leisure phase with six hours of spare time left.
	life["time_plan"] = "sparetime"
	life["occupation"] = "idle"
	life["is_sleeping"] = false
	life["shift_start"] = 6.0
	life["shift_duration"] = 2.0
	runtime.update()
	var decision: Dictionary = runtime.decision(first)
	check(not decision.is_empty(), "the leisure decision was made")
	var wish: String = str(decision.get("current_wish_occupation", ""))
	check(["eat", "fun", "slp", "bth"].has(wish), "the wish is a source occupation")
	check_equal(str(life.get("sparetime_wish", "")), wish,
		"the wish is published to the host model")
	check_equal(str(first.get_meta("current_wish_occupation", "")), wish,
		"the wish is published to the actor")
	var plan: Array = life.get("sparetime_future", [])
	check(not plan.is_empty(), "the leisure plan is planned")
	check(plan.has("eat"), "the plan starts with the meal")
	check(not plan.has("bth"), "the plan drops the bath below the desire limit")
	# A working dwarf does not get a leisure decision.
	var second: Node3D = subject.dwarf_nodes[1]
	var second_life: Dictionary = subject.dwarf_life.models[second]
	second_life["time_plan"] = "work"
	runtime.decisions.erase(second)
	runtime.update()
	check(runtime.decision(second).is_empty(), "a working dwarf has no leisure decision")
	# The work state machine gets a usable state from the host.
	life["idletimeout"] = 5
	var work_state: Dictionary = runtime.work_state(first)
	check(work_state.has("current_worklist") and work_state.has("prod_failurecount"),
		"the work state carries the source fields")
	check_equal(work_state["current_plan"], "sparetime", "the work state knows the plan")
	check(float(work_state["remaining_spare"]) > 0.0, "the work state knows the spare time")
	var idle: Dictionary = runtime.work.work_idle(work_state)
	var calls: Array = idle["calls"]
	check(calls.has(["state_triggerfresh", "sparetime_dispatch"]),
		"an idle dwarf with spare time hands over to the sparetime dispatcher")
	print("DWARF_SPARETIME_RUNTIME_SELF_TEST checks=", checks, " failures=", failures)
	quit(0 if failures == 0 else 1)
