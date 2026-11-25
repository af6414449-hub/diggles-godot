param([switch]$Install, [switch]$Upgrade)

$ErrorActionPreference = 'Stop'
$game = 'C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris'
$userInit = Join-Path $game 'data\userinit.tcl'
$digScript = Join-Path $game 'data\Scripts\classes\zwerg\z_dignwalk.tcl'
$moduleTarget = Join-Path $game 'data\dig_trace.tcl'
$moduleSource = Join-Path $PSScriptRoot 'dig_trace.tcl'
$helperSource = Join-Path $PSScriptRoot 'dwarf_helpers.tcl'
$backupDir = Join-Path $PSScriptRoot 'backups'
$encoding = [System.Text.Encoding]::GetEncoding(28591)
$crlf = [string][char]13 + [string][char]10

function Normalize-Newlines([string]$value) {
    return [regex]::Replace($value, '\r?\n', $crlf)
}

if ($Install -and $Upgrade) { throw 'Choose either -Install or -Upgrade.' }
if (-not (Test-Path -LiteralPath $userInit) -or -not (Test-Path -LiteralPath $digScript)) {
    throw 'Expected Diggles installation was not found.'
}
if (($Install -or $Upgrade) -and (Get-Process -Name Diggles -ErrorAction SilentlyContinue)) {
    throw 'Close Diggles before changing its scripts.'
}

