// Hide HUD (handoff 4.84).
//
// F1 hides the game's screen-space 2D (the HUD, and text boxes with their
// portraits, also the pause menu's text) and shows it again. func_800A73F4 draws each
// frame; banjotooie.us.toml marks the display list pointer before and after
// the calls that draw that 2D. While hidden, the pointer is put back to
// where it was before each of those calls, so what they wrote is never run.
// The area name shown on arrival (chintrotext) is drawn with the 3D scene, so a hook on its
// draw (func_808003EC_chintrotext) skips it too.
// The game itself carries on as normal: only the drawing is skipped.
//
// Headless test hook: TOOIE_HIDE_HUD=1 starts with the HUD hidden.

#include <atomic>
#include <chrono>
#include <cstdlib>
#include <mutex>
#include <thread>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recomp.h"
#include "tooie_achievements.h"
#include "tooie_debug.h"
#include "tooie_hd_shadows.h"
#include "tooie_hide_hud.h"
#include "tooie_hooks.h"
#include "tooie_model_tagging.h"
#include "tooie_gfx_budget.h"
#include "tooie_hotkeys.h"
#include "tooie_toast.h"
#include "tooie_transform_menu.h"

namespace {
    using namespace std::chrono_literals;

    constexpr auto poll_interval = 10ms;
    std::once_flag started;
    std::atomic<bool> hidden{false};

    // Display list pointer at each mark. Marks 2-3, 4-5 and 5-6 span the
    // portrait, HUD and text box calls. Marks 0-1 span func_800C0984, which is
    // left alone: while paused it also draws the frozen picture of the game
    // behind the menu, so dropping it blacks out the screen.
    uint32_t marks[7];

    bool key_down() {
        return tooie::hotkeys::down(recompinput::GameInput::HIDE_HUD);
    }

    void worker() {
        bool was_down = false;
        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            bool down = key_down();
            if (down && !was_down) {
                tooie::hide_hud::set_hidden(!tooie::hide_hud::is_hidden());
            }
            was_down = down;
        }
    }
}

// Called from func_800A73F4 with the graphics context in $s1; its first word
// is the display list pointer.
extern "C" void tooie_draw2d_mark(uint8_t* rdram, recomp_context* ctx, int index) {
    gpr gfx_ctx = ctx->r17;
    if ((index == 3 || index == 5 || index == 6) && hidden.load(std::memory_order_relaxed)) {
        MEM_W(0, gfx_ctx) = (int32_t)marks[index - 1];
    }
    if (index == 0) {
        // The 3D scene is complete here: tag its model matrices for frame
        // interpolation (model_tagging.cpp), which may append to it.
        uint32_t end = (uint32_t)MEM_W(0, gfx_ctx);
        tooie::hd_shadows::fix_pastes(rdram, tooie::model_tagging::scene_start(), end & 0x1FFFFFFF);
        tooie::hd_shadows::fix_shadow_pose(rdram, tooie::model_tagging::scene_start(), end & 0x1FFFFFFF);
        uint32_t added = tooie::model_tagging::tag_scene(rdram, tooie::model_tagging::scene_start(), end & 0x1FFFFFFF);
        tooie::gfx_budget::note_tags(0, added);
        MEM_W(0, gfx_ctx) = (int32_t)(end + added);
        tooie::dl_dump::scene_end(rdram, end + added);
    }
    if (index == 6) {
        // The achievement pop-up goes on top of the game's 2D, shown even with the HUD hidden.
        tooie::achievements::draw_popup(rdram, ctx, (uint32_t)gfx_ctx);
        // The Transform Anywhere Menu, on top of everything else.
        tooie::transform_menu::draw(rdram, ctx, (uint32_t)gfx_ctx);
        // And the 2D after it: its panels and icons are also placed through
        // the projection (model_tagging.cpp).
        uint32_t end = (uint32_t)MEM_W(0, gfx_ctx);
        uint32_t added = tooie::model_tagging::tag_2d(rdram, marks[0] & 0x1FFFFFFF, end & 0x1FFFFFFF);
        tooie::gfx_budget::note_tags(1, added);
        MEM_W(0, gfx_ctx) = (int32_t)(end + added);
        tooie::dl_dump::frame_end(rdram, marks[0], end + added);
        tooie::gfx_budget::frame_end(rdram);
    }
    marks[index] = (uint32_t)MEM_W(0, gfx_ctx);
}

// The area name's draw: not while the HUD is hidden, nor while the Transform Anywhere Menu is up (the game stands
// still behind it, so the name would stay there half faded).
extern "C" int tooie_area_name_hidden(void) {
    return hidden.load(std::memory_order_relaxed) || tooie::transform_menu::is_open() ? 1 : 0;
}

void tooie::hide_hud::set_hidden(bool hide) {
    hidden = hide;
    tooie::toast::show(hide ? "HUD hidden" : "HUD shown");
}

bool tooie::hide_hud::is_hidden() {
    return hidden;
}

void tooie::hide_hud::start() {
    std::call_once(started, [] {
        if (const char* v = std::getenv("TOOIE_HIDE_HUD"); v != nullptr && v[0] == '1') {
            hidden = true;
        }
        std::thread(worker).detach();
    });
}
