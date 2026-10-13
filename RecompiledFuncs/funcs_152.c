#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800D2910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2910: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D2914: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D2918: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800D291C: addiu       $v1, $v1, -0x4CE0
    ctx->r3 = ADD32(ctx->r3, -0X4CE0);
    // 0x800D2920: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D2924: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x800D2928: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D292C: sb          $t7, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r15;
    // 0x800D2930: lbu         $t8, 0xC($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XC);
    // 0x800D2934: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x800D2938: lbu         $t9, 0xD($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XD);
    // 0x800D293C: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x800D2940: lbu         $t0, 0xE($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XE);
    // 0x800D2944: sh          $t0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r8;
    // 0x800D2948: lbu         $t1, 0xF($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XF);
    // 0x800D294C: sh          $t1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r9;
    // 0x800D2950: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800D2954: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x800D2958: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800D295C: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x800D2960: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x800D2964: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800D2968: jr          $ra
    // 0x800D296C: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    return;
    // 0x800D296C: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
;}
RECOMP_FUNC void _ncpoducam_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089640: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089640);
    return;
    // 0x80089644: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void subaddiezone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080005C: jal         0x800BEC1C
    // 0x80800060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800BEC1C(rdram, ctx);
        goto after_0;
    // 0x80800060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800064: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080006C: jal         0x80088780
    // 0x80800070: lbu         $a1, 0x78($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X78);
    _glzone_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800070: lbu         $a1, 0x78($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X78);
    after_1:
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

    // 0x80800084: nop

    // 0x80800088: nop

    // 0x8080008C: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003AC: jal         0x800D92EC
    // 0x808003B0: nop

    func_800D92EC(rdram, ctx);
        goto after_0;
    // 0x808003B0: nop

    after_0:
    // 0x808003B4: jal         0x8080000C
    // 0x808003B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8080000C_glcutDll(rdram, ctx);
        goto after_1;
    // 0x808003B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808003BC: jal         0x80800000
    // 0x808003C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800000_glcutDll(rdram, ctx);
        goto after_2;
    // 0x808003C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x808003C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x808003C8: addiu       $v0, $v0, 0x75E8
    ctx->r2 = ADD32(ctx->r2, 0X75E8);
    // 0x808003CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808003D0: sb          $t6, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r14;
    // 0x808003D4: sb          $zero, 0xB($v0)
    MEM_B(0XB, ctx->r2) = 0;
    // 0x808003D8: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x808003DC: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x808003E0: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x808003E4: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x808003E8: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x808003EC: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    // 0x808003F0: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    // 0x808003F4: jal         0x80800018
    // 0x808003F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800018_glcutDll(rdram, ctx);
        goto after_3;
    // 0x808003F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x808003FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800404: jr          $ra
    // 0x80800408: nop

    return;
    // 0x80800408: nop

;}
RECOMP_FUNC void func_800936D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800936D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800936DC: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x800936E0: jr          $ra
    // 0x800936E4: swc1        $f12, 0x98($t6)
    MEM_W(0X98, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x800936E4: swc1        $f12, 0x98($t6)
    MEM_W(0X98, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void gsattract_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800010: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80800014: addiu       $a1, $a1, 0x5470
    ctx->r5 = ADD32(ctx->r5, 0X5470);
    // 0x80800018: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8080001C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800024: jal         0x800C95D4
    // 0x80800028: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800C95D4(rdram, ctx);
        goto after_0;
    // 0x80800028: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8080002C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80800030: beq         $v0, $zero, L_80800054
    if (ctx->r2 == 0) {
        // 0x80800034: addiu       $a1, $a1, 0x5470
        ctx->r5 = ADD32(ctx->r5, 0X5470);
            goto L_80800054;
    }
    // 0x80800034: addiu       $a1, $a1, 0x5470
    ctx->r5 = ADD32(ctx->r5, 0X5470);
    // 0x80800038: jal         0x800D9004
    // 0x8080003C: nop

    func_800D9004(rdram, ctx);
        goto after_1;
    // 0x8080003C: nop

    after_1:
    // 0x80800040: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80800044: addiu       $a1, $a1, 0x5470
    ctx->r5 = ADD32(ctx->r5, 0X5470);
    // 0x80800048: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8080004C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800050: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
L_80800054:
    // 0x80800054: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80800058: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2882, 0X490) << 16);
    // 0x8080005C: addiu       $t8, $t8, 0x490
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2882, 0X490));
    // 0x80800060: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800064: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800068: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080006C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80800070: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x80800074: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800078: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x8080007C: beql        $t9, $zero, L_808000FC
    if (ctx->r25 == 0) {
        // 0x80800080: andi        $t3, $v1, 0x2
        ctx->r11 = ctx->r3 & 0X2;
            goto L_808000FC;
    }
    goto skip_0;
    // 0x80800080: andi        $t3, $v1, 0x2
    ctx->r11 = ctx->r3 & 0X2;
    skip_0:
    // 0x80800084: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800088: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8080008C: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80800094: nop

    // 0x80800098: bc1fl       L_808000FC
    if (!c1cs) {
        // 0x8080009C: andi        $t3, $v1, 0x2
        ctx->r11 = ctx->r3 & 0X2;
            goto L_808000FC;
    }
    goto skip_1;
    // 0x8080009C: andi        $t3, $v1, 0x2
    ctx->r11 = ctx->r3 & 0X2;
    skip_1:
    // 0x808000A0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808000A4: nop

    // 0x808000A8: bc1fl       L_808000FC
    if (!c1cs) {
        // 0x808000AC: andi        $t3, $v1, 0x2
        ctx->r11 = ctx->r3 & 0X2;
            goto L_808000FC;
    }
    goto skip_2;
    // 0x808000AC: andi        $t3, $v1, 0x2
    ctx->r11 = ctx->r3 & 0X2;
    skip_2:
    // 0x808000B0: jal         0x800167F4
    // 0x808000B4: nop

    func_800167F4(rdram, ctx);
        goto after_2;
    // 0x808000B4: nop

    after_2:
    // 0x808000B8: beq         $v0, $zero, L_808000C8
    if (ctx->r2 == 0) {
        // 0x808000BC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_808000C8;
    }
    // 0x808000BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808000C0: b           L_808000C8
    // 0x808000C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_808000C8;
    // 0x808000C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_808000C8:
    // 0x808000C8: jal         0x80085C00
    // 0x808000CC: nop

    _chattract_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808000CC: nop

    after_3:
    // 0x808000D0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x808000D4: addiu       $a1, $a1, 0x5470
    ctx->r5 = ADD32(ctx->r5, 0X5470);
    // 0x808000D8: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x808000DC: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2882, 0X490) << 16);
    // 0x808000E0: addiu       $t2, $t2, 0x490
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2882, 0X490));
    // 0x808000E4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808000E8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x808000EC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808000F0: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x808000F4: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x808000F8: andi        $t3, $v1, 0x2
    ctx->r11 = ctx->r3 & 0X2;
