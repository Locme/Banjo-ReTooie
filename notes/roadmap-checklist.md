# Banjo-Tooie N64 recomp: roadmap checklist

Every item has two boxes:

- **Done**: Claude ticks this only when the work has landed on `main`. Partial work stays unticked, with a note.
- **Approved by L**: only L ticks this, and only when happy. Claude ticks it only when L says to.

Numbers are the feature numbers in the handoff report, Section 4.

## Short

### 4.2 One-click build and update scripts
- [x] Done
- [ ] Approved by L
- 2026-10-14: build.bat (finds Visual Studio with the Clang tools, builds into Release) and update_and_build.bat (pulls, restarts itself when the update changed it, repairs common build breaks, lists the error lines on a failure) are on main and are what L builds with. Dependencies are pinned as submodules plus lib-patches/.

### 4.5 Quick start (Start skips the intro)
- [x] Done
- [ ] Approved by L
- Note (2026-10-13): Start during the logos or title flight (map 0x18B) goes to the file select with the title's own wipe; on the finished title the game's own Start runs. General tab "Skip intro logos", on by default. Start in attract demos is left to the game.

### 4.7 Native in-game settings page ("GRAPHICAL SETTINGS", was "PC SETTINGS")
- [x] Done
- [ ] Approved by L
- Note (2026-10-13): L chose the RmlUi settings screen opened with Esc or the controller's Back/Select button; no row in the N64 pause menu.

### 4.10 Settings apply without restart
- [x] Done
- [ ] Approved by L
- Partial (2026-10-13): every Graphics tab option applies and saves the moment it changes; no Apply button needed (lib-patches/RecompFrontend.patch). Graphics API still needs a restart (RT64).
- 2026-10-14: claimed by the Opus helper thread (frame-rate thread): Graphics API switch without a restart, behind an option that defaults to off.
- 2026-10-14: L chose an automatic restart over rebuilding the renderer live (the menus are drawn by the renderer, so a live rebuild means tearing them down mid-game). Picking another Graphics API asks "Restart now?"; Restart closes the game and starts it again with the new API, Later keeps it for the next start (src/game/api_restart.cpp). Switching back to the API in use asks nothing. Verified headless: Vulkan run, change confirmed, the game came back on its own with the saved choice; D3D12 could not be run here. T93.

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
- Stretching and pops (2026-10-14, after L: "mesh models suddenly stretching making a broken image but it corrects itself"): a list drawn many times in one model (chains, rows of plants, swarms; up to 45 in Spiral Mountain) was numbered in draw order, so when the game left one out, the ids after it moved onto neighbours and the mesh stretched. Each drawing now keeps last frame's nearest drawing's number (7a025d1); copies of a model are paired closest first (fc5fb28). Banjo's last unpaired bone was his face, which swaps between three lists as he blinks; it now keeps its id (ac39168). Headless at Manual 170 in three levels: no parts paired over 100 units off, and no unpaired bones. T76.

### 4.22 Fit to window: fill / letterbox / 4:3, HUD 16:9
- [x] Done
- [ ] Approved by L
- Partial (2026-10-13): Fill works through Settings > Graphics > Aspect Ratio = Expand (RT64 widens the picture; the game's culling now widens with it, src/game/widescreen.cpp). 4:3 is Aspect Ratio = Original. The HUD stays in the middle 4:3. Letterbox 16:9 added (2026-10-13): Aspect Ratio now reads 4:3 / Fill / Letterbox 16:9. HUD at the edges added (2026-10-13, src/game/hud_edges.cpp): Settings > Graphics > HUD Placement. Original keeps the HUD in the 4:3 middle, 16:9 spreads it up to 16:9, Expand to the window edges. Verified headless in a 16:9 window (paused in Spiral Mountain).

### 4.30 Cutscene audio sync and N64 intro pacing
- [ ] Done
- [ ] Approved by L
- 2026-10-14: not needed on N64 (L: audio sync only affects the XBLA version). Dropped.

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
- 2026-10-14: nothing to port (the XBLA fix was removed). The open question is whether the Beak Barge volume drop with the right stick held forward happens here, where the game's own N64 mixer runs: if it does, it is how the N64 game behaves. Asked L to check (T70).

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
- 2026-10-14: deferred. Settings already open from Esc, F5 and the controller hotkey. A "Settings" row in the game's pause menu needs a new text entry (rows name their text by id), a layout change and a function hook (the main thread owns the hook file); the pause overlay's option table (D_80802070, rows of icon/text/function/sub-option/are-you-sure) was not found in memory headless yet.

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
- Partial (2026-10-14, T79): Graphics > Underwater tint (default 25) and Underwater haze (default 15), L's XBLA defaults, in the scene effects pass (4.35) under the HUD, easing in and out over a fifth of a second. Under water = player state 57 (swimming under) or 43 (floating, measured headless in Atlantis on N64; same numbers as XBLA), or the map is Atlantis (0x1A8) or the Sea Bottom (0x1A9). The camera's own position isn't checked, so the look follows Banjo, not the camera. TOOIE_WATER_TRACE=1 logs the player state. Checked headless in Atlantis. Heat haze (2026-10-14, T82): Graphics > Heat haze (0-100, default off; Enhanced preset 50) in the same pass, only on Hailfire Peaks' lava side (0x127), lava train station (0x129), Chilli Billi (0x12B) and inside the volcano (0x133): the scene so far read a few pixels off in rising waves, more past 300 units, never from something nearer (near edges stay put). Checked headless on the lava side. Map-based, not the XBLA lava collision flag. Underwater distortion (2026-10-14, in T79): Graphics > Underwater distortion (default 30) is the same shimmer at half strength while under water. Water reflections (2026-10-14, T88): Graphics > Water reflections (0-100, default off; Enhanced preset 60). RT64's framebuffer renderer lists the 3D world's draws that look like water (alpha blended, depth tested, no depth write, not a decal, at least 4 triangles) and, before the scene effects pass, redraws them with their own pipelines into a water mask that holds each pixel's surface depth (RasterPS with RasterParams.waterMask). The pass keeps flat, upward surfaces lying over something further down (fading in from the shore, so ground shadows don't count), marches a reflected ray with ripples across the screen against the depth, and falls back to the sky. F6 has a water view (red mask, yellow where it reflects). Checked headless in the Spiral Mountain pool behind the waterfall: Banjo and the tunnel mirror in the water, the waterfall face is left out. Only what is on screen can reflect. No game-side tagging (model_tagging.cpp untouched). Caustics not started.

