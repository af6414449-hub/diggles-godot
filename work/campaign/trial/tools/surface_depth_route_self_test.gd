extends SceneTree
const WALK: Script = preload("res://scripts/surface_walk_action.gd")
var checks: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func check(condition: bool, message: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		push_error("SURFACE_DEPTH_ROUTE_FAILED " + message)


func _height(_sample: Vector2i) -> int:
	return 7


func _unknown(_sample: Vector2i) -> Variant:
	return null


func _run() -> void:
	var samples: Array[Vector2i] = [Vector2i(0,0),Vector2i(8,0),Vector2i(16,0)]
	var modes: Array[int] = [2,2,2]
	var route: Array[Vector3] = [Vector3(0,0,14.5),Vector3(1,0,14.5),Vector3(2,0,12.5)]
	check(WALK.project_floor_runs(route,modes,samples,_height,9.0,11.0),"floor projection succeeds")
	check(route[0].z==9.0 and route[1].z==10.0 and route[2].z==11.0,"direct XZ line uses actual depth endpoints")
	check(WALK.project_floor_runs(route,modes,samples,_height,9.0),"unspecified floor depth")
	check(route[0].z==9.0 and route[2].z==9.0,"no requested depth change preserves current depth")
	modes = [2,2,0]
	route = [Vector3(0,0,14.5),Vector3(1,0,14.5),Vector3(1,1,8)]
	check(WALK.project_floor_runs(route,modes,samples,_height,10.0),"floor to wall")
	check(route[0].z==10 and route[1].z==8 and route[2].z==8,"approach goes directly to wall depth")
	modes = [0,2,2]
	route = [Vector3(0,0,8),Vector3(1,0,14.5),Vector3(2,0,14.5)]
	check(WALK.project_floor_runs(route,modes,samples,_height,8.0,10.0),"wall to floor")
	check(route[0].z==8 and route[1].z==8 and route[2].z==10,"wall exit has no excursion toward camera")
	var before: Array[Vector3] = route.duplicate()
	check(not WALK.project_floor_runs(route,modes,samples,_unknown,8,10) and route==before,"unknown support rejects refinement atomically")
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	subject.set_process(false)
	subject.automatic_torches = false
	for point: Vector2i in [Vector2i(1,15),Vector2i(2,15),Vector2i(2,16),Vector2i(1,16)]:
		check(subject.native_mark_corridor_cell(0,point) and subject.native_dig_apply_cell(0,point),"actual BDB passage fixture")
	var worker: Node3D = subject.dwarf_nodes[0]
	worker.position = Vector3(1.5,-16.5,12.0)
	subject.dwarf_surface_modes[worker] = 2
	for leg: int in range(2):
		var target: Vector2i = Vector2i(64,116) if leg==0 else Vector2i(12,132)
		check(subject.assign_dwarf_surface_walk(worker,target,true,false,12.0),"assign passage/cave leg")
		var max_depth: float = worker.position.z
		for frame: int in range(3000):
			if not subject.dwarf_walk_actions.has(worker):
				break
			subject._update_dwarf_locomotion(0.05)
			max_depth = maxf(max_depth,worker.position.z)
		check(not subject.dwarf_walk_actions.has(worker) and subject.surface_walk_results[worker]==4,"route finishes")
		check(max_depth<=12.00001 and is_equal_approx(worker.position.z,12.0),"actual shaft transition does not visit front lane14.5")
		print("SURFACE_DEPTH_ROUTE_LEG ",leg," max_z=",max_depth," end=",worker.position)
	subject.queue_free()
	print("SURFACE_DEPTH_ROUTE_SELF_TEST checks=%d failures=%d" % [checks,failures])
	quit(0 if failures==0 else 1)
