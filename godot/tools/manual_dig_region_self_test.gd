extends SceneTree
const REGION: Script = preload("res://scripts/manual_dig_region.gd")
const CONTOUR: Script = preload("res://scripts/native_corridor_contour.gd")
var assertions: int = 0
var failures: int = 0
var capture_enabled: bool = false

func _initialize() -> void:
	call_deferred("_run")

func check(value: bool, message: String) -> void:
	assertions += 1
	if not value:
		failures += 1
		push_error("MANUAL_DIG_REGION_FAILED " + message)

func _subject() -> Node3D:
	var result: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	result.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	result.extended_world = false # Keep the authored-template fixture.
	root.add_child(result)
	result.set_process(false)
	return result

func _run() -> void:
	capture_enabled = OS.get_cmdline_user_args().has("--capture")
	var marks: Dictionary = {Vector2i.ZERO:3,Vector2i.RIGHT:10,Vector2i(2,0):8,Vector2i(4,0):3}
	check(REGION.component(Vector2i.ZERO,marks).size()==3,"corridor and touching cave form one component")
	var outline: PackedVector2Array = CONTOUR.build_triangles({Vector2i.ZERO:true},true)
	check(not outline.is_empty(),"source thick outline exists")
	var covers_center: bool = false
	var covers_ring: bool = false
	for index: int in range(0,outline.size(),3):
		covers_center = covers_center or Geometry2D.is_point_in_polygon(Vector2.ZERO,PackedVector2Array([outline[index],outline[index+1],outline[index+2]]))
		covers_ring = covers_ring or Geometry2D.is_point_in_polygon(Vector2(0.4,0.01),PackedVector2Array([outline[index],outline[index+1],outline[index+2]]))
	check(not covers_center and covers_ring,"hover keeps native .30-.49 strip without fill")
	var subject: Node3D = _subject()
	await process_frame
	var worker: Node3D = subject.dwarf_nodes[0]
	subject._choose_tool("Коридор")
	var cursor: Vector2 = subject.camera.unproject_position(subject.scene_root.to_global(Vector3(12,-16,subject.DIG_MARK_DEPTH)))
	subject._update_hover_brush(cursor)
	check(not subject.tool_cursor.visible,"redundant cursor word removed")
	await _capture(subject,"hover_outline.png",Vector3(12,-16,14),12.0)
	subject._choose_tool("Выбор")
	var clicked: Vector2i = Vector2i(1,17)
	for y: int in range(15,18):
		for x: int in range(1,3):
			check(subject.native_mark_corridor_cell(0,Vector2i(x,y)),"source corridor fixture")
	check(not subject._assign_dwarf_dig_point(worker,clicked),"clicked buried cell has no direct stance")
	check(subject.assign_dwarf_dig(worker,clicked),"any component point starts reachable frontier")
	check(subject.dwarf_dig_jobs.has(worker) and subject.dwarf_dig_jobs[worker]["point"]!=clicked,"worker chooses another work point")
	var hats_kept: bool = true
	var boundary_seen: bool = false
	var captured_boundary: bool = false
	for tick: int in range(4000):
		subject.call("_process",0.05)
		if subject.dig_action_completions>0 and subject.dwarf_manual_dig_tasks.has(worker):
			boundary_seen = true
			if not captured_boundary:
				captured_boundary = true
				await _capture(subject,"helmet_between_cells.png",worker.position+Vector3(0,0.6,0),6.0)
			if subject.actor_attachments.has(worker):
				hats_kept = hats_kept and subject.actor_attachments[worker]["muetze_stein_a"].visible
		if not subject.dwarf_manual_dig_tasks.has(worker):
			break
	check(boundary_seen and hats_kept,"hat stays equipped across completed cells")
	check(subject.terrain_state.revision==6 and subject.native_mark_nibbles.is_empty(),"one manual assignment completes six corridor cells")
	check(not subject.dwarf_manual_dig_tasks.has(worker),"completed manual task released")
	print("MANUAL_REGION_CORRIDOR mutations=",subject.terrain_state.revision," marks=",subject.native_mark_nibbles)
	subject.queue_free()
	await process_frame
	subject = _subject()
	await process_frame
	worker = subject.dwarf_nodes[0]
	check(subject.native_mark_corridor_cell(0,Vector2i(2,15)),"mixed corridor fixture")
	check(subject.native_mark_cave_cell(0,Vector2i(1,15),2),"mixed cave target 7 fixture")
	check(subject.assign_dwarf_dig(worker,Vector2i(2,15)),"mixed region assignment")
	for tick: int in range(4000):
		subject.call("_process",0.05)
		if not subject.dwarf_manual_dig_tasks.has(worker):
			break
	check(subject.terrain_state.revision>=3 and subject.native_mark_nibbles.is_empty(),"manual corridor continues into deeper cave")
	check(int(subject.terrain_state.current_height(Vector2i(1,15)))<=7,"cave uses its own target depth")
	print("MANUAL_REGION_CAVE mutations=",subject.terrain_state.revision," marks=",subject.native_mark_nibbles)
	var fire: Node3D = subject.scene_root.get_node("Feuerstelle_018")
	var found_base: bool = false
	for visual: Node in fire.get_children():
		if visual is MeshInstance3D and visual.mesh.get_aabb().size.y < 0.00001:
			found_base = true
			check(visual.position.y>0.005,"fire base separated from coplanar floor")
	check(found_base and fire.position.y==-14.5,"fire placement preserved")
	await _capture(subject,"fire_base.png",fire.position+Vector3(0,0.5,0),6.0)
	check(subject.native_mark_corridor_cell(0,Vector2i(9,3)),"pending fixture")
	check(not subject.assign_dwarf_dig(worker,Vector2i(9,3)) and subject.dwarf_manual_dig_tasks.has(worker),"unreachable region retains manual task")
	var history: int = subject.dig_selection_history.size()
	for tick: int in range(50):
		subject.call("_process",0.05)
	check(subject.dig_selection_history.size()==history,"unchanged pending task does not replan every frame")
	subject._cancel_dwarf_dig(worker)
	check(not subject.dwarf_manual_dig_tasks.has(worker),"explicit interruption releases pending task")
	subject.queue_free()
	print("MANUAL_DIG_REGION_SELF_TEST_%s assertions=%d" % ["OK" if failures==0 else "FAILED",assertions])
	quit(0 if failures==0 else 1)


func _capture(subject: Node3D, file: String, focus_point: Vector3, camera_distance: float) -> void:
	if not capture_enabled:
		return
	var directory: String = ProjectSettings.globalize_path("res://").path_join("../docs/reverse-engineering/manual-work-2026-11-18")
	DirAccess.make_dir_recursive_absolute(directory)
	subject.focus = subject.scene_root.to_global(focus_point)
	subject.distance = camera_distance
	subject._update_camera()
	# Reproject hover after camera changes; editing tools never commit here.
	if subject.dig_tool == "Коридор":
		var screen: Vector2 = subject.camera.unproject_position(subject.scene_root.to_global(Vector3(12,-16,subject.DIG_MARK_DEPTH)))
		subject._update_hover_brush(screen)
	await process_frame
	await RenderingServer.frame_post_draw
	check(root.get_texture().get_image().save_png(directory.path_join(file))==OK,"capture " + file)
