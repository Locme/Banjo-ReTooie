#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8010F68C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F68C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8010F690: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8010F694: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8010F698: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8010F69C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8010F6A0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8010F6A4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8010F6A8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8010F6AC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8010F6B0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8010F6B4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8010F6B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8010F6BC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010F6C0: jal         0x800B2344
    // 0x8010F6C4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    func_800B2344(rdram, ctx);
        goto after_0;
    // 0x8010F6C4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010F6C8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8010F6CC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010F6D0: lw          $t7, 0x7244($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7244);
    // 0x8010F6D4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8010F6D8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8010F6DC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8010F6E0: addu        $v1, $t6, $s7
    ctx->r3 = ADD32(ctx->r14, ctx->r23);
    // 0x8010F6E4: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x8010F6E8: beq         $t7, $zero, L_8010F8AC
    if (ctx->r15 == 0) {
        // 0x8010F6EC: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_8010F8AC;
    }
    // 0x8010F6EC: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x8010F6F0: sltu        $at, $s7, $v1
    ctx->r1 = ctx->r23 < ctx->r3 ? 1 : 0;
    // 0x8010F6F4: beq         $at, $zero, L_8010F898
    if (ctx->r1 == 0) {
        // 0x8010F6F8: lui         $fp, 0x8013
        ctx->r30 = S32(0X8013 << 16);
            goto L_8010F898;
    }
    // 0x8010F6F8: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x8010F6FC: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8010F700: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010F704: addiu       $fp, $fp, 0x7250
    ctx->r30 = ADD32(ctx->r30, 0X7250);
    // 0x8010F708: lui         $s6, 0x1
    ctx->r22 = S32(0X1 << 16);
    // 0x8010F70C: addiu       $s5, $zero, 0x4000
    ctx->r21 = ADD32(0, 0X4000);
    // 0x8010F710: lhu         $t8, 0x6($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X6);
L_8010F714:
    // 0x8010F714: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
    // 0x8010F718: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8010F71C: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x8010F720: bnel        $t9, $zero, L_8010F884
    if (ctx->r25 != 0) {
        // 0x8010F724: lw          $t5, 0x48($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X48);
            goto L_8010F884;
    }
    goto skip_0;
    // 0x8010F724: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x8010F728: lw          $a3, 0x7248($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7248);
    // 0x8010F72C: lbu         $s1, 0x6($s7)
    ctx->r17 = MEM_BU(ctx->r23, 0X6);
    // 0x8010F730: lbu         $s3, 0x7($s7)
    ctx->r19 = MEM_BU(ctx->r23, 0X7);
    // 0x8010F734: sltu        $at, $fp, $a3
    ctx->r1 = ctx->r30 < ctx->r7 ? 1 : 0;
    // 0x8010F738: beq         $at, $zero, L_8010F84C
    if (ctx->r1 == 0) {
        // 0x8010F73C: lbu         $s4, 0x8($s7)
        ctx->r20 = MEM_BU(ctx->r23, 0X8);
            goto L_8010F84C;
    }
    // 0x8010F73C: lbu         $s4, 0x8($s7)
    ctx->r20 = MEM_BU(ctx->r23, 0X8);
    // 0x8010F740: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_8010F744:
    // 0x8010F744: lh          $t1, 0x0($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X0);
    // 0x8010F748: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8010F74C: lh          $t3, 0x2($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X2);
    // 0x8010F750: subu        $v0, $t0, $t1
    ctx->r2 = SUB32(ctx->r8, ctx->r9);
    // 0x8010F754: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010F758: subu        $v1, $t2, $t3
    ctx->r3 = SUB32(ctx->r10, ctx->r11);
    // 0x8010F75C: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x8010F760: lh          $t5, 0x4($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X4);
    // 0x8010F764: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    // 0x8010F768: subu        $a0, $t4, $t5
    ctx->r4 = SUB32(ctx->r12, ctx->r13);
    // 0x8010F76C: mflo        $t6
    ctx->r14 = lo;
    // 0x8010F770: nop

    // 0x8010F774: nop

    // 0x8010F778: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010F77C: mflo        $t7
    ctx->r15 = lo;
    // 0x8010F780: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8010F784: nop

    // 0x8010F788: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010F78C: mflo        $t9
    ctx->r25 = lo;
    // 0x8010F790: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8010F794: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8010F798: beq         $at, $zero, L_8010F83C
    if (ctx->r1 == 0) {
        // 0x8010F79C: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8010F83C;
    }
    // 0x8010F79C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8010F7A0: beql        $a1, $zero, L_8010F7D0
    if (ctx->r5 == 0) {
        // 0x8010F7A4: lw          $a0, 0xC($s0)
        ctx->r4 = MEM_W(ctx->r16, 0XC);
            goto L_8010F7D0;
    }
    goto skip_1;
    // 0x8010F7A4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x8010F7A8: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8010F7AC: jal         0x8002DCA0
    // 0x8010F7B0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8010F7B0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x8010F7B4: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8010F7B8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8010F7BC: lw          $a3, 0x7248($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7248);
    // 0x8010F7C0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8010F7C4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8010F7C8: nop

    // 0x8010F7CC: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
L_8010F7D0:
    // 0x8010F7D0: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x8010F7D4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8010F7D8: beq         $at, $zero, L_8010F800
    if (ctx->r1 == 0) {
        // 0x8010F7DC: nop
    
            goto L_8010F800;
    }
    // 0x8010F7DC: nop

    // 0x8010F7E0: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x8010F7E4: subu        $t3, $a2, $a0
    ctx->r11 = SUB32(ctx->r6, ctx->r4);
    // 0x8010F7E8: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010F7EC: mflo        $t4
    ctx->r12 = lo;
    // 0x8010F7F0: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x8010F7F4: subu        $v1, $s5, $t5
    ctx->r3 = SUB32(ctx->r21, ctx->r13);
    // 0x8010F7F8: b           L_8010F800
    // 0x8010F7FC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
        goto L_8010F800;
    // 0x8010F7FC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_8010F800:
    // 0x8010F800: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x8010F804: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8010F808: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x8010F80C: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010F810: mflo        $t7
    ctx->r15 = lo;
    // 0x8010F814: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8010F818: addu        $s1, $s1, $t8
    ctx->r17 = ADD32(ctx->r17, ctx->r24);
    // 0x8010F81C: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010F820: mflo        $t0
    ctx->r8 = lo;
    // 0x8010F824: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8010F828: addu        $s3, $s3, $t1
    ctx->r19 = ADD32(ctx->r19, ctx->r9);
    // 0x8010F82C: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010F830: mflo        $t3
    ctx->r11 = lo;
    // 0x8010F834: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8010F838: addu        $s4, $s4, $t4
    ctx->r20 = ADD32(ctx->r20, ctx->r12);
L_8010F83C:
    // 0x8010F83C: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x8010F840: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x8010F844: bnel        $at, $zero, L_8010F744
    if (ctx->r1 != 0) {
        // 0x8010F848: lw          $t0, 0x0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X0);
            goto L_8010F744;
    }
    goto skip_2;
    // 0x8010F848: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    skip_2:
L_8010F84C:
    // 0x8010F84C: slti        $at, $s1, 0x100
    ctx->r1 = SIGNED(ctx->r17) < 0X100 ? 1 : 0;
    // 0x8010F850: bnel        $at, $zero, L_8010F860
    if (ctx->r1 != 0) {
        // 0x8010F854: slti        $at, $s3, 0x100
        ctx->r1 = SIGNED(ctx->r19) < 0X100 ? 1 : 0;
            goto L_8010F860;
    }
    goto skip_3;
    // 0x8010F854: slti        $at, $s3, 0x100
    ctx->r1 = SIGNED(ctx->r19) < 0X100 ? 1 : 0;
    skip_3:
    // 0x8010F858: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x8010F85C: slti        $at, $s3, 0x100
    ctx->r1 = SIGNED(ctx->r19) < 0X100 ? 1 : 0;
L_8010F860:
    // 0x8010F860: bne         $at, $zero, L_8010F86C
    if (ctx->r1 != 0) {
        // 0x8010F864: sb          $s1, 0xC($s2)
        MEM_B(0XC, ctx->r18) = ctx->r17;
            goto L_8010F86C;
    }
    // 0x8010F864: sb          $s1, 0xC($s2)
    MEM_B(0XC, ctx->r18) = ctx->r17;
    // 0x8010F868: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
L_8010F86C:
    // 0x8010F86C: slti        $at, $s4, 0x100
    ctx->r1 = SIGNED(ctx->r20) < 0X100 ? 1 : 0;
    // 0x8010F870: bne         $at, $zero, L_8010F87C
    if (ctx->r1 != 0) {
        // 0x8010F874: sb          $s3, 0xD($s2)
        MEM_B(0XD, ctx->r18) = ctx->r19;
            goto L_8010F87C;
    }
    // 0x8010F874: sb          $s3, 0xD($s2)
    MEM_B(0XD, ctx->r18) = ctx->r19;
    // 0x8010F878: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
L_8010F87C:
    // 0x8010F87C: sb          $s4, 0xE($s2)
    MEM_B(0XE, ctx->r18) = ctx->r20;
    // 0x8010F880: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
L_8010F884:
    // 0x8010F884: addiu       $s7, $s7, 0xA
    ctx->r23 = ADD32(ctx->r23, 0XA);
    // 0x8010F888: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x8010F88C: sltu        $at, $s7, $t5
    ctx->r1 = ctx->r23 < ctx->r13 ? 1 : 0;
    // 0x8010F890: bnel        $at, $zero, L_8010F714
    if (ctx->r1 != 0) {
        // 0x8010F894: lhu         $t8, 0x6($s2)
        ctx->r24 = MEM_HU(ctx->r18, 0X6);
            goto L_8010F714;
    }
    goto skip_4;
    // 0x8010F894: lhu         $t8, 0x6($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X6);
    skip_4:
L_8010F898:
    // 0x8010F898: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8010F89C: lbu         $t8, 0x17($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X17);
    // 0x8010F8A0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8010F8A4: b           L_8010F91C
    // 0x8010F8A8: sb          $t9, 0x17($t6)
    MEM_B(0X17, ctx->r14) = ctx->r25;
        goto L_8010F91C;
    // 0x8010F8A8: sb          $t9, 0x17($t6)
    MEM_B(0X17, ctx->r14) = ctx->r25;
L_8010F8AC:
    // 0x8010F8AC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8010F8B0: sltu        $at, $s7, $v1
    ctx->r1 = ctx->r23 < ctx->r3 ? 1 : 0;
    // 0x8010F8B4: lhu         $t1, 0x16($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X16);
    // 0x8010F8B8: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8010F8BC: beql        $t2, $zero, L_8010F920
    if (ctx->r10 == 0) {
        // 0x8010F8C0: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8010F920;
    }
    goto skip_5;
    // 0x8010F8C0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_5:
    // 0x8010F8C4: beql        $at, $zero, L_8010F910
    if (ctx->r1 == 0) {
        // 0x8010F8C8: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_8010F910;
    }
    goto skip_6;
    // 0x8010F8C8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    skip_6:
    // 0x8010F8CC: lhu         $t3, 0x6($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X6);
L_8010F8D0:
    // 0x8010F8D0: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x8010F8D4: bnel        $t4, $zero, L_8010F8F8
    if (ctx->r12 != 0) {
        // 0x8010F8D8: lw          $t9, 0x48($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X48);
            goto L_8010F8F8;
    }
    goto skip_7;
    // 0x8010F8D8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    skip_7:
    // 0x8010F8DC: lbu         $t5, 0x6($s7)
    ctx->r13 = MEM_BU(ctx->r23, 0X6);
    // 0x8010F8E0: sb          $t5, 0xC($s2)
    MEM_B(0XC, ctx->r18) = ctx->r13;
    // 0x8010F8E4: lbu         $t7, 0x7($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0X7);
    // 0x8010F8E8: sb          $t7, 0xD($s2)
    MEM_B(0XD, ctx->r18) = ctx->r15;
    // 0x8010F8EC: lbu         $t8, 0x8($s7)
    ctx->r24 = MEM_BU(ctx->r23, 0X8);
    // 0x8010F8F0: sb          $t8, 0xE($s2)
    MEM_B(0XE, ctx->r18) = ctx->r24;
    // 0x8010F8F4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
L_8010F8F8:
    // 0x8010F8F8: addiu       $s7, $s7, 0xA
    ctx->r23 = ADD32(ctx->r23, 0XA);
    // 0x8010F8FC: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x8010F900: sltu        $at, $s7, $t9
    ctx->r1 = ctx->r23 < ctx->r25 ? 1 : 0;
    // 0x8010F904: bnel        $at, $zero, L_8010F8D0
    if (ctx->r1 != 0) {
        // 0x8010F908: lhu         $t3, 0x6($s2)
        ctx->r11 = MEM_HU(ctx->r18, 0X6);
            goto L_8010F8D0;
    }
    goto skip_8;
    // 0x8010F908: lhu         $t3, 0x6($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X6);
    skip_8:
    // 0x8010F90C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_8010F910:
    // 0x8010F910: lbu         $t0, 0x17($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X17);
    // 0x8010F914: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x8010F918: sb          $t1, 0x17($t6)
    MEM_B(0X17, ctx->r14) = ctx->r9;
