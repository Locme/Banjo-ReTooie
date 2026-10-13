#ifndef __TOOIE_GAME_H__
#define __TOOIE_GAME_H__

#include <cstdint>
#include <string>
#include <filesystem>

#include "recomp.h"

namespace tooie {
    inline const std::u8string program_id = u8"BanjoTooieN64Recomp";
    inline const std::string program_name = "Banjo-Tooie N64 Recomp";

    // Registers the recompiled code sections with the runtime (register_overlays.cpp).
    void register_overlays();

    // Called by the runtime when the game starts, before the entrypoint runs.
    void start_debug_watch(uint8_t* rdram);
    void on_game_init(uint8_t* rdram, recomp_context* ctx);

    // Overlay bookkeeping (overlays.cpp). The game numbers overlays from 1.
    bool overlay_section(uint32_t overlay_index, uint32_t& rom_addr, uint32_t& size);

    // Settings (config.cpp).
    void init_config();

    // App-data root (app_data.cpp): the exe's folder when writable (migrating the old per-user
    // folder once), else the runtime's default location.
    std::filesystem::path resolve_app_folder();
}

#endif
