# -*- coding: utf-8 -*-
"""Печатает оси сокета в пространстве тела: чтобы правильно ориентировать кирку."""
import io, json, os

MODELS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
with io.open(os.path.join(MODELS, "dwarf_attachments.json"), encoding="utf-8") as f:
    att = json.load(f)
mann = att["models"]["mann.3db::mann"]

def basis_matrix(bc):
    """bc = список из трёх массивов; трактуем как колонки матрицы."""
    return [[bc[0][i], bc[1][i], bc[2][i]] for i in range(3)]

def axes(bc):
    B = basis_matrix(bc)
    ax = [B[0], B[1], B[2]]          # B*e0, B*e1, B*e2 (в пространстве тела, Y вверх)
    return ax

for clip_name, frames in (("stand_anim_b", (0,)), ("buddeln_oben_normal", (0, 4, 6)),
                          ("werkzeug_raus_a", (0, 2, 4)), ("kletter_hoch_loop", (0, 9))):
    clip = mann["clips"][clip_name]
    print("===", clip_name)
    for fi in frames:
        s = mann["meshes"][str(clip["mesh_indices"][fi])]["slots"]["0"]
        ax = axes(s["basis_columns"])
        o = s["origin_render"]
        print("  f%-2d origin(нативн.)=(%7.1f,%7.1f,%7.1f)" % (
            fi, o[0]*200, -o[1]*200, o[2]*200))
        for i, name in enumerate("XYZ"):
            v = ax[i]
            print("        ось %s -> (%6.2f,%6.2f,%6.2f)" % (name, v[0], v[1], v[2]))
