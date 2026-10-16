// The photo panel (handoff 4.82): while photo mode is on and the panel isn't hidden (L), a list at the
// left of the screen shows photo mode's rows (tooie::photo_mode::panel_state) with the picked one
// highlighted, and the controls under it, styled like the settings menu. Like the toasts it is a UI layer that never takes input, so
// it is never in screenshots.

#include <chrono>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include "recompui/recompui.h"
#include "elements/ui_element.h"
#include "elements/ui_label.h"
#include "elements/ui_sidebar_style.h"
#include "elements/ui_svg.h"

#include "tooie_photo_mode.h"
#include "tooie_photo_panel.h"

namespace {
    using namespace std::chrono_literals;

    constexpr auto poll_interval = 50ms;
    constexpr auto flash_interval = 16ms;
    constexpr auto ui_wait = 500ms;
    constexpr size_t max_rows = 20;
    const char* const help_lines[] = {
        "D-pad: pick and change a row",
        "Left stick: move  ·  Right stick: look",
        "Z / R: down / up  ·  A: photo  ·  L: hide list",
        "Start: time  ·  B: back to the game",
    };

    std::once_flag started;

    namespace style = recompui::sidebar_style;
    const recompui::Color clear{ 0, 0, 0, 0 };

    // One row of the list: a Jiggy shown on the picked row (as on the settings menu's picked tab), the
    // row's name and its value.
    struct RowView {
        recompui::Element* box = nullptr;
        recompui::Svg* jiggy = nullptr;
        recompui::Label* name = nullptr;
        recompui::Label* value = nullptr;
    };

    struct Panel {
        recompui::ContextId context = recompui::ContextId::null();
        std::vector<RowView> rows;
        bool shown = false;
        std::vector<std::string> last_rows;
        int last_picked = -1;
    };

    // In the settings menu's colours and lettering (L: "You can copy the ESC menu"): a brown panel with a
    // gold border, the title in Luckiest Guy, the picked row in gold with brown letters.
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
            root->set_pointer_events(recompui::PointerEvents::None);

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
            box->set_pointer_events(recompui::PointerEvents::None);

            recompui::Label* title = ctx.create_element<recompui::Label>(box, "Photo Mode", recompui::LabelStyle::Normal);
            title->set_pointer_events(recompui::PointerEvents::None);
            title->set_font_family(style::font);
            title->set_font_weight(400);
            title->set_font_size(38);
            title->set_letter_spacing(2);
            title->set_color(style::gold);
            title->set_margin_bottom(8);
            title->set_padding_left(6);

            for (size_t i = 0; i < max_rows; i++) {
                RowView r;
                r.box = ctx.create_element<recompui::Element>(box);
                r.box->set_display(recompui::Display::Flex);
                r.box->set_flex_direction(recompui::FlexDirection::Row);
                r.box->set_align_items(recompui::AlignItems::Center);
                r.box->set_position(recompui::Position::Relative);
                r.box->set_padding_top(3);
                r.box->set_padding_bottom(2);
                r.box->set_padding_left(36);
                r.box->set_padding_right(10);
                r.box->set_border_radius(recompui::theme::border::radius_md);
                r.box->set_border_width(2);
                r.box->set_border_color(recompui::theme::color::Transparent);
                r.box->set_border_bottom_color(style::gold_faint);
                r.box->set_pointer_events(recompui::PointerEvents::None);

                r.jiggy = ctx.create_element<recompui::Svg>(r.box, "icons/Jiggy.svg");
                r.jiggy->set_position(recompui::Position::Absolute);
                r.jiggy->set_left(6);
                r.jiggy->set_top(50.0f, recompui::Unit::Percent);
                r.jiggy->set_width(22);
                r.jiggy->set_height(22);
                r.jiggy->set_margin_top(-11);
                r.jiggy->set_pointer_events(recompui::PointerEvents::None);

                r.name = ctx.create_element<recompui::Label>(r.box, "", recompui::LabelStyle::Small);
                r.name->set_pointer_events(recompui::PointerEvents::None);
                r.name->set_font_family(style::font);
                r.name->set_font_weight(400);
                r.name->set_font_size(20);
                r.name->set_letter_spacing(1);
                r.name->set_flex_grow(1);

                r.value = ctx.create_element<recompui::Label>(r.box, "", recompui::LabelStyle::Small);
                r.value->set_pointer_events(recompui::PointerEvents::None);
                r.value->set_text_align(recompui::TextAlign::Right);
                p.rows.push_back(r);
            }

            recompui::Element* help_box = ctx.create_element<recompui::Element>(box);
            help_box->set_display(recompui::Display::Flex);
            help_box->set_flex_direction(recompui::FlexDirection::Column);
            help_box->set_margin_top(10);
            help_box->set_padding(8);
            help_box->set_border_radius(recompui::theme::border::radius_md);
            help_box->set_border_top_width(2);
            help_box->set_border_top_color(style::gold_soft);
            help_box->set_background_color(style::sidebar);
            help_box->set_pointer_events(recompui::PointerEvents::None);
            for (const char* line : help_lines) {
                recompui::Label* help = ctx.create_element<recompui::Label>(help_box, line, recompui::LabelStyle::Annotation);
                help->set_pointer_events(recompui::PointerEvents::None);
                help->set_color(style::cream_dim);
            }
            ctx.close();

