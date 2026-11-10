# rt64-ext: Banjo-Tooie's RT64 additions kept outside the patch

Project rule (L, 2026-10-21): RT64 work moves out of `lib-patches/rt64.patch` into RT64's own
extension points wherever it can, with the picture unchanged (checked headless).

RT64 has two extension points of its own: the extended GBI commands (`include/rt64_extended_gbi.h`,
the `G_EX_` calls) and its public `Set*` API. Neither can add a render pass, so most of our work
can't use them as they are. What can move without changing anything RT64 does is every file the
patch only *adds*: those live here, in this repository's tree, and RT64's `CMakeLists.txt` has one
hook line at its end that includes `rt64_ext.cmake` (`RT64_EXTENSION_CMAKE`, set by the top-level
`CMakeLists.txt`). That file adds the sources to the same `rt64` target and builds the shaders with
RT64's own shader functions and options, so the binaries come out byte for byte the same.

A file here keeps its path under `src/` (`rt64-ext/src/render/rt64_fxaa.cpp` was
`lib/rt64/src/render/rt64_fxaa.cpp`), so includes and generated shader headers keep their names.
To change one, edit it here; there is no patch to regenerate for it, and a CMake configure that
resets `lib/rt64` doesn't touch it.

## Every file in rt64.patch, sorted (2026-10-21)

**Moved here**

| Files | Feature |
|---|---|
| `src/render/rt64_fxaa.cpp`, `.h`, `src/shaders/FxaaPS.hlsl` | FXAA (`RT64::SetFxaaMode`) |
| `src/render/rt64_smaa.cpp`, `.h`, `src/shared/rt64_smaa.h`, `src/shaders/SmaaPS.hlsl` | SMAA (`RT64::SetSmaaQuality`) |
| `src/render/rt64_mirror.cpp`, `.h`, `src/shaders/MirrorPS.hlsl` | Mirror Mode |
| `src/render/rt64_fsr.cpp`, `.h`, `src/shared/rt64_fsr.h`, `src/shaders/FsrPS.hlsl` | FSR 1 (`RT64::SetFsrMode`) |
| `src/render/rt64_photo_grade.cpp`, `.h`, `src/shared/rt64_photo_grade.h`, `src/shaders/PhotoGradePS.hlsl` | Photo mode filters, sharpening |
| `src/shaders/TextureUpscaleCS.hlsl` | Live texture upscaling |
| `src/render/rt64_gpu_sections.h` | GPU timings for the frame overlay (included by the framebuffer renderer and scene effects, unchanged) |
| `src/shaders/Parallax.hlsli` | Parallax (included by RasterPS and GroundTess) |
| `src/shaders/ParallaxShape.hlsli` | Parallax texture shapes (included by Parallax.hlsli and HeightBakeCS) |
| `src/shaders/HeightBakeCS.hlsl` | Parallax height maps baked as textures load (TextureCache::refreshHeights) |
| `src/shaders/GroundTess.hlsl` | Displaced ground |
| `src/shaders/WaterTess.hlsl`, `WaterTess.hlsli` | Tessellated water |
| `src/shaders/Fur.hlsli` | Banjo's fur (included by RasterPS) |
| `src/shaders/CharSurface.hlsli` | Wet, snowy and dirty Banjo and Kazooie (included by RasterPS) |
| `src/shaders/Snow.hlsli`, `SnowTess.hlsl` | Deep snow and tessellated sand (Snow.hlsli is included by RasterPS) |
| `src/hle/rt64_present_queue_ext.cpp`, `.h` (new) | The present queue's additions: present backlog (`WaitForPresentBacklog`), menu repaint (`SetIdleRepaint`, `PresentQueue::threadRepaint`), screenshots' state and read-back, frame statistics and input latency. `rt64_present_queue.cpp` keeps the calls in its present loop and reaches the shared state through `RT64::presentext` |
| `src/render/rt64_texture_seams.cpp`, `.h` (new) | Blend texture seams: the neighbour search (`FindTextureSeams`) and the `SeamPiece`/`SeamPoint` structs. `rt64_framebuffer_renderer.cpp` keeps the collection of pieces in its draw loop and the call |
| `src/render/rt64_texture_cache_ext.cpp` (new) | Texture cache additions moved whole: `TextureMap::setHeight`/`useHeight`, `TextureCache::recordUpscale`/`refreshUpscaled` (live texture upscaling). The calls stay in `rt64_texture_cache.cpp` |
| `src/render/rt64_raster_shader_cache_ext.cpp`, `.h` (new) | The shader list: `SetShaderListPath`, `GetShaderListProgress`, the binary load/save helpers and `RasterShaderCache::loadShaderList`. Shared state through `RT64::shaderlistext` |
| `src/render/rt64_scene_effects.cpp`, `.h`, `src/shared/rt64_scene_effects.h`, `src/shaders/SceneEffectsPS.hlsl`, `BloomPS.hlsl`, `SunShadowMap.hlsli`, `SunShadowMapVS.hlsl`, `SunShadowMapPS.hlsl` | Scene effects (AO, SSGI, reflections, bloom, fireflies, sun shadows) and the traced variants for Ray tracing (built with `rt64_ext_traced_shader`, the same ray query options) |
| `src/render/rt64_volumetric_shadows.cpp`, `.h`, `src/shared/rt64_volumetric_shadows.h`, `src/shaders/VolumetricShadows.hlsli`, `VolumetricShadowMapVS.hlsl`, `VolumetricShadowMapPS.hlsl`, `VolumetricShadowVolumeVS.hlsl`, `VolumetricShadowVolumePS.hlsl`, `VolumetricShadowCompositePS.hlsl` | Volumetric shadows (WIP): polygonal light volumes (Billeter, Sintorn and Assarsson, HPG 2010) for the sun and the nearest lamps, with their own maps and passes; called after the scene effects and set up by one line in the shader library |
| `src/shaders/CellHash.hlsli`, `FeatherGS.hlsl` | Cell hash (included by Snow.hlsli); Kazooie's feather cards (geometry shader) |

