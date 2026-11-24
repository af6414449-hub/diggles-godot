extends SceneTree

const EPSILON: float = 0.0001

var failures: int = 0
var assertions: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var scene_arg: int = args.find("--scene")
	var scene_path: String = "res://scenes/terrain_reference.tscn"
	if scene_arg >= 0 and scene_arg + 1 < args.size():
		scene_path = args[scene_arg + 1]
	var packed_scene: PackedScene = load(scene_path)
	var subject: Node3D = packed_scene.instantiate()
	if scene_path == "res://scenes/multiplayer_test.tscn":
		subject.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	if scene_path == "res://scenes/multiplayer_test.tscn":
		subject.extended_world = false
	root.add_child(subject)
	await process_frame
	if subject.get_script() == null:
		push_error("GESTURE_SELF_TEST_FAILED scene controller did not load")
		subject.queue_free()
		quit(1)
		return
	subject.set_process(false)

	_test_three_finger_gesture_is_ignored(subject)
	_test_one_finger_rotation(subject)
	_test_two_finger_pan_lock(subject)
	_test_two_finger_zoom_lock(subject)
	_test_remaining_finger_stays_locked(subject)
	_test_original_locomotion(subject)

	if failures == 0:
		print("INTERACTION_SELF_TEST_OK assertions=%d" % assertions)
	else:
		push_error("GESTURE_SELF_TEST_FAILED failures=%d" % failures)
	subject.queue_free()
	quit(0 if failures == 0 else 1)


func _test_three_finger_gesture_is_ignored(subject: Node3D) -> void:
	_reset_gesture(subject)
	var initial_focus: Vector3 = subject.focus
	var initial_distance: float = subject.distance
	_press(subject, 0, Vector2(100.0, 100.0))
	_press(subject, 1, Vector2(300.0, 100.0))
	_press(subject, 2, Vector2(200.0, 250.0))
	_drag(subject, 0, Vector2(140.0, 125.0), Vector2(40.0, 25.0))
	_drag(subject, 1, Vector2(340.0, 125.0), Vector2(40.0, 25.0))
	_drag(subject, 2, Vector2(240.0, 275.0), Vector2(40.0, 25.0))
	subject.call("_process", 0.0)
	_expect(absf(subject.distance - initial_distance) <= EPSILON, "three-finger gesture changed zoom")
	_expect(subject.focus.distance_to(initial_focus) <= EPSILON, "three-finger gesture moved the camera")
	_release_all(subject)


func _test_one_finger_rotation(subject: Node3D) -> void:
	_reset_gesture(subject)
	var initial_yaw: float = subject.yaw
	var initial_pitch: float = subject.pitch
	_press(subject, 0, Vector2(100.0, 100.0))
	_drag(subject, 0, Vector2(120.0, 110.0), Vector2(20.0, 10.0))
	_expect(absf(subject.yaw - initial_yaw) > EPSILON, "one-finger drag did not rotate yaw")
	_expect(absf(subject.pitch - initial_pitch) > EPSILON, "one-finger drag did not rotate pitch")
	_release_all(subject)


func _test_two_finger_pan_lock(subject: Node3D) -> void:
	_reset_gesture(subject)
	var initial_focus: Vector3 = subject.focus
	var initial_distance: float = subject.distance
	_press(subject, 0, Vector2(100.0, 100.0))
	_press(subject, 1, Vector2(300.0, 100.0))
	_drag(subject, 0, Vector2(140.0, 125.0), Vector2(40.0, 25.0))
	_drag(subject, 1, Vector2(340.0, 125.0), Vector2(40.0, 25.0))
	subject.call("_process", 0.0)
	_expect(subject.focus.distance_to(initial_focus) > EPSILON, "two-finger parallel drag did not pan")
	_expect(absf(subject.distance - initial_distance) <= EPSILON, "pan-locked gesture changed zoom")
	var panned_focus: Vector3 = subject.focus
	_drag(subject, 0, Vector2(120.0, 125.0), Vector2(-20.0, 0.0))
	_drag(subject, 1, Vector2(360.0, 125.0), Vector2(20.0, 0.0))
	subject.call("_process", 0.0)
	_expect(subject.focus.distance_to(panned_focus) <= EPSILON, "pinch noise moved a pan-locked gesture")
	_expect(absf(subject.distance - initial_distance) <= EPSILON, "pan lock switched to zoom")
	_release_all(subject)