            // The panel must never swallow the game's input.
            ctx.set_captures_input(false);
            ctx.set_captures_mouse(false);
            p.context = ctx;
            return true;
        } catch (...) {
            return false;
        }
    }

    void update(Panel& p, const std::vector<std::string>& rows, int picked) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        if (rows == p.last_rows && picked == p.last_picked) {
            return;
        }
        p.context.open();
        for (size_t i = 0; i < p.rows.size(); i++) {
            RowView& r = p.rows[i];
            if (i >= rows.size()) {
                r.box->set_display(recompui::Display::None);
                continue;
            }
            // Rows come as "Name: value".
            const std::string& text = rows[i];
            const size_t split = text.find(": ");
            const std::string name = split == std::string::npos ? text : text.substr(0, split);
            const std::string value = split == std::string::npos ? "" : text.substr(split + 2);
            const bool is_picked = (int)i == picked;
            r.name->set_text(name);
            // Arrows on the picked row: D-pad left and right change it.
            r.value->set_text(is_picked && !value.empty() ? "\u2039 " + value + " \u203A" : value);
            r.name->set_color(is_picked ? style::brown_text : style::cream);
            r.value->set_color(is_picked ? style::brown_text : style::gold);
            r.box->set_background_color(is_picked ? style::gold : clear);
            r.box->set_border_color(is_picked ? style::orange : clear);
            if (!is_picked) {
                r.box->set_border_bottom_color(style::gold_faint);
            }
            r.jiggy->set_display(is_picked ? recompui::Display::Block : recompui::Display::None);
            r.box->set_display(recompui::Display::Flex);
        }
        p.context.close();
        p.last_rows = rows;
        p.last_picked = picked;
    }

    // The shutter flash: a white sheet over the whole window, faded out by tooie::photo_mode::flash_level.
    // Its own context, so it shows with the list hidden too.
    struct Flash {
        recompui::ContextId context = recompui::ContextId::null();
        recompui::Element* sheet = nullptr;
        bool shown = false;
    };

    bool build_flash(Flash& f) {
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
            f.sheet = ctx.create_element<recompui::Element>(root);
            f.sheet->set_position(recompui::Position::Absolute);
            f.sheet->set_top(0);
            f.sheet->set_left(0);
            f.sheet->set_width(100.0f, recompui::Unit::Percent);
            f.sheet->set_height(100.0f, recompui::Unit::Percent);
            f.sheet->set_background_color(recompui::Color{ 255, 255, 255, 255 });
            f.sheet->set_opacity(0.0f);
            f.sheet->set_pointer_events(recompui::PointerEvents::None);
            ctx.close();
            ctx.set_captures_input(false);
            ctx.set_captures_mouse(false);
            f.context = ctx;
            return true;
        } catch (...) {
            return false;
        }
    }

    void set_flash(Flash& f, float level) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        if (level > 0.0f) {
            f.context.open();
            f.sheet->set_opacity(0.85f * level);
            f.context.close();
            if (!recompui::is_context_shown(f.context)) {
                recompui::show_context(f.context, "");
            }
            f.shown = true;
        }
        else if (f.shown) {
            if (recompui::is_context_shown(f.context)) {
                recompui::hide_context(f.context);
            }
            f.shown = false;
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
        p.shown = true;
    }

    void hide(Panel& p) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        if (p.shown && recompui::is_context_shown(p.context)) {
            recompui::hide_context(p.context);
        }
        p.shown = false;
    }

    void worker() {
        Panel panel;
        Flash flash;
        std::vector<std::string> rows;
        for (;;) {
            const float level = tooie::photo_mode::flash_level();
            std::this_thread::sleep_for(level > 0.0f || flash.shown ? flash_interval : poll_interval);
            if (level > 0.0f || flash.shown) {
                if (flash.context != recompui::ContextId::null() || build_flash(flash)) {
                    set_flash(flash, tooie::photo_mode::flash_level());
                }
            }
            int picked = 0;
            const bool want = tooie::photo_mode::panel_state(rows, picked);
            if (!want) {
                if (panel.shown) {
                    hide(panel);
                }
                continue;
            }
            if (panel.context == recompui::ContextId::null() && !build(panel)) {
                std::this_thread::sleep_for(ui_wait);
                continue;
            }
            update(panel, rows, picked);
            show(panel);
        }
    }
}

void tooie::photo_panel::start() {
    std::call_once(started, [] {
        // Detached on purpose: the thread owns no resources that need a clean shutdown.
        std::thread(worker).detach();
    });
}
