#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808016A4_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016A4: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x808016A8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x808016AC: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x808016B0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x808016B4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x808016B8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x808016BC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x808016C0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x808016C4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x808016C8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x808016CC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x808016D0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x808016D4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x808016D8: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x808016DC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x808016E0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808016E4: jal         0x80100094
    // 0x808016E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808016E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808016EC: addiu       $s5, $sp, 0xC4
    ctx->r21 = ADD32(ctx->r29, 0XC4);
    // 0x808016F0: addiu       $s6, $sp, 0xB8
    ctx->r22 = ADD32(ctx->r29, 0XB8);
    // 0x808016F4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808016F8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x808016FC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80801700: jal         0x808019F4
    // 0x80801704: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_808019F4_chfactorymagnet(rdram, ctx);
        goto after_1;
    // 0x80801704: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_1:
    // 0x80801708: jal         0x800D674C
    // 0x8080170C: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x8080170C: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    after_2:
    // 0x80801710: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80801714: jal         0x800E2594
    // 0x80801718: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E2594(rdram, ctx);
        goto after_3;
    // 0x80801718: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8080171C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801720: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80801724: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801728: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080172C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80801730: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801734: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80801738: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8080173C: addiu       $s3, $sp, 0xA0
    ctx->r19 = ADD32(ctx->r29, 0XA0);
L_80801740:
    // 0x80801740: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
    // 0x80801744: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80801748: beq         $t6, $zero, L_808018A4
    if (ctx->r14 == 0) {
        // 0x8080174C: nop
    
            goto L_808018A4;
    }
    // 0x8080174C: nop

    // 0x80801750: jal         0x800D90A4
    // 0x80801754: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x80801754: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_4:
    // 0x80801758: beql        $v0, $zero, L_8080176C
    if (ctx->r2 == 0) {
        // 0x8080175C: lwc1        $f12, 0xC($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8080176C;
    }
    goto skip_0;
    // 0x8080175C: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x80801760: b           L_808018AC
    // 0x80801764: sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
        goto L_808018AC;
    // 0x80801764: sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
    // 0x80801768: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
L_8080176C:
    // 0x8080176C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80801770: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80801774: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801778: jal         0x800F12D4
    // 0x8080177C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_800F12D4(rdram, ctx);
        goto after_5;
    // 0x8080177C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_5:
    // 0x80801780: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80801784: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80801788: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080178C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801790: bc1fl       L_80801828
    if (!c1cs) {
        // 0x80801794: lbu         $t8, 0x18($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X18);
            goto L_80801828;
    }
    goto skip_1;
    // 0x80801794: lbu         $t8, 0x18($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18);
    skip_1:
    // 0x80801798: sub.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8080179C: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    // 0x808017A0: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x808017A4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x808017A8: bne         $s4, $t7, L_808017B8
    if (ctx->r20 != ctx->r15) {
        // 0x808017AC: add.s       $f2, $f2, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
            goto L_808017B8;
    }
    // 0x808017AC: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x808017B0: b           L_808017B8
    // 0x808017B4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
        goto L_808017B8;
    // 0x808017B4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
L_808017B8:
    // 0x808017B8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808017BC: jal         0x800EFE50
    // 0x808017C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFE50(rdram, ctx);
        goto after_6;
    // 0x808017C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x808017C4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808017C8: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x808017CC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808017D0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808017D4: jal         0x800F10B4
    // 0x808017D8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x808017D8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_7:
    // 0x808017DC: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x808017E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808017E4: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x808017E8: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808017EC: jal         0x800138D0
    // 0x808017F0: nop

    func_800138D0(rdram, ctx);
        goto after_8;
    // 0x808017F0: nop

    after_8:
    // 0x808017F4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x808017F8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808017FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801800: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80801804: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80801808: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080180C: jal         0x80013970
    // 0x80801810: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    func_80013970(rdram, ctx);
        goto after_9;
    // 0x80801810: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x80801814: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80801818: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8080181C: b           L_80801874
    // 0x80801820: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
        goto L_80801874;
    // 0x80801820: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x80801824: lbu         $t8, 0x18($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18);
L_80801828:
    // 0x80801828: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8080182C: bne         $s4, $t8, L_8080183C
    if (ctx->r20 != ctx->r24) {
        // 0x80801830: nop
    
            goto L_8080183C;
    }
    // 0x80801830: nop

    // 0x80801834: b           L_8080183C
    // 0x80801838: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
        goto L_8080183C;
    // 0x80801838: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
L_8080183C:
    // 0x8080183C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80801840: jal         0x800EE7F8
    // 0x80801844: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80801844: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    after_10:
    // 0x80801848: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X2900) << 16);
    // 0x8080184C: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80801850: lwc1        $f6, 0x2900($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2284, 0X2900));
    // 0x80801854: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80801858: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8080185C: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x80801860: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x80801864: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x80801868: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080186C: mfc1        $s1, $f10
    ctx->r17 = (int32_t)ctx->f10.u32l;
    // 0x80801870: nop

L_80801874:
    // 0x80801874: jal         0x800E2588
    // 0x80801878: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800E2588(rdram, ctx);
        goto after_11;
    // 0x80801878: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_11:
    // 0x8080187C: lbu         $a1, 0x19($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X19);
    // 0x80801880: addiu       $t0, $sp, 0x94
    ctx->r8 = ADD32(ctx->r29, 0X94);
    // 0x80801884: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801888: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8080188C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80801890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801894: jal         0x800E2720
    // 0x80801898: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_800E2720(rdram, ctx);
        goto after_12;
    // 0x80801898: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_12:
    // 0x8080189C: b           L_808018B0
    // 0x808018A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_808018B0;
    // 0x808018A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_808018A4:
    // 0x808018A4: jal         0x80801508
    // 0x808018A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80801508_chfactorymagnet(rdram, ctx);
        goto after_13;
    // 0x808018A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_13:
L_808018AC:
    // 0x808018AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_808018B0:
    // 0x808018B0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x808018B4: bne         $s2, $at, L_80801740
    if (ctx->r18 != ctx->r1) {
        // 0x808018B8: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_80801740;
    }
    // 0x808018B8: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x808018BC: jal         0x800E2A14
    // 0x808018C0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800E2A14(rdram, ctx);
        goto after_14;
    // 0x808018C0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_14:
    // 0x808018C4: jal         0x800D674C
    // 0x808018C8: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800D674C(rdram, ctx);
        goto after_15;
    // 0x808018C8: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_15:
    // 0x808018CC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808018D0: jal         0x800E2594
    // 0x808018D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E2594(rdram, ctx);
        goto after_16;
    // 0x808018D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x808018D8: slti        $at, $s2, 0x1E
    ctx->r1 = SIGNED(ctx->r18) < 0X1E ? 1 : 0;
    // 0x808018DC: beq         $at, $zero, L_808019B0
    if (ctx->r1 == 0) {
        // 0x808018E0: addiu       $s3, $sp, 0x74
        ctx->r19 = ADD32(ctx->r29, 0X74);
            goto L_808019B0;
    }
    // 0x808018E0: addiu       $s3, $sp, 0x74
    ctx->r19 = ADD32(ctx->r29, 0X74);
    // 0x808018E4: addiu       $s1, $sp, 0x80
    ctx->r17 = ADD32(ctx->r29, 0X80);
L_808018E8:
    // 0x808018E8: lbu         $t1, 0x18($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X18);
    // 0x808018EC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x808018F0: beq         $t1, $zero, L_80801998
    if (ctx->r9 == 0) {
        // 0x808018F4: nop
    
            goto L_80801998;
    }
    // 0x808018F4: nop

    // 0x808018F8: jal         0x800D90A4
    // 0x808018FC: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_800D90A4(rdram, ctx);
        goto after_17;
    // 0x808018FC: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_17:
    // 0x80801900: beql        $v0, $zero, L_80801914
    if (ctx->r2 == 0) {
        // 0x80801904: lwc1        $f12, 0xC($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80801914;
    }
    goto skip_2;
    // 0x80801904: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    skip_2:
    // 0x80801908: b           L_808019A0
    // 0x8080190C: sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
        goto L_808019A0;
    // 0x8080190C: sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
    // 0x80801910: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
L_80801914:
    // 0x80801914: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80801918: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8080191C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801920: jal         0x800F12D4
    // 0x80801924: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_800F12D4(rdram, ctx);
        goto after_18;
    // 0x80801924: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_18:
    // 0x80801928: lbu         $t2, 0x18($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X18);
    // 0x8080192C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80801930: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80801934: bne         $s4, $t2, L_80801944
    if (ctx->r20 != ctx->r10) {
        // 0x80801938: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801944;
    }
    // 0x80801938: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080193C: b           L_80801948
    // 0x80801940: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
        goto L_80801948;
    // 0x80801940: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
L_80801944:
    // 0x80801944: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
L_80801948:
    // 0x80801948: jal         0x800EFE50
    // 0x8080194C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EFE50(rdram, ctx);
        goto after_19;
    // 0x8080194C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_19:
    // 0x80801950: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80801954: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80801958: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x8080195C: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80801960: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x80801964: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80801968: jal         0x800E2588
    // 0x8080196C: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    func_800E2588(rdram, ctx);
        goto after_20;
    // 0x8080196C: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    after_20:
    // 0x80801970: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80801974: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801978: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8080197C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801980: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801984: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80801988: jal         0x800E2720
    // 0x8080198C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800E2720(rdram, ctx);
        goto after_21;
    // 0x8080198C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_21:
    // 0x80801990: b           L_808019A4
    // 0x80801994: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_808019A4;
    // 0x80801994: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80801998:
    // 0x80801998: jal         0x80801508
    // 0x8080199C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80801508_chfactorymagnet(rdram, ctx);
        goto after_22;
    // 0x8080199C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_22:
L_808019A0:
    // 0x808019A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_808019A4:
    // 0x808019A4: slti        $at, $s2, 0x1E
    ctx->r1 = SIGNED(ctx->r18) < 0X1E ? 1 : 0;
    // 0x808019A8: bne         $at, $zero, L_808018E8
    if (ctx->r1 != 0) {
        // 0x808019AC: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_808018E8;
    }
    // 0x808019AC: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_808019B0:
    // 0x808019B0: jal         0x800E2A14
    // 0x808019B4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800E2A14(rdram, ctx);
        goto after_23;
    // 0x808019B4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_23:
    // 0x808019B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x808019BC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808019C0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808019C4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x808019C8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808019CC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x808019D0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x808019D4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x808019D8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x808019DC: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x808019E0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x808019E4: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x808019E8: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x808019EC: jr          $ra
    // 0x808019F0: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x808019F0: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_800A70B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A70B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A70B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A70B8: jal         0x800FFA88
    // 0x800A70BC: nop

    func_800FFA88(rdram, ctx);
        goto after_0;
    // 0x800A70BC: nop

    after_0:
    // 0x800A70C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A70C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A70C8: jr          $ra
    // 0x800A70CC: nop

    return;
    // 0x800A70CC: nop

;}
RECOMP_FUNC void chfloorbubbles_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1716, 0X2CC) << 16);
    // 0x80800250: jr          $ra
    // 0x80800254: addiu       $v0, $v0, 0x2CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1716, 0X2CC));
    return;
    // 0x80800254: addiu       $v0, $v0, 0x2CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1716, 0X2CC));
    // 0x80800258: nop

    // 0x8080025C: nop

;}
RECOMP_FUNC void func_808023E8_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808023E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808023EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808023F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808023F4: jal         0x80100094
    // 0x808023F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808023F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808023FC: beq         $v0, $zero, L_8080240C
    if (ctx->r2 == 0) {
        // 0x80802400: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080240C;
    }
    // 0x80802400: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802404: jal         0x800897C8
    // 0x80802408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80802408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_8080240C:
    // 0x8080240C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802414: jr          $ra
    // 0x80802418: nop

    return;
    // 0x80802418: nop

