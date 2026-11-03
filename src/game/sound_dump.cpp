// DEV > Dump sounds: saves the game's sound samples as WAV files.
//
// The game's sound banks are libultra ALBankFiles loaded into RDRAM (revision, bank count, bank
// pointers; each bank holds instruments, each instrument sounds, each sound a wavetable). A wavetable's
// base is the sample's offset in the ROM (the sample DMA, func_80012BB4, passes it straight to
// osPiStartDma), so the samples are read from the ROM, not from RDRAM. While the option is on, RDRAM
// is searched every few seconds for banks (new ones load with new areas) and each sample not yet
// written is decoded (VADPCM or 16-bit raw) and saved once:
//
//   sound_dump/bank<file>_<bank>/inst<n>/snd<n>_rom<offset>_<rate>hz_1ch.wav   (percussion/ for the percussion instrument)
//   sound_dump/index.txt                                                         every sample and where it came from
//
// The sample rate is the bank's; the game bends a sound's pitch by its key map, so some play faster
// or slower than the file. Loop points are saved in the WAV's smpl chunk. TOOIE_SOUND_DUMP=1 turns the
// option on, TOOIE_SOUND_DUMP_DIR=<folder> sets the folder.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <set>
#include <span>
#include <string>
#include <thread>
#include <variant>
#include <vector>

#include "recomp.h"
#include "librecomp/game.hpp"
#include "recompui/config.h"

#include "tooie_game.h"
#include "tooie_path_text.h"
#include "tooie_rdram.h"
#include "tooie_sound_dump.h"
#include "tooie_toast.h"

namespace {
    namespace fs = std::filesystem;
    using tooie::rdram::valid_ptr;
    using tooie::rdram::read_word;

    struct Sample {
        uint32_t rom;
        uint32_t length;
        uint32_t type;   // 0 ADPCM, 1 raw 16-bit
        uint32_t rate;
        uint32_t loop_start = 0, loop_end = 0, loop_count = 0;
        std::vector<int16_t> book; // order 2: npredictors * 16 vectors of 8
        int predictors = 0;
        std::string folder;
        std::string name;
    };

    std::set<uint32_t> written;       // sample ROM offsets already dumped or queued
    std::set<uint32_t> seen_files;    // ALBankFile addresses already numbered
    std::atomic<bool> writing{false};
    std::chrono::steady_clock::time_point last_scan;
    bool was_on = false;
    uint32_t next_file = 0;

    uint8_t read_byte(uint8_t* rdram, uint32_t addr) {
        return rdram[(addr ^ 3) - 0x80000000u];
    }
    uint32_t half(uint8_t* rdram, uint32_t addr) {
        return (uint16_t)tooie::rdram::read_half(rdram, addr);
    }
    bool ptr_ok(uint32_t p) { return valid_ptr(p) && (p & 3) == 0 && valid_ptr(p + 16); }

