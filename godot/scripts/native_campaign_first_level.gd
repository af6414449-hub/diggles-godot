extends Node3D
## The first campaign chapter map of the original game.
##
## This scene is the campaign mode of Diggles, not the battle mode. The battle
## mode keeps its own map in scenes/multiplayer_test.tscn; the two maps have
## different sources and are never mixed:
##
##   battle mode   Templates/multi_urw_start_010_a_0.tcl  (128x128 reference)
##   campaign      Scripts/gameplay/Campaign.tcl           (512x640 chapter)
##
## The chapter is assembled at load time by the original from the campaign's
## own templates (urw_unq_start, the first_level caves, tunnels and voodoos).
## The assembly was exported by tools/export_campaign_chapter.py into
## res://models/native_campaign_chapter.json.
##
## Source of truth, read-only:
##   C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data

const PROFILE: Script = preload("res://scripts/native_campaign_profile.gd")
const MODEL_MATERIAL: Script = preload("res://scripts/native_model_material.gd")
const WALLS: Script = preload("res://scripts/native_campaign_walls.gd")
const GROUND: Script = preload("res://scripts/native_campaign_ground.gd")
const CAMERA: Script = preload("res://scripts/native_campaign_camera.gd")
const DIG_TEST: Script = preload("res://scripts/native_campaign_dig_test.gd")
const WORLD_MODEL_LIGHT: Script = preload("res://scripts/native_world_model_light.gd")
const BACKDROP: Script = preload("res://scripts/native_campaign_backdrop.gd")
const CHAPTER_PATH: String = "res://models/native_campaign_chapter.json"
const MODELS_PATH: String = "res://models/native_campaign_models.json"

const NATIVE_POINT_SCALE: float = 16384.0
const OBJECT_WORLD_SCALE: float = 0.005
const BDB_DEPTH_SCALE: float = 2.0
const BDB_DEPTH_OFFSET: float = -14.0
const RENDER_DEPTH_SCALE: float = 0.5
const RENDER_DEPTH_OFFSET: float = 7.0

## The ground of the overworld scene, in the world Z of the engine.
##
## The decoration of the overworld (the trees, the turf, the roots) belongs to
## the scene above the map, in a system of its own: it hangs under the rock of
## the chapter and the island closes it.
const OVERWORLD_GROUND_WORLD_Z: float = 2.0

## The limit between a wall and a slanted transition of the export.
##
## The normal of a triangle of the export leans over by this much from the
## vertical when the triangle is a transition between two levels of the height
## field and not a wall. The engine builds a vertical wall there (the fact of
## FUN_004ca080:264-298 in native_campaign_walls.gd), so the slanted triangle
## of the export is not drawn and the wall of the walls module takes its place.
const RAMP_NORMAL_Z: float = 0.25

## The classes of the layer of the overworld at the edge of the island.
##
## DEVIATION from the original: the engine closes these objects with the rock
## of the island (they stand below the world Z 7.0 in the cells of the chapter,
## З9), but they are what the frame of the owner shows behind the platform,
## and the port has no other source for the layer of the overworld - the
## chapter of the original loads no separate overworld scene.
const OVERWORLD_EDGE_CLASSES: Array[String] = [
	"Dummy_Obw_baum_a", "Dummy_Obw_baum_b", "Dummy_Obw_baum_d",
	"Dummy_Obw_rasen_y", "Dummy_Wiese_oval",
	"Dummy_Pilze_03_a", "Dummy_Pilze_04_a",
	"Dummy_Urw_bas_aaa", "Dummy_Swf_sta_u_l_big",
]

## The layer of the walls of the excavations. The light of the camera reaches
## this layer only, so the walls do not darken the ground of the map.
const WALL_LAYER: int = 2

var profile: NativeCampaignProfile = null
var native_model_material: RefCounted = null
var chapter: Dictionary = {}
## The cells of the chapter that are drawn on the map of the scene.
##
## Only Campaign.tcl:first_level and the start template exist on the initial
## map. Story templates are kept in the export for later generation, but must
## not be drawn before the story asks for the corresponding map area.
var start_cells: Array = []
## Flat filler cells of procedural templates outside the fixed start clearing.
## Their block 0 is the untouched map surface, not a separate cave surface.
var cave_padding: Dictionary = {}
var initial_templates: Dictionary = {}
var scene_root: Node3D = null
var camera: Camera3D = null
var scene_environment: Environment = null
## The backdrop of the chapter: the sky and the landscape of the original.
var backdrop: RefCounted = null
var clearing_edge: Variant = null
## The number of the native light sources of the chapter.
var source_light_count: int = 0
var headlight: DirectionalLight3D = null
var status: Label = null
var dig_test: RefCounted = null
var model_texture_cache: Dictionary = {}

var focus: Vector3 = Vector3.ZERO
var yaw: float = 0.0
## The native chapter view is a horizontal 2.5D camera. The framing follows the
## native set_view command (Campaign.tcl:10): the focus on the map, the zoom
## and the small tilt of rx.
var pitch: float = 0.0
var distance: float = 120.0
var controller: RefCounted = null

var _touch_points: Dictionary = {}
var _touch_span: float = 0.0
var _touch_centroid: Vector2 = Vector2.ZERO
var _mouse_dragging: bool = false
var _mouse_panning: bool = false

var triangle_count: int = 0
var surface_count: int = 0
var wall_count: int = 0
var ground_count: int = 0
var rock_body_count: int = 0
## The faces of the floor of the void around the island that were not drawn.
var omitted_backdrop_faces: int = 0
var object_count: int = 0
var dwarf_count: int = 0
var deleted_objects: int = 0
## The objects of the decoration of the overworld that the chapter does not
## draw.
var overworld_objects: int = 0
var _capture_path: String = ""
var _capture_frames: int = -1
## The area of the map a capture is aimed at: x0, y0, x1, y1 in cell units.
## Without it the whole content of the chapter is framed.
var _capture_region: Vector4 = Vector4.ZERO
## The tilt of the capture camera from the normal of the board, in radians. The
## native view command carries the tilt of the original, but a capture may use
## another one.
var _capture_tilt: float = -10.0
var _capture_yaw: float = NAN
## A capture that keeps the framing of the native set_view command: the focus
## and the zoom of the original, so the frame can be compared with it.
var _capture_native_view: bool = false
## A capture that frames the whole chapter instead of the native view. The
## default of a capture is the framing of the interactive scene, so a frame of a
## capture and the frame of the scene are the same.
var _capture_wide: bool = false
## The distance of the camera of a capture, in native units. Zero keeps the
## distance of the framing.
var _capture_distance: float = 0.0
## A debug switch: the vertical faces of the exported blocks are skipped, so the
## contribution of the excavation walls can be measured on a capture.
var _hide_vertical: bool = false
## A debug switch: the walls of the excavation are not built, so the same scene
## can be captured with and without them under the same light.
var _no_walls: bool = false
## A debug switch: the pixels of the capture that are probed with a ray of the
## camera, so the mesh that draws them can be named. An empty list means no probe.
var _probe_pixels: Array[Vector2] = []
## The detail texture of the ground of the map.
##
## The detail of the ground of the original is chosen by the four corner codes
## of the cell: the engine names the file "data/ground/detail/<zone>_<4 бита>.tga"
## (z24_10, the rule of FUN_004cd020). The map of the original outside the
## chapter is flat, so all four of its corner codes are zero and its detail is
## the file "<zone>_0000.tga" of the theme of the chapter - and that file is
## exactly 128,128,128, the same gray as the base atlas "50PGray.tga"
## (measured: urw_0000.tga = 128,128,128; 50PGray.tga = 128,128,128).
##
## A detail of the theme with the mask 1111 (urw2_1111.tga, the mean of
## 116,136,51 - a green one) belongs to the cells of the chapter with all
## four corners raised, not to the ground of the map: it turned the whole
## ground of the map green.
const GROUND_DETAIL: String = "50PGray.tga"

## The slanted transitions of the export are skipped: the engine builds a
## vertical wall between two levels of the height field and the walls module
## rebuilds that wall. The flag below brings the slanted triangles back for an
## A/B capture.
var _hide_ramps: bool = true
## The plan of the rock of the saved game: where the map has ground at all.
## The free ground of the map is drawn.
##
## The original draws the ground of the whole map: every cell of the map that
## carries no block of the chapter is a quad of ground at the level 14.5
## (FUN_004c8480:245-253; CScapeRenderer__RenderScape_004c4de0:559-576), so
## the map around the chapter is a surface and not a void. The flag below
## hides it for an A/B capture.
var _draw_free_ground: bool = true
## The body of the rock at the edge of the drawn terrain is drawn.
##
## The map of the original is a slab of rock: the ground of the map ends at the
## edge of the rock and the rock itself stands there as a rim between the
## ground and the background of the map. The frames of the owner show that rim:
## the grey mass of granite along the edge of the map, between the earth of the
## ground and the black behind it, and the mask of the owner draws the rim as
## the black zone outside the ground.
##
## The flag below hides the body for an A/B capture.
var _draw_rock_body: bool = true
## The backdrop of the chapter is not drawn: the frame keeps the void of the
## port, for an A/B capture of the backdrop.
var _no_backdrop: bool = false
var _show_debug_ui: bool = false


