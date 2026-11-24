extends Node3D
## Source type-2 rules, local bounded pool. Caller owns clock, pose and projection.
## No global class registration and no automatic _process clock.

const HOST_SHADER: String = """
shader_type spatial;
render_mode unshaded, cull_disabled, depth_draw_never, blend_mix, fog_disabled;
uniform sampler2D atlas : source_color, filter_linear, repeat_disable;
uniform float host_gamma = 1.0;
void fragment() {
	vec4 texel = texture(atlas, UV);
	vec3 secondary = vec3(UV2.x, UV2.x, UV2.y);
	ALBEDO = pow(clamp(texel.rgb * COLOR.rgb + secondary, vec3(0.0), vec3(1.0)), vec3(1.0 / host_gamma));
	ALPHA = texel.a;
}
"""

# All original type-2 fires use the same atlas. Loading it for every corridor
# torch caused a visible activation hitch on mobile.
static var _atlas_texture_cache: Dictionary = {}

var _source: Dictionary = {}
var _constants: Dictionary = {}
var _particles: Array[Dictionary] = []
var _rng: int = 1
var _drift: Vector3 = Vector3.ZERO
var _mapping: Transform3D = Transform3D.IDENTITY
var _half_size: Vector2 = Vector2.ZERO
var _capacity: int = 0
var _mesh: ImmediateMesh = null
var _draw: MeshInstance3D = null
var _material: ShaderMaterial = null
var _ticks: int = 0
var _births: int = 0

func configure(source: Dictionary, native_to_local: Transform3D, quad_half_extent: Vector2, seed_value: int = 1, host_gamma: float = 1.0) -> Error:
	# Validation is transactional: a bad source leaves a working emitter untouched.
	if source.get("schema", "") != "diggles.native_flame.v1":
		return ERR_INVALID_DATA
	if not source.get("emitter", {}) is Dictionary or not source.get("particle", {}) is Dictionary:
		return ERR_INVALID_DATA
	var emitter: Dictionary = source.get("emitter", {})
	var particle: Dictionary = source.get("particle", {})
	if int(emitter.get("type", -1)) != 2 or int(emitter.get("pool_slots", 0)) < 2 \
			or int(emitter.get("births_per_tick",0))<1 or int(emitter.get("reserved_slots",0))!=1 \
			or int(particle.get("lifetime_ticks", 0)) != 32:
		return ERR_INVALID_DATA
	if quad_half_extent.x <= 0.0 or quad_half_extent.y <= 0.0 or not quad_half_extent.is_finite() or not is_finite(host_gamma) or host_gamma <= 0.0:
		return ERR_INVALID_PARAMETER
	var constants: Dictionary = source.get("constants", {})
	for key: String in ["velocity_xz_divisor", "velocity_y_divisor", "position_y_divisor", "rise_bias", "center_weight", "particle_weight", "weight_divisor", "fade_start", "fade_scale", "width_limit", "kick_bias", "kick_multiplier", "kick_scale", "drift_xz_divisor", "drift_y_divisor", "drift_damping", "rotation_rate", "velocity_drift_scale"]:
		if not constants.get(key) is Dictionary or not is_finite(float(constants[key].get("value", NAN))):
			return ERR_INVALID_DATA
	var atlas: Dictionary = source.get("atlas", {})
	var resource_path: String = str(atlas.get("resource", ""))
	if not FileAccess.file_exists(resource_path):
		return ERR_FILE_NOT_FOUND
	var atlas_texture: Texture2D = _atlas_texture_cache.get(resource_path) as Texture2D
	if atlas_texture == null:
		# Load the imported texture resource instead of a raw Image. Raw image
		# loading works in the editor but is omitted from exported packs.
		atlas_texture = load(resource_path) as Texture2D
		if atlas_texture == null or atlas_texture.get_width() != 128 or atlas_texture.get_height() != 128:
			return ERR_INVALID_DATA
		_atlas_texture_cache[resource_path] = atlas_texture
	clear()
	_source = source.duplicate(true)
	_constants = constants.duplicate(true)
	_mapping = native_to_local
	_half_size = quad_half_extent
	_capacity = int(emitter["pool_slots"]) - int(emitter["reserved_slots"])
	_rng = seed_value & 0xffffffff
	var shader: Shader = Shader.new()
	shader.code = HOST_SHADER
	_material = ShaderMaterial.new()
	_material.shader = shader
	_material.set_shader_parameter("atlas", atlas_texture)
	_material.set_shader_parameter("host_gamma", host_gamma)
	_mesh = ImmediateMesh.new()
	_draw = MeshInstance3D.new()
	_draw.name = "NativeFlameQuads"
	_draw.mesh = _mesh
	add_child(_draw)
	return OK


