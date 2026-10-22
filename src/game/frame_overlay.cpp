// Frame rate overlay: one Graphics option that shows, in the top left corner,
// the frame rate and frame time actually presented, the worst frame, the GPU
// time and that of each of the port's extra passes (bloom, SMAA, ...), the game's own frame rate and CPU time, the Interpolation setting and what
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
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iterator>
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
#include "tooie_hotkeys.h"
#include "tooie_model_tagging.h"
#include "tooie_picture_filters.h"
#include "tooie_toast.h"
#include "build_info.h"
#include "tooie_watchdog.h"
#include "tooie_rdram.h"

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
        double sectionMs[14] = {};
        uint32_t sectionCount[14] = {};
        uint32_t cpuFrames = 0;
        double cpuMs[5] = {};
        double snowMs[4] = {};
        double effectsMs[6] = {};
    };
    FrameStats TakeFrameStats();
    void SetGpuSectionTiming(bool wanted);
    void NoteInputRead(int64_t steadyNs);
}

namespace {
    using namespace std::chrono_literals;
    using clock_type = std::chrono::steady_clock;

    constexpr auto update_interval = 250ms;
    // Wait for the UI to come up before building the overlay.
    constexpr auto ui_wait = 500ms;
    constexpr size_t max_lines = 20;
    // Space between the groups of lines in Full.
    constexpr float group_gap = 8.0f;
    // The frame time graph: one bar per presented frame, newest on the right.
    constexpr size_t graph_bars = 100;
    constexpr float graph_height = 40.0f;
    constexpr auto key_poll = 16ms;
    constexpr auto overlay_input = recompinput::GameInput::FRAME_OVERLAY;
    constexpr auto benchmark_input = recompinput::GameInput::BENCHMARK;
    constexpr auto cost_input = recompinput::GameInput::EFFECT_COST;
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

    // Whether any key or button bound to this input (Controls tab, Hotkeys) is held.
    bool key_down(recompinput::GameInput input) {
        return tooie::hotkeys::down(input);
    }

    void toggle_benchmark();
    // The Effect Cost Check key, taken by the overlay's thread (cost_tick).
    std::atomic<bool> cost_toggle{false};