L_8010F91C:
    // 0x8010F91C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8010F920:
    // 0x8010F920: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010F924: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8010F928: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8010F92C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8010F930: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8010F934: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8010F938: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8010F93C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8010F940: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8010F944: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8010F948: jr          $ra
    // 0x8010F94C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8010F94C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void gsmaker_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080068C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800698: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080069C: jal         0x8080051C
    // 0x808006A0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    gsmaker_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x808006A0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x808006A4: bne         $v0, $zero, L_808006B4
    if (ctx->r2 != 0) {
        // 0x808006A8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808006B4;
    }
    // 0x808006A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006AC: b           L_808006C4
    // 0x808006B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006C4;
    // 0x808006B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006B4:
    // 0x808006B4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808006B8: jal         0x808002C4
    // 0x808006BC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    gsmaker_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808006BC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808006C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006C4:
    // 0x808006C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006CC: jr          $ra
    // 0x808006D0: nop

    return;
    // 0x808006D0: nop

;}
RECOMP_FUNC void func_80800AD8_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AE0: jal         0x800A587C
    // 0x80800AE4: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x80800AE4: nop

    after_0:
    // 0x80800AE8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800AEC: beq         $v0, $at, L_80800B14
    if (ctx->r2 == ctx->r1) {
        // 0x80800AF0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800B14;
    }
    // 0x80800AF0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800AF4: beq         $v0, $at, L_80800B24
    if (ctx->r2 == ctx->r1) {
        // 0x80800AF8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80800B24;
    }
    // 0x80800AF8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800AFC: beq         $v0, $at, L_80800B34
    if (ctx->r2 == ctx->r1) {
        // 0x80800B00: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800B34;
    }
    // 0x80800B00: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800B04: beq         $v0, $at, L_80800B44
    if (ctx->r2 == ctx->r1) {
        // 0x80800B08: nop
    
            goto L_80800B44;
    }
    // 0x80800B08: nop

    // 0x80800B0C: b           L_80800B54
    // 0x80800B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B54;
    // 0x80800B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B14:
    // 0x80800B14: jal         0x800A586C
    // 0x80800B18: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800B18: nop

    after_1:
    // 0x80800B1C: b           L_80800B54
    // 0x80800B20: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_80800B54;
    // 0x80800B20: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80800B24:
    // 0x80800B24: jal         0x800A586C
    // 0x80800B28: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x80800B28: nop

    after_2:
    // 0x80800B2C: b           L_80800B54
    // 0x80800B30: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
        goto L_80800B54;
    // 0x80800B30: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
L_80800B34:
    // 0x80800B34: jal         0x800A586C
    // 0x80800B38: nop

    func_800A586C(rdram, ctx);
        goto after_3;
    // 0x80800B38: nop

    after_3:
    // 0x80800B3C: b           L_80800B58
    // 0x80800B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B58;
    // 0x80800B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B44:
    // 0x80800B44: jal         0x800A586C
    // 0x80800B48: nop

    func_800A586C(rdram, ctx);
        goto after_4;
    // 0x80800B48: nop

    after_4:
    // 0x80800B4C: b           L_80800B54
    // 0x80800B50: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
        goto L_80800B54;
    // 0x80800B50: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
L_80800B54:
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B58:
    // 0x80800B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B5C: jr          $ra
    // 0x80800B60: nop

    return;
    // 0x80800B60: nop

;}
RECOMP_FUNC void func_80112204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112204: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80112208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011220C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80112210: jal         0x80112168
    // 0x80112214: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80112168(rdram, ctx);
        goto after_0;
    // 0x80112214: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80112218: jal         0x80110840
    // 0x8011221C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80110840(rdram, ctx);
        goto after_1;
    // 0x8011221C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80112220: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80112224: jal         0x800F5470
    // 0x80112228: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800F5470(rdram, ctx);
        goto after_2;
    // 0x80112228: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8011222C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80112230: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80112234: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80112238: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8011223C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80112240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80112244: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80112248: jr          $ra
    // 0x8011224C: nop

    return;
    // 0x8011224C: nop

;}
RECOMP_FUNC void _bscrouch_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F78: syscall     36
    recomp_syscall_handler(rdram, ctx, 0x80082F78);
    return;
    // 0x80082F7C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void idtwinkle_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808005C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005CC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808005D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005D4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x808005D8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x808005DC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808005E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808005E4: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x808005E8: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x808005EC: jal         0x80088888
    // 0x808005F0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    _glidmake_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808005F0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    after_0:
    // 0x808005F4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808005F8: jal         0x80088890
    // 0x808005FC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    _glidmake_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808005FC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_1:
    // 0x80800600: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80800604: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x80800608: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x8080060C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800610: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800614: addiu       $a2, $sp, 0x4E
    ctx->r6 = ADD32(ctx->r29, 0X4E);
    // 0x80800618: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
L_8080061C:
    // 0x8080061C: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80800620: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80800624: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800628: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8080062C: sh          $t8, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r24;
    // 0x80800630: lh          $v0, -0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, -0X2);
    // 0x80800634: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80800638: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080063C: mflo        $t9
    ctx->r25 = lo;
    // 0x80800640: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80800644: bnel        $a0, $a2, L_8080061C
    if (ctx->r4 != ctx->r6) {
        // 0x80800648: lh          $t6, 0x0($a1)
        ctx->r14 = MEM_H(ctx->r5, 0X0);
            goto L_8080061C;
    }
    goto skip_0;
    // 0x80800648: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    skip_0:
    // 0x8080064C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80800650: jal         0x8002DCA0
    // 0x80800654: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80800654: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x80800658: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080065C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800660: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800664: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800668: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8080066C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800670: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80800674: nop

    // 0x80800678: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080067C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800680: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800684: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2926, 0X8F0) << 16);
    // 0x80800688: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8080068C: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80800690: nop

    // 0x80800694: sh          $t4, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r12;
    // 0x80800698: lh          $t5, 0x1A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A);
    // 0x8080069C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x808006A0: nop

    // 0x808006A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808006A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808006AC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808006B0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x808006B4: nop

    // 0x808006B8: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
    // 0x808006BC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x808006C0: lwc1        $f8, 0x8F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2926, 0X8F0));
    // 0x808006C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006C8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808006CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808006D4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808006D8: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808006DC: jal         0x800DC264
    // 0x808006E0: swc1        $f14, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f14.u32l;
    func_800DC264(rdram, ctx);
        goto after_3;
    // 0x808006E0: swc1        $f14, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f14.u32l;
    after_3:
    // 0x808006E4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x808006E8: jal         0x8001ACCC
    // 0x808006EC: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    heap_alloc(rdram, ctx);
        goto after_4;
    // 0x808006EC: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_4:
    // 0x808006F0: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x808006F4: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // 0x808006F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800700: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800704: jr          $ra
    // 0x80800708: nop

    return;
    // 0x80800708: nop

;}
RECOMP_FUNC void func_808001B4_chweldarbossfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001C4: jal         0x80101970
    // 0x808001C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80101970(rdram, ctx);
        goto after_0;
    // 0x808001C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001CC: jal         0x800DF830
    // 0x808001D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_1;
    // 0x808001D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x808001D4: jal         0x800D674C
    // 0x808001D8: addiu       $a0, $zero, 0x89D
    ctx->r4 = ADD32(0, 0X89D);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x808001D8: addiu       $a0, $zero, 0x89D
    ctx->r4 = ADD32(0, 0X89D);
    after_2:
    // 0x808001DC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808001E0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808001E4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001E8: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x808001EC: jal         0x800DE448
    // 0x808001F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_3;
    // 0x808001F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x801018A4
    // 0x808001FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_801018A4(rdram, ctx);
        goto after_4;
    // 0x808001FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800200: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800204: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800208: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080020C: jr          $ra
    // 0x80800210: nop

    return;
    // 0x80800210: nop

;}
RECOMP_FUNC void func_800EA628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA628: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800EA62C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800EA630: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800EA634: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800EA638: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800EA63C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EA640: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800EA644: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800EA648: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800EA64C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800EA650: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800EA654: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800EA658: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800EA65C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800EA660: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800EA664: sw          $a3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r7;
    // 0x800EA668: jal         0x800E9E88
    // 0x800EA66C: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    func_800E9E88(rdram, ctx);
        goto after_0;
    // 0x800EA66C: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    after_0:
    // 0x800EA670: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800EA674: jal         0x800E9EB4
    // 0x800EA678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9EB4(rdram, ctx);
        goto after_1;
    // 0x800EA678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800EA67C: sltu        $at, $s4, $v0
    ctx->r1 = ctx->r20 < ctx->r2 ? 1 : 0;
    // 0x800EA680: beq         $at, $zero, L_800EA9F4
    if (ctx->r1 == 0) {
        // 0x800EA684: sw          $v0, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = ctx->r2;
            goto L_800EA9F4;
    }
    // 0x800EA684: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    // 0x800EA688: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800EA68C: lw          $s7, 0xD0($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XD0);
    // 0x800EA690: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
L_800EA694:
    // 0x800EA694: sll         $t7, $v0, 27
    ctx->r15 = S32(ctx->r2 << 27);
    // 0x800EA698: bgez        $t7, L_800EA9E0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800EA69C: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_800EA9E0;
    }
    // 0x800EA69C: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800EA6A0: bne         $t8, $zero, L_800EA858
    if (ctx->r24 != 0) {
        // 0x800EA6A4: sll         $t2, $v0, 28
        ctx->r10 = S32(ctx->r2 << 28);
            goto L_800EA858;
    }
    // 0x800EA6A4: sll         $t2, $v0, 28
    ctx->r10 = S32(ctx->r2 << 28);
    // 0x800EA6A8: sll         $t0, $v0, 30
    ctx->r8 = S32(ctx->r2 << 30);
    // 0x800EA6AC: bgezl       $t0, L_800EA9E4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800EA6B0: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_800EA9E4;
    }
    goto skip_0;
    // 0x800EA6B0: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    skip_0:
    // 0x800EA6B4: jal         0x80088C88
    // 0x800EA6B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    _gsproplookup_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x800EA6B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x800EA6BC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800EA6C0: jal         0x800BFC54
    // 0x800EA6C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BFC54(rdram, ctx);
        goto after_3;
    // 0x800EA6C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800EA6C8: bne         $v0, $zero, L_800EA6F0
    if (ctx->r2 != 0) {
        // 0x800EA6CC: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800EA6F0;
    }
    // 0x800EA6CC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800EA6D0: jal         0x800CB854
    // 0x800EA6D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_4;
    // 0x800EA6D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800EA6D8: bnel        $v0, $fp, L_800EA9E4
    if (ctx->r2 != ctx->r30) {
        // 0x800EA6DC: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_800EA9E4;
    }
    goto skip_1;
    // 0x800EA6DC: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    skip_1:
    // 0x800EA6E0: jal         0x800BFC34
    // 0x800EA6E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BFC34(rdram, ctx);
        goto after_5;
    // 0x800EA6E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800EA6E8: beq         $v0, $zero, L_800EA9E0
    if (ctx->r2 == 0) {
        // 0x800EA6EC: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800EA9E0;
    }
    // 0x800EA6EC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800EA6F0:
    // 0x800EA6F0: jal         0x800B2720
    // 0x800EA6F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800B2720(rdram, ctx);
        goto after_6;
    // 0x800EA6F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x800EA6F8: beq         $v0, $zero, L_800EA840
    if (ctx->r2 == 0) {
        // 0x800EA6FC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800EA840;
    }
    // 0x800EA6FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EA700: lh          $t4, 0x4($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X4);
    // 0x800EA704: lbu         $t2, 0xB($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0XB);
    // 0x800EA708: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EA70C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800EA710: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x800EA714: sb          $t3, 0xB($s4)
    MEM_B(0XB, ctx->r20) = ctx->r11;
    // 0x800EA718: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EA71C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EA720: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x800EA724: lh          $t5, 0x6($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X6);
    // 0x800EA728: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800EA72C: nop

    // 0x800EA730: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EA734: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x800EA738: lh          $t6, 0x8($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X8);
    // 0x800EA73C: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x800EA740: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800EA744: nop

    // 0x800EA748: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EA74C: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x800EA750: lbu         $t7, 0x2($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X2);
    // 0x800EA754: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800EA758: bgez        $t7, L_800EA76C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800EA75C: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800EA76C;
    }
    // 0x800EA75C: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EA760: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EA764: nop

    // 0x800EA768: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_800EA76C:
    // 0x800EA76C: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800EA770: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EA774: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x800EA778: lbu         $t8, 0x3($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X3);
    // 0x800EA77C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800EA780: bgez        $t8, L_800EA794
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800EA784: cvt.s.w     $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800EA794;
    }
    // 0x800EA784: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EA788: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800EA78C: nop

    // 0x800EA790: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_800EA794:
    // 0x800EA794: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800EA798: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EA79C: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    // 0x800EA7A0: lbu         $t9, 0xA($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0XA);
    // 0x800EA7A4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800EA7A8: bgez        $t9, L_800EA7BC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800EA7AC: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800EA7BC;
    }
    // 0x800EA7AC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EA7B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800EA7B4: nop

    // 0x800EA7B8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800EA7BC:
    // 0x800EA7BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EA7C0: lwc1        $f16, 0x5E50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5E50);
    // 0x800EA7C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800EA7C8: mul.s       $f20, $f8, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800EA7CC: jal         0x800B2840
    // 0x800EA7D0: nop

    func_800B2840(rdram, ctx);
        goto after_7;
    // 0x800EA7D0: nop

    after_7:
    // 0x800EA7D4: jal         0x800B2354
    // 0x800EA7D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2354(rdram, ctx);
        goto after_8;
    // 0x800EA7D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x800EA7DC: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800EA7E0: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x800EA7E4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800EA7E8: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x800EA7EC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800EA7F0: jal         0x800AAEF4
    // 0x800EA7F4: nop

    func_800AAEF4(rdram, ctx);
        goto after_9;
    // 0x800EA7F4: nop

    after_9:
    // 0x800EA7F8: beq         $v0, $zero, L_800EA840
    if (ctx->r2 == 0) {
        // 0x800EA7FC: nop
    
            goto L_800EA840;
    }
    // 0x800EA7FC: nop

    // 0x800EA800: jal         0x800B2840
    // 0x800EA804: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800B2840(rdram, ctx);
        goto after_10;
    // 0x800EA804: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x800EA808: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x800EA80C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EA810: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800EA814: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x800EA818: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    // 0x800EA81C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800EA820: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x800EA824: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x800EA828: sw          $s7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r23;
    // 0x800EA82C: jal         0x800AB868
    // 0x800EA830: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_800AB868(rdram, ctx);
        goto after_11;
    // 0x800EA830: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_11:
    // 0x800EA834: beq         $v0, $zero, L_800EA840
    if (ctx->r2 == 0) {
        // 0x800EA838: nop
    
            goto L_800EA840;
    }
    // 0x800EA838: nop

    // 0x800EA83C: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
