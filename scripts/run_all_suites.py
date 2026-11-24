#!/usr/bin/env python3
"""Run every self-test suite of the project headlessly.

Used for the regression check of the hamster integration: the suite list is
taken from tools/*self_test*.gd of the project under test.
"""
from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path

GODOT = Path(r"C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe")
MARKER = re.compile(r"OK assertions=(\d+)")
CHECKS_MARKER = re.compile(r"checks=(\d+)\s+failures=(\d+)")


def kill_suite_processes(suite: str) -> None:
    """Kill every Godot process whose command line mentions this suite.

    The console binary is a launcher that spawns the real engine, so killing
    the direct child leaves the engine behind. Matching on the command line
    keeps other sessions' Godot processes untouched.
    """
    script = (
        "$s = " + repr(suite).replace("'", "''") + "; "
        "Get-CimInstance Win32_Process -Filter \"Name like 'Godot%'\" | "
        "Where-Object { $_.CommandLine -and $_.CommandLine.Contains($s) } | "
        "ForEach-Object { Stop-Process -Id $_.ProcessId -Force -ErrorAction SilentlyContinue }"
    )
    subprocess.run(
        ["powershell", "-NoProfile", "-Command", script],
        capture_output=True,
        timeout=60,
    )


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--project", required=True)
    parser.add_argument("--out", required=True)
    parser.add_argument("--only", default="")
    args = parser.parse_args()

    project = Path(args.project)
    out = Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    suites = sorted(p.stem for p in (project / "tools").glob("*self_test*.gd"))
    if args.only:
        wanted = {name.strip() for name in args.only.split(",") if name.strip()}
        suites = [name for name in suites if name in wanted]
    print(f"suites: {len(suites)}")

    total = 0
    failed: list[str] = []
    for suite in suites:
        log = out / f"suite_{suite}.log"
        err = out / f"suite_{suite}.log.err"
        try:
            started = subprocess.run(
                [str(GODOT), "--headless", "--path", str(project), "--script", f"res://tools/{suite}.gd"],
                capture_output=True,
                timeout=240,
            )
        except subprocess.TimeoutExpired as expired:
            kill_suite_processes(suite)
            failed.append(suite)
            print(f"TIMEOUT {suite}")
            continue
        out_text = started.stdout.decode("utf-8", errors="replace")
        err_text = started.stderr.decode("utf-8", errors="replace")
        log.write_text(out_text, encoding="utf-8", newline="\n")
        err.write_text(err_text, encoding="utf-8", newline="\n")
        match = MARKER.search(out_text)
        checks = CHECKS_MARKER.search(out_text)
        stderr_noise = err_text.strip()
        green = False
        count = 0
        if match and started.returncode == 0 and "FAIL" not in out_text:
            green = True
            count = int(match.group(1))
        elif checks and checks.group(2) == "0" and started.returncode == 0 and "FAIL" not in out_text:
            green = True
            count = int(checks.group(1))
        if green:
            total += count
            print(f"OK   {suite:<46} {count:>5} assertions  exit={started.returncode}")
        else:
            failed.append(suite)
            print(f"FAIL {suite:<46} exit={started.returncode}")
            print("\n".join(out_text.splitlines()[-20:]))
            if stderr_noise:
                print("--- stderr ---")
                print("\n".join(stderr_noise.splitlines()[-20:]))

    print(f"\nTOTAL assertions: {total}")
    if failed:
        print(f"FAILED ({len(failed)}): " + ", ".join(failed))
        return 1
    print("ALL SUITES GREEN")
    return 0


if __name__ == "__main__":
    sys.exit(main())
