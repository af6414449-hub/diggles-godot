extends SceneTree
## --headless --path godot --script res://tools/native_hamster_actor_self_test.gd
## Checks the exported hamster clips and the autonomous hamster actor:
## decisions, queue, command dispatch, animation playback, escape, feeding,
## the farm pen and the paralysis timer.
const Actor = preload("res://scripts/native_hamster_actor.gd")
const Actor3D = preload("res://scripts/native_hamster_actor_3d.gd")
const Clips = preload("res://scripts/native_hamster_clips.gd")
const HamsterAnimations = preload("res://scripts/native_hamster_animations.gd")

var _checks: int = 0
var _failures: Array[String] = []


## Mutable world used by the actor adapters.
class FakeWorld extends RefCounted:
	var position: Vector3 = Vector3.ZERO
	var dwarves: Array[Vector3] = []
	var food: Array[Dictionary] = []
	var farm: Dictionary = {}
	var contained: bool = false
	var underwater: bool = false
	var place_available: bool = true
	var walk_result: int = 0
	var time: float = 0.0
	var random_value: int = 0
	var walks: Array[Dictionary] = []
	var clips: Array[Dictionary] = []
	var deleted: Array[String] = []


func _initialize() -> void:
	call_deferred("_run")


func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures.append(message)
		printerr("FAIL: " + message)


func _adapters(world: FakeWorld) -> Dictionary:
	return {
		"actor_pos": func() -> Vector3: return world.position,
		"query_dwarves": func(_range: float) -> Array: return world.dwarves,
		"query_food": func(_range: float) -> Array: return world.food,
		"is_contained": func() -> bool: return world.contained,
		"is_underwater": func() -> bool: return world.underwater,
		"pick_place": func(request: Dictionary) -> Variant:
			if not world.place_available:
				return null
			return request.get("center", null),
		"walk_action": func(params: Dictionary) -> bool:
			world.walks.append(params)
			return true,
		"play_clip": func(request: Dictionary) -> bool:
			world.clips.append(request)
			return true,
		"delete_item": func(reference: String) -> void: world.deleted.append(reference),
		"object_position": func(reference: String) -> Variant:
			for entry: Dictionary in world.food:
				if String(entry.get("ref", "")) == reference:
					return entry.get("position", null)
			return null,
		"random_int": func(_low: int, _high: int) -> int: return world.random_value,
		"random_float": func(low: float, _high: float) -> float: return low,
		"now": func() -> float: return world.time,
		"walk_result": func() -> int: return world.walk_result,
	}


func _make_actor(world: FakeWorld) -> RefCounted:
	var actor: RefCounted = Actor.new()
	actor.call("setup", _adapters(world))
	return actor


func _tick(actor: RefCounted, world: FakeWorld, seconds: float, step: float = 0.1) -> void:
	var remaining := seconds
	while remaining > 0.0:
		world.time += step
		actor.call("tick", step)
		remaining -= step


func _history(actor: RefCounted) -> Array[String]:
	return actor.call("get_history")


func _events(actor: RefCounted) -> Array[Dictionary]:
	return actor.call("get_events")


func _has_event(actor: RefCounted, name: String) -> bool:
	for event: Dictionary in _events(actor):
		if String(event.get("event", "")) == name:
			return true
	return false


func _event_count(actor: RefCounted, name: String) -> int:
	var count := 0
	for event: Dictionary in _events(actor):
		if String(event.get("event", "")) == name:
			count += 1
	return count


func _run() -> void:
	_test_clip_data()
	_test_wild_hamster()
	_test_loop_animation()
	_test_escape()
	_test_cornered()
	_test_feeding()
	_test_farm()
	_test_paralysis()
	_test_scene_binding()

	if _failures.is_empty():
		print("NATIVE_HAMSTER_ACTOR_SELF_TEST_OK assertions=%d" % _checks)
	else:
		printerr("NATIVE_HAMSTER_ACTOR_SELF_TEST_FAIL failures=%d" % _failures.size())
	quit(0 if _failures.is_empty() else 1)


# --- exported clips -----------------------------------------------------------

