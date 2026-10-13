#include <filesystem>

#include "tooie_game.h"
#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "librecomp/game.hpp"
#include "tooie_cheats.h"
#include "tooie_discord.h"
#include "tooie_free_camera.h"
#include "tooie_level_warp.h"
#include "tooie_tiptoe.h"
#include "tooie_speedup.h"

void tooie::init_config() {
    // Before finalize(), which loads the controls config and with it the hotkey bindings.
    tooie::speedup::register_input();

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
    qol.add_bool_option(
        tooie::high_detail_models_option,
        "High-detail models",
        "Models that switch to a simpler version far away always use the detailed one.",
        true);
    qol.add_bool_option(
        tooie::free_camera_option,
        "Free camera",
        "The right stick turns the camera smoothly around Banjo and tilts it, instead of the game's stepped camera swings. The camera stays where you turned it until a cutscene or another area.",
        true);
    qol.add_enum_option(
        tooie::free_camera_speed_option,
        "Free camera speed",
        "How fast the right stick turns the free camera.",
        {
            {tooie::FreeCameraSpeed::Slow, "Slow", "Slow"},
            {tooie::FreeCameraSpeed::Normal, "Normal", "Normal"},
            {tooie::FreeCameraSpeed::Fast, "Fast", "Fast"},
        },
        tooie::FreeCameraSpeed::Normal);
    qol.add_bool_option(
        tooie::free_camera_invert_x_option,
        "Free camera: invert left/right",
        "Reverses which way the right stick turns the free camera.",
        false);
    qol.add_bool_option(
        tooie::free_camera_invert_y_option,
        "Free camera: invert up/down",
        "Reverses which way the right stick tilts the free camera.",
        false);
    for (const std::string* id : { &tooie::free_camera_speed_option, &tooie::free_camera_invert_x_option,
                                   &tooie::free_camera_invert_y_option }) {
        qol.add_option_hidden_dependency(*id, tooie::free_camera_option, false);
    }
    qol.add_enum_option(
        tooie::input::tiptoe_option,
        "Tiptoe button",
        "Hold this button to tiptoe at any stick tilt. <recomp-color primary>B</recomp-color> is hidden from the game while held; a quick tap still counts as B.",
        {
            {tooie::input::TiptoeButton::Off, "Off", "Off"},
            {tooie::input::TiptoeButton::B, "B", "B"},
            {tooie::input::TiptoeButton::LeftStick, "Left stick click", "Left stick click"},
            {tooie::input::TiptoeButton::RightStick, "Right stick click", "Right stick click"},
        },
        tooie::input::TiptoeButton::B);

    recompui::config::create_graphics_tab();
    recompui::config::create_controls_tab();
    recompui::config::create_sound_tab();
    tooie::cheats::create_tab();
    tooie::level_warp::create_tab();
    recompui::config::create_mods_tab();

    recompui::config::finalize();
}
