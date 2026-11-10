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

# Whole-program speed-ups for optimised builds (L, 2026-10-14: slower builds are fine for a faster game).
# - ThinLTO lets the compiler inline and optimise across files and libraries (RT64, the runtime, the game).
#   Recompiled game functions stay separate, as RECOMP_FUNC marks them weak and noinline, so mods can
#   still patch them.
# - Every library is built for the chosen CPU level (TOOIE_CPU), not only the exe.
# Turn LTO off with -DTOOIE_LTO=OFF for quicker builds while debugging.
option(TOOIE_LTO "Build optimised configs with link-time optimisation (ThinLTO)" ON)

# Two Windows builds (L, 2026-10-14):
#   compatible: any 64-bit PC from 2008 and up (Intel Nehalem / AMD Bulldozer level, SSE4.2)
#   modern:     optimised for newer CPUs, 2013 and up (Intel Haswell / AMD Excavator level, AVX2).
#               It will not start on older CPUs.
set(TOOIE_CPU "compatible" CACHE STRING "CPU level: compatible (2008 and up) or modern (2013 and up, AVX2)")
set_property(CACHE TOOIE_CPU PROPERTY STRINGS compatible modern)
if (NOT TOOIE_CPU MATCHES "^(compatible|modern)$")
    message(FATAL_ERROR "TOOIE_CPU must be compatible or modern, not '${TOOIE_CPU}'")
