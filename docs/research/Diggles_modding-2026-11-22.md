# Diggles Mod Manager — установка, изучение, измерение эффекта

Дата: 22.11.2026. Дерево: `MiniMax\Diggles` (единственное место записи).

## 1. Что это

[DigglesModManager](https://github.com/DigglesMods/DigglesModManager) — официальный
инструмент сообщества DigglesMods (GPL-3.0, C#, активный с 2015 г., последний
пуш в master — 16.04.2024). Устанавливает моды в оригинальную игру. Релиз
**v1.3.1**, 30 звёзд, 5 форков, 12 открытых issue.

В релизе сразу 17 модов (устанавливаются одной копией):

| Мод | Суть |
|---|---|
| Barrow | предмет «Schubkarre» (тачка) |
| BetterStorage | 15 дополнительных полок склада |
| BugFix | фикс багов (в т.ч. переполнение возраста гнома) |
| ChangeCampaignClan | смена клана в кампании |
| ChangeGameSettings | настройки игры |
| CommandF9 | консольная команда F9 |
| DroppingResources | сбрасывание ресурсов |
| DwarfStatistics | статистика по гномам |
| ElfPatch | патч эльфов |
| MushroomSettings | настройки грибов |
| PowerPotion | зелье силы |
| ProductionStatistics | статистика производства |
| RareResources | редкие ресурсы |
| Recycling | переработка предметов (Alt-Click) |
| Rimless | безбородые гномы |
| StoneDoor | каменная дверь |
| SwitcherGeneratorDungeon | генератор подземелий |

Моды, помеченные `(*)` на сайте, меняют тех-дерево и **несовместимы** с сейвами
другого тех-дерева.

## 2. Где установлено

```
work/thirdparty/DigglesModManager/
  app/                    распакованный релиз v1.3.1 (EXE + 17 модов)
  source/                 исходники master (скачаны для изучения)
  sandbox/Diggles/        ПЕСОЧНИЦА: копия игры + менеджер, моды применены
  apply-mods.ps1          прогон реального кода менеджера без GUI
  restore-mods.ps1        откат через собственный Restore() менеджера
  diff-mods.py            сравнение песочницы с эталоном Steam
  mods-diff.md / .json    результат измерения
```

**Эталонная установка Steam не тронута.** Менеджер пишет прямо в `Data/`
игры, а проект использует её как первичный источник фактов, поэтому вся работа
ведётся в песочнице (140 МБ: `Diggles.exe` + `Data/` без Sound/Music/3db).

## 3. Как работает менеджер (факты из исходников)

### 3.1 Размещение

`Paths.ExePath = "."` — **текущий каталог**, а не каталог exe. Менеджер при
старте ищет рядом `Diggles.exe` или `Wiggles.exe`; не найдя, показывает ошибку
и не читает моды. Отсюда правило запуска:

```
cd <папка игры> && DigglesModManager.exe
```

### 3.2 Установка мода

Структура мода: `Mods/<Имя>/{config.json, README.md, LICENSE, Data/, Data_HD/}`.

Содержимое `Data/` **сливается** в `Data/` игры рекурсивно (по совпадению имён
каталогов). Два режима работы с файлом:

- **replace** (обычное имя) — файл мода копируется поверх файла игры, оригинал
  сохраняется как `<имя>_copy`;
- **change** (имя начинается с `change_`) — патч существующего файла игры
  собственным DSL менеджера (строковые операции по исходнику).

### 3.3 DSL патча (`change_*.tcl`)

```
$start
$before
<Grosse_Holzkiepe" {
$put
<Schubkarren" { ... }
$end
```

Поддерживаются: `$before`+`$put` (вставить перед), `$after`+`$put` (после),
`$replace`+`$with` (замена строки), `$if:<VAR>` / `$if:mod:<ИмяМода>` / `$if:!`
(условные блоки, `$ifend`), `$print:<VAR>` (подстановка значения настройки).
Условие `$if:mod:` используется, чтобы мод применялся только при наличии
другого мода (так подключается HD-вариант).

### 3.4 config.json

Версия, автор, локализованные `name`/`description` (en обязателен; de, es, fr,
it, nl, pl, ru), ссылки, сообщения, настройки (`string`/`int`/`bool`/`select`
с min/max и `possibleValues`) и `directories` — правила куда сливать подкаталоги:

- `type: data` — весь каталог льётся в `Data/` игры (опционально с условием);
- `type: optional` — каталог ставится только при выполнении условия.

Условия бывают `variable` (по значению настройки) и `mod` (по наличию другого
мода). Отсюда `Data_HD/` у большинства модов: он ставится только если
установлен `DigglesHDmod`.

### 3.5 Откат

Ведётся журнал `restore.dm` в корне: строки `del||<путь>` (файл создан модом)
или `res||<путь>` (файл оригинала, у которого есть `<путь>_copy`).
`Restore()` удаляет созданное и возвращает оригиналы из `_copy`.

### 3.6 Особенность с текстурами

При установке любого файла в каталог `Data/Texture` менеджер деактивирует
`texmaps.bin` (переименовывает в `texmaps.bin_copy`) — карту текстур нужно
перестроить под новые текстуры.

## 4. Измерение эффекта

Прогон выполнен реальным кодом менеджера (`DigglesModManager.Service.ModdingService.LetsMod`),
загруженным в PowerShell — тот же путь, что и по кнопке в GUI, но без кликов.

Результат: **17/17 модов применены без ошибок и предупреждений.**
Журнал отката: 149 записей — 104 новых файла (`del`), 45 заменённых оригиналов (`res`).

Диф песочницы против эталона (10 921 файл):

| Показатель | Значение |
|---|---|
| Без изменений | 10 733 |
| Изменено существующих | 40 |
| Добавлено новых файлов | 148 (из них 45 — резервные копии `*_copy`) |
| Из них по-настоящему новых | 83 `.tcl` + 20 `.tga` |

**Моды трогают ровно 40 существующих файлов** — и это почти все «правила игры»:

```
Scripts/misc/techtreetunes.tcl        тех-дерево (что где производится)
Scripts/classes/zwerg/z_procs.tcl     процедуры поведения гномов
Scripts/classes/zwerg/z_events.tcl    события гномов
Scripts/classes/work/lager.tcl        склад
Scripts/classes/items/*.tcl           предметы (транспорт/оружие/инструменты)
Scripts/classes/story/story.tcl       сюжет
Scripts/gameplay/Campaign{Kris,Lava,Met}.tcl   кампании
Scripts/init/classinit.tcl            регистрация атрибутов
Scripts/init/eventgen.tcl             генератор событий
Scripts/ai/std_ai.tcl                ИИ
Texture/Misc/bordermask.tga           границы (Ramless)
```

Примеры реальных правок:

```diff
# classinit.tcl — фикс переполнения возраста гнома
-def_attrib GnomeAge	-40000	1000000	0
+def_attrib GnomeAge	-40000	100000000	0

# techtreetunes.tcl — новый предмет в тех-дереве
-		set tttitems_Saegewerk	{Grosse_Holzkiepe Kettensaege ...}
+		set tttitems_Saegewerk	{Schubkarren Grosse_Holzkiepe Kettensaege ...}
```

Важная деталь: `techtreetunes.tcl` содержит блоки `//# IF FULL` / `//# ELSE` /
`//# ENDIF` (движок вырезает один из вариантов в зависимости от режима запуска),
и мод патчит **оба** варианта — потому что DSL менеджера работает как обычная
строковая замена по исходнику.

## 5. Что это значит для проекта

1. **Моддинг не нужен, чтобы менять правила игры.** Правила лежат в обычных
   `.tcl` и правятся текстовым патчем — ровно те же файлы, что уже разбираются
   при реверсе. Любой мод — это готовый пример «как правило меняется», причём
   написанный не теоретиком, а игроком.
2. **Корпус модов — источник фактов по семантике правил.** `techtreetunes.tcl`,
   `z_procs.tcl`, `classinit.tcl` и `eventgen.tcl` показывают, какие параметры
   считаются «настраиваемыми» и в каких единицах (`def_attrib`, `tttitems_*`,
   `tttinfluence_*`). Это готовая спецификация для переноса в GDScript.
3. **Структура `config.json` — готовая схема мод-пака для порта.** Если делать
   поддержку модов в Godot-порте, формат мода (`Data/` + `config.json` +
   `change_`-патчи) можно взять как есть и совместимость с сообществом.
4. **Осторожно с `texmaps.bin` и `_copy`.** Менеджер оставляет в `Data/` до 45
   файлов `*_copy` и деактивированный `texmaps.bin`; при сверке с эталоном их
   надо исключать, иначе получишь ложные «изменения».
5. **Steam-риск подтверждён практически.** Всё, что мод делает с игрой, —
   это запись в `Data/`; «проверка целостности» Steam это откатит. Моды надо
   ставить в копию игры либо держать мод-паки отдельно.

## 6. Как пользоваться

```powershell
# применить все 17 модов в песочницу
cd work\thirdparty\DigglesModManager
powershell -NoProfile -STA -File .\apply-mods.ps1

# откатить всё
powershell -NoProfile -STA -File .\restore-mods.ps1

# измерить эффект относительно эталона
python .\diff-mods.py
```

GUI (нужно запускать из папки игры, `Paths.ExePath = "."`):

```powershell
cd work\thirdparty\DigglesModManager\sandbox\Diggles
.\DigglesModManager.exe
```

## 7. Технические заметки

- **Сборка релиза — .NET Framework 4.0**, не .NET 6. `TargetFrameworkAttribute`
  в EXE: `.NETFramework,Version=v4.0`; референсы `mscorlib 4.0`, `System.Windows.Forms 4.0`,
  `Newtonsoft.Json 12.0.0.0`. В `master` проект уже мигрирован на `net6.0-windows`,
  но релизный zip собран из старой ветки — поэтому в архиве нет
  `DigglesModManager.runtimeconfig.json`/`deps.json`. Запускается штатно на
  .NET Framework 4.x (в системе: CLR 4.0.30319.42000).
- **.NET 10 Desktop Runtime 10.0.15** был установлен при изучении (до выяснения
  реальной платформы сборки) и затем **удалён** — релизному бинару он не
  требуется, а нужен только для сборки из `master`. Проверено: после удаления
  менеджер запускается штатно. Отдельно в системе уже был x86-вариант
  `Microsoft Windows Desktop Runtime 6.0.26` — он установлен не нами и на
  запуск менеджера не влияет.
- `Add-Type -Path *.exe` в PowerShell не работает — сборку грузим через
  `[System.Reflection.Assembly]::LoadFrom(...)`.
- PowerShell 5.1 читает `.ps1` без BOM как ANSI: скрипты с кириллицей нужно
  сохранять в UTF-8 **с BOM**.
- В релизе `Paths.DataPath` инициализируется как `$"{ExePath}\\Data"` до того,
  как `ExePath` меняют, — при ручной установке путей это даёт `.\Data` вместо
  абсолютного пути (на результат не влияет: подкаталог `Data_HD` в песочнице
  не ставится — условие `mod:DigglesHDmod` не выполнено).
- Миграция менеджера на .NET 6 сделана **после** релиза v1.3.1 (PR #47, 15.08.2022:
  «developer pack of .NET Framework 4.0 is not available any longer»). Новых
  релизов с тех пор не выходило, поэтому v1.3.1 — последняя сборка под .NET
  Framework 4.0, а `master` (net6.0-windows) не опубликован.
- Открытые issue менеджера: #32 — «Let's Mod» падает, если игра запущена;
  #35 — в Steam/Gog-версии нет `WigTweak.exe` (старой утилиты правки
  registry-настроек), её функций в менеджере нет; #31 — запрос на открытие
  dev-консоли из мода.

