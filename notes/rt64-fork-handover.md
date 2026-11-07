# Handover: a shared RT64 fork for L's recomps, with a renderer plugin system

For a session setting up one fork of RT64 (github.com/rt64/rt64) that L's N64 recomps all build against, in place
of each project's own pile of RT64 patches, and then adding a plugin system to it. Written 2026-11-07 from the
Banjo Re-Tooie session; the measurements are from that session's performance sweep (`tools/perf_sweep.py`).

Read first: `AGENTS.md` in each repo, `rt64-ext/README.md` in Banjo Re-Tooie (it sorts every file in its RT64
patch), and `lib-patches/README.md` in both repos (what each patch does and why).

## Ground rules that carry over

- The fork is L's own (for example `Locme/rt64`). Never open AI-written pull requests on upstream RT64, N64Recomp
  or BanjoRecomp (AGENTS.md). Pulling upstream into the fork is fine.
- RT64 is MIT-licensed; keep its licence and notices. Anything copied in from elsewhere goes in
  `docs/THIRD_PARTY.md` of the game repo, with its licence checked first.
- Nothing from a ROM goes into the fork: no textures, models or lists of game asset hashes beyond what the game
  repos already commit.
- Each change is checked in every game that uses it before that game's submodule moves to it. Say plainly what was
  and wasn't tested.

## Where things are today

