"""Normalize the two new agent files to the project's CRLF convention and
regenerate + verify the torch terrain lighting patch.

The live Godot project stores .gd scripts with CRLF endings (verified across
scripts/, tools/, scenes/ and project.godot). The two files this agent added
were written with bare LF, so they are converted here before the patch is
emitted; the patch then reproduces the prepared tree byte-for-byte.
"""
import difflib
import os
import re

LIVE = r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot"
MINIMAX = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\repro\godot"
OUT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\torch_regression\torch-terrain-light-gain.patch"

REL_MODIFIED = "scripts/native_scene_profile.gd"
REL_NEW = "tools/torch_terrain_light_regression_self_test.gd"
REL_RENDER = "tools/torch_render_visible_self_test.gd"
REL_PROBE = "tools/torch_regression_probe.gd"


def read_bytes(path):
    with open(path, "rb") as handle:
        return handle.read()


def write_bytes(path, data):
    with open(path, "wb") as handle:
        handle.write(data)


def to_crlf(data):
    """Normalize to CRLF without double-converting existing CRLF."""
    normalized = data.replace(b"\r\n", b"\n").replace(b"\n", b"\r\n")
    return normalized


def read_lines(path):
    with open(path, "r", encoding="utf-8", newline="") as handle:
        return handle.readlines()


def build():
    chunks = []
    old = read_lines(os.path.join(LIVE, REL_MODIFIED))
    new = read_lines(os.path.join(MINIMAX, REL_MODIFIED))
    chunks.extend(difflib.unified_diff(old, new, "a/godot/" + REL_MODIFIED, "b/godot/" + REL_MODIFIED, n=3))
    new_file = read_lines(os.path.join(MINIMAX, REL_NEW))
    chunks.extend(difflib.unified_diff([], new_file, "/dev/null", "b/godot/" + REL_NEW, n=3))
    render_file = read_lines(os.path.join(MINIMAX, REL_RENDER))
    chunks.extend(difflib.unified_diff([], render_file, "/dev/null", "b/godot/" + REL_RENDER, n=3))
    body = "".join(chunks)
    if not body.endswith("\n"):
        body += "\n"
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    with open(OUT, "w", encoding="utf-8", newline="") as handle:
        handle.write(body)
    return body


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
                    raise AssertionError("context mismatch at %d: %r != %r" % (cursor + 1, src[cursor], content))
                out.append(content)
                cursor += 1
            elif tag == "-":
                if src[cursor] != content:
                    raise AssertionError("removal mismatch at %d: %r != %r" % (cursor + 1, src[cursor], content))
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


def split_by_file(body):
    """Return {target_path: [hunk lines]} for each file section of the diff."""
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


def main():
    # 1. normalize the new files to CRLF
    for rel in (REL_NEW, REL_RENDER, REL_PROBE):
        path = os.path.join(MINIMAX, rel)
        before = read_bytes(path)
        after = to_crlf(before)
        if before != after:
            write_bytes(path, after)
            print("normalized to CRLF:", rel)
        else:
            print("already CRLF:", rel)

    # 2. rebuild the patch
    body = build()
    print("patch bytes:", len(body.encode("utf-8")), "hunks:", body.count("@@ -"))

    # 3. verify each section
    sections = split_by_file(body)
    live_bytes = read_bytes(os.path.join(LIVE, REL_MODIFIED))
    expected_mod = read_bytes(os.path.join(MINIMAX, REL_MODIFIED))

    mod_hunks = sections["b/godot/" + REL_MODIFIED]
    applied = apply_hunks(mod_hunks, live_bytes)
    print("modified-file patch reproduces prepared tree:", applied == expected_mod)

    new_hunks = sections["b/godot/" + REL_NEW]
    added = [line[1:] for line in new_hunks if line.startswith("+")]
    new_from_patch = "".join(added).encode("utf-8")
    new_expected = read_bytes(os.path.join(MINIMAX, REL_NEW))
    print("new-file hunk reproduces prepared tree:", new_from_patch == new_expected)

    render_hunks = sections["b/godot/" + REL_RENDER]
    render_added = [line[1:] for line in render_hunks if line.startswith("+")]
    render_from_patch = "".join(render_added).encode("utf-8")
    render_expected = read_bytes(os.path.join(MINIMAX, REL_RENDER))
    print("render-test hunk reproduces prepared tree:", render_from_patch == render_expected)

    # 4. live tree is still unpatched
    print("live file still contains the /255.0 defect:", b"/ 255.0" in live_bytes)
    print("prepared tree is fixed:", b"/ 255.0" not in expected_mod)

    # 5. final line-ending audit
    for label, path in (("live native_scene_profile", os.path.join(LIVE, REL_MODIFIED)),
                        ("new test file", os.path.join(MINIMAX, REL_NEW)),
                        ("render test file", os.path.join(MINIMAX, REL_RENDER)),
                        ("probe file", os.path.join(MINIMAX, REL_PROBE))):
        data = read_bytes(path)
        crlf = data.count(b"\r\n")
        print("  %-26s CRLF=%d bareLF=%d BOM=%s" % (label, crlf, data.count(b"\n") - crlf,
              data[:3] == b"\xef\xbb\xbf"))

    # 6. patch file line ending profile
    data = read_bytes(OUT)
    crlf = data.count(b"\r\n")
    print("  patch file                 CRLF=%d bareLF=%d" % (crlf, data.count(b"\n") - crlf))


if __name__ == "__main__":
    main()
