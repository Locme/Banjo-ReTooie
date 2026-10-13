#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80803A58_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803A58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803A60: jal         0x80088330
    // 0x80803A64: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    _gcstatusDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80803A64: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80803A68: jal         0x80803940
    // 0x80803A6C: nop

    func_80803940_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80803A6C: nop

    after_1:
    // 0x80803A70: jal         0x80803988
    // 0x80803A74: nop

    func_80803988_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80803A74: nop

    after_2:
    // 0x80803A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803A7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803A80: jr          $ra
    // 0x80803A84: nop

    return;
    // 0x80803A84: nop

;}
RECOMP_FUNC void func_800DBB64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBB64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DBB68: lw          $a0, -0x3820($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3820);
    // 0x800DBB6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DBB70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBB74: beql        $a0, $zero, L_800DBB90
    if (ctx->r4 == 0) {
        // 0x800DBB78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DBB90;
    }
    goto skip_0;
    // 0x800DBB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800DBB7C: jal         0x800B32E4
    // 0x800DBB80: nop

    freelist_defrag(rdram, ctx);
        goto after_0;
    // 0x800DBB80: nop

    after_0:
    // 0x800DBB84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DBB88: sw          $v0, -0x3820($at)
    MEM_W(-0X3820, ctx->r1) = ctx->r2;
    // 0x800DBB8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DBB90:
    // 0x800DBB90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DBB94: jr          $ra
    // 0x800DBB98: nop

    return;
    // 0x800DBB98: nop

;}
RECOMP_FUNC void func_8009E988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E988: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E98C: jr          $ra
    // 0x8009E990: lwc1        $f0, 0x7044($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7044);
    return;
    // 0x8009E990: lwc1        $f0, 0x7044($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7044);
;}
RECOMP_FUNC void func_80800D44_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D4C: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800D50: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800D54: bgezl       $t8, L_80800D78
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800D58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800D78;
    }
    goto skip_0;
    // 0x80800D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800D5C: jal         0x80085710
    // 0x80800D60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800D60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D68: lbu         $t9, 0x65($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X65);
    // 0x80800D6C: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800D70: sb          $t0, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r8;
    // 0x80800D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D78:
    // 0x80800D78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D7C: jr          $ra
    // 0x80800D80: nop

    return;
    // 0x80800D80: nop

;}
RECOMP_FUNC void _bswasher_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843D8: syscall     109
    recomp_syscall_handler(rdram, ctx, 0x800843D8);
    return;
    // 0x800843DC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800000_chfoodwarn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800008: addiu       $a0, $a1, 0x521
    ctx->r4 = ADD32(ctx->r5, 0X521);
    // 0x8080000C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800018: jal         0x80088280
    // 0x8080001C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800024: jal         0x80088C00
    // 0x80800028: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800028: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_80801300_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801300: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801308: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080130C: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80801310: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801314: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1554) << 16);
    // 0x80801318: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8080131C: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80801320: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801324: lwc1        $f14, 0x1554($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1554));
    // 0x80801328: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8080132C: lwc1        $f8, 0x30($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80801330: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80801334: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80801338: jal         0x800DC178
    // 0x8080133C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8080133C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80801340: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80801344: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80801348: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x8080134C: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80801350: addiu       $t9, $t8, -0x2A7
    ctx->r25 = ADD32(ctx->r24, -0X2A7);
    // 0x80801354: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x80801358: beq         $at, $zero, L_808013E4
    if (ctx->r1 == 0) {
        // 0x8080135C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808013E4;
    }
    // 0x8080135C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80801360: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1558) << 16);
    // 0x80801364: addu        $at, $at, $t9
    gpr jr_addend_8080136C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80801368: lw          $t9, 0x1558($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1558));
    // 0x8080136C: jr          $t9
    // 0x80801370: nop

    switch (jr_addend_8080136C >> 2) {
        case 0: goto L_80801374; break;
        case 1: goto L_80801384; break;
        case 2: goto L_80801398; break;
        case 3: goto L_808013AC; break;
        case 4: goto L_808013C0; break;
        case 5: goto L_808013D4; break;
        default: switch_error(__func__, 0x8080136C, 0x80801558);
    }
    // 0x80801370: nop

L_80801374:
    // 0x80801374: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x80801378: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x8080137C: b           L_808013E4
    // 0x80801380: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
        goto L_808013E4;
    // 0x80801380: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
L_80801384:
    // 0x80801384: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x80801388: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x8080138C: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80801390: b           L_808013E4
    // 0x80801394: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
        goto L_808013E4;
    // 0x80801394: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
L_80801398:
    // 0x80801398: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080139C: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x808013A0: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x808013A4: b           L_808013E4
    // 0x808013A8: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
        goto L_808013E4;
    // 0x808013A8: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
L_808013AC:
    // 0x808013AC: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808013B0: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808013B4: ori         $t0, $t9, 0x3
    ctx->r8 = ctx->r25 | 0X3;
    // 0x808013B8: b           L_808013E4
    // 0x808013BC: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
        goto L_808013E4;
    // 0x808013BC: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
L_808013C0:
    // 0x808013C0: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x808013C4: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x808013C8: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x808013CC: b           L_808013E4
    // 0x808013D0: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
        goto L_808013E4;
    // 0x808013D0: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
L_808013D4:
    // 0x808013D4: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    // 0x808013D8: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x808013DC: ori         $t6, $t5, 0x5
    ctx->r14 = ctx->r13 | 0X5;
    // 0x808013E0: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
L_808013E4:
    // 0x808013E4: jal         0x8080105C
    // 0x808013E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080105C_chfiregen(rdram, ctx);
        goto after_1;
    // 0x808013E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808013EC: beq         $v0, $zero, L_80801404
    if (ctx->r2 == 0) {
        // 0x808013F0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801404;
    }
    // 0x808013F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808013F4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808013F8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808013FC: jal         0x800EDDDC
    // 0x80801400: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    func_800EDDDC(rdram, ctx);
        goto after_2;
    // 0x80801400: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_2:
L_80801404:
    // 0x80801404: jal         0x808010B4
    // 0x80801408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808010B4_chfiregen(rdram, ctx);
        goto after_3;
    // 0x80801408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080140C: beq         $v0, $zero, L_80801424
    if (ctx->r2 == 0) {
        // 0x80801410: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801424;
    }
    // 0x80801410: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801414: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80801418: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080141C: jal         0x800EDDDC
    // 0x80801420: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    func_800EDDDC(rdram, ctx);
        goto after_4;
    // 0x80801420: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_4:
L_80801424:
    // 0x80801424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801428: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080142C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801430: jr          $ra
    // 0x80801434: nop

    return;
    // 0x80801434: nop

    // 0x80801438: nop

    // 0x8080143C: nop

;}
RECOMP_FUNC void batimer_isLessThan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: lw          $t6, 0x13C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X13C);
    // 0x80800210: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800214: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800218: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8080021C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80800220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800224: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80800228: nop

    // 0x8080022C: bc1f        L_80800238
    if (!c1cs) {
        // 0x80800230: nop
    
            goto L_80800238;
    }
    // 0x80800230: nop

    // 0x80800234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800238:
    // 0x80800238: jr          $ra
    // 0x8080023C: nop

    return;
    // 0x8080023C: nop

;}
RECOMP_FUNC void fxegg_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800504: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800508: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080050C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800510: jal         0x800B5BE4
    // 0x80800514: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800514: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x80800518: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080051C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800520: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800524: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800528: addiu       $a3, $zero, 0x9E5
    ctx->r7 = ADD32(0, 0X9E5);
    // 0x8080052C: jal         0x80800410
    // 0x80800530: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80800410_fxegg(rdram, ctx);
        goto after_1;
    // 0x80800530: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800534: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080053C: jr          $ra
    // 0x80800540: nop

    return;
    // 0x80800540: nop

    // 0x80800544: nop

    // 0x80800548: nop

    // 0x8080054C: nop

;}
RECOMP_FUNC void func_808000A8_chstonedartgunhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808000B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B8: addiu       $a0, $zero, 0x123
    ctx->r4 = ADD32(0, 0X123);
    // 0x808000BC: jal         0x801084B0
    // 0x808000C0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x808000C0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x808000C4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808000C8: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x808000CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000D0: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x808000D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808000D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808000DC: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    // 0x808000E0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x808000E4: lui         $at, 0x42D0
    ctx->r1 = S32(0X42D0 << 16);
    // 0x808000E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000EC: lwc1        $f6, 0x28($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X28);
    // 0x808000F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000F4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808000F8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808000FC: nop

    // 0x80800100: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800104: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800108: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x8080010C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80800110: lwc1        $f6, 0x38($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X38);
    // 0x80800114: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800118: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8080011C: jal         0x8010D254
    // 0x80800120: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x80800120: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    after_1:
    // 0x80800124: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800128: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080012C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800130: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800134: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800138: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8080013C: jal         0x800F1828
    // 0x80800140: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    func_800F1828(rdram, ctx);
        goto after_2;
    // 0x80800140: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80800144: jal         0x80013728
    // 0x80800148: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_3;
    // 0x80800148: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x8080014C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800150: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800154: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800158: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8080015C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800160: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1872, 0XE78) << 16);
    // 0x80800164: bc1fl       L_80800178
    if (!c1cs) {
        // 0x80800168: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80800178;
    }
    goto skip_0;
    // 0x80800168: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8080016C: b           L_80800190
    // 0x80800170: swc1        $f2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f2.u32l;
        goto L_80800190;
    // 0x80800170: swc1        $f2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f2.u32l;
    // 0x80800174: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80800178:
    // 0x80800178: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8080017C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800180: nop

    // 0x80800184: bc1fl       L_80800194
    if (!c1cs) {
        // 0x80800188: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800194;
    }
    goto skip_1;
    // 0x80800188: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x8080018C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
L_80800190:
    // 0x80800190: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80800194:
    // 0x80800194: addiu       $a2, $a2, 0xE78
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1872, 0XE78));
    // 0x80800198: jal         0x80089D18
    // 0x8080019C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x8080019C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void func_80800E04_chwumbawigwam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E04: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800E08: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800E0C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80800E10: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800E14: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800E18: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800E1C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800E20: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800E24: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800E28: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800E2C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800E30: jal         0x80100094
    // 0x80800E34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800E38: beq         $v0, $zero, L_80800E54
    if (ctx->r2 == 0) {
        // 0x80800E3C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800E54;
    }
    // 0x80800E3C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800E40: jal         0x80100094
    // 0x80800E44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800E44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800E48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E4C: jal         0x80089888
    // 0x80800E50: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    _sumumbofx_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800E50: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
L_80800E54:
    // 0x80800E54: lhu         $v0, 0x72($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X72);
    // 0x80800E58: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800E5C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80800E60: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800E64: beq         $t6, $at, L_80800E74
    if (ctx->r14 == ctx->r1) {
        // 0x80800E68: lui         $s0, 0x8080
        ctx->r16 = S32(RELOC_HI16(2272, 0X11F0) << 16);
            goto L_80800E74;
    }
    // 0x80800E68: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2272, 0X11F0) << 16);
    // 0x80800E6C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800E70: bne         $t6, $at, L_80800F84
    if (ctx->r14 != ctx->r1) {
        // 0x80800E74: lui         $s3, 0x8080
        ctx->r19 = S32(RELOC_HI16(2272, 0X11E4) << 16);
            goto L_80800F84;
    }
L_80800E74:
    // 0x80800E74: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2272, 0X11E4) << 16);
    // 0x80800E78: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800E7C: addiu       $s3, $s3, 0x11E4
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2272, 0X11E4));
    // 0x80800E80: addiu       $s0, $s0, 0x11F0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2272, 0X11F0));
