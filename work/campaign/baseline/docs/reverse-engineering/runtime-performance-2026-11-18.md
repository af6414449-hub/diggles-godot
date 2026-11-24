# Профиль multiplayer_test — 2026-11-18

**Дополнение после интеграции:** animation frames теперь shared ArrayMesh, узлов3106 →838; 4× MSAA выключен. Focused повтор180 кадров/фаза ×3 пары подтвердил GPU off2.908/2.947/3.368мс против4×5.761/6.397/6.699мс на Vega8, экономия28.125MiB. Draw calls289 остались. Основание костра визуально разделено с полом на .0075. Итог, JSON и кадры: [manual-work-2026-11-18.md](manual-work-2026-11-18.md). Ниже сохранён исходный профиль до интеграции; его сведения о структуре кадров не описывают обновлённый runtime.

## Вывод

На desktop низкий FPS телефона не воспроизведён: исходный idle-вид даёт около 88–91 FPS по среднему wall time. Основная измеренная нагрузка находится в рендере; обычный idle `_process` занимает десятки микросекунд. Самый сильный из проверенных переключателей — отключение 4× MSAA. Скрытые кадры занимают много нод и памяти, но не создают скрытых draw calls. У нижнего диска костра подтверждено геометрическое наложение на пол.

Это измерения Windows/Vega 8, не телефона. APK/ADB не запускались. Main, сцены, материалы и настройки проекта не изменялись. Изменены только этот документ и `godot/tools/runtime_performance_probe.gd`. Очередь, кисть, экипировка не исследовались и не правились.

## Методика и воспроизведение

Godot `4.7.2-stable (official)`, hash `ed1daf0bf001b61586d9930840f2f1394092c079`; Windows, AMD Radeon(TM) Vega 8 Graphics, OpenGL Compatibility. Окно/viewport 1280×720, VSync отключён, `Engine.max_fps=0` только в процессе probe. В проекте `anti_aliasing/quality/msaa_3d=2` означает **MSAA_4X**, а не 2×; это проверено через API установленного движка.

```powershell
Set-Location 'C:/Users/frant/OneDrive/Документы/ChatGPT/Diggles'
& 'C:/Users/frant/OneDrive/Рабочий стол/godot/Godot_v4.7.2-stable_win64_console.exe' --path godot --script res://tools/runtime_performance_probe.gd -- --probe-frames 360
```

Probe инстанцирует `scenes/multiplayer_test.tscn`, прогревает 120 кадров, перед каждой фазой пропускает ещё 90, собирает 360 кадров. Камера фиксируется перед отрисовкой; `_input` и unhandled input сцены отключены, чтобы параллельная работа за ПК не меняла ракурс. Вывод — `PERF_INVENTORY`, `PERF_PHASE`, итоговый `PERF_REPORT` JSON в stdout. Файлы результатов probe сам не пишет. Отключения действуют только в памяти. Последнее удаление невидимых кадров выполняется после остановки `_process`; после него сцена не возобновляется.

`wall_ms`: интервалы process_frame по монотонным часам, включая ожидания и present. `viewport_cpu_ms` / `viewport_gpu_ms`: реальные значения `RenderingServer.viewport_get_measured_render_time_*` при включённом `viewport_set_measure_render_time`. CPU rendering time не является временем исключительно GDScript и может включать ожидание GPU/драйвера; CPU и GPU нельзя складывать. Draw calls / objects / primitives берутся из `RenderingServer.get_rendering_info`, относятся ко всему кадру, включая UI, а не только к terrain.

`Performance.TIME_PROCESS` и `TIME_PHYSICS_PROCESS` также записываются, но мониторы обновляются редко; их p95 нельзя трактовать как p95 времени отдельных кадров. Для script CPU выполнен отдельный синтетический microbenchmark. Нулевые GPU-тайминги на неподдерживаемом backend/headless означают отсутствие измерения. Headless годится для проверки загрузки/CPU, а не для вывода об отрисовке.

