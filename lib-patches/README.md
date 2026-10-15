# Patches to submodules

CMake applies these to the submodule checkouts when it configures the build,
so the submodules stay pinned to their upstream commits.

## N64ModernRuntime.patch

* **Thread queue** (`ultramodern/src/threadqueue.cpp`): `thread_queue_remove`
  never moved past the head of the queue, so removing any other thread looped
  forever. `thread_queue_insert` could insert a thread that was already queued,
  linking the list into a cycle. Banjo-Tooie hit both during boot.
* **RDP freeze bit** (`librecomp/src/dp.cpp`, `ultramodern/src/events.cpp`):
  Banjo-Tooie paces frames with `DPC_STATUS_FREEZE`. A real RDP does no work
  while frozen, so a display list submitted then cannot finish before the game
  unfreezes it. The host renders at once, so the runtime now holds the "RDP
  done" message until the freeze is cleared. Without this the game lost track
  of its frames and stopped on the first one.
* **Save state support** (`librecomp/src/overlays.cpp`, `ultramodern/src/events.cpp`,
  `ultramodern/src/threads.cpp`, `ultramodern/src/threadqueue.cpp`, `ultramodern/src/mesgqueue.cpp`):
  ways to read and put back the runtime state that goes with RDRAM, for save states
  (handoff 4.14, `src/gameplay/save_state.cpp`): the loaded overlay table, the RDP
  freeze and its held completions, the VI framebuffers, the messages host threads
  have sent but the game hasn't taken, the head of the ready-thread queue, and a list
  of the game threads with the queue each waits on. `wait_for_tasks_idle` waits until
  no RSP or display list task is running, since those read and write RDRAM.

