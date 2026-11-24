#!/usr/bin/env python3
"""tclcheck.py - offline syntax/behaviour check of data/userinit.tcl.

The game needs ~2.5 minutes to boot, so the Tcl mod is checked offline
first: a bare Tcl interpreter (tkinter) gets stub commands for everything
the mod touches, the mod is sourced, and then the hooks are exercised.

Usage:  python tclcheck.py <path-to-userinit.tcl>
Exit code 0 = all checks passed.
"""
import os
import sys
import tkinter

STUBS = """
# --- stub commands the mod renames or calls -------------------------------
proc map {args} {
    if {[lindex $args 0] == "getoffset"} { return {10 20} }
    if {[lindex $args 0] == "create"} { return "" }
    return ""
}
proc sm_create_map {args} { return "" }
proc show_loading {args} { return "" }
proc reset_map {args} { return "" }
proc gameload {args} { return "" }
proc get_map_width {} { return 512 }
proc get_map_height {} { return 512 }
proc set_fow_begin {y {owner 0}} {
    lappend ::calls "set_fow_begin $y $owner"
    return ""
}
proc get_max_fow {obj {owner 0}} { return 1 }
proc obj_query {args} {
    # the real command is "obj_query <player> <query> -limit <n>" (4 words);
    # the v10 bug called it with a single word -> that must fail here
    if {[llength $args] < 2} { error "invalid arg count" }
    lappend ::calls "obj_query $args"
    return {1 2 3}
}
# load_info is called by the game with one argument and it calls another
# command that the mod wraps - that is the situation that broke v10.
proc load_info {msg} {
    lappend ::calls "load_info-orig $msg"
    obj_query 0 {-class Zwerg -owner 1} -limit 1
    return ""
}
proc call_method {args} { return "cm-result" }
proc sm_map_set {args} { return "" }
proc sm_map_get {args} { return {5 6} }
proc sm_get_event {args} { return 0 }
proc timer_event {args} { return "" }
proc gametime {args} { return "" }
proc load_done {args} { return "" }
proc playerinfo {args} { return "" }
proc get_local_player {} { return 0 }
proc newsticker {args} { return "" }
proc obj_list {args} { return "" }
proc send_trigger {args} { return "" }
proc gameisloading {} { return 0 }
proc gamesave {args} { return "" }
proc set_ingame_loading {args} { return "" }
proc template_set {args} { return "" }
proc autoloadlevel {args} { return "" }
proc gui_new_game {args} { return "" }
proc show_maped {args} { return "" }
proc sm_log {args} { return "" }
proc sm_get_level_info {args} { return "" }
proc sm_set_digcount {args} { return "" }
proc sm_scan {args} { return "" }
proc sm_set_event {args} { return "" }
proc sm_add_event {args} { return "" }
proc sm_add_temp {args} { return "" }
proc sm_reset {args} { return "" }
proc sm_set_temp {args} { return "" }
proc sm_map_move {args} { return "" }
proc gettime {} { return 0.0 }
set ::calls {}
"""

FAIL = []


