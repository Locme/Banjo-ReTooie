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
#include "funcs.h"
#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_player_cheats.h"
#include "tooie_progress_cheats.h"

namespace {
    // Halfword holding the map that is loaded now (found by warping to two maps
    // and comparing RDRAM; ScriptHawk's bt.lua uses the same address).
    constexpr gpr current_map_addr = (int32_t)0x80132DC2;
    // The game-state block holding map change requests.
    constexpr gpr game_state_addr = (int32_t)0x80127630;

    struct Request {
        uint16_t map;
        uint8_t exit;
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

void tooie::debug::request_warp(uint16_t map, uint8_t exit) {
    std::lock_guard lock{request_mutex};
    pending = Request{map, exit};
}

uint16_t tooie::debug::current_map(uint8_t* rdram) {
    return (uint16_t)MEM_H(0x0, current_map_addr);
}

// Hooked at the entry of func_800A7D84, the game's per-frame state update.
extern "C" void tooie_warp_tick(uint8_t* rdram, recomp_context* ctx) {
    std::call_once(env_flag, read_env);
    std::call_once(started_flag, [] { started = std::chrono::steady_clock::now(); });
    tooie::quick_start_tick(rdram);
    tooie::timer_save_tick(rdram, ctx);
    tooie::player_cheats::tick(rdram, ctx);
    tooie::progress_cheats::tick(rdram, ctx);

    if (env_next < env_requests.size()) {
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
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
    if (request->map == from) {
        fprintf(stderr, "[warp] already in map 0x%X, nothing to do\n", from);
        return;
    }

    fprintf(stderr, "[warp] map 0x%X exit %u (from map 0x%X)\n", request->map, request->exit, from);

    // Call the map change as if from here, then put the registers back for
    // func_800A7D84, which has not started yet.
    recomp_context saved = *ctx;
    ctx->r4 = request->map;
    ctx->r5 = request->exit;
    ctx->r6 = 1;
    func_800A7990(rdram, ctx);
    *ctx = saved;
}
