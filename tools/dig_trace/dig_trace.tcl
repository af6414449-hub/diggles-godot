# ## ADAPTER: observational Tcl trace for the installed 32-bit Diggles executable.
# ## SOURCE: dig_apply is called by z_dignwalk.tcl:dig_execute; dig_mark and
# cave_skin are native Tcl commands. This file does not change their arguments.
# UNKNOWN: CMapBeautifier may create renderer-only decorations that obj_query
# cannot see. A missing support in objects_after is not proof it was not drawn.
# Tcl 8.3 syntax only. Loaded at the end of data/userinit.tcl.

set ::digtrace_seq 0
set ::digtrace_limit 10000
set ::digtrace_log ""
catch {set ::digtrace_log [open "diggles_dig_trace.jsonl" a]}
if {$::digtrace_log != ""} {
    catch {fconfigure $::digtrace_log -translation lf -encoding utf-8}
}

proc digtrace_json {value} {
    set escaped [string map [list "\\" "\\\\" "\"" "\\\"" "\n" "\\n" "\r" "\\r" "\t" "\\t"] $value]
    return "\"$escaped\""
}

proc digtrace_write {event fields} {
    if {$::digtrace_log == "" || $::digtrace_seq >= $::digtrace_limit} {return}
    incr ::digtrace_seq
    set line "{\"event\":[digtrace_json $event],\"seq\":$::digtrace_seq,\"time\":[clock seconds]"
    foreach {key value} $fields {
        append line ",\"$key\":[digtrace_json $value]"
    }
    append line "}"
    catch {puts $::digtrace_log $line; flush $::digtrace_log}
}

# Five samples around the native dig point, in original map coordinates.
# Sampling uses the game's own get_hmap command. Failed samples are explicit.
proc digtrace_hmap {point} {
    set x [expr {int([lindex $point 0] + 0.5)}]
    set y [expr {int([lindex $point 1] + 0.5)}]
    set samples {}
    foreach offset {{0 0} {-1 0} {1 0} {0 -1} {0 1}} {
        set sx [expr {$x + [lindex $offset 0]}]
        set sy [expr {$y + [lindex $offset 1]}]
        set height "?"
        if {[catch {set height [get_hmap $sx $sy]} err]} {set height "ERROR:$err"}
        lappend samples [list $sx $sy $height]
    }
    return $samples
}

# Query actual engine objects near the strike. IDs, classes and native
# positions stay together so the same object can be compared across strikes.
proc digtrace_objects {point} {
    set classes {Schatztonne Stein Steinbrocken Dummy_Multi_Holzstuetze_a Dummy_Multi_Holzstuetze_b Dummy_Multi_Holzstuetze_c Dummy_Multi_Holzstuetze_d Dummy_Multi_Holzstuetze_e Dummy_Multi_Holzstuetze_f Dummy_Multi_Holzstuetze_g Dummy_Multi_Holzstuetze_h Dummy_Multi_Holzstuetze_i Dummy_Moos_hm_a Dummy_Moos_hm_b Dummy_Moos_hm_c Dummy_Moos_hm_d Dummy_Moos_hm_e}
    if {[catch {set refs [obj_query 0 -pos $point -class $classes -range 8 -limit 64 -cloaked 1]} err]} {
        return "QUERY_ERROR:$err"
    }
    set objects {}
    if {$refs == "0" || $refs == ""} {return $objects}
    foreach ref $refs {
        set class "?"
        set pos "?"
        catch {set class [get_objclass $ref]}
        catch {set pos [get_pos $ref]}
        lappend objects [list $ref $class $pos]
    }
    return $objects
}

proc digtrace_before_apply {point actor} {
    if {$::digtrace_seq >= $::digtrace_limit} {return ""}
    set actor_pos "?"
    catch {set actor_pos [get_pos $actor]}
    return [list [digtrace_hmap $point] [digtrace_objects $point] $actor_pos]
}

proc digtrace_after_apply {point actor before result} {
    if {$::digtrace_seq >= $::digtrace_limit} {return}
    set before_hmap [lindex $before 0]
    set before_objects [lindex $before 1]
    set actor_pos [lindex $before 2]
    digtrace_write dig_apply [list point $point actor $actor actor_pos $actor_pos result $result before_hmap $before_hmap after_hmap [digtrace_hmap $point] before_objects $before_objects after_objects [digtrace_objects $point]]
}

# Native handlers have no Tcl script evaluation. This preserves the result and
# error code while recording the inputs selected by the original UI/scripts.
if {![catch {rename dig_mark __digtrace_dig_mark}]} {
    proc dig_mark {args} {
        set code [catch {eval [linsert $args 0 __digtrace_dig_mark]} result]
        catch {digtrace_write dig_mark [list args $args result $result error $code]}
        if {$code} {return -code error $result}
        return $result
    }
    digtrace_write hook [list command dig_mark status installed]
} else {
    digtrace_write hook [list command dig_mark status unavailable]
}

if {![catch {rename cave_skin __digtrace_cave_skin}]} {
    proc cave_skin {args} {
        set code [catch {eval [linsert $args 0 __digtrace_cave_skin]} result]
        catch {digtrace_write cave_skin [list args $args result $result error $code]}
        if {$code} {return -code error $result}
        return $result
    }
    digtrace_write hook [list command cave_skin status installed]
} else {
    digtrace_write hook [list command cave_skin status unavailable]
}

digtrace_write session_start [list version 2 source data/userinit.tcl output diggles_dig_trace.jsonl dig_execute_visible [info commands dig_execute] digtrace_class_emit_visible [info commands digtrace_class_emit]]
