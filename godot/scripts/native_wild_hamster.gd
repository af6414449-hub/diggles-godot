extends Node3D
## Wild hamster in the game world.
##
## The original multiplayer level places four wild hamsters as ordinary objects
## (the placement list in res://models/multi_start_010_models.json carries them
## with the line numbers of the original Tcl: 141, 147, 231, 237). In the
## original game those objects are not scenery: they are instances of the
## class in hamster.tcl, they decide what to do and they walk around.
##
## This node is that object:
##   - the control flow comes from native_hamster_actor.gd, the port of
##     hamster.tcl (idle and task states, the wild activity table, the escape
##     test, the feeding, the gnome sensor);
##   - the pictures come from native_hamster_clips.gd, the 28 original clips
##     of the hamster.3db package;
##   - the world comes from the host scene: the dwarves, the food, the
##     navigation grid and the heading convention of the project.
##
## Host adapters (the multiplayer scene supplies them):
##   dwarf_positions  Callable() -> Array[Vector3]      local positions
##   food_entries     Callable() -> Array[Dictionary]  {ref, position}
##   walk_path        Callable(Vector3, Vector3) -> Array[Vector3]
##   free_spot        Callable(Vector3, float, float, Array) -> Variant
##   apply_heading    Callable(Node3D, float) -> void    the node and the heading
##   depth_scale      Callable() -> float
##   is_walkable      Callable(Vector3) -> bool          ground under the point
##
## The host may also pass "initial_heading", the direction the model looks to
## when the hamster is placed.
##
## All positions are local to the host space, which is the logical game space:
## the scan range of four and the escape range of two are game units.

const Actor = preload("res://scripts/native_hamster_actor.gd")
const Clips = preload("res://scripts/native_hamster_clips.gd")
const Animations = preload("res://scripts/native_hamster_animations.gd")

const CLASS_ID := "Hamster"
const ANIMSET_WALK := "0"
const ANIMSET_HOPPEL := "1"

# Adapter values: the native walk action owns the speed and the frame rate in
# the original game, the Tcl only names the animset.
const WALK_SPEED := 1.6
const HOPPEL_SPEED := 1.2
const WALK_FRAME_FPS := 12.0

# The turn of the original.
#
# The native walk action turns the object towards the direction of the path
# before it walks and plays the turn clip of the animset while it turns
# (hamster.tcl:48-51). The clip only shows the step of the turn, the rotation
# of the body belongs to the engine, so the heading is rotated here while the
# original clip plays. The class uses the same clip for the ninety degree and
# for the hundred eighty degree turn.
#
# A turn of at least TURN_CLIP_MIN_ANGLE plays the clip, a smaller one is
# only rotated. TURN_SPEED is the rate of the rotation without a clip: the
# engine keeps that rate in its binary, it is not in the data of the game.
const TURN_CLIP_MIN_ANGLE := 1.4
const TURN_SPEED := 90.0
const TURN_EPSILON := 0.05

# How many directions the random path finder tries before it gives up, so the
# hamster never walks into the void when the place is blocked.
const FALLBACK_TRIES := 8

# The original: a dwarf that wants to pick the hamster up calls
# activate_gnomesensor on it (z_procs.tcl:473) and walks near the item with
# walk_near_item $item 0.6 0.2 2 - the last number is the radius.
const SENSOR_TRIGGER_DISTANCE := 2.0

var actor: RefCounted = null

var _host: Dictionary = {}
var _body_root: Node3D = null
var _body_instances: Array[MeshInstance3D] = []
var _last_clip: String = ""
var _last_frame: int = -1
var _path: Array[Vector3] = []
var _path_index: int = 0
var _walk_state: String = ""
var _walk_animset: String = ANIMSET_WALK
var _walk_clip: String = ""
var _walk_frame: int = 0
var _walk_time: float = 0.0
var _walk_speed: float = WALK_SPEED
var _idle_time: float = 0.0
var _last_delta: float = 0.0
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


## Start the hamster with the world adapters of the host scene.
func setup(host: Dictionary = {}) -> void:
	_host = host.duplicate()
	_heading = float(_host.get("initial_heading", 0.0))
	actor = Actor.new()
	actor.call("setup", _build_adapters())
	_body_root = Node3D.new()
	_body_root.name = "HamsterBody"
	add_child(_body_root)
	set_process(true)


