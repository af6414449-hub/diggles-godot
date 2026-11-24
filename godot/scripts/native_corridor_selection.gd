extends RefCounted
## Pure selection math from the installed Diggles.exe; positive native map X/Y only.
## Scope: the current 44x24 map. Inputs are finite; anchors/endpoints are native centers.
## Half-integer centers are exactly representable at this scale; huge worlds are unsupported.
## GDScript scalar float is double. Explicit binary32 stores below reproduce SSE
## rounding, including the source input and every snap arithmetic intermediate.
## This does not emulate negative/NaN/overflow input or native screen picking.
## UI contour, terrain validation, marks, ownership and worker tasks are separate.


static func snap_start(raw: Vector2) -> Vector2:
	# VA 0x5680C7..0x568175: 4 * floor((p + 0.5) / 4) + 1.5.
	return Vector2(_snap_axis(raw.x, 0.5, 0.25, 4.0),
		_snap_axis(raw.y, 0.5, 0.25, 4.0))


static func snap_drag(raw: Vector2, anchor: Vector2) -> Vector2:
	# VA 0x5682F0..0x5683AD: 2 * floor((p - 0.5) / 2) + 1.5.
	var result: Vector2 = Vector2(_snap_axis(raw.x, -0.5, 0.5, 2.0),
		_snap_axis(raw.y, -0.5, 0.5, 2.0))
	var native_anchor: Vector2 = Vector2(_float32(anchor.x), _float32(anchor.y))
	var index_x: int = _coarse_index(int(native_anchor.x))
	var index_y: int = _coarse_index(int(native_anchor.y))
	# VA 0x568357..0x5683EF reads the initial anchor (+0xE4/E8), not the
	# previous preview endpoint (+0xF0/F4). The axis is recomputed each call.
	if ((index_x | index_y) & 1) == 0:
		var distance_x: float = absf(_float32(result.x - native_anchor.x))
		var distance_y: float = absf(_float32(result.y - native_anchor.y))
		if distance_x <= distance_y:
			result.x = native_anchor.x # VA 0x5683DD: ties choose vertical.
		else:
			result.y = native_anchor.y
	elif (index_x & 1) == 0:
		result.x = native_anchor.x
	elif (index_y & 1) == 0:
		result.y = native_anchor.y
	# Both-odd anchors remain unconstrained here; rasterization rejects that group.
	return result


static func rasterize(anchor: Vector2, end: Vector2, bounds: Rect2i) -> Array[Vector2i]:
	# bounds is the already-permitted, half-open SAMPLE domain [position, end).
	# VA 0x5665C4..0x566651 uses [world_min, world_max - 1). A caller with
	# those native world fields must construct bounds with that exclusive end;
	# this function does not subtract another border from the supplied rectangle.
	# VA 0x5672D0 material/height/owner checks are not part of this pure rasterizer.
	var samples: Array[Vector2i] = []
	if bounds.size.x <= 0 or bounds.size.y <= 0:
		return samples
	# VA 0x56657A..0x5665C0 truncates centers and adds 2 to the exclusive end.
	# Thus center (5.5, 9.5) selects {5,6} x {9,10}, independent of UI quad size.
	var first: Vector2i = Vector2i(int(_float32(anchor.x)), int(_float32(anchor.y)))
	var last: Vector2i = Vector2i(int(_float32(end.x)), int(_float32(end.y)))
	var lower: Vector2i = Vector2i(maxi(mini(first.x, last.x), bounds.position.x),
		maxi(mini(first.y, last.y), bounds.position.y))
	var upper: Vector2i = Vector2i(mini(maxi(first.x, last.x) + 2, bounds.end.x),
		mini(maxi(first.y, last.y) + 2, bounds.end.y))
	# VA 0x56671D..0x566779: row-major unit samples, not interpolated UI tiles.
	for sample_y: int in range(lower.y, upper.y):
		var index_y: int = _coarse_index(sample_y)
		for sample_x: int in range(lower.x, upper.x):
			var index_x: int = _coarse_index(sample_x)
			# VA 0x56672B..0x56674D / 0x5668D0..0x5668E7.
			if (index_x & index_y & 1) == 0:
				samples.append(Vector2i(sample_x, sample_y))
	return samples


static func _snap_axis(value: float, bias: float, scale: float, step: float) -> float:
	var source: float = _float32(value)
	var shifted: float = _float32(source + bias)
	var scaled: float = _float32(shifted * scale)
	# VA 0x6F6DA0 floors the double extension of the already-rounded binary32.
	var whole: float = _float32(floorf(scaled))
	var spaced: float = _float32(whole * step)
	return _float32(spaced + 1.5)


static func _coarse_index(coordinate: int) -> int:
	# VA 0x56672B..0x566748 performs signed truncation, not floor division.
	return int(float(coordinate - 1) / 2.0)


static func _float32(value: float) -> float:
	# PackedFloat32Array stores binary32 even in a double-precision Godot build.
	# A Vector2 may have rounded its input already; this cannot recover prior data.
	var packed: PackedFloat32Array = PackedFloat32Array([value])
	return packed[0]
