# Реестр параллельных сессий — 21.11.2026

Приложение к `docs/plan/queue-2026-11-19.md` (единственный источник правды об
очереди). Появилось, потому что в дереве одновременно работают несколько
агентов, а `queue-2026-11-19.md` общий: править его из нескольких сессий
одновременно нельзя — теряются правки. Этот файл — реестр без пересечений,
слить его в очередь — работа главного чата.

Правило зон: файл принадлежит одной сессии. Если блок требует чужого файла —
это явная зависимость в отчёте, а не правка чужого кода.

| Сессия | id | Зона (файлы) | Статус |
|---|---|---|---|
| **Main Chat** | `mvs_a4418a32369d4b81afea291081b4dd63` | карта главы кампании: `scripts/native_campaign_*.gd`, `models/native_campaign_*.json`, §0.9–0.12 очереди | идёт |
| **Уточнить про параллельный Main Chat** | `mvs_fb35b1f6ec28466f97af936caee61d76` | геометрия главы: грани в плоскостях `x = const`, правка экспортёра `tools/export_campaign_chapter.py` + переэкспорт | идёт; 21.11 получил разбор механики клетки/выемки/высоты (`docs/reverse-engineering/answer-osveshchenie-2026-11-21.md`) **и разбор рендера поверхности** (`docs/reverse-engineering/answer-osveshchenie-surface-2026-11-21.md`: меша 8×8 нет — 1 квад на клетку; шкала 0.5 клетки; порог 2.0) |
| **Реверс `Diggles.exe` (этот чат)** | `mvs_74f998f96a1b4662bec525ed481dd75a` | `docs/reverse-engineering/*`, `work/campaign/ref/*`; правка `docs/plan/queue-2026-11-19.md` §0.11 п.1, §0.15, §0.18 и §0.19 — по фактам движка | идёт; §0.15 пересмотрен (масштаб высот, «стены = перепад высот» опровергнуто), §0.18 — рендер поверхности, §0.19 — типизация глобалов и рендер-кластера (81 структура / 766 полей, 609 функций выгружено в `work/campaign/ref/ghidra-out/typed2/`) |
| **Начать смежную стороннюю задачу** | `session_f4efbd0e-6a04-4c15-9ed4-8851a2e92670` | генератор уровня `lg_start`: `tools/build_level_template_inventory.py`, `models/native_level_templates.json`, `scripts/native_level_generator.gd` + свой self-test | идёт |
| **explore: свет мультиплеера и главы** | `mvs_37854ea290d548419d734bac05f6fec6` | фоновая задача Main Chat, только чтение | идёт |
| **explore: карта из сохранения игры** | `mvs_9475a71a530745519d5830a212d1ae82` | фоновая задача Main Chat, только чтение | идёт |
| **ИИ гнома: состояния досуга и работы (M7)** | `mvs_c00f072b268c4f78ae88e661e965095a` | новые файлы: `scripts/native_dwarf_sparetime.gd`, `scripts/native_dwarf_place_registry.gd`, `scripts/native_dwarf_work_states.gd`, `scripts/dwarf_sparetime_runtime.gd`, `models/native_dwarf_sparetime.json`, свои self-тесты в `tools/`, свой отчёт | **закрыт 21.11** — 592 проверки блока, полный набор 61 тест / 0 падений; 3 аддитивные точки в `scripts/multiplayer_test.gd` |
| **Запустить параллельную задачу про гномов** (этот чат) | `mvs_bf44fa5479da429983ff3b793f581bcf` | постановка и контроль параллельных сессий, реестр | идёт |
| **Исправить генерацию пещер по скриншоту** | `mvs_785ae066116d4a819552d6b624e53aef` | новые файлы: `tools/audit_caves.py`, `docs/review/caves-audit-2026-11-21.md`, `out/mine-2026-11-21/`, `out/analysis/mine-q*.png`; только чтение остального | идёт; разбор скриншота пользователя, аудит по выгрузке, постановка задач стенам/Main Chat/декомпиляции |
| **Декомпиляция: гребень, декор, плоскость земли карты** | `mvs_de90f4fa1f1a45f693766449ff19e283` | новая папка `work/campaign/caves-decomp/**` + свой отчёт; `docs/reverse-engineering/*` не трогать | идёт; три вопроса к движку (З1 клетка-гребень, З2 привязка декора, З3 плоскость земли карты) |
| **Фон главной сцены кампании на поверхности** (этот чат) | `mvs_2ea0c7700e14457d9ee187466bec48eb` | новые файлы: `godot/scripts/native_campaign_backdrop.gd`, `godot/tools/native_campaign_backdrop_self_test.gd`, `godot/textures/backdrop/*`, `tools/build_panorama_backdrop.py`, `out/backdrop-2026-11-21/`, свой отчёт; минимальный хук в `godot/scripts/native_campaign_first_level.gd` (зона Main Chat — только сверка) | идёт; чёрная пустота над поверхностью главы закрыта панорамой оригинала (небо + дальний план из `Panorama_layer_*.tga`), линия горизонта матки стоит ровно на северном краю острова, при родном охвате камеры над островом — земля мира (трава у игрока, как ближнее кольцо панорамы оригинала); фон кадра — цвет неба оригинала; self-test 65/0, отчёт `docs/reverse-engineering/agent-result-campaign-backdrop-2026-11-21.md`; матка пересобрана по задаче соседней ветки «Генерация», доктрина о размерах слоёв исправлена по их декодированию (радиусы 211…1 клеток) |

## Горячие файлы — не пересекаться

| Файл | Кто может править |
|---|---|
| `godot/scripts/multiplayer_test.gd` | общий, горячий. Правка — только со сверкой SHA-256 непосредственно перед записью; иначе патч в `out/` |
| `docs/plan/queue-2026-11-19.md` | только главный чат |
| `tools/run_suite.ps1` | сессия, добавляющая в набор свои тесты, — по одному списку |

## Блок M7 — границы

M7 = машина состояний досуга и работы гнома (шаг B «Гном как самостоятельный
агент»): future/history/emergency hysteresis, реестр мест, выбор занятия,
`rotate_toangle`/`stop_prod`, состояния работы `state_work_*`.

Источник истины — оригинальные Tcl:
`data/Scripts/classes/zwerg/z_spare_main.tcl`, `z_spare_procs.tcl`,
`z_spare_fun.tcl`, `z_spare_talk.tcl`, `z_spare_reprod.tcl`, `z_work_common.tcl`,
`z_work_prod.tcl`, `z_work_prodfill.tcl`, `z_work_states.tcl`,
`data/Scripts/misc/sparetimetunes.tcl`, `data/Scripts/misc/genattribs.tcl`.

Отчёт блока: `docs/reverse-engineering/agent-result-dwarf-sparetime-work-2026-11-21.md`.
