// Translations of the game's own text: General tab > Language, and the `language` console command.
//
// Every piece of the game's text (dialogue, menus, level names, signs) is a text asset (kind 3) in the ROM's asset
// table. A text asset starts with a language count and one 16-bit little-endian offset per language; the US ROM has
// one language, so the bytes are 01 03 00 and then the English section. A section is a run of groups, each a count and
// then that many entries; an entry is a command byte, one more byte when the command is 3 (who speaks), a length byte
// and that many bytes. Commands 3 and 0x80 and up are text, a line ending in a 0 byte; the rest steer the conversation
// (camera, choices, sounds). Checked against every text asset in the US ROM: they all parse to the end with this.
//
// A translation file lists the English lines' replacements asset by asset, in the order the lines come in the asset
// (docs/translations.md). The game's text is never copied into the program: `language export` writes the English
// from the player's own ROM for translators, and a translation file holds only the translators' own lines. When the
// game loads a text asset (the asset hook in asset_mods.cpp), the asset is rebuilt from the ROM's with the translated
// lines in place of the English ones and each entry's length set to its new line.
//
// The game's text is all capitals; byte values from '[' to 'x' are its codes for accented capitals (the codes the
// European game uses, drawn by glyphs the dialogue font already has), and 'y', 'z' and 0x7B are Æ, Ø and Å, whose
// glyphs language_font.cpp adds. A translation file is written with the real letters: they are turned into these codes,
// lowercase into capitals, and the export turns the codes back. A {XX} escape puts a byte in as it is.

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <map>
#include <mutex>
#include <set>
#include <sstream>
#include <variant>

#include "librecomp/config.hpp"
#include "librecomp/game.hpp"
#include "librecomp/mods.hpp"
#include <json/json.hpp>
#include "recompui/config.h"
#include "util/file.h"
#include "recompui/recompui.h"
#include "miniz.h"
#include <thread>

#include "tooie_achievements.h"
#include "tooie_asset_mods.h"
#include "tooie_language.h"
#include "tooie_toast.h"

namespace fs = std::filesystem;

namespace {
    constexpr int kind_text = 3;
    // A length byte counts the line and its closing 0 byte.
    constexpr size_t max_line = 254;

    struct Entry {
        uint8_t cmd;
        int speaker;  // the extra byte of command 3, -1 for none
        std::vector<uint8_t> data;
    };
    using Group = std::vector<Entry>;

    bool is_text(uint8_t cmd) {
        return cmd == 3 || cmd >= 0x80;
    }

    bool parse_section(const uint8_t* s, size_t size, std::vector<Group>& groups) {
        size_t i = 0;
        while (i < size) {
            Group group;
            const uint8_t count = s[i++];
            for (uint8_t n = 0; n < count; n++) {
                if (i >= size) return false;
                Entry e{ s[i++], -1, {} };
                if (e.cmd == 3) {
                    if (i >= size) return false;
                    e.speaker = s[i++];
                }
                if (i >= size) return false;
                const uint8_t len = s[i++];
                if (i + len > size) return false;
                e.data.assign(s + i, s + i + len);
                i += len;
                group.push_back(std::move(e));
            }
            groups.push_back(std::move(group));
        }
        return true;
    }

    std::vector<uint8_t> write_asset(const std::vector<Group>& groups) {
        std::vector<uint8_t> out = { 1, 3, 0 };
        for (const Group& group : groups) {
            out.push_back((uint8_t)group.size());
            for (const Entry& e : group) {
                out.push_back(e.cmd);
                if (e.speaker >= 0) out.push_back((uint8_t)e.speaker);
                out.push_back((uint8_t)e.data.size());
                out.insert(out.end(), e.data.begin(), e.data.end());
            }
        }
        return out;
    }

    // The English section of a US text asset. False when the bytes are not a one-language text asset.
    bool english_groups(const std::vector<uint8_t>& asset, std::vector<Group>& groups) {
        if (asset.size() < 3 || asset[0] != 1 || asset[1] != 3 || asset[2] != 0) return false;
        return parse_section(asset.data() + 3, asset.size() - 3, groups);
    }

    // ---- Line text <-> game bytes ----

    std::string hex2(uint8_t b) {
        char buf[8];
        snprintf(buf, sizeof(buf), "{%02X}", b);
        return buf;
    }

    // The game's codes for the accented capitals and signs the fonts can draw, and the letters they stand for.
    // (0x6A and 0x71 are a second Ü and Ù glyph; the file writes them as {6A} and {71}.)
    const std::map<uint8_t, uint32_t>& code_letters() {
        static const std::map<uint8_t, uint32_t> map = {
            {0x5B, 0xC4 /* Ä */}, {0x5C, 0xD6 /* Ö */}, {0x5D, 0xDC /* Ü */}, {0x5E, 0xDF /* ß */}, {0x5F, 0xC0 /* À */},
            {0x60, 0xC2 /* Â */}, {0x61, 0xC7 /* Ç */}, {0x62, 0xC9 /* É */}, {0x63, 0xC8 /* È */}, {0x64, 0xCA /* Ê */},
            {0x65, 0xCB /* Ë */}, {0x66, 0xCE /* Î */}, {0x67, 0xCF /* Ï */}, {0x68, 0xD4 /* Ô */}, {0x69, 0xDB /* Û */},
            {0x6B, 0xD9 /* Ù */}, {0x6C, 0xCC /* Ì */}, {0x6D, 0xCD /* Í */}, {0x6E, 0xD3 /* Ó */}, {0x6F, 0xD2 /* Ò */},
            {0x70, 0xDA /* Ú */}, {0x72, 0xD1 /* Ñ */}, {0x73, 0xC1 /* Á */}, {0x74, 0xA1 /* ¡ */}, {0x75, 0xBF /* ¿ */},
            {0x76, 0xAA /* ª */}, {0x77, 0xBA /* º */}, {0x78, 0xA9 /* © */}, {0x79, 0xC6 /* Æ */}, {0x7A, 0xD8 /* Ø */},
            {0x7B, 0xC5 /* Å */},
        };
        return map;
    }

    std::string utf8(uint32_t cp) {
        std::string s;
        if (cp < 0x80) {
            s += (char)cp;
        } else if (cp < 0x800) {
            s += (char)(0xC0 | (cp >> 6));
            s += (char)(0x80 | (cp & 0x3F));
        } else {
            s += (char)(0xE0 | (cp >> 12));
            s += (char)(0x80 | ((cp >> 6) & 0x3F));
            s += (char)(0x80 | (cp & 0x3F));
        }
        return s;
    }

