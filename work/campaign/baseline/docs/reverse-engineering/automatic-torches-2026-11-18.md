# Автоматические факелы: оригинальные Tcl и EXE, 2026-11-18

**Продолжение:** gates установлены, runtime включён в основной сцене. [Результат и кадры](automatic-torches-runtime-2026-11-18.md). Ниже — исходное исследование и исторические границы на момент его записи; актуальные правила registry/cutoff см. `torch-placement-gates-2026-11-18.md`.

Подтверждено статическим чтением: автоматический факел — `Misc_Light`, кандидат вырабатывается периодически объектом с `autolight`, проходит очередь и проверку уже имеющегося освещения. Прямого правила «каждый завершённый dig создаёт факел» в разобранном пути нет. `Grenzstein` («Столб») раскрывает FOW; его самостоятельное создание факелов этим исследованием **не подтверждено**. Точное условие наблюдаемости, footprint и окончательный wall snap не подменены предположениями.

`O/` = `C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/data/`. Адреса ниже — preferred VA соседнего `Diggles.exe`, image base `0x400000`, SHA-256 `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`. Кэш дизассемблера использован только как индекс; описанные ветки перечитаны из оригинального EXE через pefile/Capstone. Оригинальная игра не запускалась. Интернет и сторонние описания механики не использовались.

## Класс, модель и свойства

Источник: `O/Scripts/classes/items/emitter.tcl:1–10`.

| Свойство | Буквальное значение |
| --- | --- |
| Класс | `def_class Misc_Light none dummy 0 {}` |
| Сценарии | `class_disablescripting` |
| Режим показа в тумане | `class_viewinfog 1` |
| Смещение света | `{0 -0.5 1.0}` |
| Range / цвет света | `6` / `{0.9 0.9 0.8}` |
| Анимация | `fackel.standard` |
| Частицы | `class_particle 2 {0 -0.1 0.2} {0 0 0} 32 1 0 0 -1` |
| Привязка к стене | `class_snaptowall 1` |
| Явный footprint в этом теле класса | Не задан |

`emitter.tcl:1` загружает `Scripts/init/animinit.tcl`; `animinit.tcl:16` выполняет `db_load licht`. Оригинальный `3db/licht.3db` перечитан существующим read-only parser: object `fackel` → animation index `[0]`; animation `standard` → mesh indices `[0,1]`. Это последовательность модели, не доказательство частоты проигрывания. `Scripts/misc/animclassinit.tcl:5–13` объявляет `ANIM_STILL=0`, `ANIM_ONCE=1`, `ANIM_LOOP=2` и members; из этого не следует самостоятельно назначать факелу loop.

Range `6` не означает «шаг установки 6». `class_viewinfog` описывает свойство класса и не доказывает наличие наблюдателя. Модельные bounds не являются collision footprint. `Misc_LightSrc_a..f` ниже в emitter — отдельные источники света с другими range, не варианты автоматически выбранного класса: EXE запрашивает строку именно `Misc_Light` (`0x72BC20`).

## Гном, столб и наблюдаемость

* `O/Scripts/classes/zwerg/zwerg.tcl:155–156`: `set_fogofwar this 14 8`, затем `set_autolight this 1`. `baby.tcl:130` и `items/mpinfoobjs.tcl:76` также включают autolight. Это явные команды оригинала; форма и окклюзия области FOW из двух аргументов здесь не выведены.
* `O/Scripts/classes/work/wachhaus.tcl:3–24`: класс `Grenzstein`, анимация `grenzstein.standard`, collision включается в `obj_init`. Русская справка `Scripts/text/doc/ru/tt_Grenzstein.tcl:9` называет его «Столб» (файл cp1251).
* `O/Scripts/misc/techtreetunes.tcl:767–777`: ветка `Grenzstein`, материал `{Stein}`, `tttfow_x=24`, `tttfow_y=24`. `genericprod.tcl:485–486` применяет эти значения командой `set_fogofwar`. При упаковке `genericprod.tcl:187` задаёт `-1 -1`, при распаковке `:197–199` восстанавливает значения. Это источник наблюдения/FOW, а не доказанный генератор факелов.
* `set_autolight` пишет бит `0x20` в `object+0x3D0` (`0x68B0C2–0x68B0D4`), getter читает тот же бит (`0x68B277`). Сам Tcl setter не создаёт факел.
* `O/Scripts/classes/zwerg/z_dignwalk.tcl:368–371`: после `new $cc` добытому предмету включают physics, выключают autolight и задают owner `-1`. Факел нельзя перепутать с этим порождением ресурса после копания.

