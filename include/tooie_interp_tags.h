#ifndef __TOOIE_INTERP_TAGS_H__
#define __TOOIE_INTERP_TAGS_H__

// Manual interpolation tags (src/debug/interp_tags.cpp): a model picked in
// the game (the Pick Model key) gets its own blend between game frames (the
// Tag Model key), kept in interp_tags.txt next to the save files, with the
// built-in defaults in the same file's format. model_tagging.cpp names the
// models (a hash of a model's display list, the same in every run) and
// applies the tags.
#include <cstdint>
#include <string>

namespace tooie::interp_tags {
    // What a tagged model does between game frames.
    enum Mode : int {
        mode_default = 0,  // as every other model
        mode_snap = 1,     // drawn at the game's own rate (no blend)
        mode_vertex = 2,   // its vertex positions blend too
        mode_untagged = 3, // left to RT64's own matching
        mode_count = 4
    };
    const char* mode_name(int mode);

    // Starts watching the keys and loads interp_tags.txt (once).
    void start();
    // The tag of a model, mode_default when it has none.
    int mode_of(uint32_t model);
    bool any();

    // The keys, read by the tagger once per scene: the Pick Model key was
    // pressed (steps to the next model on screen), the Tag Model key was
    // pressed (steps the picked model's tag).
    bool take_pick();
    bool take_tag();
    // The picked model (0 = none) and its setter; the tagger highlights it.
    uint32_t picked();
    void set_picked(uint32_t model, const std::string& note);
    // Steps the picked model's tag and saves the file. Returns the new mode.
    int step_picked();
}

#endif
