# probe-v8.tcl - diagnostic probe for the original Diggles (Tcl 8.3 ONLY).
#
# Tcl 8.3 restrictions:
#   * no "eq"/"ne" operators, no "file normalize"/"file join", no "lassign"/"try"
#
# Report channels:
#   * file  tclprobe.log        (cwd = game folder)
#   * error channel              -> engine logs it to tclerrors.txt
#
# This probe only READS the option system and the key/camera bindings.

set ::fh ""
if {![catch {set ::fh [open "tclprobe.log" w]}]} {
    catch {fconfigure $::fh -translation lf}
}
set ::tag "init"
if {[info exists ::argv] && [llength $::argv] > 0} { set ::tag [lindex $::argv 0] }

proc w {text} {
    global fh
    if {[string length $fh] > 0} {
        catch {puts $fh $text}
        catch {flush $fh}
    }
}

proc r {text} { w $text }

r ""
r "######## SNAPSHOT $::tag ########"

# --- option system -------------------------------------------------------------
set ::lowernames {maxgametimefactor nogamespeedlock persistoptions usetclclasscache \
    buttonmapping panning zoom tilt panmousefactor simplecontrol borderscroll \
    mousescroll keyscroll zoomspeedfactor viewmodifier altmodifier panmodifier \
    zoommodifier tiltmodifier maxframerate gamesavecompression pauseondeactivate \
    redundantstatechanges notbremse reversestereo showsubtext colormipmaps \
    maxshadowlightdist autodigrange autoharvestrange webserver evtframeskip \
    threadpriority minthreadsleep dipyieldthreshold texturequality texvideomemlimit \
    objectquality landscapequality playeraidefault animipol oldprodcontrol \
    validaterenderjobs bordermask particles lightglow scapejitter useidiobjs \
    lazytextureload useenvmapping scapelight showfmv showquotes worldisinvalid \
    animstats perfstats}

set ::listed {}
catch {set ::listed [option list]}
r "option list = $::listed"

foreach o $::lowernames {
    if {[catch {set v [option get $o]} err]} {
        r "option get $o -> ERROR: $err"
    } else {
        set n ""
        catch {set n [option getname $o]}
        set d ""
        catch {set d [option getdesc $o]}
        set i ""
        catch {set i [option getinfo $o]}
        r "option $o = $v | name=$n | desc=$d | info=$i"
    }
}

# names reported by the option system itself
foreach o $::listed {
    set v "?"
    catch {set v [option get $o]}
    set n "?"
    catch {set n [option getname $o]}
    set d "?"
    catch {set d [option getdesc $o]}
    r "listed option $o = $v | name=$n | desc=$d"
}

# --- camera + key bindings -----------------------------------------------------
catch {r "camctrlmapping desc = [camctrlmapping desc]"}
catch {r "camctrlmapping noargs = [camctrlmapping]"}
catch {r "keybind current = [keybind current]"}
catch {r "inputmode = [inputmode]"}
catch {r "gametime factor = [gametime factor]"}
catch {r "get_cameramoving = [get_cameramoving]"}

r "######## END $::tag ########"

if {$::tag ne "init"} {
    error "PROBE-V8-DONE $::tag"
}
