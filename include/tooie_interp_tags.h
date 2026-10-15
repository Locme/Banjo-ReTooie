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
    bool take_save();
    bool take_unsave();
    // The Model Effects key was pressed (turns the picked model's screen effects off or on).
    bool take_effects();
    // Models drawn without the screen effects (RT64 draws them after the effects pass).
    bool any_no_effects();
    bool no_effects_for(uint32_t model);
    // Turns the picked model's screen effects off or on (in memory; Save Tags writes the file).
    // Returns true when they are now off.
    bool toggle_picked_effects();
    // Writes interp_tags.txt. Returns how many tags it holds.
    size_t save();
    // Removes the picked model's tag from the game and the file.
    void unsave_picked();
    // "snap, saved", "snap, not saved yet", "default (saved as snap)" or "default".
    std::string describe(uint32_t model);
    // The picked model (0 = none) and its setter; the tagger highlights it.
    uint32_t picked();
    void set_picked(uint32_t model, const std::string& note);
    // Steps the picked model's tag (in memory; the Save Tags key writes the file). Returns the new mode.
    int step_picked();
}

#endif
