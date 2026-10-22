// Back-Port: Get Jiggy animation (L, 2026-10-13: "BK jiggy dance").
//
// In Banjo-Kazooie a Jiggy puts Banjo into his jig (bsjig, animation 0x2E for 4.3 s). Banjo-Tooie has no
// pose for an ordinary Jiggy: touching one (chjigsaw) only starts the Jiggy flying to the HUD
// (chjigsawcollect, an object of its own) with the jingle, and Banjo carries on. Checked headless
// 2026-10-22: a collected Jiggy left the player's state alone. The first versions of this option only
// swapped the animation of Tooie's own jig state, which a Jiggy never enters, so they did nothing
// (L, 2026-10-14 and 2026-10-21).
//
// Tooie still carries Banjo-Kazooie's jig code. Player interrupt 0x35 (flag 0x1A in the interrupt
// handler func_80099B94) starts state 0x34 for Banjo and Kazooie together: the same bsjig file's
// second jig, animation 0x282 for 3.6 s with Kazooie out, under the black bars and the celebration
// camera. Its update leaves the state when the animation stops. So with the option on:
// - the tick watches for a new chjigsawcollect object (a Jiggy was just collected) and raises
//   interrupt 0x35 once Banjo is standing (within a few seconds, or not at all), and
// - the state's init (banjotooie.us.toml hooks bsjig_entrypoint_9 right after it starts 0x282) swaps the
//   animation for BK's 0x2E at 4.3 s.
// The game's own interrupt handlers decide whether the jig can start (a form or state that has no jig
// ignores it), and only the animation in the player's own ROM is used.
//
// Debug: TOOIE_JIGGY_DANCE=1 forces it on; TOOIE_JIGGY_DANCE_TEST=<ms> raises interrupt 0x35 that
// long after the game starts (the jig without a Jiggy); TOOIE_JIGGY_DANCE_SPAWN=<ms> spawns a Jiggy
// (actor 0x21F) on Banjo that long after the game starts, so he collects one (it works with no file
// loaded: TOOIE_WARP=AF:0@15000); TOOIE_JIGGY_DANCE_LOG=1 logs it.

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <variant>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"

#include "tooie_hooks.h"
#include "tooie_jiggy_dance.h"
#include "tooie_rdram.h"

namespace {
    using Clock = std::chrono::steady_clock;

    // Player 0's PlayerState pointer (see src/gameplay/player_cheats.cpp).
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t state_offset = 0x120;   // PlayerState -> state block
    constexpr uint32_t state_current = 0x4;    // state block -> current state id
    constexpr uint32_t player_pos_ptr = 0xE4;  // PlayerState -> position (f32[3])

    constexpr uint32_t celebrate_state = 0x34; // Tooie's jig (bsjig, animation 0x282)
    constexpr uint32_t celebrate_interrupt = 0x35;
    constexpr uint32_t bk_jig_anim = 0x2E;     // BK's jiggy jig (ASSET_2E_ANIM_BSJIG_JIGGY)
    constexpr uint32_t bk_jig_duration = 0x4089999A; // 4.3f, as BK's bsjig_jiggy_init sets it

    // Objects (see src/gameplay/test_room.cpp): +0x10 holds the actor's syscall entry.
    constexpr uint32_t object_array_pointer = 0x80136EE0;
    constexpr uint32_t object_first = 0x04;
    constexpr uint32_t object_last = 0x08;
    constexpr uint32_t object_base = 0x10;
    constexpr uint32_t object_size = 0x9C;
    constexpr uint32_t object_entry = 0x10;
    constexpr int max_objects = 2048;
    constexpr uint32_t jiggy_collect_entry = 0x800867B0; // _chjigsawcollect_entrypoint_0
    constexpr uint16_t jiggy_actor = 0x21F;              // a Jiggy (src/gameplay/test_room_actors.inc)

