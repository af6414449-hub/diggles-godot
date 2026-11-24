# Auto torch: horizon registry и light-begin cutoff, 2026-11-18

**Подтверждено:** registry predicate `0x4753F0` читает список, который заполняет Tcl **`horizon_set position r g b depth size`**, callback `0x642110` (`CTclGlobalMethods::HorizonSet`). Это данные локального horizon/fog-оформления, в частности от `Info_Fog_*`, а не доказанный FOW/LOS или список наблюдателей. Последний аргумент `size` действительно используется как радиус XY в этом predicate. Глобальный integer `[0x7683D8]` задаётся **`set_light_begin integer_y`**, callback `0x64B620` (`SetLightBegin`), через setter `0x590620`. Это отдельный порог Y; horizon_set его не пишет.

Для чистого authored_2p host context доказан исходный cutoff **−10000**. Из принятых authored-пресетов приходят две конкретные записи `Info_Fog_Urw_c`, описанные ниже. Для локальной сцены start_010_a_0 доказана её собственная запись, size=30; это позволяет feed runtime без назначения гномам/столбам выдуманных радиусов. Полный список конкретного оригинального запуска остаётся зависимым от итогового generated level и состояния загрузки.

Исходник EXE: `C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/Diggles.exe`, preferred base `0x400000`, SHA-256 `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`. `O/` ниже означает соседний каталог `data/`. Все native выводы получены повторным чтением этого EXE через pefile + Capstone. Оригинал не запускался. Это статический source-контракт, не измерение live state.

## 1. Имена команд и producer

| Tcl | Строка в EXE | Регистрация | Callback / действие |
| --- | --- | --- | --- |
| `horizon_set` | `0x72D578` | `0x619D91–0x619DB1` | `0x642110`; argc==7, включая имя команды |
| `horizon_rem` | `0x72D584` | `0x619DCB–0x619DEB` | `0x642800`; argc==2, удаление по позиции |
| `horizon_clear` | `0x72D590` | `0x619E05–0x619E25` | `0x642A10`; resize registry до 0 в `0x642ACA–0x642AD8` |
| `set_light_begin` | `0x72DCC4` | `0x61BDA7–0x61BDCD` | `0x64B620`; argc==2; Tcl integer → `0x590620` |

Debug-name `0x72FC54` буквально содержит `TCL:CTclGlobalMethods::HorizonSet()`, `0x730350` — `TCL:CTclGlobalMethods::SetLightBegin()`. Имена не выведены из соседства функций. IAT `0x715534` — `Tcl_GetDoubleFromObj`, `0x715574` — `Tcl_GetIntFromObj`.

`horizon_set` берёт argv1 как vector через `0x6BAFE0` (`0x642540–0x642558`), вызывает `0x4755A0` с этим центром (`0x64255E`), затем append одного элемента через `0x47DEB0` (`0x642599–0x6425A5`). В `0x6425D9–0x6426D2` заполняются **все восемь dword**, так что это установленный producer именно того массива. Не следует пытаться строить registry из light records, FOW аргументов, owner или autolight bit.

## 2. Структура записи и обновления списка

Manager = pointer `[0x76A338]`. `manager+0x2868` — data pointer; `+0x286C` — count. Stride `0x20`. Конструктор обнуляет pointer/count (`0x464965–0x464979`); append/resize helpers — `0x47DEB0/0x47DE40`. Capacity растёт блоками по 16 элементов; это не ограничение количества horizon-записей.

| Offset | Тип / происхождение | Значение для `Info_Fog_Urw_c` |
| --- | --- | --- |
| `+00/+04/+08` | float32 XYZ из argv1 | фактическая позиция marker, Z=3.02 |
| `+0C` | int32 R из argv2 | 78 |
| `+10` | int32 G из argv3 | 96 |
| `+14` | int32 B из argv4 | 110 |
| `+18` | float32 depth из argv5 | 32 |
| `+1C` | float32 size из argv6 | 30 |

R/G/B: `clamp(FISTP(f32(f32(Tcl_double) * 256.0f)), 0, 255)`. Константа `0x737658` =256.0f; argv2/3/4 распаковываются в `0x6424EE–0x64253B`, `0x6424A4–0x6424EB`, `0x642455–0x6424A1`; записи RGB в `0x64261E/0x642648/0x642672`. FPU rounding mode callback не устанавливает. Приведённые integers соответствуют ближайшему округлению; для строгого воспроизведения при ином режиме передавать исходные decimal RGB и native FISTP context. Для torch predicate RGB и depth вообще не нужны. Depth не является радиусом: `+18` и `+1C` — разные аргументы.

