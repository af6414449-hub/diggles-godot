extends RefCounted
## One actor's finite source clip. The caller supplies its time contract:
## recovered native timing or an explicitly identified action-specific adapter.
## Completion is emitted once per run.

var elapsed: float = 0.0
var frame_count: int = 0
var fps: float = 12.0
var active: bool = false


func begin(count: int, adapter_fps: float) -> void:
	elapsed = 0.0
	frame_count = count
	fps = adapter_fps
	active = count > 0 and fps > 0.0


func advance(delta: float) -> Dictionary:
	if not active:
		return {"frame": -1, "complete": false}
	elapsed += maxf(0.0, delta)
	var frame: int = int(floor(elapsed * fps))
	if frame >= frame_count:
		active = false
		return {"frame": frame_count - 1, "complete": true}
	return {"frame": frame, "complete": false}
