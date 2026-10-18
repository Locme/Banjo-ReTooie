// Parallax pick mode and Shader Effects pick mode (see include/tooie_parallax_pick.h and include/tooie_effect_pick.h):
// one worker, as both drive the same pick in RT64.
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <map>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "librecomp/game.hpp"
#include "recompinput/input_state.h"
#include "recompui/recompui.h"
#include "elements/ui_element.h"
#include "elements/ui_label.h"

#include "tooie_dev_files.h"
#include "tooie_effect_pick.h"
#include "tooie_hotkeys.h"
#include "tooie_interp_tags.h"
#include "tooie_parallax_pick.h"
#include "tooie_toast.h"

namespace RT64 {
    void SetScenePick(bool on, float x, float y, uint32_t layer);
    uint32_t ScenePickMatrixId();
    void SetScenePickHighlight(bool on);
    void ScenePickResult(uint64_t &hash, uint32_t &layers);
    uint32_t SceneParallaxTexture(uint64_t hash);
    uint32_t SceneGrassTexture(uint64_t hash);
    bool SceneIceTexture(uint64_t hash);
}

namespace {
    using namespace std::chrono_literals;
    using tooie::parallax_pick::Pick;

    std::mutex picks_mutex;
    std::map<uint64_t, Pick> picks;
    // As parallax_tags.txt has them (the Save Pick key writes the texture under the cursor into it).
    std::map<uint64_t, Pick> saved_picks;
    std::atomic<uint32_t> picks_version{1};

    bool same_pick(const Pick& a, const Pick& b) {
        return (a.off == b.off) && (a.off || ((a.shape == b.shape) && (a.depth == b.depth) && (a.fine == b.fine) && (a.shadows == b.shadows)));
    }

    const char* shape_names[tooie::parallax_pick::shape_count] = { "stone", "bumpy", "inverted", "cracks", "terraced", "rounded",
        "grass", "wood", "bark", "brick", "dirt", "metal", "leaves", "tiles", "sand", "smooth" };
    const char* shape_labels[tooie::parallax_pick::shape_count] = { "Stone", "Bumpy", "Inverted", "Cracks", "Terraced", "Rounded",
        "Grass", "Wood", "Bark", "Brick", "Dirt", "Metal", "Leaves", "Tiles", "Sand", "Smooth" };
    const int depth_percents[tooie::parallax_pick::depth_count] = { 100, 25, 50, 150, 200, 300 };
    // Right click goes up from 100%, then round from the shallowest.
    const uint8_t depth_next[tooie::parallax_pick::depth_count] = { 3, 2, 0, 4, 5, 1 };

    std::filesystem::path file_path() {
        return tooie::dev_files::path("parallax_tags.txt");
    }

    // One line a texture: "<hash> off", or "<hash> <shape> <depth>% shadows|noshadows".
    void load() {
        std::ifstream in(tooie::dev_files::read_path("parallax_tags.txt"));
        std::string line;
        std::lock_guard lock{ picks_mutex };
        while (std::getline(in, line)) {
            std::istringstream words(line);
            std::string hash_text, shape_text, depth_text, shadows_text;
            if (!(words >> hash_text) || hash_text.empty() || (hash_text[0] == '#')) {
                continue;
            }
            Pick pick;
            words >> shape_text >> depth_text >> shadows_text;
            if (shape_text == "off") {
                pick.off = true;
            } else {
                for (int s = 0; s < tooie::parallax_pick::shape_count; s++) {
                    if (shape_text == shape_names[s]) {
                        pick.shape = uint8_t(s);
                    }
                }
                const int percent = std::atoi(depth_text.c_str());
                bool preset = false;
                for (int d = 0; d < tooie::parallax_pick::depth_count; d++) {
                    if (percent == depth_percents[d]) {
                        pick.depth = uint8_t(d);
                        preset = true;
                    }
                }
                // Any other depth is a fine one (Shift + wheel), in 10% steps.
                if (!preset && (percent > 0)) {
                    pick.fine = uint8_t(std::clamp((percent + 5) / 10, 1, 31));
                }
                pick.shadows = (shadows_text != "noshadows");
            }
            picks[std::strtoull(hash_text.c_str(), nullptr, 16)] = pick;
        }
        if (!picks.empty()) {
            fprintf(stderr, "[parallax-pick] %zu picks from %s\n", picks.size(), file_path().string().c_str());
        }
        saved_picks = picks;
        picks_version.fetch_add(1);
    }

    // Writes the file from saved_picks (picks_mutex held).
    void write_locked() {
        std::error_code ec;
        std::filesystem::create_directories(file_path().parent_path(), ec);
        std::ofstream out(file_path());
        out << "# Parallax picks (Parallax Pick Mode key): texture, shape, depth, shadows. Send this file in for the port's list.\n";
        for (const auto& [hash, pick] : saved_picks) {
            char text[32];
            snprintf(text, sizeof(text), "%016llx", (unsigned long long)hash);
            if (pick.off) {
                out << text << " off\n";
            } else {
                out << text << " " << shape_names[pick.shape] << " " << pick.depth_percent() << "% " << (pick.shadows ? "shadows" : "noshadows") << "\n";
            }
        }
    }

    // The Save Pick key: the texture's pick as it stands into the file (only that one; its built-in choice takes it out).
    void save_one(uint64_t hash) {
        std::lock_guard lock{ picks_mutex };
        const auto live = picks.find(hash);
        if (live == picks.end()) {
            saved_picks.erase(hash);
        } else {
            saved_picks[hash] = live->second;
        }
        write_locked();
    }

    // The Delete Saved Pick key: the texture back to the built-in choice, in the game and the file (other unsaved picks stay unsaved).
    void delete_saved(uint64_t hash) {
        {
            std::lock_guard lock{ picks_mutex };
            picks.erase(hash);
            saved_picks.erase(hash);
            write_locked();
        }
        picks_version.fetch_add(1);
    }

