extends RefCounted
## Exact terrain byte producer from Diggles.exe 0x5A6B40, plus the byte operation
## of object pass 0x5A5DA0. Samples are integer map XY * 8, not map-cell XY.
## Initial navigation bytes come from PMP RLE (0x599D80..0x599E50); do not
## replace them with a full terrain rebuild during map_template/0x40000.
## Callers supply current BDB bytes and already native-clipped sample regions.
## No bounds extrapolation, object placement, queue scheduling, or graph here.

const CLEARANCE_OFFSETS: Array[Vector2i] = [
	Vector2i(0, -8),
	Vector2i(-7, -15), Vector2i(7, -15), Vector2i(0, -15),
	Vector2i(0, -1),
	Vector2i(-7, -8), Vector2i(7, -8),
	Vector2i(-4, -3), Vector2i(4, -3),
	Vector2i(-7, -5), Vector2i(7, -5),
	Vector2i(-7, -12), Vector2i(7, -12),
	Vector2i(-4, -15), Vector2i(4, -15),
	Vector2i(0, -12), Vector2i(0, -4),
	Vector2i(-4, -8), Vector2i(4, -8),
	Vector2i(-3, -13), Vector2i(3, -13),
	Vector2i(-5, -11), Vector2i(5, -11),
	Vector2i(-2, -10), Vector2i(2, -10),
	Vector2i(-2, -6), Vector2i(2, -6),
	Vector2i(-5, -5), Vector2i(5, -5),
	Vector2i(-2, -2), Vector2i(2, -2),
]


static func terrain_sample(sample: Vector2i, surface_samples: Dictionary,
		cell_byte18: Dictionary) -> int:
	## surface_samples: Vector2i(sample XY) -> current metadata byte 0..255.
	## cell_byte18: Vector2i(map cell XY) -> actual low byte at runtime C+0x18.
	## Required lookups must exist. Missing data must never imply empty terrain.
	var height_query: Callable = func(point: Vector2i) -> Variant: return surface_samples.get(point)
	var gate_query: Callable = func(point: Vector2i) -> Variant: return cell_byte18.get(point)
	var value: Variant = terrain_sample_query(sample, height_query, gate_query)
	assert(value != null, "Missing native terrain inputs")
	return int(value)


static func terrain_sample_query(sample: Vector2i, heights: Callable, gates: Callable) -> Variant:
	# Nullable query adapter for a cropped template. A known blocking probe proves
	# zero even if another probe falls in the unknown surrounding world.
	# 0x5A6D76..0x5A6DC8: gate belongs to floor((sample + 4) / 8).
	var gate_cell: Vector2i = Vector2i((sample.x + 4) >> 3, (sample.y + 4) >> 3)
	var gate: Variant = gates.call(gate_cell)
	if gate == null:
		return null
	if (int(gate) & 0x80) != 0:
		return 0
	# 0x5A6E0A..0x5A7578: all 31 unsigned byte comparisons must be < 14.
	var missing: bool = false
	var values: Dictionary = {}
	for offset: Vector2i in CLEARANCE_OFFSETS:
		var value: Variant = heights.call(sample + offset)
		if value == null:
			missing = true
		elif int(value) >= 14:
			return 0
		else:
			values[offset] = int(value)
	if missing:
		return null
	# 0x5A7588 sets 1. 0x5A75E1..0x5A765B may replace it with 3.
	var current: Variant = heights.call(sample)
	if current == null:
		return null
	var upper_unknown: bool = false
	if int(values[Vector2i(0, -1)]) + 2 < int(current):
		var upper: Variant = heights.call(sample + Vector2i(0, -11))
		if upper == null:
			upper_unknown = true
		elif int(upper) + 2 < int(current):
			return 3
	# 0x5A7665..0x5A76E7: lower pair is y+1 versus y and y-10.
	# At 0x5A76B8 PUSH shifts ESP: [esp+0x1B] writes the old [esp+0x17].
	var below: Variant = heights.call(sample + Vector2i(0, 1))
	if below == null:
		return null
	if int(current) + 2 < int(below):
		var upper: Variant = heights.call(sample + Vector2i(0, -10))
		if upper == null:
			return null
		if int(upper) + 2 < int(below):
			return 3
	if upper_unknown:
		return null
	return 1


static func rebuild_terrain(sample_rect: Rect2i, surface_samples: Dictionary,
		cell_byte18: Dictionary) -> Dictionary:
	## Returns only replacement bytes in this half-open, already clipped region.
	## Writer 0x596550 replaces C+0x3C+(y&7)*8+(x&7); it does not OR old flags.
	## Replay relevant object overlays after replacement, as queue 1 -> 2 does.
	assert(sample_rect.size.x >= 0 and sample_rect.size.y >= 0)
	var result: Dictionary = {}
	for y: int in range(sample_rect.position.y, sample_rect.end.y):
		for x: int in range(sample_rect.position.x, sample_rect.end.x):
			var sample: Vector2i = Vector2i(x, y)
			result[sample] = terrain_sample(sample, surface_samples, cell_byte18)
	return result


static func object_overlay(flags: int, object_byte268: int, object_value264: int) -> int:
	## 0x5A6106..0x5A61EF, for samples inside an eligible object's clipped rect.
	## Eligibility/rect/order are caller inputs: no guessed attachment footprint.
	var keep_mask: int = 0 if object_value264 == 0x7FFFFFFF else 0xF3
	return ((flags & keep_mask) | (object_byte268 & 0xFF)) & 0xFF


static func terrain_dependency_rect(invalidated: Rect2i) -> Rect2i:
	## 0x5A409E..0x5A40CE, flag 0x10000 -> queue mask 7:
	## (L-8,T-2,R+8,B+16). Dispatcher clips before AND after this expansion.
	## This function only expands; the caller supplies the native clipping policy.
	return Rect2i(invalidated.position - Vector2i(8, 2),
		invalidated.size + Vector2i(16, 18))


static func _height(surface_samples: Dictionary, sample: Vector2i) -> int:
	assert(surface_samples.has(sample), "Missing current BlockDB height sample")
	var height: int = int(surface_samples[sample])
	assert(height >= 0 and height <= 255, "Expected an unsigned BlockDB byte")
	return height
