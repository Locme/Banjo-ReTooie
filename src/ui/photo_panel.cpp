// The photo panel (handoff 4.82): while photo mode is on and the panel isn't hidden (L), a list at the
// left of the screen shows photo mode's rows (tooie::photo_mode::panel_state) with the picked one
// highlighted, and the controls under it, styled like the settings menu. Like the toasts it is a UI layer that never takes input, so
// it is never in screenshots.
//
// The controls under the list follow what was used last (recompui::get_cont_active, as the menus' button hints do):
// the controller's buttons, or the keyboard's keys and the mouse, each drawn with the glyph of what it is bound to in
// the active input profile (promptfont), so a rebound key shows as itself. They change the moment the other is used.
//
// The pose grid (A on the Pose row, tooie::photo_mode::pose_grid) takes the list's place: a 4 x 5 page of pose cards,
// each a short film of Banjo in that pose played over and over, the picked one in gold with a Jiggy. While photo mode
// takes the cards, a dark red darkroom curtain covers the picture (it is the menus' layer, so never in the cards) and
// the cards fill in as they come out.

#include <algorithm>
#include <chrono>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include "recompui/recompui.h"
#include "elements/ui_element.h"
#include "elements/ui_image.h"
#include "elements/ui_label.h"
#include "elements/ui_sidebar_style.h"
#include "elements/ui_svg.h"
#include "elements/ui_modal.h"
#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "recompinput/profiles.h"
#include "recompinput/promptfont.h"

