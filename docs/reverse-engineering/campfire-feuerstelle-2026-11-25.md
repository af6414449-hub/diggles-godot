# Костёр (Feuerstelle): полная картина — оригинал, порт, пробелы

Сводный досье по костру оригинального Diggles и по тому, что из этого уже есть в порте на Godot 4.7.2.
Документ отвечает на вопросы: как устроен костёр в оригинале, что на нём производят, как
строится здание (и что такое «распаковка»), какие анимации и звуки задействованы, кто и как
назначается на костёр, и что из этого уже реализовано в порте.

Метки: **ФАКТ** — подтверждено строкой в оригинальном Tcl, измерением файла или разбором EXE;
**АДАПТЕР** — инженерное решение порта; **НЕИЗВЕСТНО** — не установлено, ничего не выдумано.
Что помечено как ИНФЕРЕНС — обоснованное предположение, а не установленный факт.

Объём второй части сбора (25.11.2026): разобраны `CProdPlanner` и очередь производства в EXE,
запись класса и биты состояния объекта, таксономия типов частиц и атласы; восстановлены
хореография рецептов костра, формула скорости, протокол станции и точный состав строек.

## Первичные источники

Оригинальная игра установлена локально, поэтому все правила взяты из первоисточника, а не из
пересказов: `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data`.

| Источник | Что подтверждает |
| --- | --- |
| `Scripts/classes/work/feuerstelle.tcl` | класс костра, рецепты, анимации, свет, частицы, места для гномов |
| `Scripts/misc/genericprod.tcl` | базовый класс производства: `packtobox`/`unpackfrombox`, этапы стройки, `BOXED_CLASSES` |
| `Scripts/misc/techtreetunes.tcl` | состав рецептов, стоимость зданий, энергетика, опыт |
| `Scripts/classes/zwerg/z_work_common.tcl` | цикл постройки/разборки здания, формула времени, анимации сборки |
| `Scripts/classes/zwerg/z_procs.tcl` | `unpack_pos_unfixed` — доставка ящика на место и распаковка |
| `Scripts/classes/zwerg/z_work_prod.tcl` | `prod_anim_loop_expinfl`, `prod_machineanim` — масштабирование анимаций опытом |
| `Scripts/classes/zwerg/z_spare_main.tcl`, `z_spare_procs.tcl` | трапеза гномов: место еды, блюда, выбор, места у костра |
| `Scripts/classes/items/werkzeuge.tcl`, `pilz.tcl` | класс ящика `Halbzeug_kiste`, классы `Pilzhut`, `Pilzstamm`, `Halbzeug_holz`, `Halbzeug_stein` |
| `Scripts/text/doc/ru/tt_*.tcl`, `messages.txt` | русские названия и тексты (CP1251) |
| `Sound/Produktion/Feuerstelle_1..8.wav` | звук костра (измерено) |

**ФАКТ.** Движковые команды оригинала живут в EXE (`Diggles.exe`, 3 813 376 байт), а не в Tcl.
Смещения строк в файле, найденные поиском ASCII:

| Строка | Смещение | Что даёт |
| --- | --- | --- |
| `def_class` | `0x32C4C4` | разбор четвёртого поля класса — оказалось **эпоха тех-дерева**, а не цена (§2.4) |
| `get_prod_slot_cnt` | `0x33075C` | механика очереди заказов |
| `get_boxed` | `0x330978` | состояние «в ящике» |
| `get_class_type` | `0x32C9A4` | тип объекта, из которого берётся `BOXED_CLASSES` |
| `set_buildupstate` / `get_buildupstate` | `0x33169C` / `0x3316B0` | состояние «в процессе стройки» |
| `-asbox` / `-asprod` | `0x32691D` | два режима размещения здания |

**ФАКТ.** Ключевые **методы движка**, восстановленные разбором EXE (адреса — в образе
`Diggles.exe`, база `0x00400000`):

| Метод / функция | Адрес | Что это |
| --- | --- | --- |
| `CTclGlobalMethods::Def_Class` | `0x0062EB80` | разбор `def_class` (ровно 7 токенов) |
| `CTclGlobalMethods::GetClassEra` | `0x00640140` | чтение эпохи класса (`classrec+0x60`) |
| `CTclGlobalMethods::GetClassType` / `GetClassCategory` | `0x0063FB30` / `0x0063F740` | тип и категория класса |
| `CTclGlobalMethods::GetClassFlags` | `0x0063FE40` | битовая маска «размножается/движется/живёт» |
| `CTclObjMethods::SetLock` (boxed) | `0x0067DC80` | бит `0x40000` — «в ящике» |
| `CTclObjMethods::SetBuildUpState` | `0x0067E1E0` | бит `0x400000` — «в процессе стройки» |
| `CTclObjMethods::Get/SetProdSlotCnt` | `0x00692120` / `0x00691E40` | счётчик заказа (обрезается в 0…10) |
| `SlotCountSet` | `0x005EDA20` | обрезка значения в 0…10 (`cmovns` / `cmovg`) |
| `CTclObjMethods::SetEnergyClass` / `SetEnergyConsumption` | `0x00694170` / `0x006944A0` | класс и расход энергии станции |
| `CTclObjMethods::ChangeParticleSource` | `0x00675080` | источники частиц объекта (`obj+0x2B0`, 32 слота) |
| `CTclObjMethods::SetParticleSource` | `0x0068DD60` | включение/выключение источника частиц |
| `CTclObjMethods::ProdGuest` | `0x006A8920` | таблица гостей/мест (`CProd+0x6C`, шаг `0xC`) |
| `CProdPlanner::MaintenanceTick` | `0x00433A70` | планировщик производства |
| `CProdPlanner::GnomeIdle` | `0x00434A80` | гном остаётся без работы |
| `FUN_005EDCD0` | `0x005EDCD0` | правило «нужен ли источник энергии» |

**ФАКТ.** В бинарнике сохранились имена исходников движка: `C:\dev\wiggles\Wiggles\Wiggles\AI\ProdPlanner.cpp`
(`0x007215D0`), `...\AI\ProdAllocator.cpp` (`0x00721438`), `...\Engine\Particle.cpp`
(`0x007243E0`), `...\GameUI\ViWinScapeTexture.cpp`.

**ФАКТ (важно для других сессий).** Выгрузка декомпиляции в репозитории
`work/campaign/ref/ghidra-out/decomp` — **фильтрованный подмножество** (7609 файлов, только
именованные методы). Полная выгрузка лежит отдельно: `C:\diggles-ghidra\out\decomp`
(**11 373 файла**, включая безымянные `FUN_0049xxxx` — то есть и подсистему частиц).
Именно поэтому часть выводов про частицы пришлось получать из полной выгрузки и
дизассемблирования, а не из репозиторной. Безымянные функции движка в репозитории покрыты
только выборочно (`typed2/` содержит 4 из них).

**ФАКТ.** В бинарнике сохранился путь разработчика: `C:\dev\wiggles\Wiggles\Wiggles\GameUI\ViWinScapeTexture.cpp`
— проект назывался `Wiggles\Wiggles`.

**ФАКТ.** `data/me_classinfo.txt` (11 338 строк) содержит только `category` и `lastz`
(запись `Feuerstelle` — строки 10208-10211, `category` пустая, `lastz = '0'`).
**Стоимости и размеры зданий там отсутствуют** — они в таблицах классов движка.

## 1. Что такое Feuerstelle

**ФАКТ.** `def_class Feuerstelle wood production 0` (`feuerstelle.tcl:4`).

| Параметр | Значение | Источник |
| --- | --- | --- |
| категория класса | `wood` (влияет на скорость стройки: `+0.3 × exp_Holz`) | `feuerstelle.tcl:4`, `z_work_common.tcl:544` |
| тип объекта | `production` — производственная площадка (enum 5) | `feuerstelle.tcl:4` |
| **эпоха тех-дерева** | `0` — первая эпоха (не «цена» и не «уровень еды», см. §2.4) | `feuerstelle.tcl:4`, `get_class_era` `0x00640140` |
| дистанция боя | 1.5 | `feuerstelle.tcl:9` |
| класс энергии | `0` — работает **без** энергии | `techtreetunes.tcl:34` |
| расход энергии | `0` за производство — **поэтому** источник энергии не нужен: правило движка «источник нужен только при `consumption > 0`» (`FUN_005EDCD0`) | `techtreetunes.tcl:36` |
| туман войны | раскрывает 15×15 | `techtreetunes.tcl:38-39` |
| места (guest seats) | **3 рабочих места + 5 мест ожидания** (всего 8 гостевых слотов) | `feuerstelle.tcl:297-306` |
| слот инвентаря | 1 | `feuerstelle.tcl:293` |
| анимация по умолчанию | `feuerstelle.brennt` («горит») | `feuerstelle.tcl:284`, `290` |
| смещение флага | `-1 -1` | `feuerstelle.tcl:285` |
| базовый класс | `animclassinit.tcl` + `genericprod.tcl` | `feuerstelle.tcl:6-7` |

**ФАКТ. Свет.** `change_light this {0 -0.1 0} 4 "1 0.9 0.7"` + `set_light this 1`
(`feuerstelle.tcl:279-280`): точка света на 0.1 ниже центра, радиус 4, цвет тёплый (1.0, 0.9, 0.7).
Свет включается в `init` и выключается в `packtobox` (`genericprod.tcl:174`, `188`).

**ФАКТ. Частицы.** Три источника (`feuerstelle.tcl:272-277`). Сигнатура оригинала:
`change_particlesource <объект> <слот> <ТИП> <смещение> <скорость> <lifetime> <рождений/тик> <bool> <связь> …`
— **тип частиц стоит третьим аргументом, а номер слота — вторым** (типичная ошибка — перепутать их):

| Слот | Тип | Назначение | Параметры | Управление |
| --- | --- | --- | --- | --- |
| 0 | **0** | огонь | `{0 -0.1 0} {0 0 0} 32 1 0` | включён всегда в `init` |
| 1 | **19** | пыль | `{0 0 0.5} {0.5 0.5 0.5} 32 2 0 2` | `set_dust 1/0` |
| 2 | **26** | щепки/стружка | `{0 -0.2 0.2} {0 0 0} 64 1 0 2` | `set_chips 1/0` |

Хранилище источников — `obj+0x2B0`, 32 слота на объект (`ChangeParticleSource` `0x00675080`);
`set_particlesource <объект> <слот> <режим>`: режим 0 — выключить, 1 — включить, 2 или 3 —
освободить эмиттер (`SetParticleSource` `0x0068DD60`).

**ФАКТ. Таксономия типов частиц.** В оригинале встречается **20 разных идентификаторов**:
0, 2, 3, 4, 6, 7, 8, 11, 12, 13, 17, 18, 19, 21, 25, 26, 27, 28, 33, 34 (всего 199 вызовов
`change_particlesource`). Комментарии в оригинальных скриптах прямо называют три нужных нам:

| Тип | Имя (комментарий в оригинале) | Кто использует | Параметры «по умолчанию» |
| --- | --- | --- | --- |
| **0** | `Feuer` (огонь) | костёр, домна, лаборатория, реактор, кухня, `Fake_Feuerstelle` | `{0 -0.1 0} {0 0 0} 32 1 0` — у костра, у кухни («Feuerstelle») и у декоративного огня **параметры совпадают до знака** |
| **19** | `Staub` (пыль) | пол пивоварни/кузни/токарной/лесопилки/камнерезной/костря | `{0 0 0.5} {0.5 0.5 0.5} 32 2 0` |
| **26** | `Späne` (щепки) | те же станции и костёр | `{0 -0.2 0.2} {0 0 0} 64 1 0` |

**ФАКТ.** Девятый аргумент `change_particlesource` — это **номер связи (link) в модели**, в
которой закреплён источник. Пример: у кухни факелы закреплены на связях 8 и 9, огонь — на
связи 6, и свет ставится ровно туда же: `change_light this [get_linkpos this 6] 1 "1 0.9 0.8"`
(`mittelalterkueche.tcl:297-304`). У костра огонь привязан к самому объекту (смещение
`{0 -0.1 0}`, без номера связи), а пыль и щепки — к связи **2**.

**ФАКТ. Атласы частиц в движке.** Исходник движка — `C:\dev\wiggles\Wiggles\Wiggles\Engine\Particle.cpp`
(строка в бинарнике `0x007243E0`). Менеджер частиц — синглтон `DAT_00772340` (`FUN_00492250`):
массив источников по адресу `+0x8B4` (записи **0x88 байт**, счётчик `+0x8B8`), таблица
текстур по типу — `+0x8BC`, 43 записи.

| Индекс | Слот | Атлас | Размер | Сетка |
| --- | --- | --- | --- | --- |
| 0 | `+0x8BC` | `particle_a_128d.tga` | 128×128 | 16×16 |
| 1 | `+0x8C0` | `particle_b_128d.tga` | 128×128 | 8×8 |
| 2 | `+0x8C4` | `particle_c_256d.tga` | 256×256 | — |
| **3** | **`+0x8C8`** | **`particle_e_256.tga`** | 256×256 | **4×4** |
| 4 | `+0x8CC` | `particle_d_256d.tga` | 256×256 | — |
| 5 | `+0x8D0` | `particle_a_256d.tga` | 256×256 | — |

В папке `data/Texture/Misc/` лежат **девять** файлов — ещё `particle_a_128.tga`,
`particle_c_256.tga`, `particle_d_256.tga` (без суффикса `d`) в бинарнике **не упомянуты**.

**ФАКТ. Соответствие «тип частицы → атлас»** (таблица рендера `FUN_00495F60` `0x00495F60`,
выбор текстуры — индекс в таблице выше; сетка — таблица `0x00499CB8` + jump-table
`0x00499CAC`):

| Тип | Атлас | Сетка | Шейдер / batch | Использует |
| --- | --- | --- | --- | --- |
| **0** | **`particle_e_256.tga`** | **4×4** (ячейка 64 px) | 16 / 100 | **огонь костра**, домна, реактор, лаборатория |
| 2 | `particle_a_128d.tga` | 16×16 | 16 / 180 | факелы, чаши (то, что уже перенесено в порт) |
| 19 | `particle_e_256.tga` | 4×4 | 15 / 100 | пыль |
| 26 | `particle_b_128d.tga` | 8×8 | 15 / 255 | щепки |

> **Исправление.** Прежняя редакция этого досье содержала ИНФЕРЕНС «огонь костра =
> `particle_b_128d.tga`» — по подбору атласа по цвету. Разбор таблицы рендера движка
> опровергает его: тип 0 использует **`particle_e_256.tga`** с сеткой **4×4**.
> `particle_b_128d.tga` — это щепки (тип 26), а не огонь.

**ФАКТ (измерено по содержимому TGA, для ориентира).** Разбор ячеек по цвету: `particle_b_128d` —
самый «красный» (194 из 245 ячеек с R ≫ B), `particle_a_128d` — тёплый (59), `particle_e_256` —
коричнево-белый (45 ячеек огня, 91/73/58 в среднем), `c_256`/`d_256` — серые (пыль/дым/вода),
`a_128` — почти белый. Цвет атласа **не** определяет тип — таблица движка это опровергает.

`deinit_production` гасит пыль и щепки (`feuerstelle.tcl:263-266`).

**ФАКТ. Класс `Halbzeug_kiste`** (`werkzeuge.tcl:317`) — ящик, в который упаковывается продукция
и в котором приезжает здание. Три вида: `kiste_offen` (открыт), `kiste_tragen` (в руках),
`kiste` (закрыт) — переключаются через `change_look`.

## 2. Что можно производить на костре

**ФАКТ.** `tttitems_Feuerstelle {Grillpilz Grillhamster Zelt Hauklotz Steinmetz Feuerstelle}`
(`techtreetunes.tcl:30`) — костёр производит **две еды, три постройки и сам костёр**.
`tttpreinv_Feuerstelle {Grillpilz Zelt Feuerstelle}` (`techtreetunes.tcl:32`) — изобретены с самого
начала; `Hauklotz` и `Steinmetz` требуют открытия.

### 2.1 Еда

**ФАКТ.** Рецепты из `techtreetunes.tcl` (раздел «Produkte»). Колонка «сколько» —
`tttnumber2produce_*`, то есть выход из одной единицы сырья.

