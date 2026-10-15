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
// Heap guard (src/game/heap_guard.cpp): repairs a broken heap block link before func_8001C0A0 walks the list.
void tooie_heap_guard(uint8_t* rdram, recomp_context* ctx);

void tooie_warp_tick(uint8_t* rdram, recomp_context* ctx);
// Asset replacement (src/game/asset_mods.cpp): in func_800D5B34 before it fetches an asset; 1 when a mod file was loaded instead.
int tooie_asset_replace(uint8_t* rdram, recomp_context* ctx);
// Game frame rate (src/game/game_frame_rate.cpp): the wait between frames in func_800151BC, and the time step in func_800D8FA0.
void tooie_frame_wait(uint8_t* rdram, recomp_context* ctx);
void tooie_frame_swapped(uint8_t* rdram, recomp_context* ctx);
void tooie_frame_step(uint8_t* rdram, recomp_context* ctx);
void tooie_frame_step_done(uint8_t* rdram, recomp_context* ctx);
void tooie_frame_seconds(uint8_t* rdram, recomp_context* ctx);
void tooie_vi_client_filter(uint8_t* rdram, recomp_context* ctx);
void tooie_vi_client_sent(uint8_t* rdram, recomp_context* ctx);
int tooie_scheduler_vi_skip(uint8_t* rdram, recomp_context* ctx);
int tooie_portrait_step_skip(uint8_t* rdram, recomp_context* ctx);
void tooie_audio_list_queued(uint8_t* rdram, recomp_context* ctx);
int tooie_blink_step_skip(uint8_t* rdram, recomp_context* ctx);
void tooie_vi_hang_limit(uint8_t* rdram, recomp_context* ctx);
void tooie_demo_frame(uint8_t* rdram, recomp_context* ctx);
void tooie_flag_get_enter(uint8_t* rdram, recomp_context* ctx);
void tooie_flag_get_leave(uint8_t* rdram, recomp_context* ctx);
void tooie_hud_element_begin(uint8_t* rdram, recomp_context* ctx);
void tooie_hud_element_end(uint8_t* rdram, recomp_context* ctx);
void tooie_dialogue_timer_advanced(uint8_t* rdram, recomp_context* ctx);
// Hide HUD (src/game/hide_hud.cpp): marks between the 2D draw calls of func_800A73F4.
void tooie_draw2d_mark(uint8_t* rdram, recomp_context* ctx, int index);
void tooie_scene_begin(uint8_t* rdram, recomp_context* ctx);
// Achievements (src/game/achievements.cpp): an enemy hit in func_80108F08, an Inky starting to freeze.
void tooie_ach_enemy_hit(uint8_t* rdram, recomp_context* ctx);
void tooie_ach_octopus_frozen(uint8_t* rdram, recomp_context* ctx);
void tooie_transition_frame(uint8_t* rdram, recomp_context* ctx);
void tooie_transition_anim_length(uint8_t* rdram, recomp_context* ctx);
void tooie_distance_probe(uint8_t* rdram, recomp_context* ctx, int squared);
// Free camera (src/gameplay/free_camera.cpp): after a camera controller's mode has placed the camera.
void tooie_free_camera(uint8_t* rdram, recomp_context* ctx);
// High-detail models (src/gameplay/high_detail_models.cpp): $f0 holds a geo LOD command's squared camera distance.
void tooie_lod_distance(uint8_t* rdram, recomp_context* ctx);
// Same file: $a0 is the Banjo-Kazooie detail level func_80093F30 is asked for.
void tooie_banjo_detail(uint8_t* rdram, recomp_context* ctx);
// HD shadows (src/gameplay/hd_shadows.cpp): func_800A6250 has the shadow model at $sp+0x1C8 and the on-screen model at $sp+0x1C4.
void tooie_player_shadow_model(uint8_t* rdram, recomp_context* ctx);
// Same file: func_80101808's entry ($a1 is the draw callback) and just after it draws the actor ($s0) model.
void tooie_actor_draw_begin(uint8_t* rdram, recomp_context* ctx);
void tooie_actor_shadow(uint8_t* rdram, recomp_context* ctx);
void tooie_shadow_render_mode(uint8_t* rdram, recomp_context* ctx);
void tooie_shadow_note_model(uint8_t* rdram, recomp_context* ctx);
// Extended draw distance (src/display/draw_distance.cpp): $v0 holds func_800D2F20's model draw distance.
void tooie_model_draw_distance(uint8_t* rdram, recomp_context* ctx);
// Extended draw distance: $f20 is func_800D3104's cell gather radius, $f2 func_800D2F44's cell distance.
void tooie_cell_draw_radius(uint8_t* rdram, recomp_context* ctx);
void tooie_cell_draw_distance(uint8_t* rdram, recomp_context* ctx);
// Back-Port: Get Jiggy animation (src/gameplay/jiggy_dance.cpp): bsjig's Jiggy pose init has just started animation 0x282; $s0 is the player.
void tooie_jiggy_dance_init(uint8_t* rdram, recomp_context* ctx);
// Extended draw distance: $f12 is an actor's own draw distance (func_80101970), about to be set.
void tooie_actor_draw_distance(uint8_t* rdram, recomp_context* ctx);
// Field of view (src/gameplay/field_of_view.cpp): a camera controller step, and the FOV setter func_800CA558.
void tooie_camera_controller_step(uint8_t* rdram, recomp_context* ctx);
void tooie_set_fov(uint8_t* rdram, recomp_context* ctx);
// Wide pictures (src/game/wide_transitions.cpp).
void tooie_wipe_model_scale(uint8_t* rdram, recomp_context* ctx);
// Canary Mary races (src/gameplay/canary_mary.cpp): nonzero when the host ran Mary's speed rule
// instead of the game. race 0 is the mine cart race, 1 the Cloud Cuckooland race.
int tooie_canary_mary_rule(uint8_t* rdram, recomp_context* ctx, int race);
// Split up anywhere (src/gameplay/player_cheats.cpp): around the split-up pad search in Banjo's split-up
// state; after = 0 before the search, 1 after it.
void tooie_split_pad_search(uint8_t* rdram, recomp_context* ctx, int after);
// The game's should-they-join-up check (func_8008D40C): -1 to run it, otherwise its answer.
int tooie_split_join_check(uint8_t* rdram, recomp_context* ctx);
// Hold to run (src/gameplay/hold_to_run.cpp): $a1 is the target speed baphysics_set_target_horizontal_velocity sets.
void tooie_run_target_speed(uint8_t* rdram, recomp_context* ctx);
// Same file: $v0 is the animation file about to be evaluated for the animation in $s0.
void tooie_run_anim_file(uint8_t* rdram, recomp_context* ctx);
// Totals checklist (src/gameplay/totals_checklist.cpp): end of the pause menu's draw
// (gcnewpause_entrypoint_3); $s0 is the PauseState, 0x20($sp) the display list pointer's address.
void tooie_totals_checklist_draw(uint8_t* rdram, recomp_context* ctx);
// Whether Hide HUD (or photo mode) has the HUD hidden (src/game/hide_hud.cpp).
int tooie_hud_hidden(void);
// Whether photo mode has the players hidden (src/gameplay/photo_mode.cpp).
int tooie_players_hidden(void);

// Sound > Mix rate (src/gameplay/mix_rate.cpp): hooks in the audio manager's setup and frame code.
void tooie_mix_rate_heap(uint8_t* rdram, recomp_context* ctx);
void tooie_mix_rate_frequency(uint8_t* rdram, recomp_context* ctx);
void tooie_mix_rate_buffers(uint8_t* rdram, recomp_context* ctx);
void tooie_mix_rate_queue_length(uint8_t* rdram, recomp_context* ctx);
void tooie_mix_rate_frame_size(uint8_t* rdram, recomp_context* ctx);
void tooie_mix_rate_pitch_begin(uint8_t* rdram, recomp_context* ctx);
void tooie_mix_rate_pitch_end(uint8_t* rdram, recomp_context* ctx);
// More game memory (src/game/more_memory.cpp): nonzero to use the bigger heap, frame buffers and
// animation caches (hand edits in the generated code, banjotooie.us.toml).
int tooie_more_memory(void);

#ifdef __cplusplus
}
#endif

#endif
