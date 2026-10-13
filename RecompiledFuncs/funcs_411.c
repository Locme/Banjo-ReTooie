#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _idtwinkle_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E00: syscall     742
    recomp_syscall_handler(rdram, ctx, 0x80088E00);
    return;
    // 0x80088E04: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bsbshock_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007E0: jal         0x8009E704
    // 0x808007E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getNextState(rdram, ctx);
        goto after_0;
    // 0x808007E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808007E8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808007EC: beql        $v0, $at, L_80800800
    if (ctx->r2 == ctx->r1) {
        // 0x808007F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800800;
    }
    goto skip_0;
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808007F4: jal         0x8009BC6C
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800800:
    // 0x80800800: jal         0x800A0CE8
    // 0x80800804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CE8(rdram, ctx);
        goto after_2;
    // 0x80800804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080080C: jal         0x800A0CF4
    // 0x80800810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_3;
    // 0x80800810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800818: jal         0x80093300
    // 0x8080081C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093300(rdram, ctx);
        goto after_4;
    // 0x8080081C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800824: jal         0x8009C1B4
    // 0x80800828: lui         $a1, 0x42AE
    ctx->r5 = S32(0X42AE << 16);
    func_8009C1B4(rdram, ctx);
        goto after_5;
    // 0x80800828: lui         $a1, 0x42AE
    ctx->r5 = S32(0X42AE << 16);
    after_5:
    // 0x8080082C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800830: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800834: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800838: jr          $ra
    // 0x8080083C: nop

    return;
    // 0x8080083C: nop

;}
RECOMP_FUNC void func_800EB8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB8C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EB8C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EB8C8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800EB8CC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800EB8D0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800EB8D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800EB8D8: jal         0x800E9DCC
    // 0x800EB8DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800E9DCC(rdram, ctx);
        goto after_0;
    // 0x800EB8DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800EB8E0: beq         $v0, $zero, L_800EB9D4
    if (ctx->r2 == 0) {
        // 0x800EB8E4: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_800EB9D4;
    }
    // 0x800EB8E4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800EB8E8: addiu       $s1, $s1, 0x2EA0
    ctx->r17 = ADD32(ctx->r17, 0X2EA0);
    // 0x800EB8EC: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x800EB8F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800EB8F4: beq         $v1, $at, L_800EB904
    if (ctx->r3 == ctx->r1) {
        // 0x800EB8F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800EB904;
    }
    // 0x800EB8F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EB8FC: bne         $v1, $at, L_800EB9D4
    if (ctx->r3 != ctx->r1) {
        // 0x800EB900: nop
    
            goto L_800EB9D4;
    }
    // 0x800EB900: nop

L_800EB904:
    // 0x800EB904: jal         0x800E9E88
    // 0x800EB908: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x800EB908: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x800EB90C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EB910: jal         0x800E9EB4
    // 0x800EB914: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x800EB914: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x800EB918: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800EB91C: beq         $at, $zero, L_800EB9D4
    if (ctx->r1 == 0) {
        // 0x800EB920: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800EB9D4;
    }
    // 0x800EB920: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800EB924: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
L_800EB928:
    // 0x800EB928: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x800EB92C: bnel        $t6, $zero, L_800EB9C8
    if (ctx->r14 != 0) {
        // 0x800EB930: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800EB9C8;
    }
    goto skip_0;
    // 0x800EB930: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x800EB934: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x800EB938: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800EB93C: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x800EB940: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800EB944: subu        $v0, $t7, $t8
    ctx->r2 = SUB32(ctx->r15, ctx->r24);
    // 0x800EB948: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EB94C: subu        $v1, $t9, $t0
    ctx->r3 = SUB32(ctx->r25, ctx->r8);
    // 0x800EB950: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x800EB954: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x800EB958: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x800EB95C: sll         $t9, $a1, 30
    ctx->r25 = S32(ctx->r5 << 30);
    // 0x800EB960: subu        $a0, $t1, $t2
    ctx->r4 = SUB32(ctx->r9, ctx->r10);
    // 0x800EB964: mflo        $t3
    ctx->r11 = lo;
    // 0x800EB968: nop

    // 0x800EB96C: nop

    // 0x800EB970: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EB974: mflo        $t4
    ctx->r12 = lo;
    // 0x800EB978: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800EB97C: nop

    // 0x800EB980: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EB984: mflo        $t6
    ctx->r14 = lo;
    // 0x800EB988: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x800EB98C: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800EB990: beql        $at, $zero, L_800EB9C8
    if (ctx->r1 == 0) {
        // 0x800EB994: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800EB9C8;
    }
    goto skip_1;
    // 0x800EB994: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x800EB998: bgez        $t9, L_800EB9A8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800EB99C: lw          $v1, 0x10($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X10);
            goto L_800EB9A8;
    }
    // 0x800EB99C: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x800EB9A0: b           L_800EB9AC
    // 0x800EB9A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800EB9AC;
    // 0x800EB9A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800EB9A8:
    // 0x800EB9A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB9AC:
    // 0x800EB9AC: bnel        $v0, $v1, L_800EB9C8
    if (ctx->r2 != ctx->r3) {
        // 0x800EB9B0: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800EB9C8;
    }
    goto skip_2;
    // 0x800EB9B0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_2:
    // 0x800EB9B4: sw          $a2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r6;
    // 0x800EB9B8: sw          $s3, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r19;
    // 0x800EB9BC: sw          $s0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r16;
    // 0x800EB9C0: sw          $v1, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r3;
    // 0x800EB9C4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800EB9C8:
    // 0x800EB9C8: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x800EB9CC: bnel        $at, $zero, L_800EB928
    if (ctx->r1 != 0) {
        // 0x800EB9D0: lw          $a1, 0x8($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X8);
            goto L_800EB928;
    }
    goto skip_3;
    // 0x800EB9D0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    skip_3:
L_800EB9D4:
    // 0x800EB9D4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800EB9D8: addiu       $s1, $s1, 0x2EA0
    ctx->r17 = ADD32(ctx->r17, 0X2EA0);
    // 0x800EB9DC: jal         0x800E9DC4
    // 0x800EB9E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E9DC4(rdram, ctx);
        goto after_3;
    // 0x800EB9E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x800EB9E4: beql        $v0, $zero, L_800EBB18
    if (ctx->r2 == 0) {
        // 0x800EB9E8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800EBB18;
    }
    goto skip_4;
    // 0x800EB9E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x800EB9EC: lw          $t0, 0x10($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X10);
    // 0x800EB9F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800EB9F4: bnel        $t0, $at, L_800EBB18
    if (ctx->r8 != ctx->r1) {
        // 0x800EB9F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800EBB18;
    }
    goto skip_5;
    // 0x800EB9F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800EB9FC: jal         0x800E9D68
    // 0x800EBA00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E9D68(rdram, ctx);
        goto after_4;
    // 0x800EBA00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x800EBA04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EBA08: jal         0x800E9D90
    // 0x800EBA0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E9D90(rdram, ctx);
        goto after_5;
    // 0x800EBA0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x800EBA10: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800EBA14: beq         $at, $zero, L_800EBB14
    if (ctx->r1 == 0) {
        // 0x800EBA18: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800EBB14;
    }
    // 0x800EBA18: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800EBA1C: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
L_800EBA20:
    // 0x800EBA20: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x800EBA24: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800EBA28: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800EBA2C: subu        $v0, $t1, $t2
    ctx->r2 = SUB32(ctx->r9, ctx->r10);
    // 0x800EBA30: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBA34: subu        $v1, $t3, $t4
    ctx->r3 = SUB32(ctx->r11, ctx->r12);
    // 0x800EBA38: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x800EBA3C: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x800EBA40: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x800EBA44: subu        $a0, $t5, $t6
    ctx->r4 = SUB32(ctx->r13, ctx->r14);
    // 0x800EBA48: mflo        $t7
    ctx->r15 = lo;
    // 0x800EBA4C: nop

    // 0x800EBA50: nop

    // 0x800EBA54: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBA58: mflo        $t8
    ctx->r24 = lo;
    // 0x800EBA5C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800EBA60: nop

    // 0x800EBA64: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBA68: mflo        $t0
    ctx->r8 = lo;
    // 0x800EBA6C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x800EBA70: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800EBA74: beql        $at, $zero, L_800EBB08
    if (ctx->r1 == 0) {
        // 0x800EBA78: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800EBB08;
    }
    goto skip_6;
    // 0x800EBA78: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_6:
    // 0x800EBA7C: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x800EBA80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EBA84: beql        $v0, $zero, L_800EBAF4
    if (ctx->r2 == 0) {
        // 0x800EBA88: lw          $t2, 0x10($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X10);
            goto L_800EBAF4;
    }
    goto skip_7;
    // 0x800EBA88: lw          $t2, 0x10($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X10);
    skip_7:
    // 0x800EBA8C: jalr        $v0
    // 0x800EBA90: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800EBA90: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    after_6:
    // 0x800EBA94: beql        $v0, $zero, L_800EBB08
    if (ctx->r2 == 0) {
        // 0x800EBA98: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800EBB08;
    }
    goto skip_8;
    // 0x800EBA98: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_8:
    // 0x800EBA9C: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x800EBAA0: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x800EBAA4: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x800EBAA8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800EBAAC: subu        $v0, $t2, $t3
    ctx->r2 = SUB32(ctx->r10, ctx->r11);
    // 0x800EBAB0: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBAB4: subu        $v1, $t4, $t5
    ctx->r3 = SUB32(ctx->r12, ctx->r13);
    // 0x800EBAB8: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x800EBABC: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800EBAC0: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    // 0x800EBAC4: mflo        $t8
    ctx->r24 = lo;
    // 0x800EBAC8: nop

    // 0x800EBACC: nop

    // 0x800EBAD0: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBAD4: mflo        $t9
    ctx->r25 = lo;
    // 0x800EBAD8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800EBADC: nop

    // 0x800EBAE0: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBAE4: mflo        $t1
    ctx->r9 = lo;
    // 0x800EBAE8: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x800EBAEC: nop

    // 0x800EBAF0: lw          $t2, 0x10($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X10);
L_800EBAF4:
    // 0x800EBAF4: sw          $a1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r5;
    // 0x800EBAF8: sw          $s3, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r19;
    // 0x800EBAFC: sw          $s0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r16;
    // 0x800EBB00: sw          $t2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r10;
    // 0x800EBB04: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_800EBB08:
    // 0x800EBB08: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800EBB0C: bnel        $at, $zero, L_800EBA20
    if (ctx->r1 != 0) {
        // 0x800EBB10: lh          $t1, 0x4($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X4);
            goto L_800EBA20;
    }
    goto skip_9;
    // 0x800EBB10: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    skip_9:
L_800EBB14:
    // 0x800EBB14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800EBB18:
    // 0x800EBB18: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800EBB1C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800EBB20: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800EBB24: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800EBB28: jr          $ra
    // 0x800EBB2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800EBB2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _gsmaker_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825D0: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825D0);
    return;
    // 0x800825D4: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_80800040_chpufferfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080004C: jal         0x80800518
    // 0x80800050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800518_chpufferfish(rdram, ctx);
        goto after_0;
    // 0x80800050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800054: jal         0x8010D690
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010D690(rdram, ctx);
        goto after_1;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080005C: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x80800060: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80800064: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80800068: beq         $at, $zero, L_80800260
    if (ctx->r1 == 0) {
        // 0x8080006C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800260;
    }
    // 0x8080006C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800070: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1110) << 16);
    // 0x80800074: addu        $at, $at, $t7
    gpr jr_addend_8080007C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800078: lw          $t7, 0x1110($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1110));
    // 0x8080007C: jr          $t7
    // 0x80800080: nop

    switch (jr_addend_8080007C >> 2) {
        case 0: goto L_80800084; break;
        case 1: goto L_80800158; break;
        case 2: goto L_808001CC; break;
        case 3: goto L_80800260; break;
        case 4: goto L_80800260; break;
        default: switch_error(__func__, 0x8080007C, 0x80801110);
    }
    // 0x80800080: nop

L_80800084:
    // 0x80800084: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800088: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080008C: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80800090: bgezl       $t0, L_808000AC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800094: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_808000AC;
    }
    goto skip_0;
    // 0x80800094: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80800098: jal         0x80800F30
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F30_chpufferfish(rdram, ctx);
        goto after_2;
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000A0: b           L_80800264
    // 0x808000A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800264;
    // 0x808000A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_808000AC:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000B8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808000BC: jal         0x80800AB0
    // 0x808000C0: nop

    func_80800AB0_chpufferfish(rdram, ctx);
        goto after_3;
    // 0x808000C0: nop

    after_3:
    // 0x808000C4: jal         0x80800E20
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E20_chpufferfish(rdram, ctx);
        goto after_4;
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x808000D4: jal         0x8010BA80
    // 0x808000D8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_8010BA80(rdram, ctx);
        goto after_5;
    // 0x808000D8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_5:
    // 0x808000DC: beq         $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x808000E0: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_808000F8;
    }
    // 0x808000E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808000E4: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808000E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000EC: nop

    // 0x808000F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000F4: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