endif()
if (CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    if (TOOIE_CPU STREQUAL "modern")
        set(tooie_march "-march=haswell")
    else()
        set(tooie_march "-march=nehalem")
    endif()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${tooie_march}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${tooie_march}")
    message(STATUS "CPU level: ${TOOIE_CPU} (${tooie_march})")
endif()
if (TOOIE_LTO AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if (NOT MSVC)
        # The default GNU linker cannot link LLVM bitcode; lld can.
        find_program(TOOIE_LLD NAMES ld.lld lld)
        if (TOOIE_LLD)
            foreach(link_var CMAKE_EXE_LINKER_FLAGS CMAKE_SHARED_LINKER_FLAGS CMAKE_MODULE_LINKER_FLAGS)
                set(${link_var} "${${link_var}} -fuse-ld=lld")
            endforeach()
        endif()
    endif()
    include(CheckIPOSupported)
    check_ipo_supported(RESULT tooie_ipo_ok OUTPUT tooie_ipo_error LANGUAGES C CXX)
    if (tooie_ipo_ok)
        set(CMAKE_POLICY_DEFAULT_CMP0069 NEW)
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO ON)
        message(STATUS "Link-time optimisation: on for Release and RelWithDebInfo")
    else()
        message(STATUS "Link-time optimisation: not supported here, building without it (${tooie_ipo_error})")
    endif()
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
# RmlUi (inside RecompFrontend): a note that SVG textures stay premultiplied (lib-patches/README.md).
apply_nested_patch(RmlUi lib/RecompFrontend/recompui/lib/RmlUi)
# N64Recomp (inside N64ModernRuntime): the FPU rounding mode through SSE's MXCSR on x86-64 (lib-patches/README.md).
apply_nested_patch(N64Recomp lib/N64ModernRuntime/N64Recomp)
# re-spirv (RT64's SPIR-V specialiser): its sort copes with loops, which the raster shaders now have.
apply_nested_patch(re-spirv lib/rt64/src/contrib/re-spirv)

# Android (android/ is the Gradle project that drives this build): SDL, FreeType and a stand-in for the
# desktop file dialogs are built here, since the NDK has none of them. Pinned to fixed versions.
if (ANDROID)
    include(FetchContent)

    # SDL2 as a shared library: SDLActivity (android/app/src/main/java/org/libsdl/app, copied from this
    # same SDL release) loads libSDL2.so and then the game, libmain.so.
    set(SDL_SHARED ON CACHE BOOL "" FORCE)
    set(SDL_STATIC OFF CACHE BOOL "" FORCE)
    set(SDL_TEST OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(sdl2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.30.9
        GIT_SHALLOW TRUE)
    FetchContent_MakeAvailable(sdl2)
    # Gives both <SDL.h> and <SDL2/SDL.h>, as the desktop builds have.
    set(SDL2_INCLUDE_DIRS "$<TARGET_PROPERTY:SDL2,INTERFACE_INCLUDE_DIRECTORIES>")

    # FreeType for the menu fonts (RmlUi finds it with find_package(Freetype)).
    set(FT_DISABLE_ZLIB ON CACHE BOOL "" FORCE)
    set(FT_DISABLE_BZIP2 ON CACHE BOOL "" FORCE)
    set(FT_DISABLE_PNG ON CACHE BOOL "" FORCE)
    set(FT_DISABLE_HARFBUZZ ON CACHE BOOL "" FORCE)
    set(FT_DISABLE_BROTLI ON CACHE BOOL "" FORCE)
    FetchContent_Declare(freetype
        GIT_REPOSITORY https://github.com/freetype/freetype.git
        GIT_TAG VER-2-13-3
        GIT_SHALLOW TRUE)
    FetchContent_MakeAvailable(freetype)
    # Point FindFreetype at this build, so it reports FreeType as found and uses the freetype target.
    set(FREETYPE_INCLUDE_DIR_ft2build "${freetype_SOURCE_DIR}/include" CACHE PATH "" FORCE)
    set(FREETYPE_INCLUDE_DIR_freetype2 "${freetype_SOURCE_DIR}/include" CACHE PATH "" FORCE)
    set(FREETYPE_LIBRARY freetype CACHE STRING "" FORCE)
    if (NOT TARGET Freetype::Freetype)
        add_library(Freetype::Freetype ALIAS freetype)
    endif()

    # RT64 never builds zstd dictionaries, and their code needs qsort_r, which Android only has from API 36.
    set(ZSTD_BUILD_DICTBUILDER OFF CACHE BOOL "" FORCE)

    # No native file dialogs on Android: the ROM is picked in Java before the game starts.
    add_library(nfd STATIC ${CMAKE_SOURCE_DIR}/src/android/nfd_android.cpp)
    target_include_directories(nfd PUBLIC ${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib/nativefiledialog-extended/src/include)

    add_compile_definitions("PLUME_SDL_VULKAN_ENABLED")
    add_compile_definitions("RT64_SDL_WINDOW_VULKAN")
endif()

# iryoku/smaa, for the SMAA passes rt64.patch adds.
set(RT64_SMAA_DIR ${CMAKE_SOURCE_DIR}/lib/smaa)
# AMD FidelityFX FSR 1, for the FSR passes rt64.patch adds.
set(RT64_FSR_DIR ${CMAKE_SOURCE_DIR}/lib/fsr)
# Our additions to RT64 that live in this repository, not in rt64.patch (rt64-ext/README.md).
set(RT64_EXTENSION_CMAKE ${CMAKE_SOURCE_DIR}/rt64-ext/rt64_ext.cmake)
set(RT64_EXTENSION_SOURCE_DIR ${CMAKE_SOURCE_DIR}/rt64-ext/src)
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
)
# clang-cl ignores -falign-functions unless it is passed through with /clang:.
if (MSVC)
    target_compile_options(RecompiledFuncs PRIVATE /clang:-falign-functions=16)
else()
    target_compile_options(RecompiledFuncs PRIVATE -falign-functions=16)
endif()

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
if (ANDROID)
    # SDLActivity loads the game as libmain.so and calls its SDL_main.
    add_library(BanjoTooieN64Recomp SHARED)
    set_target_properties(BanjoTooieN64Recomp PROPERTIES OUTPUT_NAME main)
else()
    add_executable(BanjoTooieN64Recomp)
    # The game is called Banjo Re-Tooie (L, 2026-10-24); the target keeps its old name for the scripts that build it.
    set_target_properties(BanjoTooieN64Recomp PROPERTIES OUTPUT_NAME BanjoReTooie)
endif()

set (SOURCES
    ${CMAKE_SOURCE_DIR}/src/main/main.cpp
    ${CMAKE_SOURCE_DIR}/src/main/app_state.cpp
    ${CMAKE_SOURCE_DIR}/src/main/register_overlays.cpp
    ${CMAKE_SOURCE_DIR}/src/main/boot_screen.cpp

    ${CMAKE_SOURCE_DIR}/src/debug/dl_dump.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/pad_script.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/trace.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/warp.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/spawn_log.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/host_profiler.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/write_watch.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/enemy_respawn.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/distance_probe.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/watchdog.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/vram_log.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/settings_script.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/menu_pad.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/session_log.cpp
    ${CMAKE_SOURCE_DIR}/src/game/api_restart.cpp
    ${CMAKE_SOURCE_DIR}/src/game/app_data.cpp
    ${CMAKE_SOURCE_DIR}/src/game/boot.cpp
    ${CMAKE_SOURCE_DIR}/src/game/cheats.cpp
    ${CMAKE_SOURCE_DIR}/src/game/cic.cpp
    ${CMAKE_SOURCE_DIR}/src/game/config.cpp
    ${CMAKE_SOURCE_DIR}/src/game/console.cpp
    ${CMAKE_SOURCE_DIR}/src/game/menu_tree.cpp
    ${CMAKE_SOURCE_DIR}/src/game/more_memory.cpp
    ${CMAKE_SOURCE_DIR}/src/game/heap_guard.cpp
    ${CMAKE_SOURCE_DIR}/src/game/cutscene_guards.cpp
    ${CMAKE_SOURCE_DIR}/src/game/crash_handler.cpp
    ${CMAKE_SOURCE_DIR}/src/game/debug_watch.cpp
    ${CMAKE_SOURCE_DIR}/src/game/discord.cpp
    ${CMAKE_SOURCE_DIR}/src/game/speedup.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/player_cheats.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/transform_picker.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/enemy_spawner.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/explode_test.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/transform_anywhere.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/transform_menu.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/menu_pause.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/music_player.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/mix_rate.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/photo_mode.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/bottles_revenge.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/torch_enemy.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/save_state.cpp
    ${CMAKE_SOURCE_DIR}/src/input/motion_aim.cpp
    ${CMAKE_SOURCE_DIR}/src/input/menu_mouse.cpp
    ${CMAKE_SOURCE_DIR}/src/input/hand_cursor.cpp
    ${CMAKE_SOURCE_DIR}/src/input/hand_model_cursor.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/classic_sounds.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/progress_cheats.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/totals_checklist.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/pause_settings.cpp
    ${CMAKE_SOURCE_DIR}/src/game/game_init.cpp
    ${CMAKE_SOURCE_DIR}/src/game/overlays.cpp
    ${CMAKE_SOURCE_DIR}/src/game/preempt.cpp
    ${CMAKE_SOURCE_DIR}/src/game/sound_events.cpp
    ${CMAKE_SOURCE_DIR}/src/game/quick_start.cpp
    ${CMAKE_SOURCE_DIR}/src/game/hide_vanilla_widescreen.cpp
    ${CMAKE_SOURCE_DIR}/src/game/mod_zips.cpp
    ${CMAKE_SOURCE_DIR}/src/game/timer_save.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/dialogue_speed.cpp
    ${CMAKE_SOURCE_DIR}/src/input/tiptoe.cpp
    ${CMAKE_SOURCE_DIR}/src/input/hotkeys.cpp
    ${CMAKE_SOURCE_DIR}/src/input/control_scheme.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/talon_trot.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/hold_to_run.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/dive.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/canary_mary.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/fine_aim.cpp
    ${CMAKE_SOURCE_DIR}/src/display/picture_filters.cpp
    ${CMAKE_SOURCE_DIR}/src/display/smaa.cpp
    ${CMAKE_SOURCE_DIR}/src/display/fxaa.cpp
    ${CMAKE_SOURCE_DIR}/src/display/mirror_mode.cpp
    ${CMAKE_SOURCE_DIR}/src/input/low_latency.cpp
    ${CMAKE_SOURCE_DIR}/src/display/frame_readback.cpp
    ${CMAKE_SOURCE_DIR}/src/display/fsr.cpp
    ${CMAKE_SOURCE_DIR}/src/display/upscaler.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/fast_transitions.cpp
    ${CMAKE_SOURCE_DIR}/src/display/draw_distance.cpp
    ${CMAKE_SOURCE_DIR}/src/display/gfx_budget.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/free_camera.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/water_camera.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/high_detail_models.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/day_night.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/sun_control.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/dust.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/volumetric.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/volumetric_shadows.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/point_lights.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/night_sounds.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/hd_shadows.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/circle_shadow.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/field_of_view.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/cutscene_skip.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/honeycomb_glitter.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/honeycomb_cap.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/snout_jiggle.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/original_honeycomb.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/window_beams.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/jiggy_dance.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/test_room.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/race_warp.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/replays.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/size_cheats.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/damage_mods.cpp
    ${CMAKE_SOURCE_DIR}/src/gameplay/boss_rush.cpp
    ${CMAKE_SOURCE_DIR}/src/game/hud_edges.cpp
    ${CMAKE_SOURCE_DIR}/src/game/model_tagging.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/interp_check.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/texture_slide.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/interp_tags.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/parallax_pick.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/material_pick.cpp
    ${CMAKE_SOURCE_DIR}/src/game/widescreen.cpp
    ${CMAKE_SOURCE_DIR}/src/game/wide_transitions.cpp
    ${CMAKE_SOURCE_DIR}/src/game/save_backup.cpp
    ${CMAKE_SOURCE_DIR}/src/game/screenshot.cpp
    ${CMAKE_SOURCE_DIR}/src/game/texture_sweep.cpp
    ${CMAKE_SOURCE_DIR}/src/game/texture_context.cpp
    ${CMAKE_SOURCE_DIR}/src/game/memory_guard.cpp
    ${CMAKE_SOURCE_DIR}/src/game/asset_mods.cpp
    ${CMAKE_SOURCE_DIR}/src/game/sound_dump.cpp
    ${CMAKE_SOURCE_DIR}/src/game/level_warp.cpp
    ${CMAKE_SOURCE_DIR}/src/game/achievements.cpp
    ${CMAKE_SOURCE_DIR}/src/game/hide_hud.cpp
    ${CMAKE_SOURCE_DIR}/src/display/effect_views.cpp
    ${CMAKE_SOURCE_DIR}/src/game/frame_overlay.cpp
    ${CMAKE_SOURCE_DIR}/src/game/game_frame_rate.cpp
    ${CMAKE_SOURCE_DIR}/src/game/audio_task_check.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/heap_check.cpp
    ${CMAKE_SOURCE_DIR}/src/debug/aim_trace.cpp
    ${CMAKE_SOURCE_DIR}/src/ui/toast.cpp
    ${CMAKE_SOURCE_DIR}/src/ui/launcher_background.cpp
    ${CMAKE_SOURCE_DIR}/src/ui/launcher_title.cpp
    ${CMAKE_SOURCE_DIR}/src/ui/shader_progress.cpp
    ${CMAKE_SOURCE_DIR}/src/ui/photo_panel.cpp
    ${CMAKE_SOURCE_DIR}/src/ui/brightness_panel.cpp
    ${CMAKE_SOURCE_DIR}/src/ui/photo_album.cpp

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
# RT64_FILE_TO_C is RT64's file_to_c tool, or on Android a CMake script with the same output.
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/icon_bytes.c ${CMAKE_CURRENT_BINARY_DIR}/icon_bytes.h
    COMMAND ${RT64_FILE_TO_C} ${CMAKE_SOURCE_DIR}/icons/app.png icon_bytes ${CMAKE_CURRENT_BINARY_DIR}/icon_bytes.c ${CMAKE_CURRENT_BINARY_DIR}/icon_bytes.h
    DEPENDS ${CMAKE_SOURCE_DIR}/icons/app.png ${RT64_FILE_TO_C_DEPENDS}
)

target_sources(BanjoTooieN64Recomp PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/icon_bytes.c)

if(CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    if (TOOIE_CPU STREQUAL "modern")
        target_compile_definitions(BanjoTooieN64Recomp PRIVATE "TOOIE_CPU_NAME=\"newer CPUs, 2013 and up\"")
    else()
        target_compile_definitions(BanjoTooieN64Recomp PRIVATE "TOOIE_CPU_NAME=\"any 64-bit PC, 2008 and up\"")
    endif()
    target_compile_options(BanjoTooieN64Recomp PRIVATE
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

    # NVIDIA DLSS runtime (third-party/nvidia-dlss/README.md): fetched from NVIDIA's own repository at a pinned
    # commit, checked against its hash and copied beside the executable. It is NVIDIA's file under NVIDIA's licence.
    set(TOOIE_DLSS_COMMIT 9981c6350dc58c0ce21f024fd65e31e851c31689)
    set(TOOIE_DLSS_DLL ${CMAKE_BINARY_DIR}/nvidia-dlss/nvngx_dlss.dll)
    if(NOT EXISTS ${TOOIE_DLSS_DLL})
        file(DOWNLOAD
            https://github.com/NVIDIA/DLSS/raw/${TOOIE_DLSS_COMMIT}/lib/Windows_x86_64/rel/nvngx_dlss.dll
            ${TOOIE_DLSS_DLL}
            EXPECTED_HASH SHA256=d00b5b0ab29c3ca101b70c3a5ecb3a01b7ef33766a3383a28a18623083e6123e
            STATUS TOOIE_DLSS_STATUS)
        list(GET TOOIE_DLSS_STATUS 0 TOOIE_DLSS_CODE)
        if(NOT TOOIE_DLSS_CODE EQUAL 0)
            message(WARNING "Could not fetch nvngx_dlss.dll (${TOOIE_DLSS_STATUS}); DLSS will be unavailable.")
            file(REMOVE ${TOOIE_DLSS_DLL})
        endif()
    endif()
    if(EXISTS ${TOOIE_DLSS_DLL})
        add_custom_command(TARGET BanjoTooieN64Recomp POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TOOIE_DLSS_DLL}
                "${CMAKE_SOURCE_DIR}/third-party/nvidia-dlss/LICENSE.txt"
                $<TARGET_FILE_DIR:BanjoTooieN64Recomp>)
    endif()

    # AMD FSR 3 / FSR 4 (third-party/amd-fsr/LICENSE.txt): AMD's signed FidelityFX DLLs, fetched from AMD's SDK
    # repository at a pinned commit, checked against their hashes and copied beside the executable with the licence.
    set(TOOIE_FFX_COMMIT 60f4ea81909200d8542eca14dccb2628b763a9a3)
    set(TOOIE_FFX_FILES
        amd_fidelityfx_loader_dx12.dll:e2d85aa05a9bd9ed8b38935fdf5199372cca6f74c12015143bb6f945ee1608aa
        amd_fidelityfx_upscaler_dx12.dll:d0dcccc74a43c44ba435b7a369b456e0970d8a4464e4bd683119b374f2c9fb46)
    foreach(TOOIE_FFX_ENTRY ${TOOIE_FFX_FILES})
        string(REPLACE ":" ";" TOOIE_FFX_PARTS ${TOOIE_FFX_ENTRY})
        list(GET TOOIE_FFX_PARTS 0 TOOIE_FFX_NAME)
        list(GET TOOIE_FFX_PARTS 1 TOOIE_FFX_HASH)
        set(TOOIE_FFX_DLL ${CMAKE_BINARY_DIR}/amd-fsr/${TOOIE_FFX_NAME})
        if(NOT EXISTS ${TOOIE_FFX_DLL})
            file(DOWNLOAD
                https://github.com/GPUOpen-LibrariesAndSDKs/FidelityFX-SDK/raw/${TOOIE_FFX_COMMIT}/Kits/FidelityFX/signedbin/${TOOIE_FFX_NAME}
                ${TOOIE_FFX_DLL}
                EXPECTED_HASH SHA256=${TOOIE_FFX_HASH}
                STATUS TOOIE_FFX_STATUS)
            list(GET TOOIE_FFX_STATUS 0 TOOIE_FFX_CODE)
            if(NOT TOOIE_FFX_CODE EQUAL 0)
                message(WARNING "Could not fetch ${TOOIE_FFX_NAME} (${TOOIE_FFX_STATUS}); FSR 3 and FSR 4 will be unavailable.")
                file(REMOVE ${TOOIE_FFX_DLL})
            endif()
        endif()
        if(EXISTS ${TOOIE_FFX_DLL})
            add_custom_command(TARGET BanjoTooieN64Recomp POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TOOIE_FFX_DLL} $<TARGET_FILE_DIR:BanjoTooieN64Recomp>)
        endif()
    endforeach()
    add_custom_command(TARGET BanjoTooieN64Recomp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/third-party/amd-fsr/LICENSE.txt"
            "$<TARGET_FILE_DIR:BanjoTooieN64Recomp>/amd-fsr-LICENSE.txt")

    set_target_properties(
        BanjoTooieN64Recomp
        PROPERTIES
            LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE"
            LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
            LINK_FLAGS_RELWITHDEBINFO  "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
            LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
    )

    target_sources(BanjoTooieN64Recomp PRIVATE ${CMAKE_SOURCE_DIR}/icons/app.rc)
    # CMake does not see the ICON line in app.rc, so rebuild the resource when app.ico changes.
    set_source_files_properties(${CMAKE_SOURCE_DIR}/icons/app.rc PROPERTIES OBJECT_DEPENDS ${CMAKE_SOURCE_DIR}/icons/app.ico)
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

if (ANDROID)
    target_sources(BanjoTooieN64Recomp PRIVATE ${CMAKE_SOURCE_DIR}/src/android/android_platform.cpp)
    target_include_directories(BanjoTooieN64Recomp PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(BanjoTooieN64Recomp PRIVATE SDL2 freetype android log ${CMAKE_DL_LIBS})
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
elseif (ANDROID)
    # Cross build: run the shader compiler made for the build machine.
    if (CMAKE_HOST_WIN32)
        set (DXC "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxc.exe")
    elseif (CMAKE_HOST_APPLE)
        set (DXC "DYLD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/lib/arm64" "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/arm64/dxc-macos")
    elseif (CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64|amd64")
        set (DXC "LD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/lib/x64" "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxc-linux")
    else()
        set (DXC "LD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/lib/arm64" "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/arm64/dxc-linux")
    endif()
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
# recompui lists RT64's include folders itself; RT64's headers also include files from rt64-ext/.
target_include_directories(recompui PRIVATE ${CMAKE_SOURCE_DIR}/rt64-ext/src ${CMAKE_SOURCE_DIR}/rt64-ext/src/render)

if (ANDROID)
    # SDL copies its headers into its build folder while building; these include them without linking SDL.
    add_dependencies(plume sdl_headers_copy)
    add_dependencies(rt64 sdl_headers_copy)
    add_dependencies(recompui sdl_headers_copy)
    add_dependencies(recompinput sdl_headers_copy)
endif()

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
        COMMAND ${RT64_FILE_TO_C} ${NRM_FILE} ${NRM_NAME} ${OUT_C} ${OUT_H}
        DEPENDS ${NRM_FILE} ${RT64_FILE_TO_C_DEPENDS}
    )

    list(APPEND GENERATED_NRM_SOURCES ${OUT_C})
endforeach()

target_sources(BanjoTooieN64Recomp PRIVATE ${GENERATED_NRM_SOURCES})

target_sources(BanjoTooieN64Recomp PRIVATE ${SOURCES})

# The menus load assets/ (styles, fonts, icons) from the working directory, and the game moves to
# its own folder when that has none, so the exe in the build folder also runs on its own.
# (Android packs them into the APK instead, android/app/build.gradle.)
if (NOT ANDROID)
    add_custom_command(TARGET BanjoTooieN64Recomp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:BanjoTooieN64Recomp>/assets"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/recompcontrollerdb.txt" $<TARGET_FILE_DIR:BanjoTooieN64Recomp>)
endif()

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
