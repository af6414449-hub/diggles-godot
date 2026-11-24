#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Measure the thin dark marks on a surface in a capture.

The original draws the dug corridors and shafts of the chapter on the ground
surface of the map as thin dark marks.  The port has to draw the same marks,
so both pictures are measured with the same method:

  1. the picture is converted to a tone channel (luminance or R-B),
  2. a thin mark is isolated with a high pass: the tone minus a blurred copy
     of the tone; a dark mark is positive there,
  3. the marks above the depth threshold are collected as components,
  4. every component is described by its length, its width and its contrast,
  5. the lattice of the marks (the pitch of their rows and columns) is
     reported as well, so a grid can be told from a random speckle.

Usage:
    python dark_marks.py FRAME.png [FRAME.png ...] [--box x0,y0,x1,y1]
        [--px-per-cell 14.0] [--depth 6] [--blur 4.0] [--channel lum|rb]
        [--min-area 3] [--save-marks OUT.png]

Read-only: it only reads PNG files.  With --save-marks it writes one PNG with
the detected marks marked over the region, into the path that is given.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image
from scipy import ndimage


def load(path: str, box) -> np.ndarray:
    image = Image.open(path).convert("RGB")
    array = np.asarray(image).astype(np.float32)
    if box is not None:
        x0, y0, x1, y1 = box
        array = array[y0:y1, x0:x1]
    return array


def tone(array: np.ndarray, channel: str) -> np.ndarray:
    if channel == "rb":
        return array[:, :, 0] - array[:, :, 2]
    return (0.299 * array[:, :, 0] + 0.587 * array[:, :, 1] + 0.114 * array[:, :, 2])


def high_pass(tone_map: np.ndarray, blur: float, method: str = "median",
              window: int = 9) -> np.ndarray:
    """The tone minus a blurred copy of the tone: positive on a dark mark.

    A thin dark line is a dark mark only against the tone around it, so the
    background has to be a filter that removes the line and keeps the surface.
    A median filter of a window wider than the line does that; a gaussian
    blur of the same width would spread the line over the background and
    would cut its amplitude down to a fraction of the real one.
    """
    if method == "gauss":
        if blur <= 0.0:
            return -tone_map
        blurred = ndimage.gaussian_filter(tone_map, blur, mode="nearest")
        return blurred - tone_map
    size = max(3, int(window) | 1)
    background = ndimage.median_filter(tone_map, size=size, mode="nearest")
    return background - tone_map


def robust_noise(values: np.ndarray) -> float:
    """The median absolute deviation of the values, scaled to a sigma."""
    median = float(np.median(values))
    return float(np.median(np.abs(values - median)) * 1.4826)


def detect(marks: np.ndarray, depth: float, min_area: int, min_aspect: float = 0.0):
    """The connected components of the marks above the depth threshold."""
    mask = marks >= depth
    labels, count = ndimage.label(mask, structure=np.ones((3, 3), dtype=int))
    objects = ndimage.find_objects(labels)
    result = []
    for index, slices in enumerate(objects, start=1):
        if slices is None:
            continue
        region = marks[slices]
        binary = labels[slices] == index
        area = int(binary.sum())
        if area < min_area:
            continue
        height = region.shape[0]
        width = region.shape[1]
        longest = max(height, width)
        shortest = min(height, width)
        aspect = longest / float(max(shortest, 1))
        if aspect < min_aspect:
            continue
        result.append({
            "area": area,
            "height": height,
            "width": width,
            "length": longest,
            "short": shortest,
            "aspect": aspect,
            "depth": float(region[binary].mean()),
            "peak": float(region[binary].max()),
            "center_y": float(slices[0].start + slices[0].stop) * 0.5,
            "center_x": float(slices[1].start + slices[1].stop) * 0.5,
        })
    return result, count


