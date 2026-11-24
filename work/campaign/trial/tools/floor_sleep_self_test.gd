extends SceneTree
const Policy: Script = preload("res://scripts/native_floor_sleep.gd")
var checks: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func check(condition: bool, label: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		printerr("FAIL ", label)


func _run() -> void:
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_floor_sleep.json"))
	for example: Dictionary in data["decision_oracle"]:
		var goal: Dictionary = Policy.fresh_goal(example["needs"], example["ill_check"])
		check(not goal.is_empty() == (example["wish"] == "slp"), "original Tcl sleep decision")
		if not goal.is_empty():
			check(is_equal_approx(goal["target"], example["target"]), "original Tcl sleep target")
			check((goal["minimum"] >= 0) == not str(example["minimum"]).is_empty(), "original Tcl minimum-goal gate")
	check(not Policy.reached({"base":0.2,"target":0.6},0.6), "strict source goal comparison")
	check(Policy.reached({"base":0.2,"target":0.6},0.6001), "goal passes above threshold")
	check(not Policy.reached({"base":0.2,"target":0.6},0.3999,0.5), "half goal multiplies progress RHS")
	check(Policy.fresh_goal({"hitpoints":1.0,"nutrition":0.4,"alertness":0.00001,"mood":0.8}).is_empty(), "unported lexical scientific values explicit")
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.extended_world = false
	subject.autonomous_dwarf_work = false
	root.add_child(subject)
	subject.set_process(false)
	var dwarf: Node3D = subject.dwarf_nodes[0]
	var other: Node3D = subject.dwarf_nodes[1]
	var model: Dictionary = subject.dwarf_life.models[dwarf]
	model["shift_start"] = 6.0
	model["needs"] = {"hitpoints":0.7,"nutrition":0.4,"alertness":0.2,"mood":0.8}
	dwarf.position = Vector3(16,-14.5,14)
	check(subject.dwarf_sleep.safe_floor(dwarf), "actual supported floor fallback")
	for frame: int in range(100):
		subject._process(0.05)
	check(not model["is_sleeping"], "source idle timeout is strict greater than five seconds")
	for frame: int in range(10):
		subject._process(0.05)
		if model["is_sleeping"]:
			break
	check(model["is_sleeping"] and subject.actor_tasks.animating(dwarf), "flag set in laydown compound while async animation blocks queue")
	check(subject._dwarf_sequence_frame_count(dwarf,&"stand_zu_schlafen") == 15, "15 original laydown frames")
	check(subject.dwarf_sleep.gain_cycles == 0, "laydown does not award sleep gain")
	for frame: int in range(50):
		subject._process(0.05)
		if subject.dwarf_sleep.gain_cycles > 0:
			break
	check(subject.dwarf_sleep.gain_cycles == 1, "first source sleep cycle")
	check(subject._dwarf_sequence_frame_count(dwarf,&"schlafen_boden_loop") == 11, "11 original sleep-loop frames")
	check(subject.actor_tasks.runner(dwarf).queue.count() == 1, "cycle queues two source animations, first already dispatched")
	var gained: float = model["needs"]["alertness"]
	subject._process(0.05)
	check(model["needs"]["alertness"] == gained, "gain is per queue cycle, not per frame")
	check(gained > 0.203 and gained < 0.2045, "0.004 times 1.1 gain with separate source decay")
	subject.simulation_paused = true
	var cycles: int = subject.dwarf_sleep.gain_cycles
	subject._process(10.0)
	check(subject.dwarf_sleep.gain_cycles == cycles and model["needs"]["alertness"] == gained, "pause freezes sleep and attribute ticks")
	subject.simulation_paused = false
	model["needs"]["alertness"] = 0.61
	for frame: int in range(80):
		subject._process(0.05)
		if not model["is_sleeping"]:
			break
	check(not model["is_sleeping"] and subject.actor_tasks.animating(dwarf), "goal queues wake and clears sleeping immediately")
	check(subject._dwarf_sequence_frame_count(dwarf,&"schlafen_zu_stand") == 7, "7 original wake frames")
	for frame: int in range(20):
		subject._process(0.05)
	check(not subject.dwarf_sleep.states.has(dwarf), "natural wake releases reservation")
	# A new sleep can be interrupted by a manual walk. Wake must precede it.
	model["needs"]["alertness"] = 0.2
	subject.dwarf_sleep.begin(dwarf, Policy.fresh_goal(model["needs"]))
	subject._process(0.05)
	check(model["is_sleeping"], "second floor sleep starts")
	var stale_token: int = subject.actor_tasks.runner(dwarf).token
	subject.actor_tasks.walk(dwarf, Vector3(18,-14.5,14))
	check(not model["is_sleeping"] and not subject.dwarf_sleep.states.has(dwarf), "manual command clears flag and reservation")
	check(subject.actor_tasks.runner(dwarf).queue.count() == 2, "wake is queued before manual walk")
	check(not subject.actor_tasks.runner(dwarf).complete(stale_token), "old sleep callback cannot finish replacement")
	subject.actor_tasks.walk(dwarf, Vector3(18,-14.5,14))
	check(subject.actor_tasks.runner(dwarf).queue.count() == 2, "rapid replacement preserves pending wake before command")
	var before: Vector3 = dwarf.position
	subject._process(0.05)
	check(subject.actor_tasks.animating(dwarf) and dwarf.position == before, "manual walk waits for source wake clip")
	subject.actor_tasks.walk(dwarf, Vector3(18,-14.5,14))
	check(subject.actor_tasks.runner(dwarf).queue.count() == 2, "replacement during wake retains wake action")
	for frame: int in range(200):
		subject._process(0.05)
		if dwarf.position.distance_to(Vector3(18,-14.5,14)) < 0.02:
			break
	check(dwarf.position.distance_to(Vector3(18,-14.5,14)) < 0.02, "manual walk completes after waking")
	check(not subject.dwarf_sleep.pending_wakes.has(dwarf), "finished wake releases replacement guard")
	check(not subject.dwarf_life.models[other]["is_sleeping"], "independent actor unchanged")
	# Work begins while asleep: queued loop drains before source wake.
	model["needs"]["alertness"] = 0.2
	subject.dwarf_sleep.begin(dwarf, Policy.fresh_goal(model["needs"]))
	subject._process(0.05)
	model["shift_start"] = 0.0
	for frame: int in range(90):
		subject._process(0.05)
		if not subject.dwarf_sleep.states.has(dwarf):
			break
	check(not model["is_sleeping"] and not subject.dwarf_sleep.states.has(dwarf), "shift start wakes after current queue")
	subject.queue_free()
	await process_frame
	print("FLOOR_SLEEP_SELF_TEST checks=",checks," failures=",failures)
	quit(0 if failures == 0 else 1)