## 8. Анатомия мода и нужен ли Mod Manager

### 8.1 Файловая структура

```
Mods/<ИмяМода>/
  config.json      манифест: имя, описание, автор, настройки, правила каталогов
  README.md        игнорируется установщиком
  LICENSE          игнорируется установщиком
  Data/            ПОЛНОЗНА — сливается в Data/ игры
    <новые файлы .tcl/.tga/...>        копируются поверх/рядом
    <change_имя_файла.tcl>             патч существующего файла игры
  Data_HD/         опциональный payload: ложится в Data/ только если
                   установлен мод DigglesHDmod (объявлен в config.json)
```

Минимальный мод целиком — `Rimless` (395 байт манифеста + одна текстура):

```
Rimless/config.json
Rimless/Data/Texture/Misc/bordermask.tga
```

Типичный мод — `Recycling` (13 файлов payload):

```
Recycling/config.json                                      1620
Recycling/Data/change_messages.txt                          193
Recycling/Data/GUI/icons/recycling.tga                     4139
Recycling/Data/Texture/ClassIcons/recycling.tga            4635
Recycling/Data/Scripts/classes/items/change_transport.tcl   843
Recycling/Data/Scripts/classes/items/change_waffen.tcl     2166
Recycling/Data/Scripts/classes/items/change_werkzeuge.tcl  472
Recycling/Data/Scripts/classes/work/change_laufrad.tcl      126
Recycling/Data/Scripts/classes/zwerg/change_zwerg.tcl      162
Recycling/Data/Scripts/classes/zwerg/change_z_events.tcl  1550
Recycling/Data/Scripts/classes/zwerg/change_z_procs.tcl   5966
Recycling/Data/Scripts/init/change_eventgen.tcl             520
Recycling/Data/Scripts/misc/change_genericprod.tcl          145
Recycling/Data_HD/Texture/ClassIcons/recycling.tga        66075
```

