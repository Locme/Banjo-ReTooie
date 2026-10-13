#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bamovespline_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084EC0: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084EC0);
    return;
    // 0x80084EC4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800DC0_suegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800DCC: jal         0x800D3948
    // 0x80800DD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80800DD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800DD4: bnel        $v0, $zero, L_80800E14
    if (ctx->r2 != 0) {
        // 0x80800DD8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800E14;
    }
    goto skip_0;
    // 0x80800DD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800DDC: jal         0x800F6CC8
    // 0x80800DE0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F6CC8(rdram, ctx);
        goto after_1;
    // 0x80800DE0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800DE4: beq         $v0, $zero, L_80800E10
    if (ctx->r2 == 0) {
        // 0x80800DE8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800E10;
    }
    // 0x80800DE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800DEC: jal         0x80100094
    // 0x80800DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800DF4: lbu         $t7, 0x39($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X39);
    // 0x80800DF8: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80800DFC: sb          $t8, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r24;
    // 0x80800E00: jal         0x808001D4
    // 0x80800E04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    suegg_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800E04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800E08: b           L_80800E14
    // 0x80800E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E14;
    // 0x80800E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E10:
    // 0x80800E10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E14:
    // 0x80800E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E1C: jr          $ra
    // 0x80800E20: nop

    return;
    // 0x80800E20: nop

    // 0x80800E24: nop

    // 0x80800E28: nop

    // 0x80800E2C: nop

;}
RECOMP_FUNC void func_80093504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009350C: lw          $a0, 0x50($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X50);
    // 0x80093510: jal         0x800F23D0
    // 0x80093514: addiu       $a0, $a0, 0xCC
    ctx->r4 = ADD32(ctx->r4, 0XCC);
    func_800F23D0(rdram, ctx);
        goto after_0;
    // 0x80093514: addiu       $a0, $a0, 0xCC
    ctx->r4 = ADD32(ctx->r4, 0XCC);
    after_0:
    // 0x80093518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009351C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80093520: jr          $ra
    // 0x80093524: nop

    return;
    // 0x80093524: nop

;}
RECOMP_FUNC void func_800A73F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A73F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A73F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A73FC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A7400: addiu       $s1, $s1, 0x7658
    ctx->r17 = ADD32(ctx->r17, 0X7658);
    // 0x800A7404: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x800A7408: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x800A740C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A7410: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A7414: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800A7418: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800A741C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800A7420: jal         0x800A8670
    // 0x800A7424: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_800A8670(rdram, ctx);
        goto after_0;
    // 0x800A7424: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x800A7428: jal         0x800A9378
    // 0x800A742C: nop

    func_800A9378(rdram, ctx);
        goto after_1;
    // 0x800A742C: nop

    after_1:
    // 0x800A7430: jal         0x800F5184
    // 0x800A7434: nop

    func_800F5184(rdram, ctx);
        goto after_2;
    // 0x800A7434: nop

    after_2:
    // 0x800A7438: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A743C: jal         0x800A8BA8
    // 0x800A7440: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800A8BA8(rdram, ctx);
        goto after_3;
    // 0x800A7440: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800A7444: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A7448: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800A744C: jal         0x800A8BD4
    // 0x800A7450: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800A8BD4(rdram, ctx);
        goto after_4;
    // 0x800A7450: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x800A7454: beql        $v0, $zero, L_800A748C
    if (ctx->r2 == 0) {
        // 0x800A7458: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800A748C;
    }
    goto skip_0;
    // 0x800A7458: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_800A745C:
    // 0x800A745C: jal         0x800A89F8
    // 0x800A7460: nop

    func_800A89F8(rdram, ctx);
        goto after_5;
    // 0x800A7460: nop

    after_5:
    // 0x800A7464: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A7468: jal         0x800E9F20
    // 0x800A746C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E9F20(rdram, ctx);
        goto after_6;
    // 0x800A746C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800A7470: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A7474: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800A7478: jal         0x800A8BD4
    // 0x800A747C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800A8BD4(rdram, ctx);
        goto after_7;
    // 0x800A747C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800A7480: bne         $v0, $zero, L_800A745C
    if (ctx->r2 != 0) {
        // 0x800A7484: nop
    
            goto L_800A745C;
    }
    // 0x800A7484: nop

    // 0x800A7488: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800A748C:
    // 0x800A748C: jal         0x800A8CCC
    // 0x800A7490: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800A8CCC(rdram, ctx);
        goto after_8;
    // 0x800A7490: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800A7494: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A7498: lh          $t8, 0x7632($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7632);
    // 0x800A749C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A74A0: bne         $t8, $at, L_800A74B0
    if (ctx->r24 != ctx->r1) {
        // 0x800A74A4: nop
    
            goto L_800A74B0;
    }
    // 0x800A74A4: nop

    // 0x800A74A8: jal         0x800A9AA4
    // 0x800A74AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A9AA4(rdram, ctx);
        goto after_9;
    // 0x800A74AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
L_800A74B0:
    // 0x800A74B0: jal         0x800EA358
    // 0x800A74B4: nop

    func_800EA358(rdram, ctx);
        goto after_10;
    // 0x800A74B4: nop

    after_10:
    // 0x800A74B8: beq         $v0, $zero, L_800A74C8
    if (ctx->r2 == 0) {
        // 0x800A74BC: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_800A74C8;
    }
    // 0x800A74BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800A74C0: jal         0x800EB51C
    // 0x800A74C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EB51C(rdram, ctx);
        goto after_11;
    // 0x800A74C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
L_800A74C8:
    // 0x800A74C8: jal         0x800C0984
    // 0x800A74CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800C0984(rdram, ctx);
        goto after_12;
    // 0x800A74CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800A74D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A74D4: jal         0x800C9358
    // 0x800A74D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800C9358(rdram, ctx);
        goto after_13;
    // 0x800A74D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x800A74DC: jal         0x800C0130
    // 0x800A74E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800C0130(rdram, ctx);
        goto after_14;
    // 0x800A74E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x800A74E4: jal         0x800EA358
    // 0x800A74E8: nop

    func_800EA358(rdram, ctx);
        goto after_15;
    // 0x800A74E8: nop

    after_15:
    // 0x800A74EC: beq         $v0, $zero, L_800A74FC
    if (ctx->r2 == 0) {
        // 0x800A74F0: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800A74FC;
    }
    // 0x800A74F0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A74F4: jal         0x800EB51C
    // 0x800A74F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EB51C(rdram, ctx);
        goto after_16;
    // 0x800A74F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_16:
