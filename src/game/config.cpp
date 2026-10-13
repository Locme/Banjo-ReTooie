#include <filesystem>

#include "tooie_game.h"
#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "librecomp/game.hpp"
#include "tooie_cheats.h"
#include "tooie_discord.h"
#include "tooie_level_warp.h"
#include "tooie_speedup.h"

void tooie::init_config() {
    std::filesystem::path app_dir = recomp::get_config_path();
    if (!app_dir.empty()) {
        std::filesystem::create_directories(app_dir);
    }

    recompui::config::GeneralTabOptions general_options{};
    general_options.has_rumble_strength = true;
    general_options.has_gyro_sensitivity = false;
    general_options.has_mouse_sensitivity = false;
    auto& general = recompui::config::create_general_tab(general_options);
    general.add_bool_option(
        tooie::save_backups_option,
        "Back up saves",
        "Copies your save file into the save_backups folder whenever it changes.",
        true);
    general.add_bool_option(
        tooie::discord::presence_option,
        "Discord status",
        "Shows the level you are playing in your Discord status while Discord is running.",
        true);
    general.add_number_option(
        tooie::save_backups_keep_option,
        "Save backups to keep",
        "How many of the newest save backups to keep.",
        1, 100, 1, 0, false, 10);
    general.add_enum_option(
        tooie::timer_save_option,
        "Timer save",
        "Saves the game by itself after this much play time in a level. Pauses, menus and cutscenes do not count, and a save never happens during them.",
        {
            {tooie::TimerSave::Off, "Off", "Off"},
            {tooie::TimerSave::Minutes5, "5", "5 min"},
            {tooie::TimerSave::Minutes10, "10", "10 min"},
            {tooie::TimerSave::Minutes30, "30", "30 min"},
            {tooie::TimerSave::Minutes60, "60", "60 min"},
            {tooie::TimerSave::Minutes120, "120", "120 min"},
        },
        tooie::TimerSave::Off);
    general.add_number_option(
        tooie::speedup::factor_option,
        "Speed-up factor",
        "How much faster the game runs while the speed-up key (F2) is active.",
        2, 4, 1, 0, false, 3);
    general.add_bool_option(
        tooie::speedup::toggle_option,
        "Speed-up toggle",
        "Press F2 to switch the speed-up on and off instead of holding it.",
        false);

    recomp::config::Config& qol = recompui::config::create_config_tab("QOL", tooie::qol_tab_id, false);
    qol.add_bool_option(
        tooie::quick_start_option,
        "Press Start Early in Intro",
        "Press Start during the logos and title flight to go straight to the file select.",
        true);
    qol.add_enum_option(
        tooie::text_speed_option,
        "Text speed",
        "How fast dialogue text prints. <recomp-color primary>Instant</recomp-color> shows each page at once. Menus are not affected.",
        {
            {tooie::TextSpeed::Normal, "Normal", "1x"},
            {tooie::TextSpeed::Double, "Double", "2x"},
            {tooie::TextSpeed::Quadruple, "Quadruple", "4x"},
            {tooie::TextSpeed::Instant, "Instant", "Instant"},
        },
        tooie::TextSpeed::Normal);
    qol.add_enum_option(
        tooie::transition_speed_option,
        "Level transitions",
        "How fast the screen wipe plays when you go to another area. <recomp-color primary>Fast</recomp-color> is 4x, <recomp-color primary>Instant</recomp-color> is 16x. Cutscene fades are not affected.",
        {
            {tooie::TransitionSpeed::Original, "Original", "Original"},
            {tooie::TransitionSpeed::Fast, "Fast", "Fast"},
            {tooie::TransitionSpeed::Instant, "Instant", "Instant"},
        },
        tooie::TransitionSpeed::Original);

    recompui::config::create_graphics_tab();
    recompui::config::create_controls_tab();
    recompui::config::create_sound_tab();
    tooie::cheats::create_tab();
    tooie::level_warp::create_tab();
    recompui::config::create_mods_tab();

    recompui::config::finalize();
}
