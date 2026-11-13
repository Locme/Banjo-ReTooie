// Photo mode (handoff 4.82).
//
// Freeze: func_800D8FA0 turns the VIs the last frame took into the frame's delta time, kept as a
// float at 0x8012C760 (func_800D8FF8 returns it). tooie_warp_tick runs at the start of the game's
// frame update (func_800A7D84), after that, so photo mode scales the value there: almost nothing
// while frozen, 1/167, 1/8 or 1/4 of it in slow time. Everything the game moves by delta time stands
// still, and the world is still drawn every frame, so the camera can move. (Things the game moves
// by a fixed step per frame can keep moving.)
//
// Camera: func_8010FC38 steps each viewport's camera controller; the free camera's hook in it
// (tooie_free_camera) calls place_camera, which writes the viewport camera's position (+0x00) and
// pitch / yaw / roll (+0x18, +0x1C, +0x20, degrees) after the game's camera has updated. Facing: yaw 0 looks
// along -z, the yaw grows turning left, and a positive pitch looks up.
//
// Input: while photo mode is on, player 1's pad goes to the camera and the game reads an idle pad.
//   left stick      move (forward, back, sideways)
//   right stick     look (C-buttons on the keyboard)
//   Z / R           down / up
//   (holding a move for a second speeds it up)
//   A               screenshot (as F12), after the self-timer if one is set
//   D-pad up/down   pick a row of the photo panel (src/ui/photo_panel.cpp)
//   D-pad left/right change it (held repeats): zoom (the field of view, through tooie_set_fov), camera
//                   (free, or orbit Banjo: the sticks circle him, Z / R move closer and further), collision on or off, time,
//                   HUD, Banjo shown or hidden, his pose and the point in it, the others shown or hidden, the filter rows below, depth of field, tilt, crop, grid
//   L               show / hide the photo panel
//   Start           frozen, 1/167 speed, 1/8 speed, 1/4 speed
//   B / Photo Mode  back to the game, with the camera and HUD as they were
//   mouse           looks (as the right stick), the wheel zooms, a left click is A (unless a game button is
//                   bound to that mouse button)
//
// Pose grid (A on the Pose row): a 4 x 5 page of pose cards, each a short film of Banjo in the pose; the D-pad
// (or the wheel) moves over them and Banjo wears the one under the cursor, L / R turn the page, A keeps it, B puts
// back the pose he had, Start takes the cards again. The cards are taken by photo mode on this PC (see "Pose cards"
// below); the photo panel draws the grid.
//
// Shutter (QOL > Photo shutter, on by default): each photo plays a camera click (synthesised, mixed into
// the game's sound by mix_shutter from main.cpp) and the photo panel flashes the screen white; the flash
// is a UI layer, so the photo itself never shows it. The Timer row (Off, 3 s, 10 s) counts down with
// toasts before the photo; A again cancels it.
//
// Others (hidden: enemies, NPCs, items, doors and other moving parts): banjotooie.us.toml hooks func_800EC7D4, the draw of
// each actor in an object pass's list, to skip it while tooie_others_hidden().
//
// Poses: the Pose row swaps Banjo's animation (his anim controller from baanim_getAnimCtrlPtr, set up as the
// game's own state inits do) and the Pose frame row holds it at a point (the animation's timer, anctrl +0x2C)
// while time is frozen. His own animation is put back on leaving or on picking "Game".
//
// Hide Banjo: func_800F5008 draws the players each frame (opaque ones at once, faded ones listed for
// func_800F50D0 to draw later); banjotooie.us.toml hooks both to skip them while tooie_players_hidden().
//
// Border (QOL > Photo border): a frame drawn by the same pass over the edge of the crop frame and kept in
// screenshots: instant photo, film strip, honeycomb, Jiggy (gold puzzle knobs) or wooden (the menus' look).
//
// Filters (QOL > Photo filter rows): a look, exposure, contrast, saturation, warmth, vignette and grain,
// drawn by RT64's photo grade pass (lib-patches/rt64.patch) only while photo mode is on, so screenshots
// show them. They can be changed from the photo panel or the menu while photo mode is on, as can
// QOL > Photo tilt (the camera's roll); the panel writes the same options, so both stay in step.
//
// Collision (the photo panel's Collision row, on by default): each move is swept with the game's
// camera line test (tooie::free_camera::sweep_line); a hit stops the camera at the surface and the
// rest of the move slides along it. In orbit the line from Banjo to the camera pulls it in instead.
//
// Headless test hook: TOOIE_PHOTO=<on ms>:<off ms> enters and leaves photo mode at those times after
// the game loop first runs. TOOIE_PHOTO_LOG=1 logs the photo camera.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <functional>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <variant>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "recompinput/input_binding.h"
#include "recompinput/input_state.h"
#include "recompinput/profiles.h"
#include "tooie_debug.h"
#include "tooie_free_camera.h"
#include "tooie_game.h"
#include "tooie_hide_hud.h"
#include "tooie_photo_mode.h"
#include "tooie_pose_puppets.h"
#include "tooie_game_frame_rate.h"
#include "tooie_picture_filters.h"
#include "tooie_screenshot.h"
#include "tooie_toast.h"
#include "tooie_hotkeys.h"
#include "tooie_progress_cheats.h"
#include "tooie_motion_aim.h"
#include "librecomp/game.hpp"
#include "recompui/recompui.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#define STBI_ONLY_PNG
#include "../../lib/rt64/src/contrib/stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_STATIC
#include "../../lib/rt64/src/contrib/stb/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_STATIC
#include "../../lib/rt64/src/contrib/stb/stb_image_resize2.h"

namespace RT64 {
    // lib/rt64/src/hle/rt64_present_queue.h (from lib-patches/rt64.patch): the next frame's game picture.
    typedef std::function<void(uint32_t width, uint32_t height, std::vector<uint8_t> &&rgba)> ScreenshotCallback;
    void RequestScreenshot(ScreenshotCallback callback);
    void RequestScreenshotRegion(float x0, float y0, float x1, float y1, ScreenshotCallback callback);
    // rt64-ext/src/render/rt64_photo_grade.h.
    void SetPhotoGrade(bool enabled, uint32_t look, float exposure, float contrast, float saturation, float warmth, float vignette, float grain);
    void SetPhotoFrame(float cropAspect, bool grid);
    void SetPhotoDepthOfField(float strength, uint32_t depthAddress);
    void SetPhotoFocus(float x, float y);
    void SetPhotoBorder(uint32_t border);
}

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;

    constexpr auto photo_input = recompinput::GameInput::PHOTO_MODE;
    constexpr auto poll_interval = 10ms;

    constexpr gpr game_state_addr = (int32_t)0x80127630;
    constexpr uint32_t game_state_playing = 3;
    constexpr gpr delta_time_addr = (int32_t)0x8012C760;

    constexpr uint32_t cam_pos = 0x00;
    constexpr uint32_t cam_rot = 0x18;

    constexpr uint16_t button_a = 0x8000, button_b = 0x4000, button_z = 0x2000, button_start = 0x1000;
    constexpr uint16_t d_up = 0x0800, d_down = 0x0400, d_left = 0x0200, d_right = 0x0100;
    constexpr uint16_t button_l = 0x0020, button_r = 0x0010;
    constexpr uint16_t c_up = 0x0008, c_down = 0x0004, c_left = 0x0002, c_right = 0x0001;

    // Units and degrees per second.
    constexpr float move_speed = 600.0f;
    constexpr float look_speed = 90.0f;
    constexpr float fast_factor = 3.0f;
    constexpr float stick_deadzone = 0.15f;
    constexpr float max_pitch = 89.0f;
    constexpr float deg = 3.14159265f / 180.0f;
    // The game's delta time while frozen: not zero, as some code divides by it, but small enough that
    // adding it to a timer changes nothing. (It was 0.0001 s, which at 60 FPS ran time at 0.0001 / (1/60)
    // = 0.006 of normal speed, about 1/167: still moving. That speed is kept as its own step, L, 2026-10-16.)
    constexpr float frozen_delta = 1.0e-7f;
    constexpr float speed_scales[] = { 0.0f, 0.006f, 0.125f, 0.25f };
    constexpr const char* speed_names[] = { "Time frozen", "Time 1/167", "Time 1/8", "Time 1/4" };
    constexpr const char* speed_values[] = { "Frozen", "1/167 speed", "1/8 speed", "1/4 speed" };
    constexpr int speed_count = (int)std::size(speed_scales);
    // Orbit: the point circled is Banjo's position plus this much, at these distances.
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t player_transform = 0xE4;
    constexpr float orbit_height = 60.0f;
    constexpr float min_orbit = 100.0f, max_orbit = 6000.0f;
    // Zoom: the field of view is multiplied by this, changed by this much per second.
    // How far the camera keeps off a surface it hit.
    constexpr float surface_gap = 2.0f;
    constexpr float min_fov_scale = 0.2f, max_fov_scale = 2.0f, fov_rate = 0.8f;

    std::once_flag started;

    // Requests from the key thread and the input path, carried out on the game thread.
    std::atomic<bool> toggle_requested{false};
    std::atomic<bool> leave_requested{false};
    std::atomic<bool> is_active{false};
    std::atomic<int> speed{0};
    std::atomic<bool> orbit_toggle{false};
    std::atomic<bool> players_toggle{false};
    std::atomic<bool> players_hidden{false};
    // Others row: every other actor (enemies, NPCs, items, doors and other moving parts) hidden.
    std::atomic<bool> others_hidden{false};
    std::atomic<float> fov_scale{1.0f};
    // The game's own delta time this frame, before photo mode scaled it (for the log).
    std::atomic<float> game_delta{0.0f};

    // The photo panel: its rows, the one picked, whether it is shown, and a change waiting for the game
    // thread (-1 or +1 on the picked row).
    enum class Row { Zoom, Camera, Collision, Time, Hud, Banjo, Character, Pose, PoseFrame, Mirror, Others, Timer, Shutter, Filter, Exposure, Contrast, Saturation, Warmth,
        Vignette, Grain, Focus, FocusPoint, Tilt, Crop, Border, Grid, Album, Count };
    constexpr int row_count = (int)Row::Count;
    std::atomic<int> picked{0};
    std::atomic<bool> panel_shown{true};
    std::atomic<int> pending_step{0};
    std::atomic<bool> orbit_on{false};
    // Mirror: the character photographed flipped left to right. It is drawn by the stand-in
    // (tooie::pose_puppets::set_mirror), the player's own form too (in his own look and animation), so the game's own
    // Banjo is never touched.
    std::atomic<bool> mirror_on{false};
    // Depth of field's focus point: the middle, Banjo, or one of the rule-of-thirds points.
    enum class Focus { Middle, Banjo, TopLeft, TopRight, BottomLeft, BottomRight, Count };
    constexpr const char* focus_names[] = { "Middle", "Banjo", "Top left", "Top right", "Bottom left", "Bottom right" };
    std::atomic<int> focus_choice{0};
    // The field of view the game last set while photo mode was on (degrees, vertical), to find Banjo on screen.
    std::atomic<float> last_fov{45.0f};
    // Banjo's middle, above his feet.
    constexpr float banjo_middle = 45.0f;

    // Poses: Banjo's animation swapped for one of these and held at a point in it (Pose frame, 0 to 1).
    // "Game" leaves him as he was. Leaving photo mode puts his own animation back.
    struct PoseChoice {
        const char* name;
        uint32_t anim;
    };
    // Banjo and Kazooie together (the game's own form 0x1).
    constexpr PoseChoice bk_poses[] = {
        { "Game", 0 },
        // Picked from a headless sweep of animations 0x1-0x17E on Banjo (names describe the look).
        { "Walk", 0x3 },
        { "Run", 0xC },
        { "Jump", 0x17 },
        { "Big stride", 0x14A },
        { "Kick", 0xAB },
        { "Crouch", 0x2A },
        { "Lie down", 0x5A },
        { "Jiggy jig", 0x2E },
        { "Wings out", 0x14 },
        { "Kazooie up", 0x1B },
        { "Kazooie dash", 0x47 },
        { "Kazooie lunge", 0x166 },
        { "Talon trot", 0x3C },
        // More from photo mode's own pose cards of every animation 0x1-0x17E (`photo develop`, 2026-11-12): the ones
        // that read clearly as Banjo and Kazooie (most above 0xC0 are other forms' and show him in his bind pose).
        { "Look around", 0x1 },
        { "Cheer", 0x6 },
        { "Roll", 0x9 },
        { "Swim", 0x10 },
        { "Somersault", 0x1C },
        { "Backflip", 0x1D },
        { "Slide", 0x1F },
        { "Swipe", 0x21 },
        { "Ta-da", 0x25 },
        { "Peck", 0x2B },
        { "Crawl", 0x3F },
        { "Dive", 0x46 },
        { "High kick", 0x48 },
        { "Sit", 0x49 },
        { "Kneel", 0x59 },
        { "Break dance", 0x7D },
        { "Cartwheel", 0x97 },
        { "Handstand", 0x9C },
        { "Lift high", 0xB0 },
        { "Lie back", 0xBA },
        { "Victory", 0xCC },
        { "Scratch head", 0xF6 },
    };

    // Each character's own animations only: those its own player states play (the constant each bs<form> state passes to
    // baanim_playForDuration_*, read from RecompiledFuncs), and ids inside its own run of them that no other form's code
    // plays, plus the other animation ids its state code sets up (found by looking at every constant those functions pass,
    // then checked on each form's own pose cards). An animation is not tied to one skeleton (Banjo's play on Mumbo and
    // the Bee too), so how well it moves a model says nothing of whose it is; small ids (under about 0x60) that turn up
    // in a form's code are Banjo and Kazooie's own and are left out.
    //
    // Banjo alone (after Split Up): Pack Whack, the Shack Pack, the Snooze Pack, the sack and swimming (bsban*).
    constexpr PoseChoice banjo_poses[] = {
        { "Standing", 0 },
        { "Jump", 0x27B },
        { "Pack Whack", 0xAF },
        { "Shack Pack", 0x145 },
        { "In The Pack", 0x293 },
        { "Snooze In", 0x276 },
        { "Snooze Pack", 0x278 },
        { "Sack In", 0x143 },
        { "Sack Hop", 0x289 },
        { "Sack Jump", 0x28A },
        { "Sack Stand", 0x28B },
        { "Sack Turn", 0x28C },
        { "Swim", 0x27D },
        { "Swim Kick", 0x27E },
        { "Backflip", 0x27B },
        { "Sack Shuffle", 0x144 },
        { "Peek From The Pack", 0x294 },
        { "Out Of The Pack", 0x295 },
    };
    // Kazooie alone: her own states (bskaz*): standing, flying, gliding, Wing Whack, paddling, jumping, hatching,
    // springing, the stilts, Torpedo and the egg shots.
    constexpr PoseChoice kazooie_poses[] = {
        { "Standing", 0 },
        { "Look About", 0xA5 },
        { "Preen", 0xAC },
        { "Stretch", 0xAD },
        { "Look Around", 0x24B },
        { "Shake", 0x24E },
        { "Take Off", 0xAA },
        { "Fly Up", 0xAB },
        { "Fly", 0x11D },
        { "Dive", 0x11E },
        { "Glide", 0x11C },
        { "Swoop", 0x13D },
        { "Flap", 0x13E },
        { "Flutter", 0x29D },
        { "Breathe Fire", 0xE1 },
        { "Wing Whack", 0x137 },
        { "Wing Spin", 0x138 },
        { "Paddle", 0x139 },
        { "Paddle About", 0x13A },
        { "Jump", 0x13B },
        { "Leap", 0x13C },
        { "Hatch", 0x13F },
        { "Hatching", 0x140 },
        { "Crouch", 0x141 },
        { "Low Crouch", 0x28F },
        { "Spring", 0x142 },
        { "Spring Jump", 0x24C },
        { "Wings Up", 0x288 },
        { "Stilts", 0x149 },
        { "Stilt Step", 0x27F },
        { "Stilt Walk", 0x280 },
        { "Torpedo", 0x133 },
        { "Torpedo Turn", 0x134 },
        { "Egg Shot", 0x28D },
        { "Egg Drop", 0x28E },
    };
    // Mumbo: his own states (bsmum*: still, walking, his staff, casting, falling flat).
    constexpr PoseChoice mumbo_poses[] = {
        { "Standing", 0 },
        { "Look About", 0xB6 },
        { "Walk", 0xBB },
        { "Run", 0xBC },
        { "Jump", 0xBD },
        { "Staff Swing", 0x9F },
        { "Cast A Spell", 0xFB },
        { "Mumbo Magic", 0xFC },
        { "Big Spell", 0x4A1 },
        { "Fall Flat", 0xCB },
        { "Stretch", 0xB7 },
        { "Twirl", 0xB8 },
        { "Tiptoe", 0xB3 },
        { "Stride", 0xB4 },
        { "Swim", 0x9C },
        { "Paddle", 0x9D },
    };
    // The Bee (Humba Wumba's, Cloud Cuckooland): its own states (bsbee*).
    constexpr PoseChoice bee_poses[] = {
        { "Hovering", 0 },
        { "Take Off", 0x1DC },
        { "Buzz", 0x1DD },
        { "Fly", 0x1DF },
        { "Stung", 0x1E1 },
        { "Hat Off", 0x1E2 },
    };
    // Humba Wumba's other forms: their own states' animations (bsstonehead, bstnt, bsvan, bssub, bstrex*, bswasher,
    // bssnowball).
    constexpr PoseChoice stony_poses[] = {
        { "Standing", 0 },
        { "Hop", 0x62 },
        { "Leap", 0x64 },
        { "Stomp", 0x122 },
    };
    constexpr PoseChoice detonator_poses[] = {
        { "Standing", 0 },
        { "Walk", 0xE2 },
        { "Fuse", 0xE3 },
        { "Spin", 0xE6 },
        { "Swim", 0xE7 },
        { "Paddle", 0xE8 },
        { "Wobble", 0x107 },
        { "Hop", 0x108 },
        { "Tip Over", 0x10E },
        { "Bounce", 0x111 },
    };
    constexpr PoseChoice van_poses[] = {
        { "Parked", 0 },
        { "Drive", 0xEC },
        { "Honk", 0xF1 },
        { "Bounce", 0xF2 },
        { "Float", 0xE7 },
        { "Paddle", 0xE8 },
        { "Tumble", 0xD7 },
        { "Wheelie", 0xED },
        { "Rev", 0x115 },
        { "Head On", 0x116 },
        { "Rock", 0x11A },
        { "Squash", 0x11D },
    };
    constexpr PoseChoice sub_poses[] = {
        { "Floating", 0 },
        { "Dive", 0x12F },
        { "Surface", 0x130 },
    };
    constexpr PoseChoice baby_trex_poses[] = {
        { "Standing", 0 },
        { "Walk", 0x1CE },
        { "Run", 0x1CF },
        { "Roar", 0x1D0 },
        { "Big Roar", 0x1D1 },
        { "Tumble", 0x148 },
    };
    constexpr PoseChoice daddy_trex_poses[] = {
        { "Standing", 0 },
        { "Walk", 0x1CE },
        { "Run", 0x1CF },
        { "Roar", 0x1D0 },
        { "Big Roar", 0x1D1 },
    };
    constexpr PoseChoice washer_poses[] = {
        { "Standing", 0 },
        { "Spin", 0x354 },
        { "Hop", 0x357 },
        { "Wash", 0x359 },
        { "Shuffle", 0x355 },
    };
    constexpr PoseChoice snowball_poses[] = {
        { "Rolling", 0 },
        { "Roll", 0x5F },
    };
    // Golden Goliath (Mumbo's, Mayahem Temple): its own states (bsstatue).
    constexpr PoseChoice goliath_poses[] = {
        { "Standing", 0 },
        { "Walk", 0x1E5 },
        { "Arm Swing", 0x1EF },
        { "Kick", 0x1F0 },
        { "Look About", 0x1F1 },
    };

    // Characters (the Character row): who is photographed. The player's own form is posed as before; any other is a
    // stand-in, drawn where the player stands by tooie::pose_puppets::stand_in while photo mode hides him, so nothing
    // changes in the game and there is nothing to undo on leaving (the game's own way to change form reloads the area
    // and sends Banjo back to its entrance). Each has its own animations only. A character shows once the save has
    // unlocked it (the flags transform_menu.cpp reads; gameflags.h's for Mumbo's pad and Golden Goliath; for Dragon
    // Kazooie 0x34E, her first change at Humba's pool, which stays set when she changes back), and the
    // player's own form always does.
    struct Character {
        const char* name;
        uint16_t form;          // the game's form id (the player's +0xA0 block +0x29); Dragon Kazooie is Kazooie's
                                // (0x0B) with dragon_form added, since the game keeps her in a save flag, not a form
        uint16_t model;         // the form's model asset, as the Transform menu's statues use them (not always the id in the
                                // player's model state: Banjo alone has 0x607 there, which is no model to draw)
        uint16_t idle;          // its standing animation, worn by a stand-in on "Game"
        int32_t flag;           // the save-file flag that unlocks it, -1 for always
        const PoseChoice* poses;
        int pose_count;
        float card_size;        // the card camera's distance and height for it, times Banjo's
    };
