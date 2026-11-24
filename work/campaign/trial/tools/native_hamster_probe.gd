extends SceneTree
## --headless --path godot --script res://tools/native_hamster_probe.gd
## Diagnostic: runs the hamster demo scene and prints what the hamsters do.
##
## The headless main loop runs unthrottled, so the frame counter is not game
## time. The probe waits on the wall clock and reports the actor time.
const DEMO := "res://scenes/native_hamster_demo.tscn"

var _scene: Node = null
var _frames: int = 0
var _delta_sum: float = 0.0


func _initialize() -> void:
	call_deferred("_run")


func _process(delta: float) -> bool:
	_frames += 1
	_delta_sum += delta
	return false


func _run() -> void:
	var wall_start := Time.get_ticks_msec()
	_scene = load(DEMO).instantiate()
	root.add_child(_scene)
	for _round: int in range(12):
		await create_timer(1.0).timeout
		_report()
	_report()
	print("PROBE wall_ms=%d frames=%d delta_sum=%.3f" % [
		Time.get_ticks_msec() - wall_start, _frames, _delta_sum])
	quit(0)


func _report() -> void:
	for child: Node in _scene.get_children():
		if not (child is Node3D):
			continue
		var actor: Variant = child.get("actor")
		if actor == null:
			continue
		print("%s t=%.1f pos=%s alias=%s clip=%s state=%s action=%s enabled=%s queue=%s" % [
			String(child.name),
			float(actor.call("get_time")),
			str((child as Node3D).position),
			String(actor.call("get_current_alias")),
			String(actor.call("get_current_clip")),
			String(actor.call("get_state_name")),
			String(actor.call("get_action_kind")),
			str(actor.call("is_state_enabled")),
			str(actor.call("get_queue_commands"))])
