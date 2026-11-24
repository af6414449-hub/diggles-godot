extends SceneTree
## Mining latency probe.
##
## Measures the synchronous cost of a dig strike and splits it into the parts
## the handoff asks to profile separately:
##
##   * walkmap rebuild          (native_walkmap.rebuild_after_strike)
##   * terrain geometry rebuild (_build_geometry: SurfaceTool -> ArrayMesh ->
##                                 mesh commit, collision shape, scene insert)
##   * open-air re-indexing     (_index_open_air)
##   * navigation rebuild       (deferred, measured separately)
##   * GPU upload               (the frame that first draws the new mesh)
##
## The strike path in multiplayer_test.gd is fully synchronous:
##   native_dig_apply_cell -> _queue_terrain_refresh -> _flush_terrain_refresh
##   -> _build_geometry + _index_open_air
## so the whole cost lands inside the strike call and shows up as a frame hitch.
##
## Usage:
##   godot --headless --path godot \
##       --script res://tools/mining_latency_probe.gd -- --burst-cells 24
##   godot --path godot --rendering-driver opengl3 \
##       --script res://tools/mining_latency_probe.gd -- --burst-cells 24
##
## The windowed run is required for the GPU upload numbers; the headless run
## gives the CPU split only.

var subject: Node3D = null
var burst_cells: int = 24
var windowed: bool = false


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var index: int = args.find("--burst-cells")
	if index >= 0 and index + 1 < args.size():
		burst_cells = maxi(1, int(args[index + 1]))
	windowed = DisplayServer.get_name() != "headless"

	subject = load("res://scenes/multiplayer_test.tscn").instantiate() as Node3D
	subject.extended_world = false
	subject.autonomous_dwarf_work = false
	# The scene already instruments the refresh; let it print the split.
	subject.verbose_runtime_trace = true
	root.add_child(subject)
	await process_frame
	print("MINING_LATENCY scene ready trace=%s processing=%s" % [
		str(subject.verbose_runtime_trace), str(subject.is_processing())])

	# Warm up: first frames pay shader compilation and the initial draw of all
	# 793 terrain surfaces. They must not pollute the idle baseline.
	for warmup_index: int in range(30):
		await process_frame
		if windowed:
			await RenderingServer.frame_post_draw

	# Baseline frame cost without any strike.
	var quiet_frames: Array[float] = []
	for repeat_index: int in range(8):
		var quiet_started: int = Time.get_ticks_usec()
		await process_frame
		# The dummy renderer of --headless never emits frame_post_draw, so the
		# GPU-side wait is only possible with a real rendering context.
		if windowed:
			await RenderingServer.frame_post_draw
		quiet_frames.append(float(Time.get_ticks_usec() - quiet_started) / 1000.0)

	# A corridor dug away from the start cave, one cell per strike, exactly how
	# a dwarf pick advances the tunnel. The native tunnel rule accepts a cell
	# only when int((x-1)/2) and int((y-1)/2) share the same low bit, so the
	# diggable cells of one row sit in pairs four columns apart.
	var corridor: Array[Vector2i] = []
	var columns: Array[int] = [9, 10, 13, 14, 17, 18, 21, 22, 25, 26, 29, 30,
		33, 34, 37, 38, 41, 42, 5, 6, 1, 2]
	for step: int in range(mini(burst_cells, columns.size())):
		corridor.append(Vector2i(columns[step], 19))

	var strike_ms: Array[float] = []
	var frame_ms: Array[float] = []
	var accepted: int = 0
	var rejected: int = 0
	for point: Vector2i in corridor:
		var marked: bool = subject.native_mark_corridor_cell(0, point)
		if not marked:
			rejected += 1
			print("MINING_LATENCY skip %s mark rejected" % str(point))
			continue
		var strike_started: int = Time.get_ticks_usec()
		var applied: bool = subject.native_dig_apply_cell(0, point)
		strike_ms.append(float(Time.get_ticks_usec() - strike_started) / 1000.0)
		if not applied:
			rejected += 1
			print("MINING_LATENCY skip %s apply rejected" % str(point))
			continue
		accepted += 1
		# The first frame that draws the rebuilt chunk carries the GPU upload.
		var frame_started: int = Time.get_ticks_usec()
		await process_frame
		if windowed:
			await RenderingServer.frame_post_draw
		frame_ms.append(float(Time.get_ticks_usec() - frame_started) / 1000.0)
		print("MINING_LATENCY strike %s total_ms=%.3f frame_ms=%.3f" % [
			str(point), strike_ms[strike_ms.size() - 1], frame_ms[frame_ms.size() - 1]])

	print("MINING_LATENCY accepted=%d rejected=%d" % [accepted, rejected])
	print("MINING_LATENCY strike_ms  " + str(_stats(strike_ms)))
	print("MINING_LATENCY quiet_ms   " + str(_stats(quiet_frames)))
	if not frame_ms.is_empty():
		print("MINING_LATENCY frame_ms   " + str(_stats(frame_ms)))
	print("MINING_LATENCY refreshes=%d navigation_refreshes=%d" % [
		int(subject.terrain_refresh_count), int(subject.navigation_refresh_count)])

	# The navigation rebuild is coalesced and deferred; force it and time it.
	if subject.navigation_refresh_pending:
		var navigation_started: int = Time.get_ticks_usec()
		subject._flush_navigation_refresh()
		print("MINING_LATENCY navigation_flush_ms=%.3f" % (
			float(Time.get_ticks_usec() - navigation_started) / 1000.0))

	subject.queue_free()
	await process_frame
	quit(0)


func _stats(values: Array) -> Dictionary:
	if values.is_empty():
		return {"count": 0}
	var sorted: Array = values.duplicate()
	sorted.sort()
	var total: float = 0.0
	for value: Variant in sorted:
		total += float(value)
	return {"count": sorted.size(),
		"mean": total / float(sorted.size()),
		"p50": sorted[floori(float(sorted.size()) * 0.5)],
		"p95": sorted[mini(sorted.size() - 1, int(float(sorted.size()) * 0.95))],
		"min": sorted[0], "max": sorted[sorted.size() - 1]}
