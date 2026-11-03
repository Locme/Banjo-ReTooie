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
// the like) run on a small thread of their own. `wait` holds the queue until it is done, and so do `load` and `walkto`,
// which drive controller 1 once per game update until they get where they are going (drive_tick).
//
// The warps go through the Warp tab's own code (src/game/level_warp.cpp) and src/debug/warp.cpp, and the settings
// through the same config calls as the settings menu, so nothing here is a second copy of a feature.

#include "tooie_console.h"
#include "tooie_cheats.h"
#include "tooie_path_text.h"
#include "tooie_debug.h"
#include "tooie_enemy_spawner.h"
#include "tooie_player_cheats.h"
#include "tooie_progress_cheats.h"
#include "tooie_rdram.h"
#include "tooie_game.h"
#include "tooie_game_frame_rate.h"
#include "tooie_free_camera.h"
#include "tooie_level_warp.h"
#include "tooie_mirror_mode.h"
#include "tooie_save_state.h"
#include "tooie_screenshot.h"
#include "tooie_frame_overlay.h"
#include "tooie_achievements.h"
#include "tooie_gfx_budget.h"
#include "tooie_photo_mode.h"
#include "tooie_texture_sweep.h"
#include "tooie_vram_log.h"
#include "librecomp/mods.hpp"
#include "recomp.h"
#include "recompui/recompui.h"
#include "recompinput/input_state.h"
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
extern "C" void func_800D035C(uint8_t* rdram, recomp_context* ctx); // RecompiledFuncs: a collectible's count (1 Jiggies)

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

