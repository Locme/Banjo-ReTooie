// Map warps for headless tests, and the base for the level warp (handoff 4.80).
//
//     TOOIE_WARP=AF:0          warp to map 0xAF, exit 0, at the first chance
//     TOOIE_WARP=AF:0@30000    the same, 30 s after the game loop first runs
//     TOOIE_WARP=AF:0@15000,B8:0@30000   several warps, in time order
//
// Map and exit are hex. Exit 0 is the area's default spawn; 1 is where a level
// is entered from the Isle o' Hags (handoff 4.80 lists verified ids).
//
// The game's map change is func_800A7990(map, exit, transition): it stores the
// request in the game-state block at 0x80127630 (+0x10 map, +0x13 exit) and
// sets the go byte (+0x12), which func_800A7D84 acts on at the start of the
// next frame. banjotooie.us.toml hooks the entry of func_800A7D84 so requests
// are issued on the game thread, between frames.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "recomp.h"

namespace tooie::debug {
    // TOOIE_EXPLODE=<type>@<ms>,...: the game's explosions in front of Banjo (src/debug/explode_test.cpp).
    void explode_tick(uint8_t* rdram, recomp_context* ctx);
}
#include "funcs.h"
#include "tooie_console.h"
#include "tooie_debug.h"
#include "tooie_game_frame_rate.h"
#include "tooie_music_player.h"
#include "tooie_photo_mode.h"
#include "tooie_bottles_revenge.h"
#include "tooie_enemy_spawner.h"
#include "tooie_torch_enemy.h"
#include "tooie_save_state.h"
#include "tooie_motion_aim.h"
#include "tooie_menu_mouse.h"
#include "tooie_game.h"
#include "tooie_damage.h"
#include "tooie_player_cheats.h"
#include "tooie_talon_trot.h"
#include "tooie_dive.h"
#include "tooie_hold_to_run.h"
#include "tooie_fine_aim.h"
#include "tooie_progress_cheats.h"
#include "tooie_transform_picker.h"
#include "tooie_transform_anywhere.h"
#include "tooie_menu_pause.h"
#include "tooie_music_player.h"
#include "tooie_classic_sounds.h"
#include "tooie_honeycomb_glitter.h"
#include "tooie_jiggy_dance.h"
#include "tooie_achievements.h"
#include "tooie_hd_shadows.h"
#include "tooie_day_night.h"
#include "tooie_volumetric.h"
#include "tooie_volumetric_shadows.h"
#include "tooie_picture_filters.h"
#include "tooie_texture_sweep.h"
#include "tooie_vram_log.h"
#include "tooie_memory_guard.h"
#include "tooie_asset_mods.h"
#include "tooie_sound_dump.h"
#include "tooie_test_room.h"
#include "tooie_race_warp.h"
#include "tooie_replays.h"
#include "tooie_boss_rush.h"
#include "tooie_point_lights.h"

namespace {
    // Halfword holding the map that is loaded now (found by warping to two maps
    // and comparing RDRAM; ScriptHawk's bt.lua uses the same address).
    constexpr gpr current_map_addr = (int32_t)0x80132DC2;
    // Halfword: id of the actor Banjo rides (0 when not riding), func_8009EA64 reads it.
    constexpr gpr ride_actor_addr = (int32_t)0x8012707C;
    // The game-state block holding map change requests.
    constexpr gpr game_state_addr = (int32_t)0x80127630;
    // Maps where no save file is being played (map_names.inc).
    constexpr uint16_t title_map = 0x18B;
    constexpr uint16_t game_select_map = 0x158;
    std::atomic<bool> ticked{false};
    std::atomic<uint16_t> last_map{0};

    struct Request {
        uint16_t map;
        uint8_t exit;
        bool same_map = false;
    };

