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
#include "tooie_upscaler.h"

namespace {
    std::atomic_bool restart_requested = false;
    // The working directory the game was started in. The menus load their files (assets/) from it,
    // and a file dialog can move it while the game runs, so the restarted game is given this one.
    std::filesystem::path launch_dir;
    // The API the renderer started with, from the saved settings.
    recomp::config::ConfigValueVariant running_api;

    void restart_now() {
        std::printf("[api-restart] restarting\n");
        std::fflush(stdout);
        restart_requested = true;
        ultramodern::quit();
    }
}

namespace {
    std::filesystem::path exe_path() {
#ifdef _WIN32
        wchar_t exe[MAX_PATH];
        DWORD length = GetModuleFileNameW(nullptr, exe, MAX_PATH);
        if (length == 0 || length == MAX_PATH) {
            return {};
        }
        return std::filesystem::path{ exe };
#else
        std::error_code ec;
        std::filesystem::path exe = std::filesystem::read_symlink("/proc/self/exe", ec);
        return ec ? std::filesystem::path{} : exe;
#endif
    }
}

void tooie::api_restart::remember_launch_dir() {
    // The menus' files (assets/recomp.rcss and the rest) are opened relative to the working
    // directory, and a missing one aborts at startup ("string too long" in init_styling). When
    // the game is started from another folder (a shortcut, a script), use the executable's.
    std::error_code ec;
    if (!std::filesystem::exists("assets", ec)) {
        std::filesystem::path exe_dir = exe_path().parent_path();
        if (!exe_dir.empty() && std::filesystem::exists(exe_dir / "assets", ec)) {
            std::filesystem::current_path(exe_dir, ec);
        }
    }
    launch_dir = std::filesystem::current_path(ec);
}

void tooie::api_restart::add_prompt(recomp::config::Config& graphics) {
    graphics.add_option_change_callback(recompui::config::graphics::options::api_option,
        [](recomp::config::ConfigValueVariant cur_value, recomp::config::ConfigValueVariant prev_value,
           recomp::config::OptionChangeContext change_context) {
            if (change_context == recomp::config::OptionChangeContext::Load) {
                // The upscaler goes by the API the renderer runs with, the loaded one: a new choice only takes
                // effect after the restart, and "Later" keeps this session on the old API.
                if (const uint32_t* api = std::get_if<uint32_t>(&cur_value)) {
                    tooie::upscaler::api_changed(*api);
                }
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
    std::filesystem::path exe = exe_path();
    if (exe.empty()) {
        return;
    }
    std::wstring command_line = GetCommandLineW();
    std::vector<wchar_t> command(command_line.begin(), command_line.end());
    command.push_back(L'\0');
    STARTUPINFOW startup{};
    startup.cb = sizeof(startup);
    PROCESS_INFORMATION process{};
    const wchar_t* dir = launch_dir.empty() ? nullptr : launch_dir.c_str();
    if (CreateProcessW(exe.c_str(), command.data(), nullptr, nullptr, FALSE, 0, nullptr, dir, &startup, &process)) {
        CloseHandle(process.hThread);
        CloseHandle(process.hProcess);
    }
#elif defined(__ANDROID__)
    // The Android build only has Vulkan, so no restart is ever asked for.
    (void)argc;
    (void)argv;
#else
    (void)argc;
    std::fflush(stdout);
    std::fflush(stderr);
    std::error_code ec;
    if (!launch_dir.empty()) {
        std::filesystem::current_path(launch_dir, ec);
    }
    // The real path, not /proc/self/exe, so the process keeps its name.
    std::filesystem::path exe = exe_path();
    if (exe.empty()) {
        exe = "/proc/self/exe";
    }
    execv(exe.c_str(), argv);
    std::printf("[api-restart] could not start again\n");
#endif
}

// A new copy of the game, started now with the same command line and folder; this one carries on
// (the texture sweep's pass-over starts one from the crash handler and the watchdog, then ends).
bool tooie::api_restart::start_copy() {
#ifdef _WIN32
    std::filesystem::path exe = exe_path();
    if (exe.empty()) {
        return false;
    }
    std::wstring command_line = GetCommandLineW();
    std::vector<wchar_t> command(command_line.begin(), command_line.end());
    command.push_back(L'\0');
    STARTUPINFOW startup{};
    startup.cb = sizeof(startup);
    PROCESS_INFORMATION process{};
    const wchar_t* dir = launch_dir.empty() ? nullptr : launch_dir.c_str();
    if (!CreateProcessW(exe.c_str(), command.data(), nullptr, nullptr, FALSE, 0, nullptr, dir, &startup, &process)) {
        return false;
    }
    CloseHandle(process.hThread);
    CloseHandle(process.hProcess);
    return true;
#elif defined(__ANDROID__)
    return false;
#else
    std::filesystem::path exe = exe_path();
    if (exe.empty()) {
        return false;
    }
    // The arguments as this process got them.
    std::vector<std::string> args;
    {
        FILE* f = std::fopen("/proc/self/cmdline", "rb");
        if (f == nullptr) {
            return false;
        }
        std::string arg;
        int c;
        while ((c = std::fgetc(f)) != EOF) {
            if (c == 0) {
                args.push_back(arg);
                arg.clear();
            } else {
                arg.push_back((char)c);
            }
        }
        std::fclose(f);
    }
    std::vector<char*> argv;
    for (std::string& a : args) {
        argv.push_back(a.data());
    }
    argv.push_back(nullptr);
    const std::string dir = launch_dir.string();
    pid_t pid = fork();
    if (pid == 0) {
        if (!dir.empty() && chdir(dir.c_str()) != 0) {
            _exit(127);
        }
        execv(exe.c_str(), argv.data());
        _exit(127);
    }
    return pid > 0;
#endif
}