L_800A74FC:
    // 0x800A74FC: jal         0x800FA508
    // 0x800A7500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FA508(rdram, ctx);
        goto after_17;
    // 0x800A7500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x800A7504: jal         0x800B7448
    // 0x800A7508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B7448(rdram, ctx);
        goto after_18;
    // 0x800A7508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x800A750C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A7510: jal         0x800C940C
    // 0x800A7514: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800C940C(rdram, ctx);
        goto after_19;
    // 0x800A7514: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_19:
    // 0x800A7518: jal         0x800E7EF4
    // 0x800A751C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E7EF4(rdram, ctx);
        goto after_20;
    // 0x800A751C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x800A7520: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A7524: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800A7528: subu        $a1, $t9, $a0
    ctx->r5 = SUB32(ctx->r25, ctx->r4);
    // 0x800A752C: sra         $t0, $a1, 6
    ctx->r8 = S32(SIGNED(ctx->r5) >> 6);
    // 0x800A7530: jal         0x8002E660
    // 0x800A7534: sll         $a1, $t0, 6
    ctx->r5 = S32(ctx->r8 << 6);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_21;
    // 0x800A7534: sll         $a1, $t0, 6
    ctx->r5 = S32(ctx->r8 << 6);
    after_21:
    // 0x800A7538: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A753C: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x800A7540: subu        $a1, $t2, $a0
    ctx->r5 = SUB32(ctx->r10, ctx->r4);
    // 0x800A7544: sra         $t3, $a1, 4
    ctx->r11 = S32(SIGNED(ctx->r5) >> 4);
    // 0x800A7548: jal         0x8002E660
    // 0x800A754C: sll         $a1, $t3, 4
    ctx->r5 = S32(ctx->r11 << 4);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_22;
    // 0x800A754C: sll         $a1, $t3, 4
    ctx->r5 = S32(ctx->r11 << 4);
    after_22:
    // 0x800A7550: jal         0x800F51A8
    // 0x800A7554: nop

    func_800F51A8(rdram, ctx);
        goto after_23;
    // 0x800A7554: nop

    after_23:
    // 0x800A7558: jal         0x800D36A8
    // 0x800A755C: nop

    func_800D36A8(rdram, ctx);
        goto after_24;
    // 0x800A755C: nop

    after_24:
    // 0x800A7560: jal         0x800FFC90
    // 0x800A7564: nop

    func_800FFC90(rdram, ctx);
        goto after_25;
    // 0x800A7564: nop

    after_25:
    // 0x800A7568: jal         0x800A89BC
    // 0x800A756C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A89BC(rdram, ctx);
        goto after_26;
    // 0x800A756C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x800A7570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7574: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A7578: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A757C: jr          $ra
    // 0x800A7580: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A7580: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080149C_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080149C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808014A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014A4: jal         0x80100094
    // 0x808014A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808014A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808014AC: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x808014B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808014B4: beql        $t6, $zero, L_808014C8
    if (ctx->r14 == 0) {
        // 0x808014B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808014C8;
    }
    goto skip_0;
    // 0x808014B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808014BC: jal         0x801042D8
    // 0x808014C0: nop

    func_801042D8(rdram, ctx);
        goto after_1;
    // 0x808014C0: nop

    after_1:
    // 0x808014C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014C8:
    // 0x808014C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014CC: jr          $ra
    // 0x808014D0: nop

    return;
    // 0x808014D0: nop

;}
RECOMP_FUNC void func_800EF174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF174: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800EF178: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EF17C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF180: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF184: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800EF188: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800EF18C: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EF190: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800EF194: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EF198: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800EF19C: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800EF1A0: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800EF1A4: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EF1A8: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800EF1AC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800EF1B0: jr          $ra
    // 0x800EF1B4: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x800EF1B4: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_8001C2D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C2D8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001C2DC: jr          $ra
    // 0x8001C2E0: lw          $v0, -0x3900($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3900);
    return;
    // 0x8001C2E0: lw          $v0, -0x3900($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3900);
;}
RECOMP_FUNC void bakey_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091AB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091AC0: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80091AC4: jal         0x800BD09C
    // 0x80091AC8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BD09C(rdram, ctx);
        goto after_0;
    // 0x80091AC8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80091ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091AD4: jr          $ra
    // 0x80091AD8: nop

    return;
    // 0x80091AD8: nop

;}
RECOMP_FUNC void gcsectionDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80088230
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _gclevel_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800014: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x80800018: bne         $at, $zero, L_80800080
    if (ctx->r1 != 0) {
        // 0x8080001C: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_80800080;
    }
    // 0x8080001C: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80800020: beql        $at, $zero, L_80800084
    if (ctx->r1 == 0) {
        // 0x80800024: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800084;
    }
    goto skip_0;
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800028: jal         0x80800144
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcsectionDll_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800030: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800034: jal         0x8080017C
    // 0x80800038: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    gcsectionDll_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800038: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_2:
    // 0x8080003C: beq         $v0, $zero, L_8080005C
    if (ctx->r2 == 0) {
        // 0x80800040: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_8080005C;
    }
    // 0x80800040: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800044: jal         0x80088368
    // 0x80800048: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800048: nop

    after_3:
    // 0x8080004C: jal         0x8001A578
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001A578(rdram, ctx);
        goto after_4;
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800054: b           L_80800070
    // 0x80800058: nop

        goto L_80800070;
    // 0x80800058: nop

L_8080005C:
    // 0x8080005C: addiu       $at, $zero, 0x189
    ctx->r1 = ADD32(0, 0X189);
    // 0x80800060: bne         $t6, $at, L_80800070
    if (ctx->r14 != ctx->r1) {
        // 0x80800064: nop
    
            goto L_80800070;
    }
    // 0x80800064: nop

    // 0x80800068: jal         0x8001A578
    // 0x8080006C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8001A578(rdram, ctx);
        goto after_5;
    // 0x8080006C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
L_80800070:
    // 0x80800070: jal         0x800F9178
    // 0x80800074: nop

    func_800F9178(rdram, ctx);
        goto after_6;
    // 0x80800074: nop

    after_6:
    // 0x80800078: jal         0x800A13B0
    // 0x8080007C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A13B0(rdram, ctx);
        goto after_7;
    // 0x8080007C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_7:
L_80800080:
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800084:
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_808003D8_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003E8: jal         0x800B53A4
    // 0x808003EC: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x808003EC: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_0:
    // 0x808003F0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808003F4: jal         0x80800234
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bssnowball_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800400: jal         0x80085248
    // 0x80800404: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    _basudie_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800404: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    after_2:
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: jal         0x8009C128
    // 0x80800410: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x80800410: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: addiu       $a1, $zero, 0x694
    ctx->r5 = ADD32(0, 0X694);
    // 0x8080041C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800420: jal         0x8009DB04
    // 0x80800424: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DB04(rdram, ctx);
        goto after_4;
    // 0x80800424: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_4:
    // 0x80800428: jal         0x8009D9D4
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D9D4(rdram, ctx);
        goto after_5;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800430: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(356, 0X1028) << 16);
    // 0x80800434: addiu       $t6, $t6, 0x1028
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(356, 0X1028));
    // 0x80800438: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080043C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800444: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800448: jal         0x800BBCB8
    // 0x8080044C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_6;
    // 0x8080044C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80800450: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(356, 0XF30) << 16);
    // 0x80800454: addiu       $t7, $t7, 0xF30
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(356, 0XF30));
    // 0x80800458: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080045C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800464: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800468: jal         0x800BBCB8
    // 0x8080046C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_7;
    // 0x8080046C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80800470: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(356, 0XF84) << 16);
    // 0x80800474: addiu       $t9, $t9, 0xF84
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(356, 0XF84));
    // 0x80800478: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8080047C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800480: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800484: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800488: jal         0x800BABB8
    // 0x8080048C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_8;
    // 0x8080048C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x80800490: jal         0x80085128
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basnowball_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080049C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808004A4: jr          $ra
    // 0x808004A8: nop

    return;
    // 0x808004A8: nop

;}
RECOMP_FUNC void ncpoddialog_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802920: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80802924: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80802928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080292C: and         $a1, $a3, $at
    ctx->r5 = ctx->r7 & ctx->r1;
    // 0x80802930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802934: srl         $t6, $a1, 16
    ctx->r14 = S32(U32(ctx->r5) >> 16);
    // 0x80802938: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8080293C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80802940: jal         0x80802958
    // 0x80802944: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    ncpoddialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80802944: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80802948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080294C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802950: jr          $ra
    // 0x80802954: nop

    return;
    // 0x80802954: nop