L_80800E84:
    // 0x80800E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E88: jal         0x800EE7F8
    // 0x80800E8C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800E8C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x80800E90: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800E94: c.eq.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl == ctx->f12.fl;
    // 0x80800E98: nop

    // 0x80800E9C: bc1tl       L_80800F10
    if (c1cs) {
        // 0x80800EA0: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80800F10;
    }
    goto skip_0;
    // 0x80800EA0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x80800EA4: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800EA8: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
    // 0x80800EAC: nop

    // 0x80800EB0: bc1tl       L_80800F10
    if (c1cs) {
        // 0x80800EB4: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80800F10;
    }
    goto skip_1;
    // 0x80800EB4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_1:
    // 0x80800EB8: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800EBC: sll         $t7, $s1, 4
    ctx->r15 = S32(ctx->r17 << 4);
    // 0x80800EC0: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x80800EC4: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x80800EC8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80800ECC: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x80800ED0: bc1tl       L_80800F10
    if (c1cs) {
        // 0x80800ED4: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80800F10;
    }
    goto skip_2;
    // 0x80800ED4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_2:
    // 0x80800ED8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800EDC: jal         0x800DF500
    // 0x80800EE0: subu        $s2, $t8, $t7
    ctx->r18 = SUB32(ctx->r24, ctx->r15);
    func_800DF500(rdram, ctx);
        goto after_4;
    // 0x80800EE0: subu        $s2, $t8, $t7
    ctx->r18 = SUB32(ctx->r24, ctx->r15);
    after_4:
    // 0x80800EE4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800EE8: jal         0x80089C98
    // 0x80800EEC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800EEC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x80800EF0: lbu         $t9, 0x7A($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X7A);
    // 0x80800EF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800EF8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800EFC: andi        $t0, $t9, 0xFF3F
    ctx->r8 = ctx->r25 & 0XFF3F;
    // 0x80800F00: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x80800F04: jal         0x80101870
    // 0x80800F08: sb          $t1, 0x7A($s4)
    MEM_B(0X7A, ctx->r20) = ctx->r9;
    func_80101870(rdram, ctx);
        goto after_6;
    // 0x80800F08: sb          $t1, 0x7A($s4)
    MEM_B(0X7A, ctx->r20) = ctx->r9;
    after_6:
    // 0x80800F0C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80800F10:
    // 0x80800F10: addiu       $s0, $s0, -0xC
    ctx->r16 = ADD32(ctx->r16, -0XC);
    // 0x80800F14: bne         $s1, $zero, L_80800E84
    if (ctx->r17 != 0) {
        // 0x80800F18: addiu       $s3, $s3, -0xC
        ctx->r19 = ADD32(ctx->r19, -0XC);
            goto L_80800E84;
    }
    // 0x80800F18: addiu       $s3, $s3, -0xC
    ctx->r19 = ADD32(ctx->r19, -0XC);
    // 0x80800F1C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2272, 0X11C0) << 16);
    // 0x80800F20: addiu       $a0, $a0, 0x11C0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2272, 0X11C0));
    // 0x80800F24: jal         0x800EE7F8
    // 0x80800F28: addiu       $a1, $s4, 0x28
    ctx->r5 = ADD32(ctx->r20, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800F28: addiu       $a1, $s4, 0x28
    ctx->r5 = ADD32(ctx->r20, 0X28);
    after_7:
    // 0x80800F2C: lwc1        $f12, 0x28($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X28);
    // 0x80800F30: c.eq.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl == ctx->f12.fl;
    // 0x80800F34: nop

    // 0x80800F38: bc1tl       L_80800F78
    if (c1cs) {
        // 0x80800F3C: lbu         $t2, 0x7A($s4)
        ctx->r10 = MEM_BU(ctx->r20, 0X7A);
            goto L_80800F78;
    }
    goto skip_3;
    // 0x80800F3C: lbu         $t2, 0x7A($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X7A);
    skip_3:
    // 0x80800F40: lwc1        $f14, 0x2C($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x80800F44: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
    // 0x80800F48: nop

    // 0x80800F4C: bc1tl       L_80800F78
    if (c1cs) {
        // 0x80800F50: lbu         $t2, 0x7A($s4)
        ctx->r10 = MEM_BU(ctx->r20, 0X7A);
            goto L_80800F78;
    }
    goto skip_4;
    // 0x80800F50: lbu         $t2, 0x7A($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X7A);
    skip_4:
    // 0x80800F54: lwc1        $f0, 0x30($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X30);
    // 0x80800F58: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x80800F5C: nop

    // 0x80800F60: bc1tl       L_80800F78
    if (c1cs) {
        // 0x80800F64: lbu         $t2, 0x7A($s4)
        ctx->r10 = MEM_BU(ctx->r20, 0X7A);
            goto L_80800F78;
    }
    goto skip_5;
    // 0x80800F64: lbu         $t2, 0x7A($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X7A);
    skip_5:
    // 0x80800F68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800F6C: jal         0x800DF500
    // 0x80800F70: nop

    func_800DF500(rdram, ctx);
        goto after_8;
    // 0x80800F70: nop

    after_8:
    // 0x80800F74: lbu         $t2, 0x7A($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X7A);
L_80800F78:
    // 0x80800F78: andi        $t3, $t2, 0xFF3F
    ctx->r11 = ctx->r10 & 0XFF3F;
    // 0x80800F7C: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x80800F80: sb          $t4, 0x7A($s4)
    MEM_B(0X7A, ctx->r20) = ctx->r12;
L_80800F84:
    // 0x80800F84: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800F88: jal         0x80089C98
    // 0x80800F8C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800F8C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_9:
    // 0x80800F90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800F94: jal         0x80101870
    // 0x80800F98: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80101870(rdram, ctx);
        goto after_10;
    // 0x80800F98: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_10:
    // 0x80800F9C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800FA0: jal         0x80100094
    // 0x80800FA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80800FA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800FA8: beq         $v0, $zero, L_80800FC4
    if (ctx->r2 == 0) {
        // 0x80800FAC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800FC4;
    }
    // 0x80800FAC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800FB0: jal         0x80100094
    // 0x80800FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x80800FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800FB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FBC: jal         0x80089880
    // 0x80800FC0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_13;
    // 0x80800FC0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_13:
L_80800FC4:
    // 0x80800FC4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800FC8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800FCC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FD0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800FD4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800FD8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800FDC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800FE0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800FE4: jr          $ra
    // 0x80800FE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800FE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800758_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800758: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080075C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800760: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800764: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x80800768: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x8080076C: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x80800770: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800774: beq         $at, $zero, L_808009EC
    if (ctx->r1 == 0) {
        // 0x80800778: sb          $a1, 0x32($t6)
        MEM_B(0X32, ctx->r14) = ctx->r5;
            goto L_808009EC;
    }
    // 0x80800778: sb          $a1, 0x32($t6)
    MEM_B(0X32, ctx->r14) = ctx->r5;
    // 0x8080077C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800780: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X1184) << 16);
    // 0x80800784: addu        $at, $at, $t7
    gpr jr_addend_8080078C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800788: lw          $t7, 0x1184($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(208, 0X1184));
    // 0x8080078C: jr          $t7
    // 0x80800790: nop

    switch (jr_addend_8080078C >> 2) {
        case 0: goto L_80800794; break;
        case 1: goto L_80800828; break;
        case 2: goto L_8080084C; break;
        case 3: goto L_80800868; break;
        case 4: goto L_80800884; break;
        case 5: goto L_808008E4; break;
        case 6: goto L_80800990; break;
        case 7: goto L_808009AC; break;
        case 8: goto L_808009C4; break;
        default: switch_error(__func__, 0x8080078C, 0x80801184);
    }
    // 0x80800790: nop

L_80800794:
    // 0x80800794: lw          $t9, 0x18C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18C);
    // 0x80800798: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A0: jal         0x8009C150
    // 0x808007A4: sb          $t8, 0x1C($t9)
    MEM_B(0X1C, ctx->r25) = ctx->r24;
    func_8009C150(rdram, ctx);
        goto after_0;
    // 0x808007A4: sb          $t8, 0x1C($t9)
    MEM_B(0X1C, ctx->r25) = ctx->r24;
    after_0:
    // 0x808007A8: lw          $t0, 0x18C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18C);
    // 0x808007AC: lui         $a1, 0x3E8F
    ctx->r5 = S32(0X3E8F << 16);
    // 0x808007B0: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B8: jal         0x808003BC
    // 0x808007BC: swc1        $f0, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f0.u32l;
    func_808003BC_bsdronexform(rdram, ctx);
        goto after_1;
    // 0x808007BC: swc1        $f0, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f0.u32l;
    after_1:
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C4: jal         0x808003CC
    // 0x808007C8: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    func_808003CC_bsdronexform(rdram, ctx);
        goto after_2;
    // 0x808007C8: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    after_2:
    // 0x808007CC: lui         $a1, 0x3D23
    ctx->r5 = S32(0X3D23 << 16);
    // 0x808007D0: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x808007D4: jal         0x808003DC
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003DC_bsdronexform(rdram, ctx);
        goto after_3;
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808007DC: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x808007E0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808007E4: jal         0x80800704
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800704_bsdronexform(rdram, ctx);
        goto after_4;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: jal         0x8009B800
    // 0x808007F4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baphysics_set_type(rdram, ctx);
        goto after_5;
    // 0x808007F4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x808007F8: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x808007FC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800804: jal         0x80085338
    // 0x80800808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_6;
    // 0x80800808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: addiu       $a1, $zero, 0x5D2
    ctx->r5 = ADD32(0, 0X5D2);
    // 0x80800814: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800818: jal         0x8009DF18
    // 0x8080081C: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DF18(rdram, ctx);
        goto after_7;
    // 0x8080081C: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_7:
    // 0x80800820: b           L_808009F0
    // 0x80800824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F0;
    // 0x80800824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800828:
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800830: jal         0x80085338
    // 0x80800834: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _batimer_set(rdram, ctx);
        goto after_8;
    // 0x80800834: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_8:
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080083C: jal         0x8009B800
    // 0x80800840: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    baphysics_set_type(rdram, ctx);
        goto after_9;
    // 0x80800840: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_9:
    // 0x80800844: b           L_808009F0
    // 0x80800848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F0;
    // 0x80800848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080084C:
    // 0x8080084C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80800850: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800858: jal         0x80085338
    // 0x8080085C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_10;
    // 0x8080085C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800860: b           L_808009F0
    // 0x80800864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F0;
    // 0x80800864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800868:
    // 0x80800868: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080086C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: jal         0x80085338
    // 0x80800878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_11;
    // 0x80800878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8080087C: b           L_808009F0
    // 0x80800880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F0;
    // 0x80800880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800884:
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800888: jal         0x8009C128
    // 0x8080088C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_12;
    // 0x8080088C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_12:
    // 0x80800890: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800894: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800898: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808008A4: jal         0x800A4C48
    // 0x808008A8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_800A4C48(rdram, ctx);
        goto after_13;
    // 0x808008A8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x808008AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008B0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808008B4: jal         0x800CA3F4
    // 0x808008B8: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_800CA3F4(rdram, ctx);
        goto after_14;
    // 0x808008B8: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_14:
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C0: jal         0x808003EC
    // 0x808008C4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_808003EC_bsdronexform(rdram, ctx);
        goto after_15;
    // 0x808008C4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_15:
    // 0x808008C8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x808008CC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D4: jal         0x80085338
    // 0x808008D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_16;
    // 0x808008D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808008DC: b           L_808009F0
    // 0x808008E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F0;
    // 0x808008E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008E4:
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E8: jal         0x8009C128
    // 0x808008EC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_17;
    // 0x808008EC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_17:
    // 0x808008F0: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x808008F4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808008F8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808008FC: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800900: jal         0x800E1610
    // 0x80800904: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    func_800E1610(rdram, ctx);
        goto after_18;
    // 0x80800904: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_18:
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080090C: addiu       $a1, $zero, 0x490
    ctx->r5 = ADD32(0, 0X490);
    // 0x80800910: jal         0x8009DE38
    // 0x80800914: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_19;
    // 0x80800914: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_19:
    // 0x80800918: jal         0x800A3274
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_20;
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800920: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800924: jal         0x800A33F8
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A33F8(rdram, ctx);
        goto after_21;
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080092C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800930: jal         0x800D5034
    // 0x80800934: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800D5034(rdram, ctx);
        goto after_22;
    // 0x80800934: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_22:
    // 0x80800938: jal         0x800A33F8
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A33F8(rdram, ctx);
        goto after_23;
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800944: jal         0x800A3410
    // 0x80800948: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A3410(rdram, ctx);
        goto after_24;
    // 0x80800948: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_24:
    // 0x8080094C: jal         0x80092778
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092778(rdram, ctx);
        goto after_25;
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800958: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8080095C: jal         0x80084668
    // 0x80800960: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    _badata_entrypoint_5(rdram, ctx);
        goto after_26;
    // 0x80800960: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_26:
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800968: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8080096C: jal         0x8008CB3C
    // 0x80800970: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_27;
    // 0x80800970: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_27:
    // 0x80800974: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800978: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800980: jal         0x80085338
    // 0x80800984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_28;
    // 0x80800984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x80800988: b           L_808009F0
    // 0x8080098C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F0;
    // 0x8080098C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800990:
    // 0x80800990: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800994: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080099C: jal         0x80085338
    // 0x808009A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_29;
    // 0x808009A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x808009A4: b           L_808009F0
    // 0x808009A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F0;
    // 0x808009A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009AC:
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808009B4: jal         0x80085338
    // 0x808009B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _batimer_set(rdram, ctx);
        goto after_30;
    // 0x808009B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_30:
    // 0x808009BC: b           L_808009F0
    // 0x808009C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F0;
    // 0x808009C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009C4:
    // 0x808009C4: lw          $t1, 0x18C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18C);
    // 0x808009C8: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808009CC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808009D8: jal         0x80085338
    // 0x808009DC: sb          $zero, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = 0;
    _batimer_set(rdram, ctx);
        goto after_31;
    // 0x808009DC: sb          $zero, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = 0;
    after_31:
    // 0x808009E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E4: jal         0x8009B800
    // 0x808009E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baphysics_set_type(rdram, ctx);
        goto after_32;
    // 0x808009E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_32:
L_808009EC:
    // 0x808009EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009F0:
    // 0x808009F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808009F8: jr          $ra
    // 0x808009FC: nop

    return;
    // 0x808009FC: nop

;}
RECOMP_FUNC void func_800C91C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C91C8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C91CC: lbu         $v1, -0x54AC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X54AC);
    // 0x800C91D0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C91D4: addiu       $a1, $a1, -0x54C0
    ctx->r5 = ADD32(ctx->r5, -0X54C0);
    // 0x800C91D8: blez        $v1, L_800C9208
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C91DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C9208;
    }
    // 0x800C91DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C91E0:
    // 0x800C91E0: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x800C91E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C91E8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C91EC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C91F0: bne         $a0, $t6, L_800C9200
    if (ctx->r4 != ctx->r14) {
        // 0x800C91F4: nop
    
            goto L_800C9200;
    }
    // 0x800C91F4: nop

    // 0x800C91F8: jr          $ra
    // 0x800C91FC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x800C91FC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800C9200:
    // 0x800C9200: bne         $at, $zero, L_800C91E0
    if (ctx->r1 != 0) {
        // 0x800C9204: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800C91E0;
    }
    // 0x800C9204: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_800C9208:
    // 0x800C9208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C920C: jr          $ra
    // 0x800C9210: nop

    return;
    // 0x800C9210: nop

