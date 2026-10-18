#ifndef __TOOIE_DEV_FILES_H__
#define __TOOIE_DEV_FILES_H__

// The Dev Files folder next to the save files: the text files the pick and tag modes write for L to send in
// (parallax_tags.txt, interp_tags.txt, shader_effect_tags.txt). It is made when the first of them is written.
#include <filesystem>
#include <system_error>

#include "librecomp/game.hpp"

namespace tooie::dev_files {
    inline std::filesystem::path folder() {
        return recomp::get_config_path() / "Dev Files";
    }

    // Where a dev file is written.
    inline std::filesystem::path path(const char* name) {
        return folder() / name;
    }

    // Where a dev file is read from: Dev Files, or next to the save files where builds before it kept it.
    inline std::filesystem::path read_path(const char* name) {
        std::error_code ec;
        const std::filesystem::path in_folder = path(name);
        if (std::filesystem::exists(in_folder, ec)) {
            return in_folder;
        }
        const std::filesystem::path old = recomp::get_config_path() / name;
        return std::filesystem::exists(old, ec) ? old : in_folder;
    }
}

#endif