| Продукт (внутрений) | Русское название | Сырьё | Выход | Прирост опыта (`tttgain_*`) | Порог изобретения (`tttinvent_*`) | Влияние (`tttinfluence_*`) | Где варится | Строка |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `Grillpilz` | Жарриб | 1 × `Pilzhut` (Шляпка) | 2 | `exp_Nahrung` 0.012 | — (изобретён сразу) | `exp_Nahrung` 0.2 | **костёр** | 508-514 |
| `Grillhamster` | Жаркое | 1 × `Hamster` | 2 | `exp_Nahrung` 0.018 | `exp_Nahrung` 0.039 | `exp_Nahrung` 0.2 | **костёр** | 515-521 |
| `Pilzbrot` | Грихль | 1 × `Pilzhut` | 4 | `exp_Nahrung` 0.008 | `exp_Nahrung` 0.25 | `exp_Nahrung` 0.25 | только `Pilzbrot__` / `Pilzbrot___` (кухни) | 522-528 |
| `Raupensuppe` | Червесу | 1 × `Raupe` | 2 | `exp_Nahrung` 0.015 | `exp_Nahrung` 0.099 | `exp_Nahrung` 0.4 | только `Raupensuppe_` / `__` / `___` (кухни) | 529-535 |
| `Raupenschleimkuchen` | Черволи | 1 × `Raupe` | 2 | `exp_Nahrung` 0.02 | `exp_Nahrung` 0.3 | `exp_Nahrung` 0.4 | только `Raupenschleimkuchen__` / `___` (кухни) | 536-542 |
| `Gourmetsuppe` | Делису | `Hamster` + `Raupe` + `Pilzhut` | 3 | `exp_Nahrung` 0.03 | `exp_Nahrung` 0.35 | `exp_Nahrung` 0.4 | только `Gourmetsuppe___` (Роскошная кухня) | 543-549 |
| `Hamstershake` | Слеза хомячка | 1 × `Hamster` | **4** | `exp_Nahrung` 0.03 | `exp_Nahrung` 0.3 + `exp_Service` 0.1 | `exp_Nahrung` 0.4 | только `Hamstershake___` (Роскошная кухня) | 550-553 |

**ФАКТ.** Базовые (без подчёркивания) варианты пяти блюд объявлены в тех-дереве, но **не входят
ни в один** список `tttitems_*` — то есть ни одна производственная станция их не производит.
Комментарий `;// an der Feuerstelle` напротив них (`techtreetunes.tcl:522,529,536,543,550`)
**устарел**: костёр производит только `Grillpilz` и `Grillhamster`
(`tttitems_Feuerstelle`, строка 30). Реально доступные варианты — с одним, двумя или тремя
подчёркиваниями, и все они у кухонь.

**ФАКТ.** `prod_item_exp_infl` возвращает именно `tttinfluence_<продукт>`
(`genericprod.tcl:128-131`) — то есть *продукта*, не станции. Для `Grillpilz` это
`{{exp_Nahrung 0.2}}`: 0.2 — не «20 % влияния», а **порог навыка**, до которого опыт гнома
линейно ускоряет работу. Станция задаёт только свой `tttinfluence_<станция>`
(для костра — `{exp_Holz 0.5} {exp_Nahrung 0.5} {exp_Stein 0.5}`), см. §2.6.

**ФАКТ.** Русские названия подтверждены `Scripts/text/doc/ru/tt_*.tcl`:
`tt_Grillpilz.tcl` → «Жарриб», `tt_Grillhamster.tcl` → «Жаркое», `tt_Pilzbrot.tcl` → «Грихль»,
`tt_Raupensuppe.tcl` → «Червесу», `tt_Raupenschleimkuchen.tcl` → «Черволи»,
`tt_Gourmetsuppe.tcl` → «Делису», `tt_Hamstershake.tcl` → «Слеза хомячка».
`messages.txt:391` → `Feuerstelle` = «Костер», `messages.txt:1006` → `Pilzhut` = «Шляпка».

**ФАКТ.** Оригинальный текст про костёр (`tt_Feuerstelle.tcl`, рус. перевод):
«В начале игры костер является экономическим, культурным, историческим и... Словом, центром всего
клана гномов и средоточием всей их жизни. У костра гномы могут готовить и с удовольствием потреблять
самую разнообразную пищу, изобретать всяческие интересные вещи, а потом строить их и все более и
более сложные сооружения.»

### 2.2 Постройки

**ФАКТ.** Стоимость здания = список `tttmaterial_<Здание>` (сырьё, которое гном приносит на костёр):

| Здание | Русское название | Сырьё | Порог изобретения | Строка |
| --- | --- | --- | --- | --- |
| `Zelt` | Палатка | 2 × `Pilzstamm` + 1 × `Pilzhut` | нет | 707-714 |
| `Feuerstelle` | Костер | 2 × `Pilzstamm` + 2 × `Stein` | нет | 21-39 |
| `Hauklotz` | Лесопилка | 4 × `Pilzstamm` + 1 × `Pilzhut` | `exp_Holz` 0.008 | 41-56 |
| `Steinmetz` | Мастерская каменщика | 4 × `Stein` + 2 × `Pilzstamm` | `exp_Stein` 0.026 | 57-67 |

**ФАКТ.** У самой станции в тех-дереве есть ещё четыре поля (`techtreetunes.tcl:21-39`):

| Поле | Значение костра | Смысл |
| --- | --- | --- |
| `tttenergyclass_Feuerstelle` | 0 | нужен источник энергии класса 0 → можно работать без энергии |
| `tttenergycons_Feuerstelle` | 0 | расход энергии за производство — 0 |
| `tttgain_Feuerstelle` | `{exp_Holz 0.01} {exp_Stein 0.01}` | опыт гнома **за саму станцию** (комментарий: «1 %» за дерево и камень) |
| `tttinfluence_Feuerstelle` | `{exp_Holz 0.5} {exp_Nahrung 0.5} {exp_Stein 0.5}` | до этих порогов опыт линейно ускоряет работу (комментарий: «bis hin zu diesen Werten beschleunigt Erfahrung linear den Herstellungsprozess») |
| `tttpreinv_Feuerstelle` | `{Grillpilz Zelt Feuerstelle}` | изобретено с начала игры |
| `tttfow_x` / `tttfow_y` | 15 / 15 | зона видимости станции |

**ФАКТ.** Для сравнения: `tttgain_Mittelalterkueche` = `{exp_Holz 0.1}`,
`tttgain_Industriekueche` = `{exp_Holz 0.15}`, `tttgain_Luxuskueche` = `{exp_Holz 0.15}`;
`tttinfluence_Mittelalterkueche` = `{exp_Holz 0.4}`, `tttinfluence_Industriekueche` и
`tttinfluence_Luxuskueche` = `{exp_Holz 0.5}` (`techtreetunes.tcl:310-338`). То есть кухни дают
в 10-15 раз больше опыта за саму станцию — костёр ценится не опытом, а тем, что он доступен с первой минуты.

**ФАКТ.** Порог изобретения — это `tttinvent_*`: список вида `{навык минимальное_значение}`.
Проектные документы приводили целочисленные пороги из вики («Na: 4», «Ho: 1», «St: 3») —
это округление UI того же самого: 0.039 → 4, 0.008 → 1, 0.026 → 3. Порог проверяется
на гноме-изобретателе, а не на станции: `prod_invent` (`z_work_common.tcl:217-227`)
считает недостающий опыт по `prod_item_attribs`.

**ФАКТ.** Флаг «изобретено» хранится у владельца: `def_attrib Bp<предмет> 0 1 0`
(`genericprod.tcl:91-94`), то есть на станции; изобретённые сразу помечаются как 1
(`genericprod.tcl:147-156`), а «уже изобретённые с начала игры» перечислены в `tttpreinv_*`.
Порядок изобретения в интерфейсе: `evt_btn_on` (`genericprod.tcl:32-52`) — клик по кнопке
производства либо прерывает текущего работника, либо ставит заказ,
`get_prod_slot_cnt`/`set_prod_slot_cnt` хранят очередь заказов на изделие.

**ФАКТ. Сюжетная зацепка.** `Scripts/classes/story/Trigger_Urwald.tcl:211,234`:
`set fire [obj_query this -class Feuerstelle -owner 1 -limit 1]`, затем
`set_prod_slot_cnt $fs Grillpilz 10` — «вудуистический костёр» заказывает десять Жаррибов.
Три постамента `Feuerstelle` на карте кампании — именно вудуистические
(шаблоны `urw_unq_vodo_001_a/_004_a/_007_a`).

**ФАКТ. Начало первого уровня.** `Scripts/sequences/Urwald/urw_3.tcl:204-210`: гном ставит
на землю ящик, вызывается `Feuerstelle` на `DropPos`, и ему сразу делают `packtobox` —
сюжет начинается именно с распаковки костра. То есть механика «ящик → распаковка → стройка»
в оригинале — не второстепенная деталь, а первый же сценарий игры.

**ФАКТ.** Комментарий в `techtreetunes.tcl:23` («нужен один грибной ствол и один камень») **устарел**:
в списке `tttmaterial_Feuerstelle` два ствола и два камня. Авторитетны значения списка, а не комментарий.

**ФАКТ.** Костёр — единственная производственная площадка, доступная в начале, поэтому первые
здания делаются именно на нём. `Hauklotz` производит `{Holzkiepe Leiter Farm Brauerei Schreinerei Holztuer}`
(techtreetunes.tcl:47-49), `Steinmetz` — `{Grenzstein Steinschleuder Grabstein Keule Plattmachfalle Schmiede Schmelze}`
(techtreetunes.tcl:63-65): это следующая ступень тех-дерева.

### 2.3 Кухни как преемники костра

**ФАКТ.** Кухни повторяют `get_eatobjects`/`sparetime this announce eat`, но требуют энергию.
Полное сравнение (строки — оригинальные Tcl-файлы):

| | **Feuerstelle** | Mittelalterkueche | Industriekueche | Luxuskueche |
| --- | --- | --- | --- | --- |
| Русское имя | Костер | Примитивная кухня | Современная кухня | Роскошная кухня |
| энергия (класс/расход) | **0 / 0** — не нужна | 1 / 10 | 2 / 20 | 3 / 20 |
| источник энергии | — | водяное колесо `Laufrad` | паровая машина `Dampfmaschine` | реактор `Reaktor` |
| блюда | `Grillpilz`, `Grillhamster` | `Grillpilz_`, `Grillhamster_`, `Raupensuppe_` | + `Pilzbrot__`, `Raupenschleimkuchen__` | + `Gourmetsuppe___`, `Hamstershake___` |
| **строит здания?** | **да**: `Zelt`, `Hauklotz`, `Steinmetz`, `Feuerstelle` | только `Feuerstelle` | нет | нет |
| посуда | открытый огонь | `Halbzeug_topf` / `pfanne` | `Halbzeug_pfanne` | `Halbzeug_topf` |
| авария при готовке | нет | дым + удар током | дым + удар током | дым + удар током |
| частицы | огонь(0), пыль(1), щепки(2) | огонь(2), факелы(0,1), дым(3), дым-авария(4), щепки(6), пыль(5) | дым(0), авария(1), 4 факела | авария(0), дым(1) |
| свет | есть `1 0.9 0.7` | есть `1 0.9 0.8` | нет | нет |
| шагов стройки | **3** (dummies 16,16,17) | 7 (16-22) | 7 (16-22) | 7 (16-22) |
| мест / ожидающих | 3 / 8 | 3 / 5 | 3 / 8 | 3 / 8 |
| «цивилизованность» места еды | **0.10** | 0.30 | 0.40 | 0.50 |
| рецепт «построй меня» | `Pilzstamm×2 + Stein×2` | `Pilzstamm×4 + Stein×3` | `Pilzstamm×2 + Stein×4 + Eisen×2` | `Stein×1 + Eisen×4 + Gold×4 + Kristall×4` |

**ФАКТ.** Одинарное подчёркивание в имени — более поздняя версия блюда (`Grillpilz_`,
`Grillhamster__`, `Gourmetsuppe___`, `Hamstershake___`); тройное подчёркивание помечено
«in der Luxuskueche» (`techtreetunes.tcl:700`).

**ФАКТ.** Число ступеней стройки у кухонь больше: `Mittelalterkueche` — 7 шагов
(`unten_linksstein unten_rechtsholz oben_rechtsholz oben_rechtsholz oben_linksholz unten_rechtsholz oben_rechtsholz`),
`Industriekueche` — 7, `Luxuskueche` — 7; у костра — **3**.

**ФАКТ.** Отличие кухонь от костра не сводится к энергии: у них появляется посуда
(`Halbzeug_topf`, `Halbzeug_pfanne`), своя хореография готовки
(`cookmiddleastart/loop/stop`, `stir`, `cookindustastart/loop/stop`), механика аварии
(дым + `prod_anim shock` + `dontknow`) и свой набор частиц.

**ФАКТ.** Русская справка подтверждает логику тех-лестницы: `tt_Mittelalterkueche.tcl` —
«Костер больше не будет местом приготовления пищи…»; `tt_Industriekueche.tcl` — «для работы
кухне требуется как минимум один паровой двигатель»; `tt_Luxuskueche.tcl` — «требуется
по крайней мере один реактор».

**ФАКТ.** Шаги стройки у первых построек: у `Hauklotz` и `Steinmetz` — **8** шагов
(dummies 12-19), `work/hauklotz.tcl:293-296`, `work/steinmetz.tcl:283-286`; у `Zelt` — 3.

### 2.4 Словарь предметов и построек костра

**ФАКТ.** Русские имена из `data/messages.txt` (CP1251): `Feuerstelle` → Костер (`:391`),
`Grillpilz` → Жарриб (`:517`), `Grillhamster` → Жаркое (`:505`), `Zelt` → Палатка (`:1669`),
`Hauklotz` → Лесопилка (`:559`), `Steinmetz` → Мастерская каменщика (`:1420`),
`Pilzhut` → Шляпка (`:1006`), `Pilzstamm` → Ножка (`:1012`), `Hamster` → Хомячок (`:541`),
`Stein` → Камень (`:1390`), `Mittelalterkueche` → Примитивная кухня (`:886`),
`Industriekueche` → Современная кухня (`:622`), `Luxuskueche` → Роскошная кухня (`:823`).

| Немецкое | Русское | Класс / категория | Свойства | Источник |
| --- | --- | --- | --- | --- |
| `Feuerstelle` | Костер | `production` / `wood` | 3 шага стройки, без энергии, свет `1 0.9 0.7`, анимация `brennt` | `work/feuerstelle.tcl:4,284,308-310` |
| `Grillpilz` | Жарриб | `material` / `food` | прирост сытости 0.19, вкус `{0.01,0.05,0,0.05}` | `items/rohstoffe.tcl:186-204`; `sparetimetunes.tcl:43,54` |
| `Grillhamster` | Жаркое | `material` / `food` | прирост сытости 0.24, вкус `{0.10,0,0.02,0}` | `items/rohstoffe.tcl:208-226`; `sparetimetunes.tcl:44,55` |
| `Pilzhut` | Шляпка | `material` / `food` | **портится**: пропадает примерно через 15 минут после броски | `items/pilz.tcl:323-360` |
| `Hamster` | Хомячок | `material` / `food`, живое существо | размножается, живёт, ходит | `characters/hamster.tcl:2` |
| `Pilzstamm` | Ножка | `material` | **вес 0.08** (хардкод в `autodef_SimpleItem`) | `items/pilz.tcl:321`; `misc/utility.tcl:57` |
| `Stein` | Камень | `material` / `stone` | 4 анимации `stein_0[1-4].standard` | `items/rohstoffe.tcl:53-70` |
| `Halbzeug_holz` | — | `dummy` / `wood` | полуфабрикат: вид `roh/half/kant/brett/rad/holzzahnrad` | `items/werkzeuge.tcl:220-233` |
| `Halbzeug_stein` | — | `dummy` / `stone` | полуфабрикат: вид `roh stein / mauer bearbeiteter_stein` | `items/werkzeuge.tcl:235-252` |
| `Halbzeug_kiste` | — | `dummy` / `none` | ящик: виды `offen`/`geschlossen`/`tragen` | `items/werkzeuge.tcl:317-330` |
| `Zelt` | Палатка | `production` / `wood` | 3 шага, место сна | `classes/sparetime/zelt.tcl:3,52-58` |

**ФАКТ. Четвёртое числовое поле `def_class` — это ЭПОХА ТЕХ-ДЕРЕВА, а не цена и не уровень
пищевой ценности.** Разбор EXE: `CTclGlobalMethods::Def_Class` (`0x0062EB80`, ровно 7 токенов)
складывает аргументы так:

| argv | Токен | Куда | Что это |
| --- | --- | --- | --- |
| `[1]` | `Feuerstelle` | `classrec+0x0C` | имя класса |
| `[2]` | `wood` | `classrec+0x58` | **категория** (enum) |
| `[3]` | `production` | `classrec+0x54` | **тип** (enum) |
| `[4]` | `0` | `classrec+0x60` | **эпоха** (`get_class_era`, `0x00640140`) |
| `[5]` | `{}` | `classrec+0x5C` | битовая маска признаков: 1 = «размножается», 2 = «движется», 4 = «живёт» (`get_class_flags`, `0x0063FE40`) |
| `[6]` | `{ … }` | тело класса | исполняется как скрипт класса |

Эпоха читается движком (`get_class_era`) и пишется в дерево (`Scripts/init/makettree.tcl:5`,
формат `//name  cat  type  Era  Flags` — `Scripts/gameplay/techtree.tcl:1`). Диапазон эпох — 0…8
на игрока (`GetMaxProdEra` `0x00629570` отклоняет значение вне 0…8).

