# probe-v7.tcl - diagnostic probe for the original Diggles (Tcl 8.3 ONLY).
#
# Tcl 8.3 restrictions (learned by hitting them):
#   * no "eq"/"ne" operators  (Tcl 8.4+)   -> use "string equal"/"string length"
#   * no "file normalize"      (Tcl 8.4+)
#   * no "file join"           (Tcl 8.5+)
#   * no "lassign"/"try"       (Tcl 8.5/8.6+)
#
# Report channel: file "tclprobe.log" in the game folder (cwd).
# Deferred snapshots use the Tcl "after" command, so we can observe the engine
# AFTER the options/game systems finished initialising.

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

proc snap {tag} {
    w ""
    w "######## SNAPSHOT $tag ########"
    foreach opt {maxgametimefactor nogamespeedlock persistoptions usetclclasscache buttonmapping panning zoom tilt panmousefactor simplecontrol borderscroll keyscroll zoomspeedfactor viewmodifier altmodifier panmodifier zoommodifier tiltmodifier maxframerate gamesavecompression} {
        catch {w "option get $opt = [option get $opt]"}
    }
    catch {w "option list = [option list]"}
    catch {w "opt getdesc maxgametimefactor = [option getdesc maxgametimefactor]"}
    catch {w "opt getinfo maxgametimefactor = [option getinfo maxgametimefactor]"}
    catch {w "opt getname maxgametimefactor = [option getname maxgametimefactor]"}
    catch {w "opt getdesc buttonmapping = [option getdesc buttonmapping]"}
    catch {w "opt getinfo buttonmapping = [option getinfo buttonmapping]"}
    catch {w "opt getname buttonmapping = [option getname buttonmapping]"}
    catch {w "camctrlmapping desc = [camctrlmapping desc]"}
    for {set i 0} {$i < 6} {incr i} {
        catch {w "camctrl slot $i = [camctrlmapping $i]"}
    }
    catch {w "camctrlmapping noargs = [camctrlmapping]"}
    catch {w "keybind current = [keybind current]"}
    catch {w "inputmode = [inputmode]"}
    catch {w "get_view = [get_view]"}
    catch {w "get_cameramoving = [get_cameramoving]"}
    catch {w "get_camerafollowdist = [get_camerafollowdist]"}
    w "######## END $tag ########"
}

snap "init"

# --- registry dump straight from inside the game interpreter --------------------
catch {
    set reg [exec reg query "HKCU\Software\SekOst\Diggles" /s]
    foreach line [split $reg "\n"] { w "REG $line" }
}
catch {
    set reg [exec reg query "HKCU\Software\SekOst\Diggles\Control"]
    foreach line [split $reg "\n"] { w "REG-CTRL $line" }
}
catch {
    set reg [exec reg query "HKCU\Software\SekOst\Diggles\Misc"]
    foreach line [split $reg "\n"] { w "REG-MISC $line" }
}

# --- deferred snapshots --------------------------------------------------------
catch {after 5000 {snap "t+5s"}}
catch {after 15000 {snap "t+15s"}}
catch {after 30000 {snap "t+30s"}}

w "=== probe-v7 done ==="
catch {close $fh}
