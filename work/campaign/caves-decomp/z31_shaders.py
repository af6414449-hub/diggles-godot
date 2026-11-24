# -*- coding: utf-8 -*-
"""З31: полный реестр шейдеров (37) с полями записи 0x6C + группы материалов.

Имена id->имя берутся из проверенной таблицы З28 (report.md:3794-3808),
значения полей парсятся из FUN_00457b90 (регистрация шейдеров).
"""
import io, re, os

DEC = r'C:\diggles-ghidra\out\decomp'
ZONE = r'C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp'
OUT_TSV = os.path.join(ZONE, 'z31_shaders.tsv')
OUT_MD = os.path.join(ZONE, 'z31_shaders.md')

NAMES = ['default', 'interface_blend', 'interface_additive', 'interface_blendq',
         'interface_additiveq', 'interface_additive_filtered', 'model_blend',
         'model_solid', 'model_solid_nozwrite', 'model_additive', 'model_additive_glow',
         'model_blend_glow', 'model_blend_nozwrite', 'model_blend_envmap',
         'model_additive_envmap', 'particle_blend', 'particle_additive', 'scape_fow',
         'scape_solid', 'scape_blend', 'scape_multi_urw', 'scape_multi_lav',
         'scape_multi_lav_fow', 'sky_blend', 'sky_blend_multi', 'ground_blend',
         'shadow_blend', 'mouse_blend', 'water_blend', 'sulfur_blend', 'lava_blend',
         'interface_glow', 'obj_glow', 'alpha_light', 'model_solid_invalpha',
         'nolight_noalpha', 'interface_blend_filter']

RE_ALLOC = re.compile(r"((?:local_[0-9a-f]+|piVar2))\s*=\s*\(int \*\)FUN_006ba810\(0x19")
RE_FIELD = re.compile(r"(local_[0-9a-f]+)\[(0x[0-9a-fA-F]+|\d+)\]\s*=\s*(-?0x[0-9a-fA-F]+|-?\d+);")
RE_COMMIT = re.compile(r"FUN_0045aa00\(&((?:local_[0-9a-f]+|piVar2))\)")
RE_STAR = re.compile(r"\*local_24\s*=\s*(-?0x[0-9a-fA-F]+|-?\d+);")


def num(tok):
    return int(tok, 16) if tok.startswith(('0x', '-0x')) else int(tok)


def parse_shaders(path):
    lines = io.open(path, 'r', encoding='utf-8', errors='replace').read().split('\n')
    rows = []
    pending_state = {}
    collecting = False
    n = 0
    for ln in lines:
        if RE_ALLOC.search(ln):
            if n:                       # закрываем предыдущую запись
                rows.append(dict(pending_state))
                pending_state = {}
            collecting = True
            n += 1
            continue
        if collecting:
            if RE_COMMIT.search(ln):
                collecting = False
            continue
        for m in RE_STAR.finditer(ln):
            pending_state[0] = num(m.group(1))
        for m in RE_FIELD.finditer(ln):
            pending_state[num(m.group(2))] = num(m.group(3))
    if n:
        rows.append(dict(pending_state))
    return rows


GROUP_NAMES = ['default', 'additiveonly', 'modelnozwrite']

# Значения по умолчанию записи шейдера — конструктор FUN_00455760_00455760.c:38-67.
# Каждый шейдер (кроме самого `default`) создаётся как копия записи 0,
# поэтому эффективное поле = default, переопределённое явной записью.
DEFAULTS = {
    0: 1,        # +0x00
    1: 1,        # +0x04
    2: 4,        # +0x08
    3: 0,        # +0x0C
    4: 0,        # +0x10
    5: 8,        # +0x14
    6: 0,        # +0x18
    7: 2,        # +0x1C
    8: 1,        # +0x20
    9: 0,        # +0x24
    10: 3,       # +0x28
    11: 1,       # +0x2C
    12: 0,       # +0x30
    13: 0,       # +0x34
    14: 0xFFFFFF,  # +0x38
    15: 0,       # +0x3C
    16: 0,       # +0x40
    17: 1,       # +0x44
    18: 0, 19: 0, 20: 0, 21: 0, 22: 0, 23: 0, 24: 0,
}