L_808000FC:
    // 0x808000FC: beq         $t3, $zero, L_8080015C
    if (ctx->r11 == 0) {
        // 0x80800100: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8080015C;
    }
    // 0x80800100: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800104: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800108: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8080010C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800110: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80800114: nop

    // 0x80800118: bc1fl       L_80800160
    if (!c1cs) {
        // 0x8080011C: lbu         $t8, 0x1($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X1);
            goto L_80800160;
    }
    goto skip_3;
    // 0x8080011C: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    skip_3:
    // 0x80800120: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800124: nop

    // 0x80800128: bc1fl       L_80800160
    if (!c1cs) {
        // 0x8080012C: lbu         $t8, 0x1($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X1);
            goto L_80800160;
    }
    goto skip_4;
    // 0x8080012C: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    skip_4:
    // 0x80800130: jal         0x80085C00
    // 0x80800134: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _chattract_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800134: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80800138: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8080013C: addiu       $a1, $a1, 0x5470
    ctx->r5 = ADD32(ctx->r5, 0X5470);
    // 0x80800140: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x80800144: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2882, 0X490) << 16);
    // 0x80800148: addiu       $t6, $t6, 0x490
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2882, 0X490));
    // 0x8080014C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80800150: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80800154: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800158: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
L_8080015C:
    // 0x8080015C: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
L_80800160:
    // 0x80800160: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80800164: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800168: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8080016C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80800170: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80800174: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80800178: lbu         $t1, 0x3($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X3);
    // 0x8080017C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80800180: beq         $t2, $zero, L_808001BC
    if (ctx->r10 == 0) {
        // 0x80800184: nop
    
            goto L_808001BC;
    }
    // 0x80800184: nop

    // 0x80800188: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080018C: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80800190: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800194: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80800198: nop

    // 0x8080019C: bc1f        L_808001BC
    if (!c1cs) {
        // 0x808001A0: nop
    
            goto L_808001BC;
    }
    // 0x808001A0: nop

    // 0x808001A4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808001A8: nop

    // 0x808001AC: bc1f        L_808001BC
    if (!c1cs) {
        // 0x808001B0: nop
    
            goto L_808001BC;
    }
    // 0x808001B0: nop

    // 0x808001B4: jal         0x80085C00
    // 0x808001B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _chattract_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808001B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
L_808001BC:
    // 0x808001BC: jal         0x800C95D4
    // 0x808001C0: nop

    func_800C95D4(rdram, ctx);
        goto after_6;
    // 0x808001C0: nop

    after_6:
    // 0x808001C4: beql        $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x808001C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001E8;
    }
    goto skip_5;
    // 0x808001C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x808001CC: jal         0x80015FA0
    // 0x808001D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015FA0(rdram, ctx);
        goto after_7;
    // 0x808001D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x808001D4: beql        $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x808001D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001E8;
    }
    goto skip_6;
    // 0x808001D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x808001DC: jal         0x800A9C50
    // 0x808001E0: nop

    func_800A9C50(rdram, ctx);
        goto after_8;
    // 0x808001E0: nop

    after_8:
    // 0x808001E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001E8:
    // 0x808001E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001EC: jr          $ra
    // 0x808001F0: nop

    return;
    // 0x808001F0: nop

;}
RECOMP_FUNC void _chskeletonexplode_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E08: syscall     459
    recomp_syscall_handler(rdram, ctx, 0x80086E08);
    return;
    // 0x80086E0C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bafly_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C38: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C38);
    return;
    // 0x80084C3C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800F7D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7D90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7D94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F7D98: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F7D9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7DA0: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F7DA4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7DAC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F7DB0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F7DB4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F7DB8: jal         0x8009AD44
    // 0x800F7DBC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD44(rdram, ctx);
        goto after_0;
    // 0x800F7DBC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7DC0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7DC4: jal         0x8009AD20
    // 0x800F7DC8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8009AD20(rdram, ctx);
        goto after_1;
    // 0x800F7DC8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800F7DCC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7DD0: jal         0x8009E7C8
    // 0x800F7DD4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F7DD4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x800F7DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7DDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7DE0: jr          $ra
    // 0x800F7DE4: nop

    return;
    // 0x800F7DE4: nop

;}
RECOMP_FUNC void chfaircoinbox_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080035C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800360: jal         0x80106790
    // 0x80800364: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800364: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800368: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080036C: jal         0x800EE7F8
    // 0x80800370: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800370: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x80800374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080037C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

;}
RECOMP_FUNC void bsclimb_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080084C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800850: jal         0x8009E6EC
    // 0x80800854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800858: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8080085C: bne         $v0, $at, L_80800870
    if (ctx->r2 != ctx->r1) {
        // 0x80800860: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800870;
    }
    // 0x80800860: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800864: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800868: b           L_80800880
    // 0x8080086C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
        goto L_80800880;
    // 0x8080086C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
L_80800870:
    // 0x80800870: jal         0x80099B94
    // 0x80800874: nop

    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x80800874: nop

    after_1:
    // 0x80800878: b           L_8080089C
    // 0x8080087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080089C;
    // 0x8080087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800880:
    // 0x80800880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800884: jal         0x8009E830
    // 0x80800888: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x80800888: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8080088C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800890: jal         0x8009E5C8
    // 0x80800894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80800894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080089C:
    // 0x8080089C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008A0: jr          $ra
    // 0x808008A4: nop

    return;
    // 0x808008A4: nop

    // 0x808008A8: nop

    // 0x808008AC: nop

;}
RECOMP_FUNC void func_80800BEC_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BF4: jal         0x8009EF1C
    // 0x80800BF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800BF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BFC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800C00: jal         0x8009EF10
    // 0x80800C04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800C04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800C08: beq         $v0, $zero, L_80800C24
    if (ctx->r2 == 0) {
        // 0x80800C0C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800C24;
    }
    // 0x80800C0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C14: beq         $v0, $at, L_80800C34
    if (ctx->r2 == ctx->r1) {
        // 0x80800C18: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80800C34;
    }
    // 0x80800C18: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800C1C: b           L_80800C58
    // 0x80800C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C58;
    // 0x80800C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C24:
    // 0x80800C24: jal         0x8009B9B0
    // 0x80800C28: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800C28: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800C2C: b           L_80800C58
    // 0x80800C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C58;
    // 0x80800C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C34:
    // 0x80800C34: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800C38: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C3C: lui         $a2, 0x4422
    ctx->r6 = S32(0X4422 << 16);
    // 0x80800C40: jal         0x800F1214
    // 0x80800C44: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800C44: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    after_3:
    // 0x80800C48: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C4C: jal         0x8009B9B0
    // 0x80800C50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800C50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C58:
    // 0x80800C58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C5C: jr          $ra
    // 0x80800C60: nop

    return;
    // 0x80800C60: nop

