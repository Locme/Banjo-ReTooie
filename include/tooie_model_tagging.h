#ifndef __TOOIE_MODEL_TAGGING_H__
#define __TOOIE_MODEL_TAGGING_H__

#include <cstdint>

// Stable matrix ids for frame interpolation (src/game/model_tagging.cpp).
namespace tooie::model_tagging {
    // Where func_800A73F4 started writing this frame's display list (physical).
    uint32_t scene_start();
    // Tags the model matrices of the 3D scene between start and end (physical
    // addresses). Returns how many bytes it appended at end.
    uint32_t tag_scene(uint8_t* rdram, uint32_t start, uint32_t end);
}

#endif
