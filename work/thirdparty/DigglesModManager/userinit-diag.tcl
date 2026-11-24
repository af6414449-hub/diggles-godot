set ::dig_log ""
catch {set ::dig_log [open "diggles_userinit.log" w]}
catch {fconfigure $::dig_log -translation lf -encoding utf-8}
proc dig_log {msg} {
    global dig_log
    if {[string length $dig_log] > 0} {
        catch {puts $dig_log $msg}
        catch {flush $dig_log}
    }
}
dig_log "START"

# --- what does get_view give us at the menu? ---
set v {}
if {[catch {set v [get_view]}]} {
    dig_log "get_view ERROR"
} else {
    dig_log "get_view -> [llength $v] values: $v"
}

# --- exactly what the pan proc does ---
set ::dig_step 4.0
proc dig_pan {dx dy} {
    set v {}
    if {[catch {set v [get_view]}]} { dig_log "PAN get_view failed"; return }
    dig_log "PAN get_view -> [llength $v] values: $v"
    if {[llength $v] < 5} { return }
    set x [lindex $v 0]
    set y [lindex $v 1]
    set z [lindex $v 2]
    set ax [lindex $v 3]
    set ay [lindex $v 4]
    dig_log "PAN types: x=$x y=$y z=$z ax=$ax ay=$ay"
    set step [expr {$::dig_step * $z}]
    set nx [expr {$x + $dx * $step}]
    set ny [expr {$y + $dy * $step}]
    dig_log "PAN about to set_view $nx $ny $z $ax $ay"
    if {[catch {set_view $nx $ny $z $ax $ay} e]} {
        dig_log "PAN set_view ERROR: $e"
    } else {
        dig_log "PAN set_view ok"
    }
    if {[catch {set v2 [get_view]}]} {
        dig_log "PAN get_view2 failed"
    } else {
        dig_log "PAN view now: $v2"
    }
}

dig_log "calling dig_pan 0 -1"
dig_pan 0 -1
dig_log "dig_pan survived"

# --- does a binding fire at all in the menu? ---
catch {keybind set P {dig_log "KEY P PRESSED"}}
catch {dig_log "after P bind: [keybind current]"}

# --- why did F1 not register? ---
if {[catch {keybind set F1 {dig_speed_8}} e1]} {
    dig_log "F1 FAIL: $e1"
} else {
    dig_log "F1 OK"
}
if {[catch {keybind set F2 {dig_speed_1}} e2]} {
    dig_log "F2 FAIL: $e2"
} else {
    dig_log "F2 OK"
}
if {[catch {keybind set F1 down {dig_speed_8}} e3]} {
    dig_log "F1 down FAIL: $e3"
} else {
    dig_log "F1 down OK"
}
catch {dig_log "current: [keybind current]"}

dig_log "END"
