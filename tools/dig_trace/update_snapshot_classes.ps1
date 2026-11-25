param([switch]$Apply)

$ErrorActionPreference = 'Stop'
$gameScript = 'C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\Scripts\classes\zwerg\z_dignwalk.tcl'
$helperSource = Join-Path $PSScriptRoot 'dwarf_helpers.tcl'
$backupDir = Join-Path $PSScriptRoot 'backups'
$encoding = [System.Text.Encoding]::GetEncoding(28591)
if (Get-Process -Name Diggles -ErrorAction SilentlyContinue) { throw 'Close Diggles before updating its diagnostic script.' }
$original = $encoding.GetString([System.IO.File]::ReadAllBytes($gameScript))
$helper = Get-Content -LiteralPath $helperSource -Raw -Encoding UTF8
$pattern = '(?s)proc digtrace_class_objects \{\} \{.*?\r?\n\}\r?\n\r?\n(?=proc digtrace_class_snapshot)'
$match = [regex]::Match($original, $pattern)
$sourceMatch = [regex]::Match($helper, $pattern)
if (-not $match.Success -or -not $sourceMatch.Success -or [regex]::Matches($original, $pattern).Count -ne 1) {
    throw 'Expected unique diagnostic object-query procedure was not found.'
}
$replacement = [regex]::Replace($sourceMatch.Value, '\r?\n', "`r`n")
$updated = $original.Substring(0, $match.Index) + $replacement + $original.Substring($match.Index + $match.Length)
Write-Output "Current SHA256: $((Get-FileHash -LiteralPath $gameScript -Algorithm SHA256).Hash)"
Write-Output "New object query includes cave skins and roots: $($updated.Contains('Dummy_Urw_caves_')) / $($updated.Contains('Dummy_Wurzel_'))"
if (-not $Apply) { Write-Output 'Dry run OK; use -Apply to update the original installation.'; return }
New-Item -ItemType Directory -Path $backupDir -Force | Out-Null
$backup = Join-Path $backupDir ('z_dignwalk.pre-classes.' + (Get-Date -Format 'yyyyMMdd-HHmmss') + '.tcl')
Copy-Item -LiteralPath $gameScript -Destination $backup
try {
    [System.IO.File]::WriteAllBytes($gameScript, $encoding.GetBytes($updated))
} catch {
    Copy-Item -LiteralPath $backup -Destination $gameScript
    throw
}
Write-Output "Backup: $backup"
Write-Output "Updated SHA256: $((Get-FileHash -LiteralPath $gameScript -Algorithm SHA256).Hash)"