L_800EA840:
    // 0x800EA840: beql        $s2, $zero, L_800EA9E4
    if (ctx->r18 == 0) {
        // 0x800EA844: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_800EA9E4;
    }
    goto skip_2;
    // 0x800EA844: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    skip_2:
    // 0x800EA848: jal         0x800BFC74
    // 0x800EA84C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BFC74(rdram, ctx);
        goto after_12;
    // 0x800EA84C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800EA850: b           L_800EA9E4
    // 0x800EA854: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
        goto L_800EA9E4;
    // 0x800EA854: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
L_800EA858:
    // 0x800EA858: bgez        $t2, L_800EA9E0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800EA85C: lw          $s3, 0x0($s4)
        ctx->r19 = MEM_W(ctx->r20, 0X0);
            goto L_800EA9E0;
    }
    // 0x800EA85C: lw          $s3, 0x0($s4)
    ctx->r19 = MEM_W(ctx->r20, 0X0);
    // 0x800EA860: lhu         $t3, 0x18($s3)
    ctx->r11 = MEM_HU(ctx->r19, 0X18);
    // 0x800EA864: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800EA868: beql        $t4, $zero, L_800EA9E4
    if (ctx->r12 == 0) {
        // 0x800EA86C: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_800EA9E4;
    }
    goto skip_3;
    // 0x800EA86C: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    skip_3:
    // 0x800EA870: lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC);
    // 0x800EA874: beq         $v0, $zero, L_800EA8BC
    if (ctx->r2 == 0) {
        // 0x800EA878: nop
    
            goto L_800EA8BC;
    }
    // 0x800EA878: nop

    // 0x800EA87C: jalr        $v0
    // 0x800EA880: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_13;
    // 0x800EA880: nop

    after_13:
    // 0x800EA884: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800EA888: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800EA88C: beq         $t5, $zero, L_800EA8BC
    if (ctx->r13 == 0) {
        // 0x800EA890: nop
    
            goto L_800EA8BC;
    }
    // 0x800EA890: nop

    // 0x800EA894: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x800EA898: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800EA89C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800EA8A0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800EA8A4: jalr        $t9
    // 0x800EA8A8: lw          $a3, 0xCC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XCC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x800EA8A8: lw          $a3, 0xCC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XCC);
    after_14:
    // 0x800EA8AC: beql        $v0, $zero, L_800EA9E4
    if (ctx->r2 == 0) {
        // 0x800EA8B0: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_800EA9E4;
    }
    goto skip_4;
    // 0x800EA8B0: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    skip_4:
    // 0x800EA8B4: b           L_800EA9E0
    // 0x800EA8B8: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
        goto L_800EA9E0;
    // 0x800EA8B8: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
L_800EA8BC:
    // 0x800EA8BC: jal         0x80106790
    // 0x800EA8C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80106790(rdram, ctx);
        goto after_15;
    // 0x800EA8C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_15:
    // 0x800EA8C4: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x800EA8C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800EA8CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800EA8D0: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x800EA8D4: bltz        $t8, L_800EA9E0
    if (SIGNED(ctx->r24) < 0) {
        // 0x800EA8D8: or          $a1, $s6, $zero
        ctx->r5 = ctx->r22 | 0;
            goto L_800EA9E0;
    }
    // 0x800EA8D8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800EA8DC: jal         0x800EB350
    // 0x800EA8E0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800EB350(rdram, ctx);
        goto after_16;
    // 0x800EA8E0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_16:
    // 0x800EA8E4: bnel        $v0, $zero, L_800EA9E4
    if (ctx->r2 != 0) {
        // 0x800EA8E8: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_800EA9E4;
    }
    goto skip_5;
    // 0x800EA8E8: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    skip_5:
    // 0x800EA8EC: jal         0x800CB854
    // 0x800EA8F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_17;
    // 0x800EA8F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x800EA8F4: bne         $v0, $fp, L_800EA904
    if (ctx->r2 != ctx->r30) {
        // 0x800EA8F8: nop
    
            goto L_800EA904;
    }
    // 0x800EA8F8: nop

    // 0x800EA8FC: jal         0x80103508
    // 0x800EA900: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80103508(rdram, ctx);
        goto after_18;
    // 0x800EA900: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
L_800EA904:
    // 0x800EA904: jal         0x80103AA0
    // 0x800EA908: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80103AA0(rdram, ctx);
        goto after_19;
    // 0x800EA908: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_19:
    // 0x800EA90C: beq         $v0, $zero, L_800EA9E0
    if (ctx->r2 == 0) {
        // 0x800EA910: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800EA9E0;
    }
    // 0x800EA910: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800EA914: jal         0x800B2720
    // 0x800EA918: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2720(rdram, ctx);
        goto after_20;
    // 0x800EA918: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x800EA91C: beq         $v0, $zero, L_800EA9D0
    if (ctx->r2 == 0) {
        // 0x800EA920: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800EA9D0;
    }
    // 0x800EA920: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EA924: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EA928: jal         0x80103CDC
    // 0x800EA92C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80103CDC(rdram, ctx);
        goto after_21;
    // 0x800EA92C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_21:
    // 0x800EA930: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x800EA934: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x800EA938: sw          $s7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r23;
    // 0x800EA93C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x800EA940: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x800EA944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EA948: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800EA94C: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    // 0x800EA950: addiu       $a3, $s1, 0x44
    ctx->r7 = ADD32(ctx->r17, 0X44);
    // 0x800EA954: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800EA958: jal         0x800AB868
    // 0x800EA95C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_800AB868(rdram, ctx);
        goto after_22;
    // 0x800EA95C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_22:
    // 0x800EA960: beq         $v0, $zero, L_800EA988
    if (ctx->r2 == 0) {
        // 0x800EA964: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800EA988;
    }
    // 0x800EA964: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EA968: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EA96C: lw          $v0, 0x2DD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2DD0);
    // 0x800EA970: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800EA974: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800EA978: beq         $v0, $zero, L_800EA988
    if (ctx->r2 == 0) {
        // 0x800EA97C: nop
    
            goto L_800EA988;
    }
    // 0x800EA97C: nop

    // 0x800EA980: jalr        $v0
    // 0x800EA984: lw          $a1, 0x2DD4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2DD4);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_23;
    // 0x800EA984: lw          $a1, 0x2DD4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2DD4);
    after_23:
L_800EA988:
    // 0x800EA988: beq         $s0, $zero, L_800EA9C4
    if (ctx->r16 == 0) {
        // 0x800EA98C: nop
    
            goto L_800EA9C4;
    }
    // 0x800EA98C: nop

    // 0x800EA990: jal         0x800CB854
    // 0x800EA994: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_800CB854(rdram, ctx);
        goto after_24;
    // 0x800EA994: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_24:
    // 0x800EA998: bne         $v0, $fp, L_800EA9C4
    if (ctx->r2 != ctx->r30) {
        // 0x800EA99C: nop
    
            goto L_800EA9C4;
    }
    // 0x800EA99C: nop

    // 0x800EA9A0: jal         0x801039E4
    // 0x800EA9A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_801039E4(rdram, ctx);
        goto after_25;
    // 0x800EA9A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_25:
    // 0x800EA9A8: lhu         $t1, 0x80($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X80);
    // 0x800EA9AC: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800EA9B0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800EA9B4: beq         $t1, $zero, L_800EA9C4
    if (ctx->r9 == 0) {
        // 0x800EA9B8: or          $a2, $s5, $zero
        ctx->r6 = ctx->r21 | 0;
            goto L_800EA9C4;
    }
    // 0x800EA9B8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800EA9BC: jal         0x800EA400
    // 0x800EA9C0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800EA400(rdram, ctx);
        goto after_26;
    // 0x800EA9C0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_26:
L_800EA9C4:
    // 0x800EA9C4: beq         $s0, $zero, L_800EA9D0
    if (ctx->r16 == 0) {
        // 0x800EA9C8: nop
    
            goto L_800EA9D0;
    }
    // 0x800EA9C8: nop

    // 0x800EA9CC: sw          $s0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r16;
L_800EA9D0:
    // 0x800EA9D0: beql        $s2, $zero, L_800EA9E4
    if (ctx->r18 == 0) {
        // 0x800EA9D4: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_800EA9E4;
    }
    goto skip_6;
    // 0x800EA9D4: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    skip_6:
    // 0x800EA9D8: jal         0x800D62E4
    // 0x800EA9DC: lhu         $a0, 0x14($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X14);
    func_800D62E4(rdram, ctx);
        goto after_27;
    // 0x800EA9DC: lhu         $a0, 0x14($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X14);
    after_27:
L_800EA9E0:
    // 0x800EA9E0: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
L_800EA9E4:
    // 0x800EA9E4: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x800EA9E8: sltu        $at, $s4, $t2
    ctx->r1 = ctx->r20 < ctx->r10 ? 1 : 0;
    // 0x800EA9EC: bnel        $at, $zero, L_800EA694
    if (ctx->r1 != 0) {
        // 0x800EA9F0: lw          $v0, 0x8($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X8);
            goto L_800EA694;
    }
    goto skip_7;
    // 0x800EA9F0: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    skip_7:
L_800EA9F4:
    // 0x800EA9F4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800EA9F8: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x800EA9FC: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800EAA00: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800EAA04: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800EAA08: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800EAA0C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800EAA10: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800EAA14: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800EAA18: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800EAA1C: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800EAA20: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800EAA24: jr          $ra
    // 0x800EAA28: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800EAA28: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void suegg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800128: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080012C: jal         0x80100094
    // 0x80800130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800134: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800138: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8080013C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800144: jr          $ra
    // 0x80800148: nop

    return;
    // 0x80800148: nop

