extends SceneTree

const SURFACE_WALK: Script = preload("res://scripts/surface_walk_action.gd")

var assertions: int = 0
var failures: int = 0
var capture_dir: String = ""


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var packed: PackedScene = load("res://scenes/multiplayer_test.tscn")
	var subject: Node3D = packed.instantiate()
	subject.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	await process_frame
	await physics_frame
	await physics_frame
	if subject.get_script() == null:
		push_error("EXCAVATED_WALK_SELF_TEST_FAILED controller missing")
		quit(1)
		return
	subject.set_process(false)
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var capture_arg: int = args.find("--excavated-capture-dir")
	if capture_arg >= 0 and capture_arg + 1 < args.size():
		capture_dir = args[capture_arg + 1]
	var worker: Node3D = subject.dwarf_nodes[0]
	var goal: Vector2i = Vector2i(12,132)
	var shallow: Vector2i = Vector2i(7,118)
	var body_probe: Vector2i = Vector2i(12,124)
	var before_flags: PackedByteArray = subject.native_walkmap.flags.duplicate()
	_expect(int(subject.native_walkmap.sample(goal)) == 0, "new floor was already accessible in initial PMP")
	_expect(int(subject.native_walkmap.sample(shallow)) == 0, "shallow new passage fixture was already accessible")
	_expect(subject._native_height_sample(body_probe) == 15, "source body probe did not start as solid ground")
	_expect(not subject.native_walkmap.is_newly_navigable(goal), "closed source sample was marked as newly open")
	_expect(not subject.assign_dwarf_surface_walk(worker,goal), "actor could enter solid ground before excavation")
	_expect(subject.dwarf_walk_actions.is_empty() and subject.terrain_state.revision == 0, "rejected walk created actions or changed terrain")
	var initial_ray: Dictionary = _floor_ray(subject, Vector3(1.5,-16.5,14.5))
	_expect(initial_ray.is_empty(), "new floor collision already existed inside solid ground")
	await _capture(subject,"before_dig.png",Vector3(2.2,-15.5,12))
	var points: Array[Vector2i] = [Vector2i(1,15),Vector2i(2,15),Vector2i(2,16),Vector2i(1,16)]
	for point: Vector2i in points:
		_expect(subject.native_mark_corridor_cell(0,point), "source corridor point rejected")
	_expect(subject.assign_dwarf_dig(worker,points[0]), "excavation worker not assigned")
	for step: int in range(3000):
		subject.call("_process",0.05)
		if not subject.dwarf_dig_jobs.has(worker):
			break
	_expect(subject.terrain_state.revision == 4 and subject.dig_action_completions == 4, "one assignment did not excavate four source points")
	_expect(subject.native_mark_nibbles.is_empty(), "completed excavation left marks")
	_expect(subject._native_height_sample(body_probe) == 11, "excavation did not clear source body probe")
	_expect(int(subject.native_walkmap.sample(goal)) == 3, "new lower floor did not receive source floor bits")
	_expect(subject.native_walkmap.is_newly_navigable(goal) and subject.native_walkmap.is_newly_navigable(shallow), "current availability lost its initial-PMP comparison")
	_expect(not subject.native_walkmap.is_newly_navigable(Vector2i(64,116)), "old floor was labeled as newly excavated")
	var width: int = subject.native_walkmap.sample_bounds.size.x
	var opened: Array[Vector2i] = []
	for index: int in range(before_flags.size()):
		var sample: Vector2i = Vector2i(index % width,floori(float(index)/float(width)))
		if subject.native_walkmap.is_newly_navigable(sample):
			opened.append(sample)
	_expect(not opened.is_empty(), "excavation produced no newly available samples")
	await physics_frame
	await physics_frame
	var floor_hit: Dictionary = _floor_ray(subject,Vector3(1.5,-16.5,14.5))
	_expect(not floor_hit.is_empty(), "new navigation floor lacks terrain collision")
	if not floor_hit.is_empty():
		var local_hit: Vector3 = subject.scene_root.to_local(floor_hit["position"])
		_expect(absf(local_hit.y+16.5)<0.001, "new collision is at another floor height")
		print("EXCAVATED_FLOOR_PHYSICS ",local_hit)
	await _capture(subject,"after_dig.png",Vector3(2.2,-15.5,12))
	# This click is only 0.25 cells below the old floor; the former height-only
	# branch sent it through the legacy floor adapter and lost the new passage.
	subject.focus = Vector3(3,-15,12)
	subject.distance = 14.0
	subject._update_camera()
	subject._choose_tool("Выбор")
	subject._select_dwarf(worker)
	var shallow_screen: Vector2 = subject.camera.unproject_position(subject.scene_root.to_global(
		Vector3(float(shallow.x)*0.125,-float(shallow.y)*0.125,subject.DIG_MARK_DEPTH)))
	subject._handle_tap(shallow_screen)
	_expect(subject.actor_tasks.runner(worker).queue.count() == 1, "shallow click did not enqueue walk")
	subject.actor_tasks.dispatch()
	_expect(subject.dwarf_walk_actions.has(worker) and subject.dwarf_walk_actions[worker] is SURFACE_WALK,
		"ordinary shallow click did not choose the source surface route")
	if subject.dwarf_walk_actions.has(worker):
		_expect(subject.dwarf_walk_actions[worker].samples[-1] == shallow, "shallow click snapped away from newly opened sample")
	subject._stop_dwarf_walk(worker)
	var start: Vector2i = subject._actor_navigation_sample(worker.position)
	var no_climb: Dictionary = subject.SURFACE_WALK.plan(start,goal,subject.native_walkmap,subject._native_height_sample,false)
	_expect(no_climb["status"] == "no_supported_route", "new lower floor was reached while climbing was disabled")
	var screen: Vector2 = subject.camera.unproject_position(subject.scene_root.to_global(
		Vector3(float(goal.x)*0.125,-float(goal.y)*0.125,subject.DIG_MARK_DEPTH)))
	subject._handle_tap(screen)
	_expect(subject.actor_tasks.runner(worker).queue.count() == 1, "new-floor click did not enqueue walk")
	subject.actor_tasks.dispatch()
	_expect(subject.dwarf_walk_actions.has(worker) and subject.dwarf_walk_actions[worker] is SURFACE_WALK,
		"ordinary new-floor click did not start a surface route")
	var traversed_new: bool = false
	var largest_step: float = 0.0
	var history_start: int = subject.surface_walk_history.size()
	for step: int in range(3000):
		var before: Vector3 = worker.position
		subject.call("_process",0.05)
		largest_step = maxf(largest_step,before.distance_to(worker.position))
		var sample: Vector2i = subject._actor_navigation_sample(worker.position)
		traversed_new = traversed_new or subject.native_walkmap.is_newly_navigable(sample)
		if not subject.dwarf_walk_actions.has(worker):
			break
	_expect(int(subject.surface_walk_results.get(worker,-1)) == 4, "new-floor route did not finish")
	_expect(worker.position.x == 1.5 and worker.position.y == -16.5, "actor did not stand on excavated lower floor")
	_expect(traversed_new, "actor bypassed all newly opened samples")
	_expect(int(subject.dwarf_surface_modes.get(worker,-1)) == 2, "actor remained in wall pose on new floor")
	_expect(largest_step <= subject.WALK_SPEED*subject.RUN_SPEED_MULTIPLIER*0.05+0.0001, "route teleported actor into excavation")
	var down_clip: bool = false
	var entered_count: int = 0
	for index: int in range(history_start,subject.surface_walk_history.size()):
		down_clip = down_clip or str(subject.surface_walk_history[index].get("clip","")) in ["kletter_runter_loop","kletter_runter_schnell"]
		if subject.surface_walk_history[index].get("event") == "completed":
			entered_count = int(subject.surface_walk_history[index].get("new_samples_entered",0))
	_expect(down_clip, "descent to new floor skipped original downward climb clip")
	_expect(entered_count > 0, "completed action did not record entering newly opened samples")
	await _capture(subject,"new_floor_reached.png",worker.position)
	_expect(subject.assign_dwarf_surface_walk(worker,Vector2i(20,116)), "return to initial floor rejected")
	for step: int in range(3000):
		subject.call("_process",0.05)
		if not subject.dwarf_walk_actions.has(worker):
			break
	_expect(int(subject.surface_walk_results.get(worker,-1)) == 4 and worker.position.y == -14.5,
		"return through excavation did not reach original floor")
	var return_up: bool = false
	for entry: Dictionary in subject.surface_walk_history:
		return_up = return_up or str(entry.get("clip","")) in ["kletter_hoch_loop","kletter_hoch_schnell"]
	_expect(return_up,"return through excavation skipped original upward climb clip")
	_expect(subject.terrain_state.revision == 4 and subject.dig_action_completions == 4,
		"traversing excavation repeated a terrain mutation")
	_expect(subject.dwarf_walk_actions.is_empty() and subject.dwarf_dig_jobs.is_empty(), "finished excavation traversal leaked actions")
	print("EXCAVATED_WALK_RESULT opened_samples=",opened.size()," entered_samples=",entered_count,
		" goal=",goal," body_depth=15->11 max_step=",largest_step)
	if failures == 0:
		print("EXCAVATED_WALK_SELF_TEST_OK assertions=%d mutations=4 new_floor=16.5 original_floor=14.5" % assertions)
	if failures == 0 and not capture_dir.is_empty():
		subject.focus = Vector3(19,-12,11)
		subject.distance = 36.0
		await subject._capture_views(capture_dir)
		return
	subject.queue_free()
	quit(0 if failures == 0 else 1)


func _floor_ray(subject: Node3D, point: Vector3) -> Dictionary:
	var from: Vector3 = subject.scene_root.to_global(point+Vector3.UP*0.4)
	var to: Vector3 = subject.scene_root.to_global(point+Vector3.DOWN*0.4)
	return subject.get_world_3d().direct_space_state.intersect_ray(PhysicsRayQueryParameters3D.create(from,to,1))


func _capture(subject: Node3D, filename: String, center: Vector3) -> void:
	if capture_dir.is_empty():
		return
	DirAccess.make_dir_recursive_absolute(capture_dir)
	var old_focus: Vector3 = subject.focus
	var old_distance: float = subject.distance
	subject.focus = center
	subject.distance = 9.0
	subject._update_camera()
	await process_frame
	await RenderingServer.frame_post_draw
	var result: Error = root.get_texture().get_image().save_png(capture_dir.path_join(filename))
	_expect(result == OK,"could not capture excavation traversal")
	subject.focus = old_focus
	subject.distance = old_distance
	subject._update_camera()


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("EXCAVATED_WALK_SELF_TEST_FAILED "+message)