### 8.2 Ключевой механизм со стороны игры

Игра **сама** подхватывает новые class-файлы — регистрация не нужна.
`Scripts/init/classinit.tcl` сканирует каталоги через `glob`:

```tcl
cd Data/scripts/classes/work
set filelist [lsort [glob -nocomplain "*.tcl"]]
cd ../../../..
foreach classfile $filelist {
	catch "call scripts/classes/work/$classfile"
}
```

Так подхватываются `characters`, `items`, `deco`, `work`, `sparetime`, `story`.
Файлы, начинающиеся с `_`, пропускаются. Файлы `zwerg/*` подключаются явно
(`call scripts/classes/zwerg/zwerg.tcl` и т.д.).

**Ловушка:** весь этот скан выполняется только если `startcache present` = false.
Кэш классов — `data/scripts/cache.bin`, опция игры `UseTclClassCache [true|false]`
со значением **false** по умолчанию. Если пользователь включил кэш, скан
пропускается и **новые class-файлы модов просто игнорируются**. Менеджер кэш
не трогает; в игре рядом лежит пустой (0 байт) `data/scripts/flush_tclclasscache.tcl`,
на который ссылается EXE.

### 8.3 Обязателен ли Mod Manager

**Нет.** Формат мода тривиален: это оверлей файлов + манифест. Игра про
`config.json` ничего не знает — его читает только менеджер.