    // Textures whose pick differs from the file's.
    size_t unsaved_count() {
        std::lock_guard lock{ picks_mutex };
        size_t count = 0;
        for (const auto& [hash, pick] : picks) {
            const auto saved = saved_picks.find(hash);
            count += ((saved == saved_picks.end()) || !same_pick(pick, saved->second)) ? 1 : 0;
        }
        for (const auto& [hash, pick] : saved_picks) {
            count += (picks.find(hash) == picks.end()) ? 1 : 0;
        }
        return count;
    }

    // The Delete All Changes button: every pick back as the file has it. Returns how many changed.
    size_t discard_changes() {
        const size_t count = unsaved_count();
        {
            std::lock_guard lock{ picks_mutex };
            picks = saved_picks;
        }
        picks_version.fetch_add(1);
        return count;
    }

    // The Save All button: every pick into the file.
    size_t save_all() {
        std::lock_guard lock{ picks_mutex };
        saved_picks = picks;
        write_locked();
        return saved_picks.size();
    }

    // ", not saved" when the texture's pick differs from the file's.
    const char* unsaved_note(uint64_t hash) {
        std::lock_guard lock{ picks_mutex };
        const auto live = picks.find(hash);
        const auto saved = saved_picks.find(hash);
        const bool has_live = live != picks.end();
        const bool has_saved = saved != saved_picks.end();
        if (has_live != has_saved) {
            return has_live ? ", not saved" : ", saved one removed";
        }
        return (has_live && !same_pick(live->second, saved->second)) ? ", not saved" : "";
    }

    // The texture's pick as it stands: its own, else the built-in list's (stone at 100% with shadows, or off).
    Pick current(uint64_t hash, bool& own) {
        std::lock_guard lock{ picks_mutex };
        const auto it = picks.find(hash);
        own = (it != picks.end());
        if (own) {
            return it->second;
        }
        Pick pick;
        pick.off = (RT64::SceneParallaxTexture(hash) == 0);
        return pick;
    }

    void set(uint64_t hash, const Pick* pick) {
        {
            std::lock_guard lock{ picks_mutex };
            if (pick == nullptr) {
                picks.erase(hash);
            } else {
                picks[hash] = *pick;
            }
        }
        picks_version.fetch_add(1);
    }

    std::string describe(uint64_t hash, uint32_t layer, uint32_t layers) {
        if (hash == 0) {
            return "No textured surface here";
        }
        bool own = false;
        const Pick pick = current(hash, own);
        char text[160];
        if (pick.off) {
            snprintf(text, sizeof(text), "%016llx\nOff (%s%s)", (unsigned long long)hash, own ? "yours" : "built-in", unsaved_note(hash));
        } else {
            snprintf(text, sizeof(text), "%016llx\n%s, %d%%, %s (%s%s)", (unsigned long long)hash, shape_labels[pick.shape],
                pick.depth_percent(), pick.shadows ? "shadows" : "no shadows", own ? "yours" : "built-in", unsaved_note(hash));
        }
        std::string result = text;
        if (layers > 1) {
            result += "\nLayer " + std::to_string((layer % layers) + 1) + " of " + std::to_string(layers);
        }
        return result;
    }

    // Shader Effects pick mode's picks.
    using tooie::effect_pick::Effect;
    std::mutex effects_mutex;
    std::map<uint64_t, Effect> effects;
    std::map<uint64_t, Effect> saved_effects;
    std::atomic<uint32_t> effects_version{1};
    const char* effect_names[tooie::effect_pick::effect_count] = { "disable", "grass", "deep_snow", "ice" };
    const char* effect_labels[tooie::effect_pick::effect_count] = { "Disable", "Grass", "Deep Snow", "Ice Reflection" };

    std::filesystem::path effects_path() {
        return tooie::dev_files::path("shader_effect_tags.txt");
    }

    // One line a texture: "<hash> disable|grass|deep_snow|ice".
    void load_effects() {
        std::ifstream in(tooie::dev_files::read_path("shader_effect_tags.txt"));
        std::string line;
        std::lock_guard lock{ effects_mutex };
        while (std::getline(in, line)) {
            std::istringstream words(line);
            std::string hash_text, effect_text;
            if (!(words >> hash_text >> effect_text) || (hash_text[0] == '#')) {
                continue;
            }
            for (int e = 0; e < tooie::effect_pick::effect_count; e++) {
                if (effect_text == effect_names[e]) {
                    effects[std::strtoull(hash_text.c_str(), nullptr, 16)] = Effect(e);
                }
            }
        }
        if (!effects.empty()) {
            fprintf(stderr, "[effect-pick] %zu picks from %s\n", effects.size(), effects_path().string().c_str());
        }
        saved_effects = effects;
        effects_version.fetch_add(1);
    }

    // Writes the file from saved_effects (effects_mutex held).
    void write_effects_locked() {
        std::error_code ec;
        std::filesystem::create_directories(effects_path().parent_path(), ec);
        std::ofstream out(effects_path());
        out << "# Shader effect picks (Shader Effects Pick Mode key): texture, effect (disable, grass, deep_snow, ice). Send this file in for the port's lists.\n";
        for (const auto& [hash, effect] : saved_effects) {
            char text[32];
            snprintf(text, sizeof(text), "%016llx", (unsigned long long)hash);
            out << text << " " << effect_names[effect] << "\n";
        }
    }

    void save_one_effect(uint64_t hash) {
        std::lock_guard lock{ effects_mutex };
        const auto live = effects.find(hash);
        if (live == effects.end()) {
            saved_effects.erase(hash);
        } else {
            saved_effects[hash] = live->second;
        }
        write_effects_locked();
    }

