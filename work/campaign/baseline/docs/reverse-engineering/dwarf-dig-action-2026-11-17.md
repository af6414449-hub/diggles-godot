# Действие киркой с пола: исходные клипы и контракт — 2026-11-17

**Результат:** `godot/models/dwarf_dig_action.json` содержит 42 кадра мужского тела: два обычных рабочих клипа и четыре общих перехода инструмента. `tools/export_dwarf_dig_action.py` воспроизводит экспорт без изменения основного экспортёра/контроллера и без копирования текстур. Это данные для исполнителя явно назначенной работы; поиск работы и native walk не реализуются здесь.

`DATA` ниже — установленный `C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/data`, `Z` — `DATA/Scripts/classes/zwerg`. JSON содержит SHA-256 исходных 3DB/Tcl и существующего модельного манифеста, исходные animation indices, mesh indices и необъяснённые поля `extra` без переинтерпретации.

**Подтверждённые клипы.** `Scripts/init/animinit.tcl:9,13` загружает `mann` и `werkzeuge`. Все рабочие клипы ниже — объект `mann` пакета `3db/mann.3db`.

| Роль / Tcl-алиас | Исходная анимация | Animation index | Mesh indices / кадров | Tcl-доказательство |
|---|---|---:|---|---|
| Достать, часть A / `tooltakeout_a` | `werkzeug_raus_a` | 72 | 557–561 / 5 | `Z/z_anims.tcl:242` |
| Достать, часть B / `tooltakeout_b` | `werkzeug_raus_b` | 73 | 562–564 / 3 | `Z/z_anims.tcl:243` |
| Вперёд с пола / `digfront` | `buddeln_vorn` | 171 | 1398–1410 / 13 | `Z/z_anims.tcl:307` |
| Вниз с пола / `digdown` | `buddeln_unten` | 165 | 1266–1278 / 13 | `Z/z_anims.tcl:312` |
| Убрать, часть A / `toolputaway_a` | `werkzeug_weg_a` | 74 | 565–568 / 4 | `Z/z_anims.tcl:244` |
| Убрать, часть B / `toolputaway_b` | `werkzeug_weg_b` | 75 | 569–572 / 4 | `Z/z_anims.tcl:245` |

Клип вверх также известен: `digup → buddeln_oben_normal`, animation 69, meshes 494–506, 13 кадров (`Z/z_anims.tcl:305`); для текущих целей он не нужен и в JSON не экспортирован. Материальные варианты `digfrontwood/metal/stone` и `digdownwood/metal/stone` зарегистрированы в `:308–310,317–330`, но не добавляются в этот ограниченный набор. Выбор такого варианта автоматически из материала этим исследованием не доказан.

**Выбор позы с пола.** При `get_gnomeposition this == 0`, без Presslufthammer и применимого Kristallstrahl, `Z/z_dignwalk.tcl:388–420` вычисляет `height = get_posy(this) − digpos.y`:

- `height > 1.6` → `digup`;
- `0.6 < height <= 1.6` → `digfront`;
- `height <= 0.6` → `digdown`.

Следовательно, при worker native Y `14.5` цели Y `15/16` требуют **digdown**, а не digfront. `default_work_clip` экспортирован как `buddeln_unten`, но исполнитель обязан выбирать по `ground_pose`. Это native Y; при существующем отображении Godot Y знак инвертирован. Нельзя выбирать позу по глубине `h=11` или только по направлению камеры.

У нормального down есть условие: если `accident_possible` включён и опыт ниже `tttfailmax_dig`, сначала ставится `digdownaccident`, затем `dig_anim` с запрещённой повторной аварией (`Z/z_dignwalk.tcl:395–411`). Установленный базовый tune равен `0.2` (`Scripts/misc/techtreetunes.tcl:1358`). Accident-клип `buddeln_unten_unfall` имеет 31 кадр и здесь не экспортируется. Нормальный down без этой ветки соответствует `accident_possible=0` либо достаточному опыту; нельзя молча заявлять полное воспроизведение аварий. Для front accident принудительно равен нулю (`:402–404`).

