#ifndef __TOOIE_PATH_TEXT_H__
#define __TOOIE_PATH_TEXT_H__

#include <cstdio>
#include <filesystem>
#include <string>

// Paths as text and C files from paths, for folders named outside the Windows ANSI code page (バンジョー on a
// Western PC). On MSVC path::string() throws for such a name, and fopen() reads a narrow name in that code page.
namespace tooie {
    // The path as UTF-8, for logs, messages and commands.
    inline std::string path_text(const std::filesystem::path& path) {
        const std::u8string text = path.u8string();
        return std::string(text.begin(), text.end());
    }

    // fopen() by path: wide on Windows.
    inline FILE* open_path(const std::filesystem::path& path, const char* mode) {
#ifdef _WIN32
        std::wstring wide_mode(mode, mode + std::char_traits<char>::length(mode));
        return _wfopen(path.c_str(), wide_mode.c_str());
#else
        return std::fopen(path.c_str(), mode);
#endif
    }
}

#endif
