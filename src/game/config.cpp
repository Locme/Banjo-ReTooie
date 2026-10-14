#include <filesystem>
#include <fstream>

#include <json/json.hpp>

#include "tooie_game.h"
#include "tooie_classic_sounds.h"
#include "tooie_music_player.h"
#include "tooie_control_scheme.h"
#include "tooie_photo_mode.h"
#include "tooie_bottles_revenge.h"
#include "tooie_save_state.h"
#include "tooie_honeycomb_glitter.h"
#include "tooie_jiggy_dance.h"
#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "librecomp/game.hpp"
#include "tooie_cheats.h"
#include "tooie_discord.h"
#include "tooie_free_camera.h"
#include "tooie_level_warp.h"
#include "tooie_tiptoe.h"
#include "tooie_talon_trot.h"
#include "tooie_hold_to_run.h"
#include "tooie_canary_mary.h"
#include "tooie_game_frame_rate.h"
#include "tooie_frame_overlay.h"
#include "tooie_fine_aim.h"
#include "tooie_motion_aim.h"
#include "tooie_picture_filters.h"
#include "tooie_smaa.h"
#include "tooie_api_restart.h"
#include "tooie_speedup.h"
#include "tooie_achievements.h"
#include "tooie_fxaa.h"

namespace {
    void show_wip_tab() {
        bool on = false;
        try {
            on = std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::wip_tab_option));
        } catch (...) {
        }
        try {
            recompui::config::set_tab_visible(tooie::wip_tab_id, on);
        } catch (...) {
        }
    }

    // Discord status moved from General to WIP: carry a saved value over once.
    void move_saved_discord_option() {
        const std::filesystem::path dir = recomp::get_config_path();
        if (std::filesystem::exists(dir / (tooie::wip_tab_id + ".json"))) {
            return;
        }
        std::ifstream general_file(dir / "general.json");
        if (!general_file) {
            return;
        }
        nlohmann::json general_json = nlohmann::json::parse(general_file, nullptr, false);
        if (!general_json.is_object() || !general_json.contains(tooie::discord::presence_option) ||
            !general_json[tooie::discord::presence_option].is_boolean()) {
            return;
        }
        recomp::config::Config& wip = recompui::config::get_config(tooie::wip_tab_id);
        wip.set_option_value(tooie::discord::presence_option, general_json[tooie::discord::presence_option].get<bool>());
        wip.save_config();
    }

    // Options that moved from the QOL tab to Graphics (L, 2026-10-13): carry a value saved in qol.json
    // over once, unless graphics.json already has one. Extended draw distance is not carried over, so
    // it starts off after its fix whatever the broken first version saved.
    void move_saved_options_to_graphics() {
        const std::filesystem::path dir = recomp::get_config_path();
        std::ifstream qol_file(dir / "qol.json");
        if (!qol_file) {
            return;
        }
        nlohmann::json qol_json = nlohmann::json::parse(qol_file, nullptr, false);
        if (!qol_json.is_object()) {
            return;
        }
        nlohmann::json graphics_json;
        if (std::ifstream graphics_file(dir / "graphics.json"); graphics_file) {
            graphics_json = nlohmann::json::parse(graphics_file, nullptr, false);
        }
        recomp::config::Config& graphics = recompui::config::get_graphics_config();
        bool changed = false;
        for (const std::string* id : { &tooie::high_detail_models_option, &tooie::fov_offset_option,
                                       &tooie::cutscene_fov_offset_option }) {
            if (!qol_json.contains(*id) || (graphics_json.is_object() && graphics_json.contains(*id))) {
                continue;
            }
            const nlohmann::json& value = qol_json[*id];
            if (value.is_boolean()) {
                graphics.set_option_value(*id, value.get<bool>());
            } else if (value.is_number()) {
                graphics.set_option_value(*id, value.get<double>());
            } else {
                continue;
            }
            changed = true;
        }
        if (changed) {
            graphics.save_config();
        }
    }
}