#define TOOIE_POSES(list) list, (int)std::size(list)
    constexpr Character characters[] = {
        { "Banjo & Kazooie", 0x01, 0x61F, 0x6F, -1, TOOIE_POSES(bk_poses), 1.0f },
        { "Banjo", 0x0A, 0x62A, 0x6F, 0x4F5, TOOIE_POSES(banjo_poses), 1.0f },
        { "Kazooie", 0x0B, 0x61C, 0xA4, 0x4F5, TOOIE_POSES(kazooie_poses), 1.0f },
        { "Mumbo", 0x0D, 0x665, 0xB5, 0x09A, TOOIE_POSES(mumbo_poses), 1.1f },
        { "Stony", 0x08, 0x61D, 0x63, 0x346, TOOIE_POSES(stony_poses), 1.3f },
        { "Detonator", 0x0F, 0x623, 0xE5, 0x347, TOOIE_POSES(detonator_poses), 1.0f },
        { "Van", 0x10, 0x624, 0xEE, 0x348, TOOIE_POSES(van_poses), 1.6f },
        { "Submarine", 0x0C, 0x626, 0x12E, 0x349, TOOIE_POSES(sub_poses), 1.5f },
        { "Baby T-Rex", 0x12, 0x609, 0x1D2, 0x34A, TOOIE_POSES(baby_trex_poses), 1.3f },
        { "Daddy T-Rex", 0x13, 0x60D, 0x1D2, 0x345, TOOIE_POSES(daddy_trex_poses), 3.5f },
        { "Washing Machine", 0x07, 0x60C, 0x356, 0x34B, TOOIE_POSES(washer_poses), 1.2f },
        { "Snowball", 0x02, 0x60B, 0x5E, 0x34C, TOOIE_POSES(snowball_poses), 1.3f },
        { "Bee", 0x06, 0x613, 0x1DE, 0x34D, TOOIE_POSES(bee_poses), 0.9f },
        { "Golden Goliath", 0x0E, 0x673, 0x1EE, 0x050, TOOIE_POSES(goliath_poses), 5.0f },
        { "Dragon Kazooie", 0x0B | 0x100, 0x62E, 0xA4, 0x34E, TOOIE_POSES(kazooie_poses), 1.0f },
    };