// A path from typed or piped text, which is UTF-8. A path made from a plain std::string reads it in the Windows ANSI
// code page, which garbles a name outside it.
std::filesystem::path typed_path(const std::string& text) {
    return std::filesystem::path(std::u8string(text.begin(), text.end()));
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
int64_t g_press_frames;                   // -1: until release (or g_press_until); 0: nothing held
Clock::time_point g_press_until;          // a press timed in ms or s ends here (epoch: not timed)

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

// Play in the launcher (start, load). False, with the error printed, when no ROM has been loaded yet.
bool start_game() {
    std::u8string id = u8"bt.n64.us.1.0"; // supported_games[0] in src/main/main.cpp
    if (!recomp::is_rom_valid(id)) { error("no Banjo-Tooie ROM is loaded yet (load it once in the launcher)"); return false; }
    recompui::update_game_mod_id("bt");
    recomp::start_game(id, {});
    recompui::hide_all_contexts();
    print("starting the game (the launcher's Play option also sets the picture preset; start does not)");
    return true;
}

void cmd_start(Ctx&) {
    if (ultramodern::is_game_started()) { print("the game is already running"); return; }
    start_game();
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
    std::filesystem::path path = typed_path(rest_of(c.line, 1));
    if (path.is_relative()) path = recompui::file::get_app_folder_path() / path;
    if (g_tee != nullptr) std::fclose(g_tee);
    g_tee = tooie::open_path(path, "a");
    if (g_tee == nullptr) { error("cannot write " + tooie::path_text(path)); return; }
    print("copying the output to " + tooie::path_text(path));
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

void cmd_costcheck(Ctx&) {
    tooie::frame_overlay::toggle_cost_check();
    print("Effect Cost Check toggled: each effect that is on is turned off in turn for a few seconds; the list goes to the overlay and benchmarks/effect_cost_<date>.txt");
}

void cmd_burst(Ctx& c) {
    if (c.w.size() != 2 || (c.w[1] != "start" && c.w[1] != "stop")) { error("burst start | burst stop"); return; }
    if (c.w[1] == "start") {
        tooie::screenshot::burst_start();
        print("burst on: every frame is kept (the last 150, shrunk 4x) until burst stop");
    } else {
        tooie::screenshot::burst_stop();
        print("burst off: the frames go to screenshots/burst-<stamp>/ (the log names the folder)");
    }
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
        sorted.size(), avg, 1000.0 / avg, p99, sorted.back(), tooie::path_text(path).c_str()));
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

// What controller 1 is held at (press, load, walkto): for `frames` game updates (-1 until release), or until `until`
// when it is set.
void hold(uint16_t buttons, bool stick, int x, int y, int64_t frames, Clock::time_point until = {}) {
    std::lock_guard lock{ g_input_mutex };
    g_press_buttons = buttons;
    g_press_stick = stick;
    g_press_x = (int8_t)std::clamp(x, -80, 80);
    g_press_y = (int8_t)std::clamp(y, -80, 80);
    g_press_frames = frames;
    g_press_until = until;
}

// Lets go of a press timed in ms or s once its time is up (g_input_mutex held).
void end_timed_press() {
    if (g_press_until == Clock::time_point{} || Clock::now() < g_press_until) return;
    g_press_until = Clock::time_point{};
    g_press_frames = 0;
    g_press_buttons = 0;
    g_press_stick = false;
}

// A press's length: game updates ("30"), or time ("200ms", "1.5s", up to an hour). Time is counted on the clock, so a
// high frame rate does not shorten it (at 500 updates a second, 5 updates are 10 ms, which menus miss).
bool parse_length(const std::string& s, int* frames, double* seconds) {
    std::string v = lower(s);
    double n;
    *seconds = 0;
    if (v.size() > 2 && v.substr(v.size() - 2) == "ms" && parse_double(v.substr(0, v.size() - 2), &n) && n > 0 && n <= 3.6e6) { *seconds = n / 1000.0; return true; }
    if (v.size() > 1 && v.back() == 's' && parse_double(v.substr(0, v.size() - 1), &n) && n > 0 && n <= 3600) { *seconds = n; return true; }
    return parse_int(v, frames) && *frames >= 1;
}

void cmd_press(Ctx& c) {
    // press <buttons> [length] | press stick <x> <y> [length] | press <buttons> stick <x> <y> [length]
    uint16_t buttons = 0;
    bool stick = false;
    int x = 0, y = 0;
    size_t i = 1;
    if (i < c.w.size() && lower(c.w[i]) != "stick") {
        if (!parse_buttons(c.w[i], &buttons)) { error("unknown button in \"" + c.w[i] + "\" (a b z start l r up down left right cup cdown cleft cright)"); return; }
        i++;
    }
    if (i < c.w.size() && lower(c.w[i]) == "stick") {
        if (i + 2 >= c.w.size() || !parse_int(c.w[i + 1], &x) || !parse_int(c.w[i + 2], &y)) { error("press stick <x> <y> [frames|n ms|n s], x and y from -80 to 80"); return; }
        stick = true;
        i += 3;
    }
    int frames = -1;
    double seconds = 0;
    if (i < c.w.size() && !parse_length(c.w[i], &frames, &seconds)) { error("press <buttons> [frames|n ms|n s]"); return; }
    if (buttons == 0 && !stick) { error("press <buttons> [frames|n ms|n s] | press stick <x> <y> [frames|n ms|n s]"); return; }
    if (seconds > 0) {
        hold(buttons, stick, x, y, -1, Clock::now() + std::chrono::microseconds((int64_t)(seconds * 1e6)));
        print(format("held for %.0f ms", seconds * 1000.0));
        return;
    }
    hold(buttons, stick, x, y, frames);
    print(frames < 0 ? "held until release" : format("held for %d frames", frames));
}

void cmd_release(Ctx&) {
    hold(0, false, 0, 0, 0);
    print("released");
}

// mouse move: motion handed to recompinput::add_mouse_deltas, where the window's own mouse motion goes (RecompFrontend
// input_events.cpp), so Mouse Sensitivity, mouse aim (src/input/motion_aim.cpp) and the free camera see it as real
// motion. Spread over its length in step with the clock, a share each game update (mouse_tick); with no length, all at once.
struct MouseMove {
    bool on = false;
    double dx = 0, dy = 0;          // still to come, in pixels
    Clock::time_point last{}, until{};
};
MouseMove g_mouse;
std::mutex g_mouse_mutex;

void mouse_tick() {
    std::lock_guard lock{ g_mouse_mutex };
    if (!g_mouse.on) return;
    Clock::time_point now = Clock::now();
    double share = 1.0;
    if (now < g_mouse.until) {
        double left = std::chrono::duration<double>(g_mouse.until - now).count();
        double step = std::chrono::duration<double>(now - g_mouse.last).count();
        share = std::clamp(step / (left + step), 0.0, 1.0);
    }
    g_mouse.last = now;
    double x = g_mouse.dx * share, y = g_mouse.dy * share;
    g_mouse.dx -= x;
    g_mouse.dy -= y;
    recompinput::add_mouse_deltas((float)x, (float)y);
    if (share >= 1.0) g_mouse.on = false;
}

void cmd_mouse(Ctx& c) {
    const char* usage = "mouse move <dx> <dy> [n ms|n s] | mouse stop";
    if (c.w.size() >= 2 && lower(c.w[1]) == "stop") {
        std::lock_guard lock{ g_mouse_mutex };
        g_mouse = MouseMove{};
        print("mouse stopped");
        return;
    }
    double dx = 0, dy = 0;
    if (c.w.size() < 4 || lower(c.w[1]) != "move" || !parse_double(c.w[2], &dx) || !parse_double(c.w[3], &dy)) { error(usage); return; }
    int frames = -1;
    double seconds = 0;
    if (c.w.size() >= 5 && (!parse_length(c.w[4], &frames, &seconds) || seconds <= 0)) { error("mouse move <dx> <dy> [n ms|n s]: the length is a time"); return; }
    {
        std::lock_guard lock{ g_mouse_mutex };
        g_mouse.on = true;
        g_mouse.dx = dx;
        g_mouse.dy = dy;
        g_mouse.last = Clock::now();
        g_mouse.until = seconds > 0 ? g_mouse.last + std::chrono::microseconds((int64_t)(seconds * 1e6)) : g_mouse.last;
    }
    if (seconds <= 0) mouse_tick();
    print(seconds > 0 ? format("moving the mouse %.0f, %.0f over %.0f ms", dx, dy, seconds * 1000.0) : format("moved the mouse %.0f, %.0f", dx, dy));
}

bool in_control(uint8_t* rdram); // below

void cmd_wait(Ctx& c) {
    const char* usage = "wait <frames> | wait <n>ms | wait <n>s | wait save [timeout s] | wait control [timeout s] | wait map <map hex> [timeout s] | wait until <address> <value> [8|16|32] [timeout s]";
    if (c.w.size() < 2) { error(usage); return; }
    std::string v = lower(c.w[1]);
    if (v == "control") {
        // wait control [timeout s]: until the player has Banjo again (no scene, talk, map change or scripted walk), and
        // has kept him for half a second, since a scene can hand back control for a moment between its shots.
        double timeout = 60;
        if (c.w.size() >= 3 && !parse_double(c.w[2], &timeout)) { error(usage); return; }
        if (!ultramodern::is_game_started()) { error("wait control needs the game running"); return; }
        Clock::time_point since{};
        g_wait_cond = [since]() mutable {
            if (g_rdram == nullptr || !in_control(g_rdram)) { since = Clock::time_point{}; return false; }
            if (since == Clock::time_point{}) since = Clock::now();
            return Clock::now() - since >= std::chrono::milliseconds(500);
        };
        g_wait_cond_deadline = Clock::now() + std::chrono::microseconds((int64_t)(timeout * 1e6));
        print("waiting for the player to have control");
        return;
    }
    if (v == "save") {
        // wait save [timeout s]: until a save file is loaded (what warp needs), for autoexec and scenarios.
        double timeout = 600;
        if (c.w.size() >= 3 && !parse_double(c.w[2], &timeout)) { error(usage); return; }
        g_wait_cond = [] { return ultramodern::is_game_started() && tooie::debug::can_warp(); };
        g_wait_cond_deadline = Clock::now() + std::chrono::microseconds((int64_t)(timeout * 1e6));
        print("waiting for a save file to be loaded");
        return;
    }
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

// ---------------------------------------------------------------------------------------------------------------
// load, goload, walkto and face: controller 1 driven once per game update (drive_tick) until a state is reached, so a
// test script needs no hands and no screenshots to get somewhere.

constexpr uint16_t kTitleMap = 0x18B;         // the logos, title flight and title screen (src/game/quick_start.cpp)
constexpr uint16_t kFileSelectMap = 0x158;    // the file select (quick_start.cpp, src/debug/warp.cpp)
// The open save file, 0 to 2, -1 for none (src/game/timer_save.cpp, src/gameplay/progress_cheats.cpp). On the file
// select the game sets it as a file is picked out (func_808005D4_chgameselect calls func_800D37C0 with the file), and
// to -1 for the choices that are not files (func_800D37D4).
constexpr uint32_t kSaveSlot = 0x8012B3F1;
// Player 0's PlayerState (src/gameplay/player_cheats.cpp); its +0xF8 points at Banjo's yaw and, after it, the yaw he
// turns to (degrees, 0 faces +z; src/gameplay/dive.cpp, src/game/game_frame_rate.cpp).
constexpr uint32_t kPlayerTable = 0x80135490;
constexpr uint32_t kPlayerYaw = 0xF8;
// Points at the camera, its position first (src/game/widescreen.cpp's camera_position).
constexpr uint32_t kCameraPtr = 0x8012D500;
constexpr uint16_t kButtonA = 0x8000;
constexpr double kPi = 3.14159265358979;

enum { kDriveNone = 0, kDriveLoad, kDriveWalk };

struct Drive {
    std::atomic<int> kind{ kDriveNone }; // stored last, after the rest is filled in (the command may run before the game)
    std::string name;                    // the command, for the "[command]" prefix
    Clock::time_point start, deadline;
    // load
    int slot = 0;                        // 0 to 2
    std::string then;                    // queued at the front once the file is loaded (goload)
    Clock::time_point next;              // no new input before this
    Clock::time_point arrived;           // when the file select was first seen (epoch: not yet)
    int moved = 0;                       // the stick's last move on the file select (+1 right, -1 left), 0 none
    int moved_from = 0;                  // the file the cursor was on before it (3: a choice that is not a file)
    int right = 1;                       // which way right moves the cursor, learned from the moves
    int stuck = 0;                       // moves in a row that did not move the cursor
    // walkto
    float x = 0, z = 0, radius = 0;
    float fx = 0, fz = 0;                // the camera's last forward across the ground (0 0: none yet)
};
Drive g_drive;

void drive_say(const std::string& text, bool failed) {
    {
        std::lock_guard lock{ g_mutex };
        g_current = g_drive.name;
    }
    if (failed) error(text);
    else print(text);
}

// Stops driving: controller 1 is let go and the queue goes on.
void drive_end() {
    hold(0, false, 0, 0, 0);
    g_drive.kind = kDriveNone;
}

// Holds the queue while a drive runs. Its own deadline ends it with an ERR from drive_tick; this one, a little later,
// only lets the queue go if no game update ever comes to run it.
void drive_begin(const std::string& name, int kind, double seconds) {
    g_drive.name = name;
    g_drive.start = Clock::now();
    g_drive.deadline = g_drive.start + std::chrono::microseconds((int64_t)(seconds * 1e6));
    g_drive.kind = kind;
    g_wait_cond = [] { return g_drive.kind.load() == kDriveNone; };
    g_wait_cond_deadline = g_drive.deadline + std::chrono::seconds(5);
}

// The file select's slot under the cursor, 0 to 2, or 3 for the other choices.
int cursor_file(uint8_t* rdram) {
    int open = (int8_t)read_ram(rdram, kSaveSlot, 1);
    return open >= 0 && open <= 2 ? open : 3;
}

void load_tick(uint8_t* rdram) {
    Clock::time_point now = Clock::now();
    uint16_t map = tooie::debug::current_map(rdram);
    double took = std::chrono::duration<double>(now - g_drive.start).count();
    if (tooie::debug::can_warp()) {
        if (tooie::debug::map_change_busy(rdram)) return; // the file's first map is still coming in
        int open = (int8_t)read_ram(rdram, kSaveSlot, 1);
        std::string then = g_drive.then;
        drive_end();
        // After a Jiggywiggy challenge (a replay) the byte reads -1 with the file still being played, so -1
        // with a save loaded counts as the file asked for.
        if (open < 0) {
            drive_say(format("a save file is loaded (which one isn't known after a challenge), map 0x%X (%s)", map, map_name(map)), false);
            if (!then.empty()) enqueue_line(then, 1, true);
            return;
        }
        if (open != g_drive.slot) {
            drive_say(format("file %d is loaded, not file %d (map 0x%X); go back to the file select first", open + 1, g_drive.slot + 1, map), true);
            return;
        }
        drive_say(format("file %d loaded after %.1f s, map 0x%X (%s)", open + 1, took, map, map_name(map)), false);
        if (!then.empty()) enqueue_line(then, 1, true);
        return;
    }
    if (now >= g_drive.deadline) {
        drive_end();
        drive_say(format("file %d did not load in %.0f s (map 0x%X, cursor on %d)", g_drive.slot + 1, took, map, cursor_file(rdram) + 1), true);
        return;
    }
    if (now < g_drive.next || tooie::debug::map_change_busy(rdram) || tooie::debug::warp_pending()) return;
    if (map == kTitleMap) {
        // What Start does with Quick start on, at any point of the logos and the title: the file select, exit 0.
        tooie::debug::request_warp(kFileSelectMap, 0);
        g_drive.arrived = Clock::time_point{};
        g_drive.next = now + std::chrono::seconds(2);
        return;
    }
    if (map != kFileSelectMap) return; // still booting
    if (g_drive.arrived == Clock::time_point{}) {
        // The screen comes in with its own camera move first.
        g_drive.arrived = now;
        g_drive.next = now + std::chrono::seconds(2);
        return;
    }
    int cur = cursor_file(rdram);
    if (g_drive.moved != 0) {
        // Learn which way right goes from the last move. A step of two is the cursor wrapping round, which says nothing;
        // two moves that went nowhere mean the cursor is against the end of the row, so the other way is tried.
        int step = cur - g_drive.moved_from;
        if (step == 0 && ++g_drive.stuck >= 2) {
            g_drive.right = -g_drive.right;
            g_drive.stuck = 0;
        } else if (step == 1 || step == -1) {
            g_drive.right = (step > 0) == (g_drive.moved > 0) ? 1 : -1;
            g_drive.stuck = 0;
        }
        g_drive.moved = 0;
    }
    if (cur == g_drive.slot) {
        // A on the file, long enough for the menu to see it at any frame rate; again every 3 s while the file select
        // stays (a new file asks more than once).
        hold(kButtonA, false, 0, 0, -1, now + std::chrono::milliseconds(200));
        g_drive.next = now + std::chrono::seconds(3);
        return;
    }
    int dir = (g_drive.slot > cur ? 1 : -1) * g_drive.right;
    g_drive.moved = dir;
    g_drive.moved_from = cur;
    hold(0, true, dir * 80, 0, -1, now + std::chrono::milliseconds(150));
    g_drive.next = now + std::chrono::milliseconds(700);
}

// The way the camera looks across the ground, as a unit x, z: from the camera to Banjo. The game turns the stick by the
// camera's yaw (src/gameplay/free_camera.cpp) and the camera looks at Banjo, so up on the stick walks this way.
bool camera_forward(uint8_t* rdram, const float player[3], float* fx, float* fz) {
    uint32_t camera = read_ram(rdram, kCameraPtr, 4);
    if (!tooie::rdram::valid_ptr(camera)) return false;
    float ax = player[0] - tooie::rdram::read_float(rdram, camera);
    float az = player[2] - tooie::rdram::read_float(rdram, camera + 8);
    float len = std::sqrt(ax * ax + az * az);
    if (!(len > 1.0f)) return false; // straight above him: no way across the ground
    *fx = ax / len;
    *fz = az / len;
    return true;
}

void walk_tick(uint8_t* rdram) {
    Clock::time_point now = Clock::now();
    double took = std::chrono::duration<double>(now - g_drive.start).count();
    float p[3];
    if (!tooie::player_cheats::position(rdram, p)) {
        drive_end();
        drive_say("there is no player any more", true);
        return;
    }
    float dx = g_drive.x - p[0], dz = g_drive.z - p[2];
    float dist = std::sqrt(dx * dx + dz * dz);
    if (dist <= g_drive.radius) {
        drive_end();
        drive_say(format("there after %.1f s, %.1f away, at %.2f %.2f %.2f", took, dist, p[0], p[1], p[2]), false);
        return;
    }
    if (now >= g_drive.deadline) {
        drive_end();
        drive_say(format("still %.0f away after %.0f s, at %.2f %.2f %.2f", dist, took, p[0], p[1], p[2]), true);
        return;
    }
    float fx, fz;
    if (camera_forward(rdram, p, &fx, &fz)) {
        g_drive.fx = fx;
        g_drive.fz = fz;
    }
    if (g_drive.fx == 0 && g_drive.fz == 0) return; // no camera yet
    // The way to go on the stick: up is the camera's forward, right is that turned a quarter clockwise seen from above
    // (+x on screen when the camera looks along -z). Slower near the point, so he stops on it instead of past it.
    float ux = dx / dist, uz = dz / dist;
    float sx = ux * -g_drive.fz + uz * g_drive.fx;
    float sy = ux * g_drive.fx + uz * g_drive.fz;
    if (tooie::mirror_mode::active()) sx = -sx; // the stick is flipped after the console's input (src/debug/pad_script.cpp)
    float speed = std::clamp(dist / (g_drive.radius * 4.0f), 0.45f, 1.0f) * 80.0f;
    hold(0, true, (int)std::lround(sx * speed), (int)std::lround(sy * speed), -1);
}

// Once per game update, before the queue runs, so a drive that ends lets the next command run in the same update.
void drive_tick(uint8_t* rdram) {
    int kind = g_drive.kind.load();
    if (kind == kDriveLoad) load_tick(rdram);
    else if (kind == kDriveWalk) walk_tick(rdram);
}

// Starts the game if it is not running, then drives to file `slot` (0 to 2); `then` runs once it is loaded.
void begin_load(const std::string& name, int slot, double timeout, const std::string& then) {
    if (!ultramodern::is_game_started() && !start_game()) return;
    g_drive.slot = slot;
    g_drive.then = then;
    g_drive.next = Clock::time_point{};
    g_drive.arrived = Clock::time_point{};
    g_drive.moved = 0;
    g_drive.right = 1;
    g_drive.stuck = 0;
    drive_begin(name, kDriveLoad, timeout);
    print(format("loading file %d (up to %.0f s)", slot + 1, timeout));
}

// load [file 1-3] [timeout s]: from the launcher, the title or the file select into a save file.
void cmd_load(Ctx& c) {
    int slot = 1;
    double timeout = 60;
    if ((c.w.size() >= 2 && (!parse_int(c.w[1], &slot) || slot < 1 || slot > 3)) || (c.w.size() >= 3 && (!parse_double(c.w[2], &timeout) || timeout <= 0))) {
        error("load [file 1 to 3] [timeout s]");
        return;
    }
    begin_load("load", slot - 1, std::min(timeout, 600.0), "");
}

// goload <file> <map hex> [exit hex]: load, then warp id and wait map, as one line for test scripts.
void cmd_goload(Ctx& c) {
    int slot;
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
    if (c.w.size() < 3 || !parse_int(c.w[1], &slot) || slot < 1 || slot > 3 || !hex_of(c.w[2], &map) || (c.w.size() >= 4 && (!hex_of(c.w[3], &exit) || exit > 0xFF))) {
        error("goload <file 1 to 3> <map hex> [exit hex]");
        return;
    }
    // The 30 updates either side let the file's first map settle before the warp, and the game place Banjo after it.
    begin_load("goload", slot - 1, 60, format("wait 30; warp id %X %X; wait map %X 60; wait 30", map, exit, map));
}

// walkto <x> <z> [radius] [timeout s]: walks Banjo to a point with the stick.
void cmd_walkto(Ctx& c) {
    double x, z, radius = 30, timeout = 10;
    if (c.w.size() < 3 || !parse_double(c.w[1], &x) || !parse_double(c.w[2], &z)
        || (c.w.size() >= 4 && (!parse_double(c.w[3], &radius) || radius <= 0))
        || (c.w.size() >= 5 && (!parse_double(c.w[4], &timeout) || timeout <= 0))) {
        error("walkto <x> <z> [radius] [timeout s] (pos shows where you are)");
        return;
    }
    float p[3];
    if (!tooie::player_cheats::position(c.rdram, p)) { error("there is no player yet"); return; }
    g_drive.x = (float)x;
    g_drive.z = (float)z;
    g_drive.radius = (float)radius;
    g_drive.fx = g_drive.fz = 0;
    timeout = std::min(timeout, 600.0);
    drive_begin("walkto", kDriveWalk, timeout);
    print(format("walking to %.2f %.2f, %.0f away (to within %.0f, up to %.0f s)", x, z, std::hypot(x - p[0], z - p[2]), radius, timeout));
}

// face <x> <z>: turns Banjo to a point at once.
void cmd_face(Ctx& c) {
    double x, z;
    if (c.w.size() < 3 || !parse_double(c.w[1], &x) || !parse_double(c.w[2], &z)) { error("face <x> <z> (pos shows where you are)"); return; }
    float p[3];
    uint32_t player = read_ram(c.rdram, kPlayerTable, 4);
    uint32_t yaw = tooie::rdram::valid_ptr(player) ? read_ram(c.rdram, player + kPlayerYaw, 4) : 0;
    if (!tooie::player_cheats::position(c.rdram, p) || !tooie::rdram::valid_ptr(yaw)) { error("there is no player yet"); return; }
    double dx = x - p[0], dz = z - p[2];
    if (std::hypot(dx, dz) < 1.0) { error("Banjo is standing on that point"); return; }
    float deg = (float)std::fmod(std::atan2(dx, dz) * 180.0 / kPi + 360.0, 360.0);
    // The yaw and the one he turns to both, or the game turns him back.
    tooie::rdram::write_float(c.rdram, yaw, deg);
    tooie::rdram::write_float(c.rdram, yaw + 4, deg);
    print(format("facing %.0f degrees, towards %.2f %.2f", deg, x, z));
}

// Player states where the game has Banjo, not the player: none (0), door walk-ins and loading zones (0x98, also the
// scripted walk Mumbo, Heggy, Master Jiggywiggy and King Jingaling call him over with), the locked states for
// signposts, talking and cutscenes (src/gameplay/player_cheats.cpp's noclip_paused_state and src/gameplay/test_room.cpp),
// and dead (0x41, src/gameplay/boss_rush.cpp).
bool locked_state(uint32_t s) {
    return s == 0 || s == 0x98 || s == 0x97 || s == 0x93 || s == 0x92 || s == 0x5D || s == 0x75 || s == 0x9A || s == 0x41;
}

constexpr uint32_t kPlayerStateBlock = 0x120; // PlayerState -> state block, whose +0x4 is the current state id
constexpr uint32_t kGamePause = 0x80128AF0;   // the game's pause menu object while it is open (player_cheats.cpp)

// wait control: a file is being played, no letterboxed scene is on (src/game/field_of_view.cpp, as Skip cutscenes
// uses), no map change is under way, the pause menu is shut, and Banjo is in a state of the player's.
bool in_control(uint8_t* rdram) {
    if (!tooie::debug::can_warp() || tooie::in_letterboxed_scene() || tooie::debug::map_change_busy(rdram)) return false;
    if (read_ram(rdram, kGamePause, 4) != 0) return false;
    uint32_t player = read_ram(rdram, kPlayerTable, 4);
    if (!tooie::rdram::valid_ptr(player)) return false;
    uint32_t block = read_ram(rdram, player + kPlayerStateBlock, 4);
    if (!tooie::rdram::valid_ptr(block)) return false;
    return !locked_state(read_ram(rdram, block + 0x4, 4));
}

// look: the gameplay camera held at an angle, for screenshots. The dynamic camera's update (func_80110588) skips its
// own work while its +0x72 is set and still hands its position (+0x74) and rotation (+0x80, pitch, yaw and roll in
// degrees) on to the viewport camera, so look writes those with +0x72 set on every game update. The free camera
// (src/gameplay/free_camera.cpp) leaves a camera held that way alone. Yaw 0 looks along -z and grows turning left, and
// a positive pitch looks up (src/gameplay/photo_mode.cpp).
constexpr uint32_t kCtlDynamic = 0x04;        // camera controller -> the dynamic camera (free_camera.cpp)
constexpr uint32_t kCtlMode = 0x16;           // camera controller -> its mode, 2 the dynamic camera
constexpr int16_t kModeDynamic = 2;
constexpr uint32_t kDynFrozen = 0x72;
constexpr uint32_t kDynPos = 0x74;
constexpr uint32_t kDynRot = 0x80;

struct Look {
    bool on = false;
    uint32_t dynamic = 0;
    uint16_t map = 0;                         // a map change ends the look (the camera is made again)
    uint32_t frozen_before = 0;               // +0x72 as the game had it, put back by look off
    float pos[3] = { 0, 0, 0 };
    float pitch = 0, yaw = 0;
};
Look g_look;

// The gameplay camera of the viewport stepped last, 0 while another kind of camera is running (a scene, a fixed one).
uint32_t gameplay_camera(uint8_t* rdram) {
    uint32_t ctl = tooie::free_camera::last_controller();
    if (!tooie::rdram::valid_ptr(ctl) || (int16_t)read_ram(rdram, ctl + kCtlMode, 2) != kModeDynamic) return 0;
    uint32_t dynamic = read_ram(rdram, ctl + kCtlDynamic, 4);
    return tooie::rdram::valid_ptr(dynamic) ? dynamic : 0;
}

float wrap_360(double deg) {
    double d = std::fmod(deg, 360.0);
    return (float)(d < 0 ? d + 360.0 : d);
}

// Once per game update. After a map change the old camera is gone, so nothing is written or put back.
void look_tick(uint8_t* rdram) {
    if (!g_look.on) return;
    if (tooie::debug::current_map(rdram) != g_look.map || tooie::debug::map_change_busy(rdram)) {
        g_look.on = false;
        {
            std::lock_guard lock{ g_mutex };
            g_current = "look";
        }
        print("the camera is the game's again (the map changed)");
        return;
    }
    write_ram(rdram, g_look.dynamic + kDynFrozen, 1, 1);
    for (int k = 0; k < 3; k++) tooie::rdram::write_float(rdram, g_look.dynamic + kDynPos + 4 * k, g_look.pos[k]);
    tooie::rdram::write_float(rdram, g_look.dynamic + kDynRot, g_look.pitch);
    tooie::rdram::write_float(rdram, g_look.dynamic + kDynRot + 4, g_look.yaw);
}

constexpr float kHeadHeight = 60.0f;          // Banjo's feet to the point the free camera orbits (free_camera.cpp)
constexpr double kLookDistance = 350.0;

// look [here] <yaw> [pitch] [distance] | look [here] at <x> <y> <z> [distance] | look off. Without `here` the camera is
// put `distance` back from Banjo's head along the view and looks at him, pulled in front of any wall between (the
// free camera's line test); with it, the camera turns where it stands.
void cmd_look(Ctx& c) {
    const char* usage = "look <yaw deg> [pitch deg] [distance] | look at <x> <y> <z> [distance] | look here <yaw> [pitch] | look here at <x> <y> <z> | look off";
    if (c.w.size() < 2) { error(usage); return; }
    if (lower(c.w[1]) == "off") {
        if (!g_look.on) { print("the camera is the game's already"); return; }
        write_ram(c.rdram, g_look.dynamic + kDynFrozen, g_look.frozen_before, 1);
        g_look.on = false;
        print("the camera is the game's again");
        return;
    }
    size_t i = 1;
    bool here = lower(c.w[i]) == "here";
    if (here) i++;
    bool at = i < c.w.size() && lower(c.w[i]) == "at";
    if (at) i++;
    uint32_t dynamic = g_look.on ? g_look.dynamic : gameplay_camera(c.rdram);
    if (dynamic == 0 || !tooie::debug::can_warp()) { error("the gameplay camera is not running (a scene, a fixed camera, or no file loaded)"); return; }
    float feet[3];
    if (!here && !tooie::player_cheats::position(c.rdram, feet)) { error("there is no player yet"); return; }
    float pos[3];
    for (int k = 0; k < 3; k++) pos[k] = g_look.on ? g_look.pos[k] : tooie::rdram::read_float(c.rdram, dynamic + kDynPos + 4 * k);
    // Where the view comes from when the angles are worked out: the camera for `here`, Banjo's head otherwise.
    float from[3] = { pos[0], pos[1], pos[2] };
    if (!here) { from[0] = feet[0]; from[1] = feet[1] + kHeadHeight; from[2] = feet[2]; }
    double yaw, pitch = 0, distance = kLookDistance;
    size_t next;
    if (at) {
        double t[3];
        if (i + 2 >= c.w.size() || !parse_double(c.w[i], &t[0]) || !parse_double(c.w[i + 1], &t[1]) || !parse_double(c.w[i + 2], &t[2])) { error(usage); return; }
        double dx = t[0] - from[0], dy = t[1] - from[1], dz = t[2] - from[2];
        double across = std::hypot(dx, dz);
        if (across < 1.0 && std::fabs(dy) < 1.0) { error(here ? "the camera is on that point" : "Banjo is on that point"); return; }
        yaw = std::atan2(-dx, -dz) * 180.0 / kPi;
        pitch = std::atan2(dy, across) * 180.0 / kPi;
        next = i + 3;
    } else {
        if (i >= c.w.size() || !parse_double(c.w[i], &yaw) || (i + 1 < c.w.size() && !parse_double(c.w[i + 1], &pitch))) { error(usage); return; }
        next = i + 2;
    }
    if (next < c.w.size() && (here || !parse_double(c.w[next], &distance) || distance < 1 || distance > 5000)) { error(usage); return; }
    pitch = std::clamp(pitch, -89.0, 89.0);
    bool pulled_in = false;
    if (!here) {
        // Back from his head against the view: yaw 0 looks along -z and grows turning left, so the view is
        // (-sin yaw, sin pitch, -cos yaw) with the across part scaled by cos pitch.
        double ry = yaw * kPi / 180.0, rp = pitch * kPi / 180.0;
        double f[3] = { -std::sin(ry) * std::cos(rp), std::sin(rp), -std::cos(ry) * std::cos(rp) };
        for (int k = 0; k < 3; k++) pos[k] = from[k] - (float)(f[k] * distance);
        float normal[3];
        if (c.ctx != nullptr) pulled_in = tooie::free_camera::sweep_line(c.rdram, c.ctx, from, pos, normal);
    }
    if (!g_look.on) {
        g_look.dynamic = dynamic;
        g_look.map = tooie::debug::current_map(c.rdram);
        g_look.frozen_before = read_ram(c.rdram, dynamic + kDynFrozen, 1);
    }
    for (int k = 0; k < 3; k++) g_look.pos[k] = pos[k];
    g_look.yaw = wrap_360(yaw);
    g_look.pitch = wrap_360(pitch); // the game keeps its angles from 0 to 360 (src/input/motion_aim.cpp)
    g_look.on = true;
    look_tick(c.rdram);
    print(format("camera at %.0f %.0f %.0f looking yaw %.1f, pitch %.1f%s (look off gives it back)", pos[0], pos[1], pos[2], wrap_360(yaw), pitch,
        pulled_in ? ", pulled in front of a wall" : ""));
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
    std::filesystem::path path = typed_path(rest_of(c.line, 1));
    if (path.is_relative() && !std::filesystem::exists(path)) path = recompui::file::get_app_folder_path() / path;
    std::ifstream in{ path };
    if (!in.good()) { error("cannot open " + tooie::path_text(path)); return; }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;
        lines.push_back(line);
    }
    for (auto it = lines.rbegin(); it != lines.rend(); ++it) enqueue_line(*it, c.depth + 1, true);
    print(format("%zu lines from %s", lines.size(), tooie::path_text(path).c_str()));
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
        // v - addr, not addr + range: a large range would wrap past 0xFFFFFFFF and match nothing.
        if (v >= addr && v - addr < std::max<uint32_t>(range, 1)) {
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
    std::filesystem::path other = typed_path(rest_of(c.line, 2));
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
    if (n == 0) { error("no settings files found in " + tooie::path_text(from)); return; }
    print(format("%d settings files copied to %s", n, tooie::path_text(to).c_str()) + (what == "import" ? "\nRestart the game to use them." : ""));
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
        print("saved a copy to " + tooie::path_text(dir));
        return;
    }
    if (what == "list") {
        std::vector<std::string> names;
        for (const auto& entry : std::filesystem::directory_iterator(root, ec)) {
            if (entry.is_directory()) names.push_back(tooie::path_text(entry.path().filename()));
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
        for (const auto& entry : std::filesystem::directory_iterator(dir, ec)) out += (out.empty() ? "" : "\n") + tooie::path_text(entry.path().stem());
        print(out.empty() ? "no profiles" : out);
        return;
    }
    if ((what != "save" && what != "load") || c.w.size() < 3) { error("profile save <name> | profile load <name> | profile list"); return; }
    std::filesystem::path file = dir / (squash(c.w[2]) + ".txt");
    if (what == "load") {
        Ctx d = c;
        d.w = { "exec", tooie::path_text(file) };
        d.line = "exec " + tooie::path_text(file);
        cmd_exec(d);
        return;
    }
    std::filesystem::create_directories(dir, ec);
    std::ofstream out{ file };
    if (!out.good()) { error("cannot write " + tooie::path_text(file)); return; }
    out << "# Console settings profile. profile load " << squash(c.w[2]) << " sets these.\n";
    int n = 0;
    for (const SettingRef& r : all_settings()) {
        if (r.debug || r.type() == ConfigOptionType::String) continue;
        std::string v = value_text(r);
        if (v == "?") continue;
        out << "set " << r.full_id() << " " << v << "\n";
        n++;
    }
    print(format("%d settings saved to %s", n, tooie::path_text(file).c_str()));
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

// Jiggies and Jiggywiggy's challenges. Whether the next challenge can start is sujiggy_entrypoint_17: the challenges
// done (flags 0x35C, 4 bits, sujiggy_entrypoint_0) against func_800D035C(1), the Jiggies collected, which the game
// counts from the collected flags each time (nothing is spent), and the challenge's price.
constexpr int32_t kJiggyFirst = 0x250;        // FLAG_250 .. FLAG_2A9, the 90 Jiggies (src/gameplay/totals_rules.inc)
constexpr int32_t kJiggyLast = 0x2A9;
// Left out when Jiggies are added: the bosses' (in case a fight reads its own), and King Jingaling's from the intro.
constexpr int32_t kJiggyKept[] = { 0x250, 0x25A, 0x266, 0x274, 0x27B, 0x283, 0x28C, 0x296, 0x2A9 };
constexpr int32_t kChallengeFlag = 0x35C;     // Jiggywiggy's challenges done, 11 all (src/gameplay/progress_cheats.cpp)
constexpr int kChallengeBits = 4;
constexpr int kChallengeCount = 11;           // sujiggy_entrypoint_1
// Jiggies the first nine challenges ask for, one per world (src/gameplay/totals_checklist.cpp's world_cost).
constexpr int kChallengeCost[9] = { 1, 4, 8, 14, 20, 28, 36, 45, 55 };

// func_800D035C(1): the Jiggies the game counts.
int32_t game_jiggies(uint8_t* rdram, recomp_context* ctx) {
    recomp_context saved = *ctx;
    ctx->r4 = 1;
    func_800D035C(rdram, ctx);
    int32_t n = (int32_t)ctx->r2;
    *ctx = saved;
    return n;
}

// The challenges done, lowest bit first as func_800DA564 reads a number kept in flags.
int challenges_done(uint8_t* rdram, recomp_context* ctx) {
    int n = 0;
    for (int b = 0; b < kChallengeBits; b++) {
        if (tooie::progress_cheats::get_flag(rdram, ctx, kChallengeFlag + b)) n |= 1 << b;
    }
    return n;
}

std::string challenge_text(uint8_t* rdram, recomp_context* ctx) {
    int done = challenges_done(rdram, ctx);
    if (done >= kChallengeCount) return format("Jiggywiggy's challenges done: %d (all)", done);
    if (done < 9) return format("Jiggywiggy's challenges done: %d, the next asks for %d Jiggies", done, kChallengeCost[done]);
    return format("Jiggywiggy's challenges done: %d", done);
}

// jiggies [n]: the Jiggies the game counts, or at least n of them by setting Jiggy flags.
void cmd_jiggies(Ctx& c) {
    if (c.ctx == nullptr) { error("no game update is running"); return; }
    if (!tooie::debug::can_warp()) { error("a save file has to be loaded first"); return; }
    int have = game_jiggies(c.rdram, c.ctx);
    if (c.w.size() < 2) {
        print(format("%d Jiggies\n", have) + challenge_text(c.rdram, c.ctx));
        return;
    }
    int want;
    if (!parse_int(c.w[1], &want) || want < 0 || want > 90) { error("jiggies [0 to 90]"); return; }
    if (have >= want) { print(format("%d Jiggies already (nothing taken away)", have)); return; }
    int added = 0;
    for (int32_t f = kJiggyFirst; f <= kJiggyLast && have + added < want; f++) {
        if (std::find(std::begin(kJiggyKept), std::end(kJiggyKept), f) != std::end(kJiggyKept)) continue;
        if (tooie::progress_cheats::get_flag(c.rdram, c.ctx, f)) continue;
        tooie::progress_cheats::set_flag(c.rdram, c.ctx, f, true);
        added++;
    }
    int now = game_jiggies(c.rdram, c.ctx);
    if (now < want) { error(format("set %d Jiggy flags, but the game counts %d, not %d", added, now, want)); return; }
    print(format("%d -> %d Jiggies (%d flags set; saving keeps them)\n", have, now, added) + challenge_text(c.rdram, c.ctx));
}

// challenge [n]: Jiggywiggy's challenges done, so challenge n + 1 is the next.
void cmd_challenge(Ctx& c) {
    if (c.ctx == nullptr) { error("no game update is running"); return; }
    if (!tooie::debug::can_warp()) { error("a save file has to be loaded first"); return; }
    if (c.w.size() < 2) { print(challenge_text(c.rdram, c.ctx)); return; }
    int n;
    if (!parse_int(c.w[1], &n) || n < 0 || n > kChallengeCount) { error("challenge [challenges done, 0 to 11]"); return; }
    int before = challenges_done(c.rdram, c.ctx);
    for (int b = 0; b < kChallengeBits; b++) tooie::progress_cheats::set_flag(c.rdram, c.ctx, kChallengeFlag + b, ((n >> b) & 1) != 0);
    print(format("challenges done %d -> %d (saving keeps it)\n", before, n) + challenge_text(c.rdram, c.ctx));
}

// ---------------------------------------------------------------------------------------------------------------
// Quick testing: marks, scenarios, input recording, the split timer, autoexec, history, grep, input.

std::filesystem::path app_file(const char* name) {
    return recompui::file::get_app_folder_path() / name;
}

// mark <name> / recall <name>: a map and a position, kept in marks.txt as "name map x y z".
struct Mark { uint16_t map; float pos[3]; };

std::map<std::string, Mark> read_marks() {
    std::map<std::string, Mark> marks;
    std::ifstream in{ app_file("marks.txt") };
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream s{ line };
        std::string name;
        Mark m{};
        unsigned map = 0;
        if (line.empty() || line[0] == '#') continue;
        if (s >> name >> std::hex >> map >> std::dec >> m.pos[0] >> m.pos[1] >> m.pos[2]) {
            m.map = (uint16_t)map;
            marks[name] = m;
        }
    }
    return marks;
}

void write_marks(const std::map<std::string, Mark>& marks) {
    std::ofstream out{ app_file("marks.txt") };
    out << "# Console marks: name, map (hex), x y z. Written by mark.\n";
    for (const auto& [name, m] : marks) out << format("%s %X %.3f %.3f %.3f\n", name.c_str(), m.map, m.pos[0], m.pos[1], m.pos[2]);
}

// The commands that put Banjo at a map and position: a warp first only when the map differs.
std::string place_commands(uint8_t* rdram, uint16_t map, const float pos[3]) {
    std::string go = format("goto %.3f %.3f %.3f", pos[0], pos[1], pos[2]);
    if (rdram != nullptr && tooie::debug::current_map(rdram) == map) return go;
    // 30 game updates after the map is in: the player is placed by then.
    return format("wait save; warp id %X; wait map %X; wait 30; ", map, map) + go;
}

void cmd_mark(Ctx& c) {
    std::map<std::string, Mark> marks = read_marks();
    if (c.w.size() < 2 || lower(c.w[1]) == "list") {
        std::string out;
        for (const auto& [name, m] : marks) {
            out += format("%s%s: map 0x%X (%s) %.1f %.1f %.1f", out.empty() ? "" : "\n", name.c_str(), m.map, map_name(m.map), m.pos[0], m.pos[1], m.pos[2]);
        }
        print(out.empty() ? "no marks (mark <name> keeps where Banjo is)" : out);
        return;
    }
    if (lower(c.w[1]) == "delete" || lower(c.w[1]) == "del") {
        if (c.w.size() < 3 || marks.erase(lower(c.w[2])) == 0) { error("mark delete <name> (mark list)"); return; }
        write_marks(marks);
        print("deleted " + lower(c.w[2]));
        return;
    }
    if (c.rdram == nullptr) { error("the game has to be running"); return; }
    Mark m{};
    if (!tooie::player_cheats::position(c.rdram, m.pos)) { error("there is no player yet"); return; }
    m.map = tooie::debug::current_map(c.rdram);
    std::string name = lower(c.w[1]);
    marks[name] = m;
    write_marks(marks);
    print(format("%s: map 0x%X (%s) %.1f %.1f %.1f", name.c_str(), m.map, map_name(m.map), m.pos[0], m.pos[1], m.pos[2]));
}

void cmd_recall(Ctx& c) {
    if (c.w.size() < 2) { error("recall <name> (mark list)"); return; }
    std::map<std::string, Mark> marks = read_marks();
    auto it = marks.find(lower(c.w[1]));
    if (it == marks.end()) { error("no mark called \"" + c.w[1] + "\" (mark list)"); return; }
    enqueue_line(place_commands(c.rdram, it->second.map, it->second.pos), c.depth + 1, true);
}

// scenario <name>: runs scenarios/<name>.txt. scenario save <name> writes one from where Banjo is and the named items.
std::filesystem::path scenario_dir() { return app_file("scenarios"); }

void cmd_scenario(Ctx& c) {
    std::error_code ec;
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "list";
    if (what == "list") {
        std::vector<std::string> names;
        for (const auto& e : std::filesystem::directory_iterator(scenario_dir(), ec)) {
            if (e.path().extension() == ".txt") names.push_back(tooie::path_text(e.path().stem()));
        }
        std::sort(names.begin(), names.end());
        std::string out;
        for (const std::string& n : names) out += (out.empty() ? "" : " ") + n;
        print(out.empty() ? "no scenarios yet (scenario save <name>, or write scenarios/<name>.txt by hand)" : out);
        return;
    }
    if (what == "save") {
        if (c.w.size() < 3) { error("scenario save <name>"); return; }
        if (c.rdram == nullptr || c.ctx == nullptr) { error("the game has to be running"); return; }
        float pos[3];
        if (!tooie::player_cheats::position(c.rdram, pos)) { error("there is no player yet"); return; }
        uint16_t map = tooie::debug::current_map(c.rdram);
        std::filesystem::create_directories(scenario_dir(), ec);
        std::filesystem::path path = scenario_dir() / typed_path(lower(c.w[2]) + ".txt");
        std::ofstream out{ path };
        if (!out.good()) { error("cannot write " + tooie::path_text(path)); return; }
        out << "# Scenario " << lower(c.w[2]) << ": map 0x" << format("%X", map) << " (" << map_name(map) << "). Add any console commands.\n";
        out << format("wait save\nwarp id %X\nwait map %X\nwait 30\ngoto %.3f %.3f %.3f\n", map, map, pos[0], pos[1], pos[2]);
        for (const ItemName& in : kItemNames) {
            out << format("item %d %d\n", in.index, tooie::progress_cheats::get_item(c.rdram, c.ctx, 0x40 + in.index));
        }
        print("wrote " + tooie::path_text(path));
        return;
    }
    if (what == "delete" || what == "del") {
        if (c.w.size() < 3 || !std::filesystem::remove(scenario_dir() / typed_path(lower(c.w[2]) + ".txt"), ec)) { error("scenario delete <name> (scenario list)"); return; }
        print("deleted " + lower(c.w[2]));
        return;
    }
    std::filesystem::path path = scenario_dir() / typed_path(what + ".txt");
    if (!std::filesystem::exists(path, ec)) { error("no scenario called \"" + what + "\" (scenario list)"); return; }
    enqueue_line("exec " + tooie::path_text(path), c.depth, true);
}

// record <name> / record stop / play <name>: controller 1, one entry per game update, in inputs/<name>.txt.
struct InputFrame { uint64_t frame; uint16_t buttons; float x, y; bool got; };
std::vector<InputFrame> g_rec;            // under g_input_mutex
bool g_recording;
uint64_t g_rec_start;
std::string g_rec_name;
std::vector<InputFrame> g_play;           // under g_input_mutex
bool g_playing;
uint64_t g_play_start;
size_t g_play_at;
InputFrame g_last_input;                  // the last input the game got, for `input`

std::filesystem::path input_dir() { return app_file("inputs"); }

bool save_recording() {
    std::error_code ec;
    std::filesystem::create_directories(input_dir(), ec);
    std::filesystem::path path = input_dir() / typed_path(g_rec_name + ".txt");
    std::ofstream out{ path };
    if (!out.good()) { error("cannot write " + tooie::path_text(path)); return false; }
    out << "# Controller 1, one line per game update: update, buttons (hex), stick x, stick y. Written by record.\n";
    for (const InputFrame& f : g_rec) out << format("%llu %04X %.4f %.4f\n", (unsigned long long)f.frame, f.buttons, f.got ? f.x : 0.0f, f.got ? f.y : 0.0f);
    print(format("%zu updates kept in %s", g_rec.size(), tooie::path_text(path).c_str()));
    return true;
}

void cmd_record(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "";
    std::lock_guard lock{ g_input_mutex };
    if (what == "stop" || what == "off") {
        if (!g_recording) { error("nothing is being recorded"); return; }
        g_recording = false;
        save_recording();
        return;
    }
    if (what.empty() || what == "list") {
        std::error_code ec;
        std::string out;
        for (const auto& e : std::filesystem::directory_iterator(input_dir(), ec)) {
            if (e.path().extension() == ".txt") out += (out.empty() ? "" : " ") + tooie::path_text(e.path().stem());
        }
        print(out.empty() ? "no recordings (record <name>, then record stop)" : out);
        return;
    }
    if (g_recording) { error("already recording " + g_rec_name + " (record stop)"); return; }
    g_rec.clear();
    g_rec_name = what;
    g_rec_start = g_frames.load() + 1;
    g_recording = true;
    print("recording controller 1 as " + what + " (record stop ends it; savestate save first lets you replay from the same place)");
}

void cmd_play(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "";
    std::lock_guard lock{ g_input_mutex };
    if (what == "stop" || what == "off") {
        g_playing = false;
        print("playback stopped");
        return;
    }
    if (what.empty()) { error("play <name> | play stop (record list)"); return; }
    std::ifstream in{ input_dir() / typed_path(what + ".txt") };
    if (!in.good()) { error("no recording called \"" + what + "\" (record list)"); return; }
    std::vector<InputFrame> frames;
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty() || line[0] == '#') continue;
        std::istringstream s{ line };
        InputFrame f{};
        unsigned long long n;
        unsigned b;
        if (s >> n >> std::hex >> b >> std::dec >> f.x >> f.y) {
            f.frame = n;
            f.buttons = (uint16_t)b;
            f.got = true;
            frames.push_back(f);
        }
    }
    if (frames.empty()) { error(what + " is empty"); return; }
    g_play = std::move(frames);
    g_play_at = 0;
    g_play_start = g_frames.load() + 1;
    g_playing = true;
    print(format("playing %s: %llu updates (play stop ends it; the game's own input is ignored meanwhile)", what.c_str(), (unsigned long long)g_play.back().frame + 1));
}

