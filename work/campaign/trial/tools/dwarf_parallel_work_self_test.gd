extends SceneTree

var failures: int = 0
var assertions: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var scene: PackedScene = load("res://scenes/multiplayer_test.tscn")
	var subject: Node3D = scene.instantiate()
	subject.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	await process_frame
	if subject.get_script() == null:
		push_error("DWARF_PARALLEL_WORK_SELF_TEST_FAILED controller missing")
		quit(1)
		return
	subject.set_process(false)
	var first: Node3D = subject.dwarf_nodes[0]
	var second: Node3D = subject.dwarf_nodes[1]
	var third: Node3D = subject.dwarf_nodes[2]
	subject._start_dwarf_walk(first, Vector3(5, -14.5, 14))
	var original: RefCounted = subject.dwarf_walk_actions[first]
	subject._start_dwarf_walk(second, Vector3(14, -14.5, 14))
	_expect(subject.dwarf_walk_actions.size() == 2, "second command cancelled first walk")
	_expect(subject.dwarf_walk_actions[first] == original, "first route state replaced")
	var first_start: Vector3 = first.position
	var second_start: Vector3 = second.position
	for step: int in range(20):
		subject.call("_process", 0.1)
	_expect(first.position.distance_to(first_start) > 0.2, "first actor did not progress concurrently")
	_expect(second.position.distance_to(second_start) > 0.2, "second actor did not progress concurrently")
	var first_elapsed: float = original.elapsed
	var first_index: int = original.path_index
	subject._start_dwarf_walk(second, Vector3(15, -14.5, 14))
	_expect(original.elapsed == first_elapsed and original.path_index == first_index, "retargeting another actor reset first animation/path")
	subject._stop_dwarf_walk(second)
	_expect(subject.dwarf_walk_actions.has(first), "stopping second stopped first")
	for step: int in range(200):
		subject.call("_process", 0.1)
		if not subject.dwarf_walk_actions.has(first):
			break
	_expect(first.position.distance_to(Vector3(5, -14.5, 14)) < 0.001, "first actor never arrived")
	# Two simultaneous real jobs from the original scene, plus a third walk.
	_expect(subject.native_mark_corridor_cell(0, Vector2i(1, 15)), "first source mark rejected")
	_expect(subject.native_mark_corridor_cell(0, Vector2i(2, 15)), "second source mark rejected")
	_expect(subject.assign_dwarf_dig(first, Vector2i(1, 15)), "first work assignment failed")
	_expect(subject.assign_dwarf_dig(second, Vector2i(2, 15)), "second work assignment failed")
	_expect(subject.dwarf_dig_jobs.size() == 2, "second job cancelled first")
	subject._start_dwarf_walk(third, Vector3(16, -14.5, 14))
	_expect(subject.dwarf_dig_jobs.size() == 2 and subject.dwarf_walk_actions.size() == 3, "third command displaced a working actor")
	var first_done: bool = false
	for step: int in range(600):
		subject.call("_process", 0.05)
		if subject.terrain_state.revision > 0 and not first_done:
			first_done = true
			_expect(subject.dwarf_dig_jobs.has(second), "first completion erased second worker job")
		if subject.dwarf_dig_jobs.is_empty() and subject.dwarf_walk_actions.is_empty():
			break
	_expect(subject.dig_action_completions == 2, "workers did not each complete exactly one action")
	_expect(subject.terrain_state.revision == 2, "workers did not each mutate actual terrain")
	_expect(subject.native_mark_nibbles.is_empty(), "completed workers left source marks")
	_expect(subject.dwarf_walk_actions.is_empty(), "finished routes leaked")
	_expect(third.position.distance_to(Vector3(16, -14.5, 14)) < 0.001, "unrelated third walk interrupted")
	# A changed floor must stop only the affected path before stepping into it.
	subject._start_dwarf_walk(third, Vector3(14, -14.5, 14))
	var blocked_walk: RefCounted = subject.dwarf_walk_actions[third]
	var blocked: Vector3 = blocked_walk.path[blocked_walk.path_index]
	subject.navigation_grid.set_point_solid(subject._local_to_navigation_id(blocked), true)
	var position_before: Vector3 = third.position
	for step: int in range(20):
		subject.call("_process", 0.1)
		if not subject.dwarf_walk_actions.has(third):
			break
	_expect(not subject.dwarf_walk_actions.has(third), "invalidated route stayed active")
	_expect(third.position == position_before, "actor stepped onto invalidated floor")
	if failures == 0:
		print("DWARF_PARALLEL_WORK_SELF_TEST_OK assertions=%d workers=2 independent_walkers=3 mutations=2" % assertions)
	subject.queue_free()
	quit(0 if failures == 0 else 1)


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("DWARF_PARALLEL_WORK_SELF_TEST_FAILED " + message)
