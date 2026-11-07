# Handover: a shared tools repo for L's recomps

For a session setting up one repository of measurement and test tools that L's N64 recomps (Banjo Re-Tooie, the
Mario Party 3 recomp and its MP1/MP2 ports, and later ones) all use, in place of each project's own copies. Written
2026-11-07 from the Banjo Re-Tooie session. The renderer side of measurement (stats API, GPU timers, hitch causes,
capture and replay, stutter detection) belongs to the RT64 fork: see `notes/rt64-fork-handover.md` and
`notes/rt64-fork-enhancements.md`. This repo holds what drives a game from outside and what reads the results.

Ground rules: L's own repo; nothing from a ROM in it (no captures, dumps, textures, symbol files of a game's own
code beyond what the game repos commit); licences checked before copying code in (both source repos are GPLv3, so
this one should be too, or each file keeps its licence); say what was and wasn't tested.

## What exists today, to merge

| Tool | Banjo Re-Tooie (`D:\Projects\Banjo Tooie N64\Banjo-Tooie-N64-Recomp`) | Mario Party 3 (`D:\Projects\Mario Party 3\Marioparty3recomp`) |
|---|---|---|
| Sweep driver | `tools/perf_sweep.py`: every map from `src/game/map_names.inc`, console on stdin, crash and hang detection with restart from the next map, `--setup` / `--teardown` commands, `--resume` | `tools/frame_check/profile_sweep.ps1`, `sweep.ps1`, `survey.ps1`, `switches.ps1`: per minigame, `MP3_CONSOLE` commands |
| Report | `tools/perf_report.py`: per map (median and worst frame, GPU time per pass, renderer CPU parts, shader compiles), profile by group and thread, top functions per map, loading costs | `tools/frame_check/profile_chart.py` (groups, top functions, a PNG) |
| Frame analysis | | `box.py`, `heat.py`, `strip.py`, `edges.py` (read `frames.txt` from frame capture), `diagnose.ps1` |
| Sampling profiler | `src/debug/host_profiler.cpp` (console `hostprof`): labels per map, samples weighted by the CPU time each thread used, two callers per sample from the x64 unwind data (`.callers.tsv`) | `src/game/host_profiler.cpp` (`MP3_PROFILE`): the original |
| Console link | the console reads stdin; `docs/console.md` | `tools/frame_check/console_send.py` |
| Notes | `notes/headless-testing.md` (Performance sweep section) | `tools/frame_check/README.md`, `docs/frame-rate.md` |

