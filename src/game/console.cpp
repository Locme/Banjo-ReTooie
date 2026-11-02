// Developer console, ported from the Mario Party 3 port's console (src/game/console.cpp there).
//
// Two ways in:
//   - In the game, the ` key (the one left of 1, whatever the keyboard layout) opens a prompt over the bottom of the
//     window. It is a RecompFrontend (recompui) context laid out in percent of the window, so it fits any aspect
//     ratio, and it is drawn by the UI layer apart from the game's frames. Enter runs the line.
//   - From a script: each line written to the program's stdin is a command (`BanjoReTooie < test.txt`, or a pipe), as
//     is `--exec <file>` on the command line and TOOIE_CONSOLE="cmd; cmd" in the environment. No window focus is
//     needed.
//
// Every result is printed to stdout (and so to the session log) one line at a time as "[command] text", and a failure
// as "[command] ERR text", so a script can read it; `quit` ends the program with exit code 1 when any command failed
// (or with the code given). console_state.txt in the app folder is rewritten about once a second for tools that
// cannot read stdout.
//
// Commands run in order from one queue. Most need the game running and run on the game thread once per game update
// (tooie_warp_tick, the start of func_800A7D84); before the game starts, the ones that don't (start, settings, quit and
// the like) run on a small thread of their own. `wait` holds the queue until it is done.
//
// The warps go through the Warp tab's own code (src/game/level_warp.cpp) and src/debug/warp.cpp, and the settings
// through the same config calls as the settings menu, so nothing here is a second copy of a feature.

#include "tooie_console.h"
#include "tooie_cheats.h"
#include "tooie_debug.h"
#include "tooie_enemy_spawner.h"
#include "tooie_player_cheats.h"
#include "tooie_progress_cheats.h"
#include "tooie_rdram.h"
#include "tooie_game.h"
#include "tooie_game_frame_rate.h"
#include "tooie_level_warp.h"
#include "tooie_save_state.h"
#include "tooie_screenshot.h"
#include "tooie_achievements.h"
#include "tooie_gfx_budget.h"
#include "tooie_photo_mode.h"
#include "tooie_texture_sweep.h"
#include "tooie_vram_log.h"
#include "librecomp/mods.hpp"
#include "recomp.h"
#include "recompui/recompui.h"
#include "recompui/config.h"
#include "librecomp/config.hpp"
#include "librecomp/game.hpp"
#include "librecomp/addresses.hpp"
#include "ultramodern/ultramodern.hpp"
#include "util/file.h"
#include "elements/ui_label.h"
#include "elements/ui_text_input.h"

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include <algorithm>
#include <atomic>
#include <cctype>
#include <cstdarg>
#include <ctime>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <filesystem>
#include <fstream>
#include <functional>
#include <map>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <variant>
#include <vector>

extern SDL_Window* window; // src/main/main.cpp

