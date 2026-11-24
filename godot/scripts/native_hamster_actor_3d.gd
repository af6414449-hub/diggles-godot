## Scene binding for the autonomous hamster actor.
##
## The behaviour lives in native_hamster_actor.gd. This node feeds the actor
## with the world, runs the clock and shows the original clips of the
## hamster.3db package.
##
## World adapters (all optional, the scene fallback is used without them):
##   query_dwarves Callable(float range) -> Array
##   query_food    Callable(float range) -> Array
##   query_farm    Callable(float range) -> Dictionary
##   pick_place    Callable(Dictionary) -> Variant
##   walk_action   Callable(Dictionary) -> bool
##   walk_complete Callable() -> bool
##
## Scene fallback conventions:
##   group "dwarf"   - the dwarves the hamster fears
##   group "food"    - edible objects (mushroom hats)
##   group "farm"    - the pen the hamster lives in
##   group "container" - objects that hold an actor (paralysis)
extends Node3D

const Actor = preload("res://scripts/native_hamster_actor.gd")
const Clips = preload("res://scripts/native_hamster_clips.gd")
const Animations = preload("res://scripts/native_hamster_animations.gd")

const GROUP_DWARF := "dwarf"
const GROUP_FOOD := "food"
const GROUP_FARM := "farm"
const GROUP_CONTAINER := "container"
const WALK_SPEED := 1.6
const WALK_REACHED := 0.12
const WALK_FRAME_FPS := 12.0

# The turn of the original (hamster.tcl:48-51): the walk action turns the
# object before it walks and plays the turn clip of the animset while it
# turns. The clip only shows the step of the turn, the rotation of the body
# belongs to the engine, so the heading is rotated here while the clip plays.
const TURN_CLIP_MIN_ANGLE := 1.4
const TURN_SPEED := 90.0
const TURN_EPSILON := 0.05

var actor: RefCounted = null

var _adapters: Dictionary = {}
var _body_root: Node3D = null
var _body_instances: Array[MeshInstance3D] = []
var _last_clip: String = ""
var _last_frame: int = -1
var _walk_target: Variant = null
var _walk_speed: float = WALK_SPEED
var _walk_clip: String = ""
var _walk_frame: int = -1
var _walk_time: float = 0.0
var _last_delta: float = 0.0
var _idle_time: float = 0.0
var _heading: float = 0.0
var _turn_active: bool = false
var _turn_delta: float = 0.0
var _turn_to: float = 0.0
var _turn_sign: float = 1.0
var _turn_speed: float = 0.0
var _turn_time: float = 0.0
var _turn_frame: int = 0
var _turn_clip: String = ""
var _turn_blocks: bool = false


## Start the hamster with the given world adapters.
func setup(adapters: Dictionary = {}) -> void:
	_adapters = adapters.duplicate()
	actor = Actor.new()
	actor.call("setup", _build_adapters())
	_body_root = Node3D.new()
	_body_root.name = "HamsterBody"
	add_child(_body_root)
	set_process(true)


## The world the hamster acts in.
func _build_adapters() -> Dictionary:
	var world: Dictionary = {
		"actor_pos": func() -> Vector3: return global_position,
		"query_dwarves": func(_range: float) -> Array: return _dwarf_positions(),
		"query_food": func(_range: float) -> Array: return _food_entries(),
		"query_farm": func(_range: float) -> Dictionary: return _farm_entry(),
		"is_contained": func() -> bool: return _is_contained(),
		"is_underwater": func() -> bool: return false,
		"pick_place": func(request: Dictionary) -> Variant: return _pick_place(request),
		"walk_action": func(params: Dictionary) -> bool: return _start_walk(params),
		"walk_complete": func() -> bool: return _walk_complete(),
		"play_clip": func(_request: Dictionary) -> bool: return true,
		"delete_item": func(reference: String) -> void: _delete_item(reference),
		"object_position": func(reference: String) -> Variant: return _object_position(reference),
		"random_int": func(low: int, high: int) -> int: return _random_int(low, high),
		"random_float": func(low: float, high: float) -> float: return _random_float(low, high),
		"now": func() -> float: return Time.get_ticks_msec() / 1000.0,
	}
	for key: String in _adapters.keys():
		world[key] = _adapters[key]
	return world


func _process(delta: float) -> void:
	_last_delta = maxf(0.0, delta)
	if actor == null:
		return
	actor.call("tick", delta)
	_sync_visual()


