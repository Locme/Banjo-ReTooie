// Frame rate overlay: one Graphics option that shows, in the top left corner,
// the frame rate and frame time actually presented, the worst frame, the GPU
// time, the game's own frame rate and CPU time, the Interpolation setting and what
// frame interpolation tagged; then the 1% low, hitches and shader compiles over the last 5 s, the
// map and Banjo's position, the renderer, and whether speed-up, cheats or
// mods are on (so a screenshot of a glitch carries what is needed to find it);
// the audio queue and its dropouts; the build; and a graph of the last 100
// frame times. Compact shows only the first line. The Frame Rate Overlay
// hotkey (F3) steps Off, Compact, Full for the session; the setting decides
// how a session starts.
//
// Nothing here times frames itself. The presented frames come from RT64's own
// present timer (presentProfiler) and the GPU time from its renderer timestamps
// (lib-patches/rt64.patch, RT64::TakeFrameStats), with its shader compiles; the
// game's frames from the 3D scenes counted by model_tagging.cpp, with the
// interpolation figures; the game's CPU time from the time its idle thread
// waits (lib-patches/N64ModernRuntime.patch, ultramodern::game_idle_ns). The
// thread below wakes four times a second, averages what arrived since the last
// wake and rewrites the text, so the overlay costs the frame loop nothing but
// drawing a few lines of UI text.

#include <algorithm>
#include <atomic>
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

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recompinput/recompinput.h"
#include "recompinput/input_binding.h"
#include "recompinput/profiles.h"
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
#include "tooie_toast.h"
#include "build_info.h"
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
        uint32_t latencyFrames = 0;
        double latencyMs = 0.0;
        double worstLatencyMs = 0.0;
        uint32_t shaderCompiles = 0;
    };
    FrameStats TakeFrameStats();
    void NoteInputRead(int64_t steadyNs);
}

namespace {
    using namespace std::chrono_literals;
    using clock_type = std::chrono::steady_clock;

    constexpr auto update_interval = 250ms;
    // Wait for the UI to come up before building the overlay.
    constexpr auto ui_wait = 500ms;
    constexpr size_t max_lines = 18;
    // The frame time graph: one bar per presented frame, newest on the right.
    constexpr size_t graph_bars = 100;
    constexpr float graph_height = 40.0f;
    constexpr auto key_poll = 16ms;
    constexpr auto overlay_input = recompinput::GameInput::FRAME_OVERLAY;
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

    using tooie::frame_overlay::Mode;

    // Set by the hotkey for this session; -1 follows the setting.
    std::atomic<int> hotkey_mode{-1};

    Mode setting_mode() {
        if (!created) {
            return Mode::Off;
        }
        try {
            return (Mode)std::get<uint32_t>(graphics_config().get_option_value(tooie::frame_overlay::option));
        } catch (...) {
            return Mode::Off;
        }
    }

    Mode current_mode() {
        int from_key = hotkey_mode.load(std::memory_order_relaxed);
        if (from_key >= 0) {
            return (Mode)from_key;
        }
        // For headless runs: TOOIE_FRAME_OVERLAY=1 (or full) shows Full, =compact shows Compact.
        static const char* forced = std::getenv("TOOIE_FRAME_OVERLAY");
        if (forced != nullptr) {
            return std::string(forced) == "compact" ? Mode::Compact : Mode::Full;
        }
        return setting_mode();
    }