;}
RECOMP_FUNC void _chloggo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864A8: syscall     329
    recomp_syscall_handler(rdram, ctx, 0x800864A8);
    return;
    // 0x800864AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808001E0_chwaterfallgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001E4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808001E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808001F4: beq         $a1, $at, L_8080021C
    if (ctx->r5 == ctx->r1) {
        // 0x808001F8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080021C;
    }
    // 0x808001F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001FC: addiu       $at, $zero, 0x9D
    ctx->r1 = ADD32(0, 0X9D);
    // 0x80800200: beq         $a1, $at, L_80800278
    if (ctx->r5 == ctx->r1) {
        // 0x80800204: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800278;
    }
    // 0x80800204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800208: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x8080020C: beq         $a1, $at, L_808002AC
    if (ctx->r5 == ctx->r1) {
        // 0x80800210: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002AC;
    }
    // 0x80800210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800214: b           L_808002B8
    // 0x80800218: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_808002B8;
    // 0x80800218: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080021C:
    // 0x8080021C: jal         0x800DA298
    // 0x80800220: addiu       $a0, $zero, 0x503
    ctx->r4 = ADD32(0, 0X503);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800220: addiu       $a0, $zero, 0x503
    ctx->r4 = ADD32(0, 0X503);
    after_0:
    // 0x80800224: beq         $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800228: nop
    
            goto L_80800234;
    }
    // 0x80800228: nop

    // 0x8080022C: b           L_808002C4
    // 0x80800230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002C4;
    // 0x80800230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800234:
    // 0x80800234: jal         0x800CEAA8
    // 0x80800238: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_1;
    // 0x80800238: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8080023C: beq         $v0, $zero, L_80800264
    if (ctx->r2 == 0) {
        // 0x80800240: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800264;
    }
    // 0x80800240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800244: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    // 0x80800248: jal         0x800CE8D8
    // 0x8080024C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    func_800CE8D8(rdram, ctx);
        goto after_2;
    // 0x8080024C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_2:
    // 0x80800250: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800254: addiu       $a1, $a1, 0x7018
    ctx->r5 = ADD32(ctx->r5, 0X7018);
    // 0x80800258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080025C: jal         0x800CE928
    // 0x80800260: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE928(rdram, ctx);
        goto after_3;
    // 0x80800260: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_80800264:
    // 0x80800264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: jal         0x80103110
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800270: b           L_808002B8
    // 0x80800274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_808002B8;
    // 0x80800274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800278:
    // 0x80800278: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    // 0x8080027C: jal         0x800CE8D8
    // 0x80800280: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    func_800CE8D8(rdram, ctx);
        goto after_5;
    // 0x80800280: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_5:
    // 0x80800284: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800288: addiu       $a1, $a1, 0x7018
    ctx->r5 = ADD32(ctx->r5, 0X7018);
    // 0x8080028C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800290: jal         0x800CE928
    // 0x80800294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE928(rdram, ctx);
        goto after_6;
    // 0x80800294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080029C: jal         0x800CE88C
    // 0x808002A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_7;
    // 0x808002A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808002A4: b           L_808002B8
    // 0x808002A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_808002B8;
    // 0x808002A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808002AC:
    // 0x808002AC: jal         0x80103110
    // 0x808002B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_8;
    // 0x808002B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808002B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808002B8:
    // 0x808002B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808002BC: jal         0x80086248
    // 0x808002C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808002C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_9:
L_808002C4:
    // 0x808002C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002CC: jr          $ra
    // 0x808002D0: nop

    return;
    // 0x808002D0: nop

;}
RECOMP_FUNC void cadbmgrDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002CC: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x808002D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002D8: addu        $t0, $a0, $t6
    ctx->r8 = ADD32(ctx->r4, ctx->r14);
    // 0x808002DC: lbu         $t7, 0x3C($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X3C);
    // 0x808002E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808002E4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808002E8: beq         $t7, $zero, L_808002F8
    if (ctx->r15 == 0) {
        // 0x808002EC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808002F8;
    }
    // 0x808002EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808002F0: b           L_808003C4
    // 0x808002F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003C4;
    // 0x808002F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002F8:
    // 0x808002F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808002FC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800300: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80800304: jal         0x808004C4
    // 0x80800308: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_808004C4_cadbmgrDll(rdram, ctx);
        goto after_0;
    // 0x80800308: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x8080030C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800310: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800314: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80800318: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800320: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80800324: blez        $a2, L_80800360
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800328: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_80800360;
    }
    // 0x80800328: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_8080032C:
    // 0x8080032C: lbu         $t8, 0x3C($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3C);
    // 0x80800330: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800334: bnel        $s0, $t8, L_80800358
    if (ctx->r16 != ctx->r24) {
        // 0x80800338: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80800358;
    }
    goto skip_0;
    // 0x80800338: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x8080033C: lbu         $a0, 0x3D($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X3D);
    // 0x80800340: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800344: bne         $at, $zero, L_80800354
    if (ctx->r1 != 0) {
        // 0x80800348: addiu       $t9, $a0, 0x1
        ctx->r25 = ADD32(ctx->r4, 0X1);
            goto L_80800354;
    }
    // 0x80800348: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x8080034C: sb          $t9, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = ctx->r25;
    // 0x80800350: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
L_80800354:
    // 0x80800354: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_80800358:
    // 0x80800358: bne         $at, $zero, L_8080032C
    if (ctx->r1 != 0) {
        // 0x8080035C: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8080032C;
    }
    // 0x8080035C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_80800360:
    // 0x80800360: sb          $s0, 0x3C($t0)
    MEM_B(0X3C, ctx->r8) = ctx->r16;
    // 0x80800364: sb          $t1, 0x3D($t0)
    MEM_B(0X3D, ctx->r8) = ctx->r9;
    // 0x80800368: addu        $v1, $a3, $t2
    ctx->r3 = ADD32(ctx->r7, ctx->r10);
    // 0x8080036C: lw          $a2, -0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, -0X4);
    // 0x80800370: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80800374: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80800378: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8080037C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800380: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800384: jal         0x808003D8
    // 0x80800388: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    func_808003D8_cadbmgrDll(rdram, ctx);
        goto after_1;
    // 0x80800388: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_1:
    // 0x8080038C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800390: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800394: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800398: lw          $t3, -0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, -0X4);
    // 0x8080039C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808003A0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x808003A4: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808003A8: beq         $at, $zero, L_808003B8
    if (ctx->r1 == 0) {
        // 0x808003AC: nop
    
            goto L_808003B8;
    }
    // 0x808003AC: nop

    // 0x808003B0: jal         0x80800528
    // 0x808003B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800528_cadbmgrDll(rdram, ctx);
        goto after_2;
    // 0x808003B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
L_808003B8:
    // 0x808003B8: jal         0x808000F4
    // 0x808003BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808000F4_cadbmgrDll(rdram, ctx);
        goto after_3;
    // 0x808003BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C4:
    // 0x808003C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003D0: jr          $ra
    // 0x808003D4: nop

    return;
    // 0x808003D4: nop

;}
RECOMP_FUNC void func_8009BD38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BD38: lw          $t6, 0xD4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD4);
    // 0x8009BD3C: jr          $ra
    // 0x8009BD40: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    return;
    // 0x8009BD40: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _bskazstilt_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083670: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083670);
    return;
    // 0x80083674: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _ncpod_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894D0: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800894D0);
    return;
    // 0x800894D4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chhillbilly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C90: syscall     218
    recomp_syscall_handler(rdram, ctx, 0x80085C90);
    return;
    // 0x80085C94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void mlMtxScale_xyz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019D30: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80019D34: addiu       $t0, $t0, -0x4350
    ctx->r8 = ADD32(ctx->r8, -0X4350);
    // 0x80019D38: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80019D3C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80019D40: addiu       $v1, $v0, 0xC
    ctx->r3 = ADD32(ctx->r2, 0XC);
L_80019D44:
    // 0x80019D44: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80019D48: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80019D4C: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80019D50: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80019D54: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80019D58: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80019D5C: mul.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80019D60: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x80019D64: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80019D68: bne         $v0, $v1, L_80019D44
    if (ctx->r2 != ctx->r3) {
        // 0x80019D6C: swc1        $f4, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
            goto L_80019D44;
    }
    // 0x80019D6C: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x80019D70: jr          $ra
    // 0x80019D74: nop

    return;
    // 0x80019D74: nop

;}
RECOMP_FUNC void fxripple_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C8: jal         0x80800094
    // 0x808001CC: nop

    func_80800094_fxripple(rdram, ctx);
        goto after_0;
    // 0x808001CC: nop

    after_0:
    // 0x808001D0: beq         $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808001D4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001E0;
    }
    // 0x808001D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001D8: jal         0x800BA22C
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_1;
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_808001E0:
    // 0x808001E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001E8: jr          $ra
    // 0x808001EC: nop

    return;
    // 0x808001EC: nop

;}
RECOMP_FUNC void func_800C72C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C72C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C72C4: addiu       $v0, $v0, -0x56FC
    ctx->r2 = ADD32(ctx->r2, -0X56FC);
    // 0x800C72C8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800C72CC: beq         $t6, $zero, L_800C72DC
    if (ctx->r14 == 0) {
        // 0x800C72D0: nop
    
            goto L_800C72DC;
    }
    // 0x800C72D0: nop

    // 0x800C72D4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800C72D8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800C72DC:
    // 0x800C72DC: jr          $ra
    // 0x800C72E0: nop

    return;
    // 0x800C72E0: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839D0: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x800839D0);
    return;
    // 0x800839D4: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_808015A4_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808015A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808015AC: jal         0x80801458
    // 0x808015B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80801458_chevilspirit(rdram, ctx);
        goto after_0;
    // 0x808015B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808015B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808015B8: jal         0x808015E0
    // 0x808015BC: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_808015E0_chevilspirit(rdram, ctx);
        goto after_1;
    // 0x808015BC: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_1:
    // 0x808015C0: beq         $v0, $zero, L_808015D0
    if (ctx->r2 == 0) {
        // 0x808015C4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808015D0;
    }
    // 0x808015C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808015C8: jal         0x80102424
    // 0x808015CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808015CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
L_808015D0:
    // 0x808015D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808015D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808015D8: jr          $ra
    // 0x808015DC: nop

    return;
    // 0x808015DC: nop

;}
RECOMP_FUNC void func_8080006C_chterryteeth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800070: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800078: beq         $a1, $at, L_80800094
    if (ctx->r5 == ctx->r1) {
        // 0x8080007C: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800094;
    }
    // 0x8080007C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800080: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800084: beq         $a1, $at, L_808000A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800088: nop
    
            goto L_808000A8;
    }
    // 0x80800088: nop

    // 0x8080008C: b           L_8080012C
    // 0x80800090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080012C;
    // 0x80800090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800094:
    // 0x80800094: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800098: jal         0x80086670
    // 0x8080009C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080009C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x808000A0: b           L_8080012C
    // 0x808000A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080012C;
    // 0x808000A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000A8:
    // 0x808000A8: jal         0x80101080
    // 0x808000AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_1;
    // 0x808000AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x808000B0: jal         0x80106790
    // 0x808000B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x808000B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808000B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808000BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000C0: jal         0x800866C0
    // 0x808000C4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x808000C4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x808000C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808000CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808000D0: jal         0x800866D0
    // 0x808000D4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_4;
    // 0x808000D4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x808000D8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808000DC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2008, 0X150) << 16);
    // 0x808000E0: addiu       $t6, $t6, 0x150
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2008, 0X150));
    // 0x808000E4: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x808000E8: lw          $a3, 0x38($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X38);
    // 0x808000EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000F4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808000F8: jal         0x800BABB8
    // 0x808000FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x808000FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80800100: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2008, 0X190) << 16);
    // 0x80800104: addiu       $a1, $a1, 0x190
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2008, 0X190));
    // 0x80800108: jal         0x800C4AF0
    // 0x8080010C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800C4AF0(rdram, ctx);
        goto after_6;
    // 0x8080010C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800110: jal         0x800DA544
    // 0x80800114: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x80800114: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    after_7:
    // 0x80800118: b           L_8080012C
    // 0x8080011C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080012C;
    // 0x8080011C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800120: b           L_8080012C
    // 0x80800124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080012C;
    // 0x80800124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080012C:
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800130: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

;}
RECOMP_FUNC void _gcegg_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883E0: syscall     680
    recomp_syscall_handler(rdram, ctx, 0x800883E0);
    return;
    // 0x800883E4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085628: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085628);
    return;
    // 0x8008562C: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_808009FC_chlagoonfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800A08: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x80800A0C: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x80800A10: srl         $t7, $a1, 26
    ctx->r15 = S32(U32(ctx->r5) >> 26);
    // 0x80800A14: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80800A18: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80800A1C: jal         0x800CC63C
    // 0x80800A20: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_0;
    // 0x80800A20: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    after_0:
    // 0x80800A24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800A2C: jal         0x800EE7F8
    // 0x80800A30: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800A30: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_1:
    // 0x80800A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A3C: jr          $ra
    // 0x80800A40: nop

    return;
    // 0x80800A40: nop

