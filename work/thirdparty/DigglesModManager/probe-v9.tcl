# probe-v9.tcl - diagnostic + verification probe for the original Diggles (Tcl 8.3).
#
# Goals:
#   1. does the Tcl "option set" command persist into HKCU\Software\SekOst\Diggles ?
#   2. does "keybind set W ..." get accepted by the engine, and what does "keybind current" show ?
#   3. what are the usage messages of the camera-related Tcl commands ?
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

r "######## PROBE V9 ########"
r "cwd = [pwd]"
r "tcl = [info patchlevel]"

# ------------------------------------------------------------------ 1. options --
r ""
r "---- option get before ----"
foreach o {maxgametimefactor nogamespeedlock persistoptions usetclclasscache buttonmapping simplecontrol maxframerate panmousefactor gamesavecompression} {
    if {[catch {set v [option get $o]} err]} {
        r "option get $o -> ERROR: $err"
    } else {
        set n "?"
        catch {set n [option getname $o]}
        set d "?"
        catch {set d [option getdesc $o]}
        set i "?"
        catch {set i [option getinfo $o]}
        r "option get $o = $v | name=$n | desc=$d | info=$i"
    }
}
catch {r "option list = [option list]"}

r ""
r "---- option set attempts ----"
catch {r "option set maxgametimefactor 8 -> [option set maxgametimefactor 8]"}
catch {r "option get maxgametimefactor after = [option get maxgametimefactor]"}
catch {r "option set nogamespeedlock 1 -> [option set nogamespeedlock 1]"}
catch {r "option get nogamespeedlock after = [option get nogamespeedlock]"}

# ------------------------------------------------------------------ 2. keybind --
r ""
r "---- keybind ----"
catch {r "keybind keynames = [keybind keynames]"}
catch {r "keybind current BEFORE = [keybind current]"}
catch {r "keybind set W  -> [keybind set W {set_view 1 1 1 0 0}]"}
catch {r "keybind set A  -> [keybind set A {set_view 2 2 1 0 0}]"}
catch {r "keybind set S  -> [keybind set S {set_view 3 3 1 0 0}]"}
catch {r "keybind set D  -> [keybind set D {set_view 4 4 1 0 0}]"}
catch {r "keybind set W shift -> [keybind set W shift {set_view 5 5 1 0 0}]"}
catch {r "keybind current AFTER = [keybind current]"}
catch {r "keybind get = [keybind get]"}
catch {r "keybind clr = [keybind clr]"}
catch {r "keybind set BADKEY -> [keybind set NOTAKEY {set_view 9 9 1 0 0}]"}

# ------------------------------------------------------------ 3. camera commands --
r ""
r "---- camera command usage ----"
foreach c {camera_set set_view set_viewpos set_view_begin set_camerafollow set_fov scroller scrollrange viewlock screen2world screen3world get_view get_cameramoving get_camerafollowdist inputmode gametime} {
    if {[catch {set v [$c]} err]} {
        r "$c -> ERROR: $err"
    } else {
        r "$c -> $v"
    }
}

# ----------------------------------------------------------- 4. time factor ----
r ""
r "---- time factor ----"
catch {r "gametime factor = [gametime factor]"}
catch {r "gametime = [gametime]"}
catch {r "set_time_factor 8 -> [set_time_factor 8]"}
catch {r "gametime factor after = [gametime factor]"}

r ""
r "---- option get after all ----"
foreach o {maxgametimefactor nogamespeedlock buttonmapping} {
    catch {r "option get $o = [option get $o]"}
}

r "######## END V9 ########"

# second copy through the error channel -> engine writes it to tclerrors.txt
error "PROBE-V9-DONE"