    // Whether any key or button bound to Frame Rate Overlay (Controls tab, Hotkeys) is held.
    bool key_down() {
        // Pressing the key to bind it in the Controls tab should not switch the overlay.
        if (recompinput::binding::is_binding()) {
            return false;
        }
        bool down = false;
        for (int profile : { recompinput::profiles::get_sp_keyboard_profile_index(), recompinput::profiles::get_sp_controller_profile_index() }) {
            if (profile < 0) {
                continue;
            }
            for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                down = down || recompinput::get_input_digital(0, recompinput::profiles::get_input_binding(profile, overlay_input, b));
            }
        }
        return down;
    }

    void key_worker() {
        bool was_down = false;
        for (;;) {
            std::this_thread::sleep_for(key_poll);
            bool down = key_down();
            if (down && !was_down) {
                Mode next = (Mode)(((uint32_t)current_mode() + 1) % 3);
                hotkey_mode.store((int)next, std::memory_order_relaxed);
                tooie::toast::show(next == Mode::Off ? "Frame rate overlay off" :
                    next == Mode::Compact ? "Frame rate overlay: Compact" : "Frame rate overlay: Full");
            }
            was_down = down;
        }
    }

    // Input latency over the last 2 s (8 updates), summed from RT64's per-update figures.
    struct LatencyTick {
        uint32_t frames = 0;
        double ms = 0.0;
        double worst = 0.0;
    };
    std::array<LatencyTick, 8> latency_ticks{};
    size_t latency_next = 0;
    uint32_t latency_frames = 0;
    double latency_ms = 0.0;
    double latency_worst = 0.0;

    void add_latency(const RT64::FrameStats& frames) {
        latency_ticks[latency_next] = { frames.latencyFrames, frames.latencyMs, frames.worstLatencyMs };
        latency_next = (latency_next + 1) % latency_ticks.size();
        latency_frames = 0;
        latency_ms = 0.0;
        latency_worst = 0.0;
        for (const LatencyTick& t : latency_ticks) {
            latency_frames += t.frames;
            latency_ms += t.ms;
            latency_worst = std::max(latency_worst, t.worst);
        }
    }

    int64_t steady_ns() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(clock_type::now().time_since_epoch()).count();
    }

    // Controller read times on their way to RT64 (see note_input_read and the others).
    std::atomic<int64_t> last_read_ns{0};
    std::atomic<int64_t> scene_read_ns{0};

    // Audio chunks since the last 2 s summary (note_audio_chunk runs on the audio thread).
    struct AudioStats {
        uint64_t chunks = 0;
        uint64_t sped_up = 0;
        uint64_t dropouts = 0;
        uint64_t min_us = UINT64_MAX;
        uint64_t max_us = 0;
    };
    std::mutex audio_mutex;
    AudioStats audio_now;
    bool audio_started = false;
    std::string audio_text = "Audio: no sound yet";

    struct Overlay {
        recompui::ContextId context = recompui::ContextId::null();
        std::vector<recompui::Label*> lines;
        recompui::Element* graph = nullptr;
        std::vector<recompui::Element*> bars;
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
            box->set_align_items(recompui::AlignItems::FlexStart);
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

            o.graph = ctx.create_element<recompui::Element>(box);
            o.graph->set_display(recompui::Display::Flex);
            o.graph->set_flex_direction(recompui::FlexDirection::Row);
            o.graph->set_align_items(recompui::AlignItems::FlexEnd);
            o.graph->set_height(graph_height);
            o.graph->set_width(graph_bars * 3.0f);
            o.graph->set_margin_top(6);
            o.graph->set_pointer_events(recompui::PointerEvents::None);
            for (size_t i = 0; i < graph_bars; i++) {
                recompui::Element* bar = ctx.create_element<recompui::Element>(o.graph);
                bar->set_display(recompui::Display::Block);
                bar->set_width(3);
                bar->set_height(1);
                bar->set_flex_shrink(0);
                bar->set_background_color(recompui::theme::color::Primary);
                bar->set_pointer_events(recompui::PointerEvents::None);
                o.bars.push_back(bar);
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
                return "Off";
            case ultramodern::renderer::RefreshRate::Display:
                return "Display";
            case ultramodern::renderer::RefreshRate::Manual:
                return "Manual (" + std::to_string(config.rr_manual_value) + ")";
            default:
                return "?";
        }
    }

    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x81000000u;
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

    // Bars scaled so twice the median frame fills the graph; hitches are drawn in red.
    void update_graph(Overlay& o) {
        if (recent.empty()) {
            for (recompui::Element* bar : o.bars) {
                bar->set_height(1);
                bar->set_background_color(recompui::theme::color::Transparent);
            }
            return;
        }
        std::vector<float> sorted;
        for (const Interval& i : recent) {
            sorted.push_back(i.ms);
        }
        std::nth_element(sorted.begin(), sorted.begin() + sorted.size() / 2, sorted.end());
        float median = std::max(sorted[sorted.size() / 2], 0.1f);
        float full = median * hitch_factor;
        size_t count = std::min(graph_bars, recent.size());
        size_t first = graph_bars - count;
        for (size_t i = 0; i < graph_bars; i++) {
            recompui::Element* bar = o.bars[i];
            if (i < first) {
                // Not filled yet; a bar with no height would also lose its width.
                bar->set_height(1);
                bar->set_background_color(recompui::theme::color::Transparent);
                continue;
            }
            float ms = recent[recent.size() - count + (i - first)].ms;
            bar->set_height(std::clamp(ms / full, 0.02f, 1.0f) * graph_height);
            bar->set_background_color(ms > full ? recompui::theme::color::Danger : recompui::theme::color::Primary);
        }
    }

    void summarize_audio() {
        AudioStats stats;
        {
            std::lock_guard lock{ audio_mutex };
            stats = audio_now;
            audio_now = AudioStats();
        }
        if (stats.chunks == 0) {
            return;
        }
        char line[200];
        std::snprintf(line, sizeof(line), "Audio queued %.0f-%.0f ms, %llu dropout%s, %llu sped up (2 s)",
            stats.min_us / 1000.0, stats.max_us / 1000.0,
            (unsigned long long)stats.dropouts, stats.dropouts == 1 ? "" : "s", (unsigned long long)stats.sped_up);
        audio_text = line;
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

    // Shader compiles over the same 5 s as the 1% low: one count per update.
    std::deque<std::pair<clock_type::time_point, uint32_t>> recent_shaders;
    uint64_t shaders_total = 0;

    void add_shaders(uint32_t compiles, clock_type::time_point now) {
        shaders_total += compiles;
        recent_shaders.push_back({ now, compiles });
        while (!recent_shaders.empty() && now - recent_shaders.front().first > stutter_window) {
            recent_shaders.pop_front();
        }
    }

    std::string shader_line() {
        uint32_t recent_count = 0;
        for (const auto& entry : recent_shaders) {
            recent_count += entry.second;
        }
        char line[96];
        std::snprintf(line, sizeof(line), "Shaders compiled: %u in 5 s, %llu this session",
            recent_count, (unsigned long long)shaders_total);
        return line;
    }

    std::vector<std::string> format(const RT64::FrameStats& frames, uint64_t game_frames, double seconds, double game_busy_ms, Mode mode) {
        char line[160];
        std::vector<std::string> text;

        if (frames.presents > 0) {
            double ms = frames.presentMs / frames.presents;
            std::snprintf(line, sizeof(line), "%.0f fps, %.2f ms frame time", 1000.0 / ms, ms);
            text.push_back(line);
            std::snprintf(line, sizeof(line), "Worst frame %.2f ms", frames.worstPresentMs);
            text.push_back(line);
        }
        if (latency_frames > 0) {
            double avg = latency_ms / latency_frames;
            if (!text.empty()) {
                std::snprintf(line, sizeof(line), ", input %.0f ms", avg);
                text[0] += line;
            }
            std::snprintf(line, sizeof(line), "Input latency %.0f ms (worst %.0f ms), controller read to screen", avg, latency_worst);
            text.insert(text.begin() + std::min<size_t>(2, text.size()), line);
        }
        else {
            text.push_back("No frames presented");
        }
        if (mode == Mode::Compact) {
            text.resize(1);
            return text;
        }
        if (frames.gpuFrames > 0) {
            std::snprintf(line, sizeof(line), "GPU %.2f ms per game frame", frames.gpuMs / frames.gpuFrames);
            text.push_back(line);
        }
        std::snprintf(line, sizeof(line), "Game %.0f fps", seconds > 0.0 ? game_frames / seconds : 0.0);
        text.push_back(line);
        if (game_frames > 0 && seconds > 0.0) {
            // The game's code ran whenever its idle thread wasn't waiting.
            std::snprintf(line, sizeof(line), ", CPU %.2f ms per frame (busy %.0f%%)",
                game_busy_ms / game_frames, std::clamp(game_busy_ms / (seconds * 10.0), 0.0, 100.0));
            text.back() += line;
        }
        // One line: the setting, then whether it is blending and what it tagged.
        tooie::model_tagging::Stats tags = tooie::model_tagging::last_stats();
        if (tags.interpolating) {
            std::snprintf(line, sizeof(line), ", on: %u models, %u bones, %u shadows, %u camera cuts",
                tags.models, tags.bones, tags.shadows, tags.camera_cuts);
            text.push_back("Interpolation: " + framerate_setting() + line);
        }
        else {
            text.push_back("Interpolation: " + framerate_setting() + ", off");
        }

        text.push_back(stutter_line());
        text.push_back(shader_line());
        if (game_rdram != nullptr) {
            text.push_back(map_line(game_rdram));
            text.push_back(position_line(game_rdram));
        }
        text.push_back(renderer_line());
        text.push_back(extras_line());
        text.push_back(audio_text);
        text.push_back(std::string("Build ") + TOOIE_GIT_COMMIT + " (" + TOOIE_GIT_DATE + ")");
        return text;
    }

    void worker() {
        Overlay overlay;
        struct GameSample {
            uint64_t frames = 0;
            uint64_t idle_ns = 0;
            clock_type::time_point time;
        };
        std::array<GameSample, 9> game_window{};
        game_window[0] = { tooie::model_tagging::last_stats().scenes, ultramodern::game_idle_ns(), clock_type::now() };
        size_t window_next = 1;
        size_t window_filled = 1;
        for (;;) {
            std::this_thread::sleep_for(update_interval);

            // Taken every time, so turning the overlay on starts from fresh figures.
            RT64::FrameStats frames = RT64::TakeFrameStats();
            uint64_t game_frames = tooie::model_tagging::last_stats().scenes;
            uint64_t idle_ns = ultramodern::game_idle_ns();
            auto now = clock_type::now();
            add_intervals(frames.intervals, now);
            add_shaders(frames.shaderCompiles, now);
            add_latency(frames);
            static int mod_ticks = 0;
            if (mod_ticks++ % 8 == 0) {
                refresh_mods();
                summarize_audio();
            }

            // The game's frame rate is counted over the last 2 s: a 30 fps game only
            // fits 7 or 8 frames into one 250 ms update, which read as 28 and 32.
            game_window[window_next] = { game_frames, idle_ns, now };
            window_next = (window_next + 1) % game_window.size();
            window_filled = std::min(window_filled + 1, game_window.size());
            const GameSample& oldest = game_window[window_filled < game_window.size() ? 0 : window_next];
            uint64_t game_delta = game_frames - oldest.frames;
            double game_seconds = std::chrono::duration<double>(now - oldest.time).count();
            double game_busy_ms = std::max(0.0, game_seconds * 1000.0 - (idle_ns - oldest.idle_ns) / 1e6);

            // TOOIE_FRAME_LOG=1: prints the same figures every 2 s, shown or not.
            static const bool log = std::getenv("TOOIE_FRAME_LOG") != nullptr;
            static int ticks = 0;
            if (log && ++ticks % 8 == 0) {
                std::string joined;
                for (const std::string& line : format(frames, game_delta, game_seconds, game_busy_ms, Mode::Full)) {
                    joined += (joined.empty() ? "" : " | ") + line;
                }
                std::printf("[frames] %s\n", joined.c_str());
                std::fflush(stdout);
            }

            Mode mode = current_mode();
            if (mode == Mode::Off) {
                if (overlay.shown) {
                    hide(overlay);
                }
                continue;
            }
            if (overlay.context == recompui::ContextId::null() && !build(overlay)) {
                std::this_thread::sleep_for(ui_wait);
                continue;
            }

            std::vector<std::string> text = format(frames, game_delta, game_seconds, game_busy_ms, mode);
            overlay.context.open();
            for (size_t i = 0; i < overlay.lines.size(); i++) {
                bool used = i < text.size();
                overlay.lines[i]->set_text(used ? text[i] : std::string());
                overlay.lines[i]->set_display(used ? recompui::Display::Block : recompui::Display::None);
            }
            overlay.graph->set_display(mode == Mode::Full ? recompui::Display::Flex : recompui::Display::None);
            if (mode == Mode::Full) {
                update_graph(overlay);
            }
            overlay.context.close();
            show(overlay);
        }
    }
}

