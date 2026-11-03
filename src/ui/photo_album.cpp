// The Album tab (L, 2026-10-16): the photos in the screenshots folder (photo mode's A and F12), newest
// first, as a grid of small pictures under a large view of the one picked. Picking one (click, or
// focus with the controller) shows it large. "Open folder" opens the folder in the system's file browser.
//
// The pictures are decoded with stb_image and shrunk with stb_image_resize2 (small ones 240 wide, the
// large view 960 wide), then handed to the menu as RGBA images named "?/album/<file>/<size>". Only the
// newest max_photos are shown, so the menu's texture memory stays small; a picture is decoded once per
// run (its name includes the file's size and time, so a replaced file is read again).
//
// Headless: TOOIE_ALBUM_LOG=1 logs how many photos the tab found and each one decoded.

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <mutex>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "librecomp/game.hpp"
#include "recompui/recompui.h"
#include "recompui/config.h"
#include "elements/ui_button.h"
#include "elements/ui_container.h"
#include "elements/ui_image.h"
#include "elements/ui_label.h"
#include "elements/ui_pseudo_border.h"
#include "elements/ui_scroll_container.h"
#include "elements/ui_sidebar_style.h"

#include "tooie_photo_album.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#define STBI_ONLY_PNG
#include "../../lib/rt64/src/contrib/stb/stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_STATIC
#include "../../lib/rt64/src/contrib/stb/stb_image_resize2.h"

namespace fs = std::filesystem;

namespace {
    constexpr size_t max_photos = 60;
    constexpr int thumb_width = 240;
    constexpr int large_width = 960;

    struct Photo {
        fs::path path;
        std::string name;    // file name without the folder
        std::string key;     // name, size and time: a new key means the file changed
        fs::file_time_type time;
    };

    std::mutex loaded_mutex;
    std::unordered_map<std::string, std::pair<int, int>> loaded; // src -> its width and height

    bool log_on() {
        static const bool on = std::getenv("TOOIE_ALBUM_LOG") != nullptr;
        return on;
    }

    fs::path folder() {
        return recomp::get_config_path() / "screenshots";
    }

    // A path as UTF-8 text. path::string() throws on Windows for a name outside the ANSI code page
    // (バンジョー on a Western PC).
    std::string utf8(const std::u8string& text) {
        return std::string(text.begin(), text.end());
    }

    std::vector<Photo> find_photos() {
        std::vector<Photo> photos;
        std::error_code ec;
        for (const auto& entry : fs::directory_iterator(folder(), ec)) {
            if (!entry.is_regular_file(ec) || entry.path().extension() != ".png") {
                continue;
            }
            Photo p;
            p.path = entry.path();
            p.name = utf8(entry.path().filename().u8string());
            p.time = entry.last_write_time(ec);
            p.key = p.name + "/" + std::to_string(entry.file_size(ec)) + "/" +
                std::to_string((long long)p.time.time_since_epoch().count());
            photos.push_back(std::move(p));
        }
        std::sort(photos.begin(), photos.end(), [](const Photo& a, const Photo& b) { return a.time > b.time; });
        if (photos.size() > max_photos) {
            photos.resize(max_photos);
        }
        return photos;
    }

    // Decodes a photo shrunk to width (never grown) and gives it to the menu under src. False if unreadable.
    // size gets the picture's width and height.
    bool load(const Photo& photo, const std::string& src, int width, std::pair<int, int>* size = nullptr) {
        {
            std::lock_guard lock{ loaded_mutex };
            auto it = loaded.find(src);
            if (it != loaded.end()) {
                if (size != nullptr) {
                    *size = it->second;
                }
                return true;
            }
        }
        // Read through the path and decoded from memory: stbi_load takes a narrow name, which Windows reads in
        // the ANSI code page.
        std::vector<stbi_uc> file;
        {
            std::ifstream in(photo.path, std::ios::binary);
            if (!in) {
                return false;
            }
            file.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
        }
        if (file.empty()) {
            return false;
        }
        int w = 0, h = 0, channels = 0;
        stbi_uc* pixels = stbi_load_from_memory(file.data(), (int)file.size(), &w, &h, &channels, 4);
        if (pixels == nullptr || w <= 0 || h <= 0) {
            if (pixels != nullptr) {
                stbi_image_free(pixels);
            }
            return false;
        }
        const int out_w = std::min(width, w);
        const int out_h = std::max(1, (int)((long long)h * out_w / w));
        std::vector<char> bytes((size_t)out_w * out_h * 4);
        stbir_resize_uint8_linear(pixels, w, h, w * 4, reinterpret_cast<unsigned char*>(bytes.data()), out_w, out_h, out_w * 4, STBIR_RGBA);
        stbi_image_free(pixels);
        recompui::queue_image_from_bytes_rgba32(src, bytes, (uint32_t)out_w, (uint32_t)out_h);
        {
            std::lock_guard lock{ loaded_mutex };
            loaded[src] = { out_w, out_h };
        }
        if (size != nullptr) {
            *size = { out_w, out_h };
        }
        if (log_on()) {
            std::printf("[album] decoded %s at %dx%d\n", photo.name.c_str(), out_w, out_h);
            std::fflush(stdout);
        }
        return true;
    }

    std::string thumb_src(const Photo& p) {
        return "?/album/" + p.key + "/thumb";
    }

    std::string large_src(const Photo& p) {
        return "?/album/" + p.key + "/large";
    }

    // "2026-10-16_21-33-00.png" reads as "2026-10-16 21:33:00".
    std::string caption(const Photo& p) {
        std::string s = utf8(p.path.stem().u8string());
        if (s.size() >= 19 && s[10] == '_') {
            s[10] = ' ';
            s[13] = ':';
            s[16] = ':';
        }
        return s;
    }