    std::mutex request_mutex;
    std::optional<Request> pending;
    struct TimedRequest {
        Request request;
        uint32_t delay_ms;
    };
    std::vector<TimedRequest> env_requests;
    size_t env_next = 0;
    std::once_flag env_flag;
    std::once_flag started_flag;
    std::chrono::steady_clock::time_point started;

    void read_env() {
        const char* env = std::getenv("TOOIE_WARP");
        if (env == nullptr || *env == '\0') {
            return;
        }
        std::stringstream list(env);
        std::string item;
        while (std::getline(list, item, ',')) {
            unsigned map = 0, exit = 0, delay = 0;
            int fields = std::sscanf(item.c_str(), "%x:%x@%u", &map, &exit, &delay);
            if (fields < 2) {
                fprintf(stderr, "[warp] TOOIE_WARP entry %s not understood, expected map:exit[@ms] in hex\n", item.c_str());
                continue;
            }
            env_requests.push_back({Request{(uint16_t)map, (uint8_t)exit}, fields >= 3 ? delay : 0u});
        }
    }
}

void tooie::debug::request_warp(uint16_t map, uint8_t exit, bool same_map) {
    std::lock_guard lock{request_mutex};
    pending = Request{map, exit, same_map};
}

bool tooie::debug::can_warp() {
    // The game loop has run (so not still in the launcher).
    if (!ticked.load()) {
        return false;
    }
    // A save file is being played: not the title screen or the game select.
    uint16_t map = last_map.load();
    return map != 0 && map != title_map && map != game_select_map;
}

bool tooie::debug::warp_pending() {
    std::lock_guard lock{request_mutex};
    return pending.has_value();
}

bool tooie::debug::map_change_busy(uint8_t* rdram) {
    return MEM_B(0x12, game_state_addr) != 0;
}

uint16_t tooie::debug::current_map(uint8_t* rdram) {
    return (uint16_t)MEM_H(0x0, current_map_addr);
}

