# Upscaler test guide (DLSS, DLAA, FSR 3, FSR 4, Temporal)

Build: `main` at or after eca73f4 (the same code is on branch `claude/project-thread-iloxp4`). Windows build. None of this has run on a GPU yet, so expect fixes. Everything is Off by default; the normal picture is unchanged when the Upscaler is Off.

## Where the settings are
Graphics > **WIP** tab > **Upscaler** section:
- **Upscaler**: Off / Temporal (built-in) / FSR 3 / FSR 4 / FSR 4 Native AA / DLSS / DLAA.
- **Upscaler Quality**: Quality (about 67% of window height), Balanced (58%), Performance (50%), Ultra Performance (33%). Only used when **Resolution is Auto**; the native modes (FSR 4 Native AA, DLAA) ignore it.
- **Upscaler: HUD Outside** (on by default): keeps the HUD out of the upscaler.
- **Upscaler: HUD Full Resolution (Experimental)** (off by default): draws the HUD again at window resolution.

Set **Resolution to Auto** first, otherwise the game renders at its normal size and the upscalers only anti-alias.

## What to send me
Run the game from a console / with the console log kept (the Windows build prints to stdout). Send the lines starting with `[upscaler]`. They appear every 5 seconds per stage and say: the mode, render size, output size, whether motion is known, the jitter, how many times the history reset. A failure prints once: `[upscaler] DLSS unavailable: ...`, `[upscaler] FSR unavailable: ...`. That line is the most useful thing if a mode does nothing.
Also send a screenshot or two per mode: standing still, running, and in a menu.

## Order to test
1. **Temporal (built-in)** at Quality. Works on any card. If this is broken, the others will be too (they share the camera, jitter and motion code).
2. **FSR 3**, any card. 
3. **DLSS** and **DLAA** (RTX card).
4. **FSR 4** and **FSR 4 Native AA** (Radeon RX 7000 or 9000). On other cards it should print `FSR unavailable` and fall back to Temporal; that is correct.

## What to look for, mode by mode
- **Is it actually upscaling?** In the log, `render` should be smaller than `output` (for example 1280x960 to 1920x1440). Native modes: equal sizes.
- **Camera movement**: pan and run. The picture should be sharp, with no doubling, no trailing, no shimmering edges. If everything looks like it swims or double-images, try `TOOIE_DLSS_FLIP=x`, `y` or `xy` (environment variable, flips the jitter sign for DLSS and FSR 3/4) and tell me which one fixes it.
- **Characters and enemies moving**: Banjo and Kazooie running, enemies walking. Look for smearing or a ghost trail behind them. This is the new per-object motion code; if they smear, the velocity view will show why (below).
- **Menus, pause, cutscene cuts, level warps**: should not blur or show a ghost of the previous picture for more than a frame. The log's `history resets` goes up on cuts.
- **Water, fire, particles, grass**: these can ghost (no reactive mask yet). Note which ones.
- **HUD** (Outside on): hearts/counters/text should be steady and not ghost when they change. They are drawn at the lowered resolution, so slightly soft at Performance or lower.
- **HUD Full Resolution on**: HUD text and icons should become sharp. Check the Start menu, the pause menu, the Jinjo/Jiggy pickup screens and text boxes. If a screen shows a wrong or missing HUD (some menus draw the 3D world inside the HUD), say which screen and turn the option off.
- **Ray tracing / shader effects on**: the upscaler runs after them; check that reflections and sun shadows don't flicker.
- **Performance**: note frame rate at Quality vs Off, and the quality-level differences.
- **Switching modes live** (Off to DLSS to Temporal and back): no crash, picture recovers within a second.

## Test aids
- `TOOIE_VELOCITY_VIEW=1` (or `2` for a bigger scale): shows the motion vectors instead of the picture. Grey = still. Standing still and turning the camera should give smooth colour; a running character should show a different colour from the background. If the character is flat grey while it moves, tell me the game's frame rate setting (Original/30/60): the object motion comes from RT64's frame matching and may need 60.
- `TOOIE_DLSS_FLIP=x|y|xy`: see above.

## Known gaps (not bugs, not done)
- Reactive mask for particles, fire and water; texture sharpness boost; sharpening after the upscale.
- Arm ASR (Android) and FSR 3 on Android: not written, so not listed on Android. Snapdragon GSR is Android only and untested.
- If the DLSS or FSR download failed when building (no internet at configure time) the build prints a CMake warning and the mode falls back to Temporal.

## Licences
`nvngx_dlss.dll` is NVIDIA's, `amd_fidelityfx_loader_dx12.dll` and `amd_fidelityfx_upscaler_dx12.dll` are AMD's, both shipped beside the exe with their licence text. They are not covered by the GPL (README says so).