> Прежняя версия этого досье утверждала, что поле — «уровень пищевой ценности» (по корреляции
> `Pilzhut`=0, `Grillhamster`=1, `Pilzbrot`=2). **Корреляция ложная:** эти блюда просто
> разблокированы в эпохах 0/1/2, а цены в движке не существует вовсе.

**ФАКТ. Перечислители категорий и типов** (из EXE, `FUN_00600190` и `FUN_005FFFE0`):

| Категория | Значение | | Тип | Значение |
| --- | --- | --- | --- | --- |
| `none` | 0 | | `none` | −1 |
| `food` | 1 | | `dummy` | 0 |
| `stone` | 2 | | `gnome` | 1 |
| `metal` | 3 | | `monster` | 2 |
| `energy` | 4 | | `material` | 3 |
| `service` | 5 | | `tool` | 4 |
| `fight` | 6 | | `production` | 5 |
| `wood` | 7 | | `energy` | 6 |
| | | | `elevator` | 10 |
| | | | `baby` | 11 |
| | | | `info` | 12 |

Значения типов 7, 8, 9 (среди них `store` и `protection` из `BOXED_CLASSES`) в выгрузке не
декодированы — см. §9.2.

**ФАКТ.** У класса есть ещё битовые флаги (`classrec+0x2C`): бит 0 — «виден в тумане», бит 1 —
«участвует в физике», бит 2 — «имеет коллизию».

**ФАКТ.** У класса **нет** полей веса, цены или пищевой ценности — в записи класса таких полей
нет, и в движке нет команд `weight` / `price` / `value`. Вес — это **атрибут объекта** с глобальным
значением по умолчанию 0 (`def_attrib weight 0 1 0`, `data/Scripts/misc/obj_attribs.tcl:4`),
который каждый класс переопределяет у себя в `obj_init` (`set_attrib this weight 0.08` и т.п.).
То есть таблицы весов в движке не существует — её надо собирать из скриптов классов.

### 2.5 Протокол производственной станции

**ФАКТ.** Полный путь заказа (все ссылки — оригинальные Tcl-файлы):

1. Клик по кнопке в GUI → `evt_btn_on` (`genericprod.tcl:32-52`): либо прерывает текущего работника,
   либо ставит заказ через `set_prod_slot_cnt`.
2. `get_prod_slot_cnt` / `set_prod_slot_cnt` — очередь заказов на изделие у станции (см. §2.7).
3. Гном приходит на станцию → `prod_getitemtask $itemtobuild` (`genericprod.tcl:699-737`) строит
   список шагов:
   - если имя начинается с `Bp` → это **изобретение**: шаги = [`prod_invent Bp<предмет>`,
     `prod_finishitem Bp<предмет>`], всего 2;
   - иначе — обычное производство: шаги = `call_method this prod_item_actions $item` + `prod_finishitem $item`;
   - если счётчик слота равен 0 → возвращается пустой список, работа не начинается.
4. `prod_finishitem` (`z_work_common.tcl:210-215`) — завершение и списание слота.
5. Прогресс-бар: глобалы `prod_maxsteps` / `prod_currentstep` + `info_start_prod` / `info_progress_prod`.

**ФАКТ.** Методы станции генерируются **автоматически** в `genericprod.tcl:98-139` — по списку
`tttitems_<станция>`:

| Метод | Возвращает | Источник |
| --- | --- | --- |
| `prod_items` | `tttitems_<станция>` | `genericprod.tcl:103` |
| `prod_preinvented` | `tttpreinv_<станция>` | `:104` |
| `prod_item_materials` | `tttmaterial_<изделие>` | `:112` |
| `prod_item_attribs` | `tttinvent_<изделие>` (пороги изобретения) | `:120-123` |
| `prod_item_exp_incr` | `tttgain_<изделие>` (прирост опыта) | `:124-127` |
| `prod_item_exp_infl` | `tttinfluence_<изделие>` (пороги влияния) | `:128-131` |
| `prod_item_number2produce` | `tttnumber2produce_<изделие>` (размер партии, по умолчанию 1) | `:132-139` |

**ФАКТ. Формула скорости.** `prod_getgnomeexper` (`genericprod.tcl:746-762`) — доля 0…1, насколько
гном «дотягивает» до требуемого опыта:

```
для каждой пары {навык, порог} из tttinfluence_<изделие>:
    если опыт_гнома < порог:  вклад += clan_exp_factor(навык) / порог × опыт_гнома
    иначе:                      вклад += clan_exp_factor(навык)
exp_infl = среднее_арифметическое(вклад) × 0.7 + atr_Mood × 0.3
```

**ФАКТ.** `clan_exp_factor` (`z_procs.tcl:45-56`) — множитель клана по навыку из
`ttt_<клан>clanexp` (по умолчанию 1.0), умноженный на `multi_exp_factor`
(`z_procs.tcl:37-43`): **1.0 в кампании и 2.0 в песочнице** — вне кампании весь опыт игры
качается вдвое быстрее.

**ФАКТ.** Число повторов анимации, зависящее от `exp_infl`: `prod_anim_loop_expinfl`
(`z_work_prod.tcl:558-565`) → `reps = round((max−min)·(1−exp_infl) + min)`. Для костра:
`workatfire` 1…3, `windloop` 3…9, `workfloorholz`/`workfloorstein` 1…4, `put` 1…2.

### 2.6 Хореография рецептов костра

**ФАКТ.** `prod_item_actions` костра (`feuerstelle.tcl:11-66`) — скелет любого заказа:

1. если изделие в `BOXED_CLASSES` (а это все постройки: `Zelt`, `Hauklotz`, `Steinmetz`,
   `Feuerstelle` — у всех тип `production`) → гном достаёт **пустой ящик** `Halbzeug_kiste`,
   ставит его на рабочее место 3 и уходит работать;
2. для каждого материала рецепта — `prod_actions_<Материал>` + `prod_exp $exp_incr 1/число_материалов`;
3. после каждого материала — отнести заготовку в ящик (`prod_anim_loop_expinfl put 1 2`);
4. собрать ящик: закрыть (`geschlossen`), взять на руки (`tragen`), отнести
   (`prod_createproduct_box_with_dummybox`);
5. если изделие не в `BOXED_CLASSES` — гном просто создаёт `prod_createproduct_rndrot`
   × `tttnumber2produce` раз;
6. финал: `prod_turnfront` + `prod_anim tired`.

**ФАКТ. Жарриб (`Grillpilz` из `Pilzhut`)** — `feuerstelle.tcl:71-101`:

```
prod_goworkdummy 0            ; встать у костра
prod_turnfront
prod_anim hungry              ; «голоден»
prod_turnright
× i раз:  prod_blowright; prod_anim fire     ; раздуть огонь
prod_walk_and_consume_itemtype Pilzhut        ; взять шляпку
prod_goworkdummy 2
prod_turnback
prod_machineanim feuerstelle.pilz; prod_anim_loop_expinfl workatfire 1 3 $exp_infl
prod_goworkdummy 3
prod_turnback
prod_anim windstart
prod_machineanim feuerstelle.pilzdreh; prod_anim_loop_expinfl windloop 3 9 $exp_infl
prod_anim windend; prod_machineanim feuerstelle.pilz
prod_goworkdummy 2
prod_turnback
prod_anim workatfire
prod_machineanim feuerstelle.brennt
```

где `i` = 5 при `exp_infl < 0.1`, иначе `1 + int(0.5/exp_infl)` (при максимуме `exp_infl` = 1 →
одно раздувание, при 0.5 → два, при 0.2 → три).

**ФАКТ. Жаркое (`Grillhamster` из `Hamster`)** — `feuerstelle.tcl:121-151`: та же схема, но машина
показывает `feuerstelle.hamster` / `feuerstelle.hamsterdreh`.

**ФАКТ. Обычная шляпка (любой другой продукт из `Pilzhut`)** — `feuerstelle.tcl:103-115`: гном
берёт шляпку, относит на рабочее место 1, `prod_anim benda`, кладёт на место 2
(`prod_beam_itemtype_to_dummypos $itemtype 2`), `bendb`, `workfloorholz`, включает частицы щепок
и пыли (`set_chips 1; set_dust 1`), `prod_anim_loop_expinfl workfloorholz 1 4`, выключает частицы.

**ФАКТ. Ножка (`Pilzstamm`)** — `feuerstelle.tcl:155-187`: гном делает из ножки `Halbzeug_holz`,
кладёт на место 2, рубит (`workfloorholz` 1…4), **с вероятностью `1 − exp_infl` спотыкается**:
`scratchhead` + `dontknow` + ещё 1…2 повтора; вид полуфабриката меняется случайно: `kant` или
`half` (50/50).

**ФАКТ. Камень (`Stein`)** — `feuerstelle.tcl:192-220`: то же через `Halbzeug_stein`, рубит
`workfloorstein` 1…4, та же неудача, вид полуфабриката всегда `mauer`.

**ФАКТ.** Виды полуфабрикатов: `Halbzeug_holz` — `roh/half/kant/brett/rad/holzzahnrad`,
`Halbzeug_stein` — `roh stein / mauer bearbeiteter_stein` (`items/werkzeuge.tcl:220-252`).

**ФАКТ.** Рабочие места (`prod_goworkdummy N`) у костра: 0 — сам костёр (раздуть огонь),
1 — место, откуда кладут заготовку, 2 — рабочее место гнома и вершина для шляпки,
3 — место у вертела / место ящика.

**ФАКТ. Места и ожидание.** `prod_guest addlink this 5/6/7`, затем `prod_guest_seats 3`, затем
`addlink 0/1/2/3/4`, `prod_guest_waits 8` (`feuerstelle.tcl:297-306`). Итого **8 гостевых слотов**:
по порядку регистрации первые 3 — **рабочие места**, оставшиеся 5 — **места ожидания**
(`reserve_seat` перебирает индексы от `prod_guest_seats` до `prod_guest_waits-1`, т.е. 3…7).
Тот же паттерн у театра (5 + 2 из 7) и бара (4 + 3 из 7) — значит правило «число `addlink` = число
слотов, первые `seats` — рабочие» общее для всех станций.

**ФАКТ.** `ask_for_seat` (`feuerstelle.tcl:239-241`) возвращает 1 («рабочее место свободно»)
тогда и только тогда, когда индекс первого свободного слота меньше `prod_guest_seats`:
`guestfree` возвращает **индекс** первого свободного слота или -1
(`z_spare_procs.tcl:903`), а целочисленное деление `guestfree / prod_guest_seats` даёт 0 ровно
при индексе < 3. Проверено по смыслу вызовов: `z_spare_procs.tcl:261-263` — «есть место, садись»,
`z_spare_procs.tcl:142-146` — «место свободно, идём сюда, `pathcosts` = 0»,
`z_spare_fun.tcl:467` — «места нет, пробуем зарезервировать очередь».

### 2.7 Движковый слой: кто назначается на костёр и как живёт очередь

**ФАКТ.** В оригинале планировщик производства — **не Tcl, а C++**: исходники лежат в бинарнике
как строки `C:\dev\wiggles\Wiggles\Wiggles\AI\ProdPlanner.cpp` (`0x007215D0`) и
`...\AI\ProdAllocator.cpp` (`0x00721438`).

| Что | Адрес | Суть |
| --- | --- | --- |
| `CProdPlannerMgr::Tick` | `0x00432720` | обход станций, наполнение реестра |
| `CProdPlannerMgr::Reset` | `0x00432970` | сброс всех 8 планировщиков |
| `CProdPlanner::MaintenanceTick` | `0x00433A70` | основной тик планировщика |
| `CProdPlanner::GnomeIdle` | `0x00434A80` | гном остаётся без работы |
| `FUN_00437DA0` | `0x00437DA0` | назначение гнома на станцию |
| `FUN_00437BB0` | `0x00437BB0` | обнуление и заполнение матрицы оценок |
| `FUN_0043A460` / `FUN_0043A0C0` | `0x0043A460` / `0x0043A0C0` | привязка / отвязка гнома от станции |
| `FUN_0043A290` | `0x0043A290` | проверка назначения |
| `FUN_00434BC0` | `0x00434BC0` | попытка заново привязать гнома |
| `SlotIdByName` / `SlotCountGet` / `SlotCountSet` | `0x005EDB60` / `0x005ED9D0` / `0x005EDA20` | таблица заказов станции |

**ФАКТ.** Планировщиков **по числу кланов — 8**, они лежат **инлайном** в менеджере с шагом
`0x3094` (12436 байт); каждый тик обрабатывается **один** планировщик по кругу:
`idx = (idx+1) & 7` (`0x0043285C`). `CProdPlannerMgr::Reset` инициализирует ровно 8 слотов.

**ФАКТ.** Структура состояния станции — `SITE = *(CObj+0x3E0)`, состояния гнома —
`GNOME = *(CObj+0x3E4)`:

| SITE | Значение | | GNOME | Значение |
| --- | --- | --- | --- | --- |
| `+0x04` | число занятых работников (`info_start_prod` ++ / `info_end_prod` --) | | `+0x04` | флаг отвязки |
| `+0x0C` / `+0x10` | таблица заказов станции, запись **0x1C** байт | | `+0x0C` | под-состояние: `2` — свободен, `14` — ждёт |
| `+0x1C` | текущий тип изделия | | `+0x28` / `+0x2C` | два связанных объекта (индексы) |
| `+0x24` | текущий работник | | `+0x34` | `0` — свободен, `1` — занят (`prod_gnomeidle`) |
| `+0x28` | запрошена распаковка | | `+0x3C` | последнее рабочее место (индекс, -1 = нет) |
| `+0x29` | запрошена упаковка | | `+0x40` | **предпочитаемое** рабочее место (индекс, -1 = нет) |
| `+0x2A` | запрошена сборка | | `+0x48` | обнуляется при перепривязке |
| `+0x3F` | `switchMode` — переключение цели производства | | | |
| `+0x40` | `exclusiveMode` — только один работник за раз | | | |
| `+0x41` / `+0x42` | нужен материал / нужен инструмент | | | |
| `+0x43` / `+0x44` | `schedule` / `directEvents` | | | |
| `+0x5C` | обнуляется/ставится в 5 при отвязке | | | |
| `+0x68` | `ownerStrength` — **float** 0…1 | | | |
| `+0x6C` | таблица гостей (`prod_guest`), запись `0xC` байт | | | |

**ФАКТ. Семантика очереди.** `set_prod_slot_cnt` (`CTclObjMethods::SetProdSlotCnt`,
`0x00691E40` → `SlotCountSet` `0x005EDA20`) **обрезает значение в диапазон 0…10**
(`cmovns` для отрицательных, `cmp`/`cmovg` с 10). Это **не убывающая FIFO-очередь**, а
**квота**: «сколько единиц этого изделия ещё должно быть сделано на этой станции».

- Пишет квоту **AI**: `ai/std_ai.tcl:2202` (`set_prod_slot_cnt $chosen $classname 1` — «заказать
  ровно одно изобретение»), `:1962`, `:1981` (по 10).
- Читает её **задачник гнома**: `prod_getitemtask` возвращает пустой список, если
  `get_prod_slot_cnt this <item> == 0` (`genericprod.tcl:708`, `:723`) — это и есть предохранитель,
  останавливающий гнома при пустой очереди.
- Сбрасывает её **всю сразу**: `stop_production 1` обнуляет все слоты
  (`genericprod.tcl:686-689`), то же при «все заказы удалить» (`z_work_common.tcl:632-635`).
- Движок **не уменьшает** счётчик: у `SlotCountSet` ровно один вызывающий — `SetProdSlotCnt`.
  Списание происходит через `prod_finishitem` → `finish_itemprod` → `stop_production`.

**ФАКТ. Связь движка и Tcl.** Планировщик **не читает** счётчики заказов и **не знает** о
`prod_guest` — эти две подсистемы связаны только через Tcl-события. Форматы команд движка
(Tcl-строка, `evt_autoprod_*`, движок → гном) лежат в `.rdata`:

```
0x0072169C  set_event %s evt_autoprod_walk -target %s -pos1 {%f %f %f}
0x00721710  set_event %s evt_autoprod_pickup_store -target %s -subject1 %s -text1 %s
0x00721760  set_event %s evt_autoprod_pickup -target %s -subject1 %s -text1 %s
0x007217A8  set_event %s evt_autoprod_transferprod -target %s -subject1 %s -subject2 %s -text1 %s
0x00721800  set_event %s evt_autoprod_harvest -target %s -subject1 %s -text1 %s
0x00721848  set_event %s evt_autoprod_workat -target %s -text1 %s -subject1 %s
0x00721890  set_event %s evt_autoprod_workat -target %s -text1 Bp%s -subject1 %s
0x007218D8  set_event %s evt_autoprod_dig -target %s -pos1 {%f %f %f}
0x00721918  set_event %s evt_autoprod_pack -target %s -subject1 %s -text1 %s
0x00721960  set_event %s evt_autoprod_unpack -target %s -subject1 %s -text1 %s -pos1 {%f %f %f} -num1 %d
```

`evt_autoprod_workat` — команда «иди работать на эту станцию, делая этот предмет»;
обработчик в оригинале (`z_events.tcl:1127-1141`):

