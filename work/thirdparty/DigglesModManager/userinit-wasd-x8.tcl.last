# ---------------------------------------------------------------------------
# userinit.tcl  --  Diggles: The Myth of Fenris (SEK GmbX / SEK-Ost, 2001)
#
# Adds WASD camera movement (the original has arrow keys + mouse only).
#
# Install: copy this file as  <game folder>\data\userinit.tcl
#           (the folder that contains Diggles.exe)
# Uninstall: delete the file. Nothing else is modified.
#
# Notes
#  * the game embeds Tcl 8.3 -- no eq/ne, file join/normalize, lassign, try.
#    One such word and the whole file fails to compile, nothing runs.
#  * the camera position is read with "get_view 1".  The engine can hand out
#    uninitialised garbage there, so every value is range-checked before it
#    is used; on garbage the key press is ignored instead of teleporting the
#    camera to 1e+33 (which crashes the engine).
#  * the log is written to %TEMP%\diggles_userinit.log and to the game folder.
# ---------------------------------------------------------------------------

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

set ::dig_log2 ""
catch {set ::dig_log2 [open "diggles_userinit.log" w]}
catch {fconfigure $::dig_log2 -translation lf -encoding utf-8}
proc dig_log2 {msg} {
    global dig_log2
    if {[string length $dig_log2] > 0} {
        catch {puts $dig_log2 $msg}
        catch {flush $dig_log2}
    }
}

proc dig_say {msg} {
    dig_log $msg
    dig_log2 $msg
}

dig_say "userinit.tcl loaded"

# ------------------------------------------------------- input mode -------
# The registry has Input\SimpleControl = 1, while the game default is
# "false" (SimpleControl [true|false] (false)).  The simplified control
# scheme uses a reduced input path; switch to the full scheme so that the
# key bindings are dispatched.
if {[catch {perfoptions simplecontrol 0} e]} {
    dig_say "perfoptions simplecontrol 0 -> ERROR: $e"
} else {
    dig_say "perfoptions simplecontrol 0 -> ok"
}
catch {dig_say "minimalrun = [minimalrun]"}

# ---------------------------------------------------------------- camera ----
set ::dig_step 4.0

proc dig_try_view {args} {
    set v {}
    if {[catch {set v [get_view {*}$args]}]} {
        dig_say "PAN get_view $args failed"
        return 0
    }
    if {[llength $v] < 5} {
        dig_say "PAN get_view $args returned [llength $v] values"
        return 0
    }
    set x  [lindex $v 0]
    set y  [lindex $v 1]
    set z  [lindex $v 2]
    set ax [lindex $v 3]
    set ay [lindex $v 4]
    foreach c [list $x $y $z $ax $ay] {
        if {![string is double $c]} {
            dig_say "PAN non numeric value in view $args: $v"
            return 0
        }
        if {$c < -100000.0 || $c > 100000.0} {
            dig_say "PAN out of range value in view $args: $v"
            return 0
        }
    }
    if {$z <= 0.0 || $z > 100.0} {
        dig_say "PAN bad zoom in view $args: $v"
        return 0
    }
    set ::dig_vx $x
    set ::dig_vy $y
    set ::dig_vz $z
    set ::dig_vax $ax
    set ::dig_vay $ay
    dig_say "PAN view $args: $v"
    return 1
}

proc dig_read_view {} {
    if {[dig_try_view 1]} { return 1 }
    if {[dig_try_view]} { return 1 }
    dig_say "PAN no usable camera values - key ignored"
    return 0
}

proc dig_pan {dx dy} {
    global ::dig_step
    global ::dig_vx ::dig_vy ::dig_vz ::dig_vax ::dig_vay
    dig_say "PAN key $dx $dy pressed"
    if {![dig_read_view]} { return 0 }
    set step [expr {$::dig_step * $::dig_vz}]
    set nx [expr {$::dig_vx + $dx * $step}]
    set ny [expr {$::dig_vy + $dy * $step}]
    dig_say "PAN $dx $dy -> set_view $nx $ny $::dig_vz $::dig_vax $::dig_vay"
    if {[catch {set_view $nx $ny $::dig_vz $::dig_vax $::dig_vay} e]} {
        dig_say "PAN set_view ERROR: $e"
        return 0
    }
    dig_say "PAN ok"
    return 1
}

proc dig_cam_north {} { dig_pan 0 -1 }
proc dig_cam_south {} { dig_pan 0 1 }
proc dig_cam_west  {} { dig_pan -1 0 }
proc dig_cam_east  {} { dig_pan 1 0 }

# plain bindings (fire on key press)
catch {keybind set W {dig_cam_north}}
catch {keybind set A {dig_cam_west}}
catch {keybind set S {dig_cam_south}}
catch {keybind set D {dig_cam_east}}

# "down" bindings (fire while the key is held) on a second key set
catch {keybind set I down {dig_cam_north}}
catch {keybind set J down {dig_cam_west}}
catch {keybind set K down {dig_cam_south}}
catch {keybind set L down {dig_cam_east}}

# ---------------------------------------------------------------- speed ----
# "gametime factor <x>" is what the game's own scripts use and it is not
# clamped (8, 16, 32 all work).  Campaign scripts reset it to 1.0 when a
# level starts, so press P again after starting a level.
proc dig_speed_8 {} {
    catch {gametime factor 8}
    catch {dig_say "speed -> [gametime factor]"}
}
proc dig_speed_1 {} {
    catch {gametime factor 1}
    catch {dig_say "speed -> [gametime factor]"}
}
catch {keybind set P {dig_speed_8}}
catch {keybind set O {dig_speed_1}}

catch {dig_say "keybind current = [keybind current]"}
catch {dig_say "done"}
