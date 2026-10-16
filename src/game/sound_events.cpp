// Sound effect player events (L's texture sweep and Mumbo's Skull hangs of 2026-10-16, Game frame rate Uncapped).
//
// The game's sound effect player (made by func_800DC380 / func_8001EB10, pointer at 0x800411DC)
// takes changes as events from a pool of 256 (its config's second word). A sound that moves or
// changes posts pan, volume and effect events every game frame, but the player takes them only on
// its own 60-a-second tick. In L's Mumbo's Skull hang dump 255 of the 256 were in use, almost all
// by one sound, so stop and end events found no room and stopped sounds kept their handles.
//
// Two changes: when the sound memory has been moved to the bigger heap (More game memory or Mix rate
// High, src/gameplay/mix_rate.cpp) the pool holds 1024 events; and a pan, volume, pitch or effect
// change is dropped while fewer than 64 events are free, so the wake-up, play and stop events always
// fit. A dropped change only loses an in-between value: the sound posts a newer one next game frame.
//
// TOOIE_SOUND_EVENT_LOG=1 logs each drop streak. TOOIE_SOUND_EVENTS=<n> sets the pool size and
// TOOIE_SOUND_NO_DROP=1 turns the drop off, for comparing.

#include <cstdio>
#include <cstdlib>

#include "recomp.h"
#include "tooie_hooks.h"

namespace {
    constexpr gpr sound_player_ptr = (int32_t)0x800411DC;
    constexpr gpr sound_heap = (int32_t)0x80046A78; // ALHeap { base, cur, len, count }
    constexpr uint32_t moved_heap_size = 0x80000;
    constexpr uint32_t bigger_pool = 0x400;
    // Events kept free for the player's own wake-up, play and stop events: a quarter of the pool, at most 64.
    int keep_free = 64;

    gpr k0(uint32_t addr) {
        return (gpr)(int64_t)(int32_t)addr;
    }

    bool parameter_event(uint16_t type) {
        // Pan, volume, pitch and effect mix (the types seen flooding the pool).
        return type == 0x4 || type == 0x8 || type == 0x10 || type == 0x100;
    }
}

// Before func_8001EB10 builds the sound effect player from its config ($a0).
extern "C" void tooie_sound_event_pool(uint8_t* rdram, recomp_context* ctx) {
    uint32_t events = MEM_W(4, ctx->r4);
    uint32_t pool = events;
    if ((uint32_t)MEM_W(8, sound_heap) == moved_heap_size && events < bigger_pool) {
        pool = bigger_pool;
    }
    if (const char* env = std::getenv("TOOIE_SOUND_EVENTS")) {
        pool = (uint32_t)std::strtoul(env, nullptr, 0);
    }
    MEM_W(4, ctx->r4) = pool;
    keep_free = (int)(pool / 4 < 64 ? pool / 4 : 64);
    std::printf("[sound] effect player events: %u (game asks %u), %d kept free\n", pool, events, keep_free);
    std::fflush(stdout);
}

// At the start of func_80026500 (post an event: $a0 the queue, $a1 the event, $a2 the delay).
// Returns true to drop the event.
extern "C" int tooie_sound_event_full(uint8_t* rdram, recomp_context* ctx) {
    uint32_t player = (uint32_t)MEM_W(0, sound_player_ptr);
    if (player == 0 || (uint32_t)ctx->r4 != player + 0x14) {
        return 0;
    }
    const uint16_t type = (uint16_t)MEM_HU(0, ctx->r5);
    static const bool no_drop = std::getenv("TOOIE_SOUND_NO_DROP") != nullptr;
    if (!parameter_event(type) || no_drop) {
        return 0;
    }
    // The queue's free list starts at its first word.
    int free_events = 0;
    for (uint32_t e = (uint32_t)MEM_W(0, ctx->r4); e != 0 && free_events < keep_free; e = (uint32_t)MEM_W(0, k0(e))) {
        free_events++;
    }
    static const bool log = std::getenv("TOOIE_SOUND_EVENT_LOG") != nullptr;
    static unsigned dropped = 0;
    if (free_events >= keep_free) {
        if (log && dropped != 0) {
            std::printf("[sound] dropped %u sound changes while the event pool was nearly full\n", dropped);
            std::fflush(stdout);
        }
        dropped = 0;
        return 0;
    }
    dropped++;
    return 1;
}
