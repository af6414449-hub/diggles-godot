# Место для копания, синие пещеры и первая ветка сна — 18.11.2026

В обычной multiplayer-сцене поле увеличено с44×24 до128×128. Стартовый шаблон помещён со смещением(40,40); вокруг доступен изменяемый грунт. Пещерные области и их hover-контур синие; коридоры зелёные. Исправлена ошибка клика пещеры: код прибавлял(16,32), хотя native_cave_brush_cells уже вычитает этот anchor. Preview и commit теперь используют одну позицию указателя.

## Поле: исходные данные и адаптер

`tools/export_playable_world_space.py` проверяет исходный BDB SHA-256, block0, support15, четыре высоты15 и исходную плоскую поверхность Z14.5. Материал взят у существующей ячейки(13,1): flags2/material_low2, attribute4. Это исходное семейство C; новая текстура не создавалась. Конфигурация сохранена отдельно в `godot/models/playable_world_space.json`; прежние экспортированные PMP/BDB/profile manifests не переписываются.

`playable_world_space.gd` меняет только runtime embedding, после проверки исходного шаблона и до построения сцены. Все943 импортированных block refs/flags сохранены с переносом. Вместе перемещаются объекты, акторы, свет, горизонты, focus и исходная navigation map. Native world offset компенсирует local shift: source-координаты исходной сцены прежние. Три object navigation obstacles сохранены.

Новый грунт использует тот же native transition kernel, изменение четырёх BDB ссылок, dirty navigation producer и mesh/collision rebuild. Navigation расширена до1024×1024 packed bytes. Ближайший surface sample ищется в ограниченном прямоугольнике вместо полного прохода по миллиону samples. Предпросмотр удара копирует только записываемые16 записей facts вместо всего поля; проверено отсутствие изменений живого состояния.

Размер, положение шаблона, равномерный внешний грунт и варианты текстуры — **host choices**. Это не перенос lg_start. Исходные multiplayer scripts вызывают map create/lg_set_area/lg_start/apply_level, но полная генерация мира600×600, дополнительных природных пещер, ресурсов и streaming ещё не восстановлена. Исходный шаблон не выдаётся за полную карту оригинала.

## Цвет и размещение пещеры

Бит8 отделяет cave marks от corridor marks при построении mesh. Обе области используют прежнюю геометрию контура и заполнения с разными material. Для cave hover остаётся только толстый контур. Конкретные RGB/alpha — presentation adapter по требованию пользователя, а не извлечённый native shader constant.

Проверка выполняет экранный клик в(110.25,110.25), получает native cursor(110,110) и сравнивает каждую помеченную ячейку с footprint предпросмотра. Повторное прибавление anchor удалено. Пространства хватает и для крупнейшей исходной кисти пещеры.

## Сон: что перенесено

Из `z_spare_main.tcl`, `z_spare_procs.tcl`, `sparetimetunes.tcl` и `mann.3db` экспортирован отдельный пакет. Подтверждённые aliases:

| Alias | Исходный clip | Кадры |
|---|---|---:|
| laydown | stand_zu_schlafen |15|
| sleepside | schlafen_boden_loop |11|
| sleeptostand | schlafen_zu_stand |7|

33 исходных кадра используют имеющиеся текстуры; mesh загружаются лениво и разделяются между акторами.

`native_floor_sleep.gd` допускает только **fresh emergency sleep branch**: пустые future/history/goal, goal_reached2, previous emergency0, отсутствие еды/госпиталя/fun stations. Оригинальная sparetime_decide_occup исполняется системным Tcl для10 контрольных случаев. Учитываются urgent-health branch, приоритет болезни, порог0.5, цели0.6/0.98, strict `>` и minimum-goal gate. Tcl сортирует строками: для scientific-notation values runtime явно отказывается от неподдерживаемого fresh решения. Это не общий алгоритм «выбери самую низкую шкалу».

Свободный вне смены уставший актор может начать сон после строго более5 игровых секунд idle. Используется безопасное текущее место на полу с navigation support и расстоянием до другого гнома≥2. Состояние хранит локальную reservation. Native get_place/placelock registry, поиск грибов, стен и кроватей не перенесены. Предварительное rotate_toangle остаётся зависимостью; host сохраняет текущую ориентацию.

Очередь исполняет исходное compound `play_anim laydown; sparetime_start_sleep`: is_sleeping включается в том же dispatch, хотя laydown ещё блокирует следующую запись. В sparetime_slp_loop бодрость увеличивается на0.004×1.1 **один раз перед двумя sleepside clips**. Отдельные source needs ticks продолжаются с occupation=slp. По завершении цели или наступлении работы очередь дожидается текущих анимаций и добавляет sleeptostand; флаг сна снимается сразу при постановке пробуждения.

Ручное задание отменяет старые callbacks, освобождает reservation и ставит вставание перед walk/dig. Быстрый повторный приказ и приказ во время вставания сохраняют пробуждение. Это ограниченный host cleanup; полный stop_prod/disturbance protocol, mood penalties, particles, dream/facial animation и динамические причины прерывания пока не перенесены. Оngoing arbitration до достижения текущей цели также ограничена: полный hysteresis/future/history/min-goal переключатель предстоит подключить. Питание, речь, мебель и полный AI этим этапом не объявляются готовыми.

## Проверки

`tools/check_world_space_and_sleep.py`:17 сценариев,1322 подсчитанных checks/assertions, без ошибок и предупреждений. Native profile дополнительно проверен своим итоговым marker. [Все логи и JSON](world-space-sleep-2026-11-18/).

- World space:24 проверки. Все943 исходные ячейки сохранены; largest cave fits; cave hover blue; screen click совпадает с preview. Одна команда выкапывает20 ячеек коридора за старой границей; гном проходит в новый участок. Отдельная мутация проверяет substrate; всего21 terrain revision.
- Floor sleep:53 проверки. Tcl oracle,15/11/7 кадров, async compound ordering, gain по циклу, pause, natural wake, manual replacement/stale callback, повтор приказа и начало смены.
- Регрессии: terrain kernel76, terrain render556, corridor input85, connected manual region27, wall continuation16, depth route19, surface walk45, needs/clock194, life runtime27, actor tasks76, task runtime39, parallel work21, world model light31, torches33.
- Общий Godot validate:101 ресурсов,0 errors/0 warnings. Убрано прежнее integer division warning в performance probe с сохранением индекса median.
- Smoke всех3 сцен с input fuzzing:0 errors/0 warnings. Оба новых exporter `--check` проходят.

Проверки headless. GPU-ракурс после изменений и FPS телефона не измерены; прежнее ограничение автоматической проверки разрешений для GPU не обходилось. APK не пересобирался. Проект Minimax не редактировался и не запускался.

## Следующий шаг

Подтвердить рабочий участок и совпадение синего hover/commit в Godot. Затем переносить native генератор/размещение окружающих пещер отдельно от нынешнего substrate и полную leisure decision machine отдельно от ограниченного floor-sleep action. Для масштабирования нужны более узкие dirty mesh buckets/видимость;600×600 нельзя просто включить тем же способом. По AI остаются resource/place registry, ongoing hysteresis, вращение перед сном, еда и stop_prod penalties. Задачи света, FOW, пыли/сколов, досок, Calc1 и анимации воды сохранены.