Разделение по 17 модам:

| Тип | Моды | Что требуется |
|---|---|---|
| Чистый copy | `Rimless`, `ProductionStatistics` | скопировать файлы в `Data/` вручную |
| С `change_`-патчами | остальные 15 | менеджер **или** своя реализация его DSL |

`change_`-патч — это по сути описание правки «старое → новое», поэтому его
можно применить и руками (файл буквально содержит искомую строку и замену),
но автоматически это делает менеджер.

Что именно даёт менеджер сверх простого копирования:

1. **Интерпретатор DSL** (`$before/$put`, `$after/$put`, `$replace/$with`,
   `$if:`, `$print:`) — самый весомый кусок, ~150 строк строковой обработки.
2. **Подстановка настроек** из `config.json` (`settings`: string/int/bool/select)
   в файлы через `$print:<ID>` + UI-настройка в окне менеджера.
3. **Условная установка**: `$if:mod:<Имя>` и правила `directories`
   (например, `Data_HD` только при наличии `DigglesHDmod`).
4. **Учёт установки/отката**: резервные копии `*_copy` и журнал `restore.dm`.
5. **Отключение `texmaps.bin`** при установке текстур.
6. **UI выбора активных модов** и их настроек.

Ручной путь (менеджер не нужен):

```
1. новые файлы  → копировать в data/<путь>
2. правка правил→ открыть data/Scripts/.../*.tcl и внести изменения руками
3. новые текстуры → удалить data/Texture/texmaps.bin (иначе карта текстур
                    не перестроится под новые)
4. кэш классов   → не включать UseTclClassCache (иначе новые классы
                    не подхватятся)
```

Отдельно от менеджера существует хук движка `data/userinit.tcl` (см. §8.4
исходников EXE) — он выполняется при старте до `systeminit.tcl` и позволяет
писать код мода без файлов-оверлеев вовсе. Файла нет в поставке — это
заложенная точка расширения.

**Вывод для порта:** если поддержка модов нужна в Godot-порте, её объём
определяется форматом мода: (а) копирование оверлея — тривиально;
(б) DSL `change_` — небольшой объём строковой обработки, совместимый с
существующими 15 модами; (в) `config.json` как манифест — уже готов;
(г) поддержка `$print:`/`$if:` и UI настроек — опционально.
Отдельно нужно решить судьбу кэша классов: в оригинале он выключен по
умолчанию, в порте его, вероятно, не будет вовсе — и тогда автоподхват
новых class-файлов нужно реализовать явно.

