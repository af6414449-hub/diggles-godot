extends SceneTree
const RUNTIME: Script = preload("res://scripts/native_torch_runtime.gd")
var checks: int = 0
var failures: int = 0
var material: Variant = 2
var raw_depth: Variant = 7


func _initialize() -> void:
	call_deferred("_run")


func check(condition: bool, message: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		push_error("AUTOMATIC_TORCH_FAILED " + message)


func _depth(_point: Vector2i) -> Variant:
	return raw_depth


func _material(_point: Vector2i) -> Variant:
	return material


func _run() -> void:
	var source: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_torches.json"))
	var runtime: RefCounted = RUNTIME.new()
	var empty_records: Array[Dictionary] = []
	runtime.configure(Rect2i(0,0,100,100),_depth,_material,source,empty_records,5)
	runtime.minimum_y = int(source["placement_defaults"]["minimum_y"])
	runtime.region_records = []
	runtime.tick = 13
	var actor: Dictionary = {"id":3,"autolight":true,"position":Vector3(10,10,7)}
	var actors: Array[Dictionary] = [actor]
	for pass_index: int in range(3):
		var result: Dictionary = runtime.update(0.0,actors)
		check(result["created"].size()==(1 if pass_index==2 else 0),"three object passes at the SAME tick, not three simulation ticks")
	check(runtime.tick==13 and runtime.torches.size()==1,"consumer independent of simulation clock")
	if runtime.torches.is_empty():
		print("TORCH_CREATE_DIAGNOSTIC ",runtime.last_decision," queue=",runtime.queue)
		quit(1)
		return
	var torch: Dictionary = runtime.torches[0]
	check(int(torch["frame"])==0,"default still frame0")
	var before_snap: Vector3 = torch["position"]
	runtime.tick = 101 # source schedule: (ID5 xor tick101)&15 ==0
	runtime.update(0.0,empty_records)
	check(torch["position"]==Vector3(before_snap.x,before_snap.y,7.010000228881836),"scheduled Z snap preserves XY")
	check(int(torch["flags"])==0x20000,"material2 corners retain snap")
	check(runtime.light_records[0]["position"]==torch["position"]+Vector3(0,-0.5,1),"moving torch updates registered source light offset")
	material = 0
	runtime.update(0.0,empty_records)
	check(int(torch["flags"])==0,"release runs without matching tick")
	for frame: int in range(60):
		runtime.update(1.0/60.0,actors)
	check(runtime.torches.size()==1 and int(torch["frame"])==0,"lit area suppresses duplicates; ANIM_STILL does not cycle")
	check(runtime.tick==111,"native .1-game-second tick, 60 host frames advance10 ticks")
	runtime.enabled = false
	var state: int = runtime.rng_state
	runtime.update(1.0,actors)
	check(runtime.tick==111 and runtime.rng_state==state,"paused system does not advance")

	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	subject.set_process(false)
	await process_frame
	check(subject.torch_runtime!=null and subject.torch_runtime.region_records.size()==1,"scene imports actual horizon registry")
	check(subject.torch_runtime.frame_playback_mode==0,"source default mode used in main")
	var points: Array[Vector2i] = [Vector2i(1,15),Vector2i(2,15),Vector2i(2,16),Vector2i(1,16)]
	for point: Vector2i in points:
		check(subject.native_mark_corridor_cell(0,point) and subject.native_dig_apply_cell(0,point),"open source corridor fixture")
	var worker: Node3D = subject.dwarf_nodes[0]
	worker.position = Vector3(1.5,-16.5,14.5)
	var before: Dictionary = {}
	var inputs_valid: bool = true
	for key: String in subject.terrain_mesh_nodes:
		var node: MeshInstance3D = subject.terrain_mesh_nodes[key]
		var arrays: Array = node.mesh.surface_get_arrays(0)
		var collision: CollisionShape3D = node.get_node_or_null("NativeGroundCollision/CollisionShape3D") as CollisionShape3D
		before[key] = {"vertices":arrays[Mesh.ARRAY_VERTEX],"colors":arrays[Mesh.ARRAY_COLOR],
			"collision":collision.shape if collision != null else null,"node":node}
		inputs_valid = inputs_valid and arrays[Mesh.ARRAY_VERTEX].size()==subject.terrain_lighting_inputs[key]["points"].size()
	check(inputs_valid,"lighting cache corresponds to committed source vertices")
	await _capture(subject,"before.png")
	var source_lights: int = subject.source_profile.terrain_lights.size()
	# Worker source ordinal1106 mod4=2; eligible native ticks are25,41,...
	subject.torch_runtime.tick = 25
	var started: int = Time.get_ticks_usec()
	for pass_index: int in range(3):
		subject._update_automatic_torches(0.0)
	var creation_ms: float = float(Time.get_ticks_usec()-started)/1000.0
	check(subject.torch_runtime.torches.size()==1 and subject.torch_nodes.size()==1,"source candidates spawn real torch in excavated corridor")
	check(subject.source_profile.terrain_lights.size()==source_lights+1,"source vertex light registered once")
	check(subject.torch_terrain_lighting_queue.is_empty(),"torch activation leaves terrain meshes untouched")
	var terrain_material: ShaderMaterial = subject.source_profile.material_cache.values()[0] as ShaderMaterial
	check(int(terrain_material.get_shader_parameter("dynamic_torch_count"))==1,"new torch updates shared terrain shader light")
	var uncovered_material: ShaderMaterial = subject.source_profile.terrain_material(0,true,false,"Gnd_A01.tga")
	check(int(uncovered_material.get_shader_parameter("dynamic_torch_count"))==1,"new terrain material inherits active torch light")
	var torch_pool: Array = []
	var current_torch_light: Dictionary = subject.source_profile.dynamic_torch_lights[0]
	for light_index: int in range(9):
		torch_pool.append(current_torch_light.duplicate())
	subject.source_profile.set_dynamic_torch_lights(torch_pool)
	check(int(uncovered_material.get_shader_parameter("dynamic_torch_count"))==9,"ninth torch remains in runtime terrain pool")
	subject.source_profile.set_dynamic_torch_lights(subject._automatic_torch_lights())
	var geometry_preserved: bool = true
	var color_changes: int = 0
	for key: String in before:
		var node: MeshInstance3D = subject.terrain_mesh_nodes[key]
		var arrays: Array = node.mesh.surface_get_arrays(0)
		var collision: CollisionShape3D = node.get_node_or_null("NativeGroundCollision/CollisionShape3D") as CollisionShape3D
		geometry_preserved = geometry_preserved and node==before[key]["node"] \
			and arrays[Mesh.ARRAY_VERTEX]==before[key]["vertices"] \
			and (collision.shape if collision != null else null)==before[key]["collision"]
		if arrays[Mesh.ARRAY_COLOR]!=before[key]["colors"]:
			color_changes += 1
	check(geometry_preserved,"lighting preserves geometry, node identity and collision resources")
	check(color_changes==0,"shader light leaves static terrain vertex colors untouched")
	var total_vertices: int = 0
	for inputs: Dictionary in subject.terrain_lighting_inputs.values():
		total_vertices += inputs["points"].size()
	check(subject.torch_lighting_vertices==0 and total_vertices>0,"torch activation does not recompute terrain vertices")
	var record: Dictionary = subject.torch_runtime.torches[0]
	var visual_root: Node3D = subject.torch_nodes[int(record["id"])]
	check(visual_root.get_child(0).get_child_count()==subject.torch_meshes.size(),"original frame0 surfaces attached")
	check((subject.torch_meshes[0].surface_get_material(0) as StandardMaterial3D).albedo_texture!=null,"original torch texture imported")
	check(subject.flame_emitters.has(visual_root),"new corridor torch receives its source type2 emitter")
	for frame: int in range(64):
		subject._update_source_flames()
	var flame: Node3D = subject.flame_emitters[visual_root]
	var flame_state: Dictionary = flame.snapshot()
	check(int(flame_state["capacity"])==31 and int(flame_state["live"])>0 \
		and int(flame_state["live"])<=31 and int(flame_state["surfaces"])==1,"automatic torch emits fire within original31-particle capacity")
	check(flame.position==visual_root.position and flame.get_parent()==subject.scene_root,"emitter follows torch without inheriting compressed model depth")
	await _capture(subject,"after.png")
	var lighting_updates: int = subject.torch_lighting_updates
	for pass_index: int in range(30):
		subject._update_automatic_torches(0.0)
	check(subject.torch_nodes.size()==1 and subject.source_profile.terrain_lights.size()==source_lights+1,"no repeated creation in already lit corridor")
	check(subject.torch_lighting_updates==lighting_updates,"unchanged light does not recolor every object pass")
	check(subject.terrain_state.revision==4,"auto lighting never excavates terrain")
	print("AUTOMATIC_TORCH_SCENE color_buckets=%d recolored=%d vertices=%d/%d creation_ms=%.3f native_position=%s" % [color_changes,
		subject.torch_lighting_updates,subject.torch_lighting_vertices,total_vertices,creation_ms,record["position"]])
	subject.queue_free()
	await process_frame
	print("AUTOMATIC_TORCH_RUNTIME_SELF_TEST checks=%d failures=%d" % [checks,failures])
	quit(0 if failures==0 else 1)


func _capture(subject: Node3D, file: String) -> void:
	if not OS.get_cmdline_user_args().has("--capture-torches"):
		return
	var directory: String = ProjectSettings.globalize_path("res://").path_join("../docs/reverse-engineering/automatic-torches-runtime-2026-11-18")
	DirAccess.make_dir_recursive_absolute(directory)
	subject.focus = subject.scene_root.to_global(Vector3(2.2,-15.4,12.5))
	subject.distance = 7.0
	subject._update_camera()
	await process_frame
	await RenderingServer.frame_post_draw
	check(root.get_texture().get_image().save_png(directory.path_join(file))==OK,"save " + file)
