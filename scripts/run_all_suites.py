#!/usr/bin/env python3
"""Run every self-test suite of the project headlessly.

Used for the regression check of the hamster integration: the suite list is
taken from tools/*self_test*.gd of the project under test. A self-test whose
name ends in _test.gd (the campaign excavation block) is a suite as well.
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
SUCCESS_CHECKS_MARKER = re.compile(r"SELF_TEST_OK checks=(\d+)")
# The suites of the project report their result in several shapes: a marker of
# the form NAME_OK, a JSON line with "ok":true, or a count of checks with a
# count of failures. A suite is green when it says so, whatever the shape it
# uses; only the exit code and the word FAIL can turn it red.
ASSERTIONS_MARKER = re.compile(r"assertions=(\d+)\s+failures=(\d+)")
OK_TOKEN = re.compile(r"\b[A-Z][A-Z0-9_]*_OK\b")
JSON_OK = re.compile(r'"ok"\s*:\s*true')
COUNT_MARKER = re.compile(r"(?:checks|assertions|commands)=(\d+)")
JSON_COUNT_MARKER = re.compile(r'"checks"\s*:\s*(\d+)')


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
    # The suites are the self-tests of tools/. A self-test that carries the
    # name of the module it checks (native_campaign_dig_test) is a suite too,
    # otherwise it would never run in a full pass.
    suites = sorted(
        {p.stem for p in (project / "tools").glob("*self_test*.gd")}
        | {p.stem for p in (project / "tools").glob("*_test.gd")}
    )
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
        success_checks = SUCCESS_CHECKS_MARKER.search(out_text)
        assertions = ASSERTIONS_MARKER.search(out_text)
        stderr_noise = err_text.strip()
        green = False
        count = 0
        if started.returncode == 0 and "FAIL" not in out_text:
            if match:
                green = True
                count = int(match.group(1))
            elif checks and checks.group(2) == "0":
                green = True
                count = int(checks.group(1))
            elif success_checks:
                green = True
                count = int(success_checks.group(1))
            elif assertions and assertions.group(2) == "0":
                green = True
                count = int(assertions.group(1))
            elif OK_TOKEN.search(out_text) or JSON_OK.search(out_text):
                # The suite names its own success without a counter.
                green = True
                counted = COUNT_MARKER.search(out_text) or JSON_COUNT_MARKER.search(out_text)
                if counted:
                    count = int(counted.group(1))
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
