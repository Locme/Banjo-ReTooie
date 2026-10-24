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
    // The title sits in the sky above the rock arch (L, 2026-10-24), so it is placed in the background
    // art's units: its middle and width there. The art is fitted to the window as in
    // launcher_background.cpp: its full height fills the window, wider windows scaling up to stay inside
    // the sky's bleed.
    constexpr float art_width = 2284.48f;
    constexpr float art_height = 1735.67f;
    constexpr float bleed_half_width = 3340.0f;
    constexpr float title_art_x = 290.0f;
    constexpr float title_art_y = 330.0f;
    constexpr float title_art_width = 1150.0f;
    // The title's own box, in title units (title_letters below).
    constexpr float title_box_width = 674.0f;
    constexpr float title_box_middle = 140.7f;
    // The bounce: when the first letter starts, the gap between letters, how long each falls and settles.
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
        // Its place in the bounce, in reading order (the table is back to front).
        int order;
        recompui::Svg* svg = nullptr;
        float left = 0, top = 0, width = 0, height = 0; // In window pixels.
    };

    // BANJO over RE-TOOIE, each row centred, the letters packed and the rows overlapping as on the N64
    // box art, some letters over their neighbours and some under (the J over the O and into the row
    // below, the I over the O); traced from u/Plebian_Donkey_Konga's lettering sheet. Back to front.
    TitleLetter title_letters[] = {
        { "launcher/title_o_blue.svg", 79.7f, 172.3f, 129.6f, 106.9f, -4.0f, 10 },
        { "launcher/title_b.svg", -271.3f, 16.9f, 139.1f, 170.3f, -6.0f, 0 },
        { "launcher/title_n.svg", -47.7f, 41.6f, 150.8f, 145.6f, -3.0f, 2 },
        { "launcher/title_e_blue.svg", -226.4f, 144.2f, 123.1f, 137.2f, 4.0f, 6 },
        { "launcher/title_o_blue.svg", -5.8f, 174.4f, 129.6f, 106.9f, 4.0f, 9 },
        { "launcher/title_a.svg", -190.4f, 41.6f, 202.8f, 150.8f, 4.0f, 1 },
        { "launcher/title_o.svg", 115.3f, 59.8f, 156.0f, 130.0f, -4.0f, 4 },
        { "launcher/title_hyphen.svg", -140.3f, 210.1f, 79.9f, 51.8f, -4.0f, 7 },
        { "launcher/title_e_blue.svg", 214.1f, 144.2f, 123.1f, 137.2f, -5.0f, 12 },
        { "launcher/title_r_blue.svg", -337.2f, 136.6f, 158.8f, 142.6f, -5.0f, 5 },
        { "launcher/title_t_blue.svg", -103.0f, 131.2f, 143.6f, 148.0f, -3.0f, 8 },
        { "launcher/title_i_blue.svg", 175.0f, 121.5f, 72.4f, 157.7f, 3.0f, 11 },
        { "launcher/title_j.svg", 60.9f, 0.0f, 97.5f, 221.0f, 5.0f, 3 },
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
        float art_scale = std::max(window_height / art_height, window_width / (2.0f * bleed_half_width));
        float center_x = window_width * 0.5f + (title_art_x - art_width * 0.5f) * art_scale;
        // Sized by the window's height, so on very wide windows (32:9), where the art is cropped top and
        // bottom, the title doesn't grow with it, and kept below the window's top edge.
        float title_scale = title_art_width * (window_height / art_height) / title_box_width;
        float min_center_y = 0.03f * window_height + title_box_middle * title_scale;
        float center_y = std::max(window_height * 0.5f + (title_art_y - art_height * 0.5f) * art_scale, min_center_y);
        for (TitleLetter& l : title_letters) {
            l.left = center_x + l.x * title_scale;
            l.top = center_y + (l.y - title_box_middle) * title_scale;
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
        for (TitleLetter& l : title_letters) {
            int index = l.order;
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
        }
    }
}
