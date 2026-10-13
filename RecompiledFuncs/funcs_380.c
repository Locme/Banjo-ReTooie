#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80016B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016B30: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80016B34: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80016B38: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80016B3C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80016B40: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80016B44: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016B48: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80016B4C: jr          $ra
    // 0x80016B50: lw          $v0, -0x6620($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6620);
    return;
    // 0x80016B50: lw          $v0, -0x6620($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6620);
;}
RECOMP_FUNC void func_80108CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108CF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80108CF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80108CFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80108D00: jal         0x80088300
    // 0x80108D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gccubesearch_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x80108D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80108D08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80108D0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80108D10: beq         $v0, $zero, L_80108D78
    if (ctx->r2 == 0) {
        // 0x80108D14: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_80108D78;
    }
    // 0x80108D14: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80108D18: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80108D1C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80108D20: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x80108D24: srl         $t9, $t8, 21
    ctx->r25 = S32(U32(ctx->r24) >> 21);
    // 0x80108D28: beql        $t9, $zero, L_80108D7C
    if (ctx->r25 == 0) {
        // 0x80108D2C: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_80108D7C;
    }
    goto skip_0;
    // 0x80108D2C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80108D30: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80108D34: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80108D38: sll         $t0, $v1, 11
    ctx->r8 = S32(ctx->r3 << 11);
    // 0x80108D3C: srl         $v1, $t0, 21
    ctx->r3 = S32(U32(ctx->r8) >> 21);
    // 0x80108D40: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80108D44:
    // 0x80108D44: jal         0x80088300
    // 0x80108D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gccubesearch_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80108D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80108D4C: beq         $v0, $zero, L_80108D78
    if (ctx->r2 == 0) {
        // 0x80108D50: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80108D78;
    }
    // 0x80108D50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80108D54: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x80108D58: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80108D5C: bnel        $s0, $t3, L_80108D7C
    if (ctx->r16 != ctx->r11) {
        // 0x80108D60: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_80108D7C;
    }
    goto skip_1;
    // 0x80108D60: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80108D64: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80108D68: sll         $t4, $v1, 11
    ctx->r12 = S32(ctx->r3 << 11);
    // 0x80108D6C: srl         $v1, $t4, 21
    ctx->r3 = S32(U32(ctx->r12) >> 21);
    // 0x80108D70: bnel        $v1, $zero, L_80108D44
    if (ctx->r3 != 0) {
        // 0x80108D74: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80108D44;
    }
    goto skip_2;
    // 0x80108D74: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    skip_2:
L_80108D78:
    // 0x80108D78: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_80108D7C:
    // 0x80108D7C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80108D80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80108D84: beq         $t6, $s0, L_80108DA8
    if (ctx->r14 == ctx->r16) {
        // 0x80108D88: nop
    
            goto L_80108DA8;
    }
    // 0x80108D88: nop

    // 0x80108D8C: beq         $v0, $zero, L_80108DA8
    if (ctx->r2 == 0) {
        // 0x80108D90: nop
    
            goto L_80108DA8;
    }
    // 0x80108D90: nop

    // 0x80108D94: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80108D98: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80108D9C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80108DA0: bne         $s0, $t8, L_80108DB0
    if (ctx->r16 != ctx->r24) {
        // 0x80108DA4: nop
    
            goto L_80108DB0;
    }
    // 0x80108DA4: nop

L_80108DA8:
    // 0x80108DA8: b           L_80108DB0
    // 0x80108DAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80108DB0;
    // 0x80108DAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80108DB0:
    // 0x80108DB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80108DB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80108DB8: jr          $ra
    // 0x80108DBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80108DBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80015178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015178: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001517C: jr          $ra
    // 0x80015180: sw          $a0, -0x6EC4($at)
    MEM_W(-0X6EC4, ctx->r1) = ctx->r4;
    return;
    // 0x80015180: sw          $a0, -0x6EC4($at)
    MEM_W(-0X6EC4, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800F86D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F86D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F86DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F86E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F86E4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F86E8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800F86EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F86F0: addiu       $s1, $s1, 0x54B0
    ctx->r17 = ADD32(ctx->r17, 0X54B0);
    // 0x800F86F4: addiu       $s0, $s0, 0x5490
    ctx->r16 = ADD32(ctx->r16, 0X5490);
    // 0x800F86F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800F86FC:
    // 0x800F86FC: beql        $a0, $zero, L_800F8714
    if (ctx->r4 == 0) {
        // 0x800F8700: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800F8714;
    }
    goto skip_0;
    // 0x800F8700: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800F8704: jal         0x800F46D8
    // 0x800F8708: nop

    func_800F46D8(rdram, ctx);
        goto after_0;
    // 0x800F8708: nop

    after_0:
    // 0x800F870C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800F8710: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800F8714:
    // 0x800F8714: bnel        $s0, $s1, L_800F86FC
    if (ctx->r16 != ctx->r17) {
        // 0x800F8718: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800F86FC;
    }
    goto skip_1;
    // 0x800F8718: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800F871C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F8720: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F8724: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F8728: jr          $ra
    // 0x800F872C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F872C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8010DF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DF98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010DF9C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8010DFA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010DFA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010DFA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8010DFAC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8010DFB0: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
L_8010DFB4:
    // 0x8010DFB4: jal         0x80104148
    // 0x8010DFB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104148(rdram, ctx);
        goto after_0;
    // 0x8010DFB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8010DFBC: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    // 0x8010DFC0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8010DFC4: bnel        $t6, $zero, L_8010DFE8
    if (ctx->r14 != 0) {
        // 0x8010DFC8: sb          $zero, 0x4($v0)
        MEM_B(0X4, ctx->r2) = 0;
            goto L_8010DFE8;
    }
    goto skip_0;
    // 0x8010DFC8: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    skip_0:
    // 0x8010DFCC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8010DFD0: bnel        $t7, $zero, L_8010DFE8
    if (ctx->r15 != 0) {
        // 0x8010DFD4: sb          $zero, 0x4($v0)
        MEM_B(0X4, ctx->r2) = 0;
            goto L_8010DFE8;
    }
    goto skip_1;
    // 0x8010DFD4: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    skip_1:
    // 0x8010DFD8: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x8010DFDC: beql        $t8, $zero, L_8010DFF4
    if (ctx->r24 == 0) {
        // 0x8010DFE0: lh          $t9, 0x0($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X0);
            goto L_8010DFF4;
    }
    goto skip_2;
    // 0x8010DFE0: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    skip_2:
    // 0x8010DFE4: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
L_8010DFE8:
    // 0x8010DFE8: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8010DFEC: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8010DFF0: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
L_8010DFF4:
    // 0x8010DFF4: beql        $t9, $zero, L_8010E00C
    if (ctx->r25 == 0) {
        // 0x8010DFF8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8010E00C;
    }
    goto skip_3;
    // 0x8010DFF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x8010DFFC: jal         0x800ADFE0
    // 0x8010E000: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    func_800ADFE0(rdram, ctx);
        goto after_1;
    // 0x8010E000: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    after_1:
    // 0x8010E004: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x8010E008: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8010E00C:
    // 0x8010E00C: bne         $s0, $s2, L_8010DFB4
    if (ctx->r16 != ctx->r18) {
        // 0x8010E010: nop
    
            goto L_8010DFB4;
    }
    // 0x8010E010: nop

    // 0x8010E014: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010E018: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010E01C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8010E020: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8010E024: jr          $ra
    // 0x8010E028: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8010E028: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010E02C: nop

;}
RECOMP_FUNC void func_808018D0_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018D8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2C98) << 16);
    // 0x808018DC: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808018E0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808018E4: addiu       $a2, $a2, 0x2C98
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2C98));
    // 0x808018E8: jal         0x80089D20
    // 0x808018EC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808018EC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x808018F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018F8: jr          $ra
    // 0x808018FC: nop

    return;
    // 0x808018FC: nop

;}
RECOMP_FUNC void batimer_increment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800100: lw          $t7, 0x13C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X13C);
    // 0x80800104: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80800108: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x8080010C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800110: swc1        $f4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f4.u32l;
    // 0x80800114: jal         0x800D8FF8
    // 0x80800118: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800118: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8080011C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800120: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800124: lw          $t9, 0x13C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X13C);
    // 0x80800128: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x8080012C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800130: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800134: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080013C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void func_808001BC_chweldarbossfusebox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001BC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808001C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001CC: jal         0x800DA298
    // 0x808001D0: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808001D0: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    after_0:
    // 0x808001D4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808001D8: jal         0x800BF744
    // 0x808001DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800BF744(rdram, ctx);
        goto after_1;
    // 0x808001DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808001E0: lui         $a2, 0x4599
    ctx->r6 = S32(0X4599 << 16);
    // 0x808001E4: lui         $a3, 0xC50F
    ctx->r7 = S32(0XC50F << 16);
    // 0x808001E8: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x808001EC: ori         $a2, $a2, 0x2000
    ctx->r6 = ctx->r6 | 0X2000;
    // 0x808001F0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001F4: jal         0x800EFA4C
    // 0x808001F8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x808001F8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808001FC: jal         0x80103014
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_3;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800204: jal         0x80089D00
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080020C: jal         0x800DA298
    // 0x80800210: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800210: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    after_5:
    // 0x80800214: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x80800218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080022C;
    }
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x800FFAB0
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800224: b           L_80800258
    // 0x80800228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800258;
    // 0x80800228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080022C:
    // 0x8080022C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800230: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800234: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    // 0x80800238: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x8080023C: jal         0x8008A0C8
    // 0x80800240: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800240: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_7:
    // 0x80800244: beq         $v0, $zero, L_80800254
    if (ctx->r2 == 0) {
        // 0x80800248: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_80800254;
    }
    // 0x80800248: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080024C: jal         0x800EE7F8
    // 0x80800250: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80800250: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_8:
