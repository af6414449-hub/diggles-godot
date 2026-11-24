# probe-engine.tcl - diagnostic script for the original Diggles.
#
# The game embeds Tcl 8.3 - only Tcl 8.3 commands may be used here:
#   * "eq" / "ne" operators  -> Tcl 8.4+  (use "string equal")
#   * "file normalize"        -> Tcl 8.4+
#   * "file join"             -> Tcl 8.5+
#   * "lassign" / "try"       -> Tcl 8.5 / 8.6+
#
# Output channels, in priority order:
#   1. stdout (the launcher redirects it to a file)
#   2. a file next to this script (info script dirname)
#   3. a file in the current working directory
#
# Robustness rules:
#   * every step is wrapped in catch -> a failing step cannot abort the script
#   * every line is flushed immediately -> a crash later still leaves data on disk
#   * never reference a variable that was not set by the immediately preceding catch

set ::out ""
catch {set ::out stdout}

proc emit {text} {
    global out probe_fh
    catch {puts $out $text}
    catch {flush $out}
    if {[info exists probe_fh] && [string length $probe_fh] > 0} {
        catch {puts $probe_fh $text}
        catch {flush $probe_fh}
    }
}

# --- open a file copy ----------------------------------------------------------
set ::probe_fh ""
catch {
    set ::probe_script [info script]
    set ::probe_dir [file dirname $::probe_script]
}
if {![info exists probe_dir]} { set ::probe_dir "." }
foreach cand [list "$::probe_dir/tclprobe.log" "tclprobe.log" "data/tclprobe.log" "Data/tclprobe.log"] {
    if {[string length $::probe_fh] > 0} { break }
    if {![catch {set h [open $cand w]}]} {
        set ::probe_fh $h
        set ::probe_where $cand
    }
}

proc p {label script} {
    set code [catch {uplevel 1 $script} res]
    if {$code == 0} {
        emit "$label = $res"
    } else {
        emit "$label = <ERROR: $res>"
    }
    return $res
}

emit "=== Diggles probe ==="
p "cwd" {pwd}
p "info_script" {info script}
p "argv" {$::argv}
p "tcl_version" {info patchlevel}
p "system_name" {get_system_name}
if {[info exists probe_where]} { emit "logfile = $::probe_where" }

# --- full list of commands available in the game interpreter -------------------
proc dump_commands {fname} {
    set code [catch {lsort [info commands]} lst]
    if {$code != 0} { emit "info commands ERROR: $lst" ; return }
    set h ""
    if {![catch {set h [open $fname w]}]} {
        foreach c $lst { catch {puts $h $c} }
        catch {close $h}
    }
    emit "commands: [llength $lst] items"
    foreach c $lst { emit "  CMD $c" }
}
catch {dump_commands "tcl-commands.txt"}

# --- options (speed cap, etc.) -------------------------------------------------
p "option maxgametimefactor" {option get maxgametimefactor}
p "option getname maxgametimefactor" {option getname maxgametimefactor}
p "option nogamespeedlock" {option get nogamespeedlock}
p "option persistoptions" {option get persistoptions}
p "option usetclclasscache" {option get usetclclasscache}
p "option buttonmapping" {option get buttonmapping}
p "option getname buttonmapping" {option getname buttonmapping}
p "option getinfo buttonmapping" {option getinfo buttonmapping}
p "option getdesc buttonmapping" {option getdesc buttonmapping}
p "option list" {option list}

# --- camera control mapping ----------------------------------------------------
p "camctrlmapping desc" {camctrlmapping desc}
for {set i 0} {$i < 6} {incr i} {
    p "camctrl slot $i" "camctrlmapping $i"
}

# --- key bindings --------------------------------------------------------------
p "keybind keynames" {keybind keynames}
p "keybind current" {keybind current}
p "keybind noargs" {keybind}

# --- view state ----------------------------------------------------------------
p "get_view" {get_view}
p "get_cameramoving" {get_cameramoving}
p "get_camerafollowdist" {get_camerafollowdist}

emit "=== end of report ==="
catch {close $::probe_fh}
catch {flush $out}