;}
RECOMP_FUNC void _glsavegame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088520: syscall     692
    recomp_syscall_handler(rdram, ctx, 0x80088520);
    return;
    // 0x80088524: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _subaddiefade_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CE0: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CE0);
    return;
    // 0x80089CE4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_8010B990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B990: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8010B994: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8010B998: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8010B99C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8010B9A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010B9A4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8010B9A8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8010B9AC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8010B9B0: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8010B9B4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8010B9B8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8010B9BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010B9C0: jal         0x80104580
    // 0x8010B9C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_80104580(rdram, ctx);
        goto after_0;
    // 0x8010B9C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x8010B9C8: addiu       $s4, $sp, 0x40
    ctx->r20 = ADD32(ctx->r29, 0X40);
    // 0x8010B9CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010B9D0: jal         0x800EE7F8
    // 0x8010B9D4: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8010B9D4: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    after_1:
    // 0x8010B9D8: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8010B9DC: addiu       $s5, $s5, 0x4714
    ctx->r21 = ADD32(ctx->r21, 0X4714);
    // 0x8010B9E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8010B9E4: addiu       $s7, $zero, 0x6
    ctx->r23 = ADD32(0, 0X6);
    // 0x8010B9E8: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x8010B9EC: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
L_8010B9F0:
    // 0x8010B9F0: srlv        $v0, $s2, $t6
    ctx->r2 = S32(U32(ctx->r18) >> (ctx->r14 & 31));
    // 0x8010B9F4: andi        $t7, $v0, 0xF
    ctx->r15 = ctx->r2 & 0XF;
    // 0x8010B9F8: beq         $t7, $zero, L_8010BA44
    if (ctx->r15 == 0) {
        // 0x8010B9FC: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_8010BA44;
    }
    // 0x8010B9FC: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8010BA00: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x8010BA04: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8010BA08: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8010BA0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8010BA10: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8010BA14: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8010BA18: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8010BA1C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8010BA20: jalr        $t9
    // 0x8010BA24: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8010BA24: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_2:
    // 0x8010BA28: bne         $v0, $s6, L_8010BA38
    if (ctx->r2 != ctx->r22) {
        // 0x8010BA2C: sllv        $t3, $v0, $s0
        ctx->r11 = S32(ctx->r2 << (ctx->r16 & 31));
            goto L_8010BA38;
    }
    // 0x8010BA2C: sllv        $t3, $v0, $s0
    ctx->r11 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x8010BA30: b           L_8010BA54
    // 0x8010BA34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010BA54;
    // 0x8010BA34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010BA38:
    // 0x8010BA38: beql        $v0, $zero, L_8010BA48
    if (ctx->r2 == 0) {
        // 0x8010BA3C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8010BA48;
    }
    goto skip_0;
    // 0x8010BA3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8010BA40: or          $s1, $s1, $t3
    ctx->r17 = ctx->r17 | ctx->r11;
L_8010BA44:
    // 0x8010BA44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8010BA48:
    // 0x8010BA48: bnel        $s0, $s7, L_8010B9F0
    if (ctx->r16 != ctx->r23) {
        // 0x8010BA4C: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_8010B9F0;
    }
    goto skip_1;
    // 0x8010BA4C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    skip_1:
    // 0x8010BA50: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8010BA54:
    // 0x8010BA54: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8010BA58: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010BA5C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010BA60: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8010BA64: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8010BA68: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8010BA6C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8010BA70: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8010BA74: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8010BA78: jr          $ra
    // 0x8010BA7C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8010BA7C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void sumole_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808014B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014B8: jal         0x80106790
    // 0x808014BC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808014BC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808014C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808014C4: jal         0x80086918
    // 0x808014C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _chmolehill_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808014C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808014CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014D4: jr          $ra
    // 0x808014D8: nop

    return;
    // 0x808014D8: nop

;}
RECOMP_FUNC void func_808005F8_chdinofamilysick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800600: jal         0x800EA05C
    // 0x80800604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800608: addiu       $at, $zero, 0x114
    ctx->r1 = ADD32(0, 0X114);
    // 0x8080060C: beq         $v0, $at, L_8080062C
    if (ctx->r2 == ctx->r1) {
        // 0x80800610: addiu       $at, $zero, 0x118
        ctx->r1 = ADD32(0, 0X118);
            goto L_8080062C;
    }
    // 0x80800610: addiu       $at, $zero, 0x118
    ctx->r1 = ADD32(0, 0X118);
    // 0x80800614: beq         $v0, $at, L_8080064C
    if (ctx->r2 == ctx->r1) {
        // 0x80800618: addiu       $at, $zero, 0x121
        ctx->r1 = ADD32(0, 0X121);
            goto L_8080064C;
    }
    // 0x80800618: addiu       $at, $zero, 0x121
    ctx->r1 = ADD32(0, 0X121);
    // 0x8080061C: beq         $v0, $at, L_808006FC
    if (ctx->r2 == ctx->r1) {
        // 0x80800620: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_808006FC;
    }
    // 0x80800620: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800624: b           L_80800750
    // 0x80800628: nop

        goto L_80800750;
    // 0x80800628: nop