## The world the hamster acts in.
func _build_adapters() -> Dictionary:
	return {
		"actor_pos": func() -> Vector3: return position,
		"query_dwarves": func(_range: float) -> Array: return _dwarf_positions(),
		"query_food": func(search_range: float) -> Array: return _food_entries(search_range),
		"is_contained": func() -> bool: return false,
		"is_underwater": func() -> bool: return false,
		"pick_place": func(request: Dictionary) -> Variant: return _pick_place(request),
		"walk_action": func(params: Dictionary) -> bool: return _start_walk(params),
		"walk_complete": func() -> bool: return _walk_complete(),
		"play_clip": func(request: Dictionary) -> bool: return _play_clip(request),
		"delete_item": func(reference: String) -> void: _delete_item(reference),
		"object_position": func(reference: String) -> Variant: return _object_position(reference),
		"random_int": func(low: int, high: int) -> int: return _random_int(low, high),
		"random_float": func(low: float, high: float) -> float: return _random_float(low, high),
		"now": func() -> float: return Time.get_ticks_msec() / 1000.0,
	}


func _process(delta: float) -> void:
	_last_delta = maxf(0.0, delta)
	if actor == null:
		return
	_check_gnome_sensor()
	actor.call("tick", delta)
	_sync_visual()


## The gnome sensor of the original.
##
## A dwarf that comes close to the hamster and wants to take it activates the
## sensor (z_procs.tcl:473). The sensor makes the hamster check for dwarves
## every second for ten seconds, and that is what makes it run away.
func _check_gnome_sensor() -> void:
	if actor == null:
		return
	var distance := nearest_dwarf_distance(_dwarf_positions(), position)
	if distance <= SENSOR_TRIGGER_DISTANCE:
		actor.call("activate_gnomesensor")


## The dwarves of the host scene.
func _dwarf_positions() -> Array:
	var provider: Variant = _host.get("dwarf_positions", null)
	if not (provider is Callable):
		return []
	var result: Variant = (provider as Callable).call()
	if not (result is Array):
		return []
	return result as Array


## The edible objects of the host scene within the search range.
func _food_entries(search_range: float) -> Array:
	var provider: Variant = _host.get("food_entries", null)
	if not (provider is Callable):
		return []
	var result: Variant = (provider as Callable).call()
	if not (result is Array):
		return []
	var entries: Array = []
	for entry: Dictionary in result as Array:
		var item_position: Variant = entry.get("position", null)
		if not (item_position is Vector3):
			continue
		if (item_position as Vector3).distance_to(position) > search_range:
			continue
		entries.append(entry)
	return entries


## get_place of the original (hamster.tcl:216 and :139-143).
##
## The escape asks for a free spot around the preferred escape point, the
## random walk asks for a free spot around the hamster itself.
func _pick_place(request: Dictionary) -> Variant:
	var center: Variant = request.get("center", null)
	if not (center is Vector3):
		return null
	var provider: Variant = _host.get("free_spot", null)
	if not (provider is Callable):
		return center
	var radius := float(request.get("circle", 4.0))
	var mindist := float(request.get("mindist", 0.0))
	var clip: Array = request.get("clip", [])
	return (provider as Callable).call(center as Vector3, radius, mindist, clip)


## The walk action of the original (hamster.tcl:139-163).
##
## The native walk action picks the path and plays the animset of the walk.
## Here the host scene provides the path and the animset gives the clips.
func _start_walk(params: Dictionary) -> bool:
	var target: Variant = params.get("target", null)
	if not (target is Vector3):
		var length := float(params.get("random_path", 4.0))
		target = _pick_place({
			"center": position,
			"circle": length,
			"mindist": 0.7,
			"random": length,
			"walldist": 1,
		})
		if not (target is Vector3):
			# No free spot: the original falls back to the random path finder.
			target = _fallback_target(length)
		if not (target is Vector3):
			# No ground to walk to: the walk does not start.
			_walk_state = ""
			_path.clear()
			return false
	_path = _walk_path(position, target as Vector3)
	if _path.is_empty():
		_path = [(target as Vector3)]
	_path_index = 0
	_walk_animset = String(params.get("animsets", ANIMSET_WALK))
	_walk_speed = WALK_SPEED if _walk_animset == ANIMSET_WALK else HOPPEL_SPEED
	_walk_state = "start"
	_walk_time = 0.0
	_walk_frame = 0
	_walk_clip = walk_clip_for(_walk_animset, "start")
	return true


