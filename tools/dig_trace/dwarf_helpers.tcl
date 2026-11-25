# DIGTRACE_CLASS_V2
# ## SOURCE: data/Scripts/classes/zwerg/z_dignwalk.tcl runs dig_next and
# dig_apply from the Zwerg class. These helpers are inserted into that class.
# ## ADAPTER: append observations to the same JSONL file as userinit.tcl.
# UNKNOWN: engine-only cave frames and beautifier decorations may not be Tcl
# objects, so an empty obj_query result cannot prove their absence.

proc digtrace_class_json {value} {
    set escaped [string map [list "\\" "\\\\" "\"" "\\\"" "\n" "\\n" "\r" "\\r" "\t" "\\t"] $value]
    return "\"$escaped\""
}

proc digtrace_class_emit {event fields} {
    if {![info exists ::digtrace_class_count]} {set ::digtrace_class_count 0}
    if {$::digtrace_class_count >= 5000} {return}
    incr ::digtrace_class_count
    set line "{\"event\":[digtrace_class_json $event],\"stream\":\"zwerg\",\"seq\":$::digtrace_class_count,\"time\":[clock seconds]"
    foreach {key value} $fields {
        append line ",\"$key\":[digtrace_class_json $value]"
    }
    append line "}"
    if {![catch {set f [open "diggles_dig_trace.jsonl" a]}]} {
        catch {fconfigure $f -translation lf -encoding utf-8}
        catch {puts $f $line; flush $f}
        catch {close $f}
    }
}

proc digtrace_class_hmap {point} {
    set x [expr {int([lindex $point 0])}]
    set y [expr {int([lindex $point 1])}]
    set samples {}
    foreach dy {-1 0 1} {
        foreach dx {-1 0 1} {
            set sx [expr {$x + $dx}]
            set sy [expr {$y + $dy}]
            set height "?"
            catch {set height [get_hmap $sx $sy]}
            lappend samples [list $sx $sy $height]
        }
    }
    return $samples
}

proc digtrace_class_objects {} {
    set classes {Schatztonne Dummy_Multi_Holzstuetze_a Dummy_Multi_Holzstuetze_b Dummy_Multi_Holzstuetze_c Dummy_Multi_Holzstuetze_d Dummy_Multi_Holzstuetze_e Dummy_Multi_Holzstuetze_f Dummy_Multi_Holzstuetze_g Dummy_Multi_Holzstuetze_h Dummy_Multi_Holzstuetze_i Dummy_Moos_hm_a Dummy_Moos_hm_b Dummy_Moos_hm_c Dummy_Moos_hm_d Dummy_Moos_hm_e}
    foreach size {1 2 3 4} {
        set details {a b c}
        if {$size == 1 || $size == 4} {set details {a b}}
        foreach shape {a b c} {
            foreach detail $details {
                lappend classes Dummy_Urw_caves_${size}_${shape}_${detail}
            }
        }
    }
    foreach root {00 01 02 03 04 05} {
        foreach detail {a b} {
            lappend classes Dummy_Wurzel_${root}_${detail}
        }
    }
    if {[catch {set refs [obj_query this -class $classes -range 12 -limit 64 -cloaked 1]} err]} {
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
        if {[scan $pos "%f %f" px py] == 2} {
            set key [list $class [format "%.2f" $px] [format "%.2f" $py]]
            if {![info exists ::digtrace_seen($key)]} {
                set ::digtrace_seen($key) 1
                catch {digtrace_class_emit object_surface [list class $class pos $pos hmap [digtrace_class_hmap [list $px $py]]]}
            }
        }
    }
    return $objects
}

proc digtrace_class_snapshot {actor} {
    if {![info exists ::digtrace_snapshot_budget]} {return}
    if {$::digtrace_snapshot_budget <= 0} {return}
    incr ::digtrace_snapshot_budget -1
    set actor_pos "?"
    catch {set actor_pos [get_pos $actor]}
    catch {digtrace_class_emit object_snapshot [list actor $actor actor_pos $actor_pos objects [digtrace_class_objects] hmap [digtrace_class_hmap $actor_pos]]}
    if {$::digtrace_snapshot_budget > 0} {
        catch {tasklist_add $actor "digtrace_class_snapshot $actor"}
    }
}

proc digtrace_class_before {point} {
    set actor_pos "?"
    set material "?"
    catch {set actor_pos [get_pos this]}
    catch {set material [get_material $point]}
    return [list [digtrace_class_hmap $point] [digtrace_class_objects] $actor_pos $material]
}

proc digtrace_class_after {point before result} {
    set actor_pos [lindex $before 2]
    if {$before == ""} {set actor_pos "?"}
    digtrace_class_emit dig_apply [list point $point actor_pos $actor_pos result $result before_hmap [lindex $before 0] after_hmap [digtrace_class_hmap $point] before_objects [lindex $before 1] after_objects [digtrace_class_objects] before_material [lindex $before 3]]
    if {$result == "1"} {
        set ::digtrace_snapshot_budget 6
        catch {tasklist_add this "digtrace_class_snapshot this"}
    }
}

catch {digtrace_class_emit class_script_loaded [list script scripts/classes/zwerg/z_dignwalk.tcl]}
