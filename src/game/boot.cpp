// Host versions of the few hardware-facing functions the game's boot code and
// core1 call, which banjotooie.us.toml marks as ignored.
//
// Banjo-Tooie's boot segment carries its own copy of libultra. Its bootproc
// (func_80000450) initializes the hardware, DMAs the compressed core1 from ROM
// with a raw PI transfer, inflates it into place and jumps into it. The
// runtime has already set the hardware up, so only the ROM read matters here.

#include <cstdio>

#include "recomp.h"
#include "librecomp/game.hpp"
#include "librecomp/addresses.hpp"
#include "ultramodern/ultra64.h"

extern "C" u32 osGetCount();

extern "C" void boot_osInitialize(uint8_t* rdram, recomp_context* ctx) {
}

// s32 __osPiRawStartDma(s32 direction, u32 devAddr, void* dramAddr, u32 size)
extern "C" void boot___osPiRawStartDma(uint8_t* rdram, recomp_context* ctx) {
    uint32_t direction = (uint32_t)ctx->r4;
    uint32_t dev_addr = (uint32_t)ctx->r5;
    gpr dram_addr = ctx->r6;
    uint32_t size = (uint32_t)ctx->r7;

    if (direction != 0 /* OS_READ */) {
        fprintf(stderr, "[tooie] boot PI DMA write ignored\n");
        ctx->r2 = 0;
        return;
    }
    // The boot code passes plain ROM offsets.
    if (dev_addr < recomp::rom_base) {
        dev_addr += recomp::rom_base;
    }
    recomp::do_rom_read(rdram, dram_addr, dev_addr, size);
    ctx->r2 = 0;
}

// The raw DMA above completes immediately, so the PI is never busy.
extern "C" void boot_osPiGetStatus(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = 0;
}

// func_8001DDC0 returns the running thread's CPU time: the cop0 Count register
// plus two fields of __osRunningThread. The runtime does not keep those fields,
// so this returns the count alone.
extern "C" void func_8001DDC0(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (int32_t)osGetCount();
}

// u32 __osGetSR(void), core1's copy. Its one caller, the scheduler, treats a
// cleared interrupt mask bit 5 (SR_IBIT5, 0x1000) as a pending reset and halts.
// On the console every interrupt is unmasked while the game runs, so report
// them all as enabled.
extern "C" void __osGetSR_2(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (int32_t)(ctx->status_reg | 0xFF01);
}
