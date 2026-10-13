#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chexploder_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086670: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x80086670);
    return;
    // 0x80086674: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800000_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $a0, $zero, 0xA37
    ctx->r4 = ADD32(0, 0XA37);
    // 0x8080000C: jal         0x800DA564
    // 0x80800010: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

;}
RECOMP_FUNC void baspin_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
;}
RECOMP_FUNC void babackpack_get_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A8: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x808004AC: jr          $ra
    // 0x808004B0: lwc1        $f0, 0x10($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X10);
    return;
    // 0x808004B0: lwc1        $f0, 0x10($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X10);
;}
RECOMP_FUNC void _anseq_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082628: syscall     3
    recomp_syscall_handler(rdram, ctx, 0x80082628);
    return;
    // 0x8008262C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bsmum_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(308, 0X1150) << 16);
    // 0x808005D8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005DC: jr          $ra
    // 0x808005E0: lw          $v0, 0x1150($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1150));
    return;
    // 0x808005E0: lw          $v0, 0x1150($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1150));
;}
RECOMP_FUNC void func_8080085C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080085C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800864: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800868: jal         0x80100094
    // 0x8080086C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080086C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800870: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x80800874: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800878: beql        $t6, $zero, L_808008A4
    if (ctx->r14 == 0) {
        // 0x8080087C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008A4;
    }
    goto skip_0;
    // 0x8080087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800880: jal         0x80100094
    // 0x80800884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800888: jal         0x80087E00
    // 0x8080088C: lw          $a0, 0x94($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X94);
    _gcnewoption_entrypoint_45(rdram, ctx);
        goto after_2;
    // 0x8080088C: lw          $a0, 0x94($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X94);
    after_2:
    // 0x80800890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800894: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800898: jal         0x808005C0
    // 0x8080089C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_808005C0_chquiz(rdram, ctx);
        goto after_3;
    // 0x8080089C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x808008A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008A4:
    // 0x808008A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008A8: jr          $ra
    // 0x808008AC: nop

    return;
    // 0x808008AC: nop

;}
RECOMP_FUNC void _gleeprom_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088500: syscall     691
    recomp_syscall_handler(rdram, ctx, 0x80088500);
    return;
    // 0x80088504: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void chtoxicroombits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ED4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2308, 0X1034) << 16);
    // 0x80800ED8: jr          $ra
    // 0x80800EDC: addiu       $v0, $v0, 0x1034
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2308, 0X1034));
    return;
    // 0x80800EDC: addiu       $v0, $v0, 0x1034
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2308, 0X1034));
;}
RECOMP_FUNC void _chfloaty_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087718: syscall     612
    recomp_syscall_handler(rdram, ctx, 0x80087718);
    return;
    // 0x8008771C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800398_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080039C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003A0: jal         0x80800970
    // 0x808003A4: nop

    func_80800970_chfriesstand(rdram, ctx);
        goto after_0;
    // 0x808003A4: nop

    after_0:
    // 0x808003A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003B0: jr          $ra
    // 0x808003B4: nop

    return;
    // 0x808003B4: nop

;}
RECOMP_FUNC void func_800D5300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5300: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800D5304: jr          $ra
    // 0x800D5308: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800D5308: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_800CAF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAF34: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CAF38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CAF3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CAF40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CAF44: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x800CAF48: jal         0x800D93A0
    // 0x800CAF4C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800D93A0(rdram, ctx);
        goto after_0;
    // 0x800CAF4C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x800CAF50: addiu       $a1, $s0, 0x64
    ctx->r5 = ADD32(ctx->r16, 0X64);
    // 0x800CAF54: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800CAF58: jal         0x800D965C
    // 0x800CAF5C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800D965C(rdram, ctx);
        goto after_1;
    // 0x800CAF5C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x800CAF60: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800CAF64: jal         0x800D9624
    // 0x800CAF68: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800D9624(rdram, ctx);
        goto after_2;
    // 0x800CAF68: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x800CAF6C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800CAF70: jal         0x800D965C
    // 0x800CAF74: addiu       $a1, $s0, 0xA4
    ctx->r5 = ADD32(ctx->r16, 0XA4);
    func_800D965C(rdram, ctx);
        goto after_3;
    // 0x800CAF74: addiu       $a1, $s0, 0xA4
    ctx->r5 = ADD32(ctx->r16, 0XA4);
    after_3:
    // 0x800CAF78: jal         0x80018EFC
    // 0x800CAF7C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    mlMtxSet(rdram, ctx);
        goto after_4;
    // 0x800CAF7C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x800CAF80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CAF84: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x800CAF88: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x800CAF8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800CAF90: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800CAF94: jal         0x800EFA4C
    // 0x800CAF98: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x800CAF98: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    after_5:
    // 0x800CAF9C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800CAFA0: jal         0x80019224
    // 0x800CAFA4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80019224(rdram, ctx);
        goto after_6;
    // 0x800CAFA4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_6:
    // 0x800CAFA8: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x800CAFAC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x800CAFB0: jal         0x80019224
    // 0x800CAFB4: addiu       $a1, $s0, 0xF8
    ctx->r5 = ADD32(ctx->r16, 0XF8);
    func_80019224(rdram, ctx);
        goto after_7;
    // 0x800CAFB4: addiu       $a1, $s0, 0xF8
    ctx->r5 = ADD32(ctx->r16, 0XF8);
    after_7:
    // 0x800CAFB8: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800CAFBC: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800CAFC0: lw          $a2, 0xFC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XFC);
    // 0x800CAFC4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800CAFC8: lw          $a3, 0x100($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X100);
    // 0x800CAFCC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800CAFD0: jal         0x80019480
    // 0x800CAFD4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80019480(rdram, ctx);
        goto after_8;
    // 0x800CAFD4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_8:
    // 0x800CAFD8: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x800CAFDC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x800CAFE0: jal         0x80019224
    // 0x800CAFE4: addiu       $a1, $s0, 0x104
    ctx->r5 = ADD32(ctx->r16, 0X104);
    func_80019224(rdram, ctx);
        goto after_9;
    // 0x800CAFE4: addiu       $a1, $s0, 0x104
    ctx->r5 = ADD32(ctx->r16, 0X104);
    after_9:
    // 0x800CAFE8: lwc1        $f8, 0x108($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X108);
    // 0x800CAFEC: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x800CAFF0: lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X104);
    // 0x800CAFF4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800CAFF8: lw          $a3, 0x10C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10C);
    // 0x800CAFFC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800CB000: jal         0x80019480
    // 0x800CB004: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80019480(rdram, ctx);
        goto after_10;
    // 0x800CB004: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_10:
    // 0x800CB008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CB00C: jal         0x800EEAA4
    // 0x800CB010: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EEAA4(rdram, ctx);
        goto after_11;
    // 0x800CB010: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x800CB014: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x800CB018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CB01C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x800CB020: jal         0x800EEAA4
    // 0x800CB024: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EEAA4(rdram, ctx);
        goto after_12;
    // 0x800CB024: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x800CB028: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x800CB02C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CB030: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x800CB034: jal         0x800EEAA4
    // 0x800CB038: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EEAA4(rdram, ctx);
        goto after_13;
    // 0x800CB038: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x800CB03C: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800CB040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CB044: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x800CB048: jal         0x800EEAA4
    // 0x800CB04C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EEAA4(rdram, ctx);
        goto after_14;
    // 0x800CB04C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_14:
    // 0x800CB050: lwc1        $f8, 0x11C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x800CB054: lwc1        $f16, 0x120($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X120);
    // 0x800CB058: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x800CB05C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800CB060: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800CB064: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800CB068: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800CB06C: swc1        $f6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f6.u32l;
    // 0x800CB070: addiu       $a0, $s0, 0x128
    ctx->r4 = ADD32(ctx->r16, 0X128);
    // 0x800CB074: jal         0x80019480
    // 0x800CB078: lw          $a3, 0x124($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X124);
    func_80019480(rdram, ctx);
        goto after_15;
    // 0x800CB078: lw          $a3, 0x124($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X124);
    after_15:
    // 0x800CB07C: addiu       $a0, $s0, 0x134
    ctx->r4 = ADD32(ctx->r16, 0X134);
    // 0x800CB080: jal         0x80019224
    // 0x800CB084: addiu       $a1, $s0, 0x11C
    ctx->r5 = ADD32(ctx->r16, 0X11C);
    func_80019224(rdram, ctx);
        goto after_16;
    // 0x800CB084: addiu       $a1, $s0, 0x11C
    ctx->r5 = ADD32(ctx->r16, 0X11C);
    after_16:
    // 0x800CB088: addiu       $a0, $s0, 0x140
    ctx->r4 = ADD32(ctx->r16, 0X140);
    // 0x800CB08C: jal         0x80019224
    // 0x800CB090: addiu       $a1, $s0, 0x110
    ctx->r5 = ADD32(ctx->r16, 0X110);
    func_80019224(rdram, ctx);
        goto after_17;
    // 0x800CB090: addiu       $a1, $s0, 0x110
    ctx->r5 = ADD32(ctx->r16, 0X110);
    after_17:
    // 0x800CB094: lwc1        $f4, 0x11C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x800CB098: addiu       $a0, $s0, 0x14C
    ctx->r4 = ADD32(ctx->r16, 0X14C);
    // 0x800CB09C: lw          $a2, 0x120($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X120);
    // 0x800CB0A0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800CB0A4: lw          $a3, 0x124($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X124);
    // 0x800CB0A8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800CB0AC: jal         0x80019480
    // 0x800CB0B0: nop

    func_80019480(rdram, ctx);
        goto after_18;
    // 0x800CB0B0: nop

    after_18:
    // 0x800CB0B4: lwc1        $f8, 0x120($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X120);
    // 0x800CB0B8: addiu       $a0, $s0, 0x158
    ctx->r4 = ADD32(ctx->r16, 0X158);
    // 0x800CB0BC: lw          $a1, 0x11C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X11C);
    // 0x800CB0C0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800CB0C4: lw          $a3, 0x124($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X124);
    // 0x800CB0C8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800CB0CC: jal         0x80019480
    // 0x800CB0D0: nop

    func_80019480(rdram, ctx);
        goto after_19;
    // 0x800CB0D0: nop

    after_19:
    // 0x800CB0D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB0D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CB0DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800CB0E0: jr          $ra
    // 0x800CB0E4: nop

    return;
    // 0x800CB0E4: nop

