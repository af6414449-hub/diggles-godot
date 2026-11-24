extends SceneTree

const SOURCE_ACTION: Script = preload("res://scripts/source_animation_action.gd")
var failures: int = 0
var assertions: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var packed: PackedScene = load("res://scenes/multiplayer_test.tscn")
	var subject: Node3D = packed.instantiate()
	subject.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	await process_frame
	if subject.get_script() == null:
		push_error("NATIVE_DWARF_DIG_SELF_TEST_FAILED controller did not load")
		quit(1)
		return
	subject.set_process(false)
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var capture: int = args.find("--work-capture-dir")
	var capture_dir: String = args[capture + 1] if capture >= 0 and capture + 1 < args.size() else ""
	await physics_frame
	await physics_frame
	_test_action_clock()
	var point: Vector2i = Vector2i(2, 15)
	var dwarf: Node3D = subject.dwarf_nodes[0]
	# This regression measures the ordinary strike callback. The novice accident
	# prelude has its own integration test and does not execute dig_apply.
	dwarf.set_meta("exp_Stein",0.2)
	_expect(subject.native_mark_corridor_cell(0, point), "floor work fixture rejected")
	subject.call("_process", 10.0)
	_expect(subject.terrain_state.revision == 0, "workerless mark changed terrain")
	_expect(subject._dwarf_dig_clip(Vector3(3, -14.5, 12), point) == &"buddeln_unten", "down/front sign reversed")
	_expect(subject._dwarf_dig_reachable(Vector3(3, -14.5, 12), point), "source dig_check fixture rejected")
	_expect(not subject._dwarf_dig_reachable(Vector3(3, -14.5, 12), Vector2i(1, 16)), "strict source XY reach ignored")
	_expect(subject.native_mark_corridor_cell(0, Vector2i(9, 3)), "high work fixture rejected")
	_expect(not subject.assign_dwarf_dig(dwarf, Vector2i(9, 3)), "remote high mark assigned to floor worker")
	subject._select_dwarf(dwarf)
	var screen: Vector2 = subject.camera.unproject_position(subject.scene_root.to_global(Vector3(point.x, -point.y, subject.DIG_MARK_DEPTH)))
	subject._handle_tap(screen)
	_expect(subject.actor_tasks.runner(dwarf).queue.count() == 1, "tap did not enqueue source command")
	# Input now queues a task; the next enabled state dispatch starts the job.
	subject.actor_tasks.dispatch()
	_expect(subject.dwarf_dig_jobs.has(dwarf), "tap on marked point did not assign job")
	if not subject.dwarf_dig_jobs.has(dwarf):
		_finish(subject)
		return
	var stance: Vector3 = subject.dwarf_dig_jobs[dwarf]["stance"]
	_expect(subject._has_source_floor(Vector2(stance.x, stance.z)), "stance has no actual source floor")
	_expect(subject._navigation_body_clear(Vector2(stance.x, stance.z)), "stance intersects source wall")
	# Arrival is walked, never teleported; approach cannot apply a strike.
	for frame: int in range(400):
		if subject.dwarf_dig_jobs[dwarf]["phase"] == "work":
			break
		subject.call("_process", 0.05)
		_expect(subject.terrain_state.revision == 0, "approach changed terrain")
	_expect(subject.dwarf_dig_jobs[dwarf]["phase"] == "work", "worker did not reach stance")
	_expect(dwarf.position.distance_to(stance) < 0.01, "work started before stance reached")
	var job: Dictionary = subject.dwarf_dig_jobs[dwarf]
	var action: RefCounted = job["action"]
	# The source sound event at frame 5 cannot be used as a terrain callback.
	subject.call("_process", maxf(0.0, 5.0 / 12.0 - action.elapsed))
	_expect(subject.terrain_state.revision == 0, "sound-frame strike fired before completion")
	if not capture_dir.is_empty():
		await _capture_work_frame(subject, capture_dir, "worker_before_strike.png")
	subject.call("_process", 0.2)
	_expect(subject.terrain_state.revision == 0, "unfinished body clip changed terrain")
	# Cancel during an action, keep the mark and block refs, restart at stance.
	subject._cancel_dwarf_dig(dwarf)
	subject.call("_process", 3.0)
	_expect(subject.terrain_state.revision == 0, "cancelled action mutated terrain")
	_expect(subject.assign_dwarf_dig(dwarf, point), "cancelled mark cannot be reassigned")
	_expect(subject.dwarf_dig_jobs[dwarf]["phase"] == "work", "worker at stance did not resume")
	var nav_before: AStarGrid2D = subject.navigation_grid
	var mesh_before: Dictionary = _mesh_ids(subject)
	var objects_before: Array[Node3D] = subject.dwarf_nodes.duplicate()
	subject.call("_process", 1.0)
	_expect(subject.terrain_state.revision == 0, "last visible frame completed too early")
	subject.call("_process", 1.0 / 12.0 + 0.0001)
	_expect(subject.terrain_state.revision == 1, "animation completion did not mutate BlockDB")
	_expect(subject.dig_action_completions == 1, "callback count is not exactly one")
	_expect(not subject.dwarf_dig_jobs.has(dwarf), "completed corridor left stale worker job")
	_expect(not subject.native_mark_nibbles.has(subject._native_cell_key(point, 0, 0)), "completed point mark survived")
	_expect(subject.terrain_state.current_height(point) == 11, "physical source height is not 11")
	_expect(subject.navigation_grid != nav_before, "navigation not rebuilt after mutation")
	_expect(_mesh_ids(subject) != mesh_before, "source mesh not replaced")
	_expect(subject.dwarf_nodes == objects_before, "terrain rebuild replaced actors")
	var fact: Dictionary = subject.tunnel_rules.data["cells"][point.y * 44 + point.x]
	_expect(int(fact["block"]) == int(subject.native_terrain_cells[point]["block"]), "mark validator has stale block refs")
	if not capture_dir.is_empty():
		await _capture_work_frame(subject, capture_dir, "worker_after_strike.png")
	subject.call("_process", 10.0)
	_expect(subject.terrain_state.revision == 1 and subject.dig_action_completions == 1, "completed clip fired callback again")
	# Independent source fixture A, including the real physics surface.
	await physics_frame
	await physics_frame
	var ray_point: Vector2 = Vector2(9.01, 3.01)
	var hit_before: Dictionary = _terrain_ray(subject, ray_point)
	_expect(not hit_before.is_empty(), "initial terrain has no physics hit")
	_expect(subject.native_dig_apply_cell(0, Vector2i(9, 3)), "fixture A strike rejected")
	await physics_frame
	await physics_frame
	var hit_after: Dictionary = _terrain_ray(subject, ray_point)
	_expect(not hit_after.is_empty(), "rebuilt terrain has no physics hit")
	if not hit_before.is_empty() and not hit_after.is_empty():
		var before: Vector3 = subject.scene_root.to_local(hit_before["position"])
		var after: Vector3 = subject.scene_root.to_local(hit_after["position"])
		print("NATIVE_TERRAIN_PHYSICS before=%s after=%s" % [before, after])
		_expect(after.z < before.z - 0.1, "collision still closes excavated surface")
	var expected_refs: Array[int] = [22, 32, 44, 54]
	var offsets: Array[Vector2i] = [Vector2i(-1, -1), Vector2i(0, -1), Vector2i(-1, 0), Vector2i.ZERO]
	for index: int in range(4):
		_expect(subject.terrain_state.block_ref(Vector2i(9, 3) + offsets[index]) == expected_refs[index], "fixture A source refs disagree")
	_expect(not subject.native_mark_corridor_cell(0, Vector2i(9, 3)), "validator reused pre-strike Hnext")
	if failures == 0:
		print("NATIVE_DWARF_DIG_SELF_TEST_OK assertions=%d callbacks=1 worker_strikes=1 fixture_strikes=1" % assertions)
	if failures == 0 and not capture_dir.is_empty():
		subject.distance = 36.0
		await subject._capture_views(capture_dir)
		return
	_finish(subject)


