$ErrorActionPreference = 'Stop'

# Smoke test for the black-fog removal script (v6, no "call" hook).
# Launches Diggles, watches diggles_nofog.log and tclerrors.txt, then closes
# the game again. The game needs 2.5-4 min to reach the menu (Tcl phase).
#
# NOTE: this file must stay ASCII only - PowerShell 5.1 reads .ps1 without BOM
# as ANSI and a non-ASCII path literal would break the parser.

$game = 'C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris'
$log  = Join-Path $game 'diggles_nofog.log'
$err  = Join-Path $game 'tclerrors.txt'
$src  = Join-Path $PSScriptRoot 'userinit-nofog.tcl'

# install
Copy-Item -LiteralPath $src -Destination (Join-Path $game 'data\userinit.tcl') -Force
Write-Output 'installed userinit.tcl'

# archive old artefacts
foreach ($f in @($log, $err)) {
    if (Test-Path -LiteralPath $f) { Move-Item -LiteralPath $f -Destination ($f + '.prev') -Force }
}

$env:SteamAppId  = '1478650'
$env:SteamGameId = '1478650'

$p = Start-Process -FilePath (Join-Path $game 'Diggles.exe') -WorkingDirectory $game -PassThru
Write-Output ('launched pid=' + $p.Id)

$sw = [Diagnostics.Stopwatch]::StartNew()
$done = $false
while ($sw.Elapsed.TotalSeconds -lt 300) {
    Start-Sleep -Seconds 5
    $alive = $true
    try { $alive = -not $p.HasExited } catch { $alive = $false }
    $state = 'nolog'
    if (Test-Path -LiteralPath $log) {
        $txt = Get-Content -LiteralPath $log -Raw -ErrorAction SilentlyContinue
        if ($txt -ne $null) {
            $state = 'log=' + $txt.Length + 'B'
            if ($txt -match 'show_loading: remove_black_fog') { $done = $true }
        }
    }
    $errSize = 0
    if (Test-Path -LiteralPath $err) {
        $errSize = (Get-Item -LiteralPath $err).Length
    }
    Write-Output ('t=' + [int]$sw.Elapsed.TotalSeconds + 's alive=' + $alive + ' ' + $state + ' tclerr=' + $errSize + 'B')
    if ($done) { break }
    if (-not $alive) { Write-Output 'game exited early'; break }
}

# let it run a bit longer, so a late crash would show up
Start-Sleep -Seconds 20
try { if (-not $p.HasExited) { Stop-Process -Id $p.Id -Force; Write-Output 'process stopped' } }
catch { Write-Output ('stop failed: ' + $_.Exception.Message) }

Start-Sleep -Seconds 2
Write-Output '--- diggles_nofog.log ---'
if (Test-Path -LiteralPath $log) { Get-Content -LiteralPath $log } else { Write-Output 'MISSING' }
Write-Output '--- tclerrors.txt (first 15 lines) ---'
if (Test-Path -LiteralPath $err) {
    $e = Get-Content -LiteralPath $err -TotalCount 15
    if ($e -eq $null) { Write-Output 'EMPTY -> no Tcl errors' } else { $e }
} else { Write-Output 'MISSING -> no Tcl errors' }
Write-Output '--- crash dumps ---'
Get-ChildItem -LiteralPath $game -Filter '*.dmp' -ErrorAction SilentlyContinue |
    Select-Object Name, Length, LastWriteTime | Format-Table -AutoSize
