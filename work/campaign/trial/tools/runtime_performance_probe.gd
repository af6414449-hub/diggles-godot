extends SceneTree
## Desktop-only, stdout JSON probe. Never saves scenes, resources or project settings.
## godot --path godot --script res://tools/runtime_performance_probe.gd -- --probe-frames 360
## Optional --probe-headless permits CPU/inventory checks; renderer zeros are NOT evidence.

var subject: Node3D
var sample_frames: int = 360
var meshes: Array[MeshInstance3D] = []
var lights: Array[OmniLight3D] = []
var report: Dictionary = {}
var fixed_camera: Camera3D
var fixed_camera_transform: Transform3D


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var index: int = args.find("--probe-frames")
	if index >= 0 and index + 1 < args.size():
		sample_frames = maxi(60, int(args[index + 1]))
	if DisplayServer.get_name() == "headless" and not args.has("--probe-headless"):
		push_error("Renderer measurements require a window. Use --probe-headless for CPU/inventory only.")
		quit(2)
		return
	Engine.max_fps = 0
	if DisplayServer.get_name() != "headless":
		DisplayServer.window_set_vsync_mode(DisplayServer.VSYNC_DISABLED)
	var started: int = Time.get_ticks_usec()
	var packed: PackedScene = load("res://scenes/multiplayer_test.tscn") as PackedScene
	if packed == null:
		quit(1)
		return
	subject = packed.instantiate() as Node3D
	root.add_child(subject)
	current_scene = subject
	if subject.get_script() == null:
		push_error("Probe aborted: target script failed to load (possibly concurrent edits).")
		quit(1)
		return
	subject.set_process_input(false)
	subject.set_process_unhandled_input(false)
	subject.set_process_unhandled_key_input(false)
	fixed_camera = subject.get("camera") as Camera3D
	if fixed_camera == null:
		push_error("Probe aborted: scene did not create a camera.")
		quit(1)
		return
	fixed_camera_transform = fixed_camera.global_transform
	RenderingServer.frame_pre_draw.connect(_lock_camera)
	report = {"engine": Engine.get_version_info(), "adapter": RenderingServer.get_video_adapter_name(),
		"renderer": RenderingServer.get_current_rendering_method(), "display": DisplayServer.get_name(),
		"viewport": str(root.size), "vsync": DisplayServer.window_get_vsync_mode(),
		"load_ready_ms": (Time.get_ticks_usec() - started) / 1000.0,
		"scene_script_sha256_at_load": FileAccess.get_sha256("res://scripts/multiplayer_test.gd"),
		"sample_frames": sample_frames, "phases": [],
		"note": "Desktop idle fixed camera; no input/network stress. Frame wall time includes wait/present; TIME_PROCESS is engine monitor, not script-exclusive CPU. Zero GPU/viewport timings mean unavailable, not free."}
	if DisplayServer.get_name() != "headless":
		RenderingServer.viewport_set_measure_render_time(root.get_viewport_rid(), true)
	await _settle(120)
	var inventory: Dictionary = {"nodes": 0, "mesh_instances": 0, "visible_meshes": 0,
		"mesh_resources": {}, "materials": {}, "visible_materials": {}, "visible_material_modes": {},
		"scripted_processors": [], "lights": [], "top_level": []}
	_inventory(subject, inventory)
	inventory["unique_meshes"] = inventory["mesh_resources"].size()
	inventory["unique_materials"] = inventory["materials"].size()
	inventory["unique_visible_materials"] = inventory["visible_materials"].size()
	inventory.erase("visible_materials")
	inventory.erase("mesh_resources")
	inventory.erase("materials")
	var render_root: Node3D = subject.get("scene_root") as Node3D
	for child: Node in render_root.get_children():
		if child is Node3D and not child.name.to_lower().begins_with("nativeterrain"):
			inventory["top_level"].append({"path": str(child.get_path()), "children": child.get_child_count()})
	report["inventory"] = inventory
	print("PERF_INVENTORY " + JSON.stringify(inventory))
	if args.has("--probe-msaa-only"):
		var saved_msaa: Viewport.MSAA = root.msaa_3d
		for repeat_index: int in range(3):
			root.msaa_3d = Viewport.MSAA_DISABLED
			await _measure("msaa_off_%d" % repeat_index)
			root.msaa_3d = Viewport.MSAA_4X
			await _measure("msaa_4x_%d" % repeat_index)
		root.msaa_3d = saved_msaa
		report["scene_script_sha256_at_end"] = FileAccess.get_sha256("res://scripts/multiplayer_test.gd")
		print("PERF_REPORT " + JSON.stringify(report))
		quit(0)
		return
	await _measure("baseline")
	subject.set_process(false)
	await _measure("root_process_off")
	subject.set_process(true)
	await _measure("baseline_return_1")
	for light: OmniLight3D in lights:
		light.visible = false
	await _measure("omni_off")
	for light: OmniLight3D in lights:
		light.visible = true
	await _measure("baseline_after_omni")
	var old_msaa: Viewport.MSAA = root.msaa_3d
	root.msaa_3d = Viewport.MSAA_DISABLED
	await _measure("msaa_off")
	root.msaa_3d = Viewport.MSAA_2X
	await _measure("msaa_2x")
	root.msaa_3d = Viewport.MSAA_4X
	await _measure("msaa_4x")
	root.msaa_3d = old_msaa
	await _measure("baseline_after_msaa")
	var terrain: Dictionary = subject.get("terrain_mesh_nodes")
	var saved_visibility: Dictionary = {}
	for mesh: MeshInstance3D in meshes:
		saved_visibility[mesh] = mesh.visible
	for node: MeshInstance3D in terrain.values():
		node.visible = false
	await _measure("terrain_hidden")
	_restore_visibility(saved_visibility)
	var saved_objects: Dictionary = {}
	for child: Node in render_root.get_children():
		if child is Node3D and not terrain.values().has(child) and not child is Light3D:
			saved_objects[child] = (child as Node3D).visible
			(child as Node3D).visible = false
	await _measure("objects_hidden")
	for child: Node3D in saved_objects:
		child.visible = bool(saved_objects[child])
	_restore_visibility(saved_visibility)
	await _measure("baseline_return_2")
	subject.set_process(false)
	report["callback_microbench"] = _microbench()
	await _measure("frozen_before_prune")
	# Destructive only inside this disposable process. No callbacks may dereference frames after this.
	var pruned: int = 0
	var visuals_by_dwarf: Dictionary = subject.get("dwarf_locomotion_visuals")
	for dwarf: Node3D in visuals_by_dwarf:
		var visuals: Dictionary = visuals_by_dwarf[dwarf]
		var sequences: Dictionary = visuals["sequences"]
		for frames: Array in sequences.values():
			for frame: Variant in frames:
				if frame is Node3D and not frame.is_visible_in_tree():
					pruned += 1 + frame.find_children("*", "", true, false).size()
					frame.free()
	report["pruned_hidden_frame_nodes"] = pruned
	await _measure("frozen_hidden_frames_pruned")
	report["scene_script_sha256_at_end"] = FileAccess.get_sha256("res://scripts/multiplayer_test.gd")
	print("PERF_REPORT " + JSON.stringify(report))
	# Dictionaries intentionally contain freed frame references; never resume scene processing.
	quit(0)