#undef TOOIE_POSES
    constexpr int character_count = (int)std::size(characters);
    std::atomic<int> character{0};
    std::atomic<uint32_t> unlocked_characters{1};     // a bit per character, worked out on entering
    std::atomic<int> player_form_now{1};
    // Added to Kazooie's form id while the save has her as the dragon (flag 0x3EC, set and cleared by Humba's Isle o'
    // Hags pool), which is read on entering photo mode.
    constexpr int dragon_form = 0x100;
    constexpr int32_t dragon_kazooie_flag = 0x3EC;
    bool player_dragon = false;
    std::atomic<int> character_request{-1};          // from the row or the console, taken by tick
    bool characters_checked = false;

    const Character& current_character() {
        return characters[std::clamp(character.load(), 0, character_count - 1)];
    }
    // Whether the picked character is another form than the player's own, so drawn by a stand-in.
    bool stand_in_wanted() {
        return current_character().form != (uint16_t)player_form_now.load();
    }
    int pose_total() {
        return current_character().pose_count;
    }
    const PoseChoice& pose_at(int i) {
        const Character& c = current_character();
        return c.poses[std::clamp(i, 0, c.pose_count - 1)];
    }
    // The animation a pose plays on a stand-in: its own, or on "Game" the character's standing animation.
    uint32_t stand_in_anim(int i) {
        const uint32_t anim = pose_at(i).anim;
        return anim != 0 ? anim : current_character().idle;
    }
    // The animation a pose's card shows (0: none, "Game" on the player's own form).
    uint32_t card_anim(int i) {
        return stand_in_wanted() ? stand_in_anim(i) : pose_at(i).anim;
    }
    std::atomic<int> pose_choice{0};
    std::atomic<int> pose_frame{0};          // in 5% steps, 0 to 20
    std::atomic<bool> pose_dirty{false};
    // Banjo's own animation, kept to put back.
    struct SavedAnim {
        bool saved = false;
        uint32_t ctrl = 0;
        uint32_t index = 0;
        uint32_t duration = 0;
        uint32_t playback = 0;
        uint32_t timer = 0;
    } saved_anim;
    constexpr uint32_t anctrl_duration = 0x0C;
    constexpr uint32_t anctrl_playback = 0x1A;     // byte
    constexpr uint32_t anctrl_timer = 0x1C + 0x10;  // the animation's place, 0 to 1
    constexpr uint32_t anctrl_index = 0x1C + 0x18;  // halfword
    // Headless: TOOIE_POSE_SWEEP=<hex>[-<hex>][,...] poses those animation ids in turn 12 s after photo mode
    // comes on, with a screenshot of each, logging "[pose] sweep 0x..". TOOIE_POSE_FRAME=<0-20> sets the pose
    // frame (default 10, the middle).
    struct PoseSweep {
        bool active = false;
        std::vector<uint32_t> ids;
        size_t next = 0;
        Clock::time_point at{};
        bool shot = false;
    } pose_sweep;
    uint32_t sweep_anim = 0;

    // Self-timer: the Timer row's choice, and the countdown (on the game thread) once A started it.
    constexpr int timer_seconds[] = { 0, 3, 10 };
    std::atomic<int> timer_choice{0};
    std::atomic<bool> timer_requested{false};
    // A on the Album row: the photo panel opens the menu's Album tab (on its own thread, which may touch the menus).
    std::atomic<bool> album_requested{false};
    bool timer_running = false;
    Clock::time_point timer_end{};
    int timer_shown = -1;
    // Shutter: photos taken (the sound mixer plays a click for each new one) and when the last one was.
    std::atomic<uint32_t> shots{0};
    std::atomic<uint32_t> shots_at_enter{0};
    std::atomic<int64_t> last_shot_ns{0};
    constexpr float flash_seconds = 0.35f;

    // Held left / right: the first change at once, then repeats.
    Clock::time_point step_held_since{};
    Clock::time_point step_last{};
    constexpr auto repeat_delay = 400ms;
    constexpr auto repeat_every = 70ms;

    // The pad as photo mode reads it (written by apply_input, read by place_camera).
    std::mutex pad_mutex;
    struct Pad {
        uint16_t buttons = 0;
        float x = 0.0f, y = 0.0f;
    } pad;
    uint16_t last_buttons = 0;
    // Buttons held as photo mode closes stay away from the game until they are let go, so the B that closed it
    // (or anything else held) doesn't reach the game as a fresh press. Set on leaving, read by apply_input.
    std::atomic<uint16_t> exit_mask{0};

    // Game-thread state.
    struct Camera {
        bool placed = false;
        float pos[3] = { 0, 0, 0 };
        float yaw = 0.0f;
        float pitch = 0.0f;
        Clock::time_point last;
        Clock::time_point moving_since;
        bool moving = false;
        bool orbit = false;
        float pivot[3] = { 0, 0, 0 };
        float distance = 0.0f;
    } cam;
    bool hud_was_hidden = false;
    uint16_t entered_map = 0;
    // Photo mode ended while the game was not playing (a pose still on Banjo): his own animation goes back
    // once the game plays again in the same map.
    bool pose_restore_pending = false;

    struct TestHold {
        bool active = false;
        long on = 0, off = 0;
        bool did_on = false, did_off = false;
        Clock::time_point begin;
    } test;

    bool key_down() {
        return tooie::hotkeys::down(photo_input);
    }

    void worker() {
        bool was_down = false;
        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            bool down = key_down();
            if (down && !was_down) {
                toggle_requested = true;
            }
            was_down = down;
        }
    }

    float read_float(uint8_t* rdram, uint32_t addr) {
        uint32_t u = (uint32_t)MEM_W(0, (gpr)(int32_t)addr);
        float f;
        std::memcpy(&f, &u, 4);
        return f;
    }

    void write_float(uint8_t* rdram, uint32_t addr, float f) {
        uint32_t u;
        std::memcpy(&u, &f, 4);
        MEM_W(0, (gpr)(int32_t)addr) = (int32_t)u;
    }

    float signed_degrees(float d) {
        d = std::fmod(d, 360.0f);
        if (d > 180.0f) d -= 360.0f;
        if (d < -180.0f) d += 360.0f;
        return d;
    }

    template <typename T>
    T qol_value(const std::string& id, T fallback) {
        try {
            return std::get<T>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }

    // Photo crop entries' width / height, by enum value (0 none).
    constexpr float crop_aspects[] = { 0.0f, 16.0f / 9.0f, 2.39f, 4.0f / 3.0f, 1.0f, 4.0f / 5.0f, 9.0f / 16.0f };

    float crop_value() {
        const uint32_t crop = qol_value<uint32_t>(tooie::photo_mode::crop_option, 0);
        return crop < std::size(crop_aspects) ? crop_aspects[crop] : 0.0f;
    }

    // The game's depth buffer pointer (decomp func_8001A0A8), for depth of field.
    constexpr gpr depth_buffer_ptr = (int32_t)0x8007BCC4;

    void apply_filters(bool on, uint32_t depth_address = 0) {
        if (!on) {
            // The game's own picture settings (Graphics tab) come back.
            tooie::picture_filters::apply();
            RT64::SetPhotoFrame(0.0f, false);
            RT64::SetPhotoBorder(0);
            RT64::SetPhotoDepthOfField(0.0f, 0);
            return;
        }
        RT64::SetPhotoDepthOfField((float)qol_value<double>(tooie::photo_mode::dof_option, 0.0) / 100.0f, depth_address);
        RT64::SetPhotoFrame(crop_value(), qol_value<bool>(tooie::photo_mode::grid_option, false));
        RT64::SetPhotoBorder(qol_value<uint32_t>(tooie::photo_mode::border_option, 0));
        RT64::SetPhotoGrade(true,
            qol_value<uint32_t>(tooie::photo_mode::look_option, 0),
            (float)qol_value<double>(tooie::photo_mode::exposure_option, 0.0) / 10.0f,
            (float)qol_value<double>(tooie::photo_mode::contrast_option, 0.0) / 100.0f,
            (float)qol_value<double>(tooie::photo_mode::saturation_option, 0.0) / 100.0f,
            (float)qol_value<double>(tooie::photo_mode::warmth_option, 0.0) / 100.0f,
            (float)qol_value<double>(tooie::photo_mode::vignette_option, 0.0) / 100.0f,
            (float)qol_value<double>(tooie::photo_mode::grain_option, 0.0) / 100.0f);
    }

    bool collision_on() {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::photo_mode_collision_option));
        } catch (...) {
            return true;
        }
    }

    // Moves the camera from `pos` by `delta`, stopping at what it hits and sliding along it.
    void move_with_collision(uint8_t* rdram, recomp_context* ctx, float pos[3], const float delta[3]) {
        float to[3] = { pos[0] + delta[0], pos[1] + delta[1], pos[2] + delta[2] };
        if (delta[0] == 0.0f && delta[1] == 0.0f && delta[2] == 0.0f) {
            return;
        }
        float normal[3] = { 0, 0, 0 };
        float want[3] = { to[0], to[1], to[2] };
        if (!tooie::free_camera::sweep_line(rdram, ctx, pos, to, normal)) {
            std::memcpy(pos, want, sizeof(want));
            return;
        }
        // Lift off the surface a little, so the next test does not start touching it.
        for (int i = 0; i < 3; i++) {
            to[i] += normal[i] * surface_gap;
        }
        // Slide: what is left of the move, without the part going into the surface.
        float rest[3] = { want[0] - to[0], want[1] - to[1], want[2] - to[2] };
        const float into = rest[0] * normal[0] + rest[1] * normal[1] + rest[2] * normal[2];
        if (into < 0.0f) {
            for (int i = 0; i < 3; i++) {
                rest[i] -= into * normal[i];
            }
        }
        float slide[3] = { to[0] + rest[0], to[1] + rest[1], to[2] + rest[2] };
        if (tooie::free_camera::sweep_line(rdram, ctx, to, slide, normal)) {
            for (int i = 0; i < 3; i++) {
                slide[i] += normal[i] * surface_gap;
            }
        }
        std::memcpy(pos, slide, sizeof(slide));
    }

    float deadzone(float v) {
        return std::fabs(v) < stick_deadzone ? 0.0f : v;
    }

    recomp::config::Config& qol_config() {
        return recompui::config::get_config(tooie::qol_tab_id);
    }

    struct NumberRow {
        Row row;
        const std::string* id;
        double min, max, step;
    };
    const NumberRow number_rows[] = {
        { Row::Exposure, &tooie::photo_mode::exposure_option, -20, 20, 1 },
        { Row::Contrast, &tooie::photo_mode::contrast_option, -50, 50, 5 },
        { Row::Saturation, &tooie::photo_mode::saturation_option, -100, 100, 5 },
        { Row::Warmth, &tooie::photo_mode::warmth_option, -100, 100, 5 },
        { Row::Vignette, &tooie::photo_mode::vignette_option, 0, 100, 5 },
        { Row::Grain, &tooie::photo_mode::grain_option, 0, 100, 5 },
        { Row::Focus, &tooie::photo_mode::dof_option, 0, 100, 5 },
        { Row::Tilt, &tooie::photo_mode::tilt_option, -45, 45, 1 },
    };
    constexpr const char* look_names[] = { "None", "Sepia", "Black and white", "Noir", "Warm", "Cool", "Vivid", "Faded film",
        "Teal and orange", "Dream" };
    constexpr const char* border_names[] = { "None", "Instant photo", "Film strip", "Honeycomb", "Jiggy", "Wooden" };
    constexpr const char* crop_names[] = { "None", "16:9", "2.39:1", "4:3", "1:1", "4:5", "9:16" };
    constexpr const char* row_names[] = { "Zoom", "Camera", "Collision", "Time", "HUD", "Banjo", "Character", "Pose", "Pose frame", "Mirror", "Others", "Timer", "Shutter", "Filter", "Exposure",
        "Contrast", "Saturation", "Warmth", "Vignette", "Film grain", "Depth of field", "Focus point", "Tilt", "Crop", "Border", "Grid", "Album" };
    static_assert(std::size(row_names) == row_count);

    // On the game thread: one step of the picked row, -1 or +1.
    void change_row(Row row, int step) {
        try {
            recomp::config::Config& qol = qol_config();
            switch (row) {
            case Row::Zoom:
                break;
            case Row::Camera:
                orbit_toggle = true;
                break;
            case Row::Collision:
                qol.update_option_value(tooie::photo_mode_collision_option, !collision_on());
                break;
            case Row::Time:
                speed = (speed + speed_count + step) % speed_count;
                break;
            case Row::Hud:
                tooie::hide_hud::set_hidden(!tooie::hide_hud::is_hidden());
                break;
            case Row::Banjo:
                players_toggle = true;
                break;
            case Row::Others:
                others_hidden = !others_hidden;
                break;
            case Row::Character: {
                // The next unlocked character that way round.
                const uint32_t unlocked = unlocked_characters.load();
                int c = character.load();
                for (int i = 0; i < character_count; i++) {
                    c = (c + character_count + step) % character_count;
                    if (unlocked & (1u << c)) {
                        break;
                    }
                }
                character_request = c;
                break;
            }
            case Row::Pose:
                pose_choice = (pose_choice + pose_total() + step) % pose_total();
                pose_dirty = true;
                break;
            case Row::PoseFrame:
                pose_frame = std::clamp(pose_frame + step, 0, 20);
                pose_dirty = true;
                break;
            case Row::Mirror:
                mirror_on = !mirror_on;
                break;
            case Row::Filter: {
                const uint32_t n = (uint32_t)std::size(look_names);
                qol.update_option_value(tooie::photo_mode::look_option, (qol_value<uint32_t>(tooie::photo_mode::look_option, 0) + n + step) % n);
                break;
            }
            case Row::Border: {
                const uint32_t n = (uint32_t)std::size(border_names);
                qol.update_option_value(tooie::photo_mode::border_option, (qol_value<uint32_t>(tooie::photo_mode::border_option, 0) + n + step) % n);
                break;
            }
            case Row::Crop: {
                const uint32_t n = (uint32_t)std::size(crop_names);
                qol.update_option_value(tooie::photo_mode::crop_option, (qol_value<uint32_t>(tooie::photo_mode::crop_option, 0) + n + step) % n);
                break;
            }
            case Row::Grid:
                qol.update_option_value(tooie::photo_mode::grid_option, !qol_value<bool>(tooie::photo_mode::grid_option, false));
                break;
            case Row::Timer: {
                const int n = (int)std::size(timer_seconds);
                timer_choice = (timer_choice + n + step) % n;
                break;
            }
            case Row::FocusPoint: {
                const int n = (int)Focus::Count;
                focus_choice = (focus_choice + n + step) % n;
                break;
            }
            case Row::Album:
                if (step > 0) {
                    album_requested = true;
                }
                break;
            case Row::Shutter:
                qol.update_option_value(tooie::photo_mode::shutter_option, !qol_value<bool>(tooie::photo_mode::shutter_option, true));
                break;
            default:
                for (const NumberRow& n : number_rows) {
                    if (n.row == row) {
                        const double v = std::clamp(qol_value<double>(*n.id, 0.0) + step * n.step, n.min, n.max);
                        qol.update_option_value(*n.id, v);
                    }
                }
                break;
            }
        } catch (...) {
        }
    }

    std::string row_value(Row row) {
        char text[32];
        switch (row) {
        case Row::Zoom:
            std::snprintf(text, sizeof(text), "x%.2f", 1.0f / fov_scale.load());
            return text;
        case Row::Camera:
            return orbit_on ? "Orbit Banjo" : "Free";
        case Row::Collision:
            return collision_on() ? "On" : "Off";
        case Row::Time:
            return speed_values[speed.load()];
        case Row::Hud:
            return tooie::hide_hud::is_hidden() ? "Hidden" : "Shown";
        case Row::Banjo:
            return players_hidden ? "Hidden" : "Shown";
        case Row::Others:
            return others_hidden ? "Hidden" : "Shown";
        case Row::Pose:
            return pose_at(pose_choice.load()).name;
        case Row::Character:
            return current_character().name;
        case Row::PoseFrame:
            std::snprintf(text, sizeof(text), "%d%%", pose_frame.load() * 5);
            return text;
        case Row::Mirror:
            return mirror_on ? "On" : "Off";
        case Row::Filter: {
            const uint32_t v = qol_value<uint32_t>(tooie::photo_mode::look_option, 0);
            return v < std::size(look_names) ? look_names[v] : "None";
        }
        case Row::Border: {
            const uint32_t v = qol_value<uint32_t>(tooie::photo_mode::border_option, 0);
            return v < std::size(border_names) ? border_names[v] : "None";
        }
        case Row::Crop: {
            const uint32_t v = qol_value<uint32_t>(tooie::photo_mode::crop_option, 0);
            return v < std::size(crop_names) ? crop_names[v] : "None";
        }
        case Row::Grid:
            return qol_value<bool>(tooie::photo_mode::grid_option, false) ? "On" : "Off";
        case Row::Timer:
            if (timer_choice == 0) {
                return "Off";
            }
            std::snprintf(text, sizeof(text), "%d s", timer_seconds[timer_choice.load()]);
            return text;
        case Row::FocusPoint:
            return focus_names[focus_choice.load()];
        case Row::Album:
            return "A to open";
        case Row::Shutter:
            return qol_value<bool>(tooie::photo_mode::shutter_option, true) ? "Click and flash" : "Off";
        case Row::Exposure:
            std::snprintf(text, sizeof(text), "%+.1f stops", qol_value<double>(tooie::photo_mode::exposure_option, 0.0) / 10.0);
            return text;
        default:
            for (const NumberRow& n : number_rows) {
                if (n.row == row) {
                    std::snprintf(text, sizeof(text), "%.0f", qol_value<double>(*n.id, 0.0));
                    return text;
                }
            }
            return "";
        }
    }

    uint32_t player_anim_ctrl(uint8_t* rdram, recomp_context* ctx) {
        const uint32_t player = (uint32_t)MEM_W(0, (gpr)(int32_t)player_table);
        if (player < 0x80000000u || player >= 0x81000000u) {
            return 0;
        }
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        call.r4 = (int32_t)player;
        baanim_getAnimCtrlPtr(rdram, &call);
        const uint32_t ctrl = (uint32_t)call.r2;
        return ctrl >= 0x80000000u && ctrl < 0x81000000u ? ctrl : 0;
    }

    // As the game's own state inits do: reset, no blend, the animation, a duration, looped, started.
    void play_anim(uint8_t* rdram, recomp_context* ctx, uint32_t ctrl, uint32_t anim, uint32_t duration_bits, uint32_t playback) {
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        call.r4 = (int32_t)ctrl;
        anctrl_reset(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = 0;
        anctrl_setSmoothTransition(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = (int32_t)anim;
        anctrl_setIndex(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = (int32_t)duration_bits;
        anctrl_setDuration(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = (int32_t)playback;
        anctrl_setPlaybackType(rdram, &call);
        call.r4 = (int32_t)ctrl;
        anctrl_start(rdram, &call);
    }

    void hold_pose_frame(uint8_t* rdram, recomp_context* ctx);

    // Puts Banjo in the picked pose (or back in his own animation for "Game"), held at the pose frame.
    void apply_pose(uint8_t* rdram, recomp_context* ctx, uint32_t anim) {
        const uint32_t ctrl = player_anim_ctrl(rdram, ctx);
        if (ctrl == 0) {
            return;
        }
        if (anim == 0) {
            if (saved_anim.saved && saved_anim.ctrl == ctrl) {
                play_anim(rdram, ctx, ctrl, saved_anim.index, saved_anim.duration, saved_anim.playback);
                MEM_W(anctrl_timer, (gpr)(int32_t)ctrl) = (int32_t)saved_anim.timer;
            }
            saved_anim.saved = false;
            return;
        }
        if (!saved_anim.saved) {
            saved_anim.saved = true;
            saved_anim.ctrl = ctrl;
            saved_anim.index = (uint32_t)(uint16_t)MEM_H(anctrl_index, (gpr)(int32_t)ctrl);
            saved_anim.duration = (uint32_t)MEM_W(anctrl_duration, (gpr)(int32_t)ctrl);
            saved_anim.playback = (uint32_t)MEM_BU(anctrl_playback, (gpr)(int32_t)ctrl);
            saved_anim.timer = (uint32_t)MEM_W(anctrl_timer, (gpr)(int32_t)ctrl);
        }
        constexpr uint32_t two_seconds = 0x40000000;   // 2.0f: how long a loop takes in slow time
        play_anim(rdram, ctx, ctrl, anim, two_seconds, 2);
        hold_pose_frame(rdram, ctx);
    }

    // Keeps the animation at the pose frame while time is frozen (in slow time it plays on from there).
    void hold_pose_frame(uint8_t* rdram, recomp_context* ctx) {
        const uint32_t ctrl = player_anim_ctrl(rdram, ctx);
        if (ctrl == 0) {
            return;
        }
        const float t = std::min((float)pose_frame.load() / 20.0f, 0.999f);
        write_float(rdram, ctrl + anctrl_timer, t);
    }

    void shoot() {
        tooie::screenshot::take();
        bool shutter = true;
        try {
            shutter = qol_value<bool>(tooie::photo_mode::shutter_option, true);
        } catch (...) {
        }
        if (shutter) {
            last_shot_ns = Clock::now().time_since_epoch().count();
            shots.fetch_add(1);
        }
    }

    void stop_timer() {
        timer_requested = false;
        timer_running = false;
        timer_shown = -1;
    }

    // ---- Pose cards and the pose grid ----
    //
    // A card is pose_card_frames pictures of Banjo through one loop of a pose, taken by photo mode itself: the
    // camera is put in front of him (card_camera), the others are hidden, the photo filters are off, and for each
    // frame the animation is held at that point and the square in the middle of the next frame's game picture is asked
    // of RT64 (the same copy F12 takes, so the menus over it are never in it). Before the first card the same square
    // is taken with Banjo hidden (the plate); what matches it is background and made transparent. The frames are cut
    // to fit Banjo, shrunk to card_size and handed to the menus as images; the frames are also written side by side to
    // <app-data>/pose_cards/<animation id>.png, so the next time the grid opens they load instead. The game's
    // pictures stay on this PC: nothing of them is in the repository.
    constexpr int card_size = 128;
    // The square cut out of the picture, as a part of its height, and the card camera: this far from Banjo's
    // middle (this high above his feet), looking down a little, turned off his face so he is seen three-quarters,
    // with this vertical field of view.
    constexpr float card_crop = 0.92f;
    constexpr float card_distance = 290.0f;
    constexpr float card_height = 62.0f;
    constexpr float card_pitch = -6.0f;
    constexpr float card_turn = 28.0f;
    constexpr float card_fov = 40.0f;
    // Game updates waited after putting on a pose (it settles) and after moving its animation (the picture shows it).
    constexpr int settle_updates = 4;
    constexpr int frame_updates = 1;
    // How long one loop of a pose takes on the cards and on Banjo while the grid is open.
    constexpr float pose_loop_seconds = 1.0f;

    struct CardStore {
        std::mutex mutex;
        struct Card {
            uint32_t gen = 0;          // 0: no card
            int frames_in = 0;         // frames of the card being taken that have come back
            std::vector<std::vector<uint8_t>> frames;
        };
        std::unordered_map<uint32_t, Card> cards;   // by card key: the model << 16 | the animation id
    } store;
    std::atomic<uint32_t> card_gen{0};
    // The model whose cards were last read from disk (0 none), so a character's are read the first time its grid opens.
    std::atomic<uint32_t> cards_loaded_model{0};
    // The model of the round of cards being taken: its cards are filed under it.
    std::atomic<uint32_t> round_model{0};

    uint32_t card_key(uint32_t model, uint32_t anim) {
        return (model << 16) | (anim & 0xFFFF);
    }
    // Set when RT64 has handed back the frame last asked for.
    std::atomic<bool> develop_shot_back{false};

    std::string card_prefix(uint32_t anim, uint32_t gen) {
        char text[48];
        std::snprintf(text, sizeof(text), "?/posecard/%X/%u/", anim, gen);
        return text;
    }

    std::filesystem::path card_folder() {
        // pose_cards held keyed cards (the background taken away by a plate); these are filmed with alpha.
        return recomp::get_config_path() / "pose_cards_v2";
    }

    // A folder for each character's model, a file for each animation.
    std::filesystem::path card_path(uint32_t key) {
        char folder[16], name[24];
        std::snprintf(folder, sizeof(folder), "%X", key >> 16);
        std::snprintf(name, sizeof(name), "%X.png", key & 0xFFFF);
        return card_folder() / folder / name;
    }

    // Hands a whole card to the menus (dropping the one it replaces) and, when asked, writes it to disk. Any thread.
    void publish_card(uint32_t anim, std::vector<std::vector<uint8_t>>&& frames, bool save) {
        if ((int)frames.size() != tooie::photo_mode::pose_card_frames) {
            return;
        }
        const uint32_t gen = card_gen.fetch_add(1) + 1;
        for (int f = 0; f < (int)frames.size(); f++) {
            std::vector<char> bytes(frames[f].begin(), frames[f].end());
            recompui::queue_image_from_bytes_rgba32(card_prefix(anim, gen) + std::to_string(f), bytes, card_size, card_size);
        }
        uint32_t old = 0;
        {
            std::lock_guard lock{ store.mutex };
            CardStore::Card& card = store.cards[anim];
            old = card.gen;
            card.gen = gen;
        }
        if (old != 0) {
            for (int f = 0; f < (int)frames.size(); f++) {
                recompui::release_image(card_prefix(anim, old) + std::to_string(f));
            }
        }
        if (save) {
            // One strip, the frames left to right.
            const int n = (int)frames.size();
            std::vector<uint8_t> strip((size_t)card_size * n * card_size * 4);
            for (int f = 0; f < n; f++) {
                for (int y = 0; y < card_size; y++) {
                    std::memcpy(&strip[((size_t)y * card_size * n + (size_t)f * card_size) * 4],
                        &frames[f][(size_t)y * card_size * 4], (size_t)card_size * 4);
                }
            }
            std::error_code ec;
            std::filesystem::create_directories(card_path(anim).parent_path(), ec);
            // Through a stream: stbi_write_png takes a narrow name, which Windows reads in the ANSI code page.
            int length = 0;
            unsigned char* png = stbi_write_png_to_mem(strip.data(), card_size * n * 4, card_size * n, card_size, 4, &length);
            if (png != nullptr) {
                std::ofstream out(card_path(anim), std::ios::binary);
                out.write(reinterpret_cast<const char*>(png), length);
                STBIW_FREE(png);
            }
        }
    }

    // Reads the cards kept from before of a character (by its model, the animations given). Returns the animations
    // that have none.
    std::vector<uint32_t> load_cards(uint32_t model, const std::vector<uint32_t>& anims) {
        std::vector<uint32_t> missing;
        for (const uint32_t anim : anims) {
            const uint32_t key = card_key(model, anim);
            {
                std::lock_guard lock{ store.mutex };
                auto it = store.cards.find(key);
                if (it != store.cards.end() && it->second.gen != 0) {
                    continue;
                }
            }
            std::vector<unsigned char> file;
            {
                std::ifstream in(card_path(key), std::ios::binary);
                if (in) {
                    file.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
                }
            }
            int w = 0, h = 0, channels = 0;
            stbi_uc* pixels = file.empty() ? nullptr : stbi_load_from_memory(file.data(), (int)file.size(), &w, &h, &channels, 4);
            const int n = tooie::photo_mode::pose_card_frames;
            if (pixels == nullptr || w != card_size * n || h != card_size) {
                if (pixels != nullptr) {
                    stbi_image_free(pixels);
                }
                missing.push_back(anim);
                continue;
            }
            std::vector<std::vector<uint8_t>> frames(n, std::vector<uint8_t>((size_t)card_size * card_size * 4));
            for (int f = 0; f < n; f++) {
                for (int y = 0; y < card_size; y++) {
                    std::memcpy(&frames[f][(size_t)y * card_size * 4], &pixels[((size_t)y * w + (size_t)f * card_size) * 4], (size_t)card_size * 4);
                }
            }
            stbi_image_free(pixels);
            publish_card(key, std::move(frames), false);
        }
        return missing;
    }

    // Only the square in the middle is copied back from the GPU (the image has the window's shape), which is
    // far quicker than the whole picture; the callbacks still cut the middle square from whatever comes.
    void request_card_square(RT64::ScreenshotCallback callback) {
        int window_w = 0, window_h = 0;
        recompui::get_window_size(window_w, window_h);
        const float half = window_w > 0 && window_h > 0 ? std::min(0.5f, 0.5f * card_crop * (float)window_h / (float)window_w) : 0.5f;
        RT64::RequestScreenshotRegion(0.5f - half, 0.5f - card_crop * 0.5f, 0.5f + half, 0.5f + card_crop * 0.5f, std::move(callback));
    }

    // The background plate: the card camera's square with Banjo hidden, taken once at the start of each round of
    // cards (Banjo and the camera stay put through it). A frame's pixels that match it are background and made
    // transparent, so the cards are Banjo alone. Under store.mutex.
    struct Plate {
        uint32_t width = 0, height = 0;
        std::vector<uint8_t> rgba;
    } plate;
    // How far a pixel's colour may be from the plate's (the largest of its three channels, 0-255) and still be
    // background, and how far it must be to be all Banjo; between the two it is partly see-through (soft edges).
    constexpr int key_near = 10;
    constexpr int key_far = 34;

    void take_plate() {
        request_card_square([](uint32_t width, uint32_t height, std::vector<uint8_t>&& rgba) {
            {
                std::lock_guard lock{ store.mutex };
                plate.width = width;
                plate.height = height;
                plate.rgba = std::move(rgba);
            }
            develop_shot_back = true;
        });
    }

    // Makes the background of a frame transparent, by the plate. Without a plate of the same size it stays opaque.
    void key_frame(uint32_t width, uint32_t height, std::vector<uint8_t>& rgba) {
        std::lock_guard lock{ store.mutex };
        const bool have = plate.width == width && plate.height == height && plate.rgba.size() == rgba.size();
        for (size_t i = 0; i + 3 < rgba.size(); i += 4) {
            if (!have) {
                rgba[i + 3] = 255;
                continue;
            }
            int d = 0;
            for (int c = 0; c < 3; c++) {
                d = std::max(d, std::abs((int)rgba[i + c] - (int)plate.rgba[i + c]));
            }
            rgba[i + 3] = (uint8_t)std::clamp((d - key_near) * 255 / (key_far - key_near), 0, 255);
        }
    }

    // Frames are kept this large until the whole card is in, then cut to fit Banjo and shrunk to card_size.
    constexpr int work_size = 256;
    // Space left round Banjo on a fitted card, as a part of its side.
    constexpr float fit_margin = 0.06f;

    // Cuts the same square out of every frame of a card: the smallest one (with a margin) that holds Banjo in all of
    // them, centred on him, so each pose fills its card however big or small it is. Then shrinks them to card_size.
    std::vector<std::vector<uint8_t>> fit_card(const std::vector<std::vector<uint8_t>>& frames) {
        int x0 = work_size, y0 = work_size, x1 = -1, y1 = -1;
        for (const auto& f : frames) {
            for (int y = 0; y < work_size; y++) {
                for (int x = 0; x < work_size; x++) {
                    if (f[((size_t)y * work_size + x) * 4 + 3] > 96) {
                        x0 = std::min(x0, x); x1 = std::max(x1, x);
                        y0 = std::min(y0, y); y1 = std::max(y1, y);
                    }
                }
            }
        }
        int side = work_size, left = 0, top = 0;
        if (x1 >= x0 && y1 >= y0) {
            side = std::max(x1 - x0 + 1, y1 - y0 + 1);
            side = std::clamp((int)((float)side * (1.0f + 2.0f * fit_margin)), work_size / 4, work_size);
            left = std::clamp((x0 + x1 + 1) / 2 - side / 2, 0, work_size - side);
            top = std::clamp((y0 + y1 + 1) / 2 - side / 2, 0, work_size - side);
        }
        std::vector<std::vector<uint8_t>> out;
        for (const auto& f : frames) {
            std::vector<uint8_t> small((size_t)card_size * card_size * 4);
            stbir_resize_uint8_linear(&f[((size_t)top * work_size + left) * 4], side, side, work_size * 4,
                small.data(), card_size, card_size, card_size * 4, STBIR_RGBA);
            out.push_back(std::move(small));
        }
        return out;
    }

    // One frame of a card back from RT64 (its present thread): keyed against the plate, the middle cut square and
    // shrunk, on a thread of its own. The last frame in publishes the card.
    void take_card_frame(uint32_t anim, int frame) {
        request_card_square([anim, frame](uint32_t width, uint32_t height, std::vector<uint8_t>&& rgba) {
            std::thread([anim, frame, width, height, rgba = std::move(rgba)]() mutable {
                if (width == 0 || height == 0 || rgba.size() < (size_t)width * height * 4) {
                    return;
                }
                key_frame(width, height, rgba);
                const uint32_t side = std::max(1u, std::min(width, height));
                const uint32_t x0 = (width - side) / 2, y0 = (height - side) / 2;
                std::vector<uint8_t> small((size_t)work_size * work_size * 4);
                // Straight alpha, as the menus draw it; the resize weighs colours by it, so no background bleeds in.
                stbir_resize_uint8_linear(&rgba[((size_t)y0 * width + x0) * 4], (int)side, (int)side, (int)width * 4,
                    small.data(), work_size, work_size, work_size * 4, STBIR_RGBA);
                std::vector<std::vector<uint8_t>> done;
                {
                    std::lock_guard lock{ store.mutex };
                    CardStore::Card& card = store.cards[anim];
                    const int n = tooie::photo_mode::pose_card_frames;
                    if ((int)card.frames.size() != n) {
                        card.frames.assign(n, {});
                        card.frames_in = 0;
                    }
                    if (card.frames[frame].empty()) {
                        card.frames_in++;
                    }
                    card.frames[frame] = std::move(small);
                    if (card.frames_in == n) {
                        done = std::move(card.frames);
                        card.frames.clear();
                        card.frames_in = 0;
                    }
                }
                if (!done.empty()) {
                    publish_card(card_key(round_model, anim), fit_card(done), true);
                }
            }).detach();
            develop_shot_back = true;
        });
    }

    // The grid, and taking the cards (game thread unless atomic).
    std::atomic<bool> grid_open{false};
    std::atomic<int> grid_cursor{0};
    // Scrubbing: the cursor's card held at a pose frame (0 to 20, the Pose frame row's steps), moved with C-left and
    // C-right or the mouse sideways; -1 while it plays. A then keeps that frame. Moving to another card lets it play.
    std::atomic<int> grid_scrub{-1};
    float scrub_mouse = 0.0f;   // mouse turn not yet made into frames, degrees (game thread)
    constexpr float scrub_degrees = 1.5f;   // mouse turn a frame
    int grid_prev_pose = 0;                  // put back when the grid is left with B
    Clock::time_point grid_anim_start{};
    std::atomic<bool> grid_open_request{false}, grid_close_request{false};
    std::atomic<int> grid_pick_request{-1};  // a pose to wear and close the grid with
    std::atomic<bool> grid_cancel{false};    // B: close and put the pose back
    std::atomic<bool> develop_again{false};  // Start in the grid: all cards again

    std::mutex develop_mutex;
    std::vector<uint32_t> develop_requested;   // under develop_mutex
    uint32_t develop_requested_model = 0;     // the character's model they are for (under develop_mutex)
    bool develop_requested_stand_in = false;  // filmed as another form than the player's (under develop_mutex)
    float develop_requested_size = 1.0f;
    std::atomic<bool> develop_pending{false};
    std::atomic<bool> developing{false};
    std::atomic<int> developed{0}, develop_total{0};
    struct Develop {
        std::vector<uint32_t> anims;
        size_t at = 0;
        int frame = 0;
        int phase = 0;
        int wait = 0;
        Clock::time_point asked{};
        bool others_were_hidden = false;
        bool players_were_hidden = false;
        // Filmed with pose puppets (pose_puppets.cpp): off screen, nothing on screen moves.
        bool puppets = false;
        std::vector<uint32_t> queue;                                // shots waiting, (anim << 8) | frame
        std::unordered_map<uint32_t, Clock::time_point> asked_at;   // shots out, when asked for
        Clock::time_point started{};
    } dev;
    // The pose puppets' side, shared with the threads their pictures come back on.
    struct FilmShared {
        std::mutex mutex;
        uint32_t gen = 0;                       // the round of cards; pictures of an older one are dropped
        std::unordered_set<uint32_t> got;       // shots back this round
        int cards_done = 0;                     // cards of this round published
    } film_shared;
    std::atomic<bool> film_stop_pending{false};
    // Cards taken the old way: Banjo posed in front of the card camera, the picture keyed against a plate.
    bool old_develop() {
        return developing && !dev.puppets;
    }

    // Sound cues for the grid, played by mix_shutter: a tick for each move, a pop for a pick, a chime when the
    // cards are ready.
    std::atomic<uint32_t> cue_ticks{0}, cue_picks{0}, cue_chimes{0};

    void start_develop(std::vector<uint32_t> anims, uint32_t model, bool stand_in, float size) {
        if (anims.empty()) {
            return;
        }
        std::lock_guard lock{ develop_mutex };
        develop_requested = std::move(anims);
        develop_requested_model = model;
        develop_requested_stand_in = stand_in;
        develop_requested_size = size;
        develop_pending = true;
    }

    float banjo_yaw(uint8_t* rdram, recomp_context* ctx) {
        const uint32_t player = (uint32_t)MEM_W(0, (gpr)(int32_t)player_table);
        if (player < 0x80000000u || player >= 0x81000000u) {
            return 0.0f;
        }
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        call.r4 = (int32_t)player;
        yaw_get(rdram, &call);
        return call.f0.fl;
    }

    // The card camera's place and turn: in front of Banjo, three-quarters on. Banjo's yaw and the camera's share
    // a sense (yaw 0 looks along -z; Banjo at yaw 0 faces +z), so a camera with his yaw looks him in the face.
    bool card_camera(uint8_t* rdram, recomp_context* ctx, float pos[3], float& yaw, float& pitch) {
        const uint32_t player = (uint32_t)MEM_W(0, (gpr)(int32_t)player_table);
        const uint32_t transform = player != 0 ? (uint32_t)MEM_W(player_transform, (gpr)(int32_t)player) : 0;
        if (transform == 0) {
            return false;
        }
        float pivot[3];
        for (int i = 0; i < 3; i++) {
            pivot[i] = read_float(rdram, transform + 4 * i);
        }
        pivot[1] += card_height;
        yaw = std::fmod(banjo_yaw(rdram, ctx) + card_turn + 720.0f, 360.0f);
        pitch = card_pitch;
        const float sy = std::sin(yaw * deg), cy = std::cos(yaw * deg);
        const float sp = std::sin(pitch * deg), cp = std::cos(pitch * deg);
        const float forward[3] = { -sy * cp, sp, -cy * cp };
        for (int i = 0; i < 3; i++) {
            pos[i] = pivot[i] - forward[i] * card_distance;
        }
        return true;
    }

    void hold_anim_at(uint8_t* rdram, recomp_context* ctx, float t) {
        const uint32_t ctrl = player_anim_ctrl(rdram, ctx);
        if (ctrl != 0) {
            write_float(rdram, ctrl + anctrl_timer, std::clamp(t, 0.0f, 0.999f));
        }
    }

    void finish_develop(bool cancelled) {
        developing = false;
        if (dev.puppets) {
            // The puppets give their room back on the game thread (tick).
            film_stop_pending = true;
            std::lock_guard lock{ film_shared.mutex };
            film_shared.gen++;
        }
        else {
            others_hidden = dev.others_were_hidden;
            players_hidden = dev.players_were_hidden;
            // The pose worn before: on again from the start.
            pose_dirty = true;
            grid_anim_start = Clock::now();
        }
        if (!cancelled) {
            cue_chimes.fetch_add(1);
        }
        const float secs = std::chrono::duration<float>(Clock::now() - dev.started).count();
        fprintf(stderr, "[photo] pose cards %s: %d of %d in %.1f s (%s)\n", cancelled ? "stopped" : "done", developed.load(),
            develop_total.load(), secs, dev.puppets ? "puppets" : "Banjo and a plate");
    }

    // A picture of a shot back from the puppets (any thread): into its card, which is published once all its frames
    // are in.
    void puppet_shot_back(uint32_t gen, uint32_t id, uint32_t side, std::vector<uint8_t>&& rgba) {
        const uint32_t anim = id >> 8;
        const int frame = (int)(id & 0xFF);
        const int n = tooie::photo_mode::pose_card_frames;
        if (frame >= n || side == 0) {
            return;
        }
        {
            std::lock_guard lock{ film_shared.mutex };
            if (gen != film_shared.gen || !film_shared.got.insert(id).second) {
                return;
            }
        }
        std::vector<uint8_t> small((size_t)work_size * work_size * 4);
        stbir_resize_uint8_linear(rgba.data(), (int)side, (int)side, (int)side * 4,
            small.data(), work_size, work_size, work_size * 4, STBIR_RGBA);
        std::vector<std::vector<uint8_t>> done;
        {
            std::lock_guard lock{ store.mutex };
            CardStore::Card& card = store.cards[anim];
            if ((int)card.frames.size() != n) {
                card.frames.assign(n, {});
                card.frames_in = 0;
            }
            if (card.frames[frame].empty()) {
                card.frames_in++;
            }
            card.frames[frame] = std::move(small);
            if (card.frames_in == n) {
                done = std::move(card.frames);
                card.frames.clear();
                card.frames_in = 0;
            }
        }
        if (!done.empty()) {
            publish_card(card_key(round_model, anim), fit_card(done), true);
            std::lock_guard lock{ film_shared.mutex };
            if (gen == film_shared.gen) {
                developed = ++film_shared.cards_done;
            }
        }
    }

    void bring_page_forward();

    // One game update of filming with the puppets: shots not back in time are asked again, and while fewer than
    // two frames are out, the next frame's shots are handed over (a pose's frames are queued when it is begun, the
    // open page's poses first).
    void step_film() {
        const int n = tooie::photo_mode::pose_card_frames;
        int done = 0;
        {
            std::lock_guard lock{ film_shared.mutex };
            done = film_shared.cards_done;
            const Clock::time_point now = Clock::now();
            for (auto it = dev.asked_at.begin(); it != dev.asked_at.end();) {
                if (film_shared.got.count(it->first) != 0) {
                    it = dev.asked_at.erase(it);
                }
                else if (now - it->second > 1500ms) {
                    dev.queue.insert(dev.queue.begin(), it->first);
                    it = dev.asked_at.erase(it);
                }
                else {
                    ++it;
                }
            }
        }
        if (done >= (int)dev.anims.size()) {
            finish_develop(false);
            return;
        }
        if (!tooie::pose_puppets::filming() || tooie::pose_puppets::film_in_flight() >= 2) {
            return;
        }
        std::vector<tooie::pose_puppets::Shot> shots;
        const int cells = tooie::pose_puppets::film_cells();
        while ((int)shots.size() < cells) {
            if (dev.queue.empty()) {
                if (dev.at >= dev.anims.size()) {
                    break;
                }
                bring_page_forward();
                const uint32_t anim = dev.anims[dev.at++];
                for (int f = n - 1; f >= 0; f--) {
                    dev.queue.insert(dev.queue.begin(), (anim << 8) | (uint32_t)f);
                }
                continue;
            }
            const uint32_t id = dev.queue.front();
            dev.queue.erase(dev.queue.begin());
            shots.push_back({ id >> 8, (float)(id & 0xFF) / (float)n, id });
            dev.asked_at[id] = Clock::now();
        }
        if (!shots.empty()) {
            tooie::pose_puppets::film_next(std::move(shots));
        }
    }

    // The cards on the page the grid shows are taken first: the next one waiting on that page is moved up to be
    // taken now, so the page fills in before the rest, whichever page is turned to meanwhile.
    void bring_page_forward() {
        if (!grid_open) {
            return;
        }
        const int page = grid_cursor.load() / tooie::photo_mode::pose_grid_page;
        for (size_t i = dev.at; i < dev.anims.size(); i++) {
            for (int p = 0; p < pose_total(); p++) {
                if (card_anim(p) == dev.anims[i] && p / tooie::photo_mode::pose_grid_page == page) {
                    std::swap(dev.anims[dev.at], dev.anims[i]);
                    return;
                }
            }
        }
    }

    // One game update of taking cards.
    void step_develop(uint8_t* rdram, recomp_context* ctx) {
        if (!developing) {
            return;
        }
        if (dev.puppets) {
            step_film();
            return;
        }
        const int n = tooie::photo_mode::pose_card_frames;
        const float t = (float)dev.frame / (float)n;
        if (dev.phase >= 1 && dev.phase <= 3) {
            hold_anim_at(rdram, ctx, t);
        }
        if (dev.wait > 0) {
            dev.wait--;
            return;
        }
        switch (dev.phase) {
        case 10:
            // The plate: Banjo hidden, then his picture asked for.
            players_hidden = true;
            dev.wait = settle_updates;
            dev.phase = 11;
            break;
        case 11:
            develop_shot_back = false;
            dev.asked = Clock::now();
            take_plate();
            dev.phase = 12;
            break;
        case 12:
            if (!develop_shot_back && Clock::now() - dev.asked < 1s) {
                break;
            }
            players_hidden = false;
            dev.phase = 0;
            break;
        case 0:
            if (dev.at >= dev.anims.size()) {
                finish_develop(false);
                return;
            }
            bring_page_forward();
            apply_pose(rdram, ctx, dev.anims[dev.at]);
            dev.frame = 0;
            hold_anim_at(rdram, ctx, 0.0f);
            dev.wait = settle_updates;
            dev.phase = 2;
            break;
        case 1:
            dev.wait = frame_updates;
            dev.phase = 2;
            break;
        case 2:
            develop_shot_back = false;
            dev.asked = Clock::now();
            take_card_frame(dev.anims[dev.at], dev.frame);
            dev.phase = 3;
            break;
        case 3:
            if (!develop_shot_back && Clock::now() - dev.asked < 1s) {
                break;
            }
            if (++dev.frame >= n) {
                dev.at++;
                developed = (int)dev.at;
                dev.phase = 0;
            }
            else {
                dev.phase = 1;
            }
            break;
        }
    }

    void begin_develop(uint8_t* rdram, recomp_context* ctx, std::vector<uint32_t>&& anims, uint32_t model, bool stand_in, float size) {
        dev = Develop{};
        round_model = model;
        dev.anims = std::move(anims);
        dev.started = Clock::now();
        developed = 0;
        develop_total = (int)dev.anims.size();
        // Off screen with the pose puppets when there is room for them: nothing on screen changes. TOOIE_POSE_OLD=1
        // takes them the old way, to compare.
        static const bool old_way = std::getenv("TOOIE_POSE_OLD") != nullptr;
        if (film_stop_pending.exchange(false)) {
            tooie::pose_puppets::film_stop(rdram, ctx);
        }
        uint32_t gen = 0;
        {
            std::lock_guard lock{ film_shared.mutex };
            gen = ++film_shared.gen;
            film_shared.got.clear();
            film_shared.cards_done = 0;
        }
        if (!old_way && tooie::pose_puppets::film_start(rdram, ctx, [gen](uint32_t id, uint32_t side, std::vector<uint8_t>&& rgba) {
                puppet_shot_back(gen, id, side, std::move(rgba));
            }, stand_in ? (uint16_t)model : 0, size)) {
            dev.puppets = true;
            developing = true;
            fprintf(stderr, "[photo] filming %d pose cards of model 0x%X with puppets, %d at a time\n", develop_total.load(), model,
                tooie::pose_puppets::film_cells());
            return;
        }
        // The old way poses the player himself, so it cannot film another form.
        if (stand_in) {
            develop_total = 0;
            fprintf(stderr, "[photo] no room for the pose puppets: model 0x%X's cards wait\n", model);
            return;
        }
        dev.others_were_hidden = others_hidden;
        dev.players_were_hidden = players_hidden;
        others_hidden = true;
        players_hidden = false;
        developed = 0;
        develop_total = (int)dev.anims.size();
        {
            std::lock_guard lock{ store.mutex };
            plate = Plate{};
        }
        // First the background plate, once the card camera is in place.
        dev.phase = 10;
        dev.wait = settle_updates;
        developing = true;
        // The cards are the plain game picture: no photo look, crop, border or blur on them.
        apply_filters(false);
        fprintf(stderr, "[photo] taking %d pose cards\n", develop_total.load());
    }

    // The mouse in photo mode (input path): its buttons and wheel, counted since the last read.
    std::atomic<bool> mouse_reset{false};
    bool mouse_clicks_seen = false;
    uint32_t last_left_clicks = 0, last_right_clicks = 0;
    bool wheel_seen = false;
    int32_t last_wheel = 0;
    std::atomic<int> zoom_notches{0};   // for place_camera

    // Whether a mouse button is bound to one of the game's buttons in the keyboard profile: then a click is
    // that button already, and photo mode leaves it alone.
    bool mouse_button_bound(int button) {
        try {
            const int profile = recompinput::profiles::get_sp_keyboard_profile_index();
            for (int i = (int)recompinput::GameInput::N64_BUTTON_START;
                 i < (int)recompinput::GameInput::N64_BUTTON_START + (int)recompinput::GameInput::N64_BUTTON_COUNT; i++) {
                for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                    const recompinput::InputField& f = recompinput::profiles::get_input_binding(profile, (recompinput::GameInput)i, b);
                    if (f.input_type == recompinput::InputType::Mouse && f.input_id == button) {
                        return true;
                    }
                }
            }
        } catch (...) {
        }
        return false;
    }

    // The first key the keyboard profile binds to a game button, by name ("Space"), for notices in plain text.
    std::string key_name(recompinput::GameInput input) {
        try {
            const int profile = recompinput::profiles::get_sp_keyboard_profile_index();
            for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                const recompinput::InputField& f = recompinput::profiles::get_input_binding(profile, input, b);
                if (f.input_type == recompinput::InputType::Keyboard && !f.has_modifier()) {
                    const char* name = SDL_GetScancodeName((SDL_Scancode)f.input_id);
                    if (name != nullptr && name[0] != '\0') {
                        return name;
                    }
                }
            }
        } catch (...) {
        }
        return recompinput::get_game_input_name(input);
    }

    // The grid's own repeat for a held D-pad direction.
    uint16_t grid_held = 0;
    Clock::time_point grid_held_since{}, grid_held_last{};

    void move_cursor(int by) {
        const int count = pose_total();
        const int now = grid_cursor.load();
        const int next = std::clamp(now + by, 0, count - 1);
        if (next != now) {
            grid_cursor = next;
            grid_scrub = -1;
            cue_ticks.fetch_add(1);
        }
    }

    // A step of the scrub (+1 or -1 a frame), from where the card's loop has got to the first time; round the loop.
    void scrub_step(int by) {
        int f = grid_scrub.load();
        if (f < 0) {
            const float s = std::chrono::duration<float>(Clock::now() - grid_anim_start).count();
            f = (int)std::lround(std::fmod(s / pose_loop_seconds, 1.0f) * 20.0f) % 21;
        }
        grid_scrub = ((f + by) % 21 + 21) % 21;
        cue_ticks.fetch_add(1);
    }
    uint16_t scrub_held = 0;
    Clock::time_point scrub_held_since{}, scrub_held_last{};

    // Input path, while the grid is open (or cards are being taken): the D-pad moves over the cards (held, it
    // repeats), L and R turn the page, A wears the pose and closes, B closes and puts the pose back, Start
    // takes every card again. While cards are being taken the cursor and the pages still move (the page shown is
    // taken first), B stops it, and A and Start wait till it is done.
    void grid_input(uint16_t buttons, uint16_t pressed, int wheel_notches, Clock::time_point now) {
        if (developing) {
            if (pressed & button_b) {
                grid_cancel = true;
            }
            pressed &= (uint16_t)~(button_a | button_b | button_start);
        }
        const uint16_t dirs = buttons & (d_up | d_down | d_left | d_right);
        auto step = [](uint16_t d) {
            const int cols = tooie::photo_mode::pose_grid_columns;
            return (d & d_up ? -cols : 0) + (d & d_down ? cols : 0) + (d & d_left ? -1 : 0) + (d & d_right ? 1 : 0);
        };
        if (pressed & dirs) {
            grid_held = dirs;
            grid_held_since = now;
            grid_held_last = now;
            move_cursor(step(pressed & dirs));
        }
        else if (dirs != 0 && dirs == grid_held && now - grid_held_since >= repeat_delay && now - grid_held_last >= repeat_every * 2) {
            grid_held_last = now;
            move_cursor(step(dirs));
        }
        else if (dirs == 0) {
            grid_held = 0;
        }
        // C-left and C-right scrub the cursor's card (held, they repeat at the D-pad's pace).
        const uint16_t scrub = buttons & (c_left | c_right);
        if (pressed & scrub) {
            scrub_held = scrub;
            scrub_held_since = now;
            scrub_held_last = now;
            scrub_step(pressed & c_right ? 1 : -1);
        }
        else if (scrub != 0 && scrub == scrub_held && now - scrub_held_since >= repeat_delay && now - scrub_held_last >= repeat_every) {
            scrub_held_last = now;
            scrub_step(scrub & c_right ? 1 : -1);
        }
        else if (scrub == 0) {
            scrub_held = 0;
        }
        const int page = tooie::photo_mode::pose_grid_page;
        if (pressed & (button_l | button_z)) {
            move_cursor(grid_cursor.load() >= page ? -page : -grid_cursor.load());
        }
        if (pressed & button_r) {
            move_cursor(page);
        }
        // The wheel scrolls a row of cards a notch.
        if (wheel_notches != 0) {
            move_cursor(-wheel_notches * tooie::photo_mode::pose_grid_columns);
        }
        if (pressed & button_a) {
            grid_pick_request = grid_cursor.load();
        }
        else if (pressed & button_b) {
            grid_cancel = true;
        }
        else if (pressed & button_start) {
            develop_again = true;
        }
    }

    // The picked character's card animations (each once).
    std::vector<uint32_t> all_pose_anims() {
        std::vector<uint32_t> anims;
        for (int i = 0; i < pose_total(); i++) {
            const uint32_t anim = card_anim(i);
            if (anim != 0 && std::find(anims.begin(), anims.end(), anim) == anims.end()) {
                anims.push_back(anim);
            }
        }
        return anims;
    }

    // Takes the picked character's cards (those given, or all), filed under its model.
    void develop_character(std::vector<uint32_t> anims) {
        const Character& c = current_character();
        start_develop(std::move(anims), c.model, stand_in_wanted(), c.card_size);
    }

    // Game thread, each update while photo mode is on: carries out the grid's requests. The pose under the
    // cursor is worn at once, so Banjo shows it in the world as well as on its card.
    int grid_worn = -1;
    void tick_grid(uint8_t* rdram, recomp_context* ctx) {
        const int count = pose_total();
        if (grid_open_request.exchange(false) && !grid_open && !developing) {
            grid_scrub = -1;
            grid_prev_pose = pose_choice;
            grid_cursor = pose_choice.load();
            grid_worn = pose_choice;
            grid_anim_start = Clock::now();
            grid_open = true;
            cue_picks.fetch_add(1);
            // The first time: the cards kept from before, then any missing are taken.
            const uint32_t model = current_character().model;
            if (cards_loaded_model.exchange(model) != model) {
                const bool stand_in = stand_in_wanted();
                const float size = current_character().card_size;
                std::thread([model, stand_in, size, anims = all_pose_anims()] {
                    start_develop(load_cards(model, anims), model, stand_in, size);
                }).detach();
            }
        }
        if (grid_close_request.exchange(false)) {
            grid_open = false;
        }
        if (grid_cancel.exchange(false)) {
            if (developing) {
                finish_develop(true);
            }
            else if (grid_open) {
                pose_choice = grid_prev_pose;
                pose_dirty = true;
                grid_open = false;
            }
        }
        if (const int pick = grid_pick_request.exchange(-1); pick >= 0 && pick < count) {
            // A scrubbed card keeps its frame: the Pose frame row takes it.
            if (const int f = grid_scrub.exchange(-1); f >= 0) {
                pose_frame = f;
            }
            pose_choice = pick;
            pose_dirty = true;
            grid_open = false;
            cue_picks.fetch_add(1);
            if (!panel_shown) {
                tooie::toast::show(std::string("Pose: ") + pose_at(pick).name);
            }
        }
        if (develop_again.exchange(false)) {
            develop_character(all_pose_anims());
        }
        if (develop_pending && !developing) {
            std::vector<uint32_t> anims;
            uint32_t model = 0;
            bool stand_in = false;
            float size = 1.0f;
            {
                std::lock_guard lock{ develop_mutex };
                anims = std::move(develop_requested);
                develop_requested.clear();
                model = develop_requested_model;
                stand_in = develop_requested_stand_in;
                size = develop_requested_size;
                develop_pending = false;
            }
            if (!anims.empty()) {
                begin_develop(rdram, ctx, std::move(anims), model, stand_in, size);
            }
        }
        if (grid_open && !old_develop()) {
            const int c = std::clamp(grid_cursor.load(), 0, count - 1);
            if (c != grid_worn) {
                grid_worn = c;
                pose_choice = c;
                pose_dirty = true;
                grid_anim_start = Clock::now();
            }
        }
    }

    // The stand-in's place in its pose, moved on in slow time.
    float stand_in_t = 0.0f;
    Clock::time_point stand_in_last{};

    uint8_t read_player_form(uint8_t* rdram) {
        const uint32_t player = (uint32_t)MEM_W(0, (gpr)(int32_t)player_table);
        if (player < 0x80000000u || player >= 0x81000000u) {
            return 0;
        }
        const uint32_t block = (uint32_t)MEM_W(0xA0, (gpr)(int32_t)player);
        if (block < 0x80000000u || block >= 0x81000000u) {
            return 0;
        }
        return (uint8_t)MEM_BU(0x29, (gpr)(int32_t)block);
    }

    // Game thread, while photo mode is on: the player's form; on entering, which characters the save has unlocked and
    // the player's own picked; a character asked for.
    void tick_characters(uint8_t* rdram, recomp_context* ctx) {
        if (!characters_checked) {
            player_dragon = tooie::progress_cheats::get_flag(rdram, ctx, dragon_kazooie_flag);
        }
        const uint8_t form = read_player_form(rdram);
        if (form != 0) {
            player_form_now = form + (form == 0x0B && player_dragon ? dragon_form : 0);
        }
        if (!characters_checked) {
            characters_checked = true;
            uint32_t unlocked = 0;
            int own = 0;
            for (int i = 0; i < character_count; i++) {
                const Character& c = characters[i];
                const bool is_own = c.form == (uint16_t)player_form_now.load();
                static const bool all = std::getenv("TOOIE_PHOTO_ALL_CHARACTERS") != nullptr;
                if (is_own || all || c.flag < 0 || tooie::progress_cheats::get_flag(rdram, ctx, c.flag)) {
                    unlocked |= 1u << i;
                }
                if (is_own) {
                    own = i;
                }
            }
            unlocked_characters = unlocked;
            character = own;
        }
        if (const int c = character_request.exchange(-1); c >= 0 && c < character_count && c != character.load()) {
            if (developing) {
                finish_develop(true);
            }
            if (saved_anim.saved) {
                apply_pose(rdram, ctx, 0);
            }
            character = c;
            pose_choice = 0;
            pose_dirty = true;
            grid_cursor = 0;
            grid_worn = 0;
            stand_in_t = 0.0f;
            if (!panel_shown) {
                tooie::toast::show(std::string("Character: ") + characters[c].name);
            }
            fprintf(stderr, "[photo] character %s (form 0x%X, model 0x%X)%s\n", characters[c].name, characters[c].form, characters[c].model,
                stand_in_wanted() ? ", a stand-in" : "");
        }
    }

    void enter(uint8_t* rdram) {
        shots_at_enter = shots.load();
        characters_checked = false;
        character_request = -1;
        if (pose_restore_pending) {
            pose_restore_pending = false;
            saved_anim.saved = false;
        }
        exit_mask = 0;
        mouse_reset = true;
        zoom_notches = 0;
        grid_open = false;
        is_active = true;
        speed = 0;
        fov_scale = 1.0f;
        orbit_toggle = false;
        cam.placed = false;
        cam.orbit = false;
        orbit_on = false;
        players_toggle = false;
        pending_step = 0;
        cam.moving = false;
        entered_map = tooie::debug::current_map(rdram);
        hud_was_hidden = tooie::hide_hud::is_hidden();
        if (!hud_was_hidden) {
            tooie::hide_hud::set_hidden(true);
        }
        {
            std::lock_guard lock{ pad_mutex };
            last_buttons = 0xFFFF;   // buttons already held don't count as presses
        }
        if (!panel_shown) {
            // In the words of what was last used: the controller's N64 buttons, or the keyboard's keys.
            if (recompui::get_cont_active()) {
                tooie::toast::show("Photo mode: A photo, B back, L shows the list");
            }
            else {
                tooie::toast::show("Photo mode: " + key_name(recompinput::GameInput::A) + " or click: photo, " +
                    key_name(recompinput::GameInput::B) + ": back, " + key_name(recompinput::GameInput::L) + ": shows the list");
            }
        }
        fprintf(stderr, "[photo] on\n");
    }

    void leave() {
        // Before is_active goes false, so no pad read in between passes a held button.
        exit_mask = 0xFFFF;
        if (developing) {
            finish_develop(true);
        }
        grid_open = false;
        is_active = false;
        apply_filters(false);
        RT64::SetPhotoFocus(0.5f, 0.5f);
        players_hidden = false;
        others_hidden = false;
        // The HUD as it was on entering, whichever way the HUD row left it.
        if (tooie::hide_hud::is_hidden() != hud_was_hidden) {
            tooie::hide_hud::set_hidden(hud_was_hidden);
        }
        if (timer_running) {
            stop_timer();
        }
        tooie::toast::show("Photo mode off");
        fprintf(stderr, "[photo] off\n");
    }
}

void tooie::photo_mode::register_input() {
    recompinput::set_game_input_name(photo_input, "Photo Mode");
    recompinput::set_game_input_description(photo_input,
        "Freezes the game and hides the HUD so you can fly the camera around and take screenshots. "
        "Left stick moves, right stick or the mouse looks, Z and R go down and up, A or a click takes a screenshot, the mouse wheel zooms. "
        "A list on screen holds zoom, camera, collision, time, HUD, Banjo, his pose, the filters, depth of field, tilt, crop and grid: "
        "D-pad up and down pick a row, left and right change it, L hides the list, A on Pose opens the pose cards. "
        "The list's help shows the keys or the buttons of whichever you used last. "
        "Start runs time at 1/167, 1/8 or 1/4 speed, B goes back to the game.");
    recompinput::set_default_mapping_for_keyboard(photo_input, { recompinput::InputField::keyboard(SDL_SCANCODE_F10) });
    recompinput::set_default_mapping_for_controller(photo_input, { recompinput::InputField::controller_digital(SDL_CONTROLLER_BUTTON_GUIDE) });
}

void tooie::photo_mode::start() {
    std::call_once(started, [] {
        if (const char* v = std::getenv("TOOIE_POSE_SWEEP")) {
            for (const char* p = v; *p != '\0';) {
                unsigned first = 0, last = 0;
                int used = 0;
                if (std::sscanf(p, "%x%n", &first, &used) != 1) {
                    break;
                }
                p += used;
                last = first;
                if (*p == '-' && std::sscanf(p + 1, "%x%n", &last, &used) == 1) {
                    p += 1 + used;
                }
                for (unsigned id = first; id <= last; id++) {
                    pose_sweep.ids.push_back(id);
                }
                if (*p == ',') {
                    p++;
                }
            }
            pose_sweep.active = !pose_sweep.ids.empty();
            const char* frame = std::getenv("TOOIE_POSE_FRAME");
            pose_frame = frame != nullptr ? std::clamp(std::atoi(frame), 0, 20) : 10;
        }
        if (const char* v = std::getenv("TOOIE_PHOTO")) {
            test.active = std::sscanf(v, "%ld:%ld", &test.on, &test.off) == 2;
        }
        std::thread(worker).detach();
    });
}

void tooie::photo_mode::add_options(recomp::config::Config& qol) {
    qol.add_enum_option(look_option, "Photo Filter",
        "A colour look for photo mode (F10). Only shown while photo mode is on, and in its screenshots.",
        {
            {0, "none", "None"},
            {1, "sepia", "Sepia"},
            {2, "bw", "Black and white"},
            {3, "noir", "Noir"},
            {4, "warm", "Warm"},
            {5, "cool", "Cool"},
            {6, "vivid", "Vivid"},
            {7, "faded", "Faded film"},
            {8, "teal_orange", "Teal and orange"},
            {9, "dream", "Dream"},
        },
        0u, true);
    qol.add_number_option(exposure_option, "Photo Exposure", "Brightens or darkens photo mode's picture, in tenths of a stop.", -20, 20, 1, 0, false, 0, true);
    qol.add_number_option(contrast_option, "Photo Contrast", "Photo mode's contrast, in percent.", -50, 50, 5, 0, false, 0, true);
    qol.add_number_option(saturation_option, "Photo Saturation", "Photo mode's colour strength, in percent. -100 is black and white.", -100, 100, 5, 0, false, 0, true);
    qol.add_number_option(warmth_option, "Photo Warmth", "Tints photo mode's picture warmer (up) or cooler (down).", -100, 100, 5, 0, false, 0, true);
    qol.add_number_option(vignette_option, "Photo Vignette", "Darkens the corners of photo mode's picture.", 0, 100, 5, 0, false, 0, true);
    qol.add_number_option(grain_option, "Photo Film Grain", "Adds film grain to photo mode's picture.", 0, 100, 5, 0, false, 0, true);
    qol.add_enum_option(crop_option, "Photo Crop",
        "Frames photo mode's picture to a shape: outside the frame is shaded, and screenshots keep only the frame.",
        {
            {0, "none", "None"},
            {1, "16_9", "16:9"},
            {2, "239_1", "2.39:1"},
            {3, "4_3", "4:3"},
            {4, "1_1", "1:1"},
            {5, "4_5", "4:5"},
            {6, "9_16", "9:16"},
        },
        0u, true);
    qol.add_enum_option(border_option, "Photo Border",
        "A frame round photo mode's picture (inside the crop), kept in its screenshots.",
        {
            {0, "none", "None"},
            {1, "instant", "Instant photo"},
            {2, "film", "Film strip"},
            {3, "honeycomb", "Honeycomb"},
            {4, "jiggy", "Jiggy"},
            {5, "wooden", "Wooden"},
        },
        0u, true);
    qol.add_number_option(tilt_option, "Photo Tilt",
        "Tilts photo mode's camera, in degrees. 0 is level.",
        -45, 45, 1, 0, false, 0, true);
    qol.add_number_option(dof_option, "Photo Depth Of Field",
        "Blurs what is nearer or further than the focus point (the middle of photo mode's picture, unless the photo panel's Focus point row moves it), which stays sharp. 0 is off.",
        0, 100, 5, 0, false, 0, true);
    qol.add_bool_option(shutter_option, "Photo Shutter",
        "Plays a camera click and flashes the screen when photo mode takes a photo. The flash is never in the photo.", true, true);
    qol.add_bool_option(grid_option, "Photo Grid",
        "Draws a rule-of-thirds grid in photo mode, inside the crop frame. It is never in screenshots.", false, true);
    // Was QOL > Photo mode camera collision until L moved it to the photo panel (2026-10-21); same key.
    qol.add_bool_option(tooie::photo_mode_collision_option, "Photo Mode Camera Collision",
        "In photo mode the camera stops at the ground and slides along walls. Off lets it fly through everything.", true, true);
}

bool tooie::photo_mode::panel_state(std::vector<std::string>& rows, int& picked_row) {
    if (!is_active || !panel_shown) {
        return false;
    }
    rows.clear();
    for (int i = 0; i < row_count; i++) {
        rows.push_back(std::string(row_names[i]) + ": " + row_value((Row)i));
    }
    picked_row = picked;
    return true;
}

bool tooie::photo_mode::take_album_request() {
    return album_requested.exchange(false) && is_active;
}

int tooie::photo_mode::shots_taken() {
    return (int)(shots.load() - shots_at_enter.load());
}

bool tooie::photo_mode::active() {
    return is_active;
}

float tooie::photo_mode::crop_aspect() {
    return is_active ? crop_value() : 0.0f;
}

float tooie::photo_mode::adjust_fov(float fov) {
    if (!is_active) {
        return fov;
    }
    if (old_develop()) {
        return card_fov;
    }
    last_fov = fov * fov_scale.load();
    return last_fov;
}

void tooie::photo_mode::apply_input(uint16_t* buttons, float* x, float* y) {
    if (!is_active) {
        // Held since photo mode closed: kept from the game until let go.
        if (const uint16_t mask = exit_mask.load(); mask != 0) {
            const uint16_t held = mask & *buttons;
            exit_mask = held;
            *buttons = (uint16_t)(*buttons & ~held);
        }
        return;
    }
    uint16_t pressed;
    {
        std::lock_guard lock{ pad_mutex };
        pad.buttons = *buttons;
        pad.x = *x;
        pad.y = *y;
        pressed = *buttons & ~last_buttons;
        last_buttons = *buttons;
    }
    // Mouse buttons (when no game button is bound to them): left as A, right as B in the grid. Clicks and wheel
    // turns from before photo mode came on don't count.
    if (mouse_reset.exchange(false)) {
        mouse_clicks_seen = false;
        wheel_seen = false;
    }
    const uint32_t left_clicks = recompinput::get_game_mouse_clicks(SDL_BUTTON_LEFT);
    const uint32_t right_clicks = recompinput::get_game_mouse_clicks(SDL_BUTTON_RIGHT);
    if (mouse_clicks_seen && !mouse_button_bound(SDL_BUTTON_LEFT) && left_clicks != last_left_clicks) {
        pressed |= button_a;
    }
    if (mouse_clicks_seen && !mouse_button_bound(SDL_BUTTON_RIGHT) && right_clicks != last_right_clicks && grid_open) {
        pressed |= button_b;
    }
    last_left_clicks = left_clicks;
    last_right_clicks = right_clicks;
    mouse_clicks_seen = true;
    // The wheel: zoom, or in the grid a row of cards a notch.
    const int32_t wheel = recompinput::get_game_mouse_wheel();
    const int wheel_notches = wheel_seen ? (int)(wheel - last_wheel) : 0;
    last_wheel = wheel;
    wheel_seen = true;

    const Clock::time_point now = Clock::now();
    if (grid_open || developing) {
        grid_input(*buttons, pressed, wheel_notches, now);
        *buttons = 0;
        *x = 0.0f;
        *y = 0.0f;
        return;
    }
    zoom_notches += wheel_notches;
    if (pressed & button_b) {
        leave_requested = true;
    }
    if (pressed & button_a) {
        if ((Row)picked.load() == Row::Album) {
            album_requested = true;
        }
        else if ((Row)picked.load() == Row::Pose) {
            grid_open_request = true;
        }
        else if (timer_choice == 0) {
            shoot();
        }
        else {
            // Started (or, while counting, cancelled) on the game thread.
            timer_requested = true;
        }
    }
    if (pressed & d_up) {
        picked = (picked + row_count - 1) % row_count;
    }
    if (pressed & d_down) {
        picked = (picked + 1) % row_count;
    }
    if (pressed & button_l) {
        panel_shown = !panel_shown;
    }
    // Left / right change the picked row (zoom is held, in place_camera).
    const int dir = (*buttons & d_right ? 1 : 0) - (*buttons & d_left ? 1 : 0);
    if (dir == 0 || (Row)picked.load() == Row::Zoom) {
        step_held_since = {};
    }
    else if (pressed & (d_left | d_right)) {
        step_held_since = now;
        step_last = now;
        pending_step = dir;
    }
    else if (step_held_since != Clock::time_point{} && now - step_held_since >= repeat_delay && now - step_last >= repeat_every) {
        step_last = now;
        pending_step = dir;
    }
    if (pressed & button_start) {
        int s = (speed + 1) % speed_count;
        speed = s;
        if (!panel_shown) {
            tooie::toast::show(speed_names[s]);
        }
    }
    *buttons = 0;
    *x = 0.0f;
    *y = 0.0f;
}

void tooie::photo_mode::tick(uint8_t* rdram, recomp_context* ctx) {
    if (test.active) {
        if (test.begin == Clock::time_point{}) {
            test.begin = Clock::now();
        }
        static const bool game_clock = std::getenv("TOOIE_SCREENSHOT_GAME") != nullptr;   // QA: times in game time
        long ms = game_clock ? (long)tooie::game_frame_rate::game_ms()
                             : (long)std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - test.begin).count();
        if (!test.did_on && ms >= test.on && tooie::debug::can_warp()) {
            test.did_on = true;
            toggle_requested = true;
        }
        if (test.did_on && !test.did_off && ms >= test.off) {
            test.did_off = true;
            if (is_active) {
                leave_requested = true;
            }
        }
    }

    const bool playing = tooie::debug::can_warp() && (uint32_t)MEM_W(0, game_state_addr) == game_state_playing;
    if (toggle_requested.exchange(false)) {
        if (is_active) {
            leave_requested = true;
        }
        else if (playing) {
            enter(rdram);
        }
    }
    const bool asked_to_leave = leave_requested.exchange(false);
    if (is_active && (asked_to_leave || !playing || tooie::debug::current_map(rdram) != entered_map)) {
        fprintf(stderr, "[photo] leaving: %s\n", asked_to_leave ? "asked (B or the key)" : !playing ? "the game stopped playing" : "the map changed");
        if (saved_anim.saved && tooie::debug::current_map(rdram) == entered_map) {
            if (playing) {
                apply_pose(rdram, ctx, 0);
                saved_anim.saved = false;
            }
            else {
                // Not safe to call the animation functions now: put it back once the game plays again.
                pose_restore_pending = true;
            }
        }
        else {
            saved_anim.saved = false;
        }
        pose_choice = 0;
        leave();
    }
    if (pose_restore_pending && !is_active) {
        if (tooie::debug::current_map(rdram) != entered_map) {
            // A new map loads Banjo afresh.
            pose_restore_pending = false;
            saved_anim.saved = false;
        }
        else if (playing) {
            apply_pose(rdram, ctx, 0);
            pose_restore_pending = false;
            saved_anim.saved = false;
        }
    }
    leave_requested = false;
    if (film_stop_pending.exchange(false)) {
        tooie::pose_puppets::film_stop(rdram, ctx);
    }
    if (!is_active) {
        // Leaving takes the stand-in away: the player shows again as he was.
        if (tooie::pose_puppets::stand_in_on()) {
            tooie::pose_puppets::stand_in(rdram, ctx, 0, 0, 0.0f);
        }
        return;
    }

    if (pose_sweep.active) {
        const Clock::time_point now = Clock::now();
        if (pose_sweep.at == Clock::time_point{}) {
            pose_sweep.at = now + 12s;
        }
        if (now >= pose_sweep.at) {
            if (!pose_sweep.shot) {
                if (pose_sweep.next >= pose_sweep.ids.size()) {
                    pose_sweep.active = false;
                    fprintf(stderr, "[pose] sweep done\n");
                }
                else {
                    sweep_anim = pose_sweep.ids[pose_sweep.next++];
                    fprintf(stderr, "[pose] sweep 0x%X\n", sweep_anim);
                    apply_pose(rdram, ctx, sweep_anim);
                    pose_sweep.shot = true;
                    pose_sweep.at = now + 300ms;
                }
            }
            else {
                tooie::screenshot::take();
                pose_sweep.shot = false;
                pose_sweep.at = now + 300ms;
            }
        }
    }
    tick_characters(rdram, ctx);
    tick_grid(rdram, ctx);
    tooie::pose_puppets::set_mirror(mirror_on.load());
    if (developing) {
        step_develop(rdram, ctx);
    }
    if (!old_develop() && stand_in_wanted()) {
        // Another form: the stand-in wears the pose, held at the pose frame while time is frozen, looping in slow time
        // and under the grid's cursor; the player, hidden, is left in his own animation.
        if (saved_anim.saved) {
            apply_pose(rdram, ctx, 0);
        }
        const float scale = speed_scales[speed.load()];
        const Clock::time_point now = Clock::now();
        const float real_dt = std::clamp(std::chrono::duration<float>(now - stand_in_last).count(), 0.0f, 0.1f);
        stand_in_last = now;
        if (pose_dirty.exchange(false)) {
            stand_in_t = std::min((float)pose_frame.load() / 20.0f, 0.999f);
        }
        float t = stand_in_t;
        if (grid_open && grid_scrub >= 0) {
            t = std::min((float)grid_scrub.load() / 20.0f, 0.999f);
        }
        else if (grid_open) {
            t = std::fmod(std::chrono::duration<float>(now - grid_anim_start).count() / pose_loop_seconds, 1.0f);
        }
        else if (scale > 0.0f) {
            stand_in_t = std::fmod(stand_in_t + real_dt * scale / pose_loop_seconds, 1.0f);
            t = stand_in_t;
        }
        else {
            t = std::min((float)pose_frame.load() / 20.0f, 0.999f);
        }
        tooie::pose_puppets::stand_in(rdram, ctx, players_hidden ? 0 : current_character().model, stand_in_anim(pose_choice.load()), t);
    }
    else if (!old_develop()) {
        // The player's own form: posed himself; mirrored, a stand-in in his own look and animation takes his place.
        if (mirror_on && !players_hidden) {
            tooie::pose_puppets::stand_in(rdram, ctx, tooie::pose_puppets::own_look, 0, 0.0f);
        }
        else if (tooie::pose_puppets::stand_in_on()) {
            tooie::pose_puppets::stand_in(rdram, ctx, 0, 0, 0.0f);
        }
        if (pose_dirty.exchange(false)) {
            apply_pose(rdram, ctx, pose_at(pose_choice.load()).anim);
        }
        if (grid_open && pose_choice != 0) {
            // In the grid Banjo plays the pose under the cursor, as its card does.
            const float s = std::chrono::duration<float>(Clock::now() - grid_anim_start).count();
            const int f = grid_scrub.load();
            hold_anim_at(rdram, ctx, f >= 0 ? std::min((float)f / 20.0f, 0.999f) : std::fmod(s / pose_loop_seconds, 1.0f));
        }
        else if (pose_choice != 0 || pose_sweep.active) {
            if (speed == 0) {
                hold_pose_frame(rdram, ctx);
            }
        }
    }

    if (timer_requested.exchange(false)) {
        if (timer_running) {
            stop_timer();
            tooie::toast::show("Timer cancelled");
        }
        else if (timer_choice > 0) {
            timer_running = true;
            timer_end = Clock::now() + std::chrono::seconds(timer_seconds[timer_choice.load()]);
            timer_shown = -1;
        }
    }
    if (timer_running) {
        const auto left = timer_end - Clock::now();
        if (left <= 0ms) {
            stop_timer();
            shoot();
        }
        else {
            const int secs = (int)std::chrono::duration_cast<std::chrono::seconds>(left + 999ms).count();
            if (secs != timer_shown) {
                timer_shown = secs;
                tooie::toast::show("Photo in " + std::to_string(secs));
            }
        }
    }

    if (const int step = pending_step.exchange(0); step != 0) {
        change_row((Row)picked.load(), step);
    }
    if (players_toggle.exchange(false)) {
        players_hidden = !players_hidden;
        if (!panel_shown) {
            tooie::toast::show(players_hidden ? "Banjo hidden" : "Banjo shown");
        }
    }

    // RT64 keys framebuffers by physical address. Not while cards are taken the old way: they are the plain picture.
    if (!old_develop()) {
        apply_filters(true, (uint32_t)MEM_W(0, depth_buffer_ptr) & 0x1FFFFFFFu);
    }

    // Time stands still while cards are taken, so each frame of a pose is only where its animation is held.
    const float scale = old_develop() ? 0.0f : speed_scales[speed.load()];
    const float dt = read_float(rdram, (uint32_t)delta_time_addr);
    game_delta = dt;
    write_float(rdram, (uint32_t)delta_time_addr, scale > 0.0f ? dt * scale : frozen_delta);
}