    // Unicode letters and signs as game bytes: the accented capitals (and their lowercase) as the game's codes, and the
    // few the fonts have no glyph for (Ã, Õ, Ý, Œ, curly quotes...) as the nearest the fonts can draw.
    const std::map<uint32_t, std::string>& letter_codes() {
        static const std::map<uint32_t, std::string> map = [] {
            std::map<uint32_t, std::string> m;
            // Æ, Ø and Å have glyphs only in a dialogue font the player supplied (language_font.cpp); without one
            // they are written as AE, O and A.
            if (!tooie::language::dialogue_font_supplied()) {
                for (const auto& [cp, text] : { std::pair<uint32_t, const char*>{0xC6, "AE"}, {0xE6, "AE"}, {0xD8, "O"}, {0xF8, "O"}, {0xC5, "A"}, {0xE5, "A"} }) {
                    m[cp] = text;
                }
            }
            for (const auto& [code, cp] : code_letters()) {
                m.try_emplace(cp, std::string(1, (char)code));
                if (cp >= 0xC0 && cp <= 0xDE) m.try_emplace(cp + 0x20, std::string(1, (char)code));  // its lowercase
            }
            const std::pair<uint32_t, const char*> nearest[] = {
                {0xC3, "A"}, {0xE3, "A"}, {0xD5, "O"}, {0xF5, "O"}, {0xDD, "Y"}, {0xFD, "Y"}, {0xFF, "Y"}, {0x152, "OE"},
                {0x153, "OE"}, {0xAB, "\""}, {0xBB, "\""}, {0x2018, "'"}, {0x2019, "'"}, {0x201C, "\""}, {0x201D, "\""},
                {0x2026, "..."}, {0x2013, "-"}, {0x2014, "-"},
            };
            for (const auto& [cp, text] : nearest) m.try_emplace(cp, text);
            return m;
        }();
        return map;
    }

    // A line of game text as the file writes it.
    std::string line_to_file(const std::vector<uint8_t>& data) {
        std::string out;
        size_t end = data.size();
        if (end > 0 && data[end - 1] == 0) end--;
        if (end == 0) {
            return "{}";  // an empty line, so it can't be taken for spacing
        }
        for (size_t i = 0; i < end; i++) {
            const uint8_t b = data[i];
            auto letter = code_letters().find(b);
            if (letter != code_letters().end()) {
                out += utf8(letter->second);  // an accented capital or sign (the game's x is ©)
            } else if (b >= 0x20 && b < 0x7F && b != '{' && b != '}' && !(b >= 'a' && b <= 'z') && !(i == 0 && (b == '#' || b == '='))) {
                out += (char)b;
            } else {
                out += hex2(b);
            }
        }
        return out;
    }

    // A line from a translation file as game bytes, with its closing 0. Counts what had to be changed in `odd`.
    std::vector<uint8_t> line_from_file(const std::string& line, size_t* odd) {
        std::vector<uint8_t> out;
        if (line == "{}") {
            return { 0 };  // an empty line of text
        }
        size_t i = 0;
        while (i < line.size()) {
            const uint8_t c = (uint8_t)line[i];
            if (c == '{') {
                const size_t close = line.find('}', i);
                unsigned value = 0;
                if (close == i + 3 && std::sscanf(line.c_str() + i + 1, "%2x", &value) == 1) {
                    out.push_back((uint8_t)value);
                    i = close + 1;
                    continue;
                }
                (*odd)++;
                i++;
                continue;
            }
            if (c < 0x80) {
                out.push_back((uint8_t)std::toupper(c));
                i++;
                continue;
            }
            // UTF-8.
            uint32_t cp = 0;
            size_t extra = 0;
            if ((c & 0xE0) == 0xC0) { cp = c & 0x1F; extra = 1; }
            else if ((c & 0xF0) == 0xE0) { cp = c & 0x0F; extra = 2; }
            else if ((c & 0xF8) == 0xF0) { cp = c & 0x07; extra = 3; }
            else { (*odd)++; i++; continue; }
            if (i + extra >= line.size()) { (*odd)++; break; }
            for (size_t k = 1; k <= extra; k++) cp = (cp << 6) | ((uint8_t)line[i + k] & 0x3F);
            i += extra + 1;
            auto found = letter_codes().find(cp);
            if (found != letter_codes().end()) {
                out.insert(out.end(), found->second.begin(), found->second.end());
            } else {
                out.push_back('?');
                (*odd)++;
            }
        }
        if (out.size() > max_line) {
            out.resize(max_line);
            (*odd)++;
        }
        out.push_back(0);
        return out;
    }

    // ---- Translation files ----

    struct Translation {
        std::string key;
        std::string name;
        fs::path path;
        std::map<uint32_t, std::vector<std::string>> lines;
        std::map<std::string, std::string> port;  // the `=== port` section: the port's own text by key
        int european = 0;  // @game european N: the game's text is section N of the player's European copy
    };

    fs::path shipped_folder() {
        return recompui::file::get_asset_path("translations");
    }

    // Capitals for a choice's name. The menu shows choices in capitals, but its capitalising only knows A-Z, so a
    // translated choice showed "på" as "På"; the Latin letters with accents (à-þ, but not ÷) are made capitals here.
    std::string upper_latin(const std::string& text) {
        std::string out;
        for (size_t i = 0; i < text.size(); i++) {
            const unsigned char c = (unsigned char)text[i];
            if (c >= 'a' && c <= 'z') {
                out += (char)(c - 0x20);
            } else if (c == 0xC3 && i + 1 < text.size()) {
                unsigned char next = (unsigned char)text[i + 1];
                if (next >= 0xA0 && next <= 0xBE && next != 0xB7) next = (unsigned char)(next - 0x20);
                out += (char)c;
                out += (char)next;
                i++;
            } else {
                out += (char)c;
            }
        }
        return out;
    }

    std::string lower(std::string s) {
        for (char& c : s) c = (char)std::tolower((unsigned char)c);
        return s;
    }

    std::string trim(const std::string& s) {
        size_t a = s.find_first_not_of(" \t");
        size_t b = s.find_last_not_of(" \t");
        return a == std::string::npos ? std::string() : s.substr(a, b - a + 1);
    }

    std::vector<std::string> read_lines(const fs::path& path) {
        std::ifstream in(path, std::ios::binary);
        std::vector<std::string> lines;
        std::string line;
        bool first = true;
        while (std::getline(in, line)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();
            if (first && line.rfind("\xEF\xBB\xBF", 0) == 0) line.erase(0, 3);
            first = false;
            lines.push_back(std::move(line));
        }
        return lines;
    }

    // "@name Français" near the top of a file, else the file name.
    // A header field ("@name Français") of a translation file, or empty.
    std::string header_field(const fs::path& path, const char* field) {
        const std::string tag = std::string(field) + " ";
        for (const std::string& line : read_lines(path)) {
            if (line.rfind("===", 0) == 0) break;
            if (line.rfind(tag, 0) == 0) return trim(line.substr(tag.size()));
        }
        return {};
    }

    // Whether a header line starts with `field` ("@default" on its own).
    bool header_field_present(const fs::path& path, const char* field) {
        for (const std::string& line : read_lines(path)) {
            if (line.rfind("===", 0) == 0) break;
            if (trim(line) == field) return true;
        }
        return false;
    }

