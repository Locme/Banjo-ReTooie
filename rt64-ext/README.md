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

## Every file in rt64.patch, sorted (2026-10-21, main eb732c7)

**Moved here**

| Files | Feature |
|---|---|
| `src/render/rt64_fxaa.cpp`, `.h`, `src/shaders/FxaaPS.hlsl` | FXAA (`RT64::SetFxaaMode`) |
| `src/render/rt64_smaa.cpp`, `.h`, `src/shared/rt64_smaa.h`, `src/shaders/SmaaPS.hlsl` | SMAA (`RT64::SetSmaaQuality`) |
| `src/render/rt64_mirror.cpp`, `.h`, `src/shaders/MirrorPS.hlsl` | Mirror Mode |

**Can move here next (new files, verbatim; owner noted)**

| Files | Feature | Owner / condition |
|---|---|---|
| `src/render/rt64_fsr.cpp`, `.h`, `src/shared/rt64_fsr.h`, `src/shaders/FsrPS.hlsl` | FSR 1 | none |
| `src/render/rt64_photo_grade.cpp`, `.h`, `src/shared/rt64_photo_grade.h`, `src/shaders/PhotoGradePS.hlsl` | Photo mode filters, sharpening | none |
| `src/shaders/TextureUpscaleCS.hlsl` | Live texture upscaling | none |
| `src/render/rt64_gpu_sections.h` | GPU timings for the frame overlay | none |
| `src/shaders/Parallax.hlsli`, `GrassGS.hlsl` | Parallax, grass blades | Fences: OK to move now (2026-10-21); tell it after the push |
| `src/shaders/GroundTess.hlsl` | Displaced ground | Displaced ground: OK, same options and same `build_tessellation_shaders` line |
| `src/render/rt64_scene_effects.cpp`, `.h`, `src/shared/rt64_scene_effects.h`, `src/shaders/SceneEffectsPS.hlsl`, `BloomPS.hlsl`, `SunShadowMap.hlsli`, `SunShadowMapVS.hlsl`, `SunShadowMapPS.hlsl` | Scene effects, ray tracing | Ray tracing: OK, but message it just before and wait for its OK. Fences: not until L's fence test T506 is back |
| `src/shaders/Grass.hlsli`, `GrassBladeCommon.hlsli`, `GrassBladeVS.hlsl`, `GrassCullCS.hlsl`, `GrassHiZCS.hlsl`, `src/shared/rt64_grass_instances.h`, `Fur.hlsli`, `Snow.hlsli`, `SnowTess.hlsl`, `WaterTess.hlsl`, `WaterTess.hlsli` | Grass, fur, deep snow, water | ask Fences (grass) first |
| `src/tools/file_to_c/file_to_c.cmake` | Android build | none; RT64's CMakeLists names it, so its hunk stays |

`.hlsli` files that RT64's own `RasterPS.hlsl` / `RasterVS.hlsl` include need `rt64-ext/src/shaders` on
the shader include path first (an added `-I`; the output stays the same). Shaders built with
`rt64_ext_shader` already get `-Irt64-ext/src` after RT64's own `-I`; with SMAA's that changed no binary.

**Checking a move:** hash every `build-cmake/src/shaders/*.spv` and `*.spirv.c` before and after
(all must match), and `llvm-dis` the old and new object of each moved `.cpp` (the build is LTO, so they
are LLVM bitcode): apart from the first two lines (file path) and the `^` summary lines, they must be
the same. After a move, delete the old untracked copies in `lib/rt64` before any `git -C lib/rt64 add -N .`,
or they go back into the patch.

**Needs an RT64 hook before it can leave the patch** (changed RT64 files that call our passes)

| Files | What they hold |
|---|---|
| `src/hle/rt64_present_queue.cpp`, `.h` | SMAA, FXAA, FSR, photo grade, mirror calls; screenshots; frame stats; fake vsync. A post-pass hook (a list of passes run on the game image before the VI pass) would take the pass calls out. |
| `src/render/rt64_framebuffer_renderer.cpp`, `.h`, `rt64_framebuffer_renderer_call.h` | Scene effects split, water mask, grass, snow, ground tessellation, mirror. Needs a scene-pass hook; the largest part of the patch. |
| `src/render/rt64_shader_library.cpp`, `.h`, `rt64_descriptor_sets.h` | Pipelines and descriptor sets for every new pass. Would go with a pass hook that lets a pass own its pipelines. |
| `src/render/rt64_raster_shader.cpp`, `.h`, `rt64_raster_shader_cache.cpp`, `.h` | Grass, tessellation pipelines, shader list. |
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