// Hooked at the entry of func_800A7D84, the game's per-frame state update.
extern "C" void tooie_warp_tick(uint8_t* rdram, recomp_context* ctx) {
    std::call_once(env_flag, read_env);
    std::call_once(started_flag, [] { started = std::chrono::steady_clock::now(); });
    ticked = true;
    // First, so the other ticks act on a loaded state.
    tooie::save_state::tick(rdram, ctx);
    // The developer console's queue, on the game thread between frames.
    tooie::console::frame(rdram, ctx);
    last_map = tooie::debug::current_map(rdram);
    tooie::quick_start_tick(rdram);
    tooie::timer_save_tick(rdram, ctx);
    tooie::cutscene_skip_tick(rdram);
    tooie::player_cheats::tick(rdram, ctx);
    tooie::talon_trot::tick(rdram, ctx);
    tooie::hold_to_run::tick(rdram, ctx);
    tooie::dive::tick(rdram, ctx);
    tooie::damage::aim_tick(rdram);
    tooie::fine_aim::tick(rdram, ctx);
    tooie::motion_aim::tick(rdram, ctx);
    tooie::menu_mouse::tick(rdram, ctx);
    tooie::picture_filters::tick(rdram, ctx);
    tooie::vanilla_widescreen_tick(rdram, ctx);
    tooie::progress_cheats::tick(rdram, ctx);
    tooie::transform_picker::tick(rdram, ctx);
    tooie::transform_anywhere::tick(rdram, ctx);
    tooie::music_player::tick(rdram, ctx);
    tooie::bottles_revenge::tick(rdram, ctx);
    tooie::torch_enemy::tick(rdram, ctx);
    tooie::enemy_spawner::tick(rdram, ctx);
    tooie::debug::explode_tick(rdram, ctx);
    tooie::classic_sounds::tick(rdram);
    tooie::honeycomb_glitter::tick(rdram, ctx);
    tooie::jiggy_dance::tick(rdram, ctx);
    tooie::achievements::tick(rdram, ctx);
    tooie::day_night::tick(rdram);
    tooie::volumetric::tick(rdram);
    tooie::volumetric_shadows::tick();
    tooie::point_lights::tick(rdram);
    tooie::hd_shadows::tick();
    tooie::vram_log::start();
    tooie::memory_guard::tick(rdram);
    tooie::texture_sweep::tick(rdram);
    tooie::asset_mods::tick(rdram);
    tooie::sound_dump::tick(rdram);
    tooie::test_room::tick(rdram, ctx);
    // Before the warp below, which it may ask for.
    tooie::replays::tick(rdram, ctx);
    tooie::race_warp::tick(rdram, ctx);
    tooie::boss_rush::tick(rdram, ctx);
    // Last: photo mode scales this frame's delta time.
    tooie::photo_mode::tick(rdram, ctx);
    // After photo mode: the ESC menu's pause sets the frame's delta time too.
    tooie::menu_pause::tick(rdram, ctx);

    // TOOIE_MAP_CHANGE_LOG=1: every map change the game asks for, with its exit, to find exit ids.
    static const bool map_change_log = std::getenv("TOOIE_MAP_CHANGE_LOG") != nullptr;
    static bool go_was_set = false;
    if (map_change_log) {
        bool go = MEM_B(0x12, game_state_addr) != 0;
        if (go && !go_was_set) {
            fprintf(stderr, "[map-change] to map 0x%X exit %u (from map 0x%X)\n",
                (unsigned)MEM_HU(0x10, game_state_addr), (unsigned)MEM_BU(0x13, game_state_addr),
                tooie::debug::current_map(rdram));
        }
        go_was_set = go;
    }

    if (env_next < env_requests.size()) {
        static const bool game_clock = std::getenv("TOOIE_SCREENSHOT_GAME") != nullptr;   // QA: times in game time
        auto elapsed = game_clock ? (long long)tooie::game_frame_rate::game_ms() : (long long)std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - started).count();
        if (elapsed >= env_requests[env_next].delay_ms) {
            const Request& r = env_requests[env_next].request;
            tooie::debug::request_warp(r.map, r.exit);
            env_next++;
        }
    }

    std::optional<Request> request;
    {
        std::lock_guard lock{request_mutex};
        if (!pending.has_value()) {
            return;
        }
        // A map change is already under way (the go byte stays set during the
        // wipe): keep the request for a later frame.
        if (MEM_B(0x12, game_state_addr) != 0) {
            return;
        }
        request.swap(pending);
    }

    uint16_t from = tooie::debug::current_map(rdram);
    if (request->map == from && !request->same_map) {
        fprintf(stderr, "[warp] already in map 0x%X, nothing to do\n", from);
        return;
    }

    fprintf(stderr, "[warp] map 0x%X exit %u (from map 0x%X)\n", request->map, request->exit, from);

    // Banjo riding a cart (Canary Mary's in a race): the halfword at 0x8012707C holds the ridden
    // actor's id (set on mounting, func_80099B54, cleared on getting off, func_808000F0_bsride).
    // Entering a map with it set puts Banjo back in the ride state, and bsride looks the cart up in
    // the new map; with no such cart there it read address 0 (L's crash of 2026-10-17 09:53:56,
    // a race warp from inside a race). The game only changes maps on a cart where both maps have
    // it, so a warp takes him off.
    if (MEM_H(0, ride_actor_addr) != 0) {
        fprintf(stderr, "[warp] Banjo was riding actor id 0x%X, taken off for the warp\n", (unsigned)MEM_HU(0, ride_actor_addr));
        MEM_H(0, ride_actor_addr) = 0;
    }

    // Call the map change as if from here, then put the registers back for
    // func_800A7D84, which has not started yet.
    recomp_context saved = *ctx;
    ctx->r4 = request->map;
    ctx->r5 = request->exit;
    ctx->r6 = 1;
    func_800A7990(rdram, ctx);
    *ctx = saved;
}
