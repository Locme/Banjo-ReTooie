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
    ${PROJECT_SOURCE_DIR}/src/render
    ${PROJECT_SOURCE_DIR}/src/hle)

target_sources(rt64 PRIVATE
    ${RT64_EXT_DIR}/src/render/rt64_smaa.cpp
    ${RT64_EXT_DIR}/src/render/rt64_fxaa.cpp
    ${RT64_EXT_DIR}/src/render/rt64_mirror.cpp
    ${RT64_EXT_DIR}/src/render/rt64_texture_marks.cpp
    ${RT64_EXT_DIR}/src/render/rt64_texture_seams.cpp
    ${RT64_EXT_DIR}/src/render/rt64_fsr.cpp
    ${RT64_EXT_DIR}/src/render/rt64_temporal_upscaler.cpp
    ${RT64_EXT_DIR}/src/render/rt64_dlss.cpp
    ${RT64_EXT_DIR}/src/render/rt64_ffx_upscaler.cpp
    ${RT64_EXT_DIR}/src/render/rt64_photo_grade.cpp
    ${RT64_EXT_DIR}/src/hle/rt64_present_queue_ext.cpp
    ${RT64_EXT_DIR}/src/render/rt64_texture_cache_ext.cpp
    ${RT64_EXT_DIR}/src/render/rt64_raster_shader_cache_ext.cpp)

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

# Camera motion for the temporal upscalers (RT64::SetUpscalerMode, src/display/upscaler.cpp).
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/UpscalerVelocityPS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/UpscalerResolvePS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/UpscalerHudPS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/UpscalerHudLayersPS.hlsl")
rt64_ext_shader(build_vertex_shader rt64 "src/shaders/ObjectVelocityVS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/ObjectVelocityPS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/ReactivePS.hlsl")
# Snapdragon GSR 1 (third-party/snapdragon-gsr, Qualcomm, BSD 3-Clause): Android builds only.
if(ANDROID)
    rt64_ext_shader(build_pixel_shader rt64 "src/shaders/GsrPS.hlsl" "-I${RT64_EXT_DIR}/../third-party/snapdragon-gsr")
endif()

# Photo mode's filters and sharpening (RT64::SetPhotoGrade, src/gameplay/photo_mode.cpp).
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/PhotoGradePS.hlsl")

# Live texture upscaling in the texture cache (RT64::SetTextureUpscale).
rt64_ext_shader(build_compute_shader rt64 "src/shaders/TextureUpscaleCS.hlsl")

# Kazooie's feathers (geometry shader; D3D12 and Vulkan only, see build_geometry_shader in RT64's CMakeLists.txt).
rt64_ext_shader(build_geometry_shader rt64 "src/shaders/FeatherGS.hlsl")

# Displaced ground: floors tessellated and pushed down (hull and domain shaders; D3D12 and Vulkan only).
rt64_ext_shader(build_tessellation_shaders rt64 "src/shaders/GroundTess.hlsl" "src/shaders/GroundTessHS.hlsl" "src/shaders/GroundTessDS.hlsl")
# (And for a material's smooth-shaded specialised shaders, which pass no flat colour.)
function(build_tessellation_shaders_with TARGETOBJ SHADERNAME HSNAME DSNAME)
    if (WIN32)
        build_shader_dxil(${TARGETOBJ} ${SHADERNAME} "${DXC_HS_OPTS}" ${HSNAME} ${ARGN})
        build_shader_dxil(${TARGETOBJ} ${SHADERNAME} "${DXC_DS_OPTS}" ${DSNAME} ${ARGN})
    endif()
    build_shader_spirv(${TARGETOBJ} ${SHADERNAME} "${DXC_HS_OPTS}" ${HSNAME} ${ARGN})
    build_shader_spirv(${TARGETOBJ} ${SHADERNAME} "${DXC_DS_OPTS}" ${DSNAME} ${ARGN})
endfunction()
rt64_ext_shader(build_tessellation_shaders_with rt64 "src/shaders/GroundTess.hlsl" "src/shaders/GroundTessSmoothHS.hlsl" "src/shaders/GroundTessSmoothDS.hlsl" "-D GROUND_SMOOTH")

# Deep snow as a tessellated surface (hull and domain shaders; D3D12 and Vulkan only).
rt64_ext_shader(build_tessellation_shaders rt64 "src/shaders/SnowTess.hlsl" "src/shaders/SnowTessHS.hlsl" "src/shaders/SnowTessDS.hlsl")

