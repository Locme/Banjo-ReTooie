#ifndef __TOOIE_MENU_PORTRAITS_H__
#define __TOOIE_MENU_PORTRAITS_H__

#include <cstdint>
#include <string>
#include <vector>

#include "recomp.h"

// The talking-head portraits of the game's Start menu rows on the Esc menu's tabs (src/ui/menu_portraits.cpp,
// 2026-11-12). The game draws them from sprites in the ROM; these are decoded to pictures for the menu.
namespace tooie::menu_portraits {
    // Call each game frame from the game thread (tooie_warp_tick): once the game runs, finds each tab's
    // portrait sprite, decodes it and hands the pictures to the menu, a texture pack's picture for a frame where
    // one replaces it; again whenever the texture packs in use change.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // A portrait (an id in gczoomboxdata's table) as a picture, RGBA, its first frame. False when it can't be
    // read. Game thread: the table is asked through the game.
    bool decode(uint8_t* rdram, recomp_context* ctx, int portrait, std::vector<uint8_t>& rgba, int& width, int& height);

    // Writes every portrait from 0 to `last` to Dev Files/portraits as PNGs (and the raw sprites), for picking
    // them (console `portraits dump`). Game thread. Returns how many were written.
    int dump(uint8_t* rdram, recomp_context* ctx, int last, std::string& folder);

    // A portrait's voice: the sounds its character's dialogue chatters with (gczoomboxdata's table, up to five),
    // each a sound id, the volume and the pitch the dialogue box plays it at. Game thread.
    struct Voice {
        int32_t sound;
        int32_t volume;
        float pitch;
    };
    std::vector<Voice> voices(uint8_t* rdram, recomp_context* ctx, int portrait);
    // Plays one of a portrait's voice sounds, picked at random (console `portraits voice`). Game thread. False when
    // it has none, or there is no player to play it on.
    bool speak(uint8_t* rdram, recomp_context* ctx, int portrait);
    // Each tab's portrait frames' RT64 hashes (the still frame and the blink's), as texture packs know them, and
    // which a texture pack in use replaces (console `portraits hashes`). Game thread.
    std::vector<std::string> hashes();

    // Another tab was picked in the Esc menu (L, 2026-11-12: "Banjo tab = Banjo sound"): its character speaks on the
    // next game frame. Any thread. False for a tab with no portrait.
    bool tab_voice(const std::string& tab_id);
}

#endif
