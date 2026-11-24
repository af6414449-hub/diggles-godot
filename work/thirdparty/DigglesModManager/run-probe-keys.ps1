$ErrorActionPreference = 'Stop'

# Runner: install a probe, launch the sandbox game, send real keystrokes to the
# game window, then stop the game and report.
# Usage: run-probe-keys.ps1 <probe-file-name> [wait-before-keys] [keys]
#
# NOTE: keep this file pure ASCII - the project path contains non-ASCII characters.

$root    = $PSScriptRoot
$sb      = Join-Path $root 'sandbox\Diggles'
$probe   = Join-Path $root $args[0]
$waitKey = 22
if ($args.Count -ge 2) { $waitKey = [int]$args[1] }
$keys    = 'w'
if ($args.Count -ge 3) { $keys = $args[2] }

$log    = Join-Path $sb 'tclprobe.log'
$err    = Join-Path $sb 'tclerrors.txt'
$marker = Join-Path $sb 'probe_marker.txt'
$camlog = Join-Path $sb 'camtest.log'

foreach ($f in @($log, $err, $marker, $camlog)) {
    if (Test-Path $f) { Move-Item $f ($f + '.prev') -Force }
}

Copy-Item $probe (Join-Path $sb 'Data\userinit.tcl') -Force
$installed = Join-Path $sb 'Data\userinit.tcl'
Write-Output ('probe installed: ' + (Get-Item $installed).Length + ' bytes, sha1=' + (Get-FileHash $installed -Algorithm SHA1).Hash.Substring(0,12))

$env:SteamAppId  = '1478650'
$env:SteamGameId = '1478650'

$p = Start-Process -FilePath (Join-Path $sb 'Diggles.exe') -WorkingDirectory $sb -PassThru
Write-Output ('launched pid=' + $p.Id)

Start-Sleep -Seconds $waitKey

$alive = $true
try { $alive = -not $p.HasExited } catch { $alive = $false }
Write-Output ('alive before keys: ' + $alive)
Write-Output ('marker exists: ' + (Test-Path $marker) + ' | log exists: ' + (Test-Path $log))
if (Test-Path $marker) { Write-Output ('marker content: ' + ((Get-Content $marker) -join '|')) }

if ($alive) {
    # focus the game window and send keystrokes
    $ws = New-Object -ComObject WScript.Shell
    $title = $p.MainWindowTitle
    Write-Output ('window title: [' + $title + ']')
    if ($ws.AppActivate($p.Id)) { Write-Output 'AppActivate by pid: OK' } else { Write-Output 'AppActivate by pid: FAILED' }
    Start-Sleep -Milliseconds 800
    foreach ($k in $keys.ToCharArray()) {
        $ws.SendKeys($k)
        Write-Output ('sent key: ' + $k)
        Start-Sleep -Milliseconds 700
    }
    Start-Sleep -Seconds 4
}

try {
    if (-not $p.HasExited) { Stop-Process -Id $p.Id -Force; Write-Output 'process stopped' }
    else { Write-Output ('process exited code=' + $p.ExitCode) }
} catch {
    Write-Output ('stop failed: ' + $_.Exception.Message)
}

Start-Sleep -Seconds 2
Write-Output '--- results ---'
foreach ($f in @($log, $err, $marker, $camlog)) {
    if (Test-Path $f) { Write-Output ((Split-Path $f -Leaf) + ' : ' + (Get-Item $f).Length + ' bytes') }
    else { Write-Output ((Split-Path $f -Leaf) + ' : MISSING') }
}
if (Test-Path $camlog) { Write-Output '--- camtest.log ---'; Get-Content $camlog }