Ни геометрическая видимость от столба, ни размер «круга наблюдения», ни принадлежность области конкретному игроку не восстановлены. Имя Tcl `GameObserver` не использовано как доказательство этой механики. Наличие RTTI `CObserver` в EXE само по себе тоже не связывает его с факелами.

## Подтверждённый путь в EXE

### 1. Периодический producer: `0x5CBF70` → `0x5CD520`

Вход object update проверяет `global[0x772400]+0x5C0 != 0` (`0x5CBF7B`). В `0x5CC12B–0x5CC1AD` вызов producer требует:

* `object+0xE8 == 1`;
* `object+0x3D0 & 0x20 != 0`;
* `global+0x590 == 0`;
* `global+0x64 == result(0x5B3680)` через singleton `0x5B28D0`;
* `t = global+0x6C > 10`, `t % 4 == 1`, `(t / 4) % 4 == (object+0xDC) % 4`.

Смысл всех global-полей и результата `0x5B3680` не переименован без отдельного разбора. В частности, это не доказанный LOS-test. `object+0xE8=1` явно назначается строковому классу `Zwerg` при прежнем значении `-1` (`0x5C80C5–0x5C8109`, строка `0x72B360="Zwerg"`); это не доказывает, что значение 1 недоступно другим путям.

Producer `0x5CD520–0x5CD721` требует world pointer `[0x77241C]` и `world+0x29 != 0`. Затем вычисляет **кандидат**, а не окончательную snapped-позицию:

```text
y = float32(object.y - float32(0.2))
y = float32(y - float32(rand15_a * 1/32768))
x = float32(object.x + float32(float32(rand15_b * 1/32768) - 0.5))
ix = FISTP(float32(8*x)); iy = FISTP(float32(8*y))
```

Порядок RNG: сначала Y, затем X. `0x6D46EA` — 15-bit генератор: state = state*`0x343FD`+`0x269EC3` по mod 2^32; результат `(state>>16)&0x7FFF`. Seed и общий порядок вызовов RNG в живой игре неизвестны. FISTP зависит от native FPU rounding mode; заменять его на floor нельзя.

Координаты проверяются по half-open границам world `+0x94/+0x98` … `+0x9C/+0xA0`. `0x4093F0` берёт depth-byte из metadata BlockDB: ref клетки `(ix>>3,iy>>3)`, stride `0x59`, индекс `((iy&7)<<3)|(ix&7)`. При центральном sample `>=15` кандидат отклоняется. У четырёх соседей `(ix±1,iy),(ix,iy±1)` берётся максимум только среди значений `<15`, затем ограничивается сверху 14. Полученное целое переводится непосредственно во float Z. Нельзя делить этот Z на 8 по аналогии с XY или подставлять константу из шаблона. Кандидат передаётся в `LightSrc` singleton `0x592D70`, очередь `+0x12000`, через `0x5912A0`.

### 2. Очередь кандидатов: `0x5912A0`

Record — 16 bytes: float X,Y,Z и integer counter. Если существует запись с `abs(dx)+abs(dy) < 10.0`, новую не добавляют; Z не участвует, позиция старой записи не обновляется. Counter старой ограничивается сверху 10, а не сбрасывается (`0x5913F2–0x591474`). Иначе append XYZ и counter=0 (`0x591375–0x5913EF`). Это дедупликация ожидающих заявок, не окончательный шаг между факелами.

### 3. Consumer и создание: `0x5D4250–0x5D4953`

