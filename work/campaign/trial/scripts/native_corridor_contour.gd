extends RefCounted
## Source-derived unit-cell atlas, all-valid filled pass, positive 44x24 native X/Y.
## EXE 0x56D402 -> 0x56AE30 -> 0x568410. No marching-squares approximation.
## Dictionary keys are selected Vector2i heightmap samples; values are opaque.
## No color, Z conversion, clipping, validator, ownership, or wave is applied here.
## Topology/index order is native, including overlapping fill/edge triangles.
## Arc floats are traced with binary32 arithmetic and host cos/sin, not bit-exact
## MSVC transcendental results. Translated atlas coordinates use 1e-5 tolerance.
## Mixed valid/invalid corner passes and outline-only mode are outside this API.

const _VERTICES: Array[Array] = [
	# Mask 0; 0 triangles, source branch 0x568448.
	[],
	# Mask 1; 12 triangles, source branch 0x56A027.
	[Vector2(0, 0), Vector2(-2.1418580686827227e-8, 0.49000000953674316), Vector2(-1.311341701892843e-8, 0.30000001192092896), Vector2(0.18751488626003265, 0.45270097255706787), Vector2(0.11480503529310226, 0.27716386318206787), Vector2(0.34648236632347107, 0.3464823365211487), Vector2(0.2121320515871048, 0.2121320366859436), Vector2(0.45270100235939026, 0.18751487135887146), Vector2(0.27716389298439026, 0.11480502039194107), Vector2(0.49000000953674316, -2.9206276508375595e-8), Vector2(0.30000001192092896, -1.7881394143159923e-8)],
	# Mask 2; 12 triangles, source branch 0x56A027.
	[Vector2(1, 0), Vector2(0.5099999904632568, -4.283716137365445e-8), Vector2(0.699999988079071, -2.622683403785686e-8), Vector2(0.5472989678382874, 0.18751481175422668), Vector2(0.7228361368179321, 0.11480499058961868), Vector2(0.6535176038742065, 0.3464822471141815), Vector2(0.7878679037094116, 0.21213199198246002), Vector2(0.8124849796295166, 0.4527009427547455), Vector2(0.8851948976516724, 0.2771638333797455), Vector2(0.9999999403953552, 0.49000000953674316), Vector2(0.9999999403953552, 0.30000001192092896)],
	# Mask 3; 4 triangles, source branch 0x56853E.
	[Vector2(0, 0.30000001192092896), Vector2(1, 0.30000001192092896), Vector2(0, 0.49000000953674316), Vector2(1, 0.49000000953674316), Vector2(0, 0), Vector2(1, 0)],
	# Mask 4; 12 triangles, source branch 0x56A027.
	[Vector2(0, 1), Vector2(0.49000000953674316, 1), Vector2(0.30000001192092896, 1), Vector2(0.45270097255706787, 0.8124850988388062), Vector2(0.27716386318206787, 0.8851949572563171), Vector2(0.3464823365211487, 0.6535176634788513), Vector2(0.2121320366859436, 0.7878679633140564), Vector2(0.18751488626003265, 0.5472990274429321), Vector2(0.11480503529310226, 0.7228361368179321), Vector2(-2.1418580686827227e-8, 0.5099999904632568), Vector2(-1.311341701892843e-8, 0.699999988079071)],
	# Mask 5; 4 triangles, source branch 0x56853E.
	[Vector2(0.30000001192092896, 0), Vector2(0.30000001192092896, 1), Vector2(0.49000000953674316, 0), Vector2(0.49000000953674316, 1), Vector2(0, 0), Vector2(0, 1)],
	# Mask 6; 24 triangles, source branch 0x56A027.
	[Vector2(1, 0), Vector2(0.5099999904632568, -4.283716137365445e-8), Vector2(0.699999988079071, -2.622683403785686e-8), Vector2(0.5472989678382874, 0.18751481175422668), Vector2(0.7228361368179321, 0.11480499058961868), Vector2(0.6535176038742065, 0.3464822471141815), Vector2(0.7878679037094116, 0.21213199198246002), Vector2(0.8124849796295166, 0.4527009427547455), Vector2(0.8851948976516724, 0.2771638333797455), Vector2(0.9999999403953552, 0.49000000953674316), Vector2(0.9999999403953552, 0.30000001192092896), Vector2(0, 1), Vector2(0.49000000953674316, 1), Vector2(0.30000001192092896, 1), Vector2(0.45270097255706787, 0.8124850988388062), Vector2(0.27716386318206787, 0.8851949572563171), Vector2(0.3464823365211487, 0.6535176634788513), Vector2(0.2121320366859436, 0.7878679633140564), Vector2(0.18751488626003265, 0.5472990274429321), Vector2(0.11480503529310226, 0.7228361368179321), Vector2(-2.1418580686827227e-8, 0.5099999904632568), Vector2(-1.311341701892843e-8, 0.699999988079071)],
	# Mask 7; 8 triangles, source branch 0x569279.
	[Vector2(1, 0.49000000953674316), Vector2(0.9999999403953552, 0.30000001192092896), Vector2(0.9999999403953552, 0), Vector2(0.49000006914138794, 0.49000006914138794), Vector2(0.30000001192092896, 0.30000001192092896), Vector2(5.960464477539063e-8, 5.960464477539063e-8), Vector2(0.49000000953674316, 1), Vector2(0.30000001192092896, 1.0000001192092896), Vector2(0, 1.0000001192092896)],
	# Mask 8; 12 triangles, source branch 0x56A027.
	[Vector2(1, 1), Vector2(1, 0.5099999904632568), Vector2(1, 0.699999988079071), Vector2(0.8124850988388062, 0.5472990274429321), Vector2(0.8851949572563171, 0.7228361368179321), Vector2(0.6535176634788513, 0.6535176634788513), Vector2(0.7878679633140564, 0.7878679633140564), Vector2(0.5472990274429321, 0.8124850988388062), Vector2(0.7228361368179321, 0.8851949572563171), Vector2(0.5099999904632568, 0.9999999403953552), Vector2(0.699999988079071, 0.9999999403953552)],
	# Mask 9; 24 triangles, source branch 0x56A027.
	[Vector2(0, 0), Vector2(-2.1418580686827227e-8, 0.49000000953674316), Vector2(-1.311341701892843e-8, 0.30000001192092896), Vector2(0.18751488626003265, 0.45270097255706787), Vector2(0.11480503529310226, 0.27716386318206787), Vector2(0.34648236632347107, 0.3464823365211487), Vector2(0.2121320515871048, 0.2121320366859436), Vector2(0.45270100235939026, 0.18751487135887146), Vector2(0.27716389298439026, 0.11480502039194107), Vector2(0.49000000953674316, -2.9206276508375595e-8), Vector2(0.30000001192092896, -1.7881394143159923e-8), Vector2(1, 1), Vector2(1, 0.5099999904632568), Vector2(1, 0.699999988079071), Vector2(0.8124850988388062, 0.5472990274429321), Vector2(0.8851949572563171, 0.7228361368179321), Vector2(0.6535176634788513, 0.6535176634788513), Vector2(0.7878679633140564, 0.7878679633140564), Vector2(0.5472990274429321, 0.8124850988388062), Vector2(0.7228361368179321, 0.8851949572563171), Vector2(0.5099999904632568, 0.9999999403953552), Vector2(0.699999988079071, 0.9999999403953552)],
	# Mask 10; 4 triangles, source branch 0x56853E.
	[Vector2(0.699999988079071, 0), Vector2(0.699999988079071, 1), Vector2(0.5099999904632568, 0), Vector2(0.5099999904632568, 1), Vector2(1, 0), Vector2(1, 1)],
	# Mask 11; 8 triangles, source branch 0x569279.
	[Vector2(0.5099999904632568, 1), Vector2(0.699999988079071, 1), Vector2(1, 1), Vector2(0.5099999308586121, 0.49000006914138794), Vector2(0.699999988079071, 0.30000001192092896), Vector2(0.9999999403953552, 5.960464477539063e-8), Vector2(-2.2292807599910702e-8, 0.49000000953674316), Vector2(-3.059797037963108e-8, 0.30000001192092896), Vector2(-4.371138828673793e-8, 0)],
	# Mask 12; 4 triangles, source branch 0x56853E.
	[Vector2(0, 0.699999988079071), Vector2(1, 0.699999988079071), Vector2(0, 0.5099999904632568), Vector2(1, 0.5099999904632568), Vector2(0, 1), Vector2(1, 1)],
	# Mask 13; 8 triangles, source branch 0x569279.
	[Vector2(0.49000000953674316, -4.4585615199821405e-8), Vector2(0.30000001192092896, -6.119594075926216e-8), Vector2(0, -8.742277657347586e-8), Vector2(0.49000006914138794, 0.5099999308586121), Vector2(0.30000001192092896, 0.699999988079071), Vector2(5.960464477539063e-8, 0.9999999403953552), Vector2(1, 0.5099999904632568), Vector2(1, 0.699999988079071), Vector2(1.0000001192092896, 1)],
	# Mask 14; 8 triangles, source branch 0x569279.
	[Vector2(-2.2292807599910702e-8, 0.5099999904632568), Vector2(-3.059797037963108e-8, 0.699999988079071), Vector2(-4.371138828673793e-8, 1), Vector2(0.5099999308586121, 0.5099999308586121), Vector2(0.699999988079071, 0.699999988079071), Vector2(0.9999999403953552, 0.9999999403953552), Vector2(0.5099999904632568, 0), Vector2(0.699999988079071, 0), Vector2(1, 0)],
	# Mask 15; 2 triangles, source branch 0x56A97C.
	[Vector2(0, 0), Vector2(1, 0), Vector2(0, 1), Vector2(1, 1)],
]

