## Hamster clip geometry: the 28 original clips of the hamster.3db package.
##
## The hamster is a separate 3DB package, so its frames are exported on their
## own (res://models/native_hamster_clips.json) instead of being mixed into the
## dwarf locomotion export.
##
## Sources (original install):
##   data/3db/hamster.3db                           - the package
##   data/Scripts/classes/characters/hamster.tcl   - the aliases and animsets
##
## The mesh contract is the project's one: normalized source points scaled by
## NATIVE_POINT_SCALE and packed by OBJECT_WORLD_SCALE, normals resolved through
## native_model_material (the legacy 'brightness' field holds the sphere.dat
## normal index).
extends RefCounted

const DATA_PATH := "res://models/native_hamster_clips.json"
const NATIVE_POINT_SCALE := 16384.0
const OBJECT_WORLD_SCALE := 0.005
const TEXTURE_DIRECTORY := "res://textures/models"

const MODEL_NORMALS = preload("res://scripts/native_model_material.gd")

static var _table: Dictionary = {}
static var _mesh_cache: Dictionary = {}
static var _texture_cache: Dictionary = {}
static var _normals: RefCounted = null


static func _load_table() -> Dictionary:
	if not _table.is_empty():
		return _table
	if not FileAccess.file_exists(DATA_PATH):
		push_error("[native_hamster_clips] missing %s" % DATA_PATH)
		return _table
	var file := FileAccess.open(DATA_PATH, FileAccess.READ)
	if file == null:
		push_error("[native_hamster_clips] cannot open %s" % DATA_PATH)
		return _table
	var parsed: Variant = JSON.parse_string(file.get_as_text())
	file.close()
	if typeof(parsed) != TYPE_DICTIONARY:
		push_error("[native_hamster_clips] malformed table")
		return _table
	_table = parsed
	return _table


static func _normalizer() -> RefCounted:
	if _normals == null:
		_normals = MODEL_NORMALS.new()
		(_normals as RefCounted).call("load_fixture")
	return _normals


## All clip names of the package.
static func clip_names() -> Array:
	var table := _load_table()
	var clips: Dictionary = table.get("clips", {})
	return clips.keys()


static func has_clip(clip_name: String) -> bool:
	var table := _load_table()
	var clips: Dictionary = table.get("clips", {})
	return clips.has(clip_name)


## Number of frames of a clip, or -1 when the clip is unknown.
static func frame_count(clip_name: String) -> int:
	var table := _load_table()
	var clips: Dictionary = table.get("clips", {})
	if not clips.has(clip_name):
		return -1
	return int((clips[clip_name] as Dictionary).get("frame_count", -1))


## Frame rate the export was written with (adapter value, not a native constant).
static func adapter_fps(clip_name: String) -> float:
	var table := _load_table()
	var clips: Dictionary = table.get("clips", {})
	if not clips.has(clip_name):
		return 12.0
	return float((clips[clip_name] as Dictionary).get("adapter_fps", 12.0))


## The raw frame record of a clip.
static func frame(clip_name: String, frame_index: int) -> Dictionary:
	var table := _load_table()
	var clips: Dictionary = table.get("clips", {})
	if not clips.has(clip_name):
		return {}
	var clip: Dictionary = clips[clip_name]
	var frames: Array = clip.get("frames", [])
	if frame_index < 0 or frame_index >= frames.size():
		return {}
	return frames[frame_index]


## Meshes of one frame, built once and cached.
##
## Returns an Array of ArrayMesh, one per surface of the frame.
static func frame_meshes(clip_name: String, frame_index: int) -> Array:
	var key := "%s:%d" % [clip_name, frame_index]
	if _mesh_cache.has(key):
		return _mesh_cache[key]
	var record := frame(clip_name, frame_index)
	if record.is_empty():
		_mesh_cache[key] = []
		return _mesh_cache[key]
	var meshes := build_frame_meshes(record)
	_mesh_cache[key] = meshes
	return meshes


## Build the meshes of a frame record (the project's model mesh contract).
static func build_frame_meshes(record: Dictionary) -> Array:
	var meshes: Array = []
	var surfaces: Array = record.get("surfaces", [])
	for source_surface: Dictionary in surfaces:
		var vertices: Array = source_surface.get("points", [])
		var uvs: Array = source_surface.get("uvs", [])
		var indices: Array = source_surface.get("triangles", [])
		if vertices.is_empty() or uvs.is_empty() or indices.is_empty():
			continue
		var source_normals: PackedVector3Array = PackedVector3Array()
		var normalizer := _normalizer()
		if normalizer != null:
			source_normals = (normalizer as RefCounted).call("godot_local_normals", source_surface)
		var surface_tool := SurfaceTool.new()
		surface_tool.begin(Mesh.PRIMITIVE_TRIANGLES)
		for index_value: Variant in indices:
			var index: int = int(index_value)
			if index >= vertices.size() or index >= uvs.size():
				continue
			var raw_point: Array = vertices[index]
			var uv: Array = uvs[index]
			surface_tool.set_uv(Vector2(float(uv[0]), float(uv[1])))
			if not source_normals.is_empty() and index < source_normals.size():
				surface_tool.set_normal(source_normals[index])
			var native_point := Vector3(float(raw_point[0]) - 0.5,
				-(float(raw_point[1]) - 0.5), float(raw_point[2]) - 0.5) * NATIVE_POINT_SCALE
			surface_tool.add_vertex(native_point * OBJECT_WORLD_SCALE)
		if source_normals.is_empty():
			surface_tool.generate_normals()
		var mesh := surface_tool.commit()
		var material := StandardMaterial3D.new()
		material.cull_mode = BaseMaterial3D.CULL_DISABLED
		material.roughness = 0.95
		material.vertex_color_use_as_albedo = false
		var texture_path := _texture_path(source_surface)
		var texture := _texture(texture_path)
		if texture != null:
			material.albedo_texture = texture
			var alpha_range: Array = source_surface.get("alpha_range", [255, 255])
			if alpha_range.size() >= 2 and int(alpha_range[0]) < 128:
				material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA_SCISSOR
				material.alpha_scissor_threshold = 0.35
		mesh.surface_set_material(0, material)
		meshes.append(mesh)
	return meshes


static func _texture_path(source_surface: Dictionary) -> String:
	var explicit_path := String(source_surface.get("texture_res_path", ""))
	if explicit_path != "":
		return explicit_path
	return TEXTURE_DIRECTORY + "/" + String(source_surface.get("texture", ""))


static func _texture(path: String) -> Texture2D:
	if path == "":
		return null
	if _texture_cache.has(path):
		return _texture_cache[path]
	var texture: Texture2D = null
	if ResourceLoader.exists(path):
		texture = load(path) as Texture2D
	elif FileAccess.file_exists(path):
		texture = ImageTexture.create_from_image(Image.load_from_file(path))
	_texture_cache[path] = texture
	return texture
