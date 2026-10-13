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

### 4.22 Fit to window: fill / letterbox / 4:3, HUD 16:9
- [ ] Done
- [ ] Approved by L
- Partial (2026-10-13): Fill works through Settings > Graphics > Aspect Ratio = Expand (RT64 widens the picture; the game's culling now widens with it, src/game/widescreen.cpp). 4:3 is Aspect Ratio = Original. The HUD stays in the middle 4:3. Letterbox 16:9 added (2026-10-13): Aspect Ratio now reads 4:3 / Fill / Letterbox 16:9. Not done: HUD pinned to the edges.

### 4.30 Cutscene audio sync and N64 intro pacing
- [ ] Done
- [ ] Approved by L

### 4.52 Text speed
- [ ] Done
- [ ] Approved by L

### 4.55 Twin-stick (free) camera
- [ ] Done
- [ ] Approved by L

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
- [ ] Done
- [ ] Approved by L

### 4.71 Unlock all moves
- [ ] Done
- [ ] Approved by L

### 4.72 Unlock everything
- [ ] Done
- [ ] Approved by L

### 4.73 Levitate
- [ ] Done
- [ ] Approved by L

### 4.79 Infinite jumps
- [ ] Done
- [ ] Approved by L

### 4.80 Level warp (F5 list and F9)
- [ ] Done
- [ ] Approved by L

### 4.83 Screenshots (F12) with a notice
- [ ] Done
- [ ] Approved by L

### 4.84 Hide HUD (F1)
- [ ] Done
- [ ] Approved by L

### 4.91 Crash handler and minidumps
- [x] Done
- [ ] Approved by L

### 4.95 Debug and test tooling
- [ ] Done
- [ ] Approved by L
- Partial (2026-10-13): `--pad-script` (scripted controller input, see src/debug/pad_script.cpp) and `TOOIE_WATCH` (RDRAM watch) are on main. Traces not started. tools/headless_boot.sh and notes/headless-testing.md added.

## Mid

### 4.6 Start-menu renames: "PC Settings" and "Exit"
- [ ] Done
- [ ] Approved by L

### 4.13 Timer save
- [ ] Done
- [ ] Approved by L

### 4.21 Speed-up key (F2)
- [ ] Done
- [ ] Approved by L

### 4.24 Field of view and cutscene field of view
- [ ] Done
- [ ] Approved by L

### 4.25 Brightness with a calibration pattern
- [ ] Done
- [ ] Approved by L

### 4.26 Extended draw distance
- [ ] Done
- [ ] Approved by L

### 4.27 Detailed nests and Mayahem Temple stairs
- [ ] Done
- [ ] Approved by L

### 4.28 High-detail models always
- [ ] Done
- [ ] Approved by L

### 4.29 Level transition speed
- [ ] Done
- [ ] Approved by L

### 4.40 Retro: N64 3-point filtering, 16-bit dither, CRT
- [ ] Done
- [ ] Approved by L

### 4.41 Colourblind filters
- [ ] Done
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
- [ ] Done
- [ ] Approved by L

### 4.54 Talon Trot toggle
- [ ] Done
- [ ] Approved by L

### 4.56 Dedicated tiptoe button
- [ ] Done
- [ ] Approved by L

### 4.57 Fine aim
- [ ] Done
- [ ] Approved by L

### 4.58 Gyro aiming and camera
- [ ] Done
- [ ] Approved by L

### 4.60 D-pad control scheme
- [ ] Done
- [ ] Approved by L

### 4.61 Music player
- [ ] Done
- [ ] Approved by L

### 4.62 Skip boss intros
- [ ] Done
- [ ] Approved by L

### 4.63 Glitter honeycombs (Cut Content)
- [ ] Done
- [ ] Approved by L

### 4.64 Classic jump sounds (Cut Content)
- [ ] Done
- [ ] Approved by L

### 4.68 Stop 'n' Swop without a Banjo-Kazooie save
- [ ] Done
- [ ] Approved by L

### 4.74 Fly anywhere, and the stop-flying button
- [ ] Done
- [ ] Approved by L

### 4.75 Clip through anything (noclip)
- [ ] Done
- [ ] Approved by L

### 4.76 Split up anywhere
- [ ] Done
- [ ] Approved by L

### 4.77 Bottles' Revenge (Cut Content)
- [ ] Done
- [ ] Approved by L

### 4.78 Transformation picker
- [ ] Done
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
- [ ] Done
- [ ] Approved by L

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
- [ ] Done
- [ ] Approved by L

### 4.81 Debug section with race warps (parked)
- [ ] Done
- [ ] Approved by L

### 4.82 Photo mode
- [ ] Done
- [ ] Approved by L

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