L_808000F8:
    // 0x808000F8: jal         0x8010C500
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_6;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800100: beql        $v0, $zero, L_80800264
    if (ctx->r2 == 0) {
        // 0x80800104: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800264;
    }
    goto skip_1;
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800108: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080010C: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800110: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80800114: nop

    // 0x80800118: bc1fl       L_80800264
    if (!c1cs) {
        // 0x8080011C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800264;
    }
    goto skip_2;
    // 0x8080011C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800120: jal         0x8008FCC8
    // 0x80800124: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8008FCC8(rdram, ctx);
        goto after_7;
    // 0x80800124: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80800128: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8080012C: bne         $v0, $at, L_80800148
    if (ctx->r2 != ctx->r1) {
        // 0x80800130: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800148;
    }
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x80800274
    // 0x8080013C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800274_chpufferfish(rdram, ctx);
        goto after_8;
    // 0x8080013C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800140: b           L_80800264
    // 0x80800144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800264;
    // 0x80800144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800148:
    // 0x80800148: jal         0x80800274
    // 0x8080014C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800274_chpufferfish(rdram, ctx);
        goto after_9;
    // 0x8080014C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800150: b           L_80800264
    // 0x80800154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800264;
    // 0x80800154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800158:
    // 0x80800158: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080015C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800164: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800168: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080016C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800170: jal         0x80800AB0
    // 0x80800174: nop

    func_80800AB0_chpufferfish(rdram, ctx);
        goto after_10;
    // 0x80800174: nop

    after_10:
    // 0x80800178: jal         0x80800E20
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E20_chpufferfish(rdram, ctx);
        goto after_11;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80800188: jal         0x8010BA80
    // 0x8080018C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_8010BA80(rdram, ctx);
        goto after_12;
    // 0x8080018C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_12:
    // 0x80800190: beq         $v0, $zero, L_808001AC
    if (ctx->r2 == 0) {
        // 0x80800194: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_808001AC;
    }
    // 0x80800194: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800198: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8080019C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001A0: nop

    // 0x808001A4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x808001A8: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
L_808001AC:
    // 0x808001AC: jal         0x8010C500
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_13;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001B4: bne         $v0, $zero, L_80800260
    if (ctx->r2 != 0) {
        // 0x808001B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800260;
    }
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x80800274
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800274_chpufferfish(rdram, ctx);
        goto after_14;
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x808001C4: b           L_80800264
    // 0x808001C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800264;
    // 0x808001C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001CC:
    // 0x808001CC: lui         $a3, 0x4409
    ctx->r7 = S32(0X4409 << 16);
    // 0x808001D0: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808001DC: jal         0x80800AB0
    // 0x808001E0: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    func_80800AB0_chpufferfish(rdram, ctx);
        goto after_15;
    // 0x808001E0: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    after_15:
    // 0x808001E4: jal         0x80800E20
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E20_chpufferfish(rdram, ctx);
        goto after_16;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x808001F4: jal         0x8010BA80
    // 0x808001F8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_8010BA80(rdram, ctx);
        goto after_17;
    // 0x808001F8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_17:
    // 0x808001FC: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x80800200: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80800218;
    }
    // 0x80800200: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800204: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800208: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080020C: nop

    // 0x80800210: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800214: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
L_80800218:
    // 0x80800218: jal         0x8010C500
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_18;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800220: beql        $v0, $zero, L_80800240
    if (ctx->r2 == 0) {
        // 0x80800224: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_80800240;
    }
    goto skip_3;
    // 0x80800224: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_3:
    // 0x80800228: jal         0x8008FCC8
    // 0x8080022C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8008FCC8(rdram, ctx);
        goto after_19;
    // 0x8080022C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_19:
    // 0x80800230: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80800234: beql        $v0, $at, L_80800264
    if (ctx->r2 == ctx->r1) {
        // 0x80800238: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800264;
    }
    goto skip_4;
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8080023C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80800240:
    // 0x80800240: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8080024C: nop

    // 0x80800250: bc1fl       L_80800264
    if (!c1cs) {
        // 0x80800254: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800264;
    }
    goto skip_5;
    // 0x80800254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80800258: jal         0x80800274
    // 0x8080025C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800274_chpufferfish(rdram, ctx);
        goto after_20;
    // 0x8080025C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
L_80800260:
    // 0x80800260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800264:
    // 0x80800264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void func_8008C0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C0C8: jr          $ra
    // 0x8008C0CC: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    return;
    // 0x8008C0CC: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
;}
RECOMP_FUNC void _chpowerhut_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086058: syscall     274
    recomp_syscall_handler(rdram, ctx, 0x80086058);
    return;
    // 0x8008605C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800B3A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3A40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B3A44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B3A48: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B3A4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B3A50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B3A54: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B3A58: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800B3A5C: jal         0x800B39D0
    // 0x800B3A60: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800B39D0(rdram, ctx);
        goto after_0;
    // 0x800B3A60: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800B3A64: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B3A68: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B3A6C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800B3A70: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B3A74: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800B3A78: bne         $t7, $a1, L_800B3AA8
    if (ctx->r15 != ctx->r5) {
        // 0x800B3A7C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800B3AA8;
    }
    // 0x800B3A7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B3A80: jal         0x800B39D0
    // 0x800B3A84: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800B39D0(rdram, ctx);
        goto after_1;
    // 0x800B3A84: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x800B3A88: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800B3A8C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800B3A90: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B3A94: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x800B3A98: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800B3A9C: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x800B3AA0: b           L_800B3AB0
    // 0x800B3AA4: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
        goto L_800B3AB0;
    // 0x800B3AA4: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
L_800B3AA8:
    // 0x800B3AA8: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x800B3AAC: sh          $a2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r6;
L_800B3AB0:
    // 0x800B3AB0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B3AB4: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x800B3AB8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800B3ABC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B3AC0: jal         0x800B39D0
    // 0x800B3AC4: subu        $a1, $t1, $t2
    ctx->r5 = SUB32(ctx->r9, ctx->r10);
    func_800B39D0(rdram, ctx);
        goto after_2;
    // 0x800B3AC4: subu        $a1, $t1, $t2
    ctx->r5 = SUB32(ctx->r9, ctx->r10);
    after_2:
    // 0x800B3AC8: bne         $v0, $s0, L_800B3AEC
    if (ctx->r2 != ctx->r16) {
        // 0x800B3ACC: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_800B3AEC;
    }
    // 0x800B3ACC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800B3AD0: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x800B3AD4: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x800B3AD8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B3ADC: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x800B3AE0: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800B3AE4: b           L_800B3AF4
    // 0x800B3AE8: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
        goto L_800B3AF4;
    // 0x800B3AE8: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
L_800B3AEC:
    // 0x800B3AEC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800B3AF0: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_800B3AF4:
    // 0x800B3AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3AF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B3AFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B3B00: jr          $ra
    // 0x800B3B04: nop

    return;
    // 0x800B3B04: nop

;}
RECOMP_FUNC void func_800CBA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBA20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CBA24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBA28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CBA2C: jal         0x80087EF0
    // 0x800CBA30: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    _gcboundDll_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x800CBA30: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    after_0:
    // 0x800CBA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBA38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CBA3C: jr          $ra
    // 0x800CBA40: nop

    return;
    // 0x800CBA40: nop

;}
RECOMP_FUNC void func_80800000_chswampplatform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x800DA298
    // 0x80800014: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_0:
    // 0x80800018: bne         $v0, $zero, L_80800054
    if (ctx->r2 != 0) {
        // 0x8080001C: lui         $at, 0x40E0
        ctx->r1 = S32(0X40E0 << 16);
            goto L_80800054;
    }
    // 0x8080001C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80800020: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80800024: addiu       $a0, $zero, 0x28E
    ctx->r4 = ADD32(0, 0X28E);
    // 0x80800028: srl         $t6, $a1, 21
    ctx->r14 = S32(U32(ctx->r5) >> 21);
    // 0x8080002C: jal         0x800882C8
    // 0x80800030: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    _gccubesearch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800030: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_1:
    // 0x80800034: bne         $v0, $zero, L_80800044
    if (ctx->r2 != 0) {
        // 0x80800038: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800044;
    }
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: jal         0x80101FDC
    // 0x80800040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_80800044:
    // 0x80800044: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800048: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080004C: b           L_80800060
    // 0x80800050: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
        goto L_80800060;
    // 0x80800050: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
L_80800054:
    // 0x80800054: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800058: nop

    // 0x8080005C: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
L_80800060:
    // 0x80800060: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800064: jal         0x800EE7F8
    // 0x80800068: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800068: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x8080006C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800070: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800074: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800078: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080007C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800080: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800084: jal         0x800EFA4C
    // 0x80800088: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800088: nop

    after_4:
    // 0x8080008C: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800090: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800094: andi        $t9, $t7, 0xFFEF
    ctx->r25 = ctx->r15 & 0XFFEF;
    // 0x80800098: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x8080009C: andi        $t0, $t9, 0xF7
    ctx->r8 = ctx->r25 & 0XF7;
    // 0x808000A0: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x808000A4: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void func_800D97E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D97E8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D97EC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800D97F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D97F4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800D97F8: nop

    // 0x800D97FC: bc1f        L_800D9808
    if (!c1cs) {
        // 0x800D9800: nop
    
            goto L_800D9808;
    }
    // 0x800D9800: nop

    // 0x800D9804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9808:
    // 0x800D9808: beq         $v0, $zero, L_800D9880
    if (ctx->r2 == 0) {
        // 0x800D980C: nop
    
            goto L_800D9880;
    }
    // 0x800D980C: nop

    // 0x800D9810: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800D9814: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800D9818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D981C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800D9820: nop

    // 0x800D9824: bc1f        L_800D9830
    if (!c1cs) {
        // 0x800D9828: nop
    
            goto L_800D9830;
    }
    // 0x800D9828: nop

    // 0x800D982C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9830:
    // 0x800D9830: beq         $v0, $zero, L_800D9880
    if (ctx->r2 == 0) {
        // 0x800D9834: nop
    
            goto L_800D9880;
    }
    // 0x800D9834: nop

    // 0x800D9838: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800D983C: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800D9840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D9844: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800D9848: nop

    // 0x800D984C: bc1f        L_800D9858
    if (!c1cs) {
        // 0x800D9850: nop
    
            goto L_800D9858;
    }
    // 0x800D9850: nop

    // 0x800D9854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9858:
    // 0x800D9858: beq         $v0, $zero, L_800D9880
    if (ctx->r2 == 0) {
        // 0x800D985C: nop
    
            goto L_800D9880;
    }
    // 0x800D985C: nop

    // 0x800D9860: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800D9864: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800D9868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D986C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800D9870: nop

    // 0x800D9874: bc1f        L_800D9880
    if (!c1cs) {
        // 0x800D9878: nop
    
            goto L_800D9880;
    }
    // 0x800D9878: nop

    // 0x800D987C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9880:
    // 0x800D9880: jr          $ra
    // 0x800D9884: nop

    return;
    // 0x800D9884: nop

;}
RECOMP_FUNC void func_80802114_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080211C: lbu         $a2, 0x5F($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X5F);
    // 0x80802120: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80802124: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80802128: bne         $a2, $zero, L_80802154
    if (ctx->r6 != 0) {
        // 0x8080212C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80802154;
    }
    // 0x8080212C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80802130: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1692, 0X4634) << 16);
    // 0x80802134: addiu       $a2, $a2, 0x4634
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1692, 0X4634));
    // 0x80802138: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080213C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80802140: jal         0x800C4350
    // 0x80802144: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x80802144: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80802148: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080214C: b           L_808021B0
    // 0x80802150: sb          $v0, 0x5F($a3)
    MEM_B(0X5F, ctx->r7) = ctx->r2;
        goto L_808021B0;
    // 0x80802150: sb          $v0, 0x5F($a3)
    MEM_B(0X5F, ctx->r7) = ctx->r2;
L_80802154:
    // 0x80802154: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80802158: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080215C: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x80802160: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80802164: nop

    // 0x80802168: bc1fl       L_80802178
    if (!c1cs) {
        // 0x8080216C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80802178;
    }
    goto skip_0;
    // 0x8080216C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80802170: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80802174: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80802178:
    // 0x80802178: nop

    // 0x8080217C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80802180: nop

    // 0x80802184: bc1fl       L_80802194
    if (!c1cs) {
        // 0x80802188: mfc1        $a1, $f12
        ctx->r5 = (int32_t)ctx->f12.u32l;
            goto L_80802194;
    }
    goto skip_1;
    // 0x80802188: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    skip_1:
    // 0x8080218C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80802190: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
L_80802194:
    // 0x80802194: jal         0x800C31DC
    // 0x80802198: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800C31DC(rdram, ctx);
        goto after_1;
    // 0x80802198: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x8080219C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808021A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808021A4: lbu         $a0, 0x5F($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X5F);
    // 0x808021A8: jal         0x800C4350
    // 0x808021AC: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    func_800C4350(rdram, ctx);
        goto after_2;
    // 0x808021AC: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    after_2:
L_808021B0:
    // 0x808021B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808021B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808021B8: jr          $ra
    // 0x808021BC: nop

    return;
    // 0x808021BC: nop

;}
RECOMP_FUNC void func_808001BC_chghostdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001C0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808001C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C8: bne         $a1, $at, L_808001FC
    if (ctx->r5 != ctx->r1) {
        // 0x808001CC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_808001FC;
    }
    // 0x808001CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001D0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808001D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001D8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808001DC: jal         0x80085708
    // 0x808001E0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x808001E0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_0:
    // 0x808001E4: addiu       $a0, $zero, 0x344
    ctx->r4 = ADD32(0, 0X344);
    // 0x808001E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808001EC: jal         0x80101180
    // 0x808001F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_1;
    // 0x808001F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808001F4: b           L_8080020C
    // 0x808001F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080020C;
    // 0x808001F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001FC:
    // 0x808001FC: jal         0x80085820
    // 0x80800200: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800200: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800204: b           L_80800210
    // 0x80800208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800210;
    // 0x80800208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080020C:
    // 0x8080020C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800210:
    // 0x80800210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

    // 0x8080021C: nop

