// Screen wipes in wide pictures.
//
// The Jiggy-shaped level wipe (and the other shaped wipes, types 5 and 6 in
// gctransitionDll) is a model drawn in front of its own camera, zooming from a
// small hole to one that clears the screen, or back. func_80800098_gctransitionDll
// sizes it for the picture: scale * 0.75 * viewport aspect, which is 1 at 4:3
// and larger in the game's own widescreen mode, so the hole still clears the
// sides at the end.
//
// With Aspect Ratio set to Expand (or Letterbox 16:9) RT64 widens the picture
// but the game still sees a 4:3 viewport, so the wipe stopped at a 4:3-sized
// hole: on a wide screen the opening wipe ended with black still at the sides
// and then vanished. banjotooie.us.toml hooks the store of the scale and this
// widens it by as much as RT64 widens the picture, the same thing the game
// does for its own widescreen mode.

#include "recomp.h"
#include "tooie_game.h"
#include "tooie_hooks.h"

// func_80800098_gctransitionDll, before the scale in $f10 is stored.
extern "C" void tooie_wipe_model_scale(uint8_t* rdram, recomp_context* ctx) {
    ctx->f10.fl *= tooie::widescreen_scale();
}
