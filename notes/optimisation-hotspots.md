# Optimisation hotspots (for Opus, later)

Marked by the Sonnet cleanup pass, 2026-11-03, by reading `src/` and `include/` and compiling every
`src/*/*.cpp` with `clang++ -fsyntax-only -Wunused`. **Nothing here was optimised.** Scope excludes
`lib/rt64`, `lib-patches/rt64.patch`, `rt64-ext/` and `RecompiledFuncs/`.

Context: [[verified-performance-facts]] says game threads were ~2-4% of one core in headless runs and the
GPU side dominates. So every cost below is a **rough guess from reading the code, not a measurement**.
Profile before touching any of it. The one place with real per-frame CPU work is `model_tagging.cpp`.

Line numbers are from `origin/main` 5da3f52 plus this branch.

## A. Likely real cost (per frame, scales with scene size)

| # | Where | Why it is hot | Rough cost |
|---|-------|---------------|-----------|
| A1 | `src/game/model_tagging.cpp:943-970` `pair_nearest` (called at 1853, 2228, 2320) | Builds every (now, last) pair within `limit` into a `std::vector<std::tuple<float,size_t,size_t>>`, `reserve(now*last)`, then sorts it. O(N*M) memory and compares each frame, one big allocation per call, per model group. Scenes with many copies of one model (grass, props, particles) make N*M large. | O(N*M) + O(P log P) per group per frame; reserve alone can be MBs for N,M ~ 1000. Grid/bucket by position or cap by `limit` would be O(N). |
| A2 | `model_tagging.cpp:1903-1914` (particles) | Same O(current * last_particles) double loop plus a fresh `std::vector<Candidate>` and sort every frame. | Same shape as A1; smaller N. |
| A3 | `model_tagging.cpp:2138` (shadow copies) | Linear scan of `last` per copy per model key (`n < last.size()`), inside the per-command loop. | O(copies^2) per key. |
| A4 | `model_tagging.cpp:1879,1944,1990-1996,2181` | Six to seven `std::vector<uint32_t>(commands.size())` zero-filled per frame in the tagging pass, plus `std::unordered_map<..., std::vector<...>>` locals at 1841, 1843, 2005-2006, 2188, 2201, 2271-2272, 2288-2289, 2340. All freed and rebuilt every frame. | Dozens of allocations per frame; list is thousands of commands. Keep them as reusable members (clear, not reconstruct). |
| A5 | `model_tagging.cpp:2048` | For each matrix command `i`, an inner `for j = i+1 ...` scan to the next matrix. If matrices nest or stop late this can approach O(n^2) in a long list. | Needs a count of commands scanned per frame to know. |
| A6 | `model_tagging.cpp:487, 497, 566, 1498` | Backward walks of up to 0x60000 / 0x80000 bytes by 8 (about 50-65k steps) and node chains up to 20000, reading RDRAM each step. Probably first-sight-only (cached by model, see the `static unordered_map` at 1392), but confirm they do not rerun on a cache miss every frame. | ~65k RDRAM reads per miss. |
| A7 | `src/game/heap_guard.cpp:65` | Walks the whole game heap, up to 200000 links, each `read_word` plus `good_link` (several more reads). Check how often `tooie_heap_guard` is called (hooked from the game, so plausibly every allocation or frame). | Up to ~200k iterations x ~4 reads if called per frame. Heap-check (`src/debug/heap_check.cpp`) is gated by `TOOIE_HEAP_CHECK`, the guard is not obviously. |
| A8 | `src/debug/dl_dump.cpp:85` | 20000-step loop. Developer-only (env gated); ignore unless the gate is wrong. | n/a |

## B. Small per-frame waste (easy wins, all low value)