;}
RECOMP_FUNC void subaddieDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080036C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800370: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800374: jal         0x800DA544
    // 0x80800378: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800378: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080037C: jal         0x80800338
    // 0x80800380: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    subaddieDll_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800380: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void func_80801268_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801268: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080126C: lh          $t6, 0x66($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X66);
    // 0x80801270: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80801274: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80801278: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8080127C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80801280: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80801284: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80801288: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8080128C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80801290: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80801294: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801298: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8080129C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808012A0: sb          $t6, 0x167($a0)
    MEM_B(0X167, ctx->r4) = ctx->r14;
    // 0x808012A4: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x808012A8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808012AC: jal         0x80801038
    // 0x808012B0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80801038_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x808012B0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_0:
    // 0x808012B4: lbu         $t7, 0x15F($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X15F);
    // 0x808012B8: sw          $s0, 0x168($s2)
    MEM_W(0X168, ctx->r18) = ctx->r16;
    // 0x808012BC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808012C0: andi        $t3, $t7, 0xFFCF
    ctx->r11 = ctx->r15 & 0XFFCF;
    // 0x808012C4: sb          $t3, 0x15F($s2)
    MEM_B(0X15F, ctx->r18) = ctx->r11;
    // 0x808012C8: lw          $v0, 0x15C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X15C);
    // 0x808012CC: andi        $t4, $t3, 0xFC
    ctx->r12 = ctx->r11 & 0XFC;
    // 0x808012D0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x808012D4: sll         $t9, $v0, 26
    ctx->r25 = S32(ctx->r2 << 26);
    // 0x808012D8: srl         $v0, $t9, 30
    ctx->r2 = S32(U32(ctx->r25) >> 30);
    // 0x808012DC: andi        $t2, $v0, 0x3
    ctx->r10 = ctx->r2 & 0X3;
    // 0x808012E0: or          $t8, $t2, $t4
    ctx->r24 = ctx->r10 | ctx->r12;
    // 0x808012E4: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x808012E8: sll         $t7, $v0, 6
    ctx->r15 = S32(ctx->r2 << 6);
    // 0x808012EC: or          $t2, $t7, $t9
    ctx->r10 = ctx->r15 | ctx->r25;
    // 0x808012F0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x808012F4: andi        $t3, $t1, 0xC
    ctx->r11 = ctx->r9 & 0XC;
    // 0x808012F8: andi        $t4, $t2, 0xF3
    ctx->r12 = ctx->r10 & 0XF3;
    // 0x808012FC: sb          $t8, 0x15F($s2)
    MEM_B(0X15F, ctx->r18) = ctx->r24;
    // 0x80801300: sb          $t2, 0x15F($s2)
    MEM_B(0X15F, ctx->r18) = ctx->r10;
    // 0x80801304: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80801308: sb          $t5, 0x15F($s2)
    MEM_B(0X15F, ctx->r18) = ctx->r13;
    // 0x8080130C: sb          $v0, 0x15D($s2)
    MEM_B(0X15D, ctx->r18) = ctx->r2;
    // 0x80801310: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80801314: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x80801318: sw          $t6, 0x170($s2)
    MEM_W(0X170, ctx->r18) = ctx->r14;
    // 0x8080131C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80801320: sw          $t8, 0x174($s2)
    MEM_W(0X174, ctx->r18) = ctx->r24;
    // 0x80801324: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80801328: beq         $s0, $zero, L_80801354
    if (ctx->r16 == 0) {
        // 0x8080132C: sw          $t7, 0x178($s2)
        MEM_W(0X178, ctx->r18) = ctx->r15;
            goto L_80801354;
    }
    // 0x8080132C: sw          $t7, 0x178($s2)
    MEM_W(0X178, ctx->r18) = ctx->r15;
    // 0x80801330: lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X12);
    // 0x80801334: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80801338: srl         $t9, $v0, 1
    ctx->r25 = S32(U32(ctx->r2) >> 1);
    // 0x8080133C: beq         $t9, $zero, L_8080134C
    if (ctx->r25 == 0) {
        // 0x80801340: nop
    
            goto L_8080134C;
    }
    // 0x80801340: nop

    // 0x80801344: b           L_8080134C
    // 0x80801348: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
        goto L_8080134C;
    // 0x80801348: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_8080134C:
    // 0x8080134C: b           L_80801358
    // 0x80801350: sw          $a1, 0x16C($s2)
    MEM_W(0X16C, ctx->r18) = ctx->r5;
        goto L_80801358;
    // 0x80801350: sw          $a1, 0x16C($s2)
    MEM_W(0X16C, ctx->r18) = ctx->r5;
L_80801354:
    // 0x80801354: sw          $t0, 0x16C($s2)
    MEM_W(0X16C, ctx->r18) = ctx->r8;
L_80801358:
    // 0x80801358: lbu         $t1, 0x15E($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X15E);
    // 0x8080135C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80801360: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x80801364: andi        $t2, $t1, 0xFFFC
    ctx->r10 = ctx->r9 & 0XFFFC;
    // 0x80801368: sb          $t2, 0x15E($s2)
    MEM_B(0X15E, ctx->r18) = ctx->r10;
L_8080136C:
    // 0x8080136C: lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X104);
    // 0x80801370: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801374: lh          $a2, 0x0($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X0);
    // 0x80801378: slti        $at, $a2, -0x5
    ctx->r1 = SIGNED(ctx->r6) < -0X5 ? 1 : 0;
    // 0x8080137C: beql        $at, $zero, L_808013BC
    if (ctx->r1 == 0) {
        // 0x80801380: sh          $a2, 0x118($s7)
        MEM_H(0X118, ctx->r23) = ctx->r6;
            goto L_808013BC;
    }
    goto skip_0;
    // 0x80801380: sh          $a2, 0x118($s7)
    MEM_H(0X118, ctx->r23) = ctx->r6;
    skip_0:
    // 0x80801384: lbu         $a0, 0x114($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X114);
    // 0x80801388: sll         $t3, $zero, 3
    ctx->r11 = S32(0 << 3);
    // 0x8080138C: addu        $v0, $a1, $t3
    ctx->r2 = ADD32(ctx->r5, ctx->r11);
    // 0x80801390: blezl       $a0, L_808013BC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80801394: sh          $a2, 0x118($s7)
        MEM_H(0X118, ctx->r23) = ctx->r6;
            goto L_808013BC;
    }
    goto skip_1;
    // 0x80801394: sh          $a2, 0x118($s7)
    MEM_H(0X118, ctx->r23) = ctx->r6;
    skip_1:
    // 0x80801398: lh          $t4, 0x8($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X8);
L_8080139C:
    // 0x8080139C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808013A0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x808013A4: slti        $at, $t4, -0x5
    ctx->r1 = SIGNED(ctx->r12) < -0X5 ? 1 : 0;
    // 0x808013A8: beq         $at, $zero, L_808013B8
    if (ctx->r1 == 0) {
        // 0x808013AC: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_808013B8;
    }
    // 0x808013AC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x808013B0: bnel        $at, $zero, L_8080139C
    if (ctx->r1 != 0) {
        // 0x808013B4: lh          $t4, 0x8($v0)
        ctx->r12 = MEM_H(ctx->r2, 0X8);
            goto L_8080139C;
    }
    goto skip_2;
    // 0x808013B4: lh          $t4, 0x8($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X8);
    skip_2:
L_808013B8:
    // 0x808013B8: sh          $a2, 0x118($s7)
    MEM_H(0X118, ctx->r23) = ctx->r6;
L_808013BC:
    // 0x808013BC: lw          $t5, 0x104($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X104);
    // 0x808013C0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808013C4: sll         $s1, $v1, 3
    ctx->r17 = S32(ctx->r3 << 3);
    // 0x808013C8: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x808013CC: sw          $t6, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r14;
    // 0x808013D0: jal         0x80801008
    // 0x808013D4: sb          $zero, 0x116($s3)
    MEM_B(0X116, ctx->r19) = 0;
    func_80801008_gcdialogexec(rdram, ctx);
        goto after_1;
    // 0x808013D4: sb          $zero, 0x116($s3)
    MEM_B(0X116, ctx->r19) = 0;
    after_1:
    // 0x808013D8: sh          $v0, 0x128($s7)
    MEM_H(0X128, ctx->r23) = ctx->r2;
    // 0x808013DC: lbu         $t8, 0x11C($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X11C);
    // 0x808013E0: andi        $t7, $t8, 0xFFCF
    ctx->r15 = ctx->r24 & 0XFFCF;
    // 0x808013E4: sb          $t7, 0x11C($s3)
    MEM_B(0X11C, ctx->r19) = ctx->r15;
    // 0x808013E8: lw          $t9, 0x104($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X104);
    // 0x808013EC: andi        $t1, $t7, 0xFF
    ctx->r9 = ctx->r15 & 0XFF;
    // 0x808013F0: srl         $t2, $t1, 6
    ctx->r10 = S32(U32(ctx->r9) >> 6);
    // 0x808013F4: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x808013F8: lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X0);
    // 0x808013FC: bltz        $v1, L_80801518
    if (SIGNED(ctx->r3) < 0) {
        // 0x80801400: slti        $at, $v1, -0x4
        ctx->r1 = SIGNED(ctx->r3) < -0X4 ? 1 : 0;
            goto L_80801518;
    }
    // 0x80801400: slti        $at, $v1, -0x4
    ctx->r1 = SIGNED(ctx->r3) < -0X4 ? 1 : 0;
    // 0x80801404: bne         $t2, $zero, L_808014C4
    if (ctx->r10 != 0) {
        // 0x80801408: lw          $a1, 0x50($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X50);
            goto L_808014C4;
    }
    // 0x80801408: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8080140C: addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // 0x80801410: lui         $s4, 0x800C
    ctx->r20 = S32(0X800C << 16);
    // 0x80801414: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80801418: addiu       $s4, $s4, 0x1D8
    ctx->r20 = ADD32(ctx->r20, 0X1D8);
    // 0x8080141C: andi        $s5, $a1, 0x100
    ctx->r21 = ctx->r5 & 0X100;
    // 0x80801420: beq         $v0, $at, L_80801468
    if (ctx->r2 == ctx->r1) {
        // 0x80801424: andi        $fp, $a1, 0x400
        ctx->r30 = ctx->r5 & 0X400;
            goto L_80801468;
    }
    // 0x80801424: andi        $fp, $a1, 0x400
    ctx->r30 = ctx->r5 & 0X400;
    // 0x80801428: addiu       $at, $zero, 0x84
    ctx->r1 = ADD32(0, 0X84);
    // 0x8080142C: beq         $v0, $at, L_80801468
    if (ctx->r2 == ctx->r1) {
        // 0x80801430: nop
    
            goto L_80801468;
    }
    // 0x80801430: nop

    // 0x80801434: jal         0x80801020
    // 0x80801438: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80801020_gcdialogexec(rdram, ctx);
        goto after_2;
    // 0x80801438: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x8080143C: lw          $t3, 0x104($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X104);
    // 0x80801440: lh          $a0, 0x128($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X128);
    // 0x80801444: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801448: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8080144C: lh          $a1, 0x0($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X0);
    // 0x80801450: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80801454: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80801458: jal         0x80087B08
    // 0x8080145C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    _gczoombox_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x8080145C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_3:
    // 0x80801460: b           L_8080149C
    // 0x80801464: sw          $v0, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->r2;
        goto L_8080149C;
    // 0x80801464: sw          $v0, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->r2;
L_80801468:
    // 0x80801468: jal         0x80801020
    // 0x8080146C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80801020_gcdialogexec(rdram, ctx);
        goto after_4;
    // 0x8080146C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_4:
    // 0x80801470: lw          $t5, 0x104($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X104);
    // 0x80801474: lh          $a0, 0x128($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X128);
    // 0x80801478: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080147C: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80801480: lh          $a1, 0x0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X0);
    // 0x80801484: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80801488: subu        $a3, $t8, $v0
    ctx->r7 = SUB32(ctx->r24, ctx->r2);
    // 0x8080148C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801490: jal         0x80087B08
    // 0x80801494: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    _gczoombox_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80801494: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_5:
    // 0x80801498: sw          $v0, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->r2;
L_8080149C:
    // 0x8080149C: beq         $s5, $zero, L_808014AC
    if (ctx->r21 == 0) {
        // 0x808014A0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808014AC;
    }
    // 0x808014A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808014A4: jal         0x80087BA0
    // 0x808014A8: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    _gczoombox_entrypoint_24(rdram, ctx);
        goto after_6;
    // 0x808014A8: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    after_6:
