extends SceneTree
## Diagnostic probe for the automatic-torch terrain lighting regression.
##
## Reproduces automatic torches in separate excavated chunks (including ones far
## from the start cave), then compares, for the real terrain vertex nearest to
## each torch, the contribution the terrain shader actually computes against the
## contribution the production CPU illumination equation produces.
##
## Usage:
##   godot --headless --path <project> --script res://tools/torch_regression_probe.gd

const TERRAIN_ILLUMINATION: Script = preload("res://scripts/native_terrain_illumination.gd")

var subject: Node3D = null
var created: Array[Dictionary] = []


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	subject = load("res://scenes/multiplayer_test.tscn").instantiate() as Node3D
	subject.extended_world = false
	root.add_child(subject)
	subject.set_process(false)
	await process_frame

	_emit("PROBE_ENV use_native_diffuse=%s template_offset=%s static_lights=%d materials=%d meshes=%d" % [
		str(subject.source_profile.use_native_diffuse), str(subject.native_world.template_offset),
		subject.source_profile.terrain_lights.size(), subject.source_profile.material_cache.size(),
		subject.terrain_mesh_nodes.size()])
	_emit("PROBE_MATERIAL_SUMMARY stage=BEFORE shader_pipeline=%d shader_detail=%d count_values=%s" % [
		_count_shader_materials("res://shaders/native_terrain_pipeline.gdshader"),
		_count_shader_materials("res://shaders/native_terrain_detail.gdshader"),
		str(_count_histogram())])

	var anchors: Array[Vector2i] = [
		Vector2i(1,15), Vector2i(1,3), Vector2i(1,7), Vector2i(1,11), Vector2i(1,19),
		Vector2i(9,19), Vector2i(13,3), Vector2i(17,19), Vector2i(21,3), Vector2i(25,19),
		Vector2i(29,3), Vector2i(33,19), Vector2i(37,3), Vector2i(37,7), Vector2i(37,11),
		Vector2i(37,15), Vector2i(41,3), Vector2i(41,11), Vector2i(41,19), Vector2i(5,15)]
	for anchor: Vector2i in anchors:
		if created.size() >= 9:
			break
		var block: Array[Vector2i] = [anchor, anchor + Vector2i.RIGHT,
			anchor + Vector2i.DOWN, anchor + Vector2i.ONE]
		var dug: int = 0
		for point: Vector2i in block:
			if subject.native_mark_corridor_cell(0, point) and subject.native_dig_apply_cell(0, point):
				dug += 1
		if dug < 3:
			continue
		var record: Dictionary = _spawn_torch_at(anchor)
		if record.is_empty():
			continue
		created.append(record)

	_emit("PROBE_TORCH_COUNT created=%d runtime_torches=%d terrain_lights=%d" % [
		created.size(), subject.torch_runtime.torches.size(), subject.source_profile.terrain_lights.size()])
	_emit("PROBE_MATERIAL_SUMMARY stage=AFTER shader_pipeline=%d shader_detail=%d count_values=%s" % [
		_count_shader_materials("res://shaders/native_terrain_pipeline.gdshader"),
		_count_shader_materials("res://shaders/native_terrain_detail.gdshader"),
		str(_count_histogram())])

	for record: Dictionary in created:
		_dump_torch(record)
	for record: Dictionary in created:
		_dump_vertex_evidence(record)

	subject.queue_free()
	await process_frame
	_emit("PROBE_DONE")
	quit(0)


func _emit(line: String) -> void:
	print(line)


func _count_shader_materials(path: String) -> int:
	var total: int = 0
	for key: String in subject.source_profile.material_cache.keys():
		var material: ShaderMaterial = subject.source_profile.material_cache[key] as ShaderMaterial
		if material.shader != null and material.shader.resource_path == path:
			total += 1
	return total


func _count_histogram() -> Dictionary:
	var histogram: Dictionary = {}
	for key: String in subject.source_profile.material_cache.keys():
		var material: ShaderMaterial = subject.source_profile.material_cache[key] as ShaderMaterial
		var count: int = int(material.get_shader_parameter("dynamic_torch_count"))
		histogram[count] = int(histogram.get(count, 0)) + 1
	return histogram


