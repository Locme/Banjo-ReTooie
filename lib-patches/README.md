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

To change a patch: edit the files in `lib/N64ModernRuntime`, then
`git -C lib/N64ModernRuntime diff > lib-patches/N64ModernRuntime.patch`.

## RecompFrontend.patch

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
  controller's name, raw button count and back buttons are logged when it is
  added.

* **Enum drop-down** (`recompui/src/config/ui_config_option.{h,cpp}`): an enum
  option with more than 6 entries is drawn as a drop-down (the menu's Select
  element) instead of a row of tabs, which ran together. Used by the Cheats
  tab's Transformation row.
* **Split controllers** (`recompinput/include/recompinput/input_state.h`,
  `recompinput/src/input_state.cpp`, `recompinput/src/profiles.cpp`): single player mode
  sends every pad to every N64 controller. `set_split_controllers(true)` makes N64
  controller N read only the Nth pad, and keeps the keyboard on controller 1. Used by
  Bottles' Revenge (handoff 4.77) so player 2's pad drives controller 2.
* **Save State and Load State keys** (`recompinput/include/recompinput/input_types.h`): two more
  game hotkeys, `SAVE_STATE` (Insert) and `LOAD_STATE` (Home), named by `src/gameplay/save_state.cpp`.

To change it: edit the files in `lib/RecompFrontend`, then
`git -C lib/RecompFrontend diff > lib-patches/RecompFrontend.patch`.

## rt64.patch

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
  and hitch count. Used by the frame rate overlay
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
  `src/shaders/BloomPS.hlsl`; depth of field from the same scene copy, `RT64::SetSceneDepthOfField(...)`; eye adaptation from a 1x1 luminance measured and eased each frame, `RT64::SetSceneEyeAdaptation(...)`; rim light from the depth, `RT64::SetSceneRimLight(...)`; the underwater tint and haze, `RT64::SetSceneUnderwater(...)`; F6 debug views and the F8 half-and-half compare, `RT64::SetSceneEffectsView(...)` and `RT64::SetPhotoGradeCompare(...)`),
  so the HUD drawn after it is left alone.

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

To change it: edit the files in `lib/rt64/src/contrib/plume`, then
`git -C lib/rt64/src/contrib/plume diff > lib-patches/plume.patch`.