### 4.50 Texture upscaling (xBR-style live cache) and the Real-ESRGAN tool
- [ ] Done
- [ ] Approved by L
- Partial (2026-10-14, T91): live upscaler done. Graphics > Texture upscaling Off / 2x / 4x (Enhanced preset 2x), live. RT64's texture cache upscales each decoded game texture on the GPU (TextureUpscaleCS.hlsl, the project's own edge-directed 2x written from the published xBR level-1 rule, run twice for 4x; the GPL xBRZ code was not used) and uses it as the texture's replacement. Textures a texture pack replaces are left alone, and raw-TMEM textures (not decoded) aren't upscaled. Changing the setting re-upscales everything already loaded. Checked headless in Spiral Mountain at 4x and with live 2x then Off. The Real-ESRGAN offline tool is not started.

### 4.51 HD shadows
- [ ] Done
- [ ] Approved by L
- 2026-10-14: claimed by the Second Opus helper thread (L picked it). Graphics > HD Shadows (off by default, live). The player's shadow is already drawn from a model on N64, but from a simpler per-form shadow model (0x853 for Banjo-Kazooie); a hook in func_800A6250 swaps in the model on screen, which the game already supports. Checked headless in map 0x173: the shadow model 801A6280 is replaced by the on-screen model 801BA710 (TOOIE_SHADOW_LOG=1). T87. Enemies and NPCs (L's pick): a hook after the generic actor draw (func_80101808) redraws the actor flattened onto the floor below it into the same shadow buffer and pastes it, up to 12 per frame. Checked headless at Klungo in map AF:3 (shadow on, none with the option off). T94.

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
- Partial (2026-10-14, T66): Graphics > Sharpening (contrast-adaptive), Contrast and Colour saturation, drawn by the photo grade RT64 pass (lib-patches/rt64.patch, PhotoGradePS.hlsl) during play; photo mode takes over its filters while on and the Graphics ones come back after. Ambient occlusion (2026-10-14, T67): Graphics > Ambient occlusion (0-100). RT64's framebuffer renderer now starts a new raster scene at the first non-perspective projection after the 3D world (the HUD), and a scene effects pass (SceneEffectsPS.hlsl, src/render/rt64_scene_effects.cpp in lib-patches/rt64.patch) runs there in the game's framebuffer only (depth buffer address from 0x8007BCC4): it reads the depth target (at the MSAA sample count), rebuilds view-space positions from the 3D projection (depth is z / w in [0, 1]) and darkens by 12 samples within 200 world units. The HUD, text and the level-entry wipe draw after it and stay clean (checked headless in Spiral Mountain). TOOIE_SCENE_FX_VIEW=1 shows the occlusion alone. Fog (2026-10-14, T68): Graphics > Fog (0-100), Fog start distance (default 1500) and Fog colour (Haze, Mist, Dusk, Gloom), in the same pass: it thickens exponentially over 3000 units past the start, and the sky takes 75% of it so there is no hard edge; the game's own fog is untouched. Checked headless: Dusk at 60 with AO 60 in Spiral Mountain, HUD and area title clean. Water-only reflections would go in this pass next. Code: src/display/picture_filters.cpp.
 Bounce light (2026-10-14, T90): Graphics > Bounce light (0-100, default off) in the scene effects pass: 16 samples around each pixel over 1.5x the occlusion radius gather the colour of nearby surfaces facing it, and the pixel is lit by that (scene x bounce x 1.5 x strength), so grass tints the stone beside it. Checked headless in Jolly Roger's Lagoon (faint speckle at 100). Contact shadows and light shafts not started (no sun direction in the pass yet).
