# Godot instructions

- Keep PMP/Tcl/3DB/BlockDB coordinates distinct from Godot coordinates; read `godot/README.md` before changing transforms.
- Identify the state owner, callers, completion path, and cancellation behavior for runtime changes.
- Add or update a targeted `godot/tools/*_self_test.gd` for non-trivial behavior.
- Run the targeted suite, then the relevant full suite/smoke. Visual changes require render/OpenGL evidence.
- Keep FACT, ADAPTER, and UNKNOWN behavior explicit in code and reports.