func _ready() -> void:
	var args: PackedStringArray = OS.get_cmdline_user_args()
	_show_debug_ui = args.has("--debug-ui")
	var capture_index: int = args.find("--capture-path")
	if capture_index >= 0 and capture_index + 1 < args.size():
		_capture_path = args[capture_index + 1]
		_capture_frames = 8
	var region_index: int = args.find("--capture-region")
	if region_index >= 0 and region_index + 1 < args.size():
		var parts: PackedStringArray = str(args[region_index + 1]).split(",")
		if parts.size() == 4:
			_capture_region = Vector4(float(parts[0]), float(parts[1]), float(parts[2]), float(parts[3]))
	var pitch_index: int = args.find("--capture-tilt")
	if pitch_index < 0:
		pitch_index = args.find("--capture-pitch")
	if pitch_index >= 0 and pitch_index + 1 < args.size():
		_capture_tilt = float(args[pitch_index + 1])
	var yaw_index: int = args.find("--capture-yaw")
	if yaw_index >= 0 and yaw_index + 1 < args.size():
		_capture_yaw = float(args[yaw_index + 1])
	_hide_vertical = args.has("--hide-vertical")
	_no_walls = args.has("--no-walls")
	var probe_index: int = args.find("--probe-pixel")
	if probe_index >= 0 and probe_index + 1 < args.size():
		for probe_point: String in str(args[probe_index + 1]).split(";"):
			var probe_parts: PackedStringArray = probe_point.split(",")
			if probe_parts.size() == 2:
				_probe_pixels.append(Vector2(float(probe_parts[0]), float(probe_parts[1])))
	_hide_ramps = not args.has("--show-ramps")
	_draw_free_ground = not args.has("--hide-free-ground")
	_draw_rock_body = not args.has("--hide-rock-body")
	_no_backdrop = args.has("--no-backdrop")
	_capture_native_view = args.has("--capture-native-view")
	_capture_wide = args.has("--capture-wide")
	var distance_index: int = args.find("--capture-distance")
	if distance_index >= 0 and distance_index + 1 < args.size():
		_capture_distance = float(args[distance_index + 1])
	native_model_material = MODEL_MATERIAL.new()
	if not native_model_material.call("load_fixture"):
		push_error("Original model normal table is missing")
		get_tree().quit(1)
		return
	profile = PROFILE.new()
	if not profile.call("load_chapter", CHAPTER_PATH):
		get_tree().quit(1)
		return
	profile.call("set_lit_excavation", not args.has("--dark-excavation"))
	chapter = profile.data
	clearing_edge = BACKDROP.clearing_edge(chapter.get("objects", []), GROUND.MAP_GROUND_LEVEL)
	for placement: Dictionary in chapter.get("placements", []):
		initial_templates[str(placement.get("template", ""))] = true
	for entry: Dictionary in chapter["cells"]:
		if not bool(entry.get("story", false)):
			start_cells.append(entry)
	_identify_cave_padding()
	profile.call("set_active_templates", initial_templates)
	# The flat filler still belongs to the template's material map. In the
	# original PMP, 306 of these cells are granite: excluding them from the
	# material profile erases the barrier surrounding the scripted caves.
	profile.call("set_active_cells", start_cells)
	# The native base map is built before this chapter's templates are placed.
	scene_root = Node3D.new()
	scene_root.name = "CampaignRenderSpace"
	scene_root.scale.z = RENDER_DEPTH_SCALE
	scene_root.position.z = RENDER_DEPTH_OFFSET
	add_child(scene_root)
	var started: int = Time.get_ticks_msec()
	_build_geometry()
	print("CAMPAIGN_BUILD_STAGE geometry ms=%d" % (Time.get_ticks_msec() - started))
	started = Time.get_ticks_msec()
	_build_objects()
	print("CAMPAIGN_BUILD_STAGE objects ms=%d" % (Time.get_ticks_msec() - started))
	started = Time.get_ticks_msec()
	_build_camera_and_light()
	_build_caption()
	var dig_caption := Label.new()
	dig_caption.set_anchors_preset(Control.PRESET_BOTTOM_LEFT)
	dig_caption.offset_left = 164.0
	dig_caption.offset_top = -72.0
	dig_caption.offset_right = 640.0
	dig_caption.offset_bottom = -48.0
	dig_caption.add_theme_color_override("font_color", Color.WHITE)
	dig_caption.add_theme_color_override("font_shadow_color", Color.BLACK)
	dig_caption.add_theme_constant_override("shadow_offset_x", 1)
	dig_caption.add_theme_constant_override("shadow_offset_y", 1)
	get_node("HUDLayer").add_child(dig_caption)
	dig_test = DIG_TEST.new()
	dig_test.setup(scene_root, camera, profile, start_cells, cave_padding,
		get_node("HUDLayer"), dig_caption)
	if args.has("--demo-dig") or args.has("--demo-mark") or args.has("--demo-join") \
			or args.has("--demo-cave-below") or args.has("--demo-upper"):
		var demo_stroke: RefCounted = preload("res://scripts/native_corridor_stroke.gd").new()
		if args.has("--demo-cave-below"):
			demo_stroke.begin(Vector2(253, 49), Rect2i(0, 0, 511, 639))
			demo_stroke.update(Vector2(274, 49))
		elif args.has("--demo-join"):
			# A new tunnel that starts inside the open shaft of the original
			# chapter: the cells x=245 and x=246 are open on the rows 45 and 46,
			# so the new passage branches off an existing tunnel.
			demo_stroke.begin(Vector2(243, 45), Rect2i(0, 0, 511, 639))
			demo_stroke.update(Vector2(266, 45))
		else:
			demo_stroke.begin(Vector2(274, 50), Rect2i(0, 0, 511, 639))
			demo_stroke.update(Vector2(282, 50))
		dig_test._mark_corridor(demo_stroke.finish())
		if args.has("--demo-dig") or args.has("--demo-join") or args.has("--demo-cave-below") \
				or args.has("--demo-upper"):
			dig_test.start_digging()
			for demo_step: int in range(240):
				if dig_test.queue.is_empty():
					break
				dig_test.advance(0.25)
		var support_report: Array = []
		for cell: Vector2i in dig_test.decorated:
			var support: Node3D = dig_test.decorated[cell]
			support_report.append("%s pos=%s meshes=%d" % [str(cell), str(support.position),
				support.get_child_count()])
		print("CAMPAIGN_DIG_SUPPORTS supports=%d excavated=%d detail=%s" % [
			dig_test.decorated.size(), dig_test.excavated_cells.size(),
			", ".join(PackedStringArray(support_report))])
	if args.has("--demo-upper"):
		# A second tunnel above the first one. The frames of wood of the lower
		# tunnel must not turn into a second row next to the ones above.
		var upper_stroke: RefCounted = preload("res://scripts/native_corridor_stroke.gd").new()
		upper_stroke.begin(Vector2(270, 47), Rect2i(0, 0, 511, 639))
		upper_stroke.update(Vector2(286, 47))
		dig_test._mark_corridor(upper_stroke.finish())
		dig_test.start_digging()
		for upper_step: int in range(240):
			if dig_test.queue.is_empty():
				break
			dig_test.advance(0.25)
		var upper_report: Array = []
		for cell: Vector2i in dig_test.decorated:
			upper_report.append(str(cell))
		print("CAMPAIGN_UPPER_SUPPORTS supports=%d excavated=%d cells=%s" % [
			dig_test.decorated.size(), dig_test.excavated_cells.size(),
			", ".join(PackedStringArray(upper_report))])
	if args.has("--demo-cave-above"):
		# A cave above the tunnel of the demo. The frame of wood of the tunnel
		# stands under an open space after that, so it must be taken away.
		dig_test._mark_cave(1, Vector2i(275, 49))
		print("CAMPAIGN_CAVE_ABOVE_MARKS count=%d reason=%s" % [dig_test.marked_count(), dig_caption.text])
		if dig_test.marked_count() > 0:
			dig_test.start_digging()
			for cave_step: int in range(360):
				if dig_test.queue.is_empty():
					break
				dig_test.advance(0.25)
		print("CAMPAIGN_CAVE_ABOVE_SUPPORTS supports=%d caves=%d frames=%d" % [
			dig_test.decorated.size(), dig_test.finished_caves.size(), dig_test.cave_frames.size()])
	if args.has("--demo-cave-below"):
		dig_test._mark_cave(1, Vector2i(268, 55))
		print("CAMPAIGN_CAVE_BELOW_MARKS count=%d reason=%s" % [dig_test.marked_count(), dig_caption.text])
		if dig_test.marked_count() > 0:
			dig_test.start_digging()
			for cave_step: int in range(360):
				if dig_test.queue.is_empty():
					break
				dig_test.advance(0.25)
		print("CAMPAIGN_CAVE_BELOW_FRAMES caves=%d frames=%d" % [
			dig_test.finished_caves.size(), dig_test.cave_frames.size()])
	print("CAMPAIGN_BUILD_STAGE camera ms=%d" % (Time.get_ticks_msec() - started))
	var summary: Dictionary = chapter.get("summary", {})
	print("CAMPAIGN_FIRST_LEVEL_READY seed=%d cells=%d templates=%d placements=%d story=%d objects=%d dwarfs=%d lights=%d deleted_wuker=%d overworld=%d surfaces=%d walls=%d ground=%d rock=%d backdrop_omitted=%d triangles=%d" % [
		int(chapter.get("seed", -1)), start_cells.size(), initial_templates.size(),
		int(summary.get("placements", 0)), int(summary.get("story_placements", 0)),
		object_count, dwarf_count, source_light_count, deleted_objects, overworld_objects,
		surface_count, wall_count, ground_count, rock_body_count, omitted_backdrop_faces, triangle_count])
	print("CAMPAIGN_CHAPTER_SOURCE %s seed=%d map=%dx%d view=%s" % [
		str(chapter.get("source", {}).get("procedure", "")), int(chapter.get("seed", -1)),
		int(chapter.get("map_size", {}).get("width", 0)), int(chapter.get("map_size", {}).get("height", 0)),
		str(chapter.get("initial_view", {}))])


## Block 0 is a flat surface at the map's ground level. The procedural cave
## templates carry it around their excavations as filler. Its MATERIAL still
## belongs to the template (including the granite barrier), but drawing its
## own separate mesh makes a rectangular footprint visible below and to the
## right of the opening. The free ground draws that material on the same plane.
## The fixed start clearing keeps its own block 0 surfaces and detail layer.
func _identify_cave_padding() -> void:
	cave_padding.clear()
	var start_bounds := Rect2i()
	for template: Dictionary in chapter.get("templates", []):
		if str(template.get("template", "")) != "urw_unq_start":
			continue
		var placements: Array = template.get("placements", [])
		if placements.is_empty():
			continue
		var placement: Dictionary = placements[0]
		start_bounds = Rect2i(int(placement["x"]), int(placement["y"]),
			int(template["width"]), int(template["height"]))
		break
	for entry: Dictionary in start_cells:
		if int(entry["block"]) != 0:
			continue
		var cell := Vector2i(int(entry["x"]), int(entry["y"]))
		if not start_bounds.has_point(cell):
			cave_padding[cell] = true