func _spawn_torch_at(anchor: Vector2i) -> Dictionary:
	# The native queue deduplicates candidates closer than 10 source units, so a
	# stale entry would swallow the next attempt.
	subject.torch_runtime.queue.clear()
	var worker: Node3D = subject.dwarf_nodes[0]
	worker.position = Vector3(float(anchor.x) + 0.5, -(float(anchor.y) + 0.5), 14.0)
	var actor_id: int = int(worker.get_meta("autolight_host_id"))
	var before_count: int = subject.torch_runtime.torches.size()
	# AUTO.scheduled: tick > 10, tick % 4 == 1, (tick >> 2) % 4 == actor_id % 4.
	subject.torch_runtime.tick = 1 + 4 * (actor_id % 4) + 16
	for pass_index: int in range(3):
		subject._update_automatic_torches(0.0)
	if subject.torch_runtime.torches.size() <= before_count:
		return {}
	var torch: Dictionary = subject.torch_runtime.torches[subject.torch_runtime.torches.size() - 1]
	var source: Vector3 = torch["position"]
	var local: Vector3 = subject.native_world.to_local(source)
	return {"id": int(torch["id"]), "source": source, "local": local,
		"chunk": Vector2i(floori(local.x / 8.0), floori(local.y / 8.0)),
		"light_index": int(torch["light_index"])}


func _dump_torch(record: Dictionary) -> void:
	var id: int = int(record["id"])
	var light_index: int = int(record["light_index"])
	var terrain_lights: Array = subject.source_profile.terrain_lights
	var light: Dictionary = terrain_lights[light_index]
	var local: Vector3 = record["local"]
	var source: Vector3 = record["source"]
	_emit("PROBE_TORCH id=%d chunk=%s source=%s local=%s range=%s color=%s terrain_lights_index=%d baked_excluded=%s" % [
		id, str(record["chunk"]), str(source), str(local), str(light["range"]), str(light["color"]),
		light_index, str(not subject._terrain_baked_lights().has(light))])
	# Which uniform slot carries this torch, and does every material carry it.
	var slots_found: Array[int] = []
	var pipeline_materials: int = 0
	var detail_materials: int = 0
	var materials_with_torch: int = 0
	var counts: Array[int] = []
	for key: String in subject.source_profile.material_cache.keys():
		var material: ShaderMaterial = subject.source_profile.material_cache[key] as ShaderMaterial
		if material.shader == null:
			continue
		if material.shader.resource_path == "res://shaders/native_terrain_pipeline.gdshader":
			pipeline_materials += 1
		else:
			detail_materials += 1
		var count: int = int(material.get_shader_parameter("dynamic_torch_count"))
		counts.append(count)
		var positions: PackedVector4Array = material.get_shader_parameter("dynamic_torch_position_range")
		var slot: int = -1
		for index: int in range(mini(count, positions.size())):
			var value: Vector3 = Vector3(positions[index].x, positions[index].y, positions[index].z)
			if value.distance_to(Vector3(light["position"])) < 0.0001:
				slot = index
		if slot >= 0:
			materials_with_torch += 1
			if not slots_found.has(slot):
				slots_found.append(slot)
	_emit("PROBE_TORCH id=%d uniform_slot=%s materials_pipeline=%d materials_detail=%d materials_holding_torch=%d counts=%s" % [
		id, str(slots_found), pipeline_materials, detail_materials, materials_with_torch, str(counts)])


func _uniform_light_colour(light_position: Vector3) -> Vector3:
	# Read the colour the GPU actually receives, straight from the uniform that
	# native_scene_profile.gd wrote onto the real terrain material.
	for key: String in subject.source_profile.material_cache.keys():
		var material: ShaderMaterial = subject.source_profile.material_cache[key] as ShaderMaterial
		var count: int = int(material.get_shader_parameter("dynamic_torch_count"))
		var positions: PackedVector4Array = material.get_shader_parameter("dynamic_torch_position_range")
		var colors: PackedVector4Array = material.get_shader_parameter("dynamic_torch_color")
		for index: int in range(mini(count, mini(positions.size(), colors.size()))):
			var value: Vector3 = Vector3(positions[index].x, positions[index].y, positions[index].z)
			if value.distance_to(light_position) < 0.0001:
				return Vector3(colors[index].x, colors[index].y, colors[index].z)
	return Vector3.ZERO