**Очередь инструмента и границы work-клипа.** `dig_continue` ставит `change_tool Spitzhacke`, затем `dig_anim` (`Z/z_dignwalk.tcl:271–277`). В обычной правой руке на земле, если инструмента ещё нет, `change_tool` образует:

```text
play_anim tooltakeout_a
change_tool_finish_out $outobj 0
play_anim tooltakeout_b
play_anim dig${dir} {$digpoint}
```

Порядок следует из `tasklist_addfront` в `Z/z_procs.tcl:1602–1677`: вызов attach расположен между двумя частями доставания. Если тот же инструмент уже в руке, `:1615–1616` возвращает сразу. У кирки нет отдельной обязательной последовательности work-start/loop/work-end: `play_anim dig${dir}` — целый одинарный клип (`Z/z_dignwalk.tcl:419–420`). Повтор проходит через `dig_continue`, а не бесконечный Godot AnimationPlayer loop.

Убирание экспортировано потому, что `stop_prod` вызывает `dig_endanim`, затем `change_tool 0` (`Z/z_procs.tcl:1247–1249`; вход `work_idle` — `Z/z_work_states.tcl:215–226`). При кирке получается `toolputaway_a → change_tool_finish_in → toolputaway_b`. Сама `dig_endanim` добавляет специальные окончания только для laser/airhammer (`Z/z_dignwalk.tcl:555–578`); для обычной кирки не следует придумывать `buddeln_unten_end`.

**Callback и контакт.** При непустом аргументе позиции `play_anim` вызывает `action this anim ...` с callback `state_enable this; dig_execute ...; dig_continue` (`Z/z_procs.tcl:193–197`). Значит, gameplay-попытка копки следует за завершением action-анимации. `sound anim mann.buddeln_unten 5 buddeln_o ...` и аналогичная строка для `buddeln_vorn` находятся в `Scripts/init/z_soundinit.tcl:598,600`: это **звуковое событие**, не вызов terrain mutation. В JSON сохранён сырой номер `frame_raw=5`; его zero/one-based трактовка и точный физический контакт не установлены. Нельзя переносить удар грунта на этот кадр только на основании звука.

`dig_execute` дополнительно проверяет расстояние, опыт, материал и случайное число (`Z/z_dignwalk.tcl:295–382`). Один callback может дать ноль либо несколько принятых операций. Принятый `dig_apply` входит в callback EXE `0x6347A0` и ядро `0x596B80`; сама анимация не доказывает принятие изменения.

**FPS: неизвестно в оригинале.** У этих 3DB-записей `extra.f32=0`, это не основание назначать исходную частоту. Данные `extra` сохраняются целиком, `native_fps=null`. `adapter_fps=12` — явная совместимая политика текущего проигрывателя Godot. Если адаптер завершает клип после `frame_count` тиков, длительности 13 кадров и переходов 5/3/4/4 будут соответственно `13/12`, `5/12`, `3/12`, `4/12`, `4/12` секунды; это не измеренные времена оригинала.

**Кирка и граница attachment.** Класс `Spitzhacke` задаёт `class_defaultanim spitzhacke.standard`, выключает физику и включает `ANIM_STILL` (`Scripts/classes/items/werkzeuge.tcl:14–22`; `Scripts/init/animinit.tcl:4`). В загруженном `werkzeuge.3db` объект `spitzhacke`, animation index 1 `standard`, meshes 2 и 3. Материал `Metall_Werkzeuge_a_128`, texture `Metall_Werkzeuge_a_128.tga`.