```tcl
proc evt_autoprod_workat_proc {} {
    tasklist_clear this ; stop_prod ; notify_autoevent
    set current_plan "work" ; set current_worktask "work"
    set current_workplace [event_get this -subject1]
    set current_workclass  [event_get this -text1]
    ...
    state_triggerfresh this work_auto
}
```

Вариант `text1 Bp%s` означает **изобретение** (префикс `Bp` снимается в
`genericprod.tcl:352`). Это точная точка стыковки, которой в порту нет.

**ФАКТ. Приоритеты.** Числового приоритета «еда против построек» в движке **нет**: единственный
порядок — float-оценка пары «гном ↔ станция» (`rating` в записи `0x28` байт, смещение `+0x18`),
и кандидат принимается только при `rating > 0` (строго). Порядок «сначала еда» живёт в Tcl-AI:
`ai/std_ai.tcl:1941-1981` — сначала проверяются `Pilz Hamster Raupe` (еда), потом ферма, а приоритет
изобретения задаётся `get_owner_attrib $populationowner Bp$item > 0.5`.

**ФАКТ.** `prod_guest` — **отдельный механизм**: аллокатор мест/очереди для зданий досуга
(больничные койки, места в баре, места в театре), а не часть планировщика производства.
Планировщик в прочитанном коде не обращается к `SITE+0x6C`.

**ФАКТ.** `evt_task_workprod_prefer` (`genericprod.tcl:80-83`) — единственная подсказка маршрутизации
гнома: она пишет `GNOME+0x40` (предпочитаемое рабочее место), и именно это поле читает
`MaintenanceTick` при отборе гномов.

## 3. Анимации

### 3.1 Анимации самого костра

**ФАКТ.** Клипы из `feuerstelle.tcl`:

| Клип | Когда | Строка |
| --- | --- | --- |
| `feuerstelle.brennt` | постоянно горит (дефолт) | 284, 290, 99, 148 |
| `feuerstelle.pilz` | гриб на костре | 90, 95 |
| `feuerstelle.pilzdreh` | гриб переворачивают | 94 |
| `feuerstelle.hamster` | хомяк на костре | 139, 144 |
| `feuerstelle.hamsterdreh` | хомяк переворачивают | 143 |

**ФАКТ (проверено штатным инструментом `tools/inspect_3db.py`, 3DB `produktionsstaetten.3db`,
объект `feuerstelle`).** У объекта 12 анимационных слотов:

| Индекс | Клип | Кадров | Меши | Роль |
| --- | --- | --- | --- | --- |
| 70 | `standard` | 3 | 307, 308, 309 | готовое, но не горящее состояние |
| 71 | `brennt` | 3 | 310, 311, 312 | **горение** (дефолт) |
| 72-75 | `bau_a`…`bau_d` | по 1 | 313, 314, 315, 316 | **шаги стройки** (3 шага + финальный) |
| 76 | `zerstoert` | 1 | 317 | разрушено |
| 77 | `pilz` | 1 | 318 | гриб на костре |
| 78 | `pilzdreh` | 8 | 319-326 | гриб переворачивают |
| 79 | `hamster` | 1 | 327 | хомяк на костре |
| 80 | `hamsterdreh` | 8 | 328-335 | хомяк переворачивают |
| 81 | `convex` | 2 | 336, 337 | коллизионный халл (материал `Checker`), не видим |

**ФАКТ.** `bau_a`…`bau_l` — это **общий набор шагов стройки для всех производственных зданий**:
в том же пакете свои `bau_a`…`bau_d` есть у пивоварни, паровой машины, додзё, токарного станка,
палаток (a/b/c), надгробья, пограничного камня и т.д. — каждый со своими мешами. Именно поэтому
общий код `genericprod.tcl:787-799` переводит номер шага в клип (`0→bau_a` … `9→bau_k`,
`10+→standard`) без знания о конкретном здании: выбирается здание, а не клип.

**ФАКТ.** Поле `extra.u16` у записей анимации заполняется неоднородно: у `standard` костра
`u16 = 6`, что совпадает с порядковым номером объекта в пакете (`fahne`=0, `brauerei`=1,
`dampfhammer`=2, `dojo`=3, `dreherei`=4, `feuerstelle`=6), а у остальных записей того же объекта
стоят 13120 и 20656. Значит трактовать это поле как «номер объекта» для всех записей нельзя;
ориентироваться надо на индекс анимации.

**ФАКТ.** У объекта 6 поверхностей: `Trollh_Boden_b_End_b_256` (щебень), `Holz_Standard_d_256`
(деревянная конструкция), `Stein_Standard_a_256` (каменное кольцо) — по ним геометрия есть, и
три слота **реквизитов других анимаций** без геометрии: `Urwald_Pilz_a_256` (шляпка) и два
`Character_Hamster_a_128` (хомячок). Подробно — §6.

**ФАКТ, решающая находка — пламя это UV-скролл, а не анимация геометрии.**
Побайтовое сравнение мешей показывает, что у `standard` и `brennt` **совпадают вершины,
UV и яркость**; различаются только две UV-подмножества: `uv_id 110` (база) и `uv_id 112`
(смещение ровно на **3/16 = 0.188235**) при 10 fps. Сдвиг есть **только** на ссылке
`Holz_Standard_d_256` — на поверхностях щебня и камня UV-дельта равна нулю.
Цикл кадров: `[110, 112, 110]` — то есть пламя мерцает прокруткой текстуры брёвна,
а видимый огонь дают **частицы + точечный свет** (`feuerstelle.tcl:272-280`).
Для порта это значит: анимацию огня можно воспроизвести ровно двумя состояниями UV,
без лишней геометрии.

**ФАКТ.** Габариты в мире: `brennt` bbox нативно x[-241.36..241.30] y[-154.68..1.52]
z[-241.31..241.29], при `model_to_world_scale = 0.005` → примерно **2.41 × 0.78 × 2.41**
мировых единиц: это большой общий костёр, а не маленький очаг.

**ФАКТ.** Длительности (10 fps): `brennt` — 3/10 = **0.30 с** цикла; `pilzdreh` и `hamsterdreh` —
8/10 = **0.80 с**; `bau_a`…`bau_d` — по 1/10 = 0.10 с (статичная поза).

**ФАКТ.** Исходник автинга: `extra.string` указывает на
`\\FILESERVER\Projects\Heinz\Grafik\Sexport\Produktionsstaetten\feuerstelle_<клип>.sex`
— по одному `.sex` на клип.

### 3.2 Анимации гнома у костра

**ФАКТ.** Из `feuerstelle.tcl`:

| Клип | Смысл | Строка |
| --- | --- | --- |
| `hungry` | подошёл покушать | 77, 126 |
| `fire` + `prod_blowright` | раздувает огонь | 85, 134 |
| `workatfire` | работает у огня | 90, 98, 139, 147 |
| `windstart` / `windloop` / `windend` | раздувает угли/ветер | 93-95, 142-144 |
| `banda` / `bendb` | нагнуться/встать | 23, 25, 106, 108, 163, 165, 200, 202 |
| `put` / `puta` / `putb` | положить/взять вещь | 40, 47, 49 |
| `takeboxa` / `takeboxb` | взять ящик | 50, 52 |
| `workfloorholz` | колоть дрова | 109, 167, 169 |
| `workfloorstein` | тесать камень | 204, 206 |
| `scratchhead` / `dontknow` | реакция на брак материала | 172-173, 209-210 |
| `tired` | устал после работы | 63 |
| `praystart`/`prayloop`/`praystop` | молитва у надгробья (для `Grabstein`) | `z_work_common.tcl:487-491` |

### 3.3 Опыт управляет длительностью работы

**ФАКТ.** `prod_anim_loop_expinfl {animname minreps maxreps exp_infl}`
(`z_work_prod.tcl:558-565`): число повторов = `round((maxreps - minreps) × (1 - exp_infl) + minreps)`.
Опытный гном повторяет меньше раз, неопытный — больше.

| Действие | Повторов | Строка |
| --- | --- | --- |
| `workatfire` | 1…3 | 90, 139 |
| `windloop` | 3…9 | 94, 143 |
| `workfloorholz` | 1…4 | 111, 169, 175, 182 |
| `workfloorstein` | 1…4 | 206, 212, 215 |

**ФАКТ.** Раздувание огня (`feuerstelle.tcl:79-83`, `128-132`): если `exp_infl < 0.1` — 5 раз,
иначе `1 + int(0.5 / exp_infl)`.

**ФАКТ.** Опыт при производстве: `prod_getgnomeexper` (`genericprod.tcl:746-762`) усредняет
по требуемым навыкам и домножает на настроение: `exper × 0.7 + atr_Mood × 0.3`.
Влияние на скорость: `tttinfluence_Feuerstelle {{exp_Holz 0.5} {exp_Nahrung 0.5} {exp_Stein 0.5}}`
(`techtreetunes.tcl:28`) — опыт в дереве/камне/питании ускоряет работу у костра до 50 %.
За сам факт постройки костра гном получает `exp_Holz 0.01` и `exp_Stein 0.01`
(`techtreetunes.tcl:26`).

### 3.4 Частота кадров

**ФАКТ (репозиторий).** Оригинальный контроллер выдаёт **10 кадров в игровую секунду**
(`controller_frames_per_game_second` = 10.0, `0x007373F0`); 12 fps в порту — адаптер,
см. `README.md` и `docs/reverse-engineering/native-animation-timing-2026-11-17.json`.

## 4. Строительство и «распаковка»

Это самая недооценённая механика оригинала: здание **приезжает ящиком** и **распаковывается**
на месте.

### 4.1 Три состояния объекта

**ФАКТ.** У производственной площадки есть флаг `boxed` (`get_boxed`/`set_boxed`):

| Состояние | Значение | Источник |
| --- | --- | --- |
| ящик (`boxed=1`) | здание упаковано, `init` не выполняется, свет и частицы выключены | `genericprod.tcl:19`, `179-192` |
| призрак (`ghost`) | размещённый, но ещё не доставленный на место силуэт | `z_work_common.tcl:364`, `416` |
| стройка (`buildup_step`) | здание собирается по шагам, показывая `bau_a`…`bau_k` | `genericprod.tcl:776-814` |

**ФАКТ.** В движке это **три независимых бита в разных хранилищах**, а не одно состояние:

| Что | Где | Бит / поле |
| --- | --- | --- |
| `boxed` — объект физически упакован | слово флагов объекта `obj+0x3D0` | **`0x00040000`** (`GetLock`/`SetLock` `0x0067E5E0` / `0x0067DC80`) |
| `build` — идёт стройка | то же слово `obj+0x3D0` | **`0x00400000`** (`Get/SetBuildUpState` `0x0067E410` / `0x0067E1E0`) |
| `locked` — предмет нельзя взять | то же слово `obj+0x3D0` | `0x00000004` (`GetLock`/`SetLock` `0x0067D2E0` / `0x0067D0C0`) |
| запрошена распаковка | запись производства `CProd = *(obj+0x3E0)` | `+0x28` (`Get/SetProdUnpack` `0x00692DB0` / `0x00692F80`) |
| запрошена упаковка | там же | `+0x29` (`Get/SetProdPack` `0x006931E0` / `0x006933B0`) |
| целевая позиция стройки | там же | `+0x30…+0x38` (vec3) |
| служебное слово статуса | там же | `+0x3D…+0x3E` (`0x0100` = «стройка заказана») |

**ФАКТ.** `set_boxed` (`0x0067DC80`) — не простое переключение бита:
- `set_boxed 1` (упаковать): **ставит** `boxed`, **снимает** `build`, обнуляет служебное слово и
  флаги «запрошена упаковка», обновляет вид объекта по классу;
- `set_boxed 0` (распаковать): **снимает** `boxed`, `build` при этом **остаётся**, и снимаются
  флаги «запрошена распаковка».

**ФАКТ.** Упакованный объект **не инициализируется**: `evt_timer_init` в `genericprod.tcl` вызывает
`init` только если `get_boxed this == 0`. Значит у костра свет, частицы и анимация `brennt`
появляются **только после распаковки** — ровно то, что описано ниже.

**ФАКТ.** Счётчик шагов `buildup_step` — **не поле движка**, а переменная уровня класса в Tcl
(`method set_buildupstep` в `genericprod.tcl`); она же вызывает `info_progress_prod` и
`set_buildupanim`. «Бит стройки» ставится самим `set_buildupanim` — он вызывает
`set_buildupstate this (buildup_step > max_buildup_step)`, то есть бит горит на шагах
0…max и гаснет после последнего.

**ФАКТ. `packtobox`** (`genericprod.tcl:179-192`): гасит свет, освобождает все 16 источников
частиц, снимает туман войны, ставит `boxed = 1`.

**ФАКТ. `unpackfrombox`** (`genericprod.tcl:194-210`): обнуляет поворот, раскрывает туман войны
по `tttfow_x/tttfow_y`, очищает список задач, ставит `boxed = 0`, прячет призрак и **вызывает
`init`** — то есть только здесь у костра появляется свет, частицы и анимация `feuerstelle.brennt`.
Ключевой вывод: `unpackfrombox` — это финальный шаг стройки, а не отдельное действие.

### 4.2 Полный цикл постройки

**ФАКТ.** `z_work_common.tcl:326-342` (`prod_autounpack`) — гном приходит на рабочее место:

```
если объект в ящике (boxed):
  walk_pos → prod_buildup_check → send_gnomes_outofplacement
            → pickup (взять ящик) → unpack_pos_unfixed
если объект уже распакован:
  walk_pos → prod_buildup_check → send_gnomes_outofplacement
            → prod_changetool Hammer → get_beambackpos → prod_buildup_rep → beam_back
```

**ФАКТ.** `unpack_pos_unfixed` (`z_procs.tcl:1172-1195`): блокирует предмет, гном ставит его
(`play_anim [putdown_anim]`), получает `exp_transp_increase`, и если это не «как ящик»
(`asbox = 0`), уходит в `prod_buildup_new` — то есть в собственно стройку.

**ФАКТ.** `prod_buildup_new` (`z_work_common.tcl:403-411`): проверка места (`check_ghost_coll`),
ожидание, пока проход освободится (до 40 игровых секунд, иначе гном уходит и теряет работу),
затем `inv_rem`, `set_boxed 0`, `set_buildupstep 0`, показ объекта, и `prod_buildup`.

**ФАКТ. Отказы на этапе проверки** (`prod_buildup_check`, `z_work_common.tcl:345-371`): гном
отказывается строить, если (а) призрак здания пересекается с другими объектами
(`check_ghost_coll objects`) или (б) здание упаковано и **у гнома нет его в инвентаре**
(`inv_find_obj this $item < 0`). При отказе: `tasklist_clear`, `set_prod_unpack 0`,
`hide_obj_ghost`, `stop_prod` — то есть заказ снимается, а здание убирается назад.

**ФАКТ. Ждать прохода** (`prod_buildup_waitforfree`, `:383-401`): пока гномы стоят в зоне
призрака, гном ждёт до 40 игровых секунд, повторяя проверку; каждый 30-й повтор он
проигрывает `impatient`, иначе `standloopa`.

**ФАКТ. Куда встаёт гном при стройке** (`prod_buildup_rep`, `:473-508`): якорь берётся из
`build_dummys` через `get_build_dummy $bstep` (для костра это `16 16 17`), позиция гнома —
`get_linkpos $item $steplink` + позиция здания, поворот — `get_linkrot $item $steplink` + π.
Рядом вычисляется `set partlink [expr {19 + $bstep}]` — **эта переменная в оригинале не
используется** (мёртвый код), но она показывает, что у модели есть и «партнёрские» якоря 19+.

**ФАКТ. Анимация гнома при стройке** — `get_buildupanim`: на шаге 0 это `digdownstone`
(для лифтов — `oben_rechtsstein`), дальше `buidup_anis[buildup_step − 1]`. У костра это
`unten_rechtsstein` → `unten_rechtsholz` → `unten_linksholz` (три удара молотом по камню, дереву
справа и дереву слева).

**ФАКТ. Вторичного расхода материалов при распаковке НЕТ** — это закрывает вопрос B09.
Материалы съедаются один раз, при изготовлении ящика на станции (`prod_actions_Pilzstamm` /
`prod_actions_Stein` заканчиваются `prod_walk_and_consume_itemtype`). При распаковке гном
просто убирает ящик из своего инвентаря (`inv_rem this $item` в `prod_buildup_new` и в
`unpack_pos_unfixed`), переводит объект в состояние «не упакован» (`set_boxed 0`), ставит его
на место и показывает. Никаких новых ресурсов не требуется.

**ФАКТ.** `unpack_pos_unfixed` (`z_procs.tcl:1172-1195`) — общий финал распаковки: требует,
чтобы предмет был в инвентаре гнома, **блокирует** его (`lock_item`), гном выходит из
транзита, поворачивается и ставит предмет (`play_anim [putdown_anim]`), получает
`exp_transp_increase` (опыт транспорта), и дальше — либо `prod_buildup_new` (полная сборка),
либо просто постановка ящика (`inv_rem` + `set_pos` + видимость + `unlock_item`), если параметр
`asbox` истинен. Именно `asbox` передаётся из `prod_autounpack` как `$current_worknum`.