def lattice(positions, limit: int = 400.0):
    """The pitch of the rows or the columns of the marks."""
    values = np.sort(np.asarray(positions, dtype=np.float64))
    if values.size < 2:
        return []
    steps = np.diff(values)
    steps = steps[steps > 0.5]
    if steps.size == 0:
        return []
    counts = {}
    for step in steps:
        key = round(float(step), 1)
        counts[key] = counts.get(key, 0) + 1
    ranked = sorted(counts.items(), key=lambda item: (-item[1], item[0]))
    return [(key, value) for key, value in ranked[:8] if key <= limit]


def sides_of_marks(base: np.ndarray, found: list, offset: int = 5, band: int = 3) -> dict:
    """The tone on both sides of every mark, across its short axis.

    A mark that is the border of two materials has a different tone on its two
    sides; a mark that is a seam of a texture has the same tone on both sides.
    """
    height, width = base.shape
    differences = []
    for item in found:
        centre_y = item["center_y"] - 0.5
        centre_x = item["center_x"] - 0.5
        along_x = item["length"] >= item["short"]
        for sign in (1, -1):
            samples = []
            for step in range(offset, offset + band):
                if along_x:
                    y = int(round(centre_y + sign * step))
                    x = int(round(centre_x))
                else:
                    y = int(round(centre_y))
                    x = int(round(centre_x + sign * step))
                if 0 <= y < height and 0 <= x < width:
                    samples.append(base[y, x])
            if not samples:
                continue
            item.setdefault("sides", {})[sign] = float(np.mean(samples))
        if len(item.get("sides", {})) == 2:
            differences.append(item["sides"][1] - item["sides"][-1])
    if not differences:
        return {"marks": 0}
    values = np.array(differences, dtype=np.float64)
    return {
        "marks": int(values.size),
        "median": float(np.median(values)),
        "p90": float(np.percentile(values, 90)),
        "p10": float(np.percentile(values, 10)),
        "share_darker_side": float(100.0 * np.mean(values > 2.0)),
        "share_same": float(100.0 * np.mean(np.abs(values) <= 2.0)),
    }


def measure(path: str, box, channel: str, blur: float, depth: float,
            min_area: int, px_per_cell: float, min_aspect: float = 0.0,
            method: str = "median", window: int = 9) -> dict:
    array = load(path, box)
    tone_map = tone(array, channel)
    marks = high_pass(tone_map, blur, method, window)
    noise = robust_noise(marks)
    found, raw_count = detect(marks, depth, min_area, min_aspect)
    lengths = np.array([item["length"] for item in found], dtype=np.float64)
    shorts = np.array([item["short"] for item in found], dtype=np.float64)
    depths = np.array([item["depth"] for item in found], dtype=np.float64)
    peaks = np.array([item["peak"] for item in found], dtype=np.float64)
    area = float(marks.shape[0] * marks.shape[1])
    share = 100.0 * sum(item["area"] for item in found) / max(area, 1.0)
    return {
        "file": os.path.basename(path),
        "region": list(box) if box is not None else [0, 0, marks.shape[1], marks.shape[0]],
        "channel": channel,
        "noise": noise,
        "threshold": depth,
        "components": len(found),
        "raw_components": raw_count,
        "area_share": share,
        "length_median": float(np.median(lengths)) if lengths.size else 0.0,
        "length_p90": float(np.percentile(lengths, 90)) if lengths.size else 0.0,
        "short_median": float(np.median(shorts)) if shorts.size else 0.0,
        "short_p90": float(np.percentile(shorts, 90)) if shorts.size else 0.0,
        "depth_median": float(np.median(depths)) if depths.size else 0.0,
        "depth_p90": float(np.percentile(depths, 90)) if depths.size else 0.0,
        "peak_median": float(np.median(peaks)) if peaks.size else 0.0,
        "peak_max": float(peaks.max()) if peaks.size else 0.0,
        "lattice_rows": lattice([item["center_y"] for item in found]),
        "lattice_columns": lattice([item["center_x"] for item in found]),
        "items": found,
        "marks": marks,
        "base": tone_map,
    }


