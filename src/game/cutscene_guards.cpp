// Guards for cutscenes entered straight from another map, as the texture sweep and the warps do.
//
// chanim_entrypoint_6 frees an actor's animation (the actor's data slot 0, from func_80100094). The
// intro characters (chintrochar) in Banjo's house is destroyed (0xAC) and All Jinjos Happy Again
// (0x199) call it on leaving the map even when they never got an animation, which the earlier intro
// scenes set up when the cutscenes are watched in order. The slot is then null and the game read
// address 0 (L's crash of 2026-10-17 09:29:58, and the 0xAC crash the sweep used to skip). With
// nothing there is nothing to free, so the guard returns early.
//
// The intro cutscenes (0xA1 to 0xAA) hold each scene, in glintrosyncDll_entrypoint_1, until a clock
// that started with the intro reaches that scene's cue in the intro music (a table of map and
// seconds: 0xA2 at 118 s). The sweep leaves each scene after a few seconds, so the next scene sat
// waiting for the clock (45.6 s in L's hang of 2026-10-17 09:24:52). While a sweep runs the wait is
// skipped.
//
// Tower of Tragedy's quiz (0x15F) sets up its contestant in func_80800F34_chquiz: it finds the
// player slot (func_800A9478, -1 when the player it asks for is not in the table) and passes it to
// func_800F5EF8, which reads the slot's object; with -1 that read address 0 (L's sweep crash of
// 2026-10-16 15:55:17, the reason 0x15F was skipped). With no slot found the setup is left out.
//
// TOOIE_CUTSCENE_GUARDS=0 turns them all off, to see the crash or the wait again in a headless run.

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <string>

#include "recomp.h"
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

extern "C" int tooie_intro_sync_skip(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
    if (!guards_on() || !tooie::texture_sweep::sweeping()) {
        return 0;
    }
    std::fprintf(stderr, "[guard] intro scene's wait for the music cue skipped (texture sweep)\n");
    return 1;
}

extern "C" int tooie_quiz_no_player(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    if (SIGNED(ctx->r2) >= 0 || !guards_on()) {
        return 0;
    }
    std::fprintf(stderr, "[guard] quiz: no player slot found for its contestant, setup skipped\n");
    return 1;
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
