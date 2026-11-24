#!/usr/bin/env python3
"""Run every self-test suite of a Godot project headlessly.

The console launcher of Godot spawns the real engine, so the runner redirects
the output into files and waits for the launcher with a hard timeout. A suite
that does not finish is terminated with the matching engine process.

Usage:
    python run_suites.py --project <godot project> --out <log dir> [--only a,b]
"""
from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path

GODOT = Path(r"C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe")
OK_MARKER = re.compile(r"OK assertions=(\d+)")
CHECKS_MARKER = re.compile(r"checks=(\d+)\s+failures=(\d+)")
TIMEOUT_SECONDS = 240


def kill_suite_processes(suite: str) -> None:
    """Kill every Godot process whose command line mentions this suite."""
    script = (
        "$s = " + repr(suite).replace("'", "''") + "; "
        "Get-CimInstance Win32_Process -Filter \"Name like 'Godot%'\" | "
        "Where-Object { $_.CommandLine -and $_.CommandLine.Contains($s) } | "
        "ForEach-Object { Stop-Process -Id $_.ProcessId -Force -ErrorAction SilentlyContinue }"
    )
    subprocess.run(["powershell", "-NoProfile", "-Command", script], capture_output=True, timeout=60)


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
    print(f"suites: {len(suites)}", flush=True)
    failed: list[str] = []
    total = 0
    for suite in suites:
        marker = out / f"{suite}.ok"
        if marker.is_file():
            # Already green in an earlier run of this same working tree.
            total += int(marker.read_text(encoding="utf-8").strip() or "0")
            print(f"SKIP {suite:<48} (already green)", flush=True)
            continue
        log = out / f"suite_{suite}.log"
        err = out / f"suite_{suite}.log.err"
        with log.open("w", encoding="utf-8") as handle_out, err.open("w", encoding="utf-8") as handle_err:
            proc = subprocess.Popen(
                [str(GODOT), "--headless", "--path", str(project), "--script", f"res://tools/{suite}.gd"],
                stdout=handle_out,
                stderr=handle_err,
            )
            try:
                code = proc.wait(timeout=TIMEOUT_SECONDS)
            except subprocess.TimeoutExpired:
                proc.kill()
                kill_suite_processes(suite)
                code = -1
        out_text = log.read_text(encoding="utf-8", errors="replace")
        err_text = err.read_text(encoding="utf-8", errors="replace")
        combined = out_text + err_text
        match = OK_MARKER.search(out_text)
        checks = CHECKS_MARKER.search(out_text)
        green = False
        count = 0
        if code == 0 and "FAILED" not in combined and "FAIL" not in combined:
            green = True
            if match:
                count = int(match.group(1))
            elif checks and checks.group(2) == "0":
                count = int(checks.group(1))
        if green:
            total += count
            marker.write_text(str(count), encoding="utf-8")
            print(f"OK   {suite:<48} {count:>6} assertions  exit={code}", flush=True)
        else:
            failed.append(suite)
            print(f"FAIL {suite:<48} exit={code}", flush=True)
            print("\n".join(out_text.splitlines()[-12:]), flush=True)
            if err_text.strip():
                print("--- stderr ---", flush=True)
                print("\n".join(err_text.splitlines()[-12:]), flush=True)
            kill_suite_processes(suite)
    print(f"\nTOTAL assertions: {total}")
    if failed:
        print(f"FAILED ({len(failed)}): " + ", ".join(failed))
        return 1
    print("ALL SUITES GREEN")
    return 0


if __name__ == "__main__":
    sys.exit(main())