;}
RECOMP_FUNC void func_800F2EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2EA0: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800F2EA4: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800F2EA8: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x800F2EAC: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x800F2EB0: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800F2EB4: jr          $ra
    // 0x800F2EB8: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    return;
    // 0x800F2EB8: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void _bskazstilt_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083718: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083718);
    return;
    // 0x8008371C: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void func_80800114_bsbwhirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080011C: jal         0x8009EF1C
    // 0x80800120: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800120: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800124: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800128: jal         0x8009EF10
    // 0x8080012C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x8080012C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800130: bne         $v0, $zero, L_8080014C
    if (ctx->r2 != 0) {
        // 0x80800134: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8080014C;
    }
    // 0x80800134: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800138: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080013C: jal         0x8009B9B0
    // 0x80800140: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800140: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800144: b           L_80800170
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800170;
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080014C:
    // 0x8080014C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800150: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800154: lui         $a2, 0x43D4
    ctx->r6 = S32(0X43D4 << 16);
    // 0x80800158: jal         0x800F1214
    // 0x8080015C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x8080015C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    after_3:
    // 0x80800160: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800164: jal         0x8009B9B0
    // 0x80800168: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800168: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800170:
    // 0x80800170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void func_8010556C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010556C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80105570: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80105574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105578: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010557C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80105580: addiu       $a0, $a0, 0x6EC0
    ctx->r4 = ADD32(ctx->r4, 0X6EC0);
    // 0x80105584: jal         0x800B3044
    // 0x80105588: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    freelist_next(rdram, ctx);
        goto after_0;
    // 0x80105588: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8010558C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80105590: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80105594: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80105598: lhu         $t9, 0x7E($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X7E);
    // 0x8010559C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x801055A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801055A4: andi        $t0, $t9, 0xF000
    ctx->r8 = ctx->r25 & 0XF000;
    // 0x801055A8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x801055AC: sh          $t1, 0x7E($a3)
    MEM_H(0X7E, ctx->r7) = ctx->r9;
    // 0x801055B0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x801055B4: jal         0x8001BCF8
    // 0x801055B8: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    rare_memset(rdram, ctx);
        goto after_1;
    // 0x801055B8: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    after_1:
    // 0x801055BC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801055C0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801055C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801055C8: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x801055CC: lbu         $t6, 0x28($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X28);
    // 0x801055D0: lbu         $t9, 0x18($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18);
    // 0x801055D4: ori         $t4, $t3, 0x7FE
    ctx->r12 = ctx->r11 | 0X7FE;
    // 0x801055D8: ori         $t7, $t6, 0xE0
    ctx->r15 = ctx->r14 | 0XE0;
    // 0x801055DC: andi        $t8, $t9, 0xFF7F
    ctx->r24 = ctx->r25 & 0XFF7F;
    // 0x801055E0: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
    // 0x801055E4: sb          $t7, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r15;
    // 0x801055E8: sb          $t8, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r24;
    // 0x801055EC: jal         0x800E6A00
    // 0x801055F0: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
    func_800E6A00(rdram, ctx);
        goto after_2;
    // 0x801055F0: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
    after_2:
    // 0x801055F4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801055F8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x801055FC: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x80105600: lbu         $t3, 0x18($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X18);
    // 0x80105604: lbu         $t6, 0x27($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X27);
    // 0x80105608: andi        $t2, $t1, 0x40
    ctx->r10 = ctx->r9 & 0X40;
    // 0x8010560C: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x80105610: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80105614: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x80105618: sb          $t5, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r13;
    // 0x8010561C: sb          $t7, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r15;
    // 0x80105620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105624: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80105628: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8010562C: jr          $ra
    // 0x80105630: nop

    return;
    // 0x80105630: nop

;}
RECOMP_FUNC void func_8080038C_chweldarhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080038C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800390: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800394: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800398: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080039C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808003A4: jal         0x80100094
    // 0x808003A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808003B4: addiu       $at, $zero, 0x1360
    ctx->r1 = ADD32(0, 0X1360);
    // 0x808003B8: beq         $a0, $at, L_808003D4
    if (ctx->r4 == ctx->r1) {
        // 0x808003BC: addiu       $a1, $v1, 0x18
        ctx->r5 = ADD32(ctx->r3, 0X18);
            goto L_808003D4;
    }
    // 0x808003BC: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    // 0x808003C0: addiu       $at, $zero, 0x1384
    ctx->r1 = ADD32(0, 0X1384);
    // 0x808003C4: beq         $a0, $at, L_80800404
    if (ctx->r4 == ctx->r1) {
        // 0x808003C8: addiu       $a1, $v1, 0x18
        ctx->r5 = ADD32(ctx->r3, 0X18);
            goto L_80800404;
    }
    // 0x808003C8: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    // 0x808003CC: b           L_80800410
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800410;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003D4:
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x808003DC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x808003E0: jal         0x8008A2D0
    // 0x808003E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808003E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: jal         0x80108B04
    // 0x808003F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x808003F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808003F4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808003F8: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808003FC: b           L_80800418
    // 0x80800400: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
        goto L_80800418;
    // 0x80800400: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_80800404:
    // 0x80800404: jal         0x8008A2C0
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800410:
    // 0x80800410: jal         0x80102424
    // 0x80800414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_80800418:
    // 0x80800418: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080041C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800420: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800424: jr          $ra
    // 0x80800428: nop

    return;
    // 0x80800428: nop

    // 0x8080042C: nop

;}
RECOMP_FUNC void func_80800DF0_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DF0: jr          $ra
    // 0x80800DF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800DF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800544_chboxingglove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800544: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800548: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080054C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800550: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800554: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800558: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080055C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800560: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80800564: jal         0x80100094
    // 0x80800568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080056C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800570: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800574: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
L_80800578:
    // 0x80800578: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080057C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80800580: jal         0x800F0064
    // 0x80800584: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F0064(rdram, ctx);
        goto after_1;
    // 0x80800584: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x80800588: beq         $v0, $zero, L_80800598
    if (ctx->r2 == 0) {
        // 0x8080058C: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800598;
    }
    // 0x8080058C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80800590: b           L_80800614
    // 0x80800594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800614;
    // 0x80800594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800598:
    // 0x80800598: bne         $s1, $s2, L_80800578
    if (ctx->r17 != ctx->r18) {
        // 0x8080059C: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80800578;
    }
    // 0x8080059C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x808005A0: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: jal         0x800EE7F8
    // 0x808005AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808005AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x808005B0: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x808005B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005B8: jal         0x800EE7F8
    // 0x808005BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808005BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x808005C0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x808005C4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808005C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005CC: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x808005D0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808005D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808005E4: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x808005E8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x808005EC: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x808005F0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808005F4: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x808005F8: jal         0x800BEF00
    // 0x808005FC: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_4;
    // 0x808005FC: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    after_4:
    // 0x80800600: beq         $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x80800604: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800610;
    }
    // 0x80800604: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800608: b           L_80800610
    // 0x8080060C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800610;
    // 0x8080060C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800610:
    // 0x80800610: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800614:
    // 0x80800614: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800618: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080061C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800620: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800624: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800628: jr          $ra
    // 0x8080062C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8080062C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800C54CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C54CC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C54D0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C54D4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C54D8: addiu       $t7, $t7, -0x5660
    ctx->r15 = ADD32(ctx->r15, -0X5660);
    // 0x800C54DC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C54E0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C54E4: swc1        $f12, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f12.u32l;
    // 0x800C54E8: jr          $ra
    // 0x800C54EC: swc1        $f14, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f14.u32l;
    return;
    // 0x800C54EC: swc1        $f14, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f14.u32l;
;}
RECOMP_FUNC void _chlightfader_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863F0: syscall     321
    recomp_syscall_handler(rdram, ctx, 0x800863F0);
    return;
    // 0x800863F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80803388_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803388: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080338C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803390: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803398: jal         0x80106790
    // 0x8080339C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080339C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808033A0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808033A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808033A8: jal         0x80100094
    // 0x808033AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808033AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808033B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X4074) << 16);
    // 0x808033B4: lwc1        $f4, 0x4074($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X4074));
    // 0x808033B8: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x808033BC: jal         0x800C8A98
    // 0x808033C0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x808033C0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x808033C4: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808033C8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808033CC: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x808033D0: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808033D4: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x808033D8: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x808033DC: lbu         $t1, 0x93($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X93);
    // 0x808033E0: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x808033E4: beq         $at, $zero, L_808033F8
    if (ctx->r1 == 0) {
        // 0x808033E8: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_808033F8;
    }
    // 0x808033E8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808033EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808033F0: b           L_80803408
    // 0x808033F4: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_80803408;
    // 0x808033F4: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_808033F8:
    // 0x808033F8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808033FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803400: nop

    // 0x80803404: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_80803408:
    // 0x80803408: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8080340C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803410: nop

    // 0x80803414: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80803418: lbu         $t2, 0x93($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X93);
    // 0x8080341C: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x80803420: beq         $at, $zero, L_80803434
    if (ctx->r1 == 0) {
        // 0x80803424: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80803434;
    }
    // 0x80803424: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80803428: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080342C: b           L_80803444
    // 0x80803430: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
        goto L_80803444;
    // 0x80803430: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
