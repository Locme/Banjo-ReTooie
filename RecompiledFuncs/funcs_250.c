#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _sccustom_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A678: syscall     846
    recomp_syscall_handler(rdram, ctx, 0x8008A678);
    return;
    // 0x8008A67C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808057D0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808057D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808057D4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808057D8: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x808057DC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x808057E0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808057E4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x808057E8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808057EC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808057F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808057F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808057F8: jal         0x80100094
    // 0x808057FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808057FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80805800: lui         $s6, 0x8081
    ctx->r22 = S32(RELOC_HI16(1480, 0XA06C) << 16);
    // 0x80805804: addiu       $s6, $s6, -0x5F94
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(1480, 0XA06C));
    // 0x80805808: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8080580C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80805810: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x80805814: addiu       $s5, $zero, 0x70
    ctx->r21 = ADD32(0, 0X70);
    // 0x80805818: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_8080581C:
    // 0x8080581C: lh          $t6, 0x34($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X34);
    // 0x80805820: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80805824: bne         $s4, $t6, L_80805834
    if (ctx->r20 != ctx->r14) {
        // 0x80805828: nop
    
            goto L_80805834;
    }
    // 0x80805828: nop

    // 0x8080582C: b           L_80805834
    // 0x80805830: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
        goto L_80805834;
    // 0x80805830: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
L_80805834:
    // 0x80805834: lw          $s1, 0x30($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X30);
    // 0x80805838: beq         $s1, $zero, L_80805878
    if (ctx->r17 == 0) {
        // 0x8080583C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80805878;
    }
    // 0x8080583C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805840: jal         0x800C8FE0
    // 0x80805844: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_1;
    // 0x80805844: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80805848: beq         $s0, $zero, L_80805878
    if (ctx->r16 == 0) {
        // 0x8080584C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80805878;
    }
    // 0x8080584C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805850: jal         0x800C8CB8
    // 0x80805854: addiu       $a1, $s2, 0x3C
    ctx->r5 = ADD32(ctx->r18, 0X3C);
    func_800C8CB8(rdram, ctx);
        goto after_2;
    // 0x80805854: addiu       $a1, $s2, 0x3C
    ctx->r5 = ADD32(ctx->r18, 0X3C);
    after_2:
    // 0x80805858: jal         0x8001210C
    // 0x8080585C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8001210C(rdram, ctx);
        goto after_3;
    // 0x8080585C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x80805860: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80805864: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805868: mflo        $t7
    ctx->r15 = lo;
    // 0x8080586C: addu        $a1, $s6, $t7
    ctx->r5 = ADD32(ctx->r22, ctx->r15);
    // 0x80805870: jal         0x800C8E84
    // 0x80805874: nop

    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x80805874: nop

    after_4:
L_80805878:
    // 0x80805878: addiu       $s3, $s3, 0x1C
    ctx->r19 = ADD32(ctx->r19, 0X1C);
    // 0x8080587C: bne         $s3, $s5, L_8080581C
    if (ctx->r19 != ctx->r21) {
        // 0x80805880: addiu       $s2, $s2, 0x1C
        ctx->r18 = ADD32(ctx->r18, 0X1C);
            goto L_8080581C;
    }
    // 0x80805880: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x80805884: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80805888: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080588C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80805890: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80805894: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80805898: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8080589C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808058A0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x808058A4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x808058A8: jr          $ra
    // 0x808058AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808058AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808039B8_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808039B8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808039BC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808039C0: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x808039C4: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x808039C8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x808039CC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x808039D0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808039D4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808039D8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808039DC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808039E0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808039E4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808039E8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x808039EC: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x808039F0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808039F4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x808039F8: beq         $s7, $t6, L_80803ABC
    if (ctx->r23 == ctx->r14) {
        // 0x808039FC: or          $s6, $a2, $zero
        ctx->r22 = ctx->r6 | 0;
            goto L_80803ABC;
    }
    // 0x808039FC: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80803A00: lui         $fp, 0x8080
    ctx->r30 = S32(RELOC_HI16(1692, 0X46B0) << 16);
    // 0x80803A04: addiu       $fp, $fp, 0x46B0
    ctx->r30 = ADD32(ctx->r30, (int16_t)RELOC_LO16(1692, 0X46B0));
    // 0x80803A08: lw          $s3, 0x68($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X68);
    // 0x80803A0C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80803A10: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80803A14: lwc1        $f20, 0x6C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80803A18: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80803A1C: addiu       $t7, $s3, -0x1
    ctx->r15 = ADD32(ctx->r19, -0X1);
L_80803A20:
    // 0x80803A20: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80803A24: beq         $at, $zero, L_80803A88
    if (ctx->r1 == 0) {
        // 0x80803A28: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80803A88;
    }
    // 0x80803A28: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80803A2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4244) << 16);
    // 0x80803A30: addu        $at, $at, $t7
    gpr jr_addend_80803A38 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80803A34: lw          $t7, 0x4244($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4244));
    // 0x80803A38: jr          $t7
    // 0x80803A3C: nop

    switch (jr_addend_80803A38 >> 2) {
        case 0: goto L_80803A40; break;
        case 1: goto L_80803A54; break;
        case 2: goto L_80803A60; break;
        case 3: goto L_80803A6C; break;
        case 4: goto L_80803A78; break;
        default: switch_error(__func__, 0x80803A38, 0x80804244);
    }
    // 0x80803A3C: nop

L_80803A40:
    // 0x80803A40: jal         0x80803844
    // 0x80803A44: nop

    func_80803844_chflysaucer(rdram, ctx);
        goto after_0;
    // 0x80803A44: nop

    after_0:
    // 0x80803A48: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80803A4C: b           L_80803A8C
    // 0x80803A50: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
        goto L_80803A8C;
    // 0x80803A50: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_80803A54:
    // 0x80803A54: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80803A58: b           L_80803A8C
    // 0x80803A5C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
        goto L_80803A8C;
    // 0x80803A5C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_80803A60:
    // 0x80803A60: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80803A64: b           L_80803A8C
    // 0x80803A68: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
        goto L_80803A8C;
    // 0x80803A68: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_80803A6C:
    // 0x80803A6C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80803A70: b           L_80803A8C
    // 0x80803A74: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
        goto L_80803A8C;
    // 0x80803A74: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_80803A78:
    // 0x80803A78: addu        $t8, $fp, $s2
    ctx->r24 = ADD32(ctx->r30, ctx->r18);
    // 0x80803A7C: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x80803A80: b           L_80803A8C
    // 0x80803A84: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
        goto L_80803A8C;
    // 0x80803A84: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_80803A88:
    // 0x80803A88: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_80803A8C:
    // 0x80803A8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80803A90: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80803A94: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80803A98: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80803A9C: jal         0x808038C4
    // 0x80803AA0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_808038C4_chflysaucer(rdram, ctx);
        goto after_1;
    // 0x80803AA0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80803AA4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80803AA8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80803AAC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80803AB0: bnel        $s7, $t9, L_80803A20
    if (ctx->r23 != ctx->r25) {
        // 0x80803AB4: addiu       $t7, $s3, -0x1
        ctx->r15 = ADD32(ctx->r19, -0X1);
            goto L_80803A20;
    }
    goto skip_0;
    // 0x80803AB4: addiu       $t7, $s3, -0x1
    ctx->r15 = ADD32(ctx->r19, -0X1);
    skip_0:
    // 0x80803AB8: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
L_80803ABC:
    // 0x80803ABC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80803AC0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80803AC4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80803AC8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80803ACC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80803AD0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80803AD4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80803AD8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80803ADC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80803AE0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80803AE4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80803AE8: jr          $ra
    // 0x80803AEC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80803AEC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800408_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080040C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800410: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800414: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x80800418: addiu       $a2, $zero, 0x374
    ctx->r6 = ADD32(0, 0X374);
    // 0x8080041C: jal         0x80800FA4
    // 0x80800420: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_80800FA4_chalienkids(rdram, ctx);
        goto after_0;
    // 0x80800420: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_0:
    // 0x80800424: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800428: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080042C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800430: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800434: bnel        $t7, $at, L_80800448
    if (ctx->r15 != ctx->r1) {
        // 0x80800438: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800448;
    }
    goto skip_0;
    // 0x80800438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080043C: jal         0x8010A63C
    // 0x80800440: nop

    func_8010A63C(rdram, ctx);
        goto after_1;
    // 0x80800440: nop

    after_1:
    // 0x80800444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800448:
    // 0x80800448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080044C: jr          $ra
    // 0x80800450: nop

    return;
    // 0x80800450: nop

;}
RECOMP_FUNC void anctrl_setSmoothTransition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B1A0: lbu         $t9, 0x1B($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1B);
    // 0x8008B1A4: sll         $t7, $a1, 6
    ctx->r15 = S32(ctx->r5 << 6);
    // 0x8008B1A8: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x8008B1AC: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x8008B1B0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8008B1B4: jr          $ra
    // 0x8008B1B8: sb          $t1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r9;
    return;
    // 0x8008B1B8: sb          $t1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8080783C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080783C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80807840: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80807844: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80807848: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080784C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80807850: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80807854: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80807858: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8080785C: jal         0x80100094
    // 0x80807860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807864: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80807868: jal         0x80802228
    // 0x8080786C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x8080786C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x80807870: jal         0x80802314
    // 0x80807874: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    func_80802314_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80807874: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_2:
    // 0x80807878: addiu       $a0, $zero, 0x10B
    ctx->r4 = ADD32(0, 0X10B);
    // 0x8080787C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80807880: jal         0x800D2498
    // 0x80807884: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_3;
    // 0x80807884: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80807888: jal         0x800F54E4
    // 0x8080788C: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x8080788C: nop

    after_4:
    // 0x80807890: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80807894: jal         0x800F64A4
    // 0x80807898: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    func_800F64A4(rdram, ctx);
        goto after_5;
    // 0x80807898: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_5:
    // 0x8080789C: beql        $v0, $zero, L_80807914
    if (ctx->r2 == 0) {
        // 0x808078A0: lbu         $a2, 0xA3($s2)
        ctx->r6 = MEM_BU(ctx->r18, 0XA3);
            goto L_80807914;
    }
    goto skip_0;
    // 0x808078A0: lbu         $a2, 0xA3($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0XA3);
    skip_0:
    // 0x808078A4: jal         0x80802228
    // 0x808078A8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x808078A8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_6:
    // 0x808078AC: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x808078B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808078B4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808078B8: jal         0x8008A0E0
    // 0x808078BC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x808078BC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_7:
    // 0x808078C0: beq         $v0, $zero, L_80807910
    if (ctx->r2 == 0) {
        // 0x808078C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80807910;
    }
    // 0x808078C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808078C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808078CC: jal         0x8010CFBC
    // 0x808078D0: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    func_8010CFBC(rdram, ctx);
        goto after_8;
    // 0x808078D0: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_8:
    // 0x808078D4: beq         $v0, $zero, L_80807910
    if (ctx->r2 == 0) {
        // 0x808078D8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80807910;
    }
    // 0x808078D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808078DC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x808078E0: sh          $t6, 0xA0($s2)
    MEM_H(0XA0, ctx->r18) = ctx->r14;
    // 0x808078E4: lh          $t8, 0xA0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0XA0);
    // 0x808078E8: lbu         $t1, 0x75($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X75);
    // 0x808078EC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x808078F0: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x808078F4: andi        $t2, $t1, 0xFFFD
    ctx->r10 = ctx->r9 & 0XFFFD;
    // 0x808078F8: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x808078FC: jal         0x800FE850
    // 0x80807900: sb          $t3, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r11;
    func_800FE850(rdram, ctx);
        goto after_9;
    // 0x80807900: sb          $t3, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r11;
    after_9:
    // 0x80807904: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    // 0x80807908: jal         0x80087A58
    // 0x8080790C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x8080790C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_80807910:
    // 0x80807910: lbu         $a2, 0xA3($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0XA3);
