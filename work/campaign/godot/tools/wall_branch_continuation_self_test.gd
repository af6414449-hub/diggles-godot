extends SceneTree
const STROKE: Script = preload("res://scripts/native_corridor_stroke.gd")
var checks: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func check(condition: bool, message: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		push_error("WALL_BRANCH_FAILED " + message)


func _run() -> void:
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	subject.set_process(false)
	subject.automatic_torches = false
	for y: int in range(15,19):
		for x: int in range(1,3):
			check(subject.native_mark_corridor_cell(0,Vector2i(x,y)) and subject.native_dig_apply_cell(0,Vector2i(x,y)),"vertical shaft fixture")
	var worker: Node3D = subject.dwarf_nodes[0]
	var sample: Vector2i = Vector2i(12,138)
	worker.position = Vector3(1.5,-17.25,float(subject.WALK_POSE.wall_depth(sample,subject._native_height_sample)))
	subject.dwarf_surface_modes[worker] = 0
	check(subject.native_walkmap.sample(sample)==1,"starts hanging, not standing on a floor")
	var stroke: RefCounted = STROKE.new()
	check(stroke.begin(Vector2(1.5,17.5),subject.tunnel_rules.bounds),"original UI brush anchor")
	stroke.update(Vector2(7.5,17.5))
	var marks: int = 0
	for point: Vector2i in stroke.finish():
		if point.x>2 and subject.native_mark_corridor_cell(0,point):
			marks += 1
	check(marks==12,"actual source brush selects both corridor rows")
	check(subject.assign_dwarf_dig(worker,Vector2i(8,17)),"one order on far end selects reachable frontier")
	var wall_work: bool = false
	var maximum_step: float = 0.0
	for frame: int in range(8000):
		var previous: Vector3 = worker.position
		subject.call("_process",0.05)
		maximum_step = maxf(maximum_step,previous.distance_to(worker.position))
		if subject.dwarf_dig_jobs.has(worker):
			wall_work = wall_work or str(subject.dwarf_dig_jobs[worker].get("clip","")).begins_with("kletter_hack_rechts")
		if not subject.dwarf_dig_jobs.has(worker):
			break
	check(wall_work,"lateral wall digging clip executed")
	check(subject.terrain_state.revision==20 and subject.dig_action_completions==12,"one order continues through12 actual branch mutations")
	check(subject.native_mark_nibbles.is_empty() and subject.dwarf_manual_dig_tasks.is_empty(),"completed branch does not remain waiting for a face")
	check(maximum_step<=subject.WALK_SPEED*subject.RUN_SPEED_MULTIPLIER*0.05+0.0001,"approaches use movement budget, no stance teleport")
	print("WALL_BRANCH_CONTINUATION_SELF_TEST checks=%d failures=%d mutations=%d max_step=%f" % [checks,failures,subject.terrain_state.revision-8,maximum_step])
	subject.queue_free()
	quit(0 if failures==0 else 1)
