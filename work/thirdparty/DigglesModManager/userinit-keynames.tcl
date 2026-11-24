set ::dig_log ""
catch {set ::dig_log [open "C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/diggles_userinit_abs.log" w]}
catch {fconfigure $::dig_log -translation lf -encoding utf-8}
set ::dig_log2 ""
catch {set ::dig_log2 [open "diggles_userinit.log" w]}
catch {fconfigure $::dig_log2 -translation lf -encoding utf-8}
proc dig_log {msg} {
    global dig_log
    global dig_log2
    if {[string length $dig_log] > 0} {
        catch {puts $dig_log $msg}
        catch {flush $dig_log}
    }
    if {[string length $dig_log2] > 0} {
        catch {puts $dig_log2 $msg}
        catch {flush $dig_log2}
    }
}
dig_log "probe started, cwd=[pwd]"

set ::dig_step 4.0
proc dig_pan {dx dy} {
    set v {}
    if {[catch {set v [get_view]}]} {
        dig_log "PAN get_view failed"
        return
    }
    dig_log "PAN get_view -> [llength $v] values: $v"
    if {[llength $v] < 5} { return }
    set x [lindex $v 0]
    set y [lindex $v 1]
    set z [lindex $v 2]
    set ax [lindex $v 3]
    set ay [lindex $v 4]
    set step [expr {$::dig_step * $z}]
    set nx [expr {$x + $dx * $step}]
    set ny [expr {$y + $dy * $step}]
    dig_log "PAN $dx $dy : $x $y $z $ax $ay -> $nx $ny"
    if {[catch {set_view $nx $ny $z $ax $ay} e]} {
        dig_log "PAN set_view ERROR: $e"
    } else {
        dig_log "PAN set_view ok"
    }
}
proc dig_cam_north {} { dig_pan 0 -1 }
proc dig_cam_south {} { dig_pan 0 1 }
proc dig_cam_west  {} { dig_pan -1 0 }
proc dig_cam_east  {} { dig_pan 1 0 }

catch {keybind set W {dig_cam_north}}
catch {keybind set A {dig_cam_west}}
catch {keybind set S {dig_cam_south}}
catch {keybind set D {dig_cam_east}}

proc trykey {k} {
    if {[catch {keybind set $k {dig_speed_8}} err]} {
        dig_log "FAIL [$k] : $err"
    } else {
        dig_log "OK   [$k]"
    }
}
foreach k {F1 f1 F2 f2 F01 F11 P T Z R Q E Y U I O H J K L N M B V C X Prior Next} {
    trykey $k
}

catch {dig_log "current = [keybind current]"}
catch {dig_log "done"}