func _build_geometry() -> void:
	var tools: Dictionary = {}
	var materials: Dictionary = {}
	var meshes: Dictionary = chapter["meshes"]
	var normals: Array = chapter["normals"]
	# The void around the island: the cells that carry no block of the
	# chapter. The battle scene reads the same flag for its backdrop samples
	# (scripts/multiplayer_test.gd:1651-1654).
	var backdrop_samples: Dictionary = {}
	for entry: Dictionary in start_cells:
		if GROUND.is_backdrop(int(entry.get("flags", 0))):
			backdrop_samples[Vector2i(int(entry["x"]), int(entry["y"]))] = true
	for entry: Dictionary in start_cells:
		# Only the island of the chapter lies on the map at the start. The zone
		# of the story is placed by the story itself, later (sm_add_temp,
		# CampaignInit.tcl:685-692), so its cells are covered by the ground of
		# the map here like any other free cell: the free ground has no hole
		# over the zone, and the faces of the island end against it.
		var cell_origin: Vector2i = Vector2i(int(entry["x"]), int(entry["y"]))
		if cave_padding.has(cell_origin):
			continue
		var block_parts: Array = meshes[str(int(entry["block"]))]
		# A cell that touches the void around the island carries the floor of
		# the base map of the original. The battle scene omits the same face
		# (scripts/multiplayer_test.gd:1671-1707): the floor of the void is
		# hidden behind the island in the native view of the original, and the
		# board of the port looks at the map face on, so that floor would close
		# the view behind the island as a granite plane in the axes Y and X.
		var borders_backdrop: bool = false
		for corner_offset: Vector2i in [Vector2i.ZERO, Vector2i.RIGHT, Vector2i.DOWN, Vector2i.ONE]:
			if backdrop_samples.has(cell_origin + corner_offset):
				borders_backdrop = true
		# The variant of the ground texture is a region field of the whole map,
		# so the chapter and the free ground around it share one texture field.
		var variant_index: int = GROUND.base_variant(cell_origin)
		for part: Dictionary in block_parts:
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			var normal_indices: Array = part["attributes"]
			var part_number: int = int(part["part"])
			var detail: String = profile.call("detail_texture", cell_origin, part_number)
			var ground_file: String = profile.call("ground_file", cell_origin, variant_index)
			# The key of a surface is the part of the block and the texture of
			# the cell. The variant of the texture is already in the name of the
			# file, so it does not split the surfaces: fifteen surfaces for one
			# and the same texture is what made the scene heavy when the camera
			# went away.
			var key: String = "%d:%s" % [part_number, ground_file]
			if not tools.has(key):
				var new_surface: SurfaceTool = SurfaceTool.new()
				new_surface.begin(Mesh.PRIMITIVE_TRIANGLES)
				new_surface.set_custom_format(0, SurfaceTool.CUSTOM_RGBA_FLOAT)
				tools[key] = new_surface
				# The export carries the vertical faces of the blocks in one
				# direction only, so the rock of the chapter has holes where a
				# face is missing. The ground of the chapter is therefore drawn
				# from both sides: a hole then shows the rock behind it and not
				# the background of the scene.
				materials[key] = profile.call("terrain_material", variant_index, true, false,
					ground_file, false, "res://textures/ground/", true)
			var surface: SurfaceTool = tools[key] as SurfaceTool
			for triangle_start in range(0, indices.size(), 3):
				# The floor of the void around the island: the deepest flat face
				# of a cell that touches the void. It belongs to the base map of
				# the original and not to the rock of the chapter.
				var backdrop_face: bool = borders_backdrop
				for corner in range(3):
					var depth_value: float = float(values[int(indices[triangle_start + corner]) * 5 + 2])
					if not GROUND.is_void_floor(part_number, depth_value):
						backdrop_face = false
				if backdrop_face:
					omitted_backdrop_faces += 1
					continue
				var triangle_points: Array[Vector3] = []
				for corner in range(3):
					var offset: int = int(indices[triangle_start + corner]) * 5
					triangle_points.append(Vector3(float(values[offset]) + float(entry["x"]),
						-(float(values[offset + 1]) + float(entry["y"])),
						BDB_DEPTH_SCALE * float(values[offset + 2]) + BDB_DEPTH_OFFSET))
				var low_z: float = triangle_points[0].z
				var high_z: float = triangle_points[0].z
				for point: Vector3 in triangle_points:
					low_z = minf(low_z, point.z)
					high_z = maxf(high_z, point.z)
				var flat: bool = high_z - low_z <= 0.01
				if _hide_vertical and not flat:
					continue
				# The geometric normal of the triangle. A face that is not flat is
				# either a wall (the normal is horizontal) or a slanted
				# transition between two levels of the height field (the normal
				# leans over).
				var geometric: Vector3 = (triangle_points[1] - triangle_points[0]) \
					.cross(triangle_points[2] - triangle_points[0])
				var geometric_length: float = geometric.length()
				if not flat and geometric_length > 0.0 and _hide_ramps:
					# The engine has no slanted face of the terrain: between two
					# levels of the height field it builds a vertical wall
					# (native_campaign_walls.gd, the fact of FUN_004ca080:264-298).
					# The walls module rebuilds that wall from the height field,
					# so the slanted triangle of the export is left out here: in
					# the plan view of the port it stands up as a thin strip of
					# rock along the tunnels (the "stakes" of the captures).
					if absf(geometric.z / geometric_length) > RAMP_NORMAL_Z:
						continue
				# How much of the sky falls on this face: the sky of the CELL and
				# not the sky of the face. In the original the daylight is baked
				# into the attributes of the cell, and every face of the cell
				# carries it: the vertical face of the rock looks at the sky
				# with the smoothed normal of the block (the lines below) and
				# was getting none of it. The battle scene lights its terrain
				# the same way (multiplayer_test.gd:1736).
				#
				# The light of the face keeps the smoothed normal of the block:
				# the face of the excavation is BRIGHTER than the floor next to
				# it (the original: the rock in the section is 71.1 against the
				# floor 56.3), and a normal tilted into the pit takes the light
				# of the torches away from it (the port measured 44.76 against
				# the floor 54.34 that way).
				var sky: float = 1.0
				for corner in range(3):
					var vertex_index: int = int(indices[triangle_start + corner])
					var offset: int = vertex_index * 5
					var source_normal: Array = normals[int(normal_indices[vertex_index])]
					surface.set_normal(Vector3(float(source_normal[0]), -float(source_normal[1]),
						float(source_normal[2]) / BDB_DEPTH_SCALE).normalized())
					# The cells of the chapter keep the native UV of the export:
					# on the ground of a cell u and v are the local coordinates
					# of the cell, on a wall and on a slope v runs along the depth
					# (v = z - 7.0). The texture is the native tile of the cell
					# (tools/build_ground_field.py writes them out).
					surface.set_uv(Vector2(float(values[offset + 3]), float(values[offset + 4])))
					surface.set_uv2(profile.call("detail_slot", detail))
					var source_local: Vector3 = Vector3(values[offset], values[offset + 1], values[offset + 2])
					# The native light of the cell: the attribute bytes of the PMP
					# and the light sources of the chapter, the same way the battle
					# scene lights its terrain.
					var channels: Dictionary = profile.call("terrain_channels", cell_origin,
						source_local, source_normal, sky)
					surface.set_color(channels["diffuse"])
					surface.set_custom(0, channels["secondary"])
					surface.add_vertex(triangle_points[corner])
					triangle_count += 1
	for key: String in tools:
		var terrain_mesh: ArrayMesh = (tools[key] as SurfaceTool).commit()
		if terrain_mesh == null or terrain_mesh.get_surface_count() == 0:
			continue
		terrain_mesh.surface_set_material(0, materials[key] as Material)
		var instance: MeshInstance3D = MeshInstance3D.new()
		instance.name = "CampaignTerrain_" + key.replace(":", "_").replace(".tga", "")
		instance.mesh = terrain_mesh
		scene_root.add_child(instance)
		var body: StaticBody3D = StaticBody3D.new()
		body.name = "CampaignGroundCollision"
		body.collision_layer = 1
		body.collision_mask = 0
		instance.add_child(body)
		var collision: CollisionShape3D = CollisionShape3D.new()
		collision.shape = terrain_mesh.create_trimesh_shape()
		body.add_child(collision)
		surface_count += 1
	if not _no_walls:
		_build_walls()
	_build_ground()


