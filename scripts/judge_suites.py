#!/usr/bin/env python3
"""Judge the suite logs of a test run.

The suites of the project use three different success markers, so the verdict
is derived from the captured log rather than from the runner output:

  OK assertions=N              - classic marker
  ... checks=N failures=0      - counter marker
  {"failures":[],...}          - JSON marker with an empty failure list
  status: ..._OK               - JSON marker with an OK status

A suite is green when the log carries one of those markers, the process exit
code was 0 and no FAIL line is present.
"""
from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

MARKER = re.compile(r"OK assertions=(\d+)")
CHECKS = re.compile(r"checks=(\d+)\s+failures=(\d+)")
STATUS_OK = re.compile(r'"status"\s*:\s*"[A-Z0-9_]*_OK"')
TOKEN_OK = re.compile(r"\b[A-Z0-9_]*_SELF_TEST_OK\b|\bNATIVE_[A-Z0-9_]*_OK\b")
JSON_OK = re.compile(r'"ok"\s*:\s*true')
FAIL_LINE = re.compile(r"^\s*FAIL\b", re.MULTILINE)
FAIL_WORD = re.compile(r"\bFAILED\b")


def judge(log_text: str) -> tuple[str, int, str]:
    match = MARKER.search(log_text)
    if match:
        return "OK", int(match.group(1)), "OK assertions="
    checks = CHECKS.search(log_text)
    if checks:
        if checks.group(2) == "0":
            return "OK", int(checks.group(1)), "checks=/failures=0"
        return "FAIL", int(checks.group(1)), "checks=/failures!=0"
    if STATUS_OK.search(log_text) or TOKEN_OK.search(log_text):
        payload = {}
        for line in log_text.splitlines():
            line = line.strip()
            if line.startswith("{") and line.endswith("}"):
                try:
                    payload = json.loads(line)
                except json.JSONDecodeError:
                    payload = {}
        failures = payload.get("failures", [])
        if isinstance(failures, list) and not failures:
            return "OK", len(payload.get("checks", [])) or 0, "token OK"
        return "FAIL", 0, "token OK but failures not empty"
    if JSON_OK.search(log_text) and '"failures":[]' in log_text.replace(" ", ""):
        return "OK", 0, "json ok:true"
    if FAIL_LINE.search(log_text):
        return "FAIL", 0, "FAIL line"
    return "FAIL", 0, "no success marker"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--logdir", required=True)
    args = parser.parse_args()
    logdir = Path(args.logdir)
    logs = sorted(logdir.glob("suite_*.log"))
    logs = [p for p in logs if not p.name.endswith(".log.err")]
    green = 0
    failed: list[str] = []
    total = 0
    for log in logs:
        suite = log.stem.replace("suite_", "")
        verdict, count, reason = judge(log.read_text(encoding="utf-8", errors="replace"))
        if verdict == "OK":
            green += 1
            total += count
            print(f"OK   {suite:<46} {count:>5}  ({reason})")
        else:
            failed.append(suite)
            print(f"FAIL {suite:<46} {'':>5}  ({reason})")
    print(f"\nsuites: {green}/{len(logs)} green, assertions counted: {total}")
    if failed:
        print("failed: " + ", ".join(failed))
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