;}
RECOMP_FUNC void func_80100230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100238: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x8010023C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80100240: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80100244: sll         $t8, $t6, 17
    ctx->r24 = S32(ctx->r14 << 17);
    // 0x80100248: bltzl       $t8, L_8010025C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8010024C: lhu         $t9, 0x7C($a2)
        ctx->r25 = MEM_HU(ctx->r6, 0X7C);
            goto L_8010025C;
    }
    goto skip_0;
    // 0x8010024C: lhu         $t9, 0x7C($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X7C);
    skip_0:
    // 0x80100250: b           L_801002B0
    // 0x80100254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801002B0;
    // 0x80100254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80100258: lhu         $t9, 0x7C($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X7C);
L_8010025C:
    // 0x8010025C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80100260: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80100264: bne         $t9, $zero, L_80100274
    if (ctx->r25 != 0) {
        // 0x80100268: nop
    
            goto L_80100274;
    }
    // 0x80100268: nop

    // 0x8010026C: b           L_801002B0
    // 0x80100270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801002B0;
    // 0x80100270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80100274:
    // 0x80100274: jal         0x800EEB40
    // 0x80100278: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800EEB40(rdram, ctx);
        goto after_0;
    // 0x80100278: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8010027C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80100280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80100284: lhu         $v1, 0x7C($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X7C);
    // 0x80100288: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010028C: mflo        $t0
    ctx->r8 = lo;
    // 0x80100290: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80100294: nop

    // 0x80100298: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010029C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x801002A0: nop

    // 0x801002A4: bc1fl       L_801002B4
    if (!c1cs) {
        // 0x801002A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801002B4;
    }
    goto skip_1;
    // 0x801002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801002AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801002B0:
    // 0x801002B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801002B4:
    // 0x801002B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801002B8: jr          $ra
    // 0x801002BC: nop

    return;
    // 0x801002BC: nop

;}
RECOMP_FUNC void _fxleaves_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088968: syscall     711
    recomp_syscall_handler(rdram, ctx, 0x80088968);
    return;
    // 0x8008896C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800D42E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D42E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D42EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D42F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D42F4: jal         0x800D41D8
    // 0x800D42F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D41D8(rdram, ctx);
        goto after_0;
    // 0x800D42F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D42FC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800D4300: beq         $v0, $at, L_800D431C
    if (ctx->r2 == ctx->r1) {
        // 0x800D4304: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D431C;
    }
    // 0x800D4304: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D4308: jal         0x800C6E38
    // 0x800D430C: nop

    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x800D430C: nop

    after_1:
    // 0x800D4310: bnel        $v0, $zero, L_800D4320
    if (ctx->r2 != 0) {
        // 0x800D4314: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800D4320;
    }
    goto skip_0;
    // 0x800D4314: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x800D4318: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800D431C:
    // 0x800D431C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_800D4320:
    // 0x800D4320: addiu       $a1, $zero, -0x2
    ctx->r5 = ADD32(0, -0X2);
    // 0x800D4324: jal         0x800D1960
    // 0x800D4328: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800D1960(rdram, ctx);
        goto after_2;
    // 0x800D4328: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800D432C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D4330: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D4334: jr          $ra
    // 0x800D4338: nop

    return;
    // 0x800D4338: nop

;}
RECOMP_FUNC void func_808007B4_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B4: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x808007B8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808007BC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808007C0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808007C4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808007C8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808007CC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808007D0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808007D4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808007D8: jal         0x80100094
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007E0: jal         0x800DB9B0
    // 0x808007E4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x808007E4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808007E8: bnel        $v0, $zero, L_80800A30
    if (ctx->r2 != 0) {
        // 0x808007EC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80800A30;
    }
    goto skip_0;
    // 0x808007EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x808007F0: jal         0x800F54E4
    // 0x808007F4: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808007F4: nop

    after_2:
    // 0x808007F8: addiu       $s4, $sp, 0x7C
    ctx->r20 = ADD32(ctx->r29, 0X7C);
    // 0x808007FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800800: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800804: jal         0x800F5A00
    // 0x80800808: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x80800808: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080080C: jal         0x800F5EF8
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_4;
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800814: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800818: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8080081C: jal         0x8010FFB0
    // 0x80800820: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_8010FFB0(rdram, ctx);
        goto after_5;
    // 0x80800820: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_5:
    // 0x80800824: jal         0x800A89F8
    // 0x80800828: nop

    func_800A89F8(rdram, ctx);
        goto after_6;
    // 0x80800828: nop

    after_6:
    // 0x8080082C: addiu       $t6, $sp, 0x98
    ctx->r14 = ADD32(ctx->r29, 0X98);
    // 0x80800830: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800834: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800838: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x8080083C: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    // 0x80800840: jal         0x800A8A04
    // 0x80800844: addiu       $a3, $sp, 0x9C
    ctx->r7 = ADD32(ctx->r29, 0X9C);
    func_800A8A04(rdram, ctx);
        goto after_7;
    // 0x80800844: addiu       $a3, $sp, 0x9C
    ctx->r7 = ADD32(ctx->r29, 0X9C);
    after_7:
    // 0x80800848: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8080084C: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80800850: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x80800854: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x80800858: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8080085C: addiu       $t0, $t9, -0x19
    ctx->r8 = ADD32(ctx->r25, -0X19);
    // 0x80800860: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80800864: addiu       $t5, $t4, -0x15
    ctx->r13 = ADD32(ctx->r12, -0X15);
    // 0x80800868: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080086C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800870: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80800874: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800878: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x8080087C: jal         0x800E253C
    // 0x80800880: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    func_800E253C(rdram, ctx);
        goto after_8;
    // 0x80800880: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    after_8:
    // 0x80800884: lbu         $a0, 0x9B($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X9B);
    // 0x80800888: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8080088C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80800890: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80800894: jal         0x800E257C
    // 0x80800898: sra         $a0, $t7, 8
    ctx->r4 = S32(SIGNED(ctx->r15) >> 8);
    func_800E257C(rdram, ctx);
        goto after_9;
    // 0x80800898: sra         $a0, $t7, 8
    ctx->r4 = S32(SIGNED(ctx->r15) >> 8);
    after_9:
    // 0x8080089C: jal         0x800E2434
    // 0x808008A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2434(rdram, ctx);
        goto after_10;
    // 0x808008A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x808008A4: jal         0x800D674C
    // 0x808008A8: addiu       $a0, $zero, 0xB81
    ctx->r4 = ADD32(0, 0XB81);
    func_800D674C(rdram, ctx);
        goto after_11;
    // 0x808008A8: addiu       $a0, $zero, 0xB81
    ctx->r4 = ADD32(0, 0XB81);
    after_11:
    // 0x808008AC: addiu       $s2, $sp, 0x88
    ctx->r18 = ADD32(ctx->r29, 0X88);
    // 0x808008B0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x808008B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808008BC: jal         0x800E30E0
    // 0x808008C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800E30E0(rdram, ctx);
        goto after_12;
    // 0x808008C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x808008C4: jal         0x800B9990
    // 0x808008C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B9990(rdram, ctx);
        goto after_13;
    // 0x808008C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x808008CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808008D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808008D4: jal         0x80800E20
    // 0x808008D8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80800E20_chevilspirit(rdram, ctx);
        goto after_14;
    // 0x808008D8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_14:
    // 0x808008DC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x808008E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808008E4: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x808008E8: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x808008EC: bne         $at, $zero, L_80800928
    if (ctx->r1 != 0) {
        // 0x808008F0: nop
    
            goto L_80800928;
    }
    // 0x808008F0: nop

    // 0x808008F4: lh          $t0, 0xA($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XA);
    // 0x808008F8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808008FC: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80800900: lw          $a0, 0xC($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XC);
    // 0x80800904: beq         $a0, $zero, L_80800928
    if (ctx->r4 == 0) {
        // 0x80800908: nop
    
            goto L_80800928;
    }
    // 0x80800908: nop

    // 0x8080090C: jal         0x801069A4
    // 0x80800910: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    func_801069A4(rdram, ctx);
        goto after_15;
    // 0x80800910: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_15:
    // 0x80800914: beq         $v0, $zero, L_80800928
    if (ctx->r2 == 0) {
        // 0x80800918: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80800928;
    }
    // 0x80800918: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8080091C: jal         0x80106790
    // 0x80800920: nop

    func_80106790(rdram, ctx);
        goto after_16;
    // 0x80800920: nop

    after_16:
    // 0x80800924: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800928:
    // 0x80800928: jal         0x801067C4
    // 0x8080092C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    func_801067C4(rdram, ctx);
        goto after_17;
    // 0x8080092C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    after_17:
    // 0x80800930: beq         $v0, $zero, L_80800990
    if (ctx->r2 == 0) {
        // 0x80800934: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800990;
    }
    // 0x80800934: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800938:
    // 0x80800938: lbu         $t3, 0x64($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X64);
    // 0x8080093C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800940: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800944: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80800948: beq         $t4, $zero, L_80800980
    if (ctx->r12 == 0) {
        // 0x8080094C: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80800980;
    }
    // 0x8080094C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800950: bne         $s0, $v0, L_80800964
    if (ctx->r16 != ctx->r2) {
        // 0x80800954: or          $a3, $s4, $zero
        ctx->r7 = ctx->r20 | 0;
            goto L_80800964;
    }
    // 0x80800954: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80800958: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(924, 0X22D8) << 16);
    // 0x8080095C: b           L_8080096C
    // 0x80800960: addiu       $v0, $v0, 0x22D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(924, 0X22D8));
        goto L_8080096C;
    // 0x80800960: addiu       $v0, $v0, 0x22D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(924, 0X22D8));
L_80800964:
    // 0x80800964: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(924, 0X22DC) << 16);
    // 0x80800968: addiu       $v0, $v0, 0x22DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(924, 0X22DC));
L_8080096C:
    // 0x8080096C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800970: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80800974: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800978: jal         0x80800A4C
    // 0x8080097C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_80800A4C_chevilspirit(rdram, ctx);
        goto after_18;
    // 0x8080097C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_18:
L_80800980:
    // 0x80800980: jal         0x8010682C
    // 0x80800984: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    func_8010682C(rdram, ctx);
        goto after_19;
    // 0x80800984: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    after_19:
    // 0x80800988: bne         $v0, $zero, L_80800938
    if (ctx->r2 != 0) {
        // 0x8080098C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800938;
    }
    // 0x8080098C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800990:
    // 0x80800990: jal         0x8008A040
    // 0x80800994: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x80800994: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_20:
    // 0x80800998: beq         $v0, $zero, L_808009C8
    if (ctx->r2 == 0) {
        // 0x8080099C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808009C8;
    }
    // 0x8080099C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808009A0: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808009A4: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(924, 0X22DC) << 16);
    // 0x808009A8: addiu       $t5, $t5, 0x22DC
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(924, 0X22DC));
    // 0x808009AC: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x808009B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808009B4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808009B8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x808009BC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808009C0: jal         0x80800A4C
    // 0x808009C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80800A4C_chevilspirit(rdram, ctx);
        goto after_21;
    // 0x808009C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_21:
L_808009C8:
    // 0x808009C8: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808009CC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(924, 0X22D4) << 16);
    // 0x808009D0: addiu       $t6, $t6, 0x22D4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(924, 0X22D4));
    // 0x808009D4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x808009D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808009DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808009E0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808009E4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x808009E8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x808009EC: jal         0x80800A4C
    // 0x808009F0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_80800A4C_chevilspirit(rdram, ctx);
        goto after_22;
    // 0x808009F0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_22:
    // 0x808009F4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x808009F8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x808009FC: lui         $t0, 0xE300
    ctx->r8 = S32(0XE300 << 16);
    // 0x80800A00: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80800A04: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80800A08: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800A0C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80800A10: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80800A14: ori         $t0, $t0, 0xA01
    ctx->r8 = ctx->r8 | 0XA01;
    // 0x80800A18: lui         $t1, 0x10
    ctx->r9 = S32(0X10 << 16);
    // 0x80800A1C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80800A20: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80800A24: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80800A28: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80800A2C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800A30:
    // 0x80800A30: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800A34: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A38: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800A3C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800A40: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800A44: jr          $ra
    // 0x80800A48: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80800A48: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800C1984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C198C: beq         $a0, $zero, L_800C19D4
    if (ctx->r4 == 0) {
        // 0x800C1990: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800C19D4;
    }
    // 0x800C1990: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C1994: bne         $a2, $zero, L_800C19BC
    if (ctx->r6 != 0) {
        // 0x800C1998: nop
    
            goto L_800C19BC;
    }
    // 0x800C1998: nop

    // 0x800C199C: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800C19A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C19A4: lwc1        $f8, -0x5788($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5788);
    // 0x800C19A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C19AC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C19B0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C19B4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800C19B8: nop

L_800C19BC:
    // 0x800C19BC: jal         0x800C1448
    // 0x800C19C0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800C1448(rdram, ctx);
        goto after_0;
    // 0x800C19C0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C19C4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C19C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C19CC: jal         0x800DC454
    // 0x800C19D0: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    func_800DC454(rdram, ctx);
        goto after_1;
    // 0x800C19D0: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    after_1:
L_800C19D4:
    // 0x800C19D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C19D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C19DC: jr          $ra
    // 0x800C19E0: nop

    return;
    // 0x800C19E0: nop

;}
RECOMP_FUNC void func_800F2E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2E7C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800F2E80: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800F2E84: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800F2E88: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800F2E8C: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800F2E90: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800F2E94: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x800F2E98: jr          $ra
    // 0x800F2E9C: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    return;
    // 0x800F2E9C: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_808002E8_bsmumattack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002F8: jal         0x808001B4
    // 0x808002FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808001B4_bsmumattack(rdram, ctx);
        goto after_0;
    // 0x808002FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: jal         0x80084F30
    // 0x80800308: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _bamum_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800308: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x8080030C: jal         0x80800000
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsmumattack(rdram, ctx);
        goto after_2;
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: jal         0x80095774
    // 0x8080031C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    baflag_clear(rdram, ctx);
        goto after_3;
    // 0x8080031C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_3:
    // 0x80800320: jal         0x800853D8
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawandglow_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800328: jal         0x80083800
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsmum_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800334: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080033C: jr          $ra
    // 0x80800340: nop

    return;
    // 0x80800340: nop

