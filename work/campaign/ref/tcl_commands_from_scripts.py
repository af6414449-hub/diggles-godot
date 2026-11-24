#!/usr/bin/env python3
"""Extract the Tcl command vocabulary used by the original Diggles scripts.

The game's logic lives in 479 .tcl files. Those scripts call both pure-Tcl
commands (proc, set, if, ...) and *native* engine commands implemented in
C++ inside Diggles.exe (map_create, set_view, sm_draw_stone, ...).

Knowing the native part tells the Godot port exactly which engine commands
have to exist and what their contract is. This script approximates a Tcl
lexer (handles quotes, braces, brackets, comments, line continuations) and
collects command-position words with usage counts.

Usage: python tcl_commands_from_scripts.py <scripts-root> [--out vocab.tsv]
"""
from __future__ import annotations

import sys
from collections import Counter
from pathlib import Path


def command_words(text: str) -> Counter:
    """Approximate Tcl command extraction."""
    words, procs = scan(text)
    out: Counter = Counter()
    for w, is_cmd in words:
        if is_cmd:
            out[w] += 1
    return out


BUILTIN_TCL = {
    "set", "unset", "if", "else", "elseif", "while", "for", "foreach", "break",
    "continue", "return", "proc", "global", "variable", "upvar", "uplevel",
    "namespace", "package", "catch", "expr", "error", "eval", "subst", "switch",
    "list", "lindex", "llength", "lappend", "linsert", "lrange", "lreplace",
    "lsearch", "lsort", "lmap", "join", "split", "concat", "append", "string",
    "format", "scan", "regexp", "regsub", "array", "dict", "info", "exists",
    "file", "open", "close", "read", "gets", "puts", "flush", "seek", "tell",
    "eof", "fconfigure", "glob", "source", "cd", "pwd", "exec", "pid", "exit",
    "after", "clock", "time", "incr", "binary", "encode", "scan", "apply",
    "tailcall", "coroutine", "yield", "yieldto", "chan", "socket", "event",
    "trace", "history", "interp", "unknown", "auto_load", "auto_import",
    "auto_mkindex", "auto_qualify", "tcl::", "expr", "while", "for", "if",
    "foreach", "string", "msgcat", "encoding", "platform", "package",
}


def scan(text: str):
    """Return (list of (word, at_command_start), set of defined proc names)."""
    words: list[tuple[str, bool]] = []
    procs: set[str] = set()
    i = 0
    n = len(text)
    at_cmd_start = True
    while i < n:
        c = text[i]
        if c == "\\" and i + 1 < n:
            i += 2
            continue
        if c == "#":
            j = text.find("\n", i)
            i = n if j < 0 else j
            continue
        if c == '"':
            i += 1
            while i < n:
                if text[i] == "\\":
                    i += 2
                    continue
                if text[i] == '"':
                    i += 1
                    break
                if text[i] == "[":
                    depth = 1
                    i += 1
                    while i < n and depth:
                        if text[i] == "\\":
                            i += 2
                            continue
                        if text[i] == "[":
                            depth += 1
                        elif text[i] == "]":
                            depth -= 1
                        i += 1
                    continue
                i += 1
            at_cmd_start = True
            continue
        if c == "{":
            depth = 1
            i += 1
            while i < n and depth:
                if text[i] == "\\":
                    i += 2
                    continue
                if text[i] == "{":
                    depth += 1
                elif text[i] == "}":
                    depth -= 1
                i += 1
            at_cmd_start = True
            continue
        if c == "[":
            depth = 1
            i += 1
            start = i
            while i < n and depth:
                if text[i] == "\\":
                    i += 2
                    continue
                if text[i] == "[":
                    depth += 1
                elif text[i] == "]":
                    depth -= 1
                    if depth == 0:
                        break
                i += 1
            inner = text[start:i]
            w2, p2 = scan(inner)
            words.extend(w2)
            procs |= p2
            i += 1
            at_cmd_start = True
            continue
        if c in " \t\r\n;":
            if c in "\n;":
                at_cmd_start = True
            i += 1
            continue
        j = i
        while j < n and (text[j].isalnum() or text[j] in "_:"):
            j += 1
        if j == i:
            i += 1
            continue
        word = text[i:j]
        words.append((word, at_cmd_start))
        if at_cmd_start and word == "proc":
            # the next word (any position) is the procedure name
            k = j
            while k < n and text[k] in " \t":
                k += 1
            e = k
            while e < n and (text[e].isalnum() or text[e] in "_:"):
                e += 1
            if e > k:
                procs.add(text[k:e])
        at_cmd_start = False
        i = j
    return words, procs


def main() -> int:
    root = Path(sys.argv[1])
    out_path = None
    if "--out" in sys.argv:
        out_path = Path(sys.argv[sys.argv.index("--out") + 1])

    total: Counter = Counter()
    all_procs: set[str] = set()
    per_file = []
    for f in sorted(root.rglob("*.tcl")):
        try:
            text = f.read_text(encoding="latin-1")
        except Exception:
            continue
        words, procs = scan(text)
        c: Counter = Counter()
        for w, is_cmd in words:
            if is_cmd:
                c[w] += 1
        total.update(c)
        all_procs |= procs
        per_file.append((f, c))

    native = {w: n for w, n in total.items()
              if w not in all_procs and w not in BUILTIN_TCL}

    print(f"# files: {len(per_file)}")
    print(f"# distinct command words: {len(total)}")
    print(f"# user procs defined:    {len(all_procs)}")
    print(f"# native-engine candidates (used, not a proc, not Tcl builtin): {len(native)}")
    print()
    for word, cnt in sorted(native.items(), key=lambda kv: (-kv[1], kv[0])):
        print(f"{cnt:7d}  {word}")

    if out_path:
        lines = ["# native_candidate\tuses"]
        for word, cnt in sorted(native.items()):
            lines.append(f"{word}\t{cnt}")
        out_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
        print(f"# written: {out_path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
