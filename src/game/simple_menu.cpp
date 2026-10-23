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
    // Number options that stay visible as a plain slider: effects that are only a slider (nothing else to
    // tune), and settings that are not effects.
    const std::unordered_set<std::string> kept_sliders = {
        "Brightness", "Field of View", "Cutscene Field of View", "Day Length", "Sharpening",
        "Ambient occlusion", "SSGI", "Bounce light", "Rim light", "Toon shading: Characters",
        "Toon shading: World", "Mist", "Parallax", "Traced reflections", "Traced light beams",
        "Screen-space reflections", "Water reflections", "Ice reflections", "Heat haze",
        "Light shafts", "Bloom", "Eye adaptation", "Cutscene depth of field", "Depth of field",
        "Vignette", "Film grain", "Contrast", "Colour saturation",
    };

    // Options with options under them. A parent number option shows as an on/off switch (off is 0, on is the
    // last non-zero value; the first "on" is the default, or half the range when the default is 0) with an
    // arrow that opens its children, which are hidden until then.
    struct Family {
        const char* parent;
        std::vector<const char*> children;
    };
    const std::vector<Family> effect_families = {
        { "Toon outlines", { "Toon outline thickness" } },
        { "Water waves", { "Water wave speed", "Water detail" } },
        { "Underwater tint", { "Underwater haze", "Underwater distortion" } },
        { "Displaced ground", { "Displaced ground distance" } },
        { "Banjo fur", { "Banjo fur length", "Banjo fur density", "Banjo fur noisiness" } },
        { "Kazooie feathers", { "Kazooie feather size", "Kazooie feather length", "Kazooie feather density",
            "Kazooie feather noisiness", "Kazooie feather transparency" } },
        { "NPC fur", { "NPC fur length", "NPC fur density", "NPC fur noisiness" } },
        { "NPC feathers", { "NPC feather size", "NPC feather length", "NPC feather density",
            "NPC feather noisiness", "NPC feather transparency" } },
        { "Sun shadows", { "Sun shadow softness", "Sun shadow distance" } },
        { "Fog", { "Fog start distance", "Fog colour" } },
        { "3D grass", { "3D grass height", "3D grass distance", "3D grass density", "3D grass patches",
            "3D grass thickness", "3D grass random length", "3D grass blending", "Chunky 3D grass",
            "Chunking",
            "3D grass LOD", "3D grass in ray tracing" } },
        { { "Chunk size" } },
        { "Pixelated 3D grass", { "Pixel size" } },
    };

    // The jiggle switches under the Jiggle switch; each owns the options named "<name>: ...".
    const char* const jiggle_master = "Jiggle";
    const char* const jiggle_parts[] = {
        "Snout jiggle", "Belly jiggle", "Ear jiggle", "Fur jiggle", "Backpack jiggle", "Kazooie jiggle", "Mumbo jiggle",
    };

    // Options (any type) hidden in Simple, whatever tab they are in.
    const std::unordered_set<std::string> advanced_names = {
        // Graphics: tuning and debugging.
        "Brightness test pattern", "Ray tracing hit colours", "Ray tracing uses Parallax materials",
        "Parallax on original textures", "Traced shadows of the player", "Ray tracing resolution",
        "Mist Time",
        "HD Shadows: Enemies", "HD Shadows: Banjo",
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
    const char* const advanced_number_prefixes[] = { "Photo " };

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
        "<recomp-color primary>On</recomp-color>: an effect with settings of its own is a single on/off switch (a "
        "plain slider stays a slider), and the tuning sliders, photo mode and free camera extras, debug options and the DEV tab are hidden. "
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
    auto id_of = [](recomp::config::Config* config, const std::string& name) -> std::string {
        for (const auto& opt : config->get_config_schema().options) {
            if (opt.name == name) {
                return opt.id;
            }
        }
        return std::string();
    };
    auto parent_of = [&](recomp::config::Config* config, const std::string& child, const std::string& parent) {
        const std::string child_id = id_of(config, child);
        const std::string parent_id = id_of(config, parent);
        if (child_id.empty() || parent_id.empty()) {
            printf("[simple-menu] no option to put \"%s\" under \"%s\"\n", child.c_str(), parent.c_str());
            return;
        }
        config->set_option_parent(child_id, parent_id);
        used.insert(child);
        used.insert(parent);
    };

    // Names that sit under a parent: not tuning clutter, shown when their parent is open.
    std::unordered_set<std::string> under_parent;
    recomp::config::Config* graphics = &recompui::config::get_graphics_config();
    for (const Family& family : effect_families) {
        for (const char* child : family.children) {
            parent_of(graphics, child, family.parent);
            under_parent.insert(child);
        }
        under_parent.insert(family.parent);
    }

    // Jiggle: one switch (off by default) over the seven body parts (on by default), each over its sliders.
    recomp::config::Config* general = &recompui::config::get_general_config();
    std::vector<std::string> jiggle_ids;
    for (const char* part : jiggle_parts) {
        parent_of(general, part, jiggle_master);
        jiggle_ids.push_back(id_of(general, part));
        const std::string prefix = std::string(part) + ":";
        for (const auto& opt : general->get_config_schema().options) {
            if (starts_with(opt.name, prefix.c_str())) {
                parent_of(general, opt.name, part);
                jiggle_ids.push_back(opt.id);
            }
        }
    }
    jiggle_ids.push_back(id_of(general, jiggle_master));
    for (const std::string& id : jiggle_ids) {
        if (!id.empty()) {
            recompui::config::set_option_page(id, tooie::gameplay_tab_id);
        }
    }

    for (recomp::config::Config* config : all_configs()) {
        const auto& options = config->get_config_schema().options;
        for (const auto& opt : options) {
            const bool is_number = opt.type == recomp::config::ConfigOptionType::Number;
            if (is_number && kept_sliders.contains(opt.name)) {
                used.insert(opt.name);
            } else if (is_number && !under_parent.contains(opt.name)) {
                // Every other graphics slider is tuning; in the other tabs only the listed prefixes are.
                bool advanced = config == graphics;
                for (const char* prefix : advanced_number_prefixes) {
                    advanced = advanced || starts_with(opt.name, prefix);
                }
                if (advanced) {
                    config->set_option_advanced(opt.id);
                }
            }
            if (advanced_names.contains(opt.name)) {
                config->set_option_advanced(opt.id);
                used.insert(opt.name);
            }
        }
    }
    try {
        for (const std::string& id : advanced_graphics_ids()) {
            graphics->set_option_advanced(id);
        }
    } catch (...) {
    }
    for (const auto* names : { &kept_sliders, &advanced_names }) {
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
