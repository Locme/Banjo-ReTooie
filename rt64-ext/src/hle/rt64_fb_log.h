//
// RT64
//

#pragma once
// Include guard as well as #pragma once (see README.md).
#ifndef RT64_EXT_HLE_RT64_FB_LOG_H
#define RT64_EXT_HLE_RT64_FB_LOG_H

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

namespace RT64 {
    // Banjo-Tooie: TOOIE_FB_LOG=1, once a second on the game's RDP thread (State::fullSync, lib-patches/rt64.patch): how many full
    // syncs ran and how long they took, how many of their GPU waits (renderAndSynchronize: render to RAM, or a framebuffer the
    // display list samples) and how long those took, the framebuffer read-backs into RDRAM and their bytes, and the framebuffer
    // manager's and texture cache's sizes as the second ended. For finding what makes the game thread slow (Jiggywiggy's later
    // challenges, 2026-11-03).
    struct FbLogTotals {
        uint32_t fullSyncs = 0;
        double fullSyncMs = 0.0;
        uint32_t gpuWaits = 0;
        double gpuWaitMs = 0.0;
        uint32_t readbacks = 0;
        uint64_t readbackBytes = 0;
        uint32_t maxFbPairs = 0;
        std::chrono::steady_clock::time_point lastLog = std::chrono::steady_clock::now();
    };

    inline bool FbLogOn() {
        static const bool on = (getenv("TOOIE_FB_LOG") != nullptr);
        return on;
    }

    // Only the RDP thread (State) touches these.
    inline FbLogTotals &FbLog() {
        static FbLogTotals totals;
        return totals;
    }

    // A full sync's time (made at its start, counted at its end); its start prints the last second's totals with the sizes given.
    struct FbLogFullSync {
        std::chrono::steady_clock::time_point start;

        FbLogFullSync(size_t framebuffers, size_t tileCopies, size_t textures) {
            if (!FbLogOn()) {
                return;
            }
            start = std::chrono::steady_clock::now();
            FbLogTotals &log = FbLog();
            if ((start - log.lastLog) >= std::chrono::seconds(1)) {
                fprintf(stderr, "[fb] %u full syncs (%.1f ms), %u GPU waits in them (%.1f ms), %u read-backs to RDRAM (%llu KB), "
                    "up to %u framebuffer pairs a sync; %zu framebuffers, %zu tile copies, %zu textures cached\n",
                    log.fullSyncs, log.fullSyncMs, log.gpuWaits, log.gpuWaitMs, log.readbacks, (unsigned long long)(log.readbackBytes / 1024),
                    log.maxFbPairs, framebuffers, tileCopies, textures);
                const auto lastLog = start;
                log = FbLogTotals();
                log.lastLog = lastLog;
            }
        }

        ~FbLogFullSync() {
            if (!FbLogOn()) {
                return;
            }
            FbLogTotals &log = FbLog();
            log.fullSyncs++;
            log.fullSyncMs += std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start).count();
        }
    };

    // A GPU wait inside a full sync (its time).
    struct FbLogGpuWait {
        std::chrono::steady_clock::time_point start;

        FbLogGpuWait() {
            if (FbLogOn()) {
                start = std::chrono::steady_clock::now();
            }
        }

        ~FbLogGpuWait() {
            if (FbLogOn()) {
                FbLogTotals &log = FbLog();
                log.gpuWaits++;
                log.gpuWaitMs += std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start).count();
            }
        }
    };

    inline void FbLogReadback(uint64_t bytes) {
        if (FbLogOn()) {
            FbLogTotals &log = FbLog();
            log.readbacks++;
            log.readbackBytes += bytes;
        }
    }

    inline void FbLogPairs(uint32_t fbPairs) {
        if (FbLogOn() && (fbPairs > FbLog().maxFbPairs)) {
            FbLog().maxFbPairs = fbPairs;
        }
    }
};

#endif // RT64_EXT_HLE_RT64_FB_LOG_H
