# Banjo-Tooie N64 recomp: roadmap checklist

Every item has two boxes:

- **Done**: Claude ticks this only when the work has landed on `main`. Partial work stays unticked, with a note.
- **Approved by L**: only L ticks this, and only when happy. Claude ticks it only when L says to.

Numbers are the feature numbers in the handoff report, Section 4.

## Short

### 4.2 One-click build and update scripts
- [ ] Done
- [ ] Approved by L

### 4.5 Quick start (Start skips the intro)
- [x] Done
- [ ] Approved by L
- Note (2026-10-13): Start during the logos or title flight (map 0x18B) goes to the file select with the title's own wipe; on the finished title the game's own Start runs. General tab "Skip intro logos", on by default. Start in attract demos is left to the game.

### 4.7 Native in-game settings page ("GRAPHICAL SETTINGS", was "PC SETTINGS")
- [x] Done
- [ ] Approved by L
- Note (2026-10-13): L chose the RmlUi settings screen opened with Esc or the controller's Back/Select button; no row in the N64 pause menu.

### 4.10 Settings apply without restart
- [ ] Done
- [ ] Approved by L
- Partial (2026-10-13): every Graphics tab option applies and saves the moment it changes; no Apply button needed (lib-patches/RecompFrontend.patch). Graphics API still needs a restart (RT64).

### 4.11 Saves folder next to the executable
- [x] Done
- [ ] Approved by L

### 4.12 Save backups
- [x] Done
- [ ] Approved by L