## The path of the host scene.
func _walk_path(from: Vector3, to: Vector3) -> Array[Vector3]:
	var provider: Variant = _host.get("walk_path", null)
	if not (provider is Callable):
		return []
	var result: Variant = (provider as Callable).call(from, to)
	if not (result is Array):
		return []
	var path: Array[Vector3] = []
	for point: Vector3 in result as Array:
		path.append(point)
	return path


## The random path finder of the original.
##
## The native walk action walks a random path of the given length when
## get_place finds nothing. The direction is only taken when there is ground
## under the end of the path, so the hamster never walks into the void.
func _fallback_target(length: float) -> Variant:
	for attempt: int in range(FALLBACK_TRIES):
		var angle := randf() * TAU
		var candidate := position + Vector3(cos(angle) * length, 0.0, sin(angle) * length)
		if _is_walkable(candidate):
			return candidate
	return null


## Is there ground under the point?
##
## The host knows the level the hamster stands on, the floor of the main level
## and the floor of the upper terrace.
func _is_walkable(point: Vector3) -> bool:
	var provider: Variant = _host.get("is_walkable", null)
	if not (provider is Callable):
		return true
	return bool((provider as Callable).call(point))


## Advance the walk and report whether it is over.
##
## The original walk action plays start, loop and end of the animset while it
## moves, so the hamster keeps its feet in the right animation.
func _walk_complete() -> bool:
	if _walk_state == "":
		return true
	if _turn_active:
		# The original turns before it walks: the rotate action blocks the walk
		# while the turn clip of the class plays.
		_advance_turn(_last_delta)
		if _turn_blocks:
			return false
	if _advance_walk_clip():
		_walk_state = ""
		_path.clear()
		return true
	if _walk_state == "start" or _walk_state == "loop":
		_move_along_path()
	return false


## Move the hamster along the path and turn it into the direction of the walk.
func _move_along_path() -> void:
	if _path.is_empty() or _path_index >= _path.size():
		return
	var waypoint: Vector3 = _path[_path_index]
	var current := Vector2(position.x, position.z)
	var target := Vector2(waypoint.x, waypoint.z)
	var direction := current.direction_to(target)
	if direction.length_squared() > 0.0:
		var wanted := heading_for_direction(direction, _depth_scale())
		var delta := wrapf(wanted - _heading, -PI, PI)
		if absf(delta) > TURN_EPSILON:
			# The original turns first. A turn of ninety degrees or more plays
			# the turn clip and blocks the walk, a smaller one is only rotated
			# while the hamster goes on.
			_start_turn(delta)
			if _turn_blocks:
				return
	var next := current.move_toward(target, _walk_speed * _last_delta)
	var step := Vector3(next.x, position.y, next.y)
	if not _is_walkable(step) and _is_walkable(position):
		# The ground ends here, the walk stops on the last ground.
		_finish_walk()
		return
	position = step
	if next.is_equal_approx(target):
		_path_index += 1
		if _path_index >= _path.size():
			_finish_walk()


## The walk is over, the end clip of the animset is played.
func _finish_walk() -> void:
	_walk_state = "end"
	_walk_time = 0.0
	_walk_frame = 0
	_walk_clip = walk_clip_for(_walk_animset, "end")


## Start the turn of the original (hamster.tcl:48-51).
##
## The walk action turns the object towards the direction of the path and plays
## the turn clip of the animset while it turns. The hamster class uses the same
## clip for the ninety degree and the hundred eighty degree turn.
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
	var clip := Animations.get_animset_clip(CLASS_ID, _walk_animset, role)
	if clip != "":
		return clip
	var alias := "turnleft"
	if delta < 0.0:
		alias = "turnright"
	if absf(delta) >= PI:
		alias = "turn180left"
		if delta < 0.0:
			alias = "turn180right"
	return Animations.get_clip(CLASS_ID, alias)


## How long the turn takes.
##
## With a turn clip the rotation lasts as long as the clip, without one it
## lasts the time the angle needs at the turn rate of the adapter.
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
	_apply_heading(_heading)


## Advance the clip of the walk animset.
##
## Returns true when the walk is over, which is the case when the end clip of
## the animset has been played.
func _advance_walk_clip() -> bool:
	if _walk_state == "":
		return true
	var frames := Clips.frame_count(_walk_clip)
	if frames <= 0:
		return true
	_walk_time += _last_delta
	var requested := int(floor(_walk_time * WALK_FRAME_FPS))
	if requested < frames:
		_walk_frame = requested
		return false
	match _walk_state:
		"start":
			_walk_state = "loop"
			_walk_clip = walk_clip_for(_walk_animset, "loop")
			_walk_time = 0.0
			_walk_frame = 0
			return false
		"loop":
			_walk_frame = requested % frames
			return false
		_:
			return true