;}
RECOMP_FUNC void func_80800FE0_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800FEC: jal         0x800DA298
    // 0x80800FF0: addiu       $a0, $zero, 0x9D6
    ctx->r4 = ADD32(0, 0X9D6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800FF0: addiu       $a0, $zero, 0x9D6
    ctx->r4 = ADD32(0, 0X9D6);
    after_0:
    // 0x80800FF4: beql        $v0, $zero, L_808010C0
    if (ctx->r2 == 0) {
        // 0x80800FF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808010C0;
    }
    goto skip_0;
    // 0x80800FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800FFC: jal         0x800DA298
    // 0x80801000: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80801000: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    after_1:
    // 0x80801004: bnel        $v0, $zero, L_808010C0
    if (ctx->r2 != 0) {
        // 0x80801008: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808010C0;
    }
    goto skip_1;
    // 0x80801008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8080100C: jal         0x8080112C
    // 0x80801010: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080112C_chstonepillar(rdram, ctx);
        goto after_2;
    // 0x80801010: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801014: beql        $v0, $zero, L_808010C0
    if (ctx->r2 == 0) {
        // 0x80801018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808010C0;
    }
    goto skip_2;
    // 0x80801018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8080101C: jal         0x800CEAD0
    // 0x80801020: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_3;
    // 0x80801020: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80801024: bne         $v0, $zero, L_8080103C
    if (ctx->r2 != 0) {
        // 0x80801028: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8080103C;
    }
    // 0x80801028: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8080102C: jal         0x800D0B68
    // 0x80801030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_4;
    // 0x80801030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80801034: beql        $v0, $zero, L_808010C0
    if (ctx->r2 == 0) {
        // 0x80801038: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808010C0;
    }
    goto skip_3;
    // 0x80801038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_8080103C:
    // 0x8080103C: jal         0x800CEAA8
    // 0x80801040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_5;
    // 0x80801040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80801044: beq         $v0, $zero, L_80801054
    if (ctx->r2 == 0) {
        // 0x80801048: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801054;
    }
    // 0x80801048: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080104C: jal         0x800CE88C
    // 0x80801050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_6;
    // 0x80801050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_80801054:
    // 0x80801054: jal         0x800DA544
    // 0x80801058: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x80801058: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    after_7:
    // 0x8080105C: jal         0x800DA298
    // 0x80801060: addiu       $a0, $zero, 0x9D9
    ctx->r4 = ADD32(0, 0X9D9);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80801060: addiu       $a0, $zero, 0x9D9
    ctx->r4 = ADD32(0, 0X9D9);
    after_8:
    // 0x80801064: beql        $v0, $zero, L_8080109C
    if (ctx->r2 == 0) {
        // 0x80801068: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8080109C;
    }
    goto skip_4;
    // 0x80801068: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    skip_4:
    // 0x8080106C: jal         0x80801174
    // 0x80801070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801174_chstonepillar(rdram, ctx);
        goto after_9;
    // 0x80801070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_9:
    // 0x80801074: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801078: addiu       $at, $zero, 0x19F
    ctx->r1 = ADD32(0, 0X19F);
    // 0x8080107C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80801080: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80801084: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x80801088: beql        $t9, $at, L_8080109C
    if (ctx->r25 == ctx->r1) {
        // 0x8080108C: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8080109C;
    }
    goto skip_5;
    // 0x8080108C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    skip_5:
    // 0x80801090: jal         0x800DA524
    // 0x80801094: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    func_800DA524(rdram, ctx);
        goto after_10;
    // 0x80801094: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    after_10:
    // 0x80801098: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8080109C:
    // 0x8080109C: jal         0x800D0B68
    // 0x808010A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_11;
    // 0x808010A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808010A4: bnel        $v0, $zero, L_808010C0
    if (ctx->r2 != 0) {
        // 0x808010A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808010C0;
    }
    goto skip_6;
    // 0x808010A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x808010AC: jal         0x808010CC
    // 0x808010B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808010CC_chstonepillar(rdram, ctx);
        goto after_12;
    // 0x808010B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_12:
    // 0x808010B4: jal         0x800FC660
    // 0x808010B8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC660(rdram, ctx);
        goto after_13;
    // 0x808010B8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_13:
    // 0x808010BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808010C0:
    // 0x808010C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010C4: jr          $ra
    // 0x808010C8: nop

    return;
    // 0x808010C8: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A150: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A150);
    return;
    // 0x8008A154: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_800C5668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5668: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C566C: addiu       $t7, $t7, -0x5660
    ctx->r15 = ADD32(ctx->r15, -0X5660);
    // 0x800C5670: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800C5674: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5678: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
    // 0x800C567C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C5680: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C5684: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C5688: beq         $v0, $at, L_800C5698
    if (ctx->r2 == ctx->r1) {
        // 0x800C568C: sw          $a1, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r5;
            goto L_800C5698;
    }
    // 0x800C568C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800C5690: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C5694: bne         $v0, $at, L_800C5754
    if (ctx->r2 != ctx->r1) {
        // 0x800C5698: addiu       $t8, $sp, 0x38
        ctx->r24 = ADD32(ctx->r29, 0X38);
            goto L_800C5754;
    }
L_800C5698:
    // 0x800C5698: addiu       $t8, $sp, 0x38
    ctx->r24 = ADD32(ctx->r29, 0X38);
    // 0x800C569C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C56A0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800C56A4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x800C56A8: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800C56AC: jal         0x800A8A04
    // 0x800C56B0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800A8A04(rdram, ctx);
        goto after_0;
    // 0x800C56B0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800C56B4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800C56B8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C56BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C56C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C56C4: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800C56C8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800C56CC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800C56D0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800C56D4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800C56D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C56DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800C56E0: addiu       $a2, $a2, -0x5780
    ctx->r6 = ADD32(ctx->r6, -0X5780);
    // 0x800C56E4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800C56E8: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800C56EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C56F0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C56F4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800C56F8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C56FC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800C5700: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C5704: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800C5708: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800C570C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800C5710: jal         0x800B9A24
    // 0x800C5714: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800B9A24(rdram, ctx);
        goto after_1;
    // 0x800C5714: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_1:
    // 0x800C5718: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800C571C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800C5720: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800C5724: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800C5728: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800C572C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800C5730: subu        $t7, $t6, $t0
    ctx->r15 = SUB32(ctx->r14, ctx->r8);
    // 0x800C5734: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800C5738: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C573C: addiu       $a2, $a2, -0x5780
    ctx->r6 = ADD32(ctx->r6, -0X5780);
    // 0x800C5740: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800C5744: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800C5748: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800C574C: jal         0x800B9A24
    // 0x800C5750: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_800B9A24(rdram, ctx);
        goto after_2;
    // 0x800C5750: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_2:
L_800C5754:
    // 0x800C5754: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C5758: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800C575C: jr          $ra
    // 0x800C5760: nop

    return;
    // 0x800C5760: nop

    // 0x800C5764: nop

    // 0x800C5768: nop

    // 0x800C576C: nop

;}
RECOMP_FUNC void _ncpoducam_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089670: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089670);
    return;
    // 0x80089674: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_801115C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801115C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801115CC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801115D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801115D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801115D8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801115DC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x801115E0: jal         0x800EEAA4
    // 0x801115E4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_800EEAA4(rdram, ctx);
        goto after_0;
    // 0x801115E4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x801115E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801115EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801115F0: jal         0x800EEAA4
    // 0x801115F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800EEAA4(rdram, ctx);
        goto after_1;
    // 0x801115F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x801115F8: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801115FC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80111600: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80111604: nop

    // 0x80111608: bc1fl       L_80111624
    if (!c1cs) {
        // 0x8011160C: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_80111624;
    }
    goto skip_0;
    // 0x8011160C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_0:
    // 0x80111610: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80111614: nop

    // 0x80111618: bc1tl       L_80111644
    if (c1cs) {
        // 0x8011161C: c.eq.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
            goto L_80111644;
    }
    goto skip_1;
    // 0x8011161C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    skip_1:
    // 0x80111620: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_80111624:
    // 0x80111624: nop

    // 0x80111628: bc1fl       L_80111670
    if (!c1cs) {
        // 0x8011162C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80111670;
    }
    goto skip_2;
    // 0x8011162C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80111630: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80111634: nop

    // 0x80111638: bc1fl       L_80111670
    if (!c1cs) {
        // 0x8011163C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80111670;
    }
    goto skip_3;
    // 0x8011163C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80111640: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
L_80111644:
    // 0x80111644: nop

    // 0x80111648: bc1tl       L_80111670
    if (c1cs) {
        // 0x8011164C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80111670;
    }
    goto skip_4;
    // 0x8011164C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x80111650: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80111654: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80111658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8011165C: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80111660: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80111664: b           L_80111670
    // 0x80111668: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
        goto L_80111670;
    // 0x80111668: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x8011166C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80111670:
    // 0x80111670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80111678: jr          $ra
    // 0x8011167C: nop

    return;
    // 0x8011167C: nop

;}
RECOMP_FUNC void func_800C157C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C157C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C1580: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C1584: addiu       $v0, $v0, -0x7470
    ctx->r2 = ADD32(ctx->r2, -0X7470);
    // 0x800C1588: addiu       $v1, $v1, -0x74F0
    ctx->r3 = ADD32(ctx->r3, -0X74F0);
L_800C158C:
    // 0x800C158C: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800C1590: sw          $zero, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = 0;
    // 0x800C1594: sw          $zero, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = 0;
    // 0x800C1598: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x800C159C: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x800C15A0: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x800C15A4: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x800C15A8: sw          $zero, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = 0;
    // 0x800C15AC: bne         $v1, $v0, L_800C158C
    if (ctx->r3 != ctx->r2) {
        // 0x800C15B0: sw          $zero, -0x1C($v1)
        MEM_W(-0X1C, ctx->r3) = 0;
            goto L_800C158C;
    }
    // 0x800C15B0: sw          $zero, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = 0;
    // 0x800C15B4: jr          $ra
    // 0x800C15B8: nop

    return;
    // 0x800C15B8: nop

;}
RECOMP_FUNC void func_800A2A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2A00: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A2A04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A2A08: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800A2A0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A2A10: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800A2A14: jal         0x800F53D0
    // 0x800A2A18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x800A2A18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800A2A1C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A2A20: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A2A24: xori        $v1, $t6, 0x4
    ctx->r3 = ctx->r14 ^ 0X4;
    // 0x800A2A28: sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800A2A2C: bne         $a0, $zero, L_800A2A4C
    if (ctx->r4 != 0) {
        // 0x800A2A30: xori        $v0, $t6, 0xB
        ctx->r2 = ctx->r14 ^ 0XB;
            goto L_800A2A4C;
    }
    // 0x800A2A30: xori        $v0, $t6, 0xB
    ctx->r2 = ctx->r14 ^ 0XB;
    // 0x800A2A34: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800A2A38: bne         $a0, $zero, L_800A2A4C
    if (ctx->r4 != 0) {
        // 0x800A2A3C: nop
    
            goto L_800A2A4C;
    }
    // 0x800A2A3C: nop

    // 0x800A2A40: jal         0x8008E35C
    // 0x800A2A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_1;
    // 0x800A2A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A2A48: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
L_800A2A4C:
    // 0x800A2A4C: beq         $a0, $zero, L_800A2A5C
    if (ctx->r4 == 0) {
        // 0x800A2A50: nop
    
            goto L_800A2A5C;
    }
    // 0x800A2A50: nop

    // 0x800A2A54: jal         0x800A26B8
    // 0x800A2A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A26B8(rdram, ctx);
        goto after_2;
    // 0x800A2A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_800A2A5C:
    // 0x800A2A5C: jal         0x8008FD48
    // 0x800A2A60: nop

    func_8008FD48(rdram, ctx);
        goto after_3;
    // 0x800A2A60: nop

    after_3:
    // 0x800A2A64: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800A2A68: sltiu       $at, $t7, 0x13
    ctx->r1 = ctx->r15 < 0X13 ? 1 : 0;
    // 0x800A2A6C: beq         $at, $zero, L_800A2C70
    if (ctx->r1 == 0) {
        // 0x800A2A70: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800A2C70;
    }
    // 0x800A2A70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A2A74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2A78: addu        $at, $at, $t7
    gpr jr_addend_800A2A80 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A2A7C: lw          $t7, 0x550C($at)
    ctx->r15 = ADD32(ctx->r1, 0X550C);
    // 0x800A2A80: jr          $t7
    // 0x800A2A84: nop

    switch (jr_addend_800A2A80 >> 2) {
        case 0: goto L_800A2C1C; break;
        case 1: goto L_800A2A88; break;
        case 2: goto L_800A2C70; break;
        case 3: goto L_800A2C70; break;
        case 4: goto L_800A2C70; break;
        case 5: goto L_800A2C70; break;
        case 6: goto L_800A2BE0; break;
        case 7: goto L_800A2C70; break;
        case 8: goto L_800A2C70; break;
        case 9: goto L_800A2C70; break;
        case 10: goto L_800A2C1C; break;
        case 11: goto L_800A2C70; break;
        case 12: goto L_800A2C70; break;
        case 13: goto L_800A2B30; break;
        case 14: goto L_800A2C70; break;
        case 15: goto L_800A2BAC; break;
        case 16: goto L_800A2C70; break;
        case 17: goto L_800A2B94; break;
        case 18: goto L_800A2B70; break;
        default: switch_error(__func__, 0x800A2A80, 0x8012550C);
    }
    // 0x800A2A84: nop