## The excavation walls of the dug tunnels.
##
## The exported blocks carry the horizontal patches of the terrain and the
## vertical faces in one direction only, so the faces between two cells of a
## different height are missing and a tunnel reads as a flat sheet. The walls
## module rebuilds them from the height field of the chapter.
func _build_walls() -> void:
	# The level of the free ground of the map: the plane of the ground and the
	# faces against it end at the same level, so the two layers meet without a
	# gap (FUN_004cca20:41-109: the height of the vertices of the ground plane
	# is 0x41680000, that is 14.5).
	var ground_level: float = GROUND.MAP_GROUND_LEVEL
	var quads: Array = WALLS.relief_quads(start_cells, chapter["meshes"], ground_level)
	if quads.is_empty():
		return
	var map_size: Dictionary = chapter.get("map_size", {})
	var size := Vector2i(int(map_size.get("width", 0)), int(map_size.get("height", 0)))
	var cell_index: Dictionary = {}
	for entry: Dictionary in start_cells:
		cell_index[Vector2i(int(entry["x"]), int(entry["y"]))] = entry
	var tools: Dictionary = {}
	var materials: Dictionary = {}
	for wall: Dictionary in quads:
		var cell: Vector2i = wall["cell"]
		var side: int = int(wall["side"])
		# The face belongs to the higher side: the block above the face owns
		# it. The light and the texture of the face are the light and the
		# texture of that block.
		var owner_cell: Vector2i = cell
		var neighbour: Vector2i = WALLS.neighbour(cell, side)
		if cell_index.has(neighbour):
			var here_level: float = _cell_surface_level(cell_index[cell])
			var there_level: float = _cell_surface_level(cell_index[neighbour])
			if there_level > here_level:
				owner_cell = neighbour
		var entry: Dictionary = cell_index[owner_cell]
		var cell_origin := Vector2i(int(entry["x"]), int(entry["y"]))
		var variant_index: int = GROUND.base_variant(cell_origin)
		var ground_file: String = profile.call("ground_file", cell_origin, variant_index)
		var detail: String = profile.call("detail_texture", cell_origin, 0)
		var key: String = ground_file
		if not tools.has(key):
			var new_surface: SurfaceTool = SurfaceTool.new()
			new_surface.begin(Mesh.PRIMITIVE_TRIANGLES)
			new_surface.set_custom_format(0, SurfaceTool.CUSTOM_RGBA_FLOAT)
			tools[key] = new_surface
			materials[key] = profile.call("terrain_material", variant_index, false, false,
				ground_file, false, "res://textures/ground/", true)
		var surface: SurfaceTool = tools[key] as SurfaceTool
		var corners: Array = wall["corners"]
		var lower: float = float(wall["lower"])
		var normal: Vector3 = wall["normal"]
		var along_x: bool = side == WALLS.SIDE_POS_X or side == WALLS.SIDE_NEG_X
		for triangle_start in range(0, 6, 3):
			for corner_index in range(3):
				var corner_index_value: int = [0, 1, 2, 0, 2, 3][triangle_start + corner_index]
				var corner: Vector3 = corners[corner_index_value]
				var world_x: float = corner.x + float(cell.x)
				var world_y: float = corner.y + float(cell.y)
				var up: float = corner.z - lower
				surface.set_normal(normal)
				# The native UV of a wall: u runs along the face (the local
				# coordinate of the cell) and v runs along the depth
				# (v = z - 7.0), the same rule as the export carries on the
				# faces of the blocks.
				var along: float = corner.y if along_x else corner.x
				surface.set_uv(Vector2(along, corner.z - 7.0))
				surface.set_uv2(profile.call("detail_slot", detail))
				# The native light of the face. The light falls on the normal of
				# the face, and the faces of the export carry the smoothed
				# normal of the block: for a vertical face of a block that
				# normal leans up, so the face is lit like the horizontal ones.
				# The battle scene lights its terrain the same way
				# (multiplayer_test.gd:1736). The wall that the walls module
				# rebuilds has no smoothed normal, so it takes the up axis.
				#
				# The sky of a face is the sky of its CELL and not the sky of the
				# face: in the original the daylight is baked into the attributes
				# of the cell, and every face of the cell carries it. The port
				# measured the sky by the orientation of the face, so a vertical
				# face got none of it: every tunnel and every shaft carried a
				# dark band along it, and the wall of the surface of the map was
				# half as bright as the ground next to it.
				# The normal of the light of a wall: the smoothed normal of the
				# height field leans towards the inside of the pit, so the wall
				# catches the light of the torches of the corridor. The battle
				# scene takes the same normal from the export of the block
				# (multiplayer_test.gd:1736). The port took the up axis, and the
				# wall was 13 units darker than the floor next to it and colder
				# by 4-6 units of R-B: the light of the torches did not reach it.
				var source_local: Vector3 = Vector3(corner.x, corner.y, corner.z)
				var light_normal: Vector3 = (Vector3(0.0, 0.0, 1.0)
					+ Vector3(normal.x, normal.y, 0.0)).normalized()
				var channels: Dictionary = profile.call("terrain_channels", cell_origin, source_local,
					[light_normal.x, light_normal.y, light_normal.z], 1.0)
				surface.set_color(channels["diffuse"])
				surface.set_custom(0, channels["secondary"])
				surface.add_vertex(Vector3(corner.x + float(cell.x), -(corner.y + float(cell.y)),
					BDB_DEPTH_SCALE * corner.z + BDB_DEPTH_OFFSET))
	wall_count += quads.size()
	for key: String in tools:
		var wall_mesh: ArrayMesh = (tools[key] as SurfaceTool).commit()
		if wall_mesh == null or wall_mesh.get_surface_count() == 0:
			continue
		wall_mesh.surface_set_material(0, materials[key] as Material)
		var instance: MeshInstance3D = MeshInstance3D.new()
		instance.name = "CampaignWalls_" + key.replace(":", "_").replace(".tga", "")
		instance.mesh = wall_mesh
		instance.layers = WALL_LAYER
		scene_root.add_child(instance)
		if not _probe_pixels.is_empty():
			# The probe ray is a ray of the physics, so the walls need a shape.
			var probe_body := StaticBody3D.new()
			probe_body.name = "CampaignWallsProbe"
			var probe_shape := CollisionShape3D.new()
			probe_shape.shape = wall_mesh.create_trimesh_shape()
			probe_body.add_child(probe_shape)
			instance.add_child(probe_body)
		triangle_count += wall_mesh.get_faces().size() / 3


## The base layer of the map.
##
## The original creates the map with map create 512 640 and draws the ground
## over the whole map, so the rock is continuous and a tunnel is a hole in it.
## The export keeps only the cells of the placed templates, so the free cells
## of the map are rebuilt here: one quad per cell, so the texture keeps the
## native scale of one texture per cell and the ground is not a few long
## stripes of one stretched texture.
func _build_ground() -> void:
	var map_size: Dictionary = chapter.get("map_size", {})
	var size := Vector2i(int(map_size.get("width", 0)), int(map_size.get("height", 0)))
	if size.x <= 0 or size.y <= 0:
		return
	# The level of the flat ground of the map: the universal ground level of the
	# engine (FUN_004cca20:41-109: the height of the vertices of the ground
	# plane is 0x41680000, that is 14.5; the engine puts an object on the
	# ground and clamps the height of an object at the same level,
	# FUN_00568410, FUN_00420840). The plane is coplanar with the surface of
	# the chapter, and the faces of the excavations against the free ground
	# end at the same level (native_campaign_first_level.gd:_build_walls), so
	# the two layers meet without a gap.
	var level: float = GROUND.MAP_GROUND_LEVEL
	var chapter_cells: Dictionary = {}
	var cell_level: Dictionary = {}
	for entry: Dictionary in start_cells:
		var cell := Vector2i(int(entry["x"]), int(entry["y"]))
		cell_level[cell] = _cell_surface_level(entry)
	# Only the cells that lie on the map at the start of the chapter take the
	# ground of the chapter: the zone of the story is placed later, so over it
	# the ground of the map is drawn like over any other free cell. Without
	# this the free ground has a hole over the zone of the story and the
	# backdrop of the scene shows through it.
	for entry: Dictionary in start_cells:
		var cell := Vector2i(int(entry["x"]), int(entry["y"]))
		if not cave_padding.has(cell):
			chapter_cells[cell] = true
	var tools: Dictionary = {}
	var materials: Dictionary = {}
	# The ground of the map of the original is flat: the engine draws it with
	# "map create" and only changes the MATERIAL of a band of cells at the
	# edge of the map ("sm_draw_stone -border/-funnel"). The material comes
	# from those commands before any cave template is stamped onto the map.
	#
	# The engine draws the ground as one four-sided polygon per run of free
	# cells (FUN_004cca20:41-109) over the whole map: the free cells of the
	# map are everything that carries no block of the chapter, and behind the
	# edge of the map there is nothing at all
	# (CScapeRenderer__RenderScape_004c4de0:565-566,573-574). The brightness
	# is packed into the vertices of the polygon
	# (CTclGlobalMethods__SetBrightness_0063cce0:90-93), so the light of the
	# run is sampled at its corners.
	# The collision of the ground is built from the pieces of the free ground.
	var collision_faces: Array = []
	for row in range(size.y):
		var run_start: int = -1
		for column in range(size.x + 1):
			var is_free: bool = column < size.x and _plane_covers(column, row, chapter_cells, cell_level, level)
			if is_free and run_start < 0:
				run_start = column
				continue
			if is_free or run_start < 0:
				continue
			# The run of the free cells of the row ends at the column before.
			var run_end: int = column - 1
			var first_column: int = run_start
			run_start = -1
			if not _draw_free_ground:
				continue
			# The original draws the ground of the map as one polygon per run of
			# the free cells and writes ONE colour into its four vertices
			# (FUN_004cca20: the same uVar8 in all four vertices, and the only
			# writer of the three globals it is built from is
			# CTclGlobalMethods__SetBrightness_0063cce0:90-93). The tone of the
			# ground is therefore flat inside a run, and the step of the tone
			# lies on the border of the runs and not on the border of the cells.
			# The port takes one colour per run for the same reason.
			var run_color: Color = _ground_run_color(row, first_column, run_end, level)
			# The run is cut into pieces: a piece is a piece of the collision of
			# the ground and the place where the family of the ground may change.
			var segment_start: int = first_column
			while segment_start <= run_end:
				var segment_end: int = mini(segment_start + GROUND.LIGHT_SEGMENT_CELLS - 1, run_end)
				# The family of the ground follows the material of the cell, and
				# the material of every free cell comes from the native map
				# generator: the granite band follows sm_draw_stone -border and
				# -funnel, and the rest of the map is earth. A piece of the
				# ground therefore never crosses the border of two families.
				segment_end = _ground_family_end(segment_start, segment_end, row)
				_append_ground_segment(tools, materials, row, segment_start, segment_end, level, collision_faces, run_color)
				segment_start = segment_end + 1
	_commit_ground_surfaces(tools, materials, "CampaignGround_")
	_add_ground_collision(collision_faces)
	if _draw_rock_body:
		_build_rock_body(chapter_cells, level)


## The family of the ground of a free cell.
##
## The material of the cell decides the family: 0 and 3 are the rock, 1 and 2
## the two diggable kinds of soil and sand. The material of the free cells is
## the material of the original: the band of granite of the edge of the map and
## the walls of the funnel are the stone of the command sm_draw_stone of the
## original (scripts/native_campaign_map_material.gd), and the rest of the map
## is the earth of the generator of the original.
func _ground_family(cell: Vector2i) -> String:
	var value: Variant = profile.call("cell_material", cell)
	var material: int = 0 if value == null else int(value)
	if material == 3:
		material = 0
	if material == 1:
		return "B"
	if material == 2:
		return "C"
	return "A"


## The last column of a piece of the free ground that keeps one family.
func _ground_family_end(column: int, last_column: int, row: int) -> int:
	var family: String = _ground_family(Vector2i(column, row))
	var end: int = column
	while end < last_column:
		if _ground_family(Vector2i(end + 1, row)) != family:
			return end
		end += 1
	return last_column


