// Graphics API restart. RT64 chooses D3D12 or Vulkan when its renderer is created, and the menus are
// drawn by that renderer, so the API cannot change while the game runs. Instead a new choice asks
// "Restart now?"; confirming quits the game the normal way (as Quit does) and main() then starts the
// same executable again with the same arguments, which reads the choice the Graphics tab saved.
// Headless: TOOIE_API_RESTART_CONFIRM=1 confirms the prompt by itself; "[api-restart]" lines log it.

#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <variant>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "ultramodern/ultramodern.hpp"
#include "recompui/config.h"
#include "recompui/recompui.h"

#include "tooie_api_restart.h"

namespace {
    std::atomic_bool restart_requested = false;
    // The API the renderer started with, from the saved settings.
    recomp::config::ConfigValueVariant running_api;

    void restart_now() {
        std::printf("[api-restart] restarting\n");
        std::fflush(stdout);
        restart_requested = true;
        ultramodern::quit();
    }
}

void tooie::api_restart::add_prompt(recomp::config::Config& graphics) {
    graphics.add_option_change_callback(recompui::config::graphics::options::api_option,
        [](recomp::config::ConfigValueVariant cur_value, recomp::config::ConfigValueVariant prev_value,
           recomp::config::OptionChangeContext change_context) {
            if (change_context == recomp::config::OptionChangeContext::Load) {
                running_api = cur_value;
                return;
            }
            // The menu changes options as Temporary; saving them then reports the same change
            // again as Permanent, which must not ask a second time.
            if (change_context != recomp::config::OptionChangeContext::Temporary || cur_value == prev_value) {
                return;
            }
            // This callback replaces the Graphics tab's own one (an option has one), which saved
            // the change; save it here so the restarted game reads it.
            recompui::config::get_graphics_config().save_config();
            // Switching back to the API in use needs no restart.
            if (cur_value == running_api) {
                std::printf("[api-restart] back to the running API\n");
                std::fflush(stdout);
                return;
            }
            std::printf("[api-restart] prompt\n");
            std::fflush(stdout);
            if (const char* confirm = std::getenv("TOOIE_API_RESTART_CONFIRM"); confirm != nullptr && confirm[0] == '1') {
                restart_now();
                return;
            }
            recompui::open_choice_prompt(
                "Restart now?",
                "The new graphics API takes effect after a restart. Any progress since your last save will be lost.",
                "Restart",
                "Later",
                restart_now,
                []() {},
                recompui::ButtonStyle::Success,
                recompui::ButtonStyle::Tertiary,
                true);
        });
}

void tooie::api_restart::relaunch_if_requested(int argc, char** argv) {
    if (!restart_requested) {
        return;
    }
#ifdef _WIN32
    (void)argc;
    (void)argv;
    wchar_t exe[MAX_PATH];
    DWORD length = GetModuleFileNameW(nullptr, exe, MAX_PATH);
    if (length == 0 || length == MAX_PATH) {
        return;
    }
    std::wstring command_line = GetCommandLineW();
    std::vector<wchar_t> command(command_line.begin(), command_line.end());
    command.push_back(L'\0');
    STARTUPINFOW startup{};
    startup.cb = sizeof(startup);
    PROCESS_INFORMATION process{};
    if (CreateProcessW(exe, command.data(), nullptr, nullptr, FALSE, 0, nullptr, nullptr, &startup, &process)) {
        CloseHandle(process.hThread);
        CloseHandle(process.hProcess);
    }
#else
    (void)argc;
    std::fflush(stdout);
    std::fflush(stderr);
    // The real path, not /proc/self/exe, so the process keeps its name.
    std::error_code ec;
    std::filesystem::path exe = std::filesystem::read_symlink("/proc/self/exe", ec);
    if (ec) {
        exe = "/proc/self/exe";
    }
    execv(exe.c_str(), argv);
    std::printf("[api-restart] could not start again\n");
#endif
}
