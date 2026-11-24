$ErrorActionPreference = 'Continue'
# All arguments are passed in so this script stays pure ASCII (PS 5.1 reads
# non-BOM .ps1 as ANSI and mangles non-ASCII path literals).
$godot     = $Args[0]
$repro     = $Args[1]
$outdir    = $Args[2]
$liveFile  = $Args[3]
$patchedBak= $Args[4]
$reproFile = Join-Path $repro 'scripts\native_scene_profile.gd'

$tests = @(
 'torch_terrain_light_regression_self_test','automatic_torch_runtime_self_test',
 'native_torch_policy_self_test','native_torch_placement_self_test','native_autolight_self_test',
 'native_scene_profile_self_test','native_shader_pipeline_self_test','native_terrain_render_self_test',
 'terrain_refresh_self_test','world_model_light_self_test','native_model_material_self_test',
 'native_model_programs_self_test','native_walk_flags_self_test','native_flame_self_test',
 'native_hamster_ai_self_test','native_hamster_actor_self_test','native_wild_hamster_self_test',
 'native_terrain_state_self_test','native_surface_walk_self_test','native_fix_dig_self_test',
 'native_dig_next_self_test','native_dig_groups_self_test','native_corridor_input_self_test',
 'navigation_representative_self_test','excavated_walk_self_test'
)

$results = New-Object System.Collections.Generic.List[object]

function Invoke-Suite([string]$label) {
  foreach ($t in $tests) {
    $script = "res://tools/$t.gd"
    $log = Join-Path $outdir "$label-$t.log"
    & $godot --headless --path $repro --script $script 2>&1 | Tee-Object -FilePath $log | Out-Null
    $code = $LASTEXITCODE
    $tail = ''
    $err  = ''
    if (Test-Path -LiteralPath $log) {
      $hits = Get-Content -LiteralPath $log | Where-Object { $_ -match 'SELF_TEST' } | Select-Object -Last 1
      if ($hits) { $tail = ($hits -replace '\s+', ' ').Trim() }
      $errs = Get-Content -LiteralPath $log | Where-Object { $_ -match 'SCRIPT ERROR|Parse Error' } | Select-Object -First 1
      if ($errs) { $err = ($errs -replace '\s+', ' ').Trim() }
    }
    $results.Add([pscustomobject]@{ tree=$label; test=$t; exit=$code; summary=$tail; error=$err })
    Write-Output ("[{0}] {1} exit={2} :: {3}" -f $label, $t, $code, $tail)
  }
}

try {
  Write-Output '=== STAGE 1: PATCHED ==='
  Copy-Item -LiteralPath $patchedBak -Destination $reproFile -Force
  Invoke-Suite 'patched'

  Write-Output '=== STAGE 2: UNPATCHED (baseline) ==='
  Copy-Item -LiteralPath $liveFile -Destination $reproFile -Force
  Invoke-Suite 'unpatched'
}
finally {
  Copy-Item -LiteralPath $patchedBak -Destination $reproFile -Force
  Write-Output ('RESTORED patched sha=' + (Get-FileHash -LiteralPath $reproFile -Algorithm SHA256).Hash.Substring(0,16))
}

$results | Export-Csv -LiteralPath (Join-Path $outdir 'suite_summary.csv') -NoTypeInformation -Encoding UTF8
Write-Output '=== DIFFERENCES BETWEEN TREES ==='
foreach ($g in ($results | Group-Object test)) {
  $p = $g.Group | Where-Object { $_.tree -eq 'patched' }
  $u = $g.Group | Where-Object { $_.tree -eq 'unpatched' }
  if ($p.exit -ne $u.exit) {
    Write-Output ("DIFF {0}: patched exit={1} unpatched exit={2}" -f $g.Name, $p.exit, $u.exit)
  }
}
Write-Output '=== ALL RESULTS ==='
$results | ForEach-Object { Write-Output ("{0,-11} {1,-46} exit={2}" -f $_.tree, $_.test, $_.exit) }
Write-Output 'SUITE_DONE'