L_800A2A88:
    // 0x800A2A88: jal         0x80085100
    // 0x800A2A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basnowball_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x800A2A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800A2A90: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800A2A94: jal         0x80085128
    // 0x800A2A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basnowball_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x800A2A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800A2A9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2AA0: lwc1        $f4, 0x5558($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5558);
    // 0x800A2AA4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800A2AA8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A2AAC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800A2AB0: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x800A2AB4: jal         0x800F10B4
    // 0x800A2AB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x800A2AB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x800A2ABC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2AC0: lwc1        $f6, 0x555C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X555C);
    // 0x800A2AC4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800A2AC8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800A2ACC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A2AD0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800A2AD4: lui         $a3, 0x45FA
    ctx->r7 = S32(0X45FA << 16);
    // 0x800A2AD8: jal         0x800F10B4
    // 0x800A2ADC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x800A2ADC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x800A2AE0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A2AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2AE8: addiu       $a1, $zero, 0x56E
    ctx->r5 = ADD32(0, 0X56E);
    // 0x800A2AEC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800A2AF0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800A2AF4: jal         0x8009DB04
    // 0x800A2AF8: nop

    func_8009DB04(rdram, ctx);
        goto after_8;
    // 0x800A2AF8: nop

    after_8:
    // 0x800A2AFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2B00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A2B04: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A2B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2B0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A2B10: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800A2B14: nop

    // 0x800A2B18: bc1fl       L_800A2C74
    if (!c1cs) {
        // 0x800A2B1C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A2C74;
    }
    goto skip_0;
    // 0x800A2B1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800A2B20: jal         0x80084FC8
    // 0x800A2B24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bashake_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x800A2B24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_9:
    // 0x800A2B28: b           L_800A2C74
    // 0x800A2B2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800A2C74;
    // 0x800A2B2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A2B30:
    // 0x800A2B30: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A2B34: jal         0x80088A30
    // 0x800A2B38: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    _fxstep_entrypoint_10(rdram, ctx);
        goto after_10;
    // 0x800A2B38: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_10:
    // 0x800A2B3C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800A2B40: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800A2B44: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A2B48: bnel        $t9, $at, L_800A2B5C
    if (ctx->r25 != ctx->r1) {
        // 0x800A2B4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A2B5C;
    }
    goto skip_1;
    // 0x800A2B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800A2B50: jal         0x80088A48
    // 0x800A2B54: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    _fxstep_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x800A2B54: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_11:
    // 0x800A2B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A2B5C:
    // 0x800A2B5C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A2B60: jal         0x80084FC8
    // 0x800A2B64: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _bashake_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x800A2B64: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_12:
    // 0x800A2B68: b           L_800A2C74
    // 0x800A2B6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800A2C74;
    // 0x800A2B6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A2B70:
    // 0x800A2B70: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A2B74: jal         0x80088A30
    // 0x800A2B78: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    _fxstep_entrypoint_10(rdram, ctx);
        goto after_13;
    // 0x800A2B78: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_13:
    // 0x800A2B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2B80: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A2B84: jal         0x80084FC8
    // 0x800A2B88: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _bashake_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x800A2B88: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_14:
    // 0x800A2B8C: b           L_800A2C74
    // 0x800A2B90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800A2C74;
    // 0x800A2B90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A2B94:
    // 0x800A2B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2B98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A2B9C: jal         0x80084FC8
    // 0x800A2BA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bashake_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x800A2BA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_15:
    // 0x800A2BA4: b           L_800A2C74
    // 0x800A2BA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800A2C74;
    // 0x800A2BA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A2BAC:
    // 0x800A2BAC: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x800A2BB0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x800A2BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2BB8: jal         0x8009DBF0
    // 0x800A2BBC: addiu       $a1, $zero, 0x4C7
    ctx->r5 = ADD32(0, 0X4C7);
    func_8009DBF0(rdram, ctx);
        goto after_16;
    // 0x800A2BBC: addiu       $a1, $zero, 0x4C7
    ctx->r5 = ADD32(0, 0X4C7);
    after_16:
    // 0x800A2BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2BC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A2BC8: jal         0x80084FC8
    // 0x800A2BCC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bashake_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x800A2BCC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_17:
    // 0x800A2BD0: jal         0x80084130
    // 0x800A2BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsvan_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x800A2BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x800A2BD8: b           L_800A2C74
    // 0x800A2BDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800A2C74;
    // 0x800A2BDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A2BE0:
    // 0x800A2BE0: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x800A2BE4: lui         $a3, 0x3F6B
    ctx->r7 = S32(0X3F6B << 16);
    // 0x800A2BE8: ori         $a3, $a3, 0x851F
    ctx->r7 = ctx->r7 | 0X851F;
    // 0x800A2BEC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x800A2BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2BF4: jal         0x8009DC98
    // 0x800A2BF8: addiu       $a1, $zero, 0x4C1
    ctx->r5 = ADD32(0, 0X4C1);
    func_8009DC98(rdram, ctx);
        goto after_19;
    // 0x800A2BF8: addiu       $a1, $zero, 0x4C1
    ctx->r5 = ADD32(0, 0X4C1);
    after_19:
    // 0x800A2BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A2C04: jal         0x80084FC8
    // 0x800A2C08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bashake_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x800A2C08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_20:
    // 0x800A2C0C: jal         0x800843B8
    // 0x800A2C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswasher_entrypoint_0(rdram, ctx);
        goto after_21;
    // 0x800A2C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x800A2C14: b           L_800A2C74
    // 0x800A2C18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800A2C74;
    // 0x800A2C18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A2C1C:
    // 0x800A2C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2C20: jal         0x8009E674
    // 0x800A2C24: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8009E674(rdram, ctx);
        goto after_22;
    // 0x800A2C24: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_22:
    // 0x800A2C28: beql        $v0, $zero, L_800A2C74
    if (ctx->r2 == 0) {
        // 0x800A2C2C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A2C74;
    }
    goto skip_2;
    // 0x800A2C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800A2C30: jal         0x80084FE0
    // 0x800A2C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_23;
    // 0x800A2C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x800A2C38: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A2C3C: beq         $v0, $at, L_800A2C58
    if (ctx->r2 == ctx->r1) {
        // 0x800A2C40: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800A2C58;
    }
    // 0x800A2C40: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A2C44: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A2C48: beq         $v0, $at, L_800A2C68
    if (ctx->r2 == ctx->r1) {
        // 0x800A2C4C: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800A2C68;
    }
    // 0x800A2C4C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A2C50: b           L_800A2C74
    // 0x800A2C54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800A2C74;
    // 0x800A2C54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A2C58:
    // 0x800A2C58: jal         0x80088A30
    // 0x800A2C5C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    _fxstep_entrypoint_10(rdram, ctx);
        goto after_24;
    // 0x800A2C5C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_24:
    // 0x800A2C60: b           L_800A2C74
    // 0x800A2C64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800A2C74;
    // 0x800A2C64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A2C68:
    // 0x800A2C68: jal         0x80088A30
    // 0x800A2C6C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    _fxstep_entrypoint_10(rdram, ctx);
        goto after_25;
    // 0x800A2C6C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_25:
L_800A2C70:
    // 0x800A2C70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A2C74:
    // 0x800A2C74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A2C78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A2C7C: jr          $ra
    // 0x800A2C80: nop

    return;
    // 0x800A2C80: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BC0: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BC0);
    return;
    // 0x80087BC4: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void func_80802A2C_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802A34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802A38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802A3C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80802A40: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80802A44: jal         0x80100094
    // 0x80802A48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802A48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802A4C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802A50: lbu         $t6, 0x49D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X49D);
    // 0x80802A54: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80802A58: beq         $t6, $zero, L_80802A68
    if (ctx->r14 == 0) {
        // 0x80802A5C: ori         $t8, $t7, 0x2000
        ctx->r24 = ctx->r15 | 0X2000;
            goto L_80802A68;
    }
    // 0x80802A5C: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x80802A60: jal         0x80085710
    // 0x80802A64: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80802A64: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_1:
L_80802A68:
    // 0x80802A68: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80802A6C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802A70: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80802A74: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80802A78: jal         0x80085708
    // 0x80802A7C: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80802A7C: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_2:
    // 0x80802A80: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80802A84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80802A88: sb          $t0, 0x49D($t1)
    MEM_B(0X49D, ctx->r9) = ctx->r8;
    // 0x80802A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802A90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802A94: jr          $ra
    // 0x80802A98: nop

    return;
    // 0x80802A98: nop

;}
RECOMP_FUNC void func_8010FFD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FFD0: jr          $ra
    // 0x8010FFD4: lbu         $v0, 0x19($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X19);
    return;
    // 0x8010FFD4: lbu         $v0, 0x19($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X19);
;}
RECOMP_FUNC void func_808000EC_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000F8: jal         0x800D9004
    // 0x808000FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D9004(rdram, ctx);
        goto after_0;
    // 0x808000FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800100: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800104: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80800108: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8080010C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800110: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800114: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800118: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080011C: jal         0x80089F20
    // 0x80800120: lui         $a3, 0x4296
    ctx->r7 = S32(0X4296 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800120: lui         $a3, 0x4296
    ctx->r7 = S32(0X4296 << 16);
    after_1:
    // 0x80800124: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800128: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080012C: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800130: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80800134: bgez        $t9, L_80800184
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800138: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_80800184;
    }
    // 0x80800138: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080013C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800140: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800144: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800148: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1440) << 16);
    // 0x8080014C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800150: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x80800154: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800158: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8080015C: nop

    // 0x80800160: bc1f        L_8080017C
    if (!c1cs) {
        // 0x80800164: nop
    
            goto L_8080017C;
    }
    // 0x80800164: nop

    // 0x80800168: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x8080016C: swc1        $f14, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f14.u32l;
    // 0x80800170: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800174: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80800178: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_8080017C:
    // 0x8080017C: b           L_808001C0
    // 0x80800180: lwc1        $f0, 0x1440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1440));
        goto L_808001C0;
    // 0x80800180: lwc1        $f0, 0x1440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1440));
L_80800184:
    // 0x80800184: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800188: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1444) << 16);
    // 0x8080018C: lwc1        $f0, 0x1444($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1444));
    // 0x80800190: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800194: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x80800198: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8080019C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x808001A0: nop

    // 0x808001A4: bc1f        L_808001C0
    if (!c1cs) {
        // 0x808001A8: nop
    
            goto L_808001C0;
    }
    // 0x808001A8: nop

    // 0x808001AC: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808001B0: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x808001B4: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808001B8: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x808001BC: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_808001C0:
    // 0x808001C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1448) << 16);
    // 0x808001C4: lwc1        $f6, 0x1448($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1448));
    // 0x808001C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001CC: jal         0x800F10B4
    // 0x808001D0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808001D0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x808001D4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808001D8: lbu         $t0, 0x79($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X79);
    // 0x808001DC: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001E4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x808001E8: andi        $t1, $t0, 0xFF0F
    ctx->r9 = ctx->r8 & 0XFF0F;
    // 0x808001EC: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x808001F0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808001F4: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
    // 0x808001F8: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808001FC: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80800200: nop

    // 0x80800204: bc1fl       L_8080021C
    if (!c1cs) {
        // 0x80800208: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_8080021C;
    }
    goto skip_0;
    // 0x80800208: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_0:
    // 0x8080020C: sub.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80800210: b           L_80800228
    // 0x80800214: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_80800228;
    // 0x80800214: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80800218: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_8080021C:
    // 0x8080021C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800220: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x80800224: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_80800228:
    // 0x80800228: lw          $t4, 0x6C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X6C);
    // 0x8080022C: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800230: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800234: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80800238: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x8080023C: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800240: or          $t0, $t6, $t8
    ctx->r8 = ctx->r14 | ctx->r24;
    // 0x80800244: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x80800248: beq         $t9, $at, L_80800468
    if (ctx->r25 == ctx->r1) {
        // 0x8080024C: sh          $t0, 0x6E($s0)
        MEM_H(0X6E, ctx->r16) = ctx->r8;
            goto L_80800468;
    }
    // 0x8080024C: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x80800250: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800254: beq         $t9, $at, L_8080026C
    if (ctx->r25 == ctx->r1) {
        // 0x80800258: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080026C;
    }
    // 0x80800258: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080025C: beq         $t9, $at, L_80800620
    if (ctx->r25 == ctx->r1) {
        // 0x80800260: nop
    
            goto L_80800620;
    }
    // 0x80800260: nop

    // 0x80800264: b           L_80800740
    // 0x80800268: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
        goto L_80800740;
    // 0x80800268: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
L_8080026C:
    // 0x8080026C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X144C) << 16);
    // 0x80800270: lwc1        $f6, 0x144C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X144C));
    // 0x80800274: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800278: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8080027C: nop

    // 0x80800280: bc1f        L_80800294
    if (!c1cs) {
        // 0x80800284: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1588, 0X1450) << 16);
            goto L_80800294;
    }
    // 0x80800284: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1450) << 16);
    // 0x80800288: lwc1        $f8, 0x1450($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1450));
    // 0x8080028C: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800290: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_80800294:
    // 0x80800294: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1454) << 16);
    // 0x80800298: lwc1        $f16, 0x1454($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1454));
    // 0x8080029C: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808002A0: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x808002A4: nop

    // 0x808002A8: bc1f        L_808002BC
    if (!c1cs) {
        // 0x808002AC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1588, 0X1458) << 16);
            goto L_808002BC;
    }
    // 0x808002AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1458) << 16);
    // 0x808002B0: lwc1        $f2, 0x1458($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1458));
    // 0x808002B4: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x808002B8: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_808002BC:
    // 0x808002BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002C0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808002C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X145C) << 16);
    // 0x808002C8: lwc1        $f6, 0x145C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X145C));
    // 0x808002CC: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808002D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1460) << 16);
    // 0x808002D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808002D8: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x808002DC: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808002E0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808002E4: nop

    // 0x808002E8: bc1f        L_808002F8
    if (!c1cs) {
        // 0x808002EC: nop
    
            goto L_808002F8;
    }
    // 0x808002EC: nop

    // 0x808002F0: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x808002F4: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