    std::string file_display_name(const fs::path& path) {
        std::string name = header_field(path, "@name");
        if (!name.empty()) return name;
        const std::u8string stem = path.stem().u8string();
        return std::string(stem.begin(), stem.end());
    }

    // Language mods that are on: mod id -> its translations/ folder. Guarded by `mutex` (below).
    std::map<std::string, fs::path> mod_folders;

    nlohmann::json read_json(const fs::path& path) {
        std::ifstream in(path, std::ios::binary);
        if (!in) return nlohmann::json();
        return nlohmann::json::parse(in, nullptr, false);
    }

    // At start, before the mod loader runs: the language mods in the mods folder that mods.json (the loader's own
    // record of the Mods menu) says are on, so their languages are in the Language setting from the start. The
    // loader then switches the same mods on through enable_mod.
    void find_enabled_mods_at_start() {
        std::set<std::string> enabled;
        nlohmann::json config = read_json(recomp::get_config_path() / "mods.json");
        if (config.is_object() && config.contains("enabled_mods") && config["enabled_mods"].is_array()) {
            for (const auto& id : config["enabled_mods"]) {
                if (id.is_string()) enabled.insert(id.get<std::string>());
            }
        }
        std::error_code ec;
        for (const auto& entry : fs::directory_iterator(recomp::mods::get_mods_directory(), ec)) {
            if (!entry.is_directory(ec) || !fs::exists(entry.path() / "translations.json", ec)) continue;
            nlohmann::json manifest = read_json(entry.path() / "mod.json");
            if (!manifest.is_object() || !manifest.contains("id") || !manifest["id"].is_string()) continue;
            const std::string id = manifest["id"].get<std::string>();
            if (enabled.contains(id)) mod_folders[id] = entry.path() / "translations";
        }
    }

    // key -> file: the shipped files first, then the language mods that are on, then the player's; a later one wins.
    std::map<std::string, fs::path> find_files() {
        std::map<std::string, fs::path> files;
        std::vector<fs::path> folders = { shipped_folder() };
        for (const auto& [id, folder] : mod_folders) folders.push_back(folder);
        folders.push_back(tooie::language::user_folder());
        for (const fs::path& folder : folders) {
            std::error_code ec;
            for (const auto& entry : fs::directory_iterator(folder, ec)) {
                if (!entry.is_regular_file(ec) || lower(entry.path().extension().string()) != ".txt") continue;
                const std::u8string stem = entry.path().stem().u8string();
                std::string key = lower(std::string(stem.begin(), stem.end()));
                if (key == "english") continue;
                files[key] = entry.path();
            }
        }
        return files;
    }

    // A language's flag: <key>.svg beside its translation file (the player's folder first), as a path from the assets
    // folder, the way the menus' pictures are given. Empty when there is none.
    std::string flag_for(const std::string& key, const fs::path& file) {
        std::vector<fs::path> candidates;
        if (!file.empty()) candidates.push_back(fs::path(file).replace_extension(".svg"));
        candidates.push_back(tooie::language::user_folder() / (key + ".svg"));
        for (const auto& [id, folder] : mod_folders) candidates.push_back(folder / (key + ".svg"));
        candidates.push_back(shipped_folder() / (key + ".svg"));
        for (const fs::path& svg : candidates) {
            std::error_code ec;
            if (!fs::exists(svg, ec)) continue;
            fs::path rel = fs::relative(fs::absolute(svg, ec), fs::absolute(recompui::file::get_asset_path(""), ec), ec);
            // A flag on another drive than the assets (a mod's, in the app-data folder) has no relative path: it
            // is given whole.
            if (ec || rel.empty()) rel = fs::absolute(svg, ec);
            if (ec || rel.empty()) continue;
            const std::u8string text = rel.generic_u8string();
            return std::string(text.begin(), text.end());
        }
        return {};
    }

    bool load_translation(Translation& t) {
        t.lines.clear();
        t.port.clear();
        std::error_code ec;
        if (!fs::exists(t.path, ec)) return false;
        std::vector<std::string>* current = nullptr;
        bool in_port = false;
        t.european = 0;
        for (const std::string& line : read_lines(t.path)) {
            if (line.rfind("@game european ", 0) == 0) {
                t.european = std::atoi(line.c_str() + 15);
                continue;
            }
            if (line.rfind("===", 0) == 0) {
                unsigned id = 0;
                in_port = trim(line.substr(3)) == "port" || trim(line.substr(3)) == "settings";
                if (in_port) {
                    current = nullptr;
                } else if (std::sscanf(line.c_str() + 3, " %x", &id) == 1) {
                    current = &t.lines[id];
                } else {
                    current = nullptr;
                }
                continue;
            }
            if (in_port) {
                const size_t eq = line.find('=');
                if (line.rfind("#", 0) != 0 && eq != std::string::npos) t.port[trim(line.substr(0, eq))] = trim(line.substr(eq + 1));
                continue;
            }
            if (current == nullptr || line.rfind("#", 0) == 0) continue;
            current->push_back(line);
        }
        // Blank lines at the end of an asset are spacing, not empty lines of text.
        for (auto& [id, lines] : t.lines) {
            while (!lines.empty() && trim(lines.back()).empty()) lines.pop_back();
        }
        return true;
    }

