#ifndef __TOOIE_ORIGINAL_HONEYCOMB_H__
#define __TOOIE_ORIGINAL_HONEYCOMB_H__

#include <cstdint>
#include <string>
#include <vector>

// Back-Port: Original honeycomb (src/gameplay/original_honeycomb.cpp): health honeycombs use
// Banjo-Kazooie's comb, which Tooie still carries unused, built from the ROM when the comb loads.
namespace tooie::original_honeycomb {
    inline const std::string option = "original_honeycomb";
    // Tooie's health honeycomb, and Banjo-Kazooie's comb left in Tooie's assets.
    constexpr uint32_t health_model = 0x0704;
    constexpr uint32_t bk_model = 0x0614;

    bool enabled();

    // Banjo-Kazooie's comb (asset bk_model) in the health honeycomb's form (asset health_model),
    // both decompressed. Empty when either is not what is expected.
    std::vector<uint8_t> build(const std::vector<uint8_t>& bk, const std::vector<uint8_t>& tooie);
}

#endif