static func projection_half_extents(source: Dictionary, projection: Projection) -> Vector2:
	var reference: Dictionary = source["projection"]
	return Vector2(2.0*float(reference["multiplier"])/float(reference["reference_width"])/absf(projection.x.x),
		2.0*float(reference["multiplier"])/float(reference["reference_height"])/absf(projection.y.y))


func set_projection(quad_half_extent: Vector2) -> void:
	if quad_half_extent.is_finite() and quad_half_extent.x>0 and quad_half_extent.y>0:
		_half_size = quad_half_extent

func clear() -> void:
	_particles.clear()
	_source.clear()
	_constants.clear()
	_drift = Vector3.ZERO
	_ticks = 0
	_births = 0
	_capacity = 0
	if _draw != null:
		remove_child(_draw)
		_draw.free()
	_draw = null
	_mesh = null
	_material = null

func _c(key: String) -> float:
	return float(_constants[key]["value"])

func _random_native() -> int:
	_rng = (_rng * 214013 + 2531011) & 0xffffffff
	return (_rng >> 16) & 32767

func _source_vector(value: Array) -> Vector3:
	return Vector3(float(value[0]), float(value[1]), float(value[2]))

func update_native_tick(emitting: bool, native_step: float) -> Error:
	## Exactly one original update, never a frame delta in guessed seconds.
	## emitting=false drains existing particles. Pause means do not call this.
	if _source.is_empty():
		return ERR_UNCONFIGURED
	if not is_finite(native_step) or native_step < 0.0:
		return ERR_INVALID_PARAMETER
	var origin: Vector3 = _source_vector(_source["emitter"]["offset"])
	var velocity: Vector3 = _source_vector(_source["emitter"]["velocity"])
	_drift.x = (_drift.x + float(_random_native() % 16 - 8) / _c("drift_xz_divisor")) * _c("drift_damping")
	_drift.y = (_drift.y + float(_random_native() % 16 - 8) / _c("drift_y_divisor")) * _c("drift_damping")
	_drift.z = (_drift.z + float(_random_native() % 16 - 8) / _c("drift_xz_divisor")) * _c("drift_damping")
	if emitting:
		for unused_birth: int in range(int(_source["emitter"]["births_per_tick"])):
			if _particles.size() < _capacity:
				_spawn(origin, velocity)
	for index: int in range(_particles.size()):
		var p: Dictionary = _particles[index]
		var age: int = int(p["age"])
		var point: Vector3 = p["point"]
		var motion: Vector3 = p["motion"]
		point += motion
		point.x = (origin.x * _c("center_weight") + point.x * _c("particle_weight")) / _c("weight_divisor")
		point.z = (origin.z * _c("center_weight") + point.z * _c("particle_weight")) / _c("weight_divisor")
		p["column"] = int((31 - int(age * age / 32.0)) / 4.0)
		p["angle"] = float(p["angle"]) + native_step * _c("rotation_rate")
		motion += _drift * _c("velocity_drift_scale") * native_step
		if age < 6:
			motion.y += (float(_random_native()) + _c("kick_bias")) * _c("kick_multiplier") * _c("kick_scale")
		var width: float = (_c("width_limit") - minf(absf(point.x - origin.x), _c("width_limit"))) * _c("center_weight")
		var red: float = clampf(255.0 - 20.0 * _fistp(float(clampi(16 - age, 0, 5)) * width), 0.0, 255.0)
		var dark: float = clampf(-20.0 * _fistp(float(clampi(16 - age, 0, 5)) * width), 0.0, 255.0)
		var blue: float = clampf(30.0 * _fistp(width), 0.0, 255.0)
		var fade: float = 1.0 - clampf((float(age) - _c("fade_start")) * _c("fade_scale"), 0.0, 1.0)
		p["diffuse"] = Color(_fistp(red * fade) / 255.0, _fistp(red * fade) / 255.0, _fistp(255.0 * fade) / 255.0, 1.0)
		p["secondary"] = Vector2(dark / 255.0, blue / 255.0)
		p["point"] = point
		p["motion"] = motion
		p["age"] = age + 1
	for index: int in range(_particles.size() - 1, -1, -1):
		if int(_particles[index]["age"]) >= int(_source["particle"]["lifetime_ticks"]):
			_particles.remove_at(index)
	_ticks += 1
	return OK

