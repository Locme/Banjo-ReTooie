#ifndef __TOOIE_HONEYCOMB_CAP_H__
#define __TOOIE_HONEYCOMB_CAP_H__

#include <string>

// WIP tab > Honeycombs Stay (src/gameplay/honeycomb_cap.cpp, WIP): the health honeycombs that enemies
// and breakables drop no longer vanish after 20 seconds. The game's own limit of 10 dropped combs (the oldest goes) stays.
namespace tooie::honeycomb_cap {
    inline const std::string option = "honeycombs_stay";
}

#endif
