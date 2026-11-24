extends RefCounted
## One tasklist element per enabled dispatch. Async actions disable dispatch,
## not the remainder of the current compound script (z_procs:186-205).
## Tokens are a host guard against callbacks from replaced actions.

const TaskList: Script = preload("res://scripts/native_tasklist.gd")
const Evaluator: Script = preload("res://scripts/native_task_eval.gd")
var queue: RefCounted = TaskList.new()
var evaluator: RefCounted = Evaluator.new()
var blocked: bool = false
var token: int = 0
var last_error: String = ""
var dispatches: int = 0


func dispatch() -> Dictionary:
	if blocked or not last_error.is_empty() or queue.count() == 0:
		return {"dispatched": false}
	var command: String = queue.remove(0)
	dispatches += 1
	var result: Dictionary = evaluator.evaluate(command)
	if int(result["code"]) != 0:
		last_error = str(result["value"])
	return {"dispatched": true, "command": command, "completion": result}


func begin_action() -> int:
	token += 1
	blocked = true
	return token


func complete(action_token: int) -> bool:
	if not blocked or action_token != token:
		return false
	blocked = false
	return true


func fail(action_token: int, message: String) -> bool:
	if not complete(action_token):
		return false
	last_error = message
	return true


func interrupt() -> void:
	token += 1
	blocked = false
	last_error = ""
	queue.clear()
