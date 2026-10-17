#ifndef __TOOIE_PHOTO_ALBUM_H__
#define __TOOIE_PHOTO_ALBUM_H__

#include <string>

// The Album tab (src/ui/photo_album.cpp): the photos in the screenshots folder, newest first, with a
// large view of the picked one and a button that opens the folder.
namespace tooie::photo_album {
    // Adds the tab to the settings menu (from src/game/config.cpp, with the other tabs).
    void create_tab();
    inline const std::string tab_id = "album";
}

#endif