void tooie::frame_overlay::register_input() {
    recompinput::set_game_input_name(overlay_input, "Frame Rate Overlay");
    recompinput::set_game_input_description(overlay_input,
        "Steps the frame rate overlay through Off, Compact and Full for this session. The Graphics tab sets how it starts.");
    recompinput::set_default_mapping_for_keyboard(overlay_input, { recompinput::InputField::keyboard(SDL_SCANCODE_F3) });
    recompinput::set_default_mapping_for_controller(overlay_input, {});
}

void tooie::frame_overlay::add_option(recomp::config::Config& graphics) {
    created = true;
    graphics.add_enum_option(
        option,
        "Frame rate overlay",
        "<recomp-color primary>Compact</recomp-color> shows the frame rate and frame time. <recomp-color primary>Full</recomp-color> adds stutter, shader compiles, GPU time, the game's own frame rate and CPU time, frame interpolation, the map and Banjo's position, the renderer, speed-up, cheats and mods, audio, the build and a frame time graph. F3 steps through them while you play.",
        {
            {Mode::Off, "Off", "Off"},
            {Mode::Compact, "Compact", "Compact"},
            {Mode::Full, "Full", "Full"},
        },
        Mode::Off);
    graphics.add_option_change_callback(option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            // A change in the menu wins over the hotkey.
            hotkey_mode.store(-1, std::memory_order_relaxed);
            if (context == recomp::config::OptionChangeContext::Temporary) {
                // The overlay thread reads the saved value.
                graphics_config().save_config();
            }
        });
}

