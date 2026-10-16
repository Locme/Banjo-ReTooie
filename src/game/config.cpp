#include <filesystem>
#include <fstream>

#include <json/json.hpp>

#include "tooie_game.h"
#include "tooie_hd_shadows.h"
#include "tooie_day_night.h"
#include "tooie_classic_sounds.h"
#include "tooie_music_player.h"
#include "tooie_mix_rate.h"
#include "tooie_control_scheme.h"
#include "tooie_photo_mode.h"
#include "tooie_bottles_revenge.h"
#include "tooie_boss_rush.h"
#include "tooie_save_state.h"
#include "tooie_honeycomb_glitter.h"
#include "tooie_snout_jiggle.h"
#include "tooie_original_honeycomb.h"
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
#include "tooie_transform_anywhere.h"
#include "tooie_totals_checklist.h"
#include "tooie_canary_mary.h"
#include "tooie_game_frame_rate.h"
#include "tooie_frame_overlay.h"
#include "tooie_fine_aim.h"
#include "tooie_motion_aim.h"
#include "tooie_picture_filters.h"
#include "tooie_smaa.h"
#include "tooie_api_restart.h"
#include "tooie_more_memory.h"
#include "tooie_speedup.h"
#include "tooie_achievements.h"
#include "tooie_fxaa.h"
#include "tooie_low_latency.h"
#include "tooie_frame_readback.h"
#include "tooie_fsr.h"
#include "tooie_effect_views.h"
#include "tooie_hotkeys.h"
#include "tooie_interp_check.h"
#include "tooie_texture_slide.h"
#include "tooie_texture_sweep.h"
#include "tooie_asset_mods.h"