func _dump_vertex_evidence(record: Dictionary) -> void:
	var id: int = int(record["id"])
	var local: Vector3 = record["local"]
	var light_index: int = int(record["light_index"])
	var light: Dictionary = subject.source_profile.terrain_lights[light_index]
	var constants: Dictionary = subject.source_profile.terrain_render["constants"]
	# Locate the real terrain vertex nearest to the torch.
	var best_key: String = ""
	var best_index: int = -1
	var best_distance: float = INF
	for key: String in subject.terrain_mesh_nodes.keys():
		var node: MeshInstance3D = subject.terrain_mesh_nodes[key] as MeshInstance3D
		var arrays: Array = node.mesh.surface_get_arrays(0)
		var vertices: PackedVector3Array = arrays[Mesh.ARRAY_VERTEX]
		for index: int in range(vertices.size()):
			var vertex: Vector3 = vertices[index]
			var distance: float = Vector2(vertex.x - local.x, -vertex.y - local.y).length()
			if distance < best_distance:
				best_distance = distance
				best_index = index
				best_key = key
	if best_index < 0:
		_emit("PROBE_VERTEX id=%d NO_VERTEX" % id)
		return
	var node: MeshInstance3D = subject.terrain_mesh_nodes[best_key] as MeshInstance3D
	var arrays: Array = node.mesh.surface_get_arrays(0)
	var vertices: PackedVector3Array = arrays[Mesh.ARRAY_VERTEX]
	var normals: PackedVector3Array = arrays[Mesh.ARRAY_NORMAL]
	var colors: PackedColorArray = arrays[Mesh.ARRAY_COLOR]
	var inputs: Dictionary = subject.terrain_lighting_inputs[best_key]
	var points: PackedVector3Array = inputs["points"]
	var cpu_normals: PackedVector3Array = inputs["normals"]
	var base: PackedInt32Array = inputs["base"]
	var vertex: Vector3 = vertices[best_index]
	var normal: Vector3 = normals[best_index]
	var baked_color: Color = colors[best_index]
	# Exactly the vertex stage of native_terrain_pipeline.gdshader.
	var source_point: Vector3 = Vector3(vertex.x, -vertex.y, (vertex.z + 14.0) * 0.5)
	var source_normal: Vector3 = Vector3(normal.x, -normal.y, normal.z * 2.0).normalized()
	var cpu_point: Vector3 = points[best_index]
	var cpu_normal: Vector3 = cpu_normals[best_index]
	var direction: Vector3 = Vector3(light["position"]) - source_point
	var squared: float = direction.length_squared()
	var radius: float = float(light["range"])
	var radius_squared: float = radius * radius
	var factor: float = 0.0
	if squared > 0.0 and squared < radius_squared:
		factor = exp(-2.0 * squared / radius_squared) * maxf(0.1, source_normal.dot(direction / sqrt(squared)))
	# Production CPU equation, called with and without this single torch.
	var with_torch: Color = TERRAIN_ILLUMINATION.channels(cpu_point, cpu_normal, int(base[best_index]),
		[light], constants)["diffuse"]
	var without_torch: Color = TERRAIN_ILLUMINATION.channels(cpu_point, cpu_normal, int(base[best_index]),
		[], constants)["diffuse"]
	var cpu_delta: Vector3 = Vector3(with_torch.r - without_torch.r,
		with_torch.g - without_torch.g, with_torch.b - without_torch.b)
	# The shader colour is whatever the material uniform actually carries.
	var uniform_colour: Vector3 = _uniform_light_colour(Vector3(light["position"]))
	var shader_delta: Vector3 = uniform_colour * factor
	var ratio: float = cpu_delta.length() / maxf(shader_delta.length(), 0.0000001)
	_emit("PROBE_VERTEX id=%d chunk_key=%s index=%d mesh_vertex=%s baked_color=%s" % [
		id, best_key, best_index, str(vertex), str(baked_color)])
	_emit("PROBE_VERTEX id=%d shader_source_point=%s cpu_source_point=%s space_match=%s" % [
		id, str(source_point), str(cpu_point), str(source_point.distance_to(cpu_point) < 0.0001)])
	_emit("PROBE_VERTEX id=%d light_pos=%s dist2=%.4f radius=%.2f factor=%.6f" % [
		id, str(Vector3(light["position"])), squared, radius, factor])
	_emit("PROBE_VERTEX id=%d uniform_colour=%s shader_delta=%s cpu_delta=%s ratio=%.4f" % [
		id, str(uniform_colour), str(shader_delta), str(cpu_delta), ratio])
	_emit("PROBE_VERTEX id=%d albedo_shader=%.6f albedo_cpu=%.6f albedo_no_torch=%.6f" % [
		id, minf(baked_color.r + shader_delta.x, 1.0), minf(baked_color.r + cpu_delta.x, 1.0), baked_color.r])