L_80800254:
    // 0x80800254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800258:
    // 0x80800258: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080025C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800260: jr          $ra
    // 0x80800264: nop

    return;
    // 0x80800264: nop

;}
RECOMP_FUNC void func_80801AF0_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801AF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801AF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801AFC: jal         0x8009E6EC
    // 0x80801B00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80801B00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801B04: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80801B08: bne         $v0, $at, L_80801B34
    if (ctx->r2 != ctx->r1) {
        // 0x80801B0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B34;
    }
    // 0x80801B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B10: jal         0x8009E830
    // 0x80801B14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x80801B14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80801B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B1C: jal         0x80095760
    // 0x80801B20: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baflag_set(rdram, ctx);
        goto after_2;
    // 0x80801B20: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x80801B24: jal         0x800A046C
    // 0x80801B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A046C(rdram, ctx);
        goto after_3;
    // 0x80801B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801B2C: b           L_80801B40
    // 0x80801B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B40;
    // 0x80801B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801B34:
    // 0x80801B34: jal         0x80099B94
    // 0x80801B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_4;
    // 0x80801B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801B40:
    // 0x80801B40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801B44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801B48: jr          $ra
    // 0x80801B4C: nop

    return;
    // 0x80801B4C: nop

;}
RECOMP_FUNC void _basudie_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085230: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085230);
    return;
    // 0x80085234: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800B46B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B46B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B46B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B46B8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B46BC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800B46C0: lh          $v1, 0xAC($a0)
    ctx->r3 = MEM_H(ctx->r4, 0XAC);
    // 0x800B46C4: addiu       $t0, $zero, -0x8000
    ctx->r8 = ADD32(0, -0X8000);
    // 0x800B46C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800B46CC: bnel        $t0, $v1, L_800B471C
    if (ctx->r8 != ctx->r3) {
        // 0x800B46D0: lh          $v0, 0xAE($a0)
        ctx->r2 = MEM_H(ctx->r4, 0XAE);
            goto L_800B471C;
    }
    goto skip_0;
    // 0x800B46D0: lh          $v0, 0xAE($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XAE);
    skip_0:
    // 0x800B46D4: lh          $t6, 0xAE($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XAE);
    // 0x800B46D8: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x800B46DC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x800B46E0: bnel        $t6, $at, L_800B471C
    if (ctx->r14 != ctx->r1) {
        // 0x800B46E4: lh          $v0, 0xAE($a0)
        ctx->r2 = MEM_H(ctx->r4, 0XAE);
            goto L_800B471C;
    }
    goto skip_1;
    // 0x800B46E4: lh          $v0, 0xAE($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XAE);
    skip_1:
    // 0x800B46E8: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x800B46EC: lui         $a3, 0x40
    ctx->r7 = S32(0X40 << 16);
    // 0x800B46F0: andi        $t8, $t7, 0x100
    ctx->r24 = ctx->r15 & 0X100;
    // 0x800B46F4: beq         $t8, $zero, L_800B4708
    if (ctx->r24 == 0) {
        // 0x800B46F8: nop
    
            goto L_800B4708;
    }
    // 0x800B46F8: nop

    // 0x800B46FC: lui         $a3, 0x42
    ctx->r7 = S32(0X42 << 16);
    // 0x800B4700: b           L_800B4708
    // 0x800B4704: ori         $a3, $a3, 0x21
    ctx->r7 = ctx->r7 | 0X21;
        goto L_800B4708;
    // 0x800B4704: ori         $a3, $a3, 0x21
    ctx->r7 = ctx->r7 | 0X21;
L_800B4708:
    // 0x800B4708: jal         0x800BEF00
    // 0x800B470C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800BEF00(rdram, ctx);
        goto after_0;
    // 0x800B470C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x800B4710: b           L_800B4784
    // 0x800B4714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B4784;
    // 0x800B4714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4718: lh          $v0, 0xAE($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XAE);
L_800B471C:
    // 0x800B471C: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x800B4720: beq         $v0, $at, L_800B4750
    if (ctx->r2 == ctx->r1) {
        // 0x800B4724: nop
    
            goto L_800B4750;
    }
    // 0x800B4724: nop

    // 0x800B4728: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800B472C: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800B4730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B4734: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4738: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800B473C: nop

    // 0x800B4740: bc1f        L_800B4750
    if (!c1cs) {
        // 0x800B4744: nop
    
            goto L_800B4750;
    }
    // 0x800B4744: nop

    // 0x800B4748: b           L_800B4780
    // 0x800B474C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
        goto L_800B4780;
    // 0x800B474C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
L_800B4750:
    // 0x800B4750: beq         $t0, $v1, L_800B4780
    if (ctx->r8 == ctx->r3) {
        // 0x800B4754: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B4780;
    }
    // 0x800B4754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4758: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800B475C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800B4760: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B4764: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800B4768: nop

    // 0x800B476C: bc1f        L_800B4780
    if (!c1cs) {
        // 0x800B4770: nop
    
            goto L_800B4780;
    }
    // 0x800B4770: nop

    // 0x800B4774: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800B4778: b           L_800B4780
    // 0x800B477C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B4780;
    // 0x800B477C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B4780:
    // 0x800B4780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B4784:
    // 0x800B4784: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800B4788: jr          $ra
    // 0x800B478C: nop

    return;
    // 0x800B478C: nop

;}
RECOMP_FUNC void suspline_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: jr          $ra
    // 0x808001CC: lwc1        $f0, 0x58($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
    return;
    // 0x808001CC: lwc1        $f0, 0x58($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
;}
RECOMP_FUNC void func_800D36A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D36A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D36AC: sw          $zero, -0x4A94($at)
    MEM_W(-0X4A94, ctx->r1) = 0;
    // 0x800D36B0: sw          $zero, -0x4A9C($at)
    MEM_W(-0X4A9C, ctx->r1) = 0;
    // 0x800D36B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D36B8: sw          $zero, -0x4A8C($at)
    MEM_W(-0X4A8C, ctx->r1) = 0;
    // 0x800D36BC: jr          $ra
    // 0x800D36C0: sw          $zero, -0x4A84($at)
    MEM_W(-0X4A84, ctx->r1) = 0;
    return;
    // 0x800D36C0: sw          $zero, -0x4A84($at)
    MEM_W(-0X4A84, ctx->r1) = 0;
;}
RECOMP_FUNC void gcstatusDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80800104: jr          $ra
    // 0x80800108: sb          $a0, -0x4BEF($at)
    MEM_B(-0X4BEF, ctx->r1) = ctx->r4;
    return;
    // 0x80800108: sb          $a0, -0x4BEF($at)
    MEM_B(-0X4BEF, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80803134_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803134: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80803138: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080313C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803140: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80803144: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803148: jal         0x80807BB8
    // 0x8080314C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080314C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80803150: jal         0x80808DB0
    // 0x80803154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808DB0_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80803154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80803158: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x8080315C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803160: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80803164: jal         0x8080261C
    // 0x80803168: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8080261C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80803168: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x8080316C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80803170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803174: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x80803178: jal         0x80800424
    // 0x8080317C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    func_80800424_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x8080317C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    after_3:
    // 0x80803180: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80803184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803188: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    // 0x8080318C: jal         0x8008CCBC
    // 0x80803190: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_4;
    // 0x80803190: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    after_4:
    // 0x80803194: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80803198: addiu       $a1, $a1, 0x42D8
    ctx->r5 = ADD32(ctx->r5, 0X42D8);
    // 0x8080319C: jal         0x80084A70
    // 0x808031A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggsetup_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808031A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808031A4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808031A8: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x808031AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808031B4: jal         0x800A0D94
    // 0x808031B8: sh          $t9, 0xE0($t0)
    MEM_H(0XE0, ctx->r8) = ctx->r25;
    func_800A0D94(rdram, ctx);
        goto after_6;
    // 0x808031B8: sh          $t9, 0xE0($t0)
    MEM_H(0XE0, ctx->r8) = ctx->r25;
    after_6:
    // 0x808031BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808031C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808031C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808031C8: jr          $ra
    // 0x808031CC: nop

    return;
    // 0x808031CC: nop

;}
RECOMP_FUNC void func_80800D88_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D98: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1112, 0X1460) << 16);
    // 0x80800D9C: addiu       $a1, $a1, 0x1460
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1112, 0X1460));
    // 0x80800DA0: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    // 0x80800DA4: jal         0x800882C0
    // 0x80800DA8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800DA8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80800DAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DB0: blez        $v0, L_80800DFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800DB4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800DFC;
    }
    // 0x80800DB4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800DB8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800DBC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1112, 0X1460) << 16);
    // 0x80800DC0: addiu       $v0, $v0, 0x1460
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1112, 0X1460));
    // 0x80800DC4: addiu       $a2, $a2, 0x2B
    ctx->r6 = ADD32(ctx->r6, 0X2B);
