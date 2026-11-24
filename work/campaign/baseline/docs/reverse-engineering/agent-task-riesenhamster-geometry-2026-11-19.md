# Задача агенту: Riesenhamster — геометрия, актёр и узел сцены

> **Статус: отложен, не запускать первым.** Проверено 19.11: босс принадлежит миру
> **Kristall** (`data/Scripts/gameplay/CampaignKris.tcl`) — предпоследнему миру
> оригинальной кампании (Urwald → Schwefel → Metall → Lava → Kristall → 6000).
> Спавнится в скирмиш-уровне `kris_unq_brains_007_a`
> (`data/Templates/kris_unq_brains_007_a.tcl`), а колесо `Riesenlaufrad` ищет его
> командой `obj_query this "-class Riesenhamster -limit 1"` и освобождает хомяка
> (`data/Scripts/classes/story/Kristallwelt.tcl:213,237`).
> В сюжете босс — актёр постановочной сцены: `sq_actor find Riesenhamster`,
> `set_anim riesenhamster.standanim`, `do_action anim riesenhamster.schlagen`
> (`data/Scripts/sequences/Kristall/brains_hebel_b_148.tcl:58,171,182`).
> В проекте нет ни мира Kristall, ни движка постановочных сцен
> (`native_sequence.gd`/`native_cutscene.gd`/`native_story.gd` отсутствуют,
> `sq_actor`/`do_action`/`link_obj` не поддержаны), ни общего боя.
> Поэтому сейчас блок дал бы манекен без игровой ценности.
> Запускать, когда появится глава, где босс нужен игроку, или когда будет
> принято решение делать постановочные сцены.

## Цель

Закрыть последний блок по боссу: выгрузить настоящую геометрию пакета
`riesenhamster.3db` (17 клипов, 237 кадров), сделать из неё исполняемого босса
и показать его в сцене.

Поведение босса уже закрыто в снимке MCode (`native_riesenhamster_ai.gd` —
таблица активностей, поиск врага, подводный урон, смерть с ожиданием 5 с,
ловушки, колесо `Riesenlaufrad`; `native_riesenhamster_animations.gd` —
24 алиаса, 2 анимасета; `tools/native_riesenhamster_self_test.gd` — 182 проверки).
Не хватает именно геометрии, актёра и узла сцены. В живом проекте босса нет
вообще: `riesenhamster.3db` не выгружен, `Character_Hamster_gross.tga` в проекте отсутствует.

Это исследование и подготовка интеграции. Основной проект не редактировать.

## Контекст и источники

- Основной проект, **только чтение**:
  `C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles`
- Снимок MCode (единственное место записи):
  `C:\Users\frant\.minimax\sessions\mvs_e213cb8b6788404489ad3b0b5c39827f\workspace\Diggles-mcode`
- Исходная игра, только чтение:
  `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris`
- Godot 4.7.2:
  `C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe`
- Образец выгрузки хомяка: `Diggles-mcode\scripts\export_hamster_clips.py`,
  декодер: `Diggles-mcode\scripts\inspect_3db.py`
- Образец актёра и узла: `work\godot\scripts\native_hamster_actor.gd`,
  `work\godot\scripts\native_hamster_actor_3d.gd`,
  `work\godot\scripts\native_hamster_clips.gd`,
  `work\godot\scenes\native_hamster_demo.tscn`
- Заметка по поведению босса: `Diggles-mcode\notes\2026-11-19-riesenhamster.md`
- Проба пакета (уже сделана, результат ниже):
  `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\boss\scripts\probe_riesenhamster_3db.py`

## Уже установлено пробой (19.11)

- `data/3db/riesenhamster.3db` — 1 041 572 Б,
  sha256 `4c0872b68e9bec5dbf956c049a4dc4a858f93462e636a8a69806d04a194a72d8`,
  декодируется полностью: 237 мешей, 450 точек, 2 треугольника-материала.
- 17 клипов, 237 кадров:
  `stand` (2), `sterben` (41), `standanim` (21), `schlafen_start` (7),
  `schlafen_loop` (16), `schlafen_end` (8), `schlagen` (17), `putzen` (17),
  `get_vorn_leicht` (11), `get_vorn_schwer` (21), `gehen_start` (4),
  `gehen_loop` (8), `gehen_end` (5), `hoppeln` (17), `laufrad` (8),
  `drehen_links` (17), `drehen_rechts` (17).
