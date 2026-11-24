extends RefCounted
## Ordered six-slot inventory backed by NativeItemRegistry.

const BASE_SLOT_COUNT: int = 6

var actor_id: String = ""
var _registry: RefCounted = null
var _slots: Array[String] = []


func setup(new_actor_id: String, registry: RefCounted) -> void:
	actor_id = new_actor_id
	_registry = registry
	_slots.clear()
	for index: int in range(BASE_SLOT_COUNT):
		_slots.append("")


func slots() -> Array[String]:
	return _slots.duplicate()


func first_free_slot() -> int:
	for index: int in range(_slots.size()):
		if _slots[index].is_empty():
			return index
	return -1


func pickup(item_id: String) -> bool:
	if _registry == null:
		return false
	var slot: int = first_free_slot()
	if slot < 0:
		return false
	if not bool(_registry.call("try_lock_world_item", item_id, actor_id)):
		return false
	if not bool(_registry.call("move_to_inventory", item_id, actor_id, slot)):
		return false
	_slots[slot] = item_id
	return true


func drop(item_id: String, world_position: Vector3) -> bool:
	if _registry == null:
		return false
	var slot: int = _slots.find(item_id)
	if slot < 0:
		return false
	if not bool(_registry.call("drop_to_world", item_id, actor_id, world_position)):
		return false
	_slots[slot] = ""
	return true
