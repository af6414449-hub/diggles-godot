extends SceneTree
## --headless --path godot --script res://tools/native_raupe_ai_self_test.gd
## Checks the ported Raupe rules on a fake adapter, without a scene:
##   - the thirteen variants and the four types that eat plants
##   - the visibility gate and the three second wait of a failed place search
##   - the one second farm classification, the release and the four second wait
##   - the eleventh plant search, the approach, the windup and the death
##   - the vanishing plant, the invalid farm, the inventory and the farm lock
##   - the seeded replay of the transitions and the chosen places
##   - the rules of the farm: the limit of six, the counter, the fodder, the
##     cooldown and the rectangle of a new Raupe
##
## Sources (original install, data/Scripts/classes/characters/raupe.tcl and
## data/Scripts/classes/work/farm.tcl).
const Raupe = preload("res://scripts/native_raupe_ai.gd")
const Actor = preload("res://scripts/native_raupe_actor.gd")
const Farm = preload("res://scripts/native_farm_raupe.gd")

var _checks: int = 0
var _failures: Array[String] = []


## The world of the fake adapter.
class FakeWorld extends RefCounted:
	var position: Vector3 = Vector3.ZERO
	var max_fow: float = 20.0
	var contained: bool = false
	var owner_id: String = "dwarf1"
	var farm: Dictionary = {}
	var farm_valid: bool = true
	var farm_buildup: bool = true
	var dwarf: Dictionary = {}
	var plant: Dictionary = {}
	var plant_valid: bool = true
	var place_code: int = 1
	var place_position: Vector3 = Vector3.ZERO
	var moves: Array[Dictionary] = []
	var waits: Array[Dictionary] = []
	var clips: Array[Dictionary] = []
	var damages: Array[Dictionary] = []
	var particles: Array[Dictionary] = []
	var place_requests: Array[Dictionary] = []
	var destroyed_count: int = 0
	var locks: Dictionary = {}


func _initialize() -> void:
	call_deferred("_run")


func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures.append(message)
		printerr("FAIL: " + message)


## The adapter of the actor, backed by the fake world.
func _adapters(world: FakeWorld) -> Dictionary:
	return {
		"actor_pos": func() -> Vector3: return world.position,
		"max_fow": func() -> float: return world.max_fow,
		"is_contained": func() -> bool: return world.contained,
		"owner_id": func() -> String: return world.owner_id,
		"query_farm": func(_request: Dictionary) -> Dictionary: return world.farm,
		"farm_state": func(_reference: String) -> Dictionary:
			return {"valid": world.farm_valid, "buildup": world.farm_buildup},
		"query_dwarf": func(_request: Dictionary) -> Dictionary: return world.dwarf,
		"query_plant": func(_request: Dictionary) -> Dictionary: return world.plant,
		"plant_state": func(_reference: String) -> Dictionary:
			return {"valid": world.plant_valid, "position": world.plant.get("position", Vector3.ZERO)},
		"pick_place": func(request: Dictionary) -> Dictionary:
			world.place_requests.append(request)
			return {"code": world.place_code, "position": world.place_position},
		"damage_plant": func(reference: String, amount: float) -> void:
			world.damages.append({"ref": reference, "amount": amount}),
		"emit_particles": func(request: Dictionary) -> void: world.particles.append(request),
		"destroy_actor": func() -> void: world.destroyed_count += 1,
		"move_action": func(params: Dictionary) -> bool:
			world.moves.append(params)
			return true,
		"move_complete": func() -> bool: return true,
		"play_clip": func(request: Dictionary) -> bool:
			world.clips.append(request)
			return true,
	}


func _make_actor(world: FakeWorld, seed_value: int = 1) -> RefCounted:
	var actor: RefCounted = Actor.new()
	actor.call("setup", _adapters(world), seed_value)
	return actor


## The waits of the trace of an actor.
func _waits(actor: RefCounted) -> Array[float]:
	var result: Array[float] = []
	for entry: Variant in actor.call("get_trace"):
		var text := String(entry)
		if text.begins_with("wait:"):
			result.append(float(text.substr(5)))
	return result


