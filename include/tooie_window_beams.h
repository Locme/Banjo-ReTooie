#ifndef __TOOIE_WINDOW_BEAMS_H__
#define __TOOIE_WINDOW_BEAMS_H__

#include <cstdint>
#include <span>
#include <string>
#include <vector>

// Graphics > Window Light Beams (src/gameplay/window_beams.cpp): Bottles' house, Banjo's house and
// King Jingaling's throne room get the see-through beams of light that Mumbo's Skull has under its
// windows, built from the ROM when the room loads.
namespace tooie::window_beams {
    inline const std::string option = "window_light_beams";

    bool enabled();
    // Whether the map is one of the rooms that get beams.
    bool has_beams(uint16_t map);
    // Whether beams are drawn in the map: Mumbo's Skulls (the game's own) always, the rooms that get
    // beams while the option is on. The traced light beams leave these maps alone, so they don't double.
    bool drawn_beams(uint16_t map);

    // Called from the asset loader for every asset it loads: the room's see-through model with the
    // beams when id is one this feature stands in for, else empty. rom_asset gives an asset as the
    // ROM has it, decompressed.
    std::vector<uint8_t> model_for(uint32_t id, std::vector<uint8_t> (*rom_asset)(uint32_t id));

    // The map whose models the game looked up last (the map table hook), for the rooms that have no
    // see-through model of their own.
    void note_map(uint16_t map);

    // The way the light comes in at a beam room's windows (world, towards the light: the beams' fall reversed,
    // averaged over its windows), for the traced light beams. False for any other map.
    bool room_light(uint16_t map, float direction[3]);
}

#endif