;}
RECOMP_FUNC void idwater_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000CC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808000D0: jal         0x800D8FF8
    // 0x808000D4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000D4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000D8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808000DC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808000E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2934, 0X400) << 16);
    // 0x808000E4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808000E8: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x808000EC: lwc1        $f10, 0x400($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2934, 0X400));
    // 0x808000F0: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808000F4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808000F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000FC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800100: nop

    // 0x80800104: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800108: jal         0x800138D0
    // 0x8080010C: nop

    func_800138D0(rdram, ctx);
        goto after_1;
    // 0x8080010C: nop

    after_1:
    // 0x80800110: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800114: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2934, 0X404) << 16);
    // 0x80800118: lwc1        $f10, 0x404($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2934, 0X404));
    // 0x8080011C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800120: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800124: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800128: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080012C: nop

    // 0x80800130: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800134: jal         0x80013970
    // 0x80800138: nop

    func_80013970(rdram, ctx);
        goto after_2;
    // 0x80800138: nop

    after_2:
    // 0x8080013C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800140: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800144: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800148: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080014C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800150: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800154: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800158: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080015C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2934, 0X408) << 16);
    // 0x80800160: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800164: lwc1        $f6, 0x408($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2934, 0X408));
    // 0x80800168: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080016C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80800170: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80800174: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800178: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8080017C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800180: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80800184: nop

    // 0x80800188: mul.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8080018C: jal         0x80013970
    // 0x80800190: nop

    func_80013970(rdram, ctx);
        goto after_3;
    // 0x80800190: nop

    after_3:
    // 0x80800194: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800198: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2934, 0X40C) << 16);
    // 0x8080019C: lwc1        $f4, 0x40C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2934, 0X40C));
    // 0x808001A0: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808001A4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808001A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001AC: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x808001B0: nop

    // 0x808001B4: mul.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x808001B8: jal         0x800138D0
    // 0x808001BC: nop

    func_800138D0(rdram, ctx);
        goto after_4;
    // 0x808001BC: nop

    after_4:
    // 0x808001C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808001C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001C8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808001CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001D0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808001D4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808001D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001DC: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x808001E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2934, 0X410) << 16);
    // 0x808001E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808001E8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808001EC: lwc1        $f6, 0x410($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2934, 0X410));
    // 0x808001F0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808001F4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808001F8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808001FC: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x80800200: nop

    // 0x80800204: bc1f        L_80800220
    if (!c1cs) {
        // 0x80800208: swc1        $f8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
            goto L_80800220;
    }
    // 0x80800208: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8080020C: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800210: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800214: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800218: b           L_80800238
    // 0x8080021C: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_80800238;
    // 0x8080021C: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_80800220:
    // 0x80800220: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800224: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80800228: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8080022C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80800230: nop

    // 0x80800234: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
L_80800238:
    // 0x80800238: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080023C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800240: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x80800244: nop

    // 0x80800248: bc1fl       L_80800268
    if (!c1cs) {
        // 0x8080024C: sub.s       $f6, $f4, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
            goto L_80800268;
    }
    goto skip_0;
    // 0x8080024C: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    skip_0:
    // 0x80800250: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80800254: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800258: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8080025C: b           L_80800278
    // 0x80800260: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
        goto L_80800278;
    // 0x80800260: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x80800264: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
L_80800268:
    // 0x80800268: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080026C: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80800270: nop

    // 0x80800274: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
L_80800278:
    // 0x80800278: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080027C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800280: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800284: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800288: nop

    // 0x8080028C: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800290: jal         0x800138D0
    // 0x80800294: nop

    func_800138D0(rdram, ctx);
        goto after_5;
    // 0x80800294: nop

    after_5:
    // 0x80800298: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8080029C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2934, 0X414) << 16);
    // 0x808002A0: lwc1        $f10, 0x414($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2934, 0X414));
    // 0x808002A4: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808002A8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808002AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002B0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808002B4: nop

    // 0x808002B8: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808002BC: jal         0x80013970
    // 0x808002C0: nop

    func_80013970(rdram, ctx);
        goto after_6;
    // 0x808002C0: nop

    after_6:
    // 0x808002C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808002CC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808002D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002D4: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808002D8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808002DC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808002E0: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x808002E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002E8: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x808002EC: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808002F0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808002F4: addiu       $a2, $a2, -0x71B8
    ctx->r6 = ADD32(ctx->r6, -0X71B8);
    // 0x808002F8: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x808002FC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80800300: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800304: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80800308: nop

    // 0x8080030C: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800310: bc1f        L_80800344
    if (!c1cs) {
        // 0x80800314: add.s       $f18, $f4, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
            goto L_80800344;
    }
    // 0x80800314: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800318: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
    // 0x8080031C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800320: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80800324: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80800328: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8080032C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80800330: nop

    // 0x80800334: bc1fl       L_80800348
    if (!c1cs) {
        // 0x80800338: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_80800348;
    }
    goto skip_1;
    // 0x80800338: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_1:
    // 0x8080033C: swc1        $f14, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f14.u32l;
    // 0x80800340: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
L_80800344:
    // 0x80800344: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_80800348:
    // 0x80800348: nop

    // 0x8080034C: bc1fl       L_80800388
    if (!c1cs) {
        // 0x80800350: lh          $t6, 0xE($s0)
        ctx->r14 = MEM_H(ctx->r16, 0XE);
            goto L_80800388;
    }
    goto skip_2;
    // 0x80800350: lh          $t6, 0xE($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE);
    skip_2:
    // 0x80800354: div.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80800358: lh          $v0, 0xC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XC);
    // 0x8080035C: lh          $t4, 0xE($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XE);
    // 0x80800360: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80800364: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80800368: nop

    // 0x8080036C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800370: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800374: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800378: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080037C: b           L_80800394
    // 0x80800380: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
        goto L_80800394;
    // 0x80800380: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80800384: lh          $t6, 0xE($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE);
L_80800388:
    // 0x80800388: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8080038C: nop

    // 0x80800390: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
L_80800394:
    // 0x80800394: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80800398: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080039C: nop

    // 0x808003A0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x808003A4: nop

    // 0x808003A8: bc1fl       L_808003C8
    if (!c1cs) {
        // 0x808003AC: sub.s       $f8, $f0, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
            goto L_808003C8;
    }
    goto skip_3;
    // 0x808003AC: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
    skip_3:
    // 0x808003B0: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808003B4: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003B8: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x808003BC: b           L_808003D8
    // 0x808003C0: sh          $t8, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r24;
        goto L_808003D8;
    // 0x808003C0: sh          $t8, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r24;
    // 0x808003C4: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
L_808003C8:
    // 0x808003C8: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808003CC: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x808003D0: nop

    // 0x808003D4: sh          $t0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r8;
L_808003D8:
    // 0x808003D8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808003DC: jal         0x80088670
    // 0x808003E0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _glid_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x808003E0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_7:
    // 0x808003E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808003F0: jr          $ra
    // 0x808003F4: nop

    return;
    // 0x808003F4: nop

    // 0x808003F8: nop

    // 0x808003FC: nop

;}
RECOMP_FUNC void func_80090624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009062C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090630: jal         0x800F54E4
    // 0x80090634: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090634: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80090638: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009063C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80090640: jal         0x800F7ECC
    // 0x80090644: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F7ECC(rdram, ctx);
        goto after_1;
    // 0x80090644: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80090648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009064C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090650: jr          $ra
    // 0x80090654: nop

    return;
    // 0x80090654: nop

;}
RECOMP_FUNC void func_80801B74_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B74: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80801B78: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2284, 0X29A4) << 16);
    // 0x80801B7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801B84: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80801B88: addiu       $t7, $t7, 0x29A4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2284, 0X29A4));
    // 0x80801B8C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80801B90: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x80801B94: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80801B98: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80801B9C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80801BA0: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2284, 0X29B0) << 16);
    // 0x80801BA4: addiu       $t2, $t2, 0x29B0
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2284, 0X29B0));
    // 0x80801BA8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80801BAC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80801BB0: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80801BB4: addiu       $t1, $sp, 0x30
    ctx->r9 = ADD32(ctx->r29, 0X30);
    // 0x80801BB8: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80801BBC: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80801BC0: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80801BC4: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80801BC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801BCC: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80801BD0: jal         0x80100094
    // 0x80801BD4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801BD4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x80801BD8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80801BDC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801BE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801BE4: lhu         $t8, 0x72($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X72);
    // 0x80801BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801BEC: srl         $t6, $t8, 10
    ctx->r14 = S32(U32(ctx->r24) >> 10);
    // 0x80801BF0: bne         $t6, $at, L_80801CB0
    if (ctx->r14 != ctx->r1) {
        // 0x80801BF4: nop
    
            goto L_80801CB0;
    }
    // 0x80801BF4: nop

    // 0x80801BF8: lw          $a0, 0x348($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X348);
    // 0x80801BFC: jal         0x800C8FE0
    // 0x80801C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_1;
    // 0x80801C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801C04: lw          $a0, 0x34C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34C);
    // 0x80801C08: jal         0x800C8FE0
    // 0x80801C0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_2;
    // 0x80801C0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801C10: lw          $a0, 0x348($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X348);
    // 0x80801C14: jal         0x800C8CB8
    // 0x80801C18: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800C8CB8(rdram, ctx);
        goto after_3;
    // 0x80801C18: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x80801C1C: lw          $a0, 0x34C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34C);
    // 0x80801C20: jal         0x800C8CB8
    // 0x80801C24: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800C8CB8(rdram, ctx);
        goto after_4;
    // 0x80801C24: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80801C28: addiu       $a0, $zero, 0xE6
    ctx->r4 = ADD32(0, 0XE6);
    // 0x80801C2C: jal         0x800DC128
    // 0x80801C30: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    func_800DC128(rdram, ctx);
        goto after_5;
    // 0x80801C30: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_5:
    // 0x80801C34: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80801C38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801C3C: jal         0x800DC128
    // 0x80801C40: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    func_800DC128(rdram, ctx);
        goto after_6;
    // 0x80801C40: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_6:
    // 0x80801C44: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801C48: addiu       $a0, $zero, 0xE6
    ctx->r4 = ADD32(0, 0XE6);
    // 0x80801C4C: jal         0x800DC128
    // 0x80801C50: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    func_800DC128(rdram, ctx);
        goto after_7;
    // 0x80801C50: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_7:
    // 0x80801C54: lw          $a0, 0x348($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X348);
    // 0x80801C58: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801C5C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80801C60: jal         0x800C8FB0
    // 0x80801C64: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800C8FB0(rdram, ctx);
        goto after_8;
    // 0x80801C64: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_8:
    // 0x80801C68: addiu       $a0, $zero, 0xE6
    ctx->r4 = ADD32(0, 0XE6);
    // 0x80801C6C: jal         0x800DC128
    // 0x80801C70: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    func_800DC128(rdram, ctx);
        goto after_9;
    // 0x80801C70: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_9:
    // 0x80801C74: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80801C78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801C7C: jal         0x800DC128
    // 0x80801C80: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    func_800DC128(rdram, ctx);
        goto after_10;
    // 0x80801C80: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_10:
    // 0x80801C84: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801C88: addiu       $a0, $zero, 0xE6
    ctx->r4 = ADD32(0, 0XE6);
    // 0x80801C8C: jal         0x800DC128
    // 0x80801C90: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    func_800DC128(rdram, ctx);
        goto after_11;
    // 0x80801C90: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_11:
    // 0x80801C94: lw          $a0, 0x34C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34C);
    // 0x80801C98: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801C9C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80801CA0: jal         0x800C8FB0
    // 0x80801CA4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800C8FB0(rdram, ctx);
        goto after_12;
    // 0x80801CA4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_12:
    // 0x80801CA8: b           L_80801CC8
    // 0x80801CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801CC8;
    // 0x80801CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801CB0:
    // 0x80801CB0: jal         0x800C8FE0
    // 0x80801CB4: lw          $a0, 0x348($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X348);
    func_800C8FE0(rdram, ctx);
        goto after_13;
    // 0x80801CB4: lw          $a0, 0x348($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X348);
    after_13:
    // 0x80801CB8: lw          $a0, 0x34C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34C);
    // 0x80801CBC: jal         0x800C8FE0
    // 0x80801CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_14;
    // 0x80801CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80801CC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801CC8:
    // 0x80801CC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801CCC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801CD0: jr          $ra
    // 0x80801CD4: nop

    return;
    // 0x80801CD4: nop

