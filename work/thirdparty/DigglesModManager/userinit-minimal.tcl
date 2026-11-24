# Minimal probe: no hooks at all. Only logs that userinit.tcl runs.
# Used to prove whether the game crash / the Tcl error "noidiobjclassescnt"
# is caused by the nofog script or exists without it.

set ::dig_log ""
catch {set ::dig_log [open "diggles_userinit.log" w]}
catch {fconfigure $::dig_log -translation lf -encoding ascii}
catch {puts $::dig_log "minimal probe ok patchlevel=[info patchlevel]"}
catch {flush $::dig_log}
catch {close $::dig_log}