L_80807914:
    // 0x80807914: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80807918: beq         $a2, $zero, L_80807938
    if (ctx->r6 == 0) {
        // 0x8080791C: nop
    
            goto L_80807938;
    }
    // 0x8080791C: nop

    // 0x80807920: beq         $a2, $at, L_80807994
    if (ctx->r6 == ctx->r1) {
        // 0x80807924: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80807994;
    }
    // 0x80807924: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80807928: beq         $a2, $at, L_808079F0
    if (ctx->r6 == ctx->r1) {
        // 0x8080792C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808079F0;
    }
    // 0x8080792C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80807930: b           L_80807A94
    // 0x80807934: nop

        goto L_80807A94;
    // 0x80807934: nop

L_80807938:
    // 0x80807938: jal         0x800D9078
    // 0x8080793C: addiu       $a0, $s2, 0x9C
    ctx->r4 = ADD32(ctx->r18, 0X9C);
    func_800D9078(rdram, ctx);
        goto after_11;
    // 0x8080793C: addiu       $a0, $s2, 0x9C
    ctx->r4 = ADD32(ctx->r18, 0X9C);
    after_11:
    // 0x80807940: beq         $v0, $zero, L_80807A94
    if (ctx->r2 == 0) {
        // 0x80807944: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80807A94;
    }
    // 0x80807944: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80807948: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8080794C: lbu         $t4, 0xA2($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XA2);
L_80807950:
    // 0x80807950: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80807954: sllv        $t6, $t5, $s0
    ctx->r14 = S32(ctx->r13 << (ctx->r16 & 31));
    // 0x80807958: and         $t7, $t4, $t6
    ctx->r15 = ctx->r12 & ctx->r14;
    // 0x8080795C: beq         $t7, $zero, L_80807970
    if (ctx->r15 == 0) {
        // 0x80807960: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80807970;
    }
    // 0x80807960: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80807964: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80807968: jal         0x80805448
    // 0x8080796C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x8080796C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
L_80807970:
    // 0x80807970: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80807974: bnel        $s0, $s1, L_80807950
    if (ctx->r16 != ctx->r17) {
        // 0x80807978: lbu         $t4, 0xA2($s2)
        ctx->r12 = MEM_BU(ctx->r18, 0XA2);
            goto L_80807950;
    }
    goto skip_1;
    // 0x80807978: lbu         $t4, 0xA2($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XA2);
    skip_1:
    // 0x8080797C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80807980: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80807984: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80807988: sb          $t8, 0xA3($s2)
    MEM_B(0XA3, ctx->r18) = ctx->r24;
    // 0x8080798C: b           L_80807A94
    // 0x80807990: swc1        $f4, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f4.u32l;
        goto L_80807A94;
    // 0x80807990: swc1        $f4, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f4.u32l;
L_80807994:
    // 0x80807994: jal         0x800D9078
    // 0x80807998: addiu       $a0, $s2, 0x9C
    ctx->r4 = ADD32(ctx->r18, 0X9C);
    func_800D9078(rdram, ctx);
        goto after_13;
    // 0x80807998: addiu       $a0, $s2, 0x9C
    ctx->r4 = ADD32(ctx->r18, 0X9C);
    after_13:
    // 0x8080799C: beq         $v0, $zero, L_80807A94
    if (ctx->r2 == 0) {
        // 0x808079A0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80807A94;
    }
    // 0x808079A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808079A4: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x808079A8: lbu         $t9, 0xA2($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0XA2);
L_808079AC:
    // 0x808079AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808079B0: sllv        $t0, $t1, $s0
    ctx->r8 = S32(ctx->r9 << (ctx->r16 & 31));
    // 0x808079B4: and         $t2, $t9, $t0
    ctx->r10 = ctx->r25 & ctx->r8;
    // 0x808079B8: beq         $t2, $zero, L_808079CC
    if (ctx->r10 == 0) {
        // 0x808079BC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808079CC;
    }
    // 0x808079BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808079C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808079C4: jal         0x80805448
    // 0x808079C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_14;
    // 0x808079C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
L_808079CC:
    // 0x808079CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808079D0: bnel        $s0, $s1, L_808079AC
    if (ctx->r16 != ctx->r17) {
        // 0x808079D4: lbu         $t9, 0xA2($s2)
        ctx->r25 = MEM_BU(ctx->r18, 0XA2);
            goto L_808079AC;
    }
    goto skip_2;
    // 0x808079D4: lbu         $t9, 0xA2($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0XA2);
    skip_2:
    // 0x808079D8: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C10) << 16);
    // 0x808079DC: lwc1        $f6, -0x63F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C10));
    // 0x808079E0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x808079E4: sb          $t3, 0xA3($s2)
    MEM_B(0XA3, ctx->r18) = ctx->r11;
    // 0x808079E8: b           L_80807A94
    // 0x808079EC: swc1        $f6, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f6.u32l;
        goto L_80807A94;
    // 0x808079EC: swc1        $f6, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f6.u32l;
L_808079F0:
    // 0x808079F0: lbu         $t5, 0xA2($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XA2);
L_808079F4:
    // 0x808079F4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808079F8: sllv        $t6, $t4, $s0
    ctx->r14 = S32(ctx->r12 << (ctx->r16 & 31));
    // 0x808079FC: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x80807A00: beq         $t7, $zero, L_80807A30
    if (ctx->r15 == 0) {
        // 0x80807A04: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80807A30;
    }
    // 0x80807A04: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80807A08: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80807A0C: jal         0x800DC298
    // 0x80807A10: nop

    func_800DC298(rdram, ctx);
        goto after_15;
    // 0x80807A10: nop

    after_15:
    // 0x80807A14: beq         $v0, $zero, L_80807A24
    if (ctx->r2 == 0) {
        // 0x80807A18: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80807A24;
    }
    // 0x80807A18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80807A1C: b           L_80807A28
    // 0x80807A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80807A28;
    // 0x80807A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80807A24:
    // 0x80807A24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80807A28:
    // 0x80807A28: jal         0x80805448
    // 0x80807A2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_16;
    // 0x80807A2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
L_80807A30:
    // 0x80807A30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80807A34: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80807A38: bnel        $at, $zero, L_808079F4
    if (ctx->r1 != 0) {
        // 0x80807A3C: lbu         $t5, 0xA2($s2)
        ctx->r13 = MEM_BU(ctx->r18, 0XA2);
            goto L_808079F4;
    }
    goto skip_3;
    // 0x80807A3C: lbu         $t5, 0xA2($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XA2);
    skip_3:
    // 0x80807A40: jal         0x800D9078
    // 0x80807A44: addiu       $a0, $s2, 0x9C
    ctx->r4 = ADD32(ctx->r18, 0X9C);
    func_800D9078(rdram, ctx);
        goto after_17;
    // 0x80807A44: addiu       $a0, $s2, 0x9C
    ctx->r4 = ADD32(ctx->r18, 0X9C);
    after_17:
    // 0x80807A48: beq         $v0, $zero, L_80807A94
    if (ctx->r2 == 0) {
        // 0x80807A4C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80807A94;
    }
    // 0x80807A4C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80807A50: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80807A54: lbu         $t8, 0xA2($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XA2);
L_80807A58:
    // 0x80807A58: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80807A5C: sllv        $t9, $t1, $s0
    ctx->r25 = S32(ctx->r9 << (ctx->r16 & 31));
    // 0x80807A60: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80807A64: beq         $t0, $zero, L_80807A78
    if (ctx->r8 == 0) {
        // 0x80807A68: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80807A78;
    }
    // 0x80807A68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80807A6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80807A70: jal         0x80805448
    // 0x80807A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_18;
    // 0x80807A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
L_80807A78:
    // 0x80807A78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80807A7C: bnel        $s0, $s1, L_80807A58
    if (ctx->r16 != ctx->r17) {
        // 0x80807A80: lbu         $t8, 0xA2($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0XA2);
            goto L_80807A58;
    }
    goto skip_4;
    // 0x80807A80: lbu         $t8, 0xA2($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XA2);
    skip_4:
    // 0x80807A84: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80807A88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80807A8C: sb          $zero, 0xA3($s2)
    MEM_B(0XA3, ctx->r18) = 0;
    // 0x80807A90: swc1        $f8, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f8.u32l;
L_80807A94:
    // 0x80807A94: jal         0x800D90A4
    // 0x80807A98: addiu       $a0, $s2, 0x98
    ctx->r4 = ADD32(ctx->r18, 0X98);
    func_800D90A4(rdram, ctx);
        goto after_19;
    // 0x80807A98: addiu       $a0, $s2, 0x98
    ctx->r4 = ADD32(ctx->r18, 0X98);
    after_19:
    // 0x80807A9C: beql        $v0, $zero, L_80807AFC
    if (ctx->r2 == 0) {
        // 0x80807AA0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80807AFC;
    }
    goto skip_5;
    // 0x80807AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80807AA4: lh          $t2, 0xA0($s2)
    ctx->r10 = MEM_H(ctx->r18, 0XA0);
    // 0x80807AA8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80807AAC: bnel        $t2, $zero, L_80807AFC
    if (ctx->r10 != 0) {
        // 0x80807AB0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80807AFC;
    }
    goto skip_6;
    // 0x80807AB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x80807AB4: jal         0x80802170
    // 0x80807AB8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_20;
    // 0x80807AB8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_20:
    // 0x80807ABC: bne         $v0, $zero, L_80807AD0
    if (ctx->r2 != 0) {
        // 0x80807AC0: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80807AD0;
    }
    // 0x80807AC0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80807AC4: addiu       $a1, $zero, 0x1728
    ctx->r5 = ADD32(0, 0X1728);
    // 0x80807AC8: jal         0x80803660
    // 0x80807ACC: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_21;
    // 0x80807ACC: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    after_21:
L_80807AD0:
    // 0x80807AD0: jal         0x80802228
    // 0x80807AD4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_22;
    // 0x80807AD4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_22:
    // 0x80807AD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80807ADC: jal         0x808041E4
    // 0x80807AE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808041E4_chdiggerboss(rdram, ctx);
        goto after_23;
    // 0x80807AE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_23:
    // 0x80807AE4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80807AE8: jal         0x80805D64
    // 0x80807AEC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80805D64_chdiggerboss(rdram, ctx);
        goto after_24;
    // 0x80807AEC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_24:
    // 0x80807AF0: b           L_80807AFC
    // 0x80807AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80807AFC;
    // 0x80807AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80807AF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80807AFC:
    // 0x80807AFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80807B00: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80807B04: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80807B08: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80807B0C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80807B10: jr          $ra
    // 0x80807B14: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80807B14: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80801314_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801314: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080131C: jal         0x800F54E4
    // 0x80801320: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801320: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801324: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801328: jal         0x800F82D4
    // 0x8080132C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_1;
    // 0x8080132C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801334: jal         0x8008A4B0
    // 0x80801338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80801338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080133C: jal         0x800F54E4
    // 0x80801340: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80801340: nop

    after_3:
    // 0x80801344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801348: jal         0x800F7B9C
    // 0x8080134C: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    func_800F7B9C(rdram, ctx);
        goto after_4;
    // 0x8080134C: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    after_4:
    // 0x80801350: jal         0x800A50B0
    // 0x80801354: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800A50B0(rdram, ctx);
        goto after_5;
    // 0x80801354: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80801358: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080135C: lbu         $t7, 0x65($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X65);
    // 0x80801360: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x80801364: sb          $t8, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r24;
    // 0x80801368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080136C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801370: jr          $ra
    // 0x80801374: nop

    return;
    // 0x80801374: nop

