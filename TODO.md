# TODO

Open issues that are known but not fixed yet. Newest first.

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
the numbers varied from run to run. Re-test on an idle PC before chasing it further.

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
