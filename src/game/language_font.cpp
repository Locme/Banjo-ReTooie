// Fonts the player supplies: the game's dialogue font and title font drawn from a TTF or OTF file, every letter of
// them, so a translation's accented letters match the rest (docs/translations.md).
//
// A font asset is a 16-bit glyph count, a 16-bit format, a byte pair each for the cell's width and height, the 32-bit
// offset of the pixel data, then 8 bytes a glyph (texture width, height, advance, height again, 32-bit offset into the
// pixel data). The pixels are IA8, intensity in the high nibble and alpha in the low, row by row, drawn white and shaped
// by their alpha. func_800D35D0 turns a character into a glyph: font 0 (asset 0C21, dialogue and menus) uses glyph
// c - 0x21 for codes up to 'z'; font 1 (0C22, the big title lettering of the Totals and level names) turns a-z into
// capitals and looks the code up in a 128-byte table, with its own order of glyphs.
//
// The player puts dialogue.ttf and title.ttf (or .otf) in the fonts folder of the app-data folder. Rare's fonts are
// believed to be Comicrazy (dialogue) and Lithos (title); any font works. When one is there, that game font is drawn
// again from it when the game loads it: the same cell height, the capitals as tall as Rare's (measured from Rare's H
// in the ROM), on Rare's baseline. An accented capital too tall for the cell is drawn a little smaller, as Rare drew its
// own accented capitals. The dialogue font gets Æ, Ø and Å after its own glyphs ('y', 'z' and 0x7B), the title font
// every accented capital the translations use; the glyph hook in banjotooie.us.toml (func_800D35D0) gives those codes
// their glyphs. Without a supplied font the game's own fonts are used, and the title font shows an accented capital as
// its plain letter. The fonts are the player's own files: nothing of them is in the program.

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#define STB_TRUETYPE_IMPLEMENTATION
#define STBTT_STATIC
#include "stb/stb_truetype.h"

#include "librecomp/game.hpp"
#include "recomp.h"

#include "tooie_asset_mods.h"
#include "tooie_language.h"

namespace fs = std::filesystem;

namespace {
    constexpr uint32_t dialogue_font = 0xC21;
    constexpr uint32_t title_font = 0xC22;
    // The title font's own glyph order (asset 0C22).
    const std::u32string title_order = U"0123456789:ABCDEFGHIJKLMNOPQRSTUVWXYZ©™?()<>\".;-!/'";

    struct Glyph {
        int w = 0, h = 0, adv = 0, h2 = 0;
        std::vector<uint8_t> px;  // IA8
        int alpha(int x, int y) const { return (x < 0 || y < 0 || x >= w || y >= h) ? 0 : (px[y * w + x] & 0xF); }
    };

    struct Font {
        uint16_t format = 0;
        uint8_t cell_w = 0, cell_h = 0;
        std::vector<Glyph> glyphs;
    };

    uint32_t be32(const std::vector<uint8_t>& b, size_t at) {
        return (uint32_t(b[at]) << 24) | (uint32_t(b[at + 1]) << 16) | (uint32_t(b[at + 2]) << 8) | b[at + 3];
    }

    bool read_font(const std::vector<uint8_t>& b, Font& f) {
        if (b.size() < 12) return false;
        const uint32_t count = (uint32_t(b[0]) << 8) | b[1];
        f.format = (uint16_t)((b[2] << 8) | b[3]);
        f.cell_w = b[5];
        f.cell_h = b[7];
        const uint32_t data = be32(b, 8);
        if (12 + count * 8 > b.size() || data > b.size()) return false;
        for (uint32_t i = 0; i < count; i++) {
            const size_t e = 12 + i * 8;
            Glyph g{ b[e], b[e + 1], b[e + 2], b[e + 3], {} };
            const size_t off = data + be32(b, e + 4);
            if (off + size_t(g.w) * g.h > b.size()) return false;
            g.px.assign(b.begin() + off, b.begin() + off + size_t(g.w) * g.h);
            f.glyphs.push_back(std::move(g));
        }
        return true;
    }

