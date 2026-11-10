# TODO

Open issues that are known but not fixed yet. Newest first.

## Renderer waits for the GPU on every game frame (performance sweep, 2026-11-07)

RT64's workload thread records a game frame, submits it and waits for the GPU before taking the next
(`WorkloadQueue::threadRenderFrame`: `execute(); wait();`), so the CPU and GPU never overlap. In Terrydactyland with
the Enhanced preset the renderer's 2.9 ms a frame was 1.4 ms preparing draws, 0.4 ms recording and 1.0 ms waiting for
the GPU, whose own time was 0.9 ms (benchmark csv `renderer_*_ms`). Letting one frame be in flight would hide most of
that wait, more so on slow GPUs, but every per-frame resource of the renderer (command lists, upload buffers, the
framebuffer renderer's scratch) would need a second copy, and read-backs to RDRAM still have to wait. A big change to
RT64's core; measure with `tools/perf_sweep.py` before and after.

Also from the sweep, not done yet:

- Sun shadows still cost Terrydactyland about 2 ms a frame of RT64 CPU time (3.7 ms against 1.6 ms with
  `TOOIE_SUN_CULL=0`): the swept test (`src/game/widescreen.cpp`) keeps much of the level at its low fixed sun.
  Since 2026-11-10 the sweeps stop at the ground under each piece (a grid of the lowest piece bottoms), not the
  level's lowest point: over the same TDL camera path that kept 40,600 culled pieces against 62,500
  (`TOOIE_SUN_SWEEP=floor`), with about the same faces in the shadow map (3,400 against 3,600). The time saved is not
  measured yet: the runs on L's PC swung from 160 to 285 FPS between runs of the same build while other work ran.
- A map change shows no new frame for 1-2 s while the game keeps updating (worst frame 1.7-2.0 s on arrival in most
  maps). It looks like the game's own black hold, not a stall: the game thread waits, and the sound-slot release
  (`src/game/preempt.cpp`) never hit its 2 s limit.

## Dual screen support with a map, also on Android (asked by L, 2026-11-07)

A second screen (a second window on a PC, or the second screen of a dual-screen handheld, Android ones included)
that shows a map of the area Banjo is in, with where he is. With two screens the HUD (honey, notes, eggs and the
other counters) moves to the bottom screen, and the start (pause) menu stays on the main screen.
Not started. To work out first: where the map comes from (the game's own pause-menu art is game data and stays out
of the repo; a map drawn at run time from the level's geometry or from what the game already shows), how a
second window or display fits RT64's single swapchain, how Android reports a second display (the Presentation API
on dual-screen handhelds), and how the HUD's draws are told apart from the world's to move them.

## Map screen for single-screen players, in the start menu (asked by L, 2026-11-07)

The same map as above on one screen: a Map page in the start (pause) menu that shows the area and where Banjo is.
Shares the map drawing with the dual-screen work.

## Graphical effects sweep, with research (asked by L, 2026-11-07)

A sweep of every map with each of the port's effects (Sun Shadows, Ambient Occlusion, the reflections, water,
snow and sand, fur, light shafts, volumetric shadows and the rest) on in turn: what each costs on the GPU and the
CPU per map (Effect Cost Check, `bench`, `hostprof`, `tools/perf_sweep.py --setup`), and screenshots to check how
each looks. First read up on how other ports and engines make the same effects cheaper (lower-resolution passes,
temporal reuse, culling what is off screen), then fix the heaviest. The performance sweep found Sun Shadows (fixed
in part), Ice Reflections (0.27 ms of GPU in Hailfire Peaks' Ice Train Station) and Ambient Occlusion (0.13 ms) the
heaviest with the Enhanced preset.

## Sweep crashes of 2026-11-07: what is left (asked by L, 2026-11-07)

The logs are in `D:\Projects\Banjo Tooie N64\crash_logs\2026-11-07\` (outside the repo). Guards for the Tower of
Tragedy quiz (0x15F), the intro characters (0xA3, 0xAC, Mayahem Temple's parade 0x167), the intro scenes' music wait
when warped into, and a repair of the heap's free list (GI Floor 3, 0x109) landed on 2026-11-10; the watchdog's hang
reports now give the map. Still to do:

- Run the texture sweep through 0x15F and 0x167, and the performance sweep through the intro scenes (0xA1-0xAC), to
  see the quiz and intro-character guards catch what they were written for. A single console warp into those maps
  did not bring the faults back, so those two guards are tested only against the logged faults.
- Find what wrote the float -1200.8 (0xC4961900) into a freed heap block in GI Floor 3. The free list is now rebuilt
  when that happens, and the `[heap]` line gives the link's address and the map; `writewatch` on that address in a
  long warp run could catch the writer. The port's own hooks that write floats into game objects (size cheats,
  jiggle, transform menu, free camera) are the first suspects.
- The 21 s hang at 03:56:16: RT64's texture dump writes its files on the graphics thread, and one `fclose` stalled
  (disk or virus scan). Writing the dumps on a worker thread (`lib-patches/rt64.patch`) would keep the game going.

## Presets and default controls, keyboard and controller (asked by L, 2026-11-07)

Settings presets that set many options at once (the Effects Preset does this for the picture: Original, Enhanced,
Retro) for the rest of the game too, and a good default control layout for both keyboard and mouse and controllers,
set on first start and restorable from the Controls tab. To work out: which presets (for example Original,
Recommended, Performance, and a phone one), and what the default bindings should be for each kind of controller.

## Ray tracing fine tune (asked by L, 2026-11-07)

Go through the ray tracing options (reflections, water and metal reflections, shadows, light, path tracing, traced
light beams) for how they look and what they cost, map by map: settle good defaults and strengths, fix what looks
wrong, and cut what costs much for little. Pairs with the graphical effects sweep above.

## Menu cleanup (asked by L, 2026-11-07)

A pass over the settings and start menus: options in the right tabs and groups, names and descriptions that say
what each does, no doubles, hidden debug options out of the way, and the order of the tabs and rows.

## Console commands on Android (asked by L, 2026-11-07)

Today the console takes commands from stdin, `--exec <file>`, `TOOIE_CONSOLE` and `autoexec.txt`. A phone has no
terminal, so only `autoexec.txt` works there, and only at start-up. Output goes to `logs/console.log` in the app's
folder (`Android/data/io.banjoretooie/files`), which `adb` may not be able to read on newer Android versions.

1. **Commands by `adb` intent:** `adb shell am broadcast -a io.banjoretooie.CONSOLE --es cmd "warp id AF; wait control; pos"`.
   `GameActivity` gets a receiver that passes the text through JNI into the console's queue (`enqueue_line` in
   `src/game/console.cpp`, behind a new public `tooie::console::submit`), as if typed. It works however strict the
   phone is about file access. It requires the `DUMP` permission (`registerReceiver(..., "android.permission.DUMP",
   null, RECEIVER_EXPORTED)`): `adb shell` has it and ordinary apps can't get it, so no other app on the phone can
   send the game commands.
2. **Command file:** done on the desktop as `console_inbox.txt` in the config folder (`src/game/console.cpp`); not
   yet checked on a phone. As planned: lines added to `console_in.txt` in the app folder run as if typed, and the file is then emptied
   (a thread looks every 200 ms, renames the file before reading it so lines written meanwhile wait for the next
   look). This also works on Windows when the game is started without a terminal, and for longer scripts: `adb push`
   a file, or `adb shell "echo 'warp id AF' >> .../console_in.txt"`.
3. **Output to logcat:** every console line also goes to Android's log (`__android_log_print`, tag `BanjoReTooie`, in
   `out_lines`), so `adb logcat -s BanjoReTooie` shows results live, errors marked as warnings. `console.log` is
   still written as well.
4. **Pulling files:** `screenshot`, `bench`, `hostprof`, saves and crash logs all write into the app folder. When
   `adb` can't read that folder, add a `share <file>` command that copies a file into the phone's Downloads, where
   `adb pull` always works.
5. **Typing on the phone:** the existing console prompt opens on the `` ` `` key, which a phone keyboard lacks. Add a
   way to open it (a five-finger tap, or a hidden button in the start menu) so commands can be typed on the phone.
6. **Driving it from the PC:** a small script, `tools/android_console.py`, that installs the APK, sends commands,
   waits for their output in logcat and pulls screenshots, so the PC sweeps (`tools/perf_sweep.py` and the rest) can
   run against the phone.
7. **Docs and tests:** an "On Android" section in `docs/console.md` with the exact `adb` lines. The command file and
   the logcat output are checked on Windows first (through Windows' own debug output); the intent and the rest on a
   phone connected over USB with USB debugging on.

Steps 1-3 and 7 are the core, a few hours with builds; 4-6 make testing on a phone much easier.

## Move features out of the port into bundled mods (asked by L, 2026-11-07)

Move as much as can be out of the port's own code and into mods that ship with the port, on by default where the
feature is today and switchable in the Mods tab like any other mod. Jiggle physics (snout, belly, ears, fur,
backpack, Kazooie, Mumbo: `src/gameplay/snout_jiggle.cpp`) is the first example. Others to weigh: cheats, the enemy spawner,
gameplay options (Enemy Respawn, Minjos Stay Dead, Mirror Mode, Boss Rush), the Transform Anywhere Menu, photo mode's
filters, model mods' helpers. What stays in the port: what needs the runtime or RT64 (renderer effects, input,
saves, the console, crash handling). To work out first:

- What a mod can reach today: N64Recomp mods (`.nrm`) patch and hook game functions and call exported port
  functions, but can't add RT64 passes or settings-menu pages of the port's kind. Each feature moved needs its hooks
  (`banjotooie.us.toml`) and settings expressed as a mod's hooks and the mod's own config options.
- How bundled mods ship: built with the port (`cmake/mods/`), copied into the mods folder at install, updated with
  the port, and not counted as the player's own mods.
- That a moved feature behaves the same: same defaults, settings carried over from the port's config, same
  console commands (or console commands a mod can add).

## Download mods straight from GitHub, texture packs included (asked by L, 2026-11-07)

A way to get mods from inside the game: a list in the Mods tab of mods and texture packs published on GitHub
(releases of known repositories, or a list file the port's repo keeps), with download, install, update and remove,
so nothing has to be unpacked by hand. Texture packs are one kind (BT Reloaded and the like, today dropped into the
mods folder as a `.zip` and unpacked by `src/game/mod_zips.cpp`); `.nrm` mods and asset mods (model mods) the
others. To work out first:

- Where the list comes from and who keeps it; GitHub's releases API (rate limits without a token: 60 an hour).
- Big downloads (a 4K texture pack is gigabytes): progress, resuming, free disk space, and on Android the app's
  own folder and mobile data.
- Trust: only repositories on the list, checksums for what is downloaded, and no mod code from unknown places run
  without the player saying yes.
- The game's own files are never part of a pack (AGENTS.md): packs are the authors' own art.

## Renderer plugin system, ray tracing as the first plugin (asked by L, 2026-11-07)

The `.nrm` mods run on the game's side and can't add GPU passes, so ray tracing (RT64 and `rt64-ext`: its shaders,
acceleration structures, Vulkan ray queries and DXR, switched from `src/display/picture_filters.cpp`) can't become a
mod as mods are today. A plugin system for the renderer would let it: native plugins (a DLL, or a `.so` on Android)
that RT64 loads and that register their own passes, shaders and settings. Ray tracing would be the first, and the
port's other effects could follow.

Performance, worked out before starting:

- The GPU work is the same (the same shaders on the same GPU), and that is nearly all of ray tracing's cost.
- With the plugin off or missing nothing is called: nothing costs anything, a little better than today.
- Calls through the plugin interface go through function pointers, a few ns each, a handful to a few dozen a frame:
  well under a microsecond against 2-4 ms frames (performance sweep, 2026-11-07).
- No inlining across the boundary: the interface must be per pass, never per draw or per triangle.
- The real risk: the plugin needs RT64's scene data every frame (draw lists, vertices, transforms, textures,
  framebuffers). Copied into a format of the plugin's own, that could cost as much as the renderer's whole draw
  setup (about 1 ms a frame in Terrydactyland); handed over as read-only views of RT64's own buffers, it costs
  nothing. That is the main design work.
- Other costs, not speed: the interface has to keep up with RT64 updates, plugin and port are built and versioned
  together, and a crash in a plugin still ends the game.

A simpler step first: a CMake switch (`TOOIE_RAY_TRACING=OFF`) that leaves the ray tracing code and shaders out of a
build (Android, low-end PCs), as the options are already hidden there.

## Texture dump: what is left (2026-11-08)

The dump records each texture's context (map, entrance, HUD, the asset it belongs to; `src/game/texture_context.cpp`
and RT64's display-list hook) and `tools/organize_textures.py` sorts a dump by it. Still open:

- A dump found emptied: on 2026-11-08, after a short `sweep fast` test, `texture_dump/png` held only that test's 2,367
  textures, where the full sweep's 8,728 PNGs and its `rt64.json` had been. No code in `texture_sweep.cpp` removes the
  folder, so the cause isn't found. Back the folder up before the next quick pass and check whether a start or a resume
  empties it. The 8,728 are still in `D:\Projects\Banjo Tooie N64\texture_organized_test` (hard links, with
  `manifest.csv`).
- `rt64.json` is only written when dumping stops (`write_pack_database`). A game closed or crashed mid-sweep leaves
  none, and the organiser then stops with "no readable rt64.json" (L hit this, 2026-11-08). Write it as the dump goes,
  or let the organiser build it from the PNGs and their json files.
- The Texture Dump option stays on "Sweep all maps" after a sweep finishes, and `TOOIE_TEXTURE_DUMP=sweep` saves it
  that way to `wip.json`, so the menu shows it as if it were the default (L, 2026-11-08). A finished or stopped sweep
  should set it back to Off, and the environment variable should not be saved.
- The folders only appear when the organiser is run by hand. Run it at the end of a sweep (L asked, 2026-11-08).
- In the hook's test run (map 0xAF), `dl_command` went up to 0xD5A9A0, above the 8 MB of N64 memory, while `dl_list`
  stayed below it; probably display lists called from the top-level one in the port's extended memory. Check before
  relying on the addresses for anything beyond what `texture_context.cpp` does now. 12 of that run's 131 textures had no
  recorded load (both fields 0) and so no context.
- `sweep fast` and `sweep more` have only had short runs: a whole fast pass followed by a more pass is still to do.

## Earlier open items

L asked (2026-11-07) for the items already in this list to be worked through as well, after the above.

## Jiggywiggy challenges may slow down above 30 FPS (2026-11-03)

Challenges (the jigsaw puzzles) now run at the chosen Game Frame Rate instead of the recorded 30: the replay is
sub-stepped, one recorded entry every 1/30 s with the frames in between repeating its input
(`src/game/game_frame_rate.cpp`, `tooie_replay_substep` / `tooie_demo_frame`). The game speed and the countdown stay
right (the countdown counts real seconds; checked in the game).

What may be wrong: at Unlocked, a challenge can lose frame rate over time, and a later challenge in the same session
starts slower (seen 280-420 game updates/s on a first challenge, then about 80 falling to 20-30 on a second one, which
also runs the challenge in slow motion). One test run of this ended in `VK_ERROR_DEVICE_LOST`. Results varied between
runs: one run was already at about 94 updates/s before any challenge.

It may not be the game at all: while these runs were made, other recomp builds (unrelated to this test, compiling on
the same PC) may have been running and taking the CPU and GPU, which would explain both the slowdowns and how much
the numbers varied from run to run. Re-test on an idle PC before chasing it further. L (2026-11-03) saw normal frame rates in a challenge playing it
themself, which fits this.

What is known:

- It is not the game side: heap blocks stay flat, the display list is small (`gfx` 3-4 %), one controller read per
  update, the replay bytes are cleared when the challenge is left, and leaving the map and coming back doesn't help.
- It is not the frame-rate switch: going from 30 to Unlocked with no challenge first doesn't slow anything.
- On RT64's game-thread side nothing grows without bound (`TOOIE_FB_LOG=1`): no GPU waits, no read-backs to RDRAM,
  6-8 framebuffers, 12 → 52 tile copies (then flat), 120-180 textures cached. Full-sync time doesn't follow the
  slowdown, so the time goes somewhere else, most likely RT64's workload thread.
- During a challenge the game renders the recorded run into a 160x128 picture at 0x80382000 every game update and
  draws it on the board; sub-stepped at ~300 updates/s that is about 10 times the 30 FPS amount of work.

Next steps:

1. Time the workload thread (`WorkloadQueue::threadRenderFrame`): frames, ms per phase, its tile copies and render
   targets, texture uploads.
2. Possible fix that doesn't need the cause: while sub-stepping, let the game redraw the board's picture only when a
   new recorded entry is taken (about 30 times a second), so RT64's picture work stays at the 30 FPS level.

Repro with the console (`docs/console.md`): `fps Unlocked`, `goload 1 14F 0`, `goload 1 151 1`, `wait control 90`,
`goto 1891 199 20`, `wait control 30`, `press b 300ms`, then `repeat 12 press a 200ms; wait 1.2s`; wait about 30 s,
`warp id 14F 0`, and start the challenge again the same way. Run with `TOOIE_DEMO_LOG=1` (updates/s and entries/s each
second) and `TOOIE_FB_LOG=1`.

## Jigsaw board: faint lines along the pieces (2026-11-03, left as the game draws it; the fix to be an option)

Thin lines follow the board's piece grid at every resolution (native 406x228 too), so they are the game's own. The
dotted cracks between pieces are fixed (vertex snap). Each piece samples only its own 32x32 block of the 160x128 live
picture, with the tile wrapping every 32 texels, and its shape reaches a little past that block: those edge pixels
read the block's far side. Tried and dropped: sampling at the native pixel centre (pixelated, lines stayed), holding
the edge texel (thicker line), holding one texel in (thicker still), leaving the edge pixels out (shows the board's
gold slot outlines beneath).

A real fix has to sample the whole picture, not the per-piece block:
- A: sample RT64's GPU render target of the picture (0x80382080, 160x128) with the block offset and no wrap: high
  resolution and true neighbour pixels, but wrong wherever the game's CPU writes into the picture.
- B: upload the synced picture from RDRAM as one texture and sample that: always right, stays native resolution,
  needs a new RDRAM-layout upload path in RT64.
- C: A, falling back to the game's sampling on frames the CPU changed the picture.
Needs changes in RT64's tile setup and tile copies (rt64_state.cpp, rt64_framebuffer_manager.cpp).

L (2026-11-07): the fix is to be an option (on or off in the settings), so the board can still be drawn as the
game draws it.

## Smaller open items

- Settings: `session_log` reads settings once every 2 s; the settings store is now locked (N64ModernRuntime patch), so
  this is only a note if new threads start reading settings.
- Effect Debug View and Effect Compare: the menu rows don't follow the F6 / F8 keys any more (the keys no longer write
  the settings from their own thread).
- Not yet played through in the game since the bug review fixes: boss rush (a fight over two maps would now end the
  rush), Dive with transformations, Cheato flags per save file, photo mode exit, the pause menu highlight.