L_808002F8:
    // 0x808002F8: lwc1        $f2, 0x1460($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1460));
    // 0x808002FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800300: nop

    // 0x80800304: bc1fl       L_80800314
    if (!c1cs) {
        // 0x80800308: lbu         $a0, 0x5F($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X5F);
            goto L_80800314;
    }
    goto skip_1;
    // 0x80800308: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    skip_1:
    // 0x8080030C: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x80800310: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
L_80800314:
    // 0x80800314: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1588, 0X1580) << 16);
    // 0x80800318: addiu       $a2, $a2, 0x1580
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1588, 0X1580));
    // 0x8080031C: bne         $a0, $zero, L_80800334
    if (ctx->r4 != 0) {
        // 0x80800320: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_80800334;
    }
    // 0x80800320: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800324: jal         0x800C4350
    // 0x80800328: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_3;
    // 0x80800328: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8080032C: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x80800330: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_80800334:
    // 0x80800334: jal         0x800C31DC
    // 0x80800338: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    func_800C31DC(rdram, ctx);
        goto after_4;
    // 0x80800338: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    after_4:
    // 0x8080033C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800344: jal         0x800C4350
    // 0x80800348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_5;
    // 0x80800348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8080034C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800350: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800354: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80800358: nop

    // 0x8080035C: bc1f        L_80800388
    if (!c1cs) {
        // 0x80800360: nop
    
            goto L_80800388;
    }
    // 0x80800360: nop

    // 0x80800364: jal         0x80089D40
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: jal         0x808008F4
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808008F4_chfiregen(rdram, ctx);
        goto after_7;
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800378: lbu         $t1, 0x72($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X72);
    // 0x8080037C: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x80800380: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80800384: sb          $t3, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r11;
L_80800388:
    // 0x80800388: jal         0x800DC0C0
    // 0x8080038C: nop

    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x8080038C: nop

    after_8:
    // 0x80800390: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1464) << 16);
    // 0x80800394: lwc1        $f18, 0x1464($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1464));
    // 0x80800398: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808003A4: nop

    // 0x808003A8: bc1f        L_808003E0
    if (!c1cs) {
        // 0x808003AC: nop
    
            goto L_808003E0;
    }
    // 0x808003AC: nop

    // 0x808003B0: lbu         $t4, 0x72($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X72);
    // 0x808003B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003BC: andi        $t5, $t4, 0xFF03
    ctx->r13 = ctx->r12 & 0XFF03;
    // 0x808003C0: ori         $t7, $t5, 0xC
    ctx->r15 = ctx->r13 | 0XC;
    // 0x808003C4: sb          $t7, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r15;
    // 0x808003C8: jal         0x808008F4
    // 0x808003CC: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    func_808008F4_chfiregen(rdram, ctx);
        goto after_9;
    // 0x808003CC: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    after_9:
    // 0x808003D0: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808003D4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808003D8: jal         0x80101CDC
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101CDC(rdram, ctx);
        goto after_10;
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_808003E0:
    // 0x808003E0: jal         0x800DC0C0
    // 0x808003E4: nop

    func_800DC0C0(rdram, ctx);
        goto after_11;
    // 0x808003E4: nop

    after_11:
    // 0x808003E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1468) << 16);
    // 0x808003EC: lwc1        $f6, 0x1468($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1468));
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808003F8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808003FC: nop

    // 0x80800400: bc1f        L_80800434
    if (!c1cs) {
        // 0x80800404: nop
    
            goto L_80800434;
    }
    // 0x80800404: nop

    // 0x80800408: jal         0x80101E14
    // 0x8080040C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_12;
    // 0x8080040C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_12:
    // 0x80800410: beq         $v0, $zero, L_80800434
    if (ctx->r2 == 0) {
        // 0x80800414: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800434;
    }
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: jal         0x80800B4C
    // 0x8080041C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800B4C_chfiregen(rdram, ctx);
        goto after_13;
    // 0x8080041C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x80800420: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1588, 0X1570) << 16);
    // 0x80800424: addiu       $a2, $a2, 0x1570
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1588, 0X1570));
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: jal         0x80089D18
    // 0x80800430: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x80800430: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_14:
L_80800434:
    // 0x80800434: jal         0x800DC0C0
    // 0x80800438: nop

    func_800DC0C0(rdram, ctx);
        goto after_15;
    // 0x80800438: nop

    after_15:
    // 0x8080043C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800440: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8080044C: nop

    // 0x80800450: bc1fl       L_80800740
    if (!c1cs) {
        // 0x80800454: lwc1        $f0, 0x30($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
            goto L_80800740;
    }
    goto skip_2;
    // 0x80800454: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    skip_2:
    // 0x80800458: jal         0x80800B4C
    // 0x8080045C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800B4C_chfiregen(rdram, ctx);
        goto after_16;
    // 0x8080045C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800460: b           L_80800740
    // 0x80800464: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
        goto L_80800740;
    // 0x80800464: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
L_80800468:
    // 0x80800468: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X146C) << 16);
    // 0x8080046C: lwc1        $f10, 0x146C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X146C));
    // 0x80800470: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800474: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800478: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1470) << 16);
    // 0x8080047C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: bc1f        L_80800498
    if (!c1cs) {
        // 0x80800488: nop
    
            goto L_80800498;
    }
    // 0x80800488: nop

    // 0x8080048C: lwc1        $f16, 0x1470($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1470));
    // 0x80800490: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80800494: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
L_80800498:
    // 0x80800498: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1474) << 16);
    // 0x8080049C: lwc1        $f2, 0x1474($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1474));
    // 0x808004A0: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808004A4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x808004A8: nop

    // 0x808004AC: bc1fl       L_808004C0
    if (!c1cs) {
        // 0x808004B0: lwc1        $f8, 0x58($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
            goto L_808004C0;
    }
    goto skip_3;
    // 0x808004B0: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    skip_3:
    // 0x808004B4: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x808004B8: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x808004BC: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
L_808004C0:
    // 0x808004C0: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x808004C4: nop

    // 0x808004C8: bc1t        L_80800504
    if (c1cs) {
        // 0x808004CC: nop
    
            goto L_80800504;
    }
    // 0x808004CC: nop

    // 0x808004D0: jal         0x808008F4
    // 0x808004D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808008F4_chfiregen(rdram, ctx);
        goto after_17;
    // 0x808004D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x808004D8: lbu         $t6, 0x72($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X72);
    // 0x808004DC: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x808004E0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808004E4: andi        $t8, $t6, 0xFF03
    ctx->r24 = ctx->r14 & 0XFF03;
    // 0x808004E8: ori         $t0, $t8, 0x8
    ctx->r8 = ctx->r24 | 0X8;
    // 0x808004EC: sb          $t0, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r8;
    // 0x808004F0: jal         0x80101CDC
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101CDC(rdram, ctx);
        goto after_18;
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808004F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1478) << 16);
    // 0x808004FC: lwc1        $f2, 0x1478($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1478));
    // 0x80800500: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
L_80800504:
    // 0x80800504: jal         0x80101D0C
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101D0C(rdram, ctx);
        goto after_19;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080050C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1480) << 16);
    // 0x80800510: lwc1        $f2, 0x1480($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1480));
    // 0x80800514: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1484) << 16);
    // 0x80800518: lwc1        $f10, 0x1484($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1484));
    // 0x8080051C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800520: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1488) << 16);
    // 0x80800524: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80800528: nop

    // 0x8080052C: bc1tl       L_80800740
    if (c1cs) {
        // 0x80800530: lwc1        $f0, 0x30($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
            goto L_80800740;
    }
    goto skip_4;
    // 0x80800530: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x80800534: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800538: lwc1        $f18, 0x1488($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1488));
    // 0x8080053C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1588, 0X1580) << 16);
    // 0x80800540: addiu       $a2, $a2, 0x1580
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1588, 0X1580));
    // 0x80800544: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800548: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x8080054C: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800550: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80800554: nop

    // 0x80800558: bc1fl       L_80800568
    if (!c1cs) {
        // 0x8080055C: lbu         $a0, 0x5F($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X5F);
            goto L_80800568;
    }
    goto skip_5;
    // 0x8080055C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    skip_5:
    // 0x80800560: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x80800564: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
L_80800568:
    // 0x80800568: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080056C: bne         $a0, $zero, L_80800584
    if (ctx->r4 != 0) {
        // 0x80800570: nop
    
            goto L_80800584;
    }
    // 0x80800570: nop

    // 0x80800574: jal         0x800C4350
    // 0x80800578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_20;
    // 0x80800578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x8080057C: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x80800580: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_80800584:
    // 0x80800584: jal         0x800C31DC
    // 0x80800588: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    func_800C31DC(rdram, ctx);
        goto after_21;
    // 0x80800588: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    after_21:
    // 0x8080058C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800594: jal         0x800C4350
    // 0x80800598: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_22;
    // 0x80800598: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x8080059C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X148C) << 16);
    // 0x808005A0: lwc1        $f12, 0x148C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X148C));
    // 0x808005A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1490) << 16);
    // 0x808005A8: jal         0x800DC178
    // 0x808005AC: lwc1        $f14, 0x1490($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1490));
    func_800DC178(rdram, ctx);
        goto after_23;
    // 0x808005AC: lwc1        $f14, 0x1490($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1490));
    after_23:
    // 0x808005B0: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808005B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808005B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005BC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808005C8: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x808005CC: nop

    // 0x808005D0: bc1fl       L_80800610
    if (!c1cs) {
        // 0x808005D4: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_80800610;
    }
    goto skip_6;
    // 0x808005D4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_6:
    // 0x808005D8: jal         0x80800B4C
    // 0x808005DC: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    func_80800B4C_chfiregen(rdram, ctx);
        goto after_24;
    // 0x808005DC: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    after_24:
    // 0x808005E0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1588, 0X1570) << 16);
    // 0x808005E4: addiu       $a2, $a2, 0x1570
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1588, 0X1570));
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005EC: jal         0x80089D18
    // 0x808005F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x808005F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_25:
    // 0x808005F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1494) << 16);
    // 0x808005F8: lwc1        $f10, 0x1494($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1494));
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: jal         0x80089D40
    // 0x80800604: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_26;
    // 0x80800604: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    after_26:
    // 0x80800608: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080060C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_80800610:
    // 0x80800610: jal         0x80101CDC
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101CDC(rdram, ctx);
        goto after_27;
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800618: b           L_80800740
    // 0x8080061C: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
        goto L_80800740;
    // 0x8080061C: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
L_80800620:
    // 0x80800620: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1498) << 16);
    // 0x80800624: lwc1        $f12, 0x1498($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1498));
    // 0x80800628: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8080062C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X149C) << 16);
    // 0x80800630: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800634: nop

    // 0x80800638: bc1f        L_80800648
    if (!c1cs) {
        // 0x8080063C: nop
    
            goto L_80800648;
    }
    // 0x8080063C: nop

    // 0x80800640: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80800644: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_80800648:
    // 0x80800648: lwc1        $f2, 0x149C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X149C));
    // 0x8080064C: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800650: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80800654: nop

    // 0x80800658: bc1f        L_80800668
    if (!c1cs) {
        // 0x8080065C: nop
    
            goto L_80800668;
    }
    // 0x8080065C: nop

    // 0x80800660: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80800664: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_80800668:
    // 0x80800668: jal         0x800DC0C0
    // 0x8080066C: nop

    func_800DC0C0(rdram, ctx);
        goto after_28;
    // 0x8080066C: nop

    after_28:
    // 0x80800670: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X14A0) << 16);
    // 0x80800674: lwc1        $f4, 0x14A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X14A0));
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080067C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800680: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800684: nop

    // 0x80800688: bc1f        L_808006B0
    if (!c1cs) {
        // 0x8080068C: nop
    
            goto L_808006B0;
    }
    // 0x8080068C: nop

    // 0x80800690: jal         0x80101E14
    // 0x80800694: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_29;
    // 0x80800694: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_29:
    // 0x80800698: beq         $v0, $zero, L_808006B0
    if (ctx->r2 == 0) {
        // 0x8080069C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006B0;
    }
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1588, 0X1570) << 16);
    // 0x808006A4: addiu       $a2, $a2, 0x1570
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1588, 0X1570));
    // 0x808006A8: jal         0x80089D18
    // 0x808006AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_30;
    // 0x808006AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_30:
L_808006B0:
    // 0x808006B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X14A4) << 16);
    // 0x808006B4: lwc1        $f2, 0x14A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X14A4));
    // 0x808006B8: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808006BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1588, 0X1580) << 16);
    // 0x808006C0: addiu       $a2, $a2, 0x1580
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1588, 0X1580));
    // 0x808006C4: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x808006C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X14A8) << 16);
    // 0x808006CC: bc1fl       L_808006DC
    if (!c1cs) {
        // 0x808006D0: lbu         $a0, 0x5F($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X5F);
            goto L_808006DC;
    }
    goto skip_7;
    // 0x808006D0: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    skip_7:
    // 0x808006D4: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x808006D8: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
L_808006DC:
    // 0x808006DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808006E0: bnel        $a0, $zero, L_808006FC
    if (ctx->r4 != 0) {
        // 0x808006E4: lwc1        $f8, 0x54($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
            goto L_808006FC;
    }
    goto skip_8;
    // 0x808006E4: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    skip_8:
    // 0x808006E8: jal         0x800C4350
    // 0x808006EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_31;
    // 0x808006EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x808006F0: b           L_80800720
    // 0x808006F4: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
        goto L_80800720;
    // 0x808006F4: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x808006F8: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
