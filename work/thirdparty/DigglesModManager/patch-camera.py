"""Diggles: свободная камера (панорамирование за пределы вскопанной области)
и расширенный диапазон зума.

Что делает патч (версия 2, без code cave)
----------------------------------------
1) ГРАНИЦЫ КАМЕРЫ = ПОЛНЫЕ ГРАНИЦЫ КАРТЫ
   Границы камеры лежат в app+0xa328 + owner*0x10 (4 int: x0,y0,x1,y1 в ячейках).
   Обычно они растут по мере снятия тумана (= "вскопанная область"), и
   FUN_00529570 / winroot-tick клампят camX/camY этим прямоугольником.
   В движке есть штатная ветка "показать всю карту" (CFogOfWar::UpdateFoW,
   0x0057fac2): она копирует map+0x84 (полные границы карты) во все 8
   прямоугольников камеры. Патч заставляет эту ветку выполняться каждый
   игровой тик, но БЕЗ раскрытия тумана (цикл раскрытия пропускается),
   чтобы не трогать туман ИИ.

   Правки в FUN_0057F5C0:
     P1 0x0057fabd  jmp 0x57fc72 -> jmp 0x57fac2
         (после штатной обработки тумана перейти в ветку "вся карта")
     P2 0x0057fac9  je -> 6x nop
         (игнорировать флаг "показать всю карту": он всегда сбрасывается)
     P3 0x0057faf8  nop(8) -> jmp 0x57fb3b + 3 nop
         (войти в цикл копирования с eax = [0x772400] = app:
          в исходном коде eax берётся из "mov eax,[0x772400]" в конце
          итерации, а при входе с другого пути он был бы мусором)
     P4 0x0057fb5a  jge 0x57fc64 -> jmp 0x57fc64
         (пропустить цикл раскрытия тумана 0xff - оставить только копирование)

2) ДИАПАЗОН ЗУМА [1.0 .. ZOOM_MAX] (было [1.0 .. 2.5])
   CGameThread::Draw клампит зум в ветке "обычная игра":
     0x006b6968  movss xmm6,[0x737138]  = 1.0   нижняя граница (ПРИБЛИЖЕНИЕ)
     0x006b6973  movss xmm5,[0x7373d8]  = 2.5   ВЕРХНЯЯ граница (ОТДАЛЕНИЕ)
     0x006b697e  maxss / 0x006b6997 minss -> zoom = min(upper, max(lower, zoom))
   zoom - ОБРАТНАЯ величина: размер объекта на экране = 300.0/zoom
   (CDisplay::DrawObjects). Значит БОЛЬШИЙ zoom = МЕЛЬЧЕ объекты = ОТДАЛЕНИЕ.
   Отдаление ограничено ВЕРХНЕЙ границей, приближение - нижней.
     P5 0x006b6968  константа 1.0 (0x737138) - оставляем как есть
        (раньше здесь был 0.1 - это дало "сильное приближение", не отдаление)
     P6 0x006b6973  верхняя граница зума -> значение из таблицы ZOOM_MAX_TABLE
        (все константы уже есть в .rdata exe, ничего дописывать не нужно):
        2.5 (штатно) / 4.0 / 6.0 / 8.0 / 10.0 / 12.0 / 16.0 / 50.0
        По умолчанию патчится 16.0; выбрать другое:
            python patch-camera.py --zoom-max=10.0
     P7 0x00452bf9  ТОТ ЖЕ кламп, но в рендерере (CDXExecBuf::Render):
        "movss xmm1,[2.5]" -> "movss xmm1,[<тот же предел>]"
        Рендерер сам по себе зажимает зум в [1.0 .. 2.5] и передаёт это
        значение в пост-эффект. При реальном зуме > 2.5 эффект считает
        "радиус видимости" по старому зуму -> на большом отдалении весь
        экран закрашивается в чёрное. Поэтому верхнюю границу поднимаем
        и здесь (иначе P6 и P7 разъезжаются).

3) МНОЖИТЕЛЬ ПАНОРАМИРОВАНИЯ - править НЕ нужно
   Множитель = (zoom-1)*app[0x198]*0.2+1, где app+0x198 - это опция
   Input\\ZoomSpeedFactor (в реестре = 0), т.е. множитель всегда 1.0
   и инверсии панорамы при zoom<1 не происходит. (Раньше app+0x198
   ошибочно считался опцией Screen\\Brightness - это не так.)

Почему это безопасно при ASLR
-----------------------------
Все правки - либо относительные переходы (jmp/je), либо immediate/константа
в .rdata. У адресов в .reloc нет записей HIGHLOW на RVA 0x17FABE/0x17FAC9/
0x17FAF8/0x17FB5B => загрузчик их не чинит. Абсолютные адреса есть только
в P5 (0x737138) и P6 (0x7374e0) - на оба есть HIGHLOW-записи в .reloc
(RVA 0x2B696C и 0x2B6977), поэтому загрузчик пересчитает их правильно
(адрес нужной float-константы в загруженном образе).

Запуск:
    python patch-camera.py                  # наложить патч (зум до 16.0)
    python patch-camera.py --zoom-max=10.0  # другая верхняя граница зума
    python patch-camera.py --revert         # откатить (вернуть .camera.orig)
    python patch-camera.py --check          # только проверить (+ текущий диапазон)
"""
import hashlib
import os
import shutil
import struct
import sys

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
EXE = os.path.join(GAME, "Diggles.exe")
BAK = os.path.join(GAME, "Diggles.exe.camera.orig")

