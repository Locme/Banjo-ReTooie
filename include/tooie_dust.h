#pragma once

// Dust exposure (src/gameplay/dust.cpp), for the dirty characters in picture_filters.cpp.
namespace tooie::dust {
    // How many dust triggers there have been since the last call (puffs made within 0.75 s of one count are one), for the
    // character surface layer's dirt, 5% each.
    float take_exposure();
}