;}
RECOMP_FUNC void func_800F732C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F732C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F7330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7334: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800F7338: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F733C: sb          $t6, 0x54DA($at)
    MEM_B(0X54DA, ctx->r1) = ctx->r14;
    // 0x800F7340: jal         0x800F482C
    // 0x800F7344: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_800F482C(rdram, ctx);
        goto after_0;
    // 0x800F7344: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_0:
    // 0x800F7348: jal         0x800F482C
    // 0x800F734C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800F482C(rdram, ctx);
        goto after_1;
    // 0x800F734C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800F7350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7354: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7358: sb          $zero, 0x54DA($at)
    MEM_B(0X54DA, ctx->r1) = 0;
    // 0x800F735C: jr          $ra
    // 0x800F7360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F7360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _batranslate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085340: syscall     158
    recomp_syscall_handler(rdram, ctx, 0x80085340);
    return;
    // 0x80085344: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void chweather_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(732, 0X638) << 16);
    // 0x80800130: jr          $ra
    // 0x80800134: addiu       $v0, $v0, 0x638
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X638));
    return;
    // 0x80800134: addiu       $v0, $v0, 0x638
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X638));
;}
RECOMP_FUNC void ncpod_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800F98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800F9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800FA0: jal         0x80110024
    // 0x80800FA4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80110024(rdram, ctx);
        goto after_0;
    // 0x80800FA4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800FA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800FAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FB0: jal         0x808005C0
    // 0x80800FB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    ncpod_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80800FB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800FB8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FBC: jal         0x800896A0
    // 0x80800FC0: lh          $a0, 0x4($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X4);
    _ncpodfixpos_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800FC0: lh          $a0, 0x4($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X4);
    after_2:
    // 0x80800FC4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800FC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FCC: jal         0x800896B8
    // 0x80800FD0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _ncpodfixpos_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80800FD0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800FD4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800FD8: beql        $a1, $zero, L_80800FEC
    if (ctx->r5 == 0) {
        // 0x80800FDC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800FEC;
    }
    goto skip_0;
    // 0x80800FDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800FE0: jal         0x800896B0
    // 0x80800FE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _ncpodfixpos_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800FE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800FE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800FEC:
    // 0x80800FEC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800FF0: jal         0x800896A8
    // 0x80800FF4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _ncpodfixpos_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800FF4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801000: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80801004: jr          $ra
    // 0x80801008: nop

    return;
    // 0x80801008: nop

;}
RECOMP_FUNC void func_80095124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095124: lw          $t7, 0x78($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X78);
    // 0x80095128: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8009512C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80095130: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80095134: sb          $t6, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r14;
    // 0x80095138: lw          $t9, 0x78($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X78);
    // 0x8009513C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80095140: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80095144: jr          $ra
    // 0x80095148: swc1        $f12, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f12.u32l;
    return;
    // 0x80095148: swc1        $f12, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800BD0_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BD4: addiu       $at, $zero, 0x17E1
    ctx->r1 = ADD32(0, 0X17E1);
    // 0x80800BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BDC: beq         $a1, $at, L_80800BF8
    if (ctx->r5 == ctx->r1) {
        // 0x80800BE0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800BF8;
    }
    // 0x80800BE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800BE4: addiu       $at, $zero, 0x17FE
    ctx->r1 = ADD32(0, 0X17FE);
    // 0x80800BE8: bnel        $a1, $at, L_80800BFC
    if (ctx->r5 != ctx->r1) {
        // 0x80800BEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800BFC;
    }
    goto skip_0;
    // 0x80800BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800BF0: jal         0x80102424
    // 0x80800BF4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800BF4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
L_80800BF8:
    // 0x80800BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BFC:
    // 0x80800BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C00: jr          $ra
    // 0x80800C04: nop

    return;
    // 0x80800C04: nop

;}
RECOMP_FUNC void func_8080455C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080455C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804564: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80804568: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x8080456C: bgezl       $t8, L_80804580
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80804570: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80804580;
    }
    goto skip_0;
    // 0x80804570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80804574: jal         0x800904C8
    // 0x80804578: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800904C8(rdram, ctx);
        goto after_0;
    // 0x80804578: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x8080457C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804580:
    // 0x80804580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804584: jr          $ra
    // 0x80804588: nop

    return;
    // 0x80804588: nop

;}
RECOMP_FUNC void func_8080067C_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080067C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800680: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800684: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800688: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080068C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800690: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800694: jal         0x80100094
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080069C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1392, 0X1AC8) << 16);
    // 0x808006A0: lwc1        $f6, 0x1AC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1392, 0X1AC8));
    // 0x808006A4: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x808006A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006AC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808006B0: nop

    // 0x808006B4: bc1tl       L_80800824
    if (c1cs) {
        // 0x808006B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800824;
    }
    goto skip_0;
    // 0x808006B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808006BC: lbu         $t6, 0x12($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12);
    // 0x808006C0: beql        $t6, $zero, L_80800818
    if (ctx->r14 == 0) {
        // 0x808006C4: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_80800818;
    }
    goto skip_1;
    // 0x808006C4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_1:
    // 0x808006C8: lbu         $t7, 0x56($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X56);
    // 0x808006CC: bnel        $t7, $zero, L_80800818
    if (ctx->r15 != 0) {
        // 0x808006D0: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_80800818;
    }
    goto skip_2;
    // 0x808006D0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_2:
    // 0x808006D4: lbu         $v1, 0x12($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X12);
    // 0x808006D8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1392, 0X1B28) << 16);
    // 0x808006DC: addiu       $t9, $t9, 0x1B28
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1392, 0X1B28));
    // 0x808006E0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x808006E4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x808006E8: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x808006EC: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x808006F0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x808006F4: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x808006F8: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x808006FC: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800700: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80800704: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80800708: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080070C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800710: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x80800714: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80800718: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080071C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80800720: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800724: mul.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800728: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8080072C: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800730: jal         0x800DC178
    // 0x80800734: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800734: nop

    after_1:
    // 0x80800738: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8080073C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800740: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800744: lh          $t4, 0x8($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X8);
    // 0x80800748: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080074C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800750: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800754: nop

    // 0x80800758: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080075C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800760: jal         0x800C4B7C
    // 0x80800764: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    func_800C4B7C(rdram, ctx);
        goto after_2;
    // 0x80800764: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80800768: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8080076C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800770: lbu         $t6, 0x38($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X38);
    // 0x80800774: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80800778: bgez        $t6, L_8080078C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080077C: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8080078C;
    }
    // 0x8080077C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800780: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800784: nop

    // 0x80800788: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8080078C:
    // 0x8080078C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800790: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800794: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800798: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080079C: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x808007A0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808007A4: jal         0x800C4B64
    // 0x808007A8: sub.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f16.fl;
    func_800C4B64(rdram, ctx);
        goto after_3;
    // 0x808007A8: sub.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f16.fl;
    after_3:
    // 0x808007AC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x808007B0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x808007B4: lbu         $t9, 0x38($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X38);
    // 0x808007B8: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x808007BC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x808007C0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808007C4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x808007C8: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x808007CC: subu        $a0, $t7, $t0
    ctx->r4 = SUB32(ctx->r15, ctx->r8);
    // 0x808007D0: jal         0x800C4B70
    // 0x808007D4: addiu       $a0, $a0, 0xFA0
    ctx->r4 = ADD32(ctx->r4, 0XFA0);
    func_800C4B70(rdram, ctx);
        goto after_4;
    // 0x808007D4: addiu       $a0, $a0, 0xFA0
    ctx->r4 = ADD32(ctx->r4, 0XFA0);
    after_4:
    // 0x808007D8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x808007DC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1392, 0X1BA0) << 16);
    // 0x808007E0: addiu       $a3, $a3, 0x1BA0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1392, 0X1BA0));
    // 0x808007E4: lw          $a1, 0x70($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X70);
    // 0x808007E8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x808007EC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x808007F0: andi        $t2, $a1, 0x1
    ctx->r10 = ctx->r5 & 0X1;
    // 0x808007F4: jal         0x8010D930
    // 0x808007F8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_8010D930(rdram, ctx);
        goto after_5;
    // 0x808007F8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_5:
    // 0x808007FC: lh          $t3, 0x54($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X54);
    // 0x80800800: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800804: andi        $t4, $t3, 0x100
    ctx->r12 = ctx->r11 & 0X100;
    // 0x80800808: beql        $t4, $zero, L_80800818
    if (ctx->r12 == 0) {
        // 0x8080080C: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_80800818;
    }
    goto skip_3;
    // 0x8080080C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_3:
    // 0x80800810: sb          $t5, 0x56($s0)
    MEM_B(0X56, ctx->r16) = ctx->r13;
    // 0x80800814: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80800818:
    // 0x80800818: nop

    // 0x8080081C: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800824:
    // 0x80800824: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800828: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080082C: jr          $ra
    // 0x80800830: nop

    return;
    // 0x80800830: nop

;}
RECOMP_FUNC void func_80800000_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8080000C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800010: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800014: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800018: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8080001C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800020: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800024: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800028: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080002C: jal         0x80100094
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800034: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800038: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8080003C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800040: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800044: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800048: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080004C: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
L_80800050:
    // 0x80800050: jal         0x800DA298
    // 0x80800054: addiu       $a0, $s1, 0x4F6
    ctx->r4 = ADD32(ctx->r17, 0X4F6);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800054: addiu       $a0, $s1, 0x4F6
    ctx->r4 = ADD32(ctx->r17, 0X4F6);
    after_1:
    // 0x80800058: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8080005C: bne         $t6, $zero, L_80800068
    if (ctx->r14 != 0) {
        // 0x80800060: sb          $v0, 0x34($s0)
        MEM_B(0X34, ctx->r16) = ctx->r2;
            goto L_80800068;
    }
    // 0x80800060: sb          $v0, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r2;
    // 0x80800064: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80800068:
    // 0x80800068: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080006C: sb          $zero, 0x39($s0)
    MEM_B(0X39, ctx->r16) = 0;
    // 0x80800070: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800074: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800078: bne         $s1, $s4, L_80800050
    if (ctx->r17 != ctx->r20) {
        // 0x8080007C: swc1        $f20, 0x14($s2)
        MEM_W(0X14, ctx->r18) = ctx->f20.u32l;
            goto L_80800050;
    }
    // 0x8080007C: swc1        $f20, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f20.u32l;
    // 0x80800080: bne         $s3, $zero, L_80800090
    if (ctx->r19 != 0) {
        // 0x80800084: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800090;
    }
    // 0x80800084: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800088: jal         0x808000E8
    // 0x8080008C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808000E8_chtoothyfish(rdram, ctx);
        goto after_2;
    // 0x8080008C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