## One piece of the free ground of the map.
##
## The original draws the ground of the map as one quad per cell with the local
## UV of the cell (0..1), so every cell of the map carries one of the fifteen
## native tiles of its family (the renderer takes the UV of the ground from the
## vertex table of the block, and on a flat cell they are the coordinates
## inside the cell).
##
## The port drew the ground of the map with the field of the family
## (tools/build_ground_field.py) instead. The field averages the fifteen tiles
## of the family into one canvas, so the ground of the map carried a third of
## the contrast of a native tile (the measured standard deviation of the field
## was 11.8 against 27 of Gnd_A01) and the granite of the barrier read as a
## flat grey against the sharp tiles of the chapter.
##
## The colour of a run of the free ground of the map.
##
## The original draws the ground of the map as one polygon per run of the free
## cells and writes ONE colour into its four vertices (FUN_004cca20: the same
## uVar8 in all four vertices, and the only writer of the three globals it is
## built from is CTclGlobalMethods__SetBrightness_0063cce0:90-93). The tone of
## the ground is therefore flat inside a run, and the step of the tone lies on
## the border of the runs and not on the border of the cells.
##
## The light of the run is the light of the surface of the map: the sky and
## nothing else, so it is the same for every run of the map
## (native_campaign_profile.gd:free_ground_channels). The light of the torches
## of the chapter falls on the cells of the chapter, not on the surface of the
## map, and the red streaks it drew over the map are gone.
##
func _ground_run_color(row: int, first_column: int, _run_end: int, level: float) -> Color:
	var channels: Dictionary = profile.call("free_ground_channels",
		Vector2i(first_column, row), Vector2(0.5, 0.5), level)
	var light: Color = channels["diffuse"]
	# The native tiles carry local variation. A tint selected from the first
	# cell of each row made horizontal seams on top of them.
	return light


## One piece of the free ground of the map.
##
## The colour of the piece is the colour of its run: the tone of the ground of
## the original is flat inside a run, and the pieces of a run carry the same
## colour.
func _append_ground_segment(tools: Dictionary, materials: Dictionary, row: int,
		first_column: int, last_column: int, level: float, collision: Array,
		run_color: Color) -> void:
	# The collision of the ground is the piece and not the cell: the picture of
	# the ground is a quad per cell, the collision stays a quad per piece.
	var piece: Array[Vector3] = [
		Vector3(float(first_column), 0.0, level), Vector3(float(last_column + 1), 0.0, level),
		Vector3(float(last_column + 1), 1.0, level), Vector3(float(first_column), 1.0, level)]
	for triangle_start in range(0, 6, 3):
		for corner_index in range(3):
			var corner_index_value: int = [0, 1, 2, 0, 2, 3][triangle_start + corner_index]
			var piece_corner: Vector3 = piece[corner_index_value]
			collision.append(Vector3(piece_corner.x,
				-float(row) - piece_corner.y, BDB_DEPTH_SCALE * level + BDB_DEPTH_OFFSET))
	# The detail of the ground of the map: the detail of the theme of the
	# ground, chosen by the four corner codes of the cell (the original names
	# the file "data/ground/detail/<zone>_<4 бита>.tga", z24_10). The ground
	# of the map outside the chapter is flat, so all four of its corner codes
	# are zero and its detail is the file "<zone>_0000.tga" of the theme of the
	# chapter - and that file is exactly 128,128,128, the same gray as the
	# base atlas 50PGray.tga (measured).
	var detail_slot: Vector2 = profile.call("detail_slot", GROUND_DETAIL)
	for column in range(first_column, last_column + 1):
		var cell := Vector2i(column, row)
		# The tile of the cell is chosen by the materials of its FOUR corners,
		# the rule of the original (FUN_004c4ae0: the index is built from the
		# four corner codes). The port took the tile of the cell's own family,
		# and six of the forty five native tiles have a dark edge on one side:
		# the dark edge then landed on the same side of every cell, and along
		# the rim of the excavations (a border of the materials) the cells stood
		# into one long continuous line. The original has no such line: the
		# frame of the owner shows the rock at the edge of an opened tunnel as
		# a continuous surface.
		var variant_index: int = GROUND.base_variant(cell)
		var ground_file: String = profile.call("ground_file", cell, variant_index)
		var key: String = ground_file
		if not tools.has(key):
			tools[key] = [[], [], [], [], []]
			materials[key] = profile.call("terrain_material", variant_index, false, false,
				ground_file, false, "res://textures/ground/", true)
		var surface: Array = tools[key]
		# The colour of the cell is the colour of the run: the original writes
		# one colour into the four vertices of the polygon of a run, so the tone
		# of the ground is flat inside a run.
		# The corners of the cell: the bottom left, the bottom right, the top
		# right and the top left. The UV of a cell are the local coordinates of
		# the cell, so the tile of the cell covers the cell and no more.
		var corners: Array[Vector3] = [
			Vector3(float(column), 0.0, level), Vector3(float(column + 1), 0.0, level),
			Vector3(float(column + 1), 1.0, level), Vector3(float(column), 1.0, level)]
		var cell_uvs: Array[Vector2] = [
			Vector2(0.0, 0.0), Vector2(1.0, 0.0), Vector2(1.0, 1.0), Vector2(0.0, 1.0)]
		for triangle_start in range(0, 6, 3):
			for corner_index in range(3):
				var corner_index_value: int = [0, 1, 2, 0, 2, 3][triangle_start + corner_index]
				var corner: Vector3 = corners[corner_index_value]
				surface[0].append(Vector3(corner.x,
					-float(row) - corner.y, BDB_DEPTH_SCALE * level + BDB_DEPTH_OFFSET))
				surface[1].append(Vector3(0.0, 0.0, 1.0))
				surface[2].append(cell_uvs[corner_index_value])
				surface[4].append(detail_slot)
				surface[3].append(run_color)
		ground_count += 1


## The surface level of a cell of the chapter: the highest point of its block.
func _cell_surface_level(entry: Dictionary) -> float:
	var highest: float = -INF
	for part: Dictionary in chapter["meshes"].get(str(int(entry["block"])), []):
		var values: Array = part["vertices"]
		for index in range(2, values.size(), 5):
			highest = maxf(highest, float(values[index]))
	return highest


## Whether the flat ground of the map covers a cell of the map.
##
## The free cells of the map are the cells that carry no block of the chapter.
## A free cell that lies right north of an excavation does not carry the ground
## either: the plane of the map would close the window into the excavation,
## because the board of the port is seen face on and a plane in front of the
## rock shifts over it by 0.286 cells per unit of height. In the original the
## same effect needs a free space of four to thirteen cells north of the
## excavation (the ray of the camera under 16.6 degrees), and the original
## shows the excavation through that window.
##
func _plane_covers(column: int, row: int, chapter_cells: Dictionary, cell_level: Dictionary,
		level: float) -> bool:
	if column < 0 or row < 0 or column >= GROUND.MAP_WIDTH or row >= GROUND.MAP_HEIGHT:
		return false
	if chapter_cells.has(Vector2i(column, row)):
		return false
	var below: Vector2i = Vector2i(column, row + 1)
	if not chapter_cells.has(below):
		return true
	var below_level: float = float(cell_level.get(below, level))
	return below_level > level - 2.0


## The collision of the base layer.
##
## The ground of the map is one flat body, so it gets one collision shape for
## all of its materials instead of one shape per material. The collision is
## built from the pieces of the free ground and not from the cells: the tiles
## of the cells are a picture and the collision does not need them.
func _add_ground_collision(faces: Array) -> void:
	if faces.is_empty():
		return
	var shape := ConcavePolygonShape3D.new()
	shape.set_faces(PackedVector3Array(faces))
	var body := StaticBody3D.new()
	body.name = "CampaignGroundCollision"
	body.collision_layer = 1
	body.collision_mask = 0
	var collision := CollisionShape3D.new()
	collision.shape = shape
	body.add_child(collision)
	scene_root.add_child(body)


## Commit the arrays of the base layer into meshes.
##
## The ground of the map is one quad per cell, so the arrays are large: they are
## written straight into the mesh instead of through the vertex by vertex
## interface of the surface builder.
func _commit_ground_surfaces(tools: Dictionary, materials: Dictionary, prefix: String) -> void:
	for key: String in tools:
		var surface: Array = tools[key]
		if surface[0].is_empty():
			continue
		var arrays: Array = []
		arrays.resize(Mesh.ARRAY_MAX)
		arrays[Mesh.ARRAY_VERTEX] = PackedVector3Array(surface[0])
		arrays[Mesh.ARRAY_NORMAL] = PackedVector3Array(surface[1])
		arrays[Mesh.ARRAY_TEX_UV] = PackedVector2Array(surface[2])
		arrays[Mesh.ARRAY_COLOR] = PackedColorArray(surface[3])
		if surface.size() > 4:
			arrays[Mesh.ARRAY_TEX_UV2] = PackedVector2Array(surface[4])
		var mesh := ArrayMesh.new()
		mesh.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES, arrays)
		mesh.surface_set_material(0, materials[key] as Material)
		var instance: MeshInstance3D = MeshInstance3D.new()
		instance.name = prefix + key.replace(":", "_").replace(".tga", "")
		instance.mesh = mesh
		scene_root.add_child(instance)
		triangle_count += surface[0].size() / 3


