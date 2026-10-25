#ifndef __TOOIE_HONEYCOMB_CAP_H__
#define __TOOIE_HONEYCOMB_CAP_H__

#include <string>

// WIP tab > Honeycombs Stay (src/gameplay/honeycomb_cap.cpp, WIP): the health honeycombs that enemies
// and breakables drop no longer vanish after 20 seconds. At most as many as Banjo's full health lie about at once;
// when another drops, the oldest goes (the game's own rule, with its limit of 10 moved to the full health).
namespace tooie::honeycomb_cap {
    inline const std::string option = "honeycombs_stay";
}

#endif