L_80803434:
    // 0x80803434: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80803438: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080343C: nop

    // 0x80803440: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
L_80803444:
    // 0x80803444: lbu         $t3, 0x93($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X93);
    // 0x80803448: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x8080344C: beq         $at, $zero, L_80803460
    if (ctx->r1 == 0) {
        // 0x80803450: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1676, 0X4078) << 16);
            goto L_80803460;
    }
    // 0x80803450: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X4078) << 16);
    // 0x80803454: lwc1        $f4, 0x4078($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X4078));
    // 0x80803458: b           L_8080346C
    // 0x8080345C: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
        goto L_8080346C;
    // 0x8080345C: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
L_80803460:
    // 0x80803460: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X407C) << 16);
    // 0x80803464: lwc1        $f6, 0x407C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X407C));
    // 0x80803468: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
L_8080346C:
    // 0x8080346C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80803470: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80803474: jal         0x800EE7F8
    // 0x80803478: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80803478: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_3:
    // 0x8080347C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80803480: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803484: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80803488: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080348C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803490: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80803494: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80803498: jal         0x800F1DF4
    // 0x8080349C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    func_800F1DF4(rdram, ctx);
        goto after_4;
    // 0x8080349C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x808034A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808034A4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808034A8: jal         0x800F1828
    // 0x808034AC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F1828(rdram, ctx);
        goto after_5;
    // 0x808034AC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x808034B0: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x808034B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808034B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808034BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808034C0: jr          $ra
    // 0x808034C4: nop

    return;
    // 0x808034C4: nop

;}
RECOMP_FUNC void bscarry_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800648: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080064C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(132, 0X7D0) << 16);
    // 0x80800650: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800654: jr          $ra
    // 0x80800658: lw          $v0, 0x7D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(132, 0X7D0));
    return;
    // 0x80800658: lw          $v0, 0x7D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(132, 0X7D0));
;}
RECOMP_FUNC void func_800F3780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3780: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F3784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F3788: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F378C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F3790: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800F3794: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800F3798: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800F379C: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x800F37A0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800F37A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800F37A8: bc1f        L_800F37BC
    if (!c1cs) {
        // 0x800F37AC: sll         $t8, $a2, 3
        ctx->r24 = S32(ctx->r6 << 3);
            goto L_800F37BC;
    }
    // 0x800F37AC: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x800F37B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F37B4: b           L_800F3840
    // 0x800F37B8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_800F3840;
    // 0x800F37B8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800F37BC:
    // 0x800F37BC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800F37C0: lwc1        $f6, -0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, -0X8);
    // 0x800F37C4: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800F37C8: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x800F37CC: nop

    // 0x800F37D0: bc1f        L_800F37E4
    if (!c1cs) {
        // 0x800F37D4: nop
    
            goto L_800F37E4;
    }
    // 0x800F37D4: nop

    // 0x800F37D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F37DC: b           L_800F3840
    // 0x800F37E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_800F3840;
    // 0x800F37E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800F37E4:
    // 0x800F37E4: bne         $at, $zero, L_800F3840
    if (ctx->r1 != 0) {
        // 0x800F37E8: subu        $t1, $t0, $a0
        ctx->r9 = SUB32(ctx->r8, ctx->r4);
            goto L_800F3840;
    }
    // 0x800F37E8: subu        $t1, $t0, $a0
    ctx->r9 = SUB32(ctx->r8, ctx->r4);
L_800F37EC:
    // 0x800F37EC: bgez        $t1, L_800F37FC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800F37F0: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_800F37FC;
    }
    // 0x800F37F0: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800F37F4: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x800F37F8: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_800F37FC:
    // 0x800F37FC: addu        $v0, $t2, $a0
    ctx->r2 = ADD32(ctx->r10, ctx->r4);
    // 0x800F3800: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x800F3804: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800F3808: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800F380C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F3810: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x800F3814: nop

    // 0x800F3818: bc1fl       L_800F3830
    if (!c1cs) {
        // 0x800F381C: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_800F3830;
    }
    goto skip_0;
    // 0x800F381C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    skip_0:
    // 0x800F3820: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F3824: b           L_800F3834
    // 0x800F3828: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800F3834;
    // 0x800F3828: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F382C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800F3830:
    // 0x800F3830: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
L_800F3834:
    // 0x800F3834: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800F3838: bnel        $at, $zero, L_800F37EC
    if (ctx->r1 != 0) {
        // 0x800F383C: subu        $t1, $t0, $a0
        ctx->r9 = SUB32(ctx->r8, ctx->r4);
            goto L_800F37EC;
    }
    goto skip_1;
    // 0x800F383C: subu        $t1, $t0, $a0
    ctx->r9 = SUB32(ctx->r8, ctx->r4);
    skip_1:
L_800F3840:
    // 0x800F3840: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x800F3844: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x800F3848: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x800F384C: addu        $v0, $t5, $a1
    ctx->r2 = ADD32(ctx->r13, ctx->r5);
    // 0x800F3850: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800F3854: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F3858: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x800F385C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x800F3860: jal         0x800F10B4
    // 0x800F3864: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x800F3864: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800F3868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F386C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F3870: jr          $ra
    // 0x800F3874: nop

    return;
    // 0x800F3874: nop

    // 0x800F3878: nop

    // 0x800F387C: nop

;}
RECOMP_FUNC void func_80106D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106D60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80106D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106D68: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80106D6C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80106D70: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80106D74: jal         0x800C87B8
    // 0x80106D78: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800C87B8(rdram, ctx);
        goto after_0;
    // 0x80106D78: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80106D7C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80106D80: jal         0x80106DA4
    // 0x80106D84: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80106DA4(rdram, ctx);
        goto after_1;
    // 0x80106D84: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80106D88: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80106D8C: jal         0x800B38A8
    // 0x80106D90: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800B38A8(rdram, ctx);
        goto after_2;
    // 0x80106D90: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80106D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106D98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80106D9C: jr          $ra
    // 0x80106DA0: nop

    return;
    // 0x80106DA0: nop

;}
RECOMP_FUNC void func_800DA7A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA7A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800DA7AC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800DA7B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800DA7B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800DA7B8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800DA7BC: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800DA7C0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800DA7C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800DA7C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800DA7CC: bltz        $a0, L_800DA814
    if (SIGNED(ctx->r4) < 0) {
        // 0x800DA7D0: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800DA814;
    }
    // 0x800DA7D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DA7D4: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x800DA7D8: beql        $at, $zero, L_800DA818
    if (ctx->r1 == 0) {
        // 0x800DA7DC: slti        $at, $s2, 0x29
        ctx->r1 = SIGNED(ctx->r18) < 0X29 ? 1 : 0;
            goto L_800DA818;
    }
    goto skip_0;
    // 0x800DA7DC: slti        $at, $s2, 0x29
    ctx->r1 = SIGNED(ctx->r18) < 0X29 ? 1 : 0;
    skip_0:
    // 0x800DA7E0: blez        $a2, L_800DA924
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800DA7E4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800DA924;
    }
    // 0x800DA7E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800DA7E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