void tooie::init_config() {
    // Before finalize(), which loads the controls config and with it the hotkey bindings.
    tooie::speedup::register_input();
    tooie::frame_overlay::register_input();
    tooie::input::register_input();
    tooie::hold_to_run::register_input();
    tooie::photo_mode::register_input();
    tooie::save_state::register_input();

    std::filesystem::path app_dir = recomp::get_config_path();
    if (!app_dir.empty()) {
        std::filesystem::create_directories(app_dir);
    }

    recompui::config::GeneralTabOptions general_options{};
    general_options.has_rumble_strength = true;
    // Mouse and gyro aiming in first person (src/input/motion_aim.cpp).
    general_options.has_gyro_sensitivity = true;
    general_options.has_mouse_sensitivity = true;
    auto& general = recompui::config::create_general_tab(general_options);
    general.add_bool_option(
        tooie::save_backups_option,
        "Back up saves",
        "Copies your save file into the save_backups folder whenever it changes.",
        true);
    general.add_bool_option(
        tooie::wip_tab_option,
        "WIP tab",
        "Shows the WIP tab, with features that are still being worked on.",
        false);
    general.add_option_change_callback(tooie::wip_tab_option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext) {
            show_wip_tab();
        });
    general.add_bool_option(
        tooie::classic_sounds::option,
        "Back-Port: Old Banjo sounds",
        "Banjo-Kazooie's jump sounds instead of Banjo-Tooie's.",
        false);
    general.add_bool_option(
        tooie::honeycomb_glitter::option,
        "Back-Port: Glittering honeycombs",
        "Health honeycombs sparkle like they did in Banjo-Kazooie.",
        false);
    general.add_bool_option(
        tooie::jiggy_dance::option,
        "Back-Port: Get Jiggy animation",
        "Banjo does Banjo-Kazooie's jiggy dance when he collects a Jiggy.",
        false);
    tooie::control_scheme::add_option(general);
    tooie::bottles_revenge::add_option(general);
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
        tooie::cutscene_skip_option,
        "Skip boss intros",
        "Press B during a boss's intro cutscene to fast-forward through it and its dialogue to the fight.",
        true);
    qol.add_bool_option(
        tooie::cutscene_skip_other_option,
        "Skip other cutscenes",
        "Press B during any other cutscene to fast-forward through it and its dialogue. This includes conversations, so a stray B skips them.",
        false);
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
    qol.add_bool_option(
        tooie::photo_mode_collision_option,
        "Photo mode camera collision",
        "In photo mode (F10) the camera stops at the ground and slides along walls. Off lets it fly through everything.",
        true);
    tooie::photo_mode::add_options(qol);
    for (const std::string* id : { &tooie::free_camera_speed_option, &tooie::free_camera_invert_x_option,
                                   &tooie::free_camera_invert_y_option }) {
        qol.add_option_hidden_dependency(*id, tooie::free_camera_option, false);
    }
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
    qol.add_enum_option(
        tooie::fine_aim::mode_option,
        "Fine aim",
        "Turns the first-person view (C-up) slower with the left stick, for aiming eggs. <recomp-color primary>Hold R</recomp-color> slows it only while R is held.",
        {
            {tooie::fine_aim::Mode::Off, "Off", "Off"},
            {tooie::fine_aim::Mode::HoldR, "Hold R", "Hold R"},
            {tooie::fine_aim::Mode::Always, "Always", "Always"},
        },
        tooie::fine_aim::Mode::Off);
    qol.add_enum_option(
        tooie::fine_aim::speed_option,
        "Fine aim speed",
        "How fast the view turns with fine aim: 25%, 40% or 60% of the normal speed.",
        {
            {tooie::fine_aim::Speed::Slow, "Slow", "25%"},
            {tooie::fine_aim::Speed::Medium, "Medium", "40%"},
            {tooie::fine_aim::Speed::Fast, "Fast", "60%"},
        },
        tooie::fine_aim::Speed::Medium);
    qol.add_option_hidden_dependency(tooie::fine_aim::speed_option, tooie::fine_aim::mode_option, tooie::fine_aim::Mode::Off);
    tooie::motion_aim::add_options(qol);

    // Section headings in the QOL tab (the options of a group sit next to each other above).
    recompui::config::set_option_group(tooie::quick_start_option, "Speed and skipping");
    recompui::config::set_option_group(tooie::free_camera_option, "Camera");
    recompui::config::set_option_group(tooie::talon_trot::mode_option, "Moves and aiming");

    recomp::config::Config& graphics = recompui::config::create_graphics_tab();
    tooie::picture_filters::add_options(graphics);
    graphics.add_bool_option(
        tooie::high_detail_models_option,
        "Always High-Detail Models",
        "Models that switch to a simpler version far away always use the detailed one. Banjo always uses his close-up model (with his necklace).",
        true);
    graphics.add_bool_option(
        tooie::hd_shadows_option,
        "HD Shadows",
        "The player's shadow is shaped like the full model on screen, with its pose, instead of the game's simpler shadow model.",
        false);
    tooie::frame_overlay::add_option(graphics);
    tooie::game_frame_rate::add_option(graphics);
    graphics.add_bool_option(
        tooie::draw_distance_option,
        "Extended Draw Distance",
        "Keeps characters and objects that are already loaded drawn much further away than the original.",
        false);
    graphics.add_number_option(
        tooie::fov_offset_option,
        "Field of View",
        "Degrees added to the normal gameplay camera's field of view. Higher shows more around Banjo.",
        -10, 30, 1, 0, false, 0);
    graphics.add_number_option(
        tooie::cutscene_fov_offset_option,
        "Cutscene Field of View",
        "Degrees added to the field of view in cutscenes and the game's fixed cameras (bosses, some puzzles).",
        -10, 20, 1, 0, false, 0);
    tooie::smaa::add_option(graphics);
    tooie::fxaa::add_option(graphics);
    tooie::api_restart::add_prompt(graphics);

    recompui::config::create_controls_tab();
    tooie::music_player::add_options(recompui::config::create_sound_tab());
    tooie::cheats::create_tab();
    tooie::level_warp::create_tab();
    tooie::achievements::create_tab();
    recompui::config::create_mods_tab();

    // Work-in-progress features (L, 2026-10-13), shown with General > WIP tab.
    recomp::config::Config& wip = recompui::config::create_config_tab("WIP", tooie::wip_tab_id, false);
    wip.add_bool_option(
        tooie::discord::presence_option,
        "Discord status",
        "Shows the level you are playing in your Discord status while Discord is running.",
        true);

    recompui::config::finalize();
    move_saved_options_to_graphics();
    show_wip_tab();
    move_saved_discord_option();
    tooie::picture_filters::apply();
    tooie::smaa::apply();
    tooie::fxaa::apply();
}