L_808006FC:
    // 0x808006FC: lwc1        $f10, 0x14A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X14A8));
    // 0x80800700: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800704: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800708: jal         0x800C31DC
    // 0x8080070C: nop

    func_800C31DC(rdram, ctx);
        goto after_32;
    // 0x8080070C: nop

    after_32:
    // 0x80800710: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800718: jal         0x800C4350
    // 0x8080071C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_33;
    // 0x8080071C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_33:
L_80800720:
    // 0x80800720: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080072C: andi        $t1, $t9, 0xFF03
    ctx->r9 = ctx->r25 & 0XFF03;
    // 0x80800730: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80800734: jal         0x808008F4
    // 0x80800738: sb          $t2, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r10;
    func_808008F4_chfiregen(rdram, ctx);
        goto after_34;
    // 0x80800738: sb          $t2, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r10;
    after_34:
    // 0x8080073C: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
L_80800740:
    // 0x80800740: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800744: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x80800748: nop

    // 0x8080074C: bc1t        L_808007A8
    if (c1cs) {
        // 0x80800750: nop
    
            goto L_808007A8;
    }
    // 0x80800750: nop

    // 0x80800754: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800758: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080075C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800760: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80800764: nop

    // 0x80800768: beq         $t4, $at, L_808007A8
    if (ctx->r12 == ctx->r1) {
        // 0x8080076C: nop
    
            goto L_808007A8;
    }
    // 0x8080076C: nop

    // 0x80800770: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800774: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800778: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080077C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800780: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80800784: nop

    // 0x80800788: bc1fl       L_808007A4
    if (!c1cs) {
        // 0x8080078C: sub.s       $f18, $f2, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
            goto L_808007A4;
    }
    goto skip_9;
    // 0x8080078C: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    skip_9:
    // 0x80800790: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800794: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80800798: b           L_808007A8
    // 0x8080079C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
        goto L_808007A8;
    // 0x8080079C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x808007A0: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
L_808007A4:
    // 0x808007A4: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_808007A8:
    // 0x808007A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X14AC) << 16);
    // 0x808007AC: lwc1        $f4, 0x14AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X14AC));
    // 0x808007B0: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808007B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808007B8: nop

    // 0x808007BC: bc1fl       L_80800814
    if (!c1cs) {
        // 0x808007C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800814;
    }
    goto skip_10;
    // 0x808007C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x808007C4: jal         0x801039E4
    // 0x808007C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_35;
    // 0x808007C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_35:
    // 0x808007CC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D4: jal         0x80103CB8
    // 0x808007D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80103CB8(rdram, ctx);
        goto after_36;
    // 0x808007D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_36:
    // 0x808007DC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808007E0: jal         0x800B2768
    // 0x808007E4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800B2768(rdram, ctx);
        goto after_37;
    // 0x808007E4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_37:
    // 0x808007E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808007EC: jal         0x800B2840
    // 0x808007F0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800B2840(rdram, ctx);
        goto after_38;
    // 0x808007F0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_38:
    // 0x808007F4: addiu       $t5, $s0, 0x34
    ctx->r13 = ADD32(ctx->r16, 0X34);
    // 0x808007F8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808007FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800800: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800804: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800808: jal         0x80087990
    // 0x8080080C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _dbmorph_entrypoint_3(rdram, ctx);
        goto after_39;
    // 0x8080080C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_39:
    // 0x80800810: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800814:
    // 0x80800814: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800818: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080081C: jr          $ra
    // 0x80800820: nop

    return;
    // 0x80800820: nop

;}
RECOMP_FUNC void bakaztorpedo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
;}
RECOMP_FUNC void chstonepillar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(880, 0X13F0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(880, 0X13F0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(880, 0X13F0));
;}
RECOMP_FUNC void func_80800060_chklungospiral(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080006C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800070: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800078: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080007C: beq         $t6, $at, L_8080009C
    if (ctx->r14 == ctx->r1) {
        // 0x80800080: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080009C;
    }
    // 0x80800080: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800084: beq         $t6, $at, L_808000CC
    if (ctx->r14 == ctx->r1) {
        // 0x80800088: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000CC;
    }
    // 0x80800088: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080008C: beq         $t6, $at, L_808000DC
    if (ctx->r14 == ctx->r1) {
        // 0x80800090: nop
    
            goto L_808000DC;
    }
    // 0x80800090: nop

    // 0x80800094: b           L_80800120
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800120;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080009C:
    // 0x8080009C: jal         0x8010C500
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000A4: beq         $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x808000A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080011C;
    }
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x80102424
    // 0x808000B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808000B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x808000BC: jal         0x808003AC
    // 0x808000C0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808003AC_chklungospiral(rdram, ctx);
        goto after_2;
    // 0x808000C0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_2:
    // 0x808000C4: b           L_80800120
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800120;
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000CC:
    // 0x808000CC: jal         0x80800480
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800480_chklungospiral(rdram, ctx);
        goto after_3;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000D4: b           L_80800120
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800120;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000DC:
    // 0x808000DC: jal         0x80105834
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_4;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000E4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1468, 0X668) << 16);
    // 0x808000E8: addiu       $a1, $a1, 0x668
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1468, 0X668));
    // 0x808000EC: jal         0x80105230
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105230(rdram, ctx);
        goto after_5;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000F4: jal         0x80105A5C
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_6;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000FC: beql        $v0, $zero, L_80800120
    if (ctx->r2 == 0) {
        // 0x80800100: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800120;
    }
    goto skip_0;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800104: jal         0x80800430
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800430_chklungospiral(rdram, ctx);
        goto after_7;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080010C: jal         0x800FFAB0
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800114: jal         0x800DA544
    // 0x80800118: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800118: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_9:
L_8080011C:
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800120:
    // 0x80800120: jal         0x80100094
    // 0x80800124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x80800124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800128: beq         $v0, $zero, L_80800148
    if (ctx->r2 == 0) {
        // 0x8080012C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800148;
    }
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: jal         0x80100094
    // 0x80800134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80800134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080013C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800140: jal         0x800897D8
    // 0x80800144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_12;
    // 0x80800144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
L_80800148:
    // 0x80800148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080014C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800150: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void func_8008F880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F888: jal         0x80106790
    // 0x8008F88C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8008F88C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008F890: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F894: jal         0x800EE7F8
    // 0x8008F898: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8008F898: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x8008F89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F8A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F8A4: jr          $ra
    // 0x8008F8A8: nop

    return;
    // 0x8008F8A8: nop

    // 0x8008F8AC: nop

;}
RECOMP_FUNC void _baflamethrower_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B98: syscall     131
    recomp_syscall_handler(rdram, ctx, 0x80084B98);
    return;
    // 0x80084B9C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80800D84_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D84: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800D88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800D90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D94: jal         0x80100094
    // 0x80800D98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D9C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800DA0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DA8: jal         0x80101E14
    // 0x80800DAC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x80800DAC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800DB0: beq         $v0, $zero, L_80800DC4
    if (ctx->r2 == 0) {
        // 0x80800DB4: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_80800DC4;
    }
    // 0x80800DB4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80800DB8: lbu         $t7, 0x8($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X8);
    // 0x80800DBC: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80800DC0: sb          $t8, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r24;
L_80800DC4:
    // 0x80800DC4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800DC8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1540, 0X1250) << 16);
    // 0x80800DCC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1540, 0X1290) << 16);
    // 0x80800DD0: addiu       $a3, $a3, 0x1290
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1540, 0X1290));
    // 0x80800DD4: addiu       $a2, $a2, 0x1250
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1540, 0X1250));
    // 0x80800DD8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800DDC: jal         0x80089D28
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800DE4: bne         $v0, $zero, L_80800E08
    if (ctx->r2 != 0) {
        // 0x80800DE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E08;
    }
    // 0x80800DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DEC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1540, 0X125C) << 16);
    // 0x80800DF0: lui         $a3, 0x3F23
    ctx->r7 = S32(0X3F23 << 16);
    // 0x80800DF4: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800DF8: addiu       $a2, $a2, 0x125C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1540, 0X125C));
    // 0x80800DFC: jal         0x80089D20
    // 0x80800E00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800E00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800E04: beq         $v0, $zero, L_80800E6C
    if (ctx->r2 == 0) {
        // 0x80800E08: addiu       $s0, $sp, 0x38
        ctx->r16 = ADD32(ctx->r29, 0X38);
            goto L_80800E6C;
    }
L_80800E08:
    // 0x80800E08: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x80800E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E10: jal         0x800EE7F8
    // 0x80800E14: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800E14: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800E18: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800E1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E20: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800E24: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800E28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800E2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800E30: jal         0x800EE7F8
    // 0x80800E34: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800E34: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80800E38: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800E3C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800E40: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800E44: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1540, 0X1264) << 16);
    // 0x80800E48: addiu       $t9, $t9, 0x1264
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1540, 0X1264));
    // 0x80800E4C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800E50: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E58: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800E5C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80800E60: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800E64: jal         0x800BBCB8
    // 0x80800E68: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_800BBCB8(rdram, ctx);
        goto after_6;
    // 0x80800E68: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_6:
L_80800E6C:
    // 0x80800E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800E70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E74: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800E78: jr          $ra
    // 0x80800E7C: nop

    return;
    // 0x80800E7C: nop

;}
RECOMP_FUNC void gcdialogcamera_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: jal         0x80089628
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _ncpoddialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080007C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800080: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    // 0x80800084: jr          $ra
    // 0x80800088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bsvanswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841B8: syscall     106
    recomp_syscall_handler(rdram, ctx, 0x800841B8);
    return;
    // 0x800841BC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chmineprospector_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CF0: syscall     228
    recomp_syscall_handler(rdram, ctx, 0x80085CF0);
    return;
    // 0x80085CF4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bswalk_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801440: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801444: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(435, 0X1560) << 16);
    // 0x80801448: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080144C: jr          $ra
    // 0x80801450: lw          $v0, 0x1560($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(435, 0X1560));
    return;
    // 0x80801450: lw          $v0, 0x1560($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(435, 0X1560));
;}
RECOMP_FUNC void _bsbtrot_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C38: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C38);
    return;
    // 0x80082C3C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_80801138_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080113C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801140: jal         0x80801994
    // 0x80801144: nop

    func_80801994_chalienkids(rdram, ctx);
        goto after_0;
    // 0x80801144: nop

    after_0:
    // 0x80801148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080114C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801150: jr          $ra
    // 0x80801154: nop

    return;
    // 0x80801154: nop

;}
RECOMP_FUNC void func_808026BC_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808026BC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808026C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808026C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808026C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808026CC: jal         0x80100094
    // 0x808026D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808026D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808026D4: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x808026D8: jal         0x801022E4
    // 0x808026DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_1;
    // 0x808026DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808026E0: slti        $at, $v0, 0x376
    ctx->r1 = SIGNED(ctx->r2) < 0X376 ? 1 : 0;
    // 0x808026E4: bne         $at, $zero, L_80802700
    if (ctx->r1 != 0) {
        // 0x808026E8: addiu       $t6, $v0, -0x371
        ctx->r14 = ADD32(ctx->r2, -0X371);
            goto L_80802700;
    }
    // 0x808026E8: addiu       $t6, $v0, -0x371
    ctx->r14 = ADD32(ctx->r2, -0X371);
    // 0x808026EC: addiu       $at, $zero, 0x3E7
    ctx->r1 = ADD32(0, 0X3E7);
    // 0x808026F0: beq         $v0, $at, L_808028E0
    if (ctx->r2 == ctx->r1) {
        // 0x808026F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808028E0;
    }
    // 0x808026F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026F8: b           L_808029C8
    // 0x808026FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808029C8;
    // 0x808026FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802700:
    // 0x80802700: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80802704: beq         $at, $zero, L_808029C4
    if (ctx->r1 == 0) {
        // 0x80802708: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808029C4;
    }
    // 0x80802708: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080270C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4540) << 16);
    // 0x80802710: addu        $at, $at, $t6
    gpr jr_addend_80802718 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80802714: lw          $t6, 0x4540($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4540));
    // 0x80802718: jr          $t6
    // 0x8080271C: nop

    switch (jr_addend_80802718 >> 2) {
        case 0: goto L_80802720; break;
        case 1: goto L_808028B8; break;
        case 2: goto L_80802900; break;
        case 3: goto L_808029C4; break;
        case 4: goto L_808028CC; break;
        default: switch_error(__func__, 0x80802718, 0x80804540);
    }
    // 0x8080271C: nop

L_80802720:
    // 0x80802720: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80802724: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X4980) << 16);
    // 0x80802728: lui         $a3, 0x3E61
    ctx->r7 = S32(0X3E61 << 16);
    // 0x8080272C: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    // 0x80802730: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80802734: ori         $a3, $a3, 0x47AE
    ctx->r7 = ctx->r7 | 0X47AE;
    // 0x80802738: addiu       $a2, $a2, 0x4980
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4980));
    // 0x8080273C: jal         0x80089D20
    // 0x80802740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80802740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802744: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X4970) << 16);
    // 0x80802748: lui         $a3, 0x3E75
    ctx->r7 = S32(0X3E75 << 16);
    // 0x8080274C: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x80802750: addiu       $a2, $a2, 0x4970
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4970));
    // 0x80802754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802758: jal         0x80089D20
    // 0x8080275C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080275C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80802760: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80802764: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80802768: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080276C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802770: jal         0x80102320
    // 0x80802774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102320(rdram, ctx);
        goto after_4;
    // 0x80802774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802778: beql        $v0, $zero, L_808027F4
    if (ctx->r2 == 0) {
        // 0x8080277C: lui         $a1, 0x3E75
        ctx->r5 = S32(0X3E75 << 16);
            goto L_808027F4;
    }
    goto skip_0;
    // 0x8080277C: lui         $a1, 0x3E75
    ctx->r5 = S32(0X3E75 << 16);
    skip_0:
    // 0x80802780: jal         0x8001210C
    // 0x80802784: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_5;
    // 0x80802784: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80802788: bne         $v0, $zero, L_808027F0
    if (ctx->r2 != 0) {
        // 0x8080278C: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_808027F0;
    }
    // 0x8080278C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80802790: jal         0x800EE7F8
    // 0x80802794: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80802794: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80802798: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080279C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x808027A0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808027A4: jal         0x800EE7F8
    // 0x808027A8: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x808027A8: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x808027AC: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x808027B0: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808027B4: jal         0x800EF1B8
    // 0x808027B8: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_8;
    // 0x808027B8: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    after_8:
    // 0x808027BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4554) << 16);
    // 0x808027C0: lwc1        $f8, 0x4554($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4554));
    // 0x808027C4: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808027C8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1360, 0X4928) << 16);
    // 0x808027CC: addiu       $t7, $t7, 0x4928
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1360, 0X4928));
    // 0x808027D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808027D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808027D8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808027DC: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808027E0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x808027E4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808027E8: jal         0x800BBCB8
    // 0x808027EC: nop

    func_800BBCB8(rdram, ctx);
        goto after_9;
    // 0x808027EC: nop

    after_9:
L_808027F0:
    // 0x808027F0: lui         $a1, 0x3E75
    ctx->r5 = S32(0X3E75 << 16);
L_808027F4:
    // 0x808027F4: lui         $a2, 0x3F23
    ctx->r6 = S32(0X3F23 << 16);
    // 0x808027F8: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x808027FC: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x80802800: jal         0x80102320
    // 0x80802804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102320(rdram, ctx);
        goto after_10;
    // 0x80802804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80802808: beq         $v0, $zero, L_8080283C
    if (ctx->r2 == 0) {
        // 0x8080280C: nop
    
            goto L_8080283C;
    }
    // 0x8080280C: nop

    // 0x80802810: jal         0x8001210C
    // 0x80802814: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_11;
    // 0x80802814: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80802818: beq         $v0, $zero, L_8080283C
    if (ctx->r2 == 0) {
        // 0x8080281C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080283C;
    }
    // 0x8080281C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80802820: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1360, 0X4928) << 16);
    // 0x80802824: addiu       $t8, $t8, 0x4928
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1360, 0X4928));
    // 0x80802828: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8080282C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80802830: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80802834: jal         0x800BBCB8
    // 0x80802838: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_12;
    // 0x80802838: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_12:
L_8080283C:
    // 0x8080283C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X4990) << 16);
    // 0x80802840: lui         $a3, 0x3EAE
    ctx->r7 = S32(0X3EAE << 16);
    // 0x80802844: ori         $a3, $a3, 0x147B
    ctx->r7 = ctx->r7 | 0X147B;
    // 0x80802848: addiu       $a2, $a2, 0x4990
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4990));
    // 0x8080284C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802850: jal         0x80089D20
    // 0x80802854: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x80802854: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x80802858: beql        $v0, $zero, L_808029C8
    if (ctx->r2 == 0) {
        // 0x8080285C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808029C8;
    }
    goto skip_1;
    // 0x8080285C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80802860: jal         0x800E1540
    // 0x80802864: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800E1540(rdram, ctx);
        goto after_14;
    // 0x80802864: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_14:
    // 0x80802868: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080286C: jal         0x800E1378
    // 0x80802870: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E1378(rdram, ctx);
        goto after_15;
    // 0x80802870: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x80802874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802878: jal         0x800E13F0
    // 0x8080287C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_800E13F0(rdram, ctx);
        goto after_16;
    // 0x8080287C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_16:
    // 0x80802880: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80802884: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80802888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080288C: jal         0x800E1410
    // 0x80802890: lui         $a1, 0xC100
    ctx->r5 = S32(0XC100 << 16);
    func_800E1410(rdram, ctx);
        goto after_17;
    // 0x80802890: lui         $a1, 0xC100
    ctx->r5 = S32(0XC100 << 16);
    after_17:
    // 0x80802894: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80802898: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x8080289C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808028A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808028A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808028A8: jal         0x800187B4
    // 0x808028AC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800187B4(rdram, ctx);
        goto after_18;
    // 0x808028AC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_18:
    // 0x808028B0: b           L_808029C8
    // 0x808028B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808029C8;
    // 0x808028B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808028B8:
    // 0x808028B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808028BC: jal         0x80802ABC
    // 0x808028C0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80802ABC_chweldarboss(rdram, ctx);
        goto after_19;
    // 0x808028C0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_19:
    // 0x808028C4: b           L_808029C8
    // 0x808028C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808029C8;
    // 0x808028C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808028CC:
    // 0x808028CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808028D0: jal         0x80802ABC
    // 0x808028D4: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80802ABC_chweldarboss(rdram, ctx);
        goto after_20;
    // 0x808028D4: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_20:
    // 0x808028D8: b           L_808029C8
    // 0x808028DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808029C8;
    // 0x808028DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808028E0:
    // 0x808028E0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X4918) << 16);
    // 0x808028E4: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x808028E8: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808028EC: addiu       $a2, $a2, 0x4918
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4918));
    // 0x808028F0: jal         0x80089D20
    // 0x808028F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_21;
    // 0x808028F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_21:
    // 0x808028F8: b           L_808029C8
    // 0x808028FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808029C8;
    // 0x808028FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802900:
    // 0x80802900: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802904: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X4918) << 16);
    // 0x80802908: lui         $a3, 0x3DA3
    ctx->r7 = S32(0X3DA3 << 16);
    // 0x8080290C: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80802910: addiu       $a2, $a2, 0x4918
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4918));
    // 0x80802914: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80802918: jal         0x80089D20
    // 0x8080291C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x8080291C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80802920: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X49A4) << 16);
    // 0x80802924: addiu       $a2, $a2, 0x49A4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X49A4));
    // 0x80802928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080292C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80802930: jal         0x80089D20
    // 0x80802934: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x80802934: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_23:
    // 0x80802938: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x8080293C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80802940: jal         0x80101E14
    // 0x80802944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_24;
    // 0x80802944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80802948: beq         $v0, $zero, L_808029C4
    if (ctx->r2 == 0) {
        // 0x8080294C: lw          $v1, 0x6C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X6C);
            goto L_808029C4;
    }
    // 0x8080294C: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80802950: lbu         $t9, 0x6F($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X6F);
    // 0x80802954: lbu         $v0, 0x66($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X66);
    // 0x80802958: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x8080295C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80802960: sb          $t0, 0x6F($v1)
    MEM_B(0X6F, ctx->r3) = ctx->r8;
    // 0x80802964: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80802968: jal         0x8008A0E0
    // 0x8080296C: addiu       $a1, $v0, 0x7
    ctx->r5 = ADD32(ctx->r2, 0X7);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x8080296C: addiu       $a1, $v0, 0x7
    ctx->r5 = ADD32(ctx->r2, 0X7);
    after_25:
    // 0x80802970: beq         $v0, $zero, L_808029C4
    if (ctx->r2 == 0) {
        // 0x80802974: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808029C4;
    }
    // 0x80802974: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80802978: jal         0x800F1DF4
    // 0x8080297C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800F1DF4(rdram, ctx);
        goto after_26;
    // 0x8080297C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_26:
    // 0x80802980: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80802984: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80802988: jal         0x800EE7F8
    // 0x8080298C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_27;
    // 0x8080298C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_27:
    // 0x80802990: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80802994: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80802998: jal         0x800EF1B8
    // 0x8080299C: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_28;
    // 0x8080299C: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    after_28:
    // 0x808029A0: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808029A4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x808029A8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808029AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808029B0: addiu       $a1, $zero, 0x86E
    ctx->r5 = ADD32(0, 0X86E);
    // 0x808029B4: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x808029B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808029BC: jal         0x80086680
    // 0x808029C0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    _chexploder_entrypoint_5(rdram, ctx);
        goto after_29;
    // 0x808029C0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_29:
L_808029C4:
    // 0x808029C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808029C8:
    // 0x808029C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808029CC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x808029D0: jr          $ra
    // 0x808029D4: nop

    return;
    // 0x808029D4: nop

;}
RECOMP_FUNC void func_80800C18_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C20: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800C24: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800C28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800C2C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800C30: beql        $t7, $zero, L_80800C54
    if (ctx->r15 == 0) {
        // 0x80800C34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800C54;
    }
    goto skip_0;
    // 0x80800C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800C38: jal         0x800856B8
    // 0x80800C3C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800C3C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800C40: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800C44: lhu         $t8, 0x6E($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6E);
    // 0x80800C48: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800C4C: sh          $t9, 0x6E($a1)
    MEM_H(0X6E, ctx->r5) = ctx->r25;
    // 0x80800C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C54:
    // 0x80800C54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C58: jr          $ra
    // 0x80800C5C: nop

    return;
    // 0x80800C5C: nop

;}
RECOMP_FUNC void func_8010B910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B914: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010B918: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8010B91C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B920: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010B924: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010B928: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010B92C: addiu       $a1, $a2, 0x28
    ctx->r5 = ADD32(ctx->r6, 0X28);
    // 0x8010B930: jal         0x800EF04C
    // 0x8010B934: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_0;
    // 0x8010B934: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8010B938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B93C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B940: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B944: jr          $ra
    // 0x8010B948: nop

    return;
    // 0x8010B948: nop

;}
RECOMP_FUNC void _idflasha_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D58: syscall     738
    recomp_syscall_handler(rdram, ctx, 0x80088D58);
    return;
    // 0x80088D5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_chlinkpipefan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800018: slti        $at, $t6, 0x33
    ctx->r1 = SIGNED(ctx->r14) < 0X33 ? 1 : 0;
    // 0x8080001C: bne         $at, $zero, L_80800030
    if (ctx->r1 != 0) {
        // 0x80800020: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800030;
    }
    // 0x80800020: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800024: slti        $at, $t6, 0x3A
    ctx->r1 = SIGNED(ctx->r14) < 0X3A ? 1 : 0;
    // 0x80800028: bne         $at, $zero, L_80800044
    if (ctx->r1 != 0) {
        // 0x8080002C: nop
    
            goto L_80800044;
    }
    // 0x8080002C: nop

L_80800030:
    // 0x80800030: jal         0x800FFA88
    // 0x80800034: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_0;
    // 0x80800034: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x80800038: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x8080003C: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x80800040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80800044:
    // 0x80800044: jal         0x800DA298
    // 0x80800048: addiu       $a0, $v0, 0x15C
    ctx->r4 = ADD32(ctx->r2, 0X15C);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800048: addiu       $a0, $v0, 0x15C
    ctx->r4 = ADD32(ctx->r2, 0X15C);
    after_1:
    // 0x8080004C: beql        $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x80800050: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_80800060;
    }
    goto skip_0;
    // 0x80800050: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    skip_0:
    // 0x80800054: jal         0x800FFA88
    // 0x80800058: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80800058: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x8080005C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_80800060:
    // 0x80800060: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800064: nop

    // 0x80800068: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x8080006C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800070: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800074: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void chscorepoints_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080033C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800340: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800344: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800348: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080034C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800350: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800354: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800358: lwc1        $f8, 0x4($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8080035C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80800360: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80800364: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800368: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080036C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800370: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800374: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80800378: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8080037C: addiu       $a0, $a0, 0x6460
    ctx->r4 = ADD32(ctx->r4, 0X6460);
    // 0x80800380: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800384: lwc1        $f16, 0x8($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80800388: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8080038C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80800390: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800394: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80800398: jal         0x80086D58
    // 0x8080039C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x8080039C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_0:
    // 0x808003A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003A8: jr          $ra
    // 0x808003AC: nop

    return;
    // 0x808003AC: nop

;}
RECOMP_FUNC void bapulse_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800078: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080007C: jal         0x800D8FF8
    // 0x80800080: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800080: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800088: lw          $v0, 0xE8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE8);
    // 0x8080008C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80800090: bnel        $t6, $zero, L_808000F4
    if (ctx->r14 != 0) {
        // 0x80800094: lwc1        $f16, 0x8($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
            goto L_808000F4;
    }
    goto skip_0;
    // 0x80800094: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x80800098: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8080009C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808000A0: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x808000A4: lw          $v0, 0xE8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE8);
    // 0x808000A8: lwc1        $f20, 0x8($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808000AC: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808000B0: c.le.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl <= ctx->f20.fl;
    // 0x808000B4: nop

    // 0x808000B8: bc1fl       L_80800140
    if (!c1cs) {
        // 0x808000BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800140;
    }
    goto skip_1;
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808000C0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808000C4: jal         0x800F13C4
    // 0x808000C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F13C4(rdram, ctx);
        goto after_1;
    // 0x808000C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x808000CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808000D4: lw          $v0, 0xE8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE8);
    // 0x808000D8: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808000DC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808000E0: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x808000E4: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x808000E8: b           L_8080013C
    // 0x808000EC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
        goto L_8080013C;
    // 0x808000EC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x808000F0: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
L_808000F4:
    // 0x808000F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000F8: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x808000FC: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x80800100: lw          $v0, 0xE8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE8);
    // 0x80800104: lwc1        $f20, 0x8($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800108: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x8080010C: nop

    // 0x80800110: bc1fl       L_80800140
    if (!c1cs) {
        // 0x80800114: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800140;
    }
    goto skip_2;
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800118: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8080011C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800120: jal         0x800F13C4
    // 0x80800124: neg.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = -ctx->f20.fl;
    func_800F13C4(rdram, ctx);
        goto after_2;
    // 0x80800124: neg.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = -ctx->f20.fl;
    after_2:
    // 0x80800128: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080012C: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x80800130: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
    // 0x80800134: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x80800138: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_8080013C:
    // 0x8080013C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800140:
    // 0x80800140: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800144: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