**Can move here next (new files, verbatim; owner noted)**

| Files | Feature | Owner / condition |
|---|---|---|
| `src/tools/file_to_c/file_to_c.cmake` | Android build | none; RT64's CMakeLists names it, so its hunk stays |

RT64's own shaders find `.hlsli` files here: with `RT64_EXTENSION_SOURCE_DIR` set (top-level
`CMakeLists.txt`), RT64's `DXC_COMMON_OPTS` also has `-I` for its own `src/shaders`, `rt64-ext/src` and
`rt64-ext/src/shaders`, and the shader rebuild dependencies cover `.hlsli` files here too (no binary changed). Shaders built with
`rt64_ext_shader` already get `-Irt64-ext/src` after RT64's own `-I`; with SMAA's that changed no binary.

**Include guards:** every header here has an `#ifndef` guard as well as `#pragma once`, and so do the RT64
`.hlsli` files these include (`FbRendererCommon`, `TextureSampler`, `Depth`). On Windows DXC reaches a file
by two spellings of its path (`shaders\Snow.hlsli` from a file beside it, `shaders/Snow.hlsli` through
`-I`), and `#pragma once` then lets it in twice (L's build, 2026-10-21). A new header here needs a guard.
Linux can't show it as is; to check, rerun each shader command from `ninja -t commands` with `/.` after
each `-I` folder.

**Checking a move:** hash every `build-cmake/src/shaders/*.spv` and `*.spirv.c` before and after
(all must match), and `llvm-dis` the old and new object of each moved `.cpp` (the build is LTO, so they
are LLVM bitcode): apart from the first two lines (file path) and the `^` summary lines, they must be
the same. After a move, delete the old untracked copies in `lib/rt64` before any `git -C lib/rt64 add -N .`,
or they go back into the patch.

**Needs an RT64 hook before it can leave the patch** (changed RT64 files that call our passes)

| Files | What they hold |
|---|---|
| `src/hle/rt64_present_queue.cpp`, `.h` | SMAA, FXAA, FSR, photo grade, mirror calls; the screenshot copy; frame stats per present; fake vsync; the repaint and vsync switches in the present loop. A post-pass hook (a list of passes run on the game image before the VI pass) would take the pass calls out. |
| `src/render/rt64_framebuffer_renderer.cpp`, `.h`, `rt64_framebuffer_renderer_call.h` | Scene effects split, water mask, snow, ground tessellation, mirror. Needs a scene-pass hook; the largest part of the patch. |
| `src/render/rt64_shader_library.cpp`, `.h`, `rt64_descriptor_sets.h` | Pipelines and descriptor sets for every new pass. Would go with a pass hook that lets a pass own its pipelines. |
| `src/render/rt64_raster_shader.cpp`, `.h`, `rt64_raster_shader_cache.cpp`, `.h` | Feather, tessellation pipelines, shader list. |
| `src/render/rt64_texture_cache.cpp`, `.h`, `rt64_texture.h` | Texture upscaling, textures kept until drawn. |
| `src/render/rt64_vi_renderer.cpp`, `.h`, `src/shaders/VideoInterfacePS.hlsl`, `src/shared/rt64_video_interface.h` | Picture filters. |
| `src/hle/rt64_workload_queue.cpp`, `.h`, `rt64_workload.cpp`, `.h`, `rt64_rsp.cpp`, `rt64_state.cpp`, `rt64_draw_call.h`, `rt64_framebuffer_manager.cpp`, `rt64_present.h` | Per-frame data the passes read, `Set*` API entry points. |

**Stays in the patch** (fixes and changes inside RT64 itself)

| Files | Why |
|---|---|
| `src/shaders/RasterPS.hlsl`, `RasterVS.hlsl`, `FbRendererCommon.hlsli`, `TextureSampler.hlsli`, `RenderParamsSpecConstants.hlsli`, `src/shared/rt64_raster_params.h`, `rt64_frame_params.h`, `rt64_render_params.h`, `rt64_gpu_tile.h` | RT64's own raster shaders and their constant layouts. Do not reorder RasterParams or FrameParams fields without telling the Displaced ground thread. |
| `CMakeLists.txt` | Android build, shader rules, the `rt64_ext.cmake` hook. |
| `include/rt64_extended_gbi.h`, `src/gbi/rt64_gbi_extended.cpp` | New `G_EX_` commands (RT64's own extension mechanism, but the command table is RT64's). |
| `src/common/rt64_math.cpp` | Camera split fix. |
| `src/hle/rt64_interpreter.cpp` | Unknown microcode guard. |
| `src/hle/rt64_rdp_tmem.cpp`, `.h`, `rt64_rdp.cpp`, `.h` | Texture dumps. |
| `src/hle/rt64_vi.cpp`, `.h`, `rt64_game_frame.cpp` | VI rate, texture slides. |
| `src/common/rt64_emulator_configuration.cpp`, `.h` | Settings behind the `Set*` calls. |
| `src/hle/rt64_application_window.cpp`, `src/render/rt64_projection_processor.cpp`, `.h`, `rt64_render_target.cpp`, `rt64_shader_common.cpp`, `.h` | Small fixes inside RT64. |
