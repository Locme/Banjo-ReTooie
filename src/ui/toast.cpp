#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <deque>
#include <mutex>
#include <string>
#include <thread>

#include "recompui/recompui.h"
#include "elements/ui_element.h"
#include "elements/ui_label.h"

#include "tooie_toast.h"
#include "tooie_language.h"

namespace {
    using namespace std::chrono_literals;

    constexpr auto display_time = 3s;
    constexpr auto fade_time = 500ms;
    constexpr auto fade_step = 40ms;
    // Wait for the UI to come up before building the overlay.
    constexpr auto ui_wait = 500ms;

    std::mutex queue_mutex;
    std::condition_variable queue_cv;
    std::deque<std::string> pending;
    std::once_flag worker_once;

    struct Overlay {
        recompui::ContextId context = recompui::ContextId::null();
        recompui::Element* box = nullptr;
        recompui::Label* label = nullptr;
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
            // The page's own body covers the whole window: without this it took the clicks meant for the Esc
            // menu under it for as long as a notice showed (found 2026-11-12, "Screenshot saved").
            ctx.get_root_element()->set_pointer_events(recompui::PointerEvents::None);
            recompui::Element* root = ctx.create_element<recompui::Element>(ctx.get_root_element());
            root->set_display(recompui::Display::Flex);
            root->set_background_color(recompui::theme::color::Transparent);
            root->set_pointer_events(recompui::PointerEvents::None);

            o.box = ctx.create_element<recompui::Element>(root);
            o.box->set_display(recompui::Display::Flex);
            o.box->set_position(recompui::Position::Absolute);
            o.box->set_top(24);
            o.box->set_right(24);
            o.box->set_max_width(520);
            o.box->set_padding(16);
            o.box->set_border_radius(recompui::theme::border::radius_lg);
            o.box->set_background_color(recompui::theme::color::ModalOverlay);
            o.box->set_pointer_events(recompui::PointerEvents::None);

            o.label = ctx.create_element<recompui::Label>(o.box, "", recompui::LabelStyle::Normal);
            o.label->set_pointer_events(recompui::PointerEvents::None);
            ctx.close();

            // A notice must never swallow the game's input.
            ctx.set_captures_input(false);
            ctx.set_captures_mouse(false);
            o.context = ctx;
            return true;
        } catch (...) {
            return false;
        }
    }

    void set_state(Overlay& o, const std::string* text, float opacity) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        o.context.open();
        if (text != nullptr) {
            o.label->set_text(*text);
        }
        o.box->set_opacity(opacity);
        o.context.close();
    }

    // The game start clears every shown context, so check the real state each time.
    void show_overlay(Overlay& o) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        if (!recompui::is_context_shown(o.context)) {
            recompui::show_context(o.context, "");
        }
        o.shown = true;
    }

    void hide_overlay(Overlay& o) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        if (o.shown && recompui::is_context_shown(o.context)) {
            recompui::hide_context(o.context);
        }
        o.shown = false;
    }

    // Takes the newest queued message, if any.
    bool take(std::string& out) {
        std::lock_guard lock{ queue_mutex };
        if (pending.empty()) {
            return false;
        }
        out = std::move(pending.back());
        pending.clear();
        return true;
    }

    void worker() {
        Overlay overlay;
        for (;;) {
            {
                std::unique_lock lock{ queue_mutex };
                queue_cv.wait(lock, [] { return !pending.empty(); });
            }
            if (overlay.context == recompui::ContextId::null() && !build(overlay)) {
                std::this_thread::sleep_for(ui_wait);
                continue;
            }

            std::string message;
            while (take(message)) {
                set_state(overlay, &message, 1.0f);
                show_overlay(overlay);

                // Hold, restarting the timer if another notice arrives.
                bool replaced = false;
                auto deadline = std::chrono::steady_clock::now() + display_time;
                while (std::chrono::steady_clock::now() < deadline) {
                    show_overlay(overlay);
                    std::unique_lock lock{ queue_mutex };
                    auto wake = std::min(deadline, std::chrono::steady_clock::now() + 250ms);
                    if (queue_cv.wait_until(lock, wake, [] { return !pending.empty(); })) {
                        replaced = true;
                        break;
                    }
                }
                if (replaced) {
                    continue;
                }

                for (auto elapsed = 0ms; elapsed < fade_time; elapsed += fade_step) {
                    float opacity = 1.0f - static_cast<float>(elapsed.count()) / fade_time.count();
                    set_state(overlay, nullptr, opacity);
                    std::this_thread::sleep_for(fade_step);
                    std::lock_guard lock{ queue_mutex };
                    if (!pending.empty()) {
                        break;
                    }
                }
            }
            hide_overlay(overlay);
        }
    }
}

void tooie::toast::show(const std::string& message) {
    std::call_once(worker_once, [] {
        // Detached on purpose: the thread owns no resources that need a clean shutdown.
        std::thread(worker).detach();
    });
    {
        std::lock_guard lock{ queue_mutex };
        // In the chosen language (General > Language): the translation file's toast.<English> lines.
        pending.push_back(tooie::language::notice_text(message));
    }
    queue_cv.notify_all();
}
