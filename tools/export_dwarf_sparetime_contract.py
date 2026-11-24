"""Recover the dwarf sparetime/work state-machine contract from the original Tcl.

The oracle is produced by executing the *original* procedures in a Tcl
interpreter with recorded stubs, so the exported golden values are the
behaviour of the shipped game and not a re-implementation of it.

Sources (read-only):
    data/Scripts/classes/zwerg/z_spare_main.tcl
    data/Scripts/classes/zwerg/z_spare_procs.tcl
    data/Scripts/classes/zwerg/z_spare_fun.tcl
    data/Scripts/classes/zwerg/z_work_states.tcl
    data/Scripts/classes/zwerg/z_work_prod.tcl
    data/Scripts/classes/zwerg/z_procs.tcl
    data/Scripts/classes/zwerg/z_dignwalk.tcl
    data/Scripts/misc/sparetimetunes.tcl
    data/Scripts/misc/genattribs.tcl
"""
import argparse
import hashlib
import json
import re
import tkinter
from pathlib import Path

PROJECT = Path(__file__).resolve().parents[1]
DEFAULT_DATA = Path(
    r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
)

SOURCES = [
    "Scripts/classes/zwerg/z_spare_main.tcl",
    "Scripts/classes/zwerg/z_spare_procs.tcl",
    "Scripts/classes/zwerg/z_spare_fun.tcl",
    "Scripts/classes/zwerg/z_work_states.tcl",
    "Scripts/classes/zwerg/z_work_prod.tcl",
    "Scripts/classes/zwerg/z_procs.tcl",
    "Scripts/classes/zwerg/z_dignwalk.tcl",
    "Scripts/misc/sparetimetunes.tcl",
    "Scripts/misc/genattribs.tcl",
]


# --------------------------------------------------------------------------- #
# source access
# --------------------------------------------------------------------------- #
def read_tcl(data: Path, relative: str) -> str:
    return (data / relative).read_bytes().decode("cp1252")


def extract_proc(text: str, name: str) -> str:
    """Return the full text of `proc <name> ...` including its body braces."""
    marker = "proc %s " % name
    start = text.index(marker)
    index = start + len(marker)
    while text[index] in " \t":
        index += 1
    if text[index] != "{":
        raise ValueError("Unexpected proc header for %s" % name)
    depth = 0
    while True:
        char = text[index]
        if char == "\\":
            index += 2
            continue
        if char == "{":
            depth += 1
        elif char == "}":
            depth -= 1
            if depth == 0:
                index += 1
                break
        index += 1
    while text[index] in " \t\r\n":
        index += 1
    if text[index] != "{":
        raise ValueError("Unexpected proc body for %s" % name)
    depth = 0
    while index < len(text):
        char = text[index]
        if char == "\\":
            index += 2
            continue
        if char == "{":
            depth += 1
        elif char == "}":
            depth -= 1
            if depth == 0:
                return text[start:index + 1]
        index += 1
    raise ValueError("Unbalanced braces in proc %s" % name)


def strip_comments(text: str) -> str:
    out = []
    for line in text.splitlines():
        out.append(line.split("//", 1)[0])
    return "\n".join(out)


def line_of(text: str, needle: str) -> int:
    for number, line in enumerate(text.splitlines(), 1):
        if needle in line:
            return number
    raise ValueError("Source marker not found: %s" % needle)


# --------------------------------------------------------------------------- #
# Tcl harness
# --------------------------------------------------------------------------- #
HELPERS = (
    "proc hmin {args} {if {[llength $args]==1} {set best {};set first 1;"
    "foreach x [lindex $args 0] {if {$first||$x<$best} {set best $x;set first 0}};return $best};"
    "set a [lindex $args 0];set b [lindex $args 1];if {$a<$b} {return $a};return $b};"
    "proc hmax {args} {if {[llength $args]==1} {set best {};set first 1;"
    "foreach x [lindex $args 0] {if {$first||$x>$best} {set best $x;set first 0}};return $best};"
    "set a [lindex $args 0];set b [lindex $args 1];if {$a>$b} {return $a};return $b};"
    "proc fincr {name v} {upvar 1 $name x;set x [expr {$x+$v}]};"
    "proc lrem {name i} {upvar 1 $name x;set x [lreplace $x $i $i]};"
    "proc land {a b} {set r {};foreach x $a {if {[lsearch -exact $b $x]!=-1} "
    "{lappend r $x}};return $r};"
    "proc lnand {a b} {set r {};foreach x $b {if {[lsearch -exact $a $x]==-1} "
    "{lappend r $x}};return $r};"
    "proc lcount {a b} {set n 0;foreach x $a {if {$x eq $b} {incr n}};return $n};"
    "proc log {args} {};"
    "proc fun_log {args} {};"
    "proc is_selected {args} {return 0};"
    "proc get_remaining_sparetime {args} {return $::remaining_spare};"
    "proc get_attrib {obj key} {return $::at_Mo};"
    "proc get_objname {args} {return \"obj\"};"
    "proc get_ref {args} {return 7};"
)


def new_interp(extra: str = "") -> tkinter.Tcl:
    interp = tkinter.Tcl()
    interp.eval(HELPERS)
    if extra:
        interp.eval(extra)
    return interp


def set_state(interp: tkinter.Tcl, state: dict) -> None:
    for key, value in state.items():
        interp.setvar(key, value)


def tcl_value(value):
    """Normalise tkinter results (Tcl_Obj) into plain JSON types."""
    if value is None or isinstance(value, (bool, int, float, str)):
        return value
    if isinstance(value, (list, tuple)):
        return [tcl_value(item) for item in value]
    if isinstance(value, dict):
        return {str(key): tcl_value(item) for key, item in value.items()}
    return str(value)


def as_text(value) -> str:
    """A Tcl list of tokens collapses back to its source spacing."""
    if isinstance(value, (list, tuple)):
        return " ".join(str(item) for item in value)
    return str(value)


def get_state(interp: tkinter.Tcl, keys) -> dict:
    return {key: interp.getvar(key) for key in keys}


