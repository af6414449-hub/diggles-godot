"""Summarize the latest original Diggles excavation trace session."""

from collections import Counter
import argparse
import json
from pathlib import Path
import tkinter


LOG = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\diggles_dig_trace.jsonl")


def records(interpreter: tkinter.Tcl, value: str) -> list[tuple[str, ...]]:
    try:
        return [interpreter.splitlist(item) for item in interpreter.splitlist(value)]
    except tkinter.TclError:
        return []


def placement(row: tuple[str, ...]) -> tuple[str, str, str]:
    """obj_query references are ephemeral; class and horizontal position identify a placement."""
    coordinates = row[2].split()
    return (row[1], *(f"{float(value):.2f}" for value in coordinates[:2]))


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("log", nargs="?", type=Path, default=LOG)
    args = parser.parse_args()
    events = [json.loads(line) for line in args.log.read_text(encoding="utf-8").splitlines() if line.strip()]
    starts = [index for index, event in enumerate(events) if event.get("event") == "session_start"]
    if starts:
        events = events[starts[-1]:]
    interpreter = tkinter.Tcl()
    counts = Counter(event.get("event", "?") for event in events)
    surfaces_by_class = Counter(event.get("class", "?") for event in events if event.get("event") == "object_surface")
    changes = []
    successful_without_hmap_change = []
    object_changes = []
    seen_classes = Counter()
    unique_objects = {}
    results = Counter()
    height_transitions = Counter()
    transition_cells = {}
    changed_xy = set()
    query_errors = []
    snapshot_transitions = []
    snapshot_placements = {}
    previous_snapshot = None
    last_by_ref = {}
    z_movements = []
    for event in events:
        observed_fields = ("objects",) if event.get("event") == "object_snapshot" else (
            ("before_objects", "after_objects") if event.get("event") == "dig_apply" else ()
        )
        for field in observed_fields:
            for row in records(interpreter, event.get(field, "")):
                if len(row) < 3:
                    continue
                try:
                    xyz = tuple(float(value) for value in row[2].split()[:3])
                except ValueError:
                    continue
                if len(xyz) != 3:
                    continue
                previous = last_by_ref.get(row[0])
                if previous and previous[0] == row[1] and abs(previous[1][0] - xyz[0]) < .02 and abs(previous[1][1] - xyz[1]) < .02 and abs(previous[1][2] - xyz[2]) > .1:
                    z_movements.append({"ref": row[0], "class": row[1], "xy": [xyz[0], xyz[1]], "before_z": previous[1][2], "after_z": xyz[2], "before_time": previous[2], "after_time": event.get("time")})
                last_by_ref[row[0]] = (row[1], xyz, event.get("time"))
        if event.get("event") == "object_snapshot":
            raw = event.get("objects", "")
            pos = event.get("actor_pos", "")
            if raw.startswith("QUERY_ERROR:"):
                query_errors.append({"event": "object_snapshot", "error": raw})
            else:
                current = {placement(row): row for row in records(interpreter, raw) if len(row) >= 3}
                snapshot_placements.update(current)
                try:
                    xy = tuple(float(value) for value in pos.split()[:2])
                except ValueError:
                    xy = ()
                if previous_snapshot and len(xy) == 2 and xy == previous_snapshot[0]:
                    prior = previous_snapshot[1]
                    added = [current[ref] for ref in current.keys() - prior.keys()]
                    removed = [prior[ref] for ref in prior.keys() - current.keys()]
                    if added or removed:
                        snapshot_transitions.append({"time": event.get("time"), "actor_xy": xy, "added": added, "removed": removed})
                previous_snapshot = (xy, current)
        if event.get("event") != "dig_apply":
            continue
        results[event.get("result", "?")] += 1
        before = records(interpreter, event.get("before_hmap", ""))
        after = records(interpreter, event.get("after_hmap", ""))
        before_by_xy = {(row[0], row[1]): row[2] for row in before if len(row) >= 3}
        changed = [
            [row[0], row[1], before_by_xy.get((row[0], row[1]), "?"), row[2]]
            for row in after
            if len(row) >= 3 and before_by_xy.get((row[0], row[1])) != row[2]
        ]
        if changed:
            changes.append({"point": event.get("point"), "actor_pos": event.get("actor_pos"), "cells": changed})
            for x, y, old, new in changed:
                changed_xy.add((int(x), int(y)))
                transition = f"{old}->{new}"
                height_transitions[transition] += 1
                transition_cells.setdefault(transition, set()).add((int(x), int(y)))
        elif event.get("result") == "1":
            successful_without_hmap_change.append(event.get("point"))
        for field in ("before_objects", "after_objects"):
            if event.get(field, "").startswith("QUERY_ERROR:"):
                query_errors.append({"point": event.get("point"), "field": field, "error": event[field]})
        before_objects = {placement(row): row for row in records(interpreter, event.get("before_objects", "")) if len(row) >= 3}
        after_objects = {placement(row): row for row in records(interpreter, event.get("after_objects", "")) if len(row) >= 3}
        seen_classes.update(row[1] for row in after_objects.values())
        unique_objects.update(after_objects)
        added = [after_objects[ref] for ref in after_objects.keys() - before_objects.keys()]
        removed = [before_objects[ref] for ref in before_objects.keys() - after_objects.keys()]
        if added or removed:
            object_changes.append({"point": event.get("point"), "added": added, "removed": removed})
    summary = {
        "session_start": next((event for event in events if event.get("event") == "session_start"), None),
        "event_counts": dict(counts),
        "class_script_loaded": counts["class_script_loaded"] > 0,
        "dig_execute_seen": counts["dig_execute"] > 0,
        "dig_apply_seen": counts["dig_apply"] > 0,
        "object_snapshots_seen": counts["object_snapshot"],
        "object_surfaces_by_class": dict(surfaces_by_class),
        "dig_apply_results": dict(results),
        "height_changes_count": len(changes),
        "successful_without_hmap_change": successful_without_hmap_change[:20],
        "height_transitions": dict(height_transitions),
        "height_transition_rows": {
            transition: {
                str(y): sorted(x for x, row_y in cells if row_y == y)
                for y in sorted({row_y for _, row_y in cells})
            }
            for transition, cells in transition_cells.items()
        },
        "changed_cell_extent": {
            "x_min": min((x for x, _ in changed_xy), default=None),
            "x_max": max((x for x, _ in changed_xy), default=None),
            "y_min": min((y for _, y in changed_xy), default=None),
            "y_max": max((y for _, y in changed_xy), default=None),
        },
        "first_height_changes": changes[:12],
        "object_changes_count": len(object_changes),
        "first_object_changes": object_changes[:20],
        "stationary_snapshot_transitions_count": len(snapshot_transitions),
        "stationary_snapshot_transitions": snapshot_transitions,
        "snapshot_placements_by_class": dict(Counter(row[1] for row in snapshot_placements.values())),
        "snapshot_unique_placements": sorted((row[1], row[2]) for row in snapshot_placements.values()),
        "same_ref_z_movements": z_movements,
        "object_observations_by_class": dict(seen_classes),
        "unique_object_placements": sorted({(row[1], row[2]) for row in unique_objects.values()}),
        "query_errors": query_errors[:12],
    }
    print(json.dumps(summary, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