const _INDICES: Array[Array] = [
	[], # 0
	[0, 1, 3, 1, 3, 4, 1, 2, 4, 0, 3, 5, 3, 5, 6, 3, 4, 6, 0, 5, 7, 5, 7, 8, 5, 6, 8, 0, 7, 9, 7, 9, 10, 7, 8, 10], # 1
	[0, 1, 3, 1, 3, 4, 1, 2, 4, 0, 3, 5, 3, 5, 6, 3, 4, 6, 0, 5, 7, 5, 7, 8, 5, 6, 8, 0, 7, 9, 7, 9, 10, 7, 8, 10], # 2
	[0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 5], # 3
	[0, 1, 3, 1, 3, 4, 1, 2, 4, 0, 3, 5, 3, 5, 6, 3, 4, 6, 0, 5, 7, 5, 7, 8, 5, 6, 8, 0, 7, 9, 7, 9, 10, 7, 8, 10], # 4
	[0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 5], # 5
	[0, 1, 3, 1, 3, 4, 1, 2, 4, 0, 3, 5, 3, 5, 6, 3, 4, 6, 0, 5, 7, 5, 7, 8, 5, 6, 8, 0, 7, 9, 7, 9, 10, 7, 8, 10, 11, 12, 14, 12, 14, 15, 12, 13, 15, 11, 14, 16, 14, 16, 17, 14, 15, 17, 11, 16, 18, 16, 18, 19, 16, 17, 19, 11, 18, 20, 18, 20, 21, 18, 19, 21], # 6
	[2, 5, 3, 3, 6, 8, 0, 2, 3, 0, 1, 3, 4, 3, 1, 3, 7, 6, 3, 4, 7, 5, 3, 8], # 7
	[0, 1, 3, 1, 3, 4, 1, 2, 4, 0, 3, 5, 3, 5, 6, 3, 4, 6, 0, 5, 7, 5, 7, 8, 5, 6, 8, 0, 7, 9, 7, 9, 10, 7, 8, 10], # 8
	[0, 1, 3, 1, 3, 4, 1, 2, 4, 0, 3, 5, 3, 5, 6, 3, 4, 6, 0, 5, 7, 5, 7, 8, 5, 6, 8, 0, 7, 9, 7, 9, 10, 7, 8, 10, 11, 12, 14, 12, 14, 15, 12, 13, 15, 11, 14, 16, 14, 16, 17, 14, 15, 17, 11, 16, 18, 16, 18, 19, 16, 17, 19, 11, 18, 20, 18, 20, 21, 18, 19, 21], # 9
	[0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 5], # 10
	[2, 5, 3, 3, 6, 8, 0, 2, 3, 0, 1, 3, 4, 3, 1, 3, 7, 6, 3, 4, 7, 5, 3, 8], # 11
	[0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 5], # 12
	[2, 5, 3, 3, 6, 8, 0, 2, 3, 0, 1, 3, 4, 3, 1, 3, 7, 6, 3, 4, 7, 5, 3, 8], # 13
	[2, 5, 3, 3, 6, 8, 0, 2, 3, 0, 1, 3, 4, 3, 1, 3, 7, 6, 3, 4, 7, 5, 3, 8], # 14
	[0, 1, 2, 1, 2, 3], # 15
]