L_808014AC:
    // 0x808014AC: beq         $fp, $zero, L_80801508
    if (ctx->r30 == 0) {
        // 0x808014B0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80801508;
    }
    // 0x808014B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808014B4: jal         0x80087BA8
    // 0x808014B8: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    _gczoombox_entrypoint_25(rdram, ctx);
        goto after_7;
    // 0x808014B8: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    after_7:
    // 0x808014BC: b           L_8080150C
    // 0x808014C0: lbu         $t4, 0x15D($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X15D);
        goto L_8080150C;
    // 0x808014C0: lbu         $t4, 0x15D($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X15D);
L_808014C4:
    // 0x808014C4: lw          $a0, 0x168($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X168);
    // 0x808014C8: jal         0x80800000
    // 0x808014CC: lw          $a1, 0x16C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X16C);
    func_80800000_gcdialogexec(rdram, ctx);
        goto after_8;
    // 0x808014CC: lw          $a1, 0x16C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X16C);
    after_8:
    // 0x808014D0: beql        $v0, $zero, L_808014F0
    if (ctx->r2 == 0) {
        // 0x808014D4: lbu         $v0, 0x15F($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X15F);
            goto L_808014F0;
    }
    goto skip_3;
    // 0x808014D4: lbu         $v0, 0x15F($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X15F);
    skip_3:
    // 0x808014D8: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    // 0x808014DC: lw          $a1, 0x168($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X168);
    // 0x808014E0: lbu         $a2, 0x167($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X167);
    // 0x808014E4: jal         0x80087BF8
    // 0x808014E8: lw          $a3, 0x16C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X16C);
    _gczoombox_entrypoint_35(rdram, ctx);
        goto after_9;
    // 0x808014E8: lw          $a3, 0x16C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X16C);
    after_9:
    // 0x808014EC: lbu         $v0, 0x15F($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X15F);
L_808014F0:
    // 0x808014F0: srl         $t7, $v0, 6
    ctx->r15 = S32(U32(ctx->r2) >> 6);
    // 0x808014F4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x808014F8: sll         $t1, $t9, 6
    ctx->r9 = S32(ctx->r25 << 6);
    // 0x808014FC: andi        $t2, $v0, 0xFF3F
    ctx->r10 = ctx->r2 & 0XFF3F;
    // 0x80801500: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80801504: sb          $t3, 0x15F($s2)
    MEM_B(0X15F, ctx->r18) = ctx->r11;
L_80801508:
    // 0x80801508: lbu         $t4, 0x15D($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X15D);
L_8080150C:
    // 0x8080150C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80801510: b           L_80801594
    // 0x80801514: sb          $t5, 0x15D($s2)
    MEM_B(0X15D, ctx->r18) = ctx->r13;
        goto L_80801594;
    // 0x80801514: sb          $t5, 0x15D($s2)
    MEM_B(0X15D, ctx->r18) = ctx->r13;
L_80801518:
    // 0x80801518: beql        $at, $zero, L_80801560
    if (ctx->r1 == 0) {
        // 0x8080151C: lbu         $t2, 0x11C($s3)
        ctx->r10 = MEM_BU(ctx->r19, 0X11C);
            goto L_80801560;
    }
    goto skip_4;
    // 0x8080151C: lbu         $t2, 0x11C($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X11C);
    skip_4:
    // 0x80801520: lbu         $t6, 0x11C($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X11C);
    // 0x80801524: srl         $t8, $t6, 6
    ctx->r24 = S32(U32(ctx->r14) >> 6);
    // 0x80801528: beql        $t8, $zero, L_8080154C
    if (ctx->r24 == 0) {
        // 0x8080152C: sw          $zero, 0x120($s0)
        MEM_W(0X120, ctx->r16) = 0;
            goto L_8080154C;
    }
    goto skip_5;
    // 0x8080152C: sw          $zero, 0x120($s0)
    MEM_W(0X120, ctx->r16) = 0;
    skip_5:
    // 0x80801530: jal         0x80087B30
    // 0x80801534: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_10;
    // 0x80801534: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    after_10:
    // 0x80801538: lbu         $t7, 0x15D($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X15D);
    // 0x8080153C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80801540: b           L_8080154C
    // 0x80801544: sb          $t9, 0x15D($s2)
    MEM_B(0X15D, ctx->r18) = ctx->r25;
        goto L_8080154C;
    // 0x80801544: sb          $t9, 0x15D($s2)
    MEM_B(0X15D, ctx->r18) = ctx->r25;
    // 0x80801548: sw          $zero, 0x120($s0)
    MEM_W(0X120, ctx->r16) = 0;
L_8080154C:
    // 0x8080154C: lbu         $t0, 0x11C($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X11C);
    // 0x80801550: andi        $t1, $t0, 0xFF3F
    ctx->r9 = ctx->r8 & 0XFF3F;
    // 0x80801554: b           L_80801594
    // 0x80801558: sb          $t1, 0x11C($s3)
    MEM_B(0X11C, ctx->r19) = ctx->r9;
        goto L_80801594;
    // 0x80801558: sb          $t1, 0x11C($s3)
    MEM_B(0X11C, ctx->r19) = ctx->r9;
    // 0x8080155C: lbu         $t2, 0x11C($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X11C);
L_80801560:
    // 0x80801560: srl         $t3, $t2, 6
    ctx->r11 = S32(U32(ctx->r10) >> 6);
    // 0x80801564: beql        $t3, $zero, L_80801598
    if (ctx->r11 == 0) {
        // 0x80801568: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_80801598;
    }
    goto skip_6;
    // 0x80801568: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_6:
    // 0x8080156C: lbu         $v0, 0x15F($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X15F);
    // 0x80801570: lbu         $t4, 0x15D($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X15D);
    // 0x80801574: srl         $t6, $v0, 6
    ctx->r14 = S32(U32(ctx->r2) >> 6);
    // 0x80801578: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8080157C: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x80801580: andi        $t0, $v0, 0xFF3F
    ctx->r8 = ctx->r2 & 0XFF3F;
    // 0x80801584: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80801588: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8080158C: sb          $t5, 0x15D($s2)
    MEM_B(0X15D, ctx->r18) = ctx->r13;
    // 0x80801590: sb          $t1, 0x15F($s2)
    MEM_B(0X15F, ctx->r18) = ctx->r9;
L_80801594:
    // 0x80801594: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_80801598:
    // 0x80801598: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080159C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808015A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x808015A4: bne         $s6, $at, L_8080136C
    if (ctx->r22 != ctx->r1) {
        // 0x808015A8: addiu       $s7, $s7, 0x2
        ctx->r23 = ADD32(ctx->r23, 0X2);
            goto L_8080136C;
    }
    // 0x808015A8: addiu       $s7, $s7, 0x2
    ctx->r23 = ADD32(ctx->r23, 0X2);
    // 0x808015AC: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x808015B0: lh          $t4, 0x118($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X118);
    // 0x808015B4: sh          $t2, 0x162($s2)
    MEM_H(0X162, ctx->r18) = ctx->r10;
    // 0x808015B8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x808015BC: bgez        $t4, L_808015D4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808015C0: sh          $t3, 0x15A($s2)
        MEM_H(0X15A, ctx->r18) = ctx->r11;
            goto L_808015D4;
    }
    // 0x808015C0: sh          $t3, 0x15A($s2)
    MEM_H(0X15A, ctx->r18) = ctx->r11;
    // 0x808015C4: lbu         $t5, 0x15E($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X15E);
    // 0x808015C8: andi        $t6, $t5, 0xFF7F
    ctx->r14 = ctx->r13 & 0XFF7F;
    // 0x808015CC: b           L_808015E0
    // 0x808015D0: sb          $t6, 0x15E($s2)
    MEM_B(0X15E, ctx->r18) = ctx->r14;
        goto L_808015E0;
    // 0x808015D0: sb          $t6, 0x15E($s2)
    MEM_B(0X15E, ctx->r18) = ctx->r14;
L_808015D4:
    // 0x808015D4: lbu         $t7, 0x15E($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X15E);
    // 0x808015D8: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x808015DC: sb          $t9, 0x15E($s2)
    MEM_B(0X15E, ctx->r18) = ctx->r25;
L_808015E0:
    // 0x808015E0: lbu         $t1, 0x15E($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X15E);
    // 0x808015E4: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x808015E8: jal         0x800A9C98
    // 0x808015EC: sb          $t2, 0x15E($s2)
    MEM_B(0X15E, ctx->r18) = ctx->r10;
    func_800A9C98(rdram, ctx);
        goto after_11;
    // 0x808015EC: sb          $t2, 0x15E($s2)
    MEM_B(0X15E, ctx->r18) = ctx->r10;
    after_11:
    // 0x808015F0: beq         $v0, $zero, L_80801614
    if (ctx->r2 == 0) {
        // 0x808015F4: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_80801614;
    }
    // 0x808015F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808015F8: lw          $t3, 0x15C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X15C);
    // 0x808015FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801600: sll         $t5, $t3, 20
    ctx->r13 = S32(ctx->r11 << 20);
    // 0x80801604: bgezl       $t5, L_80801618
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80801608: sb          $t8, 0x160($s2)
        MEM_B(0X160, ctx->r18) = ctx->r24;
            goto L_80801618;
    }
    goto skip_7;
    // 0x80801608: sb          $t8, 0x160($s2)
    MEM_B(0X160, ctx->r18) = ctx->r24;
    skip_7:
    // 0x8080160C: b           L_80801618
    // 0x80801610: sb          $t6, 0x160($s2)
    MEM_B(0X160, ctx->r18) = ctx->r14;
        goto L_80801618;
    // 0x80801610: sb          $t6, 0x160($s2)
    MEM_B(0X160, ctx->r18) = ctx->r14;
L_80801614:
    // 0x80801614: sb          $t8, 0x160($s2)
    MEM_B(0X160, ctx->r18) = ctx->r24;
L_80801618:
    // 0x80801618: jal         0x800A9C98
    // 0x8080161C: nop

    func_800A9C98(rdram, ctx);
        goto after_12;
    // 0x8080161C: nop

    after_12:
    // 0x80801620: beq         $v0, $zero, L_80801640
    if (ctx->r2 == 0) {
        // 0x80801624: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80801640;
    }
    // 0x80801624: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801628: lw          $t7, 0x15C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X15C);
    // 0x8080162C: sll         $t0, $t7, 20
    ctx->r8 = S32(ctx->r15 << 20);
    // 0x80801630: bgez        $t0, L_80801640
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80801634: nop
    
            goto L_80801640;
    }
    // 0x80801634: nop

    // 0x80801638: b           L_80801640
    // 0x8080163C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_80801640;
    // 0x8080163C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_80801640:
    // 0x80801640: jal         0x80800A50
    // 0x80801644: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_13;
    // 0x80801644: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x80801648: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8080164C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801650: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801654: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x80801658: andi        $t3, $t1, 0x80
    ctx->r11 = ctx->r9 & 0X80;
    // 0x8080165C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801660: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801664: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80801668: jal         0x808011A4
    // 0x8080166C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    func_808011A4_gcdialogexec(rdram, ctx);
        goto after_14;
    // 0x8080166C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_14:
    // 0x80801670: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80801674: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801678: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8080167C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80801680: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80801684: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80801688: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8080168C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80801690: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80801694: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80801698: jr          $ra
    // 0x8080169C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080169C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _glsplinefind_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088498: syscall     687
    recomp_syscall_handler(rdram, ctx, 0x80088498);
    return;
    // 0x8008849C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800E9C_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E9C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800EA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800EA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800EA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800EAC: lui         $a1, 0x400C
    ctx->r5 = S32(0X400C << 16);
    // 0x80800EB0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800EB4: jal         0x800D9154
    // 0x80800EB8: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9154(rdram, ctx);
        goto after_0;
    // 0x80800EB8: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800EBC: beq         $v0, $zero, L_80800ED4
    if (ctx->r2 == 0) {
        // 0x80800EC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800ED4;
    }
    // 0x80800EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X16A0) << 16);
    // 0x80800EC8: addiu       $a2, $a2, 0x16A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X16A0));
    // 0x80800ECC: jal         0x80089D18
    // 0x80800ED0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800ED0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_1:
