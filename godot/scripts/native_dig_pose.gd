extends RefCounted
## get_angle_num4: 0x646D48..0x646E0C and 0x40B700, float32 boundaries.
const MATH: Script = preload("res://scripts/native_fix_dig.gd")


static func direction(from: Vector3, to: Vector3) -> int:
	var dx: float = MATH._f32(to.x - from.x)
	var dy: float = MATH._f32(to.y - from.y)
	var dz: float = MATH._f32(to.z - from.z)
	var length3: float = MATH._f32(sqrt(MATH._f32(MATH._f32(MATH._f32(dy * dy) + MATH._f32(dx * dx)) + MATH._f32(dz * dz))))
	if length3 != 0.0:
		dx = MATH._f32(dx / length3)
		dy = MATH._f32(dy / length3)
	var squared_xy: float = MATH._f32(MATH._f32(dx * dx) + MATH._f32(dy * dy))
	var angle: float = 0.0
	if squared_xy != 0.0:
		var radius: float = MATH._f32(sqrt(squared_xy))
		var ratio: float = MATH._f32(dx / radius)
		angle = MATH._f32(acos(clampf(ratio, -1.0, 1.0)))
		if dy <= 0.0:
			angle = -angle
	var shifted: float = MATH._f32(MATH._f32(angle - 2.356194496154785) + 31.41592788696289)
	return (63 - int(MATH._f32(shifted / -1.5707963705062866))) & 3


static func wall_clip(from: Vector3, to: Vector3) -> StringName:
	return [&"kletter_hack_oben", &"kletter_hack_rechts", &"kletter_hack_unten", &"kletter_hack_links"][direction(from, to)]