L_800DA7EC:
    // 0x800DA7EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DA7F0: sllv        $t7, $t6, $s0
    ctx->r15 = S32(ctx->r14 << (ctx->r16 & 31));
    // 0x800DA7F4: and         $a1, $t7, $s4
    ctx->r5 = ctx->r15 & ctx->r20;
    // 0x800DA7F8: jal         0x800DA3B8
    // 0x800DA7FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_0;
    // 0x800DA7FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800DA800: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800DA804: bne         $s0, $s3, L_800DA7EC
    if (ctx->r16 != ctx->r19) {
        // 0x800DA808: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DA7EC;
    }
    // 0x800DA808: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800DA80C: b           L_800DA928
    // 0x800DA810: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800DA928;
    // 0x800DA810: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800DA814:
    // 0x800DA814: slti        $at, $s2, 0x29
    ctx->r1 = SIGNED(ctx->r18) < 0X29 ? 1 : 0;
L_800DA818:
    // 0x800DA818: bne         $at, $zero, L_800DA844
    if (ctx->r1 != 0) {
        // 0x800DA81C: slti        $at, $s2, 0x5A5
        ctx->r1 = SIGNED(ctx->r18) < 0X5A5 ? 1 : 0;
            goto L_800DA844;
    }
    // 0x800DA81C: slti        $at, $s2, 0x5A5
    ctx->r1 = SIGNED(ctx->r18) < 0X5A5 ? 1 : 0;
    // 0x800DA820: beq         $at, $zero, L_800DA844
    if (ctx->r1 == 0) {
        // 0x800DA824: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA844;
    }
    // 0x800DA824: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA828: lw          $a0, -0x3890($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3890);
    // 0x800DA82C: addiu       $a1, $s2, -0x28
    ctx->r5 = ADD32(ctx->r18, -0X28);
    // 0x800DA830: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800DA834: jal         0x800D9F84
    // 0x800DA838: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    bitfield_set_n_bits(rdram, ctx);
        goto after_1;
    // 0x800DA838: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
    // 0x800DA83C: b           L_800DA928
    // 0x800DA840: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800DA928;
    // 0x800DA840: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800DA844:
    // 0x800DA844: slti        $at, $s2, 0x641
    ctx->r1 = SIGNED(ctx->r18) < 0X641 ? 1 : 0;
    // 0x800DA848: bne         $at, $zero, L_800DA874
    if (ctx->r1 != 0) {
        // 0x800DA84C: slti        $at, $s2, 0x6ED
        ctx->r1 = SIGNED(ctx->r18) < 0X6ED ? 1 : 0;
            goto L_800DA874;
    }
    // 0x800DA84C: slti        $at, $s2, 0x6ED
    ctx->r1 = SIGNED(ctx->r18) < 0X6ED ? 1 : 0;
    // 0x800DA850: beq         $at, $zero, L_800DA874
    if (ctx->r1 == 0) {
        // 0x800DA854: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA874;
    }
    // 0x800DA854: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA858: lw          $a0, -0x388C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X388C);
    // 0x800DA85C: addiu       $a1, $s2, -0x640
    ctx->r5 = ADD32(ctx->r18, -0X640);
    // 0x800DA860: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800DA864: jal         0x800D9F84
    // 0x800DA868: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    bitfield_set_n_bits(rdram, ctx);
        goto after_2;
    // 0x800DA868: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_2:
    // 0x800DA86C: b           L_800DA928
    // 0x800DA870: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800DA928;
    // 0x800DA870: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800DA874:
    // 0x800DA874: slti        $at, $s2, 0x9C5
    ctx->r1 = SIGNED(ctx->r18) < 0X9C5 ? 1 : 0;
    // 0x800DA878: bne         $at, $zero, L_800DA8A4
    if (ctx->r1 != 0) {
        // 0x800DA87C: slti        $at, $s2, 0xAC4
        ctx->r1 = SIGNED(ctx->r18) < 0XAC4 ? 1 : 0;
            goto L_800DA8A4;
    }
    // 0x800DA87C: slti        $at, $s2, 0xAC4
    ctx->r1 = SIGNED(ctx->r18) < 0XAC4 ? 1 : 0;
    // 0x800DA880: beq         $at, $zero, L_800DA8A4
    if (ctx->r1 == 0) {
        // 0x800DA884: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA8A4;
    }
    // 0x800DA884: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA888: lw          $a0, -0x3888($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3888);
    // 0x800DA88C: addiu       $a1, $s2, -0x9C4
    ctx->r5 = ADD32(ctx->r18, -0X9C4);
    // 0x800DA890: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800DA894: jal         0x800D9F84
    // 0x800DA898: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    bitfield_set_n_bits(rdram, ctx);
        goto after_3;
    // 0x800DA898: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_3:
    // 0x800DA89C: b           L_800DA928
    // 0x800DA8A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800DA928;
    // 0x800DA8A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800DA8A4:
    // 0x800DA8A4: slti        $at, $s2, 0xBB9
    ctx->r1 = SIGNED(ctx->r18) < 0XBB9 ? 1 : 0;
    // 0x800DA8A8: bne         $at, $zero, L_800DA8FC
    if (ctx->r1 != 0) {
        // 0x800DA8AC: slti        $at, $s2, 0xC16
        ctx->r1 = SIGNED(ctx->r18) < 0XC16 ? 1 : 0;
            goto L_800DA8FC;
    }
    // 0x800DA8AC: slti        $at, $s2, 0xC16
    ctx->r1 = SIGNED(ctx->r18) < 0XC16 ? 1 : 0;
    // 0x800DA8B0: beq         $at, $zero, L_800DA8FC
    if (ctx->r1 == 0) {
        // 0x800DA8B4: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_800DA8FC;
    }
    // 0x800DA8B4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800DA8B8: addiu       $s1, $s1, -0x3880
    ctx->r17 = ADD32(ctx->r17, -0X3880);
    // 0x800DA8BC: addiu       $s0, $s2, -0xBB8
    ctx->r16 = ADD32(ctx->r18, -0XBB8);
    // 0x800DA8C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800DA8C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DA8C8: jal         0x800D9EA0
    // 0x800DA8CC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    bitfield_get_n_bits(rdram, ctx);
        goto after_4;
    // 0x800DA8CC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_4:
    // 0x800DA8D0: beql        $v0, $s4, L_800DA8E4
    if (ctx->r2 == ctx->r20) {
        // 0x800DA8D4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800DA8E4;
    }
    goto skip_1;
    // 0x800DA8D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x800DA8D8: jal         0x800DA544
    // 0x800DA8DC: addiu       $a0, $zero, 0xD54
    ctx->r4 = ADD32(0, 0XD54);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x800DA8DC: addiu       $a0, $zero, 0xD54
    ctx->r4 = ADD32(0, 0XD54);
    after_5:
    // 0x800DA8E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800DA8E4:
    // 0x800DA8E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800DA8E8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800DA8EC: jal         0x800D9F84
    // 0x800DA8F0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    bitfield_set_n_bits(rdram, ctx);
        goto after_6;
    // 0x800DA8F0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_6:
    // 0x800DA8F4: b           L_800DA928
    // 0x800DA8F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800DA928;
    // 0x800DA8F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800DA8FC:
    // 0x800DA8FC: slti        $at, $s2, 0xD49
    ctx->r1 = SIGNED(ctx->r18) < 0XD49 ? 1 : 0;
    // 0x800DA900: bne         $at, $zero, L_800DA924
    if (ctx->r1 != 0) {
        // 0x800DA904: slti        $at, $s2, 0xD75
        ctx->r1 = SIGNED(ctx->r18) < 0XD75 ? 1 : 0;
            goto L_800DA924;
    }
    // 0x800DA904: slti        $at, $s2, 0xD75
    ctx->r1 = SIGNED(ctx->r18) < 0XD75 ? 1 : 0;
    // 0x800DA908: beq         $at, $zero, L_800DA924
    if (ctx->r1 == 0) {
        // 0x800DA90C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA924;
    }
    // 0x800DA90C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA910: addiu       $a0, $a0, -0x3874
    ctx->r4 = ADD32(ctx->r4, -0X3874);
    // 0x800DA914: addiu       $a1, $s2, -0xD48
    ctx->r5 = ADD32(ctx->r18, -0XD48);
    // 0x800DA918: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800DA91C: jal         0x800D9F84
    // 0x800DA920: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    bitfield_set_n_bits(rdram, ctx);
        goto after_7;
    // 0x800DA920: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_7:
