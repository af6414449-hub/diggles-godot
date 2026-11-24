param(
	[string]$Script,
	[string]$Godot,
	[string]$Project = '',
	[string]$Tag = 'run'
)
$ErrorActionPreference = 'Stop'
$root = Split-Path $PSScriptRoot -Parent
if ([string]::IsNullOrEmpty($Project)) { $Project = Join-Path $root 'godot' }
$logDir = Join-Path $root 'out\testlogs'
if (-not (Test-Path $logDir)) { New-Item -ItemType Directory -Path $logDir | Out-Null }
$stem = [IO.Path]::GetFileNameWithoutExtension($Script)
$log = Join-Path $logDir ($stem + '-' + $Tag + '.log')
$err = $log + '.err'
$p = Start-Process -FilePath $Godot -ArgumentList @('--headless', '--path', $Project, '--script', ('res://tools/' + $Script)) -RedirectStandardOutput $log -RedirectStandardError $err -PassThru -NoNewWindow
if (-not $p.WaitForExit(60000)) {
	Stop-Process -Id $p.Id -Force
	Write-Output 'TIMEOUT'
	exit 2
}
Write-Output ('EXIT=' + $p.ExitCode)
Write-Output '--- stdout tail ---'
if (Test-Path $log) { Get-Content $log -Encoding UTF8 | Select-Object -Last 40 }
Write-Output '--- stderr tail ---'
if (Test-Path $err) { Get-Content $err -Encoding UTF8 | Select-Object -Last 40 }