### 4.15 Frame rate modes: 30 / 40 / 60 / 120 / 175 / uncapped
- [ ] Done
- [ ] Approved by L
- Partial (2026-10-13): handled the N64Recomp way (report §4.15 g). Game logic stays at its own rate and RT64 draws in-between frames. Settings > Graphics > Framerate: Original (the game's own 30 or lower), Display (the monitor's rate, the closest to "uncapped") and Manual 20 to 240 (covers 40, 60, 120 and 175). It applies live. Not checked yet: how smooth it looks and whether camera cuts smear, because the headless renderer only reaches about 7 fps (T12). No per-object tagging yet; add it only where T12 finds smearing.
- Fix (2026-10-13): above Original, Banjo's and Kazooie's limbs could be drawn away from the body in the in-between frames (headless at Manual 60, Kazooie's head and legs floated beside Banjo), because RT64 had to guess which bone matrix of the last frame each new one continued. src/game/model_tagging.cpp now gives every model's bone matrices stable ids (model, copy, bone) after each frame's 3D scene; checked headless at Manual 60 (no stray parts, four levels look normal). T20. On the game select screen (map 0x158) the shaking portraits and hand are drawn at the game's own rate instead, because blending turned their random shake into a slow wobble.
- Pass 2 (2026-10-13, after L: "still very buggy, especially the animations", "Banjo slides in cutscene when over 30 fps"): Banjo loads 48 to 68 bone matrices depending on what he does, so naming bones by count paired the wrong bones between frames; bones are now named by the geometry list they draw next. Models are keyed by their first list and their textures (some share a first list). Camera cuts are detected from the view matrix (a jump of over 150 units per 30 fps frame, or a turn of over about 35 degrees); on a cut nothing is blended for that frame, so cutscene shots no longer slide into each other. Bones blend with RT64's decomposed mode (turns stay rigid instead of shrinking).
- Pass 3 (2026-10-13, after L: enemies and items look low-res above 30 fps): checked headless that enemy and item models get stable ids and RT64 matches them (62-63 of 63 tagged matrices per frame). Banjo's vertices are rewritten by the game every frame (his joints bend on the CPU), so those stepped at 30 fps while his bones blended; tagged models now also blend vertex positions. Enemy and item vertices were static in the checked scene.
- Shadows (2026-10-13, after L: "the shadow goes wild" in the flutter jump): Banjo's shadow is a flattened shadow model the game places by multiplying its matrix into the projection, with its bones loaded inside the geometry lists. RT64 blends only the first projection of a frame, so the shadow's bones were left to guesswork. model_tagging.cpp now multiplies the shadow matrix into copies of the bones, leaves the projection alone and gives the bones one id matched in load order. Checked headless at Manual 60 during repeated flutter jumps in Mayahem Temple: the shadow keeps its shape (untagged it stretched and tore).
- Pause menu panels (2026-10-13, after L: "Pressing start, the transparent black bars flicker a bit back before finally finishing the animation"): the pause menu's translucent panels are placed through the projection the same way, and each stretches between a bone and the matrix before it. The 2D after the scene (hide_hud.cpp's last mark) now gets the same rewrite, and every model placed this way is matched to last frame's nearest copy, so a panel appearing does not shift the others. Checked headless at Manual 60 that the paused menu draws the same as without tagging; the flicker itself lasts too short to catch in headless screenshots.
- Cut detection, pass 2 (2026-10-13, after L: "Banjo still slides uncontrollably in cutscenes"): logged the camera for every frame of the new game intro (TOOIE_CUT_LOG=1). One shot change in the poker scene (camera 225 units and 33 degrees) was under both limits, so that shot blended into the previous one. A sudden move or turn now also counts as a cut: over 40 units or 10 degrees per frame and over 3 times the camera's motion the frame before, so steady pans and dollies still blend. Intro: 13 cuts found (was 12), none on a steady dolly; normal play in Mayahem Temple and Spiral Mountain with jumps and running: no cuts but the two warps.
- Fix (2026-10-13, after L: "A lot of frameskipping in the interpolation of banjo walking"): the 2D pass added for the pause panels also cleared the list of last frame's model copies, so on about half the frames (whenever the 2D after the scene was drawn) every model got new ids and RT64 blended nothing. Logged with TOOIE_TAG_LOG=1 while walking in Mayahem Temple: before, Banjo's 48 bone ids carried over on 88 of 202 frames; after, on 201 of 202 (the first frame has nothing to carry over).
- Interpolation check (2026-10-13, L picked "Tint jumps" and "LOG"): F7 tints a model red for 10 game frames and logs it when it jumps (over 60 units and over 3 times its move the frame before) or when some of its matrices cannot be paired with last frame's. Textures are swapped for red ones and vertices drawn from a red copy, since most characters are coloured by their vertices. Running it at Manual 170 found particles (dust, feathers, flutter sparkles) never blended: each is drawn from a list the game builds anew every frame, so every id was new. Models without a texture segment now keep RT64's automatic matching. Left after that, headless at Manual 170 in Mayahem Temple and Jinjo Village: pickups jumping (legit) and Banjo with 1 of 48 or 68 bones unpaired on a few frames.
- Particles, pass 2 (2026-10-13, after L: "fire is not rendering correctly"): with RT64's automatic matching, look-alike flames and sparks could be paired with each other and jump about in the in-between frames. Each particle matrix is now paired with the nearest particle of last frame (within 40 units, closest pairs first) and keeps that particle's id; one with none near is drawn as it is. Its quad is not blended, only its place. Headless in Hailfire Peaks' volcano at Manual 60 (TOOIE_TAG_LOG=1 logs `[particles]`): most frames pair every particle (a lone particle 659 of 765 frames, bursts of 20-24 mostly all).
- Game select (2026-10-13, after L: "The Save Game Select is not properly interpolated (feels laggy, especially the hand)"): that screen was drawn wholly at the game's rate to keep the portraits' shake crisp, so the hand's wave was not blended either. Its models put their place (and shake) in the projection and load their bones inside their own lists; the place now stays at the game's rate and the bones get one id per model, set with segment 5 and matched in load order, so the wave is blended. Headless at Manual 170: 11 models with steady ids over 500 frames, drawn correctly. T54.

