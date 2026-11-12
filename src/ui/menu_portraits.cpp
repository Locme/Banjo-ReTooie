// The Esc menu's tab portraits (2026-11-12): each tab of the settings sidebar shows a talking-head portrait, as
// each row of the game's Start menu does. The game draws its portraits from sprite assets in the ROM;
// gczoomboxdata_entrypoint_1 gives a portrait's asset (as src/gameplay/totals_checklist.cpp uses it). Here the
// sprite is decoded to RGBA and handed to the menu as an image, so an asset mod that replaces it shows too.
//
// The sprite (worked out from `portraits dump`): big-endian halfwords, the frame count at 0, the texture format
// at 2 (1 CI4, 4 CI8), the width and height at 8 and 0xA, and at 0x10 a word with where its texture segment
// starts. The segment holds the palette (RGBA5551, 16 or 256 entries) and then the pixels, rows top to bottom,
// as the sprite's own display list loads them (palette at segment 2 + 0, texture at + 0x20 or + 0x200). The frames
// follow one another, sharing the palette. A portrait has ten: 0 to 5 the mouth talking, 6 to 9 the eyes closing.
// A few large sprites are cut into tiles and don't decode this way; none of them is used.
//
// The Start menu's portraits blink now and then, each on its own (seen in game, 2026-11-12): the tabs get the still
// frame and the blink's four, and the menu blinks them (Tab::update_blink in lib-patches/RecompFrontend.patch).

#include <algorithm>
#include <cstdio>
#include <mutex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <system_error>
#include <unordered_map>
#include <vector>

#include "funcs.h"
#include "recompui/config.h"
#include "recompui/recompui.h"
#include "ultramodern/ultramodern.hpp"
#include "tooie_asset_mods.h"
#include "tooie_dev_files.h"
#include "tooie_menu_portraits.h"
#include "tooie_menu_pause.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_STATIC
#include "../../lib/rt64/src/contrib/stb/stb_image_write.h"

namespace {
    uint32_t call(uint8_t* rdram, recomp_context* ctx, void (*fn)(uint8_t*, recomp_context*), uint32_t a0) {
        recomp_context saved = *ctx;
        ctx->r29 = (int32_t)((((uint32_t)ctx->r29 - 0x100) & ~0xFu));
        ctx->r4 = (int32_t)a0;
        fn(rdram, ctx);
        const uint32_t result = (uint32_t)ctx->r2;
        *ctx = saved;
        return result;
    }

    // gczoomboxdata_entrypoint_4(portrait, index, &sound, &other, &value) (gczoombox func_80802C80 calls it through
    // the thunk at 0x80088430, after entrypoint_3, 0x80088428, gave the count): the out arguments are written to a
    // scratch area below the stack, the fifth passed on the stack as the game passes it.
    bool voice_entry(uint8_t* rdram, recomp_context* ctx, int portrait, int index, tooie::menu_portraits::Voice& out) {
        recomp_context saved = *ctx;
        const uint32_t sp = ((uint32_t)ctx->r29 - 0x200) & ~0xFu;
        const uint32_t scratch = sp + 0x100;
        MEM_W(0, (gpr)(int32_t)scratch) = 0;
        MEM_W(4, (gpr)(int32_t)scratch) = 0;
        MEM_W(8, (gpr)(int32_t)scratch) = 0;
        MEM_W(0x10, (gpr)(int32_t)sp) = (int32_t)(scratch + 8);
        ctx->r29 = (int32_t)sp;
        ctx->r4 = portrait;
        ctx->r5 = index;
        ctx->r6 = (int32_t)scratch;
        ctx->r7 = (int32_t)(scratch + 4);
        _gczoomboxdata_entrypoint_4(rdram, ctx);
        *ctx = saved;
        out.sound = (int16_t)MEM_H(0, (gpr)(int32_t)scratch);
        out.volume = (int16_t)MEM_H(4, (gpr)(int32_t)scratch);
        const uint32_t bits = (uint32_t)MEM_W(8, (gpr)(int32_t)scratch);
        std::memcpy(&out.pitch, &bits, sizeof(bits));
        return true;
    }