## 9. Точки управления вводом и скоростью (результат разбора EXE)

Полезно для любых задач «поменять поведение оригинала»: значительная часть
настроек оригинала вынесена в **реестр**, а не в скрипты.

### 9.1 Реестр

Путь: `HKCU\Software\SekOst\Diggles\` (имя компании — из ресурса версии EXE:
`CompanyName = SEK-Ost`, `ProductName = SEK-Ost Diggles`).

| Подключ | Значения |
|---|---|
| `Control` | **ButtonMapping**, Panning, Zoom, Tilt, PanMouseFactor |
| `Input` | SimpleControl, MouseSpeed, BorderScroll, MouseScroll, **KeyScroll**, ZoomSpeedFactor, ViewModifier, AltModifier, PanModifier, ZoomModifier, TiltModifier |
| `Misc` | **PersistOptions**, **NoGamespeedLock**, **MaxGametimeFactor**, UseTclClassCache, ShowFMV, ThreadPriority, LoadInfoMax, … |
| `Performance` | MaxFramerate, TextureQuality, ObjectQuality, LandscapeQuality, MultiTexture, … |
| `Screen` | Width, Height, Fullscreen, Brightness, Gamma, DisplayIndex, AntiAliasing, … |
| `Sound` | VolumeMusic, VolumeSound |

Текущие значения на машине: `Misc\MaxGametimeFactor = 8`, `Misc\NoGamespeedLock = 0`,
`Misc\PersistOptions = 1`, `Misc\UseTclClassCache = 0`,
`Control\ButtonMapping = 0`, `Control\Panning = -1`, `Control\Zoom = -1`,
`Control\Tilt = -1`, `Input\SimpleControl = 1`, `Input\ViewModifier = 2`, `Input\AltModifier = 3`,
`Input\PanModifier = 1`, `Input\ZoomModifier = 4`, `Input\TiltModifier = 5`.

`ButtonMapping`, `Panning`, `Zoom`, `Tilt` — целые числа (REG_SZ, парсятся как int);
`-1` означает «не назначено». Модификаторы (1…5) — индексы в списке клавиш.

### 9.2 Нативные Tcl-команды

Полная таблица имён команд лежит в `.rdata` EXE (~500 строк). Для этих задач важны:

| Команда | Назначение |
|---|---|
| `option get <имя>` / `option set <имя> <значение>` | чтение/запись опций (те же, что в реестре) |
| `option getname <имя>` | отображаемое имя опции (`MaxGameTimeFactor [value] (4.0)=%f`) |
| `set_time_factor <float>` | множитель времени; **декомпиляция показывает запись float без ограничения** |
| `camctrlmapping desc` | описание текущей раскладки камеры (строки `Default:`, ` LMB:`, ` RMB:`) |
| `camctrlmapping <0..5>` | код клавиши слота раскладки (индекс клампится в 0..5) |
| `get_cameramoving`, `get_view`, `set_viewpos`, `viewlock`, `camera_set` | камера |
| `option`, `tclhelp` | опции и справка (`tclhelp` пишет `data/tclhelp.txt`) |

### 9.3 Что НЕ работает

- **`keybind` в этой сборке не «срабатывает».** Команда **есть** и регистрация работает
  (`keybind set F6 …` проходит без ошибки, `keybind current` показывает привязку),
  но **по нажатию клавиши скрипт не вызывается ни разу** — проверено в меню и в геймплее,
  с обычной привязкой и с флагом `down`, при `Input\SimpleControl` = 1 и 0.
  Причина в бинарнике: `Tcl_EvalObjEx` (единственный импорт `tcl83.dll`) вызывается
  **ровно в одном месте** — VA `0x006BC3E3`; отдельного «диспетчера привязок»,
  читающего таблицу `DAT_00772400 + 0x148/+0x14C`, в коде нет. Обработчик
  `CTclGlobalMethods::KeyBind` (подкоманды `keynames`/`current`) присутствует —
  это легаси от оригинала Wiggles. Практический вывод: **привязать клавишу к
  Tcl-команде средствами игры нельзя** — ни через `keybind`, ни другим путём
  (см. §9.5 про WASD).
- Потолок скорости x4 — **не в сеттере**: `set_time_factor` пишёт значение
  без клампа. Кламп живёт в UI/обработчике клавиш «+»/«-» и в опции
  `MaxGameTimeFactor`.

### 9.4 Диагностика

`work/thirdparty/DigglesModManager/probe-engine.tcl` — готовый скрипт: кладётся
как `data/userinit.tcl` в копию игры (или вставляется в игровую консоль Tcl) и
печатает в `data/tclprobe.log` текущие значения опций, раскладку камеры и её
слоты. Он ничего не меняет.

Инструменты разбора, написанные при этом исследовании (все в
`work/thirdparty/DigglesModManager/`):

- `find-tcl-handler.py <команда>` — находит обработчик нативной Tcl-команды и
  печатает его строковые литералы (синтаксис команды);
- `find-string-refs.py <строка>` — находит в `.text` ссылки на строковый
  литерал и печатает окружающий код;
- `tcl-handler.py <VA> [байт]` — дизассемблирование функции с аннотацией строк;
- `find-cam-slots.py`, `find-cam-table.py`, `find-keycodes.py` — поиск таблиц и
  кодов клавиш.

### 9.5 Рецепты

**Скорость x8** — правится без патча бинаря:

```
HKCU\Software\SekOst\Diggles\Misc\MaxGametimeFactor = 8      (через regedit)
```

или из Tcl: `option set maxgametimefactor 8`. Текущее значение немедленно задаётся
`set_time_factor 8` (либо `set_time_factor 4` для возврата к норме).
`PersistOptions = 1` — игра сама сохранит опцию при выходе.
`NoGamespeedLock` должен остаться **`0`**: при `"1"` пропадала надпись скорости
на экране даже на x2/x4.

**WASD вместо/вместе со стрелками** — **не решено, задача закрыта**. Разбор EXE показал,
что привязка камеры хранится нативно (`Control\ButtonMapping` + модификаторы в `Input`),
а Tcl-команды, позволяющей её записать, нет; `keybind` в сборке не «срабатывает» (§9.3).
Были испробованы и **откачены** три подхода (патч `GetVKScanCode` в `DigglesPort.dll`,
code-cave в `Diggles.exe`, внешний перехватчик `SendInput`) — ни один не дал эффекта
в игре. В папке игры бинарных патчей не осталось. Подробно:
`docs/reverse-engineering/agent-result-keybind-camera-2026-11-22.md`, §14–15.

### 9.6 Снятие чёрного тумана войны (Tcl)

Работает через `data/userinit.tcl` — точку расширения, которая загружается **до**
`data/systeminit.tcl`. Скрипт оборачивает четыре команды: `map create` (новая карта),
`show_loading` (момент перед стартом уровня), `reset_map` (сюжетные переходы) и
`gameload` (загрузка сохранения), плюс использует Tcl-процедуру ИИ `ai_tickhandler`
как «пульс» (движок вызывает её каждый тик — это единственный способ поймать
ситуацию «уровень загружен из сейва»). После каждой из них вызывается
`remove_black_fog 0 0 0 100000 100000` — команда переводит ячейки из состояния «чёрный
туман» (0) в «разведано, но темно» (1), то есть **чёрный туман исчезает, обычная
дымка остаётся**. Прямоугольник можно задавать с запасом: движок обрезает его по
карте сам. Подробно — `docs/reverse-engineering/agent-result-fogofwar-2026-11-22.md`.

```powershell
Copy-Item 'work\thirdparty\DigglesModManager\userinit-nofog.tcl' `
          'C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\userinit.tcl' -Force
```