    // Every piece of the port's own text a translation can replace, with its English, in the order `language export`
    // writes them. The achievements' names and descriptions come from achievements.cpp.
    std::vector<std::pair<std::string, std::string>> port_strings() {
        std::vector<std::pair<std::string, std::string>> list = {
            {"popup.european.title", "European copy needed"},
            {"popup.european.text", "Rare's French, German and Spanish text is read from your own copy of the European (PAL) Banjo-Tooie. Browse to the ROM file to use it; it is kept for next time."},
            {"popup.european.browse", "Browse"},
            {"popup.european.exit", "Exit"},
            {"popup.european.bad", "Can't use that file"},
            {"language.official", "Official"},
            {"pause.achievements", "ACHIEVEMENTS"},
            {"pause.settings", "SETTINGS"},
            {"achievements.popup", "ACHIEVEMENT UNLOCKED"},
            {"achievements.unlocked", "UNLOCKED"},
            {"achievements.locked", "LOCKED"},
            {"achievements.of", "OF"},
            {"totals.left_here", "LEFT HERE"},
            {"totals.left_in_game", "LEFT IN GAME"},
            {"totals.now", "NOW"},
            {"totals.done", "DONE"},
            {"totals.none_here", "NONE HERE"},
            {"totals.new_world_ready", "NEW WORLD READY"},
            {"totals.all_done_here", "ALL DONE HERE"},
            {"totals.more_to_get_here", "MORE TO GET HERE"},
            {"totals.move_on_for_now", "MOVE ON FOR NOW"},
            {"totals.get_now", "GET NOW"},
            {"totals.later", "LATER"},
            {"totals.jiggies", "JIGGIES"},
            {"totals.honeycombs", "HONEYCOMBS"},
            {"totals.pages", "PAGES"},
            {"totals.glowbos", "GLOWBOS"},
            {"totals.notes", "NOTES"},
            {"totals.jinjos", "JINJOS"},
            {"totals.moves", "MOVES"},
        };
        // Notices (src/ui/toast.cpp): the whole notice, or the start of one that goes on with a name or number.
        const std::pair<const char*, const char*> notices[] = {
            {"toast.Screenshot saved", "Screenshot saved"},
            {"toast.Screenshot not saved", "Screenshot not saved"},
            {"toast.Game saved", "Game saved"},
            {"toast.State saved", "State saved"},
            {"toast.State loaded", "State loaded"},
            {"toast.No saved state yet", "No saved state yet"},
            {"toast.Save states work in a level", "Save states work in a level"},
            {"toast.Couldn't save the state here", "Couldn't save the state here"},
            {"toast.Couldn't load the state here", "Couldn't load the state here"},
            {"toast.Couldn't load the state: the way back to its area was interrupted", "Couldn't load the state: the way back to its area was interrupted"},
            {"toast.Cutscene skipped", "Cutscene skipped"},
            {"toast.Photo mode off", "Photo mode off"},
            {"toast.Photo mode: A photo, B back, L shows the list", "Photo mode: A photo, B back, L shows the list"},
            {"toast.Photo in", "Photo in"},
            {"toast.Burst saved:", "Burst saved:"},
            {"toast.Burst: let go of F12 after the glitch", "Burst: let go of F12 after the glitch"},
            {"toast.Fast Forward stopped", "Fast Forward stopped"},
            {"toast.Timer cancelled", "Timer cancelled"},
            {"toast.Start the game and load a file first", "Start the game and load a file first"},
            {"toast.Pick a place in Level warp first", "Pick a place in Level warp first"},
            {"toast.Warping to", "Warping to"},
            {"toast.Replay:", "Replay:"},
            {"toast.Replay not started: the game select screen did not load", "Replay not started: the game select screen did not load"},
            {"toast.Races use your save file: quit the replay or mode first", "Races use your save file: quit the replay or mode first"},
            {"toast.Racing Canary Mary:", "Racing Canary Mary:"},
            {"toast.Boss rush", "Boss rush"},
            {"toast.Boss rush stopped", "Boss rush stopped"},
            {"toast.Boss rush stops after this fight", "Boss rush stops after this fight"},
            {"toast.Turn off Bottles' Revenge first", "Turn off Bottles' Revenge first"},
            {"toast.Preset:", "Preset:"},
            {"toast.Blend mode:", "Blend mode:"},
            {"toast.The wheel changes:", "The wheel changes:"},
            {"toast.Frozen: change the blend mode to compare", "Frozen: change the blend mode to compare"},
            {"toast.Unfrozen", "Unfrozen"},
            {"toast.HUD hidden", "HUD hidden"},
            {"toast.HUD shown", "HUD shown"},
            {"toast.Frame rate overlay off", "Frame rate overlay off"},
            {"toast.Ray tracing needs the Vulkan renderer and a graphics card with ray tracing. Using the current effects.", "Ray tracing needs the Vulkan renderer and a graphics card with ray tracing. Using the current effects."},
            {"toast.Passed over a crash: logs/PassedOver.txt has the details", "Passed over a crash: logs/PassedOver.txt has the details"},
            {"toast.Assets dumped:", "Assets dumped:"},
            {"toast.Sounds dumped:", "Sounds dumped:"},
            {"toast.Benchmark recording (press again to stop)", "Benchmark recording (press again to stop)"},
            {"toast.Benchmark saved:", "Benchmark saved:"},
        };
        for (const auto& [key, english] : notices) list.emplace_back(key, english);
        for (const auto& text : tooie::achievements::texts()) list.push_back(text);
        return list;
    }

    // ---- The player's European copy (French, German and Spanish game text) ----
    //
    // The European ROM (PAL, NB7P) holds the same text assets with the same ids as the US one, each with four
    // languages: a count of 4, four 16-bit little-endian offsets, then the English, French, German and Spanish sections.
    // A section is the same as the US asset's only one, so the US asset is that section behind 01 03 00. The player
    // supplies the copy (the Language setting's pop-up, or `language rom <file>`); it is kept beside the US one and read
    // when a European language is chosen. Nothing of it is in the program.

    struct EuropeanRom {
        std::vector<uint8_t> bytes;
        uint32_t data = 0;       // where the assets' data starts
        uint32_t words = 0;      // the table's first word
        uint32_t count = 0;
        bool ok = false;
    };
    EuropeanRom european;
    bool european_tried = false;

    uint32_t be32_at(const std::vector<uint8_t>& b, size_t at) {
        return at + 4 <= b.size() ? (uint32_t(b[at]) << 24) | (uint32_t(b[at + 1]) << 16) | (uint32_t(b[at + 2]) << 8) | b[at + 3] : 0;
    }

    // Big-endian (.z64) bytes whatever order the file is in (.v64 swaps 16-bit halves, .n64 is little-endian).
    bool to_z64(std::vector<uint8_t>& b) {
        if (b.size() < 0x40) return false;
        if (b[0] == 0x80 && b[1] == 0x37 && b[2] == 0x12 && b[3] == 0x40) return true;
        if (b[0] == 0x37 && b[1] == 0x80) {
            for (size_t i = 0; i + 1 < b.size(); i += 2) std::swap(b[i], b[i + 1]);
            return true;
        }
        if (b[0] == 0x40 && b[1] == 0x12) {
            for (size_t i = 0; i + 3 < b.size(); i += 4) { std::swap(b[i], b[i + 3]); std::swap(b[i + 1], b[i + 2]); }
            return true;
        }
        return false;
    }

    // The asset table: a count, 0xFFFFFFFF, then a word an asset (offset << 6 | compressed << 4 | kind).
    bool find_table(EuropeanRom& rom) {
        for (uint32_t at = 0x1000; at < 0x40000 && at + 72 < rom.bytes.size(); at += 4) {
            const uint32_t count = be32_at(rom.bytes, at);
            if (count <= 0x1000 || count >= 0x10000 || be32_at(rom.bytes, at + 4) != 0xFFFFFFFF) continue;
            bool rising = true;
            for (uint32_t k = 0; k < 15 && rising; k++) rising = (be32_at(rom.bytes, at + 8 + k * 4) >> 6) <= (be32_at(rom.bytes, at + 12 + k * 4) >> 6);
            if (!rising) continue;
            rom.count = count;
            rom.words = at + 8;
            rom.data = rom.words + count * 4;
            return true;
        }
        return false;
    }

