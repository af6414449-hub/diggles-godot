extends SceneTree
## --headless --path godot --script res://tools/native_wild_hamster_self_test.gd
## Checks the wild hamster of the multiplayer scene: the walk animsets, the
## heading convention of the project, the gnome sensor, the walk itself, the
## turn of the original and the ground the hamster walks on.
const Hamster = preload("res://scripts/native_wild_hamster.gd")
const Clips = preload("res://scripts/native_hamster_clips.gd")
const Animations = preload("res://scripts/native_hamster_animations.gd")
const Ground = preload("res://scripts/native_level_ground.gd")
var _checks: int = 0
var _failures: Array[String] = []

func _initialize() -> void:
	call_deferred("_run")

func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures.append(message)
		printerr("FAIL: " + message)

## A host that stands in for the multiplayer scene.
func _make_host(dwarves: Array, headings: Array, free_spot: Variant) -> Dictionary:
	return {
		"dwarf_positions": func() -> Array: return dwarves,
		"food_entries": func() -> Array: return [],
		"walk_path": func(_from: Vector3, to: Vector3) -> Array: return [to],
		"free_spot": func(center: Vector3, _radius: float, _mindist: float, _clip: Array) -> Variant:
			return free_spot if free_spot != null else center,
		"apply_heading": func(_node: Node3D, heading: float) -> void: headings.append(heading),
		"depth_scale": func() -> float: return 1.0,
	}

## One tick of the walk.
##
## The actor of the class calls the walk adapter of the node while the walk
## action runs, so the test does the same.
func _tick(hamster: Node3D, steps: int = 1) -> void:
	for index: int in range(steps):
		hamster.call("_process", 0.1)
		hamster.call("_walk_complete")


## Stop the actor from choosing its own activities.
##
## The wild activity table of the class starts a random walk, which would take
## the walk away from the tests that drive it themselves.
func _quiet(hamster: Node3D) -> void:
	var actor: RefCounted = hamster.get("actor")
	if actor != null:
		actor.call("paralyze")