Важно: в игре **два разных тумана**. Скрипт убирает чёрный (неразведанные области);
обычная дымка, лежащая на карте там, где нет гнома или постройки, остаётся как есть.

**Правило при перехвате Tcl-команд:** перехватывать можно только команды, которые
**не вычисляют игровые скрипты**. Нативная `call` вычисляет загружаемый скрипт в
области видимости вызывающей команды, поэтому обёртка `call` ломает область
видимости глобальных переменных игровых скриптов (`noidiobjclassescnt` и др.) и
убивает игру. Обёртка **процедуры** (например `ai_tickhandler`) безопасна.

### 9.7 Полная таблица Tcl-команд движка (факт, RE)

Имена всех команд движка лежат в `.rdata` подряд, в диапазоне
`0x0072D168 … 0x0072E4A0` (`strings.tsv`), а регистрируются в
`FUN_00618010` (`0x00618010 … 0x0061E131`). Это готовый справочник по API игры:

| группа | команды |
|---|---|
| карта | `map` (`create`/`getoffset`), `reset_map`, `get_map_width`, `get_map_height`, `get_mapedit`, `save_map`, `load_file`, `has_cmap` |
| туман | `remove_black_fog`, `set_fow_begin`, `set_fogofwar`, `show_fogofwar`, `get_max_fow`, `set_light_begin`, `set_ground_begin`, `set_view_begin` |
| сохранения | `gamesave`, `gameload`, `gameisloading`, `load_info`, `load_done`, `set_ingame_loading` |
| загрузка скриптов | `call`, `callnc`, `startcache`, `init_techtree` |
| объекты | `new`, `obj_query`, `obj_list`, `obj_valid`, `obj_clear`, `obj_eval`, `call_method`, `call_method_static`, `check_method`, `ref_set`, `ref_get` |
| камера/вид | `set_view`, `set_viewpos`, `get_view`, `set_fov`, `camera_set`, `get_cameramoving`, `viewlock`, `scroller` |
| время/производительность | `gametime` (`now`/`all`/`factor`/`start`), `gettime`, `gethours`, `time_schedule`, `set_time_factor`, `perfoptions`, `perfwin` |
| интерфейс | `gui_new_game`, `show_loading`, `show_maped`, `msgb`, `picture_box`, `newsticker`, `notifyflare`, `selection`, `layout` |
| уровни/генератор | `lg_start`, `lg_set_leveltype`, `lg_get_level`, `lg_tp_*`, `sm_*` (story manager), `autoloadlevel`, `set_level`, `template_set` |
| ИИ | `ai init/enable`, `ai_tickhandler` (Tcl-проц из `Scripts/ai/std_ai.tcl`), `ai_getownerid` |
| отладка | `dump_var`, `logdebug`, `logmod`, `sm_log`, `lmsg`, `xtest`, `tclhelp`, `minimalrun`, `perfwin` |

