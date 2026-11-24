# Runs the hamster self-test suites headlessly in the agent working tree.
$ErrorActionPreference = 'Stop'
$godot = 'C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe'
$project = 'C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot'
$outdir = Join-Path $project 'out'
New-Item -ItemType Directory -Force -Path $outdir | Out-Null
$suites = @('native_hamster_ai_self_test','native_hamster_actor_self_test','native_wild_hamster_self_test')
foreach ($s in $suites) {
  $log = Join-Path $outdir ("suite_" + $s + ".log")
  $err = $log + '.err'
  $p = Start-Process -FilePath $godot -ArgumentList @('--headless','--path',$project,'--script',("res://tools/" + $s + ".gd")) -RedirectStandardOutput $log -RedirectStandardError $err -PassThru -NoNewWindow
  $null = $p.Handle
  if (-not $p.WaitForExit(300000)) { Stop-Process -Id $p.Id -Force; Write-Output ("TIMEOUT " + $s); continue }
  $text = Get-Content $log -Raw
  $m = [regex]::Match($text, 'OK assertions=(\d+)')
  if ($m.Success) {
    Write-Output ("OK   {0,-42} {1,4} assertions  exit={2}" -f $s, [int]$m.Groups[1].Value, $p.ExitCode)
  } else {
    Write-Output ("FAIL {0,-42} exit={1}" -f $s, $p.ExitCode)
    Write-Output "--- stdout tail ---"
    if ($text) { $text -split "`n" | Select-Object -Last 25 | ForEach-Object { Write-Output $_ } }
    Write-Output "--- stderr tail ---"
    $e = Get-Content $err -Raw
    if ($e) { $e -split "`n" | Select-Object -Last 25 | ForEach-Object { Write-Output $_ } }
  }
}
