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
  Shorter sweeps (to the ground under each piece rather than the level's lowest point) would keep less.
- A map change shows no new frame for 1-2 s while the game keeps updating (worst frame 1.7-2.0 s on arrival in most
  maps). It looks like the game's own black hold, not a stall: the game thread waits, and the sound-slot release
  (`src/game/preempt.cpp`) never hit its 2 s limit.

## Dual screen support with a map (asked by L, 2026-11-07)

A second screen (a second window, or the second screen of a dual-screen handheld) that shows a map of the area
Banjo is in, with where he is. For single-screen players the map is an option: shown in a corner or on a key.
Not started. To work out first: where the map comes from (the game's own pause-menu art is game data and stays out
of the repo; a map drawn at run time from the level's geometry or from what the game already shows), and how a
second window fits RT64's single swapchain.

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

## Jigsaw board: faint lines along the pieces (2026-11-03, left as the game draws it)

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

## Smaller open items

- Settings: `session_log` reads settings once every 2 s; the settings store is now locked (N64ModernRuntime patch), so
  this is only a note if new threads start reading settings.
- Parallax / Displaced ground: with more than 8 cameras in a frame, the later draws are drawn flat (`[parallax]` line
  with `TOOIE_FX_LOG=1`). Never seen so far.
- Effect Debug View and Effect Compare: the menu rows don't follow the F6 / F8 keys any more (the keys no longer write
  the settings from their own thread).
- Not yet played through in the game since the bug review fixes: boss rush (a fight over two maps would now end the
  rush), Dive with transformations, Cheato flags per save file, photo mode exit, the pause menu highlight.
- The console can't change High-precision framebuffer (`hpfb_option` isn't in its setting list).
