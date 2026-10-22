#ifndef __TOOIE_SUN_CONTROL_H__
#define __TOOIE_SUN_CONTROL_H__

#include <cstdint>

// Moving the sun by hand (L, 2026-10-22), for picking where each level's sun stands under ray tracing. Hold the
// Move Sun key (Controls > Ray Trace Debug) and turn the mouse wheel: the wheel turns the sun round the compass, Ctrl
// + wheel raises or lowers it, Shift for fine steps. Save Sun Location writes the map's sun to sun.txt in the Dev
// Files folder, which is read back at start, so L can send it in for the level's built-in sun.
namespace tooie::sun_control {
    // Call once per game frame from day_night::tick with the current map. True when the map's sun changed this frame
    // (moved by hand), so it is sent again. start is the sun the level shows now (a unit vector towards it), where
    // the first move starts from.
    bool tick(uint16_t map, const float start[3]);
    // The sun moved by hand or saved in sun.txt for the map: a unit vector towards it in the world. False when the
    // map has neither (the level keeps its built-in sun).
    bool map_sun(uint16_t map, float out[3]);
}

#endif