L_80800090:
    // 0x80800090: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800094: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800098: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x8080009C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808000A0: jal         0x80089F48
    // 0x808000A4: swc1        $f4, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->f4.u32l;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808000A4: swc1        $f4, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->f4.u32l;
    after_3:
    // 0x808000A8: lhu         $t9, 0x6E($s5)
    ctx->r25 = MEM_HU(ctx->r21, 0X6E);
    // 0x808000AC: andi        $t8, $v0, 0x1FF
    ctx->r24 = ctx->r2 & 0X1FF;
    // 0x808000B0: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x808000B4: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808000B8: sh          $t1, 0x6E($s5)
    MEM_H(0X6E, ctx->r21) = ctx->r9;
    // 0x808000BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808000C0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808000C4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808000C8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808000CC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808000D0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808000D4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808000D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000DC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808000E0: jr          $ra
    // 0x808000E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808000E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800C675C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C675C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6760: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C6764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6768: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800C676C: jal         0x800EE7F8
    // 0x800C6770: addiu       $a1, $a3, 0x64
    ctx->r5 = ADD32(ctx->r7, 0X64);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800C6770: addiu       $a1, $a3, 0x64
    ctx->r5 = ADD32(ctx->r7, 0X64);
    after_0:
    // 0x800C6774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C677C: jr          $ra
    // 0x800C6780: nop

    return;
    // 0x800C6780: nop

;}
RECOMP_FUNC void func_800E9070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9070: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E9074: addiu       $v1, $v1, -0x2970
    ctx->r3 = ADD32(ctx->r3, -0X2970);
    // 0x800E9078: subu        $t6, $a0, $v1
    ctx->r14 = SUB32(ctx->r4, ctx->r3);
    // 0x800E907C: addiu       $t7, $t6, -0x3A8
    ctx->r15 = ADD32(ctx->r14, -0X3A8);
    // 0x800E9080: addiu       $at, $zero, 0xD8
    ctx->r1 = ADD32(0, 0XD8);
    // 0x800E9084: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800E9088: mflo        $t8
    ctx->r24 = lo;
    // 0x800E908C: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x800E9090: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800E9094: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E9098: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800E909C: jr          $ra
    // 0x800E90A0: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    return;
    // 0x800E90A0: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void _chfactorysmoke_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862C8: syscall     302
    recomp_syscall_handler(rdram, ctx, 0x800862C8);
    return;
    // 0x800862CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void baroll_setIdeal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C4CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C4D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C4D4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009C4D8: jal         0x800136E4
    // 0x8009C4DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x8009C4DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009C4E0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8009C4E4: lw          $t7, 0xF4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XF4);
    // 0x8009C4E8: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x8009C4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C4F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C4F4: jr          $ra
    // 0x8009C4F8: nop

    return;
    // 0x8009C4F8: nop

;}
RECOMP_FUNC void func_80801AA0_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AA0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801AA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801AA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801AAC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801AB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801AB4: jal         0x80100094
    // 0x80801AB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801AB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801ABC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80801AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AC4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80801AC8: jal         0x80102424
    // 0x80801ACC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80801ACC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801AD0: jal         0x80803460
    // 0x80801AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803460_chweldarboss(rdram, ctx);
        goto after_2;
    // 0x80801AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801AD8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80801ADC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801AE0: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80801AE4: sltiu       $at, $t7, 0x30
    ctx->r1 = ctx->r15 < 0X30 ? 1 : 0;
    // 0x80801AE8: beq         $at, $zero, L_80801F08
    if (ctx->r1 == 0) {
        // 0x80801AEC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80801F08;
    }
    // 0x80801AEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801AF0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X443C) << 16);
    // 0x80801AF4: addu        $at, $at, $t7
    gpr jr_addend_80801AFC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801AF8: lw          $t7, 0x443C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1360, 0X443C));
    // 0x80801AFC: jr          $t7
    // 0x80801B00: nop

    switch (jr_addend_80801AFC >> 2) {
        case 0: goto L_80801B04; break;
        case 1: goto L_80801B24; break;
        case 2: goto L_80801B78; break;
        case 3: goto L_80801BB0; break;
        case 4: goto L_80801F08; break;
        case 5: goto L_80801BFC; break;
        case 6: goto L_80801BCC; break;
        case 7: goto L_80801BFC; break;
        case 8: goto L_80801C38; break;
        case 9: goto L_80801C80; break;
        case 10: goto L_80801C08; break;
        case 11: goto L_80801BFC; break;
        case 12: goto L_80801C68; break;
        case 13: goto L_80801F08; break;
        case 14: goto L_80801C98; break;
        case 15: goto L_80801CF4; break;
        case 16: goto L_80801D7C; break;
        case 17: goto L_80801BFC; break;
        case 18: goto L_80801F08; break;
        case 19: goto L_80801BFC; break;
        case 20: goto L_80801C80; break;
        case 21: goto L_80801C08; break;
        case 22: goto L_80801BFC; break;
        case 23: goto L_80801C68; break;
        case 24: goto L_80801C98; break;
        case 25: goto L_80801CF4; break;
        case 26: goto L_80801D04; break;
        case 27: goto L_80801F08; break;
        case 28: goto L_80801F08; break;
        case 29: goto L_80801F08; break;
        case 30: goto L_80801D54; break;
        case 31: goto L_80801F08; break;
        case 32: goto L_80801F08; break;
        case 33: goto L_80801D4C; break;
        case 34: goto L_80801F08; break;
        case 35: goto L_80801BFC; break;
        case 36: goto L_80801C80; break;
        case 37: goto L_80801C08; break;
        case 38: goto L_80801BFC; break;
        case 39: goto L_80801C68; break;
        case 40: goto L_80801C98; break;
        case 41: goto L_80801CF4; break;
        case 42: goto L_80801DAC; break;
        case 43: goto L_80801DD4; break;
        case 44: goto L_80801E14; break;
        case 45: goto L_80801E38; break;
        case 46: goto L_80801EB4; break;
        case 47: goto L_80801EC4; break;
        default: switch_error(__func__, 0x80801AFC, 0x8080443C);
    }
    // 0x80801B00: nop

L_80801B04:
    // 0x80801B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B08: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80801B0C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80801B10: jal         0x80803CF0
    // 0x80801B14: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_3;
    // 0x80801B14: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80801B18: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801B1C: b           L_80801F08
    // 0x80801B20: sb          $zero, 0x70($v1)
    MEM_B(0X70, ctx->r3) = 0;
        goto L_80801F08;
    // 0x80801B20: sb          $zero, 0x70($v1)
    MEM_B(0X70, ctx->r3) = 0;
L_80801B24:
    // 0x80801B24: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80801B28: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801B2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801B30: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80801B34: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80801B38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801B3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801B40: jal         0x800BF744
    // 0x80801B44: swc1        $f4, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->f4.u32l;
    func_800BF744(rdram, ctx);
        goto after_4;
    // 0x80801B44: swc1        $f4, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->f4.u32l;
    after_4:
    // 0x80801B48: jal         0x800FDC28
    // 0x80801B4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_5;
    // 0x80801B4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80801B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801B58: jal         0x80803CF0
    // 0x80801B5C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_6;
    // 0x80801B5C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_6:
    // 0x80801B60: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    // 0x80801B64: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801B68: jal         0x80101180
    // 0x80801B6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80801B6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80801B70: b           L_80801F0C
    // 0x80801B74: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801B74: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801B78:
    // 0x80801B78: lbu         $t1, 0x7B($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7B);
    // 0x80801B7C: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    // 0x80801B80: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80801B84: andi        $t2, $t1, 0xFF3F
    ctx->r10 = ctx->r9 & 0XFF3F;
    // 0x80801B88: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x80801B8C: sb          $t3, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r11;
    // 0x80801B90: jal         0x80101180
    // 0x80801B94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_8;
    // 0x80801B94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80801B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B9C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80801BA0: jal         0x80803CF0
    // 0x80801BA4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_9;
    // 0x80801BA4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_9:
    // 0x80801BA8: b           L_80801F0C
    // 0x80801BAC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801BAC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801BB0:
    // 0x80801BB0: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x80801BB4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80801BB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801BBC: jal         0x800861A0
    // 0x80801BC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80801BC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x80801BC4: b           L_80801F0C
    // 0x80801BC8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801BC8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801BCC:
    // 0x80801BCC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801BD0: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80801BD4: lbu         $t5, 0x7A($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X7A);
    // 0x80801BD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BE0: bne         $t5, $zero, L_80801F08
    if (ctx->r13 != 0) {
        // 0x80801BE4: addiu       $a1, $zero, 0x1357
        ctx->r5 = ADD32(0, 0X1357);
            goto L_80801F08;
    }
    // 0x80801BE4: addiu       $a1, $zero, 0x1357
    ctx->r5 = ADD32(0, 0X1357);
    // 0x80801BE8: sb          $t6, 0x7A($v1)
    MEM_B(0X7A, ctx->r3) = ctx->r14;
    // 0x80801BEC: jal         0x80802214
    // 0x80801BF0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_11;
    // 0x80801BF0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_11:
    // 0x80801BF4: b           L_80801F0C
    // 0x80801BF8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801BF8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801BFC:
    // 0x80801BFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801C00: b           L_80801F08
    // 0x80801C04: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
        goto L_80801F08;
    // 0x80801C04: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_80801C08:
    // 0x80801C08: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801C0C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80801C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C14: jal         0x80803378
    // 0x80801C18: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_80803378_chweldarboss(rdram, ctx);
        goto after_12;
    // 0x80801C18: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_12:
    // 0x80801C1C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801C20: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80801C24: jal         0x80089D48
    // 0x80801C28: lbu         $a0, 0xB2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB2);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x80801C28: lbu         $a0, 0xB2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB2);
    after_13:
    // 0x80801C2C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801C30: b           L_80801F08
    // 0x80801C34: sb          $v0, 0xB2($v1)
    MEM_B(0XB2, ctx->r3) = ctx->r2;
        goto L_80801F08;
    // 0x80801C34: sb          $v0, 0xB2($v1)
    MEM_B(0XB2, ctx->r3) = ctx->r2;
