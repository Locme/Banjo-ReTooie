# Banjo-Tooie's additions to RT64 that live in this repository instead of lib-patches/rt64.patch.
# RT64's CMakeLists.txt includes this file at its end (RT64_EXTENSION_CMAKE, set by the top-level
# CMakeLists.txt), so it runs in RT64's directory scope: RT64's shader functions and DXC options
# apply here unchanged. rt64-ext/README.md says what has moved here and what is still in the patch.

set(RT64_EXT_DIR ${CMAKE_CURRENT_LIST_DIR})

# Files here and in RT64 include each other as RT64's own files do: "shared/...", "render/..." and, in
# src/render, headers beside them ("rt64_render_target.h", "rt64_mirror.h"). PUBLIC, since RT64 headers
# that the game and RecompFrontend include (rt64_present_queue.h) include these.
target_include_directories(rt64 PUBLIC
    ${RT64_EXT_DIR}/src
    ${RT64_EXT_DIR}/src/render
    ${PROJECT_SOURCE_DIR}/src/render)

target_sources(rt64 PRIVATE
    ${RT64_EXT_DIR}/src/render/rt64_smaa.cpp
    ${RT64_EXT_DIR}/src/render/rt64_fxaa.cpp
    ${RT64_EXT_DIR}/src/render/rt64_mirror.cpp
    ${RT64_EXT_DIR}/src/render/rt64_fsr.cpp
    ${RT64_EXT_DIR}/src/render/rt64_photo_grade.cpp)

# iryoku/smaa (lib/smaa, MIT): SMAA.hlsl for the shaders, AreaTex.h and SearchTex.h for rt64_smaa.cpp.
target_include_directories(rt64 PRIVATE ${RT64_SMAA_DIR})
# AMD FidelityFX FSR 1 (lib/fsr, MIT): ffx_a.h and ffx_fsr1.h.
target_include_directories(rt64 PRIVATE ${RT64_FSR_DIR})

# Calls one of RT64's shader functions (build_pixel_shader and the others), reading the shader from
# rt64-ext/ instead of lib/rt64/. The output has the same name in the build folder as before (src/shaders/<name>.hlsl.spirv.h and so on), so RT64's sources
# include it unchanged, and the shader is compiled with the same options as RT64's own, plus two include
# folders after RT64's src: rt64-ext/src (for "shared/..." headers that moved here) and RT64's src/shaders
# (for its .hlsli files, which a shader in lib/rt64 found beside itself).
set(RT64_EXT_RT64_SHADERS ${PROJECT_SOURCE_DIR}/src/shaders)
function(rt64_ext_shader FUNCTION)
    set(PROJECT_SOURCE_DIR ${RT64_EXT_DIR})
    foreach(OPTS DXC_PS_OPTS DXC_VS_OPTS DXC_CS_OPTS DXC_GS_OPTS DXC_HS_OPTS DXC_DS_OPTS)
        list(APPEND ${OPTS} "-I${RT64_EXT_DIR}/src" "-I${RT64_EXT_RT64_SHADERS}")
    endforeach()
    cmake_language(CALL ${FUNCTION} ${ARGN})
endfunction()

# SMAA 1x (RT64::SetSmaaQuality, src/display/smaa.cpp): edges and blend weights for each preset, then the blend.
foreach(SMAA_PRESET LOW MEDIUM HIGH ULTRA)
    string(SUBSTRING ${SMAA_PRESET} 0 1 SMAA_PRESET_HEAD)
    string(SUBSTRING ${SMAA_PRESET} 1 -1 SMAA_PRESET_TAIL)
    string(TOLOWER ${SMAA_PRESET_TAIL} SMAA_PRESET_TAIL)
    set(SMAA_PRESET_NAME "${SMAA_PRESET_HEAD}${SMAA_PRESET_TAIL}")
    rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SmaaPS.hlsl" "src/shaders/SmaaEdges${SMAA_PRESET_NAME}PS.hlsl" "-I${RT64_SMAA_DIR}" "-D SMAA_PASS_EDGES" "-D SMAA_PRESET_${SMAA_PRESET}")
    rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SmaaPS.hlsl" "src/shaders/SmaaWeights${SMAA_PRESET_NAME}PS.hlsl" "-I${RT64_SMAA_DIR}" "-D SMAA_PASS_WEIGHTS" "-D SMAA_PRESET_${SMAA_PRESET}")