L_80800DC8:
    // 0x80800DC8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800DCC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800DD0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80800DD4: lhu         $t6, 0x6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X6);
    // 0x80800DD8: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800DDC: bne         $a2, $t7, L_80800DF4
    if (ctx->r6 != ctx->r15) {
        // 0x80800DE0: nop
    
            goto L_80800DF4;
    }
    // 0x80800DE0: nop

    // 0x80800DE4: jal         0x800EE88C
    // 0x80800DE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x80800DE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800DEC: b           L_80800E00
    // 0x80800DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800E00;
    // 0x80800DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DF4:
    // 0x80800DF4: bne         $at, $zero, L_80800DC8
    if (ctx->r1 != 0) {
        // 0x80800DF8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80800DC8;
    }
    // 0x80800DF8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80800DFC:
    // 0x80800DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E00:
    // 0x80800E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E04: jr          $ra
    // 0x80800E08: nop

    return;
    // 0x80800E08: nop

;}
RECOMP_FUNC void func_80800E74_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E7C: jal         0x8009BC6C
    // 0x80800E80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80800E80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E88: jal         0x8009BF5C
    // 0x80800E8C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x80800E8C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800E90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E94: jal         0x8009C4CC
    // 0x80800E98: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x80800E98: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800E9C: jal         0x808000F0
    // 0x80800EA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000F0_bswasher(rdram, ctx);
        goto after_3;
    // 0x80800EA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EAC: jr          $ra
    // 0x80800EB0: nop

    return;
    // 0x80800EB0: nop

;}
RECOMP_FUNC void func_808000AC_chmoley(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000BC: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x808000C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808000C8: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x808000CC: bgez        $t9, L_808000F0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808000D0: nop
    
            goto L_808000F0;
    }
    // 0x808000D0: nop

    // 0x808000D4: jal         0x800DF744
    // 0x808000D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x808000D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x808000DC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808000E0: jal         0x800DF744
    // 0x808000E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x808000E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808000E8: b           L_80800108
    // 0x808000EC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
        goto L_80800108;
    // 0x808000EC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_808000F0:
    // 0x808000F0: jal         0x800DF744
    // 0x808000F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808000F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808000F8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808000FC: jal         0x800DF744
    // 0x80800100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800104: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_80800108:
    // 0x80800108: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080010C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800110: lw          $t1, 0x64($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X64);
    // 0x80800114: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x80800118: bgez        $t3, L_80800148
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8080011C: nop
    
            goto L_80800148;
    }
    // 0x8080011C: nop

    // 0x80800120: jal         0x800DF744
    // 0x80800124: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x80800124: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // 0x80800128: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080012C: jal         0x800DF744
    // 0x80800130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x80800130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800134: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80800138: jal         0x800DF744
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_6;
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800140: b           L_8080016C
    // 0x80800144: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
        goto L_8080016C;
    // 0x80800144: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80800148:
    // 0x80800148: jal         0x800DF744
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800150: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800154: jal         0x800DF744
    // 0x80800158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_8;
    // 0x80800158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8080015C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80800160: jal         0x800DF744
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_9;
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800168: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8080016C:
    // 0x8080016C: jal         0x800DF744
    // 0x80800170: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_10;
    // 0x80800170: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800178: jal         0x80101870
    // 0x8080017C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_11;
    // 0x8080017C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_11:
    // 0x80800180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void bababykaz_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080042C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800434: jal         0x80095774
    // 0x80800438: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    baflag_clear(rdram, ctx);
        goto after_0;
    // 0x80800438: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_0:
    // 0x8080043C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800440: jal         0x8009F198
    // 0x80800444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_func_8009F198(rdram, ctx);
        goto after_1;
    // 0x80800444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080044C: jal         0x80091C74
    // 0x80800450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bakey_func_80091C74(rdram, ctx);
        goto after_2;
    // 0x80800450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080045C: jr          $ra
    // 0x80800460: nop

    return;
    // 0x80800460: nop

;}
RECOMP_FUNC void chbadshad_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(684, 0XA10) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xA10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(684, 0XA10));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xA10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(684, 0XA10));
;}
RECOMP_FUNC void func_800FFE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFE08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FFE0C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800FFE10: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800FFE14: addiu       $s3, $s3, 0x4394
    ctx->r19 = ADD32(ctx->r19, 0X4394);
    // 0x800FFE18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FFE1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FFE20: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800FFE24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FFE28: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800FFE2C: jal         0x801068A8
    // 0x800FFE30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_801068A8(rdram, ctx);
        goto after_0;
    // 0x800FFE30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800FFE34: beq         $v0, $zero, L_800FFE70
    if (ctx->r2 == 0) {
        // 0x800FFE38: addiu       $s2, $zero, 0x8
        ctx->r18 = ADD32(0, 0X8);
            goto L_800FFE70;
    }
    // 0x800FFE38: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x800FFE3C: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
L_800FFE40:
    // 0x800FFE40: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800FFE44: beq         $a0, $zero, L_800FFE58
    if (ctx->r4 == 0) {
        // 0x800FFE48: nop
    
            goto L_800FFE58;
    }
    // 0x800FFE48: nop

    // 0x800FFE4C: jal         0x800DC060
    // 0x800FFE50: nop

    func_800DC060(rdram, ctx);
        goto after_1;
    // 0x800FFE50: nop

    after_1:
    // 0x800FFE54: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_800FFE58:
    // 0x800FFE58: jal         0x80106920
    // 0x800FFE5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80106920(rdram, ctx);
        goto after_2;
    // 0x800FFE5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x800FFE60: beq         $v0, $zero, L_800FFE70
    if (ctx->r2 == 0) {
        // 0x800FFE64: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FFE70;
    }
    // 0x800FFE64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FFE68: bnel        $s1, $s2, L_800FFE40
    if (ctx->r17 != ctx->r18) {
        // 0x800FFE6C: lw          $s0, 0x0($v0)
        ctx->r16 = MEM_W(ctx->r2, 0X0);
            goto L_800FFE40;
    }
    goto skip_0;
    // 0x800FFE6C: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    skip_0:
