extends RefCounted
## Source model material primitives; deliberately no invented model light solver.
## The old exported `brightness` array contains sphere.dat normal indices.
## Supply original renderer diffuse/secondary separately to the stage shader.

var data: Dictionary = {}


func load_fixture(path: String = "res://models/native_model_material.json") -> bool:
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	if not decoded is Dictionary:
		return false
	if decoded.get("schema", "") != "diggles.model_material.v1":
		return false
	var table: Array = decoded.get("normal_table", [])
	if table.size() != 256:
		return false
	data = decoded
	return true


func source_normals(surface: Dictionary) -> PackedVector3Array:
	# Return source model coordinates. Apply the instance normal basis afterwards.
	# Accept both new explicit spelling and the unchanged legacy model export.
	var indices: Array = surface.get("normal_indices", surface.get("brightness", []))
	var points: Array = surface.get("points", [])
	var result: PackedVector3Array = PackedVector3Array()
	if data.is_empty() or indices.size() != points.size():
		return result
	for value: Variant in indices:
		var index: int = int(value)
		if float(value) != float(index) or index < 0 or index >= 256:
			return PackedVector3Array()
		var raw: Array = data["normal_table"][index]
		result.append(Vector3(float(raw[0]), float(raw[1]), float(raw[2])))
	return result


func godot_local_normals(surface: Dictionary) -> PackedVector3Array:
	# Same local reflection used by _build_model_meshes for points; no normalize
	# here: retain original float32 sphere entries for source arithmetic as well.
	var result: PackedVector3Array = source_normals(surface)
	for index: int in range(result.size()):
		result[index] = Vector3(result[index].x, -result[index].y, result[index].z)
	return result


static func rgb555_pre_visibility(packed: int, intensity: float, additive_rgb: Vector3i) -> Dictionary:
	# EXE 0x484CD0..0x484DD9 ONLY. Subsequent visibility/fog is NOT included.
	# x87 rounding mode was not captured; use explicit host ties-to-even.
	var scaled: float = clampf(intensity * 256.0, 0.0, 256.0)
	var lower: int = floori(scaled)
	var weight: int = lower
	if scaled - float(lower) > 0.5 or (scaled - float(lower) == 0.5 and (lower & 1) != 0):
		weight += 1
	var levels: Vector3i = Vector3i(((packed >> 10) & 31) * weight >> 5,
		((packed >> 5) & 31) * weight >> 5, (packed & 31) * weight >> 5) + additive_rgb
	levels = levels.clamp(Vector3i.ZERO, Vector3i(511, 511, 511))
	return {"diffuse": Color(float(mini(levels.x,255))/255.0,
		float(mini(levels.y,255))/255.0,float(mini(levels.z,255))/255.0),
		"secondary": Color(float(maxi(levels.x-255,0))/255.0,
		float(maxi(levels.y-255,0))/255.0,float(maxi(levels.z-255,0))/255.0)}


func single_texture_preview(texture: Texture2D, color_op: int) -> ShaderMaterial:
	# Explicit diagnostic program: stage0(texture,diffuse), stage1 disabled.
	# Do not claim this is the active original draw state without capturing it.
	if data.is_empty() or not color_op in [2,3,4,5,6,7,8,9,10,11]:
		return null
	var material: ShaderMaterial = ShaderMaterial.new()
	material.shader = load("res://shaders/native_model_material.gdshader") as Shader
	material.set_shader_parameter("albedo_texture", texture)
	material.set_shader_parameter("color_op", color_op)
	material.set_shader_parameter("native_gamma", float(data["gamma_defaults"]["gamma"]))
	material.set_shader_parameter("native_brightness", float(data["gamma_defaults"]["brightness"]))
	return material