L_80800ED4:
    // 0x80800ED4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X1690) << 16);
    // 0x80800ED8: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800EDC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800EE0: addiu       $a2, $a2, 0x1690
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X1690));
    // 0x80800EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE8: jal         0x80089D20
    // 0x80800EEC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800EEC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x80800EF0: beq         $v0, $zero, L_80800FD4
    if (ctx->r2 == 0) {
        // 0x80800EF4: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_80800FD4;
    }
    // 0x80800EF4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800EF8: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x80800EFC: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80800F00: jal         0x800EFA4C
    // 0x80800F04: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80800F04: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    after_3:
    // 0x80800F08: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800F0C: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x80800F10: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80800F14: jal         0x800EFA4C
    // 0x80800F18: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800F18: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    after_4:
    // 0x80800F1C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800F20: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x80800F24: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80800F28: jal         0x800EFA4C
    // 0x80800F2C: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x80800F2C: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    after_5:
    // 0x80800F30: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800F34: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800F38: jal         0x800EF1B8
    // 0x80800F3C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x80800F3C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_6:
    // 0x80800F40: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800F44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800F48: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800F4C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800F50: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x80800F54: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800F58: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800F5C: jal         0x800EF1B8
    // 0x80800F60: nop

    func_800EF1B8(rdram, ctx);
        goto after_7;
    // 0x80800F60: nop

    after_7:
    // 0x80800F64: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800F68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800F6C: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800F70: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800F74: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x80800F78: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800F7C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800F80: jal         0x800EF1B8
    // 0x80800F84: nop

    func_800EF1B8(rdram, ctx);
        goto after_8;
    // 0x80800F84: nop

    after_8:
    // 0x80800F88: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800F8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800F90: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800F94: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1020, 0X16AC) << 16);
    // 0x80800F98: addiu       $s0, $s0, 0x16AC
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1020, 0X16AC));
    // 0x80800F9C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800FA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80800FA4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800FA8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800FAC: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x80800FB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800FB4: jal         0x80800614
    // 0x80800FB8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    func_80800614_chtiptup(rdram, ctx);
        goto after_9;
    // 0x80800FB8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_9:
    // 0x80800FBC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800FC0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800FC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800FC8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80800FCC: jal         0x80800614
    // 0x80800FD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80800614_chtiptup(rdram, ctx);
        goto after_10;
    // 0x80800FD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_10:
L_80800FD4:
    // 0x80800FD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800FD8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800FDC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800FE0: jr          $ra
    // 0x80800FE4: nop

    return;
    // 0x80800FE4: nop

;}
RECOMP_FUNC void func_80800FD0_subaddiestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FD8: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800FDC: addiu       $v0, $a0, 0xB0
    ctx->r2 = ADD32(ctx->r4, 0XB0);
    // 0x80800FE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800FE4: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80800FE8: beql        $t7, $zero, L_80800FF8
    if (ctx->r15 == 0) {
        // 0x80800FEC: lw          $t8, 0x94($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X94);
            goto L_80800FF8;
    }
    goto skip_0;
    // 0x80800FEC: lw          $t8, 0x94($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X94);
    skip_0:
    // 0x80800FF0: addiu       $a1, $v0, 0x48
    ctx->r5 = ADD32(ctx->r2, 0X48);
    // 0x80800FF4: lw          $t8, 0x94($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X94);
L_80800FF8:
    // 0x80800FF8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800FFC: srl         $t0, $t9, 22
    ctx->r8 = S32(U32(ctx->r25) >> 22);
    // 0x80801000: beq         $t0, $zero, L_8080100C
    if (ctx->r8 == 0) {
        // 0x80801004: nop
    
            goto L_8080100C;
    }
    // 0x80801004: nop

    // 0x80801008: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
L_8080100C:
    // 0x8080100C: jal         0x80800F98
    // 0x80801010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800F98_subaddiestore(rdram, ctx);
        goto after_0;
    // 0x80801010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801014: beq         $v0, $zero, L_80801040
    if (ctx->r2 == 0) {
        // 0x80801018: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80801040;
    }
    // 0x80801018: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080101C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80801020: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80801024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801028: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8080102C:
    // 0x8080102C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80801030: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80801034: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80801038: bne         $v0, $a0, L_8080102C
    if (ctx->r2 != ctx->r4) {
        // 0x8080103C: addu        $a1, $t1, $a1
        ctx->r5 = ADD32(ctx->r9, ctx->r5);
            goto L_8080102C;
    }
    // 0x8080103C: addu        $a1, $t1, $a1
    ctx->r5 = ADD32(ctx->r9, ctx->r5);
L_80801040:
    // 0x80801040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801044: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801048: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8080104C: jr          $ra
    // 0x80801050: nop

    return;
    // 0x80801050: nop

;}
RECOMP_FUNC void _suexpressjoint_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089768: syscall     794
    recomp_syscall_handler(rdram, ctx, 0x80089768);
    return;
    // 0x8008976C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void cheggsplode_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080065C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800660: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800664: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800668: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8080066C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800670: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800674: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800678: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8080067C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800680: jal         0x80108474
    // 0x80800684: addiu       $a0, $zero, 0x2B2
    ctx->r4 = ADD32(0, 0X2B2);
    func_80108474(rdram, ctx);
        goto after_0;
    // 0x80800684: addiu       $a0, $zero, 0x2B2
    ctx->r4 = ADD32(0, 0X2B2);
    after_0:
    // 0x80800688: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080068C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800690: jal         0x80100094
    // 0x80800694: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800694: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800698: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080069C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808006A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808006A4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x808006A8: sh          $a2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r6;
    // 0x808006AC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x808006B0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808006B4: sltiu       $t8, $t7, 0x1
    ctx->r24 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x808006B8: bne         $a2, $at, L_808006E0
    if (ctx->r6 != ctx->r1) {
        // 0x808006BC: sh          $t8, 0x6($v0)
        MEM_H(0X6, ctx->r2) = ctx->r24;
            goto L_808006E0;
    }
    // 0x808006BC: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x808006C0: lbu         $t9, 0x72($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X72);
    // 0x808006C4: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x808006C8: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x808006CC: sb          $t1, 0x72($v1)
    MEM_B(0X72, ctx->r3) = ctx->r9;
    // 0x808006D0: jal         0x80800548
    // 0x808006D4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80800548_cheggsplode(rdram, ctx);
        goto after_2;
    // 0x808006D4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x808006D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808006DC: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
L_808006E0:
    // 0x808006E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006E8: jr          $ra
    // 0x808006EC: nop

    return;
    // 0x808006EC: nop

;}
RECOMP_FUNC void _chbounce_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085908: syscall     180
    recomp_syscall_handler(rdram, ctx, 0x80085908);
    return;
    // 0x8008590C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_808005AC_rtlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808005B8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x808005BC: jal         0x800C8898
    // 0x808005C0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800C8898(rdram, ctx);
        goto after_0;
    // 0x808005C0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808005C4: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x808005C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005CC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808005D0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808005D4: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x808005D8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808005DC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808005E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005E4: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x808005E8: nop

    // 0x808005EC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x808005F0: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808005F4: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x808005F8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808005FC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80800600: nop

    // 0x80800604: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80800608: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080060C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800610: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800614: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80800618: nop

    // 0x8080061C: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    // 0x80800620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800624: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800628: jr          $ra
    // 0x8080062C: nop

    return;
    // 0x8080062C: nop

;}
RECOMP_FUNC void heap_largest_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001B3F8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001B3FC: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8001B400: addiu       $s3, $s3, -0x1670
    ctx->r19 = ADD32(ctx->r19, -0X1670);
    // 0x8001B404: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8001B408: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001B40C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001B410: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001B414: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001B418: lw          $s0, 0x14($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X14);
    // 0x8001B41C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001B420: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8001B424: jal         0x8001B3E8
    // 0x8001B428: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    heap_bytes_allocated(rdram, ctx);
        goto after_0;
    // 0x8001B428: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_0:
    // 0x8001B42C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8001B430: addiu       $t7, $s0, 0x20
    ctx->r15 = ADD32(ctx->r16, 0X20);
    // 0x8001B434: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8001B438: beql        $t7, $t9, L_8001B488
    if (ctx->r15 == ctx->r25) {
        // 0x8001B43C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001B488;
    }
    goto skip_0;
    // 0x8001B43C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8001B440: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
L_8001B444:
    // 0x8001B444: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8001B448: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001B44C: subu        $v0, $t0, $s0
    ctx->r2 = SUB32(ctx->r8, ctx->r16);
    // 0x8001B450: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001B454: beql        $at, $zero, L_8001B468
    if (ctx->r1 == 0) {
        // 0x8001B458: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8001B468;
    }
    goto skip_1;
    // 0x8001B458: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    skip_1:
    // 0x8001B45C: b           L_8001B468
    // 0x8001B460: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
        goto L_8001B468;
    // 0x8001B460: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x8001B464: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_8001B468:
    // 0x8001B468: jal         0x8001B3E8
    // 0x8001B46C: lw          $s0, 0x14($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X14);
    heap_bytes_allocated(rdram, ctx);
        goto after_1;
    // 0x8001B46C: lw          $s0, 0x14($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X14);
    after_1:
    // 0x8001B470: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8001B474: addiu       $t1, $s0, 0x20
    ctx->r9 = ADD32(ctx->r16, 0X20);
    // 0x8001B478: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8001B47C: bnel        $t1, $t3, L_8001B444
    if (ctx->r9 != ctx->r11) {
        // 0x8001B480: lw          $t0, 0x4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X4);
            goto L_8001B444;
    }
    goto skip_2;
    // 0x8001B480: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x8001B484: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001B488:
    // 0x8001B488: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8001B48C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B490: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001B494: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001B498: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001B49C: jr          $ra
    // 0x8001B4A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001B4A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80804AA8_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804AB0: jal         0x8080009C
    // 0x80804AB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080009C_chcollballcontrol(rdram, ctx);
        goto after_0;
    // 0x80804AB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80804AB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804ABC: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80804AC0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80804AC4: nop

    // 0x80804AC8: bc1fl       L_80804AEC
    if (!c1cs) {
        // 0x80804ACC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80804AEC;
    }
    goto skip_0;
    // 0x80804ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80804AD0: jal         0x808000F4
    // 0x80804AD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000F4_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x80804AD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80804AD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804ADC: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80804AE0: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80804AE4: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x80804AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804AEC:
    // 0x80804AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804AF0: jr          $ra
    // 0x80804AF4: nop

    return;
    // 0x80804AF4: nop

;}
RECOMP_FUNC void chlavaarchgrill3switches_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2036, 0X1F0) << 16);
    // 0x8080011C: jr          $ra
    // 0x80800120: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2036, 0X1F0));
    return;
    // 0x80800120: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2036, 0X1F0));
;}
RECOMP_FUNC void func_80800AB8_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800ABC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800AC0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800AC4: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800AC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800ACC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800AD0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800AD4: sltiu       $at, $t8, 0xD
    ctx->r1 = ctx->r24 < 0XD ? 1 : 0;
    // 0x80800AD8: beq         $at, $zero, L_80800FF8
    if (ctx->r1 == 0) {
        // 0x80800ADC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800FF8;
    }
    // 0x80800ADC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800AE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2276, 0X1924) << 16);
    // 0x80800AE4: addu        $at, $at, $t8
    gpr jr_addend_80800AEC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800AE8: lw          $t8, 0x1924($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2276, 0X1924));
    // 0x80800AEC: jr          $t8
    // 0x80800AF0: nop

    switch (jr_addend_80800AEC >> 2) {
        case 0: goto L_80800AF4; break;
        case 1: goto L_80800FF8; break;
        case 2: goto L_80800B30; break;
        case 3: goto L_80800B5C; break;
        case 4: goto L_80800FAC; break;
        case 5: goto L_80800BA4; break;
        case 6: goto L_80800D68; break;
        case 7: goto L_80800DA0; break;
        case 8: goto L_80800F70; break;
        case 9: goto L_80800D88; break;
        case 10: goto L_80800FF8; break;
        case 11: goto L_80800FF8; break;
        case 12: goto L_80800FAC; break;
        default: switch_error(__func__, 0x80800AEC, 0x80801924);
    }
    // 0x80800AF0: nop