L_800FFE70:
    // 0x800FFE70: jal         0x80106630
    // 0x800FFE74: nop

    func_80106630(rdram, ctx);
        goto after_3;
    // 0x800FFE74: nop

    after_3:
    // 0x800FFE78: jal         0x801041C8
    // 0x800FFE7C: nop

    func_801041C8(rdram, ctx);
        goto after_4;
    // 0x800FFE7C: nop

    after_4:
    // 0x800FFE80: jal         0x801043A0
    // 0x800FFE84: nop

    func_801043A0(rdram, ctx);
        goto after_5;
    // 0x800FFE84: nop

    after_5:
    // 0x800FFE88: jal         0x8010545C
    // 0x800FFE8C: nop

    func_8010545C(rdram, ctx);
        goto after_6;
    // 0x800FFE8C: nop

    after_6:
    // 0x800FFE90: jal         0x80105CD0
    // 0x800FFE94: nop

    func_80105CD0(rdram, ctx);
        goto after_7;
    // 0x800FFE94: nop

    after_7:
    // 0x800FFE98: jal         0x80106A60
    // 0x800FFE9C: nop

    func_80106A60(rdram, ctx);
        goto after_8;
    // 0x800FFE9C: nop

    after_8:
    // 0x800FFEA0: jal         0x80106E50
    // 0x800FFEA4: nop

    func_80106E50(rdram, ctx);
        goto after_9;
    // 0x800FFEA4: nop

    after_9:
    // 0x800FFEA8: jal         0x80107C10
    // 0x800FFEAC: nop

    func_80107C10(rdram, ctx);
        goto after_10;
    // 0x800FFEAC: nop

    after_10:
    // 0x800FFEB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FFEB4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FFEB8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FFEBC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFEC0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800FFEC4: jr          $ra
    // 0x800FFEC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FFEC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsdronebitten_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800544: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800548: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080054C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800550: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800554: lbu         $v0, 0x190($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X190);
    // 0x80800558: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080055C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800560: beq         $v0, $zero, L_80800578
    if (ctx->r2 == 0) {
        // 0x80800564: nop
    
            goto L_80800578;
    }
    // 0x80800564: nop

    // 0x80800568: beq         $v0, $at, L_8080064C
    if (ctx->r2 == ctx->r1) {
        // 0x8080056C: nop
    
            goto L_8080064C;
    }
    // 0x8080056C: nop

    // 0x80800570: b           L_8080066C
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080066C;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800578:
    // 0x80800578: jal         0x80084DD8
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800580: beql        $v0, $zero, L_8080066C
    if (ctx->r2 == 0) {
        // 0x80800584: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080066C;
    }
    goto skip_0;
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800588: jal         0x8009D9D4
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D9D4(rdram, ctx);
        goto after_1;
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800590: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800594: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080059C: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x808005A0: jal         0x8009DB04
    // 0x808005A4: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DB04(rdram, ctx);
        goto after_2;
    // 0x808005A4: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_2:
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808005B0: jal         0x80084FC8
    // 0x808005B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _bashake_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808005B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x808005B8: jal         0x80084A08
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808005C0: jal         0x800A1718
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_5;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808005C8: bne         $v0, $zero, L_808005E0
    if (ctx->r2 != 0) {
        // 0x808005CC: nop
    
            goto L_808005E0;
    }
    // 0x808005CC: nop

    // 0x808005D0: jal         0x800846E0
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_20(rdram, ctx);
        goto after_6;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808005D8: b           L_80800668
    // 0x808005DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_80800668;
    // 0x808005DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808005E0:
    // 0x808005E0: jal         0x800A3274
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_7;
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808005E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005EC: beq         $v0, $at, L_80800610
    if (ctx->r2 == ctx->r1) {
        // 0x808005F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800610;
    }
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808005F8: beq         $v0, $at, L_80800610
    if (ctx->r2 == ctx->r1) {
        // 0x808005FC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80800610;
    }
    // 0x808005FC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800600: beq         $v0, $at, L_80800624
    if (ctx->r2 == ctx->r1) {
        // 0x80800604: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800624;
    }
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800608: b           L_8080063C
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080063C;
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800610:
    // 0x80800610: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x80800614: jal         0x808004C4
    // 0x80800618: lui         $a2, 0x4010
    ctx->r6 = S32(0X4010 << 16);
    func_808004C4_bsdronebitten(rdram, ctx);
        goto after_8;
    // 0x80800618: lui         $a2, 0x4010
    ctx->r6 = S32(0X4010 << 16);
    after_8:
    // 0x8080061C: b           L_8080066C
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080066C;
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800624:
    // 0x80800624: lui         $a2, 0x3FCC
    ctx->r6 = S32(0X3FCC << 16);
    // 0x80800628: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080062C: jal         0x808004C4
    // 0x80800630: addiu       $a1, $zero, 0x11E
    ctx->r5 = ADD32(0, 0X11E);
    func_808004C4_bsdronebitten(rdram, ctx);
        goto after_9;
    // 0x80800630: addiu       $a1, $zero, 0x11E
    ctx->r5 = ADD32(0, 0X11E);
    after_9:
    // 0x80800634: b           L_8080066C
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080066C;
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080063C:
    // 0x8080063C: jal         0x80800478
    // 0x80800640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800478_bsdronebitten(rdram, ctx);
        goto after_10;
    // 0x80800640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800644: b           L_80800668
    // 0x80800648: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_80800668;
    // 0x80800648: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_8080064C:
    // 0x8080064C: jal         0x8008CAEC
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_11;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800654: beq         $v0, $zero, L_80800668
    if (ctx->r2 == 0) {
        // 0x80800658: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800668;
    }
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080065C: jal         0x80800478
    // 0x80800660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800478_bsdronebitten(rdram, ctx);
        goto after_12;
    // 0x80800660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800664: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800668:
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080066C:
    // 0x8080066C: jal         0x8009E5C8
    // 0x80800670: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x80800670: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x80800674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800678: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080067C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800680: jr          $ra
    // 0x80800684: nop

    return;
    // 0x80800684: nop

    // 0x80800688: nop

    // 0x8080068C: nop

;}
RECOMP_FUNC void func_8080036C_rtlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080036C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80800370: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800374: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800378: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080037C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800380: addiu       $t3, $sp, 0x54
    ctx->r11 = ADD32(ctx->r29, 0X54);
    // 0x80800384: addiu       $t4, $sp, 0x48
    ctx->r12 = ADD32(ctx->r29, 0X48);
    // 0x80800388: addiu       $t5, $sp, 0x54
    ctx->r13 = ADD32(ctx->r29, 0X54);
    // 0x8080038C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_80800390:
    // 0x80800390: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800394: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800398: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8080039C: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x808003A0: add.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x808003A4: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808003A8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808003AC: mul.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x808003B0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808003B8: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x808003BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808003C0: bc1fl       L_808003D0
    if (!c1cs) {
        // 0x808003C4: c.lt.s      $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
            goto L_808003D0;
    }
    goto skip_0;
    // 0x808003C4: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    skip_0:
    // 0x808003C8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x808003CC: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
L_808003D0:
    // 0x808003D0: nop

    // 0x808003D4: bc1fl       L_808003E4
    if (!c1cs) {
        // 0x808003D8: lh          $t0, 0x0($t1)
        ctx->r8 = MEM_H(ctx->r9, 0X0);
            goto L_808003E4;
    }
    goto skip_1;
    // 0x808003D8: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
    skip_1:
    // 0x808003DC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x808003E0: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
L_808003E4:
    // 0x808003E4: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x808003E8: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x808003EC: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x808003F0: beql        $at, $zero, L_80800400
    if (ctx->r1 == 0) {
        // 0x808003F4: slt         $at, $t2, $v1
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80800400;
    }
    goto skip_2;
    // 0x808003F4: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    skip_2:
    // 0x808003F8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x808003FC: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
L_80800400:
    // 0x80800400: beql        $at, $zero, L_80800410
    if (ctx->r1 == 0) {
        // 0x80800404: slt         $at, $a1, $t0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80800410;
    }
    goto skip_3;
    // 0x80800404: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    skip_3:
    // 0x80800408: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x8080040C: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
L_80800410:
    // 0x80800410: beq         $at, $zero, L_8080041C
    if (ctx->r1 == 0) {
        // 0x80800414: subu        $t8, $v1, $t0
        ctx->r24 = SUB32(ctx->r3, ctx->r8);
            goto L_8080041C;
    }
    // 0x80800414: subu        $t8, $v1, $t0
    ctx->r24 = SUB32(ctx->r3, ctx->r8);
    // 0x80800418: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_8080041C:
    // 0x8080041C: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800420: beql        $at, $zero, L_80800430
    if (ctx->r1 == 0) {
        // 0x80800424: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_80800430;
    }
    goto skip_4;
    // 0x80800424: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    skip_4:
    // 0x80800428: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8080042C: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
L_80800430:
    // 0x80800430: subu        $t9, $a1, $t0
    ctx->r25 = SUB32(ctx->r5, ctx->r8);
    // 0x80800434: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80800438: sw          $t8, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r24;
    // 0x8080043C: bne         $t4, $t5, L_80800390
    if (ctx->r12 != ctx->r13) {
        // 0x80800440: sw          $t9, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r25;
            goto L_80800390;
    }
    // 0x80800440: sw          $t9, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r25;
    // 0x80800444: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80800448: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8080044C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80800450: addiu       $t2, $t2, 0x5550
    ctx->r10 = ADD32(ctx->r10, 0X5550);
    // 0x80800454: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800458: bne         $at, $zero, L_8080052C
    if (ctx->r1 != 0) {
        // 0x8080045C: sw          $t2, 0x258($t2)
        MEM_W(0X258, ctx->r10) = ctx->r10;
            goto L_8080052C;
    }
    // 0x8080045C: sw          $t2, 0x258($t2)
    MEM_W(0X258, ctx->r10) = ctx->r10;
    // 0x80800460: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80800464: addiu       $t3, $t3, 0x57A8
    ctx->r11 = ADD32(ctx->r11, 0X57A8);
    // 0x80800468: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
L_8080046C:
    // 0x8080046C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80800470: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800474: bnel        $at, $zero, L_8080051C
    if (ctx->r1 != 0) {
        // 0x80800478: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_8080051C;
    }
    goto skip_5;
    // 0x80800478: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    skip_5:
    // 0x8080047C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
L_80800480:
    // 0x80800480: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80800484: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800488: bnel        $at, $zero, L_80800508
    if (ctx->r1 != 0) {
        // 0x8080048C: lw          $t7, 0x4C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X4C);
            goto L_80800508;
    }
    goto skip_6;
    // 0x8080048C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    skip_6:
    // 0x80800490: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
