extends RefCounted
## ADAPTER: chapter-local navigation over original BDB 8x8 samples and the
## original terrain-byte producer. The chapter has no exported live PMP cache;
## flags are calculated lazily from its current blocks and template cell gate.

const FLAGS: Script = preload("res://scripts/native_walk_flags.gd")
const REPRESENTATIVE: Script = preload("res://scripts/native_navigation_representative.gd")

var dig: RefCounted = null
var gates: Dictionary = {}
var sample_bounds: Rect2i = Rect2i(0, 0, 512 * 8, 640 * 8)
var _flags: Dictionary = {}
var _representatives: Dictionary = {}
var _revision: int = -1


func setup(excavation: RefCounted, chapter_cells: Array) -> void:
	dig = excavation
	for entry: Dictionary in chapter_cells:
		gates[Vector2i(int(entry["x"]), int(entry["y"]))] = int(entry["flags"]) & 0x80
	_revision = int(dig.terrain_revision)


func set_route_window(start: Vector2i, goal: Vector2i, margin_cells: int = 16) -> void:
	var low: Vector2i = Vector2i(mini(start.x, goal.x), mini(start.y, goal.y)) - Vector2i.ONE * margin_cells * 8
	var high: Vector2i = Vector2i(maxi(start.x, goal.x), maxi(start.y, goal.y)) + Vector2i.ONE * margin_cells * 8
	low = low.clamp(Vector2i.ZERO, Vector2i(512 * 8 - 1, 640 * 8 - 1))
	high = high.clamp(Vector2i.ZERO, Vector2i(512 * 8 - 1, 640 * 8 - 1))
	sample_bounds = Rect2i(low, high - low + Vector2i.ONE)
	_representatives.clear()


func surface_height(point: Vector2i) -> Variant:
	var cell: Vector2i = Vector2i(point.x >> 3, point.y >> 3)
	var block: int = int(dig.block_overrides.get(cell, dig.source_blocks.get(cell, -1)))
	if not dig.native_blocks.has(str(block)):
		return null
	var samples: Array = dig.native_blocks[str(block)].get("surface_samples", [])
	if samples.size() != 64:
		return null
	return int(samples[(point.y & 7) * 8 + (point.x & 7)])


func _gate(cell: Vector2i) -> Variant:
	return gates.get(cell)


func sample(point: Vector2i) -> Variant:
	if point.x < 0 or point.y < 0 or point.x >= 512 * 8 or point.y >= 640 * 8:
		return null
	if _revision != int(dig.terrain_revision):
		_revision = int(dig.terrain_revision)
		_flags.clear()
		_representatives.clear()
	if not _flags.has(point):
		_flags[point] = FLAGS.terrain_sample_query(point,
			Callable(self, "surface_height"), Callable(self, "_gate"))
	return _flags[point]


func cell_representative(cell: Vector2i) -> Variant:
	if not sample_bounds.has_point(cell * 8 + Vector2i(4, 4)):
		return null
	if _representatives.has(cell):
		return _representatives[cell]
	var bytes := PackedByteArray()
	for y: int in range(8):
		for x: int in range(8):
			var flag: Variant = sample(cell * 8 + Vector2i(x, y))
			if flag == null or (int(flag) & 12) != 0:
				_representatives[cell] = null
				return null
			bytes.append(int(flag))
	var selected: Variant = REPRESENTATIVE.choose(bytes)
	_representatives[cell] = cell * 8 + selected if selected is Vector2i else null
	return _representatives[cell]
