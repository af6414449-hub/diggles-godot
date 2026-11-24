#!/usr/bin/env python3
"""Run the hamster self-test suites headlessly in the agent working tree.

Mirrors the run_all_suites.ps1 of the snapshot: one Godot process per suite,
stdout and stderr captured separately, the "OK assertions=N" marker parsed from
stdout and the real exit code reported.
"""
from __future__ import annotations

import re
import subprocess
import sys
from pathlib import Path

GODOT = Path(r"C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe")
PROJECT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot")
OUT = PROJECT / "out"
SUITES = [
    "native_hamster_ai_self_test",
    "native_hamster_actor_self_test",
    "native_wild_hamster_self_test",
]
MARKER = re.compile(r"OK assertions=(\d+)")


def main() -> int:
    if not GODOT.is_file():
        print(f"godot binary missing: {GODOT}")
        return 2
    OUT.mkdir(parents=True, exist_ok=True)
    failures = 0
    for suite in SUITES:
        log = OUT / f"suite_{suite}.log"
        err = log.with_suffix(log.suffix + ".err")
        started = subprocess.run(
            [str(GODOT), "--headless", "--path", str(PROJECT), "--script", f"res://tools/{suite}.gd"],
            capture_output=True,
            timeout=600,
        )
        out_text = started.stdout.decode("utf-8", errors="replace")
        err_text = started.stderr.decode("utf-8", errors="replace")
        log.write_text(out_text, encoding="utf-8", newline="\n")
        err.write_text(err_text, encoding="utf-8", newline="\n")
        match = MARKER.search(out_text)
        if match:
            print(f"OK   {suite:<42} {int(match.group(1)):>4} assertions  exit={started.returncode}")
        else:
            failures += 1
            print(f"FAIL {suite:<42} exit={started.returncode}")
            print("--- stdout tail ---")
            print("\n".join(out_text.splitlines()[-30:]))
            print("--- stderr tail ---")
            print("\n".join(err_text.splitlines()[-30:]))
    print(f"\nresult: {len(SUITES) - failures}/{len(SUITES)} suites green")
    return 0 if failures == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
