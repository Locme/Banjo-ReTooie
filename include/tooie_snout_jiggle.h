#ifndef __TOOIE_SNOUT_JIGGLE_H__
#define __TOOIE_SNOUT_JIGGLE_H__

#include <string>

// General > Snout jiggle (src/gameplay/snout_jiggle.cpp): Banjo's snout wobbles on a spring as he
// moves, like Mario's nose in Super Mario Odyssey. Works with player-model mods that keep his
// skeleton (Smash Banjo). The sliders under it shape the wobble.
#include <cstdint>

namespace tooie::snout_jiggle {
    // Whether the model whose first display list is at this physical address has vertices this file
    // rewrites each frame (the muzzle and jaw), so frame interpolation should blend them too
    // (src/game/model_tagging.cpp); otherwise they move only at the game's frame rate and stutter.
    bool blend_vertices(uint32_t first_list_phys);

    inline const std::string option = "snout_jiggle";
    inline const std::string kazooie_option = "kazooie_jiggle";               // her crest and tail feathers
    inline const std::string kazooie_strength_option = "kazooie_jiggle_strength";
    inline const std::string kazooie_bounce_option = "kazooie_jiggle_bounce";
    inline const std::string kazooie_speed_option = "kazooie_jiggle_speed";
    inline const std::string kazooie_exaggeration_option = "kazooie_jiggle_exaggeration";
    inline const std::string strength_option = "snout_jiggle_strength";       // % of the default swing
    inline const std::string bounce_option = "snout_jiggle_bounce";           // 0 stiff .. 100 wobbles for ages
    inline const std::string speed_option = "snout_jiggle_speed";             // wobbles a second
    inline const std::string exaggeration_option = "snout_jiggle_exaggeration"; // % of the largest swing
    inline const std::string stretch_option = "snout_jiggle_stretch";         // % squash and stretch
    inline const std::string size_option = "snout_jiggle_size";               // % snout size
    inline const std::string reach_option = "snout_jiggle_reach";             // vanilla model: how far back it bends
    inline const std::string floppiness_option = "snout_jiggle_floppiness";   // 0 springy .. 150 limp, flops like a hot dog
    inline const std::string heaviness_option = "snout_jiggle_heaviness";     // % of its weight: slower, bigger swings, more droop
}

#endif
