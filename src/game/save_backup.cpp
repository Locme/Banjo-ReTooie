#include <atomic>
#include <iterator>
#include <chrono>
#include <cstdint>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <thread>
#include <vector>
#include <algorithm>
#include <string>

#include "ultramodern/ultramodern.hpp"
#include "librecomp/game.hpp"
#include "recompui/config.h"

#include "tooie_game.h"

namespace fs = std::filesystem;

namespace {
    constexpr const char* backups_folder = "save_backups";
    constexpr auto poll_interval = std::chrono::seconds(120);

    std::atomic_bool stop_requested{false};
    std::thread backup_thread;

    bool read_file(const fs::path& path, std::vector<char>& out) {
        std::ifstream f(path, std::ios::binary);
        if (!f.good()) {
            return false;
        }
        out.assign(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>());
        return true;
    }

    // FNV-1a, 64 bit. Only used to notice that the save changed.
    uint64_t hash_bytes(const std::vector<char>& data) {
        uint64_t h = 1469598103934665603ull;
        for (char c : data) {
            h ^= static_cast<unsigned char>(c);
            h *= 1099511628211ull;
        }
        return h;
    }

    bool backups_enabled() {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::save_backups_option));
        } catch (...) {
            return true;
        }
    }

    size_t backups_to_keep() {
        try {
            double v = std::get<double>(recompui::config::get_general_config().get_option_value(tooie::save_backups_keep_option));
            return static_cast<size_t>(std::clamp(v, 1.0, 100.0));
        } catch (...) {
            return 10;
        }
    }

    std::string timestamp() {
        std::time_t t = std::time(nullptr);
        std::tm tm_buf{};
#ifdef _WIN32
        localtime_s(&tm_buf, &t);
#else
        localtime_r(&t, &tm_buf);
#endif
        char buf[32];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d_%H-%M-%S", &tm_buf);
        return buf;
    }

    void prune(const fs::path& root, size_t keep) {
        std::error_code ec;
        std::vector<fs::path> dirs;
        for (const auto& entry : fs::directory_iterator(root, ec)) {
            if (entry.is_directory(ec)) {
                dirs.push_back(entry.path());
            }
        }
        // Names are date-times, so sorting by name sorts by age.
        std::sort(dirs.begin(), dirs.end());
        while (dirs.size() > keep) {
            fs::remove_all(dirs.front(), ec);
            dirs.erase(dirs.begin());
        }
    }

    void backup_loop() {
        fs::path last_path;
        uint64_t last_hash = 0;
        bool have_hash = false;
        auto next_check = std::chrono::steady_clock::now();

        while (!stop_requested) {
            fs::path save_path = ultramodern::get_save_file_path();
            auto now = std::chrono::steady_clock::now();
            // The save path is empty until a game starts, so check as soon as it appears, then every 120 s.
            bool path_changed = !save_path.empty() && save_path != last_path;

            if (!save_path.empty() && (path_changed || now >= next_check)) {
                next_check = now + poll_interval;
                std::vector<char> data;
                if (backups_enabled() && read_file(save_path, data) && !data.empty()) {
                    uint64_t h = hash_bytes(data);
                    // The first look at a save only records its hash and backs it up if it is new to us.
                    if (!have_hash || path_changed || h != last_hash) {
                        std::error_code ec;
                        fs::path root = recomp::get_config_path() / backups_folder;
                        fs::path dir = root / timestamp();
                        fs::create_directories(dir, ec);
                        fs::copy_file(save_path, dir / save_path.filename(), fs::copy_options::overwrite_existing, ec);
                        if (!ec) {
                            prune(root, backups_to_keep());
                        }
                        last_hash = h;
                        have_hash = true;
                    }
                }
                last_path = save_path;
            }

            for (int i = 0; i < 10 && !stop_requested; i++) {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }
}

void tooie::start_save_backups() {
    if (backup_thread.joinable()) {
        return;
    }
    backup_thread = std::thread(backup_loop);
    // The process may exit without joining; the thread only reads files, so detach and let it die with the process.
    backup_thread.detach();
}