Сохранён один полный прогон с фиксированной камерой. Предварительный прогон с меняющейся камерой исключён. Попытка повторного полного прогона встретила промежуточные ошибки компиляции параллельно редактируемого `multiplayer_test.gd` (`_work_mark`, `_work_marks`, `_assign_region_frontier`, `_update_pending_manual_dig` ещё не определены). Процесс остановлен; его данные не используются. Финальная версия probe дополнительно проверяет script/camera и завершает работу при такой ошибке. Она также добавляет 2× MSAA и дополнительные возвраты к baseline; эти дополнительные фазы **не измерены** в приведённом ниже завершённом прогоне. Версия probe на диске проходит Godot `--check-only`.

Во время GPU-запуска движок сообщил `Can't create shader cache folder ... user://`. Это ограничение окружения, не ошибка разбора probe. Прогрев исключён из таблицы; влияние повторной компиляции при смене режимов полностью исключить нельзя. ПК использовался параллельно, поэтому небольшие различия времени не считаются доказанным ускорением.

## Реальные измерения завершённого прогона

Время — миллисекунды. CPU/GPU — среднее; wall — среднее / p95. Во всех baseline ракурс и counters совпали.

| Фаза | Wall mean / p95 | Viewport CPU | Viewport GPU | Draw calls | Primitives |
|---|---:|---:|---:|---:|---:|
| baseline | 11.031 / 13.955 | 9.395 | 7.645 | 289 | 17163 |
| `_process` выключен | 10.934 / 14.514 | 9.466 | 7.614 | 289 | 17163 |
| baseline return 1 | 11.382 / 13.810 | 9.828 | 7.911 | 289 | 17163 |
| 9 omni выключены | 11.637 / 14.347 | 10.005 | 8.023 | 289 | 17163 |
| MSAA выключен | 8.984 / 12.030 | 7.494 | 5.352 | 289 | 17163 |
| terrain скрыт | 12.021 / 15.188 | 10.261 | 8.492 | 178 | 12074 |
| объекты скрыты | 11.884 / 15.781 | 10.148 | 7.141 | 133 | 6457 |
| baseline return 2 | 11.375 / 14.513 | 9.814 | 7.926 | 289 | 17163 |
| frozen, до удаления кадров | 11.610 / 14.086 | 10.221 | 8.118 | 289 | 17163 |
| frozen, скрытые кадры удалены | 10.648 / 12.567 | 9.396 | 7.541 | 289 | 17163 |

Baseline rendering objects = 713; terrain hidden = 602; objects hidden = 557. Нельзя приравнивать этот renderer counter к числу видимых MeshInstance3D. Исходная геометрия terrain: 5619 треугольников, 317 closing/back faces исключены, 5302 остаются. Frame primitives включают объекты и UI, поэтому не равны этому числу.

Отключение MSAA снизило GPU time на 2.29–2.57 мс относительно трёх baseline, wall — на 2.05–2.40 мс. Это наиболее заметный положительный результат, но не серия независимых повторов. У скрытия terrain и объектов уменьшаются counters, однако нет надёжного ускорения wall time. Возможны изменение occlusion/overdraw и внешняя нагрузка; по этой таблице нельзя объявлять terrain или объекты единственным bottleneck.

## Ноды, mesh, материалы, lights

Инвентаризация после прогрева:

- 3106 нод в поддереве сцены; глобальный monitor показывал 3107.
- 2255 MeshInstance3D, **349 видимы в дереве**, 913 уникальных mesh ресурсов, 786 уникальных активных material ресурсов по всем кадрам, включая скрытые. Видимость в дереве не гарантирует попадание во frustum.
- 3 гнома, у каждого 132 непосредственных ребёнка, включая frame-root ноды. `_build_static_objects` заранее строит locomotion, `_load_dig_action_visuals` — 7 dig clips / 55 уникальных mesh-index. Ресурсы кадров кешируются между гномами, но ноды для кадров создаются у каждого.
- Единственная scripted нода с активным process/physics callback в сцене — `/root/MultiplayerTest`. Тысячи MeshInstance3D не имеют индивидуальных GDScript `_process`.
- 9 OmniLight3D: радиусы 4,4,5,8,8,8,2,2,2; **все без теней**. Плюс один DirectionalLight3D, также без явно включённых теней. Выключение omni не уменьшило draw calls и не дало ускорения в этом ракурсе.