    // How long after a Jiggy is collected the jig may still start (Banjo landing first).
    constexpr auto start_window = std::chrono::milliseconds(3000);

    using tooie::rdram::read_float;
    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;
    using tooie::rdram::write_float;

    bool log_on() {
        static const bool on = std::getenv("TOOIE_JIGGY_DANCE_LOG") != nullptr;
        return on;
    }

    long env_ms(const char* name) {
        const char* v = std::getenv(name);
        return v != nullptr ? std::atol(v) : -1L;
    }

    bool chosen(Clock::time_point now) {
        static const bool forced = std::getenv("TOOIE_JIGGY_DANCE") != nullptr;
        static bool cached = false;
        static Clock::time_point cached_at{};
        if (forced) {
            return true;
        }
        // The option is read a few times a second, not every frame.
        if (cached_at == Clock::time_point{} || now - cached_at > std::chrono::milliseconds(250)) {
            cached_at = now;
            try {
                cached = std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::jiggy_dance::option));
            } catch (...) {
                cached = false;
            }
        }
        return cached;
    }

    // A copy of the game's context with room below its stack, for calling game functions from the tick.
    recomp_context call_context(recomp_context* ctx, uint32_t player) {
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        call.r4 = (int32_t)player;
        return call;
    }

    void play_bk_jig(uint8_t* rdram, recomp_context* ctx, uint32_t player) {
        recomp_context call = call_context(ctx, player);
        baanim_getAnimCtrlPtr(rdram, &call);
        const int32_t anim_ctrl = (int32_t)call.r2;
        if (!valid_ptr((uint32_t)anim_ctrl)) {
            return;
        }
        // As bsjig_jiggy_init: reset, no blend, animation 0x2E for 4.3 s, played once.
        call.r4 = anim_ctrl;
        anctrl_reset(rdram, &call);
        call.r4 = anim_ctrl;
        call.r5 = 0;
        anctrl_setSmoothTransition(rdram, &call);
        call.r4 = anim_ctrl;
        call.r5 = bk_jig_anim;
        anctrl_setIndex(rdram, &call);
        call.r4 = anim_ctrl;
        call.r5 = (int32_t)bk_jig_duration;
        anctrl_setDuration(rdram, &call);
        call.r4 = anim_ctrl;
        call.r5 = 1;
        anctrl_setPlaybackType(rdram, &call);
        call.r4 = anim_ctrl;
        anctrl_start(rdram, &call);
    }

    // Raises the jig's interrupt, as bs_checkInterrupt; returns the handler's result.
    int raise_jig(uint8_t* rdram, recomp_context* ctx, uint32_t player) {
        recomp_context call = call_context(ctx, player);
        call.r5 = celebrate_interrupt;
        func_8009E7C8(rdram, &call); // bs_checkInterrupt
        return (int)call.r2;
    }

    bool player_stable(uint8_t* rdram, recomp_context* ctx, uint32_t player) {
        recomp_context call = call_context(ctx, player);
        player_isStable(rdram, &call);
        return call.r2 != 0;
    }

    // How many Jiggies are flying to the HUD (chjigsawcollect objects).
    int jiggies_collecting(uint8_t* rdram) {
        const uint32_t array = read_word(rdram, object_array_pointer);
        if (!valid_ptr(array)) {
            return 0;
        }
        const uint32_t first = read_word(rdram, array + object_first);
        const uint32_t last = read_word(rdram, array + object_last);
        if (!valid_ptr(first) || !valid_ptr(last) || last < first) {
            return 0;
        }
        const int count = (int)((last - first) / object_size) + 1;
        int found = 0;
        for (int i = 0; i < count && i < max_objects; i++) {
            if (read_word(rdram, array + object_base + (uint32_t)i * object_size + object_entry) == jiggy_collect_entry) {
                found++;
            }
        }
        return found;
    }

    // Debug aid (TOOIE_JIGGY_DANCE_SPAWN): spawns a Jiggy where Banjo stands, as src/gameplay/test_room.cpp
    // does, with the position in a scratch area below the stack.
    void spawn_jiggy(uint8_t* rdram, recomp_context* ctx, uint32_t pos_ptr) {
        recomp_context call = *ctx;
        const uint32_t vec = ((uint32_t)ctx->r29 - 0x100) & ~0xFu;
        for (int k = 0; k < 3; k++) {
            write_float(rdram, vec + 4 * k, read_float(rdram, pos_ptr + 4 * k));
        }
        call.r29 = (int32_t)(vec - 0x40);
        call.r4 = jiggy_actor;
        call.r5 = (int32_t)vec;
        call.r6 = 0;
        func_80108474(rdram, &call);
        std::printf("[jiggy dance] spawned a Jiggy on Banjo (object 0x%08X)\n", (uint32_t)call.r2);
        std::fflush(stdout);
    }

    uint32_t last_state = 0;
    int last_collecting = 0;
    bool pending = false;
    Clock::time_point pending_since{};
}