;}
RECOMP_FUNC void func_800F0AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0AA4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F0AA8: lwc1        $f14, 0x8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800F0AAC: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F0AB0: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F0AB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F0AB8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800F0ABC: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F0AC0: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800F0AC4: sub.s       $f0, $f14, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800F0AC8: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800F0ACC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800F0AD0: sub.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800F0AD4: mul.s       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x800F0AD8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800F0ADC: swc1        $f6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f6.u32l;
    // 0x800F0AE0: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F0AE4: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F0AE8: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F0AEC: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800F0AF0: nop

    // 0x800F0AF4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F0AF8: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800F0AFC: add.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800F0B00: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800F0B04: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800F0B08: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x800F0B0C: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800F0B10: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F0B14: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800F0B18: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800F0B1C: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F0B20: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800F0B24: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800F0B28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800F0B2C: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800F0B30: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800F0B34: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800F0B38: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800F0B3C: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F0B40: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F0B44: bc1f        L_800F0B54
    if (!c1cs) {
        // 0x800F0B48: nop
    
            goto L_800F0B54;
    }
    // 0x800F0B48: nop

    // 0x800F0B4C: b           L_800F0BC8
    // 0x800F0B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0BC8;
    // 0x800F0B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F0B54:
    // 0x800F0B54: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F0B58: sub.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800F0B5C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F0B60: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800F0B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0B68: sub.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800F0B6C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800F0B70: nop

    // 0x800F0B74: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800F0B78: nop

    // 0x800F0B7C: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800F0B80: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800F0B84: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800F0B88: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800F0B8C: lwc1        $f8, 0x14($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F0B90: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800F0B94: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800F0B98: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x800F0B9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0BA0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800F0BA4: add.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800F0BA8: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800F0BAC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800F0BB0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800F0BB4: nop

    // 0x800F0BB8: bc1f        L_800F0BC8
    if (!c1cs) {
        // 0x800F0BBC: nop
    
            goto L_800F0BC8;
    }
    // 0x800F0BBC: nop

    // 0x800F0BC0: b           L_800F0BC8
    // 0x800F0BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0BC8;
    // 0x800F0BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F0BC8:
    // 0x800F0BC8: jr          $ra
    // 0x800F0BCC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800F0BCC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80801B98_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B98: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x80801B9C: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80801BA0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80801BA4: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80801BA8: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80801BAC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80801BB0: addiu       $s0, $a0, 0x148
    ctx->r16 = ADD32(ctx->r4, 0X148);
    // 0x80801BB4: addiu       $s1, $s5, 0x58
    ctx->r17 = ADD32(ctx->r21, 0X58);
    // 0x80801BB8: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x80801BBC: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80801BC0: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80801BC4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80801BC8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801BCC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801BD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801BD4: jal         0x800F1DF4
    // 0x80801BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_0;
    // 0x80801BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801BDC: jal         0x800136E4
    // 0x80801BE0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80801BE0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80801BE4: addiu       $s2, $s5, 0xC4
    ctx->r18 = ADD32(ctx->r21, 0XC4);
    // 0x80801BE8: swc1        $f0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f0.u32l;
    // 0x80801BEC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80801BF0: jal         0x800F1DF4
    // 0x80801BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_2;
    // 0x80801BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801BF8: jal         0x800136E4
    // 0x80801BFC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x80801BFC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80801C00: addiu       $s3, $sp, 0x110
    ctx->r19 = ADD32(ctx->r29, 0X110);
    // 0x80801C04: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
    // 0x80801C08: jal         0x8080189C
    // 0x80801C0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8080189C_ncpoddialog(rdram, ctx);
        goto after_4;
    // 0x80801C0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x80801C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801C14: jal         0x800EFB8C
    // 0x80801C18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EFB8C(rdram, ctx);
        goto after_5;
    // 0x80801C18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80801C1C: swc1        $f0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f0.u32l;
    // 0x80801C20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801C24: jal         0x800EFB8C
    // 0x80801C28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EFB8C(rdram, ctx);
        goto after_6;
    // 0x80801C28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80801C2C: addiu       $s4, $sp, 0xE8
    ctx->r20 = ADD32(ctx->r29, 0XE8);
    // 0x80801C30: swc1        $f0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f0.u32l;
    // 0x80801C34: jal         0x80801A30
    // 0x80801C38: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80801A30_ncpoddialog(rdram, ctx);
        goto after_7;
    // 0x80801C38: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_7:
    // 0x80801C3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801C40: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801C44: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80801C48: jal         0x80801AC0
    // 0x80801C4C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80801AC0_ncpoddialog(rdram, ctx);
        goto after_8;
    // 0x80801C4C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_8:
    // 0x80801C50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801C54: jal         0x800EEAD4
    // 0x80801C58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_9;
    // 0x80801C58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80801C5C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801C60: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80801C64: jal         0x800EE7F8
    // 0x80801C68: addiu       $a1, $s5, 0x200
    ctx->r5 = ADD32(ctx->r21, 0X200);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80801C68: addiu       $a1, $s5, 0x200
    ctx->r5 = ADD32(ctx->r21, 0X200);
    after_10:
    // 0x80801C6C: addiu       $s0, $sp, 0xDC
    ctx->r16 = ADD32(ctx->r29, 0XDC);
    // 0x80801C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C74: jal         0x800EE7F8
    // 0x80801C78: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80801C78: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_11:
    // 0x80801C7C: lwc1        $f4, 0x13C($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X13C);
    // 0x80801C80: neg.s       $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = -ctx->f20.fl;
    // 0x80801C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C88: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80801C8C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80801C90: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80801C94: jal         0x800EF214
    // 0x80801C98: lw          $a2, 0x140($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X140);
    func_800EF214(rdram, ctx);
        goto after_12;
    // 0x80801C98: lw          $a2, 0x140($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X140);
    after_12:
    // 0x80801C9C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80801CA0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80801CA4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80801CA8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80801CAC: addiu       $s4, $sp, 0x7C
    ctx->r20 = ADD32(ctx->r29, 0X7C);
    // 0x80801CB0: addiu       $s2, $sp, 0x7C
    ctx->r18 = ADD32(ctx->r29, 0X7C);
L_80801CB4:
    // 0x80801CB4: mtc1        $s3, $f10
    ctx->f10.u32l = ctx->r19;
    // 0x80801CB8: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80801CBC: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x80801CC0: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
L_80801CC4:
    // 0x80801CC4: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80801CC8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80801CCC: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80801CD0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80801CD4: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80801CD8: jal         0x800F10B4
    // 0x80801CDC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_13;
    // 0x80801CDC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x80801CE0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801CE4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80801CE8: bne         $s0, $s2, L_80801CC4
    if (ctx->r16 != ctx->r18) {
        // 0x80801CEC: swc1        $f0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f0.u32l;
            goto L_80801CC4;
    }
    // 0x80801CEC: swc1        $f0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f0.u32l;
    // 0x80801CF0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80801CF4: slti        $at, $s3, 0x9
    ctx->r1 = SIGNED(ctx->r19) < 0X9 ? 1 : 0;
    // 0x80801CF8: bne         $at, $zero, L_80801CB4
    if (ctx->r1 != 0) {
        // 0x80801CFC: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_80801CB4;
    }
    // 0x80801CFC: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80801D00: addiu       $s1, $s5, 0x188
    ctx->r17 = ADD32(ctx->r21, 0X188);
    // 0x80801D04: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80801D08: addiu       $s2, $sp, 0xE8
    ctx->r18 = ADD32(ctx->r29, 0XE8);
L_80801D0C:
    // 0x80801D0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801D10: jal         0x800EE7F8
    // 0x80801D14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_14;
    // 0x80801D14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x80801D18: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80801D1C: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80801D20: bne         $at, $zero, L_80801D0C
    if (ctx->r1 != 0) {
        // 0x80801D24: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80801D0C;
    }
    // 0x80801D24: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80801D28: addiu       $s1, $s5, 0xC
    ctx->r17 = ADD32(ctx->r21, 0XC);
    // 0x80801D2C: addiu       $s2, $s1, 0x58
    ctx->r18 = ADD32(ctx->r17, 0X58);
    // 0x80801D30: addiu       $s0, $sp, 0x7C
    ctx->r16 = ADD32(ctx->r29, 0X7C);
    // 0x80801D34: addiu       $s3, $sp, 0xDC
    ctx->r19 = ADD32(ctx->r29, 0XDC);
