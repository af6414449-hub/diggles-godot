<#
.SYNOPSIS
    Headless Ghidra pipeline for Diggles.exe: import -> analyze -> decompile -> index.

.DESCRIPTION
    Runs Ghidra in batch mode against Diggles.exe, then executes the
    ExportDiggles post-script which writes decompiled C for every function,
    an index TSV, the string table and the class list.

    The optional names TSV (name<TAB>0xVA) renames functions before export, so
    the decompiled C carries meaningful names for the native Tcl commands.

.EXAMPLE
    .\run_ghidra.ps1 -Exe "..\ref\Diggles.exe" -Out "C:\diggles-ghidra" -Names "..\ref\tcl_commands.tsv"
#>
[CmdletBinding()]
param(
    [string]$Ghidra   = "C:\ghidra",
    [string]$Exe      = "$PSScriptRoot\..\ref\Diggles.exe",
    [string]$Out      = "C:\diggles-ghidra",
    [string]$Project  = "C:\diggles-ghidra\project",
    [string]$Names    = "",
    [int]$MaxRamMB    = 3072
)

$ErrorActionPreference = "Stop"

$analyze = Join-Path $Ghidra "support\analyzeHeadless.bat"
if (-not (Test-Path $analyze)) {
    throw "analyzeHeadless not found at $analyze (expected Ghidra install in '$Ghidra')"
}
if (-not (Test-Path $Exe)) {
    throw "exe not found: $Exe"
}

New-Item -ItemType Directory -Force -Path $Out | Out-Null
New-Item -ItemType Directory -Force -Path $Project | Out-Null

$script = Join-Path $PSScriptRoot "ExportDiggles.java"
$argsList = @(
    $Project, "Diggles",
    "-import", $Exe,
    "-analysisTimeoutPerFile", "3600",
    "-scriptPath", $PSScriptRoot,
    "-postScript", "ExportDiggles.java", $Out
)
if ($Names -and (Test-Path $Names)) {
    $argsList += $Names
}

Write-Host "[ghidra] $($analyze)"
Write-Host "[ghidra] project=$Project out=$Out"
$sw = [Diagnostics.Stopwatch]::StartNew()
& $analyze @argsList
Write-Host "[ghidra] finished in $([math]::Round($sw.Elapsed.TotalMinutes,1)) min"

$index = Join-Path $Out "index.tsv"
if (Test-Path $index) {
    $rows = Import-Csv -Delimiter "`t" $index
    $ok = ($rows | Where-Object { $_.status -eq "ok" }).Count
    Write-Host "[ghidra] functions: $($rows.Count), decompiled ok: $ok"
    Write-Host "[ghidra] index: $index"
}