    // F4 was the Benchmark key's default until L asked for it gone (2026-10-17). Saved controls
    // that still have F4 on it lose it once. Returns false until the keyboard profile is loaded.
    bool take_f4_off_benchmark() {
        const std::filesystem::path marker = recomp::get_config_path() / "benchmark_no_f4.done";
        std::error_code ec;
        if (std::filesystem::exists(marker, ec)) {
            return true;
        }
        const int profile = recompinput::profiles::get_sp_keyboard_profile_index();
        if (profile < 0) {
            return false;
        }
        const recompinput::InputField f4 = recompinput::InputField::keyboard(SDL_SCANCODE_F4);
        bool changed = false;
        for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
            if (recompinput::profiles::get_input_binding(profile, benchmark_input, b) == f4) {
                recompinput::profiles::set_input_binding(profile, benchmark_input, b, recompinput::InputField{});
                changed = true;
            }
        }
        if (changed) {
            recompinput::profiles::save_controls_config(recomp::get_config_path() / "controls.json");
            std::printf("[benchmark] F4 taken off the Benchmark key\n");
            std::fflush(stdout);
        }
        std::ofstream(marker) << "F4 was taken off the Benchmark key once (frame_overlay.cpp).\n";
        return true;
    }

    void key_worker() {
        bool was_down = false;
        bool benchmark_was_down = false;
        bool cost_was_down = false;
        bool f4_checked = false;
        for (;;) {
            std::this_thread::sleep_for(key_poll);
            if (!f4_checked) {
                f4_checked = take_f4_off_benchmark();
            }
            bool benchmark_down = key_down(benchmark_input);
            if (benchmark_down && !benchmark_was_down) {
                toggle_benchmark();
            }
            benchmark_was_down = benchmark_down;
            bool cost_down = key_down(cost_input);
            if (cost_down && !cost_was_down) {
                cost_toggle.store(true, std::memory_order_relaxed);
            }
            cost_was_down = cost_down;
            bool down = key_down(overlay_input);
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
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        if (!recompui::is_context_shown(o.context)) {
            recompui::show_context(o.context, "");
        }
        o.shown = true;
    }

    void hide(Overlay& o) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
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

    using tooie::rdram::read_float;
    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;

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

    // The port's extra GPU passes, in RT64::GpuSection order. The first four and the last four are
    // recorded with the game's frame (per_game_frame), the rest at each present.
    constexpr size_t section_count = 14;
    constexpr const char* section_names[section_count] = {
        "water mask", "eye adaptation", "bloom", "effects", "SMAA", "FXAA", "photo filters", "FSR", "output", "UI",
        "sun shadow map", "ray tracing build", "AO and bounce light", "traced effects"
    };
    constexpr bool per_game_frame[section_count] = {
        true, true, true, true, false, false, false, false, false, false, true, true, true, true
    };
    // The order the overlay lists them in, a line each: the game frame's passes as the GPU runs them,
    // the ray tracing ones, then the present's.
    constexpr size_t frame_order[] = { 10, 0, 2, 1, 12, 3 };
    constexpr size_t traced_order[] = { 11, 13 };
    constexpr size_t present_order[] = { 4, 5, 6, 7, 8, 9 };

    // "GPU 3D effects: bloom 0.31, effects 1.20 ms" with the passes that ran, per game frame or present;
    // empty when none ran.
    template <size_t N>
    std::string section_line(const RT64::FrameStats& frames, const char* label, const size_t (&order)[N], uint32_t per) {
        std::string text;
        char part[48];
        for (size_t i : order) {
            if (frames.sectionCount[i] == 0 || per == 0) {
                continue;
            }
            std::snprintf(part, sizeof(part), "%s%s %.2f", text.empty() ? "" : ", ", section_names[i], frames.sectionMs[i] / per);
            text += part;
        }
        return text.empty() ? std::string() : std::string(label) + text + " ms";
    }

    // The Effect Cost Check's lines for the overlay (its progress, then its results for a while); empty
    // otherwise. Only the overlay's thread touches them.
    std::vector<std::string> cost_lines;

    // The last frame rate line, kept for an update in which no frame was shown (below 4 fps).
    std::string last_rate_line;
    std::string last_worst_line;

    // Full mode's lines in groups: frames, GPU, the game, where Banjo is, and the PC and build.
    // A line holding a single space separates the groups (drawn as a gap, not a line).
    std::vector<std::string> format(const RT64::FrameStats& frames, uint64_t game_frames, double seconds, double game_busy_ms, Mode mode) {
        char line[200];
        std::vector<std::string> text;
        const std::string gap = " ";

        // Frames shown.
        if (frames.presents > 0) {
            double ms = frames.presentMs / frames.presents;
            std::snprintf(line, sizeof(line), "%.0f fps, %.2f ms frame time", 1000.0 / ms, ms);
            last_rate_line = line;
            std::snprintf(line, sizeof(line), "Worst frame %.2f ms", frames.worstPresentMs);
            last_worst_line = line;
        }
        std::string rate = last_rate_line.empty() ? std::string("No frames shown yet") : last_rate_line;
        if (latency_frames > 0) {
            std::snprintf(line, sizeof(line), ", input %.0f ms", latency_ms / latency_frames);
            rate += line;
        }
        text.push_back(rate);
        // The Effect Cost Check's progress or results take the place of everything else while shown.
        if (!cost_lines.empty()) {
            text.push_back(" ");
            text.insert(text.end(), cost_lines.begin(), cost_lines.end());
            return text;
        }
        if (mode == Mode::Compact) {
            return text;
        }
        if (!last_worst_line.empty()) {
            text.push_back(last_worst_line);
        }
        text.push_back(stutter_line());
        if (latency_frames > 0) {
            std::snprintf(line, sizeof(line), "Input latency %.0f ms, worst %.0f ms (controller read to screen)",
                latency_ms / latency_frames, latency_worst);
            text.push_back(line);
        }

        // GPU.
        text.push_back(gap);
        if (frames.gpuFrames > 0) {
            std::snprintf(line, sizeof(line), "GPU %.2f ms per game frame", frames.gpuMs / frames.gpuFrames);
            text.push_back(line);
            std::string effects = section_line(frames, "GPU 3D effects: ", frame_order, frames.gpuFrames);
            if (!effects.empty()) {
                text.push_back(effects);
            }
            std::string traced = section_line(frames, "GPU ray tracing: ", traced_order, frames.gpuFrames);
            if (!traced.empty()) {
                text.push_back(traced);
            }
        }
        // The renderer thread's own time on each game frame: where a frame goes when the GPU isn't the slow part.
        if (frames.cpuFrames > 0) {
            const double n = frames.cpuFrames;
            std::snprintf(line, sizeof(line), "Renderer CPU %.2f ms per game frame: draws %.2f, effects setup %.2f, record %.2f, GPU wait %.2f, after %.2f",
                (frames.cpuMs[0] + frames.cpuMs[1] + frames.cpuMs[2] + frames.cpuMs[3] + frames.cpuMs[4]) / n,
                frames.cpuMs[0] / n, frames.cpuMs[1] / n, frames.cpuMs[2] / n, frames.cpuMs[3] / n, frames.cpuMs[4] / n);
            text.push_back(line);
            const double snow = frames.snowMs[0] + frames.snowMs[1] + frames.snowMs[2] + frames.snowMs[3];
            if (snow > 0.0) {
                std::snprintf(line, sizeof(line), "Snow and sand CPU %.2f ms: trail %.2f, ground %.2f, models pressing %.2f, edges %.2f",
                    snow / n, frames.snowMs[0] / n, frames.snowMs[1] / n, frames.snowMs[2] / n, frames.snowMs[3] / n);
                text.push_back(line);
            }
            const double *e = frames.effectsMs;
            if (e[0] + e[1] + e[2] + e[3] + e[4] + e[5] > 0.0) {
                std::snprintf(line, sizeof(line), "Effects setup: fur %.2f, grass mask, snow and sand %.2f, grass %.2f, ray traced scene %.2f, uploads %.2f, shader views %.2f",
                    e[0] / n, e[1] / n, e[2] / n, e[3] / n, e[4] / n, e[5] / n);
                text.push_back(line);
            }
        }
        if (frames.presents > 0) {
            std::string passes = section_line(frames, "GPU screen passes: ", present_order, frames.presents);
            if (!passes.empty()) {
                text.push_back(passes);
            }
        }
        text.push_back(shader_line());

        // The game.
        text.push_back(gap);
        std::snprintf(line, sizeof(line), "Game %.0f fps", seconds > 0.0 ? game_frames / seconds : 0.0);
        text.push_back(line);
        if (game_frames > 0 && seconds > 0.0) {
            // The game's code ran whenever none of its threads was waiting.
            std::snprintf(line, sizeof(line), ", CPU %.2f ms per frame (busy %.0f%%)",
                game_busy_ms / game_frames, std::clamp(game_busy_ms / (seconds * 10.0), 0.0, 100.0));
            text.back() += line;
        }
        // One line: the setting, then whether it is blending and what it tagged.
        tooie::model_tagging::Stats tags = tooie::model_tagging::last_stats();
        if (tags.interpolating) {
            auto plural = [](uint32_t n) { return n == 1 ? "" : "s"; };
            std::snprintf(line, sizeof(line), ", on: %u model%s, %u bone%s, %u shadow%s, %u camera cut%s",
                tags.models, plural(tags.models), tags.bones, plural(tags.bones), tags.shadows, plural(tags.shadows),
                tags.camera_cuts, plural(tags.camera_cuts));
            text.push_back("Interpolation: " + framerate_setting() + line);
        }
        else {
            // With the setting itself Off, "Off, off" says it twice.
            const std::string setting = framerate_setting();
            text.push_back("Interpolation: " + (setting == "Off" ? setting : setting + ", off"));
        }
        if (game_rdram != nullptr) {
            text.push_back(map_line(game_rdram));
            text.push_back(position_line(game_rdram));
        }

        // The PC and the build.
        text.push_back(gap);
        text.push_back(renderer_line());
        text.push_back(extras_line());
        if (!audio_text.empty()) {
            text.push_back(audio_text);
        }
        text.push_back(std::string("Build ") + TOOIE_GIT_COMMIT + " (" + TOOIE_GIT_DATE + ")");
        return text;
    }

    // Benchmark (the Benchmark key, unbound by default since L 2026-10-17): records what the overlay measures to
    // benchmarks/benchmark_<date>.csv, one row per update (four a second), and on
    // stopping writes a summary with the settings next to it (.txt), so two settings
    // or two builds can be compared on the same PC. TOOIE_BENCHMARK=<seconds> records
    // that long from the first game frame, for headless runs.
    struct Benchmark {
        std::FILE* csv = nullptr;
        std::filesystem::path path;
        clock_type::time_point started;
        std::string map_at_start;
        std::vector<float> intervals;
        uint32_t presents = 0;
        double present_ms = 0.0;
        double worst_ms = 0.0;
        uint32_t gpu_frames = 0;
        double gpu_ms = 0.0;
        double section_ms[section_count] = {};
        uint32_t latency_frames = 0;
        double latency_ms = 0.0;
        uint64_t shader_compiles = 0;
        uint64_t game_frames = 0;
        double busy_ms = 0.0;
        uint64_t last_frames = 0;
        uint64_t last_idle_ns = 0;
        clock_type::time_point last_tick;
    };
    std::mutex benchmark_mutex;
    Benchmark benchmark;
    // Set by the key thread, acted on by the update thread.
    std::atomic<bool> benchmark_toggle{false};

    void toggle_benchmark() {
        benchmark_toggle.store(true, std::memory_order_relaxed);
    }

    std::string date_stamp() {
        std::time_t t = std::time(nullptr);
        std::tm tm{};
#ifdef _WIN32
        localtime_s(&tm, &t);
#else
        localtime_r(&t, &tm);
#endif
        char text[32];
        std::strftime(text, sizeof(text), "%Y-%m-%d_%H-%M-%S", &tm);
        return text;
    }

    void start_benchmark(uint64_t game_frames, uint64_t idle_ns) {
        std::filesystem::path dir = recomp::get_config_path() / "benchmarks";
        std::error_code ec;
        std::filesystem::create_directories(dir, ec);
        Benchmark b;
        b.path = dir / ("benchmark_" + date_stamp());
        std::filesystem::path csv_path = b.path;
        csv_path += ".csv";
#ifdef _WIN32
        b.csv = _wfopen(csv_path.c_str(), L"w");
#else
        b.csv = std::fopen(csv_path.c_str(), "w");
#endif
        if (b.csv == nullptr) {
            tooie::toast::show("Benchmark not started: can't write to the benchmarks folder");
            return;
        }
        std::fprintf(b.csv, "seconds,fps,frame_ms,worst_frame_ms,gpu_ms_per_game_frame");
        for (const char* name : section_names) {
            std::string column = name;
            std::replace(column.begin(), column.end(), ' ', '_');
            std::fprintf(b.csv, ",gpu_%s_ms", column.c_str());
        }
        std::fprintf(b.csv, ",game_fps,game_cpu_ms,input_latency_ms,shader_compiles,map,x,y,z\n");
        b.started = clock_type::now();
        b.last_tick = b.started;
        b.map_at_start = game_rdram != nullptr ? map_line(game_rdram) : std::string("Map unknown");
        b.last_frames = game_frames;
        b.last_idle_ns = idle_ns;
        {
            std::lock_guard lock{ benchmark_mutex };
            benchmark = std::move(b);
        }
        tooie::toast::show("Benchmark recording (press again to stop)");
    }

    std::string summary_text(const Benchmark& b, double seconds) {
        std::vector<float> sorted = b.intervals;
        std::sort(sorted.begin(), sorted.end());
        char line[256];
        std::string text = "Banjo-Tooie N64 Recomp benchmark\n\n";
        text += std::string("Build ") + TOOIE_GIT_COMMIT + " (" + TOOIE_GIT_DATE + ")\n";
        std::snprintf(line, sizeof(line), "Length %.1f s, started in %s, ended in %s\n\n", seconds,
            b.map_at_start.c_str(), game_rdram != nullptr ? map_line(game_rdram).c_str() : "Map unknown");
        text += line;
        if (b.presents > 0) {
            double ms = b.present_ms / b.presents;
            std::snprintf(line, sizeof(line), "Frames shown %u: %.1f fps average, %.2f ms\n", b.presents, 1000.0 / ms, ms);
            text += line;
        }
        if (!sorted.empty()) {
            float median = sorted[sorted.size() / 2];
            float low1 = sorted[std::min(sorted.size() - 1, sorted.size() * 99 / 100)];
            float low01 = sorted[std::min(sorted.size() - 1, sorted.size() * 999 / 1000)];
            size_t hitches = (size_t)(sorted.end() - std::upper_bound(sorted.begin(), sorted.end(), median * hitch_factor));
            std::snprintf(line, sizeof(line), "Median frame %.2f ms; 1%% low %.1f fps (%.2f ms); 0.1%% low %.1f fps (%.2f ms); worst %.2f ms; %zu hitches\n",
                median, 1000.0f / low1, low1, 1000.0f / low01, low01, sorted.back(), hitches);
            text += line;
        }
        if (b.gpu_frames > 0) {
            std::snprintf(line, sizeof(line), "GPU %.2f ms per game frame\n", b.gpu_ms / b.gpu_frames);
            text += line;
            for (size_t i = 0; i < section_count; i++) {
                uint32_t per = per_game_frame[i] ? b.gpu_frames : b.presents;
                if (b.section_ms[i] > 0.0 && per > 0) {
                    std::snprintf(line, sizeof(line), "  %s %.3f ms\n", section_names[i], b.section_ms[i] / per);
                    text += line;
                }
            }
        }
        if (b.game_frames > 0) {
            std::snprintf(line, sizeof(line), "Game %.1f fps, CPU %.2f ms per frame\n", b.game_frames / seconds, b.busy_ms / b.game_frames);
            text += line;
        }
        if (b.latency_frames > 0) {
            std::snprintf(line, sizeof(line), "Input latency %.1f ms average\n", b.latency_ms / b.latency_frames);
            text += line;
        }
        std::snprintf(line, sizeof(line), "Shader compiles %llu\n\n", (unsigned long long)b.shader_compiles);
        text += line;
        text += "Framerate: " + framerate_setting() + "\n";
        text += renderer_line() + "\n";
        text += extras_line() + "\n\n";
        // The whole Graphics tab, as saved.
        std::ifstream graphics(recomp::get_config_path() / "graphics.json");
        if (graphics) {
            text += "graphics.json:\n";
            text += std::string(std::istreambuf_iterator<char>(graphics), std::istreambuf_iterator<char>());
            text += "\n";
        }
        return text;
    }

    void stop_benchmark() {
        Benchmark b;
        {
            std::lock_guard lock{ benchmark_mutex };
            b = std::move(benchmark);
            benchmark = Benchmark();
        }
        if (b.csv == nullptr) {
            return;
        }
        std::fclose(b.csv);
        double seconds = std::chrono::duration<double>(clock_type::now() - b.started).count();
        std::filesystem::path txt_path = b.path;
        txt_path += ".txt";
        std::ofstream txt(txt_path);
        txt << summary_text(b, seconds);
        std::string name = b.path.filename().string();
        std::printf("[benchmark] saved %s.csv and .txt (%.1f s)\n", b.path.string().c_str(), seconds);
        std::fflush(stdout);
        tooie::toast::show("Benchmark saved: benchmarks\\" + name + ".txt");
    }

    void benchmark_tick(const RT64::FrameStats& frames, uint64_t game_frames, uint64_t idle_ns, clock_type::time_point now) {
        std::lock_guard lock{ benchmark_mutex };
        Benchmark& b = benchmark;
        if (b.csv == nullptr) {
            return;
        }
        double tick_s = std::max(std::chrono::duration<double>(now - b.last_tick).count(), 0.001);
        b.last_tick = now;
        uint64_t frames_delta = game_frames - b.last_frames;
        double idle_ms = (idle_ns - b.last_idle_ns) / 1e6;
        double busy = std::max(0.0, tick_s * 1000.0 - idle_ms);
        b.last_frames = game_frames;
        b.last_idle_ns = idle_ns;

        b.intervals.insert(b.intervals.end(), frames.intervals.begin(), frames.intervals.end());
        b.presents += frames.presents;
        b.present_ms += frames.presentMs;
        b.worst_ms = std::max(b.worst_ms, frames.worstPresentMs);
        b.gpu_frames += frames.gpuFrames;
        b.gpu_ms += frames.gpuMs;
        for (size_t i = 0; i < section_count; i++) {
            b.section_ms[i] += frames.sectionMs[i];
        }
        b.latency_frames += frames.latencyFrames;
        b.latency_ms += frames.latencyMs;
        b.shader_compiles += frames.shaderCompiles;
        b.game_frames += frames_delta;
        b.busy_ms += busy;

        double seconds = std::max(std::chrono::duration<double>(now - b.started).count(), 0.0);
        double frame_ms = frames.presents > 0 ? frames.presentMs / frames.presents : 0.0;
        std::fprintf(b.csv, "%.2f,%.1f,%.3f,%.3f,%.3f", seconds, frame_ms > 0.0 ? 1000.0 / frame_ms : 0.0, frame_ms,
            frames.worstPresentMs, frames.gpuFrames > 0 ? frames.gpuMs / frames.gpuFrames : 0.0);
        for (size_t i = 0; i < section_count; i++) {
            uint32_t per = per_game_frame[i] ? frames.gpuFrames : frames.presents;
            std::fprintf(b.csv, ",%.3f", per > 0 ? frames.sectionMs[i] / per : 0.0);
        }
        float x = 0, y = 0, z = 0;
        uint16_t map = 0;
        if (game_rdram != nullptr) {
            map = tooie::debug::current_map(game_rdram);
            uint32_t player = read_word(game_rdram, player_table);
            uint32_t transform = valid_ptr(player) ? read_word(game_rdram, player + player_transform) : 0;
            if (valid_ptr(transform)) {
                x = read_float(game_rdram, transform);
                y = read_float(game_rdram, transform + 4);
                z = read_float(game_rdram, transform + 8);
            }
        }
        std::fprintf(b.csv, ",%.1f,%.2f,%.1f,%u,%X,%.0f,%.0f,%.0f\n", frames_delta / tick_s,
            frames_delta > 0 ? busy / frames_delta : 0.0,
            frames.latencyFrames > 0 ? frames.latencyMs / frames.latencyFrames : 0.0, frames.shaderCompiles, map, x, y, z);
        std::fflush(b.csv);
    }

    bool benchmark_running() {
        std::lock_guard lock{ benchmark_mutex };
        return benchmark.csv != nullptr;
    }

    // Effect Cost Check (the Effect Cost Check key, or TOOIE_COST_CHECK=<seconds> once the game runs): measures
    // the GPU time per game frame with every effect as set, then with each effect that is on turned off in
    // turn (picture_filters::set_cost_override, the saved settings untouched), then as set again; each
    // effect's cost is how much the time drops without it, against the two measurements as set. The list,
    // heaviest first, shows in the overlay (shown for the check even when it is off) and goes to
    // benchmarks/effect_cost_<date>.txt.
    struct CostMeasure {
        double gpu_ms = 0.0;
        uint32_t gpu_frames = 0;
        double present_ms = 0.0;
        uint32_t presents = 0;
        double gpu() const { return gpu_frames > 0 ? gpu_ms / gpu_frames : -1.0; }
        double frame() const { return presents > 0 ? present_ms / presents : -1.0; }
    };
    struct CostCheck {
        bool running = false;
        std::vector<tooie::picture_filters::CostEffect> effects;
        // 0: as set; 1 to n: effects[step - 1] off; n + 1: as set again.
        size_t step = 0;
        int ticks = 0;
        CostMeasure now;
        std::vector<CostMeasure> measured;
        std::string map;
    };
    CostCheck cost;
    clock_type::time_point cost_lines_until{};
    // Each step lets the change settle (new shaders, the effect's history) before it measures, for at
    // least 2 s and 20 game frames drawn (a slow PC takes longer), up to 30 s.
    constexpr int cost_settle_ticks = 4;
    constexpr int cost_measure_ticks = 8;
    constexpr uint32_t cost_measure_frames = 20;
    constexpr int cost_measure_most_ticks = 120;
    constexpr auto cost_results_shown = 45s;
    constexpr size_t cost_lines_listed = 12;

    std::string cost_step_name(const CostCheck& c) {
        if (c.step == 0 || c.step > c.effects.size()) {
            return "everything as set";
        }
        return c.effects[c.step - 1].name + " off";
    }

    void cost_progress(const CostCheck& c, clock_type::time_point now) {
        const size_t steps = c.effects.size() + 2;
        const int left = int(steps - c.step) * (cost_settle_ticks + cost_measure_ticks) - std::min(c.ticks, cost_settle_ticks + cost_measure_ticks);
        char line[160];
        std::snprintf(line, sizeof(line), "Effect cost check: %s (%zu of %zu), about %d s left", cost_step_name(c).c_str(), c.step + 1, steps,
            std::max(1, left / 4));
        cost_lines = { line, "Keep the camera still; press the key again to stop" };
        cost_lines_until = now + cost_results_shown;
    }

    void cost_finish(CostCheck& c, clock_type::time_point now) {
        tooie::picture_filters::set_cost_override(nullptr);
        c.running = false;
        const CostMeasure& first = c.measured.front();
        const CostMeasure& last = c.measured.back();
        auto average = [](double a, double b) { return (a >= 0.0 && b >= 0.0) ? (a + b) / 2.0 : std::max(a, b); };
        const double base_gpu = average(first.gpu(), last.gpu());
        const double base_frame = average(first.frame(), last.frame());
        struct Row {
            std::string name;
            double gpu;
            double frame;
        };
        std::vector<Row> rows;
        for (size_t i = 0; i < c.effects.size(); i++) {
            const CostMeasure& m = c.measured[i + 1];
            rows.push_back({ c.effects[i].name, (m.gpu() >= 0.0 && base_gpu >= 0.0) ? base_gpu - m.gpu() : NAN,
                (m.frame() >= 0.0 && base_frame >= 0.0) ? base_frame - m.frame() : NAN });
        }
        std::stable_sort(rows.begin(), rows.end(), [](const Row& a, const Row& b) {
            return (std::isnan(b.gpu) ? -1e9 : b.gpu) < (std::isnan(a.gpu) ? -1e9 : a.gpu);
        });

        char line[512];
        cost_lines.clear();
        std::string text = "Banjo-Tooie N64 Recomp effect cost check\n\n";
        text += std::string("Build ") + TOOIE_GIT_COMMIT + " (" + TOOIE_GIT_DATE + ")\n" + c.map + "\n";
        if (base_gpu < 0.0) {
            cost_lines.push_back("Effect cost check: no frames drawn, nothing measured");
        }
        else {
            std::snprintf(line, sizeof(line), "Effect cost (GPU per game frame, %.2f ms as set), heaviest first:", base_gpu);
            cost_lines.push_back(line);
            std::snprintf(line, sizeof(line), "GPU %.2f ms per game frame and %.2f ms frame time with everything as set (GPU %.2f ms at the start, %.2f at the end).\n"
                "Each effect's cost is how much those drop with it off. A cost near 0 or below is within the noise.\n\n",
                base_gpu, std::max(base_frame, 0.0), std::max(first.gpu(), 0.0), std::max(last.gpu(), 0.0));
            text += line;
            for (const Row& r : rows) {
                if (std::isnan(r.gpu)) {
                    std::snprintf(line, sizeof(line), "%s: not measured (no frames drawn)", r.name.c_str());
                }
                else {
                    std::snprintf(line, sizeof(line), "%s: %.2f ms (%.0f%%)", r.name.c_str(), r.gpu, base_gpu > 0.0 ? 100.0 * r.gpu / base_gpu : 0.0);
                }
                if (cost_lines.size() <= cost_lines_listed) {
                    cost_lines.push_back(line);
                }
                text += line;
                if (!std::isnan(r.frame)) {
                    std::snprintf(line, sizeof(line), ", frame time %.2f ms", r.frame);
                    text += line;
                }
                text += "\n";
            }
        }
        std::filesystem::path dir = recomp::get_config_path() / "benchmarks";
        std::error_code ec;
        std::filesystem::create_directories(dir, ec);
        const std::string name = "effect_cost_" + date_stamp() + ".txt";
        std::ofstream file(dir / name);
        file << text;
        const bool saved = file.good();
        file.close();
        cost_lines.push_back(saved ? "Saved to benchmarks\\" + name : std::string("Not saved: can't write to the benchmarks folder"));
        cost_lines_until = now + cost_results_shown;
        std::printf("[cost] %s", text.c_str());
        std::fflush(stdout);
        tooie::toast::show(saved ? "Effect cost check saved: benchmarks\\" + name : std::string("Effect cost check done (not saved)"));
    }

    void cost_tick(const RT64::FrameStats& frames, uint64_t game_frames, clock_type::time_point now) {
        static const char* auto_check = std::getenv("TOOIE_COST_CHECK");
        static clock_type::time_point auto_start{};
        if (auto_check != nullptr && auto_start == clock_type::time_point{} && game_frames > 0) {
            auto_start = now + std::chrono::milliseconds((int64_t)(std::atof(auto_check) * 1000.0));
        }
        if (auto_check != nullptr && auto_start != clock_type::time_point{} && now >= auto_start) {
            auto_start = clock_type::time_point::max();
            cost_toggle.store(true, std::memory_order_relaxed);
        }
        if (cost_toggle.exchange(false, std::memory_order_relaxed)) {
            if (cost.running) {
                tooie::picture_filters::set_cost_override(nullptr);
                cost.running = false;
                cost_lines.clear();
                tooie::toast::show("Effect cost check stopped");
            }
            else {
                cost = CostCheck();
                cost.effects = tooie::picture_filters::cost_effects();
                if (cost.effects.empty()) {
                    tooie::toast::show("Effect cost check: no effects are on");
                }
                else {
                    cost.running = true;
                    cost.map = game_rdram != nullptr ? map_line(game_rdram) : std::string("Map unknown");
                    cost_progress(cost, now);
                }
            }
            return;
        }
        if (!cost.running) {
            if (!cost_lines.empty() && now >= cost_lines_until) {
                cost_lines.clear();
            }
            return;
        }
        cost.ticks++;
        if (cost.ticks > cost_settle_ticks) {
            cost.now.gpu_ms += frames.gpuMs;
            cost.now.gpu_frames += frames.gpuFrames;
            cost.now.present_ms += frames.presentMs;
            cost.now.presents += frames.presents;
        }
        const bool enough = (cost.ticks >= cost_settle_ticks + cost_measure_ticks) && (cost.now.gpu_frames >= cost_measure_frames);
        if (enough || (cost.ticks >= cost_settle_ticks + cost_measure_most_ticks)) {
            cost.measured.push_back(cost.now);
            cost.now = CostMeasure();
            cost.ticks = 0;
            cost.step++;
            if (cost.step > cost.effects.size() + 1) {
                cost_finish(cost, now);
                return;
            }
            tooie::picture_filters::set_cost_override(cost.step <= cost.effects.size() ? &cost.effects[cost.step - 1] : nullptr);
        }
        cost_progress(cost, now);
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

            // The Benchmark key, or TOOIE_BENCHMARK=<seconds> once the game is running.
            static const char* auto_benchmark = std::getenv("TOOIE_BENCHMARK");
            static clock_type::time_point auto_stop{};
            if (auto_benchmark != nullptr && auto_stop == clock_type::time_point{} && game_frames > 0) {
                auto_stop = now + std::chrono::milliseconds((int64_t)(std::atof(auto_benchmark) * 1000.0));
                start_benchmark(game_frames, idle_ns);
            }
            else if (auto_benchmark != nullptr && auto_stop != clock_type::time_point{} && now >= auto_stop && benchmark_running()) {
                stop_benchmark();
            }
            if (benchmark_toggle.exchange(false, std::memory_order_relaxed)) {
                if (benchmark_running()) {
                    stop_benchmark();
                }
                else {
                    start_benchmark(game_frames, idle_ns);
                }
            }
            benchmark_tick(frames, game_frames, idle_ns, now);
            cost_tick(frames, game_frames, now);
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
                    if (line != " ") {
                        joined += (joined.empty() ? "" : " | ") + line;
                    }
                }
                std::printf("[frames] %s\n", joined.c_str());
                std::fflush(stdout);
            }

            Mode mode = current_mode();
            // The cost check shows its progress and results with the overlay off too.
            if (mode == Mode::Off && !cost_lines.empty()) {
                mode = Mode::Compact;
            }
            // The per-pass GPU times are only shown in Full and written by the benchmark and the log;
            // otherwise RT64 skips its timestamps (64 a frame, each a separate copy on D3D12).
            RT64::SetGpuSectionTiming(log || mode == Mode::Full || benchmark_running());
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
            {
                auto lifetime = recompui::lock_context_lifetime();
                if (!recompui::contexts_alive()) {
                    return;
                }
                overlay.context.open();
                // A " " line is a gap: the next line gets a margin above it instead.
                size_t used = 0;
                bool gap = false;
                for (const std::string& t : text) {
                    if (t == " ") {
                        gap = true;
                        continue;
                    }
                    if (used == overlay.lines.size()) {
                        break;
                    }
                    overlay.lines[used]->set_text(t);
                    overlay.lines[used]->set_margin_top(gap ? group_gap : 0.0f);
                    overlay.lines[used]->set_display(recompui::Display::Block);
                    gap = false;
                    used++;
                }
                for (size_t i = used; i < overlay.lines.size(); i++) {
                    overlay.lines[i]->set_text(std::string());
                    overlay.lines[i]->set_display(recompui::Display::None);
                }
                overlay.graph->set_display(mode == Mode::Full ? recompui::Display::Flex : recompui::Display::None);
                if (mode == Mode::Full) {
                    update_graph(overlay);
                }
                overlay.context.close();
            }
            show(overlay);
        }
    }
}