# --------------------------------------------------------------------------- #
# 1. constants from sparetimetunes.tcl
# --------------------------------------------------------------------------- #
TUNE_PATTERN = re.compile(r"^\s*set\s+(stt_[A-Za-z0-9_]+)\s+(.+?)\s*$")


def parse_tunes(text: str) -> dict:
    """Collect every `set stt_*` inside the "Zwerg" section of sparetimetunes.tcl."""
    body = text[text.index('"Zwerg" {'):]
    body = body[: body.index("\n\t}")] if "\n\t}" in body else body
    values = {}
    for line in body.splitlines():
        match = TUNE_PATTERN.match(line)
        if not match:
            continue
        name, raw = match.group(1), match.group(2).split(";#")[0].split("#")[0].strip()
        if raw.startswith("{") and raw.endswith("}"):
            parts = raw[1:-1].split()
            try:
                values[name] = [float(part) for part in parts]
            except ValueError:
                values[name] = parts
        else:
            try:
                values[name] = float(raw)
            except ValueError:
                values[name] = raw
    return values


# --------------------------------------------------------------------------- #
# 2. Tcl double formatting (used by the source `lsort -index 1` ASCII order)
# --------------------------------------------------------------------------- #
DOUBLE_VALUES = [
    0.0, 1.0, 0.9, 0.8190000000000001, 0.5, 0.05, 0.25, 0.8, 0.85, 0.95, 0.97,
    0.98, 0.99, 0.1, 0.01, 0.0001, 0.00015, 0.00012345, 1e-05, 3e-05, 1e-06,
    2.5e-07, 1e-09, 0.3, 0.7, 0.6, 0.65, 0.55, 0.45, 0.35, 0.15, 0.2, 0.4,
    0.75, 0.125, 0.375, 1e16, 1e17, 1e18, 1.5e17, 123456789012345.0,
    1234567890123456.0, 1.2345678901234568e16, 0.6666666666666666,
    0.123456789012345, 0.819, 2.0, 100.0, 1e14, 1e15, -0.5, -1e-05,
]


def double_strings(data: Path) -> list:
    interp = tkinter.Tcl()
    rows = []
    for value in DOUBLE_VALUES:
        interp.setvar("v", value)
        rows.append({"value": value, "expected": interp.eval("set v")})
    return rows


# --------------------------------------------------------------------------- #
# 3. sparetime_future plan (z_spare_main.tcl:53-68)
# --------------------------------------------------------------------------- #
def future_plans(data: Path) -> list:
    text = read_tcl(data, "Scripts/classes/zwerg/z_spare_main.tcl")
    start = text.index("set sparetime_rest [hceil [get_remaining_sparetime this]]")
    end = text.index("set own [get_owner this]", start)
    block = strip_comments(text[start:end])
    rows = []
    for rest in [0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0]:
        for initialize in [0, 1, 2]:
            for bath in [0.0, 3.0, 6.5]:
                for random_index in [0, 1]:
                    for keep in [False, True]:
                        for ceil_mode in ["double", "int"]:
                            interp = new_interp()
                            if ceil_mode == "double":
                                interp.eval("proc hceil {v} {set d [expr {double(ceil($v))}];"
                                            "return [expr {$d + 0.0}]}")
                            else:
                                interp.eval("proc hceil {v} {return [expr {int(ceil($v))}]}")
                            interp.createcommand("irandom", lambda n, v=random_index: v)
                            interp.setvar("sparetime_initialize", initialize)
                            interp.setvar("spt_bath_desire", bath)
                            interp.setvar("remaining_spare", rest)
                            interp.setvar("last_spareleave", 1000.0 if keep else 0.0)
                            interp.setvar("time_count_start", 1000.0)
                            interp.setvar("sparetime_future", "eat fun" if keep else "")
                            interp.eval(block)
                            rows.append({
                                "rest": rest,
                                "initialize": initialize,
                                "bath_desire": bath,
                                "random_index": random_index,
                                "keep_future": keep,
                                "ceil_mode": ceil_mode,
                                "expected": interp.getvar("sparetime_future"),
                            })
    return rows, block


# --------------------------------------------------------------------------- #
# 4. sparetime_decide_occup (z_spare_main.tcl:378-710)
# --------------------------------------------------------------------------- #
DECIDE_KEYS = [
    "current_wish_occupation", "sparetime_emergency", "sparetime_compare_value",
    "sparetime_goal_reached", "sparetime_goal", "sparetime_mingoal",
    "sparetime_emchange_initial", "sparetime_remembered_scv", "spt_fun_portion",
    "spt_fun_ignore", "sparetime_future", "sparetime_history",
]


