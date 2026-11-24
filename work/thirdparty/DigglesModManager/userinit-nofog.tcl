# ---------------------------------------------------------------------------
# Diggles - remove the BLACK fog of war (the not-yet-explored regions).
#
# The regular haze/shroud that lies over the map wherever no gnome or
# building stands right now is NOT touched - it stays exactly as it is.
#
# Engine facts (reverse engineered, see
# docs/reverse-engineering/agent-result-fogofwar-2026-11-22.md):
#
#   The fog state is one byte per (owner x map cell), the cell is 8x8 world
#   units. Cell byte offset: cell + 0x34 + owner.
#     0x00 = never explored  -> black fog
#     0x01 = explored, but as dark as possible -> the haze (this is the floor
#            that CFogOfWar::FadeBlocks clamps to, it subtracts 4 per frame)
#     0xFF = fully lit
#
#   There is a SECOND state per cell: a 4 bit field per owner at cell + 8
#   (8 owners x 4 bits = one dword) - the height of the fog volume over that
#   cell. A cell whose volume is still there is drawn BLACK, a cell whose
#   volume was removed by CFogOfWar::NewVisibleBlock is drawn, and the byte
#   above only says how BRIGHT it is drawn.
#
#   remove_black_fog <owner> <x0> <y0> <x1> <y1>      handler 0x0066AEC0
#     For every cell of the rectangle whose byte is 0 the byte becomes 1.
#     It does NOT touch the fog volume -> the ground stays BLACK. That is why
#     the black fog did not disappear with it.
#
#   set_fow_begin <y> [owner]                        handler 0x0064B380
#     -> FUN_00580610: for every cell below the frontier whose byte is 0 it
#     calls FUN_0057DFC0 (NewVisibleBlock - the fog volume over that cell is
#     removed, THE CELL BECOMES VISIBLE) and then sets the byte to 0xFF.
#
#   The byte 0xFF would light the whole map up, so Diggles.exe is patched:
#   one instruction in FUN_00580610 (VA 0x005807B2, file offset 0x0017FBB2)
#   writes 0x01 instead of 0xFF -> every cell ends up "explored, but as dark
#   as possible", i.e. the normal haze. No black areas, haze stays.
#   Patch script: work/thirdparty/DigglesModManager/patch-fogbyte.py
#
# WHERE THE MAP OF A LEVEL IS CREATED (the important part)
#
#   The menu map:   "map create 64 64 { }"          (systeminit.tcl:64)
#   The LEVEL map:   "sm_create_map 512 640"        (CampaignInit.tcl:34)
#                    -> CTclGlobalMethods::SMCreateMap, handler 0x0065F430
#   The level is started by the story manager:
#                    call_method $sm load_level Campaign
#                    -> story.tcl:1139 load_level ->
#                       call "scripts/gameplay/CampaignInit.tcl"
#
#   An earlier version of this script only hooked "map create", so the
#   level map was never touched - that is why the black fog stayed.
#
# WRAPPING RULES (learned the hard way, versions 2-5 killed the game):
#   The engine has exactly ONE entry point into Tcl - FUN_006BC2C0 ->
#   Tcl_EvalObjEx(interp, obj, flags = 0) - and it evaluates script text in
#   the CURRENT call frame. A wrapper proc becomes that frame, so a wrapped
#   command must NOT be able to reach that evaluation, otherwise the game
#   scripts get their global variables in the wrong scope.
#   Verified with work/tmp_re/reach.py (transitive call graph):
#     UNSAFE - do not wrap: call (0x006313A0), call_method (0x00626970),
#     call_method_static, update_objdetail (0x006647D0), gameload (0x006310F0),
#     gamesave (0x00630EB0), sm_add_temp (0x0065CBA0),
#     sm_get_level_info (0x00661340)
#     SAFE: everything in the list at the bottom of this file.
#
# VERSION HISTORY
#   v10 (2026-11-23) - first run: the game crashed during start up.
#     Cause (my bug, see tclerrors.txt): every generated wrapper stored the
#     name of the original command in the GLOBAL variable nofog_orig_name.
#     A nested wrapper call (obj_query called from the probe while load_info
#     was running) overwrote it, so load_info then called
#     "__nofog_orig_obj_query {Classes done}" -> "invalid arg count" -> the
#     game script was aborted in the middle of the start up.
#   v11 (2026-11-23) - fixes:
#     * the original command name is written into the wrapper body literally,
#       no shared global -> nested calls cannot break each other;
#     * the generic wrappers ONLY write the first call into the log, they do
#       not run the probe any more (no engine command is called from inside a
#       wrapped engine command);
#     * the probe/heartbeat only runs when the level is really running
#       (nofog_ready) and only from the Tcl timer.
# ---------------------------------------------------------------------------

