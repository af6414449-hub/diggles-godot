extends SceneTree

const Registry: Script = preload("res://scripts/native_item_registry.gd")
const Inventory: Script = preload("res://scripts/native_dwarf_inventory.gd")

var _checks: int = 0
var _failures: int = 0


func _init() -> void:
	var registry: RefCounted = Registry.new()
	var first: RefCounted = Inventory.new()
	var second: RefCounted = Inventory.new()
	first.call("setup", "dwarf-a", registry)
	second.call("setup", "dwarf-b", registry)
	_check(bool(registry.call("register_world_item", "stone-1", "Stein", Vector3(1.0, 2.0, 3.0))), "register stone")
	_check(bool(first.call("pickup", "stone-1")), "first dwarf picks up stone")
	_check((first.call("slots") as Array)[0] == "stone-1", "pickup uses first base slot")
	_check(not bool(second.call("pickup", "stone-1")), "held item cannot be picked twice")
	var held: Dictionary = registry.call("item", "stone-1")
	_check(StringName(held["location"]) == &"inventory" and String(held["owner_id"]) == "dwarf-a", "registry owns held item")
	_check(bool(first.call("drop", "stone-1", Vector3(9.0, 1.0, 4.0))), "owner drops stone")
	_check((first.call("slots") as Array)[0] == "", "drop clears slot")
	var dropped: Dictionary = registry.call("item", "stone-1")
	_check(StringName(dropped["location"]) == &"world" and (dropped["world_position"] as Vector3).is_equal_approx(Vector3(9.0, 1.0, 4.0)), "drop restores world state")
	for index: int in range(6):
		var item_id: String = "fill-%d" % index
		_check(bool(registry.call("register_world_item", item_id, "Stein", Vector3.ZERO)), "register fill %d" % index)
		_check(bool(first.call("pickup", item_id)), "fill slot %d" % index)
	_check(bool(registry.call("register_world_item", "overflow", "Stein", Vector3.ZERO)), "register overflow")
	_check(not bool(first.call("pickup", "overflow")), "full inventory refuses pickup")
	print("NATIVE_ITEM_INVENTORY_SELF_TEST checks=", _checks, " failures=", _failures)
	quit(1 if _failures > 0 else 0)


func _check(condition: bool, label: String) -> void:
	_checks += 1
	if condition:
		return
	_failures += 1
	push_error("NATIVE_ITEM_INVENTORY_SELF_TEST failed: %s" % label)
