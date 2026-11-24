#!/usr/bin/env python3
"""diff-mods.py — сравнивает песочницу (после установки модов) с оригиналом игры.

Песочница:  <root>/sandbox/Diggles/Data
Оригинал:   Steam/Diggles The Myth of Fenris/data

Песочница содержит не все подкаталоги оригинала (Sound/Music/3db/BlockDB
намеренно не копировались), поэтому сравниваем только по файлам песочницы.
"""
import difflib
import hashlib
import json
import os
import sys

ROOT = os.path.dirname(os.path.abspath(__file__))
SANDBOX = os.path.join(ROOT, "sandbox", "Diggles", "Data")
ORIGINAL = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
OUT_JSON = os.path.join(ROOT, "mods-diff.json")
OUT_MD = os.path.join(ROOT, "mods-diff.md")

TEXT_EXT = {".tcl", ".txt", ".json", ".md"}


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def rel_files(root):
    out = {}
    for dirpath, _dirs, files in os.walk(root):
        for name in files:
            p = os.path.join(dirpath, name)
            out[os.path.relpath(p, root).replace("\\", "/")] = p
    return out


def read_text(path):
    for enc in ("utf-8", "cp1252", "latin-1"):
        try:
            with open(path, "r", encoding=enc) as f:
                return f.read().splitlines(keepends=True)
        except (UnicodeDecodeError, OSError):
            continue
    return None


def main():
    sb = rel_files(SANDBOX)
    added, modified, identical = [], [], []

    for rel, sb_path in sorted(sb.items()):
        orig_path = os.path.join(ORIGINAL, rel.replace("/", os.sep))
        if not os.path.exists(orig_path):
            added.append(rel)
            continue
        if sha256(sb_path) != sha256(orig_path):
            modified.append(rel)
        else:
            identical.append(rel)

    # текстовые диффы для изменённых tcl/txt
    diffs = {}
    for rel in modified:
        ext = os.path.splitext(rel)[1].lower()
        if ext not in TEXT_EXT:
            continue
        a = read_text(os.path.join(ORIGINAL, rel.replace("/", os.sep)))
        b = read_text(os.path.join(SANDBOX, rel.replace("/", os.sep)))
        if a is None or b is None:
            continue
        d = list(difflib.unified_diff(a, b, fromfile="original/" + rel,
                                       tofile="modded/" + rel, n=1))
        if d:
            diffs[rel] = d

    result = {
        "sandbox": SANDBOX,
        "original": ORIGINAL,
        "totals": {
            "files_in_sandbox": len(sb),
            "identical": len(identical),
            "modified": len(modified),
            "added": len(added),
        },
        "added": added,
        "modified": modified,
        "diffs": diffs,
    }
    with open(OUT_JSON, "w", encoding="utf-8") as f:
        json.dump(result, f, ensure_ascii=False, indent=2)

    # markdown-отчёт
    lines = [
        "# Diggles Mod Manager — эффект установки 17 модов",
        "",
        "Сгенерировано `diff-mods.py`: сравнение песочницы (после установки модов)",
        "с эталонной установкой Steam-версии.",
        "",
        "| Показатель | Значение |",
        "|---|---|",
        f"| Файлов в песочнице | {len(sb)} |",
        f"| Без изменений | {len(identical)} |",
        f"| Изменено (существовали в оригинале) | {len(modified)} |",
        f"| Добавлено (новых файлов) | {len(added)} |",
        "",
        "## Изменённые файлы",
        "",
    ]
    for rel in modified:
        n = len(diffs.get(rel, []))
        lines.append(f"- `{rel}`" + (f" — {n} строк диффа" if n else " (бинарный)"))
    lines += ["", "## Добавленные файлы", ""]
    for rel in added:
        lines.append(f"- `{rel}`")
    lines += ["", "## Текстовые диффы", ""]
    for rel, d in diffs.items():
        lines.append(f"### `{rel}`")
        lines.append("```diff")
        lines.extend(line.rstrip("\n") for line in d)
        lines.append("```")
        lines.append("")
    with open(OUT_MD, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))

    print(f"файлов: {len(sb)} | без изменений: {len(identical)} | "
          f"изменено: {len(modified)} | добавлено: {len(added)}")
    print(f"текстовых диффов: {len(diffs)}")
    print(f"отчёт: {OUT_MD}")
    print(f"json:  {OUT_JSON}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