def report(row: dict, px_per_cell: float) -> None:
    print("%-28s region=%s channel=%s" % (row["file"], row["region"], row["channel"]))
    print("   noise of the high pass = %.2f, threshold = %.2f" % (row["noise"], row["threshold"]))
    print("   marks: %d (of %d components), %.2f %% of the area" %
          (row["components"], row["raw_components"], row["area_share"]))
    if row["components"]:
        print("   length: median=%.1f px p90=%.1f px   width: median=%.1f px p90=%.1f px" %
              (row["length_median"], row["length_p90"], row["short_median"], row["short_p90"]))
        if px_per_cell > 0.0:
            print("   in cells: length=%.2f p90=%.2f   width=%.2f p90=%.2f" %
                  (row["length_median"] / px_per_cell, row["length_p90"] / px_per_cell,
                   row["short_median"] / px_per_cell, row["short_p90"] / px_per_cell))
        print("   contrast: median=%.2f p90=%.2f   peak: median=%.2f max=%.2f" %
              (row["depth_median"], row["depth_p90"], row["peak_median"], row["peak_max"]))
        print("   pitch of the rows: %s" % (row["lattice_rows"] or "no lattice"))
        print("   pitch of the columns: %s" % (row["lattice_columns"] or "no lattice"))
    print("")


def save_marks(path: str, row: dict, out_path: str) -> None:
    marks = row["marks"]
    base = row["base"]
    scale = max(1.0, row["threshold"])
    normalised = np.clip(marks / (4.0 * scale), 0.0, 1.0)
    picture = np.zeros(base.shape + (3,), dtype=np.uint8)
    if base.ndim == 2:
        grey = np.clip(base, 0, 255).astype(np.uint8)
        picture[:, :, 0] = grey
        picture[:, :, 1] = grey
        picture[:, :, 2] = grey
    else:
        picture = np.clip(base, 0, 255).astype(np.uint8)
    picture[:, :, 0] = np.clip(picture[:, :, 0].astype(np.float32) + 220.0 * normalised, 0, 255)
    picture[:, :, 1] = np.clip(picture[:, :, 1].astype(np.float32) - 40.0 * normalised, 0, 255)
    picture[:, :, 2] = np.clip(picture[:, :, 2].astype(np.float32) - 40.0 * normalised, 0, 255)
    Image.fromarray(picture).save(out_path)
    print("saved %s" % out_path)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("images", nargs="+")
    parser.add_argument("--box", default="")
    parser.add_argument("--px-per-cell", type=float, default=0.0)
    parser.add_argument("--depth", type=float, default=0.0)
    parser.add_argument("--blur", type=float, default=4.0)
    parser.add_argument("--channel", default="lum", choices=["lum", "rb"])
    parser.add_argument("--min-area", type=int, default=3)
    parser.add_argument("--min-aspect", type=float, default=0.0)
    parser.add_argument("--method", default="median", choices=["median", "gauss"])
    parser.add_argument("--window", type=int, default=9)
    parser.add_argument("--save-marks", default="")
    parser.add_argument("--auto-depth", type=float, default=3.0)
    arguments = parser.parse_args()
    box = None
    if arguments.box:
        box = tuple(int(part) for part in arguments.box.split(","))
    for path in arguments.images:
        if not os.path.isfile(path):
            print("missing: %s" % path)
            continue
        probe = measure(path, box, arguments.channel, arguments.blur,
                        max(arguments.depth, 1.0), arguments.min_area,
                        arguments.px_per_cell, arguments.min_aspect,
                        arguments.method, arguments.window)
        depth = arguments.depth
        if depth <= 0.0:
            depth = max(arguments.auto_depth * probe["noise"], 2.0)
        row = measure(path, box, arguments.channel, arguments.blur, depth,
                      arguments.min_area, arguments.px_per_cell, arguments.min_aspect,
                      arguments.method, arguments.window)
        report(row, arguments.px_per_cell)
        if arguments.save_marks:
            save_marks(path, row, arguments.save_marks)
    return 0


if __name__ == "__main__":
    sys.exit(main())
