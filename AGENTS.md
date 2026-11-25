# Diggles / MiniMax project instructions

## Context

- This is the active Godot 4.7.2 Android reimplementation of Diggles.
- Read `README.md`, `PROJECT-MAP-2026-11-21.md`, and the active queue under `docs/plan/` before changing code.
- The source-of-truth queue is `docs/plan/queue-2026-11-19.md` unless a newer queue is explicitly identified.
- Every claim and implementation choice must remain FACT, ADAPTER, or UNKNOWN. Preserve `## SOURCE:` and `## ADAPTER:` annotations.

## Workflow

- Keep one measurable work block per change and use the smallest relevant self-test first.
- For gameplay changes, verify state transitions, completion/cancel behavior, and real world mutation.
- For visual changes, run the relevant OpenGL/render check; headless tests alone do not prove appearance.
- Use `scripts/run_all_suites.py` or the targeted runner described in `README.md` after non-trivial Godot changes.
- Do not rebuild the APK for every iteration; rebuild after meaningful Android-facing changes.

## Context selection

- Start with `PROJECT-MAP-2026-11-21.md` and the active plan, then read only the relevant subsystem report and scripts.
- Do not load `work/`, `out/`, `baseline/`, `repro/`, `trial/`, or unrelated `RefusalRates/` artefacts by default.
- Preserve provenance, coordinate-space assumptions, and known limitations in the relevant report.

## Project map

- `godot/`: main Godot project, runtime scripts, scenes, assets, and self-tests.
- `docs/plan/`: active work queue and phase plans.
- `docs/reverse-engineering/`: source evidence and per-block reports.
- `scripts/`: suite runners, build helpers, and verification scripts.
- `tools/`: source import, audits, and chapter/field tooling.
