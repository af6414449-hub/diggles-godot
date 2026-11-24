extends SceneTree
## Real controller/input integration, including world-ray projection.

var subject: Node3D
var assertions: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var scene: PackedScene = load("res://scenes/multiplayer_test.tscn")
	subject = scene.instantiate()
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	await process_frame
	subject.set_process(false)
	subject.focus = Vector3(22.0, -12.0, 11.0)
	subject.yaw = 0.0
	subject.pitch = 0.0
	subject.distance = 60.0
	subject.camera.projection = Camera3D.PROJECTION_ORTHOGONAL
	subject.camera.size = 40.0
	subject.call("_update_camera")
	_test_source_validator()
	_test_mouse_commit()
	_test_replace_and_cancel()
	_test_touch()
	_test_erase()
	_test_group_commit_lifecycle()
	if failures == 0:
		print("NATIVE_CORRIDOR_INPUT_SELF_TEST_OK assertions=%d" % assertions)
	else:
		push_error("NATIVE_CORRIDOR_INPUT_SELF_TEST_FAILED failures=%d" % failures)
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var capture_arg: int = args.find("--corridor-capture-dir")
	if failures == 0 and capture_arg >= 0 and capture_arg + 1 < args.size():
		_reset()
		_mouse(Vector2(3.75, 3.75), true)
		_motion(Vector2(10.0, 4.0))
		_mouse(Vector2(10.0, 4.0), false)
		subject.tool_cursor.visible = false
		subject.camera.projection = Camera3D.PROJECTION_PERSPECTIVE
		subject.focus = Vector3(19.0, -12.0, 11.0)
		subject.distance = 36.0
		await subject.call("_capture_views", args[capture_arg + 1])
		return
	subject.queue_free()
	quit(0 if failures == 0 else 1)


func _reset() -> void:
	subject.native_mark_nibbles.clear()
	subject.native_cell_heights.clear()
	subject.touch_points.clear()
	subject.touch_start_positions.clear()
	subject.gesture_had_multiple_touches = false
	subject.two_finger_mode = &"none"
	subject.call("_choose_tool", "Коридор")


func _screen(raw: Vector2) -> Vector2:
	return subject.camera.unproject_position(subject.scene_root.to_global(Vector3(raw.x, -raw.y, subject.DIG_MARK_DEPTH)))


func _mouse(raw: Vector2, pressed: bool, device: int = 0) -> void:
	var event: InputEventMouseButton = InputEventMouseButton.new()
	event.device = device
	event.button_index = MOUSE_BUTTON_LEFT
	event.position = _screen(raw)
	event.pressed = pressed
	subject.call("_input", event)


func _motion(raw: Vector2) -> void:
	var event: InputEventMouseMotion = InputEventMouseMotion.new()
	event.position = _screen(raw)
	event.button_mask = MOUSE_BUTTON_MASK_LEFT
	subject.call("_input", event)


func _touch(index: int, raw: Vector2, pressed: bool, canceled: bool = false) -> void:
	var event: InputEventScreenTouch = InputEventScreenTouch.new()
	event.index = index
	event.position = _screen(raw)
	event.pressed = pressed
	event.canceled = canceled
	subject.call("_input", event)


func _drag(index: int, raw: Vector2) -> void:
	var event: InputEventScreenDrag = InputEventScreenDrag.new()
	event.index = index
	event.position = _screen(raw)
	event.relative = Vector2(15.0, 0.0)
	subject.call("_input", event)


func _test_mouse_commit() -> void:
	_reset()
	var group_counter: int = subject.native_dig_groups.counters[0]
	_mouse(Vector2(3.75, 3.75), true)
	_expect(subject.native_dig_groups.counters[0] == group_counter, "preview advanced group counter")
	_expect(subject.corridor_stroke.active, "press did not start a stroke")
	_expect(subject.native_mark_nibbles.is_empty(), "press wrote world marks")
	_expect(subject.corridor_stroke.anchor == Vector2(5.5, 5.5), "screen picking lost native start")
	_motion(Vector2(10.0, 4.0))
	_expect(subject.corridor_stroke.endpoint == Vector2(9.5, 5.5), "drag did not use original anchor")
	_expect(subject.native_mark_nibbles.is_empty(), "motion wrote world marks")
	# Different release coordinates must not replace the stored preview.
	_mouse(Vector2(10.0, 14.0), false)
	_expect(subject.native_dig_groups.counters[0] == group_counter + 1, "one commit did not advance exactly one group")
	_expect(not subject.corridor_stroke.active, "release left preview active")
	_expect(not subject.native_mark_nibbles.is_empty(), "release did not commit marks")
	for key: String in subject.native_mark_nibbles:
		var parts: PackedStringArray = key.split(":")
		_expect(int(parts[1]) in [5, 6], "release used its new vertical coordinates")
		_expect(int(subject.native_mark_nibbles[key]) == 3, "corridor mark is not nibble 3")
		_expect((subject.native_dig_groups.word(Vector2i(int(parts[0]), int(parts[1]))) & 15) == (group_counter & 15), "one stroke received different group stamps")
	_expect(subject.native_cell_heights.is_empty(), "selection changed terrain heights")
	_expect(subject.corridor_visual.mesh != null and subject.corridor_visual.visible, "committed marks are invisible")


