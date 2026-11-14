// Texture packs and asset mods dropped into the mods folder as a .zip.
//
// The mod loader takes .nrm mods, .rtz texture packs and unpacked mod folders.
// Texture packs made for RT64 are often shipped as a plain .zip with the pack
// one folder down (BT Reloaded: "BANJO TOOIE/rt64.json", "BANJO TOOIE/mod.json"
// and the PNGs). Asset mods (model mods such as Smash Banjo) come the same way,
// with an assets.json instead of or next to the rt64.json. At startup, before
// the mods are scanned, every .zip in the mods folder that holds an rt64.json,
// an assets.json or a translations.json (a language mod) is unpacked into a folder named after the zip, which the loader
// then opens like any other mod folder. Refresh Mods does the same; in game it only
// unpacks zips that have no folder yet, which the refresh then opens next to the loaded mods. A marker file in
// that folder remembers which zip (size and date) it came from, so the zip is
// only unpacked again when it changes. A pack without a mod.json gets a small
// one so the loader accepts the folder. At startup the window says "Installing Mods"
// (src/main/boot_screen.cpp) while a zip unpacks, as nothing else is drawn yet.

#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <string>

#include "miniz.h"
#include "librecomp/mods.hpp"
#include "tooie_boot_screen.h"
#include "tooie_game.h"

namespace {
    namespace fs = std::filesystem;

    constexpr const char* marker_name = ".unpacked_from_zip";

    // Set during the scan at startup: unpacking shows the "Installing Mods" screen.
    bool show_boot_screen = false;

    std::string zip_stamp(const fs::path& zip) {
        std::error_code ec;
        auto size = fs::file_size(zip, ec);
        // The tick count is a 128-bit integer with libc++ (Android), which std::to_string does not take.
        auto time = static_cast<long long>(fs::last_write_time(zip, ec).time_since_epoch().count());
        return std::to_string(size) + " " + std::to_string(time);
    }

