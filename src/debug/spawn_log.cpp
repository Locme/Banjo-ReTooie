// TOOIE_SPAWN_LOG=1 (headless test aid): logs every object the game spawns by id (func_80108DC0, which the map's
// placed objects come through from gspropsDll as the map loads) and every object it removes
// (func_800FFAB0), so where an enemy goes and when it comes back can be seen.

#include <cstdio>
#include <cstdlib>

#include "recomp.h"
#include "tooie_hooks.h"
#include "tooie_rdram.h"

namespace {
    bool on() {
        static const bool log = std::getenv("TOOIE_SPAWN_LOG") != nullptr;
        return log;
    }
}

// func_80108DC0 entry: $a0 the actor id, $a1 the position (three words; gspropsDll gives whole units).
extern "C" void tooie_spawn_log_spawn(uint8_t* rdram, recomp_context* ctx) {
    if (!on()) {
        return;
    }
    const uint32_t pos = (uint32_t)ctx->r5;
    float p[3] = {};
    if (tooie::rdram::valid_ptr(pos)) {
        for (int i = 0; i < 3; i++) {
            p[i] = float((int32_t)tooie::rdram::read_word(rdram, pos + 4 * i));
        }
    }
    std::printf("[spawnlog] spawn id 0x%03X at %.0f %.0f %.0f\n", (unsigned)(ctx->r4 & 0xFFFF), p[0], p[1], p[2]);
    std::fflush(stdout);
}

// func_800FFAB0 entry: $a0 the object.
extern "C" void tooie_spawn_log_remove(uint8_t* rdram, recomp_context* ctx) {
    if (!on()) {
        return;
    }
    const uint32_t object = (uint32_t)ctx->r4;
    const uint32_t marker = tooie::rdram::valid_ptr(object) ? tooie::rdram::read_word(rdram, object) : 0;
    const unsigned model = tooie::rdram::valid_ptr(marker) ? (unsigned)(tooie::rdram::read_word(rdram, marker + 0x14) >> 16) : 0;
    std::printf("[spawnlog] remove object %08X model %03X entry %08X at %.0f %.0f %.0f\n", object, model,
        tooie::rdram::valid_ptr(object) ? tooie::rdram::read_word(rdram, object + 0x10) : 0,
        tooie::rdram::read_float(rdram, object + 4), tooie::rdram::read_float(rdram, object + 8), tooie::rdram::read_float(rdram, object + 12));
    std::fflush(stdout);
}
