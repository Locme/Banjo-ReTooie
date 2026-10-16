// The photo panel (handoff 4.82): while photo mode is on and the panel isn't hidden (L), a list at the
// left of the screen shows photo mode's rows (tooie::photo_mode::panel_state) with the picked one
// highlighted, and the controls under it. Like the toasts it is a UI layer that never takes input, so
// it is never in screenshots.

#include <chrono>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include "recompui/recompui.h"
#include "elements/ui_element.h"
#include "elements/ui_label.h"

#include "tooie_photo_mode.h"
#include "tooie_photo_panel.h"

namespace {
    using namespace std::chrono_literals;

    constexpr auto poll_interval = 50ms;
    constexpr auto ui_wait = 500ms;
    constexpr size_t max_rows = 20;
    const char* const help_lines[] = {
        "D-pad: pick and change a row  ·  L: hide this list",
        "Left stick: move  ·  Right stick: look  ·  Z / R: down / up",
        "A: photo  ·  Start: time  ·  B: back to the game",
    };

    std::once_flag started;

    struct Panel {
        recompui::ContextId context = recompui::ContextId::null();
        std::vector<recompui::Label*> rows;
        bool shown = false;
        std::vector<std::string> last_rows;
        int last_picked = -1;
    };

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
            box->set_align_items(recompui::AlignItems::FlexStart);
            box->set_position(recompui::Position::Absolute);
            box->set_top(24);
            box->set_left(24);
            box->set_padding(14);
            box->set_border_radius(recompui::theme::border::radius_lg);
            box->set_background_color(recompui::theme::color::ModalOverlay);
            box->set_pointer_events(recompui::PointerEvents::None);

            recompui::Label* title = ctx.create_element<recompui::Label>(box, "Photo mode", recompui::LabelStyle::Normal);
            title->set_pointer_events(recompui::PointerEvents::None);
            title->set_margin_bottom(6);
            // One label per row: a label is laid out as a single line.
            for (size_t i = 0; i < max_rows; i++) {
                recompui::Label* row = ctx.create_element<recompui::Label>(box, "", recompui::LabelStyle::Small);
                row->set_pointer_events(recompui::PointerEvents::None);
                p.rows.push_back(row);
            }
            for (size_t i = 0; i < std::size(help_lines); i++) {
                recompui::Label* help = ctx.create_element<recompui::Label>(box, help_lines[i], recompui::LabelStyle::Annotation);
                help->set_pointer_events(recompui::PointerEvents::None);
                help->set_color(recompui::theme::color::TextDim);
                if (i == 0) {
                    help->set_margin_top(8);
                }
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
            recompui::Label* label = p.rows[i];
            if (i < rows.size()) {
                const bool is_picked = (int)i == picked;
                label->set_text((is_picked ? "> " : "   ") + rows[i]);
                label->set_color(is_picked ? recompui::theme::color::Primary : recompui::theme::color::Text);
                label->set_display(recompui::Display::Block);
            }
            else {
                label->set_display(recompui::Display::None);
            }
        }
        p.context.close();
        p.last_rows = rows;
        p.last_picked = picked;
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
        std::vector<std::string> rows;
        for (;;) {
            std::this_thread::sleep_for(poll_interval);
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
