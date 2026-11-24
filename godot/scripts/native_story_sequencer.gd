class_name NativeStorySequencer
extends RefCounted

## Data-only adapter for the original Diggles story sequencer.
## It intentionally does not create Nodes or call game APIs.

var actors: Array[Dictionary] = []
var objects: Array[Dictionary] = []
var events: Array[Dictionary] = []
var enabled: Array[bool] = []
var camera: Dictionary = {}
var loading: bool = false
var map_size: Vector2i = Vector2i.ZERO
var cursor: int = 0
var trace: Array[Dictionary] = []
var skipped_commands: Array[String] = []

func reset() -> void:
	actors.clear()
	objects.clear()
	events.clear()
	enabled.clear()
	camera.clear()
	loading = false
	map_size = Vector2i.ZERO
	cursor = 0
	trace.clear()
	skipped_commands.clear()

func parse_script(source: String) -> Array[Dictionary]:
	reset()
	var commands: Array[Dictionary] = []
	for raw_line: String in source.split("\n"):
		var line: String = raw_line.strip_edges()
		if line.is_empty() or line.begins_with("#") or line.begins_with("//"):
			continue
		var control: String = "normal"
		if line.begins_with("+"):
			control = "plus"
			line = line.substr(1).strip_edges()
		elif line.begins_with("-"):
			control = "minus"
			line = line.substr(1).strip_edges()
		var tokens: Array[String] = _tokenize(line)
		if tokens.is_empty():
			continue
		commands.append({"name": tokens[0], "args": tokens.slice(1), "control": control, "line": raw_line})
	return commands

func execute(source: String) -> Array[Dictionary]:
	var commands: Array[Dictionary] = parse_script(source)
	for command: Dictionary in commands:
		_apply(command)
	return trace.duplicate(true)

## Sends normalized events to a scene/runtime adapter.
func dispatch_trace(adapter: Callable) -> int:
	var dispatched: int = 0
	for event: Dictionary in trace:
		if adapter.is_valid():
			adapter.call(event)
			dispatched += 1
	return dispatched

func _apply(command: Dictionary) -> void:
	var name: String = String(command["name"])
	var args: Array[String] = command["args"]
	var control: String = String(command["control"])
	var record: Dictionary = {"index": trace.size(), "command": name, "args": args.duplicate(), "control": control}
	match name:
		"show_loading":
			loading = args.size() > 0 and args[0].to_lower() == "yes"
			record["loading"] = loading
		"obj_clear":
			objects.clear()
			record["objects_cleared"] = true
		"map":
			if args.size() >= 3 and args[0] == "create":
				map_size = Vector2i(_to_int(args[1]), _to_int(args[2]))
				record["map_size"] = map_size
		"set_view":
			camera = {"x": _to_float(args, 0), "y": _to_float(args, 1), "zoom": _to_float(args, 2), "rx": _to_float(args, 3), "ry": _to_float(args, 4)}
			record["camera"] = camera.duplicate()
		"call":
			record["script"] = args[0] if not args.is_empty() else ""
		"MapTemplateSet":
			record["template_origin"] = Vector2i(_to_int(args[0]), _to_int(args[1])) if args.size() >= 2 else Vector2i.ZERO
		"sm_def_temp_group":
			record["template_group"] = args
		"sel":
			record["selection"] = args[0] if not args.is_empty() else ""
		"sequence_enable", "sequence_disable":
			var value: bool = name == "sequence_enable"
			var who: String = args[0] if not args.is_empty() else "all"
			if who == "all":
				for i: int in enabled.size():
					enabled[i] = value
			record["enabled"] = value
			record["who"] = who
		"sq_actor":
			var actor_command: String = args[0] if not args.is_empty() else ""
			var actor_selector: String = args[1] if args.size() > 1 else "all"
			if actor_command == "find":
				var actor: Dictionary = {"class": args[2] if args.size() > 2 else "", "selector": actor_selector}
				actors.append(actor)
				enabled.append(false)
				record["actor_index"] = actors.size() - 1
			elif actor_command in ["idleanim", "express", "mouth", "eyes", "setrot", "focus", "actionlist"]:
				record["actor_command"] = actor_command
				record["actor_selector"] = actor_selector
		"sq_object":
			record["object_command"] = args[0] if not args.is_empty() else ""
			if not args.is_empty() and args[0] == "summon":
				objects.append({"class": args[1] if args.size() > 1 else "", "index": objects.size()})
		"sq_text":
			record["text_command"] = args[0] if not args.is_empty() else ""
			record["text_file"] = args[1] if args.size() > 1 else ""
		"sq_audio":
			record["audio_command"] = args[0] if not args.is_empty() else ""
			record["audio_data"] = args[1] if args.size() > 1 else ""
		"sq_music":
			record["music_theme"] = args[0] if not args.is_empty() else ""
			record["music_position"] = args[1] if args.size() > 1 else ""
		"sq_camera":
			record["camera_command"] = args[0] if not args.is_empty() else ""
		"sq_screenvibe":
			record["screen_effect"] = args[0] if not args.is_empty() else ""
		"do_wait":
			record["wait_kind"] = args[0] if not args.is_empty() else "none"
			record["wait_value"] = _to_float(args, 1)
		"do_text":
			record["text"] = args[0] if not args.is_empty() else ""
			record["text_actor"] = args[1] if args.size() > 1 else "all"
		"call_method":
			record["method_target"] = args[0] if not args.is_empty() else ""
			record["method"] = args[1] if args.size() > 1 else ""
		"timer_event":
			record["timer_target"] = args[0] if not args.is_empty() else ""
			record["timer_event"] = args[1] if args.size() > 1 else ""
		"keybind":
			record["keybind_action"] = args[1] if args.size() > 1 else ""
		_:
			skipped_commands.append(name)
			record["status"] = "unhandled_adapter_command"
	trace.append(record)

func _tokenize(line: String) -> Array[String]:
	var result: Array[String] = []
	var current: String = ""
	var quote: String = ""
	var brace_depth: int = 0
	for ch: String in line:
		if not quote.is_empty():
			current += ch
			if ch == quote:
				quote = ""
		elif ch == "\"":
			quote = ch
		elif ch == "{":
			brace_depth += 1
			current += ch
		elif ch == "}":
			brace_depth -= 1
			current += ch
		elif ch == " " or ch == "\t" or ch == "\r":
			if brace_depth == 0 and not current.is_empty():
				result.append(current.strip_edges())
				current = ""
		else:
			current += ch
	if not current.is_empty():
		result.append(current.strip_edges())
	return result

func _to_int(value: String) -> int:
	return int(value)

func _to_float(values: Array[String], index: int) -> float:
	return float(values[index]) if index < values.size() else 0.0
