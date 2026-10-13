#include <filesystem>

#include "tooie_game.h"
#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "librecomp/game.hpp"

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
    general.add_number_option(
        tooie::save_backups_keep_option,
        "Save backups to keep",
        "How many of the newest save backups to keep.",
        1, 100, 1, 0, false, 10);

    recompui::config::create_graphics_tab();
    recompui::config::create_controls_tab();
    recompui::config::create_sound_tab();
    recompui::config::create_mods_tab();

    recompui::config::finalize();
}
