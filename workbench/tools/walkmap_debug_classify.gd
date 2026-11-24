extends SceneTree
## Classifies every divergence between the baseline full rebuild and the
## optimised walkmap at the first strike where they differ.
##
## Categories:
##   STALE_SKIP - the optimised run skipped the sample although the host
##                predicate answers a different value now.
##   PREDICATE  - the optimised run computed the sample, but the cached
##                predicate disagrees with the host predicate.
##   STATE      - both predicates agree, the difference is only bookkeeping.

const HARNESS: Script = preload("res://tools/walkmap_harness.gd")
const BASELINE_WALKMAP: Script = preload("res://baseline/scripts/native_walkmap.gd")
const OPT_WALKMAP: Script = preload("res://scripts/native_walkmap.gd")
const BASE_FLAGS: Script = preload("res://baseline/scripts/native_walk_flags.gd")
const OPT_FLAGS: Script = preload("res://scripts/native_walk_flags.gd")

const CAVE_STRIKES: Array = [
	[Vector2i(9, 3), 10], [Vector2i(9, 3), 8],
	[Vector2i(20, 1), 10], [Vector2i(23, 1), 10],
	[Vector2i(15, 2), 10], [Vector2i(16, 2), 8],
	[Vector2i(17, 2), 10], [Vector2i(18, 2), 8],
	[Vector2i(19, 2), 10], [Vector2i(20, 2), 8],
]


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var base: RefCounted = HARNESS.new()
	var opt: RefCounted = HARNESS.new()
	base.build(BASELINE_WALKMAP)
	opt.build(OPT_WALKMAP)
	var base_bounds: Rect2i = base.sample_bounds()
	var opt_bounds: Rect2i = opt.sample_bounds()
	var series: Array = []
	for entry: Array in CAVE_STRIKES:
		series.append(entry)
	for y: int in range(0, 12):
		for x: int in range(0, 44):
			series.append([Vector2i(x, y), 3])
	for entry: Array in series:
		var point: Vector2i = entry[0]
		var marks: int = int(entry[1])
		var base_patch: Dictionary = base.terrain_state.apply_accepted_step(point, 0, marks, true)
		var opt_patch: Dictionary = opt.terrain_state.apply_accepted_step(point, 0, marks, true)
		if not bool(base_patch["accepted"]):
			continue
		var pre_verified: PackedByteArray = opt.walkmap.verified_samples.duplicate()
		var pre_dirty: PackedByteArray = opt.walkmap.dirty_flag.duplicate()
		var base_report: Dictionary = base.walkmap.rebuild_after_strike(base_patch, base.heights(),
			base.gates(), base_bounds)
		var opt_report: Dictionary = opt.walkmap.rebuild_after_strike(opt_patch, opt.heights(),
			opt.gates(), opt_bounds)
		var stride: int = base.walkmap.sample_bounds.size.x
		var diffs: int = 0
		for rect: Rect2i in base_report["rects"]:
			for index: int in _indices(rect, stride):
				if int(base.walkmap.flags[index]) != int(opt.walkmap.flags[index]) \
						or int(base.walkmap.unknown_samples[index]) != int(opt.walkmap.unknown_samples[index]):
					diffs += 1
		if diffs == 0:
			continue
		print("CLASSIFY strike=%s marks=%d diffs=%d base_changed=%d opt_changed=%d" % [
			str(point), marks, diffs, int(base_report["changed"]), int(opt_report["changed"])])
		for rect: Rect2i in base_report["rects"]:
			print("  rect=%s" % str(rect))
		for change: Dictionary in base_patch["changes"]:
			print("  change cell=%s before=%s after=%s" % [
				str(change["cell"]), str(change["before"]), str(change["after"])])
		var stale: int = 0
		var predicate: int = 0
		var state: int = 0
		var shown: int = 0
		var affected: Array[Rect2i] = _affected_rects(base_patch)
		for rect: Rect2i in base_report["rects"]:
			for index: int in _indices(rect, stride):
				if int(base.walkmap.flags[index]) == int(opt.walkmap.flags[index]) \
						and int(base.walkmap.unknown_samples[index]) == int(opt.walkmap.unknown_samples[index]):
					continue
				var sample: Vector2i = Vector2i(index % stride, index / stride)
				var dirty_now: bool = false
				for rect2: Rect2i in affected:
					if rect2.has_point(sample):
						dirty_now = true
						break
				var skipped: bool = int(pre_verified[index]) != 0 and not dirty_now
				var host_value: Variant = BASE_FLAGS.terrain_sample_query(sample, base.heights(), base.gates())
				var gate: Variant = opt.walkmap._gate_at(sample)
				var cached_value: Variant = OPT_FLAGS.terrain_sample_query_cached(sample,
					opt.walkmap.surface_heights, opt.walkmap.grid_origin, opt.walkmap.grid_stride,
					opt.walkmap.grid_rows, gate)
				var kind: String = "STATE"
				if str(host_value) != str(cached_value):
					kind = "PREDICATE"
					predicate += 1
				elif skipped:
					kind = "STALE_SKIP"
					stale += 1
				else:
					state += 1
				if shown < 6:
					shown += 1
					print("  %s sample=%s base=%d/%d opt=%d/%d host=%s cached=%s skipped=%s pre_verified=%d pre_dirty=%d" % [
						kind, str(sample), int(base.walkmap.flags[index]), int(base.walkmap.unknown_samples[index]),
						int(opt.walkmap.flags[index]), int(opt.walkmap.unknown_samples[index]),
						str(host_value), str(cached_value), str(skipped),
						int(pre_verified[index]), int(pre_dirty[index])])
					if kind == "PREDICATE":
						_print_probe_diff(base, opt, sample)
		print("CLASSIFY totals stale_skip=%d predicate=%d state=%d" % [stale, predicate, state])
		break
	quit(0)