    // An asset of the European copy as the game would load it (decompressed).
    std::vector<uint8_t> european_asset(const EuropeanRom& rom, uint32_t id) {
        if (id + 1 >= rom.count) return {};
        const uint32_t word = be32_at(rom.bytes, rom.words + id * 4), next = be32_at(rom.bytes, rom.words + (id + 1) * 4);
        const uint32_t offset = rom.data + (word >> 6), size = (next >> 6) - (word >> 6);
        if ((next >> 6) < (word >> 6) || size < 3 || offset + size > rom.bytes.size()) return {};
        const uint8_t* src = rom.bytes.data() + offset;
        if (((word >> 4) & 1) == 0) return std::vector<uint8_t>(src, src + size);
        size_t out_len = 0;
        void* out = tinfl_decompress_mem_to_heap(src + 2, size - 2, &out_len, 0);
        if (out == nullptr) return {};
        std::vector<uint8_t> bytes((uint8_t*)out, (uint8_t*)out + out_len);
        mz_free(out);
        return bytes;
    }

    // Section `n` (0 English .. 3 Spanish) of a four-language text asset, or empty.
    std::vector<uint8_t> european_section(const std::vector<uint8_t>& asset, int n) {
        if (asset.size() < 9 || asset[0] != 4) return {};
        uint32_t offs[5];
        for (int i = 0; i < 4; i++) offs[i] = asset[1 + 2 * i] | (asset[2 + 2 * i] << 8);
        offs[4] = (uint32_t)asset.size();
        if (offs[0] != 9 || offs[n] > offs[n + 1] || offs[n + 1] > asset.size()) return {};
        return std::vector<uint8_t>(asset.begin() + offs[n], asset.begin() + offs[n + 1]);
    }

    // Checks a European copy: a Banjo-Tooie PAL ROM whose pause menu text (asset 1863) has four languages.
    bool check_european(EuropeanRom& rom, std::string* why) {
        if (!to_z64(rom.bytes)) { *why = "that file is not an N64 ROM"; return false; }
        if (std::string((const char*)rom.bytes.data() + 0x20, 11) != "BANJO TOOIE") { *why = "that is not Banjo-Tooie"; return false; }
        if (rom.bytes[0x3E] != 'P') { *why = "that is not the European (PAL) Banjo-Tooie"; return false; }
        if (!find_table(rom) || european_section(european_asset(rom, 0x1863), 1).empty()) {
            *why = "its text could not be read (a bad dump?)";
            return false;
        }
        rom.ok = true;
        return true;
    }

    fs::path european_path() {
        return recomp::get_config_path() / "bt.n64.eu.z64";
    }

    // With the mutex held: the stored European copy, read once.
    const EuropeanRom* european_rom() {
        if (!european_tried) {
            european_tried = true;
            std::error_code ec;
            if (fs::exists(european_path(), ec)) {
                std::ifstream in(european_path(), std::ios::binary);
                european.bytes.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
                std::string why;
                if (!check_european(european, &why)) {
                    fprintf(stderr, "[language] the stored European copy can't be used: %s\n", why.c_str());
                    european = EuropeanRom{};
                }
            }
        }
        return european.ok ? &european : nullptr;
    }

    std::mutex mutex;
    // Index in the Language setting -> translation key; 0 is English ("").
    std::vector<std::string> choices = { "" };
    std::map<std::string, fs::path> files;
    Translation loaded;
    std::map<uint32_t, std::vector<uint8_t>> built;
    std::set<uint32_t> warned;

    // A language with more than one written form is one choice in the Language setting, with a setting of its own
    // under it for the form; its files say the same `@group <language>` and each its own `@variant <form>`.
    struct FormGroup {
        std::string option_id;               // its form setting
        std::vector<std::string> variants;   // translation keys, in the form setting's order
    };
    std::map<uint32_t, FormGroup> groups;
    // The Language setting's choices that are Rare's own text (English, and the European copy's languages): their
    // names get "(Official)", in the menu's language. The others are fan translations.
    std::set<uint32_t> official_choices = { 0 };    // by its index in the Language setting
    std::vector<std::pair<std::string, std::string>> settings_strings();  // below

    std::string chosen_key() {
        uint32_t index = 0;
        try {
            index = std::get<uint32_t>(recompui::config::get_general_config().get_option_value(tooie::language::option));
        } catch (...) {
        }
        auto group = groups.find(index);
        if (group != groups.end()) {
            uint32_t form = 0;
            try {
                form = std::get<uint32_t>(recompui::config::get_general_config().get_option_value(group->second.option_id));
            } catch (...) {
            }
            return form < group->second.variants.size() ? group->second.variants[form] : group->second.variants.front();
        }
        return index < choices.size() ? choices[index] : std::string();
    }

    // With the mutex held: the chosen translation loaded. False for English or a file that is gone.
    bool ensure_loaded(const std::string& key) {
        if (key.empty()) return false;
        if (loaded.key == key) return !loaded.lines.empty() || !loaded.port.empty();
        auto found = files.find(key);
        loaded = Translation{ key, {}, found == files.end() ? fs::path() : found->second, {} };
        built.clear();
        warned.clear();
        if (found == files.end() || !load_translation(loaded)) {
            fprintf(stderr, "[language] translation %s not found; the game's English is used\n", key.c_str());
            return false;
        }
        size_t lines = 0;
        for (const auto& [id, l] : loaded.lines) lines += l.size();
        printf("[language] %s: %zu lines in %zu text assets from %s\n", key.c_str(), lines, loaded.lines.size(),
            (const char*)loaded.path.u8string().c_str());
        fflush(stdout);
        return true;
    }
}

fs::path tooie::language::user_folder() {
    return recomp::get_config_path() / "translations";
}

std::vector<std::pair<std::string, std::string>> tooie::language::available() {
    std::vector<std::pair<std::string, std::string>> out;
    for (const auto& [key, path] : find_files()) {
        out.emplace_back(key, file_display_name(path));
    }
    return out;
}

namespace {
    // A European language was chosen and there is no European copy: a pop-up says so, with Browse (a file picker; the
    // copy is checked and kept) and Exit (back to the language before), in the newly chosen language. From the menu
    // it opens at once; from another thread (the console's `set language french`) under the UI's context lock, as the
    // console opens the menu. The console can also give the copy with `language rom <file>`.
    std::thread::id menu_thread;