#include "tooie_photo_album.h"
#include "tooie_photo_mode.h"
#include "tooie_photo_panel.h"

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;
    using recompinput::GameInput;
    namespace photo = tooie::photo_mode;

    constexpr auto poll_interval = 50ms;
    constexpr auto grid_interval = 16ms;
    constexpr auto flash_interval = 16ms;
    constexpr auto ui_wait = 500ms;
    constexpr size_t max_rows = 20;
    // How long each frame of a pose card shows: 30 a second, the game's own animation rate (30 frames make the
    // second a pose loop takes).
    constexpr int card_frame_ms = 33;
    constexpr float card_image = 120.0f;
    // Honeycombs made for pages: enough for any character's poses.
    constexpr int max_pages = 4;

    std::once_flag started;

    namespace style = recompui::sidebar_style;
    const recompui::Color clear{ 0, 0, 0, 0 };
    // The darkroom curtain while cards are taken: a deep safelight red.
    const recompui::Color darkroom{ 46, 6, 4, 238 };
    // Behind Banjo on a card.
    const recompui::Color card_back{ 104, 62, 26, 255 };

    // ---- The controls, in the words of the controller or of the keyboard and mouse ----

    // A piece of a help line: words, a game button (drawn as what the active profile binds to it), or a glyph.
    struct Seg {
        enum class Kind { Text, Input, Glyph } kind;
        std::string text;
        GameInput input = GameInput::COUNT;
    };
    using Line = std::vector<Seg>;
    Seg T(std::string text) { return { Seg::Kind::Text, std::move(text) }; }
    Seg I(GameInput input) { return { Seg::Kind::Input, "", input }; }
    Seg G(const char* glyph) { return { Seg::Kind::Glyph, glyph }; }

    enum class HelpMode { Panel, Grid, Developing };

    // The active profile: the single-player controller or keyboard one, whichever was used last.
    int help_profile(bool pad) {
        try {
            return pad ? recompinput::profiles::get_sp_controller_profile_index() : recompinput::profiles::get_sp_keyboard_profile_index();
        } catch (...) {
            return -1;
        }
    }

    // What the profile binds to a game button, as promptfont glyphs ("" when nothing is).
    std::string bound_glyph(int profile, GameInput input, bool pad) {
        if (profile < 0) {
            return "";
        }
        try {
            for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                const recompinput::InputField& f = recompinput::profiles::get_input_binding(profile, input, b);
                if (f.is_empty()) {
                    continue;
                }
                // The keyboard profile's mouse bindings belong to it too; a controller binding never shows for the keyboard.
                const bool is_pad = f.input_type == recompinput::InputType::ControllerDigital || f.input_type == recompinput::InputType::ControllerAnalog;
                if (is_pad == pad) {
                    return f.to_string();
                }
            }
        } catch (...) {
        }
        return "";
    }

    std::vector<Line> help_lines(bool pad, HelpMode mode, photo::AButton a) {
        const std::string a_text = a == photo::AButton::PoseGrid ? " pose cards" : a == photo::AButton::Album ? " album" : " photo";
        const Seg dot = T("  ·  ");
        if (mode == HelpMode::Developing) {
            // The page shown is developed first, so turning to another one is worth showing.
            return { { I(GameInput::L), T(" / "), I(GameInput::R), T(" page"), dot, I(GameInput::B), T(" stop developing") } };
        }
        if (mode == HelpMode::Grid) {
            if (pad) {
                return {
                    { I(GameInput::DPAD_UP), I(GameInput::DPAD_DOWN), I(GameInput::DPAD_LEFT), I(GameInput::DPAD_RIGHT), T(" pick a card"), dot,
                      I(GameInput::L), T(" / "), I(GameInput::R), T(" page") },
                    { I(GameInput::A), T(" wear it"), dot, I(GameInput::B), T(" back"), dot, I(GameInput::START), T(" develop again") },
                };
            }
            return {
                { I(GameInput::DPAD_UP), I(GameInput::DPAD_DOWN), I(GameInput::DPAD_LEFT), I(GameInput::DPAD_RIGHT), T(" / "),
                  G(PF_MOUSE_SCROLL_UP), G(PF_MOUSE_SCROLL_DOWN), T(" pick a card") },
                { I(GameInput::L), T(" / "), I(GameInput::R), T(" page") },
                { I(GameInput::A), T(" / "), G(PF_MOUSE_LEFT), T(" wear it"), dot, I(GameInput::B), T(" / "), G(PF_MOUSE_RIGHT), T(" back"), dot,
                  I(GameInput::START), T(" develop again") },
            };
        }
        if (pad) {
            return {
                { I(GameInput::DPAD_UP), I(GameInput::DPAD_DOWN), T(" pick a row"), dot, I(GameInput::DPAD_LEFT), I(GameInput::DPAD_RIGHT), T(" change it") },
                { G(PF_ANALOG_L), T(" move"), dot, G(PF_ANALOG_R), T(" look"), dot, I(GameInput::Z), T(" / "), I(GameInput::R), T(" down / up") },
                { I(GameInput::A), T(a_text), dot, I(GameInput::L), T(" hide list") },
                { I(GameInput::START), T(" time"), dot, I(GameInput::B), T(" back to the game") },
            };
        }
        return {
            { I(GameInput::DPAD_UP), I(GameInput::DPAD_DOWN), T(" pick a row"), dot, I(GameInput::DPAD_LEFT), I(GameInput::DPAD_RIGHT), T(" change it") },
            { I(GameInput::Y_AXIS_POS), I(GameInput::X_AXIS_NEG), I(GameInput::Y_AXIS_NEG), I(GameInput::X_AXIS_POS), T(" move"), dot,
              G(PF_MOUSE_ANY), T(" look") },
            { I(GameInput::Z), T(" / "), I(GameInput::R), T(" down / up"), dot, G(PF_MOUSE_SCROLL_UP), G(PF_MOUSE_SCROLL_DOWN), T(" zoom") },
            { I(GameInput::A), T(" / "), G(PF_MOUSE_LEFT), T(a_text), dot, I(GameInput::L), T(" hide list") },
            { I(GameInput::START), T(" time"), dot, I(GameInput::B), T(" back to the game") },
        };
    }

    // The box the help lines are drawn in, and what it shows now.
    struct Help {
        recompui::Element* box = nullptr;
        std::string key;
    };

    recompui::Element* make_help_box(recompui::ContextId& ctx, recompui::Element* parent) {
        recompui::Element* box = ctx.create_element<recompui::Element>(parent);
        box->set_display(recompui::Display::Flex);
        box->set_flex_direction(recompui::FlexDirection::Column);
        box->set_gap(2);
        box->set_margin_top(10);
        box->set_padding(8);
        box->set_border_radius(recompui::theme::border::radius_md);
        box->set_border_top_width(2);
        box->set_border_top_color(style::gold_soft);
        box->set_background_color(style::sidebar);
        box->set_pointer_events(recompui::PointerEvents::None);
        return box;
    }

    // Draws the help lines again when the device, its profile or what they are for has changed. In the open context.
    void render_help(recompui::ContextId& ctx, Help& help, HelpMode mode, photo::AButton a) {
        const bool pad = recompui::get_cont_active();
        const int profile = help_profile(pad);
        const std::string key = std::to_string(pad) + "/" + std::to_string(profile) + "/" + std::to_string((int)mode) + "/" + std::to_string((int)a);
        if (key == help.key || help.box == nullptr) {
            return;
        }
        help.key = key;
        help.box->clear_children();

        // Which it is: a controller or the keyboard and mouse.
        recompui::Element* head = ctx.create_element<recompui::Element>(help.box);
        head->set_display(recompui::Display::Flex);
        head->set_flex_direction(recompui::FlexDirection::Row);
        head->set_align_items(recompui::AlignItems::Center);
        head->set_gap(6);
        head->set_margin_bottom(2);
        recompui::Svg* icon = ctx.create_element<recompui::Svg>(head, pad ? "icons/Cont.svg" : "icons/Keyboard.svg");
        icon->set_width(20);
        icon->set_height(20);
        icon->set_image_color(style::gold);
        recompui::Label* which = ctx.create_element<recompui::Label>(head, pad ? "Controller" : "Keyboard and Mouse", recompui::LabelStyle::Annotation);
        which->set_font_family(style::font);
        which->set_font_weight(400);
        which->set_letter_spacing(1);
        which->set_color(style::gold);

        for (const Line& line : help_lines(pad, mode, a)) {
            recompui::Element* row = ctx.create_element<recompui::Element>(help.box);
            row->set_display(recompui::Display::Flex);
            row->set_flex_direction(recompui::FlexDirection::Row);
            row->set_flex_wrap(recompui::FlexWrap::Wrap);
            row->set_align_items(recompui::AlignItems::Center);
            row->set_pointer_events(recompui::PointerEvents::None);
            for (const Seg& seg : line) {
                std::string text = seg.text;
                bool glyph = seg.kind == Seg::Kind::Glyph;
                if (seg.kind == Seg::Kind::Input) {
                    text = bound_glyph(profile, seg.input, pad);
                    glyph = !text.empty();
                    if (!glyph) {
                        // Not bound: the N64 button's name.
                        text = "[" + recompinput::get_game_input_name(seg.input) + "]";
                    }
                }
                recompui::Label* label = ctx.create_element<recompui::Label>(row, text, recompui::LabelStyle::Annotation);
                label->set_pointer_events(recompui::PointerEvents::None);
                label->set_white_space(recompui::WhiteSpace::Pre);
                if (glyph) {
                    label->set_font_family("promptfont");
                    label->set_font_style(recompui::FontStyle::Normal);
                    label->set_font_weight(400);
                    label->set_font_size(20);
                    label->set_color(style::cream);
                }
                else {
                    label->set_color(style::cream_dim);
                }
            }
        }
    }

    // ---- The list ----

    // One row of the list: a Jiggy shown on the picked row (as on the settings menu's picked tab), the
    // row's name and its value.
    struct RowView {
        recompui::Element* box = nullptr;
        recompui::Svg* jiggy = nullptr;
        recompui::Label* name = nullptr;
        recompui::Label* value = nullptr;
    };

    struct Panel {
        recompui::ContextId context = recompui::ContextId::null();
        std::vector<RowView> rows;
        Help help;
        bool shown = false;
        std::vector<std::string> last_rows;
        int last_picked = -1;
        size_t first = 0; // the first row shown, when there are more rows than fit
    };

    recompui::Label* make_title(recompui::ContextId& ctx, recompui::Element* parent, const char* text) {
        recompui::Label* title = ctx.create_element<recompui::Label>(parent, text, recompui::LabelStyle::Normal);
        title->set_pointer_events(recompui::PointerEvents::None);
        title->set_font_family(style::font);
        title->set_font_weight(400);
        title->set_font_size(38);
        title->set_letter_spacing(2);
        title->set_color(style::gold);
        title->set_padding_left(6);
        return title;
    }

    recompui::Element* make_frame(recompui::ContextId& ctx, recompui::Element* root) {
        recompui::Element* box = ctx.create_element<recompui::Element>(root);
        box->set_display(recompui::Display::Flex);
        box->set_flex_direction(recompui::FlexDirection::Column);
        box->set_align_items(recompui::AlignItems::Stretch);
        box->set_position(recompui::Position::Absolute);
        box->set_top(24);
        box->set_left(24);
        box->set_padding(14);
        box->set_border_radius(recompui::theme::border::radius_lg);
        box->set_border_width(3);
        box->set_border_color(style::gold);
        box->set_background_color(style::panel);
        box->set_pointer_events(recompui::PointerEvents::None);
        return box;
    }

    recompui::Element* make_root(recompui::ContextId& ctx) {
        recompui::Element* root = ctx.create_element<recompui::Element>(ctx.get_root_element());
        root->set_display(recompui::Display::Flex);
        root->set_position(recompui::Position::Absolute);
        root->set_top(0);
        root->set_left(0);
        root->set_width(100.0f, recompui::Unit::Percent);
        root->set_height(100.0f, recompui::Unit::Percent);
        root->set_background_color(recompui::theme::color::Transparent);
        root->set_pointer_events(recompui::PointerEvents::None);
        return root;
    }

    // In the settings menu's colours and lettering (L: "You can copy the ESC menu"): a brown panel with a
    // gold border, the title in Luckiest Guy, the picked row in gold with brown letters.
    bool build(Panel& p) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return false;
        }
        try {
            recompui::ContextId ctx = recompui::create_context();
            ctx.open();
            recompui::Element* root = make_root(ctx);
            recompui::Element* box = make_frame(ctx, root);
            box->set_width(470);
            make_title(ctx, box, "Photo Mode")->set_margin_bottom(8);

            for (size_t i = 0; i < max_rows; i++) {
                RowView r;
                r.box = ctx.create_element<recompui::Element>(box);
                r.box->set_display(recompui::Display::Flex);
                r.box->set_flex_direction(recompui::FlexDirection::Row);
                r.box->set_align_items(recompui::AlignItems::Center);
                r.box->set_position(recompui::Position::Relative);
                r.box->set_padding_top(3);
                r.box->set_padding_bottom(2);
                r.box->set_padding_left(36);
                r.box->set_padding_right(10);
                r.box->set_border_radius(recompui::theme::border::radius_md);
                r.box->set_border_width(2);
                r.box->set_border_color(recompui::theme::color::Transparent);
                r.box->set_border_bottom_color(style::gold_faint);
                r.box->set_pointer_events(recompui::PointerEvents::None);

                r.jiggy = ctx.create_element<recompui::Svg>(r.box, "icons/Jiggy.svg");
                r.jiggy->set_position(recompui::Position::Absolute);
                r.jiggy->set_left(6);
                r.jiggy->set_top(50.0f, recompui::Unit::Percent);
                r.jiggy->set_width(22);
                r.jiggy->set_height(22);
                r.jiggy->set_margin_top(-11);
                r.jiggy->set_pointer_events(recompui::PointerEvents::None);

                r.name = ctx.create_element<recompui::Label>(r.box, "", recompui::LabelStyle::Small);
                r.name->set_pointer_events(recompui::PointerEvents::None);
                r.name->set_font_family(style::font);
                r.name->set_font_weight(400);
                r.name->set_font_size(20);
                r.name->set_letter_spacing(1);
                r.name->set_flex_grow(1);

                r.value = ctx.create_element<recompui::Label>(r.box, "", recompui::LabelStyle::Small);
                r.value->set_pointer_events(recompui::PointerEvents::None);
                r.value->set_text_align(recompui::TextAlign::Right);
                p.rows.push_back(r);
            }

            p.help.box = make_help_box(ctx, box);
            render_help(ctx, p.help, HelpMode::Panel, photo::a_button());
            ctx.close();

            // The panel must never swallow the game's input.
            ctx.set_captures_input(false);
            ctx.set_captures_mouse(false);
            p.context = ctx;
            return true;
        } catch (...) {
            return false;
        }
    }

    void update(Panel& p, const std::vector<std::string>& rows, int picked) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        p.context.open();
        render_help(p.context, p.help, HelpMode::Panel, photo::a_button());
        if (rows == p.last_rows && picked == p.last_picked) {
            p.context.close();
            return;
        }
        // More rows than fit: the list scrolls, moving only when the picked row would leave it.
        const size_t shown = p.rows.size();
        if (rows.size() <= shown) {
            p.first = 0;
        }
        else {
            const size_t pick = (size_t)std::max(picked, 0);
            if (pick < p.first) {
                p.first = pick;
            }
            else if (pick >= p.first + shown) {
                p.first = pick + 1 - shown;
            }
            p.first = std::min(p.first, rows.size() - shown);
        }
        for (size_t v = 0; v < shown; v++) {
            RowView& r = p.rows[v];
            const size_t i = p.first + v;
            if (i >= rows.size()) {
                r.box->set_display(recompui::Display::None);
                continue;
            }
            // Rows come as "Name: value".
            const std::string& text = rows[i];
            const size_t split = text.find(": ");
            const std::string name = split == std::string::npos ? text : text.substr(0, split);
            const std::string value = split == std::string::npos ? "" : text.substr(split + 2);
            const bool is_picked = (int)i == picked;
            r.name->set_text(name);
            // Arrows on the picked row: D-pad left and right change it.
            r.value->set_text(is_picked && !value.empty() ? "‹ " + value + " ›" : value);
            r.name->set_color(is_picked ? style::brown_text : style::cream);
            r.value->set_color(is_picked ? style::brown_text : style::gold);
            r.box->set_background_color(is_picked ? style::gold : clear);
            r.box->set_border_color(is_picked ? style::orange : clear);
            if (!is_picked) {
                r.box->set_border_bottom_color(style::gold_faint);
            }
            r.jiggy->set_display(is_picked ? recompui::Display::Block : recompui::Display::None);
            r.box->set_display(recompui::Display::Flex);
        }
        p.context.close();
        p.last_rows = rows;
        p.last_picked = picked;
    }

    // ---- The pose grid ----

    struct CardView {
        recompui::Element* box = nullptr;
        recompui::Element* frame = nullptr;     // the picture's square
        recompui::Image* image = nullptr;
        recompui::Svg* placeholder = nullptr;   // a honeycomb while it has no card; a Jiggy for "Game"
        recompui::Svg* jiggy = nullptr;         // on the picked card
        recompui::Label* name = nullptr;
        int index = -2;
        std::string prefix;
        int frame_shown = -1;
        int state = -1;                         // 0 empty, 1 placeholder, 2 picture
        int picked = -1;
    };

    // Lines said while the cards come out of the darkroom, one after another.
    const char* const develop_quips[] = {
        "Hold still, Banjo!",
        "Say \"honeycomb\"!",
        "Kazooie, stop pulling faces!",
        "Mixing the darkroom potions...",
        "Shaking the pictures dry...",
        "Hanging them on the line...",
    };

    struct Grid {
        recompui::ContextId context = recompui::ContextId::null();
        recompui::Element* root = nullptr;
        recompui::Label* page = nullptr;
        std::vector<recompui::Svg*> pips;
        std::vector<CardView> cards;
        recompui::Element* develop = nullptr;
        recompui::Label* develop_label = nullptr;
        recompui::Label* develop_quip = nullptr;
        recompui::Element* develop_fill = nullptr;
        Help help;
        bool shown = false;
        int pages = 1;
        int last_page = -1;
        int last_count = -1;
        std::string last_character;
        bool last_developing = false;
        bool last_curtain = false;
        int last_developed = -1;
        int last_quip = -1;
    };

    bool build_grid(Grid& g) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return false;
        }
        try {
            recompui::ContextId ctx = recompui::create_context();
            ctx.open();
            g.root = make_root(ctx);
            recompui::Element* box = make_frame(ctx, g.root);

            // The title, and the page with a honeycomb for each page (the one shown lit).
            recompui::Element* head = ctx.create_element<recompui::Element>(box);
            head->set_display(recompui::Display::Flex);
            head->set_flex_direction(recompui::FlexDirection::Row);
            head->set_align_items(recompui::AlignItems::Center);
            head->set_margin_bottom(8);
            make_title(ctx, head, "Pose Cards")->set_flex_grow(1);
            // A honeycomb for each page, as many as the character with the most poses needs; those past the picked
            // character's last page are hidden.
            for (int i = 0; i < max_pages; i++) {
                recompui::Svg* pip = ctx.create_element<recompui::Svg>(head, "icons/Honeycomb.svg");
                pip->set_width(22);
                pip->set_height(22);
                pip->set_margin_left(4);
                g.pips.push_back(pip);
            }
            g.page = ctx.create_element<recompui::Label>(head, "", recompui::LabelStyle::Small);
            g.page->set_font_family(style::font);
            g.page->set_font_weight(400);
            g.page->set_font_size(18);
            g.page->set_color(style::cream_dim);
            g.page->set_margin_left(10);

            recompui::Element* cards = ctx.create_element<recompui::Element>(box);
            cards->set_display(recompui::Display::Flex);
            cards->set_flex_direction(recompui::FlexDirection::Row);
            cards->set_flex_wrap(recompui::FlexWrap::Wrap);
            cards->set_gap(8);
            cards->set_width(photo::pose_grid_columns * (card_image + 14.0f) + (photo::pose_grid_columns - 1) * 8.0f);
            for (int i = 0; i < photo::pose_grid_page; i++) {
                CardView c;
                c.box = ctx.create_element<recompui::Element>(cards);
                c.box->set_display(recompui::Display::Flex);
                c.box->set_flex_direction(recompui::FlexDirection::Column);
                c.box->set_align_items(recompui::AlignItems::Center);
                c.box->set_position(recompui::Position::Relative);
                c.box->set_width(card_image + 14.0f);
                c.box->set_padding(4);
                c.box->set_border_width(3);
                c.box->set_border_radius(recompui::theme::border::radius_md);
                c.box->set_border_color(style::gold_faint);
                c.box->set_background_color(style::sidebar);

                // The picture, on a cream mount like an instant photo.
                c.frame = ctx.create_element<recompui::Element>(c.box);
                c.frame->set_position(recompui::Position::Relative);
                c.frame->set_width(card_image);
                c.frame->set_height(card_image);
                c.frame->set_border_radius(4);
                c.frame->set_overflow(recompui::Overflow::Hidden);
                c.frame->set_background_color(card_back);
                // Banjo is cut out (no background, src/gameplay/photo_mode.cpp keys it out), so he stands on a
                // warm card with a big faint honeycomb behind him.
                recompui::Svg* backdrop = ctx.create_element<recompui::Svg>(c.frame, "icons/Honeycomb.svg");
                backdrop->set_position(recompui::Position::Absolute);
                backdrop->set_left(card_image * 0.1f);
                backdrop->set_top(card_image * 0.1f);
                backdrop->set_width(card_image * 0.8f);
                backdrop->set_height(card_image * 0.8f);
                backdrop->set_opacity(0.12f);
                c.image = ctx.create_element<recompui::Image>(c.frame, "");
                c.image->set_position(recompui::Position::Absolute);
                c.image->set_left(0);
                c.image->set_top(0);
                c.image->set_width(card_image);
                c.image->set_height(card_image);
                c.placeholder = ctx.create_element<recompui::Svg>(c.frame, "icons/Honeycomb.svg");
                c.placeholder->set_position(recompui::Position::Absolute);
                c.placeholder->set_left(card_image * 0.5f - 28.0f);
                c.placeholder->set_top(card_image * 0.5f - 28.0f);
                c.placeholder->set_width(56);
                c.placeholder->set_height(56);

                c.jiggy = ctx.create_element<recompui::Svg>(c.box, "icons/Jiggy.svg");
                c.jiggy->set_position(recompui::Position::Absolute);
                c.jiggy->set_left(-10);
                c.jiggy->set_top(-10);
                c.jiggy->set_width(30);
                c.jiggy->set_height(30);

                c.name = ctx.create_element<recompui::Label>(c.box, "", recompui::LabelStyle::Small);
                c.name->set_font_family(style::font);
                c.name->set_font_weight(400);
                c.name->set_font_size(15);
                c.name->set_letter_spacing(1);
                c.name->set_margin_top(3);
                c.name->set_white_space(recompui::WhiteSpace::Nowrap);
                g.cards.push_back(c);
            }

            // While the cards are taken: how far along, and a line from the darkroom.
            g.develop = ctx.create_element<recompui::Element>(box);
            g.develop->set_display(recompui::Display::None);
            g.develop->set_flex_direction(recompui::FlexDirection::Column);
            g.develop->set_margin_top(10);
            g.develop_label = ctx.create_element<recompui::Label>(g.develop, "", recompui::LabelStyle::Normal);
            g.develop_label->set_font_family(style::font);
            g.develop_label->set_font_weight(400);
            g.develop_label->set_font_size(24);
            g.develop_label->set_letter_spacing(1);
            g.develop_label->set_color(style::gold);
            recompui::Element* track = ctx.create_element<recompui::Element>(g.develop);
            track->set_height(14);
            track->set_margin_top(4);
            track->set_border_radius(7);
            track->set_border_width(2);
            track->set_border_color(style::gold_soft);
            track->set_background_color(style::sidebar);
            track->set_overflow(recompui::Overflow::Hidden);
            g.develop_fill = ctx.create_element<recompui::Element>(track);
            g.develop_fill->set_height(100.0f, recompui::Unit::Percent);
            g.develop_fill->set_width(0.0f, recompui::Unit::Percent);
            g.develop_fill->set_background_color(style::orange);
            g.develop_quip = ctx.create_element<recompui::Label>(g.develop, "", recompui::LabelStyle::Annotation);
            g.develop_quip->set_color(style::cream_dim);
            g.develop_quip->set_margin_top(4);

            g.help.box = make_help_box(ctx, box);
            ctx.close();
            ctx.set_captures_input(false);
            ctx.set_captures_mouse(false);
            g.context = ctx;
            return true;
        } catch (...) {
            return false;
        }
    }

    void update_grid(Grid& g, const photo::PoseGridView& view) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        const int page = view.cursor / photo::pose_grid_page;
        const long long ms = std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now().time_since_epoch()).count();
        g.context.open();
        render_help(g.context, g.help, view.developing ? HelpMode::Developing : HelpMode::Grid, photo::AButton::Photo);

        if (page != g.last_page || view.count != g.last_count || view.character != g.last_character) {
            g.last_page = page;
            g.last_count = view.count;
            g.last_character = view.character;
            g.pages = std::max(1, (view.count + photo::pose_grid_page - 1) / photo::pose_grid_page);
            for (int i = 0; i < (int)g.pips.size(); i++) {
                g.pips[i]->set_display(i < g.pages ? recompui::Display::Block : recompui::Display::None);
                g.pips[i]->set_opacity(i == page ? 1.0f : 0.3f);
            }
            g.page->set_text(view.character + "  ·  Page " + std::to_string(page + 1) + " of " + std::to_string(g.pages));
            // Another character: every card is looked at again.
            for (CardView& c : g.cards) {
                c.index = -2;
            }
        }

        for (int slot = 0; slot < (int)g.cards.size(); slot++) {
            CardView& c = g.cards[slot];
            const int index = page * photo::pose_grid_page + slot;
            if (index != c.index) {
                c.index = index;
                c.prefix.clear();
                c.state = -1;
                c.frame_shown = -1;
                c.picked = -1;
                c.name->set_text(index < view.count ? photo::pose_name(index) : "");
            }
            if (index >= view.count) {
                if (c.state != 0) {
                    c.state = 0;
                    c.box->set_visibility(recompui::Visibility::Hidden);
                }
                continue;
            }
            const std::string prefix = photo::pose_card(index);
            const int state = prefix.empty() ? 1 : 2;
            if (state != c.state || prefix != c.prefix) {
                c.state = state;
                c.prefix = prefix;
                c.frame_shown = -1;
                c.box->set_visibility(recompui::Visibility::Visible);
                c.image->set_display(state == 2 ? recompui::Display::Block : recompui::Display::None);
                c.placeholder->set_display(state == 1 ? recompui::Display::Block : recompui::Display::None);
                if (state == 1) {
                    // "Game" is Banjo as the game had him: a Jiggy. The rest wait for their cards: a honeycomb.
                    c.placeholder->set_src(index == 0 ? "icons/Jiggy.svg" : "icons/Honeycomb.svg");
                    c.placeholder->set_opacity(index == 0 ? 1.0f : 0.35f);
                }
            }
            if (state == 2) {
                // Each card starts its loop at its own point, so the page doesn't move in step.
                const int frame = (int)((ms / card_frame_ms + index * 3) % photo::pose_card_frames);
                if (frame != c.frame_shown) {
                    c.frame_shown = frame;
                    c.image->set_src(c.prefix + std::to_string(frame));
                }
            }
            const int picked = index == view.cursor ? 1 : 0;
            if (picked != c.picked) {
                c.picked = picked;
                c.box->set_background_color(picked ? style::gold : style::sidebar);
                c.box->set_border_color(picked ? style::orange : style::gold_faint);
                c.name->set_color(picked ? style::brown_text : style::cream);
                c.jiggy->set_display(picked ? recompui::Display::Block : recompui::Display::None);
            }
        }

        // The darkroom: the curtain over the picture, and how many cards are out.
        if (view.developing != g.last_developing || view.curtain != g.last_curtain) {
            g.last_developing = view.developing;
            g.last_curtain = view.curtain;
            // The curtain only while the cards are taken the old way (Banjo posed in front of the camera); filmed with
            // the pose puppets nothing on screen moves, so the game stays in sight.
            g.root->set_background_color(view.curtain ? darkroom : clear);
            g.develop->set_display(view.developing ? recompui::Display::Flex : recompui::Display::None);
            g.last_developed = -1;
        }
        if (view.developing) {
            if (view.developed != g.last_developed) {
                g.last_developed = view.developed;
                g.develop_label->set_text("Developing Photos...  " + std::to_string(view.developed) + " / " + std::to_string(view.develop_total));
                const float part = view.develop_total > 0 ? (float)view.developed / (float)view.develop_total : 0.0f;
                g.develop_fill->set_width(100.0f * part, recompui::Unit::Percent);
            }
            const int quip = (int)((ms / 2500) % (long long)std::size(develop_quips));
            if (quip != g.last_quip) {
                g.last_quip = quip;
                g.develop_quip->set_text(develop_quips[quip]);
            }
        }
        g.context.close();
    }

    // ---- The shutter flash ----

    // A white sheet over the whole window, faded out by tooie::photo_mode::flash_level.
    // Its own context, so it shows with the list hidden too.
    struct Flash {
        recompui::ContextId context = recompui::ContextId::null();
        recompui::Element* sheet = nullptr;
        bool shown = false;
    };

    bool build_flash(Flash& f) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return false;
        }
        try {
            recompui::ContextId ctx = recompui::create_context();
            ctx.open();
            recompui::Element* root = ctx.create_element<recompui::Element>(ctx.get_root_element());
            root->set_display(recompui::Display::Flex);
            root->set_background_color(recompui::theme::color::Transparent);
            root->set_pointer_events(recompui::PointerEvents::None);
            f.sheet = ctx.create_element<recompui::Element>(root);
            f.sheet->set_position(recompui::Position::Absolute);
            f.sheet->set_top(0);
            f.sheet->set_left(0);
            f.sheet->set_width(100.0f, recompui::Unit::Percent);
            f.sheet->set_height(100.0f, recompui::Unit::Percent);
            f.sheet->set_background_color(recompui::Color{ 255, 255, 255, 255 });
            f.sheet->set_opacity(0.0f);
            f.sheet->set_pointer_events(recompui::PointerEvents::None);
            ctx.close();
            ctx.set_captures_input(false);
            ctx.set_captures_mouse(false);
            f.context = ctx;
            return true;
        } catch (...) {
            return false;
        }
    }

    void set_flash(Flash& f, float level) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        if (level > 0.0f) {
            f.context.open();
            f.sheet->set_opacity(0.85f * level);
            f.context.close();
            if (!recompui::is_context_shown(f.context)) {
                recompui::show_context(f.context, "");
            }
            f.shown = true;
        }
        else if (f.shown) {
            if (recompui::is_context_shown(f.context)) {
                recompui::hide_context(f.context);
            }
            f.shown = false;
        }
    }

    // The game start clears every shown context, so check the real state each time.
    void show(recompui::ContextId context, bool& shown) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        if (!recompui::is_context_shown(context)) {
            recompui::show_context(context, "");
        }
        shown = true;
    }

    void hide(recompui::ContextId context, bool& shown) {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        if (shown && recompui::is_context_shown(context)) {
            recompui::hide_context(context);
        }
        shown = false;
    }

    bool menu_open() {
        try {
            return recompui::config::get_config_modal()->is_open_now();
        } catch (...) {
            return false;
        }
    }

    // The Album row: the menu, opened on its Album tab. Closing it goes back to photo mode.
    void open_album() {
        auto lifetime = recompui::lock_context_lifetime();
        if (!recompui::contexts_alive()) {
            return;
        }
        try {
            recompui::ContextId context = recompui::config::get_config_context_id();
            context.open();
            recompui::config::set_tab(tooie::photo_album::tab_id);
            recompui::config::open();
            context.close();
        } catch (...) {
        }
    }

    void worker() {
        Panel panel;
        Grid grid;
        Flash flash;
        std::vector<std::string> rows;
        for (;;) {
            const float level = tooie::photo_mode::flash_level();
            photo::PoseGridView view;
            const bool want_grid = photo::pose_grid(view) && !menu_open();
            std::this_thread::sleep_for(level > 0.0f || flash.shown ? flash_interval : want_grid ? grid_interval : poll_interval);
            if (level > 0.0f || flash.shown) {
                if (flash.context != recompui::ContextId::null() || build_flash(flash)) {
                    set_flash(flash, tooie::photo_mode::flash_level());
                }
            }
            if (tooie::photo_mode::take_album_request()) {
                open_album();
            }

            // The grid takes the list's place while it is open.
            if (want_grid && (grid.context != recompui::ContextId::null() || build_grid(grid))) {
                photo::pose_grid(view);
                update_grid(grid, view);
                show(grid.context, grid.shown);
            }
            else if (grid.shown) {
                hide(grid.context, grid.shown);
            }

            int picked = 0;
            // The panel steps aside while the menu is open over photo mode.
            const bool want = !want_grid && tooie::photo_mode::panel_state(rows, picked) && !menu_open();
            if (!want) {
                if (panel.shown) {
                    hide(panel.context, panel.shown);
                }
                continue;
            }
            if (panel.context == recompui::ContextId::null() && !build(panel)) {
                std::this_thread::sleep_for(ui_wait);
                continue;
            }
            update(panel, rows, picked);
            show(panel.context, panel.shown);
        }
    }
}

void tooie::photo_panel::start() {
    std::call_once(started, [] {
        // Detached on purpose: the thread owns no resources that need a clean shutdown.
        std::thread(worker).detach();
    });
}