func _indices(rect: Rect2i, stride: int) -> Array:
	var result: Array = []
	for y: int in range(rect.position.y, rect.end.y):
		for x: int in range(rect.position.x, rect.end.x):
			result.append(y * stride + x)
	return result


func _affected_rects(patch: Dictionary) -> Array[Rect2i]:
	# Same dilation the optimised walkmap marks as dirty.
	var result: Array[Rect2i] = []
	for change: Dictionary in patch.get("changes", []):
		if int(change.get("before", -1)) == int(change.get("after", -2)):
			continue
		var cell: Vector2i = change["cell"] as Vector2i
		result.append(Rect2i(Vector2i(cell.x * 8 - 7, cell.y * 8 - 1), Vector2i(22, 24)))
		result.append(Rect2i(Vector2i(cell.x * 8 - 4, cell.y * 8 - 4), Vector2i(8, 8)))
	return result


func _print_probe_diff(base: RefCounted, opt: RefCounted, sample: Vector2i) -> void:
	var stride: int = base.walkmap.sample_bounds.size.x
	var gate_cell: Vector2i = Vector2i((sample.x + 4) >> 3, (sample.y + 4) >> 3)
	var host_gate: Variant = base.gates().call(gate_cell)
	var cached_gate: Variant = opt.walkmap._gate_at(sample)
	var cell_index: int = (gate_cell.y - opt.walkmap.cell_origin.y) * opt.walkmap.cell_width \
		+ (gate_cell.x - opt.walkmap.cell_origin.x)
	print("    gate_cell=%s host_gate=%s cached_gate=%s cell_index=%d state=%d value=%d manifest_flags=%s" % [
		str(gate_cell), str(host_gate), str(cached_gate), cell_index,
		int(opt.walkmap.gate_state[cell_index]), int(opt.walkmap.gate_values[cell_index]),
		str(base.terrain_cells.get(gate_cell, {}).get("flags", "<none>"))])
	for extra: Vector2i in [Vector2i.ZERO, Vector2i(0, 1), Vector2i(0, -10), Vector2i(0, -11)]:
		var probe: Vector2i = sample + extra
		var host: Variant = base.terrain_state.surface_depth(Vector2(probe) * 0.125)
		var px: int = probe.x
		var py: int = probe.y
		var cached: int = -999
		if px >= 0 and py >= 0 and px < stride and py < base.walkmap.sample_bounds.size.y:
			cached = int(opt.walkmap.surface_heights[py * stride + px])
		print("    extra %s host=%s cached=%d" % [str(extra), str(host), cached])
	var offsets: Array[Vector2i] = BASE_FLAGS.CLEARANCE_OFFSETS
	for offset: Vector2i in offsets:
		var probe: Vector2i = sample + offset
		var host: Variant = base.terrain_state.surface_depth(Vector2(probe) * 0.125)
		var px: int = probe.x
		var py: int = probe.y
		var cached: int = -999
		if px >= 0 and py >= 0 and px < stride and py < base.walkmap.sample_bounds.size.y:
			cached = int(opt.walkmap.surface_heights[py * stride + px])
		var host_str: String = "<null>" if host == null else str(host)
		var cached_str: String = "<null>" if cached < 0 else str(cached)
		if host_str != cached_str:
			print("    probe %s host=%s cached=%d" % [str(offset), host_str, cached])
