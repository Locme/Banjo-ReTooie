# Changelog

What landed on main, newest first. Only changes you can see or use are listed;
regenerated code, CI, notes and tooling are left out.

## 2026-10-13

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
- Cheats: Levitate (D-pad down) and Infinite jumps (A in mid-air).
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
