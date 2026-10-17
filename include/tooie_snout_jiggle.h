#ifndef __TOOIE_SNOUT_JIGGLE_H__
#define __TOOIE_SNOUT_JIGGLE_H__

#include <string>

// General > Snout jiggle (src/gameplay/snout_jiggle.cpp): Banjo's snout wobbles on a spring as he
// moves, like Mario's nose in Super Mario Odyssey. Works with player-model mods that keep his
// skeleton (Smash Banjo). The sliders under it shape the wobble.
namespace tooie::snout_jiggle {
    inline const std::string option = "snout_jiggle";
    inline const std::string kazooie_option = "kazooie_jiggle";               // her crest and tail feathers
    inline const std::string strength_option = "snout_jiggle_strength";       // % of the default swing
    inline const std::string bounce_option = "snout_jiggle_bounce";           // 0 stiff .. 100 wobbles for ages
    inline const std::string speed_option = "snout_jiggle_speed";             // wobbles a second
    inline const std::string exaggeration_option = "snout_jiggle_exaggeration"; // % of the largest swing
    inline const std::string stretch_option = "snout_jiggle_stretch";         // % squash and stretch
    inline const std::string size_option = "snout_jiggle_size";               // % snout size
    inline const std::string reach_option = "snout_jiggle_reach";             // vanilla model: how far back it bends
}

#endif