| # | Where | Why | Cost |
|---|-------|-----|------|
| B1 | `src/game/game_frame_rate.cpp:458` | `std::getenv("TOOIE_POS_LOG")` on every game frame, with a `std::printf` it guards. Make it a `static const bool`. | One env scan per frame (~100s of ns). |
| B2 | `src/display/gfx_budget.cpp:92` | `std::getenv("TOOIE_GFX_LOG")` in the function that reads the draw-buffer heads (`room_for_extras` path, called by every extra draw per the project notes). Cache in a `static const bool`. | One env scan per call, many calls per frame. |
| B3 | `src/debug/heap_check.cpp:126` | `getenv("TOOIE_HEAP_CHECK")` on each check. Cache it. | Tiny. |
| B4 | `src/game/console.cpp:4190` `tooie_debug_log_on(env_name)` | Takes a global mutex and does a `std::unordered_map<std::string,...>` lookup (constructing a `std::string` from `env_name`) every call. If it is used from a hot path, callers should cache the result. Grep its callers first. | Mutex + hash per call. |
| B5 | `src/display/picture_filters.cpp` `value<T>()` (4267) | Every setting read does a `try`, a relaxed atomic load, and `graphics_config().get_option_value(id)` (a map lookup keyed by string, returns a `std::variant` copy). `apply()` calls it ~100 times; `apply()` is on-change only so this is fine today. Only matters if some caller starts invoking `apply()` per frame. | ~100 map lookups per `apply()`. |
| B6 | `src/display/picture_filters.cpp` `tick()` (about 4986-5100) | The map id is read with `MEM_HU(0, 0x80132DC2)` four separate times per frame in different blocks. Read once at the top. | 4 RDRAM reads (trivial), but tidier. |
| B7 | `src/display/picture_filters.cpp:4962-4980` | `fprintf` in a 250 ms-gated block; fine. Noted only because it sits in the per-frame path. | n/a |

## C. Duplicated constants and helpers (not done, would need a build to be safe)

- `constexpr gpr game_state_addr = (int32_t)0x80127630;` is repeated in 13 files: `debug/warp.cpp`,
  `debug/explode_test.cpp`, `game/asset_mods.cpp`, `gameplay/{photo_mode,test_room,transform_picker,save_state,enemy_spawner,
  transform_anywhere,replays,bottles_revenge,boss_rush}.cpp`; `race_warp.cpp` has a `uint32_t` copy. One
  `tooie::rdram::game_state_addr` in `include/tooie_rdram.h` would replace them all. Mechanical, but each
  file's `gpr` type use differs, so build-check each.
- Local copies of the `tooie_rdram.h` helpers that I did not switch because the semantics differ slightly
  (argument type `gpr` vs `uint32_t`, or signed vs unsigned return):
  - `input/motion_aim.cpp:80-95` (`valid_ptr(gpr)`, `read_float`, `write_float` take `gpr`)
  - `game/game_frame_rate.cpp:367,374`, `gameplay/fast_transitions.cpp:52,59` (`read_float`/`write_float` on `gpr`)
  - `gameplay/photo_mode.cpp:310,317`, `display/picture_filters.cpp:248` (`read_f32`)
  - `game/heap_guard.cpp:29` (`read_word` via `MEM_W`)
  - `gameplay/canary_mary.cpp:64-70` (`rd_float`/`wr_float`)
  - `game/achievements.cpp:592`, `gameplay/honeycomb_glitter.cpp:68` (`read_half` returns `uint16_t`, the shared one returns `int16_t`), `gameplay/torch_enemy.cpp` `read_half` (same reason, kept local)
  - `gameplay/original_honeycomb.cpp:29-35` and `gameplay/window_beams.cpp:117-123`: identical big-endian byte-vector `rd32`/`rd16`. Could share one header.
- `src/gameplay/totals_rules.inc:1742` `r_mega_glowbo` is defined but never referenced (forward-declared at 784). It is a game
  logic rule, so left in case it is waiting to be wired into the rule table. Remove if not.

## D. Left alone, unclear if dead

- `src/game/crash_handler.cpp:87,89` (`hang_dumps_kept`, `hang_rdram_stream`) warn unused on Linux only; they are used under `_WIN32`.
- `src/gameplay/enemy_spawner.cpp:673` lambda capture warning is a false positive caused by header drift in the lib submodules.
- `src/debug/parallax_pick.cpp:1028` Clang warns about a string literal concatenation in an array initialiser (missing comma?). Worth a look; changing it would change behaviour.
- `src/gameplay/free_camera.cpp:473` `&&` inside `||` without parentheses (precedence is probably right; confirm intent).
- `src/gameplay/day_night.cpp:343` aggregate initialiser misses the `tint` field (zero-initialised; fine).
