// Field of view (handoff 4.24).
//
// func_800CA558(camera, fov) is the game's viewport FOV setter: it stores the
// vertical FOV in degrees at camera+0xE4, 1/tan(fov/2) at +0xF4 (which
// func_800CB124 turns into the projection) and rebuilds the culling planes.
// banjotooie.us.toml hooks its entry, where the FOV is still in $a1, and this
// file adds the QOL offset there, so the projection and the culling agree.
//
// Which offset: func_8010FC38 steps each viewport's camera controller
// (+0x00 the viewport camera, +0x16 the mode, 2 = the dynamic gameplay camera).
// Its entry hook remembers each camera's mode; a camera last stepped in the
// dynamic mode gets the gameplay offset, any other camera (cutscenes, fixed
// boss and puzzle cameras) the cutscene offset. Cameras no controller steps
// (the 3D HUD icons) count as other too. The normal gameplay FOV is 40.
// TOOIE_FOV_LOG=1 logs each change.

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_hooks.h"

namespace {
    constexpr uint32_t ctl_camera = 0x00;
    constexpr uint32_t ctl_mode = 0x16;
    constexpr int16_t mode_dynamic = 2;

    constexpr int max_cameras = 4;
    struct CameraMode {
        uint32_t camera = 0;
        bool gameplay = false;
    } modes[max_cameras];

    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x80800000u;
    }

    uint32_t read_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }

    int16_t read_half(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<int16_t*>(rdram + ((addr ^ 2) - 0x80000000u));
    }

    int offset(const std::string& id) {
        try {
            return (int)std::get<double>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(id));
        } catch (...) {
            return 0;
        }
    }

    bool is_gameplay_camera(uint32_t camera) {
        for (const CameraMode& m : modes) {
            if (m.camera == camera) {
                return m.gameplay;
            }
        }
        return false;
    }

    bool log_enabled() {
        static const bool on = std::getenv("TOOIE_FOV_LOG") != nullptr;
        return on;
    }
}

extern "C" void tooie_camera_controller_step(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t ctl = (uint32_t)ctx->r4;
    if (!valid_ptr(ctl)) {
        return;
    }
    const uint32_t camera = read_word(rdram, ctl + ctl_camera);
    if (!valid_ptr(camera)) {
        return;
    }
    const bool gameplay = read_half(rdram, ctl + ctl_mode) == mode_dynamic;
    CameraMode* slot = nullptr;
    for (CameraMode& m : modes) {
        if (m.camera == camera) {
            slot = &m;
            break;
        }
        if (slot == nullptr && m.camera == 0) {
            slot = &m;
        }
    }
    if (slot == nullptr) {
        slot = &modes[0];
    }
    slot->camera = camera;
    slot->gameplay = gameplay;
}

extern "C" void tooie_set_fov(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t camera = (uint32_t)ctx->r4;
    float fov;
    uint32_t bits = (uint32_t)ctx->r5;
    std::memcpy(&fov, &bits, sizeof(fov));

    const bool gameplay = is_gameplay_camera(camera);
    const int add = offset(gameplay ? tooie::fov_offset_option : tooie::cutscene_fov_offset_option);
    float result = fov + (float)add;
    if (result < 10.0f) result = 10.0f;
    if (result > 150.0f) result = 150.0f;

    if (log_enabled()) {
        static float last_fov = -1.0f, last_result = -1.0f;
        static uint32_t last_camera = 0;
        if (fov != last_fov || result != last_result || camera != last_camera) {
            printf("[fov] camera %08X %s %.2f -> %.2f\n", camera, gameplay ? "gameplay" : "other", fov, result);
            fflush(stdout);
            last_fov = fov; last_result = result; last_camera = camera;
        }
    }

    std::memcpy(&bits, &result, sizeof(bits));
    ctx->r5 = (int32_t)bits;
}
