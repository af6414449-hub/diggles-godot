$ErrorActionPreference = 'Stop'

# Test runner for the final userinit script:
#   - installs userinit-wasd-x8.tcl into the sandbox game
#   - launches the sandbox game (fake Steam app id)
#   - sends real W/A/S/D keystrokes to the game window
#   - stops the game and prints the log the script produced
#
# NOTE: keep this file pure ASCII - the project path contains non-ASCII characters.

$root    = $PSScriptRoot
$sb      = Join-Path $root 'sandbox\Diggles'
$probe   = Join-Path $root 'userinit-wasd-x8.tcl'
$log     = Join-Path $sb 'diggles_userinit.log'
$err     = Join-Path $sb 'tclerrors.txt'
$waitKey = 25

foreach ($f in @($log, $err)) {
    if (Test-Path $f) { Move-Item $f ($f + '.prev') -Force }
}

Copy-Item $probe (Join-Path $sb 'Data\userinit.tcl') -Force
Write-Output ('installed: ' + (Get-Item (Join-Path $sb 'Data\userinit.tcl')).Length + ' bytes')

$env:SteamAppId  = '1478650'
$env:SteamGameId = '1478650'

$p = Start-Process -FilePath (Join-Path $sb 'Diggles.exe') -WorkingDirectory $sb -PassThru
Write-Output ('launched pid=' + $p.Id)

$sw = [Diagnostics.Stopwatch]::StartNew()
while ($sw.Elapsed.TotalSeconds -lt $waitKey) {
    Start-Sleep -Seconds 3
    $alive = $true
    try { $alive = -not $p.HasExited } catch { $alive = $false }
    $li = 'nolog'
    if (Test-Path $log) { $li = 'log=' + (Get-Item $log).Length + 'B' }
    Write-Output ('t=' + [int]$sw.Elapsed.TotalSeconds + 's alive=' + $alive + ' ' + $li)
    if (-not $alive) { break }
}

$alive = $true
try { $alive = -not $p.HasExited } catch { $alive = $false }
Write-Output ('alive before keys: ' + $alive)

if ($alive) {
    $ws = New-Object -ComObject WScript.Shell
    Write-Output ('window title: [' + $p.MainWindowTitle + ']')
    if ($ws.AppActivate($p.Id)) { Write-Output 'AppActivate: OK' } else { Write-Output 'AppActivate: FAILED' }
    Start-Sleep -Seconds 2
    foreach ($k in @('w','a','s','d')) {
        $ws.SendKeys($k)
        Write-Output ('sent key: ' + $k)
        Start-Sleep -Seconds 2
    }
    Start-Sleep -Seconds 3
}

try {
    if (-not $p.HasExited) { Stop-Process -Id $p.Id -Force; Write-Output 'process stopped' }
    else { Write-Output ('process exited code=' + $p.ExitCode) }
} catch {
    Write-Output ('stop failed: ' + $_.Exception.Message)
}

Start-Sleep -Seconds 2
Write-Output '--- diggles_userinit.log ---'
if (Test-Path $log) { Get-Content $log } else { Write-Output 'MISSING' }
Write-Output '--- tclerrors.txt ---'
if (Test-Path $err) { Get-Content $err } else { Write-Output 'MISSING' }
