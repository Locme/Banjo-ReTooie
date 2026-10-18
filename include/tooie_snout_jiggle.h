#ifndef __TOOIE_SNOUT_JIGGLE_H__
#define __TOOIE_SNOUT_JIGGLE_H__

#include <string>

// General > Snout jiggle (src/gameplay/snout_jiggle.cpp): Banjo's snout wobbles on a spring as he
// moves, like Mario's nose in Super Mario Odyssey. Works with player-model mods that keep his
// skeleton (Smash Banjo). Four sliders under it: stiffness, damping, mass, max squash & stretch.
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
    // The jiggle bone (L, 2026-10-18): a point on a damped spring from the tip.
    inline const std::string stiffness_option = "snout_jiggle_stiffness";
    inline const std::string damping_option = "snout_jiggle_damping";
    inline const std::string mass_option = "snout_jiggle_mass";
    inline const std::string squash_option = "snout_jiggle_squash";           // % of its length the tip may move
}

#endif