L_80801D38:
    // 0x80801D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D3C: jal         0x800F1DF4
    // 0x80801D40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_15;
    // 0x80801D40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_15:
    // 0x80801D44: jal         0x800136E4
    // 0x80801D48: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_16;
    // 0x80801D48: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_16:
    // 0x80801D4C: swc1        $f0, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = ctx->f0.u32l;
    // 0x80801D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D54: jal         0x800F1828
    // 0x80801D58: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800F1828(rdram, ctx);
        goto after_17;
    // 0x80801D58: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_17:
    // 0x80801D5C: jal         0x800136E4
    // 0x80801D60: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_18;
    // 0x80801D60: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_18:
    // 0x80801D64: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80801D68: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80801D6C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80801D70: swc1        $f0, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f0.u32l;
    // 0x80801D74: bne         $s0, $s3, L_80801D38
    if (ctx->r16 != ctx->r19) {
        // 0x80801D78: swc1        $f24, 0xCC($s1)
        MEM_W(0XCC, ctx->r17) = ctx->f24.u32l;
            goto L_80801D38;
    }
    // 0x80801D78: swc1        $f24, 0xCC($s1)
    MEM_W(0XCC, ctx->r17) = ctx->f24.u32l;
    // 0x80801D7C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80801D80: jal         0x800F0EF0
    // 0x80801D84: addiu       $a1, $s5, 0xD0
    ctx->r5 = ADD32(ctx->r21, 0XD0);
    func_800F0EF0(rdram, ctx);
        goto after_19;
    // 0x80801D84: addiu       $a1, $s5, 0xD0
    ctx->r5 = ADD32(ctx->r21, 0XD0);
    after_19:
    // 0x80801D88: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80801D8C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801D90: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80801D94: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80801D98: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80801D9C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80801DA0: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80801DA4: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80801DA8: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x80801DAC: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x80801DB0: jr          $ra
    // 0x80801DB4: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x80801DB4: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
;}
RECOMP_FUNC void _gsworldDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B70: syscall     726
    recomp_syscall_handler(rdram, ctx, 0x80088B70);
    return;
    // 0x80088B74: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bacough_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084630: syscall     117
    recomp_syscall_handler(rdram, ctx, 0x80084630);
    return;
    // 0x80084634: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800AD0_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AD8: jal         0x80082FF0
    // 0x80800ADC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800ADC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800AE0: jal         0x80800164
    // 0x80800AE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800164_bsbanshack(rdram, ctx);
        goto after_1;
    // 0x80800AE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AF0: jr          $ra
    // 0x80800AF4: nop

    return;
    // 0x80800AF4: nop

;}
RECOMP_FUNC void chfloaty_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DAC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2416, 0XEF0) << 16);
    // 0x80800DB0: jr          $ra
    // 0x80800DB4: addiu       $v0, $v0, 0xEF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2416, 0XEF0));
    return;
    // 0x80800DB4: addiu       $v0, $v0, 0xEF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2416, 0XEF0));
    // 0x80800DB8: nop

    // 0x80800DBC: nop

;}
RECOMP_FUNC void func_80800304_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080030C: jal         0x800897C8
    // 0x80800310: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800310: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080031C: jr          $ra
    // 0x80800320: nop

    return;
    // 0x80800320: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808009EC: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x808009F0: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x808009F4: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x808009F8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x808009FC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800A00: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80800A04: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80800A08: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80800A0C: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80800A10: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80800A14: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80800A18: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80800A1C: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80800A20: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800A24: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800A28: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800A2C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800A30: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800A34: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80800A38: jal         0x808013B4
    // 0x80800A3C: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    sumumbofx_entrypoint_26(rdram, ctx);
        goto after_0;
    // 0x80800A3C: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800A40: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80800A44: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80800A48: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80800A4C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800A50: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80800A54: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800A58: addu        $s0, $s3, $t6
    ctx->r16 = ADD32(ctx->r19, ctx->r14);
    // 0x80800A5C: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800A60: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80800A64: addiu       $s0, $s0, 0x64
    ctx->r16 = ADD32(ctx->r16, 0X64);
    // 0x80800A68: beq         $at, $zero, L_80800C00
    if (ctx->r1 == 0) {
        // 0x80800A6C: or          $s2, $s1, $zero
        ctx->r18 = ctx->r17 | 0;
            goto L_80800C00;
    }
    // 0x80800A6C: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80800A70: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800A74: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800A78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X14AC) << 16);
    // 0x80800A7C: lwc1        $f28, 0x14AC($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X14AC));
    // 0x80800A80: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800A84: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800A88: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X14B0) << 16);
    // 0x80800A8C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800A90: lwc1        $f20, 0x14B0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X14B0));
    // 0x80800A94: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80800A98: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80800A9C: lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X88);
    // 0x80800AA0: lw          $s5, 0x8C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X8C);
    // 0x80800AA4: lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X90);
    // 0x80800AA8: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
L_80800AAC:
    // 0x80800AAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AB0: jal         0x8080060C
    // 0x80800AB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8080060C_sumumbofx(rdram, ctx);
        goto after_1;
    // 0x80800AB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800AB8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800ABC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800AC0: addiu       $s1, $s0, 0x10
    ctx->r17 = ADD32(ctx->r16, 0X10);
    // 0x80800AC4: mul.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x80800AC8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800ACC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X14B4) << 16);
    // 0x80800AD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AD4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800AD8: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80800ADC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800AE0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800AE4: nop

    // 0x80800AE8: bc1fl       L_80800B3C
    if (!c1cs) {
        // 0x80800AEC: lwc1        $f18, 0xC($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80800B3C;
    }
    goto skip_0;
    // 0x80800AEC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x80800AF0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800AF4: nop

    // 0x80800AF8: bc1fl       L_80800B20
    if (!c1cs) {
        // 0x80800AFC: lw          $v0, 0x60($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X60);
            goto L_80800B20;
    }
    goto skip_1;
    // 0x80800AFC: lw          $v0, 0x60($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X60);
    skip_1:
    // 0x80800B00: sub.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f22.fl;
L_80800B04:
    // 0x80800B04: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80800B08: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800B0C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800B10: nop

    // 0x80800B14: bc1tl       L_80800B04
    if (c1cs) {
        // 0x80800B18: sub.s       $f16, $f0, $f22
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f22.fl;
            goto L_80800B04;
    }
    goto skip_2;
    // 0x80800B18: sub.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f22.fl;
    skip_2:
    // 0x80800B1C: lw          $v0, 0x60($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X60);
L_80800B20:
    // 0x80800B20: srl         $t8, $v0, 25
    ctx->r24 = S32(U32(ctx->r2) >> 25);
    // 0x80800B24: beql        $s7, $t8, L_80800B3C
    if (ctx->r23 == ctx->r24) {
        // 0x80800B28: lwc1        $f18, 0xC($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80800B3C;
    }
    goto skip_3;
    // 0x80800B28: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    skip_3:
    // 0x80800B2C: beql        $fp, $t8, L_80800B3C
    if (ctx->r30 == ctx->r24) {
        // 0x80800B30: lwc1        $f18, 0xC($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80800B3C;
    }
    goto skip_4;
    // 0x80800B30: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    skip_4:
    // 0x80800B34: swc1        $f30, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f30.u32l;
    // 0x80800B38: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
L_80800B3C:
    // 0x80800B3C: lwc1        $f6, 0x14B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X14B4));
    // 0x80800B40: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800B44: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80800B48: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80800B4C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80800B50: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800B54: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800B58: nop

    // 0x80800B5C: bc1fl       L_80800B70
    if (!c1cs) {
        // 0x80800B60: lwc1        $f16, 0x7C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
            goto L_80800B70;
    }
    goto skip_5;
    // 0x80800B60: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    skip_5:
    // 0x80800B64: swc1        $f24, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f24.u32l;
    // 0x80800B68: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800B6C: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
L_80800B70:
    // 0x80800B70: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80800B74: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800B78: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80800B7C: jal         0x800EF4E4
    // 0x80800B80: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_2;
    // 0x80800B80: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80800B84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B88: jal         0x800EF04C
    // 0x80800B8C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80800B8C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_3:
    // 0x80800B90: beq         $s4, $zero, L_80800BB0
    if (ctx->r20 == 0) {
        // 0x80800B94: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800BB0;
    }
    // 0x80800B94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B98: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800B9C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80800BA0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80800BA4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800BA8: jal         0x800EF5A0
    // 0x80800BAC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_4;
    // 0x80800BAC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
L_80800BB0:
    // 0x80800BB0: beq         $s5, $zero, L_80800BC0
    if (ctx->r21 == 0) {
        // 0x80800BB4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800BC0;
    }
    // 0x80800BB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800BB8: jal         0x800EF04C
    // 0x80800BBC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800BBC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
L_80800BC0:
    // 0x80800BC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800BC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800BC8: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BD0: lui         $a1, 0x42FA
    ctx->r5 = S32(0X42FA << 16);
    // 0x80800BD4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800BD8: nop

    // 0x80800BDC: bc1fl       L_80800BF0
    if (!c1cs) {
        // 0x80800BE0: lw          $t9, 0x84($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X84);
            goto L_80800BF0;
    }
    goto skip_6;
    // 0x80800BE0: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    skip_6:
    // 0x80800BE4: jal         0x808003E4
    // 0x80800BE8: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_808003E4_sumumbofx(rdram, ctx);
        goto after_6;
    // 0x80800BE8: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_6:
    // 0x80800BEC: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
L_80800BF0:
    // 0x80800BF0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800BF4: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x80800BF8: bnel        $s2, $t9, L_80800AAC
    if (ctx->r18 != ctx->r25) {
        // 0x80800BFC: mfc1        $a2, $f26
        ctx->r6 = (int32_t)ctx->f26.u32l;
            goto L_80800AAC;
    }
    goto skip_7;
    // 0x80800BFC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    skip_7:
L_80800C00:
    // 0x80800C00: lw          $s5, 0x8C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X8C);
    // 0x80800C04: addiu       $a0, $s3, 0x1C
    ctx->r4 = ADD32(ctx->r19, 0X1C);
    // 0x80800C08: beql        $s5, $zero, L_80800C1C
    if (ctx->r21 == 0) {
        // 0x80800C0C: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80800C1C;
    }
    goto skip_8;
    // 0x80800C0C: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_8:
    // 0x80800C10: jal         0x800EE7F8
    // 0x80800C14: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800C14: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_7:
    // 0x80800C18: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_80800C1C:
    // 0x80800C1C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800C20: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800C24: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800C28: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800C2C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80800C30: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80800C34: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80800C38: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80800C3C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80800C40: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80800C44: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80800C48: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80800C4C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80800C50: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x80800C54: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80800C58: jr          $ra
    // 0x80800C5C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80800C5C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void chfactoryroofbits_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2280, 0XB34) << 16);
    // 0x808008FC: jr          $ra
    // 0x80800900: addiu       $v0, $v0, 0xB34
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0XB34));
    return;
    // 0x80800900: addiu       $v0, $v0, 0xB34
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0XB34));
    // 0x80800904: nop

    // 0x80800908: nop

    // 0x8080090C: nop

;}
RECOMP_FUNC void chfactorytrashbelt_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2328, 0X5EC) << 16);
    // 0x808005B0: jr          $ra
    // 0x808005B4: addiu       $v0, $v0, 0x5EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2328, 0X5EC));
    return;
    // 0x808005B4: addiu       $v0, $v0, 0x5EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2328, 0X5EC));
    // 0x808005B8: nop

    // 0x808005BC: nop

;}
RECOMP_FUNC void func_808009E4_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808009E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808009EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808009F0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808009F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009FC: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80800A00: beq         $a0, $zero, L_80800E0C
    if (ctx->r4 == 0) {
        // 0x80800A04: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800E0C;
    }
    // 0x80800A04: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800A08: lbu         $a0, 0x178($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X178);
    // 0x80800A0C: beql        $a0, $zero, L_80800E10
    if (ctx->r4 == 0) {
        // 0x80800A10: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E10;
    }
    goto skip_0;
    // 0x80800A10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800A14: lw          $t6, 0x1E4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1E4);
    // 0x80800A18: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800A1C: sll         $t8, $t6, 20
    ctx->r24 = S32(ctx->r14 << 20);
    // 0x80800A20: bgezl       $t8, L_80800E10
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800A24: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E10;
    }
    goto skip_1;
    // 0x80800A24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800A28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A2C: lwc1        $f6, 0x14C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14C);
    // 0x80800A30: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800A34: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800A38: nop

    // 0x80800A3C: bc1f        L_80800A64
    if (!c1cs) {
        // 0x80800A40: nop
    
            goto L_80800A64;
    }
    // 0x80800A40: nop

    // 0x80800A44: jal         0x800FCCD4
    // 0x80800A48: lbu         $a0, 0x144($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X144);
    func_800FCCD4(rdram, ctx);
        goto after_0;
    // 0x80800A48: lbu         $a0, 0x144($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X144);
    after_0:
    // 0x80800A4C: bnel        $v0, $zero, L_80800E10
    if (ctx->r2 != 0) {
        // 0x80800A50: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E10;
    }
    goto skip_2;
    // 0x80800A50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800A54: jal         0x800FC6B0
    // 0x80800A58: lbu         $a0, 0x144($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X144);
    func_800FC6B0(rdram, ctx);
        goto after_1;
    // 0x80800A58: lbu         $a0, 0x144($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X144);
    after_1:
    // 0x80800A5C: b           L_80800E10
    // 0x80800A60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E10;
    // 0x80800A60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A64:
    // 0x80800A64: blez        $a0, L_80800AAC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80800A68: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80800AAC;
    }
    // 0x80800A68: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80800A6C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80800A70: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