L_80800AF4:
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF8: jal         0x80100094
    // 0x80800AFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800AFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B04: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800B08: jal         0x8008A050
    // 0x80800B0C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _subaddiefx_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800B0C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x80800B10: jal         0x800D90A4
    // 0x80800B14: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_2;
    // 0x80800B14: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x80800B18: beq         $v0, $zero, L_80800FF8
    if (ctx->r2 == 0) {
        // 0x80800B1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FF8;
    }
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B20: jal         0x8080130C
    // 0x80800B24: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080130C_chfactorybattery(rdram, ctx);
        goto after_3;
    // 0x80800B24: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80800B28: b           L_80800FF8
    // 0x80800B2C: nop

        goto L_80800FF8;
    // 0x80800B2C: nop

L_80800B30:
    // 0x80800B30: jal         0x80800678
    // 0x80800B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800678_chfactorybattery(rdram, ctx);
        goto after_4;
    // 0x80800B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B3C: jal         0x8008A500
    // 0x80800B40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddietaxi_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800B40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80800B44: beq         $v0, $zero, L_80800FF8
    if (ctx->r2 == 0) {
        // 0x80800B48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FF8;
    }
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B4C: jal         0x8080130C
    // 0x80800B50: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080130C_chfactorybattery(rdram, ctx);
        goto after_6;
    // 0x80800B50: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80800B54: b           L_80800FF8
    // 0x80800B58: nop

        goto L_80800FF8;
    // 0x80800B58: nop

L_80800B5C:
    // 0x80800B5C: jal         0x80800678
    // 0x80800B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800678_chfactorybattery(rdram, ctx);
        goto after_7;
    // 0x80800B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B68: jal         0x8008A550
    // 0x80800B6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddietaxi_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800B6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x80800B70: beq         $v0, $zero, L_80800FF8
    if (ctx->r2 == 0) {
        // 0x80800B74: nop
    
            goto L_80800FF8;
    }
    // 0x80800B74: nop

    // 0x80800B78: jal         0x80800678
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800678_chfactorybattery(rdram, ctx);
        goto after_9;
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B84: jal         0x8008A520
    // 0x80800B88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddietaxi_entrypoint_5(rdram, ctx);
        goto after_10;
    // 0x80800B88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x80800B8C: beq         $v0, $zero, L_80800FF8
    if (ctx->r2 == 0) {
        // 0x80800B90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FF8;
    }
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B94: jal         0x8080130C
    // 0x80800B98: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080130C_chfactorybattery(rdram, ctx);
        goto after_11;
    // 0x80800B98: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_11:
    // 0x80800B9C: b           L_80800FF8
    // 0x80800BA0: nop

        goto L_80800FF8;
    // 0x80800BA0: nop

L_80800BA4:
    // 0x80800BA4: jal         0x80101F24
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_12;
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800BAC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2276, 0X1B88) << 16);
    // 0x80800BB0: addiu       $a1, $a1, 0x1B88
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2276, 0X1B88));
    // 0x80800BB4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800BB8: jal         0x800F3780
    // 0x80800BBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800F3780(rdram, ctx);
        goto after_13;
    // 0x80800BBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_13:
    // 0x80800BC0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC8: jal         0x80100094
    // 0x80800BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_14;
    // 0x80800BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800BD0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800BD4: jal         0x80089F78
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800BDC: beql        $v0, $zero, L_80800D10
    if (ctx->r2 == 0) {
        // 0x80800BE0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800D10;
    }
    goto skip_0;
    // 0x80800BE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80800BE4: jal         0x8010C500
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_16;
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800BEC: beq         $v0, $zero, L_80800C90
    if (ctx->r2 == 0) {
        // 0x80800BF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C90;
    }
    // 0x80800BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BF4: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x80800BF8: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x80800BFC: srl         $t9, $a1, 26
    ctx->r25 = S32(U32(ctx->r5) >> 26);
    // 0x80800C00: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80800C04: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80800C08: jal         0x800CC63C
    // 0x80800C0C: addiu       $a1, $t9, -0x1
    ctx->r5 = ADD32(ctx->r25, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_17;
    // 0x80800C0C: addiu       $a1, $t9, -0x1
    ctx->r5 = ADD32(ctx->r25, -0X1);
    after_17:
    // 0x80800C10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C14: jal         0x800F1DF4
    // 0x80800C18: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_18;
    // 0x80800C18: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_18:
    // 0x80800C1C: jal         0x800F54E4
    // 0x80800C20: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_800F54E4(rdram, ctx);
        goto after_19;
    // 0x80800C20: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x80800C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C28: jal         0x8010CD50
    // 0x80800C2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010CD50(rdram, ctx);
        goto after_20;
    // 0x80800C2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_20:
    // 0x80800C30: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800C34: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C38: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800C3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C40: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800C44: sub.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800C48: add.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80800C4C: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x80800C50: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800C54: nop

    // 0x80800C58: bc1fl       L_80800C70
    if (!c1cs) {
        // 0x80800C5C: sub.s       $f2, $f16, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f14.fl;
            goto L_80800C70;
    }
    goto skip_1;
    // 0x80800C5C: sub.s       $f2, $f16, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f14.fl;
    skip_1:
    // 0x80800C60: swc1        $f12, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f12.u32l;
    // 0x80800C64: b           L_80800CC8
    // 0x80800C68: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
        goto L_80800CC8;
    // 0x80800C68: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800C6C: sub.s       $f2, $f16, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f14.fl;
L_80800C70:
    // 0x80800C70: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800C74: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800C78: nop

    // 0x80800C7C: bc1fl       L_80800CCC
    if (!c1cs) {
        // 0x80800C80: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80800CCC;
    }
    goto skip_2;
    // 0x80800C80: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    skip_2:
    // 0x80800C84: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x80800C88: b           L_80800CC8
    // 0x80800C8C: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
        goto L_80800CC8;
    // 0x80800C8C: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
L_80800C90:
    // 0x80800C90: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x80800C94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2276, 0X1958) << 16);
    // 0x80800C98: lwc1        $f6, 0x1958($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2276, 0X1958));
    // 0x80800C9C: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80800CA0: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80800CA4: srl         $t0, $a2, 7
    ctx->r8 = S32(U32(ctx->r6) >> 7);
    // 0x80800CA8: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80800CAC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80800CB0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800CB4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800CB8: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x80800CBC: jal         0x80089F88
    // 0x80800CC0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_21;
    // 0x80800CC0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x80800CC4: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
L_80800CC8:
    // 0x80800CC8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_80800CCC:
    // 0x80800CCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800CD0: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800CD4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800CD8: addiu       $t3, $zero, 0x4803
    ctx->r11 = ADD32(0, 0X4803);
    // 0x80800CDC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800CE8: jal         0x80089F90
    // 0x80800CEC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_22;
    // 0x80800CEC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_22:
    // 0x80800CF0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80800CF4: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x80800CF8: lhu         $t6, 0x6($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X6);
    // 0x80800CFC: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x80800D00: sll         $t8, $t6, 7
    ctx->r24 = S32(ctx->r14 << 7);
    // 0x80800D04: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800D08: sh          $t1, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r9;
    // 0x80800D0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800D10:
    // 0x80800D10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800D14: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800D18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800D1C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800D20: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x80800D24: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80800D28: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800D2C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800D30: srl         $t2, $a2, 7
    ctx->r10 = S32(U32(ctx->r6) >> 7);
    // 0x80800D34: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D3C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800D40: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800D44: jal         0x80089F80
    // 0x80800D48: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_23;
    // 0x80800D48: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_23:
    // 0x80800D4C: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x80800D50: ori         $a1, $a1, 0x5425
    ctx->r5 = ctx->r5 | 0X5425;
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D58: jal         0x8010C3A8
    // 0x80800D5C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    func_8010C3A8(rdram, ctx);
        goto after_24;
    // 0x80800D5C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    after_24:
    // 0x80800D60: b           L_80800FF8
    // 0x80800D64: nop

        goto L_80800FF8;
    // 0x80800D64: nop

L_80800D68:
    // 0x80800D68: jal         0x800D90A4
    // 0x80800D6C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_25;
    // 0x80800D6C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_25:
    // 0x80800D70: beq         $v0, $zero, L_80800FF8
    if (ctx->r2 == 0) {
        // 0x80800D74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FF8;
    }
    // 0x80800D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D78: jal         0x8080130C
    // 0x80800D7C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080130C_chfactorybattery(rdram, ctx);
        goto after_26;
    // 0x80800D7C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_26:
    // 0x80800D80: b           L_80800FF8
    // 0x80800D84: nop

        goto L_80800FF8;
    // 0x80800D84: nop

L_80800D88:
    // 0x80800D88: jal         0x800D90A4
    // 0x80800D8C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_27;
    // 0x80800D8C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_27:
    // 0x80800D90: beq         $v0, $zero, L_80800DA0
    if (ctx->r2 == 0) {
        // 0x80800D94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DA0;
    }
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D98: jal         0x8080130C
    // 0x80800D9C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8080130C_chfactorybattery(rdram, ctx);
        goto after_28;
    // 0x80800D9C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_28:
L_80800DA0:
    // 0x80800DA0: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DA8: sll         $t5, $t3, 11
    ctx->r13 = S32(ctx->r11 << 11);
    // 0x80800DAC: bgez        $t5, L_80800E2C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800DB0: nop
    
            goto L_80800E2C;
    }
    // 0x80800DB0: nop

    // 0x80800DB4: jal         0x80089BD8
    // 0x80800DB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_29;
    // 0x80800DB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80800DBC: beql        $v0, $zero, L_80800E20
    if (ctx->r2 == 0) {
        // 0x80800DC0: lbu         $t6, 0x79($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X79);
            goto L_80800E20;
    }
    goto skip_3;
    // 0x80800DC0: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    skip_3:
    // 0x80800DC4: jal         0x800D90A4
    // 0x80800DC8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_30;
    // 0x80800DC8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_30:
    // 0x80800DCC: beq         $v0, $zero, L_80800DFC
    if (ctx->r2 == 0) {
        // 0x80800DD0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800DFC;
    }
    // 0x80800DD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800DD4: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800DD8: lbu         $t9, 0x79($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X79);
    // 0x80800DDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800DE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800DE4: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800DE8: andi        $t8, $t9, 0xFF0F
    ctx->r24 = ctx->r25 & 0XFF0F;
    // 0x80800DEC: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x80800DF0: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
    // 0x80800DF4: b           L_80800E80
    // 0x80800DF8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80800E80;
    // 0x80800DF8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800DFC:
    // 0x80800DFC: jal         0x800DC128
    // 0x80800E00: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_31;
    // 0x80800E00: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_31:
    // 0x80800E04: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x80800E08: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x80800E0C: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x80800E10: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800E14: b           L_80800E80
    // 0x80800E18: sb          $t5, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r13;
        goto L_80800E80;
    // 0x80800E18: sb          $t5, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r13;
    // 0x80800E1C: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
L_80800E20:
    // 0x80800E20: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80800E24: b           L_80800E80
    // 0x80800E28: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
        goto L_80800E80;
    // 0x80800E28: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
L_80800E2C:
    // 0x80800E2C: jal         0x800D90A4
    // 0x80800E30: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_32;
    // 0x80800E30: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_32:
    // 0x80800E34: beq         $v0, $zero, L_80800E80
    if (ctx->r2 == 0) {
        // 0x80800E38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E80;
    }
    // 0x80800E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E3C: jal         0x80089BD8
    // 0x80800E40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_33;
    // 0x80800E40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x80800E44: beq         $v0, $zero, L_80800E80
    if (ctx->r2 == 0) {
        // 0x80800E48: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80800E80;
    }
    // 0x80800E48: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800E4C: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800E50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800E54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800E58: ori         $t0, $t8, 0x10
    ctx->r8 = ctx->r24 | 0X10;
    // 0x80800E5C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800E60: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800E64: jal         0x800DC128
    // 0x80800E68: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_800DC128(rdram, ctx);
        goto after_34;
    // 0x80800E68: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_34:
    // 0x80800E6C: lbu         $t4, 0x79($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X79);
    // 0x80800E70: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x80800E74: andi        $t5, $t4, 0xFF0F
    ctx->r13 = ctx->r12 & 0XFF0F;
    // 0x80800E78: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x80800E7C: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