Banjo's sweep of 2026-11-07 (224 maps as set, 194 with the Enhanced preset, a texture sweep of 926 entrances)
found and fixed real costs with these tools; their outputs are the examples to test the merged versions against
(`D:\Projects\Banjo Tooie N64\perf_sweep\`, outside the repo).

## The pieces

### 1. A per-game settings file

Everything game-specific in one small file per game (TOML or JSON), kept in the game's repo, so the tools stay
generic:

- the exe and its working folder, the build folders to choose from;
- how to send console commands (stdin, an env var such as `MP3_CONSOLE`, a command file) and how to read output
  (the log file and its line format, `[command] text`, `ERR` for errors);
- the commands for: warp to an entry, wait until the player can move (or the scene is ready), a short camera turn or
  idle, take a screenshot, start and stop the benchmark and the profiler, quit;
- the entry list (maps, minigames, boards) or where to read it (`map_names.inc`), and entries to skip;
- where crash and hang reports, dumps and the benchmark csv go;
- how function names group in a profile (the recompiled game's `func_<address>` and overlay suffixes, the
  runtime, the renderer, the driver, the port's own code, the OS).

### 2. A console contract

The few console commands each game must have for the tools to drive it, with the same meaning everywhere, even if
spelled differently in the settings file: warp to an entry, wait for control with a timeout, look or turn the
camera, screenshot, benchmark start and stop, profiler start, label and stop, echo a marker line, quit with an exit
code. Banjo's console has all of them (`docs/console.md`); Mario Party's has most. A game missing one adds it, as the
Banjo project's rule says: if it can't be done with the console, add console support.

### 3. The sweep driver

One driver merged from both (Banjo's `perf_sweep.py` as the base, it already restarts after crashes and hangs):
builds the command list from the settings file, feeds it, watches the log for its markers, notes timeouts, crashes
(with the entry, the exit code and the crash files it finds) and hangs (no progress for a set time), copies the
benchmark csv and profile per run, and starts again from the next entry. Options as Banjo's: `--entries`, `--dwell`,
`--setup` and `--teardown` commands (a pass with other settings, then put them back), `--resume`, `--dry-run`.
Passes with settings changed should check the setting really changed (Banjo's first Enhanced pass ran without it,
because `set effects preset enhanced` read "preset enhanced" as the value).

### 4. Reports and charts

- Per entry: median and worst frame time, frames per second, GPU time per game frame and per pass, the renderer's
  CPU parts, the game's own CPU time, shader compiles, hitches; heaviest first, plus top lists per column.
- Profile: shares by group and by thread, top functions per entry and overall, what loading each entry costs.
- Comparing runs: two output folders side by side per entry (before and after a change), with each run's spread
  shown, so a change smaller than the noise isn't called a gain. Compare runs made the same way: Banjo's first
  comparison mixed a full sweep with a twelve-map one and showed gains of 30% that a like-for-like rerun put at 2%.
- Charts as PNGs (Pillow), and Mario Party's frame analysis scripts (`box.py`, `heat.py`, `strip.py`, `edges.py`)
  for frame-time files.

### 5. The sampling profiler

One copy of `host_profiler.cpp` for every game, as a small library the game links (Windows first, Linux next; on
Android use `simpleperf`), with Banjo's additions: labels (the sweep labels each entry), CPU-time weighting (a thread
that only woke briefly counts for little; without it, waiting threads filled the top of the profile) and two
callers per sample. Self time only otherwise, and wait functions still show where a thread was waiting when sampled;
the report groups them as OS. Started from the console (`hostprof start|label|stop`) or an env var.

### 6. Slow-function reports that map back to the game

A recompiled function's name is its N64 address (`func_800C2AB8`), sometimes with an overlay (`func_8080682C_bsfirstp`,
`ncpod_entrypoint_12`). Group a profile by game function across all entries, show where each is called from (the
callers file), and give its real name where the game has a symbol list or a decomp. This is how Banjo found its
biggest game-side costs: the FPU rounding-mode calls around float conversions, and the sound-slot busy-wait
`func_800C2AB8` before a map change.

### 7. Symbols kept for every build

Every build writes over its PDB (Banjo's `BanjoReTooie.pdb`), so crash and hang dumps from earlier builds can't be
named any more: Banjo's sweep dumps of 2026-11-07 couldn't. A script run after each build copies the PDB (and on
Android `libmain.so` with its symbols) into a local symbol store by commit, and a dump reader that picks the right
one for a dump by its build id. The store stays outside every repo.

### 8. Build tuning scripts

Profile-guided optimisation for the games and the runtime: a script that builds with `/GENPROFILE` (MSVC) or
`-fprofile-instr-generate` (clang), runs the sweep driver over a set route to train it, then rebuilds with the
profile. ThinLTO with clang-cl as an option. The recompiled game code is huge, and PGO's layout of hot and cold code
helps it most. LLVM BOLT does not support Windows binaries.

### 9. Phone driving

For Android builds: install the APK, start it, send console commands (an `adb` intent and a command file, planned in
Banjo's `TODO.md`, "Console commands on Android"), read output from logcat, pull screenshots, benchmark files and
crash reports, and run the sweep driver against the phone as against the PC. One script, `android_console.py`,
used by the sweep driver when the settings file says the target is a phone.

## Order of work

1. Make the repo; copy in Banjo's `perf_sweep.py` and `perf_report.py` and Mario Party's frame-check scripts as they
   are, with their history noted.
2. Write the settings file format and both games' settings files; make the driver and report read them. Check
   that a short sweep of each game gives the same results as its old tools did.
3. Merge the two profilers into one library; both games link it.
4. The symbol store script, then the slow-function report.
5. Comparison reports, then the PGO script.
6. Phone driving, once the Android console work in Banjo's `TODO.md` is done.

How the games use it: as a submodule or a checkout next to them; each game keeps only its settings file and its
console commands.

## Open questions for L

- The repo's name, and whether the games take it as a submodule or expect it next to them.
- Python for everything (Banjo's tools are), or keep Mario Party's PowerShell where it is.
- Which games beyond Banjo and Mario Party should have settings files from the start.