namespace {
using recomp::config::Config;
using recomp::config::ConfigOption;
using recomp::config::ConfigOptionType;
using recomp::config::ConfigValueVariant;
using Clock = std::chrono::steady_clock;

struct MapName {
    uint16_t id;
    const char* name;
};

// Map id -> name (shared with the other map_names.inc users).
constexpr MapName kMapNames[] = {
#include "map_names.inc"
};

constexpr uint32_t kRamStart = 0x80000000;
constexpr uint32_t kRamEnd = 0x80000000u + (uint32_t)std::min<size_t>(recomp::mem_size, 0x20000000);
constexpr uint32_t kFindEnd = 0x81000000;   // find searches the first 16 MB unless told otherwise

constexpr int kShownLines = 14;
constexpr size_t kKeptLines = 400;
constexpr size_t kKeptHistory = 64;

// ---------------------------------------------------------------------------------------------------------------
// Text helpers

std::string lower(std::string s) {
    for (char& c : s) c = (char)std::tolower((unsigned char)c);
    return s;
}

// Letters and digits only, lower case: "Hand, Line and Sinker" and "hand line & sinker" compare equal.
std::string squash(const std::string& s) {
    std::string out;
    for (char c : s) {
        if (std::isalnum((unsigned char)c)) out += (char)std::tolower((unsigned char)c);
    }
    return out;
}

std::string trim(const std::string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == std::string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

std::vector<std::string> split(const std::string& line) {
    std::vector<std::string> words;
    std::istringstream in{ line };
    std::string w;
    while (in >> w) words.push_back(w);
    return words;
}

std::string join(const std::vector<std::string>& words, size_t from, size_t to = std::string::npos) {
    std::string out;
    for (size_t i = from; i < words.size() && i < to; i++) {
        if (!out.empty()) out += ' ';
        out += words[i];
    }
    return out;
}

// Commands on one line are separated by ';', except in alias, bind, repeat, if and break, whose commands run later.
std::vector<std::string> split_commands(const std::string& line) {
    std::vector<std::string> out;
    {
        std::string t = trim(line);
        std::string first = t.substr(0, t.find_first_of(" \t"));
        for (char& ch : first) ch = (char)std::tolower((unsigned char)ch);
        if (first == "alias" || first == "bind" || first == "repeat" || first == "if" || first == "break") {
            if (!t.empty()) out.push_back(t);
            return out;
        }
    }
    std::string cur;
    for (char c : line) {
        if (c == ';') { out.push_back(trim(cur)); cur.clear(); }
        else cur += c;
    }
    out.push_back(trim(cur));
    out.erase(std::remove_if(out.begin(), out.end(), [](const std::string& s) { return s.empty(); }), out.end());
    return out;
}

bool parse_int(const std::string& s, int* out) {
    if (s.empty() || s.size() > 9) return false;
    size_t i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    if (i == s.size()) return false;
    for (; i < s.size(); i++) {
        if (!std::isdigit((unsigned char)s[i])) return false;
    }
    *out = std::atoi(s.c_str());
    return true;
}

// Decimal, or hexadecimal with 0x in front.
bool parse_u32(const std::string& s, uint32_t* out) {
    if (s.empty()) return false;
    char* end = nullptr;
    unsigned long long v;
    if (s.size() > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) v = std::strtoull(s.c_str() + 2, &end, 16);
    else if (s[0] == '-') {
        long long sv = std::strtoll(s.c_str(), &end, 10);
        v = (unsigned long long)(uint32_t)(int32_t)sv;
    }
    else v = std::strtoull(s.c_str(), &end, 10);
    if (end == nullptr || *end != '\0' || v > 0xFFFFFFFFull) return false;
    *out = (uint32_t)v;
    return true;
}

// An address is always hexadecimal (with or without 0x): 800CD058 or 0x800CD058.
bool parse_addr(const std::string& s, uint32_t* out) {
    std::string h = (s.size() > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) ? s.substr(2) : s;
    if (h.empty() || h.size() > 8) return false;
    for (char c : h) {
        if (!std::isxdigit((unsigned char)c)) return false;
    }
    uint32_t v = (uint32_t)std::strtoul(h.c_str(), nullptr, 16);
    if (v < kRamStart) v += kRamStart; // a physical address: KSEG0
    *out = v;
    return v >= kRamStart && v < kRamEnd;
}

bool parse_double(const std::string& s, double* out) {
    if (s.empty()) return false;
    char* end = nullptr;
    double v = std::strtod(s.c_str(), &end);
    if (end == s.c_str() || *end != '\0' || !std::isfinite(v)) return false;
    *out = v;
    return true;
}

bool parse_bool(const std::string& s, bool* out) {
    std::string v = lower(s);
    if (v == "1" || v == "on" || v == "true" || v == "yes" || v == "enable" || v == "enabled") { *out = true; return true; }
    if (v == "0" || v == "off" || v == "false" || v == "no" || v == "disable" || v == "disabled") { *out = false; return true; }
    return false;
}

std::string format(const char* fmt, ...) {
    char buf[1024];
    va_list args;
    va_start(args, fmt);
    std::vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    return buf;
}

std::string format_number(double v, int precision) {
    return format("%.*f", std::max(precision, 0), v);
}

// ---------------------------------------------------------------------------------------------------------------
// RAM, on the game thread

uint32_t read_ram(uint8_t* rdram, uint32_t addr, int size) {
    gpr a = (gpr)(int32_t)addr;
    if (size == 1) return MEM_BU(0, a);
    if (size == 2) return MEM_HU(0, a);
    return (uint32_t)MEM_W(0, a);
}

void write_ram(uint8_t* rdram, uint32_t addr, uint32_t value, int size) {
    gpr a = (gpr)(int32_t)addr;
    if (size == 1) MEM_B(0, a) = (int8_t)value;
    else if (size == 2) MEM_H(0, a) = (int16_t)value;
    else MEM_W(0, a) = (int32_t)value;
}

// A size word: 8, 16, 32 (bits) or b, h, w; 0 when the word is not one.
int parse_size(const std::string& s) {
    std::string v = lower(s);
    if (v == "8" || v == "b" || v == "byte" || v == "u8" || v == "s8") return 1;
    if (v == "16" || v == "h" || v == "half" || v == "u16" || v == "s16") return 2;
    if (v == "32" || v == "w" || v == "word" || v == "u32" || v == "s32") return 4;
    return 0;
}

// The size a written value implies: hex digits typed (0x12 1 byte, 0x1234 2, more 4), or the value's range.
int size_of_value(const std::string& text, uint32_t v) {
    if (text.size() > 2 && text[0] == '0' && (text[1] == 'x' || text[1] == 'X')) {
        size_t digits = text.size() - 2;
        return digits <= 2 ? 1 : digits <= 4 ? 2 : 4;
    }
    if (!text.empty() && text[0] == '-') return 4;
    return v <= 0xFF ? 1 : v <= 0xFFFF ? 2 : 4;
}

std::string hex(uint32_t v, int size) {
    return format("0x%0*X", size * 2, v);
}

// ---------------------------------------------------------------------------------------------------------------
// State

std::recursive_mutex g_mutex; // the output, the queue, and the console's lists below
std::deque<std::string> g_lines;
FILE* g_tee = nullptr; // tee <file>: the output copied to a file (under g_mutex)
std::vector<std::string> g_history;
size_t g_history_pos;
int g_scroll;

struct Entry {
    std::string text;
    int depth = 0; // alias and exec nesting
};
std::deque<Entry> g_queue;
std::string g_current = "console"; // the command running, for the "[command]" prefix

std::atomic<bool> g_had_error{ false };
std::atomic<int> g_exit_code{ -1 };
std::atomic<uint64_t> g_frames{ 0 };      // frames counted by console_frame
uint8_t* g_rdram = nullptr;               // set on the game thread

// What holds the queue: a wait, or a capture or screenshot being saved.
uint64_t g_wait_frames_until;             // 0: none
Clock::time_point g_wait_until;           // epoch: none
std::atomic<bool> g_busy{ false };
std::function<bool()> g_wait_cond;        // wait map / wait until: true when what it waits for has happened
Clock::time_point g_wait_cond_deadline;

// press / release (apply_input).
std::mutex g_input_mutex;
uint16_t g_press_buttons;
int8_t g_press_x, g_press_y;
bool g_press_stick;
int64_t g_press_frames;                   // -1: until release; 0: nothing held

// watch, freeze, binds, aliases.
struct Watch { uint32_t addr; int size; bool is_float; std::string name; };
std::vector<Watch> g_watches;
struct Freeze { uint32_t addr; uint32_t value; int size; };
std::vector<Freeze> g_freezes;
std::map<std::string, std::string> g_aliases;     // name -> commands
std::map<SDL_Scancode, std::string> g_binds;      // key -> commands

// FPS, measured over the last second of frames.
std::deque<Clock::time_point> g_frame_times;

// The prompt.
recompui::ContextId g_context = recompui::ContextId::null();
recompui::Label* g_shown[kShownLines];
recompui::TextInput* g_input;
bool g_open;

// The watch panel (top right).
recompui::ContextId g_watch_context = recompui::ContextId::null();
recompui::Element* g_watch_box;
std::vector<recompui::Label*> g_watch_labels;
bool g_watch_shown;

// ---------------------------------------------------------------------------------------------------------------
// Output

void with_context(recompui::ContextId ctx, const std::function<void()>& f) {
    if (ctx == recompui::ContextId::null()) return;
    recompui::ContextId prev = recompui::try_close_current_context();
    ctx.open();
    f();
    ctx.close();
    if (prev != recompui::ContextId::null()) prev.open();
}

void refresh_output() {
    std::lock_guard lock{ g_mutex };
    if (g_context == recompui::ContextId::null()) return;
    with_context(g_context, [] {
        int newest = (int)g_lines.size() - 1 - g_scroll;
        for (int i = 0; i < kShownLines; i++) {
            int at = newest - (kShownLines - 1 - i);
            g_shown[i]->set_text(at >= 0 && at < (int)g_lines.size() ? g_lines[at] : std::string());
        }
    });
}

// One result line per line of `text`, as "[command] line" (stdout, the session log and the prompt).
void out_lines(const std::string& text, bool error) {
    std::string prefix;
    {
        std::lock_guard lock{ g_mutex };
        prefix = "[" + g_current + "] " + (error ? "ERR " : "");
    }
    std::vector<std::string> lines;
    std::string cur;
    for (char c : text) {
        if (c == '\n') { lines.push_back(cur); cur.clear(); }
        else cur += c;
    }
    lines.push_back(cur);
    {
        std::lock_guard lock{ g_mutex };
        for (const std::string& l : lines) {
            std::string line = prefix + l;
            std::fprintf(stdout, "%s\n", line.c_str());
            if (g_tee != nullptr) {
                std::fprintf(g_tee, "%s\n", line.c_str());
                std::fflush(g_tee);
            }
            g_lines.push_back(line);
        }
        std::fflush(stdout);
        while (g_lines.size() > kKeptLines) g_lines.pop_front();
        g_scroll = 0;
    }
    refresh_output();
}

void print(const std::string& text) { out_lines(text, false); }

void error(const std::string& text) {
    g_had_error = true;
    out_lines(text, true);
}

// A line from the console itself (READY, IDLE), for scripts and AI testers that wait on stdout.
void announce(const std::string& text) {
    {
        std::lock_guard lock{ g_mutex };
        g_current = "console";
    }
    print(text);
}

// console_state.txt in the game folder: the console's state for tools that can't read stdout, rewritten about once a
// second.
std::atomic<bool> g_ran_any{ false };

void write_state_file(uint8_t* rdram, int32_t map) {
    size_t queued;
    std::string last;
    {
        std::lock_guard lock{ g_mutex };
        queued = g_queue.size();
        last = g_lines.empty() ? std::string() : g_lines.back();
    }
    std::filesystem::path path = recompui::file::get_app_folder_path() / "console_state.txt";
    std::filesystem::path tmp = path;
    tmp += ".tmp";
    {
        std::ofstream out{ tmp };
        if (!out.good()) return;
        out << "ready 1\n";
        out << "game_started " << (ultramodern::is_game_started() ? 1 : 0) << "\n";
        out << "map " << (rdram != nullptr ? map : -1) << "\n";
        out << "frames " << g_frames.load() << "\n";
        out << "queued " << queued << "\n";
        out << "busy " << (g_busy.load() || queued > 0 ? 1 : 0) << "\n";
        out << "errors " << (g_had_error.load() ? 1 : 0) << "\n";
        out << "last " << last << "\n";
    }
    std::error_code ec;
    std::filesystem::rename(tmp, path, ec);
}

// ---------------------------------------------------------------------------------------------------------------
// The queue

void enqueue_line(const std::string& line, int depth = 0, bool front = false) {
    std::vector<std::string> cmds = split_commands(line);
    std::lock_guard lock{ g_mutex };
    if (front) {
        for (auto it = cmds.rbegin(); it != cmds.rend(); ++it) g_queue.push_front({ *it, depth });
    } else {
        for (const std::string& c : cmds) g_queue.push_back({ c, depth });
    }
}

bool holding() {
    if (g_busy.load()) return true;
    if (g_wait_frames_until != 0) {
        if (g_frames.load() < g_wait_frames_until) return true;
        g_wait_frames_until = 0;
    }
    if (g_wait_until != Clock::time_point{}) {
        if (Clock::now() < g_wait_until) return true;
        g_wait_until = Clock::time_point{};
    }
    if (g_wait_cond) {
        if (g_wait_cond()) {
            g_wait_cond = nullptr;
            return false;
        }
        if (Clock::now() < g_wait_cond_deadline) return true;
        g_wait_cond = nullptr;
        {
            std::lock_guard lock{ g_mutex };
            g_current = "wait";
        }
        error("gave up waiting (timed out)");
    }
    return false;
}

// ---------------------------------------------------------------------------------------------------------------
// Settings: every option of the port's settings tabs, plus the Debug tab's own values (kept in debug.json).

const char* const kTabs[] = { "general", "graphics", "sound", "qol", "cheats", "wip" };

Config* find_config(const std::string& id) {
    try {
        return &recompui::config::get_config(id);
    } catch (...) {
        return nullptr; // a tab this build does not have
    }
}

struct DebugSetting {
    const char* id;
    const char* name;
    ConfigOptionType type;
    double min, max, step, def;
    std::function<ConfigValueVariant()> get;
    std::function<void(const ConfigValueVariant&)> set;
};

// The console's own values that are not in a settings tab. None yet: add { id, name, type, min, max, step, default,
// get, set } here and they show in `settings` under "debug".
const std::vector<DebugSetting>& debug_settings() {
    static const std::vector<DebugSetting> list = {};
    return list;
}

struct SettingRef {
    std::string tab;
    Config* config = nullptr;
    size_t index = 0;
    const DebugSetting* debug = nullptr;

    std::string id() const { return debug ? debug->id : config->get_option(index).id; }
    std::string name() const { return debug ? debug->name : config->get_option(index).name; }
    std::string full_id() const { return tab + "." + id(); }
    ConfigOptionType type() const { return debug ? debug->type : config->get_option(index).type; }
};

std::vector<SettingRef> all_settings() {
    std::vector<SettingRef> out;
    for (const char* tab : kTabs) {
        Config* config = find_config(tab);
        if (config == nullptr) continue;
        const auto& options = config->get_config_schema().options;
        for (size_t i = 0; i < options.size(); i++) {
            if (options[i].hidden) continue; // not in the menu either
            SettingRef ref;
            ref.tab = tab;
            ref.config = config;
            ref.index = i;
            out.push_back(ref);
        }
    }
    for (const DebugSetting& d : debug_settings()) {
        SettingRef ref;
        ref.tab = "debug";
        ref.debug = &d;
        out.push_back(ref);
    }
    return out;
}

const recomp::config::ConfigOptionEnum& enum_of(const SettingRef& ref) {
    return std::get<recomp::config::ConfigOptionEnum>(ref.config->get_option(ref.index).variant);
}

std::string value_text(const SettingRef& ref) {
    if (ref.debug) {
        ConfigValueVariant v = ref.debug->get();
        if (ref.debug->type == ConfigOptionType::Bool) return std::get<bool>(v) ? "on" : "off";
        return format_number(std::get<double>(v), 1);
    }
    const ConfigOption& option = ref.config->get_option(ref.index);
    ConfigValueVariant v = ref.config->get_option_value(option.id);
    switch (option.type) {
        case ConfigOptionType::Bool:
            return std::holds_alternative<bool>(v) && std::get<bool>(v) ? "on" : "off";
        case ConfigOptionType::Enum: {
            if (!std::holds_alternative<uint32_t>(v)) return "?";
            const auto& e = enum_of(ref);
            auto it = e.find_option_from_value(std::get<uint32_t>(v));
            return it == e.options.end() ? std::to_string(std::get<uint32_t>(v)) : it->key;
        }
        case ConfigOptionType::Number:
            return std::holds_alternative<double>(v)
                ? format_number(std::get<double>(v), std::get<recomp::config::ConfigOptionNumber>(option.variant).precision) : "?";
        case ConfigOptionType::String:
            return std::holds_alternative<std::string>(v) ? "\"" + std::get<std::string>(v) + "\"" : "?";
        default:
            return "?";
    }
}

std::string value_help(const SettingRef& ref) {
    switch (ref.type()) {
        case ConfigOptionType::Bool:
            return "on or off";
        case ConfigOptionType::Number: {
            double min = ref.debug ? ref.debug->min : std::get<recomp::config::ConfigOptionNumber>(ref.config->get_option(ref.index).variant).min;
            double max = ref.debug ? ref.debug->max : std::get<recomp::config::ConfigOptionNumber>(ref.config->get_option(ref.index).variant).max;
            return "a number from " + format_number(min, 1) + " to " + format_number(max, 1);
        }
        case ConfigOptionType::Enum: {
            std::string out = "one of:";
            int n = 0;
            for (const auto& o : enum_of(ref).options) {
                if (++n > 24) { out += " ..."; break; }
                out += " " + o.key;
            }
            return out;
        }
        case ConfigOptionType::String:
            return "any text";
        default:
            return "?";
    }
}

// A setting by id ("walk_speed"), tab and id ("general.walk_speed"), name ("Board Walk Speed"), or a part of one of
// those that only one setting has.
bool find_setting(const std::string& query, SettingRef* out, std::vector<SettingRef>* matches) {
    std::vector<SettingRef> list = all_settings();
    std::string q = lower(query);
    std::string sq = squash(query);
    matches->clear();
    if (sq.empty()) return false;
    for (const SettingRef& r : list) {
        if (lower(r.full_id()) == q || lower(r.id()) == q) { *out = r; return true; }
    }
    for (const SettingRef& r : list) {
        if (squash(r.name()) == sq || squash(r.id()) == sq || squash(r.full_id()) == sq) { *out = r; return true; }
    }
    for (const SettingRef& r : list) {
        if (squash(r.full_id()).find(sq) != std::string::npos || squash(r.name()).find(sq) != std::string::npos) {
            matches->push_back(r);
        }
    }
    if (matches->size() == 1) { *out = (*matches)[0]; return true; }
    return false;
}

bool lookup_setting(const std::string& query, SettingRef* ref) {
    std::vector<SettingRef> matches;
    if (find_setting(query, ref, &matches)) return true;
    if (matches.empty()) {
        error("no setting called \"" + query + "\" (type settings to see them all)");
        return false;
    }
    std::string out = "several settings match \"" + query + "\":";
    int n = 0;
    for (const SettingRef& r : matches) {
        if (++n > 12) { out += " ..."; break; }
        out += " " + r.full_id();
    }
    error(out);
    return false;
}

bool parse_value(const SettingRef& ref, const std::string& text, ConfigValueVariant* out, std::string* why) {
    switch (ref.type()) {
        case ConfigOptionType::Bool: {
            bool b;
            if (!parse_bool(text, &b)) break;
            *out = b;
            return true;
        }
        case ConfigOptionType::Number: {
            double v;
            if (!parse_double(text, &v)) break;
            double min, max, step;
            if (ref.debug) {
                min = ref.debug->min; max = ref.debug->max; step = ref.debug->step;
            } else {
                const auto& n = std::get<recomp::config::ConfigOptionNumber>(ref.config->get_option(ref.index).variant);
                min = n.min; max = n.max; step = n.step;
            }
            if (max > min) v = std::clamp(v, min, max);
            if (step > 0) v = min + std::round((v - min) / step) * step; // the menu's slider moves in these steps
            if (max > min) v = std::clamp(v, min, max);
            *out = v;
            return true;
        }
        case ConfigOptionType::Enum: {
            const auto& e = enum_of(ref);
            std::string sq = squash(text);
            for (const auto& o : e.options) {
                if (lower(o.key) == lower(text) || squash(o.key) == sq || squash(o.name) == sq) { *out = o.value; return true; }
            }
            int n;
            if (parse_int(text, &n) && n >= 0 && e.find_option_from_value((uint32_t)n) != e.options.end()) { *out = (uint32_t)n; return true; }
            // A choice whose name starts with the text ("30" is "Original (30)" in the frame rates' names).
            const recomp::config::ConfigOptionEnumOption* found = nullptr;
            int count = 0;
            for (const auto& o : e.options) {
                if (!sq.empty() && squash(o.name).find(sq) != std::string::npos) { found = &o; count++; }
            }
            if (count == 1) { *out = found->value; return true; }
            break;
        }
        case ConfigOptionType::String:
            *out = text;
            return true;
        default:
            break;
    }
    *why = "\"" + text + "\" is not a value for " + ref.full_id() + ": it takes " + value_help(ref);
    return false;
}

// Sets a value the way the settings menu does: the option's change callbacks run, and the tab is saved (which also
// applies a tab that waits for Apply, like Graphics).
bool apply_value(const SettingRef& ref, const ConfigValueVariant& value, std::string* why) {
    if (ref.debug) {
        ref.debug->set(value);
        return true;
    }
    if (ref.config->is_config_option_disabled(ref.index)) {
        *why = ref.full_id() + " is greyed out in the menu right now (another setting turns it off)";
        return false;
    }
    if (std::holds_alternative<uint32_t>(value)) {
        const auto& e = enum_of(ref);
        auto it = e.find_option_from_value(std::get<uint32_t>(value));
        if (it != e.options.end() && ref.config->get_enum_option_disabled(ref.index, (uint32_t)(it - e.options.begin()))) {
            *why = "that choice of " + ref.full_id() + " is greyed out in the menu right now";
            return false;
        }
    }
    ref.config->update_option_value(ref.id(), value);
    ref.config->save_config();
    return true;
}

ConfigValueVariant default_value(const SettingRef& ref) {
    if (ref.debug) {
        if (ref.debug->type == ConfigOptionType::Bool) return ref.debug->def != 0.0;
        return ref.debug->def;
    }
    const ConfigOption& option = ref.config->get_option(ref.index);
    switch (option.type) {
        case ConfigOptionType::Bool: return std::get<recomp::config::ConfigOptionBool>(option.variant).default_value;
        case ConfigOptionType::Enum: return std::get<recomp::config::ConfigOptionEnum>(option.variant).default_value;
        case ConfigOptionType::Number: return std::get<recomp::config::ConfigOptionNumber>(option.variant).default_value;
        case ConfigOptionType::String: return std::get<recomp::config::ConfigOptionString>(option.variant).default_value;
        default: return std::monostate{};
    }
}

bool set_setting(const std::string& query, const std::string& text) {
    SettingRef ref;
    if (!lookup_setting(query, &ref)) return false;
    ConfigValueVariant value;
    std::string why;
    if (!parse_value(ref, text, &value, &why) || !apply_value(ref, value, &why)) {
        error(why);
        return false;
    }
    print(ref.full_id() + " = " + value_text(ref));
    return true;
}

// ---------------------------------------------------------------------------------------------------------------
// Warp lists

enum { kListPlace = 0, kListMap = 1 };

struct WarpList {
    const char* name;
    int id;
    const char* title;
    std::vector<const char*> aliases;
};

const std::vector<WarpList>& warp_lists() {
    static const std::vector<WarpList> lists = {
        { "place", kListPlace, "The Warp tab's places (levels, areas and the test room)", { "place", "places", "level", "levels" } },
        { "map", kListMap, "Every map the game has (map_names.inc), by name", { "map", "maps" } },
    };
    return lists;
}

const WarpList* find_list(const std::string& word) {
    std::string w = lower(word);
    for (const WarpList& l : warp_lists()) {
        for (const char* a : l.aliases) {
            if (w == a) return &l;
        }
    }
    return nullptr;
}

std::vector<std::string> list_names(int list) {
    if (list == kListPlace) return tooie::level_warp::place_names();
    std::vector<std::string> names;
    for (const MapName& m : kMapNames) names.push_back(m.name);
    return names;
}

const char* map_name(uint16_t id) {
    for (const MapName& m : kMapNames) {
        if (m.id == id) return m.name;
    }
    return "unnamed map";
}

// Entry `query` of a list, by number or name. 0: none; -1: several (in `matches`).
int find_entry(const std::vector<std::string>& names, const std::string& query, std::vector<int>* matches) {
    int n;
    matches->clear();
    if (parse_int(query, &n)) return (n >= 1 && n <= (int)names.size()) ? n : 0;
    std::string sq = squash(query);
    if (sq.empty()) return 0;
    for (size_t i = 0; i < names.size(); i++) {
        if (squash(names[i]) == sq) return (int)i + 1;
    }
    for (size_t i = 0; i < names.size(); i++) {
        if (squash(names[i]).find(sq) != std::string::npos) matches->push_back((int)i + 1);
    }
    if (matches->size() == 1) return (*matches)[0];
    return matches->empty() ? 0 : -1;
}

void hide_prompt() {
    if (g_open) {
        g_open = false;
        recompui::hide_context(g_context);
    }
}

bool can_warp_now() {
    if (!tooie::debug::can_warp()) {
        error("a save file has to be loaded first (not the launcher, the title screen or the file select)");
        return false;
    }
    return true;
}

bool do_warp(const WarpList& list, int pos, const std::string& name) {
    if (!can_warp_now()) return false;
    if (list.id == kListPlace) {
        if (!tooie::level_warp::warp_to_place((size_t)pos - 1)) {
            error(format("could not warp to %s %d", list.name, pos));
            return false;
        }
    } else {
        tooie::debug::request_warp(kMapNames[pos - 1].id, 0);
    }
    print(format("%s %d: %s", list.name, pos, name.c_str()));
    hide_prompt(); // the warp is seen at once, as when the Warp tab closes the menu
    return true;
}

// `query` in one list, or (list null) in every list.
void warp_lookup(const WarpList* list, const std::string& query) {
    std::vector<int> matches;
    if (list != nullptr) {
        std::vector<std::string> names = list_names(list->id);
        int pos = find_entry(names, query, &matches);
        if (pos > 0) { do_warp(*list, pos, names[pos - 1]); return; }
        if (pos == 0) { error(format("nothing in %s matches \"%s\" (list %s shows it)", list->name, query.c_str(), list->name)); return; }
        std::string out = "several match:";
        int n = 0;
        for (int m : matches) {
            if (++n > 12) { out += " ..."; break; }
            out += format(" %s %d (%s);", list->name, m, names[m - 1].c_str());
        }
        error(out);
        return;
    }
    struct Hit { const WarpList* list; int pos; std::string name; };
    std::vector<Hit> hits;
    std::string sq = squash(query);
    for (const WarpList& l : warp_lists()) {
        std::vector<std::string> names = list_names(l.id);
        for (size_t i = 0; i < names.size(); i++) {
            if (squash(names[i]) == sq) { do_warp(l, (int)i + 1, names[i]); return; }
            if (!sq.empty() && squash(names[i]).find(sq) != std::string::npos) hits.push_back({ &l, (int)i + 1, names[i] });
        }
    }
    if (hits.size() == 1) { do_warp(*hits[0].list, hits[0].pos, hits[0].name); return; }
    if (hits.empty()) { error("nothing matches \"" + query + "\" (list shows the lists)"); return; }
    std::string out = "several match:";
    int n = 0;
    for (const Hit& h : hits) {
        if (++n > 12) { out += " ..."; break; }
        out += format(" %s %d (%s);", h.list->name, h.pos, h.name.c_str());
    }
    error(out);
}

// ---------------------------------------------------------------------------------------------------------------
// Pad buttons and characters

// The N64 pad's bits (the same values src/debug/pad_script.cpp uses).
struct ButtonName { const char* name; uint16_t bit; };
const ButtonName kButtons[] = {
    { "a", 0x8000 }, { "b", 0x4000 }, { "z", 0x2000 }, { "start", 0x1000 },
    { "l", 0x0020 }, { "r", 0x0010 },
    { "up", 0x0800 }, { "down", 0x0400 }, { "left", 0x0200 }, { "right", 0x0100 },
    { "dup", 0x0800 }, { "ddown", 0x0400 }, { "dleft", 0x0200 }, { "dright", 0x0100 },
    { "cup", 0x0008 }, { "cdown", 0x0004 }, { "cleft", 0x0002 }, { "cright", 0x0001 },
};

// "a", "a+b", "start".
bool parse_buttons(const std::string& text, uint16_t* out) {
    *out = 0;
    std::string cur;
    std::string t = lower(text) + "+";
    for (char c : t) {
        if (c != '+') { cur += c; continue; }
        bool found = false;
        for (const ButtonName& b : kButtons) {
            if (cur == b.name) { *out |= b.bit; found = true; break; }
        }
        if (!found) return false;
        cur.clear();
    }
    return true;
}

// ---------------------------------------------------------------------------------------------------------------
// Persistence of bind and alias (console.txt in the game folder).

std::filesystem::path state_path() {
    return recompui::file::get_app_folder_path() / "console.txt";
}

void save_state() {
    std::ofstream out{ state_path() };
    if (!out.good()) return;
    out << "# Developer console binds and aliases. Written by the game.\n";
    std::lock_guard lock{ g_mutex };
    for (const auto& [name, body] : g_aliases) out << "alias " << name << " " << body << "\n";
    for (const auto& [code, body] : g_binds) out << "bind " << SDL_GetScancodeName(code) << " " << body << "\n";
}

void load_state() {
    std::ifstream in{ state_path() };
    std::string line;
    while (std::getline(in, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;
        std::vector<std::string> w = split(line);
        if (w.size() < 3) continue;
        size_t body_at = line.find(w[1], line.find(w[0]) + w[0].size()) + w[1].size();
        std::string body = trim(line.substr(body_at));
        std::lock_guard lock{ g_mutex };
        if (lower(w[0]) == "alias") g_aliases[lower(w[1])] = body;
        else if (lower(w[0]) == "bind") {
            SDL_Scancode code = SDL_GetScancodeFromName(w[1].c_str());
            if (code != SDL_SCANCODE_UNKNOWN) g_binds[code] = body;
        }
    }
}

// The text after the first `n` words of a command line, as typed (keeps its own spacing and ';').
std::string rest_of(const std::string& line, size_t n) {
    size_t at = 0;
    for (size_t i = 0; i < n; i++) {
        at = line.find_first_not_of(" \t", at);
        if (at == std::string::npos) return "";
        at = line.find_first_of(" \t", at);
        if (at == std::string::npos) return "";
    }
    return trim(line.substr(at));
}

// ---------------------------------------------------------------------------------------------------------------
// Commands

struct Ctx {
    uint8_t* rdram; // null before the game starts
    recomp_context* ctx; // the game update hook's registers (null before the game starts)
    std::vector<std::string> w;
    std::string line; // the whole command as typed
    int depth;
};

struct Command {
    const char* name;
    std::vector<const char*> aliases;
    bool needs_game;
    const char* usage;
    const char* help;
    std::function<void(Ctx&)> run;
};

const std::vector<Command>& commands();

void cmd_help(Ctx& c) {
    if (c.w.size() >= 2) {
        std::string want = lower(c.w[1]);
        for (const Command& cmd : commands()) {
            bool match = want == cmd.name;
            for (const char* a : cmd.aliases) match = match || want == a;
            if (match) { print(std::string(cmd.usage) + "  -  " + cmd.help); return; }
        }
        // Not a command name: the commands whose use or help mention the word.
        std::string sq = squash(join(c.w, 1));
        std::string out;
        for (const Command& cmd : commands()) {
            if (squash(cmd.usage).find(sq) == std::string::npos && squash(cmd.help).find(sq) == std::string::npos) continue;
            out += (out.empty() ? "" : "\n") + std::string(cmd.usage) + "  -  " + cmd.help;
        }
        if (out.empty()) error("no command or help text mentions \"" + join(c.w, 1) + "\"");
        else print(out);
        return;
    }
    std::string out;
    for (const Command& cmd : commands()) {
        if (!out.empty()) out += '\n';
        out += std::string(cmd.usage) + "  -  " + cmd.help;
    }
    print(out);
}

void cmd_start(Ctx&) {
    if (ultramodern::is_game_started()) { print("the game is already running"); return; }
    std::u8string id = u8"bt.n64.us.1.0"; // supported_games[0] in src/main/main.cpp
    if (!recomp::is_rom_valid(id)) { error("no Banjo-Tooie ROM is loaded yet (load it once in the launcher)"); return; }
    recompui::update_game_mod_id("bt");
    recomp::start_game(id, {});
    recompui::hide_all_contexts();
    print("starting the game (the launcher's Play option also sets the picture preset; start does not)");
}

void cmd_quit(Ctx& c) {
    int code = g_had_error.load() ? 1 : 0;
    if (c.w.size() >= 2 && !parse_int(c.w[1], &code)) { error("quit [exit code]"); return; }
    g_exit_code = code;
    print(format("quitting with exit code %d", code));
    ultramodern::quit();
}

void cmd_warp(Ctx& c) {
    if (c.w.size() < 2) { error("warp <list> <number or name> | warp <name> | warp id <map hex> [exit hex]"); return; }
    if (lower(c.w[1]) == "id") {
        // warp id AF [exit]: a map by its number, in hex as everywhere else (TOOIE_WARP, map_names.inc), exit 0 the default.
        uint32_t map = 0, exit = 0;
        auto hex_of = [](const std::string& s, uint32_t* out) {
            std::string h = (s.size() > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) ? s.substr(2) : s;
            if (h.empty() || h.size() > 4) return false;
            for (char ch : h) {
                if (!std::isxdigit((unsigned char)ch)) return false;
            }
            *out = (uint32_t)std::strtoul(h.c_str(), nullptr, 16);
            return true;
        };
        if (c.w.size() < 3 || !hex_of(c.w[2], &map) || (c.w.size() >= 4 && (!hex_of(c.w[3], &exit) || exit > 0xFF))) {
            error("warp id <map hex> [exit hex]");
            return;
        }
        if (!can_warp_now()) return;
        tooie::debug::request_warp((uint16_t)map, (uint8_t)exit);
        print(format("map 0x%X (%s), exit %u", map, map_name((uint16_t)map), exit));
        hide_prompt();
        return;
    }
    const WarpList* list = find_list(c.w[1]);
    if (list != nullptr && c.w.size() >= 3) warp_lookup(list, join(c.w, 2));
    else warp_lookup(nullptr, join(c.w, 1));
}

void cmd_list(Ctx& c) {
    if (c.w.size() < 2) {
        std::string out;
        for (const WarpList& l : warp_lists()) {
            if (!out.empty()) out += '\n';
            out += format("%s: %s, %zu entries", l.name, l.title, list_names(l.id).size());
        }
        print(out);
        return;
    }
    const WarpList* list = find_list(c.w[1]);
    if (list == nullptr) { error("no list called \"" + c.w[1] + "\"; the lists are place and map"); return; }
    std::string sq = squash(join(c.w, 2));
    std::vector<std::string> names = list_names(list->id);
    std::string out;
    for (size_t i = 0; i < names.size(); i++) {
        if (!sq.empty() && squash(names[i]).find(sq) == std::string::npos) continue;
        if (!out.empty()) out += '\n';
        out += format("%s %zu: %s", list->name, i + 1, names[i].c_str());
    }
    if (out.empty()) error("nothing matches");
    else print(out);
}

void cmd_status(Ctx& c) {
    double fps = 0.0;
    {
        std::lock_guard lock{ g_mutex };
        if (g_frame_times.size() >= 2) {
            double span = std::chrono::duration<double>(g_frame_times.back() - g_frame_times.front()).count();
            if (span > 0) fps = (g_frame_times.size() - 1) / span;
        }
    }
    uint16_t map = tooie::debug::current_map(c.rdram);
    print(format("map 0x%X (%s), game updates %llu (%.1f per second), warp %s, a save file %s",
        map, map_name(map), (unsigned long long)g_frames.load(), fps,
        tooie::debug::warp_pending() ? "pending" : "none", tooie::debug::can_warp() ? "is loaded" : "is not loaded"));
}

bool cheats_master_on(); // below

// flag <hex id> [on|off]: the game's own progress flags (the getter and setter func_800DA298 / func_800DA3B8).
void cmd_flag(Ctx& c) {
    uint32_t id = 0;
    auto hex_of = [](const std::string& s, uint32_t* out) {
        std::string h = (s.size() > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) ? s.substr(2) : s;
        if (h.empty() || h.size() > 4) return false;
        for (char ch : h) {
            if (!std::isxdigit((unsigned char)ch)) return false;
        }
        *out = (uint32_t)std::strtoul(h.c_str(), nullptr, 16);
        return true;
    };
    bool on;
    if (c.w.size() < 2 || !hex_of(c.w[1], &id) || (c.w.size() >= 3 && !parse_bool(c.w[2], &on))) { error("flag <flag number in hex> [on|off]"); return; }
    if (c.ctx == nullptr) { error("no game update is running"); return; }
    if (c.w.size() >= 3) {
        tooie::progress_cheats::set_flag(c.rdram, c.ctx, (int32_t)id, on);
        print(format("flag 0x%X set %s (the save file keeps it if you save)", id, on ? "on" : "off"));
        return;
    }
    print(format("flag 0x%X is %s", id, tooie::progress_cheats::get_flag(c.rdram, c.ctx, (int32_t)id) ? "on" : "off"));
}

void cmd_pos(Ctx& c) {
    float p[3];
    if (!tooie::player_cheats::position(c.rdram, p)) { error("there is no player yet"); return; }
    print(format("%.2f %.2f %.2f (x y z), map 0x%X", p[0], p[1], p[2], tooie::debug::current_map(c.rdram)));
}

void cmd_goto(Ctx& c) {
    float p[3];
    double v[3];
    if (c.w.size() < 4 || !parse_double(c.w[1], &v[0]) || !parse_double(c.w[2], &v[1]) || !parse_double(c.w[3], &v[2])) { error("goto <x> <y> <z> (pos shows where you are)"); return; }
    for (int k = 0; k < 3; k++) p[k] = (float)v[k];
    if (!tooie::player_cheats::teleport(c.rdram, p)) { error("there is no player yet"); return; }
    print(format("moved to %.2f %.2f %.2f", p[0], p[1], p[2]));
}

// transform <form>: the Cheats tab's Transformation row (turns the cheats on).
void cmd_transform(Ctx& c) {
    SettingRef ref;
    if (!lookup_setting("cheats.cheat_transform", &ref)) return;
    if (c.w.size() < 2) { print(ref.full_id() + " = " + value_text(ref) + "   (takes " + value_help(ref) + ")"); return; }
    if (!tooie::debug::can_warp()) { error("a save file has to be loaded first"); return; }
    if (!cheats_master_on()) return;
    set_setting("cheats.cheat_transform", join(c.w, 1));
}

// repeat <n> <command>: the command n times (up to 1000).
void cmd_repeat(Ctx& c) {
    int n;
    std::string body = rest_of(c.line, 2);
    if (c.w.size() < 3 || !parse_int(c.w[1], &n) || n < 1 || n > 1000) { error("repeat <times, 1 to 1000> <command>"); return; }
    if (c.depth > 8) { error("repeat nests too deep"); return; }
    for (int i = 0; i < n; i++) enqueue_line(body, c.depth + 1, true);
    print(format("%d times: %s", n, body.c_str()));
}

// tee <file> | tee off: copy everything the console prints to a file.
void cmd_tee(Ctx& c) {
    std::lock_guard lock{ g_mutex };
    if (c.w.size() >= 2 && lower(c.w[1]) == "off") {
        if (g_tee != nullptr) { std::fclose(g_tee); g_tee = nullptr; }
        print("tee off");
        return;
    }
    if (c.w.size() < 2) { error("tee <file> | tee off"); return; }
    std::filesystem::path path = rest_of(c.line, 1);
    if (path.is_relative()) path = recompui::file::get_app_folder_path() / path;
    if (g_tee != nullptr) std::fclose(g_tee);
    g_tee = std::fopen(path.string().c_str(), "a");
    if (g_tee == nullptr) { error("cannot write " + path.string()); return; }
    print("copying the output to " + path.string());
}

void cmd_dev(Ctx& c) {
    bool on = true;
    if (c.w.size() >= 2 && !parse_bool(c.w[1], &on)) { error("dev | dev on | dev off"); return; }
    std::string path;
    if (!tooie::set_dev_file(on, &path)) { error(std::string(on ? "could not write " : "could not remove ") + path); return; }
    print((on ? "dev.txt is in place: " : "dev.txt is gone: ") + path + "\nRestart the game for the tabs to " + (on ? "show." : "go back to their switches."));
}

void cmd_screenshot(Ctx&) {
    tooie::screenshot::take();
    print("screenshot of the next frame, saved to the screenshots folder of the app-data folder (as F12)");
}

// ---------------------------------------------------------------------------------------------------------------
// Cheats, save states, spawning, waiting for a state, RAM diffs, timing

// The Cheats tab's on/off cheats (the master switch is not one of them).
std::vector<SettingRef> cheat_list() {
    std::vector<SettingRef> out;
    for (const SettingRef& r : all_settings()) {
        if (r.tab == "cheats" && !r.debug && r.type() == ConfigOptionType::Bool && r.id() != "cheats_enabled") out.push_back(r);
    }
    return out;
}

// "noclip", "no clip", "cheat_noclip", or a part of a name that only one cheat has.
bool find_cheat(const std::string& query, SettingRef* out) {
    std::vector<SettingRef> list = cheat_list();
    std::string sq = squash(query);
    if (sq.empty()) return false;
    for (const SettingRef& r : list) {
        if (squash(r.id()) == sq || squash(r.id()) == "cheat" + sq || squash(r.name()) == sq) { *out = r; return true; }
    }
    std::vector<SettingRef> matches;
    for (const SettingRef& r : list) {
        if (squash(r.id()).find(sq) != std::string::npos || squash(r.name()).find(sq) != std::string::npos) matches.push_back(r);
    }
    if (matches.size() == 1) { *out = matches[0]; return true; }
    if (matches.empty()) {
        error("no cheat called \"" + query + "\" (cheat lists them)");
    } else {
        std::string text = "several cheats match \"" + query + "\":";
        for (const SettingRef& r : matches) text += " " + r.id();
        error(text);
    }
    return false;
}

// The cheats only work while the Cheats tab's master switch is on: the console turns it on when it sets a cheat.
bool cheats_master_on() {
    SettingRef master;
    std::vector<SettingRef> matches;
    if (!find_setting("cheats.cheats_enabled", &master, &matches)) { error("this build has no Cheats tab"); return false; }
    if (std::get<bool>(master.config->get_option_value(master.id()))) return true;
    std::string why;
    if (!apply_value(master, ConfigValueVariant{ true }, &why)) { error(why); return false; }
    return true;
}

void cmd_cheat(Ctx& c) {
    if (c.w.size() < 2) {
        std::string out = std::string("cheats ") + (tooie::cheats::enabled() ? "on" : "off") + " (the master switch; setting a cheat turns it on)";
        for (const SettingRef& r : cheat_list()) out += "\n" + r.id() + " = " + value_text(r) + "   (" + r.name() + ")";
        print(out);
        return;
    }
    SettingRef ref;
    if (!find_cheat(c.w[1], &ref)) return;
    bool now = std::get<bool>(ref.config->get_option_value(ref.id()));
    bool on = !now; // no value: flip it
    if (c.w.size() >= 3 && !parse_bool(c.w[2], &on)) { error("cheat [name] [on|off]"); return; }
    std::string why;
    if (on && !cheats_master_on()) return;
    if (!apply_value(ref, ConfigValueVariant{ on }, &why)) { error(why); return; }
    print(ref.id() + " = " + value_text(ref));
}

void cmd_unlock(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "";
    const char* cheat = what == "moves" ? "all_moves" : what == "everything" ? "unlock_everything" : nullptr;
    if (cheat == nullptr) { error("unlock moves | unlock everything (cheats; the save file is not changed)"); return; }
    SettingRef ref;
    if (!find_cheat(cheat, &ref)) return;
    std::string why;
    if (!cheats_master_on() || !apply_value(ref, ConfigValueVariant{ true }, &why)) { if (!why.empty()) error(why); return; }
    print(ref.id() + " = " + value_text(ref));
}

void cmd_savestate(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "";
    if (what != "save" && what != "load") { error("savestate save | savestate load (one snapshot, kept in memory; in a level only)"); return; }
    if (!tooie::debug::can_warp()) { error("a save file has to be loaded first"); return; }
    if (what == "save") tooie::save_state::request_save();
    else tooie::save_state::request_load();
    print(what + " requested (taken on the next game update)");
}

void cmd_spawn(Ctx& c) {
    std::vector<std::string> names = tooie::enemy_spawner::names();
    if (c.w.size() < 2) {
        std::string out;
        for (size_t i = 0; i < names.size(); i++) out += format("%zu: %s%s", i + 1, names[i].c_str(), i + 1 < names.size() ? "\n" : "");
        print(out);
        return;
    }
    int count = 1;
    std::string query = join(c.w, 1);
    if (c.w.size() >= 3 && parse_int(c.w.back(), &count) && count >= 1 && count <= 20) query = join(c.w, 1, c.w.size() - 1);
    else count = 1;
    std::vector<int> matches;
    int pos = find_entry(names, query, &matches);
    if (pos <= 0) {
        if (pos == 0) { error("no enemy matches \"" + query + "\" (spawn lists them)"); return; }
        std::string out = "several match:";
        int n = 0;
        for (int m : matches) {
            if (++n > 12) { out += " ..."; break; }
            out += format(" %d (%s);", m, names[m - 1].c_str());
        }
        error(out);
        return;
    }
    if (!tooie::debug::can_warp()) { error("a save file has to be loaded first"); return; }
    if (!cheats_master_on()) return; // the spawner only works with the cheats on
    for (int i = 0; i < count; i++) tooie::enemy_spawner::spawn((size_t)pos - 1);
    print(format("%d x %s (in front of Banjo, on the next game update)", count, names[pos - 1].c_str()));
}

// RAM diff: the first 16 MB as words, kept by `diff snapshot`, compared by `diff` / `diff compare`.
std::vector<uint32_t> g_diff_snapshot;

void cmd_diff(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "compare";
    if (what == "snapshot" || what == "snap" || what == "keep") {
        g_diff_snapshot.resize((kFindEnd - kRamStart) / 4);
        for (size_t i = 0; i < g_diff_snapshot.size(); i++) g_diff_snapshot[i] = read_ram(c.rdram, kRamStart + (uint32_t)i * 4, 4);
        print("RAM kept (diff shows what changed since)");
        return;
    }
    if (what != "compare") { error("diff snapshot | diff [compare] [how many to show, default 64]"); return; }
    if (g_diff_snapshot.empty()) { error("no snapshot yet (diff snapshot)"); return; }
    int show = 64;
    if (c.w.size() >= 3 && (!parse_int(c.w[2], &show) || show < 1)) { error("diff compare [how many to show]"); return; }
    size_t changed = 0;
    std::string out;
    for (size_t i = 0; i < g_diff_snapshot.size(); i++) {
        uint32_t now = read_ram(c.rdram, kRamStart + (uint32_t)i * 4, 4);
        if (now == g_diff_snapshot[i]) continue;
        if ((int)changed < show) out += format("%08X: %08X -> %08X\n", kRamStart + (uint32_t)i * 4, g_diff_snapshot[i], now);
        changed++;
    }
    print(format("%zu words changed", changed) + (out.empty() ? "" : "\n" + out.substr(0, out.size() - 1)) + (changed > (size_t)show ? "\n..." : ""));
}

// perf <seconds>: the time between game updates, written to perf-<time>.csv in the app folder.
std::vector<double> g_perf_ms;
bool g_perf_on;
Clock::time_point g_perf_end, g_perf_last;

void cmd_perf(Ctx& c) {
    double seconds;
    if (c.w.size() < 2 || !parse_double(c.w[1], &seconds) || seconds <= 0 || seconds > 600) { error("perf <seconds, up to 600>"); return; }
    g_perf_ms.clear();
    g_perf_last = Clock::time_point{};
    g_perf_end = Clock::now() + std::chrono::microseconds((int64_t)(seconds * 1e6));
    g_perf_on = true;
    print(format("timing game updates for %.0f seconds", seconds));
}

// Called once per game update.
void perf_tick() {
    if (!g_perf_on) return;
    Clock::time_point now = Clock::now();
    if (g_perf_last != Clock::time_point{}) g_perf_ms.push_back(std::chrono::duration<double, std::milli>(now - g_perf_last).count());
    g_perf_last = now;
    if (now < g_perf_end) return;
    g_perf_on = false;
    if (g_perf_ms.empty()) { error("no game updates were timed"); return; }
    std::time_t t = std::time(nullptr);
    char stamp[32];
    std::strftime(stamp, sizeof(stamp), "%Y%m%d-%H%M%S", std::localtime(&t));
    std::filesystem::path path = recompui::file::get_app_folder_path() / (std::string("perf-") + stamp + ".csv");
    {
        std::ofstream out{ path };
        out << "update,ms\n";
        for (size_t i = 0; i < g_perf_ms.size(); i++) out << i << "," << g_perf_ms[i] << "\n";
    }
    std::vector<double> sorted = g_perf_ms;
    std::sort(sorted.begin(), sorted.end());
    double sum = 0;
    for (double v : sorted) sum += v;
    double avg = sum / sorted.size();
    double p99 = sorted[std::min(sorted.size() - 1, (size_t)(sorted.size() * 0.99))];
    {
        std::lock_guard lock{ g_mutex };
        g_current = "perf";
    }
    print(format("%zu updates, average %.2f ms (%.1f per second), 99th percentile %.2f ms, worst %.2f ms; saved to %s",
        sorted.size(), avg, 1000.0 / avg, p99, sorted.back(), path.string().c_str()));
}

void cmd_sysinfo(Ctx&) {
    int w = 0, h = 0;
    if (window != nullptr) SDL_GetWindowSize(window, &w, &h);
    const char* driver = SDL_GetCurrentVideoDriver();
    print(format("%s, %d logical CPUs, %d MB RAM, video driver %s, window %dx%d",
        SDL_GetPlatform(), SDL_GetCPUCount(), SDL_GetSystemRAM(), driver != nullptr ? driver : "none", w, h));
}

void cmd_settings(Ctx& c) {
    std::string sq = squash(join(c.w, 1));
    std::string out;
    int n = 0;
    for (const SettingRef& r : all_settings()) {
        if (!sq.empty() && squash(r.full_id()).find(sq) == std::string::npos && squash(r.name()).find(sq) == std::string::npos) continue;
        if (!out.empty()) out += '\n';
        out += r.full_id() + " = " + value_text(r) + "   (" + r.name() + ")";
        n++;
    }
    if (n == 0) error("no settings match");
    else print(out);
}

void cmd_get(Ctx& c) {
    if (c.w.size() < 2) { error("get <setting>"); return; }
    SettingRef ref;
    if (!lookup_setting(join(c.w, 1), &ref)) return;
    print(ref.full_id() + " = " + value_text(ref) + "   (" + ref.name() + "; takes " + value_help(ref) + ")");
}

void cmd_set(Ctx& c) {
    if (c.w.size() < 3) { error("set <setting> <value>"); return; }
    set_setting(c.w[1], join(c.w, 2));
}

void cmd_toggle(Ctx& c) {
    if (c.w.size() < 2) { error("toggle <setting>"); return; }
    SettingRef ref;
    if (!lookup_setting(join(c.w, 1), &ref)) return;
    std::string why;
    if (ref.type() == ConfigOptionType::Bool) {
        bool now = ref.debug ? std::get<bool>(ref.debug->get()) : std::get<bool>(ref.config->get_option_value(ref.id()));
        if (!apply_value(ref, ConfigValueVariant{ !now }, &why)) { error(why); return; }
    } else if (ref.type() == ConfigOptionType::Enum) {
        const auto& e = enum_of(ref);
        auto it = e.find_option_from_value(std::get<uint32_t>(ref.config->get_option_value(ref.id())));
        size_t at = it == e.options.end() ? 0 : (size_t)(it - e.options.begin());
        bool done = false;
        for (size_t k = 1; k <= e.options.size() && !done; k++) {
            size_t next = (at + k) % e.options.size();
            if (ref.config->get_enum_option_disabled(ref.index, (uint32_t)next)) continue;
            if (!apply_value(ref, ConfigValueVariant{ e.options[next].value }, &why)) { error(why); return; }
            done = true;
        }
    } else {
        error(ref.full_id() + " is not on/off or a choice; use set");
        return;
    }
    print(ref.full_id() + " = " + value_text(ref));
}

void cmd_reset(Ctx& c) {
    if (c.w.size() < 2) { error("reset <setting>"); return; }
    SettingRef ref;
    if (!lookup_setting(join(c.w, 1), &ref)) return;
    std::string why;
    if (!apply_value(ref, default_value(ref), &why)) { error(why); return; }
    print(ref.full_id() + " = " + value_text(ref) + " (default)");
}

void cmd_fps(Ctx& c) {
    if (c.w.size() < 2) {
        Ctx d = c;
        d.w = { "get", tooie::game_frame_rate::option };
        cmd_get(d);
        return;
    }
    set_setting(tooie::game_frame_rate::option, c.w[1]);
}

void cmd_press(Ctx& c) {
    // press <buttons> [frames] | press stick <x> <y> [frames] | press <buttons> stick <x> <y> [frames]
    uint16_t buttons = 0;
    bool stick = false;
    int x = 0, y = 0;
    size_t i = 1;
    if (i < c.w.size() && lower(c.w[i]) != "stick") {
        if (!parse_buttons(c.w[i], &buttons)) { error("unknown button in \"" + c.w[i] + "\" (a b z start l r up down left right cup cdown cleft cright)"); return; }
        i++;
    }
    if (i < c.w.size() && lower(c.w[i]) == "stick") {
        if (i + 2 >= c.w.size() || !parse_int(c.w[i + 1], &x) || !parse_int(c.w[i + 2], &y)) { error("press stick <x> <y> [frames], x and y from -80 to 80"); return; }
        x = std::clamp(x, -80, 80);
        y = std::clamp(y, -80, 80);
        stick = true;
        i += 3;
    }
    int frames = -1;
    if (i < c.w.size() && (!parse_int(c.w[i], &frames) || frames < 1)) { error("press <buttons> [frames]"); return; }
    if (buttons == 0 && !stick) { error("press <buttons> [frames] | press stick <x> <y> [frames]"); return; }
    {
        std::lock_guard lock{ g_input_mutex };
        g_press_buttons = buttons;
        g_press_stick = stick;
        g_press_x = (int8_t)x;
        g_press_y = (int8_t)y;
        g_press_frames = frames;
    }
    print(frames < 0 ? "held until release" : format("held for %d frames", frames));
}

void cmd_release(Ctx&) {
    std::lock_guard lock{ g_input_mutex };
    g_press_frames = 0;
    g_press_buttons = 0;
    g_press_stick = false;
    print("released");
}

void cmd_wait(Ctx& c) {
    const char* usage = "wait <frames> | wait <n>ms | wait <n>s | wait map <map hex> [timeout s] | wait until <address> <value> [8|16|32] [timeout s]";
    if (c.w.size() < 2) { error(usage); return; }
    std::string v = lower(c.w[1]);
    if (v == "map" || v == "until") {
        if (!ultramodern::is_game_started()) { error("wait " + v + " needs the game running"); return; }
        double timeout = 120;
        if (v == "map") {
            uint32_t id = 0;
            std::string h = c.w.size() >= 3 && c.w[2].size() > 2 && c.w[2][0] == '0' && (c.w[2][1] == 'x' || c.w[2][1] == 'X') ? c.w[2].substr(2) : (c.w.size() >= 3 ? c.w[2] : "");
            char* end = nullptr;
            id = (uint32_t)std::strtoul(h.c_str(), &end, 16);
            if (h.empty() || *end != '\0' || id > 0xFFFF || (c.w.size() >= 4 && !parse_double(c.w[3], &timeout))) { error(usage); return; }
            g_wait_cond = [id] { return g_rdram != nullptr && tooie::debug::current_map(g_rdram) == id && !tooie::debug::map_change_busy(g_rdram); };
            print(format("waiting for map 0x%X", id));
        } else {
            uint32_t addr, value;
            if (c.w.size() < 4 || !parse_addr(c.w[2], &addr) || !parse_u32(c.w[3], &value)) { error(usage); return; }
            int size = size_of_value(c.w[3], value);
            size_t next = 4;
            if (c.w.size() > next) {
                int s = parse_size(c.w[next]);
                if (s != 0) { size = s; next++; }
            }
            if (c.w.size() > next && !parse_double(c.w[next], &timeout)) { error(usage); return; }
            if ((addr & (size - 1)) != 0) { error("the address must be aligned to the size"); return; }
            uint32_t mask = size == 4 ? 0xFFFFFFFFu : (1u << (size * 8)) - 1;
            g_wait_cond = [addr, value, size, mask] { return g_rdram != nullptr && read_ram(g_rdram, addr, size) == (value & mask); };
            print(format("waiting for %08X = %s", addr, hex(value & mask, size).c_str()));
        }
        g_wait_cond_deadline = Clock::now() + std::chrono::microseconds((int64_t)(timeout * 1e6));
        return;
    }
    double n;
    if (v.size() > 2 && v.substr(v.size() - 2) == "ms" && parse_double(v.substr(0, v.size() - 2), &n) && n >= 0) {
        g_wait_until = Clock::now() + std::chrono::microseconds((int64_t)(n * 1000.0));
    } else if (v.size() > 1 && v.back() == 's' && parse_double(v.substr(0, v.size() - 1), &n) && n >= 0) {
        g_wait_until = Clock::now() + std::chrono::microseconds((int64_t)(n * 1e6));
    } else {
        int f;
        if (!parse_int(v, &f) || f < 0) { error(usage); return; }
        if (!ultramodern::is_game_started()) { error("wait in frames needs the game running; use ms or s"); return; }
        g_wait_frames_until = g_frames.load() + (uint64_t)f;
    }
    print("waiting " + v);
}

void cmd_peek(Ctx& c) {
    uint32_t addr;
    if (c.w.size() < 2 || !parse_addr(c.w[1], &addr)) { error("peek <address> [bytes, up to 256]"); return; }
    int len = 4;
    if (c.w.size() >= 3 && (!parse_int(c.w[2], &len) || len < 1 || len > 256)) { error("peek <address> [bytes, up to 256]"); return; }
    if ((uint64_t)addr + len > kRamEnd) { error("past the end of RAM"); return; }
    std::string out;
    for (int row = 0; row < len; row += 16) {
        if (!out.empty()) out += '\n';
        out += format("%08X:", addr + row);
        for (int k = row; k < len && k < row + 16; k++) out += format(" %02X", read_ram(c.rdram, addr + k, 1));
    }
    print(out);
}

void cmd_poke(Ctx& c) {
    uint32_t addr, value;
    if (c.w.size() < 3 || !parse_addr(c.w[1], &addr) || !parse_u32(c.w[2], &value)) { error("poke <address> <value> [8|16|32]"); return; }
    int size = c.w.size() >= 4 ? parse_size(c.w[3]) : size_of_value(c.w[2], value);
    if (size == 0) { error("size is 8, 16 or 32"); return; }
    if ((addr & (size - 1)) != 0) { error("the address must be aligned to the size"); return; }
    write_ram(c.rdram, addr, value, size);
    print(format("%08X = %s", addr, hex(read_ram(c.rdram, addr, size), size).c_str()));
}

void cmd_expect(Ctx& c) {
    uint32_t addr, value;
    if (c.w.size() < 3 || !parse_addr(c.w[1], &addr) || !parse_u32(c.w[2], &value)) { error("expect <address> <value> [8|16|32]"); return; }
    int size = c.w.size() >= 4 ? parse_size(c.w[3]) : size_of_value(c.w[2], value);
    if (size == 0 || (addr & (size - 1)) != 0) { error("size is 8, 16 or 32, and the address aligned to it"); return; }
    uint32_t mask = size == 4 ? 0xFFFFFFFFu : (1u << (size * 8)) - 1;
    uint32_t got = read_ram(c.rdram, addr, size);
    if (got == (value & mask)) print(format("ok: %08X = %s", addr, hex(got, size).c_str()));
    else error(format("%08X = %s, expected %s", addr, hex(got, size).c_str(), hex(value & mask, size).c_str()));
}

void cmd_find(Ctx& c) {
    // find <value> [8|16|32] [from] [to]
    uint32_t value;
    if (c.w.size() < 2 || !parse_u32(c.w[1], &value)) { error("find <value> [8|16|32] [from address] [to address]"); return; }
    int size = c.w.size() >= 3 ? parse_size(c.w[2]) : size_of_value(c.w[1], value);
    uint32_t from = kRamStart, to = kFindEnd;
    if (size == 0 || (c.w.size() >= 4 && !parse_addr(c.w[3], &from)) || (c.w.size() >= 5 && !parse_addr(c.w[4], &to)) || to <= from) {
        error("find <value> [8|16|32] [from address] [to address]");
        return;
    }
    uint32_t mask = size == 4 ? 0xFFFFFFFFu : (1u << (size * 8)) - 1;
    value &= mask;
    std::vector<uint32_t> hits;
    size_t total = 0;
    for (uint32_t a = (from + size - 1) & ~(uint32_t)(size - 1); a + size <= to; a += size) {
        if (read_ram(c.rdram, a, size) == value) {
            if (hits.size() < 32) hits.push_back(a);
            total++;
        }
    }
    std::string out = format("%zu found", total);
    for (uint32_t a : hits) out += format(" %08X", a);
    if (total > hits.size()) out += " ...";
    print(out);
}

void cmd_freeze(Ctx& c) {
    uint32_t addr, value;
    if (c.w.size() < 3 || !parse_addr(c.w[1], &addr) || !parse_u32(c.w[2], &value)) { error("freeze <address> <value> [8|16|32]"); return; }
    int size = c.w.size() >= 4 ? parse_size(c.w[3]) : size_of_value(c.w[2], value);
    if (size == 0 || (addr & (size - 1)) != 0) { error("size is 8, 16 or 32, and the address aligned to it"); return; }
    std::lock_guard lock{ g_mutex };
    g_freezes.erase(std::remove_if(g_freezes.begin(), g_freezes.end(), [&](const Freeze& f) { return f.addr == addr; }), g_freezes.end());
    g_freezes.push_back({ addr, value, size });
    print(format("%08X kept at %s every frame", addr, hex(value, size).c_str()));
}

void cmd_unfreeze(Ctx& c) {
    std::lock_guard lock{ g_mutex };
    uint32_t addr;
    if (c.w.size() < 2 || lower(c.w[1]) == "all") {
        g_freezes.clear();
        print("nothing frozen");
        return;
    }
    if (!parse_addr(c.w[1], &addr)) { error("unfreeze <address> | unfreeze all"); return; }
    size_t before = g_freezes.size();
    g_freezes.erase(std::remove_if(g_freezes.begin(), g_freezes.end(), [&](const Freeze& f) { return f.addr == addr; }), g_freezes.end());
    if (before == g_freezes.size()) error(format("%08X is not frozen", addr));
    else print(format("%08X no longer frozen", addr));
}

void cmd_watch(Ctx& c) {
    if (c.w.size() < 2) {
        std::lock_guard lock{ g_mutex };
        if (g_watches.empty()) { print("nothing watched"); return; }
        std::string out;
        for (const Watch& w : g_watches) {
            if (!out.empty()) out += '\n';
            out += format("%08X %s%s", w.addr, w.is_float ? "f" : std::to_string(w.size * 8).c_str(), w.name.empty() ? "" : (" " + w.name).c_str());
        }
        print(out);
        return;
    }
    uint32_t addr;
    if (!parse_addr(c.w[1], &addr)) { error("watch <address> [8|16|32|f] [name]"); return; }
    int size = 4;
    bool is_float = false;
    size_t name_at = 2;
    if (c.w.size() >= 3) {
        if (lower(c.w[2]) == "f" || lower(c.w[2]) == "float") { is_float = true; name_at = 3; }
        else if (int s = parse_size(c.w[2])) { size = s; name_at = 3; }
    }
    if ((addr & (size - 1)) != 0) { error("the address must be aligned to the size"); return; }
    std::lock_guard lock{ g_mutex };
    g_watches.erase(std::remove_if(g_watches.begin(), g_watches.end(), [&](const Watch& w) { return w.addr == addr; }), g_watches.end());
    g_watches.push_back({ addr, size, is_float, join(c.w, name_at) });
    print(format("watching %08X", addr));
}

void cmd_unwatch(Ctx& c) {
    std::lock_guard lock{ g_mutex };
    uint32_t addr;
    if (c.w.size() < 2 || lower(c.w[1]) == "all") { g_watches.clear(); print("nothing watched"); return; }
    if (!parse_addr(c.w[1], &addr)) { error("unwatch <address> | unwatch all"); return; }
    g_watches.erase(std::remove_if(g_watches.begin(), g_watches.end(), [&](const Watch& w) { return w.addr == addr; }), g_watches.end());
    print(format("%08X no longer watched", addr));
}

// log <name> on|off, log list: switches that game code reads through tooie_debug_log_on("TOOIE_SOMETHING"). The
// existing TOOIE_*_LOG variables are read straight from the environment, so none is listed yet; add one here when the
// code that uses it calls tooie_debug_log_on.
struct LogName { const char* name; std::vector<const char*> env; const char* what; };
const std::vector<LogName>& log_names() {
    static const std::vector<LogName> list = {};
    return list;
}

// The switches: the environment at start, then the console.
std::mutex g_log_mutex;
std::map<std::string, bool>& log_switches() {
    static std::map<std::string, bool> m;
    return m;
}

void cmd_log(Ctx& c) {
    if (c.w.size() < 2 || lower(c.w[1]) == "list") {
        std::string out;
        for (const LogName& l : log_names()) {
            if (!out.empty()) out += '\n';
            bool on = tooie_debug_log_on(l.env[0]) != 0;
            out += format("%s %s: %s (%s)", l.name, on ? "on" : "off", l.what, l.env[0]);
        }
        print(out.empty() ? "no log can be switched from here yet" : out + "\nlog <name> on|off");
        return;
    }
    bool on;
    if (c.w.size() < 3 || !parse_bool(c.w[2], &on)) { error("log <name> on|off | log list"); return; }
    std::string want = lower(c.w[1]);
    for (const LogName& l : log_names()) {
        bool match = want == l.name;
        for (const char* e : l.env) match = match || want == lower(e);
        if (!match) continue;
        {
            std::lock_guard lock{ g_log_mutex };
            for (const char* e : l.env) log_switches()[e] = on;
        }
        print(format("%s %s", l.name, on ? "on" : "off"));
        return;
    }
    error("no log called \"" + c.w[1] + "\" (log list)");
}

void cmd_aspect(Ctx& c) {
    double w = 0, h = 0;
    std::string v = lower(c.w.size() >= 2 ? c.w[1] : "");
    size_t colon = v.find_first_of(":x/");
    if (colon == std::string::npos || !parse_double(v.substr(0, colon), &w) || !parse_double(v.substr(colon + 1), &h) || w <= 0 || h <= 0) {
        error("aspect <w:h>, such as 4:3, 16:9 or 21:9");
        return;
    }
    if (window == nullptr) { error("no game window"); return; }
    if (SDL_GetWindowFlags(window) & (SDL_WINDOW_FULLSCREEN | SDL_WINDOW_FULLSCREEN_DESKTOP)) { error("the window is fullscreen; windowed only"); return; }
    int ww, wh;
    SDL_GetWindowSize(window, &ww, &wh);
    int nw = (int)std::lround(wh * w / h);
    SDL_SetWindowSize(window, nw, wh);
    print(format("window %dx%d (%s)", nw, wh, v.c_str()));
}

void cmd_bind(Ctx& c) {
    if (c.w.size() < 2) {
        std::lock_guard lock{ g_mutex };
        std::string out;
        for (const auto& [code, body] : g_binds) {
            if (!out.empty()) out += '\n';
            out += std::string(SDL_GetScancodeName(code)) + ": " + body;
        }
        print(out.empty() ? "no binds" : out);
        return;
    }
    SDL_Scancode code = SDL_GetScancodeFromName(c.w[1].c_str());
    if (code == SDL_SCANCODE_UNKNOWN) { error("no key called \"" + c.w[1] + "\" (SDL key names: F5, K, Keypad 1, ...)"); return; }
    if (code == SDL_SCANCODE_GRAVE || code == SDL_SCANCODE_ESCAPE) { error("that key is the console's or the menu's"); return; }
    std::string body = rest_of(c.line, 2);
    {
        std::lock_guard lock{ g_mutex };
        if (body.empty()) g_binds.erase(code);
        else g_binds[code] = body;
    }
    save_state();
    print(body.empty() ? std::string(SDL_GetScancodeName(code)) + " unbound" : std::string(SDL_GetScancodeName(code)) + ": " + body);
}

void cmd_unbind(Ctx& c) {
    if (c.w.size() < 2) { error("unbind <key>"); return; }
    SDL_Scancode code = SDL_GetScancodeFromName(c.w[1].c_str());
    {
        std::lock_guard lock{ g_mutex };
        g_binds.erase(code);
    }
    save_state();
    print(c.w[1] + " unbound");
}

void cmd_alias(Ctx& c) {
    if (c.w.size() < 2) {
        std::lock_guard lock{ g_mutex };
        std::string out;
        for (const auto& [name, body] : g_aliases) {
            if (!out.empty()) out += '\n';
            out += name + ": " + body;
        }
        print(out.empty() ? "no aliases" : out);
        return;
    }
    std::string name = lower(c.w[1]);
    for (const Command& cmd : commands()) {
        if (name == cmd.name) { error("\"" + name + "\" is a command"); return; }
    }
    std::string body = rest_of(c.line, 2);
    {
        std::lock_guard lock{ g_mutex };
        if (body.empty()) g_aliases.erase(name);
        else g_aliases[name] = body;
    }
    save_state();
    print(body.empty() ? name + " removed" : name + ": " + body);
}

void cmd_exec(Ctx& c) {
    if (c.w.size() < 2) { error("exec <file>"); return; }
    std::filesystem::path path = rest_of(c.line, 1);
    if (path.is_relative() && !std::filesystem::exists(path)) path = recompui::file::get_app_folder_path() / path;
    std::ifstream in{ path };
    if (!in.good()) { error("cannot open " + path.string()); return; }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;
        lines.push_back(line);
    }
    for (auto it = lines.rbegin(); it != lines.rend(); ++it) enqueue_line(*it, c.depth + 1, true);
    print(format("%zu lines from %s", lines.size(), path.string().c_str()));
}

void cmd_echo(Ctx& c) {
    std::string text = rest_of(c.line, 1);
    print(text);
    std::fprintf(stderr, "[Console] ---- %s ----\n", text.c_str()); // a marker in the session log
}

void cmd_clear(Ctx&) {
    std::lock_guard lock{ g_mutex };
    g_lines.clear();
    g_scroll = 0;
    refresh_output();
}

void cmd_close(Ctx&) {
    hide_prompt();
}

// ---------------------------------------------------------------------------------------------------------------
// Pause, time scale, breaks, macros, mods, configs, saves and other tools

// The frame's delta time, which func_800D8FA0 writes before tooie_warp_tick runs (as src/gameplay/menu_pause.cpp
// uses it): everything the game moves by delta time follows it.
constexpr uint32_t kDeltaTime = 0x8012C760;
bool g_paused;
bool g_step_pending;
double g_timescale = 1.0;

void cmd_pause(Ctx&) { g_paused = true; print("paused (resume goes on, step runs one game update)"); }
void cmd_resume(Ctx&) { g_paused = false; print("resumed"); }
void cmd_step(Ctx&) {
    if (!g_paused) { error("not paused (pause first)"); return; }
    g_step_pending = true;
    print("one game update");
}

void cmd_timescale(Ctx& c) {
    double v;
    if (c.w.size() < 2) { print(format("time scale %.2f", g_timescale)); return; }
    if (!parse_double(c.w[1], &v) || v <= 0 || v > 4) { error("timescale <0.05 to 4> (1 is normal)"); return; }
    g_timescale = std::max(v, 0.05);
    print(format("time scale %.2f (game movement only; the frame rate stays)", g_timescale));
}

// Once per game update, after the queue: holds or scales the frame's delta time.
void time_tick(uint8_t* rdram) {
    if (g_paused && !g_step_pending) {
        tooie::rdram::write_float(rdram, kDeltaTime, 1.0e-7f);
        return;
    }
    g_step_pending = false;
    if (g_timescale != 1.0) tooie::rdram::write_float(rdram, kDeltaTime, tooie::rdram::read_float(rdram, kDeltaTime) * (float)g_timescale);
}

// break <address> [value] [8|16|32] [pause] [then <command>]: tells when RAM changes (or takes a value).
struct Break { uint32_t addr; int size; bool has_value; uint32_t value; uint32_t last; bool pause; std::string then; };
std::vector<Break> g_breaks;

void cmd_break(Ctx& c) {
    const char* usage = "break <address> [value] [8|16|32] [pause] [then <commands>] | break list | break clear";
    if (c.w.size() >= 2 && (lower(c.w[1]) == "list" || lower(c.w[1]) == "clear")) {
        std::lock_guard lock{ g_mutex };
        if (lower(c.w[1]) == "clear") { g_breaks.clear(); print("no breaks"); return; }
        std::string out;
        for (const Break& b : g_breaks) out += format("%s%08X %s%s%s", out.empty() ? "" : "\n", b.addr, b.has_value ? ("= " + hex(b.value, b.size)).c_str() : "changes", b.pause ? ", pause" : "", b.then.empty() ? "" : (", then " + b.then).c_str());
        print(out.empty() ? "no breaks" : out);
        return;
    }
    uint32_t addr;
    if (c.w.size() < 2 || !parse_addr(c.w[1], &addr)) { error(usage); return; }
    Break b{ addr, 4, false, 0, 0, false, "" };
    size_t i = 2;
    if (i < c.w.size() && lower(c.w[i]) != "pause" && lower(c.w[i]) != "then") {
        if (!parse_u32(c.w[i], &b.value)) { error(usage); return; }
        b.has_value = true;
        b.size = size_of_value(c.w[i], b.value);
        i++;
    }
    if (i < c.w.size() && parse_size(c.w[i]) != 0) b.size = parse_size(c.w[i++]);
    if (i < c.w.size() && lower(c.w[i]) == "pause") { b.pause = true; i++; }
    if (i < c.w.size() && lower(c.w[i]) == "then") b.then = rest_of(c.line, i + 1);
    else if (i < c.w.size()) { error(usage); return; }
    if ((addr & (b.size - 1)) != 0) { error("the address must be aligned to the size"); return; }
    uint32_t mask = b.size == 4 ? 0xFFFFFFFFu : (1u << (b.size * 8)) - 1;
    b.value &= mask;
    b.last = read_ram(c.rdram, addr, b.size);
    std::lock_guard lock{ g_mutex };
    g_breaks.push_back(b);
    print(format("break at %08X when it %s", addr, b.has_value ? ("is " + hex(b.value, b.size)).c_str() : "changes"));
}

// Once per game update: the breaks that hit print, can pause, and queue their commands. A hit break is removed.
void break_tick(uint8_t* rdram) {
    std::vector<std::string> run;
    std::vector<std::string> hits;
    {
        std::lock_guard lock{ g_mutex };
        for (auto it = g_breaks.begin(); it != g_breaks.end();) {
            uint32_t now = read_ram(rdram, it->addr, it->size);
            bool hit = it->has_value ? now == it->value : now != it->last;
            if (!hit) { it->last = now; ++it; continue; }
            hits.push_back(format("%08X: %s -> %s at game update %llu", it->addr, hex(it->last, it->size).c_str(), hex(now, it->size).c_str(), (unsigned long long)g_frames.load()));
            if (it->pause) g_paused = true;
            if (!it->then.empty()) run.push_back(it->then);
            it = g_breaks.erase(it);
        }
        if (!hits.empty()) g_current = "break";
    }
    for (const std::string& h : hits) print(h);
    for (const std::string& r : run) enqueue_line(r);
}

// if <address> ==|!= <value> [8|16|32] <command>: runs the command only when RAM holds (or does not hold) the value.
void cmd_if(Ctx& c) {
    uint32_t addr, value;
    if (c.w.size() < 5 || !parse_addr(c.w[1], &addr) || (c.w[2] != "==" && c.w[2] != "!=") || !parse_u32(c.w[3], &value)) {
        error("if <address> ==|!= <value> [8|16|32] <commands>");
        return;
    }
    int size = size_of_value(c.w[3], value);
    size_t body_at = 4;
    if (parse_size(c.w[4]) != 0 && c.w.size() >= 6) { size = parse_size(c.w[4]); body_at = 5; }
    if ((addr & (size - 1)) != 0) { error("the address must be aligned to the size"); return; }
    uint32_t mask = size == 4 ? 0xFFFFFFFFu : (1u << (size * 8)) - 1;
    bool equal = read_ram(c.rdram, addr, size) == (value & mask);
    bool go = c.w[2] == "==" ? equal : !equal;
    std::string body = rest_of(c.line, body_at);
    if (go) enqueue_line(body, c.depth + 1, true);
    print(go ? "true: " + body : "false");
}

// findptr <address> [range]: words in RAM that point at the address, or within range bytes after it.
void cmd_findptr(Ctx& c) {
    uint32_t addr, range = 4;
    if (c.w.size() < 2 || !parse_addr(c.w[1], &addr) || (c.w.size() >= 3 && !parse_u32(c.w[2], &range))) { error("findptr <address> [range in bytes, default 4]"); return; }
    std::vector<uint32_t> hits;
    size_t total = 0;
    for (uint32_t a = kRamStart; a + 4 <= kFindEnd; a += 4) {
        uint32_t v = read_ram(c.rdram, a, 4);
        if (v >= addr && v < addr + std::max<uint32_t>(range, 1)) {
            if (hits.size() < 32) hits.push_back(a);
            total++;
        }
    }
    std::string out = format("%zu found", total);
    for (uint32_t a : hits) out += format(" %08X", a);
    if (total > hits.size()) out += " ...";
    print(out);
}

// macro record <name> | macro stop | macro list: the console lines typed or piped in while recording become an
// alias (kept in console.txt) that runs them again.
std::string g_macro_name;
std::vector<std::string> g_macro_lines;
std::string g_last_line;

void save_state();

void cmd_macro(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "";
    if (what == "record" && c.w.size() >= 3) {
        g_macro_name = lower(c.w[2]);
        g_macro_lines.clear();
        print("recording the next commands into " + g_macro_name + " (macro stop ends it)");
        return;
    }
    if (what == "stop") {
        if (g_macro_name.empty()) { error("not recording"); return; }
        std::string body;
        for (const std::string& l : g_macro_lines) body += (body.empty() ? "" : "; ") + l;
        {
            std::lock_guard lock{ g_mutex };
            if (!body.empty()) g_aliases[g_macro_name] = body;
        }
        save_state();
        print(body.empty() ? "nothing recorded" : g_macro_name + ": " + body);
        g_macro_name.clear();
        return;
    }
    error("macro record <name> | macro stop (play it by typing its name)");
}

void cmd_last(Ctx& c) {
    if (g_last_line.empty()) { error("nothing to repeat yet"); return; }
    enqueue_line(g_last_line, c.depth + 1, true);
    print(g_last_line);
}

// mod list | mod on|off <id>: the mods the launcher's Mods menu shows.
void cmd_mod(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "list";
    if (what == "list") {
        std::string out;
        for (const auto& m : recomp::mods::get_all_mod_details("bt")) {
            out += format("%s%s %s (%s, %s)%s", out.empty() ? "" : "\n", recomp::mods::is_mod_enabled(m.mod_id) ? "on " : "off", m.mod_id.c_str(),
                m.display_name.c_str(), m.version.to_string().c_str(), m.runtime_toggleable ? "" : ", needs a restart");
        }
        print(out.empty() ? "no mods" : out);
        return;
    }
    bool on;
    if (c.w.size() < 3 || !parse_bool(what, &on)) { error("mod list | mod on <id> | mod off <id>"); return; }
    std::string id = c.w[2];
    if (!recomp::mods::get_details_for_mod(id).has_value()) { error("no mod with the id " + id + " (mod list)"); return; }
    recomp::mods::enable_mod(id, on);
    print(id + (on ? " on" : " off"));
}

// config export <folder> | config import <folder>: every settings file (*.json in the config folder).
void cmd_config(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "";
    if ((what != "export" && what != "import") || c.w.size() < 3) { error("config export <folder> | config import <folder>"); return; }
    std::filesystem::path other = rest_of(c.line, 2);
    if (other.is_relative()) other = recompui::file::get_app_folder_path() / other;
    std::filesystem::path config = recomp::get_config_path();
    std::filesystem::path from = what == "export" ? config : other;
    std::filesystem::path to = what == "export" ? other : config;
    std::error_code ec;
    std::filesystem::create_directories(to, ec);
    int n = 0;
    for (const auto& entry : std::filesystem::directory_iterator(from, ec)) {
        if (!entry.is_regular_file() || entry.path().extension() != ".json") continue;
        std::filesystem::copy_file(entry.path(), to / entry.path().filename(), std::filesystem::copy_options::overwrite_existing, ec);
        if (!ec) n++;
    }
    if (n == 0) { error("no settings files found in " + from.string()); return; }
    print(format("%d settings files copied to %s", n, to.string().c_str()) + (what == "import" ? "\nRestart the game to use them." : ""));
}

// save backup | save list: copies of the save file in save_backups/ in the config folder (as Save backups makes).
void cmd_save(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "";
    std::filesystem::path root = recomp::get_config_path() / "save_backups";
    std::error_code ec;
    if (what == "backup") {
        std::filesystem::path save = ultramodern::get_save_file_path();
        if (save.empty() || !std::filesystem::exists(save, ec)) { error("no save file yet"); return; }
        std::time_t t = std::time(nullptr);
        char stamp[32];
        std::strftime(stamp, sizeof(stamp), "%Y-%m-%d_%H-%M-%S", std::localtime(&t));
        std::filesystem::path dir = root / (std::string(stamp) + "_console");
        std::filesystem::create_directories(dir, ec);
        std::filesystem::copy_file(save, dir / save.filename(), std::filesystem::copy_options::overwrite_existing, ec);
        if (ec) { error("could not copy the save file: " + ec.message()); return; }
        print("saved a copy to " + dir.string());
        return;
    }
    if (what == "list") {
        std::vector<std::string> names;
        for (const auto& entry : std::filesystem::directory_iterator(root, ec)) {
            if (entry.is_directory()) names.push_back(entry.path().filename().string());
        }
        std::sort(names.begin(), names.end());
        std::string out;
        for (const std::string& n : names) out += (out.empty() ? "" : "\n") + n;
        print(out.empty() ? "no backups" : out);
        return;
    }
    error("save backup | save list (put a backup back by copying it over the save with the game closed)");
}

// profile save <name> | profile load <name> | profile list: every setting's value, kept as set commands.
void cmd_profile(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "";
    std::filesystem::path dir = recompui::file::get_app_folder_path() / "console_profiles";
    std::error_code ec;
    if (what == "list") {
        std::string out;
        for (const auto& entry : std::filesystem::directory_iterator(dir, ec)) out += (out.empty() ? "" : "\n") + entry.path().stem().string();
        print(out.empty() ? "no profiles" : out);
        return;
    }
    if ((what != "save" && what != "load") || c.w.size() < 3) { error("profile save <name> | profile load <name> | profile list"); return; }
    std::filesystem::path file = dir / (squash(c.w[2]) + ".txt");
    if (what == "load") {
        Ctx d = c;
        d.w = { "exec", file.string() };
        d.line = "exec " + file.string();
        cmd_exec(d);
        return;
    }
    std::filesystem::create_directories(dir, ec);
    std::ofstream out{ file };
    if (!out.good()) { error("cannot write " + file.string()); return; }
    out << "# Console settings profile. profile load " << squash(c.w[2]) << " sets these.\n";
    int n = 0;
    for (const SettingRef& r : all_settings()) {
        if (r.debug || r.type() == ConfigOptionType::String) continue;
        std::string v = value_text(r);
        if (v == "?") continue;
        out << "set " << r.full_id() << " " << v << "\n";
        n++;
    }
    print(format("%d settings saved to %s", n, file.string().c_str()));
}

// sweep start | sweep stop: the texture sweep (Texture dump > Sweep all maps), without the menu prompt.
void cmd_sweep(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "";
    if (what == "start") {
        if (!set_setting(tooie::texture_dump_option, "sweepallmaps")) return;
        tooie::texture_sweep::confirm_start();
        print("texture sweep started (about 40 minutes; sweep stop ends it)");
        return;
    }
    if (what == "stop") { set_setting(tooie::texture_dump_option, "off"); return; }
    print(tooie::texture_sweep::sweeping() ? "sweeping" : "not sweeping (sweep start | sweep stop)");
}

void cmd_photo(Ctx&) {
    tooie::photo_mode::request_toggle();
    print(std::string("photo mode ") + (tooie::photo_mode::active() ? "off" : "on") + " (on the next frame)");
}

void cmd_ach(Ctx& c) {
    std::string filter = squash(join(c.w, 1));
    std::string out;
    int unlocked = 0, total = 0;
    for (const auto& a : tooie::achievements::pause_entries()) {
        total++;
        if (a.unlocked) unlocked++;
        if (!filter.empty() && squash(a.name).find(filter) == std::string::npos) continue;
        out += format("\n%s %s (%d points)%s", a.unlocked ? "[x]" : "[ ]", a.name.c_str(), a.points,
            a.goal > 0 && a.count >= 0 ? format(", %d of %d", a.count, a.goal).c_str() : "");
    }
    print(format("%d of %d unlocked", unlocked, total) + out);
}

void cmd_version(Ctx&) {
    print("Banjo Re-Tooie " + recomp::get_project_version().to_string());
}

void cmd_vram(Ctx&) {
    std::string s = tooie::vram_log::summary();
    print(s.empty() ? "no VRAM figures yet" : s);
}

void cmd_gfx(Ctx&) {
    print(format("the last display list used %.1f%% of its buffer", tooie::gfx_budget::last_list_fraction() * 100.0f));
}

// crash test confirm | hang test <seconds>: checks that the crash and hang reports get written.
void cmd_crash(Ctx& c) {
    if (c.w.size() < 3 || lower(c.w[1]) != "test" || lower(c.w[2]) != "confirm") { error("crash test confirm (this really crashes the game)"); return; }
    print("crashing now");
    std::fflush(stdout);
    volatile int* p = nullptr;
    *p = 1;
}

void cmd_hang(Ctx& c) {
    int seconds;
    if (c.w.size() < 3 || lower(c.w[1]) != "test" || !parse_int(c.w[2], &seconds) || seconds < 1 || seconds > 300) { error("hang test <seconds, 1 to 300> (the game thread stops that long)"); return; }
    print(format("holding the game thread for %d seconds", seconds));
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    print("going on");
}

// item [list] | item <name|number> [value|+n|-n]: the game's item counters through its own getter and setter.
struct ItemName { int index; const char* name; };
// Places in the item table the Cheats tab names (src/game/cheats.cpp); the others show by number.
const ItemName kItemNames[] = {
    { 0, "blue eggs" }, { 1, "fire eggs" }, { 2, "ice eggs" }, { 3, "grenade eggs" }, { 4, "clockwork eggs" },
    { 5, "proximity eggs" }, { 6, "red feathers" }, { 7, "gold feathers" }, { 8, "glowbos" }, { 19, "ice keys" },
};
constexpr int kItemCount = 22; // the save keeps 22 counters (func_800D1C78)

std::string item_name(int index) {
    for (const ItemName& n : kItemNames) {
        if (n.index == index) return n.name;
    }
    return format("item %d", index);
}

void cmd_item(Ctx& c) {
    if (c.ctx == nullptr) { error("no game update is running"); return; }
    if (c.w.size() < 2 || lower(c.w[1]) == "list") {
        std::string out;
        for (int i = 0; i < kItemCount; i++) {
            int32_t v = tooie::progress_cheats::get_item(c.rdram, c.ctx, 0x40 + i);
            out += format("%s%d %s: %d", out.empty() ? "" : "\n", i, item_name(i).c_str(), v);
        }
        print(out);
        return;
    }
    // The name may be several words; a last word that is a number (or +n / -n) is the value.
    std::string last = c.w.back();
    bool has_value = c.w.size() >= 3 && (last[0] == '+' || last[0] == '-' || std::isdigit((unsigned char)last[0]));
    std::string query = join(c.w, 1, has_value ? c.w.size() - 1 : c.w.size());
    int index = -1, n;
    if (parse_int(query, &n) && n >= 0 && n < kItemCount) index = n;
    for (const ItemName& in : kItemNames) {
        if (index < 0 && squash(in.name).find(squash(query)) != std::string::npos) index = in.index;
    }
    if (index < 0) { error("no item called \"" + query + "\" (item list)"); return; }
    int32_t item = 0x40 + index;
    int32_t now = tooie::progress_cheats::get_item(c.rdram, c.ctx, item);
    if (!has_value) { print(format("%s: %d", item_name(index).c_str(), now)); return; }
    int value;
    if (!parse_int(last, &value)) { error("item <name> [value | +n | -n]"); return; }
    if (last[0] == '+' || last[0] == '-') value = now + value;
    tooie::progress_cheats::set_item(c.rdram, c.ctx, item, std::max(value, 0));
    print(format("%s: %d -> %d (the game keeps it within the item's limit)", item_name(index).c_str(), now, tooie::progress_cheats::get_item(c.rdram, c.ctx, item)));
}

// sfx <hex id> [volume]: a sound effect on Banjo.
void cmd_sfx(Ctx& c) {
    uint32_t id = 0;
    double volume = 1.0;
    std::string h = c.w.size() >= 2 && c.w[1].size() > 2 && c.w[1][0] == '0' && (c.w[1][1] == 'x' || c.w[1][1] == 'X') ? c.w[1].substr(2) : (c.w.size() >= 2 ? c.w[1] : "");
    char* end = nullptr;
    id = (uint32_t)std::strtoul(h.c_str(), &end, 16);
    if (h.empty() || *end != '\0' || id > 0xFFFF || (c.w.size() >= 3 && (!parse_double(c.w[2], &volume) || volume < 0 || volume > 2))) { error("sfx <sound id in hex> [volume 0 to 2]"); return; }
    if (c.ctx == nullptr) { error("no game update is running"); return; }
    if (!tooie::progress_cheats::play_sound(c.rdram, c.ctx, (int32_t)id, (float)volume)) { error("there is no player yet"); return; }
    print(format("sound 0x%X", id));
}

// invincible on|off: the game's own no-damage flag (0x53C, the Honey King's reward, which src/gameplay/damage_mods.cpp
// reads). It is a save-file flag, so saving keeps it.
bool cmd_flag_set(Ctx& c, int32_t flag, bool on) {
    if (c.ctx == nullptr) { error("no game update is running"); return false; }
    tooie::progress_cheats::set_flag(c.rdram, c.ctx, flag, on);
    return true;
}

void cmd_invincible(Ctx& c) {
    bool on;
    if (c.w.size() < 2 || !parse_bool(c.w[1], &on)) {
        if (c.ctx == nullptr) { error("no game update is running"); return; }
        print(std::string("invincible ") + (tooie::progress_cheats::get_flag(c.rdram, c.ctx, 0x53C) ? "on" : "off"));
        return;
    }
    if (!cmd_flag_set(c, 0x53C, on)) return;
    print(std::string("invincible ") + (on ? "on" : "off") + " (flag 0x53C; saving keeps it)");
}

const std::vector<Command>& commands() {
    static const std::vector<Command> list = {
        { "help", { "?" }, false, "help [command]", "list the commands, or one command's use", cmd_help },
        { "start", {}, false, "start", "press Play in the launcher", cmd_start },
        { "quit", { "exit" }, false, "quit [code]", "exit the program; the exit code is 1 if any command failed, unless given", cmd_quit },
        { "warp", { "go" }, true, "warp <list> <n|name> | warp <name> | warp id <map hex> [exit hex]", "warp like the Warp tab (lists: place map), or to a map id", cmd_warp },
        { "list", { "ls" }, false, "list [list] [filter]", "the warp lists with their numbers", cmd_list },
        { "status", {}, true, "status", "map, game update count, updates per second, warp state", cmd_status },
        { "settings", { "options" }, false, "settings [filter]", "every setting with its id and value", cmd_settings },
        { "get", {}, false, "get <setting>", "a setting's value and what it takes", cmd_get },
        { "set", {}, false, "set <setting> <value>", "change a setting and save it, as the menu does", cmd_set },
        { "toggle", {}, false, "toggle <setting>", "flip on/off, or the next choice", cmd_toggle },
        { "reset", {}, false, "reset <setting>", "a setting back to its default", cmd_reset },
        { "fps", {}, false, "fps [value]", "the Game Frame Rate setting", cmd_fps },
        { "cheat", {}, false, "cheat [name] [on|off]", "list the cheats, or switch one (turns the cheats master switch on); no value flips it", cmd_cheat },
        { "unlock", {}, false, "unlock moves | unlock everything", "the Unlock all moves / Unlock everything cheats", cmd_unlock },
        { "savestate", { "ss" }, true, "savestate save | savestate load", "the Save State / Load State keys (one snapshot, in a level)", cmd_savestate },
        { "spawn", {}, true, "spawn [enemy|number] [count]", "spawn an enemy in front of Banjo (the Enemy Spawner cheat); no argument lists them", cmd_spawn },
        { "flag", {}, true, "flag <hex id> [on|off]", "read or set one of the game's progress flags (the getter and setter the cheats use)", cmd_flag },
        { "pos", {}, true, "pos", "Banjo's position", cmd_pos },
        { "goto", { "tp" }, true, "goto <x> <y> <z>", "move Banjo to a position in this map", cmd_goto },
        { "transform", {}, true, "transform [form]", "the Cheats tab's Transformation row (turns the cheats on)", cmd_transform },
        { "repeat", {}, false, "repeat <n> <command>", "run a command n times", cmd_repeat },
        { "tee", {}, false, "tee <file> | tee off", "copy everything the console prints to a file", cmd_tee },
        { "pause", {}, true, "pause", "stop the game's movement (its delta time), without the pause menu", cmd_pause },
        { "resume", {}, true, "resume", "go on after pause", cmd_resume },
        { "step", {}, true, "step", "one game update while paused", cmd_step },
        { "timescale", { "ff", "slowmo" }, true, "timescale [0.05 to 4]", "scale the game's movement (2 is double speed, 0.5 half)", cmd_timescale },
        { "break", {}, true, "break <address> [value] [8|16|32] [pause] [then <commands>]", "tell when RAM changes or takes a value; can pause or run commands", cmd_break },
        { "if", {}, true, "if <address> ==|!= <value> [8|16|32] <commands>", "run commands only when RAM holds a value", cmd_if },
        { "findptr", {}, true, "findptr <address> [range]", "find the words in RAM that point at an address", cmd_findptr },
        { "macro", {}, false, "macro record <name> | macro stop", "record the next commands as an alias", cmd_macro },
        { "last", { "!!" }, false, "last", "run the last command line again", cmd_last },
        { "mod", { "mods" }, false, "mod list | mod on|off <id>", "the mods in the Mods menu", cmd_mod },
        { "config", {}, false, "config export|import <folder>", "copy every settings file out or in (import needs a restart)", cmd_config },
        { "save", {}, false, "save backup | save list", "copy the save file into save_backups", cmd_save },
        { "profile", {}, false, "profile save|load <name> | profile list", "keep every setting's value under a name and set them again", cmd_profile },
        { "sweep", {}, true, "sweep [start|stop]", "the texture sweep (Texture dump > Sweep all maps)", cmd_sweep },
        { "photo", {}, true, "photo", "photo mode on or off, as its key", cmd_photo },
        { "ach", { "achievements" }, false, "ach [filter]", "the achievements and which are unlocked", cmd_ach },
        { "item", { "give", "items" }, true, "item [list] | item <name|n> [value|+n|-n]", "read or set an item counter (eggs, feathers, Glowbos...) through the game's own functions", cmd_item },
        { "sfx", {}, true, "sfx <hex id> [volume]", "play a sound effect on Banjo (the game's func_8009DE38)", cmd_sfx },
        { "invincible", { "god" }, true, "invincible [on|off]", "the game's own no-damage flag (0x53C; saving keeps it)", cmd_invincible },
        { "version", {}, false, "version", "the build's version", cmd_version },
        { "vram", {}, false, "vram", "the VRAM figures the VRAM log keeps", cmd_vram },
        { "gfx", { "gfxbudget" }, true, "gfx", "how full the last display list was", cmd_gfx },
        { "crash", {}, false, "crash test confirm", "crash the game on purpose, to check the crash report", cmd_crash },
        { "hang", {}, true, "hang test <seconds>", "hold the game thread, to check the hang watchdog", cmd_hang },
        { "diff", {}, true, "diff snapshot | diff [compare] [n]", "keep RAM, then list the words that changed since", cmd_diff },
        { "perf", {}, true, "perf <seconds>", "time the game updates and write perf-<time>.csv", cmd_perf },
        { "sysinfo", {}, false, "sysinfo", "platform, CPUs, RAM, video driver and window size (for bug reports)", cmd_sysinfo },
        { "dev", {}, false, "dev [on|off]", "make dev.txt next to the exe (shows every hidden tab after a restart); off removes it", cmd_dev },
        { "screenshot", { "shot" }, true, "screenshot", "save the next frame as a PNG, as F12 does", cmd_screenshot },
        { "press", {}, true, "press <buttons> [stick <x> <y>] [frames]", "hold controller 1's buttons (a+b) and stick (-80..80), for n frames or until release", cmd_press },
        { "release", {}, false, "release", "let go of what press holds", cmd_release },
        { "wait", {}, false, "wait <frames|n ms|n s|map <hex>|until <addr> <value>>", "hold the next commands (frames are game updates; map and until wait for a state)", cmd_wait },
        { "peek", {}, true, "peek <address> [bytes]", "read RAM (hex address)", cmd_peek },
        { "poke", {}, true, "poke <address> <value> [8|16|32]", "write RAM", cmd_poke },
        { "expect", {}, true, "expect <address> <value> [8|16|32]", "ERR when RAM does not hold the value", cmd_expect },
        { "find", {}, true, "find <value> [8|16|32] [from] [to]", "search RAM for a value", cmd_find },
        { "freeze", {}, true, "freeze <address> <value> [8|16|32]", "write a value every game update", cmd_freeze },
        { "unfreeze", {}, false, "unfreeze <address> | unfreeze all", "stop a freeze", cmd_unfreeze },
        { "watch", {}, false, "watch [address] [8|16|32|f] [name]", "show a RAM value live at the top right", cmd_watch },
        { "unwatch", {}, false, "unwatch <address> | unwatch all", "stop watching", cmd_unwatch },
        { "log", {}, false, "log list | log <name> on|off", "switch a debug log", cmd_log },
        { "aspect", {}, false, "aspect <w:h>", "resize the window to 4:3, 16:9, 21:9 or any shape", cmd_aspect },
        { "bind", {}, false, "bind [key] [commands]", "run commands on a key (kept in console.txt)", cmd_bind },
        { "unbind", {}, false, "unbind <key>", "remove a bind", cmd_unbind },
        { "alias", {}, false, "alias [name] [commands]", "one word for several commands (kept in console.txt)", cmd_alias },
        { "exec", {}, false, "exec <file>", "run a file of commands", cmd_exec },
        { "echo", {}, false, "echo <text>", "print text and mark the session log", cmd_echo },
        { "clear", { "cls" }, false, "clear", "clear the console", cmd_clear },
        { "close", {}, false, "close", "hide the console (` too)", cmd_close },
    };
    return list;
}

const Command* find_command(const std::string& name) {
    std::string n = lower(name);
    for (const Command& cmd : commands()) {
        if (n == cmd.name) return &cmd;
        for (const char* a : cmd.aliases) {
            if (n == a) return &cmd;
        }
    }
    return nullptr;
}

// One-word shortcuts the console knows without an alias: the name, then the command it runs with the rest of the
// line added after it. Your own aliases win over these.
struct Shortcut { const char* name; const char* body; };
const Shortcut kShortcuts[] = {
    { "noclip", "cheat noclip" }, { "levitate", "cheat infinite_jumps" }, { "fly", "cheat fly_anywhere" }, { "onehit", "cheat one_hit" },
    { "msaa", "set msaa_option" }, { "res", "set res_option" }, { "hdshadows", "set hd_shadows" }, { "mirror", "set mirror_mode" },
    { "daynight", "set day_night" }, { "sunshadows", "set sun_shadows" }, { "upscale", "set texture_upscale" },
    { "interp", "set force_scene_interpolation" }, { "testroom", "warp place test room" },
    { "freecam", "set free_camera" }, { "boss", "set boss_rush" }, { "cutscene", "set cutscene_skip_all" },
    { "dive", "set dive" }, { "trot", "set talon_trot" }, { "fineaim", "set fine_aim" }, { "music", "set music_player" },
    { "mem", "set more_game_memory" }, { "char", "transform" },
};

std::string shortcut_body(const std::string& name, const std::string& line) {
    for (const Shortcut& s : kShortcuts) {
        if (name != s.name) continue;
        std::string rest = rest_of(line, 1);
        return std::string(s.body) + (rest.empty() ? "" : " " + rest);
    }
    return "";
}

// Runs the front of the queue while nothing holds it. rdram is null before the game starts: then a command that
// needs the game waits at the front until the game thread takes over.
void pump(uint8_t* rdram, recomp_context* hook_ctx) {
    static std::recursive_mutex pump_mutex;
    std::unique_lock pl{ pump_mutex, std::try_to_lock };
    if (!pl.owns_lock()) return;
    for (int guard = 0; guard < 256; guard++) {
        if (holding()) return;
        Entry e;
        {
            std::lock_guard lock{ g_mutex };
            if (g_queue.empty()) {
                if (g_ran_any.exchange(false)) {
                    // Everything queued has finished: for scripts on stdout and in the log, not on screen.
                    std::fprintf(stdout, "[console] IDLE\n");
                    std::fflush(stdout);
                }
                return;
            }
            e = g_queue.front();
        }
        g_ran_any = true;
        std::vector<std::string> w = split(e.text);
        if (w.empty()) {
            std::lock_guard lock{ g_mutex };
            g_queue.pop_front();
            continue;
        }
        const Command* cmd = find_command(w[0]);
        if (cmd != nullptr && cmd->needs_game && rdram == nullptr) return; // after `start`
        {
            std::lock_guard lock{ g_mutex };
            g_queue.pop_front();
            g_current = cmd != nullptr ? cmd->name : lower(w[0]);
        }
        if (cmd == nullptr) {
            std::string body;
            {
                std::lock_guard lock{ g_mutex };
                auto it = g_aliases.find(lower(w[0]));
                if (it != g_aliases.end()) body = it->second;
            }
            if (body.empty()) body = shortcut_body(lower(w[0]), e.text);
            if (body.empty()) { error("unknown command \"" + w[0] + "\" (help)"); continue; }
            if (e.depth > 8) { error("aliases nest too deep"); continue; }
            enqueue_line(body, e.depth + 1, true);
            continue;
        }
        if (e.depth == 0 && cmd->name != std::string("last") && cmd->name != std::string("macro")) {
            g_last_line = e.text;
            if (!g_macro_name.empty()) g_macro_lines.push_back(e.text);
        }
        Ctx c{ rdram, hook_ctx, w, e.text, e.depth };
        try {
            cmd->run(c);
        } catch (const std::exception& ex) {
            error(ex.what());
        }
    }
}

// ---------------------------------------------------------------------------------------------------------------
// The prompt

void create_ui() {
    recompui::ContextId prev = recompui::try_close_current_context();
    g_context = recompui::create_context();
    g_context.open();
    g_context.set_captures_input(true);
    g_context.set_captures_mouse(true);

    recompui::Element* panel = g_context.create_element<recompui::Element>(g_context.get_root_element());
    panel->set_position(recompui::Position::Absolute);
    panel->set_left(0);
    panel->set_right(0);
    panel->set_bottom(0);
    panel->set_display(recompui::Display::Flex);
    panel->set_flex_direction(recompui::FlexDirection::Column);
    panel->set_gap(2);
    panel->set_padding_left(16);
    panel->set_padding_right(16);
    panel->set_padding_top(10);
    panel->set_padding_bottom(12);
    panel->set_background_color(recompui::theme::color::ModalOverlay);
    panel->set_border_width(recompui::theme::border::width);
    panel->set_border_color(recompui::theme::color::WhiteA20);

    for (int i = 0; i < kShownLines; i++) {
        g_shown[i] = g_context.create_element<recompui::Label>(panel, "", recompui::LabelStyle::Small);
        g_shown[i]->set_height(22);
        g_shown[i]->set_overflow(recompui::Overflow::Hidden);
    }

    recompui::Element* row = g_context.create_element<recompui::Element>(panel);
    row->set_display(recompui::Display::Flex);
    row->set_flex_direction(recompui::FlexDirection::Row);
    row->set_align_items(recompui::AlignItems::Center);
    row->set_gap(8);
    row->set_margin_top(6);
    g_context.create_element<recompui::Label>(row, ">", recompui::LabelStyle::Normal);
    g_input = g_context.create_element<recompui::TextInput>(row);
    g_input->set_flex_grow(1.0f);
    g_input->set_as_primary_focus(true);
    g_input->add_submit_callback([](const std::string& typed) {
        std::string text = typed; // a copy: typed is the input's own text, which set_text clears
        g_input->set_text("");
        // The console key's own character, if it reached the prompt, is not part of the command.
        std::string line;
        for (char ch : text) {
            if (ch != '`' && ch != '~') line += ch;
        }
        line = trim(line);
        if (line.empty()) return;
        {
            std::lock_guard lock{ g_mutex };
            g_lines.push_back("> " + line);
            if (g_history.empty() || g_history.back() != line) g_history.push_back(line);
            if (g_history.size() > kKeptHistory) g_history.erase(g_history.begin());
            g_history_pos = g_history.size();
        }
        refresh_output();
        enqueue_line(line);
    });

    g_context.close();
    if (prev != recompui::ContextId::null()) prev.open();
}

void open_prompt() {
    if (g_context == recompui::ContextId::null()) {
        create_ui();
        std::lock_guard lock{ g_mutex };
        g_lines.push_back("Banjo Re-Tooie console. help lists the commands; ` closes it.");
    }
    recompui::show_context(g_context, "");
    with_context(g_context, [] {
        g_input->set_text("");
        g_input->focus();
    });
    refresh_output();
    g_open = true;
}

void history_move(int dir) {
    std::string text;
    {
        std::lock_guard lock{ g_mutex };
        if (g_history.empty()) return;
        if (dir < 0 && g_history_pos > 0) g_history_pos--;
        else if (dir > 0 && g_history_pos < g_history.size()) g_history_pos++;
        text = g_history_pos < g_history.size() ? g_history[g_history_pos] : std::string();
    }
    with_context(g_context, [&] { g_input->set_text(text); });
}

void scroll(int lines) {
    {
        std::lock_guard lock{ g_mutex };
        int max = std::max(0, (int)g_lines.size() - kShownLines);
        g_scroll = std::clamp(g_scroll + lines, 0, max);
    }
    refresh_output();
}

// The watch panel: one line per watched address at the top right, updated every few frames.
void update_watch_panel(uint8_t* rdram) {
    std::vector<std::string> lines;
    {
        std::lock_guard lock{ g_mutex };
        {
            for (const Watch& w : g_watches) {
                std::string label = w.name.empty() ? format("%08X", w.addr) : w.name;
                uint32_t v = read_ram(rdram, w.addr, w.is_float ? 4 : w.size);
                if (w.is_float) {
                    float f;
                    std::memcpy(&f, &v, 4);
                    lines.push_back(format("%s: %.4f", label.c_str(), f));
                } else {
                    int32_t sv = w.size == 1 ? (int8_t)v : w.size == 2 ? (int16_t)v : (int32_t)v;
                    lines.push_back(format("%s: %s (%d)", label.c_str(), hex(v, w.size).c_str(), sv));
                }
            }
        }
    }
    if (lines.empty()) {
        if (g_watch_shown) {
            recompui::hide_context(g_watch_context);
            g_watch_shown = false;
        }
        return;
    }
    if (g_watch_context == recompui::ContextId::null()) {
        recompui::ContextId prev = recompui::try_close_current_context();
        g_watch_context = recompui::create_context();
        g_watch_context.open();
        g_watch_context.set_captures_input(false);
        g_watch_context.set_captures_mouse(false);
        g_watch_box = g_watch_context.create_element<recompui::Element>(g_watch_context.get_root_element());
        g_watch_box->set_position(recompui::Position::Absolute);
        g_watch_box->set_top(12);
        g_watch_box->set_right(12);
        g_watch_box->set_display(recompui::Display::Flex);
        g_watch_box->set_flex_direction(recompui::FlexDirection::Column);
        g_watch_box->set_padding_left(10);
        g_watch_box->set_padding_right(10);
        g_watch_box->set_padding_top(4);
        g_watch_box->set_padding_bottom(4);
        g_watch_box->set_border_radius(recompui::theme::border::radius_sm);
        g_watch_box->set_background_color(recompui::theme::color::ModalOverlay);
        g_watch_context.close();
        if (prev != recompui::ContextId::null()) prev.open();
    }
    with_context(g_watch_context, [&] {
        while (g_watch_labels.size() < lines.size()) {
            g_watch_labels.push_back(g_watch_context.create_element<recompui::Label>(g_watch_box, "", recompui::LabelStyle::Small));
        }
        for (size_t i = 0; i < g_watch_labels.size(); i++) {
            g_watch_labels[i]->set_display(i < lines.size() ? recompui::Display::Block : recompui::Display::None);
            if (i < lines.size()) g_watch_labels[i]->set_text(lines[i]);
        }
    });
    if (!g_watch_shown) {
        recompui::show_context(g_watch_context, "");
        g_watch_shown = true;
    }
}

// Key presses, caught as SDL events when they happen (a quick tap can fall between two frames at a low frame rate, so
// the keyboard state alone could miss it) and taken on the next frame. Keys are scancodes: their place on the keyboard.
std::atomic<uint64_t> g_key_presses[SDL_NUM_SCANCODES / 64 + 1];

int SDLCALL key_watch(void*, SDL_Event* event) {
    if (event->type == SDL_KEYDOWN) {
        int code = event->key.keysym.scancode;
        bool repeat = event->key.repeat != 0;
        // Held Up / Down / Page keys repeat in the prompt; the console key and binds don't.
        bool repeats = code == SDL_SCANCODE_UP || code == SDL_SCANCODE_DOWN || code == SDL_SCANCODE_PAGEUP || code == SDL_SCANCODE_PAGEDOWN;
        if (code > 0 && code < SDL_NUM_SCANCODES && (!repeat || repeats)) {
            g_key_presses[code / 64].fetch_or(1ull << (code % 64));
        }
    }
    return 1;
}

bool take_press(int code) {
    uint64_t bit = 1ull << (code % 64);
    return (g_key_presses[code / 64].fetch_and(~bit) & bit) != 0;
}

// Tab in the prompt: completes the first word to the one command (or alias) it starts, or lists the choices.
void complete_input() {
    std::string text = g_input->get_text();
    if (text.empty() || text.find(' ') != std::string::npos) return;
    std::string start = lower(text);
    std::vector<std::string> hits;
    for (const Command& cmd : commands()) {
        if (std::string(cmd.name).rfind(start, 0) == 0) hits.push_back(cmd.name);
    }
    {
        std::lock_guard lock{ g_mutex };
        for (const auto& [name, body] : g_aliases) {
            if (name.rfind(start, 0) == 0) hits.push_back(name);
        }
    }
    if (hits.size() == 1) {
        std::string done = hits[0] + " ";
        with_context(g_context, [&] { g_input->set_text(done); });
    } else if (hits.size() > 1) {
        std::string out;
        for (const std::string& h : hits) out += (out.empty() ? "" : " ") + h;
        {
            std::lock_guard lock{ g_mutex };
            g_lines.push_back(out);
        }
        refresh_output();
    }
}

void poll_keys() {
    static bool watching = false;
    if (!watching) {
        SDL_AddEventWatch(key_watch, nullptr);
        watching = true;
        return;
    }
    bool console_key = take_press(SDL_SCANCODE_GRAVE);
    bool up = take_press(SDL_SCANCODE_UP), down = take_press(SDL_SCANCODE_DOWN);
    bool tab = take_press(SDL_SCANCODE_TAB);
    bool page_up = take_press(SDL_SCANCODE_PAGEUP), page_down = take_press(SDL_SCANCODE_PAGEDOWN);

    bool menu_open = recompui::is_context_shown(recompui::config::get_config_context_id());
    // The settings menu (Esc) goes over everything: the console makes way for it.
    if (g_open && (menu_open || !recompui::is_context_shown(g_context))) {
        if (recompui::is_context_shown(g_context)) recompui::hide_context(g_context);
        g_open = false;
    }

    if (console_key) {
        if (g_open) hide_prompt();
        else if (!menu_open) open_prompt();
        return;
    }
    if (g_open) {
        for (auto& bits : g_key_presses) bits.store(0); // typing in the prompt runs no binds
        if (tab) complete_input();
        if (up) history_move(-1);
        if (down) history_move(1);
        if (page_up) scroll(kShownLines - 1);
        if (page_down) scroll(-(kShownLines - 1));
        return;
    }

    // Binds: only while no menu or panel takes the keyboard.
    std::vector<std::string> run;
    {
        std::lock_guard lock{ g_mutex };
        bool free = !recompui::is_context_capturing_input();
        for (const auto& [code, body] : g_binds) {
            if (take_press(code) && free) run.push_back(body);
        }
    }
    for (const std::string& body : run) enqueue_line(body);
}

// stdin: one command per line, until it ends.
void stdin_thread() {
    char buf[4096];
    while (std::fgets(buf, sizeof(buf), stdin) != nullptr) {
        std::string line = trim(buf);
        if (line.empty() || line[0] == '#') continue;
        enqueue_line(line);
    }
}

// Before the game starts, the queue is run here (start, settings, quit, waits in ms).
void pregame_thread() {
    // Commands start once the launcher is on screen (or the game has started some other way).
    while (!ultramodern::is_game_started() && !recompui::is_context_shown(recompui::get_launcher_context_id())) {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    if (!ultramodern::is_game_started()) announce("READY launcher");
    int ticks = 0;
    while (!ultramodern::is_game_started()) {
        pump(nullptr, nullptr);
        if (ticks++ % 50 == 0) write_state_file(nullptr, -1);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}
} // namespace

// Program start (src/main/main.cpp): the binds and aliases, TOOIE_CONSOLE, --exec, and the stdin reader.
void tooie::console::start(int argc, char** argv) {
    load_state();
    for (int i = 1; i + 1 < argc; i++) {
        if (std::strcmp(argv[i], "--exec") == 0) enqueue_line(std::string("exec ") + argv[i + 1]);
    }
    if (const char* env = std::getenv("TOOIE_CONSOLE")) enqueue_line(env);
    std::thread(stdin_thread).detach();
    std::thread(pregame_thread).detach();
}

int tooie::console::exit_code() {
    int code = g_exit_code.load();
    return code < 0 ? 0 : code;
}

// Once per game update, from tooie_warp_tick (src/debug/warp.cpp), on the game thread before the update's own logic.
void tooie::console::frame(uint8_t* rdram, recomp_context* ctx) {
    g_rdram = rdram;
    uint64_t frame = ++g_frames;
    if (frame == 1) announce("READY game");
    {
        std::lock_guard lock{ g_mutex };
        Clock::time_point now = Clock::now();
        g_frame_times.push_back(now);
        while (g_frame_times.size() > 2 && now - g_frame_times.front() > std::chrono::seconds(1)) g_frame_times.pop_front();
    }
    {
        std::lock_guard lock{ g_input_mutex };
        if (g_press_frames > 0 && --g_press_frames == 0) {
            g_press_buttons = 0;
            g_press_stick = false;
        }
    }
    {
        std::lock_guard lock{ g_mutex };
        for (const Freeze& f : g_freezes) write_ram(rdram, f.addr, f.value, f.size);
    }
    perf_tick();
    break_tick(rdram);
    poll_keys();
    pump(rdram, ctx);
    time_tick(rdram);
    if (frame % 6 == 0) update_watch_panel(rdram);
    {
        static Clock::time_point last_state;
        Clock::time_point now = Clock::now();
        if (now - last_state > std::chrono::seconds(1)) {
            last_state = now;
            write_state_file(rdram, (int32_t)tooie::debug::current_map(rdram));
        }
    }
}

// Debug logs: the environment at start, then the console's log command.
extern "C" int tooie_debug_log_on(const char* env_name) {
    std::lock_guard lock{ g_log_mutex };
    auto& m = log_switches();
    auto it = m.find(env_name);
    if (it == m.end()) it = m.emplace(env_name, std::getenv(env_name) != nullptr).first;
    return it->second ? 1 : 0;
}

// Controller input (tooie::debug::get_n64_input): a press takes over controller 1's buttons and stick.
bool tooie::console::apply_input(int controller, uint16_t* buttons, float* x, float* y, bool got) {
    if (controller != 0) return got;
    std::lock_guard lock{ g_input_mutex };
    if (g_press_frames != 0) {
        *buttons = (got ? *buttons : 0) | g_press_buttons;
        if (g_press_stick) {
            *x = g_press_x / 80.0f;
            *y = g_press_y / 80.0f;
        } else if (!got) {
            *x = *y = 0.0f;
        }
        got = true;
    }
    return got;
}
