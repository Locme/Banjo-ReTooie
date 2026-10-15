#ifndef __TOOIE_MORE_MEMORY_H__
#define __TOOIE_MORE_MEMORY_H__

#include <string>

// More game memory (src/game/more_memory.cpp, DEV tab): a bigger game heap, bigger per-frame display list,
// matrix and vertex buffers, and bigger animation caches (banjotooie.us.toml), so crowded scenes
// do not crash. The generated code asks tooie_more_memory() (tooie_hooks.h) which values to use.
namespace tooie::more_memory {
    inline const std::string option = "more_game_memory";
}

#endif