    void delete_saved_effect(uint64_t hash) {
        {
            std::lock_guard lock{ effects_mutex };
            effects.erase(hash);
            saved_effects.erase(hash);
            write_effects_locked();
        }
        effects_version.fetch_add(1);
    }

    size_t effects_unsaved_count() {
        std::lock_guard lock{ effects_mutex };
        size_t count = 0;
        for (const auto& [hash, effect] : effects) {
            const auto saved = saved_effects.find(hash);
            count += ((saved == saved_effects.end()) || (saved->second != effect)) ? 1 : 0;
        }
        for (const auto& [hash, effect] : saved_effects) {
            count += (effects.find(hash) == effects.end()) ? 1 : 0;
        }
        return count;
    }

    size_t discard_effect_changes() {
        const size_t count = effects_unsaved_count();
        {
            std::lock_guard lock{ effects_mutex };
            effects = saved_effects;
        }
        effects_version.fetch_add(1);
        return count;
    }

    size_t save_all_effects() {
        std::lock_guard lock{ effects_mutex };
        saved_effects = effects;
        write_effects_locked();
        return saved_effects.size();
    }

    // effects_mutex held.
    const char* effect_unsaved_note_locked(uint64_t hash) {
        const auto live = effects.find(hash);
        const auto saved = saved_effects.find(hash);
        const bool has_live = live != effects.end();
        const bool has_saved = saved != saved_effects.end();
        if (has_live != has_saved) {
            return has_live ? ", not saved" : ", saved one removed";
        }
        return (has_live && (live->second != saved->second)) ? ", not saved" : "";
    }

    // The built-in choice: grass (or grass along an edge) or ice from the lists, else none.
    const char* built_in_effect(uint64_t hash) {
        const uint32_t grass = RT64::SceneGrassTexture(hash);
        if (grass == 1) {
            return "Grass";
        }
        if (grass == 2) {
            return "Grass along edges";
        }
        return RT64::SceneIceTexture(hash) ? "Ice Reflection" : "None";
    }

    std::string describe_effect(uint64_t hash, uint32_t layer, uint32_t layers) {
        if (hash == 0) {
            return "No textured surface here";
        }
        char text[160];
        bool own = false;
        Effect effect = tooie::effect_pick::effect_disable;
        const char* note = "";
        {
            std::lock_guard lock{ effects_mutex };
            const auto it = effects.find(hash);
            own = (it != effects.end());
            if (own) {
                effect = it->second;
            }
            note = effect_unsaved_note_locked(hash);
        }
        if (own) {
            snprintf(text, sizeof(text), "%016llx\n%s (yours%s)", (unsigned long long)hash, effect_labels[effect], note);
        } else {
            snprintf(text, sizeof(text), "%016llx\n%s (built-in%s)", (unsigned long long)hash, built_in_effect(hash), note);
        }
        std::string result = text;
        if (layers > 1) {
            result += "\nLayer " + std::to_string((layer % layers) + 1) + " of " + std::to_string(layers);
        }
        return result;
    }

    // Left click: built-in, Disable, Grass, Deep Snow, Ice Reflection, built-in again.
    // A texture's effect pick as it stands (had = false: none, the built-in choice), and setting it back.
    bool effect_of(uint64_t hash, Effect& effect) {
        std::lock_guard lock{ effects_mutex };
        const auto it = effects.find(hash);
        if (it == effects.end()) {
            return false;
        }
        effect = it->second;
        return true;
    }

    void set_effect(uint64_t hash, bool had, Effect effect) {
        {
            std::lock_guard lock{ effects_mutex };
            if (had) {
                effects[hash] = effect;
            } else {
                effects.erase(hash);
            }
        }
        effects_version.fetch_add(1);
    }

    bool pick_of(uint64_t hash, Pick& pick) {
        std::lock_guard lock{ picks_mutex };
        const auto it = picks.find(hash);
        if (it == picks.end()) {
            return false;
        }
        pick = it->second;
        return true;
    }

    void step_effect(uint64_t hash, bool reset) {
        {
            std::lock_guard lock{ effects_mutex };
            const auto it = effects.find(hash);
            if (reset || ((it != effects.end()) && (it->second + 1 >= tooie::effect_pick::effect_count))) {
                effects.erase(hash);
            } else if (it == effects.end()) {
                effects[hash] = tooie::effect_pick::effect_disable;
            } else {
                it->second = Effect(it->second + 1);
            }
        }
        effects_version.fetch_add(1);
    }

    // The Save All and Delete All Changes buttons at the top left, under the unsaved count, as fractions of the window
    // (the worker tests clicks against them; toasts use the top right).
    constexpr float panel_left = 0.015f, panel_top = 0.03f, panel_width = 0.12f, count_height = 0.045f, button_height = 0.05f;
    constexpr float panel_gap = 0.008f;
    enum PanelButton { panel_none = -1, panel_save_all = 0, panel_discard = 1 };

    float panel_button_top(int button) {
        return panel_top + count_height + panel_gap + float(button) * (button_height + panel_gap);
    }

    PanelButton panel_button_at(float x, float y) {
        if ((x < panel_left) || (x > panel_left + panel_width)) {
            return panel_none;
        }
        for (int k = 0; k < 2; k++) {
            if ((y >= panel_button_top(k)) && (y <= panel_button_top(k) + button_height)) {
                return PanelButton(k);
            }
        }
        return panel_none;
    }

    // The label beside the cursor, and the unsaved count and Save All button.
    struct Label {
        recompui::ContextId context = recompui::ContextId::null();
        recompui::Element* box = nullptr;
        recompui::Label* label = nullptr;
        // The Save Pick and Delete Saved Pick rows: the key's name, then what it is bound to in promptfont's glyphs.
        recompui::Label* key_glyphs[2] = {};
        recompui::Label* key_unbound[2] = {};
        std::string shown_keys[2] = { "?", "?" };
        recompui::Label* count_label = nullptr;
        recompui::Element* panel_buttons[2] = {};
        size_t shown_count = SIZE_MAX;
        int shown_hover = -2;
        bool shown = false;