L_8080062C:
    // 0x8080062C: jal         0x80088840
    // 0x80800630: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800630: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_1:
    // 0x80800634: bne         $v0, $zero, L_80800758
    if (ctx->r2 != 0) {
        // 0x80800638: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800758;
    }
    // 0x80800638: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080063C: jal         0x800FFA88
    // 0x80800640: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80800640: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x80800644: b           L_8080075C
    // 0x80800648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080075C;
    // 0x80800648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080064C:
    // 0x8080064C: jal         0x80088848
    // 0x80800650: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800650: nop

    after_3:
    // 0x80800654: beq         $v0, $zero, L_8080068C
    if (ctx->r2 == 0) {
        // 0x80800658: nop
    
            goto L_8080068C;
    }
    // 0x80800658: nop

    // 0x8080065C: jal         0x80105494
    // 0x80800660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80105494(rdram, ctx);
        goto after_4;
    // 0x80800660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800664: beq         $v0, $zero, L_8080067C
    if (ctx->r2 == 0) {
        // 0x80800668: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080067C;
    }
    // 0x80800668: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080066C: jal         0x800FFAB0
    // 0x80800670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80800674: b           L_8080075C
    // 0x80800678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080075C;
    // 0x80800678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080067C:
    // 0x8080067C: jal         0x80102424
    // 0x80800680: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800680: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_6:
    // 0x80800684: b           L_8080075C
    // 0x80800688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080075C;
    // 0x80800688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080068C:
    // 0x8080068C: jal         0x80088840
    // 0x80800690: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_7;
    // 0x80800690: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_7:
    // 0x80800694: bnel        $v0, $zero, L_8080075C
    if (ctx->r2 != 0) {
        // 0x80800698: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080075C;
    }
    goto skip_0;
    // 0x80800698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080069C: jal         0x80105494
    // 0x808006A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80105494(rdram, ctx);
        goto after_8;
    // 0x808006A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_8:
    // 0x808006A4: bne         $v0, $zero, L_808006EC
    if (ctx->r2 != 0) {
        // 0x808006A8: nop
    
            goto L_808006EC;
    }
    // 0x808006A8: nop

    // 0x808006AC: jal         0x800DA298
    // 0x808006B0: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808006B0: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_9:
    // 0x808006B4: bne         $v0, $zero, L_808006DC
    if (ctx->r2 != 0) {
        // 0x808006B8: nop
    
            goto L_808006DC;
    }
    // 0x808006B8: nop

    // 0x808006BC: jal         0x800DA298
    // 0x808006C0: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x808006C0: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_10:
    // 0x808006C4: beq         $v0, $zero, L_808006DC
    if (ctx->r2 == 0) {
        // 0x808006C8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808006DC;
    }
    // 0x808006C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006CC: jal         0x80102424
    // 0x808006D0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x808006D0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_11:
    // 0x808006D4: b           L_8080075C
    // 0x808006D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080075C;
    // 0x808006D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006DC:
    // 0x808006DC: jal         0x800FFAB0
    // 0x808006E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x808006E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_12:
    // 0x808006E4: b           L_8080075C
    // 0x808006E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080075C;
    // 0x808006E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006EC:
    // 0x808006EC: jal         0x800FFAB0
    // 0x808006F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x808006F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_13:
    // 0x808006F4: b           L_8080075C
    // 0x808006F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080075C;
    // 0x808006F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006FC:
    // 0x808006FC: jal         0x800DA298
    // 0x80800700: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x80800700: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_14:
    // 0x80800704: beq         $v0, $zero, L_80800740
    if (ctx->r2 == 0) {
        // 0x80800708: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80800740;
    }
    // 0x80800708: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080070C: jal         0x800DA298
    // 0x80800710: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x80800710: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_15:
    // 0x80800714: beq         $v0, $zero, L_80800730
    if (ctx->r2 == 0) {
        // 0x80800718: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800730;
    }
    // 0x80800718: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080071C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800720: jal         0x80102424
    // 0x80800724: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x80800724: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_16:
    // 0x80800728: b           L_8080075C
    // 0x8080072C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080075C;
    // 0x8080072C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800730:
    // 0x80800730: jal         0x80102424
    // 0x80800734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x80800734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800738: b           L_8080075C
    // 0x8080073C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080075C;
    // 0x8080073C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800740:
    // 0x80800740: jal         0x800FFA88
    // 0x80800744: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_18;
    // 0x80800744: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_18:
    // 0x80800748: b           L_8080075C
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080075C;
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800750:
    // 0x80800750: jal         0x800FFA88
    // 0x80800754: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_19;
    // 0x80800754: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_19:
L_80800758:
    // 0x80800758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080075C:
    // 0x8080075C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800760: jr          $ra
    // 0x80800764: nop

    return;
    // 0x80800764: nop

;}
RECOMP_FUNC void func_800E9EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9EE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E9EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9EF0: jal         0x80088300
    // 0x800E9EF4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    _gccubesearch_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x800E9EF4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800E9EF8: beq         $v0, $zero, L_800E9F08
    if (ctx->r2 == 0) {
        // 0x800E9EFC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800E9F08;
    }
    // 0x800E9EFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E9F00: jal         0x800E9B74
    // 0x800E9F04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800E9B74(rdram, ctx);
        goto after_1;
    // 0x800E9F04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_800E9F08:
    // 0x800E9F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9F0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E9F10: jr          $ra
    // 0x800E9F14: nop

    return;
    // 0x800E9F14: nop

    // 0x800E9F18: nop

    // 0x800E9F1C: nop

;}
RECOMP_FUNC void chpiranha_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A78: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1804, 0X1BF0) << 16);
    // 0x80801A7C: jr          $ra
    // 0x80801A80: addiu       $v0, $v0, 0x1BF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1804, 0X1BF0));
    return;
    // 0x80801A80: addiu       $v0, $v0, 0x1BF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1804, 0X1BF0));
    // 0x80801A84: nop

    // 0x80801A88: nop

    // 0x80801A8C: nop

;}
RECOMP_FUNC void func_808005EC_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808005F4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808005F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800600: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800604: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800608: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8080060C: jal         0x80100094
    // 0x80800610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800614: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800618: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080061C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800620: beq         $a2, $at, L_808006A8
    if (ctx->r6 == ctx->r1) {
        // 0x80800624: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_808006A8;
    }
    // 0x80800624: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800628: beq         $a2, $at, L_80800668
    if (ctx->r6 == ctx->r1) {
        // 0x8080062C: addiu       $v0, $sp, 0x28
        ctx->r2 = ADD32(ctx->r29, 0X28);
            goto L_80800668;
    }
    // 0x8080062C: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800630: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80800634: beq         $a2, $at, L_80800680
    if (ctx->r6 == ctx->r1) {
        // 0x80800638: addiu       $v0, $sp, 0x28
        ctx->r2 = ADD32(ctx->r29, 0X28);
            goto L_80800680;
    }
    // 0x80800638: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x8080063C: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800640: beq         $a2, $at, L_808006E4
    if (ctx->r6 == ctx->r1) {
        // 0x80800644: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(924, 0X21D0) << 16);
            goto L_808006E4;
    }
    // 0x80800644: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(924, 0X21D0) << 16);
    // 0x80800648: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x8080064C: beq         $a2, $at, L_808006B8
    if (ctx->r6 == ctx->r1) {
        // 0x80800650: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006B8;
    }
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800658: beq         $a2, $at, L_80800698
    if (ctx->r6 == ctx->r1) {
        // 0x8080065C: nop
    
            goto L_80800698;
    }
    // 0x8080065C: nop

    // 0x80800660: b           L_80800704
    // 0x80800664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800704;
    // 0x80800664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800668:
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800670: jal         0x80801F1C
    // 0x80800674: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80801F1C_chevilspirit(rdram, ctx);
        goto after_1;
    // 0x80800674: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x80800678: b           L_80800704
    // 0x8080067C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800704;
    // 0x8080067C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800680:
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800688: jal         0x80802024
    // 0x8080068C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80802024_chevilspirit(rdram, ctx);
        goto after_2;
    // 0x8080068C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_2:
    // 0x80800690: b           L_80800704
    // 0x80800694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800704;
    // 0x80800694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800698:
    // 0x80800698: jal         0x80801C04
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C04_chevilspirit(rdram, ctx);
        goto after_3;
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808006A0: b           L_80800704
    // 0x808006A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800704;
    // 0x808006A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006A8:
    // 0x808006A8: jal         0x801015D0
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_4;
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808006B0: b           L_80800704
    // 0x808006B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800704;
    // 0x808006B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006B8:
    // 0x808006B8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808006BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808006C0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808006C4: andi        $t6, $a2, 0xFFFF
    ctx->r14 = ctx->r6 & 0XFFFF;
    // 0x808006C8: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x808006CC: srl         $a3, $t7, 16
    ctx->r7 = S32(U32(ctx->r15) >> 16);
    // 0x808006D0: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x808006D4: jal         0x8008A2B8
    // 0x808006D8: addiu       $a1, $v1, 0x40
    ctx->r5 = ADD32(ctx->r3, 0X40);
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808006D8: addiu       $a1, $v1, 0x40
    ctx->r5 = ADD32(ctx->r3, 0X40);
    after_5:
    // 0x808006DC: b           L_80800708
    // 0x808006E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800708;
    // 0x808006E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006E4:
    // 0x808006E4: addiu       $a0, $a0, 0x21D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(924, 0X21D0));
    // 0x808006E8: jal         0x80088090
    // 0x808006EC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808006EC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x808006F0: b           L_80800704
    // 0x808006F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800704;
    // 0x808006F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808006F8: b           L_80800704
    // 0x808006FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800704;
    // 0x808006FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800704:
    // 0x80800704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800708:
    // 0x80800708: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080070C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800710: jr          $ra
    // 0x80800714: nop

    return;
    // 0x80800714: nop