    std::string read_text(const fs::path& path) {
        std::ifstream in(path, std::ios::binary);
        return std::string(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
    }

    std::string json_escape(const std::string& text) {
        std::string out;
        for (char c : text) {
            if (c == '"' || c == '\\') out += '\\';
            out += c;
        }
        return out;
    }

    // The folder inside the zip that holds rt64.json, assets.json or translations.json ("" for the root, else
    // ending in '/'). False if the zip has neither.
    bool find_pack_root(mz_zip_archive& zip, std::string& root) {
        bool found = false;
        mz_uint count = mz_zip_reader_get_num_files(&zip);
        for (mz_uint i = 0; i < count; i++) {
            char name[1024];
            if (mz_zip_reader_get_filename(&zip, i, name, sizeof(name)) == 0) {
                continue;
            }
            std::string entry = name;
            std::string dir;
            bool matched = false;
            for (const std::string file : {"rt64.json", "assets.json", "translations.json"}) {
                if (entry.size() >= file.size() && entry.compare(entry.size() - file.size(), file.size(), file) == 0) {
                    dir = entry.substr(0, entry.size() - file.size());
                    matched = true;
                }
            }
            if (!matched) {
                continue;
            }
            if (!dir.empty() && dir.back() != '/') {
                continue;
            }
            if (!found || dir.size() < root.size()) {
                root = dir;
                found = true;
            }
        }
        return found;
    }

    // An entry may only land inside the folder it is unpacked into. A zip can name "/x", "C:x", "C:/x" or
    // "a/../../x": on Windows "/x" and "C:x" are not absolute, yet target / "/x" goes to the root of the drive.
    bool safe_relative(const fs::path& relative) {
        if (relative.empty() || relative.is_absolute() || relative.has_root_name() || relative.has_root_directory()) {
            return false;
        }
        for (const fs::path& part : relative) {
            if (part == "..") {
                return false;
            }
        }
        return true;
    }

    // out, normalised, starts with every element of target.
    bool inside(const fs::path& target, const fs::path& out) {
        const fs::path base = target.lexically_normal();
        const fs::path full = out.lexically_normal();
        auto b = base.begin();
        auto f = full.begin();
        for (; b != base.end(); ++b, ++f) {
            if (b->empty() && std::next(b) == base.end()) {
                break; // a trailing separator
            }
            if (f == full.end() || *b != *f) {
                return false;
            }
        }
        return f != full.end();
    }

    bool unpack(mz_zip_archive& zip, const std::string& root, const fs::path& target, const std::string& mod_name) {
        std::error_code ec;
        mz_uint count = mz_zip_reader_get_num_files(&zip);
        for (mz_uint i = 0; i < count; i++) {
            if (show_boot_screen) {
                tooie::boot_screen::show("Installing Mods", mod_name + "  " + std::to_string(i * 100 / count) + "%");
            }
            char name[1024];
            if (mz_zip_reader_get_filename(&zip, i, name, sizeof(name)) == 0 || mz_zip_reader_is_file_a_directory(&zip, i)) {
                continue;
            }
            std::string entry = name;
            if (entry.compare(0, root.size(), root) != 0) {
                continue;
            }
            fs::path relative = fs::path(std::u8string((const char8_t*)entry.c_str() + root.size())).lexically_normal();
            fs::path out = target / relative;
            if (!safe_relative(relative) || !inside(target, out)) {
                fprintf(stderr, "[mods] skipping unsafe zip entry %s\n", name);
                continue;
            }
            fs::create_directories(out.parent_path(), ec);
            if (!mz_zip_reader_extract_to_file(&zip, i, (const char*)out.u8string().c_str(), 0)) {
                fprintf(stderr, "[mods] failed to unpack %s\n", name);
                return false;
            }
        }
        return true;
    }

    void unpack_zip(const fs::path& zip_path, bool new_only) {
        std::error_code ec;
        fs::path target = zip_path.parent_path() / zip_path.stem();
        if (new_only && fs::exists(target, ec)) {
            return;
        }
        const std::string stamp = zip_stamp(zip_path);
        const bool ours = fs::exists(target / marker_name, ec);
        if (ours && read_text(target / marker_name) == stamp) {
            return;
        }
        // A folder of that name we didn't unpack (no marker) is the player's own, unpacked by hand and maybe
        // edited: leave it and the zip alone rather than replace it.
        if (!ours && fs::exists(target, ec)) {
            fprintf(stderr, "[mods] %s not unpacked: the folder %s is already there and was not unpacked from it; "
                "remove or rename that folder to unpack the zip\n",
                (const char*)zip_path.filename().u8string().c_str(), (const char*)target.filename().u8string().c_str());
            return;
        }

        mz_zip_archive zip{};
        if (!mz_zip_reader_init_file(&zip, (const char*)zip_path.u8string().c_str(), 0)) {
            fprintf(stderr, "[mods] %s is not a readable zip\n", (const char*)zip_path.filename().u8string().c_str());
            return;
        }
        std::string root;
        if (!find_pack_root(zip, root)) {
            fprintf(stderr, "[mods] %s has no rt64.json, assets.json or translations.json, so it is not a texture pack, asset mod or language mod; skipped\n",
                (const char*)zip_path.filename().u8string().c_str());
            mz_zip_reader_end(&zip);
            return;
        }

        printf("[mods] unpacking %s (once; this can take a while)\n", (const char*)zip_path.filename().u8string().c_str());
        fflush(stdout);
        fs::path temp = target;
        temp += ".unpacking";
        fs::remove_all(temp, ec);
        bool ok = unpack(zip, root, temp, (const char*)zip_path.stem().u8string().c_str());
        mz_zip_reader_end(&zip);
        if (!ok) {
            fs::remove_all(temp, ec);
            return;
        }

        if (!fs::exists(temp / "mod.json", ec)) {
            std::string id = json_escape((const char*)zip_path.stem().u8string().c_str());
            std::ofstream manifest(temp / "mod.json", std::ios::binary);
            manifest << "{\n"
                "    \"id\": \"" << id << "\",\n"
                "    \"display_name\": \"" << id << "\",\n"
                "    \"version\": \"1.0.0\",\n"
                "    \"authors\": [\"Unknown\"],\n"
                "    \"game_id\": \"bt\",\n"
                "    \"minimum_recomp_version\": \"0.0.1\"\n"
                "}\n";
        }
        std::ofstream(temp / marker_name, std::ios::binary) << stamp;

        // Only a folder with our marker is replaced (checked above; checked again in case it changed meanwhile).
        if (fs::exists(target, ec)) {
            if (!fs::exists(target / marker_name, ec)) {
                fprintf(stderr, "[mods] %s appeared while unpacking and was not unpacked by us; left as it is\n",
                    (const char*)target.filename().u8string().c_str());
                fs::remove_all(temp, ec);
                return;
            }
            fs::remove_all(target, ec);
        }
        fs::rename(temp, target, ec);
        if (ec) {
            fprintf(stderr, "[mods] could not move the unpacked pack into place: %s\n", ec.message().c_str());
            return;
        }
        printf("[mods] unpacked %s into %s\n", (const char*)zip_path.filename().u8string().c_str(),
            (const char*)target.filename().u8string().c_str());
    }
}

void tooie::unpack_mod_zips(bool new_only, bool at_boot) {
    std::error_code ec;
    fs::path mods = recomp::mods::get_mods_directory();
    if (!fs::is_directory(mods, ec)) {
        return;
    }
    show_boot_screen = at_boot;
    for (const auto& entry : fs::directory_iterator(mods, fs::directory_options::skip_permission_denied, ec)) {
        if (entry.is_regular_file(ec) && entry.path().extension() == ".zip") {
            unpack_zip(entry.path(), new_only);
        }
    }
    show_boot_screen = false;
    boot_screen::close();
}
