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
    // F8 cycles a blend mode for finding what blends wrong (0 = normal):
    // 1 no tags (RT64's own matching), 2 tags with vertex blending (off since
    // it tore the sky),
    // 3 camera untagged, 4 models snap (camera still blends).
    int blend_mode();
    const char* blend_mode_name(int mode);
}

#endif