## The body of the rock at the edge of the terrain.
##
## The map of the original is a slab of rock: the blocks of the exported
## chapter reach down to the bottom of the rock, so the terrain has a body and
## not only a surface. The export does not keep the body of the free cells, so
## it is drawn here at the edge of the terrain: the rock ends and the
## background of the map is behind it.
func _build_rock_body(chapter_cells: Dictionary, level: float) -> void:
	var tools: Dictionary = {}
	var materials: Dictionary = {}
	var map_size: Dictionary = chapter.get("map_size", {})
	var size := Vector2i(int(map_size.get("width", 0)), int(map_size.get("height", 0)))
	for row in range(size.y):
		for column in range(size.x):
			var cell := Vector2i(column, row)
			if chapter_cells.has(cell):
				continue
			# The rim of the map is the granite of the border of the original
			# (the command sm_draw_stone -border walks the outer band of the
			# cells of the map and resets the material of a cell to stone), so
			# the body always carries the stone of the map and not the earth of
			# the cell it stands on. The face of the rock is drawn with a native
			# tile of the family A: the UV of a face are the local coordinates of
			# the cell along the face and the depth below it, so the tile of the
			# cell covers the cell and is not stretched over the whole rim.
			var ground_file: String = "Gnd_A01.tga"
			var key: String = ground_file
			if not tools.has(key):
				tools[key] = [[], [], [], []]
				materials[key] = profile.call("terrain_material", 0, false, false, ground_file)
			var surface: Array = tools[key]
			for side in range(4):
				var neighbour: Vector2i = WALLS.neighbour(cell, side)
				# The body of the rock ends at the edge of the map: beyond the map
				# there is nothing at all, and the rock of the map stands there as
				# a wall between the ground of the map and the background. This is
				# the barrier of the frames of the owner.
				if neighbour.y >= 0 and neighbour.y < size.y \
						and neighbour.x >= 0 and neighbour.x < size.x:
					continue
				var quad: Array[Vector3] = _rock_face(cell, side, level)
				var normal: Vector3 = _rock_normal(side)
				var facing: Vector3 = (quad[1] - quad[0]).cross(quad[2] - quad[0])
				if facing.dot(normal) < 0.0:
					quad = [quad[0], quad[3], quad[2], quad[1]]
				for triangle_start in range(0, 6, 3):
					for corner_index in range(3):
						var corner_index_value: int = [0, 1, 2, 0, 2, 3][triangle_start + corner_index]
						var corner: Vector3 = quad[corner_index_value]
						var along: float = corner.x if side == WALLS.SIDE_POS_X or side == WALLS.SIDE_NEG_X else corner.y
						surface[0].append(Vector3(float(column) + corner.x,
							-float(row) - corner.y,
							BDB_DEPTH_SCALE * corner.z + BDB_DEPTH_OFFSET))
						surface[1].append(normal)
						# The native UV of a vertical face: u runs along the face and
						# v runs along the depth (v = z - 7.0), the same rule the export
						# carries on the faces of the blocks. The texture of the field is
						# therefore not stretched over the height of the rim, and the rim
						# does not read as a bundle of bars.
						surface[2].append(Vector2(along, corner.z - 7.0))
						# The native light of the face of the rock. The faces of the export
						# carry the smoothed normal of the block, and for a vertical face
						# it leans up, so the face is lit like the horizontal ones; the
						# battle scene lights its terrain the same way
						# (multiplayer_test.gd:1736). With the geometric normal the rim
						# would be black.
						var light_normal: Vector3 = Vector3(0.0, 0.0, 1.0)
						# The rim of the map is the edge of the surface of the map, and the
						# surface of the map is a day surface: the rim is lit like the ground
						# that stands on it, and with the granite of the field.
						var channels: Dictionary = profile.call("free_ground_channels", cell,
							Vector2(corner.x, corner.y), level)
						var diffuse: Color = channels["diffuse"]
						surface[3].append(diffuse)
			rock_body_count += 1
	_commit_ground_surfaces(tools, materials, "CampaignRockBody_")


## The outward normal of one face of the rock body.
##
## The row direction of the map is mirrored in the scene, so the normal of the
## south side points to the south of the scene and not to the north.
func _rock_normal(side: int) -> Vector3:
	match side:
		WALLS.SIDE_POS_X:
			return Vector3(1.0, 0.0, 0.0)
		WALLS.SIDE_NEG_X:
			return Vector3(-1.0, 0.0, 0.0)
		WALLS.SIDE_POS_Y:
			return Vector3(0.0, -1.0, 0.0)
		_:
			return Vector3(0.0, 1.0, 0.0)


## The four corners of one face of the rock body, in the cell space.
func _rock_face(cell: Vector2i, side: int, level: float) -> Array[Vector3]:
	var top: float = level
	var bottom: float = GROUND.ROCK_BOTTOM
	match side:
		WALLS.SIDE_POS_X:
			return [Vector3(1.0, 0.0, top), Vector3(1.0, 1.0, top),
				Vector3(1.0, 1.0, bottom), Vector3(1.0, 0.0, bottom)]
		WALLS.SIDE_NEG_X:
			return [Vector3(0.0, 0.0, top), Vector3(0.0, 1.0, top),
				Vector3(0.0, 1.0, bottom), Vector3(0.0, 0.0, bottom)]
		WALLS.SIDE_POS_Y:
			return [Vector3(0.0, 1.0, top), Vector3(1.0, 1.0, top),
				Vector3(1.0, 1.0, bottom), Vector3(0.0, 1.0, bottom)]
		_:
			return [Vector3(0.0, 0.0, top), Vector3(1.0, 0.0, top),
				Vector3(1.0, 0.0, bottom), Vector3(0.0, 0.0, bottom)]


func _build_objects() -> void:
	if not FileAccess.file_exists(MODELS_PATH):
		push_warning("Campaign object models are missing: " + MODELS_PATH)
		return
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(MODELS_PATH))
	if not decoded is Dictionary:
		push_error("Campaign model manifest is missing or invalid")
		return
	var manifest: Dictionary = decoded
	var model_data: Dictionary = manifest.get("objects", {})
	var mesh_cache: Dictionary = {}
	for key: String in model_data:
		mesh_cache[key] = _build_model_meshes(model_data[key]["surfaces"])
	var deleted_class: String = str(chapter.get("deleted_class", "Wuker"))
	# The visibility of the decoration of the overworld (З9): the engine does
	# not cut the objects by their level, but every cell of the map carries
	# opaque geometry above the world Z 7.0 - the mesh of the block in a cell
	# of the chapter, the quad of the ground in a free cell - so an object
	# below that level is hidden by the rock where it stands and is visible
	# only in a free cell.
	var chapter_cells: Dictionary = {}
	for entry: Dictionary in start_cells:
		chapter_cells[Vector2i(int(entry["x"]), int(entry["y"]))] = true
	for placement: Dictionary in manifest.get("placements", []):
		if not initial_templates.has(str(placement.get("template", ""))):
			continue
		var placement_class: String = str(placement["class"])
		# The decoration of the overworld (the roots of the giant trees, the
		# swamp water, the rock walls of the overworld) belongs to the scene
		# above the map, in a system of its own: it hangs under the rock of the
		# chapter and the island closes it.
		var world_z: float = RENDER_DEPTH_SCALE * float(placement["z"]) + RENDER_DEPTH_OFFSET
		var placement_cell := Vector2i(int(floor(float(placement["x"]))),
			int(floor(float(placement["y"]))))
		var clearing_mountain: bool = not _no_backdrop and placement_class == "Dummy_Obw_berg_a" \
			and placement.get("template") == "urw_unq_start"
		var clearing_turf: bool = not _no_backdrop and placement.get("template") == "urw_unq_start" \
			and (placement_class.begins_with("Dummy_Obw_rasen_") \
				or placement_class.begins_with("Dummy_Multi_Obw_rasen_"))
		if world_z < 7.0 and chapter_cells.has(placement_cell) \
				and not OVERWORLD_EDGE_CLASSES.has(placement_class) \
				and not clearing_mountain and not clearing_turf:
			overworld_objects += 1
			continue
		# Campaign.tcl:198-203 deletes every object of this class after the
		# chapter is assembled.
		if placement_class == deleted_class:
			deleted_objects += 1
			continue
		var key: String = str(placement.get("model_package", "")).to_lower() \
			+ "::" + str(placement.get("model_object", "")).to_lower()
		if not mesh_cache.has(key):
			continue
		var instance_root: Node3D = Node3D.new()
		instance_root.name = "%s_%03d" % [placement_class, object_count]
		var game_to_godot: Basis = Basis(Vector3.RIGHT, Vector3.DOWN, Vector3.BACK)
		var rotation_data: Array = placement.get("rotation", [0.0, 0.0, 0.0])
		var source_rotation: Basis = Basis(Vector3.UP, -float(rotation_data[1])) \
			* Basis(Vector3.RIGHT, -float(rotation_data[0])) \
			* Basis(Vector3.BACK, -float(rotation_data[2]))
		var mapped_rotation: Basis = game_to_godot * source_rotation * game_to_godot.inverse()
		var render_to_logical: Basis = Basis(Vector3.RIGHT, Vector3.UP,
			Vector3(0.0, 0.0, 1.0 / RENDER_DEPTH_SCALE))
		# The height of a placement is the LEVEL of the cell of the template, and
		# the engine converts it to its world Z itself:
		#   world Z = 7.0 + 0.5 * level
		# (CDisplay__DrawObjects_00473cc0.c:429,435; FUN_00496300:46-50;
		# FUN_0052d170:613). The packing of the scene turns the local Z into the
		# world Z as 0.5 * local + 7.0, so the local Z of a placement is the
		# level of the template as it is. The blocks of the chapter carry the
		# world Z in their vertices instead, and that is why the two spaces
		# differ.
		instance_root.transform = Transform3D(render_to_logical * mapped_rotation,
			Vector3(float(placement["x"]), -float(placement["y"]),
				float(placement["z"])))
		instance_root.set_meta("native_class", placement_class)
		var in_daylight: bool = PROFILE.model_is_in_clearing(placement, clearing_edge)
		for mesh: ArrayMesh in mesh_cache[key]:
			var mesh_instance: MeshInstance3D = MeshInstance3D.new()
			mesh_instance.mesh = _lit_model_mesh(mesh, instance_root, mapped_rotation, in_daylight)
			instance_root.add_child(mesh_instance)
		scene_root.add_child(instance_root)
		object_count += 1
		if placement_class == "Zwerg":
			dwarf_count += 1