L_80800E80:
    // 0x80800E80: jal         0x80089BC0
    // 0x80800E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_35;
    // 0x80800E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80800E88: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800E8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E94: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800E98: jal         0x80101F24
    // 0x80800E9C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    func_80101F24(rdram, ctx);
        goto after_36;
    // 0x80800E9C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_36:
    // 0x80800EA0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800EA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800EA8: nop

    // 0x80800EAC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800EB0: nop

    // 0x80800EB4: bc1f        L_80800FF8
    if (!c1cs) {
        // 0x80800EB8: nop
    
            goto L_80800FF8;
    }
    // 0x80800EB8: nop

    // 0x80800EBC: jal         0x80102CCC
    // 0x80800EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102CCC(rdram, ctx);
        goto after_37;
    // 0x80800EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800EC4: bne         $v0, $zero, L_80800EE4
    if (ctx->r2 != 0) {
        // 0x80800EC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EE4;
    }
    // 0x80800EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ECC: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80800ED0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800ED4: jal         0x80102BAC
    // 0x80800ED8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    func_80102BAC(rdram, ctx);
        goto after_38;
    // 0x80800ED8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_38:
    // 0x80800EDC: b           L_80800FF8
    // 0x80800EE0: nop

        goto L_80800FF8;
    // 0x80800EE0: nop

L_80800EE4:
    // 0x80800EE4: jal         0x80101F24
    // 0x80800EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_39;
    // 0x80800EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80800EEC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800EF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800EF4: nop

    // 0x80800EF8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800EFC: nop

    // 0x80800F00: bc1fl       L_80800F2C
    if (!c1cs) {
        // 0x80800F04: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800F2C;
    }
    goto skip_4;
    // 0x80800F04: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_4:
    // 0x80800F08: jal         0x80101F24
    // 0x80800F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_40;
    // 0x80800F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80800F10: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800F14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800F18: nop

    // 0x80800F1C: sub.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80800F20: b           L_80800F30
    // 0x80800F24: add.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f2.fl;
        goto L_80800F30;
    // 0x80800F24: add.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80800F28: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800F2C:
    // 0x80800F2C: nop

L_80800F30:
    // 0x80800F30: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800F34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800F38: nop

    // 0x80800F3C: mul.s       $f12, $f14, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80800F40: jal         0x80013970
    // 0x80800F44: nop

    func_80013970(rdram, ctx);
        goto after_41;
    // 0x80800F44: nop

    after_41:
    // 0x80800F48: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800F4C: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x80800F50: ori         $a1, $a1, 0x1005
    ctx->r5 = ctx->r5 | 0X1005;
    // 0x80800F54: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F5C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80800F60: jal         0x8010BA80
    // 0x80800F64: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    func_8010BA80(rdram, ctx);
        goto after_42;
    // 0x80800F64: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_42:
    // 0x80800F68: b           L_80800FF8
    // 0x80800F6C: nop

        goto L_80800FF8;
    // 0x80800F6C: nop

L_80800F70:
    // 0x80800F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F74: jal         0x80100094
    // 0x80800F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_43;
    // 0x80800F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x80800F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F80: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800F84: jal         0x8008A050
    // 0x80800F88: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _subaddiefx_entrypoint_0(rdram, ctx);
        goto after_44;
    // 0x80800F88: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_44:
    // 0x80800F8C: jal         0x800D90A4
    // 0x80800F90: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_45;
    // 0x80800F90: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_45:
    // 0x80800F94: beq         $v0, $zero, L_80800FF8
    if (ctx->r2 == 0) {
        // 0x80800F98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FF8;
    }
    // 0x80800F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F9C: jal         0x8080130C
    // 0x80800FA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8080130C_chfactorybattery(rdram, ctx);
        goto after_46;
    // 0x80800FA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_46:
    // 0x80800FA4: b           L_80800FF8
    // 0x80800FA8: nop

        goto L_80800FF8;
    // 0x80800FA8: nop

L_80800FAC:
    // 0x80800FAC: jal         0x80103EAC
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_47;
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80800FB4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800FB8: jal         0x80103EF4
    // 0x80800FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_48;
    // 0x80800FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x80800FC0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800FC4: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800FC8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800FCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800FD0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800FD4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800FD8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800FDC: jal         0x8010C9FC
    // 0x80800FE0: nop

    func_8010C9FC(rdram, ctx);
        goto after_49;
    // 0x80800FE0: nop

    after_49:
    // 0x80800FE4: beq         $v0, $zero, L_80800FF8
    if (ctx->r2 == 0) {
        // 0x80800FE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FF8;
    }
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FEC: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80800FF0: jal         0x8010108C
    // 0x80800FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_50;
    // 0x80800FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_50:
L_80800FF8:
    // 0x80800FF8: jal         0x808009C8
    // 0x80800FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009C8_chfactorybattery(rdram, ctx);
        goto after_51;
    // 0x80800FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80801000: jal         0x80800948
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800948_chfactorybattery(rdram, ctx);
        goto after_52;
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80801008: jal         0x808008C8
    // 0x8080100C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008C8_chfactorybattery(rdram, ctx);
        goto after_53;
    // 0x8080100C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80801010: jal         0x80800760
    // 0x80801014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800760_chfactorybattery(rdram, ctx);
        goto after_54;
    // 0x80801014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x80801018: jal         0x80800678
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800678_chfactorybattery(rdram, ctx);
        goto after_55;
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80801020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801024: jal         0x8008A540
    // 0x80801028: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddietaxi_entrypoint_9(rdram, ctx);
        goto after_56;
    // 0x80801028: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_56:
    // 0x8080102C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801030: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801034: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801038: jr          $ra
    // 0x8080103C: nop

    return;
    // 0x8080103C: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084258: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084258);
    return;
    // 0x8008425C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void _gcstatusDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088358: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088358);
    return;
    // 0x8008835C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800374_chstarspinnerctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080037C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800380: jal         0x800DA298
    // 0x80800384: addiu       $a0, $zero, 0x679
    ctx->r4 = ADD32(0, 0X679);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800384: addiu       $a0, $zero, 0x679
    ctx->r4 = ADD32(0, 0X679);
    after_0:
    // 0x80800388: beql        $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x8080038C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003AC;
    }
    goto skip_0;
    // 0x8080038C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800390: jal         0x8010A570
    // 0x80800394: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x80800394: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800398: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080039C: lbu         $t8, 0x65($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X65);
    // 0x808003A0: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x808003A4: sb          $t9, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r25;
    // 0x808003A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003AC:
    // 0x808003AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003B0: jr          $ra
    // 0x808003B4: nop

    return;
    // 0x808003B4: nop

;}
RECOMP_FUNC void chrainripples_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1196, 0X290) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x290
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1196, 0X290));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x290
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1196, 0X290));
;}
RECOMP_FUNC void func_800BA8F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA8F8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800BA8FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BA900: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BA904: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BA908: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800BA90C: nop

    // 0x800BA910: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800BA914: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BA918: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BA91C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800BA920: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BA924: sh          $t7, 0xA2($a0)
    MEM_H(0XA2, ctx->r4) = ctx->r15;
    // 0x800BA928: jr          $ra
    // 0x800BA92C: sh          $t9, 0xA4($a0)
    MEM_H(0XA4, ctx->r4) = ctx->r25;
    return;
    // 0x800BA92C: sh          $t9, 0xA4($a0)
    MEM_H(0XA4, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_8080000C_chbigtopticket(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8080010C_chelectricfence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800110: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80800114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800118: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080011C: beq         $a1, $at, L_80800138
    if (ctx->r5 == ctx->r1) {
        // 0x80800120: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80800138;
    }
    // 0x80800120: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800124: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800128: beq         $a1, $at, L_80800184
    if (ctx->r5 == ctx->r1) {
        // 0x8080012C: nop
    
            goto L_80800184;
    }
    // 0x8080012C: nop

    // 0x80800130: b           L_808001D4
    // 0x80800134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001D4;
    // 0x80800134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800138:
    // 0x80800138: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080013C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800140: jal         0x800EC75C
    // 0x80800144: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EC75C(rdram, ctx);
        goto after_0;
    // 0x80800144: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800148: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080014C: jal         0x808001E4
    // 0x80800150: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    chelectricfence_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800150: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800154: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1180, 0X4B4) << 16);
    // 0x80800158: lwc1        $f4, 0x4B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1180, 0X4B4));
    // 0x8080015C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800160: jal         0x8010A570
    // 0x80800164: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80800164: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x80800168: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080016C: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80800170: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x80800174: bnel        $t9, $zero, L_808001D4
    if (ctx->r25 != 0) {
        // 0x80800178: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808001D4;
    }
    goto skip_0;
    // 0x80800178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080017C: b           L_808001D4
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001D4;
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800184:
    // 0x80800184: jal         0x800F54E4
    // 0x80800188: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800188: nop

    after_3:
    // 0x8080018C: jal         0x800F6438
    // 0x80800190: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_4;
    // 0x80800190: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800194: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800198: beq         $a1, $zero, L_808001B8
    if (ctx->r5 == 0) {
        // 0x8080019C: nop
    
            goto L_808001B8;
    }
    // 0x8080019C: nop

    // 0x808001A0: jal         0x800F54E4
    // 0x808001A4: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x808001A4: nop

    after_5:
    // 0x808001A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001AC: jal         0x800F64A4
    // 0x808001B0: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    func_800F64A4(rdram, ctx);
        goto after_6;
    // 0x808001B0: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    after_6:
    // 0x808001B4: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
L_808001B8:
    // 0x808001B8: jal         0x8010A5B0
    // 0x808001BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8010A5B0(rdram, ctx);
        goto after_7;
    // 0x808001BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x808001C0: b           L_808001D4
    // 0x808001C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001D4;
    // 0x808001C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001C8: b           L_808001D4
    // 0x808001CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001D4;
    // 0x808001CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001D4:
    // 0x808001D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001DC: jr          $ra
    // 0x808001E0: nop

    return;
    // 0x808001E0: nop

;}
RECOMP_FUNC void func_8008FEC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FEC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FED0: jal         0x800F54E4
    // 0x8008FED4: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FED4: nop

    after_0:
    // 0x8008FED8: jal         0x800F58A0
    // 0x8008FEDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F58A0(rdram, ctx);
        goto after_1;
    // 0x8008FEDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FEE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FEE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FEE8: jr          $ra
    // 0x8008FEEC: nop

    return;
    // 0x8008FEEC: nop

;}
RECOMP_FUNC void _baduo_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084968: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084968);
    return;
    // 0x8008496C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800C07F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C07F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C07F8: lw          $v0, -0x75F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X75F4);
    // 0x800C07FC: sll         $t6, $v0, 21
    ctx->r14 = S32(ctx->r2 << 21);
    // 0x800C0800: jr          $ra
    // 0x800C0804: srl         $v0, $t6, 31
    ctx->r2 = S32(U32(ctx->r14) >> 31);
    return;
    // 0x800C0804: srl         $v0, $t6, 31
    ctx->r2 = S32(U32(ctx->r14) >> 31);
;}
RECOMP_FUNC void func_80800054_ch1pfreeze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800060: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800064: jal         0x80100094
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080006C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800070: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800074: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800078: lhu         $v1, 0x72($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X72);
    // 0x8080007C: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x80800080: beq         $t7, $at, L_80800098
    if (ctx->r15 == ctx->r1) {
        // 0x80800084: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800098;
    }
    // 0x80800084: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800088: beq         $t7, $at, L_808000DC
    if (ctx->r15 == ctx->r1) {
        // 0x8080008C: nop
    
            goto L_808000DC;
    }
    // 0x8080008C: nop

    // 0x80800090: b           L_8080011C
    // 0x80800094: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_8080011C;
    // 0x80800094: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800098:
    // 0x80800098: jal         0x800D8FF8
    // 0x8080009C: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080009C: nop

    after_1:
    // 0x808000A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000A4: jal         0x800F1574
    // 0x808000A8: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    func_800F1574(rdram, ctx);
        goto after_2;
    // 0x808000A8: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_2:
    // 0x808000AC: beq         $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x808000B0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808000BC;
    }
    // 0x808000B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000B4: jal         0x808002D0
    // 0x808000B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808002D0_ch1pfreeze(rdram, ctx);
        goto after_3;
    // 0x808000B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
