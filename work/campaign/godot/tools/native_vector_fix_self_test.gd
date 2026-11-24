extends SceneTree
const FIX: Script = preload("res://scripts/native_vector_fix.gd")
const DIG_POSE: Script = preload("res://scripts/native_dig_pose.gd")
const WALK_POSE: Script = preload("res://scripts/native_walk_pose.gd")
var assertions: int = 0
var failures: int = 0

func _initialize() -> void:
	var bounds: Rect2i = Rect2i(0, 0, 600, 600)
	var flags: Dictionary = {Vector2i(800, 800): 1}
	var query: Callable = func(p: Vector2i) -> Variant: return flags.get(p, 0)
	var heights: Dictionary = {Vector2i(801, 799): 4, Vector2i(800, 799): 3}
	var height_query: Callable = func(p: Vector2i) -> Variant: return heights.get(p)
	var result: Dictionary = FIX.solve(Vector3(100.0625, 100.0625, 99), bounds, query, height_query, &"nearest_even")
	_expect(result["point"] == Vector3(100, 100, 99) and result["found_navigation"], "initial sample must round XY and preserve Z without a height query")
	flags.clear()
	flags.merge({Vector2i(801, 800): 1, Vector2i(800, 801): 1})
	result = FIX.solve(Vector3(100, 100, 1), bounds, query, height_query, &"nearest_even")
	_expect(result["point"] == Vector3(100.125, 100, 5), "spiral tie must preserve +X and read H at Y-1")
	result = FIX.solve(Vector3(100, 100, 99), bounds, query, height_query, &"nearest_even")
	_expect(result["point"].z == 14.5, "searched branch must cap input depth")
	flags.clear()
	result = FIX.solve(Vector3(100, 100, 1), bounds, query, height_query, &"nearest_even")
	_expect(not result["found_navigation"] and result["point"] == Vector3(100, 100, 4), "native no-navigation fallback differs")
	result = FIX.solve(Vector3(3, 3, 99), bounds, query, height_query, &"nearest_even")
	_expect(result["point"] == Vector3(3, 3, 99) and result["reason"] == "outside_interior", "48-sample margin must preserve input")
	result = FIX.solve(Vector3(1, 1, 3), Rect2i(-10, -10, 600, 600), query, height_query, &"nearest_even")
	_expect(result["point"] == Vector3.ZERO, "native low-sample fallback differs")
	result = FIX.solve(Vector3(100, 100, 1), bounds, query, height_query)
	_expect(result["status"] == "unknown", "unspecified FPU mode was guessed")
	flags[Vector2i(801, 800)] = null
	result = FIX.solve(Vector3(100, 100, 1), bounds, query, height_query, &"nearest_even")
	_expect(result["status"] == "unknown" and result["missing"] == "walk_flags", "missing navigation became known empty")
	for fixture: Array in [[Vector3(0,-2,3),0], [Vector3(2,0,0),1], [Vector3(0,2,0),2],
			[Vector3(-2,0,0),3], [Vector3(2,-1,4),1], [Vector3(-1,-2,3),0], [Vector3.ZERO,1]]:
		_expect(DIG_POSE.direction(Vector3.ZERO, fixture[0]) == fixture[1], "source cardinal angle differs: %s" % [fixture])
	var contact_flags: Dictionary = {Vector2i(800,801): 2}
	var contact_query: Callable = func(p: Vector2i) -> Variant: return contact_flags.get(p,0)
	_expect(WALK_POSE.ground_contact(Vector2i(800,800), Rect2i(0,0,4800,4800), contact_query) == true, "floor contact at Y+1 missed")
	contact_flags.clear()
	_expect(WALK_POSE.ground_contact(Vector2i(800,800), Rect2i(0,0,4800,4800), contact_query) == false, "wall classified as floor")
	contact_flags[Vector2i(800,799)] = null
	_expect(WALK_POSE.ground_contact(Vector2i(800,800), Rect2i(0,0,4800,4800), contact_query) == null, "unknown contact was guessed")
	contact_flags[Vector2i(800,800)] = 2
	_expect(WALK_POSE.ground_contact(Vector2i(800,800), Rect2i(0,0,4800,4800), contact_query) == true, "known floor contact lost to unrelated unknown")
	if failures == 0:
		print("NATIVE_VECTOR_FIX_SELF_TEST_OK assertions=%d" % assertions)
	quit(0 if failures == 0 else 1)

func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("NATIVE_VECTOR_FIX_SELF_TEST_FAILED " + message)
