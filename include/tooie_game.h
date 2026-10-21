#ifndef __TOOIE_GAME_H__
#define __TOOIE_GAME_H__

#include <cstdint>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <vector>

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
    // Where each overlay's code is mapped, by overlay index (save states keep and restore it).
    std::unordered_map<uint32_t, int32_t> mapped_overlays();
    void set_mapped_overlays(const std::unordered_map<uint32_t, int32_t>& overlays);

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
    // The Performance tab (a page of Graphics options, recompui::config::create_page_tab).
    inline const std::string performance_tab_id = "performance";
    inline const std::string quick_start_option = "quick_start";
    void quick_start_note_input(uint16_t buttons);
    void quick_start_tick(uint8_t* rdram);

    // Dialogue text speed (src/gameplay/dialogue_speed.cpp).
    enum class TextSpeed : uint32_t { Normal, Double, Quadruple, Instant };
    inline const std::string text_speed_option = "dialogue_text_speed";
    // --dialogue_text_speed 1|2|4|instant; overrides the setting. False if the value is unknown.
    bool parse_text_speed_arg(const char* value);

    // Unpacks RT64 texture packs and asset mods dropped into the mods folder as a .zip (src/game/mod_zips.cpp).
    // Runs before each mod scan. With new_only (a refresh after the game started) a zip is only unpacked
    // when it has no folder yet, so a loaded mod's files are never swapped out under it. With at_boot (the
    // scan at startup, before the renderer exists) the window shows "Installing Mods" while a zip unpacks.
    void unpack_mod_zips(bool new_only = false, bool at_boot = false);

    // Timer save (src/game/timer_save.cpp): saves every N minutes of play. Called each frame from tooie_warp_tick.
    enum class TimerSave : uint32_t { Off, Minutes5, Minutes10, Minutes30, Minutes60, Minutes120 };
    inline const std::string timer_save_option = "timer_save";
    void timer_save_tick(uint8_t* rdram, recomp_context* ctx);

    // Level transition speed (src/gameplay/fast_transitions.cpp).
    enum class TransitionSpeed : uint32_t { Original, Fast, Instant };
    inline const std::string transition_speed_option = "transition_speed";

    // High-detail models always (src/gameplay/high_detail_models.cpp), QOL tab.
    inline const std::string high_detail_models_option = "high_detail_models";
    // HD shadows (src/gameplay/hd_shadows.cpp), Graphics tab.
    inline const std::string hd_shadows_option = "hd_shadows";
    // DEV tab, formerly WIP (src/game/config.cpp): its id, and the General toggle that shows it
    // (Developer Mode).
    inline const std::string wip_tab_id = "wip";
    inline const std::string wip_tab_option = "wip_tab";
    // WIP tab (L, 2026-10-21): player features still being worked on, in a section also named WIP; each
    // moves to its own tab when it is done. (The DEV tab keeps the old "wip" id.)
    inline const std::string work_in_progress_tab_id = "work_in_progress";
    // DEV > Additional Tabs (L, 2026-10-16): the toggles that show the Achievements and Cheats tabs.
    // The Warp tab's toggle is there too (src/game/level_warp.cpp). Cheats tab was in General before.
    inline const std::string achievements_tab_option = "achievements_tab";
    inline const std::string cheats_tab_option = "cheats_tab";
    // DEV > Hide Unnecessary Settings Entry (src/game/hide_vanilla_widescreen.cpp).
    inline const std::string hide_vanilla_widescreen_option = "hide_vanilla_widescreen";
    // Once a frame: keeps the game's own widescreen mode off while that switch is on.
    void vanilla_widescreen_tick(uint8_t* rdram, recomp_context* ctx);
    // The pause menu's Settings page (src/gameplay/pause_settings.cpp opens it as a Totals sub page,
    // src/gameplay/totals_checklist.cpp draws it): the TV's settings, read and set here
    // (src/game/hide_vanilla_widescreen.cpp).
    namespace game_settings {
        constexpr uint8_t pause_sub_page = 0x7D;
        struct Row {
            const char* name;
            const char* value;
        };
        std::vector<Row> rows(uint8_t* rdram, recomp_context* ctx);
        // step: +1 / -1, the next or previous value of row.
        void change(uint8_t* rdram, recomp_context* ctx, size_t row, int step);
    }
    // Extended draw distance (src/display/draw_distance.cpp).
    inline const std::string draw_distance_option = "extended_draw_distance";
    // Field of view offsets in degrees (src/gameplay/field_of_view.cpp), QOL tab.
    inline const std::string fov_offset_option = "fov_offset";
    inline const std::string cutscene_fov_offset_option = "cutscene_fov_offset";
    // True while a letterboxed scene camera is drawing instead of the gameplay camera (field_of_view.cpp).
    bool in_letterboxed_scene();
    // Headless settings script, TOOIE_SET (src/debug/settings_script.cpp).
    void start_settings_script();
    // Headless menu controller presses, TOOIE_MENU_PAD (src/debug/menu_pad.cpp).
    void start_menu_pad_script();
    // Skip cutscenes with Start (src/gameplay/cutscene_skip.cpp), QOL tab.
    inline const std::string cutscene_skip_option = "cutscene_skip_all";
    inline const std::string cutscene_skip_other_option = "cutscene_skip_other";
    void cutscene_skip_tick(uint8_t* rdram);
    // Applies the skip to player 1's buttons as the game reads them (input thread).
    void cutscene_skip_apply(uint16_t* buttons);
    // True while a skip is fast-forwarding (the sound is muted then).
    bool cutscene_skip_active();
    // Starts a skip because Speed-Up was held 3 s; false outside a skippable scene or while skipping.
    bool cutscene_skip_hold_request();

    // Crash handler (crash_handler.cpp): writes logs/crashes.log (plus a minidump on Windows) when the
    // game crashes, and keeps logs/running.marker so a silent death is flagged at the next start.
    // Only the newest 5 minidumps are kept.
    void install_crash_handler(const std::filesystem::path& app_folder);
    // Lines (build, settings) written under every crash entry; see tooie_session_log.h.
    void set_crash_context(const std::string& text);
    // For the hang watchdog (watchdog.cpp). The function and module an address is in, as the crash
    // log writes it (Windows; elsewhere just the address).
    void describe_code_address(void* addr, char* out, size_t size);
    // Writes logs/hang_<time>.dmp with every thread's stack and report_text as its comment, keeping
    // the newest 3. The game's memory (rdram, rdram_size bytes) goes in as an extra stream that
    // tools/read_dump.py --rdram saves. Returns its path, or empty if none was written (always
    // empty off Windows).
    std::string write_hang_dump(const std::string& report_text, const uint8_t* rdram, size_t rdram_size);
    // Appends one line to logs/crashes.log (the pass-over guard's MAJOR lines, memory_guard.cpp).
    void crash_log_line(const char* line);
    // Writes a fatal error that is not a crash (text, one or more lines) to logs/crashes.log with the build
    // and settings, and removes logs/running.marker, since the game is about to close on purpose.
    void log_fatal_error(const std::string& text);
}

#endif
