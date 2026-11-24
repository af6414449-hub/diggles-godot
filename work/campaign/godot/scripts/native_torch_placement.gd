extends RefCounted
## Pure, bounded translation of EXE 0x5CC202..0x5CC43B; native coordinates.
## Caller must already have passed the enclosing object-update gates.
## No creation policy, FOW, LOS, footprint, scene mutation or coordinate adapter.

const SNAP: int = 0x20000
const SNAP_BLOCKED: int = 0x4000
const Z_BIAS: float = 0.009999999776482582 # f32 at 0x736FE0
const RELEASE_Z: float = 0.019999999552965164 # f32 at 0x736FF0
const FRAME_SCALE: float = 0.004999999888241291 # f32 at 0x736FCC


## sample_xy MUST be native FISTP(f32(8*XY)), with the actual FPU mode.
## depth_at(Vector2i) returns the raw depth byte, or null if unavailable.
## bounds = (world+94, +98, +9C, +A0), in sample units.
## This stage does not decide whether the snap flag is subsequently released.
static func snap_step(native_position: Vector3, native_rotation: Vector3,
		flags: int, tick: int, object_id: int, sample_xy: Vector2i,
		bounds: Vector4i, depth_at: Callable) -> Dictionary:
	var result: Dictionary = {"status": "unchanged", "position": native_position,
		"rotation": native_rotation, "flags": flags, "sampled": false}
	if (flags & SNAP) == 0 or (flags & SNAP_BLOCKED) != 0:
		return result
	if tick <= 100 or ((object_id ^ tick) & 15) != 0:
		return result
	if sample_xy.x < bounds.x + 4 or sample_xy.x >= bounds.z - 4 \
			or sample_xy.y < bounds.y + 4 or sample_xy.y >= bounds.w - 4:
		return result
	var minimum: int = 255
	for offset: Vector2i in [Vector2i.ZERO, Vector2i(-2, 0), Vector2i(2, 0),
			Vector2i(0, -2), Vector2i(0, 2)]:
		var raw: Variant = depth_at.call(sample_xy + offset)
		if not raw is int or int(raw) < 0 or int(raw) > 255:
			result["status"] = "deferred"
			result["reason"] = "missing raw depth byte"
			return result
		minimum = mini(minimum, int(raw))
	var snapped_position: Vector3 = native_position
	snapped_position.z = _f32(float(minimum) + Z_BIAS)
	result["position"] = snapped_position
	result["sampled"] = true
	result["status"] = "snapped"
	return result


## Separate native 0x5CC388..0x5CC431, run even when snap_step did not sample.
## native_rect is RAW (left, top, right, bottom) from 0x5CB250, NOT Rect2i size.
## map_bounds = (world+84, +88, +8C, +90), in coarse map units.
## cell_flags(Vector2i) returns byte [0x592F10(x,y)+0x18], or null.
## Only a null rect means missing data; (-1,-1,-1,-1) is native invalid rect.
static func release_step(native_z: float, flags: int, class_type: int,
		native_rect: Variant, map_bounds: Vector4i, cell_flags: Callable) -> Dictionary:
	var result: Dictionary = {"status": "unchanged", "flags": flags}
	if (flags & SNAP) == 0 or (flags & SNAP_BLOCKED) != 0 or class_type != 0:
		return result
	if native_z < RELEASE_Z:
		result["flags"] = flags & ~SNAP
		result["status"] = "released"
		return result
	if not native_rect is Vector4i:
		return {"status": "deferred", "flags": flags,
			"reason": "missing current animation frame rect (0x5CB250)"}
	var rect: Vector4i = native_rect
	if rect.y < map_bounds.y or rect.w >= map_bounds.w \
			or rect.x < map_bounds.x or rect.z >= map_bounds.z:
		return result
	for corner: Vector2i in [Vector2i(rect.x, rect.y), Vector2i(rect.x, rect.w),
			Vector2i(rect.z, rect.y), Vector2i(rect.z, rect.w)]:
		var raw: Variant = cell_flags.call(corner)
		if not raw is int:
			return {"status": "deferred", "flags": flags,
				"reason": "missing coarse cell +0x18 flags"}
		if (int(raw) & 3) != 0:
			return result
	result["flags"] = flags & ~SNAP
	result["status"] = "released"
	return result


## 0x5CB250 frame fields +44/+48/+50/+54, multiplied by f32[0x736FCC].
## These are animation bounds, not object collision/overlay footprint.
## frame_bounds=null is valid ONLY for native anim==-1 or frame==-1.
static func animation_rect(native_xy: Vector2, frame_bounds: Variant) -> Vector4i:
	if native_xy.x <= 0.0 or native_xy.y <= 0.0:
		return Vector4i(-1, -1, -1, -1)
	var low: Vector2 = native_xy
	var high: Vector2 = native_xy
	if frame_bounds is Vector4:
		var frame: Vector4 = frame_bounds
		low.x = _f32(native_xy.x + _f32(frame.x * FRAME_SCALE))
		low.y = _f32(native_xy.y + _f32(frame.y * FRAME_SCALE))
		high.x = _f32(native_xy.x + _f32(frame.z * FRAME_SCALE))
		high.y = _f32(native_xy.y + _f32(frame.w * FRAME_SCALE))
	return Vector4i(int(low.x), int(low.y), int(high.x) + 1, int(high.y) + 1)


static func _f32(value: float) -> float:
	var bytes: PackedByteArray = PackedByteArray()
	bytes.resize(4)
	bytes.encode_float(0, value)
	return bytes.decode_float(0)