void cmd_input(Ctx&) {
    InputFrame f;
    {
        std::lock_guard lock{ g_input_mutex };
        f = g_last_input;
    }
    std::string names;
    for (const auto& [name, bit] : kButtons) {
        if (std::strncmp(name, "d", 1) == 0 && std::strlen(name) > 1 && name[1] != 'o') continue; // dup etc.: same bits as up etc.
        if ((f.buttons & bit) != 0) names += (names.empty() ? "" : "+") + std::string(name);
    }
    print(format("buttons %04X %s, stick %d %d (of 80)%s", f.buttons, names.empty() ? "(none)" : names.c_str(),
        (int)std::lround(f.x * 80.0f), (int)std::lround(f.y * 80.0f), f.got ? "" : ", no controller"));
}

// timer start|stop|show: time between map changes, for practice runs.
struct Split { uint16_t map; double seconds; uint64_t updates; };
bool g_timer_on;
Clock::time_point g_timer_start, g_split_start;
uint64_t g_timer_frames, g_split_frames;
uint16_t g_timer_map;
std::vector<Split> g_splits;

std::string split_text(const Split& s) {
    return format("%s: %.2f s (%llu updates)", map_name(s.map), s.seconds, (unsigned long long)s.updates);
}

void timer_tick(uint8_t* rdram) {
    if (!g_timer_on || tooie::debug::map_change_busy(rdram)) return;
    uint16_t map = tooie::debug::current_map(rdram);
    if (map == g_timer_map) return;
    Clock::time_point now = Clock::now();
    Split s{ g_timer_map, std::chrono::duration<double>(now - g_split_start).count(), g_frames.load() - g_split_frames };
    g_splits.push_back(s);
    g_split_start = now;
    g_split_frames = g_frames.load();
    g_timer_map = map;
    {
        std::lock_guard lock{ g_mutex };
        g_current = "timer";
    }
    print("split " + split_text(s));
}