# ------------------------------------------------------------------ правки
# (VA, допустимые старые байты, новые байты, описание)
PATCHES = [
    (0x0057FABD, (bytes.fromhex("E9 B0 01 00 00"),),
     bytes.fromhex("E9 00 00 00 00"),
     "P1 после обработки тумана -> штатная ветка 'вся карта'"),
    (0x0057FAC9, (bytes.fromhex("0F 84 E6 01 00 00"),),
     bytes.fromhex("90 90 90 90 90 90"),
     "P2 не проверять флаг 'раскрыть всю карту'"),
    (0x0057FAF8, (bytes.fromhex("0F 1F 84 00 00 00 00 00"),),
     bytes.fromhex("E9 3E 00 00 00 90 90 90"),
     "P3 вход в цикл копирования с eax=app"),
    (0x0057FB5A, (bytes.fromhex("0F 8D 04 01 00 00"),),
     bytes.fromhex("E9 05 01 00 00 90"),
     "P4 пропустить раскрытие тумана (только границы камеры)"),
    # P5: нижняя граница зума - 1.0 (0x737138).
    #     (это предел ПРИБЛИЖЕНИЯ; 0.1 из 0x737034 давал "сильное приближение")
    (0x006B6968, (bytes.fromhex("F3 0F 10 35 38 71 73 00"),
                  bytes.fromhex("F3 0F 10 35 8C 70 73 00"),
                  bytes.fromhex("F3 0F 10 35 34 70 73 00")),
     bytes.fromhex("F3 0F 10 35 38 71 73 00"),
     "P5 минимальный зум 1.0 (нижняя граница)"),
]

# ------------------------------------------------------------------ P6: верхняя граница зума
# Это и есть предел ОТДАЛЕНИЯ (zoom - обратная величина: 300/zoom = размер объекта).
# Значения берутся из готовых float-констант в .rdata exe - дописывать ничего не нужно.
ZOOM_MAX_TABLE = {
    2.5: 0x7373D8,    # штатно (оригинал)
    4.0: 0x7374A0,
    6.0: 0x7374E0,
    8.0: 0x73752C,
    10.0: 0x737534,
    12.0: 0x737540,
    16.0: 0x73756C,
    50.0: 0x7375CC,   # экстремум: обзор шире карты, объекты ~6 px
}
ZOOM_MAX_DEFAULT = 16.0


def zoom_max_patch(value):
    """(старые байты, новые байты) для P6 с заданной верхней границей зума."""
    addr = ZOOM_MAX_TABLE[value]
    olds = tuple(bytes.fromhex("F3 0F 10 2D") + struct.pack("<I", a)
                 for a in ZOOM_MAX_TABLE.values())
    new = bytes.fromhex("F3 0F 10 2D") + struct.pack("<I", addr)
    return olds, new


def render_zoom_patch(value):
    """(старые байты, новые байты) для P7: кламп зума в рендерере.

    CDXExecBuf::Render (0x00452bf9) тоже клампит зум в [1.0 .. 2.5] и
    передаёт это значение в пост-эффект. Если зум реально больше 2.5,
    эффект считает "видимый радиус" по старому зуму и закрашивает экран
    в чёрное. Поэтому верхнюю границу надо поднять и здесь.
    """
    addr = ZOOM_MAX_TABLE[value]
    olds = tuple(bytes.fromhex("F3 0F 10 0D") + struct.pack("<I", a)
                 for a in ZOOM_MAX_TABLE.values())
    new = bytes.fromhex("F3 0F 10 0D") + struct.pack("<I", addr)
    return olds, new