L_80800494:
    // 0x80800494: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800498: sll         $t9, $a2, 5
    ctx->r25 = S32(ctx->r6 << 5);
    // 0x8080049C: mflo        $t6
    ctx->r14 = lo;
    // 0x808004A0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x808004A4: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x808004A8: lhu         $t7, 0xC($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XC);
    // 0x808004AC: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x808004B0: multu       $a1, $t7
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808004B4: mflo        $t8
    ctx->r24 = lo;
    // 0x808004B8: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x808004BC: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x808004C0: lb          $t7, 0x1B($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X1B);
    // 0x808004C4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x808004C8: bltzl       $t7, L_808004F4
    if (SIGNED(ctx->r15) < 0) {
        // 0x808004CC: lw          $t9, 0x48($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X48);
            goto L_808004F4;
    }
    goto skip_7;
    // 0x808004CC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    skip_7:
    // 0x808004D0: lw          $t1, 0x258($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X258);
    // 0x808004D4: sltu        $at, $t1, $t3
    ctx->r1 = ctx->r9 < ctx->r11 ? 1 : 0;
    // 0x808004D8: beql        $at, $zero, L_808004F4
    if (ctx->r1 == 0) {
        // 0x808004DC: lw          $t9, 0x48($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X48);
            goto L_808004F4;
    }
    goto skip_8;
    // 0x808004DC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    skip_8:
    // 0x808004E0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x808004E4: lw          $t8, 0x258($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X258);
    // 0x808004E8: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x808004EC: sw          $t6, 0x258($t2)
    MEM_W(0X258, ctx->r10) = ctx->r14;
    // 0x808004F0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
L_808004F4:
    // 0x808004F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x808004F8: slt         $at, $t9, $a2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808004FC: beql        $at, $zero, L_80800494
    if (ctx->r1 == 0) {
        // 0x80800500: lhu         $t9, 0xE($v0)
        ctx->r25 = MEM_HU(ctx->r2, 0XE);
            goto L_80800494;
    }
    goto skip_9;
    // 0x80800500: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    skip_9:
    // 0x80800504: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
L_80800508:
    // 0x80800508: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8080050C: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800510: beql        $at, $zero, L_80800480
    if (ctx->r1 == 0) {
        // 0x80800514: lw          $a2, 0x54($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X54);
            goto L_80800480;
    }
    goto skip_10;
    // 0x80800514: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    skip_10:
    // 0x80800518: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
L_8080051C:
    // 0x8080051C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800520: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800524: beql        $at, $zero, L_8080046C
    if (ctx->r1 == 0) {
        // 0x80800528: lw          $a1, 0x58($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X58);
            goto L_8080046C;
    }
    goto skip_11;
    // 0x80800528: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    skip_11:
L_8080052C:
    // 0x8080052C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80800530: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80800534: lw          $t6, 0x258($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X258);
    // 0x80800538: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080053C: jr          $ra
    // 0x80800540: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    return;
    // 0x80800540: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
;}
RECOMP_FUNC void inantab_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808066C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808066C4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x808066C8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6D5C) << 16);
    // 0x808066CC: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x808066D0: lw          $v0, 0x6D5C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6D5C));
    // 0x808066D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808066D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808066DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808066E0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808066E4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808066E8: lh          $s0, 0x2($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X2);
    // 0x808066EC: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x808066F0: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x808066F4: beq         $s0, $zero, L_80806728
    if (ctx->r16 == 0) {
        // 0x808066F8: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_80806728;
    }
    // 0x808066F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808066FC: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
L_80806700:
    // 0x80806700: bne         $a3, $t9, L_80806718
    if (ctx->r7 != ctx->r25) {
        // 0x80806704: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80806718;
    }
    // 0x80806704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806708: jal         0x808064DC
    // 0x8080670C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_808064DC_inantab(rdram, ctx);
        goto after_0;
    // 0x8080670C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x80806710: b           L_8080672C
    // 0x80806714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080672C;
    // 0x80806714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806718:
    // 0x80806718: lh          $s0, 0x6($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X6);
    // 0x8080671C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80806720: bnel        $s0, $zero, L_80806700
    if (ctx->r16 != 0) {
        // 0x80806724: lh          $t9, 0x0($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X0);
            goto L_80806700;
    }
    goto skip_0;
    // 0x80806724: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    skip_0:
L_80806728:
    // 0x80806728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080672C:
    // 0x8080672C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80806730: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806734: jr          $ra
    // 0x80806738: nop

    return;
    // 0x80806738: nop

    // 0x8080673C: nop

;}
RECOMP_FUNC void bsbbarge_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800188: jal         0x8009E474
    // 0x8080018C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E474(rdram, ctx);
        goto after_0;
    // 0x8080018C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800190: jal         0x800C6DA0
    // 0x80800194: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    func_800C6DA0(rdram, ctx);
        goto after_1;
    // 0x80800194: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    after_1:
    // 0x80800198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080019C: jal         0x800A0CF4
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808001A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001A8: jal         0x80095774
    // 0x808001AC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    baflag_clear(rdram, ctx);
        goto after_3;
    // 0x808001AC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_3:
    // 0x808001B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001B4: jal         0x80084A28
    // 0x808001B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _badust_entrypoint_12(rdram, ctx);
        goto after_4;
    // 0x808001B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void basetup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void subaddietaxi_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080057C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800580: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800584: jal         0x80106790
    // 0x80800588: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800588: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080058C: jal         0x8010410C
    // 0x80800590: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_8010410C(rdram, ctx);
        goto after_1;
    // 0x80800590: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80800594: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800598: jal         0x80104248
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_2;
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808005A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808005A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005A8: jal         0x800EE7F8
    // 0x808005AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808005AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808005B0: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808005B4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808005B8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x808005BC: addiu       $a1, $a1, -0x5AD8
    ctx->r5 = ADD32(ctx->r5, -0X5AD8);
    // 0x808005C0: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
    // 0x808005C4: jal         0x8008AEE4
    // 0x808005C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8008AEE4(rdram, ctx);
        goto after_4;
    // 0x808005C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x808005CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808005D8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x808005DC: jal         0x8008AF04
    // 0x808005E0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8008AF04(rdram, ctx);
        goto after_5;
    // 0x808005E0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: jal         0x80089C98
    // 0x808005EC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808005EC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_6:
    // 0x808005F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005FC: jr          $ra
    // 0x80800600: nop

    return;
    // 0x80800600: nop

;}
RECOMP_FUNC void func_808052C8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808052C8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x808052CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808052D0: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x808052D4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808052D8: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x808052DC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808052E0: bc1t        L_80805378
    if (c1cs) {
        // 0x808052E4: nop
    
            goto L_80805378;
    }
    // 0x808052E4: nop

    // 0x808052E8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808052EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808052F0: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x808052F4: nop

    // 0x808052F8: bc1t        L_80805370
    if (c1cs) {
        // 0x808052FC: nop
    
            goto L_80805370;
    }
    // 0x808052FC: nop

    // 0x80805300: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80805304: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80805308: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8080530C: bc1fl       L_80805320
    if (!c1cs) {
        // 0x80805310: lwc1        $f4, 0x8($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
            goto L_80805320;
    }
    goto skip_0;
    // 0x80805310: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    skip_0:
    // 0x80805314: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80805318: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x8080531C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
L_80805320:
    // 0x80805320: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80805324: div.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80805328: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x8080532C: nop

    // 0x80805330: bc1f        L_80805340
    if (!c1cs) {
        // 0x80805334: nop
    
            goto L_80805340;
    }
    // 0x80805334: nop

    // 0x80805338: b           L_8080534C
    // 0x8080533C: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
        goto L_8080534C;
    // 0x8080533C: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
L_80805340:
    // 0x80805340: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80805344: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
    // 0x80805348: add.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f8.fl;
L_8080534C:
    // 0x8080534C: add.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80805350: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80805354: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80805358: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8080535C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80805360: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80805364: sub.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80805368: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8080536C: add.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f8.fl;
L_80805370:
    // 0x80805370: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80805374: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
L_80805378:
    // 0x80805378: jr          $ra
    // 0x8080537C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8080537C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_808006DC_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808006E0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808006E4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808006E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006EC: jal         0x8008CABC
    // 0x808006F0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808006F0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    after_0:
    // 0x808006F4: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x808006F8: jal         0x800852C0
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800700: jal         0x800852C8
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800708: jal         0x800852D0
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800710: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800714: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800718: jal         0x8008B348
    // 0x8080071C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x8080071C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x80800720: beq         $v0, $zero, L_8080072C
    if (ctx->r2 == 0) {
        // 0x80800724: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8080072C;
    }
    // 0x80800724: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800728: sb          $t6, 0x166($s0)
    MEM_B(0X166, ctx->r16) = ctx->r14;