### 4.36 Bloom, toon outlines, rim light, cutscene DoF, vignette and grain, 16-bit effects
- [x] Done
- [ ] Approved by L
- Partial (2026-10-14, T66): Graphics > Vignette and Film grain during play (same pass as 4.35). 16-bit colour is 4.40 (Graphics > Retro). Toon outlines (2026-10-14, T69): Graphics > Toon outlines (0-100) in the scene effects pass (4.35), dark where the distance jumps by over 8% against a neighbour, about a pixel per 540 rows, under the HUD; checked headless around Banjo, the posts and the platform edge. Bloom (2026-10-14, T72): Graphics > Bloom (0-100) in the same pass: the scene so far (resolved, or copied without MSAA) gives its parts above 65% brightness at a quarter size, blurred across and down (BloomPS.hlsl), added under the HUD; each RT64 worker that records the pass has its own textures (the workload thread and the game's framebuffer syncs record at the same time, which crashed when shared). Checked headless: clouds and lit rock glow, HUD head and area title don't. Cutscene depth of field (2026-10-14, T73): Graphics > Cutscene depth of field (0-100), only while tooie::in_letterboxed_scene(); drawn in the scene effects pass from the scene so far, so cutscene text and the HUD stay sharp; focus is the nearest thing in a 5x5 box at the middle. Checked headless on the title flyby: near rock blurs, logo and copyright text sharp. Rim light (2026-10-14, T81): Graphics > Rim light (0-100) in the same pass: a warm-white band about four pixels per 540 rows wide inside the edge of anything in front of something further back, strongest where the surface turns away from the camera, kept off tops that face up (ground and ledge edges) and fading out past 1500-4000 units. Checked headless in Spiral Mountain (effects-only view): Banjo's outline, posts and rope net lit, ground not.

### 4.37 Eye adaptation
- [x] Done
- [ ] Approved by L
- 2026-10-14 (T74): Graphics > Eye adaptation (0-100) in the scene effects pass (4.35): the scene's average brightness (geometric mean of a 16x16 grid) is eased toward over about a second, and the picture is brightened in dark places and toned down in bright ones (exposure 0.5x to 2.5x), under the HUD. Checked headless: Glitter Gulch Mine mean brightness 69 -> 93, Spiral Mountain 89 -> 92.

### 4.42 Effect presets
- [x] Done
- [ ] Approved by L
- 2026-10-14 (T71): Graphics > Effects preset: Custom, Original (every effect off), Enhanced (SMAA High, ambient occlusion 50, sharpening 30), Retro (N64 16-bit colour Console, CRT, 3-point filtering). It sets the options through update_option_value, so the menu shows the new values, and saves once; changing any effect it covers by hand makes it Custom. Brightness, colourblind and fog colour/start are left alone. Sun shadows aren't in it (4.98 not built). Checked headless with TOOIE_PRESET_TEST (saved graphics.json values for each preset). Code: src/display/picture_filters.cpp.

### 4.43 F8 split-screen compare, F3 per-effect GPU times, F6 debug views
- [ ] Done
- [ ] Approved by L
- Partial (2026-10-14, T80): F6 steps through the scene effects pass's views (effects alone, depth: near white, far dark, sky blue, normals, off) and F8 splits the picture (scene effects and photo grade passes on the left half, original on the right, a white line between); src/display/effect_views.cpp, lib-patches/rt64.patch. The volumetric view has nothing to show (no volumetrics built). F3 per-effect GPU times not started (the frame rate overlay is another thread's).