func _restore_visibility(saved: Dictionary) -> void:
	for mesh: MeshInstance3D in saved:
		mesh.visible = bool(saved[mesh])


func _lock_camera() -> void:
	# The desktop may be used concurrently; physical WASD must not invalidate A/B views.
	fixed_camera.global_transform = fixed_camera_transform


func _settle(frames: int) -> void:
	for frame_index: int in range(frames):
		await process_frame


func _measure(label: String) -> void:
	await _settle(90)
	var series: Dictionary = {"wall_ms": [], "process_monitor_ms": [], "physics_monitor_ms": [],
		"viewport_cpu_ms": [], "viewport_gpu_ms": [], "draw_calls": [], "objects": [], "primitives": []}
	var previous: int = Time.get_ticks_usec()
	for frame_index: int in range(sample_frames):
		await process_frame
		var now: int = Time.get_ticks_usec()
		series["wall_ms"].append((now - previous) / 1000.0)
		previous = now
		series["process_monitor_ms"].append(Performance.get_monitor(Performance.TIME_PROCESS) * 1000.0)
		series["physics_monitor_ms"].append(Performance.get_monitor(Performance.TIME_PHYSICS_PROCESS) * 1000.0)
		series["viewport_cpu_ms"].append(RenderingServer.viewport_get_measured_render_time_cpu(root.get_viewport_rid()))
		series["viewport_gpu_ms"].append(RenderingServer.viewport_get_measured_render_time_gpu(root.get_viewport_rid()))
		series["draw_calls"].append(RenderingServer.get_rendering_info(RenderingServer.RENDERING_INFO_TOTAL_DRAW_CALLS_IN_FRAME))
		series["objects"].append(RenderingServer.get_rendering_info(RenderingServer.RENDERING_INFO_TOTAL_OBJECTS_IN_FRAME))
		series["primitives"].append(RenderingServer.get_rendering_info(RenderingServer.RENDERING_INFO_TOTAL_PRIMITIVES_IN_FRAME))
	var result: Dictionary = {"phase": label}
	for key: String in series:
		result[key] = _stats(series[key])
	result["nodes"] = Performance.get_monitor(Performance.OBJECT_NODE_COUNT)
	result["static_memory_bytes"] = Performance.get_monitor(Performance.MEMORY_STATIC)
	result["render_memory_bytes"] = Performance.get_monitor(Performance.RENDER_VIDEO_MEM_USED)
	report["phases"].append(result)
	print("PERF_PHASE " + JSON.stringify(result))