;}
RECOMP_FUNC void bstrexlarge_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800920: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800924: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(412, 0X19B0) << 16);
    // 0x80800928: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080092C: jr          $ra
    // 0x80800930: lw          $v0, 0x19B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X19B0));
    return;
    // 0x80800930: lw          $v0, 0x19B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X19B0));
;}
RECOMP_FUNC void _bsstatue_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BA0: syscall     91
    recomp_syscall_handler(rdram, ctx, 0x80083BA0);
    return;
    // 0x80083BA4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chanim_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800170: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800174: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800178: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8080017C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800180: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800188: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8080018C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800190: addiu       $a2, $a2, 0x5988
    ctx->r6 = ADD32(ctx->r6, 0X5988);
    // 0x80800194: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800198: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080019C: jal         0x80082630
    // 0x808001A0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808001A0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x808001A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802BA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80802BA8: jal         0x80802458
    // 0x80802BAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80802458_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80802BAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802BB0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80802BB4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802BB8: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x80802BBC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80802BC0: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80802BC4: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x80802BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802BD0: jr          $ra
    // 0x80802BD4: nop

    return;
    // 0x80802BD4: nop

;}
RECOMP_FUNC void chgobihailfire_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1208, 0X7D0) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x7D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1208, 0X7D0));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x7D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1208, 0X7D0));
;}
RECOMP_FUNC void func_80800000_chbaddiesetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800004: bnel        $t6, $zero, L_80800018
    if (ctx->r14 != 0) {
        // 0x80800008: lbu         $t7, 0x4($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X4);
            goto L_80800018;
    }
    goto skip_0;
    // 0x80800008: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    skip_0:
    // 0x8080000C: jr          $ra
    // 0x80800010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800014: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
L_80800018:
    // 0x80800018: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8080001C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800020: bne         $t7, $at, L_80800030
    if (ctx->r15 != ctx->r1) {
        // 0x80800024: nop
    
            goto L_80800030;
    }
    // 0x80800024: nop

    // 0x80800028: jr          $ra
    // 0x8080002C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8080002C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800030:
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void func_80801520_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801524: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801528: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080152C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801530: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801534: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801538: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080153C: jal         0x80089CA0
    // 0x80801540: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801540: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80801544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801548: jal         0x8008A4B0
    // 0x8080154C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080154C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801550: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80801554: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801558: jal         0x8010A3E8
    // 0x8080155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A3E8(rdram, ctx);
        goto after_2;
    // 0x8080155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801564: jal         0x80102424
    // 0x80801568: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80801568: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_3:
    // 0x8080156C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801570: jal         0x808014B0
    // 0x80801574: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808014B0_chalienkids(rdram, ctx);
        goto after_4;
    // 0x80801574: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801578: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080157C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801584: jr          $ra
    // 0x80801588: nop

    return;
    // 0x80801588: nop

;}
RECOMP_FUNC void func_80108528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108528: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010852C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108530: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80108534: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80108538: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8010853C: jal         0x80108474
    // 0x80108540: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    func_80108474(rdram, ctx);
        goto after_0;
    // 0x80108540: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80108544: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80108548: jal         0x80106790
    // 0x8010854C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x8010854C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80108550: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80108554: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80108558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010855C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80108560: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80108564: jr          $ra
    // 0x80108568: nop

    return;
    // 0x80108568: nop

;}
RECOMP_FUNC void func_8080171C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080171C: jr          $ra
    // 0x80801720: lbu         $v0, 0x90($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X90);
    return;
    // 0x80801720: lbu         $v0, 0x90($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X90);
;}
RECOMP_FUNC void _basquash_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850D0: syscall     150
    recomp_syscall_handler(rdram, ctx, 0x800850D0);
    return;
    // 0x800850D4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _ncpod_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089560: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089560);
    return;
    // 0x80089564: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void chklungoleave_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1256, 0X130) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1256, 0X130));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1256, 0X130));
;}
RECOMP_FUNC void func_808002E0_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808002E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002F0: jal         0x80100094
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002F8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x808002FC: jal         0x808025AC
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808025AC_changlerboss(rdram, ctx);
        goto after_1;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800304: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80800308: sh          $v0, 0x128($v1)
    MEM_H(0X128, ctx->r3) = ctx->r2;
    // 0x8080030C: jal         0x800F6438
    // 0x80800310: lh          $a0, 0x128($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X128);
    func_800F6438(rdram, ctx);
        goto after_2;
    // 0x80800310: lh          $a0, 0x128($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X128);
    after_2:
    // 0x80800314: beq         $v0, $zero, L_80800330
    if (ctx->r2 == 0) {
        // 0x80800318: lw          $t6, 0x54($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X54);
            goto L_80800330;
    }
    // 0x80800318: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8080031C: lh          $a0, 0x128($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X128);
    // 0x80800320: jal         0x800F5A00
    // 0x80800324: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x80800324: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x80800328: b           L_80800338
    // 0x8080032C: nop

        goto L_80800338;
    // 0x8080032C: nop

L_80800330:
    // 0x80800330: jal         0x8010D640
    // 0x80800334: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_8010D640(rdram, ctx);
        goto after_4;
    // 0x80800334: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_4:
L_80800338:
    // 0x80800338: jal         0x808025EC
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808025EC_changlerboss(rdram, ctx);
        goto after_5;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800340: jal         0x80802680
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802680_changlerboss(rdram, ctx);
        goto after_6;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800348: jal         0x808022C4
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808022C4_changlerboss(rdram, ctx);
        goto after_7;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800350: jal         0x80802340
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802340_changlerboss(rdram, ctx);
        goto after_8;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800358: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x8080035C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80800360: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80800364: bgezl       $t9, L_80800394
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800368: lhu         $t1, 0x72($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X72);
            goto L_80800394;
    }
    goto skip_0;
    // 0x80800368: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x8080036C: lw          $a0, 0xA0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XA0);
    // 0x80800370: beql        $a0, $zero, L_80800394
    if (ctx->r4 == 0) {
        // 0x80800374: lhu         $t1, 0x72($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X72);
            goto L_80800394;
    }
    goto skip_1;
    // 0x80800374: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x80800378: jal         0x80106790
    // 0x8080037C: nop

    func_80106790(rdram, ctx);
        goto after_9;
    // 0x8080037C: nop

    after_9:
    // 0x80800380: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800384: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800388: jal         0x8008A0E0
    // 0x8080038C: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x8080038C: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    after_10:
    // 0x80800390: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
L_80800394:
    // 0x80800394: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80800398: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8080039C: sltiu       $at, $t3, 0x1D
    ctx->r1 = ctx->r11 < 0X1D ? 1 : 0;
    // 0x808003A0: beq         $at, $zero, L_80800B68
    if (ctx->r1 == 0) {
        // 0x808003A4: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80800B68;
    }
    // 0x808003A4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x808003A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2B10) << 16);
    // 0x808003AC: addu        $at, $at, $t3
    gpr jr_addend_808003B4 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x808003B0: lw          $t3, 0x2B10($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2B10));
    // 0x808003B4: jr          $t3
    // 0x808003B8: nop

    switch (jr_addend_808003B4 >> 2) {
        case 0: goto L_808003BC; break;
        case 1: goto L_80800470; break;
        case 2: goto L_80800490; break;
        case 3: goto L_8080051C; break;
        case 4: goto L_80800538; break;
        case 5: goto L_80800560; break;
        case 6: goto L_80800588; break;
        case 7: goto L_808005B0; break;
        case 8: goto L_80800614; break;
        case 9: goto L_80800B68; break;
        case 10: goto L_808006A0; break;
        case 11: goto L_80800B68; break;
        case 12: goto L_808006FC; break;
        case 13: goto L_8080071C; break;
        case 14: goto L_80800744; break;
        case 15: goto L_8080076C; break;
        case 16: goto L_80800834; break;
        case 17: goto L_80800898; break;
        case 18: goto L_80800918; break;
        case 19: goto L_80800988; break;
        case 20: goto L_808009B0; break;
        case 21: goto L_80800A20; break;
        case 22: goto L_80800B68; break;
        case 23: goto L_80800A98; break;
        case 24: goto L_80800AB8; break;
        case 25: goto L_80800AC8; break;
        case 26: goto L_80800B68; break;
        case 27: goto L_80800B68; break;
        case 28: goto L_80800B50; break;
        default: switch_error(__func__, 0x808003B4, 0x80802B10);
    }
    // 0x808003B8: nop

L_808003BC:
    // 0x808003BC: lw          $a1, 0x7C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7C);
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: sll         $t4, $a1, 19
    ctx->r12 = S32(ctx->r5 << 19);
    // 0x808003C8: jal         0x8010A5B0
    // 0x808003CC: srl         $a1, $t4, 31
    ctx->r5 = S32(U32(ctx->r12) >> 31);
    func_8010A5B0(rdram, ctx);
        goto after_11;
    // 0x808003CC: srl         $a1, $t4, 31
    ctx->r5 = S32(U32(ctx->r12) >> 31);
    after_11:
    // 0x808003D0: jal         0x800D9078
    // 0x808003D4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_12;
    // 0x808003D4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_12:
    // 0x808003D8: beq         $v0, $zero, L_808003EC
    if (ctx->r2 == 0) {
        // 0x808003DC: addiu       $a0, $zero, 0x46C
        ctx->r4 = ADD32(0, 0X46C);
            goto L_808003EC;
    }
    // 0x808003DC: addiu       $a0, $zero, 0x46C
    ctx->r4 = ADD32(0, 0X46C);
    // 0x808003E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808003E4: jal         0x80101180
    // 0x808003E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_13;
    // 0x808003E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
L_808003EC:
    // 0x808003EC: jal         0x800DA298
    // 0x808003F0: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x808003F0: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_14:
    // 0x808003F4: bnel        $v0, $zero, L_80800430
    if (ctx->r2 != 0) {
        // 0x808003F8: lw          $v0, 0x54($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X54);
            goto L_80800430;
    }
    goto skip_2;
    // 0x808003F8: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x808003FC: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80800400: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800404: addiu       $a1, $zero, 0x103E
    ctx->r5 = ADD32(0, 0X103E);
    // 0x80800408: lbu         $t6, 0x12E($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12E);
    // 0x8080040C: addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
    // 0x80800410: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800414: bne         $t6, $zero, L_8080042C
    if (ctx->r14 != 0) {
        // 0x80800418: addiu       $t8, $zero, 0xB4
        ctx->r24 = ADD32(0, 0XB4);
            goto L_8080042C;
    }
    // 0x80800418: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x8080041C: sb          $t7, 0x12E($v0)
    MEM_B(0X12E, ctx->r2) = ctx->r15;
    // 0x80800420: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800424: jal         0x8008A208
    // 0x80800428: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80800428: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_15:
L_8080042C:
    // 0x8080042C: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