;}
RECOMP_FUNC void func_8080003C_chbeanstalkseed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800040: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2356, 0XBE0) << 16);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080004C: addiu       $t6, $t6, 0xBE0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2356, 0XBE0));
    // 0x80800050: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80800054: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800058: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2356, 0XBF4) << 16);
    // 0x8080005C: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80800060: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80800064: addiu       $t1, $t1, 0xBF4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2356, 0XBF4));
    // 0x80800068: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x8080006C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80800070: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80800074: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80800078: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x8080007C: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x80800080: lw          $at, 0x10($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X10);
    // 0x80800084: sw          $at, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r1;
    // 0x80800088: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8080008C: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x80800090: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80800094: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80800098: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x8080009C: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x808000A0: jal         0x80101E4C
    // 0x808000A4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80101E4C(rdram, ctx);
        goto after_0;
    // 0x808000A4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x808000A8: beq         $v0, $zero, L_80800184
    if (ctx->r2 == 0) {
        // 0x808000AC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800184;
    }
    // 0x808000AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808000B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XB80) << 16);
    // 0x808000B4: lwc1        $f12, 0xB80($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XB80));
    // 0x808000B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XB84) << 16);
    // 0x808000BC: jal         0x800DC178
    // 0x808000C0: lwc1        $f14, 0xB84($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XB84));
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808000C0: lwc1        $f14, 0xB84($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XB84));
    after_1:
    // 0x808000C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XB88) << 16);
    // 0x808000C8: lwc1        $f4, 0xB88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XB88));
    // 0x808000CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808000D0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808000D4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808000D8: lui         $a2, 0x3E8
    ctx->r6 = S32(0X3E8 << 16);
    // 0x808000DC: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808000E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808000E4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808000E8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x808000EC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808000F0: nop

    // 0x808000F4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808000F8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808000FC: nop

    // 0x80800100: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800104: beql        $a0, $zero, L_80800154
    if (ctx->r4 == 0) {
        // 0x80800108: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80800154;
    }
    goto skip_0;
    // 0x80800108: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x8080010C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800110: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800114: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800118: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8080011C: nop

    // 0x80800120: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800124: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800128: nop

    // 0x8080012C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800130: bne         $a0, $zero, L_80800148
    if (ctx->r4 != 0) {
        // 0x80800134: nop
    
            goto L_80800148;
    }
    // 0x80800134: nop

    // 0x80800138: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8080013C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800140: b           L_80800160
    // 0x80800144: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800160;
    // 0x80800144: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800148:
    // 0x80800148: b           L_80800160
    // 0x8080014C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800160;
    // 0x8080014C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800150: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80800154:
    // 0x80800154: nop

    // 0x80800158: bltz        $a0, L_80800148
    if (SIGNED(ctx->r4) < 0) {
        // 0x8080015C: nop
    
            goto L_80800148;
    }
    // 0x8080015C: nop

L_80800160:
    // 0x80800160: or          $t8, $a0, $zero
    ctx->r24 = ctx->r4 | 0;
    // 0x80800164: lui         $at, 0xD
    ctx->r1 = S32(0XD << 16);
    // 0x80800168: ori         $at, $at, 0xABF0
    ctx->r1 = ctx->r1 | 0XABF0;
    // 0x8080016C: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x80800170: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800174: jal         0x800C4140
    // 0x80800178: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_2;
    // 0x80800178: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    after_2:
    // 0x8080017C: b           L_80800260
    // 0x80800180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800260;
    // 0x80800180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800184:
    // 0x80800184: jal         0x80101E4C
    // 0x80800188: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_80101E4C(rdram, ctx);
        goto after_3;
    // 0x80800188: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x8080018C: beq         $v0, $zero, L_8080025C
    if (ctx->r2 == 0) {
        // 0x80800190: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2356, 0XB8C) << 16);
            goto L_8080025C;
    }
    // 0x80800190: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XB8C) << 16);
    // 0x80800194: lwc1        $f12, 0xB8C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XB8C));
    // 0x80800198: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XB90) << 16);
    // 0x8080019C: jal         0x800DC178
    // 0x808001A0: lwc1        $f14, 0xB90($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XB90));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808001A0: lwc1        $f14, 0xB90($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XB90));
    after_4:
    // 0x808001A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XB94) << 16);
    // 0x808001A8: lwc1        $f10, 0xB94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XB94));
    // 0x808001AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808001B0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808001B4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808001B8: lui         $a2, 0x3E8
    ctx->r6 = S32(0X3E8 << 16);
    // 0x808001BC: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808001C0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808001C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808001C8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808001CC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808001D0: nop

    // 0x808001D4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808001D8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808001DC: nop

    // 0x808001E0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808001E4: beql        $a0, $zero, L_80800234
    if (ctx->r4 == 0) {
        // 0x808001E8: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80800234;
    }
    goto skip_1;
    // 0x808001E8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x808001EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808001F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808001F4: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808001F8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808001FC: nop

    // 0x80800200: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80800204: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800208: nop

    // 0x8080020C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800210: bne         $a0, $zero, L_80800228
    if (ctx->r4 != 0) {
        // 0x80800214: nop
    
            goto L_80800228;
    }
    // 0x80800214: nop

    // 0x80800218: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8080021C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800220: b           L_80800240
    // 0x80800224: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800240;
    // 0x80800224: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800228:
    // 0x80800228: b           L_80800240
    // 0x8080022C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800240;
    // 0x8080022C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800230: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80800234:
    // 0x80800234: nop

    // 0x80800238: bltz        $a0, L_80800228
    if (SIGNED(ctx->r4) < 0) {
        // 0x8080023C: nop
    
            goto L_80800228;
    }
    // 0x8080023C: nop

L_80800240:
    // 0x80800240: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x80800244: lui         $at, 0xD
    ctx->r1 = S32(0XD << 16);
    // 0x80800248: ori         $at, $at, 0xACD5
    ctx->r1 = ctx->r1 | 0XACD5;
    // 0x8080024C: sll         $t3, $t9, 21
    ctx->r11 = S32(ctx->r25 << 21);
    // 0x80800250: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800254: jal         0x800C4140
    // 0x80800258: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_5;
    // 0x80800258: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    after_5:
L_8080025C:
    // 0x8080025C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800260:
    // 0x80800260: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800264: jr          $ra
    // 0x80800268: nop

    return;
    // 0x80800268: nop

;}
RECOMP_FUNC void chpotogoldgame_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808022B8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2336, 0X2578) << 16);
    // 0x808022BC: jr          $ra
    // 0x808022C0: addiu       $v0, $v0, 0x2578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2336, 0X2578));
    return;
    // 0x808022C0: addiu       $v0, $v0, 0x2578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2336, 0X2578));
    // 0x808022C4: nop

    // 0x808022C8: nop

    // 0x808022CC: nop

;}
RECOMP_FUNC void func_8080000C_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x800EB854
    // 0x8080001C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EB854(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800020: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800024: bne         $v0, $at, L_8080004C
    if (ctx->r2 != ctx->r1) {
        // 0x80800028: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080004C;
    }
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080002C: jal         0x80100094
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800034: beq         $v0, $zero, L_80800054
    if (ctx->r2 == 0) {
        // 0x80800038: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800054;
    }
    // 0x80800038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080003C: jal         0x80087CA0
    // 0x80800040: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800040: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800044: b           L_80800058
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800058;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080004C:
    // 0x8080004C: jal         0x80101870
    // 0x80800050: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_3;
    // 0x80800050: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_80800054:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_808001D4_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001DC: jal         0x8009EF1C
    // 0x808001E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x808001E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001E4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x808001E8: jal         0x8009EF10
    // 0x808001EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x808001EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808001F0: bne         $v0, $zero, L_8080020C
    if (ctx->r2 != 0) {
        // 0x808001F4: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8080020C;
    }
    // 0x808001F4: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808001F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001FC: jal         0x8009B9B0
    // 0x80800200: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800200: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800204: b           L_8080022C
    // 0x80800208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080022C;
    // 0x80800208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080020C:
    // 0x8080020C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800210: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800214: jal         0x800F1214
    // 0x80800218: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800218: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    after_3:
    // 0x8080021C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800220: jal         0x8009B9B0
    // 0x80800224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080022C:
    // 0x8080022C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800230: jr          $ra
    // 0x80800234: nop

    return;
    // 0x80800234: nop

;}
RECOMP_FUNC void func_80800068_bskazcrouch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: lui         $a3, 0x3F7F
    ctx->r7 = S32(0X3F7F << 16);
    // 0x80800074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800078: ori         $a3, $a3, 0xF972
    ctx->r7 = ctx->r7 | 0XF972;
    // 0x8080007C: addiu       $a1, $zero, 0x28F
    ctx->r5 = ADD32(0, 0X28F);
    // 0x80800080: jal         0x8008CD30
    // 0x80800084: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    baanim_playForDuration_onceSmoothStartingAt(rdram, ctx);
        goto after_0;
    // 0x80800084: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80800088: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800090: jal         0x80085338
    // 0x80800094: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    _batimer_set(rdram, ctx);
        goto after_1;
    // 0x80800094: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_1:
    // 0x80800098: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000A0: sw          $t6, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = ctx->r14;
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void bakey_releaseCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800919AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800919B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800919B4: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800919B8: jal         0x800BCEC0
    // 0x800919BC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BCEC0(rdram, ctx);
        goto after_0;
    // 0x800919BC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800919C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800919C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800919C8: jr          $ra
    // 0x800919CC: nop

    return;
    // 0x800919CC: nop

;}
RECOMP_FUNC void func_800DF580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF580: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DF584: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF588: sw          $t6, -0x37C4($at)
    MEM_W(-0X37C4, ctx->r1) = ctx->r14;
    // 0x800DF58C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800DF590: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF594: addiu       $v0, $v0, -0x3678
    ctx->r2 = ADD32(ctx->r2, -0X3678);
    // 0x800DF598: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x800DF59C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x800DF5A0: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
    // 0x800DF5A4: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800DF5A8: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x800DF5AC: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x800DF5B0: sw          $t0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r8;
    // 0x800DF5B4: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800DF5B8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800DF5BC: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x800DF5C0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800DF5C4: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x800DF5C8: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x800DF5CC: lw          $t4, 0xC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XC);
    // 0x800DF5D0: jr          $ra
    // 0x800DF5D4: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    return;
    // 0x800DF5D4: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
;}
RECOMP_FUNC void bainput_func_80097D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097D30: jal         0x800F424C
    // 0x80097D34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F424C(rdram, ctx);
        goto after_0;
    // 0x80097D34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80097D38: bne         $v0, $zero, L_80097D48
    if (ctx->r2 != 0) {
        // 0x80097D3C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80097D48;
    }
    // 0x80097D3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80097D40: b           L_80097D8C
    // 0x80097D44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097D8C;
    // 0x80097D44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097D48:
    // 0x80097D48: jal         0x80098024
    // 0x80097D4C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    bainput_isEnabled(rdram, ctx);
        goto after_1;
    // 0x80097D4C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80097D50: beq         $v0, $zero, L_80097D60
    if (ctx->r2 == 0) {
        // 0x80097D54: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80097D60;
    }
    // 0x80097D54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80097D58: b           L_80097D8C
    // 0x80097D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097D8C;
    // 0x80097D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097D60:
    // 0x80097D60: jal         0x80091A94
    // 0x80097D64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bakey_newlyReleased(rdram, ctx);
        goto after_2;
    // 0x80097D64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80097D68: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097D6C: beq         $t6, $zero, L_80097D8C
    if (ctx->r14 == 0) {
        // 0x80097D70: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097D8C;
    }
    // 0x80097D70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097D74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80097D78: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80097D7C: jal         0x80091940
    // 0x80097D80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bakey_func_80091940(rdram, ctx);
        goto after_3;
    // 0x80097D80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80097D84: slti        $t7, $v0, 0x7
    ctx->r15 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80097D88: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80097D8C:
    // 0x80097D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097D90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097D94: jr          $ra
    // 0x80097D98: nop

    return;
    // 0x80097D98: nop

;}
RECOMP_FUNC void bsjump_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F40: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800F44: jal         0x800852F0
    // 0x80800F48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x80800F48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800F4C: beq         $v0, $zero, L_80800F64
    if (ctx->r2 == 0) {
        // 0x80800F50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F64;
    }
    // 0x80800F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F54: addiu       $a1, $zero, 0x446
    ctx->r5 = ADD32(0, 0X446);
    // 0x80800F58: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800F5C: jal         0x8009DF18
    // 0x80800F60: addiu       $a3, $zero, 0x7D00
    ctx->r7 = ADD32(0, 0X7D00);
    func_8009DF18(rdram, ctx);
        goto after_1;
    // 0x80800F60: addiu       $a3, $zero, 0x7D00
    ctx->r7 = ADD32(0, 0X7D00);
    after_1:
L_80800F64:
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F68: jal         0x800852F0
    // 0x80800F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x80800F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800F70: jal         0x800841D8
    // 0x80800F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F7C: jal         0x80085330
    // 0x80800F80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_isZero(rdram, ctx);
        goto after_4;
    // 0x80800F80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800F84: beql        $v0, $zero, L_80800FB4
    if (ctx->r2 == 0) {
        // 0x80800F88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FB4;
    }
    goto skip_0;
    // 0x80800F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800F8C: jal         0x8009BFD8
    // 0x80800F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFD8(rdram, ctx);
        goto after_5;
    // 0x80800F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800F94: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800F98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800FA4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800FA8: jal         0x8009BF5C
    // 0x80800FAC: nop

    func_8009BF5C(rdram, ctx);
        goto after_6;
    // 0x80800FAC: nop

    after_6:
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FB4:
    // 0x80800FB4: jal         0x80085328
    // 0x80800FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isNonzero(rdram, ctx);
        goto after_7;
    // 0x80800FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800FBC: beq         $v0, $zero, L_8080103C
    if (ctx->r2 == 0) {
        // 0x80800FC0: nop
    
            goto L_8080103C;
    }
    // 0x80800FC0: nop

    // 0x80800FC4: jal         0x800A3274
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_8;
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800FCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800FD0: beq         $v0, $at, L_80800FE8
    if (ctx->r2 == ctx->r1) {
        // 0x80800FD4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80800FE8;
    }
    // 0x80800FD4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800FD8: beq         $v0, $at, L_80801028
    if (ctx->r2 == ctx->r1) {
        // 0x80800FDC: nop
    
            goto L_80801028;
    }
    // 0x80800FDC: nop

    // 0x80800FE0: b           L_8080103C
    // 0x80800FE4: nop

        goto L_8080103C;
    // 0x80800FE4: nop