set ::nofog_log ""
catch {set ::nofog_log [open "diggles_nofog.log" w]}
catch {fconfigure $::nofog_log -translation lf -encoding ascii}

proc nofog_log {msg} {
    global nofog_log
    if {[string length $nofog_log] > 0} {
        catch {puts $::nofog_log $msg}
        catch {flush $::nofog_log}
    }
}

# the player is owner 0
set ::nofog_owner 0
set ::nofog_count 0
# nofog_seen_cmd is an ARRAY: nofog_seen_cmd(<command>) = 1 when it was seen
# (it is never created as a scalar, so no unset -nocomplain is needed)
# heartbeat state
set ::nofog_last 0
# 1 as soon as a level is really being set up - before that no engine command
# may be called from this script (the game is still in its start up phase and
# a failing command there aborts the game scripts)
set ::nofog_ready 0
# re-entrancy guard
set ::nofog_busy 0

# Reveal the map for the player: register every cell as visible (the fog
# volume over it is removed) and leave it dark - with the patched engine the
# byte becomes 1 = "explored, as dark as possible" = the normal haze.
proc nofog_reveal {ctx} {
    global nofog_count nofog_owner
    set w "?"
    set h "?"
    catch {set w [get_map_width]}
    catch {set h [get_map_height]}
    if {[catch {set_fow_begin 999999 $nofog_owner} e]} {
        nofog_log "$ctx: set_fow_begin FAILED: $e (map=${w}x${h})"
        return 0
    }
    incr nofog_count
    nofog_log "$ctx: set_fow_begin ok  n=$nofog_count  map=${w}x${h}"
    # objective check right after the reveal: the fog byte of a gnome of
    # another owner. 0 = still black, 1 = explored but dark (the haze),
    # 255 = lit.
    catch {nofog_probe "$ctx after"}
    return 1
}

# Objective reading of the fog state: the fog byte of the player (owner 0) at
# the position of a gnome of another owner. 0 = black fog, 1 = explored but
# dark (the haze), 255 = lit. The smallest value over all foreign gnomes is
# used - a foreign gnome stands far away from the player, so its cell is the
# one that is still black.
proc nofog_probe {ctx} {
    global nofog_owner
    set minv 255
    set found 0
    foreach q {{-class Zwerg -owner 1} {-class Zwerg -owner 2} \
               {-class Zwerg -owner 3} {-class Zwerg -owner 4} \
               {-class Zwerg -owner 5} {-class Zwerg -owner 6}} {
        set g [obj_query 0 $q -limit 1]
        if {$g == "" || $g == 0} { continue }
        if {[catch {set v [get_max_fow $g $nofog_owner]}]} { continue }
        set found 1
        if {$v < $minv} { set minv $v }
    }
    if {!$found} {
        nofog_log "$ctx: probe: no foreign gnome found"
        return 255
    }
    nofog_log "$ctx: probe: min fow(owner $nofog_owner)=$minv"
    return $minv
}

# Repeated check while the level runs: a level that was started from a saved
# game restores the map and the fog without any map creation command, so the
# reveal has to be repeated - but only when the fog is really black again,
# otherwise the map would stay bright.
proc nofog_heartbeat {ctx} {
    global nofog_last nofog_ready nofog_busy
    if {!$nofog_ready} { return }
    if {$nofog_busy} { return }
    set now [clock seconds]
    if {$now - $nofog_last < 3} { return }
    set nofog_last $now
    set nofog_busy 1
    catch {set v [nofog_probe $ctx]}
    set nofog_busy 0
    if {[info exists v] && $v == 0} {
        catch {nofog_reveal "$ctx (black fog back)"}
    }
}

# Backup heartbeat through the Tcl timer. The wrapper heartbeat only ran when
# the engine happened to call one of the wrapped commands, and during a
# running level that may never happen. The timer only works if the engine
# pumps the Tcl event loop - if it does not, nothing happens (no harm).
proc nofog_timer {} {
    catch {nofog_heartbeat "after"}
    catch {after 3000 nofog_timer}
}

nofog_log "== nofog userinit loaded =="
nofog_log "patchlevel=[info patchlevel]"

