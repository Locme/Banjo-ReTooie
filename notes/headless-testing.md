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
- `TOOIE_MAP_CHANGE_LOG=1`: logs every map change the game asks for, as `[map-change] to map 0x.. exit N (from map 0x..)`, to find exit ids (src/debug/warp.cpp). To find which exit puts Banjo by something, warp to each exit in turn (through a small map between them, since a warp to the map you are in does nothing) with a screenshot well after the wipe: Glitter Gulch Mine exit 8 is outside Mumbo's Skull.

- `TOOIE_TEXTURE_DUMP=play|sweep`: sets General > Texture dump whatever the setting says. `TOOIE_TEXTURE_SWEEP_MAPS=B8,142,AF` sweeps only those maps (hex), `TOOIE_TEXTURE_DUMP_DIR=<dir>` writes there instead of `texture_dump/` (keep it out of the repo: the textures are ROM data). Logs `[texture-dump]` and `[texture-sweep]`. Code: `src/game/texture_sweep.cpp`. A sweep needs a map with a file, so pair it with `TOOIE_WARP=AF:0@15000`.

- `TOOIE_ASSET_DUMP=1`: dumps every asset whatever General > Dump assets says (to `TOOIE_ASSET_DUMP_DIR` if set). `TOOIE_ASSET_MODS_DIR=<dir>` reads replacements from there instead of `mods/assets`, and `TOOIE_ASSET_LOG=1` logs every asset the game loads by id with its kind (`[assets] load 0x08C1 (..., kind 0)`; kind 0 is a model). Code: `src/game/asset_mods.cpp`. Spiral Mountain loads 37 models; replacing 0x065E with 0x08C1 showed water in place of the ground, and replacing 0x062A with a static model crashed.