func _test_two_finger_zoom_lock(subject: Node3D) -> void:
	_reset_gesture(subject)
	var initial_focus: Vector3 = subject.focus
	var initial_distance: float = subject.distance
	_press(subject, 0, Vector2(100.0, 100.0))
	_press(subject, 1, Vector2(300.0, 100.0))
	_drag(subject, 0, Vector2(80.0, 100.0), Vector2(-20.0, 0.0))
	_drag(subject, 1, Vector2(320.0, 100.0), Vector2(20.0, 0.0))
	subject.call("_process", 0.0)
	_expect(subject.distance < initial_distance, "outward pinch did not zoom in")
	_expect(subject.focus.distance_to(initial_focus) <= EPSILON, "symmetric pinch moved focus")
	var zoomed_distance: float = subject.distance
	_drag(subject, 0, Vector2(120.0, 125.0), Vector2(40.0, 25.0))
	_drag(subject, 1, Vector2(360.0, 125.0), Vector2(40.0, 25.0))
	subject.call("_process", 0.0)
	_expect(absf(subject.distance - zoomed_distance) <= EPSILON, "zoom lock switched to pan movement")
	_expect(subject.focus.distance_to(initial_focus) <= EPSILON, "zoom-locked gesture panned the camera")
	_release_all(subject)


func _test_remaining_finger_stays_locked(subject: Node3D) -> void:
	_reset_gesture(subject)
	var initial_yaw: float = subject.yaw
	var initial_pitch: float = subject.pitch
	_press(subject, 0, Vector2(100.0, 100.0))
	_press(subject, 1, Vector2(300.0, 100.0))
	_release(subject, 1)
	_drag(subject, 0, Vector2(130.0, 115.0), Vector2(30.0, 15.0))
	_expect(absf(subject.yaw - initial_yaw) <= EPSILON and absf(subject.pitch - initial_pitch) <= EPSILON,
		"remaining two-finger gesture contact rotated the camera")
	_release_all(subject)


