# probe-min.tcl - minimal probe: does the engine execute data/userinit.tcl at all?
# Tcl 8.3 only. No eq/ne, no file normalize/join.

set ::f ""
if {![catch {set ::f [open "tclprobe.log" w]}]} {
    catch {puts $::f "probe ok: cwd=[pwd] script=[info script] version=[info patchlevel]"}
    catch {flush $::f}
    catch {close $::f}
}