L_808000BC:
    // 0x808000BC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x808000C0: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808000C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000CC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808000D0: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x808000D4: b           L_80800118
    // 0x808000D8: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
        goto L_80800118;
    // 0x808000D8: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
L_808000DC:
    // 0x808000DC: jal         0x800D8FF8
    // 0x808000E0: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x808000E0: nop

    after_4:
    // 0x808000E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000E8: jal         0x800F1574
    // 0x808000EC: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    func_800F1574(rdram, ctx);
        goto after_5;
    // 0x808000EC: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_5:
    // 0x808000F0: beql        $v0, $zero, L_8080010C
    if (ctx->r2 == 0) {
        // 0x808000F4: lwc1        $f18, 0x14($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
            goto L_8080010C;
    }
    goto skip_0;
    // 0x808000F4: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    skip_0:
    // 0x808000F8: jal         0x800FFAB0
    // 0x808000FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x808000FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800100: b           L_8080013C
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080013C;
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800108: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
L_8080010C:
    // 0x8080010C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800110: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800114: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
L_80800118:
    // 0x80800118: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8080011C:
    // 0x8080011C: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800120: jal         0x800F1214
    // 0x80800124: lui         $a2, 0x4300
    ctx->r6 = S32(0X4300 << 16);
    func_800F1214(rdram, ctx);
        goto after_7;
    // 0x80800124: lui         $a2, 0x4300
    ctx->r6 = S32(0X4300 << 16);
    after_7:
    // 0x80800128: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080012C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80800130: nop

    // 0x80800134: sw          $t9, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r25;
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080013C:
    // 0x8080013C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800140: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800144: jr          $ra
    // 0x80800148: nop

    return;
    // 0x80800148: nop

;}
RECOMP_FUNC void func_808028E8_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808028E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808028EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808028F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3C98) << 16);
    // 0x808028F4: addiu       $a2, $a2, 0x3C98
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3C98));
    // 0x808028F8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808028FC: jal         0x80089D20
    // 0x80802900: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80802900: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x80802904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080290C: jr          $ra
    // 0x80802910: nop

    return;
    // 0x80802910: nop

;}
RECOMP_FUNC void func_800F47C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F47C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F47C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800F47C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F47CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800F47D0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F47D4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800F47D8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800F47DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F47E0: addiu       $s1, $s1, 0x54B0
    ctx->r17 = ADD32(ctx->r17, 0X54B0);
    // 0x800F47E4: addiu       $s0, $s0, 0x5490
    ctx->r16 = ADD32(ctx->r16, 0X5490);
    // 0x800F47E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800F47EC:
    // 0x800F47EC: beql        $a0, $zero, L_800F480C
    if (ctx->r4 == 0) {
        // 0x800F47F0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800F480C;
    }
    goto skip_0;
    // 0x800F47F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800F47F4: lw          $t6, 0x17C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X17C);
    // 0x800F47F8: beql        $t6, $zero, L_800F480C
    if (ctx->r14 == 0) {
        // 0x800F47FC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800F480C;
    }
    goto skip_1;
    // 0x800F47FC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x800F4800: jalr        $s2
    // 0x800F4804: nop

    LOOKUP_FUNC(ctx->r18)(rdram, ctx);
        goto after_0;
    // 0x800F4804: nop

    after_0:
    // 0x800F4808: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800F480C:
    // 0x800F480C: bnel        $s0, $s1, L_800F47EC
    if (ctx->r16 != ctx->r17) {
        // 0x800F4810: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800F47EC;
    }
    goto skip_2;
    // 0x800F4810: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x800F4814: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800F4818: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F481C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4820: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800F4824: jr          $ra
    // 0x800F4828: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F4828: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080123C_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080123C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801248: jal         0x80095774
    // 0x8080124C: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    baflag_clear(rdram, ctx);
        goto after_0;
    // 0x8080124C: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_0:
    // 0x80801250: jal         0x80800508
    // 0x80801254: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800508_bskaztorpedo(rdram, ctx);
        goto after_1;
    // 0x80801254: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080125C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801260: jr          $ra
    // 0x80801264: nop

    return;
    // 0x80801264: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_46(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E08: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087E08);
    return;
    // 0x80087E0C: addi        $t0, $zero, 0xB8
    ctx->r8 = ADD32(0, 0XB8);
;}
RECOMP_FUNC void ncbafly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080023C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800240: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800244: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800248: jr          $ra
    // 0x8080024C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x8080024C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void func_800C89D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C89D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C89DC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C89E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C89E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C89E8: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C89EC: jal         0x800B28CC
    // 0x800C89F0: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C89F0: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x800C89F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C89F8: lbu         $v0, 0x19($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X19);
    // 0x800C89FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8A00: jr          $ra
    // 0x800C8A04: nop

    return;
    // 0x800C8A04: nop

;}
RECOMP_FUNC void badrone_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000DC: lw          $v0, 0x54($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X54);
    // 0x808000E0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000E4: lw          $v1, 0x1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C);
    // 0x808000E8: beql        $v1, $zero, L_80800100
    if (ctx->r3 == 0) {
        // 0x808000EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800100;
    }
    goto skip_0;
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000F0: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    // 0x808000F4: jalr        $v1
    // 0x808000F8: lw          $a1, 0x184($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X184);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x808000F8: lw          $a1, 0x184($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X184);
    after_0:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800100:
    // 0x80800100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_80800AA8_chfirefx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AA8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800AAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800AB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AB8: jal         0x80100094
    // 0x80800ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800AC0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800AC4: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800AC8: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800ACC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800AD0: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800AD4: xori        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 ^ 0X2;
    // 0x80800AD8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80800ADC: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800AE0: bgez        $t0, L_80800AFC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800AE4: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80800AFC;
    }
    // 0x80800AE4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80800AE8: jal         0x800DA298
    // 0x80800AEC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800AEC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_1:
    // 0x80800AF0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AF4: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800AF8: and         $v1, $v1, $t1
    ctx->r3 = ctx->r3 & ctx->r9;
L_80800AFC:
    // 0x80800AFC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800B00: jal         0x8010D640
    // 0x80800B04: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_8010D640(rdram, ctx);
        goto after_2;
    // 0x80800B04: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800B08: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B0C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800B10: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800B14: beq         $v1, $zero, L_80800B58
    if (ctx->r3 == 0) {
        // 0x80800B18: nop
    
            goto L_80800B58;
    }
    // 0x80800B18: nop

    // 0x80800B1C: jal         0x800EEB40
    // 0x80800B20: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x80800B20: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80800B24: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B28: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B2C: lhu         $v0, 0x16($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X16);
    // 0x80800B30: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800B34: mflo        $t3
    ctx->r11 = lo;
    // 0x80800B38: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800B3C: nop

    // 0x80800B40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800B44: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800B48: nop

    // 0x80800B4C: bc1f        L_80800B58
    if (!c1cs) {
        // 0x80800B50: nop
    
            goto L_80800B58;
    }
    // 0x80800B50: nop

    // 0x80800B54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800B58:
    // 0x80800B58: beq         $v1, $zero, L_80800BFC
    if (ctx->r3 == 0) {
        // 0x80800B5C: nop
    
            goto L_80800BFC;
    }
    // 0x80800B5C: nop

    // 0x80800B60: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800B64: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800B68: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1104, 0X1290) << 16);
    // 0x80800B6C: bne         $a0, $zero, L_80800B84
    if (ctx->r4 != 0) {
        // 0x80800B70: nop
    
            goto L_80800B84;
    }
    // 0x80800B70: nop

    // 0x80800B74: jal         0x800C4350
    // 0x80800B78: addiu       $a2, $a2, 0x1290
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1104, 0X1290));
    func_800C4350(rdram, ctx);
        goto after_4;
    // 0x80800B78: addiu       $a2, $a2, 0x1290
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1104, 0X1290));
    after_4:
    // 0x80800B7C: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x80800B80: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_80800B84:
    // 0x80800B84: beq         $a0, $zero, L_80800C04
    if (ctx->r4 == 0) {
        // 0x80800B88: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80800C04;
    }
    // 0x80800B88: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800B8C: jal         0x800C4350
    // 0x80800B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_5;
    // 0x80800B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800B94: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B98: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800B9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800BA0: lhu         $t5, 0x14($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X14);
    // 0x80800BA4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80800BA8: bgez        $t5, L_80800BBC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800BAC: cvt.s.w     $f8, $f8
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80800BBC;
    }
    // 0x80800BAC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800BB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800BB4: nop

    // 0x80800BB8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80800BBC:
    // 0x80800BBC: lhu         $t6, 0x16($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X16);
    // 0x80800BC0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800BC4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800BC8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80800BCC: bgez        $t6, L_80800BE0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800BD0: cvt.s.w     $f16, $f16
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80800BE0;
    }
    // 0x80800BD0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800BD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800BD8: nop

    // 0x80800BDC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80800BE0:
    // 0x80800BE0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800BE4: jal         0x800C3584
    // 0x80800BE8: nop

    func_800C3584(rdram, ctx);
        goto after_6;
    // 0x80800BE8: nop

    after_6:
    // 0x80800BEC: jal         0x800C3BDC
    // 0x80800BF0: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C3BDC(rdram, ctx);
        goto after_7;
    // 0x80800BF0: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_7:
    // 0x80800BF4: b           L_80800C08
    // 0x80800BF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C08;
    // 0x80800BF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BFC:
    // 0x80800BFC: jal         0x80089D40
    // 0x80800C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800C04:
    // 0x80800C04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C08:
    // 0x80800C08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C0C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800C10: jr          $ra
    // 0x80800C14: nop

    return;
    // 0x80800C14: nop

;}
RECOMP_FUNC void bstwirl_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800048: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080004C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800050: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80800054: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800058: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080005C: jal         0x8008CDB8
    // 0x80800060: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    baanim_playForDuration_once(rdram, ctx);
        goto after_0;
    // 0x80800060: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    after_0:
    // 0x80800064: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80800068: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800074: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800078: jal         0x8009FFD8
    // 0x8080007C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x8080007C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80800088: jal         0x8009C99C
    // 0x8080008C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_2;
    // 0x8080008C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_2:
    // 0x80800090: jal         0x8009C990
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_3;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800098: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080009C: jal         0x8009B9C0
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_4;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000A4: jal         0x8009C990
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_5;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000AC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808000B0: jal         0x8009BB00
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: jal         0x8009BA68
    // 0x808000C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x808000C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x8009B9B0
    // 0x808000D0: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x808000D0: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_8:
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: jal         0x800A0CF4
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_9;
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x80095760
    // 0x808000E8: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    baflag_set(rdram, ctx);
        goto after_10;
    // 0x808000E8: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_10:
    // 0x808000EC: jal         0x800DC0C0
    // 0x808000F0: nop

    func_800DC0C0(rdram, ctx);
        goto after_11;
    // 0x808000F0: nop

    after_11:
    // 0x808000F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800104: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800108: addiu       $a1, $zero, 0x57E
    ctx->r5 = ADD32(0, 0X57E);
    // 0x8080010C: bc1f        L_80800128
    if (!c1cs) {
        // 0x80800110: nop
    
            goto L_80800128;
    }
    // 0x80800110: nop

    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800118: jal         0x8009DE38
    // 0x8080011C: addiu       $a1, $zero, 0x57C
    ctx->r5 = ADD32(0, 0X57C);
    func_8009DE38(rdram, ctx);
        goto after_12;
    // 0x8080011C: addiu       $a1, $zero, 0x57C
    ctx->r5 = ADD32(0, 0X57C);
    after_12:
    // 0x80800120: b           L_80800134
    // 0x80800124: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800134;
    // 0x80800124: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800128:
    // 0x80800128: jal         0x8009DE38
    // 0x8080012C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_13;
    // 0x8080012C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_13:
    // 0x80800130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800134:
    // 0x80800134: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800138: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void chfactorysparkroom_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2372, 0X115C) << 16);
    // 0x8080101C: jr          $ra
    // 0x80801020: addiu       $v0, $v0, 0x115C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2372, 0X115C));
    return;
    // 0x80801020: addiu       $v0, $v0, 0x115C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2372, 0X115C));
    // 0x80801024: nop

    // 0x80801028: nop

    // 0x8080102C: nop

