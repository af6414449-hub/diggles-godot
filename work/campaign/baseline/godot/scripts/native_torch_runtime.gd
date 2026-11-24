extends RefCounted
## Source contracts driven by a Godot single-player scene adapter.
## Separate outer object passes from 0.1-game-second ticks (6B4BA1/6B4C94).
## Actor IDs and this isolated RNG stream are deterministic host state, not a
## captured native session. Unknown terrain/policy inputs remain deferred.

const AUTO: Script = preload("res://scripts/native_autolight.gd")
const POLICY: Script = preload("res://scripts/native_torch_policy.gd")
const PLACEMENT: Script = preload("res://scripts/native_torch_placement.gd")
const FIX: Script = preload("res://scripts/native_fix_dig.gd")
const TIMING: Script = preload("res://scripts/native_animation_timing.gd")

var world_bounds: Rect2i
var sample_bounds: Rect2i
var read_depth: Callable
var read_material: Callable
var light_records: Array[Dictionary] = []
var region_records: Variant = null
var minimum_y: Variant = null
var frame_bounds: Array[Vector4] = []
var properties: Dictionary = {}
var queue: Array[Dictionary] = []
var torches: Array[Dictionary] = []
var tick: int = 0
var game_seconds: float = 0.0
var remainder: float = 0.0
var rng_state: int = 1
var next_id: int = 0
var enabled: bool = true
var last_decision: Dictionary = {}
var created_this_pass: Array[Dictionary] = []
var frame_playback_mode: int = 0 # class_defaultanim without mode is ANIM_STILL.


func configure(bounds: Rect2i, depth_at: Callable, material_at: Callable,
		source: Dictionary, initial_lights: Array[Dictionary], first_id: int) -> void:
	world_bounds = bounds
	sample_bounds = Rect2i(bounds.position*8,bounds.size*8)
	read_depth = depth_at
	read_material = material_at
	properties = source["properties"]
	light_records = initial_lights.duplicate()
	next_id = first_id
	for frame: Dictionary in source["model"]["frames"]:
		var values: Array = frame["rect_fields"]
		frame_bounds.append(Vector4(values[0],values[1],values[2],values[3]))


func update(delta_game_seconds: float, actors: Array[Dictionary]) -> Dictionary:
	created_this_pass = []
	var moved: Array[Dictionary] = []
	if not enabled:
		return {"created":created_this_pass,"moved":moved}
	# Existing objects update before the consumer creates any new object.
	for torch: Dictionary in torches:
		var animation: Dictionary = TIMING.sample_clock(torch["clock"],game_seconds,TIMING.X87Rounding.NEAREST_EVEN)
		torch["clock"] = animation
		torch["frame"] = int(animation["frame_index"])
		var before: Vector3 = torch["position"]
		var sample_xy: Vector2i = Vector2i(FIX._round(FIX._f32(before.x*8.0),&"nearest_even"),
			FIX._round(FIX._f32(before.y*8.0),&"nearest_even"))
		var snap_result: Dictionary = PLACEMENT.snap_step(before,Vector3.ZERO,int(torch["flags"]),tick,
			int(torch["id"]),sample_xy,Vector4i(sample_bounds.position.x,sample_bounds.position.y,
			sample_bounds.end.x,sample_bounds.end.y),read_depth)
		torch["position"] = snap_result["position"]
		var position: Vector3 = torch["position"]
		var rect: Vector4i = PLACEMENT.animation_rect(Vector2(position.x,position.y),frame_bounds[int(torch["frame"])])
		var release: Dictionary = PLACEMENT.release_step(position.z,int(torch["flags"]),0,rect,
			Vector4i(world_bounds.position.x,world_bounds.position.y,world_bounds.end.x,world_bounds.end.y),read_material)
		torch["flags"] = release["flags"]
		if position != before:
			_update_registered_light(torch)
			moved.append(torch)
	for actor: Dictionary in actors:
		if not AUTO.scheduled(tick,int(actor["id"]),bool(actor.get("autolight",false))):
			continue
		var y_draw: Dictionary = AUTO.rand15(rng_state)
		var x_draw: Dictionary = AUTO.rand15(int(y_draw["state"]))
		rng_state = int(x_draw["state"])
		var actor_position: Vector3 = actor["position"]
		var candidate: Dictionary = AUTO.candidate(Vector2(actor_position.x,actor_position.y),
			int(y_draw["value"]),int(x_draw["value"]),sample_bounds,read_depth,&"nearest_even")
		if candidate["status"] == "candidate":
			AUTO.enqueue(queue,candidate["position"])
	AUTO.advance(queue,true,_attempt_create)
	# Source object manager call precedes tick catch-up; no assumed 10Hz consumer.
	game_seconds += maxf(0.0,delta_game_seconds)
	remainder += maxf(0.0,delta_game_seconds)
	var catchup: int = 0
	while remainder + 1e-10 >= TIMING.SIMULATION_STEP_GAME_SECONDS and catchup < 10:
		remainder -= TIMING.SIMULATION_STEP_GAME_SECONDS
		tick += 1
		catchup += 1
	return {"created":created_this_pass,"moved":moved}


func _attempt_create(position: Vector3) -> String:
	var sample_xy: Vector2i = Vector2i(FIX._round(FIX._f32(position.x*8.0),&"nearest_even"),
		FIX._round(FIX._f32(position.y*8.0),&"nearest_even"))
	if not sample_bounds.grow(-1).has_point(sample_xy):
		last_decision = {"status":"outside_sample_margin"}
		return str(last_decision["status"])
	last_decision = POLICY.evaluate(position,world_bounds,minimum_y,read_material,region_records,light_records)
	if last_decision["status"] != "allowed":
		return str(last_decision["status"])
	var torch: Dictionary = {"id":next_id,"position":position,"flags":PLACEMENT.SNAP,
		"frame":0,"clock":TIMING.new_clock(frame_bounds.size(),game_seconds,frame_playback_mode),
		"light_index":light_records.size()}
	next_id += 1
	torches.append(torch)
	var offset: Array = properties["light_offset"]
	light_records.append({"position":position+Vector3(offset[0],offset[1],offset[2]),
		"range":float(properties["light_range"])})
	created_this_pass.append(torch)
	return "created"


func _update_registered_light(torch: Dictionary) -> void:
	var offset: Array = properties["light_offset"]
	light_records[int(torch["light_index"])]["position"] = torch["position"]+Vector3(offset[0],offset[1],offset[2])
