extends SceneTree
## --headless --path godot --script res://tools/native_campaign_camera_self_test.gd
## Checks the camera of the campaign chapter: the framing of the native view
## and the pan, zoom and rotate rules.
const Camera = preload("res://scripts/native_campaign_camera.gd")

var _checks: int = 0
var _failures: Array[String] = []


func _initialize() -> void:
	call_deferred("_run")


func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures.append(message)
		printerr("FAIL: " + message)


func _run() -> void:
	# --- the native framing (Campaign.tcl:10) --------------------------------
	var view: Dictionary = {"x": 246.7, "y": 28.8, "zoom": 1.478, "rx": -0.29, "ry": 0.05}
	var framing: Dictionary = Camera.native_view(view, 480.0, 38.0)
	var focus: Vector3 = framing["focus"] as Vector3
	_check(absf(focus.x - 246.7) < 0.0001, "the focus keeps the native x")
	_check(absf(focus.y + 28.8) < 0.0001, "the native y is mirrored")
	_check(absf(focus.z - Camera.GROUND_LEVEL) < 0.0001, "the focus sits on the ground level")
	_check(absf(float(framing["yaw"]) - 0.05) < 0.0001, "the yaw keeps the native ry")
	# The native view looks down the normal of the board: rx is the tilt from
	# that normal, so the tilt is small and the map is seen in plan.
	_check(absf(float(framing["tilt"]) - 0.29) < 0.0001,
		"the tilt is the native tilt from the normal of the board")
	_check(float(framing["tilt"]) < 0.35, "the tilt from the normal stays small")

	# The native view is at the scale of the original: a cell of the map is
	# 22-30 px in the frame of the original (1151x778), so the visible height
	# of the view is about 29 cells.
	var expected_distance: float = (43.0 / 1.478) / (2.0 * tan(deg_to_rad(38.0) * 0.5))
	_check(absf(float(framing["distance"]) - expected_distance) < 0.01, "the distance follows the native zoom")
	_check(float(framing["distance"]) > 40.0 and float(framing["distance"]) < 45.0,
		"the native view is at the scale of the frame of the original")

	# --- the limits ----------------------------------------------------------
	_check(Camera.clamp_tilt(5.0) == Camera.MAX_TILT, "the tilt does not tip over")
	_check(Camera.clamp_tilt(-5.0) == Camera.MIN_TILT, "the tilt does not flip under")
	_check(Camera.clamp_distance(1.0) == Camera.MIN_DISTANCE, "the camera does not get into the rock")
	_check(Camera.clamp_distance(99999.0) == Camera.MAX_DISTANCE, "the camera does not leave the chapter")

	# --- pan -----------------------------------------------------------------
	var panned: Vector3 = Camera.pan_focus(Vector3.ZERO, 0.0, 0.0, 100.0, Vector2(10.0, 0.0))
	_check(absf(panned.x + 100.0 * Camera.PAN_SPEED * 10.0) < 0.0001, "a drag to the right moves the map to the right")
	_check(absf(panned.z) < 0.0001, "a drag sideways does not change the height")
	var panned_y: Vector3 = Camera.pan_focus(Vector3.ZERO, 0.0, 0.0, 100.0, Vector2(0.0, 10.0))
	_check(absf(panned_y.y - 100.0 * Camera.PAN_SPEED * 10.0) < 0.0001, "a drag down moves the map down")
	_check(absf(panned_y.z) < 0.0001, "a drag forward does not change the height")
	var panned_tilted: Vector3 = Camera.pan_focus(Vector3.ZERO, 0.0, 0.29, 100.0, Vector2(0.0, 10.0))
	_check(absf(panned_tilted.z + 100.0 * Camera.PAN_SPEED * 10.0 * sin(0.29)) < 0.0001,
		"a tilted camera pans along the screen up, which has a height part")

	# --- zoom ----------------------------------------------------------------
	_check(Camera.zoom_distance(100.0, 0.5) == 50.0, "a smaller factor moves the camera closer")
	_check(Camera.zoom_distance(100.0, 0.5) >= Camera.MIN_DISTANCE, "the camera keeps its distance")
	_check(Camera.zoom_distance(Camera.MIN_DISTANCE, 0.5) == Camera.MIN_DISTANCE, "the camera does not enter the rock")
	_check(Camera.zoom_factor(1.0) < 1.0, "a wheel step zooms in")
	_check(Camera.zoom_factor(-1.0) > 1.0, "a wheel step back zooms out")
	# The battle scene clamps its camera to 10..65; the near end is shared.
	_check(Camera.MIN_DISTANCE <= 10.0, "the camera gets as close as the battle scene")
	# The battle scene opens at the distance 25 (multiplayer_test.gd:144) and
	# multiplies the distance by 0.9 per wheel step (multiplayer_test.gd:2084).
	_check(Camera.DEFAULT_DISTANCE == 25.0, "the chapter opens at the distance of the battle scene")
	_check(absf(Camera.zoom_factor(1.0) - 0.9) < 0.0001, "a wheel step multiplies the distance by 0.9")
	_check(absf(Camera.zoom_factor(-1.0) - 1.0 / 0.9) < 0.0001, "a wheel step back divides the distance by 0.9")
	_check(Camera.zoom_distance(Camera.DEFAULT_DISTANCE, Camera.zoom_factor(1.0)) < Camera.DEFAULT_DISTANCE,
		"the chapter can be zoomed in from its default distance")

	# --- the keyboard pan ----------------------------------------------------
	# The battle scene reads the move actions every frame
	# (multiplayer_test.gd:1989-1992) and moves the focus of the camera with
	# them: focus.x += camera_move.x, focus.y -= camera_move.y. The keys move
	# the camera, so the map moves the other way on the screen, and the keys
	# are not inverted.
	var keyed_right: Vector3 = Camera.pan_focus_by(Vector3.ZERO, 0.0, 0.0, 100.0, Vector2(1.0, 0.0), 1.0)
	_check(absf(keyed_right.x - 100.0 * Camera.KEYBOARD_PAN_RATE) < 0.0001,
		"the right key moves the camera to the right")
	_check(absf(keyed_right.z) < 0.0001, "the keyboard pan does not change the height")
	var keyed_left: Vector3 = Camera.pan_focus_by(Vector3.ZERO, 0.0, 0.0, 100.0, Vector2(-1.0, 0.0), 1.0)
	_check(absf(keyed_left.x + 100.0 * Camera.KEYBOARD_PAN_RATE) < 0.0001,
		"the left key moves the camera to the left")
	var keyed_down: Vector3 = Camera.pan_focus_by(Vector3.ZERO, 0.0, 0.0, 100.0, Vector2(0.0, 1.0), 1.0)
	_check(absf(keyed_down.y + 100.0 * Camera.KEYBOARD_PAN_RATE) < 0.0001,
		"the down key moves the camera down")
	_check(absf(keyed_down.z) < 0.0001, "the keyboard pan does not change the height")
	var keyed_half: Vector3 = Camera.pan_focus_by(Vector3.ZERO, 0.0, 0.0, 100.0, Vector2(1.0, 0.0), 0.5)
	_check(absf(keyed_half.x - 50.0 * Camera.KEYBOARD_PAN_RATE) < 0.0001,
		"the keyboard pan follows the frame time")
	var keyed_tilted: Vector3 = Camera.pan_focus_by(Vector3.ZERO, 0.0, 0.29, 100.0, Vector2(0.0, 1.0), 1.0)
	_check(absf(keyed_tilted.z - 100.0 * Camera.KEYBOARD_PAN_RATE * sin(0.29)) < 0.0001,
		"a tilted camera moves along the screen up, which has a height part")

	# --- rotate --------------------------------------------------------------
	var angles: Vector2 = Camera.rotate_angles(0.0, 0.29, Vector2(100.0, 0.0))
	_check(absf(angles.x + 100.0 * Camera.ROTATE_SPEED) < 0.0001, "a drag turns the camera")
	_check(absf(angles.y - 0.29) < 0.0001, "a horizontal drag does not change the tilt")
	var tilted: Vector2 = Camera.rotate_angles(0.0, 0.29, Vector2(0.0, 10000.0))
	_check(absf(tilted.y - Camera.MAX_TILT) < 0.0001, "the tilt stops at the limit")

	# --- the projected size --------------------------------------------------
	# In the plan view the rows of the map are drawn one to one, the relief of
	# the rock only adds its height times the sine of the tilt.
	var projected: Vector2 = Camera.projected_size(Vector2(100.0, 100.0), 10.0, 0.29)
	_check(projected.x == 100.0, "the width of the map is not compressed")
	_check(projected.y >= 100.0, "the rows of the map are drawn one to one")
	_check(projected.y < 110.0, "the relief of the rock adds only its shadow")
	var flat: Vector2 = Camera.projected_size(Vector2(100.0, 100.0), 10.0, 0.0)
	_check(absf(flat.y - 100.0) < 0.0001, "the straight plan view has no relief on the screen")

	# --- the controller ------------------------------------------------------
	var controller: RefCounted = Camera.new()
	controller.call("setup", view)
	_check(absf(float(controller.call("get", "distance")) - expected_distance) < 0.01, "the controller uses the native distance")
	_check(absf(float(controller.call("get", "tilt")) - 0.29) < 0.0001,
		"the controller uses the native tilt from the normal")

	controller.call("rotate", Vector2(10.0, 0.0))
	_check(absf(float(controller.call("get", "yaw")) - (0.05 - 10.0 * Camera.ROTATE_SPEED)) < 0.0001,
		"the controller turns the camera")
	controller.call("zoom", 0.5)
	_check(absf(float(controller.call("get", "distance")) - expected_distance * 0.5) < 0.01,
		"the controller zooms the camera")
	var position: Vector3 = controller.call("camera_position") as Vector3
	var target: Vector3 = controller.call("look_target") as Vector3
	_check(position.distance_to(target) > 0.0, "the camera looks at the focus")
	# The camera stands on the normal of the board, so it is above the map and
	# the map is seen in plan.
	_check(position.z > target.z, "the camera is above the board")
	var height: float = position.z - target.z
	var sideways: float = Vector2(position.x - target.x, position.y - target.y).length()
	_check(height > sideways, "the camera looks down on the map, not along it")
	var yaw_value: float = float(controller.call("get", "yaw"))
	var tilt_value: float = float(controller.call("get", "tilt"))
	var zoom_distance_value: float = float(controller.call("get", "distance"))
	_check(absf(height - zoom_distance_value * cos(yaw_value) * cos(tilt_value)) < 0.01,
		"the camera stands on the normal of the board")

	if _failures.is_empty():
		print("NATIVE_CAMPAIGN_CAMERA_SELF_TEST_OK assertions=%d" % _checks)
	else:
		printerr("NATIVE_CAMPAIGN_CAMERA_SELF_TEST_FAIL failures=%d" % _failures.size())
	quit(0 if _failures.is_empty() else 1)
