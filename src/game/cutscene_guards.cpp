// Guards for cutscenes entered straight from another map, as the texture sweep and the warps do.
//
// chanim_entrypoint_6 frees an actor's animation (the actor's data slot 0, from func_80100094). The
// intro characters (chintrochar) in Banjo's house is destroyed (0xAC) and All Jinjos Happy Again
// (0x199) call it on leaving the map even when they never got an animation, which the earlier intro
// scenes set up when the cutscenes are watched in order. The slot is then null and the game read
// address 0 (L's crash of 2026-10-17 09:29:58, and the 0xAC crash the sweep used to skip). With
// nothing there is nothing to free, so the guard returns early. The same characters then free the
// animation sequences and blinks held in their data slot 2 (func_80800648_chintrochar), null for the
// same reason in the intro scenes 0xA3 and 0xAC and Mayahem Temple's character parade (0x167); that
// is skipped too (L's sweeps of 2026-11-07).
//
// The intro cutscenes (0xA1 to 0xAA) hold each scene, in glintrosyncDll_entrypoint_1, until a clock
// that started with the intro reaches that scene's cue in the intro music (a table of map and
// seconds: 0xA2 at 118 s). The sweep leaves each scene after a few seconds, so the next scene sat
// waiting for the clock (45.6 s in L's hang of 2026-10-17 09:24:52, and the performance sweep's hang
// of 2026-11-07 00:57:26). While a texture sweep runs, or when the scene was entered by a warp, the
// wait is skipped.
//
// Tower of Tragedy's quiz (0x15F) sets up its contestant in func_80800F34_chquiz: it finds the
// player slot (func_800A9478, -1 when the player it asks for is not in the table) and passes it to
// func_800F5EF8, which reads the slot's object; with -1 that read address 0 (L's sweep crash of
// 2026-10-16 15:55:17, the reason 0x15F was skipped). Entered by a warp, the slot can also be found
// with no player object in it yet, and func_800A4C88 read address 0x184, followed by a run of null
// reads and writes in ncpod and ncpoducam (L's sweeps of 2026-11-07). With no slot found, or an empty
// one, the setup is left out.
//
// TOOIE_CUTSCENE_GUARDS=0 turns them all off, to see the crash or the wait again in a headless run.

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <string>

#include "recomp.h"
#include "tooie_debug.h"
#include "tooie_hooks.h"
#include "tooie_texture_sweep.h"

namespace {
    bool guards_on() {
        static const bool on = [] {
            const char* env = std::getenv("TOOIE_CUTSCENE_GUARDS");
            return !(env && std::strcmp(env, "0") == 0);
        }();
        return on;
    }

    // D_80135490: the player objects, one word a player slot (func_800F5EF8 reads it).
    constexpr uint32_t players_address = 0x80135490;
}

extern "C" int tooie_chanim_missing(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    if (ctx->r2 != 0 || !guards_on()) {
        return 0;
    }
    static int logged = 0;
    if (logged < 5) {
        logged++;
        std::fprintf(stderr, "[guard] an actor had no animation to free (chanim_entrypoint_6), skipped\n");
    }
    return 1;
}

extern "C" int tooie_null_slot(uint8_t* rdram, gpr slot, const char* where) {
    (void)rdram;
    if (slot != 0 || !guards_on()) {
        return 0;
    }
    static std::set<std::string> logged;
    if (logged.insert(where).second) {
        std::fprintf(stderr, "[guard] %s: an actor had no data to free, skipped\n", where);
    }
    return 1;
}

extern "C" int tooie_intro_sync_skip(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    const bool sweep = tooie::texture_sweep::sweeping();
    if (!guards_on() || !(sweep || tooie::debug::entered_by_warp())) {
        return 0;
    }
    static uint16_t logged_map = 0xFFFF;
    const uint16_t map = tooie::debug::current_map(rdram);
    if (map != logged_map) {
        logged_map = map;
        std::fprintf(stderr, "[guard] intro scene 0x%X's wait for the music cue skipped (%s)\n", (unsigned)map,
            sweep ? "texture sweep" : "entered by a warp");
    }
    return 1;
}

extern "C" int tooie_quiz_no_player(uint8_t* rdram, recomp_context* ctx) {
    if (!guards_on()) {
        return 0;
    }
    const int32_t slot = (int32_t)ctx->r2;
    if (slot < 0) {
        std::fprintf(stderr, "[guard] quiz: no player slot found for its contestant, setup skipped\n");
        return 1;
    }
    // A slot can be found while its player object (D_80135490[slot], the pointer func_800F5EF8 reads)
    // is not there yet: entered by a warp, the slot is empty for the quiz's first frames.
    if (slot < 8 && MEM_W(0, (int32_t)(players_address + (uint32_t)slot * 4)) == 0) {
        static int logged = 0;
        if (logged < 5) {
            logged++;
            std::fprintf(stderr, "[guard] quiz: player slot %d is empty, setup skipped\n", slot);
        }
        return 1;
    }
    return 0;
}

extern "C" int tooie_null_guard(uint8_t* rdram, recomp_context* ctx, const char* where) {
    (void)rdram;
    if (ctx->r2 != 0 || !guards_on()) {
        return 0;
    }
    static std::set<std::string> logged;
    if (logged.insert(where).second) {
        std::fprintf(stderr, "[guard] %s: the game got no object and would have read through null, skipped\n", where);
    }
    return 1;
}
