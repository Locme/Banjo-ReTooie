#include <vector>

#include "tooie_game.h"
#include "../../RecompiledFuncs/recomp_overlays.inl"

#include "librecomp/overlays.hpp"

namespace {
    // ROM address and size of each overlay's code section, by game overlay
    // index minus one. Copied before the runtime sees the section table:
    // init_overlays() sorts that table in place, so indices into it taken from
    // overlay_sections_by_index would no longer name the right section.
    struct OverlaySection {
        uint32_t rom_addr;
        uint32_t size;
    };
    std::vector<OverlaySection> overlay_sections;
}

bool tooie::overlay_section(uint32_t overlay_index, uint32_t& rom_addr, uint32_t& size) {
    if (overlay_index == 0 || overlay_index > overlay_sections.size()) {
        return false;
    }
    const OverlaySection& section = overlay_sections[overlay_index - 1];
    if (section.size == 0) {
        return false;
    }
    rom_addr = section.rom_addr;
    size = section.size;
    return true;
}

void tooie::register_overlays() {
    overlay_sections.clear();
    for (int section_index : overlay_sections_by_index) {
        if (section_index < 0) {
            overlay_sections.push_back({ 0, 0 });
        }
        else {
            const SectionTableEntry& section = section_table[section_index];
            overlay_sections.push_back({ section.rom_addr, section.size });
        }
    }

    recomp::overlays::overlay_section_table_data_t sections {
        .code_sections = section_table,
        .num_code_sections = ARRLEN(section_table),
        .total_num_sections = num_sections,
    };

    recomp::overlays::overlays_by_index_t overlays {
        .table = overlay_sections_by_index,
        .len = ARRLEN(overlay_sections_by_index),
    };

    recomp::overlays::register_overlays(sections, overlays);
}
