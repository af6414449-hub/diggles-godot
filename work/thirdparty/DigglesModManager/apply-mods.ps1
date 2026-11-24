# apply-mods.ps1 — прогон реального кода DigglesModManager (ModdingService) по песочнице.
#
# Зачем не GUI: DigglesModManager — WinForms-приложение, но вся логика установки модов
# публична (DigglesModManager.Service.ModdingService.LetsMod). Мы вызываем её напрямую,
# чтобы получить тот же результат, что даёт кнопка в GUI, но без кликов и без
# риска для эталонной установки в Steam.
#
# ВАЖНО: Paths.ExePath в оригинале = "." (текущий каталог), поэтому менеджер
# обязан запускаться с CWD = папка игры. Здесь мы выставляем его явно.

$ErrorActionPreference = 'Stop'

$Sandbox = $PSScriptRoot + '\sandbox\Diggles'
$Manager = $Sandbox

Write-Output "=== Песочница: $Sandbox ==="
if (-not (Test-Path (Join-Path $Sandbox 'Diggles.exe'))) { throw "В песочнице нет Diggles.exe" }

# 1. Загружаем сборку менеджера (собранную под .NET Framework 4.0)
Add-Type -AssemblyName System.Windows.Forms
# Add-Type не принимает .exe — грузим сборку напрямую (контекст LoadFrom сам найдёт Newtonsoft.Json рядом)
[void][System.Reflection.Assembly]::LoadFrom((Join-Path $Manager 'Newtonsoft.Json.dll'))
[void][System.Reflection.Assembly]::LoadFrom((Join-Path $Manager 'DigglesModManager.exe'))

# 2. Перенаправляем пути менеджера на песочницу
[DigglesModManager.Paths]::ExePath = $Sandbox
[DigglesModManager.Paths]::ModPath = $Sandbox
Write-Output ("Paths.ExePath = " + [DigglesModManager.Paths]::ExePath)
Write-Output ("Paths.ModPath = " + [DigglesModManager.Paths]::ModPath)
Write-Output ("Paths.DataPath = " + [DigglesModManager.Paths]::DataPath)

# 3. Готовим progress-bar (WinForms), т.к. LetsMod требует ProgressBarManipulator
$form = New-Object System.Windows.Forms.Form
$strip = New-Object System.Windows.Forms.ToolStrip
$bar = New-Object System.Windows.Forms.ToolStripProgressBar
[void]$strip.Items.Add($bar)
$form.Controls.Add($strip)
$pbm = New-Object DigglesModManager.ProgressBarManipulator($form, $bar)

# 4. Читаем список модов и применяем их — ровно как делает GUI
$modsRoot = Join-Path $Sandbox 'Mods'
$modNames = Get-ChildItem $modsRoot -Directory | Sort-Object Name | Select-Object -ExpandProperty Name

$svc = New-Object DigglesModManager.Service.ModdingService
$active = New-Object 'System.Collections.Generic.List[DigglesModManager.Mod]'
$results = @()

foreach ($name in $modNames) {
    $vars = New-Object 'System.Collections.Generic.Dictionary[string,object]'
    $mod = New-Object DigglesModManager.Mod($name, $vars)
    $active.Add($mod)

    # gameDirectory = корень папки игры (как в GUI): подкаталог Data мода
    # сопоставляется с каталогом Data игры по имени
    $code = $svc.LetsMod($mod, $mod.ModDirectoryInfo, (Get-Item $Sandbox), $active, $pbm)
    $status = switch ($code) { 0 {'OK'} 1 {'WARNING'} 2 {'ERROR'} default {"code=$code"} }
    $results += [PSCustomObject]@{ Mod = $name; Status = $status; Files = $mod.FileCount }
    Write-Output ("  {0,-26} {1,-8} (файлов в моде: {2})" -f $name, $status, $mod.FileCount)
}

Write-Output ""
Write-Output "=== Журнал восстановления (restore.dm) ==="
$restore = Join-Path $Sandbox 'restore.dm'
if (Test-Path $restore) {
    $lines = Get-Content $restore
    Write-Output ("  записей: " + $lines.Count)
    $lines | Group-Object { ($_ -split '\|\|')[0] } | ForEach-Object { "  тип {0}: {1}" -f $_.Name, $_.Count }
} else { Write-Output "  (нет)" }

Write-Output ""
Write-Output "=== Итог ==="
$results | Group-Object Status | ForEach-Object { "  {0}: {1}" -f $_.Name, $_.Count }
$results | Where-Object { $_.Status -ne 'OK' } | Format-Table -AutoSize | Out-String -Width 120