;}
RECOMP_FUNC void glsavegame_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080057C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800584: jal         0x80800000
    // 0x80800588: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80800000_glsavegame(rdram, ctx);
        goto after_0;
    // 0x80800588: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080058C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800590: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800594: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800598: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8080059C: lb          $a0, 0x7624($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X7624);
    // 0x808005A0: jal         0x80800020
    // 0x808005A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800020_glsavegame(rdram, ctx);
        goto after_1;
    // 0x808005A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808005A8: bne         $v0, $zero, L_808005B8
    if (ctx->r2 != 0) {
        // 0x808005AC: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_808005B8;
    }
    // 0x808005AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808005B0: jal         0x80088580
    // 0x808005B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _glgamedata_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808005B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_808005B8:
    // 0x808005B8: jal         0x8001B084
    // 0x808005BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    heap_free(rdram, ctx);
        goto after_3;
    // 0x808005BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808005C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005C4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808005C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005CC: jr          $ra
    // 0x808005D0: nop

    return;
    // 0x808005D0: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DD8: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083DD8);
    return;
    // 0x80083DDC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chchuffycont_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800ABC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800AC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800AC4: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1704, 0XB20) << 16);
    // 0x80800AC8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1704, 0XB66) << 16);
    // 0x80800ACC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AD0: addiu       $s1, $s1, 0xB66
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1704, 0XB66));
    // 0x80800AD4: addiu       $s0, $s0, 0xB20
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1704, 0XB20));
L_80800AD8:
    // 0x80800AD8: jal         0x800DA298
    // 0x80800ADC: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800ADC: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_0:
    // 0x80800AE0: bne         $v0, $zero, L_80800AF4
    if (ctx->r2 != 0) {
        // 0x80800AE4: nop
    
            goto L_80800AF4;
    }
    // 0x80800AE4: nop

    // 0x80800AE8: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x80800AEC: bne         $s0, $s1, L_80800AD8
    if (ctx->r16 != ctx->r17) {
        // 0x80800AF0: nop
    
            goto L_80800AD8;
    }
    // 0x80800AF0: nop

L_80800AF4:
    // 0x80800AF4: jal         0x80088268
    // 0x80800AF8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800AF8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_1:
    // 0x80800AFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B00: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800B04: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800B08: jr          $ra
    // 0x80800B0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800B0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8080238C_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080238C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802390: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802394: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802398: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x8080239C: ori         $t6, $a2, 0x104
    ctx->r14 = ctx->r6 | 0X104;
    // 0x808023A0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808023A4: addiu       $t8, $zero, 0x42
    ctx->r24 = ADD32(0, 0X42);
    // 0x808023A8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x808023AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808023B0: jal         0x8008A208
    // 0x808023B4: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808023B4: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    after_0:
    // 0x808023B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808023BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808023C0: jr          $ra
    // 0x808023C4: nop

    return;
    // 0x808023C4: nop

;}
RECOMP_FUNC void func_800965C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800965C8: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800965CC: jr          $ra
    // 0x800965D0: lbu         $v0, 0xA4($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA4);
    return;
    // 0x800965D0: lbu         $v0, 0xA4($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA4);
;}
RECOMP_FUNC void func_800A2EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2EAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A2EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2EB4: jal         0x800A2C84
    // 0x800A2EB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A2C84(rdram, ctx);
        goto after_0;
    // 0x800A2EB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A2EBC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A2EC0: lw          $t7, 0x124($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X124);
    // 0x800A2EC4: jal         0x80088A28
    // 0x800A2EC8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _fxstep_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x800A2EC8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x800A2ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A2ED4: jr          $ra
    // 0x800A2ED8: nop

    return;
    // 0x800A2ED8: nop

;}
RECOMP_FUNC void func_808049DC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808049DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808049E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808049E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808049E8: jal         0x80100094
    // 0x808049EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808049EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808049F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808049F4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808049F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808049FC: lwc1        $f12, 0x20($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80804A00: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80804A04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80804A08: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80804A0C: jal         0x800F10B4
    // 0x80804A10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80804A10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80804A14: jal         0x800D8FF8
    // 0x80804A18: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80804A18: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80804A1C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80804A20: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80804A24: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80804A28: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80804A2C: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x80804A30: jal         0x800136E4
    // 0x80804A34: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x80804A34: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    after_3:
    // 0x80804A38: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80804A3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80804A40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80804A44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80804A48: jr          $ra
    // 0x80804A4C: nop

    return;
    // 0x80804A4C: nop

