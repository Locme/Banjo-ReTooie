//
// RT64
//
// Banjo-Tooie: the raster shader cache's shader list (cache/shader_list.bin, compiled in the background at start)
// and saved shader binaries: SetShaderListPath, GetShaderListProgress, LoadShaderBinary, SaveShaderBinary and
// RasterShaderCache::loadShaderList. rt64_raster_shader_cache.cpp (lib-patches/rt64.patch) uses them.

#include "rt64_raster_shader_cache.h"

#include <algorithm>
#include <atomic>
#include <cstdio>
#include <vector>

#include "render/rt64_raster_shader_cache_ext.h"

namespace RT64 {
    namespace {
        std::mutex shaderListMutex;
        std::filesystem::path shaderListPath;

        // "BTSL", then the format version and the size of a ShaderDescription; a list written by a
        // build whose descriptions differ is started over.
        constexpr uint32_t ShaderListMagic = 0x4C535442;
        constexpr uint32_t ShaderListVersion = 1;
    }

    namespace shaderlistext {
        std::atomic<uint32_t> listProgressDone = 0;
        std::atomic<uint32_t> listProgressTotal = 0;
    }

    namespace {
        // "BTSB", the format version, the key, then the two sizes and the two shaders.
        constexpr uint32_t ShaderBinaryMagic = 0x42535442;
        constexpr uint32_t ShaderBinaryVersion = 1;
        // Larger than any real shader; a bigger size means a damaged file.
        constexpr uint32_t ShaderBinaryMaxSize = 16 * 1024 * 1024;

        std::filesystem::path shaderBinaryPath(uint64_t key) {
            std::filesystem::path listPath;
            {
                const std::scoped_lock lock(shaderListMutex);
                listPath = shaderListPath;
            }

            if (listPath.empty()) {
                return {};
            }

            char name[32];
            snprintf(name, sizeof(name), "%016llx.bin", (unsigned long long)(key));
            return listPath.parent_path() / "shaders" / name;
        }
    }

    void SetShaderListPath(const std::filesystem::path &path) {
        const std::scoped_lock lock(shaderListMutex);
        shaderListPath = path;
    }

    void GetShaderListProgress(uint32_t &done, uint32_t &total) {
        total = listProgressTotal.load();
        done = std::min(listProgressDone.load(), total);
    }

    bool LoadShaderBinary(uint64_t key, std::vector<uint8_t> &vertexShader, std::vector<uint8_t> &pixelShader) {
        const std::filesystem::path path = shaderBinaryPath(key);
        if (path.empty()) {
            return false;
        }

        std::ifstream in(path, std::ios::binary);
        if (!in.is_open()) {
            return false;
        }

        uint32_t header[2] = {};
        uint64_t fileKey = 0;
        uint32_t sizes[2] = {};
        if (!in.read(reinterpret_cast<char *>(header), sizeof(header)) || (header[0] != ShaderBinaryMagic) || (header[1] != ShaderBinaryVersion) ||
            !in.read(reinterpret_cast<char *>(&fileKey), sizeof(fileKey)) || (fileKey != key) ||
            !in.read(reinterpret_cast<char *>(sizes), sizeof(sizes)) || (sizes[0] == 0) || (sizes[1] == 0) ||
            (sizes[0] > ShaderBinaryMaxSize) || (sizes[1] > ShaderBinaryMaxSize))
        {
            return false;
        }

        vertexShader.resize(sizes[0]);
        pixelShader.resize(sizes[1]);
        return in.read(reinterpret_cast<char *>(vertexShader.data()), sizes[0]) && in.read(reinterpret_cast<char *>(pixelShader.data()), sizes[1]);
    }