$oldInit = $encoding.GetString([System.IO.File]::ReadAllBytes($userInit))
$oldDig = $encoding.GetString([System.IO.File]::ReadAllBytes($digScript))
$helper = Normalize-Newlines (Get-Content -LiteralPath $helperSource -Raw -Encoding UTF8)
$helper = $helper.TrimEnd([char]13, [char]10)
$classMarker = '# DIGTRACE_CLASS_V2'
$v1Marker = '# DIGTRACE_SOURCE_V1'
$v2Marker = '# DIGTRACE_SOURCE_V2'
$v1Block = Normalize-Newlines (@'
set digtrace_before ""
catch {set digtrace_before [digtrace_before_apply $digpoint this]}
set digtrace_apply_result [dig_apply $digpoint this]
catch {digtrace_after_apply $digpoint this $digtrace_before $digtrace_apply_result}
if {$digtrace_apply_result} {
'@).TrimEnd([char]13, [char]10)
$v2Block = Normalize-Newlines (@'
set digtrace_before ""
catch {set digtrace_before [digtrace_class_before $digpoint]}
set digtrace_apply_result [dig_apply $digpoint this]
catch {digtrace_class_after $digpoint $digtrace_before $digtrace_apply_result}
if {$digtrace_apply_result} {
'@).TrimEnd([char]13, [char]10)
$indent = ([string][char]9) * 4
$v2Block = $v2Block.Replace($crlf, $crlf + $indent)
$freshAnchor = 'if {[dig_apply $digpoint this]} {'
$entryAnchor = 'proc dig_execute {digpoint} {'
$helperAnchor = '// ----------------------------------------------------------------------'
$isV1 = $oldInit.Contains($v1Marker) -and $oldDig.Contains('digtrace_before_apply')
$isV2 = $oldInit.Contains($v2Marker) -or $oldDig.Contains($classMarker)
if ($isV2) { throw 'Dig trace v2 is already installed; nothing was changed.' }
if ($oldInit.Contains($v1Marker) -ne $oldDig.Contains('digtrace_before_apply')) {
    throw 'Partial v1 install detected; inspect files manually before changing them.'
}
if ($isV1) {
    if ($Install) { throw 'v1 is installed. Use -Upgrade.' }
    if ([regex]::Matches($oldDig, [regex]::Escape($v1Block)).Count -ne 1) {
        throw 'The v1 dig block is missing or duplicated.'
    }
    $newDig = $oldDig.Replace($v1Block, $v2Block)
    $newInit = $oldInit
    $mode = 'upgrade'
} else {
    if ($Upgrade) { throw 'No v1 install found. Use -Install.' }
    if ([regex]::Matches($oldDig, [regex]::Escape($freshAnchor)).Count -ne 1) {
        throw 'The original dig_apply anchor is missing or duplicated.'
    }
    $newDig = $oldDig.Replace($freshAnchor, $v2Block)
    $newInit = $oldInit + $crlf + $v2Marker + $crlf +
        'if {[catch {source "data/dig_trace.tcl"} digtrace_load_error]} {' + $crlf +
        '    catch {nofog_log "digtrace load FAILED: $digtrace_load_error"}' + $crlf +
        '}' + $crlf
    $mode = 'install'
}

if ([regex]::Matches($newDig, [regex]::Escape($entryAnchor)).Count -ne 1) {
    throw 'The dig_execute entry is missing or duplicated.'
}
$entryTrace = 'catch {digtrace_class_emit dig_execute [list point $digpoint actor_pos [get_pos this] main_helper_visible [info commands digtrace_before_apply]]}'
$newDig = $newDig.Replace($entryAnchor, $entryAnchor + $crlf + [string][char]9 + $entryTrace)
foreach ($entry in @(
    @('set digpoint [vector_add [dig_next $cpos this $try] {0 0 -1}]', 'offset_down'),
    @('set digpoint [dig_next $cpos this $try]', 'normal'),
    @('set digpoint [dig_next $thispos this 1 1]', 'retry')
)) {
    $anchor = $entry[0]
    $branch = $entry[1]
    if ([regex]::Matches($newDig, [regex]::Escape($anchor)).Count -ne 1) {
        throw "The dig_next anchor '$branch' is missing or duplicated."
    }
    $trace = 'catch {digtrace_class_emit dig_next [list branch ' + $branch + ' point $digpoint actor_pos [get_pos this]]}'
    $newDig = $newDig.Replace($anchor, $anchor + $crlf + [string][char]9 + $trace)
}
$helperIndex = $newDig.IndexOf($helperAnchor, [System.StringComparison]::Ordinal)
if ($helperIndex -lt 0) { throw 'The class script insertion point is missing.' }
$newDig = $newDig.Insert($helperIndex, $helper + $crlf + $crlf)

Write-Output "Mode: $mode"
Write-Output "Current userinit SHA256: $((Get-FileHash -LiteralPath $userInit -Algorithm SHA256).Hash)"
Write-Output "Current dig script SHA256: $((Get-FileHash -LiteralPath $digScript -Algorithm SHA256).Hash)"
Write-Output "Trace output: $(Join-Path $game 'diggles_dig_trace.jsonl')"
if (-not $Install -and -not $Upgrade) {
    Write-Output "Dry run OK; no files changed. Use -$mode to create backups and apply v2."
    return
}

New-Item -ItemType Directory -Path $backupDir -Force | Out-Null
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$initBackup = Join-Path $backupDir "userinit.pre-v2.$stamp.tcl"
$digBackup = Join-Path $backupDir "z_dignwalk.pre-v2.$stamp.tcl"
$moduleBackup = Join-Path $backupDir "dig_trace.pre-v2.$stamp.tcl"
$hadModule = Test-Path -LiteralPath $moduleTarget
Copy-Item -LiteralPath $userInit -Destination $initBackup
Copy-Item -LiteralPath $digScript -Destination $digBackup
if ($hadModule) { Copy-Item -LiteralPath $moduleTarget -Destination $moduleBackup }
try {
    Copy-Item -LiteralPath $moduleSource -Destination $moduleTarget -Force
    [System.IO.File]::WriteAllBytes($digScript, $encoding.GetBytes($newDig))
    if ($mode -eq 'install') {
        [System.IO.File]::WriteAllBytes($userInit, $encoding.GetBytes($newInit))
    }
    Write-Output "Applied v2. Backups: $initBackup and $digBackup"
} catch {
    Copy-Item -LiteralPath $initBackup -Destination $userInit -Force
    Copy-Item -LiteralPath $digBackup -Destination $digScript -Force
    if ($hadModule) {
        Copy-Item -LiteralPath $moduleBackup -Destination $moduleTarget -Force
    } else {
        Remove-Item -LiteralPath $moduleTarget -Force -ErrorAction SilentlyContinue
    }
    throw
}