def check(name, cond, detail=""):
    if cond:
        print("  OK   %s" % name)
    else:
        print("  FAIL %s %s" % (name, detail))
        FAIL.append(name)


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    path = os.path.abspath(sys.argv[1])
    workdir = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "..")
    workdir = os.path.abspath(workdir)
    scratch = os.path.join(workdir, "work", "tclcheck")
    os.makedirs(scratch, exist_ok=True)
    os.chdir(scratch)

    root = tkinter.Tcl()
    root.eval(STUBS)

    print("== source %s ==" % path)
    with open(path, "r", encoding="utf-8", errors="replace") as fh:
        src = fh.read()

    complete = root.eval("info complete {%s}" % src)
    check("script is syntactically complete", complete in (1, "1"), "(got %r)" % complete)

    try:
        root.eval(src)
        print("  OK   script sourced without error")
    except Exception as exc:  # tkinter.TclError
        print("  FAIL script raised: %s" % exc)
        FAIL.append("source")
        return 1

    # 1) every hook must be installed
    names = ["map", "sm_create_map", "show_loading", "reset_map",
             "obj_query", "sm_get_event", "sm_map_set"]
    for n in names:
        cmds = root.eval("info commands %s" % n).split()
        check("hook installed: %s" % n, n in cmds, "(commands: %s)" % cmds)

    # 1b) SAFETY: commands that can reach a Tcl evaluation must NOT be
    #     wrapped - a wrapper proc would become the frame in which the
    #     engine evaluates script text and break the scope of the game
    #     scripts (that killed the game in versions 2-5).
    for n in ("call", "call_method", "call_method_static", "update_objdetail",
              "gameload", "gamesave"):
        renamed = root.eval("info commands __nofog_orig_%s" % n).split()
        check("NOT wrapped (unsafe): %s" % n, not renamed, "(renamed: %s)" % renamed)

    # 2) calling a hooked command must reach the original
    root.eval("set ::calls {}")
    root.eval("map create 512 640")
    calls = root.eval("set ::calls")
    check("map create reaches set_fow_begin",
          "set_fow_begin" in calls, "(calls: %s)" % calls)

    # 3) sm_create_map (the LEVEL map) must reach remove_black_fog
    root.eval("set ::calls {}")
    root.eval("sm_create_map 512 640")
    calls = root.eval("set ::calls")
    check("sm_create_map reaches set_fow_begin",
          "set_fow_begin" in calls, "(calls: %s)" % calls)

    # 4) multi value result must survive the wrapper (map getoffset)
    res = root.eval("map getoffset").split()
    check("map getoffset keeps 2 values", len(res) >= 2, "(got %r)" % res)

    # 5) a generic wrapper keeps the result of the original
    res = root.eval("call_method 0 foo 1")
    check("call_method keeps result", res == "cm-result", "(got %r)" % res)
    res = root.eval("obj_query 0 -class Zwerg")
    check("obj_query keeps result", res == "1 2 3", "(got %r)" % res)

    # 6) the reveal uses the huge rectangle that the engine clips
    root.eval("set ::calls {}")
    root.eval("reset_map 0 0 10 10")
    calls = root.eval("set ::calls")
    check("reset_map reaches set_fow_begin",
          "set_fow_begin" in calls, "(calls: %s)" % calls)

    # 7) the reveal rectangle must be the huge one (engine clips it)
    root.eval("set ::calls {}")
    root.eval("map create 512 640")
    calls = root.eval("set ::calls")
    check("reveal uses set_fow_begin 999999 0",
          "set_fow_begin 999999 0" in calls, "(calls: %s)" % calls)

    # 8) NESTED wrapper calls must not break the outer wrapper.
    #     This is the bug that crashed the game in v10: every wrapper kept
    #     the name of its original in one shared global, so a nested call
    #     overwrote it and the outer wrapper called the wrong command.
    root.eval("set ::calls {}")
    # force the heartbeat to run (it is throttled by 3 seconds), so that the
    # nested call really happens in the versions that call it from a wrapper
    root.eval("catch {set ::nofog_last 0}")
    err = None
    try:
        root.eval('load_info "Classes done"')
    except Exception as exc:
        err = str(exc)
    check("nested wrapper call does not break the outer one",
          err is None, "(error: %s)" % err)
    calls = root.eval("set ::calls")
    check("outer wrapper called its own original",
          "load_info-orig Classes done" in calls, "(calls: %s)" % calls)

    # 9) a generic wrapper must not call engine commands by itself
    #     (a failing engine call inside a game script aborts the script)
    root.eval("set ::calls {}")
    root.eval("sm_map_set 1")
    calls = root.eval("set ::calls")
    check("generic wrapper calls no engine command",
          "obj_query" not in calls and "set_fow_begin" not in calls,
          "(calls: %s)" % calls)

    print("")
    if FAIL:
        print("FAILED: %s" % ", ".join(FAIL))
        return 1
    print("ALL CHECKS PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())
