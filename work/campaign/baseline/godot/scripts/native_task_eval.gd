extends RefCounted
## Deliberately bounded Tcl word/substitution evaluator, NOT a Tcl interpreter.
## Supports scalar variables, braces/quotes, nested commands and basic escapes.
## Unsupported commands/array variables/numeric escapes fail explicitly.
## Handler contract: {code: Tcl completion code, value: String}. "0" is success.

var variables: Dictionary = {}
var handlers: Dictionary = {}


static func ok(value: String = "") -> Dictionary:
	return {"code": 0, "value": value}


static func error(message: String) -> Dictionary:
	return {"code": 1, "value": message}


func evaluate(script: String) -> Dictionary:
	var cursor: Dictionary = {"text": script, "at": 0, "error": ""}
	return _script(cursor, false, 0)


func _script(cursor: Dictionary, nested: bool, depth: int) -> Dictionary:
	if depth > 32:
		return error("Task substitution depth limit")
	var words: Array[String] = []
	var result: Dictionary = ok()
	var text: String = cursor["text"]
	while int(cursor["at"]) < text.length():
		var character: String = text[int(cursor["at"])]
		if character in [" ", "\t", "\r"]:
			cursor["at"] += 1
			continue
		if character == "\\" and text.substr(int(cursor["at"]), 2) == "\\\n":
			cursor["at"] += 1
			_continuation(cursor)
			continue
		if character == "#" and words.is_empty():
			while int(cursor["at"]) < text.length() and text[int(cursor["at"])] != "\n":
				if text.substr(int(cursor["at"]), 2) == "\\\n":
					cursor["at"] += 2
					continue
				cursor["at"] += 1
			continue
		if character in [";", "\n"] or (nested and character == "]"):
			cursor["at"] += 1
			if not words.is_empty():
				result = _invoke(words)
				words.clear()
				if int(result["code"]) != 0:
					return result
			if nested and character == "]":
				return result
			continue
		words.append(_word(cursor, depth))
		if not str(cursor["error"]).is_empty():
			return error(cursor["error"])
	if nested:
		return error("Missing closing bracket")
	return _invoke(words) if not words.is_empty() else result


func _word(cursor: Dictionary, depth: int) -> String:
	var text: String = cursor["text"]
	var start: String = text[int(cursor["at"])]
	var braced: bool = start == "{"
	var quoted: bool = start == '"'
	var braces: int = 1
	var value: String = ""
	if braced or quoted:
		cursor["at"] += 1
	while int(cursor["at"]) < text.length():
		var character: String = text[int(cursor["at"])]
		if braced:
			cursor["at"] += 1
			if character == "\\":
				if int(cursor["at"]) >= text.length():
					break
				if text[int(cursor["at"])] == "\n":
					value += _continuation(cursor)
				else:
					value += character + text[int(cursor["at"])]
					cursor["at"] += 1
				continue
			if character == "{":
				braces += 1
			elif character == "}":
				braces -= 1
				if braces == 0:
					_check_word_end(cursor)
					return value
			value += character
			continue
		if quoted and character == '"':
			cursor["at"] += 1
			_check_word_end(cursor)
			return value
		if not quoted and character in [" ", "\t", "\r", "\n", ";", "]"]:
			# ] is a boundary only inside a command substitution. At top level
			# it is literal; _word cannot know nesting, so consume via cursor flag.
			if character != "]" or bool(cursor.get("in_substitution", false)):
				return value
		if not quoted and character == "\\" and text.substr(int(cursor["at"]), 2) == "\\\n":
			cursor["at"] += 1
			_continuation(cursor)
			return value
		cursor["at"] += 1
		if character == "\\":
			value += _escape(cursor)
		elif character == "$":
			value += _variable(cursor)
		elif character == "[":
			var was_nested: bool = bool(cursor.get("in_substitution", false))
			cursor["in_substitution"] = true
			var substitution: Dictionary = _script(cursor, true, depth + 1)
			cursor["in_substitution"] = was_nested
			if int(substitution["code"]) != 0:
				cursor["error"] = str(substitution["value"])
			else:
				value += str(substitution["value"])
		else:
			value += character
		if not str(cursor["error"]).is_empty():
			return ""
	if braced or quoted:
		cursor["error"] = "Missing closing brace or quote"
	return value


func _check_word_end(cursor: Dictionary) -> void:
	var text: String = cursor["text"]
	if int(cursor["at"]) < text.length():
		var character: String = text[int(cursor["at"])]
		if not character in [" ", "\t", "\r", "\n", ";"] \
				and not (character == "]" and bool(cursor.get("in_substitution", false))):
			cursor["error"] = "Extra characters after grouped word"


func _continuation(cursor: Dictionary) -> String:
	var text: String = cursor["text"]
	cursor["at"] += 1
	while int(cursor["at"]) < text.length() and text[int(cursor["at"])] in [" ", "\t"]:
		cursor["at"] += 1
	return " "


func _escape(cursor: Dictionary) -> String:
	var text: String = cursor["text"]
	if int(cursor["at"]) >= text.length():
		return "\\"
	var character: String = text[int(cursor["at"])]
	if character == "\n":
		return _continuation(cursor)
	cursor["at"] += 1
	if character in ["u", "U", "x", "0", "1", "2", "3", "4", "5", "6", "7"]:
		cursor["error"] = "Numeric escape is outside task evaluator subset"
		return ""
	return {"n": "\n", "r": "\r", "t": "\t", "a": "\u0007", "b": "\b", "f": "\f", "v": "\v"}.get(character, character)


func _variable(cursor: Dictionary) -> String:
	var text: String = cursor["text"]
	var at: int = int(cursor["at"])
	var name: String = ""
	if at < text.length() and text[at] == "{":
		at += 1
		while at < text.length() and text[at] != "}":
			name += text[at]
			at += 1
		if at == text.length():
			cursor["error"] = "Missing variable brace"
			return ""
		at += 1
	else:
		while at < text.length():
			var character: String = text[at]
			if not (character >= "a" and character <= "z") and not (character >= "A" and character <= "Z") \
					and not (character >= "0" and character <= "9") and character != "_":
				break
			name += character
			at += 1
		if at < text.length() and text[at] in ["(", ":"]:
			cursor["error"] = "Array/namespace variables are outside task evaluator subset"
			return ""
	cursor["at"] = at
	if name.is_empty():
		return "$"
	if not variables.has(name):
		cursor["error"] = "Unknown task variable: " + name
		return ""
	return str(variables[name])


func _invoke(words: Array[String]) -> Dictionary:
	var args: Array[String] = words.slice(1)
	match words[0]:
		"set":
			if not args.is_empty() and (args[0].contains(":") or args[0].contains("(")):
				return error("Array/namespace variables are outside task evaluator subset")
			if args.size() == 2:
				variables[args[0]] = args[1]
			if args.size() in [1, 2] and variables.has(args[0]):
				return ok(str(variables[args[0]]))
			return error("Invalid set or missing variable")
		"string":
			if args.size() != 3 or args[0] != "index" or not args[2].is_valid_int():
				return error("Only string index with integer index is supported")
			var index: int = int(args[2])
			return ok(args[1].substr(index, 1) if index >= 0 and index < args[1].length() else "")
		"error":
			return error(args[0]) if args.size() == 1 else error("Invalid error arity")
	if not handlers.has(words[0]):
		return error("Unsupported task command: " + words[0])
	var result: Variant = handlers[words[0]].call(args)
	if not result is Dictionary or not result.has("code") or not result.has("value"):
		return error("Invalid task handler completion contract")
	return result