`change_tool_finish_out` делает `link_obj $outobj this $hand` и включает видимость (`Z/z_procs.tcl:1538–1557`); по умолчанию `hand=0` — правая рука (`:1600–1602`). Это доказывает слот 0, **но не его transform**. `inspect_3db.parse` пропускает блоки данных после mesh bounds; attachment этого рабочего клипа не декодирован. Поэтому JSON намеренно body-only: `tool.attachment_transform=null`, `mesh_exported=false`, `render_ready=false`. Исходный tool asset/материал записан в `tool`, но отдельная кирка не размещается через придуманный offset. Наличие меша инструмента в пакете не означает, что он входит в body surfaces.

**Подход, dig_check и досягаемость для первого задания `(2,15)`.**

1. Начало работы — `get_digedge(startpos,this)`; при edge Y > 0 берётся `vector_fixdig(edgepos,get_pos(this))`, затем Z walkpos возвращается к исходному edge Z (`Z/z_dignwalk.tcl:136–163`). Контракт команд доказан, точный выбор кромки/алгоритм `vector_fixdig` здесь не восстановлен. Его native callback зарегистрирован как `0x635610` в `0x61A848`; `get_digedge` — `0x635180`. Нельзя считать смещение от цели к стойке равным произвольно выбранной клетке.
2. Продолжение получает `digpoint = dig_next(cpos,this,try) + {0 0 -1}`, затем `walkpos = vector_fixdig(digpoint,cpos)` (`:210–241`). Для кирки новый подход нужен, когда `vector_dist3d(worker,walkpos) > 0.5` (`:243–251`). Это порог перестановки к стойке, **не радиус удара**.
3. `vector_dist3d` в оригинале использует `sqrt(dx² + dy² + (0.5*dz)²)`, а не обычную несжатую 3D-длину: callback `0x638A60`, математика `0x638C44–0x638C7C`. `walk_pos_dig` передаёт `-target {walkpos} -waving 0 -dig 1 -digpos {digpoint}`, а завершение проверяет `get_walkresult == 4` (`:705–721,910–934`). Разрешённый пользователем A* одного пола остаётся адаптером, а не реализацией этих native-команд; телепортация не следует из данного контракта.
4. `dig_check` использует опорную позицию **worker + `{0 -0.8 0}`**, затем `get_angle_num4(digpoint,offset_worker)` и три соседних значения `get_hmap`; пройти должны **хотя бы два**, каждое строго `<13` (`:166–182`). Высота ровно 13 не считается свободной.

| Направление `w` | Смещения трёх точек в исходном порядке |
|---:|---|
| 0 | `(0,-1),(-1,-1),(1,-1)` |
| 1 | `(1,0),(1,-1),(1,1)` |
| 2 | `(0,1),(-1,1),(1,1)` |
| 3 | `(-1,0),(-1,-1),(-1,1)` |

Для worker `(3,14.5)` опорная точка `(3,13.7)` лежит относительно цели `(2,15)` выше и справа, с преобладающим Y-смещением: native-направление **0**. Следовательно, проверять нужно `(2,14),(1,14),(3,14)`. Хотя бы две **известные исходные** высоты должны удовлетворять `<13`; неизвестную высоту нельзя объявить свободным соседом. Знак подтверждён callback `get_angle_num4` `0x646B10` (регистрация `0x61BBE6`): разность берётся как второй вектор минус первый (`0x646D48–0x646D52`), угол считает `0x40B700`, сектор — `0x646DD4–0x646E0C`. Helper использует signed `acos(dx/hypot(dx,dy))`; константы сектора — `3*pi/4 @0x7373B0`, `10*pi @0x7375AC`, `-pi/2 @0x737744`. Этот пример не находится на границе секторов.

Радиус выполнения проверяется отдельно: при кирке `digattr = 0.5*exp_Stein` (`:304–307`), `thispos = worker + {0 -0.8 0}`, затем `vector_dist(digpoint,thispos) < 3 + 2*digattr`, то есть строго **`distanceXY < 3 + exp_Stein`** (`:310–315`). В отличие от предыдущей функции, native `vector_dist` действительно игнорирует Z: регистрация `0x61ABAC → 0x638730`, математика `0x638914–0x638932` читает только X/Y.