    // A portrait's sprite asset, 0 when it has none. The table is fixed, so each is asked once.
    uint32_t asset_of(uint8_t* rdram, recomp_context* ctx, int portrait) {
        static std::unordered_map<int, uint32_t> assets;
        auto found = assets.find(portrait);
        if (found == assets.end()) {
            found = assets.emplace(portrait, call(rdram, ctx, _gczoomboxdata_entrypoint_1, (uint32_t)portrait) & 0xFFFF).first;
        }
        return found->second;
    }

    uint16_t half(const std::vector<uint8_t>& b, size_t at) {
        return (uint16_t)((b[at] << 8) | b[at + 1]);
    }

    // The sprite's frame count, 0 when it can't be read.
    int frame_count(const std::vector<uint8_t>& b) {
        return b.size() < 0x20 ? 0 : half(b, 0);
    }

    bool decode_sprite(const std::vector<uint8_t>& b, std::vector<uint8_t>& rgba, int& width, int& height, int frame = 0) {
        if (b.size() < 0x20 || frame < 0 || frame >= std::max(1, frame_count(b))) {
            return false;
        }
        const int format = half(b, 2);
        width = half(b, 8);
        height = half(b, 0xA);
        const size_t segment = ((size_t)half(b, 0x10) << 16) | half(b, 0x12);
        if ((format != 1 && format != 4) || width <= 0 || height <= 0 || width > 256 || height > 256) {
            return false;
        }
        const int colours = format == 4 ? 256 : 16;
        const size_t pixel_bytes = format == 4 ? (size_t)width * height : ((size_t)width * height + 1) / 2;
        const size_t pixels = segment + 2 * (size_t)colours + (size_t)frame * pixel_bytes;
        if (pixels + pixel_bytes > b.size()) {
            return false;
        }
        rgba.assign((size_t)width * height * 4, 0);
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                const size_t i = (size_t)y * width + x;
                int index;
                if (format == 4) {
                    index = b[pixels + i];
                } else {
                    const uint8_t byte = b[pixels + i / 2];
                    index = (i % 2 == 0) ? (byte >> 4) : (byte & 0xF);
                }
                const uint16_t c = half(b, segment + 2 * (size_t)index);
                uint8_t* p = &rgba[i * 4];
                p[0] = (uint8_t)(((c >> 11) & 31) * 255 / 31);
                p[1] = (uint8_t)(((c >> 6) & 31) * 255 / 31);
                p[2] = (uint8_t)(((c >> 1) & 31) * 255 / 31);
                p[3] = (c & 1) ? 255 : 0;
            }
        }
        return true;
    }

    // Each tab's portrait: its sprite asset (from `portraits dump`; the portrait id is in the comment).
    // Each tab's portrait: its id in gczoomboxdata's table (for its voice) and its sprite asset (from `portraits dump`).
    struct TabPortrait {
        const char* tab;
        int portrait;
        uint32_t asset;
    };
    // Picked to suit each tab (L, 2026-11-12).
    constexpr TabPortrait tab_portraits[] = {
        { "general", 0x0C, 0x0B89 },          // Banjo
        { "qol", 0x0D, 0x0B8B },              // Kazooie
        { "gameplay", 0x28, 0x0BAB },         // Jamjars, who teaches the moves
        { "work_in_progress", 0x2A, 0x0BB2 }, // a caveman: still in the stone age (WIP)
        { "graphics", 0xA5, 0x0BCF },         // Mumbo and his magic
        { "performance", 0xB0, 0x0BF2 },      // Bottles and his glasses (Display)
        { "controls", 0x04, 0x0C00 },         // a machine of buttons
        { "sound", 0x9B, 0x0BE8 },            // the singing bird
        { "cheats", 0xA7, 0x0BFA },           // Cheato, the spell book of cheats
        { "debug", 0x47, 0x0BF5 },            // Boggy, the polar bear (Warp)
        { "achievements", 0xAE, 0x0BCE },     // King Jingaling, who hands out rewards
        { "album", 0x3E, 0x0BAD },            // in a safari hat, out taking pictures
        { "mods", 0xAB, 0x0B9A },             // Klungo the inventor
        { "wip", 0x32, 0x0BB8 },              // in a miner's hard hat, the builder (DEV)
    };

    // A tab whose character is to speak on the next game frame (main thread in, game thread out).
    std::mutex voice_mutex;
    std::string voice_tab;

    bool shown = false;
}

