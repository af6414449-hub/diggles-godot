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
dig_log "START (read-only probe)"

set v0 {}
if {[catch {set v0 [get_view]}]} { dig_log "get_view ERROR" } else { dig_log "get_view   -> [llength $v0] values: $v0" }

set v1 {}
if {[catch {set v1 [get_view 1]}]} { dig_log "get_view 1 ERROR" } else { dig_log "get_view 1 -> [llength $v1] values: $v1" }

set v2 {}
if {[catch {set v2 [get_view 0]}]} { dig_log "get_view 0 ERROR" } else { dig_log "get_view 0 -> [llength $v2] values: $v2" }

dig_log "menu camera should be 32.368 40.858 1.38 -0.355 0.165"
dig_log "END"