func _stats(values: Array) -> Dictionary:
	values.sort()
	var total: float = 0.0
	for value: Variant in values:
		total += float(value)
	return {"mean": total / values.size(), "p50": values[floori(values.size() * 0.5)],
		"p95": values[mini(values.size() - 1, int(values.size() * 0.95))], "min": values[0], "max": values[-1]}


func _inventory(node: Node, counts: Dictionary) -> void:
	counts["nodes"] += 1
	if node.get_script() != null and (node.is_processing() or node.is_physics_processing()):
		counts["scripted_processors"].append(str(node.get_path()))
	if node is MeshInstance3D:
		var mesh_node: MeshInstance3D = node as MeshInstance3D
		meshes.append(mesh_node)
		counts["mesh_instances"] += 1
		if mesh_node.is_visible_in_tree():
			counts["visible_meshes"] += 1
		if mesh_node.mesh != null:
			counts["mesh_resources"][mesh_node.mesh.get_instance_id()] = true
			for surface: int in range(mesh_node.mesh.get_surface_count()):
				var material: Material = mesh_node.get_active_material(surface)
				if material != null:
					counts["materials"][material.get_instance_id()] = true
					if mesh_node.is_visible_in_tree():
						counts["visible_materials"][material.get_instance_id()] = true
						var mode: String = material.get_class()
						if material is BaseMaterial3D:
							mode += ":alpha=%d:cull=%d" % [(material as BaseMaterial3D).transparency, (material as BaseMaterial3D).cull_mode]
						counts["visible_material_modes"][mode] = int(counts["visible_material_modes"].get(mode, 0)) + 1
	if node is OmniLight3D:
		var light: OmniLight3D = node as OmniLight3D
		lights.append(light)
		counts["lights"].append({"path": str(light.get_path()), "range": light.omni_range,
			"shadow": light.shadow_enabled, "position": str(light.global_position)})
	for child: Node in node.get_children():
		_inventory(child, counts)


func _microbench() -> Dictionary:
	var results: Dictionary = {}
	for method: String in ["_process", "_update_dwarf_locomotion", "_update_dwarf_dig_jobs", "_update_dwarf_idle_animations"]:
		var values: Array = []
		for batch: int in range(20):
			var started: int = Time.get_ticks_usec()
			for iteration: int in range(100):
				subject.call(method, 1.0 / 60.0)
			values.append((Time.get_ticks_usec() - started) / 100.0)
		results[method + "_us_per_call"] = _stats(values)
	# This synthetic loop advances idle visuals faster than wall time; not gameplay FPS.
	return results