## The native light of a model of the chapter.
##
## The models of the original are lit by the world model path: the light map of
## the cell (the attribute bytes of the PMP) over the normal of the vertex,
## plus the native light sources of the chapter. The battle scene takes the
## same path (multiplayer_test.gd:1289-1399), so the boards, the mushrooms and
## the rest of the ground cover of the chapter are dark where the original is
## dark, and bright near a torch.
func _lit_model_mesh(mesh: ArrayMesh, instance_root: Node3D, rotation_basis: Basis,
		in_daylight: bool) -> ArrayMesh:
	var arrays: Array = mesh.surface_get_arrays(0)
	var points: PackedVector3Array = arrays[Mesh.ARRAY_VERTEX]
	var normals: PackedVector3Array = arrays[Mesh.ARRAY_NORMAL]
	var material: StandardMaterial3D = mesh.surface_get_material(0) as StandardMaterial3D
	if material == null or material.albedo_texture == null or points.is_empty() \
			or points.size() != normals.size():
		return mesh
	var colors := PackedColorArray()
	var secondary := PackedFloat32Array()
	var transform: Transform3D = instance_root.transform
	# A model that is drawn as a patch of texture (the turf, the meadow) takes
	# its normals from the radial table of the sphere of the original, and those
	# normals say nothing about the orientation of the patch: the sky of such a
	# model is the sky of the place it stands in, not the sky of its normals.
	var radial_count: int = 0
	for normal: Vector3 in normals:
		if profile.call("is_radial_normal", Vector3(normal.x, -normal.y, normal.z)):
			radial_count += 1
	var is_patch: bool = not normals.is_empty() and radial_count * 2 >= normals.size()
	for index in range(points.size()):
		var local: Vector3 = transform * points[index]
		# The source space of the blocks: the map lies in XY, the depth is Z.
		var source_point := Vector3(local.x, -local.y,
			local.z * RENDER_DEPTH_SCALE + RENDER_DEPTH_OFFSET)
		var godot_normal: Vector3 = rotation_basis * normals[index]
		var source_normal := Vector3(godot_normal.x, -godot_normal.y, godot_normal.z).normalized()
		var fields: Dictionary = profile.model_light_fields(source_point)
		if fields.is_empty():
			return mesh
		var color: Dictionary = WORLD_MODEL_LIGHT.channels(source_point, source_normal, fields,
			profile.lights_near(source_point), float(profile.world_model_lighting["gain"]["default"]))
		# The daylight of the surface: the turf, the moss, the meadow and the
		# trees of the original are models, and the models of the surface are
		# lit by the sky like the surface of the map itself. The gate is the
		# cell the model stands in: a model of an excavation stands in a cell
		# whose surface is below the surface of the map, and that one stays the
		# underground.
		var diffuse: Color = color["diffuse"]
		if in_daylight:
			var daylight_normal: Vector3 = Vector3.DOWN if is_patch else source_normal
			diffuse = PROFILE.clearing_model_diffuse(diffuse, daylight_normal)
		else:
			var model_cell: Vector2i = Vector2i(floori(source_point.x), floori(source_point.y))
			var cell_level: float = profile.cell_surface_level(model_cell)
			if absf(cell_level - GROUND.MAP_GROUND_LEVEL) < 0.0001:
				var sky: float = 1.0 if is_patch else clampf(source_normal.z, 0.0, 1.0)
				var gain: float = 1.0 + (profile.DAYLIGHT_GAIN - 1.0) * sky
				diffuse = Color(diffuse.r * gain, diffuse.g * gain, diffuse.b * gain)
		colors.append(diffuse)
		var spec: Color = color["secondary"]
		secondary.append_array(PackedFloat32Array([spec.r, spec.g, spec.b, 1.0]))
	arrays[Mesh.ARRAY_COLOR] = colors
	arrays[Mesh.ARRAY_CUSTOM0] = secondary
	var lit := ArrayMesh.new()
	lit.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES, arrays, [], {},
		Mesh.ARRAY_CUSTOM_RGBA_FLOAT << Mesh.ARRAY_FORMAT_CUSTOM0_SHIFT)
	lit.surface_set_material(0, _native_model_material(material))
	return lit


## The material of the world model path for a model of the chapter.
##
## The stage of the original: the texture of the model times the light of the
## vertex, then the secondary channel, then the gamma of the original.
func _native_model_material(source: StandardMaterial3D) -> Material:
	var native_material := ShaderMaterial.new()
	var blending: bool = source.transparency == BaseMaterial3D.TRANSPARENCY_ALPHA
	native_material.shader = load("res://shaders/native_world_model_blend.gdshader" if blending \
		else "res://shaders/native_world_model.gdshader") as Shader
	native_material.set_shader_parameter("albedo_texture", source.albedo_texture)
	native_material.set_shader_parameter("native_gamma",
		float(profile.shader_pipeline["defaults"]["gamma"]))
	native_material.set_shader_parameter("native_brightness",
		float(profile.shader_pipeline["defaults"]["brightness"]))
	native_material.set_shader_parameter("alpha_cutout", true)
	native_material.set_shader_parameter("alpha_threshold", 0.0 if blending else 0.35)
	return native_material


func _build_model_meshes(surfaces: Array, texture_directory: String = "res://textures/models") -> Array[ArrayMesh]:
	var meshes: Array[ArrayMesh] = []
	for source_surface: Dictionary in surfaces:
		var vertices: Array = source_surface["points"]
		var uvs: Array = source_surface["uvs"]
		var indices: Array = source_surface["triangles"]
		var source_normals: PackedVector3Array = native_model_material.call("godot_local_normals", source_surface)
		if vertices.is_empty() or uvs.is_empty() or indices.is_empty():
			continue
		var surface_tool: SurfaceTool = SurfaceTool.new()
		surface_tool.begin(Mesh.PRIMITIVE_TRIANGLES)
		for index_value: Variant in indices:
			var index: int = int(index_value)
			if index >= vertices.size() or index >= uvs.size():
				continue
			var raw_point: Array = vertices[index]
			var uv: Array = uvs[index]
			surface_tool.set_uv(Vector2(float(uv[0]), float(uv[1])))
			if not source_normals.is_empty():
				surface_tool.set_normal(source_normals[index])
			var native_point: Vector3 = Vector3(float(raw_point[0]) - 0.5,
				-(float(raw_point[1]) - 0.5), float(raw_point[2]) - 0.5) * NATIVE_POINT_SCALE
			surface_tool.add_vertex(native_point * OBJECT_WORLD_SCALE)
		if source_normals.is_empty():
			surface_tool.generate_normals()
		var mesh: ArrayMesh = surface_tool.commit()
		var material: StandardMaterial3D = StandardMaterial3D.new()
		material.cull_mode = BaseMaterial3D.CULL_DISABLED
		material.roughness = 0.95
		material.vertex_color_use_as_albedo = false
		var texture_name: String = str(source_surface["texture"])
		var texture_path: String = str(source_surface.get("texture_res_path", texture_directory + "/" + texture_name))
		if not ResourceLoader.exists(texture_path) and not FileAccess.file_exists(texture_path):
			texture_path = "res://assets/textures/" + texture_name
		if not model_texture_cache.has(texture_path):
			if ResourceLoader.exists(texture_path):
				model_texture_cache[texture_path] = load(texture_path) as Texture2D
			elif FileAccess.file_exists(texture_path):
				model_texture_cache[texture_path] = ImageTexture.create_from_image(Image.load_from_file(texture_path))
		if model_texture_cache.has(texture_path):
			material.albedo_texture = model_texture_cache[texture_path]
			var alpha_range: Array = source_surface.get("alpha_range", [255, 255])
			if int(alpha_range[0]) < 128:
				if texture_name.begins_with("FX_"):
					material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
				else:
					material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA_SCISSOR
					material.alpha_scissor_threshold = 0.35
		mesh.surface_set_material(0, material)
		meshes.append(mesh)
	return meshes


func _build_camera_and_light() -> void:
	var view: Dictionary = chapter.get("initial_view", {})
	controller = CAMERA.new()
	controller.call("setup", view)
	# The default of the capture tilt is below every legal tilt, so it keeps the
	# tilt of the native view. A capture of the native view keeps it as well.
	if _capture_tilt > -10.0 and not _capture_native_view:
		controller.call("set_tilt", _capture_tilt)
	# The native zoom is not documented, so the distance follows the box of the
	# exported chapter content.
	var box_min := Vector2(INF, INF)
	var box_max := Vector2(-INF, -INF)
	for entry: Dictionary in start_cells:
		var cell_position := Vector2(float(entry["x"]), float(entry["y"]))
		box_min = box_min.min(cell_position)
		box_max = box_max.max(cell_position)
	if box_min.x <= box_max.x and not _capture_native_view:
		var viewport := get_viewport().get_visible_rect().size
		var aspect: float = 1.0
		if viewport.y > 0.0:
			aspect = viewport.x / viewport.y
		var tilt: float = float(controller.call("get", "tilt"))
		var depth_span: float = _chapter_depth_span()
		if _capture_region.z > _capture_region.x:
			# A capture of one area of the map: frame that area instead of the
			# whole chapter.
			var region_min := Vector2(_capture_region.x, _capture_region.y)
			var region_max := Vector2(_capture_region.z, _capture_region.w)
			var region_size := region_max - region_min + Vector2.ONE
			controller.call("focus_on", (region_min + region_max) * 0.5)
			controller.call("frame", CAMERA.projected_size(region_size, depth_span, tilt), 0.05, aspect)
		elif not _capture_path.is_empty() and _capture_wide:
			# A capture of the whole chapter: the native zoom of the view, but
			# the focus on the middle of the chapter, so the whole level of the
			# zone is in the frame. The flag below keeps this framing; a capture
			# without it uses the framing of the interactive scene, so the frame
			# of a capture and the frame of the scene are the same.
			var content_size := box_max - box_min + Vector2.ONE
			controller.call("focus_on", (box_min + box_max) * 0.5)
			controller.call("frame", CAMERA.projected_size(content_size, depth_span, tilt), 0.45, aspect)
		else:
			# The interactive view opens at the scale of the native view: the
			# focus of the set_view command and the distance of the native
			# framing, so a cell of the map has the size it has in the frame
			# of the original (22-30 px there). The wide framing of the whole
			# chapter stays a deliberate shot of the capture, not the default
			# of the scene.
			pass
	if _capture_distance > 0.0:
		controller.call("set", "distance", _capture_distance)
	if is_finite(_capture_yaw):
		controller.call("set", "yaw", _capture_yaw)
	camera = Camera3D.new()
	camera.name = "ChapterCamera"
	camera.current = true
	camera.fov = float(CAMERA.FOV_DEGREES)
	camera.near = 0.05
	camera.far = 3000.0
	add_child(camera)
	# The exterior starts at the turf pieces along the back of the clearing.
	if not _no_backdrop and clearing_edge is Vector3:
		backdrop = BACKDROP.new()
		backdrop.call("build", clearing_edge, self)
	var environment: Environment = Environment.new()
	scene_environment = environment
	environment.background_mode = Environment.BG_COLOR
	environment.background_color = BACKDROP.SKY_COLOUR
	environment.ambient_light_source = Environment.AMBIENT_SOURCE_COLOR
	environment.ambient_light_color = Color.WHITE
	environment.ambient_light_energy = 0.3
	var world_environment: WorldEnvironment = WorldEnvironment.new()
	world_environment.environment = environment
	add_child(world_environment)
	# The light of the terrain of the chapter is the native light of the
	# original and it is baked into the vertex colour of the terrain, so the
	# terrain is unshaded (shaders/native_campaign_terrain.gdshader) and the
	# lights of the scene only light the models. The key light is the one of
	# the battle scene (multiplayer_test.gd:1845), the sources of the chapter
	# are the native ones (scripts/native_campaign_profile.gd:add_lights).
	var light: DirectionalLight3D = DirectionalLight3D.new()
	light.rotation_degrees = Vector3(-32.0, -25.0, 0.0)
	light.light_energy = 0.6
	light.shadow_enabled = false
	add_child(light)
	source_light_count = profile.call("add_lights", scene_root)
	_update_camera()


