extends RefCounted
## The camera of the campaign chapter: the framing of the native view and the
## control rules for pan, zoom and rotate.
##
## Sources (original install, read-only):
##   data/Scripts/gameplay/Campaign.tcl:10   set_view 246.7 28.8 1.478 -0.29 0.05
##
## MODEL: the chapter is a board. The map lies in the XY plane, the level of a
## cell is its height along Z, and the camera looks down the normal of the
## board: the map is seen in plan, and the height of the rock comes towards the
## viewer, so a dug tunnel is a recess in the surface.
##
## The port follows the battle scene, which renders the same kind of board
## (scripts/multiplayer_test.gd:1929):
##     offset = Vector3(sin(yaw) * cos(tilt), sin(tilt), cos(yaw) * cos(tilt)) * distance
##     camera.position = focus + offset
##     camera.look_at(focus)
## The camera stands on the normal of the board (the Z axis) and is tilted by
## the native rx; the yaw turns the map in plan; the screen up is the row
## direction of the map, the deeper rows of the map are at the bottom of the
## screen, like the board of the original.
##
## rx is the tilt of the native camera from the normal of the board, ry its
## yaw. Every native call has a small negative rx (-0.2 ... -0.35); the sign
## selects the side of the board the camera stands on. The chapter uses
## rx = -0.29, so the tilt from the normal is 0.29 rad (16.6 degrees).
##
## The native zoom is not documented: the distance follows the box of the
## exported chapter.
##
## The scale of the native view is measured on the frame of the original
## (1151x778): a dwarf of the tavern is 22-25 px high there and the tavern is
## 200-220 px wide, so a cell of the map is 22-30 px there and the frame
## covers about 40-45 cells. The visible height of the native view is
## therefore about 29 cells, which is this constant at the native zoom of
## 1.478.
const FOV_DEGREES: float = 38.0
const NATIVE_VIEWPORT_HEIGHT: float = 43.0
const GROUND_LEVEL: float = 14.5
## The battle scene clamps its camera distance to 10..65; the chapter map is
## much wider, so only the near end is shared.
const MIN_DISTANCE: float = 10.0
const MAX_DISTANCE: float = 1400.0
## The distance of the battle scene when the scene opens
## (scripts/multiplayer_test.gd:144) and after the reset key R
## (scripts/multiplayer_test.gd:2126). The chapter opens at the same scale:
## the board is the same board, and the wide framing of the whole chapter is
## a deliberate shot, not the default.
const DEFAULT_DISTANCE: float = 25.0
const MIN_TILT: float = -0.6
const MAX_TILT: float = 1.25
const ROTATE_SPEED: float = 0.006
const PAN_SPEED: float = 0.0017
## The speed of the keyboard pan, in camera distances per second. The battle
## scene moves 9 units per second at its scale; the chapter map is wider, so
## the rate follows the distance of the camera instead.
const KEYBOARD_PAN_RATE: float = 0.35
## One step of the wheel of the battle scene multiplies the distance by 0.9
## (scripts/multiplayer_test.gd:2084-2086).
const ZOOM_STEP: float = 0.9

var focus: Vector3 = Vector3.ZERO
var yaw: float = 0.0
## The tilt of the camera from the normal of the board, in radians. Zero is the
## straight plan view of the map.
var tilt: float = 0.29
var distance: float = 120.0
var fov: float = FOV_DEGREES


## The framing of the native set_view command.
##
## The native y of the map grows away from the camera, so the focus mirrors it.
static func native_view(view: Dictionary, viewport_height: float, fov_degrees: float) -> Dictionary:
	var zoom: float = maxf(float(view.get("zoom", 1.0)), 0.0001)
	var visible_height: float = NATIVE_VIEWPORT_HEIGHT / zoom
	var half_fov: float = deg_to_rad(fov_degrees) * 0.5
	var distance: float = visible_height / (2.0 * tan(half_fov))
	return {
		"focus": Vector3(float(view.get("x", 0.0)), -float(view.get("y", 0.0)), GROUND_LEVEL),
		"yaw": float(view.get("ry", 0.0)),
		"tilt": clamp_tilt(-float(view.get("rx", 0.0))),
		"distance": clamp_distance(distance),
	}


## The framing of a projected box, so the chapter is seen as a whole.
##
## ADAPTER: the size is the size of the chapter on the screen: the width of the
## map and the height of its projection, which depends on the tilt.
static func frame_content(size: Vector2, margin: float, fov_degrees: float, aspect: float) -> Dictionary:
	var visible_height: float = maxf(size.y, size.x / maxf(aspect, 0.0001)) * (1.0 + margin)
	var half_fov: float = deg_to_rad(fov_degrees) * 0.5
	return {
		"distance": clamp_distance(visible_height / (2.0 * tan(half_fov))),
		"visible_height": visible_height,
	}


## The size of the box of the chapter on the screen.
##
## In the plan view the rows of the map are drawn one to one, the relief of the
## rock only adds its height times the sine of the tilt.
static func projected_size(size: Vector2, relief_span: float, tilt_value: float) -> Vector2:
	return Vector2(size.x, size.y + absf(relief_span) * sin(absf(tilt_value)))


