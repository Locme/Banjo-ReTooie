#include <filesystem>
#include <type_traits>
#include <variant>
#include <fstream>

#include <json/json.hpp>

#include "tooie_photo_album.h"
#include "tooie_game.h"
#include "tooie_hand_cursor.h"
#include "tooie_menu_tree.h"
#include "tooie_hd_shadows.h"
#include "tooie_day_night.h"
#include "tooie_volumetric.h"
#include "tooie_volumetric_shadows.h"
#include "tooie_classic_sounds.h"
#include "tooie_music_player.h"
#include "tooie_mix_rate.h"
#include "tooie_control_scheme.h"
#include "tooie_photo_mode.h"
#include "tooie_bottles_revenge.h"
#include "tooie_torch_enemy.h"
#include "tooie_boss_rush.h"
#include "tooie_save_state.h"
#include "tooie_honeycomb_glitter.h"
#include "tooie_snout_jiggle.h"
#include "tooie_original_honeycomb.h"
#include "tooie_window_beams.h"
#include "tooie_jiggy_dance.h"
#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "librecomp/game.hpp"
#include "tooie_cheats.h"
#include "tooie_debug.h"
#include "tooie_discord.h"
#include "tooie_free_camera.h"
#include "tooie_level_warp.h"
#include "tooie_parallax_pick.h"
#include "tooie_tiptoe.h"
#include "tooie_talon_trot.h"
#include "tooie_player_cheats.h"
#include "tooie_hold_to_run.h"
#include "tooie_dive.h"
#include "tooie_transform_anywhere.h"
#include "tooie_menu_pause.h"
#include "tooie_totals_checklist.h"
#include "tooie_canary_mary.h"
#include "tooie_game_frame_rate.h"
#include "tooie_frame_overlay.h"
#include "tooie_fine_aim.h"
#include "tooie_motion_aim.h"
#include "tooie_menu_mouse.h"
#include "tooie_picture_filters.h"
#include "tooie_smaa.h"
#include "tooie_api_restart.h"
#include "tooie_more_memory.h"
#include "tooie_speedup.h"
#include "tooie_achievements.h"
#include "tooie_fxaa.h"
#include "tooie_mirror_mode.h"
#include "tooie_low_latency.h"
#include "tooie_frame_readback.h"
#include "tooie_fsr.h"
#include "tooie_upscaler.h"
#include "tooie_effect_views.h"
#include "tooie_hotkeys.h"
#include "tooie_interp_check.h"
#include "tooie_texture_slide.h"
#include "tooie_texture_sweep.h"
#include "tooie_memory_guard.h"
#include "tooie_asset_mods.h"
#include "tooie_sound_dump.h"
#include "tooie_damage.h"
#include "tooie_aim_trace.h"

