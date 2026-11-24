extends SceneTree
## --headless --path godot --script res://tools/native_raupe_scene_self_test.gd
## Checks the Raupe in a scene: the probe scene loads and runs, the actor
## reports its state, the multiplayer map loads without an error and it stays
## free of quiet Raupe spawns.
##
## The multiplayer scene is instantiated read only: the test does not change
## the game and it does not put a Raupe into the map.

const ProbeScene = preload("res://scenes/native_raupe_probe.tscn")
const Actor = preload("res://scripts/native_raupe_actor.gd")

var _checks: int = 0
var _failures: Array[String] = []


func _initialize() -> void:
	call_deferred("_run")


func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures.append(message)
		printerr("FAIL: " + message)


## The nodes of the tree that carry a Raupe script.
func _raupe_nodes(node: Node) -> int:
	var count: int = 0
	for child: Node in node.get_children():
		var script: Variant = child.get_script()
		if script is Script:
			var path := String((script as Script).resource_path)
			if path.to_lower().contains("raupe"):
				count += 1
		count += _raupe_nodes(child)
	return count


func _run() -> void:
	# --- the probe scene ------------------------------------------------------
	var probe: Node = ProbeScene.instantiate()
	_check(probe != null, "the probe scene loads")
	root.add_child(probe)
	for _index: int in range(10):
		await process_frame
	var actor: Variant = probe.get("actor")
	_check(actor != null, "the probe owns a Raupe")
	if actor != null:
		_check(int(probe.get("ticks")) > 0, "the probe ticks the Raupe")
		_check(String(actor.call("get_state")) == "free", "the Raupe of the scene stays free")
		_check((actor.call("get_trace") as Array).size() > 1, "the Raupe of the scene acts")
		_check(int(actor.call("get_variant")) >= 1, "the Raupe of the scene has a type")
		_check(int(actor.call("get_variant")) <= 13, "the Raupe of the scene has one of the thirteen types")
		print("RAUPE_SCENE_ACTOR state=%s variant=%s anim=%s hitpoints=%.2f" % [
			String(actor.call("get_state")),
			String(actor.call("get_variant_tag")),
			String(actor.call("get_anim_mode")),
			float(actor.call("get_hitpoints")),
		])
	probe.queue_free()

	# --- the multiplayer map --------------------------------------------------
	var multiplayer: PackedScene = load("res://scenes/multiplayer_test.tscn")
	_check(multiplayer != null and multiplayer.can_instantiate(), "the multiplayer scene loads")
	var subject: Node3D = multiplayer.instantiate()
	subject.autonomous_dwarf_work = false
	subject.extended_world = false
	root.add_child(subject)
	await process_frame
	_check(subject.get_script() != null, "the multiplayer scene keeps its controller")
	for _index: int in range(5):
		await process_frame
	_check(subject.is_inside_tree(), "the multiplayer scene stays alive in the headless run")
	_check(_raupe_nodes(subject) == 0, "the multiplayer scene holds no Raupe actor")
	subject.queue_free()
	await process_frame

	# --- no quiet Raupe spawn -------------------------------------------------
	var scene_text := FileAccess.get_file_as_string("res://scenes/multiplayer_test.tscn")
	var script_text := FileAccess.get_file_as_string("res://scripts/multiplayer_test.gd")
	_check(not scene_text.to_lower().contains("raupe"), "the multiplayer scene has no quiet Raupe spawn")
	_check(not script_text.to_lower().contains("raupe"), "the multiplayer script has no quiet Raupe spawn")

	# --- the actor of the rules module is usable without a scene --------------
	var standalone: RefCounted = Actor.new()
	standalone.call("setup", {
		"actor_pos": func() -> Vector3: return Vector3.ZERO,
		"max_fow": func() -> float: return 20.0,
		"is_contained": func() -> bool: return false,
		"owner_id": func() -> String: return "scene",
		"query_farm": func(_request: Dictionary) -> Dictionary: return {},
		"query_dwarf": func(_request: Dictionary) -> Dictionary: return {},
		"query_plant": func(_request: Dictionary) -> Dictionary: return {},
		"pick_place": func(request: Dictionary) -> Dictionary:
			return {"code": 1, "position": request.get("center", Vector3.ZERO)},
		"move_action": func(_params: Dictionary) -> bool: return true,
		"move_complete": func() -> bool: return true,
	}, 20261119)
	standalone.call("tick", 1.0)
	_check(String(standalone.call("get_state")) == "free", "an actor without a scene roams in the free state")
	print("RAUPE_SCENE_STANDALONE state=%s variant=%s" % [
		String(standalone.call("get_state")),
		String(standalone.call("get_variant_tag")),
	])

	if _failures.is_empty():
		print("NATIVE_RAUPE_SCENE_SELF_TEST_OK assertions=%d" % _checks)
	else:
		printerr("NATIVE_RAUPE_SCENE_SELF_TEST_FAIL failures=%d" % _failures.size())
	quit(0 if _failures.is_empty() else 1)