L_8080072C:
    // 0x8080072C: jal         0x8001210C
    // 0x80800730: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_5;
    // 0x80800730: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80800734: bne         $v0, $zero, L_808007A4
    if (ctx->r2 != 0) {
        // 0x80800738: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007A4;
    }
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080073C: jal         0x8009C128
    // 0x80800740: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8009C128(rdram, ctx);
        goto after_6;
    // 0x80800740: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x80800744: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800748: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080074C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800754: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800758: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080075C: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x80800760: jal         0x8009FBB0
    // 0x80800764: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    func_8009FBB0(rdram, ctx);
        goto after_7;
    // 0x80800764: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x80800768: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8080076C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80800770: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x80800774: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800778: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8080077C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800780: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800784: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800788: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x8080078C: addiu       $a2, $zero, -0x32
    ctx->r6 = ADD32(0, -0X32);
    // 0x80800790: jal         0x800BA930
    // 0x80800794: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    func_800BA930(rdram, ctx);
        goto after_8;
    // 0x80800794: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    after_8:
    // 0x80800798: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8080079C: jal         0x800BA22C
    // 0x808007A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_9;
    // 0x808007A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_808007A4:
    // 0x808007A4: lui         $a1, 0x3DA3
    ctx->r5 = S32(0X3DA3 << 16);
    // 0x808007A8: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x808007AC: jal         0x8008B348
    // 0x808007B0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x808007B0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_10:
    // 0x808007B4: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x808007B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007EC;
    }
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007BC: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808007C0: lui         $a3, 0x3FB3
    ctx->r7 = S32(0X3FB3 << 16);
    // 0x808007C4: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808007C8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D0: jal         0x8009DE74
    // 0x808007D4: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    func_8009DE74(rdram, ctx);
        goto after_11;
    // 0x808007D4: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    after_11:
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007DC: jal         0x800852B8
    // 0x808007E0: lui         $a1, 0x4461
    ctx->r5 = S32(0X4461 << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_12;
    // 0x808007E0: lui         $a1, 0x4461
    ctx->r5 = S32(0X4461 << 16);
    after_12:
    // 0x808007E4: b           L_808007F4
    // 0x808007E8: nop

        goto L_808007F4;
    // 0x808007E8: nop

L_808007EC:
    // 0x808007EC: jal         0x800852B8
    // 0x808007F0: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_13;
    // 0x808007F0: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_13:
L_808007F4:
    // 0x808007F4: jal         0x80085280
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808007FC: beq         $v0, $zero, L_80800828
    if (ctx->r2 == 0) {
        // 0x80800800: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80800828;
    }
    // 0x80800800: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800804: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800808: beq         $v0, $at, L_80800844
    if (ctx->r2 == ctx->r1) {
        // 0x8080080C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800844;
    }
    // 0x8080080C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800810: beq         $v0, $at, L_8080085C
    if (ctx->r2 == ctx->r1) {
        // 0x80800814: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080085C;
    }
    // 0x80800814: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800818: beq         $v0, $at, L_80800870
    if (ctx->r2 == ctx->r1) {
        // 0x8080081C: nop
    
            goto L_80800870;
    }
    // 0x8080081C: nop

    // 0x80800820: b           L_80800870
    // 0x80800824: nop

        goto L_80800870;
    // 0x80800824: nop

L_80800828:
    // 0x80800828: lui         $a1, 0x3EF5
    ctx->r5 = S32(0X3EF5 << 16);
    // 0x8080082C: jal         0x8008B348
    // 0x80800830: ori         $a1, $a1, 0x4C98
    ctx->r5 = ctx->r5 | 0X4C98;
    anctrl_isAt(rdram, ctx);
        goto after_15;
    // 0x80800830: ori         $a1, $a1, 0x4C98
    ctx->r5 = ctx->r5 | 0X4C98;
    after_15:
    // 0x80800834: beq         $v0, $zero, L_80800870
    if (ctx->r2 == 0) {
        // 0x80800838: addiu       $t0, $zero, 0x2B
        ctx->r8 = ADD32(0, 0X2B);
            goto L_80800870;
    }
    // 0x80800838: addiu       $t0, $zero, 0x2B
    ctx->r8 = ADD32(0, 0X2B);
    // 0x8080083C: b           L_80800870
    // 0x80800840: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
        goto L_80800870;
    // 0x80800840: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_80800844:
    // 0x80800844: lbu         $t1, 0x166($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X166);
    // 0x80800848: addiu       $t2, $zero, 0x39
    ctx->r10 = ADD32(0, 0X39);
    // 0x8080084C: beq         $t1, $zero, L_80800870
    if (ctx->r9 == 0) {
        // 0x80800850: nop
    
            goto L_80800870;
    }
    // 0x80800850: nop

    // 0x80800854: b           L_80800870
    // 0x80800858: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
        goto L_80800870;
    // 0x80800858: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_8080085C:
    // 0x8080085C: lbu         $t3, 0x166($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X166);
    // 0x80800860: addiu       $t4, $zero, 0x2C
    ctx->r12 = ADD32(0, 0X2C);
    // 0x80800864: beq         $t3, $zero, L_80800870
    if (ctx->r11 == 0) {
        // 0x80800868: nop
    
            goto L_80800870;
    }
    // 0x80800868: nop

    // 0x8080086C: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
L_80800870:
    // 0x80800870: jal         0x8009803C
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_8009803C(rdram, ctx);
        goto after_16;
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800878: beq         $v0, $zero, L_80800884
    if (ctx->r2 == 0) {
        // 0x8080087C: addiu       $t5, $zero, 0x157
        ctx->r13 = ADD32(0, 0X157);
            goto L_80800884;
    }
    // 0x8080087C: addiu       $t5, $zero, 0x157
    ctx->r13 = ADD32(0, 0X157);
    // 0x80800880: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_80800884:
    // 0x80800884: jal         0x80085278
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080088C: beq         $v0, $zero, L_80800898
    if (ctx->r2 == 0) {
        // 0x80800890: addiu       $t6, $zero, 0x2D
        ctx->r14 = ADD32(0, 0X2D);
            goto L_80800898;
    }
    // 0x80800890: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x80800894: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_80800898:
    // 0x80800898: jal         0x8008E35C
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_18;
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808008A0: bne         $v0, $zero, L_808008B0
    if (ctx->r2 != 0) {
        // 0x808008A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008B0;
    }
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808008AC: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_808008B0:
    // 0x808008B0: jal         0x8009E5C8
    // 0x808008B4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x808008B4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_19:
    // 0x808008B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808008BC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808008C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808008C4: jr          $ra
    // 0x808008C8: nop

    return;
    // 0x808008C8: nop

;}
RECOMP_FUNC void func_808036D0_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808036D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808036D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808036DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808036E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808036E4: jal         0x80100094
    // 0x808036E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808036E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808036EC: lui         $a1, 0x3F70
    ctx->r5 = S32(0X3F70 << 16);
    // 0x808036F0: ori         $a1, $a1, 0xA300
    ctx->r5 = ctx->r5 | 0XA300;
    // 0x808036F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808036F8: jal         0x80105998
    // 0x808036FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80105998(rdram, ctx);
        goto after_1;
    // 0x808036FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80803700: beq         $v0, $zero, L_80803720
    if (ctx->r2 == 0) {
        // 0x80803704: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80803720;
    }
    // 0x80803704: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80803708: sb          $zero, 0x8F8($v1)
    MEM_B(0X8F8, ctx->r3) = 0;
    // 0x8080370C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80803710: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803714: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80803718: jal         0x80800998
    // 0x8080371C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    func_80800998_chhandcart(rdram, ctx);
        goto after_2;
    // 0x8080371C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    after_2:
L_80803720:
    // 0x80803720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803728: jr          $ra
    // 0x8080372C: nop

    return;
    // 0x8080372C: nop

