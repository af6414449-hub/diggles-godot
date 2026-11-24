# probe-v5.tcl - diagnostic probe for the original Diggles (Tcl 8.3).
#
# The engine writes Tcl script errors to tclerrors.txt in the game folder.
# We use that as the report channel: build a report string and raise it as an
# error, so the text lands in tclerrors.txt even if file writing is unavailable.
#
# Tcl 8.3 only: no eq/ne, no file normalize/join, no lassign/try.

set ::report ""
proc r {text} {
    global report
    append report "$text\n"
}

# --- 1. environment ------------------------------------------------------------
catch {r "cwd = [pwd]"}
catch {r "info_script = [info script]"}
catch {r "argv = $::argv"}
catch {r "tcl_version = [info patchlevel]"}
catch {r "system_name = [get_system_name]"}

# --- 2. can we write a file? ---------------------------------------------------
set ::fh ""
foreach cand [list "tclprobe.log" "data/tclprobe.log" "Data/tclprobe.log"] {
    if {[string length $::fh] > 0} { break }
    if {![catch {set h [open $cand w]}]} {
        set ::fh $h
        r "OPEN_OK $cand"
    } else {
        r "OPEN_FAIL $cand : $h"
    }
}
if {[string length $::fh] > 0} {
    catch {puts $::fh $::report}
    catch {flush $::fh}
    catch {close $::fh}
    r "FILE_WRITE_DONE"
}

# --- 3. option system ----------------------------------------------------------
foreach opt {maxgametimefactor nogamespeedlock persistoptions usetclclasscache buttonmapping} {
    catch {r "option get $opt = [option get $opt]"}
    catch {r "option getname $opt = [option getname $opt]"}
}
catch {r "option list = [option list]"}

# --- 4. camera control mapping -------------------------------------------------
catch {r "camctrlmapping desc = [camctrlmapping desc]"}
for {set i 0} {$i < 6} {incr i} {
    catch {r "camctrl slot $i = [camctrlmapping $i]"}
}

# --- 5. key bindings -----------------------------------------------------------
catch {r "keybind keynames = [keybind keynames]"}
catch {r "keybind current = [keybind current]"}
catch {r "keybind noargs = [keybind]"}

# --- 6. command inventory ------------------------------------------------------
if {![catch {set cmds [lsort [info commands]]}]} {
    r "COMMANDS [llength $cmds]:"
    foreach c $cmds { r "  CMD $c" }
} else {
    r "COMMANDS_ERROR $cmds"
}

# --- 7. view state -------------------------------------------------------------
catch {r "get_view = [get_view]"}
catch {r "get_cameramoving = [get_cameramoving]"}
catch {r "get_camerafollowdist = [get_camerafollowdist]"}

# --- report via the error channel ----------------------------------------------
error "PROBE-REPORT-BEGIN\n$::report\nPROBE-REPORT-END"
