# Промпт для GPT (Codex) — движок сюжета и постановки

**Куда применять:** сессия Codex в живом проекте
`C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles`.
**Почему именно эта задача:** это последний из крупных блоков до «игра проходится
от первой главы до последней», к которому не прикасался никто, он целиком живёт
в живом проекте и не пересекается с работой MCode по файлам.

---

```text
ЗАДАЧА: портировать движок сюжета (sequencer) оригинальной игры и собрать
первую играбельную сюжетную сцену в живом проекте.

Это крупный последний блок до «игра проходится от первой главы до последней».
Работа идёт параллельно с другой веткой (MCode: хомяки, поведение гномов,
генератор уровня кампании) — пересечений по файлам нет, см. «ГРАНИЦЫ».

КОНТЕКСТ
Проект — реимплементация Diggles The Myth of Fenris на Godot 4.7.2.
Ты (Codex) правишь живой проект:
  C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles
Снимок MCode — только для чтения:
  C:\Users\frant\OneDrive\Документы\MiniMax\Diggles

ЧТО ТАКОЕ «ДВИЖОК СЮЖЕТА» В ОРИГИНАЛЕ
Это не тексты и не диалоги, а интерпретатор сценариев — файл
  data\Scripts\classes\story\sequencer.tcl   (60 920 Б, 75 процедур)
Он держит состояние постановки и исполняет команды сценария: актёров,
выражения, реплики, звук, камеру, экранные эффекты.

Публичный API (75 процедур, сгруппировано):
- жизненный цикл: init_sequencer, sequencer_activate, shut_sequencer, reset,
  reset_enablelist, sequence_enable, sequence_disable, parse_next, sq_auto_idle
- актёры: add_actor, parse_actors, sq_actor, do_idle; признаки: Name, Actor,
  Gender, Expression; seq_expression, seq_gender, seq_male, seq_female
- текст и звук: parse_text, parse_file, sq_text, parse_audio_file, sq_audio,
  sq_music, parse_pen, sq_pen, init_pens
- объекты и камера: parse_objects, parse_pos, sq_object, sq_color,
  opts_formation; init_camsets, add_camset, sel_camset, sq_screenvibe;
  Getobjpos, Getobjref

ФОРМАТ СЦЕНАРИЯ (data\GameScripts\single_*.tcl, 28 файлов)
  show_loading yes
  obj_clear
  map create 300 300
  set_view 62.2 22.1 1.5 -0.3 0.0
  call templates/urw_unq_vodo_001_a.tcl
  MapTemplateSet 12 12
  call templates/zwerg_exit_left.tcl
  MapTemplateSet 60 20
  sm_def_temp_group temp_name { 12 12 urw_unq_vodo_001_a.tcl ... }
Сценарий = расстановка шаблонов + камера + команды секвенсера.
Сами истории: single_Seq_FirstContact.tcl (499 Б), single_Seq_Fairy_Quest.tcl,
single_Seq_Hermit_Quest.tcl, single_Seq_Dragon_Quest.tcl,
single_seq_Schwefelbruecke.tcl, single_Tutorial.tcl, single_Knockersdorf.tcl.
Реплики и тексты: data\Scripts\text\doc\ru\*.tcl (дневник, в оригинале
Windows-1251 — кодировку проверь и зафиксируй), плюс messages.txt, quotes.txt.

ЧТО СДЕЛАТЬ — по фазам, каждая закрывается отдельно и приносит проверяемый результат

ФАЗА 1 — разбор и чистая модель (без сцены)
1. Разобрать sequencer.tcl по функциям: какие команды принимает, в каком
   порядке разбираются, что делает parse_next, как собирается состояние сцены,
   как вызываются текст, звук, камера, как выключаются/включаются ветки
   (sequence_enable/disable, reset_enablelist).
2. Определить формат входного сценария (команда → аргументы) и вынести его в
   данные, а не в код.
3. Реализовать в живом проекте чистый модуль, например
   godot\scripts\native_story_sequencer.gd — без привязки к сцене:
   состояние = актёры (позиция, выражение, пол) + реплики (номер строки, текст) +
   события звука/камеры/экрана. Никаких Node3D, только данные и команды.
4. Self-test с golden-значениями: godot\tools\native_story_sequencer_self_test.gd.
   Возьми заранее выбранные сценарии (начни с single_Seq_FirstContact.tcl и
   single_Tutorial.tcl) и сверяй трассу состояния — что записано в отчёте.

ФАЗА 2 — подключение к сцене
5. Актёры = существующие гномы сцены; выражение и пол = таблицы анимаций проекта;
   реплика = текст с номером строки (и репликой/жестом, если есть);
   камера = set_view и camset.
6. Проверка в headless-сцене: сцена исполняется, состояние сходится с
   golden-трассой из фазы 1.

ФАЗА 3 — первая играбельная история
7. Один сценарий целиком (single_Seq_FirstContact.tcl или single_Tutorial.tcl)
   как сцена проекта: персонажи появляются, двигаются, говорят, камера едет,
   сценарий доигрывается до конца.

ГРАНИЦЫ (пересечения с MCode запрещены)
- Не трогай: scripts\native_hamster_*.gd, native_wild_hamster*.gd,
  native_hamster_clips.gd, native_hamster_ai.gd, native_hamster_actor*.gd,
  native_hamster_animations.gd, models\native_hamster_*,
  tools\native_hamster*, tools\native_wild_hamster*,
  scripts\native_dwarf_needs.gd, dwarf_life_runtime.gd, dwarf_sleep_runtime.gd,
  native_actor_tasks.gd, native_task_eval.gd, native_work_clock.gd,
  native_floor_sleep.gd, native_command_dispatcher.gd, native_command_handlers.gd,
  native_tasklist.gd.
  Их ведёт MCode.
- Не начинай генератор уровня кампании (парсер urw_*.tcl, first_level, irandom,
  наложение PMP/L2M): это задача MCode, контракт уже разобран в
  MiniMax\Diggles\docs\plan\campaign-generator-2026-11-19.md.
- Не трогай native_scene_profile.gd, шейдеры, walkmap, факелы, APK —
  там отдельная задача (свет факелов и collision).
- Тексты оригинала читать в исходной кодировке (проверь cp1251 против UTF-8),
  в проекте хранить в UTF-8; расхождение зафиксировать в отчёте.
- Факт / инженерный адаптер / неизвестное — держать раздельно.
  Не выдумывать команды секвенсера: если в Tcl такой команды нет — её нет.

ПРИЁМКА
- Отчёт: ChatGPT\Diggles\docs\reverse-engineering\
  agent-result-story-sequencer-2026-11-19.md
  В нём: таблица команд секвенсера со ссылками на строки Tcl; формат
  сценария; что сделано в каждой фазе; golden-трассы и результаты тестов;
  что осталось адаптером и что неизвестно; план следующего шага (следующая
  история, диалоги с репликами, журнал).
- Тест: godot\tools\native_story_sequencer_self_test.gd (golden-значения).
- Регрессия: существующие наборы не должны падать.
- В конце отчёта строка:
  INTEGRATION_HANDOFF: docs/reverse-engineering/agent-result-story-sequencer-2026-11-19.md

ПРОВЕРКА
Godot 4.7.2: C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe
Запускать через Start-Process + WaitForExit, иначе он зависает до quit():
  $p=Start-Process -FilePath $godot -ArgumentList @('--headless','--path',$project,'--script','res://tools/<имя>.gd') `
    -RedirectStandardOutput $log -RedirectStandardError ($log+'.err') -PassThru -NoNewWindow
  if(-not $p.WaitForExit(120000)){Stop-Process -Id $p.Id -Force; 'TIMEOUT'}
