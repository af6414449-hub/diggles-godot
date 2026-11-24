extends SceneTree
const REPRESENTATIVE: Script = preload("res://scripts/native_navigation_representative.gd")
const MAP: Script = preload("res://scripts/native_walkmap.gd")
const WALK: Script = preload("res://scripts/surface_walk_action.gd")
var checks: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func check(condition: bool, message: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		push_error("NAV_REPRESENTATIVE_FAILED " + message)


func height(_sample: Vector2i) -> int:
	return 7


func _run() -> void:
	var flags: PackedByteArray = PackedByteArray()
	flags.resize(64)
	flags.fill(1)
	check(REPRESENTATIVE.choose(flags)==Vector2i(4,4),"fully available wall center")
	flags.fill(3)
	check(REPRESENTATIVE.choose(flags)==Vector2i(4,7),"full floor class advances down continuous floor samples")
	flags.fill(0)
	for y: int in range(8):
		for x: int in range(1,7):
			flags[y*8+x] = 1
	check(REPRESENTATIVE.choose(flags)==Vector2i(4,4),"partial wall uses source center score")
	flags[36] = 0
	check(REPRESENTATIVE.choose(flags)==Vector2i(4,3),"strict tie keeps original row-major winner")
	flags[9] = 3
	check(REPRESENTATIVE.choose(flags)==Vector2i(1,1),"source floor bonus beats wall center")
	flags.fill(0)
	flags[0] = 1
	check(REPRESENTATIVE.choose(flags)==null,"score-zero corner cannot turn sentinel center into navigation")
	var walkmap: RefCounted = MAP.new()
	walkmap.sample_bounds = Rect2i(0,0,8,32)
	walkmap.flags.resize(256)
	walkmap.unknown_samples.resize(256)
	for y: int in range(32):
		for x: int in range(1,7):
			walkmap.flags[y*8+x] = 1
	var start: Vector2i = Vector2i(1,1)
	var goal: Vector2i = Vector2i(6,30)
	var result: Dictionary = WALK.plan(start,goal,walkmap,height,true)
	check(result.status=="ok" and result.planner=="host_bfs_via_source_cell_representatives","graph uses source representatives")
	var centered: bool = true
	var navigable: bool = true
	for point: Vector2i in result.samples:
		if point.y>4 and point.y<28:
			centered = centered and point.x==4
		navigable = navigable and (int(walkmap.sample(point))&1)!=0
	check(centered,"intermediate shaft route follows cell center instead of edge")
	check(navigable and result.samples[0]==start and result.samples[-1]==goal,"validated connectors retain actual endpoints")
	walkmap.unknown_samples[0] = 1
	walkmap.revision += 1
	check(walkmap.cell_representative(Vector2i.ZERO)==null,"partial unknown cell does not invent a summary")
	result = WALK.plan(start,goal,walkmap,height,true)
	check(result.status=="ok" and result.planner=="host_cardinal_bfs_over_source_samples","known sample route remains available when summary is unknown")
	print("NAVIGATION_REPRESENTATIVE_SELF_TEST checks=%d failures=%d" % [checks,failures])
	quit(0 if failures==0 else 1)
