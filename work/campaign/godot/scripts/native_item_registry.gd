extends RefCounted
## Authoritative location state for world items and actor inventories.

const LOCATION_WORLD: StringName = &"world"
const LOCATION_INVENTORY: StringName = &"inventory"

var _items: Dictionary = {}


func register_world_item(item_id: String, class_name: String, world_position: Vector3) -> bool:
	if item_id.is_empty() or _items.has(item_id):
		return false
	_items[item_id] = {
		"id": item_id,
		"class_name": class_name,
		"location": LOCATION_WORLD,
		"owner_id": "",
		"slot": -1,
		"world_position": world_position,
		"locked_by": "",
	}
	return true


func item(item_id: String) -> Dictionary:
	if not _items.has(item_id):
		return {}
	return (_items[item_id] as Dictionary).duplicate(true)


func try_lock_world_item(item_id: String, actor_id: String) -> bool:
	var state: Dictionary = _mutable(item_id)
	if state.is_empty() or StringName(state["location"]) != LOCATION_WORLD:
		return false
	var lock_owner: String = String(state["locked_by"])
	if not lock_owner.is_empty() and lock_owner != actor_id:
		return false
	state["locked_by"] = actor_id
	return true


func move_to_inventory(item_id: String, actor_id: String, slot: int) -> bool:
	var state: Dictionary = _mutable(item_id)
	if state.is_empty() or slot < 0:
		return false
	if StringName(state["location"]) != LOCATION_WORLD:
		return false
	var lock_owner: String = String(state["locked_by"])
	if not lock_owner.is_empty() and lock_owner != actor_id:
		return false
	state["location"] = LOCATION_INVENTORY
	state["owner_id"] = actor_id
	state["slot"] = slot
	state["locked_by"] = ""
	return true


func drop_to_world(item_id: String, actor_id: String, world_position: Vector3) -> bool:
	var state: Dictionary = _mutable(item_id)
	if state.is_empty() or StringName(state["location"]) != LOCATION_INVENTORY:
		return false
	if String(state["owner_id"]) != actor_id:
		return false
	state["location"] = LOCATION_WORLD
	state["owner_id"] = ""
	state["slot"] = -1
	state["world_position"] = world_position
	state["locked_by"] = ""
	return true


func _mutable(item_id: String) -> Dictionary:
	if not _items.has(item_id):
		return {}
	return _items[item_id] as Dictionary
