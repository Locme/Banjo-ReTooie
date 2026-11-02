#ifndef __TOOIE_SAVE_STATE_H__
#define __TOOIE_SAVE_STATE_H__

#include <cstdint>
#include <filesystem>
#include <string>

#include "recomp.h"
#include "librecomp/config.hpp"

// Save states (handoff 4.14, src/gameplay/save_state.cpp): the Save State key (Insert) keeps one
// snapshot of the game in memory, and the Load State key (Home) goes back to it. In a level only;
// lost when the game closes.
namespace tooie::save_state {
    // Names the two keys and sets their default bindings (before the controls config loads).
    void register_input();

    // Starts the thread that watches the keys.
    void start();

    // Once per frame on the game thread (tooie_warp_tick): takes or restores the snapshot.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // Freeze (the Freeze key, src/debug/interp_check.cpp): holds the game on
    // two game frames, put back every two frames, so the blend mode can be switched on a still scene.
    // In a level only; a map change or Load State ends it (freeze_on() then reads false).
    void set_freeze(bool on);
    // Same as the Save State / Load State keys, for the developer console. Taken on the next game frame; a load
    // with no snapshot kept does nothing.
    void request_save();
    void request_load();
    bool freeze_on();
    // True while the game is actually being held (sound is muted).
    bool frozen();

    // DEV > RAM dump with screenshots: each screenshot (F12) also writes the game's memory next to it, for
    // finding out why something got stuck on a player's machine.
    inline const std::string ram_dump_option = "ram_dump_with_screenshots";
    void add_ram_dump_option(recomp::config::Config& wip);
    bool ram_dump_on();
    // Writes RDRAM (16 MB, big-endian words as the game sees them) to path at the start of the next game frame.
    void request_ram_dump(const std::filesystem::path& path);
}

#endif