На входе нужны `global+0x8A != 0` и `global+0xA098 != 0`. Далее consumer сравнивает `global+0x64` с 0 при `[0x772409]==0`, иначе с `singleton(0x5B28D0)+0x14` (`0x5D43F5–0x5D4412`). Разрешение `Misc_Light` в class manager должно вернуть ненулевой класс. Затем counters всех заявок увеличиваются на 1.

* Создание проверяется **ровно при counter==3** (`0x5D44F6`). World должен существовать и иметь `+0x29 != 0`; rounded `8*X/Y` должен находиться на 1 sample внутри границ (`0x5D45B8–0x5D45FA`).
* Дополнительно вызывается `0x590E60`, только true допускает создание (`0x5D4613–0x5D461A`).
* `0x601DF0` получает class `Misc_Light`, исходный XYZ record, нулевую rotation и дополнительные native аргументы (`0x5D4637–0x5D4694`). У созданного объекта очищают bits `0x690` поля `+0x3D0` (`0x5D46A3`), запускают недостающую default animation и устанавливают `+0x36C=-1`. При несовпадении позиции вызывают `0x5CD8E0`; затем native presentation update. Это не устанавливает окончательную wall-snapping формулу.
* При counter==6 запись удаляют со сдвигом хвоста (`0x5D48AD–0x5D492B`). Если проверка при 3 не прошла, в этом consumer нет повторной попытки при 4/5. Это число проходов consumer, а не доказанная длительность в кадрах или секундах.

`0x590E60` проверяет world XY bounds с margin 2 map units; Y должен быть **не меньше** integer `[0x7683D8]` (нижний порог, не верхний). В начале/reset world этот integer равен −10000; последующие writers ещё не перенесены. При material-low==3 вызывается дополнительный predicate `0x4753F0`; его true отклоняет размещение. Затем функция **обнуляет Z аргумента в своей копии** и собирает nearby light records через spatial index `world_object+0x849C`. Сначала выбирает записи с positive radius и `dx²+dy² < radius²` (`0x59106A–0x5910C6`); затем отклоняет при расстоянии до центра `<radius+4` (`0x591185–0x5911F2`). Records положительного радиуса регистрируются native light path (`0x591480`, `0x591A20`), а не списком гномов/столбов. Считать это проверкой «наблюдатель увидел кандидата» нельзя. Полный смысл material predicate и пространственной индексации требует дальнейшего разбора.

## Footprint, размещение и свет: граница доказанного

В `Misc_Light` нет явного footprint/коллизии. В создании очищаются конкретные native bits, но их имена здесь не угаданы. Отдельный общий object overlay `0x5A5F1B–0x5A60C3` использует eligibility `(obj+0x268 != 0 OR obj+0x264 == INT_MAX)` и `(flags&0x400001)==0x400001`; rect строится из FISTP(8*positionXY) и offsets `+0x254,+0x258,+0x25C,+0x260`. Этот код перечитан и включён в экспорт, но actual offsets/маска экземпляра факела неизвестны. Нельзя выдавать модельные bounds или квадрат 1×1 за оригинальный footprint.

`class_snaptowall 1` требует native wall snapping. Пример Z из начального Tcl-шаблона не заменяет результат для новой вырытой стены. Окончательное положение, orientation, light world transform и частицы должны проходить один существующий native scene-space adapter. В проекте уже есть `licht.3db::fackel` в `godot/models/demo_start_models.json` и native diffuse evaluator в `godot/scripts/native_terrain_illumination.gd`; это возможные точки повторного использования, не новые свидетельства политики placement. Цвет `{0.9,0.9,0.8}` в JSON — исходный class color; преобразование class bytes и renderer units следует существующему light pipeline, без прямого присвоения произвольной Godot intensity.

## Минимальный путь интеграции

