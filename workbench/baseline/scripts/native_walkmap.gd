extends RefCounted
## Imported initial C+0x3C navigation bytes. A changed, unrecomputed cache is
## unknown; the original cached flags must never silently survive excavation.

const PRODUCER: Script = preload("res://baseline/scripts/native_walk_flags.gd")
const REPRESENTATIVE: Script = preload("res://baseline/scripts/native_navigation_representative.gd")
var representatives_revision: int = -1
var representatives: Dictionary = {}

var data: Dictionary = {}
var flags: PackedByteArray = PackedByteArray()
var unknown_samples: PackedByteArray = PackedByteArray()
var sample_bounds: Rect2i
var current: bool = false
var unknown_count: int = 0
var revision: int = 0
var stage: String = "initial_pmp_cache"
var last_rebuild: Dictionary = {}


func load_map(path: String, terrain: Dictionary) -> bool:
	representatives_revision = -1
	representatives.clear()
	var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	if not parsed is Dictionary:
		return false
	data = parsed
	if data.get("source_pmp_sha256") != terrain.get("source_pmp_sha256") \
			or data.get("source_bdb_sha256") != terrain.get("source_bdb_sha256"):
		return false
	var width: int = int(data.get("width", 0))
	var height: int = int(data.get("height", 0))
	if width != int(terrain["width"]) * 8 or height != int(terrain["height"]) * 8:
		return false
	var source_flags: Array = data.get("flags", [])
	if source_flags.size() != width * height:
		return false
	for value: int in source_flags:
		if value < 0 or value > 3:
			return false
	flags = PackedByteArray(source_flags)
	unknown_samples.resize(flags.size())
	unknown_samples.fill(0)
	unknown_count = 0
	sample_bounds = Rect2i(0, 0, width, height)
	current = true
	return true


func sample(point: Vector2i) -> Variant:
	if not sample_bounds.has_point(point):
		return null
	var index: int = point.y * sample_bounds.size.x + point.x
	if unknown_samples[index] != 0:
		return null
	return int(flags[index])


func cell_representative(cell: Vector2i) -> Variant:
	if representatives_revision!=revision:
		representatives.clear()
		representatives_revision = revision
	if representatives.has(cell):
		return representatives[cell]
	var bytes: PackedByteArray = PackedByteArray()
	for y: int in range(8):
		for x: int in range(8):
			var value: Variant = sample(cell*8+Vector2i(x,y))
			if value==null or (int(value)&12)!=0:
				representatives[cell] = null
				return null
			bytes.append(int(value))
	var local: Variant = REPRESENTATIVE.choose(bytes)
	if local is Vector2i:
		representatives[cell] = cell*8+local
	else:
		representatives[cell] = null
	return representatives[cell]


func is_newly_navigable(point: Vector2i) -> bool:
	# Compare current source terrain bytes against the preserved initial PMP.
	# Unknown/closed samples must not be offered as newly opened destinations.
	var value: Variant = sample(point)
	if value == null or (int(value) & 1) == 0:
		return false
	var index: int = point.y * sample_bounds.size.x + point.x
	return (int(data["flags"][index]) & 1) == 0


func invalidate() -> void:
	unknown_samples.fill(1)
	unknown_count = flags.size()
	current = false
	stage = "dirty_unknown"


func rebuild_after_strike(patch: Dictionary, heights: Callable, gates: Callable, world_sample_bounds: Rect2i) -> Dictionary:
	# Native producer 0x5A6B40 clips by +24,+16,-24,-24 samples.
	# Object overlays are a separate, currently unported pass; this is terrain.
	var producer_bounds: Rect2i = Rect2i(world_sample_bounds.position + Vector2i(24, 16),
		world_sample_bounds.size - Vector2i(48, 40))
	var rebuilt: int = 0
	var changed: int = 0
	var rects: Array[Rect2i] = []
	for invalidation: Dictionary in patch["invalidations"]:
		if (int(invalidation["flags"]) & 0x10000) == 0:
			continue
		var clipped: Rect2i = (invalidation["rect"] as Rect2i).intersection(world_sample_bounds)
		if not clipped.has_area():
			continue
		var expanded: Rect2i = PRODUCER.terrain_dependency_rect(clipped).intersection(world_sample_bounds)
		var output: Rect2i = expanded.intersection(producer_bounds).intersection(sample_bounds)
		rects.append(output)
		for y: int in range(output.position.y, output.end.y):
			for x: int in range(output.position.x, output.end.x):
				var point: Vector2i = Vector2i(x, y)
				var index: int = y * sample_bounds.size.x + x
				var value: Variant = PRODUCER.terrain_sample_query(point, heights, gates)
				if value == null:
					if unknown_samples[index] == 0:
						unknown_count += 1
					unknown_samples[index] = 1
				else:
					rebuilt += 1
					if int(flags[index]) != int(value):
						changed += 1
					flags[index] = int(value)
					if unknown_samples[index] != 0:
						unknown_count -= 1
					unknown_samples[index] = 0
	current = unknown_count == 0
	revision += 1
	stage = "native_terrain_rebuilt"
	last_rebuild = {"rebuilt": rebuilt, "changed": changed, "unknown_total": unknown_count,
		"rects": rects, "object_overlays_applied": false}
	return last_rebuild
