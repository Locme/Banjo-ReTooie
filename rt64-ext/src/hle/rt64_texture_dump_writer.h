//
// RT64 extension: texture dump files written off the renderer thread.
//

#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace RT64 {
    // One file of a texture dump, its bytes already copied. A text file is written through a text-mode stream,
    // as RT64's dumper always wrote its .json files, so line endings come out the same.
    struct TextureDumpFile {
        std::filesystem::path path;
        std::string bytes;
        bool binary = true;
    };

    // Queues the files of one dumped texture. A worker thread writes them in order, so a slow disk or a virus scan
    // holding a file open stalls that thread and never the frame being drawn (L's sweep of 2026-11-07: one fclose
    // took 21 s on the renderer thread and the game waited the whole time).
    void QueueTextureDumpFiles(std::vector<TextureDumpFile> files);

    // Waits until every queued file is written. Called when dumping stops and when the program quits.
    void FlushTextureDumps();
};