    std::vector<uint8_t> write_font(const Font& f) {
        const size_t n = f.glyphs.size();
        const size_t data = (12 + n * 8 + 7) & ~size_t(7);
        std::vector<uint8_t> out(data, 0);
        out[0] = uint8_t(n >> 8); out[1] = uint8_t(n);
        out[2] = uint8_t(f.format >> 8); out[3] = uint8_t(f.format);
        out[5] = f.cell_w; out[7] = f.cell_h;
        auto put32 = [&](size_t at, uint32_t v) { out[at] = uint8_t(v >> 24); out[at + 1] = uint8_t(v >> 16); out[at + 2] = uint8_t(v >> 8); out[at + 3] = uint8_t(v); };
        put32(8, (uint32_t)data);
        std::vector<uint8_t> pixels;
        for (size_t i = 0; i < n; i++) {
            const Glyph& g = f.glyphs[i];
            const size_t e = 12 + i * 8;
            out[e] = uint8_t(g.w); out[e + 1] = uint8_t(g.h); out[e + 2] = uint8_t(g.adv); out[e + 3] = uint8_t(g.h2);
            put32(e + 4, (uint32_t)pixels.size());
            pixels.insert(pixels.end(), g.px.begin(), g.px.end());
            while (pixels.size() % 8) pixels.push_back(0);
        }
        out.insert(out.end(), pixels.begin(), pixels.end());
        return out;
    }

    // The rows a Rare glyph has ink in. False for an empty one.
    bool ink_rows(const Glyph& g, int& y0, int& y1) {
        y0 = g.h; y1 = -1;
        for (int y = 0; y < g.h; y++) {
            for (int x = 0; x < g.w; x++) {
                if (g.alpha(x, y) > 0) { y0 = std::min(y0, y); y1 = std::max(y1, y); }
            }
        }
        return y1 >= 0;
    }

    // ---- Drawing from the supplied font ----

    struct Supplied {
        std::vector<unsigned char> file;
        stbtt_fontinfo info{};
        bool ok = false;
    };

    bool load_supplied(const char* name, Supplied& s) {
        for (const char* ext : { ".ttf", ".otf", ".TTF", ".OTF" }) {
            const fs::path path = tooie::language::fonts_folder() / (std::string(name) + ext);
            std::error_code ec;
            if (!fs::exists(path, ec)) continue;
            std::ifstream in(path, std::ios::binary);
            s.file.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
            const int offset = stbtt_GetFontOffsetForIndex(s.file.data(), 0);
            s.ok = offset >= 0 && stbtt_InitFont(&s.info, s.file.data(), offset) != 0;
            printf("[language] font %s: %s\n", (const char*)path.u8string().c_str(), s.ok ? "drawn from it" : "could not be read");
            fflush(stdout);
            return s.ok;
        }
        return false;
    }

    // Where a game font's letters sit in its cell, measured from Rare's H: the row its top is on and the row under
    // its foot (the baseline).
    struct Metrics {
        int cell_h;
        int cap_top;
        int baseline;
    };

    // `cp` drawn from the supplied font for a cell `m`. The capitals are as tall as Rare's; a letter whose top would go
    // above the cell (an accented capital) is drawn smaller so it fits, keeping the baseline.
    Glyph draw(const Supplied& s, uint32_t cp, const Metrics& m) {
        Glyph g;
        g.h = g.h2 = m.cell_h;
        int x0, y0, x1, y1;
        if (!stbtt_GetCodepointBox(&s.info, 'H', &x0, &y0, &x1, &y1) || y1 <= 0) y1 = 700;
        float scale = float(m.baseline - m.cap_top) / float(y1);
        const int glyph_index = stbtt_FindGlyphIndex(&s.info, (int)cp);
        int gx0 = 0, gy0 = 0, gx1 = 0, gy1 = 0;
        const bool has_box = glyph_index != 0 && stbtt_GetGlyphBox(&s.info, glyph_index, &gx0, &gy0, &gx1, &gy1);
        if (has_box && gy1 * scale > m.baseline - 0.25f) {
            scale = (m.baseline - 0.25f) / float(gy1);
        }
        int advance = 0, lsb = 0;
        stbtt_GetGlyphHMetrics(&s.info, glyph_index, &advance, &lsb);
        g.adv = std::clamp((int)std::lround(advance * scale), 1, 255);
        int bx0 = 0, by0 = 0, bx1 = 0, by1 = 0;
        stbtt_GetGlyphBitmapBox(&s.info, glyph_index, scale, scale, &bx0, &by0, &bx1, &by1);
        const int left = std::max(0, bx0);
        const int bw = std::max(0, bx1 - bx0), bh = std::max(0, by1 - by0);
        g.w = std::max(8, ((left + bw) + 7) & ~7);
        g.px.assign(size_t(g.w) * g.h, 0);
        if (glyph_index == 0 || bw == 0 || bh == 0) return g;
        std::vector<unsigned char> bitmap(size_t(bw) * bh, 0);
        stbtt_MakeGlyphBitmap(&s.info, bitmap.data(), bw, bh, bw, scale, scale, glyph_index);
        // Laid out as Rare's glyphs are: the ink from the glyph's first column, and the advance the width of the ink;
        // the game puts its own gap between letters. (A font's own side bearings on top of that gap ran letters
        // into each other.)
        int ink0 = bw, ink1 = -1;
        for (int y = 0; y < bh; y++) {
            for (int x = 0; x < bw; x++) {
                if ((bitmap[size_t(y) * bw + x] * 15 + 127) / 255 > 0) { ink0 = std::min(ink0, x); ink1 = std::max(ink1, x); }
            }
        }
        if (ink1 < 0) return g;
        g.w = std::max(8, (ink1 - ink0 + 1 + 7) & ~7);
        g.px.assign(size_t(g.w) * g.h, 0);
        g.adv = std::clamp(ink1 - ink0 + 1, 1, 255);
        for (int y = 0; y < bh; y++) {
            const int ty = m.baseline + by0 + y;  // by0 is negative above the baseline
            if (ty < 0 || ty >= g.h) continue;
            for (int x = ink0; x <= ink1; x++) {
                const int a = (bitmap[size_t(y) * bw + x] * 15 + 127) / 255;
                if (a > 0) g.px[size_t(ty) * g.w + (x - ink0)] = uint8_t(0xF0 | a);
            }
        }
        (void)left;
        return g;
    }