;}
RECOMP_FUNC void _choctopus_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F38: syscall     262
    recomp_syscall_handler(rdram, ctx, 0x80085F38);
    return;
    // 0x80085F3C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chweather_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(732, 0X518) << 16);
    // 0x80800100: jr          $ra
    // 0x80800104: addiu       $v0, $v0, 0x518
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X518));
    return;
    // 0x80800104: addiu       $v0, $v0, 0x518
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X518));
;}
RECOMP_FUNC void func_808000CC_chcaptainblubber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D8: jal         0x80088848
    // 0x808000DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808000DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000E0: beq         $v0, $zero, L_8080010C
    if (ctx->r2 == 0) {
        // 0x808000E4: addiu       $a0, $zero, 0x299
        ctx->r4 = ADD32(0, 0X299);
            goto L_8080010C;
    }
    // 0x808000E4: addiu       $a0, $zero, 0x299
    ctx->r4 = ADD32(0, 0X299);
    // 0x808000E8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2228, 0X16CC) << 16);
    // 0x808000EC: addiu       $a1, $a1, 0x16CC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2228, 0X16CC));
    // 0x808000F0: jal         0x800EE7F8
    // 0x808000F4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808000F4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: jal         0x80102424
    // 0x80800100: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800100: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_2:
    // 0x80800104: b           L_808001E0
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001E0;
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080010C:
    // 0x8080010C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800110: jal         0x80088280
    // 0x80800114: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800114: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_3:
    // 0x80800118: bne         $v0, $zero, L_80800130
    if (ctx->r2 != 0) {
        // 0x8080011C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800130;
    }
    // 0x8080011C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800120: jal         0x800FFA88
    // 0x80800124: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_4;
    // 0x80800124: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80800128: b           L_808001E0
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001E0;
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800130:
    // 0x80800130: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800134: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800138: jal         0x80088C00
    // 0x8080013C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x8080013C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_5:
    // 0x80800140: jal         0x80088C08
    // 0x80800144: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x80800144: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80800148: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8080014C: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x80800150: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800154: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80800158: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
    // 0x8080015C: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x80800160: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800164: jal         0x800EEAD4
    // 0x80800168: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800EEAD4(rdram, ctx);
        goto after_7;
    // 0x80800168: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x8080016C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1500) << 16);
    // 0x80800170: lwc1        $f8, 0x1500($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1500));
    // 0x80800174: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x80800178: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8080017C: nop

    // 0x80800180: bc1fl       L_8080019C
    if (!c1cs) {
        // 0x80800184: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8080019C;
    }
    goto skip_0;
    // 0x80800184: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_0:
    // 0x80800188: jal         0x800FFA88
    // 0x8080018C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_8;
    // 0x8080018C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x80800190: b           L_808001E0
    // 0x80800194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001E0;
    // 0x80800194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800198: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8080019C:
    // 0x8080019C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808001A0: lui         $at, 0xC204
    ctx->r1 = S32(0XC204 << 16);
    // 0x808001A4: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808001A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001AC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808001B0: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x808001B4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808001B8: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    // 0x808001BC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808001C0: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x808001C4: jal         0x800DA298
    // 0x808001C8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808001C8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_9:
    // 0x808001CC: beq         $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001DC;
    }
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: jal         0x80108B04
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_10;
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_808001DC:
    // 0x808001DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001E0:
    // 0x808001E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001E8: jr          $ra
    // 0x808001EC: nop

    return;
    // 0x808001EC: nop

;}
RECOMP_FUNC void _glgamedata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088580: syscall     693
    recomp_syscall_handler(rdram, ctx, 0x80088580);
    return;
    // 0x80088584: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801EA0_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801EA4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801EA8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80801EAC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80801EB0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801EB4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801EB8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80801EBC: jal         0x80100094
    // 0x80801EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801EC4: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    // 0x80801EC8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80801ECC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801ED0: blez        $t6, L_80801F2C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80801ED4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80801F2C;
    }
    // 0x80801ED4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801ED8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801EDC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80801EE0: addiu       $s2, $v0, 0x70
    ctx->r18 = ADD32(ctx->r2, 0X70);
L_80801EE4:
    // 0x80801EE4: lwc1        $f4, 0x80($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80801EE8: addiu       $a0, $zero, 0x234
    ctx->r4 = ADD32(0, 0X234);
    // 0x80801EEC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80801EF0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801EF4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80801EF8: jal         0x80108474
    // 0x80801EFC: nop

    func_80108474(rdram, ctx);
        goto after_1;
    // 0x80801EFC: nop

    after_1:
    // 0x80801F00: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801F04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801F08: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80801F0C: jal         0x800862E0
    // 0x80801F10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chappearfx_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80801F10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x80801F14: lw          $t8, 0x6C($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X6C);
    // 0x80801F18: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801F1C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80801F20: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80801F24: bne         $at, $zero, L_80801EE4
    if (ctx->r1 != 0) {
        // 0x80801F28: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_80801EE4;
    }
    // 0x80801F28: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
L_80801F2C:
    // 0x80801F2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801F30: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80801F34: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801F38: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801F3C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80801F40: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80801F44: jr          $ra
    // 0x80801F48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801F48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bsswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D90: syscall     94
    recomp_syscall_handler(rdram, ctx, 0x80083D90);
    return;
    // 0x80083D94: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80115A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115A9C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80115AA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80115AA4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80115AA8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80115AAC: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80115AB0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80115AB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80115AB8: sb          $zero, 0x12($t6)
    MEM_B(0X12, ctx->r14) = 0;
    // 0x80115ABC: lw          $s0, 0x3C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X3C);
    // 0x80115AC0: lbu         $t7, 0x12($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X12);
    // 0x80115AC4: sb          $t7, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r15;
    // 0x80115AC8: lw          $s0, 0x3C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X3C);
    // 0x80115ACC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80115AD0: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80115AD4: beq         $v0, $at, L_80115AEC
    if (ctx->r2 == ctx->r1) {
        // 0x80115AD8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80115AEC;
    }
    // 0x80115AD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80115ADC: beq         $v0, $at, L_80115B00
    if (ctx->r2 == ctx->r1) {
        // 0x80115AE0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80115B00;
    }
    // 0x80115AE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80115AE4: b           L_80115B14
    // 0x80115AE8: lbu         $t8, 0x1D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1D);
        goto L_80115B14;
    // 0x80115AE8: lbu         $t8, 0x1D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1D);
L_80115AEC:
    // 0x80115AEC: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x80115AF0: jal         0x80115828
    // 0x80115AF4: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    func_80115828(rdram, ctx);
        goto after_0;
    // 0x80115AF4: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    after_0:
    // 0x80115AF8: b           L_80115B10
    // 0x80115AFC: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
        goto L_80115B10;
    // 0x80115AFC: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
L_80115B00:
    // 0x80115B00: lui         $a1, 0xC2A0
    ctx->r5 = S32(0XC2A0 << 16);
    // 0x80115B04: jal         0x80115828
    // 0x80115B08: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_80115828(rdram, ctx);
        goto after_1;
    // 0x80115B08: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_1:
    // 0x80115B0C: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
L_80115B10:
    // 0x80115B10: lbu         $t8, 0x1D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1D);
L_80115B14:
    // 0x80115B14: beql        $t8, $zero, L_80115C30
    if (ctx->r24 == 0) {
        // 0x80115B18: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80115C30;
    }
    goto skip_0;
    // 0x80115B18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80115B1C: jal         0x800D8FF8
    // 0x80115B20: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80115B20: nop

    after_2:
    // 0x80115B24: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
    // 0x80115B28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80115B2C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80115B30: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80115B34: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80115B38: jal         0x801158CC
    // 0x80115B3C: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    func_801158CC(rdram, ctx);
        goto after_3;
    // 0x80115B3C: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x80115B40: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x80115B44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80115B48: jal         0x801107F0
    // 0x80115B4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_801107F0(rdram, ctx);
        goto after_4;
    // 0x80115B4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80115B50: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80115B54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80115B58: jal         0x800EFB24
    // 0x80115B5C: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x80115B5C: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_5:
    // 0x80115B60: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80115B64: jal         0x800F1A88
    // 0x80115B68: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F1A88(rdram, ctx);
        goto after_6;
    // 0x80115B68: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x80115B6C: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
    // 0x80115B70: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80115B74: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80115B78: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80115B7C: nop

    // 0x80115B80: bc1fl       L_80115B98
    if (!c1cs) {
        // 0x80115B84: lwc1        $f18, 0x20($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
            goto L_80115B98;
    }
    goto skip_1;
    // 0x80115B84: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    skip_1:
    // 0x80115B88: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80115B8C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80115B90: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
    // 0x80115B94: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
L_80115B98:
    // 0x80115B98: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80115B9C: jal         0x800F2100
    // 0x80115BA0: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    mlAbsF(rdram, ctx);
        goto after_7;
    // 0x80115BA0: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_7:
    // 0x80115BA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80115BA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80115BAC: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80115BB0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80115BB4: nop

    // 0x80115BB8: bc1fl       L_80115BC8
    if (!c1cs) {
        // 0x80115BBC: sw          $t9, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r25;
            goto L_80115BC8;
    }
    goto skip_2;
    // 0x80115BBC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    skip_2:
    // 0x80115BC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80115BC4: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_80115BC8:
    // 0x80115BC8: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
    // 0x80115BCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80115BD0: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80115BD4: jal         0x80115828
    // 0x80115BD8: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    func_80115828(rdram, ctx);
        goto after_8;
    // 0x80115BD8: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    after_8:
    // 0x80115BDC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80115BE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80115BE4: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
    // 0x80115BE8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80115BEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80115BF0: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80115BF4: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    // 0x80115BF8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80115BFC: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    // 0x80115C00: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x80115C04: jal         0x801158EC
    // 0x80115C08: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_801158EC(rdram, ctx);
        goto after_9;
    // 0x80115C08: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80115C0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80115C10: jal         0x801160DC
    // 0x80115C14: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_801160DC(rdram, ctx);
        goto after_10;
    // 0x80115C14: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x80115C18: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80115C1C: beql        $t0, $zero, L_80115C30
    if (ctx->r8 == 0) {
        // 0x80115C20: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80115C30;
    }
    goto skip_3;
    // 0x80115C20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80115C24: lw          $t1, 0x3C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X3C);
    // 0x80115C28: sb          $zero, 0x1D($t1)
    MEM_B(0X1D, ctx->r9) = 0;
    // 0x80115C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80115C30:
    // 0x80115C30: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80115C34: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80115C38: jr          $ra
    // 0x80115C3C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80115C3C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void gcnewoption_entrypoint_38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802BC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802BC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802BCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802BD0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80802BD4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80802BD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802BDC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80802BE0: beq         $v0, $at, L_80802BF4
    if (ctx->r2 == ctx->r1) {
        // 0x80802BE4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802BF4;
    }
    // 0x80802BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802BE8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80802BEC: bnel        $v0, $at, L_80802C54
    if (ctx->r2 != ctx->r1) {
        // 0x80802BF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80802C54;
    }
    goto skip_0;
    // 0x80802BF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80802BF4:
    // 0x80802BF4: jal         0x80800038
    // 0x80802BF8: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    func_80800038_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80802BF8: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    after_0:
    // 0x80802BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C00: jal         0x80800000
    // 0x80802C04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_1;
    // 0x80802C04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80802C08: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80802C0C: jal         0x80802A9C
    // 0x80802C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802A9C_gcnewoption(rdram, ctx);
        goto after_2;
    // 0x80802C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802C14: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80802C18: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x80802C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C20: jal         0x80802B24
    // 0x80802C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802B24_gcnewoption(rdram, ctx);
        goto after_3;
    // 0x80802C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80802C28: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80802C2C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80802C30: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80802C34: beq         $t7, $zero, L_80802C48
    if (ctx->r15 == 0) {
        // 0x80802C38: sll         $t9, $t8, 2
        ctx->r25 = S32(ctx->r24 << 2);
            goto L_80802C48;
    }
    // 0x80802C38: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80802C3C: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80802C40: jal         0x80087C28
    // 0x80802C44: lw          $a0, 0x3C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X3C);
    _gczoombox_entrypoint_41(rdram, ctx);
        goto after_4;
    // 0x80802C44: lw          $a0, 0x3C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X3C);
    after_4:
