# Changelog

What landed on main, newest first. Only changes you can see or use are listed;
regenerated code, CI, notes and tooling are left out.

## Since 2026-10-13 23:00 UTC (L away)

Every item below is untested on a real PC unless L's test list says otherwise
(see notes/for-L-to-test.md, T52 onward; none is confirmed yet).

### Graphics

- HD Shadows and Extended Draw Distance stop adding to a frame when the game's fixed drawing memory is nearly full (both together filled up to 87% of it headless, and past the end it tears or explodes models). Untested on PC (T120).
- Game Frame Rate: 120 FPS and Unlocked (up to 240), both experimental; the sound stays at its normal pace. The Framerate option is now Interpolation (Original is now Off) and sits under Game Frame Rate. Untested on PC (T122).
- Frame rate overlay: shows input latency (controller read to screen), in Compact and Full.
- Frame rate overlay (Full): shader compiles in the last 5 s, and the game's CPU time per frame.
- Extended Draw Distance now takes effect as soon as it is switched (before, it did nothing until Apply), and notes, eggs and other placed objects draw as far as characters. Untested on PC (T30).
- Game Frame Rate (Original, 30 FPS, 60 FPS) holds the game's own update rate; attract demos keep their pacing (6231d8b, 6736f06). Untested on PC (T52).
- Save Game Select: the waving hand is blended above Original, pictures keep their quick shake (a9b1817, 5fd696e). Untested on PC (T54).
- Frame rate overlay: 1% low, hitches, map and Banjo's position, renderer, speed-up/cheats/mods (5bd3bbd); Off, Compact and Full with F3 (435fe16). Untested on PC (T75, T84).
- Interpolation: repeated model parts paired with last frame's nearest (7a025d1, fc5fb28); swapped bone keeps its id (ac39168, e075788). Untested on PC (T76).
- Effects: sharpening, contrast, saturation, vignette, film grain (c0801d2); ambient occlusion under the HUD (86f3937); fog with start distance and colour (3d5776b); toon outlines (4f8b8d4); effects preset Original/Enhanced/Retro (f61ac36); bloom under the HUD (a364434); depth of field in letterboxed cutscenes (aa21380); eye adaptation (a45ff11); rim light (38942a7); heat haze by lava (160c285); underwater tint and distortion (ac6613b, aabde0b); water reflections (eeadba0); bounce light (f319872). Untested on PC (T66–T69, T71–T74, T79, T81, T82, T88, T90).
- Photo mode: orbit and zoom (3ef2fb1), camera collision (24d1721), hide Banjo (758ef8e), filters (1740a93), crop and rule-of-thirds grid (d436740), depth of field and tilt (02a1f9a, ae1d780), panel (d3fdb80). Untested on PC (T60, T62, T65, T85).
- F6 effect views and F8 compare (c5a21ee). Untested on PC (T80).
- FXAA and FXAA Extreme (61bd0ba). Untested on PC (T92).
- Texture upscaling, live 2x/4x (36bb76a). Untested on PC (T91).
- HD Shadows for the player (aa2351d). Untested on PC (T87).
- Always High-Detail Models keeps Banjo's close-up necklace model (b2f41b9). Untested on PC (T77).
- Graphics API: Vulkan is the default and Auto is removed (3516154). Untested on PC (T89).
- Glittering honeycombs sparkle on the comb (e482297). Untested on PC.

### Controls

- Fine aim now really slows first-person turning (headless: 44% of the normal turn at the 40% setting; before, about 89%). Its key is bindable: Controls tab, Hotkeys, Fine Aim (R or right trigger by default). Untested on PC (T102).
- Gyro aim: the controller's turn now moves the view the right way (left/right and up/down were swapped) and by the right amount (it was a rate, not degrees). Untested on PC (T103).
- Split up anywhere: D-pad left plays Banjo, right plays Kazooie (065b633, 22ee63c). Untested on PC (T55).
- D-pad control scheme in General (1bbfe86). Untested on PC (T58).
- Mouse and gyro aiming in first person (8888075). Untested on PC (T64).
- Hold B to run, with a faster run animation (f4a8154, 64a95d0). Untested on PC (T86).
- Speed-up key test notes and 4.21 marked done (af32c7a). Untested on PC (T59).

### Audio

- Music player in the Sound tab (098bb74). Untested on PC (T57).
- Back-Port: Get Jiggy animation, off by default (0c63fd2). Untested on PC.
- Old Banjo sounds (4.64 marked done, da43b51). Untested on PC.

### Cheats

- Noclip (cb79700). Untested on PC (T53).
- Unlock everything (a6d5d1d). Untested on PC (T56).
- Cheato effects written up from fan wiki pages (7e1ab37), shown in the cheat menu (d9ada2c), and moved to their own Cheato tab (b64fd23). Effects are not checked in this port.
- Cut Content: Bottles' Revenge, the cut two-player mode (accf3f7). Untested on PC (T61).
- Save states (c433c88). Untested on PC (T63).
- Split up anywhere, as above.

