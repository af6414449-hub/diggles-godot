## Handlers for the original animation and walking commands.
##
## The original game executes queued commands with Tcl `eval`. These handlers
## replace the original procedures for the two most common command families and
## reproduce their control flow, including the early exits and the fallback
## chains.
##
## Sources (original install, data/Scripts):
##   classes/zwerg/z_procs.tcl:186-249        - play_anim, play_anim_time,
##                                              play_anim_loop, play_dig_anim_loop
##   classes/zwerg/z_dignwalk.tcl:590-619     - walk_pos, walk_pos_with_box
##   classes/zwerg/z_dignwalk.tcl:724-729     - walk_random
##   classes/zwerg/z_dignwalk.tcl:735-811     - walk_near_item
##   classes/zwerg/z_dignwalk.tcl:814-827     - walk_dummy
##
## Scene dependent primitives are injected as callables, because the original
## ones are native: vector_fix, get_place, get_pos, get_posbottom,
## get_linkpos, obj_valid, walk_action, action/set_anim.
##
## Adapter contract (all optional unless stated):
##   play_clip            Callable(Dictionary) -> bool   (required for play_anim)
##   queue                NativeTaskList                   (required for play_anim_loop)
##   actor_pos            Callable() -> Vector3
##   fix_position         Callable(Vector3) -> Variant     Vector3 or null
##   object_valid         Callable(String) -> bool
##   object_position      Callable(String) -> Variant
##   object_link_position Callable(String, String) -> Variant
##   pick_place           Callable(Dictionary) -> Variant
##   walk_action          Callable(Dictionary) -> bool
##   note_path_length     Callable(Vector3) -> void
##   random_value         Callable() -> float
extends RefCounted

const Aliases = preload("res://scripts/native_animation_aliases.gd")

const WALK_POS_ARGS := 1
const WALK_NEAR_ITEM_ARGS := 2
const WALK_DUMMY_ARGS := 2


## Register play_anim, play_anim_time, play_anim_loop and play_dig_anim_loop.
static func register_animation_handlers(dispatcher: RefCounted, adapters: Dictionary = {}) -> void:
	dispatcher.register("play_anim", func(args: Array) -> bool:
		return _play_anim(args, adapters)
	)
	dispatcher.register("play_anim_time", func(args: Array) -> bool:
		return _play_anim_time(args, adapters)
	)
	dispatcher.register("play_anim_loop", func(args: Array) -> bool:
		return _play_anim_loop(args, adapters)
	)
	dispatcher.register("play_dig_anim_loop", func(args: Array) -> bool:
		return _play_dig_anim_loop(args, adapters)
	)


## Register walk_pos, walk_pos_with_box, walk_random, walk_near_item,
## walk_dummy and walk_outoftransit.
static func register_walk_handlers(dispatcher: RefCounted, adapters: Dictionary = {}) -> void:
	dispatcher.register("walk_pos", func(args: Array) -> bool:
		return _walk_pos(args, adapters, false)
	)
	dispatcher.register("walk_pos_with_box", func(args: Array) -> bool:
		return _walk_pos(args, adapters, true)
	)
	dispatcher.register("walk_random", func(args: Array) -> bool:
		return _walk_random(args, adapters)
	)
	dispatcher.register("walk_near_item", func(args: Array) -> bool:
		return _walk_near_item(args, adapters)
	)
	dispatcher.register("walk_dummy", func(args: Array) -> bool:
		return _walk_dummy(args, adapters)
	)
	dispatcher.register("walk_outoftransit", func(args: Array) -> bool:
		return _walk_outoftransit(args, adapters)
	)


# --- animation --------------------------------------------------------------