L_80802C48:
    // 0x80802C48: b           L_80802C54
    // 0x80802C4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802C54;
    // 0x80802C4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802C50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802C54:
    // 0x80802C54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802C58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802C5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802C60: jr          $ra
    // 0x80802C64: nop

    return;
    // 0x80802C64: nop

;}
RECOMP_FUNC void _badrone_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848D8: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800848D8);
    return;
    // 0x800848DC: addi        $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
;}
RECOMP_FUNC void func_8001A0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A0F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A0F8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A0FC: addiu       $a0, $a0, -0x4120
    ctx->r4 = ADD32(ctx->r4, -0X4120);
    // 0x8001A100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A104: jal         0x8002E1F0
    // 0x8001A108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001A108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8001A10C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A114: jr          $ra
    // 0x8001A118: nop

    return;
    // 0x8001A118: nop

;}
RECOMP_FUNC void func_8080000C_ch1pfreeze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800F2094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F2098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F209C: jal         0x800F1DCC
    // 0x800F20A0: nop

    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x800F20A0: nop

    after_0:
    // 0x800F20A4: jal         0x800F2100
    // 0x800F20A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800F20A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x800F20AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F20B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F20B4: jr          $ra
    // 0x800F20B8: nop

    return;
    // 0x800F20B8: nop

;}
RECOMP_FUNC void func_8009DE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DE74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009DE78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DE7C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009DE80: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8009DE84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009DE88: jal         0x800DC178
    // 0x8009DE8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8009DE8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009DE90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8009DE94: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8009DE98: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x8009DE9C: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009DEA0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8009DEA4: lbu         $a1, 0x2($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X2);
    // 0x8009DEA8: jal         0x8009DCCC
    // 0x8009DEAC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8009DCCC(rdram, ctx);
        goto after_1;
    // 0x8009DEAC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x8009DEB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DEB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009DEB8: jr          $ra
    // 0x8009DEBC: nop

    return;
    // 0x8009DEBC: nop

;}
RECOMP_FUNC void func_800CA3F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA3F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CA3F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800CA3FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800CA400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA404: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800CA408: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800CA40C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800CA410: jal         0x800EFB24
    // 0x800CA414: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800CA414: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800CA418: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800CA41C: jal         0x800EF368
    // 0x800CA420: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EF368(rdram, ctx);
        goto after_1;
    // 0x800CA420: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800CA424: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800CA428: jal         0x800EF04C
    // 0x800CA42C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x800CA42C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x800CA430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA434: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CA438: jr          $ra
    // 0x800CA43C: nop

    return;
    // 0x800CA43C: nop

;}
RECOMP_FUNC void func_80801898_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080189C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018A0: jal         0x80800128
    // 0x808018A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800128_bskazfly(rdram, ctx);
        goto after_0;
    // 0x808018A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808018A8: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x808018AC: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808018B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808018B8: jal         0x80084C30
    // 0x808018BC: addiu       $a2, $zero, 0x11C
    ctx->r6 = ADD32(0, 0X11C);
    _bafly_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808018BC: addiu       $a2, $zero, 0x11C
    ctx->r6 = ADD32(0, 0X11C);
    after_1:
    // 0x808018C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018C8: jr          $ra
    // 0x808018CC: nop

    return;
    // 0x808018CC: nop

;}
RECOMP_FUNC void func_80024E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024E90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024E98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80024E9C: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x80024EA0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80024EA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80024EA8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80024EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80024EB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80024EB4: jal         0x80026500
    // 0x80024EB8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x80024EB8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x80024EBC: b           L_80024EC4
    // 0x80024EC0: nop

        goto L_80024EC4;
    // 0x80024EC0: nop

L_80024EC4:
    // 0x80024EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024EC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80024ECC: jr          $ra
    // 0x80024ED0: nop

    return;
    // 0x80024ED0: nop

    // 0x80024ED4: nop

    // 0x80024ED8: nop

    // 0x80024EDC: nop

;}
RECOMP_FUNC void func_80019750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019758: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001975C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80019760: beq         $a0, $zero, L_80019778
    if (ctx->r4 == 0) {
        // 0x80019764: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_80019778;
    }
    // 0x80019764: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80019768: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001976C: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019770: jal         0x80019C84
    // 0x80019774: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    mlMtxTranslate(rdram, ctx);
        goto after_0;
    // 0x80019774: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    after_0:
L_80019778:
    // 0x80019778: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001977C: beql        $t6, $zero, L_800197A8
    if (ctx->r14 == 0) {
        // 0x80019780: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800197A8;
    }
    goto skip_0;
    // 0x80019780: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80019784: jal         0x80018FE8
    // 0x80019788: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    mlMtxRotYaw(rdram, ctx);
        goto after_1;
    // 0x80019788: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    after_1:
    // 0x8001978C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80019790: jal         0x80018F50
    // 0x80019794: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    mlMtxRotPitch(rdram, ctx);
        goto after_2;
    // 0x80019794: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x80019798: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8001979C: jal         0x8001907C
    // 0x800197A0: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    mlMtxRotRoll(rdram, ctx);
        goto after_3;
    // 0x800197A0: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    after_3:
    // 0x800197A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800197A8:
    // 0x800197A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800197AC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800197B0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800197B4: nop

    // 0x800197B8: bc1tl       L_800197D4
    if (c1cs) {
        // 0x800197BC: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_800197D4;
    }
    goto skip_1;
    // 0x800197BC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800197C0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800197C4: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x800197C8: jal         0x80019D30
    // 0x800197CC: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    mlMtxScale_xyz(rdram, ctx);
        goto after_4;
    // 0x800197CC: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    after_4:
    // 0x800197D0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_800197D4:
    // 0x800197D4: beql        $t9, $zero, L_80019800
    if (ctx->r25 == 0) {
        // 0x800197D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80019800;
    }
    goto skip_2;
    // 0x800197D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800197DC: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800197E0: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800197E4: lwc1        $f14, 0x4($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800197E8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800197EC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800197F0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800197F4: jal         0x80019C84
    // 0x800197F8: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    mlMtxTranslate(rdram, ctx);
        goto after_5;
    // 0x800197F8: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_5:
    // 0x800197FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80019800:
    // 0x80019800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019804: jr          $ra
    // 0x80019808: nop

    return;
    // 0x80019808: nop

;}
RECOMP_FUNC void bsjig_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080059C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(212, 0X5C0) << 16);
    // 0x808005A4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005A8: jr          $ra
    // 0x808005AC: lw          $v0, 0x5C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(212, 0X5C0));
    return;
    // 0x808005AC: lw          $v0, 0x5C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(212, 0X5C0));
;}
RECOMP_FUNC void func_800D2748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D274C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2750: jal         0x800D21D0
    // 0x800D2754: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D21D0(rdram, ctx);
        goto after_0;
    // 0x800D2754: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D2758: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800D275C: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    // 0x800D2760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2768: jr          $ra
    // 0x800D276C: nop

    return;
    // 0x800D276C: nop

;}
RECOMP_FUNC void fxstep_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080055C: sw          $a1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r5;
    // 0x80800560: jr          $ra
    // 0x80800564: sw          $a2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r6;
    return;
    // 0x80800564: sw          $a2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r6;
;}
