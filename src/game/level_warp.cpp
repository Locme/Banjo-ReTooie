// Level warp (handoff 4.80).
//
// A "Level warp" tab in the menu lists the places in level_warp_places.inc,
// grouped by area. Picking one closes the menu and asks for the warp, which
// src/debug/warp.cpp issues on the game thread at the start of the next frame
// with the game's own map change (the usual wipe and title card). Warping to
// the map you are in does nothing. F9 repeats the last warp.

#include <atomic>
#include <chrono>
#include <mutex>
#include <optional>
#include <string>
#include <thread>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recompui/recompui.h"
#include "recompui/config.h"
#include "elements/ui_button.h"
#include "elements/ui_container.h"
#include "elements/ui_label.h"
#include "elements/ui_scroll_container.h"

#include "tooie_debug.h"
#include "tooie_level_warp.h"
#include "tooie_toast.h"

namespace {
    using namespace std::chrono_literals;

    struct Place {
        const char* group;
        const char* name;
        uint16_t map;
        uint8_t exit;
    };

    constexpr Place places[] = {
#include "level_warp_places.inc"
    };

    constexpr auto poll_interval = 10ms;
    std::once_flag started;

    std::mutex last_mutex;
    std::optional<Place> last;

    void warp_to(const Place& place) {
        {
            std::lock_guard lock{last_mutex};
            last = place;
        }
        tooie::debug::request_warp(place.map, place.exit);
        tooie::toast::show(std::string("Warping to ") + place.name);
    }

    bool key_down() {
        const Uint8* keys = SDL_GetKeyboardState(nullptr);
        return keys != nullptr && keys[SDL_SCANCODE_F9] != 0;
    }

    void worker() {
        bool was_down = false;
        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            bool down = key_down();
            if (down && !was_down) {
                std::optional<Place> place;
                {
                    std::lock_guard lock{last_mutex};
                    place = last;
                }
                if (place.has_value()) {
                    warp_to(*place);
                } else {
                    tooie::toast::show("Pick a place in Level warp first");
                }
            }
            was_down = down;
        }
    }

    void create_contents(recompui::ContextId context, recompui::Element* parent) {
        using namespace recompui;
        ScrollContainer* scroll = context.create_element<ScrollContainer>(parent, ScrollDirection::Vertical);
        scroll->set_width(100.0f, Unit::Percent);
        scroll->set_height(100.0f, Unit::Percent);
        scroll->set_padding(16.0f);

        Container* list = context.create_element<Container>(scroll, FlexDirection::Column, JustifyContent::FlexStart);
        list->set_gap(8.0f);

        Container* row = nullptr;
        const char* group = nullptr;
        for (const Place& place : places) {
            if (group == nullptr || std::string(group) != place.group) {
                group = place.group;
                Label* heading = context.create_element<Label>(list, group, LabelStyle::Large);
                heading->set_margin_top(8.0f);
                row = context.create_element<Container>(list, FlexDirection::Row, JustifyContent::FlexStart);
                row->set_flex_wrap(FlexWrap::Wrap);
                row->set_gap(8.0f);
            }
            Button* button = context.create_element<Button>(row, place.name, ButtonStyle::Secondary, ButtonSize::Medium);
            button->add_pressed_callback([place]() {
                recompui::config::close();
                warp_to(place);
            });
        }
    }
}

void tooie::level_warp::create_tab() {
    recompui::config::create_tab("Level warp", "level_warp", create_contents);
}

void tooie::level_warp::start() {
    std::call_once(started, [] {
        std::thread(worker).detach();
    });
}