        bool build() {
            auto lifetime = recompui::lock_context_lifetime();
            if (!recompui::contexts_alive()) {
                return false;
            }
            try {
                recompui::ContextId ctx = recompui::create_context();
                ctx.open();
                recompui::Element* root = ctx.create_element<recompui::Element>(ctx.get_root_element());
                root->set_display(recompui::Display::Flex);
                root->set_background_color(recompui::theme::color::Transparent);
                root->set_pointer_events(recompui::PointerEvents::None);
                box = ctx.create_element<recompui::Element>(root);
                box->set_display(recompui::Display::Flex);
                box->set_position(recompui::Position::Absolute);
                box->set_padding(10);
                box->set_border_radius(recompui::theme::border::radius_md);
                box->set_background_color(recompui::theme::color::ModalOverlay);
                box->set_pointer_events(recompui::PointerEvents::None);
                box->set_flex_direction(recompui::FlexDirection::Column);
                label = ctx.create_element<recompui::Label>(box, "", recompui::LabelStyle::Small);
                label->set_pointer_events(recompui::PointerEvents::None);
                static const char* key_names[2] = { "Save Pick: ", "Delete Saved Pick: " };
                for (int k = 0; k < 2; k++) {
                    recompui::Element* row = ctx.create_element<recompui::Element>(box);
                    row->set_display(recompui::Display::Flex);
                    row->set_flex_direction(recompui::FlexDirection::Row);
                    row->set_align_items(recompui::AlignItems::Center);
                    row->set_pointer_events(recompui::PointerEvents::None);
                    ctx.create_element<recompui::Label>(row, key_names[k], recompui::LabelStyle::Small)->set_pointer_events(recompui::PointerEvents::None);
                    key_glyphs[k] = ctx.create_element<recompui::Label>(row, "", recompui::LabelStyle::Small);
                    key_glyphs[k]->set_font_family("promptfont");
                    key_glyphs[k]->set_pointer_events(recompui::PointerEvents::None);
                    key_unbound[k] = ctx.create_element<recompui::Label>(row, "Unbinded", recompui::LabelStyle::Small);
                    key_unbound[k]->set_pointer_events(recompui::PointerEvents::None);
                }
                recompui::Element* count_box = ctx.create_element<recompui::Element>(root);
                count_box->set_display(recompui::Display::Flex);
                count_box->set_position(recompui::Position::Absolute);
                count_box->set_left(panel_left * 100.0f, recompui::Unit::Percent);
                count_box->set_top(panel_top * 100.0f, recompui::Unit::Percent);
                count_box->set_width(panel_width * 100.0f, recompui::Unit::Percent);
                count_box->set_height(count_height * 100.0f, recompui::Unit::Percent);
                count_box->set_justify_content(recompui::JustifyContent::Center);
                count_box->set_align_items(recompui::AlignItems::Center);
                count_box->set_border_radius(recompui::theme::border::radius_md);
                count_box->set_background_color(recompui::theme::color::ModalOverlay);
                count_box->set_pointer_events(recompui::PointerEvents::None);
                count_label = ctx.create_element<recompui::Label>(count_box, "", recompui::LabelStyle::Small);
                count_label->set_pointer_events(recompui::PointerEvents::None);
                static const char* button_names[2] = { "Save All", "Delete All Changes" };
                for (int k = 0; k < 2; k++) {
                    recompui::Element* button = ctx.create_element<recompui::Element>(root);
                    button->set_display(recompui::Display::Flex);
                    button->set_position(recompui::Position::Absolute);
                    button->set_left(panel_left * 100.0f, recompui::Unit::Percent);
                    button->set_top(panel_button_top(k) * 100.0f, recompui::Unit::Percent);
                    button->set_width(panel_width * 100.0f, recompui::Unit::Percent);
                    button->set_height(button_height * 100.0f, recompui::Unit::Percent);
                    button->set_justify_content(recompui::JustifyContent::Center);
                    button->set_align_items(recompui::AlignItems::Center);
                    button->set_border_radius(recompui::theme::border::radius_md);
                    button->set_background_color(recompui::theme::color::ModalOverlay);
                    button->set_pointer_events(recompui::PointerEvents::None);
                    recompui::Label* button_text = ctx.create_element<recompui::Label>(button, button_names[k], recompui::LabelStyle::Small);
                    button_text->set_pointer_events(recompui::PointerEvents::None);
                    panel_buttons[k] = button;
                }
                ctx.close();
                ctx.set_captures_input(false);
                ctx.set_captures_mouse(false);
                context = ctx;
                return true;
            } catch (...) {
                return false;
            }
        }

