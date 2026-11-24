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
#   remove_black_fog <owner> <x0> <y0> <x1> <y1>      handler 0x0066AEC0
#     For every cell of the rectangle whose byte is 0 the byte becomes 1.
#     Coordinates are map cells, the rectangle is clipped to the map by the
#     engine (start = max(mapCellX0, x0), end = min(mapCellX1, x1)).
#     *** BUT IT ONLY CHANGES THE BYTE - it does NOT register the cell as a
#     visible block, and the ground is drawn only for registered cells:
#     CScapeRenderer::RenderScape: "if (*(int *)(cell + 8 + owner*4) <=
#     threshold) break;"  => with remove_black_fog the ground stays BLACK.
#     That is why the black fog did not disappear with it.
#
#   set_fow_begin <y> [owner]                        handler 0x0064B380
#     -> FUN_00580610: for every cell below the frontier whose byte is 0 it
#     calls FUN_0057DFC0 (NewVisibleBlock - THE CELL BECOMES VISIBLE) and
#     then sets the byte to 0xFF ("fully lit"). Afterwards the engine's own
#     CFogOfWar::FadeBlocks fades the byte down (255 -> 1, four per frame)
#     and the map ends up as the normal "explored but dark" haze - which is
#     exactly what is wanted: no black areas, the haze stays.
# ---------------------------------------------------------------------------
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
# ---------------------------------------------------------------------------

set ::nofog_log ""
catch {set ::nofog_log [open "diggles_nofog.log" w]}
catch {fconfigure $::nofog_log -translation lf -encoding ascii}

proc nofog_log {msg} {
    global nofog_log
    if {[string length $nofog_log] > 0} {
        catch {puts $nofog_log $msg}
        catch {flush $nofog_log}
    }
}

# the player is owner 0
set ::nofog_owner 0
set ::nofog_count 0
# nofog_seen_cmd is an ARRAY: nofog_seen_cmd(<command>) = 1 when it was seen
# (it is never created as a scalar, so no unset -nocomplain is needed)

# heartbeat state
set ::nofog_last 0

# Reveal the map for the player: register every cell as visible and light it.
# The engine fades it back to the normal haze by itself.
proc nofog_reveal {ctx} {
    global nofog_count nofog_owner
    if {[catch {set_fow_begin 999999 $nofog_owner} e]} {
        nofog_log "$ctx: set_fow_begin FAILED: $e"
        return 0
    }
    incr nofog_count
    nofog_log "$ctx: set_fow_begin ok  n=$nofog_count"
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
    global nofog_last
    set now [clock seconds]
    if {$now - $nofog_last < 3} { return }
    set nofog_last $now
    set v [nofog_probe $ctx]
    if {$v == 0} {
        nofog_reveal "$ctx (black fog back)"
    }
}

nofog_log "== nofog userinit loaded =="
nofog_log "patchlevel=[info patchlevel]"

# --- 1) map: the menu map and the map of a plain level --------------------
if {![catch {rename map __nofog_map_orig}]} {
    proc map {args} {
        set cmd [linsert $args 0 __nofog_map_orig]
        if {[lindex $args 0] == "create"} {
            if {[catch {eval $cmd} res]} { return -code error $res }
            nofog_reveal "map create"
            return
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
        nofog_reveal "sm_create_map"
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
        nofog_heartbeat "show_loading"
        return $res
    }
    nofog_log "hook show_loading: ok"
} else {
    nofog_log "hook show_loading: FAILED"
}

# --- 4) reset_map: story / skirmish transitions ---------------------------
if {![catch {rename reset_map __nofog_reset_map_orig}]} {
    proc reset_map {args} {
        set cmd [linsert $args 0 __nofog_reset_map_orig]
        if {[catch {eval $cmd} res]} { return -code error $res }
        nofog_reveal "reset_map"
        return $res
    }
    nofog_log "hook reset_map: ok"
} else {
    nofog_log "hook reset_map: FAILED"
}

# --- 5) gameload: DEAD CODE, NOT WRAPPED -----------------------------------
# The GUI loads a saved game directly in C++ (the loader FUN_00556570 is
# called from 0x0053F27D and 0x005418B5), the Tcl command "gameload" has
# no caller at all - so hooking it would do nothing. It is also the only
# way to reach a Tcl evaluation from the load path (in the AI
# interpreter), so it must not be wrapped.

# --- 6) generic wrappers: log the first call, act as heartbeat ------------
# These commands are watched to find out what the engine does while a level
# runs and while a save is loaded. The first call of every one of them is
# written into the log.
#
# The body of the generated wrapper is built as a STRING, so every "[" has
# to be escaped as "\[" - otherwise Tcl would run it as a command
# substitution while the body is being built.
proc nofog_pre {name args} {
    global nofog_seen_cmd
    if {![info exists nofog_seen_cmd($name)]} {
        set nofog_seen_cmd($name) 1
        nofog_log "HOOK $name: $args"
    }
    nofog_heartbeat $name
}

proc nofog_wrap {name} {
    set orig "__nofog_orig_$name"
    if {[catch {rename $name $orig}]} { return 0 }
    set body "global nofog_orig_name\n"
    append body "set nofog_orig_name $orig\n"
    append body "nofog_pre $name \$args\n"
    append body "eval \[concat \[list \$nofog_orig_name\] \$args\]\n"
    catch {uplevel "proc $name {args} {$body}"}
    return 1
}

foreach c {sm_map_set sm_map_get sm_set_temp sm_set_digcount \
           sm_scan sm_log sm_get_event sm_set_event sm_add_event \
           sm_reset obj_query timer_event gametime get_local_player gettime \
           playerinfo send_trigger newsticker obj_list load_info load_done \
           gameisloading set_ingame_loading template_set autoloadlevel \
           gui_new_game show_maped} {
    if {[nofog_wrap $c]} {
        nofog_log "hook $c: ok"
    } else {
        nofog_log "hook $c: FAILED"
    }
}

nofog_log "== end =="
