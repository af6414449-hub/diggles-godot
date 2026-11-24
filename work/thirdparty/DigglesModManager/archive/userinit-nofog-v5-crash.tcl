# ---------------------------------------------------------------------------
# Diggles - remove the BLACK fog of war (the not-yet-explored regions).
#
# ARCHIVE COPY - VERSION v5 (23.11.2026, 02:01) - THIS VERSION CRASHES THE GAME.
# It is kept only as evidence for docs/reverse-engineering/agent-result-fogofwar-2026-11-22.md.
#
# Why it crashed: the "call" hook. The wrapper proc changes the scope in which
# the engine evaluates a loaded script, so every "call scripts/init/animinit.tcl"
# ran inside the wrapper proc. The global variables of the game scripts
# ("noidiobjclassescnt", "tttmaterial__Offen", ...) were then created in the
# wrapper's local scope instead of the global scope, which produced a storm of
# Tcl errors (tclerrors.txt, 54 KB) and an access violation in atidxx32.dll.
#
# The working version is userinit-nofog.tcl (v6): it hooks only "map",
# "show_loading" and "reset_map" - commands that do not evaluate game scripts.
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

# current map size in cells, 0 = no map yet
set ::nofog_w 0
set ::nofog_h 0
set ::nofog_count 0

# probe object + last measured fog value
set ::nofog_probe 0
set ::nofog_probe_val "?"
set ::nofog_probe_tick 0

proc nofog_apply {ctx} {
    global nofog_w nofog_h nofog_owner nofog_count
    if {$nofog_w <= 0 || $nofog_h <= 0} { return }
    if {[catch {remove_black_fog $nofog_owner 0 0 $nofog_w $nofog_h} e]} {
        nofog_log "$ctx: remove_black_fog FAILED: $e"
    } else {
        incr nofog_count
        nofog_log "$ctx: remove_black_fog ok  map=${nofog_w}x${nofog_h}  n=$nofog_count"
    }
}

# --- probe: read the fog byte of a far away cell --------------------------
# get_max_fow <obj> <owner> returns that owner's fog byte for the cell the
# object stands on (0 = black fog, 1 = explored but dark, 255 = lit).
proc nofog_probe_now {ctx} {
    global nofog_probe nofog_probe_val nofog_owner
    if {$nofog_probe == 0} { return }
    set v "?"
    if {[catch {set v [get_max_fow $nofog_probe $nofog_owner]} e]} {
        set v "ERR:$e"
    }
    if {$v != $nofog_probe_val} {
        set nofog_probe_val $v
        nofog_log "$ctx: fow(owner $nofog_owner)=$v"
    }
}

nofog_log "== nofog userinit loaded =="
nofog_log "patchlevel=[info patchlevel]"

# --- 1) map: remember the size of the new map, then reveal ----------------
if {![catch {rename map __nofog_map_orig}]} {
    proc map {args} {
        global nofog_w nofog_h
        set sub [lindex $args 0]
        if {$sub == "getoffset"} {
            return [__nofog_map_orig getoffset]
        }
        set cmd $sub
        foreach a [lrange $args 1 end] {
            append cmd " " [list $a]
        }
        set rc [catch {eval __nofog_map_orig $cmd} res]
        if {$sub == "create"} {
            set nofog_w [lindex $args 1]
            set nofog_h [lindex $args 2]
            nofog_apply "map create"
        }
        if {$rc} { return $res }
        return
    }
    nofog_log "hook map: ok"
} else {
    nofog_log "hook map: FAILED"
}

# --- 2) call: the level is assembled by script calls -----------------------
if {![catch {rename call __nofog_call_orig}]} {
    proc call {args} {
        set rc [catch {eval __nofog_call_orig $args} res]
        nofog_apply "call"
        if {$rc} { return $res }
        return
    }
    nofog_log "hook call: ok"
} else {
    nofog_log "hook call: FAILED"
}

# --- 3) show_loading: the moment right before the level starts -------------
if {![catch {rename show_loading __nofog_show_loading_orig}]} {
    proc show_loading {args} {
        set rc [catch {eval __nofog_show_loading_orig $args} res]
        nofog_apply "show_loading"
        if {$rc} { return $res }
        return
    }
    nofog_log "hook show_loading: ok"
} else {
    nofog_log "hook show_loading: FAILED"
}

# --- 4) reset_map: story / skirmish transitions ---------------------------
if {![catch {rename reset_map __nofog_reset_map_orig}]} {
    proc reset_map {args} {
        set rc [catch {eval __nofog_reset_map_orig $args} res]
        nofog_apply "reset_map"
        if {$rc} { return $res }
        return
    }
    nofog_log "hook reset_map: ok"
} else {
    nofog_log "hook reset_map: FAILED"
}

# --- 5) obj_query: poll the fog state of the probe object -----------------
# (disabled: creating a game object inside the map create hook crashed the
#  engine, so no probe object is created any more)
if {0} {
    if {![catch {rename obj_query __nofog_obj_query_orig}]} {
        proc obj_query {args} {
            global nofog_probe_tick
            incr nofog_probe_tick
            if {$nofog_probe_tick >= 50} {
                set nofog_probe_tick 0
                nofog_probe_now "probe"
            }
            return [eval __nofog_obj_query_orig $args]
        }
        nofog_log "hook obj_query: ok"
    } else {
        nofog_log "hook obj_query: FAILED"
    }
}

nofog_log "== end =="