L_80800430:
    // 0x80800430: lbu         $t9, 0x12C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X12C);
    // 0x80800434: beql        $t9, $zero, L_80800B6C
    if (ctx->r25 == 0) {
        // 0x80800438: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_3;
    // 0x80800438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8080043C: lbu         $t0, 0x12D($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X12D);
    // 0x80800440: beql        $t0, $zero, L_80800B6C
    if (ctx->r8 == 0) {
        // 0x80800444: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_4;
    // 0x80800444: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80800448: jal         0x800F54E4
    // 0x8080044C: nop

    func_800F54E4(rdram, ctx);
        goto after_16;
    // 0x8080044C: nop

    after_16:
    // 0x80800450: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800454: jal         0x800F82D4
    // 0x80800458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_17;
    // 0x80800458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: jal         0x808012E0
    // 0x80800464: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_18;
    // 0x80800464: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x80800468: b           L_80800B6C
    // 0x8080046C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x8080046C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800470:
    // 0x80800470: jal         0x80101DDC
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_19;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800478: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x8080047C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: jal         0x808012E0
    // 0x80800484: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_20;
    // 0x80800484: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_20:
    // 0x80800488: b           L_80800B6C
    // 0x8080048C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x8080048C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800490:
    // 0x80800490: jal         0x800D9078
    // 0x80800494: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_21;
    // 0x80800494: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_21:
    // 0x80800498: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080049C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808004A0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808004A4: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808004A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808004AC: jal         0x800F12D4
    // 0x808004B0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_22;
    // 0x808004B0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_22:
    // 0x808004B4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x808004B8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808004BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808004C0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808004C4: addiu       $a1, $t1, 0x11C
    ctx->r5 = ADD32(ctx->r9, 0X11C);
    // 0x808004C8: jal         0x800EFE50
    // 0x808004CC: addiu       $a2, $t1, 0x104
    ctx->r6 = ADD32(ctx->r9, 0X104);
    func_800EFE50(rdram, ctx);
        goto after_23;
    // 0x808004CC: addiu       $a2, $t1, 0x104
    ctx->r6 = ADD32(ctx->r9, 0X104);
    after_23:
    // 0x808004D0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D8: beql        $t2, $zero, L_80800B6C
    if (ctx->r10 == 0) {
        // 0x808004DC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_5;
    // 0x808004DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x808004E0: jal         0x808012E0
    // 0x808004E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_24;
    // 0x808004E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_24:
    // 0x808004E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004EC: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x808004F0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808004F4: addiu       $a1, $zero, 0x1027
    ctx->r5 = ADD32(0, 0X1027);
    // 0x808004F8: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    // 0x808004FC: jal         0x8008A208
    // 0x80800500: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_25;
    // 0x80800500: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_25:
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800508: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8080050C: jal         0x808021E4
    // 0x80800510: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_26;
    // 0x80800510: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_26:
    // 0x80800514: b           L_80800B6C
    // 0x80800518: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800518: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080051C:
    // 0x8080051C: lw          $a1, 0x7C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7C);
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: sll         $t4, $a1, 19
    ctx->r12 = S32(ctx->r5 << 19);
    // 0x80800528: jal         0x8010A5B0
    // 0x8080052C: srl         $a1, $t4, 31
    ctx->r5 = S32(U32(ctx->r12) >> 31);
    func_8010A5B0(rdram, ctx);
        goto after_27;
    // 0x8080052C: srl         $a1, $t4, 31
    ctx->r5 = S32(U32(ctx->r12) >> 31);
    after_27:
    // 0x80800530: b           L_80800B6C
    // 0x80800534: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800534: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800538:
    // 0x80800538: jal         0x80801A10
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A10_changlerboss(rdram, ctx);
        goto after_28;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800540: jal         0x800D9078
    // 0x80800544: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_29;
    // 0x80800544: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_29:
    // 0x80800548: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x8080054C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: jal         0x808012E0
    // 0x80800554: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_30;
    // 0x80800554: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_30:
    // 0x80800558: b           L_80800B6C
    // 0x8080055C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x8080055C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800560:
    // 0x80800560: jal         0x80801A10
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A10_changlerboss(rdram, ctx);
        goto after_31;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800568: jal         0x80801948
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801948_changlerboss(rdram, ctx);
        goto after_32;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800570: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800574: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: jal         0x808012E0
    // 0x8080057C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_33;
    // 0x8080057C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_33:
    // 0x80800580: b           L_80800B6C
    // 0x80800584: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800584: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800588:
    // 0x80800588: jal         0x80801948
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801948_changlerboss(rdram, ctx);
        goto after_34;
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800590: jal         0x80801AF0
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_changlerboss(rdram, ctx);
        goto after_35;
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80800598: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x8080059C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: jal         0x808012E0
    // 0x808005A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_36;
    // 0x808005A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_36:
    // 0x808005A8: b           L_80800B6C
    // 0x808005AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x808005AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005B0:
    // 0x808005B0: jal         0x80801AF0
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_changlerboss(rdram, ctx);
        goto after_37;
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x808005B8: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808005BC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808005C0: jal         0x80101E14
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_38;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x808005C8: beq         $v0, $zero, L_808005D8
    if (ctx->r2 == 0) {
        // 0x808005CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005D8;
    }
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: jal         0x80108B04
    // 0x808005D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_39;
    // 0x808005D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_39:
L_808005D8:
    // 0x808005D8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808005DC: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x808005E0: jal         0x80101E14
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_40;
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x808005E8: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x808005EC: lw          $t6, 0x54($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X54);
            goto L_80800B68;
    }
    // 0x808005EC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x808005F0: lh          $t7, 0x94($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X94);
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808005FC: bne         $t8, $zero, L_80800B68
    if (ctx->r24 != 0) {
        // 0x80800600: sh          $t8, 0x94($t6)
        MEM_H(0X94, ctx->r14) = ctx->r24;
            goto L_80800B68;
    }
    // 0x80800600: sh          $t8, 0x94($t6)
    MEM_H(0X94, ctx->r14) = ctx->r24;
    // 0x80800604: jal         0x808012E0
    // 0x80800608: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_41;
    // 0x80800608: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_41:
    // 0x8080060C: b           L_80800B6C
    // 0x80800610: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800610: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800614:
    // 0x80800614: jal         0x80101DDC
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_42;
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x8080061C: beql        $v0, $zero, L_80800B6C
    if (ctx->r2 == 0) {
        // 0x80800620: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_6;
    // 0x80800620: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80800624: jal         0x80801C50
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C50_changlerboss(rdram, ctx);
        goto after_43;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x8080062C: beq         $v0, $zero, L_80800648
    if (ctx->r2 == 0) {
        // 0x80800630: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800648;
    }
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800638: beq         $v0, $at, L_80800658
    if (ctx->r2 == ctx->r1) {
        // 0x8080063C: addiu       $a1, $zero, 0x102A
        ctx->r5 = ADD32(0, 0X102A);
            goto L_80800658;
    }
    // 0x8080063C: addiu       $a1, $zero, 0x102A
    ctx->r5 = ADD32(0, 0X102A);
    // 0x80800640: b           L_80800684
    // 0x80800644: nop

        goto L_80800684;
    // 0x80800644: nop

L_80800648:
    // 0x80800648: jal         0x808012E0
    // 0x8080064C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_44;
    // 0x8080064C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_44:
    // 0x80800650: b           L_80800B6C
    // 0x80800654: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800654: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800658:
    // 0x80800658: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080065C: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x80800660: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800664: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    // 0x80800668: jal         0x8008A208
    // 0x8080066C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_45;
    // 0x8080066C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_45:
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800674: jal         0x808012E0
    // 0x80800678: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_46;
    // 0x80800678: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_46:
    // 0x8080067C: b           L_80800B6C
    // 0x80800680: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800680: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800684:
    // 0x80800684: jal         0x808016A8
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016A8_changlerboss(rdram, ctx);
        goto after_47;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: jal         0x808012E0
    // 0x80800694: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_48;
    // 0x80800694: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_48:
    // 0x80800698: b           L_80800B6C
    // 0x8080069C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x8080069C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006A0:
    // 0x808006A0: jal         0x800D9078
    // 0x808006A4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_49;
    // 0x808006A4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_49:
    // 0x808006A8: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x808006AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2F44) << 16);
    // 0x808006B4: addiu       $a2, $a2, 0x2F44
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2F44));
    // 0x808006B8: jal         0x80089D18
    // 0x808006BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_50;
    // 0x808006BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_50:
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C4: jal         0x8010A85C
    // 0x808006C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_51;
    // 0x808006C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_51:
    // 0x808006CC: lbu         $t0, 0x7A($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X7A);
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x808006D8: andi        $t1, $t0, 0xFFCF
    ctx->r9 = ctx->r8 & 0XFFCF;
    // 0x808006DC: ori         $t3, $t1, 0x10
    ctx->r11 = ctx->r9 | 0X10;
    // 0x808006E0: andi        $t4, $t3, 0xF1
    ctx->r12 = ctx->r11 & 0XF1;
    // 0x808006E4: sb          $t3, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r11;
    // 0x808006E8: ori         $t5, $t4, 0x6
    ctx->r13 = ctx->r12 | 0X6;
    // 0x808006EC: jal         0x808012E0
    // 0x808006F0: sb          $t5, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r13;
    func_808012E0_changlerboss(rdram, ctx);
        goto after_52;
    // 0x808006F0: sb          $t5, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r13;
    after_52:
    // 0x808006F4: b           L_80800B6C
    // 0x808006F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x808006F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006FC:
    // 0x808006FC: jal         0x800D9078
    // 0x80800700: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_53;
    // 0x80800700: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_53:
    // 0x80800704: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800708: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080070C: jal         0x808012E0
    // 0x80800710: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_54;
    // 0x80800710: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_54:
    // 0x80800714: b           L_80800B6C
    // 0x80800718: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800718: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080071C:
    // 0x8080071C: jal         0x80801A10
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A10_changlerboss(rdram, ctx);
        goto after_55;
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80800724: jal         0x80801948
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801948_changlerboss(rdram, ctx);
        goto after_56;
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x8080072C: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800730: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: jal         0x808012E0
    // 0x80800738: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_57;
    // 0x80800738: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_57:
    // 0x8080073C: b           L_80800B6C
    // 0x80800740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800744:
    // 0x80800744: jal         0x80801948
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801948_changlerboss(rdram, ctx);
        goto after_58;
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x8080074C: jal         0x80801AF0
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_changlerboss(rdram, ctx);
        goto after_59;
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x80800754: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800758: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080075C: jal         0x808012E0
    // 0x80800760: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_60;
    // 0x80800760: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_60:
    // 0x80800764: b           L_80800B6C
    // 0x80800768: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800768: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080076C:
    // 0x8080076C: jal         0x80101F24
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_61;
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80800774: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800778: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2F60) << 16);
    // 0x8080077C: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800780: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800784: addiu       $a2, $a2, 0x2F60
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2F60));
    // 0x80800788: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800790: jal         0x80089D20
    // 0x80800794: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_62;
    // 0x80800794: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_62:
    // 0x80800798: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2F50) << 16);
    // 0x8080079C: addiu       $a2, $a2, 0x2F50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2F50));
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808007A8: jal         0x80089D20
    // 0x808007AC: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_63;
    // 0x808007AC: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    after_63:
    // 0x808007B0: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808007B4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808007B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2B84) << 16);
    // 0x808007BC: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x808007C0: nop

    // 0x808007C4: bc1f        L_80800804
    if (!c1cs) {
        // 0x808007C8: nop
    
            goto L_80800804;
    }
    // 0x808007C8: nop

    // 0x808007CC: lwc1        $f4, 0x2B84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2B84));
    // 0x808007D0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808007D4: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x808007D8: nop

    // 0x808007DC: bc1f        L_80800804
    if (!c1cs) {
        // 0x808007E0: nop
    
            goto L_80800804;
    }
    // 0x808007E0: nop

    // 0x808007E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007E8: nop

    // 0x808007EC: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x808007F0: nop

    // 0x808007F4: bc1f        L_80800804
    if (!c1cs) {
        // 0x808007F8: nop
    
            goto L_80800804;
    }
    // 0x808007F8: nop

    // 0x808007FC: jal         0x80801CD8
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CD8_changlerboss(rdram, ctx);
        goto after_64;
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
L_80800804:
    // 0x80800804: jal         0x80801AF0
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_changlerboss(rdram, ctx);
        goto after_65;
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x8080080C: jal         0x80101DDC
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_66;
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x80800814: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800818: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080081C: jal         0x808012E0
    // 0x80800820: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_67;
    // 0x80800820: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_67:
    // 0x80800824: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80800828: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8080082C: b           L_80800B68
    // 0x80800830: sh          $t7, 0x94($t6)
    MEM_H(0X94, ctx->r14) = ctx->r15;
        goto L_80800B68;
    // 0x80800830: sh          $t7, 0x94($t6)
    MEM_H(0X94, ctx->r14) = ctx->r15;