## play_anim {anim args} (z_procs.tcl:186)
##
## The original disables the actor state, starts the animation action and - when
## the alias carries a face animation - starts the face sequence as well.
static func _play_anim(args: Array, adapters: Dictionary) -> bool:
	if args.is_empty():
		return false
	var alias_name := String(args[0])
	var clip := Aliases.get_clip(alias_name)
	if clip == "":
		return false
	var request := {
		"alias": alias_name,
		"clip": clip,
		"frames": Aliases.get_frame_count(alias_name),
		"face_anim": Aliases.get_face_anim(alias_name),
		"accident": alias_name.contains("accident"),
		"wait": 0.0,
	}
	if not adapters.has("play_clip"):
		return false
	return bool((adapters["play_clip"] as Callable).call(request))


## play_anim_time {anim time args} (z_procs.tcl:208)
static func _play_anim_time(args: Array, adapters: Dictionary) -> bool:
	if args.size() < 2:
		return false
	var alias_name := String(args[0])
	var clip := Aliases.get_clip(alias_name)
	if clip == "":
		return false
	var request := {
		"alias": alias_name,
		"clip": clip,
		"frames": Aliases.get_frame_count(alias_name),
		"face_anim": Aliases.get_face_anim(alias_name),
		"accident": alias_name.contains("accident"),
		"wait": _to_float(String(args[1])),
	}
	if not adapters.has("play_clip"):
		return false
	return bool((adapters["play_clip"] as Callable).call(request))


## play_anim_loop {animroot cnt} (z_procs.tcl:219)
##
## The original pushes start, loop*cnt and end onto the actor queue with
## tasklist_addfront, so the execution order is start -> loop -> end.
static func _play_anim_loop(args: Array, adapters: Dictionary) -> bool:
	if args.size() < 2:
		return false
	if not adapters.has("queue"):
		return false
	var root := String(args[0])
	var count := int(_to_float(String(args[1])))
	var queue: RefCounted = adapters["queue"]
	# pushed in reverse, exactly like the original addfront chain
	queue.add_front("play_anim %send" % root)
	for _index: int in range(count):
		queue.add_front("play_anim %sloop" % root)
	queue.add_front("play_anim %sstart" % root)
	return true


## play_dig_anim_loop {animroot cnt digpoint acc} (z_procs.tcl:228)
##
## The accident branch depends on the native rand(); the original compares
## acc*0.3 against it. A random_value adapter supplies the draw.
static func _play_dig_anim_loop(args: Array, adapters: Dictionary) -> bool:
	if args.size() < 3:
		return false
	if not adapters.has("queue"):
		return false
	var root := String(args[0])
	var count := int(_to_float(String(args[1])))
	var digpoint := String(args[2])
	var accident_chance: Variant = _to_float(String(args[3])) if args.size() > 3 else 0.0
	var queue: RefCounted = adapters["queue"]
	var draw := 0.0
	if adapters.has("random_value"):
		draw = float((adapters["random_value"] as Callable).call())
	for index: int in range(1, count + 1):
		var command := "play_anim %sloop {%s}" % [root, digpoint]
		if index > 1 and accident_chance != null and float(accident_chance) * 0.3 > draw:
			command = "play_anim %saccident" % root
		if index == count:
			if not adapters.has("play_clip"):
				return false
			var alias_name := "%sloop" % root
			if command.contains("accident"):
				alias_name = "%saccident" % root
			var clip := Aliases.get_clip(alias_name)
			if clip == "":
				return false
			(adapters["play_clip"] as Callable).call({
				"alias": alias_name,
				"clip": clip,
				"frames": Aliases.get_frame_count(alias_name),
				"face_anim": Aliases.get_face_anim(alias_name),
				"accident": command.contains("accident"),
				"wait": 0.0,
			})
		else:
			queue.add_front(command)
	return true


# --- walking ----------------------------------------------------------------