static func build_triangles(samples: Dictionary, outline_only: bool = false) -> PackedVector2Array:
	var result: PackedVector2Array = PackedVector2Array()
	if samples.is_empty():
		return result
	# 0x56D166..0x56D173 pads by one sample; each point touches four cells.
	# Deterministic row-major unit cells; bounded map coordinates are a precondition.
	var initialized: bool = false
	var minimum: Vector2i = Vector2i.ZERO
	var maximum: Vector2i = Vector2i.ZERO
	for key: Variant in samples:
		if not key is Vector2i:
			continue
		var point: Vector2i = key
		if not initialized:
			minimum = point
			maximum = point
			initialized = true
		else:
			minimum = Vector2i(mini(minimum.x, point.x), mini(minimum.y, point.y))
			maximum = Vector2i(maxi(maximum.x, point.x), maxi(maximum.y, point.y))
	if not initialized:
		return result
	for cell_y: int in range(minimum.y - 1, maximum.y + 1):
		for cell_x: int in range(minimum.x - 1, maximum.x + 1):
			var origin: Vector2i = Vector2i(cell_x, cell_y)
			var mask: int = cell_mask(samples, origin)
			var points: Array = _VERTICES[mask]
			var indices: Array = _INDICES[mask]
			for triangle: int in range(0,indices.size(),3):
				var fill: bool = false
				if outline_only:
					# The source atlas's fill fans touch a selected cell corner;
					# its .30..49 contour strips do not. Retain the SAME strips.
					for vertex: int in range(3):
						var point: Vector2 = points[indices[triangle+vertex]]
						for corner: int in range(4):
							if (mask & (1 << corner)) != 0 and point.distance_squared_to(Vector2(corner & 1,corner >> 1)) < 0.00000001:
								fill = true
				if not fill:
					for vertex: int in range(3):
						var point: Vector2 = points[indices[triangle+vertex]]
						result.append(Vector2(float(cell_x) + point.x,float(cell_y) + point.y))
	return result


static func cell_mask(samples: Dictionary, origin: Vector2i) -> int:
	# 0x56D402..0x56D481: arguments TL, TR, BL, BR; bits 1, 2, 4, 8.
	var mask: int = 0
	if samples.has(origin):
		mask |= 1
	if samples.has(origin + Vector2i.RIGHT):
		mask |= 2
	if samples.has(origin + Vector2i.DOWN):
		mask |= 4
	if samples.has(origin + Vector2i.ONE):
		mask |= 8
	return mask


static func cell_triangles(mask: int) -> PackedVector2Array:
	# The same source atlas in a unit cell, useful for independent case checks.
	var result: PackedVector2Array = PackedVector2Array()
	if mask < 0 or mask > 15:
		return result
	var points: Array = _VERTICES[mask]
	var indices: Array = _INDICES[mask]
	for index: int in indices:
		var point: Vector2 = points[index]
		result.append(point)
	return result