func _run() -> void:
	# --- the walk animsets of the class (hamster.tcl:42-81) -----------------
	_check(Hamster.walk_clip_for("0", "start") == "laufen_start", "the walk set starts with laufen_start")
	_check(Hamster.walk_clip_for("0", "loop") == "laufen_loop", "the walk set loops with laufen_loop")
	_check(Hamster.walk_clip_for("0", "end") == "laufen_end", "the walk set ends with laufen_end")
	_check(Hamster.walk_clip_for("1", "start") == "hoppeln_start", "the hop set starts with hoppeln_start")
	_check(Hamster.walk_clip_for("1", "loop") == "hoppeln_loop", "the hop set loops with hoppeln_loop")
	_check(Hamster.walk_clip_for("1", "end") == "hoppeln_end", "the hop set ends with hoppeln_end")
	_check(Hamster.walk_clip_for("2", "loop") == "galopp_loop", "the gallop set loops with galopp_loop")
	_check(Clips.frame_count("laufen_loop") == 7, "laufen_loop has 7 frames")
	_check(Clips.frame_count("hoppeln_loop") == 7, "hoppeln_loop has 7 frames")
	_check(Clips.frame_count("laufen_start") == 4, "laufen_start has 4 frames")
	_check(Animations.get_clip("Hamster", "standstill") == "stand_anim", "the standby animation is stand_anim")

	# --- the turn clips of the class (hamster.tcl:6-9 and :48-51) ----------
	_check(Animations.get_animset_clip("Hamster", "0", "turn_left_90") == "drehen_links_90",
		"the walk set turns left with drehen_links_90")
	_check(Animations.get_animset_clip("Hamster", "0", "turn_right_90") == "drehen_rechts_90",
		"the walk set turns right with drehen_rechts_90")
	_check(Animations.get_animset_clip("Hamster", "0", "turn_left_180") == "drehen_links_90",
		"the hundred eighty degree turn uses the same clip")
	_check(Animations.get_animset_clip("Hamster", "0", "turn_right_180") == "drehen_rechts_90",
		"the hundred eighty degree turn uses the same clip")
	_check(Animations.get_clip("Hamster", "turnleft") == "drehen_links_90", "the class turns left")
	_check(Animations.get_clip("Hamster", "turnright") == "drehen_rechts_90", "the class turns right")
	_check(Clips.frame_count("drehen_links_90") == 17, "drehen_links_90 has 17 frames")
	_check(Clips.frame_count("drehen_rechts_90") == 17, "drehen_rechts_90 has 17 frames")

	# --- the heading convention of the project ------------------------------
	_check(absf(Hamster.heading_for_direction(Vector2(0.0, 1.0), 1.0)) < 0.0001, "walking to +Z keeps the heading")
	_check(absf(Hamster.heading_for_direction(Vector2(1.0, 0.0), 1.0) - PI * 0.5) < 0.0001, "walking to +X is a quarter turn")
	_check(absf(Hamster.heading_for_direction(Vector2(-1.0, 0.0), 1.0) + PI * 0.5) < 0.0001, "walking to -X is the other quarter")
	# The scene packs the depth by 0.5, so the heading of the scene is the one
	# of the dwarves: atan2(dx, dz * depth_scale).
	_check(absf(Hamster.heading_for_direction(Vector2(0.0, 1.0), 0.5)) < 0.0001, "the depth packing does not change the +Z heading")
	_check(absf(Hamster.heading_for_direction(Vector2(1.0, 1.0), 0.5) - atan2(1.0, 0.5)) < 0.0001, "the depth packing enters the heading")

	# --- the gnome sensor (z_procs.tcl:467-475) ----------------------------
	_check(absf(Hamster.nearest_dwarf_distance([Vector3(3.0, 0.0, 0.0)], Vector3.ZERO) - 3.0) < 0.0001, "the dwarf is three units away")
	_check(Hamster.nearest_dwarf_distance([], Vector3.ZERO) == INF, "without dwarves there is no distance")
	_check(Hamster.sensor_should_trigger(1.9), "a dwarf at 1.9 makes the hamster run")
	_check(Hamster.sensor_should_trigger(2.0), "the take radius of the original is two")
	_check(not Hamster.sensor_should_trigger(2.1), "a dwarf at 2.1 is too far")

	# --- the walk over the path of the host --------------------------------
	var headings: Array = []
	var hamster: Node3D = Hamster.new()
	root.add_child(hamster)
	hamster.position = Vector3.ZERO
	hamster.call("setup", _make_host([], headings, null))
	_quiet(hamster)
	hamster.call("_process", 0.1)
	_check(bool(hamster.call("_start_walk", {"target": Vector3(2.0, 0.0, 0.0), "animsets": "1"})), "the walk starts")
	var guard: int = 0
	while not bool(hamster.call("_walk_complete")) and guard < 200:
		guard += 1
		hamster.call("_process", 0.1)
	_check((hamster.position - Vector3(2.0, 0.0, 0.0)).length() < 0.2, "the hamster reaches the end of the path")
	_check((headings as Array).size() > 0, "the hamster turns while it walks")
	_check(absf(float((headings as Array)[(headings as Array).size() - 1]) - PI * 0.5) < 0.0001,
		"the hamster looks into the direction of the walk")
	_check(guard < 200, "the walk ends")

	# --- the turn of the original is a turn, not a jump ---------------------
	# The walk action turns the object before it walks and plays the turn clip
	# of the animset while it turns (hamster.tcl:48-51).
	var turn_headings: Array = []
	var turning: Node3D = Hamster.new()
	root.add_child(turning)
	turning.position = Vector3.ZERO
	turning.call("setup", _make_host([], turn_headings, null))
	_quiet(turning)
	turning.call("_process", 0.1)
	turning.call("_start_walk", {"target": Vector3(2.0, 0.0, 0.0), "animsets": "0"})
	turning.call("_walk_complete")
	turning.call("_process", 0.1)
	_check(String(turning.call("get_current_clip")) == "drehen_links_90",
		"a quarter turn shows the turn clip of the original")
	_check(absf(float(turning.call("get_heading"))) < 0.2, "the turn does not jump to the direction")
	_check((turning.position - Vector3.ZERO).length() < 0.0001, "the hamster waits for the turn")
	var turn_steps: int = 0
	while turn_steps < 60 and absf(float(turning.call("get_heading")) - PI * 0.5) > 0.0001:
		_tick(turning)
		turn_steps += 1
	_check(absf(float(turning.call("get_heading")) - PI * 0.5) < 0.0001, "the turn ends in the direction of the walk")
	_check(turn_steps > 4, "the turn takes more than one frame")

	# --- the turn is played by the hamster that turns -----------------------
	var turned_nodes: Array = []
	var first: Node3D = Hamster.new()
	var second: Node3D = Hamster.new()
	root.add_child(first)
	root.add_child(second)
	first.position = Vector3.ZERO
	second.position = Vector3(5.0, 0.0, 0.0)
	var shared_headings: Array = []
	var shared_host := {
		"dwarf_positions": func() -> Array: return [],
		"food_entries": func() -> Array: return [],
		"walk_path": func(_from: Vector3, to: Vector3) -> Array: return [to],
		"free_spot": func(center: Vector3, _radius: float, _mindist: float, _clip: Array) -> Variant: return center,
		"apply_heading": func(node: Node3D, heading: float) -> void:
			turned_nodes.append(node)
			shared_headings.append(heading),
		"depth_scale": func() -> float: return 1.0,
	}
	first.call("setup", shared_host)
	second.call("setup", shared_host)
	_quiet(first)
	_quiet(second)
	first.call("_process", 0.1)
	first.call("_start_walk", {"target": Vector3(2.0, 0.0, 0.0), "animsets": "0"})
	first.call("_walk_complete")
	_tick(first)
	_check((turned_nodes as Array).size() > 0, "the walking hamster turns")
	_check((turned_nodes as Array).all(func(node: Variant) -> bool: return node == first),
		"only the hamster that walks is turned")

	# --- the hamster stays on the ground ------------------------------------
	var ground_host := _make_host([], [], null)
	ground_host["is_walkable"] = func(point: Vector3) -> bool: return point.z >= -1.0
	var walker: Node3D = Hamster.new()
	root.add_child(walker)
	walker.position = Vector3.ZERO
	walker.call("setup", ground_host)
	_quiet(walker)
	walker.call("_process", 0.1)
	walker.call("_start_walk", {"target": Vector3(0.0, 0.0, -3.0), "animsets": "0"})
	_tick(walker, 60)
	_check(walker.position.z >= -1.0001, "the hamster does not walk into the void")
	_check(walker.position.z < 0.0, "the hamster walks while there is ground")

	# --- the random path finder needs ground -------------------------------
	var void_host := _make_host([], [], null)
	void_host["free_spot"] = func(_center: Vector3, _radius: float, _mindist: float, _clip: Array) -> Variant: return null
	void_host["is_walkable"] = func(_point: Vector3) -> bool: return false
	var lost: Node3D = Hamster.new()
	root.add_child(lost)
	lost.position = Vector3.ZERO
	lost.call("setup", void_host)
	_quiet(lost)
	lost.call("_process", 0.1)
	_check(not bool(lost.call("_start_walk", {"random_path": 4.0, "animsets": "0"})),
		"the walk does not start without ground")
	_check((lost.position - Vector3.ZERO).length() < 0.0001, "the hamster stays where it is")

	# --- the ground of the level per height level --------------------------
	var ground: RefCounted = Ground.new()
	var terrain: Dictionary = _load_terrain()
	_check(not terrain.is_empty(), "the terrain of the level is available")
	if not terrain.is_empty():
		(ground as RefCounted).call("load_terrain", terrain)
		var levels: Array = (ground as RefCounted).call("levels")
		_check(levels.has(14.5), "the level has the floor of the cave")
		_check(levels.has(18.5), "the level has the upper terrace")
		_check(bool((ground as RefCounted).call("floor_at", 14.5, Vector2(9.75, 5.96))),
			"the floor of the cave is under the hamster of the floor")
		_check(bool((ground as RefCounted).call("floor_at", 18.5, Vector2(37.0, 5.96))),
			"the terrace is under the hamster of the terrace")
		_check(not bool((ground as RefCounted).call("floor_at", 14.5, Vector2(37.0, 5.96))),
			"the terrace is not on the floor of the cave")
		_check(not bool((ground as RefCounted).call("floor_at", 18.5, Vector2(9.75, 5.96))),
			"the floor of the cave is not on the terrace")
		var bounds: Rect2 = (ground as RefCounted).call("level_bounds", 18.5)
		_check(bounds.size.x > 20.0 and bounds.size.y > 10.0, "the terrace has an area to walk on")

	# --- the wild hamster runs away from a dwarf ----------------------------
	var flee_headings: Array = []
	var flee: Node3D = Hamster.new()
	root.add_child(flee)
	flee.position = Vector3(4.0, 0.0, 4.0)
	flee.call("setup", _make_host([Vector3(5.5, 0.0, 4.0)], flee_headings, null))
	var start_distance := (flee.position - Vector3(5.5, 0.0, 4.0)).length()
	var steps: int = 0
	while steps < 120:
		flee.call("_process", 0.1)
		steps += 1
		if (flee.position - Vector3(5.5, 0.0, 4.0)).length() > start_distance + 0.5:
			break
	var end_distance := (flee.position - Vector3(5.5, 0.0, 4.0)).length()
	_check(end_distance > start_distance + 0.5, "the wild hamster runs away from the dwarf")
	_check((flee_headings as Array).size() > 0, "the fleeing hamster turns")
	_check(String(flee.call("get_current_clip")) != "", "the fleeing hamster shows an animation")

	# --- the wild activity table (hamster.tcl:409-426) ----------------------
	var actor: RefCounted = flee.get("actor")
	_check(int(actor.call("get_scanrange")) == 4, "the scan range of the hamster is four")

	if _failures.is_empty():
		print("NATIVE_WILD_HAMSTER_SELF_TEST_OK assertions=%d" % _checks)
	else:
		printerr("NATIVE_WILD_HAMSTER_SELF_TEST_FAIL failures=%d" % _failures.size())
	quit(0 if _failures.is_empty() else 1)


## The terrain source of the scene.
func _load_terrain() -> Dictionary:
	var path := "res://models/multi_start_010_terrain.json"
	if not FileAccess.file_exists(path):
		return {}
	var file := FileAccess.open(path, FileAccess.READ)
	if file == null:
		return {}
	var parsed: Variant = JSON.parse_string(file.get_as_text())
	file.close()
	if not (parsed is Dictionary):
		return {}
	return parsed
