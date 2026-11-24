# Dig extras: userpoints 6/7, 2026-11-18

Дополнение после интеграции: аварийные clips и исходные sockets теперь подключены в multiplayer; source export расширен alpha-range и готовыми slot0/4 transforms. Ниже сохранён исходный аудит до интеграции. Текущие условия, ограничения timing/опыта и новые lining-кандидаты досок: [feedback-2026-11-18.md](feedback-2026-11-18.md).

Исследована установленная Steam-версия, source-first. Здесь userpoints 6/7 — обозначения запроса; отдельные обработчики с такими именами в просмотренных Tcl не найдены.

**Подтверждено:** застревание кирки выбирается детерминированно; обычные удары и аварии экспортированы из оригинального `mann.3db`. **Не установлено:** класс автоматически появляющихся досок, их частота, пространственное правило и callback появления. Экспорт `brett` — только справочный ресурс, не идентификация досок в коридоре. Скриншоты и подбор позиций не использовались.

## Условия и частота аварии

Источник: `data/Scripts/classes/zwerg/z_dignwalk.tcl:385–420`, порог — `Scripts/misc/techtreetunes.tcl:1358`.

1. `get_gnomeposition this == 0` — ветка на земле.
2. Нет `Kristallstrahl` **или** `digpos.y > get_posy this` — обычная, не лазерная ветка. Наличие кристаллического инструмента само по себе не исключает кирку для всех направлений.
3. `accident_possible` истинно; значение по умолчанию — `1`.
4. `height = get_posy this - digpos.y` в исходных координатах Tcl. `height > 1.6` — вверх; `0.6 < height <= 1.6` — вперёд; `height <= 0.6` — вниз. Для передней позы `accident` принудительно сбрасывается в `0`.
5. `accident = max((0.2 - exp_Stein) * 5, 0)`. Выбор аварии проверяет **`accident > 0`**, а не `rand() < accident`.
6. В инвентаре нет `Presslufthammer`. Проверяется именно `inv_find`, не визуально удерживаемый инструмент.

Итого для верхней/нижней позы кирки: при `exp_Stein < 0.2` авария ставится перед каждым подходящим вызовом `dig_anim`; при `>= 0.2` — нет. Даже `exp_Stein = 0.199999` даёт аварийную очередь, а не маленькую вероятность. Это частота на вызов процедуры, не в секунду и не на excavated cell. Произвольные изменения tasklist, инструмента, позы или прерывание действия могут остановить очередь.

`animcnt = max(4.8 - exp_Stein*5, 1)` и `hf2i` не задают число повторов обычной кирки: в её ветке стоит один `play_anim dig${dir}`. Ветка пневмомолота отдельно использует `play_dig_anim_loop`; там действительно есть `acc*0.3 > rand()` (`z_procs.tcl`, процедура `play_dig_anim_loop`). Это другая проверка, её нельзя переносить на кирку.

## Очередь, callbacktime и clips

`tasklist_addfront` вызывается сначала для повторного `dig_anim {$digpos} 0`, затем для `play_anim dig${dir}accident`. Поэтому исполняется:

```text
play_anim digupaccident / digdownaccident
    completion: state_enable this
dig_anim {$digpos} 0
    повторно вычисляет позу/инвентарь, запрещает ещё одну аварию этого повтора
play_anim digup / digfront / digdown {$digpos}
    completion: state_enable this;dig_execute {$digpos};dig_continue
```

`z_procs.tcl:182–205` передаёт callback в `action this anim`. Без args авария не вызывает `dig_execute`. Она также добавляет `uqw` в `sparetime_talkevents`. Обычное действие с `digpos` вызывает изменение грунта на завершении, не по sound event. `dig_execute` имеет собственные вероятности успешного копания/ресурсного выпадения (`z_dignwalk.tcl:295–382`); их нельзя считать шансом застревания или досок.

