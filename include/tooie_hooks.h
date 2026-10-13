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
void tooie_transition_frame(uint8_t* rdram, recomp_context* ctx);
void tooie_transition_anim_length(uint8_t* rdram, recomp_context* ctx);

#ifdef __cplusplus
}
#endif

#endif
