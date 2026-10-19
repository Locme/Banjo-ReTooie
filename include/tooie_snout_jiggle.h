#ifndef __TOOIE_SNOUT_JIGGLE_H__
#define __TOOIE_SNOUT_JIGGLE_H__

#include <string>

// General > Snout jiggle (src/gameplay/snout_jiggle.cpp): Banjo's snout wobbles on a spring as he
// moves. Works with player-model mods that keep his
// skeleton (Smash Banjo). Sliders under it: stiffness, damping, mass and three squash & stretch limits; Nose jiggle
// swings the black nose with the same sliders.
#include <cstdint>

namespace tooie::snout_jiggle {
    // Whether the model whose first display list is at this physical address has vertices this file
    // rewrites each frame (the muzzle and jaw), so frame interpolation should blend them too
    // (src/game/model_tagging.cpp); otherwise they move only at the game's frame rate and stutter.
    bool blend_vertices(uint32_t first_list_phys);

    inline const std::string option = "snout_jiggle";
    // Backpack jiggle (L, 2026-10-19): the backpack and its lid, its own sliders.
    inline const std::string body_option = "backpack_jiggle";
    inline const std::string body_stiffness_option = "backpack_jiggle_stiffness";
    inline const std::string body_damping_option = "backpack_jiggle_damping";
    inline const std::string body_mass_option = "backpack_jiggle_mass";
    inline const std::string body_squash_option = "backpack_jiggle_squash";      // % of its size, every direction
    inline const std::string body_tilt_option = "backpack_jiggle_tilt";          // degrees, + leans its top forward
    inline const std::string kazooie_option = "kazooie_jiggle";               // her crest and tail feathers
    // Her feathers are jiggle bones too, with the snout's kinds of slider (L, 2026-10-19).
    inline const std::string kazooie_stiffness_option = "kazooie_jiggle_stiffness";
    inline const std::string kazooie_damping_option = "kazooie_jiggle_damping";
    inline const std::string kazooie_mass_option = "kazooie_jiggle_mass";
    inline const std::string kazooie_squash_in_option = "kazooie_jiggle_squash_in";
    inline const std::string kazooie_squash_out_option = "kazooie_jiggle_squash_out";
    inline const std::string kazooie_squash_across_option = "kazooie_jiggle_squash_across";
    // The jiggle bone (L, 2026-10-18): a point on a damped spring from the tip.
    inline const std::string stiffness_option = "snout_jiggle_stiffness";
    inline const std::string damping_option = "snout_jiggle_damping";
    inline const std::string mass_option = "snout_jiggle_mass";
    // How far the tip may move from rest, as % of the bone's length.
    inline const std::string squash_in_option = "snout_jiggle_squash_in";     // back into the face
    inline const std::string squash_out_option = "snout_jiggle_squash_out";   // out along it
    inline const std::string squash_across_option = "snout_jiggle_squash_across"; // up, down and sideways
    inline const std::string squash_walk_option = "snout_jiggle_squash_walk"; // back into the face while walking or running
    inline const std::string nose_option = "snout_jiggle_nose";               // the black nose, same sliders
}

#endif
