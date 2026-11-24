extends SceneTree
var failures: int = 0
var assertions: int = 0

func _initialize() -> void:
	call_deferred("_run")

func expect(value: bool, label: String) -> void:
	assertions += 1
	if not value:
		failures += 1
		push_error("MOVEMENT_FEEDBACK_FAILED " + label)

func _run() -> void:
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	await process_frame
	subject.set_process(false)
	var worker: Node3D = subject.dwarf_nodes[0]
	worker.position = Vector3(30, -18.5, 14.5)
	expect(subject.assign_dwarf_surface_walk(worker, Vector2i(256,148)), "right floor route")
	var action: RefCounted = subject.dwarf_walk_actions[worker]
	action.fast = true
	var speed: float = subject._current_walk_speed(action)
	expect(absf(speed - 1.7143362760543823) < 0.000001, "native run speed")
	subject._update_surface_walk(worker, 0.2)
	expect(absf(worker.position.x - 30.0 - speed * 0.2) < 0.00001, "full budget across short samples")
	subject._stop_dwarf_walk(worker)
	worker.position = Vector3(30,-18.5,14.5)
	expect(subject.assign_dwarf_surface_walk(worker, Vector2i(256,148)), "depth route")
	action = subject.dwarf_walk_actions[worker]
	subject._set_surface_floor_goal(worker, action, 12.0)
	expect(action.path[1].z < 14.5 and action.path[-1].z == 12.0, "depth distributed before final waypoint")
	subject._update_surface_walk(worker, 0.2)
	expect(worker.position.z < 14.5, "depth begins on first command")
	var heading: float = float(subject.dwarf_headings[worker])
	expect(heading > PI * 0.5 and heading < PI, "diagonal heading includes depth")
	subject._stop_dwarf_walk(worker)
	worker.position = Vector3(30,-18.5,12.0)
	expect(subject.assign_dwarf_surface_walk(worker, Vector2i(240,148)), "pure depth route")
	action = subject.dwarf_walk_actions[worker]
	subject._set_surface_floor_goal(worker, action, 14.5)
	subject._update_surface_walk(worker, 0.2)
	expect(worker.position.z > 12.0 and absf(float(subject.dwarf_headings[worker])) < 0.00001, "towards viewer heading")
	subject._stop_dwarf_walk(worker)
	subject._choose_tool("Коридор")
	var screen: Vector2 = subject.camera.unproject_position(subject.scene_root.to_global(Vector3(12,-16,subject.DIG_MARK_DEPTH)))
	subject._update_hover_brush(screen)
	expect(subject.hover_visual.visible and subject.hover_visual.mesh != null, "hover outline before press")
	expect(not subject.corridor_stroke.active and subject.native_mark_nibbles.is_empty(), "hover changes no marks")
	subject._choose_tool("Выбор")
	expect(not subject.hover_visual.visible, "selection hides brush")
	expect(subject._dwarf_dig_clip(Vector3(3,-14.5,12),Vector2i(3,12)) == &"buddeln_oben_normal", "source upper work clip")
	expect(subject._dwarf_sequence_frame_count(worker, &"buddeln_oben_normal") == 13, "upper clip exported")
	worker.position = Vector3(8,-14.5,10)
	expect(subject.native_mark_corridor_cell(0, Vector2i(2,15)), "work mark")
	expect(subject.assign_dwarf_dig(worker, Vector2i(2,15)), "tool work assignment")
	for step: int in range(1000):
		subject.call("_process", 0.05)
		if subject.dwarf_dig_jobs.has(worker) and subject.dwarf_dig_jobs[worker]["phase"] == "work":
			break
	expect(subject.actor_attachments.has(worker), "attachments instantiated")
	if subject.actor_attachments.has(worker):
		for asset: String in ["spitzhacke", "muetze_stein_a"]:
			expect(subject.actor_attachments[worker][asset].visible, "visible " + asset)
	var args: PackedStringArray = OS.get_cmdline_user_args()
	if args.has("--capture"):
		subject.focus = worker.position + Vector3(0,0.7,0)
		subject.distance = 4.5
		subject._update_camera()
		await process_frame
		await RenderingServer.frame_post_draw
		root.get_texture().get_image().save_png(ProjectSettings.globalize_path("res://").path_join("../docs/reverse-engineering/work-attachments-2026-11-18.png"))
	subject._cancel_dwarf_dig(worker)
	if subject.actor_attachments.has(worker):
		expect(not subject.actor_attachments[worker]["spitzhacke"].visible, "cancel hides tool")
	print("MOVEMENT_FEEDBACK_SELF_TEST_%s assertions=%d" % ["OK" if failures == 0 else "FAILED", assertions])
	subject.queue_free()
	quit(0 if failures == 0 else 1)