| Цель при worker `(3,14.5)` | XY-расстояние от `(3,13.7)` | Проходит дистанцию при нулевом опыте |
|---|---:|---|
| `(2,15)` | ≈1.64012 | да |
| `(2,16)` | ≈2.50799 | да |
| `(1,15)` | ≈2.38537 | да |
| `(1,16)` | ≈3.04795 | нет; требуется опыт строго больше ≈0.04795 |

Это вычисления по исходной формуле, не live-наблюдение успешного удара. Они не заменяют проверку соседей, достижение стойки, ориентацию, material/random gate и принятие операции BlockDB. Ограничение `abs(digpoint.z−dig_z)<2` в `:311–314` сравнивает последующие точки серии с начальной глубиной этой серии, а не Z-distance от гнома. Для первого ручного задания `(2,15)` нельзя расширять доступность остальных отмеченных точек одной только успешной дистанцией.

**Экспорт без нового чтения формата.** Используется `inspect_3db.parse` (`tools/inspect_3db.py:44–102`). Тело уже существующей `main.export_mesh` (`tools/export_demo_start_models.py:69–88`) извлекается через AST и компилируется без изменений с исходным closure; файл экспортёра не редактируется. Получаются те же `mesh_index/bounds/surfaces` и нормализованные `u16/65536` точки, которые уже принимает `_build_model_meshes`. Исходные transforms копируются из существующего манифеста: VA `0x487430`, `0x484C10`, `0x48CDA0`, `0x47EC30`. Не центрировать каждый кадр по bounds и не заменять делитель на 65535.

Пять body-текстур повторно используются из `res://assets/textures/` с проверкой SHA-256 и сохранением `alpha_range`; новых TGA/OBJ/модельных файлов вне выделенного JSON не создаётся. Требование texture для инструмента записано отдельным списком; отсутствие/наличие проверяется без копирования.

**JSON-схема для интегратора:**

```text
schema = diggles.dwarf_dig_action.v1
model_key = mann.3db::mann
aliases[Tcl alias] -> native clip name
clips[native name] = {animation_index, frame_count, mesh_indices, extra,
                     native_fps:null, adapter_fps:12, completion_tcl,
                     terrain_effect_on_completion, sound_events, frames:[...]}
frames[] = {mesh_index, frame_index, bounds, surfaces:[...]}
surfaces[] = {material, texture, points, uvs, triangles, brightness, alpha_range}
ground_pose / queue_contract / timing / worker_contract = исходные условия + явные пределы
tool = asset mapping, slot 0, attachment_transform:null, render_ready:false
textures / sources / mesh_exporter = повторное использование и provenance
```

Воспроизведение: `python -B tools/export_dwarf_dig_action.py`; проверка без записи: `python -B tools/export_dwarf_dig_action.py --check`. Экспортёр проверяет полное потребление обоих пакетов, длины клипов, границы mesh/point/UV ссылок и конечность координат; `--check` заново строит payload из источников и побайтово сравнивает JSON. Визуальная интеграция action/meshcache и исполнение callback принадлежат родительскому исполнителю; здесь сцена не менялась.

Фактическая проверка: `DWARF_DIG_ACTION_CHECK_OK`, exit `0`. JSON — 2 050 776 байт, SHA-256 `443c6e3831a7b27a3b2c352c5bc8935b08f4ddd5812a1c4e9f181cedf49d7854`; 42 кадра, каждый с пятью body surfaces. Повторно использованы пять body-текстур, отсутствующих нет. Texture кирки также уже найдена как `res://assets/textures/Metall_Werkzeuge_a_128.tga`; наличие этой текстуры не устраняет неизвестный attachment transform. Основной экспортёр остался с SHA-256 `7520b9c8a0ca3f9b494267ebdec2024d231cd8a70d484c48cd6de7055848ca58`.
