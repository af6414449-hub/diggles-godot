# -*- coding: utf-8 -*-
"""Патч: пометка ошибочных утверждений З30 в report.md и z30.md."""
import io, os

ZONE = r'C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp'

NOTE = u"""> **⚠ ОПРОВЕРГНУТО в З33 (2026-11-22).** Разбор дизассемблером показал, что
> `DAT_00773650` — это **реестр областей (скоупов) профилировщика**, а не «реестр типов
> объектов»; «1024 тайла на тип» — это 1024 возможных **родительских областей**, а не
> тайлы; `DAT_00773680 + tile*0x10` — не bbox тайла, а `+0x30` записи области
> (накопитель времени); порядок отрисовки задаётся **ключом сортировки** в
> `FUN_00450850`, а не «типом объекта»; «группа» из З28 — это **группа материалов**,
> а не тип объекта. Полный разбор и ссылки: **З33**, п. 2–4.
> Ниже сохранён исходный текст З30 без правок — читать его следует только с этой оговоркой.
"""

MARK = u'<!-- Z30-SUPERSEDED-BY-Z33 -->\n'

targets = [
    (os.path.join(ZONE, 'report.md'), u'## З30.'),
    (os.path.join(ZONE, 'z30.md'), u'# З30.'),
]

for path, head in targets:
    txt = io.open(path, 'r', encoding='utf-8').read()
    if MARK in txt:
        print('SKIP (уже помечено):', os.path.basename(path))
        continue
    idx = txt.find(head)
    if idx < 0:
        print('FAIL: заголовок не найден в', os.path.basename(path))
        continue
    eol = txt.find('\n', idx)
    insert_at = eol + 1
    # пропускаем пустые строки после заголовка
    while insert_at < len(txt) and txt[insert_at] == '\n':
        insert_at += 1
    new = txt[:insert_at] + MARK + NOTE + '\n' + txt[insert_at:]
    io.open(path, 'w', encoding='utf-8', newline='\n').write(new)
    print('OK: %s (+%d симв.)' % (os.path.basename(path), len(new) - len(txt)))