## walk_pos {pos force} and walk_pos_with_box {pos} (z_dignwalk.tcl:590, 607)
##
## The original notes the path length with the raw position, then fixes the
## position with vector_fix and starts the walk action.
static func _walk_pos(args: Array, adapters: Dictionary, with_box: bool) -> bool:
	if args.is_empty():
		return false
	var raw: Variant = parse_position(String(args[0]))
	if raw == null:
		return false
	if adapters.has("note_path_length"):
		(adapters["note_path_length"] as Callable).call(raw)
	var fixed: Variant = raw
	if adapters.has("fix_position"):
		fixed = (adapters["fix_position"] as Callable).call(raw)
	if fixed == null:
		return false
	var params := {
		"target": fixed,
		"waving": 1,
		"forcetarget": 0,
	}
	if not with_box and args.size() > 1:
		params["forcetarget"] = int(_to_float(String(args[1])))
	if with_box:
		params["canclimb"] = 0
		params["withbox"] = true
	if not adapters.has("walk_action"):
		return false
	return bool((adapters["walk_action"] as Callable).call(params))


## walk_random {plength} (z_dignwalk.tcl:724)
static func _walk_random(args: Array, adapters: Dictionary) -> bool:
	if args.is_empty():
		return false
	var length: Variant = _to_float(String(args[0]))
	if length == null:
		return false
	if not adapters.has("pick_place"):
		return false
	var center: Variant = _actor_pos(adapters)
	if center == null:
		return false
	var place: Variant = (adapters["pick_place"] as Callable).call({
		"center": center,
		"circle": length,
		"mindist": 0.7,
		"random": length,
		"walldist": 1,
	})
	if place == null:
		return false
	return _walk_pos([_position_text(place)], adapters, false)


## walk_near_item {item radius tolerance speedtype} (z_dignwalk.tcl:735)
##
## The original has three early exits (already close enough, unreachable target
## in the air) and a three step fallback chain for the walk position.
static func _walk_near_item(args: Array, adapters: Dictionary) -> bool:
	if args.size() < WALK_NEAR_ITEM_ARGS:
		return false
	var item := String(args[0])
	var radius: Variant = _to_float(String(args[1]))
	if radius == null:
		return false
	var tolerance := 0.1
	if args.size() > 2:
		tolerance = _to_float(String(args[2]))
	var speedtype := "auto"
	if args.size() > 3:
		speedtype = String(args[3])

	var itempos: Variant = null
	if _looks_like_position(item):
		itempos = parse_position(item)
	else:
		if not adapters.has("object_valid"):
			return false
		if not bool((adapters["object_valid"] as Callable).call(item)):
			return false
		if not adapters.has("object_position"):
			return false
		itempos = (adapters["object_position"] as Callable).call(item)
	if itempos == null:
		return false

	var thispos: Variant = _actor_pos(adapters)
	if thispos == null:
		return false

	# exit 1: already close enough
	if _distance3d(thispos, itempos) - radius <= tolerance:
		return true

	var walkpos: Variant = null
	if adapters.has("pick_place"):
		walkpos = (adapters["pick_place"] as Callable).call({
			"center": itempos,
			"nearpos": thispos,
			"mindist": radius,
			"circle": radius + 2.0,
			"except": "this",
		})
		if walkpos != null and adapters.has("fix_position"):
			walkpos = (adapters["fix_position"] as Callable).call(walkpos)
		elif walkpos != null:
			walkpos = null
		# second attempt without materials
		if walkpos == null:
			walkpos = (adapters["pick_place"] as Callable).call({
				"center": itempos,
				"nearpos": thispos,
				"mindist": radius,
				"circle": radius + 2.0,
				"except": "this",
				"materials": false,
			})
			if walkpos != null and adapters.has("fix_position"):
				walkpos = (adapters["fix_position"] as Callable).call(walkpos)
			elif walkpos != null:
				walkpos = null
	# last fallback: the fixed item position itself
	if walkpos == null and adapters.has("fix_position"):
		walkpos = (adapters["fix_position"] as Callable).call(itempos)

	if walkpos == null:
		return false

	if adapters.has("note_path_length"):
		(adapters["note_path_length"] as Callable).call(walkpos)

	# exit 2: the fixed position is already close
	if _distance3d(thispos, walkpos) < tolerance:
		return true
	# exit 3: the target floats above the actor and is out of reach
	if float((thispos as Vector3).z) < float((walkpos as Vector3).z) + 2.0 \
			and _distance2d(thispos, walkpos) <= 2.0:
		return true

	var params := {
		"target": walkpos,
		"forcetarget": 0,
	}
	if speedtype != "auto":
		params["speedtype"] = speedtype
	if not adapters.has("walk_action"):
		return false
	return bool((adapters["walk_action"] as Callable).call(params))


