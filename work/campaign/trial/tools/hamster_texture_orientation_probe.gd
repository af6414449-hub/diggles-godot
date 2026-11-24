extends SceneTree
## Diagnostic: is the vertical orientation of the hamster texture in Godot the
## same as the orientation PIL (and the browser PNG) uses?
##
## The hamster face is only correct when the UV v coordinate points at the same
## image row in both engines. The HTML stand proved that the correct mapping is
## "v = 0 is the visual top row of the texture". This probe prints the pixels of
## a few rows of the TGA as Godot reads them, so the same rows can be compared
## with the PIL reading of the same file.
##
## Run: --headless --path godot --script res://tools/hamster_texture_orientation_probe.gd

const TGA := "res://textures/models/Character_Hamster_a_128.tga"
const COLUMNS: Array[int] = [4, 64, 120]
const ROWS: Array[int] = [0, 1, 2, 63, 64, 125, 126, 127]


func _initialize() -> void:
	var image: Image = Image.load_from_file(TGA)
	if image == null:
		print("PROBE_FAIL cannot read ", TGA)
		quit(1)
		return
	print("PROBE size=%s format=%s" % [str(image.get_size()), str(image.get_format())])
	for row: int in ROWS:
		var parts: Array[String] = []
		for column: int in COLUMNS:
			var color: Color = image.get_pixel(column, row)
			parts.append("x%d=%d,%d,%d" % [column, int(color.r * 255.0), int(color.g * 255.0), int(color.b * 255.0)])
		print("PROBE row=%d %s" % [row, " ".join(parts)])
	_report_imported()
	print("PROBE_DONE")
	quit(0)


## The hamster code loads the imported texture when the project has one. The
## importer must not flip the rows relative to the raw reader.
func _report_imported() -> void:
	if not ResourceLoader.exists(TGA):
		print("PROBE imported=missing")
		return
	var texture: Texture2D = load(TGA) as Texture2D
	if texture == null:
		print("PROBE imported=null")
		return
	var image: Image = texture.get_image()
	if image == null or image.is_empty():
		print("PROBE imported=image_unavailable")
		return
	print("PROBE imported size=%s format=%s" % [str(image.get_size()), str(image.get_format())])
	for row: int in ROWS:
		var parts: Array[String] = []
		for column: int in COLUMNS:
			var color: Color = image.get_pixel(column, row)
			parts.append("x%d=%d,%d,%d" % [column, int(color.r * 255.0), int(color.g * 255.0), int(color.b * 255.0)])
		print("PROBE imported_row=%d %s" % [row, " ".join(parts)])