func _test_clip_data() -> void:
	_check(Clips.clip_names().size() == 28, "the package exports 28 clips")
	_check(Clips.has_clip("stand_anim"), "stand_anim is exported")
	_check(Clips.frame_count("stand_anim") == 12, "stand_anim has 12 frames")
	_check(Clips.frame_count("maennchen") == 17, "maennchen has 17 frames")
	_check(Clips.frame_count("sterben") == 21, "sterben has 21 frames")
	_check(Clips.frame_count("getroffen") == 15, "getroffen has 15 frames")
	_check(Clips.frame_count("not_a_clip") == -1, "an unknown clip has no frames")

	# every alias of the class must point at an exported clip with the same count
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_hamster_animations.json"))
	_check(decoded is Dictionary, "the alias table is readable")
	var aliases: Dictionary = (decoded as Dictionary)["classes"]["Hamster"]["aliases"]
	_check(aliases.size() == 27, "the class has 27 aliases")
	var unresolved := 0
	var mismatched := 0
	for alias_name: String in aliases.keys():
		var clip := String((aliases[alias_name] as Dictionary).get("target", ""))
		if clip.begins_with("hamster."):
			clip = clip.substr("hamster.".length())
		if not Clips.has_clip(clip):
			unresolved += 1
			continue
		if Clips.frame_count(clip) != int((aliases[alias_name] as Dictionary).get("frames", -1)):
			mismatched += 1
	_check(unresolved == 0, "every alias points at an exported clip")
	_check(mismatched == 0, "the alias table and the clip export agree on the frame counts")

	# the frames carry real geometry
	var meshes := Clips.frame_meshes("stand_anim", 0)
	_check(meshes.size() >= 1, "a frame builds at least one mesh")
	if meshes.size() >= 1:
		var mesh := meshes[0] as ArrayMesh
		_check(mesh.get_surface_count() == 1, "the mesh has one surface")
		_check(mesh.surface_get_array_len(0) > 0, "the surface has vertices")
	_check(FileAccess.file_exists("res://textures/models/Character_Hamster_a_128.tga"),
		"the hamster texture is imported")


# --- autonomous behaviour ------------------------------------------------------

func _test_wild_hamster() -> void:
	var world := FakeWorld.new()
	var actor := _make_actor(world)
	_tick(actor, world, 0.2)
	_check(actor.call("get_nutrition") == 1, "the first idle step counts the nutrition up")
	_check(String(actor.call("get_current_alias")) == "beg",
		"the hamster starts a mating animation")
	_check(String(actor.call("get_current_clip")) == "maennchen",
		"the mating animation is the original clip")
	_check(world.clips.size() >= 1, "the host is told which clip to show")
	if world.clips.size() >= 1:
		_check(String((world.clips[0] as Dictionary).get("clip", "")) == "maennchen",
			"the host receives the hamster clip name")
		_check(int((world.clips[0] as Dictionary).get("frames", 0)) == 17,
			"the host receives the original frame count")
	_check(actor.call("is_playing_animation"), "the actor is busy while the clip plays")
	var last_frame := -1
	for _step: int in range(30):
		_tick(actor, world, 0.1)
		if String(actor.call("get_current_clip")) == "maennchen":
			last_frame = maxi(last_frame, int(actor.call("get_current_frame")))
	_check(last_frame == 16, "the mating clip runs through its last frame")
	_check(last_frame >= 0, "the original frame count drives the playback")


func _test_loop_animation() -> void:
	var world := FakeWorld.new()
	world.position = Vector3(20, 0, 20)
	var actor := _make_actor(world)
	# the first activity is beg (activity 0 is shifted to 1), the second is clean
	_tick(actor, world, 8.0)
	_tick(actor, world, 8.0)
	var history := _history(actor)
	var start_count := 0
	var loop_count := 0
	var stop_count := 0
	for command: String in history:
		if command == "play_anim cleanstart":
			start_count += 1
		elif command == "play_anim cleanloop":
			loop_count += 1
		elif command == "play_anim cleanstop":
			stop_count += 1
	_check(start_count >= 1, "the grooming loop queues its start clip")
	_check(loop_count >= 2, "the grooming loop repeats at least twice")
	_check(stop_count >= 1, "the grooming loop queues its stop clip")
	var clean_clips := 0
	for entry: Dictionary in world.clips:
		if String(entry.get("alias", "")).begins_with("clean"):
			clean_clips += 1
	_check(clean_clips >= 3, "every grooming clip is played")
	var played := ""
	for entry: Dictionary in world.clips:
		if String(entry.get("alias", "")) == "cleanstart":
			played = String(entry.get("clip", ""))
	_check(played == "putzen_start", "the grooming start clip is the original one")


