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

To change a patch: edit the files in `lib/N64ModernRuntime`, then
`git -C lib/N64ModernRuntime diff > lib-patches/N64ModernRuntime.patch`.

## RecompFrontend.patch

* **Live graphics settings** (`recompui/src/config/ui_config_tab_graphics.cpp`):
  every graphics option applies and saves as soon as it changes, so the
  Apply button is no longer needed (handoff 4.10).
* **Letterbox 16:9** (same file): the Aspect Ratio row offers RT64's manual
  aspect (16:9 with bars) as "Letterbox 16:9"; the other two are labelled
  "4:3" and "Fill" (handoff 4.22).
* **Speed-Up hotkey** (`recompinput/include/recompinput/input_types.h`,
  `recompinput/src/input_types.cpp`, `recompui/src/config/ui_config_page_controls.cpp`):
  adds `SPEED_UP` and `TIPTOE` game inputs in a new hotkey group, so the speed-up and tiptoe keys can be
  bound like any other input. The Controls tab lists hotkeys under their own
  "Hotkeys" heading. Name, description and default (F2) are set by
  `src/game/speedup.cpp`.
* **Back buttons** (`recompinput/src/extra_buttons.cpp`, `recompinput/src/input_events.cpp`,
  `recompinput/src/input_state.cpp`): many pads (DirectInput and generic HID
  ones) report their back buttons only as raw joystick buttons that SDL's
  controller mapping leaves out, so the Controls tab never saw them. Unmapped
  raw buttons now stand in, in order, for the paddle buttons the pad doesn't
  report (Paddle 1 to 4, then Misc 1), both when binding and in play. Each
  controller's name, raw button count and back buttons are logged when it is
  added.

To change it: edit the files in `lib/RecompFrontend`, then
`git -C lib/RecompFrontend diff > lib-patches/RecompFrontend.patch`.

## rt64.patch

* **Screenshots** (`src/hle/rt64_present_queue.cpp`, `.h`): adds
  `RT64::RequestScreenshot(callback)`. The next presented frame's game image is
  copied to a read-back buffer before the UI is drawn over it, converted to
  RGBA8 and handed to the callback (handoff 4.83, `src/game/screenshot.cpp`).

To change it: edit the files in `lib/rt64`, then
`git -C lib/rt64 diff > lib-patches/rt64.patch`.

## plume.patch

Applied in `lib/rt64/src/contrib/plume` (a submodule of rt64).

* **Texture to buffer copies**: plume's Vulkan `copyTextureRegion` only copied
  buffer to texture or texture to texture; it now also copies a texture into a
  buffer (`vkCmdCopyImageToBuffer`). Its D3D12 version no longer sets sample
  positions for a destination that is a buffer (it dereferenced a null
  texture). The screenshot read-back needs both.

To change it: edit the files in `lib/rt64/src/contrib/plume`, then
`git -C lib/rt64/src/contrib/plume diff > lib-patches/plume.patch`.
