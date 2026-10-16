// Sound > Mix rate (L, 2026-10-14): mix the game's sound at 44.1 kHz instead of 22.05 kHz.
//
// The audio manager (func_800125B0 / func_8001268C / func_800129FC, as in Banjo-Kazooie) asks the AI
// for 22050 Hz and gives the synthesizer that rate, so pitch, envelopes and the sequencer already follow
// the rate. What is built around 22 kHz, and changed here when High is picked:
// - Frame sizes: each audio frame (two VIs) mixes 736 samples, 920 after a near underrun and 552 when
//   too much is queued, with the queue checked against 92 and 277 samples (osAiGetLength / 4). The
//   queue length is halved for that check and the chosen size doubled, so the logic runs as before.
// - Buffers: the three AI buffers (920 samples each, 0x80073E18) and the two command lists (20000
//   bytes each, 0x8006A1D8) are fixed in the game's memory. They move to bigger ones in extended RDRAM.
// - Reverb: the game's custom effect (8 sections at 0x8003CA44) gives its delays in samples, so they are
//   doubled to keep the echoes' timing. The chorus rate is in Hz and its depth in cents, so they stay.
// - Pitch: the voices' resampler (func_8002D450, n_alResamplePull) steps through each sample at the
//   ratio the sequencer and sound code ask for, which assumes 22 kHz output; left alone everything
//   plays an octave up. The ratio (PVoice +0x44, kept between pulls) is halved for each pull, after the
//   game's own clamp and rounding, and put back when the pull ends.
// - The audio heap (0x22A00 bytes at 0x80046A88, under 0x200 bytes left over) moves to a bigger one, as
//   the longer delay lines need more.
// - With General > More game memory on, the heap and buffers move even at 22 kHz: the synthesizer then
//   gets 48 voices instead of 24 and 180 sample DMA buffers instead of 90 (their list at 0x80EE0000).
// The RSP reaches only the first 16 MB, so the new memory sits at physical 0xE00000, below the model
// tagging lists at 0xF00000.
// It changes while the game runs (L, 2026-10-16): the heap and buffers always move at boot and the reverb's
// delay line is made long enough for 44 kHz, so at the start of a sound frame (func_800129FC) the AI rate,
// the reverb's delays (found in the heap) and the scale factor can be switched.

#include <cstdio>
#include <cstring>
#include <variant>

#include "recomp.h"
#include "librecomp/config.hpp"
#include "recompui/config.h"
#include "tooie_hooks.h"
#include "tooie_mix_rate.h"

extern "C" void osAiSetFrequency_recomp(uint8_t* rdram, recomp_context* ctx);

namespace {
    constexpr const char* option = "mix_rate";

    constexpr gpr heap_addr = (int32_t)0x80046A78;      // ALHeap { base, cur, len, count }
    constexpr gpr fx_params_addr = (int32_t)0x8003CA44; // { sections, length, 8 words per section }
    constexpr gpr pointer_table = (int32_t)0x800459E0;  // 2 command lists, then 3 AudioInfo
    constexpr uint32_t fx_section_words = 8;
    constexpr uint32_t original_heap_size = 0x22A00;

    // Sized for 44.1 kHz and for More game memory's 48 voices and 180 sample DMA buffers.
    constexpr uint32_t region_start = 0x00E00000;
    constexpr uint32_t heap_size = 0x80000;
    constexpr uint32_t cmd_list_size = 0x20000;
    constexpr uint32_t ai_buffer_size = 0x2000;          // 1840 samples * 4 bytes, rounded up
    constexpr uint32_t heap_offset = 0;
    constexpr uint32_t cmd_list_offset = heap_offset + heap_size;
    constexpr uint32_t ai_buffer_offset = cmd_list_offset + 2 * cmd_list_size;
    // The sample DMA buffers' list (180 entries of 0x14 bytes): the generated code in func_8001268C and
    // func_80012D4C points at 0x80EE0000 when More game memory is on (banjotooie.us.toml).
    constexpr uint32_t dma_list_offset = 0xE0000;
    constexpr uint32_t dma_list_size = 180 * 0x14;
    constexpr uint32_t region_size = dma_list_offset + dma_list_size;
    static_assert(ai_buffer_offset + 3 * ai_buffer_size <= dma_list_offset, "audio buffers run into the DMA list");
    static_assert(region_start + region_size <= 0x00F00000, "audio memory runs into the model tagging lists");

    // 1 at the original rate, 2 at 44.1 kHz. Switched at the start of a sound frame.
    uint32_t factor = 1;
    // The reverb's delays in the heap (ALDelay: input, output, ...), found the first time the rate
    // changes; 0 if not found (then only the reverb's timing stays as it was).
    gpr delays_addr = 0;
    uint32_t delays_stride = 0;
    bool delays_searched = false;
    // Whether the audio heap and buffers moved to the region above (44.1 kHz or More game memory).
    bool relocated = false;