void cmd_timer(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "show";
    if (what == "start") {
        if (c.rdram == nullptr) { error("the game has to be running"); return; }
        g_timer_on = true;
        g_timer_start = g_split_start = Clock::now();
        g_timer_frames = g_split_frames = g_frames.load();
        g_timer_map = tooie::debug::current_map(c.rdram);
        g_splits.clear();
        print("timer started; it splits on every map change");
        return;
    }
    if (what != "stop" && what != "show") { error("timer start | timer stop | timer show"); return; }
    if (g_timer_start == Clock::time_point{}) { error("the timer has not run (timer start)"); return; }
    Clock::time_point now = Clock::now();
    std::string out;
    for (const Split& s : g_splits) out += split_text(s) + "\n";
    if (g_timer_on) {
        out += split_text({ g_timer_map, std::chrono::duration<double>(now - g_split_start).count(), g_frames.load() - g_split_frames }) + " (so far)\n";
        out += format("total %.2f s (%llu updates)", std::chrono::duration<double>(now - g_timer_start).count(), (unsigned long long)(g_frames.load() - g_timer_frames));
    } else {
        out += "stopped";
    }
    if (what == "stop") g_timer_on = false;
    print(out);
}

// autoexec: autoexec.txt in the game folder runs when the game starts.
void cmd_autoexec(Ctx& c) {
    std::filesystem::path path = app_file("autoexec.txt");
    std::error_code ec;
    bool there = std::filesystem::exists(path, ec);
    if (c.w.size() >= 2 && lower(c.w[1]) == "run") {
        if (!there) { error(tooie::path_text(path) + " does not exist"); return; }
        enqueue_line("exec " + tooie::path_text(path), c.depth, true);
        return;
    }
    print(tooie::path_text(path) + (there ? " runs at every start (autoexec run runs it now)" : " does not exist; put commands in it and they run at every start"));
}

