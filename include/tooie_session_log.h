#ifndef __TOOIE_SESSION_LOG_H__
#define __TOOIE_SESSION_LOG_H__

#include <string>

// What a crash report needs besides the stack (src/debug/session_log.cpp): the build and the
// settings in effect. Printed to the console (logs/console.log on Windows) at start and whenever
// a setting changes, and handed to the crash handler so every crashes.log entry carries it.
namespace tooie::session_log {
    // Call once the settings are loaded. version is the program version string.
    void start(const std::string& version);
}

#endif
