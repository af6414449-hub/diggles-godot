extends SceneTree
## EXE-backed golden inputs plus lifecycle checks. Does not create scene lights.

const LIGHT: Script = preload("res://scripts/native_autolight.gd")
var checks: int = 0
var failures: int = 0
var depths: Dictionary = {}
var reads: Array[Vector2i] = []
var attempts: Array[Vector3] = []


func _initialize() -> void:
	call_deferred("_run")


func check(condition: bool, message: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		push_error("NATIVE_AUTOLIGHT_FAILED " + message)


func depth_at(point: Vector2i) -> Variant:
	reads.append(point)
	return depths.get(point)


func attempt(position: Vector3) -> String:
	attempts.append(position)
	return "deferred_source_policy"


func _run() -> void:
	var state: int = 1
	for expected: int in [41, 18467, 6334, 26500, 19169]:
		var draw: Dictionary = LIGHT.rand15(state)
		check(int(draw.value)==expected,"MSVC CRT sequence from state1")
		state = int(draw.state)
	check(not LIGHT.scheduled(9,2,true),"tick <=10 blocked")
	check(LIGHT.scheduled(13,3,true) and not LIGHT.scheduled(13,0,true),"tick13 ID remainder3")
	check(LIGHT.scheduled(17,4,true) and not LIGHT.scheduled(17,4,false),"outer gates required")
	check(not LIGHT.scheduled(18,4,true),"only tick remainder1")
	var bounds: Rect2i = Rect2i(0,0,160,160)
	var sample_xy: Vector2i = Vector2i(82,92)
	for offset: Vector2i in [Vector2i.ZERO,Vector2i.LEFT,Vector2i.RIGHT,Vector2i.UP,Vector2i.DOWN]:
		depths[sample_xy+offset] = 7
	depths[sample_xy+Vector2i.RIGHT] = 14
	depths[sample_xy+Vector2i.UP] = 255
	var result: Dictionary = LIGHT.candidate(Vector2(10.25,11.75),0,16384,bounds,depth_at,&"nearest_even")
	check(result.status=="candidate" and result.position==Vector3(10.25,11.550000190734863,14),"float32 XY; raw neighbor maximum, no Z /8")
	check(reads==[sample_xy,sample_xy+Vector2i.LEFT,sample_xy+Vector2i.RIGHT,sample_xy+Vector2i.UP,sample_xy+Vector2i.DOWN],"source sample order")
	depths[sample_xy] = 15
	reads.clear()
	result = LIGHT.candidate(Vector2(10.25,11.75),0,16384,bounds,depth_at,&"nearest_even")
	check(result.status=="solid" and reads.size()==1,"solid center stops neighbor reads")
	depths.erase(sample_xy)
	check(LIGHT.candidate(Vector2(10.25,11.75),0,16384,bounds,depth_at,&"nearest_even").status=="deferred","unknown terrain remains unknown")
	check(LIGHT.candidate(Vector2(10.25,11.75),0,16384,bounds,depth_at).status=="deferred","no invented x87 mode")
	check(LIGHT.candidate(Vector2(100,100),0,16384,bounds,depth_at,&"nearest_even").status=="outside_world","actual sample bounds")
	var queue: Array[Dictionary] = []
	var first: Vector3 = Vector3(10,10,7)
	check(LIGHT.enqueue(queue,first)==0,"new candidate")
	queue[0]["counter"] = 2
	check(LIGHT.enqueue(queue,Vector3(19,10,14))==0 and queue.size()==1,"dedup ignores Z")
	check(queue[0].counter==2 and queue[0].position==first,"duplicate neither resets counter nor changes position")
	check(LIGHT.enqueue(queue,Vector3(20,10,7))==1,"Manhattan10 is not duplicate")
	queue[0]["counter"] = 15
	LIGHT.enqueue(queue,first)
	check(queue[0].counter==10,"dedup counter upper cap10")
	queue.clear()
	LIGHT.enqueue(queue,first)
	LIGHT.enqueue(queue,Vector3(20,10,7))
	check(LIGHT.advance(queue,false,attempt).is_empty() and queue[0].counter==0,"consumer gates pause counters")
	for pass_index: int in range(1,7):
		var events: Array[Dictionary] = LIGHT.advance(queue,true,attempt)
		check(events.size()==(2 if pass_index==3 else 0),"attempt exactly at consumer pass3")
		if pass_index < 6:
			check(queue.size()==2,"records retained until pass6")
	check(attempts.size()==2 and queue.is_empty(),"failed attempts not retried; consecutive records purged together")
	print("NATIVE_AUTOLIGHT_SELF_TEST checks=%d failures=%d" % [checks,failures])
	quit(0 if failures==0 else 1)
