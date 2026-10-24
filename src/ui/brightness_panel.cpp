// The Brightness & Colour Grading panel (L, 2026-10-24): the button at the top of Display > Display turns the test
// pattern on (ten grey boxes at the top of the picture). While it is on, the ESC menu is shut and a panel along the
// bottom edge has sliders for Brightness, Contrast, Colour Saturation, Vignette and Film Grain (hidden from the
// Graphics page), a Quit button and a Back To Menu button. Quit turns the pattern off and the panel goes away; Back To
// Menu does the same and opens the ESC menu again. The panel is its own UI context that takes input (as the menu
// does), so the game stays paused behind it like behind the menu.

#include <atomic>
#include <chrono>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include "recompui/recompui.h"
#include "recompui/config.h"
#include "elements/ui_element.h"
#include "elements/ui_label.h"
#include "elements/ui_button.h"
#include "elements/ui_slider.h"
#include "elements/ui_sidebar_style.h"

#include "tooie_brightness_panel.h"
#include "tooie_picture_filters.h"

namespace {
    using namespace std::chrono_literals;

    constexpr auto poll_interval = 50ms;
    constexpr auto ui_wait = 500ms;

    std::once_flag started;
    std::atomic<bool> panel_up{ false };
    // Set by the Back To Menu button: once the panel is gone the ESC menu opens again.
    std::atomic<bool> reopen_menu{ false };

    namespace style = recompui::sidebar_style;