;}
RECOMP_FUNC void _chfactorybattery_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087488: syscall     577
    recomp_syscall_handler(rdram, ctx, 0x80087488);
    return;
    // 0x8008748C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sucoasterdata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A240: syscall     831
    recomp_syscall_handler(rdram, ctx, 0x8008A240);
    return;
    // 0x8008A244: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gcdialogcamera_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002EC: jal         0x808002A4
    // 0x808002F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808002A4_gcdialogcamera(rdram, ctx);
        goto after_0;
    // 0x808002F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002F4: jal         0x8080026C
    // 0x808002F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080026C_gcdialogcamera(rdram, ctx);
        goto after_1;
    // 0x808002F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808002FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800304: jr          $ra
    // 0x80800308: nop

    return;
    // 0x80800308: nop

;}
RECOMP_FUNC void func_80800064_bskazstilt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080006C: jal         0x8009EF1C
    // 0x80800070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800074: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800078: jal         0x8009EF10
    // 0x8080007C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x8080007C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800080: bne         $v0, $zero, L_8080009C
    if (ctx->r2 != 0) {
        // 0x80800084: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8080009C;
    }
    // 0x80800084: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800088: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080008C: jal         0x8009B9B0
    // 0x80800090: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800090: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800094: b           L_808000BC
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000BC;
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080009C:
    // 0x8080009C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808000A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000A4: jal         0x800F1214
    // 0x808000A8: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x808000A8: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    after_3:
    // 0x808000AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000B0: jal         0x8009B9B0
    // 0x808000B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x808000B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000BC:
    // 0x808000BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C0: jr          $ra
    // 0x808000C4: nop

    return;
    // 0x808000C4: nop

;}
RECOMP_FUNC void func_800FAD68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAD68: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800FAD6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FAD70: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800FAD74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800FAD78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FAD7C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800FAD80: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800FAD84: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800FAD88: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800FAD8C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x800FAD90: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800FAD94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FAD98: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800FAD9C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800FADA0: jal         0x800EFA4C
    // 0x800FADA4: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800FADA4: nop

    after_0:
    // 0x800FADA8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800FADAC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800FADB0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800FADB4: jal         0x800C6C94
    // 0x800FADB8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    func_800C6C94(rdram, ctx);
        goto after_1;
    // 0x800FADB8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x800FADBC: beq         $v0, $zero, L_800FAE30
    if (ctx->r2 == 0) {
        // 0x800FADC0: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800FAE30;
    }
    // 0x800FADC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FADC4: lwc1        $f0, 0x6140($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6140);
    // 0x800FADC8: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800FADCC: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800FADD0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800FADD4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800FADD8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800FADDC: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800FADE0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x800FADE4: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FADE8: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800FADEC: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800FADF0: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x800FADF4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800FADF8: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FADFC: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800FAE00: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800FAE04: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800FAE08: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800FAE0C: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800FAE10: beql        $t6, $zero, L_800FAE34
    if (ctx->r14 == 0) {
        // 0x800FAE14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800FAE34;
    }
    goto skip_0;
    // 0x800FAE14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800FAE18: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800FAE1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FAE20: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800FAE24: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800FAE28: jal         0x800FACA0
    // 0x800FAE2C: nop

    func_800FACA0(rdram, ctx);
        goto after_2;
    // 0x800FAE2C: nop

    after_2:
L_800FAE30:
    // 0x800FAE30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FAE34:
    // 0x800FAE34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FAE38: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800FAE3C: jr          $ra
    // 0x800FAE40: nop

    return;
    // 0x800FAE40: nop

;}
RECOMP_FUNC void func_80800054_chwaterfallgrillswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800060: jal         0x80085808
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080006C: jal         0x80085810
    // 0x80800070: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800070: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_1:
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void _ncbadive_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892B0: syscall     770
    recomp_syscall_handler(rdram, ctx, 0x800892B0);
    return;
    // 0x800892B4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800838_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800838: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080083C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800840: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800844: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800848: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080084C: beq         $t7, $at, L_808008A0
    if (ctx->r15 == ctx->r1) {
        // 0x80800850: nop
    
            goto L_808008A0;
    }
    // 0x80800850: nop

    // 0x80800854: jal         0x800D8FF8
    // 0x80800858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080085C: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x80800860: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800868: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8080086C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800870: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
    // 0x80800874: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800878: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080087C: lwc1        $f10, 0x4C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x80800880: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1624, 0XB18) << 16);
    // 0x80800884: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80800888: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080088C: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x80800890: swc1        $f18, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f18.u32l;
    // 0x80800894: lwc1        $f4, 0xB18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1624, 0XB18));
    // 0x80800898: b           L_808008D4
    // 0x8080089C: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
        goto L_808008D4;
    // 0x8080089C: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_808008A0:
    // 0x808008A0: jal         0x800D8FF8
    // 0x808008A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808008A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808008A8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x808008AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008B0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808008B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008B8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808008BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808008C0: lui         $at, 0xC425
    ctx->r1 = S32(0XC425 << 16);
    // 0x808008C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808008C8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x808008CC: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x808008D0: swc1        $f8, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f8.u32l;
L_808008D4:
    // 0x808008D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1624, 0XB1C) << 16);
    // 0x808008D8: lwc1        $f18, 0xB1C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1624, 0XB1C));
    // 0x808008DC: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x808008E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008E8: jr          $ra
    // 0x808008EC: nop

    return;
    // 0x808008EC: nop

;}
RECOMP_FUNC void func_8008ED70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ED70: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8008ED74: jr          $ra
    // 0x8008ED78: addiu       $v0, $v0, 0x7CAC
    ctx->r2 = ADD32(ctx->r2, 0X7CAC);
    return;
    // 0x8008ED78: addiu       $v0, $v0, 0x7CAC
    ctx->r2 = ADD32(ctx->r2, 0X7CAC);
    // 0x8008ED7C: nop

;}
RECOMP_FUNC void baeggcursor_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080015C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800160: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80800164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800168: jal         0x8080018C
    // 0x8080016C: sb          $zero, 0x9($t6)
    MEM_B(0X9, ctx->r14) = 0;
    baeggcursor_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080016C: sb          $zero, 0x9($t6)
    MEM_B(0X9, ctx->r14) = 0;
    after_0:
    // 0x80800170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void _chfantasyonion_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876C8: syscall     607
    recomp_syscall_handler(rdram, ctx, 0x800876C8);
    return;
    // 0x800876CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801580_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801580: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801588: lb          $t6, 0x3($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3);
    // 0x8080158C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801590: addiu       $a1, $a3, 0x22
    ctx->r5 = ADD32(ctx->r7, 0X22);
    // 0x80801594: bne         $t6, $zero, L_808015AC
    if (ctx->r14 != 0) {
        // 0x80801598: nop
    
            goto L_808015AC;
    }
    // 0x80801598: nop

    // 0x8080159C: lb          $t7, 0x7($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X7);
    // 0x808015A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808015A4: beq         $t7, $zero, L_808015B4
    if (ctx->r15 == 0) {
        // 0x808015A8: nop
    
            goto L_808015B4;
    }
    // 0x808015A8: nop