// grep <text>: the console's lines that hold some text.
void cmd_grep(Ctx& c) {
    if (c.w.size() < 2) { error("grep <text>"); return; }
    std::string want = lower(rest_of(c.line, 1));
    std::vector<std::string> hits;
    {
        std::lock_guard lock{ g_mutex };
        for (const std::string& l : g_lines) {
            if (l.rfind("> grep", 0) == 0) continue;
            if (lower(l).find(want) != std::string::npos) hits.push_back(l);
        }
    }
    std::string out;
    for (const std::string& h : hits) out += (out.empty() ? "" : "\n") + h;
    print(out.empty() ? "no lines hold \"" + want + "\"" : out);
}

// The typed history, kept in console_history.txt between launches.
void save_history() {
    std::ofstream out{ app_file("console_history.txt") };
    std::lock_guard lock{ g_mutex };
    for (const std::string& h : g_history) out << h << "\n";
}

void load_history() {
    std::ifstream in{ app_file("console_history.txt") };
    std::string line;
    std::lock_guard lock{ g_mutex };
    while (std::getline(in, line)) {
        if (!trim(line).empty()) g_history.push_back(trim(line));
    }
    while (g_history.size() > kKeptHistory) g_history.erase(g_history.begin());
    g_history_pos = g_history.size();
}

