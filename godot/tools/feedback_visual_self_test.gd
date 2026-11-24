extends SceneTree
var checks: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func check(condition: bool, message: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		push_error("FEEDBACK_VISUAL_FAILED " + message)


func _run() -> void:
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	subject.set_process(false)
	subject.automatic_torches = false
	check(subject.flame_emitters.size()==3,"three original bowls have their own source emitters")
	var source_normals_ok: bool = false
	for child: Node in subject.scene_root.get_children():
		if child is Node3D and str(child.get_meta("native_class","")).begins_with("Dummy_Wand_kaserne"):
			var mesh: MeshInstance3D = child.get_child(0)
			var normals: PackedVector3Array = mesh.mesh.surface_get_arrays(0)[Mesh.ARRAY_NORMAL]
			var raw: Array = subject.native_model_material.data["normal_table"][183]
			var expected: Vector3 = Vector3(raw[0],-float(raw[1]),raw[2])
			source_normals_ok = normals[0].distance_to(expected)<0.002 and normals[0].distance_to(Vector3.BACK)>0.02
			break
	check(source_normals_ok,"masonry uses its original smooth sphere normal, not generated plane shading")
	var lights_before: int = subject.source_profile.terrain_lights.size()
	for frame: int in range(64):
		subject._update_source_flames()
	var bounded: bool = true
	for effect: Node3D in subject.flame_emitters.values():
		var snapshot: Dictionary = effect.snapshot()
		bounded = bounded and int(snapshot["live"])>0 and int(snapshot["live"])<=int(snapshot["capacity"]) and int(snapshot["surfaces"])==1
	check(bounded,"source flames remain bounded and submit actual quads")
	check(subject.source_profile.terrain_lights.size()==lights_before,"flames do not duplicate existing bowl lights")
	await _capture(subject,"overview.png",Vector3(19,-12,11),36.0)
	for anchor: Node3D in subject.flame_emitters:
		await _capture(subject,"torch_close.png",anchor.position+Vector3(0,0.4,0),5.0)
		break
	var worker: Node3D = subject.dwarf_nodes[0]
	subject._select_dwarf(worker)
	var silhouette: MeshInstance3D = worker.get_node_or_null("SelectionSilhouette") as MeshInstance3D
	var per_part_overlay: bool = false
	for mesh: MeshInstance3D in worker.find_children("*", "MeshInstance3D", true, false):
		if mesh != silhouette and mesh.material_overlay != null:
			per_part_overlay = true
	check(silhouette != null and silhouette.visible and silhouette.mesh != null,
		"selection uses one body silhouette proxy")
	check(not per_part_overlay,"selection does not outline body parts or attachments independently")
	worker.set_meta("exp_Stein",0.0)
	var point: Vector2i = Vector2i(2,15)
	check(subject.native_mark_corridor_cell(0,point) and subject.assign_dwarf_dig(worker,point),"novice mining order")
	for frame: int in range(600):
		if subject.dwarf_dig_jobs.has(worker) and subject.dwarf_dig_jobs[worker]["phase"]=="work":
			break
		subject.call("_process",0.05)
	var job: Dictionary = subject.dwarf_dig_jobs[worker]
	check(bool(job.get("accident_prelude",false)) and job["clip"]==&"buddeln_unten_unfall","source novice down-pick accident selected")
	subject.call("_process",1.5)
	check(subject.terrain_state.revision==0 and subject.dig_action_completions==0,"stuck-pick prelude has no terrain callback")
	check(subject.actor_attachments[worker]["spitzhacke"].visible and subject.actor_attachments[worker]["muetze_stein_a"].visible,"actual accident sockets retain pick and miner hat")
	var helmet: Node3D = subject.actor_attachments[worker]["muetze_stein_a"] as Node3D
	var helmet_lamp: OmniLight3D = helmet.get_node_or_null("MinerHelmetLight") as OmniLight3D
	check(helmet_lamp != null and helmet_lamp.visible and helmet_lamp.light_energy > 1.0,
		"active miner helmet carries a real local light")
	await _capture(subject,"pick_stuck.png",worker.position+Vector3(0,0.5,0),5.0)
	subject.call("_process",2.0)
	job = subject.dwarf_dig_jobs[worker]
	check(not bool(job.get("accident_prelude",false)) and job["clip"]==&"buddeln_unten","completion retries ordinary work with accident disabled")
	check(subject.terrain_state.revision==0 and subject.dig_action_completions==0,"finishing accident never digs")
	subject.call("_process",1.1)
	check(subject.terrain_state.revision==1 and subject.dig_action_completions==1,"only the following ordinary strike mutates BlockDB once")
	worker.set_meta("exp_Stein",0.2)
	check(subject.native_mark_corridor_cell(0,Vector2i(1,15)) and subject.assign_dwarf_dig(worker,Vector2i(1,15)),"experienced work order")
	for frame: int in range(600):
		if subject.dwarf_dig_jobs[worker]["phase"]=="work":
			break
		subject.call("_process",0.05)
	check(not bool(subject.dwarf_dig_jobs[worker].get("accident_prelude",false)),"threshold0.2 skips accident")
	subject._cancel_dwarf_dig(worker)
	subject.queue_free()
	await process_frame
	print("FEEDBACK_VISUAL_SELF_TEST checks=%d failures=%d" % [checks,failures])
	quit(0 if failures==0 else 1)


func _capture(subject: Node3D, file: String, focus_point: Vector3, camera_distance: float) -> void:
	if not OS.get_cmdline_user_args().has("--capture-feedback"):
		return
	var folder: String = ProjectSettings.globalize_path("res://").path_join("../docs/reverse-engineering/feedback-2026-11-18")
	DirAccess.make_dir_recursive_absolute(folder)
	subject.focus = subject.scene_root.to_global(focus_point)
	if file=="pick_stuck.png":
		subject.yaw = -0.4
	subject.distance = camera_distance
	subject._update_camera()
	subject._update_source_flames()
	await process_frame
	await RenderingServer.frame_post_draw
	check(root.get_texture().get_image().save_png(folder.path_join(file))==OK,"capture "+file)
