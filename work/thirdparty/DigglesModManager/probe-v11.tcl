# probe-v11.tcl - verification probe for the original Diggles (Tcl 8.3).
#
# Ordering matters: the engine can hard-crash on some native commands, so the
# most valuable checks come first and risky ones last.
#
# Tcl 8.3 only: no eq/ne, no file normalize/join, no lassign/try.

set ::fh ""
if {![catch {set ::fh [open "tclprobe.log" w]}]} {
    catch {fconfigure $::fh -translation lf}
}
set ::mk ""
if {![catch {set ::mk [open "probe_marker.txt" w]}]} {
    catch {puts $::mk "userinit.tcl executed"}
    catch {flush $::mk}
    catch {close $::mk}
}

proc w {text} {
    global fh
    if {[string length $fh] > 0} {
        catch {puts $fh $text}
        catch {flush $fh}
    }
}
proc r {text} { w $text }
proc try1 {label script} {
    if {[catch {uplevel 1 $script} err]} { r "$label -> ERROR: $err" } else { r "$label -> $err" }
}

r "######## PROBE V11 ########"
r "tcl = [info patchlevel]"

r ""
r "---- 1. time factor ----"
try1 "gametime factor" {gametime factor}
try1 "set_time_factor 8" {set_time_factor 8}
try1 "gametime factor after 8" {gametime factor}
try1 "set_time_factor 1" {set_time_factor 1}
try1 "gametime factor after 1" {gametime factor}

r ""
r "---- 2. keybind with modifiers ----"
try1 "keybind set W down" {keybind set W down {set_view 1 1 1 0 0}}
try1 "keybind set A down" {keybind set A down {set_view 2 2 1 0 0}}
try1 "keybind set S down ctrl" {keybind set S down ctrl {set_view 3 3 1 0 0}}
try1 "keybind set D down alt" {keybind set D down alt {set_view 4 4 1 0 0}}
try1 "keybind current" {keybind current}
try1 "keybind get W" {keybind get W}

r ""
r "---- 3. option system ----"
try1 "option list" {option list}
foreach n {Inventions Place_Menu Place_Scape ShowUI TextSpeed} {
    try1 "option get $n" "option get $n"
    try1 "option getname $n" "option getname $n"
    try1 "option getdesc $n" "option getdesc $n"
    try1 "option getinfo $n" "option getinfo $n"
}
try1 "option set ShowUI 0" {option set ShowUI 0}
try1 "option get ShowUI after" {option get ShowUI}

r ""
r "---- 4. camera ----"
try1 "camctrlmapping desc" {camctrlmapping desc}
try1 "camctrlmapping noargs" {camctrlmapping}
try1 "get_view" {get_view}
try1 "get_cameramoving" {get_cameramoving}

r ""
r "---- 5. registry from inside the game ----"
try1 "reg query Control" {exec reg query "HKCU\Software\SekOst\Diggles\Control"}
try1 "reg query Misc" {exec reg query "HKCU\Software\SekOst\Diggles\Misc"}

r ""
r "---- 6. risky native calls (may crash the engine) ----"
try1 "camera_set 0 0" {camera_set 0 0}
try1 "set_view 1 2 3" {set_view 1 2 3}
try1 "set_viewpos 1 2 3 4 5 6" {set_viewpos 1 2 3 4 5 6}

r "######## END V11 ########"
error "PROBE-V11-DONE"