L_800DA924:
    // 0x800DA924: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800DA928:
    // 0x800DA928: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DA92C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA930: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800DA934: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800DA938: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800DA93C: jr          $ra
    // 0x800DA940: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800DA940: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808005F0_bstaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808005F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808005FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800600: jal         0x80800144
    // 0x80800604: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    bstaxi_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800604: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080060C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800610: jal         0x80085338
    // 0x80800614: lw          $a2, 0x16C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X16C);
    _batimer_set(rdram, ctx);
        goto after_1;
    // 0x80800614: lw          $a2, 0x16C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X16C);
    after_1:
    // 0x80800618: jal         0x8008CABC
    // 0x8080061C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_2;
    // 0x8080061C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800620: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800624: jal         0x8008AF24
    // 0x80800628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_3;
    // 0x80800628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: jal         0x8008AED4
    // 0x80800634: addiu       $a1, $zero, 0x24A
    ctx->r5 = ADD32(0, 0X24A);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80800634: addiu       $a1, $zero, 0x24A
    ctx->r5 = ADD32(0, 0X24A);
    after_4:
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080063C: jal         0x8008B1BC
    // 0x80800640: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80800640: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_5:
    // 0x80800644: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800648: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080064C: jal         0x8008B1C8
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_6;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800658: jal         0x8008B134
    // 0x8080065C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x8080065C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800660: jal         0x8008B064
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800668: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x8080066C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800678: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080067C: jal         0x8009FFD8
    // 0x80800680: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x80800680: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x80800684: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800688: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x8080068C: jal         0x8009C99C
    // 0x80800690: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_10;
    // 0x80800690: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_10:
    // 0x80800694: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x80800698: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080069C: jal         0x8009C128
    // 0x808006A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009C128(rdram, ctx);
        goto after_11;
    // 0x808006A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x808006A4: jal         0x80096364
    // 0x808006A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80096364(rdram, ctx);
        goto after_12;
    // 0x808006A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x808006AC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808006B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006B4: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808006B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006BC: add.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808006C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808006C4: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x808006C8: nop

    // 0x808006CC: bc1f        L_808006D8
    if (!c1cs) {
        // 0x808006D0: nop
    
            goto L_808006D8;
    }
    // 0x808006D0: nop

    // 0x808006D4: add.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
L_808006D8:
    // 0x808006D8: jal         0x80084E48
    // 0x808006DC: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    _bamovehover_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x808006DC: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_13:
    // 0x808006E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006E4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808006E8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808006EC: jr          $ra
    // 0x808006F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808006F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_808019C8_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808019CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808019D0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(932, 0X2ACC) << 16);
    // 0x808019D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808019D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808019DC: addiu       $t6, $t6, 0x2ACC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(932, 0X2ACC));
    // 0x808019E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808019E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808019E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808019EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808019F0: jal         0x800BBCB8
    // 0x808019F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x808019F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x808019F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808019FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801A00: jr          $ra
    // 0x80801A04: nop

    return;
    // 0x80801A04: nop

;}
RECOMP_FUNC void func_800BD860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD860: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800BD864: addiu       $t1, $t1, -0x7BF0
    ctx->r9 = ADD32(ctx->r9, -0X7BF0);
    // 0x800BD868: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800BD86C: lw          $t8, 0x20($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X20);
    // 0x800BD870: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800BD874: subu        $v0, $a0, $t6
    ctx->r2 = SUB32(ctx->r4, ctx->r14);
    // 0x800BD878: sra         $t7, $v0, 3
    ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800BD87C: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x800BD880: mflo        $t9
    ctx->r25 = lo;
    // 0x800BD884: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800BD888: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x800BD88C: lw          $t5, 0x1C($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X1C);
    // 0x800BD890: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800BD894: multu       $t2, $t9
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD898: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x800BD89C: bne         $t8, $zero, L_800BD8A8
    if (ctx->r24 != 0) {
        // 0x800BD8A0: nop
    
            goto L_800BD8A8;
    }
    // 0x800BD8A0: nop

    // 0x800BD8A4: break       7
    do_break(2148260004);
L_800BD8A8:
    // 0x800BD8A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD8AC: bne         $t8, $at, L_800BD8C0
    if (ctx->r24 != ctx->r1) {
        // 0x800BD8B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD8C0;
    }
    // 0x800BD8B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD8B4: bne         $v0, $at, L_800BD8C0
    if (ctx->r2 != ctx->r1) {
        // 0x800BD8B8: nop
    
            goto L_800BD8C0;
    }
    // 0x800BD8B8: nop

    // 0x800BD8BC: break       6
    do_break(2148260028);
L_800BD8C0:
    // 0x800BD8C0: mflo        $t4
    ctx->r12 = lo;
    // 0x800BD8C4: subu        $v1, $v0, $t4
    ctx->r3 = SUB32(ctx->r2, ctx->r12);
    // 0x800BD8C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BD8CC: div         $zero, $v1, $t5
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r13)));
    // 0x800BD8D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800BD8D4: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800BD8D8: lw          $t7, 0x1C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X1C);
    // 0x800BD8DC: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x800BD8E0: addiu       $v0, $v0, -0x7BE4
    ctx->r2 = ADD32(ctx->r2, -0X7BE4);
    // 0x800BD8E4: multu       $t7, $t6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD8E8: addiu       $t0, $t0, -0x7BF0
    ctx->r8 = ADD32(ctx->r8, -0X7BF0);
    // 0x800BD8EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BD8F0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800BD8F4: bne         $t5, $zero, L_800BD900
    if (ctx->r13 != 0) {
        // 0x800BD8F8: nop
    
            goto L_800BD900;
    }
    // 0x800BD8F8: nop

    // 0x800BD8FC: break       7
    do_break(2148260092);
L_800BD900:
    // 0x800BD900: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD904: bne         $t5, $at, L_800BD918
    if (ctx->r13 != ctx->r1) {
        // 0x800BD908: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD918;
    }
    // 0x800BD908: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD90C: bne         $v1, $at, L_800BD918
    if (ctx->r3 != ctx->r1) {
        // 0x800BD910: nop
    
            goto L_800BD918;
    }
    // 0x800BD910: nop

    // 0x800BD914: break       6
    do_break(2148260116);
L_800BD918:
    // 0x800BD918: mflo        $t9
    ctx->r25 = lo;
    // 0x800BD91C: subu        $t2, $v1, $t9
    ctx->r10 = SUB32(ctx->r3, ctx->r25);
    // 0x800BD920: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_800BD924:
    // 0x800BD924: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800BD928: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x800BD92C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800BD930: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800BD934: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800BD938: bne         $t0, $v0, L_800BD924
    if (ctx->r8 != ctx->r2) {
        // 0x800BD93C: sw          $t5, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = ctx->r13;
            goto L_800BD924;
    }
    // 0x800BD93C: sw          $t5, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r13;
    // 0x800BD940: jr          $ra
    // 0x800BD944: nop

    return;
    // 0x800BD944: nop

;}
RECOMP_FUNC void func_80800D18_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D20: jal         0x800839B8
    // 0x80800D24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800D24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D28: jal         0x808004B8
    // 0x80800D2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800D2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D38: jr          $ra
    // 0x80800D3C: nop

    return;
    // 0x80800D3C: nop