    Metrics measure(const Font& rare, const Glyph& h) {
        int y0 = 2, y1 = rare.cell_h - 2;
        ink_rows(h, y0, y1);
        return { rare.cell_h, y0, y1 + 1 };
    }

    // ---- The fonts ----

    std::mutex mutex;
    bool built = false;
    bool dialogue_supplied = false;
    bool title_supplied = false;
    int title_gap = 1;  // pixels between title letters with a supplied font, before the lettering's scale
    std::vector<uint8_t> dialogue_bytes, title_bytes;
    // Character code -> glyph index for the codes the game's lookup can't give (font 0 and font 1).
    std::map<int, int> dialogue_codes, title_codes;

    void build_all() {
        built = true;
        Font dialogue, title;
        const bool have_dialogue = read_font(tooie::asset_mods::rom_asset_bytes(dialogue_font), dialogue) && dialogue.glyphs.size() >= 88;
        const bool have_title = read_font(tooie::asset_mods::rom_asset_bytes(title_font), title) && title.glyphs.size() >= 51;

        Supplied ttf;
        if (have_dialogue && load_supplied("dialogue", ttf)) {
            // Every glyph, codes 0x21 to 0x7B: ASCII, then the game's accented capitals, then Æ Ø Å.
            const Metrics m = measure(dialogue, dialogue.glyphs['H' - 0x21]);
            dialogue.glyphs.clear();
            for (int code = 0x21; code <= 0x7B; code++) {
                const uint32_t letter = code < 0x5B ? (uint32_t)code : tooie::language::code_letter((uint8_t)code);
                dialogue.glyphs.push_back(draw(ttf, letter ? letter : (uint32_t)code, m));
            }
            dialogue_codes[0x7B] = 0x7B - 0x21;
            dialogue_bytes = write_font(dialogue);
            dialogue_supplied = true;
        }

        Supplied title_ttf;
        if (have_title && load_supplied("title", title_ttf)) {
            const Metrics m = measure(title, title.glyphs[title_order.find(U'H')]);
            title.glyphs.clear();
            for (char32_t c : title_order) title.glyphs.push_back(draw(title_ttf, (uint32_t)c, m));
            for (int code = 0x5B; code <= 0x7B; code++) {
                const uint32_t letter = tooie::language::code_letter((uint8_t)code);
                if (letter == 0) continue;
                title_codes[code] = (int)title.glyphs.size();
                title.glyphs.push_back(draw(title_ttf, letter, m));
            }
            title_gap = std::max(1, (int)std::lround((m.baseline - m.cap_top) * 0.08));
            title_supplied = true;
            title_bytes = write_font(title);
        } else if (have_title) {
            // Rare's title font has no accented capitals: each shows as its plain letter (É as E, not the B the
            // game's capitalising would give).
            for (int code = 0x5B; code <= 0x7B; code++) {
                const uint32_t letter = tooie::language::code_letter((uint8_t)code);
                static const std::map<uint32_t, char> plain = {
                    {0xC0, 'A'}, {0xC1, 'A'}, {0xC2, 'A'}, {0xC4, 'A'}, {0xC5, 'A'}, {0xC6, 'A'}, {0xC7, 'C'}, {0xC8, 'E'},
                    {0xC9, 'E'}, {0xCA, 'E'}, {0xCB, 'E'}, {0xCC, 'I'}, {0xCD, 'I'}, {0xCE, 'I'}, {0xCF, 'I'}, {0xD1, 'N'},
                    {0xD2, 'O'}, {0xD3, 'O'}, {0xD4, 'O'}, {0xD6, 'O'}, {0xD8, 'O'}, {0xD9, 'U'}, {0xDA, 'U'}, {0xDB, 'U'},
                    {0xDC, 'U'},
                };
                auto found = plain.find(letter);
                if (found != plain.end()) title_codes[code] = (int)title_order.find((char32_t)found->second);
            }
        }

        // TOOIE_FONT_DUMP=<folder>: the fonts as built, for checking them (font_0C21.bin, font_0C22.bin).
        if (const char* dir = std::getenv("TOOIE_FONT_DUMP")) {
            for (const auto& [name, bytes] : { std::pair{ "font_0C21.bin", &dialogue_bytes }, std::pair{ "font_0C22.bin", &title_bytes } }) {
                if (bytes->empty()) continue;
                if (FILE* f = std::fopen((std::string(dir) + "/" + name).c_str(), "wb")) {
                    std::fwrite(bytes->data(), 1, bytes->size(), f);
                    std::fclose(f);
                }
            }
        }
    }
}

