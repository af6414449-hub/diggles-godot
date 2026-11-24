"""A/B of the light of the surface of the campaign map.

The port lights the terrain with the attribute byte of the cell, which is not
a light level (see work/campaign/walls/surface_light.py). The surface of the
map therefore comes out as dark as the deepest pit. This script measures the
same regions of one or more frames and compares them with the reference of the
original game, so a change of the light path can be checked at once.

The regions belong to a fixed camera, so the frames of a comparison must be
captured with the same view:

    --view default   the start area of the chapter (the camp and the ground)
    --view north     the excavation and the ground of the same frame

The frames are captures of the campaign scene with the framing of the native
set_view command (--capture-native-view), without it the scene frames the whole
chapter and the regions do not match. The baseline is the frame of the scene
before the daylight of the surface, so the factor of the change of the light
path is the difference of the two captures.

The original is the target of the comparison. Its daylight is measured on
steam_03.jpg, the daylight surface of the original game, and the grass of the
original comes from the frame of the owner. The grass of the port and the grass
of the original are the same native texture, so the two are comparable, and the
factor to the original is the number a change of the light path has to hit.

Usage:
    python work/campaign/walls/surface_ab.py --view default frame.png [frame.png ...]
    python work/campaign/walls/surface_ab.py --view north frame.png [frame.png ...]
"""

import os
import sys

from PIL import Image

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))))

# The regions and their baseline, measured before any change of the light path.
# The third value of a region is the reference of the original, None where the
# original has no counterpart for the region.
VIEWS = {
    "default": {
        "baseline_frame": "out/campaign-shots/v30-start.png",
        "regions": (
            ("grass plateau of the chapter", (330, 288, 430, 316), "grass"),
            ("free ground of the map", (80, 430, 320, 540), None),
        ),
    },
    "north": {
        "baseline_frame": "out/campaign-shots/v30-start.png",
        "regions": (
            ("excavation floor (underground)", (380, 480, 660, 570), None),
            ("free ground of the map", (80, 430, 320, 540), None),
        ),
    },
}

# The grass of the surface of the original in the frame of the owner: the same
# native texture as the grass of the port, so the two are comparable.
ORIGINAL_GRASS = (99, 94, 44)

# The daylight of the original on a frame of the repository: steam_03.jpg is
# the daylight surface of the original game, its pale ground and its lit
# foliage. The values are measured, the frame is measured again on every run.
ORIGINAL_SHOT = {
    "frame": "out/original-shots/steam_03.jpg",
    "regions": (
        ("pale ground of the original", (20, 430, 200, 520), (114, 106, 47)),
        ("foliage of the original", (0, 0, 120, 260), (82, 98, 50)),
    ),
}

# A frame of the original within 5 percent of the reference counts as the
# original.
TOLERANCE = 0.05


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


def luminance(colour):
    return round(0.2126 * colour[0] + 0.7152 * colour[1] + 0.0722 * colour[2])


def factor_to(colour, reference):
    """How bright the colour is against the reference, 1.0 is the original."""
    base = luminance(reference)
    if not base:
        return None
    return luminance(colour) / float(base)


def print_original():
    """The daylight of the original: the target of the comparison."""
    print("=== the original game ===")
    print("%-32s %-16s %-16s" % ("region", "measured", "expected"))
    path = os.path.join(ROOT, ORIGINAL_SHOT["frame"])
    for name, box, expected in ORIGINAL_SHOT["regions"]:
        if os.path.exists(path):
            measured = mean_rgb(Image.open(path), box)
            print("%-32s %-16s %-16s" % (name, str(measured), str(expected)))
        else:
            print("%-32s %-16s %-16s" % (name, "NOT FOUND", str(expected)))
    print("%-32s %-16s" % ("grass of the original", str(ORIGINAL_GRASS)))
    print()


def main():
    arguments = sys.argv[1:]
    view_name = "default"
    if "--view" in arguments:
        index = arguments.index("--view")
        view_name = arguments[index + 1]
        del arguments[index:index + 2]
    frames = arguments
    if view_name not in VIEWS:
        print("unknown view %r, use %s" % (view_name, " or ".join(VIEWS)))
        return 1
    if not frames:
        print(__doc__)
        return 1

    view = VIEWS[view_name]
    baseline_frame = os.path.join(ROOT, view["baseline_frame"])
    baseline = {}
    if os.path.exists(baseline_frame):
        image = Image.open(baseline_frame)
        for name, box, _reference in view["regions"]:
            baseline[name] = mean_rgb(image, box)
    else:
        print("baseline frame %s NOT FOUND" % view["baseline_frame"])
        print()

    print_original()

    for path in frames:
        if not os.path.exists(path):
            print("%s: NOT FOUND" % path)
            continue
        image = Image.open(path)
        print("=== %s (%dx%d) view=%s ===" % (
            os.path.basename(path), image.width, image.height, view_name))
        print("%-32s %-16s %-16s %-10s %s" % (
            "region", "this frame", "baseline", "change", "to the original"))
        for name, box, reference in view["regions"]:
            colour = mean_rgb(image, box)
            base = baseline.get(name, (0, 0, 0))
            change = ""
            if luminance(base):
                factor = luminance(colour) / float(luminance(base))
                change = "%.2fx" % factor
                if factor > 1.05:
                    change += " BRIGHTER"
                elif factor < 0.95:
                    change += " DARKER"
            against = ""
            if reference == "grass":
                against = "grass"
            if against:
                factor = factor_to(colour, ORIGINAL_GRASS)
                if factor is not None:
                    against = "%.2fx the grass %s" % (
                        factor, "IS the original" if abs(factor - 1.0) <= TOLERANCE
                        else "of the original")
            print("%-32s %-16s %-16s %-10s %s" % (
                name, str(colour), str(base), change, against))
        print()
    return 0


if __name__ == "__main__":
    sys.exit(main())
