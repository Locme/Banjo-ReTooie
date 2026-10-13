#ifndef __TOOIE_HOOKS_H__
#define __TOOIE_HOOKS_H__

// Host functions called from hooks in banjotooie.us.toml. Included by every
// generated file, so this must stay valid C.

#include "recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

void tooie_read_overlay_key(uint8_t* rdram, recomp_context* ctx);
void tooie_overlay_placed(uint8_t* rdram, recomp_context* ctx);
void tooie_overlay_unloading(uint8_t* rdram, recomp_context* ctx);
void tooie_preempt_point(uint8_t* rdram, recomp_context* ctx);

void tooie_warp_tick(uint8_t* rdram, recomp_context* ctx);
void tooie_flag_get_enter(uint8_t* rdram, recomp_context* ctx);
void tooie_flag_get_leave(uint8_t* rdram, recomp_context* ctx);
void tooie_hud_element_begin(uint8_t* rdram, recomp_context* ctx);
void tooie_hud_element_end(uint8_t* rdram, recomp_context* ctx);
void tooie_dialogue_timer_advanced(uint8_t* rdram, recomp_context* ctx);
// Hide HUD (src/game/hide_hud.cpp): marks between the 2D draw calls of func_800A73F4.
void tooie_draw2d_mark(uint8_t* rdram, recomp_context* ctx, int index);
void tooie_scene_begin(uint8_t* rdram, recomp_context* ctx);
void tooie_transition_frame(uint8_t* rdram, recomp_context* ctx);
void tooie_transition_anim_length(uint8_t* rdram, recomp_context* ctx);
void tooie_distance_probe(uint8_t* rdram, recomp_context* ctx, int squared);
// Free camera (src/gameplay/free_camera.cpp): after a camera controller's mode has placed the camera.
void tooie_free_camera(uint8_t* rdram, recomp_context* ctx);
// High-detail models (src/gameplay/high_detail_models.cpp): $f0 holds a geo LOD command's squared camera distance.
void tooie_lod_distance(uint8_t* rdram, recomp_context* ctx);
// Extended draw distance (src/display/draw_distance.cpp): $v0 holds func_800D2F20's model draw distance.
void tooie_model_draw_distance(uint8_t* rdram, recomp_context* ctx);
// Field of view (src/gameplay/field_of_view.cpp): a camera controller step, and the FOV setter func_800CA558.
void tooie_camera_controller_step(uint8_t* rdram, recomp_context* ctx);
void tooie_set_fov(uint8_t* rdram, recomp_context* ctx);
// Wide pictures (src/game/wide_transitions.cpp).
void tooie_wipe_model_scale(uint8_t* rdram, recomp_context* ctx);
// Canary Mary races (src/gameplay/canary_mary.cpp): nonzero when the host ran Mary's speed rule
// instead of the game. race 0 is the mine cart race, 1 the Cloud Cuckooland race.
int tooie_canary_mary_rule(uint8_t* rdram, recomp_context* ctx, int race);

#ifdef __cplusplus
}
#endif

#endif
