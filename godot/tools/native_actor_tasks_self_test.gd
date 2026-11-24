extends SceneTree
const Eval: Script = preload("res://scripts/native_task_eval.gd")
const Runner: Script = preload("res://scripts/native_actor_tasks.gd")
var checks: int = 0
var failures: int = 0
var trace: Array = []
var current: RefCounted = null


func check(condition: bool, label: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		printerr("FAIL ", label)


func record(args: Array[String], command: String) -> Dictionary:
	var entry: Array[String] = [command]
	entry.append_array(args)
	trace.append(entry)
	if command == "returns_false":
		return Eval.ok("0")
	if command in ["irandom", "play_anim"]:
		return Eval.ok("1")
	return Eval.ok(args[-1] if not args.is_empty() else "")


func start_async(_args: Array[String]) -> Dictionary:
	current.begin_action()
	return Eval.ok("1")


func _init() -> void:
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_actor_task_contract.json"))
	for fixture: Dictionary in data["fixtures"]:
		var evaluator: RefCounted = Eval.new()
		evaluator.variables = fixture["variables"].duplicate(true)
		for command: String in ["capture", "returns_false", "play_anim", "irandom"]:
			evaluator.handlers[command] = record.bind(command)
		trace.clear()
		var result: Dictionary = evaluator.evaluate(fixture["script"])
		check(int(result["code"]) == int(fixture["code"]), str(fixture["name"]) + " completion code: " + str(result))
		check(trace == fixture["trace"], str(fixture["name"]) + " effects: " + str(trace))
		if int(result["code"]) == 0:
			check(result["value"] == fixture["value"], str(fixture["name"]) + " result")
	current = Runner.new()
	current.evaluator.handlers = {"async": start_async, "capture": record.bind("capture")}
	current.queue.add("async;capture same_script")
	current.queue.add("capture next_element")
	trace.clear()
	current.dispatch()
	var old_token: int = current.token
	check(current.blocked and trace == [["capture", "same_script"]], "async does not suspend compound remainder")
	check(current.queue.count() == 1, "dequeue before eval")
	check(not current.dispatch()["dispatched"], "next element waits for callback")
	check(current.complete(old_token) and not current.complete(old_token), "completion once")
	current.dispatch()
	check(trace.size() == 2 and trace[-1] == ["capture", "next_element"], "callback enables next element")
	current.queue.add("async")
	current.dispatch()
	old_token = current.token
	current.queue.add("capture cancelled")
	current.interrupt()
	current.queue.add("async")
	current.dispatch()
	check(not current.complete(old_token) and current.blocked, "stale callback cannot enable replacement")
	check(current.queue.count() == 0, "interrupt clears old pending commands")
	current.interrupt()
	current.queue.add("capture back")
	current.queue.add_front("capture front")
	current.dispatch()
	check(trace[-1] == ["capture", "front"] and current.queue.count() == 1, "addfront and one element per tick")
	var copy: Array[String] = current.queue.commands()
	copy.clear()
	check(current.queue.count() == 1 and current.queue.find("capture back") == 0, "queue isolation and exact find")
	current.interrupt()
	current.queue.add("unsupported")
	current.queue.add("capture after_error")
	current.dispatch()
	check(not current.last_error.is_empty() and not current.dispatch()["dispatched"], "unsupported operation fails visibly and pauses queue")
	var second: RefCounted = Runner.new()
	second.queue.add("set other independent")
	second.dispatch()
	check(second.evaluator.variables["other"] == "independent" and current.queue.count() == 1, "actors remain independent")
	current = null
	print("NATIVE_ACTOR_TASKS_SELF_TEST checks=", checks, " failures=", failures)
	quit(0 if failures == 0 else 1)