## The states of the trace of an actor.
func _states(actor: RefCounted) -> Array[String]:
	var result: Array[String] = []
	for entry: Variant in actor.call("get_trace"):
		var text := String(entry)
		if text.begins_with("state:"):
			result.append(text.substr(6))
	return result


func _run() -> void:
	# --- the thirteen variants (raupe.tcl:31-32, :48-52) ---------------------
	_check(Raupe.variant_tag(1) == "01", "a one digit variant gets a leading zero")
	_check(Raupe.variant_tag(13) == "13", "a two digit variant stays as it is")
	var seen: Array[String] = []
	for seed_value: int in range(1, 121):
		var world := FakeWorld.new()
		var actor := _make_actor(world, seed_value)
		var tag := String(actor.call("get_variant_tag"))
		if not seen.has(tag):
			seen.append(tag)
	_check(seen.size() == 13, "every one of the thirteen variants is drawn")
	var predatory: Array[int] = []
	for variant: int in range(1, 14):
		if Raupe.is_predatory(variant):
			predatory.append(variant)
	_check(predatory.size() == 4, "four of the thirteen variants eat plants")
	for variant: int in [2, 6, 7, 8]:
		_check(Raupe.is_predatory(variant), "type %02d eats plants" % variant)
		_check(int(Raupe.attack_type(variant)) == 1, "type %02d has the attack type one" % variant)
	for variant: int in [1, 3, 4, 5, 9, 10, 11, 12, 13]:
		_check(not Raupe.is_predatory(variant), "type %02d does not eat plants" % variant)
		_check(int(Raupe.attack_type(variant)) == 0, "type %02d has the attack type zero" % variant)

	# --- the nine peaceful types never attack (raupe.tcl:48-52, :119) -------
	for variant: int in [1, 3, 4, 5, 9, 10, 11, 12, 13]:
		var peaceful := FakeWorld.new()
		peaceful.plant = {"ref": "plant1", "position": Vector3(0.0, 0.0, 3.0)}
		peaceful.place_position = Vector3(0.0, 0.0, 3.0)
		var peaceful_actor := _make_actor(peaceful, 7)
		peaceful_actor.call("set_variant", variant)
		for _index: int in range(20):
			peaceful_actor.call("tick", 1.0)
		_check(String(peaceful_actor.call("get_state")) == "free",
			"type %02d never enters the plant attack" % variant)
		_check(peaceful.damages.is_empty(), "type %02d never damages a plant" % variant)

	# --- the visibility gate (raupe.tcl:68) ----------------------------------
	var dark := FakeWorld.new()
	dark.max_fow = 9.9
	var dark_actor := _make_actor(dark, 7)
	dark_actor.call("tick", 1.0)
	_check(dark.place_requests.is_empty(), "a Raupe below the visibility of ten asks for no place")
	_check(dark.moves.is_empty(), "a Raupe below the visibility of ten does not move")
	_check(String(dark_actor.call("get_state")) == "free", "a blind Raupe stays free")

	# --- a failed place search (raupe.tcl:77-80) ------------------------------
	var blocked := FakeWorld.new()
	blocked.place_code = -1
	var blocked_actor := _make_actor(blocked, 7)
	blocked_actor.call("tick", 1.0)
	_check(blocked.moves.is_empty(), "a failed place search does not move")
	var blocked_waits := _waits(blocked_actor)
	_check(blocked_waits.size() == 1, "a failed place search waits once")
	_check(absf(blocked_waits[0] - 3.0) < 0.0001, "a failed place search waits three seconds")
	_check(String(blocked_actor.call("get_anim_mode")) == "wait", "a waiting Raupe uses the still animation")

	# --- the free roaming (raupe.tcl:70-84) ----------------------------------
	var roam := FakeWorld.new()
	roam.place_position = Vector3(0.0, 0.0, 3.0)
	var roam_actor := _make_actor(roam, 7)
	roam_actor.call("tick", 1.0)
	_check(roam.moves.size() == 1, "a free Raupe moves")
	_check(roam.place_requests.size() == 1, "a free Raupe asks for a place")
	var request := roam.place_requests[0]
	_check(int(request["circle"]) == 3, "the roaming place search uses a radius of three")
	_check(int(request["random"]) == 2, "the roaming place search randomises by two")
	var candidate := request["center"] as Vector3
	_check(candidate.length() >= 2.0 and candidate.length() <= 4.0, "the roaming candidate is two to four units away")
	_check((request["nearpos"] as Vector3) == Vector3.ZERO, "the roaming place search starts at the own position")
	_check(absf(float(roam.moves[0]["speed"]) - 0.03) < 0.0001, "the move runs with speed 0.03")
	_check(String(roam_actor.call("get_anim_mode")) == "crawl", "a moving Raupe uses the crawl animation")

	# --- the farm classification on the timer (raupe.tcl:166-178) -----------
	var farm_world := FakeWorld.new()
	farm_world.farm = {"ref": "farm1", "position": Vector3.ZERO}
	var farm_actor := _make_actor(farm_world, 7)
	farm_actor.call("tick", 0.5)
	_check(String(farm_actor.call("get_state")) == "free", "half a second does not classify the Raupe")
	farm_actor.call("tick", 0.5)
	_check(String(farm_actor.call("get_state")) == "farmed", "the farm classifies the Raupe after one second")
	_check(String(farm_actor.call("get_farm_id")) == "farm1", "the Raupe knows its farm")
	_check(farm_world.moves.size() >= 1, "a farmed Raupe roams inside the farm")
	var farm_request := farm_world.place_requests[farm_world.place_requests.size() - 1]
	_check(farm_request.has("rect"), "the farmed place search is limited to the farm rectangle")
	var rectangle: Array = farm_request["rect"]
	_check(absf(float(rectangle[0]) + 2.0) < 0.0001, "the farm rectangle starts two units before the farm")
	_check(absf(float(rectangle[1]) + 3.0) < 0.0001, "the farm rectangle starts three units before the farm")
	_check(absf(float(rectangle[2]) - 1.5) < 0.0001, "the farm rectangle ends one and a half units after the farm")
	_check(absf(float(rectangle[3]) - 3.0) < 0.0001, "the farm rectangle ends three units after the farm")

	# --- a farm without buildup (raupe.tcl:225) -----------------------------
	farm_world.farm_buildup = false
	farm_actor.call("tick", 1.0)
	_check(String(farm_actor.call("get_state")) == "free", "a farm without buildup sends the Raupe back to free")

	# --- the inventory (raupe.tcl:207-216, :238-251) -------------------------
	var stored := FakeWorld.new()
	stored.contained = true
	var stored_actor := _make_actor(stored, 7)
	stored_actor.call("tick", 0.1)
	_check(String(stored_actor.call("get_state")) == "contained", "a stored Raupe is contained")
	stored_actor.call("tick", 0.1)
	var stored_waits := _waits(stored_actor)
	_check(stored_waits.size() >= 1, "a stored Raupe waits")
	_check(absf(stored_waits[0] - 4.0) < 0.0001, "a stored Raupe waits four seconds")
	# The wait of the inventory runs in four second steps.
	for _index: int in range(40):
		stored_actor.call("tick", 0.25)
	var contained_waits := _waits(stored_actor)
	var four_second_waits: int = 0
	for seconds: float in contained_waits:
		if absf(seconds - 4.0) < 0.0001:
			four_second_waits += 1
	_check(four_second_waits == 3, "the inventory waits in four second steps")
	# The release follows the one second timer.
	stored.contained = false
	stored_actor.call("tick", 1.0)
	_check(String(stored_actor.call("get_state")) == "free", "a released Raupe becomes free")

	# --- the plant search on the eleventh tick (raupe.tcl:120-124) -----------
	var hunt := FakeWorld.new()
	hunt.plant = {"ref": "plant1", "position": Vector3(0.0, 0.0, 3.0)}
	hunt.place_position = Vector3(0.0, 0.0, 3.0)
	var hunt_actor := _make_actor(hunt, 7)
	hunt_actor.call("set_variant", 6)
	for _index: int in range(10):
		hunt_actor.call("tick", 1.0)
	_check(String(hunt_actor.call("get_state")) == "free", "the plant search waits for the eleventh tick")
	_check(hunt.place_requests.size() == 10, "the first ten ticks do not search a plant")
	hunt_actor.call("tick", 1.0)
	_check(String(hunt_actor.call("get_state")) == "plant_attack", "the eleventh tick starts the plant attack")
	_check(String(hunt_actor.call("get_attack_plant")) == "plant1", "the attack keeps the plant")

	# --- the approach to 0.55 (raupe.tcl:307-317) ---------------------------
	_check(int(hunt_actor.call("get_approached")) == 0, "the attack starts with the approach")
	var approach_moves := hunt.moves.size()
	hunt_actor.call("tick", 0.1)
	_check(hunt.moves.size() == approach_moves + 1, "the approach moves towards the plant")
	var approach_target := hunt.moves[hunt.moves.size() - 1]["target"] as Vector3
	var plant_position := Vector3(0.0, 0.0, 3.0)
	_check(absf(approach_target.distance_to(plant_position) - 0.55) < 0.0001,
		"the approach point is 0.55 away from the plant")
	hunt.position = plant_position + Vector3(0.0, 0.0, -0.55)
	hunt_actor.call("tick", 0.1)
	_check(int(hunt_actor.call("get_approached")) == 1, "the approach ends at 0.55")

	# --- the windup and the bite (raupe.tcl:278-306) -------------------------
	hunt_actor.call("tick", 0.1)
	_check(int(hunt_actor.call("get_approached")) == 2, "the windup starts the second phase")
	_check(hunt.damages.is_empty(), "the windup does not damage the plant")
	_check(absf(float(hunt_actor.call("get_hitpoints")) - 0.02) < 0.0001, "the windup costs no hit points")
	hunt_actor.call("tick", 1.0)
	_check(hunt.damages.is_empty(), "the windup still does not damage the plant")
	hunt_actor.call("tick", 1.0)
	_check(hunt.damages.size() == 1, "the bite damages the plant once")
	_check(absf(float(hunt.damages[0]["amount"]) - 0.03) < 0.0001, "the plant loses 0.03")
	hunt_actor.call("tick", 0.3)
	_check(hunt.particles.size() == 1, "the bite emits the particles of the original")
	_check(int(hunt.particles[0]["source"]) == 15, "the particles use the source of the original")
	_check(absf(float(hunt_actor.call("get_hitpoints")) + 0.03) < 0.0001, "the bite costs the Raupe 0.05 hit points")
	hunt_actor.call("tick", 1.2)
	_check(int(hunt_actor.call("get_hitpoints")) < 0.01, "the Raupe is below the death threshold")
	hunt_actor.call("tick", 1.2)
	_check(hunt.destroyed_count == 1, "the Raupe dies below 0.01 hit points")
	_check(hunt.destroyed_count == 1, "the Raupe dies only once")

	# --- a plant that vanishes (raupe.tcl:267-273) --------------------------
	var lost := FakeWorld.new()
	lost.plant = {"ref": "plant1", "position": Vector3(0.0, 0.0, 3.0)}
	lost.place_position = Vector3(0.0, 0.0, 3.0)
	var lost_actor := _make_actor(lost, 7)
	lost_actor.call("set_variant", 6)
	for _index: int in range(11):
		lost_actor.call("tick", 1.0)
	_check(String(lost_actor.call("get_state")) == "plant_attack", "the attack starts")
	lost.plant_valid = false
	lost_actor.call("tick", 0.1)
	_check(String(lost_actor.call("get_state")) == "free", "a vanished plant sends the Raupe back to free")
	_check(String(lost_actor.call("get_attack_plant")) == "", "a vanished plant leaves no target")
	_check(int(lost_actor.call("get_approached")) == 0, "a vanished plant clears the approach")

	# --- the inventory during an attack (raupe.tcl:259-266) -----------------
	var caught := FakeWorld.new()
	caught.plant = {"ref": "plant1", "position": Vector3(0.0, 0.0, 3.0)}
	caught.place_position = Vector3(0.0, 0.0, 3.0)
	var caught_actor := _make_actor(caught, 7)
	caught_actor.call("set_variant", 6)
	for _index: int in range(11):
		caught_actor.call("tick", 1.0)
	_check(String(caught_actor.call("get_state")) == "plant_attack", "the attack starts")
	caught.contained = true
	caught_actor.call("tick", 0.1)
	_check(String(caught_actor.call("get_state")) == "contained", "a stored Raupe leaves the attack")
	_check(String(caught_actor.call("get_attack_plant")) == "", "the inventory clears the target")
	_check(int(caught_actor.call("get_approached")) == 0, "the inventory clears the approach")

	# --- a plant without a place keeps the old target (raupe.tcl:130-137) --
	var no_place := FakeWorld.new()
	no_place.plant = {"ref": "plant1", "position": Vector3(0.0, 0.0, 8.0)}
	no_place.place_code = 0
	var no_place_actor := _make_actor(no_place, 7)
	no_place_actor.call("set_variant", 6)
	for _index: int in range(11):
		no_place_actor.call("tick", 1.0)
	_check(String(no_place_actor.call("get_state")) == "free", "a plant without a place does not start the attack")
	_check(String(no_place_actor.call("get_attack_plant")) == "", "a plant without a place leaves no target")

	# --- the seeded replay (raupe.tcl:31, :60) -------------------------------
	var first_world := FakeWorld.new()
	var second_world := FakeWorld.new()
	var first_actor := _make_actor(first_world, 4242)
	var second_actor := _make_actor(second_world, 4242)
	_check(int(first_actor.call("get_variant")) == int(second_actor.call("get_variant")), "the same seed gives the same type")
	for _index: int in range(12):
		first_actor.call("tick", 1.0)
		second_actor.call("tick", 1.0)
	_check(str(first_actor.call("get_trace")) == str(second_actor.call("get_trace")),
		"the same seed gives the same transitions")
	_check(str(first_world.moves) == str(second_world.moves), "the same seed gives the same chosen places")
	_check(str(first_world.place_requests) == str(second_world.place_requests),
		"the same seed gives the same place requests")

	# --- the snapshot of the actor (multiplayer state) ----------------------
	var snapshot_world := FakeWorld.new()
	var snapshot_actor := _make_actor(snapshot_world, 99)
	for _index: int in range(3):
		snapshot_actor.call("tick", 1.0)
	var snapshot: Dictionary = snapshot_actor.call("get_state_snapshot")
	_check(snapshot.has("variant_id"), "the snapshot carries the type tag")
	_check(snapshot.has("contained"), "the snapshot carries the inventory state")
	_check(snapshot.has("next_decision_time"), "the snapshot carries the time of the next decision")
	_check(snapshot.has("rng"), "the snapshot carries the random generator")
	var restored_world := FakeWorld.new()
	var restored := _make_actor(restored_world, 1)
	restored.call("restore_from_snapshot", snapshot)
	_check(int(restored.call("get_variant")) == int(snapshot_actor.call("get_variant")), "the restored Raupe keeps the type")
	_check(String(restored.call("get_state")) == String(snapshot_actor.call("get_state")), "the restored Raupe keeps the state")
	_check(absf(float(restored.call("get_hitpoints")) - float(snapshot_actor.call("get_hitpoints"))) < 0.0001,
		"the restored Raupe keeps its hit points")

	# --- the rules of the farm (farm.tcl:243-270, :470-513) -----------------
	_check(Farm.MAX_WORMS == 6, "a farm holds at most six Raupen")
	_check(absf(Farm.threshold(2, 0.0) - 36.0) < 0.0001, "the threshold of the farm is 60 - material*12")
	_check(absf(Farm.threshold(2, 1.0) - 41.0) < 0.0001, "the threshold of the farm adds rand()*5")
	_check(absf(Farm.threshold(0, 0.5) - 62.5) < 0.0001, "the threshold of the farm uses the material of the ground")
	_check(absf(Farm.WORM_FODDER_COST - 30.0) < 0.0001, "a new Raupe costs thirty fodder")
	_check(absf(Farm.CREATION_COOLDOWN - 50.0) < 0.0001, "the creation cooldown is fifty seconds")
	var farm_rules := Farm.new()
	_check(not farm_rules.can_recreate(49.0), "the cooldown blocks a creation after 49 seconds")
	_check(farm_rules.can_recreate(50.0), "the cooldown allows a creation after 50 seconds")
	var recreate_request := farm_rules.recreate_request(Vector3.ZERO)
	var recreate_rect: Array = recreate_request["rect"]
	_check(absf(float(recreate_rect[0]) + 1.7) < 0.0001, "the new Raupe is placed at least 1.7 from the farm in x")
	_check(absf(float(recreate_rect[1]) + 2.5) < 0.0001, "the new Raupe is placed at least 2.5 from the farm in z")
	_check(absf(float(recreate_rect[2]) - 1.7) < 0.0001, "the new Raupe is placed at most 1.7 from the farm in x")
	_check(absf(float(recreate_rect[3]) - 2.5) < 0.0001, "the new Raupe is placed at most 2.5 from the farm in z")
	var candidate_request := Farm.candidate_request(Vector3.ZERO)
	var candidate_box: Vector3 = candidate_request["box"]
	_check(candidate_box == Vector3(2.0, 0.5, 3.0), "the candidates of a farm are two by three")
	# The farm keeps the lock on its first Raupe (actualize_worm).
	var locked := farm_rules.actualize_worm([{"ref": "w1", "locked": true}, {"ref": "w2", "locked": false}], "")
	_check(String(locked) == "w2", "the farm locks the first free Raupe of its box")
	locked = farm_rules.actualize_worm([{"ref": "w1", "locked": true}, {"ref": "w2", "locked": false}], "w1")
	_check(String(locked) == "w1", "the farm keeps the lock on its first Raupe")
	_check(String(farm_rules.original_worm) == "w1", "the farm remembers its first Raupe")
	farm_rules.free_original_worm()
	_check(String(farm_rules.original_worm) == "", "the release of the farm clears the lock")
	# The production rules of the farm.
	var plan := farm_rules.production_plan(6, 100, 2, 0.0, true)
	_check(not bool(plan["recreate"]), "a farm with six Raupen creates no new one")
	_check(String(plan["reason"]) == "full", "the reason is the limit of six")
	plan = farm_rules.production_plan(1, 100, 2, 0.0, true)
	_check(bool(plan["recreate"]), "a farm above the threshold creates a new Raupe")
	_check(absf(float(plan["fodder"]) - 30.0) < 0.0001, "the creation costs thirty fodder")
	plan = farm_rules.production_plan(1, 100, 2, 0.0, false)
	_check(not bool(plan["recreate"]), "without a gnome the farm creates no new Raupe")
	plan = farm_rules.production_plan(1, 10, 2, 0.0, true)
	_check(not bool(plan["recreate"]), "below the threshold the farm only counts up")
	var applied := farm_rules.apply_creation(plan, true)
	_check(absf(float(applied["fodder"])) < 0.0001, "a creation that does not happen costs no fodder")

	if _failures.is_empty():
		print("NATIVE_RAUPE_AI_SELF_TEST_OK assertions=%d" % _checks)
	else:
		printerr("NATIVE_RAUPE_AI_SELF_TEST_FAIL failures=%d" % _failures.size())
	quit(0 if _failures.is_empty() else 1)
