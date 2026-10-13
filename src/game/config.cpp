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
#include "tooie_talon_trot.h"
#include "tooie_canary_mary.h"
#include "tooie_frame_overlay.h"
#include "tooie_picture_filters.h"
#include "tooie_speedup.h"

void tooie::init_config() {
    // Before finalize(), which loads the controls config and with it the hotkey bindings.
    tooie::speedup::register_input();
    tooie::input::register_input();

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
    qol.add_bool_option(
        tooie::draw_distance_option,
        "Extended draw distance",
        "Keeps characters and objects that are already loaded drawn much further away than the original.",
        false);
    qol.add_enum_option(
        tooie::talon_trot::mode_option,
        "Talon Trot",
        "<recomp-color primary>Toggle</recomp-color>: once Z + C-left starts the trot, Banjo keeps trotting after you let go of Z. Press Z or C-left to stop. <recomp-color primary>Hold</recomp-color> is the original: hold Z to keep trotting.",
        {
            {tooie::talon_trot::Mode::Hold, "Hold", "Hold"},
            {tooie::talon_trot::Mode::Toggle, "Toggle", "Toggle"},
        },
        tooie::talon_trot::Mode::Toggle);
    qol.add_enum_option(
        tooie::canary_mary::mode_option,
        "Canary Mary races",
        "<recomp-color primary>Fair</recomp-color>: Canary Mary never speeds up past her normal pace to catch you when you lead. <recomp-color primary>Easy</recomp-color> is Fair with her pace at 85%. <recomp-color primary>Original</recomp-color> keeps her catch-up. She still slows down when you fall behind, as in the original.",
        {
            {tooie::canary_mary::Mode::Original, "Original", "Original"},
            {tooie::canary_mary::Mode::Fair, "Fair", "Fair"},
            {tooie::canary_mary::Mode::Easy, "Easy", "Easy"},
        },
        tooie::canary_mary::Mode::Fair);
    qol.add_number_option(
        tooie::fov_offset_option,
        "Field of view",
        "Degrees added to the normal gameplay camera's field of view. Higher shows more around Banjo.",
        -10, 30, 1, 0, false, 0);
    qol.add_number_option(
        tooie::cutscene_fov_offset_option,
        "Cutscene field of view",
        "Degrees added to the field of view in cutscenes and the game's fixed cameras (bosses, some puzzles).",
        -10, 20, 1, 0, false, 0);
    qol.add_bool_option(
        tooie::cutscene_skip_option,
        "Skip boss intros",
        "Press B during a boss's intro cutscene to fast-forward through it and its dialogue to the fight.",
        true);

    recomp::config::Config& graphics = recompui::config::create_graphics_tab();
    tooie::picture_filters::add_options(graphics);
    graphics.add_bool_option(
        tooie::high_detail_models_option,
        "Always High-Detail Models",
        "Models that switch to a simpler version far away always use the detailed one.",
        true);
    tooie::frame_overlay::add_option(graphics);

    recompui::config::create_controls_tab();
    recompui::config::create_sound_tab();
    tooie::cheats::create_tab();
    tooie::level_warp::create_tab();
    recompui::config::create_mods_tab();

    recompui::config::finalize();
    tooie::picture_filters::apply();
}