L_80801C38:
    // 0x80801C38: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80801C3C: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80801C40: lbu         $t0, 0x7B($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X7B);
    // 0x80801C44: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C4C: bne         $t0, $zero, L_80801F08
    if (ctx->r8 != 0) {
        // 0x80801C50: addiu       $a1, $zero, 0x1358
        ctx->r5 = ADD32(0, 0X1358);
            goto L_80801F08;
    }
    // 0x80801C50: addiu       $a1, $zero, 0x1358
    ctx->r5 = ADD32(0, 0X1358);
    // 0x80801C54: sb          $t1, 0x7B($v1)
    MEM_B(0X7B, ctx->r3) = ctx->r9;
    // 0x80801C58: jal         0x80802214
    // 0x80801C5C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_14;
    // 0x80801C5C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_14:
    // 0x80801C60: b           L_80801F0C
    // 0x80801C64: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801C64: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801C68:
    // 0x80801C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C6C: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80801C70: jal         0x80803CF0
    // 0x80801C74: addiu       $a2, $zero, 0x438
    ctx->r6 = ADD32(0, 0X438);
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_15;
    // 0x80801C74: addiu       $a2, $zero, 0x438
    ctx->r6 = ADD32(0, 0X438);
    after_15:
    // 0x80801C78: b           L_80801F0C
    // 0x80801C7C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801C7C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801C80:
    // 0x80801C80: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80801C84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801C88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801C8C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80801C90: b           L_80801F08
    // 0x80801C94: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80801F08;
    // 0x80801C94: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80801C98:
    // 0x80801C98: lbu         $a0, 0xB2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB2);
    // 0x80801C9C: jal         0x80089D48
    // 0x80801CA0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80801CA0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_16:
    // 0x80801CA4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801CA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801CAC: sb          $v0, 0xB2($v1)
    MEM_B(0XB2, ctx->r3) = ctx->r2;
    // 0x80801CB0: jal         0x800F82D4
    // 0x80801CB4: lh          $a0, 0x76($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X76);
    func_800F82D4(rdram, ctx);
        goto after_17;
    // 0x80801CB4: lh          $a0, 0x76($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X76);
    after_17:
    // 0x80801CB8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801CC0: jal         0x800F8150
    // 0x80801CC4: lh          $a0, 0x76($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X76);
    func_800F8150(rdram, ctx);
        goto after_18;
    // 0x80801CC4: lh          $a0, 0x76($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X76);
    after_18:
    // 0x80801CC8: jal         0x800F4FC4
    // 0x80801CCC: nop

    func_800F4FC4(rdram, ctx);
        goto after_19;
    // 0x80801CCC: nop

    after_19:
    // 0x80801CD0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801CD4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80801CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CDC: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80801CE0: addiu       $a2, $zero, 0x428
    ctx->r6 = ADD32(0, 0X428);
    // 0x80801CE4: jal         0x80803CF0
    // 0x80801CE8: sb          $t3, 0x60($v1)
    MEM_B(0X60, ctx->r3) = ctx->r11;
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_20;
    // 0x80801CE8: sb          $t3, 0x60($v1)
    MEM_B(0X60, ctx->r3) = ctx->r11;
    after_20:
    // 0x80801CEC: b           L_80801F0C
    // 0x80801CF0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801CF0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801CF4:
    // 0x80801CF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X44FC) << 16);
    // 0x80801CF8: lwc1        $f8, 0x44FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X44FC));
    // 0x80801CFC: b           L_80801F08
    // 0x80801D00: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80801F08;
    // 0x80801D00: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80801D04:
    // 0x80801D04: lbu         $t4, 0x7E($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X7E);
    // 0x80801D08: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D10: bne         $t4, $zero, L_80801D2C
    if (ctx->r12 != 0) {
        // 0x80801D14: addiu       $a1, $zero, 0x135B
        ctx->r5 = ADD32(0, 0X135B);
            goto L_80801D2C;
    }
    // 0x80801D14: addiu       $a1, $zero, 0x135B
    ctx->r5 = ADD32(0, 0X135B);
    // 0x80801D18: sb          $t5, 0x7E($v1)
    MEM_B(0X7E, ctx->r3) = ctx->r13;
    // 0x80801D1C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80801D20: jal         0x80802214
    // 0x80801D24: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_21;
    // 0x80801D24: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_21:
    // 0x80801D28: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_80801D2C:
    // 0x80801D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D30: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x80801D34: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80801D38: jal         0x80803CF0
    // 0x80801D3C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_22;
    // 0x80801D3C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_22:
    // 0x80801D40: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801D44: b           L_80801F08
    // 0x80801D48: sh          $zero, 0x74($v1)
    MEM_H(0X74, ctx->r3) = 0;
        goto L_80801F08;
    // 0x80801D48: sh          $zero, 0x74($v1)
    MEM_H(0X74, ctx->r3) = 0;
L_80801D4C:
    // 0x80801D4C: b           L_80801F08
    // 0x80801D50: sh          $zero, 0x74($v1)
    MEM_H(0X74, ctx->r3) = 0;
        goto L_80801F08;
    // 0x80801D50: sh          $zero, 0x74($v1)
    MEM_H(0X74, ctx->r3) = 0;
L_80801D54:
    // 0x80801D54: lbu         $t6, 0x7F($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X7F);
    // 0x80801D58: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D60: bne         $t6, $zero, L_80801F08
    if (ctx->r14 != 0) {
        // 0x80801D64: addiu       $a1, $zero, 0x135C
        ctx->r5 = ADD32(0, 0X135C);
            goto L_80801F08;
    }
    // 0x80801D64: addiu       $a1, $zero, 0x135C
    ctx->r5 = ADD32(0, 0X135C);
    // 0x80801D68: sb          $t7, 0x7F($v1)
    MEM_B(0X7F, ctx->r3) = ctx->r15;
    // 0x80801D6C: jal         0x80802214
    // 0x80801D70: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_23;
    // 0x80801D70: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_23:
    // 0x80801D74: b           L_80801F0C
    // 0x80801D78: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801D78: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801D7C:
    // 0x80801D7C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801D80: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80801D84: lbu         $t9, 0x7D($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X7D);
    // 0x80801D88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D90: bne         $t9, $zero, L_80801F08
    if (ctx->r25 != 0) {
        // 0x80801D94: addiu       $a1, $zero, 0x135A
        ctx->r5 = ADD32(0, 0X135A);
            goto L_80801F08;
    }
    // 0x80801D94: addiu       $a1, $zero, 0x135A
    ctx->r5 = ADD32(0, 0X135A);
    // 0x80801D98: sb          $t0, 0x7D($v1)
    MEM_B(0X7D, ctx->r3) = ctx->r8;
    // 0x80801D9C: jal         0x80802214
    // 0x80801DA0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_24;
    // 0x80801DA0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_24:
    // 0x80801DA4: b           L_80801F0C
    // 0x80801DA8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801DA8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801DAC:
    // 0x80801DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801DB0: addiu       $a1, $zero, 0x135E
    ctx->r5 = ADD32(0, 0X135E);
    // 0x80801DB4: jal         0x80802214
    // 0x80801DB8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_25;
    // 0x80801DB8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_25:
    // 0x80801DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801DC0: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80801DC4: jal         0x80803CF0
    // 0x80801DC8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_26;
    // 0x80801DC8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_26:
    // 0x80801DCC: b           L_80801F0C
    // 0x80801DD0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801DD0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801DD4:
    // 0x80801DD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801DD8: sb          $t1, 0x6E($v1)
    MEM_B(0X6E, ctx->r3) = ctx->r9;
    // 0x80801DDC: jal         0x800FDC28
    // 0x80801DE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_27;
    // 0x80801DE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
    // 0x80801DE4: jal         0x8080373C
    // 0x80801DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080373C_chweldarboss(rdram, ctx);
        goto after_28;
    // 0x80801DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80801DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801DF0: addiu       $a1, $zero, 0x135D
    ctx->r5 = ADD32(0, 0X135D);
    // 0x80801DF4: jal         0x80802214
    // 0x80801DF8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_29;
    // 0x80801DF8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_29:
    // 0x80801DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E00: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80801E04: jal         0x80803CF0
    // 0x80801E08: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_30;
    // 0x80801E08: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_30:
    // 0x80801E0C: b           L_80801F0C
    // 0x80801E10: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801E10: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801E14:
    // 0x80801E14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801E18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E20: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80801E24: addiu       $a2, $zero, 0x430
    ctx->r6 = ADD32(0, 0X430);
    // 0x80801E28: jal         0x80803CF0
    // 0x80801E2C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_31;
    // 0x80801E2C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_31:
    // 0x80801E30: b           L_80801F0C
    // 0x80801E34: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801E34: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801E38:
    // 0x80801E38: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80801E3C: jal         0x800EE7F8
    // 0x80801E40: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_32;
    // 0x80801E40: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_32:
    // 0x80801E44: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80801E48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801E4C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801E50: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X48F8) << 16);
    // 0x80801E54: addiu       $a2, $a2, 0x48F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X48F8));
    // 0x80801E58: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80801E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E60: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80801E64: jal         0x80089D18
    // 0x80801E68: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_33;
    // 0x80801E68: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_33:
    // 0x80801E6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4500) << 16);
    // 0x80801E70: lwc1        $f6, 0x4500($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4500));
    // 0x80801E74: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801E78: lw          $a3, 0x48($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X48);
    // 0x80801E7C: addiu       $t2, $zero, 0x100
    ctx->r10 = ADD32(0, 0X100);
    // 0x80801E80: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80801E84: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80801E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E8C: addiu       $a1, $zero, 0x870
    ctx->r5 = ADD32(0, 0X870);
    // 0x80801E90: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80801E94: jal         0x80086680
    // 0x80801E98: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_5(rdram, ctx);
        goto after_34;
    // 0x80801E98: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_34:
    // 0x80801E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EA0: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x80801EA4: jal         0x80803CF0
    // 0x80801EA8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_35;
    // 0x80801EA8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_35:
    // 0x80801EAC: b           L_80801F0C
    // 0x80801EB0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801EB0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801EB4:
    // 0x80801EB4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801EB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801EBC: b           L_80801F08
    // 0x80801EC0: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80801F08;
    // 0x80801EC0: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80801EC4:
    // 0x80801EC4: jal         0x800D395C
    // 0x80801EC8: nop

    func_800D395C(rdram, ctx);
        goto after_36;
    // 0x80801EC8: nop

    after_36:
    // 0x80801ECC: beq         $v0, $zero, L_80801EEC
    if (ctx->r2 == 0) {
        // 0x80801ED0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801EEC;
    }
    // 0x80801ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801ED4: jal         0x80803D64
    // 0x80801ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803D64_chweldarboss(rdram, ctx);
        goto after_37;
    // 0x80801ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80801EDC: jal         0x80088180
    // 0x80801EE0: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_38;
    // 0x80801EE0: nop

    after_38:
    // 0x80801EE4: b           L_80801F0C
    // 0x80801EE8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_80801F0C;
    // 0x80801EE8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801EEC:
    // 0x80801EEC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80801EF0: jal         0x80803CF0
    // 0x80801EF4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_39;
    // 0x80801EF4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_39:
    // 0x80801EF8: addiu       $a0, $zero, 0x431
    ctx->r4 = ADD32(0, 0X431);
    // 0x80801EFC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801F00: jal         0x80101180
    // 0x80801F04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_40;
    // 0x80801F04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_40:
L_80801F08:
    // 0x80801F08: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80801F0C:
    // 0x80801F0C: beql        $t3, $zero, L_80801F20
    if (ctx->r11 == 0) {
        // 0x80801F10: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801F20;
    }
    goto skip_0;
    // 0x80801F10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801F14: jal         0x8080340C
    // 0x80801F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080340C_chweldarboss(rdram, ctx);
        goto after_41;
    // 0x80801F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80801F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801F20:
    // 0x80801F20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801F24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801F28: jr          $ra
    // 0x80801F2C: nop

    return;
    // 0x80801F2C: nop