L_808015AC:
    // 0x808015AC: b           L_808015B4
    // 0x808015B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_808015B4;
    // 0x808015B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_808015B4:
    // 0x808015B4: addiu       $a0, $a3, 0x28
    ctx->r4 = ADD32(ctx->r7, 0X28);
    // 0x808015B8: jal         0x80801248
    // 0x808015BC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80801248_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x808015BC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x808015C0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808015C4: addiu       $a0, $a3, 0x24
    ctx->r4 = ADD32(ctx->r7, 0X24);
    // 0x808015C8: addiu       $a1, $a3, 0x20
    ctx->r5 = ADD32(ctx->r7, 0X20);
    // 0x808015CC: jal         0x80801248
    // 0x808015D0: lbu         $a2, 0x1E($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X1E);
    func_80801248_gcnewpause(rdram, ctx);
        goto after_1;
    // 0x808015D0: lbu         $a2, 0x1E($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X1E);
    after_1:
    // 0x808015D4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808015D8: addiu       $a0, $a3, 0x26
    ctx->r4 = ADD32(ctx->r7, 0X26);
    // 0x808015DC: addiu       $a1, $a3, 0x21
    ctx->r5 = ADD32(ctx->r7, 0X21);
    // 0x808015E0: jal         0x80801248
    // 0x808015E4: lbu         $a2, 0x1F($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X1F);
    func_80801248_gcnewpause(rdram, ctx);
        goto after_2;
    // 0x808015E4: lbu         $a2, 0x1F($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X1F);
    after_2:
    // 0x808015E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808015EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808015F0: jr          $ra
    // 0x808015F4: nop

    return;
    // 0x808015F4: nop

;}
RECOMP_FUNC void func_80013B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013B70: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80013B74: j           L_80013B90
    // 0x80013B78: nop

    func_80013B90(rdram, ctx);
    return;
    // 0x80013B78: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800DB4: jal         0x80800C9C
    // 0x80800DB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800C9C_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800DB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800DBC: bne         $v0, $zero, L_80800DCC
    if (ctx->r2 != 0) {
        // 0x80800DC0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800DCC;
    }
    // 0x80800DC0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DC4: b           L_80800DF4
    // 0x80800DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800DF4;
    // 0x80800DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DCC:
    // 0x80800DCC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800DD0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800DD4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800DD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800DDC: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80800DE0: beql        $t8, $zero, L_80800DF4
    if (ctx->r24 == 0) {
        // 0x80800DE4: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_80800DF4;
    }
    goto skip_0;
    // 0x80800DE4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_0:
    // 0x80800DE8: b           L_80800DF4
    // 0x80800DEC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_80800DF4;
    // 0x80800DEC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80800DF0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80800DF4:
    // 0x80800DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DFC: jr          $ra
    // 0x80800E00: nop

    return;
    // 0x80800E00: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5A8: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5A8);
    return;
    // 0x8008A5AC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chdiggerbossshell_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1492, 0X5A8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x5A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1492, 0X5A8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x5A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1492, 0X5A8));
;}
RECOMP_FUNC void func_80804C90_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804C98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80804C9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80804CA0: jal         0x800E24D8
    // 0x80804CA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E24D8(rdram, ctx);
        goto after_0;
    // 0x80804CA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80804CA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804CAC: jal         0x80089C10
    // 0x80804CB0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddiedraw25d_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80804CB0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80804CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804CBC: jr          $ra
    // 0x80804CC0: nop

    return;
    // 0x80804CC0: nop

;}
RECOMP_FUNC void func_8002D450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D450: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002D454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D458: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8002D45C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8002D460: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8002D464: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8002D468: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8002D46C: addiu       $t7, $zero, 0x170
    ctx->r15 = ADD32(0, 0X170);
    // 0x8002D470: sh          $t7, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r15;
    // 0x8002D474: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8002D478: lw          $t9, 0x48($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X48);
    // 0x8002D47C: beq         $t9, $zero, L_8002D4F0
    if (ctx->r25 == 0) {
        // 0x8002D480: nop
    
            goto L_8002D4F0;
    }
    // 0x8002D480: nop

    // 0x8002D484: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8002D488: addiu       $a1, $sp, 0x32
    ctx->r5 = ADD32(ctx->r29, 0X32);
    // 0x8002D48C: addiu       $a2, $zero, 0xB8
    ctx->r6 = ADD32(0, 0XB8);
    // 0x8002D490: jal         0x8002C5F8
    // 0x8002D494: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_8002C5F8(rdram, ctx);
        goto after_0;
    // 0x8002D494: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x8002D498: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8002D49C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8002D4A0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002D4A4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8002D4A8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8002D4AC: lh          $t2, 0x32($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X32);
    // 0x8002D4B0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002D4B4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002D4B8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8002D4BC: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8002D4C0: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x8002D4C4: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8002D4C8: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8002D4CC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8002D4D0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002D4D4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8002D4D8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002D4DC: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002D4E0: ori         $t0, $t9, 0x170
    ctx->r8 = ctx->r25 | 0X170;
    // 0x8002D4E4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8002D4E8: b           L_8002D674
    // 0x8002D4EC: nop

        goto L_8002D674;
    // 0x8002D4EC: nop

L_8002D4F0:
    // 0x8002D4F0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8002D4F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002D4F8: ldc1        $f8, 0x1DB0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1DB0);
    // 0x8002D4FC: lwc1        $f4, 0x44($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X44);
    // 0x8002D500: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002D504: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8002D508: nop

    // 0x8002D50C: bc1f        L_8002D524
    if (!c1cs) {
        // 0x8002D510: nop
    
            goto L_8002D524;
    }
    // 0x8002D510: nop

    // 0x8002D514: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002D518: lwc1        $f10, 0x1DB8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1DB8);
    // 0x8002D51C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8002D520: swc1        $f10, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f10.u32l;
