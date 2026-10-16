// Headless controller presses for the menus: TOOIE_MENU_PAD="<ms>:<button>[:<hold ms>];<ms>:..."
// pushes SDL controller button events at those times after the game started, so menu
// navigation with a pad (Back, Start, the d-pad) can be tested without a controller.
// --pad-script only feeds the game's own input, which the menus never read.
// Buttons: a b x y back start l r du dd dl dr. Each press is logged as "[menu-pad] ...".
// TOOIE_MENU_PAD_FILE=<path>: presses the buttons written to that file (one per line) as soon as
// they appear, then empties it, for driving the menus step by step alongside xdotool.

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "SDL.h"

#include "tooie_game.h"

namespace {
    struct Press {
        long ms = 0;
        long hold_ms = 150;
        int button = SDL_CONTROLLER_BUTTON_INVALID;
        std::string name;
    };

    int button_from_name(const std::string &name) {
        static const struct { const char *name; int button; } buttons[] = {
            { "a", SDL_CONTROLLER_BUTTON_A }, { "b", SDL_CONTROLLER_BUTTON_B },
            { "x", SDL_CONTROLLER_BUTTON_X }, { "y", SDL_CONTROLLER_BUTTON_Y },
            { "back", SDL_CONTROLLER_BUTTON_BACK }, { "start", SDL_CONTROLLER_BUTTON_START },
            { "l", SDL_CONTROLLER_BUTTON_LEFTSHOULDER }, { "r", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER },
            { "du", SDL_CONTROLLER_BUTTON_DPAD_UP }, { "dd", SDL_CONTROLLER_BUTTON_DPAD_DOWN },
            { "dl", SDL_CONTROLLER_BUTTON_DPAD_LEFT }, { "dr", SDL_CONTROLLER_BUTTON_DPAD_RIGHT },
        };
        for (const auto &b : buttons) {
            if (name == b.name) {
                return b.button;
            }
        }
        return SDL_CONTROLLER_BUTTON_INVALID;
    }

    std::vector<Press> parse(const char *text) {
        std::vector<Press> presses;
        std::stringstream steps{ text };
        std::string step;
        while (std::getline(steps, step, ';')) {
            std::stringstream fields{ step };
            std::string ms, name, hold;
            if (!std::getline(fields, ms, ':') || !std::getline(fields, name, ':')) {
                continue;
            }
            Press p;
            p.ms = std::strtol(ms.c_str(), nullptr, 10);
            p.name = name;
            p.button = button_from_name(name);
            if (std::getline(fields, hold, ':')) {
                p.hold_ms = std::strtol(hold.c_str(), nullptr, 10);
            }
            if (p.button != SDL_CONTROLLER_BUTTON_INVALID) {
                presses.push_back(p);
            } else {
                std::printf("[menu-pad] unknown button '%s'\n", name.c_str());
            }
        }
        return presses;
    }

    void push(int button, bool down) {
        SDL_Event event{};
        event.type = down ? SDL_CONTROLLERBUTTONDOWN : SDL_CONTROLLERBUTTONUP;
        event.cbutton.type = event.type;
        event.cbutton.timestamp = SDL_GetTicks();
        event.cbutton.which = 0;
        event.cbutton.button = (Uint8)button;
        event.cbutton.state = down ? SDL_PRESSED : SDL_RELEASED;
        SDL_PushEvent(&event);
    }
}

void tooie::start_menu_pad_script() {
    static std::once_flag once;
    std::call_once(once, [] {
        if (const char *file = std::getenv("TOOIE_MENU_PAD_FILE")) {
            std::thread([path = std::string(file)] {
                while (true) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    std::vector<std::string> names;
                    {
                        std::ifstream in(path);
                        std::string line;
                        while (std::getline(in, line)) {
                            if (!line.empty()) {
                                names.push_back(line);
                            }
                        }
                    }
                    if (names.empty()) {
                        continue;
                    }
                    std::ofstream(path, std::ios::trunc);
                    for (const std::string &name : names) {
                        int button = button_from_name(name);
                        if (button == SDL_CONTROLLER_BUTTON_INVALID) {
                            std::printf("[menu-pad] unknown button '%s'\n", name.c_str());
                            continue;
                        }
                        push(button, true);
                        std::printf("[menu-pad] %s\n", name.c_str());
                        std::fflush(stdout);
                        std::this_thread::sleep_for(std::chrono::milliseconds(150));
                        push(button, false);
                        std::this_thread::sleep_for(std::chrono::milliseconds(150));
                    }
                }
            }).detach();
        }
        const char *text = std::getenv("TOOIE_MENU_PAD");
        if (text == nullptr) {
            return;
        }
        std::thread([presses = parse(text)] {
            auto begin = std::chrono::steady_clock::now();
            for (const Press &p : presses) {
                std::this_thread::sleep_until(begin + std::chrono::milliseconds(p.ms));
                push(p.button, true);
                std::printf("[menu-pad] %ld ms: %s\n", p.ms, p.name.c_str());
                std::fflush(stdout);
                std::this_thread::sleep_for(std::chrono::milliseconds(p.hold_ms));
                push(p.button, false);
            }
        }).detach();
    });
}
