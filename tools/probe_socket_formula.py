# -*- coding: utf-8 -*-
"""Сверяет формулу локального трансформата с эталонными fixtures из dwarf_attachments.json."""
import io, json, os

PROJECT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
MODELS = os.path.join(PROJECT, "godot", "models")

with io.open(os.path.join(MODELS, "dwarf_attachments.json"), encoding="utf-8") as f:
    att = json.load(f)
mann = att["models"]["mann.3db::mann"]

def col_basis(bc):
    return [[bc[0][i], bc[1][i], bc[2][i]] for i in range(3)]

def mul(m, v):
    return [m[0][0]*v[0]+m[0][1]*v[1]+m[0][2]*v[2],
            m[1][0]*v[0]+m[1][1]*v[1]+m[1][2]*v[2],
            m[2][0]*v[0]+m[2][1]*v[1]+m[2][2]*v[2]]

def sub(a, b):
    return [a[i]-b[i] for i in range(3)]

def add(a, b):
    return [a[i]+b[i] for i in range(3)]

def scale(a, s):
    return [v*s for v in a]

fixtures = att.get("fixtures") or []
print("fixtures:", len(fixtures))
if fixtures:
    print(json.dumps(fixtures[0], ensure_ascii=False, indent=1))

ok_count = {}
for fx in fixtures[:40]:
    clip = mann["clips"].get(fx["clip"])
    if not clip:
        continue
    mi = clip["mesh_indices"][fx["frame"]]
    slot = mann["meshes"][str(mi)]["slots"][str(fx["slot"])]
    bc = slot["basis_columns"]
    B_col = col_basis(bc)          # если это колонки: p' = B_col * p
    B_row = bc                     # если это строки: p' = B_row * p
    origin = slot["origin_render"]
    p = fx["probe_native"]
    exp = fx["expected_render"]
    cands = {
        "col*+orig":        add(mul(B_col, p), origin),
        "row*+orig":        add(mul(B_row, p), origin),
        "col*+orig_native": add(mul(B_col, p), [origin[0]/0.005, -origin[1]/0.005, origin[2]/0.005]),
    }
    for name, val in cands.items():
        for s, tag in ((1.0, "x1"), (0.005, "x0.005")):
            diff = max(abs(val[i]*s - exp[i]) for i in range(3))
            ok_count.setdefault("%s %s" % (name, tag), []).append(diff)
    # вариант: probe уже в render units
    for name, val in (("col*probe/200", add(mul(B_col, [v/200.0 for v in p]), origin)),):
        diff = max(abs(val[i] - exp[i]) for i in range(3))
        ok_count.setdefault(name, []).append(diff)

for name, diffs in ok_count.items():
    print("%-24s max_err=%.6g  mean=%.6g" % (name, max(diffs), sum(diffs)/len(diffs)))
