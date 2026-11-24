extends RefCounted
## Tcl vector_fix/0x635940 -> 0x595770. Does not contain vector_fixdig's Y-5.
const MATH: Script = preload("res://baseline/scripts/native_fix_dig.gd")


static func solve(point: Vector3, bounds: Rect2i, flags: Callable, heights: Callable, rounding_mode: StringName = &"unspecified") -> Dictionary:
	if not point.is_finite() or bounds.size.x <= 0 or bounds.size.y <= 0:
		return {"status": "invalid_input"}
	if not rounding_mode in [&"nearest_even", &"floor", &"ceil", &"truncate"]:
		return {"status": "unknown", "missing": "x87_rounding_mode"}
	var origin: Vector2i = Vector2i(MATH._round(MATH._f32(point.x * 8.0), rounding_mode),
		MATH._round(MATH._f32(point.y * 8.0), rounding_mode))
	var interior: Rect2i = Rect2i(bounds.position * 8 + Vector2i(48, 48), bounds.size * 8 - Vector2i(96, 96))
	if not interior.has_point(origin):
		return {"status": "ok", "point": point, "found_navigation": false, "reason": "outside_interior"}
	if origin.x < 10 or origin.y < 10:
		return {"status": "ok", "point": Vector3.ZERO, "found_navigation": false, "reason": "low_sample"}
	var initial: Variant = flags.call(MATH._clamped_sample(origin, bounds))
	if initial == null:
		return {"status": "unknown", "missing": "walk_flags", "at_sample": origin}
	if (int(initial) & 1) != 0:
		return {"status": "ok", "point": Vector3(float(origin.x) * 0.125, float(origin.y) * 0.125, point.z),
			"found_navigation": true, "sample": origin, "reason": "initial_sample"}
	var best: Vector2i = origin
	var cursor: Vector2i = origin
	var length: int = 1
	var limit: int = 48
	var best_squared: int = 0x7FFFFFFF
	var found: bool = false
	while true:
		for direction: Vector2i in [Vector2i.RIGHT, Vector2i.DOWN, Vector2i.LEFT, Vector2i.UP]:
			if direction == Vector2i.LEFT:
				length += 1
			for step: int in range(length):
				cursor += direction
				var value: Variant = flags.call(MATH._clamped_sample(cursor, bounds))
				if value == null:
					return {"status": "unknown", "missing": "walk_flags", "at_sample": cursor}
				if (int(value) & 1) == 0:
					continue
				var delta: Vector2i = cursor - origin
				var squared: int = delta.x * delta.x + delta.y * delta.y
				if squared >= best_squared:
					continue
				best_squared = squared
				best = cursor
				found = true
				var distance: float = MATH._f32(sqrt(MATH._f32(float(squared))))
				limit = mini(limit, int(MATH._f32(distance + distance) + 2.1))
		length += 1
		if length >= limit:
			break
	var height: Variant = heights.call(MATH._clamped_sample(best + Vector2i.UP, bounds))
	if height == null:
		return {"status": "unknown", "missing": "block_height", "at_sample": best + Vector2i.UP}
	return {"status": "ok", "point": Vector3(float(best.x) * 0.125, float(best.y) * 0.125,
		minf(14.5, maxf(point.z, float(int(height) + 1)))), "sample": best,
		"found_navigation": found, "reason": "spiral"}
