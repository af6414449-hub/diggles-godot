extends SceneTree
## Debug helper: find the first sample where the optimised walkmap diverges from
## the full rebuild and explain why.

const HARNESS: Script = preload("res://tools/walkmap_harness.gd")
const BASELINE_WALKMAP: Script = preload("res://baseline/scripts/native_walkmap.gd")
const OPT_WALKMAP: Script = preload("res://scripts/native_walkmap.gd")

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
		var base_report: Dictionary = base.walkmap.rebuild_after_strike(base_patch, base.heights(),
			base.gates(), base_bounds)
		var opt_report: Dictionary = opt.walkmap.rebuild_after_strike(opt_patch, opt.heights(),
			opt.gates(), opt_bounds)
		var stride: int = base.walkmap.sample_bounds.size.x
		var diffs: int = 0
		for index: int in range(base.walkmap.flags.size()):
			if int(base.walkmap.flags[index]) != int(opt.walkmap.flags[index]) \
					or int(base.walkmap.unknown_samples[index]) != int(opt.walkmap.unknown_samples[index]):
				diffs += 1
				if diffs <= 3:
					var sample: Vector2i = Vector2i(index % stride, index / stride)
					var host_height: Variant = opt.terrain_state.surface_depth(Vector2(sample) * 0.125)
					print("  DEBUG diff at %s base=%d/%d opt=%d/%d verified=%d dirty=%d host_h=%s cached_h=%d" % [
						str(sample), int(base.walkmap.flags[index]), int(base.walkmap.unknown_samples[index]),
						int(opt.walkmap.flags[index]), int(opt.walkmap.unknown_samples[index]),
						int(opt.walkmap.verified_samples[index]), int(opt.walkmap.dirty_flag[index]),
						str(host_height), int(opt.walkmap.surface_heights[index])])
		if diffs > 0:
			print("DEBUG opt_report=%s" % str(opt_report))
			print("DEBUG base_report=%s" % str(base_report))
			print("DEBUG strike=%s marks=%d base_changed=%d opt_changed=%d opt_rebuilt=%d opt_skipped=%d diffs=%d base_unknown=%d opt_unknown=%d" % [
				str(point), marks, int(base_report["changed"]), int(opt_report["changed"]),
				int(opt_report["rebuilt"]), int(opt_report["skipped"]), diffs,
				int(base.walkmap.unknown_count), int(opt.walkmap.unknown_count)])
			for change: Dictionary in base_patch["changes"]:
				print("  DEBUG change cell=%s before=%s after=%s" % [
					str(change["cell"]), str(change["before"]), str(change["after"])])
			for rect: Rect2i in base_report["rects"]:
				print("  DEBUG base rect=%s" % str(rect))
			_dump_sample(base, opt, Vector2i(0, 65))
			break
	quit(0)


func _dump_sample(base: RefCounted, opt: RefCounted, sample: Vector2i) -> void:
	var stride: int = base.walkmap.sample_bounds.size.x
	var index: int = sample.y * stride + sample.x
	print("  DEBUG probe dump for %s cached_h=%d state=%d verified=%d dirty=%d" % [
		str(sample), int(opt.walkmap.surface_heights[index]),
		int(opt.walkmap.surface_state[index]), int(opt.walkmap.verified_samples[index]),
		int(opt.walkmap.dirty_flag[index])])
	print("  DEBUG base block (0,8)=%d opt block (0,8)=%d base (0,7)=%d opt (0,7)=%d" % [
		base.terrain_state.block_ref(Vector2i(0, 8)), opt.terrain_state.block_ref(Vector2i(0, 8)),
		base.terrain_state.block_ref(Vector2i(0, 7)), opt.terrain_state.block_ref(Vector2i(0, 7))])
	var offsets: Array[Vector2i] = preload("res://scripts/native_walk_flags.gd").CLEARANCE_OFFSETS
	for offset: Vector2i in offsets:
		var probe: Vector2i = sample + offset
		var host: Variant = opt.terrain_state.surface_depth(Vector2(probe) * 0.125)
		var base_host: Variant = base.terrain_state.surface_depth(Vector2(probe) * 0.125)
		var px: int = probe.x
		var py: int = probe.y
		var cached: int = -999
		if px >= 0 and py >= 0 and px < stride and py < base.walkmap.sample_bounds.size.y:
			cached = int(opt.walkmap.surface_heights[py * stride + px])
		if str(host) != str(cached) or str(host) != str(base_host):
			print("  DEBUG probe %s opt_host=%s base_host=%s cached=%d" % [
				str(offset), str(host), str(base_host), cached])
	var gate_cell: Vector2i = Vector2i((sample.x + 4) >> 3, (sample.y + 4) >> 3)
	print("  DEBUG gate_cell=%s base_gate=%s opt_gate=%s" % [str(gate_cell),
		str(base.gates().call(gate_cell)), str(opt.gates().call(gate_cell))])
