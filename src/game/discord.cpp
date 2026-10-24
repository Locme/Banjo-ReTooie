#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <mutex>
#include <string>
#include <thread>
#include <variant>

#ifdef _WIN32
#include <Windows.h>
#else
#include <poll.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#endif

#include "recompui/config.h"

#include "tooie_debug.h"
#include "tooie_discord.h"
#include "tooie_game.h"

namespace {
    using namespace std::chrono_literals;

    // The "Banjo-Tooie" Discord application L made (https://discord.com/developers/applications,
    // 2026-10-17); its name is what Discord shows as "Playing ...". The id is public, not a secret.
    constexpr const char* discord_client_id = "1561009623530741832";

    constexpr auto poll_interval = 1s;      // how often the map is looked at
    constexpr auto min_update_gap = 4s;     // Discord rate-limits activity updates
    constexpr auto reconnect_gap = 15s;     // between attempts when Discord isn't running

    struct MapName {
        uint16_t id;
        const char* name;
    };

    constexpr MapName map_names[] = {
#include "map_names.inc"
    };

    // Prefix the community list puts before a level's areas, spelled out.
    struct Prefix {
        const char* code;
        const char* world;
    };
    constexpr Prefix prefixes[] = {
        { "SM", "Spiral Mountain" },
        { "MT", "Mayahem Temple" },
        { "GGM", "Glitter Gulch Mine" },
        { "WW", "Witchyworld" },
        { "JRL", "Jolly Roger's Lagoon" },
        { "TDL", "Terrydactyland" },
        { "GI", "Grunty Industries" },
        { "HFP", "Hailfire Peaks" },
        { "CCL", "Cloud Cuckooland" },
        { "IoH", "Isle O' Hags" },
        { "JV", "Jinjo Village" },
        { "CK", "Cauldron Keep" },
    };

    std::once_flag start_once;

    // Level and area for a map id: "Mayahem Temple" / "Prospector's Hut".
    void describe_map(uint16_t id, std::string& details, std::string& state) {
        const char* name = nullptr;
        for (const MapName& m : map_names) {
            if (m.id == id) {
                name = m.name;
                break;
            }
        }
        if (name == nullptr) {
            details = "Banjo Re-Tooie";
            state.clear();
            return;
        }
        std::string full = name;
        size_t sep = full.find(" - ");
        if (sep == std::string::npos) {
            details = full;
            state.clear();
            return;
        }
        std::string code = full.substr(0, sep);
        std::string area = full.substr(sep + 3);
        for (const Prefix& p : prefixes) {
            if (code == p.code) {
                details = p.world;
                state = area == details ? "" : area;
                return;
            }
        }
        // Cutscenes and the menus.
        details = (code == "Cutscene") ? "Watching a cutscene" : full;
        state = (code == "Cutscene") ? area : "";
    }

    std::string json_escape(const std::string& s) {
        std::string out;
        for (char c : s) {
            if (c == '"' || c == '\\') {
                out += '\\';
                out += c;
            } else if (static_cast<unsigned char>(c) < 0x20) {
                out += ' ';
            } else {
                out += c;
            }
        }
        return out;
    }