L_80800FE8:
    // 0x80800FE8: jal         0x80097DF4
    // 0x80800FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097DF4(rdram, ctx);
        goto after_9;
    // 0x80800FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800FF0: beq         $v0, $zero, L_80800FFC
    if (ctx->r2 == 0) {
        // 0x80800FF4: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_80800FFC;
    }
    // 0x80800FF4: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80800FF8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800FFC:
    // 0x80800FFC: jal         0x80097F08
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097F08(rdram, ctx);
        goto after_10;
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801004: beq         $v0, $zero, L_80801010
    if (ctx->r2 == 0) {
        // 0x80801008: addiu       $t7, $zero, 0x11
        ctx->r15 = ADD32(0, 0X11);
            goto L_80801010;
    }
    // 0x80801008: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x8080100C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80801010:
    // 0x80801010: jal         0x80097A90
    // 0x80801014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_bust(rdram, ctx);
        goto after_11;
    // 0x80801014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801018: beq         $v0, $zero, L_8080103C
    if (ctx->r2 == 0) {
        // 0x8080101C: addiu       $t8, $zero, 0xF
        ctx->r24 = ADD32(0, 0XF);
            goto L_8080103C;
    }
    // 0x8080101C: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80801020: b           L_8080103C
    // 0x80801024: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_8080103C;
    // 0x80801024: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80801028:
    // 0x80801028: jal         0x80097EC8
    // 0x8080102C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097EC8(rdram, ctx);
        goto after_12;
    // 0x8080102C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801030: beq         $v0, $zero, L_8080103C
    if (ctx->r2 == 0) {
        // 0x80801034: addiu       $t9, $zero, 0xE4
        ctx->r25 = ADD32(0, 0XE4);
            goto L_8080103C;
    }
    // 0x80801034: addiu       $t9, $zero, 0xE4
    ctx->r25 = ADD32(0, 0XE4);
    // 0x80801038: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_8080103C:
    // 0x8080103C: jal         0x8008E35C
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_13;
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80801044: beq         $v0, $zero, L_80801050
    if (ctx->r2 == 0) {
        // 0x80801048: addiu       $t0, $zero, 0x4C
        ctx->r8 = ADD32(0, 0X4C);
            goto L_80801050;
    }
    // 0x80801048: addiu       $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
    // 0x8080104C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80801050:
    // 0x80801050: jal         0x8008E078
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_14;
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801058: beq         $v0, $zero, L_80801068
    if (ctx->r2 == 0) {
        // 0x8080105C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801068;
    }
    // 0x8080105C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801060: addiu       $t1, $zero, 0x72
    ctx->r9 = ADD32(0, 0X72);
    // 0x80801064: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80801068:
    // 0x80801068: jal         0x8009E5C8
    // 0x8080106C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x8080106C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x80801070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801074: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080107C: jr          $ra
    // 0x80801080: nop

    return;
    // 0x80801080: nop

;}
RECOMP_FUNC void _idscroll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DB8: syscall     740
    recomp_syscall_handler(rdram, ctx, 0x80088DB8);
    return;
    // 0x80088DBC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800BCC_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BCC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800BD0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1608, 0X50B0) << 16);
    // 0x80800BD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BDC: addiu       $t7, $t7, 0x50B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1608, 0X50B0));
    // 0x80800BE0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800BE4: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80800BE8: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800BEC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800BF0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800BF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BF8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800BFC: bne         $a1, $zero, L_80800C28
    if (ctx->r5 != 0) {
        // 0x80800C00: sw          $at, 0x8($t6)
        MEM_W(0X8, ctx->r14) = ctx->r1;
            goto L_80800C28;
    }
    // 0x80800C00: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800C04: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80800C08: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C0C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800C10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C14: jal         0x800DC178
    // 0x80800C18: nop

    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800C18: nop

    after_0:
    // 0x80800C1C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800C20: b           L_80800C50
    // 0x80800C24: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
        goto L_80800C50;
    // 0x80800C24: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
L_80800C28:
    // 0x80800C28: jal         0x80102D78
    // 0x80800C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x80800C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800C30: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80800C34: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C38: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800C3C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C40: jal         0x800DC178
    // 0x80800C44: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800C44: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800C48: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800C4C: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
L_80800C50:
    // 0x80800C50: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800C54: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800C58: jal         0x800EFCD8
    // 0x80800C5C: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    func_800EFCD8(rdram, ctx);
        goto after_3;
    // 0x80800C5C: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    after_3:
    // 0x80800C60: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800C64: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800C68: jal         0x800EE780
    // 0x80800C6C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800EE780(rdram, ctx);
        goto after_4;
    // 0x80800C6C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80800C70: jal         0x8080009C
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chstoneballcontrol(rdram, ctx);
        goto after_5;
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800C78: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80800C7C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800C80: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800C84: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800C88: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    // 0x80800C8C: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80800C90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800C94: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800C98: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C9C: bc1f        L_80800CA8
    if (!c1cs) {
        // 0x80800CA0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800CA8;
    }
    // 0x80800CA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800CA4: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
L_80800CA8:
    // 0x80800CA8: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800CAC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800CB0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80800CB4: nop

    // 0x80800CB8: bc1fl       L_80800CC8
    if (!c1cs) {
        // 0x80800CBC: lwc1        $f16, 0x18($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
            goto L_80800CC8;
    }
    goto skip_0;
    // 0x80800CBC: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x80800CC0: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x80800CC4: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
L_80800CC8:
    // 0x80800CC8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800CCC: nop

    // 0x80800CD0: bc1fl       L_80800CE0
    if (!c1cs) {
        // 0x80800CD4: lwc1        $f18, 0x20($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
            goto L_80800CE0;
    }
    goto skip_1;
    // 0x80800CD4: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    skip_1:
    // 0x80800CD8: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800CDC: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
L_80800CE0:
    // 0x80800CE0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80800CE4: nop

    // 0x80800CE8: bc1f        L_80800CF4
    if (!c1cs) {
        // 0x80800CEC: nop
    
            goto L_80800CF4;
    }
    // 0x80800CEC: nop

    // 0x80800CF0: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_80800CF4:
    // 0x80800CF4: jal         0x800DC178
    // 0x80800CF8: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800CF8: nop

    after_6:
    // 0x80800CFC: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D04: jal         0x80800B4C
    // 0x80800D08: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_7;
    // 0x80800D08: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_7:
    // 0x80800D0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800D18: jr          $ra
    // 0x80800D1C: nop

    return;
    // 0x80800D1C: nop

;}
RECOMP_FUNC void func_80800A44_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A44: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800A48: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800A4C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800A50: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800A54: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800A58: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800A5C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800A60: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800A64: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800A68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800A6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800A70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A74: jal         0x80100094
    // 0x80800A78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A7C: lbu         $v1, 0xFB($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XFB);
    // 0x80800A80: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1564, 0X3E08) << 16);
    // 0x80800A84: addiu       $t6, $t6, 0x3E08
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1564, 0X3E08));
    // 0x80800A88: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80800A8C: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x80800A90: addu        $s1, $a0, $t6
    ctx->r17 = ADD32(ctx->r4, ctx->r14);
    // 0x80800A94: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80800A98: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800A9C: beql        $t7, $zero, L_80800BE8
    if (ctx->r15 == 0) {
        // 0x80800AA0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80800BE8;
    }
    goto skip_0;
    // 0x80800AA0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80800AA4: lw          $t8, 0x7C($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X7C);
    // 0x80800AA8: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1564, 0X3E18) << 16);
    // 0x80800AAC: addiu       $t0, $t0, 0x3E18
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1564, 0X3E18));
    // 0x80800AB0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80800AB4: beq         $t9, $zero, L_80800BE4
    if (ctx->r25 == 0) {
        // 0x80800AB8: addu        $s5, $a0, $t0
        ctx->r21 = ADD32(ctx->r4, ctx->r8);
            goto L_80800BE4;
    }
    // 0x80800AB8: addu        $s5, $a0, $t0
    ctx->r21 = ADD32(ctx->r4, ctx->r8);
    // 0x80800ABC: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x80800AC0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800AC4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800AC8: blez        $t1, L_80800BE4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80800ACC: addiu       $fp, $zero, 0x3
        ctx->r30 = ADD32(0, 0X3);
            goto L_80800BE4;
    }
    // 0x80800ACC: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x80800AD0: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80800AD4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80800AD8: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
L_80800ADC:
    // 0x80800ADC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AE0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80800AE4: jal         0x80105998
    // 0x80800AE8: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    func_80105998(rdram, ctx);
        goto after_1;
    // 0x80800AE8: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    after_1:
    // 0x80800AEC: beql        $v0, $zero, L_80800BD0
    if (ctx->r2 == 0) {
        // 0x80800AF0: lw          $t8, 0x0($s5)
        ctx->r24 = MEM_W(ctx->r21, 0X0);
            goto L_80800BD0;
    }
    goto skip_1;
    // 0x80800AF0: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    skip_1:
    // 0x80800AF4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80800AF8: addu        $v1, $t4, $s0
    ctx->r3 = ADD32(ctx->r12, ctx->r16);
    // 0x80800AFC: lh          $a0, 0xC($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XC);
    // 0x80800B00: beq         $a0, $s6, L_80800B20
    if (ctx->r4 == ctx->r22) {
        // 0x80800B04: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80800B20;
    }
    // 0x80800B04: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80800B08: beql        $v0, $s7, L_80800B50
    if (ctx->r2 == ctx->r23) {
        // 0x80800B0C: lbu         $t8, 0xFE($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0XFE);
            goto L_80800B50;
    }
    goto skip_2;
    // 0x80800B0C: lbu         $t8, 0xFE($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XFE);
    skip_2:
    // 0x80800B10: beql        $v0, $fp, L_80800B80
    if (ctx->r2 == ctx->r30) {
        // 0x80800B14: lbu         $t1, 0xFE($s2)
        ctx->r9 = MEM_BU(ctx->r18, 0XFE);
            goto L_80800B80;
    }
    goto skip_3;
    // 0x80800B14: lbu         $t1, 0xFE($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XFE);
    skip_3:
    // 0x80800B18: b           L_80800BCC
    // 0x80800B1C: sb          $a0, 0xFF($s2)
    MEM_B(0XFF, ctx->r18) = ctx->r4;
        goto L_80800BCC;
    // 0x80800B1C: sb          $a0, 0xFF($s2)
    MEM_B(0XFF, ctx->r18) = ctx->r4;
L_80800B20:
    // 0x80800B20: lbu         $t5, 0xFE($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XFE);
    // 0x80800B24: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800B28: beql        $t5, $zero, L_80800BCC
    if (ctx->r13 == 0) {
        // 0x80800B2C: sb          $a0, 0xFF($s2)
        MEM_B(0XFF, ctx->r18) = ctx->r4;
            goto L_80800BCC;
    }
    goto skip_4;
    // 0x80800B2C: sb          $a0, 0xFF($s2)
    MEM_B(0XFF, ctx->r18) = ctx->r4;
    skip_4:
    // 0x80800B30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800B34: jal         0x80800968
    // 0x80800B38: lbu         $a1, 0xFB($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XFB);
    func_80800968_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x80800B38: lbu         $a1, 0xFB($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XFB);
    after_2:
    // 0x80800B3C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80800B40: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80800B44: b           L_80800BC8
    // 0x80800B48: lh          $a0, 0xC($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XC);
        goto L_80800BC8;
    // 0x80800B48: lh          $a0, 0xC($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XC);
    // 0x80800B4C: lbu         $t8, 0xFE($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XFE);
L_80800B50:
    // 0x80800B50: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800B54: beql        $t8, $zero, L_80800BCC
    if (ctx->r24 == 0) {
        // 0x80800B58: sb          $a0, 0xFF($s2)
        MEM_B(0XFF, ctx->r18) = ctx->r4;
            goto L_80800BCC;
    }
    goto skip_5;
    // 0x80800B58: sb          $a0, 0xFF($s2)
    MEM_B(0XFF, ctx->r18) = ctx->r4;
    skip_5:
    // 0x80800B5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800B60: lh          $a1, 0xE($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XE);
    // 0x80800B64: jal         0x808008DC
    // 0x80800B68: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    func_808008DC_chclockworkmouse(rdram, ctx);
        goto after_3;
    // 0x80800B68: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    after_3:
    // 0x80800B6C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80800B70: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80800B74: b           L_80800BC8
    // 0x80800B78: lh          $a0, 0xC($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XC);
        goto L_80800BC8;
    // 0x80800B78: lh          $a0, 0xC($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XC);
    // 0x80800B7C: lbu         $t1, 0xFE($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XFE);
