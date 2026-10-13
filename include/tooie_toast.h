#ifndef __TOOIE_TOAST_H__
#define __TOOIE_TOAST_H__

#include <string>

// Small on-screen notices ("Screenshot saved", "Game saved", ...), src/ui/toast.cpp.
// A notice sits in the top-right corner, fades out after about 3 seconds, and never takes input.
namespace tooie::toast {
    // Queues a notice. Safe to call from any thread, and before the UI exists (it waits).
    void show(const std::string& message);
}

#endif
