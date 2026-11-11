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
// tooie::in_letterboxed_scene() tells other features (the cutscene skip) when a
// letterboxed scene camera, not the gameplay camera, is the one setting the FOV.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_field_of_view.h"
#include "tooie_game.h"
#include "tooie_hooks.h"
#include "tooie_photo_mode.h"
#include "tooie_rdram.h"
#include "tooie_water_camera.h"

namespace {
    constexpr uint32_t ctl_camera = 0x00;
    constexpr uint32_t ctl_mode = 0x16;
    constexpr int16_t mode_dynamic = 2;

    constexpr int max_cameras = 4;
    struct CameraMode {
        uint32_t camera = 0;
        bool gameplay = false;
    } modes[max_cameras];

    using tooie::rdram::read_float;
    using tooie::rdram::read_half;
    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;

    int offset(const std::string& id) {
        try {
            return (int)std::get<double>(recompui::config::get_graphics_config().get_option_value(id));
        } catch (...) {
            return 0;
        }
    }

    // 0 = no controller steps this camera (HUD icons), 1 = gameplay, 2 = any other controller mode.
    int camera_kind(uint32_t camera) {
        for (const CameraMode& m : modes) {
            if (m.camera == camera) {
                return m.gameplay ? 1 : 2;
            }
        }
        return 0;
    }

    // Last time a gameplay camera and a letterboxed scene camera set their FOV, for in_letterboxed_scene().
    std::atomic<int64_t> last_gameplay_ms{0};
    std::atomic<int64_t> last_letterbox_ms{0};
    constexpr uint32_t cam_aspect = 0xE8;

    int64_t now_ms() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();
    }

    bool log_enabled() {
        static const bool on = std::getenv("TOOIE_FOV_LOG") != nullptr;
        return on;
    }

    // tooie::field_of_view::set_override, in degrees; 0 when off.
    std::atomic<float> override_fov{0.0f};
}

void tooie::field_of_view::set_override(float degrees) {
    override_fov = degrees;
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
    // The water camera's touches last step are for the picture only; the game's update starts from its own camera.
    tooie::water_camera::give_back(rdram, camera);
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

    const int kind = camera_kind(camera);
    const bool gameplay = kind == 1;
    if (gameplay) {
        last_gameplay_ms = now_ms();
    } else if (kind == 2 && valid_ptr(camera) && read_float(rdram, camera + cam_aspect) > 1.5f) {
        // Cutscenes draw letterboxed: a camera driven by a non-gameplay controller with a wide aspect.
        last_letterbox_ms = now_ms();
    }
    const int add = offset(gameplay ? tooie::fov_offset_option : tooie::cutscene_fov_offset_option);
    float result = fov + (float)add;
    if (gameplay) {
        result = tooie::photo_mode::adjust_fov(result);
        if (const float held = override_fov.load(); held > 0.0f) {
            result = held;
        }
    }
    if (result < 8.0f) result = 8.0f;
    if (result > 150.0f) result = 150.0f;

    if (log_enabled()) {
        static float last_fov = -1.0f, last_result = -1.0f;
        static uint32_t last_camera = 0;
        if (fov != last_fov || result != last_result || camera != last_camera) {
            printf("[fov] camera %08X %s %.2f -> %.2f aspect %.2f\n", camera, gameplay ? "gameplay" : kind == 2 ? "scene" : "other", fov, result,
                valid_ptr(camera) ? read_float(rdram, camera + cam_aspect) : 0.0f);
            fflush(stdout);
            last_fov = fov; last_result = result; last_camera = camera;
        }
    }

    std::memcpy(&bits, &result, sizeof(bits));
    ctx->r5 = (int32_t)bits;
}

bool tooie::in_letterboxed_scene() {
    const int64_t letterbox = last_letterbox_ms.load();
    return letterbox != 0 && letterbox > last_gameplay_ms.load() && now_ms() - letterbox < 250;
}
