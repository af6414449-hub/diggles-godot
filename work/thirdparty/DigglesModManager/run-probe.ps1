$ErrorActionPreference = 'Stop'

# Runner for Diggles probes: launches the sandbox game with a fake Steam app id,
# waits, then stops the process and reports what the probe produced.
# Usage: run-probe.ps1 <probe-file-name> [wait-seconds]
#
# NOTE: keep this file pure ASCII - the project path contains non-ASCII characters
# and PowerShell 5.1 would mis-decode a BOM-less UTF-8 file.

$root    = $PSScriptRoot
$sb      = Join-Path $root 'sandbox\Diggles'
$probe   = Join-Path $root $args[0]
$waitSec = 40
if ($args.Count -ge 2) { $waitSec = [int]$args[1] }

$log = Join-Path $sb 'tclprobe.log'
$err = Join-Path $sb 'tclerrors.txt'

foreach ($f in @($log, $err)) {
    if (Test-Path $f) {
        Move-Item $f ($f + '.prev') -Force
    }
}

Copy-Item $probe (Join-Path $sb 'Data\userinit.tcl') -Force
Write-Output ('probe installed: ' + (Get-Item (Join-Path $sb 'Data\userinit.tcl')).Length + ' bytes')

$env:SteamAppId  = '1478650'
$env:SteamGameId = '1478650'

$p = Start-Process -FilePath (Join-Path $sb 'Diggles.exe') -WorkingDirectory $sb -PassThru
Write-Output ('launched pid=' + $p.Id)

$sw = [Diagnostics.Stopwatch]::StartNew()
while ($sw.Elapsed.TotalSeconds -lt $waitSec) {
    Start-Sleep -Seconds 3
    $alive = $true
    try { $alive = -not $p.HasExited } catch { $alive = $false }
    $logInfo = 'nolog'
    if (Test-Path $log) { $logInfo = 'log=' + (Get-Item $log).Length + 'B' }
    $errInfo = 'noerr'
    if (Test-Path $err) { $errInfo = 'err=' + (Get-Item $err).Length + 'B' }
    Write-Output ('t=' + [int]$sw.Elapsed.TotalSeconds + 's alive=' + $alive + ' ' + $logInfo + ' ' + $errInfo)
    if (-not $alive) { break }
}

try {
    if (-not $p.HasExited) { Stop-Process -Id $p.Id -Force; Write-Output 'process stopped' }
    else { Write-Output ('process exited code=' + $p.ExitCode) }
} catch {
    Write-Output ('stop failed: ' + $_.Exception.Message)
}

Start-Sleep -Seconds 2
Write-Output '--- results ---'
foreach ($f in @($log, $err)) {
    if (Test-Path $f) { Write-Output ($f + ' : ' + (Get-Item $f).Length + ' bytes') }
    else { Write-Output ($f + ' : MISSING') }
}
