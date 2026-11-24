extends SceneTree
const LIGHT: Script = preload("res://scripts/native_terrain_illumination.gd")
var failures: int = 0
var assertions: int = 0

func _initialize() -> void:
	call_deferred("_run")

func check(value: bool, message: String) -> void:
	assertions += 1
	if not value:
		failures += 1
		push_error("NATIVE_TERRAIN_RENDER_FAILED " + message)

func _run() -> void:
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	await process_frame
	subject.set_process(false)
	var profile: RefCounted = subject.source_profile
	var constants: Dictionary = profile.terrain_render["constants"]
	check(LIGHT.base_byte([4,4,4,4],Vector2.ZERO)==128,"constant source bytes")
	check(LIGHT.base_byte([0,4,8,0],Vector2(0.5,0.5))==112,"fixed-point bilinear bytes")
	var wall: Color = LIGHT.diffuse(Vector3.ZERO,Vector3.BACK,128,[],constants)
	var floor_color: Color = LIGHT.diffuse(Vector3.ZERO,Vector3.DOWN,128,[],constants)
	check(absf(wall.r-46.0/255.0)<0.000001,"native normal base and constructor gain")
	check(absf(floor_color.r-79.0/255.0)<0.000001,"source floor normal")
	var lamps: Array = [{"position":Vector3(0,0,1),"range":2.0,"color":Vector3(1,0,0)}]
	var lit: Color = LIGHT.diffuse(Vector3.ZERO,Vector3.BACK,128,lamps,constants)
	check(lit.r>wall.r and lit.g==wall.g and lit.b==wall.b,"colored local contribution")
	check(LIGHT.diffuse(Vector3.ZERO,Vector3.BACK,128,lamps,constants,0)==wall,"visibility gate")
	lamps[0]["position"] = Vector3(0,0,2)
	check(LIGHT.diffuse(Vector3.ZERO,Vector3.BACK,128,lamps,constants)==wall,"strict original light radius")
	var textures: Dictionary = {}
	var vertices: int = 0
	for mesh_node: MeshInstance3D in subject.terrain_mesh_nodes.values():
		var material: ShaderMaterial = mesh_node.mesh.surface_get_material(0)
		check(material.shader.code.contains("cull_back"),"ordinary mode retains visible terrain faces")
		var texture: Texture2D = material.get_shader_parameter("ground_texture")
		textures[texture.resource_path.get_file()] = true
		var arrays: Array = mesh_node.mesh.surface_get_arrays(0)
		var colors: PackedColorArray = arrays[Mesh.ARRAY_COLOR]
		var points: PackedVector3Array = arrays[Mesh.ARRAY_VERTEX]
		check(colors.size()==points.size(),"color on every terrain vertex")
		var custom: PackedFloat32Array = arrays[Mesh.ARRAY_CUSTOM0]
		check(custom.size()==points.size()*4,"secondary RGBA32F on every terrain vertex")
		vertices += points.size()
	check(vertices==5302*3,"original geometry and aperture retained")
	var has_a: bool = false
	var has_c: bool = false
	var has_mixed: bool = false
	for file: String in textures:
		has_a = has_a or file.begins_with("Gnd_A")
		has_c = has_c or file.begins_with("Gnd_C")
		has_mixed = has_mixed or file.begins_with("Native_")
		check(not file.begins_with("Gnd_B"),"no unsupported uniform B in this PMP")
	check(has_a and has_c and has_mixed,"source rock families and transitions")
	check(profile.use_native_diffuse,"recovered lighting enabled by default")
	profile.use_native_diffuse = true
	var candidate_material: ShaderMaterial = profile.terrain_material(0,false,false,"Gnd_C01.tga")
	check(candidate_material.shader.code.contains("unshaded") and candidate_material.shader.code.contains("COLOR.rgb"),"native diffuse shader independent of Godot lamps")
	print("NATIVE_TERRAIN_RENDER_SELF_TEST_%s assertions=%d vertices=%d textures=%d" % ["OK" if failures==0 else "FAILED",assertions,vertices,textures.size()])
	subject.queue_free()
	quit(0 if failures==0 else 1)
