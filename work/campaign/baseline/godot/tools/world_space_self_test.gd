extends SceneTree
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
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.autonomous_dwarf_work = false
	root.add_child(subject)
	subject.set_process(false)
	check(subject.extended_world and subject.terrain_state.bounds.size == Vector2i(128,128), "normal scene has larger playable bounds")
	check(subject.template_shift == Vector2i(40,40), "start cave has margins on all sides")
	check(subject.native_terrain_cells.size() == 128*128, "entire field has actual BDB cells")
	check(subject.native_world.to_source(Vector3(42,55,13)) == Vector3(94,99,13), "shift preserves source world coordinates")
	var original: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/multi_start_010_terrain.json"))
	var intact: bool = true
	for cell: Dictionary in original["cells"]:
		var current: Dictionary = subject.native_terrain_cells[Vector2i(cell["x"]+40,cell["y"]+40)]
		intact = intact and current["block"] == cell["block"] and current["flags"] == cell["flags"]
	check(intact, "all authored block references and flags are preserved")
	var worker: Node3D = subject.dwarf_nodes[0]
	check(worker.position == Vector3(48,-54.5,10), "actors translated together with cave")
	check(subject.navigation_obstacles.size() == 3, "original object navigation obstacles retained")
	check(subject.model_light_records.size() >= 32, "original lightable surfaces retained")
	check(subject.terrain_state.current_height(Vector2i(20,54)) == 15, "added soil is native solid block")
	check(subject.native_mark_corridor_cell(0,Vector2i(20,54)), "corridor can be marked outside old template")
	check(subject.native_begin_cave(0,4,90,90), "largest cave brush fits in new field")
	subject._rebuild_corridor_preview()
	check(subject.cave_visual.visible and subject.cave_visual.mesh != null, "cave has a separate visible mask")
	var blue: Color = subject.cave_visual.material_override.albedo_color
	var green: Color = subject.corridor_visual.material_override.albedo_color
	check(blue.b > blue.g*1.8 and blue.r < blue.b*0.4 and green.g > green.b*2.0, "cave muted blue and corridor green")
	var old_focus: Vector3 = subject.focus
	subject.focus = Vector3(110,-110,12)
	subject._update_camera()
	subject._choose_tool("Пещера 1")
	var screen: Vector2 = subject.camera.unproject_position(subject.scene_root.to_global(Vector3(110.25,-110.25,subject.DIG_MARK_DEPTH)))
	subject._update_hover_brush(screen)
	var hover_color: Color = subject.hover_visual.material_override.albedo_color
	check(subject.hover_visual.visible and hover_color.b > hover_color.g*1.1, "hover cave outline is blue")
	var count_before: int = subject.native_active_caves.size()
	subject._handle_tap(screen)
	check(subject.native_active_caves.size() == count_before+1, "screen click places cave in expanded world")
	check(subject.native_active_caves.back()["cursor"] == Vector2i(110,110), "commit shares hover cursor without adding anchor twice")
	var clicked_cells: Array[Vector3i] = subject.native_cave_brush_cells(1,110,110)
	var all_blue: bool = true
	for cell: Vector3i in clicked_cells:
		all_blue = all_blue and (subject._work_mark(Vector2i(cell.x,cell.z)) & 8) != 0
	check(all_blue, "screen click commits every cell of the preview footprint")
	subject._choose_tool("Выбор")
	subject._choose_tool("Ластик")
	subject._update_hover_brush(screen)
	var erase_color: Color = subject.hover_visual.material_override.albedo_color
	check(subject.hover_visual.visible and absf(erase_color.r-erase_color.g)<0.03 and absf(erase_color.g-erase_color.b)<0.03, "eraser has grey native-footprint outline")
	subject._choose_tool("Выбор")
	subject.focus = old_focus
	subject._update_camera()
	# Native copy-on-write preview must leave every original field unchanged.
	var before: Dictionary = subject.terrain_state.facts.duplicate(true)
	var patch: Dictionary = subject.terrain_state.preview_accepted_step(Vector2i(20,54),0,3,true)
	check(patch["accepted"] and subject.terrain_state.facts == before, "large-world preview is isolated")
	check(subject.native_dig_apply_cell(0,Vector2i(20,54)), "new field uses real native terrain mutation")
	check(subject.native_walkmap.sample_bounds.size == Vector2i(1024,1024), "navigation spans expanded field")
	# A connected corridor extends left from the original cave into the substrate.
	var stroke: RefCounted = subject.CORRIDOR_STROKE.new()
	stroke.begin(Vector2(41.5,53.5),subject.tunnel_rules.bounds)
	stroke.update(Vector2(31.5,53.5))
	var marks: Array[Vector2i] = []
	for point: Vector2i in stroke.finish():
		if point.x < 41 and subject.native_mark_corridor_cell(0,point):
			marks.append(point)
	check(marks.size() >= 16, "source brush selects a full-height extension corridor")
	print("WORLD_EXTENSION_MARKS ",marks)
	worker.set_meta("exp_Stein",0.2)
	check(subject.assign_dwarf_dig(worker,marks[0]), "worker finds frontier for distant corridor click")
	for step: int in range(5000):
		subject._process(0.05)
		if not subject.dwarf_manual_dig_tasks.has(worker):
			break
	var completed: int = 0
	for point: Vector2i in marks:
		if subject._work_mark(point) == 0:
			completed += 1
	check(completed == marks.size(), "worker actually digs entire source corridor beyond the old border")
	check(worker.position.x < 40.0, "worker traverses the newly excavated extension")
	# Completed cave skin must follow map X/Y, not use map Y as model depth.
	check(subject.native_begin_cave(0,1,100,100), "completion skin fixture fits")
	for cell: Vector3i in subject.native_active_caves.back()["cells"]:
		subject.native_clear_cave_mark(0,Vector2i(cell.x,cell.z))
	check(subject.native_finish_completed_caves() == 1, "completed cave creates one skin")
	var skin: Node3D = subject.scene_root.get_node("CaveSkinPreview_1") as Node3D
	check(skin != null and skin.position.y < -90.0 and is_equal_approx(skin.position.z,16.0), "cave skin uses map vertical axis and BDB depth")
	# Three independent workers can reserve three different cave cells.
	var workers: Array[Node3D] = subject.dwarf_nodes
	for worker_index: int in range(workers.size()):
		workers[worker_index].position = Vector3(48+worker_index*2,-54.5,10)
		check(subject.native_mark_cave_cell(0,Vector2i(44+worker_index,54),2), "three-worker cave mark")
	var assigned: int = 0
	for worker_index: int in range(workers.size()):
		if subject.assign_dwarf_dig(workers[worker_index],Vector2i(44+worker_index,54)):
			assigned += 1
	check(assigned == 3 and subject.dwarf_dig_jobs.size() == 3, "three workers receive separate cave frontiers")
	subject.queue_free()
	await process_frame
	print("WORLD_SPACE_SELF_TEST checks=", checks, " failures=", failures)
	quit(0 if failures == 0 else 1)
