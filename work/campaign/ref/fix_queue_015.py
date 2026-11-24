import io, sys

p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\docs\plan\queue-2026-11-19.md"
raw = io.open(p, "rb").read()
bom = raw.startswith(b"\xef\xbb\xbf")
s = raw.decode("utf-8-sig")
nl = "\r\n" if "\r\n" in s else "\n"
lines = s.split(nl)

def find(pred, start=0):
    for i in range(start, len(lines)):
        if pred(lines[i]):
            return i
    return -1

def repl_block(anchor, nlines, new_lines, label):
    """Replace nlines lines starting at the anchor line with new_lines."""
    global lines
    i = find(lambda l: anchor in l)
    if i < 0:
        print("MISS:", label)
        return False
    lines[i:i + nlines] = new_lines
    print("OK:", label, "@line", i + 1)
    return True

# 1) scale of the height byte
repl_block(
    "**Масштаб: 8 единиц движка на клетку**",
    2,
    [
        "**Шкала (исправлено в §0.18):** байт — это **уровень**, world-Z = **`7.0 + 0.5*v` клетки**",
        "(`FUN_004c8220:33,44`), диапазон 7.0…14.5, верхняя плоскость = 15.0. Горизонталь —",
        "адресация 1/8 клетки (`GetHMap`: `ROUND(x*8.0)`), 64 отсчёта на клетку; **вершины",
        "геометрии — в клетках**.",
    ],
    "scale",
)

# 2) cell+0x3C is flags, not a copy of the height grid
repl_block(
    "под-блок хранит ту же сетку 8×8 в первых 64 байтах",
    1,
    [
        "под-блок хранит **сетку высот 8×8** в первых 64 байтах, а `cell+0x3C` — **параллельный",
        "массив флагов** на те же 64 отсчёта, а не копию высот (см. §0.18 п.5).",
    ],
    "cell+0x3C",
)

# 3) walls are NOT derived from height differences
repl_block(
    "**Стены движок выводит из перепада высот**",
    2,
    [
        "**«Стены = перепад высот» — ОПРОВЕРГНУТО (§0.18 п.4):** вертикальные стенки движок",
        "строит из состояния выемки (owner-байты `cell+0x34` + различие под-блоков соседей),",
        "а высоты лишь задают Z углов (`FUN_004c6b20:37-145,173`).",
    ],
    "walls",
)

# 4) consequences for the port
repl_block(
    "- «стены из высот» — статус **реконструкция** (факт), а не адаптер;",
    6,
    [
        "- «стены из высот» — **не реконструкция, а ошибка**: в оригинале стены из выемки (§0.18);",
        "- **меша по сетке 8×8 в движке нет** — поверхность это 1 квад на клетку (§0.18 п.1);",
        "- шкала z оригинала: `Z = 7.0 + 0.5*уровень`, уровень 0…15 ⇒ **шаг 0.5 клетки**,",
        "  то есть z = 14.5 / 12.5 / 7.0 — это уровни 15 / 11 / 0 (а не «невозможные полуцелые»);",
        "- порог появления ямы/ребра — **2.0 клетки** (≥4 уровней), перепад **внутри** клетки (§0.18 п.3);",
        "- материал 3 = порода (исправлено в §0.11 п.1 и в отчёте от 20.11).",
    ],
    "consequences",
)

# 5) open items
repl_block(
    "**Открыто:** смысл байта `cell+0x34[owner]`",
    2,
    [
        "**Открыто:** смысл байта `cell+0x34[owner]`; четыре «типа углов» под-блока высот",
        "(+0x40..+0x4C) — это варианты под-блока по 4 направлениям выемки (§0.18 п.5);",
        "расхождение соглашений «уровень vs world-Z» внутри движка (проверяемый тест — §0.18 п.7);",
        "семантика зоны в `sm_draw_stone -exlimit`.",
    ],
    "open",
)

out = nl.join(lines)
data = out.encode("utf-8")
if bom:
    data = b"\xef\xbb\xbf" + data
io.open(p, "wb").write(data)
print("written, lines:", len(lines))