    void ask_for_european_copy(recomp::config::ConfigValueVariant previous) {
        auto go_back = [previous]() {
            recompui::config::get_general_config().update_option_value(tooie::language::option, previous);
        };
        auto t = [](const char* key, const char* english) { return tooie::language::port_text(key, english); };
        auto show = [&]() { recompui::open_choice_prompt(
            t("popup.european.title", "European copy needed"),
            t("popup.european.text", "Rare's French, German and Spanish text is read from your own copy of the European (PAL) "
                "Banjo-Tooie. Browse to the ROM file to use it; it is kept for next time."),
            t("popup.european.browse", "Browse"),
            t("popup.european.exit", "Exit"),
            [go_back]() {
                recompui::file::open_file_dialog([go_back](bool success, const std::filesystem::path& path) {
                    if (!success) { go_back(); return; }
                    std::string why;
                    if (tooie::language::use_european_copy(path, &why)) {
                        tooie::asset_mods::request_area_reload();
                        tooie::language::apply_settings();
                        tooie::toast::show("European copy found");
                    } else {
                        go_back();
                        recompui::open_info_prompt(tooie::language::port_text("popup.european.bad", "Can't use that file"),
                            tooie::language::port_text("popup.european.bad", "Can't use that file") + ": " + why + ".", "OK", []() {});
                    }
                });
            },
            go_back,
            recompui::ButtonStyle::Success,
            recompui::ButtonStyle::Tertiary,
            false,
            true); };
        if (std::this_thread::get_id() == menu_thread) {
            show();
            return;
        }
        auto lifetime = recompui::lock_context_lifetime();
        if (recompui::contexts_alive()) show();
    }
}

bool tooie::language::needs_european_copy() {
    const std::string key = chosen_key();
    if (key.empty()) return false;
    std::lock_guard lock{ mutex };
    if (!ensure_loaded(key) || loaded.european == 0) return false;
    return european_rom() == nullptr;
}

bool tooie::language::use_european_copy(const std::filesystem::path& from, std::string* why) {
    EuropeanRom rom;
    {
        std::ifstream in(from, std::ios::binary);
        if (!in) { *why = "it could not be opened"; return false; }
        rom.bytes.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
    }
    if (!check_european(rom, why)) return false;
    std::error_code ec;
    fs::create_directories(european_path().parent_path(), ec);
    {
        std::ofstream out(european_path(), std::ios::binary);
        out.write((const char*)rom.bytes.data(), (std::streamsize)rom.bytes.size());
        if (!out) { *why = "it could not be saved beside the game"; return false; }
    }
    std::lock_guard lock{ mutex };
    european = std::move(rom);
    european_tried = true;
    built.clear();
    printf("[language] European copy kept as %s\n", (const char*)european_path().u8string().c_str());
    fflush(stdout);
    return true;
}

void tooie::language::add_option(recomp::config::Config& general) {
    menu_thread = std::this_thread::get_id();
    std::error_code ec;
    fs::create_directories(user_folder(), ec);
    std::vector<recomp::config::ConfigOptionEnumOption> options = { {0u, "english", "English"} };
    // English is a British game's own text, so its flag is the Union Jack (assets/translations/english.svg).
    std::vector<std::string> flags = { flag_for("english", {}) };
    // A form setting for each language that has more than one: id, its name, its forms (key, name).
    struct FormSetting {
        std::string id, name;
        std::vector<recomp::config::ConfigOptionEnumOption> forms;
        uint32_t default_form = 0;  // the file that says @default
    };
    std::vector<FormSetting> form_settings;
    {
        std::lock_guard lock{ mutex };
        find_enabled_mods_at_start();
        files = find_files();
        choices = { "" };
        groups.clear();
        // Files with the same @group are one choice (named after the group, with the first form's flag).
        std::map<std::string, std::vector<std::pair<std::string, fs::path>>> grouped;
        for (const auto& [key, path] : files) {
            const std::string group = header_field(path, "@group");
            grouped[group.empty() ? "\x01" + key : group].emplace_back(key, path);
        }
        for (const auto& [group, members] : grouped) {
            const uint32_t index = (uint32_t)choices.size();
            if (group[0] == '\x01' || members.size() == 1) {
                const auto& [key, path] = members.front();
                options.push_back({ index, key, group[0] == '\x01' ? file_display_name(path) : group });
                if (header_field(path, "@game").rfind("european", 0) == 0) official_choices.insert(index);
                flags.push_back(flag_for(key, path));
                choices.push_back(key);
                continue;
            }
            const std::string group_key = lower(group);
            options.push_back({ index, group_key, group });
            flags.push_back(flag_for(group_key, {}).empty() ? flag_for(members.front().first, members.front().second) : flag_for(group_key, {}));
            choices.push_back(members.front().first);
            FormSetting form{ std::string(option) + "_" + group_key, group, {} };
            FormGroup g{ form.id, {} };
            for (const auto& [key, path] : members) {
                const std::string variant = header_field(path, "@variant");
                form.forms.push_back({ (uint32_t)g.variants.size(), key, upper_latin(variant.empty() ? file_display_name(path) : variant) });
                if (!header_field(path, "@default").empty() || header_field_present(path, "@default")) form.default_form = (uint32_t)g.variants.size();
                g.variants.push_back(key);
            }
            groups[index] = g;
            form_settings.push_back(std::move(form));
        }
    }
    recompui::config::set_option_icons(option, flags);
    general.add_enum_option(option, "Language",
        "The language of the game's own text: dialogue, menus and signs. Each choice besides English is a translation "
        "file from the translations folder; lines a translation leaves out stay English. Changing it reloads the area "
        "so the new text shows at once. Translations are written by fans and AI, not by Rare.",
        options, 0u);
    auto changed = [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant prev, recomp::config::OptionChangeContext context) {
        if (context == recomp::config::OptionChangeContext::Load) return;
        tooie::asset_mods::request_area_reload();
        tooie::language::apply_settings();
        if (tooie::language::needs_european_copy()) {
            ask_for_european_copy(prev);
        }
    };
    general.add_option_change_callback(option, changed);
    // Each form setting right under Language, shown only while its language is chosen.
    for (const FormSetting& form : form_settings) {
        general.add_enum_option(form.id, form.name, "Which written form of the language the game's text is in.", form.forms, form.default_form);
        general.add_option_change_callback(form.id, changed);
        std::vector<recomp::config::ConfigValueVariant> others;
        for (const auto& [index, g] : groups) {
            if (g.option_id == form.id) {
                for (uint32_t i = 0; i < (uint32_t)options.size(); i++) {
                    if (i != index) others.push_back(i);
                }
            }
        }
        general.add_option_hidden_dependency(form.id, option, others);
    }
}

namespace {
    // With the mutex held: the files found again after a language mod went on or off. When they changed, the chosen
    // language is loaded again (English when its file went) and the area reloads so the text shows.
    void refind_files() {
        std::map<std::string, fs::path> found = find_files();
        if (found == files) return;
        files = std::move(found);
        loaded = Translation{};
        built.clear();
        warned.clear();
        tooie::asset_mods::request_area_reload();
    }
}

void tooie::language::enable_mod(const std::string& mod_id, const std::filesystem::path& root) {
    std::error_code ec;
    if (!fs::is_directory(root / "translations", ec)) {
        fprintf(stderr, "[language] mod %s has translations.json but no translations folder next to it\n", mod_id.c_str());
        return;
    }
    std::lock_guard lock{ mutex };
    mod_folders[mod_id] = root / "translations";
    refind_files();
    printf("[language] mod %s on\n", mod_id.c_str());
    fflush(stdout);
}