### Achievements

- The Xbox Live Arcade twelve, with pop-ups and an Achievements tab (8694d99). Untested on PC (T83).
- Treasure Hunt, one of each collectible (df684cf). Untested on PC (T83).
- Shoot Em Up!, 20 targets in the shooting games (009573c). Untested on PC (T83).
- All Beaten Up and Calamari Bonanza counters (965eb06). Untested on PC (T83).

### Stability

- General > More game memory (on by default): a bigger game heap (2.8 MB to 12.8 MB), about 4x the per-frame display list, matrix and vertex buffers, and room for 240 animation files and 1023 animations instead of 130 and 135, so scenes crowded with characters no longer crash. Takes effect at the next start. Untested on PC (T122).

### Tools and build

- Two Windows builds: Any 64-bit PC (2008 and up) and Optimized for newer CPUs (2013 and up), with three update scripts (e49f23c, 3a25fe3). Untested on PC (T78).
- Turn ThinLTO on for optimised builds (5eac701). Untested on PC.
- Warp tab: Down goes down and Right goes right (b5550b0). Untested on PC.
- F7 skips first moves in the interpolation check (e075788). Untested on PC.
- Headless TOOIE_SET script changes Graphics options live (5fd696e). For testing only.

## 2026-10-14

- Extended Draw Distance also reaches objects that set their own short draw distance, such as Jolly Roger's Doubloons (T30).
- Graphics: MS Anti-Aliasing is now in the Anti-aliasing and scaling section, above SMAA.
- Achievements: Down on a controller or the arrow keys now moves through the list and scrolls it (T117).
- Settings search: every settings tab (General, QOL, Graphics, Sound, Cheats) has a Search box at the top that filters that tab's options by name and description as you type. It searches one tab at a time and needs a keyboard or mouse to type.
- Settings search: a Search tab finds options in every tab (name, description or tab name); you can change them right there. It needs a keyboard or mouse to type. The per-tab search boxes are gone.
- Cheats: each Cheato code now says what it does in detail (the "from wiki pages" line is gone).
- Graphics tab: section headings (Display, Picture and effects, Lighting water and fog, Colour grading, Game view, Anti-aliasing and scaling, Frame rate and overlay). Game Frame Rate and the Frame rate overlay rows moved to the end, under their own heading.
- Graphics > Texture upscaling: the description now says what each option uses (2x is one pass of an xBR-style edge filter, 4x is two passes).
- Menus: moving the selection down a list with a controller or the arrow keys now scrolls the list with it (the Warp list used to keep the selection out of view).
- Settings: the Cheato codes are back in Cheats (under a Cheato codes heading); the separate Cheato tab is gone. Cheato switches you had on are read from the Cheats settings again.
- Graphics > Resolution: 720p, 1080p and 4K are now named 3x, 4.5x and 9x with the pixel height in brackets, and 6x (1440p) is new. Every Graphics option (including Field of View and Game Frame Rate) applies the moment you change it; the Apply button is not needed.
- Fixed a crash in play when the game hands the renderer graphics code it doesn't recognize (your 10:33 crash). The renderer keeps going and writes the details to logs/console.log.
- Fixed a crash at startup ("string too long") when the game was started from another folder, for example by the Graphics API restart. It now finds its files next to the exe.
- Graphics API now shows in Graphics. Picking the other one asks "Restart now?" and the game reopens itself with it; Later keeps it for the next start.
- Cheats and General tabs: section headings (Infinite items, Moves, Unlocks, Tabs; Saves, Back-Ports and cut content, Developer). In General the Control scheme, save and timer-save rows moved next to related rows; headings in Cheats hide while Enable cheats is off.
- QOL tab: split into Speed and skipping, Camera, and Moves and aiming, with a heading for each. The two cutscene-skip options moved up next to the speed options.
- Graphics: FSR 1 Upscaling (On or Sharp), AMD's upscaler for when Resolution is below the window's, as on Xbox Live Arcade.
- Graphics: FXAA Anti-Aliasing (FXAA or Extreme), the Xbox Live Arcade version's quick edge smoothing; it works with MSAA and SMAA.
- Graphics API: Auto is gone and Vulkan is the default (D3D12 is still a choice on Windows). If you have Auto saved, switch the row once.
- Settings: the eleven Cheato codes moved from Cheats to their own Cheato tab, shown while Enable cheats is on (Cheats is much shorter). Your old Cheato switches start off.
- Hold to run: a new Run control (Controls tab, Movement), not bound by default. Hold it while moving and Banjo-Kazooie, Banjo alone or Kazooie alone runs half again as fast, with a new sprint animation: Banjo leans forward with a longer stride and arms held in, Kazooie leans in with a longer, bouncier stride. Starting and stopping the sprint eases over about a third of a second. Holding Run with the stick only partly pushed now runs too (before, Banjo walked and Run did nothing). Run no longer has anything to do with B or the roll. QOL > Running turns it off.
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
