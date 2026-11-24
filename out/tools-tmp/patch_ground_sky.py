#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The ground of the map is lit by the sky only.

The original draws the ground of the map as one polygon per run of the free
cells and writes the colour of the polygon into its four vertices from three
globals whose only writer is CTclGlobalMethods__SetBrightness (90-93).  That
is one brightness for the whole map: the torches of the chapter are under the
rock and do not reach the surface of the map.  The port let the light sources
of the chapter fall on the surface of the map, and the warm light of the
torches drew red streaks from the chapter to the edge of the map.
"""
import io
import os
import re
import sys

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\scripts"
PROFILE = os.path.join(ROOT, "native_campaign_profile.gd")
FIRST = os.path.join(ROOT, "native_campaign_first_level.gd")


def load(path):
    with io.open(path, "r", encoding="utf-8", newline="") as handle:
        text = handle.read()
    return text, ("\r\n" if "\r\n" in text else "\n")


def replace(text, old, new, eol, count=1):
    # The files of the project keep their own line endings, and a file may mix
    # them, so the pattern matches both.
    pattern = re.escape(old).replace(re.escape("\n"), r"\r?\n")
    found = len(re.findall(pattern, text))
    if found != count:
        raise SystemExit("expected %d matches, found %d for:\n%s" % (count, found, old[:160]))
    return re.sub(pattern, lambda _match: new.replace("\n", eol), text, count=count)


# 1. The surface of the map: the sky and nothing else.
text, eol = load(PROFILE)
text = replace(text, """## The native light of a free cell of the map.
##
## The free cells of the map are not in the export: they have no attribute
## bytes and carry the mean of the chapter. Their surface is flat, so the
## normal of the source space is the up axis, and their depth is the depth of
## the ground level in the source space: the blocks encode the depth as
## (game_z + 14) / 2.
##
## The light of the surface of the map is the sky and nothing else. The engine
## draws the ground of the map as one polygon per run of the free cells and
## writes ONE colour into its four vertices (FUN_004cca20: the same uVar8 in
## all four vertices), and that colour is built from three globals whose only
## writer is CTclGlobalMethods__SetBrightness_0063cce0:90-93 - one brightness
## for the whole map. The torches of the chapter are under the rock and do not
## fall on the surface of the map: the port let them fall, and the warm light
## of the torches drew red streaks from the chapter to the edge of the map.
func free_ground_channels(cell: Vector2i, local_point: Vector2, level: float) -> Dictionary:
\tvar point: Vector3 = Vector3(cell.x + local_point.x, cell.y + local_point.y, (level + 14.0) * 0.5)
\tvar channels: Dictionary = ILLUMINATION.channels(point, Vector3(0.0, 0.0, 1.0),
\t\tterrain_base_byte(cell, local_point), [], terrain_render["constants"])
\treturn _with_daylight(channels, Vector2i(-1, -1), 1.0)""", """## The native light of a free cell of the map.
##
## The free cells of the map are not in the export: they have no attribute
## bytes and carry the mean attribute of the chapter. Their surface is flat, so
## the normal of the source space is the up axis, and their depth is the depth of
## the ground level in the source space: the blocks encode the depth as
## (game_z + 14) / 2.
##
## The light of the surface of the map is the sky and nothing else. The engine
## draws the ground of the map as one polygon per run of the free cells and
## writes ONE colour into its four vertices (FUN_004cca20: the same uVar8 in
## all four vertices), and that colour is built from three globals whose only
## writer is CTclGlobalMethods__SetBrightness_0063cce0:90-93 - one brightness
## for the whole map. The torches of the chapter are under the rock and do not
## fall on the surface of the map: the port let them fall, and the warm light
## of the torches drew red streaks from the chapter to the edge of the map.
func free_ground_channels(cell: Vector2i, local_point: Vector2, level: float) -> Dictionary:
\tvar point: Vector3 = Vector3(cell.x + local_point.x, cell.y + local_point.y, (level + 14.0) * 0.5)
\tvar channels: Dictionary = ILLUMINATION.channels(point, Vector3(0.0, 0.0, 1.0),
\t\tterrain_base_byte(cell, local_point), [], terrain_render["constants"])
\treturn _with_daylight(channels, Vector2i(-1, -1), 1.0)""", eol)
with io.open(PROFILE, "w", encoding="utf-8", newline="") as handle:
    handle.write(text)

# 2. The colour of a run: the light is one value for the whole map, so it is
# taken once, and the tint of the run is the tint of its first cell.
text, eol = load(FIRST)
text = replace(text, """## The light of the run is the native light of its cells, averaged over the
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
\treturn light * tint""", """## The light of the run is the light of the surface of the map: the sky and
## nothing else, so it is the same for every run of the map
## (native_campaign_profile.gd:free_ground_channels). The light of the torches
## of the chapter falls on the cells of the chapter, not on the surface of the
## map, and the red streaks it drew over the map are gone.
##
## The colour variation of the original is a tint of every cell of the map
## (Campaign.tcl:6 generate_color_variation), and it lies in the vertices of the
## polygon of the run, so the run takes the tint of its first cell.
func _ground_run_color(row: int, first_column: int, _run_end: int, level: float) -> Color:
\tvar channels: Dictionary = profile.call("free_ground_channels",
\t\tVector2i(first_column, row), Vector2(0.5, 0.5), level)
\tvar light: Color = channels["diffuse"]
\tvar tint: float = 0.9 + _variation_image.get_pixel(first_column, row).r * 0.2
\treturn light * tint""", eol)
with io.open(FIRST, "w", encoding="utf-8", newline="") as handle:
    handle.write(text)

print("patched the light of the surface of the map")