func _test_source_validator() -> void:
	_reset()
	_expect(subject.tunnel_rules.point_rule(Vector2i(9, 3), false, false) == 1, "source positive fixture (9,3) rejected")
	_expect(subject.tunnel_rules.point_rule(Vector2i(5, 17), false, false) == 1, "source positive fixture (5,17) rejected")
	_expect(subject.tunnel_rules.point_rule(Vector2i(3, 3), false, false) == 0, "forbidden source parity accepted")
	_expect(subject.tunnel_rules.point_rule(Vector2i(9, 3), true, false) == 0, "existing cave mark overwritten")
	_expect(subject.tunnel_rules.point_rule(Vector2i(9, 3), false, true) == 0, "cave mark below ignored")
	_expect(subject.tunnel_rules.point_rule(Vector2i(0, 3), false, false) == 0, "standalone world interior border ignored")
	_expect(subject.tunnel_rules.point_rule(Vector2i(13, 5), false, false) == -1, "unknown player byte was invented")
	_expect(subject.tunnel_rules.point_rule(Vector2i(13, 5), false, false, 0) == 1, "zero player byte did not bypass material check")
	_expect(subject.tunnel_rules.point_rule(Vector2i(13, 5), false, false, 1) == 0, "nonzero player byte did not reject material 0")
	_expect(not subject.native_mark_corridor_cell(0, Vector2i(13, 5)), "unknown source state was committed")


func _test_replace_and_cancel() -> void:
	_reset()
	_mouse(Vector2(3.75, 3.75), true)
	_motion(Vector2(14.0, 4.0))
	_motion(Vector2(4.0, 10.0))
	_expect(subject.corridor_stroke.endpoint == Vector2(5.5, 9.5), "axis change accumulated old horizontal tiles")
	# Drag uses S2, while press uses S4: return to the snapped center, not the
	# raw press location, to shrink back to the original four samples.
	_motion(Vector2(5.75, 5.75))
	_expect(subject.corridor_stroke.samples().size() == 4, "shrinking did not replace the old preview")
	var escape: InputEventKey = InputEventKey.new()
	escape.physical_keycode = KEY_ESCAPE
	escape.pressed = true
	subject.call("_input", escape)
	_mouse(Vector2(4.0, 4.0), false)
	_expect(subject.native_mark_nibbles.is_empty(), "Escape confirmed draft marks")
	_mouse(Vector2(3.75, 3.75), true)
	subject.call("_choose_tool", "Выбор")
	_expect(not subject.corridor_stroke.active and subject.native_mark_nibbles.is_empty(), "tool switch committed preview")
	subject.call("_choose_tool", "Коридор")
	_mouse(Vector2(3.75, 3.75), true)
	subject.call("_notification", Node.NOTIFICATION_WM_WINDOW_FOCUS_OUT)
	_expect(not subject.corridor_stroke.active and subject.native_mark_nibbles.is_empty(), "focus loss committed preview")


func _test_touch() -> void:
	_reset()
	var original_yaw: float = subject.yaw
	_touch(0, Vector2(3.75, 3.75), true)
	_drag(0, Vector2(10.0, 4.0))
	_expect(subject.yaw == original_yaw, "one-finger drawing rotated camera")
	_expect(subject.native_mark_nibbles.is_empty(), "touch drag wrote marks")
	_touch(1, Vector2(12.0, 10.0), true)
	_expect(not subject.corridor_stroke.active, "second finger did not cancel draft")
	_touch(1, Vector2(12.0, 10.0), false)
	_touch(0, Vector2(10.0, 4.0), false)
	_expect(subject.native_mark_nibbles.is_empty(), "multitouch release committed canceled draft")
	_touch(0, Vector2(3.75, 3.75), true)
	_touch(0, Vector2(3.75, 3.75), false, true)
	_expect(subject.native_mark_nibbles.is_empty(), "canceled OS touch committed draft")
	_mouse(Vector2(3.75, 3.75), true, InputEvent.DEVICE_ID_EMULATION)
	_mouse(Vector2(3.75, 3.75), false, InputEvent.DEVICE_ID_EMULATION)
	_expect(subject.native_mark_nibbles.is_empty(), "emulated mouse duplicated touch action")
	_touch(0, Vector2(3.75, 3.75), true)
	_touch(0, Vector2(3.75, 3.75), false)
	_expect(subject.native_mark_nibbles.size() == 4, "single-finger tap did not commit the four source samples")