;}
RECOMP_FUNC void func_801160DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801160DC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801160E0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x801160E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801160E8: swc1        $f12, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f12.u32l;
    // 0x801160EC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x801160F0: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801160F4: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x801160F8: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x801160FC: sb          $v1, 0x24($t7)
    MEM_B(0X24, ctx->r15) = ctx->r3;
    // 0x80116100: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80116104: lbu         $t8, 0x24($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X24);
    // 0x80116108: sb          $t8, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r24;
    // 0x8011610C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80116110: swc1        $f12, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f12.u32l;
    // 0x80116114: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x80116118: jr          $ra
    // 0x8011611C: sb          $v1, 0x48($t0)
    MEM_B(0X48, ctx->r8) = ctx->r3;
    return;
    // 0x8011611C: sb          $v1, 0x48($t0)
    MEM_B(0X48, ctx->r8) = ctx->r3;
;}
RECOMP_FUNC void _bsfirstp_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842A8: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842A8);
    return;
    // 0x800842AC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080129C_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080129C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012A4: jal         0x80106790
    // 0x808012A8: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808012A8: nop

    after_0:
    // 0x808012AC: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x808012B0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808012B4: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
    // 0x808012B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012C0: jr          $ra
    // 0x808012C4: nop

    return;
    // 0x808012C4: nop

;}
RECOMP_FUNC void _bsdroneslide_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083148: syscall     46
    recomp_syscall_handler(rdram, ctx, 0x80083148);
    return;
    // 0x8008314C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800E3A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3A80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3A88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3A8C: jal         0x800CAA1C
    // 0x800E3A90: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CAA1C(rdram, ctx);
        goto after_0;
    // 0x800E3A90: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3A98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3A9C: jr          $ra
    // 0x800E3AA0: nop

    return;
    // 0x800E3AA0: nop

;}
RECOMP_FUNC void func_800B274C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B274C: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x800B2750: bne         $v1, $zero, L_800B2760
    if (ctx->r3 != 0) {
        // 0x800B2754: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800B2760;
    }
    // 0x800B2754: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800B2758: jr          $ra
    // 0x800B275C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B275C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B2760:
    // 0x800B2760: jr          $ra
    // 0x800B2764: nop

    return;
    // 0x800B2764: nop

;}
RECOMP_FUNC void func_800FF44C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF44C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FF450: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FF454: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FF458: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    // 0x800FF45C: jal         0x80101238
    // 0x800FF460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80101238(rdram, ctx);
        goto after_0;
    // 0x800FF460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800FF464: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x800FF468: jal         0x801067C4
    // 0x800FF46C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801067C4(rdram, ctx);
        goto after_1;
    // 0x800FF46C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800FF470: beq         $v0, $zero, L_800FF490
    if (ctx->r2 == 0) {
        // 0x800FF474: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FF490;
    }
    // 0x800FF474: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800FF478:
    // 0x800FF478: jal         0x800FF3EC
    // 0x800FF47C: nop

    func_800FF3EC(rdram, ctx);
        goto after_2;
    // 0x800FF47C: nop

    after_2:
    // 0x800FF480: jal         0x8010682C
    // 0x800FF484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010682C(rdram, ctx);
        goto after_3;
    // 0x800FF484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800FF488: bne         $v0, $zero, L_800FF478
    if (ctx->r2 != 0) {
        // 0x800FF48C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FF478;
    }
    // 0x800FF48C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800FF490:
    // 0x800FF490: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FF494: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FF498: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FF49C: jr          $ra
    // 0x800FF4A0: nop

    return;
    // 0x800FF4A0: nop

;}
RECOMP_FUNC void func_800DFD64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFD64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800DFD68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800DFD6C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800DFD70: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800DFD74: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800DFD78: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800DFD7C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800DFD80: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800DFD84: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800DFD88: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800DFD8C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800DFD90: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800DFD94: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800DFD98: addu        $s3, $t7, $s0
    ctx->r19 = ADD32(ctx->r15, ctx->r16);
    // 0x800DFD9C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800DFDA0: lw          $s1, 0x0($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X0);
    // 0x800DFDA4: beq         $at, $zero, L_800DFE88
    if (ctx->r1 == 0) {
        // 0x800DFDA8: lw          $s2, 0x0($a2)
        ctx->r18 = MEM_W(ctx->r6, 0X0);
            goto L_800DFE88;
    }
    // 0x800DFDA8: lw          $s2, 0x0($a2)
    ctx->r18 = MEM_W(ctx->r6, 0X0);
L_800DFDAC:
    // 0x800DFDAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DFDB0: jal         0x800D97E8
    // 0x800DFDB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800D97E8(rdram, ctx);
        goto after_0;
    // 0x800DFDB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800DFDB8: beq         $v0, $zero, L_800DFDD4
    if (ctx->r2 == 0) {
        // 0x800DFDBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800DFDD4;
    }
    // 0x800DFDBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DFDC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DFDC4: jal         0x800D9600
    // 0x800DFDC8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D9600(rdram, ctx);
        goto after_1;
    // 0x800DFDC8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800DFDCC: b           L_800DFDE8
    // 0x800DFDD0: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
        goto L_800DFDE8;
    // 0x800DFDD0: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
L_800DFDD4:
    // 0x800DFDD4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800DFDD8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800DFDDC: jal         0x800D9AD4
    // 0x800DFDE0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800D9AD4(rdram, ctx);
        goto after_2;
    // 0x800DFDE0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x800DFDE4: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
L_800DFDE8:
    // 0x800DFDE8: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x800DFDEC: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x800DFDF0: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800DFDF4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800DFDF8: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x800DFDFC: addiu       $s2, $s2, 0x28
    ctx->r18 = ADD32(ctx->r18, 0X28);
    // 0x800DFE00: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800DFE04: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800DFE08: swc1        $f10, -0x18($s0)
    MEM_W(-0X18, ctx->r16) = ctx->f10.u32l;
    // 0x800DFE0C: lwc1        $f16, -0x14($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, -0X14);
    // 0x800DFE10: lwc1        $f2, -0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, -0X14);
    // 0x800DFE14: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x800DFE18: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800DFE1C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800DFE20: swc1        $f6, -0x14($s0)
    MEM_W(-0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800DFE24: lwc1        $f8, -0x10($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, -0X10);
    // 0x800DFE28: lwc1        $f12, -0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0X10);
    // 0x800DFE2C: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800DFE30: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800DFE34: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800DFE38: swc1        $f18, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = ctx->f18.u32l;
    // 0x800DFE3C: lwc1        $f4, -0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, -0XC);
    // 0x800DFE40: lwc1        $f14, -0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, -0XC);
    // 0x800DFE44: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800DFE48: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800DFE4C: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800DFE50: swc1        $f10, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->f10.u32l;
    // 0x800DFE54: lwc1        $f16, -0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, -0X8);
    // 0x800DFE58: lwc1        $f0, -0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, -0X8);
    // 0x800DFE5C: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800DFE60: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800DFE64: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800DFE68: swc1        $f6, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800DFE6C: lwc1        $f8, -0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, -0X4);
    // 0x800DFE70: lwc1        $f2, -0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, -0X4);
    // 0x800DFE74: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800DFE78: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800DFE7C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800DFE80: bne         $at, $zero, L_800DFDAC
    if (ctx->r1 != 0) {
        // 0x800DFE84: swc1        $f18, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f18.u32l;
            goto L_800DFDAC;
    }
    // 0x800DFE84: swc1        $f18, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f18.u32l;
L_800DFE88:
    // 0x800DFE88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800DFE8C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800DFE90: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800DFE94: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800DFE98: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800DFE9C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800DFEA0: jr          $ra
    // 0x800DFEA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800DFEA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8080000C_chcoderoomdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800014: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800020: beq         $a1, $at, L_8080003C
    if (ctx->r5 == ctx->r1) {
        // 0x80800024: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_8080003C;
    }
    // 0x80800024: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800028: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8080002C: beq         $a1, $at, L_80800070
    if (ctx->r5 == ctx->r1) {
        // 0x80800030: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800070;
    }
    // 0x80800030: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800034: b           L_808000C0
    // 0x80800038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000C0;
    // 0x80800038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080003C:
    // 0x8080003C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800040: jal         0x800EE7F8
    // 0x80800044: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800044: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80800048: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080004C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800050: jal         0x800EF1B8
    // 0x80800054: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800054: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    after_1:
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800060: jal         0x80086670
    // 0x80800064: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800064: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_2:
    // 0x80800068: b           L_808000C0
    // 0x8080006C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C0;
    // 0x8080006C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800070:
    // 0x80800070: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1948, 0X128) << 16);
    // 0x80800074: addiu       $t6, $t6, 0x128
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1948, 0X128));
    // 0x80800078: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080007C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800080: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800084: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800088: jal         0x800BABB8
    // 0x8080008C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x8080008C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80800090: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1948, 0X170) << 16);
    // 0x80800094: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800098: addiu       $a2, $a2, 0x170
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1948, 0X170));
    // 0x8080009C: jal         0x80089D18
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000A4: jal         0x800DA544
    // 0x808000A8: addiu       $a0, $zero, 0x366
    ctx->r4 = ADD32(0, 0X366);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x808000A8: addiu       $a0, $zero, 0x366
    ctx->r4 = ADD32(0, 0X366);
    after_5:
    // 0x808000AC: b           L_808000C0
    // 0x808000B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C0;
    // 0x808000B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000B4: b           L_808000C0
    // 0x808000B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000C0;
    // 0x808000B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C0:
    // 0x808000C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

    // 0x808000D4: nop

    // 0x808000D8: nop

    // 0x808000DC: nop

;}
RECOMP_FUNC void func_808000AC_chdiggergroundgen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B8: beq         $a1, $at, L_808000D4
    if (ctx->r5 == ctx->r1) {
        // 0x808000BC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808000D4;
    }
    // 0x808000BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000C0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000C4: beq         $a1, $at, L_808000E4
    if (ctx->r5 == ctx->r1) {
        // 0x808000C8: nop
    
            goto L_808000E4;
    }
    // 0x808000C8: nop

    // 0x808000CC: b           L_80800108
    // 0x808000D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800108;
    // 0x808000D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000D4:
    // 0x808000D4: jal         0x808002C4
    // 0x808000D8: nop

    func_808002C4_chdiggergroundgen(rdram, ctx);
        goto after_0;
    // 0x808000D8: nop

    after_0:
    // 0x808000DC: b           L_80800108
    // 0x808000E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800108;
    // 0x808000E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000E4:
    // 0x808000E4: jal         0x80100094
    // 0x808000E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808000E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808000EC: jal         0x8008A038
    // 0x808000F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808000F4: b           L_80800108
    // 0x808000F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800108;
    // 0x808000F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000FC: b           L_80800108
    // 0x80800100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800108;
    // 0x80800100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800108:
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080010C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void bsclimb_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800798: lui         $a2, 0x4028
    ctx->r6 = S32(0X4028 << 16);
    // 0x8080079C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007A0: ori         $a2, $a2, 0xF5C3
    ctx->r6 = ctx->r6 | 0XF5C3;
    // 0x808007A4: jal         0x8008CB3C
    // 0x808007A8: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x808007A8: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    after_0:
    // 0x808007AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007B0: jal         0x8008CA4C
    // 0x808007B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_1;
    // 0x808007B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808007B8: jal         0x808000E8
    // 0x808007BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000E8_bsclimb(rdram, ctx);
        goto after_2;
    // 0x808007BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808007C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007C4: jal         0x8009B800
    // 0x808007C8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baphysics_set_type(rdram, ctx);
        goto after_3;
    // 0x808007C8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_3:
    // 0x808007CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007D4: jr          $ra
    // 0x808007D8: nop

    return;
    // 0x808007D8: nop

;}
RECOMP_FUNC void _ncpoddialog_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895F0: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x800895F0);
    return;
    // 0x800895F4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