;}
RECOMP_FUNC void func_80101074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101074: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80101078: jr          $ra
    // 0x8010107C: sw          $a0, 0x5A80($at)
    MEM_W(0X5A80, ctx->r1) = ctx->r4;
    return;
    // 0x8010107C: sw          $a0, 0x5A80($at)
    MEM_W(0X5A80, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _fxrain_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088900: syscall     710
    recomp_syscall_handler(rdram, ctx, 0x80088900);
    return;
    // 0x80088904: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void suspline_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080062C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800630: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800634: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800638: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3202, 0XEB0) << 16);
    // 0x8080063C: lwc1        $f4, 0xEB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3202, 0XEB0));
    // 0x80800640: lwc1        $f0, 0x58($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800648: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080064C: nop

    // 0x80800650: bc1fl       L_8080074C
    if (!c1cs) {
        // 0x80800654: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080074C;
    }
    goto skip_0;
    // 0x80800654: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800658: lbu         $t6, 0x8A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8A);
    // 0x8080065C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800660: bnel        $t7, $zero, L_8080074C
    if (ctx->r15 != 0) {
        // 0x80800664: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080074C;
    }
    goto skip_1;
    // 0x80800664: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800668: lh          $t8, 0x7A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X7A);
    // 0x8080066C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80800670: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80800674: lh          $t1, 0x68($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X68);
    // 0x80800678: addu        $a1, $t1, $a0
    ctx->r5 = ADD32(ctx->r9, ctx->r4);
    // 0x8080067C: lh          $a0, 0x78($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X78);
    // 0x80800680: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80800684: bnel        $at, $zero, L_808006CC
    if (ctx->r1 != 0) {
        // 0x80800688: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_808006CC;
    }
    goto skip_2;
    // 0x80800688: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    skip_2:
    // 0x8080068C: lwc1        $f6, 0x64($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X64);
    // 0x80800690: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800694: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800698: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080069C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808006A0: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x808006A4: addiu       $t2, $t2, -0x6EE8
    ctx->r10 = ADD32(ctx->r10, -0X6EE8);
    // 0x808006A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808006AC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x808006B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x808006B4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x808006B8: jal         0x80089140
    // 0x808006BC: nop

    _mlspline_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x808006BC: nop

    after_0:
    // 0x808006C0: b           L_80800748
    // 0x808006C4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800748;
    // 0x808006C4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x808006C8: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
L_808006CC:
    // 0x808006CC: bnel        $at, $zero, L_80800714
    if (ctx->r1 != 0) {
        // 0x808006D0: lwc1        $f10, 0x64($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X64);
            goto L_80800714;
    }
    goto skip_3;
    // 0x808006D0: lwc1        $f10, 0x64($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X64);
    skip_3:
    // 0x808006D4: lwc1        $f18, 0x64($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X64);
    // 0x808006D8: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808006DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006E4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808006E8: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x808006EC: addiu       $t3, $t3, -0x6EF0
    ctx->r11 = ADD32(ctx->r11, -0X6EF0);
    // 0x808006F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808006F4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808006F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808006FC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800700: jal         0x80089140
    // 0x80800704: nop

    _mlspline_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800704: nop

    after_1:
    // 0x80800708: b           L_80800748
    // 0x8080070C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800748;
    // 0x8080070C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800710: lwc1        $f10, 0x64($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X64);
L_80800714:
    // 0x80800714: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800718: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080071C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800720: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800724: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80800728: addiu       $t4, $t4, -0x6EF8
    ctx->r12 = ADD32(ctx->r12, -0X6EF8);
    // 0x8080072C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800730: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80800734: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800738: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8080073C: jal         0x80089140
    // 0x80800740: nop

    _mlspline_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800740: nop

    after_2:
    // 0x80800744: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800748:
    // 0x80800748: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080074C:
    // 0x8080074C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800750: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800754: jr          $ra
    // 0x80800758: nop

    return;
    // 0x80800758: nop

;}
RECOMP_FUNC void func_8080057C_chfactorytoxicpools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080057C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800580: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800584: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800588: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8080058C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800590: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800594: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800598: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080059C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005A0: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x808005A4: jal         0x80100094
    // 0x808005A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808005A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005AC: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x808005B0: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    // 0x808005B4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x808005B8: jal         0x800882C0
    // 0x808005BC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808005BC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x808005C0: sh          $v0, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r2;
    // 0x808005C4: lh          $t6, 0x2($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X2);
    // 0x808005C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808005CC: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x808005D0: blez        $t6, L_80800630
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808005D4: or          $s1, $s6, $zero
        ctx->r17 = ctx->r22 | 0;
            goto L_80800630;
    }
    // 0x808005D4: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x808005D8: addiu       $s4, $s6, 0x14
    ctx->r20 = ADD32(ctx->r22, 0X14);
    // 0x808005DC: addiu       $s5, $s6, 0x8
    ctx->r21 = ADD32(ctx->r22, 0X8);
    // 0x808005E0: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
L_808005E4:
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: jal         0x800EE88C
    // 0x808005EC: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x808005EC: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x808005F0: jal         0x800CBC3C
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800CBC3C(rdram, ctx);
        goto after_3;
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005F8: sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
    // 0x808005FC: jal         0x800EFD24
    // 0x80800600: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x80800600: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x80800604: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800608: jal         0x800EE7F8
    // 0x8080060C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x8080060C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800610: lh          $t7, 0x2($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X2);
    // 0x80800614: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800618: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8080061C: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800620: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x80800624: addiu       $s4, $s4, 0x1C
    ctx->r20 = ADD32(ctx->r20, 0X1C);
    // 0x80800628: bne         $at, $zero, L_808005E4
    if (ctx->r1 != 0) {
        // 0x8080062C: addiu       $s5, $s5, 0x1C
        ctx->r21 = ADD32(ctx->r21, 0X1C);
            goto L_808005E4;
    }
    // 0x8080062C: addiu       $s5, $s5, 0x1C
    ctx->r21 = ADD32(ctx->r21, 0X1C);
L_80800630:
    // 0x80800630: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80800634: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    // 0x80800638: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1156, 0X930) << 16);
    // 0x8080063C: lwc1        $f4, 0x930($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1156, 0X930));
    // 0x80800640: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80800644: swc1        $f4, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f4.u32l;
    // 0x80800648: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080064C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800650: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800654: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800658: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080065C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800660: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800668: jr          $ra
    // 0x8080066C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8080066C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void chmolehill_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808007EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808007F0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808007F4: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x808007F8: beq         $at, $zero, L_8080082C
    if (ctx->r1 == 0) {
        // 0x808007FC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080082C;
    }
    // 0x808007FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800800: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1560, 0XA88) << 16);
    // 0x80800804: addu        $at, $at, $t7
    gpr jr_addend_8080080C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800808: lw          $t7, 0xA88($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1560, 0XA88));
    // 0x8080080C: jr          $t7
    // 0x80800810: nop

    switch (jr_addend_8080080C >> 2) {
        case 0: goto L_80800814; break;
        case 1: goto L_80800814; break;
        case 2: goto L_80800824; break;
        case 3: goto L_80800814; break;
        case 4: goto L_80800824; break;
        case 5: goto L_80800824; break;
        case 6: goto L_80800824; break;
        case 7: goto L_8080081C; break;
        case 8: goto L_8080081C; break;
        case 9: goto L_8080081C; break;
        case 10: goto L_80800824; break;
        case 11: goto L_80800814; break;
        default: switch_error(__func__, 0x8080080C, 0x80800A88);
    }
    // 0x80800810: nop

L_80800814:
    // 0x80800814: jr          $ra
    // 0x80800818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080081C:
    // 0x8080081C: jr          $ra
    // 0x80800820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800824:
    // 0x80800824: jr          $ra
    // 0x80800828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080082C:
    // 0x8080082C: jr          $ra
    // 0x80800830: nop

    return;
    // 0x80800830: nop

;}
RECOMP_FUNC void _bskazmove_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834E8: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x800834E8);
    return;
    // 0x800834EC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _gcmapsects_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FD8: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087FD8);
    return;
    // 0x80087FDC: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void chbounce_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800040: jr          $ra
    // 0x80800044: swc1        $f12, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x80800044: swc1        $f12, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void _ncba1p_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893E0: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x800893E0);
    return;
    // 0x800893E4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080009C_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A4: jal         0x80800040
    // 0x808000A8: nop

    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_0;
    // 0x808000A8: nop

    after_0:
    // 0x808000AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4E00) << 16);
    // 0x808000B0: lwc1        $f4, 0x4E00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E00));
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000BC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808000C0: jr          $ra
    // 0x808000C4: nop

    return;
    // 0x808000C4: nop