        void update(bool show, const std::string& text, float x, float y) {
            if ((context == recompui::ContextId::null()) && (!show || !build())) {
                return;
            }
            auto lifetime = recompui::lock_context_lifetime();
            if (!recompui::contexts_alive()) {
                return;
            }
            if (show) {
                context.open();
                label->set_text(text);
                static const recompinput::GameInput key_inputs[2] = { recompinput::GameInput::PICK_SAVE, recompinput::GameInput::PICK_DELETE };
                for (int k = 0; k < 2; k++) {
                    const std::string keys = tooie::hotkeys::binding_text(key_inputs[k]);
                    if (keys != shown_keys[k]) {
                        key_glyphs[k]->set_text(keys);
                        key_glyphs[k]->set_display(keys.empty() ? recompui::Display::None : recompui::Display::Block);
                        key_unbound[k]->set_display(keys.empty() ? recompui::Display::Block : recompui::Display::None);
                        shown_keys[k] = keys;
                    }
                }
                // Just below and right of the cursor, on the other side near the window's right or bottom edge.
                if (x < 0.75f) {
                    box->unset_right();
                    box->set_left(x * 100.0f + 1.5f, recompui::Unit::Percent);
                } else {
                    box->unset_left();
                    box->set_right((1.0f - x) * 100.0f + 1.5f, recompui::Unit::Percent);
                }
                if (y < 0.8f) {
                    box->unset_bottom();
                    box->set_top(y * 100.0f + 2.5f, recompui::Unit::Percent);
                } else {
                    box->unset_top();
                    box->set_bottom((1.0f - y) * 100.0f + 2.5f, recompui::Unit::Percent);
                }
                context.close();
                if (!recompui::is_context_shown(context)) {
                    recompui::show_context(context, "");
                }
                shown = true;
            } else if (shown) {
                if (recompui::is_context_shown(context)) {
                    recompui::hide_context(context);
                }
                shown = false;
                shown_count = SIZE_MAX;
                shown_hover = -2;
            }
        }

        // The unsaved count and the Save All button's highlight, when they change (after update has shown the label).
        void update_panel(size_t unsaved, PanelButton hover) {
            if (!shown || ((unsaved == shown_count) && (int(hover) == shown_hover))) {
                return;
            }
            auto lifetime = recompui::lock_context_lifetime();
            if (!recompui::contexts_alive()) {
                return;
            }
            context.open();
            count_label->set_text(std::to_string(unsaved) + (unsaved == 1 ? " is unsaved" : " are unsaved"));
            for (int k = 0; k < 2; k++) {
                panel_buttons[k]->set_background_color((int(hover) == k) ? recompui::theme::color::PrimaryA80 : recompui::theme::color::ModalOverlay);
            }
            context.close();
            shown_count = unsaved;
            shown_hover = int(hover);
        }
    };

    // Headless: TOOIE_PICK="<x>,<y>" (fractions of the window) turns pick mode on with the cursor there, and
    // TOOIE_PICK_CLICKS="<ms>:left|right|middle|reset|deeper;..." clicks that long after start.
    struct Click {
        int64_t at;
        std::string what;
    };

