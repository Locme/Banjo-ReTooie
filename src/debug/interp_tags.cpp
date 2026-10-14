// Manual interpolation tags (see include/tooie_interp_tags.h).
//
// The Pick Model key (bound in the Debug section of the Controls tab) steps a green highlight through the models on screen, nearest the
// middle of the picture first; a toast names the picked model. The Tag Model
// key steps the picked model's blend: default, snap, vertex blend,
// untagged; the tags show in the "custom" blend mode. The Save Tags key
// writes them to interp_tags.txt next to the save files, one line per model:
//   <model> <mode>   # map <map> <where it was picked>
// The file is read at start over the built-in defaults below, so a tag made
// in the game wins. L sends the file; its lines go into `defaults` to ship.
//
// Headless hook: TOOIE_TAG_KEYS="<ms>:pick;<ms>:tag;<ms>:save;<ms>:unsave;..." presses the keys at
// those times after start.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include "librecomp/game.hpp"

#include "tooie_hotkeys.h"
#include "tooie_interp_tags.h"
#include "tooie_toast.h"

namespace {
    using namespace std::chrono_literals;

    struct Default {
        uint32_t model;
        int mode;
    };
    // Tags that ship with the port (from L's interp_tags.txt).
    const Default defaults[] = {
        {0, 0},
    };

    std::once_flag started;
    std::mutex lock;
    std::unordered_map<uint32_t, int> tags;
    // What interp_tags.txt holds (the tags as last read or written).
    std::unordered_map<uint32_t, int> saved;
    std::unordered_map<uint32_t, std::string> notes;
    std::atomic<bool> have_tags{false};
    std::atomic<bool> pick_pending{false};
    std::atomic<bool> tag_pending{false};
    std::atomic<bool> save_pending{false};
    std::atomic<bool> unsave_pending{false};
    std::atomic<uint32_t> picked_model{0};
    std::string picked_note;

    std::filesystem::path file_path() {
        return recomp::get_config_path() / "interp_tags.txt";
    }

    int parse_mode(const std::string& word) {
        for (int m = 0; m < tooie::interp_tags::mode_count; m++) {
            if (word == tooie::interp_tags::mode_name(m)) {
                return m;
            }
        }
        return -1;
    }

    void load() {
        std::lock_guard<std::mutex> guard(lock);
        tags.clear();
        for (const Default& d : defaults) {
            if (d.model != 0 && d.mode != tooie::interp_tags::mode_default) {
                tags[d.model] = d.mode;
            }
        }
        std::ifstream in(file_path());
        std::string line;
        size_t read = 0;
        while (std::getline(in, line)) {
            char mode_word[32] = {};
            unsigned model = 0;
            if (std::sscanf(line.c_str(), "%x %31s", &model, mode_word) != 2 || model == 0) {
                continue;
            }
            int mode = parse_mode(mode_word);
            if (mode < 0) {
                continue;
            }
            size_t hash = line.find('#');
            if (hash != std::string::npos) {
                notes[model] = line.substr(hash + 1);
            }
            if (mode == tooie::interp_tags::mode_default) {
                tags.erase(model);
            } else {
                tags[model] = mode;
            }
            read++;
        }
        saved = tags;
        have_tags = !tags.empty();
        if (read != 0) {
            std::printf("[interp-tags] %zu tags read from interp_tags.txt\n", read);
        }
    }

    // Writes the tags, with the note of any model that had one.
    void save_locked() {
        std::error_code ec;
        std::filesystem::create_directories(file_path().parent_path(), ec);
        std::ofstream out(file_path());
        out << "# Manual interpolation tags: <model> <mode>, modes default, snap, vertex, untagged.\n";
        std::vector<uint32_t> models;
        for (const auto& [model, note] : notes) {
            models.push_back(model);
        }
        for (const auto& [model, mode] : tags) {
            if (notes.find(model) == notes.end()) {
                models.push_back(model);
            }
        }
        for (uint32_t model : models) {
            auto it = tags.find(model);
            int mode = it == tags.end() ? tooie::interp_tags::mode_default : it->second;
            char line[64];
            std::snprintf(line, sizeof(line), "%08X %-8s", model, tooie::interp_tags::mode_name(mode));
            out << line;
            auto note = notes.find(model);
            if (note != notes.end()) {
                out << " #" << note->second;
            }
            out << "\n";
        }
    }