# Tessellated water (hull and domain shaders; D3D12 and Vulkan only).
rt64_ext_shader(build_tessellation_shaders rt64 "src/shaders/WaterTess.hlsl" "src/shaders/WaterTessHS.hlsl" "src/shaders/WaterTessDS.hlsl")

# Scene effects over the 3D world (ambient occlusion, SSGI, reflections, bloom, fireflies, sun shadows).
target_sources(rt64 PRIVATE ${RT64_EXT_DIR}/src/render/rt64_scene_effects.cpp)
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/BloomPS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl" "src/shaders/SceneEffects2XPS.hlsl" "-D SAMPLES_2X")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl" "src/shaders/SceneEffects4XPS.hlsl" "-D SAMPLES_4X")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl" "src/shaders/SceneEffects8XPS.hlsl" "-D SAMPLES_8X")
# The fireflies' table, worked out once a frame for the scene effects pass.
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl" "src/shaders/FireflyTablePS.hlsl" "-D FIREFLY_TABLE")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl" "src/shaders/FireflyTable2XPS.hlsl" "-D FIREFLY_TABLE" "-D SAMPLES_2X")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl" "src/shaders/FireflyTable4XPS.hlsl" "-D FIREFLY_TABLE" "-D SAMPLES_4X")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl" "src/shaders/FireflyTable8XPS.hlsl" "-D FIREFLY_TABLE" "-D SAMPLES_8X")
# The indirect pass (GTAO and SSGI at half size) for the scene effects pass.
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl" "src/shaders/SceneIndirectPS.hlsl" "-D INDIRECT_PASS")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl" "src/shaders/SceneIndirect2XPS.hlsl" "-D INDIRECT_PASS" "-D SAMPLES_2X")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl" "src/shaders/SceneIndirect4XPS.hlsl" "-D INDIRECT_PASS" "-D SAMPLES_4X")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SceneEffectsPS.hlsl" "src/shaders/SceneIndirect8XPS.hlsl" "-D INDIRECT_PASS" "-D SAMPLES_8X")
# The sun shadow map pass.
rt64_ext_shader(build_vertex_shader rt64 "src/shaders/SunShadowMapVS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/SunShadowMapPS.hlsl")

# Volumetric shadows (rt64_volumetric_shadows.cpp, WIP tab): the light's map, the lit air's mesh, the composite.
target_sources(rt64 PRIVATE ${RT64_EXT_DIR}/src/render/rt64_volumetric_shadows.cpp)
rt64_ext_shader(build_vertex_shader rt64 "src/shaders/VolumetricShadowMapVS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/VolumetricShadowMapPS.hlsl")
rt64_ext_shader(build_vertex_shader rt64 "src/shaders/VolumetricShadowVolumeVS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/VolumetricShadowVolumePS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/VolumetricShadowVolumePS.hlsl" "src/shaders/VolumetricShadowVolume2XPS.hlsl" "-D SAMPLES_2X")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/VolumetricShadowVolumePS.hlsl" "src/shaders/VolumetricShadowVolume4XPS.hlsl" "-D SAMPLES_4X")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/VolumetricShadowVolumePS.hlsl" "src/shaders/VolumetricShadowVolume8XPS.hlsl" "-D SAMPLES_8X")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/VolumetricShadowCompositePS.hlsl")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/VolumetricShadowCompositePS.hlsl" "src/shaders/VolumetricShadowComposite2XPS.hlsl" "-D SAMPLES_2X")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/VolumetricShadowCompositePS.hlsl" "src/shaders/VolumetricShadowComposite4XPS.hlsl" "-D SAMPLES_4X")
rt64_ext_shader(build_pixel_shader rt64 "src/shaders/VolumetricShadowCompositePS.hlsl" "src/shaders/VolumetricShadowComposite8XPS.hlsl" "-D SAMPLES_8X")

