import io

p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\docs\plan\queue-2026-11-19.md"
raw = io.open(p, "rb").read()
bom = raw.startswith(b"\xef\xbb\xbf")
s = raw.decode("utf-8-sig")
nl = "\r\n" if "\r\n" in s else "\n"
lines = s.split(nl)

def find(sub, start=0):
    for i in range(start, len(lines)):
        if sub in lines[i]:
            return i
    return -1

# 1) scale block (line contains GetHMap + ROUND(x*8.0))
i = find("ROUND(x*8.0)")
if i < 0:
    print("MISS scale")
else:
    print("scale at", i + 1, "->", repr(lines[i][:40]))
    lines[i:i + 2] = [
        "**Шкала (исправлено в §0.18):** байт — это **уровень**, world-Z = **`7.0 + 0.5*v` клетки**",
        "(`FUN_004c8220:33,44`), диапазон 7.0…14.5, верхняя плоскость = 15.0. Горизонталь —",
        "адресация 1/8 клетки (`GetHMap`: `ROUND(x*8.0)`), 64 отсчёта на клетку; **вершины",
        "геометрии — в клетках**.",
    ]

# 2) leftover fragment line about diagonals
j = find("диагонали учитываются")
if j < 0:
    print("MISS diag")
else:
    print("diag at", j + 1)
    lines[j:j + 1] = [
        "Отдельных 45-граней в движке нет: диагонали учитываются только при сглаживании",
        "точки опоры (`GroundPos`).",
    ]

out = nl.join(lines)
data = out.encode("utf-8")
if bom:
    data = b"\xef\xbb\xbf" + data
io.open(p, "wb").write(data)
print("written, lines:", len(lines))