    void SaveShaderBinary(uint64_t key, const void *vertexShader, size_t vertexShaderSize, const void *pixelShader, size_t pixelShaderSize) {
        const std::filesystem::path path = shaderBinaryPath(key);
        if (path.empty() || (vertexShaderSize == 0) || (pixelShaderSize == 0) || (vertexShaderSize > ShaderBinaryMaxSize) || (pixelShaderSize > ShaderBinaryMaxSize)) {
            return;
        }

        std::error_code ec;
        std::filesystem::create_directories(path.parent_path(), ec);

        // Written under another name and renamed when complete, so a crash never leaves half a file under the real name.
        std::filesystem::path tempPath = path;
        tempPath += ".tmp";
        {
            std::ofstream out(tempPath, std::ios::binary | std::ios::trunc);
            if (!out.is_open()) {
                return;
            }

            const uint32_t header[2] = { ShaderBinaryMagic, ShaderBinaryVersion };
            const uint32_t sizes[2] = { uint32_t(vertexShaderSize), uint32_t(pixelShaderSize) };
            out.write(reinterpret_cast<const char *>(header), sizeof(header));
            out.write(reinterpret_cast<const char *>(&key), sizeof(key));
            out.write(reinterpret_cast<const char *>(sizes), sizeof(sizes));
            out.write(reinterpret_cast<const char *>(vertexShader), std::streamsize(vertexShaderSize));
            out.write(reinterpret_cast<const char *>(pixelShader), std::streamsize(pixelShaderSize));
            if (!out.good()) {
                out.close();
                std::filesystem::remove(tempPath, ec);
                return;
            }
        }

        std::filesystem::rename(tempPath, path, ec);
        if (ec) {
            std::filesystem::remove(tempPath, ec);
        }
    }

    void RasterShaderCache::loadShaderList() {
        std::filesystem::path path;
        {
            const std::scoped_lock lock(shaderListMutex);
            path = shaderListPath;
        }

        if (path.empty()) {
            return;
        }

        std::vector<ShaderDescription> descs;
        bool valid = false;
        {
            std::ifstream in(path, std::ios::binary);
            uint32_t header[3] = {};
            if (in.read(reinterpret_cast<char *>(header), sizeof(header)) &&
                (header[0] == ShaderListMagic) && (header[1] == ShaderListVersion) && (header[2] == sizeof(ShaderDescription)))
            {
                valid = true;
                ShaderDescription desc;
                while ((descs.size() < ShaderListLimit) && in.read(reinterpret_cast<char *>(&desc), sizeof(desc))) {
                    descs.push_back(desc);
                }
            }
        }

        {
            const std::unique_lock<std::mutex> queueLock(submissionMutex);
            listedHashes.clear();
            for (const ShaderDescription &desc : descs) {
                listedHashes[desc.hash()] = true;
            }

            listCount = uint32_t(descs.size());
            listFile.close();
            if (valid) {
                listFile.open(path, std::ios::binary | std::ios::app);
            }
            else {
                std::error_code ec;
                std::filesystem::create_directories(path.parent_path(), ec);
                listFile.open(path, std::ios::binary | std::ios::trunc);
                const uint32_t header[3] = { ShaderListMagic, ShaderListVersion, uint32_t(sizeof(ShaderDescription)) };
                listFile.write(reinterpret_cast<const char *>(header), sizeof(header));
                listFile.flush();
            }
        }

        uint32_t queued = 0;
        {
            const std::unique_lock<std::mutex> queueLock(submissionMutex);
            const std::unique_lock<std::mutex> descLock(descQueueMutex);
            listPromoted.clear();
            for (const ShaderDescription &desc : descs) {
                bool &found = shaderHashes[desc.hash()];
                if (!found) {
                    found = true;
                    listQueue.push(desc);
                    listPending.insert(desc.hash());
                    queued++;
                }
            }
        }

        listProgressDone = 0;
        listProgressTotal = queued;
        descQueueChanged.notify_all();

        if (queued > 0) {
            fprintf(stdout, "[shaders] compiling %u shaders from the shader list in the background\n", queued);
        }
    }
}