L_80800B80:
    // 0x80800B80: beql        $t1, $zero, L_80800BCC
    if (ctx->r9 == 0) {
        // 0x80800B84: sb          $a0, 0xFF($s2)
        MEM_B(0XFF, ctx->r18) = ctx->r4;
            goto L_80800BCC;
    }
    goto skip_6;
    // 0x80800B84: sb          $a0, 0xFF($s2)
    MEM_B(0XFF, ctx->r18) = ctx->r4;
    skip_6:
    // 0x80800B88: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800B8C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800B90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800B94: swc1        $f4, 0x104($s2)
    MEM_W(0X104, ctx->r18) = ctx->f4.u32l;
    // 0x80800B98: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80800B9C: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80800BA0: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80800BA4: swc1        $f6, 0x108($s2)
    MEM_W(0X108, ctx->r18) = ctx->f6.u32l;
    // 0x80800BA8: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80800BAC: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    // 0x80800BB0: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80800BB4: jal         0x80800850
    // 0x80800BB8: lh          $a1, 0xE($t5)
    ctx->r5 = MEM_H(ctx->r13, 0XE);
    func_80800850_chclockworkmouse(rdram, ctx);
        goto after_4;
    // 0x80800BB8: lh          $a1, 0xE($t5)
    ctx->r5 = MEM_H(ctx->r13, 0XE);
    after_4:
    // 0x80800BBC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80800BC0: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80800BC4: lh          $a0, 0xC($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XC);
L_80800BC8:
    // 0x80800BC8: sb          $a0, 0xFF($s2)
    MEM_B(0XFF, ctx->r18) = ctx->r4;
L_80800BCC:
    // 0x80800BCC: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
L_80800BD0:
    // 0x80800BD0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800BD4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800BD8: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800BDC: bnel        $at, $zero, L_80800ADC
    if (ctx->r1 != 0) {
        // 0x80800BE0: lw          $t2, 0x0($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X0);
            goto L_80800ADC;
    }
    goto skip_7;
    // 0x80800BE0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    skip_7:
L_80800BE4:
    // 0x80800BE4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800BE8:
    // 0x80800BE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800BF4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800BF8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800BFC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C00: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800C04: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800C08: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800C0C: jr          $ra
    // 0x80800C10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800C10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _sujiggy_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A708: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A708);
    return;
    // 0x8008A70C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void _chpotogoldgame_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875C0: syscall     592
    recomp_syscall_handler(rdram, ctx, 0x800875C0);
    return;
    // 0x800875C4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800D6E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6E54: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D6E58: lh          $t6, -0x419E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X419E);
    // 0x800D6E5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D6E60: lwc1        $f8, 0x5CC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5CC8);
    // 0x800D6E64: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800D6E68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D6E6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D6E70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D6E74: lwc1        $f10, 0x5CCC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5CCC);
    // 0x800D6E78: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D6E7C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800D6E80: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800D6E84: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D6E88: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D6E8C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D6E90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D6E94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D6E98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D6E9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D6EA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D6EA4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800D6EA8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800D6EAC: bc1t        L_800D6ED0
    if (c1cs) {
        // 0x800D6EB0: nop
    
            goto L_800D6ED0;
    }
    // 0x800D6EB0: nop

    // 0x800D6EB4: jal         0x800A9F30
    // 0x800D6EB8: nop

    func_800A9F30(rdram, ctx);
        goto after_0;
    // 0x800D6EB8: nop

    after_0:
    // 0x800D6EBC: beq         $v0, $zero, L_800D6ED0
    if (ctx->r2 == 0) {
        // 0x800D6EC0: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_800D6ED0;
    }
    // 0x800D6EC0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800D6EC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D6EC8: beql        $t7, $at, L_800D7024
    if (ctx->r15 == ctx->r1) {
        // 0x800D6ECC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800D7024;
    }
    goto skip_0;
    // 0x800D6ECC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
L_800D6ED0:
    // 0x800D6ED0: jal         0x8001211C
    // 0x800D6ED4: nop

    func_8001211C(rdram, ctx);
        goto after_1;
    // 0x800D6ED4: nop

    after_1:
    // 0x800D6ED8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D6EDC: jal         0x800A9F14
    // 0x800D6EE0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800A9F14(rdram, ctx);
        goto after_2;
    // 0x800D6EE0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x800D6EE4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800D6EE8: subu        $a2, $s0, $v0
    ctx->r6 = SUB32(ctx->r16, ctx->r2);
    // 0x800D6EEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D6EF0: bne         $t8, $at, L_800D6F00
    if (ctx->r24 != ctx->r1) {
        // 0x800D6EF4: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800D6F00;
    }
    // 0x800D6EF4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800D6EF8: b           L_800D6F08
    // 0x800D6EFC: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
        goto L_800D6F08;
    // 0x800D6EFC: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
L_800D6F00:
    // 0x800D6F00: lh          $s0, -0x419E($s0)
    ctx->r16 = MEM_H(ctx->r16, -0X419E);
    // 0x800D6F04: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_800D6F08:
    // 0x800D6F08: bltz        $s0, L_800D7020
    if (SIGNED(ctx->r16) < 0) {
        // 0x800D6F0C: addiu       $fp, $zero, 0x5
        ctx->r30 = ADD32(0, 0X5);
            goto L_800D7020;
    }
    // 0x800D6F0C: addiu       $fp, $zero, 0x5
    ctx->r30 = ADD32(0, 0X5);
    // 0x800D6F10: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800D6F14: addiu       $s1, $s1, -0x4800
    ctx->r17 = ADD32(ctx->r17, -0X4800);
    // 0x800D6F18: addiu       $s7, $zero, 0x7
    ctx->r23 = ADD32(0, 0X7);
    // 0x800D6F1C: addiu       $s6, $zero, 0x6
    ctx->r22 = ADD32(0, 0X6);
    // 0x800D6F20: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800D6F24: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800D6F28: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800D6F2C: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_800D6F30:
    // 0x800D6F30: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800D6F34: lw          $t9, -0x46EC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X46EC);
    // 0x800D6F38: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6F3C: mflo        $t0
    ctx->r8 = lo;
    // 0x800D6F40: addu        $v0, $s1, $t0
    ctx->r2 = ADD32(ctx->r17, ctx->r8);
    // 0x800D6F44: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800D6F48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D6F4C: sll         $v1, $a0, 27
    ctx->r3 = S32(ctx->r4 << 27);
    // 0x800D6F50: srl         $t1, $v1, 28
    ctx->r9 = S32(U32(ctx->r3) >> 28);
    // 0x800D6F54: beq         $t1, $zero, L_800D6FD8
    if (ctx->r9 == 0) {
        // 0x800D6F58: nop
    
            goto L_800D6FD8;
    }
    // 0x800D6F58: nop

    // 0x800D6F5C: lhu         $t2, 0xA($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XA);
    // 0x800D6F60: srl         $t4, $a0, 5
    ctx->r12 = S32(U32(ctx->r4) >> 5);
    // 0x800D6F64: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800D6F68: srl         $t3, $t2, 12
    ctx->r11 = S32(U32(ctx->r10) >> 12);
    // 0x800D6F6C: bne         $t3, $zero, L_800D6FD8
    if (ctx->r11 != 0) {
        // 0x800D6F70: nop
    
            goto L_800D6FD8;
    }
    // 0x800D6F70: nop

    // 0x800D6F74: bne         $at, $zero, L_800D6FB0
    if (ctx->r1 != 0) {
        // 0x800D6F78: lw          $t5, 0x48($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X48);
            goto L_800D6FB0;
    }
    // 0x800D6F78: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800D6F7C: bne         $t5, $s3, L_800D6FD8
    if (ctx->r13 != ctx->r19) {
        // 0x800D6F80: nop
    
            goto L_800D6FD8;
    }
    // 0x800D6F80: nop

    // 0x800D6F84: beql        $s4, $t1, L_800D6FB4
    if (ctx->r20 == ctx->r9) {
        // 0x800D6F88: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800D6FB4;
    }
    goto skip_1;
    // 0x800D6F88: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_1:
    // 0x800D6F8C: beql        $s5, $t1, L_800D6FB4
    if (ctx->r21 == ctx->r9) {
        // 0x800D6F90: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800D6FB4;
    }
    goto skip_2;
    // 0x800D6F90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_2:
    // 0x800D6F94: beql        $s6, $t1, L_800D6FB4
    if (ctx->r22 == ctx->r9) {
        // 0x800D6F98: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800D6FB4;
    }
    goto skip_3;
    // 0x800D6F98: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_3:
    // 0x800D6F9C: beql        $s7, $t1, L_800D6FB4
    if (ctx->r23 == ctx->r9) {
        // 0x800D6FA0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800D6FB4;
    }
    goto skip_4;
    // 0x800D6FA0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_4:
    // 0x800D6FA4: beq         $fp, $t1, L_800D6FB0
    if (ctx->r30 == ctx->r9) {
        // 0x800D6FA8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800D6FB0;
    }
    // 0x800D6FA8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800D6FAC: bne         $t1, $at, L_800D6FD8
    if (ctx->r9 != ctx->r1) {
        // 0x800D6FB0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800D6FD8;
    }
L_800D6FB0:
    // 0x800D6FB0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800D6FB4:
    // 0x800D6FB4: jal         0x800D6378
    // 0x800D6FB8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800D6378(rdram, ctx);
        goto after_3;
    // 0x800D6FB8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_3:
    // 0x800D6FBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800D6FC0: lw          $t6, -0x46EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X46EC);
    // 0x800D6FC4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800D6FC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D6FCC: blez        $t6, L_800D6FD8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D6FD0: addiu       $t7, $t6, -0x1
        ctx->r15 = ADD32(ctx->r14, -0X1);
            goto L_800D6FD8;
    }
    // 0x800D6FD0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800D6FD4: sw          $t7, -0x46EC($at)
    MEM_W(-0X46EC, ctx->r1) = ctx->r15;
L_800D6FD8:
    // 0x800D6FD8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800D6FDC: lh          $t9, -0x419E($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X419E);
    // 0x800D6FE0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800D6FE4: lw          $t8, -0x46EC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X46EC);
    // 0x800D6FE8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800D6FEC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D6FF0: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D6FF4: bne         $at, $zero, L_800D7008
    if (ctx->r1 != 0) {
        // 0x800D6FF8: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800D7008;
    }
    // 0x800D6FF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800D6FFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D7000: b           L_800D7018
    // 0x800D7004: sw          $zero, -0x46EC($at)
    MEM_W(-0X46EC, ctx->r1) = 0;
        goto L_800D7018;
    // 0x800D7004: sw          $zero, -0x46EC($at)
    MEM_W(-0X46EC, ctx->r1) = 0;
L_800D7008:
    // 0x800D7008: lw          $t1, -0x46EC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X46EC);
    // 0x800D700C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D7010: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800D7014: sw          $t2, -0x46EC($at)
    MEM_W(-0X46EC, ctx->r1) = ctx->r10;
L_800D7018:
    // 0x800D7018: bgez        $s0, L_800D6F30
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800D701C: nop
    
            goto L_800D6F30;
    }
    // 0x800D701C: nop

L_800D7020:
    // 0x800D7020: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800D7024:
    // 0x800D7024: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D7028: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D702C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D7030: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D7034: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D7038: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D703C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D7040: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800D7044: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800D7048: jr          $ra
    // 0x800D704C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800D704C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80806800_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80806804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806808: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080680C: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80806810: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80806814: bnel        $t6, $at, L_80806828
    if (ctx->r14 != ctx->r1) {
        // 0x80806818: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80806828;
    }
    goto skip_0;
    // 0x80806818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080681C: jal         0x80803B84
    // 0x80806820: nop

    func_80803B84_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80806820: nop

    after_0:
    // 0x80806824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806828:
    // 0x80806828: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080682C: jr          $ra
    // 0x80806830: nop

    return;
    // 0x80806830: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080073C: jal         0x80800758
    // 0x80800740: nop

    sujiggy_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80800740: nop

    after_0:
    // 0x80800744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800748: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8080074C: xori        $v0, $t6, 0x1
    ctx->r2 = ctx->r14 ^ 0X1;
    // 0x80800750: jr          $ra
    // 0x80800754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8008F964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F96C: jal         0x800F54E4
    // 0x8008F970: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008F970: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008F974: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F978: jal         0x800F4A2C
    // 0x8008F97C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F4A2C(rdram, ctx);
        goto after_1;
    // 0x8008F97C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008F980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F984: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F988: jr          $ra
    // 0x8008F98C: nop

    return;
    // 0x8008F98C: nop