Перед append `0x4755A0` ищет **первую** запись с `sqrt(f32(dy²+dx²)) < 1.0f` (константа `0x737138`). Если нашёл, сдвигает хвост на 32 bytes, уменьшает count на 1 и возвращает. Это не удаление всех пересекающихся кругов, не сравнение Z и не точное равенство координат. `horizon_rem` вызывает тот же helper; `horizon_set` после него добавляет новую запись в конец. Порядок операций нужен при повторном импорте/наложении шаблонов.

Другие найденные пути изменения:

* `0x47D420`: сериализует count и восемь dword каждого элемента (`0x47D446`, `0x47D46C..0x47D4B9`); при чтении resize может создать записи **без Tcl callback**. Callers: `0x556E61`, `0x557871`. Поэтому reload/save нельзя подменять чистым startup.
* `0x4750B0–0x4753E8`: выбирает ближайшую подходящую horizon-запись относительно XY из `global[0x772400]+0x5A4`, поля `+0x154/+0x158`. Принимает `distance < size`, копирует RGB/depth в manager `+0x2854..+0x2860` (`0x475234–0x475258`), также удаляет outside-world записи. Это дополнительное подтверждение назначения списка; полная визуальная формула horizon этим отчётом не переносится.
* `0x66A8AA–0x66A94F`: удаляет записи с центром в обрабатываемом rect, через `0x47D810`; проверки включают обе границы rect. Здесь зафиксирован дополнительный путь удаления, без присвоения имени всего внешнего Tcl callback.
* Resize-to-zero найден также у `0x4F803C`, `0x53F25E`, `0x5402F0`, `0x541895`, `0x5B38AB`; destructor освобождает storage в `0x464B3B–0x464B5E`. Отсутствие marker-объекта в runtime не означает отсутствие horizon-записи: Tcl сам удаляет marker после init.

## 3. Узкий контракт predicate `0x4753F0`

На входе pointer на candidate XYZ; результат AL boolean. Для обычных конечных координат:

```text
i = 0
while i < count:
    e = entries[i]
    if e.x < world.min_x or e.x >= world.max_x or
       e.y < world.min_y or e.y >= world.max_y:
        entries[i] = entries[count - 1]  # если не последний
        count -= 1
        continue                         # проверить подставленный элемент
    dx = f32(e.x - candidate.x)
    dy = f32(e.y - candidate.y)
    d2 = f32(f32(dy*dy) + f32(dx*dx))
    distance = f32(sqrt(float64(d2)))
    if e.size > distance: return true
    i += 1
return false
```

World float bounds: `[0x77241C]+0xA4/+0xA8/+0xAC/+0xB0`; margin=0. Predicate удаляет по положению **центра**, не по выходу края круга. Дистанция строго XY, Z не читается. Сравнение строгое: на самой границе size результат false. Нулевой/отрицательный size не проходит для конечного distance; отдельного positive-size gate нет. Native SSE `comiss/ucomisd` и его NaN-ветви не следует заменять этим finite-only pseudocode для повреждённых данных.

Геометрия проверки круга доказана инструкциями `0x4754A2–0x4754E4`; семантика «наблюдатель видит» из неё **не следует**. True возвращается немедленно: последующие outside-world записи в этом вызове могут остаться непроверенными. Удаление swap-last отличается от shift-tail при `horizon_rem`.

В `auto torch 0x590E60` порядок gates (`0x590E88–0x590F41`):

1. Candidate XY внутри world `[min+2,max−2)`.
2. Отклонить, если `float32(cutoff_int) > candidate.y`; равенство разрешено (`0x590EF4–0x590F02`).
3. Читать cell по `trunc(f32(X+0.5f)), trunc(f32(Y+0.5f))` (`0x590F08–0x590F22`); bias `0x73708C`=0.5f. Взять `cell[+0x18] & 3`.
4. **Только при low2==3** вызвать registry predicate; его true отклоняет размещение (`0x590F27–0x590F3B`). Для остальных low2 horizon-список в этом пути не проверяется и не purges.
5. Затем отдельная проверка существующего освещения, описанная в `automatic-torches-2026-11-18.md`; входной Z-копии присваивается 0 (`0x590F41`). Прохождение horizon/cutoff ещё не означает создания факела.

