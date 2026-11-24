extends SceneTree

const POSE: Script = preload("res://scripts/native_walk_pose.gd")
const SURFACE: Script = preload("res://scripts/surface_walk_action.gd")
var assertions: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	_test_source_pose()
	var scene: PackedScene = load("res://scenes/multiplayer_test.tscn")
	var subject: Node3D = scene.instantiate()
	subject.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	await process_frame
	if subject.get_script() == null:
		push_error("NATIVE_SURFACE_WALK_SELF_TEST_FAILED controller missing")
		quit(1)
		return
	subject.set_process(false)
	var proof_path: String = ProjectSettings.globalize_path("res://").path_join("../docs/reverse-engineering/native-surface-walk-2026-11-17.json")
	var proof: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(proof_path))
	for fixture: Dictionary in proof["source_height_fixtures"]:
		var sample: Array = fixture["sample"]
		_expect(POSE.wall_depth(Vector2i(int(sample[0]), int(sample[1])), subject._native_height_sample) == float(fixture["wall_depth"]), "current BDB source wall-depth fixture differs")
	var worker: Node3D = subject.dwarf_nodes[0]
	var other: Node3D = subject.dwarf_nodes[1]
	var initial: Vector3 = worker.position
	var original_facts: Dictionary = subject.terrain_state.facts.duplicate(true)
	var goal: Vector2i = Vector2i(192, 84)
	_expect(int(subject.native_walkmap.sample(goal)) == 3, "upper platform source fixture lost floor bits")
	var blocked: Dictionary = SURFACE.plan(Vector2i(64, 116), goal, subject.native_walkmap, subject._native_height_sample, false)
	_expect(blocked["status"] == "no_supported_route", "canclimb=0 permitted a wall route")
	_expect(subject.assign_dwarf_surface_walk(worker, goal), "lower floor to upper platform route failed")
	_expect(worker.position == initial, "assignment teleported actor")
	var walk: RefCounted = subject.dwarf_walk_actions[worker]
	_expect(walk.modes.has(0) and walk.modes.has(2), "route did not contain source wall and floor modes")
	var wall_position: Vector3 = initial
	var wall_seen: bool = false
	var largest_step: float = 0.0
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var capture_index: int = args.find("--surface-capture-dir")
	var capture_dir: String = args[capture_index + 1] if capture_index >= 0 and capture_index + 1 < args.size() else ""
	for step: int in range(5000):
		var before: Vector3 = worker.position
		subject.call("_process", 0.05)
		largest_step = maxf(largest_step, before.distance_to(worker.position))
		if int(subject.dwarf_surface_modes.get(worker, 2)) == 0 and absf(worker.position.y - initial.y) > 1.0 and not wall_seen:
			wall_seen = true
			wall_position = worker.position
			var active: RefCounted = subject.dwarf_walk_actions[worker]
			_expect(not subject.assign_dwarf_surface_walk(worker, goal, false), "wall actor ignored canclimb=0")
			_expect(subject.dwarf_walk_actions.get(worker) == active, "rejected replacement destroyed active route")
			_expect(not subject.assign_dwarf_dig(worker, Vector2i(1, 15)), "unmarked wall command started digging")
			if not capture_dir.is_empty():
				await _capture(subject, capture_dir, "wall_up.png", worker.position)
		if not subject.dwarf_walk_actions.has(worker):
			break
	_expect(wall_seen, "actor never climbed above lower floor")
	_expect(largest_step <= subject.WALK_SPEED * 0.05 + 0.0001, "surface walk contains a position jump")
	_expect(int(subject.surface_walk_results.get(worker, -1)) == 4, "upper platform action did not return target reached")
	_expect(worker.position.y == -10.5 and worker.position.x == 24.0, "actor did not finish on actual upper platform")
	_expect(int(subject.dwarf_surface_modes.get(worker, -1)) == 2, "actor retained wall pose on platform")
	var clips: Array[String] = []
	for entry: Dictionary in subject.surface_walk_history:
		if entry.get("event") == "clip":
			clips.append(str(entry["clip"]))
	_expect(clips.has("stand_zu_kletterstand") and clips.has("kletter_hoch_loop") and clips.has("kletterstand_zu_stand"), "source ground/wall transition clips were skipped")
	_expect(subject.terrain_state.facts == original_facts and subject.terrain_state.revision == 0, "walking mutated source terrain")
	_expect(subject.native_mark_nibbles.is_empty(), "walking created excavation marks")
	if not capture_dir.is_empty():
		await _capture(subject, capture_dir, "upper_platform.png", worker.position)
	_expect(subject.assign_dwarf_surface_walk(worker, Vector2i(64, 116)), "return route could not be assigned")
	for step: int in range(5000):
		subject.call("_process", 0.05)
		if not subject.dwarf_walk_actions.has(worker):
			break
	_expect(int(subject.surface_walk_results[worker]) == 4 and worker.position.y == -14.5 and worker.position.x == 8.0, "return route did not reach lower floor")
	var downward: bool = false
	for entry: Dictionary in subject.surface_walk_history:
		downward = downward or entry.get("clip") == "kletter_runter_loop"
	_expect(downward, "return route did not use original downward climb clip")
	# Two actors have separate actions; an unknown route byte must interrupt only its owner.
	subject._select_dwarf(worker)
	var screen_goal: Vector2 = subject.camera.unproject_position(subject.scene_root.to_global(Vector3(24, -10.5, 14.5)))
	subject._command_selected_dwarf(screen_goal)
	_expect(subject.actor_tasks.runner(worker).queue.count() == 1, "selection click did not enqueue walk")
	subject.actor_tasks.dispatch()
	_expect(subject.dwarf_walk_actions.has(worker) and subject.dwarf_walk_actions[worker] is SURFACE, "normal selection click did not assign an upper-level route")
	if subject.dwarf_walk_actions.has(worker):
		_expect(absf(subject.dwarf_walk_actions[worker].target.x - 24.0) <= 0.5 \
			and subject.dwarf_walk_actions[worker].target.y == -10.5, "screen picking selected the wrong platform")
	subject._start_dwarf_walk(other, Vector3(14, -14.5, 14))
	_expect(subject.dwarf_walk_actions.has(other), "independent floor walker not started")
	var other_action: RefCounted = subject.dwarf_walk_actions[other]
	var other_before: Vector3 = other.position
	var route_action: RefCounted = subject.dwarf_walk_actions[worker]
	var interrupted: Vector2i = route_action.samples[0]
	var byte_index: int = interrupted.y * subject.native_walkmap.sample_bounds.size.x + interrupted.x
	subject.native_walkmap.unknown_samples[byte_index] = 1
	subject.call("_process", 0.05)
	_expect(not subject.dwarf_walk_actions.has(worker) and int(subject.surface_walk_results[worker]) == 3, "unknown navigation byte did not stop its actor")
	_expect(subject.dwarf_walk_actions.get(other) == other_action, "surface interruption replaced another actor's action")
	for step: int in range(40):
		subject.call("_process", 0.05)
	_expect(other.position != other_before, "independent actor stopped after surface route interruption")
	subject.native_walkmap.unknown_samples[byte_index] = 0
	subject._stop_dwarf_walk(other)
	# A wall destination remains a wall idle; replacing/cancelling it must not
	# send the actor through the legacy one-floor planner or reset its pose.
	_expect(subject.assign_dwarf_surface_walk(worker, Vector2i(172, 108)), "explicit wall destination rejected")
	for step: int in range(5000):
		subject.call("_process", 0.05)
		if not subject.dwarf_walk_actions.has(worker):
			break
	_expect(int(subject.surface_walk_results[worker]) == 4 and int(subject.dwarf_surface_modes[worker]) == 0, "wall destination did not finish in wall mode")
	var wall_idle: Node3D = subject.dwarf_locomotion_visuals[worker]["current"]
	_expect(str(wall_idle.name).begins_with("kletterstand_anim"), "wall destination played floor idle")
	var held_position: Vector3 = worker.position
	subject._start_dwarf_walk(worker, Vector3(8, -14.5, 12.5))
	_expect(subject.dwarf_walk_actions[worker] is SURFACE and worker.position == held_position, "floor command bypassed surface route while on wall")
	subject._stop_dwarf_walk(worker)
	subject.call("_process", 0.05)
	_expect(int(subject.surface_walk_results[worker]) == 1 and worker.position == held_position \
		and int(subject.dwarf_surface_modes[worker]) == 0, "cancelled route moved actor or erased wall pose")
	if not capture_dir.is_empty():
		await _capture(subject, capture_dir, "wall_idle.png", worker.position)
	print("NATIVE_SURFACE_WALK_RESULT wall=%s final=%s clips=%s" % [wall_position, worker.position, clips])
	if failures == 0:
		print("NATIVE_SURFACE_WALK_SELF_TEST_OK assertions=%d trips=2 floors=2 wall_idle=ok" % assertions)
	if failures == 0 and not capture_dir.is_empty():
		subject.distance = 36.0
		await subject._capture_views(capture_dir)
		return
	subject.queue_free()
	quit(0 if failures == 0 else 1)


