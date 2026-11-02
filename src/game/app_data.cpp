#include <filesystem>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <system_error>

#ifdef _WIN32
#include <Windows.h>
#elif defined(__linux__)
#include <unistd.h>
#include <limits.h>
#endif

#include "tooie_game.h"
#include "util/file.h"

namespace fs = std::filesystem;

namespace {
    fs::path get_exe_dir() {
#ifdef _WIN32
        wchar_t buf[MAX_PATH * 4];
        DWORD len = GetModuleFileNameW(nullptr, buf, sizeof(buf) / sizeof(buf[0]));
        if (len == 0 || len >= sizeof(buf) / sizeof(buf[0])) {
            return {};
        }
        return fs::path(buf).parent_path();
#elif defined(__linux__)
        char buf[PATH_MAX];
        ssize_t len = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
        if (len <= 0) {
            return {};
        }
        buf[len] = '\0';
        return fs::path(buf).parent_path();
#else
        return {};
#endif
    }

    bool dir_writable(const fs::path& dir) {
        std::error_code ec;
        fs::create_directories(dir, ec);
        fs::path probe = dir / ".write_test";
        bool ok = false;
        {
            std::ofstream f(probe, std::ios::binary);
            ok = f.good();
        }
        fs::remove(probe, ec);
        return ok;
    }
}

bool tooie::dev_file_present() {
    static const bool present = [] {
        std::error_code ec;
        if (fs::exists("dev.txt", ec)) {
            return true;
        }
        const fs::path exe_dir = get_exe_dir();
        return !exe_dir.empty() && fs::exists(exe_dir / "dev.txt", ec);
    }();
    return present;
}

bool tooie::set_dev_file(bool create, std::string* path) {
    std::error_code ec;
    const fs::path exe_dir = get_exe_dir();
    fs::path file = exe_dir.empty() ? fs::path("dev.txt") : exe_dir / "dev.txt";
    if (!create) {
        // Both places dev_file_present looks in.
        for (const fs::path& p : { fs::path("dev.txt"), file }) {
            if (fs::exists(p, ec)) {
                file = p;
                break;
            }
        }
        *path = file.string();
        if (!fs::exists(file, ec)) {
            return true; // nothing to remove
        }
        return fs::remove(file, ec);
    }
    *path = file.string();
    if (fs::exists(file, ec)) {
        return true;
    }
    std::ofstream f(file, std::ios::binary);
    return f.good();
}

fs::path tooie::resolve_app_folder() {
    // The runtime's own choice: portable.txt in the working directory, else the per-user folder.
    const fs::path legacy = recompui::file::get_app_folder_path();

    std::error_code ec;
#if defined(__APPLE__) || defined(RECOMP_FLATPAK)
    return legacy;
#else
    // An explicit override keeps the old behaviour.
    if (std::getenv("APP_FOLDER_PATH") != nullptr || fs::exists("portable.txt", ec)) {
        return legacy;
    }

    const fs::path exe_dir = get_exe_dir();
    if (exe_dir.empty() || !dir_writable(exe_dir)) {
        return legacy;
    }
    if (fs::exists(exe_dir / "portable.txt", ec)) {
        return exe_dir;
    }

    // Portable by default: settings and saves live next to the exe. Bring over the old per-user folder once.
    const fs::path marker = exe_dir / "migrated_from.txt";
    std::error_code eq_ec;
    if (!legacy.empty() && fs::exists(legacy, ec) && !fs::exists(marker, ec) && !fs::equivalent(legacy, exe_dir, eq_ec)) {
        fs::copy(legacy, exe_dir, fs::copy_options::recursive | fs::copy_options::skip_existing, ec);
        if (ec) {
            fprintf(stderr, "Could not copy %s to %s (%s); using the old folder.\n",
                legacy.string().c_str(), exe_dir.string().c_str(), ec.message().c_str());
            return legacy;
        }
        std::ofstream out(marker);
        out << "Copied from " << legacy.string() << " on first start of the portable build.\n"
            << "The old folder was left in place and can be deleted once you have checked your saves.\n";
    }
    return exe_dir;
#endif
}