### 4.22 Fit to window: fill / letterbox / 4:3, HUD 16:9
- [x] Done
- [ ] Approved by L
- Partial (2026-10-13): Fill works through Settings > Graphics > Aspect Ratio = Expand (RT64 widens the picture; the game's culling now widens with it, src/game/widescreen.cpp). 4:3 is Aspect Ratio = Original. The HUD stays in the middle 4:3. Letterbox 16:9 added (2026-10-13): Aspect Ratio now reads 4:3 / Fill / Letterbox 16:9. HUD at the edges added (2026-10-13, src/game/hud_edges.cpp): Settings > Graphics > HUD Placement. Original keeps the HUD in the 4:3 middle, 16:9 spreads it up to 16:9, Expand to the window edges. Verified headless in a 16:9 window (paused in Spiral Mountain).

### 4.30 Cutscene audio sync and N64 intro pacing
- [ ] Done
- [ ] Approved by L

### 4.52 Text speed
- [x] Done
- Note: QOL tab "Text speed" (1x/2x/4x/Instant) and `--dialogue_text_speed 1|2|4|instant`. Hooks the zoombox print timer; verified headless in the new-game intro (Klungo's lines print whole on Instant).
- [ ] Approved by L

### 4.55 Twin-stick (free) camera
- [x] Done
- [ ] Approved by L
- 2026-10-13: QOL > Free camera (on by default, L's pick), with Free camera speed (Slow/Normal/Fast) and invert left/right and up/down. The right stick turns the camera smoothly around Banjo and tilts it; pushing on past the lowest tilt slides the camera in to a quarter of the distance, past the highest it pulls out to 1.6x. Once used, the yaw is held in world space until a cutscene, a fixed camera or another area; first person is left to the game and the held yaw comes back after it. Walking follows the turned camera. Walls and floors pull the camera in with the game's own camera line test. While it is on, the right stick no longer acts as C buttons in normal play (clicking the right stick still gives C-up, so first person; L's pick, 2026-10-13). 2026-10-13 fix: the camera keeps its own height and aim, so it no longer tips towards the floor on its own. Code: src/gameplay/free_camera.cpp, hook in func_8010FC38. Verified headless in Spiral Mountain (turning, tilting, close-in, pull-out, first person, walking in the camera's direction). Not checked: flying, transformations, multiplayer split screen, feel on a real pad (T23).

### 4.66 Held sounds / "full-length sounds" (removed) and the Beak Barge investigation
- [ ] Done
- [ ] Approved by L

### 4.67 "Enable cheats" gate
- [x] Done
- [ ] Approved by L

### 4.69 Infinite eggs, feathers, Glowbos and ice keys
- [x] Done
- [ ] Approved by L

### 4.70 Cheato cheats as live toggles
- [x] Done
- [ ] Approved by L

### 4.71 Unlock all moves
- [x] Done
- [ ] Approved by L

### 4.72 Unlock everything
- [x] Done (T56)
- [ ] Approved by L

### 4.73 Levitate
- [x] Done
- [ ] Approved by L

### 4.79 Infinite jumps
- [x] Done
- [ ] Approved by L

### 4.80 Level warp (F5 list and F9)
- [x] Done
- [ ] Approved by L
- 2026-10-13: a "Warp" tab in the menu (Esc), shown while Settings > Cheats > Enable cheats and Warp tab are on (renamed from "Debug" and moved to Cheats later the same day), lists 42 places by area (Spiral Mountain, 10 Isle o' Hags spots, every level with 3 sub-areas, Cauldron Keep). Picking one closes the menu and warps with the game's own map change. F9 repeats the last warp (only while the Warp tab is on). Warping to the current map does nothing, and a warp waits while another map change is under way. All 42 were warped to in one headless run and each landed with Banjo standing in the area. Code: src/game/level_warp.cpp, level_warp_places.inc, src/debug/warp.cpp.

### 4.83 Screenshots (F12) with a notice
- [x] Done
- [ ] Approved by L
- 2026-10-13: F12 saves the game picture (no menus or notices in it) as screenshots/<date>_<time>.png in the app-data folder and shows "Screenshot saved". The picture has its on-screen shape (wide in Fill). Code: src/game/screenshot.cpp, RT64 read-back in lib-patches/rt64.patch and plume.patch. Verified headless (Vulkan). D3D12 is untested (T13). Photo mode (A to shoot, crop to its frame) waits for photo mode.

### 4.84 Hide HUD (F1)
- [x] Done
- [ ] Approved by L
- 2026-10-13: F1 hides and shows the HUD, text boxes with their portraits, and the pause menu's text, live, with a "HUD hidden" / "HUD shown" notice (src/game/hide_hud.cpp; hooks in func_800A73F4). Not hidden: the pause menu's backdrop and icons, because the same call draws the frozen game picture behind the menu. Verified headless in Heggy's Egg Shed (her talk scene, walking, paused).

### 4.91 Crash handler and minidumps
- [x] Done
- [ ] Approved by L

### 4.95 Debug and test tooling
- [ ] Done
- [ ] Approved by L
- Partial (2026-10-13): `--pad-script` (scripted controller input, see src/debug/pad_script.cpp) and `TOOIE_WATCH` (RDRAM watch) are on main. Traces not started. tools/headless_boot.sh and notes/headless-testing.md added. Call profiler: tools/trace_build.sh, TOOIE_TRACE, tools/trace_diff.py (9c39f4b).

## Mid

### 4.6 Start-menu renames: "PC Settings" and "Exit"
- [ ] Done
- [ ] Approved by L

### 4.13 Timer save
- [x] Done
- Note: General > Timer save (Off/5/10/30/60/120 min, default Off). Counts the game's own play time (no pauses, menus or cutscenes) and calls _glsavegame_entrypoint_7(slot), the save half of the pause menu's Save and quit. Verified headless with TOOIE_TIMER_SAVE_SECONDS=10: new game, Spiral Mountain, the save file was rewritten every 10 s of play, and after a restart file 1 loaded straight into Spiral Mountain.
- [ ] Approved by L

### 4.21 Speed-up key (F2)
- [x] Done
- [ ] Approved by L

### 4.24 Field of view and cutscene field of view
- [x] Done
- [ ] Approved by L

### 4.25 Brightness with a calibration pattern
- [x] Done
- [ ] Approved by L

### 4.26 Extended draw distance
- [x] Done
- [ ] Approved by L

### 4.27 Detailed nests and Mayahem Temple stairs
- [ ] Done
- [ ] Approved by L

### 4.28 High-detail models always
- [x] Done
- [ ] Approved by L
- 2026-10-13: QOL > High-detail models (on by default, live). Hooks the geo LOD command (func_800DD214 draw pass, func_800DD2E8 matrix pass) after the squared camera distance is computed and sets it to 1, so every LOD command picks its detailed child. Checked headless with TOOIE_LOD_LOG=1: Jinjo Village, Mayahem Temple, Witchyworld, Terrydactyland and JRL all use LOD pairs (for example near 0 / far 1800 and near 1800 / far 2e8); with the option on, the detailed child runs at every distance. Banjo swapping by distance (report f) not checked. Code: src/gameplay/high_detail_models.cpp. 2026-10-13: renamed "Always High-Detail Models" (L); also hooks the third LOD pass, func_800DD37C. L asked for Banjo too: his model has no LOD command (none run in Spiral Mountain), so that needs the cutscene model swap, waiting on L's card. Moved to the Graphics tab (L); the saved QOL value is not carried over, so it starts On again. Banjo (L: the necklace model): func_80094070 picks his Banjo-Kazooie model by camera distance through func_80093F30(level 0 close-up / 1 far); a hook at its entry forces level 0 while the option is on. Checked headless: necklace and buckle at normal distance with it on, plain model with it off.

### 4.29 Level transition speed
- [x] Done
- Note: QOL tab "Level transitions" (Original / Fast 4x / Instant 16x), default Original. Speeds up the gctransitionDll wipe of a map change and its fade-in only; cutscene fades keep their speed. Headless warp AF→B8: 5.3 s → 1.4 s. About 1.2 s between the wipe-out and the fade-in is outside the wipe and is left as is. `TOOIE_LOG_TRANSITIONS=1` logs wipe timing.
- [ ] Approved by L

### 4.40 Retro: N64 3-point filtering, 16-bit dither, CRT
- [x] Done
- [ ] Approved by L

### 4.41 Colourblind filters
- [x] Done
- [ ] Approved by L

### 4.45 Water: underwater tint, water reflections, caustics, heat haze
- [ ] Done
- [ ] Approved by L

### 4.50 Texture upscaling (xBR-style live cache) and the Real-ESRGAN tool
- [ ] Done
- [ ] Approved by L

### 4.51 HD shadows
- [ ] Done
- [ ] Approved by L

### 4.53 Canary Mary rubber banding
- [x] Done
- [ ] Approved by L

### 4.54 Talon Trot toggle
- [x] Done
- [ ] Approved by L

### 4.56 Dedicated tiptoe button
- [x] Done
- [ ] Approved by L

### 4.57 Fine aim
- [x] Done
- [ ] Approved by L

### 4.58 Gyro aiming and camera
- [x] Done (T64)
- [ ] Approved by L
- 2026-10-14 (T64, with 4.58/4.59): in first person the mouse and a controller's gyro turn the view directly (src/input/motion_aim.cpp), on top of the stick. The source angles are the dynamic camera's +0xBC pitch / +0xC0 yaw (found by RDRAM diffs, checked by writing them headless: the view, Banjo's yaw and the up/down limits of -68 and 70 follow). Strength: General > Mouse Sensitivity (default 0, off; non-zero locks the cursor while playing) and Gyro Sensitivity (default 25%), both RecompFrontend's own rows. QOL > "Mouse and gyro aim: invert up/down". Checked headless with scripted mouse motion; real mouse and gyro not checked.

### 4.60 D-pad control scheme
- [x] Done
- [ ] Approved by L

### 4.61 Music player
- [x] Done
- [ ] Approved by L

### 4.62 Skip boss intros
- [x] Done
- [ ] Approved by L

### 4.63 Glitter honeycombs (Cut Content)
- [x] Done
- [ ] Approved by L

### 4.64 Classic jump sounds (Cut Content)
- [x] Done (General > Back-Port: Old Banjo sounds; CI green on 1abb9fe, T46)
- [ ] Approved by L

### 4.68 Stop 'n' Swop without a Banjo-Kazooie save
- [x] Done (flags only; the in-world effect is untested, T26)
- [ ] Approved by L

### 4.74 Fly anywhere, and the stop-flying button
- [x] Done (T50)
- [ ] Approved by L

### 4.75 Clip through anything (noclip)
- [x] Done (T53)
- [ ] Approved by L

### 4.76 Split up anywhere
- [x] Done (T55)
- [ ] Approved by L

### 4.77 Bottles' Revenge (Cut Content)
- [x] Done (T61)
- [ ] Approved by L

### 4.78 Transformation picker
- [x] Done
- [ ] Approved by L

### 4.86 Notice toasts
- [x] Done
- [ ] Approved by L

### 4.90 Discord Rich Presence
- [x] Done
- [ ] Approved by L

### 4.92 Hang watchdog
- [x] Done
- [ ] Approved by L

## Long

### 4.14 Save states
- [x] Done (T63)
- [ ] Approved by L
- 2026-10-14: Insert saves, Home loads (Controls > Hotkeys > Save State / Load State). One slot in memory, in a level. A save copies all 8 MB of RDRAM, the game thread's registers and the runtime state that goes with it (overlay tables, RDP freeze, VI framebuffers, pending host messages, ready-thread queue head; lib-patches/N64ModernRuntime.patch) at the start of the game's frame update, after any RSP or display list task finishes. A load needs every game thread waiting on the same queue as at the save and the same stack; it retries for up to 300 frames. A load from another area warps back there first: loading straight across areas hung the game headless. Checked headless: 6 loads in a row in Spiral Mountain, and a load from Mayahem Temple, with play carrying on after. Not checked: sound after a load.

### 4.35 Shader effects suite (AO, GI, fog, reflections, light shafts, sharpening, colour grading)
- [ ] Done
- [ ] Approved by L

### 4.36 Bloom, toon outlines, rim light, cutscene DoF, vignette and grain, 16-bit effects
- [ ] Done
- [ ] Approved by L

### 4.37 Eye adaptation
- [ ] Done
- [ ] Approved by L

### 4.42 Effect presets
- [ ] Done
- [ ] Approved by L

### 4.43 F8 split-screen compare, F3 per-effect GPU times, F6 debug views
- [ ] Done
- [ ] Approved by L

### 4.46 Real-time water waves (requested 2026-10-13, not built)
- [ ] Done
- [ ] Approved by L

### 4.47 3D grass (requested 2026-10-13, not built)
- [ ] Done
- [ ] Approved by L

### 4.59 Mouse aiming
- [x] Done (T64)
- [ ] Approved by L
- 2026-10-14 (T64, with 4.58/4.59): in first person the mouse and a controller's gyro turn the view directly (src/input/motion_aim.cpp), on top of the stick. The source angles are the dynamic camera's +0xBC pitch / +0xC0 yaw (found by RDRAM diffs, checked by writing them headless: the view, Banjo's yaw and the up/down limits of -68 and 70 follow). Strength: General > Mouse Sensitivity (default 0, off; non-zero locks the cursor while playing) and Gyro Sensitivity (default 25%), both RecompFrontend's own rows. QOL > "Mouse and gyro aim: invert up/down". Checked headless with scripted mouse motion; real mouse and gyro not checked.

### 4.81 Debug section with race warps (parked)
- [ ] Done
- [ ] Approved by L

### 4.82 Photo mode
- [ ] Done
- [ ] Approved by L
- 2026-10-14: first part built (T60). The Photo Mode key (F10, or the controller's Share/Misc button; bindable under Controls > Hotkeys) freezes the game by scaling its delta time (0x8012C760), hides the HUD and the area name, and flies the camera: left stick moves, right stick looks, Z/R down/up (a held move speeds up after a second), L hide Banjo (skips the player draws func_800F5008 / func_800F50D0), A screenshot, D-pad up HUD, D-pad down orbit Banjo (Z/R closer/further), D-pad left/right zoom (the field of view, via tooie_set_fov), Start frozen / 1/8 / 1/4, B back. Code: src/gameplay/photo_mode.cpp, camera written from the free camera's hook. Verified headless in Spiral Mountain. Camera collision (QOL > Photo mode camera collision, on): moves are swept with the game's camera line test and slide along what they hit; in orbit the line from Banjo pulls the camera in. Filters: QOL > Photo filter (10 looks) and Photo exposure / contrast / saturation / warmth / vignette / film grain, drawn by an RT64 pass after SMAA (lib-patches/rt64.patch, PhotoGradePS.hlsl) only while photo mode is on, so screenshots show them; changed from the menu. Crop and grid (2026-10-14, T62): QOL > Photo crop (16:9, 2.39:1, 4:3, 1:1, 4:5, 9:16) shades outside the frame in the same RT64 pass and screenshots keep only the frame (src/game/screenshot.cpp); QOL > Photo grid draws rule-of-thirds lines inside it, left out of the frame a screenshot is taken from. Checked headless: 4:5 gave a 730x912 screenshot without the grid while the window showed it. Not built yet: the in-mode D-pad list, tilt and depth of field (needs the scene depth in RT64's present pass).

### 4.85 Achievements pop-up
- [ ] Done
- [ ] Approved by L

### 4.88 Asset dump and replacement
- [ ] Done
- [ ] Approved by L

### 4.89 Model mods: Smash Banjo and FBX Banjo (out of repo)
- [ ] Done
- [ ] Approved by L

## Stretch

### 4.97 Requested or planned but not started (carry onto the roadmap)
- [ ] Done
- [ ] Approved by L

### 4.98 New sun shadows shader (rebuilt as an RT64 pass, replaces 4.38)
- [ ] Done
- [ ] Approved by L

## Free

### 4.1 Platform boot (Windows D3D12/Vulkan, Linux Vulkan)
- [ ] Done
- [ ] Approved by L

### 4.8 F5 "PC Settings" window (ImGui) and the SDK overlays
- [ ] Done
- [ ] Approved by L

### 4.9 Config file and option table (BanjoTooieConfig)
- [ ] Done
- [ ] Approved by L

### 4.23 Window mode: fullscreen or windowed, live
- [ ] Done
- [ ] Approved by L

### 4.31 Low input latency and late frame start
- [ ] Done
- [ ] Approved by L

### 4.32 Performance defaults
- [ ] Done
- [ ] Approved by L

### 4.33 Graphics API choice
- [ ] Done
- [ ] Approved by L

### 4.34 Anti-aliasing, supersampling, upscaling
- [ ] Done
- [ ] Approved by L

### 4.49 Texture dumping and replacement
- [ ] Done
- [ ] Approved by L

### 4.87 Mod folders
- [ ] Done
- [ ] Approved by L

## Dropped

### 4.3 Full version and the "Connect to Xbox LIVE" prompt (XBLA only)
- [ ] Done
- [ ] Approved by L

### 4.4 Xbox LIVE Arcade splash skip (XBLA only)
- [ ] Done
- [ ] Approved by L

### 4.16 300 Hz substeps
- [ ] Done
- [ ] Approved by L

### 4.17 60 fps per-frame constant blends
- [ ] Done
- [ ] Approved by L

### 4.18 Animation steps held at 30 (blinks, fades, swim strokes)
- [ ] Done
- [ ] Approved by L

### 4.19 Menu/HUD widget animations and cursor repeat at 30
- [ ] Done
- [ ] Approved by L

### 4.20 Dialogue at 30 Hz with the text box opening at full rate
- [ ] Done
- [ ] Approved by L

### 4.44 Smooth triangles (removed)
- [ ] Done
- [ ] Approved by L

### 4.48 Fonts: TrueType redraw (Comicrazy), font toggle
- [ ] Done
- [ ] Approved by L

### 4.65 N64 pitch limit (N64-accurate music)
- [ ] Done
- [ ] Approved by L

### 4.93 Sound command queue guard
- [ ] Done
- [ ] Approved by L

### 4.94 Sound list loop guard
- [ ] Done
- [ ] Approved by L

### 4.39 Sun flare through walls fix
L ruled this not relevant to this project on 2026-10-13 ("Sunglare fix for instance is not relevant in this Project"). Leave unticked.
- [ ] Done
- [ ] Approved by L

### 4.96 Small fixes (XBLA or SDK)
- [ ] Done
- [ ] Approved by L

### 4.38 Sun shadows
- [ ] Done
- [ ] Approved by L
