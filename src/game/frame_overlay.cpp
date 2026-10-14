// Frame rate overlay: one Graphics option that shows, in the top left corner,
// the frame rate and frame time actually presented, the worst frame, the GPU
// time, the game's own frame rate, the Framerate setting and what frame
// interpolation tagged; then the 1% low and hitches over the last 5 s, the
// map and Banjo's position, the renderer, and whether speed-up, cheats or
// mods are on (so a screenshot of a glitch carries what is needed to find it).
//
// Nothing here times frames itself. The presented frames come from RT64's own
// present timer (presentProfiler) and the GPU time from its renderer timestamps
// (lib-patches/rt64.patch, RT64::TakeFrameStats); the game's frames from the
// 3D scenes counted by model_tagging.cpp, with the interpolation figures. The
// thread below wakes four times a second, averages what arrived since the last
// wake and rewrites the text, so the overlay costs the frame loop nothing but
// drawing a few lines of UI text.

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <mutex>
#include <string>
#include <thread>
#include <variant>
#include <vector>

#include "recompui/config.h"
#include "recompui/recompui.h"
#include "elements/ui_element.h"
#include "elements/ui_label.h"
#include "ultramodern/config.hpp"
#include "ultramodern/ultramodern.hpp"
#include "librecomp/mods.hpp"

#include "tooie_cheats.h"
#include "tooie_debug.h"
#include "tooie_frame_overlay.h"
#include "tooie_model_tagging.h"
#include "tooie_watchdog.h"

namespace RT64 {
    // lib/rt64/src/hle/rt64_present_queue.h (from lib-patches/rt64.patch).
    struct FrameStats {
        uint32_t presents = 0;
        double presentMs = 0.0;
        double worstPresentMs = 0.0;
        uint32_t gpuFrames = 0;
        double gpuMs = 0.0;
        std::vector<float> intervals;
    };
    FrameStats TakeFrameStats();
}

namespace {
    using namespace std::chrono_literals;
    using clock_type = std::chrono::steady_clock;

    constexpr auto update_interval = 250ms;
    // Wait for the UI to come up before building the overlay.
    constexpr auto ui_wait = 500ms;
    constexpr size_t max_lines = 12;
    // How far back the 1% low and the hitch count look.
    constexpr auto stutter_window = 5s;
    // A hitch: a frame more than this many times the median frame.
    constexpr float hitch_factor = 2.0f;

    // PlayerState pointers by player at 0x80135490; PlayerState +0xE4 points at
    // Banjo's position (as in free_camera.cpp).
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t player_transform = 0xE4;

    struct MapName {
        uint16_t id;
        const char* name;
    };

    constexpr MapName map_names[] = {
#include "map_names.inc"
    };

    uint8_t* game_rdram = nullptr;