func _test_erase() -> void:
	_reset()
	_mouse(Vector2(3.75, 3.75), true)
	_mouse(Vector2(3.75, 3.75), false)
	subject.native_mark_corridor_cell(1, Vector2i(5, 5))
	subject.native_mark_corridor_cell(0, Vector2i(9, 3))
	subject.call("_choose_tool", "Ластик")
	_mouse(Vector2(5.25, 5.25), true)
	_expect(subject.native_mark_nibbles.size() == 2, "native tool-5 eraser did not clear on press")
	_mouse(Vector2(5.25, 5.25), false)
	_expect(subject.native_mark_nibbles.size() == 2, "eraser did not clear just its source samples")
	_expect(subject.native_mark_nibbles.has("5:5:0:1"), "eraser changed another owner's marks")
	_expect(subject.native_mark_nibbles.has("9:3:0:0"), "eraser changed unrelated marks")
	_expect(subject.native_cell_heights.is_empty(), "eraser changed terrain")
	# Imported marks may exist at positions forbidden to new tunnel placement.
	subject.native_mark_nibbles["3:3:0:0"] = 3
	_mouse(Vector2(3.25, 3.25), true)
	_mouse(Vector2(3.25, 3.25), false)
	_expect(not subject.native_mark_nibbles.has("3:3:0:0"), "eraser incorrectly used placement parity")
	_reset()
	_expect(subject.native_begin_cave(0, 1, 16, 11), "cave erase fixture rejected")
	subject.native_mark_cave_cell(0, Vector2i(9, 3), 1)
	var first: Vector3i = subject.native_active_caves[0]["cells"][0]
	subject.call("_choose_tool", "Ластик")
	_mouse(Vector2(float(first.x) + 0.1, float(first.z) + 0.1), true)
	_expect(subject.native_active_caves.is_empty(), "cave seed did not cancel pending cave record")
	_expect(subject.native_mark_nibbles.size() == 1 and subject.native_mark_nibbles.has("9:3:0:0"), "cave eraser did not preserve a disconnected island")
	_expect(subject.native_finished_cave_skins.is_empty(), "erasing spawned a completed cave")
	# A sparse motion path must cover the swept 2x2 brush, without filling its
	# entire bounding rectangle or applying placement parity.
	var eraser_script: Script = load("res://scripts/native_erase_brush.gd")
	var horizontal: Array[Vector2i] = eraser_script.between(Vector3(5.25, 5.25, 0), Vector3(9.25, 5.25, 0), Rect2i(0, 0, 44, 24))
	_expect(horizontal.size() == 12, "interpolated erase skipped a horizontal sample")
	var diagonal: Array[Vector2i] = eraser_script.between(Vector3(5.25, 5.25, 0), Vector3(9.25, 9.25, 0), Rect2i(0, 0, 44, 24))
	_expect(not diagonal.has(Vector2i(5, 9)) and not diagonal.has(Vector2i(9, 5)), "diagonal eraser cleared its bounding rectangle")


func _test_group_commit_lifecycle() -> void:
	_reset()
	var before: int = subject.native_dig_groups.counters[0]
	var words: Dictionary = subject.native_dig_groups.words.duplicate()
	_mouse(Vector2(3.75, 3.75), true)
	subject.call("_choose_tool", "Выбор")
	_expect(subject.native_dig_groups.counters[0] == before, "cancel advanced group counter")
	_expect(subject.native_dig_groups.words == words, "cancel stamped uncommitted preview")
	_reset()
	_mouse(Vector2(11.75, 3.75), true)
	_mouse(Vector2(11.75, 3.75), false)
	_expect(subject.native_mark_nibbles.is_empty(), "fully rejected source fixture unexpectedly committed")
	_expect(subject.native_dig_groups.counters[0] == before + 1, "fully rejected commit did not advance source group")


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("CORRIDOR_INPUT_ASSERT " + message)