func _test_escape() -> void:
	var world := FakeWorld.new()
	world.position = Vector3(20, 0, 20)
	world.dwarves = [Vector3(23, 0, 20)]
	var actor := _make_actor(world)
	_tick(actor, world, 0.5)
	var history := _history(actor)
	_check(history.has("walk_pos {18.0 0.0 20.0}"),
		"the hamster runs away from the dwarf")
	_check(world.walks.size() >= 1, "the walk action is started")
	if world.walks.size() >= 1:
		var params: Dictionary = world.walks[0]
		_check(String(params.get("animsets", "")) == "0", "the escape uses the walk animset")
		_check(int(params.get("can_climb", -1)) == 0, "the hamster cannot climb")
		_check(int(params.get("use_objects", -1)) == 0, "the hamster ignores objects")
		_check((params.get("target", null) as Vector3) == Vector3(18, 0, 20),
			"the escape target is the flee point")


func _test_cornered() -> void:
	var world := FakeWorld.new()
	world.position = Vector3(20, 0, 20)
	world.dwarves = [Vector3(23, 0, 20)]
	world.place_available = false
	var actor := _make_actor(world)
	_tick(actor, world, 0.5)
	var history := _history(actor)
	_check(history.has("walk_random 5"), "a cornered hamster takes the random path")
	_check(world.walks.size() >= 1, "the random walk action is started")
	if world.walks.size() >= 1:
		var params: Dictionary = world.walks[0]
		_check(int(params.get("random_path", 0)) == 5, "the random path is five units long")
		_check(int(params.get("random_z", 0)) == 4, "the random walk wanders up to four")


func _test_feeding() -> void:
	var world := FakeWorld.new()
	world.position = Vector3(20, 0, 20)
	world.food = [{"ref": "item7", "position": Vector3(20.5, 0, 20)}]
	var actor := _make_actor(world)
	var guard := 0
	while _event_count(actor, "taken") == 0 and guard < 4000:
		world.time += 0.1
		actor.call("tick", 0.1)
		guard += 1
	_check(_event_count(actor, "taken") == 1, "the hamster picks up the food")
	_check(world.deleted.has("item7"), "the food object is removed")
	var history := _history(actor)
	var eating := 0
	for command: String in history:
		if command == "play_anim goteaten":
			eating += 1
	_check(eating == 5, "the eating animation plays five times")
	_check(history.has("take_item item7"), "the food is taken at the end of the round")


func _test_farm() -> void:
	var world := FakeWorld.new()
	world.random_value = 4
	world.farm = {"ref": "farm1", "position": Vector3(10, 0, 20)}
	var actor := _make_actor(world)
	actor.call("set_farmhamster", world.farm)
	_check(bool(actor.call("is_farmed")), "the hamster belongs to the farm")
	world.dwarves = [Vector3(0, 0, 0)]
	_tick(actor, world, 0.5)
	_check(not _has_event(actor, "escape"), "a farmed hamster does not flee")
	_check(world.walks.size() >= 1, "the farmed hamster hops inside the pen")
	if world.walks.size() >= 1:
		var params: Dictionary = world.walks[0]
		_check(String(params.get("animsets", "")) == "1", "the farm hop uses the hop animset")
		var target: Vector3 = params.get("target", Vector3.ZERO)
		_check(target.x >= 8.5 and target.x <= 11.5, "the hop stays inside the pen width")
		_check(target.z >= 18.0 and target.z <= 22.0, "the hop stays inside the pen depth")
		_check(int(params.get("can_climb", -1)) == 0, "the hamster cannot climb")