def decide_occup(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_spare_main.tcl")
    chunk = extract_proc(text, "sparetime_decide_occup")
    chunk = strip_comments(chunk)
    cases = [
        # needs, illness, occupation, wish, future, history, extra state
        dict(at_Hi=1.0, at_Nu=0.9, at_Al=0.9, at_Mo=0.8, ill=0, occ="fun", wish="fun",
             future="", history="", goal_reached=2, emergency=0, scv=0.0, future_init=2),
        dict(at_Hi=1.0, at_Nu=0.4, at_Al=0.2, at_Mo=0.8, ill=0, occ="fun", wish="fun",
             future="", history="", goal_reached=2, emergency=0, scv=0.0, future_init=2),
        dict(at_Hi=1.0, at_Nu=0.1, at_Al=0.05, at_Mo=0.3, ill=0, occ="idle", wish="idle",
             future="", history="", goal_reached=2, emergency=0, scv=0.0, future_init=2),
        dict(at_Hi=0.7, at_Nu=0.2, at_Al=0.2, at_Mo=0.1, ill=1, occ="fun", wish="fun",
             future="", history="", goal_reached=2, emergency=0, scv=0.0, future_init=2),
        dict(at_Hi=1.0, at_Nu=0.05, at_Al=0.9, at_Mo=0.8, ill=0, occ="fun", wish="fun",
             future="", history="", goal_reached=2, emergency=0, scv=0.0, future_init=2),
        dict(at_Hi=1.0, at_Nu=0.9, at_Al=0.05, at_Mo=0.8, ill=0, occ="fun", wish="fun",
             future="", history="", goal_reached=2, emergency=0, scv=0.0, future_init=2),
        dict(at_Hi=1.0, at_Nu=0.9, at_Al=0.9, at_Mo=0.3, ill=0, occ="fun", wish="fun",
             future="", history="", goal_reached=2, emergency=0, scv=0.0, future_init=2),
        dict(at_Hi=1.0, at_Nu=0.4, at_Al=0.2, at_Mo=0.8, ill=0, occ="eat", wish="eat",
             future="eat fun slp eat", history="slp", goal_reached=0, emergency=1, scv=0.3,
             future_init=1),
        dict(at_Hi=1.0, at_Nu=0.4, at_Al=0.2, at_Mo=0.8, ill=0, occ="slp", wish="slp",
             future="eat fun slp eat", history="", goal_reached=1, emergency=1, scv=0.3,
             future_init=1),
        dict(at_Hi=1.0, at_Nu=0.9, at_Al=0.9, at_Mo=0.8, ill=0, occ="fun", wish="fun",
             future="eat fun slp eat", history="", goal_reached=0, emergency=0, scv=0.3,
             future_init=1),
        dict(at_Hi=1.0, at_Nu=0.9, at_Al=0.9, at_Mo=0.8, ill=0, occ="eat", wish="eat",
             future="eat fun slp eat", history="", goal_reached=0, emergency=0, scv=0.3,
             future_init=1),
        dict(at_Hi=1.0, at_Nu=0.95, at_Al=0.95, at_Mo=0.99, ill=0, occ="fun", wish="fun",
             future="eat fun slp eat", history="", goal_reached=2, emergency=0, scv=0.3,
             future_init=1),
        dict(at_Hi=1.0, at_Nu=0.6, at_Al=0.6, at_Mo=0.6, ill=0, occ="fun", wish="fun",
             future="fun", history="", goal_reached=2, emergency=0, scv=0.3, future_init=1),
        dict(at_Hi=1.0, at_Nu=0.6, at_Al=0.6, at_Mo=0.6, ill=0, occ="fun", wish="fun",
             future="fun", history="", goal_reached=2, emergency=0, scv=0.3, future_init=1,
             fun_needs=8, fun_stations=2),
        dict(at_Hi=1.0, at_Nu=0.6, at_Al=0.6, at_Mo=0.6, ill=0, occ="fun", wish="fun",
             future="fun", history="", goal_reached=2, emergency=0, scv=0.3, future_init=1,
             bath_desire=7.0),
        dict(at_Hi=1.0, at_Nu=0.3, at_Al=0.3, at_Mo=0.3, ill=0, occ="fun", wish="fun",
             future="", history="", goal_reached=2, emergency=0, scv=0.3, future_init=1,
             fun_ignore=1, eat_check=1),
        dict(at_Hi=1.0, at_Nu=0.9, at_Al=0.9, at_Mo=0.8, ill=0, occ="slp", wish="slp",
             future="slp eat", history="", goal_reached=2, emergency=0, scv=0.3,
             future_init=1, eat_check=1),
        # A goal that is still unmet keeps the wish occupation and clears it.
        dict(at_Hi=1.0, at_Nu=0.4, at_Al=0.2, at_Mo=0.8, ill=0, occ="slp", wish="slp",
             future="eat fun slp eat", history="", goal_reached=0, emergency=0, scv=0.3,
             future_init=1, goal="$at_Al- 0.2 >=0.5345454545454545"),
        # A reached goal clears the plan and falls back to fun.
        dict(at_Hi=1.0, at_Nu=0.4, at_Al=0.2, at_Mo=0.8, ill=0, occ="slp", wish="slp",
             future="eat fun slp eat", history="", goal_reached=0, emergency=0, scv=0.3,
             future_init=1, goal="$at_Al- 0.2 >=-0.1"),
        # The bath wish is reachable through the future plan.
        dict(at_Hi=1.0, at_Nu=0.9, at_Al=0.9, at_Mo=0.8, ill=0, occ="fun", wish="fun",
             future="eat fun slp bth eat", history="", goal_reached=2, emergency=0,
             scv=0.3, future_init=1, bath_desire=3.0),
        # Missing fun stations raise the fun goal threshold.
        dict(at_Hi=1.0, at_Nu=0.6, at_Al=0.6, at_Mo=0.6, ill=0, occ="fun", wish="fun",
             future="fun", history="", goal_reached=2, emergency=0, scv=0.3,
             future_init=1, fun_needs=8, fun_stations=1),
    ]
    rows = []
    for case in cases:
        interp = new_interp()
        interp.createcommand("sparetime_eat_check", lambda v=case.get("eat_check", 0): v)
        interp.createcommand("sparetime_ill_check", lambda v=case["ill"]: v)
        state = dict(
            at_Hi=case["at_Hi"], at_Nu=case["at_Nu"], at_Al=case["at_Al"],
            at_Mo=case["at_Mo"], sparetime_emergency=case["emergency"],
            current_occupation=case["occ"], current_wish_occupation=case["wish"],
            sparetime_remembered_scv=case["scv"], sparetime_compare_value=case["scv"],
            sparetime_goal=case.get("goal", ""), sparetime_mingoal="",
            spt_fun_ignore=case.get("fun_ignore", 0),
            sparetime_goal_reached=case["goal_reached"], spt_fun_check=0,
            spt_fun_stations=case.get("fun_stations", 0),
            civ_state=case.get("civ_state", 0.0),
            spt_fun_needs=case.get("fun_needs", 0),
            spt_fun_portion=0.0, sparetime_future=case["future"],
            sparetime_history=case["history"],
            sparetime_emchange_initial=0, spt_bath_desire=case.get("bath_desire", 0.0),
            has_bathed=0, declog=0, remaining_spare=6.0,
            ill_check=case["ill"], eat_check=case.get("eat_check", 0),
        )
        set_state(interp, state)
        interp.eval(chunk)
        interp.eval("sparetime_decide_occup")
        row = {"input": state}
        row.update(get_state(interp, DECIDE_KEYS))
        row["sparetime_goal"] = as_text(row["sparetime_goal"])
        row["sparetime_mingoal"] = as_text(row["sparetime_mingoal"])
        row["sparetime_goal_tokens"] = row["sparetime_goal"].split(" ") \
            if row["sparetime_goal"] else []
        row["expected"] = {key: row[key] for key in DECIDE_KEYS}
        rows.append(row)
    return rows, chunk


# --------------------------------------------------------------------------- #
# 5. work state machine (z_work_states.tcl)
# --------------------------------------------------------------------------- #
WORK_AUTO_TASKS = ["pickup", "pickupitem", "bringprod", "transferprod", "work",
                   "dig", "pack", "buildup", "unpack", "repair", "unknown"]


def work_auto_cases(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_work_states.tcl")
    chunk = strip_comments(extract_proc(text, "state_work_auto_proc"))
    rows = []
    for task in WORK_AUTO_TASKS:
        interp = new_interp()
        calls = []
        interp.createcommand("state_trigger", lambda o, s: calls.append(("state_trigger", s)) or "")
        interp.createcommand("tasklist_add", lambda o, c: calls.append(("tasklist_add", c)) or "")
        interp.createcommand("log", lambda *a: "")
        set_state(interp, dict(
            state_log=0, state_shell=0, current_workplace=17, current_worktask=task,
            current_workitem=42, current_workclass=9, current_digpos="3 4 0",
            current_workpos="5 6", idletimeout=0, current_occupation="idle",
        ))
        interp.eval(chunk)
        interp.eval("state_work_auto_proc")
        rows.append({
            "task": task,
            "expected_calls": calls,
            "expected_occupation": interp.getvar("current_occupation"),
            "expected_idletimeout": interp.getvar("idletimeout"),
        })
    return rows, chunk


def work_dispatch_cases(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_work_states.tcl")
    chunk = strip_comments(extract_proc(text, "state_work_dispatch_proc"))
    rows = []
    scenarios = [
        ("empty-list", [], "work", 0),
        ("task-true", ["set ok 1"], "work", 0),
        ("task-false", ["set ok 0"], "work", 0),
        ("task-false-sparetime", ["set ok 0"], "sparetime", 0),
        ("task-false-sparetime-list", ["set ok 0"], "sparetime", 3),
    ]
    for name, worklist, plan, failures in scenarios:
        interp = new_interp()
        calls = []
        interp.createcommand("state_trigger", lambda o, s: calls.append(("state_trigger", s)) or "")
        interp.createcommand("state_triggerfresh",
                            lambda o, s: calls.append(("state_triggerfresh", s)) or "")
        interp.createcommand("state_disable", lambda o: calls.append(("state_disable",)) or "")
        interp.createcommand("state_enable", lambda o: calls.append(("state_enable",)) or "")
        interp.createcommand("action",
                            lambda o, a, v, cb=None: calls.append(("action", a, str(v))) or "")
        interp.createcommand("call_method",
                            lambda o, m: calls.append(("call_method", m)) or "")
        set_state(interp, dict(
            state_log=0, state_shell=0, prod_failurecount=failures,
            current_workplace=17, current_worktask="work", current_workitem=42,
            current_workclass=9, current_digpos="3 4 0", idletimeout=0,
            current_occupation="idle", current_worklist=worklist, current_plan=plan,
            errorInfo="",
        ))
        interp.eval(chunk)
        interp.eval("state_work_dispatch_proc")
        rows.append({
            "name": name,
            "worklist": worklist,
            "plan": plan,
            "failure_count": failures,
            "expected_calls": calls,
            "expected_worklist": interp.getvar("current_worklist"),
            "expected_workplace": interp.getvar("current_workplace"),
            "expected_failure_count": interp.getvar("prod_failurecount"),
        })
    return rows, chunk


def work_idle_cases(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_work_states.tcl")
    chunk = strip_comments(extract_proc(text, "state_work_idle_proc"))
    rows = []
    scenarios = [
        # idletimeout, remaining_spare, sparetime_is_on, plan, gnome_position, strike
        ("idle-1", 1, 6.0, 0, "work", 0, 0),
        ("idle-3", 3, 6.0, 0, "work", 0, 0),
        ("idle-4", 4, 6.0, 0, "work", 0, 0),
        ("idle-6-spare", 6, 6.0, 0, "work", 0, 0),
        ("idle-6-no-spare", 6, 0.0, 1, "work", 0, 0),
        ("idle-11", 11, 6.0, 0, "work", 0, 0),
        ("idle-11-strike", 11, 6.0, 0, "work", 0, 1),
        ("idle-11-nopos", 11, 6.0, 0, "work", 0, 0),
    ]
    for name, timeout, spare, is_on, plan, position, strike in scenarios:
        interp = new_interp()
        calls = []
        interp.createcommand("prod_gnome_state",
                            lambda o, s: calls.append(("prod_gnome_state", s)) or "")
        interp.createcommand("act_when_idle", lambda: calls.append(("act_when_idle",)) or 0)
        interp.createcommand("state_enable", lambda o: calls.append(("state_enable",)) or "")
        interp.createcommand("state_disable", lambda o: calls.append(("state_disable",)) or "")
        interp.createcommand("state_triggerfresh",
                            lambda o, s: calls.append(("state_triggerfresh", s)) or "")
        interp.createcommand("action",
                            lambda o, a, v, cb=None: calls.append(("action", a, str(v))) or "")
        interp.createcommand("sparetime_state_end", lambda: calls.append(("sparetime_state_end",)) or "")
        interp.createcommand("get_gnomeposition", lambda o: position)
        interp.createcommand("get_prodautoschedule", lambda o: 0)
        interp.createcommand("call_method", lambda o, m: calls.append(("call_method", m)) or "fight")
        interp.createcommand("prod_change_muetze",
                            lambda v: calls.append(("prod_change_muetze", v)) or "")
        interp.createcommand("set_idle_anim", lambda: calls.append(("set_idle_anim",)) or "")
        interp.createcommand("rand", lambda: 0.5)
        interp.createcommand("get_remaining_sparetime", lambda o: spare)
        set_state(interp, dict(
            state_log=0, state_shell=0, idletimeout=timeout - 1,
            current_workplace=0, current_time_plan=plan, current_plan=plan,
            current_occupation="idle", current_muetze_ref=0, muetzen_counter=1,
            muetzen_counter_start=100, current_muetze_name="fight", muetze_counter=1,
            work_strike=strike, sparetime_is_on=is_on,
        ))
        interp.eval(chunk)
        interp.eval("state_work_idle_proc")
        rows.append({
            "name": name,
            "idletimeout": timeout,
            "remaining_spare": spare,
            "sparetime_is_on": is_on,
            "plan": plan,
            "gnome_position": position,
            "work_strike": strike,
            "expected_calls": calls,
            "expected_occupation": interp.getvar("current_occupation"),
            "expected_idletimeout": interp.getvar("idletimeout"),
        })
    return rows, chunk


def work_plan_switch_cases(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_work_states.tcl")
    rows = []
    for proc_name, state in [("state_work_active_proc", "work_active"),
                             ("state_work_breakable_proc", "work_breakable")]:
        chunk = strip_comments(extract_proc(text, proc_name))
        for plan in ["work", "sparetime"]:
            interp = new_interp()
            calls = []
            interp.createcommand("state_triggerfresh",
                                lambda o, s: calls.append(("state_triggerfresh", s)) or "")
            set_state(interp, dict(state_log=0, state_shell=0, current_plan=plan))
            interp.eval(chunk)
            interp.eval(proc_name)
            rows.append({"proc": proc_name, "plan": plan, "expected_calls": calls})
    return rows


def work_enter_leave_cases(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_work_states.tcl")
    enter = strip_comments(extract_proc(text, "state_enter_work_idle_proc"))
    leave = strip_comments(extract_proc(text, "state_leave_work_idle_proc"))
    rows = []
    interp = new_interp()
    calls = []
    interp.createcommand("stop_prod", lambda: calls.append(("stop_prod",)) or "")
    interp.createcommand("gnome_idle", lambda o, v: calls.append(("gnome_idle", v)) or "")
    set_state(interp, dict(state_log=0, state_shell=0, current_worktask="work",
                           current_workplace=17, current_workclass=9,
                           last_event="evt", event_repeat=1))
    interp.eval(enter)
    interp.eval("state_enter_work_idle_proc")
    rows.append({"proc": "state_enter_work_idle_proc", "expected_calls": calls,
                 "expected_worktask": interp.getvar("current_worktask"),
                 "expected_workclass": interp.getvar("current_workclass"),
                 "expected_last_event": interp.getvar("last_event"),
                 "expected_event_repeat": interp.getvar("event_repeat")})
    interp = new_interp()
    calls = []
    interp.createcommand("gnome_idle", lambda o, v: calls.append(("gnome_idle", v)) or "")
    set_state(interp, dict(state_log=0, state_shell=0))
    interp.eval(leave)
    interp.eval("state_leave_work_idle_proc")
    rows.append({"proc": "state_leave_work_idle_proc", "expected_calls": calls})
    return rows


# --------------------------------------------------------------------------- #
# 6. rotate_toangle / stop_prod
# --------------------------------------------------------------------------- #
def rotate_cases(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_dignwalk.tcl")
    chunk = strip_comments(extract_proc(text, "rotate_toangle"))
    rows = []
    for angle, anim in [(5.0, ""), (1.25, ""), (0.5, "stand")]:
        interp = new_interp()
        calls = []
        interp.createcommand("state_disable", lambda o: calls.append(("state_disable",)) or "")
        interp.createcommand("state_enable", lambda o: calls.append(("state_enable",)) or "")
        interp.createcommand("action",
                            lambda o, a, v, cb=None: calls.append(("action", a, str(v))) or "")
        interp.eval(chunk)
        result = interp.eval("rotate_toangle %s %s" % (angle, anim))
        rows.append({"angle": angle, "anim": anim, "expected_result": result,
                     "expected_calls": calls})
    return rows, chunk


def stop_prod_cases(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_procs.tcl")
    chunk = strip_comments(extract_proc(text, "stop_prod"))
    rows = []
    for state, toolchange in [("sparetime_dispatch", 1), ("work_dispatch", 1),
                              ("interaction", 1), ("reprod", 1), ("work_idle", 0)]:
        interp = new_interp()
        calls = []
        interp.createcommand("beam_back", lambda: calls.append(("beam_back",)) or "")
        interp.createcommand("add_attrib",
                            lambda o, k, v: calls.append(("add_attrib", k, v)) or "")
        interp.createcommand("unlock_item", lambda: calls.append(("unlock_item",)) or "")
        interp.createcommand("inv_list", lambda o: "")
        interp.createcommand("get_objtype", lambda i: "")
        interp.createcommand("set_prod_unpack", lambda i, v: calls.append(("set_prod_unpack",)) or "")
        interp.createcommand("dig_resetid", lambda o: calls.append(("dig_resetid",)) or "")
        interp.createcommand("placelock_rem", lambda r: calls.append(("placelock_rem",)) or "")
        interp.createcommand("enable_auto_fanim", lambda: calls.append(("enable_auto_fanim",)) or "")
        interp.createcommand("dig_endanim", lambda: calls.append(("dig_endanim",)) or "")
        interp.createcommand("sparetime_reset_clothes",
                            lambda: calls.append(("sparetime_reset_clothes",)) or "")
        interp.createcommand("change_tool",
                            lambda *a: calls.append(("change_tool",) + tuple(str(x) for x in a)) or "")
        interp.createcommand("gettime", lambda: 1000.0)
        interp.createcommand("state_get", lambda o: state)
        interp.createcommand("get_ref", lambda o: 7)
        interp.createcommand("set_workplace", lambda o, w: None)
        for suffix in ["eat", "fun", "slp", "bth", "ill"]:
            interp.createcommand("sparetime_%s_end" % suffix,
                                lambda s=suffix: calls.append(("sparetime_%s_end" % s,)) or "")
        # stop_prod reaches deep into the production stack; unknown native
        # commands are neutralised so only the recorded calls matter.
        interp.eval("proc unknown {args} {return \"\"}")
        set_state(interp, dict(
            current_workplace=0, current_worklist="", reprod_actionlock=1,
            walkfail_tasks="x", last_disturb=0.0, sparetime_talkevents="",
            myref=7, event_repeat=1, current_occupation="eat",
            stt_dst_spare=-0.01, stt_dst_sex=-0.05, stt_dst_talk=-0.02,
            stt_dst_work=-0.005, stt_dst_idle=0.0,
        ))
        interp.eval(chunk)
        interp.eval("stop_prod %d" % toolchange)
        rows.append({"state": state, "toolchange": toolchange,
                     "expected_calls": calls})
    return rows, chunk


# --------------------------------------------------------------------------- #
# 7. place registry / sparetime_check_in
# --------------------------------------------------------------------------- #
def check_in_cases(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_spare_procs.tcl")
    chunk = strip_comments(extract_proc(text, "sparetime_check_in"))
    rows = []
    scenarios = [
        # seats available, current place ref, method
        ("fresh", [0, 1], 0, 0),
        ("fresh-random", [0, 1], 0, -1),
        ("fresh-method", [0, 1], 0, 1),
        ("full", [], 0, 0),
        ("replace", [0, 1], 33, 0),
    ]
    for name, free, current_ref, method in scenarios:
        interp = new_interp()
        calls = []
        # Tcl hands every argument over as a string, so the reference has to be
        # converted before it can be compared with the numeric object id.
        interp.createcommand("obj_valid", lambda r: int(r) == 33)
        interp.createcommand("call_method",
                            lambda o, m, *a: calls.append(("call_method", m)) or 1)
        interp.createcommand("get_objclass", lambda r: "Feuerstelle")
        interp.createcommand("get_ref", lambda o: 7)

        def prod_guest(op, place, seat=None, *rest):
            calls.append(("prod_guest", op, str(place), str(seat)))
            if op == "guestfree":
                return free[0] if free else -1
            return ""

        interp.createcommand("prod_guest", prod_guest)
        set_state(interp, dict(
            sparetime_current_place=0, sparetime_current_place_ref=current_ref,
            sparetime_seat=0, sparetime_reservation=0,
        ))
        interp.eval(chunk)
        result = interp.eval("sparetime_check_in %d %d" % (33, method))
        rows.append({
            "name": name,
            "method": method,
            "expected_result": result,
            "expected_calls": calls,
            "expected_place_ref": interp.getvar("sparetime_current_place_ref"),
            "expected_place_class": interp.getvar("sparetime_current_place"),
            "expected_seat": interp.getvar("sparetime_seat"),
        })
    return rows, chunk


def place_find_cases(data: Path) -> tuple:
    """sparetime_place_find judgement: path cost, recent-place penalty, favourites."""
    text = read_tcl(data, "Scripts/classes/zwerg/z_spare_fun.tcl")
    chunk = strip_comments(extract_proc(text, "sparetime_place_find"))
    rows = []
    scenarios = [
        # recent place names, favourite places, place position, place class
        ([], [], (0, 0), "Bar"),
        (["pub"], [], (0, 0), "Bar"),
        (["pub", "pub"], [], (0, 0), "Bar"),
        ([], ["pub"], (0, 0), "Bar"),
        ([], [], (10, 5), "Bar"),
        ([], [], (0, 0), "Bar"),
    ]
    for recent, favourites, position, place_class in scenarios:
        interp = new_interp()
        interp.eval(strip_comments(extract_proc(text, "sparetime_translate_name")))
        calls = []
        interp.createcommand("sparetime_searchrange", lambda: 160.0)
        interp.createcommand("sparetime", lambda *a: "55")
        interp.createcommand("obj_query", lambda *a: "55")
        interp.createcommand("get_prod_pack", lambda p: 0)
        interp.createcommand("get_posx", lambda o: 0 if o == "this" else position[0])
        interp.createcommand("get_posy", lambda o: 0 if o == "this" else position[1])
        interp.createcommand("get_objclass", lambda o: place_class)
        interp.createcommand("get_prod_materialneed", lambda p: 0)

        def place_call_method(place, method, *rest):
            calls.append(("call_method", method))
            if method == "ask_seat_cnt":
                return 3
            if method == "get_inactive":
                return 0
            return 1

        interp.createcommand("call_method", place_call_method)
        interp.createcommand("check_method", lambda o, m: 0)
        interp.createcommand("prod_guest", lambda op, p, *a: 0)
        interp.createcommand("get_prodautoschedule", lambda o: 1)
        set_state(interp, dict(
            current_occupation="fun", sparetime_current_place=0,
            sparetime_recent_places=recent, sparetime_avoid_place={0, 0.0},
            stt_maxsearch_range=160.0, spt_favplaces=favourites,
            spt_place_desire=50.0, spt_placefind_counter=1, reprod_partner=0,
            sparetime_current_place_ref=0, sparetime_seat=0, sparetime_reservation=0,
        ))
        interp.eval(chunk)
        result = interp.eval("sparetime_place_find")
        rows.append({
            "recent_places": recent,
            "fav_places": favourites,
            "position": list(position),
            "place_class": place_class,
            "expected_result": result,
        })
    return rows, chunk


# --------------------------------------------------------------------------- #
# 8. taste / disappointment helpers
# --------------------------------------------------------------------------- #
def taste_cases(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_spare_procs.tcl")
    exec_taste = strip_comments(extract_proc(text, "sparetime_exec_taste"))
    taste_wish = strip_comments(extract_proc(text, "sparetime_taste_wish"))
    eat_judge = strip_comments(extract_proc(text, "sparetime_eat_judge"))
    rows = []
    aftertaste_cases = [
        [0.0, 0.0, 0.0, 0.0],
        [0.1, 0.2, 0.3, 0.4],
        [0.25, 0.25, 0.25, 0.25],
        [0.6, 0.1, 0.2, 0.1],
    ]
    for aftertaste in aftertaste_cases:
        for tastelist in [[0.05, 0.05, 0.0, 0.05], [0.12, 0.01, 0.08, 0.0], [0.0, 0.0, 0.0, 0.0]]:
            interp = new_interp()
            set_state(interp, dict(sparetime_aftertaste=aftertaste))
            interp.eval(exec_taste)
            interp.eval("sparetime_exec_taste {%s}" % " ".join(str(x) for x in tastelist))
            rows.append({
                "aftertaste": aftertaste,
                "tastelist": tastelist,
                "expected_aftertaste": interp.getvar("sparetime_aftertaste"),
            })
    wish_rows = []
    for aftertaste in aftertaste_cases:
        interp = new_interp()
        set_state(interp, dict(sparetime_aftertaste=aftertaste))
        interp.eval(taste_wish)
        wish_rows.append({"aftertaste": aftertaste,
                          "expected": interp.eval("sparetime_taste_wish")})
    judge_rows = []
    for taste, civ, count in [(0.0, 0.0, 0), (0.11, 0.5, 0), (0.11, 0.5, 2),
                              (0.22, 1.0, 0), (0.05, 2.0, 1)]:
        interp = new_interp()
        set_state(interp, dict(civ_state=civ, sparetime_recent_food=["Grillpilz"] * count))
        interp.eval(eat_judge)
        judge_rows.append({
            "taste": taste, "civ_state": civ, "recent_count": count,
            "expected": interp.eval("sparetime_eat_judge %s Grillpilz" % taste),
        })
    return rows, wish_rows, judge_rows


def disapp_cases(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_spare_procs.tcl")
    set_disapp = strip_comments(extract_proc(text, "sparetime_set_disapp"))
    disappoint = strip_comments(extract_proc(text, "sparetime_disappoint"))
    rows = []
    for value in [0.0, 0.1, 0.5, 1.0, -0.5, -1.0]:
        interp = new_interp()
        set_state(interp, dict(stt_disapp_max=0.2, stt_disapp_factor=0.3,
                               sparetime_disappointment=0.0))
        interp.eval(set_disapp)
        interp.eval("sparetime_set_disapp %s" % value)
        rows.append({"value": value,
                     "expected": interp.getvar("sparetime_disappointment")})
    decay_rows = []
    for rate in [0, 1, 3]:
        interp = new_interp()
        mood = [0.5]
        # Tcl hands the stub the attribute delta as a string; the real
        # add_attrib applies it numerically, so the stub converts first.
        interp.createcommand(
            "add_attrib",
            lambda o, k, v: mood.__setitem__(0, mood[0] + float(v)) or "")
        set_state(interp, dict(sparetime_disappointment=0.09,
                               sparetime_disapp_rates=int(rate), this=7))
        interp.eval(disappoint)
        interp.eval("sparetime_disappoint")
        decay_rows.append({"rates": rate,
                           "input_disappointment": 0.09,
                           "expected_disappointment": interp.getvar("sparetime_disappointment"),
                           "expected_rates": interp.getvar("sparetime_disapp_rates"),
                           "expected_mood": mood[0]})
    return rows, decay_rows


def variety_cases(data: Path) -> tuple:
    main = read_tcl(data, "Scripts/classes/zwerg/z_spare_main.tcl")
    eat_variety = strip_comments(extract_proc(main, "sparetime_eat_variety"))
    place_variety = strip_comments(extract_proc(main, "sparetime_place_variety"))
    rows = []
    for recent in [[], ["Grillpilz"], ["Grillpilz", "Grillpilz", "Raupensuppe"]]:
        interp = new_interp()
        set_state(interp, dict(funloss_eatvariety=0.2, sparetime_recent_food=recent,
                               sparetime_eatclasses=["Grillpilz", "Grillhamster",
                                                     "Pilzbrot", "Raupensuppe",
                                                     "Raupenschleimkuchen",
                                                     "Gourmetsuppe", "Hamstershake"]))
        interp.eval(eat_variety)
        interp.eval("sparetime_eat_variety")
        rows.append({"recent_food": recent,
                     "expected": interp.getvar("funloss_eatvariety")})
    place_rows = []
    for recent in [[], ["pub"], ["pub", "pub", "dsc"]]:
        interp = new_interp()
        set_state(interp, dict(funloss_placevariety=0.2, sparetime_recent_fun=recent,
                               spt_favplaces=["pub", "bwl"]))
        interp.eval(place_variety)
        interp.eval("sparetime_place_variety")
        place_rows.append({"recent_fun": recent,
                           "expected": interp.getvar("funloss_placevariety")})
    return rows, place_rows


# --------------------------------------------------------------------------- #
# 9. fun station bit masks
# --------------------------------------------------------------------------- #
def fun_cases(data: Path) -> tuple:
    text = read_tcl(data, "Scripts/classes/zwerg/z_spare_fun.tcl")
    fun_check = strip_comments(extract_proc(text, "sparetime_fun_check"))
    fun_entry = strip_comments(extract_proc(text, "sparetime_fun_entry"))
    history = strip_comments(extract_proc(text, "sparetime_check_funhistory"))
    check_rows = []
    for gnome, places, partner, distance in [
        (1, [], 0, 0), (0, [], 0, 0), (1, ["fun"], 0, 0),
        (1, ["fun", "home"], 0, 0), (1, ["fun", "home", "sex"], 3, 100),
    ]:
        interp = new_interp()
        interp.createcommand("sparetime_searchrange", lambda: 160.0)
        interp.createcommand("obj_query", lambda *a: "9" if gnome else "0")
        interp.createcommand("sparetime", lambda *a: "55" if a[2] in places else "")
        interp.createcommand("dist_between", lambda a, b: distance)
        set_state(interp, dict(reprod_partner=partner, spt_fun_stations=0))
        interp.eval(fun_check)
        check_rows.append({"gnome": gnome, "places": places, "partner": partner,
                           "distance": distance,
                           "expected": interp.eval("sparetime_fun_check")})
    entry_rows = []
    for name in ["talk", "place", "home", "sex", "prtn", "none", "self"]:
        interp = new_interp()
        calls = []
        interp.createcommand("gettime", lambda: 500.0)
        set_state(interp, dict(sparetime_fun_history=[], spt_fun_stations=0,
                               spt_fun_fail=0, spt_last_place=0.0, spt_place_desire=1.0))
        interp.eval(fun_entry)
        interp.eval("sparetime_fun_entry %s" % name)
        entry_rows.append({"name": name,
                           "expected_history": interp.getvar("sparetime_fun_history"),
                           "expected_stations": interp.getvar("spt_fun_stations"),
                           "expected_fail": interp.getvar("spt_fun_fail")})
    history_rows = []
    for name, count in [("talk", 1), ("place", 1), ("talk", 3)]:
        interp = new_interp()
        set_state(interp, dict(sparetime_fun_history=["talk", "place", "talk"]))
        interp.eval(history)
        history_rows.append({"name": name, "count": count,
                             "expected": int(interp.eval("sparetime_check_funhistory %s %d" % (name, count)))})
    return check_rows, entry_rows, history_rows


# --------------------------------------------------------------------------- #
# build
# --------------------------------------------------------------------------- #
def build(data: Path) -> dict:
    sources = {}
    for relative in SOURCES:
        sources[relative] = hashlib.sha256((data / relative).read_bytes()).hexdigest()

    tunes = parse_tunes(read_tcl(data, "Scripts/misc/sparetimetunes.tcl"))
    attribs = read_tcl(data, "Scripts/misc/genattribs.tcl")
    defaults = {}
    for key, name in [("hitpoints", "atr_Hitpoints"), ("nutrition", "atr_Nutrition"),
                      ("alertness", "atr_Alertness"), ("mood", "atr_Mood")]:
        match = re.search(r"^def_attrib %s\s+0\s+1\s+([\d.]+)" % name, attribs, re.M)
        defaults[key] = float(match.group(1))

    doubles = double_strings(data)
    futures, future_block = future_plans(data)
    decide_rows, decide_source = decide_occup(data)
    auto_rows, auto_source = work_auto_cases(data)
    dispatch_rows, dispatch_source = work_dispatch_cases(data)
    idle_rows, idle_source = work_idle_cases(data)
    switch_rows = work_plan_switch_cases(data)
    enter_leave_rows = work_enter_leave_cases(data)
    rotate_rows, rotate_source = rotate_cases(data)
    stop_rows, stop_source = stop_prod_cases(data)
    checkin_rows, checkin_source = check_in_cases(data)
    place_find_rows, place_find_source = place_find_cases(data)
    taste_rows, wish_rows, judge_rows = taste_cases(data)
    disapp_rows, decay_rows = disapp_cases(data)
    eat_variety_rows, place_variety_rows = variety_cases(data)
    fun_check_rows, fun_entry_rows, fun_history_rows = fun_cases(data)

    return tcl_value({
        "schema": "diggles.dwarf_sparetime.v1",
        "sources": sources,
        "defaults": defaults,
        "constants": tunes,
        "double_strings": doubles,
        "future_plan": futures,
        "future_plan_source": future_block,
        "decide_occup": decide_rows,
        "decide_occup_source": decide_source,
        "work_auto": auto_rows,
        "work_auto_source": auto_source,
        "work_dispatch": dispatch_rows,
        "work_dispatch_source": dispatch_source,
        "work_idle": idle_rows,
        "work_idle_source": idle_source,
        "work_plan_switch": switch_rows,
        "work_enter_leave": enter_leave_rows,
        "rotate": rotate_rows,
        "rotate_source": rotate_source,
        "stop_prod": stop_rows,
        "stop_prod_source": stop_source,
        "check_in": checkin_rows,
        "check_in_source": checkin_source,
        "place_find": place_find_rows,
        "place_find_source": place_find_source,
        "taste": taste_rows,
        "taste_wish": wish_rows,
        "eat_judge": judge_rows,
        "set_disapp": disapp_rows,
        "disappoint": decay_rows,
        "eat_variety": eat_variety_rows,
        "place_variety": place_variety_rows,
        "fun_check": fun_check_rows,
        "fun_entry": fun_entry_rows,
        "fun_history": fun_history_rows,
        "limits": [
            "The decision oracle drives the original sparetime_decide_occup with stubbed "
            "eat/ill checks; real food objects and hospitals are not part of the port.",
            "Place registry oracle covers the guest seat bookkeeping only; native "
            "prod_guest seat objects and walk_dummy routes are host concerns.",
            "Work state oracle records stubbed calls; production item graphs and the "
            "clan job registry are outside this export.",
            "sparetime_talk, sparetime_reprod and the fun station bit masks are covered "
            "only where the dispatcher touches them.",
        ],
    })


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    parser.add_argument("--data", type=Path, default=DEFAULT_DATA)
    args = parser.parse_args()
    document = build(args.data)
    raw = (json.dumps(document, indent=2) + "\n").encode("utf-8")
    out = PROJECT / "godot/models/native_dwarf_sparetime.json"
    if args.check:
        if out.read_bytes() != raw:
            raise ValueError("Dwarf sparetime source contract changed")
    else:
        out.write_bytes(raw)
    print(json.dumps({
        "ok": True,
        "check": args.check,
        "constants": len(document["constants"]),
        "decide": len(document["decide_occup"]),
        "work": len(document["work_auto"]) + len(document["work_dispatch"]) + len(document["work_idle"]),
        "place": len(document["check_in"]) + len(document["place_find"]),
    }))


if __name__ == "__main__":
    main()
