"""Build the unified diff for the walkmap performance work and verify it.

The diff is generated with difflib (no git in this environment) and is
checked by applying it back to the pristine project files with a minimal
unified-diff applier, then comparing the result with the workbench sources.
"""
import difflib
import os
import sys

MAIN = r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles"
WB = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\workbench"

FILES = [
    ("godot/scripts/native_walkmap.gd", "scripts/native_walkmap.gd"),
    ("godot/scripts/native_walk_flags.gd", "scripts/native_walk_flags.gd"),
    ("godot/scripts/native_terrain_state.gd", "scripts/native_terrain_state.gd"),
]


def read(path):
    with open(path, "r", encoding="utf-8", newline="") as handle:
        return handle.read().splitlines(keepends=True)


def apply_unified(original, diff_lines):
    """Minimal unified-diff applier used only to verify our own diff."""
    result = []
    source = list(original)
    index = 0
    cursor = 0
    while index < len(diff_lines):
        line = diff_lines[index]
        if not line.startswith("@@"):
            index += 1
            continue
        header = line.split("@@")[1].strip()
        old_part = header.split(" ")[0]
        new_part = header.split(" ")[1]
        old_start = int(old_part[1:].split(",")[0]) - 1
        new_start = int(new_part[1:].split(",")[0]) - 1
        result.extend(source[cursor:old_start])
        cursor = old_start
        if new_start != len(result):
            raise AssertionError("new start %d != %d" % (new_start, len(result)))
        index += 1
        while index < len(diff_lines) and not diff_lines[index].startswith("@@"):
            body = diff_lines[index]
            if body.startswith("---") or body.startswith("+++"):
                index += 1
                continue
            marker = body[0]
            text = body[1:]
            if marker == " ":
                if cursor >= len(source) or source[cursor] != text:
                    raise AssertionError("context mismatch at line %d" % cursor)
                result.append(source[cursor])
                cursor += 1
            elif marker == "-":
                if cursor >= len(source) or source[cursor] != text:
                    raise AssertionError("removal mismatch at line %d" % cursor)
                cursor += 1
            elif marker == "+":
                result.append(text)
            elif marker == "\\":
                pass
            else:
                raise AssertionError("bad diff line %r" % body)
            index += 1
    result.extend(source[cursor:])
    return result


def main():
    chunks = []
    for main_rel, wb_rel in FILES:
        old = read(os.path.join(MAIN, main_rel))
        new = read(os.path.join(WB, wb_rel))
        diff = list(difflib.unified_diff(old, new,
                                          fromfile="a/" + main_rel,
                                          tofile="b/" + main_rel,
                                          n=3))
        if not diff:
            print("SKIP %s (no change)" % main_rel)
            continue
        chunks.extend(diff)
        rebuilt = apply_unified(old, diff)
        if rebuilt != new:
            raise AssertionError("patch does not reproduce %s" % main_rel)
        added = sum(1 for line in diff if line.startswith("+") and not line.startswith("+++"))
        removed = sum(1 for line in diff if line.startswith("-") and not line.startswith("---"))
        print("PATCH %s +%d -%d verified" % (main_rel, added, removed))
    out = os.path.join(WB, "walkmap-performance.patch")
    with open(out, "w", encoding="utf-8", newline="\n") as handle:
        handle.write("".join(chunks))
    print("WROTE %s (%d bytes)" % (out, os.path.getsize(out)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
