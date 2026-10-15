# Headless test runs (Linux container)

How to run the game without a display or a person, to check that it boots,
reaches a point in the game and does not hang. `tools/headless_boot.sh` does
the work. Read `tools/headless_boot.sh` and `src/debug/pad_script.cpp` if you
need the details.

## One-time setup

- Start a virtual display: `Xvfb :99 -screen 0 1280x720x24 &`
- The script needs `gdb` and ImageMagick (`import`, and `montage` for the sheet).
- Software Vulkan (lavapipe) is picked up from `/usr/share/vulkan/icd.d/lvp_icd.json`.
- Make a run folder (default `/home/claude/run`, or set `RUN_DIR`). It holds:
  - a copy of `BanjoTooieN64Recomp` (copy the exe, do not symlink it)
  - `assets/`
  - an empty `portable.txt`
  - the ROM, named `bt.n64.us.1.0.z64`

Build the exe first, then copy it into the run folder each time you rebuild.

## Usage

    [PAD='<pad script>'] [TOOIE_WATCH=addr,addr+len] [TOOIE_WARP=map:exit@ms] tools/headless_boot.sh <seconds> <tag>

- `<seconds>`: how long to run. A screenshot is taken every 20 s, so use a
  multiple of 20 where you can.
- `<tag>`: a name for this run. Output files start with it.
- `PAD`: scripted controller input, passed as `--pad-script`.
- `TOOIE_WATCH`: RDRAM words to print every 2 s. Each entry is a hex address,
  or `addr+len` (both hex) to print every word in that range. The watch is
  read from `src/game/debug_watch.cpp`.
- `TOOIE_WARP=map:exit[@ms]` (hex map and exit): warps with the game's own
  map change, `ms` after the game loop first runs (default: at once). From the
  title, `TOOIE_WARP=AF:0@15000` lands in Spiral Mountain about 20 s later with
  no file loaded, skipping the 10-minute intro. Logs `[warp] map ... (from map
  ...)`. Map ids are in handoff §4.80 and `src/game/level_warp_places.inc`.
  Several warps: `TOOIE_WARP=AF:0@15000,142:0@29000,...` (in time order).
  Code: `src/debug/warp.cpp`.

- `TOOIE_TEXTURE_DUMP=play|sweep`: sets General > Texture dump whatever the setting says. `TOOIE_TEXTURE_SWEEP_MAPS=B8,142,AF` sweeps only those maps (hex), `TOOIE_TEXTURE_DUMP_DIR=<dir>` writes there instead of `texture_dump/` (keep it out of the repo: the textures are ROM data). Logs `[texture-dump]` and `[texture-sweep]`. Code: `src/game/texture_sweep.cpp`. A sweep needs a map with a file, so pair it with `TOOIE_WARP=AF:0@15000`.

- `TOOIE_ASSET_DUMP=1`: dumps every asset whatever General > Dump assets says (to `TOOIE_ASSET_DUMP_DIR` if set). `TOOIE_ASSET_MODS_DIR=<dir>` reads replacements from there instead of `mods/assets`, and `TOOIE_ASSET_LOG=1` logs every asset the game loads by id with its kind (`[assets] load 0x08C1 (..., kind 0)`; kind 0 is a model). Code: `src/game/asset_mods.cpp`. Spiral Mountain loads 37 models; replacing 0x065E with 0x08C1 showed water in place of the ground, and replacing 0x062A with a static model crashed.

- `TOOIE_SCREENSHOT_AT=ms[,ms...]`: takes an F12 screenshot at those times
  after the game started; files land in `screenshots/` in the run folder and
  `[screenshot] saved ...` is logged. Code: `src/game/screenshot.cpp`.