    struct Panel {
        recompui::ContextId context = recompui::ContextId::null();
        std::vector<recompui::Slider*> sliders;
        recompui::Button* quit = nullptr;
        recompui::Button* back = nullptr;
    };

    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(recompui::config::graphics::id);
    }

    bool pattern_on() {
        try {
            return std::get<bool>(graphics_config().get_option_value(tooie::picture_filters::brightness_pattern_option));
        } catch (...) {
            return false;
        }
    }

    // The settings the panel edits, in order; they are hidden from the Graphics page.
    struct Row {
        const std::string* id;
        const char* name;
        double min, max, step;
    };
    const Row rows[] = {
        { &tooie::picture_filters::brightness_option, "Brightness", -5, 5, 1 },
        { &tooie::picture_filters::contrast_option, "Contrast", -50, 50, 5 },
        { &tooie::picture_filters::saturation_option, "Colour Saturation", -100, 100, 5 },
        { &tooie::picture_filters::vignette_option, "Vignette", 0, 100, 5 },
        { &tooie::picture_filters::grain_option, "Film Grain", 0, 100, 5 },
    };

    double option_value(const std::string& id) {
        try {
            return std::get<double>(graphics_config().get_option_value(id));
        } catch (...) {
            return 0.0;
        }
    }

    bool menu_open() {
        try {
            return recompui::config::get_config_modal()->is_open_now();
        } catch (...) {
            return false;
        }
    }

    // Shuts the ESC menu (it was open to press the button).
    void close_menu() {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        try {
            recompui::ContextId context = recompui::config::get_config_context_id();
            context.open();
            recompui::config::close();
            context.close();
        } catch (...) {
        }
    }

    // In the settings menu's colours and lettering, like the photo panel.
    bool build(Panel& p) {
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

            recompui::Element* box = ctx.create_element<recompui::Element>(root);
            box->set_display(recompui::Display::Flex);
            box->set_flex_direction(recompui::FlexDirection::Column);
            box->set_align_items(recompui::AlignItems::Stretch);
            box->set_position(recompui::Position::Absolute);
            // Along the bottom of the window; the test pattern is at the top.
            box->set_bottom(24);
            box->set_left(24);
            box->set_right(24);
            box->set_padding(14);
            box->set_border_radius(recompui::theme::border::radius_lg);
            box->set_border_width(3);
            box->set_border_color(style::gold);
            box->set_background_color(style::panel);
            box->set_as_navigation_container(recompui::NavigationType::Vertical);

            recompui::Label* title = ctx.create_element<recompui::Label>(box, "Brightness & Colour Grading", recompui::LabelStyle::Normal);
            title->set_font_family(style::font);
            title->set_font_weight(400);
            title->set_font_size(38);
            title->set_letter_spacing(2);
            title->set_color(style::gold);
            title->set_margin_bottom(8);
            title->set_padding_left(6);

            recompui::Label* help = ctx.create_element<recompui::Label>(box,
                "Set Brightness so the first box at the top just disappears into the black and the second one is just visible.",
                recompui::LabelStyle::Annotation);
            help->set_color(style::cream_dim);
            help->set_margin_bottom(10);
            help->set_padding_left(6);

            for (const Row& row : rows) {
                recompui::Element* line = ctx.create_element<recompui::Element>(box);
                line->set_display(recompui::Display::Flex);
                line->set_flex_direction(recompui::FlexDirection::Row);
                line->set_align_items(recompui::AlignItems::Center);
                line->set_padding_left(6);
                recompui::Label* name = ctx.create_element<recompui::Label>(line, row.name, recompui::LabelStyle::Small);
                name->set_font_family(style::font);
                name->set_font_weight(400);
                name->set_font_size(20);
                name->set_letter_spacing(1);
                name->set_color(style::cream);
                name->set_width(220);
                recompui::Slider* slider = ctx.create_element<recompui::Slider>(line, recompui::SliderType::Double);
                slider->set_flex_grow(1);
                slider->set_min_value(row.min);
                slider->set_max_value(row.max);
                slider->set_step_value(row.step);
                slider->set_precision(0);
                slider->set_value(option_value(*row.id));
                const std::string* id = row.id;
                slider->add_value_changed_callback([id](double v) {
                    graphics_config().set_option_value(*id, v);
                });
                p.sliders.push_back(slider);
            }

            recompui::Element* buttons = ctx.create_element<recompui::Element>(box);
            buttons->set_display(recompui::Display::Flex);
            buttons->set_flex_direction(recompui::FlexDirection::Row);
            buttons->set_margin_top(10);
            buttons->set_as_navigation_container(recompui::NavigationType::Horizontal);
            p.quit = ctx.create_element<recompui::Button>(buttons, "Quit", recompui::ButtonStyle::Primary, recompui::ButtonSize::Medium);
            p.quit->set_margin_right(12);
            p.quit->add_pressed_callback([] {
                graphics_config().set_option_value(tooie::picture_filters::brightness_pattern_option, false);
            });

            p.back = ctx.create_element<recompui::Button>(buttons, "Back To Menu", recompui::ButtonStyle::Secondary, recompui::ButtonSize::Medium);
                        p.back->add_pressed_callback([] {
                reopen_menu.store(true);
                graphics_config().set_option_value(tooie::picture_filters::brightness_pattern_option, false);
            });

            ctx.set_autofocus_element(p.quit);
            ctx.close();
            p.context = ctx;
            return true;
        } catch (...) {
            return false;
        }
    }

    // The game start clears every shown context, so check the real state each time.
    void show(Panel& p) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        if (!recompui::is_context_shown(p.context)) {
            recompui::show_context(p.context, "");
        }
    }

    void hide(Panel& p) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        if (recompui::is_context_shown(p.context)) {
            recompui::hide_context(p.context);
        }
    }

    // Brings the slider to the saved value each time the panel comes up.
    void sync_slider(Panel& p) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        p.context.open();
        for (size_t i = 0; i < p.sliders.size(); i++) {
            p.sliders[i]->set_value(option_value(*rows[i].id));
        }
        p.context.close();
    }

    // The ESC menu again, on the tab it was left on.
    void open_menu() {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        try {
            recompui::ContextId context = recompui::config::get_config_context_id();
            context.open();
            recompui::config::open();
            context.close();
        } catch (...) {
        }
    }

    void worker() {
        Panel panel;
        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            if (!pattern_on()) {
                if (panel_up.load()) {
                    hide(panel);
                    panel_up.store(false);
                    if (reopen_menu.exchange(false)) {
                        open_menu();
                    }
                }
                continue;
            }
            if (panel.context == recompui::ContextId::null() && !build(panel)) {
                std::this_thread::sleep_for(ui_wait);
                continue;
            }
            if (!panel_up.load()) {
                // The pattern was just turned on from the menu: shut the menu, then bring the panel up.
                panel_up.store(true);
                sync_slider(panel);
            }
            if (menu_open()) {
                close_menu();
            }
            show(panel);
        }
    }
}

bool tooie::brightness_panel::active() {
    return panel_up.load();
}

void tooie::brightness_panel::start() {
    std::call_once(started, [] {
        // Detached on purpose: the thread owns no resources that need a clean shutdown.
        std::thread(worker).detach();
    });
}
