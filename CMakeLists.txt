cmake_minimum_required(VERSION 3.20)

if (APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0" CACHE STRING "Minimum OS X deployment version")
endif()

project(BanjoTooieN64Recomp LANGUAGES C CXX)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_SIMULATE_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-everything /W4")
endif()

# The Windows CI ships RelWithDebInfo so crash dumps have symbols. For MSVC-style compilers CMake gives
# that config /Ob1, which only inlines functions marked inline; use full inlining (/Ob2, as Release has)
# so RT64, the runtime and the recompiled code get the same optimisation as a Release build.
if (MSVC)
    foreach(flags_var CMAKE_C_FLAGS_RELWITHDEBINFO CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        string(REPLACE "/Ob1" "/Ob2" ${flags_var} "${${flags_var}}")
    endforeach()
endif()

# Opt out of constexpr mutex constructor on windows to prevent vcredist issues
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR")
endif()

if (APPLE)
    enable_language(OBJC OBJCXX)
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    option(RECOMP_FLATPAK "Configure the build for Flatpak compatibility." OFF)
endif()

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if (WIN32)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/lib/")
endif()

set(RT64_STATIC TRUE)
set(RT64_SDL_WINDOW_VULKAN TRUE)
add_compile_definitions(
    HLSL_CPU
    __PRFCHWINTRIN_H
)

if (RECOMP_FLATPAK)
    add_compile_definitions(RECOMP_FLATPAK)
endif()

# Changes to submodules that Banjo-Tooie needs (lib-patches/README.md). They are applied before
# any submodule is added, so a patched CMakeLists.txt is the one CMake reads.
# Each is applied to the submodule checkout once; a second configure finds it applied.
function(apply_submodule_patch name)
    set(patch ${CMAKE_SOURCE_DIR}/lib-patches/${name}.patch)
    execute_process(
        COMMAND git apply --ignore-whitespace --reverse --check ${patch}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${name}
        RESULT_VARIABLE patch_present OUTPUT_QUIET ERROR_QUIET)
    if (NOT patch_present EQUAL 0)
        # Not applied as it stands now: drop whatever an older version of the
        # patch left in the checkout, then apply this one.
        execute_process(
            COMMAND git reset --hard -q
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${name}
            OUTPUT_QUIET ERROR_QUIET)
        # Files an older patch added are untracked, so the reset leaves them behind.
        execute_process(
            COMMAND git clean -fd
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${name}
            OUTPUT_QUIET ERROR_QUIET)
        execute_process(
            COMMAND git apply --ignore-whitespace ${patch}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${name}
            RESULT_VARIABLE patch_result)
        if (NOT patch_result EQUAL 0)
            message(FATAL_ERROR "Could not apply ${patch} to lib/${name}")
        endif()
    endif()
endfunction()
apply_submodule_patch(N64ModernRuntime)
apply_submodule_patch(RecompFrontend)
apply_submodule_patch(rt64)

# The same for a submodule nested inside another: lib-patches/<name>.patch is applied in <dir>.
function(apply_nested_patch name dir)
    set(patch ${CMAKE_SOURCE_DIR}/lib-patches/${name}.patch)
    execute_process(
        COMMAND git apply --ignore-whitespace --reverse --check ${patch}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/${dir}
        RESULT_VARIABLE patch_present OUTPUT_QUIET ERROR_QUIET)
    if (NOT patch_present EQUAL 0)
        execute_process(
            COMMAND git reset --hard -q
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/${dir}
            OUTPUT_QUIET ERROR_QUIET)
        # Files an older patch added are untracked, so the reset leaves them behind.
        execute_process(
            COMMAND git clean -fd
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/${dir}
            OUTPUT_QUIET ERROR_QUIET)
        execute_process(
            COMMAND git apply --ignore-whitespace ${patch}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/${dir}
            RESULT_VARIABLE patch_result)
        if (NOT patch_result EQUAL 0)
            message(FATAL_ERROR "Could not apply ${patch} to ${dir}")
        endif()
    endif()
endfunction()
apply_nested_patch(plume lib/rt64/src/contrib/plume)

# iryoku/smaa, for the SMAA passes rt64.patch adds.
set(RT64_SMAA_DIR ${CMAKE_SOURCE_DIR}/lib/smaa)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/rt64 ${CMAKE_BINARY_DIR}/rt64)

set(BUILD_SHARED_LIBS OFF)


add_subdirectory(${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime)

target_include_directories(rt64 PRIVATE ${CMAKE_BINARY_DIR}/rt64/src)

# RecompiledFuncs - Library containing the primary recompiler output.
# RECOMP_FUNCS_DIR points a call-profiling build at a trace-mode copy of the
# generated code (tools/trace_build.sh); normal builds use RecompiledFuncs/.
set(RECOMP_FUNCS_DIR ${CMAKE_SOURCE_DIR}/RecompiledFuncs CACHE PATH "Generated recompiled code")
add_library(RecompiledFuncs STATIC)

target_compile_options(RecompiledFuncs PRIVATE
    # -Wno-unused-but-set-variable
    -fno-strict-aliasing
    -Wno-unused-variable
    -Wno-implicit-function-declaration
    -falign-functions=16
)

target_include_directories(RecompiledFuncs PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${RECOMP_FUNCS_DIR}
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/ultramodern/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/librecomp/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/N64Recomp/include
)

file(GLOB FUNC_C_SOURCES ${RECOMP_FUNCS_DIR}/*.c)
file(GLOB FUNC_CXX_SOURCES ${RECOMP_FUNCS_DIR}/*.cpp)

target_sources(RecompiledFuncs PRIVATE ${FUNC_C_SOURCES} ${FUNC_CXX_SOURCES})

# Main executable
add_executable(BanjoTooieN64Recomp)

set (SOURCES
    ${CMAKE_SOURCE_DIR}/src/main/main.cpp
    ${CMAKE_SOURCE_DIR}/src/main/register_overlays.cpp

    ${CMAKE_SOURCE_DIR}/src/debug/dl_dump.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/pad_script.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/trace.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/warp.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/distance_probe.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/watchdog.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/session_log.cpp
    ${CMAKE_SOURCE_DIR}/src/game/app_data.cpp
    ${CMAKE_SOURCE_DIR}/src/game/boot.cpp
    ${CMAKE_SOURCE_DIR}/src/game/cheats.cpp
    ${CMAKE_SOURCE_DIR}/src/game/cic.cpp
    ${CMAKE_SOURCE_DIR}/src/game/config.cpp
    ${CMAKE_SOURCE_DIR}/src/game/crash_handler.cpp
    ${CMAKE_SOURCE_DIR}/src/game/debug_watch.cpp
    ${CMAKE_SOURCE_DIR}/src/game/discord.cpp
    ${CMAKE_SOURCE_DIR}/src/game/speedup.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/player_cheats.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/transform_picker.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/music_player.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/photo_mode.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/classic_sounds.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/progress_cheats.cpp
    ${CMAKE_SOURCE_DIR}/src/game/game_init.cpp
    ${CMAKE_SOURCE_DIR}/src/game/overlays.cpp
    ${CMAKE_SOURCE_DIR}/src/game/preempt.cpp
    ${CMAKE_SOURCE_DIR}/src/game/quick_start.cpp
    ${CMAKE_SOURCE_DIR}/src/game/mod_zips.cpp
    ${CMAKE_SOURCE_DIR}/src/game/timer_save.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/dialogue_speed.cpp
    ${CMAKE_SOURCE_DIR}/src/input/tiptoe.cpp
    ${CMAKE_SOURCE_DIR}/src/input/control_scheme.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/talon_trot.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/canary_mary.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/fine_aim.cpp
    ${CMAKE_SOURCE_DIR}/src/display/picture_filters.cpp
    ${CMAKE_SOURCE_DIR}/src/display/smaa.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/fast_transitions.cpp
    ${CMAKE_SOURCE_DIR}/src/display/draw_distance.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/free_camera.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/high_detail_models.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/field_of_view.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/cutscene_skip.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/honeycomb_glitter.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/jiggy_dance.cpp
    ${CMAKE_SOURCE_DIR}/src/game/recomp_api.cpp
    ${CMAKE_SOURCE_DIR}/src/game/hud_edges.cpp
    ${CMAKE_SOURCE_DIR}/src/game/model_tagging.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/interp_check.cpp
    ${CMAKE_SOURCE_DIR}/src/game/widescreen.cpp
    ${CMAKE_SOURCE_DIR}/src/game/wide_transitions.cpp
    ${CMAKE_SOURCE_DIR}/src/game/save_backup.cpp
    ${CMAKE_SOURCE_DIR}/src/game/screenshot.cpp
    ${CMAKE_SOURCE_DIR}/src/game/level_warp.cpp
    ${CMAKE_SOURCE_DIR}/src/game/hide_hud.cpp
    ${CMAKE_SOURCE_DIR}/src/game/frame_overlay.cpp
    ${CMAKE_SOURCE_DIR}/src/game/game_frame_rate.cpp
    ${CMAKE_SOURCE_DIR}/src/ui/toast.cpp

    ${CMAKE_SOURCE_DIR}/rsp/n_aspMain.cpp
)

target_include_directories(BanjoTooieN64Recomp PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${RECOMP_FUNCS_DIR}
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/N64Recomp/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/thirdparty/sse2neon
    ${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib
    ${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib/hlslpp/include
    ${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib/dxc/inc
    ${CMAKE_SOURCE_DIR}/lib/rt64/src
    ${CMAKE_SOURCE_DIR}/lib/rt64/src/rhi
    ${CMAKE_SOURCE_DIR}/lib/rt64/src/render
    ${CMAKE_SOURCE_DIR}/lib/RecompFrontend/recompinput/include
    ${CMAKE_SOURCE_DIR}/lib/RecompFrontend/recompui/include
    ${CMAKE_SOURCE_DIR}/lib/RecompFrontend/recompui/src
    ${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib/nativefiledialog-extended/src/include
    ${CMAKE_SOURCE_DIR}/lib/RecompFrontend/lib/SlotMap
    ${CMAKE_CURRENT_BINARY_DIR}
)

# Generate icon_bytes.c from the app icon PNG.
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/icon_bytes.c ${CMAKE_CURRENT_BINARY_DIR}/icon_bytes.h
    COMMAND file_to_c ${CMAKE_SOURCE_DIR}/icons/app.png icon_bytes ${CMAKE_CURRENT_BINARY_DIR}/icon_bytes.c ${CMAKE_CURRENT_BINARY_DIR}/icon_bytes.h
    DEPENDS ${CMAKE_SOURCE_DIR}/icons/app.png
)

target_sources(BanjoTooieN64Recomp PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/icon_bytes.c)

if(CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    target_compile_options(BanjoTooieN64Recomp PRIVATE
        -march=nehalem
        -fno-strict-aliasing
        -fms-extensions
    )
else()
    target_compile_options(BanjoTooieN64Recomp PRIVATE
        -fno-strict-aliasing
        -fms-extensions
    )
endif()

if (MSVC)
    # Disable identical code folding, since this breaks mod function patching as multiple functions can get merged into one.
    target_link_options(BanjoTooieN64Recomp PRIVATE /OPT:NOICF)
endif()

if (WIN32)
    include(FetchContent)

    if (DEFINED ENV{SDL2_COMPAT_VERSION})
        set(SDL2_COMPAT_VERSION $ENV{SDL2_COMPAT_VERSION})
    else()
        set(SDL2_COMPAT_VERSION "2.32.74")
    endif()

    # Fetch sdl2-compat on windows: the SDL2 API running on SDL3, whose controller
    # drivers report back buttons on more pads (8BitDo, Flydigi, newer Xbox and
    # PlayStation pads). Its package carries both SDL2.dll and SDL3.dll.
    FetchContent_Declare(
        sdl2
        URL https://github.com/libsdl-org/sdl2-compat/releases/download/release-${SDL2_COMPAT_VERSION}/sdl2-compat-devel-${SDL2_COMPAT_VERSION}-VC.zip
    )
    FetchContent_MakeAvailable(sdl2)
    target_include_directories(BanjoTooieN64Recomp PRIVATE
        ${sdl2_SOURCE_DIR}/include
    )
    target_link_directories(BanjoTooieN64Recomp PRIVATE
        ${sdl2_SOURCE_DIR}/lib/x64
    )

    # Copy SDL and dxc DLLs to output folder as post build step
    add_custom_command(TARGET BanjoTooieN64Recomp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${sdl2_SOURCE_DIR}/lib/x64/SDL2.dll"
            "${sdl2_SOURCE_DIR}/lib/x64/SDL3.dll"
            "${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxil.dll"
            "${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxcompiler.dll"
            $<TARGET_FILE_DIR:BanjoTooieN64Recomp>)

    set_target_properties(
        BanjoTooieN64Recomp
        PROPERTIES
            LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE"
            LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
            LINK_FLAGS_RELWITHDEBINFO  "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
            LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
    )

    target_sources(BanjoTooieN64Recomp PRIVATE ${CMAKE_SOURCE_DIR}/icons/app.rc)
    target_link_libraries(BanjoTooieN64Recomp PRIVATE SDL2 Winmm.lib Dbghelp.lib)
endif()

if (APPLE)
    find_package(SDL2 REQUIRED)
    target_include_directories(BanjoTooieN64Recomp PRIVATE ${SDL2_INCLUDE_DIRS})

    set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
    set(THREADS_PREFER_PTHREAD_FLAG TRUE)
    find_package(Threads REQUIRED)

    target_link_libraries(BanjoTooieN64Recomp PRIVATE ${CMAKE_DL_LIBS} Threads::Threads SDL2::SDL2)

endif()

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_package(SDL2 REQUIRED)

    add_compile_definitions("PLUME_SDL_VULKAN_ENABLED")
    add_compile_definitions("RT64_SDL_WINDOW_VULKAN")

    message(STATUS "SDL2_FOUND = ${SDL2_FOUND}")
    message(STATUS "SDL2_INCLUDE_DIRS = ${SDL2_INCLUDE_DIRS}")

    target_include_directories(BanjoTooieN64Recomp PRIVATE ${SDL2_INCLUDE_DIRS})

    find_package(Freetype REQUIRED)

    message(STATUS "FREETYPE_FOUND = ${FREETYPE_FOUND}")
    message(STATUS "FREETYPE_INCLUDE_DIRS = ${FREETYPE_INCLUDE_DIRS}")
    message(STATUS "FREETYPE_LIBRARIES = ${FREETYPE_LIBRARIES}")

    include_directories(${FREETYPE_LIBRARIES})
    target_link_libraries(BanjoTooieN64Recomp PRIVATE ${FREETYPE_LIBRARIES} SDL2::SDL2)

    set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
    set(THREADS_PREFER_PTHREAD_FLAG TRUE)
    find_package(Threads REQUIRED)

    target_link_libraries(BanjoTooieN64Recomp PRIVATE "-latomic -static-libstdc++" ${CMAKE_DL_LIBS} Threads::Threads)
endif()

# TODO fix the rt64 CMake script so that this doesn't need to be duplicated here
# For DXC
set (DXC_COMMON_OPTS "-I${PROJECT_SOURCE_DIR}/src")
set (DXC_DXIL_OPTS "-Wno-ignored-attributes")
set (DXC_SPV_OPTS "-spirv" "-fspv-target-env=vulkan1.0" "-fvk-use-dx-layout")
set (DXC_PS_OPTS "${DXC_COMMON_OPTS}" "-E" "PSMain" "-T ps_6_0" "-D DYNAMIC_RENDER_PARAMS")
set (DXC_VS_OPTS "${DXC_COMMON_OPTS}" "-E" "VSMain" "-T vs_6_0" "-D DYNAMIC_RENDER_PARAMS" "-fvk-invert-y")
set (DXC_CS_OPTS "${DXC_COMMON_OPTS}" "-E" "CSMain" "-T cs_6_0")
set (DXC_GS_OPTS "${DXC_COMMON_OPTS}" "-E" "GSMain" "-T gs_6_0")
set (DXC_RT_OPTS "${DXC_COMMON_OPTS}" "-D" "RT_SHADER" "-T" "lib_6_3" "-fspv-target-env=vulkan1.1spirv1.4" "-fspv-extension=SPV_KHR_ray_tracing" "-fspv-extension=SPV_EXT_descriptor_indexing")

if (${WIN32})
    set (DXC "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxc.exe")
    add_compile_definitions(NOMINMAX)
else()
    if (APPLE)
        # Apple's binary is universal, so it'll work on both x86_64 and arm64
        set (DXC "DYLD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/lib/arm64" "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/arm64/dxc-macos")
        if(CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
            set(SPIRVCROSS "DYLD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/spirv-cross/lib/x64" "${PROJECT_SOURCE_DIR}/lib/rt64//src/contrib/spirv-cross/bin/x64/spirv-cross")
        else()
            set(SPIRVCROSS "DYLD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/spirv-cross/lib/arm64" "${PROJECT_SOURCE_DIR}/lib/rt64//src/contrib/spirv-cross/bin/x64/spirv-cross")
        endif()
    else()
        if(CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
            set (DXC "LD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/lib/x64" "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxc-linux")
        else()
            set (DXC "LD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/lib/arm64" "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/arm64/dxc-linux")
        endif()
    endif()
endif()

set(RECOMP_FRONTEND_N64MODERNRUNTIME_PATH ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime)
set(RECOMP_FRONTEND_RT64_PATH ${CMAKE_SOURCE_DIR}/lib/rt64)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/RecompFrontend)

target_link_libraries(BanjoTooieN64Recomp PRIVATE
    RecompiledFuncs
    recompui
    recompinput
    librecomp
    ultramodern
    rt64
    nfd
)

# Embed all .nrm files in the "mods" directory
file(GLOB NRM_FILES "${CMAKE_SOURCE_DIR}/mods/*.nrm")

set(GENERATED_NRM_SOURCES "")

foreach(NRM_FILE ${NRM_FILES})
    get_filename_component(NRM_NAME ${NRM_FILE} NAME_WE)
    set(OUT_C "${CMAKE_CURRENT_BINARY_DIR}/mods/${NRM_NAME}.c")
    set(OUT_H "${CMAKE_CURRENT_BINARY_DIR}/mods/${NRM_NAME}.h")

    add_custom_command(
        OUTPUT ${OUT_C} ${OUT_H}
        COMMAND file_to_c ${NRM_FILE} ${NRM_NAME} ${OUT_C} ${OUT_H}
        DEPENDS ${NRM_FILE}
    )

    list(APPEND GENERATED_NRM_SOURCES ${OUT_C})
endforeach()

target_sources(BanjoTooieN64Recomp PRIVATE ${GENERATED_NRM_SOURCES})

target_sources(BanjoTooieN64Recomp PRIVATE ${SOURCES})

# Release builds stamp their version from the environment (set by CI).
if (DEFINED ENV{TOOIE_VERSION})
    target_compile_definitions(BanjoTooieN64Recomp PRIVATE "TOOIE_VERSION=\"$ENV{TOOIE_VERSION}\"")
endif()

# Every build records the commit it was built from (build_info.h), for the logs.
add_custom_target(tooie_build_info
    COMMAND ${CMAKE_COMMAND} -DSOURCE_DIR=${CMAKE_SOURCE_DIR} -DOUT=${CMAKE_BINARY_DIR}/build_info/build_info.h
        -P ${CMAKE_SOURCE_DIR}/cmake/build_info.cmake
    BYPRODUCTS ${CMAKE_BINARY_DIR}/build_info/build_info.h
    VERBATIM)
add_dependencies(BanjoTooieN64Recomp tooie_build_info)
target_include_directories(BanjoTooieN64Recomp PRIVATE ${CMAKE_BINARY_DIR}/build_info)

set_property(TARGET BanjoTooieN64Recomp PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
