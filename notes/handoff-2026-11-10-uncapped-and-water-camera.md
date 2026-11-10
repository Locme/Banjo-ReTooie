# Handoff 2026-11-10: Uncapped fixes and the water camera

## State

- All work is uncommitted on `main` in the working tree.
- Other people's uncommitted changes are also in the tree, for example `notes/changelog.md`, `CMakeLists.txt` and `include/tooie_hooks.h` had earlier edits. Commit only the hunks listed here.
- Last build: `build.bat modern`, succeeded.
- Tested on Windows, Vulkan, by driving the game from the developer console. Not tested on other machines.

## Done and verified in game

1. Underwater camera sway too fast above 30 FPS.
   - Cause: `func_80114EEC` adds 2 degrees to the sway phase once per game frame, with no frame time.
   - Fix: a hook before 0x80114F88 scales `$f18` by the frame's share of 1/30 s (`tooie_underwater_wobble_step`, `src/game/game_frame_rate.cpp`; hand edit in `RecompiledFuncs/funcs_202.c`).
   - Verified: the picture is still while paused, and the change per second matches 30 FPS.
2. Talon Torpedo too fast above 30 FPS.
   - Cause: `bamovethrust_entrypoint_5` sets velocity = k*velocity + push once per frame. k is thrust +0x84: 0.85 cruising, 1.0 during wind-up. The launch kick (push 225) lasts one frame.
   - Fix: a hook before 0x80800110 (`tooie_thrust_step`; hand edit in `RecompiledFuncs/funcs_162.c`). It uses k^(dt*30), scales push to keep top speed, scales push by the share when k == 1, and holds each new thrust speed (+0x8C) for 1/30 s.
   - Verified: wind-up 0 to 30 in 1 s; kick peak 417; cruise 150. These match 30 FPS, about 1/30 s earlier.
   - Env vars: `TOOIE_NO_THRUST_FIX=1`, `TOOIE_THRUST_LOG=1`.
   - Steering not measured.
   - Also covers the Sub-Aqua transformation, which is untested.
3. Particles wrong above 30 FPS (all emitters, including torpedo bubbles).
   - Cause: `func_800B4790` keeps particle place, speed and spin as whole numbers and cuts the fraction each frame. The drag factor (+0xD0) is applied per frame.
   - Fix: 8 hooks in `func_800B4790` (`tooie_particle_whole`, `tooie_particle_drag`; hand edit in `RecompiledFuncs/funcs_167.c`). Each part moves by the 30 FPS frame's move times the frame's share, keeping the fraction. The drag factor is raised to the share.
   - Verified by screenshots: torpedo bubbles match 30 FPS.
   - Other particle effects not checked one by one.
4. Free camera stutter on long falls (also at 30 FPS).
   - Cause: Smooth Stairs eased the pivot height and snapped it when more than 300 behind, about every 0.1 s in a fall.
   - Fix in `src/gameplay/free_camera.cpp`: snap only on a teleport (target jumps more than 300 in one step); otherwise clamp the lag to 300.
   - Verified: no snaps at 30 FPS or Uncapped, including while turning the camera during the fall.
5. Hooks for items 1 to 3 are listed in `banjotooie.us.toml`. Changelog lines are added under 2026-11-10 in `notes/changelog.md`.

## Water camera (new)

Files: `src/gameplay/water_camera.cpp`, `include/tooie_water_camera.h`.

- QOL tab: a "Water Camera" switch with seven toggles under it, all on by default:
  - Off the Waterline
  - Smooth Splash
  - Surface Bob
  - Underwater Drag
  - Follow the Torpedo
  - Torpedo Pull-Back
  - Look Up Under Water