Both projects build against the same upstream commit, `6f1c2d9` ("Revert "Revert "Perform far plane clipping
manually on pixel shader..."""), as the submodule `lib/rt64`, and patch it at CMake configure time.

| | Banjo Re-Tooie | Mario Party 3 recomp |
|---|---|---|
| Repo | `D:\Projects\Banjo Tooie N64\Banjo-Tooie-N64-Recomp` (github.com/Locme/Banjo-ReTooie) | `D:\Projects\Mario Party 3\Marioparty3recomp` (github.com/Locme/Marioparty3recomp) |
| RT64 patches | one `lib-patches/rt64.patch`, about 9,300 lines over 63 RT64 files (2,800 in `src/render/rt64_framebuffer_renderer.cpp`) | 23 `lib-patches/rt64-*.patch`, about 2,400 lines, applied in an order its `CMakeLists.txt` sets (`mp3_apply_patch`) |
| Files outside RT64 | `rt64-ext/` (85 files, about 20,000 lines), pulled in by one hook line, `RT64_EXTENSION_CMAKE` / `RT64_EXTENSION_SOURCE_DIR`, that `rt64.patch` adds to RT64's `CMakeLists.txt` | `rt64-ext/` with texture seams, scene outline, scene lights |
| plume patches | `lib-patches/plume.patch` (nested in `lib/rt64/src/contrib/plume`) | `plume-mailbox.patch`, `plume-swapchain-copy-source.patch` |
| How patches apply | `apply_submodule_patch` / `apply_nested_patch` in `CMakeLists.txt`: a configure resets the checkout to the committed patch, so a patch must be regenerated before building after an edit in `lib/rt64` | `mp3_apply_patch`, with old versions in `lib-patches/old/` to reverse first |

Sizes, for scale: RT64 itself is about 50,600 lines (16,000 `hle/`, 14,200 `render/`, 4,000 shaders), plume about
19,500. Banjo's additions are already more than half of RT64's size.

## What goes where

### 1. The fork's core: shared fixes and plumbing every game gets

| What | From Banjo | From Mario Party |
|---|---|---|
| Accuracy fixes | TLUT bitset fast path in `src/common/rt64_tmem_hasher.h` (same hashes, 2026-11-07) | `alpha-cvg-select`, `tile-declared-size`, `vertex-weld`, `texrect-joins` |
| Races | | `rdram-write-lock` |
| Widescreen correctness | the widescreen and wide-scissor parts of `rt64.patch` | `wide-scissor-union`, `window-wide-scissor`, `wide-draw-rect`, `wide-rect-area`, `behind-eye-draw-rect` |
| Microcode detection | | `mp1-l3dex-data` |
| Texture seams | `rt64-ext/src/render/rt64_texture_seams.cpp` (hash grid, one pass per point: the newest) | `rt64-texture-seams.patch` + its `rt64-ext` copy (older, ported from Banjo) |
| Screenshots, capture, dumping | `RequestWindowScreenshot` (`rt64-ext/src/hle/rt64_present_queue_ext.*`), `SetTextureDumpDirectory` | `rt64-frame-capture.patch` |
| Timing and profiling | `FrameStats`, `GpuSection` GPU timers, `RecordRendererCpuTimes` (renderer CPU parts) | |
| Texture cache | | `texture-age` |
| plume | swapchain `TRANSFER_SRC` usage | `swapchain-copy-source` (the same fix), `mailbox` |
| Builds | Android parts (CMake, the window handle, `src/tools/file_to_c/file_to_c.cmake`), `RT64_EXTENSION_*` hook | `vulkan-default` |

Merge the doubles first, as they are fixed twice today: texture seams (take Banjo's version), the swapchain copy
flag, the widescreen fixes, screenshots and capture.

### 2. Shared effects, as optional modules: in the fork, off by default, switched on per game

From Banjo: SMAA, FXAA, FSR 1, Snapdragon GSR (Android), the temporal upscaler, DLSS and FSR 3/4 (Windows), the
scene effects framework (bloom, ambient occlusion, eye adaptation, light shafts), sun shadows, volumetric shadows,
screen-space and mirror reflections, texture upscaling, photo grading, Mirror Mode. From Mario Party: outlines and
point lights. These are generic in technique but tuned on one game; each needs its settings passed in by the game,
never hard-coded values or map ids. They are the first users of the extension points and then of the plugins.

### 3. Game-specific: stays in each game's repo, plugged into the fork's extension points

Banjo: water, ice, snow and sand tessellation and ground parallax keyed to its materials and textures; fur and
feathers; the jigsaw board's vertex snapping; the sky drawn in parts with the effects once per picture; texture
marks and material lists. Mario Party: the present-window compositing (`present-composite`, `present-window-fade`,
`-blend`, `-key`), unless its interface turns out general enough for the core.

The hard part of the move is sorting `rt64_framebuffer_renderer.cpp`'s 2,800 changed lines in Banjo's patch into
generic hooks (core) and Banjo code (its repo). Its comments start with "Banjo-Tooie:", which helps.

## Fork layout

- Branch `main`: upstream plus the core, as small commits by topic (one per fix or feature, with the why in the
  message). Upstream is merged in now and then; one set of conflicts for all games.
- Optional modules (group 2) live in the fork under their own folder (for example `src/ext/`), each behind a
  runtime switch, default off, and a CMake option so a build can leave one out (`RT64_WITH_RAY_TRACING=OFF` for
  Android and low-end builds).
- Per-game behaviour is a runtime setting the game passes at start-up (a profile struct or flags), never
  `#ifdef BANJO`, so one fork commit builds and runs for every game.
- Each game pins a fork commit as its `lib/rt64` submodule and moves up on its own schedule after testing. The
  game's patch files for RT64 go away; game-only code stays in the game's `rt64-ext/`, linked in through the
  extension hook as today.
- The same layout suits N64ModernRuntime (Mario Party's `librecomp-*`, `ultramodern-*` patches; Banjo's
  `get_function` cache and N64Recomp's MXCSR rounding) and RecompFrontend (both repos' menu patches). Those are
  separate forks for later; RT64 first.

## Extension points the fork needs (before plugins)

Static, compiled in: no call overhead beyond a function pointer. What Banjo's `rt64.patch` touches shows where:

- Per framebuffer, after its draws are collected (`FramebufferRenderer::addFramebuffer`): read the instance and
  call lists, add per-instance data (texture seams' `instanceSeamVector`, ground tessellation's values).
- Per draw while collecting: a callback that may flag or adjust a draw (seam pieces, snapping, material marks).
- Scene effects: after the world is drawn in a framebuffer, before the HUD (bloom, AO, shadows, reflections).
- Shader features: a way to add a feature bit and its code to the raster shaders (`RENDER_FEATURE_*`,
  `RasterPS.hlsl`, `rt64_raster_shader*.cpp`) without editing RT64's shader sources per game.
- Present: before and after the final picture (photo grading, upscalers, window screenshots, composites).
- Frame timing: GPU section timers and CPU part timers as a fork API (already built in Banjo's `rt64-ext`).
- Settings in: plain `Set*` calls, as RT64 and `rt64-ext` do now (`RT64::SetSceneSunShadows` and the rest).
- Data out: `RT64::GetSceneSunDirection` (2026-11-07) is the kind of call the game side needs.

## The renderer plugin system

Why: `.nrm` mods run on the game's side and can't add GPU passes, so effects like ray tracing can't be mods. A
plugin is a native library (a DLL on Windows, a `.so` on Linux and Android) that RT64 loads and that registers its
own passes, shaders and settings. Ray tracing is the first candidate; the group 2 effects could follow.

Interface, in outline:

- A C ABI (no C++ classes across the boundary), with a version number checked at load; a plugin built for another
  version is refused with a clear message, never loaded half-way.
- `plugin_init(host_api*)` returns the plugin's table: name, version, the hooks it uses, its settings.
- Hooks per pass, never per draw or per triangle: frame begin, scene ready (after collection), after the world,
  before present, frame end, resize, device lost.
- Scene data handed over as read-only views of RT64's own buffers (draw lists, transformed vertices, transforms,
  texture and framebuffer handles), valid only during the hook. No copies.
- GPU work through the host: the plugin records into a command list the host hands it, creates its pipelines and
  resources through plume (shared device), and the host owns ordering and barriers.
- Settings: the plugin declares options (name, type, range, default); the game's menu shows them and passes
  values back through the host. Settings apply at once (AGENTS.md).
- Shaders: compiled ahead of time with the plugin (DXIL and SPIR-V, as RT64 does), loaded through the host's
  shader cache so they share its ubershader and specialisation path.
- Lifetime: everything the plugin made is released on unload or on device loss, before the device goes (the
  static-destructor crash on quitting, fixed 2026-11-07 in Banjo's `main.cpp`, is the warning).

Performance budget (from the Banjo sweep, 2026-11-07):

- GPU: the same shaders on the same GPU, the same cost. That is nearly all of ray tracing's cost.
- Plugin missing or off: nothing is called; no cost at all.
- Calls through the interface: function pointers, a few ns each, a handful to a few dozen a frame: well under a
  microsecond against frames of 2-4 ms on L's PC.
- No inlining across the boundary: keep hooks per pass.
- The real risk is scene data: copied into a plugin's own format every frame, it would cost about as much as the
  renderer's whole draw setup (about 1 ms a frame in Terrydactyland with the Enhanced preset). Read-only views cost
  nothing. Getting that right is the main design work.
- Not speed: the ABI must keep up with RT64 updates, plugins and the port are versioned together, and a crash in a
  plugin still ends the game.

## Order of work

1. Make the fork (from `6f1c2d9`, the commit both games use), set up CI building it alone and with each game.
2. Move group 1 from Banjo's `rt64.patch` and Mario Party's patches as topic commits; the doubles first. Point both
   games at the fork with their remaining patches on top; check each game is unchanged (below).
3. Add the extension points; move the hooks Banjo's patch adds into them; Banjo's game-only code stays in its
   `rt64-ext/` through them. Repeat for Mario Party. Each game's RT64 patch should end up empty.
4. Move group 2 into optional modules behind runtime switches and CMake options.
5. Plugin system: the C ABI and loader, with one plugin. Ray tracing is the obvious first, but it is large; a small
   effect (FXAA or photo grading) proves the interface faster. Then ray tracing.
6. Merge upstream RT64 into the fork; check both games.
7. Later, from the same sweep: let the CPU record the next frame while the GPU draws (about 1 ms a frame waited
   today, `WorkloadQueue::threadRenderFrame`: `execute(); wait();`), cache static display lists as built geometry
   instead of re-reading them every frame, cache texture hashes for unchanged loads, fewer thread handoffs. All
   carry over to every game, and the cached-world idea is the biggest CPU win found.

## How to check that nothing changed

- Each game has headless tooling: Banjo's developer console (`docs/console.md`; `warp`, `look`, `screenshot`,
  `bench`, `hostprof`) and `tools/perf_sweep.py` / `tools/perf_report.py`; Mario Party's `tools/frame_check/`.
- Pictures: the same maps and camera angles before and after, diffed per pixel against the spread between two runs
  of the old build (what moves on its own, water and idle poses, sets the noise floor). Banjo did this for the sun
  shadow culling (2026-11-07): six maps, four angles each.
- Speed: the same map list swept twice before and twice after, medians compared (frame time, GPU time per pass, the
  renderer's CPU parts in the benchmark csv). A run order that differs changes results, so compare like with like.
- Exactness where it can be checked: old and new code side by side on the same inputs (Banjo did this for the TLUT
  hasher, 20,000 random textures, and the seam search, 3,000 generated scenes).
- Android: Banjo's APK builds with `cd android && ./gradlew assembleRelease` (NDK 27.2.12479018, CMake 3.22.1,
  JDK 17); nothing has run on a phone yet.

## Open questions for L

- The fork's name and where it lives (`Locme/rt64`?), and whether Mario Party moves first (fewer, smaller patches)
  or Banjo (most to gain).
- Whether group 2 effects become plugins at all, or stay compiled-in modules with switches. Plugins pay off when
  effects should ship or update apart from the game.
- Whether to fork N64ModernRuntime and RecompFrontend in the same way now or after RT64.