void tooie::language::disable_mod(const std::string& mod_id) {
    std::lock_guard lock{ mutex };
    if (mod_folders.erase(mod_id) == 0) return;
    refind_files();
    printf("[language] mod %s off\n", mod_id.c_str());
    fflush(stdout);
}

std::string tooie::language::current() {
    return chosen_key();
}

std::string tooie::language::reload() {
    const std::string key = chosen_key();
    {
        std::lock_guard lock{ mutex };
        files = find_files();
        loaded = Translation{};
        built.clear();
        warned.clear();
        if (key.empty()) {
            return "English (the game's own text)";
        }
        if (!ensure_loaded(key)) {
            return "translation " + key + " not found; the game's English is used";
        }
        size_t lines = 0;
        for (const auto& [id, l] : loaded.lines) lines += l.size();
        tooie::asset_mods::request_area_reload();
        return key + ": " + std::to_string(lines) + " lines in " + std::to_string(loaded.lines.size()) + " text assets, area reloading";
    }
}

namespace {
    // Text asset `id` rebuilt with `lines`. Empty when it is not a text asset or the line count is not the game's
    // (`game_lines` is then the game's count). `odd` counts characters that could not be used as written.
    std::vector<uint8_t> build_asset(uint32_t id, const std::vector<std::string>& lines, size_t* odd, size_t* game_lines) {
        *game_lines = 0;
        if (tooie::asset_mods::asset_kind(id) != kind_text) return {};
        std::vector<Group> groups;
        if (!english_groups(tooie::asset_mods::rom_asset_bytes(id), groups)) return {};
        for (const Group& g : groups) {
            for (const Entry& e : g) *game_lines += is_text(e.cmd) ? 1 : 0;
        }
        if (lines.size() != *game_lines) return {};
        size_t at = 0;
        for (Group& g : groups) {
            for (Entry& e : g) {
                if (is_text(e.cmd)) e.data = line_from_file(lines[at++], odd);
            }
        }
        return write_asset(groups);
    }
}

std::vector<uint8_t> tooie::language::text_asset(uint32_t id) {
    const std::string key = chosen_key();
    if (key.empty()) return {};
    std::lock_guard lock{ mutex };
    if (!ensure_loaded(key)) return {};
    auto cached = built.find(id);
    if (cached != built.end()) return cached->second;
    if (loaded.european >= 1 && loaded.european <= 3) {
        // Rare's own translation, from the player's European copy: the US asset is that language's section behind
        // 01 03 00 (US text assets have one language).
        std::vector<uint8_t> out;
        const EuropeanRom* rom = european_rom();
        if (rom != nullptr && tooie::asset_mods::asset_kind(id) == kind_text) {
            const std::vector<uint8_t> section = european_section(european_asset(*rom, id), loaded.european);
            if (!section.empty()) {
                out = { 1, 3, 0 };
                out.insert(out.end(), section.begin(), section.end());
            }
        }
        built[id] = out;
        return out;
    }
    auto lines = loaded.lines.find(id);
    if (lines == loaded.lines.end()) return {};
    size_t odd = 0, game_lines = 0;
    std::vector<uint8_t> out = build_asset(id, lines->second, &odd, &game_lines);
    if (out.empty() && game_lines > 0 && warned.insert(id).second) {
        fprintf(stderr, "[language] %s: asset %04X has %zu lines but the game's has %zu; it stays English\n",
            key.c_str(), id, lines->second.size(), game_lines);
    }
    if (odd > 0 && warned.insert(id).second) {
        fprintf(stderr, "[language] %s: asset %04X: %zu characters could not be used as written (a bad {XX}, a letter the "
            "font lacks, or a line over %zu)\n", key.c_str(), id, odd, max_line);
    }
    built[id] = out;
    return out;
}

std::vector<std::string> tooie::language::check() {
    std::vector<std::string> report;
    const std::string key = chosen_key();
    if (key.empty()) return { "the Language setting is English: choose a translation first" };
    if (recomp::get_rom().empty()) return { "the game has not started, so the ROM is not loaded; start it first" };
    std::lock_guard lock{ mutex };
    loaded = Translation{};
    built.clear();
    warned.clear();
    if (!ensure_loaded(key)) return { "translation " + key + " not found" };
    size_t ok = 0, same = 0, wrong_count = 0, not_text = 0, odd_assets = 0;
    for (const auto& [id, lines] : loaded.lines) {
        size_t odd = 0, game_lines = 0;
        std::vector<uint8_t> out = build_asset(id, lines, &odd, &game_lines);
        char name[16];
        snprintf(name, sizeof(name), "%04X", id);
        if (out.empty()) {
            if (game_lines == 0) {
                not_text++;
                report.push_back(std::string(name) + ": not a text asset of the game");
            } else {
                wrong_count++;
                report.push_back(std::string(name) + ": " + std::to_string(lines.size()) + " lines, the game's has " + std::to_string(game_lines));
            }
            continue;
        }
        ok++;
        if (odd > 0) {
            odd_assets++;
            report.push_back(std::string(name) + ": " + std::to_string(odd) + " characters could not be used as written");
        }
        if (out == tooie::asset_mods::rom_asset_bytes(id)) same++;
    }
    report.push_back(key + ": " + std::to_string(ok) + " assets build (" + std::to_string(same) + " the same as the game's English), " +
        std::to_string(wrong_count) + " with the wrong line count, " + std::to_string(not_text) + " not text, " +
        std::to_string(odd_assets) + " with characters changed");
    return report;
}

bool tooie::language::export_english(const fs::path& to, size_t* assets, size_t* lines, std::string* why) {
    if (recomp::get_rom().empty()) {
        *why = "the game has not started, so the ROM is not loaded; start it first";
        return false;
    }
    std::error_code ec;
    if (to.has_parent_path()) fs::create_directories(to.parent_path(), ec);
    std::ofstream out(to, std::ios::binary);
    if (!out) {
        *why = "could not write " + std::string((const char*)to.u8string().c_str());
        return false;
    }
    out << "# Banjo Re-Tooie translation file (docs/translations.md).\n"
           "# Exported from your own Banjo-Tooie ROM: these are Rare's English lines. Do not share this file as it is;\n"
           "# share only a file holding your own translated lines.\n"
           "# Each === starts a text asset; under it come its lines in order, one per line. Keep the count the same.\n"
           "# {0A} is a line break, {80}-{87} are button pictures, other {XX} are control bytes: keep them. {} is an empty line.\n"
           "@name English\n";
    *assets = 0;
    *lines = 0;
    for (uint32_t id = 0;; id++) {
        const int kind = tooie::asset_mods::asset_kind(id);
        if (kind < 0) break;
        if (kind != kind_text) continue;
        std::vector<Group> groups;
        if (!english_groups(tooie::asset_mods::rom_asset_bytes(id), groups)) continue;
        std::string block;
        size_t count = 0;
        for (const Group& g : groups) {
            for (const Entry& e : g) {
                if (!is_text(e.cmd)) continue;
                block += line_to_file(e.data) + "\n";
                count++;
            }
        }
        if (count == 0) continue;
        char head[32];
        snprintf(head, sizeof(head), "\n=== %04X\n", id);
        out << head << block;
        (*assets)++;
        *lines += count;
    }
    // The Esc menu's text.
    out << "\n=== settings\n# The Esc menu: each setting's name, description and choices. key = text.\n";
    for (const auto& [key, english] : settings_strings()) {
        out << key << " = " << english << "\n";
    }
    // The port's own text, so a translation covers it too.
    out << "\n=== port\n# The port's own text: achievements, the Totals checklist, our pause menu entries. key = text.\n";
    for (const auto& [key, english] : port_strings()) {
        out << key << " = " << english << "\n";
    }
    return true;
}

