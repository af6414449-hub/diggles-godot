"""How dark is the surface of the port compared to the original.

The measurement answers one question: what colour does the ground of the map
come out as, and how does it compare with the surface of the original game.

Usage:
    python work/campaign/walls/surface_brightness.py
"""

import json
import os

from PIL import Image

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))))
OUT = os.path.join(ROOT, "out", "agent-visual-2026-11-21")
CHAPTER = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")
RENDER = os.path.join(ROOT, "godot", "models", "native_terrain_render.json")


def mean_rgb(image, box):
    region = image.crop(box).convert("RGB")
    pixels = region.load()
    width, height = region.size
    totals = [0, 0, 0]
    count = width * height
    if count == 0:
        return (0, 0, 0)
    for y in range(height):
        for x in range(width):
            pixel = pixels[x, y]
            totals[0] += pixel[0]
            totals[1] += pixel[1]
            totals[2] += pixel[2]
    return tuple(round(total / count) for total in totals)


def engine_math(attribute, normal, gain, haze=None, z=None):
    """The diffuse of the engine path FUN_004cc040 and the port path.

    The port: base = 64 + 16 * attribute, level = base * normal_term, rgb = level * gain.
    The engine: base = 64 + (interpolated byte >> 20), then the haze multiplies
    the diffuse down by (1 - fog).
    """
    normal_term = 3.6 - 2.546 * normal[0] - 2.546 * normal[1]
    port_base = 64 + 16 * attribute
    engine_base = 64 + (attribute * 65536 >> 20)
    port_value = port_base * normal_term * gain
    engine_value = engine_base * normal_term * gain
    if haze is not None and z is not None:
        fog = min(1.0, max(0.0, (1.0 - (z - 7.0) * 0.125 * 1.02) * haze))
        engine_value *= 1.0 - fog
    return (round(port_value), round(engine_value))


def main():
    with open(RENDER, encoding="utf-8") as handle:
        constants = json.load(handle)["constants"]
    gain = float(constants["gain"])

    print("=== the light of a flat ground of the port ===")
    for attribute in (0, 1, 2, 4, 6, 8, 255):
        port, engine = engine_math(attribute, (0.0, 0.0), gain)
        print("attribute %3d -> base %5d  port %3d/255 (%.0f%%)   engine %3d/255"
              % (attribute, 64 + 16 * attribute, port, port / 255.0 * 100, engine))

    print()
    print("=== the haze of the engine (owner byte -> haze) ===")
    for owner in (0, 1, 64, 127, 128, 200, 255):
        if 0 < owner < 128:
            haze = 1.0
        else:
            raw = owner - 128
            if raw > 0:
                raw = min(128, int(raw * 1.3))
            doubled = min(255, raw * 2) if raw > 0 else raw * 2
            haze = max(0, 255 - abs(doubled)) / 255.0
        surface = engine_math(4, (0.0, 0.0), gain, haze, 14.25)[1]
        deep = engine_math(4, (0.0, 0.0), gain, haze, 10.5)[1]
        print("owner %3d -> haze %.3f  surface %3d/255  deep %3d/255"
              % (owner, haze, surface, deep))

    print()
    print("=== the colours of the frames ===")
    start = Image.open(os.path.join(ROOT, "out", "campaign-shots", "v9-start.png"))
    print("port v9-start.png 1280x720")
    print("  grass plateau of the chapter (x 440..760, y 340..430):",
          mean_rgb(start, (440, 340, 760, 430)))
    print("  free ground of the map (x 120..380, y 480..640):",
          mean_rgb(start, (120, 480, 380, 640)))
    print("  sky area (x 0..300, y 0..40):",
          mean_rgb(start, (0, 0, 300, 40)))

    shot = os.path.join(OUT, "north-normal.png")
    if os.path.exists(shot):
        north = Image.open(shot)
        print("port north-normal.png (the surface between the mountains)")
        print("  middle (x 300..900, y 250..500):",
              mean_rgb(north, (300, 250, 900, 500)))

    reference = os.environ.get("REFERENCE_SHOT")
    if reference and os.path.exists(reference):
        original = Image.open(reference)
        print("original %s %s" % (os.path.basename(reference), original.size))
        print("  grass (x 300..900, y 150..450):",
              mean_rgb(original, (300, 150, 900, 450)))
        print("  grass (x 80..300, y 200..320):",
              mean_rgb(original, (80, 200, 300, 320)))

    original = os.path.join(ROOT, "out", "original-shots", "steam_05_big.png")
    if os.path.exists(original):
        print("original steam_05_big.png is the underground, not the surface")


if __name__ == "__main__":
    main()