**ФАКТ.** `prod_buildup` (`z_work_common.tcl:413-437`): гном берёт **молот** (`prod_changetool Hammer`),
встаёт к нужной точке и начинает бить. Для `Abfluss`, `Leiter`, `Leiter_Kristall`, `Leiter_Metall`,
`Plattmachfalle`, `SteinfalleMedusa` есть ускоренный путь (`set_buildupstep 4` + `unpackfrombox`).

**ФАКТ.** `prod_buildup_rep` (`z_work_common.tcl:473-508`) — шаг за шагом:
1. `buildup_step` сравнивается с `max_buildup_step`;
2. если шаг пройден — `unpackfrombox` (здание оживает) и `beam_back`;
3. иначе гном встаёт к `build_dummys[step]`, смотрит в сторону объекта,
   проигрывает `buidup_anis[step - 1]` нужное число раз, `buildup_step` увеличивается,
   и гном получает `exp_Transport`.

**ФАКТ. Анимации здания при стройке.** `set_buildupanim` (`genericprod.tcl:776-814`) переводит
`buildup_step` в клип: 0→`bau_a`, 1→`bau_b`, 2→`bau_c`, 3→`bau_d`, 4→`bau_e`, 5→`bau_f`,
6→`bau_g`, 7→`bau_h`, 8→`bau_i`, 9→`bau_k` (буквы `j` нет), дальше — `standard`.
У костра `max_buildup_step = 3` (`feuerstelle.tcl:309`), `buidup_anis` =
`{unten_rechtsstein unten_rechtsholz unten_linksholz}` (`feuerstelle.tcl:310`) — это удары гнома
молотом: камень справа снизу → дерево справа снизу → дерево слева снизу.
`build_dummys {16 16 17}` (`feuerstelle.tcl:308`) — номера точек привязки в модели.

**ФАКТ. Флаг `buildupstate`** (`genericprod.tcl:812-813`) — здание «в процессе стройки»;
в `z_work_prodfill.tcl:568` гном не берёт заказ у недостроенного здания.

### 4.3 Время постройки

**ФАКТ.** `get_buildanim_count` (`z_work_common.tcl:541-552`):

```
exper = exp_Transport (+ 0.3 × exp_Holz/exp_Stein/exp_Metall по категории здания)
exper = clamp(exper, 0.1, 0.8)
число повторов анимации = (1 - exper) × (8.0 + шаги × 0.7)
```

Для костра (`шаги = 3`): база `8 + 3×0.7 = 10.1`; при `exper = 0.1` → 9.09 повторов,
при `exper = 0.8` → 2.02. Разборка занимает половину времени
(`z_work_common.tcl:531`: `maxanimcnt × 0.5`).

**ФАКТ.** Гном при постройке получает `exp_Transport` по `tttgain_buildup`
(`z_work_common.tcl:506`, `537`).

### 4.4 Разборка и ремонт

**ФАКТ.** `prod_builddown` (`z_work_common.tcl:439-470`) — обратный ход: те же анимации в обратном
порядке, пока не остаётся `buildup_step = 0`, затем `packtobox` — здание снова становится ящиком.
`prod_repair` / `prod_repair_rep` (`z_work_common.tcl:554-587`) восстанавливают `atr_Hitpoints`
по 0.01 за удар.

**ФАКТ.** Стройка и разборка недоступны, если здание захвачено: `conquer`
(`z_work_common.tcl:590+`) распределяет завоевание по шагам, `get_max_buildup_step` даёт число
шагов, каждый шаг занимает `1.0 / buildup_step / 6`.

### 4.5 Про «распаковку» — два разных механизма

**ФАКТ, решающий.** Русская строка интерфейса для действия `unpack` — **«распакуй»**
(`data/messages.txt:1972-1973`). Соседние строки того же смыслового семейства:
`pack` → «упакуй» (`:1930-1931`), `packtobox` → «пакуй» (`:1831-1832`),
`boxed` → «упаковано» (`:1828-1829`), `buildup` → «строй» (`:1837-1838`).
То есть «распаковка» в игре — **буквально** действие над ящиком с готовым зданием.

**ФАКТ.** Курсор мыши при этом возвращает строку `"unpack"`
(`Scripts/init/eventgen.tcl:161-185`, `:221`), и она уходит в машину состояний гнома:
`z_work_states.tcl:140-144` → `tasklist_add this "prod_autounpack $current_workplace {$current_workpos}"`.

**ФАКТ.** В движке два режима размещения производственной площадки — `-asbox` (поставить ящиком)
и `-asprod` (поставить готовой площадкой); обе строки лежат в `Diggles.exe` по смещению
`0x32691D`:
`-command -placement -asbox -pos {%f %f %f} -rot {%f %f %f} -snapobj %d`
(и `-asprod` соответственно).

**ФАКТ.** Два разных механизма:

1. **`unpackfrombox` — распаковка здания.** Только что описанный финал стройки: ящик приезжает,
   гном его ставит, строит, и на последнем шаге здание «распаковывается» — появляется свет,
   частицы, анимация горения.
2. **Упаковка продукции в ящик.** `BOXED_CLASSES = {production energy store elevator protection}`
   (`genericprod.tcl:6`). Если производимый предмет относится к этим классам, гном:
   ставит пустой ящик (`Halbzeug_kiste`) → относит каждую заготовку в ящик
   (`prod_anim_loop_expinfl put 1 2`) → кладёт готовый продукт в ящик
   (`prod_createproduct_inv_boxed`, `prod_itemtype_change_look Halbzeug_kiste geschlossen`) →
   переносит ящик (`prod_goworkdummy_with_box`, `prod_createproduct_box_with_dummybox`).
   Для костра это касается `Zelt`, `Hauklotz`, `Steinmetz`, `Feuerstelle` — то есть здания
   уезжают с костра **в ящике**, а еда (`Grillpilz` и прочие) просто кладётся на землю
   (`prod_createproduct_rndrot`, `feuerstelle.tcl:55-60`).

**ФАКТ. Важное уточнение.** `Halbzeug_kiste` объявлен как `def_class Halbzeug_kiste none dummy 0`
(`werkzeuge.tcl:317`) — это **реквизит**, а не контейнер с ресурсами. Реальная начинка —
невидимый объект-здание с `set_boxed 1`. **Механики «открыть ящик и высыпать ресурсы» в
`Scripts/` и `GameScripts/` нет**: поиск `auspacken/entpacken/auspack/entpack` не даёт совпадений,
немецкий код использует только `packtobox` / `unpackfrombox` / `unpack_pos_unfixed` /
`prod_autounpack`. Единственное «открытие» в игре — `evt_task_open_box` для сундука-сокровищ
(`Schatzbuch`), к ящикам отношения не имеет.

**ФАКТ.** В интерфейсе упакованное здание помечается иконкой `data/gui/icons/unpack.tga`
(`Scripts/text/doc/ru/info_prods.tcl:54-58`).

## 5. Еда, досуг и лагерь у костра

**ФАКТ.** `sparetime_eatplaces {Feuerstelle}` (`z_spare_main.tcl:333`) — костёр единственное
место еды на ранней стадии. `sparetime_eatclasses {Grillpilz Grillhamster Pilzbrot Raupensuppe
Raupenschleimkuchen Gourmetsuppe Hamstershake}` (`z_spare_main.tcl:334`) — полный список еды.

**ФАКТ.** `sparetime_eat_check` (`z_spare_procs.tcl:63-92`): гном ищет еду
1) в своём инвентаре, 2) рядом на земле, 3) **внутри склада** (`-flagpos {visible instore}`) —
то есть принесённую еду гном может взять прямо из кладовой.

**ФАКТ.** `sparetime_eat_start` (`z_spare_procs.tcl:94-209`): гном оценивает каждое блюдо
по «вкусу» (смесь предпочтений и характеристик блюда), ищет площадку, у которой есть еда
(`get_eat_objects`, радиус 7), учитывает расстояние (вес 15.0, если место занято и рядом) и
разочарование (`civ_state` минус «цивилизованность» места). Если место свободно — занимает
сиденье (`ask_for_seat`/`reserve_seat`), иначе встаёт в очередь из 8 ожидающих.

**ФАКТ.** `get_certain_object` (`feuerstelle.tcl:234-238`) — гном забирает конкретное блюдо
с площадки (поиск в радиусе 8, без `contained`/`locked`).

**ФАКТ.** Костёр — и место досуга: `z_spare_reprod.tcl:383` ищет `{Feuerstelle Zelt}` в радиусе 7,
чтобы поставить там «попplace» для отдыха.

### 5.1 Лагерь у костра на карте оригинала

**ФАКТ.** Шаблоны карты лежат в `data/Templates/*.tcl` обычным текстом — сцену можно прочитать
целиком. Шаблон `urw_unq_vodo_001_a.tcl` (22 547 байт) — «вудуистический лагерь», и его состав:

| Объект | Позиция в шаблоне | Владелец | Роль |
| --- | --- | --- | --- |
| `Feuerstelle` | 14.6248, 10.4012, 9.47998 | 1 (игрок) | **костёр**, `physic true`, `autolight false`, `boxed false` |
| `Zelt` | 9.9217, 10.46, 6.39999 | 1 | палатка рядом с костром |
| `Misc_LightSrc_a` | 15.5, 9.5, 8.75 | −1 | источник света у костра |
| `Misc_Light` | 21.1549, 9.55325, 11.01 | −1 | факел |
| `Grillpilz` ×5 | 16.4004, 10.5265, 5.8 | −1 | готовая еда, лежит кучкой |
| `Grillhamster` ×5 | 7.77…15.35, 10.5, 5.6…7.34 | −1 | готовая еда |
| `Hamster`, `Raupe` ×2, `Pilz` ×2 (возраст 3 и 1), `Bier` ×3 | — | −1 | сырьё и добыча |
| `Keule`, `Fuchsschwanz`, `Schatztonne` ×2 | — | −1 | булава, хвост, сундуки |
| `PseudoZwerg` ×2 (мужского пола) | 11.32 / 6.97 | 1 | статичные «гномы» декорации |
| `Trigger_FirstContact` | 31.04, 10.5, 13.01 | 0 (игрок) | сюжетный триггер |
| `Dummy_Multi_Voodoo_Seule_*`, `Info_Coll_*`, `Info_Pos_Troll` | — | −1 | вудуистические столбы и служебные маркеры |

**ФАКТ.** У костра явно стоит `set_autolight $objhandle false` — движок не ставит факел рядом
с костром автоматически (у костра есть собственный свет). У всех объектов идёт
`set_boxed $objhandle false` — `set_boxed` настоящая команда движка.

**ФАКТ.** Шаблоны размечены по уровню детализации: `loading_objdetail high / medium / low / off`
(`data/Templates/urw_unq_vodo_001_a.tcl`) — это LOD размещения объектов, а не рендера.

**ФАКТ.** Мировые координаты тех же трёх костров в портовых данных
(`godot/models/native_campaign_model_manifest.json`):

| Шаблон | template_x / y | Мировая позиция | z |
| --- | --- | --- | --- |
| `urw_unq_vodo_001_a` | 212 / 56 | 226.6248, 66.4012 | 9.47998 |
| `urw_unq_vodo_004_a` | 96 / 142 | 120.1881, 152.44 | 6.79 |
| `urw_unq_vodo_007_a` | 104 / 162 | 119.0, 168.5 | 10.0 |

### 5.2 Сюжетная линия вудуистического костра

**ФАКТ.** `Trigger_FirstContact` (`Scripts/classes/story/Trigger_Urwald.tcl:180-236`):
комментарий в оригинале — «ausgelöst durch Zwerg Owner 0 (Wiggle) / FogRemover 14 Zm nach links /
setzt Produktion der Feuerstelle auf 10 Futter». То есть: игрок-гном подходит к костру →
срабатывает триггер → снимается туман войны → **костру ставится заказ на 10 Жаррибов**:

```
set fs [obj_query this "-class Feuerstelle -range 10 -limit 1"]
if { $fs != 0 } { set_prod_slot_cnt $fs Grillpilz 10 }
```

**ФАКТ.** `Trigger_FirstContact::destroy_overload` (`:203-219`): если костёр уничтожают,
всё сырьё (`Pilz`, `Hamster`) в радиусе 10 от него переводится владельцу 1 — то есть игрок
не теряет пропажу.

**ФАКТ.** `Trigger_Urwald.tcl:192-201` — `remove_fow` создаёт `FogRemover` шириной 14 клеток.

### 5.3 Другие источники огня в игре

**ФАКТ.** Костёр — не единственный огонь в оригинале:

| Класс | Где | Что это |
| --- | --- | --- |
| `Fake_Feuerstelle` | `classes/items/misc_items.tcl:3` | **декоративный** костёр без всякой логики; дефолтная анимация — `feuerstelle.hamsterdreh`; используется как реквизит в сюжете (`sequences/Lava/lav_450.tcl:297`) |
| `Dummy_Feuerkelch_a` / `_b` | `classes/deco/dummy_trollhausen.tcl:4,13` | **чаши с огнём** (декорации): своя анимация `feuerkelch_a.standard`, `class_physic 0` |
| `Ring_Des_Feuers` | `classes/story/Ringe.tcl:50` | «Кольцо огня» — сюжетный объект, анимация `feuerring.standard` (в 3DB — 19 кадров `drehen`) |
| `Schmiedefeuer_a` | `3db/trollhausen.3db` | кузнечный огонь |
| `Kernzenstaender_a/b` | `3db/licht.3db` | подсвечники (8 кадров каждый) |
| `Lava_Flammenwerfer` | `3db/lavawelt.3db` | огнемёт |

**ФАКТ.** Чаши с огнём (`Dummy_Feuerkelch_a/b`) — это **не** `Feuerstelle`: у них нет
производства, нет мест, нет энергии; только частицы type-2 и своя геометрия.
То есть «огонь в игре» — это минимум три разных механизма: костёр (производство + свет +
частицы type 0), факел/чаша (только частицы type 2) и декоративные огни.

### 5.4 Учебник оригинала: первый урок — распаковать костёр

**ФАКТ.** Учебная карта — `data/GameScripts/oberwelt.tcl` + шаблоны `obw_tutorial`,
`obw_wettkampf`, `obw_szene`. Учебник управляется горячими клавишами
(`single_Tutorial.tcl`: F6→`s2010`, F7→`s2020`, F8→`sdig`, F9→`s2500`, F10→`s2015`,
F11→`s2022`, F12→`sdoor`).

**ФАКТ. Шаг `s2015` — «собрано1» (`oberwelt.tcl:42-61`)** — это и есть канонический разбор
механики распаковки:

```
set fire [obj_query $ref -class Feuerstelle -owner 0 -limit 1]
set_pos $fire {100 30.5 10}
set_boxed $fire 0            ;// снять признак «в ящике»
set_buildupstate $fire 1     ;// пометить «в процессе стройки»
set ps [obj_query $fire -class Pilzstamm -range 3 -limit 1]
if {!$ps} { new Pilzstamm "" [get_pos $fire] {0 0 0} }   ;// подкинуть материал
set g [obj_query $fire -class Zwerg -owner 0 -range 20 -limit 1]
if {$g} {set_attrib $g exp_Holz 0.02}                    ;// опыт за постройку
```

То есть за четыре строки исходника: **костёр выходит из ящика, помечается как строящийся,
рядом появляется нужный материал (грибной ствол), а гном-строитель получает опыт в дереве.**

**ФАКТ. Шаг `s2020` — «zeltunboxed» (`oberwelt.tcl:62-78`)** учит следующему: из инвентаря
гнома убирается предмет `Feuerstelle` (то есть гном принёс/вытащил костёр), костёр снова
ставится на место и распаковывается, и создаётся новая `Zelt`.

**ФАКТ.** В учебной карте `obw_wettkampf.tcl` есть постамент `Feuerstelle` на
(27.5, 66.48, 11.01). Флаг `set_boxed $objhandle false` проставлен у **всех** объектов шаблонов
(`urw_unq_vodo_*`, `obw_*`) — это стандартная практика размещения, а не признак
«костёр в ящике»: ящик получается только через `packtobox`.

**ФАКТ.** В учебной карте также: `sdig` создаёт и удаляет `Grillpilz` (проверка «гном поел»),
`s2500` отправляет гнома к `Trainingspuppe` и добавляет `exp_F_Kungfu 0.021`,
`sdoor` открывает дверь и включает копание (`set_owner_attrib 0 digenable0 1`).

## 6. Звук и графика оригинала

**ФАКТ (измерено).** `Sound/Produktion/Feuerstelle_1..8.wav` — восемь вариантов треска огня:
моно, 22050 Гц, 16 бит, длительность 0.311…0.320 с (6864…7056 кадров). Это короткие зацикливаемые
вставки, а не длинные лупы.

