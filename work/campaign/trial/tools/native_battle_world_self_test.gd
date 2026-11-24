extends SceneTree

const BATTLE_WORLD: Script = preload("res://scripts/native_battle_world.gd")

var checks: int = 0
var failures: int = 0


func check(condition: bool, label: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		printerr("FAIL ",label)


func _initialize() -> void:
	var subject: RefCounted = BATTLE_WORLD.new()
	var loaded: bool = subject.load_first_slice("res://../docs/reverse-engineering/minimax-battle-world-2026-11-19.json")
	check(loaded,
		"loads source-derived first battle slice")
	check(subject.validate().is_empty(),"all first-slice invariants hold")
	var world_size: Array = subject.data["world_size"]
	var area_min: Array = subject.data["area_min"]
	check(int(world_size[0]) == 112 and int(world_size[1]) == 88,"world uses source 112x88 bounds")
	check(int(area_min[0]) == 16 and int(area_min[1]) == 16,"area offset is source 16,16")
	var caves: Array[Rect2i] = subject.cave_world_rects()
	check(caves.size() == 3 and caves[0] == Rect2i(24,24,44,24),"split start cave is placed at preset plus area")
	var walls: Array[Rect2i] = subject.stone_world_rects(0)
	check(walls.size() == 4,"source type0 stone frame has four strips")
	var enclosed: bool = true
	for cave: Rect2i in caves:
		var min_x: int = 16
		var max_x: int = 90
		var min_y: int = 16
		var max_y: int = 66
		enclosed = enclosed and cave.position.x >= min_x and cave.position.y >= min_y \
			and cave.end.x <= max_x and cave.end.y <= max_y
	check(enclosed,"stone frame encloses every first-slice cave")
	var bridges: Array[Rect2i] = subject.stone_world_rects(2)
	check(bridges == [Rect2i(64,32,6,6),Rect2i(24,44,6,6)],"type2 bridge rects include native plus2 expansion")
	print("NATIVE_BATTLE_WORLD_SELF_TEST checks=%d failures=%d caves=%s" % [checks,failures,caves])
	quit(0 if failures == 0 else 1)