;}
RECOMP_FUNC void chicywind_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1280, 0X300) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x300
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1280, 0X300));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x300
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1280, 0X300));
;}
RECOMP_FUNC void func_80800624_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800624: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800628: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080062C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800630: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800634: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800638: jal         0x80100094
    // 0x8080063C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080063C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800640: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800644: jal         0x801022E4
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_1;
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: jal         0x801015D0
    // 0x80800654: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_801015D0(rdram, ctx);
        goto after_2;
    // 0x80800654: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800658: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x8080065C: addiu       $at, $zero, 0x42C
    ctx->r1 = ADD32(0, 0X42C);
    // 0x80800660: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800664: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800668: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x8080066C: bne         $t8, $at, L_8080067C
    if (ctx->r24 != ctx->r1) {
        // 0x80800670: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_8080067C;
    }
    // 0x80800670: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800674: b           L_80800680
    // 0x80800678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800680;
    // 0x80800678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080067C:
    // 0x8080067C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800680:
    // 0x80800680: addiu       $at, $zero, 0x2D5
    ctx->r1 = ADD32(0, 0X2D5);
    // 0x80800684: beq         $v1, $at, L_808006A0
    if (ctx->r3 == ctx->r1) {
        // 0x80800688: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_808006A0;
    }
    // 0x80800688: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080068C: addiu       $at, $zero, 0x2D6
    ctx->r1 = ADD32(0, 0X2D6);
    // 0x80800690: beq         $v1, $at, L_808006A0
    if (ctx->r3 == ctx->r1) {
        // 0x80800694: nop
    
            goto L_808006A0;
    }
    // 0x80800694: nop

    // 0x80800698: b           L_808006A0
    // 0x8080069C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_808006A0;
    // 0x8080069C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_808006A0:
    // 0x808006A0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808006A4: jal         0x800DF744
    // 0x808006A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x808006A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_3:
    // 0x808006AC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808006B0: jal         0x800DF744
    // 0x808006B4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x808006B4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // 0x808006B8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808006BC: jal         0x800DF744
    // 0x808006C0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x808006C0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x808006C4: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x808006C8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x808006CC: srl         $t9, $a1, 7
    ctx->r25 = S32(U32(ctx->r5) >> 7);
    // 0x808006D0: jal         0x800DF744
    // 0x808006D4: addiu       $a1, $t9, -0x31
    ctx->r5 = ADD32(ctx->r25, -0X31);
    func_800DF744(rdram, ctx);
        goto after_6;
    // 0x808006D4: addiu       $a1, $t9, -0x31
    ctx->r5 = ADD32(ctx->r25, -0X31);
    after_6:
    // 0x808006D8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x808006DC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x808006E0: srl         $t0, $a1, 7
    ctx->r8 = S32(U32(ctx->r5) >> 7);
    // 0x808006E4: jal         0x800DF744
    // 0x808006E8: addiu       $a1, $t0, -0x31
    ctx->r5 = ADD32(ctx->r8, -0X31);
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x808006E8: addiu       $a1, $t0, -0x31
    ctx->r5 = ADD32(ctx->r8, -0X31);
    after_7:
    // 0x808006EC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x808006F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006F4: lh          $t1, 0x18($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X18);
    // 0x808006F8: bnel        $t1, $at, L_80800734
    if (ctx->r9 != ctx->r1) {
        // 0x808006FC: lhu         $t3, 0x14($v0)
        ctx->r11 = MEM_HU(ctx->r2, 0X14);
            goto L_80800734;
    }
    goto skip_0;
    // 0x808006FC: lhu         $t3, 0x14($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X14);
    skip_0:
    // 0x80800700: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800704: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800708: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080070C: lwc1        $f12, 0x1C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80800710: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x80800714: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800718: jal         0x800F12D4
    // 0x8080071C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_8;
    // 0x8080071C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80800720: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800724: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800728: b           L_8080074C
    // 0x8080072C: nop

        goto L_8080074C;
    // 0x8080072C: nop

    // 0x80800730: lhu         $t3, 0x14($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X14);
L_80800734:
    // 0x80800734: addiu       $at, $zero, 0x7E7
    ctx->r1 = ADD32(0, 0X7E7);
    // 0x80800738: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8080073C: bne         $t3, $at, L_8080074C
    if (ctx->r11 != ctx->r1) {
        // 0x80800740: nop
    
            goto L_8080074C;
    }
    // 0x80800740: nop

    // 0x80800744: b           L_8080074C
    // 0x80800748: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8080074C;
    // 0x80800748: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8080074C:
    // 0x8080074C: jal         0x800DF6BC
    // 0x80800750: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_800DF6BC(rdram, ctx);
        goto after_9;
    // 0x80800750: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_9:
    // 0x80800754: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080075C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80800760: jal         0x8008A078
    // 0x80800764: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    _subaddiepalette_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80800764: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_10:
    // 0x80800768: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080076C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800770: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800774: jr          $ra
    // 0x80800778: nop

    return;
    // 0x80800778: nop

;}
RECOMP_FUNC void func_80800128_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080012C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800134: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800138: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080013C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80800140: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800148: jal         0x800DA9E4
    // 0x8080014C: addiu       $a0, $zero, 0xE4
    ctx->r4 = ADD32(0, 0XE4);
    func_800DA9E4(rdram, ctx);
        goto after_0;
    // 0x8080014C: addiu       $a0, $zero, 0xE4
    ctx->r4 = ADD32(0, 0XE4);
    after_0:
    // 0x80800150: bne         $v0, $zero, L_80800168
    if (ctx->r2 != 0) {
        // 0x80800154: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_80800168;
    }
    // 0x80800154: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800158: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8080015C: addiu       $a1, $zero, 0x100C
    ctx->r5 = ADD32(0, 0X100C);
    // 0x80800160: b           L_808001E8
    // 0x80800164: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
        goto L_808001E8;
    // 0x80800164: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80800168:
    // 0x80800168: beq         $t8, $zero, L_808001D0
    if (ctx->r24 == 0) {
        // 0x8080016C: addiu       $a0, $zero, 0x19
        ctx->r4 = ADD32(0, 0X19);
            goto L_808001D0;
    }
    // 0x8080016C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80800170: jal         0x800D0B68
    // 0x80800174: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_800D0B68(rdram, ctx);
        goto after_1;
    // 0x80800174: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x80800178: bnel        $v0, $zero, L_808001D4
    if (ctx->r2 != 0) {
        // 0x8080017C: addiu       $a0, $zero, 0x100D
        ctx->r4 = ADD32(0, 0X100D);
            goto L_808001D4;
    }
    goto skip_0;
    // 0x8080017C: addiu       $a0, $zero, 0x100D
    ctx->r4 = ADD32(0, 0X100D);
    skip_0:
    // 0x80800180: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80800184: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80800188: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8080018C: andi        $t9, $v0, 0x1FF
    ctx->r25 = ctx->r2 & 0X1FF;
    // 0x80800190: addiu       $a1, $t9, 0x1010
    ctx->r5 = ADD32(ctx->r25, 0X1010);
    // 0x80800194: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x80800198: sltiu       $at, $t9, 0x2
    ctx->r1 = ctx->r25 < 0X2 ? 1 : 0;
    // 0x8080019C: beq         $at, $zero, L_808001C0
    if (ctx->r1 == 0) {
        // 0x808001A0: sra         $a1, $t0, 16
        ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
            goto L_808001C0;
    }
    // 0x808001A0: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    // 0x808001A4: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    // 0x808001A8: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x808001AC: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x808001B0: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x808001B4: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x808001B8: b           L_808001E8
    // 0x808001BC: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
        goto L_808001E8;
    // 0x808001BC: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
L_808001C0:
    // 0x808001C0: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808001C4: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808001C8: b           L_808001E8
    // 0x808001CC: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
        goto L_808001E8;
    // 0x808001CC: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
L_808001D0:
    // 0x808001D0: addiu       $a0, $zero, 0x100D
    ctx->r4 = ADD32(0, 0X100D);
L_808001D4:
    // 0x808001D4: jal         0x800DC128
    // 0x808001D8: addiu       $a1, $zero, 0x1010
    ctx->r5 = ADD32(0, 0X1010);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x808001D8: addiu       $a1, $zero, 0x1010
    ctx->r5 = ADD32(0, 0X1010);
    after_2:
    // 0x808001DC: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x808001E0: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x808001E4: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_808001E8:
    // 0x808001E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001EC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1796, 0XEAC) << 16);
    // 0x808001F0: addiu       $t1, $zero, 0x6E
    ctx->r9 = ADD32(0, 0X6E);
    // 0x808001F4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808001F8: addiu       $a3, $a3, 0xEAC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1796, 0XEAC));
    // 0x808001FC: jal         0x8008A208
    // 0x80800200: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800200: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800204: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80800208: ori         $t5, $t3, 0x40
    ctx->r13 = ctx->r11 | 0X40;
    // 0x8080020C: sb          $t5, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r13;
    // 0x80800210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800214: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800218: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080021C: jr          $ra
    // 0x80800220: nop

    return;
    // 0x80800220: nop

;}
RECOMP_FUNC void func_80800AB4_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800ABC: jal         0x808009E4
    // 0x80800AC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808009E4_chfactoryworkerdirty(rdram, ctx);
        goto after_0;
    // 0x80800AC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800AC4: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800AC8: bne         $t6, $zero, L_80800AE8
    if (ctx->r14 != 0) {
        // 0x80800ACC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800AE8;
    }
    // 0x80800ACC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800AD0: jal         0x80800A04
    // 0x80800AD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800A04_chfactoryworkerdirty(rdram, ctx);
        goto after_1;
    // 0x80800AD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800AD8: jal         0x800DA298
    // 0x80800ADC: addiu       $a0, $v0, 0x42D
    ctx->r4 = ADD32(ctx->r2, 0X42D);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800ADC: addiu       $a0, $v0, 0x42D
    ctx->r4 = ADD32(ctx->r2, 0X42D);
    after_2:
    // 0x80800AE0: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800AE4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80800AE8:
    // 0x80800AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AF0: jr          $ra
    // 0x80800AF4: nop

    return;
    // 0x80800AF4: nop

;}
RECOMP_FUNC void func_8080003C_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800048: jal         0x800D8FF8
    // 0x8080004C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080004C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800050: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800054: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800058: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080005C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800060: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80800064: nop

    // 0x80800068: bc1f        L_8080007C
    if (!c1cs) {
        // 0x8080006C: nop
    
            goto L_8080007C;
    }
    // 0x8080006C: nop

    // 0x80800070: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80800074: b           L_808000C4
    // 0x80800078: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_808000C4;
    // 0x80800078: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_8080007C:
    // 0x8080007C: jal         0x800DC128
    // 0x80800080: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80800080: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80800084: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80800088: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1796, 0XEA0) << 16);
    // 0x8080008C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80800090: jal         0x800C4B7C
    // 0x80800094: lh          $a0, 0xEA0($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1796, 0XEA0));
    func_800C4B7C(rdram, ctx);
        goto after_2;
    // 0x80800094: lh          $a0, 0xEA0($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1796, 0XEA0));
    after_2:
    // 0x80800098: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0XE68) << 16);
    // 0x8080009C: addiu       $a1, $a1, 0xE68
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE68));
    // 0x808000A0: jal         0x80800000
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chblackeye(rdram, ctx);
        goto after_3;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000A8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x808000AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000B0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808000B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000B8: jal         0x800DC178
    // 0x808000BC: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808000BC: nop

    after_4:
    // 0x808000C0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_808000C4:
    // 0x808000C4: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808000C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808000CC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808000D8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0XE80) << 16);
    // 0x808000DC: bc1f        L_808000F0
    if (!c1cs) {
        // 0x808000E0: nop
    
            goto L_808000F0;
    }
    // 0x808000E0: nop

    // 0x808000E4: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x808000E8: b           L_80800114
    // 0x808000EC: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
        goto L_80800114;
    // 0x808000EC: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
L_808000F0:
    // 0x808000F0: jal         0x80800000
    // 0x808000F4: addiu       $a1, $a1, 0xE80
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE80));
    func_80800000_chblackeye(rdram, ctx);
        goto after_5;
    // 0x808000F4: addiu       $a1, $a1, 0xE80
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE80));
    after_5:
    // 0x808000F8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x808000FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800100: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800104: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800108: jal         0x800DC178
    // 0x8080010C: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x8080010C: nop

    after_6:
    // 0x80800110: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_80800114:
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800118: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void _sulights_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8B8: syscall     854
    recomp_syscall_handler(rdram, ctx, 0x8008A8B8);
    return;
    // 0x8008A8BC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800170D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800170D4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800170D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800170DC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800170E0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800170E4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800170E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800170EC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800170F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800170F4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800170F8: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800170FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80017100: jr          $ra
    // 0x80017104: lw          $v0, -0x5E50($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E50);
    return;
    // 0x80017104: lw          $v0, -0x5E50($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E50);
;}
