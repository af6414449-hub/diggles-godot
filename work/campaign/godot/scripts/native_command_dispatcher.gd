## Command dispatcher for actor tasklists.
##
## The original game executes queued commands with Tcl `eval`
## (z_work_states.tcl:13-22). This module is the Godot side of that: it parses
## a command string into a head command plus arguments and calls a registered
## handler.
##
## Sources (original install, data/Scripts):
##   classes/zwerg/z_work_prod.tcl:229-232   - compound commands separated by ';'
##   classes/zwerg/z_work_common.tcl:91-94   - brace grouped arguments
##   classes/zwerg/z_work_states.tcl:98-149  - the command shapes that are queued
##
## Command vocabulary recovered from the original: 200 distinct heads over 1573
## tasklist calls (res://models/native_tasklist_commands.json).
##
## Handlers are Callables with the signature func(args: Array) -> bool.
## Returning false aborts the rest of a compound command, which is how a failed
## step stops the chain in the original.
extends RefCounted

const VOCABULARY_PATH := "res://models/native_tasklist_commands.json"

var _handlers: Dictionary = {}
var _vocabulary: Dictionary = {}
var _vocabulary_loaded := false


## Register a handler for a head command.
func register(command: String, handler: Callable) -> void:
	_handlers[command] = handler


func unregister(command: String) -> void:
	_handlers.erase(command)


func has_handler(command: String) -> bool:
	return _handlers.has(command)


## Registered head commands.
func registered_commands() -> Array:
	return _handlers.keys()


## Split a command string into statements and parse each one.
##
## "beam_from_inv_to_pos $item {$itempos};play_anim bendb" becomes two
## statements: {head: "beam_from_inv_to_pos", args: ["$item", "$itempos"]} and
## {head: "play_anim", args: ["bendb"]}.
static func parse(command_string: String) -> Array:
	var statements: Array = []
	for statement in split_statements(command_string):
		var tokens := tokenize(statement)
		if tokens.is_empty():
			continue
		statements.append({"head": tokens[0], "args": tokens.slice(1)})
	return statements


## Split on top level ';' - braces and quotes group, like Tcl.
static func split_statements(command_string: String) -> Array:
	var parts: Array = []
	var current := ""
	var depth := 0
	var in_quote := false
	var index := 0
	while index < command_string.length():
		var character := command_string[index]
		if character == "\\" and index + 1 < command_string.length():
			current += command_string.substr(index, 2)
			index += 2
			continue
		if character == '"':
			in_quote = not in_quote
		elif not in_quote:
			if character == "{":
				depth += 1
			elif character == "}":
				depth -= 1
			elif character == ";" and depth == 0:
				parts.append(current.strip_edges())
				current = ""
				index += 1
				continue
		current += character
		index += 1
	parts.append(current.strip_edges())
	return parts.filter(func(part: String) -> bool: return part != "")


## Tokenize one statement: head plus arguments.
##
## "{...}" and "..." group into a single argument, braces are stripped.
static func tokenize(statement: String) -> Array:
	var tokens: Array = []
	var index := 0
	var length := statement.length()
	while index < length:
		while index < length and statement[index] in [" ", "\t"]:
			index += 1
		if index >= length:
			break
		var character := statement[index]
		if character == "{":
			var depth := 1
			var start := index + 1
			index += 1
			while index < length and depth > 0:
				if statement[index] == "{":
					depth += 1
				elif statement[index] == "}":
					depth -= 1
					if depth == 0:
						break
				index += 1
			tokens.append(statement.substr(start, index - start))
			index += 1
		elif character == "\"":
			var start := index + 1
			index += 1
			while index < length and statement[index] != "\"":
				index += 1
			tokens.append(statement.substr(start, index - start))
			index += 1
		else:
			var start := index
			while index < length and statement[index] not in [" ", "\t", ";"]:
				index += 1
			tokens.append(statement.substr(start, index - start))
	return tokens


## Execute a command string.
##
## Returns {ok, executed, results, error}. `results` holds one entry per
## statement: {head, ok, error}. A handler returning false stops the chain and
## makes ok false.
func dispatch(command_string: String) -> Dictionary:
	var results: Array = []
	var executed := 0
	for statement in parse(command_string):
		var head := String(statement["head"])
		var args: Array = statement["args"]
		if not _handlers.has(head):
			results.append({"head": head, "ok": false, "error": "unknown command: %s" % head})
			return {
				"ok": false,
				"executed": executed,
				"results": results,
				"error": "unknown command: %s" % head,
			}
		var handler: Callable = _handlers[head]
		var ok := false
		var error := ""
		var returned = handler.call(args)
		if typeof(returned) == TYPE_BOOL:
			ok = returned
		elif typeof(returned) == TYPE_DICTIONARY:
			ok = bool(returned.get("ok", true))
			error = String(returned.get("error", ""))
		else:
			ok = true
		executed += 1
		results.append({"head": head, "ok": ok, "error": error})
		if not ok:
			return {
				"ok": false,
				"executed": executed,
				"results": results,
				"error": error if error != "" else "command failed: %s" % head,
			}
	return {"ok": true, "executed": executed, "results": results, "error": ""}


## Head commands that the original game queues (recovered vocabulary).
func known_commands() -> Dictionary:
	if not _vocabulary_loaded:
		_vocabulary_loaded = true
		if FileAccess.file_exists(VOCABULARY_PATH):
			var file := FileAccess.open(VOCABULARY_PATH, FileAccess.READ)
			if file != null:
				var parsed: Variant = JSON.parse_string(file.get_as_text())
				file.close()
				if typeof(parsed) == TYPE_DICTIONARY:
					for entry: Dictionary in (parsed.get("commands", []) as Array):
						_vocabulary[String(entry.get("command", ""))] = int(entry.get("occurrences", 0))
	return _vocabulary


## True when the head command exists in the recovered original vocabulary.
func is_known_command(command: String) -> bool:
	return known_commands().has(command)
