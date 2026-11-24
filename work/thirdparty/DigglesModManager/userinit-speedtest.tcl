set ::dig_log ""
catch {set ::dig_log [open "diggles_userinit.log" w]}
catch {fconfigure $::dig_log -translation lf}
proc dig_log {msg} {
    global dig_log
    if {[string length $dig_log] > 0} {
        catch {puts $dig_log $msg}
        catch {flush $dig_log}
    }
}
dig_log "--- speed test ---"
catch {dig_log "initial factor = [gametime factor]"}
catch {dig_log "set_time_factor 8 -> [set_time_factor 8]"}
catch {dig_log "after set_time_factor = [gametime factor]"}
catch {dig_log "gametime factor 8 -> [gametime factor 8]"}
catch {dig_log "after gametime factor 8 = [gametime factor]"}
catch {dig_log "gametime factor 16 -> [gametime factor 16]"}
catch {dig_log "after gametime factor 16 = [gametime factor]"}
catch {dig_log "set_time_factor 16 -> [set_time_factor 16]"}
catch {dig_log "after set_time_factor 16 = [gametime factor]"}
dig_log "--- end ---"
