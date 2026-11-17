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
  messages stay at 60 a second. No longer used by the game (Game Frame Rate used 2 and 4 before
  the extra VIs below).

* **Extra VIs** (`ultramodern/src/events.cpp`, `ultramodern.hpp`): `request_vi()` wakes the VI thread
  to send a VI at once (swap in the next framebuffer, send the game's VI message) without moving the
  timed VIs, sending an AI message or calling the VI callback; `get_timed_vi_count()` counts the
  timed ones. Game Frame Rate 40 to 240 FPS and Uncapped ask for one after each swap, so the game
  can make frames faster than 60 a second with the VIs left at 60 (`src/game/game_frame_rate.cpp`).

* **Low input latency** (`ultramodern/src/events.cpp`, `ultramodern.hpp`): upstream queues each screen
  update before latching the framebuffer the game just swapped in, so a frame showed two VIs after
  the swap. `set_low_latency(true)` queues it after the latch, so it shows at the next VI, as on an
  N64 (Graphics > Low Input Latency, `src/input/low_latency.cpp`). `TOOIE_VI_LOG=1` prints each VI
  message, buffer swap, screen update and player 1 controller read, timed from the latest VI tick.

* **Suspend** (`ultramodern/src/events.cpp`, `ultramodern/src/timer.cpp`, `librecomp/src/pi.cpp`, `ultramodern.hpp`):
  `set_suspended(true)` stops the VI thread sending VIs and holds the game clock (`set_game_clock_frozen`:
  `osGetCount`, `osGetTime` and the game's timers stand still), so the game threads wait for their next VI and
  carry on where they were after `set_suspended(false)`. `flush_save_file` writes the save buffer at once (under a
  lock shared with the saving thread). For an Android app in the background (`src/main/app_state.cpp`).

To change a patch: edit the files in `lib/N64ModernRuntime`, then
`git -C lib/N64ModernRuntime diff > lib-patches/N64ModernRuntime.patch`.

* **Menu layers** (`librecomp/src/config.cpp`, `librecomp/include/librecomp/config.hpp`): display-only
  layers on top of the hidden dependencies (which each option has only one of): "advanced" options hidden in
  Simple mode, parent options whose children stay hidden until the parent is expanded
  (`set_option_parent`, `set_option_expanded`), and button options (a bool shown as a button).
  `is_config_option_hidden` takes `ignore_menu_layers` for Search.

- **`get_function` cache** (`librecomp/src/overlays.cpp`): every `jalr` and call through a function pointer looks
  the target up in `func_map`, a hash map. A 1024-entry cache per thread now answers repeat lookups; a counter that
  each change to `func_map` (an overlay loaded or unloaded, a save state's map put back) moves on marks every
  entry stale. A few percent of the game thread in the performance sweep (2026-11-07).

## RecompFrontend.patch

* **Option display order** (`recompui/include/recompui/config.h`, `ui_config.cpp`, `ui_config_page_options_menu.cpp`): `set_option_display_before(id, before_id)` shows an option above another in its tab without changing the config schema (used to show MS Anti-Aliasing under Anti-aliasing and scaling).
* **Moving the Esc menu** (`recompui/src/elements/ui_modal.h/.cpp`): `Modal::set_offset(x, y)` moves a modal's box from its
  centred place, and `get_box_position` reads where it is laid out (the console's `menupos`).
* **Settings search** (`recompui/src/config/ui_config.cpp`, `create_search_tab()`): a Search tab with a hidden row for every option of every other tab; typing in its box shows the matching rows.
* **Focus scrolls into view** (`recompui/src/elements/ui_button.cpp`): a button that gets focus scrolls itself into view, so moving down a long list with a controller keeps the selection visible.
* **Blinking portraits without layout** (`recompui/src/elements/ui_tab_set.cpp/.h`): each Esc menu tab's portrait holds
  one image per frame of its blink, laid over each other, and the blink shows one at a time by visibility. It changed
  the one image's `src` before, and RmlUi lays out the whole menu again on every `src` change: some 20 ms a draw with
  the blinks going, the menu at 25 to 55 frames a second and its scrolling and slides uneven (2026-11-17). It is now
  about 0.5 ms and 160 to 190 frames a second on the same PC.
* **Menu frame log** (`recompui/src/base/ui_state.cpp`): `TOOIE_UI_FRAME_LOG=1` prints once a second how evenly the
  menus were drawn and what a draw cost.
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
* **Button combinations** (`input_types.h`, `input_binding.{h,cpp}`,
  `input_state.cpp`, `profiles.{h,cpp}`, `ui_config_page_controls.cpp`): an
  `InputField` can carry a modifier input (`modifier_type`, `modifier_id`, saved
  in controls.json only when set) that must be held for it to count. While a
  combination's modifier is held, the same input bound alone does not count.
  The Controls tab footer's "Combo binding" button makes binding take two
  inputs, the first held while the second is pressed.
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
* **Sidebar layout** (`recompui/include/recompui/config.h`, `ui_config.cpp`, `recompui/src/elements/ui_modal.{h,cpp}`,
  `ui_tab_set.{h,cpp}`, `ui_config_page_options_menu.{h,cpp}`): `recompui::config::set_sidebar_layout(true)` draws the
  settings tabs as a vertical list on the left (the header becomes a column, the quit and close buttons at its foot) and
  each options page's description in a strip along the bottom instead of a column on the right. The modal and pages
  check it on every update, so it switches while the menu is open. The game turns it on at start (`src/game/config.cpp`); it is the only layout the port uses (L, 2026-10-16). `config::create_page_tab` adds a tab that shows some options of another tab's config (`set_option_page`; the port's Performance tab shows Graphics options), so they keep saving where they did. Back (`TabbedModal`) goes to the search box when the Search tab is open, and the modal keeps its context's autofocus element on the picked tab, which `update_focus` (`ui_state.cpp`) now prefers, so the menu reopens there with a controller. The Graphics page has no Apply footer in any layout, since it saves each change as it is made.
  In that layout a "Search settings" box at the top of the sidebar stands in for the Search tab's row (L and R still
  reach the tab, `TabSet::set_tab_listed`), and each options page shows its tab's name as a heading and a line under
  each option, with the option's name and its control on one line (`ConfigOptionElement::set_compact`,
  `ui_config_option.{h,cpp}`). The layout is styled after Banjo-Tooie's menus (`recompui/src/elements/ui_sidebar_style.h`): brown
  panels with a gold border, gold "Luckiest Guy" lettering (the game registers the font), and the picked tab filled
  gold with a Jiggy (`assets/icons/Jiggy.svg`), and switches that are on drawn gold instead of blue
  (`Toggle::set_sidebar_colors`, `ui_toggle.{h,cpp}`, also on the Search tab's rows); turning it off puts the old colours and font back.
  Navigation in that layout (`ui_document.cpp`, `ui_element.{h,cpp}`, `ui_tab_set.cpp`, `ui_modal.cpp`): the sidebar
  and the page are barriers (`Element::set_nav_barrier`), so the stick never crosses between them; reaching a tab or
  the search box opens it; A or Right (`Element::set_nav_override`) moves into the page's first option
  (`Element::focus_first_nav_element`, the search box's text field on the Search tab); L and R from inside a page
  land in the next page.
* **Android** (`recompui/CMakeLists.txt`, `recompinput/CMakeLists.txt`): the SDL include folders are added on
  Android too (the game's CMakeLists builds SDL there).

* **Banjo quit prompt** (`recompui/src/composites/ui_prompt.cpp`, `recompui.h`, `ui_state.cpp`, `ui_button.h`): the
  prompt context holds two panels, the plain one and one styled like the sidebar layout (brown, gold border, a Jiggy from `assets/icons/JiggyBadge.svg`, whose orange rim shows on brown,
  Luckiest Guy lettering, buttons that turn gold when picked); `open_choice_prompt`'s new `banjo_look` argument picks
  it, and the quit prompt is the only caller that does. `Button::get_label` lets the label's font be set.
  The Banjo panel (`BanjoPanelElement`) pops in on each open through `Element::animate` (`ui_element.{h,cpp}`, a
  wrapper over RmlUi's `Element::Animate` that takes RCSS values), takes the menu's Back (B) as Keep Playing, and shows
  hints for Accept and Back from the controller or keyboard profile last used, refreshed when that changes.
* **Esc menu slide** (`recompui/src/elements/ui_modal.{h,cpp}`, `recompui/include/recompui/config.h`, `ui_config.cpp`,
  `ui_element.h`, `ui_style.{h,cpp}`): a modal made animated (`Modal::set_animated`) slides in from the left past its
  place and back, its tabs following one after another and then the page's rows (`Modal::page_rows`: the children of
  the element under the page with the most children), and slides out to the left; Esc while it slides out brings it
  back. `config::set_slide_callback` is told each wave of rows starting in and landing (five waves, 0.095 s apart, as
  the game's Start menu rows) and the slide out starting, for the game's sounds (`src/gameplay/menu_pause.cpp`).
  `Element::get_children` and `Style::unset_opacity` are new. 2026-11-12, more of the Start menu: a page shown while
  the menu is open (another tab) cascades in too (`Modal::start_page_slide`, one RowIn/RowLand pair at most every
  0.25 s), the rows leave one after another on the slide out (`Modal::move_rows`), and the tabs stop at their place
  and swell instead of passing it. In the sidebar layout each tab can show a portrait (`config::set_tab_portrait`: the still
  picture and its blink frames, any thread, applied on the menu's update; `Tab::set_portrait`, `Tab::update_blink`
  blinks each tab every 1.5 to 4 s): the picked one is full size, the rest smaller and
  dimmer, and the newly picked tab's label and portrait pop (`Element::animate` with overshoot). Option descriptions
  print in a word at a time (`ConfigPageOptionsMenu::print_in_rml` wraps each word in a `print-in` span, faded in
  by `Element::print_in` once the queued text is set, all within `print_longest`). The tab's own sound: on a tab
  change `config::notify_tab_sound(tab_id)` goes to the game (its character's voice), falling back to the
  RowIn/RowLand pair when no callback is set; that page glides 48 dp in from the left while the settings list fades
  in (`Modal::update_page_slide`, `Modal::page_list`). `Tab::set_fade` fades a sliding tab's portrait with it, as
  RmlUi does not carry a parent's opacity onto a child that sets its own. The peek (`Modal::update_peek`): after a
  slider in the page moves (`Slider::get_peek`: dragged, pressed or changed), on pages `config::set_peek_page_callback`
  allows (the game: its graphics pages), the box fades to 2% and the backdrop away, and it holds while the pointer
  stays on the row (`recompui::get_ui_mouse_position`) or, with a controller, the focus does; leaving ends it until
  the next change. The moved slider's row grows 3% on a dark panel and keeps opacity 1 (opacity is inherited in RmlUi, not multiplied),
  and everything beside the row and beside its parents up to the page, the header's buttons and the hints under
  the box are hidden (`visibility`), since some of them set their own opacity and would stay at full strength.
  `Style::unset_visibility` and `Style::unset_background_color` are new.
* **Hand cursor reach** (`recompui/src/base/ui_state.cpp`, `hand_reach`): when nothing focusable or no scroll bar is
  under the mouse, its motion and clicks go to the nearest point within 22 pixels that has one, so the hand cursor
  (64 pixels across, its click point in its middle) picks what it covers. A drag keeps the shift its press had.
* **Texture pack pictures for the menus** (`recompui/include/recompui/renderer.h`, `rt64_render_context.cpp`):
  `renderer::read_texture_replacement(tmem, fmt, siz, line, width, height, tlut, bytes, path)` gives the file of the
  texture pack picture that replaces a texture of the game, found as RT64's TextureCache finds one: the texture's
  RT64 hash (`TMEMHasher`, with each pack's own hash version) looked up in the packs in use, the first in the mod list
  first, and read through that pack's file system (folder, zip or .rtz). Packs switched off are skipped as RT64 skips
  them (their hash version is no longer among `resolvedHashVersions`). `renderer::texture_hash` gives the hash alone,
  and `renderer::texture_packs_version()` goes up after each change of the packs in use. The game's Esc menu
  portraits use it (src/ui/menu_portraits.cpp).
* **Another config's options on a page** (`recompui/include/recompui/config.h`, `ui_config.cpp`,
  `ui_config_tab_sound.cpp`, `ui_config_page_options_menu.{h,cpp}`):
  `config::add_page_config(tab_config_id, extra_config_id, before_option_id)` shows a config's own options on another
  tab's page, just above that tab's option `before_option_id` (or after all its options). `config::create_config`
  makes a config with no tab, which loads and saves as a tab's does, and `create_sound_config` the sound config so
  (the game puts Sound on General, before Saves, and has no Sound tab). Each option still belongs to its config: `ConfigPageOptionsMenu::owner_of` routes a change, its
  description and its updates to it, and a change to a guest config is saved at once (it has no tab of its own whose
  closing saves it; Search saves it at once too). Search names the host tab for them (`get_option_tab_name`).

To change it: edit the files in `lib/RecompFrontend`, then
`git -C lib/RecompFrontend diff > lib-patches/RecompFrontend.patch`.

* **Menu layers** (`recompui/src/config/ui_config_option.*`, `ui_config.cpp`, `ui_config_page_options_menu.cpp`,
  `assets/icons/CaretUp.svg`): a row with children gets a down/up arrow that opens its children on a darker,
  indented panel; a number option with children shows an on/off switch (off is 0, on the last non-zero value)
  and, while open, its slider on a "Strength" line above its children; a button option shows a Button instead of the switch; Search rows ignore all of it.

## rt64.patch

Files this patch would only add live in `rt64-ext/` instead (its README sorts every file of the patch):
RT64's `CMakeLists.txt` includes `rt64-ext/rt64_ext.cmake` at its end, which builds them into the same
`rt64` target with RT64's own shader options. Move more there wherever a change allows (L, 2026-10-21).

* **Textures kept until drawn** (`src/render/rt64_texture_cache.cpp/.h`, `src/hle/rt64_rdp_tmem.cpp`):
  the display list parser uploads only textures whose hash it hasn't seen, and evicts old textures at
  the end of each parse, before that frame is drawn. A texture unused for a while and used again by the
  frame just parsed was evicted there, so that frame drew it blank (white talking-head boxes above 30
  FPS). The parser now marks each known texture it uses (`TextureCache::touchTexture`), and a draw of an
  older frame no longer moves a texture's last use back.
* **Render to RAM switch** (`src/common/rt64_emulator_configuration.cpp/.h`, `src/hle/rt64_state.cpp`):
  `SetRenderToRAM` turns RT64's copy of each frame back into RDRAM on or off while the game runs
  (Graphics > Frame Read-Back, `src/display/frame_readback.cpp`, off by default). With it on, the
  display list thread renders and waits for the GPU every frame.
* **Texture slides** (`src/hle/rt64_game_frame.cpp`, `src/common/rt64_emulator_configuration.cpp/.h`):
  with frame smoothing, a texture move of half the drawn width or height or more in one game frame is
  an animation stepping to its next frame on a sheet (smoke, splashes), so it snaps instead of sliding
  through the frames between. `SetTileInterpolation` turns all texture sliding off while the game runs
  (WIP > Debug > Texture slide blending, `src/debug/texture_slide.cpp`). `TOOIE_TILE_LOG=1` logs each
  texture move RT64 sees.
* **No spinning on a full queue** (`src/hle/rt64_workload_queue.cpp/.h`, `src/hle/rt64_present_queue.cpp/.h`):
  writing a new workload or present while the GPU still used that slot spun on a mutex, keeping a core
  busy whenever the GPU was behind. It now sleeps on a condition variable that the barrier advance wakes.
* **VI rate** (`src/hle/rt64_vi.cpp/.h`): `SetVIRate` replaces the fixed 60 VIs a second that
  `logicalRateFromFactors` worked the game's frame rate out from (no longer used by the game).
  `SetFixedFrameRate` gives that rate outright (40 to 240) when Game Frame Rate paces the frames itself
  with extra VIs, so Interpolation can still blend above it; 0 goes back to working it out.
  When that rate is above the screen's refresh rate (Uncapped gives 100000) the present thread turns
  vsync off (`setVsyncEnabled`, the swap chain is made again), and `WaitForPresentBacklog` (in
  `rt64_present_queue.cpp`) lets the game wait until no more than n presents are queued and not shown.
  While the port paces the frames and vsync is on, the swap chain prefers mailbox presenting
  (`setMailboxPreferred`, plume Vulkan only; other backends ignore it). A FIFO present waited for the
  vblank, so with the GPU near the screen rate the queue stayed two deep and the present thread skipped
  every other frame (L, 2026-10-22: 175 FPS showed 53 with the game at 99). `wait()` returns at once in mailbox.
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
  (`src/game/texture_sweep.cpp`), and with the address and display-list command that
  its `.rice.json` holds. The files' bytes are copied on the renderer thread and written
  by a worker thread (`rt64-ext/src/hle/rt64_texture_dump_writer.cpp`): one `fclose` there
  once held the renderer, and with it the game, for 21 s (L's sweep, 2026-11-07).
  `RT64::FlushTextureDumps()` waits for the queue; the game calls it when dumping stops,
  and the writer waits for it at exit (`atexit` and `at_quick_exit`).
* **Screenshots** (`src/hle/rt64_present_queue.cpp`, `.h`, with the state and read-back in
  `rt64-ext/src/hle/rt64_present_queue_ext.cpp`): adds
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
* **Frame statistics** (`src/hle/rt64_present_queue.cpp`, `.h`, `rt64-ext/src/hle/rt64_present_queue_ext.cpp`,
  `src/hle/rt64_workload_queue.cpp`): adds `RT64::TakeFrameStats()`, which
  returns the presented frames, their total and worst interval (from
  `presentProfiler`) and the GPU time per game frame (from the renderer's
  timestamps) since the last call, with each present interval for the 1% low
  and hitch count, and input latency: `RT64::NoteInputRead` gives the next
  game frame the time its controller read happened, and the first present of
  that frame is timed against it. Used by the frame rate overlay
  (`src/game/frame_overlay.cpp`).

* **SMAA** (`src/render/rt64_shader_library.cpp`, `.h`, `src/render/rt64_descriptor_sets.h`,
  `src/hle/rt64_present_queue.cpp`, `.h`; the pass itself, `rt64_smaa.cpp`, `.h`, `shared/rt64_smaa.h`
  and `SmaaPS.hlsl`, is in `rt64-ext/`, as is Mirror Mode's `rt64_mirror.cpp`, `.h` and `MirrorPS.hlsl`): adds `RT64::SetSmaaQuality(...)`. Before the VI pass, SMAA
  1x (edges, blend weights, neighbourhood blending) runs on the game image, so
  it works with MSAA and screenshots show it. The shader and lookup textures
  are iryoku/smaa in `lib/smaa` (MIT); the top-level `CMakeLists.txt` points
  `RT64_SMAA_DIR` at it (used by `rt64-ext/rt64_ext.cmake`). Because this patch changes RT64's
  `CMakeLists.txt`, the patches are applied before `add_subdirectory(lib/rt64)`.
  `src/display/smaa.cpp` sets the quality.
* **FXAA** (`src/render/rt64_shader_library.cpp`, `.h`, `src/hle/rt64_present_queue.cpp`, `.h`;
  the pass itself, `rt64_fxaa.cpp`, `.h` and `FxaaPS.hlsl`, is in `rt64-ext/`): adds `RT64::SetFxaaMode(...)`. After SMAA, one FXAA pass
  (written for this port) smooths the game image; Extreme searches further along
  edges. `src/display/fxaa.cpp` sets the mode.
* **FSR 1** (`src/render/rt64_shader_library.cpp`, `.h`, `src/hle/rt64_present_queue.cpp`, `.h`;
  the pass itself, `rt64_fsr.cpp`, `.h`, `shared/rt64_fsr.h` and `FsrPS.hlsl`, is in `rt64-ext/`): adds
  `RT64::SetFsrMode(...)`. Just before the VI pass (after screenshots and photo
  effects), when the game renders below the window's height, EASU upscales the
  image to it and RCAS sharpens it; the VI gets a matching resolution scale.
  The shaders include AMD's `ffx_a.h` and `ffx_fsr1.h` from `lib/fsr` (MIT),
  through `RT64_FSR_DIR`, built with `-HV 2018`; EASU reads its 2x2 texels with
  point samples instead of Gather, which came out grey on lavapipe.
  `src/display/fsr.cpp` sets the mode.
* **Photo mode filters** (`src/render/rt64_shader_library.cpp`, `.h`, `src/hle/rt64_present_queue.cpp`, `.h`;
  the pass itself, `rt64_photo_grade.cpp`, `.h`, `shared/rt64_photo_grade.h` and `PhotoGradePS.hlsl`, is in
  `rt64-ext/`): adds `RT64::SetPhotoGrade(...)`. After SMAA
  and before the VI pass, one pass applies a look (sepia, black and white, ...), exposure, contrast,
  saturation, warmth, vignette and film grain, so screenshots show them. `src/gameplay/photo_mode.cpp`
  turns it on only while photo mode is on. `RT64::SetPhotoFrame(...)` adds the crop frame and grid, and
  `RT64::SetPhotoDepthOfField(strength, depthAddress)` adds depth of field: the present pass finds the
  game's depth buffer at that address, copies it to colour (`copyFromTarget`) and the photo pass reads it.
  `RT64::SetSharpening(strength)` adds a contrast-adaptive sharpen to the same pass, kept apart from the
  filters so it applies in and out of photo mode; with the filters off the pass runs for it alone.
* **Scene effects** (in `rt64-ext/`: `src/render/rt64_scene_effects.cpp`, `.h`, `src/shared/rt64_scene_effects.h`,
  `src/shaders/SceneEffectsPS.hlsl`, `BloomPS.hlsl`, `SunShadowMap*`; in the patch: `src/render/rt64_framebuffer_renderer.cpp`, `.h`,
  `src/render/rt64_shader_library.cpp`, `.h`, `CMakeLists.txt`): adds `RT64::SetSceneEffects(ao, radius,
  depthAddress)`. The framebuffer renderer splits its raster scenes at the first projection that isn't a
  perspective one after the 3D world, and in the framebuffer whose depth target is at `depthAddress` it
  draws a full-screen pass there (ambient occlusion, fog and toon outlines from the depth target, `RT64::SetSceneFog(...)`,
  `RT64::SetSceneOutlines(...)`; bloom from a resolve of the scene so far, `RT64::SetSceneBloom(...)`,
  `src/shaders/BloomPS.hlsl`; depth of field from the same scene copy, `RT64::SetSceneDepthOfField(...)`; eye adaptation from a 1x1 luminance measured and eased each frame, `RT64::SetSceneEyeAdaptation(...)`; rim light from the depth, `RT64::SetSceneRimLight(...)`; the underwater tint and haze, `RT64::SetSceneUnderwater(...)`; heat haze, `RT64::SetSceneHeatHaze(...)`; water reflections from a water mask the framebuffer renderer redraws (`submitWaterMask`, `RasterParams.waterMask` in RasterPS.hlsl), `RT64::SetSceneWaterReflections(...)`; bounce light, `RT64::SetSceneBounceLight(...)`; the day and night cycle's tint of the 3D world, night sky and moving sun, `RT64::SetSceneTimeOfDay(...)` with `RT64::SetSceneSun(...)` (the tint is packed in `SceneEffectsCB.shadows.z`); water waves on the water mask from world x and z (the view matrix's inverse in the pass constants), `RT64::SetSceneWaterWaves(...)`; Modern water (Graphics > Water), `RT64::SetSceneModernWater(...)` (water draws must also lie mostly flat in the world, `flatInWorld`, so light beams aren't taken for water; steep level draws that pass the same test go to `fallInstances`, drawn into the mask with alpha 64/255 by `RasterParams.waterMask` 3, and SceneEffectsPS `ModernFall()` keeps the game's own animated fall, a little thicker, with soft world-space streaks, sun sparkles and mist at its foot, and boiling foam where it lands; the falls go into the mask with either water so the night's lights pass over them, `DayWorld(..., glow)`; see-through flat level decals on the icy maps (`RT64::SetSceneIcyLevel(...)`) and anything drawn with an ice texture (`RT64::SetSceneIceTextures(...)`, solid or see-through) go into the mask too (`iceInstances`, waterMask 4, alpha 16/255, drawn a hair nearer in RasterVS so solid ice passes the depth test against itself; RasterPS skips its decal depth check there and SceneEffectsPS `IceAt()` keeps ice lying on or in front of the picture's own surface) and reflect with Ice reflections (`RT64::SetSceneIceReflections(...)`, packed into `SceneEffectsCB.water.x` as twice its hundredths over Water reflections), facing the way the mask's depths say, with rays that would head back past the camera bent into the picture so ice reflects from above too, kept as the game draws them; `TOOIE_ICE_LOG=1` prints each 3D world texture combination once (`[ice-tex]`) to find ice textures; a part of the picture that writes no depth after a draw to another buffer (an HD shadow) carries on the earlier part's world (`continuedWorld`), so its water still counts as water; Graphics > Shore foam puts Modern's shore foam on the game's own water (`RT64::SetSceneShoreFoam(...)`, `SceneEffectsCB.water.y` 1.25); draws need only a fifth of their area flat to count as water, so a pool drawn with its falls stays water, and the shader sorts flat from steep per pixel; the water is lit as level, not by the game's bobbing triangles, so it doesn't look blocky; non-watery colours such as light beams are put back as drawn; a draw marked never water (`G_EX_SETSCENEEFFECTSEXCLUDE_V1` mode 4, `sceneEffectsNotWater`: the window light beams' pools of light) is never water or ice): the framebuffer renderer leaves the game's water draws out of the shown picture (`instanceWaterSkipVector`, also in an earlier part of the same picture whose water went to a later part's effects, `waterHandedOn`; a `[modern water]` console line says when it stops or starts replacing and why) and also redraws them into a water colours target (`RasterParams.waterMask` 2: their own colour and blending alpha), and SceneEffectsPS `ModernWater()` draws the new water on flat water while putting back anything else as the game drew it; the player's ripples are a wave-equation grid round them (256 cells of 3 units, BloomPS pass 7 with `BloomCB.waterSim`/`waterPush`, stepped at 120 a second into `gWaterRipples`), and the surface is raised and lowered by the waves and ripples by stepping each pixel's ray through them; from under the water the surface shows Snell's window (`ModernWaterBelow`), and caustics light what faces up below it (`RT64::SetSceneModernUnderwater(...)` gives the surface height and how far under); F6 debug views and the F8 half-and-half compare, `RT64::SetSceneEffectsView(...)` and `RT64::SetPhotoGradeCompare(...)`),
  live texture upscaling in the texture cache (`TextureUpscaleCS.hlsl` and `rt64_texture_cache_ext.cpp`, in `rt64-ext/`, an own edge-directed 2x from the published xBR rule, upscales stored as each texture's replacement; `RT64::SetTextureUpscale(1|2|4)`),
  so the HUD drawn after it is left alone.

* **Frame stats for the frame rate overlay** (`src/hle/rt64_present_queue.cpp/.h`, `RT64::TakeFrameStats`): present
  intervals, GPU time, input latency, shader compiles, and the GPU time of each extra pass
  (`rt64_gpu_sections.h`, in `rt64-ext/src/render`: timestamps around the water mask, eye adaptation, bloom, sun shadow map, indirect (AO and bounce light),
  ray tracing build and effects passes, the last as traced effects while it traces, and
  around SMAA, FXAA, photo filters, FSR, the output and the UI).
* **Shader list** (`src/render/rt64_raster_shader_cache.cpp/.h`, `RT64::SetShaderListPath`; the list code itself is in `rt64-ext/src/render/rt64_raster_shader_cache_ext.cpp`): every shader description
  submitted is appended to `cache/shader_list.bin`; at start the list is submitted again, so those shaders compile in
  the background before they are needed (roadmap 4.32). A list from a build whose `ShaderDescription` differs in
  size is started over.
* **Android build** (`CMakeLists.txt`, `src/hle/rt64_application_window.cpp`,
  `src/tools/file_to_c/file_to_c.cmake`): a cross build cannot run the `file_to_c` tool it builds, so
  `RT64_FILE_TO_C` is a CMake script with the same output there (the desktop builds still use the tool);
  the shader compiler (DXC) is picked by the build machine; the native file dialogs and the texture tools are
  left out; the SDL window path (`RT64_SDL_WINDOW_VULKAN`) is used on Android instead of a stub that stopped
  the build.
* **Ray traced reflections** (Graphics > Ray tracing; `rt64_scene_effects.cpp/.h` and `SceneEffectsPS.hlsl` in `rt64-ext/`, built with
  `-D RAY_TRACED` as `SceneEffectsRT{,2X,4X,8X}PS` (SPIR-V only, shader model 6.5), `rt64_shader_library.cpp`,
  `rt64_framebuffer_renderer.cpp`, `rt64_workload_queue.cpp`): `SetSceneRayTracing`, `NoteRayTracingSupport`
  (from the device's `rayQuery` capability; `TOOIE_RAY_TRACING_SUPPORT=0` pretends none), `RayTracingActive()`.
  While active, `BuildSceneBVH` builds one bottom level structure (a geometry for each run of the sun shadow
  casters' index ranges, over the vertex processor's world positions) under one top level instance each frame, the
  world positions are worked out for every frame (they were only for interpolated ones), reflections are at 60 at
  least, and the scene effects pass uses the traced pipeline: `TracedReflection` replaces the depth march with a ray
  query over `gSceneBVH` (t13, only in the descriptor set when the device has ray queries). `TOOIE_RT_LOG=1` logs
  `[rt]` lines. Vulkan only: D3D12 reports no ray query support. Add further traced effects (shadows) beside it,
  checking `RayTracingActive()`.

* **Losing the window surface** (`src/hle/rt64_present_queue.cpp/.h`, `src/hle/rt64_application.cpp`; the rest in
  `rt64-ext/src/hle/rt64_present_queue_ext.cpp`): `SetWindowSurfaceAvailable(false)` has the present thread release
  the swap chain and its surface between presents (`threadSyncSurface`) and waits for it; presents and repaints are
  dropped until `SetWindowSurfaceAvailable(true)`, after which the next present makes them again. The first swap
  chain waits for a surface (`waitForWindowSurface`). An Android app's window loses its surface in the background.

* **Display list command of each load** (`src/common/rt64_load_types.h`, `src/hle/rt64_state.h`, `src/hle/rt64_interpreter.cpp`,
  `src/hle/rt64_rdp.cpp`, `src/hle/rt64_rdp_tmem.cpp`): the command loop stores the RDRAM address of the command it is
  running in `State::currentCommandAddress` (one store per command; a command split across two buffers keeps the address
  where it started). Each `LoadOperation` copies it into `dlCommandAddress`, and the display list's start address
  into `dlListAddress`. The texture dump writes them as decimal `dl_command` and `dl_list` in `.rice.json` (and
  `.rice.palette.json`). They are RDRAM addresses of the command that loaded the texture and of the start of its display
  list, and are 0 for loads the game did not make through a display list. They change no pixel and no hash. The
  game-side consumer is the texture dump's per-texture context (`src/game/texture_context.cpp`).

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

* **Vulkan pipeline cache** (`plume_vulkan.cpp/.h`): `plume::SetPipelineCachePath` / `SavePipelineCache`. One `VkPipelineCache`
  (made on first pipeline, loaded from the file; the driver ignores data from another driver or GPU) is passed to every
  graphics and compute pipeline, written under another name and renamed, at device release and every 20 s while the
  shader list compiles (`src/ui/shader_progress.cpp`). The game sets `cache/vulkan_pipelines.bin` in `main.cpp`.
* **Video memory log**: `plume::GetVideoMemoryUse` reports device-local memory in use and the
  driver's budget (VK_EXT_memory_budget is enabled when the driver has it), for the `[vram]` lines
  from `src/debug/vram_log.cpp`. Failed presents and image acquires (other than out of date) are
  logged; they were silent, so a lost GPU left no trace in console.log.

* **Swap chain copies** (`plume_vulkan.cpp`): Vulkan swap chain images are made with `VK_IMAGE_USAGE_TRANSFER_SRC_BIT`
  as well, so the console's `screenshot ui` can copy the presented window (D3D12's could be copied already).

* **Ray queries and multi-mesh builds**: Vulkan enables `VK_KHR_ray_query` and its feature when the device has it
  (`capabilities.rayQuery`; D3D12 leaves it false), and `buildBottomLevelAS` gives each geometry its own build
  range (it gave one range for all, wrong with more than one mesh).

* **Indirect draws** (`drawInstancedIndirect`, `RenderBufferFlag::INDIRECT`): one instanced draw whose
  arguments a GPU buffer holds (`vkCmdDrawIndirect`; D3D12 `ExecuteIndirect` with a plain draw command
  signature made on first use, buffer state INDIRECT_ARGUMENT while read). Metal does nothing (instanced 3D
  grass, its only user, has no Metal pipeline).

* **Releasing the surface** (`plume_render_interface.h`, `plume_vulkan.cpp/.h`): `RenderSwapChain::releaseSurface`
  destroys the swap chain and the `VkSurfaceKHR` (Vulkan; nothing elsewhere), and the next `resize()` makes the surface
  again (`createSurface`, split from the constructor). A swap chain that can't be made because its surface was lost
  releases the surface too. Present, acquire, wait and the refresh rate do nothing without a swap chain.

To change it: edit the files in `lib/rt64/src/contrib/plume`, then
`git -C lib/rt64/src/contrib/plume diff > lib-patches/plume.patch`.
* **Context lifetime lock** (`recompui/include/recompui/recompui.h`, `src/core/ui_context.cpp`): `lock_context_lifetime()` and `contexts_alive()`; `destroy_all_contexts` takes the lock and marks contexts gone, so the port's overlay, notice and photo panel threads never open a context after exit tears them down.
* **Clicks after keyboard or controller use** (`recompui/src/base/ui_state.cpp`): mouse motion isn't passed to RmlUi while the controller is active or after small moves, so a mouse button press first sends RmlUi a move to the click's position; otherwise a click (on Alt+F4's quit prompt, say) could land on the old position.
* **Mouse buttons in the Keyboard controls** (`recompinput/src/input_events.cpp`, `input_state.cpp`, `input_types.cpp`): while a Keyboard section binding waits for input, a mouse button press binds that button (left, right, middle, side buttons 4 and 5, up to 8), also as half of a button combination. The click is used up by the binding, so it does not also press a menu button. Bound buttons are read with `SDL_GetMouseState` and shown with PromptFont's mouse glyphs. The menu's own inputs (Toggle Menu, Accept and so on) stay keys only, since the menu reads keys from RmlUi.
* **No red "!" box** (`recompui/src/base/ui_state.cpp`): the RmlUi debugger starts on the first F8 press (Developer Mode on) instead of at start. Once started, it shows a red "!" beacon in the top-right corner of every menu and notification whenever RmlUi logs a warning, even with the debugger closed.

## RmlUi.patch

Applied in `lib/RecompFrontend/recompui/lib/RmlUi`.

* **SVG alpha** (`Source/SVG/ElementSVG.cpp`): a comment only. The SVG pixels stay premultiplied, as upstream
  RmlUi hands them over: the recompui renderer goes through RmlUi's compatibility adapter
  (`RenderInterfaceCompatibility`), which turns textures and vertex colours to straight alpha itself. The earlier
  version of this patch (2026-10-24) converted the SVGs to straight alpha as well, so each antialiased edge pixel was
  divided by its alpha twice and drawn too bright: a light outline round every shape of the start menu
  (L, 2026-11-03). The seams it was meant to close come from the traced art's shapes meeting edge to edge, and
  `tools/seal_launcher_svg.py` closes those in the SVGs. The patch is kept so CMake resets checkouts that still carry
  the old one.
* **Clear pixels keep their neighbour's colour** (`Source/Core/RenderInterfaceCompatibility.cpp`): the adapter turns
  a generated texture's clear pixels white when it converts it to straight alpha, and the renderer's linear filter
  blended that white into the edge beside it: a white outline round the start menu's art whenever a layer moved by
  part of a pixel (L, 2026-11-03). Clear pixels now take the colour of a neighbour that isn't clear, two pixels out.
* **Even smooth scrolling** (`Source/Core/ScrollController.cpp`, `.h`): a smooth scroll (the mouse wheel, and a row
  scrolled into view as a controller moves down the Esc menu) eases out towards where it is going by the time passed,
  keeps its place between pixels, and is held to 6000 dp a second on long scrolls. RmlUi's own moved a whole number of
  pixels each frame, rounded from a speed that changed with the distance left, so the steps went 5, 6, 5, 7 pixels and
  the list juddered (2026-11-17). `TOOIE_UI_SCROLL_LOG=1` prints each step.

## N64Recomp.patch

Applied inside `lib/N64ModernRuntime/N64Recomp` (a submodule of N64ModernRuntime), to `include/recomp.h`, which every
file in `RecompiledFuncs/` includes.

- On x86-64, `get_cop1_cs` and `set_cop1_cs` (the game's `cfc1`/`ctc1` of the FPU control register, which it uses to
  change the rounding mode around float to int conversions) read and write SSE's MXCSR rounding bits directly, and
  `cvt.w.s` / `cvt.w.d` use `cvtss2si` / `cvtsd2si`, which round by MXCSR. They went through `fegetround`,
  `fesetround`, `lrintf` and `lrint`, which in MSVC's runtime also read and set the x87 unit: about a third of the game
  thread's own CPU time in the performance sweep (`tools/perf_sweep.py`, 2026-11-07). The floats were already done in
  SSE, so the results are the same; a check of every mode against the old calls agreed on every value. Other targets
  (arm64 Android) keep the `fenv` calls.
