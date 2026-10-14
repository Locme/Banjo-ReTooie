// Banjo-Tooie's overlay system on the recompiled runtime.
//
// The game keeps ~850 code overlays in ROM. All of them are linked at
// 0x80800000, but the game loads each one into its heap wherever there is
// room, relocates it there, and may later move it (heap defragmentation) or
// free it. Code outside an overlay never calls into one directly. It calls an
// 8-byte thunk in core2 instead:
//
//     syscall <overlay index << 6>      # word 0
//     addi    $t0, $zero, <4 * entry>   # word 1
//
// The first call traps into the game's syscall_handler, which loads and
// relocates the overlay, builds a small entry stub in the overlay's header and
// rewrites word 0 of every thunk of that overlay into `j <stub>`. The stub
// looks the entry up in the overlay's entrypoint table and jumps to it. When
// the overlay is freed, the thunks are turned back into syscalls.
//
// On the host, the recompiled thunk is a function that calls
// recomp_syscall_handler and returns. Whether word 0 is currently a syscall or
// a jump is read from RDRAM each time, so this follows the game's own state.
// The overlay's recompiled functions are mapped at its current address from
// the hooks the recompiler places in the game's relocation and unload code
// (see banjotooie.us.toml).

#include <cstdio>
#include <unordered_map>

#include "recomp.h"
#include "funcs.h"
#include "tooie_game.h"
#include "tooie_hooks.h"
#include "librecomp/game.hpp"
#include "ultramodern/error_handling.hpp"

extern "C" void load_overlays(uint32_t rom, int32_t ram_addr, uint32_t size);
extern "C" void unload_overlays(int32_t ram_addr, uint32_t size);

namespace {
    // Field offsets in the game's struct Overlay (decomp include/overlays.h).
    constexpr uint32_t ovl_flags = 0x0F;
    constexpr uint32_t ovl_overlay_index = 0x2C;
    constexpr uint32_t ovl_flag_pinned = 0x04;

    // Code address of each currently mapped overlay, by overlay index.
    std::unordered_map<uint32_t, int32_t> mapped_overlays;
}

std::unordered_map<uint32_t, int32_t> tooie::mapped_overlays() {
    return ::mapped_overlays;
}

void tooie::set_mapped_overlays(const std::unordered_map<uint32_t, int32_t>& overlays) {
    ::mapped_overlays = overlays;
}

namespace {

    void unmap_overlay(uint32_t overlay_index) {
        auto it = mapped_overlays.find(overlay_index);
        if (it == mapped_overlays.end()) {
            return;
        }
        uint32_t rom_addr, size;
        if (tooie::overlay_section(overlay_index, rom_addr, size)) {
            unload_overlays(it->second, size);
        }
        mapped_overlays.erase(it);
    }

    [[noreturn]] void fatal(const char* message, uint32_t value) {
        fprintf(stderr, "[tooie] %s (0x%08X)\n", message, value);
        fflush(stderr);
        ultramodern::error_handling::message_box(message);
        ultramodern::error_handling::quick_exit(__FILE__, __LINE__, __FUNCTION__);
    }

    // The one-shot stub (ovl_entrypoint_alternate), built for thunks with the
    // "unload after the call" flag. It sits at overlay + 0x10:
    //     jal  <entry>
    //     nop
    //     jal  func_80081E30
    //     nop
    //     .word <the caller's $ra>
    // func_80081E30 frees the overlay with ovl_unload(overlay, 1), keeping the
    // entry's return values, and returns to the saved $ra. On the host the
    // return address is implicit, so this calls the entry, then ovl_unload.
    void call_one_shot_stub(uint8_t* rdram, recomp_context* ctx, gpr stub, uint32_t stub_word0) {
        gpr entry = (gpr)(int32_t)(((uint32_t)stub & 0xF0000000) | ((stub_word0 & 0x03FFFFFF) << 2));
        LOOKUP_FUNC(entry)(rdram, ctx);

        gpr v0 = ctx->r2;
        gpr v1 = ctx->r3;
        fpr f0 = ctx->f0;
        fpr f2 = ctx->f2;
        ctx->r4 = stub - 0x10;
        ctx->r5 = 1;
        ovl_unload(rdram, ctx);
        ctx->r2 = v0;
        ctx->r3 = v1;
        ctx->f0 = f0;
        ctx->f2 = f2;
    }
}