## Show the frame of the clip that is played.
##
## While the hamster walks, the walk animset decides the picture. Otherwise
## the actor decides, and the idle picture of the original is the standby
## animation (hamster.tcl:93).
func _sync_visual() -> void:
	if actor == null or _body_root == null:
		return
	var clip := ""
	var frame := -1
	if _turn_active and _turn_clip != "":
		# While the hamster turns, the turn clip of the original is shown.
		clip = _turn_clip
		frame = _turn_frame
	elif _walk_state != "":
		clip = _walk_clip
		frame = _walk_frame
	else:
		clip = String(actor.call("get_current_clip"))
		frame = int(actor.call("get_current_frame"))
		if clip == "":
			clip = Animations.get_clip(CLASS_ID, "standstill")
			_idle_time += _last_delta
			var idle_frames := Clips.frame_count(clip)
			if idle_frames > 0:
				frame = int(floor(_idle_time * WALK_FRAME_FPS)) % idle_frames
			else:
				frame = -1
	if clip == "" or frame < 0:
		return
	if clip == _last_clip and frame == _last_frame:
		return
	if clip != _last_clip:
		print("WILD_HAMSTER %s clip=%s pos=%s" % [String(name), clip, str(position)])
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
	if _walk_state != "":
		return _walk_clip
	if actor == null:
		return ""
	return String(actor.call("get_current_clip"))


## The frame that is shown right now.
func get_current_frame() -> int:
	if _turn_active and _turn_clip != "":
		return _turn_frame
	if _walk_state != "":
		return _walk_frame
	if actor == null:
		return -1
	return int(actor.call("get_current_frame"))


## The heading the hamster looks to.
func get_heading() -> float:
	return _heading


## The host applies the heading of the hamster with the packing convention of
## the scene.
##
## The node is passed on, so the host turns the hamster that walks and not all
## of them at once.
func _apply_heading(heading: float) -> void:
	var provider: Variant = _host.get("apply_heading", null)
	if provider is Callable:
		(provider as Callable).call(self, heading)


func _depth_scale() -> float:
	var provider: Variant = _host.get("depth_scale", null)
	if provider is Callable:
		return float((provider as Callable).call())
	return 1.0


## The clip of the walk animset.
##
## animset 0 is the walk (laufen_*), animset 1 is the hop (hoppeln_*), the
## third one is the gallop. This is the class scoped table of hamster.tcl.
static func walk_clip_for(animset: String, part: String) -> String:
	var role := "walk_loop"
	match part:
		"start":
			role = "walk_start"
		"end":
			role = "walk_stop"
	return Animations.get_animset_clip(CLASS_ID, animset, role)


## The heading of the project for a direction on the ground.
##
## The multiplayer scene packs the depth by 0.5, so the heading of the scene
## is the same one the dwarves use: atan2 of the direction with the depth
## correction.
static func heading_for_direction(direction: Vector2, depth_scale: float) -> float:
	return atan2(direction.x, direction.y * depth_scale)


## Distance to the closest dwarf.
static func nearest_dwarf_distance(dwarves: Array, origin: Vector3) -> float:
	var best := INF
	for entry: Variant in dwarves:
		var dwarf_position: Variant = entry
		if not (dwarf_position is Vector3):
			continue
		var distance := Vector2(origin.x - (dwarf_position as Vector3).x,
			origin.z - (dwarf_position as Vector3).z).length()
		if distance < best:
			best = distance
	return best


## Is the dwarf close enough to make the hamster run away?
static func sensor_should_trigger(dwarf_distance: float) -> bool:
	return dwarf_distance <= SENSOR_TRIGGER_DISTANCE


func _play_clip(request: Dictionary) -> bool:
	return String(request.get("clip", "")) != ""


func _delete_item(reference: String) -> void:
	var provider: Variant = _host.get("delete_item", null)
	if provider is Callable:
		(provider as Callable).call(reference)


func _object_position(reference: String) -> Variant:
	var provider: Variant = _host.get("object_position", null)
	if provider is Callable:
		return (provider as Callable).call(reference)
	return null


func _random_int(low: int, high: int) -> int:
	if high < low:
		return low
	return randi_range(low, high)


func _random_float(low: float, high: float) -> float:
	if high < low:
		return low
	return randf_range(low, high)
