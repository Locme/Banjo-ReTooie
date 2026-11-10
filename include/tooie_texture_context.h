#ifndef __TOOIE_TEXTURE_CONTEXT_H__
#define __TOOIE_TEXTURE_CONTEXT_H__

#include <cstdint>

// What a dumped texture belongs to (src/game/texture_context.cpp), for sorting a texture dump into Levels, Characters,
// HUD, FX and the rest (tools/organize_textures.py).
namespace tooie::texture_context {
    // Once per game frame from the game thread: where the game's memory is.
    void tick(uint8_t* rdram);
    // At the end of each frame (hide_hud.cpp): the frame's 2D part of the display list, physical addresses.
    void note_2d(uint32_t start, uint32_t end);
    // When the game looks up a map's entry in its map table (window_beams.cpp's hook): the map's solid and
    // see-through models, so their textures count as the map's own.
    void note_map_models(uint16_t map, uint16_t solid, uint16_t see_through);

    struct Context {
        bool drawn_2d = false;       // its load was in the frame's own 2D part (the HUD, menus, text)
        int32_t asset = -1;          // the loaded asset the texture sits in, or -1 (not in an asset)
        int32_t asset_kind = -1;     // that asset's kind in the ROM's table (0 a model)
        uint32_t asset_offset = 0;   // where in the asset
        int32_t level_of = -1;       // the map whose solid or see-through model the asset is, or -1
    };
    // For a texture RT64 loaded from this physical address by the display-list command at dl_command (physical, 0
    // when unknown). Called on RT64's thread; reads the game's asset table as it is now.
    Context classify(uint32_t texture_address, uint32_t dl_command);
}

#endif