func _update_camera() -> void:
	if controller == null or camera == null:
		return
	camera.position = controller.call("camera_position") as Vector3
	# The board lies in the XY plane and its normal is the Z axis: the camera
	# stands on the normal and looks down at the map, the screen up is the row
	# direction of the map. The height of the rock comes towards the viewer.
	var target: Vector3 = controller.call("look_target") as Vector3
	camera.look_at(target)
	if backdrop != null:
		var view: Dictionary = chapter.get("initial_view", {})
		backdrop.call("update", target.x - float(view.get("x", 0.0)))


## The range of the heights of the chapter, in native units.
##
## The height of the rock is drawn nearly one to one, so the span of the
## heights is part of the size of the chapter on the screen.
func _chapter_depth_span() -> float:
	var low: float = INF
	var high: float = -INF
	var seen: Dictionary = {}
	for entry: Dictionary in start_cells:
		var block: String = str(int(entry["block"]))
		if seen.has(block):
			continue
		seen[block] = true
		for part: Dictionary in chapter["meshes"].get(block, []):
			var values: Array = part["vertices"]
			for offset in range(2, values.size(), 5):
				low = minf(low, float(values[offset]))
				high = maxf(high, float(values[offset]))
	if is_inf(low) or is_inf(high):
		return 0.0
	return high - low


## The camera controls of the chapter.
##
## One finger or the left mouse button turns the view, two fingers or the
## right mouse button move it, the wheel and the pinch zoom. The arrow keys
## move the map, Q and E turn it.
func _input(event: InputEvent) -> void:
	# HUD labels may consume motion before _unhandled_input. The native brush
	# outline still tracks the pointer over the map.
	if dig_test != null and event is InputEventMouseMotion:
		dig_test._update_hover(event.position)


func _unhandled_input(event: InputEvent) -> void:
	if dig_test != null and dig_test.handle_input(event):
		get_viewport().set_input_as_handled()
		return
	if controller == null:
		return
	if event is InputEventScreenTouch:
		var touch := event as InputEventScreenTouch
		if touch.pressed:
			_touch_points[touch.index] = touch.position
		else:
			_touch_points.erase(touch.index)
		_update_touch_reference()
		return
	if event is InputEventScreenDrag:
		var drag := event as InputEventScreenDrag
		_touch_points[drag.index] = drag.position
		if _touch_points.size() >= 2:
			var span := _current_touch_span()
			if _touch_span > 0.0 and span > 0.0:
				controller.call("zoom", span / _touch_span)
			var centroid := _current_touch_centroid()
			controller.call("pan", centroid - _touch_centroid)
			_touch_span = span
			_touch_centroid = centroid
		else:
			controller.call("rotate", drag.relative)
		_update_camera()
		return
	if event is InputEventMouseButton:
		var button := event as InputEventMouseButton
		if button.button_index == MOUSE_BUTTON_WHEEL_UP and button.pressed:
			controller.call("zoom", CAMERA.zoom_factor(1.0))
		elif button.button_index == MOUSE_BUTTON_WHEEL_DOWN and button.pressed:
			controller.call("zoom", CAMERA.zoom_factor(-1.0))
		elif button.button_index == MOUSE_BUTTON_LEFT or button.button_index == MOUSE_BUTTON_RIGHT:
			_mouse_dragging = button.pressed
			_mouse_panning = button.button_index == MOUSE_BUTTON_RIGHT
		_update_camera()
		return
	if event is InputEventMouseMotion:
		var motion := event as InputEventMouseMotion
		if not _mouse_dragging:
			return
		if _mouse_panning:
			controller.call("pan", motion.relative)
		else:
			controller.call("rotate", motion.relative)
		_update_camera()
		return
	if event is InputEventKey and event.is_pressed() and not event.is_echo():
		_handle_key(event as InputEventKey)


func _handle_key(key_event: InputEventKey) -> void:
	var step: float = 24.0
	match key_event.keycode:
		KEY_Q:
			controller.call("rotate", Vector2(-step, 0.0))
		KEY_E:
			controller.call("rotate", Vector2(step, 0.0))
		KEY_EQUAL, KEY_KP_ADD:
			controller.call("zoom", CAMERA.zoom_factor(1.0))
		KEY_MINUS, KEY_KP_SUBTRACT:
			controller.call("zoom", CAMERA.zoom_factor(-1.0))
		_:
			return
	_update_camera()


## The smooth camera movement of the arrow keys and WASD.
##
## The battle scene reads the move actions every frame
## (multiplayer_test.gd:1989), so the map follows the key while it is held.
## The chapter board is a different model: the map lies in the XY plane and
## the keys move the focus along the screen axes of the camera, so the keys are
## not inverted and the movement is not a step per press.
func _update_keyboard_pan(delta: float) -> void:
	if controller == null:
		return
	var direction: Vector2 = Input.get_vector("move_left", "move_right", "move_up", "move_down")
	if direction == Vector2.ZERO:
		return
	controller.call("pan_by", direction, delta)
	_update_camera()


func _current_touch_span() -> float:
	if _touch_points.size() < 2:
		return 0.0
	var keys: Array = _touch_points.keys()
	var first: Vector2 = _touch_points[keys[0]]
	var second: Vector2 = _touch_points[keys[1]]
	return first.distance_to(second)


func _current_touch_centroid() -> Vector2:
	var sum := Vector2.ZERO
	for value: Variant in _touch_points.values():
		sum += value as Vector2
	return sum / float(maxi(_touch_points.size(), 1))


func _update_touch_reference() -> void:
	_touch_span = _current_touch_span()
	_touch_centroid = _current_touch_centroid()


func _process(delta: float) -> void:
	if dig_test != null:
		dig_test.advance(delta)
	_update_keyboard_pan(delta)
	if _capture_frames < 0:
		return
	_capture_frames -= 1
	if _capture_frames > 0:
		return
	_capture_frames = -1
	_probe_camera_ray()
	var image: Image = get_viewport().get_texture().get_image()
	var error: int = image.save_png(_capture_path)
	print("CAMPAIGN_CAPTURE_READY path=%s error=%d size=%s" % [_capture_path, error, str(image.get_size())])
	get_tree().quit(0 if error == OK else 1)


## The mesh that draws one pixel of the capture: the ray of the camera is
## tested against every mesh of the scene, so the name of the mesh and the point
## of the hit say what is drawn in that pixel.
func _probe_camera_ray() -> void:
	if _probe_pixels.is_empty() or camera == null:
		return
	var space: PhysicsDirectSpaceState3D = get_world_3d().direct_space_state
	for probe_pixel: Vector2 in _probe_pixels:
		var origin: Vector3 = camera.project_ray_origin(probe_pixel)
		var direction: Vector3 = camera.project_ray_normal(probe_pixel)
		var query := PhysicsRayQueryParameters3D.create(origin, origin + direction * 4000.0)
		query.collide_with_areas = false
		query.collide_with_bodies = true
		var result: Dictionary = space.intersect_ray(query)
		if result.is_empty():
			print("CAMPAIGN_PROBE pixel=%s MISS" % str(probe_pixel))
			continue
		var collider: Object = result.get("collider") as Object
		var point: Vector3 = result.get("position", Vector3.ZERO)
		var normal: Vector3 = result.get("normal", Vector3.ZERO)
		var owner_path: String = ""
		if collider is Node:
			var collider_node: Node = collider as Node
			owner_path = String(collider_node.name)
			var parent: Node = collider_node.get_parent()
			if parent != null:
				owner_path = String(parent.name) + "/" + owner_path
		print("CAMPAIGN_PROBE pixel=%s collider=%s point=%s normal=%s" % [
			str(probe_pixel), owner_path, str(point), str(normal)])


func _build_caption() -> void:
	var layer: CanvasLayer = CanvasLayer.new()
	layer.name = "HUDLayer"
	add_child(layer)
	status = Label.new()
	status.name = "Status"
	status.position = Vector2(18.0, 14.0)
	var state: Dictionary = chapter.get("generator_state", {})
	status.text = "Diggles campaign chapter 1 - Urwald\nseed %d | map %dx%d | %s\n%d objects / %d dwarves | templates %d\nfirst_level: combination %d, connection %d, side %d\n1 finger / left mouse: turn | 2 fingers / right mouse: move | wheel: zoom | arrows / WASD: move" % [
		int(chapter.get("seed", -1)),
		int(chapter.get("map_size", {}).get("width", 0)),
		int(chapter.get("map_size", {}).get("height", 0)),
		str(chapter.get("source", {}).get("procedure", "")),
		object_count, dwarf_count, initial_templates.size(),
		int(state.get("combination_index", -1)), int(state.get("connection_index", -1)),
		int(state.get("present_side", -1))]
	status.visible = _show_debug_ui
	status.add_theme_color_override("font_color", Color.WHITE)
	status.add_theme_color_override("font_shadow_color", Color.BLACK)
	status.add_theme_constant_override("shadow_offset_x", 1)
	status.add_theme_constant_override("shadow_offset_y", 1)
	layer.add_child(status)
