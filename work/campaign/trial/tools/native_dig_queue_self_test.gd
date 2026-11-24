extends SceneTree

const DIG_NEXT: Script = preload("res://scripts/native_dig_next.gd")
var assertions: int = 0
var failures: int = 0


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
		push_error("NATIVE_DIG_QUEUE_SELF_TEST_FAILED controller missing")
		quit(1)
		return
	subject.set_process(false)
	var worker: Node3D = subject.dwarf_nodes[0]
	subject._select_dwarf(worker)
	# Three previous empty mode1 commits; this stroke's group must be 3, not 0.
	for commit: int in range(3):
		subject.native_dig_groups.finish_commit(0)
	var points: Array[Vector2i] = [Vector2i(1, 15), Vector2i(2, 15), Vector2i(2, 16)]
	if OS.get_cmdline_user_args().has("--full-stroke"):
		points.append(Vector2i(1, 16))
	var expected_count: int = points.size()
	# A region click now chooses its closest reachable edge instead of forcing
	# the clicked point. Subsequent entries remain native dig_next rank 0.
	var expected_order: Array[Vector2i] = [Vector2i(2,15),Vector2i(1,15),Vector2i(2,16)]
	if expected_count == 4:
		expected_order.append(Vector2i(1,16))
	for point: Vector2i in points:
		_expect(subject.native_mark_corridor_cell(0, point), "source corridor fixture rejected: %s" % point)
	var original_facts: Dictionary = subject.terrain_state.facts.duplicate(true)
	var preview: Dictionary = subject.terrain_state.preview_accepted_step(points[0], 0, 3, true)
	_expect(bool(preview["accepted"]), "preview fixture rejected")
	_expect(subject.terrain_state.facts == original_facts and subject.terrain_state.revision == 0, "planning preview mutated live terrain/validator")
	_expect(subject._has_source_floor(Vector2(2.0, 12.0)), "unsafe stance fixture lacks its initial floor")
	_expect(not subject._has_source_floor(Vector2(2.0, 12.0), subject._future_floor_for_dig(Vector2i(2, 15))), "planner retained floor removed by the next source blocks")
	_expect(subject.assign_dwarf_dig(worker, points[0]), "initial explicit assignment failed")
	for step: int in range(1200):
		subject.call("_process", 0.05)
		if not subject.dwarf_dig_jobs.has(worker):
			break
	_expect(subject.terrain_state.revision == expected_count, "single assignment did not complete all source mutations")
	_expect(subject.dig_action_completions == expected_count, "queue callback count differs")
	_expect(subject.native_mark_nibbles.is_empty(), "completed queue left marks")
	_expect(subject.dig_selection_history.size() == expected_count, "queue selected an extra or missing point")
	for index: int in range(mini(expected_count, subject.dig_selection_history.size())):
		var selection: Dictionary = subject.dig_selection_history[index]
		_expect(selection["point"] == expected_order[index], "native next order differs from source fixture")
		_expect(int(selection["rank"]) == (-1 if index == 0 else 0), "native retry rank differs")
		if index > 0:
			_expect(selection["digpoint"].z == 13.0, "queue lost native clamp-then-minus-one depth")
			_expect(int(selection["group"]) == 3, "accepted step did not propagate runtime worker group")
	_expect(subject._has_source_floor(Vector2(worker.position.x, worker.position.z)), "queue left worker standing over removed floor")
	_expect(subject.dwarf_walk_actions.is_empty() and subject.dwarf_dig_jobs.is_empty(), "finished task leaked an action")
	for point: Vector2i in points:
		_expect(subject.native_dig_groups.word(point) == 3, "clearing completed marks erased their group stamp")
	# Missing source state stops the queue without consuming that mark or terrain.
	var unknown: Vector2i = Vector2i(2, 2)
	subject.native_mark_nibbles[subject._native_cell_key(unknown, 0, 0)] = 3
	var native_position: Vector3 = subject.native_world.to_source(Vector3(worker.position.x, -worker.position.y, worker.position.z))
	var snapshot: Dictionary = subject._native_dig_snapshot(native_position)
	var unknown_result: Dictionary = DIG_NEXT.select_next(native_position, subject.native_world.bounds, 0, 0, snapshot)
	_expect(unknown_result["status"] == "unknown", "incomplete snapshot was treated as known empty/solid")
	subject._continue_dwarf_dig(worker)
	_expect(subject.terrain_state.revision == expected_count, "unknown snapshot changed terrain")
	_expect(subject.native_mark_nibbles.has(subject._native_cell_key(unknown, 0, 0)), "unknown snapshot silently erased a mark")
	_expect(subject.dwarf_dig_jobs.is_empty(), "unknown snapshot scheduled invented work")
	subject.native_mark_nibbles.clear()
	subject._continue_dwarf_dig(worker)
	print("NATIVE_DIG_QUEUE_RESULT selections=%s revisions=%d worker=%s" % [subject.dig_selection_history, subject.terrain_state.revision, worker.position])
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var capture: int = args.find("--queue-capture-dir")
	if failures == 0 and capture >= 0 and capture + 1 < args.size():
		print("NATIVE_DIG_QUEUE_SELF_TEST_OK assertions=%d assignments=1 callbacks=%d mutations=%d" % [assertions, expected_count, expected_count])
		var directory: String = args[capture + 1]
		DirAccess.make_dir_recursive_absolute(directory)
		var old_focus: Vector3 = subject.focus
		subject.focus = Vector3(3.5, -15.0, 12.0)
		subject.distance = 12.0
		subject._update_camera()
		await process_frame
		await RenderingServer.frame_post_draw
		var saved: Error = root.get_texture().get_image().save_png(directory.path_join("queue_complete.png"))
		if saved != OK:
			push_error("NATIVE_DIG_QUEUE_SELF_TEST_FAILED screenshot could not be saved")
			quit(1)
			return
		subject.focus = old_focus
		subject.distance = 36.0
		await subject._capture_views(directory)
		return
	if failures == 0:
		print("NATIVE_DIG_QUEUE_SELF_TEST_OK assertions=%d assignments=1 callbacks=%d mutations=%d" % [assertions, expected_count, expected_count])
	subject.queue_free()
	quit(0 if failures == 0 else 1)


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("NATIVE_DIG_QUEUE_SELF_TEST_FAILED " + message)
