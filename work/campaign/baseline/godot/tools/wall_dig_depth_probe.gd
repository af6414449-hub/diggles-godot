extends SceneTree

func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	root.add_child(subject)
	subject.set_process(false)
	subject.automatic_torches = false
	for point: Vector2i in [Vector2i(1,15),Vector2i(2,15),Vector2i(1,16),Vector2i(2,16),Vector2i(1,17),Vector2i(2,17)]:
		subject.native_mark_corridor_cell(0,point)
		subject.native_dig_apply_cell(0,point)
	for point: Vector2i in [Vector2i(1,18),Vector2i(2,18)]:
		subject.native_mark_corridor_cell(0,point)
		subject.native_dig_apply_cell(0,point)
	var worker: Node3D = subject.dwarf_nodes[0]
	var standing: Vector2i = Vector2i(12,142)
	worker.position = Vector3(1.5,-17.75,float(subject.WALK_POSE.wall_depth(standing,subject._native_height_sample)))
	subject.dwarf_surface_modes[worker] = 0
	print("WALL_PROBE_STAND ",worker.position," flags=",subject.native_walkmap.sample(standing))
	for y: int in range(15,19):
		for x: int in range(1,5):
			var point: Vector2i = Vector2i(x,y)
			if not subject.native_mark_corridor_cell(0,point):
				continue
			var digpoint: Vector3 = Vector3(x,y,float(subject.terrain_state.current_height(point)))
			var request: Dictionary = subject.query_native_dig_stance(digpoint,worker.position)
			var normalized: Dictionary = subject.query_native_walk_target(request["point"]) if request.get("status")=="ok" else {}
			if normalized.get("found_navigation",false):
				var target: Vector3 = normalized["point"]
				var stance: Vector3 = Vector3(target.x,-target.y,target.z)
				print("WALL_PROBE ",point," stance=",stance," clip=",subject._surface_work_clip_at(stance,digpoint)," future_safe=",subject._surface_dig_supports_next(point,stance))
			subject.native_clear_cave_mark(0,point)
	for x: int in range(3,9):
		print("WALL_CHAIN_MARK ",x," ",subject.native_mark_corridor_cell(0,Vector2i(x,17)))
		print("WALL_CHAIN_MARK_SECOND_ROW ",x," ",subject.native_mark_corridor_cell(0,Vector2i(x,18)))
	print("WALL_CHAIN_ASSIGN ",subject.assign_dwarf_dig(worker,Vector2i(3,17)))
	for frame: int in range(5000):
		subject.call("_process",0.05)
		if not subject.dwarf_dig_jobs.has(worker):
			break
	print("WALL_CHAIN_END pos=",worker.position," revision=",subject.terrain_state.revision," tasks=",subject.dwarf_manual_dig_tasks," marks=",subject.native_mark_nibbles)
	for sample_y: int in range(128,157,2):
		var row: String = ""
		for sample_x: int in range(8,49,2):
			var flags: Variant = subject.native_walkmap.sample(Vector2i(sample_x,sample_y))
			row += "?" if flags==null else str(flags)
		print("WALL_NAV_ROW ",sample_y," ",row)
	for probe: Vector2i in [Vector2i(28,148),Vector2i(20,148),Vector2i(28,140)]:
		var blocked: Dictionary = {}
		for offset: Vector2i in subject.WALK_FLAGS.CLEARANCE_OFFSETS:
			var height: Variant = subject._native_height_sample(probe+offset)
			if height==null or int(height)>=14:
				blocked[offset] = height
		print("WALL_BODY_BLOCK ",probe," blocks=",blocked," gate=",subject._native_walk_gate(Vector2i((probe.x+4)>>3,(probe.y+4)>>3)))
	for entry: Vector2i in subject._work_marks():
		var point: Vector2i = entry
		if subject._work_mark(point)==0:
			continue
		var request: Dictionary = subject.query_native_dig_stance(Vector3(point.x,point.y,float(subject.terrain_state.current_height(point))),worker.position)
		print("WALL_CHAIN_REMAIN ",point," request=",request)
		if request.get("found_navigation",false):
			var normalized: Dictionary = subject.query_native_walk_target(request["point"])
			var target: Vector3 = normalized["point"]
			var stance: Vector3 = Vector3(target.x,-target.y,target.z)
			print("WALL_CHAIN_CAUSE ",point," stance=",stance," check=",subject._dwarf_dig_check(stance,point)," clip=",subject._surface_work_clip_at(stance,Vector3(point.x,point.y,float(subject.terrain_state.current_height(point))))," future=",subject._surface_dig_supports_next(point,stance)," currentcheck=",subject._dwarf_dig_check(worker.position,point))
	subject.queue_free()
	quit()