    gpr kseg0(uint32_t physical) {
        return (gpr)(int32_t)(0x80000000u | physical);
    }

    bool high_picked() {
        try {
            return std::get<uint32_t>(recompui::config::get_sound_config().get_option_value(option)) == 1;
        } catch (...) {
            return false;
        }
    }
}

void tooie::mix_rate::add_option(recomp::config::Config& sound) {
    sound.add_enum_option(option, "Mix rate",
        "The rate the game mixes its sound at. <recomp-color primary>High</recomp-color> (44 kHz) gives "
        "clearer high notes than the original 22 kHz; the instruments' own recordings stay the same. "
        "Takes effect at once.",
        {
            {0u, "Original", "Original (22 kHz)"},
            {1u, "High", "High (44 kHz)"},
        },
        0u);
}

uint32_t tooie::mix_rate::extra_region_start() {
    return region_start;
}

uint32_t tooie::mix_rate::extra_region_size() {
    return relocated ? region_size : 0;
}

// func_800125B0, after the audio heap is set up and before func_8001268C builds the synthesizer.
extern "C" void tooie_mix_rate_heap(uint8_t* rdram, recomp_context* /*ctx*/) {
    factor = high_picked() ? 2 : 1;
    fprintf(stderr, "[mix rate] %u Hz\n", 22050 * factor);
    // More game memory (src/game/more_memory.cpp) gives the synthesizer 48 voices and 180 sample DMA
    // buffers, which need the bigger heap too. Its generated code expects the move.
    // The move always happens now, so the rate can change while the game runs.
    const bool more_memory = tooie_more_memory() != 0;
    std::memset(rdram + region_start, 0, region_size);

    // The audio heap is still empty here: point it at the bigger memory.
    if (!more_memory && ((uint32_t)MEM_W(8, heap_addr) != original_heap_size || MEM_W(0, heap_addr) != MEM_W(4, heap_addr))) {
        fprintf(stderr, "[mix rate] audio heap is not as expected, staying at 22050 Hz\n");
        factor = 1;
        return;
    }
    MEM_W(0, heap_addr) = (int32_t)kseg0(region_start + heap_offset);
    MEM_W(4, heap_addr) = (int32_t)kseg0(region_start + heap_offset);
    MEM_W(8, heap_addr) = (int32_t)heap_size;
    relocated = true;

    // Reverb delays are in samples: doubled at 44 kHz so the echoes keep their timing. The delay line
    // (the length) is always made long enough for 44 kHz; a longer ring doesn't change the echoes.
    uint32_t sections = (uint32_t)MEM_W(0, fx_params_addr);
    MEM_W(4, fx_params_addr) = MEM_W(4, fx_params_addr) * 2;
    if (factor == 1) {
        return;
    }
    for (uint32_t i = 0; i < sections; i++) {
        gpr section = fx_params_addr + (int32_t)(8 + i * fx_section_words * 4);
        MEM_W(0, section) = MEM_W(0, section) * 2; // input
        MEM_W(4, section) = MEM_W(4, section) * 2; // output
    }
}

namespace {
    // The reverb's ALDelay array in the heap: each section's input and output, as the parameters
    // (now at the current factor) give them, at a fixed stride.
    void find_delays(uint8_t* rdram) {
        delays_searched = true;
        uint32_t sections = (uint32_t)MEM_W(0, fx_params_addr);
        if (sections < 2 || sections > 16) {
            return;
        }
        auto param = [&](uint32_t i, uint32_t w) {
            return (uint32_t)MEM_W(0, fx_params_addr + (int32_t)(8 + (i * fx_section_words + w) * 4));
        };
        const uint32_t start = region_start + heap_offset;
        for (uint32_t addr = start; addr + 4 * 0x60 * sections < start + heap_size; addr += 4) {
            if ((uint32_t)MEM_W(0, kseg0(addr)) != param(0, 0) || (uint32_t)MEM_W(4, kseg0(addr)) != param(0, 1)) {
                continue;
            }
            for (uint32_t stride = 0x10; stride <= 0x60; stride += 4) {
                bool all = true;
                for (uint32_t i = 1; i < sections && all; i++) {
                    all = (uint32_t)MEM_W(0, kseg0(addr + i * stride)) == param(i, 0) &&
                        (uint32_t)MEM_W(4, kseg0(addr + i * stride)) == param(i, 1);
                }
                if (all) {
                    delays_addr = kseg0(addr);
                    delays_stride = stride;
                    fprintf(stderr, "[mix rate] reverb delays at %08X, stride 0x%X\n", (uint32_t)addr | 0x80000000u, stride);
                    return;
                }
            }
        }
        fprintf(stderr, "[mix rate] reverb delays not found; the echoes keep the old timing\n");
    }

