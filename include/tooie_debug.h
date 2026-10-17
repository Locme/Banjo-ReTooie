#ifndef __TOOIE_DEBUG_H__
#define __TOOIE_DEBUG_H__

#include <cstdint>
#include <string>

namespace recomp::config {
    class Config;
}

namespace tooie::debug {
    // Walks the game heap once per frame and logs the first damage (src/debug/heap_check.cpp).
    void heap_check(uint8_t* rdram, const char* where);
    // DEV > Heap check, on by default (L, 2026-10-17). TOOIE_HEAP_CHECK=0 turns it off for a run.
    inline const std::string heap_check_option = "heap_check";
    void add_heap_check_option(recomp::config::Config& wip);
    // Reads the saved setting (after the config loads).
    void apply_heap_check();
    // Parses a --pad-script argument (see src/debug/pad_script.cpp).
    bool parse_pad_script(const char* script);
    // Player input with any scripted input added, for the runtime's callbacks.
    bool get_n64_input(int player_index, uint16_t* buttons_out, float* x_out, float* y_out);
    // The right stick set by the pad script's rx=/ry= steps at this moment, if any.
    bool get_scripted_right_stick(float* x_out, float* y_out);
    // Map warps (see src/debug/warp.cpp). The request is issued on the game
    // thread at the start of the next frame.
    // same_map: also when that map is the one loaded now (another entrance of it; the texture sweep).
    void request_warp(uint16_t map, uint8_t exit, bool same_map = false);
    uint16_t current_map(uint8_t* rdram);
    // True while a save file is being played, so a warp can be issued.
    bool can_warp();
    // A warp asked for with request_warp that the game hasn't been told about yet.
    bool warp_pending();
    // The game is changing maps: the go byte stays set from the wipe-out until the new map runs.
    bool map_change_busy(uint8_t* rdram);
}

namespace tooie::dl_dump {
    // Display list dumps (see src/debug/dl_dump.cpp), called after the 3D scene.
    void scene_end(uint8_t* rdram, uint32_t gfx_end);
    // After the frame's 2D (hide_hud.cpp's last mark): appends it to the
    // dump scene_end just wrote, if any.
    void frame_end(uint8_t* rdram, uint32_t from, uint32_t to);
}

#endif