## walk_dummy {item dummy speed} (z_dignwalk.tcl:814)
static func _walk_dummy(args: Array, adapters: Dictionary) -> bool:
	if args.size() < WALK_DUMMY_ARGS:
		return false
	var item := String(args[0])
	var dummy := String(args[1])
	var speed := 0
	if args.size() > 2:
		speed = int(_to_float(String(args[2])))
	if not adapters.has("object_valid"):
		return false
	if not bool((adapters["object_valid"] as Callable).call(item)):
		return false
	if not adapters.has("object_position") or not adapters.has("object_link_position"):
		return false
	var base: Variant = (adapters["object_position"] as Callable).call(item)
	var offset: Variant = (adapters["object_link_position"] as Callable).call(item, dummy)
	if base == null or offset == null:
		return false
	var target: Vector3 = (base as Vector3) + (offset as Vector3)
	if adapters.has("note_path_length"):
		(adapters["note_path_length"] as Callable).call(target)
	var params := {
		"object": item,
		"dummy": dummy,
		"speedtype": speed,
	}
	if not adapters.has("walk_action"):
		return false
	return bool((adapters["walk_action"] as Callable).call(params))


## walk_outoftransit {} (z_dignwalk.tcl:846)
##
## Walks out of a transit tube: the z coordinate is clamped to 13 and a small
## offset is added before walking there.
static func _walk_outoftransit(_args: Array, adapters: Dictionary) -> bool:
	var thispos: Variant = _actor_pos(adapters)
	if thispos == null:
		return false
	var pos := thispos as Vector3
	if pos.z <= 13.0:
		return true
	var target := Vector3(pos.x + 0.2, pos.y, 13.0)
	return _walk_pos([_format_position(target)], adapters, false)


# --- helpers ----------------------------------------------------------------

## Parse an original position string "x y z" into a Vector3.
static func parse_position(text: String) -> Variant:
	var parts := text.strip_edges().split(" ", false)
	if parts.size() != 3:
		return null
	var values: Array[float] = []
	for part: String in parts:
		var value: Variant = _to_float(part)
		if value == null:
			return null
		values.append(value)
	return Vector3(values[0], values[1], values[2])


static func _format_position(value: Vector3) -> String:
	return "%s %s %s" % [str(value.x), str(value.y), str(value.z)]


## Turn a place value into the original position text.
static func _position_text(place: Variant) -> String:
	if place is Vector3:
		return _format_position(place)
	return String(place)


## A single element list is an object reference, a three element list a position.
static func _looks_like_position(text: String) -> bool:
	return parse_position(text) != null


static func _to_float(text: String) -> Variant:
	var value := text.strip_edges()
	if value == "":
		return null
	if not value.is_valid_float():
		return null
	return value.to_float()


static func _actor_pos(adapters: Dictionary) -> Variant:
	if not adapters.has("actor_pos"):
		return null
	return (adapters["actor_pos"] as Callable).call()


static func _distance3d(a: Variant, b: Variant) -> float:
	if not (a is Vector3) or not (b is Vector3):
		return INF
	return (a as Vector3).distance_to(b as Vector3)


static func _distance2d(a: Variant, b: Variant) -> float:
	if not (a is Vector3) or not (b is Vector3):
		return INF
	var first := a as Vector3
	var second := b as Vector3
	return Vector2(first.x, first.y).distance_to(Vector2(second.x, second.y))