L_8002D524:
    // 0x8002D524: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8002D528: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8002D52C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002D530: lwc1        $f16, 0x44($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X44);
    // 0x8002D534: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8002D538: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002D53C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002D540: nop

    // 0x8002D544: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8002D548: nop

    // 0x8002D54C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002D550: swc1        $f10, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f10.u32l;
    // 0x8002D554: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8002D558: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8002D55C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002D560: lwc1        $f16, 0x44($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X44);
    // 0x8002D564: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8002D568: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
    // 0x8002D56C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8002D570: lui         $at, 0x4338
    ctx->r1 = S32(0X4338 << 16);
    // 0x8002D574: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002D578: lwc1        $f6, 0x44($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X44);
    // 0x8002D57C: lwc1        $f16, 0x4C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4C);
    // 0x8002D580: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002D584: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8002D588: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8002D58C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002D590: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002D594: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8002D598: nop

    // 0x8002D59C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8002D5A0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D5A4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002D5A8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8002D5AC: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8002D5B0: nop

    // 0x8002D5B4: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002D5B8: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8002D5BC: swc1        $f18, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->f18.u32l;
    // 0x8002D5C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8002D5C4: addiu       $a1, $sp, 0x32
    ctx->r5 = ADD32(ctx->r29, 0X32);
    // 0x8002D5C8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D5CC: jal         0x8002C5F8
    // 0x8002D5D0: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_8002C5F8(rdram, ctx);
        goto after_1;
    // 0x8002D5D0: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x8002D5D4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8002D5D8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8002D5DC: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8002D5E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002D5E4: lwc1        $f4, 0x44($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X44);
    // 0x8002D5E8: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002D5EC: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8002D5F0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8002D5F4: nop

    // 0x8002D5F8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8002D5FC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8002D600: addiu       $t7, $t4, 0x8
    ctx->r15 = ADD32(ctx->r12, 0X8);
    // 0x8002D604: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8002D608: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8002D60C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8002D610: jal         0x8002E330
    // 0x8002D614: lw          $a0, 0x40($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X40);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x8002D614: lw          $a0, 0x40($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X40);
    after_2:
    // 0x8002D618: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002D61C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002D620: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D624: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x8002D628: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8002D62C: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x8002D630: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8002D634: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8002D638: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8002D63C: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    // 0x8002D640: lw          $t3, 0x50($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X50);
    // 0x8002D644: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x8002D648: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x8002D64C: andi        $t5, $t3, 0x3
    ctx->r13 = ctx->r11 & 0X3;
    // 0x8002D650: sll         $t6, $t5, 30
    ctx->r14 = S32(ctx->r13 << 30);
    // 0x8002D654: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D658: andi        $t1, $t0, 0xFFF
    ctx->r9 = ctx->r8 & 0XFFF;
    // 0x8002D65C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8002D660: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8002D664: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x8002D668: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x8002D66C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8002D670: sw          $zero, 0x50($t4)
    MEM_W(0X50, ctx->r12) = 0;
L_8002D674:
    // 0x8002D674: b           L_8002D684
    // 0x8002D678: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
        goto L_8002D684;
    // 0x8002D678: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8002D67C: b           L_8002D684
    // 0x8002D680: nop

        goto L_8002D684;
    // 0x8002D680: nop

L_8002D684:
    // 0x8002D684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D688: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8002D68C: jr          $ra
    // 0x8002D690: nop

    return;
    // 0x8002D690: nop

;}
RECOMP_FUNC void chtrashcompactor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1128, 0X960) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x960
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1128, 0X960));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x960
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1128, 0X960));
;}
RECOMP_FUNC void func_808008EC_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008EC: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x808008F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008F4: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x808008F8: beq         $t6, $zero, L_80800918
    if (ctx->r14 == 0) {
        // 0x808008FC: nop
    
            goto L_80800918;
    }
    // 0x808008FC: nop

    // 0x80800900: beq         $t6, $at, L_80800920
    if (ctx->r14 == ctx->r1) {
        // 0x80800904: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800920;
    }
    // 0x80800904: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800908: beq         $t6, $at, L_80800928
    if (ctx->r14 == ctx->r1) {
        // 0x8080090C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800928;
    }
    // 0x8080090C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800910: b           L_80800930
    // 0x80800914: nop

        goto L_80800930;
    // 0x80800914: nop

L_80800918:
    // 0x80800918: jr          $ra
    // 0x8080091C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    return;
    // 0x8080091C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_80800920:
    // 0x80800920: jr          $ra
    // 0x80800924: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    return;
    // 0x80800924: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_80800928:
    // 0x80800928: jr          $ra
    // 0x8080092C: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    return;
    // 0x8080092C: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
L_80800930:
    // 0x80800930: jr          $ra
    // 0x80800934: nop

    return;
    // 0x80800934: nop

;}
RECOMP_FUNC void func_808011A8_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011B0: jal         0x800839B8
    // 0x808011B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808011B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011B8: jal         0x80800448
    // 0x808011BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstrexsmall_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808011BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808011C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011C8: jr          $ra
    // 0x808011CC: nop

    return;
    // 0x808011CC: nop

;}
RECOMP_FUNC void func_80803AB0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803AB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803AB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803AB8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80803ABC: jal         0x80088380
    // 0x80803AC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80803AC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80803AC4: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80803AC8: beq         $v0, $s1, L_80803B28
    if (ctx->r2 == ctx->r17) {
        // 0x80803ACC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80803B28;
    }
    // 0x80803ACC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80803AD0: beq         $v0, $at, L_80803AEC
    if (ctx->r2 == ctx->r1) {
        // 0x80803AD4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80803AEC;
    }
    // 0x80803AD4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80803AD8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80803ADC: beql        $v0, $at, L_80803B2C
    if (ctx->r2 == ctx->r1) {
        // 0x80803AE0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803B2C;
    }
    goto skip_0;
    // 0x80803AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80803AE4: b           L_80803B20
    // 0x80803AE8: nop

        goto L_80803B20;
    // 0x80803AE8: nop

L_80803AEC:
    // 0x80803AEC: jal         0x80088388
    // 0x80803AF0: nop

    _gcstatusDll_entrypoint_15(rdram, ctx);
        goto after_1;
    // 0x80803AF0: nop

    after_1:
    // 0x80803AF4: bne         $v0, $s0, L_80803B04
    if (ctx->r2 != ctx->r16) {
        // 0x80803AF8: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80803B04;
    }
    // 0x80803AF8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80803AFC: b           L_80803B04
    // 0x80803B00: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_80803B04;
    // 0x80803B00: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80803B04:
    // 0x80803B04: jal         0x80088340
    // 0x80803B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcstatusDll_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80803B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80803B0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80803B10: bne         $s0, $s1, L_80803AEC
    if (ctx->r16 != ctx->r17) {
        // 0x80803B14: nop
    
            goto L_80803AEC;
    }
    // 0x80803B14: nop

    // 0x80803B18: b           L_80803B2C
    // 0x80803B1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803B2C;
    // 0x80803B1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803B20:
    // 0x80803B20: jal         0x80803940
    // 0x80803B24: nop

    func_80803940_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80803B24: nop

    after_3:
L_80803B28:
    // 0x80803B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803B2C:
    // 0x80803B2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80803B30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80803B34: jr          $ra
    // 0x80803B38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80803B38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chclockworkmouse_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086950: syscall     398
    recomp_syscall_handler(rdram, ctx, 0x80086950);
    return;
    // 0x80086954: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