### 4.46 Real-time water waves (requested 2026-10-13, not built)
- [x] Done
- [ ] Approved by L
- 2026-10-14 (T95): Graphics > Water waves (0-100, default off; Enhanced preset 50) and Water wave speed (25-200%). Route 2 of the handoff, as an RT64 normal-map pass rather than moving vertices: in the scene effects pass, on the water mask's flat surfaces (4.45), four travelling waves (mostly one way, wavelengths 230 to 51 units) over the world's x and z give a normal; the water seen through bends with it, slopes facing the light brighten and the others darken, with a glint, and water reflections use the same waves. World x and z come from RT64's view matrix (its inverse, sent with the pass), so the waves stay in place as the camera turns. Small waves fade out with distance. Collision is untouched and the surface doesn't move, so Banjo floats as before (risk f). Checked headless in the Spiral Mountain pool behind the waterfall with F8 compare.

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
- 2026-10-14: tried and parked. Warping straight to the race maps (0x16F, 0x170 mine cart, 0x161 clouds) works but Mary and the race are not there unless her flags are set: 0x066 (freed) and 0x507 (ready to race) for the mine cart, 0x504 for the clouds, plus the 3-bit race state at flag 0xA4C (mine cart) or 0xA37 (clouds) set to 1 (all read back fine after setting). With those set the game crashes at the cart's init (func_80802068_chhandcart calling func_800EE88C on a missing cube-search prop 0x313/0x314 in the race map), so the race can't be entered from a warp yet. Canary Cave (0xDB) in the Warp tab starts the races normally.

### 4.82 Photo mode
- [x] Done
- [ ] Approved by L
- 2026-10-14: first part built (T60). The Photo Mode key (F10, or the controller's Share/Misc button; bindable under Controls > Hotkeys) freezes the game by scaling its delta time (0x8012C760), hides the HUD and the area name, and flies the camera: left stick moves, right stick looks, Z/R down/up (a held move speeds up after a second), L hide Banjo (skips the player draws func_800F5008 / func_800F50D0), A screenshot, D-pad up HUD, D-pad down orbit Banjo (Z/R closer/further), D-pad left/right zoom (the field of view, via tooie_set_fov), Start frozen / 1/8 / 1/4, B back. Code: src/gameplay/photo_mode.cpp, camera written from the free camera's hook. Verified headless in Spiral Mountain. Camera collision (QOL > Photo mode camera collision, on): moves are swept with the game's camera line test and slide along what they hit; in orbit the line from Banjo pulls the camera in. Filters: QOL > Photo filter (10 looks) and Photo exposure / contrast / saturation / warmth / vignette / film grain, drawn by an RT64 pass after SMAA (lib-patches/rt64.patch, PhotoGradePS.hlsl) only while photo mode is on, so screenshots show them; changed from the menu. Crop and grid (2026-10-14, T62): QOL > Photo crop (16:9, 2.39:1, 4:3, 1:1, 4:5, 9:16) shades outside the frame in the same RT64 pass and screenshots keep only the frame (src/game/screenshot.cpp); QOL > Photo grid draws rule-of-thirds lines inside it, left out of the frame a screenshot is taken from. Checked headless: 4:5 gave a 730x912 screenshot without the grid while the window showed it. Depth of field (2026-10-14, T65): QOL > Photo depth of field (0-100) keeps the nearest thing in a small box at the middle of the picture sharp and blurs by distance from it; the game's depth buffer (pointer at 0x8007BCC4) is copied to colour in RT64's present pass and read by the same photo pass. Checked headless in Spiral Mountain at 80: cliff at the middle sharp, nearer platform and sky blurred. Tilt (2026-10-14, T65): QOL > Photo tilt (-45 to 45 degrees) writes the camera's roll (+0x20); checked headless at 20, the picture turns clockwise. Not built yet: the in-mode D-pad list (the settings are QOL rows that apply live instead).
 Photo panel (2026-10-14, T85): while photo mode is on, a list at the top left (src/ui/photo_panel.cpp, a UI layer, so never in screenshots) shows Zoom, Camera (free / orbit Banjo), Time, HUD, Banjo, Filter, Exposure, Contrast, Saturation, Warmth, Vignette, Film grain, Depth of field, Tilt, Crop and Grid with the controls under it; D-pad up/down picks a row, left/right changes it (held repeats; zoom held), L hides the list. The rows write the same QOL options as the menu. D-pad up/down no longer toggle HUD/orbit and L no longer hides Banjo: those are rows now. Checked headless: five D-pad downs and two rights set Filter to Black and white, and the A screenshot showed the filter without the list. Left out from XBLA: right-stick click to level and unzoom (set Tilt to 0 and Zoom back by hand), and the WASD/QE keyboard layout (keyboard keys follow the N64 bindings).
### 4.85 Achievements pop-up
- [ ] Done
- [ ] Approved by L
- 2026-10-14: owned by the Super Opus 64 helper thread (XBLA achievement back-port and pop-ups).

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
- [x] Done
- [ ] Approved by L
- 2026-10-14: claimed by the Opus helper thread with 4.10. The Graphics API row was hidden in the menu (upstream); it now shows in Graphics with Vulkan (default) and D3D12 on Windows (default set by the Sonnet Tasks lane). Untested on D3D12 until L tries it, so the default stays Vulkan. T93.

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