По уточнению интегратора `terrain_state.cell` уже содержит source-derived low2 из loader passes в `tools/export_native_tunnel_rules.py`. Этого достаточно для данного gate и low2-проверок snap-release; полный coarse byte для этих операций не требуется. Здесь эти exporter/runtime-файлы не изменялись.

## 4. Writers `[0x7683D8]` и смысл cutoff

| Адрес | Доказанное действие |
| --- | --- |
| EXE data `0x7683D8` | Начальные bytes `F0 D8 FF FF` = int32 −10000 |
| `0x59473A` | World-create/reset пишет −10000; `0x594744` ставит такое же значение в `[0x76A324]+0x4410` |
| `0x590688` | Setter `0x590620(new_y)` пишет новый integer, только если отличается от прежнего |
| `0x59337F–0x593386` | Передаёт **адрес глобала** в serializer `0x406F60`; mode=1 может непосредственно записать прочитанные 4 bytes |
| `0x5937B4–0x5937C2` | Другой путь чтения: serializes local integer, затем вызывает setter `0x590620` |

`0x406F60`: mode1/type `0x1C4F`, status0/−5 → `0x6C6DA0`; mode2/type `0x79B1`, status0 → `0x6C76B0`, размер4. Это установленные read/write ветви, а не только xref по совпадению bytes. Дополнительное поле manager+4410 сериализуется отдельно (`0x59338B–0x59339F`, version>=123 — `0x5937C7–0x5937E3`); равенство его текущему cutoff нельзя считать инвариантом всех сохранений.

Оба прямых caller setter: `0x64B77A` и `0x5937C2`. Tcl callback `0x64B620` парсит argv1 через `Tcl_GetIntFromObj`, передаёт integer setter, затем пишет `[0x76A324]+0x4410` (`0x64B77F–0x64B78C`). Некорректный integer в этой реализации превращается в0; runtime adapter лучше отличать ошибку входных данных от валидного startup, не угадывать порог.

Перед изменением setter строит sample-rect `(world.sample_min_x, world.sample_min_y, world.sample_max_x, 8*max(old,new)+8)` и вызывает `0x5A3FD0` с mask8 (`0x590637–0x590683`); helper ограничивает rect world bounds. Это побочный эффект обновления terrain-области. **Присваиваемое значение — new, не max(old,new)**: порог можно уменьшать. Для pure placement policy достаточно int cutoff; живой adapter с соответствующим cache обязан воспроизвести invalidation.

Поиск всех raw operands `D8 83 76 00` дал девять ссылок: `0x4872A0`, `0x4880F6`, `0x590628`, `0x59068A`, `0x590C84`, `0x590EF8`, `0x593380`, `0x59473C`, `0x599F04` (это адреса operand bytes). Перечитанные инструкции показывают: readers у `0x48729E`, `0x4880F4`, `0x590626`, `0x590C82`, `0x590EF4`, `0x599F03`; два direct stores выше плюс передача адреса serializer. Проверка абсолютных ссылок не является доказательством отсутствия произвольного alias-write; выше перечислены установленные writers и связанные read paths.

В исходных Tcl есть реальные значения33 (`Scripts/gameplay/Campaign.tcl:8`, SandboxUrw:8 и другие),6033 (`Campaign6000.tcl:15`),2000 (`classes/story/Trigger_Lava.tcl:56`),0 (`classes/story/story.tcl:590`). Это другие пути сценариев, **не** основание поставить33 в authored_2p. В `GameScripts/startseqs.tcl:6` значение−10 закомментировано.

## 5. Конкретный authored_2p startup feed

Источник сценария — `O/GameScripts/multi_dm_kris_2p_001.tcl`: map_size600×600 (`:3`), Zone=Urwald (`:5`), preset a_0=(76,68) (`:49`), b_1=(192,68) (`:60`). Преобразование accepted preset → level XY=source+(16,16) доказано прежним исследованием `native-multiplayer-world-2026-11-17.md`, в частности stores `0x584CAF–0x584CDC`; текущий `godot/models/multi_start_010_world_context.json` подтверждает a_0 offset=(92,84). Это условие принятого placement, не capture исторического запуска.

`multiplayer.tcl:264,272,279,285,296`: map create; generation area; add presets; получить итоговый level; apply_level. **Читать следует `Templates/tcl/...`, а не только монолит `Templates/...`.** `Scripts/misc/mp_tools.tcl:13–15,35–44` передаёт level offset и tile offset; split BA затем вычитает16 из xoffset. Поэтому marker local X уже измерен от целого шаблона: ещё раз прибавлять tile16 нельзя.

