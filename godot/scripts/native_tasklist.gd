extends RefCounted
## FIFO API contributed by Minimax, checked against original tasklist callers.
## Storage adapter only. Invalid-index empty-string policy is host-defined.

var _commands: Array[String] = []


func add(command: String) -> void:
	_commands.append(command)


func add_front(command: String) -> void:
	_commands.push_front(command)


func count() -> int:
	return _commands.size()


func get_command(index: int) -> String:
	return _commands[index] if index >= 0 and index < _commands.size() else ""


func remove(index: int) -> String:
	var command: String = get_command(index)
	if index >= 0 and index < _commands.size():
		_commands.remove_at(index)
	return command


func clear() -> void:
	_commands.clear()


func commands() -> Array[String]:
	return _commands.duplicate()


func find(command: String) -> int:
	return _commands.find(command)


## Compatibility names for the hamster actor (hamster.tcl tasklist).
##
## The original Tcl queue used the names tasklist_cnt, tasklist_rem,
## tasklist_list, tasklist_get and the original states drained it with
## cnt > 0 -> get 0 -> rem 0. The live project spells the same operations
## count(), remove(index), commands() and get_command(index).
##
## Both spellings now live side by side. Nothing existing changes: the queue
## of the dwarves keeps using count() and remove(0), the hamster actor calls
## these names dynamically with _queue.call("cnt") and friends.
func cnt() -> int:
	return _commands.size()


## Remove the command at an index (tasklist_rem) and return it.
##
## Out of range returns "" and removes nothing, same as remove(index).
func rem(index: int) -> String:
	return remove(index)


## All commands in order (tasklist_list).
func list() -> Array[String]:
	return _commands.duplicate()


## Pop the first command, or "" when the queue is empty (tasklist_get 0 +
## tasklist_rem 0).
func pop_front() -> String:
	return remove(0)


## True when the actor has queued commands.
func has_pending() -> bool:
	return not _commands.is_empty()
