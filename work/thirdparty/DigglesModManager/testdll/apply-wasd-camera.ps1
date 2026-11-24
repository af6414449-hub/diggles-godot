$ErrorActionPreference = 'Stop'
$dir = Split-Path -Parent $MyInvocation.MyCommand.Path
$dll = Join-Path $dir 'DigglesPort.dll'
$bak = Join-Path $dir 'DigglesPort.dll.orig'

if (-not (Test-Path $dll)) {
    Write-Host 'ERROR: DigglesPort.dll not found next to this script.' -ForegroundColor Red
    exit 1
}

$game = Get-Process -Name Diggles -ErrorAction SilentlyContinue
if ($game) {
    Write-Host 'ERROR: the game is running - close it first.' -ForegroundColor Red
    exit 1
}

if (-not (Test-Path $bak)) { Copy-Item $dll $bak }

$enc = [System.Text.Encoding]::GetEncoding(28591)
$data = [System.IO.File]::ReadAllBytes($dll)
$txt = $enc.GetString($data)

$pairs = @(
    @{ Old = [uint32]0x00410004; New = [uint32]0x00250004; Name = 'A -> Left  ' },
    @{ Old = [uint32]0x00440007; New = [uint32]0x00270007; Name = 'D -> Right ' },
    @{ Old = [uint32]0x00530016; New = [uint32]0x00280016; Name = 'S -> Down  ' },
    @{ Old = [uint32]0x0057001A; New = [uint32]0x0026001A; Name = 'W -> Up    ' }
)

$changed = 0
$already = 0
foreach ($p in $pairs) {
    $oldB = [BitConverter]::GetBytes($p.Old)
    $newB = [BitConverter]::GetBytes($p.New)
    $pat = $enc.GetString($oldB)
    $idx = $txt.IndexOf($pat)
    if ($idx -lt 0) {
        if ($txt.IndexOf($enc.GetString($newB)) -ge 0) {
            $already++
            Write-Host ("  [ok] {0} already applied" -f $p.Name)
        }
        else {
            Write-Host ("  [!!] {0} pattern not found - DLL version differs?" -f $p.Name) -ForegroundColor Yellow
        }
        continue
    }
    for ($i = 0; $i -lt 4; $i++) { $data[$idx + $i] = $newB[$i] }
    $changed++
    Write-Host ("  [ok] {0} patched at offset 0x{1:X6}" -f $p.Name, $idx)
}

if ($changed -gt 0) {
    [System.IO.File]::WriteAllBytes($dll, $data)
}

Write-Host ("WASD camera patch: changed={0} already={1}" -f $changed, $already)
Write-Host 'Backup of the original file: DigglesPort.dll.orig'
exit 0
