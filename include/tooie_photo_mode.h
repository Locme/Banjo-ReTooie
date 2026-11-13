#ifndef __TOOIE_PHOTO_MODE_H__
#define __TOOIE_PHOTO_MODE_H__

#include <cstdint>
#include <string>
#include <vector>

#include "recomp.h"

// Photo mode (handoff 4.82, src/gameplay/photo_mode.cpp): the Photo Mode key (F10, bindable in the
// Controls tab) freezes the game, hides the HUD and flies the camera freely. A takes a screenshot (after
// the self-timer, with a click and flash),
// Start cycles frozen / 1/167 / 1/8 / 1/4 speed, B or the Photo Mode key goes back to the game. An on-screen
// list (the photo panel) picks and changes the camera, time and filter settings with the D-pad.
namespace recomp::config {
    class Config;
}

namespace tooie::photo_mode {
    inline const std::string look_option = "photo_look";
    inline const std::string exposure_option = "photo_exposure";
    inline const std::string contrast_option = "photo_contrast";
    inline const std::string saturation_option = "photo_saturation";
    inline const std::string warmth_option = "photo_warmth";
    inline const std::string vignette_option = "photo_vignette";
    inline const std::string grain_option = "photo_grain";
    inline const std::string crop_option = "photo_crop";
    inline const std::string grid_option = "photo_grid";
    inline const std::string dof_option = "photo_dof";
    inline const std::string tilt_option = "photo_tilt";
    inline const std::string shutter_option = "photo_shutter";
    inline const std::string border_option = "photo_border";

    // Adds photo mode's filter settings to the QOL tab, hidden there: the photo panel changes them (L,
    // 2026-10-19: QOL's Photo Filter section went), and qol.json keeps them.
    void add_options(recomp::config::Config& qol);

    // Names the Photo Mode key and sets its default bindings (before the controls config loads).
    void register_input();

    // Starts the thread that watches the Photo Mode key.
    void start();

    bool active();
    // Same as the photo mode key: turns photo mode on or off on the next frame (developer console).
    void request_toggle();

    // The photo panel's rows ("Name: value") and the picked one; false when the panel isn't shown
    // (photo mode off, or hidden with L). Read by src/ui/photo_panel.cpp.
    bool panel_state(std::vector<std::string>& rows, int& picked_row);
    // Whether the picked row is one that A acts on instead of taking a photo (Pose opens the grid, Album the
    // album), for the panel's help lines.
    enum class AButton { Photo, PoseGrid, Album };
    AButton a_button();

    // The photo crop's width / height while photo mode is on, 0 for none. Screenshots keep only the frame.
    float crop_aspect();

    // The field of view the game sets, zoomed while photo mode is on (tooie_set_fov).
    float adjust_fov(float fov);

    // Takes player 1's input while photo mode is on: the controls drive the camera and the game
    // sees an idle pad.
    void apply_input(uint16_t* buttons, float* x, float* y);

    // How white the shutter flash is now, 1 just after a photo down to 0 (read by src/ui/photo_panel.cpp).
    float flash_level();
    // True once after A on the Album row: the photo panel then opens the menu on its Album tab.
    bool take_album_request();

    // Adds the shutter's click, and the pose grid's tick, pick and "photos ready" chime, to interleaved stereo float
    // samples (main.cpp queue_samples, audio thread).
    void mix_shutter(float* stereo, size_t frames, uint32_t rate, float volume);
    // The grid's sounds alone (mix_shutter calls it).
    void mix_cues(float* stereo, size_t frames, uint32_t rate, float volume);

    // The pose grid (A on the Pose row): a 4 x 5 page of pose cards, each a short looping film of Banjo in that
    // pose, taken by photo mode on this PC the first time the grid opens (the game's own pictures are never
    // shipped) and kept in the app-data folder's pose_cards. Drawn by src/ui/photo_panel.cpp.
    inline constexpr int pose_grid_columns = 4;
    inline constexpr int pose_grid_rows = 5;
    inline constexpr int pose_grid_page = pose_grid_columns * pose_grid_rows;
    inline constexpr int pose_card_frames = 30;
    struct PoseGridView {
        bool open = false;
        int cursor = 0;       // the pose picked in the grid (its index in the pose list)
        int count = 0;        // poses in the list, "Game" first
        bool developing = false;
        int developed = 0;    // of develop_total, while developing
        int develop_total = 0;
        std::string character;   // whose poses they are
        bool curtain = false; // the picture is covered while the cards are taken (the old way, which moves Banjo)
    };
    // False while the grid is shut (and photo mode off).
    bool pose_grid(PoseGridView& view);
    int pose_count();
    std::string pose_name(int index);
    // The UI image name of a pose card's frames, "<prefix><frame>", or "" while it has no card yet (and for "Game").
    // Changes when the card is taken again.
    std::string pose_card(int index);

    // Developer console: open or shut the grid; pick a pose by its place in the list; take the pose cards again
    // (all of them, or the given animation ids, which need not be in the list: for finding new poses).
    // False when photo mode is off.
    bool request_pose_grid(bool open);
    bool request_pose(int index);
    bool request_develop(const std::vector<uint32_t>& anims);
    // The Character row: who is photographed (Banjo and Kazooie, Banjo, Kazooie, Mumbo, Humba Wumba's forms...). Another
    // form than the player's own is drawn as a stand-in where he stands; each has its own poses and pose cards.
    // request_character is false when photo mode is off.
    bool request_character(int index);
    int character_count();
    std::string character_name(int index);
    // One line per character: its place, name, form and model, how many poses, and whether picked or locked.
    std::string character_list();
    // One line per pose: its place, animation id and name.
    std::string pose_list();

    // Once per frame on the game thread (tooie_warp_tick): enters and leaves, and slows game time.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // From the camera controller hook (tooie_free_camera) with the viewport camera; returns true
    // when photo mode placed the camera.
    bool place_camera(uint8_t* rdram, recomp_context* ctx, uint32_t camera);
}

#endif