    bool wanted() {
        if (std::getenv("TOOIE_SOUND_DUMP") != nullptr) {
            return true;
        }
        try {
            return std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(tooie::sound_dump_option));
        } catch (...) {
            return false;
        }
    }

    fs::path dump_folder() {
        if (const char* env = std::getenv("TOOIE_SOUND_DUMP_DIR")) {
            return fs::path(env);
        }
        return recomp::get_config_path() / "sound_dump";
    }

    // A sound's wavetable, if it looks like a real one.
    bool read_sound(uint8_t* rdram, uint32_t sound, uint32_t rate, size_t rom_size, Sample& out) {
        if (!ptr_ok(sound)) {
            return false;
        }
        const uint32_t wave = read_word(rdram, sound + 8);
        if (!ptr_ok(wave)) {
            return false;
        }
        const uint32_t base = read_word(rdram, wave), len = read_word(rdram, wave + 4);
        const uint32_t type = read_byte(rdram, wave + 8);
        if (type > 1 || len == 0 || len > 0x400000 || base >= rom_size || base + len > rom_size) {
            return false;
        }
        out.rom = base;
        out.length = len;
        out.type = type;
        out.rate = rate;
        const uint32_t loop = read_word(rdram, wave + 12);
        if (ptr_ok(loop)) {
            out.loop_start = read_word(rdram, loop);
            out.loop_end = read_word(rdram, loop + 4);
            out.loop_count = read_word(rdram, loop + 8);
        }
        if (type == 0) {
            const uint32_t book = read_word(rdram, wave + 16);
            if (!ptr_ok(book)) {
                return false;
            }
            const uint32_t order = read_word(rdram, book), preds = read_word(rdram, book + 4);
            if (order != 2 || preds == 0 || preds > 16 || !valid_ptr(book + 8 + preds * 32)) {
                return false;
            }
            out.predictors = (int)preds;
            out.book.resize(preds * 16);
            for (uint32_t i = 0; i < preds * 16; i++) {
                out.book[i] = tooie::rdram::read_half(rdram, book + 8 + i * 2);
            }
        }
        return true;
    }

    // Whether RDRAM at `at` starts an ALBankFile; fills `out` with its samples not yet queued.
    bool read_bank_file(uint8_t* rdram, uint32_t at, size_t rom_size, uint32_t file, std::vector<Sample>& out) {
        const uint32_t banks = half(rdram, at + 2);
        if (banks == 0 || banks > 32 || !valid_ptr(at + 4 + banks * 4)) {
            return false;
        }
        const size_t first = out.size();
        bool real = false;
        for (uint32_t b = 0; b < banks; b++) {
            const uint32_t bank = read_word(rdram, at + 4 + b * 4);
            if (!ptr_ok(bank)) {
                out.resize(first);
                return false;
            }
            const uint32_t insts = half(rdram, bank);
            const uint32_t rate = read_word(rdram, bank + 4);
            if (insts > 300 || rate < 4000 || rate > 48000) {
                out.resize(first);
                return false;
            }
            char folder[48];
            for (uint32_t i = 0; i <= insts; i++) {
                // Slot `insts` stands for the percussion instrument.
                const uint32_t inst = i < insts ? read_word(rdram, bank + 12 + i * 4) : read_word(rdram, bank + 8);
                if (!ptr_ok(inst)) {
                    continue;
                }
                const uint32_t count = half(rdram, inst + 14);
                if (count > 600) {
                    continue;
                }
                if (i < insts) {
                    snprintf(folder, sizeof(folder), "bank%u_%u/inst%u", file, b, i);
                } else {
                    snprintf(folder, sizeof(folder), "bank%u_%u/percussion", file, b);
                }
                for (uint32_t s = 0; s < count; s++) {
                    Sample sample;
                    if (!read_sound(rdram, read_word(rdram, inst + 16 + s * 4), rate, rom_size, sample)) {
                        continue;
                    }
                    real = true;
                    sample.folder = folder;
                    char name[64];
                    snprintf(name, sizeof(name), "snd%u_rom%07X_%uhz_1ch.wav", s, sample.rom, rate);
                    sample.name = name;
                    out.push_back(std::move(sample));
                }
            }
        }
        if (!real) {
            out.resize(first);
        }
        return real;
    }

    // ---- Writing ----

    void put16(std::vector<uint8_t>& v, uint32_t x) { v.push_back(x & 0xFF); v.push_back((x >> 8) & 0xFF); }
    void put32(std::vector<uint8_t>& v, uint32_t x) { put16(v, x & 0xFFFF); put16(v, x >> 16); }
    void tag(std::vector<uint8_t>& v, const char* t) { v.insert(v.end(), t, t + 4); }

    int16_t clamp16(int32_t x) { return (int16_t)std::clamp(x, -32768, 32767); }

    std::vector<int16_t> decode(std::span<const uint8_t> rom, const Sample& s) {
        std::vector<int16_t> pcm;
        const uint8_t* src = rom.data() + s.rom;
        if (s.type == 1) {
            for (uint32_t i = 0; i + 2 <= s.length; i += 2) {
                pcm.push_back((int16_t)((src[i] << 8) | src[i + 1]));
            }
            return pcm;
        }
        int32_t last[2] = {0, 0}; // the two newest samples
        for (uint32_t f = 0; f + 9 <= s.length; f += 9) {
            const int shift = src[f] >> 4;
            const int pred = std::min<int>(src[f] & 0xF, s.predictors - 1);
            const int16_t* v0 = &s.book[pred * 16];
            const int16_t* v1 = v0 + 8;
            for (int half = 0; half < 2; half++) {
                int32_t in[8];
                for (int i = 0; i < 8; i++) {
                    const uint8_t byte = src[f + 1 + half * 4 + i / 2];
                    int n = (i & 1) ? (byte & 0xF) : (byte >> 4);
                    if (n >= 8) {
                        n -= 16;
                    }
                    in[i] = n * (1 << shift);
                }
                int32_t out[8];
                for (int i = 0; i < 8; i++) {
                    int64_t acc = (int64_t)in[i] * 2048 + (int64_t)v0[i] * last[0] + (int64_t)v1[i] * last[1];
                    for (int j = 0; j < i; j++) {
                        acc += (int64_t)in[j] * v1[i - 1 - j];
                    }
                    out[i] = clamp16((int32_t)std::clamp<int64_t>(acc >> 11, -32768, 32767));
                }
                for (int i = 0; i < 8; i++) {
                    pcm.push_back((int16_t)out[i]);
                }
                last[0] = out[6];
                last[1] = out[7];
            }
        }
        return pcm;
    }

    std::vector<uint8_t> wav(const Sample& s, const std::vector<int16_t>& pcm) {
        std::vector<uint8_t> v;
        const uint32_t data = (uint32_t)pcm.size() * 2;
        const bool loops = s.loop_count != 0 && s.loop_end > s.loop_start && s.loop_end <= pcm.size();
        const uint32_t smpl = loops ? 68 : 0;
        tag(v, "RIFF"); put32(v, 36 + data + smpl); tag(v, "WAVE");
        tag(v, "fmt "); put32(v, 16); put16(v, 1); put16(v, 1); put32(v, s.rate); put32(v, s.rate * 2); put16(v, 2); put16(v, 16);
        if (loops) {
            tag(v, "smpl"); put32(v, 60);
            put32(v, 0); put32(v, 0); put32(v, 1000000000u / std::max<uint32_t>(s.rate, 1)); put32(v, 60);
            put32(v, 0); put32(v, 0); put32(v, 0); put32(v, 1);
            put32(v, 0);
            put32(v, 0); put32(v, 0); put32(v, s.loop_start); put32(v, s.loop_end - 1); put32(v, 0);
            put32(v, s.loop_count == 0xFFFFFFFFu ? 0 : s.loop_count);
        }
        tag(v, "data"); put32(v, data);
        for (int16_t x : pcm) {
            put16(v, (uint16_t)x);
        }
        return v;
    }

    void write_all(std::vector<Sample> samples) {
        std::span<const uint8_t> rom = recomp::get_rom();
        const fs::path root = dump_folder();
        std::error_code ec;
        uint32_t count = 0;
        std::ofstream index(root / "index.txt", std::ios::app);
        for (const Sample& s : samples) {
            fs::create_directories(root / s.folder, ec);
            const fs::path path = root / s.folder / s.name;
            if (!fs::exists(path, ec)) {
                const std::vector<uint8_t> bytes = wav(s, decode(rom, s));
                std::ofstream out(path, std::ios::binary);
                out.write((const char*)bytes.data(), bytes.size());
                count++;
            }
            index << (s.folder + "/" + s.name) << "  rom 0x" << std::hex << s.rom << std::dec << "  bytes " << s.length
                  << (s.type ? "  raw16" : "  adpcm") << "\n";
        }
        printf("[sound-dump] wrote %u sounds to %s\n", count, tooie::path_text(root).c_str());
        fflush(stdout);
        if (count != 0) {
            tooie::toast::show("Sounds dumped: " + std::to_string(count) + " new files");
        }
        writing = false;
    }
}

