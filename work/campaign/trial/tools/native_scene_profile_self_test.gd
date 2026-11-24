extends SceneTree

const DIG_RULES: Script = preload("res://scripts/native_dig_rules.gd")


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
		push_error("NATIVE_PROFILE_SELF_TEST_FAILED scene script did not load")
		quit(1)
		return
	subject.set_process(false)
	var expected_targets: Array[int] = [15, 11, 11, 11, 11, 11, 11, 11, 0, 3, 7, 11, 0, 3, 7, 11]
	for nibble: int in range(16):
		if DIG_RULES.target_height(nibble) != expected_targets[nibble]:
			push_error("NATIVE_PROFILE_SELF_TEST_FAILED native mark decoder")
			quit(1)
			return
	if not DIG_RULES.corridor_indices_allowed(Vector2i(1, 0)) or DIG_RULES.corridor_indices_allowed(Vector2i(1, 1)):
		push_error("NATIVE_PROFILE_SELF_TEST_FAILED corridor parity")
		quit(1)
		return
	# Proven positive fixture from the native validator/source PMP trace.
	var sample: Vector2i = Vector2i(9, 3)
	if not subject.native_mark_corridor_cell(0, sample):
		push_error("NATIVE_PROFILE_SELF_TEST_FAILED corridor mark rejected")
		quit(1)
		return
	# A marked job must not progress just because render time passes.
	var corridor_marks: Dictionary = subject.native_mark_nibbles.duplicate()
	if not subject.native_begin_cave(0, 1, 16, 11):
		push_error("NATIVE_PROFILE_SELF_TEST_FAILED cave fixture rejected")
		quit(1)
		return
	var saved_marks: Dictionary = subject.native_mark_nibbles.duplicate()
	subject.call("_process", 10.0)
	if subject.native_mark_nibbles != saved_marks or not subject.native_cell_heights.is_empty():
		push_error("NATIVE_PROFILE_SELF_TEST_FAILED workerless job advanced")
		quit(1)
		return
	subject.native_active_caves.clear()
	subject.native_mark_nibbles = corridor_marks
	var lights: int = 0
	var triangles: int = 0
	var markers: int = 0
	var terrain_surfaces: int = 0
	for child: Node in subject.scene_root.get_children():
		if child is OmniLight3D:
			lights += 1
			if not child.has_meta("native_class_source") or not child.has_meta("native_placement_source"):
				push_error("NATIVE_PROFILE_SELF_TEST_FAILED untraceable source light")
				quit(1)
				return
		if child.name.begins_with("Misc_Light"):
			markers += 1
		if child is MeshInstance3D and child.name.begins_with("NativeTerrain_"):
			for surface: int in range(child.mesh.get_surface_count()):
				triangles += int(child.mesh.surface_get_array_len(surface) / 3.0)
				terrain_surfaces += 1
	if lights != 9 or markers != 0 or triangles != 5302 or subject.triangle_count != 5619 or terrain_surfaces <= 0:
		push_error("NATIVE_PROFILE_SELF_TEST_FAILED lights=%d markers=%d triangles=%d input=%d" % [lights, markers, triangles, subject.triangle_count])
		quit(1)
		return
	# Original four-reference mutation consumes corridor3 in this same step.
	if not subject.native_dig_apply_cell(0, sample) or not subject.native_mark_nibbles.is_empty() \
			or subject.terrain_state.revision != 1 or subject.native_dig_apply_cell(0, sample):
		push_error("NATIVE_PROFILE_SELF_TEST_FAILED native mutation/mark completion")
		quit(1)
		return
	print("NATIVE_PROFILE_SELF_TEST_OK lights=9 editor_markers=0 retained_triangles=5302 source_triangles=5619 terrain_surfaces=%d" % terrain_surfaces)
	subject.queue_free()
	quit(0)
