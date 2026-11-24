# Misc_Light: runtime wall snap, 2026-11-18

**Продолжение:** source low2 материала, horizon registry/cutoff и эти helpers подключены к основной сцене. [Runtime-отчёт](automatic-torches-runtime-2026-11-18.md). Неизвестные ниже gates описывают предыдущий checkpoint; актуальные доказательства — `torch-placement-gates-2026-11-18.md`.

**Wall-snap блок восстановлен. Это периодическая коррекция только Z, а не поиск ближайшей стенки или поворот по нормали.** При создании autolight consumer передаёт candidate XYZ; snap не вызывается синхронно из создания. На последующем object update возможны коррекция Z и отдельно снятие snap-флага. Поэтому единственной «окончательной позиции при new» здесь нет: нужны tick, object ID и реальные terrain/frame данные.

Исходник: установленный `C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/Diggles.exe`, preferred base `0x400000`, SHA-256 `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`. Все перечисленные инструкции перечитаны pefile/Capstone из этого EXE. Игра не запускалась. Предыдущие producer/queue/light-exclusion доказательства остаются в `automatic-torches-2026-11-18.md` и `godot/models/native_torches.json`; они здесь не переэкспортируются.

## Флаг → экземпляр → update

| Участок | Подтверждённое действие |
| --- | --- |
| `data/Scripts/classes/items/emitter.tcl:3–11` | `Misc_Light`, `class_snaptowall 1`, `fackel.standard` |
| `0x6108E7–0x610929` | имя `class_snaptowall` (`0x72D104`), регистрация callback `0x614740` |
| `0x614897–0x6148E0` | ненулевой Tcl integer ставит `class+0x2C |= 8`, нулевой очищает этот бит |
| `0x5C7C6B–0x5C7CC7` | class pointer = `object+0xD4`; class bit 8 → `object+0x3D0 |= 0x20000` |
| `0x62EDE7–0x62EE00`, `0x5FFFFF–0x600018` | `def_class` получает native type через `0x5FFFE0`; строка `dummy` (`0x72C670`) даёт 0, записываемый в `class+0x54` |
| `0x5D4694–0x5D46AD` | consumer создаёт объект и очищает `0x690`; snap bit `0x20000` остаётся |
| `0x5D47E7–0x5D483F` | при несовпадении позиции consumer задаёт candidate XYZ через `0x5CD8E0` |
| `0x5CC202–0x5CC43B` | потребитель snap bit внутри object update `0x5CBF70` |

`0x601DF0` вызывает class factory через `class+0x74` (class context `+0x70`). Для обычного класса callback `0x5C7B70` назначается в `0x601B2A–0x601B38`; он ставит флаг, но не вызывает snap-блок. Его дополнительные position/rotation аргументы не превращаются в raycast. Конструктор `0x5C83F0` обнуляет position `+0xC/+0x10/+0x14` и Euler `+0x40/+0x44/+0x48` (`0x5C8430–0x5C8499`). В consumer передана нулевая rotation. Сам разобранный snap-блок **не пишет rotation**. Нормаль стены, side selection, XY offset, LOS и collision-footprint в нём отсутствуют.

## Точный snap_step: `0x5CC202–0x5CC388`

На вход уже должны быть пройдены внешние ветви object update. Локальная eligibility: `(flags & 0x20000) != 0` и `(flags & 0x4000) == 0`. В противном случае пропускаются **обе** стадии ниже.

Коррекция Z выполняется только при `global[0x772400]+0x6C > 100` и `((object_id ^ tick) & 15) == 0`; ID = `object+0xDC`. Это не доказанная единица wall-clock времени.

1. `ix = FISTP(f32(8*object.x))`, `iy = FISTP(f32(8*object.y))`. FPU rounding mode здесь не назначается. Helper получает готовый `Vector2i`, не выбирает режим округления за вызывающего.
2. `0x409450(ix,iy,4)` проверяет `xmin+4 <= ix < xmax-4`, `ymin+4 <= iy < ymax-4`. Bounds — world `+0x94,+0x98,+0x9C,+0xA0`, **sample units**. При false коррекция пропускается, но следующая стадия остаётся.
3. Raw depth byte `0x4093F0` читается в порядке: `(ix,iy)`, `(ix-2,iy)`, `(ix+2,iy)`, `(ix,iy-2)`, `(ix,iy+2)`. Берётся минимум. Native код повторно читает тот же соседний sample при `current_min >= sample`; pure helper читает каждый один раз и требует неизменного snapshot.
4. `z = f32(float(minimum) + f32[0x736FE0])`, где bias = `0.009999999776482582`. Запись через `0x5CD7E0` → `0x5CD8E0`; X/Y сохраняются. Z не делится на 8. **Фильтра `<15` и clamp 14 здесь нет**, в отличие от предшествующего autolight producer.