- `TOOIE_AUDIO_DUMP=<file>`: writes the sound as it is queued (raw 32-bit float stereo at 48 kHz) to that file.
- `TOOIE_AUDIO_LOG=1`: prints `[audio]` every 2 s: how much audio was queued when each chunk arrived (normal is about 10 to 50 ms), how many chunks were sped up to cut latency, and how often the queue ran dry. Both counts should be 0 in normal play.
- `TOOIE_HIDE_HUD=1`: starts with the HUD hidden (as after F1).
- `TOOIE_FRAME_OVERLAY=1`: shows the frame rate overlay in Full whatever the setting says (`=compact` for Compact). `TOOIE_FRAME_LOG=1` prints its figures every 2 s as `[frames]`, shown or not (src/game/frame_overlay.cpp). The game window is 1600x900, wider than a 1280x720 Xvfb screen, so its top left corner is off screen; start Xvfb at 1920x1080 to see it.

- `TOOIE_FAKE_VSYNC=<hz>`: RT64 holds each present to that rate, like a vsync'd monitor (Xvfb + lavapipe presents at once). At 15 Hz the game still ran 30-49 fps at 120 FPS, so presents don't cap the game.
- `TOOIE_GAME_FPS=30|40|60|120|175|240|uncapped`: Game Frame Rate as that mode whatever the setting says (`unlocked` also means Uncapped; 40 and up pace the frames themselves with an extra VI after each swap; headless can't reach 40, so the fixed modes run in slow motion there, as 60 does, while Uncapped keeps game time at real time; `[game-fps]` shows the step used in ms). `TOOIE_GAME_FPS_LOG=1` prints `[game-fps]` every 2 s: game frames a second, the time steps the game asked for, the wait it asked for, game time against real time, and how far Banjo moved per second of game time (src/game/game_frame_rate.cpp). It also prints `[game-time]` at every map change and letterboxed scene start or end, with game time, real time, frame count and whether an attract demo is playing, to compare scene lengths between modes. Lavapipe at the default resolution caps the game near 15 fps; set `res_option` to `Original` and `msaa_option` to `None` in the run folder's graphics.json to reach 30.

- `TOOIE_PAD_GAME_TIME=1`: the pad script and `TOOIE_TELEPORT` count game time instead of real time, so a mode the container can't keep up with (120 FPS runs in slow motion) gets the same inputs at the same game moments. `TOOIE_UNCAPPED_FPS=<fps>[,<fps>...]` makes Uncapped step as if those frame rates were reached, in turn, whatever really went by (`1000` = a steady 1000 fps, `240,1000,60` = uneven frames). `TOOIE_POS_LOG=1` (with `TOOIE_GAME_FPS_LOG=1`) prints `[pos]` every frame: game time, the frame's step and Banjo's position. Swimming check (Spiral Mountain pool): `TOOIE_WARP=AF:0@15000 TOOIE_TELEPORT=1178,-377,471@40000 PAD='44000:y=1:2000;46500:b:300;47000:y=1:5000;47200:a:150;47700:a:150'`; at 30, 120, 240 and uneven Unlocked steps Banjo's path matched (src/game/game_frame_rate.cpp, src/debug/pad_script.cpp).

- Heap check (src/debug/heap_check.cpp): every game frame the game's heap is walked and the first damage is logged as `[heap] damage found ...` with the blocks around it and the map; on by default (also on PCs, for crash reports). `TOOIE_HEAP_CHECK=1` also prints `[heap] ok` every 600 checks, `=0` turns it off. The heap starts at the address held at 0x8007E990 and its size is at 0x8007BF00.

- Heap guard (src/game/heap_guard.cpp): before func_8001C0A0 walks the heap's block list, a next link that is outside the heap or doesn't link back is repaired and logged as `[heap] block ... repaired to ...`. `TOOIE_HEAP_BREAK=<n>` breaks a link on the nth walk (clears its top bit, as in L's 2026-10-15 crash, or writes `TOOIE_HEAP_BREAK_VALUE=<hex>`), to test the repair.

- `TOOIE_FX_LOG=1`: prints `[fx]` twice a second from the scene effects pass (fog strength and start, Banjo's position, the camera's world position worked out from the view matrix, the projection terms), `[fx-proj]` (a frame's perspective projections and which is the world's) and `[fx-draw]` (on the world's frame buffer: frames with the effects drawn, recorded, or skipped and why) (lib-patches/rt64.patch). `TOOIE_FX_RAW_VIEW=1` makes the effects use the game's own camera instead of the in-between camera that frame smoothing draws with, to compare the two.

- `TOOIE_SET="<ms>:<option>=<value>[,...];<ms>:..."`: changes Graphics options at those times after the game started, the way the menu does (saved and applied at once), to test live switching. Enum options take the index of their choice (`game_frame_rate` 0 Original, 1 30 FPS, 2 60 FPS; `rr_option` 0 Original, 1 Display, 2 Manual), number options a number (`rr_manual_value=120`). Logs `[set]`. It saves graphics.json in the run folder, so put that back afterwards (src/debug/settings_script.cpp).

- `TOOIE_FREE_CAMERA=1`: turns the free camera on whatever the setting says;
  `TOOIE_FREECAM_LOG=1` logs the camera, Banjo and stick 4 times a second
  (`[freecam]`). Drive the right stick with `rx=`/`ry=` in the pad script.
- `TOOIE_HONEYCOMB_LOG=1`: logs how many health honeycombs are loaded (src/gameplay/honeycomb_glitter.cpp). `TOOIE_HONEYCOMB_AT_PLAYER=1` makes the sparkles appear around Banjo, `TOOIE_HONEYCOMB_MODEL=<hex>` sparkles one more model, `TOOIE_HONEYCOMB_GO=<ms>` moves Banjo next to the first health honeycomb that long after one is first seen (9000 with `TOOIE_WARP=AF:0@15000` puts him by the three in Spiral Mountain's cave), and `TOOIE_HONEYCOMB_RATE=<x>` sparkles x times as often.
- `TOOIE_CUTSCENE_LOG=1`: logs `[cutscene] scene` / `gameplay` when a letterboxed scene starts or ends (src/gameplay/cutscene_skip.cpp). The skip itself always logs start and end.
- `TOOIE_FOV_LOG=1`: logs `[fov]` each time a camera's field of view or its gameplay/other kind changes (src/gameplay/field_of_view.cpp).
- `TOOIE_DLDUMP=ms[,ms...]`: writes the 3D scene's display list of the first frame after each time to dl_<ms>.txt in the working directory (matrices, vertex loads, segments, called lists), followed by the frame's 2D (pause menu, HUD, text). `TOOIE_DLDUMP_ALL=1` also prints each matrix in full and every other command raw.
- `TOOIE_PHOTO=<on ms>:<off ms>`: enters and leaves photo mode at those times; `TOOIE_PHOTO_LOG=1` logs the photo camera and the delta time (src/gameplay/photo_mode.cpp). The pad script drives it (x/y move, rx/ry look, z/r down/up, a screenshot, start time speed, b leave).
- `TOOIE_MUSIC=<entry>@ms[,...]`: picks Music player row entries (0 Level music, 1-48 jukebox, 49+ Track 0...) ms after the game loop starts. `TOOIE_MUSIC_LOG=1` logs the six music slots (track, volume, stopping, +0x34) every second (src/gameplay/music_player.cpp).
- `TOOIE_CUT_LOG=1`: logs `[cut]` each frame with how far the camera moved and turned, and whether frame interpolation treats it as a camera cut (src/game/model_tagging.cpp).
- `TOOIE_TAG_LOG=1`: logs `[ids]` each frame for every model with 20 or more tagged matrices: how many there are and how many ids carried over from the last frame (RT64 can only blend those).
- `TOOIE_INTERP_CHECK=1`: starts with the F7 interpolation check on (`[interp-check]` lines, red tint; src/debug/interp_check.cpp).
- `TOOIE_TAG_KEYS="25000:pick;27000:tag;29000:save;31000:unsave;33000:effects"`: presses the Pick Model, Tag Model, Save Tags, Unsave Tag and Model Effects keys at those ms after start (a tag switches the blend mode to custom) (manual interpolation tags, src/debug/interp_tags.cpp; `[interp-tags]` lines; with `TOOIE_TAG_LOG=1` also `[print]` lines naming every model once). The tags are read from and written to `interp_tags.txt` in the run folder.
- `TOOIE_RACE_WARP=<race 0-3>@<ms>`: asks for a Race Warps entry (0 GGM first race, 1 GGM second, 2 CCL first, 3 CCL second) that long after the game loop first runs; pair it with `TOOIE_WARP=AF:0@15000` and ask at 40000 or later. `TOOIE_RACE_LOG=1` logs `[race-warp]`: the flags stood in for, the race state every 2 s in the race and the restore when it is left (`=2` also logs every other flag read during the race). Pumping for a win: `PAD` with `<t>:a:120` every 240 ms. Code: `src/gameplay/race_warp.cpp`.
- `TOOIE_SET_FLAGS=<hex flag>[-<hex flag>][,...]`: sets those game flags once a map is loaded (src/gameplay/progress_cheats.cpp; flag names in the decomp's include/gameflags.h). `TOOIE_TOTALS_LOG=1` logs `[totals]` when the pause menu page changes, with each Totals level page's counts, and when Totals opens every collectible that can be got now (`[totals] now: MT: Golden Goliath Jiggy`) and how many areas are reachable (src/gameplay/totals_checklist.cpp). The rules are generated: `python3 -I tools/gen_totals_rules.py <AP_Banjo-Tooie>/worlds/banjo_tooie lib/bt-decomp/include/gameflags.h src/gameplay/totals_rules.inc` (clone https://github.com/jjjj12212/AP_Banjo-Tooie first). A Mayahem Temple Totals page with progress: `TOOIE_SET_FLAGS=392-39A,1E3-1EC,250-253,2DB-2DD,23F-240,222,44F-452 TOOIE_WARP=B8:0@15000 PAD='40000:start:150;43000:y=-1:150;46000:a:150;52000:x=1:300;55000:x=1:300;58000:x=1:300'` (QOL > Totals checklist is off by default: set `"totals_checklist_v2": true` in the run folder's qol.json first; 1E3-1EC are the "world visited" flags that make the pages show; Jinjo flags open the slow Jinjo page first, so leave them out). Then `62000:a:300` opens the Jiggies list, `66000:dd:300` steps down it and `84000:b:300` closes it; the log has `[totals] list ...` with every entry and `[totals] hint: ...` for each LATER one picked. Hold presses 300 ms: headless runs slowly and can miss a 150 ms press.
- `TOOIE_RUN_HOLD=<from ms>:<to ms>[,...]`: acts as the Run key held in those windows (after the first pad read). `TOOIE_RUN_LOG=1` logs `[run]` 10 times a second: form, state, animation, target and actual speed, the run animation's duration and its speed map, and the sprint blend (0 to 1; it eases over 0.35 s). `TOOIE_RUN_REBIND=<SDL scancode>` rebinds Run on the keyboard as the Controls tab does (src/gameplay/hold_to_run.cpp). `TOOIE_RUN_ANIM_TEST=1` plays the sprint on the spot while standing still. `TOOIE_RUN_ANIM_TUNE=<file>` replaces the sprint rules for tuning, lines `<anim hex> <bone> <type> <scale> <offset deg>`, and `@<ms>` starts a set used from that many ms after the first animation update. `TOOIE_RUN_ANIM_DUMP=<dir>` writes animation files as the game loads them (ROM data: keep out of the repo). Sprint animations are made at runtime from the run animation (format: s16 start, end, track count, pad; each track u16 bone<<4|type, s16 key count, keys of u16 0xC000|frame and s16 value; types 0-2 rotation in 1/64 degree, 3-5 scale, 6-8 translation). Banjo's lean bone is 3, his legs the chains 6-10 and 20-24, his arms 12-16 and 26-30; Kazooie's legs are 6-12 and 20-26, her body 106. Measured: run state 4 (Banjo-Kazooie and Banjo alone, animation 0xC) and 199 (Kazooie alone, 0xA6); the forward roll is state 49.
- `TOOIE_NO_MODEL_TAGS=1`: turns off the matrix ids for frame interpolation (src/game/model_tagging.cpp), for before/after comparisons. Interpolation only runs with Interpolation (formerly Framerate) set to Manual (headless, Display gives no in-between frames).

## Pad script syntax

Pass the script with `--pad-script '<steps>'` (tools/headless_boot.sh does this from `PAD`).

Steps are separated by `;`. Each step is `time_ms:action[:hold_ms]`, with
times counted from the game's first controller read.

- Buttons, joined with `,`: `a b z start l r du dd dl dr cu cd cl cr`.
  Held for `hold_ms` (default 150).
- Stick: `x=<-1..1>` and `y=<-1..1>`, mixed freely with buttons.
- Right stick: `rx=<-1..1>` and `ry=<-1..1>` (up is positive), read by the
  free camera.
- `quit` ends the program.
- Scripted input is added to player 1's real input.

Worked example: press Start every 3 s from 15 s to 45 s, then A every 2.5 s
until 60 s, then quit. Run it for at least 70 s:

    PAD='15000:start;18000:start;21000:start;24000:start;27000:start;30000:start;33000:start;36000:start;39000:start;42000:start;45000:start;47500:a;50000:a;52500:a;55000:a;57500:a;60000:a;62500:quit' \
        tools/headless_boot.sh 70 newgame

## Reading the outputs

- `<tag>-N.png`: a screenshot every 20 s.
- `<tag>-all.png`: all screenshots in one sheet (needs `montage`).
- `<tag>.log`: the game's output. The script prints its last 15 lines.
- `<tag>-gdb.txt`: a backtrace of every thread, taken at the end.
- The script also prints a summary of the game threads from that backtrace.
  If one game thread is stuck inside a `func_` while the others sit in
  `osRecvMesg`, that is a busy-wait livelock. The fix is a preemption point in
  the loop: see `src/game/preempt.cpp`, and the hooks in `banjotooie.us.toml`
  that call `tooie_preempt_point`.

## Do not use `pkill -f`

`pkill -f` matches the full command line, which includes the shell running
the test, so it can kill that shell too. The script uses `pgrep -x` and kills
by exact process name. Do the same when you clean up by hand.

## Finding the code behind something on screen

Use the call profiler to see which functions run while something is on screen.

1. Build the profiling copy: `tools/trace_build.sh`. It builds `build-trace/`,
   where every recompiled function counts its calls. Nothing it makes is
   committed.
2. Run it with `TOOIE_TRACE=calls.txt`. The game writes the calls made in each
   2-second window to `calls.txt`, one block per window.
3. Compare two stretches of time with `tools/trace_diff.py`:

       tools/trace_diff.py calls.txt A_FROM-A_TO B_FROM-B_TO [--top N]

   Windows are numbered as they are in the file. The output lists functions
   called in the B windows but never in the A windows, then the functions whose
   call rate changed the most. For example, A is the HUD hidden and B is the HUD
   shown, which points to the HUD's draw code.

Details are in `include/trace.h`, `src/debug/trace.cpp` and
`tools/trace_diff.py`.
- `TOOIE_BOTTLES=1`: turns on Cut Content: Bottles' Revenge (src/gameplay/bottles_revenge.cpp); Devil Bottles spawns in the next area loaded (checked at Mayahem Temple, map 0xB8). Outside Spiral Mountain it first warps there for the mode's intro if game flag 0xCA is unset, then back (`[bottles] intro ...` lines); `TOOIE_WARP=B8:0@15000` with A pressed every 2 s from 50 s shows the whole trip in about 300 s.
- `TOOIE_SAVESTATE=<save ms>:<load ms>[:<load ms>...]`: saves, then loads at those times (src/gameplay/save_state.cpp). `TOOIE_SAVESTATE_LOG=1` lists the game threads and the queue each waits on at each save and load.
- `TOOIE_AIM_TEST=<dx>,<dy>,<from ms>,<to ms>`: adds that mouse motion (pixels) to each pad read in that window; `TOOIE_AIM_LOG=1` logs the first-person angles (src/input/motion_aim.cpp).
- `TOOIE_RAMDUMP=<ms>[,<ms>...]`: writes RDRAM as the game sees it (big-endian) to `ramdump_<ms>.bin` in the working folder at those times, for finding values by diffing (src/gameplay/save_state.cpp).
- `TOOIE_SCENE_FX_VIEW=<1-4>`: starts in that F6 effect view: 1 the scene effects pass alone (ambient occlusion and outlines as grey, rim light lighter, fog blue, sky magenta), 2 depth (near white, far dark, sky blue), 3 normals, 4 water (red mask, yellow where it reflects; `TOOIE_WARP=AF:1@15000` faces the Spiral Mountain pool); `TOOIE_FX_COMPARE=1` starts with the F8 compare on; `TOOIE_AO_RADIUS=<units>` overrides the occlusion radius (src/display/effect_views.cpp, lib-patches/rt64.patch rt64_scene_effects.cpp, src/display/picture_filters.cpp).
- `TOOIE_WATER_TRACE=1`: logs player 0's state when it changes and whether it counts as under water (src/display/picture_filters.cpp).
- `TOOIE_TELEPORT=<x>,<y>,<z>@<ms>`: puts Banjo at that place (held for 30 frames) that long after the program started. `1178,-377,471@40000` with `TOOIE_WARP=AF:0@15000` drops him in a deep Spiral Mountain pool; dive with `PAD='46000:b:300;47000:y=1,b:4000'` (src/display/picture_filters.cpp).
- `TOOIE_PRESET_TEST=<n>`: picks Graphics > Effects preset n (1 Original, 2 Enhanced, 3 Retro) on the first frame, logs the settings, then changes Sharpening by hand (the preset should go to Custom); check graphics.json (src/display/picture_filters.cpp). Back up graphics.json first.
- `TOOIE_ASYNC_DL=1`: the game no longer waits for the renderer to read each display list it sends (the old behaviour; lib-patches/N64ModernRuntime.patch, submit_rsp_task). `TOOIE_EARLY_SP_DONE=1` also reports the RSP done before the list is read, as upstream does. `TOOIE_DL_DELAY_MS=<n>` makes the renderer wait n ms before reading each list. Together they bring back the race where the game rewrote vertices the renderer was still reading (Jinjo Village, `TOOIE_WARP=142:0@15000`: about 1 frame in 3 headless).
- `TOOIE_VP_SPLIT_LOG=1`: logs `[vp-split]` whenever RT64's split of the game's camera matrix into view and projection does not multiply back to the input (lib-patches/rt64.patch, rt64_math.cpp). `TOOIE_OLD_VP_SPLIT=1` uses the old split, which went wrong with the camera facing nearly along z: `TOOIE_WARP=136:0@15000 TOOIE_FREE_CAMERA=1 PAD='35000:rx=0.3:80000'` (a Cloud Cuckooland spin) logged 34 bad frames in 2 minutes with it, none without.
- `TOOIE_BURST=<from ms>:<to ms>`: acts as F12 held over that window. Holding F12 for half a second keeps every presented frame, shrunk 4x, in a ring of the last 150; letting go writes them to `screenshots/burst-<stamp>/000.png...` (src/game/screenshot.cpp). For glitches that last a frame or two.

- `TOOIE_BENCHMARK=<seconds>`: records a benchmark (the Benchmark key's files in `benchmarks/`) for that long from the first game frame; the log prints `[benchmark] saved ...`.

- `TOOIE_DAY_NIGHT=<0 Off, 1 Cycle, 2 Morning, 3 Sunset, 4 Night>`: Graphics > Day and Night whatever the setting says; `TOOIE_TIME_OF_DAY=<0 to 1>` starts the clock there (0 midnight, 0.5 noon), `TOOIE_DAY_LENGTH=<minutes>` (can be below the menu's 4, e.g. 0.5) and `TOOIE_SUN_FRONT=<x>,<y>` puts the sun at that view-space spot (camera looks down -z; `0.3,0.45` is in the Spiral Mountain sky at the warp start) to see the sun and lens flare, and `TOOIE_DAY_NIGHT_LOG=1` logs `[day-night]` every second of game time: map, time, tint, sun and night sounds (crickets, owls, birds; src/gameplay/day_night.cpp, src/gameplay/night_sounds.cpp). Night in Spiral Mountain: `TOOIE_DAY_NIGHT=4 TOOIE_WARP=AF:0@15000 TOOIE_SCREENSHOT_AT=55000`. The tint is packed in the scene effects' `shadows.z` push constant (lib-patches/rt64.patch).