| Marker source | Поля исходника | Conditional world XYZ |
| --- | --- | --- |
| `Templates/tcl/split/splt_multi_urw_start_010_a_0_tBA.tcl:66–71` | new `Info_Fog_Urw_c`, local `(31.3032,12.3286,3.02)`, затем `Editor_Set_Info {{blah fahsel}}`; компенсация tile в `:4` | `(123.3032,96.3286,3.02)` |
| `Templates/tcl/split/splt_multi_urw_start_010_b_1_tBA.tcl:72–77` | тот же класс, local `(31.0606,12.9618,3.02)`, `Editor_Set_Info`; компенсация tile в `:4` | `(239.0606,96.9618,3.02)` |

`Scripts/misc/info_obj.tcl:24–28`: `Editor_Set_Info` записывает info_string и **вызывает init**. `Scripts/classes/items/infoobjs.tcl:748–762`: init класса вызывает **`horizon_set [get_pos this] 0.305 0.375 0.429 32 30`** (`:751`), затем удаляет объект, если не map editor (`:752`). `obj_init` сам horizon_set не вызывает; нельзя привязывать заполнение только к наличию меша или к позднему списку живых объектов. `blah fahsel` для этого специализированного класса не задаёт RGB/depth/size.

Generic `Info_Fog` (`infoobjs.tcl:683–711`) отличается: читает `get_info r,g,b,depth,size`, default0.5 для RGB,5 для depth,15 для size (`:688–697`); `get_info` возвращает undefined при отсутствии ключа (`info_obj.tcl:4–13`). Его marker удаляется timer event. Для других специализированных классов читать их literal `horizon_set`, не распространять Urw_c size30 на все объекты.

Аудит **65 authored preset occurrences, 60 уникальных прочитанных файлов** (scenario + wrappers + split Tcl) нашёл ровно эти две конструкции `new Info_Fog*`; прямых команд `horizon_set/rem/clear/set_light_begin` в просмотренных template-файлах нет. Повторяющиеся имена presets остаются повторными occurrence. Aggregate manifest SHA-256 (JSON `relative_path → raw_file_sha256`, sorted keys, separators `(',',':')`, UTF-8): `fd6d869b5e92648e626cb8b0fdbdf69c9858dd1b0c85e366b8062cee8182a0ed`. Это проверка restricted literal source grammar, не исполнение Tcl и не доказательство отсутствия произвольных динамических calls.

Дополнительно `Scripts/init/lginit.tcl:8–15` задаёт `Urwald.Std` как `tcl/urw_gng_*`, `tcl/urw_gsg_*`, `tcl/urw_hol_*`. Проверены **192 root Tcl и их split-части, всего280 уникальных файлов**: ноль буквальных `new Info_Fog*`, ноль прямых `horizon_set/rem/clear/set_light_begin`. Aggregate manifest по той же формуле: `4e836c3404f6d84cd78915cc06fe8be2535175f7228ddfd3dc2a987fe612c848`. Таким образом, выбор обычных fillers из этого source pool не добавляет явных horizon-маркеров или cutoff-команд. При чистом reset, принятых обоих authored start-presets и выполненных их init **явный source startup feed содержит ровно две записи выше и cutoff−10000**. Это сильнее произвольного предположения о заполнении generated окружения; всё ещё не утверждает исполнения всех динамических Tcl-ветвей оригинального запуска.

Практический feed для **чистого authored host context с принятым a_0**:

```text
cutoff_int = -10000                 # EXE init + world reset, не Campaign33
horizon_registry = []               # новый context, не переиспользованный save
on source Editor_Set_Info -> init at marker a_0:
    horizon_set((123.3032,96.3286,3.02), 0.305,0.375,0.429,32,30)
on accepted marker b_1 init, if that template is part of host level:
    horizon_set((239.0606,96.9618,3.02), 0.305,0.375,0.429,32,30)
```

Adapter выполняет native float32-преобразование аргументов, remove-first-within1 → append и сохраняет registry независимо от удаления marker. Для pure policy можно передавать только centerXY и float32 size30, плюс count/order и world bounds; RGB/depth/marker Z не влияют на это решение. Сохранять provenance класса, позиции и init event полезно для последующего horizon renderer и диагностики. При template-local policy кандидат и **все** registry центры нужно переводить одним offset; cutoff/world bounds также должны оставаться в согласованной native системе, нельзя сравнивать local Y с глобальным порогом произвольно.

