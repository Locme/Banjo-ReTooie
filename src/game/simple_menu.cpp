// Simple / Advanced settings menu (see tooie_simple_menu.h).
//
// Options are told apart by their on-screen names, so a rename in the menu needs the same change
// here; classify() logs any name that matches nothing.

#include <cstdio>
#include <string>
#include <unordered_set>
#include <variant>
#include <vector>

#include "librecomp/config.hpp"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_simple_menu.h"

namespace {
    // Number options that stay visible in Simple as a plain slider.
    const std::unordered_set<std::string> kept_sliders = {
        "Brightness", "Field of View", "Cutscene Field of View", "Day Length",
    };

    // Number options whose main use is on/off: Simple shows them as a switch (off is 0, on is the
    // last non-zero value; the first "on" is the default, or half the range when the default is 0).
    const std::unordered_set<std::string> toggle_names = {
        "Sharpening", "Ambient occlusion", "SSGI", "Bounce light", "Toon outlines", "Rim light",
        "Toon shading: Characters", "Toon shading: World", "Water waves", "Mist", "Parallax",
        "Displaced ground", "Traced reflections", "Traced light beams", "Screen-space reflections",
        "Water reflections", "Ice reflections", "Banjo fur", "Kazooie feathers", "NPC fur",
        "NPC feathers", "Heat haze", "Sun shadows", "Light shafts", "Bloom", "Eye adaptation",
        "Cutscene depth of field", "Depth of field", "Fog", "Vignette", "Film grain", "3D grass",
    };

    // Options (any type) hidden in Simple, whatever tab they are in.
    const std::unordered_set<std::string> advanced_names = {
        // Graphics: tuning and debugging.
        "Brightness test pattern", "Ray tracing hit colours", "Ray tracing uses Parallax materials",
        "Parallax on original textures", "Traced shadows of the player", "Ray tracing resolution",
        "Sun shadow on Banjo", "Fog colour", "Mist Time", "Chunky 3D grass", "Pixelated 3D grass",
        "3D grass on edges", "Frustum culling", "Occlusion culling", "Chunking", "30 FPS 3D grass",
        "3D grass in ray tracing", "HD Shadows: Enemies", "HD Shadows: Banjo",
        "Interpolation check", "Interpolation blend mode", "Effect debug view", "Effect compare",
        "Frame Read-Back", "Frame rate overlay",
        "Free camera: ease back", "Free camera: floor clearance", "Free camera: look up",
        // General.
        "Save backups to keep", "Compile all shaders at start", "Enemy aim: aimed shots",
        "Enemy aim: homing shots",
        // QOL.
        "Free camera speed", "Free camera: invert left/right", "Free camera: invert up/down",
        "Free camera: smooth walls", "Fine aim speed", "Mouse and gyro aim: invert up/down",
        "Photo mode camera collision",
    };

    // Name prefixes of number options that are tuning sliders.
    const char* const advanced_number_prefixes[] = {
        "Snout jiggle:", "Belly jiggle:", "Ear jiggle:", "Fur jiggle:", "Backpack jiggle:",
        "Kazooie jiggle:", "Photo ",
    };

    // Options found by id rather than name (their names are not worth repeating here).
    std::vector<std::string> advanced_graphics_ids() {
        return { recompui::config::graphics::options::rr_manual_value };
    }

    bool starts_with(const std::string& s, const char* prefix) {
        return s.rfind(prefix, 0) == 0;
    }

    std::vector<recomp::config::Config*> all_configs() {
        std::vector<recomp::config::Config*> configs;
        auto add = [&](recomp::config::Config& (*get)()) {
            try {
                configs.push_back(&get());
            } catch (...) {
            }
        };
        add(recompui::config::get_general_config);
        add(recompui::config::get_graphics_config);
        add(recompui::config::get_sound_config);
        for (const std::string& id : { tooie::qol_tab_id, tooie::wip_tab_id }) {
            try {
                configs.push_back(&recompui::config::get_config(id));
            } catch (...) {
            }
        }
        return configs;
    }

