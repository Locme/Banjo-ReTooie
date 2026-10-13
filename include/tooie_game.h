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

    // How much wider than 4:3 RT64 draws the picture: 1 unless Aspect Ratio is
    // Expand and the window is wider than 4:3 (widescreen.cpp).
    float widescreen_scale();

    // Settings (config.cpp).
    void init_config();

    // App-data root (app_data.cpp): the exe's folder when writable (migrating the old per-user
    // folder once), else the runtime's default location.
    std::filesystem::path resolve_app_folder();

    // Save backups (save_backup.cpp): at launch and every 120 s, copies the save file to
    // save_backups/<date-time>/ if it changed, keeping the newest N (General tab settings).
    inline const std::string save_backups_option = "save_backups";
    inline const std::string save_backups_keep_option = "save_backups_keep";
    void start_save_backups();

    // Quick start (quick_start.cpp): Start during the boot logos goes to the file select.
    inline const std::string qol_tab_id = "qol";
    inline const std::string quick_start_option = "quick_start";
    void quick_start_note_input(uint16_t buttons);
    void quick_start_tick(uint8_t* rdram);

    // Dialogue text speed (src/gameplay/dialogue_speed.cpp).
    enum class TextSpeed : uint32_t { Normal, Double, Quadruple, Instant };
    inline const std::string text_speed_option = "dialogue_text_speed";
    // --dialogue_text_speed 1|2|4|instant; overrides the setting. False if the value is unknown.
    bool parse_text_speed_arg(const char* value);

    // Unpacks RT64 texture packs dropped into the mods folder as a .zip (src/game/mod_zips.cpp).
    void unpack_mod_zips();

    // Timer save (src/game/timer_save.cpp): saves every N minutes of play. Called each frame from tooie_warp_tick.
    enum class TimerSave : uint32_t { Off, Minutes5, Minutes10, Minutes30, Minutes60, Minutes120 };
    inline const std::string timer_save_option = "timer_save";
    void timer_save_tick(uint8_t* rdram, recomp_context* ctx);

    // Level transition speed (src/gameplay/fast_transitions.cpp).
    enum class TransitionSpeed : uint32_t { Original, Fast, Instant };
    inline const std::string transition_speed_option = "transition_speed";

    // High-detail models always (src/gameplay/high_detail_models.cpp), QOL tab.
    inline const std::string high_detail_models_option = "high_detail_models";

    // Crash handler (crash_handler.cpp): writes logs/crashes.log (plus a minidump on Windows) when the
    // game crashes, and keeps logs/running.marker so a silent death is flagged at the next start.
    void install_crash_handler(const std::filesystem::path& app_folder);
}

#endif