Собственная запись a_0 **не покрывает весь** его44×24 rect по strict XY-distance30 (например local `(0,0)` даёт≈33.65). Поэтому проверять actual candidate и size, не упрощать gate до «весь start-шаблон запрещён». Material-low!=3 вообще обходит этот predicate. Вторая запись b_1 далеко от a_0; её включение в global list не меняет проверку a_0-кандидатов внутри его rect. Для всего generated мира нужны его собственные marker/init events.

## 6. Что установлено и что остаётся неизвестным

**Установлено для нового source-driven host context:** начальные empty registry/−10000; producer API и полный record; явная a_0 marker-запись с center/size, условная b_1-запись; порядок material/cutoff/horizon gates. Этого достаточно передать доказанные входы в pure policy. По уточнению интегратора timestep0.1 и writer `global+6C/0x6B4C94` уже восстановлены в `godot/models/native_animation_timing.json`; здесь они не пересматривались и не являются новой зависимостью gate. RNG/ID stream остаётся отдельным явным deterministic host context.

**Не установлено:** полный итоговый generated level, принятые/отклонённые placements и их реальный порядок в историческом запуске; возможные дополнительные записи от динамических calls и loaded save (явные маркеры стандартного Urwald-пула проверены выше); точный момент оригинального consumer относительно каждого init event; полная визуальная интерпретация horizon depth/RGB. Поэтому «две authored записи» — подтверждённый явный source feed при перечисленных startup-условиях, не безусловный полный registry любого multiplayer запуска. В новом локальном host context допустимо явно реализовать только выбранный source scenario; это ограничение сценария, не гипотеза о live оригинале.

Не требуется выдумывать FOW radius, заимствовать33 из Campaign или ждать полного coarse byte для low2 gates. Остальные light-index/queue/snap checks остаются отдельными контрактами; этот документ не выдаёт их за выполненные. Main, exporter native_torches, runtime/data и APK не менялись.

## 7. Воспроизводимость и byte proof

Новый `tools/audit_torch_placement_gates.py` читает установку, проверяет pinned EXE, печатает JSON hashes и authored contribution; `--disasm A:B` печатает bytes/Capstone для half-open VA span; `--xref VA` ищет absolute и rel32 candidate xrefs, `--raw VALUE` — raw operands. Raw hits требуют проверки окружающей функции: произвольный byte-offset не принимается за instruction boundary. Скрипт не запускает Tcl/EXE и не пишет runtime-данные.

```powershell
python -B tools/audit_torch_placement_gates.py --check
python -B tools/audit_torch_placement_gates.py --disasm 0x642110:0x6427f4 --xref 0x590620 --raw 0x7683d8
```

`--check` сверяет hashes с таблицами ниже, два marker occurrences, count presets, оба aggregate manifests, отсутствие буквальных markers/direct gate-команд в standard pool и исходные EXE strings/−10000. Это source reproducibility check, не dynamic parity test.


### EXE spans

SHA-256 сырых bytes; start включён, end исключён. RVA=start−0x400000.

