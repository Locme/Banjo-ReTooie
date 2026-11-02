// Level warp (handoff 4.80).
//
// A "Warp" tab in the menu lists the places in level_warp_places.inc,
// grouped by area. The tab shows only while Cheats > Enable cheats and
// Cheats > Warp tab are both on, and F9 only works then too. Picking one closes the menu and asks for the warp, which
// src/debug/warp.cpp issues on the game thread at the start of the next frame
// with the game's own map change (the usual wipe and title card). Warping to
// the map you are in does nothing. F9 repeats the last warp. Before a save
// file is being played (launcher, title screen, game select) a pick only shows
// "Start the game and load a file first". Test > Test room also fills its area
// with the test room's line-up (src/gameplay/test_room.cpp). Race Warps moved to Cheats > Replays
// (src/gameplay/replays.cpp, L 2026-10-17).

#include <atomic>
#include <chrono>
#include <mutex>
#include <optional>
#include <string>
#include <iterator>
#include <thread>
#include <variant>

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
#include "tooie_cheats.h"
#include "tooie_game.h"
#include "tooie_hotkeys.h"
#include "tooie_level_warp.h"
#include "tooie_test_room.h"
#include "tooie_toast.h"

namespace {
    using namespace std::chrono_literals;

    struct Place {
        const char* group;
        const char* name;
        uint16_t map;
        uint8_t exit;
        // Fills the area with the test room's line-up on arrival (src/gameplay/test_room.cpp).
        bool test_room = false;
    };

    const Place places[] = {
#include "level_warp_places.inc"
        { "Test", "Test room", tooie::test_room::map, tooie::test_room::exit, true },
        // Last, at the bottom of the tab.
    };

    constexpr auto poll_interval = 10ms;
    const std::string tab_id = "debug";
    const std::string option_id = "debug_tab";

    // The switch lives in the DEV tab's Additional Tabs (L, 2026-10-16; it was in Cheats > Tabs and
    // needed Enable cheats).
    bool debug_tab_on() {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(option_id));
        } catch (...) {
            return false;
        }
    }

    void show_tab(bool visible) {
        try {
            recompui::config::set_tab_visible(tab_id, visible);
        } catch (...) {
        }
    }
    std::once_flag started;

    std::mutex last_mutex;
    std::optional<Place> last;

    void warp_to(const Place& place) {
        {
            std::lock_guard lock{last_mutex};
            last = place;
        }
        if (place.test_room) {
            tooie::test_room::request();
        }
        tooie::debug::request_warp(place.map, place.exit);
        tooie::toast::show(std::string("Warping to ") + place.name);
    }

    bool key_down() {
        return tooie::hotkeys::down(recompinput::GameInput::WARP_AGAIN);
    }

    void worker() {
        bool was_down = false;
        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            bool down = key_down() && (debug_tab_on() || tooie::dev_file_present());
            if (down && !was_down) {
                std::optional<Place> place;
                {
                    std::lock_guard lock{last_mutex};
                    place = last;
                }
                if (place.has_value()) {
                    if (tooie::debug::can_warp()) {
                        warp_to(*place);
                    } else {
                        tooie::toast::show("Start the game and load a file first");
                    }
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
        // Down goes down and Right goes right: the list steps through the areas, and each area's buttons
        // (which wrap onto several lines) are reached by where they are on screen.
        list->set_as_navigation_container(NavigationType::Vertical);

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
                row->set_as_navigation_container(NavigationType::Auto);
            }
            Button* button = context.create_element<Button>(row, place.name, ButtonStyle::Secondary, ButtonSize::Medium);
            button->add_pressed_callback([place]() {
                if (!tooie::debug::can_warp()) {
                    tooie::toast::show("Start the game and load a file first");
                    return;
                }
                recompui::config::close();
                warp_to(place);
            });
        }
    }
}

void tooie::level_warp::create_tab() {
    recompui::config::create_tab("Warp", tab_id, create_contents);
    show_tab(false);
}

void tooie::level_warp::add_option(recomp::config::Config& dev) {
    dev.add_bool_option(option_id, "Warp Tab",
        "Shows the Warp tab, with the level warp list. F9 repeats the last warp. A dev.txt file next to the game's exe shows it whatever this says.", false);
    dev.add_option_change_callback(option_id,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext) {
            tooie::level_warp::refresh();
        });
}

void tooie::level_warp::start() {
    std::call_once(started, [] {
        std::thread(worker).detach();
    });
}

void tooie::level_warp::refresh() {
    show_tab(debug_tab_on());
}

std::vector<std::string> tooie::level_warp::place_names() {
    std::vector<std::string> names;
    for (const Place& place : places) {
        names.push_back(std::string(place.group) + ": " + place.name);
    }
    return names;
}

bool tooie::level_warp::warp_to_place(size_t index) {
    if (index >= std::size(places)) {
        return false;
    }
    warp_to(places[index]);
    return true;
}