# --- 1) map: the menu map and the map of a plain level --------------------
if {![catch {rename map __nofog_map_orig}]} {
    proc map {args} {
        set cmd [linsert $args 0 __nofog_map_orig]
        if {[lindex $args 0] == "create"} {
            if {[catch {eval $cmd} res]} { return -code error $res }
            set ::nofog_ready 1
        catch {nofog_view_start}
            catch {nofog_reveal "map create"}
            return $res
        }
        eval $cmd
    }
    nofog_log "hook map: ok"
} else {
    nofog_log "hook map: FAILED"
}

# --- 2) sm_create_map: THE MAP OF THE STORY LEVEL -------------------------
if {![catch {rename sm_create_map __nofog_sm_create_map_orig}]} {
    proc sm_create_map {args} {
        set cmd [linsert $args 0 __nofog_sm_create_map_orig]
        if {[catch {eval $cmd} res]} { return -code error $res }
        set ::nofog_ready 1
        catch {nofog_view_start}
        catch {nofog_reveal "sm_create_map"}
        return $res
    }
    nofog_log "hook sm_create_map: ok"
} else {
    nofog_log "hook sm_create_map: FAILED"
}

# --- 3) show_loading: right before the level starts ------------------------
if {![catch {rename show_loading __nofog_show_loading_orig}]} {
    proc show_loading {args} {
        set cmd [linsert $args 0 __nofog_show_loading_orig]
        if {[catch {eval $cmd} res]} { return -code error $res }
        set ::nofog_ready 1
        catch {nofog_view_start}
        catch {nofog_heartbeat "show_loading"}
        return $res
    }
    nofog_log "hook show_loading: ok"
} else {
    nofog_log "hook show_loading: FAILED"
}

# --- 4) load_done: a save was loaded, the old (black) fog is back ---------
# The loader runs in C++ (FUN_00556570) and the Tcl command "load_done" is
# called afterwards, so this is the first moment at which the restored map can
# be revealed again.
if {![catch {rename load_done __nofog_load_done_orig}]} {
    proc load_done {args} {
        set cmd [linsert $args 0 __nofog_load_done_orig]
        if {[catch {eval $cmd} res]} { return -code error $res }
        set ::nofog_ready 1
        catch {nofog_view_start}
        catch {nofog_reveal "load_done (save loaded)"}
        return $res
    }
    nofog_log "hook load_done: ok"
} else {
    nofog_log "hook load_done: FAILED"
}

# --- 5) reset_map: story / skirmish transitions ---------------------------
if {![catch {rename reset_map __nofog_reset_map_orig}]} {
    proc reset_map {args} {
        set cmd [linsert $args 0 __nofog_reset_map_orig]
        if {[catch {eval $cmd} res]} { return -code error $res }
        set ::nofog_ready 1
        catch {nofog_view_start}
        catch {nofog_reveal "reset_map"}
        return $res
    }
    nofog_log "hook reset_map: ok"
} else {
    nofog_log "hook reset_map: FAILED"
}

# --- 6) gameload: DEAD CODE, NOT WRAPPED -----------------------------------
# The GUI loads a saved game directly in C++ (the loader FUN_00556570 is
# called from 0x0053F27D and 0x005418B5), the Tcl command "gameload" has
# no caller at all - so hooking it would do nothing. It is also the only
# way to reach a Tcl evaluation from the load path (in the AI
# interpreter), so it must not be wrapped.

# --- 7) generic wrappers: write the first call into the log ----------------
# The body of the generated wrapper is built as a STRING, so every "[" has
# to be escaped as "\[" - otherwise Tcl would run it as a command
# substitution while the body is being built.
#
# The name of the original command is written INTO the body (not into a
# global variable) - otherwise a nested wrapper call would overwrite it and
# the outer wrapper would call the wrong command (this was the crash of v10).
#
# These wrappers do nothing else: they must not call engine commands, the
# game script would be aborted if that fails.
proc nofog_pre {name args} {
    global nofog_seen_cmd
    if {![info exists nofog_seen_cmd($name)]} {
        set nofog_seen_cmd($name) 1
        nofog_log "HOOK $name: $args"
    }
}

proc nofog_wrap {name} {
    set orig "__nofog_orig_$name"
    if {[catch {rename $name $orig}]} { return 0 }
    set body "catch \{nofog_pre $name \$args\}\n"
    append body "eval \[concat \[list $orig\] \$args\]\n"
    catch {uplevel "proc $name {args} {$body}"}
    return 1
}

