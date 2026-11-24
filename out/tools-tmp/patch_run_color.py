#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The ground of the map gets one colour per run, the way the original does.

FUN_004cca20 writes the same colour into the four vertices of the polygon of a
run of the free cells, and the only writer of the three globals that colour is
built from is CTclGlobalMethods__SetBrightness (90-93).  The tone of the ground
is therefore flat inside a run, and the step of the tone lies on the border of
the runs and not on the border of the cells.
"""
import io
import os
import sys

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\scripts"
FIRST = os.path.join(ROOT, "native_campaign_first_level.gd")
GROUND = os.path.join(ROOT, "native_campaign_ground.gd")


def load(path):
    with io.open(path, "r", encoding="utf-8", newline="") as handle:
        text = handle.read()
    return text, ("\r\n" if "\r\n" in text else "\n")


def replace(text, old, new, eol, count=1):
    old = old.replace("\n", eol)
    new = new.replace("\n", eol)
    found = text.count(old)
    if found != count:
        raise SystemExit("expected %d matches, found %d for:\n%s" % (count, found, old[:120]))
    return text.replace(old, new, count)


text, eol = load(FIRST)

# 1. The run gets one colour.
text = replace(text, """\t\t\t# The engine draws the ground of the map as one polygon per run of
\t\t\t# the free cells and packs the light of the polygon into its
\t\t\t# vertices (FUN_004cca20, CTclGlobalMethods__SetBrightness_0063cce0:
\t\t\t# 90-93), so the light of a run is the light of its two ends. A run
\t\t\t# of hundreds of cells crosses the whole island: its two ends carry
\t\t\t# a very different light and the ground between them reads as one
\t\t\t# long dark bar ("channels" along the ground of the map). The run is
\t\t\t# therefore cut into pieces, so that the light is sampled in the
\t\t\t# place of the ground.
\t\t\tvar segment_start: int = first_column""", """\t\t\t# The original draws the ground of the map as one polygon per run of
\t\t\t# the free cells and writes ONE colour into its four vertices
\t\t\t# (FUN_004cca20: the same uVar8 in all four vertices, and the only
\t\t\t# writer of the three globals it is built from is
\t\t\t# CTclGlobalMethods__SetBrightness_0063cce0:90-93). The tone of the
\t\t\t# ground is therefore flat inside a run, and the step of the tone
\t\t\t# lies on the border of the runs and not on the border of the cells.
\t\t\t# The port takes one colour per run for the same reason.
\t\t\tvar run_color: Color = _ground_run_color(row, first_column, run_end, level)
\t\t\t# The run is cut into pieces: a piece is a piece of the collision of
\t\t\t# the ground and the place where the family of the ground may change.
\t\t\tvar segment_start: int = first_column""", eol)

# 2. The colour goes into the piece.
text = replace(text,
    "\t\t\t\t_append_ground_segment(tools, materials, row, segment_start, segment_end, level, collision_faces)",
    "\t\t\t\t_append_ground_segment(tools, materials, row, segment_start, segment_end, level, collision_faces, run_color)",
    eol)

# 3. The new function and the new signature of the piece.
text = replace(text, """## The light of the piece is the light of its four corners, the way the engine
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
""", """## The colour of a run of the free ground of the map.
##
## The original draws the ground of the map as one polygon per run of the free
## cells and writes ONE colour into its four vertices (FUN_004cca20: the same
## uVar8 in all four vertices, and the only writer of the three globals it is
## built from is CTclGlobalMethods__SetBrightness_0063cce0:90-93). The tone of
## the ground is therefore flat inside a run, and the step of the tone lies on
## the border of the runs and not on the border of the cells.
##
## The light of the run is the native light of its cells, averaged over the
## run: the native light of the free ground is the mean attribute of the
## chapter and the light sources of the chapter, and the light of the torches
## falls off with the distance, so the average is the tone of the run.
##
## The colour variation of the original is a tint of every cell of the map
## (Campaign.tcl:6 generate_color_variation), and it lies in the vertices of the
## polygon of the run, so the run takes the tint of its first cell.
func _ground_run_color(row: int, first_column: int, run_end: int, level: float) -> Color:
\tvar sum := Color(0.0, 0.0, 0.0, 1.0)
\tvar count: int = 0
\tvar step: int = maxi(GROUND.LIGHT_SAMPLE_CELLS, 1)
\tvar column: int = first_column
\twhile column <= run_end:
\t\tvar channels: Dictionary = profile.call("free_ground_channels",
\t\t\tVector2i(column, row), Vector2(0.5, 0.5), level)
\t\tvar diffuse: Color = channels["diffuse"]
\t\tsum += diffuse
\t\tcount += 1
\t\tcolumn += step
\tif count == 0:
\t\tcount = 1
\tvar light := Color(sum.r / float(count), sum.g / float(count), sum.b / float(count), 1.0)
\tvar tint: float = 0.9 + _variation_image.get_pixel(first_column, row).r * 0.2
\treturn light * tint


## One piece of the free ground of the map.
##
## The colour of the piece is the colour of its run: the tone of the ground of
## the original is flat inside a run, and the pieces of a run carry the same
## colour.
func _append_ground_segment(tools: Dictionary, materials: Dictionary, row: int,
\t\tfirst_column: int, last_column: int, level: float, collision: Array,
\t\trun_color: Color) -> void:
""", eol)

# 4. The colour of the cell is the colour of the run.
text = replace(text, """\t\t# The light of the cell is the light of the piece, interpolated over
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
""", """\t\t# The colour of the cell is the colour of the run: the original writes
\t\t# one colour into the four vertices of the polygon of a run, so the tone
\t\t# of the ground is flat inside a run.
""", eol)

text = replace(text, "\tvar width: float = float(last_column - first_column + 1)\n", "", eol)
text = replace(text, "\t\t\t\tsurface[3].append(cell_colors[corner_index_value] * tint)",
               "\t\t\t\tsurface[3].append(run_color)", eol)

with io.open(FIRST, "w", encoding="utf-8", newline="") as handle:
    handle.write(text)

# 5. The step of the sampling of the light of a run.
text, eol = load(GROUND)
text = replace(text, """## The length of a piece of the free ground of the map, in map cells.
##
## The engine draws the ground of the map as one polygon per run of the free
## cells and packs the light of the polygon into its vertices, so the light of
## a long run is the light of its two ends. A run of the map of the chapter
## crosses the whole island, and the ground between its ends then reads as one
## long dark bar. The port cuts the run into pieces of this length, so that
## the light is sampled in the place of the ground.
const LIGHT_SEGMENT_CELLS: int = 8""", """## The length of a piece of the free ground of the map, in map cells.
##
## The tone of the ground of the original is flat inside a run of the free
## cells (the colour of the polygon of the run lies in its four vertices), so
## the pieces of a run carry one colour. The pieces are the pieces of the
## collision of the ground and the place where the family of the ground may
## change.
const LIGHT_SEGMENT_CELLS: int = 8

## The step of the sampling of the light of a run, in map cells.
##
## The native light of the free ground falls off with the distance from the
## torches of the chapter, and the tone of the run is one colour, so the light
## of the run is averaged over its cells. The light falls off slowly, so every
## sixteenth cell of the run is enough for the average.
const LIGHT_SAMPLE_CELLS: int = 16""", eol)
with io.open(GROUND, "w", encoding="utf-8", newline="") as handle:
    handle.write(text)

print("patched the run colour")