;}
RECOMP_FUNC void func_800E4B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4B1C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800E4B20: addiu       $t7, $t7, -0x2AA0
    ctx->r15 = ADD32(ctx->r15, -0X2AA0);
    // 0x800E4B24: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800E4B28: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800E4B2C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800E4B30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E4B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4B38: beql        $a1, $zero, L_800E4BAC
    if (ctx->r5 == 0) {
        // 0x800E4B3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E4BAC;
    }
    goto skip_0;
    // 0x800E4B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E4B40: lw          $a0, 0x34($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X34);
    // 0x800E4B44: beql        $a0, $zero, L_800E4B60
    if (ctx->r4 == 0) {
        // 0x800E4B48: lw          $a0, 0x0($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X0);
            goto L_800E4B60;
    }
    goto skip_1;
    // 0x800E4B48: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x800E4B4C: jal         0x8001B084
    // 0x800E4B50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    heap_free(rdram, ctx);
        goto after_0;
    // 0x800E4B50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800E4B54: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4B58: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800E4B5C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
L_800E4B60:
    // 0x800E4B60: beql        $a0, $zero, L_800E4B7C
    if (ctx->r4 == 0) {
        // 0x800E4B64: lw          $a0, 0x28($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X28);
            goto L_800E4B7C;
    }
    goto skip_2;
    // 0x800E4B64: lw          $a0, 0x28($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X28);
    skip_2:
    // 0x800E4B68: jal         0x8001B084
    // 0x800E4B6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    heap_free(rdram, ctx);
        goto after_1;
    // 0x800E4B6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E4B70: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4B74: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800E4B78: lw          $a0, 0x28($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X28);
L_800E4B7C:
    // 0x800E4B7C: beql        $a0, $zero, L_800E4B98
    if (ctx->r4 == 0) {
        // 0x800E4B80: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800E4B98;
    }
    goto skip_3;
    // 0x800E4B80: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_3:
    // 0x800E4B84: jal         0x8001B084
    // 0x800E4B88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    heap_free(rdram, ctx);
        goto after_2;
    // 0x800E4B88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x800E4B8C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4B90: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800E4B94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800E4B98:
    // 0x800E4B98: jal         0x8001B084
    // 0x800E4B9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    heap_free(rdram, ctx);
        goto after_3;
    // 0x800E4B9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x800E4BA0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4BA4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800E4BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E4BAC:
    // 0x800E4BAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E4BB0: jr          $ra
    // 0x800E4BB4: nop

    return;
    // 0x800E4BB4: nop

;}
RECOMP_FUNC void func_80801050_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801054: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80801058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080105C: beq         $a1, $at, L_8080108C
    if (ctx->r5 == ctx->r1) {
        // 0x80801060: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080108C;
    }
    // 0x80801060: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801064: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80801068: beq         $a1, $at, L_808010A4
    if (ctx->r5 == ctx->r1) {
        // 0x8080106C: addiu       $v0, $sp, 0x20
        ctx->r2 = ADD32(ctx->r29, 0X20);
            goto L_808010A4;
    }
    // 0x8080106C: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x80801070: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80801074: beq         $a1, $at, L_808010B8
    if (ctx->r5 == ctx->r1) {
        // 0x80801078: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808010B8;
    }
    // 0x80801078: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080107C: beq         $a1, $at, L_808010C8
    if (ctx->r5 == ctx->r1) {
        // 0x80801080: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808010C8;
    }
    // 0x80801080: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801084: b           L_80801104
    // 0x80801088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801104;
    // 0x80801088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080108C:
    // 0x8080108C: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x80801090: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80801094: jal         0x80801114
    // 0x80801098: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80801114_chmonsterinterior(rdram, ctx);
        goto after_0;
    // 0x80801098: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_0:
    // 0x8080109C: b           L_80801104
    // 0x808010A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801104;
    // 0x808010A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808010A4:
    // 0x808010A4: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808010A8: jal         0x80801180
    // 0x808010AC: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80801180_chmonsterinterior(rdram, ctx);
        goto after_1;
    // 0x808010AC: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x808010B0: b           L_80801108
    // 0x808010B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801108;
    // 0x808010B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808010B8:
    // 0x808010B8: jal         0x80800A44
    // 0x808010BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800A44_chmonsterinterior(rdram, ctx);
        goto after_2;
    // 0x808010BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808010C0: b           L_80801104
    // 0x808010C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801104;
    // 0x808010C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808010C8:
    // 0x808010C8: jal         0x8008A090
    // 0x808010CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiemulti_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808010CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808010D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808010D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808010D8: jal         0x800BF544
    // 0x808010DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BF544(rdram, ctx);
        goto after_4;
    // 0x808010DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808010E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808010E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808010E8: jal         0x800BF544
    // 0x808010EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BF544(rdram, ctx);
        goto after_5;
    // 0x808010EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x808010F0: b           L_80801104
    // 0x808010F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801104;
    // 0x808010F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808010F8: b           L_80801104
    // 0x808010FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801104;
    // 0x808010FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801104:
    // 0x80801104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801108:
    // 0x80801108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080110C: jr          $ra
    // 0x80801110: nop

    return;
    // 0x80801110: nop

;}
RECOMP_FUNC void func_800C0920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0928: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C092C: jal         0x80088200
    // 0x800C0930: lw          $a0, -0x7510($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7510);
    _gcnewpause_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800C0930: lw          $a0, -0x7510($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7510);
    after_0:
    // 0x800C0934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0938: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C093C: sw          $zero, -0x7510($at)
    MEM_W(-0X7510, ctx->r1) = 0;
    // 0x800C0940: jr          $ra
    // 0x800C0944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C0944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084098: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x80084098);
    return;
    // 0x8008409C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8009272C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009272C: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092730: jr          $ra
    // 0x80092734: sb          $a1, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r5;
    return;
    // 0x80092734: sb          $a1, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void boot___osDispatchThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80803624_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803624: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803628: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080362C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80803630: jal         0x80100094
    // 0x80803634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803638: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8080363C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80803640: lbu         $a2, 0x6E($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X6E);
    // 0x80803644: lw          $t6, 0x70($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X70);
    // 0x80803648: lbu         $a0, 0xB1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB1);
    // 0x8080364C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1360, 0X4AB4) << 16);
    // 0x80803650: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80803654: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80803658: addiu       $a3, $a3, 0x4AB4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1360, 0X4AB4));
    // 0x8080365C: jal         0x80089D68
    // 0x80803660: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80803660: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    after_1:
    // 0x80803664: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80803668: sb          $v0, 0xB1($t8)
    MEM_B(0XB1, ctx->r24) = ctx->r2;
    // 0x8080366C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803670: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803674: jr          $ra
    // 0x80803678: nop

    return;
    // 0x80803678: nop

;}
RECOMP_FUNC void _ncbaspline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089388: syscall     776
    recomp_syscall_handler(rdram, ctx, 0x80089388);
    return;
    // 0x8008938C: xori        $t0, $zero, 0x4
    ctx->r8 = 0 ^ 0X4;
;}
RECOMP_FUNC void func_80803940_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803948: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080394C: jal         0x80088340
    // 0x80803950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcstatusDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80803950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803954: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80803958: jal         0x80088340
    // 0x8080395C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080395C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80803960: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80803964: jal         0x80088340
    // 0x80803968: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _gcstatusDll_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80803968: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080396C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80803970: jal         0x80088340
    // 0x80803974: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _gcstatusDll_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80803974: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80803978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080397C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803980: jr          $ra
    // 0x80803984: nop

    return;
    // 0x80803984: nop

;}
RECOMP_FUNC void _gcdialogexec_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E70: syscall     658
    recomp_syscall_handler(rdram, ctx, 0x80087E70);
    return;
    // 0x80087E74: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _bababykaz_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844B8: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x800844B8);
    return;
    // 0x800844BC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