void tooie::frame_overlay::register_input() {
    recompinput::set_game_input_name(benchmark_input, "Benchmark");
    recompinput::set_game_input_description(benchmark_input,
        "Starts and stops recording the frame rate overlay's figures to the benchmarks folder, with a summary and your settings, for comparing settings or builds.");
    // No default key (L, 2026-10-17: it was F4); bind it in the Controls tab.
    recompinput::set_default_mapping_for_keyboard(benchmark_input, {});
    recompinput::set_default_mapping_for_controller(benchmark_input, {});

    recompinput::set_game_input_name(cost_input, "Effect Cost Check");
    recompinput::set_game_input_description(cost_input,
        "Measures how much GPU time each graphics effect that is on costs, by turning each off for a few seconds in turn (your settings stay as they are), then lists them heaviest first in the overlay and in the benchmarks folder.");
    recompinput::set_default_mapping_for_keyboard(cost_input, {});
    recompinput::set_default_mapping_for_controller(cost_input, {});

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
        "<recomp-color primary>Compact</recomp-color> shows the frame rate and frame time. <recomp-color primary>Full</recomp-color> adds stutter, shader compiles, GPU time with each effect's share, the game's own frame rate and CPU time, frame interpolation, the map and Banjo's position, the renderer, speed-up, cheats and mods, audio, the build and a frame time graph. F3 steps through them while you play.",
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