void tooie::sound_dump::tick(uint8_t* rdram) {
    const bool on = wanted();
    if (!on) {
        was_on = false;
        return;
    }
    const auto now = std::chrono::steady_clock::now();
    if (was_on && now - last_scan < std::chrono::seconds(3)) {
        return;
    }
    if (writing.load()) {
        return;
    }
    was_on = true;
    last_scan = now;
    const size_t rom_size = recomp::get_rom().size();
    std::vector<Sample> found;
    // Every aligned word could start an ALBankFile; the checks reject nearly all quickly.
    for (uint32_t at = 0x80000000u; at < 0x81000000u - 64; at += 4) {
        const uint32_t banks = (uint16_t)tooie::rdram::read_half(rdram, at + 2);
        if (banks == 0 || banks > 32 || !ptr_ok(read_word(rdram, at + 4))) {
            continue;
        }
        if (seen_files.count(at)) {
            continue;
        }
        if (read_bank_file(rdram, at, rom_size, next_file, found)) {
            seen_files.insert(at);
            next_file++;
        }
    }
    std::vector<Sample> fresh;
    for (Sample& s : found) {
        if (written.insert(s.rom).second) {
            fresh.push_back(std::move(s));
        }
    }
    if (fresh.empty()) {
        return;
    }
    writing = true;
    std::thread(write_all, std::move(fresh)).detach();
}