func _test_action_clock() -> void:
	var first: RefCounted = SOURCE_ACTION.new()
	var second: RefCounted = SOURCE_ACTION.new()
	first.begin(13, 12.0)
	second.begin(13, 12.0)
	_expect(not bool(first.advance(1.0)["complete"]), "finite clip completed before its 13th duration")
	_expect(second.elapsed == 0.0 and second.active, "actor action clocks share state")
	_expect(bool(first.advance(0.084)["complete"]), "finite clip missed completion")
	_expect(not bool(first.advance(10.0)["complete"]), "finite clip completed twice")
	_expect(second.active, "one actor completion stopped the other")


func _terrain_ray(subject: Node3D, point: Vector2) -> Dictionary:
	var from: Vector3 = subject.scene_root.to_global(Vector3(point.x, -point.y, 20.0))
	var to: Vector3 = subject.scene_root.to_global(Vector3(point.x, -point.y, 0.0))
	return subject.get_world_3d().direct_space_state.intersect_ray(PhysicsRayQueryParameters3D.create(from, to, 1))


func _mesh_ids(subject: Node3D) -> Dictionary:
	var result: Dictionary = {}
	for key: String in subject.terrain_mesh_nodes:
		result[key] = subject.terrain_mesh_nodes[key].get_instance_id()
	return result


func _capture_work_frame(subject: Node3D, directory: String, filename: String) -> void:
	DirAccess.make_dir_recursive_absolute(directory)
	var old_focus: Vector3 = subject.focus
	var old_distance: float = subject.distance
	subject.focus = Vector3(4.0, -14.2, 12.0)
	subject.distance = 12.0
	subject._update_camera()
	await process_frame
	await RenderingServer.frame_post_draw
	var result: Error = root.get_texture().get_image().save_png(directory.path_join(filename))
	_expect(result == OK, "worker action screenshot failed")
	subject.focus = old_focus
	subject.distance = old_distance
	subject._update_camera()


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("NATIVE_DWARF_DIG_SELF_TEST_FAILED " + message)


func _finish(subject: Node3D) -> void:
	subject.queue_free()
	quit(0 if failures == 0 else 1)
