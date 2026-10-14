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

- `TOOIE_SCREENSHOT_AT=ms[,ms...]`: takes an F12 screenshot at those times
  after the game started; files land in `screenshots/` in the run folder and
  `[screenshot] saved ...` is logged. Code: `src/game/screenshot.cpp`.

- `TOOIE_AUDIO_LOG=1`: prints `[audio]` every 2 s: how much audio was queued when each chunk arrived (normal is about 10 to 50 ms), how many chunks were sped up to cut latency, and how often the queue ran dry. Both counts should be 0 in normal play.
- `TOOIE_HIDE_HUD=1`: starts with the HUD hidden (as after F1).
- `TOOIE_FRAME_OVERLAY=1`: shows the frame rate overlay whatever the setting says. `TOOIE_FRAME_LOG=1` prints its figures every 2 s as `[frames]`, shown or not (src/game/frame_overlay.cpp). The game window is 1600x900, wider than a 1280x720 Xvfb screen, so its top left corner is off screen; start Xvfb at 1920x1080 to see it.

- `TOOIE_GAME_FPS=30|60`: Game Frame Rate as 30 or 60 FPS whatever the setting says. `TOOIE_GAME_FPS_LOG=1` prints `[game-fps]` every 2 s: game frames a second, the time steps the game asked for, the wait it asked for, game time against real time, and how far Banjo moved per second of game time (src/game/game_frame_rate.cpp). It also prints `[game-time]` at every map change and letterboxed scene start or end, with game time, real time, frame count and whether an attract demo is playing, to compare scene lengths between modes. Lavapipe at the default resolution caps the game near 15 fps; set `res_option` to `Original` and `msaa_option` to `None` in the run folder's graphics.json to reach 30.

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
- `TOOIE_NO_MODEL_TAGS=1`: turns off the matrix ids for frame interpolation (src/game/model_tagging.cpp), for before/after comparisons. Interpolation only runs with Framerate set to Manual (headless, Display gives no in-between frames).

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
- `TOOIE_BOTTLES=1`: turns on Cut Content: Bottles' Revenge (src/gameplay/bottles_revenge.cpp); Devil Bottles spawns in the next area loaded (checked at Mayahem Temple, map 0xB8).
- `TOOIE_SAVESTATE=<save ms>:<load ms>[:<load ms>...]`: saves, then loads at those times (src/gameplay/save_state.cpp). `TOOIE_SAVESTATE_LOG=1` lists the game threads and the queue each waits on at each save and load.
- `TOOIE_AIM_TEST=<dx>,<dy>,<from ms>,<to ms>`: adds that mouse motion (pixels) to each pad read in that window; `TOOIE_AIM_LOG=1` logs the first-person angles (src/input/motion_aim.cpp).
- `TOOIE_RAMDUMP=<ms>[,<ms>...]`: writes RDRAM as the game sees it (big-endian) to `ramdump_<ms>.bin` in the working folder at those times, for finding values by diffing (src/gameplay/save_state.cpp).
- `TOOIE_SCENE_FX_VIEW=<1-3>`: starts in that F6 effect view: 1 the scene effects pass alone (ambient occlusion and outlines as grey, rim light lighter, fog blue, sky magenta), 2 depth (near white, far dark, sky blue), 3 normals; `TOOIE_FX_COMPARE=1` starts with the F8 compare on; `TOOIE_AO_RADIUS=<units>` overrides the occlusion radius (src/display/effect_views.cpp, lib-patches/rt64.patch rt64_scene_effects.cpp, src/display/picture_filters.cpp).
- `TOOIE_WATER_TRACE=1`: logs player 0's state when it changes and whether it counts as under water (src/display/picture_filters.cpp).
- `TOOIE_PRESET_TEST=<n>`: picks Graphics > Effects preset n (1 Original, 2 Enhanced, 3 Retro) on the first frame, logs the settings, then changes Sharpening by hand (the preset should go to Custom); check graphics.json (src/display/picture_filters.cpp). Back up graphics.json first.