namespace {
    void show_cheats_tab() {
        bool on = false;
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

    // The Dive and Mouse in the game's menus moved from QOL to the WIP tab (L, 2026-10-21), which shows
    // Graphics options (graphics.json): carry a value saved in qol.json (or work_in_progress.json, the
    // first WIP tab's own file) over once, while graphics.json doesn't have it yet.
    void move_saved_options_to_wip() {
        const std::filesystem::path dir = recomp::get_config_path();
        auto load = [&](const std::string& file) {
            std::ifstream in(dir / file);
            nlohmann::json json = in ? nlohmann::json::parse(in, nullptr, false) : nlohmann::json();
            return json.is_object() ? json : nlohmann::json::object();
        };
        const nlohmann::json graphics_json = load("graphics.json");
        const nlohmann::json sources[] = { load(tooie::work_in_progress_tab_id + ".json"), load("qol.json") };
        recomp::config::Config& graphics = recompui::config::get_config(recompui::config::graphics::id);
        bool changed = false;
        for (const std::string& option : {tooie::dive::option}) {
            if (graphics_json.contains(option)) {
                continue;
            }
            for (const nlohmann::json& source : sources) {
                if (source.contains(option) && source[option].is_boolean()) {
                    graphics.set_option_value(option, source[option].get<bool>());
                    changed = true;
                    break;
                }
            }
        }
        if (changed) {
            graphics.save_config();
        }
    }

    // Mouse Sensitivity is 5 by default (L, 2026-10-23). A saved value from before is set to 5 once, so PCs
    // that saved the old default (off, or 50 on a Steam Deck) get 5; changing it afterwards stays.
    void default_mouse_sensitivity() {
        const std::filesystem::path marker = recomp::get_config_path() / "mouse_sensitivity_5.done";
        if (std::filesystem::exists(marker)) {
            return;
        }
        try {
            recomp::config::Config& general = recompui::config::get_general_config();
            general.set_option_value("mouse_sensitivity", 5.0);
            general.save_config();
        } catch (...) {
        }
        std::ofstream{marker};
    }

    // Transform anywhere became on by default (L, 2026-10-19): a saved "off" from the old default turns
    // on once; turning it off again afterwards stays.
    void turn_on_transform_anywhere_once() {
        const std::filesystem::path marker = recomp::get_config_path() / "transform_anywhere_on.done";
        if (std::filesystem::exists(marker)) {
            return;
        }
        recomp::config::Config& qol = recompui::config::get_config(tooie::qol_tab_id);
        if (!std::get<bool>(qol.get_option_value(tooie::transform_anywhere::option))) {
            qol.set_option_value(tooie::transform_anywhere::option, true);
            qol.save_config();
        }
        std::ofstream{marker};
    }

    // The Cheats tab became off by default (L, 2026-10-23): turn a saved "on" off once, so it hides on
    // PCs that saved the old default. dev.txt shows it; the switch in DEV > Additional Tabs still works.
    void turn_off_cheats_tab_once() {
        const std::filesystem::path marker = recomp::get_config_path() / "cheats_tab_off.done";
        if (std::filesystem::exists(marker)) {
            return;
        }
        recomp::config::Config& dev = recompui::config::get_config(tooie::wip_tab_id);
        if (std::get<bool>(dev.get_option_value(tooie::cheats_tab_option))) {
            dev.set_option_value(tooie::cheats_tab_option, false);
            dev.save_config();
        }
        std::ofstream{marker};
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

namespace {
    // Canary Mary races moved from the QOL tab to Gameplay, a page of General options (L, 2026-10-23): carry a
    // value saved in qol.json into general.json once, while general.json has none. Done on the files before the
    // configs load, so the saved enum name is copied as it is.
    void move_saved_canary_mary() {
        const std::filesystem::path dir = recomp::get_config_path();
        nlohmann::json qol_json;
        if (std::ifstream file(dir / "qol.json"); file) {
            qol_json = nlohmann::json::parse(file, nullptr, false);
        }
        if (!qol_json.is_object() || !qol_json.contains(tooie::canary_mary::mode_option) ||
            !qol_json[tooie::canary_mary::mode_option].is_string()) {
            return;
        }
        const std::filesystem::path path = dir / "general.json";
        nlohmann::json json;
        if (std::ifstream file(path); file) {
            json = nlohmann::json::parse(file, nullptr, false);
        }
        if (!json.is_object() || json.contains(tooie::canary_mary::mode_option)) {
            return;
        }
        json[tooie::canary_mary::mode_option] = qol_json[tooie::canary_mary::mode_option];
        std::ofstream file(path, std::ios::trunc);
        file << json.dump(4);
    }
}

namespace {
    // Mouse in the game's menus moved from the WIP tab (a page of Graphics options, graphics.json) to QOL
    // (L, 2026-10-23): carry a value saved in graphics.json (or work_in_progress.json) into qol.json once,
    // while qol.json has none. Done on the files before the configs load.
    void move_saved_menu_mouse() {
        const std::filesystem::path dir = recomp::get_config_path();
        auto load = [&](const std::string& file) {
            std::ifstream in(dir / file);
            nlohmann::json json = in ? nlohmann::json::parse(in, nullptr, false) : nlohmann::json();
            return json.is_object() ? json : nlohmann::json::object();
        };
        nlohmann::json qol_json = load("qol.json");
        if (qol_json.contains(tooie::menu_mouse::enabled_option)) {
            return;
        }
        for (const std::string& file : { std::string("graphics.json"), tooie::work_in_progress_tab_id + ".json" }) {
            const nlohmann::json source = load(file);
            if (source.contains(tooie::menu_mouse::enabled_option) && source[tooie::menu_mouse::enabled_option].is_boolean()) {
                qol_json[tooie::menu_mouse::enabled_option] = source[tooie::menu_mouse::enabled_option];
                std::ofstream out(dir / "qol.json", std::ios::trunc);
                out << qol_json.dump(4);
                return;
            }
        }
    }
}

namespace {
    // Smooth walls became on by default (L, 2026-10-23). A saved off from the old default is turned on once.
    void turn_on_saved_smooth_walls() {
        const std::filesystem::path dir = recomp::get_config_path();
        const std::filesystem::path marker = dir / "smooth_walls_on.done";
        if (std::filesystem::exists(marker)) {
            return;
        }
        const std::filesystem::path path = dir / "qol.json";
        nlohmann::json json;
        if (std::ifstream file(path); file) {
            json = nlohmann::json::parse(file, nullptr, false);
        }
        if (json.is_object() && json.contains(tooie::free_camera_smooth_walls_option)) {
            json[tooie::free_camera_smooth_walls_option] = true;
            std::ofstream file(path, std::ios::trunc);
            file << json.dump(4);
        }
        std::ofstream{marker};
    }
}

namespace {
    // Toon shading became two sliders, Characters and World (L, 2026-10-21). A value saved under the old single
    // "toon_shading" is carried to both once, unless graphics.json already has either of the new ones. Done on the
    // file before the configs load.
    void split_saved_toon_shading() {
        const std::filesystem::path dir = recomp::get_config_path();
        const std::filesystem::path marker = dir / "toon_shading_split.done";
        if (std::filesystem::exists(marker)) {
            return;
        }
        const std::filesystem::path path = dir / "graphics.json";
        nlohmann::json json;
        if (std::ifstream file(path); file) {
            json = nlohmann::json::parse(file, nullptr, false);
        }
        if (json.is_object() && json.contains("toon_shading")) {
            if (json["toon_shading"].is_number() && !json.contains(tooie::picture_filters::toon_world_option) &&
                !json.contains(tooie::picture_filters::toon_characters_option))
            {
                json[tooie::picture_filters::toon_world_option] = json["toon_shading"];
                json[tooie::picture_filters::toon_characters_option] = json["toon_shading"];
            }
            json.erase("toon_shading");
            std::ofstream file(path, std::ios::trunc);
            file << json.dump(4);
        }
        std::ofstream{marker};
    }
}

void tooie::init_config() {
    // dev.txt next to the exe shows every tab hidden by a switch, including tabs added later (L, 2026-10-23).
    recompui::config::set_show_all_tabs(tooie::dev_file_present());
    // Before finalize(), which loads the controls config and with it the hotkey bindings.
    tooie::speedup::register_input();
    tooie::frame_overlay::register_input();
    tooie::input::register_input();
    tooie::hold_to_run::register_input();
    tooie::transform_anywhere::register_input();
    tooie::photo_mode::register_input();
    tooie::save_state::register_input();
    tooie::fine_aim::register_input();
    tooie::talon_trot::register_input();
    tooie::player_cheats::register_input();
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
        "Back Up Saves",
        "Copies your save file into the save_backups folder whenever it changes.",
        true);
    general.add_number_option(
        tooie::save_backups_keep_option,
        "Save Backups To Keep",
        "How many of the newest save backups to keep.",
        1, 100, 1, 0, false, 10);
    general.add_bool_option(
        tooie::precompile_shaders_option,
        "Compile All Shaders At Start",
        "Compiles every shader the game uses while the game starts, with a percentage on screen, so no area stutters on its first visit. Off: only the shaders you have already met compile at start. The first start takes a while; later starts reuse what was built. Takes effect on the next start.",
        true);
    general.add_enum_option(
        tooie::timer_save_option,
        "Timer Save",
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
    tooie::boss_rush::add_option(general);
    tooie::mirror_mode::add_option(general);
    general.add_bool_option(
        tooie::snout_jiggle::master_option,
        "Jiggle Physics",
        "Turns every jiggle below on or off at once: Banjo's snout, nose, belly, ears, fur and backpack, Kazooie's feathers and Mumbo. Each part keeps its own switch and settings, which open under this one.",
        false);
    general.add_bool_option(
        tooie::snout_jiggle::option,
        "Snout Jiggle",
        "Banjo's snout wobbles as he runs, turns, jumps, falls and lands: it trails behind the way he moves and folds back towards his eyes in a dive. It stays mid-wobble in Photo Mode. Works with player model mods that keep his skeleton, such as Smash Banjo.",
        true);
    {
        using namespace tooie::snout_jiggle;
        general.add_number_option(stiffness_option, "Snout Jiggle: Stiffness",
            "How hard the snout springs back to straight. Lower is floppier and slower, higher is quicker and tighter.", 10, 900, 10, 0, false, 300);
        general.add_number_option(damping_option, "Snout Jiggle: Damping",
            "How quickly the wobble dies out. 0 wobbles for ages.", 0, 90, 1, 0, false, 12);
        general.add_number_option(mass_option, "Snout Jiggle: Mass",
            "How heavy the snout is: heavier lags further behind and swings slower.", 0.1, 7.5, 0.1, 1, false, 1);
        general.add_number_option(squash_in_option, "Snout Jiggle: Max Squash & Stretch Inwards",
            "How far the tip may be pushed back into his face and eyes, as a share of the snout's length.", 0, 95, 5, 0, true, 50);
        general.add_number_option(squash_walk_option, "Squash & Stretch While Walking",
            "The inwards limit while Banjo walks or runs along the ground, so walking forward doesn't squash his face. Jumps, falls, stops and turns use the inwards setting above. It can only be gentler than that.", 0, 95, 5, 0, true, 15);
        general.add_number_option(squash_out_option, "Snout Jiggle: Max Squash & Stretch Outwards",
            "How far the tip may stretch out, as a share of the snout's length.", 0, 300, 5, 0, true, 50);
        general.add_number_option(squash_across_option, "Snout Jiggle: Max Squash & Stretch Up And Down",
            "How far the tip may swing up and down (and to the side), as a share of the snout's length.", 0, 300, 5, 0, true, 50);
        general.add_bool_option(nose_option, "Nose Jiggle",
            "Banjo's black nose wobbles too, on its own jiggle bone on the end of the snout, with the same spring. Its squash and stretch stays small so it always looks like a nose.", true);
        for (const std::string* id : { &stiffness_option, &damping_option, &mass_option, &squash_in_option, &squash_walk_option, &squash_out_option,
                                       &squash_across_option, &nose_option }) {
            general.add_option_hidden_dependency(*id, option, false);
        }
    }
    general.add_bool_option(tooie::snout_jiggle::belly_option, "Belly Jiggle",
        "The front of Banjo's belly wobbles on a spring as he runs, jumps and lands, with its own settings like the snout's. On Banjo's own model (not model mods). It stays mid-wobble in Photo Mode.",
        true);
    {
        using namespace tooie::snout_jiggle;
        general.add_number_option(belly_stiffness_option, "Belly Jiggle: Stiffness",
            "How hard the belly springs back. Lower is floppier and slower, higher is quicker and tighter.", 10, 900, 10, 0, false, 300);
        general.add_number_option(belly_damping_option, "Belly Jiggle: Damping",
            "How quickly the wobble dies out. 0 wobbles for ages.", 0, 90, 1, 0, false, 12);
        general.add_number_option(belly_mass_option, "Belly Jiggle: Mass",
            "How heavy the belly is: heavier lags further behind and swings slower.", 0.1, 7.5, 0.1, 1, false, 1);
        general.add_number_option(belly_squash_in_option, "Belly Jiggle: Max Squash & Stretch Inwards",
            "How far the belly may squash in, as a share of its depth.", 0, 95, 5, 0, true, 25);
        general.add_number_option(belly_squash_out_option, "Belly Jiggle: Max Squash & Stretch Outwards",
            "How far the belly may bulge out, as a share of its depth.", 0, 300, 5, 0, true, 25);
        general.add_number_option(belly_squash_across_option, "Belly Jiggle: Max Squash & Stretch Up And Down",
            "How far the belly may swing up and down (and to the side), as a share of its depth.", 0, 300, 5, 0, true, 25);
        for (const std::string* id : { &belly_stiffness_option, &belly_damping_option, &belly_mass_option, &belly_squash_in_option,
                                       &belly_squash_out_option, &belly_squash_across_option }) {
            general.add_option_hidden_dependency(*id, belly_option, false);
        }
    }
    general.add_bool_option(tooie::snout_jiggle::ears_option, "Ear Jiggle",
        "Banjo's ears wobble on springs as he runs, turns, jumps and lands, each on its own jiggle bone, with their own settings like the snout's. On Banjo's own model (not model mods). They stay mid-wobble in Photo Mode.",
        true);
    {
        using namespace tooie::snout_jiggle;
        general.add_number_option(ears_stiffness_option, "Ear Jiggle: Stiffness",
            "How hard the ears spring back. Lower is floppier and slower, higher is quicker and tighter.", 10, 900, 10, 0, false, 300);
        general.add_number_option(ears_damping_option, "Ear Jiggle: Damping",
            "How quickly the wobble dies out. 0 wobbles for ages.", 0, 90, 1, 0, false, 10);
        general.add_number_option(ears_mass_option, "Ear Jiggle: Mass",
            "How heavy the ears are: heavier lags further behind and swings slower.", 0.1, 7.5, 0.1, 1, false, 1);
        general.add_number_option(ears_squash_option, "Max Squash & Stretch",
            "How far an ear may squash down, stretch up and flop forwards, backwards and to the side, as a share of its height (squashing stops at 95%).", 0, 300, 5, 0, true, 60);
        for (const std::string* id : { &ears_stiffness_option, &ears_damping_option, &ears_mass_option, &ears_squash_option }) {
            general.add_option_hidden_dependency(*id, ears_option, false);
        }
    }
    general.add_bool_option(tooie::snout_jiggle::fur_option, "Fur Jiggle",
        "The strands of Banjo's fur (the Banjo fur shader, in Character Shaders) lean back as he runs, turns, jumps and lands, and spring upright again when he stops. Its own settings like the snout's. It stays mid-sway in Photo Mode.",
        true);
    {
        using namespace tooie::snout_jiggle;
        general.add_number_option(fur_stiffness_option, "Fur Jiggle: Stiffness",
            "How hard the fur springs back upright. Lower is floppier and slower, higher is quicker and tighter.", 10, 900, 10, 0, false, 300);
        general.add_number_option(fur_damping_option, "Fur Jiggle: Damping",
            "How quickly the swaying dies out. 0 sways for ages.", 0, 90, 1, 0, false, 8);
        general.add_number_option(fur_mass_option, "Fur Jiggle: Mass",
            "How heavy the fur is: heavier lags further behind and sways slower.", 0.1, 7.5, 0.1, 1, false, 1);
        general.add_number_option(fur_sway_option, "Max Sway",
            "How far the tips may lean, as a share of the strands' length.", 0, 300, 5, 0, true, 100);
        for (const std::string* id : { &fur_stiffness_option, &fur_damping_option, &fur_mass_option, &fur_sway_option }) {
            general.add_option_hidden_dependency(*id, fur_option, false);
        }
    }
    general.add_bool_option(tooie::snout_jiggle::body_option, "Backpack Jiggle",
        "Banjo's backpack swings on a spring as he moves, carrying Kazooie with it, so the pack bounces when he runs, jumps and lands and settles when he stops. Separate from Snout jiggle and Kazooie jiggle, with its own settings. It stays mid-swing in Photo Mode.",
        true);
    {
        using namespace tooie::snout_jiggle;
        general.add_number_option(body_stiffness_option, "Backpack Jiggle: Stiffness",
            "How hard the backpack springs back. Lower is floppier and slower, higher is quicker and tighter.", 10, 900, 10, 0, false, 300);
        general.add_number_option(body_damping_option, "Backpack Jiggle: Damping",
            "How quickly the bouncing dies out. 0 bounces for ages.", 0, 90, 1, 0, false, 10);
        general.add_number_option(body_mass_option, "Backpack Jiggle: Mass",
            "How heavy the backpack is: heavier lags further behind and swings slower.", 0.1, 7.5, 0.1, 1, false, 1.5);
        general.add_number_option(body_squash_option, "Squash & Stretch",
            "How far the pack may swing, squash and stretch from where it rests, as a share of its size.", 0, 300, 5, 0, true, 25);
        general.add_number_option(body_tilt_option, "Tilt",
            "How the pack leans while Banjo walks or runs: positive leans its top forward towards his head, negative leans it back, in degrees. It eases back upright when he stops or leaves the ground.", -60, 60, 5, 0, false, 0);
        for (const std::string* id : { &body_stiffness_option, &body_damping_option, &body_mass_option, &body_squash_option,
                                       &body_tilt_option }) {
            general.add_option_hidden_dependency(*id, body_option, false);
        }
    }
    general.add_bool_option(tooie::snout_jiggle::kazooie_option, "Kazooie Jiggle",
        "Kazooie's crest and tail feathers wobble on springs as she moves, whether she rides in the backpack or walks alone after Split Up. Separate from Snout jiggle. They stay mid-wobble in Photo Mode.",
        true);
    {
        using namespace tooie::snout_jiggle;
        general.add_number_option(kazooie_stiffness_option, "Kazooie Jiggle: Stiffness",
            "How hard her feathers spring back. Lower is floppier and slower, higher is quicker and tighter.", 10, 900, 10, 0, false, 300);
        general.add_number_option(kazooie_damping_option, "Kazooie Jiggle: Damping",
            "How quickly the wobble dies out. 0 wobbles for ages.", 0, 90, 1, 0, false, 12);
        general.add_number_option(kazooie_mass_option, "Kazooie Jiggle: Mass",
            "How heavy her feathers are: heavier lags further behind and swings slower.", 0.1, 7.5, 0.1, 1, false, 1);
        general.add_number_option(kazooie_squash_in_option, "Kazooie Jiggle: Max Squash & Stretch Inwards",
            "How far each feather may squash back on itself, as a share of its length.", 0, 95, 5, 0, true, 50);
        general.add_number_option(kazooie_squash_out_option, "Kazooie Jiggle: Max Squash & Stretch Outwards",
            "How far each feather may stretch out, as a share of its length.", 0, 300, 5, 0, true, 50);
        general.add_number_option(kazooie_squash_across_option, "Kazooie Jiggle: Max Squash & Stretch Up And Down",
            "How far each feather may swing up and down (and to the side), as a share of its length.", 0, 300, 5, 0, true, 50);
        for (const std::string* id : { &kazooie_stiffness_option, &kazooie_damping_option, &kazooie_mass_option,
                                       &kazooie_squash_in_option, &kazooie_squash_out_option, &kazooie_squash_across_option }) {
            general.add_option_hidden_dependency(*id, kazooie_option, false);
        }
    general.add_bool_option(tooie::snout_jiggle::mumbo_option, "Mumbo Jiggle",
        "The feathers on top of Mumbo's head wobble on springs as he moves, whether you play as him or meet him in his skull. Uses the Kazooie jiggle settings.",
        true);
    // Enhancements on the Gameplay tab (L, 2026-10-23): touches to the game's own look, from Graphics.
    general.add_bool_option(
        tooie::window_beams::option,
        "Window Light Beams",
        "Beams of light, shaped like their windows, fall from the windows onto the floor and light a patch of it, the way they do in Mumbo's Skull: in Bottles' house, Banjo's house and King Jingaling's throne room. Switching it in one of those rooms reloads the room.",
        true);
    general.add_option_change_callback(tooie::window_beams::option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                recompui::config::get_general_config().save_config();
            }
        });
    }
    general.add_bool_option(
        tooie::damage::double_damage_option,
        "Enemies Do Double Damage",
        "Every hit from an enemy or hazard takes twice the honeycombs. Falls hurt as they always do.",
        false);
    general.add_enum_option(
        tooie::damage::aim_option,
        "Enemy Aim",
        "The enemies and shots that aim ahead of you (Klungo's potions, lava gargoyles, fantasy eyeballs, balloon bombs, Gruntilda's fireballs and others) aim at where you are running to. <recomp-color primary>Original</recomp-color> is the game's own aim. <recomp-color primary>Better</recomp-color> aims half a second of your running ahead and <recomp-color primary>Sharp</recomp-color> a full second ahead, and Klungo's potion also steers toward you while it flies. Running in a straight line stops working; only really changing direction still dodges.",
        {
            {tooie::damage::Aim::Original, "Original", "Original"},
            {tooie::damage::Aim::Better, "Better", "Better"},
            {tooie::damage::Aim::Sharp, "Sharp", "Sharp"},
        },
        tooie::damage::Aim::Original);
    general.add_number_option(
        tooie::damage::aim_chance_option,
        "Aimed Shots",
        "With Enemy aim on Better or Sharp, how many shots are aimed ahead of you and steered, in percent. The others fly as in the game, so the boss cannot be read as always aiming ahead.",
        0, 100, 5, 0, false, 75);
    general.add_option_hidden_dependency(tooie::damage::aim_chance_option, tooie::damage::aim_option, tooie::damage::Aim::Original);
    general.add_bool_option(
        tooie::damage::homing_option,
        "Homing Shots",
        "With Enemy aim on Better or Sharp, Klungo's potion also steers toward where you are heading while it flies, so only really changing direction dodges it.",
        true);
    general.add_option_hidden_dependency(tooie::damage::homing_option, tooie::damage::aim_option, tooie::damage::Aim::Original);
    general.add_bool_option(
        tooie::damage::strafe_option,
        "Enemy Dynamic Positioning",
        "A curated list of enemies (Billy Bob, Boltoid, Diggit, Flatso, Globble, Gruntydactyl, Guvnor, Hothead, Jippo Jim, Keelhaul, Minjo, Moggy, Nutta, Pansie, S'Hard, Soarasaur, Ugger, Washup, Zubba) slide sideways while they close in, and sidestep when you roll toward them, so they are harder to roll over.",
        false);
    general.add_bool_option(
        tooie::damage::faster_attacks_option,
        "Lower Enemy Attack Cooldown",
        "The curated list of enemies (Billy Bob, Boltoid, Diggit, Flatso, Globble, Gruntydactyl, Guvnor, Hothead, Jippo Jim, Keelhaul, Minjo, Moggy, Nutta, Pansie, S'Hard, Soarasaur, Ugger, Washup, Zubba) wait half as long between attacks.",
        false);
    // Moved from QOL > Balancing to Gameplay > Difficulty (L, 2026-10-23); move_saved_canary_mary carries the
    // value saved in qol.json.
    general.add_enum_option(
        tooie::canary_mary::mode_option,
        "Canary Mary Races",
        "<recomp-color primary>Fair</recomp-color>: Canary Mary never speeds up past her normal pace to catch you when you lead. <recomp-color primary>Easy</recomp-color> is Fair with her pace at 85%. <recomp-color primary>Original</recomp-color> keeps her catch-up. She still slows down when you fall behind, as in the original.",
        {
            {tooie::canary_mary::Mode::Original, "Original", "Original"},
            {tooie::canary_mary::Mode::Fair, "Fair", "Fair"},
            {tooie::canary_mary::Mode::Easy, "Easy", "Easy"},
        },
        tooie::canary_mary::Mode::Fair);
    general.add_bool_option(
        tooie::classic_sounds::option,
        "Back-Port: Old Banjo Sounds",
        "Banjo-Kazooie's jump sounds instead of Banjo-Tooie's.",
        false);
    general.add_bool_option(
        tooie::honeycomb_glitter::option,
        "Back-Port: Glittering Honeycombs",
        "Health honeycombs sparkle like they did in Banjo-Kazooie.",
        false);
    general.add_bool_option(
        tooie::original_honeycomb::option,
        "Back-Port: Original Honeycomb",
        "Health honeycombs use Banjo-Kazooie's honeycomb model, which is still in Banjo-Tooie's files. Switching it in a level reloads the area.",
        false);
    general.add_bool_option(
        tooie::jiggy_dance::option,
        "Back-Port: Get Jiggy Animation",
        "Banjo does Banjo-Kazooie's jiggy dance when he collects a Jiggy.",
        false);
    tooie::torch_enemy::add_option(general);
    tooie::bottles_revenge::add_option(general);
    // L, 2026-10-17: in General, off by default (a new id, so the old DEV value, on by default, is not carried over).
    general.add_bool_option(
        tooie::discord::presence_option,
        "Discord Status",
        "Shows the world and area you are in, and how long you have been playing, in your Discord status while Discord is running on this PC.",
        false);
    general.add_bool_option(
        tooie::wip_tab_option,
        "Developer Mode",
        "Shows the DEV tab, with features for developers and features that are still being worked on, and the switches for the Achievements, Cheats and Warp tabs. A dev.txt file next to the game's exe shows all of these tabs whatever their switches say.",
        false);
    general.add_option_change_callback(tooie::wip_tab_option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext) {
            show_wip_tab();
        });

