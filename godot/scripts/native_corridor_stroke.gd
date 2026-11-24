extends RefCounted
## Source selection contract with an uncommitted, replaceable preview.
## Native press/motion/release: EXE 0x5664F0, 0x566830, 0x566550.

const SELECTION: Script = preload("res://scripts/native_corridor_selection.gd")

var active: bool = false
var anchor: Vector2 = Vector2.ZERO
var endpoint: Vector2 = Vector2.ZERO
var bounds: Rect2i = Rect2i()


func begin(raw: Vector2, sample_bounds: Rect2i) -> bool:
	cancel()
	if not raw.is_finite() or raw.x < 0.0 or raw.y < 0.0:
		return false
	bounds = sample_bounds
	anchor = SELECTION.snap_start(raw)
	endpoint = anchor
	active = true
	if samples().is_empty():
		cancel()
		return false
	return true


func update(raw: Vector2) -> void:
	if not active or not raw.is_finite() or raw.x < 0.0 or raw.y < 0.0:
		return
	endpoint = SELECTION.snap_drag(raw, anchor)


func samples() -> Array[Vector2i]:
	if not active:
		return []
	return SELECTION.rasterize(anchor, endpoint, bounds)


func finish() -> Array[Vector2i]:
	# The release position is deliberately not an argument: native commit uses
	# the last stored endpoint, even when release carries different coordinates.
	var result: Array[Vector2i] = samples()
	cancel()
	return result


func cancel() -> void:
	active = false
