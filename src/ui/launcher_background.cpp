// The start menu's animated background (L, 2026-10-24). L's BANJO.svg is split into layers in
// assets/launcher/ (tools/split_launcher_svg.py), each with a viewBox around its own art so the art that
// bleeds past L's artboard is kept. The layers are placed as one picture: the artboard's full height
// fills the window, and wider windows show the bleed at the sides.
//
// The picture fades in, the cliff slides in from the right and the pillar and the rock arch (group
// "4") from the left, the path (L's group "1") rises from below, the ledge with the fence (group "5")
// rises at the right, the head (group "2") drops onto the cliff and squashes as it lands, and its
// ladder (group "3") unrolls from its mouth. Then everything drifts a little: the two sides against
// each other, the hill a little less (depth), the head swaying on its ladder, the little green critter
// on the ledge hopping now and then, and clouds crossing the sky. The title is its own animation,
// src/ui/launcher_title.cpp.

#include <algorithm>
#include <chrono>
#include <cmath>

#include "recompui/recompui.h"
#include "core/ui_context.h"
#include "elements/ui_element.h"
#include "elements/ui_svg.h"
#include "base/ui_launcher.h"

#include "tooie_launcher_background.h"

namespace {
    using clock = std::chrono::steady_clock;

    // L's artboard (the BANJO.svg viewBox).
    constexpr float art_width = 2284.48f;
    constexpr float art_height = 1735.67f;
    // How far the sky reaches each side of the artboard's centre; wider windows scale up to stay inside it.
    constexpr float bleed_half_width = 1793.0f;
    constexpr float two_pi = 6.2831853f;

    // Timing, in seconds.
    constexpr float fade_time = 0.6f;
    constexpr float slide_delay = 0.3f;
    constexpr float slide_time = 1.6f;
    constexpr float path_rise_start = 1.6f;
    constexpr float path_rise_time = 0.7f;
    constexpr float head_drop_start = 2.1f;
    constexpr float head_drop_time = 0.45f;
    constexpr float head_land_time = 0.9f;
    constexpr float back_left_delay = 0.2f;
    constexpr float ledge_rise_start = 1.9f;
    constexpr float ledge_rise_time = 0.7f;
    constexpr float ladder_unroll_start = 2.8f;
    constexpr float ladder_unroll_time = 0.6f;
    constexpr float hop_start = 3.4f;
    constexpr float hop_period = 3.5f;
    constexpr float hop_time = 0.55f;
    constexpr float drift_ramp_time = 1.5f;
    constexpr float drift_period_x = 7.0f;
    constexpr float drift_period_y = 5.0f;
    constexpr float head_sway_period = 6.0f;
    // Drift size, as a fraction of the window.
    constexpr float drift_x = 0.004f;
    constexpr float drift_y = 0.003f;
    // The hill drifts this much of the front parts' drift, so it looks further away.
    constexpr float hill_depth = 0.35f;
    // Head sway, in degrees, and its squash on landing.
    constexpr float head_sway = 1.2f;
    constexpr float head_squash = 0.12f;
    // The ladder's top (its layer's middle) sits this far above the head's turning point, in artboard units.
    constexpr float ladder_above_pivot = 376.0f;
    // The critter's hop height, in artboard units, and its squash.
    constexpr float hop_height = 70.0f;
    constexpr float hop_squash = 0.15f;
    // Seconds for a cloud to cross the artboard.
    constexpr float cloud_crossing_time = 120.0f;
    // The launcher was hidden if no update came for this long; the intro plays again when it is back.
    constexpr float restart_gap = 1.0f;

    enum class Motion {
        Hill,
        Cloud,
        FromRight,
        Path,
        Head,
        Ladder,
        BackLeft,
        FromLeft,
        Ledge,
        Critter,
    };

    struct Layer {
        const char* path;
        // The layer's viewBox, in artboard units.
        float x, y, w, h;
        Motion motion;
        // Clouds: where along the crossing it starts (0 to 1), and its speed relative to the others.
        float phase = 0.0f;
        float speed = 1.0f;
        recompui::Svg* svg = nullptr;
        float left = 0, top = 0, width = 0, height = 0; // In window pixels.
    };

    // Back to front. The art viewBoxes match tools/split_launcher_svg.py; a cloud is 400x160 (cloud.svg)
    // scaled to its size here.
    Layer layers[] = {
        { "launcher/background.svg", -829, -917, 4045, 3140, Motion::Hill },
        { "launcher/cloud.svg", 0, 40, 520, 208, Motion::Cloud, 0.15f, 1.0f },
        { "launcher/cloud.svg", 0, 230, 340, 136, Motion::Cloud, 0.55f, 0.7f },
        { "launcher/cloud.svg", 0, -60, 420, 168, Motion::Cloud, 0.85f, 0.85f },
        { "launcher/slide_right.svg", 516, 347, 2695, 952, Motion::FromRight },
        { "launcher/path.svg", -2, 1031, 1945, 931, Motion::Path },
        { "launcher/head.svg", 1128, -276, 844, 2632, Motion::Head },
        { "launcher/ladder.svg", 1498, 280, 98, 768, Motion::Ladder },
        { "launcher/back_left.svg", -842, 584, 1511, 605, Motion::BackLeft },
        { "launcher/slide_left.svg", 263, 590, 1557, 965, Motion::FromLeft },
        { "launcher/ledge.svg", 1721, 1194, 1134, 525, Motion::Ledge },
        { "launcher/bird.svg", 2091, 1316, 184, 268, Motion::Critter },
    };