`0x5CD7E0–0x5CD839` проверяет изменение позиции, вызывает setter и обновляет presentation при `object+0x238==0`. `0x5CD8E0–0x5CDA53` обновляет XYZ, spatial index и dirty flags. Helper возвращает данные; эти side effects должен выполнить интегратор.

## release_step: `0x5CC388–0x5CC43B`

Выполняется на каждом дошедшем сюда update, даже если tick не подошёл для коррекции или sample вышел за margin4.

* Если `class+0x54 != 0`, ничего не делать. Для `Misc_Light` (`dummy`) это поле равно 0.
* Если текущий Z (уже после возможного snap) `< f32[0x736FF0]` (`0.019999999552965164`), снять только `0x20000`.
* Иначе получить raw rectangle `(left,top,right,bottom)` через `0x5CB250`. Если `top < world+0x88`, `bottom >= world+0x90`, `left < world+0x84` или `right >= world+0x8C`, флаг сохранить. Здесь bounds и rect уже в **coarse map units**, не sample units.
* Прочитать byte `+0x18` записей `0x592F10(left,top)`, `(left,bottom)`, `(right,top)`, `(right,bottom)`, именно в таком порядке. Если у любого byte `&3 != 0`, сохранить флаг; если у всех `&3==0`, снять `0x20000` (`0x5CC431`). Значение остальных битов не участвует.

Не следует называть `&3` «solid» или «видимая стена» без отдельного исследования этих flags. Это проверка удержания snap, **не отказ в создании факела**. При minimum=0 получается Z≈0.01, после чего snap снимается в том же update. При неподходящем tick release может сработать раньше первой коррекции. Поэтому нельзя безусловно snap-ить все новые факелы немедленно при `new`.

## Producer прямоугольника: `0x5CB250–0x5CB397`

Если native X или Y `<=0`, возвращаются четыре `-1`. Иначе при anim ID `object+0x39C==-1` или frame `object+0x3A0==-1` берутся bounds точки XY. При обоих существующих ID:

```text
animation = global[0x772400].animation_slots[anim_id]  # +0x5C8, 256 pointers
frame = animation.frames[frame_id]                   # array +0x34, stride 0xE8
left_f   = f32(x + f32(frame[+0x44] * scale))
top_f    = f32(y + f32(frame[+0x48] * scale))
right_f  = f32(x + f32(frame[+0x50] * scale))
bottom_f = f32(y + f32(frame[+0x54] * scale))
rect = (trunc(left_f), trunc(top_f), trunc(right_f)+1, trunc(bottom_f)+1)
scale = f32[0x736FCC] = 0.004999999888241291
```

Accessor slots `0x40B550–0x40B57E`; accessor frames `0x4059A0–0x4059D5`. Здесь `CVTTSS2SI`, то есть truncation к нулю, **не FISTP**, не floor. Правый/нижний результат с `+1` используется прямо как координата corner, не уменьшается на 1. Это animation-frame bounds, а не overlay/collision offsets `object+0x254..0x260` из прежнего исследования.

## Интеграция и оставшаяся граница

Новые `res://scripts/native_torch_placement.gd` и `res://tools/native_torch_placement_self_test.gd` не подключены к main. Чистый API:

```gdscript
var snap_result: Dictionary = Placement.snap_step(native_xyz, native_euler,
    object_flags, native_tick, native_id, native_fistp_xy,
    world_sample_bounds, read_depth_byte)
# Если status=deferred, не считать возвращённую позицию окончательной.
# Получить rect из реального текущего кадра, если он уже доступен.
var released: Dictionary = Placement.release_step(snap_result.position.z,
    snap_result.flags, 0, actual_frame_rect_or_null,
    world_coarse_bounds, read_coarse_cell_flags)
```

