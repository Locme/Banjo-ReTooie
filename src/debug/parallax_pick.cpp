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
    std::atomic<uint32_t> picks_version{1};

    const char* shape_names[tooie::parallax_pick::shape_count] = { "stone", "bumpy", "inverted", "cracks", "terraced", "rounded" };
    const char* shape_labels[tooie::parallax_pick::shape_count] = { "Stone", "Bumpy", "Inverted", "Cracks", "Terraced", "Rounded" };
    const int depth_percent[tooie::parallax_pick::depth_count] = { 100, 25, 50, 150, 200, 300 };
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
                for (int d = 0; d < tooie::parallax_pick::depth_count; d++) {
                    if (percent == depth_percent[d]) {
                        pick.depth = uint8_t(d);
                    }
                }
                pick.shadows = (shadows_text != "noshadows");
            }
            picks[std::strtoull(hash_text.c_str(), nullptr, 16)] = pick;
        }
        if (!picks.empty()) {
            fprintf(stderr, "[parallax-pick] %zu picks from %s\n", picks.size(), file_path().string().c_str());
        }
        picks_version.fetch_add(1);
    }

    void save() {
        std::error_code ec;
        std::filesystem::create_directories(file_path().parent_path(), ec);
        std::ofstream out(file_path());
        out << "# Parallax picks (Parallax Pick Mode key): texture, shape, depth, shadows. Send this file in for the port's list.\n";
        std::lock_guard lock{ picks_mutex };
        for (const auto& [hash, pick] : picks) {
            char text[32];
            snprintf(text, sizeof(text), "%016llx", (unsigned long long)hash);
            if (pick.off) {
                out << text << " off\n";
            } else {
                out << text << " " << shape_names[pick.shape] << " " << depth_percent[pick.depth] << "% " << (pick.shadows ? "shadows" : "noshadows") << "\n";
            }
        }
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
        save();
    }

    std::string describe(uint64_t hash, uint32_t layer, uint32_t layers) {
        if (hash == 0) {
            return "No textured surface here";
        }
        bool own = false;
        const Pick pick = current(hash, own);
        char text[160];
        if (pick.off) {
            snprintf(text, sizeof(text), "%016llx\nOff (%s)", (unsigned long long)hash, own ? "yours" : "built-in");
        } else {
            snprintf(text, sizeof(text), "%016llx\n%s, %d%%, %s (%s)", (unsigned long long)hash, shape_labels[pick.shape],
                depth_percent[pick.depth], pick.shadows ? "shadows" : "no shadows", own ? "yours" : "built-in");
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
        effects_version.fetch_add(1);
    }

    void save_effects() {
        std::error_code ec;
        std::filesystem::create_directories(effects_path().parent_path(), ec);
        std::ofstream out(effects_path());
        out << "# Shader effect picks (Shader Effects Pick Mode key): texture, effect (disable, grass, deep_snow, ice). Send this file in for the port's lists.\n";
        std::lock_guard lock{ effects_mutex };
        for (const auto& [hash, effect] : effects) {
            char text[32];
            snprintf(text, sizeof(text), "%016llx", (unsigned long long)hash);
            out << text << " " << effect_names[effect] << "\n";
        }
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
        {
            std::lock_guard lock{ effects_mutex };
            const auto it = effects.find(hash);
            own = (it != effects.end());
            if (own) {
                effect = it->second;
            }
        }
        if (own) {
            snprintf(text, sizeof(text), "%016llx\n%s (yours)", (unsigned long long)hash, effect_labels[effect]);
        } else {
            snprintf(text, sizeof(text), "%016llx\n%s (built-in)", (unsigned long long)hash, built_in_effect(hash));
        }
        std::string result = text;
        if (layers > 1) {
            result += "\nLayer " + std::to_string((layer % layers) + 1) + " of " + std::to_string(layers);
        }
        return result;
    }

    // Left click: built-in, Disable, Grass, Deep Snow, Ice Reflection, built-in again.
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
        save_effects();
    }

    // The label beside the cursor.
    struct Label {
        recompui::ContextId context = recompui::ContextId::null();
        recompui::Element* box = nullptr;
        recompui::Label* label = nullptr;
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
                label = ctx.create_element<recompui::Label>(box, "", recompui::LabelStyle::Small);
                label->set_pointer_events(recompui::PointerEvents::None);
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
            }
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
            while (!script.empty() && (script.front().at <= ms)) {
                const std::string& what = script.front().what;
                left = left || (what == "left");
                right = right || (what == "right");
                middle = middle || (what == "middle");
                reset = reset || (what == "reset");
                deeper += (what == "deeper") ? 1 : 0;
                script.erase(script.begin());
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
            if (interp_on) {
                const uint32_t model = tooie::interp_tags::hovered();
                if ((model != 0) && (model == tooie::interp_tags::picked())) {
                    if (reset) {
                        tooie::interp_tags::request_unsave();
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
                continue;
            }
            if (effects_on) {
                if ((hash != 0) && (left || reset)) {
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
                continue;
            }
            if ((hash != 0) && (left || right || middle || reset)) {
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