namespace {
    void show_cheats_tab() {
        bool on = true;
        try {
            on = std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(tooie::cheats_tab_option));
        } catch (...) {
        }
        try {
            recompui::config::set_tab_visible("cheats", on);
        } catch (...) {
        }
    }

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

    void show_achievements_tab() {
        bool on = false;
        try {
            on = std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(tooie::achievements_tab_option));
        } catch (...) {
        }
        try {
            recompui::config::set_tab_visible(tooie::achievements::tab_id, on);
        } catch (...) {
        }
    }

    // The Cheats tab switch moved from General, and the Warp tab switch from Cheats, to DEV > Additional
    // Tabs (L, 2026-10-16): carry saved values over once, while the DEV tab's file doesn't have them yet.
    void move_saved_tab_options() {
        const std::filesystem::path dir = recomp::get_config_path();
        nlohmann::json dev_json;
        {
            std::ifstream dev_file(dir / (tooie::wip_tab_id + ".json"));
            if (dev_file) {
                dev_json = nlohmann::json::parse(dev_file, nullptr, false);
            }
        }
        recomp::config::Config& dev = recompui::config::get_config(tooie::wip_tab_id);
        bool changed = false;
        auto carry = [&](const char* file, const std::string& option) {
            if (dev_json.is_object() && dev_json.contains(option)) {
                return;
            }
            std::ifstream old_file(dir / file);
            if (!old_file) {
                return;
            }
            nlohmann::json old_json = nlohmann::json::parse(old_file, nullptr, false);
            if (old_json.is_object() && old_json.contains(option) && old_json[option].is_boolean()) {
                dev.set_option_value(option, old_json[option].get<bool>());
                changed = true;
            }
        };
        carry("general.json", tooie::cheats_tab_option);
        carry("cheats.json", "debug_tab");
        if (changed) {
            dev.save_config();
        }
    }

    // Discord status moved from General to DEV: carry a saved value over once.
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

    // Skip boss intros and Skip other cutscenes became one option (L, 2026-10-16), saved under the boss
    // option's key: someone who had other cutscenes on keeps fast-forwarding them.
    void move_saved_cutscene_skip() {
        std::ifstream qol_file(recomp::get_config_path() / "qol.json");
        if (!qol_file) {
            return;
        }
        nlohmann::json qol_json = nlohmann::json::parse(qol_file, nullptr, false);
        if (!qol_json.is_object() || !qol_json.contains(tooie::cutscene_skip_other_option) ||
            !qol_json[tooie::cutscene_skip_other_option].is_boolean() ||
            !qol_json[tooie::cutscene_skip_other_option].get<bool>()) {
            return;
        }
        recomp::config::Config& qol = recompui::config::get_config(tooie::qol_tab_id);
        qol.set_option_value(tooie::cutscene_skip_option, true);
        qol.save_config();
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

namespace {
    // HUD Placement's default became Expand (L, 2026-10-16: "make it the default Option"), and its
    // label is Expand again after a while as Default. A saved 16:9 from the old default changes to
    // Expand once; picking 16:9 again afterwards stays. Done on the file before the configs load.
    void move_saved_hud_placement() {
        const std::filesystem::path dir = recomp::get_config_path();
        const std::filesystem::path marker = dir / "hud_expand_default.done";
        if (std::filesystem::exists(marker)) {
            return;
        }
        const std::filesystem::path path = dir / "graphics.json";
        nlohmann::json json;
        if (std::ifstream file(path); file) {
            json = nlohmann::json::parse(file, nullptr, false);
        }
        if (json.is_object() && json.contains(recompui::config::graphics::options::hr_option) &&
            json[recompui::config::graphics::options::hr_option] == "Clamp16x9") {
            json[recompui::config::graphics::options::hr_option] = "Expand";
            std::ofstream file(path, std::ios::trunc);
            file << json.dump(4);
        }
        std::ofstream{marker};
    }
}

void tooie::init_config() {
    // Before finalize(), which loads the controls config and with it the hotkey bindings.
    tooie::speedup::register_input();
    tooie::frame_overlay::register_input();
    tooie::input::register_input();
    tooie::hold_to_run::register_input();
    tooie::transform_anywhere::register_input();
    tooie::photo_mode::register_input();
    tooie::save_state::register_input();
    tooie::fine_aim::register_input();
    tooie::hotkeys::register_inputs();

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
    tooie::control_scheme::add_option(general);
    general.add_bool_option(
        tooie::save_backups_option,
        "Back up saves",
        "Copies your save file into the save_backups folder whenever it changes.",
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
        tooie::original_honeycomb::option,
        "Back-Port: Original honeycomb",
        "Health honeycombs use Banjo-Kazooie's honeycomb model, which is still in Banjo-Tooie's files. Switching it in a level reloads the area.",
        false);
    general.add_bool_option(
        tooie::jiggy_dance::option,
        "Back-Port: Get Jiggy animation",
        "Banjo does Banjo-Kazooie's jiggy dance when he collects a Jiggy.",
        false);
    tooie::bottles_revenge::add_option(general);
    tooie::boss_rush::add_option(general);
    general.add_bool_option(
        tooie::snout_jiggle::option,
        "Snout jiggle",
        "Banjo's snout wobbles on a spring as he runs, turns, jumps and lands, like Mario's nose in Super Mario Odyssey. Works with player model mods that keep his skeleton, such as Smash Banjo.",
        false);
    general.add_bool_option(
        tooie::wip_tab_option,
        "Developer Mode",
        "Shows the DEV tab, with features for developers and features that are still being worked on, and the switches for the Achievements, Cheats and Warp tabs.",
        false);
    general.add_option_change_callback(tooie::wip_tab_option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext) {
            show_wip_tab();
        });

    // Section headings in the General tab (the controls and sliders above them have none).
    recompui::config::set_option_group(tooie::save_backups_option, "Saves");
    recompui::config::set_option_group(tooie::classic_sounds::option, "Back-Ports and cut content");
    recompui::config::set_option_group(tooie::boss_rush::option, "Features");
    recompui::config::set_option_group(tooie::wip_tab_option, "Developer");

    recomp::config::Config& qol = recompui::config::create_config_tab("QOL", tooie::qol_tab_id, false);
    qol.add_bool_option(
        tooie::quick_start_option,
        "Press Start Anytime In Intro",
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
    // One option for every cutscene (L, 2026-10-16); it was Skip boss intros plus Skip other cutscenes.
    // Saved under the boss option's key; move_saved_cutscene_skip carries "other cutscenes on" over.
    qol.add_bool_option(
        tooie::cutscene_skip_option,
        "Fast Forward Cutscenes",
        "Press Start during a cutscene, a boss's intro included, to fast-forward through it and its dialogue (Start again stops it). This includes conversations, so a stray Start skips them. The sound is muted while it fast-forwards. The title screen and file select are left alone.",
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
    qol.add_bool_option(
        tooie::hold_to_run::option,
        "Running",
        "Hold the Run key (Controls tab, Movement; not bound by default) to run faster as Banjo-Kazooie, Banjo or Kazooie. Off turns running off.",
        true);
    qol.add_bool_option(
        tooie::transform_anywhere::option,
        "Transform anywhere",
        "The Transform key (Controls tab, Movement; T on the keyboard, not bound on a controller) changes Banjo into the world's Humba Wumba form where he stands, and back, once you have changed in that world's Humba pool. Not in the air, swimming or in cutscenes. The submarine changes in water only.",
        false);
    qol.add_bool_option(
        tooie::totals_checklist::option,
        "Totals checklist",
        "The pause menu's Totals pages also say how many of each item are left in a world and how many you can get with the moves you have now.",
        true);
    qol.add_enum_option(
        tooie::fine_aim::mode_option,
        "Fine aim",
        "Turns the first-person view (C-up) slower with the left stick, for aiming eggs. <recomp-color primary>Hold key</recomp-color> slows it only while the Fine Aim key is held (Controls tab, Hotkeys; R by default).",
        {
            {tooie::fine_aim::Mode::Off, "Off", "Off"},
            // Saved under its old key, "Hold R", so existing settings keep working.
            {tooie::fine_aim::Mode::HoldKey, "Hold R", "Hold key"},
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

    // Section headings in the QOL tab (the options of a group sit next to each other above).
    recompui::config::set_option_group(tooie::text_speed_option, "Speed and skipping");
    // Press Start Anytime In Intro sits at the bottom of Speed and skipping (L, 2026-10-16).
    recompui::config::set_option_display_before(tooie::quick_start_option, tooie::free_camera_option);
    recompui::config::set_option_group(tooie::photo_mode::hide_settings_option, "Photo Filter");
    recompui::config::set_option_group(tooie::canary_mary::mode_option, "Balancing");
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
        "HD Shadows (Experimental)",
        "Shadows are shaped like the full model on screen, with its pose. Covers the player (instead of the game's simpler shadow model) and enemies and NPCs, which have none on N64.",
        false);
    graphics.add_enum_option(
        tooie::hd_shadows::enemy_direction_option,
        "HD Shadows: Enemies",
        "Where the light for enemy and NPC shadows comes from. Overhead: straight down, as the game lights them, so the shadow sits right under them. Tilt: at an angle, like a low sun, so the shadow falls beside them and shows their shape.",
        {
            {tooie::hd_shadows::Direction::Overhead, "Overhead", "Overhead"},
            {tooie::hd_shadows::Direction::Tilt, "Tilt", "Tilt"},
        },
        tooie::hd_shadows::Direction::Overhead);
    graphics.add_option_hidden_dependency(tooie::hd_shadows::enemy_direction_option, tooie::hd_shadows_option, false);
    graphics.add_enum_option(
        tooie::hd_shadows::banjo_direction_option,
        "HD Shadows: Banjo",
        "Banjo's shadow (or whoever you play as). Overhead: the light comes straight down, as in the original, so the shadow sits right under him. Tilt: the light comes at an angle, so the shadow falls beside him; this makes it easier to see where Banjo is in 3D space. Off: Banjo keeps the game's own simpler shadow, while enemies and NPCs keep their HD shadows.",
        {
            {tooie::hd_shadows::Direction::Overhead, "Overhead", "Overhead"},
            {tooie::hd_shadows::Direction::Tilt, "Tilt", "Tilt"},
            {tooie::hd_shadows::Direction::Off, "Off", "Off"},
        },
        tooie::hd_shadows::Direction::Overhead);
    graphics.add_option_hidden_dependency(tooie::hd_shadows::banjo_direction_option, tooie::hd_shadows_option, false);
    tooie::day_night::add_options(graphics);
    graphics.add_bool_option(
        tooie::draw_distance_option,
        "Extended Draw Distance",
        "Keeps characters and objects that are already loaded drawn much further away than the original.",
        false);
    graphics.add_option_change_callback(tooie::draw_distance_option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                recompui::config::get_graphics_config().save_config();
            }
        });
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
    tooie::fsr::add_option(graphics);
    tooie::game_frame_rate::add_option(graphics);
    recompui::config::graphics::add_interpolation_options(graphics);
    tooie::low_latency::add_option(graphics);
    tooie::frame_readback::add_option(graphics);
    tooie::frame_overlay::add_option(graphics);

    // Section headings in the Graphics tab. The options of a group sit next to each other above, and a
    // heading hides with its option.
    recompui::config::set_option_group(recompui::config::graphics::options::res_option, "Display");
    recompui::config::set_option_group(tooie::picture_filters::preset_option, "Picture and effects");
    recompui::config::set_option_group(tooie::picture_filters::lighting_section_option, "Shaders");
    // HD Shadows sits in the Sun shadows part of the Shaders group, with its own toggle (L, 2026-10-16).
    recompui::config::set_option_display_before(tooie::hd_shadows_option, tooie::picture_filters::sun_shadows_option);
    recompui::config::set_option_display_before(tooie::hd_shadows::enemy_direction_option, tooie::picture_filters::sun_shadows_option);
    recompui::config::set_option_display_before(tooie::hd_shadows::banjo_direction_option, tooie::picture_filters::sun_shadows_option);
    // Character Shaders (L, 2026-10-16): Banjo's fur and Kazooie's feathers, after the Shaders group.
    for (const std::string* option : { &tooie::picture_filters::character_section_option, &tooie::picture_filters::banjo_fur_option,
                                       &tooie::picture_filters::banjo_fur_length_option, &tooie::picture_filters::banjo_fur_density_option,
                                       &tooie::picture_filters::banjo_fur_noisiness_option, &tooie::picture_filters::kazooie_feathers_option,
                                       &tooie::picture_filters::kazooie_feather_size_option, &tooie::picture_filters::enemy_fur_option }) {
        recompui::config::set_option_display_before(*option, tooie::picture_filters::contrast_option);
    }
    recompui::config::set_option_group(tooie::picture_filters::character_section_option, "Character Shaders");
    recompui::config::set_option_group(tooie::picture_filters::contrast_option, "Colour grading");
    // 3D grass has its own section after the colour grading (L, 2026-10-16).
    recompui::config::set_option_group(tooie::picture_filters::grass_section_option, "Grass");
    recompui::config::set_option_group(tooie::high_detail_models_option, "Game view");
    // MSAA is added by the frontend with the display options; show it with the other anti-aliasing (L).
    recompui::config::set_option_display_before(recompui::config::graphics::options::msaa_option, tooie::smaa::option);
    recompui::config::set_option_group(recompui::config::graphics::options::msaa_option, "Anti-aliasing and scaling");
    recompui::config::set_option_group(tooie::game_frame_rate::option, "Frame rate and overlay");
    recompui::config::set_option_group(tooie::effect_views::option, "Debug");

    // Performance tab under Graphics (L, 2026-10-16): the frame rate and latency options. They stay in the
    // graphics config (graphics.json), so saving and the code that reads them don't change.
    recompui::config::create_page_tab("Performance", tooie::performance_tab_id, recompui::config::graphics::id);
    for (const std::string* id : { &tooie::game_frame_rate::option, &recompui::config::graphics::options::rr_option,
            &recompui::config::graphics::options::rr_manual_value, &tooie::low_latency::option,
            &tooie::frame_readback::option, &tooie::frame_overlay::option }) {
        recompui::config::set_option_page(*id, tooie::performance_tab_id);
    }

    recompui::config::create_controls_tab();
    {
        recomp::config::Config& sound = recompui::config::create_sound_tab();
        tooie::music_player::add_options(sound);
        tooie::mix_rate::add_option(sound);
    }
    tooie::cheats::create_tab();
    tooie::level_warp::create_tab();
    tooie::achievements::create_tab();
    recompui::config::create_search_tab();
    recompui::config::create_mods_tab();

    // Work-in-progress and developer features (L, 2026-10-13), shown with General > DEV tab.
    recomp::config::Config& wip = recompui::config::create_config_tab("DEV", tooie::wip_tab_id, false);
    // Dumps moved here from General (L, 2026-10-15): they are read from the DEV tab.
    wip.add_enum_option(
        tooie::texture_dump_option,
        "Texture dump",
        "Saves every texture the game draws to the texture_dump folder, for making texture packs: each as a PNG named by its RT64 hash, with an rt64.json, plus RT64's raw dump files. <recomp-color primary>While playing</recomp-color> saves what you see as you play. <recomp-color primary>Sweep all maps</recomp-color> warps through every map by itself and turns the camera around in each, which takes about 40 minutes; load a spare save file first, since the game may save in odd places. It asks before it starts, and it keeps going after a restart (a map the game stopped in is skipped) until it is done or you set this to Off.",
        {
            {tooie::TextureDump::Off, "Off", "Off"},
            {tooie::TextureDump::WhilePlaying, "WhilePlaying", "While playing"},
            {tooie::TextureDump::SweepAllMaps, "SweepAllMaps", "Sweep all maps"},
        },
        tooie::TextureDump::Off);
    tooie::texture_sweep::add_prompt(wip);
    wip.add_bool_option(
        tooie::more_memory::option,
        "More game memory",
        "Gives the game a bigger memory heap, bigger buffers for drawing and animations, and 48 sound voices instead of 24, so scenes crowded with characters do not crash and fewer sounds cut out. Takes effect the next time the game starts.",
        true);
    wip.add_bool_option(
        tooie::asset_dump_option,
        "Dump assets",
        "Writes every model, animation, sprite and other game asset to the asset_dump folder as asset_<id>.bin, with assets.txt listing them (kind 0 is a model). Takes a few seconds. To replace an asset, put an edited asset_<id>.bin in mods/assets: it loads in place of the game's, at any size, the next time the game loads it.",
        false);
    wip.add_bool_option(
        tooie::discord::presence_option,
        "Discord status",
        "Shows the level you are playing in your Discord status while Discord is running.",
        true);
    tooie::game_frame_rate::add_dev_options(wip);
    // Debug options (under the Debug heading): they moved here from Graphics.
    tooie::effect_views::add_option(wip);
    tooie::interp_check::add_options(wip);
    tooie::texture_slide::add_option(wip);
    // Additional Tabs (L, 2026-10-16): switches for the tabs that are hidden or shown as wanted.
    wip.add_bool_option(
        tooie::achievements_tab_option,
        "Achievements tab",
        "Shows the Achievements tab. Achievements are still earned while it is hidden, and the Start menu's Achievements page always shows them.",
        false);
    wip.add_option_change_callback(tooie::achievements_tab_option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext) {
            show_achievements_tab();
        });
    wip.add_bool_option(
        tooie::cheats_tab_option,
        "Cheats tab",
        "Shows the Cheats tab. Turn it off to hide it; cheats that are already on stay on.",
        true);
    wip.add_option_change_callback(tooie::cheats_tab_option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext) {
            show_cheats_tab();
        });
    tooie::level_warp::add_option(wip);
    recompui::config::set_option_group(tooie::achievements_tab_option, "Additional Tabs");

    move_saved_hud_placement();
    recompui::config::finalize();
    move_saved_options_to_graphics();
    show_wip_tab();
    move_saved_discord_option();
    move_saved_tab_options();
    show_cheats_tab();
    show_achievements_tab();
    tooie::level_warp::refresh();
    move_saved_cutscene_skip();
    // The settings menu's layout (L, 2026-10-16): tabs in a sidebar on the left, descriptions along the bottom.
    recompui::config::set_sidebar_layout(true);
    tooie::picture_filters::apply();
    tooie::smaa::apply();
    tooie::texture_slide::apply();
    tooie::fxaa::apply();
    tooie::fsr::apply();
    tooie::low_latency::apply();
    tooie::frame_readback::apply();
}
