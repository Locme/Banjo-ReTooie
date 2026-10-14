#ifndef __TOOIE_TEST_ROOM_H__
#define __TOOIE_TEST_ROOM_H__

#include <cstdint>

#include "recomp.h"

// Test room (src/gameplay/test_room.cpp): a Warp tab entry that warps to a quiet area and lines up the game's
// characters, enemies, transformations and objects in rows in front of Banjo.
namespace tooie::test_room {
    // The area the test room uses, for the Warp tab entry.
    constexpr uint16_t map = 0x15C;
    constexpr uint8_t exit = 0;

    // Fills the room after the next load of its area (or at once if Banjo is already there).
    void request();

    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
