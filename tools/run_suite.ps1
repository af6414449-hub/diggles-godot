$ErrorActionPreference = 'Continue'
# ASCII-only on purpose: PowerShell 5.1 reads non-BOM .ps1 as ANSI.
$godot  = $Args[0]
$proj   = $Args[1]
$outdir = $Args[2]
$label  = $Args[3]

$tests = @(
 'campaign_level_generator_self_test','native_story_sequencer_self_test','native_level_generator_self_test',
 'native_campaign_chapter_self_test','native_campaign_cross_check',
 'native_campaign_walls_self_test','native_campaign_camera_self_test','native_campaign_ground_self_test',
 'torch_terrain_light_regression_self_test','automatic_torch_runtime_self_test',
 'native_torch_policy_self_test','native_torch_placement_self_test','native_autolight_self_test',
 'native_scene_profile_self_test','native_shader_pipeline_self_test','native_terrain_render_self_test',
 'terrain_refresh_self_test','world_model_light_self_test','native_model_material_self_test',
 'native_model_programs_self_test','native_walk_flags_self_test','native_flame_self_test',
 'native_hamster_ai_self_test','native_hamster_actor_self_test','native_wild_hamster_self_test',
 'native_raupe_ai_self_test','native_raupe_actor_self_test','native_farm_raupe_self_test','native_raupe_scene_self_test',
 'native_terrain_state_self_test','native_surface_walk_self_test','native_fix_dig_self_test',
 'native_dig_next_self_test','native_dig_groups_self_test','native_corridor_input_self_test',
 'navigation_representative_self_test','excavated_walk_self_test','native_battle_world_self_test',
 'native_dig_queue_self_test','native_dwarf_dig_self_test','native_dig_feedback_self_test',
 'native_model_programs_self_test','native_stance_integration_self_test','surface_depth_route_self_test',
 'wall_branch_continuation_self_test','native_corridor_contour_self_test','native_corridor_selection_self_test',
 'native_attachment_self_test','native_animation_aliases_self_test','native_actor_tasks_self_test',
 'dwarf_life_runtime_self_test','dwarf_task_runtime_self_test','dwarf_parallel_work_self_test','native_dwarf_sparetime_self_test','native_dwarf_work_states_self_test','native_dwarf_place_registry_self_test','dwarf_sparetime_runtime_self_test',
 'floor_sleep_self_test','gesture_self_test','manual_dig_region_self_test','movement_feedback_self_test',
 'native_autolight_self_test','native_vector_fix_self_test','native_torch_placement_self_test'
)

$seen = @{}
$results = New-Object System.Collections.Generic.List[object]
foreach ($t in $tests) {
  if ($seen.ContainsKey($t)) { continue }
  $seen[$t] = $true
  $log = Join-Path $outdir "$label-$t.log"
  & $godot --headless --path $proj --script "res://tools/$t.gd" 2>&1 | Tee-Object -FilePath $log | Out-Null
  $code = $LASTEXITCODE
  $tail = ''
  $err = ''
  if (Test-Path -LiteralPath $log) {
    $hits = Get-Content -LiteralPath $log | Where-Object { $_ -match 'SELF_TEST' } | Select-Object -Last 1
    if ($hits) { $tail = ($hits -replace '\s+', ' ').Trim() }
    $errs = Get-Content -LiteralPath $log | Where-Object { $_ -match 'SCRIPT ERROR|Parse Error' } | Select-Object -First 1
    if ($errs) { $err = ($errs -replace '\s+', ' ').Trim() }
  }
  $results.Add([pscustomobject]@{ tree=$label; test=$t; exit=$code; summary=$tail; error=$err })
  Write-Output ("[{0}] {1} exit={2} :: {3}" -f $label, $t, $code, $tail)
}
$results | Export-Csv -LiteralPath (Join-Path $outdir "suite_$label.csv") -NoTypeInformation -Encoding UTF8
Write-Output '=== FAILURES ==='
$results | Where-Object { $_.exit -ne 0 } | ForEach-Object { Write-Output ("  {0} exit={1} :: {2}" -f $_.test, $_.exit, $_.error) }
Write-Output ("=== {0}: {1} tests, {2} failing ===" -f $label, $results.Count, ($results | Where-Object { $_.exit -ne 0 }).Count)
Write-Output 'SUITE_DONE'