**ФАКТ.** Привязка в оригинале (`Scripts/init/soundinit.tcl:1019-1026`):
`sound anim feuerstelle.brennt 0 Feuerstelle_N any any 0.9 1.0 0 0` — все восемь привязаны
к **одной** анимации `feuerstelle.brennt` на кадре 0, то есть движок выбирает треск случайно
на каждом цикле горения (цикл = 3 кадра = 0.30 с). Отдельного непрерывного лупа огня в
`Sound/Produktion` нет.

**ФАКТ.** Прочие звуки огня и стройки (измерено, все 22050 Гц моно 16 бит):

| Файл | Длительность | Привязка |
| --- | --- | --- |
| `Sound/pusten_feuer.wav` | 1.147 с | `mann.pusten_feuer`, кадр 5 (`z_soundinit.tcl:825`) |
| `Sound/feuer_springen.wav` | 2.340 с | `mann.feuer_springen` (`:633`) |
| `Sound/haende_waerm.wav` | 1.369 с | `mann.haende_waermen`, кадр 12 (`:703`) |
| `Sound/aufbauen_stein.wav` | 0.257 с | `mann.aufbauen_*_stein` (`:563-566`) |
| `Sound/aufbauen_holz.wav` | 0.455 с | `mann.aufbauen_*_holz` (`:552-555`) |
| `Sound/aufbauen_met.wav` | 0.253 с | `mann.aufbauen_*_metall` (`:547-550`) |
| `Sound/werkel_holz.wav` / `_2` | 1.461 / 1.866 с | `mann.werkeln_boden_holz` — работа у костра |
| `Sound/werkel_stein.wav` / `_2` | 2.000 / 1.866 с | `mann.werkeln_boden_stein` — теска камня у костра |
| `Sound/kiste_ablegen.wav` | 0.724 с | `mann.kiste_ablegen_*` — постановка ящика |
| `Sound/g_kiste_{e,l,s}.wav` | 0.306 / 1.041 / 0.206 с | переноска ящика |

**ФАКТ.** Иконки и картинки (размеры прочитаны из заголовков TGA):
`Texture/ClassIcons/Feuerstelle.tga` и `Feuerstelle_u.tga` — 32×32; `Texture/ClassIcons/Aufbau.tga`,
`unpack.tga`, `packtobox.tga`, `Kisten_einlagern.tga` — 32×32; `GUI/icons/Feuerstelle.tga` — 40×40;
`GUI/icons/unpack.tga`, `packtobox.tga`, `Aufbau.tga` — 40×40; `GUI/icons/S_packtobox.tga` — 16×16;
`GUI/docpix/Info_Feuerstelle.tga` — 160×120 (76 844 байта).

**ФАКТ.** Отдельной «текстуры огня» в оригинале нет: в `data/Texture/` нет ни одного файла,
в имени которого есть `feuer` или `flam`, кроме иконок. Огонь — это частицы + точечный свет
+ UV-скролл по текстуре брёвна (см. §3.1). Атлас частиц `Texture/Misc/particle_a_128d.tga`
(128×128) уже перенесён в порт.

**ФАКТ. Из чего собрана геометрия костра.** У кадра `brennt` (mesh 310) в 3DB **шесть**
поверхностей, но геометрия есть только у трёх (проверено по `native_campaign_models.json`):

| Поверхность | Материал | Геометрия в порте | Роль |
| --- | --- | --- | --- |
| 0 | `Trollh_Boden_b_End_b_256` | 25 точек / 72 треугольника | щебень под костром |
| 1 | `Holz_Standard_d_256` | 175 / 339 | **брёвна — именно на этой поверхности живёт UV-скролл огня (наборы 110 ↔ 112)** |
| 2 | `Stein_Standard_a_256` | 344 / 372 | каменное кольцо |
| 3 | `Urwald_Pilz_a_256` | **0** | шляпка — реквизит для анимаций `pilz` / `pilzdreh` |
| 4-5 | `Character_Hamster_a_128` | **0** | хомячок — реквизит для `hamster` / `hamsterdreh` |

То есть список поверхностей кадра `brennt` перечисляет ещё и реквизиты других анимаций — они
появляются только в кадрах `pilz` (318) и `hamster` (327). При выгрузке остальных кадров
нужно брать геометрию из соответствующих mesh, а не из 310.

**ФАКТ (репозиторий).** Звук костра в порту описан как `E02` в `docs/research/Diggles_audio_spec.md:85`:
«очаг имеет несколько вариантов/фаз», приоритет P0, «периодические варианты огня на активном очаге,
плавное затухание».

### 6.1 Частицы типа 0 (огонь костра) — полные правила из EXE

**ФАКТ.** Тип частицы выбирает обработчик через jump-table `0x00494250` (43 типа, `0…42`),
обработчик типа 0 — **`FUN_0049E760`** (`0x0049E760`), троник `0x00493EC0`. Все обработчики
получают масштаб **1.0** (`0x00737138`) — то есть **нет** подстройки под дельту кадра:
один проход обновления = один отрисованный кадр.

**ФАКТ. Появление частицы** (`FUN_0049E760:217-477`, адреса 0x49EA70…0x49F000). RNG —
тот же LCG `seed = seed*0x343fd + 0x269ec3; r = (seed>>16) & 0x7fff` (`FUN_00492190`):

| Параметр | Формула | Константа |
| --- | --- | --- |
| угол | `((r % 360)/180.0) * π` | π = `0x00737378` |
| радиус | `(r % 100)/350.0` | 350.0 = `0x00737490` |
| позиция | `x = T1(угол)*радиус + src.x`; `y = (r % 10)/200.0 + src.y`; `z = T2(угол)*радиус + src.z` | 200.0 = `0x00737644` |
| скорость | `vx = src.vx + ((r>>16 & 0xF)-8)/800.0`; `vy = src.vy - ((r % 10)/600.0 + 0.006)`; `vz` — как `vx` | 800.0 = `0x0073768C`, 600.0 = `0x00737688` |
| размер | **2.15** | `0x4009999A` |
| поворот | `(r & 0x7FFF)/5215.0` | 5215.0 = `0x007376A8` |
| ячейка атласа | `r & 3` → **строка 0, колонка 0…3**, больше **не меняется** | — |
| цвет | `diffuse = 0xFFFFFFFF`, `secondary = 0` | — |

**ФАКТ. Обновление частицы:**

```
pos += vel
pos.x = (src.x*8 + pos.x*92)/100      // притяжение к источнику
pos.z = (pos.z*92 + src.z*8)/100      // по y не притягивается
rot  += 0.2
vel  += src.drift * 0.1
если age < 16:  vel.y += ((r & 0x7FFF) + 32768.0) * (-0.0008) * 1.52587890625e-05
цвет (age ДО инкремента):
    w = min(|pos.x - src.x|, 0.1);  w = (0.1 - w) * 8.0
    k = clamp(16 - age, 0, 5);  m = round(k * w)
    secondary = clamp(-20*m) в R и G, clamp(30*m) в B
    f = clamp((age - 16.0) * 0.0625, 0, 1)
    diffuse = round((255-20*m)*(1-f)) в R и G, round((1-f)*255) в B
age += 1
если age >= 32 — частица умирает
```

**ФАКТ. Дрейф источника** (раз за тик, три шага LCG): `drift.x = (drift.x + ((r>>16 & 0xF)-8)/8200.0)*0.9`,
`drift.y` — делитель 9500.0 (`0x007376C0`), `drift.z` — как `x`.

**ФАКТ. Тип 19 (пыль)** — обработчик `FUN_004B1480`: дрейф `/6200.0`, по y `/5500.0`, затухание
**0.98**; рождений за тик `P-1 + (r & 0x7FFF) % 3`; размер `(r & 0x7FFF)/16847.0 * 1.8`;
возраст при рождении `(r & 7) + (r % 12)`; ячейка `(r % 3) + 0x10000` → **строка 1, колонки 0…2**
атласа `particle_e_256.tga` (сетка 4×4, ячейки 64 px); после возраста 49 частица оседает
(`pos.y += 0.005`) или скользит по вторичной скорости, если `src.y - pos.y <= 0.5`; умирает при
возрасте 128.

**ФАКТ. Тип 26 (щепки)** — обработчик `FUN_004B6440`: рождается ровно в точке источника,
разлетается баллистическим конусом (`((r&0xF)-8)/80.0` по X, `/87.0` с поправкой на `sqrt(1-10·x)`
по Z, `((r&0xF)-8)/85.0` по Y), размер `(r % 10)/25.0 + 0.8`, возраст при рождении `r & 0x1F`,
ячейка **`0x60000 + (r % 6)`** → строка 6, колонки 0…5 атласа `particle_b_128d.tga`
(сетка 8×8, ячейки 16 px); дальше — баллистика с **столкновением с рельефом** (`CMap` /
`CHeightBlockArray`).

**ФАКТ. Пул частиц.** `FUN_00492F80` выдаёт слот из LIFO-списка свободных, причём
`free[count-1]` — то есть слоты выдаются **по убыванию** (`pool, pool-1, …`), а освобождённый
слот становится следующим используемым. В `FUN_00495940:17` общее число слотов = `pool + 1`,
а выделение требует `free_count ≥ 2` → **один слот зарезервирован, полезных ровно `pool`**.
*Поправка к порту:* `native_flame.json` моделирует 32 слота / 1 зарезервирован / 31 полезный —
на единицу меньше, чем в движке (там 32 полезных при Tcl-пуле 32).

**ФАКТ. Когда происходит обновление.** `FUN_00498590` вызывается **только** из
`CDisplay::DrawObjects` (`0x00473CC0:756-785`), то есть частицы обновляются **один раз на
отрисованный кадр**, а не на игровой тик 10 Гц. Значит «32 тика» = **32 отрисованных кадра**.

**ФАКТ. Ворота (gates).** Перед обновлением проверяются: три глобальных переключателя
(`DAT_0077241C+0x29`, `DAT_0076A32A`, `DAT_00768379`); тип источника < 43; видимость источника
во frustum (иначе частицы источника освобождаются); для типов 1 и 15 источник принудительно
невидим; флаг «особый рендер» `source+0x6E` — он выставляется типам
**{0, 2, 3, 9, 11, 12, 27, 28, 29, 30}**, когда объект виден по туману, и для них обычный путь
рождения **не выполняется**; состояние источника `source+0x5C` (2 — освободить, 3 → 2,
5 → 0, 6 — одноразовое рождение).

**ФАКТ. Структуры.** Источник — запись **0x88 байт**: `+0x08` тип, `+0x0C…+0x14` базовая позиция,
`+0x18…+0x20` скорость, `+0x24…+0x2C` дрейф, `+0x4C` всего слотов, `+0x50` рождений за тик,
`+0x54` массив частиц, `+0x5C` состояние, `+0x60` предел расстояния, `+0x64` флаг,
`+0x68` дедлайн, `+0x6D` видимость, `+0x70` привязанный объект, `+0x74` связанный объект.
Частица — запись **0x44 байт**: позиция, скорость, `+0x28` размер, `+0x2C` возраст
(−10000 = мертва), `+0x30` поворот, `+0x34` diffuse, `+0x38` secondary, `+0x3C` ячейка атласа
(`row<<16 | column`), `+0x40` флаг.

**НЕИЗВЕСТНО (мелочи).** (1) `T1` (`0x6F6AD0`) и `T2` (`0x6F5AE0`) — это CRT-синус и косинус, но
какой из них какой, не доказано; на распределение (равномерный диск) это не влияет, но для
побитового совпадения проверить надо. (2) Не найдено, кто именно обновляет `source+0x0C…+0x14`
при движении объекта — практическое правило для порта: **мировая позиция эмиттера = позиция
объекта + смещение**. (3) Не прослежено, кто читает `link id` (argv[9]); у костра и пыль, и
щепки передают `2`.

## 7. Готовность порта

**ФАКТ (по коду порта).** Костёр в порте сейчас — это **статическая сетка на карте** плюс
навигационное препятствие. Ни производства, ни стройки, ни огня, ни звука у него нет.

| Подсистема | Файл в порте | Состояние |
| --- | --- | --- |
| Сетка костра | `godot/models/native_campaign_models.json` → `produktionsstaetten.3db::feuerstelle` | **ЕСТЬ**, 6 поверхностей, геометрия только у 3 (`Holz_Standard_d_256` — деревянная конструкция, `Stein_Standard_a_256` — каменное кольцо, `Trollh_Boden_b_End_b_256` — щебень); анимация `brennt`, mesh_index 310 |
| Расстановка на карте | `godot/scripts/native_campaign_first_level.gd`, `godot/models/native_campaign_model_manifest.json:5093-5116` | **ЕСТЬ**: три постамента `Feuerstelle` (шаблоны `urw_unq_vodo_001_a/_004_a/_007_a` — «вудуистические» костры), `boxed false` |
| Препятствие навигации | `godot/scripts/multiplayer_test.gd:1252-1253` | **АДАПТЕР**: радиус 0.75 (в оригинале footprint не документирован) |
| Декаль пола | `godot/scripts/multiplayer_test.gd:939-941` | **АДАПТЕР**: `+0.0075` по Y, чтобы декаль не совпадала с полом |
| Свет костра | `godot/models/native_campaign_lights.json` | **НЕТ записи** `Feuerstelle` — и это **не ошибка выгрузки**, а следствие архитектуры: статическая карта света порта собирается только из объявлений `class_light {offset} range {colour}` (28 классов, 122 источника), а костёр задаёт свет **на объекте** — `change_light this {0 -0.1 0} 4 "1 0.9 0.7"` в `init` (`feuerstelle.tcl:279`). Значит свет костра нельзя «добавить в карту» — его должен создавать сам объект костра в рантайме. Движок: `CTclObjMethods::ChangeLight` @ `0x00614990`, `SetLight` @ `0x006884F0`, `GetLight` @ `0x00688780` |
| Огонь | `godot/models/native_flame.json` → `classes` | **НЕТ `Feuerstelle`**: есть `Misc_Light`, `Dummy_Feuerkelch_a/b`. Тип частиц костра — **0**, а эмиттер жёстко отвергает `type != 2` (`native_flame_emitter.gd:44`). **Но эмиттер почти готов:** у источника огня костра `lifetime = 32` и **1 рождение за кадр** — ровно как у type-2; различаются **атлас** (`particle_e_256.tga` против `particle_a_128d.tga`), **сетка** (4×4 против 16×16), **размер** (2.15 против 1.15), радиус разброса (350 против 850) и порог «пинка» (age < 16 против age < 6) — полные формулы в §6.1 |
| Частицы пыли и щепок | — | **НЕТ**: типы 19 и 26 не реализованы ни в каком виде. У костра: пыль — lifetime 32, 2 рождения за кадр, атлас `particle_e_256.tga` строка 1; щепки — lifetime 64, 1 рождение, атлас `particle_b_128d.tga` строка 6, с отскоком от рельефа (§6.1) |
| Контракт обновления частиц | `godot/scripts/native_flame_emitter.gd:122` | **Совпадает с оригиналом**: `update_native_tick` — один проход на кадр, без дельты. Оригинал обновляет частицы из `CDisplay::DrawObjects`, т.е. **на отрисованный кадр**, а не на игровой тик 10 Гц — «32 тика» = 32 кадра |
| Пул частиц | `godot/models/native_flame.json` → `emitter.pool_slots` / `reserved_slots` | **РАСХОЖДЕНИЕ на единицу**: движок даёт `total = pool + 1` при одном зарезервированном слоте → полезных ровно `pool` (32 при Tcl-пуле 32), порт моделирует 32 слота / 1 резерв / 31 полезный |
| Анимации машины | `native_campaign_models.json`, `demo_start_models.json` | **Только `brennt`**, одним кадром (mesh 310). Машины `feuerstelle.pilz`, `.pilzdreh`, `.hamster`, `.hamsterdreh` не выгружены; также **нет** кадров 1-2 `brennt` (311, 312), `standard` (307-309), `bau_a`…`bau_d` (313-316) и **UV-набора 112** (сдвиг 3/16) |
| Анимации гнома | `godot/models/native_animation_aliases.json` (926 алиасов, 20 анимасетов, 884 цели) | **ЕСТЬ, ВСЕ**: `workatfire` → `mann.werkeln_feuer` (17), `fire` → `mann.pusten_feuer` (15), `windstart`/`windloop`/`windend` → `mann.kurbeln_*` (3/8/4), `hungry` → `mann.hungrig` (15), `benda` → `mann.buecken_a` (6), `bendb` → `mann.buecken_b` (2), `put`/`puta`/`putb` → `mann.ablegen*` (11/6/5), `takeboxa`/`takeboxb` → `mann.kiste_nehmen_*` (3/2), `tired` → `mann.erschoepft` (15), `scratchhead` → `mann.kopf_kratzen` (17), `dontknow` → `mann.weissnich` (17), `workfloorholz`/`workfloorstein` → `mann.werkeln_boden_*` (21/21), строй-алиасы `unten_rechtsstein`/`unten_rechtsholz`/`unten_linksholz` → `mann.aufbauen_*` (по 7). **Проверено скриптом:** все 18 клипов, которые использует рецепт костра (`feuerstelle.tcl`), присутствуют — пропусков нет |
| Звук | `godot/audio/` | **ПУСТО**: 0 из 1194 WAV оригинала перенесено. Нужны как минимум `Feuerstelle_1..8.wav` (привязаны к `feuerstelle.brennt`, кадр 0 — случайный треск), `aufbauen_holz/met/stein.wav`, `pusten_feuer.wav`, `kiste_ablegen.wav`, `werkel_holz/stein.wav` |
| Реквизит ящиков | — | **НЕТ**: `transport.3db::kiste` (закрытый), `kiste_tragen` (в руках), `halbzeuge.3db::kiste_offen` (открытый) — исходный вид «распаковки» |
| Производство | `godot/scripts/native_dwarf_work_states.gd:64-97` | **Только строки**: команда `prod_autobuild Feuerstelle <workplace>` формируется, но обработчика `prod_*` нет — `native_task_eval.gd:214` возвращает `Unsupported task command`, а `native_actor_tasks.gd:17` залипает на `last_error` |
| Инвентарь предметов | — | **НЕТ**: `native_item_inventory*.gd` не существует |
| Распаковка | `godot/scripts/native_dwarf_work_states.gd:47` | **Смоделирована на уровне типов**: `UNPACKED_ITEM_TYPES = ["production","elevator","energy","store","protection"]` — точный аналог `BOXED_CLASSES` из оригинала |
| Строительство | — | **НЕТ**: ни призрака, ни счётчика шагов, ни молота; поиск `ghost\|buildupstep\|build_dummys\|buidup\|check_ghost` по `godot/**/*.gd` даёт ноль совпадений |
| Места у костра | `godot/scripts/native_dwarf_place_registry.gd` | **Механизм ЕСТЬ, костёр не подключён**: в реестре есть таблица мест (`register_place` → `seats`), `free_seat` (первый свободный индекс), `claim`/`release`, но вызовов `register_place` в игровом коде нет — только в self-тесте (`native_dwarf_place_registry_self_test.gd:43,66`). **Оракул совпадает с оригиналом:** `prod_guest guestfree` → `guestset` → `resetorder`, а при выборе случайного места — `call_method <место> get_random_seat` — это в точности контракт оригинального `sparetime_check_in` (`z_spare_procs.tcl:882-917`). **Расхождение с оригиналом:** у костра 3 рабочих места + **5** мест ожидания (всего 8 слотов), а не «3 + 8» |
| Реестр заданий (планировщик) | — | **НЕТ**: в порте нет ни списка станций клана, ни свободных гномов, ни матрицы оценок «гном ↔ станция», ни таблицы назначений. В оригинале это `CProdPlanner` (`0x00433A70`), по одному планировщику на клан (8 кланов, тик по кругу) |
| Очередь производства | — | **НЕТ**: счётчики заказов (`SITE+0x0C`, запись 0x1C байт) не смоделированы. В оригинале квота 0…10 на изделие, **обрезается** движком, пишется AI, а читается как предохранитель в `prod_getitemtask` |
| События `evt_autoprod_*` | — | **НЕТ**: движок в оригинале отдаёт гному команду `evt_autoprod_workat -target <станция> -text1 <изделие или Bp<изделие>>` (`0x00721848`), а Tcl-обработчик (`z_events.tcl:1127`) ставит `current_workplace` / `current_workclass` и будит `work_auto`. В порте `work_auto` формирует строку `prod_autobuild …`, но обработчика `prod_*` нет — это **разрыв именно на этом стыке** |
| Еда у костра | `godot/models/native_dwarf_sparetime.json` | **Частично**: `stt_eatciv_Feuerstelle` = 0.1, `stt_eatgain_Grillpilz` = 0.19, `stt_eatgain_Grillhamster` = 0.24 — константы есть, поиск места еды не привязан к костру |
| Сюжетная зацепка | `Scripts/classes/story/Trigger_Urwald.tcl:211,234` | **В оригинале**: `set_prod_slot_cnt $fs Grillpilz 10` — «вудуистический костёр» заказывает 10 Жаррибов |
| Сюжетный старт | `Scripts/sequences/Urwald/urw_3.tcl:204-210` | **В оригинале**: гном ставит ящик, вызывается `Feuerstelle`, ему сразу делают `packtobox` — **первый уровень начинается именно с распаковки костра** |