L_80800834:
    // 0x80800834: jal         0x80801AF0
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_changlerboss(rdram, ctx);
        goto after_68;
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
    // 0x8080083C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80800840: addiu       $a0, $zero, 0x460
    ctx->r4 = ADD32(0, 0X460);
    // 0x80800844: lh          $t9, 0x94($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X94);
    // 0x80800848: bne         $t9, $zero, L_80800868
    if (ctx->r25 != 0) {
        // 0x8080084C: nop
    
            goto L_80800868;
    }
    // 0x8080084C: nop

    // 0x80800850: jal         0x80089C30
    // 0x80800854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_69;
    // 0x80800854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_69:
    // 0x80800858: bne         $v0, $zero, L_80800868
    if (ctx->r2 != 0) {
        // 0x8080085C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800868;
    }
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800860: jal         0x808012E0
    // 0x80800864: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_70;
    // 0x80800864: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_70:
L_80800868:
    // 0x80800868: jal         0x800D9078
    // 0x8080086C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_71;
    // 0x8080086C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_71:
    // 0x80800870: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800874: lw          $t0, 0x54($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X54);
            goto L_80800B68;
    }
    // 0x80800874: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80800878: lh          $t1, 0x94($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X94);
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800880: blezl       $t1, L_80800B6C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80800884: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_7;
    // 0x80800884: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x80800888: jal         0x808012E0
    // 0x8080088C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_72;
    // 0x8080088C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_72:
    // 0x80800890: b           L_80800B6C
    // 0x80800894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800898:
    // 0x80800898: jal         0x80801AF0
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_changlerboss(rdram, ctx);
        goto after_73;
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_73:
    // 0x808008A0: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808008A4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808008A8: jal         0x80101E14
    // 0x808008AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_74;
    // 0x808008AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_74:
    // 0x808008B0: beq         $v0, $zero, L_808008C0
    if (ctx->r2 == 0) {
        // 0x808008B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008C0;
    }
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B8: jal         0x80108B04
    // 0x808008BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_75;
    // 0x808008BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_75:
L_808008C0:
    // 0x808008C0: jal         0x80101DDC
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_76;
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_76:
    // 0x808008C8: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x808008CC: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_80800B68;
    }
    // 0x808008CC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x808008D0: lh          $t3, 0x94($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X94);
    // 0x808008D4: addiu       $a0, $zero, 0x460
    ctx->r4 = ADD32(0, 0X460);
    // 0x808008D8: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x808008DC: bne         $t4, $zero, L_80800904
    if (ctx->r12 != 0) {
        // 0x808008E0: sh          $t4, 0x94($t2)
        MEM_H(0X94, ctx->r10) = ctx->r12;
            goto L_80800904;
    }
    // 0x808008E0: sh          $t4, 0x94($t2)
    MEM_H(0X94, ctx->r10) = ctx->r12;
    // 0x808008E4: jal         0x80089C30
    // 0x808008E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_77;
    // 0x808008E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_77:
    // 0x808008EC: bne         $v0, $zero, L_80800904
    if (ctx->r2 != 0) {
        // 0x808008F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800904;
    }
    // 0x808008F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F4: jal         0x808012E0
    // 0x808008F8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_78;
    // 0x808008F8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_78:
    // 0x808008FC: b           L_80800B6C
    // 0x80800900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800904:
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800908: jal         0x808012E0
    // 0x8080090C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_79;
    // 0x8080090C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_79:
    // 0x80800910: b           L_80800B6C
    // 0x80800914: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800914: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800918:
    // 0x80800918: jal         0x80801AF0
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_changlerboss(rdram, ctx);
        goto after_80;
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_80:
    // 0x80800920: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800924: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800928: jal         0x80101E14
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_81;
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_81:
    // 0x80800930: beq         $v0, $zero, L_80800940
    if (ctx->r2 == 0) {
        // 0x80800934: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800940;
    }
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800938: jal         0x80108B04
    // 0x8080093C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_82;
    // 0x8080093C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_82:
L_80800940:
    // 0x80800940: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800944: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800948: jal         0x80101E14
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_83;
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_83:
    // 0x80800950: beql        $v0, $zero, L_80800B6C
    if (ctx->r2 == 0) {
        // 0x80800954: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_8;
    // 0x80800954: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x80800958: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800960: lh          $t5, 0x94($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X94);
    // 0x80800964: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x80800968: sh          $t7, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r15;
    // 0x8080096C: lh          $t6, 0x94($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X94);
    // 0x80800970: bnel        $t6, $zero, L_80800B6C
    if (ctx->r14 != 0) {
        // 0x80800974: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_9;
    // 0x80800974: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x80800978: jal         0x808012E0
    // 0x8080097C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_84;
    // 0x8080097C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_84:
    // 0x80800980: b           L_80800B6C
    // 0x80800984: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800984: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800988:
    // 0x80800988: jal         0x80801AF0
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_changlerboss(rdram, ctx);
        goto after_85;
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_85:
    // 0x80800990: jal         0x800D9078
    // 0x80800994: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_86;
    // 0x80800994: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_86:
    // 0x80800998: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x8080099C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A0: jal         0x808012E0
    // 0x808009A4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_87;
    // 0x808009A4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_87:
    // 0x808009A8: b           L_80800B6C
    // 0x808009AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x808009AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009B0:
    // 0x808009B0: jal         0x80801AF0
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_changlerboss(rdram, ctx);
        goto after_88;
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_88:
    // 0x808009B8: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808009BC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808009C0: jal         0x80101E14
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_89;
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_89:
    // 0x808009C8: beq         $v0, $zero, L_808009D8
    if (ctx->r2 == 0) {
        // 0x808009CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009D8;
    }
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: jal         0x80108B04
    // 0x808009D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_90;
    // 0x808009D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_90:
L_808009D8:
    // 0x808009D8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808009DC: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x808009E0: jal         0x80101E14
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_91;
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_91:
    // 0x808009E8: beql        $v0, $zero, L_80800B6C
    if (ctx->r2 == 0) {
        // 0x808009EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_10;
    // 0x808009EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x808009F0: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F8: lh          $t8, 0x94($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X94);
    // 0x808009FC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800A00: sh          $t9, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r25;
    // 0x80800A04: lh          $t0, 0x94($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X94);
    // 0x80800A08: bnel        $t0, $zero, L_80800B6C
    if (ctx->r8 != 0) {
        // 0x80800A0C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_11;
    // 0x80800A0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_11:
    // 0x80800A10: jal         0x808012E0
    // 0x80800A14: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_92;
    // 0x80800A14: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_92:
    // 0x80800A18: b           L_80800B6C
    // 0x80800A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A20:
    // 0x80800A20: jal         0x80101DDC
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_93;
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_93:
    // 0x80800A28: beql        $v0, $zero, L_80800B6C
    if (ctx->r2 == 0) {
        // 0x80800A2C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_12;
    // 0x80800A2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x80800A30: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80800A34: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800A38: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800A3C: lh          $t3, 0x96($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X96);
    // 0x80800A40: addiu       $a1, $zero, 0x1036
    ctx->r5 = ADD32(0, 0X1036);
    // 0x80800A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A48: bne         $t3, $at, L_80800A7C
    if (ctx->r11 != ctx->r1) {
        // 0x80800A4C: sb          $t1, 0x12F($v0)
        MEM_B(0X12F, ctx->r2) = ctx->r9;
            goto L_80800A7C;
    }
    // 0x80800A4C: sb          $t1, 0x12F($v0)
    MEM_B(0X12F, ctx->r2) = ctx->r9;
    // 0x80800A50: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800A54: addiu       $t2, $zero, 0xB4
    ctx->r10 = ADD32(0, 0XB4);
    // 0x80800A58: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800A5C: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    // 0x80800A60: jal         0x8008A208
    // 0x80800A64: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_94;
    // 0x80800A64: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_94:
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A6C: jal         0x808012E0
    // 0x80800A70: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_95;
    // 0x80800A70: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_95:
    // 0x80800A74: b           L_80800B6C
    // 0x80800A78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800A78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A7C:
    // 0x80800A7C: jal         0x80109FE8
    // 0x80800A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_96;
    // 0x80800A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_96:
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A88: jal         0x808012E0
    // 0x80800A8C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_97;
    // 0x80800A8C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_97:
    // 0x80800A90: b           L_80800B6C
    // 0x80800A94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800A94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A98:
    // 0x80800A98: jal         0x80101DDC
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_98;
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_98:
    // 0x80800AA0: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800AA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x80800AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA8: jal         0x808012E0
    // 0x80800AAC: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_99;
    // 0x80800AAC: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_99:
    // 0x80800AB0: b           L_80800B6C
    // 0x80800AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800AB8:
    // 0x80800AB8: jal         0x80801BC8
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801BC8_changlerboss(rdram, ctx);
        goto after_100;
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_100:
    // 0x80800AC0: b           L_80800B6C
    // 0x80800AC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800AC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800AC8:
    // 0x80800AC8: jal         0x80801BC8
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801BC8_changlerboss(rdram, ctx);
        goto after_101;
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_101:
    // 0x80800AD0: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80800AD4: lbu         $t5, 0x12B($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X12B);
    // 0x80800AD8: bnel        $t5, $zero, L_80800B6C
    if (ctx->r13 != 0) {
        // 0x80800ADC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_13;
    // 0x80800ADC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_13:
    // 0x80800AE0: jal         0x800D90A4
    // 0x80800AE4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_102;
    // 0x80800AE4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_102:
    // 0x80800AE8: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800AEC: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800B68;
    }
    // 0x80800AEC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800AF0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800AF4: jal         0x800EEB40
    // 0x80800AF8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800EEB40(rdram, ctx);
        goto after_103;
    // 0x80800AF8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_103:
    // 0x80800AFC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2B88) << 16);
    // 0x80800B00: lwc1        $f8, 0x2B88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2B88));
    // 0x80800B04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B08: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800B0C: nop

    // 0x80800B10: bc1fl       L_80800B6C
    if (!c1cs) {
        // 0x80800B14: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_14;
    // 0x80800B14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_14:
    // 0x80800B18: jal         0x800DC128
    // 0x80800B1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_104;
    // 0x80800B1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_104:
    // 0x80800B20: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800B24: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x80800B28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800B2C: addiu       $a1, $v0, 0x1037
    ctx->r5 = ADD32(ctx->r2, 0X1037);
    // 0x80800B30: addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
    // 0x80800B34: jal         0x8008A208
    // 0x80800B38: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_105;
    // 0x80800B38: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_105:
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B40: jal         0x808012E0
    // 0x80800B44: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_106;
    // 0x80800B44: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_106:
    // 0x80800B48: b           L_80800B6C
    // 0x80800B4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B6C;
    // 0x80800B4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B50:
    // 0x80800B50: jal         0x80101DDC
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_107;
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_107:
    // 0x80800B58: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800B5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B60: jal         0x80102424
    // 0x80800B64: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_80102424(rdram, ctx);
        goto after_108;
    // 0x80800B64: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_108:
L_80800B68:
    // 0x80800B68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B6C:
    // 0x80800B6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800B74: jr          $ra
    // 0x80800B78: nop

    return;
    // 0x80800B78: nop

;}
RECOMP_FUNC void func_800C05B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C05B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C05BC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C05C0: lbu         $t6, -0x75D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X75D0);
    // 0x800C05C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C05C8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C05CC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C05D0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C05D4: beq         $t6, $zero, L_800C0620
    if (ctx->r14 == 0) {
        // 0x800C05D8: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_800C0620;
    }
    // 0x800C05D8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C05DC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800C05E0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800C05E4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800C05E8: lh          $t0, 0x4A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4A);
    // 0x800C05EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C05F0: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    // 0x800C05F4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800C05F8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C05FC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C0600: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C0604: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C0608: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800C060C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800C0610: jal         0x80087E28
    // 0x800C0614: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    _gcdialogexec_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800C0614: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_0:
    // 0x800C0618: b           L_800C0624
    // 0x800C061C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800C0624;
    // 0x800C061C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800C0620:
    // 0x800C0620: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C0624:
    // 0x800C0624: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C0628: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C062C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C0630: jr          $ra
    // 0x800C0634: nop

    return;
    // 0x800C0634: nop

;}
RECOMP_FUNC void func_800E4244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4244: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E4248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E424C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E4250: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E4254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4258: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E425C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800E4260: jal         0x800CA3F4
    // 0x800E4264: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA3F4(rdram, ctx);
        goto after_0;
    // 0x800E4264: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E4268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E426C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E4270: jr          $ra
    // 0x800E4274: nop

    return;
    // 0x800E4274: nop

;}
RECOMP_FUNC void bsswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(384, 0XBA4) << 16);
    // 0x808006B8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808006BC: jr          $ra
    // 0x808006C0: lw          $v0, 0xBA4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(384, 0XBA4));
    return;
    // 0x808006C0: lw          $v0, 0xBA4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(384, 0XBA4));
;}
RECOMP_FUNC void _capod_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856A0: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856A0);
    return;
    // 0x800856A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bskazstilt_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080097C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800980: jal         0x800C2FDC
    // 0x80800984: lbu         $a0, 0x160($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X160);
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800984: lbu         $a0, 0x160($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X160);
    after_0:
    // 0x80800988: jal         0x80800234
    // 0x8080098C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800234_bskazstilt(rdram, ctx);
        goto after_1;
    // 0x8080098C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800998: jr          $ra
    // 0x8080099C: nop

    return;
    // 0x8080099C: nop

