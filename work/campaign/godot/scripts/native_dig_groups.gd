extends RefCounted
## Fresh native mark manager: per-slot dword counters and packed group words.
## EXE 0x56631C, 0x5673AD, 0x566783; saved manager import is separate.

var counters: Array[int] = [0, 0, 0, 0, 0, 0, 0, 0]
var words: Dictionary = {}


func word(point: Vector2i) -> int:
	# Our runtime starts with explicitly cleared marks/groups, not an imported save.
	return int(words.get(point, 0)) & 0xFFFFFFFF


func stamp(point: Vector2i, slot: int) -> void:
	var shift: int = slot * 4
	words[point] = ((word(point) & ~(15 << shift)) | ((counters[slot] & 15) << shift)) & 0xFFFFFFFF


func finish_commit(slot: int) -> void:
	# Also advances after a fully rejected/empty mode1 commit, not on cancel.
	counters[slot] = (counters[slot] + 1) & 0xFFFFFFFF


static func worker_stamp(groups: int, slot: int) -> int:
	# SHR, without the candidate-only AND 15. Preserve this native asymmetry.
	return (groups & 0xFFFFFFFF) >> (slot * 4)
