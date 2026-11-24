#!/usr/bin/env python3
"""Cross-reference the engine's C++ methods with the Tcl commands the game uses.

Inputs:
  engine_symbols.tsv  — class/method names recovered from the exe's assert
                         strings (prefix, class, method, va, text)
  tcl_native_candidates.tsv — command words used by the 479 original .tcl
                         scripts (word, uses)

Method: the same command is spelled differently in the two worlds
("SMAddEvent" in C++, "sm_add_event" in Tcl), so both sides are normalised
(lower-cased, underscores dropped) and matched.

Output: a table "C++ method <TAB> Tcl command <TAB> uses in scripts", which
tells the port which engine features the original game actually relies on.

Usage: python tcl_name_match.py <ref-dir>
"""
from __future__ import annotations

import re
import sys
from collections import defaultdict
from pathlib import Path


def norm(s: str) -> str:
    return re.sub(r"[^a-z0-9]", "", s.lower())


def predict_names(method: str) -> list[str]:
    """Guess the Tcl spelling of a C++ method name.

    The engine exposes commands in snake_case ("SMAddEvent" -> "sm_add_event"),
    but the original author also wrote compound words by hand
    ("SetParticleSource" -> "set_particlesource"), so several variants are
    offered and the scripts are used as the judge.
    """
    out = []
    # CamelCase -> snake_case
    s1 = re.sub(r"(?<=[a-z0-9])(?=[A-Z])", "_", method)
    s1 = re.sub(r"(?<=[A-Z])(?=[A-Z][a-z])", "_", s1)
    out.append(s1.lower())
    # plain lowercase
    out.append(method.lower())
    # lowercase without underscores between words, e.g. SetClassAnimSet
    out.append(re.sub(r"_", "", s1.lower()))
    # prefix split for acronyms: "LGSetArea" -> "lg_set_area"
    s2 = re.sub(r"^(.)([A-Z][a-z])", r"\1_\2", method)
    s2 = re.sub(r"(?<=[a-z0-9])(?=[A-Z])", "_", s2)
    out.append(s2.lower())
    seen = set()
    res = []
    for o in out:
        if o and o not in seen:
            seen.add(o)
            res.append(o)
    return res


def main() -> int:
    ref = Path(sys.argv[1])
    sym_path = ref / "engine_symbols.tsv"
    vocab_path = ref / "tcl_native_candidates.tsv"
    out_path = ref / "method_tcl_map.tsv"

    methods: list[tuple[str, str, str]] = []   # class, method, prefix
    for line in sym_path.read_text(encoding="utf-8").splitlines():
        if line.startswith("prefix") or not line.strip():
            continue
        p = line.split("\t")
        if len(p) < 3:
            continue
        methods.append((p[1].strip(), p[2].strip(), p[0].strip()))

    vocab: dict[str, int] = {}
    for line in vocab_path.read_text(encoding="utf-8").splitlines():
        if line.startswith("#") or not line.strip():
            continue
        p = line.split("\t")
        if len(p) < 2:
            continue
        vocab[p[0].strip()] = int(p[1])

    by_norm: dict[str, list[str]] = defaultdict(list)
    for word, cnt in vocab.items():
        by_norm[norm(word)].append(word)

    rows = []
    predicted_rows = []
    matched = 0
    for cls, method, prefix in methods:
        key = norm(method)
        cands = by_norm.get(key, [])
        if cands:
            cands.sort(key=lambda w: -vocab.get(w, 0))
            best = cands[0]
            matched += 1
            rows.append((prefix, cls, method, best, vocab.get(best, 0),
                         ";".join(f"{c}:{vocab.get(c,0)}" for c in cands[1:4])))
        else:
            # no exact match: guess the Tcl spelling and look it up
            for guess in predict_names(method):
                if guess in vocab:
                    predicted_rows.append((prefix, cls, method, guess, vocab[guess], "predicted"))
                    break

    rows.sort(key=lambda r: (-r[4], r[1], r[2]))
    out = ["prefix\tclass\tcpp_method\ttcl_command\tuses\tkind"]
    for r in rows:
        out.append("\t".join(str(x) for x in r))
    for r in predicted_rows:
        out.append("\t".join(str(x) for x in r))
    out_path.write_text("\n".join(out) + "\n", encoding="utf-8")

    print(f"# methods: {len(methods)}, confirmed by scripts: {matched}, "
          f"predicted: {len(predicted_rows)}")
    print(f"# written: {out_path}")
    print()
    for prefix, cls, method, cmd, uses, other in rows[:45]:
        print(f"{uses:7d}  {cls}::{method:34s} -> {cmd}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