endforeach()
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SmaaPS.hlsl" "src/shaders/SmaaBlendPS.hlsl" "-I${RT64_SMAA_DIR}" "-D SMAA_PASS_BLEND" "-D SMAA_PRESET_HIGH")

# FXAA and FXAA Extreme (RT64::SetFxaaMode, src/display/fxaa.cpp).
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/FxaaPS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/FxaaPS.hlsl" "src/shaders/FxaaExtremePS.hlsl" "-D FXAA_EXTREME")

# Mirror Mode (src/display/mirror_mode.cpp).
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/MirrorPS.hlsl")

# FSR 1 (RT64::SetFsrMode, src/display/fsr.cpp): EASU upscale and RCAS sharpen.
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/FsrPS.hlsl" "src/shaders/FsrEasuPS.hlsl" "-I${RT64_FSR_DIR}" "-D FSR_PASS_EASU" "-HV 2018")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/FsrPS.hlsl" "src/shaders/FsrRcasPS.hlsl" "-I${RT64_FSR_DIR}" "-D FSR_PASS_RCAS" "-HV 2018")

# Photo mode's filters and sharpening (RT64::SetPhotoGrade, src/gameplay/photo_mode.cpp).
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/PhotoGradePS.hlsl")

# Live texture upscaling in the texture cache (RT64::SetTextureUpscale).
rt64_ext_shader(build_compute_shader rt64 "src/shaders/TextureUpscaleCS.hlsl")

# 3D grass blades (geometry shader; D3D12 and Vulkan only, see build_geometry_shader in RT64's CMakeLists.txt).
rt64_ext_shader(build_geometry_shader rt64 "src/shaders/GrassGS.hlsl")

# Displaced ground: floors tessellated and pushed down (hull and domain shaders; D3D12 and Vulkan only).
rt64_ext_shader(build_tessellation_shaders rt64 "src/shaders/GroundTess.hlsl" "src/shaders/GroundTessHS.hlsl" "src/shaders/GroundTessDS.hlsl")

# Tessellated water (hull and domain shaders; D3D12 and Vulkan only).
rt64_ext_shader(build_tessellation_shaders rt64 "src/shaders/WaterTess.hlsl" "src/shaders/WaterTessHS.hlsl" "src/shaders/WaterTessDS.hlsl")

# 3D grass with GPU instancing: the culling passes, the depth pyramid and the blades (D3D12 and Vulkan only).
# build_grass_shader takes its options as one list, which rt64_ext_shader's ARGN would split, so this
# passes the options variable's name instead.
function(rt64_ext_grass_shader SHADERNAME OPTIONS_VAR)
    set(PROJECT_SOURCE_DIR ${RT64_EXT_DIR})
    build_grass_shader(rt64 ${SHADERNAME} "${${OPTIONS_VAR}}" ${ARGN})
endfunction()
rt64_ext_grass_shader("src/shaders/GrassBladeVS.hlsl" DXC_VS_OPTS)
rt64_ext_grass_shader("src/shaders/GrassCullCS.hlsl" DXC_CS_OPTS)
rt64_ext_grass_shader("src/shaders/GrassCullCS.hlsl" DXC_CS_OPTS "src/shaders/GrassChunkCullCS.hlsl" "-D CHUNK_PASS")
rt64_ext_grass_shader("src/shaders/GrassHiZCS.hlsl" DXC_CS_OPTS)
rt64_ext_grass_shader("src/shaders/GrassHiZCS.hlsl" DXC_CS_OPTS "src/shaders/GrassHiZMSCS.hlsl" "-D MULTISAMPLING")
rt64_ext_grass_shader("src/shaders/GrassHiZCS.hlsl" DXC_CS_OPTS "src/shaders/GrassHiZCoarseCS.hlsl" "-D COARSE_PASS")