void cmd_history(Ctx& c) {
    if (c.w.size() >= 2 && lower(c.w[1]) == "clear") {
        {
            std::lock_guard lock{ g_mutex };
            g_history.clear();
            g_history_pos = 0;
        }
        save_history();
        print("history cleared");
        return;
    }
    std::string out;
    {
        std::lock_guard lock{ g_mutex };
        for (const std::string& h : g_history) out += (out.empty() ? "" : "\n") + h;
    }
    print(out.empty() ? "no history" : out);
}

// open <folder>: shows one of the game's folders in the file manager.
void cmd_open(Ctx& c) {
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "";
    std::filesystem::path path;
    if (what == "config" || what == "data") path = recomp::get_config_path();
    else if (what == "game" || what == "exe" || what == "app") path = recompui::file::get_app_folder_path();
    else if (what == "mods") path = recomp::mods::get_mods_directory();
    else if (what == "saves" || what == "save") {
        path = ultramodern::get_save_file_path();
        path = path.empty() ? recomp::get_config_path() / "saves" : path.parent_path();
    }
    else if (what == "backups") path = recomp::get_config_path() / "save_backups";
    else if (what == "screenshots" || what == "shots") path = recomp::get_config_path() / "screenshots";
    else if (what == "scenarios") path = scenario_dir();
    else if (what == "inputs" || what == "recordings") path = input_dir();
    else { error("open config | game | mods | saves | backups | screenshots | scenarios | inputs"); return; }
    std::error_code ec;
    std::filesystem::create_directories(path, ec);
    // SDL_OpenURL takes UTF-8.
    const std::u8string generic = std::filesystem::absolute(path, ec).generic_u8string();
    std::string url = "file://" + std::string(generic.begin(), generic.end());
#ifdef _WIN32
    if (url.size() > 7 && url[7] != '/') url = "file:///" + url.substr(7);
#endif
    if (SDL_OpenURL(url.c_str()) != 0) { error("could not open " + tooie::path_text(path) + ": " + SDL_GetError()); return; }
    print("opened " + tooie::path_text(path));
}

// ---------------------------------------------------------------------------------------------------------------
// RAM tracing: trace prints (and can log to a file) every change in a range; memview shows a range live.

struct Trace {
    uint32_t addr;
    uint32_t bytes;           // a multiple of size
    int size;                 // 1, 2 or 4: how the range is compared and printed
    std::vector<uint32_t> last;
    FILE* file = nullptr;     // trace ... file <name>: frame,address,old,new lines
    bool quiet = false;       // trace ... quiet: only the file, nothing printed
    uint64_t changes = 0;
};
std::vector<Trace> g_traces;  // under g_mutex
constexpr int kTracePrintsPerUpdate = 16;

struct MemView { uint32_t addr; int rows; };
std::vector<MemView> g_memviews; // under g_mutex

void close_trace(Trace& t) {
    if (t.file != nullptr) {
        std::fclose(t.file);
        t.file = nullptr;
    }
}

void cmd_trace(Ctx& c) {
    const char* usage = "trace <address> [bytes] [8|16|32] [file <name>] [quiet] | trace list | trace stop <address>|all";
    std::string what = c.w.size() >= 2 ? lower(c.w[1]) : "list";
    std::lock_guard lock{ g_mutex };
    if (what == "list") {
        std::string out;
        for (const Trace& t : g_traces) {
            out += format("%s%08X, %u bytes as %d-bit, %llu changes%s", out.empty() ? "" : "\n", t.addr, t.bytes, t.size * 8,
                (unsigned long long)t.changes, t.file != nullptr ? ", to a file" : "");
        }
        print(out.empty() ? "nothing traced" : out);
        return;
    }
    if (what == "stop" || what == "off") {
        uint32_t addr = 0;
        bool all = c.w.size() >= 3 && lower(c.w[2]) == "all";
        if (!all && (c.w.size() < 3 || !parse_addr(c.w[2], &addr))) { error("trace stop <address> | trace stop all"); return; }
        size_t before = g_traces.size();
        for (Trace& t : g_traces) {
            if (all || t.addr == addr) close_trace(t);
        }
        g_traces.erase(std::remove_if(g_traces.begin(), g_traces.end(), [&](const Trace& t) { return all || t.addr == addr; }), g_traces.end());
        print(format("stopped %zu trace(s)", before - g_traces.size()));
        return;
    }
    if (c.rdram == nullptr) { error("the game has to be running"); return; }
    Trace t{};
    if (!parse_addr(c.w[1], &t.addr)) { error(usage); return; }
    t.size = 4;
    t.bytes = 0;
    std::string file_name;
    for (size_t i = 2; i < c.w.size(); i++) {
        std::string a = lower(c.w[i]);
        uint32_t n;
        if (a == "file" && i + 1 < c.w.size()) file_name = c.w[++i];
        else if (a == "quiet") t.quiet = true;
        else if (int s = parse_size(a); s != 0 && t.bytes != 0) t.size = s;
        else if (t.bytes == 0 && parse_u32(a, &n) && n > 0) t.bytes = n;
        else if (int s2 = parse_size(a); s2 != 0) t.size = s2;
        else { error(usage); return; }
    }
    if (t.bytes == 0) t.bytes = t.size;
    if (t.bytes > 0x10000) { error("at most 0x10000 bytes"); return; }
    if ((t.addr & (t.size - 1)) != 0) { error("the address must be aligned to the size"); return; }
    t.bytes = (t.bytes + t.size - 1) / t.size * t.size;
    if (t.addr + t.bytes > kRamEnd || t.addr + t.bytes < t.addr) { error("the range runs past the end of RAM"); return; }
    if (t.quiet && file_name.empty()) { error("quiet needs file <name>"); return; }
    if (!file_name.empty()) {
        std::filesystem::path path = typed_path(file_name);
        if (path.extension().empty()) path += ".csv";
        if (path.is_relative()) path = recompui::file::get_app_folder_path() / "traces" / path;
        std::error_code ec;
        std::filesystem::create_directories(path.parent_path(), ec);
        t.file = tooie::open_path(path, "w");
        if (t.file == nullptr) { error("cannot write " + tooie::path_text(path)); return; }
        std::fprintf(t.file, "update,address,old,new\n");
        print("logging to " + tooie::path_text(path));
    }
    for (uint32_t off = 0; off < t.bytes; off += t.size) t.last.push_back(read_ram(c.rdram, t.addr + off, t.size));
    for (Trace& old : g_traces) {
        if (old.addr == t.addr) close_trace(old);
    }
    g_traces.erase(std::remove_if(g_traces.begin(), g_traces.end(), [&](const Trace& o) { return o.addr == t.addr; }), g_traces.end());
    print(format("tracing %08X..%08X as %d-bit values (trace stop %08X ends it)", t.addr, t.addr + t.bytes - 1, t.size * 8, t.addr));
    g_traces.push_back(std::move(t));
}

