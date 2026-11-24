extends SceneTree
## --headless --path godot --script res://tools/native_flame_self_test.gd
## Optional -- --preview: standalone adapter demo, no main-scene integration.
const Flame = preload("res://scripts/native_flame_emitter.gd")
var _checks: int = 0
var _failures: Array[String] = []
var _demo: Node3D = null
var _accumulator: float = 0.0

func _initialize() -> void:
	call_deferred("_run")

func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures.append(message)
		printerr("FAIL: " + message)

func _run() -> void:
	var source: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_flame.json"))
	var flame = Flame.new()
	root.add_child(flame)
	# DEMO host mapping: native Y down -> Godot Y up. These are not native defaults.
	var mapping: Transform3D = Transform3D(Basis(Vector3(2, 0, 0), Vector3(0, -2, 0), Vector3(0, 0, 2)), Vector3.ZERO)
	_check(flame.configure(source, mapping, Vector2(0.07, 0.07), 1, 1.0) == OK, "valid source configures without import")
	_check(flame.update_native_tick(true, 1.0) == OK, "native update")
	var first: Dictionary = flame.snapshot()
	_check(int(first["live"]) == 1, "one birth, not 32 particles per tick")
	var p: Dictionary = first["particles"][0]
	_check(int(p["row"]) == 2 and int(p["column"]) == 7 and int(p["age"]) == 1, "seed 1 EXE LCG row and first age")
	_check(Vector3(p["point"]).distance_to(Vector3(-0.0503048911, -0.1013333333, 0.1358899985)) < 0.000001, "EXE seed 1 spawn and first contraction golden")
	flame.update_visual(Vector3.RIGHT, Vector3.UP)
	_check(int(flame.snapshot()["surfaces"]) == 1, "live particle submits triangles")
	var atlas_texture: Texture2D = load(str(source["atlas"]["resource"])) as Texture2D
	var image: Image = atlas_texture.get_image() if atlas_texture != null else null
	_check(image != null and not image.is_empty(),"imported fire atlas is available for pixel checks")
	if image == null:
		quit(1)
	var visible_texels: int = 0
	_check(source["atlas"]["grid"]==[16.0,16.0],"native type2 uses16-grid, not8 animation columns as atlas size")
	var warmth: float = 0.0
	for y: int in range(16,24):
		for x: int in range(56,64):
			var pixel: Color = image.get_pixel(x, y)
			warmth += pixel.r-pixel.b
			if pixel.a > 0.1 and maxf(pixel.r, pixel.g) > 0.1:
				visible_texels += 1
	_check(visible_texels > 8, "actual first source cell has visible fire texels")
	_check(warmth>0.0,"first fire cell is warm; adjacent rock/smoke palette is not sampled")
	var before: Dictionary = flame.snapshot()
	_check(flame.update_native_tick(false, -1.0) == ERR_INVALID_PARAMETER and flame.snapshot() == before, "bad step cannot mutate state")
	_check(flame.configure({}, mapping, Vector2.ONE) == ERR_INVALID_DATA and flame.snapshot() == before, "bad config preserves active emitter")
	# Original frame selection at ages 8, 16, 24, 31; no seconds or linear flipbook.
	var checkpoints: Dictionary = {8: 7, 16: 5, 24: 3, 31: 0}
	for tick: int in range(1, 32):
		flame.update_native_tick(false, 1.0)
		var state: Dictionary = flame.snapshot()
		if checkpoints.has(tick):
			if tick < 31:
				_check(int(state["particles"][0]["column"]) == int(checkpoints[tick]), "source quadratic frame at age " + str(tick))
			else:
				_check(int(state["live"]) == 0, "removed at 32 native updates")
	flame.update_visual(Vector3.RIGHT, Vector3.UP)
	_check(int(flame.snapshot()["surfaces"]) == 0, "drain clears geometry")
	flame.configure(source, mapping, Vector2(0.07, 0.07), 1)
	for tick: int in range(2000):
		flame.update_native_tick(true, 1.0)
	_check(int(flame.snapshot()["live"]) <= 31 and int(flame.snapshot()["live"]) > 0, "sustained bounded effect")
	var rows_seen: Dictionary = {}
	for particle: Dictionary in flame.snapshot()["particles"]:
		rows_seen[int(particle["row"])] = true
		_check(int(particle["column"]) >= 0 and int(particle["column"]) <= 7, "atlas cell within original grid")
	_check(rows_seen.size() == 3, "all original flame variants exercised")
	for tick: int in range(32):
		flame.update_native_tick(false, 1.0)
	_check(int(flame.snapshot()["live"]) == 0, "stop drains after bounded lifetime")
	flame.configure(source, mapping, Vector2(0.07, 0.07), 1)
	flame.update_native_tick(true, 1.0)
	_check(flame.snapshot()["particles"] == first["particles"], "reconfigure resets RNG and drift")
	flame.clear()
	_check(flame.get_child_count() == 0 and flame.update_native_tick(true, 1.0) == ERR_UNCONFIGURED, "clear releases draw node and invalidates simulation")
	print(JSON.stringify({"ok": _failures.is_empty(), "checks": _checks, "failures": _failures, "gpu_pixels_verified": false, "source_visible_texels": visible_texels}))
	if _failures.is_empty() and OS.get_cmdline_user_args().has("--preview"):
		flame.configure(source, mapping, Vector2(0.07, 0.07), 1)
		_demo = flame
		var camera: Camera3D = Camera3D.new()
		root.add_child(camera)
		camera.position = Vector3(0, 0.5, 3)
		camera.set_orthogonal(1.4, 0.05, 20)
		camera.current = true
		return
	flame.free()
	quit(0 if _failures.is_empty() else 1)

func _process(delta: float) -> bool:
	if _demo != null:
		# Demonstration cadence only: explicitly not a recovered native frequency.
		_accumulator += minf(delta, 0.25)
		while _accumulator >= 1.0 / 30.0:
			_accumulator -= 1.0 / 30.0
			_demo.update_native_tick(true, 1.0)
		_demo.update_visual(Vector3.RIGHT, Vector3.UP)
	return false