| Tcl alias | Оригинальный clip `mann` | Кадров DB | Sound events: raw frame → sound |
|---|---|---:|---|
| `digup` | `buddeln_oben_normal` | 13 | 3 → `buddeln_o` |
| `digfront` | `buddeln_vorn` | 13 | 5 → `buddeln_o` |
| `digdown` | `buddeln_unten` | 13 | 5 → `buddeln_o` |
| `digupaccident` | `buddeln_oben_norm_unfall` | 29 | 3 → `buddeln_o`; 18 → `skipp_l` |
| `digdownaccident` | `buddeln_unten_unfall` | 31 | 9 → `buddeln_unten_unf_stein` |

Alias: `z_anims.tcl:305–315`; звуковые строки: `Scripts/init/z_soundinit.tcl:595–600`. Полные строки, номера, индексы анимаций/мешей, `extra` и геометрия сохранены в JSON. Нумерация sound frames и точный момент контакта не декодированы; `frame_index_base`, `seconds` оставлены `null`. WAV не копировались.

`callbacktime`: подтверждён триггер **завершения animation action**, числовое время в секундах — **не установлено**. Имеющийся профиль `native_animation_timing.json` сообщает частоту контроллера 10 кадров на game second; здесь не доказано, что это автоматически задаёт длительность именно `action anim` с его finish predicate. Ни 12 FPS из старого адаптера, ни `frame_count / 10` не выдаются за проверенное время callback. API возвращает `seconds: null`, а не таймер по предположению.

Экспорт содержит 99 body frames и сырые attachment indices/records каждого mesh. Меш кирки и готовое присоединение не создаются. `Spitzhacke` задан в `Scripts/classes/items/werkzeuge.tcl:14–22`, модель `spitzhacke.standard` из `werkzeuge.3db`, режим `ANIM_STILL = 0`. Существующий экспорт сокетов/инструментов можно подключить отдельно.

## Доски: граница доказательства

`animinit.tcl:9,13,14` загружает `mann`, `werkzeuge`, `halbzeuge`. `ANIM_STILL/ONCE/LOOP` равны `0/1/2` (`:4–6`).

`werkzeuge.tcl:220–233` определяет `Halbzeug_holz`: изначально `pilzstamm.standard`; `change_look brett` выбирает `brett.standard`, кадр `0`, `ANIM_STILL`, физика отключена. DB `halbzeuge.3db`, object `brett`, animation `standard` содержит **два** mesh index: `[4,5]`. Оба экспортированы, но это не основание проигрывать их циклом.

Не найдена доказанная цепочка `dig_apply → spawn этого класса → transform`. Нельзя утверждать, что именно этот полуфабрикат образует наблюдаемые доски; нельзя выбирать случайную точку в коридоре или назначать процент появления. В API и JSON:

```json
{"status":"unknown","chance":null,"callbacktime":null,"transform":null,"automatic_corridor_class":null}
```

Дополнительно прочитаны `dummy_auskleidung.tcl` и `animinit.tcl:385–431`: `SetCaveSkinClasses` регистрирует `auskleidung` по set/detail/size, отключает физику и collision, вызывает `add_cave_skin_class`. Эта регистрация сама по себе не доказывает тождество с досками и не определяет их случайную частоту. Её нельзя подменять правилом для `brett`.

В raw JSON сохранены инструкции `dig_apply` Tcl callback `0x6347A0..0x634B50` и native участка `0x596B80..0x597150` (конец исключён), с байтами и VA. Это ограниченная статическая проверка, не завершённая реконструкция генератора декораций. Следующий шаг для досок — связать конкретный spawn/render object с дальнейшими вызовами terrain/deco, а затем доказать выбор класса, RNG и transform. Без этого точный контракт досок остаётся неизвестным.

## API для интегратора

