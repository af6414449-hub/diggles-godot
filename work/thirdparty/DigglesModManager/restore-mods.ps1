# restore-mods.ps1 — откат модов через собственный Restore() менеджера.
# Restore() читает журнал restore.dm: удаляет добавленные модом файлы (тип "del")
# и возвращает оригиналы из *_copy (тип "res").
$ErrorActionPreference = 'Stop'

$Sandbox = $PSScriptRoot + '\sandbox\Diggles'

Add-Type -AssemblyName System.Windows.Forms
[void][System.Reflection.Assembly]::LoadFrom((Join-Path $Sandbox 'Newtonsoft.Json.dll'))
[void][System.Reflection.Assembly]::LoadFrom((Join-Path $Sandbox 'DigglesModManager.exe'))

[DigglesModManager.Paths]::ExePath = $Sandbox
[DigglesModManager.Paths]::ModPath = $Sandbox

$svc = New-Object DigglesModManager.Service.ModdingService
$svc.Restore()

Write-Output "Restore() выполнен."
Write-Output ("restore.dm остался: " + (Test-Path (Join-Path $Sandbox 'restore.dm')))
$leftover = Get-ChildItem (Join-Path $Sandbox 'Data') -Recurse -File -Filter '*_copy' -EA SilentlyContinue
Write-Output ("файлов _copy: " + $leftover.Count)
