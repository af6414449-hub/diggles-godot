"""Match live object coordinates to original Urwald Tcl template placements."""

import argparse
import json
from pathlib import Path
import sys
import tkinter

from analyze import LOG, records

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from extract_template_objects import NEW, coordinate_values  # noqa: E402


TEMPLATES = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\Templates")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("log", nargs="?", type=Path, default=LOG)
    args = parser.parse_args()
    events = [json.loads(line) for line in args.log.read_text(encoding="utf-8").splitlines() if line.strip()]
    starts = [i for i, event in enumerate(events) if event.get("event") == "session_start"]
    events = events[starts[-1]:] if starts else events
    interp = tkinter.Tcl()
    observed = {}
    for event in events:
        if event.get("event") not in ("object_snapshot", "dig_apply"):
            continue
        for field in (("objects",) if event["event"] == "object_snapshot" else ("before_objects", "after_objects")):
            for row in records(interp, event.get(field, "")):
                if len(row) < 3 or not row[1].startswith(("Dummy_Multi_Holzstuetze_", "Dummy_Moos_hm_", "Dummy_Wurzel_")):
                    continue
                xyz = tuple(float(value) for value in row[2].split()[:3])
                if len(xyz) == 3:
                    key = (row[1], round(xyz[0], 2), round(xyz[1], 2))
                    if key not in observed or xyz[2] > observed[key][2]:
                        observed[key] = xyz
    templates = []
    paths = sorted(set(TEMPLATES.glob("urw_gng_*.tcl")) | set(TEMPLATES.glob("urw_hol_*.tcl")) | {TEMPLATES / "urw_unq_start.tcl"})
    for path in paths:
        source = path.read_text(encoding="cp1252", errors="replace")
        for match in NEW.finditer(source):
            xyz = coordinate_values(match.group(2))
            if xyz and match.group(1).startswith("Dummy_"):
                templates.append((path.name, match.group(1), xyz))
    result = []
    for (class_name, _, _), world in sorted(observed.items()):
        matches = []
        for name, candidate_class, local in templates:
            if class_name != candidate_class or abs(world[2] - local[2]) > .04:
                continue
            dx, dy = round(world[0] - local[0]), round(world[1] - local[1])
            if dx % 4 == 0 and dy % 4 == 0 and abs(world[0] - local[0] - dx) < .02 and abs(world[1] - local[1] - dy) < .02:
                matches.append({"template": name, "offset": [dx, dy], "local": local})
        result.append({"class": class_name, "world": world, "matches": matches})
    print(json.dumps({"observed": len(result), "matched": sum(bool(item["matches"]) for item in result), "placements": result}, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