bool tooie::menu_portraits::decode(uint8_t* rdram, recomp_context* ctx, int portrait, std::vector<uint8_t>& rgba, int& width, int& height) {
    const uint32_t asset = asset_of(rdram, ctx, portrait);
    if (asset == 0) {
        return false;
    }
    return decode_sprite(tooie::asset_mods::asset_bytes(asset), rgba, width, height);
}

int tooie::menu_portraits::dump(uint8_t* rdram, recomp_context* ctx, int last, std::string& folder_out) {
    const std::filesystem::path folder = tooie::dev_files::folder() / "portraits";
    std::error_code ec;
    std::filesystem::create_directories(folder, ec);
    folder_out = folder.string();
    int written = 0;
    for (int portrait = 0; portrait <= last; portrait++) {
        const uint32_t asset = asset_of(rdram, ctx, portrait);
        if (asset == 0) {
            continue;
        }
        const std::vector<uint8_t> bytes = tooie::asset_mods::asset_bytes(asset);
        if (bytes.empty()) {
            continue;
        }
        char name[64];
        std::snprintf(name, sizeof(name), "%02X_asset%04X", portrait, asset);
        {
            std::ofstream out(folder / (std::string(name) + ".bin"), std::ios::binary | std::ios::trunc);
            out.write(reinterpret_cast<const char*>(bytes.data()), (std::streamsize)bytes.size());
        }
        std::vector<uint8_t> rgba;
        int width = 0, height = 0;
        if (decode_sprite(bytes, rgba, width, height)) {
            std::vector<uint8_t> png;
            auto append = [](void* context, void* data, int size) {
                auto* out = static_cast<std::vector<uint8_t>*>(context);
                out->insert(out->end(), static_cast<uint8_t*>(data), static_cast<uint8_t*>(data) + size);
            };
            if (stbi_write_png_to_func(append, &png, width, height, 4, rgba.data(), width * 4)) {
                std::ofstream out(folder / (std::string(name) + ".png"), std::ios::binary | std::ios::trunc);
                out.write(reinterpret_cast<const char*>(png.data()), (std::streamsize)png.size());
            }
        }
        written++;
    }
    return written;
}

void tooie::menu_portraits::tick(uint8_t* rdram, recomp_context* ctx) {
    std::string tab;
    {
        std::lock_guard lock{ voice_mutex };
        tab.swap(voice_tab);
    }
    if (!tab.empty()) {
        for (const TabPortrait& t : tab_portraits) {
            // A character with no voice makes the Start menu's sound for a page instead.
            if (tab == t.tab && !speak(rdram, ctx, t.portrait)) {
                tooie::menu_pause::slide_sound(recompui::config::SlideSound::RowIn);
            }
        }
    }
    // The pictures, once, from the first game frame: the ROM is read by then.
    if (shown) {
        return;
    }
    shown = true;
    // The still frame, then the blink's frames (6 to 9) when the sprite has them.
    constexpr int still = 0;
    constexpr int blink_first = 6;
    constexpr int blink_last = 9;
    for (const TabPortrait& t : tab_portraits) {
        const std::vector<uint8_t> bytes = tooie::asset_mods::asset_bytes(t.asset);
        std::vector<int> wanted{ still };
        if (frame_count(bytes) > blink_last) {
            for (int f = blink_first; f <= blink_last; f++) {
                wanted.push_back(f);
            }
        }
        std::vector<std::string> frames;
        for (const int f : wanted) {
            std::vector<uint8_t> rgba;
            int width = 0, height = 0;
            if (!decode_sprite(bytes, rgba, width, height, f)) {
                break;
            }
            const std::string src = std::string("?/portrait/") + t.tab + "/" + std::to_string(f);
            recompui::queue_image_from_bytes_rgba32(src, std::vector<char>(rgba.begin(), rgba.end()), (uint32_t)width, (uint32_t)height);
            frames.push_back(src);
        }
        if (!frames.empty()) {
            recompui::config::set_tab_portrait(t.tab, frames);
        }
    }
}