func _test_paralysis() -> void:
	var world := FakeWorld.new()
	world.position = Vector3(20, 0, 20)
	world.contained = true
	var actor := _make_actor(world)
	# the scan timer drops to five seconds when no dwarf is in sight
	_tick(actor, world, 6.0)
	_check(bool(actor.call("is_paralyzed")), "a contained hamster is paralysed")
	_check(String(actor.call("get_current_clip")) == "getroffen",
		"the hit animation is the original clip")
	_check(int(actor.call("get_queue_size")) == 0, "the queue is cleared on paralysis")
	_check(not _has_event(actor, "wakeup"), "the hamster does not wake up early")
	world.contained = false
	_tick(actor, world, 1800.0, 1.0)
	_check(_has_event(actor, "wakeup"), "the hamster wakes up after thirty minutes")
	_check(not bool(actor.call("is_paralyzed")), "the paralysis ends")
	_check(String(actor.call("get_state_name")) != "", "the actor has a state after the wake up")


# --- scene binding -------------------------------------------------------------

func _test_scene_binding() -> void:
	# a hamster node that finds the dwarf in the scene and reacts to it
	var dwarf := Node3D.new()
	dwarf.name = "TestDwarf"
	dwarf.position = Vector3(23, 0, 20)
	dwarf.add_to_group("dwarf")
	root.add_child(dwarf)

	var hamster: Node3D = Actor3D.new()
	hamster.name = "TestHamster"
	hamster.position = Vector3(20, 0, 20)
	root.add_child(hamster)
	hamster.call("setup", {})

	var scene_actor: RefCounted = hamster.get("actor")
	_check(scene_actor != null, "the scene node owns an actor")
	# The hamster turns with the turn clip of the original before it walks, so
	# the walk needs more than the turn of a single second.
	for _step: int in range(40):
		hamster.call("_process", 0.1)
	var history: Array[String] = scene_actor.call("get_history")
	_check(history.has("walk_pos {18.0 0.0 20.0}"),
		"the scene hamster flees the dwarf it finds in the scene")
	# the walk must actually move the node: a fallback that returns the own
	# position as the walk target would freeze the hamster in place
	_check((hamster as Node3D).position.distance_to(Vector3(20, 0, 20)) > 0.5,
		"the scene hamster leaves its place while it walks")
	_check(String(scene_actor.call("get_action_kind")) != "walk" or
		(hamster as Node3D).position.distance_to(Vector3(20, 0, 20)) > 0.5,
		"the walk action makes progress")

	# a hamster alone in the scene plays the original clips and shows the mesh
	var lonely: Node3D = Actor3D.new()
	lonely.name = "TestLonelyHamster"
	lonely.position = Vector3(-8, 0, 20)
	root.add_child(lonely)
	lonely.call("setup", {})
	# The activity of a hamster is drawn at random, so the clips are collected
	# over the ticks instead of reading the one of the last tick. The standby
	# picture of the original is the fallback while nothing is played, so the
	# activity clip is the one that proves the hamster acts.
	var activity_clip := ""
	for _step: int in range(60):
		lonely.call("_process", 0.1)
		var shown := String(lonely.call("get_current_clip"))
		if activity_clip == "" and shown != "" and shown != "stand_anim":
			activity_clip = shown
		var bound: Array = lonely.get("_body_instances")
		if activity_clip != "" and bound.size() >= 1:
			break
	# The clip the node shows, not the one of the actor: while the hamster walks
	# the walk clip of the animset is shown, the actor itself has no clip then.
	_check(activity_clip != "", "the scene hamster plays an original clip")
	_check(Clips.frame_count(activity_clip) > 0,
		"the clip of the scene hamster comes from the original package")
	var instances: Array = lonely.get("_body_instances")
	_check(instances.size() >= 1, "the scene hamster binds a mesh for the frame")
	if instances.size() >= 1:
		var instance := instances[0] as MeshInstance3D
		_check(instance.visible, "the bound mesh is visible")
		_check(instance.mesh != null, "the bound mesh has geometry")

	root.remove_child(dwarf)
	root.remove_child(hamster)
	root.remove_child(lonely)
