#ifndef __TOOIE_INTERP_CHECK_H__
#define __TOOIE_INTERP_CHECK_H__

// Interpolation check (src/debug/interp_check.cpp): F7 turns on a debug view
// that tints models red for a moment when their blend between frames looks
// wrong, and logs each one ([interp-check] lines in logs/console.log).
// model_tagging.cpp does the checking.
namespace tooie::interp_check {
    // Starts watching the key (once).
    void start();
    bool enabled();
}

#endif