Удалены только скрытые frame-root поддеревья, 2268 нод. Глобальное число нод стало 839, draw calls и primitives сохранились. `MEMORY_STATIC`: 140179830 → 127483606 bytes, −12.11 MiB. Учтённая renderer memory: 71232701 → 65816381 bytes, −5.17 MiB; это не измерение физической VRAM телефона. Кеши mesh ресурсов сцены остаются, так что это не оценка полного выигрыша streaming-анимации. Wall улучшился на 0.96 мс, но устойчивость такого FPS-эффекта не доказана.

При выключении MSAA renderer memory: 71232701 → 41741501 bytes, −28.13 MiB в этом backend/viewport.

`_build_model_meshes` создаёт отдельный `StandardMaterial3D` и ArrayMesh на каждую непустую поверхность каждого кадра. Cull disabled, roughness=0.95; для alpha<128 — FX alpha blend, остальным alpha scissor 0.35. В статических моделях 110 непустых поверхностей, 35 комбинаций texture/alpha_range: есть потенциал переиспользования состояния материалов. **Сам по себе material cache не гарантирует уменьшение draw calls**: нужны также объединение совместимых surfaces/instances или MultiMesh для повторов.

Terrain уже кеширует ShaderMaterial по file/culling/native_diffuse (`native_scene_profile.gd:98`, `terrain_material`). В `_build_geometry` ключ mesh-bucket дополнительно включает ground_variant и part (`multiplayer_test.gd:1072`); создано 168 mesh-buckets. Нельзя бездумно сливать их: dirty rebuild использует variant, а part — диагностический фильтр. Default `native_terrain_pipeline.gdshader` — **unshaded**, diffuse/secondary рассчитаны при сборке vertices; отключение runtime omni не убирает эти цвета. Сборка lighting/terrain и trimesh collision не выполняется каждый idle-кадр.

## Recurrent callbacks и CPU

Синтетический тест: 20 пакетов по 100 вызовов, `delta=1/60`; результаты в микросекундах на вызов. Idle clock искусственно продвигается, поэтому это стоимость выполнения, не длительность игрового кадра.

| Метод | Mean µs | p95 пакетов µs |
|---|---:|---:|
| `_process` | 15.89 | 19.63 |
| `_update_dwarf_locomotion` | 1.52 | 1.63 |
| `_update_dwarf_dig_jobs` без jobs | 0.90 | 0.95 |
| `_update_dwarf_idle_animations` | 10.11 | 12.38 |

`_process` (`multiplayer_test.gd:1293` на измеренном снимке) вызывает эти три обновления. Idle идёт на 7 FPS и меняет visible frame только при смене frame_index, без обхода всех кадров (`_update_dwarf_idle_animations`, около строки 2450). `_show_dwarf_animation_frame` скрывает прошлый frame и показывает новый; он не создаёт новые meshes каждый кадр. `_set_outline_recursive` обходит все descendants, но вызывается при выборе, а не постоянно; overlay у видимого выбранного гнома может добавить проходы, режим selection отдельно не измерялся.

`create_timer(0.35)` около строки 1834 — одноразовый lifetime маркера клика. `_capture_views` с `await process_frame` около строки 2955 запускается только через `--capture-dir`. Автокопание требует `--demo-auto-dig`; по умолчанию выключено. Признаков бесконечного recurring timer или пересборки terrain в idle нет. Стоимость настоящего копания, поиска пути, выбора/outline и сетевого трафика этим idle-профилем не покрыта. Название multiplayer_test само по себе не доказывает сетевую нагрузку.

## Костёр: подтверждённое наложение

Источник: `godot/models/multi_start_010_models.json`, placement ordinal=18, Tcl line=111: `Feuerstelle`, position `[15.5,14.5,7.01]`, rotation zero, `produktionsstaetten.3db::feuerstelle`.

