// Openable settings (see tooie_menu_tree.h).
//
// Options are matched by their on-screen names (case ignored), so a rename in the menu needs the same change
// here; classify() logs any name that matches nothing.

#include <cctype>
#include <cstdio>
#include <string>
#include <vector>

#include "librecomp/config.hpp"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_free_camera.h"
#include "tooie_water_camera.h"
#include "tooie_menu_tree.h"
#include "tooie_picture_filters.h"
#include "tooie_snout_jiggle.h"

namespace {
    // Menu names change case now and then ("Fog start distance", "Fog Start Distance"), so names are
    // compared in lower case.
    std::string lc(std::string s) {
        for (char& c : s) {
            c = (char)std::tolower((unsigned char)c);
        }
        return s;
    }

    // Options with options under them. A parent number option shows an on/off switch (off is 0, on is the last
    // non-zero value) with an arrow that opens its slider (a "Strength" line) and its children, hidden until then.
    struct Family {
        const char* parent;
        std::vector<const char*> children;
    };
    const std::vector<Family> effect_families = {
        { "Toon outlines", { "Toon outline thickness" } },
        { "Water waves", { "Water wave speed", "Water detail" } },
        { "Underwater tint", { "Underwater haze", "Underwater distortion" } },
        { "Displaced ground", { "Displaced ground distance" } },
        { "Kazooie feathers", { "Kazooie feather size", "Kazooie feather length", "Kazooie feather density",
            "Kazooie feather noisiness", "Kazooie feather transparency" } },
        { "NPC feathers", { "NPC feather size", "NPC feather length", "NPC feather density",
            "NPC feather noisiness", "NPC feather transparency" } },
        { "Sun shadows", { "Sun Shadow On Banjo", "Sun shadow softness", "Sun shadow distance" } },
        { "Parallax", { "Parallax On Original Textures", "Parallax Smoothness" } },
        { "Fog", { "Fog start distance", "Fog colour" } },
    };

}

