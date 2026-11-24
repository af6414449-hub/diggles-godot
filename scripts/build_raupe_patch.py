"""Build the ready-to-apply patch with the Raupe AI for the live Codex tree.

Scope: the worm behaviour module, the worm actor, the farm side of the worm
production and the four self-tests, plus the small RNG accessor change that
the multiplayer snapshot needs.

Read: live Codex tree + Minimax tree.
Write: out/raupe-ai-for-live-2026-11-19.patch (unified diff, difflib format,
no git in this environment).
"""
from __future__ import annotations

import difflib
import hashlib
import os

LIVE = r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot"
MINIMAX = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot"
OUT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\raupe-ai-for-live-2026-11-19.patch"

# rel path -> review note
FILES = {
    "scripts/native_raupe_ai.gd": "правила червя по оригиналу (raupe.tcl)",
    "scripts/native_raupe_actor.gd": "машина состояний червя + адаптер к миру",
    "scripts/native_farm_raupe.gd": "сторона фермы: кандидаты, lock, порог, корм, кулдаун",
    "scripts/native_raupe_probe.gd": "пробная сцена червя",
    "scenes/native_raupe_probe.tscn": "сцена пробника червя",
    "tools/native_raupe_ai_self_test.gd": "self-тест правил червя",
    "tools/native_raupe_actor_self_test.gd": "self-тест актёра червя",
    "tools/native_farm_raupe_self_test.gd": "self-тест правил фермы",
    "tools/native_raupe_scene_self_test.gd": "self-тест сцены + гард тихих спавнов",
    "scripts/diggles_irandom.gd": "добавлены get_state/set_state для снапшота RNG",
}


def read(path: str) -> list[str]:
    with open(path, encoding="utf-8", errors="replace") as handle:
        return handle.read().splitlines(keepends=True)


def main() -> None:
    chunks: list[str] = []
    report: list[str] = []
    for rel, note in FILES.items():
        live_path = os.path.join(LIVE, rel.replace("/", os.sep))
        mini_path = os.path.join(MINIMAX, rel.replace("/", os.sep))
        live_exists = os.path.isfile(live_path)
        mini_exists = os.path.isfile(mini_path)
        if not mini_exists:
            report.append(f"SKIP  {rel}: нет в дереве Minimax")
            continue
        if not live_exists:
            diff = difflib.unified_diff(
                [], read(mini_path), fromfile="/dev/null", tofile="b/" + rel, n=3)
            chunks.append("".join(diff))
            report.append(f"ADD   {rel}: {note}")
            continue
        live_lines = read(live_path)
        mini_lines = read(mini_path)
        if live_lines == mini_lines:
            report.append(f"SAME  {rel}: разницы нет")
            continue
        diff = difflib.unified_diff(
            live_lines, mini_lines, fromfile="a/" + rel, tofile="b/" + rel, n=3)
        body = "".join(diff)
        chunks.append(body)
        changed = sum(1 for line in body.splitlines()
                      if line.startswith(("+", "-")) and not line.startswith(("+++", "---")))
        report.append(f"DIFF  {rel}: {note} (строк +/-: {changed})")

    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    with open(OUT, "w", encoding="utf-8", newline="\n") as handle:
        handle.write("\n".join(chunks))
    with open(OUT, "rb") as handle:
        digest = hashlib.sha256(handle.read()).hexdigest()

    print("\n".join(report))
    print("patch:", OUT)
    print("bytes:", os.path.getsize(OUT))
    print("sha256:", digest)


if __name__ == "__main__":
    main()
