// A text screen drawn on the game window before the renderer exists (include/tooie_boot_screen.h):
// "Installing Mods" while mod zips unpack, then "Loading" while the renderer starts (main.cpp).
//
// At startup the window is created and the mods are scanned (unpacking any new mod zips) before RT64
// and the menus start, so the window would otherwise stay blank, and stop responding, for as long as a
// big zip takes. This draws the text with SDL's software window surface and stb_truetype, using the
// menu fonts from assets/. The surface is a plain CPU framebuffer (GDI on Windows, XShm on X11), and
// close() destroys it before RT64 makes its swapchain for the same window.
//
// Not on Android, where a CPU framebuffer would hold the native window and the Vulkan swapchain could
// not be made for it afterwards, nor on macOS (Metal view).

#include "tooie_boot_screen.h"

#if defined(_WIN32) || (defined(__linux__) && !defined(__ANDROID__))

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <vector>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#define STBTT_STATIC
#define STB_TRUETYPE_IMPLEMENTATION
#include "../../lib/rt64/src/contrib/stb/stb_truetype.h"

#include "util/file.h"

namespace {
    struct Font {
        std::vector<unsigned char> data;
        stbtt_fontinfo info{};
        bool loaded = false;

        void load(const char* asset) {
            std::ifstream in(recompui::file::get_asset_path(asset), std::ios::binary);
            data.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
            loaded = !data.empty() && stbtt_InitFont(&info, data.data(), stbtt_GetFontOffsetForIndex(data.data(), 0));
        }
    };

    SDL_Window* window = nullptr;
    bool shown = false;
    std::string old_acceleration_hint;
    bool had_acceleration_hint = false;
    Font title_font;
    Font detail_font;
    std::chrono::steady_clock::time_point next_draw{};

    constexpr uint8_t background[3] = { 0x14, 0x14, 0x14 };

    int text_width(const Font& font, float scale, const std::string& text) {
        float width = 0;
        for (unsigned char c : text) {
            int advance, bearing;
            stbtt_GetCodepointHMetrics(&font.info, c, &advance, &bearing);
            width += advance * scale;
        }
        return int(width);
    }

    // Draws one line of text (ASCII; anything else is skipped) centred on x, with its baseline at y.
    void draw_text(SDL_Surface* surface, const Font& font, int pixel_height, int center_x, int baseline,
        const std::string& text, uint8_t brightness) {
        if (!font.loaded || pixel_height <= 0) {
            return;
        }
        const float scale = stbtt_ScaleForPixelHeight(&font.info, float(pixel_height));
        float x = float(center_x - text_width(font, scale, text) / 2);
        for (unsigned char c : text) {
            if (c < 0x20 || c > 0x7E) {
                continue;
            }
            int advance, bearing;
            stbtt_GetCodepointHMetrics(&font.info, c, &advance, &bearing);
            int w, h, xoff, yoff;
            unsigned char* glyph = stbtt_GetCodepointBitmap(&font.info, 0, scale, c, &w, &h, &xoff, &yoff);
            for (int gy = 0; gy < h; gy++) {
                int py = baseline + yoff + gy;
                if (py < 0 || py >= surface->h) {
                    continue;
                }
                auto* row = static_cast<uint8_t*>(surface->pixels) + py * surface->pitch;
                for (int gx = 0; gx < w; gx++) {
                    int px = int(x) + xoff + gx;
                    if (px < 0 || px >= surface->w) {
                        continue;
                    }
                    uint32_t a = glyph[gy * w + gx];
                    if (a == 0) {
                        continue;
                    }
                    auto mix = [&](uint8_t bg) { return uint8_t((bg * (255 - a) + brightness * a) / 255); };
                    uint32_t pixel = SDL_MapRGB(surface->format, mix(background[0]), mix(background[1]), mix(background[2]));
                    std::memcpy(row + px * surface->format->BytesPerPixel, &pixel, surface->format->BytesPerPixel);
                }
            }
            stbtt_FreeBitmap(glyph, nullptr);
            x += advance * scale;
        }
    }
}

void tooie::boot_screen::set_window(SDL_Window* new_window) {
    window = new_window;
}

void tooie::boot_screen::show(const std::string& title, const std::string& detail) {
    if (window == nullptr) {
        return;
    }
    // Keeps the window responding (and the OS from calling it hung) while the caller works.
    SDL_PumpEvents();
    auto now = std::chrono::steady_clock::now();
    if (shown && now < next_draw) {
        return;
    }
    next_draw = now + std::chrono::milliseconds(30);

    if (!shown) {
        shown = true;
        // A software framebuffer, not one made with an SDL renderer (which would make its own swapchain).
        const char* hint = SDL_GetHint(SDL_HINT_FRAMEBUFFER_ACCELERATION);
        had_acceleration_hint = hint != nullptr;
        old_acceleration_hint = hint ? hint : "";
        SDL_SetHint(SDL_HINT_FRAMEBUFFER_ACCELERATION, "0");
        title_font.load("LuckiestGuy-Regular.ttf");
        detail_font.load("InterVariable.ttf");
    }

    SDL_Surface* surface = SDL_GetWindowSurface(window);
    if (surface == nullptr) {
        return;
    }
    if (SDL_MUSTLOCK(surface)) {
        SDL_LockSurface(surface);
    }
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, background[0], background[1], background[2]));
    const int size = std::max(1, std::min(surface->h, surface->w * 9 / 16));
    draw_text(surface, title_font, size / 9, surface->w / 2, surface->h / 2, title, 0xFF);
    draw_text(surface, detail_font, size / 28, surface->w / 2, surface->h / 2 + size / 12, detail, 0xA0);
    if (SDL_MUSTLOCK(surface)) {
        SDL_UnlockSurface(surface);
    }
    SDL_UpdateWindowSurface(window);
}

void tooie::boot_screen::close() {
    if (!shown) {
        return;
    }
    shown = false;
    SDL_DestroyWindowSurface(window);
    if (had_acceleration_hint) {
        SDL_SetHint(SDL_HINT_FRAMEBUFFER_ACCELERATION, old_acceleration_hint.c_str());
    } else {
        SDL_ResetHint(SDL_HINT_FRAMEBUFFER_ACCELERATION);
    }
    title_font = {};
    detail_font = {};
}

#else

void tooie::boot_screen::set_window(SDL_Window*) {}
void tooie::boot_screen::show(const std::string&, const std::string&) {}
void tooie::boot_screen::close() {}

#endif