    float laid_out_width = 0, laid_out_height = 0;
    // Window pixels per artboard unit, and where the artboard's left edge is.
    float scale = 1.0f;
    float origin_x = 0.0f;
    clock::time_point start_time;
    clock::time_point last_update;
    bool started = false;

    float clamp01(float t) {
        return std::clamp(t, 0.0f, 1.0f);
    }

    float ease_out_cubic(float t) {
        float u = 1.0f - t;
        return 1.0f - u * u * u;
    }

    // Ease out with a small overshoot.
    float ease_out_back(float t) {
        constexpr float c1 = 1.2f;
        constexpr float c3 = c1 + 1.0f;
        float u = t - 1.0f;
        return 1.0f + c3 * u * u * u + c1 * u * u;
    }

    float smoothstep(float t) {
        t = clamp01(t);
        return t * t * (3.0f - 2.0f * t);
    }

    void lay_out(float window_width, float window_height) {
        scale = std::max(window_height / art_height, window_width / (2.0f * bleed_half_width));
        origin_x = window_width * 0.5f - art_width * 0.5f * scale;
        float origin_y = window_height * 0.5f - art_height * 0.5f * scale;
        for (Layer& l : layers) {
            l.left = origin_x + l.x * scale;
            l.top = origin_y + l.y * scale;
            l.width = l.w * scale;
            l.height = l.h * scale;
            // Percent of the window, so the menu's own UI scale doesn't matter.
            l.svg->set_left(l.left / window_width * 100.0f, recompui::Unit::Percent);
            l.svg->set_top(l.top / window_height * 100.0f, recompui::Unit::Percent);
            l.svg->set_width(l.width / window_width * 100.0f, recompui::Unit::Percent);
            l.svg->set_height(l.height / window_height * 100.0f, recompui::Unit::Percent);
        }
        laid_out_width = window_width;
        laid_out_height = window_height;
    }
}

namespace tooie::launcher_background {
    void init(recompui::LauncherMenu* menu) {
        recompui::ContextId context = recompui::get_current_context();
        recompui::Element* wrapper = menu->get_background_wrapper();
        wrapper->set_overflow(recompui::Overflow::Hidden);
        wrapper->set_opacity(0.0f);
        for (Layer& l : layers) {
            l.svg = context.create_element<recompui::Svg>(wrapper, l.path);
            l.svg->set_position(recompui::Position::Absolute);
            // Transforms keep the order they were first set in: move, then turn, then squash.
            l.svg->set_translate_2D(0.0f, 0.0f, recompui::Unit::Percent);
            if (l.motion == Motion::Head || l.motion == Motion::Ladder || l.motion == Motion::Critter) {
                l.svg->set_rotation(0.0f);
                l.svg->set_scale_2D(1.0f, 1.0f);
            }
        }
        started = false;
    }