Как пользоваться: `python work/thirdparty/DigglesModManager/find-tcl-handler.py <имя>`
даёт адрес обработчика и ссылки на строки; декомпиляция лежит в
`work/campaign/ref/ghidra-out/decomp/`.

### 9.8 Единственная точка входа в Tcl и правило безопасных обёрток (факт, RE)

В движке **ровно одна точка входа в Tcl** — `FUN_006BC2C0`:

```
0x006BC3DC: push 0                    ; flags = 0  (НЕ TCL_EVAL_GLOBAL)
0x006BC3DE: push dword ptr [edi]       ; Tcl_Obj*
0x006BC3E0: push dword ptr [ebx]       ; interp
0x006BC3E2: call dword ptr [0x715530]  ; Tcl_EvalObjEx
```

То есть движок **никогда не вызывает Tcl-команду по имени** — он вычисляет
текст скрипта **в текущей рамке вызова** (`flags = 0` → локальная область
вызывающего). Собственные команды движка вызываются только из игровых `.tcl`.

**Правило для модов на `data/userinit.tcl`:** процедура-обёртка становится той
самой рамкой, поэтому оборачивать можно только команды, которые **не достигают
`FUN_006BC2C0`**. Иначе переменные вычисляемого скрипта создаются в области
обёртки, а не глобально — и игра падает.

| статус | команды |
|---|---|
| **нельзя оборачивать** | `call`, `call_method`, `call_method_static`, `update_objdetail`, `gameload`, `gamesave` |
| **можно** | `map`, `sm_create_map`, `show_loading`, `reset_map`, `obj_query`, `gettime`, `gametime`, `load_info`, `load_done`, `set_ingame_loading`, `particle_processing`, `gameisloading`, `newsticker`, `obj_list`, `playerinfo`, `get_local_player`, `send_trigger`, `autoloadlevel`, `gui_new_game`, `template_set`, `show_maped`, семейство `sm_*` |

Проверка: `python work/tmp_re/reach.py fwd <адрес-обработчика>` — транзитивный
обход графа вызовов до `FUN_006BC2C0`; `NO PATH` = можно оборачивать.

Отдельно: **GUI грузит сохранения напрямую из C++** (вызовы загрузчика
`FUN_00556570` из `0x0053F27D` и `0x005418B5`), а Tcl-команда `gameload` не
имеет ни одного вызова — это мёртвый код. После загрузки сейва **никакая
Tcl-команда не выполняется**: карта и туман восстанавливаются молча.


