// The game's direct conversations with the cartridge's lockout chip (CIC) and
// the SI/PIF hardware, which the runtime does not model.
//
// Banjo-Tooie runs a thread (func_8001DEE8) that sends 15-byte challenges to
// the CIC-NUS-6105 through PIF RAM with raw SI DMAs and uses the answers. It
// writes the 64-byte PIF RAM image with the challenge at 0x30-0x3F and the
// command byte 0x02 at 0x3F, waits for the SI interrupt, then reads the image
// back with the response in place of the challenge.

#include <cstdio>
#include <cstring>

#include "recomp.h"
#include "librecomp/game.hpp"
#include "ultramodern/ultramodern.hpp"

namespace {
    uint8_t pif_ram[64];

    // The CIC-NUS-6105 challenge/response algorithm, as documented by X-Scale
    // and used by mupen64plus and other emulators. Works on 4-bit nibbles.
    void cic_6105_response(const uint8_t* challenge, uint8_t* response, int len) {
        static const uint8_t lut0[16] = { 0x4, 0x7, 0xA, 0x7, 0xE, 0x5, 0xE, 0x1, 0xC, 0xF, 0x8, 0xF, 0x6, 0x3, 0x6, 0x9 };
        static const uint8_t lut1[16] = { 0x4, 0x1, 0xA, 0x7, 0xE, 0x5, 0xE, 0x1, 0xC, 0x9, 0x8, 0x5, 0x6, 0x3, 0xC, 0x9 };
        uint8_t key = 0xB;
        const uint8_t* lut = lut0;
        for (int i = 0; i < len; i++) {
            response[i] = (key + 5 * challenge[i]) & 0xF;
            key = lut[response[i]];
            int sgn = (response[i] >> 3) & 0x1;
            int mag = ((sgn == 1) ? ~response[i] : response[i]) & 0x7;
            int mod = (mag % 3 == 1) ? sgn : 1 - sgn;
            if (lut == lut1 && (response[i] == 0x1 || response[i] == 0x9)) {
                mod = 1;
            }
            if (lut == lut1 && (response[i] == 0xB || response[i] == 0xE)) {
                mod = 0;
            }
            lut = (mod == 1) ? lut1 : lut0;
        }
    }

    void run_pif_command() {
        if ((pif_ram[0x3F] & 0x02) == 0) {
            fprintf(stderr, "[tooie] unhandled PIF command 0x%02X\n", pif_ram[0x3F]);
            return;
        }
        uint8_t challenge[30], response[30];
        for (int i = 0; i < 15; i++) {
            challenge[i * 2] = (pif_ram[0x30 + i] >> 4) & 0x0F;
            challenge[i * 2 + 1] = pif_ram[0x30 + i] & 0x0F;
        }
        cic_6105_response(challenge, response, 30);
        for (int i = 0; i < 15; i++) {
            pif_ram[0x30 + i] = (response[i * 2] << 4) | response[i * 2 + 1];
        }
        pif_ram[0x3F] = 0;
    }
}

extern "C" void __osSiGetAccess_recomp(uint8_t* /*rdram*/, recomp_context* /*ctx*/) {
}

extern "C" void __osSiRelAccess_recomp(uint8_t* /*rdram*/, recomp_context* /*ctx*/) {
}

// s32 __osSiRawStartDma(s32 direction, void* dramAddr)
extern "C" void __osSiRawStartDma_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint32_t direction = (uint32_t)ctx->r4;
    gpr dram_addr = ctx->r5;
    if (direction == 1 /* OS_WRITE */) {
        for (int i = 0; i < 64; i++) {
            pif_ram[i] = MEM_BU(i, dram_addr);
        }
        run_pif_command();
    }
    else {
        for (int i = 0; i < 64; i++) {
            MEM_B(i, dram_addr) = pif_ram[i];
        }
    }
    ultramodern::send_si_message();
    ctx->r2 = 0;
}

// s32 osPfsInit(OSMesgQueue*, OSPfs*, int channel): no Controller Pak.
extern "C" void osPfsInit_recomp(uint8_t* /*rdram*/, recomp_context* ctx) {
    ctx->r2 = 1; // PFS_ERR_NOPACK
}

// Only wait_one_frame (in the gz debug overlay) uses this, to spin until the
// beam passes line 5. Line 5 lets both of its loops finish at once.
extern "C" void osViGetCurrentLine_recomp(uint8_t* /*rdram*/, recomp_context* ctx) {
    ctx->r2 = 5;
}

// s32 rom_read_word(u32 rom_offset, u32* out): reads a word of the original
// cartridge ROM.
extern "C" void rom_read_word(uint8_t* rdram, recomp_context* ctx) {
    uint32_t offset = (uint32_t)ctx->r4 & 0x0FFFFFFF;
    std::span<const uint8_t> rom = recomp::get_rom();
    uint32_t word = 0;
    if (offset + 4 <= rom.size()) {
        word = (uint32_t(rom[offset]) << 24) | (uint32_t(rom[offset + 1]) << 16) |
               (uint32_t(rom[offset + 2]) << 8) | uint32_t(rom[offset + 3]);
    }
    else {
        fprintf(stderr, "[tooie] rom_read_word outside the ROM (0x%08X)\n", offset);
    }
    MEM_W(0, ctx->r5) = (int32_t)word;
    ctx->r2 = 0;
}