void tooie::menu_tree::classify() {
    auto id_of = [](recomp::config::Config* config, const std::string& name) -> std::string {
        for (const auto& opt : config->get_config_schema().options) {
            if (lc(opt.name) == lc(name)) {
                return opt.id;
            }
        }
        return std::string();
    };
    auto parent_of = [&](recomp::config::Config* config, const std::string& child, const std::string& parent) {
        const std::string child_id = id_of(config, child);
        const std::string parent_id = id_of(config, parent);
        if (child_id.empty() || parent_id.empty()) {
            printf("[menu-tree] no option to put \"%s\" under \"%s\"\n", child.c_str(), parent.c_str());
            return;
        }
        config->set_option_parent(child_id, parent_id);
    };

    recomp::config::Config* graphics = &recompui::config::get_graphics_config();
    for (const Family& family : effect_families) {
        for (const char* child : family.children) {
            parent_of(graphics, child, family.parent);
        }
    }

    // Reflections, Toon Shading and Free Camera are collapsible menus (L, 2026-10-23): each switch is an enable
    // switch, and its settings open under it. Ray Tracing's settings show under Graphics > Lighting when it is set
    // to Ray Tracing instead (L, 2026-11-12; picture_filters.cpp).
    {
        using namespace tooie::picture_filters;
        const std::vector<std::pair<const std::string*, std::vector<const std::string*>>> groups = {
            { &reflections_section_option, { &ssr_option, &ssr_stochastic_option, &water_reflections_option,
                &ice_reflections_option } },
            { &toon_section_option, { &toon_style_option, &toon_characters_option, &toon_world_option } },
            { &tessellation_section_option, { &deep_snow_option, &tessellated_sand_option } },
            { &deep_snow_option, { &snow_height_option, &snow_detail_option, &snow_refill_option, &snow_lod_option } },
            { &grass_option, { &grass_density_option, &grass_distance_option, &grass_height_option, &grass_type_option, &grass_patches_option, &grass_long_option, &grass_long_height_option, &grass_flowers_option, &grass_flower_amount_option, &grass_flower_beds_option, &grass_bed_size_option, &critter_insects_option, &critter_fish_option, &critter_amount_option } },
            // Banjo Fur and NPC Fur: each coat's settings sit under its choice (only the chosen coat's show,
            // picture_filters.cpp), so they read as part of it (L, 2026-11-15). The Character Shaders menu is gone.
            { &fur_option, { &clump_fur_option, &clump_fur_size_option, &clump_fur_length_option, &banjo_fur_option,
                &banjo_fur_length_option, &banjo_fur_density_option, &banjo_fur_noisiness_option } },
            { &npc_fur_style_option, { &npc_clump_fur_option, &npc_clump_fur_size_option, &npc_clump_fur_length_option,
                &npc_fur_option, &npc_fur_length_option, &npc_fur_density_option, &npc_fur_noisiness_option } },
        };
        recomp::config::Config* graphics_config = &recompui::config::get_graphics_config();
        for (const auto& group : groups) {
            for (const std::string* child : group.second) {
                graphics_config->set_option_parent(*child, *group.first);
            }
        }
        // The fur choices start open, so a coat's settings show as soon as it is picked.
        for (const std::string* open : { &fur_option, &npc_fur_style_option }) {
            const auto& by_id = graphics_config->get_config_schema().options_by_id;
            if (const auto found = by_id.find(*open); found != by_id.end()) {
                graphics_config->set_option_expanded(found->second, true);
            }
        }
        // (Each grass and flower kind's switch under 3D Grass too.)
        for (const GrassKindOption& kind : grass_kind_options) {
            graphics_config->set_option_parent(kind.id, grass_option);
        }
    }
    {
        recomp::config::Config* qol = &recompui::config::get_config(tooie::qol_tab_id);
        const std::vector<const std::string*> rows = { &tooie::free_camera_speed_option, &tooie::free_camera_invert_x_option,
            &tooie::free_camera_invert_y_option, &tooie::free_camera_smooth_walls_option, &tooie::free_camera_ease_back_option,
            &tooie::free_camera_smooth_height_option, &tooie::free_camera_hover_option, &tooie::free_camera_mouse_option,
            &tooie::free_camera_gyro_option, &tooie::free_camera_floor_clearance_option, &tooie::free_camera_look_up_option };
        for (const std::string* row : rows) {
            qol->set_option_parent(*row, tooie::free_camera_option);
        }
        const std::vector<const std::string*> water_rows = { &tooie::water_camera_waterline_option,
            &tooie::water_camera_splash_option, &tooie::water_camera_bob_option, &tooie::water_camera_drag_option,
            &tooie::water_camera_follow_option, &tooie::water_camera_torpedo_option, &tooie::water_camera_look_up_option };
        for (const std::string* row : water_rows) {
            qol->set_option_parent(*row, tooie::water_camera_option);
        }
    }

    // Jiggle: one switch (off by default) over the seven body parts (on by default), each over its sliders.
    // Found by id: the sliders' names change with the menu wording.
    recomp::config::Config* general = &recompui::config::get_general_config();
    {
        using namespace tooie::snout_jiggle;
        struct Part {
            const std::string* option;
            std::vector<const std::string*> children;
        };
        const std::vector<Part> parts = {
            { &tooie::snout_jiggle::option, { &stiffness_option, &damping_option, &mass_option, &squash_in_option, &squash_walk_option,
                &squash_out_option, &squash_across_option, &nose_option } },
            { &belly_option, { &belly_stiffness_option, &belly_damping_option, &belly_mass_option,
                &belly_squash_in_option, &belly_squash_out_option, &belly_squash_across_option } },
            { &ears_option, { &ears_stiffness_option, &ears_damping_option, &ears_mass_option, &ears_squash_option } },
            { &fur_option, { &fur_stiffness_option, &fur_damping_option, &fur_mass_option, &fur_sway_option } },
            { &body_option, { &body_stiffness_option, &body_damping_option, &body_mass_option, &body_squash_option,
                &body_tilt_option } },
            { &kazooie_option, { &kazooie_stiffness_option, &kazooie_damping_option, &kazooie_mass_option,
                &kazooie_squash_in_option, &kazooie_squash_out_option, &kazooie_squash_across_option } },
            { &mumbo_option, {} },
        };
        recompui::config::set_option_page(master_option, tooie::gameplay_tab_id);
        for (const Part& part : parts) {
            general->set_option_parent(*part.option, master_option);
            recompui::config::set_option_page(*part.option, tooie::gameplay_tab_id);
            for (const std::string* child : part.children) {
                general->set_option_parent(*child, *part.option);
                recompui::config::set_option_page(*child, tooie::gameplay_tab_id);
            }
        }
    }

}