    // Section headings in the General tab (the controls and sliders above them have none).
    // Saves is one section in General (L, 2026-10-24), and Discord Status is in Others, with Compile All Shaders at Start.
    recompui::config::set_option_group(tooie::save_backups_option, "Saves");
    recompui::config::set_option_display_before(tooie::discord::presence_option, tooie::precompile_shaders_option);
    recompui::config::set_option_group(tooie::discord::presence_option, "Others");
    // At the end of the section before Back-Ports, with its own heading, so the options around it keep theirs.
    recompui::config::set_option_display_before(tooie::precompile_shaders_option, tooie::classic_sounds::option);
    recompui::config::set_option_group(tooie::classic_sounds::option, "Back-Ports And Cut Content");
    recompui::config::set_option_group(tooie::boss_rush::option, "Features");
    recompui::config::set_option_group(tooie::snout_jiggle::master_option, "Enhancements");
    recompui::config::set_option_group(tooie::wip_tab_option, "Developer");

    recomp::config::Config& qol = recompui::config::create_config_tab("QOL", tooie::qol_tab_id, false);
    recompui::config::set_open_allowed_callback(tooie::menu_pause::open_allowed);
    qol.add_bool_option(
        tooie::quick_start_option,
        "Press Start Anytime In Intro",
        "Press Start during the logos and title flight to go straight to the file select.",
        true);
    qol.add_enum_option(
        tooie::text_speed_option,
        "Text Speed",
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
        "Level Transitions",
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
        "Free Camera",
        "The right stick turns the camera smoothly around Banjo and tilts it, instead of the game's stepped camera swings. The camera stays where you turned it until a cutscene or another area. Its settings show below it.",
        true);
    qol.add_bool_option(
        tooie::free_camera_rb_distance_option,
        "Hold C Down To Fine-Tune Distance",
        "Hold C Down (RB on a controller, the game's camera distance button) and push the camera stick up or down to move the free camera closer or further away, in small steps, from about half to twice the game's distance. A quick tap still does the game's own camera distance step; only a hold (about a quarter of a second) fine-tunes, and the game does not see it.",
        true);
    qol.add_enum_option(
        tooie::free_camera_speed_option,
        "Free Camera Speed",
        "How fast the right stick turns the free camera.",
        {
            {tooie::FreeCameraSpeed::Slow, "Slow", "Slow"},
            {tooie::FreeCameraSpeed::Normal, "Normal", "Normal"},
            {tooie::FreeCameraSpeed::Fast, "Fast", "Fast"},
        },
        tooie::FreeCameraSpeed::Normal);
    qol.add_bool_option(
        tooie::free_camera_invert_x_option,
        "Invert Left/Right",
        "Reverses which way the right stick turns the free camera.",
        false);
    qol.add_bool_option(
        tooie::free_camera_invert_y_option,
        "Invert Up/Down",
        "Reverses which way the right stick tilts the free camera.",
        false);
    qol.add_bool_option(
        tooie::free_camera_smooth_walls_option,
        "Smooth Walls",
        "The camera glides in when a wall gets between it and Banjo and glides back out afterwards, instead of jumping. Banjo fades out when the camera gets very close to him.",
        true);
    qol.add_enum_option(
        tooie::free_camera_ease_back_option,
        "Ease Back",
        "A second after you let go of the right stick, the camera drifts back behind Banjo. <recomp-color primary>Flying only</recomp-color> does it while flying, <recomp-color primary>Always</recomp-color> also while running or swimming. Standing still leaves the camera where you turned it.",
        {
            {tooie::FreeCameraEaseBack::Off, "Off", "Off"},
            {tooie::FreeCameraEaseBack::Flying, "Flying", "Flying only"},
            {tooie::FreeCameraEaseBack::Always, "Always", "Always"},
        },
        tooie::FreeCameraEaseBack::Off);
    qol.add_bool_option(
        tooie::free_camera_smooth_height_option,
        "Smooth Stairs",
        "The free camera follows Banjo's height with a gentle ease, so walking down (or up) stairs and small steps no longer bobs or jerks the camera.",
        true);
    qol.add_bool_option(
        tooie::free_camera_hover_option,
        "Hover Over Small Objects",
        "A small object near the camera no longer pulls it in towards Banjo when the camera can still see him past it: the camera stays where you put it and hovers over the object. An object that is really between Banjo and the camera still pulls it in.",
        true);
    qol.add_enum_option(
        tooie::free_camera_mouse_option,
        "Mouse",
        "Moving the mouse turns and tilts the free camera, like the right stick. <recomp-color primary>Always</recomp-color>: whenever you play. <recomp-color primary>Hold a key</recomp-color>: only while the Camera Mouse Look key (Controls > Hotkeys) is held. Strength is General > Mouse Sensitivity; at 0 the mouse does nothing. Invert left/right and up/down apply too. When it is not Off, the mouse wheel zooms the camera in and out and the middle button snaps it behind Banjo.",
        {
            {tooie::FreeCameraMouse::Off, "Off", "Off"},
            {tooie::FreeCameraMouse::Always, "Always", "Always"},
            {tooie::FreeCameraMouse::Hold, "Hold", "Hold a key"},
        },
        tooie::FreeCameraMouse::Always);
    qol.add_enum_option(
        tooie::free_camera_gyro_option,
        "Gyro",
        "Tilting a controller that has a gyro turns and tilts the free camera. <recomp-color primary>Hold a key</recomp-color> (the default): only while the Camera Mouse Look key (Controls > Hotkeys, not bound by default) is held. <recomp-color primary>Always</recomp-color>: whenever you play. Strength is General > Gyro Sensitivity; at 0 the gyro does nothing.",
        {
            {tooie::FreeCameraMouse::Off, "Off", "Off"},
            {tooie::FreeCameraMouse::Always, "Always", "Always"},
            {tooie::FreeCameraMouse::Hold, "Hold", "Hold a key"},
        },
        tooie::FreeCameraMouse::Hold);
    qol.add_bool_option(
        tooie::free_camera_floor_clearance_option,
        "Floor Clearance",
        "Keeps the free camera a little above the floor under it, so tilting the camera low cannot push it into the ground.",
        true);
    qol.add_bool_option(
        tooie::free_camera_look_up_option,
        "Look Up",
        "Pushing the right stick (or mouse) up past the lowest the camera can go swings it down near the ground and then tips the view up, to about 80 degrees, so tall things show. Only the picture moves, not the game's camera or collision.",
        true);
    tooie::photo_mode::add_options(qol);
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
        "Transform Anywhere",
        "The Transform key (Controls tab, Movement; T on the keyboard, not bound on a controller) changes Banjo into the world's Humba Wumba form where he stands, and back, once you have changed in that world's Humba pool. Not in the air, swimming or in cutscenes. The submarine changes in water only.",
        true);
    qol.add_enum_option(
        tooie::fine_aim::mode_option,
        "Fine Aim",
        "Turns the first-person view (C-up) slower with the left stick, for aiming eggs. <recomp-color primary>Hold key</recomp-color> slows it only while the Fine Aim key is held (Controls tab, Hotkeys; R by default).",
        {
            {tooie::fine_aim::Mode::Off, "Off", "Off"},
            // Saved under its old key, "Hold R", so existing settings keep working.
            {tooie::fine_aim::Mode::HoldKey, "Hold R", "Hold key"},
            {tooie::fine_aim::Mode::Always, "Always", "Always"},
        },
        tooie::fine_aim::Mode::HoldKey);
    qol.add_enum_option(
        tooie::fine_aim::speed_option,
        "Fine Aim Speed",
        "How fast the view turns with fine aim: 25%, 40% or 60% of the normal speed.",
        {
            {tooie::fine_aim::Speed::Slow, "Slow", "25%"},
            {tooie::fine_aim::Speed::Medium, "Medium", "40%"},
            {tooie::fine_aim::Speed::Fast, "Fast", "60%"},
        },
        tooie::fine_aim::Speed::Medium);
    qol.add_option_hidden_dependency(tooie::fine_aim::speed_option, tooie::fine_aim::mode_option, tooie::fine_aim::Mode::Off);
    tooie::motion_aim::add_options(qol);
    // Menu is the last section of QOL (L, 2026-10-23): Pause Special Menu, Totals Checklist, Mouse in the game's menus.
    qol.add_bool_option(
        tooie::menu_pause::option,
        "Pause Special Menu",
        "While this menu is open during play, the game is paused as if you pressed Start, without the pause menu drawn over it. The pause menu's music plays and the picture's effects keep moving. Cutscenes and the title screen carry on as before.",
        true);
    qol.add_bool_option(
        tooie::totals_checklist::option,
        "Totals Checklist",
        "The pause menu's Totals pages also say how many of each item are left in a world and how many you can get with the moves you have now.",
        true);
    // Mouse in the game's menus moved from the WIP tab to QOL > Menu (L, 2026-10-23).
    tooie::menu_mouse::add_options(qol);

    // Section headings in the QOL tab (the options of a group sit next to each other above).
    recompui::config::set_option_group(tooie::menu_pause::option, "Menu");
    recompui::config::set_option_group(tooie::text_speed_option, "Speed And Skipping");
    // Press Start Anytime In Intro sits at the bottom of Speed and skipping (L, 2026-10-16).
    recompui::config::set_option_display_before(tooie::quick_start_option, tooie::free_camera_option);
    recompui::config::set_option_group(tooie::free_camera_option, "Camera");
    recompui::config::set_option_group(tooie::talon_trot::mode_option, "Moves And Aiming");

    // Gameplay tab (L, 2026-10-23): the enemy options and Canary Mary races under a Difficulty heading. A page
    // of General options, so they stay in general.json and the code that reads them doesn't change.
    recompui::config::create_page_tab("Gameplay", tooie::gameplay_tab_id, recompui::config::general::id);
    for (const std::string* id : { &tooie::damage::double_damage_option, &tooie::damage::aim_option,
            &tooie::damage::aim_chance_option, &tooie::damage::homing_option, &tooie::damage::strafe_option,
            &tooie::damage::faster_attacks_option, &tooie::canary_mary::mode_option }) {
        recompui::config::set_option_page(*id, tooie::gameplay_tab_id);
    }
    recompui::config::set_option_group(tooie::damage::double_damage_option, "Difficulty");
    // Difficulty goes to the top of the Gameplay tab, ahead of Boss Rush (L, 2026-10-23).
    for (const std::string* id : { &tooie::damage::double_damage_option, &tooie::damage::aim_option,
            &tooie::damage::aim_chance_option, &tooie::damage::homing_option, &tooie::damage::strafe_option,
            &tooie::damage::faster_attacks_option, &tooie::canary_mary::mode_option }) {
        recompui::config::set_option_display_before(*id, tooie::boss_rush::option);
    }
    // Features and Back-Ports from General (L, 2026-10-23), with their headings. Saves, shaders, Discord and the
    // Developer switch stay in General.
    for (const std::string* id : { &tooie::boss_rush::option, &tooie::mirror_mode::option, &tooie::classic_sounds::option,
            &tooie::honeycomb_glitter::option, &tooie::original_honeycomb::option, &tooie::jiggy_dance::option,
            &tooie::bottles_revenge::option, &tooie::window_beams::option,
            &tooie::snout_jiggle::master_option,
            &tooie::snout_jiggle::option,
            &tooie::snout_jiggle::body_option,
            &tooie::snout_jiggle::body_stiffness_option,
            &tooie::snout_jiggle::body_damping_option,
            &tooie::snout_jiggle::body_mass_option,
            &tooie::snout_jiggle::body_squash_option,
            &tooie::snout_jiggle::body_tilt_option,
            &tooie::snout_jiggle::belly_option,
            &tooie::snout_jiggle::belly_stiffness_option,
            &tooie::snout_jiggle::belly_damping_option,
            &tooie::snout_jiggle::belly_mass_option,
            &tooie::snout_jiggle::belly_squash_in_option,
            &tooie::snout_jiggle::belly_squash_out_option,
            &tooie::snout_jiggle::belly_squash_across_option,
            &tooie::snout_jiggle::ears_option,
            &tooie::snout_jiggle::ears_stiffness_option,
            &tooie::snout_jiggle::ears_damping_option,
            &tooie::snout_jiggle::ears_mass_option,
            &tooie::snout_jiggle::ears_squash_option,
            &tooie::snout_jiggle::fur_option,
            &tooie::snout_jiggle::fur_stiffness_option,
            &tooie::snout_jiggle::fur_damping_option,
            &tooie::snout_jiggle::fur_mass_option,
            &tooie::snout_jiggle::fur_sway_option,
            &tooie::snout_jiggle::kazooie_option,
            &tooie::snout_jiggle::mumbo_option,
            &tooie::snout_jiggle::kazooie_stiffness_option,
            &tooie::snout_jiggle::kazooie_damping_option,
            &tooie::snout_jiggle::kazooie_mass_option,
            &tooie::snout_jiggle::kazooie_squash_in_option,
            &tooie::snout_jiggle::kazooie_squash_out_option,
            &tooie::snout_jiggle::kazooie_squash_across_option,
            &tooie::snout_jiggle::stiffness_option,
            &tooie::snout_jiggle::damping_option,
            &tooie::snout_jiggle::mass_option,
            &tooie::snout_jiggle::squash_in_option,
            &tooie::snout_jiggle::squash_out_option,
            &tooie::snout_jiggle::squash_across_option,
            &tooie::snout_jiggle::squash_walk_option,
            &tooie::snout_jiggle::nose_option,
            &tooie::torch_enemy::option }) {
        recompui::config::set_option_page(*id, tooie::gameplay_tab_id);
    }

    // Features still being worked on (L, 2026-10-21), in a section named like the tab. When one is done it
    // moves to its own tab (the Dive to QOL > Moves and aiming, Mouse in the game's menus back to QOL, the
    // Grass section back to Graphics). The tab is a page of Graphics options, so they all save to
    // graphics.json and the grass keeps its live preview; the options are added below with the graphics ones.
    recompui::config::create_page_tab("WIP", tooie::work_in_progress_tab_id, recompui::config::graphics::id);

    recomp::config::Config& graphics = recompui::config::create_graphics_tab();
    tooie::picture_filters::add_options(graphics);
    graphics.add_bool_option(
        tooie::dive::option,
        "Dive",
        "Press the Run key (B on a controller) in the air as Banjo-Kazooie for a fast forward lunge. On landing Banjo slides on his belly and lies there until you jump. Works from a jump, after the Feathery Flap and in the ground pound, once per jump. Off (the default) leaves B in the air to the game.",
        false);
    {
        namespace pf = tooie::picture_filters;
        for (const std::string* id : { &tooie::dive::option, &pf::grass_section_option,
                &pf::grass_option, &pf::grass_height_option, &pf::grass_distance_option, &pf::grass_density_option,
                &pf::grass_patches_option, &pf::grass_thickness_option, &pf::grass_random_length_option,
                &pf::grass_blend_option, &pf::grass_chunky_option, &pf::grass_chunk_size_option,
                &pf::grass_pixelated_option, &pf::grass_pixel_size_option, &pf::grass_edges_option,
                &pf::grass_frustum_cull_option, &pf::grass_occlusion_cull_option, &pf::grass_chunking_option,
                &pf::grass_lod_option, &pf::grass_half_rate_option, &pf::grass_ray_tracing_option }) {
            recompui::config::set_option_page(*id, tooie::work_in_progress_tab_id);
        }
        // Dive first, then the Grass toggle and its settings, all under one
        // WIP heading.
        recompui::config::set_option_display_before(tooie::dive::option, pf::grass_section_option);
        // Each WIP feature has its own heading, so it is quick to find and test (L, 2026-10-23).
        recompui::config::set_option_group(tooie::dive::option, "Dive");
        recompui::config::set_option_group(pf::grass_section_option, "3D Grass");
    }
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
    {
        // Day and night is a WIP section for now (L, 2026-10-22): its options sit in the WIP tab under one
        // "Day and night" heading. They are still Graphics options, so they save to graphics.json as before.
        namespace dn = tooie::day_night;
        for (const std::string* id : { &dn::option, &dn::length_option, &dn::flare_option, &dn::fireflies_option,
                &dn::weather_option, &dn::aurora_option, &dn::clouds_option, &dn::cloud_amount_option,
                &dn::cloud_height_option, &dn::cloud_thickness_option, &dn::cloud_speed_option, &dn::wet_ground_option,
                &dn::drops_option, &dn::mist_option, &dn::mist_time_option, &dn::sounds_option }) {
            recompui::config::set_option_page(*id, tooie::work_in_progress_tab_id);
        }
        recompui::config::set_option_group(dn::option, "Day And Night");
    }
    tooie::volumetric::add_options(graphics);
    {
        // Volumetric mist, fog and clouds are WIP too (L, 2026-10-23): the WIP tab, under their own heading, off by default.
        namespace vol = tooie::volumetric;
        for (const std::string* id : { &vol::mist_option, &vol::mist_water_option, &vol::mist_water_height_option, &vol::mist_fall_option,
                &vol::mist_fall_height_option, &vol::fog_option, &vol::fog_preset_option, &vol::fog_start_option, &vol::fog_colour_option,
                &vol::clouds_option, &vol::cloud_amount_option, &vol::cloud_height_option, &vol::cloud_size_option, &vol::cloud_speed_option,
                &vol::file_option }) {
            recompui::config::set_option_page(*id, tooie::work_in_progress_tab_id);
        }
        // One heading a kind, so each can be tested on its own.
        recompui::config::set_option_group(vol::mist_option, "Volumetric Mist");
        recompui::config::set_option_group(vol::fog_option, "Volumetric Fog");
        recompui::config::set_option_group(vol::clouds_option, "Volumetric Clouds");
        recompui::config::set_option_group(vol::file_option, "Volumetric Levels");
    }
    tooie::volumetric_shadows::add_options(graphics);
    {
        // Volumetric shadows are WIP (L, 2026-10-23): the WIP tab, under their own heading, off by default.
        namespace vs = tooie::volumetric_shadows;
        for (const std::string* id : { &vs::sun_option, &vs::lamps_option, &vs::lamp_count_option, &vs::haze_option, &vs::quality_option,
                &vs::distance_option, &vs::view_option }) {
            recompui::config::set_option_page(*id, tooie::work_in_progress_tab_id);
        }
        recompui::config::set_option_group(vs::sun_option, "Volumetric Shadows");
    }
    {
        // Wet, snowy and dirty characters are WIP too (L, 2026-10-23): the WIP tab, under their own heading, off by default.
        namespace pf = tooie::picture_filters;
        for (const std::string* id : { &pf::char_wet_option, &pf::char_snow_option, &pf::char_dirt_option }) {
            recompui::config::set_option_page(*id, tooie::work_in_progress_tab_id);
        }
        recompui::config::set_option_group(pf::char_wet_option, "Character Surface");
    }
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
        "Field Of View",
        "Degrees added to the normal gameplay camera's field of view. Higher shows more around Banjo.",
        -10, 30, 1, 0, false, 0);
    graphics.add_number_option(
        tooie::cutscene_fov_offset_option,
        "Cutscene Field Of View",
        "Degrees added to the field of view in cutscenes and the game's fixed cameras (bosses, some puzzles).",
        -10, 20, 1, 0, false, 0);
    tooie::smaa::add_option(graphics);
    tooie::fxaa::add_option(graphics);
    tooie::api_restart::add_prompt(graphics);
    tooie::fsr::add_option(graphics);
    tooie::upscaler::add_option(graphics);
    // The Water entry (Original, Modern, Stylised) is WIP (L, 2026-10-23): it sits in the WIP tab.
    recompui::config::set_option_page(tooie::picture_filters::water_option, tooie::work_in_progress_tab_id);
    {
        // The upscalers are WIP (L, 2026-10-23): in the WIP tab. Still Graphics options, so they save to
        // graphics.json. The Upscaler drop-down is a collapsible menu over the rest (L, 2026-10-24).
        for (const std::string* id : { &tooie::upscaler::option, &tooie::upscaler::quality_option, &tooie::upscaler::hud_option, &tooie::upscaler::hud_full_option, &tooie::upscaler::reactive_option, &tooie::upscaler::object_motion_option, &tooie::upscaler::sharpness_option }) {
            recompui::config::set_option_page(*id, tooie::work_in_progress_tab_id);
        }
    }
    tooie::game_frame_rate::add_option(graphics);
    recompui::config::graphics::add_interpolation_options(graphics);
    tooie::low_latency::add_option(graphics);
    tooie::frame_readback::add_option(graphics);
    tooie::frame_overlay::add_option(graphics);

    // Section headings in the Graphics tab. The options of a group sit next to each other above, and a
    // heading hides with its option.
    recompui::config::set_option_group(recompui::config::graphics::options::res_option, "Display");
    recompui::config::set_option_group(tooie::picture_filters::preset_option, "Picture And Effects");
    // HD Shadows sits in the Sun shadows part of the Shaders group, with its own toggle (L, 2026-10-16).
    recompui::config::set_option_display_before(tooie::hd_shadows_option, tooie::picture_filters::sun_shadows_option);
    recompui::config::set_option_display_before(tooie::hd_shadows::enemy_direction_option, tooie::picture_filters::sun_shadows_option);
    recompui::config::set_option_display_before(tooie::hd_shadows::banjo_direction_option, tooie::picture_filters::sun_shadows_option);
    // Character Shaders (L, 2026-10-16): Banjo's fur and Kazooie's feathers, after the Shaders group.
    for (const std::string* option : { &tooie::picture_filters::character_section_option, &tooie::picture_filters::banjo_fur_option,
                                       &tooie::picture_filters::banjo_fur_length_option, &tooie::picture_filters::banjo_fur_density_option,
                                       &tooie::picture_filters::banjo_fur_noisiness_option, &tooie::picture_filters::kazooie_feathers_option,
                                       &tooie::picture_filters::kazooie_feather_size_option, &tooie::picture_filters::kazooie_feather_length_option,
                                       &tooie::picture_filters::kazooie_feather_density_option, &tooie::picture_filters::kazooie_feather_noisiness_option,
                                       &tooie::picture_filters::kazooie_feather_transparency_option, &tooie::picture_filters::npc_fur_option,
                                       &tooie::picture_filters::npc_fur_length_option, &tooie::picture_filters::npc_fur_density_option,
                                       &tooie::picture_filters::npc_fur_noisiness_option, &tooie::picture_filters::npc_feathers_option,
                                       &tooie::picture_filters::npc_feather_size_option, &tooie::picture_filters::npc_feather_length_option,
                                       &tooie::picture_filters::npc_feather_density_option, &tooie::picture_filters::npc_feather_noisiness_option,
                                       &tooie::picture_filters::npc_feather_transparency_option }) {
        recompui::config::set_option_display_before(*option, tooie::picture_filters::colour_grading_option);
    }
    recompui::config::set_option_group(tooie::picture_filters::character_section_option, "Character Shaders");
    // Colour Grading (L, 2026-10-23): its header sits under Colourblind Filter, and its four settings follow it.
    recompui::config::set_option_display_before(tooie::picture_filters::colour_grading_option, tooie::picture_filters::three_point_option);
    for (const std::string* option : { &tooie::picture_filters::contrast_option, &tooie::picture_filters::saturation_option,
                                       &tooie::picture_filters::vignette_option, &tooie::picture_filters::grain_option }) {
        recompui::config::set_option_display_before(*option, tooie::picture_filters::three_point_option);
    }
    // Tessellation (L, 2026-10-23): its switch sits above Tessellated Snow; Tessellated Sand comes after Tessellated
    // Snow's settings, before Parallax.
    recompui::config::set_option_display_before(tooie::picture_filters::tessellation_section_option, tooie::picture_filters::deep_snow_option);
    recompui::config::set_option_display_before(tooie::picture_filters::tessellated_sand_option, tooie::picture_filters::parallax_option);
    // 3D grass had its own section after the colour grading (L, 2026-10-16); it is in the WIP tab for now
    // (L, 2026-10-21), and gets set_option_group(grass_section_option, "Grass") back when it returns.
    // Ray Tracing has its own section after the grass, always shown (L, 2026-10-21).
    for (const std::string* option : { &tooie::picture_filters::ray_tracing_option, &tooie::picture_filters::ray_tracing_strength_option,
                                       &tooie::picture_filters::ray_tracing_reflections_option, &tooie::picture_filters::ray_tracing_water_reflections_option,
                                       &tooie::picture_filters::ray_tracing_metal_option, &tooie::picture_filters::ray_tracing_tiles_option,
                                       &tooie::picture_filters::ray_tracing_smooth_option, &tooie::picture_filters::ray_tracing_smoothing_option,
                                       &tooie::picture_filters::ray_tracing_brdf_option, &tooie::picture_filters::ray_tracing_subsurface_option,
                                       &tooie::picture_filters::path_tracing_option, &tooie::picture_filters::path_tracing_bounces_option,
                                       &tooie::picture_filters::traced_beams_option, &tooie::picture_filters::ray_tracing_player_shadows_option,
                                       &tooie::picture_filters::ray_tracing_hit_colours_option, &tooie::picture_filters::ray_tracing_resolution_option,
                                       &tooie::picture_filters::ray_tracing_parallax_option,
                                       &tooie::picture_filters::ray_detail_half_option, &tooie::picture_filters::ray_detail_quarter_option }) {
        recompui::config::set_option_display_before(*option, tooie::high_detail_models_option);
    }
    recompui::config::set_option_group(tooie::picture_filters::ray_tracing_option, "Ray Tracing");
    recompui::config::set_option_group(tooie::high_detail_models_option, "Game View");
    // MSAA is added by the frontend with the display options; show it with the other anti-aliasing (L).
    // Anti-Aliasing and Scaling sit at the bottom of the Display tab (L, 2026-10-24), in this order.
    recompui::config::set_option_display_last(recompui::config::graphics::options::msaa_option);
    recompui::config::set_option_display_last(tooie::smaa::option);
    recompui::config::set_option_display_last(tooie::fxaa::option);
    recompui::config::set_option_display_last(tooie::fsr::option);
    recompui::config::set_option_group(recompui::config::graphics::options::msaa_option, "Anti-Aliasing And Scaling");
    recompui::config::set_option_group(tooie::game_frame_rate::option, "Frame Rate And Overlay");
    recompui::config::set_option_group(tooie::effect_views::option, "Debug");

    // Display tab under Graphics (L, 2026-10-23; was Performance, L 2026-10-16): the Display section, Anti-Aliasing
    // and Scaling, and the frame rate and latency options. They stay in the graphics config (graphics.json), so
    // saving and the code that reads them don't change.
    recompui::config::create_page_tab("Display", tooie::performance_tab_id, recompui::config::graphics::id);
    for (const std::string* id : { &tooie::game_frame_rate::option, &recompui::config::graphics::options::rr_option,
            &recompui::config::graphics::options::rr_manual_value, &tooie::low_latency::option,
            &tooie::frame_readback::option, &tooie::frame_overlay::option,
            &recompui::config::graphics::options::res_option, &recompui::config::graphics::options::ds_option,
            &recompui::config::graphics::options::ar_option, &recompui::config::graphics::options::wm_option,
            &recompui::config::graphics::options::hr_option, &recompui::config::graphics::options::api_option,
            &recompui::config::graphics::options::msaa_option, &tooie::smaa::option, &tooie::fxaa::option,
            &tooie::fsr::option }) {
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
    tooie::photo_album::create_tab();
    recompui::config::create_search_tab();
    recompui::config::create_mods_tab();

    // Work-in-progress and developer features (L, 2026-10-13), shown with General > DEV tab.
    recomp::config::Config& wip = recompui::config::create_config_tab("DEV", tooie::wip_tab_id, false);
    // Dumps moved here from General (L, 2026-10-15): they are read from the DEV tab. One Dump heading (L, 2026-10-23).
    wip.add_enum_option(
        tooie::texture_dump_option,
        "Texture Dump",
        "Saves every texture the game draws to the texture_dump folder, for making texture packs: each as a PNG named by its RT64 hash, with an rt64.json, plus RT64's raw dump files. <recomp-color primary>While playing</recomp-color> saves what you see as you play. <recomp-color primary>Sweep all maps</recomp-color> warps through every map by itself and turns the camera around in each, which takes about 40 minutes; load a spare save file first, since the game may save in odd places. It asks before it starts, and it keeps going after a restart (a map the game stopped in is skipped) until it is done or you set this to Off.",
        {
            {tooie::TextureDump::Off, "Off", "Off"},
            {tooie::TextureDump::WhilePlaying, "WhilePlaying", "While playing"},
            {tooie::TextureDump::SweepAllMaps, "SweepAllMaps", "Sweep all maps"},
        },
        tooie::TextureDump::Off);
    wip.add_bool_option(
        tooie::asset_dump_option,
        "Dump Assets",
        "Writes every model, animation, sprite and other game asset to the asset_dump folder as asset_<id>.bin, with assets.txt listing them (kind 0 is a model). Takes a few seconds. To replace an asset, put an edited asset_<id>.bin in mods/assets: it loads in place of the game's, at any size, the next time the game loads it.",
        false);
    wip.add_bool_option(
        tooie::sound_dump_option,
        "Dump Sounds",
        "Saves the game's sounds as WAV files to the sound_dump folder, sorted into a folder for each sound bank and instrument (bank0_0/inst3/snd12_rom01A2B40_22050hz_1ch.wav), with index.txt listing each one's place in the ROM. Each sound is written once, as banks load while you play, so visit different areas to collect more. Samples are saved at the bank's rate; the game bends some sounds' pitch when it plays them.",
        false);
    recompui::config::set_option_group(tooie::texture_dump_option, "Dump");
    tooie::texture_sweep::add_prompt(wip);
    tooie::memory_guard::add_option(wip);
    // Pass Over Crashes through the two Force Interpolation options (L, 2026-10-23): one heading on the first.
    recompui::config::set_option_group(tooie::memory_guard::option, "Stability And Features");
    wip.add_bool_option(
        tooie::more_memory::option,
        "More Game Memory",
        "Gives the game a bigger memory heap, bigger buffers for drawing and animations, and 48 sound voices instead of 24, so scenes crowded with characters do not crash and fewer sounds cut out. Takes effect the next time the game starts.",
        true);
    // L, 2026-10-17: a vanilla issue, so a blending option, on by default.
    wip.add_bool_option(
        tooie::picture_filters::texture_seams_option,
        "Blend Texture Seams",
        "Smooths the lines where the pieces of a picture drawn in parts meet, such as the title screen's logo. The game clamps each piece at its edge, which on the N64 is a fraction of a pixel but shows as a line at high resolutions; this carries each piece's shading on to its edge so the pieces blend.",
        true);
    // L, 2026-10-17: on by default; the game's own widescreen mode is for stretched TVs.
    wip.add_bool_option(
        tooie::hide_vanilla_widescreen_option,
        "Hide Unnecessary Settings Entry",
        "Hides the settings entries this port makes unnecessary: Wide-screen Mode and Screen Alignment in the global settings on the save select screen (the TV) and in the Start menu's Settings page, leaving Speaker Mode, and while it is on keeps the game's own widescreen mode off and the picture centred: the game's widescreen squashes the picture for a stretched TV, and this port's widescreen is Aspect Ratio in the Graphics tab. The menu change shows the next time it opens.",
        true);
    tooie::game_frame_rate::add_dev_options(wip);
    // L, 2026-10-23: under Stability And Features, on by default.
    wip.add_bool_option(
        tooie::hide_pause_settings_option,
        "Hide Custom Settings In Start Menu",
        "Leaves out the SETTINGS entry this port adds to the Start menu (the pause menu). Speaker Mode stays in the global settings on the save select screen (the TV). The change shows the next time the Start menu opens.",
        true);
    // L, 2026-10-24: under Stability And Features, on by default.
    tooie::hand_cursor::add_option(wip);
    // Debug options (under the Debug heading): they moved here from Graphics.
    tooie::effect_views::add_option(wip);
    // Picker Save Only Current Active sits under the same Debug heading (L, 2026-10-23).
    tooie::parallax_pick::add_dev_option(wip);
    tooie::interp_check::add_options(wip);
    tooie::texture_slide::add_option(wip);
    tooie::debug::add_heap_check_option(wip);
    tooie::aim_trace::add_option(wip);
    tooie::save_state::add_ram_dump_option(wip);
    // Additional Tabs (L, 2026-10-16): switches for the tabs that are hidden or shown as wanted.
    wip.add_bool_option(
        tooie::achievements_tab_option,
        "Achievements Tab",
        "Shows the Achievements tab. Achievements are still earned while it is hidden, and the Start menu's Achievements page always shows them.",
        false);
    wip.add_option_change_callback(tooie::achievements_tab_option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext) {
            show_achievements_tab();
        });
    wip.add_bool_option(
        tooie::cheats_tab_option,
        "Cheats Tab",
        "Shows the Cheats tab. Turn it off to hide it; cheats that are already on stay on. A dev.txt file next to the game's exe shows it whatever this says.",
        // Off by default (L, 2026-10-23); dev.txt shows it.
        false);
    wip.add_option_change_callback(tooie::cheats_tab_option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext) {
            show_cheats_tab();
        });
    tooie::level_warp::add_option(wip);
    recompui::config::set_option_group(tooie::achievements_tab_option, "Additional Tabs");

    move_saved_hud_placement();
    move_saved_canary_mary();
    move_saved_menu_mouse();
    turn_on_saved_smooth_walls();
    split_saved_toon_shading();
    tooie::menu_tree::classify();
    recompui::config::finalize();
    tooie::cheats::reset_on_start();
    move_saved_options_to_graphics();
    show_wip_tab();
    move_saved_tab_options();
    turn_off_cheats_tab_once();
    show_cheats_tab();
    show_achievements_tab();
    tooie::level_warp::refresh();
    move_saved_cutscene_skip();
    turn_on_transform_anywhere_once();
    move_saved_options_to_wip();
    default_mouse_sensitivity();
    // The settings menu's layout (L, 2026-10-16): tabs in a sidebar on the left, descriptions along the bottom.
    recompui::config::set_sidebar_layout(true);
    tooie::picture_filters::apply();
    tooie::smaa::apply();
    tooie::texture_slide::apply();
    tooie::debug::apply_heap_check();
    tooie::fxaa::apply();
    tooie::mirror_mode::apply();
    tooie::fsr::apply();
    tooie::upscaler::apply();
    tooie::low_latency::apply();
    tooie::frame_readback::apply();
}
