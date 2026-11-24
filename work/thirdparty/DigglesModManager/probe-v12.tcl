# probe-v12.tcl - does a keybind actually FIRE when the key is pressed?
#
# Plan: bind W/A/S/D to a proc that appends a line to camtest.log, then send
# real keystrokes to the game window and check the file.
#
# Tcl 8.3 only: no eq/ne, no file normalize/join, no lassign/try.

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

# --- the proc the keybinds will call ------------------------------------------
proc camtest {key} {
    set h ""
    if {![catch {set h [open "camtest.log" a]}]} {
        catch {puts $h "FIRED $key [clock seconds]"}
        catch {flush $h}
        catch {close $h}
    }
    # also try to move the camera a little
    catch {
        set v [get_view]
        set x [lindex $v 0]
        set y [lindex $v 1]
        set z [lindex $v 2]
        set ax [lindex $v 3]
        set ay [lindex $v 4]
        set_view [expr {$x + 0.5}] $y $z $ax $ay
    }
}

r "######## PROBE V12 ########"

r ""
r "---- bind keys ----"
try1 "keybind set W down" {keybind set W down {camtest W}}
try1 "keybind set A down" {keybind set A down {camtest A}}
try1 "keybind set S down" {keybind set S down {camtest S}}
try1 "keybind set D down" {keybind set D down {camtest D}}
try1 "keybind current" {keybind current}

r ""
r "---- camera scroll command signatures ----"
try1 "scroller (no args)" {scroller}
try1 "scrollrange (no args)" {scrollrange}
try1 "camera_set (1 arg)" {camera_set 1}
try1 "get_view" {get_view}

r ""
r "---- direct proc call (sanity: the proc itself works) ----"
try1 "camtest DIRECT" {camtest DIRECT}
catch {r "camtest.log exists: [file exists camtest.log]"}

r "######## END V12 ########"