- Единственная текстура пакета — `Character_Hamster_gross.tga`
  (в оригинале `data\Texture\m256\`, 262 188 Б; также m128/m064/Gray).
  В живом проекте её нет: в `godot\textures\models\` лежит только
  `Character_Hamster_a_128.tga`.

## Что сделать

1. Обобщить `scripts/export_hamster_clips.py` на второй пакет: вынести
   `PACKAGE`/`OBJECT`/`CLASS`/схему в параметры, добавить режим `--check`
   для побайтовой воспроизводимости. Вывод:
   `work/godot/models/native_riesenhamster_clips.json`.
2. Импортировать `Character_Hamster_gross.tga` (m256) в `work/godot/textures/models/`
   и внести запись в `models/multi_start_010_models.json` (формат записи:
   `name`, `file`, `package`, `material`, `found`, `sha256`, `alpha_range`, `source`).
   Без записи экспортёр падает с «Unimported texture».
3. `scripts/native_riesenhamster_clips.gd` — таблица клипов и кадров.
4. `scripts/native_riesenhamster_actor.gd` — состояния `idle`/`fight`/`die`,
   очередь команд, таймер `evt_timer_init`, по образцу `native_hamster_actor.gd`.
5. `scripts/native_riesenhamster_actor_3d.gd` — узел сцены, босс в колесе
   `Riesenlaufrad`, по образцу `native_hamster_actor_3d.gd`.
6. `scenes/native_riesenhamster_demo.tscn` — босс и гном, который его атакует;
   запуск по F6 (F5 запускает главную сцену игры).
7. `tools/native_riesenhamster_actor_self_test.gd`: каждый алиас класса указывает
   на существующий клип, кадры дают меш с вершинами и корректными UV, босс
   сам играет клипы, смерть в бою даёт 5 с ожидания.
8. Прогнать все наборы (старые + новый), обновить `README.md` и TODO снимка.
9. Собрать unified diff (все файлы, кроме 5 МБ JSON вынести отдельным
   патч-файлом, как это сделано для хомяка) и отчёт.

## Ограничения

- Основной проект не редактировать.
- Тайминги клипов неизвестны в оригинале (12 fps — адаптер): помечай это как
  адаптер в JSON и в отчёте, не выдавай за факт.
- Боевая таблица босса уже есть (`init/fight.tcl:434-444`: 6 действий, одна
  атака `schlagen` сила 2.5, блока и уклона нет) — не переписывай её,
  а подключи к общему диспетчеру позже отдельной задачей.
- GDScript-предупреждения считаются ошибками: типы явно, неиспользуемые
  параметры с `_`, никаких `Variant` без типа.
- `class_name` — зарезервированное слово; `Object.get()` не переопределяется
  (в очереди метод называется `get_command`).
- Лямбды GDScript захватывают по значению — для наблюдаемых переменных нужен
  объект-контейнер.
- Позиции в командах в скобках: `walk_pos {x y z}`, формат `"4.0 0.0 6.0"`.
- `state_trigger` не выполняет состояние сразу, иначе бесконечный цикл
  `idle → task → idle`; таймер оригинала не зависит от состояния актёра.
- Отрицательный x означает «`get_place` ничего не нашёл».
- Алиасы class-scoped: у босса `riesenhamster.stand`, не `mann.standard`.
- Headless-цикл Godot не ограничен по fps: мерить поведение по `get_time()`.
- Godot запускать через `Start-Process` + `WaitForExit`, иначе он зависает до `quit()`:
  ```
  $p=Start-Process -FilePath 'C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe' `
    -ArgumentList @('--headless','--path',(Join-Path $root 'work\godot'),'--script','res://tools/<имя>.gd') `
    -RedirectStandardOutput $log -RedirectStandardError ($log+'.err') -PassThru -NoNewWindow
  if(-not $p.WaitForExit(120000)){Stop-Process -Id $p.Id -Force; 'TIMEOUT'}
  ```

## Результат

Создай в основном проекте только один новый файл:

`docs/reverse-engineering/agent-result-riesenhamster-geometry-2026-11-19.md`

В нём должны быть:

1. Таблица выгруженных файлов с размерами и sha256, отдельно — текстура.
2. Что и как сделано по шагам 1–7, с ссылками на строки оригинала
   (`data/Scripts/classes/characters/riesenhamster.tcl` и др.).
3. Unified diff и новые self-test файлы из рабочего дерева агента.
4. Результаты прогонов: новый набор + все прежние наборы (число проверок, exit 0).
5. План интеграции в живой проект и отката.
6. Что осталось адаптером, а что факт.

В конце добавь строку:

`INTEGRATION_HANDOFF: docs/reverse-engineering/agent-result-riesenhamster-geometry-2026-11-19.md`