namespace {
    // Tells RT64 where depth of field focuses, as a fraction of the picture. For Banjo, his middle is
    // projected with the photo camera (yaw 0 looks along -z, turning left as it grows; positive pitch
    // looks up), the game's vertical field of view and the window's shape, then turned with the tilt.
    void place_focus(uint8_t* rdram, float tilt) {
        float fx = 0.5f, fy = 0.5f;
        switch ((Focus)focus_choice.load()) {
        case Focus::TopLeft: fx = 1.0f / 3.0f; fy = 1.0f / 3.0f; break;
        case Focus::TopRight: fx = 2.0f / 3.0f; fy = 1.0f / 3.0f; break;
        case Focus::BottomLeft: fx = 1.0f / 3.0f; fy = 2.0f / 3.0f; break;
        case Focus::BottomRight: fx = 2.0f / 3.0f; fy = 2.0f / 3.0f; break;
        case Focus::Banjo: {
            const uint32_t player = (uint32_t)MEM_W(0, (gpr)(int32_t)player_table);
            const uint32_t transform = player != 0 ? (uint32_t)MEM_W(player_transform, (gpr)(int32_t)player) : 0;
            if (transform == 0) {
                break;
            }
            float v[3];
            for (int i = 0; i < 3; i++) {
                v[i] = read_float(rdram, transform + 4 * i) - cam.pos[i];
            }
            v[1] += banjo_middle;
            const float sy = std::sin(cam.yaw * deg), cy = std::cos(cam.yaw * deg);
            const float sp = std::sin(cam.pitch * deg), cp = std::cos(cam.pitch * deg);
            const float forward[3] = { -sy * cp, sp, -cy * cp };
            const float right[3] = { cy, 0.0f, -sy };
            const float up[3] = { right[1] * forward[2] - right[2] * forward[1], right[2] * forward[0] - right[0] * forward[2],
                right[0] * forward[1] - right[1] * forward[0] };
            const float z = v[0] * forward[0] + v[1] * forward[1] + v[2] * forward[2];
            if (z < 1.0f) {
                break;
            }
            int width = 0, height = 0;
            recompui::get_window_size(width, height);
            const float aspect = width > 0 && height > 0 ? (float)width / (float)height : 16.0f / 9.0f;
            const float t = std::tan(std::clamp(last_fov.load(), 8.0f, 150.0f) * 0.5f * deg);
            // In units of half the picture's height, so the tilt turns them without stretching.
            const float x = (v[0] * right[0] + v[1] * right[1] + v[2] * right[2]) / (z * t);
            const float y = (v[0] * up[0] + v[1] * up[1] + v[2] * up[2]) / (z * t);
            const float st = std::sin(tilt * deg), ct = std::cos(tilt * deg);
            const float tx = x * ct + y * st, ty = -x * st + y * ct;
            fx = std::clamp(0.5f + 0.5f * tx / aspect, 0.02f, 0.98f);
            fy = std::clamp(0.5f - 0.5f * ty, 0.02f, 0.98f);
            break;
        }
        default:
            break;
        }
        RT64::SetPhotoFocus(fx, fy);
        static const bool log = std::getenv("TOOIE_PHOTO_LOG") != nullptr;
        static Clock::time_point last_log;
        if (log && Clock::now() - last_log >= 500ms) {
            last_log = Clock::now();
            fprintf(stderr, "[photo] focus %.3f %.3f\n", fx, fy);
        }
    }
}

