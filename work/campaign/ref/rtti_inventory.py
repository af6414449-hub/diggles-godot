#!/usr/bin/env python3
"""Extract MSVC RTTI type descriptors from a PE32 image.

RTTI type names live in .rdata as ".?AV<Class>@@" (classes), ".?AU<Struct>@@",
".?AW4<enum>@@" (enums), and the complete-object-locator points at the
name descriptor. This script lists every mangled type name it can find and
groups them per kind, which gives a class inventory of the original engine.

Usage: python rtti_inventory.py <path-to-pe> [regex-filter]
"""
from __future__ import annotations

import re
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections  # noqa: E402

KIND = {
    "V": "class",
    "U": "struct",
    "W": "enum",
    "T": "union",
}


def demangle_msvc(name: str) -> str:
    """Very small MSVC name prettifier: enough for a readable inventory."""
    # strip leading ? and trailing @
    body = name
    if body.startswith("?"):
        body = body[1:]
    if body.endswith("@"):
        body = body[:-1]
    # "?AVFoo@@" -> "Foo"
    if body.startswith("?A"):
        body = body[2:]
    elif body.startswith("A"):
        body = body[1:]
    if body.endswith("@"):
        body = body[:-1]
    # replace @ with ::  (nested scopes)
    body = body.replace("@@", "::").replace("@", "::")
    body = body.replace("@@", "::")
    return body


def main() -> int:
    path = Path(sys.argv[1])
    positional: list[str] = []
    skip_next = False
    for a in sys.argv[2:]:
        if skip_next:
            skip_next = False
            continue
        if a == "--out":
            skip_next = True
            continue
        if a.startswith("--"):
            continue
        positional.append(a)
    pattern = re.compile(positional[0]) if positional else None
    data = path.read_bytes()
    sections, image_base = parse_sections(data)

    hits = []
    for m in re.finditer(rb"\.\?A([VUWT])([ -~]{1,120}?)@@\x00", data):
        kind = KIND.get(m.group(1).decode(), "?")
        raw = m.group(0)[:-1].decode("latin-1")
        pretty = demangle_msvc(raw)
        if pattern and not pattern.search(pretty):
            continue
        hits.append((kind, pretty, raw))

    # de-duplicate by raw name
    uniq: dict[str, tuple[str, str]] = {}
    for kind, pretty, raw in hits:
        uniq.setdefault(raw, (kind, pretty))

    counts = Counter(k for k, _ in uniq.values())
    print(f"# RTTI inventory of {path.name}: {len(uniq)} type names")
    print("# " + ", ".join(f"{k}={v}" for k, v in sorted(counts.items())))
    print()
    lines = []
    for raw, (kind, pretty) in sorted(uniq.items(), key=lambda kv: kv[1][1].lower()):
        print(f"{kind:7s} {pretty}")
        lines.append(f"{kind}\t{pretty}")
    if "--out" in sys.argv:
        out = Path(sys.argv[sys.argv.index("--out") + 1])
        out.write_text("\n".join(lines) + "\n", encoding="utf-8")
        print(f"# written: {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