L_80800A74:
    // 0x80800A74: jal         0x800C3D78
    // 0x80800A78: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    func_800C3D78(rdram, ctx);
        goto after_2;
    // 0x80800A78: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800A7C: beq         $v0, $zero, L_80800A94
    if (ctx->r2 == 0) {
        // 0x80800A80: lw          $v1, 0x64($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X64);
            goto L_80800A94;
    }
    // 0x80800A80: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80800A84: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    // 0x80800A88: jal         0x800C3CE8
    // 0x80800A8C: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    func_800C3CE8(rdram, ctx);
        goto after_3;
    // 0x80800A8C: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_3:
    // 0x80800A90: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
L_80800A94:
    // 0x80800A94: lbu         $v0, 0x178($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X178);
    // 0x80800A98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800A9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800AA0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800AA4: bnel        $at, $zero, L_80800A74
    if (ctx->r1 != 0) {
        // 0x80800AA8: lbu         $a0, 0x144($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X144);
            goto L_80800A74;
    }
    goto skip_3;
    // 0x80800AA8: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    skip_3:
L_80800AAC:
    // 0x80800AAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800AB0: beq         $v0, $at, L_80800AE4
    if (ctx->r2 == ctx->r1) {
        // 0x80800AB4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800AE4;
    }
    // 0x80800AB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800AB8:
    // 0x80800AB8: jal         0x800DC214
    // 0x80800ABC: lbu         $a1, 0x178($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X178);
    func_800DC214(rdram, ctx);
        goto after_4;
    // 0x80800ABC: lbu         $a1, 0x178($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X178);
    after_4:
    // 0x80800AC0: lbu         $t9, 0x1D3($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X1D3);
    // 0x80800AC4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800AC8: beql        $v0, $t9, L_80800AB8
    if (ctx->r2 == ctx->r25) {
        // 0x80800ACC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800AB8;
    }
    goto skip_4;
    // 0x80800ACC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_4:
    // 0x80800AD0: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    // 0x80800AD4: addu        $t1, $s1, $t0
    ctx->r9 = ADD32(ctx->r17, ctx->r8);
    // 0x80800AD8: lh          $t2, 0x160($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X160);
    // 0x80800ADC: beql        $t2, $zero, L_80800AB8
    if (ctx->r10 == 0) {
        // 0x80800AE0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800AB8;
    }
    goto skip_5;
    // 0x80800AE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_5:
L_80800AE4:
    // 0x80800AE4: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x80800AE8: sb          $s2, 0x1D3($s1)
    MEM_B(0X1D3, ctx->r17) = ctx->r18;
    // 0x80800AEC: addu        $s0, $s1, $t3
    ctx->r16 = ADD32(ctx->r17, ctx->r11);
    // 0x80800AF0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800AF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800AF8: lwc1        $f2, 0x14C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x80800AFC: sll         $t4, $s2, 1
    ctx->r12 = S32(ctx->r18 << 1);
    // 0x80800B00: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x80800B04: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80800B08: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80800B0C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3DC8) << 16);
    // 0x80800B10: bc1f        L_80800C38
    if (!c1cs) {
        // 0x80800B14: addiu       $a0, $zero, -0xC
        ctx->r4 = ADD32(0, -0XC);
            goto L_80800C38;
    }
    // 0x80800B14: addiu       $a0, $zero, -0xC
    ctx->r4 = ADD32(0, -0XC);
L_80800B18:
    // 0x80800B18: jal         0x800DC214
    // 0x80800B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DC214(rdram, ctx);
        goto after_5;
    // 0x80800B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800B20: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80800B24: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x80800B28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B2C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800B30: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80800B34: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800B38: bc1tl       L_80800B18
    if (c1cs) {
        // 0x80800B3C: addiu       $a0, $zero, -0xC
        ctx->r4 = ADD32(0, -0XC);
            goto L_80800B18;
    }
    goto skip_6;
    // 0x80800B3C: addiu       $a0, $zero, -0xC
    ctx->r4 = ADD32(0, -0XC);
    skip_6:
    // 0x80800B40: lui         $at, 0xC110
    ctx->r1 = S32(0XC110 << 16);
    // 0x80800B44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B48: nop

    // 0x80800B4C: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800B50: nop

    // 0x80800B54: bc1tl       L_80800B18
    if (c1cs) {
        // 0x80800B58: addiu       $a0, $zero, -0xC
        ctx->r4 = ADD32(0, -0XC);
            goto L_80800B18;
    }
    goto skip_7;
    // 0x80800B58: addiu       $a0, $zero, -0xC
    ctx->r4 = ADD32(0, -0XC);
    skip_7:
    // 0x80800B5C: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x80800B60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B64: nop

    // 0x80800B68: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80800B6C: nop

    // 0x80800B70: bc1tl       L_80800B18
    if (c1cs) {
        // 0x80800B74: addiu       $a0, $zero, -0xC
        ctx->r4 = ADD32(0, -0XC);
            goto L_80800B18;
    }
    goto skip_8;
    // 0x80800B74: addiu       $a0, $zero, -0xC
    ctx->r4 = ADD32(0, -0XC);
    skip_8:
    // 0x80800B78: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80800B7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800B80: nop

    // 0x80800B84: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80800B88: nop

    // 0x80800B8C: bc1tl       L_80800B18
    if (c1cs) {
        // 0x80800B90: addiu       $a0, $zero, -0xC
        ctx->r4 = ADD32(0, -0XC);
            goto L_80800B18;
    }
    goto skip_9;
    // 0x80800B90: addiu       $a0, $zero, -0xC
    ctx->r4 = ADD32(0, -0XC);
    skip_9:
    // 0x80800B94: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80800B98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B9C: nop

    // 0x80800BA0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800BA4: nop

    // 0x80800BA8: bc1tl       L_80800B18
    if (c1cs) {
        // 0x80800BAC: addiu       $a0, $zero, -0xC
        ctx->r4 = ADD32(0, -0XC);
            goto L_80800B18;
    }
    goto skip_10;
    // 0x80800BAC: addiu       $a0, $zero, -0xC
    ctx->r4 = ADD32(0, -0XC);
    skip_10:
    // 0x80800BB0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80800BB4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800BB8: nop

    // 0x80800BBC: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    // 0x80800BC0: nop

    // 0x80800BC4: bc1tl       L_80800B18
    if (c1cs) {
        // 0x80800BC8: addiu       $a0, $zero, -0xC
        ctx->r4 = ADD32(0, -0XC);
            goto L_80800B18;
    }
    goto skip_11;
    // 0x80800BC8: addiu       $a0, $zero, -0xC
    ctx->r4 = ADD32(0, -0XC);
    skip_11:
    // 0x80800BCC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800BD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800BD4: nop

    // 0x80800BD8: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800BDC: nop

    // 0x80800BE0: bc1tl       L_80800B18
    if (c1cs) {
        // 0x80800BE4: addiu       $a0, $zero, -0xC
        ctx->r4 = ADD32(0, -0XC);
            goto L_80800B18;
    }
    goto skip_12;
    // 0x80800BE4: addiu       $a0, $zero, -0xC
    ctx->r4 = ADD32(0, -0XC);
    skip_12:
    // 0x80800BE8: lwc1        $f2, 0x14C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x80800BEC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800BF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800BF4: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80800BF8: nop

    // 0x80800BFC: bc1f        L_80800C0C
    if (!c1cs) {
        // 0x80800C00: nop
    
            goto L_80800C0C;
    }
    // 0x80800C00: nop

    // 0x80800C04: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80800C08: sub.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f8.fl;
L_80800C0C:
    // 0x80800C0C: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80800C10: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800C14: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800C18: jal         0x80027170
    // 0x80800C1C: nop

    func_80027170(rdram, ctx);
        goto after_6;
    // 0x80800C1C: nop

    after_6:
    // 0x80800C20: addu        $s0, $s1, $s2
    ctx->r16 = ADD32(ctx->r17, ctx->r18);
    // 0x80800C24: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C28: jal         0x800C31DC
    // 0x80800C2C: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    func_800C31DC(rdram, ctx);
        goto after_7;
    // 0x80800C2C: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    after_7:
    // 0x80800C30: b           L_80800CD4
    // 0x80800C34: lh          $t7, 0x13A($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X13A);
        goto L_80800CD4;
    // 0x80800C34: lh          $t7, 0x13A($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X13A);
L_80800C38:
    // 0x80800C38: lwc1        $f18, 0x3DC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3DC8));
    // 0x80800C3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3DCC) << 16);
    // 0x80800C40: lwc1        $f8, 0x3DCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3DCC));
    // 0x80800C44: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800C48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800C4C: sub.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80800C50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800C54: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3DD0) << 16);
    // 0x80800C58: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800C5C: nop

    // 0x80800C60: bc1fl       L_80800C74
    if (!c1cs) {
        // 0x80800C64: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_80800C74;
    }
    goto skip_13;
    // 0x80800C64: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_13:
    // 0x80800C68: b           L_80800C74
    // 0x80800C6C: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
        goto L_80800C74;
    // 0x80800C6C: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    // 0x80800C70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80800C74:
    // 0x80800C74: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x80800C78: sub.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80800C7C: bc1fl       L_80800C8C
    if (!c1cs) {
        // 0x80800C80: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_80800C8C;
    }
    goto skip_14;
    // 0x80800C80: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_14:
    // 0x80800C84: lwc1        $f12, 0x3DD0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3DD0));
    // 0x80800C88: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_80800C8C:
    // 0x80800C8C: nop

    // 0x80800C90: bc1fl       L_80800CA4
    if (!c1cs) {
        // 0x80800C94: mov.s       $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
            goto L_80800CA4;
    }
    goto skip_15;
    // 0x80800C94: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    skip_15:
    // 0x80800C98: b           L_80800CA4
    // 0x80800C9C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80800CA4;
    // 0x80800C9C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800CA0: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_80800CA4:
    // 0x80800CA4: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x80800CA8: nop

    // 0x80800CAC: bc1t        L_80800CB8
    if (c1cs) {
        // 0x80800CB0: nop
    
            goto L_80800CB8;
    }
    // 0x80800CB0: nop

    // 0x80800CB4: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
L_80800CB8:
    // 0x80800CB8: jal         0x800DC264
    // 0x80800CBC: nop

    func_800DC264(rdram, ctx);
        goto after_8;
    // 0x80800CBC: nop

    after_8:
    // 0x80800CC0: addu        $s0, $s1, $s2
    ctx->r16 = ADD32(ctx->r17, ctx->r18);
    // 0x80800CC4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800CC8: jal         0x800C31DC
    // 0x80800CCC: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    func_800C31DC(rdram, ctx);
        goto after_9;
    // 0x80800CCC: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    after_9:
    // 0x80800CD0: lh          $t7, 0x13A($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X13A);