func _test_original_locomotion(subject: Node3D) -> void:
	var dwarf: Node3D = subject.dwarf_nodes[0]
	subject.selected_dwarf = dwarf
	_expect(subject.call("_dwarf_sequence_frame_count", dwarf, &"gehen_start") == 3,
		"original gehen_start frame count is not 3")
	_expect(subject.call("_dwarf_sequence_frame_count", dwarf, &"gehen_loop") == 10,
		"original gehen_loop frame count is not 10")
	_expect(subject.call("_dwarf_sequence_frame_count", dwarf, &"gehen_end") == 4,
		"original gehen_end frame count is not 4")
	_expect(subject.call("_dwarf_sequence_frame_count", dwarf, &"laufen_schnell_loop") == 10,
		"original fast-run loop frame count is not 10")
	_expect(subject.call("_dwarf_sequence_frame_count", dwarf, &"drehen_links") == 4,
		"original turn-left frame count is not 4")
	_expect(subject.call("_dwarf_sequence_frame_count", dwarf, &"stand_anim_a") == 13,
		"original stand_anim_a frame count is not 13")
	_expect(subject.call("_dwarf_sequence_frame_count", dwarf, &"stand_anim_b") == 7,
		"original stand_anim_b frame count is not 7")
	var multiplayer: bool = subject.scene_file_path.ends_with("multiplayer_test.tscn")
	_expect(subject.camera.projection == Camera3D.PROJECTION_PERSPECTIVE, "default perspective camera changed")
	var floor_y: float = -14.5 if multiplayer else -10.5
	var valid_local := Vector3(5.0, floor_y, 14.0)
	var valid_world: Vector3 = subject.scene_root.to_global(valid_local)
	var resolved: Variant = subject.call("_resolve_walk_target", valid_world)
	_expect(resolved is Vector3 and (resolved as Vector3).is_equal_approx(valid_local),
		"walk target near the mushrooms was not accepted")
	# Explicit fixtures: multiplayer's Pilz and demo_start's tree stump.
	var obstacle_target: Vector3 = Vector3(10.9121, floor_y, 13.62) if multiplayer else Vector3(6.3, floor_y, 4.3)
	var resolved_obstacle: Variant = subject.call("_resolve_walk_target", subject.scene_root.to_global(obstacle_target))
	_expect(resolved_obstacle is Vector3 and Vector2((resolved_obstacle as Vector3).x, (resolved_obstacle as Vector3).z).distance_to(
		Vector2(obstacle_target.x, obstacle_target.z)) > 0.5, "blocked object target was not moved to a free place")
	var outside_world: Vector3 = subject.scene_root.to_global(Vector3(25.0, floor_y, 10.0))
	_expect(subject.call("_resolve_walk_target", outside_world) == null,
		"target outside the cave floor was accepted")
	var path: Array[Vector3] = subject.call("_navigation_path", dwarf.position, valid_local)
	_expect(path.size() > 2, "navigation graph did not build a route across the cave floor")
	for point: Vector3 in path:
		var point_id: Vector2i = subject.call("_local_to_navigation_id", point)
		_expect(not subject.navigation_grid.is_point_solid(point_id), "navigation route crossed an obstacle")
	subject.call("_start_dwarf_walk", dwarf, valid_local)
	for _step: int in range(500):
		subject.call("_update_dwarf_locomotion", 0.1)
		if subject.moving_dwarf == null:
			break
	_expect(subject.moving_dwarf == null and Vector2(dwarf.position.x, dwarf.position.z).distance_to(
		Vector2(valid_local.x, valid_local.z)) <= EPSILON, "dwarf did not finish the routed walk with result 4")
	var rendered_basis: Basis = dwarf.global_transform.basis
	_expect(absf(rendered_basis.x.length() - 1.0) <= 0.001
		and absf(rendered_basis.y.length() - 1.0) <= 0.001
		and absf(rendered_basis.z.length() - 1.0) <= 0.001,
		"dwarf heading introduced non-uniform render-space stretching")
	subject.last_walk_target = valid_local
	var nearby_target := Vector3(5.5, floor_y, 13.5)
	subject.call("_start_dwarf_walk", dwarf, nearby_target)
	_expect(subject.fast_walk, "repeated nearby command did not enable original fast-run mode")
	subject.call("_finish_dwarf_walk")


func _reset_gesture(subject: Node3D) -> void:
	subject.touch_points.clear()
	subject.touch_start_positions.clear()
	subject.gesture_baseline_ready = false
	subject.gesture_dirty = false
	subject.gesture_had_multiple_touches = false
	subject.two_finger_mode = &"none"


func _press(subject: Node3D, index: int, position: Vector2) -> void:
	var event := InputEventScreenTouch.new()
	event.index = index
	event.position = position
	event.pressed = true
	_deliver_input(subject, event)


func _drag(subject: Node3D, index: int, position: Vector2, relative: Vector2) -> void:
	var event := InputEventScreenDrag.new()
	event.index = index
	event.position = position
	event.relative = relative
	_deliver_input(subject, event)


func _release(subject: Node3D, index: int) -> void:
	var event := InputEventScreenTouch.new()
	event.index = index
	event.position = subject.touch_points.get(index, Vector2.ZERO)
	event.pressed = false
	_deliver_input(subject, event)


func _release_all(subject: Node3D) -> void:
	var active_indices: Array = subject.touch_points.keys()
	for index: int in active_indices:
		var event := InputEventScreenTouch.new()
		event.index = index
		event.position = subject.touch_points.get(index, Vector2.ZERO)
		event.pressed = false
		_deliver_input(subject, event)


func _deliver_input(subject: Node3D, event: InputEvent) -> void:
	subject.call("_input" if subject.has_method("_input") else "_unhandled_input", event)


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("GESTURE_ASSERT: " + message)
