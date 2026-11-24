extends SceneTree
## Regression self-test for automatic torch terrain lighting.
##
## The existing automatic_torch_runtime_self_test.gd only proves that the
## uniform plumbing works: it reads back dynamic_torch_count and the uniform
## slots. That test stays green while the light that reaches the GPU is scaled
## wrongly, so the terrain around a torch can stay completely dark.
##
## This test reproduces automatic torches in several separately excavated
## chunks, including one far from the start cave, and then checks the light
## that the real terrain material of the real terrain chunk actually receives:
##
##   1. the chunk material uses native_terrain_pipeline.gdshader;
##   2. the torch occupies a live uniform slot of that material;
##   3. the uniform colour equals the native light colour scaled by the shared
##      terrain gain (the exact value the source equation requires);
##   4. the albedo the shader vertex stage produces for the real terrain vertex
##      nearest the torch matches the production CPU illumination equation.
##
## Any of those failing means the torch exists but does not light the terrain.
##
## Usage:
##   godot --headless --path godot --script res://tools/torch_terrain_light_regression_self_test.gd

const TERRAIN_ILLUMINATION: Script = preload("res://scripts/native_terrain_illumination.gd")
const PIPELINE_SHADER: String = "res://shaders/native_terrain_pipeline.gdshader"
const COLOR_EPSILON: float = 0.000001
const ALBEDO_EPSILON: float = 3.0 / 255.0
const FAR_FROM_START_X: float = 32.0

var checks: int = 0
var failures: int = 0
var subject: Node3D = null
var torches: Array[Dictionary] = []


func _initialize() -> void:
	call_deferred("_run")