// Every game update: compare each traced range with the last update and report what changed.
void trace_tick(uint8_t* rdram) {
    std::lock_guard lock{ g_mutex };
    if (g_traces.empty()) return;
    uint64_t frame = g_frames.load();
    int printed = 0, held_back = 0;
    std::string out;
    for (Trace& t : g_traces) {
        for (size_t i = 0; i < t.last.size(); i++) {
            uint32_t a = t.addr + (uint32_t)i * t.size;
            uint32_t now = read_ram(rdram, a, t.size);
            if (now == t.last[i]) continue;
            t.changes++;
            if (t.file != nullptr) std::fprintf(t.file, "%llu,%08X,%s,%s\n", (unsigned long long)frame, a, hex(t.last[i], t.size).c_str(), hex(now, t.size).c_str());
            if (!t.quiet) {
                if (printed < kTracePrintsPerUpdate) {
                    out += format("%s[%llu] %08X %s -> %s", out.empty() ? "" : "\n", (unsigned long long)frame, a, hex(t.last[i], t.size).c_str(), hex(now, t.size).c_str());
                    printed++;
                } else {
                    held_back++;
                }
            }
            t.last[i] = now;
        }
        if (t.file != nullptr) std::fflush(t.file);
    }
    if (held_back > 0) out += format("\n... and %d more changes this update (trace ... file <name> keeps them all)", held_back);
    if (!out.empty()) {
        g_current = "trace";
        print(out);
    }
}

// memview <address> [rows]: 16 bytes a row in the panel at the top right, updated live.
void cmd_memview(Ctx& c) {
    std::lock_guard lock{ g_mutex };
    if (c.w.size() < 2) {
        std::string out;
        for (const MemView& m : g_memviews) out += format("%s%08X, %d rows", out.empty() ? "" : "\n", m.addr, m.rows);
        print(out.empty() ? "no memview (memview <address> [rows])" : out);
        return;
    }
    if (lower(c.w[1]) == "off" || lower(c.w[1]) == "stop") {
        g_memviews.clear();
        print("memview off");
        return;
    }
    MemView m{};
    int rows = 4;
    if (!parse_addr(c.w[1], &m.addr) || (c.w.size() >= 3 && (!parse_int(c.w[2], &rows) || rows < 1))) { error("memview <address> [rows 1-16] | memview off"); return; }
    m.addr &= ~0xFu;
    m.rows = std::min(rows, 16);
    if (m.addr + m.rows * 16u > kRamEnd) { error("the range runs past the end of RAM"); return; }
    g_memviews.erase(std::remove_if(g_memviews.begin(), g_memviews.end(), [&](const MemView& o) { return o.addr == m.addr; }), g_memviews.end());
    g_memviews.push_back(m);
    print(format("showing %08X..%08X at the top right (memview off hides it)", m.addr, m.addr + m.rows * 16 - 1));
}

// ---------------------------------------------------------------------------------------------------------------
// Finding addresses: search narrows RAM down step by step (changed, increased, = 5...); ramlog counts which words
// change over a stretch of play and writes them to a file, busiest first.

struct Search {
    int size = 0;             // 1, 2, 4; 0: no search
    bool is_float = false;
    std::vector<uint32_t> addrs; // empty with `all` set: every address from `from` to `to`
    std::vector<uint32_t> values;
    bool all = false;
    uint32_t from = 0, to = 0;
    int steps = 0;
};
Search g_search;

uint32_t search_addr(size_t i) {
    return g_search.all ? g_search.from + (uint32_t)i * g_search.size : g_search.addrs[i];
}

double as_number(uint32_t v, int size, bool is_float) {
    if (is_float) {
        float f;
        std::memcpy(&f, &v, 4);
        return f;
    }
    // Bytes and halves read as unsigned (counters), words as signed.
    return size == 1 ? (double)(uint8_t)v : size == 2 ? (double)(uint16_t)v : (double)(int32_t)v;
}

std::string search_value_text(uint32_t v) {
    if (g_search.is_float) return format("%.4f", as_number(v, 4, true));
    return format("%s (%.0f)", hex(v, g_search.size).c_str(), as_number(v, g_search.size, false));
}

void cmd_search(Ctx& c) {
    const char* usage = "search start [8|16|32|f] [from] [to] | search changed|unchanged|up|down | search = <v> | != <v> | > <v> | < <v> | "
        "search up <n> | down <n> | search list [n] | search watch [n] | search trace [n] | search count";
    if (c.w.size() < 2) { error(usage); return; }
    std::string what = lower(c.w[1]);
    if (what == "start" || what == "new") {
        Search s{};
        s.size = 4;
        s.from = kRamStart;
        s.to = kFindEnd;
        size_t i = 2;
        if (i < c.w.size()) {
            std::string a = lower(c.w[i]);
            if (a == "f" || a == "float") { s.is_float = true; s.size = 4; i++; }
            else if (int z = parse_size(a)) { s.size = z; i++; }
        }
        if ((i < c.w.size() && !parse_addr(c.w[i], &s.from)) || (i + 1 < c.w.size() && !parse_addr(c.w[i + 1], &s.to)) || s.to <= s.from) { error(usage); return; }
        s.from = (s.from + s.size - 1) & ~(uint32_t)(s.size - 1);
        s.all = true;
        size_t n = (s.to - s.from) / s.size;
        s.values.resize(n);
        for (size_t k = 0; k < n; k++) s.values[k] = read_ram(c.rdram, s.from + (uint32_t)k * s.size, s.size);
        g_search = std::move(s);
        print(format("%zu %s values kept from %08X to %08X. Now change something in the game and narrow it down: search changed, "
            "search up, search = 5...", n, g_search.is_float ? "float" : (std::to_string(g_search.size * 8) + "-bit").c_str(), g_search.from, g_search.to));
        return;
    }
    if (g_search.size == 0) { error("no search yet (search start [8|16|32|f])"); return; }
    size_t count = g_search.all ? g_search.values.size() : g_search.addrs.size();
    if (what == "count") { print(format("%zu left after %d steps", count, g_search.steps)); return; }
    if (what == "list" || what == "watch" || what == "trace") {
        int n = what == "list" ? 32 : 8;
        if (c.w.size() >= 3 && (!parse_int(c.w[2], &n) || n < 1)) { error(usage); return; }
        if (what != "list" && n > 32) { error(what + " takes at most 32 addresses at once"); return; }
        if (g_search.all && count > 100000) { error(format("%zu left; narrow it down first", count)); return; }
        std::string out = format("%zu left", count);
        for (size_t i = 0; i < count && (int)i < n; i++) {
            uint32_t a = search_addr(i);
            uint32_t v = read_ram(c.rdram, a, g_search.size);
            out += format("\n%08X: %s", a, search_value_text(v).c_str());
            if (what == "watch") enqueue_line(format("watch %08X %s", a, g_search.is_float ? "f" : std::to_string(g_search.size * 8).c_str()), c.depth + 1);
            if (what == "trace") enqueue_line(format("trace %08X %d %d", a, g_search.size, g_search.size * 8), c.depth + 1);
        }
        if ((size_t)n < count) out += "\n...";
        print(out);
        return;
    }
    // A filter: keep the addresses whose value now passes it, and keep the value they have now for the next step.
    std::function<bool(double old_v, double now_v, uint32_t old_raw, uint32_t now_raw)> keep;
    double arg = 0;
    bool has_arg = c.w.size() >= 3;
    if (has_arg) {
        uint32_t raw;
        bool is_hex = c.w[2].size() > 2 && c.w[2][0] == '0' && (c.w[2][1] == 'x' || c.w[2][1] == 'X');
        if (is_hex && !g_search.is_float && parse_u32(c.w[2], &raw)) arg = as_number(raw, g_search.size, false);
        else if (!parse_double(c.w[2], &arg)) { error(usage); return; }
    }
    const double eps = 1e-4;
    if (what == "changed" || what == "ch") keep = [](double, double, uint32_t o, uint32_t n) { return o != n; };
    else if (what == "unchanged" || what == "same") keep = [](double, double, uint32_t o, uint32_t n) { return o == n; };
    else if ((what == "up" || what == "increased" || what == "inc") && !has_arg) keep = [](double o, double n, uint32_t, uint32_t) { return n > o; };
    else if ((what == "down" || what == "decreased" || what == "dec") && !has_arg) keep = [](double o, double n, uint32_t, uint32_t) { return n < o; };
    else if (what == "up" || what == "increased" || what == "inc") keep = [arg, eps](double o, double n, uint32_t, uint32_t) { return std::fabs((n - o) - arg) < eps; };
    else if (what == "down" || what == "decreased" || what == "dec") keep = [arg, eps](double o, double n, uint32_t, uint32_t) { return std::fabs((o - n) - arg) < eps; };
    else if ((what == "=" || what == "==" || what == "eq") && has_arg) keep = [arg, eps](double, double n, uint32_t, uint32_t) { return std::fabs(n - arg) < eps; };
    else if ((what == "!=" || what == "ne") && has_arg) keep = [arg, eps](double, double n, uint32_t, uint32_t) { return std::fabs(n - arg) >= eps; };
    else if ((what == ">" || what == "gt") && has_arg) keep = [arg](double, double n, uint32_t, uint32_t) { return n > arg; };
    else if ((what == "<" || what == "lt") && has_arg) keep = [arg](double, double n, uint32_t, uint32_t) { return n < arg; };
    else { error(usage); return; }
    std::vector<uint32_t> addrs, values;
    for (size_t i = 0; i < count; i++) {
        uint32_t a = search_addr(i);
        uint32_t now = read_ram(c.rdram, a, g_search.size);
        uint32_t old = g_search.values[i];
        if (keep(as_number(old, g_search.size, g_search.is_float), as_number(now, g_search.size, g_search.is_float), old, now)) {
            addrs.push_back(a);
            values.push_back(now);
        }
    }
    g_search.all = false;
    g_search.addrs = std::move(addrs);
    g_search.values = std::move(values);
    g_search.steps++;
    std::string out = format("%zu left (from %zu)", g_search.addrs.size(), count);
    for (size_t i = 0; i < g_search.addrs.size() && i < 8; i++) out += format("\n%08X: %s", g_search.addrs[i], search_value_text(g_search.values[i]).c_str());
    if (g_search.addrs.size() > 8) out += "\n... (search list shows more)";
    print(out);
}

// ramlog <seconds> [from] [to]: counts how often each word changes, then writes ramlog-<time>.csv in the game folder.
struct RamLog {
    bool on = false;
    uint32_t from = 0, to = 0;
    Clock::time_point until;
    uint64_t updates = 0;
    std::vector<uint32_t> first, last, changes;
};
RamLog g_ramlog;