func _test_source_pose() -> void:
	_expect(POSE.mode(1, false, false) == 0, "bit0-only path sample must select wall mode")
	_expect(POSE.mode(3, false, false) == 2, "bit1 path sample must select floor mode")
	_expect(POSE.mode(7, true, true) == 1, "eligible ladder must take precedence over floor bit")
	_expect(POSE.mode(7, false, true) == 2 and POSE.mode(7, true, false) == 2, "ladder must require both permissions and object")
	var heights: Dictionary = {Vector2i(8, 7): 11}
	var query: Callable = func(point: Vector2i) -> Variant: return heights.get(point)
	_expect(POSE.wall_depth(Vector2i(8, 8), query) == 12.0, "wall depth must use previous row plus one")
	heights[Vector2i(8, 7)] = 14
	_expect(POSE.wall_depth(Vector2i(8, 8), query) == 15.0, "height14 incorrectly triggered height15 cross fallback")
	heights[Vector2i(8, 7)] = 15
	_expect(POSE.wall_depth(Vector2i(8, 8), query) == null, "missing cross neighbors were guessed")
	heights.merge({Vector2i(7, 7): 13, Vector2i(9, 7): 10, Vector2i(8, 6): 12, Vector2i(8, 8): 11})
	_expect(POSE.wall_depth(Vector2i(8, 8), query) == 11.0, "height15 fallback did not choose minimum of exact four probes")
	heights[Vector2i(8, 8)] = 7
	_expect(POSE.wall_depth(Vector2i(8, 8), query) == 8.0, "vertical minimum missing from cross fallback")
	_expect(POSE.floor_depth(-1) == 12.5 and POSE.floor_depth(0) == 14.5 and POSE.floor_depth(1) == 14.5, "native intermediate floor lane sign differs")


func _capture(subject: Node3D, directory: String, filename: String, actor_position: Vector3) -> void:
	DirAccess.make_dir_recursive_absolute(directory)
	var previous_focus: Vector3 = subject.focus
	var previous_distance: float = subject.distance
	subject.focus = actor_position
	subject.distance = 8.0
	subject._update_camera()
	await process_frame
	await RenderingServer.frame_post_draw
	var result: Error = root.get_texture().get_image().save_png(directory.path_join(filename))
	_expect(result == OK, "could not capture source locomotion")
	subject.focus = previous_focus
	subject.distance = previous_distance
	subject._update_camera()


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("NATIVE_SURFACE_WALK_SELF_TEST_FAILED " + message)
