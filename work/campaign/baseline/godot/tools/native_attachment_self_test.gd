extends SceneTree

const Attachment = preload("res://scripts/native_attachment.gd")
var failures: Array[String] = []
var sample_count: int = 0
var fixture_count: int = 0
var geometry_vertices: int = 0


func _initialize() -> void:
	var data: Dictionary = Attachment.read_data()
	check(not data.is_empty(), "manifest loaded")
	if data.is_empty():
		finish()
		return
	var models: Dictionary = data["models"]
	for model_key: String in models:
		var model: Dictionary = models[model_key]
		var clips: Dictionary = model["clips"]
		for clip_name: String in clips:
			var clip: Dictionary = clips[clip_name]
			var indices: Array = clip["mesh_indices"]
			for frame_index: int in range(indices.size()):
				for slot: int in [0, 1, 4]:
					var sampled: Dictionary = Attachment.sample(data, model_key, clip_name, frame_index, slot)
					check(bool(sampled["ok"]), "sample exists")
					if not bool(sampled["ok"]):
						continue
					var transform: Transform3D = sampled["transform"]
					var source: Dictionary = sampled["source"]
					check(int(sampled["mesh_index"]) == int(indices[frame_index]), "body frame identity")
					check(transform.is_finite(), "finite transform")
					check(absf(transform.basis.determinant() - 1.0) < 0.00001, "proper rotation")
					var position_u16: Array = source["position_u16"]
					var expected: Vector3 = Vector3(float(position_u16[0]) - 32768.0,
						-(float(position_u16[1]) - 32768.0), float(position_u16[2]) - 32768.0) * 0.00125
					near(transform.origin, expected, "packed source position")
					var euler: Vector3 = Attachment.vector(source["rotation_radians"])
					var rotation: Basis = Attachment.native_rotation(euler)
					near(transform.basis.x, rotation.x, "native X basis")
					near(transform.basis.y, rotation.y, "native Y basis")
					near(transform.basis.z, rotation.z, "native Z basis")
					sample_count += 1
	var fixtures: Array = data["fixtures"]
	for fixture: Dictionary in fixtures:
		var sampled: Dictionary = Attachment.sample(data, str(fixture["model"]), str(fixture["clip"]),
			int(fixture["frame"]), int(fixture["slot"]))
		var socket: Transform3D = sampled["transform"]
		var parent_euler: Vector3 = Attachment.vector(fixture["parent_euler"])
		var expected_render: Vector3 = Attachment.vector(fixture["expected_render"])
		var native_probe: Vector3 = Attachment.vector(fixture["probe_native"])
		var mapped_probe: Vector3 = Vector3(native_probe.x, -native_probe.y, native_probe.z) * 0.005
		var native_position: Vector3 = Vector3(3.25, -14.5, 2.0)
		var world: Transform3D = Attachment.logical_world_transform(socket, native_position, parent_euler)
		var logical: Vector3 = world * mapped_probe
		var rendered_displacement: Vector3 = logical - Vector3(native_position.x, -native_position.y, native_position.z)
		rendered_displacement.z *= 0.5
		near(rendered_displacement, expected_render, "independent native scalar fixture")
		fixture_count += 1
	# Fail closed: no wrap/clamp/identity fallback for absent source samples.
	for invalid: Array in [["missing", "gehen_loop", 0, 0], ["mann.3db::mann", "missing", 0, 0],
		["mann.3db::mann", "gehen_loop", -1, 0], ["mann.3db::mann", "gehen_loop", 999, 0],
		["mann.3db::mann", "gehen_loop", 0, 2]]:
		var sampled: Dictionary = Attachment.sample(data, str(invalid[0]), str(invalid[1]), int(invalid[2]), int(invalid[3]))
		check(not bool(sampled["ok"]) and not sampled.has("transform"), "invalid sample rejected")
	var textures: Dictionary = Attachment.decode_textures(data)
	check(textures.size() == 2, "two exact source textures decoded")
	var assets: Dictionary = data["assets"]
	check(assets.size() == 3, "pick plus male/female stone work hats")
	for asset_key: String in assets:
		var asset: Dictionary = assets[asset_key]
		var frames: Array = asset["frames"]
		check(frames.size() == 2, "both source asset frames exported")
		for frame: Dictionary in frames:
			var meshes: Array[ArrayMesh] = Attachment.build_meshes(frame, textures)
			var surfaces: Array = frame["surfaces"]
			check(meshes.size() == surfaces.size(), "asset surfaces built")
			for surface_index: int in range(meshes.size()):
				var arrays: Array = meshes[surface_index].surface_get_arrays(0)
				var vertices: PackedVector3Array = arrays[Mesh.ARRAY_VERTEX]
				var surface: Dictionary = surfaces[surface_index]
				var indices: Array = surface["triangles"]
				var points: Array = surface["points"]
				check(vertices.size() == indices.size(), "triangle stream complete")
				var material: StandardMaterial3D = meshes[surface_index].surface_get_material(0) as StandardMaterial3D
				check(material != null and material.albedo_texture != null, "source asset texture assigned")
				for vertex_index: int in range(vertices.size()):
					near(vertices[vertex_index], Attachment.mesh_point(points[int(indices[vertex_index])]), "mesh point contract")
				geometry_vertices += vertices.size()
	finish()


func check(condition: bool, message: String) -> void:
	if not condition and failures.size() < 30:
		failures.append(message)


func near(actual: Vector3, expected: Vector3, message: String) -> void:
	check(actual.distance_to(expected) < 0.00002, "%s: %s != %s" % [message, actual, expected])


func finish() -> void:
	print(JSON.stringify({"status": "NATIVE_ATTACHMENT_SELF_TEST_OK" if failures.is_empty() else "NATIVE_ATTACHMENT_SELF_TEST_FAILED",
		"samples": sample_count, "scalar_fixtures": fixture_count,
		"geometry_vertices": geometry_vertices, "failures": failures}))
	quit(0 if failures.is_empty() else 1)