    bool presence_enabled() {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::discord::presence_option));
        } catch (...) {
            return false;
        }
    }

    // One connection to the Discord client. Frames are u32 op, u32 length (little endian), then JSON.
    class Connection {
    public:
        ~Connection() { close_pipe(); }

        bool is_open() const { return open_flag; }

        bool connect() {
            for (int i = 0; i < 10; i++) {
                if (try_open(i)) {
                    open_flag = true;
                    return true;
                }
            }
            return false;
        }

        void close_pipe() {
            if (!open_flag) {
                return;
            }
#ifdef _WIN32
            CloseHandle(handle);
            handle = INVALID_HANDLE_VALUE;
#else
            ::close(fd);
            fd = -1;
#endif
            open_flag = false;
        }

        bool send_frame(uint32_t op, const std::string& json) {
            std::string frame(8, '\0');
            uint32_t len = static_cast<uint32_t>(json.size());
            for (int i = 0; i < 4; i++) {
                frame[i] = static_cast<char>((op >> (8 * i)) & 0xFF);
                frame[4 + i] = static_cast<char>((len >> (8 * i)) & 0xFF);
            }
            frame += json;
            return write_all(frame.data(), frame.size());
        }

        // Reads one frame, waiting up to timeout. Returns false on error or timeout.
        bool read_frame(uint32_t& op, std::string& json, std::chrono::milliseconds timeout) {
            unsigned char header[8];
            if (!read_all(reinterpret_cast<char*>(header), 8, timeout)) {
                return false;
            }
            op = header[0] | (header[1] << 8) | (header[2] << 16) | (static_cast<uint32_t>(header[3]) << 24);
            uint32_t len = header[4] | (header[5] << 8) | (header[6] << 16) | (static_cast<uint32_t>(header[7]) << 24);
            if (len > 64 * 1024) {
                return false;
            }
            json.assign(len, '\0');
            return len == 0 || read_all(json.data(), len, timeout);
        }

    private:
        bool open_flag = false;
#ifdef _WIN32
        HANDLE handle = INVALID_HANDLE_VALUE;

        bool try_open(int index) {
            std::string path = "\\\\.\\pipe\\discord-ipc-" + std::to_string(index);
            handle = CreateFileA(path.c_str(), GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
            return handle != INVALID_HANDLE_VALUE;
        }

        bool write_all(const char* data, size_t size) {
            DWORD written = 0;
            return WriteFile(handle, data, static_cast<DWORD>(size), &written, nullptr) && written == size;
        }

        bool read_all(char* out, size_t size, std::chrono::milliseconds timeout) {
            auto deadline = std::chrono::steady_clock::now() + timeout;
            size_t got = 0;
            while (got < size) {
                DWORD available = 0;
                if (!PeekNamedPipe(handle, nullptr, 0, nullptr, &available, nullptr)) {
                    return false;
                }
                if (available == 0) {
                    if (std::chrono::steady_clock::now() > deadline) {
                        return false;
                    }
                    std::this_thread::sleep_for(20ms);
                    continue;
                }
                DWORD read = 0;
                DWORD want = static_cast<DWORD>(std::min<size_t>(available, size - got));
                if (!ReadFile(handle, out + got, want, &read, nullptr) || read == 0) {
                    return false;
                }
                got += read;
            }
            return true;
        }
#else
        int fd = -1;

        bool try_open(int index) {
            // Discord puts the socket in the runtime dir, directly or under its Flatpak/Snap folders.
            const char* bases[] = { std::getenv("XDG_RUNTIME_DIR"), std::getenv("TMPDIR"), std::getenv("TMP"), std::getenv("TEMP"), "/tmp" };
            const char* subs[] = { "", "/app/com.discordapp.Discord", "/snap.discord" };
            for (const char* base : bases) {
                if (base == nullptr || *base == '\0') {
                    continue;
                }
                for (const char* sub : subs) {
                    std::string path = std::string(base) + sub + "/discord-ipc-" + std::to_string(index);
                    sockaddr_un addr{};
                    addr.sun_family = AF_UNIX;
                    if (path.size() >= sizeof(addr.sun_path)) {
                        continue;
                    }
                    std::strcpy(addr.sun_path, path.c_str());
                    int s = ::socket(AF_UNIX, SOCK_STREAM, 0);
                    if (s < 0) {
                        continue;
                    }
                    if (::connect(s, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == 0) {
                        fd = s;
                        return true;
                    }
                    ::close(s);
                }
            }
            return false;
        }

        bool write_all(const char* data, size_t size) {
            size_t sent = 0;
            while (sent < size) {
                ssize_t n = ::send(fd, data + sent, size - sent, MSG_NOSIGNAL);
                if (n <= 0) {
                    return false;
                }
                sent += static_cast<size_t>(n);
            }
            return true;
        }

        bool read_all(char* out, size_t size, std::chrono::milliseconds timeout) {
            auto deadline = std::chrono::steady_clock::now() + timeout;
            size_t got = 0;
            while (got < size) {
                auto left = std::chrono::duration_cast<std::chrono::milliseconds>(deadline - std::chrono::steady_clock::now());
                if (left.count() <= 0) {
                    return false;
                }
                pollfd p{ fd, POLLIN, 0 };
                if (::poll(&p, 1, static_cast<int>(left.count())) <= 0) {
                    return false;
                }
                ssize_t n = ::recv(fd, out + got, size - got, 0);
                if (n <= 0) {
                    return false;
                }
                got += static_cast<size_t>(n);
            }
            return true;
        }
#endif
    };

    uint32_t process_id() {
#ifdef _WIN32
        return static_cast<uint32_t>(GetCurrentProcessId());
#else
        return static_cast<uint32_t>(getpid());
#endif
    }

    bool handshake(Connection& conn) {
        std::string hello = std::string("{\"v\":1,\"client_id\":\"") + discord_client_id + "\"}";
        uint32_t op = 0;
        std::string reply;
        // The client answers the handshake with a READY event.
        return conn.send_frame(0, hello) && conn.read_frame(op, reply, 3s) && op != 2;
    }

    int nonce_counter = 0;

    bool set_activity(Connection& conn, const std::string* details, const std::string* state, int64_t start_time) {
        std::string payload = "{\"cmd\":\"SET_ACTIVITY\",\"nonce\":\"" + std::to_string(++nonce_counter) + "\",\"args\":{\"pid\":" + std::to_string(process_id());
        if (details != nullptr) {
            payload += ",\"activity\":{\"details\":\"" + json_escape(*details) + "\"";
            if (state != nullptr && !state->empty()) {
                payload += ",\"state\":\"" + json_escape(*state) + "\"";
            }
            payload += ",\"timestamps\":{\"start\":" + std::to_string(start_time) + "}}";
        }
        payload += "}}";
        if (!conn.send_frame(1, payload)) {
            return false;
        }
        uint32_t op = 0;
        std::string reply;
        // Drain the answer so the pipe never fills; a close (op 2) means Discord went away.
        if (conn.read_frame(op, reply, 2s)) {
            return op != 2;
        }
        return true;
    }

    void presence_loop(uint8_t* rdram) {
        Connection conn;
        auto next_connect = std::chrono::steady_clock::now();
        auto last_update = std::chrono::steady_clock::time_point{};
        uint32_t shown_map = UINT32_MAX;
        bool showing = false;
        const int64_t start_time = static_cast<int64_t>(std::time(nullptr));

        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            auto now = std::chrono::steady_clock::now();
            const bool want = presence_enabled();

            if (!want) {
                if (showing && conn.is_open()) {
                    set_activity(conn, nullptr, nullptr, 0);
                }
                showing = false;
                shown_map = UINT32_MAX;
                conn.close_pipe();
                continue;
            }

            if (!conn.is_open()) {
                if (now < next_connect) {
                    continue;
                }
                next_connect = now + reconnect_gap;
                if (!conn.connect()) {
                    continue;
                }
                if (!handshake(conn)) {
                    conn.close_pipe();
                    continue;
                }
                shown_map = UINT32_MAX;
            }

            uint16_t map = tooie::debug::current_map(rdram);
            if (map == shown_map || now - last_update < min_update_gap) {
                continue;
            }
            std::string details, state;
            describe_map(map, details, state);
            if (!set_activity(conn, &details, &state, start_time)) {
                conn.close_pipe();
                showing = false;
                continue;
            }
            shown_map = map;
            showing = true;
            last_update = now;
        }
    }
}

void tooie::discord::start(uint8_t* rdram) {
    if (*discord_client_id == '\0') {
        return;
    }
    std::call_once(start_once, [rdram] {
        // Detached: it only talks to a local pipe, so it can die with the process.
        std::thread(presence_loop, rdram).detach();
    });
}
