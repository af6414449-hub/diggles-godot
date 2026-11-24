param(
	[string]$Godot,
	[string]$Project,
	[string]$Out,
	[string]$Scene = 'res://scenes/campaign_first_level.tscn',
	[string]$Driver = 'vulkan',
	[string]$ExtraArgs = '',
	[int]$TimeoutSec = 300
)
$ErrorActionPreference = 'Stop'
if ([string]::IsNullOrEmpty($Godot)) { $Godot = $Args[0] }
if ([string]::IsNullOrEmpty($Project)) { $Project = $Args[1] }
if ([string]::IsNullOrEmpty($Out)) { $Out = $Args[2] }
$outDir = Split-Path $Out -Parent
if (-not (Test-Path $outDir)) { New-Item -ItemType Directory -Force -Path $outDir | Out-Null }
if (Test-Path $Out) { Remove-Item -LiteralPath $Out -Force }
$log = $Out + '.log'
$err = $Out + '.err'
$godotArgs = @('--path', $Project, '--rendering-driver', $Driver, '--resolution', '1280x720', '--', '--capture-path', $Out)
if (-not [string]::IsNullOrEmpty($ExtraArgs)) {
	$godotArgs += $ExtraArgs.Split(' ')
}
$p = Start-Process -FilePath $Godot -ArgumentList $godotArgs -RedirectStandardOutput $log -RedirectStandardError $err -PassThru -NoNewWindow
if (-not $p.WaitForExit($TimeoutSec * 1000)) {
	Stop-Process -Id $p.Id -Force
	Write-Output 'TIMEOUT'
	exit 2
}
Write-Output ('EXIT=' + $p.ExitCode)
if (Test-Path $Out) {
	$info = Get-Item -LiteralPath $Out
	Write-Output ('SHOT=' + $Out + ' bytes=' + $info.Length)
} else {
	Write-Output 'SHOT=MISSING'
}
Write-Output '--- stdout tail ---'
if (Test-Path $log) { Get-Content $log -Encoding UTF8 | Select-Object -Last 25 }
Write-Output '--- stderr tail ---'
if (Test-Path $err) { Get-Content $err -Encoding UTF8 | Select-Object -Last 25 }
