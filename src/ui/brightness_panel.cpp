// The brightness test panel (L, 2026-10-24): the Brightness Test Pattern button in the Graphics tab turns the
// pattern on. While it is on, the ESC menu is shut and a panel with only the Brightness slider and a Quit
// button is shown over the pattern. Quit turns the pattern off and the panel goes away. The panel is its own
// UI context that takes input (as the menu does), so the game stays paused behind it like behind the menu.

#include <atomic>
#include <chrono>
#include <mutex>
#include <thread>

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

    namespace style = recompui::sidebar_style;

    struct Panel {
        recompui::ContextId context = recompui::ContextId::null();
        recompui::Slider* slider = nullptr;
        recompui::Button* quit = nullptr;
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

    double brightness() {
        try {
            return std::get<double>(graphics_config().get_option_value(tooie::picture_filters::brightness_option));
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
            box->set_top(24);
            box->set_left(24);
            box->set_width(470);
            box->set_padding(14);
            box->set_border_radius(recompui::theme::border::radius_lg);
            box->set_border_width(3);
            box->set_border_color(style::gold);
            box->set_background_color(style::panel);
            box->set_as_navigation_container(recompui::NavigationType::Vertical);

            recompui::Label* title = ctx.create_element<recompui::Label>(box, "Brightness", recompui::LabelStyle::Normal);
            title->set_font_family(style::font);
            title->set_font_weight(400);
            title->set_font_size(38);
            title->set_letter_spacing(2);
            title->set_color(style::gold);
            title->set_margin_bottom(8);
            title->set_padding_left(6);

            recompui::Label* help = ctx.create_element<recompui::Label>(box,
                "Set Brightness so the first box just disappears into the black and the second one is just visible.",
                recompui::LabelStyle::Annotation);
            help->set_color(style::cream_dim);
            help->set_margin_bottom(10);
            help->set_padding_left(6);

            p.slider = ctx.create_element<recompui::Slider>(box, recompui::SliderType::Double);
            p.slider->set_width(100.0f, recompui::Unit::Percent);
            p.slider->set_min_value(-5);
            p.slider->set_max_value(5);
            p.slider->set_step_value(1);
            p.slider->set_precision(0);
            p.slider->set_value(brightness());
            p.slider->add_value_changed_callback([](double v) {
                graphics_config().set_option_value(tooie::picture_filters::brightness_option, v);
            });

            p.quit = ctx.create_element<recompui::Button>(box, "Quit", recompui::ButtonStyle::Primary, recompui::ButtonSize::Medium);
            p.quit->set_margin_top(14);
            p.quit->add_pressed_callback([] {
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
        p.slider->set_value(brightness());
        p.context.close();
    }

    void worker() {
        Panel panel;
        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            if (!pattern_on()) {
                if (panel_up.load()) {
                    hide(panel);
                    panel_up.store(false);
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