;}
RECOMP_FUNC void _ncbapan_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891A8: syscall     765
    recomp_syscall_handler(rdram, ctx, 0x800891A8);
    return;
    // 0x800891AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80093230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093238: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009323C: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093240: swc1        $f12, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f12.u32l;
    // 0x80093244: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x80093248: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8009324C: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80093250: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80093254: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x80093258: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x8009325C: lwc1        $f10, 0x60($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80093260: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80093264: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80093268: swc1        $f18, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f18.u32l;
    // 0x8009326C: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x80093270: addiu       $a0, $v0, 0x64
    ctx->r4 = ADD32(ctx->r2, 0X64);
    // 0x80093274: jal         0x800EF334
    // 0x80093278: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    func_800EF334(rdram, ctx);
        goto after_0;
    // 0x80093278: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    after_0:
    // 0x8009327C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80093280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80093284: jr          $ra
    // 0x80093288: nop

    return;
    // 0x80093288: nop

;}
RECOMP_FUNC void func_80800324_idwibble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800324: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80800328: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x8080032C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2938, 0X77E) << 16);
    // 0x80800330: lh          $t7, 0x77E($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(2938, 0X77E));
    // 0x80800334: mfhi        $t6
    ctx->r14 = hi;
    // 0x80800338: subu        $a0, $a0, $t6
    ctx->r4 = SUB32(ctx->r4, ctx->r14);
    // 0x8080033C: bne         $a0, $t7, L_80800350
    if (ctx->r4 != ctx->r15) {
        // 0x80800340: lui         $t8, 0x8080
        ctx->r24 = S32(RELOC_HI16(2938, 0X78E) << 16);
            goto L_80800350;
    }
    // 0x80800340: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2938, 0X78E) << 16);
    // 0x80800344: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2938, 0X770) << 16);
    // 0x80800348: jr          $ra
    // 0x8080034C: addiu       $v0, $a1, 0x770
    ctx->r2 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2938, 0X770));
    return;
    // 0x8080034C: addiu       $v0, $a1, 0x770
    ctx->r2 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2938, 0X770));
L_80800350:
    // 0x80800350: lh          $t8, 0x78E($t8)
    ctx->r24 = MEM_H(ctx->r24, (int16_t)RELOC_LO16(2938, 0X78E));
    // 0x80800354: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2938, 0X770) << 16);
    // 0x80800358: addiu       $a1, $a1, 0x770
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2938, 0X770));
    // 0x8080035C: bne         $a0, $t8, L_80800370
    if (ctx->r4 != ctx->r24) {
        // 0x80800360: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80800370;
    }
    // 0x80800360: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80800364: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2938, 0X780) << 16);
    // 0x80800368: jr          $ra
    // 0x8080036C: addiu       $v0, $v0, 0x780
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2938, 0X780));
    return;
    // 0x8080036C: addiu       $v0, $v0, 0x780
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2938, 0X780));
L_80800370:
    // 0x80800370: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80800374: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x80800378: lh          $t0, 0xE($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XE);
    // 0x8080037C: bnel        $a0, $t0, L_80800390
    if (ctx->r4 != ctx->r8) {
        // 0x80800380: lh          $t1, 0x1E($v1)
        ctx->r9 = MEM_H(ctx->r3, 0X1E);
            goto L_80800390;
    }
    goto skip_0;
    // 0x80800380: lh          $t1, 0x1E($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X1E);
    skip_0:
    // 0x80800384: jr          $ra
    // 0x80800388: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800388: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080038C: lh          $t1, 0x1E($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X1E);
L_80800390:
    // 0x80800390: bnel        $a0, $t1, L_808003A4
    if (ctx->r4 != ctx->r9) {
        // 0x80800394: lh          $t2, 0x2E($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X2E);
            goto L_808003A4;
    }
    goto skip_1;
    // 0x80800394: lh          $t2, 0x2E($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2E);
    skip_1:
    // 0x80800398: jr          $ra
    // 0x8080039C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    return;
    // 0x8080039C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x808003A0: lh          $t2, 0x2E($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2E);
L_808003A4:
    // 0x808003A4: bnel        $a0, $t2, L_808003B8
    if (ctx->r4 != ctx->r10) {
        // 0x808003A8: lh          $t3, 0x3E($v1)
        ctx->r11 = MEM_H(ctx->r3, 0X3E);
            goto L_808003B8;
    }
    goto skip_2;
    // 0x808003A8: lh          $t3, 0x3E($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X3E);
    skip_2:
    // 0x808003AC: jr          $ra
    // 0x808003B0: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    return;
    // 0x808003B0: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x808003B4: lh          $t3, 0x3E($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X3E);
L_808003B8:
    // 0x808003B8: bnel        $a0, $t3, L_808003CC
    if (ctx->r4 != ctx->r11) {
        // 0x808003BC: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_808003CC;
    }
    goto skip_3;
    // 0x808003BC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_3:
    // 0x808003C0: jr          $ra
    // 0x808003C4: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    return;
    // 0x808003C4: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x808003C8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_808003CC:
    // 0x808003CC: jr          $ra
    // 0x808003D0: nop

    return;
    // 0x808003D0: nop

;}
RECOMP_FUNC void _gspropmarker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C38: syscall     730
    recomp_syscall_handler(rdram, ctx, 0x80088C38);
    return;
    // 0x80088C3C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800008_basub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800010: beq         $a1, $v1, L_8080002C
    if (ctx->r5 == ctx->r3) {
        // 0x80800014: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8080002C;
    }
    // 0x80800014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080001C: beql        $a1, $at, L_80800064
    if (ctx->r5 == ctx->r1) {
        // 0x80800020: lw          $v0, 0x130($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X130);
            goto L_80800064;
    }
    goto skip_0;
    // 0x80800020: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    skip_0:
    // 0x80800024: b           L_808000B8
    // 0x80800028: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
        goto L_808000B8;
    // 0x80800028: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
L_8080002C:
    // 0x8080002C: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x80800030: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800034: lbu         $t6, 0x5D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5D);
    // 0x80800038: bnel        $t6, $at, L_808000BC
    if (ctx->r14 != ctx->r1) {
        // 0x8080003C: sb          $a1, 0x5D($v0)
        MEM_B(0X5D, ctx->r2) = ctx->r5;
            goto L_808000BC;
    }
    goto skip_1;
    // 0x8080003C: sb          $a1, 0x5D($v0)
    MEM_B(0X5D, ctx->r2) = ctx->r5;
    skip_1:
    // 0x80800040: sb          $zero, 0x5E($v0)
    MEM_B(0X5E, ctx->r2) = 0;
    // 0x80800044: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x80800048: lwc1        $f4, 0x60($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8080004C: lwc1        $f6, 0x64($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X64);
    // 0x80800050: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800054: swc1        $f8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f8.u32l;
    // 0x80800058: b           L_808000B8
    // 0x8080005C: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
        goto L_808000B8;
    // 0x8080005C: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x80800060: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
L_80800064:
    // 0x80800064: lbu         $t7, 0x5D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5D);
    // 0x80800068: bnel        $v1, $t7, L_80800084
    if (ctx->r3 != ctx->r15) {
        // 0x8080006C: lbu         $t0, 0x5C($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X5C);
            goto L_80800084;
    }
    goto skip_2;
    // 0x8080006C: lbu         $t0, 0x5C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X5C);
    skip_2:
    // 0x80800070: lbu         $t8, 0x5F($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5F);
    // 0x80800074: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800078: b           L_8080008C
    // 0x8080007C: sb          $t9, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r25;
        goto L_8080008C;
    // 0x8080007C: sb          $t9, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r25;
    // 0x80800080: lbu         $t0, 0x5C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X5C);
L_80800084:
    // 0x80800084: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80800088: sb          $t1, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r9;
L_8080008C:
    // 0x8080008C: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x80800090: lwc1        $f10, 0x54($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X54);
    // 0x80800094: lwc1        $f16, 0x64($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X64);
    // 0x80800098: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080009C: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
    // 0x808000A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000A4: jal         0x80800834
    // 0x808000A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800834_basub(rdram, ctx);
        goto after_0;
    // 0x808000A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B4: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
L_808000B8:
    // 0x808000B8: sb          $a1, 0x5D($v0)
    MEM_B(0X5D, ctx->r2) = ctx->r5;