namespace {
    // The Esc menu's text as the program made it, in English, so a translation can be put on and taken off again.
    struct SettingText {
        std::string name;
        std::string description;
        std::vector<std::string> choice_keys, choice_names;
    };
    std::map<std::string, SettingText> setting_english;  // by "<tab>.<setting>"

    // Every config tab's settings with their English (the first call keeps the English).
    void each_setting(const std::function<void(recomp::config::Config&, const recomp::config::ConfigOption&, const std::string&, const SettingText&)>& fn) {
        recompui::config::for_each_config([&](recomp::config::Config& config) {
            for (const auto& option : config.get_config_schema().options) {
                const std::string base = config.id + "." + option.id;
                auto found = setting_english.find(base);
                if (found == setting_english.end()) {
                    SettingText text{ option.name, option.description, {}, {} };
                    if (option.type == recomp::config::ConfigOptionType::Enum) {
                        for (const auto& choice : std::get<recomp::config::ConfigOptionEnum>(option.variant).options) {
                            text.choice_keys.push_back(choice.key);
                            text.choice_names.push_back(choice.name);
                        }
                    }
                    found = setting_english.emplace(base, std::move(text)).first;
                }
                fn(config, option, base, found->second);
            }
        });
    }

    // One line of text in a translation file: a line break becomes a space (the menu wraps text by itself).
    std::string one_line(std::string text) {
        for (char& c : text) if (c == '\n' || c == '\r') c = ' ';
        return text;
    }

    std::vector<std::pair<std::string, std::string>> settings_strings() {
        std::vector<std::pair<std::string, std::string>> list;
        each_setting([&](recomp::config::Config&, const recomp::config::ConfigOption&, const std::string& base, const SettingText& text) {
            if (!text.name.empty()) list.emplace_back(base + ".name", one_line(text.name));
            if (!text.description.empty()) list.emplace_back(base + ".description", one_line(text.description));
            for (size_t i = 0; i < text.choice_keys.size(); i++) {
                if (text.choice_names[i] != text.choice_keys[i] || !text.choice_names[i].empty()) {
                    list.emplace_back(base + ".choice." + text.choice_keys[i], one_line(text.choice_names[i]));
                }
            }
        });
        // The menu's own text: tab names, section headings, the search box.
        for (const auto& [key, english] : recompui::config::menu_texts()) list.emplace_back(key, english);
        return list;
    }
}

void tooie::language::apply_settings() {
    // Tab names, section headings, page titles and the search box ask for their text when they are made.
    static const bool translator_set = [] {
        recompui::config::set_text_translator([](const std::string& key, const std::string& english) {
            return tooie::language::port_text(key, english);
        });
        return true;
    }();
    (void)translator_set;
    recompui::config::refresh_texts();
    size_t changed = 0;
    each_setting([&](recomp::config::Config& config, const recomp::config::ConfigOption& option, const std::string& base, const SettingText& text) {
        const std::string name = port_text(base + ".name", text.name);
        if (name != option.name) { config.update_option_name(option.id, name); changed++; }
        const std::string description = port_text(base + ".description", text.description);
        if (description != option.description) { config.update_option_description(option.id, description); changed++; }
        if (!text.choice_keys.empty()) {
            std::vector<std::string> names;
            for (size_t i = 0; i < text.choice_keys.size(); i++) {
                std::string translated = port_text(base + ".choice." + text.choice_keys[i], text.choice_names[i]);
                if (config.id == "general" && option.id == tooie::language::option && official_choices.contains((uint32_t)i)) {
                    // On a line of its own under the name, so the choices stay narrow (the menu turns \n into a
                    // line break).
                    translated += "\n(" + port_text("language.official", "Official") + ")";
                }
                names.push_back(translated == text.choice_names[i] ? translated : upper_latin(translated));
            }
            const auto& now = std::get<recomp::config::ConfigOptionEnum>(option.variant).options;
            bool differs = false;
            for (size_t i = 0; i < now.size() && i < names.size(); i++) differs = differs || now[i].name != names[i];
            if (differs) { config.update_enum_option_names(option.id, names); changed++; }
        }
    });
    if (changed > 0) {
        printf("[language] menu: %zu settings' text changed\n", changed);
        fflush(stdout);
    }
}

std::string tooie::language::port_text(const std::string& key, const std::string& english) {
    const std::string chosen = chosen_key();
    if (chosen.empty()) return english;
    std::lock_guard lock{ mutex };
    if (!ensure_loaded(chosen)) return english;
    auto found = loaded.port.find(key);
    return found == loaded.port.end() || found->second.empty() ? english : found->second;
}

uint32_t tooie::language::code_letter(uint8_t code) {
    if (code == 0x6A) return 0xDC;  // the second Ü glyph
    if (code == 0x71) return 0xD9;  // the second Ù glyph
    auto found = code_letters().find(code);
    return found == code_letters().end() ? 0 : found->second;
}

std::string tooie::language::notice_text(const std::string& english) {
    const std::string chosen = chosen_key();
    if (chosen.empty()) return english;
    std::lock_guard lock{ mutex };
    if (!ensure_loaded(chosen)) return english;
    auto whole = loaded.port.find("toast." + english);
    if (whole != loaded.port.end() && !whole->second.empty()) return whole->second;
    // The longest translated start of the notice; what follows it (a number, a name, a file) is kept.
    size_t best = 0;
    std::string out = english;
    for (auto it = loaded.port.lower_bound("toast."); it != loaded.port.end() && it->first.rfind("toast.", 0) == 0; ++it) {
        const std::string start = it->first.substr(6);
        if (start.size() > best && english.size() > start.size() && english.compare(0, start.size(), start) == 0 && !it->second.empty()) {
            best = start.size();
            out = it->second + english.substr(start.size());
        }
    }
    return out;
}

std::string tooie::language::game_text(const std::string& utf8) {
    size_t odd = 0;
    std::vector<uint8_t> bytes = line_from_file(utf8, &odd);
    if (!bytes.empty() && bytes.back() == 0) bytes.pop_back();
    return std::string(bytes.begin(), bytes.end());
}

std::string tooie::language::port_game_text(const std::string& key, const std::string& english) {
    return game_text(port_text(key, english));
}
