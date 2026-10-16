#ifndef __TOOIE_SHADER_PROGRESS_H__
#define __TOOIE_SHADER_PROGRESS_H__

// "Compiling shaders N%" while the saved shader list compiles at start, src/ui/shader_progress.cpp.
namespace tooie::shader_progress {
    // Starts the watcher. Safe to call before the UI exists (it waits).
    void start();
}

#endif