void tooie::frame_overlay::note_input_read() {
    last_read_ns.store(steady_ns(), std::memory_order_relaxed);
}

void tooie::frame_overlay::note_scene_done() {
    // The game reads the controller before it builds a frame, so the newest read when the
    // scene is done is the one this frame used. Taken, so a read is counted once.
    int64_t read = last_read_ns.exchange(0, std::memory_order_relaxed);
    if (read != 0) {
        scene_read_ns.store(read, std::memory_order_relaxed);
    }
}

void tooie::frame_overlay::note_screen_update() {
    int64_t read = scene_read_ns.exchange(0, std::memory_order_relaxed);
    if (read != 0) {
        RT64::NoteInputRead(read);
    }
}

void tooie::frame_overlay::note_audio_chunk(uint64_t queued_us, bool sped_up) {
    std::lock_guard lock{ audio_mutex };
    audio_now.chunks++;
    if (sped_up) {
        audio_now.sped_up++;
    }
    // The queue running dry after sound has started is a dropout (a gap you can hear).
    if (audio_started && queued_us == 0) {
        audio_now.dropouts++;
    }
    audio_started = true;
    audio_now.min_us = std::min(audio_now.min_us, queued_us);
    audio_now.max_us = std::max(audio_now.max_us, queued_us);
}

void tooie::frame_overlay::start(uint8_t* rdram) {
    game_rdram = rdram;
    std::call_once(start_once, [] {
        // Detached on purpose: the thread owns no resources that need a clean shutdown.
        std::thread(worker).detach();
        std::thread(key_worker).detach();
    });
}