bool tooie::photo_mode::place_camera(uint8_t* rdram, recomp_context* ctx, uint32_t camera) {
    if (!is_active) {
        return false;
    }
    const Clock::time_point now = Clock::now();
    if (!cam.placed) {
        // Start where the game's camera is.
        cam.placed = true;
        cam.last = now;
        for (int i = 0; i < 3; i++) {
            cam.pos[i] = read_float(rdram, camera + cam_pos + 4 * i);
        }
        cam.pitch = signed_degrees(read_float(rdram, camera + cam_rot + 0));
        cam.yaw = read_float(rdram, camera + cam_rot + 4);
    }
    const float dt = std::clamp(std::chrono::duration<float>(now - cam.last).count(), 0.0f, 0.1f);
    cam.last = now;

    // Mouse (and gyro) motion since the last frame, in degrees: yaw positive to the left, as the camera's.
    float mouse_yaw = 0.0f, mouse_pitch = 0.0f, gyro_yaw = 0.0f, gyro_pitch = 0.0f;
    tooie::motion_aim::take_orbit(&mouse_yaw, &mouse_pitch, &gyro_yaw, &gyro_pitch);

    if (old_develop()) {
        // Taking pose cards: the card camera, in front of Banjo. The photo camera's own place is kept for after.
        float pos[3], yaw = 0.0f, pitch = 0.0f;
        if (card_camera(rdram, ctx, pos, yaw, pitch)) {
            for (int i = 0; i < 3; i++) {
                write_float(rdram, camera + cam_pos + 4 * i, pos[i]);
            }
            write_float(rdram, camera + cam_rot + 0, pitch < 0.0f ? pitch + 360.0f : pitch);
            write_float(rdram, camera + cam_rot + 4, yaw);
            write_float(rdram, camera + cam_rot + 8, 0.0f);
        }
        return true;
    }

    Pad p;
    {
        std::lock_guard lock{ pad_mutex };
        p = pad;
    }
    // While the grid is open the controls are the grid's: the camera stays where it is.
    if (grid_open) {
        p = Pad{};
        // The mouse sideways scrubs the cursor's card (right is later in the loop).
        scrub_mouse -= mouse_yaw;
        while (std::fabs(scrub_mouse) >= scrub_degrees) {
            const int by = scrub_mouse > 0.0f ? 1 : -1;
            scrub_mouse -= by * scrub_degrees;
            scrub_step(by);
        }
        mouse_yaw = mouse_pitch = 0.0f;
    }
    else {
        scrub_mouse = 0.0f;
    }
    // Look: the right stick, or the C-buttons when the stick is still (keyboard).
    float look_x = 0.0f, look_y = 0.0f;
    if (!grid_open) {
        recompinput::get_right_analog(0, &look_x, &look_y);
        look_y = -look_y;
        tooie::debug::get_scripted_right_stick(&look_x, &look_y);
    }
    look_x = deadzone(look_x);
    look_y = deadzone(look_y);
    if (look_x == 0.0f && look_y == 0.0f) {
        look_x = (p.buttons & c_right ? 1.0f : 0.0f) - (p.buttons & c_left ? 1.0f : 0.0f);
        look_y = (p.buttons & c_up ? 1.0f : 0.0f) - (p.buttons & c_down ? 1.0f : 0.0f);
    }
    // Zoom, held; and the mouse wheel, a step a notch (up zooms in).
    const float zoom = (Row)picked.load() != Row::Zoom ? 0.0f : (p.buttons & d_left ? 1.0f : 0.0f) - (p.buttons & d_right ? 1.0f : 0.0f);
    if (zoom != 0.0f) {
        fov_scale = std::clamp(fov_scale.load() * std::exp(zoom * fov_rate * dt), min_fov_scale, max_fov_scale);
    }
    if (const int notches = zoom_notches.exchange(0); notches != 0) {
        fov_scale = std::clamp(fov_scale.load() * std::exp(-0.12f * (float)notches), min_fov_scale, max_fov_scale);
    }
    if (orbit_toggle.exchange(false)) {
        cam.orbit = !cam.orbit;
        if (cam.orbit) {
            const uint32_t player = (uint32_t)MEM_W(0, (gpr)(int32_t)player_table);
            const uint32_t transform = player != 0 ? (uint32_t)MEM_W(player_transform, (gpr)(int32_t)player) : 0;
            if (transform == 0) {
                cam.orbit = false;
            }
            else {
                for (int i = 0; i < 3; i++) {
                    cam.pivot[i] = read_float(rdram, transform + 4 * i);
                }
                cam.pivot[1] += orbit_height;
                float d[3] = { cam.pivot[0] - cam.pos[0], cam.pivot[1] - cam.pos[1], cam.pivot[2] - cam.pos[2] };
                cam.distance = std::clamp(std::sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]), min_orbit, max_orbit);
                const float len = std::max(1.0f, std::sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]));
                cam.pitch = std::clamp(std::asin(std::clamp(d[1] / len, -1.0f, 1.0f)) / deg, -max_pitch, max_pitch);
                cam.yaw = std::fmod(std::atan2(-d[0], -d[2]) / deg + 360.0f, 360.0f);
                // Headless: TOOIE_PHOTO_ORBIT=<yaw>,<pitch>,<distance>[,<height>] puts the orbit camera
                // there at once (degrees as the camera's; height above Banjo's feet, default 60), so
                // close-ups frame the same whatever the frame rate.
                static const char* fixed = std::getenv("TOOIE_PHOTO_ORBIT");
                float fy, fp, fd, fh = orbit_height;
                if (fixed != nullptr && std::sscanf(fixed, "%f,%f,%f,%f", &fy, &fp, &fd, &fh) >= 3) {
                    cam.pivot[1] += fh - orbit_height;
                    cam.yaw = std::fmod(fy + 360.0f, 360.0f);
                    cam.pitch = std::clamp(fp, -max_pitch, max_pitch);
                    cam.distance = std::clamp(fd, min_orbit, max_orbit);
                }
            }
        }
        orbit_on = cam.orbit;
        if (!panel_shown) {
            tooie::toast::show(cam.orbit ? "Orbit Banjo" : "Free camera");
        }
    }
    const float move_x = deadzone(p.x);
    const float move_y = deadzone(p.y);
    const float rise = (p.buttons & button_r ? 1.0f : 0.0f) - (p.buttons & button_z ? 1.0f : 0.0f);

    const bool moving = move_x != 0.0f || move_y != 0.0f || rise != 0.0f;
    if (moving && !cam.moving) {
        cam.moving_since = now;
    }
    cam.moving = moving;
    const bool fast = moving && now - cam.moving_since >= 1s;
    const float speed_now = move_speed * (fast ? fast_factor : 1.0f);

    if (cam.orbit) {
        // Both sticks circle the pivot; Z / R move closer and further.
        look_x += move_x;
        look_y += move_y;
    }
    // The mouse turns the camera as the right stick does (the gyro is left out: a controller held still in the
    // hands would drift the view).
    cam.yaw = std::fmod(cam.yaw - look_x * look_speed * dt + mouse_yaw + 720.0f, 360.0f);
    cam.pitch = std::clamp(cam.pitch + look_y * look_speed * dt + mouse_pitch, -max_pitch, max_pitch);

    const float sy = std::sin(cam.yaw * deg), cy = std::cos(cam.yaw * deg);
    const float sp = std::sin(cam.pitch * deg), cp = std::cos(cam.pitch * deg);
    const float forward[3] = { -sy * cp, sp, -cy * cp };
    const float right[3] = { cy, 0.0f, -sy };
    const bool collide = collision_on();
    if (cam.orbit) {
        cam.distance = std::clamp(cam.distance + rise * speed_now * dt, min_orbit, max_orbit);
        for (int i = 0; i < 3; i++) {
            cam.pos[i] = cam.pivot[i] - forward[i] * cam.distance;
        }
        if (collide) {
            float normal[3];
            tooie::free_camera::sweep_line(rdram, ctx, cam.pivot, cam.pos, normal);
        }
    }
    else {
        float delta[3];
        for (int i = 0; i < 3; i++) {
            delta[i] = (forward[i] * move_y + right[i] * move_x) * speed_now * dt;
        }
        delta[1] += rise * speed_now * dt;
        if (collide) {
            move_with_collision(rdram, ctx, cam.pos, delta);
        }
        else {
            for (int i = 0; i < 3; i++) {
                cam.pos[i] += delta[i];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        write_float(rdram, camera + cam_pos + 4 * i, cam.pos[i]);
    }
    write_float(rdram, camera + cam_rot + 0, cam.pitch < 0.0f ? cam.pitch + 360.0f : cam.pitch);
    write_float(rdram, camera + cam_rot + 4, cam.yaw);
    // Tilt: the camera's roll, positive turning the picture clockwise.
    const float tilt = (float)qol_value<double>(tooie::photo_mode::tilt_option, 0.0);
    write_float(rdram, camera + cam_rot + 8, tilt < 0.0f ? tilt + 360.0f : tilt);

    place_focus(rdram, tilt);

    static const bool log = std::getenv("TOOIE_PHOTO_LOG") != nullptr;
    static Clock::time_point last_log;
    if (log && now - last_log >= 500ms) {
        last_log = now;
        fprintf(stderr, "[photo] cam %.0f %.0f %.0f yaw %.1f pitch %.1f speed %d dt %.7f (game %.5f) orbit %d dist %.0f fov x%.2f\n",
            cam.pos[0], cam.pos[1], cam.pos[2], cam.yaw, cam.pitch, speed.load(), read_float(rdram, (uint32_t)delta_time_addr),
            game_delta.load(), cam.orbit, cam.distance, fov_scale.load());
    }
    return true;
}

extern "C" int tooie_others_hidden(void) {
    return is_active && others_hidden ? 1 : 0;
}

extern "C" int tooie_players_hidden(void) {
    // Another character is photographed: the player gives way to its stand-in.
    return is_active && (players_hidden || stand_in_wanted() || (mirror_on && !old_develop())) ? 1 : 0;
}

float tooie::photo_mode::flash_level() {
    const int64_t at = last_shot_ns.load();
    if (at == 0) {
        return 0.0f;
    }
    const float t = std::chrono::duration<float>(Clock::now().time_since_epoch() - Clock::duration(at)).count();
    return t >= 0.0f && t < flash_seconds ? 1.0f - t / flash_seconds : 0.0f;
}

// A camera shutter, made up: two short clicks (the shutter opening and closing, 70 ms apart), each a
// burst of noise and a high ring dying away within a few milliseconds.
void tooie::photo_mode::mix_shutter(float* stereo, size_t frames, uint32_t rate, float volume) {
    mix_cues(stereo, frames, rate, volume);
    static uint32_t seen = 0;
    static float time = -1.0f;
    static uint32_t noise = 22222;
    const uint32_t now_shots = shots.load(std::memory_order_relaxed);
    if (now_shots != seen) {
        seen = now_shots;
        time = 0.0f;
    }
    if (time < 0.0f || rate == 0) {
        return;
    }
    constexpr float level = 0.22f;
    constexpr float second_click = 0.07f;
    constexpr float length = 0.12f;
    const float dt = 1.0f / (float)rate;
    for (size_t i = 0; i < frames && time < length; i++, time += dt) {
        float v = 0.0f;
        for (const float start : { 0.0f, second_click }) {
            const float t = time - start;
            if (t < 0.0f) {
                continue;
            }
            noise = noise * 1664525u + 1013904223u;
            const float white = (float)(noise >> 8) / (float)(1u << 24) * 2.0f - 1.0f;
            const float loud = start == 0.0f ? 1.0f : 0.7f;
            v += loud * (white * std::exp(-t / 0.004f) + 0.6f * std::sin(t * 2.0f * 3.14159265f * 2400.0f) * std::exp(-t / 0.012f));
        }
        stereo[i * 2 + 0] += v * level * volume;
        stereo[i * 2 + 1] += v * level * volume;
    }
    if (time >= length) {
        time = -1.0f;
    }
}

namespace {
    // The grid's sounds, made up like the shutter: notes that ring and die away. A cue is a list of notes
    // (start, pitch, length of the ring) played over a short time.
    struct Note {
        float start, hz, ring;
    };
    struct Cue {
        const std::atomic<uint32_t>* counter;
        std::vector<Note> notes;
        float level;
        uint32_t seen = 0;
        float time = -1.0f;
    };

    float cue_length(const Cue& cue) {
        float end = 0.0f;
        for (const Note& n : cue.notes) {
            end = std::max(end, n.start + n.ring * 6.0f);
        }
        return end;
    }
}

void tooie::photo_mode::mix_cues(float* stereo, size_t frames, uint32_t rate, float volume) {
    // A woody tick for a move, a rising two-note pop for a pick, and a bright four-note chime when the cards are
    // ready.
    static Cue cues[] = {
        { &cue_ticks, { { 0.0f, 1480.0f, 0.010f } }, 0.10f },
        { &cue_picks, { { 0.0f, 784.0f, 0.030f }, { 0.06f, 1175.0f, 0.045f } }, 0.10f },
        { &cue_chimes, { { 0.0f, 1047.0f, 0.06f }, { 0.08f, 1319.0f, 0.06f }, { 0.16f, 1568.0f, 0.06f }, { 0.24f, 2093.0f, 0.10f } }, 0.08f },
    };
    if (rate == 0) {
        return;
    }
    const float dt = 1.0f / (float)rate;
    for (Cue& cue : cues) {
        const uint32_t now = cue.counter->load(std::memory_order_relaxed);
        if (now != cue.seen) {
            cue.seen = now;
            cue.time = 0.0f;
        }
        if (cue.time < 0.0f) {
            continue;
        }
        const float length = cue_length(cue);
        for (size_t i = 0; i < frames && cue.time < length; i++, cue.time += dt) {
            float v = 0.0f;
            for (const Note& n : cue.notes) {
                const float t = cue.time - n.start;
                if (t < 0.0f) {
                    continue;
                }
                // A sine with a little of its octave, so it sounds like a struck bar.
                const float phase = t * 2.0f * 3.14159265f * n.hz;
                v += (std::sin(phase) + 0.3f * std::sin(2.0f * phase)) * std::exp(-t / n.ring) * std::min(1.0f, t * 2000.0f);
            }
            stereo[i * 2 + 0] += v * cue.level * volume;
            stereo[i * 2 + 1] += v * cue.level * volume;
        }
        if (cue.time >= length) {
            cue.time = -1.0f;
        }
    }
}

bool tooie::photo_mode::pose_grid(PoseGridView& view) {
    if (!is_active || (!grid_open && !developing)) {
        return false;
    }
    view.open = grid_open;
    view.cursor = grid_cursor;
    view.count = pose_total();
    view.character = current_character().name;
    view.developing = developing;
    view.curtain = old_develop();
    view.developed = developed;
    view.develop_total = develop_total;
    view.scrub = grid_scrub;
    return true;
}

int tooie::photo_mode::pose_count() {
    return pose_total();
}

std::string tooie::photo_mode::pose_name(int index) {
    return index >= 0 && index < pose_total() ? pose_at(index).name : "";
}

std::string tooie::photo_mode::pose_card(int index) {
    if (index < 0 || index >= pose_total()) {
        return "";
    }
    const uint32_t anim = card_anim(index);
    if (anim == 0) {
        return "";
    }
    const uint32_t key = card_key(current_character().model, anim);
    std::lock_guard lock{ store.mutex };
    auto it = store.cards.find(key);
    return it == store.cards.end() || it->second.gen == 0 ? "" : card_prefix(key, it->second.gen);
}

bool tooie::photo_mode::request_character(int index) {
    if (!is_active || index < 0 || index >= ::character_count) {
        return false;
    }
    character_request = index;
    return true;
}

void tooie::photo_mode::set_mirror(bool on) {
    mirror_on = on;
}

bool tooie::photo_mode::mirror() {
    return mirror_on.load();
}

int tooie::photo_mode::character_count() {
    return ::character_count;
}

std::string tooie::photo_mode::character_list() {
    std::string out;
    char line[128];
    const uint32_t unlocked = unlocked_characters.load();
    for (int i = 0; i < ::character_count; i++) {
        const Character& c = characters[i];
        std::snprintf(line, sizeof(line), "%s%2d  %-16s form 0x%X, model 0x%X, %d poses%s%s", i == 0 ? "" : "\n", i, c.name, c.form, c.model,
            c.pose_count, i == character.load() ? "  (picked)" : "", is_active && !(unlocked & (1u << i)) ? "  (locked in this save)" : "");
        out += line;
    }
    return out;
}

std::string tooie::photo_mode::character_name(int index) {
    return index >= 0 && index < ::character_count ? characters[index].name : "";
}

bool tooie::photo_mode::request_pose_grid(bool open) {
    if (!is_active) {
        return false;
    }
    (open ? grid_open_request : grid_close_request) = true;
    return true;
}

bool tooie::photo_mode::request_pose(int index) {
    if (!is_active || index < 0 || index >= pose_total()) {
        return false;
    }
    grid_pick_request = index;
    return true;
}

bool tooie::photo_mode::request_develop(const std::vector<uint32_t>& anims) {
    if (!is_active) {
        return false;
    }
    develop_character(anims.empty() ? all_pose_anims() : anims);
    return true;
}

std::string tooie::photo_mode::pose_list() {
    std::string out;
    char line[96];
    for (int i = 0; i < pose_total(); i++) {
        std::snprintf(line, sizeof(line), "%s%2d  %3X  %s", i == 0 ? "" : "\n", i, pose_at(i).anim, pose_at(i).name);
        out += line;
    }
    return out;
}

tooie::photo_mode::AButton tooie::photo_mode::a_button() {
    switch ((Row)picked.load()) {
    case Row::Pose: return AButton::PoseGrid;
    case Row::Album: return AButton::Album;
    default: return AButton::Photo;
    }
}

void tooie::photo_mode::request_toggle() {
    toggle_requested = true;
}