    void update(recompui::LauncherMenu* menu) {
        if (layers[0].svg == nullptr) {
            return;
        }
        recompui::Element* wrapper = menu->get_background_wrapper();
        float window_width = wrapper->get_client_width();
        float window_height = wrapper->get_client_height();
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

        wrapper->set_opacity(smoothstep(t / fade_time));

        float slide = ease_out_cubic(clamp01((t - slide_delay) / slide_time));
        float drift_t = t - slide_delay - slide_time;
        float ramp = smoothstep(drift_t / drift_ramp_time);
        float wave_x = drift_t > 0 ? std::sin(two_pi * drift_t / drift_period_x) * ramp : 0.0f;
        float wave_y = drift_t > 0 ? std::sin(two_pi * drift_t / drift_period_y) * ramp : 0.0f;
        // The right-hand part's drift; the left part and the hill move against it.
        float drift_dx = wave_x * drift_x * window_width;
        float drift_dy = wave_y * drift_y * window_height;
        float right_slide_dx = 0.0f;
        float slide_back = ease_out_cubic(clamp01((t - slide_delay - back_left_delay) / slide_time));
        // The head's move and turn, which the ladder follows; the ledge's, which the critter rides.
        float head_dx = 0.0f, head_dy = 0.0f, head_turn = 0.0f;
        float ledge_dx = 0.0f, ledge_dy = 0.0f;

        for (Layer& l : layers) {
            float dx = 0.0f, dy = 0.0f;
            switch (l.motion) {
                case Motion::Hill:
                    dx = -drift_dx * hill_depth;
                    dy = -drift_dy * hill_depth;
                    break;
                case Motion::Cloud: {
                    // Left to right across the sky the window shows, then round again.
                    float visible_left = -origin_x / scale;
                    float span = window_width / scale + l.w;
                    float along = std::fmod(l.phase + t * l.speed * art_width / (cloud_crossing_time * span), 1.0f);
                    dx = (visible_left - l.w + along * span - l.x) * scale;
                    dy = std::sin(two_pi * (t / 11.0f + l.phase)) * 6.0f * scale;
                    break;
                }
                case Motion::FromRight:
                    right_slide_dx = (window_width - l.left) * (1.0f - slide);
                    dx = right_slide_dx + drift_dx;
                    dy = drift_dy;
                    break;
                case Motion::Path: {
                    // Rises from below the window, overshooting a little, then moves with the left part.
                    float rise = ease_out_back(clamp01((t - path_rise_start) / path_rise_time));
                    dx = -drift_dx;
                    dy = -drift_dy + (window_height - l.top) * (1.0f - rise);
                    break;
                }
                case Motion::FromLeft:
                    dx = -(l.left + l.width) * (1.0f - slide) - drift_dx;
                    dy = -drift_dy;
                    break;
                case Motion::BackLeft:
                    // A beat behind the pillar, and drifting less, as it is further back.
                    dx = -(l.left + l.width) * (1.0f - slide_back) - drift_dx * 0.6f;
                    dy = -drift_dy * 0.6f;
                    break;
                case Motion::Ledge: {
                    float rise = ease_out_back(clamp01((t - ledge_rise_start) / ledge_rise_time));
                    ledge_dx = drift_dx;
                    ledge_dy = drift_dy + (window_height - l.top) * (1.0f - rise);
                    dx = ledge_dx;
                    dy = ledge_dy;
                    break;
                }
                case Motion::Critter: {
                    // Rides the ledge and hops every few seconds: crouch, jump, squash on landing.
                    dx = ledge_dx;
                    dy = ledge_dy;
                    float squash = 0.0f;
                    float hop_t = t - hop_start;
                    if (hop_t > 0) {
                        float k = std::fmod(hop_t, hop_period) / hop_time;
                        if (k < 1.0f) {
                            dy -= hop_height * scale * 4.0f * k * (1.0f - k);
                            squash = -hop_squash * std::sin(two_pi * 0.5f * k) * 0.5f;
                        }
                        else if (k < 1.5f) {
                            squash = hop_squash * std::sin(two_pi * (k - 1.0f));
                        }
                    }
                    l.svg->set_scale_2D(1.0f + squash, 1.0f - squash);
                    break;
                }
                case Motion::Ladder: {
                    // Hangs from the head's mouth: turns with the head (about its own top, plus the
                    // move that turning about the head's pivot gives the top), and unrolls downward.
                    float unroll = ease_out_back(clamp01((t - ladder_unroll_start) / ladder_unroll_time));
                    float turn = head_turn * two_pi / 360.0f;
                    dx = head_dx + ladder_above_pivot * scale * std::sin(turn);
                    dy = head_dy + ladder_above_pivot * scale * (1.0f - std::cos(turn));
                    l.svg->set_rotation(head_turn);
                    // Scaled about the layer's middle, which is the ladder's top.
                    l.svg->set_scale_2D(1.0f, std::max(unroll, 0.0f));
                    break;
                }
                case Motion::Head: {
                    // Rides on the cliff, and drops in from above the window as the cliff arrives.
                    float drop_t = t - head_drop_start;
                    float fall = clamp01(drop_t / head_drop_time);
                    // The art ends at the layer's middle (the ladder's foot), so lifting that above the
                    // window's top hides it all.
                    float above_window = l.top + l.height * 0.5f + 0.02f * window_height;
                    dx = right_slide_dx + drift_dx;
                    dy = drift_dy - above_window * (1.0f - fall * fall);
                    // Squash on landing, wobbling back to its shape.
                    float land_t = drop_t - head_drop_time;
                    float squash = 0.0f;
                    if (land_t > 0 && land_t < head_land_time) {
                        float k = land_t / head_land_time;
                        squash = head_squash * std::cos(two_pi * 1.5f * k) * (1.0f - k) * (1.0f - k);
                    }
                    l.svg->set_scale_2D(1.0f + squash, 1.0f - squash);
                    // Sway on its ladder once settled.
                    float sway_t = land_t - head_land_time * 0.5f;
                    float sway = sway_t > 0 ? std::sin(two_pi * sway_t / head_sway_period) * smoothstep(sway_t / 2.0f) : 0.0f;
                    l.svg->set_rotation(sway * head_sway);
                    head_dx = dx;
                    head_dy = dy;
                    head_turn = sway * head_sway;
                    break;
                }
            }
            // Percent of the layer's own size, as CSS transforms take it.
            l.svg->set_translate_2D(dx / l.width * 100.0f, dy / l.height * 100.0f, recompui::Unit::Percent);
        }
    }
}