def sha(data):
    return hashlib.sha256(data).hexdigest().upper()


def main():
    args = sys.argv[1:]
    mode = args[0] if args else "apply"

    # верхняя граница зума: --zoom-max=16.0 (по умолчанию ZOOM_MAX_DEFAULT)
    zoom_max = ZOOM_MAX_DEFAULT
    for a in args:
        if a.startswith("--zoom-max="):
            zoom_max = float(a.split("=", 1)[1])
    if zoom_max not in ZOOM_MAX_TABLE:
        print("ABORT: zoom-max %s нет в таблице: %s"
              % (zoom_max, sorted(ZOOM_MAX_TABLE)))
        return 3

    if not os.path.exists(EXE):
        print("NOT FOUND:", EXE)
        return 2

    data = bytearray(open(EXE, "rb").read())

    import pefile
    pe = pefile.PE(EXE)
    base = pe.OPTIONAL_HEADER.ImageBase

    def off(va):
        return pe.get_offset_from_rva(va - base)

    p6_olds, p6_new = zoom_max_patch(zoom_max)
    p7_olds, p7_new = render_zoom_patch(zoom_max)
    patches = list(PATCHES) + [
        (0x006B6973, p6_olds, p6_new,
         "P6 максимальный зум (верхняя граница) -> %.1f" % zoom_max),
        (0x00452BF9, p7_olds, p7_new,
         "P7 кламп зума в рендерере -> %.1f (то же, что P6)" % zoom_max),
    ]
    offs = [(va, off(va), olds, new, desc) for va, olds, new, desc in patches]

    def zoom_bounds():
        """Текущие значения нижней/верхней границ зума из байтов exe."""
        out = []
        for va in (0x006B6968, 0x006B6973):
            o = off(va)
            addr = struct.unpack_from("<I", data, o + 4)[0]
            try:
                fo = pe.get_offset_from_rva(addr - base)
                val = struct.unpack_from("<f", data, fo)[0]
            except Exception:  # noqa: BLE001
                val = None
            out.append((addr, val))
        return out

    if mode == "--check":
        print("exe sha256 :", sha(data))
        for va, o, olds, new, desc in offs:
            cur = bytes(data[o:o + len(new)])
            state = ("PATCHED" if cur == new
                     else ("ok" if cur in olds else "!! UNEXPECTED"))
            print("%08X %-52s %-14s %s" % (va, desc, state, cur.hex(" ")))
        lo, hi = zoom_bounds()
        print("диапазон зума: [%s .. %s]" % (lo[1], hi[1]))
        print("  нижняя константа %08X, верхняя %08X" % (lo[0], hi[0]))
        print("backup     :", os.path.exists(BAK))
        pe.close()
        return 0

    if mode == "--revert":
        if not os.path.exists(BAK):
            print("NO BACKUP:", BAK)
            pe.close()
            return 2
        pe.close()
        shutil.copyfile(BAK, EXE)
        print("reverted. sha256 =", sha(open(EXE, "rb").read()))
        return 0

    # ---- apply ----
    problems = []
    for va, o, olds, new, desc in offs:
        cur = bytes(data[o:o + len(new)])
        if cur != new and cur not in olds:
            problems.append("%08X %s: unexpected %s" % (va, desc, cur.hex(" ")))
    if problems:
        for p in problems:
            print("ABORT:", p)
        pe.close()
        return 3

    # exe нельзя держать открытым (pefile) при записи
    pe.close()

    if not os.path.exists(BAK):
        shutil.copyfile(EXE, BAK)
        print("backup created:", BAK, sha(open(BAK, "rb").read()))

    for va, o, olds, new, desc in offs:
        data[o:o + len(new)] = new

    # запись в exe делаем через временный файл: прямое усечение файла в
    # папке Steam блокируется фильтром (OSError 22)
    tmp = os.path.join(os.environ.get("TEMP", "."), "diggles_camera_patch.exe")
    open(tmp, "wb").write(bytes(data))
    shutil.copyfile(tmp, EXE)
    try:
        os.remove(tmp)
    except OSError:
        pass

    d = open(EXE, "rb").read()
    ok = all(bytes(d[o:o + len(new)]) == new for va, o, olds, new, desc in offs)
    print("patched   :", ok, "sha256 =", sha(d))
    for va, o, olds, new, desc in offs:
        print("  %08X off %08X  %-52s %s" % (va, o, desc, d[o:o + len(new)].hex(" ")))
    print("диапазон зума: [1.0 .. %.1f]" % zoom_max)
    return 0 if ok else 4


if __name__ == "__main__":
    sys.exit(main())
