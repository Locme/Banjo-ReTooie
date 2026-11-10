// What a dumped texture belongs to, for sorting a texture dump (texture_sweep.cpp writes it into each texture's
// <hash>.json; tools/organize_textures.py sorts by it).
//
// RT64 dumps a texture while it draws the frame that first loads it, and beside the dump writes <hash>.rice.json with
// the texture's address in the game's memory and the address of the display-list command that loaded it. From those:
//   - drawn in 2D: the load command lies in the frame's own 2D part of the display list (from the end of the 3D
//     scene to the end of the frame, hide_hud.cpp's marks; the last few frames are kept, as RT64 draws a frame or
//     two after the game made it). That is the HUD, the pause menu, text and the like.
//   - the asset: the game keeps the assets it has loaded in a table of slots (func_800D5B34, load asset by id): the
//     slot count at 0x8012B7E4, each slot's asset id (a halfword at 0x80137800) and address (a word at 0x80137AD0).
//     The heap puts a 16-byte header before each block (+4: the next block), so an asset runs from its address to
//     the next block's header. The owner is the asset whose block holds the display-list command that loaded the
//     texture: a model's display list is in the model, wherever the model loader put its textures (Mayahem Temple's
//     see-through model is 0x2B60 bytes and its textures sit in a block of their own after it, in no slot; the
//     texture's own address would name no asset, or the wrong one). A load made from a list built each frame (a
//     sprite, an effect) is in no asset, and then the asset whose block holds the texture itself is the owner.
//     Models (kind 0) are characters, objects, pickups and maps by their id; other kinds hold sprites and effects.
//   - the level: the map table gives each map a solid and a see-through model (func_80800000_gcmapDll, hooked for
//     the window beams); textures in those assets are the map's own.
// The textures of a model drawn in 2D (the talking heads in the dialogue box) are drawn from inside the model's own
// display list, not the frame's, so they come out as the model with drawn_2d false; the organiser sorts the talking
// heads by their names.

#include <algorithm>
#include <array>
#include <atomic>
#include <mutex>
#include <unordered_map>

#include "recomp.h"

#include "tooie_asset_mods.h"
#include "tooie_texture_context.h"

namespace {
    std::atomic<uint8_t*> game_rdram{ nullptr };

    // The 2D parts of the last few frames, physical [start, end).
    std::mutex ranges_mutex;
    std::array<std::pair<uint32_t, uint32_t>, 6> ranges{};
    size_t next_range = 0;

    // Model asset -> the map it is the solid or see-through model of.
    std::mutex maps_mutex;
    std::unordered_map<uint16_t, uint16_t> level_models;

    constexpr uint32_t slot_count_addr = 0x8012B7E4;
    constexpr uint32_t slot_ids_addr = 0x80137800;
    constexpr uint32_t slot_ptrs_addr = 0x80137AD0;
    constexpr uint32_t max_slots = 0xF0;
    // RAM the heap's block pointers may point into (the game's 8 MB and the port's extra memory).
    bool heap_pointer(uint32_t p) {
        return p >= 0x80000000u && p < 0x80000000u + 0x1000000u;
    }

    uint32_t read_word(uint8_t* rdram, uint32_t addr) {
        return (uint32_t)MEM_W(0, (int32_t)addr);
    }
    uint16_t read_half(uint8_t* rdram, uint32_t addr) {
        return (uint16_t)MEM_HU(0, (int32_t)addr);
    }
    uint8_t read_byte(uint8_t* rdram, uint32_t addr) {
        return (uint8_t)MEM_BU(0, (int32_t)addr);
    }
}

void tooie::texture_context::tick(uint8_t* rdram) {
    game_rdram.store(rdram, std::memory_order_relaxed);
}

void tooie::texture_context::note_2d(uint32_t start, uint32_t end) {
    std::lock_guard lock{ ranges_mutex };
    ranges[next_range] = { start & 0x1FFFFFFF, end & 0x1FFFFFFF };
    next_range = (next_range + 1) % ranges.size();
}

void tooie::texture_context::note_map_models(uint16_t map, uint16_t solid, uint16_t see_through) {
    std::lock_guard lock{ maps_mutex };
    if (solid != 0) level_models[solid] = map;
    if (see_through != 0) level_models[see_through] = map;
}

tooie::texture_context::Context tooie::texture_context::classify(uint32_t texture_address, uint32_t dl_command) {
    Context c;
    const uint32_t phys = texture_address & 0x1FFFFFFF;
    if (dl_command != 0) {
        const uint32_t cmd = dl_command & 0x1FFFFFFF;
        std::lock_guard lock{ ranges_mutex };
        for (const auto& [start, end] : ranges) {
            if (start < end && cmd >= start && cmd < end) {
                c.drawn_2d = true;
                break;
            }
        }
    }
    uint8_t* rdram = game_rdram.load(std::memory_order_relaxed);
    if (rdram == nullptr || (phys == 0 && dl_command == 0)) {
        return c;
    }
    const uint32_t count = std::min<uint32_t>(read_byte(rdram, slot_count_addr), max_slots);
    // The asset whose own heap block holds this physical address, or -1.
    auto owner_of = [&](uint32_t at, uint32_t& start_out) -> int32_t {
        int32_t id = -1;
        start_out = 0;
        for (uint32_t slot = 0; slot < count; slot++) {
            const uint32_t start = read_word(rdram, slot_ptrs_addr + slot * 4) & 0x1FFFFFFF;
            if (start < 0x10 || start > at || start < start_out) continue;
            const uint32_t next = read_word(rdram, 0x80000000u | (start - 0x10 + 4));
            if (heap_pointer(next) && at < (next & 0x1FFFFFFF)) {
                start_out = start;
                id = read_half(rdram, slot_ids_addr + slot * 2);
            }
        }
        return id;
    };
    uint32_t best_start = 0;
    int32_t best_id = dl_command != 0 ? owner_of(dl_command & 0x1FFFFFFF, best_start) : -1;
    if (best_id < 0 && phys != 0) {
        best_id = owner_of(phys, best_start);
    }
    if (best_id >= 0) {
        c.asset = best_id;
        c.asset_offset = phys >= best_start ? phys - best_start : 0;
        c.asset_kind = tooie::asset_mods::asset_kind((uint32_t)best_id);
        std::lock_guard lock{ maps_mutex };
        auto found = level_models.find((uint16_t)best_id);
        if (found != level_models.end()) {
            c.level_of = found->second;
        }
    }
    return c;
}
