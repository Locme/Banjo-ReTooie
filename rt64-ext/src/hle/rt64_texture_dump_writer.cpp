//
// RT64 extension: texture dump files written off the renderer thread.
//

#include "hle/rt64_texture_dump_writer.h"

#include <condition_variable>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <mutex>
#include <thread>

namespace RT64 {
    namespace {
        std::mutex writerMutex;
        std::condition_variable writerWake;
        std::condition_variable writerIdle;
        std::deque<std::vector<TextureDumpFile>> writerQueue;
        bool writerBusy = false;
        std::once_flag writerStarted;

        void writeFiles(const std::vector<TextureDumpFile> &files) {
            for (const TextureDumpFile &file : files) {
                std::ofstream stream(file.path, file.binary ? std::ios::binary : std::ios::out);
                if (stream.is_open()) {
                    stream.write(file.bytes.data(), std::streamsize(file.bytes.size()));
                    stream.close();
                }
            }
        }

        void writerThread() {
            while (true) {
                std::vector<TextureDumpFile> files;
                {
                    std::unique_lock lock(writerMutex);
                    writerWake.wait(lock, [] { return !writerQueue.empty(); });
                    files = std::move(writerQueue.front());
                    writerQueue.pop_front();
                    writerBusy = true;
                }

                writeFiles(files);

                {
                    std::scoped_lock lock(writerMutex);
                    writerBusy = false;
                    if (writerQueue.empty()) {
                        writerIdle.notify_all();
                    }
                }
            }
        }

        void flushAtExit() {
            FlushTextureDumps();
        }
    };

    void QueueTextureDumpFiles(std::vector<TextureDumpFile> files) {
        // The thread is detached: the program ends with std::quick_exit, which joins nothing, and the exit handlers
        // below wait for the queue to empty first.
        std::call_once(writerStarted, [] {
            std::thread(writerThread).detach();
            std::atexit(flushAtExit);
            std::at_quick_exit(flushAtExit);
        });

        {
            std::scoped_lock lock(writerMutex);
            writerQueue.push_back(std::move(files));
        }

        writerWake.notify_one();
    }

    void FlushTextureDumps() {
        std::unique_lock lock(writerMutex);
        writerIdle.wait(lock, [] { return writerQueue.empty() && !writerBusy; });
    }
};