L_80800CD4:
    // 0x80800CD4: lh          $t8, 0x172($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X172);
    // 0x80800CD8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800CDC: bnel        $t7, $t8, L_80800DB8
    if (ctx->r15 != ctx->r24) {
        // 0x80800CE0: lh          $v1, 0x160($t6)
        ctx->r3 = MEM_H(ctx->r14, 0X160);
            goto L_80800DB8;
    }
    goto skip_16;
    // 0x80800CE0: lh          $v1, 0x160($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X160);
    skip_16:
    // 0x80800CE4: lw          $a0, 0x130($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X130);
    // 0x80800CE8: jal         0x808006B4
    // 0x80800CEC: lw          $a1, 0x13C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X13C);
    func_808006B4_gczoombox(rdram, ctx);
        goto after_10;
    // 0x80800CEC: lw          $a1, 0x13C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X13C);
    after_10:
    // 0x80800CF0: beq         $v0, $zero, L_80800D2C
    if (ctx->r2 == 0) {
        // 0x80800CF4: addiu       $a1, $s1, 0x134
        ctx->r5 = ADD32(ctx->r17, 0X134);
            goto L_80800D2C;
    }
    // 0x80800CF4: addiu       $a1, $s1, 0x134
    ctx->r5 = ADD32(ctx->r17, 0X134);
    // 0x80800CF8: jal         0x800EC370
    // 0x80800CFC: lw          $a0, 0x130($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X130);
    func_800EC370(rdram, ctx);
        goto after_11;
    // 0x80800CFC: lw          $a0, 0x130($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X130);
    after_11:
    // 0x80800D00: jal         0x80089788
    // 0x80800D04: lbu         $a0, 0x173($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X173);
    _suexpression_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x80800D04: lbu         $a0, 0x173($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X173);
    after_12:
    // 0x80800D08: lh          $t9, 0x136($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X136);
    // 0x80800D0C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800D10: nop

    // 0x80800D14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800D18: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800D1C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800D20: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80800D24: nop

    // 0x80800D28: sh          $t1, 0x136($s1)
    MEM_H(0X136, ctx->r17) = ctx->r9;
L_80800D2C:
    // 0x80800D2C: lh          $t2, 0x134($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X134);
    // 0x80800D30: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80800D34: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80800D38: nop

    // 0x80800D3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800D40: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80800D44: lh          $t3, 0x136($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X136);
    // 0x80800D48: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80800D4C: nop

    // 0x80800D50: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800D54: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80800D58: lh          $t4, 0x138($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X138);
    // 0x80800D5C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800D60: nop

    // 0x80800D64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800D68: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80800D6C: lh          $v1, 0x160($t5)
    ctx->r3 = MEM_H(ctx->r13, 0X160);
    // 0x80800D70: addiu       $v0, $v1, -0x1770
    ctx->r2 = ADD32(ctx->r3, -0X1770);
    // 0x80800D74: bgez        $v0, L_80800D84
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80800D78: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800D84;
    }
    // 0x80800D78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D7C: b           L_80800D84
    // 0x80800D80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80800D84;
    // 0x80800D80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800D84:
    // 0x80800D84: bgez        $v1, L_80800D94
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80800D88: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80800D94;
    }
    // 0x80800D88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800D8C: b           L_80800D98
    // 0x80800D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800D98;
    // 0x80800D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800D94:
    // 0x80800D94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800D98:
    // 0x80800D98: jal         0x800DC214
    // 0x80800D9C: nop

    func_800DC214(rdram, ctx);
        goto after_13;
    // 0x80800D9C: nop

    after_13:
    // 0x80800DA0: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    // 0x80800DA4: jal         0x800C3058
    // 0x80800DA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800C3058(rdram, ctx);
        goto after_14;
    // 0x80800DA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x80800DAC: b           L_80800DF4
    // 0x80800DB0: nop

        goto L_80800DF4;
    // 0x80800DB0: nop

    // 0x80800DB4: lh          $v1, 0x160($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X160);
L_80800DB8:
    // 0x80800DB8: addiu       $v0, $v1, -0x1770
    ctx->r2 = ADD32(ctx->r3, -0X1770);
    // 0x80800DBC: bgez        $v0, L_80800DCC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80800DC0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800DCC;
    }
    // 0x80800DC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DC4: b           L_80800DCC
    // 0x80800DC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80800DCC;
    // 0x80800DC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800DCC:
    // 0x80800DCC: bgez        $v1, L_80800DDC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80800DD0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80800DDC;
    }
    // 0x80800DD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800DD4: b           L_80800DE0
    // 0x80800DD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800DE0;
    // 0x80800DD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800DDC:
    // 0x80800DDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800DE0:
    // 0x80800DE0: jal         0x800DC214
    // 0x80800DE4: nop

    func_800DC214(rdram, ctx);
        goto after_15;
    // 0x80800DE4: nop

    after_15:
    // 0x80800DE8: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    // 0x80800DEC: jal         0x800C3058
    // 0x80800DF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800C3058(rdram, ctx);
        goto after_16;
    // 0x80800DF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
L_80800DF4:
    // 0x80800DF4: jal         0x800C3BDC
    // 0x80800DF8: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    func_800C3BDC(rdram, ctx);
        goto after_17;
    // 0x80800DF8: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    after_17:
    // 0x80800DFC: jal         0x800D52CC
    // 0x80800E00: lh          $a0, 0x172($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X172);
    func_800D52CC(rdram, ctx);
        goto after_18;
    // 0x80800E00: lh          $a0, 0x172($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X172);
    after_18:
    // 0x80800E04: jal         0x800D527C
    // 0x80800E08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800D527C(rdram, ctx);
        goto after_19;
    // 0x80800E08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_19:
L_80800E0C:
    // 0x80800E0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E10:
    // 0x80800E10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800E1C: jr          $ra
    // 0x80800E20: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800E20: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800DA3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA3B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DA3BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA3C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800DA3C4: bltz        $a0, L_800DA420
    if (SIGNED(ctx->r4) < 0) {
        // 0x800DA3C8: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800DA420;
    }
    // 0x800DA3C8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800DA3CC: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x800DA3D0: beql        $at, $zero, L_800DA424
    if (ctx->r1 == 0) {
        // 0x800DA3D4: slti        $at, $a3, 0x29
        ctx->r1 = SIGNED(ctx->r7) < 0X29 ? 1 : 0;
            goto L_800DA424;
    }
    goto skip_0;
    // 0x800DA3D4: slti        $at, $a3, 0x29
    ctx->r1 = SIGNED(ctx->r7) < 0X29 ? 1 : 0;
    skip_0:
    // 0x800DA3D8: beq         $a1, $zero, L_800DA400
    if (ctx->r5 == 0) {
        // 0x800DA3DC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800DA400;
    }
    // 0x800DA3DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800DA3E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800DA3E4: addiu       $v0, $v0, -0x4670
    ctx->r2 = ADD32(ctx->r2, -0X4670);
    // 0x800DA3E8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800DA3EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DA3F0: sllv        $t8, $t7, $a0
    ctx->r24 = S32(ctx->r15 << (ctx->r4 & 31));
    // 0x800DA3F4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800DA3F8: b           L_800DA514
    // 0x800DA3FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_800DA514;
    // 0x800DA3FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_800DA400:
    // 0x800DA400: addiu       $v0, $v0, -0x4670
    ctx->r2 = ADD32(ctx->r2, -0X4670);
    // 0x800DA404: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800DA408: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800DA40C: sllv        $t2, $t1, $a3
    ctx->r10 = S32(ctx->r9 << (ctx->r7 & 31));
    // 0x800DA410: nor         $t3, $t2, $zero
    ctx->r11 = ~(ctx->r10 | 0);
    // 0x800DA414: and         $t4, $t0, $t3
    ctx->r12 = ctx->r8 & ctx->r11;
    // 0x800DA418: b           L_800DA514
    // 0x800DA41C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_800DA514;
    // 0x800DA41C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_800DA420:
    // 0x800DA420: slti        $at, $a3, 0x29
    ctx->r1 = SIGNED(ctx->r7) < 0X29 ? 1 : 0;
L_800DA424:
    // 0x800DA424: bne         $at, $zero, L_800DA448
    if (ctx->r1 != 0) {
        // 0x800DA428: slti        $at, $a3, 0x5A5
        ctx->r1 = SIGNED(ctx->r7) < 0X5A5 ? 1 : 0;
            goto L_800DA448;
    }
    // 0x800DA428: slti        $at, $a3, 0x5A5
    ctx->r1 = SIGNED(ctx->r7) < 0X5A5 ? 1 : 0;
    // 0x800DA42C: beq         $at, $zero, L_800DA448
    if (ctx->r1 == 0) {
        // 0x800DA430: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA448;
    }
    // 0x800DA430: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA434: lw          $a0, -0x3890($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3890);
    // 0x800DA438: jal         0x800D9F18
    // 0x800DA43C: addiu       $a1, $a3, -0x28
    ctx->r5 = ADD32(ctx->r7, -0X28);
    bitfield_set_bit(rdram, ctx);
        goto after_0;
    // 0x800DA43C: addiu       $a1, $a3, -0x28
    ctx->r5 = ADD32(ctx->r7, -0X28);
    after_0:
    // 0x800DA440: b           L_800DA518
    // 0x800DA444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DA518;
    // 0x800DA444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA448:
    // 0x800DA448: slti        $at, $a3, 0x641
    ctx->r1 = SIGNED(ctx->r7) < 0X641 ? 1 : 0;
    // 0x800DA44C: bne         $at, $zero, L_800DA470
    if (ctx->r1 != 0) {
        // 0x800DA450: slti        $at, $a3, 0x6ED
        ctx->r1 = SIGNED(ctx->r7) < 0X6ED ? 1 : 0;
            goto L_800DA470;
    }
    // 0x800DA450: slti        $at, $a3, 0x6ED
    ctx->r1 = SIGNED(ctx->r7) < 0X6ED ? 1 : 0;
    // 0x800DA454: beq         $at, $zero, L_800DA470
    if (ctx->r1 == 0) {
        // 0x800DA458: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA470;
    }
    // 0x800DA458: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA45C: lw          $a0, -0x388C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X388C);
    // 0x800DA460: jal         0x800D9F18
    // 0x800DA464: addiu       $a1, $a3, -0x640
    ctx->r5 = ADD32(ctx->r7, -0X640);
    bitfield_set_bit(rdram, ctx);
        goto after_1;
    // 0x800DA464: addiu       $a1, $a3, -0x640
    ctx->r5 = ADD32(ctx->r7, -0X640);
    after_1:
    // 0x800DA468: b           L_800DA518
    // 0x800DA46C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DA518;
    // 0x800DA46C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA470:
    // 0x800DA470: slti        $at, $a3, 0x9C5
    ctx->r1 = SIGNED(ctx->r7) < 0X9C5 ? 1 : 0;
    // 0x800DA474: bne         $at, $zero, L_800DA498
    if (ctx->r1 != 0) {
        // 0x800DA478: slti        $at, $a3, 0xAC4
        ctx->r1 = SIGNED(ctx->r7) < 0XAC4 ? 1 : 0;
            goto L_800DA498;
    }
    // 0x800DA478: slti        $at, $a3, 0xAC4
    ctx->r1 = SIGNED(ctx->r7) < 0XAC4 ? 1 : 0;
    // 0x800DA47C: beq         $at, $zero, L_800DA498
    if (ctx->r1 == 0) {
        // 0x800DA480: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA498;
    }
    // 0x800DA480: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA484: lw          $a0, -0x3888($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3888);
    // 0x800DA488: jal         0x800D9F18
    // 0x800DA48C: addiu       $a1, $a3, -0x9C4
    ctx->r5 = ADD32(ctx->r7, -0X9C4);
    bitfield_set_bit(rdram, ctx);
        goto after_2;
    // 0x800DA48C: addiu       $a1, $a3, -0x9C4
    ctx->r5 = ADD32(ctx->r7, -0X9C4);
    after_2:
    // 0x800DA490: b           L_800DA518
    // 0x800DA494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DA518;
    // 0x800DA494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA498:
    // 0x800DA498: slti        $at, $a3, 0xBB9
    ctx->r1 = SIGNED(ctx->r7) < 0XBB9 ? 1 : 0;
    // 0x800DA49C: bne         $at, $zero, L_800DA4F4
    if (ctx->r1 != 0) {
        // 0x800DA4A0: slti        $at, $a3, 0xC16
        ctx->r1 = SIGNED(ctx->r7) < 0XC16 ? 1 : 0;
            goto L_800DA4F4;
    }
    // 0x800DA4A0: slti        $at, $a3, 0xC16
    ctx->r1 = SIGNED(ctx->r7) < 0XC16 ? 1 : 0;
    // 0x800DA4A4: beq         $at, $zero, L_800DA4F4
    if (ctx->r1 == 0) {
        // 0x800DA4A8: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA4F4;
    }
    // 0x800DA4A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA4AC: addiu       $a1, $a3, -0xBB8
    ctx->r5 = ADD32(ctx->r7, -0XBB8);
    // 0x800DA4B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DA4B4: addiu       $a0, $a0, -0x3880
    ctx->r4 = ADD32(ctx->r4, -0X3880);
    // 0x800DA4B8: jal         0x800D9E60
    // 0x800DA4BC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    bitfield_get_bit(rdram, ctx);
        goto after_3;
    // 0x800DA4BC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x800DA4C0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800DA4C4: addiu       $a0, $zero, 0xD54
    ctx->r4 = ADD32(0, 0XD54);
    // 0x800DA4C8: beq         $v0, $a2, L_800DA4DC
    if (ctx->r2 == ctx->r6) {
        // 0x800DA4CC: nop
    
            goto L_800DA4DC;
    }
    // 0x800DA4CC: nop

    // 0x800DA4D0: jal         0x800DA544
    // 0x800DA4D4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x800DA4D4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_4:
    // 0x800DA4D8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_800DA4DC:
    // 0x800DA4DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA4E0: addiu       $a0, $a0, -0x3880
    ctx->r4 = ADD32(ctx->r4, -0X3880);
    // 0x800DA4E4: jal         0x800D9F18
    // 0x800DA4E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bitfield_set_bit(rdram, ctx);
        goto after_5;
    // 0x800DA4E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_5:
    // 0x800DA4EC: b           L_800DA518
    // 0x800DA4F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DA518;
    // 0x800DA4F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA4F4:
    // 0x800DA4F4: slti        $at, $a3, 0xD49
    ctx->r1 = SIGNED(ctx->r7) < 0XD49 ? 1 : 0;
    // 0x800DA4F8: bne         $at, $zero, L_800DA514
    if (ctx->r1 != 0) {
        // 0x800DA4FC: slti        $at, $a3, 0xD75
        ctx->r1 = SIGNED(ctx->r7) < 0XD75 ? 1 : 0;
            goto L_800DA514;
    }
    // 0x800DA4FC: slti        $at, $a3, 0xD75
    ctx->r1 = SIGNED(ctx->r7) < 0XD75 ? 1 : 0;
    // 0x800DA500: beq         $at, $zero, L_800DA514
    if (ctx->r1 == 0) {
        // 0x800DA504: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA514;
    }
    // 0x800DA504: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA508: addiu       $a0, $a0, -0x3874
    ctx->r4 = ADD32(ctx->r4, -0X3874);
    // 0x800DA50C: jal         0x800D9F18
    // 0x800DA510: addiu       $a1, $a3, -0xD48
    ctx->r5 = ADD32(ctx->r7, -0XD48);
    bitfield_set_bit(rdram, ctx);
        goto after_6;
    // 0x800DA510: addiu       $a1, $a3, -0xD48
    ctx->r5 = ADD32(ctx->r7, -0XD48);
    after_6:
