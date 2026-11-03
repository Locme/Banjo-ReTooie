#ifndef __TOOIE_CIRCLE_SHADOW_H__
#define __TOOIE_CIRCLE_SHADOW_H__

#include <string>

// Graphics > Demake > Simple Circle Shadow (src/gameplay/circle_shadow.cpp): the player gets the game's
// own round blob shadow instead of the flattened model.
namespace tooie::circle_shadow {
    inline const std::string option = "circle_shadow";
    bool enabled();
}

#endif
