#include <chrono>
#include <cstdint>
#include <cstdio>
#include <mutex>
#include <string>
#include <thread>

#include "recompui/recompui.h"
#include "ultramodern/ultramodern.hpp"
#include "elements/ui_element.h"
#include "elements/ui_label.h"

#include "tooie_shader_progress.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_raster_shader_cache.h (from lib-patches/rt64.patch).
    void GetShaderListProgress(uint32_t &done, uint32_t &total);
}

// "Compiling shaders 42%" in the bottom-right corner while the shader list (the shaders met on earlier starts)
// compiles in the background, on the start menu and in the game alike. It goes away when the list is through.
namespace {
    using namespace std::chrono_literals;

    constexpr auto poll_interval = 250ms;
    // Wait for the UI to come up before building the overlay.
    constexpr auto ui_wait = 500ms;
    // "100%" stays up this long before the notice goes.
    constexpr auto done_hold = 1s;

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
            // Clicks pass through to the start menu under it: the document itself must not catch them either.
            ctx.get_root_element()->set_pointer_events(recompui::PointerEvents::None);
            recompui::Element* root = ctx.create_element<recompui::Element>(ctx.get_root_element());
            root->set_display(recompui::Display::Flex);
            root->set_background_color(recompui::theme::color::Transparent);
            root->set_pointer_events(recompui::PointerEvents::None);

            o.box = ctx.create_element<recompui::Element>(root);
            o.box->set_display(recompui::Display::Flex);
            o.box->set_position(recompui::Position::Absolute);
            o.box->set_bottom(24);
            o.box->set_right(24);
            o.box->set_padding(12);
            o.box->set_border_radius(recompui::theme::border::radius_lg);
            o.box->set_background_color(recompui::theme::color::ModalOverlay);
            o.box->set_pointer_events(recompui::PointerEvents::None);

            o.label = ctx.create_element<recompui::Label>(o.box, "", recompui::LabelStyle::Small);
            o.label->set_pointer_events(recompui::PointerEvents::None);
            ctx.close();

            // The notice must never take the menu's or the game's input.
            ctx.set_captures_input(false);
            ctx.set_captures_mouse(false);
            o.context = ctx;
            return true;
        } catch (...) {
            return false;
        }
    }

    // The game start clears every shown context, so the real state is checked each time.
    void show(Overlay& o, const std::string& text) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        // Before the game starts, the start menu only comes up while no other context is shown, so the
        // notice waits for it rather than keeping it away.
        if (!ultramodern::is_game_started() && !recompui::is_context_shown(recompui::get_launcher_context_id())) {
            return;
        }
        o.context.open();
        o.label->set_text(text);
        o.context.close();
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

    void worker() {
        Overlay overlay;
        std::string last_text;
        auto done_since = std::chrono::steady_clock::time_point{};
        for (;;) {
            std::this_thread::sleep_for(poll_interval);

            uint32_t done = 0;
            uint32_t total = 0;
            RT64::GetShaderListProgress(done, total);

            // Nothing to compile (no list, or the list is through and its 100% was shown).
            const auto now = std::chrono::steady_clock::now();
            if (total == 0 || done >= total) {
                if (overlay.shown) {
                    if (done_since == std::chrono::steady_clock::time_point{}) {
                        done_since = now;
                        show(overlay, "Compiling shaders 100%");
                    }
                    else if (now - done_since >= done_hold) {
                        hide(overlay);
                    }
                }
                continue;
            }
            done_since = {};

            if (overlay.context == recompui::ContextId::null() && !build(overlay)) {
                std::this_thread::sleep_for(ui_wait);
                continue;
            }

            char text[64];
            std::snprintf(text, sizeof(text), "Compiling shaders %u%%", static_cast<unsigned>(uint64_t(done) * 100 / total));
            show(overlay, text);
        }
    }
}

void tooie::shader_progress::start() {
    std::call_once(worker_once, [] {
        // Detached on purpose, like the toast worker: it owns nothing that needs a clean shutdown.
        std::thread(worker).detach();
    });
}
