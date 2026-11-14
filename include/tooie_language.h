#ifndef __TOOIE_LANGUAGE_H__
#define __TOOIE_LANGUAGE_H__

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

namespace recomp::config {
    class Config;
}

// Translations of the game's own text (src/game/language.cpp, docs/translations.md).
//
// The game's English is exported from the player's own US ROM into a plain text file, a translator replaces the lines,
// and the game loads that file over the ROM's text: each text asset is rebuilt with the translated lines in place of
// the English ones. A line or an asset the file leaves out stays English. Translation files sit in the program's
// assets/translations folder (shipped with the game), in language mods (a mod folder with a translations.json and a
// translations/ folder, while the mod is on in the Mods menu) and in the translations folder of the app-data folder
// (the player's own). A later place wins over an earlier one for a file of the same name.
namespace tooie::language {
    inline const std::string option = "language";

    // General tab > Language: English, then one choice per translation file found at start.
    void add_option(recomp::config::Config& general);

    // The text asset `id` in the chosen language, ready for the game to use, or empty for the ROM's own (English, or
    // not a text asset, or not translated). Called from the asset load hook on the game thread.
    std::vector<uint8_t> text_asset(uint32_t id);

    // The dialogue font (0C21) or title font (0C22) drawn from a TTF/OTF the player put in the fonts folder
    // (src/game/language_font.cpp); empty when there is none for it, or for any other asset. The asset load hook
    // serves them.
    std::vector<uint8_t> font_asset(uint32_t id);
    // Whether the player supplied a font for the dialogue font, which has room for Æ, Ø and Å only then (without one
    // the text writes them as AE, O and A).
    bool dialogue_font_supplied();
    // The folder the player puts fonts in: dialogue.ttf (or .otf) and title.ttf.
    std::filesystem::path fonts_folder();
    // The letter a game text byte stands for (0x5B..0x7B are the game's accented capitals and Æ Ø Å), or 0.
    uint32_t code_letter(uint8_t code);

    // The port's own text (achievements, the Totals checklist, our pause menu entries) in the chosen language: the
    // translation file's `=== port` section holds `key = text` lines. Returns `english` when the language is English or
    // the file has no line for `key`. UTF-8, for the settings menu and toasts.
    std::string port_text(const std::string& key, const std::string& english);
    // Text as the game draws it: capitals, accented letters as the game's codes (see language.cpp). For text drawn
    // with the game's fonts.
    std::string game_text(const std::string& utf8);
    // A notice (src/ui/toast.cpp) in the chosen language: the translation's `toast.<English>` line for the whole
    // notice, or for the longest one the notice starts with ("Warping to" for "Warping to Mayahem Temple"), the
    // rest kept as it is. The notice itself when there is none.
    std::string notice_text(const std::string& english);
    // port_text, then game_text.
    std::string port_game_text(const std::string& key, const std::string& english);

    // Puts the Esc menu's text (every setting's name, description and choices) in the chosen language: a translation
    // file's `=== settings` section, keys <tab>.<setting>.name, .description and .choice.<choice key>. Call once
    // the menu's tabs exist; the Language setting calls it again when it changes, and the menu shows it at once.
    void apply_settings();

    // French, German and Spanish take the game's text from the player's own European (PAL) copy: true when that
    // language is chosen and there is none yet. use_european_copy checks a ROM file and keeps a copy of it (in .z64
    // order) beside the game; false with `why` filled when it can't be used.
    bool needs_european_copy();
    bool use_european_copy(const std::filesystem::path& from, std::string* why);

    // The chosen translation's key (its file name without .txt), or empty for English.
    std::string current();
    // Reads the chosen translation file again and reloads the area so its text shows. Returns what happened.
    std::string reload();
    // Builds every asset of the chosen translation and lists the problems, then a summary line.
    std::vector<std::string> check();

    // Writes the game's English text from the US ROM to `to` in the translation file format. The game must have
    // started (the ROM loaded). Returns false with `why` filled when it could not.
    bool export_english(const std::filesystem::path& to, size_t* assets, size_t* lines, std::string* why);

    // The folder for the player's own translation files.
    std::filesystem::path user_folder();
    // Every translation file found: key and display name.
    std::vector<std::pair<std::string, std::string>> available();

    // A language mod switched on or off in the Mods menu (src/main/main.cpp registers translations.json as a mod
    // content type). Its translations/ folder counts while it is on. The Language setting's choices are made once at
    // start, from the mods on then; a mod's language chosen while the mod is off falls back to English.
    void enable_mod(const std::string& mod_id, const std::filesystem::path& root);
    void disable_mod(const std::string& mod_id);
}

#endif
