# Banjo-Tooie's additions to RT64 that live in this repository instead of lib-patches/rt64.patch.
# RT64's CMakeLists.txt includes this file at its end (RT64_EXTENSION_CMAKE, set by the top-level
# CMakeLists.txt), so it runs in RT64's directory scope: RT64's shader functions and DXC options
# apply here unchanged. rt64-ext/README.md says what has moved here and what is still in the patch.

set(RT64_EXT_DIR ${CMAKE_CURRENT_LIST_DIR})

# The files here include RT64's headers as RT64's own files do: "shared/...", "render/..." and, from
# src/render, headers beside them ("rt64_render_target.h"). PUBLIC, since RT64 headers that the game and
# RecompFrontend include (rt64_present_queue.h) include these.
target_include_directories(rt64 PUBLIC
    ${RT64_EXT_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/render)

target_sources(rt64 PRIVATE
    ${RT64_EXT_DIR}/src/render/rt64_fxaa.cpp)

# RT64's build_<kind>_shader, reading the shader from rt64-ext/ instead of lib/rt64/. The output has the
# same name in the build folder as before (src/shaders/<name>.hlsl.spirv.h and so on), so RT64's sources
# include it unchanged, and the shader is compiled with the same options as RT64's own.
function(rt64_ext_shader KIND)
    set(PROJECT_SOURCE_DIR ${RT64_EXT_DIR})
    cmake_language(CALL build_${KIND}_shader ${ARGN})
endfunction()

# FXAA and FXAA Extreme (RT64::SetFxaaMode, src/display/fxaa.cpp).
rt64_ext_shader(pixel rt64 "src/shaders/FxaaPS.hlsl")
rt64_ext_shader(pixel rt64 "src/shaders/FxaaPS.hlsl" "src/shaders/FxaaExtremePS.hlsl" "-D FXAA_EXTREME")
