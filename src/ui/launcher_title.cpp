// The start menu's BANJO RE-TOOIE title (L, 2026-10-24): its own animation, on its own layer above the
// background (src/ui/launcher_background.cpp) and on its own clock. The lettering is traced from
// u/Plebian_Donkey_Konga's Banjo-Tooie style letter sheet, one SVG per letter in assets/launcher/. Each
// letter falls in from above the window in turn, squashes and rebounds as it lands, then rocks gently,
// each a little out of step with the next.

#include <algorithm>
#include <chrono>
#include <cmath>

#include "recompui/recompui.h"
#include "core/ui_context.h"
#include "elements/ui_element.h"
#include "elements/ui_svg.h"
#include "base/ui_launcher.h"

#include "tooie_launcher_title.h"

namespace {
    using clock = std::chrono::steady_clock;

    constexpr float two_pi = 6.2831853f;
    // The title: its top and height as fractions of the window (it is centred across), and its letters'
    // bounce: when the first starts, the gap between letters, how long each falls and settles.
    constexpr float title_top = 0.02f;
    constexpr float title_height = 0.22f;
    constexpr float title_box_height = 338.0f; // Title units, as in title_letters below.
    constexpr float title_start = 0.4f;
    constexpr float title_letter_gap = 0.12f;
    constexpr float title_fall_time = 0.35f;
    constexpr float title_settle_time = 0.5f;
    constexpr float title_rock = 2.0f; // Degrees.
    constexpr float title_rock_period = 3.0f;
    // The launcher was hidden if no update came for this long; the title bounces in again when it is back.
    constexpr float restart_gap = 1.0f;

    struct TitleLetter {
        const char* path;
        // Box in title units: left from the title's centre line, top from the title's top.
        float x, y, w, h;
        float tilt; // Degrees.
        recompui::Svg* svg = nullptr;
        float left = 0, top = 0, width = 0, height = 0; // In window pixels.
    };

    // BANJO over RE-TOOIE, each row centred; traced from u/Plebian_Donkey_Konga's lettering sheet.
    TitleLetter title_letters[] = {
        { "launcher/title_b.svg", -342.8f, 22.8f, 133.8f, 163.8f, -6.0f },
        { "launcher/title_a.svg", -217.0f, 45.5f, 195.0f, 145.0f, 4.0f },
        { "launcher/title_n.svg", -30.0f, 46.5f, 145.0f, 140.0f, -3.0f },
        { "launcher/title_j.svg", 107.0f, 0.0f, 93.8f, 212.5f, 5.0f },
        { "launcher/title_o.svg", 192.8f, 63.5f, 150.0f, 125.0f, -4.0f },
        { "launcher/title_r_blue.svg", -391.1f, 211.1f, 139.7f, 125.4f, -5.0f },
        { "launcher/title_e_blue.svg", -259.5f, 217.9f, 108.3f, 120.6f, 4.0f },
        { "launcher/title_hyphen.svg", -163.2f, 272.5f, 74.0f, 48.0f, -4.0f },
        { "launcher/title_t_blue.svg", -103.2f, 206.3f, 126.3f, 130.2f, -3.0f },
        { "launcher/title_o_blue.svg", 15.2f, 244.4f, 114.0f, 94.0f, 4.0f },
        { "launcher/title_o_blue.svg", 121.2f, 242.4f, 114.0f, 94.0f, -4.0f },
        { "launcher/title_i_blue.svg", 227.2f, 197.8f, 63.6f, 138.7f, 3.0f },
        { "launcher/title_e_blue.svg", 282.8f, 217.9f, 108.3f, 120.6f, -5.0f },
    };

    recompui::Element* layer = nullptr;
    float laid_out_width = 0, laid_out_height = 0;
    clock::time_point start_time;
    clock::time_point last_update;
    bool started = false;

    float clamp01(float t) {
        return std::clamp(t, 0.0f, 1.0f);
    }

    float smoothstep(float t) {
        t = clamp01(t);
        return t * t * (3.0f - 2.0f * t);
    }

