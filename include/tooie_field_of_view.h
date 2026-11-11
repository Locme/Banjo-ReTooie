#ifndef __TOOIE_FIELD_OF_VIEW_H__
#define __TOOIE_FIELD_OF_VIEW_H__

// The gameplay camera's field of view (src/gameplay/field_of_view.cpp).
namespace tooie::field_of_view {
    // Holds the gameplay camera's vertical field of view at this many degrees, in place of the game's and the QOL
    // offset, for an overhead view of a whole level (the console's look overview). 0 gives it back.
    void set_override(float degrees);
}

#endif