- Registered in `src/game/config.cpp`, grouped in `src/game/menu_tree.cpp`. The file is added to `CMakeLists.txt`.
- Called from the end of `tooie_free_camera` (hook in `func_8010FC38`) for every camera stepped in play (only when that hook's `gameplay && !paused` holds, so first person, cutscenes and Photo Mode are left alone). There is one state per camera; the torpedo steps two cameras.
- Look Up Under Water is a change in `free_camera.cpp` itself: the lowest elevation becomes -60 degrees while Banjo is under water.
- The water state (water player states, surface from where Banjo floats) is copied from `src/display/picture_filters.cpp`, not shared with it.
- Verified in game:
  - Surface Bob: the camera rises and falls 5 units over 2.6 s while floating.
  - Off the Waterline: a camera parked inside 30 of the surface moves to surface + 30.
  - Smooth Splash: biggest camera step 5.4, against 33.5 with the toggle off.
  - Underwater Drag: mean jerk 0.11, against 0.31 with the toggle off.
  - Follow the Torpedo (second session, Sea Bottom, Unlocked): the first build read Kazooie from player slot 0,
    which is Banjo, so the camera sat still 260 behind the warp point. Fixed: she is read from slot 1
    (0x80135494). The camera now blends in fully (blend 1.00) and turns with her: steering right, yaw went
    278, 250, 207, 150, 106, 44 over about 1.5 s; steering left, 278, 299, 339, 22, 49.
  - Torpedo Pull-Back: pull reached 0.37 at the kick and eased back to 0.03 at cruise.
  - Look Up Under Water: the free camera goes down to -60.0 degrees under water and holds there while pushed,
    looking up 80. With the toggle off it stops at about -30 (Look Up's own limit). The top is still +70.
- Launch fixes (same session, after L chose to fix them before committing):
  - Sharp first turn: the way across now comes from the way she faces (PlayerState +0xF8, what the stick steers);
    only the climb or dive comes from her velocity, at most about 50 degrees. Camera yaw now holds at 275 through the
    wind-up and kick, where it swung 275, 51, 89, 299 before.
  - Through Banjo: the eye is kept 110 from his middle (50 above his feet). Screenshots at 0.35, 0.6 and 1.0 s
    after the press show him at the bottom of the picture, below the camera, not around it.
  - Walls: the eye is swept from Kazooie with the free camera's `sweep_line` (func_800FAB50) and put 15 short of a
    hit. `apply()` now takes the hook's `ctx` for this. Checked with `TOOIE_WATERCAM_FOLLOW_DISTANCE=2000`: the
    eye stopped at x 3675 instead of about 3480, in front of the cave wall, with the cave in view. With the normal
    260 the test never fired in these runs.
  - Hard turns: with the eye's ease and the view's ease both at 8 per second, she slid to the edge of the picture.
    Now the way eases at 6 and the view at 16. Steering right for 1.5 s (her facing swung about 200 degrees), she
    stayed within 6.3 degrees of the middle of the view.
- Known problems, for L to judge:
  - The camera still trails her heading in a hard turn (up to about 100 degrees behind), so for a moment the view
    is from her side. She stays in the middle of the picture.
  - Which camera the game draws during a torpedo changes from run to run. In one of four runs the drawn camera
    (8032A6C0) never went through the free camera hook, so Follow did nothing that time. Kazooie had hit a stump
    straight away in that run.
  - Once, after a torpedo, a free-camera push down threw the camera above Banjo (elevation +56). Not reproduced in
    two later tries.
- Debug log: `TOOIE_WATERCAM_LOG=1` prints, four times a second, the drawn camera height, the current camera pointer, and each camera's place, state, surface, pull, Kazooie's position and facing, whether the wall test moved the eye (and how many steps it has), and the follow blend. `TOOIE_WATERCAM_FOLLOW_DISTANCE=<units>` sets the follow distance, for testing the wall test. It goes to `logs/console.log`, not stdout. Remove or keep before commit.

## Findings about the torpedo camera

- While torpedoing, player 0 (0x80135490) stays Banjo, standing still; its state reads 237 (343 is the wind-up).
  Kazooie is in the next slot (0x80135494), in a PlayerState made anew for each torpedo (803AB830, then
  803F1890). Her position is at that PlayerState +0xE4, her yaw through +0xF8, her physics through +0xC8.
  (Corrected 2026-11-10 by peeking the table; the first session had the slots the other way round.)
- The game steps two cameras: Banjo's, which stays still, and a chase camera. The drawn one is the one 0x8012D500 points at, the chase camera (checked against RT64's drawn camera height).
- The chase camera does move after Kazooie, but slowly and from far back, and its yaw stays fixed (274.9 in every log) even while she is steered. So she soon turns or swims out of the view. This is the game's own behaviour at both 30 FPS and Uncapped, not a frame-rate bug. L says it makes the move unusable.
- Follow the Torpedo is the fix. It puts the drawn camera behind Kazooie, along the way she faces, tipped by her climb: distance 260, height 60, looking 120 ahead, kept clear of Banjo and in front of walls. It eases in and out.
- Camera angle convention: camera yaw = heading + 180. A camera behind Banjo facing 95 has yaw 275. Looking down is a pitch just under 360.

## Next steps

1. L to try Follow the Torpedo by hand: the launch fixes above were checked only from the console and
   screenshots. The Sea Bottom start point is a narrow cave; open water would test it better.
2. Test the Sub-Aqua transformation with Follow the Torpedo (not checked; it only acts on state 237).
3. One-off: a 30 FPS trace once showed the camera height as about 398 million for one update at a splash. Not reproduced in four runs.
4. Commit only the hunks listed here, with before and after numbers. Keep `README.md` honest that the code is AI-written.

## Testing tips

- Run `Release\Optimized for newer CPUs (2013 and up)\BanjoReTooie.exe` fed by `tail -n +1 -f cmds.txt | ./BanjoReTooie.exe`. Output goes to `logs/console.log`. The pipe must outlive the shell that started it, so run it in the background.
- `warp id <map>` to the map you are already in does nothing; Banjo keeps his place.
- A second torpedo right after the first often does not fire. Wait about 4 s.
- `pause` sets frame time to about 0. Anything that still changes while paused steps per frame; this is how the camera sway was found.
- `diff snapshot`, `diff compare`, `writewatch` and `trace` find the writer.
- Inside the Mountain (map 0x116): the ledge is at (-292, -2800, 453). The pool is next to it, with its surface at about y -3150. `walkto -526 907` from the ledge walks into it.
- Settings were put back after tests: frame rate Unlocked, free camera on, all water camera toggles on.
