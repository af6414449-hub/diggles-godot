"""Offline contract check for the original-game Tcl trace (no game writes)."""

import json
import os
from pathlib import Path
import tempfile
import tkinter


def main() -> None:
    module = Path(__file__).with_name("dig_trace.tcl")
    class_module = Path(__file__).with_name("dwarf_helpers.tcl")
    interpreter = tkinter.Tcl()
    height = {"value": "15"}
    calls: list[tuple[str, tuple[str, ...]]] = []

    def mark(*args: str) -> str:
        calls.append(("dig_mark", args))
        return "MARK_OK"

    def skin(*args: str) -> str:
        calls.append(("cave_skin", args))
        return "SKIN_OK"

    interpreter.createcommand("dig_mark", mark)
    interpreter.createcommand("cave_skin", skin)
    interpreter.createcommand("get_hmap", lambda *_: height["value"])
    interpreter.createcommand("obj_query", lambda *_: "42")
    interpreter.createcommand("get_objclass", lambda *_: "Schatztonne")
    interpreter.createcommand("get_pos", lambda *_: "10 20 15")

    with tempfile.TemporaryDirectory(prefix="digtrace-") as directory:
        old_cwd = Path.cwd()
        try:
            os.chdir(directory)
            interpreter.eval(f"source {{{module.as_posix()}}}")
            assert interpreter.call("dig_mark", "0", "10", "20", "1") == "MARK_OK"
            assert interpreter.call("cave_skin", "add", "0", "10", "20", "11", "21") == "SKIN_OK"
            before = interpreter.call("digtrace_before_apply", "10 20 14", "this")
            height["value"] = "11"
            interpreter.call("digtrace_after_apply", "10 20 14", "this", before, "1")
            interpreter.eval("flush $::digtrace_log")
            interpreter.eval("close $::digtrace_log")

            class_interpreter = tkinter.Tcl()
            class_height = {"value": "15"}
            class_interpreter.createcommand("get_hmap", lambda *_: class_height["value"])
            class_interpreter.createcommand("get_material", lambda *_: "2")
            class_interpreter.createcommand("obj_query", lambda *_: "42")
            class_interpreter.createcommand("get_objclass", lambda *_: "Schatztonne")
            class_interpreter.createcommand("get_pos", lambda *_: "10 20 15")
            class_interpreter.createcommand("tasklist_add", lambda *_: "")
            class_interpreter.eval(f"source {{{class_module.as_posix()}}}")
            class_interpreter.call("digtrace_class_emit", "dig_execute", "point {10 20 14}")
            class_before = class_interpreter.call("digtrace_class_before", "10 20 14")
            class_height["value"] = "11"
            class_interpreter.call("digtrace_class_after", "10 20 14", class_before, "1")
            events = [json.loads(line) for line in Path("diggles_dig_trace.jsonl").read_text(encoding="utf-8").splitlines()]
        finally:
            os.chdir(old_cwd)

    assert calls == [
        ("dig_mark", ("0", "10", "20", "1")),
        ("cave_skin", ("add", "0", "10", "20", "11", "21")),
    ]
    assert [event["event"] for event in events] == [
        "hook", "hook", "session_start", "dig_mark", "cave_skin", "dig_apply",
        "class_script_loaded", "dig_execute", "object_surface", "dig_apply"
    ]
    strike = events[5]
    assert strike["result"] == "1"
    assert "15" in strike["before_hmap"] and "11" in strike["after_hmap"]
    assert "Schatztonne" in strike["after_objects"]
    class_strike = events[-1]
    assert class_strike["stream"] == "zwerg" and class_strike["result"] == "1"
    assert "15" in class_strike["before_hmap"] and "11" in class_strike["after_hmap"]
    assert "Schatztonne" in class_strike["after_objects"]
    assert events[-2]["class"] == "Schatztonne" and "15" in events[-2]["hmap"]
    print("DIG_TRACE_VERIFY_OK events=10 class_script=1 class_strike=1 surface=1 mark=1 cave_skin=1")


if __name__ == "__main__":
    main()