func frame(size: Vector2, margin: float, aspect: float) -> void:
	var framing: Dictionary = frame_content(size, margin, fov, aspect)
	distance = float(framing["distance"])


## The focus on a point of the map.
##
## The native view command addresses the focus in map coordinates, so the port
## mirrors the y axis of the map.
func focus_on(centre: Vector2) -> void:
	focus = Vector3(centre.x, -centre.y, focus.z)


static func clamp_tilt(value: float) -> float:
	return clampf(value, MIN_TILT, MAX_TILT)


static func clamp_distance(value: float) -> float:
	return clampf(value, MIN_DISTANCE, MAX_DISTANCE)


## The new focus after a drag of the given pixel amount.
##
## The drag moves the map with the mouse: the pan follows the screen axes of
## the camera, so the map follows the finger in both directions.
static func pan_focus(focus_value: Vector3, yaw_value: float, tilt_value: float,
		distance_value: float, pixels: Vector2) -> Vector3:
	var scale: float = distance_value * PAN_SPEED
	var right := Vector3(cos(yaw_value), 0.0, -sin(yaw_value))
	var up := Vector3(-sin(yaw_value) * sin(tilt_value), cos(tilt_value), -cos(yaw_value) * sin(tilt_value))
	return focus_value - right * pixels.x * scale + up * pixels.y * scale


## The focus after a keyboard pan.
##
## The direction is a screen space vector with the same convention as
## Input.get_vector("move_left", "move_right", "move_up", "move_down"): x is
## right, y is down.
##
## The keys move the camera, not the map: the battle scene reads the same
## actions every frame and moves the focus of the camera with them
## (scripts/multiplayer_test.gd:1989-1992):
##     focus.x += camera_move.x * delta * 9.0
##     focus.y -= camera_move.y * delta * 9.0
## The chapter board lies in the XY plane, so the same rule is written with the
## screen axes of the camera: the focus moves along the right axis of the
## camera and against its up axis.
static func pan_focus_by(focus_value: Vector3, yaw_value: float, tilt_value: float,
		distance_value: float, direction: Vector2, delta: float) -> Vector3:
	var speed: float = distance_value * KEYBOARD_PAN_RATE * delta
	var right := Vector3(cos(yaw_value), 0.0, -sin(yaw_value))
	var up := Vector3(-sin(yaw_value) * sin(tilt_value), cos(tilt_value), -cos(yaw_value) * sin(tilt_value))
	return focus_value + right * direction.x * speed - up * direction.y * speed


## The new distance after a zoom step.
##
## A factor below one moves the camera closer to the map.
static func zoom_distance(distance_value: float, factor: float) -> float:
	return clamp_distance(distance_value * factor)


## The new yaw and tilt after a drag of the given pixel amount.
static func rotate_angles(yaw_value: float, tilt_value: float, pixels: Vector2) -> Vector2:
	var new_yaw: float = yaw_value - pixels.x * ROTATE_SPEED
	var new_tilt: float = clamp_tilt(tilt_value + pixels.y * ROTATE_SPEED)
	return Vector2(new_yaw, new_tilt)


## The zoom factor of one wheel or pinch step.
##
## The wheel of the battle scene multiplies the distance by 0.9 per step
## (scripts/multiplayer_test.gd:2084-2086), so the chapter uses the same
## factor: a positive amount moves the camera closer to the map.
static func zoom_factor(amount: float) -> float:
	if amount > 0.0:
		return pow(ZOOM_STEP, minf(amount, 3.0))
	return pow(1.0 / ZOOM_STEP, minf(-amount, 3.0))


func setup(view: Dictionary) -> void:
	var framing: Dictionary = native_view(view, NATIVE_VIEWPORT_HEIGHT, fov)
	focus = framing["focus"] as Vector3
	yaw = float(framing["yaw"])
	tilt = float(framing["tilt"])
	distance = float(framing["distance"])


func rotate(pixels: Vector2) -> void:
	var angles := rotate_angles(yaw, tilt, pixels)
	yaw = angles.x
	tilt = angles.y


func pan(pixels: Vector2) -> void:
	focus = pan_focus(focus, yaw, tilt, distance, pixels)


func pan_by(direction: Vector2, delta: float) -> void:
	focus = pan_focus_by(focus, yaw, tilt, distance, direction, delta)


func zoom(factor: float) -> void:
	distance = zoom_distance(distance, factor)


## The tilt of the camera from the normal of the board, in radians.
func set_tilt(value: float) -> void:
	tilt = clamp_tilt(value)


## The position of the camera: it stands on the normal of the board and is
## tilted by the tilt of the view.
func camera_position() -> Vector3:
	var offset := Vector3(sin(yaw) * cos(tilt), sin(tilt), cos(yaw) * cos(tilt)) * distance
	return focus + offset


func look_target() -> Vector3:
	return focus