**ФАКТ.** Главная сцена `campaign_first_level.tscn` вообще не создаёт эмиттеров пламени:
поиск `flame` по `godot/scripts/` даёт попадания только в `multiplayer_test.gd` и
`native_flame_emitter.gd`. То есть система пламени type-2 работает только в мультиплеерной сцене.

## 8. Что уже записано в документации проекта

**ФАКТ.** Проектные документы знают про костёр меньше, чем показывает оригинал, но знают верно:

| Утверждение | Статус в проекте | Источник |
| --- | --- | --- |
| `Feuerstelle` — корень тех-дерева, стартовая станция кампании | В | `docs/research/diggles_technology_tree.md:24,29,474` |
| Рецепты костра: Grillpilz ×2, Grillhamster ×2, Zelt, Hauklotz, Steinmetz, Feuerstelle | В* | `diggles_technology_tree.md:95-100` |
| Энергетика костра = 0 (работает без энергии) | С | `diggles_technology_tree.md:389` |
| `preinv_Feuerstelle = Grillpilz, Zelt, Feuerstelle` | В | `diggles_technology_tree.md:389` |
| Кухни суперсидируют костёр: Mittelalter → Industrie → Luxus, требуют энергию | С/В | `diggles_technology_tree.md:75-77,299-301` |
| Пороги изобретений: Log = Wood 1, Stonemason = Stones 3 | С | `diggles_economy_research.md:152-153` |
| Цикл строительства B01–B09 (изобретение → заказ → ящик → размещение → сборка гномом) | ✅ В / ⚪ Н по B09 | `diggles_economy_research.md:183-195` |
| Модель состояния здания: `packed / waiting_placement / placed_pending / assembling / operational / packing` | ПРОЕКТ | `diggles_economy_research.md:240` |
| Звук костра: 8 файлов `Produktion/Feuerstelle_1..8.wav`, P0 | В/С | `docs/research/Diggles_audio_spec.md:85` |
| Частота кадров оригинала 10 игровых кадров/сек (`0x007373F0`) | ФАКТ | `docs/PROJECT_GUIDE.md:312`, `docs/plan/queue-2026-11-19.md:1029` |
| Частицы type2 у `Feuerstelle` автоматически не назначены | ФАКТ | `work/campaign/docs/reverse-engineering/native-flame-2026-11-18.md:32` |
| Правило проекта: ФАКТ / АДАПТЕР / НЕИЗВЕСТНО, в коде `## SOURCE:` / `## ADAPTER:` | Правило | `docs/PROJECT_GUIDE.md:21,279-281` |

**ФАКТ.** До 25.11 в очереди работ (`docs/plan/queue-2026-11-19.md`) **не было ни одного пункта**
про сам костёр, про производственную станцию как объект, ящики/упаковку, распаковку и сборку
зданий. Ближайшее — шаг C «Экономика и фермы» (производственные слоты, состояние «частично») и
M8 (`prod_anim`, 253 вызова в оригинальном Tcl). **Пункт добавлен:** M9 «Костёр `Feuerstelle` как
производственная станция» — строка в §2 очереди, карточка в §3, белые пятна №10-13 в §4.

## 9. Пробелы и НЕИЗВЕСТНО

### 9.1 Что удалось закрыть сверх документов

| Вопрос, помеченный в документах как открытый | Ответ из оригинала |
| --- | --- |
| «Точная функция `tttinfluence_*` неизвестна» (`diggles_technology_tree.md:360`) | Восстановлена: `prod_getgnomeexper` (`genericprod.tcl:746-762`) — среднее по требуемым навыкам × `0.7` + настроение × `0.3` |
| «Пороги изобретений» (С, из wiki) | `tttinvent_*` в оригинале: `Grillhamster` = `exp_Nahrung 0.039`, `Hauklotz` = `exp_Holz 0.008`, `Steinmetz` = `exp_Stein 0.026`; остальные пусты. Целочисленные «Na: 4 / Ho: 1 / St: 3» — это округление UI |
| «Время производства не задано» | Время = число повторов анимации × 0.1 игровой секунды (10 fps). Для огня: `workatfire` 1…3 повтора, `windloop` 3…9, `workfloorholz/stein` 1…4 — множитель от опыта гнома |
| «Костёр не имеет анимации работы» | `feuerstelle.tcl:90,139` — `workatfire`; машина: `feuerstelle.pilz/.pilzdreh/.hamster/.hamsterdreh/.brennt` |
| «Не описан footprint» | Footprint в оригинале — привязки модели `build_dummys {16 16 17}` и `damage_dummys` (у кухонь), а не радиус; портовые 0.75 — АДАПТЕР |
| «Четвёртое поле `def_class` — цена или ценность?» | **Эпоха тех-дерева** (`classrec+0x60`, `get_class_era` `0x00640140`), диапазон 0…8; корреляция «еда ⇒ эпоха» оказалась ложной (§2.4) |
| «Вес предметов — где таблица?» | Таблицы нет: вес — атрибут объекта с глобальным умолчанием 0, каждый класс переопределяет его у себя в `obj_init` (`set_attrib this weight …`) |
| «Вторичный расход материалов при распаковке» (B09) | **Вторичного расхода нет**: материалы съедаются один раз при изготовлении ящика; распаковка лишь убирает ящик из инвентаря гнома (§4.2) |
| «Когда у костра появляется свет» | Только после распаковки: упакованный объект **не инициализируется** — `evt_timer_init` вызывает `init` лишь при `get_boxed this == 0`; `set_boxed` управляет битом `0x40000` слова флагов `obj+0x3D0` |
| «Почему кухням нужен энергоисточник, а костру нет» | Правило движка — **расход**: `consumption > 0` ⇒ нужен источник того же класса в радиусе источника; `consumption ≤ 0` ⇒ источник не нужен. У костра класс 0 и расход 0 (`techtreetunes.tcl:34-36`), у кухонь 1/10, 2/20, 3/20 |
| «Что такое три состояния объекта на самом деле» | Три **независимых** бита: `boxed` = `0x40000`, `build` = `0x400000` (слово `obj+0x3D0`), плюс флаги запросов в записи производства `CProd+0x28` (распаковка) и `+0x29` (упаковка) (§4.1) |
| «Какие типы частиц у костра» | Типы — идентификаторы движка: `change_particlesource <объект> <слот> <ТИП> …`, то есть argv[3] — тип (0 огонь, 19 пыль, 26 щепки), argv[2] — номер слота источника (0…31, слот хранится в `obj+0x2B0`) |
| «Какая текстура у огня костра» | **Тип 0 → `particle_e_256.tga`, сетка 4×4** (таблица рендера `FUN_00495F60`); тип 2 → `particle_a_128d.tga` 16×16; тип 19 → `particle_e_256.tga` 4×4; тип 26 → `particle_b_128d.tga` 8×8. Полные правила спавна и обновления типа 0 — §6.1 |
| «Когда обновляются частицы» | **Один проход на отрисованный кадр** (`FUN_00498590` вызывается только из `CDisplay::DrawObjects`), без дельты времени: «32 тика» = 32 кадра, а не 32 игровых тика по 0.1 с |
| «Приоритеты выбора работника и порядок очереди рецептов» (`docs/plan/queue-2026-11-19.md`, P0-неизвестное) | Разделено на две части (§2.7): **очередь** — это квота 0…10 на изделие, пишет AI (`std_ai.tcl:2202`), читает `prod_getitemtask` как предохранитель, обнуляется всё сразу; **приоритет** — float-оценка пары «гном ↔ станция» в C++ (`rating > 0`), а «сначала еда» задано в Tcl-AI (`std_ai.tcl:1941-1981`: `Pilz Hamster Raupe` проверяются первыми) |
| «Как гном понимает, что делать» | Точка стыка найдена: движок шлёт `evt_autoprod_workat -target <станция> -text1 <изделие>` (`0x00721848`), Tcl-обработчик `evt_autoprod_workat_proc` (`z_events.tcl:1127`) ставит `current_workplace` / `current_workclass` и вызывает `work_auto` |
| «Сколько мест у костра» | 3 рабочих места + **5** мест ожидания (8 гостевых слотов): `prod_guest addlink` × 8, `prod_guest_seats 3`, `prod_guest_waits 8`; `ask_for_seat` возвращает 1 только если индекс первого свободного слота < 3 |
| «Что гном реально делает у костра» | Полная хореография рецептов — §2.6: раздувание огня (`prod_blowright` + `prod_anim fire`), надевание шляпки на вертел (`feuerstelle.pilz` → `pilzdreh`), вращение (`windstart`/`windloop`/`windend`), рубка ножки/камня (`workfloorholz`/`workfloorstein`) со случайной неудачей (`scratchhead` + `dontknow`), и упаковка построек в ящик |
| «Куда девается счётчик заказа» | Он **не уменьшается**: движок обрезает его в 0…10 (`0x005EDA20`), а списание делает Tcl через `prod_finishitem` → `finish_itemprod` → `stop_production` |

### 9.2 Что осталось НЕИЗВЕСТНО

| Вопрос | Почему не закрыт | Что делать |
| --- | --- | --- |
| Правила частиц **типа 0** (огонь костра), 19 (пыль), 26 (щепки) | В порту восстановлен только type-2 (факел/чаша); type-0 правил нет | Разобрать EXE по образцу type-2 или взять из `native_flame.json` только type-2 и написать type-0 отдельно. **Что уже решено:** параметры источника (lifetime 32, 1 рождение за тик, смещение `{0 -0.1 0}`) совпадают с type-2, отличается только идентификатор типа и текстура; атлас-кандидат — `particle_b_128d.tga` (§1) |
| Соответствие «тип частицы → атлас» в движке | **ЗАКРЫТО** (§1, §6.1): таблица рендера `FUN_00495F60` (`0x00495F60`) — тип 0 → `particle_e_256.tga` (сетка 4×4), тип 2 → `particle_a_128d.tga` (16×16), тип 19 → `particle_e_256.tga` (4×4), тип 26 → `particle_b_128d.tga` (8×8) | — |
| Какой из CRT-функций синус, а какой косинус, в рождении частиц типа 0 | `T1` = `0x6F6AD0` (x), `T2` = `0x6F5AE0` (z) — обе CRT-тригонометрия, но кто есть кто не доказано | Сверить хвосты полиномов `0x6F6C07…` и `0x6F5F80…`, либо с golden-спавном type-2 в `native_flame_self_test.gd` |
| Обновление типа 26 (щепки) до конца | Обработчик `FUN_004B6440` — это ~650 строк декомпиляции с баллистикой и **столкновением с рельефом** (`CMap`/`CHeightBlockArray`); прочитан только спавн | Дочитать `0x4B6B7B…` и найти коллизию с `CHeightBlockArray` |
| Механизм обновления позиции источника при движении объекта | `FUN_00495940` пишет позицию один раз; дальше смещение идёт через очередь команд (`FUN_005B4E90:217-250`, тип 8) | Для порта достаточно правила «позиция эмиттера = позиция объекта + смещение» (§6.1) |
| Историческая частота кадров частиц и visibility/pause gates | `native-flame-2026-11-18.md:28` | Обратный анализ EXE |
| Точный размер зданий и правила допуска места | В оригинале — геометрия модели и `check_ghost_coll`; в Tcl нет чисел | Считать из 3DB-поверхностей + проверка коллизий в движке |
| Радиусы видимости ресурсов и граница «известности» | Документы: P0-неизвестное | Проверка в оригинальной игре (нужен запуск оригинала) |
| Приоритеты выбора работника и порядок очереди рецептов | Частично закрыто (§2.7): очередь-квота и место приоритета в Tcl понятны | Осталось: **веса оценки** пары «гном ↔ станция» — `FUN_00439DA0` (`0x00439DA0`) и хвост `FUN_00437BB0` (`0x00437BB0`), оба без `.c` в выгрузке, читать дизассемблированием |
| Вторичный расход материалов при распаковке | B09 — ⚪ Н | Только наблюдением в оригинале |
| Звук производственного цикла станции | Для `Feuerstelle` есть только 8 файлов огня; отдельного цикла нет | Проверить список `Sound/Produktion` |
| Значение полей `extra.u16` / `extra.f32` в 3DB | Не совпадает с индексом анимации; в `trollhausen.3db` `extra.f32` — мусор | Не полагаться на них; работать по индексу анимации |
| Значения типов классов 7, 8, 9 (`protection`, `store` и ещё один) | `FUN_005FFFE0` декодирован только до значения 6; строки для 7-9 не разобраны | Дочитать `FUN_005FFFE0` с `0x00600126` — там сравнения строк |
| Точное правило «источник энергии нужного класса в радиусе» | `FUN_005B93D0` (`0x005B93D0`) не декомпилирован, но сам факт потребления известен: **`consumption > 0` ⇒ нужен источник**, `consumption ≤ 0` ⇒ не нужен | Дизассемблировать `FUN_005B93D0`: сравнение `registry[i].energyClass` и `registry[i].range` |
| Кто пишет `CProd+0x2A` (`get_prod_buildup`) в 1 | Ни одна Tcl-команда и ни `ai_setbuildup`, ни `ai_setpack` это не делают | Искать запись `1` в `byte [CProd+0x2a]` среди безымянных функций |
| Немецкая локализация | В этой сборке `Scripts/text/doc/` содержит **только** `ru/` — русский патч заменил немецкий текст на месте | Искать немецкие строки в `Diggles.exe` либо в других сборках |
| Смысл параметра `n` в `sound anim <объект>.<клип> <n> <звук>` | В репозитории нет разбора этой команды; `n = 0` у всех восьми тресков | Построчно разобрать команду в EXE |
| Габариты и `convex` | `convex` — коллизионный халл (материал `Checker`), невидимый; радиус 0.75 в порту — адаптер | Взять халл из 3DB (меши 336-337) вместо подбора |