## Show the frame of the clip the actor is playing.
func _sync_visual() -> void:
	if actor == null or _body_root == null:
		return
	var clip := get_current_clip()
	var frame := get_current_frame()
	if clip == "" or frame < 0:
		return
	if clip == _last_clip and frame == _last_frame:
		return
	_last_clip = clip
	_last_frame = frame
	var meshes := Clips.frame_meshes(clip, frame)
	while _body_instances.size() < meshes.size():
		var instance := MeshInstance3D.new()
		_body_root.add_child(instance)
		_body_instances.append(instance)
	for index: int in range(_body_instances.size()):
		var instance := _body_instances[index]
		instance.visible = index < meshes.size()
		if instance.visible:
			instance.mesh = meshes[index]


# --- world fallback -----------------------------------------------------------

func _dwarf_positions() -> Array:
	var positions: Array = []
	for node: Node in get_tree().get_nodes_in_group(GROUP_DWARF):
		if node is Node3D:
			positions.append((node as Node3D).global_position)
	return positions


func _food_entries() -> Array:
	var entries: Array = []
	for node: Node in get_tree().get_nodes_in_group(GROUP_FOOD):
		if node is Node3D:
			entries.append({"ref": String(node.name), "position": (node as Node3D).global_position})
	return entries


func _farm_entry() -> Dictionary:
	for node: Node in get_tree().get_nodes_in_group(GROUP_FARM):
		if node is Node3D:
			return {"ref": String(node.name), "position": (node as Node3D).global_position}
	return {}


func _is_contained() -> bool:
	# lint:ignore group_ref -- container nodes are supplied dynamically by host scenes.
	for node: Node in get_tree().get_nodes_in_group(GROUP_CONTAINER):
		if node is Node3D and (node as Node3D).is_ancestor_of(self):
			return true
	return false


## Position of an edible object by its node name.
func _object_position(reference: String) -> Variant:
	for node: Node in get_tree().get_nodes_in_group(GROUP_FOOD):
		if node is Node3D and String(node.name) == reference:
			return (node as Node3D).global_position
	return null


## Remove an eaten object.
func _delete_item(reference: String) -> void:
	for node: Node in get_tree().get_nodes_in_group(GROUP_FOOD):
		if node is Node3D and String(node.name) == reference:
			node.queue_free()
			return


# --- walking fallback ---------------------------------------------------------
#
# The original hands the target to the native walk action. Without the project
# pathfinder the hamster walks straight to the target; a host with a pathfinder
# replaces walk_action and walk_complete.

## Fallback for the original get_place.
##
## A request with "random" asks for a random spot around the center (the
## random walk of the hamster), a request without it asks for the preferred
## center of a flight. The original reports "nothing found" with a negative
## coordinate, so the fallback keeps the world coordinates positive.
func _pick_place(request: Dictionary) -> Variant:
	var center: Variant = request.get("center", null)
	if not (center is Vector3):
		return null
	if request.has("random"):
		var radius := float(request.get("random", 4.0))
		var minimum := float(request.get("mindist", 0.0))
		var offset := Vector3(randf_range(-radius, radius), 0.0, randf_range(-radius, radius))
		if offset.length() < minimum:
			offset = offset.normalized() * minimum if offset.length() > 0.0 else Vector3(minimum, 0.0, 0.0)
		return (center as Vector3) + offset
	return center


func _start_walk(params: Dictionary) -> bool:
	# The native walk action plays the animset of the walk, so the host has to
	# show the walk clip while the hamster moves.
	var animset := String(params.get("animsets", "0"))
	_walk_clip = Animations.get_animset_clip("Hamster", animset, "walk_loop")
	_walk_time = 0.0
	_walk_frame = -1
	# A new walk turns again, the turn of the old walk is over.
	_turn_active = false
	_turn_clip = ""
	if params.has("target"):
		_walk_target = params["target"]
		return true
	# a random walk without a target: pick a reachable point around the actor
	var length := float(params.get("random_path", 4.0))
	_walk_target = global_position + Vector3(randf_range(-length, length), 0.0, randf_range(-length, length))
	return true


func _walk_complete() -> bool:
	if not (_walk_target is Vector3):
		_walk_target = null
		_walk_clip = ""
		return true
	if _turn_active:
		# The original turns before it walks: the rotate action blocks the walk
		# while the turn clip of the class plays.
		_advance_turn(_last_delta)
		if _turn_blocks:
			return false
	var target := _walk_target as Vector3
	var delta := target - global_position
	delta.y = 0.0
	if delta.length() <= WALK_REACHED:
		global_position = Vector3(target.x, global_position.y, target.z)
		_walk_target = null
		_walk_clip = ""
		return true
	# The model turns into the direction of the walk, like the native walk
	# action does. Without it the hamster walks sideways.
	var direction := delta.normalized()
	var wanted := atan2(direction.x, direction.z)
	var turn := wrapf(wanted - _heading, -PI, PI)
	if absf(turn) > TURN_EPSILON:
		# The original turns first. A turn of ninety degrees or more plays the
		# turn clip and blocks the walk, a smaller one is only rotated while
		# the hamster goes on.
		_start_turn(turn)
		if _turn_blocks:
			return false
	global_position += direction * _walk_speed * _last_delta
	_advance_walk_clip()
	return false