    void lay_out(float window_width, float window_height) {
        float title_scale = title_height * window_height / title_box_height;
        for (TitleLetter& l : title_letters) {
            l.left = window_width * 0.5f + l.x * title_scale;
            l.top = title_top * window_height + l.y * title_scale;
            l.width = l.w * title_scale;
            l.height = l.h * title_scale;
            l.svg->set_left(l.left / window_width * 100.0f, recompui::Unit::Percent);
            l.svg->set_top(l.top / window_height * 100.0f, recompui::Unit::Percent);
            l.svg->set_width(l.width / window_width * 100.0f, recompui::Unit::Percent);
            l.svg->set_height(l.height / window_height * 100.0f, recompui::Unit::Percent);
        }
        laid_out_width = window_width;
        laid_out_height = window_height;
    }
}

namespace tooie::launcher_title {
    void init(recompui::LauncherMenu* menu) {
        recompui::ContextId context = recompui::get_current_context();
        menu->remove_default_title();
        layer = context.create_element<recompui::Element>(menu, 0, "div", false);
        layer->set_position(recompui::Position::Absolute);
        layer->set_top(0);
        layer->set_left(0);
        layer->set_width(100.0f, recompui::Unit::Percent);
        layer->set_height(100.0f, recompui::Unit::Percent);
        layer->set_overflow(recompui::Overflow::Hidden);
        layer->set_pointer_events(recompui::PointerEvents::None);
        for (TitleLetter& l : title_letters) {
            l.svg = context.create_element<recompui::Svg>(layer, l.path);
            l.svg->set_position(recompui::Position::Absolute);
            l.svg->set_pointer_events(recompui::PointerEvents::None);
            // Transforms keep the order they were first set in: move, then turn, then squash.
            l.svg->set_translate_2D(0.0f, -1000.0f, recompui::Unit::Percent);
            l.svg->set_rotation(l.tilt);
            l.svg->set_scale_2D(1.0f, 1.0f);
        }
        started = false;
    }

    void update(recompui::LauncherMenu* menu) {
        if (layer == nullptr) {
            return;
        }
        float window_width = layer->get_client_width();
        float window_height = layer->get_client_height();
        if (window_width <= 0 || window_height <= 0) {
            return;
        }
        if (window_width != laid_out_width || window_height != laid_out_height) {
            lay_out(window_width, window_height);
        }

        clock::time_point now = clock::now();
        if (!started || std::chrono::duration<float>(now - last_update).count() > restart_gap) {
            start_time = now;
            started = true;
        }
        last_update = now;
        float t = std::chrono::duration<float>(now - start_time).count();

        // Each letter falls from above the window, squashes as it lands, then rocks gently, each a
        // little out of step with the next.
        int index = 0;
        for (TitleLetter& l : title_letters) {
            float letter_t = t - title_start - index * title_letter_gap;
            float k = clamp01(letter_t / title_fall_time);
            float dy = -(l.top + l.height + 0.05f * window_height) * (1.0f - k * k);
            float squash = 0.0f;
            float land_t = letter_t - title_fall_time;
            if (land_t > 0 && land_t < title_settle_time) {
                float j = land_t / title_settle_time;
                squash = 0.2f * std::cos(two_pi * 1.5f * j) * (1.0f - j) * (1.0f - j);
                // A small rebound off the ground.
                dy -= l.height * 0.15f * std::sin(two_pi * 0.5f * j) * (1.0f - j);
            }
            float rock_t = land_t - title_settle_time;
            float rock = rock_t > 0 ? std::sin(two_pi * (rock_t / title_rock_period + index * 0.13f)) * smoothstep(rock_t) : 0.0f;
            l.svg->set_translate_2D(0.0f, dy / l.height * 100.0f, recompui::Unit::Percent);
            l.svg->set_rotation(l.tilt + rock * title_rock);
            l.svg->set_scale_2D(1.0f + squash, 1.0f - squash);
            index++;
        }
    }
}
