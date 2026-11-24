set ::dig_log ""
catch {set ::dig_log [open "C:/Users/frant/AppData/Local/Temp/diggles_userinit.log" w]}
catch {fconfigure $::dig_log -translation lf -encoding utf-8}
proc dig_log {msg} {
    global dig_log
    if {[string length $dig_log] > 0} {
        catch {puts $dig_log $msg}
        catch {flush $dig_log}
    }
}
dig_log "START"
catch {dig_log "cwd = [pwd]"}
catch {dig_log "tcl = [info patchlevel]"}
catch {dig_log "user = [get_system_name]"}

set v0 {}
if {[catch {set v0 [get_view]}]} { dig_log "get_view ERROR" } else { dig_log "get_view   -> [llength $v0] values: $v0" }
set v1 {}
if {[catch {set v1 [get_view 1]}]} { dig_log "get_view 1 ERROR" } else { dig_log "get_view 1 -> [llength $v1] values: $v1" }
set v2 {}
if {[catch {set v2 [get_view 0]}]} { dig_log "get_view 0 ERROR" } else { dig_log "get_view 0 -> [llength $v2] values: $v2" }
dig_log "menu camera should be 32.368 40.858 1.38 -0.355 0.165"

# does the game dir accept a log file at all?
catch {
    set fh [open "C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/diggles_probe.log" w]
    puts $fh "game dir writable"
    close $fh
    dig_log "game dir writable: YES"
}
catch {dig_log "game dir writable: NO"}
dig_log "END"