std::vector<tooie::menu_portraits::Voice> tooie::menu_portraits::voices(uint8_t* rdram, recomp_context* ctx, int portrait) {
    std::vector<Voice> out;
    const int count = (int)(call(rdram, ctx, _gczoomboxdata_entrypoint_3, (uint32_t)portrait) & 0xFF);
    for (int i = 0; i < count && i < 5; i++) {
        Voice v{};
        if (voice_entry(rdram, ctx, portrait, i, v)) {
            out.push_back(v);
        }
    }
    return out;
}

bool tooie::menu_portraits::speak(uint8_t* rdram, recomp_context* ctx, int portrait) {
    const std::vector<Voice> list = voices(rdram, ctx, portrait);
    if (list.empty()) {
        return false;
    }
    const Voice& v = list[(size_t)std::rand() % list.size()];
    // As func_8009DE38 plays a sound on the player, through func_8009DCCC(player, its sound slot, sound, pitch,
    // volume), with the voice's own pitch and volume as the dialogue box gives them.
    const uint32_t player = (uint32_t)MEM_W(0, (gpr)(int32_t)0x80135490);
    if (player < 0x80000000u || player >= 0x81000000u) {
        return false;
    }
    const uint32_t info = (uint32_t)MEM_W(0x104, (gpr)(int32_t)player);
    if (info < 0x80000000u || info >= 0x81000000u) {
        return false;
    }
    recomp_context saved = *ctx;
    const uint32_t sp = ((uint32_t)ctx->r29 - 0x200) & ~0xFu;
    MEM_W(0x10, (gpr)(int32_t)sp) = v.volume;
    uint32_t pitch_bits;
    std::memcpy(&pitch_bits, &v.pitch, sizeof(pitch_bits));
    ctx->r29 = (int32_t)sp;
    ctx->r4 = (int32_t)player;
    ctx->r5 = (int32_t)MEM_BU(2, (gpr)(int32_t)info);
    ctx->r6 = v.sound;
    ctx->r7 = (int32_t)pitch_bits;
    func_8009DCCC(rdram, ctx);
    const uint32_t result = (uint32_t)ctx->r2;
    *ctx = saved;
    if (std::getenv("TOOIE_MENU_PAUSE_LOG") != nullptr) {
        std::fprintf(stderr, "[menu-portraits] portrait 0x%X says sound 0x%X (pitch %.2f, volume %d): 0x%X\n", portrait,
            (uint32_t)v.sound & 0xFFFF, v.pitch, v.volume, result);
    }
    return true;
}

bool tooie::menu_portraits::tab_voice(const std::string& tab_id) {
    // The menu also works from the launcher, before the game runs: no voice then, and none left over for later.
    if (!ultramodern::is_game_started()) {
        return true;
    }
    for (const TabPortrait& t : tab_portraits) {
        if (tab_id == t.tab) {
            std::lock_guard lock{ voice_mutex };
            voice_tab = tab_id;
            return true;
        }
    }
    return false;
}