| Назначение | Start | End | SHA-256 |
| --- | --- | --- | --- |
| registry_ctor | `0x464965` | `0x464979` | `53db2fab77460e3bdacb4db97ed67f04ee970cfb3b6d0b5f4796c1c982ba6cf4` |
| horizon_selection | `0x4750b0` | `0x4753e8` | `163405a90cf0fc58df6369e63b9edce376fd423b389a3c244bfa7d6023e0cc3a` |
| predicate | `0x4753f0` | `0x47559f` | `ab79a76da1b971ec2085097f7b723853fc0ce82c2bb292a8f0b3d7ad58aae55f` |
| remove_near | `0x4755a0` | `0x4756a0` | `7c274df98f0636685e1370f1202deee408c21a6cb56b135e824985461f104a51` |
| serialize_registry | `0x47d420` | `0x47d4d9` | `b40fe98d8e3e07ed3efe5bc8e5fbe3f4419b41fc26005433a457a268ff4a8839` |
| resize_registry | `0x47de40` | `0x47dea8` | `cac4aac92f6c3ec506928a90563c93c0fb69130041a2b4fa2850f3debdf1f240` |
| append_registry | `0x47deb0` | `0x47df79` | `bc5ef88d220d776cc8d988eaa952441becff91aef40ba1ccbb5322e162008b3c` |
| cutoff_setter | `0x590620` | `0x590695` | `91b23838f7890230214398dc27450342199d6a28872a9eca32ba3f5e7050e17e` |
| placement_gates | `0x590e88` | `0x590f41` | `a5bd8a615316ffd10a9f5918199c0f8eaabb7b2d1bab9b0e3baeb064ff5267db` |
| serialize_cutoff | `0x59337f` | `0x5933a4` | `1bac4190efbb7fb41985973db3c8331f64c765ff1bdc4f9b3036dc91e92073ad` |
| load_cutoff_setter | `0x5937b4` | `0x5937e9` | `eeb2da29c2c841a305907f1fbae801151e51c9d805551ce2545bf4670b225cf0` |
| world_reset_cutoff | `0x59472f` | `0x59474e` | `a18deb380437a105141936edbc11433a714c774428165db5fdfa3826a455dc52` |
| horizon_registrations | `0x619d91` | `0x619e2a` | `03a848cc7cdb1daf37eca118da9ce1085a242a1c19fed0f00a778e4af8592914` |
| cutoff_registration | `0x61bda7` | `0x61bdd2` | `50efb3db40febfc59557e85f2e7f3d830288041386678e623be0088ae2cf20b3` |
| horizon_set | `0x642110` | `0x6427f4` | `71743883cd4bac9484541b6b75c53593fa33999fd4e9a0b7f1b6ed971ecb1e1e` |
| horizon_rem | `0x642800` | `0x642a10` | `2134a842fc2393460ec5ff59859dc9ac33224c6391f0f7ac6b7e75dc1f00d988` |
| horizon_clear | `0x642a10` | `0x642b87` | `5fce39533fed8c0cd8a66019055e4b2fdcf90b09b9c3edab70e34a315949a051` |
| set_light_begin | `0x64b620` | `0x64b82b` | `98d9afbb71a97b3f74e36e3ff56820dd156916a2338bf74178d70681bcd08086` |
| region_remove | `0x66a8aa` | `0x66a94f` | `e7b406f942151a95bacaf7c2537ee5b38addce519b2fc775105f83ff632a4abf` |

### Исходные Tcl

SHA-256 raw bytes до декодирования/перевода строк; пути относительно O/.

| Файл | SHA-256 |
| --- | --- |
| `Scripts/classes/items/infoobjs.tcl` | `6eb49f95881bf0cc8dd8a16d12da779498255e7494580280bc9b521f6784f9df` |
| `Scripts/misc/info_obj.tcl` | `6aacde183a7d5ee5423e55f32c9335c8d51e6ffc608ef4483eae5e900b388c9f` |
| `Scripts/misc/mp_tools.tcl` | `180d8d6b49ff8e8b6cd8793f7f0b0c3b4319847156fb38c58e193b2564f8dcb0` |
| `Scripts/init/mpinit.tcl` | `8405c5735fc859fad161fd47996b8b5e1020dc2ed97eeabe2123cc992c34f202` |
| `Scripts/init/lginit.tcl` | `84080c5b84678988a4ff9b0af48883126a12ee1b3d9b8b76897e67d2a0658783` |
| `GameScripts/multiplayer.tcl` | `c1eaa85ef503bf6e76747166bea5af211246738152ed40a03c1c544343c9cc2a` |
| `GameScripts/multi_dm_kris_2p_001.tcl` | `c94819f6dc5f97f8432c36b656ed8c10469c8d8920ab38cca7935cfa6a7bf65b` |
| `Templates/tcl/multi_urw_start_010_a_0.tcl` | `e660b407d99621375a8cdd1ba7352bfb14f692fc9d69ce6cf028b23b855c9d61` |
| `Templates/tcl/split/splt_multi_urw_start_010_a_0_tBA.tcl` | `018a5a6c81b1406072e4a1d776617d919cb2c0550cb5953b16f0fea5c26d7fb8` |
| `Templates/tcl/multi_urw_start_010_b_1.tcl` | `b1a78e2617b2b21c2b54b10db353ed4f4a574961f6f2addeaa0e35ba64ad2977` |
| `Templates/tcl/split/splt_multi_urw_start_010_b_1_tBA.tcl` | `e3734402349b0b73b83f14e4a94550d2e3cb121cb6a6511e774ff4524766e3cb` |
