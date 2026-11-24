$ErrorActionPreference = 'Stop'
$dir = Split-Path -Parent $MyInvocation.MyCommand.Path
$dll = Join-Path $dir 'DigglesPort.dll'
$bak = Join-Path $dir 'DigglesPort.dll.orig'
$ver = Join-Path $dir 'WasdVerify.exe'
$log = Join-Path $env:TEMP 'diggles-wasd-patch.log'

function Say($msg) {
    Write-Host $msg
    Add-Content -LiteralPath $log -Value ("[{0}] {1}" -f (Get-Date -Format 'HH:mm:ss'), $msg)
}

Say '--- Diggles WASD camera patch ---'

$running = Get-Process -Name Diggles -ErrorAction SilentlyContinue
if ($running) {
    Say 'ERROR: Diggles.exe is still running - close the game first (old DLL is already loaded in memory).'
    exit 1
}

if (-not (Test-Path $dll)) {
    Say ('ERROR: DigglesPort.dll not found next to this script: ' + $dll)
    exit 1
}

if (-not (Test-Path $bak)) { Copy-Item $dll $bak; Say 'Backup created: DigglesPort.dll.orig' }

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
            Say ('  [ok] ' + $p.Name + ' already applied')
        }
        else {
            Say ('  [!!] ' + $p.Name + ' pattern not found - DLL version differs?')
        }
        continue
    }
    for ($i = 0; $i -lt 4; $i++) { $data[$idx + $i] = $newB[$i] }
    $changed++
    Say ('  [ok] ' + $p.Name + ' patched at offset 0x' + $idx.ToString('X6'))
}

if ($changed -gt 0) {
    [System.IO.File]::WriteAllBytes($dll, $data)
    Say ('Patched ' + $changed + ' constant(s).')
}
else {
    Say ('Nothing to patch (changed=0, already=' + $already + ').')
}

if (Test-Path $ver) {
    Say 'Verification (A/D/S/W must map to 25/27/28/26):'
    & $ver $dll 2>&1 | ForEach-Object { Say ('  ' + $_) }
}
else {
    Say 'Verifier WasdVerify.exe not found - skipping verification.'
}

Say 'Done. Start the game now.'
exit 0