```gdscript
const Feedback = preload("res://scripts/native_dig_feedback.gd")
var raw: Dictionary = Feedback.read_data()
var probability: Dictionary = Feedback.chance(exp_stein, native_height_delta,
    on_ground, has_airhammer, laser_branch, accident_possible)
var work: Dictionary = Feedback.plan(exp_stein, native_height_delta)
var alias: String = Feedback.clip(native_height_delta, true)
var original: Dictionary = Feedback.clip_data(raw, alias)
var callback: Dictionary = Feedback.callbacktime(raw, alias)
var boards: Dictionary = Feedback.placement_rule()
```

`laser_branch` передаёт вычисленный результат нативной ветки, не просто наличие инструмента. `clip` возвращает alias; передняя авария возвращает пустую строку. Для wall/airhammer/laser `plan` возвращает `outside_pick_ground_scope`. Для normal pick/ground `plan.steps` описывает порядок; при реальной аварии после неё нужно повторно оценить состояние с `accident_possible=false`, как Tcl, а не безусловно продолжать старый snapshot. Передавать native Y; инвертированный Godot Y здесь неверен. Helper не вызывает RNG и не меняет сцены/terrain.

`clip_data.frames[].surfaces` сохраняет существующий point contract: `u16/65536`; native displacement — `16384*(point-0.5)`. Текстура находится по `texture_res_path`, исходное имя — `texture`. Масштаб/rotation/world placement остаются обязанностью интегратора. Функция меш-экспорта компилируется из существующего AST `export_demo_start_models.main.export_mesh` без правок. Качество TGA выбирается явной политикой существующего экспортера: наибольшая площадь, `m256` при равенстве. Это адаптер качества; все варианты и выбранный source/hash перечислены. Textures скопированы byte-for-byte.

## Воспроизведение и proof

```powershell
python -B tools/export_native_dig_feedback.py
python -B tools/export_native_dig_feedback.py --check
godot --headless --debug --path godot --script res://tools/native_dig_feedback_self_test.gd
python -B C:/Users/frant/.codex/skills/godot/scripts/debug/lint_project.py godot --pretty
```

`--check` заново читает оригиналы и сравнивает байты всех восьми экспортируемых файлов без записи. `-B` предотвращает запись Python bytecode в общие каталоги. При изменении исследованного `z_dignwalk.tcl` экспорт останавливается до повторного аудита. Все текстовые результаты — UTF-8 без BOM.

Источник `Diggles.exe` SHA-256: `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`.

Источник `z_dignwalk.tcl` SHA-256: `c0d6f01eade25f6659890bf79debbcfad0eef6d7acc0a8cdb700557bfff93846`.

Источник `mann.3db` SHA-256: `20a8f710f25ae5007ce228734e18976b103e142e61c7cd6d03189f59eed364bd`.

Остальные source hashes, полные прочитанные Tcl по строкам и raw DB records находятся в `native_dig_feedback.json`; исходные байты текстов проверяются hash, декодирование — обратимое cp1252.

Созданы только:

- `godot/scripts/native_dig_feedback.gd`
- `godot/tools/native_dig_feedback_self_test.gd`
- `tools/export_native_dig_feedback.py`
- `godot/models/native_dig_feedback.json`
- `godot/models/native_dig_feedback/board_candidate.json`
- `godot/assets/textures/native_dig_feedback/holz_standard_b_256.tga`
- `godot/assets/textures/native_dig_feedback/zmann_augen_normal.tga`
- `godot/assets/textures/native_dig_feedback/zmann_gesicht_normal.tga`
- `godot/assets/textures/native_dig_feedback/zmann_haare.tga`
- `godot/assets/textures/native_dig_feedback/zmann_koerper_oben.tga`
- `godot/assets/textures/native_dig_feedback/zmann_koerper_unten.tga`
- этот документ.

`main`, `export_dwarf_dig_action.py` и другие существующие файлы реализации не редактировались. Интеграция и APK не выполнялись. Проверки новых скриптов в движке проводятся в отдельном временном мини-проекте с копиями этих ресурсов, чтобы не затрагивать импорт/кеш основного проекта.