    // One small picture: focusable and clickable, shows itself in the large view when picked.
    class Tile : public recompui::Element {
    public:
        Tile(recompui::ResourceId rid, recompui::Element* parent, std::function<void()> picked)
            : Element(rid, parent, recompui::Events(recompui::EventType::Click, recompui::EventType::Focus, recompui::EventType::Hover), "button", false),
              picked(std::move(picked)) {
            enable_focus();
            set_position(recompui::Position::Relative);
            set_padding(3.0f);
            set_flex_shrink(0.0f);
            set_display(recompui::Display::Block);
            set_width(170.0f); // the 160x90 picture, its padding and border
            set_height(100.0f);
            set_border_width(2.0f);
            set_border_radius(recompui::theme::border::radius_md);
            set_border_color(recompui::sidebar_style::gold_faint);
            set_background_color(recompui::sidebar_style::panel);
            set_cursor(recompui::Cursor::Pointer);
            recompui::get_current_context().create_element<recompui::FocusBorder>(this, false);
        }

    protected:
        std::string_view get_type_name() override { return "AlbumTile"; }
        void process_event(const recompui::Event& e) override {
            switch (e.type) {
            case recompui::EventType::Click:
                picked();
                break;
            case recompui::EventType::Focus: {
                const bool active = std::get<recompui::EventFocus>(e.variant).active;
                set_style_enabled(recompui::focus_state, active);
                set_border_color(active ? recompui::sidebar_style::gold : recompui::sidebar_style::gold_faint);
                if (active) {
                    scroll_into_view();
                    picked();
                }
                break;
            }
            case recompui::EventType::Hover:
                set_border_color(std::get<recompui::EventHover>(e.variant).active ? recompui::sidebar_style::gold : recompui::sidebar_style::gold_faint);
                break;
            default:
                break;
            }
        }

    private:
        std::function<void()> picked;
    };

    void open_folder() {
        std::error_code ec;
        fs::create_directories(folder(), ec);
        // SDL_OpenURL takes UTF-8.
        std::string url = "file://" + utf8(fs::absolute(folder(), ec).generic_u8string());
#ifdef _WIN32
        if (url.rfind("file://", 0) == 0 && url.size() > 7 && url[7] != '/') {
            url = "file:///" + url.substr(7);
        }
#endif
        SDL_OpenURL(url.c_str());
    }

    void create_contents(recompui::ContextId context, recompui::Element* parent) {
        using namespace recompui;
        namespace style = recompui::sidebar_style;
        const std::vector<Photo> photos = find_photos();
        if (log_on()) {
            std::printf("[album] %zu photos in %s\n", photos.size(), utf8(folder().u8string()).c_str());
            std::fflush(stdout);
        }

        ScrollContainer* scroll = context.create_element<ScrollContainer>(parent, ScrollDirection::Vertical);
        scroll->set_width(100.0f, Unit::Percent);
        scroll->set_height(100.0f, Unit::Percent);
        scroll->set_padding(16.0f);

        Container* page = context.create_element<Container>(scroll, FlexDirection::Column, JustifyContent::FlexStart);
        page->set_gap(10.0f);
        page->set_as_navigation_container(NavigationType::Vertical);

        Container* top = context.create_element<Container>(page, FlexDirection::Row, JustifyContent::SpaceBetween);
        top->set_align_items(AlignItems::Center);
        top->set_as_navigation_container(NavigationType::Horizontal);
        Label* count = context.create_element<Label>(top,
            photos.empty() ? std::string("No photos yet. Take one in photo mode with A, or with F12.")
                           : std::to_string(photos.size()) + (photos.size() == 1 ? " photo" : " photos") +
                             (photos.size() == max_photos ? " (the newest)" : ""),
            LabelStyle::Normal);
        count->set_color(style::cream);
        Button* open = context.create_element<Button>(top, "Open folder", ButtonStyle::Secondary, ButtonSize::Medium);
        open->add_pressed_callback([] { open_folder(); });

        if (photos.empty()) {
            return;
        }

        // The large view of the picked photo, with its date and time.
        Container* view = context.create_element<Container>(page, FlexDirection::Column, JustifyContent::FlexStart);
        view->set_align_items(AlignItems::Center);
        view->set_padding(8.0f);
        view->set_border_width(3.0f);
        view->set_border_radius(theme::border::radius_lg);
        view->set_border_color(style::gold);
        view->set_background_color(style::panel);
        // The image is given its size: the menu does not size it from the picture.
        constexpr float large_height = 360.0f;
        Image* large = context.create_element<Image>(view, "");
        large->set_height(large_height);
        Label* when = context.create_element<Label>(view, "", LabelStyle::Small);
        when->set_color(style::cream_dim);
        when->set_margin_top(6.0f);

        auto show = [large, when](const Photo& p) {
            std::pair<int, int> size;
            if (load(p, large_src(p), large_width, &size)) {
                large->set_width(large_height * size.first / size.second);
                large->set_src(large_src(p));
            }
            when->set_text(caption(p));
        };
        show(photos.front());

        Container* grid = context.create_element<Container>(page, FlexDirection::Row, JustifyContent::FlexStart);
        grid->set_flex_wrap(FlexWrap::Wrap);
        grid->set_gap(8.0f);
        grid->set_as_navigation_container(NavigationType::Auto);
        for (const Photo& p : photos) {
            if (!load(p, thumb_src(p), thumb_width)) {
                continue;
            }
            Tile* tile = context.create_element<Tile>(grid, [show, p] { show(p); });
            Image* image = context.create_element<Image>(tile, thumb_src(p));
            image->set_width(160.0f);
            image->set_height(90.0f);
        }
    }
}

void tooie::photo_album::create_tab() {
    recompui::config::create_tab("Album", tab_id, create_contents);
}
