extends SceneTree
const POLICY: Script = preload("res://scripts/native_torch_policy.gd")
var checks: int = 0
var failures: int = 0
var material: Variant = 0


func _initialize() -> void:
	call_deferred("_run")


func _material(_point: Vector2i) -> Variant:
	return material


func check(condition: bool, message: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		push_error("TORCH_POLICY_FAILED " + message)


func query(position: Vector3 = Vector3(10,10,7), minimum_y: Variant = -10000,
		regions: Variant = [], lights: Array[Dictionary] = []) -> String:
	return POLICY.evaluate(position,Rect2i(0,0,100,100),minimum_y,_material,regions,lights).status


func _run() -> void:
	check(query()=="allowed","known unlit source state")
	check(query(Vector3(2,2,7))=="allowed","lower margin included")
	check(query(Vector3(98,10,7))=="outside_world","upper margin excluded")
	check(query(Vector3(1.99,10,7))=="outside_world","margin2")
	check(query(Vector3(10,10,7),11)=="below_y_cutoff","Y threshold is lower bound")
	check(query(Vector3(10,10,7),10)=="allowed","Y threshold equality allowed")
	check(query(Vector3(10,10,7),null)=="deferred","unknown Y state not fabricated")
	material = null
	check(query()=="deferred","unknown cell not empty")
	material = 3
	check(query(Vector3(10,10,7),-10000,null)=="deferred","material3 requires registry")
	check(query(Vector3(10,10,7),-10000,[{"position":Vector2(11,10),"radius":2.0}])=="region_excluded","source region radius")
	check(query(Vector3(10,10,7),-10000,[{"position":Vector2(12,10),"radius":2.0}])=="allowed","strict region boundary")
	check(query(Vector3(10,10,7),-10000,[{"position":Vector2(-1,10),"radius":100.0}])=="allowed","expired outside-world record ignored")
	material = 0
	check(query(Vector3(10,10,7),-10000,null)=="allowed","other materials skip region predicate")
	for depth: float in [0.0,100.0]:
		check(query(Vector3(10,10,7),-10000,[],[{"position":Vector3(12,10,depth),"range":3.0}])=="already_lit","existing light excludes regardless of Z")
	check(query(Vector3(10,10,7),-10000,[],[{"position":Vector3(13,10,7),"range":3.0}])=="allowed","strict light boundary, no invented radius+4 expansion")
	check(query(Vector3(10,10,7),-10000,[],[{"position":Vector3(10,10,7),"range":0.0}])=="allowed","inactive radius skipped")
	print("NATIVE_TORCH_POLICY_SELF_TEST checks=%d failures=%d" % [checks,failures])
	quit(0 if failures==0 else 1)