def parse_groups():
    """FUN_0045a130 — три захардкоженные группы материалов.

    Порядок в файле: имя-строка -> FUN_0045ac70 (регистрация группы)
                     -> 12 записей слотов (смещение 0x00..0x2C, шаг 4).
    """
    p = os.path.join(DEC, 'FUN_0045a130_0045a130.c')
    lines = io.open(p, 'r', encoding='utf-8', errors='replace').read().split('\n')
    re_commit = re.compile(r"FUN_0045ac70\(&local_14\)")
    re_slot = re.compile(
        r"\*\(undefined4 \*\)\(iVar1 \+ (?:(0x[0-9a-fA-F]+|\d+) \+ )?[^*]*\* 0x48\) = (0x[0-9a-fA-F]+|\d+);")
    groups = []
    cur = None
    for ln in lines:
        if re_commit.search(ln):
            if cur is not None:
                groups.append(cur)
            cur = {'slots': {}}
            continue
        m = re_slot.search(ln)
        if m and cur is not None:
            off = num(m.group(1)) if m.group(1) else 0
            cur['slots'][off // 4] = num(m.group(2))
    if cur is not None:
        groups.append(cur)
    for i, g in enumerate(groups):
        g['name'] = GROUP_NAMES[i] if i < len(GROUP_NAMES) else 'group%d' % i
    return groups


def effective(st):
    """Эффективные значения полей: default + явные переопределения."""
    out = dict(DEFAULTS)
    out.update(st)
    return out


def main():
    rows = parse_shaders(os.path.join(DEC, 'FUN_00457b90_00457b90.c'))
    assert len(rows) == len(NAMES), (len(rows), len(NAMES))
    rows = [effective(r) for r in rows]

    tsv = io.StringIO()
    tsv.write('id\tname\t' + '\t'.join('+%02X' % (i * 4) for i in range(25)) + '\n')
    for i, st in enumerate(rows):
        tsv.write('%d\t%s\t%s\n' % (i, NAMES[i], '\t'.join(str(st.get(k, 0)) for k in range(25))))
    io.open(OUT_TSV, 'w', encoding='utf-8', newline='\n').write(tsv.getvalue())

    md = io.StringIO()
    md.write('# З31. Полный реестр шейдеров Diggles.exe (37 техник)\n\n')
    md.write('Источник: `FUN_00457b90_00457b90.c` — регистрация шейдеров, запись 0x6C байт.\n')
    md.write('Поля записи: +0x00..+0x40 — 17 dword, +0x44..+0x63 — 8 dword, ')
    md.write('+0x64 — имя, +0x68 — имя родителя.\n')
    md.write('Каждый шейдер кроме `default` создаётся копией записи 0 '
             '(`FUN_00455ad0` -> `FUN_004559a0`), значения по умолчанию — '
             'конструктор `FUN_00455760_00455760.c:38-67`.\n')
    md.write('Поля записи 0 (`default`): ' + ', '.join(
        '+%02X=%s' % (k * 4, hex(v)) for k, v in sorted(DEFAULTS.items())) + '\n\n')
    md.write('| id | техника | ' + ' | '.join('+%02X' % (i * 4) for i in range(25)) + ' |\n')
    md.write('|---:|---|' + '---:|' * 25 + '\n')
    for i, st in enumerate(rows):
        vals = [str(st.get(k, 0)) for k in range(25)]
        md.write('| %d | `%s` | %s |\n' % (i, NAMES[i], ' | '.join(vals)))

    md.write('\n## Группы материалов (таблицы 16 техник)\n\n')
    md.write('Источник: `FUN_0045a130_0045a130.c` — регистрация трёх встроенных групп.\n')
    md.write('Запись группы 0x48 байт: +0x00..+0x3C — 16 id техник (слот 0…15), ')
    md.write('+0x40 — имя группы, +0x44 — имя родителя.\n\n')
    md.write('| слот | `default` | `additiveonly` | `modelnozwrite` |\n')
    md.write('|---:|---|---|---|\n')
    groups = parse_groups()
    for s in range(16):
        cells = []
        for g in groups:
            v = g['slots'].get(s, 0)
            cells.append('%d (`%s`)' % (v, NAMES[v]) if v < len(NAMES) else str(v))
        md.write('| %d | %s |\n' % (s, ' | '.join(cells)))
    md.write('\n')
    for g in groups:
        md.write('- группа `%s`: %d слотов задано явно\n' % (g['name'], len(g['slots'])))
    io.open(OUT_MD, 'w', encoding='utf-8', newline='\n').write(md.getvalue())

    print('wrote', OUT_TSV)
    print('wrote', OUT_MD)
    print('groups:', [(g['name'], len(g['slots'])) for g in groups])
    for i, st in enumerate(rows):
        print('%2d %-28s %s' % (i, NAMES[i], {k: v for k, v in sorted(st.items())}))


if __name__ == '__main__':
    main()
