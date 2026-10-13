#ifndef __TOOIE_DISCORD_H__
#define __TOOIE_DISCORD_H__

#include <cstdint>
#include <string>

// Discord Rich Presence (src/game/discord.cpp): shows the level being played. It talks to the
// Discord client over its local IPC pipe and quietly does nothing when Discord isn't running.
namespace tooie::discord {
    inline const std::string presence_option = "discord_presence";

    // Starts the presence thread (safe to call more than once). Call once the game's RDRAM exists.
    void start(uint8_t* rdram);
}

#endif
