#!/usr/bin/env python3
"""Run the multiplayer scene headlessly and report the hamster integration lines.

The scene is an interactive one, so the process is stopped after a bounded
number of seconds. The log is searched for the navigation ready line of the
hamster grids, the clip changes of the hamsters and any script error.
"""
from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path

GODOT = Path(r"C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--project", required=True)
    parser.add_argument("--out", required=True)
    parser.add_argument("--seconds", type=int, default=180)
    parser.add_argument("--scene", default="res://scenes/multiplayer_test.tscn")
    args = parser.parse_args()

    project = Path(args.project)
    out = Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    log = out / "multiplayer_wild_hamster.log"

    command = [str(GODOT), "--headless", "--path", str(project), args.scene]
    print("command:", " ".join(command))
    try:
        started = subprocess.run(command, capture_output=True, timeout=args.seconds)
        out_text = started.stdout.decode("utf-8", errors="replace")
        err_text = started.stderr.decode("utf-8", errors="replace")
        returncode = started.returncode
        timed_out = False
    except subprocess.TimeoutExpired as expired:
        out_text = (expired.stdout or b"").decode("utf-8", errors="replace")
        err_text = (expired.stderr or b"").decode("utf-8", errors="replace")
        returncode = "timeout"
        timed_out = True

    log.write_text(out_text, encoding="utf-8", newline="\n")
    (out / "multiplayer_wild_hamster.log.err").write_text(err_text, encoding="utf-8", newline="\n")

    print(f"exit={returncode} timed_out={timed_out} stdout_lines={len(out_text.splitlines())}")
    print("\n--- integration lines ---")
    for line in out_text.splitlines():
        if re.search(r"WILD_HAMSTER|DWARF_NAV_READY|NATIVE_TERRAIN_READY|WORLD_MODEL_LIGHT_READY", line):
            print(line)
    print("\n--- errors ---")
    errors = [
        line
        for line in (out_text + "\n" + err_text).splitlines()
        if re.search(r"SCRIPT ERROR|Parse Error|ERROR:|Cannot call|nonexistent", line)
    ]
    for line in errors[:40]:
        print(line)
    if not errors:
        print("(none)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
