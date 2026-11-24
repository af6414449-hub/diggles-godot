extends RefCounted
## Native path-sample mode 0x423730 and wall depth 0x4238E0.
## These helpers classify a supplied path; they do not discover native edges.


static func mode(flags: int, use_objects: bool, ladder_available: bool) -> int:
	if use_objects and (flags & 4) != 0 and ladder_available:
		return 1
	return 2 if (flags & 2) != 0 else 0


static func wall_depth(sample: Vector2i, heights: Callable) -> Variant:
	var above: Variant = heights.call(sample + Vector2i.UP)
	if above == null:
		return null
	var value: int = int(above)
	if value == 15:
		value = 255
		for offset: Vector2i in [Vector2i(-1, -1), Vector2i(1, -1), Vector2i(0, -2), Vector2i.ZERO]:
			var probe: Variant = heights.call(sample + offset)
			if probe == null:
				return null
			value = mini(value, int(probe))
	return float(value + 1)


static func floor_depth(direction_x: int) -> float:
	# 0x41A40B..0x41A44A: sign from path[index].x - path[index-1].x.
	return 12.5 if direction_x < 0 else 14.5


static func ground_contact(sample: Vector2i, bounds: Rect2i, flags: Callable) -> Variant:
	# get_gnomeposition/0x68D9C7..0x68DA93: outside the one-sample interior -> 0.
	if not bounds.grow(-1).has_point(sample):
		return true
	var missing: bool = false
	for offset: Vector2i in [Vector2i.DOWN, Vector2i.ZERO, Vector2i.UP]:
		var value: Variant = flags.call(sample + offset)
		if value == null:
			missing = true
		elif (int(value) & 2) != 0:
			return true
	if missing:
		return null
	return false
