// Level transition speed (handoff 4.29): Original, Fast (4x) or Instant (16x).
//
// The screen wipes are the gctransitionDll overlay. gctransitionDll_entrypoint_9
// is a wipe's per-frame update: it reads the frame time into $f0/$f2 and adds
// it to the wipe's timer (+0x28) until the timer passes its length (+0xC). Wipes
// with a model also play an animation whose length func_808000D8 sets with
// anctrl_setDuration (the animation controller is at +0x2C, its length at +0xC).
// banjotooie.us.toml hooks both spots: the frame time is multiplied by the
// speed, and the animation length is divided by it. Only wipes that run while
// a map change is pending, or right after one, are sped up, so cutscene fades
// keep their speed.
//
// TOOIE_LOG_TRANSITIONS=1 prints when each wipe starts and ends.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_hooks.h"

namespace {
    constexpr gpr map_change_request_addr = (int32_t)0x80127642; // D_80127630.unk12
    constexpr gpr current_map_addr = (int32_t)0x80132DC2;

    bool log_enabled() {
        static const bool enabled = std::getenv("TOOIE_LOG_TRANSITIONS") != nullptr;
        return enabled;
    }

    double seconds_now() {
        using namespace std::chrono;
        return duration<double>(steady_clock::now().time_since_epoch()).count();
    }

    float speed_factor() {
        uint32_t value = 0;
        try {
            value = std::get<uint32_t>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::transition_speed_option));
        } catch (...) {
        }
        switch (static_cast<tooie::TransitionSpeed>(value)) {
            case tooie::TransitionSpeed::Fast:    return 4.0f;
            case tooie::TransitionSpeed::Instant: return 16.0f;
            default: return 1.0f;
        }
    }

    float read_float(uint8_t* rdram, gpr addr) {
        uint32_t bits = MEM_W(0, addr);
        float f;
        memcpy(&f, &bits, sizeof(f));
        return f;
    }

    void write_float(uint8_t* rdram, gpr addr, float f) {
        uint32_t bits;
        memcpy(&bits, &f, sizeof(bits));
        MEM_W(0, addr) = bits;
    }

    // The map at the last pending map change. The first wipe on the map that
    // change led to is the fade-in that belongs to it; once that wipe is over,
    // later wipes there (cutscene fades) keep their speed.
    int last_change_target = -1;
    gpr fade_in_wipe = 0;
    gpr logged_wipe = 0;
    bool logged_active = false;
    int logged_quarter = 0;

    bool map_change_wipe(uint8_t* rdram) {
        if (MEM_BU(0, map_change_request_addr) != 0) {
            last_change_target = MEM_HU(0, (int32_t)0x80127640);
            fade_in_wipe = 0;
            return true;
        }
        return last_change_target == (int)MEM_HU(0, current_map_addr);
    }
}

namespace {
    // When a wipe was last seen drawing (steady clock ticks), for wipe_showing.
    std::atomic<int64_t> wipe_seen_at{0};
}

bool tooie::wipe_showing() {
    const int64_t at = wipe_seen_at.load();
    return at != 0 && std::chrono::steady_clock::now().time_since_epoch().count() - at <
        std::chrono::duration_cast<std::chrono::steady_clock::duration>(std::chrono::milliseconds(100)).count();
}

// gctransitionDll_entrypoint_9, after the frame time is in $f2. $a3 is the wipe.
extern "C" void tooie_transition_frame(uint8_t* rdram, recomp_context* ctx) {
    gpr wipe = ctx->r7;
    bool active = MEM_BU(0x8, wipe) != 0;
    if (active) {
        wipe_seen_at = std::chrono::steady_clock::now().time_since_epoch().count();
    }
    if (log_enabled() && (wipe != logged_wipe || active != logged_active)) {
        fprintf(stderr, "[transition] %.3f wipe %08X %s type %u timer %.3f/%.3f map %03X request %u speed %.0f\n",
            seconds_now(), (uint32_t)wipe, active ? "on" : "off", MEM_BU(0x1C, wipe),
            read_float(rdram, wipe + 0x28), read_float(rdram, wipe + 0xC),
            MEM_HU(0, current_map_addr), MEM_BU(0, map_change_request_addr), speed_factor());
        logged_wipe = wipe;
        logged_active = active;
        logged_quarter = 0;
    }
    if (log_enabled() && active) {
        float length = read_float(rdram, wipe + 0xC);
        int quarter = length > 0 ? (int)(4 * read_float(rdram, wipe + 0x28) / length) : 4;
        if (quarter != logged_quarter) {
            fprintf(stderr, "[transition] %.3f wipe %08X at %d/4\n", seconds_now(), (uint32_t)wipe, quarter);
            logged_quarter = quarter;
        }
    }
    if (!active || !map_change_wipe(rdram)) {
        return;
    }
    if (MEM_BU(0, map_change_request_addr) == 0) {
        // The fade-in. Stop after it, when its timer is used up.
        if (fade_in_wipe == 0) {
            fade_in_wipe = wipe;
        } else if (fade_in_wipe != wipe) {
            last_change_target = -1;
            return;
        }
        if (read_float(rdram, wipe + 0x28) >= read_float(rdram, wipe + 0xC)) {
            last_change_target = -1;
        }
    }
    // Both: the timer takes $f0 when the wipe has no animation, $f2 otherwise.
    float speed = speed_factor();
    ctx->f0.fl *= speed;
    ctx->f2.fl *= speed;
}

// func_808000D8_gctransitionDll, after anctrl_setDuration. $s0 is the wipe.
extern "C" void tooie_transition_anim_length(uint8_t* rdram, recomp_context* ctx) {
    if (!map_change_wipe(rdram)) {
        return;
    }
    gpr anim = (int32_t)MEM_W(0x2C, ctx->r16);
    if (anim == 0) {
        return;
    }
    write_float(rdram, anim + 0xC, read_float(rdram, anim + 0xC) / speed_factor());
}