// Hook in func_80082088 before `lw $s5, 0x40($s5)`, which the config replaces
// with a no-op. $s5 holds 0xB0000000 | (overlay index * 4): the key lives in
// the ROM's IPL3 area at 0x40 + overlay index * 4.
extern "C" void tooie_read_overlay_key(uint8_t* /*rdram*/, recomp_context* ctx) {
    uint32_t offset = 0x40 + ((uint32_t)ctx->r21 & 0x0FFFFFFF);
    std::span<const uint8_t> rom = recomp::get_rom();
    if (offset + 4 > rom.size()) {
        fatal("Overlay key read outside the ROM", offset);
    }
    uint32_t key = (uint32_t(rom[offset]) << 24) | (uint32_t(rom[offset + 1]) << 16) |
                   (uint32_t(rom[offset + 2]) << 8) | uint32_t(rom[offset + 3]);
    ctx->r21 = (int32_t)key;
}

// Hook in func_80082088 once the overlay has been relocated: its code starts
// at $s2, and the struct Overlay pointer is saved at 0x28($sp).
extern "C" void tooie_overlay_placed(uint8_t* rdram, recomp_context* ctx) {
    gpr overlay = (gpr)(int32_t)MEM_W(0x28, ctx->r29);
    uint32_t overlay_index = MEM_HU(ovl_overlay_index, overlay);
    int32_t code_addr = (int32_t)ctx->r18;

    uint32_t rom_addr, size;
    if (!tooie::overlay_section(overlay_index, rom_addr, size)) {
        fatal("Unknown overlay was loaded", overlay_index);
    }

    unmap_overlay(overlay_index);
    load_overlays(rom_addr, code_addr, size);
    mapped_overlays[overlay_index] = code_addr;
}

// Hook at the start of ovl_unload(struct Overlay* $a0, ...).
extern "C" void tooie_overlay_unloading(uint8_t* rdram, recomp_context* ctx) {
    gpr overlay = ctx->r4;
    if (MEM_BU(ovl_flags, overlay) & ovl_flag_pinned) {
        return; // ovl_unload refuses to free pinned overlays
    }
    unmap_overlay(MEM_HU(ovl_overlay_index, overlay));
}

extern "C" void recomp_syscall_handler(uint8_t* rdram, recomp_context* ctx, int32_t instruction_vram) {
    gpr thunk = (gpr)instruction_vram;
    uint32_t word0 = MEM_W(0, thunk);

    if ((word0 & 0xFC00003F) == 0x0000000C) {
        // Still a syscall: let the game load the overlay. syscall_handler
        // reads the thunk through $t0 and finishes with `jr $t0`, which
        // re-enters this thunk, now rewritten into a jump.
        ctx->r8 = thunk;
        syscall_handler(rdram, ctx);
        return;
    }

    if ((word0 >> 26) != 0x02) {
        fatal("Overlay thunk is neither a syscall nor a jump", word0);
    }

    // `j stub` with `addi $t0, $zero, entry * 4` in its delay slot.
    gpr stub = (gpr)(int32_t)(((uint32_t)thunk & 0xF0000000) | ((word0 & 0x03FFFFFF) << 2));
    ctx->r8 = (int16_t)(MEM_W(4, thunk) & 0xFFFF);

    uint32_t stub_word0 = MEM_W(0, stub);
    if ((stub_word0 >> 26) == 0x03) {
        call_one_shot_stub(rdram, ctx, stub, stub_word0);
        return;
    }

    // The usual stub (ovl_entrypoint, copied into the overlay header):
    //     lui  $t1, %hi(table)
    //     ori  $t1, $t1, %lo(table)
    //     add  $t2, $t0, $t1
    //     lw   $t3, 0($t2)
    //     jr   $t3
    //     sh   $zero, -6($t1)
    uint32_t lui = stub_word0;
    uint32_t ori = MEM_W(4, stub);
    if ((lui >> 16) != 0x3C09 || (ori >> 16) != 0x3529) {
        fatal("Unsupported overlay entry stub", lui);
    }
    gpr table = (gpr)(int32_t)(((lui & 0xFFFF) << 16) | (ori & 0xFFFF));
    ctx->r9 = table;
    ctx->r10 = ctx->r8 + table;
    ctx->r11 = (int32_t)MEM_W(0, ctx->r10);
    MEM_H(-6, table) = 0;

    LOOKUP_FUNC(ctx->r11)(rdram, ctx);
}