fs::path tooie::language::fonts_folder() {
    return recomp::get_config_path() / "fonts";
}

bool tooie::language::dialogue_font_supplied() {
    // Known before the game loads its fonts too: the text of the first area may be built first.
    static const bool supplied = [] {
        for (const char* ext : { ".ttf", ".otf", ".TTF", ".OTF" }) {
            std::error_code ec;
            if (fs::exists(fonts_folder() / (std::string("dialogue") + ext), ec)) return true;
        }
        return false;
    }();
    return supplied;
}

std::vector<uint8_t> tooie::language::font_asset(uint32_t id) {
    if (id != dialogue_font && id != title_font) return {};
    std::lock_guard lock{ mutex };
    if (!built) build_all();
    return id == dialogue_font ? dialogue_bytes : title_bytes;
}

// Hooked at the start of func_800D35D0 (character -> glyph index; $a0 the font, $a1 the character). Returns 1 with $v0
// set for a character the game's own lookup can't give, 0 to let the game look it up.
extern "C" int tooie_glyph_index(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    const int font = (int)ctx->r4;
    const int c = (int)ctx->r5;
    if (font != 0 && font != 1) return 0;
    std::lock_guard lock{ mutex };
    if (!built) return 0;  // the fonts load before any text is drawn
    const auto& codes = font == 0 ? dialogue_codes : title_codes;
    auto found = codes.find(c);
    if (found == codes.end()) return 0;
    ctx->r2 = found->second;
    return 1;
}

// The title lettering's spacing. func_80800084_fxkern puts each letter half its drawn width on from half the last
// one's, less 4 pixels, plus a nudge for the pair from func_80800000_fxkern (in pixels before the lettering's scale),
// so Rare's stone letters overlap; its table of nudges is tuned to their shapes (some sit higher). With a title font of
// the player's own, whose glyphs are as wide as their ink, the nudge gives the 4 pixels back plus a small gap and
// nothing up or down, so its letters sit side by side.

// Hooked at the start of func_80800000_fxkern ($a2 and $a3 point at the x and y nudge). Returns 1 with the nudge set
// for a supplied title font, 0 to let the game look the pair up.
extern "C" int tooie_title_kerning(uint8_t* rdram, recomp_context* ctx) {
    int gap;
    {
        std::lock_guard lock{ mutex };
        if (!title_supplied) return 0;
        gap = title_gap;
    }
    MEM_W(0, ctx->r6) = 4 + gap;
    MEM_W(0, ctx->r7) = 0;
    return 1;
}
