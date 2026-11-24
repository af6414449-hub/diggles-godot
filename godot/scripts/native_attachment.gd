extends RefCounted
## Native mesh-frame sockets. Coordinates match _build_model_meshes.
## A socket is a child of the same body transform as the frame's body meshes.
## No clock, interpolation, equip policy, scene mutation, or fitted offsets.

const DATA_PATH: String = "res://models/dwarf_attachments.json"
const POINT_SCALE: float = 16384.0
const RENDER_SCALE: float = 0.005
const SOURCE_Y: Basis = Basis(Vector3.RIGHT, Vector3.DOWN, Vector3.BACK)


static func read_data(path: String = DATA_PATH) -> Dictionary:
	var raw: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	if not raw is Dictionary:
		return {}
	var data: Dictionary = raw
	if str(data.get("schema", "")) != "diggles.native_attachments.v1":
		return {}
	return data


static func vector(values: Array) -> Vector3:
	return Vector3(float(values[0]), float(values[1]), float(values[2]))


static func sample(data: Dictionary, model_key: String, clip: String,
		frame_index: int, slot: int) -> Dictionary:
	var models: Dictionary = data.get("models", {})
	var model: Dictionary = models.get(model_key, {})
	var clips: Dictionary = model.get("clips", {})
	var sequence: Dictionary = clips.get(clip, {})
	var indices: Array = sequence.get("mesh_indices", [])
	if frame_index < 0 or frame_index >= indices.size():
		return {"ok": false, "reason": "missing model/clip or frame outside sequence"}
	var mesh_index: int = int(indices[frame_index])
	var meshes: Dictionary = model.get("meshes", {})
	var mesh: Dictionary = meshes.get(str(mesh_index), {})
	var slots: Dictionary = mesh.get("slots", {})
	if not slots.has(str(slot)):
		return {"ok": false, "reason": "slot not exported"}
	var socket: Dictionary = slots[str(slot)]
	var columns: Array = socket["basis_columns"]
	var basis: Basis = Basis(vector(columns[0]), vector(columns[1]), vector(columns[2]))
	return {"ok": true, "mesh_index": mesh_index, "record_index": int(socket["record_index"]),
		"source": socket, "transform": Transform3D(basis, vector(socket["origin_render"]))}


static func native_rotation(euler_radians: Vector3) -> Basis:
	# Transpose of EXE row Rz*Rx*Ry, then source Y reflection.
	var transposed_row: Basis = Basis(Vector3.UP, -euler_radians.y) \
		* Basis(Vector3.RIGHT, -euler_radians.x) \
		* Basis(Vector3.BACK, -euler_radians.z)
	return SOURCE_Y * transposed_row * SOURCE_Y


static func body_transform(native_position: Vector3, native_euler: Vector3,
		render_depth_scale: float = 0.5) -> Transform3D:
	# For an independent linked object beneath the common logical scene root.
	# For an attachment beneath an existing body root, use sample.transform alone.
	assert(render_depth_scale > 0.0)
	var unpack_depth: Basis = Basis(Vector3.RIGHT, Vector3.UP,
		Vector3(0.0, 0.0, 1.0 / render_depth_scale))
	return Transform3D(unpack_depth * native_rotation(native_euler), SOURCE_Y * native_position)


static func logical_world_transform(local_socket: Transform3D, native_position: Vector3,
		native_euler: Vector3, render_depth_scale: float = 0.5) -> Transform3D:
	return body_transform(native_position, native_euler, render_depth_scale) * local_socket


static func mesh_point(normalized: Array) -> Vector3:
	# Same point contract as multiplayer_test._build_model_meshes, no bounds offset.
	return SOURCE_Y * (vector(normalized) - Vector3(0.5, 0.5, 0.5)) * POINT_SCALE * RENDER_SCALE


static func decode_textures(data: Dictionary) -> Dictionary:
	var result: Dictionary = {}
	var textures: Dictionary = data.get("textures", {})
	for texture_name: String in textures:
		var record: Dictionary = textures[texture_name]
		var source_image: Image = Image.new()
		var error: Error = source_image.load_tga_from_buffer(
			Marshalls.base64_to_raw(str(record["tga_base64"])))
		if error == OK:
			result[texture_name] = ImageTexture.create_from_image(source_image)
	return result


static func build_meshes(frame: Dictionary, textures: Dictionary = {}) -> Array[ArrayMesh]:
	# Optional standalone asset builder; surfaces can also go directly to the
	# existing _build_model_meshes. Embedded textures require decode_textures().
	var result: Array[ArrayMesh] = []
	var surfaces: Array = frame.get("surfaces", [])
	for surface: Dictionary in surfaces:
		var points: Array = surface["points"]
		var uvs: Array = surface["uvs"]
		var indices: Array = surface["triangles"]
		if indices.is_empty() or indices.size() % 3 != 0:
			return []
		var builder: SurfaceTool = SurfaceTool.new()
		builder.begin(Mesh.PRIMITIVE_TRIANGLES)
		for raw_index: Variant in indices:
			var index: int = int(raw_index)
			if index < 0 or index >= points.size() or index >= uvs.size():
				return []
			var uv: Array = uvs[index]
			builder.set_uv(Vector2(float(uv[0]), float(uv[1])))
			builder.add_vertex(mesh_point(points[index]))
		builder.generate_normals()
		var mesh: ArrayMesh = builder.commit()
		var material: StandardMaterial3D = StandardMaterial3D.new()
		material.cull_mode = BaseMaterial3D.CULL_DISABLED
		material.roughness = 0.95
		material.albedo_texture = textures.get(str(surface["texture"])) as Texture2D
		var alpha_range: Array = surface.get("alpha_range", [255, 255])
		if int(alpha_range[0]) < 128:
			material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA_SCISSOR
			material.alpha_scissor_threshold = 0.35
		mesh.surface_set_material(0, material)
		result.append(mesh)
	return result
