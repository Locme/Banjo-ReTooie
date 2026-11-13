#pragma once

#include <cstdint>
#include <functional>
#include <string>
#include <vector>

#include "recomp.h"

// Pose puppets (src/gameplay/pose_puppets.cpp): extra copies of Banjo's model, each posed by an animation controller
// of its own, drawn without moving the player's Banjo or the camera. Photo mode films its pose cards with them,
// off screen; the console's `puppet` command draws some beside Banjo to look at.
namespace tooie::pose_puppets {
    // ---- Filming (photo mode's pose cards) ----
    // One picture to take: animation anim held at t (0 to 1). id is the caller's own, handed back with the picture.
    struct Shot {
        uint32_t anim = 0;
        float t = 0.0f;
        uint32_t id = 0;
    };
    // A picture back: Banjo alone on a transparent background, side x side packed RGBA (straight alpha), on a
    // thread of its own.
    using ShotCallback = std::function<void(uint32_t id, uint32_t side, std::vector<uint8_t>&& rgba)>;
    // Starts filming: room in the game's heap for the picture, controllers for the copies. False when there is no
    // player or no room (nothing is held then). Game thread.
    // model: another form's model id (photo mode's Character row), 0 for the player's own look; size scales the card
    // camera's distance and height, for forms bigger or smaller than Banjo.
    bool film_start(uint8_t* rdram, recomp_context* ctx, ShotCallback callback, uint16_t model = 0, float size = 1.0f);
    // Stops and gives the room back. Game thread.
    void film_stop(uint8_t* rdram, recomp_context* ctx);
    bool filming();
    // How many shots a frame takes.
    int film_cells();
    // The shots for the next frame drawn (at most film_cells()). Game thread.
    void film_next(std::vector<Shot> shots);
    // Frames drawn whose picture has not come back yet.
    int film_in_flight();

    // ---- The stand-in (photo mode's Character row) ----
    // Another form's model drawn where the player stands, turned as he is, posed by animation `anim` held at t (0 to 1).
    // Photo mode hides the player meanwhile. Called each game update while wanted; model 0 takes it away. Game thread.
    // model own_look: the player's own look (Kazooie in the backpack, his eyes) in his own animation as it plays, for
    // photo mode's Mirror on the player's own form (anim and t are not used then).
    constexpr uint16_t own_look = 0xFFFF;
    void stand_in(uint8_t* rdram, recomp_context* ctx, uint16_t model, uint32_t anim, float t);
    bool stand_in_on();
    // Photo mode's Mirror: the stand-in is drawn flipped left to right (its own left and right swapped, turned as
    // before). Any thread.
    void set_mirror(bool on);

    // ---- Looking (the console's puppet command) ----
    // Adds a copy beside Banjo playing animation `anim` held at `t` (0 to 1), dx, dz world units from him. Game
    // thread. Returns an error, or "" when added.
    std::string add(uint8_t* rdram, recomp_context* ctx, uint32_t anim, float t, float dx, float dz);
    // Removes all copies.
    void clear(uint8_t* rdram, recomp_context* ctx);
    // A line per copy.
    std::string list();
}
