# probe-v6.tcl - diagnostic probe for the original Diggles (Tcl 8.3).
#
# Two report channels:
#   * a file "tclprobe.log" in the game folder (cwd)
#   * an intentional Tcl error -> engine writes it to tclerrors.txt
#
# userinit.tcl runs BEFORE systeminit.tcl, so registry-backed options may not be
# loaded yet. This probe therefore also schedules deferred dumps via "after".

set ::fh ""
if {![catch {set ::fh [open "tclprobe.log" w]}]} {
    catch {fconfigure $::fh -translation lf}
}

proc w {text} {
    global fh
    if {$fh ne ""} {
        catch {puts $fh $text}
        catch {flush $fh}
    }
}

proc r {text} { w $text }

# ---------------------------------------------------------------- snapshot ---
proc snap {tag} {
    w ""
    w "######## SNAPSHOT $tag ########"
    foreach opt {maxgametimefactor nogamespeedlock persistoptions usetclclasscache buttonmapping panning zoom tilt panmousefactor simplecontrol borderscroll keyscroll zoomspeedfactor viewmodifier altmodifier panmodifier zoommodifier tiltmodifier maxframerate} {
        catch {r "option get $opt = [option get $opt]"}
    }
    catch {r "option list = [option list]"}
    catch {r "option getdesc maxgametimefactor = [option getdesc maxgametimefactor]"}
    catch {r "option getinfo maxgametimefactor = [option getinfo maxgametimefactor]"}
    catch {r "option getname maxgametimefactor = [option getname maxgametimefactor]"}
    catch {r "option getdesc buttonmapping = [option getdesc buttonmapping]"}
    catch {r "option getinfo buttonmapping = [option getinfo buttonmapping]"}
    catch {r "option getname buttonmapping = [option getname buttonmapping]"}
    catch {r "camctrlmapping desc = [camctrlmapping desc]"}
    for {set i 0} {$i < 6} {incr i} {
        catch {r "camctrl slot $i = [camctrlmapping $i]"}
    }
    catch {r "camctrlmapping noargs = [camctrlmapping]"}
    catch {r "keybind current = [keybind current]"}
    catch {r "inputmode = [inputmode]"}
    catch {r "get_view = [get_view]"}
    catch {r "get_cameramoving = [get_cameramoving]"}
    w "######## END $tag ########"
}

snap "init"

# deferred snapshots, if the engine services the Tcl event loop
catch {after 4000 {snap "t+4s"}}
catch {after 12000 {snap "t+12s"}}
catch {after 25000 {snap "t+25s"}}

# final report through the error channel (engine logs it to tclerrors.txt)
if {![catch {set fh2 [open "tclprobe2.log" w]}]} {
    catch {puts $fh2 "secondary probe file"}
    catch {close $fh2}
}
error "PROBE-V6-DONE"