L_808000BC:
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void _sumole_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899D8: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x800899D8);
    return;
    // 0x800899DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void badrone_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003E4: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x808003E8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808003EC: sb          $a2, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r6;
    // 0x808003F0: lw          $a0, 0x54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54);
    // 0x808003F4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x808003F8: jal         0x800EE7F8
    // 0x808003FC: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808003FC: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_0:
    // 0x80800400: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800404: jal         0x80800348
    // 0x80800408: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800348_badrone(rdram, ctx);
        goto after_1;
    // 0x80800408: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x8080040C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800414: jr          $ra
    // 0x80800418: nop

    return;
    // 0x80800418: nop

;}
RECOMP_FUNC void func_800F5D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5D44: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5D4C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5D54: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5D58: jal         0x800A33CC
    // 0x800F5D5C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A33CC(rdram, ctx);
        goto after_0;
    // 0x800F5D5C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5D68: jr          $ra
    // 0x800F5D6C: nop

    return;
    // 0x800F5D6C: nop

;}
RECOMP_FUNC void badata_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CB0: jal         0x80800000
    // 0x80800CB4: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800CB4: nop

    after_0:
    // 0x80800CB8: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80800CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CC0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X1A78) << 16);
    // 0x80800CC4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800CC8: lh          $v0, 0x1A78($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X1A78));
    // 0x80800CCC: jr          $ra
    // 0x80800CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808014C4_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808014C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808014CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808014D0: jal         0x808006F0
    // 0x808014D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808014D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808014D8: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808014DC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808014E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014E4: jal         0x8008CB3C
    // 0x808014E8: addiu       $a1, $zero, 0x1CF
    ctx->r5 = ADD32(0, 0X1CF);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808014E8: addiu       $a1, $zero, 0x1CF
    ctx->r5 = ADD32(0, 0X1CF);
    after_1:
    // 0x808014EC: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x808014F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808014F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808014FC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801500: jal         0x8009FFD8
    // 0x80801504: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801504: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080150C: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80801510: jal         0x8009C99C
    // 0x80801514: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80801514: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_3:
    // 0x80801518: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x8080151C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801524: jal         0x8008C9BC
    // 0x80801528: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_4;
    // 0x80801528: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_4:
    // 0x8080152C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(412, 0X198C) << 16);
    // 0x80801530: lwc1        $f4, 0x198C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(412, 0X198C));
    // 0x80801534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801538: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x8080153C: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80801540: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801544: jal         0x8008C9F0
    // 0x80801548: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_5;
    // 0x80801548: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8080154C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801550: jal         0x8008CA30
    // 0x80801554: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_6;
    // 0x80801554: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x80801558: jal         0x80800000
    // 0x8080155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bstrexlarge(rdram, ctx);
        goto after_7;
    // 0x8080155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801560: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801564: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080156C: jr          $ra
    // 0x80801570: nop

    return;
    // 0x80801570: nop

;}
RECOMP_FUNC void chnests_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F80: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X1398) << 16);
    // 0x80800F84: jr          $ra
    // 0x80800F88: addiu       $v0, $v0, 0x1398
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1398));
    return;
    // 0x80800F88: addiu       $v0, $v0, 0x1398
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1398));
;}
RECOMP_FUNC void func_800F8B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8B94: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F8B98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F8B9C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F8BA0: addiu       $s0, $s0, 0x54F0
    ctx->r16 = ADD32(ctx->r16, 0X54F0);
    // 0x800F8BA4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800F8BA8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800F8BAC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800F8BB0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800F8BB4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800F8BB8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800F8BBC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800F8BC0: jal         0x800B28C4
    // 0x800F8BC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_begin(rdram, ctx);
        goto after_0;
    // 0x800F8BC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x800F8BC8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800F8BCC: jal         0x800B296C
    // 0x800F8BD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_end(rdram, ctx);
        goto after_1;
    // 0x800F8BD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x800F8BD4: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800F8BD8: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800F8BDC: beq         $at, $zero, L_800F8D28
    if (ctx->r1 == 0) {
        // 0x800F8BE0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800F8D28;
    }
    // 0x800F8BE0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800F8BE4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800F8BE8: addiu       $s3, $s3, 0x54F8
    ctx->r19 = ADD32(ctx->r19, 0X54F8);
    // 0x800F8BEC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800F8BF0: addiu       $s4, $zero, 0xB
    ctx->r20 = ADD32(0, 0XB);
    // 0x800F8BF4: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_800F8BF8:
    // 0x800F8BF8: jal         0x800EA05C
    // 0x800F8BFC: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x800F8BFC: nop

    after_2:
    // 0x800F8C00: lh          $t6, 0x22($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X22);
    // 0x800F8C04: bnel        $v0, $t6, L_800F8D1C
    if (ctx->r2 != ctx->r14) {
        // 0x800F8C08: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_800F8D1C;
    }
    goto skip_0;
    // 0x800F8C08: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    skip_0:
    // 0x800F8C0C: jal         0x800F6204
    // 0x800F8C10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800F6204(rdram, ctx);
        goto after_3;
    // 0x800F8C10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800F8C14: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800F8C18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F8C1C: jal         0x800F7E64
    // 0x800F8C20: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    func_800F7E64(rdram, ctx);
        goto after_4;
    // 0x800F8C20: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    after_4:
    // 0x800F8C24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F8C28: lbu         $a1, 0x1D($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1D);
    // 0x800F8C2C: jal         0x800F8268
    // 0x800F8C30: lbu         $a2, 0x1C($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1C);
    func_800F8268(rdram, ctx);
        goto after_5;
    // 0x800F8C30: lbu         $a2, 0x1C($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1C);
    after_5:
    // 0x800F8C34: lbu         $t7, 0x1($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X1);
    // 0x800F8C38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F8C3C: beq         $t7, $zero, L_800F8C80
    if (ctx->r15 == 0) {
        // 0x800F8C40: nop
    
            goto L_800F8C80;
    }
    // 0x800F8C40: nop

    // 0x800F8C44: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800F8C48: beq         $s2, $v0, L_800F8C58
    if (ctx->r18 == ctx->r2) {
        // 0x800F8C4C: nop
    
            goto L_800F8C58;
    }
    // 0x800F8C4C: nop

    // 0x800F8C50: bne         $s4, $v0, L_800F8C80
    if (ctx->r20 != ctx->r2) {
        // 0x800F8C54: nop
    
            goto L_800F8C80;
    }
    // 0x800F8C54: nop

L_800F8C58:
    // 0x800F8C58: bne         $s2, $v0, L_800F8C6C
    if (ctx->r18 != ctx->r2) {
        // 0x800F8C5C: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800F8C6C;
    }
    // 0x800F8C5C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800F8C60: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800F8C64: b           L_800F8C70
    // 0x800F8C68: addiu       $a1, $a1, 0x5500
    ctx->r5 = ADD32(ctx->r5, 0X5500);
        goto L_800F8C70;
    // 0x800F8C68: addiu       $a1, $a1, 0x5500
    ctx->r5 = ADD32(ctx->r5, 0X5500);
L_800F8C6C:
    // 0x800F8C6C: addiu       $a1, $a1, 0x5510
    ctx->r5 = ADD32(ctx->r5, 0X5510);
L_800F8C70:
    // 0x800F8C70: jal         0x800F8294
    // 0x800F8C74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F8294(rdram, ctx);
        goto after_6;
    // 0x800F8C74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x800F8C78: b           L_800F8C8C
    // 0x800F8C7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800F8C8C;
    // 0x800F8C7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800F8C80:
    // 0x800F8C80: jal         0x800F8294
    // 0x800F8C84: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    func_800F8294(rdram, ctx);
        goto after_7;
    // 0x800F8C84: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    after_7:
    // 0x800F8C88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800F8C8C:
    // 0x800F8C8C: jal         0x800F832C
    // 0x800F8C90: addiu       $a1, $s0, 0x30
    ctx->r5 = ADD32(ctx->r16, 0X30);
    func_800F832C(rdram, ctx);
        goto after_8;
    // 0x800F8C90: addiu       $a1, $s0, 0x30
    ctx->r5 = ADD32(ctx->r16, 0X30);
    after_8:
    // 0x800F8C94: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x800F8C98: beql        $t8, $zero, L_800F8CAC
    if (ctx->r24 == 0) {
        // 0x800F8C9C: lbu         $t9, 0x0($s3)
        ctx->r25 = MEM_BU(ctx->r19, 0X0);
            goto L_800F8CAC;
    }
    goto skip_1;
    // 0x800F8C9C: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
    skip_1:
    // 0x800F8CA0: jal         0x800F80D8
    // 0x800F8CA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F80D8(rdram, ctx);
        goto after_9;
    // 0x800F8CA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x800F8CA8: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
L_800F8CAC:
    // 0x800F8CAC: beql        $s5, $t9, L_800F8CD8
    if (ctx->r21 == ctx->r25) {
        // 0x800F8CB0: lbu         $a1, 0x2($s0)
        ctx->r5 = MEM_BU(ctx->r16, 0X2);
            goto L_800F8CD8;
    }
    goto skip_2;
    // 0x800F8CB0: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    skip_2:
    // 0x800F8CB4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800F8CB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F8CBC: beq         $s2, $v0, L_800F8CCC
    if (ctx->r18 == ctx->r2) {
        // 0x800F8CC0: nop
    
            goto L_800F8CCC;
    }
    // 0x800F8CC0: nop

    // 0x800F8CC4: bnel        $s4, $v0, L_800F8CD8
    if (ctx->r20 != ctx->r2) {
        // 0x800F8CC8: lbu         $a1, 0x2($s0)
        ctx->r5 = MEM_BU(ctx->r16, 0X2);
            goto L_800F8CD8;
    }
    goto skip_3;
    // 0x800F8CC8: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    skip_3:
L_800F8CCC:
    // 0x800F8CCC: jal         0x800F8358
    // 0x800F8CD0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800F8358(rdram, ctx);
        goto after_10;
    // 0x800F8CD0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_10:
    // 0x800F8CD4: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
L_800F8CD8:
    // 0x800F8CD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F8CDC: beq         $a1, $s5, L_800F8CF4
    if (ctx->r5 == ctx->r21) {
        // 0x800F8CE0: nop
    
            goto L_800F8CF4;
    }
    // 0x800F8CE0: nop

    // 0x800F8CE4: beq         $a1, $at, L_800F8CFC
    if (ctx->r5 == ctx->r1) {
        // 0x800F8CE8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800F8CFC;
    }
    // 0x800F8CE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F8CEC: b           L_800F8D08
    // 0x800F8CF0: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
        goto L_800F8D08;
    // 0x800F8CF0: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
L_800F8CF4:
    // 0x800F8CF4: b           L_800F8D08
    // 0x800F8CF8: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
        goto L_800F8D08;
    // 0x800F8CF8: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
L_800F8CFC:
    // 0x800F8CFC: jal         0x800F608C
    // 0x800F8D00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F608C(rdram, ctx);
        goto after_11;
    // 0x800F8D00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x800F8D04: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
L_800F8D08:
    // 0x800F8D08: beq         $v0, $zero, L_800F8D18
    if (ctx->r2 == 0) {
        // 0x800F8D0C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800F8D18;
    }
    // 0x800F8D0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F8D10: jal         0x800F8D80
    // 0x800F8D14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800F8D80(rdram, ctx);
        goto after_12;
    // 0x800F8D14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
L_800F8D18:
    // 0x800F8D18: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
