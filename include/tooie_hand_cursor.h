#ifndef __TOOIE_HAND_CURSOR_H__
#define __TOOIE_HAND_CURSOR_H__

#include <cstdint>
#include <string>
#include <vector>

namespace recomp::config {
    class Config;
}

// The cursor is the save select's pointing hand wherever it shows over the game window (the Start menu,
// the ESC menu, the other menus) (L, 2026-10-24; src/input/hand_cursor.cpp), always.
namespace tooie::hand_cursor {
    // DEV > Stability And Features > 3D Hand Cursor: the game's own hand model and its animations as the
    // cursor, on by default (src/input/hand_model_cursor.cpp); off shows the flat glove.
    inline const std::string model_option = "hand_cursor_3d";

    void add_option(recomp::config::Config& dev);

    // Each pass of the window's event loop (main thread): puts the hand or the system cursor in place.
    void update();

    // The 3D hand's pictures (RGBA, size x size), made from the ROM's model 0x0862 and animations.
    struct ModelFrames {
        int size = 0;
        int hot_x = 0, hot_y = 0;
        float idle_fps = 30.0f, click_fps = 30.0f;
        std::vector<std::vector<uint8_t>> idle;
        std::vector<std::vector<uint8_t>> click;
    };
    // False when the ROM or its assets can't be read.
    bool make_model_frames(int size, ModelFrames& frames);
}

#endif
