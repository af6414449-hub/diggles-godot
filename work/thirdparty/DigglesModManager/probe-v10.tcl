# probe-v10.tcl - verification probe for the original Diggles (Tcl 8.3).
#
# Answers, in order of value (the game may crash, so most valuable first):
#   1. does "set_time_factor 8" work at runtime (x8 speed)?
#   2. does "keybind set <KEY> down <script>" accept a "down" (held-key) modifier?
#   3. what are the camera command signatures?
#   4. does the engine read/write the registry from inside the game?

set ::fh ""
if {![catch {set ::fh [open "tclprobe.log" w]}]} {
    catch {fconfigure $::fh -translation lf}
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

r "######## PROBE V10 ########"
r "tcl = [info patchlevel]"

r ""
r "---- 1. time factor ----"
try1 "gametime (no args)" {gametime}
try1 "gametime factor" {gametime factor}
try1 "gametime factor (2nd)" {gametime factor}
try1 "set_time_factor 8" {set_time_factor 8}
try1 "gametime factor after set 8" {gametime factor}
try1 "set_time_factor 1" {set_time_factor 1}
try1 "gametime factor after set 1" {gametime factor}

r ""
r "---- 2. keybind modifiers ----"
try1 "keybind set W (plain)" {keybind set W {set_view 1 1 1 0 0}}
try1 "keybind set W down" {keybind set W down {set_view 2 2 1 0 0}}
try1 "keybind set A down ctrl" {keybind set A down ctrl {set_view 3 3 1 0 0}}
try1 "keybind set S shift" {keybind set S shift {set_view 4 4 1 0 0}}
try1 "keybind set D alt" {keybind set D alt {set_view 5 5 1 0 0}}
try1 "keybind set BOGUSKEY" {keybind set BOGUSKEY {set_view 6 6 1 0 0}}
try1 "keybind current" {keybind current}
try1 "keybind keynames" {keybind keynames}

r ""
r "---- 3. camera command signatures ----"
foreach c {camera_set set_view set_viewpos set_view_begin set_camerafollow set_fov scroller scrollrange viewlock screen2world screen3world get_view get_cameramoving get_camerafollowdist set_viewinfog inputmode autoloadlevel} {
    try1 "$c (no args)" "$c"
}

r ""
r "---- 4. registry access from inside the game ----"
try1 "reg query Control" {exec reg query "HKCU\Software\SekOst\Diggles\Control"}
try1 "reg query Misc" {exec reg query "HKCU\Software\SekOst\Diggles\Misc"}

r ""
r "---- 5. option subcommands ----"
try1 "option list" {option list}
try1 "option getname Inventions" {option getname Inventions}
try1 "option get ShowUI" {option get ShowUI}
try1 "option getdesc ShowUI" {option getdesc ShowUI}
try1 "option getinfo ShowUI" {option getinfo ShowUI}
try1 "option get TextSpeed" {option get TextSpeed}

r ""
r "---- 6. camera state now ----"
try1 "get_view" {get_view}
try1 "get_cameramoving" {get_cameramoving}

r "######## END V10 ########"
error "PROBE-V10-DONE"
