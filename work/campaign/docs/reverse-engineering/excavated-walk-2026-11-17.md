# Пройден реально выкопанный участок — 17.11.2026

Контрольный цикл в Godot: четыре corridor points `(1,15),(2,15),(2,16),(1,16)` → четыре worker callback/accepted BDB steps → новый пол Y=16.5 → спуск и обратный подъём на Y=14.5.

До копания sample `(12,132)` имеет flags0, body probe `(12,124)` имеет H15; назначение пути отвергается, вертикальный physics ray внутри массива не находит пола. После копания flags3, H11; ray попадает точно в local `(1.5,-16.5,14.5)`. Открылись 64 source navigation samples; завершённый маршрут действительно вошёл в 16 из них. Оба маршрута содержат по 25 samples; применяются исходные climb-down/up и переходы. Ходьба не увеличивает terrain revision4.

Исправлен UI dispatch: новый доступный sample, стеновая цель и цель за старым X-диапазоном направляются в surface route. Прежний порог `abs(targetY−14.5)>0.25` мог отправить неглубокий новый участок в старый floor adapter. Regression tap `(7,118)`/local `(0.875,14.75)` теперь выбирает правильный route. Подтверждено через обычный `_handle_tap` в режиме «Выбор».

`NativeWalkmap.is_newly_navigable` сравнивает актуальный известный bit0 с сохранённым исходным PMP byte, без выдумывания окружения. Assigned/completed history сохраняет terrain/nav revisions, новую цель и число реально достигнутых новых samples. Source byte producer и BDB kernel не заменялись.

`excavated_walk_self_test.gd`: 37 assertions headless для authored_2p/4p, 40 OpenGL с тремя дополнительными captures. `before_dig.png`, `after_dig.png`, `new_floor_reached.png` и общие ракурсы/scene_space.json находятся в одноимённом каталоге; крупные планы просмотрены. Оригинальные mutable package и PMP walkmap прошли exporter `--check`; lint42 и smoke трёх сцен — 0 ошибок/предупреждений. Wall dig22, parallel21, gestures37 проходят повторно.

Это доказательство рабочего host-цикла на исходных данных, не live-трасса оригинала. BFS, picking plane, скорость, scheduler и один accepted step на clip остаются адаптерами. APK не пересобирался.

Последующее сообщение пользователя добавило четыре направления: проскальзывание бега (сверить время/root-motion по EXE), отказ копания вверх, реальные attachments кирки/головных уборов и выбор целей справа. Эти вопросы продолжают текущую разработку; факт прохода нового участка уже зафиксирован.
