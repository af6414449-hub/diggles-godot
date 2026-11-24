$ErrorActionPreference = 'Stop'

# Short smoke test: launch Diggles, wait for the nofog log to show that
# data/userinit.tcl was executed, then close the game again.

$game = 'C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris'
$log  = Join-Path $game 'diggles_nofog.log'

if (Test-Path -LiteralPath $log) { Move-Item -LiteralPath $log -Destination ($log + '.prev') -Force }

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
    Write-Output ('t=' + [int]$sw.Elapsed.TotalSeconds + 's alive=' + $alive + ' ' + $state)
    if ($done) { break }
    if (-not $alive) { Write-Output 'game exited early'; break }
}

if ($done) { Start-Sleep -Seconds 15 }
try { if (-not $p.HasExited) { Stop-Process -Id $p.Id -Force; Write-Output 'process stopped' } }
catch { Write-Output ('stop failed: ' + $_.Exception.Message) }

Start-Sleep -Seconds 2
Write-Output '--- diggles_nofog.log ---'
if (Test-Path -LiteralPath $log) { Get-Content -LiteralPath $log } else { Write-Output 'MISSING' }
