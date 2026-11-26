extends SceneTree
## ADAPTER: isolated chapter input routing without building the whole map.

const LEVEL: Script = preload("res://scripts/native_campaign_first_level.gd")


class ProbeController:
	extends RefCounted
	var rotations: int = 0
	var pans: int = 0
	func rotate(_relative: Vector2) -> void:
		rotations += 1
	func pan(_relative: Vector2) -> void:
		pans += 1


class ProbeDig:
	extends RefCounted
	var dragging: bool = false
	var releases: int = 0
	func handle_input(event: InputEvent) -> bool:
		if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT \
				and not event.pressed:
			releases += 1
			dragging = false
			return true
		return false
	func _update_hover(_screen: Vector2) -> void:
		pass


class ProbeDwarfs:
	extends RefCounted
	var calls: int = 0
	func handle_input(_event: InputEvent) -> bool:
		calls += 1
		return false


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var level := Node3D.new()
	get_root().add_child(level)
	level.set_script(LEVEL)
	var controller := ProbeController.new()
	var dig := ProbeDig.new()
	var dwarfs := ProbeDwarfs.new()
	level.set("controller", controller)
	level.set("dig_test", dig)
	level.set("dwarfs", dwarfs)
	var left := InputEventMouseButton.new()
	left.button_index = MOUSE_BUTTON_LEFT
	left.pressed = true
	left.position = Vector2(100, 100)
	level.call("_unhandled_input", left)
	var motion := InputEventMouseMotion.new()
	motion.relative = Vector2(30, 10)
	motion.position = Vector2(130, 110)
	level.call("_unhandled_input", motion)
	assert(controller.rotations == 0 and controller.pans == 0)
	var right := InputEventMouseButton.new()
	right.button_index = MOUSE_BUTTON_RIGHT
	right.pressed = true
	level.call("_unhandled_input", right)
	level.call("_unhandled_input", motion)
	assert(controller.rotations == 0 and controller.pans == 1)
	right.pressed = false
	level.call("_unhandled_input", right)
	dig.dragging = true
	var release := InputEventMouseButton.new()
	release.button_index = MOUSE_BUTTON_LEFT
	release.pressed = false
	release.position = Vector2(130, 110)
	var dwarf_calls: int = dwarfs.calls
	level.call("_input", release)
	assert(dig.releases == 1 and not dig.dragging)
	assert(dwarfs.calls == dwarf_calls)
	print("CAMPAIGN_INPUT_TEST_OK left_camera_still=1 right_pan=1 tool_owns_release=1")
	quit(0)