void tooie::jiggy_dance::tick(uint8_t* rdram, recomp_context* ctx) {
    static const Clock::time_point started = Clock::now();
    const auto now = Clock::now();
    const uint32_t player = read_word(rdram, player_table);
    if (!valid_ptr(player)) {
        last_state = 0;
        pending = false;
        return;
    }
    const uint32_t block = read_word(rdram, player + state_offset);
    if (!valid_ptr(block)) {
        last_state = 0;
        pending = false;
        return;
    }
    const uint32_t state = read_word(rdram, block + state_current);

    static const long test_ms = env_ms("TOOIE_JIGGY_DANCE_TEST");
    static bool test_done = false;
    if (test_ms >= 0 && !test_done && now - started > std::chrono::milliseconds(test_ms)) {
        test_done = true;
        const int result = raise_jig(rdram, ctx, player);
        if (log_on()) {
            std::printf("[jiggy dance] raised interrupt 0x35 (result %d)\n", result);
            std::fflush(stdout);
        }
    }

    static const long spawn_ms = env_ms("TOOIE_JIGGY_DANCE_SPAWN");
    static bool spawn_done = false;
    const uint32_t pos_ptr = read_word(rdram, player + player_pos_ptr);
    if (spawn_ms >= 0 && !spawn_done && now - started > std::chrono::milliseconds(spawn_ms) && valid_ptr(pos_ptr)) {
        spawn_done = true;
        spawn_jiggy(rdram, ctx, pos_ptr);
    }

    // A new Jiggy flying to the HUD means one was just collected.
    const int collecting = jiggies_collecting(rdram);
    if (collecting > last_collecting && chosen(now)) {
        pending = true;
        pending_since = now;
        if (log_on()) {
            std::printf("[jiggy dance] Jiggy collected (state 0x%X)\n", state);
            std::fflush(stdout);
        }
    }
    last_collecting = collecting;

    if (pending) {
        if (state == celebrate_state || now - pending_since > start_window) {
            pending = false;
        } else if (player_stable(rdram, ctx, player)) {
            pending = false;
            const int result = raise_jig(rdram, ctx, player);
            if (log_on()) {
                std::printf("[jiggy dance] raised the jig from state 0x%X (result %d)\n", state, result);
                std::fflush(stdout);
            }
        }
    }

    if (state != last_state && log_on()) {
        std::printf("[jiggy dance] state 0x%X -> 0x%X\n", last_state, state);
        std::fflush(stdout);
    }
    last_state = state;
}

extern "C" void tooie_jiggy_dance_init(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t player = (uint32_t)ctx->r16;
    const bool on = valid_ptr(player) && chosen(Clock::now());
    if (on) {
        play_bk_jig(rdram, ctx, player);
    }
    if (log_on()) {
        std::printf("[jiggy dance] jig init: %s\n", on ? "playing BK's jig" : "Tooie's animation");
        std::fflush(stdout);
    }
}