;}
RECOMP_FUNC void func_800D23E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D23E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D23EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D23F0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800D23F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D23F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D23FC: jal         0x800D21F0
    // 0x800D2400: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    func_800D21F0(rdram, ctx);
        goto after_0;
    // 0x800D2400: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    after_0:
    // 0x800D2404: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D2408: slti        $t7, $v0, 0x0
    ctx->r15 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800D240C: xori        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 ^ 0X1;
    // 0x800D2410: beq         $v0, $zero, L_800D2428
    if (ctx->r2 == 0) {
        // 0x800D2414: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_800D2428;
    }
    // 0x800D2414: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800D2418: jal         0x800FA874
    // 0x800D241C: lbu         $a1, 0x1($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X1);
    func_800FA874(rdram, ctx);
        goto after_1;
    // 0x800D241C: lbu         $a1, 0x1($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X1);
    after_1:
    // 0x800D2420: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800D2424: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_800D2428:
    // 0x800D2428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D242C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2430: jr          $ra
    // 0x800D2434: nop

    return;
    // 0x800D2434: nop

;}
RECOMP_FUNC void func_800EEFD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEFD4: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EEFD8: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EEFDC: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EEFE0: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800EEFE4: nop

    // 0x800EEFE8: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EEFEC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EEFF0: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EEFF4: jr          $ra
    // 0x800EEFF8: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    return;
    // 0x800EEFF8: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
;}
RECOMP_FUNC void func_8080000C_chfloater(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: jal         0x80100094
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800028: jal         0x80088FA8
    // 0x8080002C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _mlwave_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080002C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800030: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800034: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x80800038: jal         0x80088FA8
    // 0x8080003C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    _mlwave_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080003C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800040: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800044: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    // 0x80800048: jal         0x80088FA8
    // 0x8080004C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _mlwave_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080004C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800050: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800054: lui         $a1, 0xC0F0
    ctx->r5 = S32(0XC0F0 << 16);
    // 0x80800058: jal         0x80088FC8
    // 0x8080005C: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    _mlwave_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x8080005C: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    after_4:
    // 0x80800060: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800064: jal         0x800136E4
    // 0x80800068: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x80800068: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_5:
    // 0x8080006C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80800070: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800074: lui         $a1, 0xC040
    ctx->r5 = S32(0XC040 << 16);
    // 0x80800078: jal         0x80088FC8
    // 0x8080007C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    _mlwave_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x8080007C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_6:
    // 0x80800080: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800084: jal         0x800136E4
    // 0x80800088: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x80800088: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    after_7:
    // 0x8080008C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800090: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800094: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    // 0x80800098: jal         0x80088FC8
    // 0x8080009C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _mlwave_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x8080009C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_8:
    // 0x808000A0: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808000A4: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808000A8: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x808000AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void func_800F0E44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0E44: bgezl       $a0, L_800F0E5C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800F0E48: slti        $at, $a0, 0x168
        ctx->r1 = SIGNED(ctx->r4) < 0X168 ? 1 : 0;
            goto L_800F0E5C;
    }
    goto skip_0;
    // 0x800F0E48: slti        $at, $a0, 0x168
    ctx->r1 = SIGNED(ctx->r4) < 0X168 ? 1 : 0;
    skip_0:
    // 0x800F0E4C: addiu       $a0, $a0, 0x168
    ctx->r4 = ADD32(ctx->r4, 0X168);
L_800F0E50:
    // 0x800F0E50: bltzl       $a0, L_800F0E50
    if (SIGNED(ctx->r4) < 0) {
        // 0x800F0E54: addiu       $a0, $a0, 0x168
        ctx->r4 = ADD32(ctx->r4, 0X168);
            goto L_800F0E50;
    }
    goto skip_1;
    // 0x800F0E54: addiu       $a0, $a0, 0x168
    ctx->r4 = ADD32(ctx->r4, 0X168);
    skip_1:
    // 0x800F0E58: slti        $at, $a0, 0x168
    ctx->r1 = SIGNED(ctx->r4) < 0X168 ? 1 : 0;
L_800F0E5C:
    // 0x800F0E5C: bne         $at, $zero, L_800F0E74
    if (ctx->r1 != 0) {
        // 0x800F0E60: nop
    
            goto L_800F0E74;
    }
    // 0x800F0E60: nop

    // 0x800F0E64: addiu       $a0, $a0, -0x168
    ctx->r4 = ADD32(ctx->r4, -0X168);
L_800F0E68:
    // 0x800F0E68: slti        $at, $a0, 0x168
    ctx->r1 = SIGNED(ctx->r4) < 0X168 ? 1 : 0;
    // 0x800F0E6C: beql        $at, $zero, L_800F0E68
    if (ctx->r1 == 0) {
        // 0x800F0E70: addiu       $a0, $a0, -0x168
        ctx->r4 = ADD32(ctx->r4, -0X168);
            goto L_800F0E68;
    }
    goto skip_2;
    // 0x800F0E70: addiu       $a0, $a0, -0x168
    ctx->r4 = ADD32(ctx->r4, -0X168);
    skip_2:
L_800F0E74:
    // 0x800F0E74: jr          $ra
    // 0x800F0E78: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800F0E78: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_808002C4_chdiggergroundgen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002D4: jal         0x80100094
    // 0x808002D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808002E0: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x808002E4: jal         0x801084B0
    // 0x808002E8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x808002E8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x808002EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(860, 0X4E4) << 16);
    // 0x808002F0: lwc1        $f12, 0x4E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(860, 0X4E4));
    // 0x808002F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(860, 0X4E8) << 16);
    // 0x808002F8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808002FC: jal         0x800DC178
    // 0x80800300: lwc1        $f14, 0x4E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(860, 0X4E8));
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800300: lwc1        $f14, 0x4E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(860, 0X4E8));
    after_2:
    // 0x80800304: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800308: jal         0x80102FDC
    // 0x8080030C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x8080030C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800310: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800314: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800318: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    // 0x8080031C: jal         0x800F1DF4
    // 0x80800320: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800F1DF4(rdram, ctx);
        goto after_4;
    // 0x80800320: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_4:
    // 0x80800324: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80800328: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x8080032C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800330: jal         0x8008A028
    // 0x80800334: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800334: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_5:
    // 0x80800338: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080033C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(860, 0X548) << 16);
    // 0x80800340: addiu       $a2, $a2, 0x548
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(860, 0X548));
    // 0x80800344: jal         0x80089D18
    // 0x80800348: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800348: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_6:
    // 0x8080034C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800354: jr          $ra
    // 0x80800358: nop

    return;
    // 0x80800358: nop

;}
RECOMP_FUNC void func_808000D0_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000D4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808000D8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808000DC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808000E0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808000E4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808000E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000EC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808000F0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000F8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808000FC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800100: beq         $t6, $at, L_8080011C
    if (ctx->r14 == ctx->r1) {
        // 0x80800104: or          $s4, $a0, $zero
        ctx->r20 = ctx->r4 | 0;
            goto L_8080011C;
    }
    // 0x80800104: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800108: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080010C: beq         $t6, $at, L_80800198
    if (ctx->r14 == ctx->r1) {
        // 0x80800110: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800198;
    }
    // 0x80800110: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800114: b           L_808001FC
    // 0x80800118: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808001FC;
    // 0x80800118: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8080011C:
    // 0x8080011C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800120: jal         0x80087D98
    // 0x80800124: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    _gcnewoption_entrypoint_32(rdram, ctx);
        goto after_0;
    // 0x80800124: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    after_0:
    // 0x80800128: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080012C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1824, 0X14F4) << 16);
    // 0x80800130: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800134: addiu       $s1, $s1, 0x14F4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1824, 0X14F4));
    // 0x80800138: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080013C: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x80800140: addiu       $s3, $zero, 0x50
    ctx->r19 = ADD32(0, 0X50);
L_80800144:
    // 0x80800144: lbu         $t7, 0x5($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X5);
    // 0x80800148: bnel        $s3, $t7, L_80800178
    if (ctx->r19 != ctx->r15) {
        // 0x8080014C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800178;
    }
    goto skip_0;
    // 0x8080014C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80800150: jal         0x800DC298
    // 0x80800154: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x80800154: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80800158: beq         $v0, $zero, L_80800174
    if (ctx->r2 == 0) {
        // 0x8080015C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800174;
    }
    // 0x8080015C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800160: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800164: jal         0x80087D90
    // 0x80800168: addiu       $a2, $zero, 0x51
    ctx->r6 = ADD32(0, 0X51);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_2;
    // 0x80800168: addiu       $a2, $zero, 0x51
    ctx->r6 = ADD32(0, 0X51);
    after_2:
    // 0x8080016C: b           L_80800188
    // 0x80800170: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80800188;
    // 0x80800170: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800174:
    // 0x80800174: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800178:
    // 0x80800178: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080017C: jal         0x80087D90
    // 0x80800180: lbu         $a2, 0x5($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X5);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_3;
    // 0x80800180: lbu         $a2, 0x5($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X5);
    after_3:
    // 0x80800184: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800188:
    // 0x80800188: bne         $s0, $s4, L_80800144
    if (ctx->r16 != ctx->r20) {
        // 0x8080018C: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80800144;
    }
    // 0x8080018C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80800190: b           L_808001FC
    // 0x80800194: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808001FC;
    // 0x80800194: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800198:
    // 0x80800198: jal         0x80087D98
    // 0x8080019C: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    _gcnewoption_entrypoint_32(rdram, ctx);
        goto after_4;
    // 0x8080019C: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    after_4:
    // 0x808001A0: jal         0x80087DA0
    // 0x808001A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _gcnewoption_entrypoint_33(rdram, ctx);
        goto after_5;
    // 0x808001A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x808001A8: lw          $t8, 0x30($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X30);
    // 0x808001AC: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1824, 0X14F4) << 16);
    // 0x808001B0: addiu       $s3, $s3, 0x14F4
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1824, 0X14F4));
    // 0x808001B4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x808001B8: addu        $s1, $s3, $t9
    ctx->r17 = ADD32(ctx->r19, ctx->r25);
    // 0x808001BC: lbu         $t0, 0x4($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X4);
    // 0x808001C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001C4: blez        $t0, L_808001F8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x808001C8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808001F8;
    }
    // 0x808001C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808001CC:
    // 0x808001CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80087D90
    // 0x808001D4: lbu         $a2, 0x5($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X5);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_6;
    // 0x808001D4: lbu         $a2, 0x5($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X5);
    after_6:
    // 0x808001D8: lw          $t1, 0x30($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X30);
    // 0x808001DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001E0: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x808001E4: addu        $s1, $s3, $t2
    ctx->r17 = ADD32(ctx->r19, ctx->r10);
    // 0x808001E8: lbu         $t3, 0x4($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X4);
    // 0x808001EC: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x808001F0: bnel        $at, $zero, L_808001CC
    if (ctx->r1 != 0) {
        // 0x808001F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808001CC;
    }
    goto skip_1;
    // 0x808001F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_808001F8:
    // 0x808001F8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808001FC:
    // 0x808001FC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800200: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800204: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800208: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080020C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800210: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800214: jr          $ra
    // 0x80800218: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800218: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8080026C_chbeanstalkseed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080026C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800270: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800274: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800278: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080027C: bne         $a1, $at, L_80800308
    if (ctx->r5 != ctx->r1) {
        // 0x80800280: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800308;
    }
    // 0x80800280: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800284: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x80800288: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x8080028C: jal         0x800DA544
    // 0x80800290: addiu       $a0, $t7, 0x33D
    ctx->r4 = ADD32(ctx->r15, 0X33D);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800290: addiu       $a0, $t7, 0x33D
    ctx->r4 = ADD32(ctx->r15, 0X33D);
    after_0:
    // 0x80800294: jal         0x800FC6B0
    // 0x80800298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FC6B0(rdram, ctx);
        goto after_1;
    // 0x80800298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8080029C: jal         0x800D1844
    // 0x808002A0: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    func_800D1844(rdram, ctx);
        goto after_2;
    // 0x808002A0: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_2:
    // 0x808002A4: jal         0x800DA298
    // 0x808002A8: addiu       $a0, $zero, 0x6BE
    ctx->r4 = ADD32(0, 0X6BE);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808002A8: addiu       $a0, $zero, 0x6BE
    ctx->r4 = ADD32(0, 0X6BE);
    after_3:
    // 0x808002AC: bnel        $v0, $zero, L_808002F8
    if (ctx->r2 != 0) {
        // 0x808002B0: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_808002F8;
    }
    goto skip_0;
    // 0x808002B0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x808002B4: jal         0x800F54E4
    // 0x808002B8: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808002B8: nop

    after_4:
    // 0x808002BC: jal         0x800F5410
    // 0x808002C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_5;
    // 0x808002C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808002C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002C8: bne         $v0, $at, L_808002F4
    if (ctx->r2 != ctx->r1) {
        // 0x808002CC: addiu       $a1, $zero, 0x1430
        ctx->r5 = ADD32(0, 0X1430);
            goto L_808002F4;
    }
    // 0x808002CC: addiu       $a1, $zero, 0x1430
    ctx->r5 = ADD32(0, 0X1430);
    // 0x808002D0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808002D4: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x808002D8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808002DC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808002E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808002E4: jal         0x8008A208
    // 0x808002E8: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808002E8: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_6:
    // 0x808002EC: jal         0x800DA544
    // 0x808002F0: addiu       $a0, $zero, 0x6BE
    ctx->r4 = ADD32(0, 0X6BE);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x808002F0: addiu       $a0, $zero, 0x6BE
    ctx->r4 = ADD32(0, 0X6BE);
    after_7:
L_808002F4:
    // 0x808002F4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
L_808002F8:
    // 0x808002F8: jal         0x800FFA88
    // 0x808002FC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_8;
    // 0x808002FC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_8:
    // 0x80800300: b           L_8080030C
    // 0x80800304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080030C;
    // 0x80800304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800308:
    // 0x80800308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080030C:
    // 0x8080030C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800314: jr          $ra
    // 0x80800318: nop

    return;
    // 0x80800318: nop

;}
RECOMP_FUNC void _dbshift_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087968: syscall     642
    recomp_syscall_handler(rdram, ctx, 0x80087968);
    return;
    // 0x8008796C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800B34_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B3C: jal         0x80082FF0
    // 0x80800B40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800B40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B44: jal         0x80800270
    // 0x80800B48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800270_bsswim(rdram, ctx);
        goto after_1;
    // 0x80800B48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B54: jr          $ra
    // 0x80800B58: nop

    return;
    // 0x80800B58: nop

;}
RECOMP_FUNC void func_80800CFC_chquicksandbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D04: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800D08: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800D0C: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800D10: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D14: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800D18: bltz        $t8, L_80800D28
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800D1C: nop
    
            goto L_80800D28;
    }
    // 0x80800D1C: nop

    // 0x80800D20: b           L_80800DAC
    // 0x80800D24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800DAC;
    // 0x80800D24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D28:
    // 0x80800D28: jal         0x800EEB40
    // 0x80800D2C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EEB40(rdram, ctx);
        goto after_0;
    // 0x80800D2C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80800D30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1896, 0X1298) << 16);
    // 0x80800D34: lwc1        $f4, 0x1298($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1896, 0X1298));
    // 0x80800D38: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800D3C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D40: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800D44: nop

    // 0x80800D48: bc1fl       L_80800D5C
    if (!c1cs) {
        // 0x80800D4C: lwc1        $f6, 0x4($t9)
        ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
            goto L_80800D5C;
    }
    goto skip_0;
    // 0x80800D4C: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    skip_0:
    // 0x80800D50: b           L_80800DAC
    // 0x80800D54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800DAC;
    // 0x80800D54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800D58: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
L_80800D5C:
    // 0x80800D5C: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80800D60: jal         0x800F2100
    // 0x80800D64: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x80800D64: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_1:
    // 0x80800D68: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800D6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800D70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D74: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800D78: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800D7C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80800D80: bc1f        L_80800D90
    if (!c1cs) {
        // 0x80800D84: nop
    
            goto L_80800D90;
    }
    // 0x80800D84: nop

    // 0x80800D88: b           L_80800DAC
    // 0x80800D8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800DAC;
    // 0x80800D8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D90:
    // 0x80800D90: jal         0x800C6A7C
    // 0x80800D94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6A7C(rdram, ctx);
        goto after_2;
    // 0x80800D94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80800D98: beql        $v0, $zero, L_80800DAC
    if (ctx->r2 == 0) {
        // 0x80800D9C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800DAC;
    }
    goto skip_1;
    // 0x80800D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800DA0: b           L_80800DAC
    // 0x80800DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800DAC;
    // 0x80800DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800DA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DAC:
    // 0x80800DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800DB4: jr          $ra
    // 0x80800DB8: nop

    return;
    // 0x80800DB8: nop

;}
RECOMP_FUNC void func_80802480_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802488: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x8080248C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80802490: beq         $a1, $zero, L_808024A4
    if (ctx->r5 == 0) {
        // 0x80802494: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_808024A4;
    }
    // 0x80802494: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80802498: jal         0x8001B084
    // 0x8080249C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    heap_free(rdram, ctx);
        goto after_0;
    // 0x8080249C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808024A0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_808024A4:
    // 0x808024A4: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x808024A8: beq         $a0, $zero, L_808024BC
    if (ctx->r4 == 0) {
        // 0x808024AC: nop
    
            goto L_808024BC;
    }
    // 0x808024AC: nop

    // 0x808024B0: jal         0x8001B084
    // 0x808024B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    heap_free(rdram, ctx);
        goto after_1;
    // 0x808024B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808024B8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_808024BC:
    // 0x808024BC: jal         0x80802620
    // 0x808024C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80802620_chgameselect(rdram, ctx);
        goto after_2;
    // 0x808024C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x808024C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808024C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808024CC: jr          $ra
    // 0x808024D0: nop

    return;
    // 0x808024D0: nop

;}
RECOMP_FUNC void func_800E1748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1748: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E174C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E1750: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E1754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E1758: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800E175C: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
L_800E1760:
    // 0x800E1760: jal         0x800E1720
    // 0x800E1764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E1720(rdram, ctx);
        goto after_0;
    // 0x800E1764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800E1768: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800E176C: bne         $s0, $s1, L_800E1760
    if (ctx->r16 != ctx->r17) {
        // 0x800E1770: nop
    
            goto L_800E1760;
    }
    // 0x800E1770: nop

    // 0x800E1774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1778: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E177C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E1780: jr          $ra
    // 0x800E1784: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800E1784: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800054_bsmumattack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: sb          $zero, 0x160($a0)
    MEM_B(0X160, ctx->r4) = 0;
    // 0x80800058: jr          $ra
    // 0x8080005C: sw          $zero, 0x164($a0)
    MEM_W(0X164, ctx->r4) = 0;
    return;
    // 0x8080005C: sw          $zero, 0x164($a0)
    MEM_W(0X164, ctx->r4) = 0;
;}
RECOMP_FUNC void sumumbofx_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080138C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801390: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801394: sw          $a1, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r5;
    // 0x80801398: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080139C: jal         0x800EE830
    // 0x808013A0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x808013A0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x808013A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013AC: jr          $ra
    // 0x808013B0: nop

    return;
    // 0x808013B0: nop

;}
RECOMP_FUNC void func_800C4B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4B64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C4B68: jr          $ra
    // 0x800C4B6C: swc1        $f12, -0x5670($at)
    MEM_W(-0X5670, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800C4B6C: swc1        $f12, -0x5670($at)
    MEM_W(-0X5670, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void _chclinker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873B8: syscall     560
    recomp_syscall_handler(rdram, ctx, 0x800873B8);
    return;
    // 0x800873BC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800C3394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3398: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C339C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C33A0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C33A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C33A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C33AC: beq         $t6, $zero, L_800C33CC
    if (ctx->r14 == 0) {
        // 0x800C33B0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800C33CC;
    }
    // 0x800C33B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C33B4: jal         0x800C1414
    // 0x800C33B8: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C33B8: nop

    after_0:
    // 0x800C33BC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C33C0: sw          $t7, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r15;
    // 0x800C33C4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800C33C8: sw          $t8, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r24;
L_800C33CC:
    // 0x800C33CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C33D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C33D4: jr          $ra
    // 0x800C33D8: nop

    return;
    // 0x800C33D8: nop

;}
RECOMP_FUNC void fxstep_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800568: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080056C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800578: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8080057C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80800580: jal         0x808003B4
    // 0x80800584: lbu         $a3, 0x27($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X27);
    func_808003B4_fxstep(rdram, ctx);
        goto after_0;
    // 0x80800584: lbu         $a3, 0x27($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X27);
    after_0:
    // 0x80800588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080058C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800590: jr          $ra
    // 0x80800594: nop

    return;
    // 0x80800594: nop

;}
RECOMP_FUNC void func_8009557C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009557C: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80095580: jr          $ra
    // 0x80095584: lbu         $v0, 0xC($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XC);
    return;
    // 0x80095584: lbu         $v0, 0xC($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XC);
;}
RECOMP_FUNC void func_80804F14_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804F14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804F18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804F1C: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    // 0x80804F20: jal         0x80801658
    // 0x80804F24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801658_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804F24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804F30: jr          $ra
    // 0x80804F34: nop

    return;
    // 0x80804F34: nop

;}
RECOMP_FUNC void func_80802C30_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80802C34: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80802C38: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80802C3C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80802C40: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80802C44: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80802C48: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80802C4C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80802C50: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80802C54: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80802C58: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80802C5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802C60: jal         0x800BE3F8
    // 0x80802C64: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800BE3F8(rdram, ctx);
        goto after_0;
    // 0x80802C64: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80802C68: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80802C6C: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80802C70: addiu       $s7, $zero, 0x237
    ctx->r23 = ADD32(0, 0X237);
    // 0x80802C74: beq         $t6, $zero, L_80802D6C
    if (ctx->r14 == 0) {
        // 0x80802C78: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80802D6C;
    }
    // 0x80802C78: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80802C7C: addiu       $s6, $zero, 0x254
    ctx->r22 = ADD32(0, 0X254);
    // 0x80802C80: addiu       $s5, $zero, 0x253
    ctx->r21 = ADD32(0, 0X253);
    // 0x80802C84: addiu       $s4, $zero, 0x267
    ctx->r20 = ADD32(0, 0X267);
L_80802C88:
    // 0x80802C88: jal         0x800E9E88
    // 0x80802C8C: nop

    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x80802C8C: nop

    after_1:
    // 0x80802C90: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80802C94: jal         0x800E9EB4
    // 0x80802C98: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x80802C98: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    after_2:
    // 0x80802C9C: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80802CA0: beq         $at, $zero, L_80802D5C
    if (ctx->r1 == 0) {
        // 0x80802CA4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80802D5C;
    }
    // 0x80802CA4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80802CA8: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