1. Загрузить новый `res://models/native_torches.json`: класс, исходные light/particle properties и адресные доказательства. Использовать существующий mesh `licht.3db::fackel`. Экспорт не содержит размещённых факелов: `placements=[]` с явным статусом отсутствующего live state.
2. Хранить FOW observers отдельно от autolight-enabled объектов. Для Zwerg исходные аргументы `14,8`, для распакованного Grenzstein `24,24`. Не приравнивать их к кругу, камере, полностью видимому миру или радиусу освещения.
3. После принятого изменения terrain сначала обновить реальные BlockDB/depth samples. Producer запускать от расписания объекта выше; передавать RNG-state, world bounds и native rounding явно. Кандидат считать строго по пяти samples. Не создавать факел из dig queue или из факта существования столба.
4. Держать очередь `{native_xyz,counter}` с точной дедупликацией и стадиями 3/6. На стадии 3 нужен source-backed `0x590E60`, реальный light spatial index и реализованный wall snap. Только после этих проверок создавать объект и включать его light в существующий terrain lighting path.
5. Пока FOW/owner predicates, wall snap и фактический footprint не восстановлены, возвращать `unknown/deferred` и сохранять диагностическую причину. **Автоматическое размещение нельзя честно включить полностью по одному этому отчёту.** Уже можно без гипотез подключить класс/asset/properties и очередь для кандидатов с externally verified окончательными позициями. Следующая узкая RE-задача: `set_fogofwar` → native observer/owner bytes, `class_snaptowall` → окончательная transform/footprint и назначение перечисленных global gates.

Приёмка будущей интеграции: зафиксировать оригинальные terrain samples, RNG state и light records; сравнить candidate XYZ, dedup, решение при counter=3, removal при 6 и final snapped transform. Отдельно проверить упакованный/распакованный столб и отсутствие наблюдателя в оригинале. Скриншот похожего освещения этих правил не доказывает.

## Созданные файлы и воспроизводимость

Изменения этой задачи ограничены тремя новыми файлами:

* `docs/reverse-engineering/automatic-torches-2026-11-18.md` — этот отчёт.
* `tools/export_native_torches.py` — самостоятельный reader исходных Tcl/EXE, без импортов других project tools; зависимости pefile и Capstone. EXE pinned по SHA-256; Tcl hashes и строки, byte hashes и дизассемблирование 12 диапазонов сохраняются в JSON.
* `godot/models/native_torches.json` — воспроизводимый source-facts artifact, без выдуманных positions/visibility/footprint.

```powershell
python tools/export_native_torches.py
python tools/export_native_torches.py --check
```

`--check` повторно читает оригиналы и сравнивает весь артефакт без записи. Этот check доказывает воспроизводимость статического извлечения, а не исполнение механики оригинала. Existing main/scripts, очередь копания, кисть и каска не изменялись.


## Исполняемый контракт producer/queue — дополнение интегратора

`godot/scripts/native_autolight.gd` переводит расписание положительного native tick/ID, MSVC rand15, candidate XY/depth, pending dedup и consumer counters. RNG stream, outer gates, x87 mode и actual creation callback подаются извне. Выбор соседнего max включает центральный sample; values >=15 у соседей пропускаются; центральный >=15 отвергает заявку. Нельзя усреднять depth или делить candidate Z на8. Дедупликация строго Manhattan<10; не меняет исходную XYZ и не сбрасывает counter. Consumer: одна попытка на3, purge на6, никаких дополнительных retries. Отдельный headless test:33 checks,0 failures.

`0x4753F0–0x47559D` дополнительно прочитан: перебирает registry по `[0x76A338]+0x2868/+0x286C`, stride32; центр XY каждой записи должен оставаться внутри world, иначе запись удаляется заменой последней. Для оставшихся проверяется sqrt(f32(dx²+dy²)) < entry[+0x1C]. Семантика registry и producer списка пока не установлены; это **не доказанный FOW/LOS**. `0x40B7E0` — sqrt с float32 входом/выходом. Во второй проверке light exclusion Z кандидата уже0, световые Z в расстояние не читаются. Все новые spans добавлены в JSON (18 всего), `--check` перечитывает оригиналы.

Эти helpers **не подключены к созданию объектов в основной сцене**. Ни столбам, ни гномам не назначен произвольный радиус наблюдения; полного original FOW/observer runtime ещё нет. Wall snap и исходные bounds разобраны отдельно: `torch-placement-2026-11-18.md`.