    void worker() {
        // The headless key script.
        struct Press {
            int64_t at;
            std::string key;
        };
        std::vector<Press> script;
        if (const char* v = std::getenv("TOOIE_TAG_KEYS"); v != nullptr) {
            std::string s = v;
            size_t pos = 0;
            while (pos < s.size()) {
                size_t end = s.find(';', pos);
                std::string item = s.substr(pos, end == std::string::npos ? std::string::npos : end - pos);
                size_t colon = item.find(':');
                if (colon != std::string::npos) {
                    script.push_back({std::atoll(item.substr(0, colon).c_str()), item.substr(colon + 1)});
                }
                pos = end == std::string::npos ? s.size() : end + 1;
            }
        }
        const auto start = std::chrono::steady_clock::now();
        bool pick_was_down = false;
        bool tag_was_down = false;
        bool save_was_down = false;
        bool unsave_was_down = false;
        for (;;) {
            std::this_thread::sleep_for(10ms);
            bool pick_down = tooie::hotkeys::down(recompinput::GameInput::PICK_MODEL);
            bool tag_down = tooie::hotkeys::down(recompinput::GameInput::TAG_MODEL);
            bool save_down = tooie::hotkeys::down(recompinput::GameInput::SAVE_TAGS);
            bool unsave_down = tooie::hotkeys::down(recompinput::GameInput::UNSAVE_TAG);
            int64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
            while (!script.empty() && script.front().at <= ms) {
                const std::string& key = script.front().key;
                (key == "pick" ? pick_pending : key == "save" ? save_pending : key == "unsave" ? unsave_pending : tag_pending) = true;
                script.erase(script.begin());
            }
            if (pick_down && !pick_was_down) {
                pick_pending = true;
            }
            if (tag_down && !tag_was_down) {
                tag_pending = true;
            }
            if (save_down && !save_was_down) {
                save_pending = true;
            }
            if (unsave_down && !unsave_was_down) {
                unsave_pending = true;
            }
            pick_was_down = pick_down;
            tag_was_down = tag_down;
            save_was_down = save_down;
            unsave_was_down = unsave_down;
        }
    }
}

const char* tooie::interp_tags::mode_name(int mode) {
    switch (mode) {
        case mode_snap: return "snap";
        case mode_vertex: return "vertex";
        case mode_untagged: return "untagged";
        default: return "default";
    }
}

void tooie::interp_tags::start() {
    std::call_once(started, [] {
        load();
        std::thread(worker).detach();
    });
}

int tooie::interp_tags::mode_of(uint32_t model) {
    if (!have_tags.load(std::memory_order_relaxed)) {
        return mode_default;
    }
    std::lock_guard<std::mutex> guard(lock);
    auto it = tags.find(model);
    return it == tags.end() ? mode_default : it->second;
}

bool tooie::interp_tags::any() {
    return have_tags.load(std::memory_order_relaxed);
}

bool tooie::interp_tags::take_pick() {
    return pick_pending.exchange(false);
}

bool tooie::interp_tags::take_tag() {
    return tag_pending.exchange(false);
}

bool tooie::interp_tags::take_save() {
    return save_pending.exchange(false);
}

bool tooie::interp_tags::take_unsave() {
    return unsave_pending.exchange(false);
}

size_t tooie::interp_tags::save() {
    std::lock_guard<std::mutex> guard(lock);
    save_locked();
    saved = tags;
    std::printf("[interp-tags] %zu tags saved to interp_tags.txt\n", tags.size());
    return tags.size();
}

void tooie::interp_tags::unsave_picked() {
    std::lock_guard<std::mutex> guard(lock);
    uint32_t model = picked_model.load();
    tags.erase(model);
    notes.erase(model);
    have_tags = !tags.empty();
    // The file keeps the other saved tags as they are.
    std::unordered_map<uint32_t, int> live = std::move(tags);
    tags = saved;
    tags.erase(model);
    save_locked();
    saved = tags;
    tags = std::move(live);
    std::printf("[interp-tags] model %08X: tag removed and unsaved\n", model);
}

std::string tooie::interp_tags::describe(uint32_t model) {
    std::lock_guard<std::mutex> guard(lock);
    auto t = tags.find(model);
    auto s = saved.find(model);
    int live = t == tags.end() ? mode_default : t->second;
    int on_disk = s == saved.end() ? mode_default : s->second;
    std::string text = mode_name(live);
    if (live == on_disk) {
        text += live == mode_default ? "" : ", saved";
    } else if (on_disk == mode_default) {
        text += ", not saved yet";
    } else {
        text += std::string(" (saved as ") + mode_name(on_disk) + ")";
    }
    return text;
}

uint32_t tooie::interp_tags::picked() {
    return picked_model.load(std::memory_order_relaxed);
}

void tooie::interp_tags::set_picked(uint32_t model, const std::string& note) {
    std::lock_guard<std::mutex> guard(lock);
    picked_model = model;
    picked_note = note;
}

int tooie::interp_tags::step_picked() {
    std::lock_guard<std::mutex> guard(lock);
    uint32_t model = picked_model.load();
    if (model == 0) {
        return mode_default;
    }
    auto it = tags.find(model);
    int mode = (it == tags.end() ? mode_default : it->second) + 1;
    if (mode >= mode_count) {
        mode = mode_default;
    }
    if (mode == mode_default) {
        tags.erase(model);
    } else {
        tags[model] = mode;
    }
    if (notes.find(model) == notes.end() && !picked_note.empty()) {
        notes[model] = picked_note;
    }
    have_tags = !tags.empty();
    std::printf("[interp-tags] model %08X: %s\n", model, mode_name(mode));
    return mode;
}