    // At the start of a sound frame: switch to the rate the menu asks for.
    void switch_rate(uint8_t* rdram, recomp_context* ctx) {
        const uint32_t wanted = high_picked() ? 2 : 1;
        if (!relocated || wanted == factor) {
            return;
        }
        if (!delays_searched) {
            find_delays(rdram);
        }
        uint32_t sections = (uint32_t)MEM_W(0, fx_params_addr);
        for (uint32_t i = 0; i < sections; i++) {
            gpr section = fx_params_addr + (int32_t)(8 + i * fx_section_words * 4);
            MEM_W(0, section) = (int32_t)((uint32_t)MEM_W(0, section) / factor * wanted);
            MEM_W(4, section) = (int32_t)((uint32_t)MEM_W(4, section) / factor * wanted);
            if (delays_addr != 0) {
                gpr delay = delays_addr + (int32_t)(i * delays_stride);
                MEM_W(0, delay) = MEM_W(0, section);
                MEM_W(4, delay) = MEM_W(4, section);
            }
        }
        factor = wanted;
        // osAiSetFrequency keeps $a0..; save what the frame code still needs.
        const gpr saved_a0 = ctx->r4;
        const gpr saved_v0 = ctx->r2;
        ctx->r4 = 22050 * factor;
        osAiSetFrequency_recomp(rdram, ctx);
        ctx->r4 = saved_a0;
        ctx->r2 = saved_v0;
        fprintf(stderr, "[mix rate] switched to %u Hz\n", 22050 * factor);
    }
}

// func_8001268C, right after osAiSetFrequency(22050): ask for 44100 instead.
extern "C" void tooie_mix_rate_frequency(uint8_t* rdram, recomp_context* ctx) {
    if (factor == 1) {
        return;
    }
    ctx->r4 = 22050 * factor;
    osAiSetFrequency_recomp(rdram, ctx);
}

// func_8001268C, after the command lists and AI buffers are assigned: swap in the bigger ones.
extern "C" void tooie_mix_rate_buffers(uint8_t* rdram, recomp_context* /*ctx*/) {
    if (!relocated) {
        return;
    }
    for (uint32_t i = 0; i < 2; i++) {
        MEM_W(i * 4, pointer_table) = (int32_t)kseg0(region_start + cmd_list_offset + i * cmd_list_size);
    }
    for (uint32_t i = 0; i < 3; i++) {
        gpr info = (gpr)MEM_W(8 + i * 4, pointer_table);
        MEM_W(0, info) = (int32_t)kseg0(region_start + ai_buffer_offset + i * ai_buffer_size);
    }
}

namespace {
    constexpr int32_t ratio_offset = 0x44;
    gpr pulled_voice = 0;
    int32_t pulled_ratio_bits = 0;

    float as_float(int32_t bits) {
        float f;
        std::memcpy(&f, &bits, sizeof(f));
        return f;
    }

    int32_t as_bits(float f) {
        int32_t bits;
        std::memcpy(&bits, &f, sizeof(bits));
        return bits;
    }
}

// func_8002D450, after the game clamps and rounds the voice's pitch ratio: step at the mix rate instead.
extern "C" void tooie_mix_rate_pitch_begin(uint8_t* rdram, recomp_context* ctx) {
    if (factor == 1) {
        return;
    }
    gpr voice = (gpr)MEM_W(0x38, ctx->r29);
    int32_t bits = MEM_W(ratio_offset, voice);
    pulled_voice = voice;
    pulled_ratio_bits = bits;
    // Rounded to the resampler's 1/32768 steps, as the game does.
    float ratio = (float)(int32_t)(as_float(bits) / (float)factor * 32768.0f) / 32768.0f;
    MEM_W(ratio_offset, voice) = as_bits(ratio);
}

// func_8002D450, at its return: put the voice's own ratio back for the next pull and pitch updates.
extern "C" void tooie_mix_rate_pitch_end(uint8_t* rdram, recomp_context* /*ctx*/) {
    if (pulled_voice == 0) {
        return;
    }
    MEM_W(ratio_offset, pulled_voice) = pulled_ratio_bits;
    pulled_voice = 0;
}

// func_800129FC, right after osAiGetLength: count the queue in 22 kHz samples for the game's checks.
extern "C" void tooie_mix_rate_queue_length(uint8_t* rdram, recomp_context* ctx) {
    switch_rate(rdram, ctx);
    if (factor == 1) {
        return;
    }
    ctx->r2 = (int32_t)(((uint32_t)ctx->r2 / factor) & ~3u);
}

// func_800129FC, once the frame's sample count is chosen (AudioInfo +4 in $s0): scale it to the rate.
extern "C" void tooie_mix_rate_frame_size(uint8_t* rdram, recomp_context* ctx) {
    if (factor == 1) {
        return;
    }
    MEM_H(4, ctx->r16) = (int16_t)(MEM_H(4, ctx->r16) * factor);
}
