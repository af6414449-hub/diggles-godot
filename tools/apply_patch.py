"""Apply a unified diff to a project tree.

Deliberately independent of the generator in make_patch.py: it reads the patch
file from disk and applies it, so a successful run also proves the shipped
patch file is usable with `git apply -p1` semantics.

Usage:
    python apply_patch.py <patch_file> <project_root>

The patch paths are rooted at `godot/`, so <project_root> is the directory that
contains `godot/`.
"""
import os
import re
import sys


def split_by_file(body):
    sections = {}
    target = None
    current = []
    for line in body.splitlines(keepends=True):
        if line.startswith("--- "):
            target = None
            current = []
        elif line.startswith("+++ "):
            target = line[4:].strip()
            sections[target] = current
        elif target is not None:
            current.append(line)
    return sections


def apply_hunks(hunk_lines, source_bytes):
    src = source_bytes.decode("utf-8").splitlines(keepends=True)
    out = []
    cursor = 0
    index = 0
    while index < len(hunk_lines):
        line = hunk_lines[index]
        if not line.startswith("@@"):
            index += 1
            continue
        match = re.match(r"@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@", line)
        old_start = int(match.group(1))
        out.extend(src[cursor:old_start - 1])
        cursor = old_start - 1
        index += 1
        while index < len(hunk_lines) and not hunk_lines[index].startswith("@@"):
            hunk_line = hunk_lines[index]
            if hunk_line.startswith("---") or hunk_line.startswith("+++"):
                index += 1
                continue
            tag = hunk_line[0]
            content = hunk_line[1:]
            if tag == " ":
                if src[cursor] != content:
                    raise AssertionError("context mismatch at line %d:\n  file %r\n  patch %r"
                                         % (cursor + 1, src[cursor], content))
                out.append(content)
                cursor += 1
            elif tag == "-":
                if src[cursor] != content:
                    raise AssertionError("removal mismatch at line %d:\n  file %r\n  patch %r"
                                         % (cursor + 1, src[cursor], content))
                cursor += 1
            elif tag == "+":
                out.append(content)
            elif hunk_line in ("\n", "\r\n"):
                pass
            else:
                raise AssertionError("unexpected diff line %r" % hunk_line)
            index += 1
    out.extend(src[cursor:])
    return "".join(out).encode("utf-8")


def main():
    patch_path = sys.argv[1]
    project_root = sys.argv[2]
    with open(patch_path, "r", encoding="utf-8", newline="") as handle:
        body = handle.read()

    sections = split_by_file(body)
    print("patch sections:", len(sections))
    for target, hunks in sections.items():
        if target == "/dev/null":
            continue
        relative = target
        if relative.startswith("b/"):
            relative = relative[2:]
        path = os.path.join(project_root, relative.replace("/", os.sep))
        if not os.path.exists(path):
            print("  SKIP (missing target):", relative)
            continue
        with open(path, "rb") as handle:
            source = handle.read()
        result = apply_hunks(hunks, source)
        with open(path, "wb") as handle:
            handle.write(result)
        print("  applied:", relative, "bytes", len(source), "->", len(result))

    # New files: /dev/null -> b/<path>
    for target, hunks in sections.items():
        if target == "/dev/null":
            continue
        source_label = None
        # find the matching "---" label by scanning the body order
        for candidate in re.finditer(r"--- (\S+)\n\+\+\+ " + re.escape(target) + r"\n", body):
            source_label = candidate.group(1)
        if source_label != "/dev/null":
            continue
        relative = target[2:] if target.startswith("b/") else target
        path = os.path.join(project_root, relative.replace("/", os.sep))
        if os.path.exists(path):
            print("  exists already, skipped:", relative)
            continue
        added = [line[1:] for line in hunks if line.startswith("+")]
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, "wb") as handle:
            handle.write("".join(added).encode("utf-8"))
        print("  created:", relative, len(added), "lines")


if __name__ == "__main__":
    main()