L_80802CAC:
    // 0x80802CAC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80802CB0: beql        $t8, $zero, L_80802D50
    if (ctx->r24 == 0) {
        // 0x80802CB4: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80802D50;
    }
    goto skip_0;
    // 0x80802CB4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_0:
    // 0x80802CB8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80802CBC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80802CC0: beql        $s0, $t9, L_80802D50
    if (ctx->r16 == ctx->r25) {
        // 0x80802CC4: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80802D50;
    }
    goto skip_1;
    // 0x80802CC4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_1:
    // 0x80802CC8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80802CCC: srl         $t0, $v0, 22
    ctx->r8 = S32(U32(ctx->r2) >> 22);
    // 0x80802CD0: beq         $s4, $t0, L_80802CE8
    if (ctx->r20 == ctx->r8) {
        // 0x80802CD4: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80802CE8;
    }
    // 0x80802CD4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80802CD8: beq         $s5, $t0, L_80802CE8
    if (ctx->r21 == ctx->r8) {
        // 0x80802CDC: nop
    
            goto L_80802CE8;
    }
    // 0x80802CDC: nop

    // 0x80802CE0: bne         $s6, $t0, L_80802D08
    if (ctx->r22 != ctx->r8) {
        // 0x80802CE4: nop
    
            goto L_80802D08;
    }
    // 0x80802CE4: nop

L_80802CE8:
    // 0x80802CE8: jal         0x80106790
    // 0x80802CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80802CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802CF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802CF4: jal         0x80802D9C
    // 0x80802CF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80802D9C_chstoneballcontrol(rdram, ctx);
        goto after_4;
    // 0x80802CF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80802CFC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80802D00: srl         $t1, $v0, 22
    ctx->r9 = S32(U32(ctx->r2) >> 22);
    // 0x80802D04: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80802D08:
    // 0x80802D08: bne         $v0, $zero, L_80802D30
    if (ctx->r2 != 0) {
        // 0x80802D0C: nop
    
            goto L_80802D30;
    }
    // 0x80802D0C: nop

    // 0x80802D10: lhu         $a1, 0x1A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X1A);
    // 0x80802D14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802D18: srl         $t2, $a1, 5
    ctx->r10 = S32(U32(ctx->r5) >> 5);
    // 0x80802D1C: jal         0x80802E30
    // 0x80802D20: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_80802E30_chstoneballcontrol(rdram, ctx);
        goto after_5;
    // 0x80802D20: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_5:
    // 0x80802D24: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80802D28: srl         $t3, $v0, 22
    ctx->r11 = S32(U32(ctx->r2) >> 22);
    // 0x80802D2C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80802D30:
    // 0x80802D30: bnel        $s7, $v0, L_80802D50
    if (ctx->r23 != ctx->r2) {
        // 0x80802D34: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80802D50;
    }
    goto skip_2;
    // 0x80802D34: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_2:
    // 0x80802D38: jal         0x80106790
    // 0x80802D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80802D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802D40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802D44: jal         0x80802EA0
    // 0x80802D48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80802EA0_chstoneballcontrol(rdram, ctx);
        goto after_7;
    // 0x80802D48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80802D4C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80802D50:
    // 0x80802D50: sltu        $at, $s1, $s3
    ctx->r1 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x80802D54: bnel        $at, $zero, L_80802CAC
    if (ctx->r1 != 0) {
        // 0x80802D58: lw          $t7, 0x8($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X8);
            goto L_80802CAC;
    }
    goto skip_3;
    // 0x80802D58: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    skip_3:
L_80802D5C:
    // 0x80802D5C: lw          $a0, 0x4($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X4);
    // 0x80802D60: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80802D64: bne         $a0, $zero, L_80802C88
    if (ctx->r4 != 0) {
        // 0x80802D68: nop
    
            goto L_80802C88;
    }
    // 0x80802D68: nop

L_80802D6C:
    // 0x80802D6C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80802D70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802D74: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80802D78: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80802D7C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80802D80: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80802D84: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80802D88: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80802D8C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80802D90: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80802D94: jr          $ra
    // 0x80802D98: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80802D98: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800A59B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A59B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A59BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A59C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A59C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A59C8: jal         0x800A5930
    // 0x800A59CC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800A5930(rdram, ctx);
        goto after_0;
    // 0x800A59CC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A59D0: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800A59D4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800A59D8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A59DC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800A59E0: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x800A59E4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A59E8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800A59EC: lh          $t0, 0x8($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X8);
    // 0x800A59F0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A59F4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A59F8: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x800A59FC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5A00: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5A04: lh          $t4, 0xC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XC);
    // 0x800A5A08: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A5A0C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800A5A10: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x800A5A14: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A5A18: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800A5A1C: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x800A5A20: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A5A24: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800A5A28: lh          $t0, 0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X12);
    // 0x800A5A2C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A5A30: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800A5A34: lh          $t2, 0x14($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X14);
    // 0x800A5A38: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5A44: jr          $ra
    // 0x800A5A48: nop

    return;
    // 0x800A5A48: nop

;}
RECOMP_FUNC void func_80800008_chgruntylairexttowerwindow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: beq         $a1, $at, L_80800030
    if (ctx->r5 == ctx->r1) {
        // 0x80800018: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800030;
    }
    // 0x80800018: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080001C: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800020: beq         $a1, $at, L_80800044
    if (ctx->r5 == ctx->r1) {
        // 0x80800024: nop
    
            goto L_80800044;
    }
    // 0x80800024: nop

    // 0x80800028: b           L_80800060
    // 0x8080002C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800060;
    // 0x8080002C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800030:
    // 0x80800030: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800034: jal         0x80086670
    // 0x80800038: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x8080003C: b           L_80800060
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800060;
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800044:
    // 0x80800044: jal         0x80800070
    // 0x80800048: nop

    func_80800070_chgruntylairexttowerwindow(rdram, ctx);
        goto after_1;
    // 0x80800048: nop

    after_1:
    // 0x8080004C: b           L_80800060
    // 0x80800050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800060;
    // 0x80800050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800054: b           L_80800060
    // 0x80800058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800060;
    // 0x80800058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080005C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800060:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void _bsdie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F98: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082F98);
    return;
    // 0x80082F9C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800B4134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4134: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B4138: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B413C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B4140: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B4144: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B4148: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B414C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B4150: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
    // 0x800B4154: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800B4158: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B415C: lh          $t6, 0x4($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X4);
    // 0x800B4160: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B4164: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x800B4168: beql        $t6, $zero, L_800B420C
    if (ctx->r14 == 0) {
        // 0x800B416C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B420C;
    }
    goto skip_0;
    // 0x800B416C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800B4170: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
L_800B4174:
    // 0x800B4174: lh          $t7, 0x0($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X0);
    // 0x800B4178: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B417C: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800B4180: bnel        $t7, $t9, L_800B41EC
    if (ctx->r15 != ctx->r25) {
        // 0x800B4184: lh          $a1, 0x0($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X0);
            goto L_800B41EC;
    }
    goto skip_1;
    // 0x800B4184: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    skip_1:
    // 0x800B4188: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x800B418C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B4190: sh          $t0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r8;
    // 0x800B4194: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x800B4198: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800B419C: jal         0x800B39D0
    // 0x800B41A0: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    func_800B39D0(rdram, ctx);
        goto after_0;
    // 0x800B41A0: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    after_0:
    // 0x800B41A4: lh          $t2, 0x2($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X2);
    // 0x800B41A8: lh          $t3, 0x0($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X0);
    // 0x800B41AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B41B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B41B4: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B41B8: mflo        $a2
    ctx->r6 = lo;
    // 0x800B41BC: jal         0x8001BBC8
    // 0x800B41C0: nop

    aligned4_memcpy(rdram, ctx);
        goto after_1;
    // 0x800B41C0: nop

    after_1:
    // 0x800B41C4: sh          $s1, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r17;
    // 0x800B41C8: lh          $t4, 0x0($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X0);
    // 0x800B41CC: lh          $t5, 0x2($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X2);
    // 0x800B41D0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B41D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B41D8: jal         0x800B3B08
    // 0x800B41DC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    func_800B3B08(rdram, ctx);
        goto after_2;
    // 0x800B41DC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x800B41E0: b           L_800B420C
    // 0x800B41E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B420C;
    // 0x800B41E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B41E8: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
L_800B41EC:
    // 0x800B41EC: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x800B41F0: jal         0x800B39D0
    // 0x800B41F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    func_800B39D0(rdram, ctx);
        goto after_3;
    // 0x800B41F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_3:
    // 0x800B41F8: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800B41FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B4200: bnel        $t6, $zero, L_800B4174
    if (ctx->r14 != 0) {
        // 0x800B4204: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800B4174;
    }
    goto skip_2;
    // 0x800B4204: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_2:
    // 0x800B4208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B420C:
    // 0x800B420C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B4210: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B4214: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4218: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B421C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B4220: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B4224: jr          $ra
    // 0x800B4228: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800B4228: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _baeggaim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AA8: syscall     127
    recomp_syscall_handler(rdram, ctx, 0x80084AA8);
    return;
    // 0x80084AAC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800F98_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800FA4: jal         0x800EB854
    // 0x80800FA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EB854(rdram, ctx);
        goto after_0;
    // 0x80800FA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800FAC: bne         $v0, $zero, L_80801018
    if (ctx->r2 != 0) {
        // 0x80800FB0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801018;
    }
    // 0x80800FB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800FB4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800FBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800FC0: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x80800FC4: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800FC8: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x80800FCC: beq         $at, $zero, L_80800FF0
    if (ctx->r1 == 0) {
        // 0x80800FD0: nop
    
            goto L_80800FF0;
    }
    // 0x80800FD0: nop

    // 0x80800FD4: jal         0x800DF744
    // 0x80800FD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800FD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800FDC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800FE0: jal         0x800DF744
    // 0x80800FE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800FE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800FE8: b           L_80801008
    // 0x80800FEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80801008;
    // 0x80800FEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800FF0:
    // 0x80800FF0: jal         0x800DF744
    // 0x80800FF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800FF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800FF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800FFC: jal         0x800DF744
    // 0x80801000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x80801000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80801004: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80801008:
    // 0x80801008: jal         0x80101870
    // 0x8080100C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_5;
    // 0x8080100C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_5:
    // 0x80801010: b           L_80801034
    // 0x80801014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801034;
    // 0x80801014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801018:
    // 0x80801018: jal         0x80100094
    // 0x8080101C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x8080101C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80801020: beq         $v0, $zero, L_80801030
    if (ctx->r2 == 0) {
        // 0x80801024: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801030;
    }
    // 0x80801024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801028: jal         0x80087CA0
    // 0x8080102C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x8080102C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_7:
L_80801030:
    // 0x80801030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801034:
    // 0x80801034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801038: jr          $ra
    // 0x8080103C: nop

    return;
    // 0x8080103C: nop

;}
RECOMP_FUNC void dbskeleton_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    return;
    // 0x80800004: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
;}
RECOMP_FUNC void bssnowball_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B30: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800B34: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(356, 0X1094) << 16);
    // 0x80800B38: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B3C: jr          $ra
    // 0x80800B40: lw          $v0, 0x1094($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X1094));
    return;
    // 0x80800B40: lw          $v0, 0x1094($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X1094));
;}