func check(condition: bool, message: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		push_error("TORCH_TERRAIN_LIGHT_FAILED " + message)


func _run() -> void:
	subject = load("res://scenes/multiplayer_test.tscn").instantiate() as Node3D
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	subject.set_process(false)
	await process_frame

	var constants: Dictionary = subject.source_profile.terrain_render["constants"]
	var gain: float = float(constants["gain"])

	# Excavate separated corridors and let the native placement rules spawn one
	# automatic torch per corridor.
	var anchors: Array[Vector2i] = [
		Vector2i(1,15), Vector2i(1,3), Vector2i(1,7), Vector2i(1,11), Vector2i(1,19),
		Vector2i(9,19), Vector2i(13,3), Vector2i(17,19), Vector2i(21,3), Vector2i(25,19),
		Vector2i(29,3), Vector2i(33,19), Vector2i(37,3), Vector2i(37,7), Vector2i(37,11),
		Vector2i(37,15), Vector2i(41,3), Vector2i(41,11), Vector2i(41,19), Vector2i(5,15)]
	for anchor: Vector2i in anchors:
		if torches.size() >= 9:
			break
		var far_so_far: int = 0
		for record: Dictionary in torches:
			if float(record["local"].x) >= FAR_FROM_START_X:
				far_so_far += 1
		if torches.size() >= 3 and far_so_far >= 1:
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
		if not record.is_empty():
			torches.append(record)

	check(torches.size() >= 3, "at least three automatic torches spawn in excavated corridors")
	var chunks: Dictionary = {}
	var far_count: int = 0
	for record: Dictionary in torches:
		chunks[record["chunk"]] = true
		if float(record["local"].x) >= FAR_FROM_START_X:
			far_count += 1
	check(chunks.size() >= 3, "automatic torches occupy three different excavated chunks")
	check(far_count >= 1, "at least one automatic torch spawns far from the start cave")

	for record: Dictionary in torches:
		_check_torch(record, constants, gain)

	subject.queue_free()
	await process_frame
	print("TORCH_TERRAIN_LIGHT_SELF_TEST torches=%d checks=%d failures=%d" % [
		torches.size(), checks, failures])
	quit(0 if failures == 0 else 1)


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


func _check_torch(record: Dictionary, constants: Dictionary, gain: float) -> void:
	var id: int = int(record["id"])
	var chunk: Vector2i = record["chunk"]
	var light: Dictionary = subject.source_profile.terrain_lights[int(record["light_index"])]
	var light_position: Vector3 = light["position"]
	var light_color: Vector3 = light["color"]

	# The material the real terrain chunk of this torch actually renders with.
	var material: ShaderMaterial = _chunk_material(chunk)
	check(material != null, "torch %d chunk %s has a terrain material" % [id, str(chunk)])
	if material == null:
		return
	check(material.shader != null and material.shader.resource_path == PIPELINE_SHADER,
		"torch %d chunk %s material uses %s" % [id, str(chunk), PIPELINE_SHADER])

	var count: int = int(material.get_shader_parameter("dynamic_torch_count"))
	var positions: PackedVector4Array = material.get_shader_parameter("dynamic_torch_position_range")
	var colors: PackedVector4Array = material.get_shader_parameter("dynamic_torch_color")
	check(count >= 1, "torch %d chunk %s material reports dynamic_torch_count %d" % [id, str(chunk), count])
	var slot: int = -1
	for index: int in range(mini(count, mini(positions.size(), colors.size()))):
		var value: Vector3 = Vector3(positions[index].x, positions[index].y, positions[index].z)
		if value.distance_to(light_position) < 0.0001:
			slot = index
	check(slot >= 0, "torch %d occupies a live uniform slot of chunk %s" % [id, str(chunk)])
	if slot < 0:
		return

	# The colour the GPU receives must be the native light colour scaled by the
	# shared terrain gain. A further 1/255 division makes the torch invisible.
	var uniform_color: Vector3 = Vector3(colors[slot].x, colors[slot].y, colors[slot].z)
	var expected_color: Vector3 = light_color * gain
	check(uniform_color.distance_to(expected_color) <= COLOR_EPSILON,
		"torch %d uniform colour %s equals native colour %s scaled by gain %f (got %s)" % [
			id, str(uniform_color), str(light_color), gain, str(uniform_color)])

	# End to end: the albedo the shader vertex stage produces for the real
	# terrain vertex nearest the torch must match the CPU illumination equation.
	var vertex_result: Dictionary = _nearest_vertex(chunk, Vector3(light_position))
	check(vertex_result.has("index"), "torch %d finds a terrain vertex in chunk %s" % [id, str(chunk)])
	if not vertex_result.has("index"):
		return
	var index: int = int(vertex_result["index"])
	var inputs: Dictionary = subject.terrain_lighting_inputs[vertex_result["key"]]
	var points: PackedVector3Array = inputs["points"]
	var normals: PackedVector3Array = inputs["normals"]
	var base: PackedInt32Array = inputs["base"]
	var cpu_point: Vector3 = points[index]
	var cpu_normal: Vector3 = normals[index]
	var vertex: Vector3 = vertex_result["vertex"]
	var normal: Vector3 = vertex_result["normal"]
	var baked: float = vertex_result["color"]

	# Exactly the vertex stage of native_terrain_pipeline.gdshader.
	var shader_point: Vector3 = Vector3(vertex.x, -vertex.y, (vertex.z + 14.0) * 0.5)
	var shader_normal: Vector3 = Vector3(normal.x, -normal.y, normal.z * 2.0).normalized()
	check(shader_point.distance_to(cpu_point) <= 0.0001,
		"torch %d shader vertex coordinates match the source point" % [id])

	var direction: Vector3 = light_position - shader_point
	var squared: float = direction.length_squared()
	var radius: float = float(light["range"])
	var factor: float = 0.0
	if squared > 0.0 and squared < radius * radius:
		factor = exp(-2.0 * squared / (radius * radius)) * maxf(0.1, shader_normal.dot(direction / sqrt(squared)))
	var shader_albedo: float = minf(baked + uniform_color.x * factor, 1.0)

	var with_torch: Color = TERRAIN_ILLUMINATION.channels(cpu_point, cpu_normal, int(base[index]),
		[light], constants)["diffuse"]
	var without_torch: Color = TERRAIN_ILLUMINATION.channels(cpu_point, cpu_normal, int(base[index]),
		[], constants)["diffuse"]
	var cpu_albedo: float = minf(without_torch.r + (with_torch.r - without_torch.r), 1.0)
	check(absf(shader_albedo - cpu_albedo) <= ALBEDO_EPSILON,
		"torch %d shader albedo %.6f matches the source equation %.6f (baked %.6f)" % [
			id, shader_albedo, cpu_albedo, baked])
	check(shader_albedo > baked + 0.01,
		"torch %d visibly lifts the terrain albedo above the baked value %.6f" % [id, baked])


func _chunk_material(chunk: Vector2i) -> ShaderMaterial:
	var suffix: String = ":%d:%d" % [chunk.x, chunk.y]
	for key: String in subject.terrain_mesh_nodes.keys():
		if not key.ends_with(suffix):
			continue
		var node: MeshInstance3D = subject.terrain_mesh_nodes[key] as MeshInstance3D
		if node.mesh.get_surface_count() == 0:
			continue
		return node.mesh.surface_get_material(0) as ShaderMaterial
	return null


func _nearest_vertex(chunk: Vector2i, light_position: Vector3) -> Dictionary:
	var suffix: String = ":%d:%d" % [chunk.x, chunk.y]
	var best: Dictionary = {}
	var best_distance: float = INF
	for key: String in subject.terrain_mesh_nodes.keys():
		if not key.ends_with(suffix):
			continue
		var node: MeshInstance3D = subject.terrain_mesh_nodes[key] as MeshInstance3D
		var arrays: Array = node.mesh.surface_get_arrays(0)
		var vertices: PackedVector3Array = arrays[Mesh.ARRAY_VERTEX]
		var normals: PackedVector3Array = arrays[Mesh.ARRAY_NORMAL]
		var colors: PackedColorArray = arrays[Mesh.ARRAY_COLOR]
		for index: int in range(vertices.size()):
			var vertex: Vector3 = vertices[index]
			var distance: float = Vector2(vertex.x - light_position.x, -vertex.y - light_position.y).length()
			if distance < best_distance:
				best_distance = distance
				best = {"key": key, "index": index, "vertex": vertex,
					"normal": normals[index], "color": colors[index].r}
	return best