L_800DA514:
    // 0x800DA514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA518:
    // 0x800DA518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DA51C: jr          $ra
    // 0x800DA520: nop

    return;
    // 0x800DA520: nop

;}
RECOMP_FUNC void func_800A275C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A275C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A2760: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A2764: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800A2768: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800A276C: jal         0x8009FC34
    // 0x800A2770: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009FC34(rdram, ctx);
        goto after_0;
    // 0x800A2770: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x800A2774: jal         0x8009BB5C
    // 0x800A2778: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8009BB5C(rdram, ctx);
        goto after_1;
    // 0x800A2778: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800A277C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x800A2780: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A2784: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800A2788: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800A278C: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x800A2790: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    // 0x800A2794: jal         0x800F10B4
    // 0x800A2798: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x800A2798: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x800A279C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800A27A0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800A27A4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800A27A8: lw          $t7, 0x124($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X124);
    // 0x800A27AC: jal         0x8008FE94
    // 0x800A27B0: lbu         $a0, 0x4($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X4);
    func_8008FE94(rdram, ctx);
        goto after_3;
    // 0x800A27B0: lbu         $a0, 0x4($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X4);
    after_3:
    // 0x800A27B4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800A27B8: bnel        $t8, $zero, L_800A27D0
    if (ctx->r24 != 0) {
        // 0x800A27BC: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_800A27D0;
    }
    goto skip_0;
    // 0x800A27BC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    skip_0:
    // 0x800A27C0: jal         0x800964DC
    // 0x800A27C4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800964DC(rdram, ctx);
        goto after_4;
    // 0x800A27C4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x800A27C8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800A27CC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_800A27D0:
    // 0x800A27D0: jal         0x80088AE8
    // 0x800A27D4: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    _fxsplash_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x800A27D4: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_5:
    // 0x800A27D8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A27DC: addiu       $t6, $zero, 0x15E
    ctx->r14 = ADD32(0, 0X15E);
    // 0x800A27E0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800A27E4: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800A27E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A27EC: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x800A27F0: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
    // 0x800A27F4: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800A27F8: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800A27FC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A2800: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x800A2804: sra         $v1, $t4, 16
    ctx->r3 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800A2808: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800A280C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800A2810: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x800A2814: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x800A2818: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800A281C: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x800A2820: sra         $t2, $a3, 16
    ctx->r10 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800A2824: jal         0x800BA930
    // 0x800A2828: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    func_800BA930(rdram, ctx);
        goto after_6;
    // 0x800A2828: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    after_6:
    // 0x800A282C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A2830: jal         0x800BA22C
    // 0x800A2834: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x800A2834: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x800A2838: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A283C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A2840: jr          $ra
    // 0x800A2844: nop

    return;
    // 0x800A2844: nop

;}
RECOMP_FUNC void _bskazshock_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083568: syscall     66
    recomp_syscall_handler(rdram, ctx, 0x80083568);
    return;
    // 0x8008356C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800710_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800710: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800714: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800718: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080071C: jal         0x80102424
    // 0x80800720: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800720: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800724: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800728: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080072C: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x80800730: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80800734: beq         $at, $zero, L_808007EC
    if (ctx->r1 == 0) {
        // 0x80800738: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808007EC;
    }
    // 0x80800738: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080073C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1636, 0X11C4) << 16);
    // 0x80800740: addu        $at, $at, $t8
    gpr jr_addend_80800748 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800744: lw          $t8, 0x11C4($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1636, 0X11C4));
    // 0x80800748: jr          $t8
    // 0x8080074C: nop

    switch (jr_addend_80800748 >> 2) {
        case 0: goto L_80800750; break;
        case 1: goto L_8080076C; break;
        case 2: goto L_80800784; break;
        case 3: goto L_808007BC; break;
        case 4: goto L_808007DC; break;
        case 5: goto L_808007EC; break;
        case 6: goto L_808007CC; break;
        default: switch_error(__func__, 0x80800748, 0x808011C4);
    }
    // 0x8080074C: nop

L_80800750:
    // 0x80800750: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800754: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800758: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080075C: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x80800760: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800764: b           L_808007EC
    // 0x80800768: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
        goto L_808007EC;
    // 0x80800768: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
L_8080076C:
    // 0x8080076C: jal         0x80800464
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800464_chcredits(rdram, ctx);
        goto after_1;
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800774: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800778: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080077C: b           L_808007EC
    // 0x80800780: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808007EC;
    // 0x80800780: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800784:
    // 0x80800784: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800788: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x8080078C: jal         0x800EA05C
    // 0x80800790: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80800790: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    after_2:
    // 0x80800794: addiu       $at, $zero, 0x116
    ctx->r1 = ADD32(0, 0X116);
    // 0x80800798: bne         $v0, $at, L_808007AC
    if (ctx->r2 != ctx->r1) {
        // 0x8080079C: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_808007AC;
    }
    // 0x8080079C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808007A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007A4: b           L_808007EC
    // 0x808007A8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_808007EC;
    // 0x808007A8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_808007AC:
    // 0x808007AC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x808007B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808007B4: b           L_808007EC
    // 0x808007B8: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_808007EC;
    // 0x808007B8: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_808007BC:
    // 0x808007BC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808007C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007C4: b           L_808007EC
    // 0x808007C8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_808007EC;
    // 0x808007C8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_808007CC:
    // 0x808007CC: jal         0x8080038C
    // 0x808007D0: nop

    func_8080038C_chcredits(rdram, ctx);
        goto after_3;
    // 0x808007D0: nop

    after_3:
    // 0x808007D4: b           L_808007F0
    // 0x808007D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007F0;
    // 0x808007D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007DC:
    // 0x808007DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808007E4: nop

    // 0x808007E8: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_808007EC:
    // 0x808007EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007F0:
    // 0x808007F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007F8: jr          $ra
    // 0x808007FC: nop

    return;
    // 0x808007FC: nop

;}
RECOMP_FUNC void bswasher_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801280: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801284: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(443, 0X1E70) << 16);
    // 0x80801288: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080128C: jr          $ra
    // 0x80801290: lw          $v0, 0x1E70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E70));
    return;
    // 0x80801290: lw          $v0, 0x1E70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E70));
;}
RECOMP_FUNC void boot_osYieldThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void suexpression_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800214: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800218: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x8080021C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800220: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x80800224: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x80800228: addu        $a0, $a0, $v0
        ctx->r4 = ADD32(ctx->r4, ctx->r2);
            goto L_80800238;
    }
    // 0x80800228: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8080022C: jal         0x80089B50
    // 0x80800230: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _suexpressmorph_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800230: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800234: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80800238:
    // 0x80800238: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x8080023C: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x80800240: addu        $a0, $a2, $v0
        ctx->r4 = ADD32(ctx->r6, ctx->r2);
            goto L_8080024C;
    }
    // 0x80800240: addu        $a0, $a2, $v0
    ctx->r4 = ADD32(ctx->r6, ctx->r2);
    // 0x80800244: jal         0x80089768
    // 0x80800248: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    _suexpressjoint_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800248: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    after_1:
L_8080024C:
    // 0x8080024C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800254: jr          $ra
    // 0x80800258: nop

    return;
    // 0x80800258: nop

;}
RECOMP_FUNC void chfishshootgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(740, 0X18C0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x18C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(740, 0X18C0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x18C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(740, 0X18C0));
;}
RECOMP_FUNC void _gcgoto_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A70: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087A70);
    return;
    // 0x80087A74: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bsmumcast_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083890: syscall     77
    recomp_syscall_handler(rdram, ctx, 0x80083890);
    return;
    // 0x80083894: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chtiptup_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1020, 0X14D8) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x14D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1020, 0X14D8));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x14D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1020, 0X14D8));
;}
RECOMP_FUNC void func_80800278_glglobalsettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800278: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080027C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800280: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800284: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800288: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080028C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800290: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800294: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800298: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080029C: jal         0x80800084
    // 0x808002A0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    func_80800084_glglobalsettings(rdram, ctx);
        goto after_0;
    // 0x808002A0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    after_0:
    // 0x808002A4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808002A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808002AC:
    // 0x808002AC: jal         0x800884C0
    // 0x808002B0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    _glgamestore_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808002B0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x808002B4: bne         $v0, $zero, L_808002C8
    if (ctx->r2 != 0) {
        // 0x808002B8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_808002C8;
    }
    // 0x808002B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808002BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002C0: jal         0x808000A4
    // 0x808002C4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_808000A4_glglobalsettings(rdram, ctx);
        goto after_2;
    // 0x808002C4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