### 9.3 Противоречия, которые нельзя разрешать угадыванием

- **Материалы костра**: комментарий `techtreetunes.tcl:23` говорит «один ствол и один камень»,
  список `tttmaterial_Feuerstelle` содержит 2 + 2. Доверять списку (так же и
  `diggles_technology_tree.md:422`).
- **Размер партии**: `Grillpilz` ×2 на костре и ×3 на кухнях — это разные рецепты с одинаковым
  типом выхода (`diggles_technology_tree.md:95,307,316,499`).
- **`Grenzstein`**: лесопилка или мастерская каменщика — расхождение источников
  (`diggles_economy_research.md:146`, `:297`).
- **Четвёртое поле `def_class`**: вики и старые заметки читают его как «цену» или «уровень
  пищевой ценности». Разбор EXE показал, что это **эпоха тех-дерева** (`classrec+0x60`), а
  совпадение с пищевыми уровнями — случайность: блюда разблокированы в эпохах 0/1/2.
  Разрешено в пользу EXE: §2.4.

## 10. Предлагаемый блок работ

Порт не имеет **никакой** производственной машинерии: команда `prod_*` существует только строкой,
инвентаря нет, стройки нет, нет даже реестра станций и очереди заказов. Поэтому костёр нельзя
делать «одним объектом» — он первый носитель всей семейки `prod_*`. Работу стоит разбить на
**четыре блока по зависимости**: A (костёр как объект) → B (стройка и распаковка) →
**D (реестр заданий и планировщик — хребет)** → C (производство, инвентарь и хореография рецептов).

Порядок неочевиден и важен: блок C без D бессмыслен (кто закажет и кто выполнит?), а D без C
пуст (нечего планировать). Первым по коду писать D, первым по результату — C.

### Блок A — костёр как объект: данные, огонь, свет, анимация

| # | Действие | Файл |
| --- | --- | --- |
| A1 | Создать `godot/models/native_campfire.json` (schema `diggles.native_campfire.v1`): класс, категория `wood` (enum 7), тип `production` (enum 5), **эпоха 0** (`classrec+0x60`), дистанция боя 1.5, дефолтная анимация, флаг `-1 -1`, свет `{0,-0.1,0}/4/[1,0.9,0.7]`, три источника частиц (тип 0 / 19 / 26, lifetime 32/32/64, рождений 1/2/1), **3 рабочих места + 5 мест ожидания (8 гостевых слотов)**, `build_dummys {16,16,17}`, `max_buildup_step 3`, `buidup_anis`, рецепты с порогами изобретений, блок `limits`. **Флаги объекта** (слово `obj+0x3D0`): `boxed` = `0x40000`, `build` = `0x400000`, `locked` = `0x4`. **Энергия:** класс 0, расход 0 — источник не нужен (правило движка: источник нужен только при `consumption > 0`) | новый |
| A2 | Выгрузить из `produktionsstaetten.3db::feuerstelle` меши **311, 312** (кадры 1-2 `brennt`), **307-309** (`standard`), **313-316** (`bau_a`…`bau_d`), **336-337** (`convex`) и **UV-набор 112** (сдвиг 3/16) — без UV 112 огонь не мерцает. Опционально 317 (`zerstoert`), 318, 319-326, 327, 328-335 (`pilz`/`pilzdreh`/`hamster`/`hamsterdreh`). **Инструмент уже есть:** `tools/inspect_3db.py <3db> --object feuerstelle --frame N --output <obj> --texture-root <dir> --summary` (проверено: пакет читается, объект и кадры видны) | новый `godot/models/native_campfire_visual.json` |
| A2a | Реализовать пламя как 2-состоянийный UV-скролл (наборы 110↔112) на 10 fps, а не как анимацию геометрии | `native_campfire.gd` / шейдер |
| A2b | Перенести звук: `Feuerstelle_1..8.wav` (случайный треск на кадре 0 `brennt`), `aufbauen_holz/stein.wav`, `pusten_feuer.wav`, `kiste_ablegen.wav`, `werkel_holz/stein.wav` | `godot/audio/` (сейчас пусто) |
| A3 | **Огонь типа 0 — по готовой спецификации §6.1.** Завести `godot/models/native_campfire_fire.json` (schema `diggles.native_flame.v1`, тот же, что у `native_flame.json`): `type 0`, атлас `Texture/Misc/particle_e_256.tga` (импорт **с переворотом по вертикали**, как уже сделан `particle_a_128d.png`), сетка **4×4**, ячейки `[0,0,64,64]…[192,0,64,64]`, `size 2.15`, `lifetime_ticks 32` (= 32 **отрисованных кадров**), `births_per_tick 1`, `pool_slots 32` (полезных 32, резерв 1), `column = rand & 3` фиксируется при рождении и **не анимируется**. Формулы спавна и обновления — §6.1 дословно. **Не сломать type-2:** его правила подтверждены этой же выгрузкой (размер 1.15, радиус 850, `vy`-смещение 0.008, формула колонки `trunc((31-trunc(age²/32))/4)`, атлас `particle_a_128d.tga`, сетка 16) | `native_flame_emitter.gd` (+ новый `native_campfire_fire.json`) |
| A3a | Поправить расхождение пула: в движке полезных слотов ровно `pool`, а `pool_slots - reserved_slots` даёт на единицу меньше — или задокументировать как известное отклонение | `native_flame.json`, `native_flame_emitter.gd` |
| A3b | Пыль (тип 19) и щепки (тип 26) по §6.1; для щепок нужна коллизия с рельефом — либо ограничиться падением по `pos.y` (в оригинале — `CHeightBlockArray`) | `native_flame_emitter.gd` |
| A4 | Добавить `Feuerstelle` в список классов огня (`native_flame.json`). **Свет — не в карту света**, а в рантайм объекта: `native_campaign_lights.json` собирается только из `class_light`, а костёр объявляет свет через `change_light` в `init` — значит `OmniLight3D` создаёт сам объект костра: смещение `{0,-0.1,0}`, радиус 4, цвет `(1.0,0.9,0.7)`, вкл. при `init`, выкл. при `packtobox` | `native_flame.json`, `native_campfire.gd` |
| A5 | Объект костра: состояния, три источника частиц, свет, места, проигрывание `brennt` в цикле на 10 fps | новый `godot/scripts/native_campfire.gd` |
| A6 | Подключить костёр к главной сцене (сейчас эмиттеров пламени там нет) | `native_campaign_first_level.gd` — **осторожно, файл уже правит другая сессия** |

### Блок B — стройка и распаковка

| # | Действие | Файл |
| --- | --- | --- |
| B1 | Состояние стройки: `buildup_step` 0…3, `max_buildup_step`, `buidup_anis`, призрак, проверка коллизии, молот, разборка (`prod_builddown` → `packtobox`) | новый `native_build_site.gd` |
| B2 | Обработчики команд: `prod_autobuildup`, `prod_buildup`, `prod_buildup_rep`, `prod_builddown`, `prod_buildup_check`, `prod_builddown_rep`, `prod_progress`, `prod_repair*`, `prod_autounpack`, `prod_autopack`, `prod_autobuild` | новый `native_prod_commands.gd` + регистрация в `native_command_handlers.gd` |
| B3 | Тайминг стройки по оригиналу: повторы = `(1 - clamp(exper,0.1,0.8)) × (8 + шаги×0.7)`, разборка — половина | там же |
| B4 | Ящик как объект: `Halbzeug_kiste` с тремя видами (`offen`/`tragen`/`geschlossen`), упаковка здания и продукции | `native_item_inventory.gd` (см. блок C) |

### Блок C — производство и инвентарь

| # | Действие | Файл |
| --- | --- | --- |
| C1 | Инвентарь и предметы: `Pilzhut`, `Pilzstamm`, `Hamster`, `Stein`, `Halbzeug_holz`, `Halbzeug_stein`, `Halbzeug_kiste`, еда, здания | новый `native_item_inventory.gd` |
| C2 | Слоты производства: квота 0…10 на изделие (обрезание как в `SlotCountSet` `0x005EDA20`), `prod_items`, `prod_item_materials`, `prod_item_number2produce`, `prod_item_attribs` (пороги изобретений), `prod_preinvented` | новый `native_production.gd` |
| C3 | Сценарии производства костра **дословно по §2.6**: `prod_actions_Pilzhut` (ветка `Grillpilz` с раздуванием огня и вертелом), `prod_actions_Hamster` (ветка `Grillhamster`), `prod_actions_Pilzhut` (общая ветка), `prod_actions_Pilzstamm`, `prod_actions_Stein`, `prod_actions_default`; с вероятностью `1 − exp_infl` — неудача `scratchhead` + `dontknow` | там же |
| C4 | Действия гнома: `prod_anim`, `prod_anim_loop_expinfl` (нового в порте нет), `prod_machineanim`, `prod_goworkdummy`, `prod_turnright/front/back`, `prod_changetool`, `prod_blowright`, `prod_walk_and_consume_itemtype`, `prod_createproduct_*`, `prod_beam_itemtype_*`, `prod_walk_and_hide_itemtype`, `prod_call_method set_chips/set_dust` | там же |
| C5 | Опыт: `prod_getgnomeexper` (0.7·опыт + 0.3·настроение), `clan_exp_factor`, `multi_exp_factor` (1.0 в кампании / 2.0 в песочнице), `tttgain_*`, `tttinfluence_*`, `exp_Transport` за стройку | там же |
| C6 | Еда и досуг у костра: `sparetime_eatplaces {Feuerstelle}`, 7 классов еды, выбор места, места и очередь | `native_dwarf_sparetime.gd` + `native_dwarf_place_registry.gd` |
| C7 | **Клипы гнома дописывать не нужно:** проверено скриптом по `native_animation_aliases.json` — все 18 анимаций рецепта костра на месте (`benda` → `mann.buecken_a` (6), `bendb` (2), `workatfire` (17), `fire` (15), `windstart`/`windloop`/`windend` (3/8/4), `hungry` (15), `put`/`puta`/`putb` (11/6/5), `takeboxa`/`takeboxb` (3/2), `tired` (15), `scratchhead` (17), `dontknow` (17), `workfloorholz`/`workfloorstein` (21/21)). Ранее записанное «не хватает `banda`» — **ошибка чтения**: в оригинале тоже `benda` (`z_anims.tcl:272`), а `banda` не существует нигде | — (правок не требуется) |
| C8 | Класс станции в порту: `prod_items`, `prod_preinvented`, `prod_item_*`, `prod_guest` (места), `ask_for_seat` (индекс первого свободного слота < 3), `reserve_seat` (слоты 3…7) — по §2.5-2.6 | `native_production.gd` |

### Блок D — реестр заданий и планировщик

Это **хребет** системы: без него станция не знает, кто за ней стоит и что заказано, а гном не
знает, куда идти. Блоки B и C — наполнение этого хребта.

| # | Действие | Файл |
| --- | --- | --- |
| D1 | Минимальная модель станции (зеркало `SITE` = `CObj+0x3E0`): `owner_id`, `items`, `slot_count` (0…10 на изделие), `enabled`, `exclusive_mode`, `switch_mode`, `schedule`, `material_need`, `tool_need`, `direct_events`, `unpack`/`pack`/`buildup`, `owner_strength` (float), `current_worker`, `occupied`, `seats` | новый `native_prod_site.gd` |
| D2 | Модель гнома (зеркало `GNOME` = `CObj+0x3E4`): `work_state` (2 — производит, 20 — отпущен), `sub_state` (2 — свободен, 14 — ждёт), `idle_flag`, `last_workplace`, `preferred_workplace` | там же |
| D3 | Реестр по кланам: список станций, список свободных гномов, таблица спроса, таблица оценок «гном ↔ станция» (float, кандидат принимается только при `rating > 0`), таблица назначений | новый `native_job_registry.gd` |
| D4 | Тик планировщика по оригиналу: 1) собрать станции клана, 2) собрать свободных гномов (`sub_state == 2`, не заблокирован маской `0x800000`), 3) снять просроченные записи спроса, 4) построить матрицу оценок, 5) назначить гномов, обходя станции **с конца** | там же |
| D5 | Диспетчеризация: эмитить `evt_autoprod_workat` с `target` = станция, `text1` = изделие (или `Bp<изделие>` для изобретения) — и принять его в портовом `work_auto` как `current_workplace` / `current_workclass` / `current_worktask = "work"` | `native_dwarf_work_states.gd` + `native_job_registry.gd` |
| D6 | Квота заказов: писать её должен «директор» (в оригинале — `ai/std_ai.tcl`); для первой версии достаточно правила «для каждого изобретённого (`Bp<изделие> > 0`) изделия держать квоту 1, приоритет — еда (`Pilz Hamster Raupe`), затем постройки» | `native_job_registry.gd` |

### Тесты

По конвенции репозитория: файл `godot/tools/*self_test*.gd`, маркер
`checks=N failures=M`, golden-значения — в `godot/models/*.json` (schema, status, limits, evidence),
запуск — `python scripts/run_all_suites.py --project godot --out out/testlogs --only <имя>`.

| # | Суite | Что проверяет |
| --- | --- | --- |
| T1 | `native_campfire_self_test` | константы класса, свет, три источника частиц, места, конфигурация type-0 огня в пределах пула, цикл `brennt` на 10 fps |
| T2 | `native_campfire_buildup_self_test` | последовательность 0→3 с правильным алиасом на шаг, отказ при коллизии, сброс `prod_builddown` |
| T3 | `native_campfire_production_self_test` | порядок команд для `Grillpilz` и `Hamster` — побайтно, как в `feuerstelle.tcl:74-99` и `:124-148` |
| T4 | `native_campfire_recipes_self_test` | **число раздуваний огня** `i = 5` при `exp_infl < 0.1`, иначе `1 + int(0.5/exp_infl)`; число повторов `workatfire` 1…3 и `windloop` 3…9 по формуле `round((max−min)(1−exp_infl)+min)`; вероятность неудачи `1 − exp_infl` при рубке |
| T5 | `native_campfire_experience_self_test` | `prod_getgnomeexper`: вклад по каждому навыку, среднее, итог `0.7·опыт + 0.3·настроение`; `multi_exp_factor` = 1.0 в кампании и 2.0 вне её |
| T6 | `native_job_registry_self_test` | квота заказа обрезается в 0…10; гном не берётся на станцию при нулевой квоте; приоритет «еда → постройки»; назначение обходом станций с конца; `rating > 0` — единственное условие пригодности |
| T7 | `native_campfire_guest_self_test` | `guestfree` возвращает индекс первого свободного слота; `ask_for_seat` = 1 только при индексе < 3; `reserve_seat` занимает слоты 3…7; 8 гостевых слотов всего |

### Порядок и риски

1. Начать с **A1** — это чистые данные, они блокируют всё остальное и сами по себе проверяемы.
2. Затем **D** (реестр и планировщик) — это хребет: без него ни B, ни C не имеют смысла, но он
   проверяем сам по себе (квота, матрица оценок, диспетчеризация `evt_autoprod_workat`).
3. **C1/C2** — самая крупная часть: инвентаря в порте нет вообще, и без него производство не
   запустится. Хореографию рецептов (§2.6) переносить дословно — это уже готовая спецификация.
4. **A3** требует разбора EXE по типу 0 — это исследование, а не перенос; тип 2 можно оставить
   нетронутым, а огонь костра вести отдельным эмиттером `native_campfire_flame.gd`.
5. `native_campaign_first_level.gd`, `native_campaign_profile.gd`, `native_campaign_ground.gd` и
   шейдер рельефа уже изменяются другой сессией — правки A6 и A4 надо согласовать.
6. **Веса оценки «гном ↔ станция»** (`FUN_00439DA0`) восстановить не удалось — на первом этапе
   достаточно оценки «есть ли свободное место и есть ли изобретённое изделие с квотой»,
   а точные веса — отдельная задача на разбор дизассемблированием.

### Проверка

```powershell
python -B scripts/run_all_suites.py --project godot --out out/testlogs --only native_campfire_self_test
python -B scripts/run_all_suites.py --project godot --out out/testlogs
```