## Start the turn of the original (hamster.tcl:48-51).
##
## The walk action turns the object towards the direction of the path and plays
## the turn clip of the animset while it turns.
func _start_turn(delta: float) -> void:
	_turn_active = true
	_turn_delta = delta
	_turn_to = wrapf(_heading + delta, -PI, PI)
	_turn_sign = signf(delta)
	_turn_time = 0.0
	_turn_frame = 0
	_turn_blocks = absf(delta) >= TURN_CLIP_MIN_ANGLE
	_turn_clip = _turn_clip_for(delta) if _turn_blocks else ""
	_turn_speed = absf(delta) / maxf(0.0001, _turn_duration(delta))


## The turn clip of the class for the angle of the turn.
##
## The walk animset names the turn roles, the hop and the gallop animset have
## none, so the class aliases are the fallback (hamster.tcl:6-9).
func _turn_clip_for(delta: float) -> String:
	var role := "turn_left_90"
	if delta < 0.0:
		role = "turn_right_90"
	if absf(delta) >= PI:
		role = "turn_left_180"
		if delta < 0.0:
			role = "turn_right_180"
	var clip := Animations.get_animset_clip("Hamster", "0", role)
	if clip != "":
		return clip
	var alias := "turnleft"
	if delta < 0.0:
		alias = "turnright"
	if absf(delta) >= PI:
		alias = "turn180left"
		if delta < 0.0:
			alias = "turn180right"
	return Animations.get_clip("Hamster", alias)


## How long the turn takes.
func _turn_duration(delta: float) -> float:
	if _turn_clip != "":
		var frames := Clips.frame_count(_turn_clip)
		if frames > 0:
			return float(frames) / WALK_FRAME_FPS
	return absf(delta) / deg_to_rad(TURN_SPEED)


## Rotate the hamster while the turn clip plays.
func _advance_turn(delta: float) -> void:
	_turn_time += delta
	if _turn_clip != "":
		var frames := Clips.frame_count(_turn_clip)
		if frames > 0:
			_turn_frame = mini(int(floor(_turn_time * WALK_FRAME_FPS)), frames - 1)
	var step := _turn_speed * delta
	var remaining := absf(_turn_delta) - step
	if remaining <= 0.0:
		_heading = _turn_to
		_turn_delta = 0.0
		_turn_active = false
	else:
		_turn_delta = _turn_sign * remaining
		_heading = wrapf(_heading + _turn_sign * step, -PI, PI)
	rotation.y = _heading


## The clip that is shown right now.
##
## While the hamster turns, the turn clip of the original decides the picture,
## while it walks the walk animset does, otherwise the actor of the class does.
##
## A turn that is too small for the turn clip has no picture of its own: the
## turn clip is only played from ninety degrees on, so the walk animset keeps
## the picture during a small turn.
func get_current_clip() -> String:
	if _turn_active and _turn_clip != "":
		return _turn_clip
	if _walk_clip != "":
		return _walk_clip
	if actor == null:
		return ""
	var clip := String(actor.call("get_current_clip"))
	if clip != "":
		return clip
	# Nothing is played: the standby picture of the original is shown
	# (hamster.tcl:93), so the hamster is never a picture without a clip.
	return Animations.get_clip("Hamster", "standstill")


## The frame that is shown right now.
func get_current_frame() -> int:
	if _turn_active and _turn_clip != "":
		return _turn_frame
	if _walk_clip != "":
		return _walk_frame
	if actor == null:
		return -1
	if String(actor.call("get_current_clip")) == "":
		# The standby picture of the original loops while nothing is played.
		_idle_time += _last_delta
		var frames := Clips.frame_count(Animations.get_clip("Hamster", "standstill"))
		if frames > 0:
			return int(floor(_idle_time * WALK_FRAME_FPS)) % frames
		return -1
	return int(actor.call("get_current_frame"))


## Play the walk clip of the animset while the hamster moves.
func _advance_walk_clip() -> void:
	if _walk_clip == "":
		return
	var frames := Clips.frame_count(_walk_clip)
	if frames <= 0:
		return
	_walk_time += _last_delta
	_walk_frame = int(floor(_walk_time * WALK_FRAME_FPS)) % frames


# --- randomness ----------------------------------------------------------------

func _random_int(low: int, high: int) -> int:
	if high < low:
		return low
	return randi_range(low, high)


func _random_float(low: float, high: float) -> float:
	if high < low:
		return low
	return randf_range(low, high)