L_800F8D1C:
    // 0x800F8D1C: sltu        $at, $s0, $s6
    ctx->r1 = ctx->r16 < ctx->r22 ? 1 : 0;
    // 0x800F8D20: bne         $at, $zero, L_800F8BF8
    if (ctx->r1 != 0) {
        // 0x800F8D24: nop
    
            goto L_800F8BF8;
    }
    // 0x800F8D24: nop

L_800F8D28:
    // 0x800F8D28: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800F8D2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F8D30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800F8D34: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800F8D38: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800F8D3C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800F8D40: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800F8D44: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800F8D48: jr          $ra
    // 0x800F8D4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800F8D4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808011D0_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011D0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808011D4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x808011D8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808011DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808011E0: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808011E4: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x808011E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808011EC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808011F0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808011F4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808011F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808011FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801200: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801204: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80801208: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8080120C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80801210: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801214: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80801218: jal         0x800EEC30
    // 0x8080121C: nop

    func_800EEC30(rdram, ctx);
        goto after_0;
    // 0x8080121C: nop

    after_0:
    // 0x80801220: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801224: jal         0x800EF04C
    // 0x80801228: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x80801228: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x8080122C: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
    // 0x80801230: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801234: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801238: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080123C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80801240: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80801244: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80801248: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8080124C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80801250: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801254: jal         0x800EFA4C
    // 0x80801258: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80801258: nop

    after_2:
    // 0x8080125C: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x80801260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801264: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80801268: jal         0x800A516C
    // 0x8080126C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800A516C(rdram, ctx);
        goto after_3;
    // 0x8080126C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80801270: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801274: jal         0x800E39D8
    // 0x80801278: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E39D8(rdram, ctx);
        goto after_4;
    // 0x80801278: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8080127C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801280: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801284: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801288: jr          $ra
    // 0x8080128C: nop

    return;
    // 0x8080128C: nop

;}
RECOMP_FUNC void func_80800DC8_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800DCC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800DD0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800DD4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800DD8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800DDC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800DE0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800DE4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800DE8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800DEC: jal         0x80100094
    // 0x80800DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DF4: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
    // 0x80800DF8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800DFC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800E00: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800E04: sw          $zero, 0x34($s2)
    MEM_W(0X34, ctx->r18) = 0;
    // 0x80800E08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800E0C: beq         $t7, $zero, L_80800E54
    if (ctx->r15 == 0) {
        // 0x80800E10: swc1        $f20, 0x54($s2)
        MEM_W(0X54, ctx->r18) = ctx->f20.u32l;
            goto L_80800E54;
    }
    // 0x80800E10: swc1        $f20, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f20.u32l;
    // 0x80800E14: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800E18: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800E1C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800E20: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
L_80800E24:
    // 0x80800E24: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800E28: jal         0x800DC178
    // 0x80800E2C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800E2C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_1:
    // 0x80800E30: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80800E34: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    // 0x80800E38: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
    // 0x80800E3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800E40: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80800E44: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800E48: sltu        $at, $s1, $t9
    ctx->r1 = ctx->r17 < ctx->r25 ? 1 : 0;
    // 0x80800E4C: bnel        $at, $zero, L_80800E24
    if (ctx->r1 != 0) {
        // 0x80800E50: sw          $zero, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = 0;
            goto L_80800E24;
    }
    goto skip_0;
    // 0x80800E50: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    skip_0:
L_80800E54:
    // 0x80800E54: sw          $zero, 0x204($s3)
    MEM_W(0X204, ctx->r19) = 0;
    // 0x80800E58: sw          $zero, 0x208($s3)
    MEM_W(0X208, ctx->r19) = 0;
    // 0x80800E5C: sw          $zero, 0x20C($s3)
    MEM_W(0X20C, ctx->r19) = 0;
    // 0x80800E60: sw          $zero, 0x200($s3)
    MEM_W(0X200, ctx->r19) = 0;
    // 0x80800E64: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800E68: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800E6C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E70: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800E74: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800E78: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800E7C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800E80: jr          $ra
    // 0x80800E84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800E84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80801CBC_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CC4: jal         0x80082FF0
    // 0x80801CC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801CC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801CCC: jal         0x80800188
    // 0x80801CD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800188_bsbfly(rdram, ctx);
        goto after_1;
    // 0x80801CD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801CD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801CDC: jr          $ra
    // 0x80801CE0: nop

    return;
    // 0x80801CE0: nop

;}
RECOMP_FUNC void func_808001B8_chloggo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001C0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808001C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001CC: beq         $a1, $at, L_80800338
    if (ctx->r5 == ctx->r1) {
        // 0x808001D0: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800338;
    }
    // 0x808001D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808001D4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808001D8: beq         $a1, $at, L_80800204
    if (ctx->r5 == ctx->r1) {
        // 0x808001DC: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_80800204;
    }
    // 0x808001DC: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x808001E0: beq         $a1, $at, L_808002C8
    if (ctx->r5 == ctx->r1) {
        // 0x808001E4: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_808002C8;
    }
    // 0x808001E4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808001E8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808001EC: beq         $a1, $at, L_80800328
    if (ctx->r5 == ctx->r1) {
        // 0x808001F0: addiu       $at, $zero, 0x91
        ctx->r1 = ADD32(0, 0X91);
            goto L_80800328;
    }
    // 0x808001F0: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x808001F4: beql        $a1, $at, L_8080036C
    if (ctx->r5 == ctx->r1) {
        // 0x808001F8: lbu         $t4, 0x94($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X94);
            goto L_8080036C;
    }
    goto skip_0;
    // 0x808001F8: lbu         $t4, 0x94($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X94);
    skip_0:
    // 0x808001FC: b           L_80800384
    // 0x80800200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800384;
    // 0x80800200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800204:
    // 0x80800204: lh          $a1, 0x30($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X30);
    // 0x80800208: addiu       $at, $zero, 0x1343
    ctx->r1 = ADD32(0, 0X1343);
    // 0x8080020C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80800210: beq         $a1, $at, L_8080022C
    if (ctx->r5 == ctx->r1) {
        // 0x80800214: addiu       $a2, $s0, 0x18
        ctx->r6 = ADD32(ctx->r16, 0X18);
            goto L_8080022C;
    }
    // 0x80800214: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x80800218: addiu       $at, $zero, 0x1367
    ctx->r1 = ADD32(0, 0X1367);
    // 0x8080021C: beq         $a1, $at, L_80800274
    if (ctx->r5 == ctx->r1) {
        // 0x80800220: addiu       $at, $zero, 0x1380
        ctx->r1 = ADD32(0, 0X1380);
            goto L_80800274;
    }
    // 0x80800220: addiu       $at, $zero, 0x1380
    ctx->r1 = ADD32(0, 0X1380);
    // 0x80800224: bne         $a1, $at, L_80800290
    if (ctx->r5 != ctx->r1) {
        // 0x80800228: addiu       $a3, $zero, 0x6
        ctx->r7 = ADD32(0, 0X6);
            goto L_80800290;
    }
    // 0x80800228: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
L_8080022C:
    // 0x8080022C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800230: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800234: jal         0x800D1000
    // 0x80800238: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_0;
    // 0x80800238: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8080023C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1292, 0X6E8) << 16);
    // 0x80800240: addiu       $a2, $a2, 0x6E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1292, 0X6E8));
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: jal         0x80089D18
    // 0x8080024C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080024C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800250: jal         0x80085710
    // 0x80800254: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x80800254: nop

    after_2:
    // 0x80800258: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080025C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800260: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800264: jal         0x80085708
    // 0x80800268: addiu       $a3, $zero, 0x2030
    ctx->r7 = ADD32(0, 0X2030);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800268: addiu       $a3, $zero, 0x2030
    ctx->r7 = ADD32(0, 0X2030);
    after_3:
    // 0x8080026C: b           L_80800384
    // 0x80800270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800384;
    // 0x80800270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800274:
    // 0x80800274: jal         0x80085710
    // 0x80800278: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x80800278: nop

    after_4:
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x80102424
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800288: b           L_80800384
    // 0x8080028C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800384;
    // 0x8080028C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800290:
    // 0x80800290: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1292, 0X5E0) << 16);
    // 0x80800294: addiu       $a2, $a2, 0x5E0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1292, 0X5E0));
    // 0x80800298: jal         0x8008A1F8
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808002A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002A4: bnel        $v0, $at, L_808002B8
    if (ctx->r2 != ctx->r1) {
        // 0x808002A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002B8;
    }
    goto skip_1;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808002AC: jal         0x8010A590
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_7;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002B8:
    // 0x808002B8: jal         0x80102424
    // 0x808002BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x808002BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808002C0: b           L_80800384
    // 0x808002C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800384;
    // 0x808002C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002C8:
    // 0x808002C8: lhu         $t6, 0x18($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X18);
    // 0x808002CC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808002D0: beql        $t7, $zero, L_808002E4
    if (ctx->r15 == 0) {
        // 0x808002D4: lhu         $a0, 0x1A($v0)
        ctx->r4 = MEM_HU(ctx->r2, 0X1A);
            goto L_808002E4;
    }
    goto skip_2;
    // 0x808002D4: lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1A);
    skip_2:
    // 0x808002D8: b           L_80800384
    // 0x808002DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800384;
    // 0x808002DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002E0: lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1A);
L_808002E4:
    // 0x808002E4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808002E8: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x808002EC: jal         0x800F52B8
    // 0x808002F0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800F52B8(rdram, ctx);
        goto after_9;
    // 0x808002F0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_9:
    // 0x808002F4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808002F8: bnel        $v0, $at, L_80800384
    if (ctx->r2 != ctx->r1) {
        // 0x808002FC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800384;
    }
    goto skip_3;
    // 0x808002FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80800300: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80800304: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800310: beql        $t0, $at, L_80800384
    if (ctx->r8 == ctx->r1) {
        // 0x80800314: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800384;
    }
    goto skip_4;
    // 0x80800314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x80800318: jal         0x80102424
    // 0x8080031C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x8080031C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800320: b           L_80800384
    // 0x80800324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800384;
    // 0x80800324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800328:
    // 0x80800328: jal         0x80800398
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800398_chloggo(rdram, ctx);
        goto after_11;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800330: b           L_80800384
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800384;
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800338:
    // 0x80800338: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8080033C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800340: addiu       $a1, $zero, 0x1367
    ctx->r5 = ADD32(0, 0X1367);
    // 0x80800344: bne         $t1, $at, L_80800360
    if (ctx->r9 != ctx->r1) {
        // 0x80800348: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80800360;
    }
    // 0x80800348: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8080034C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800350: addiu       $t2, $zero, 0xAD
    ctx->r10 = ADD32(0, 0XAD);
    // 0x80800354: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800358: jal         0x8008A208
    // 0x8080035C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x8080035C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_12:
L_80800360:
    // 0x80800360: b           L_80800384
    // 0x80800364: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800384;
    // 0x80800364: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800368: lbu         $t4, 0x94($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X94);
L_8080036C:
    // 0x8080036C: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x80800370: b           L_80800380
    // 0x80800374: sb          $t5, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r13;
        goto L_80800380;
    // 0x80800374: sb          $t5, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r13;
    // 0x80800378: b           L_80800384
    // 0x8080037C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800384;
    // 0x8080037C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800380:
    // 0x80800380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800384:
    // 0x80800384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800388: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080038C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800390: jr          $ra
    // 0x80800394: nop

    return;
    // 0x80800394: nop

;}
