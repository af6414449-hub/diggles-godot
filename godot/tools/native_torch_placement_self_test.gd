extends SceneTree
## Headless pure tests; no main scene, terrain mutation or exporter writes.
const PLACEMENT: Script = preload("res://scripts/native_torch_placement.gd")
var _checks: int = 0
var _failures: int = 0
var _calls: Array[Vector2i] = []
var _depths: Dictionary = {}
var _cell_bytes: Dictionary = {}
const POS: Vector3 = Vector3(10.25, 11.75, 9.0)
const ROT: Vector3 = Vector3(0.125, 0.25, -0.5)
const SAMPLE: Vector2i = Vector2i(82, 94)
const BOUNDS: Vector4i = Vector4i(0, 0, 160, 160)


func _initialize() -> void:
	call_deferred("_run")


func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures += 1
		push_error(message)


func _depth(at: Vector2i) -> Variant:
	_calls.append(at)
	return _depths.get(at)


func _cell(at: Vector2i) -> Variant:
	_calls.append(at)
	return _cell_bytes.get(at)


func _snap(tick: int = 101, object_id: int = 5, flags: int = 0x20000,
		sample_xy: Vector2i = SAMPLE) -> Dictionary:
	return PLACEMENT.snap_step(POS, ROT, flags, tick, object_id, sample_xy,
		BOUNDS, _depth)


func _release(z: float = 1.0, rect: Variant = Vector4i(10, 11, 12, 13),
		type_value: int = 0) -> Dictionary:
	return PLACEMENT.release_step(z, 0x20020, type_value, rect,
		Vector4i(0, 0, 20, 20), _cell)


func _run() -> void:
	var offsets: Array[Vector2i] = [Vector2i.ZERO, Vector2i(-2, 0),
		Vector2i(2, 0), Vector2i(0, -2), Vector2i(0, 2)]
	for offset: Vector2i in offsets:
		_depths[SAMPLE + offset] = 14
	for index: int in range(5):
		_depths[SAMPLE + offsets[index]] = 3
		_calls.clear()
		var result: Dictionary = _snap()
		_check(result.status == "snapped", "scheduled snap")
		_check(result.position == Vector3(POS.x, POS.y, 3.009999990463257),
			"minimum at each of five offsets; f32 bias")
		_check(result.rotation == ROT and result.flags == 0x20000,
			"snap preserves rotation and flags")
		_check(_calls == offsets.map(func(v: Vector2i) -> Vector2i: return SAMPLE + v),
			"five sample query order")
		_depths[SAMPLE + offsets[index]] = 14
	for value: int in [0, 15, 255]:
		for key: Vector2i in _depths:
			_depths[key] = value
		var result: Dictionary = _snap()
		_check(result.status == "snapped", "no producer depth<15 filter in snap")
		_check(result.position.z == float(PackedFloat32Array([float(value) + PLACEMENT.Z_BIAS])[0]),
			"depth byte is native Z, no /8")
	for args: Array in [[100, 4, 0x20000], [101, 4, 0x20000],
			[101, 5, 0], [101, 5, 0x24000]]:
		_calls.clear()
		_check(_snap(args[0], args[1], args[2]).status == "unchanged", "schedule/flag gate")
		_check(_calls.is_empty(), "gate must not query depth")
	for edge: Vector2i in [Vector2i(3, 94), Vector2i(156, 94),
			Vector2i(82, 3), Vector2i(82, 156)]:
		_calls.clear()
		_check(_snap(101, 5, 0x20000, edge).status == "unchanged", "margin4 half-open")
		_check(_calls.is_empty(), "out of bounds must not query")
	_depths.erase(SAMPLE)
	_check(_snap().status == "deferred" and _snap().position == POS,
		"missing depth cannot invent a transform")
	_check(_release(0.0).flags == 0x20, "z below .02 releases only snap bit")
	_check(_release(PLACEMENT.RELEASE_Z, null).status == "deferred", "threshold is strict")
	_check(_release(1.0, null, 1).status == "unchanged", "class+54 nonzero bypass")
	_check(_release(1.0, Vector4i(-1, -1, -1, -1)).status == "unchanged", "invalid native rect")
	_check(_release(1.0, Vector4i(10, 11, 20, 13)).status == "unchanged", "coarse upper bound strict")
	var corners: Array[Vector2i] = [Vector2i(10, 11), Vector2i(10, 13),
		Vector2i(12, 11), Vector2i(12, 13)]
	for corner: Vector2i in corners:
		_cell_bytes[corner] = 4
	_calls.clear()
	_check(_release().flags == 0x20 and _calls == corners, "all four low2 clear releases")
	for corner: Vector2i in corners:
		for value: int in [1, 2, 3]:
			_cell_bytes[corner] = value
			_check(_release().flags == 0x20020, "any corner low2 retains snap")
		_cell_bytes[corner] = 4
	_cell_bytes.erase(corners[0])
	_check(_release().status == "deferred", "missing cell flags")
	_check(PLACEMENT.animation_rect(Vector2(10.25, 11.75), null) == Vector4i(10, 11, 11, 12),
		"native no-frame fallback is explicit, not a collision footprint")
	_check(PLACEMENT.animation_rect(Vector2.ZERO, null) == Vector4i(-1, -1, -1, -1),
		"nonpositive XY")
	_check(PLACEMENT.animation_rect(Vector2(10.25, 11.75), Vector4(-400, -200, 400, 200))
		== Vector4i(8, 10, 13, 13), "frame bounds scale, truncation, +1")
	# Release runs on nonscheduled updates too: do not snap immediately on creation.
	var delayed: Dictionary = _snap(102, 5)
	var released: Dictionary = PLACEMENT.release_step(0.0, delayed.flags, 0,
		null, Vector4i.ZERO, _cell)
	_check(released.flags == 0, "unscheduled update can release before first snap")
	for offset: Vector2i in offsets:
		_depths[SAMPLE + offset] = 0
	var snap_result: Dictionary = _snap()
	_check(_release(snap_result.position.z).flags == 0x20, "min0 + .01 releases on same update")
	var source: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_torches.json"))
	var source_frames: Array = source["model"]["frames"]
	_check(source_frames.size()==2,"source standard torch has two frames")
	for frame: Dictionary in source_frames:
		var values: Array = frame["rect_fields"]
		var rect: Vector4i = PLACEMENT.animation_rect(Vector2(10.25,11.75),Vector4(float(values[0]),float(values[1]),float(values[2]),float(values[3])))
		_check(rect==Vector4i(10,11,11,13),"original 3DB frame bounds feed native release rectangle")
	print("NATIVE_TORCH_PLACEMENT_SELF_TEST checks=%d failures=%d" % [_checks, _failures])
	quit(1 if _failures else 0)
