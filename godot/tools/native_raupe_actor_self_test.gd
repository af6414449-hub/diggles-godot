extends SceneTree
## --headless --path godot --script res://tools/native_raupe_actor_self_test.gd
## Checks the autonomous Raupe actor: the state machine, the visibility gate,
## the roaming, the plant search cadence, the self sacrificing attack, the
## inventory, the farm and the seeded replay.
##
## Sources (original install, data/Scripts/classes/characters/raupe.tcl).
const Actor = preload("res://scripts/native_raupe_actor.gd")
const Raupe = preload("res://scripts/native_raupe_ai.gd")

var _checks: int = 0
var _failures: Array[String] = []


## Mutable world used by the actor adapters.
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
	var destroyed: bool = false
	var destroyed_count: int = 0


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
		"destroy_actor": func() -> void:
			world.destroyed = true
			world.destroyed_count += 1,
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


func _waits(actor: RefCounted) -> Array[float]:
	var result: Array[float] = []
	var trace: Array = actor.call("get_trace")
	for entry: Variant in trace:
		var text := String(entry)
		if text.begins_with("wait:"):
			result.append(float(text.substr(5)))
	return result


func _run() -> void:
	# --- construction (raupe.tcl:27-60) --------------------------------------
	var world := FakeWorld.new()
	var actor := _make_actor(world, 12345)
	var variant := int(actor.call("get_variant"))
	_check(variant >= 1 and variant <= 13, "the variant is one of the thirteen types")
	_check(String(actor.call("get_variant_tag")).length() == 2, "the variant tag has two digits")
	_check(absf(float(actor.call("get_hitpoints")) - 0.02) < 0.0001, "the Raupe starts with 0.02 hit points")
	_check(String(actor.call("get_state")) == "free", "a fresh Raupe is free")
	_check(String(actor.call("get_anim_mode")) == "wait", "a fresh Raupe uses the still animation")

	# --- the visibility gate (raupe.tcl:68) -----------------------------------
	var dark := FakeWorld.new()
	dark.max_fow = 5.0
	var dark_actor := _make_actor(dark, 7)
	dark_actor.call("tick", 1.0)
	_check(dark.place_requests.is_empty(), "a blind Raupe asks for no place")
	_check(dark.moves.is_empty(), "a blind Raupe does not move")
	_check(String(dark_actor.call("get_state")) == "free", "a blind Raupe stays free")

	# --- a failed place search (raupe.tcl:78-80) -----------------------------
	var blocked := FakeWorld.new()
	blocked.place_code = -1
	var blocked_actor := _make_actor(blocked, 7)
	blocked_actor.call("tick", 1.0)
	_check(blocked.moves.is_empty(), "a failed place search does not move")
	var blocked_waits := _waits(blocked_actor)
	_check(blocked_waits.size() == 1, "a failed place search waits once")
	_check(absf(blocked_waits[0] - 3.0) < 0.0001, "a failed place search waits three seconds")
	_check(String(blocked_actor.call("get_anim_mode")) == "wait", "a waiting Raupe uses the still animation")

	# --- free roaming (raupe.tcl:70-84) ---------------------------------------
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
	var last_clip: Dictionary = roam.clips[roam.clips.size() - 1]
	_check(String(last_clip["clip"]) == "raupe%s.kriechen" % String(roam_actor.call("get_variant_tag")), "the crawl clip carries the type")

	# --- the plant search cadence (raupe.tcl:120-124) -------------------------
	var hunt := FakeWorld.new()
	hunt.plant = {"ref": "plant1", "position": Vector3(0.0, 0.0, 3.0)}
	hunt.place_position = Vector3(0.0, 0.0, 3.0)
	var hunt_actor := _make_actor(hunt, 7)
	hunt_actor.call("set_variant", 6)
	for _index: int in range(10):
		hunt_actor.call("tick", 1.0)
	_check(String(hunt_actor.call("get_state")) == "free", "the plant search waits for the eleventh tick")
	for _index: int in range(1):
		hunt_actor.call("tick", 1.0)
	_check(String(hunt_actor.call("get_state")) == "plant_attack", "the eleventh tick starts the plant attack")
	_check(String(hunt_actor.call("get_attack_plant")) == "plant1", "the attack keeps the plant")

	# --- a type that does not eat plants (raupe.tcl:48-52, :119) -------------
	var peaceful := FakeWorld.new()
	peaceful.plant = {"ref": "plant1", "position": Vector3(0.0, 0.0, 3.0)}
	peaceful.place_position = Vector3(0.0, 0.0, 3.0)
	var peaceful_actor := _make_actor(peaceful, 7)
	peaceful_actor.call("set_variant", 5)
	for _index: int in range(20):
		peaceful_actor.call("tick", 1.0)
	_check(String(peaceful_actor.call("get_state")) == "free", "a type outside 02, 06, 07 and 08 never attacks")
	_check(peaceful.damages.is_empty(), "a peaceful type never damages a plant")

	# --- the approach (raupe.tcl:307-317) -------------------------------------
	var approach := FakeWorld.new()
	approach.plant = {"ref": "plant1", "position": Vector3(0.0, 0.0, 3.0)}
	approach.place_position = Vector3(0.0, 0.0, 3.0)
	var approach_actor := _make_actor(approach, 7)
	approach_actor.call("set_variant", 7)
	for _index: int in range(11):
		approach_actor.call("tick", 1.0)
	_check(String(approach_actor.call("get_state")) == "plant_attack", "the attack starts")
	_check(int(approach_actor.call("get_approached")) == 0, "the attack starts with the approach")
	approach.position = Vector3(0.0, 0.0, 2.45)
	approach_actor.call("tick", 0.1)
	_check(int(approach_actor.call("get_approached")) == 1, "the approach ends at 0.55")

	# --- the attack (raupe.tcl:278-306) --------------------------------------
	var fight := FakeWorld.new()
	fight.plant = {"ref": "plant1", "position": Vector3(0.0, 0.0, 0.55)}
	fight.place_position = Vector3(0.0, 0.0, 0.55)
	var fight_actor := _make_actor(fight, 7)
	fight_actor.call("set_variant", 8)
	for _index: int in range(11):
		fight_actor.call("tick", 1.0)
	_check(String(fight_actor.call("get_state")) == "plant_attack", "the attack starts at the plant")
	fight_actor.call("tick", 0.1)
	_check(int(fight_actor.call("get_approached")) == 1, "the attack closes to the plant")
	fight_actor.call("tick", 0.1)
	_check(int(fight_actor.call("get_approached")) == 2, "the windup starts the second phase")
	_check(fight.damages.is_empty(), "the windup does not damage yet")
	fight_actor.call("tick", 1.2)
	fight_actor.call("tick", 1.2)
	_check(fight.damages.size() == 1, "the attack damages the plant once")
	_check(absf(float(fight.damages[0]["amount"]) - 0.03) < 0.0001, "the plant loses 0.03")
	fight_actor.call("tick", 1.2)
	_check(float(fight_actor.call("get_hitpoints")) < 0.01, "the attack costs the Raupe 0.05 hit points")
	fight_actor.call("tick", 1.2)
	_check(fight.destroyed, "the Raupe dies below 0.01 hit points")
	_check(fight.destroyed_count == 1, "the Raupe dies only once")

	# --- a plant that vanishes (raupe.tcl:267-273) ---------------------------
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
	stored.contained = false
	stored_actor.call("tick", 4.1)
	_check(String(stored_actor.call("get_state")) == "free", "a released Raupe becomes free")

	# --- the farm (raupe.tcl:218-236, :87-115) -------------------------------
	var farm_world := FakeWorld.new()
	farm_world.farm = {"ref": "farm1", "position": Vector3.ZERO}
	var farm_actor := _make_actor(farm_world, 7)
	farm_actor.call("tick", 1.0)
	_check(String(farm_actor.call("get_state")) == "farmed", "a Raupe next to a farm is farmed")
	_check(farm_world.moves.size() >= 1, "a farmed Raupe roams inside the farm")
	var farm_request := farm_world.place_requests[0]
	_check(farm_request.has("rect"), "the farmed place search is limited to the farm rectangle")
	var rectangle: Array = farm_request["rect"]
	_check(absf(float(rectangle[0]) + 2.0) < 0.0001, "the farm rectangle starts two units before the farm")
	_check(absf(float(rectangle[3]) - 3.0) < 0.0001, "the farm rectangle ends three units after the farm")

	farm_world.farm_buildup = false
	farm_actor.call("tick", 1.0)
	_check(String(farm_actor.call("get_state")) == "free", "a farm without buildup sends the Raupe back to free")

	# --- the seeded replay (raupe.tcl:31, :60) --------------------------------
	var first_world := FakeWorld.new()
	var second_world := FakeWorld.new()
	var first_actor := _make_actor(first_world, 4242)
	var second_actor := _make_actor(second_world, 4242)
	_check(int(first_actor.call("get_variant")) == int(second_actor.call("get_variant")), "the same seed gives the same type")
	for _index: int in range(12):
		first_actor.call("tick", 1.0)
		second_actor.call("tick", 1.0)
	_check(str(first_actor.call("get_trace")) == str(second_actor.call("get_trace")), "the same seed gives the same trace")

	# --- the snapshot (multiplayer state) -------------------------------------
	var snapshot_world := FakeWorld.new()
	var snapshot_actor := _make_actor(snapshot_world, 99)
	for _index: int in range(3):
		snapshot_actor.call("tick", 1.0)
	var snapshot: Dictionary = snapshot_actor.call("get_state_snapshot")
	_check(int(snapshot["variant"]) == int(snapshot_actor.call("get_variant")), "the snapshot carries the type")
	_check(String(snapshot["state"]) == String(snapshot_actor.call("get_state")), "the snapshot carries the state")
	_check(snapshot.has("rng"), "the snapshot carries the random generator")
	var restored_world := FakeWorld.new()
	var restored := _make_actor(restored_world, 1)
	restored.call("restore_from_snapshot", snapshot)
	_check(int(restored.call("get_variant")) == int(snapshot_actor.call("get_variant")), "the restored Raupe keeps the type")
	_check(String(restored.call("get_state")) == String(snapshot_actor.call("get_state")), "the restored Raupe keeps the state")

	if _failures.is_empty():
		print("NATIVE_RAUPE_ACTOR_SELF_TEST_OK assertions=%d" % _checks)
	else:
		printerr("NATIVE_RAUPE_ACTOR_SELF_TEST_FAIL failures=%d" % _failures.size())
	quit(0 if _failures.is_empty() else 1)
