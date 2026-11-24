#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Patch the campaign ground builder: one native tile per cell.

The original draws the ground of the map as one quad per cell with the local
UV of the cell (0..1), so every cell carries one of the fifteen native tiles
of its family.  The port drew the free ground with the blended field of the
family instead, which averaged the tiles into a flat grey.

The patch is applied by line ranges (the file is edited in place, the line
endings of the file are kept).
"""
import io
import os
import sys

TARGET = os.path.join(
    r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot", "scripts",
    "native_campaign_first_level.gd")

with io.open(TARGET, "r", encoding="utf-8", newline="") as handle:
    text = handle.read()
eol = "\r\n" if "\r\n" in text else "\n"
lines = text.split(eol)


def check(index, expected):
    actual = lines[index - 1]
    if expected not in actual:
        raise SystemExit("line %d does not match: %r" % (index, actual))


# ---------------------------------------------------------------- rock body
check(908, "var variant_index: int = (column * 7 + row * 11) % 15")
check(914, "field_ground_file")
check(918, "terrain_material")
rock_body = """\t\t\t# The rim of the map is the granite of the border of the original
\t\t\t# (the command sm_draw_stone -border walks the outer band of the
\t\t\t# cells of the map and resets the material of a cell to stone), so
\t\t\t# the body always carries the stone of the map and not the earth of
\t\t\t# the cell it stands on. The face of the rock is drawn with a native
\t\t\t# tile of the family A: the UV of a face are the local coordinates of
\t\t\t# the cell along the face and the depth below it, so the tile of the
\t\t\t# cell covers the cell and is not stretched over the whole rim.
\t\t\tvar ground_file: String = "Gnd_A01.tga"
\t\t\tvar key: String = ground_file
\t\t\tif not tools.has(key):
\t\t\t\ttools[key] = [[], [], [], []]
\t\t\t\tmaterials[key] = profile.call("terrain_material", 0, false, false, ground_file)""".split("\n")
lines[907:918] = rock_body

# ---------------------------------------------------------------- collision
check(838, "## The collision of the base layer.")
check(842, "func _add_ground_collision(tools: Dictionary) -> void:")
check(859, "scene_root.add_child(body)")
collision = """## The collision of the base layer.
##
## The ground of the map is one flat body, so it gets one collision shape for
## all of its materials instead of one shape per material. The collision is
## built from the pieces of the free ground and not from the cells: the tiles
## of the cells are a picture and the collision does not need them.
func _add_ground_collision(faces: Array) -> void:
\tif faces.is_empty():
\t\treturn
\tvar shape := ConcavePolygonShape3D.new()
\tshape.set_faces(PackedVector3Array(faces))
\tvar body := StaticBody3D.new()
\tbody.name = "CampaignGroundCollision"
\tbody.collision_layer = 1
\tbody.collision_mask = 0
\tvar collision := CollisionShape3D.new()
\tcollision.shape = shape
\tbody.add_child(collision)
\tscene_root.add_child(body)""".split("\n")
lines[837:859] = collision

# ------------------------------------------------------------ ground segment
check(704, "## One piece of the free ground of the map.")
check(792, "ground_count += 1")
segment = """## One piece of the free ground of the map.
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
## The light of the piece is the light of its four corners, the way the engine
## packs the light of its polygon into the vertices, and it is interpolated
## over the cells of the piece.
func _append_ground_segment(tools: Dictionary, materials: Dictionary, row: int,
\t\tfirst_column: int, last_column: int, level: float, collision: Array) -> void:
\t# The four corners of the piece. The native light of the free ground is the
\t# mean attribute of the chapter and the light sources of the chapter: the
\t# rock around the chapter is dark in the original and bright only near a
\t# torch, so the light has to be the native one.
\tvar corner_cells: Array[Vector2i] = [
\t\tVector2i(first_column, row), Vector2i(last_column + 1, row),
\t\tVector2i(last_column + 1, row + 1), Vector2i(first_column, row + 1)]
\tvar corner_colors: Array[Color] = []
\tfor corner_cell: Vector2i in corner_cells:
\t\tvar corner_channels: Dictionary = profile.call("free_ground_channels", corner_cell,
\t\t\tVector2(0.5, 0.5), level)
\t\t# The colour variation of the map is a tint of every cell, and the
\t\t# shader applies it by the cell of the ground, so the light of the
\t\t# corner carries no tint.
\t\tcorner_colors.append(corner_channels["diffuse"])
\t# The collision of the ground is the piece and not the cell: the picture of
\t# the ground is a quad per cell, the collision stays a quad per piece.
\tvar piece: Array[Vector3] = [
\t\tVector3(float(first_column), 0.0, level), Vector3(float(last_column + 1), 0.0, level),
\t\tVector3(float(last_column + 1), 1.0, level), Vector3(float(first_column), 1.0, level)]
\tfor triangle_start in range(0, 6, 3):
\t\tfor corner_index in range(3):
\t\t\tvar corner_index_value: int = [0, 1, 2, 0, 2, 3][triangle_start + corner_index]
\t\t\tvar piece_corner: Vector3 = piece[corner_index_value]
\t\t\tcollision.append(Vector3(piece_corner.x,
\t\t\t\t-float(row) - piece_corner.y, BDB_DEPTH_SCALE * level + BDB_DEPTH_OFFSET))
\t# The detail of the ground of the map: the detail of the theme of the
\t# ground, chosen by the four corner codes of the cell (the original names
\t# the file "data/ground/detail/<zone>_<4 бита>.tga", z24_10). The ground
\t# of the map outside the chapter is flat, so all four of its corner codes
\t# are zero and its detail is the file "<zone>_0000.tga" of the theme of the
\t# chapter - and that file is exactly 128,128,128, the same gray as the
\t# base atlas 50PGray.tga (measured).
\tvar detail_slot: Vector2 = profile.call("detail_slot", GROUND_DETAIL)
\tvar width: float = float(last_column - first_column + 1)
\tfor column in range(first_column, last_column + 1):
\t\tvar cell := Vector2i(column, row)
\t\t# The family of the cell decides the texture of the ground: the stone of
\t\t# the map (the stone band of the border of the original and the rock
\t\t# around the chapter) is the family A, the earth is the family C, the
\t\t# sand is the family B. The piece of the ground never crosses the
\t\t# border of two families (the segment is cut at that border).
\t\tvar family: String = _ground_family(cell)
\t\t# The native staging picks one of the fifteen tiles of the family per
\t\t# cell from the live random stream; the static port spreads the same
\t\t# fifteen tiles over the cells with a hash.
\t\tvar variant_index: int = GROUND.base_variant(cell)
\t\tvar ground_file: String = "Gnd_%s%02d.tga" % [family, variant_index + 1]
\t\tvar key: String = ground_file
\t\tif not tools.has(key):
\t\t\ttools[key] = [[], [], [], [], []]
\t\t\tmaterials[key] = profile.call("terrain_material", variant_index, false, false,
\t\t\t\tground_file, false, "res://textures/ground/", true, null)
\t\tvar surface: Array = tools[key]
\t\t# The light of the cell is the light of the piece, interpolated over
\t\t# the piece, so that the light is sampled in the place of the ground.
\t\tvar u0: float = float(column - first_column) / width
\t\tvar u1: float = float(column - first_column + 1) / width
\t\tvar cell_colors: Array[Color] = [
\t\t\tcorner_colors[0].lerp(corner_colors[1], u0),
\t\t\tcorner_colors[0].lerp(corner_colors[1], u1),
\t\t\tcorner_colors[3].lerp(corner_colors[2], u1),
\t\t\tcorner_colors[3].lerp(corner_colors[2], u0)]
\t\t# The colour variation of the original is generated over the whole map
\t\t# (Campaign.tcl:6 generate_color_variation), a tint of every cell. The
\t\t# tint is written into the colour of the cell: the shader multiplies the
\t\t# texture of the ground with the light of the vertex, so a tint in the
\t\t# colour is the same product as a tint in the texture.
\t\tvar tint: float = 0.9 + _variation_image.get_pixel(column, row).r * 0.2
\t\t# The corners of the cell: the bottom left, the bottom right, the top
\t\t# right and the top left. The UV of a cell are the local coordinates of
\t\t# the cell, so the tile of the cell covers the cell and no more.
\t\tvar corners: Array[Vector3] = [
\t\t\tVector3(float(column), 0.0, level), Vector3(float(column + 1), 0.0, level),
\t\t\tVector3(float(column + 1), 1.0, level), Vector3(float(column), 1.0, level)]
\t\tvar cell_uvs: Array[Vector2] = [
\t\t\tVector2(0.0, 0.0), Vector2(1.0, 0.0), Vector2(1.0, 1.0), Vector2(0.0, 1.0)]
\t\tfor triangle_start in range(0, 6, 3):
\t\t\tfor corner_index in range(3):
\t\t\t\tvar corner_index_value: int = [0, 1, 2, 0, 2, 3][triangle_start + corner_index]
\t\t\t\tvar corner: Vector3 = corners[corner_index_value]
\t\t\t\tsurface[0].append(Vector3(corner.x,
\t\t\t\t\t-float(row) - corner.y, BDB_DEPTH_SCALE * level + BDB_DEPTH_OFFSET))
\t\t\t\tsurface[1].append(Vector3(0.0, 0.0, 1.0))
\t\t\t\tsurface[2].append(cell_uvs[corner_index_value])
\t\t\t\tsurface[4].append(detail_slot)
\t\t\t\tsurface[3].append(cell_colors[corner_index_value] * tint)
\t\tground_count += 1""".split("\n")
lines[703:792] = segment

# ------------------------------------------------------------------- calls
check(617, "_append_ground_segment(tools, materials, row, segment_start, segment_end, level)")
lines[616] = "\t\t\t\t_append_ground_segment(tools, materials, row, segment_start, segment_end, level, collision_faces)"
check(620, "_add_ground_collision(tools)")
lines[619] = "\t_add_ground_collision(collision_faces)"
check(578, "\tfor row in range(size.y):")
lines[577:577] = [
    "\t# The collision of the ground is built from the pieces of the free ground.",
    "\tvar collision_faces: Array = []",
]

text = eol.join(lines)

# The tint of a cell is read out of the map of the variation, so that the tint
# of the cell is the tint of the shader (0.9 + stored * 0.2) and not a second
# formula.
anchor = "\t_variation_map = GROUND.build_variation_map()" + eol
if anchor not in text:
    raise SystemExit("variation map assignment not found")
text = text.replace(anchor, anchor + "\t_variation_image = _variation_map.get_image()" + eol, 1)

anchor = "var _variation_map: Texture2D = null" + eol
if anchor not in text:
    raise SystemExit("variation map declaration not found")
text = text.replace(anchor, anchor + "## The map of the variation as an image: the tint of a cell is read" + eol
                    + "## out of it when the cell is drawn." + eol
                    + "var _variation_image: Image = null" + eol, 1)

with io.open(TARGET, "w", encoding="utf-8", newline="") as handle:
    handle.write(text)
print("patched %s (%d lines, eol=%r)" % (TARGET, len(lines), eol))