* **Sound task failure** (`ultramodern/src/events.cpp`, `ultramodern/include/ultramodern/ultramodern.hpp`):
  a sound (audio) task whose microcode stops on a bad command list ("Unhandled jump target ... in
  n_aspMain") used to end the game. That sound frame is now skipped and logged, and the game and its
  sound carry on. `set_audio_task_check` lets the game look at a sound task just before it runs
  (`src/game/audio_task_check.cpp` logs a list that changed after it was queued).

* **VI start-up crash** (`ultramodern/src/events.cpp`): the game can start before the VI thread's
  first tick, so no mode was set yet and `update_vi` read a null `OSViMode` (a segfault on "VI Thread"
  in about 1 in 4 to 1 in 30 boots). The VI thread now falls back to the dummy mode, and swaps the VI
  states under `message_mutex`, which `osViSetMode` and `osViSwapBuffer` already hold.

* **VI rate multiplier** (`ultramodern/src/events.cpp`, `ultramodern.hpp`): `set_vi_rate_multiplier(n)`
  sends VIs 60 * n times a second (game time unchanged, unlike the speed multiplier) while the AI
  messages stay at 60 a second. Game Frame Rate 120 FPS and Unlocked use 2 and 4
  (`src/game/game_frame_rate.cpp`).

* **Low input latency** (`ultramodern/src/events.cpp`, `ultramodern.hpp`): upstream queues each screen
  update before latching the framebuffer the game just swapped in, so a frame showed two VIs after
  the swap. `set_low_latency(true)` queues it after the latch, so it shows at the next VI, as on an
  N64 (Graphics > Low Input Latency, `src/input/low_latency.cpp`). `TOOIE_VI_LOG=1` prints each VI
  message, buffer swap, screen update and player 1 controller read, timed from the latest VI tick.

To change a patch: edit the files in `lib/N64ModernRuntime`, then
`git -C lib/N64ModernRuntime diff > lib-patches/N64ModernRuntime.patch`.

## RecompFrontend.patch

* **Option display order** (`recompui/include/recompui/config.h`, `ui_config.cpp`, `ui_config_page_options_menu.cpp`): `set_option_display_before(id, before_id)` shows an option above another in its tab without changing the config schema (used to show MS Anti-Aliasing under Anti-aliasing and scaling).
* **Settings search** (`recompui/src/config/ui_config.cpp`, `create_search_tab()`): a Search tab with a hidden row for every option of every other tab; typing in its box shows the matching rows.
* **Focus scrolls into view** (`recompui/src/elements/ui_button.cpp`): a button that gets focus scrolls itself into view, so moving down a long list with a controller keeps the selection visible.
* **1440p resolution** (`ui_config_tab_graphics.cpp`, `rt64_render_context.cpp`, and `ultramodern/include/ultramodern/config.hpp` in N64ModernRuntime.patch): `R1440p` is 6x the game's 240 lines. The Resolution row names are 3x/4.5x/6x/9x with the pixel height in brackets (the saved keys stay 720p, 1080p, 2160p).
* **All Graphics options are live** (`ui_config_page_options_menu.cpp`): any change in the Graphics tab calls `save_config()` at once, so options added by the port need no callback of their own.
* **Section headings** (`recompui/include/recompui/config.h`, `ui_config.cpp`,
  `ui_config_page_options_menu.cpp`): `recompui::config::set_option_group(option_id, title)`
  puts a heading above that option in its tab (used by the QOL tab).
* **Vulkan is the default Graphics API** (`recompui/src/config/ui_config_tab_graphics.cpp`):
  the `api_option` default is Vulkan and the Auto entry is removed (the list is D3D12 and
  Vulkan on Windows). A saved `graphics.json` with Auto is not migrated. The row is shown
  in the Graphics tab (upstream hides it); src/game/api_restart.cpp asks to restart when it
  changes.
* **Live graphics settings** (`recompui/src/config/ui_config_tab_graphics.cpp`):
  every graphics option applies and saves as soon as it changes, so the
  Apply button is no longer needed (handoff 4.10).
* **Fixed resolutions** (same file, `recompui/src/renderer/rt64_render_context.cpp`, and
  `ultramodern/include/ultramodern/config.hpp` in N64ModernRuntime.patch): the Resolution row
  offers 720p, 1080p and 4K (RT64 manual multipliers 3x, 4.5x and 9x of the N64's 240 lines)
  before Auto, which stays last (L, 2026-10-13). Saved as "720p", "1080p", "2160p".
* **Letterbox 16:9** (same file): the Aspect Ratio row offers RT64's manual
  aspect (16:9 with bars) as "Letterbox 16:9"; the other two are labelled
  "4:3" and "Fill" (handoff 4.22).
* **Speed-Up hotkey** (`recompinput/include/recompinput/input_types.h`,
  `recompinput/src/input_types.cpp`, `recompui/src/config/ui_config_page_controls.cpp`):
  adds `SPEED_UP`, `TIPTOE` and `PHOTO_MODE` game inputs in a new hotkey group, so the speed-up, tiptoe and photo mode keys can be
  bound like any other input. The Controls tab lists hotkeys under their own
  "Hotkeys" heading, or under another heading a game picks with
  `set_game_input_section` (Speed-Up is under "Cheats"). Name, description and default (F2) are set by
  `src/game/speedup.cpp`.
* **Back buttons** (`recompinput/src/extra_buttons.cpp`, `recompinput/src/input_events.cpp`,
  `recompinput/src/input_state.cpp`): many pads (DirectInput and generic HID
  ones) report their back buttons only as raw joystick buttons that SDL's
  controller mapping leaves out, so the Controls tab never saw them. Unmapped
  raw buttons now stand in, in order, for the paddle buttons the pad doesn't
  report (Paddle 1 to 4, then Misc 1), both when binding and in play. Each
  controller's name, raw button count, back buttons and whether it has a gyro
  are logged when it is added.
* **Gyro in degrees** (`recompinput/src/input_events.cpp`): SDL's player-space
  gyro is a rate in degrees per second; it is multiplied by the time since the
  last sensor update so the deltas the game reads are degrees turned.
* **Fine Aim input** (`recompinput/include/recompinput/input_types.h`): a
  `FINE_AIM` game input, so the game's Fine aim key can be bound in the Controls
  tab.
* **Interpolation rows** (`ui_config_tab_graphics.cpp`, `recompui/config.h`): the Framerate option is
  named Interpolation, its Original choice reads Off (saved key unchanged), and it is added by
  `graphics::add_interpolation_options()`, which the port calls right after Game Frame Rate.

* **Enum drop-down** (`recompui/src/config/ui_config_option.{h,cpp}`): an enum
  option with more than 6 entries is drawn as a drop-down (the menu's Select
  element) instead of a row of tabs, which ran together. Used by the Cheats
  tab's Transformation row.
* **Long drop-down lists scroll** (`recompui/src/elements/ui_select.{h,cpp}`,
  `recompui/src/elements/ui_element.{h,cpp}`): a list taller than the window is
  cut to fit it and now scrolls, and moving through it with a pad or the arrow
  keys scrolls it to keep the picked entry in view. Before, entries past the
  window edge could be picked but not seen (Graphics > Effect debug view).
* **Split controllers** (`recompinput/include/recompinput/input_state.h`,
  `recompinput/src/input_state.cpp`, `recompinput/src/profiles.cpp`): single player mode
  sends every pad to every N64 controller. `set_split_controllers(true)` makes N64
  controller N read only the Nth pad, and keeps the keyboard on controller 1. Used by
  Bottles' Revenge (handoff 4.77) so player 2's pad drives controller 2.
* **Save State and Load State keys** (`recompinput/include/recompinput/input_types.h`): two more
  game hotkeys, `SAVE_STATE` (Insert) and `LOAD_STATE` (Home), named by `src/gameplay/save_state.cpp`.
* **Frame Rate Overlay key** (same file): `FRAME_OVERLAY` (F3), named by `src/game/frame_overlay.cpp`.
* **Debug and capture keys** (same file): `HIDE_HUD` (F1), `SCREENSHOT` (F12), `EFFECT_VIEW` (F6), `EFFECT_COMPARE` (F8), `INTERP_CHECK` (F7), `BLEND_MODE` (F5) and `WARP_AGAIN` (F9), named by `src/input/hotkeys.cpp`. The Controls tab lists the last four under a "Debug" heading.
* **Android** (`recompui/CMakeLists.txt`, `recompinput/CMakeLists.txt`): the SDL include folders are added on
  Android too (the game's CMakeLists builds SDL there).

To change it: edit the files in `lib/RecompFrontend`, then
`git -C lib/RecompFrontend diff > lib-patches/RecompFrontend.patch`.

## rt64.patch

* **Render to RAM switch** (`src/common/rt64_emulator_configuration.cpp/.h`, `src/hle/rt64_state.cpp`):
  `SetRenderToRAM` turns RT64's copy of each frame back into RDRAM on or off while the game runs
  (Graphics > Frame Read-Back, `src/display/frame_readback.cpp`, off by default). With it on, the
  display list thread renders and waits for the GPU every frame.
* **No spinning on a full queue** (`src/hle/rt64_workload_queue.cpp/.h`, `src/hle/rt64_present_queue.cpp/.h`):
  writing a new workload or present while the GPU still used that slot spun on a mutex, keeping a core
  busy whenever the GPU was behind. It now sleeps on a condition variable that the barrier advance wakes.
* **VI rate** (`src/hle/rt64_vi.cpp/.h`): `SetVIRate` replaces the fixed 60 VIs a second that
  `logicalRateFromFactors` worked the game's frame rate out from, for Game Frame Rate 120 FPS and Unlocked.
* **Camera split** (`src/common/rt64_math.cpp`, `matrixDecomposeViewProj`): Banjo-Tooie loads one
  combined view-projection matrix, which RT64 splits back into a view and a projection. The near and far
  scale was taken from row 0 alone (`vp[0][2] / -vp[0][3]`, the x of the camera's facing), so with the
  camera facing nearly along z it was a ratio of two tiny 16.16 fixed-point numbers and came out wrong
  by up to several percent for a frame or two. Every depth went with it: near things were cut by the near
  plane and far things (the sky) fell past the far plane, torn triangles and black patches for a frame
  (L's "vertex explosion", 2026-10-14). The scale now comes from the row with the largest facing
  component. `TOOIE_OLD_VP_SPLIT=1` brings the old split back; `TOOIE_VP_SPLIT_LOG=1` logs `[vp-split]`
  for any split whose product differs from the input.
* **Fake vsync for headless runs** (`src/hle/rt64_present_queue.cpp`): `TOOIE_FAKE_VSYNC=<hz>` holds each
  present to that rate, as a vsync'd monitor would.
* **Unknown microcode guard** (`src/hle/rt64_interpreter.cpp`): a graphics task whose microcode
  isn't in RT64's database left the interpreter with no command table, and the next display list
  crashed (L's 2026-10-14 10:33 dump). It now keeps the last known microcode and logs
  "[rt64] Unknown microcode (text, data)" to console.log; with none known yet, lists are skipped.
* **Texture dumps** (`src/hle/rt64_rdp_tmem.cpp`, `.h`): adds
  `RT64::SetTextureDumpDirectory(folder, callback)`, which starts RT64's own
  texture dumper (normally only in the debugger window) in that folder, or stops
  it with an empty path. Each texture dumped the first time is also handed to the
  callback with TMEM and its tile, so the game can save it as a PNG
  (`src/game/texture_sweep.cpp`).
* **Screenshots** (`src/hle/rt64_present_queue.cpp`, `.h`): adds
  `RT64::RequestScreenshot(callback)`. The next presented frame's game image is
  copied to a read-back buffer before the UI is drawn over it, converted to
  RGBA8 and handed to the callback (handoff 4.83, `src/game/screenshot.cpp`).
* **Picture filters** (`src/render/rt64_vi_renderer.cpp`, `.h`,
  `src/shaders/VideoInterfacePS.hlsl`, `src/shared/rt64_video_interface.h`,
  `src/hle/rt64_state.cpp`): adds `RT64::SetPictureFilters(...)`. The VI pass
  that draws the picture into the window also applies brightness (with a test
  pattern), a colourblind filter, N64 16-bit colour and CRT scanlines, and the
  N64 3-point texture filter can be switched to bilinear live (handoff 4.25,
  4.40, 4.41, `src/display/picture_filters.cpp`). Screenshots are taken before
  this pass, so they don't show these filters.
* **Frame statistics** (`src/hle/rt64_present_queue.cpp`, `.h`,
  `src/hle/rt64_workload_queue.cpp`): adds `RT64::TakeFrameStats()`, which
  returns the presented frames, their total and worst interval (from
  `presentProfiler`) and the GPU time per game frame (from the renderer's
  timestamps) since the last call, with each present interval for the 1% low
  and hitch count, and input latency: `RT64::NoteInputRead` gives the next
  game frame the time its controller read happened, and the first present of
  that frame is timed against it. Used by the frame rate overlay
  (`src/game/frame_overlay.cpp`).

* **SMAA** (`src/render/rt64_smaa.cpp`, `.h`, `src/shaders/SmaaPS.hlsl`,
  `src/shared/rt64_smaa.h`, `src/render/rt64_shader_library.cpp`, `.h`,
  `src/render/rt64_descriptor_sets.h`, `src/hle/rt64_present_queue.cpp`, `.h`,
  `CMakeLists.txt`): adds `RT64::SetSmaaQuality(...)`. Before the VI pass, SMAA
  1x (edges, blend weights, neighbourhood blending) runs on the game image, so
  it works with MSAA and screenshots show it. The shader and lookup textures
  are iryoku/smaa in `lib/smaa` (MIT); the top-level `CMakeLists.txt` points
  `RT64_SMAA_DIR` at it. Because this patch changes RT64's `CMakeLists.txt`,
  the patches are applied before `add_subdirectory(lib/rt64)`.
  `src/display/smaa.cpp` sets the quality.
* **FXAA** (`src/render/rt64_fxaa.cpp`, `.h`, `src/shaders/FxaaPS.hlsl`,
  `src/render/rt64_shader_library.cpp`, `.h`, `src/hle/rt64_present_queue.cpp`, `.h`,
  `CMakeLists.txt`): adds `RT64::SetFxaaMode(...)`. After SMAA, one FXAA pass
  (written for this port) smooths the game image; Extreme searches further along
  edges. `src/display/fxaa.cpp` sets the mode.
* **FSR 1** (`src/render/rt64_fsr.cpp`, `.h`, `src/shaders/FsrPS.hlsl`,
  `src/shared/rt64_fsr.h`, `src/render/rt64_shader_library.cpp`, `.h`,
  `src/hle/rt64_present_queue.cpp`, `.h`, `CMakeLists.txt`): adds
  `RT64::SetFsrMode(...)`. Just before the VI pass (after screenshots and photo
  effects), when the game renders below the window's height, EASU upscales the
  image to it and RCAS sharpens it; the VI gets a matching resolution scale.
  The shaders include AMD's `ffx_a.h` and `ffx_fsr1.h` from `lib/fsr` (MIT),
  through `RT64_FSR_DIR`, built with `-HV 2018`; EASU reads its 2x2 texels with
  point samples instead of Gather, which came out grey on lavapipe.
  `src/display/fsr.cpp` sets the mode.
* **Photo mode filters** (`src/render/rt64_photo_grade.cpp`, `.h`, `src/shaders/PhotoGradePS.hlsl`,
  `src/shared/rt64_photo_grade.h`, `src/render/rt64_shader_library.cpp`, `.h`,
  `src/hle/rt64_present_queue.cpp`, `.h`, `CMakeLists.txt`): adds `RT64::SetPhotoGrade(...)`. After SMAA
  and before the VI pass, one pass applies a look (sepia, black and white, ...), exposure, contrast,
  saturation, warmth, vignette and film grain, so screenshots show them. `src/gameplay/photo_mode.cpp`
  turns it on only while photo mode is on. `RT64::SetPhotoFrame(...)` adds the crop frame and grid, and
  `RT64::SetPhotoDepthOfField(strength, depthAddress)` adds depth of field: the present pass finds the
  game's depth buffer at that address, copies it to colour (`copyFromTarget`) and the photo pass reads it.
  `RT64::SetSharpening(strength)` adds a contrast-adaptive sharpen to the same pass, kept apart from the
  filters so it applies in and out of photo mode; with the filters off the pass runs for it alone.
* **Scene effects** (`src/render/rt64_scene_effects.cpp`, `.h`, `src/shared/rt64_scene_effects.h`,
  `src/shaders/SceneEffectsPS.hlsl`, `src/render/rt64_framebuffer_renderer.cpp`, `.h`,
  `src/render/rt64_shader_library.cpp`, `.h`, `CMakeLists.txt`): adds `RT64::SetSceneEffects(ao, radius,
  depthAddress)`. The framebuffer renderer splits its raster scenes at the first projection that isn't a
  perspective one after the 3D world, and in the framebuffer whose depth target is at `depthAddress` it
  draws a full-screen pass there (ambient occlusion, fog and toon outlines from the depth target, `RT64::SetSceneFog(...)`,
  `RT64::SetSceneOutlines(...)`; bloom from a resolve of the scene so far, `RT64::SetSceneBloom(...)`,
  `src/shaders/BloomPS.hlsl`; depth of field from the same scene copy, `RT64::SetSceneDepthOfField(...)`; eye adaptation from a 1x1 luminance measured and eased each frame, `RT64::SetSceneEyeAdaptation(...)`; rim light from the depth, `RT64::SetSceneRimLight(...)`; the underwater tint and haze, `RT64::SetSceneUnderwater(...)`; heat haze, `RT64::SetSceneHeatHaze(...)`; water reflections from a water mask the framebuffer renderer redraws (`submitWaterMask`, `RasterParams.waterMask` in RasterPS.hlsl), `RT64::SetSceneWaterReflections(...)`; bounce light, `RT64::SetSceneBounceLight(...)`; water waves on the water mask from world x and z (the view matrix's inverse in the pass constants), `RT64::SetSceneWaterWaves(...)`; F6 debug views and the F8 half-and-half compare, `RT64::SetSceneEffectsView(...)` and `RT64::SetPhotoGradeCompare(...)`),
  live texture upscaling in the texture cache (`src/shaders/TextureUpscaleCS.hlsl`, an own edge-directed 2x from the published xBR rule, upscales stored as each texture's replacement; `RT64::SetTextureUpscale(1|2|4)`),
  so the HUD drawn after it is left alone.

* **Frame stats for the frame rate overlay** (`src/hle/rt64_present_queue.cpp/.h`, `RT64::TakeFrameStats`): present
  intervals, GPU time, input latency, shader compiles, and the GPU time of each extra pass
  (`src/render/rt64_gpu_sections.h`: timestamps around the water mask, eye adaptation, bloom and effects passes and
  around SMAA, FXAA, photo filters, FSR, the output and the UI).
* **Shader list** (`src/render/rt64_raster_shader_cache.cpp/.h`, `RT64::SetShaderListPath`): every shader description
  submitted is appended to `cache/shader_list.bin`; at start the list is submitted again, so those shaders compile in
  the background before they are needed (roadmap 4.32). A list from a build whose `ShaderDescription` differs in
  size is started over.
* **Android build** (`CMakeLists.txt`, `src/hle/rt64_application_window.cpp`,
  `src/tools/file_to_c/file_to_c.cmake`): a cross build cannot run the `file_to_c` tool it builds, so
  `RT64_FILE_TO_C` is a CMake script with the same output there (the desktop builds still use the tool);
  the shader compiler (DXC) is picked by the build machine; the native file dialogs and the texture tools are
  left out; the SDL window path (`RT64_SDL_WINDOW_VULKAN`) is used on Android instead of a stub that stopped
  the build.

To change it: edit the files in `lib/rt64`, then
`git -C lib/rt64 diff --ignore-submodules > lib-patches/rt64.patch`. New files
need `git -C lib/rt64 add -N <file>` first, or the diff leaves them out.

## plume.patch

Applied in `lib/rt64/src/contrib/plume` (a submodule of rt64).

* **Texture to buffer copies**: plume's Vulkan `copyTextureRegion` only copied
  buffer to texture or texture to texture; it now also copies a texture into a
  buffer (`vkCmdCopyImageToBuffer`). Its D3D12 version no longer sets sample
  positions for a destination that is a buffer (it dereferenced a null
  texture). The screenshot read-back needs both.

* **Android** (`CMakeLists.txt`, `plume_render_interface_types.h`): the SDL Vulkan surface is used on Android
  too, so the window handle is the SDL window there, as on Linux.

To change it: edit the files in `lib/rt64/src/contrib/plume`, then
`git -C lib/rt64/src/contrib/plume diff > lib-patches/plume.patch`.
