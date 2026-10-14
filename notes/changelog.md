# Changelog

What landed on main, newest first. Only changes you can see or use are listed;
regenerated code, CI, notes and tooling are left out.

## 2026-10-14

- Settings: the eleven Cheato codes moved from Cheats to their own Cheato tab, shown while Enable cheats is on (Cheats is much shorter). Your old Cheato switches start off.
- Hold to run: hold B while moving and Banjo-Kazooie, Banjo alone or Kazooie alone runs half again as fast, with the run animation stepping faster to match. A quick tap of B still rolls. Rebind it as Run under Movement in the Controls tab.
- Frame rate overlay: Off, Compact or Full, with F3 to step through them; Full adds audio queue and dropouts, the build, and a frame time graph.
- Above Original, a part of Banjo that changes its look (his face when he blinks) no longer jumps for a frame.
- Achievements: the Xbox Live Arcade version's twelve achievements (200 G), with a pop-up when one unlocks and an Achievements tab listing them. Eight are tracked so far; nothing is awarded while cheats are on.
- Warp tab: Down on a controller or keyboard now goes down a line, and Right goes right (before, both went to the next place).
- Windows builds: build.bat makes two games in Release: "Any 64-bit PC (2008 and up)" and "Optimized for newer CPUs (2013 and up)". update_and_build_any_pc_2008.bat and update_and_build_newer_cpu_2013.bat build one each, update_and_build.bat both; saves and settings from the old Release folder are copied into each new folder.
- Above Original, models made of one repeated part (chains, rows of plants, swarms) no longer stretch for a moment when the game drops one of the parts.
- Frame rate overlay: adds the 1% low and hitches, the map and Banjo's position, the renderer and resolution, and whether speed-up, cheats or mods are on.

## 2026-10-13

- Save Game Select: above Original, the waving hand is smooth again while the pictures keep their quick shake.
- Banjo no longer slides when Jamjars (or anyone) starts talking to him: talking now stops him on the spot, as on N64. A function that stops Banjo was recompiled empty.
- Graphics: Game Frame Rate (Original, 30 FPS, 60 FPS) holds the game's own update rate steady.
- Frame rate overlay: the game's frame rate is averaged over 2 seconds, so a steady 30 no longer reads as 28 and 32.
- General: Back-Port: Get Jiggy animation, Banjo does Banjo-Kazooie's jiggy dance when he collects a Jiggy (off by default).
- Graphics: SMAA Anti-Aliasing (Low, Medium, High or Ultra) smooths jagged edges, with or without MSAA.
- Transformation drop-down: moving through the list with a controller or the arrow keys no longer applies every entry on the way; the pick applies when you confirm.
- F7 turns on an interpolation check: models whose blend between frames looks wrong turn red for a moment and are logged.
- Fire, dust, feathers and other particles are blended above Original, each paired with itself from the frame before (they were drawn at 30 fps, then could swap places between frames).
- Above Original frame rate, a cutscene's black bars coming in no longer blend the picture's shape (likely cause of the brief squash in ultrawide, not yet tested).
- Fine aim: the first-person view turns slower, always or while R is held (QOL).
- General: Back-Port: Old Banjo sounds swaps in Banjo-Kazooie's jump sounds (off by default).
- Canary Mary races: Fair (default), Easy or Original in QOL (works once the game code is regenerated with its hooks).
- Graphics: Frame rate overlay shows frame rate, frame time, the worst frame, GPU time and frame interpolation figures in the top left corner.
- Graphics: Brightness with a test pattern, Colourblind filters, and Retro N64 16-bit colour, CRT and a 3-point filtering switch.
- Controller support now comes from SDL 3 (through sdl2-compat): back buttons work on more pads, including 8BitDo Pro 2, Pro 3, Ultimate 2 Wireless and Ultimate 3.
- Talon Trot can be a toggle (QOL, on by default): let go of Z and Banjo keeps trotting until you press Z or C-left.
- Controller back buttons that SDL doesn't name can now be bound in Controls (they show as L4, R4, L5, R5).
- Fixed the Jiggy level wipe ending early in wide pictures: it now opens the whole screen.
- Fixed Banjo's limbs coming apart when the frame rate is above Original.
- Texture packs can be dropped into the mods folder as a .zip.
- The Warp tab switch is in Cheats, and needs Enable cheats on.
- Skip intro logos is renamed Press Start Early to Skip Intro.
- Cheato codes are live toggles in Cheats. Unlock all moves is added (first part, not yet tested).
- Fixed missing terrain at the edges of wide windows.
- Text speed and level transitions moved to the QOL tab.
- Level transition speed: Original, Fast 4x or Instant 16x.
- Skip intro logos moved to a new QOL tab.
- F1 hides the HUD and text boxes.
- Cheats: Infinite Jumps (Levitate) (A in mid-air; the separate D-pad down Levitate was removed).
- Dialogue text speed: 1x, 2x, 4x or instant.
- Level warp list is in a Warp tab, shown by Cheats > Warp tab (with Enable cheats on). F9 repeats the last warp.
- Level warp tab with 42 places.
- F12 takes screenshots, with a "Screenshot saved" notice.
- The HUD is at the screen edges in wide pictures.
- Speed-up key: hold F2 for 2x, 3x or 4x.
- The crash log names the last C++ error and lists the crashing code.
- Windows: the game's console output is kept in logs/console.log.
- build.bat puts the finished game in a Release folder.
- Discord status shows the level you are playing in.
- Start skips the boot logos to the file select.
- Cheats tab, with an Enable cheats switch: infinite eggs, feathers, Glowbos and ice keys.
- Notice toasts appear at the top right and fade after 3 seconds.
- Graphics settings apply live, and Aspect Ratio has a Letterbox 16:9 choice.
- A hang watchdog writes logs/hangs.log when no frame is shown for 5 seconds.
- Save backups, and a crash handler that writes crash dumps.
- Fill also widens what the game draws, not just the picture.
- Settings and saves are kept next to the exe by default.
- Fixed a freeze in the intro after the Klungo scene.
- The game boots to the title screen.
