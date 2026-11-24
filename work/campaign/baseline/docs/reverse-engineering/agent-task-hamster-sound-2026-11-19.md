# Задача агенту: звук хомяка — привязка клипов к WAV оригинала

## Цель

Закрыть белое пятно №6 отчёта об интеграции хомяков: звук поворота
`ham_drehen` не реализован. Плюс закрыть общий вопрос «звук по кадрам»
(`z_soundinit.tcl`) на классе `Hamster`.

Задача — восстановить исходную таблицу «анимация → номер кадра → wav» и
подключить её к узлу хомяка, с проверяемым контрактом.

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
- Уже закрытые модули хомяка (снимок): `native_hamster_actor.gd`,
  `native_hamster_clips.gd`, `native_wild_hamster.gd`, `native_hamster_ai.gd`.

## Уже установлено в оригинале (проверено 19.11)

`data/Scripts/init/soundinit.tcl`:

- 328–338 — привязки: `sound bind ham_drehen data/sound/hamster/ham_drehen.wav`,
  `ham_hoppeln_l`, `ham_laufen_l`, `ham_laufrad`, `ham_maennchen`, `ham_putzen`,
  `ham_schlaf_e`, `ham_schlaf_s`, `ham_sterben`.
- 843–854 — **таблица «анимация → кадр → звук»**:
  ```
  845  sound anim hamster.drehen_links_90  11 ham_drehen     any any 0.4 1.0 0 0
  846  sound anim hamster.drehen_rechts_90 11 ham_drehen     any any 0.4 1.0 0 0
  847  sound anim hamster.hoppeln_loop     0  ham_hoppeln_l  any any 0.4 1.0 0 0
  848  sound anim hamster.laufen_loop      0  ham_laufen_l   any any 0.4 1.0 0 0
  849  sound anim hamster.laufrad_loop     1  ham_laufrad    any any 0.4 1.0 0 0
  850  sound anim hamster.maennchen        5  ham_maennchen  any any 0.4 1.0 0 0
  851  sound anim hamster.putzen_loop      5  ham_putzen     any any 0.4 1.0 0 0
  852  sound anim hamster.schlafen_start   2  ham_schlaf_s   any any 0.4 1.0 0 0
  853  sound anim hamster.schlafen_end     2  ham_schlaf_e   any any 0.4 1.0 0 0
  854  sound anim hamster.sterben          6  ham_sterben    any any 0.4 1.0 0 0
  ```
- 61 — `sound bind Riesenlaufrad_kaputt data/sound/Specials/hamsterrad_kaputt.wav`
  (связано с боссом — пригодится блоку Riesenhamster).
- 109 — `sound bind equake4 data/sound/Hamster/ham_karre_l.wav`.
- 3 — комментарий: «schlafen, hamster.laufen_loop, raupe…».

Файлы: `data/Sound/Hamster/` — `ham_drehen.wav`, `ham_hoppeln_l.wav`,
`ham_laufen_l.wav`, `ham_karre_l.wav`, `ham_laufrad.wav`, `ham_maennchen.wav`,
`ham_putzen.wav`, `ham_schlaf_e.wav`, `ham_schlaf_s.wav`, `ham_sterben.wav`,
`hamster.wav`; рядом `data/Sound/Hamster_drehen.wav`, `Hamster_absteigen.wav`,
`Hamster_reiten.wav`, `InGame/hamster_reit_3o.wav`.

## Что сделать

1. Разобрать формат строки `sound anim`: что означают позиции
   `<алиас> <номер> <звук> any any 0.4 1.0 0 0` — номер кадра (с какого кадра
   звучит), громкость/радиус/затухание. Подтвердить по реализации `sound anim`
   в оригинале (Tcl/EXE) и по `z_soundinit.tcl` целиком.
2. Проверить, что все алиасы из строк 845–854 существуют в
   `hamster.tcl` (`set_class_anim`): `drehen_links_90`, `drehen_rechts_90`,
   `hoppeln_loop`, `laufen_loop`, `laufrad_loop`, `maennchen`, `putzen_loop`,
   `schlafen_start`, `schlafen_end`, `sterben` — и что они есть в
   `models/native_hamster_animations.json` (27 алиасов, 3 анимасета).
3. Собрать таблицу «алиас → wav → кадр» в виде данных проекта
   (по образцу `models/native_hamster_animations.json` и словаря команд
   `models/native_tasklist_commands.json`), без захардкоженного звука в коде.
4. Импортировать нужные WAV в проект (`godot/audio/…` — посмотреть, где
   лежат остальные звуки и как они подключены) и проверить, что Godot
   импортирует их без ошибок.
5. Подключить воспроизведение в узле хомяка: звук стартует на указанном кадре
   анимации, а не на её начале; для `*_loop` — зацикливание, для `sterben` —
   однократно. Отдельно проверить, что прерывание анимации (`drehen_*` → `laufen`)
   останавливает звук.
6. Self-test: для каждой строки таблицы — алиас существует, wav существует,
   номер кадра в пределах длины клипа, ожидаемый момент срабатывания
   совпадает с golden-значением.
7. Прогнать все наборы (прежние + новый), подготовить unified diff и отчёт.

## Ограничения

- Основной проект не редактировать.
- Не подключать WAV наугад: каждый звук должен иметь строку в `soundinit.tcl`
  или другое доказательство в оригинале.
- Звук на кадре — не «на начале анимации»: номер из оригинала значим.
- Headless-прогон не проверяет слышимость: проверяй триггер и контракт,
  а не «звук играет».
- Факт / инженерный адаптер / неизвестное — раздельно.
- GDScript-предупреждения считаются ошибками.
- Godot запускать через `Start-Process` + `WaitForExit`, иначе он зависает до `quit()`.

## Результат

Создай в основном проекте только один новый файл:

`docs/reverse-engineering/agent-result-hamster-sound-2026-11-19.md`

В нём должны быть:

1. Разбор формата `sound anim` со ссылками на строки оригинала.
2. Таблица «алиас → wav → кадр → что означает параметр» и полный список
   привязок `sound bind` (330–338) с указанием, какие из них не задействованы
   в анимациях и почему.
3. Unified diff, новые файлы данных и self-test из рабочего дерева агента.
4. Результаты прогонов (число проверок, exit 0) и прежних наборов без регрессий.
5. План интеграции в живой проект и отката.
6. Что осталось адаптером, а что факт.

В конце добавь строку:

`INTEGRATION_HANDOFF: docs/reverse-engineering/agent-result-hamster-sound-2026-11-19.md`