Surface 0, `Trollh_Boden_b_End_b_256.tga`: 25 points / 24 triangles, все source Y=0.5, после `_build_model_meshes` local Y=0, после placement **world Y=-14.5**. Alpha range `[0,255]`, значит сейчас alpha-scissor. В том же Y лежат terrain floor faces. Например точка logical XZ `(15.55,7.05)` одновременно лежит внутри треугольника диска №16 и terrain cell `(15,14)`, part 1:

```text
fire XZ:    (15.5,7.01), (16.1025,7.01), (15.5,8.215)
terrain:    (15,-14.5,7), (16,-14.5,7), (15,-14.5,9)
```

Это реальная конкуренция coplanar fragments по depth, достаточная причина z-fighting. В модели самого костра точных повторных треугольников не найдено; placement костра один. Мерцание с телефона визуально не проверялось, поэтому нельзя утверждать, что только этот дефект объясняет любое наблюдаемое мерцание. Влияние 24 треугольников на общий FPS не измерено и предположительно мало. Camera near=0.05 / far=250 дополнительно делает глубину менее устойчивой; изменение near не устраняет математически совпадающие плоскости.

## Три конкретных исправления для интегратора

1. **Снизить MSAA на мобильном профиле до 2× или выключить.** Место: `[rendering]` в `godot/project.godot`, `anti_aliasing/quality/msaa_3d`, либо runtime `get_viewport().msaa_3d`. Причина: стоимость multisample raster/resolve и render targets. Измерено только 4× → off: GPU −2.29…2.57 мс, учтённая renderer memory −28.13 MiB при 1280×720 на Vega 8. Выигрыш 4× → 2× и результат телефона — гипотеза, их надо измерить; компромисс — края геометрии.

2. **Оставить у гнома постоянные MeshInstance3D для поверхностей, переключать `.mesh` при смене кадра.** Места: `multiplayer_test.gd`, `_build_static_objects` (около 689), `_load_dig_action_visuals` (806), `_ensure_surface_clip`, `_show_dwarf_animation_frame` (2566). Хранить sequences как массивы mesh ресурсов, не frame-root деревья; при смене кадра обновлять только нужные поверхности, скрывать лишние. Сохранить существующие frame-index/socket контракты; это отдельная последующая правка интегратора, без вмешательства в текущую экипировку. Измеренная возможность: убрать до 2268 скрытых нод и около 12 MiB CPU-памяти у трёх гномов, без изменения draw calls. Возможный выигрыш FPS небольшой, не обещать кратного ускорения. После этого отдельно кешировать материалы `_build_model_meshes` по texture/transparency/scissor/culling/vertex-color; для снижения draw calls объединять статические поверхности с одинаковым полным состоянием или MultiMesh повторов. Это вторичная оптимизация, не доказанный главный bottleneck.

3. **Приподнять только нижний диск Feuerstelle на 0.005–0.01 world units по Y.** Место: `_build_static_objects`, где доступен model key, рядом с созданием `default_visuals`; для `produktionsstaetten.3db::feuerstelle` определить surface по `Trollh_Boden_b_End_b_256.tga` и сместить только её MeshInstance3D. Не полагаться на общий mesh_index для всех моделей: пустые source surfaces пропускаются. Альтернатива — явный depth bias для этого материала, если он проверен на backend. Причина: устранить подтверждённое совпадение плоскостей. Ожидаемый эффект — стабильный диск без z-fighting; существенный прирост FPS не ожидается. Сам placement и terrain collision сохранять.

Omni lights не входят в первые исправления: в текущем idle-ракурсе измеренного выигрыша от их удаления нет. Не удалять источники из исходного профиля ради неподтверждённого предположения о телефоне.

## Проверка артефактов

До и после добавления probe: bundled `lint_project.py` — 0 errors / 0 warnings. Godot `--headless --path godot --script res://tools/runtime_performance_probe.gd --check-only` — exit 0, без ошибок. Завершённый измерительный прогон — exit 0, без GDScript ошибок; отдельно отмечена средовая ошибка shader-cache. Полную проверку изменяемого параллельно Main не выдаём за выполненную. Ссылки на строки выше относятся к измеренному снимку; при интеграции надёжнее искать по именам функций.