    void worker() {
        load();
        load_effects();
        float forced_x = -1.0f, forced_y = -1.0f;
        if (const char* v = std::getenv("TOOIE_PICK")) {
            std::sscanf(v, "%f,%f", &forced_x, &forced_y);
        }
        std::vector<Click> script;
        if (const char* v = std::getenv("TOOIE_PICK_CLICKS")) {
            std::string s = v;
            size_t pos = 0;
            while (pos < s.size()) {
                size_t end = s.find(';', pos);
                std::string item = s.substr(pos, (end == std::string::npos) ? std::string::npos : end - pos);
                size_t colon = item.find(':');
                if (colon != std::string::npos) {
                    script.push_back({ std::atoll(item.substr(0, colon).c_str()), item.substr(colon + 1) });
                }
                pos = (end == std::string::npos) ? s.size() : end + 1;
            }
        }
        const auto start = std::chrono::steady_clock::now();
        Label label;
        // One pick mode at a time. TOOIE_PICK_MODE=effects or interp: the headless pick is that mode's.
        enum Mode { mode_off, mode_parallax, mode_effects, mode_interp };
        Mode mode = mode_off;
        if (forced_x >= 0.0f) {
            const char* forced = std::getenv("TOOIE_PICK_MODE");
            const std::string name = forced != nullptr ? forced : "";
            mode = name == "effects" ? mode_effects : (name == "interp" ? mode_interp : mode_parallax);
        }
        bool key_was_down[3] = {};
        bool save_was_down = false, delete_was_down = false;
        bool copy_was_down = false, paste_was_down = false, undo_was_down = false;
        // Undo Pick's history: each texture or model as it was before a change, newest last.
        struct Undo {
            Mode mode;
            uint64_t key;
            bool had;
            Pick pick;
            Effect effect;
            int interp_mode;
            bool no_effects;
        };
        std::vector<Undo> undo_stack;
        // Copy Pick's copy (Paste Pick puts it on what is under the cursor, in the same mode).
        Undo copied{ mode_off, 0, false, Pick{}, tooie::effect_pick::effect_disable, 0, false };
        // The texture or model's state now, in the mode's terms.
        auto snapshot = [&](Mode m, uint64_t key) {
            Undo u{ m, key, false, Pick{}, tooie::effect_pick::effect_disable, tooie::interp_tags::mode_default, false };
            if (m == mode_parallax) {
                u.had = pick_of(key, u.pick);
            } else if (m == mode_effects) {
                u.had = effect_of(key, u.effect);
            } else if (m == mode_interp) {
                tooie::interp_tags::live(uint32_t(key), u.interp_mode, u.no_effects);
                u.had = true;
            }
            return u;
        };
        // Puts a snapshot's state on a texture or model (key), as a change the pick modes see at once.
        auto apply = [&](const Undo& u, uint64_t key) {
            if (u.mode == mode_parallax) {
                set(key, u.had ? &u.pick : nullptr);
            } else if (u.mode == mode_effects) {
                set_effect(key, u.had, u.effect);
            } else if (u.mode == mode_interp) {
                tooie::interp_tags::set_live(uint32_t(key), u.interp_mode, u.no_effects);
            }
        };
        auto remember = [&](Mode m, uint64_t key) {
            if (key == 0) {
                return;
            }
            undo_stack.push_back(snapshot(m, key));
            if (undo_stack.size() > 200) {
                undo_stack.erase(undo_stack.begin());
            }
        };
        uint32_t buttons_were = 0;
        int32_t wheel_was = recompinput::get_mouse_wheel_pos();
        uint32_t layer = 0;
        uint64_t shown_hash = 0;
        uint32_t shown_layers = 0;
        uint32_t shown_version = 0;
        float shown_x = -1.0f, shown_y = -1.0f;
        int64_t last_log = 0;
        for (;;) {
            std::this_thread::sleep_for(10ms);
            static const recompinput::GameInput keys[3] = { recompinput::GameInput::PARALLAX_PICK, recompinput::GameInput::EFFECTS_PICK,
                recompinput::GameInput::INTERP_PICK };
            static const char* on_toasts[3] = {
                "Parallax pick mode: left click shape, right click depth, middle click shadows, Shift + left click built-in, wheel deeper",
                "Shader Effects pick mode: left click steps Disable, Grass, Deep Snow, Ice Reflection, built-in; Shift + left click built-in, wheel deeper",
                "Interpolation pick mode: left click steps the model's blend (snap, vertex, untagged, default), middle click its screen effects, "
                    "Shift + left click default, wheel deeper (needs interpolation on)" };
            static const char* off_toasts[3] = { "Parallax pick mode off", "Shader Effects pick mode off", "Interpolation pick mode off" };
            for (int k = 0; k < 3; k++) {
                const bool down = tooie::hotkeys::down(keys[k]);
                if (down && !key_was_down[k]) {
                    // The newer mode wins.
                    const Mode pressed_mode = Mode(mode_parallax + k);
                    mode = (mode == pressed_mode) ? mode_off : pressed_mode;
                    layer = 0;
                    tooie::toast::show(mode == pressed_mode ? on_toasts[k] : off_toasts[k]);
                }
                key_was_down[k] = down;
            }
            const bool on = (mode == mode_parallax);
            const bool effects_on = (mode == mode_effects);
            const bool interp_on = (mode == mode_interp);
            recompinput::set_pick_mode(mode != mode_off);
            // The game highlights a picked model itself.
            RT64::SetScenePickHighlight(!interp_on);
            tooie::interp_tags::set_mouse_pick(interp_on, interp_on ? RT64::ScenePickMatrixId() : 0);
            if (mode == mode_off) {
                RT64::SetScenePick(false, 0.0f, 0.0f, 0);
                label.update(false, "", 0.0f, 0.0f);
                buttons_were = 0;
                wheel_was = recompinput::get_mouse_wheel_pos();
                continue;
            }

            // The cursor as a fraction of the window.
            float x = forced_x, y = forced_y;
            uint32_t buttons = 0;
            SDL_Window* window = SDL_GetMouseFocus();
            if (window == nullptr) {
                window = SDL_GetKeyboardFocus();
            }
            if (forced_x < 0.0f) {
                int mx = 0, my = 0, w = 1, h = 1;
                buttons = SDL_GetMouseState(&mx, &my);
                if (window != nullptr) {
                    SDL_GetWindowSize(window, &w, &h);
                }
                x = float(mx) / float(std::max(w, 1));
                y = float(my) / float(std::max(h, 1));
            }
            const bool shift = (SDL_GetModState() & KMOD_SHIFT) != 0;
            const uint32_t pressed = buttons & ~buttons_were;
            buttons_were = buttons;
            bool left = (pressed & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;
            bool right = (pressed & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0;
            bool middle = (pressed & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0;
            bool reset = left && shift;
            left = left && !shift;
            // Wheel down goes a layer deeper, up a layer back.
            const int32_t wheel = recompinput::get_mouse_wheel_pos();
            int32_t deeper = wheel_was - wheel;
            wheel_was = wheel;
            const int64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
            bool press_save = false, press_delete = false, press_save_all = false, press_discard = false;
            bool press_copy = false, press_paste = false, press_undo = false;
            int32_t depth_steps = 0;
            while (!script.empty() && (script.front().at <= ms)) {
                const std::string& what = script.front().what;
                press_save = press_save || (what == "save");
                press_save_all = press_save_all || (what == "saveall");
                press_discard = press_discard || (what == "discard");
                press_delete = press_delete || (what == "delete");
                left = left || (what == "left");
                right = right || (what == "right");
                middle = middle || (what == "middle");
                reset = reset || (what == "reset");
                deeper += (what == "deeper") ? 1 : 0;
                press_copy = press_copy || (what == "copy");
                press_paste = press_paste || (what == "paste");
                press_undo = press_undo || (what == "undo");
                depth_steps += (what == "depthup") ? 1 : ((what == "depthdown") ? -1 : 0);
                script.erase(script.begin());
            }
            // A left click on Save All saves every unsaved pick of this mode, and on Delete All Changes puts every pick
            // back as the file has it, instead of picking what is under them.
            const PanelButton hover_panel = panel_button_at(x, y);
            if (hover_panel != panel_none) {
                press_save_all = press_save_all || ((left || reset) && (hover_panel == panel_save_all));
                press_discard = press_discard || ((left || reset) && (hover_panel == panel_discard));
                left = right = middle = reset = false;
            }
            // The Save Pick and Delete Saved Pick keys act on the texture or model under the cursor.
            const bool save_down = tooie::hotkeys::down(recompinput::GameInput::PICK_SAVE);
            const bool delete_down = tooie::hotkeys::down(recompinput::GameInput::PICK_DELETE);
            press_save = press_save || (save_down && !save_was_down);
            press_delete = press_delete || (delete_down && !delete_was_down);
            save_was_down = save_down;
            delete_was_down = delete_down;
            // Copy Pick, Paste Pick and Undo Pick.
            const bool copy_down = tooie::hotkeys::down(recompinput::GameInput::PICK_COPY);
            const bool paste_down = tooie::hotkeys::down(recompinput::GameInput::PICK_PASTE);
            const bool undo_down = tooie::hotkeys::down(recompinput::GameInput::PICK_UNDO);
            press_copy = press_copy || (copy_down && !copy_was_down);
            press_paste = press_paste || (paste_down && !paste_was_down);
            press_undo = press_undo || (undo_down && !undo_was_down);
            copy_was_down = copy_down;
            paste_was_down = paste_down;
            undo_was_down = undo_down;
            // In parallax pick mode, Shift + wheel steps the depth by 10% (down deeper) instead of the layer.
            if (on && shift && (deeper != 0)) {
                depth_steps += deeper;
                deeper = 0;
            }
            if (deeper > 0) {
                layer += uint32_t(deeper);
            } else if (deeper < 0) {
                layer = (uint32_t(-deeper) > layer) ? 0 : layer - uint32_t(-deeper);
            }
            if ((shown_layers > 0) && (layer >= shown_layers)) {
                layer %= shown_layers;
            }
            RT64::SetScenePick(true, x, y, layer);
            uint64_t hash = 0;
            uint32_t layers = 0;
            RT64::ScenePickResult(hash, layers);
            // The unsaved count and Save All, every poll (they only change the page when they change).
            auto show_panel = [&] {
                const size_t unsaved = interp_on ? tooie::interp_tags::unsaved_count() : (effects_on ? effects_unsaved_count() : unsaved_count());
                label.update_panel(unsaved, hover_panel);
            };
            if (press_discard) {
                const size_t count = interp_on ? tooie::interp_tags::discard_changes() : (effects_on ? discard_effect_changes() : discard_changes());
                char text[96];
                snprintf(text, sizeof(text), "Deleted all changes: %zu back as Dev Files/%s has them", count,
                    interp_on ? "interp_tags.txt" : (effects_on ? "shader_effect_tags.txt" : "parallax_tags.txt"));
                tooie::toast::show(text);
                fprintf(stderr, "[pick] %s\n", text);
                shown_hash = UINT64_MAX;
            }
            if (press_save_all) {
                const size_t count = interp_on ? tooie::interp_tags::save() : (effects_on ? save_all_effects() : save_all());
                char text[96];
                snprintf(text, sizeof(text), "Saved all: %zu picks in Dev Files/%s", count,
                    interp_on ? "interp_tags.txt" : (effects_on ? "shader_effect_tags.txt" : "parallax_tags.txt"));
                tooie::toast::show(text);
                fprintf(stderr, "[pick] %s\n", text);
                shown_hash = UINT64_MAX;
            }
            {
                // What the keys act on: the texture under the cursor, or in interpolation pick mode its model.
                const uint64_t key = interp_on ? uint64_t(tooie::interp_tags::hovered()) : hash;
                char text[160] = {};
                if (press_undo) {
                    if (undo_stack.empty() || (undo_stack.back().mode != mode)) {
                        snprintf(text, sizeof(text), "Nothing to undo in this pick mode");
                    } else {
                        const Undo u = undo_stack.back();
                        undo_stack.pop_back();
                        apply(u, u.key);
                        snprintf(text, sizeof(text), "Undone: %016llx as it was", (unsigned long long)u.key);
                    }
                } else if (press_copy) {
                    if (key == 0) {
                        snprintf(text, sizeof(text), "Nothing under the cursor to copy");
                    } else {
                        copied = snapshot(mode, key);
                        snprintf(text, sizeof(text), "Copied %016llx's pick", (unsigned long long)key);
                    }
                } else if (press_paste) {
                    if (key == 0) {
                        snprintf(text, sizeof(text), "Nothing under the cursor to paste on");
                    } else if (copied.mode != mode) {
                        snprintf(text, sizeof(text), "Copy a pick in this pick mode first");
                    } else {
                        remember(mode, key);
                        apply(copied, key);
                        snprintf(text, sizeof(text), "Pasted onto %016llx (not saved yet)", (unsigned long long)key);
                    }
                } else if ((depth_steps != 0) && (hash != 0)) {
                    remember(mode, hash);
                    bool own = false;
                    Pick pick = current(hash, own);
                    const int percent = std::clamp(pick.depth_percent() / 10 + int(depth_steps), 1, 31) * 10;
                    pick.off = false;
                    pick.fine = uint8_t(percent / 10);
                    set(hash, &pick);
                    snprintf(text, sizeof(text), "%016llx: depth %d%%", (unsigned long long)hash, percent);
                }
                if (text[0] != '\0') {
                    tooie::toast::show(text);
                    fprintf(stderr, "[pick] %s\n", text);
                    shown_hash = UINT64_MAX;
                }
            }
            if (press_save || press_delete) {
                if (press_delete) {
                    remember(mode, interp_on ? uint64_t(tooie::interp_tags::hovered()) : hash);
                }
                const uint32_t model = interp_on ? tooie::interp_tags::hovered() : 0;
                const char* file = interp_on ? "interp_tags.txt" : (effects_on ? "shader_effect_tags.txt" : "parallax_tags.txt");
                char name[32];
                if (interp_on) {
                    snprintf(name, sizeof(name), "Model %08X", model);
                } else {
                    snprintf(name, sizeof(name), "%016llx", (unsigned long long)hash);
                }
                char text[192];
                if (interp_on ? (model == 0) : (hash == 0)) {
                    snprintf(text, sizeof(text), "Nothing under the cursor to %s", press_save ? "save" : "delete");
                } else if (press_save) {
                    if (interp_on) {
                        tooie::interp_tags::save_one(model);
                    } else if (effects_on) {
                        save_one_effect(hash);
                    } else {
                        save_one(hash);
                    }
                    snprintf(text, sizeof(text), "%s saved to Dev Files/%s", name, file);
                } else {
                    if (interp_on) {
                        tooie::interp_tags::unsave(model);
                    } else if (effects_on) {
                        delete_saved_effect(hash);
                    } else {
                        delete_saved(hash);
                    }
                    snprintf(text, sizeof(text), "%s: save deleted from Dev Files/%s, back to %s", name, file, interp_on ? "default" : "built-in");
                }
                tooie::toast::show(text);
                fprintf(stderr, "[pick] %s\n", text);
                shown_hash = UINT64_MAX;
            }
            if (interp_on) {
                const uint32_t model = tooie::interp_tags::hovered();
                if ((model != 0) && (model == tooie::interp_tags::picked())) {
                    if (left || middle || reset) {
                        remember(mode, model);
                    }
                    if (reset) {
                        tooie::interp_tags::reset(model);
                    } else if (left) {
                        tooie::interp_tags::request_tag();
                    } else if (middle) {
                        tooie::interp_tags::request_effects();
                    }
                }
                std::string text;
                if (model == 0) {
                    // Level pieces have no model; nothing has one at the Original refresh rate (no interpolation).
                    text = "No model here";
                } else {
                    char line[48];
                    snprintf(line, sizeof(line), "Model %08X\n", model);
                    text = line + tooie::interp_tags::describe(model);
                    if (layers > 1) {
                        text += "\nLayer " + std::to_string((layer % layers) + 1) + " of " + std::to_string(layers);
                    }
                }
                if ((left || middle || reset) && (model != 0)) {
                    fprintf(stderr, "[interp-pick] %08X click\n", model);
                }
                // The tag shows a scene after the click, so the label is refreshed every few polls.
                static int refresh = 0;
                if ((++refresh % 10 == 0) || (hash != shown_hash) || (std::abs(x - shown_x) > 0.002f) || (std::abs(y - shown_y) > 0.002f)) {
                    label.update(true, text, x, y);
                    if ((hash != shown_hash) && (ms - last_log > 200)) {
                        fprintf(stderr, "[interp-pick] under the cursor: model %08X (%s)\n", model, text.c_str());
                        last_log = ms;
                    }
                    shown_hash = hash;
                    shown_x = x;
                    shown_y = y;
                }
                show_panel();
                continue;
            }
            if (effects_on) {
                if ((hash != 0) && (left || reset)) {
                    remember(mode, hash);
                    step_effect(hash, reset);
                    fprintf(stderr, "[effect-pick] %016llx %s\n", (unsigned long long)hash, describe_effect(hash, layer, layers).c_str());
                }
                const uint32_t version = effects_version.load() + 0x80000000u;
                if ((hash != shown_hash) || (layers != shown_layers) || (version != shown_version) ||
                    (std::abs(x - shown_x) > 0.002f) || (std::abs(y - shown_y) > 0.002f))
                {
                    label.update(true, describe_effect(hash, layer, layers), x, y);
                    if ((hash != shown_hash) && (ms - last_log > 200)) {
                        fprintf(stderr, "[effect-pick] under the cursor: %016llx, %u layers\n", (unsigned long long)hash, layers);
                        last_log = ms;
                    }
                    shown_hash = hash;
                    shown_layers = layers;
                    shown_version = version;
                    shown_x = x;
                    shown_y = y;
                }
                show_panel();
                continue;
            }
            if ((hash != 0) && (left || right || middle || reset)) {
                remember(mode, hash);
                bool own = false;
                Pick pick = current(hash, own);
                if (reset) {
                    set(hash, nullptr);
                } else {
                    if (left) {
                        // Through the shapes, then off, then round again.
                        if (pick.off) {
                            pick.off = false;
                            pick.shape = tooie::parallax_pick::shape_stone;
                        } else if (pick.shape + 1 >= tooie::parallax_pick::shape_count) {
                            pick.off = true;
                        } else {
                            pick.shape++;
                        }
                    }
                    if (right) {
                        pick.depth = pick.off ? 0 : depth_next[pick.depth];
                        pick.fine = 0;
                        pick.off = false;
                    }
                    if (middle) {
                        pick.shadows = pick.off ? true : !pick.shadows;
                        pick.off = false;
                    }
                    set(hash, &pick);
                }
                fprintf(stderr, "[parallax-pick] %016llx %s\n", (unsigned long long)hash, describe(hash, layer, layers).c_str());
            }
            const uint32_t version = picks_version.load();
            if ((hash != shown_hash) || (layers != shown_layers) || (version != shown_version) ||
                (std::abs(x - shown_x) > 0.002f) || (std::abs(y - shown_y) > 0.002f))
            {
                label.update(true, describe(hash, layer, layers), x, y);
                if ((hash != shown_hash) && (ms - last_log > 200)) {
                    fprintf(stderr, "[parallax-pick] under the cursor: %016llx, %u layers\n", (unsigned long long)hash, layers);
                    last_log = ms;
                }
                shown_hash = hash;
                shown_layers = layers;
                shown_version = version;
                shown_x = x;
                shown_y = y;
            }
            show_panel();
        }
    }
}

void tooie::parallax_pick::start() {
    static std::once_flag once;
    std::call_once(once, [] {
        std::thread(worker).detach();
    });
}

uint32_t tooie::parallax_pick::version() {
    return picks_version.load();
}

void tooie::parallax_pick::for_each(const std::function<void(uint64_t hash, const Pick& pick)>& visit) {
    std::lock_guard lock{ picks_mutex };
    for (const auto& [hash, pick] : picks) {
        visit(hash, pick);
    }
}

uint32_t tooie::effect_pick::version() {
    return effects_version.load();
}

void tooie::effect_pick::for_each(const std::function<void(uint64_t hash, Effect effect)>& visit) {
    std::lock_guard lock{ effects_mutex };
    for (const auto& [hash, effect] : effects) {
        visit(hash, effect);
    }
}

int tooie::parallax_pick::Pick::depth_percent() const {
    return (fine != 0) ? int(fine) * 10 : depth_percents[depth];
}