    // Counts the advanced options that no longer have their default value.
    size_t changed_advanced_count() {
        size_t changed = 0;
        for (recomp::config::Config* config : all_configs()) {
            const auto& options = config->get_config_schema().options;
            for (size_t i = 0; i < options.size(); i++) {
                if (!config->is_option_advanced(i)) {
                    continue;
                }
                try {
                    const auto value = config->get_option_value(options[i].id);
                    if (const auto* num = std::get_if<recomp::config::ConfigOptionNumber>(&options[i].variant)) {
                        changed += std::get<double>(value) != num->default_value;
                    } else if (const auto* flag = std::get_if<recomp::config::ConfigOptionBool>(&options[i].variant)) {
                        changed += std::get<bool>(value) != flag->default_value;
                    } else if (const auto* en = std::get_if<recomp::config::ConfigOptionEnum>(&options[i].variant)) {
                        changed += std::get<uint32_t>(value) != en->default_value;
                    }
                } catch (...) {
                }
            }
        }
        return changed;
    }

    const std::string base_description =
        "<recomp-color primary>On</recomp-color>: each effect is a single on/off switch, and the tuning "
        "sliders, photo mode and free camera extras, debug options and the DEV tab are hidden. "
        "<recomp-color primary>Off</recomp-color> (Advanced): everything is shown. Hidden settings keep "
        "their values and keep working, and Search still finds them.";
}

void tooie::simple_menu::add_option(recomp::config::Config& general) {
    general.add_bool_option(option, "Simple menu", base_description, true);
    recompui::config::set_option_group(option, "Menu");
}

bool tooie::simple_menu::on() {
    try {
        return std::get<bool>(recompui::config::get_general_config().get_option_value(option));
    } catch (...) {
        return true;
    }
}

void tooie::simple_menu::classify() {
    std::unordered_set<std::string> used;
    for (recomp::config::Config* config : all_configs()) {
        const auto& options = config->get_config_schema().options;
        for (const auto& opt : options) {
            const bool is_number = opt.type == recomp::config::ConfigOptionType::Number;
            if (is_number && toggle_names.contains(opt.name)) {
                config->set_option_simple_toggle(opt.id);
                used.insert(opt.name);
            } else if (is_number && !kept_sliders.contains(opt.name)) {
                // Every other graphics slider is tuning; in the other tabs only the listed prefixes are.
                bool advanced = config == &recompui::config::get_graphics_config();
                for (const char* prefix : advanced_number_prefixes) {
                    advanced = advanced || starts_with(opt.name, prefix);
                }
                if (advanced) {
                    config->set_option_advanced(opt.id);
                }
            } else if (is_number) {
                used.insert(opt.name);
            }
            if (advanced_names.contains(opt.name)) {
                config->set_option_advanced(opt.id);
                used.insert(opt.name);
            }
        }
    }
    try {
        for (const std::string& id : advanced_graphics_ids()) {
            recompui::config::get_graphics_config().set_option_advanced(id);
        }
    } catch (...) {
    }
    for (const auto* names : { &toggle_names, &kept_sliders, &advanced_names }) {
        for (const std::string& name : *names) {
            if (!used.contains(name)) {
                printf("[simple-menu] no option is named \"%s\"\n", name.c_str());
            }
        }
    }
}

void tooie::simple_menu::apply(void (*refresh_tabs)()) {
    const bool simple = on();
    for (recomp::config::Config* config : all_configs()) {
        config->set_simple_mode(simple);
    }
    if (refresh_tabs != nullptr) {
        refresh_tabs();
    }
    const size_t changed = changed_advanced_count();
    std::string description = base_description;
    if (simple && changed > 0) {
        description += " <recomp-color primary>" + std::to_string(changed) + " hidden advanced setting" +
            (changed == 1 ? " differs" : "s differ") + " from the default.</recomp-color>";
    }
    try {
        recompui::config::get_general_config().update_option_description(option, description);
    } catch (...) {
    }
    printf("[simple-menu] %s, %zu hidden settings changed\n", simple ? "simple" : "advanced", changed);
}
