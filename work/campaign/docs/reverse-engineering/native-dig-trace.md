# Native digging trace

This note records the reproducible static trace of the original `Diggles.exe`. Addresses are preferred virtual addresses for the installed 32-bit executable; use the listed RVA plus the runtime module base when ASLR relocates it.

## Tcl entry points

| Command | Preferred VA | RVA |
| --- | ---: | ---: |
| `add_cave_skin_class` | `0x617570` | `0x217570` |
| `dig_mark` | `0x6586C0` | `0x2586C0` |
| `dig_apply` | `0x6347A0` | `0x2347A0` |
| `dig_next` | `0x634B50` | `0x234B50` |
| `get_digedge` | `0x635180` | `0x235180` |
| `cave_skin` | `0x66A9A0` | `0x26A9A0` |

The table can be regenerated with:

```powershell
python tools\inspect_native_commands.py
```

Its machine-readable output is `native-dig-command-map.json` in this directory.

## Player cave brush path

1. Singleton constructor `0x5661C0` loads `data/templates/cave0.tga` through `cave3.tga`.
2. Every source channel is normalized as `(value + 32) >> 6`.
3. Brush placement at `0x567CB0` anchors the 32x32 mask at cursor `(x - 16, y - 32)`.
4. Normalized value `4` is transparent. Values `0`, `1`, and `3` are passed to cave-cell marker `0x5671A0`.
5. Target native heights are `0 -> 0`, `1 -> 3`, `2 -> 7`, `3 -> 11`; zero/unmarked terrain falls back to `15`.

Consequently brush 1 has 34 interior cells at height 3 and four entrance cells at height 11. Brushes 2-4 have respectively 54, 132, and 124 interior cells at height 0, each with the same four height-11 entrance cells.

Exact masks and enlarged visualizations are generated with:

```powershell
python tools\extract_cave_brushes.py
```

## Mark and strike path

`dig_mark` dispatches as follows:

- mode 0 -> `0x5671A0`, cave cell;
- mode 1 -> validator/rasterizer path and `0x5672D0`, tunnel cell;
- mode 2 -> clear the selected owner/layer mark nibble.

The cave mark uses bit 8 plus a two-bit depth code. A tunnel mark is the nonzero nibble `3` **without** bit 8 (`0x567350`, `0x5673AD..0x5673D1`). The shared target decoder (`0x597430..0x597456`) returns `15` for zero, `11` for any nonzero nibble with bit 8 clear, and `max(0, 4 * (nibble & 3) - 1)` otherwise. Bit 8 is not a universal active-work flag. The owner occupies the corresponding nibble in the adjacent terrain field. Corrected by the 2026-11-17 corridor audit.

`dig_apply` at `0x6347A0` calls terrain core `0x596B80`. One accepted strike validates the grid point, obtains the dwarf owner's terrain layer, compares current and target heights, replaces the four BlockDB cells sharing the grid corner, marks affected terrain regions dirty, clears completed mark nibbles, schedules redraw, and emits debris/resource side effects.

## Cave registration and completion

`cave_skin add subtype x1 y1 x2 y2` appends an active rectangle record. `cave_skin rem x y` removes the record at a rounded map coordinate. `add_cave_skin_class set detail size` registers the finished mesh class selected by the same world subsystem.

After a successful strike, `dig_apply` enters completion manager `0x58BA00`:

```text
dig_apply 0x6347A0
  -> terrain strike 0x596B80
  -> completion manager 0x58BA00
       -> skin-class selector 0x58E9C0
       -> detail pools 0x58C336 / 0x58C369 / 0x58C39C
       -> instantiate finished object 0x58C450 (z = 15)
       -> remove pending record 0x58C437 -> 0x58F2A0
```

This is the source-backed reason finished cave supports must come from the original `auskleidung` mesh instead of separately placed guessed props.

## Remaining dynamic targets

1. Exact tunnel placement validator and invalid-selection coloring.
2. Exact cave-completion predicate and alternate geometry selection.
3. Native corridor support and torch spacing policy.
4. Exact selection wobble/colors and debris presentation.