foreach c {sm_map_set sm_map_get sm_set_temp sm_set_digcount \
           sm_scan sm_log sm_get_event sm_set_event sm_add_event \
           sm_reset obj_query timer_event gametime get_local_player gettime \
           playerinfo send_trigger newsticker obj_list load_info \
           gameisloading set_ingame_loading template_set autoloadlevel \
           gui_new_game show_maped} {
    if {[nofog_wrap $c]} {
        nofog_log "hook $c: ok"
    } else {
        nofog_log "hook $c: FAILED"
    }
}

# start the backup heartbeat
if {![catch {after 3000 nofog_timer}]} {
    nofog_log "backup heartbeat: after 3000 started"
} else {
    nofog_log "backup heartbeat: FAILED"
}

# ---------------------------------------------------------------------------
# v13 (2026-11-24) - DIAGNOSTIC: logger of the camera view.
#
# Symptom: at a very large zoom-out (our patch raises the engine limit from
# 2.5 to 16) the whole screen turns black on the next wheel click.
#
# What we need to know: what the view actually looks like at that moment.
# The Tcl command "get_view" returns {x y zoom pers1 pers2} - the camera
# position, the zoom and the TWO perspective angles. The zoom is clamped in
# the engine (CGameThread::Draw), the perspective angles are CRUSHED to
# ~0.7/(zoom^2-2) rad, i.e. to almost exactly 0 at zoom 16 - and a renderer
# that divides by that angle would produce a degenerate view (black screen).
#
# The logger writes to "diggles_view.log" (game folder) and only when the
# zoom changed or every 2 seconds, so the file stays small.
# ---------------------------------------------------------------------------
set ::nofog_viewlog ""
catch {set ::nofog_viewlog [open "diggles_view.log" w]}
catch {fconfigure $::nofog_viewlog -translation lf -encoding ascii}

proc nofog_view_write {msg} {
    global nofog_viewlog
    if {[string length $::nofog_viewlog] > 0} {
        catch {puts $::nofog_viewlog $msg}
        catch {flush $::nofog_viewlog}
    }
}

set ::nofog_view_lastzoom ""
set ::nofog_view_lasttime 0
set ::nofog_view_started 0

proc nofog_view_log_now {} {
    global nofog_view_lastzoom nofog_view_lasttime
    set now [clock seconds]
    catch {
        set v [get_view]
        set z [lindex $v 2]
        set changed 0
        if {$z != $::nofog_view_lastzoom} { set changed 1 }
        if {$now - $::nofog_view_lasttime >= 2} { set changed 1 }
        if {$changed} {
            set ::nofog_view_lastzoom $z
            set ::nofog_view_lasttime $now
            # fog state at the same moment: 255 = no black fog, 0 = black fog
            set fv "?"
            if {$::nofog_ready} {
                catch {set fv [nofog_probe "view"]}
            }
            nofog_view_write "[clock seconds] x=[lindex $v 0] y=[lindex $v 1] zoom=$z pers1=[lindex $v 3] pers2=[lindex $v 4] fog=$fv raw=[join $v |]"
        }
    }
}

# The tasklist of an object is executed by the engine on its tick - that is the
# ONLY periodic mechanism the game has (the game scripts never use "after", and
# the Tcl event loop is not pumped, so "after" never fires - proved: an "after"
# based logger produced an empty file).
proc nofog_view_tick {} {
    global nofog_view_gnome
    # re-queue on the SAME object (not via "this" - the task context may not
    # have "this", and two chains would double every tick)
    if {$nofog_view_gnome != ""} {
        catch {tasklist_add $nofog_view_gnome "nofog_view_tick"}
    }
    catch {nofog_view_log_now}
}

proc nofog_view_start {} {
    global nofog_view_started nofog_view_gnome
    if {$nofog_view_started} { return }
    set g ""
    catch {set g [obj_query 0 "-class Zwerg -owner 0 -limit 1]}
    if {$g == "" || $g == 0} {
        nofog_view_write "[clock seconds] view logger: no player gnome yet"
        return
    }
    set nofog_view_gnome $g
    if {[catch {tasklist_add $g "nofog_view_tick"} err]} {
        nofog_view_write "[clock seconds] view logger: tasklist_add failed: $err"
        return
    }
    set nofog_view_started 1
    nofog_view_write "[clock seconds] view logger started on gnome $g"
}

# fallback (the engine may or may not pump the Tcl event loop)
proc nofog_view_timer {} {
    global nofog_view_lastzoom nofog_view_lasttime
    catch {after 250 nofog_view_timer}
    catch {nofog_view_log_now}
}

if {![catch {after 250 nofog_view_timer}]} {
    nofog_log "view logger: after 250 started"
} else {
    nofog_log "view logger: FAILED"
}

nofog_log "== end =="