# The traced variant of the scene effects (Graphics > Ray tracing): a ray query over the world's triangles in
# place of the reflections' depth march. Vulkan only (SPIR-V), where the device has ray queries; shader model 6.5
# for the ray query, and SPIR-V 1.5 (Vulkan 1.2) for the ray query capability. build_shader_spirv takes its
# options as one list, so these go through a wrapper.
if (NOT APPLE)
    set(DXC_PS_RQ_OPTS "${DXC_COMMON_OPTS}" "-E" "PSMain" "-T ps_6_5" "-fspv-target-env=vulkan1.2" "-fspv-extension=SPV_KHR_ray_query" "-fspv-extension=SPV_EXT_descriptor_indexing" "-I${RT64_EXT_DIR}/src" "-I${RT64_EXT_RT64_SHADERS}")
    function(rt64_ext_traced_shader OUTNAME)
        set(PROJECT_SOURCE_DIR ${RT64_EXT_DIR})
        build_shader_spirv(rt64 "src/shaders/SceneEffectsPS.hlsl" "${DXC_PS_RQ_OPTS}" ${OUTNAME} ${ARGN})
    endfunction()
    rt64_ext_traced_shader("src/shaders/SceneEffectsRTPS.hlsl" "-D RAY_TRACED")
    rt64_ext_traced_shader("src/shaders/SceneEffectsRT2XPS.hlsl" "-D RAY_TRACED" "-D SAMPLES_2X")
    rt64_ext_traced_shader("src/shaders/SceneEffectsRT4XPS.hlsl" "-D RAY_TRACED" "-D SAMPLES_4X")
    rt64_ext_traced_shader("src/shaders/SceneEffectsRT8XPS.hlsl" "-D RAY_TRACED" "-D SAMPLES_8X")
    rt64_ext_traced_shader("src/shaders/SceneIndirectRTPS.hlsl" "-D INDIRECT_PASS" "-D RAY_TRACED")
    rt64_ext_traced_shader("src/shaders/SceneIndirectRT2XPS.hlsl" "-D INDIRECT_PASS" "-D RAY_TRACED" "-D SAMPLES_2X")
    rt64_ext_traced_shader("src/shaders/SceneIndirectRT4XPS.hlsl" "-D INDIRECT_PASS" "-D RAY_TRACED" "-D SAMPLES_4X")
    rt64_ext_traced_shader("src/shaders/SceneIndirectRT8XPS.hlsl" "-D INDIRECT_PASS" "-D RAY_TRACED" "-D SAMPLES_8X")
endif()

# NVIDIA DLSS / DLAA (rt64_dlss.cpp, Windows only): the NGX headers are in third-party/nvidia-dlss/include (NVIDIA's
# licence, see its README.md); the import library is fetched from NVIDIA's repository at a pinned commit and checked
# against its hash. If it cannot be fetched the backend is left out and the DLSS choices fall back to the built-in resolve.
if(WIN32)
    set(RT64_EXT_NGX_LIB ${CMAKE_BINARY_DIR}/nvidia-dlss/nvsdk_ngx_d.lib)
    if(NOT EXISTS ${RT64_EXT_NGX_LIB})
        file(DOWNLOAD
            https://github.com/NVIDIA/DLSS/raw/9981c6350dc58c0ce21f024fd65e31e851c31689/lib/Windows_x86_64/x64/nvsdk_ngx_d.lib
            ${RT64_EXT_NGX_LIB}
            EXPECTED_HASH SHA256=bc43df9ec032004fde681d3e3afd01cde239e03a0125b822e88674c84287f99c
            STATUS RT64_EXT_NGX_STATUS)
        list(GET RT64_EXT_NGX_STATUS 0 RT64_EXT_NGX_CODE)
        if(NOT RT64_EXT_NGX_CODE EQUAL 0)
            message(WARNING "Could not fetch nvsdk_ngx_d.lib (${RT64_EXT_NGX_STATUS}); DLSS will not be built in.")
            file(REMOVE ${RT64_EXT_NGX_LIB})
        endif()
    endif()
    if(EXISTS ${RT64_EXT_NGX_LIB})
        target_include_directories(rt64 PRIVATE ${RT64_EXT_DIR}/../third-party/nvidia-dlss/include)
        target_link_libraries(rt64 ${RT64_EXT_NGX_LIB})
        target_compile_definitions(rt64 PRIVATE TOOIE_HAS_NGX=1)
        # Vulkan: plume asks NGX for the extensions DLSS needs (rt64-ext/src/plume_dlss/render/plume_dlss.h).
        target_compile_definitions(plume PRIVATE DLSS_ENABLED=1)
        target_include_directories(plume PRIVATE ${RT64_EXT_DIR}/src/plume_dlss)
        target_include_directories(rt64 PRIVATE ${RT64_EXT_DIR}/src/plume_dlss)
    endif()
endif()

# AMD FSR 3 / FSR 4 (rt64_ffx_upscaler.cpp, Windows only): the FidelityFX API headers are in third-party/amd-fsr (AMD's
# licence, LICENSE.txt, which must go with the DLLs); the DLLs are loaded at run time, so nothing is linked.
if(WIN32)
    target_include_directories(rt64 PRIVATE ${RT64_EXT_DIR}/../third-party/amd-fsr)
    target_compile_definitions(rt64 PRIVATE TOOIE_HAS_FFX=1)
endif()