    std::once_flag start_once;
    bool created = false;

    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(recompui::config::graphics::id);
    }

    bool enabled() {
        // For headless runs: shows the overlay whatever the setting says.
        static const bool forced = std::getenv("TOOIE_FRAME_OVERLAY") != nullptr;
        if (forced) {
            return true;
        }
        if (!created) {
            return false;
        }
        try {
            return std::get<bool>(graphics_config().get_option_value(tooie::frame_overlay::option));
        } catch (...) {
            return false;
        }
    }

    struct Overlay {
        recompui::ContextId context = recompui::ContextId::null();
        std::vector<recompui::Label*> lines;
        bool shown = false;
    };

    bool build(Overlay& o) {
        try {
            recompui::ContextId ctx = recompui::create_context();
            ctx.open();
            recompui::Element* root = ctx.create_element<recompui::Element>(ctx.get_root_element());
            root->set_display(recompui::Display::Flex);
            root->set_background_color(recompui::theme::color::Transparent);
            root->set_pointer_events(recompui::PointerEvents::None);

            recompui::Element* box = ctx.create_element<recompui::Element>(root);
            box->set_display(recompui::Display::Flex);
            box->set_flex_direction(recompui::FlexDirection::Column);
            box->set_position(recompui::Position::Absolute);
            box->set_top(16);
            box->set_left(16);
            box->set_padding(10);
            box->set_border_radius(recompui::theme::border::radius_md);
            box->set_background_color(recompui::theme::color::ModalOverlay);
            box->set_pointer_events(recompui::PointerEvents::None);

            // One label per line: a label is laid out as a single line.
            for (size_t i = 0; i < max_lines; i++) {
                recompui::Label* line = ctx.create_element<recompui::Label>(box, "", recompui::LabelStyle::Small);
                line->set_pointer_events(recompui::PointerEvents::None);
                o.lines.push_back(line);
            }
            ctx.close();

            // The overlay must never swallow the game's input.
            ctx.set_captures_input(false);
            ctx.set_captures_mouse(false);
            o.context = ctx;
            return true;
        } catch (...) {
            return false;
        }
    }

    // The game start clears every shown context, so check the real state each time.
    void show(Overlay& o) {
        if (!recompui::is_context_shown(o.context)) {
            recompui::show_context(o.context, "");
        }
        o.shown = true;
    }

    void hide(Overlay& o) {
        if (o.shown && recompui::is_context_shown(o.context)) {
            recompui::hide_context(o.context);
        }
        o.shown = false;
    }

    std::string framerate_setting() {
        const auto& config = ultramodern::renderer::get_graphics_config();
        switch (config.rr_option) {
            case ultramodern::renderer::RefreshRate::Original:
                return "Original";
            case ultramodern::renderer::RefreshRate::Display:
                return "Display";
            case ultramodern::renderer::RefreshRate::Manual:
                return "Manual (" + std::to_string(config.rr_manual_value) + ")";
            default:
                return "?";
        }
    }

    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x80800000u;
    }

    uint32_t read_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }

    float read_float(uint8_t* rdram, uint32_t addr) {
        uint32_t bits = read_word(rdram, addr);
        float value;
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }

    // Present intervals of the last few seconds, for the 1% low and hitches.
    struct Interval {
        clock_type::time_point taken;
        float ms;
    };
    std::deque<Interval> recent;

    void add_intervals(const std::vector<float>& intervals, clock_type::time_point now) {
        for (float ms : intervals) {
            recent.push_back({ now, ms });
        }
        while (!recent.empty() && now - recent.front().taken > stutter_window) {
            recent.pop_front();
        }
    }

    std::string stutter_line() {
        if (recent.size() < 10) {
            return "1% low: not enough frames yet";
        }
        std::vector<float> sorted;
        sorted.reserve(recent.size());
        for (const Interval& i : recent) {
            sorted.push_back(i.ms);
        }
        std::sort(sorted.begin(), sorted.end());
        float median = sorted[sorted.size() / 2];
        // The frame time 99% of frames beat: the "1% low" frame rate is 1000 / it.
        float low = sorted[std::min(sorted.size() - 1, sorted.size() * 99 / 100)];
        size_t hitches = (size_t)(sorted.end() - std::upper_bound(sorted.begin(), sorted.end(), median * hitch_factor));
        char line[160];
        std::snprintf(line, sizeof(line), "1%% low %.0f fps (%.2f ms), %zu hitch%s in 5 s",
            1000.0f / low, low, hitches, hitches == 1 ? "" : "es");
        return line;
    }

    std::string map_line(uint8_t* rdram) {
        uint16_t map = tooie::debug::current_map(rdram);
        const char* name = "unknown";
        for (const MapName& m : map_names) {
            if (m.id == map) {
                name = m.name;
                break;
            }
        }
        char line[200];
        std::snprintf(line, sizeof(line), "Map %X: %s", map, name);
        return line;
    }

    std::string position_line(uint8_t* rdram) {
        uint32_t player = read_word(rdram, player_table);
        uint32_t transform = valid_ptr(player) ? read_word(rdram, player + player_transform) : 0;
        if (!valid_ptr(transform)) {
            return "Banjo: not in play";
        }
        char line[160];
        std::snprintf(line, sizeof(line), "Banjo at %.0f, %.0f, %.0f",
            read_float(rdram, transform), read_float(rdram, transform + 4), read_float(rdram, transform + 8));
        return line;
    }

    std::string renderer_line() {
        const auto& config = ultramodern::renderer::get_graphics_config();
        tooie::watchdog::RendererInfo info = tooie::watchdog::renderer_info();
        const char* api = "?";
        switch (info.api) {
            case ultramodern::renderer::GraphicsApi::D3D12: api = "D3D12"; break;
            case ultramodern::renderer::GraphicsApi::Vulkan: api = "Vulkan"; break;
            case ultramodern::renderer::GraphicsApi::Metal: api = "Metal"; break;
            default: break;
        }
        const char* resolution = "Auto";
        switch (config.res_option) {
            case ultramodern::renderer::Resolution::Original: resolution = "Original"; break;
            case ultramodern::renderer::Resolution::Original2x: resolution = "Original 2x"; break;
            default: break;
        }
        const char* msaa = "no MSAA";
        switch (config.msaa_option) {
            case ultramodern::renderer::Antialiasing::MSAA2X: msaa = "MSAA 2x"; break;
            case ultramodern::renderer::Antialiasing::MSAA4X: msaa = "MSAA 4x"; break;
            case ultramodern::renderer::Antialiasing::MSAA8X: msaa = "MSAA 8x"; break;
            default: break;
        }
        char line[200];
        std::snprintf(line, sizeof(line), "%s, %.2fx resolution (%s), %s, display %u Hz",
            api, info.resolution_scale, resolution, msaa, info.display_rate);
        return line;
    }

    // Enabled mods by name, looked up every 2 s (the list takes the mod lock).
    std::string mods_text = "none";

    void refresh_mods() {
        std::string names;
        try {
            for (const recomp::mods::ModDetails& mod : recomp::mods::get_all_mod_details("bt")) {
                if (recomp::mods::is_mod_enabled(mod.mod_id)) {
                    names += (names.empty() ? "" : ", ") + mod.display_name;
                }
            }
        } catch (...) {
        }
        mods_text = names.empty() ? "none" : names;
    }

    std::string extras_line() {
        uint32_t speed = ultramodern::get_speed_multiplier();
        std::string text = speed > 1 ? "Speed-up " + std::to_string(speed) + "x" : "Speed-up off";
        text += tooie::cheats::enabled() ? ", cheats on" : ", cheats off";
        text += ", mods: " + mods_text;
        return text;
    }

    std::vector<std::string> format(const RT64::FrameStats& frames, uint64_t game_frames, double seconds) {
        char line[160];
        std::vector<std::string> text;

        if (frames.presents > 0) {
            double ms = frames.presentMs / frames.presents;
            std::snprintf(line, sizeof(line), "%.0f fps, %.2f ms frame time", 1000.0 / ms, ms);
            text.push_back(line);
            std::snprintf(line, sizeof(line), "Worst frame %.2f ms", frames.worstPresentMs);
            text.push_back(line);
        }
        else {
            text.push_back("No frames presented");
        }
        if (frames.gpuFrames > 0) {
            std::snprintf(line, sizeof(line), "GPU %.2f ms per game frame", frames.gpuMs / frames.gpuFrames);
            text.push_back(line);
        }
        std::snprintf(line, sizeof(line), "Game %.0f fps", seconds > 0.0 ? game_frames / seconds : 0.0);
        text.push_back(line);
        text.push_back("Framerate: " + framerate_setting());

        tooie::model_tagging::Stats tags = tooie::model_tagging::last_stats();
        if (tags.interpolating) {
            std::snprintf(line, sizeof(line), "Interpolation on: %u models, %u bones, %u shadows",
                tags.models, tags.bones, tags.shadows);
            text.push_back(line);
            std::snprintf(line, sizeof(line), "Camera cuts %u", tags.camera_cuts);
            text.push_back(line);
        }
        else {
            text.push_back("Interpolation off");
        }

        text.push_back(stutter_line());
        if (game_rdram != nullptr) {
            text.push_back(map_line(game_rdram));
            text.push_back(position_line(game_rdram));
        }
        text.push_back(renderer_line());
        text.push_back(extras_line());
        return text;
    }

    void worker() {
        Overlay overlay;
        struct GameSample {
            uint64_t frames = 0;
            clock_type::time_point time;
        };
        std::array<GameSample, 9> game_window{};
        game_window[0] = { tooie::model_tagging::last_stats().scenes, clock_type::now() };
        size_t window_next = 1;
        size_t window_filled = 1;
        for (;;) {
            std::this_thread::sleep_for(update_interval);

            // Taken every time, so turning the overlay on starts from fresh figures.
            RT64::FrameStats frames = RT64::TakeFrameStats();
            uint64_t game_frames = tooie::model_tagging::last_stats().scenes;
            auto now = clock_type::now();
            add_intervals(frames.intervals, now);
            static int mod_ticks = 0;
            if (mod_ticks++ % 8 == 0) {
                refresh_mods();
            }

            // The game's frame rate is counted over the last 2 s: a 30 fps game only
            // fits 7 or 8 frames into one 250 ms update, which read as 28 and 32.
            game_window[window_next] = { game_frames, now };
            window_next = (window_next + 1) % game_window.size();
            window_filled = std::min(window_filled + 1, game_window.size());
            const GameSample& oldest = game_window[window_filled < game_window.size() ? 0 : window_next];
            uint64_t game_delta = game_frames - oldest.frames;
            double game_seconds = std::chrono::duration<double>(now - oldest.time).count();

            // TOOIE_FRAME_LOG=1: prints the same figures every 2 s, shown or not.
            static const bool log = std::getenv("TOOIE_FRAME_LOG") != nullptr;
            static int ticks = 0;
            if (log && ++ticks % 8 == 0) {
                std::string joined;
                for (const std::string& line : format(frames, game_delta, game_seconds)) {
                    joined += (joined.empty() ? "" : " | ") + line;
                }
                std::printf("[frames] %s\n", joined.c_str());
                std::fflush(stdout);
            }

            if (!enabled()) {
                if (overlay.shown) {
                    hide(overlay);
                }
                continue;
            }
            if (overlay.context == recompui::ContextId::null() && !build(overlay)) {
                std::this_thread::sleep_for(ui_wait);
                continue;
            }

            std::vector<std::string> text = format(frames, game_delta, game_seconds);
            overlay.context.open();
            for (size_t i = 0; i < overlay.lines.size(); i++) {
                bool used = i < text.size();
                overlay.lines[i]->set_text(used ? text[i] : std::string());
                overlay.lines[i]->set_display(used ? recompui::Display::Block : recompui::Display::None);
            }
            overlay.context.close();
            show(overlay);
        }
    }
}

void tooie::frame_overlay::add_option(recomp::config::Config& graphics) {
    created = true;
    graphics.add_bool_option(
        option,
        "Frame rate overlay",
        "Shows the frame rate, frame time, stutter, GPU time, the game's own frame rate, frame interpolation figures, the map and Banjo's position, the renderer and whether speed-up, cheats or mods are on, in the top left corner.",
        false);
    graphics.add_option_change_callback(option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                // The overlay thread reads the saved value.
                graphics_config().save_config();
            }
        });
}

void tooie::frame_overlay::start(uint8_t* rdram) {
    game_rdram = rdram;
    std::call_once(start_once, [] {
        // Detached on purpose: the thread owns no resources that need a clean shutdown.
        std::thread(worker).detach();
    });
}