GDScript-предупреждения считаются ошибками: типы явно, неиспользуемые параметры с _.
Не перестраивай APK: по просьбе пользователя сборка отменена, замер на телефоне
остаётся за пользователем.
```

---

## Разделение зон

| Зона | Владелец | Файлы |
|---|---|---|
| Движок сюжета, сценарии, диалоги, камера постановки | **GPT (этот промпт)** | новые `native_story_*.gd`, `tools/native_story_*`, сцены |
| Хомяки, поведение гномов, очередь задач, диспетчер | **MCode** | `native_hamster_*`, `native_wild_hamster*`, `native_dwarf_needs.gd`, `dwarf_*_runtime.gd`, `native_actor_tasks.gd`, `native_task_eval.gd`, `native_work_clock.gd`, `native_command_*`, `native_tasklist.gd` |
| Генератор уровня кампании (`first_level`, `irandom`, композитор шаблонов) | **MCode** | `docs/plan/campaign-generator-2026-11-19.md` + будущие модули |
| Свет факелов, collision, walkmap, GPU-захваты | отдельная задача (промпт отложен) | `native_scene_profile.gd`, `multiplayer_test.gd`, `tools/torch_*` |

Сюжет — самый дальний от моей очереди блок: в моём списке M1–M8 его нет вовсе,
он появился только в глобальном шаге E. GPT может взять его сейчас, не толкая
меня ни в чём.