func _spawn(origin: Vector3, velocity: Vector3) -> void:
	var angle: float = float(_random_native() % 360) / 180.0 * PI
	var radius: float = float(_random_native() % 100) / 850.0
	var height: float = float(_random_native() % 10) / _c("position_y_divisor")
	var point: Vector3 = origin + Vector3(sin(angle) * radius, height, cos(angle) * radius)
	var motion: Vector3 = velocity
	motion.x += float(_random_native() % 16 - 8) / _c("velocity_xz_divisor")
	motion.y -= float(_random_native() % 10) / _c("velocity_y_divisor") + _c("rise_bias")
	motion.z += float(_random_native() % 16 - 8) / _c("velocity_xz_divisor")
	point += velocity * float(_random_native()) / 32768.0
	var row: int = _random_native() % 3
	_particles.append({"point": point, "motion": motion, "row": row, "column": 7, "angle": 0.0, "age": 0, "diffuse": Color.WHITE, "secondary": Vector2.ZERO})
	_births += 1

func _fistp(value: float) -> float:
	# Explicit host assumption: x87 default round-to-nearest-even.
	var lower: float = floorf(value)
	var fraction: float = value - lower
	if fraction == 0.5:
		return lower if int(lower) % 2 == 0 else lower + 1.0
	return floorf(value + 0.5)

func update_visual(right_local: Vector3, up_local: Vector3) -> void:
	## Camera screen axes expressed in emitter-local space; no automatic camera lookup.
	if _mesh == null:
		return
	_mesh.clear_surfaces()
	if _particles.is_empty():
		return
	_mesh.surface_begin(Mesh.PRIMITIVE_TRIANGLES, _material)
	for p: Dictionary in _particles:
		var angle: float = float(p["angle"])
		var size_value: float = float(_source["particle"]["size"])
		# 0x497df5..0x4981de: source corners are a rotated diamond,
		# not the usual axis-aligned Godot billboard rectangle.
		var diagonal_a: Vector3 = (-right_local * sin(angle) * _half_size.x + up_local * cos(angle) * _half_size.y) * size_value
		var diagonal_b: Vector3 = (right_local * cos(angle) * _half_size.x + up_local * sin(angle) * _half_size.y) * size_value
		var center: Vector3 = _mapping * Vector3(p["point"])
		var corners: Array[Vector3] = [center + diagonal_a, center + diagonal_b, center - diagonal_b, center - diagonal_a]
		var grid: Array = _source["atlas"]["grid"]
		var step: Vector2 = Vector2(1.0/float(grid[0]),1.0/float(grid[1]))
		var uv: Vector2 = Vector2(float(p["column"]),float(p["row"]))*step
		var uvs: Array[Vector2] = [uv,uv+Vector2(step.x,0),uv+Vector2(0,step.y),uv+step]
		_mesh.surface_set_color(p["diffuse"])
		_mesh.surface_set_uv2(p["secondary"])
		for corner: int in [0, 1, 2, 1, 3, 2]:
			_mesh.surface_set_uv(uvs[corner])
			_mesh.surface_add_vertex(corners[corner])
	_mesh.surface_end()

func snapshot() -> Dictionary:
	## Read-only copies for host diagnostics and standalone tests.
	return {"configured": not _source.is_empty(), "ticks": _ticks, "births": _births, "live": _particles.size(), "capacity": _capacity, "particles": _particles.duplicate(true), "surfaces": _mesh.get_surface_count() if _mesh != null else 0}