L_808002C8:
    // 0x808002C8: beq         $s1, $zero, L_808002D8
    if (ctx->r17 == 0) {
        // 0x808002CC: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_808002D8;
    }
    // 0x808002CC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808002D0: bnel        $s0, $zero, L_808002AC
    if (ctx->r16 != 0) {
        // 0x808002D4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808002AC;
    }
    goto skip_0;
    // 0x808002D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_808002D8:
    // 0x808002D8: jal         0x8001B084
    // 0x808002DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    heap_free(rdram, ctx);
        goto after_3;
    // 0x808002DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x808002E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808002E4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x808002E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808002EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002F0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808002F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808002F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808002FC: jr          $ra
    // 0x80800300: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800300: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800B2248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2248: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B224C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2250: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B2254: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800B2258: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800B225C: jal         0x800F2100
    // 0x800B2260: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x800B2260: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x800B2264: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B2268: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B226C: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x800B2270: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800B2274: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800B2278: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800B227C: jal         0x800F2100
    // 0x800B2280: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800B2280: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_1:
    // 0x800B2284: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B2288: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800B228C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800B2290: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800B2294: nop

    // 0x800B2298: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B229C: beql        $at, $zero, L_800B22AC
    if (ctx->r1 == 0) {
        // 0x800B22A0: lh          $t3, 0x6($t2)
        ctx->r11 = MEM_H(ctx->r10, 0X6);
            goto L_800B22AC;
    }
    goto skip_0;
    // 0x800B22A0: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    skip_0:
    // 0x800B22A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B22A8: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
L_800B22AC:
    // 0x800B22AC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800B22B0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800B22B4: jal         0x800F2100
    // 0x800B22B8: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x800B22B8: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_2:
    // 0x800B22BC: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B22C0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800B22C4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800B22C8: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800B22CC: nop

    // 0x800B22D0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B22D4: beql        $at, $zero, L_800B22E4
    if (ctx->r1 == 0) {
        // 0x800B22D8: lh          $t6, 0xA($t5)
        ctx->r14 = MEM_H(ctx->r13, 0XA);
            goto L_800B22E4;
    }
    goto skip_1;
    // 0x800B22D8: lh          $t6, 0xA($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XA);
    skip_1:
    // 0x800B22DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B22E0: lh          $t6, 0xA($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XA);
L_800B22E4:
    // 0x800B22E4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800B22E8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B22EC: jal         0x800F2100
    // 0x800B22F0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x800B22F0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_3:
    // 0x800B22F4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B22F8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800B22FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B2304: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800B2308: nop

    // 0x800B230C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B2310: beq         $at, $zero, L_800B231C
    if (ctx->r1 == 0) {
        // 0x800B2314: nop
    
            goto L_800B231C;
    }
    // 0x800B2314: nop

    // 0x800B2318: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B231C:
    // 0x800B231C: jr          $ra
    // 0x800B2320: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B2320: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void bsblongleg_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013E8: jal         0x808000C8
    // 0x808013EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000C8_bsblongleg(rdram, ctx);
        goto after_0;
    // 0x808013EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013F0: jal         0x80082FE8
    // 0x808013F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808013F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808013F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808013FC: jal         0x800915AC
    // 0x80801400: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_isDone(rdram, ctx);
        goto after_2;
    // 0x80801400: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80801404: beq         $v0, $zero, L_80801414
    if (ctx->r2 == 0) {
        // 0x80801408: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801414;
    }
    // 0x80801408: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080140C: jal         0x8009E5C8
    // 0x80801410: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80801410: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_3:
L_80801414:
    // 0x80801414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080141C: jr          $ra
    // 0x80801420: nop

    return;
    // 0x80801420: nop

;}
RECOMP_FUNC void chlagoonbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1052, 0X894) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x894
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1052, 0X894));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x894
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1052, 0X894));
;}
RECOMP_FUNC void func_808004F4_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004FC: jal         0x80089828
    // 0x80800500: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800500: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800504: bne         $v0, $zero, L_80800538
    if (ctx->r2 != 0) {
        // 0x80800508: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800538;
    }
    // 0x80800508: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080050C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800510: jal         0x800897C0
    // 0x80800514: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800514: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    after_1:
    // 0x80800518: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080051C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800520: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800524: jal         0x800897E8
    // 0x80800528: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800528: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_2:
    // 0x8080052C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800530: jal         0x80089810
    // 0x80800534: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x80800534: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_3:
L_80800538:
    // 0x80800538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080053C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800540: jr          $ra
    // 0x80800544: nop

    return;
    // 0x80800544: nop

;}
RECOMP_FUNC void func_808004C4_bsdronebitten(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808004D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808004D8: jal         0x8008CABC
    // 0x808004DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808004DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808004E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808004E4: jal         0x8008AF24
    // 0x808004E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808004E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: jal         0x8008AED4
    // 0x808004F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x808004F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: jal         0x8008B1BC
    // 0x80800500: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x80800500: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800508: jal         0x8008B134
    // 0x8080050C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x8080050C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800514: jal         0x8008B1A0
    // 0x80800518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_5;
    // 0x80800518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080051C: jal         0x8008B064
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800524: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800528: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080052C: sb          $t6, 0x190($t7)
    MEM_B(0X190, ctx->r15) = ctx->r14;
    // 0x80800530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800534: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080053C: jr          $ra
    // 0x80800540: nop

    return;
    // 0x80800540: nop

;}
RECOMP_FUNC void _badata_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846A0: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846A0);
    return;
    // 0x800846A4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _capod_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085730: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x80085730);
    return;
    // 0x80085734: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_800AE0D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE0D0: beq         $a0, $zero, L_800AE0E0
    if (ctx->r4 == 0) {
        // 0x800AE0D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AE0E0;
    }
    // 0x800AE0D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE0D8: jr          $ra
    // 0x800AE0DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    return;
    // 0x800AE0DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800AE0E0:
    // 0x800AE0E0: jr          $ra
    // 0x800AE0E4: nop

    return;
    // 0x800AE0E4: nop

;}
RECOMP_FUNC void gcmapDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C24: jal         0x800EA05C
    // 0x80800C28: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800C28: nop

    after_0:
    // 0x80800C2C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2646, 0X1BE8) << 16);
    // 0x80800C30: addiu       $a3, $a3, 0x1BE8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2646, 0X1BE8));
    // 0x80800C34: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x80800C38: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800C3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C40: beq         $a2, $t6, L_80800C70
    if (ctx->r6 == ctx->r14) {
        // 0x80800C44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800C70;
    }
    // 0x80800C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C48: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2646, 0X1BE8) << 16);
    // 0x80800C4C: addiu       $v1, $t7, 0x1BE8
    ctx->r3 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2646, 0X1BE8));
    // 0x80800C50: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
L_80800C54:
    // 0x80800C54: beql        $v0, $a0, L_80800C74
    if (ctx->r2 == ctx->r4) {
        // 0x80800C58: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80800C74;
    }
    goto skip_0;
    // 0x80800C58: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_0:
    // 0x80800C5C: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x80800C60: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800C64: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800C68: bne         $a2, $a0, L_80800C54
    if (ctx->r6 != ctx->r4) {
        // 0x80800C6C: nop
    
            goto L_80800C54;
    }
    // 0x80800C6C: nop

L_80800C70:
    // 0x80800C70: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
L_80800C74:
    // 0x80800C74: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x80800C78: lh          $v0, 0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X2);
    // 0x80800C7C: jr          $ra
    // 0x80800C80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800C80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _ncbastring_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089158: syscall     763
    recomp_syscall_handler(rdram, ctx, 0x80089158);
    return;
    // 0x8008915C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80102320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102328: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010232C: jal         0x80104248
    // 0x80102330: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80102330: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80102334: beq         $v0, $zero, L_80102380
    if (ctx->r2 == 0) {
        // 0x80102338: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102380;
    }
    // 0x80102338: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010233C: jal         0x8008B2B4
    // 0x80102340: nop

    anctrl_getAnimTimer(rdram, ctx);
        goto after_1;
    // 0x80102340: nop

    after_1:
    // 0x80102344: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80102348: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8010234C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80102350: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80102354: nop

    // 0x80102358: bc1f        L_80102378
    if (!c1cs) {
        // 0x8010235C: nop
    
            goto L_80102378;
    }
    // 0x8010235C: nop

    // 0x80102360: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80102364: nop

    // 0x80102368: bc1f        L_80102378
    if (!c1cs) {
        // 0x8010236C: nop
    
            goto L_80102378;
    }
    // 0x8010236C: nop

    // 0x80102370: b           L_80102384
    // 0x80102374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80102384;
    // 0x80102374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80102378:
    // 0x80102378: b           L_80102384
    // 0x8010237C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80102384;
    // 0x8010237C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80102380:
    // 0x80102380: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102384:
    // 0x80102384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010238C: jr          $ra
    // 0x80102390: nop

    return;
    // 0x80102390: nop

;}
RECOMP_FUNC void func_80800104_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800108: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800114: jal         0x8009E74C
    // 0x80800118: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800118: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x8080011C: bne         $v0, $zero, L_80800194
    if (ctx->r2 != 0) {
        // 0x80800120: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800194;
    }
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: jal         0x8009BF5C
    // 0x80800128: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x80800128: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: jal         0x8009C4CC
    // 0x80800134: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x80800134: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800138: jal         0x8009BC34
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BC34(rdram, ctx);
        goto after_3;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: jal         0x800A0CF4
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_4;
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x800961AC
    // 0x80800154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_5;
    // 0x80800154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x80093360
    // 0x80800160: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_6;
    // 0x80800160: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x80085298
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _baswim_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800170: jal         0x8009E6F8
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_8;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800178: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x8080017C: beq         $v0, $at, L_8080018C
    if (ctx->r2 == ctx->r1) {
        // 0x80800180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080018C;
    }
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x80085558
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baairbar_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_8080018C:
    // 0x8080018C: jal         0x80085288
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80800194:
    // 0x80800194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080019C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void func_80800D28_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D30: addiu       $at, $zero, 0xFFB
    ctx->r1 = ADD32(0, 0XFFB);
    // 0x80800D34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D3C: beq         $a1, $at, L_80800D50
    if (ctx->r5 == ctx->r1) {
        // 0x80800D40: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800D50;
    }
    // 0x80800D40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800D44: addiu       $at, $zero, 0x1054
    ctx->r1 = ADD32(0, 0X1054);
    // 0x80800D48: bne         $a1, $at, L_80800D9C
    if (ctx->r5 != ctx->r1) {
        // 0x80800D4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D9C;
    }
    // 0x80800D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D50:
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D54: jal         0x80102424
    // 0x80800D58: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800D58: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D60: jal         0x80105A9C
    // 0x80800D64: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    func_80105A9C(rdram, ctx);
        goto after_1;
    // 0x80800D64: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    after_1:
    // 0x80800D68: jal         0x80105BAC
    // 0x80800D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105BAC(rdram, ctx);
        goto after_2;
    // 0x80800D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800D70: jal         0x800F54E4
    // 0x80800D74: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800D74: nop

    after_3:
    // 0x80800D78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D7C: jal         0x800F82D4
    // 0x80800D80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_4;
    // 0x80800D80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800D8C: jal         0x80800F3C
    // 0x80800D90: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800F3C_chjollyroger(rdram, ctx);
        goto after_5;
    // 0x80800D90: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_5:
    // 0x80800D94: b           L_80800DA8
    // 0x80800D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800DA8;
    // 0x80800D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D9C:
    // 0x80800D9C: jal         0x80102424
    // 0x80800DA0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800DA0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80800DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800DA8:
    // 0x80800DA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800DAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DB0: jr          $ra
    // 0x80800DB4: nop

    return;
    // 0x80800DB4: nop

;}
RECOMP_FUNC void func_808067B0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808067B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808067B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808067B8: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x808067BC: jal         0x80809D94
    // 0x808067C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80809D94_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808067C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x808067C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808067C8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808067CC: swc1        $f0, 0x20C($v0)
    MEM_W(0X20C, ctx->r2) = ctx->f0.u32l;
    // 0x808067D0: swc1        $f2, 0x210($v0)
    MEM_W(0X210, ctx->r2) = ctx->f2.u32l;
    // 0x808067D4: swc1        $f2, 0x214($v0)
    MEM_W(0X214, ctx->r2) = ctx->f2.u32l;
    // 0x808067D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808067DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808067E0: jr          $ra
    // 0x808067E4: nop

    return;
    // 0x808067E4: nop

;}
