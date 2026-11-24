# -*- coding: utf-8 -*-
"""Определяет, как basis_columns соотносятся с вектором (колонки или строки)."""
import io, json, os

MODELS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
with io.open(os.path.join(MODELS, "dwarf_attachments.json"), encoding="utf-8") as f:
    att = json.load(f)
mann = att["models"]["mann.3db::mann"]

def mul_col(bc, v):   # bc = список колонок
    return [bc[0][0]*v[0]+bc[1][0]*v[1]+bc[2][0]*v[2],
            bc[0][1]*v[0]+bc[1][1]*v[1]+bc[2][1]*v[2],
            bc[0][2]*v[0]+bc[1][2]*v[1]+bc[2][2]*v[2]]

def mul_row(bc, v):   # bc = список строк
    return [bc[0][0]*v[0]+bc[0][1]*v[1]+bc[0][2]*v[2],
            bc[1][0]*v[0]+bc[1][1]*v[1]+bc[1][2]*v[2],
            bc[2][0]*v[0]+bc[2][1]*v[1]+bc[2][2]*v[2]]

for fx in att["fixtures"]:
    if fx["clip"] != "gehen_loop" or fx["frame"] != 0 or fx["slot"] != 0:
        continue
    clip = mann["clips"][fx["clip"]]
    slot = mann["meshes"][str(clip["mesh_indices"][fx["frame"]])]["slots"][str(fx["slot"])]
    bc = slot["basis_columns"]
    origin = slot["origin_render"]
    p = fx["probe_native"]
    exp = fx["expected_render"]
    diff = [exp[i] - origin[i] for i in range(3)]
    print("basis_columns =", json.dumps(bc))
    print("expected - origin =", [round(v, 8) for v in diff])
    print("0.005*col*p      =", [round(v, 8) for v in [0.005*x for x in mul_col(bc, p)]])
    print("0.005*row*p      =", [round(v, 8) for v in [0.005*x for x in mul_row(bc, p)]])
    print("err col=%.3e row=%.3e" % (
        max(abs(0.005*mul_col(bc, p)[i] - diff[i]) for i in range(3)),
        max(abs(0.005*mul_row(bc, p)[i] - diff[i]) for i in range(3))))
    break