- `TOOIE_SCREENSHOT_GAME=1`: `TOOIE_SCREENSHOT_AT`, `TOOIE_WARP`, `TOOIE_REPLAY` and `TOOIE_PHOTO` count game time (what the game's frames add up to) instead of real time, so runs at different frame rates (the container reaches 30 to 60 game fps, a stepped 175 runs at about x0.35) line up at the same game moments. Use it with `TOOIE_PAD_GAME_TIME=1` to compare 30 FPS against 60, 120, 175 or `TOOIE_UNCAPPED_FPS` runs. `TOOIE_TELEPORT` holds 30 frames, not 30 game ms, so its camera settles differently per rate; avoid it for comparisons.
- `TOOIE_SCREENSHOT_AT=ms[,ms...]`: takes an F12 screenshot at those times
  after the game started; files land in `screenshots/` in the run folder and
  `[screenshot] saved ...` is logged. Code: `src/game/screenshot.cpp`.

- `TOOIE_AUDIO_DUMP=<file>`: writes the sound as it is queued (raw 32-bit float stereo at 48 kHz) to that file.
- `TOOIE_AUDIO_LOG=1`: prints `[audio]` every 2 s: how much audio was queued when each chunk arrived (normal is about 10 to 50 ms), how many chunks were sped up to cut latency, and how often the queue ran dry. Both counts should be 0 in normal play.
- `TOOIE_HIDE_HUD=1`: starts with the HUD hidden (as after F1).
- `TOOIE_FRAME_OVERLAY=1`: shows the frame rate overlay in Full whatever the setting says (`=compact` for Compact). `TOOIE_FRAME_LOG=1` prints its figures every 2 s as `[frames]`, shown or not (src/game/frame_overlay.cpp). The game window is 1600x900, wider than a 1280x720 Xvfb screen, so its top left corner is off screen; start Xvfb at 1920x1080 to see it.

- `TOOIE_FAKE_VSYNC=<hz>`: RT64 holds each present to that rate, like a vsync'd monitor (Xvfb + lavapipe presents at once). At 15 Hz the game still ran 30-49 fps at 120 FPS, so presents don't cap the game.
- `TOOIE_GAME_FPS=30|40|60|120|175|240|uncapped`: Game Frame Rate as that mode whatever the setting says (`unlocked` also means Uncapped; 40 and up pace the frames themselves with an extra VI after each swap; headless can't reach 40, so the fixed modes fall back to stepping by the real time, as Uncapped does; `TOOIE_FORCE_SCENE_INTERP=0|1` overrides DEV > Force Interpolation in cutscenes; `TOOIE_FIXED_SLOW_MOTION=1` keeps their fixed step instead, so they run in slow motion as 60 does; `[game-fps]` shows the step used in ms). `TOOIE_GAME_FPS_LOG=1` prints `[game-fps]` every 2 s: game frames a second, the time steps the game asked for, the wait it asked for, game time against real time, and how far Banjo moved per second of game time (src/game/game_frame_rate.cpp). It also prints `[game-time]` at every map change and letterboxed scene start or end, with game time, real time, frame count and whether an attract demo is playing, to compare scene lengths between modes. Lavapipe at the default resolution caps the game near 15 fps; set `res_option` to `Original` and `msaa_option` to `None` in the run folder's graphics.json to reach 30.

- `TOOIE_PAD_GAME_TIME=1`: the pad script and `TOOIE_TELEPORT` count game time instead of real time, so a mode the container can't keep up with (120 FPS runs in slow motion) gets the same inputs at the same game moments. `TOOIE_UNCAPPED_FPS=<fps>[,<fps>...]` makes Uncapped step as if those frame rates were reached, in turn, whatever really went by (`1000` = a steady 1000 fps, `240,1000,60` = uneven frames). `TOOIE_PAD_EVERY=<n>` reads the controller on every n-th timed VI only, so a slow-motion run gets several game frames per controller read, as a fast PC does. `TOOIE_POS_LOG=1` (with `TOOIE_GAME_FPS_LOG=1`) prints `[pos]` every frame: game time, the frame's step and Banjo's position. Swimming check (Spiral Mountain pool): `TOOIE_WARP=AF:0@15000 TOOIE_TELEPORT=1178,-377,471@40000 PAD='44000:y=1:2000;46500:b:300;47000:y=1:5000;47200:a:150;47700:a:150'`; at 30, 120, 240 and uneven Unlocked steps Banjo's path matched (src/game/game_frame_rate.cpp, src/debug/pad_script.cpp).

- Heap check (src/debug/heap_check.cpp): every game frame the game's heap is walked and the first damage is logged as `[heap] damage found ...` with the blocks around it and the map; on by default (also on PCs, for crash reports). `TOOIE_HEAP_CHECK=1` also prints `[heap] ok` every 600 checks, `=0` turns it off. The heap starts at the address held at 0x8007E990 and its size is at 0x8007BF00.

- Heap guard (src/game/heap_guard.cpp): before func_8001C0A0 walks the heap's block list, a next link that is outside the heap or doesn't link back is repaired and logged as `[heap] block ... repaired to ...`. `TOOIE_HEAP_BREAK=<n>` breaks a link on the nth walk (clears its top bit, as in L's 2026-10-15 crash, or writes `TOOIE_HEAP_BREAK_VALUE=<hex>`), to test the repair.

- `TOOIE_FX_LOG=1`: prints `[fx]` twice a second from the scene effects pass (fog strength and start, Banjo's position, the camera's world position worked out from the view matrix, the projection terms), `[fx-proj]` (a frame's perspective projections and which is the world's) and `[fx-draw]` (on the world's frame buffer: frames with the effects drawn, recorded, or skipped and why) (lib-patches/rt64.patch). `[fx-proj]` lines (only for the 3D world's frame buffer) also give each projection's viewport depth scale and offset (`vz`). `TOOIE_TEST_NEAR=<n>` redraws every perspective projection with near plane n (same far plane), as the game does with the camera close to the ground or a wall: before T285 the fog and other effects read the world as far nearer than it is with n = 5 or less. `TOOIE_FX_RAW_VIEW=1` makes the effects use the game's own camera instead of the in-between camera that frame smoothing draws with, to compare the two.
- `TOOIE_GRASS_LOG=1`: prints `[grass]` twice a second: the 3D grass draws and their blade passes since the last line, the camera, and how many textured perspective draws were turned down and why (`noshells` no grass this frame buffer, `excl` marked "no effects", `noworld` outside the 3D world, `mtx` drawn with a model matrix). A large `excl` across the level means a model's no-effects mark leaked (T300, Spiral Mountain dirt pit: `TOOIE_FREE_CAMERA=1 PAD='34000:rx=1:6000'` after the Banjo's house teleport). `TOOIE_GRASS_LOG=2` also prints `[grass-tex]` once for each texture combination grass grows on (decal or not, edges or not, each tile's hash and list match). `TOOIE_GRASS_LOG=3` prints `[grass-decal]` once for each level decal texture combination (blended or not, grass list match, triangles, tile hashes); a blended decal with grass 0 marks the no-grass grid (T323). `TOOIE_GRASS_LOG=3` also lists blended non-decal level draws with their z mode; `TOOIE_GRASS_LOG=4` prints the frame's ground draws behind the grid every 5 s and writes grass-mask.pgm in the run folder (white marked, grey grass ground). Mayahem Temple stone floor: `TOOIE_WARP=B8:1@15000`, screenshot at 75 s (T381).

- `TOOIE_SET="<ms>:<option>=<value>[,...];<ms>:..."`: changes Graphics options at those times after the game started, the way the menu does (saved and applied at once), to test live switching. Enum options take the index of their choice (`game_frame_rate` 0 Original, 1 30 FPS, 2 60 FPS; `rr_option` 0 Original, 1 Display, 2 Manual), number options a number (`rr_manual_value=120`). Logs `[set]`. It saves graphics.json in the run folder, so put that back afterwards (src/debug/settings_script.cpp).

- `TOOIE_FREE_CAMERA=1`: turns the free camera on whatever the setting says;
  `TOOIE_FREECAM_LOG=1` logs the camera, Banjo and stick 4 times a second
  (`[freecam]`). Drive the right stick with `rx=`/`ry=` in the pad script.
- `TOOIE_HONEYCOMB_LOG=1`: logs how many health honeycombs are loaded (src/gameplay/honeycomb_glitter.cpp). `TOOIE_HONEYCOMB_AT_PLAYER=1` makes the sparkles appear around Banjo, `TOOIE_HONEYCOMB_MODEL=<hex>` sparkles one more model, `TOOIE_HONEYCOMB_GO=<ms>` moves Banjo next to the first health honeycomb that long after one is first seen (9000 with `TOOIE_WARP=AF:0@15000` puts him by the three in Spiral Mountain's cave), and `TOOIE_HONEYCOMB_RATE=<x>` sparkles x times as often.
- `TOOIE_CUTSCENE_LOG=1`: logs `[cutscene] scene` / `gameplay` when a letterboxed scene starts or ends (src/gameplay/cutscene_skip.cpp). The skip itself always logs start and end.
- `TOOIE_FOV_LOG=1`: logs `[fov]` each time a camera's field of view or its gameplay/other kind changes (src/gameplay/field_of_view.cpp).
- `TOOIE_DLDUMP=ms[,ms...]`: writes the 3D scene's display list of the first frame after each time to dl_<ms>.txt in the working directory (matrices, vertex loads, segments, called lists), followed by the frame's 2D (pause menu, HUD, text). `TOOIE_DLDUMP_ALL=1` also prints each matrix in full and every other command raw.
- `TOOIE_PHOTO=<on ms>:<off ms>`: enters and leaves photo mode at those times; `TOOIE_PHOTO_LOG=1` logs the photo camera and the delta time (src/gameplay/photo_mode.cpp). The pad script drives it (x/y move, rx/ry look, z/r down/up, a screenshot, start time speed, b leave).
- `TOOIE_PHOTO_ORBIT=<yaw>,<pitch>,<distance>[,<height>]`: when photo mode's camera is switched to orbit (`PAD='46000:dd:300;47000:dr:300'` with `TOOIE_PHOTO=45000:...`), it goes straight to that place round Banjo (camera degrees; height of the pivot above his feet, default 60), so close-ups frame the same whatever the frame rate. With `TOOIE_POSE_SWEEP=C` the pose is fixed too: `TOOIE_PHOTO_ORBIT=315,-3,170,92` is a side close-up of his head in Spiral Mountain (src/gameplay/photo_mode.cpp).
- `TOOIE_SNOUT_FORCE=<pitch>,<yaw>`: holds Snout jiggle's bend at those degrees (pitch up towards the eyes), for close-ups of the bent snout; `TOOIE_SNOUT_LOG=1` logs the swing (src/gameplay/snout_jiggle.cpp).
- `TOOIE_POSE_SWEEP=<hex>[-<hex>][,...]`: 12 s after photo mode comes on, puts Banjo in each of those animations in turn (photo mode's Pose row) with a screenshot of each, logging `[pose] sweep 0x..`; `TOOIE_POSE_FRAME=<0-20>` is the point in it (default 10, the middle). Orbit the camera first with the pad script (`46000:dd:300;47000:dr:300;48000:rx=1:1500;51000:z:800` with `TOOIE_PHOTO=45000:...` gives a three-quarter front view in Spiral Mountain). Animations 0x1-0x17E were swept on 2026-10-16 without a crash.
- `TOOIE_ALBUM_LOG=1`: logs `[album]` with how many photos the ESC menu's Album tab found (also opened from photo mode: its last row, Album, with A or D-pad right; `PAD='50000:du:300;54000:a:300'` with `TOOIE_PHOTO=45000:...`) and each picture it decoded (src/ui/photo_album.cpp). To open it headless: `TOOIE_MENU_PAD_FILE=pad.txt`, then `back` (opens the menu) and `r` eight times; `dr`/`dd` move between photos.
- `TOOIE_MUSIC=<entry>@ms[,...]`: picks Music player row entries (0 Level music, 1-48 jukebox, 49+ Track 0...) ms after the game loop starts. `TOOIE_MUSIC_LOG=1` logs the six music slots (track, volume, stopping, +0x34) every second (src/gameplay/music_player.cpp).
- `TOOIE_CUT_LOG=1`: logs `[cut]` each frame with how far the camera moved and turned, and whether frame interpolation treats it as a camera cut (src/game/model_tagging.cpp).
- `TOOIE_TAG_LOG=1`: logs `[ids]` each frame for every model with 20 or more tagged matrices: how many there are and how many ids carried over from the last frame (RT64 can only blend those).
- `TOOIE_INTERP_CHECK=1`: starts with the F7 interpolation check on (`[interp-check]` lines, red tint; src/debug/interp_check.cpp).
- `TOOIE_TAG_KEYS="25000:pick;27000:tag;29000:save;31000:unsave;33000:effects"`: presses the Pick Model, Tag Model, Save Tags, Unsave Tag and Model Effects keys at those ms after start (a tag switches the blend mode to custom) (manual interpolation tags, src/debug/interp_tags.cpp; `[interp-tags]` lines; with `TOOIE_TAG_LOG=1` also `[print]` lines naming every model once). The tags are read from and written to `interp_tags.txt` in the run folder.
- `TOOIE_RACE_WARP=<race 0-3>@<ms>`: asks for a Race Warps entry (0 GGM first race, 1 GGM second, 2 CCL first, 3 CCL second) that long after the game loop first runs; pair it with `TOOIE_WARP=AF:0@15000` and ask at 40000 or later. `TOOIE_RACE_LOG=1` logs `[race-warp]`: the flags stood in for, the race state every 2 s in the race and the restore when it is left (`=2` also logs every other flag read during the race). Pumping for a win: `PAD` with `<t>:a:120` every 240 ms. Code: `src/gameplay/race_warp.cpp`.
- `TOOIE_BOSS_RUSH=<ms>[:<first>]`: starts a boss rush (General > Boss rush) that long after the game loop first runs, from boss `<first>` (0-12 in rush order) if given; pair it with `TOOIE_WARP=AF:0@15000` and start at 40000. `TOOIE_BOSS_RUSH_MENU=<ms>` turns the General > Boss rush switch on at that time the way the menu does (its change callback). A file open: `PAD='8000:start:300;16000:a:300;20000:a:300;24000:a:300;28000:a:300' TOOIE_WARP=AF:0@40000` starts a new game on file 1 and lands in Spiral Mountain with it. `TOOIE_BOSS_RUSH_LOSS_IS_WIN=1` counts a loss as a win, to test the hand-over to the next boss without beating one: in Klungo's fight Banjo dies by himself after about 4 minutes, and `PAD` with `<t>:b:400` every 10 s from 285000 answers No to "play again?". `TOOIE_REPLAY=<hex>@<ms>` starts one replay number (bosses 0x20-0x2C, multiplayer 0x40-0x4D, minigames 0x60-0x76, cutscenes 0x80-0x85); `TOOIE_REPLAY_SCAN=1` with it logs the map every number from there asks for. Logs `[boss-rush]`. Code: `src/gameplay/boss_rush.cpp`.
- `TOOIE_REPLAY_PICK=<hex>@<ms>`: picks that replay in Cheats > Replays (saves the open file first, then starts it; logs `[replays]`; src/gameplay/replays.cpp). Beat Hag 1 shows when `[complete] file is 100%` is logged.
- `TOOIE_SET_FLAGS=<hex flag>[-<hex flag>][,...]`: sets those game flags once a map is loaded (src/gameplay/progress_cheats.cpp; flag names in the decomp's include/gameflags.h). `TOOIE_TOTALS_LOG=1` logs `[totals]` when the pause menu page changes, with each Totals level page's counts, and when Totals opens every collectible that can be got now (`[totals] now: MT: Golden Goliath Jiggy`) and how many areas are reachable (src/gameplay/totals_checklist.cpp). The rules are generated: `python3 -I tools/gen_totals_rules.py <AP_Banjo-Tooie>/worlds/banjo_tooie lib/bt-decomp/include/gameflags.h src/gameplay/totals_rules.inc` (clone https://github.com/jjjj12212/AP_Banjo-Tooie first). A Mayahem Temple Totals page with progress: `TOOIE_SET_FLAGS=392-39A,1E3-1EC,250-253,2DB-2DD,23F-240,222,44F-452 TOOIE_WARP=B8:0@15000 PAD='40000:start:150;43000:y=-1:150;46000:a:150;52000:x=1:300;55000:x=1:300;58000:x=1:300'` (QOL > Totals checklist is off by default: set `"totals_checklist_v2": true` in the run folder's qol.json first; 1E3-1EC are the "world visited" flags that make the pages show; Jinjo flags open the slow Jinjo page first, so leave them out). Then `62000:a:300` opens the Jiggies list, `66000:dd:300` steps down it and `84000:b:300` closes it; the log has `[totals] list ...` with every entry and `[totals] hint: ...` for each LATER one picked. Hold presses 300 ms: headless runs slowly and can miss a 150 ms press.
- `TOOIE_RUN_HOLD=<from ms>:<to ms>[,...]`: acts as the Run key held in those windows (after the first pad read). `TOOIE_RUN_LOG=1` logs `[run]` 10 times a second: form, state, animation, target and actual speed, the run animation's duration and its speed map, and the sprint blend (0 to 1; it eases over 0.35 s). `TOOIE_RUN_REBIND=<SDL scancode>` rebinds Run on the keyboard as the Controls tab does (src/gameplay/hold_to_run.cpp). `TOOIE_RUN_ANIM_TEST=1` plays the sprint on the spot while standing still. `TOOIE_RUN_ANIM_TUNE=<file>` replaces the sprint rules for tuning, lines `<anim hex> <bone> <type> <scale> <offset deg>`, and `@<ms>` starts a set used from that many ms after the first animation update. `TOOIE_RUN_ANIM_DUMP=<dir>` writes animation files as the game loads them (ROM data: keep out of the repo). Sprint animations are made at runtime from the run animation (format: s16 start, end, track count, pad; each track u16 bone<<4|type, s16 key count, keys of u16 0xC000|frame and s16 value; types 0-2 rotation in 1/64 degree, 3-5 scale, 6-8 translation). Banjo's lean bone is 3, his legs the chains 6-10 and 20-24, his arms 12-16 and 26-30; Kazooie's legs are 6-12 and 20-26, her body 106. Measured: run state 4 (Banjo-Kazooie and Banjo alone, animation 0xC) and 199 (Kazooie alone, 0xA6); the forward roll is state 49.
- `TOOIE_NO_MODEL_TAGS=1`: turns off the matrix ids for frame interpolation (src/game/model_tagging.cpp), for before/after comparisons. Interpolation only runs with Interpolation (formerly Framerate) set to Manual (headless, Display gives no in-between frames).

- `TOOIE_MENU_PAD="<ms>:<button>[:<hold ms>];..."`: controller presses for the menus (the pad script only reaches the game, never the menus), at those times after the game started. `TOOIE_MENU_PAD_FILE=<path>` presses each button written to that file (one per line) as soon as it appears, so a run can be driven step by step next to xdotool (`printf 'r\nr\n' > pad.txt`). Buttons: a b x y back start l r du dd dl dr. Default menu bindings: A accept, X back, Select close, L/R tabs. Logs `[menu-pad]` (src/debug/menu_pad.cpp).

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
- `TOOIE_TORCH=1`: turns on Cut Content: Torch enemy (src/gameplay/torch_enemy.cpp). `TOOIE_WARP=CC:0@15000` lands in the Flooded Caves, where the entrance-ledge torch chases and burns Banjo within about 5 s; press B (`PAD` with `b` every 600 ms from 30000) to put it out with a claw swipe. `TOOIE_TORCH_LOG=1` logs spawns, floor heights, state changes and Banjo's state; `TOOIE_TORCH_SHOTS=1` takes screenshots on each change; `TOOIE_TORCH_NEAR=<units>` adds a torch in front of Banjo in any map; `TOOIE_TORCH_AT=x,y,z[,yaw];...` replaces the spots; `TOOIE_TORCH_EGG_AT=<game ms>` puts a blue egg on the first torch; `TOOIE_TORCH_ANIMS=a,b,c,d` tries other animations. A `TOOIE_TELEPORT` to the far end of the caves (-3550,260,-7500) stalls lavapipe in the container with or without the torch, so the far spots were checked by their floor heights only.
- `TOOIE_SAVESTATE=<save ms>:<load ms>[:<load ms>...]`: saves, then loads at those times (src/gameplay/save_state.cpp). `TOOIE_SAVESTATE_LOG=1` lists the game threads and the queue each waits on at each save and load.
- `TOOIE_AIM_TEST=<dx>,<dy>,<from ms>,<to ms>`: adds that mouse motion (pixels) to each pad read in that window; `TOOIE_AIM_LOG=1` logs the first-person angles (src/input/motion_aim.cpp).
- `TOOIE_RAMDUMP=<ms>[,<ms>...]`: writes RDRAM as the game sees it (big-endian) to `ramdump_<ms>.bin` in the working folder at those times, for finding values by diffing (src/gameplay/save_state.cpp).
- `TOOIE_SCENE_FX_VIEW=<1-4>`: starts in that F6 effect view: 1 the scene effects pass alone (ambient occlusion and outlines as grey, rim light lighter, fog blue, sky magenta), 2 depth (near white, far dark, sky blue), 3 normals, 4 water (red mask, yellow where it reflects; `TOOIE_WARP=AF:1@15000` faces the Spiral Mountain pool); `TOOIE_FX_COMPARE=1` starts with the F8 compare on; `TOOIE_AO_RADIUS=<units>` overrides the occlusion radius (src/display/effect_views.cpp, lib-patches/rt64.patch rt64_scene_effects.cpp, src/display/picture_filters.cpp).
- `TOOIE_WATER_TRACE=1`: logs player 0's state when it changes and whether it counts as under water (src/display/picture_filters.cpp).
- `TOOIE_TELEPORT=<x>,<y>,<z>@<ms>`: puts Banjo at that place (held for 30 frames) that long after the program started; several `x,y,z@ms` entries split by `;` teleport in turn. `1178,-377,471@40000` with `TOOIE_WARP=AF:0@15000` drops him in a deep Spiral Mountain pool; dive with `PAD='46000:b:300;47000:y=1,b:4000'` (src/display/picture_filters.cpp).
- Ice reflections (Graphics > Ice reflections, `ice_reflections` in graphics.json): `TOOIE_ICE_LOG=1` prints `[ice-tex]` once for each 3D world texture combination (tile hashes, see-through, depth write, decal, level) to find ice textures; `TOOIE_ICE_TEXTURES=<hex>,...` adds hashes to the ice list in src/display/picture_filters.cpp. `TOOIE_SCENE_FX_VIEW=4` shows ice blue. Icy Side spawn: `TOOIE_WARP=AF:0@15000,128:0@30000`, camera raised with `PAD='84000:ry=-1:3000'`; Icicle Grotto is map 132.
- Deep snow: `TOOIE_DEEP_SNOW=1` forces it on, `TOOIE_SNOW_HEIGHT=<percent>` sets the height, `TOOIE_SNOW_LOG=1` prints a `[snow]` summary every 2 s and the snow draw counts, `TOOIE_SNOW_MAPS=<hex>,...` replaces the snowy map list (Icy Side 128, Chilly Willy 12C), `TOOIE_SNOW_LOG=1` also counts the actor draws seen and the actor stamps, `TOOIE_SNOW_DEBUG=1` paints the shells blue (ground) to magenta (top) and `=2` shows the trail (yellow, brighter where pressed, red where banked). Icy Side is map 0x128 (`TOOIE_TEXTURE_SWEEP_MAPS=128`): `TOOIE_TELEPORT=3800,600,-1200@<ms>` puts Banjo on a snow field (a polar bear wanders in; `PAD='75000:y=1:3000;80000:x=-1:2000;84000:y=1:3000'` walks him up to it and it follows); `TOOIE_WARP=12C:0@15000` is Chilly Willy's arena (the rim is snow; 12B is the lava dragon) (src/display/picture_filters.cpp, lib/rt64 Snow.hlsli).
- `TOOIE_PRESET_TEST=<n>`: picks Graphics > Effects preset n (1 Original, 2 Enhanced, 3 Retro) on the first frame, logs the settings, then changes Sharpening by hand (the preset should go to Custom); check graphics.json (src/display/picture_filters.cpp). Back up graphics.json first.
- `TOOIE_ASYNC_DL=1`: the game no longer waits for the renderer to read each display list it sends (the old behaviour; lib-patches/N64ModernRuntime.patch, submit_rsp_task). `TOOIE_EARLY_SP_DONE=1` also reports the RSP done before the list is read, as upstream does. `TOOIE_DL_DELAY_MS=<n>` makes the renderer wait n ms before reading each list. Together they bring back the race where the game rewrote vertices the renderer was still reading (Jinjo Village, `TOOIE_WARP=142:0@15000`: about 1 frame in 3 headless).
- `TOOIE_VP_SPLIT_LOG=1`: logs `[vp-split]` whenever RT64's split of the game's camera matrix into view and projection does not multiply back to the input (lib-patches/rt64.patch, rt64_math.cpp). `TOOIE_OLD_VP_SPLIT=1` uses the old split, which went wrong with the camera facing nearly along z: `TOOIE_WARP=136:0@15000 TOOIE_FREE_CAMERA=1 PAD='35000:rx=0.3:80000'` (a Cloud Cuckooland spin) logged 34 bad frames in 2 minutes with it, none without.
- `TOOIE_BURST=<from ms>:<to ms>`: acts as F12 held over that window. Holding F12 for half a second keeps every presented frame, shrunk 4x, in a ring of the last 150; letting go writes them to `screenshots/burst-<stamp>/000.png...` (src/game/screenshot.cpp). For glitches that last a frame or two.

- `TOOIE_BENCHMARK=<seconds>`: records a benchmark (the Benchmark key's files in `benchmarks/`) for that long from the first game frame; the log prints `[benchmark] saved ...`.

- `TOOIE_DAY_NIGHT=<0 Off, 1 Cycle, 2 Morning, 3 Sunset, 4 Night, 5 Dawn, 6 Noon, 7 Afternoon, 8 Golden Hour, 9 Dusk>`: Graphics > Day and Night whatever the setting says; `TOOIE_TIME_OF_DAY=<0 to 1>` starts the clock there (0 midnight, 0.5 noon), `TOOIE_DAY_LENGTH=<minutes>` (can be below the menu's 4, e.g. 0.5) and `TOOIE_SUN_FRONT=<x>,<y>` puts the sun at that view-space spot (camera looks down -z; `0.3,0.45` is in the Spiral Mountain sky at the warp start) to see the sun and lens flare, and `TOOIE_WEATHER=<0 Clear, 1 Changing, 2 Rain, 3 Storm>` sets Graphics > Weather, `TOOIE_LIGHTNING=<0 to 1>` holds a lightning flash on, and `TOOIE_MOON_PHASE=<0 new to 7>` sets the moon, and `TOOIE_NIGHT_LIGHTS=0` leaves the windows unlit, and `TOOIE_AURORA=1` shows the northern lights on any cycling map, and `TOOIE_MIST=<0 to 100>,<0 mornings, 1 and nights, 2 always>` sets Mist and Mist Time, and `TOOIE_WET=<0 to 1>` holds how wet the ground is, and `TOOIE_CLOUDS=<amount>,<height>,<thickness>,<speed>` (0 to 100 each) shapes the clouds, and `TOOIE_DAY_NIGHT_LOG=1` logs `[day-night]` every second of game time: map, time, tint, sun night sounds (crickets, owls, birds) and weather (rain, lightning; src/gameplay/day_night.cpp, src/gameplay/night_sounds.cpp). Night in Spiral Mountain: `TOOIE_DAY_NIGHT=4 TOOIE_WARP=AF:0@15000 TOOIE_SCREENSHOT_AT=55000`. The tint is packed in the scene effects' `shadows.z` push constant (lib-patches/rt64.patch).
- `TOOIE_PAUSE_LOG=1`: logs `[pause-settings]`: the pause menu's option table by variant, each option's text as it is drawn, `Achievements picked`, and `pointer ... set back` when the game moved the pause overlay (src/gameplay/pause_settings.cpp). `TOOIE_PAUSE_VARIANT=0-3` forces the menu variant (3 = with Objects and Items and Jinjos, six rows). Achievements page: `TOOIE_WARP=B8:0@15000 PAD='40000:start:300;44000:y=-1:300;47000:y=-1:300;54000:a:300;66000:b:300'` (hold presses 300 ms; the d-pad does not move the cursor headless).
- Achievement icons (src/game/achievements.cpp, src/gameplay/totals_checklist.cpp): `TOOIE_ACH_PORTRAITS=id=hex,...` (achievement ids as in achievements.json, e.g. `my_nemesis=7D`) overrides an icon's portrait id; `TOOIE_ACH_ICON_LOG=1` logs `[ach-icon]` with each portrait's sprite asset, size and frames. With `TOOIE_SCREENSHOT_GAME=1 TOOIE_PAD_GAME_TIME=1` the Achievements page opens with `PAD='40000:start:300;44000:y=-1:150;46000:y=-1:150;54000:a:300'` (two short presses; one long press can skip a row). Pop-up: `TOOIE_ACHIEVEMENT_TEST=86@70000` (real ms) with screenshots from 76 s to 86 s after `TOOIE_WARP=B8:0@15000`; delete the achievement from the run folder's achievements.json first.
- Texture seams: `TOOIE_TEXTURE_SEAMS=0` or `1` sets DEV > Blend texture seams, and `TOOIE_SEAM_LOG=1` prints `[seam] <n> pieces, <m> joined edges` every 120 frames: the flat 2D pieces found and how many of their edges blend into a neighbour (the title screen: about 90-118 pieces, 135-230 edges; Grunty Industries 120 / 289; Mayahem Temple 48 / 74). `TOOIE_SEAM_SHOW=1` paints every blended edge magenta.
- Parallax pick mode: `TOOIE_PICK=<x>,<y>` (fractions of the window) turns it on with the cursor held there, `TOOIE_PICK_CLICKS="<ms>:left|right|middle|reset|deeper;..."` clicks that long after the first 3D frame, and `TOOIE_PICK_HIGHLIGHT=0` drops the pulsing highlight for clean shots. It logs `[parallax-pick] under the cursor: <hash>, <n> layers` and each change; picks land in Dev Files/parallax_tags.txt in the run folder (src/debug/parallax_pick.cpp). `TOOIE_PICK_CLICKS` also takes `save` and `delete` (the Save and Delete Save buttons; a left click with the cursor on a button presses it too). `TOOIE_PICK_MODE=effects` makes it Shader Effects pick mode instead (left = next effect, reset): logs `[effect-pick]`, writes Dev Files/shader_effect_tags.txt. `TOOIE_PICK_MODE=interp` makes it Interpolation pick mode (left = next blend tag, middle = screen effects, reset; needs a frame rate above Original): logs `[interp-pick]`, writes Dev Files/interp_tags.txt.
- `TOOIE_PARALLAX_SKIP=<hex hash>,...` leaves those textures out of the parallax list, to tell which listed texture is which in a picture.
- Parallax: `TOOIE_PARALLAX=<0-100>` sets it whatever the setting says, `TOOIE_PARALLAX_ALL=1` puts it on every textured world draw (to hunt textures), and `TOOIE_PARALLAX_LOG=1` (or `=<ms>`, starting that long after the first 3D frame, to list one place's textures) prints `[parallax-tex] <hash> on|off tile <n>, <triangles> triangles` once per world texture drawn, so stone the list (parallax_textures[] in src/display/picture_filters.cpp) misses shows as `off`; hashes match the texture dump's PNG names (lib-patches/rt64.patch, rt64_framebuffer_renderer.cpp).
- Sun shadow distance (src/game/widescreen.cpp, lib-patches/rt64.patch): with sun shadows on, every level box the game culls (func_800E3D0C, the level's own pieces) is drawn anyway, and culled models and effects (func_800E3E8C spheres) within the distance; a second coarse far map (4096, half width 24000, right of the near one in the same texture) covers the whole level past the near map. `TOOIE_SUN_FAR_OFF=1` skips the far map. `TOOIE_SUN_CULL_LOG=1` also prints `[sun-cull] map 0xNN boxes span` (Spiral Mountain about x -11500..11900, Mayahem Temple x -13056..17344); far map cost was lost in lavapipe noise, so the sun shadow maps hold it. `TOOIE_SUN_CULL=0` turns that off; `TOOIE_SUN_CULL=<from>-<to>[,...]` only between those ms after the first cull test (logs `[sun-cull] off/on at`), to compare one camera in one run. `TOOIE_SUN_CULL_LOG=1` prints how many culled spheres and boxes were kept every 2 s. `TOOIE_FX_LOG=1`'s `[sunmap] drawn` line gives the distance and the map's size (2048 up to 3000, 4096 at 6000 and up), and `[sunmap] casters N faces F` how much it drew. Spiral Mountain warp spot, free camera panning: casters 3400-4700 faces at 3000 before, steady 5900-6900 at 20000. At 20000 lavapipe drops to about 1 frame a second, so leave 25 s after a `TOOIE_SET` before a screenshot.