void finish_ramlog() {
    g_ramlog.on = false;
    std::vector<size_t> order;
    for (size_t i = 0; i < g_ramlog.changes.size(); i++) {
        if (g_ramlog.changes[i] != 0) order.push_back(i);
    }
    std::stable_sort(order.begin(), order.end(), [](size_t a, size_t b) { return g_ramlog.changes[a] > g_ramlog.changes[b]; });
    std::time_t t = std::time(nullptr);
    char stamp[32];
    std::strftime(stamp, sizeof(stamp), "%Y-%m-%d_%H-%M-%S", std::localtime(&t));
    std::filesystem::path path = recompui::file::get_app_folder_path() / "traces" / (std::string("ramlog-") + stamp + ".csv");
    std::error_code ec;
    std::filesystem::create_directories(path.parent_path(), ec);
    FILE* f = tooie::open_path(path, "w");
    if (f != nullptr) {
        std::fprintf(f, "address,changes,of_updates,first,last\n");
        for (size_t i : order) {
            std::fprintf(f, "%08X,%u,%llu,%08X,%08X\n", g_ramlog.from + (uint32_t)i * 4, g_ramlog.changes[i], (unsigned long long)g_ramlog.updates, g_ramlog.first[i], g_ramlog.last[i]);
        }
        std::fclose(f);
    }
    std::string out = format("ramlog: %zu words changed in %llu updates", order.size(), (unsigned long long)g_ramlog.updates);
    out += f != nullptr ? ", all in " + tooie::path_text(path) : ", but " + tooie::path_text(path) + " could not be written";
    // The quietest words that changed are often the ones a single event touched; the busiest are timers and the like.
    auto line = [&](size_t i) {
        out += format("\n%08X changed %u times: %08X -> %08X", g_ramlog.from + (uint32_t)i * 4, g_ramlog.changes[i], g_ramlog.first[i], g_ramlog.last[i]);
    };
    if (!order.empty()) out += "\nbusiest:";
    for (size_t k = 0; k < order.size() && k < 8; k++) line(order[k]);
    if (order.size() > 16) {
        out += "\nquietest (changed once or a few times):";
        for (size_t k = order.size() - 8; k < order.size(); k++) line(order[k]);
    }
    g_ramlog.first.clear(); g_ramlog.last.clear(); g_ramlog.changes.clear();
    g_ramlog.first.shrink_to_fit(); g_ramlog.last.shrink_to_fit(); g_ramlog.changes.shrink_to_fit();
    {
        std::lock_guard lock{ g_mutex };
        g_current = "ramlog";
    }
    print(out);
}

void ramlog_tick(uint8_t* rdram) {
    if (!g_ramlog.on) return;
    g_ramlog.updates++;
    for (size_t i = 0; i < g_ramlog.last.size(); i++) {
        uint32_t v = read_ram(rdram, g_ramlog.from + (uint32_t)i * 4, 4);
        if (v != g_ramlog.last[i]) {
            g_ramlog.last[i] = v;
            g_ramlog.changes[i]++;
        }
    }
    if (Clock::now() >= g_ramlog.until) finish_ramlog();
}

void cmd_ramlog(Ctx& c) {
    const char* usage = "ramlog <seconds> [from] [to] | ramlog stop";
    if (c.w.size() >= 2 && lower(c.w[1]) == "stop") {
        if (!g_ramlog.on) { error("no ramlog is running"); return; }
        finish_ramlog();
        return;
    }
    double seconds;
    uint32_t from = kRamStart, to = 0x80800000;
    if (c.w.size() < 2 || !parse_double(c.w[1], &seconds) || seconds <= 0 || (c.w.size() >= 3 && !parse_addr(c.w[2], &from)) ||
        (c.w.size() >= 4 && !parse_addr(c.w[3], &to)) || to <= from) { error(usage); return; }
    if (g_ramlog.on) { error("a ramlog is running (ramlog stop)"); return; }
    from &= ~3u;
    size_t n = (to - from) / 4;
    g_ramlog.from = from;
    g_ramlog.to = to;
    g_ramlog.updates = 0;
    g_ramlog.first.resize(n);
    for (size_t i = 0; i < n; i++) g_ramlog.first[i] = read_ram(c.rdram, from + (uint32_t)i * 4, 4);
    g_ramlog.last = g_ramlog.first;
    g_ramlog.changes.assign(n, 0);
    g_ramlog.until = Clock::now() + std::chrono::microseconds((int64_t)(seconds * 1e6));
    g_ramlog.on = true;
    print(format("logging %08X..%08X for %.1f s (it can slow the game a little; ramlog stop ends it early)", from, to - 1, seconds));
}

const std::vector<Command>& commands() {
    static const std::vector<Command> list = {
        { "help", { "?" }, false, "help [command]", "list the commands, or one command's use", cmd_help },
        { "start", {}, false, "start", "press Play in the launcher", cmd_start },
        { "load", {}, false, "load [file 1-3] [timeout s]", "from the launcher, title or file select into a save file with no hands (holds the queue until it is loaded; 60 s)", cmd_load },
        { "goload", {}, false, "goload <file 1-3> <map hex> [exit hex]", "load a save file, warp to a map and wait for it, in one line", cmd_goload },
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
        { "walkto", { "walk" }, true, "walkto <x> <z> [radius] [timeout s]", "walk Banjo to a point with controller 1's stick, the way the camera faces (holds the queue; radius 30, 10 s)", cmd_walkto },
        { "face", {}, true, "face <x> <z>", "turn Banjo to face a point", cmd_face },
        { "look", {}, true, "look <yaw deg> [pitch deg] [distance] | look at <x> <y> <z> [distance] | look here <yaw> [pitch] | look here at <x> <y> <z> | look off", "hold the gameplay camera looking at Banjo from a direction, 350 back (here: turn it where it stands), for screenshots; a map change ends it", cmd_look },
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
        { "jiggies", { "jiggy" }, true, "jiggies [n]", "the Jiggies the game counts for Jiggywiggy, or set Jiggy flags until it counts at least n (saving keeps them)", cmd_jiggies },
        { "challenge", {}, true, "challenge [n]", "Jiggywiggy's challenges done (0 to 11), so challenge n + 1 is next (flags 0x35C; saving keeps it)", cmd_challenge },
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
        { "burst", {}, true, "burst start | burst stop", "keep every frame from start to stop and save them, as F12 held does", cmd_burst },
        { "costcheck", { "cost" }, true, "costcheck", "start or stop the Effect Cost Check (GPU time of each effect that is on)", cmd_costcheck },
        { "press", {}, true, "press <buttons> [stick <x> <y>] [frames|n ms|n s]", "hold controller 1's buttons (a+b) and stick (-80..80), for n game updates, a time, or until release", cmd_press },
        { "release", {}, false, "release", "let go of what press holds", cmd_release },
        { "mouse", {}, true, "mouse move <dx> <dy> [n ms|n s] | mouse stop", "move the mouse by dx, dy pixels (right and down positive), at once or spread over a time, as the window's own mouse motion", cmd_mouse },
        { "wait", {}, false, "wait <frames|n ms|n s|save|control|map <hex>|until <addr> <value>>", "hold the next commands (frames are game updates; save, control, map and until wait for a state)", cmd_wait },
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
        { "search", { "ramsearch", "s" }, true, "search start [8|16|32|f] [from] [to] | search changed|unchanged|up|down|= v|!= v|> v|< v | search up|down <n> | search list|watch|trace [n] | search count", "find an unknown address: keep RAM, change something in the game, keep only what changed the same way, repeat", cmd_search },
        { "ramlog", {}, true, "ramlog <seconds> [from] [to] | ramlog stop", "count which RAM words change while you play, then write traces/ramlog-<time>.csv busiest first", cmd_ramlog },
        { "trace", {}, false, "trace <address> [bytes] [8|16|32] [file <name>] [quiet] | trace list | trace stop <address>|all", "print every change in a RAM range as it happens (file keeps them in traces/<name>.csv)", cmd_trace },
        { "memview", { "hexview", "mv" }, false, "memview <address> [rows] | memview off", "a live hex view of RAM at the top right, 16 bytes a row", cmd_memview },
        { "mark", {}, false, "mark <name> | mark list | mark delete <name>", "keep Banjo's map and position under a name (marks.txt)", cmd_mark },
        { "recall", {}, true, "recall <name>", "go back to a mark: warps first when it is in another map", cmd_recall },
        { "scenario", { "sc" }, false, "scenario <name> | scenario list | scenario save <name> | scenario delete <name>", "set up a test in one word: runs scenarios/<name>.txt; save writes one from the map, position and items now", cmd_scenario },
        { "record", {}, false, "record <name> | record stop | record list", "record controller 1 into inputs/<name>.txt", cmd_record },
        { "play", {}, true, "play <name> | play stop", "play a recording back as controller 1", cmd_play },
        { "input", {}, true, "input", "the buttons and stick the game got last", cmd_input },
        { "timer", {}, false, "timer start | timer stop | timer show", "a stopwatch that splits on every map change", cmd_timer },
        { "autoexec", {}, false, "autoexec [run]", "where autoexec.txt is (its commands run at every start)", cmd_autoexec },
        { "grep", {}, false, "grep <text>", "the console lines that hold some text", cmd_grep },
        { "history", {}, false, "history [clear]", "the commands you typed (kept between launches)", cmd_history },
        { "open", {}, false, "open <config|game|mods|saves|backups|screenshots|scenarios|inputs>", "show a folder in the file manager", cmd_open },
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
        save_history();
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
            for (const MemView& m : g_memviews) {
                for (int r = 0; r < m.rows; r++) {
                    uint32_t row = m.addr + r * 16;
                    std::string line = format("%08X ", row);
                    for (int k = 0; k < 16; k += 4) line += format(" %08X", read_ram(rdram, row + k, 4));
                    lines.push_back(line);
                }
            }
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
    load_history();
    {
        std::error_code ec;
        if (std::filesystem::exists(app_file("autoexec.txt"), ec)) enqueue_line("exec " + tooie::path_text(app_file("autoexec.txt")));
    }
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
        end_timed_press();
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
    drive_tick(rdram);
    pump(rdram, ctx);
    look_tick(rdram);
    mouse_tick();
    time_tick(rdram);
    timer_tick(rdram);
    trace_tick(rdram);
    ramlog_tick(rdram);
    bool play_ended = false;
    {
        std::lock_guard lock{ g_input_mutex };
        if (g_playing && frame >= g_play_start && frame - g_play_start > g_play.back().frame) {
            g_playing = false;
            play_ended = true;
        }
    }
    if (play_ended) {
        {
            std::lock_guard lock{ g_mutex };
            g_current = "play";
        }
        print("playback finished");
    }
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
    uint64_t now = g_frames.load();
    if (g_playing && now >= g_play_start) {
        // The last recorded update at or before this one (input is read more often than the game updates).
        uint64_t at = now - g_play_start;
        while (g_play_at + 1 < g_play.size() && g_play[g_play_at + 1].frame <= at) g_play_at++;
        const InputFrame& f = g_play[g_play_at];
        if (f.frame <= at) {
            *buttons = f.buttons;
            *x = f.x;
            *y = f.y;
            got = true;
        }
    }
    end_timed_press();
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
    g_last_input = { now, got ? *buttons : (uint16_t)0, got ? *x : 0.0f, got ? *y : 0.0f, got };
    if (g_recording && now >= g_rec_start) {
        // One entry per game update: the last read in an update wins.
        InputFrame f = g_last_input;
        f.frame = now - g_rec_start;
        if (!g_rec.empty() && g_rec.back().frame == f.frame) g_rec.back() = f;
        else g_rec.push_back(f);
    }
    return got;
}