Обновить native position/flags, затем использовать существующий общий scene-space/light/particle adapter; helper выдаёт native XYZ/Euler, не Godot world transform. Для построения rect предусмотрен `animation_rect(native_xy, frame_bounds)`, где `frame_bounds=Vector4(frame+44,+48,+50,+54)`. Передавать туда null можно **только** для подтверждённого native anim/frame `-1`; отсутствие извлечённых данных обозначать null непосредственно в `release_step`, который вернёт `deferred`.

**Дополнение интегратора 18.11: соответствие bounds доказано.** Loader `0x4027AC–0x4027C6` читает первые 12 bytes исходных bounds прямо в mesh `+0x44`, следующие 12 — в `+0x50`. Поэтому поля rect — `bounds[0], bounds[1], bounds[3], bounds[4]`. В `native_torches.json.model.frames` экспортированы оба исходных кадра `licht.3db::fackel.standard`; byte span loader включён в проверяемый EXE artifact. Для native XY `(10.25,11.75)` оба кадра дают rect `(10,11,11,13)`; это проверено helper-тестом. Подмена квадратом 1×1 не используется.

**Остаётся до runtime:** внешние object-update gates, живые tick/ID/frame, coarse cell `+0x18` и размещение `0x590E60` с реальным индексом света и registry `0x4753F0`. Новый чистый producer/queue — `native_autolight.gd`: использует supplied RNG/x87/gates, не назначает частоту native tick и FOW-радиус. Main пока не создаёт автоматические факелы; перенос формулы не выдаётся за завершённую игровую механику.

Проверка: Godot 4.7.2 headless выполняет 70 assertions: все пять минимумов, float32 bias, значения 0/15/255 без ложного фильтра, gates/tick/margin, неизменность XY/rotation, отсутствие данных, четыре corner/low2, frame rect и порядок snap→release. Это synthetic unit checks по восстановленной формуле, **не** сравнение с запущенным оригиналом. Project linter: 0 errors / 0 warnings до и после добавления.

```powershell
& 'C:/Users/frant/OneDrive/Рабочий стол/godot/Godot_v4.7.2-stable_win64_console.exe' --headless --path godot --script res://tools/native_torch_placement_self_test.gd
```

Исходная работа агента была ограничена helper/test/report; интегратор дополнил source exporter и JSON доказанными frame bounds и byte spans. Основной отчёт этапа — `manual-work-2026-11-18.md`.

## Byte proof для повторного чтения

SHA-256 сырых EXE bytes, half-open preferred VA spans; `pe.get_data(start-0x400000, end-start)`. Это новые spans, прежний JSON не изменён.

| Start | End exclusive | SHA-256 |
| --- | --- | --- |
| `0x6108e7` | `0x61092f` | `5fa9eb31bbf178e2cd646337b009900f04995228b92132082c5c00d0d20a9dc8` |
| `0x614897` | `0x6148e2` | `ed8399751b384a123ada299e6800a54d3e84655c170a94cadb5aff9ef8de148f` |
| `0x5c7c6b` | `0x5c7cc7` | `c7983169179852beaeafbd2676f1a6e7bc561d795a9899473ceebe3925981e30` |
| `0x5fffff` | `0x600018` | `d8ee07c8b9bc92fe3a53fbfa768df2ebe8710fe0b96b3d0f855fade429ae5966` |
| `0x62ede7` | `0x62ee00` | `10e444f1b31cc27d1caf3f204befc44cd9c050fdd027f3adcfcb01e27ba47523` |
| `0x5cc202` | `0x5cc388` | `a060fa7218538663598942949830455f3c7987eca1533fb7217af3672d530b5c` |
| `0x5cc388` | `0x5cc43b` | `2fef40bbd36ce182c73cb9fd8fe151c95a36155aefb12a1fde81519926e54faa` |
| `0x409450` | `0x40949b` | `0e85f85c9528fc9542bece28cb351218db0d4a1f3018170e54486aed2339b1f4` |
| `0x5cb250` | `0x5cb399` | `67bd35ef47ba276cbdd4d83adf982787434bd4579a0a346e93126b9728d5adc5` |
| `0x5cd7e0` | `0x5cd83c` | `5f0d24bbfee3ee66659204a231bf18f68e4d1704f8b338a5fd33650664cf30a6` |
| `0x5cd8e0` | `0x5cda55` | `ca1ab12aa36e8d74534456e76a1363279f774ea44b6c99cb6247718e9c0dfe0d` |
