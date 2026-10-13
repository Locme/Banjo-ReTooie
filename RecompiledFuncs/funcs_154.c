#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F73C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F73C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F73C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F73CC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800F73D0: addiu       $a1, $a1, 0x5490
    ctx->r5 = ADD32(ctx->r5, 0X5490);
    // 0x800F73D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800F73D8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F73DC: addiu       $v1, $t6, 0x5490
    ctx->r3 = ADD32(ctx->r14, 0X5490);
    // 0x800F73E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F73E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F73E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F73EC: sb          $zero, 0x4A($a1)
    MEM_B(0X4A, ctx->r5) = 0;
    // 0x800F73F0: sb          $zero, 0x49($a1)
    MEM_B(0X49, ctx->r5) = 0;
    // 0x800F73F4: addiu       $a0, $a0, 0x5498
    ctx->r4 = ADD32(ctx->r4, 0X5498);
    // 0x800F73F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800F73FC:
    // 0x800F73FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F7400: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800F7404: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800F7408: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800F740C: bne         $at, $zero, L_800F73FC
    if (ctx->r1 != 0) {
        // 0x800F7410: sb          $zero, 0x1F($v1)
        MEM_B(0X1F, ctx->r3) = 0;
            goto L_800F73FC;
    }
    // 0x800F7410: sb          $zero, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = 0;
    // 0x800F7414: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800F7418: sh          $t7, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r15;
    // 0x800F741C: lh          $t8, 0x52($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X52);
    // 0x800F7420: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800F7424: jal         0x800F80D8
    // 0x800F7428: sh          $t8, 0x50($a1)
    MEM_H(0X50, ctx->r5) = ctx->r24;
    func_800F80D8(rdram, ctx);
        goto after_0;
    // 0x800F7428: sh          $t8, 0x50($a1)
    MEM_H(0X50, ctx->r5) = ctx->r24;
    after_0:
    // 0x800F742C: jal         0x800DB9B0
    // 0x800F7430: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x800F7430: nop

    after_1:
    // 0x800F7434: bne         $v0, $zero, L_800F7478
    if (ctx->r2 != 0) {
        // 0x800F7438: nop
    
            goto L_800F7478;
    }
    // 0x800F7438: nop

    // 0x800F743C: jal         0x800887B0
    // 0x800F7440: nop

    _glcutDll_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x800F7440: nop

    after_2:
    // 0x800F7444: bne         $v0, $zero, L_800F7478
    if (ctx->r2 != 0) {
        // 0x800F7448: nop
    
            goto L_800F7478;
    }
    // 0x800F7448: nop

    // 0x800F744C: jal         0x800F99E8
    // 0x800F7450: nop

    func_800F99E8(rdram, ctx);
        goto after_3;
    // 0x800F7450: nop

    after_3:
    // 0x800F7454: bne         $v0, $zero, L_800F7478
    if (ctx->r2 != 0) {
        // 0x800F7458: nop
    
            goto L_800F7478;
    }
    // 0x800F7458: nop

    // 0x800F745C: blez        $s1, L_800F7478
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800F7460: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800F7478;
    }
    // 0x800F7460: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800F7464:
    // 0x800F7464: jal         0x800F61E4
    // 0x800F7468: nop

    func_800F61E4(rdram, ctx);
        goto after_4;
    // 0x800F7468: nop

    after_4:
    // 0x800F746C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800F7470: bne         $s0, $s1, L_800F7464
    if (ctx->r16 != ctx->r17) {
        // 0x800F7474: nop
    
            goto L_800F7464;
    }
    // 0x800F7474: nop

L_800F7478:
    // 0x800F7478: jal         0x800F8B94
    // 0x800F747C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F8B94(rdram, ctx);
        goto after_5;
    // 0x800F747C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_5:
    // 0x800F7480: jal         0x800F5898
    // 0x800F7484: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_6;
    // 0x800F7484: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_6:
    // 0x800F7488: blez        $v0, L_800F74B8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800F748C: nop
    
            goto L_800F74B8;
    }
    // 0x800F748C: nop

L_800F7490:
    // 0x800F7490: jal         0x800F6BE4
    // 0x800F7494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_7;
    // 0x800F7494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800F7498: beq         $v0, $zero, L_800F74A4
    if (ctx->r2 == 0) {
        // 0x800F749C: nop
    
            goto L_800F74A4;
    }
    // 0x800F749C: nop

    // 0x800F74A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800F74A4:
    // 0x800F74A4: jal         0x800F5898
    // 0x800F74A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_8;
    // 0x800F74A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_8:
    // 0x800F74AC: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F74B0: bne         $at, $zero, L_800F7490
    if (ctx->r1 != 0) {
        // 0x800F74B4: nop
    
            goto L_800F7490;
    }
    // 0x800F74B4: nop

L_800F74B8:
    // 0x800F74B8: bne         $s1, $zero, L_800F74D4
    if (ctx->r17 != 0) {
        // 0x800F74BC: nop
    
            goto L_800F74D4;
    }
    // 0x800F74BC: nop

    // 0x800F74C0: jal         0x800F61E4
    // 0x800F74C4: nop

    func_800F61E4(rdram, ctx);
        goto after_9;
    // 0x800F74C4: nop

    after_9:
    // 0x800F74C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F74CC: jal         0x800F7E64
    // 0x800F74D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800F7E64(rdram, ctx);
        goto after_10;
    // 0x800F74D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
L_800F74D4:
    // 0x800F74D4: jal         0x800F8B88
    // 0x800F74D8: nop

    func_800F8B88(rdram, ctx);
        goto after_11;
    // 0x800F74D8: nop

    after_11:
    // 0x800F74DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F74E0: bne         $v0, $at, L_800F7554
    if (ctx->r2 != ctx->r1) {
        // 0x800F74E4: nop
    
            goto L_800F7554;
    }
    // 0x800F74E4: nop

    // 0x800F74E8: jal         0x800878A0
    // 0x800F74EC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x800F74EC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_12:
    // 0x800F74F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800F74F4: jal         0x800878A0
    // 0x800F74F8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x800F74F8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_13:
    // 0x800F74FC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800F7500: beq         $s1, $v1, L_800F7554
    if (ctx->r17 == ctx->r3) {
        // 0x800F7504: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800F7554;
    }
    // 0x800F7504: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800F7508: beq         $v0, $v1, L_800F7554
    if (ctx->r2 == ctx->r3) {
        // 0x800F750C: nop
    
            goto L_800F7554;
    }
    // 0x800F750C: nop

    // 0x800F7510: jal         0x800F65D0
    // 0x800F7514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F65D0(rdram, ctx);
        goto after_14;
    // 0x800F7514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x800F7518: beq         $v0, $zero, L_800F7528
    if (ctx->r2 == 0) {
        // 0x800F751C: nop
    
            goto L_800F7528;
    }
    // 0x800F751C: nop

    // 0x800F7520: b           L_800F754C
    // 0x800F7524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800F754C;
    // 0x800F7524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800F7528:
    // 0x800F7528: jal         0x800F65D0
    // 0x800F752C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F65D0(rdram, ctx);
        goto after_15;
    // 0x800F752C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x800F7530: beq         $v0, $zero, L_800F7540
    if (ctx->r2 == 0) {
        // 0x800F7534: nop
    
            goto L_800F7540;
    }
    // 0x800F7534: nop

    // 0x800F7538: b           L_800F754C
    // 0x800F753C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800F754C;
    // 0x800F753C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800F7540:
    // 0x800F7540: jal         0x800878A0
    // 0x800F7544: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x800F7544: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_16:
    // 0x800F7548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800F754C:
    // 0x800F754C: jal         0x800F8128
    // 0x800F7550: nop

    func_800F8128(rdram, ctx);
        goto after_17;
    // 0x800F7550: nop

    after_17:
L_800F7554:
    // 0x800F7554: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F7558: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F755C: addiu       $s0, $s0, 0x54B0
    ctx->r16 = ADD32(ctx->r16, 0X54B0);
    // 0x800F7560: addiu       $v0, $v0, 0x5490
    ctx->r2 = ADD32(ctx->r2, 0X5490);
    // 0x800F7564: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
L_800F7568:
    // 0x800F7568: beql        $a0, $zero, L_800F7580
    if (ctx->r4 == 0) {
        // 0x800F756C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800F7580;
    }
    goto skip_0;
    // 0x800F756C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x800F7570: jal         0x80084FB0
    // 0x800F7574: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    _basetup_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x800F7574: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_18:
    // 0x800F7578: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800F757C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800F7580:
    // 0x800F7580: bnel        $v0, $s0, L_800F7568
    if (ctx->r2 != ctx->r16) {
        // 0x800F7584: lw          $a0, 0x0($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X0);
            goto L_800F7568;
    }
    goto skip_1;
    // 0x800F7584: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x800F7588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F758C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F7590: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F7594: jr          $ra
    // 0x800F7598: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800F7598: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8008AC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AC4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008AC50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008AC54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008AC58: jal         0x8008AEDC
    // 0x8008AC5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_0;
    // 0x8008AC5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8008AC60: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8008AC64: jal         0x8008AA0C
    // 0x8008AC68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AA0C(rdram, ctx);
        goto after_1;
    // 0x8008AC68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8008AC6C: jal         0x8008C0C8
    // 0x8008AC70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008C0C8(rdram, ctx);
        goto after_2;
    // 0x8008AC70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8008AC74: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8008AC78: jal         0x8008A990
    // 0x8008AC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008A990(rdram, ctx);
        goto after_3;
    // 0x8008AC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008AC80: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8008AC84: jal         0x8008B2AC
    // 0x8008AC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B2AC(rdram, ctx);
        goto after_4;
    // 0x8008AC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8008AC8C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008AC90: lb          $t7, 0x1B($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1B);
    // 0x8008AC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AC98: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8008AC9C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008ACA0: bltz        $t7, L_8008ACAC
    if (SIGNED(ctx->r15) < 0) {
        // 0x8008ACA4: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_8008ACAC;
    }
    // 0x8008ACA4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8008ACA8: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_8008ACAC:
    // 0x8008ACAC: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8008ACB0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8008ACB4: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8008ACB8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8008ACBC: nop

    // 0x8008ACC0: bc1fl       L_8008ACDC
    if (!c1cs) {
        // 0x8008ACC4: lwc1        $f2, 0x8($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
            goto L_8008ACDC;
    }
    goto skip_0;
    // 0x8008ACC4: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x8008ACC8: jal         0x8008B134
    // 0x8008ACCC: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x8008ACCC: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_5:
    // 0x8008ACD0: b           L_8008AD60
    // 0x8008ACD4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
        goto L_8008AD60;
    // 0x8008ACD4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8008ACD8: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
L_8008ACDC:
    // 0x8008ACDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ACE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008ACE4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8008ACE8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008ACEC: bc1tl       L_8008AD0C
    if (c1cs) {
        // 0x8008ACF0: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8008AD0C;
    }
    goto skip_1;
    // 0x8008ACF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x8008ACF4: lwc1        $f12, 0x4A94($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4A94);
    // 0x8008ACF8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8008ACFC: nop

    // 0x8008AD00: bc1fl       L_8008AD48
    if (!c1cs) {
        // 0x8008AD04: trunc.w.s   $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8008AD48;
    }
    goto skip_2;
    // 0x8008AD04: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_2:
    // 0x8008AD08: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8008AD0C:
    // 0x8008AD0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AD10: lwc1        $f12, 0x4A98($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4A98);
    // 0x8008AD14: bc1fl       L_8008AD24
    if (!c1cs) {
        // 0x8008AD18: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_8008AD24;
    }
    goto skip_3;
    // 0x8008AD18: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_3:
    // 0x8008AD1C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8008AD20: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_8008AD24:
    // 0x8008AD24: nop

    // 0x8008AD28: bc1f        L_8008AD34
    if (!c1cs) {
        // 0x8008AD2C: nop
    
            goto L_8008AD34;
    }
    // 0x8008AD2C: nop

    // 0x8008AD30: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8008AD34:
    // 0x8008AD34: jal         0x8008B134
    // 0x8008AD38: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x8008AD38: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8008AD3C: b           L_8008AD60
    // 0x8008AD40: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
        goto L_8008AD60;
    // 0x8008AD40: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8008AD44: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
L_8008AD48:
    // 0x8008AD48: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8008AD4C: nop

    // 0x8008AD50: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8008AD54: nop

    // 0x8008AD58: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8008AD5C: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
L_8008AD60:
    // 0x8008AD60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008AD64: jal         0x8008C1C0
    // 0x8008AD68: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008C1C0(rdram, ctx);
        goto after_7;
    // 0x8008AD68: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x8008AD6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AD70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AD74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008AD78: jr          $ra
    // 0x8008AD7C: nop

    return;
    // 0x8008AD7C: nop

;}
RECOMP_FUNC void baeggfire_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: jal         0x800F53D0
    // 0x8080009C: nop

    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x8080009C: nop

    after_0:
    // 0x808000A0: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    // 0x808000A4: sb          $zero, 0x13($t6)
    MEM_B(0X13, ctx->r14) = 0;
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void func_80800720_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800720: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80800724: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800728: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8080072C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800730: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800734: addu        $s1, $t6, $a2
    ctx->r17 = ADD32(ctx->r14, ctx->r6);
    // 0x80800738: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080073C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800740: sltu        $at, $a2, $s1
    ctx->r1 = ctx->r6 < ctx->r17 ? 1 : 0;
    // 0x80800744: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800748: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080074C: beq         $at, $zero, L_80800770
    if (ctx->r1 == 0) {
        // 0x80800750: or          $s0, $a2, $zero
        ctx->r16 = ctx->r6 | 0;
            goto L_80800770;
    }
    // 0x80800750: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800754: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800758:
    // 0x80800758: jal         0x80800EBC
    // 0x8080075C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800EBC_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x8080075C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80800760: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80800764: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80800768: bnel        $at, $zero, L_80800758
    if (ctx->r1 != 0) {
        // 0x8080076C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800758;
    }
    goto skip_0;
    // 0x8080076C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_80800770:
    // 0x80800770: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800774: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800778: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080077C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800780: jr          $ra
    // 0x80800784: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800784: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sccustom_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800644: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800648: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080064C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800650: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800654: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800658: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080065C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800660: jal         0x8008A618
    // 0x80800664: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _scinfobar_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80800664: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800668: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080066C: jal         0x8008A620
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800674: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080067C: bnel        $v0, $t6, L_80800690
    if (ctx->r2 != ctx->r14) {
        // 0x80800680: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800690;
    }
    goto skip_0;
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800684: jal         0x8008A5A8
    // 0x80800688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _scinfobar_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800690:
    // 0x80800690: jal         0x8080050C
    // 0x80800694: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    func_8080050C_sccustom(rdram, ctx);
        goto after_3;
    // 0x80800694: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_3:
    // 0x80800698: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080069C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808006A0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808006A4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808006A8: jal         0x80800000
    // 0x808006AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80800000_sccustom(rdram, ctx);
        goto after_4;
    // 0x808006AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x808006B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006BC: jr          $ra
    // 0x808006C0: nop

    return;
    // 0x808006C0: nop

;}
RECOMP_FUNC void _suspline_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DD8: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DD8);
    return;
    // 0x80089DDC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C68: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C68);
    return;
    // 0x80083C6C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_800C1414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1414: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C1418: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C141C: addiu       $t8, $t8, -0x7470
    ctx->r24 = ADD32(ctx->r24, -0X7470);
    // 0x800C1420: sll         $t7, $t6, 7
    ctx->r15 = S32(ctx->r14 << 7);
    // 0x800C1424: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C1428: jr          $ra
    // 0x800C142C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x800C142C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void func_800A3A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3A80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A3A84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A3A88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A3A8C: lw          $v0, 0xA0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3A90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A3A94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A3A98: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x800A3A9C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800A3AA0: nop

    // 0x800A3AA4: bc1t        L_800A3AB4
    if (c1cs) {
        // 0x800A3AA8: nop
    
            goto L_800A3AB4;
    }
    // 0x800A3AA8: nop

    // 0x800A3AAC: jal         0x800D9078
    // 0x800A3AB0: addiu       $a0, $v0, 0x40
    ctx->r4 = ADD32(ctx->r2, 0X40);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x800A3AB0: addiu       $a0, $v0, 0x40
    ctx->r4 = ADD32(ctx->r2, 0X40);
    after_0:
L_800A3AB4:
    // 0x800A3AB4: jal         0x8008E078
    // 0x800A3AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_1;
    // 0x800A3AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A3ABC: beq         $v0, $zero, L_800A3AD4
    if (ctx->r2 == 0) {
        // 0x800A3AC0: nop
    
            goto L_800A3AD4;
    }
    // 0x800A3AC0: nop

    // 0x800A3AC4: lw          $a1, 0xA0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3ACC: jal         0x8009C128
    // 0x800A3AD0: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x800A3AD0: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_2:
L_800A3AD4:
    // 0x800A3AD4: jal         0x8008E078
    // 0x800A3AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x800A3AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800A3ADC: bne         $v0, $zero, L_800A3AF0
    if (ctx->r2 != 0) {
        // 0x800A3AE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3AF0;
    }
    // 0x800A3AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3AE4: jal         0x8009E71C
    // 0x800A3AE8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8009E71C(rdram, ctx);
        goto after_4;
    // 0x800A3AE8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_4:
    // 0x800A3AEC: beq         $v0, $zero, L_800A3B08
    if (ctx->r2 == 0) {
        // 0x800A3AF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3B08;
    }
L_800A3AF0:
    // 0x800A3AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3AF4: jal         0x80095774
    // 0x800A3AF8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baflag_clear(rdram, ctx);
        goto after_5;
    // 0x800A3AF8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x800A3AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3B00: jal         0x80095774
    // 0x800A3B04: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baflag_clear(rdram, ctx);
        goto after_6;
    // 0x800A3B04: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_6:
L_800A3B08:
    // 0x800A3B08: jal         0x8008E35C
    // 0x800A3B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_7;
    // 0x800A3B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800A3B10: beq         $v0, $zero, L_800A3B2C
    if (ctx->r2 == 0) {
        // 0x800A3B14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3B2C;
    }
    // 0x800A3B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3B18: jal         0x80095774
    // 0x800A3B1C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baflag_clear(rdram, ctx);
        goto after_8;
    // 0x800A3B1C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_8:
    // 0x800A3B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3B24: jal         0x80095774
    // 0x800A3B28: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baflag_clear(rdram, ctx);
        goto after_9;
    // 0x800A3B28: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_9:
L_800A3B2C:
    // 0x800A3B2C: jal         0x800A3644
    // 0x800A3B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3644(rdram, ctx);
        goto after_10;
    // 0x800A3B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800A3B34: jal         0x800A355C
    // 0x800A3B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A355C(rdram, ctx);
        goto after_11;
    // 0x800A3B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800A3B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3B40: jal         0x80096568
    // 0x800A3B44: addiu       $a1, $zero, 0x600
    ctx->r5 = ADD32(0, 0X600);
    func_80096568(rdram, ctx);
        goto after_12;
    // 0x800A3B44: addiu       $a1, $zero, 0x600
    ctx->r5 = ADD32(0, 0X600);
    after_12:
    // 0x800A3B48: beq         $v0, $zero, L_800A3B58
    if (ctx->r2 == 0) {
        // 0x800A3B4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3B58;
    }
    // 0x800A3B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3B50: jal         0x8009BD18
    // 0x800A3B54: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_8009BD18(rdram, ctx);
        goto after_13;
    // 0x800A3B54: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_13:
L_800A3B58:
    // 0x800A3B58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A3B5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A3B60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A3B64: jr          $ra
    // 0x800A3B68: nop

    return;
    // 0x800A3B68: nop

    // 0x800A3B6C: nop

;}
RECOMP_FUNC void func_8001DDA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DDA4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001DDA8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001DDAC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8001DDB0: jr          $ra
    // 0x8001DDB4: lw          $v0, -0x27E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X27E0);
    return;
    // 0x8001DDB4: lw          $v0, -0x27E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X27E0);
;}
RECOMP_FUNC void bssub_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808013B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(380, 0X18D0) << 16);
    // 0x808013B8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808013BC: jr          $ra
    // 0x808013C0: lw          $v0, 0x18D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18D0));
    return;
    // 0x808013C0: lw          $v0, 0x18D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18D0));
;}
RECOMP_FUNC void bskazeggass_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x800832E0
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800018: addiu       $a1, $zero, 0x28E
    ctx->r5 = ADD32(0, 0X28E);
    // 0x8080001C: jal         0x8008CDB8
    // 0x80800020: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    baanim_playForDuration_once(rdram, ctx);
        goto after_1;
    // 0x80800020: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_1:
    // 0x80800024: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800028: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800034: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800038: jal         0x8009FFD8
    // 0x8080003C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x80800048: jal         0x8009C99C
    // 0x8080004C: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x8080004C: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    after_3:
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: jal         0x8009B9B0
    // 0x80800058: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800058: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: jal         0x800A0CDC
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CDC(rdram, ctx);
        goto after_5;
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800068: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080006C: sw          $v0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r2;
    // 0x80800070: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
    // 0x80800074: jal         0x80094510
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094510(rdram, ctx);
        goto after_6;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080007C: sw          $v0, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r2;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800088: jal         0x80098140
    // 0x8080008C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_7;
    // 0x8080008C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800094: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800098: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void func_80800C2C_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C3C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800C40: jal         0x8008CB10
    // 0x80800C44: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80800C44: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x80800C48: beq         $v0, $zero, L_80800C58
    if (ctx->r2 == 0) {
        // 0x80800C4C: nop
    
            goto L_80800C58;
    }
    // 0x80800C4C: nop

    // 0x80800C50: jal         0x800951B4
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_1;
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80800C58:
    // 0x80800C58: jal         0x80084600
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800C60: beq         $v0, $zero, L_80800C6C
    if (ctx->r2 == 0) {
        // 0x80800C64: addiu       $t6, $zero, 0xE5
        ctx->r14 = ADD32(0, 0XE5);
            goto L_80800C6C;
    }
    // 0x80800C64: addiu       $t6, $zero, 0xE5
    ctx->r14 = ADD32(0, 0XE5);
    // 0x80800C68: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800C6C:
    // 0x80800C6C: jal         0x8008E35C
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_3;
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800C74: beql        $v0, $zero, L_80800CA4
    if (ctx->r2 == 0) {
        // 0x80800C78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CA4;
    }
    goto skip_0;
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800C7C: jal         0x8009BB50
    // 0x80800C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_4;
    // 0x80800C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800C84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800C88: addiu       $t7, $zero, 0xF4
    ctx->r15 = ADD32(0, 0XF4);
    // 0x80800C8C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80800C90: nop

    // 0x80800C94: bc1fl       L_80800CA4
    if (!c1cs) {
        // 0x80800C98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CA4;
    }
    goto skip_1;
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800C9C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80800CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800CA4:
    // 0x80800CA4: jal         0x8009E5C8
    // 0x80800CA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x80800CA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80800CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CB8: jr          $ra
    // 0x80800CBC: nop

    return;
    // 0x80800CBC: nop

;}
RECOMP_FUNC void func_80800530_chintroticker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800534: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800538: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1648, 0X8C4) << 16);
    // 0x8080053C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800540: addiu       $v1, $v1, 0x8C4
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(1648, 0X8C4));
    // 0x80800544: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080054C:
    // 0x8080054C: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80800550: beql        $a1, $t6, L_80800568
    if (ctx->r5 == ctx->r14) {
        // 0x80800554: sltiu       $at, $v0, 0x1C
        ctx->r1 = ctx->r2 < 0X1C ? 1 : 0;
            goto L_80800568;
    }
    goto skip_0;
    // 0x80800554: sltiu       $at, $v0, 0x1C
    ctx->r1 = ctx->r2 < 0X1C ? 1 : 0;
    skip_0:
    // 0x80800558: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080055C: bne         $v0, $a0, L_8080054C
    if (ctx->r2 != ctx->r4) {
        // 0x80800560: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8080054C;
    }
    // 0x80800560: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800564: sltiu       $at, $v0, 0x1C
    ctx->r1 = ctx->r2 < 0X1C ? 1 : 0;
L_80800568:
    // 0x80800568: beql        $at, $zero, L_808005A0
    if (ctx->r1 == 0) {
        // 0x8080056C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005A0;
    }
    goto skip_1;
    // 0x8080056C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_80800570:
    // 0x80800570: lh          $a1, 0x2($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X2);
    // 0x80800574: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800578: sltiu       $at, $v0, 0x1C
    ctx->r1 = ctx->r2 < 0X1C ? 1 : 0;
    // 0x8080057C: bgez        $a1, L_80800594
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80800580: nop
    
            goto L_80800594;
    }
    // 0x80800580: nop

    // 0x80800584: jal         0x808004A8
    // 0x80800588: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808004A8_chintroticker(rdram, ctx);
        goto after_0;
    // 0x80800588: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8080058C: b           L_808005A0
    // 0x80800590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808005A0;
    // 0x80800590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800594:
    // 0x80800594: bne         $at, $zero, L_80800570
    if (ctx->r1 != 0) {
        // 0x80800598: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800570;
    }
    // 0x80800598: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080059C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005A0:
    // 0x808005A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005A4: jr          $ra
    // 0x808005A8: nop

    return;
    // 0x808005A8: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887E8: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x800887E8);
    return;
    // 0x800887EC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80801C00_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C00: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80801C04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801C08: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801C0C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80801C10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801C14: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801C18: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801C1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801C20: jal         0x80100094
    // 0x80801C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801C28: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80801C2C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801C30: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801C34: addiu       $t8, $t7, -0x3
    ctx->r24 = ADD32(ctx->r15, -0X3);
    // 0x80801C38: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80801C3C: beq         $at, $zero, L_80801E2C
    if (ctx->r1 == 0) {
        // 0x80801C40: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801E2C;
    }
    // 0x80801C40: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801C44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2144) << 16);
    // 0x80801C48: addu        $at, $at, $t8
    gpr jr_addend_80801C50 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801C4C: lw          $t8, 0x2144($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2144));
    // 0x80801C50: jr          $t8
    // 0x80801C54: nop

    switch (jr_addend_80801C50 >> 2) {
        case 0: goto L_80801C58; break;
        case 1: goto L_80801CB0; break;
        case 2: goto L_80801D64; break;
        case 3: goto L_80801E2C; break;
        case 4: goto L_80801E2C; break;
        case 5: goto L_80801E2C; break;
        case 6: goto L_80801E2C; break;
        case 7: goto L_80801DAC; break;
        case 8: goto L_80801E2C; break;
        default: switch_error(__func__, 0x80801C50, 0x80802144);
    }
    // 0x80801C54: nop

L_80801C58:
    // 0x80801C58: jal         0x800F54E4
    // 0x80801C5C: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80801C5C: nop

    after_1:
    // 0x80801C60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801C64: jal         0x800F5A00
    // 0x80801C68: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80801C68: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_2:
    // 0x80801C6C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801C70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801C74: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80801C78: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80801C7C: addiu       $s3, $sp, 0x68
    ctx->r19 = ADD32(ctx->r29, 0X68);
    // 0x80801C80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801C84: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x80801C88: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801C8C: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
L_80801C90:
    // 0x80801C90: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    // 0x80801C94: jal         0x800C8CB8
    // 0x80801C98: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_3;
    // 0x80801C98: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x80801C9C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801CA0: bne         $s0, $s2, L_80801C90
    if (ctx->r16 != ctx->r18) {
        // 0x80801CA4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80801C90;
    }
    // 0x80801CA4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80801CA8: b           L_80801E30
    // 0x80801CAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801E30;
    // 0x80801CAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801CB0:
    // 0x80801CB0: jal         0x800F54E4
    // 0x80801CB4: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80801CB4: nop

    after_4:
    // 0x80801CB8: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x80801CBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801CC0: jal         0x800F5A00
    // 0x80801CC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5A00(rdram, ctx);
        goto after_5;
    // 0x80801CC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80801CC8: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    // 0x80801CCC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2304, 0X23C0) << 16);
    // 0x80801CD0: addiu       $a2, $a2, 0x23C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2304, 0X23C0));
    // 0x80801CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CD8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801CDC: jal         0x800EFE50
    // 0x80801CE0: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    func_800EFE50(rdram, ctx);
        goto after_6;
    // 0x80801CE0: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    after_6:
    // 0x80801CE4: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    // 0x80801CE8: jal         0x800C8CB8
    // 0x80801CEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_7;
    // 0x80801CEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80801CF0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2304, 0X23CC) << 16);
    // 0x80801CF4: addiu       $a2, $a2, 0x23CC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2304, 0X23CC));
    // 0x80801CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801D00: jal         0x800EFE50
    // 0x80801D04: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    func_800EFE50(rdram, ctx);
        goto after_8;
    // 0x80801D04: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    after_8:
    // 0x80801D08: lw          $a0, 0x40($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X40);
    // 0x80801D0C: jal         0x800C8CB8
    // 0x80801D10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_9;
    // 0x80801D10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80801D14: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2304, 0X23D8) << 16);
    // 0x80801D18: addiu       $a2, $a2, 0x23D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2304, 0X23D8));
    // 0x80801D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801D24: jal         0x800EFE50
    // 0x80801D28: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    func_800EFE50(rdram, ctx);
        goto after_10;
    // 0x80801D28: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    after_10:
    // 0x80801D2C: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x80801D30: jal         0x800C8CB8
    // 0x80801D34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_11;
    // 0x80801D34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x80801D38: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2304, 0X23E4) << 16);
    // 0x80801D3C: addiu       $a2, $a2, 0x23E4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2304, 0X23E4));
    // 0x80801D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801D48: jal         0x800EFE50
    // 0x80801D4C: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    func_800EFE50(rdram, ctx);
        goto after_12;
    // 0x80801D4C: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    after_12:
    // 0x80801D50: lw          $a0, 0x48($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X48);
    // 0x80801D54: jal         0x800C8CB8
    // 0x80801D58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_13;
    // 0x80801D58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x80801D5C: b           L_80801E30
    // 0x80801D60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801E30;
    // 0x80801D60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801D64:
    // 0x80801D64: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2304, 0X23C0) << 16);
    // 0x80801D68: addiu       $a1, $a1, 0x23C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2304, 0X23C0));
    // 0x80801D6C: jal         0x800C8CB8
    // 0x80801D70: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    func_800C8CB8(rdram, ctx);
        goto after_14;
    // 0x80801D70: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    after_14:
    // 0x80801D74: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2304, 0X23CC) << 16);
    // 0x80801D78: addiu       $a1, $a1, 0x23CC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2304, 0X23CC));
    // 0x80801D7C: jal         0x800C8CB8
    // 0x80801D80: lw          $a0, 0x40($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X40);
    func_800C8CB8(rdram, ctx);
        goto after_15;
    // 0x80801D80: lw          $a0, 0x40($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X40);
    after_15:
    // 0x80801D84: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2304, 0X23D8) << 16);
    // 0x80801D88: addiu       $a1, $a1, 0x23D8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2304, 0X23D8));
    // 0x80801D8C: jal         0x800C8CB8
    // 0x80801D90: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    func_800C8CB8(rdram, ctx);
        goto after_16;
    // 0x80801D90: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    after_16:
    // 0x80801D94: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2304, 0X23E4) << 16);
    // 0x80801D98: addiu       $a1, $a1, 0x23E4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2304, 0X23E4));
    // 0x80801D9C: jal         0x800C8CB8
    // 0x80801DA0: lw          $a0, 0x48($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X48);
    func_800C8CB8(rdram, ctx);
        goto after_17;
    // 0x80801DA0: lw          $a0, 0x48($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X48);
    after_17:
    // 0x80801DA4: b           L_80801E30
    // 0x80801DA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801E30;
    // 0x80801DA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801DAC:
    // 0x80801DAC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2304, 0X23F0) << 16);
    // 0x80801DB0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2304, 0X23FC) << 16);
    // 0x80801DB4: addiu       $a2, $a2, 0x23FC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2304, 0X23FC));
    // 0x80801DB8: addiu       $a1, $a1, 0x23F0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2304, 0X23F0));
    // 0x80801DBC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80801DC0: jal         0x800F3214
    // 0x80801DC4: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    func_800F3214(rdram, ctx);
        goto after_18;
    // 0x80801DC4: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    after_18:
    // 0x80801DC8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80801DCC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801DD0: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80801DD4: jal         0x800F1214
    // 0x80801DD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F1214(rdram, ctx);
        goto after_19;
    // 0x80801DD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_19:
    // 0x80801DDC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80801DE0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801DE4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80801DE8: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80801DEC: jal         0x800F1214
    // 0x80801DF0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F1214(rdram, ctx);
        goto after_20;
    // 0x80801DF0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_20:
    // 0x80801DF4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80801DF8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80801DFC: addiu       $s2, $sp, 0x34
    ctx->r18 = ADD32(ctx->r29, 0X34);
    // 0x80801E00: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801E04: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_80801E08:
    // 0x80801E08: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801E0C: jal         0x800C8D4C
    // 0x80801E10: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C8D4C(rdram, ctx);
        goto after_21;
    // 0x80801E10: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_21:
    // 0x80801E14: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801E18: jal         0x800C8E84
    // 0x80801E1C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800C8E84(rdram, ctx);
        goto after_22;
    // 0x80801E1C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_22:
    // 0x80801E20: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80801E24: bne         $s1, $s3, L_80801E08
    if (ctx->r17 != ctx->r19) {
        // 0x80801E28: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80801E08;
    }
    // 0x80801E28: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80801E2C:
    // 0x80801E2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801E30:
    // 0x80801E30: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801E34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801E38: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E3C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801E40: jr          $ra
    // 0x80801E44: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80801E44: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80800260_chanemone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800264: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080026C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800270: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800274: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800278: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080027C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800280: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800284: jal         0x80102FDC
    // 0x80800288: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800288: nop

    after_0:
    // 0x8080028C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800290: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800294: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800298: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080029C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002A0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808002A4: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x808002A8: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x808002AC: jal         0x800DC178
    // 0x808002B0: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808002B0: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x808002B4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x808002B8: jal         0x80089F48
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002C0: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808002CC: jal         0x80089F50
    // 0x808002D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiesect_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808002D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808002D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void func_808018A0_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018A0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808018A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808018A8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808018AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808018B0: jal         0x80100094
    // 0x808018B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808018B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808018B8: jal         0x800D8FF8
    // 0x808018BC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808018BC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808018C0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x808018C4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808018C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808018CC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808018D0: beql        $t7, $at, L_8080193C
    if (ctx->r15 == ctx->r1) {
        // 0x808018D4: lhu         $t2, 0x72($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0X72);
            goto L_8080193C;
    }
    goto skip_0;
    // 0x808018D4: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x808018D8: jal         0x800CEAD0
    // 0x808018DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_2;
    // 0x808018DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x808018E0: beql        $v0, $zero, L_8080193C
    if (ctx->r2 == 0) {
        // 0x808018E4: lhu         $t2, 0x72($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0X72);
            goto L_8080193C;
    }
    goto skip_1;
    // 0x808018E4: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x808018E8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x808018EC: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x808018F0: sll         $t1, $t9, 18
    ctx->r9 = S32(ctx->r25 << 18);
    // 0x808018F4: bltzl       $t1, L_8080193C
    if (SIGNED(ctx->r9) < 0) {
        // 0x808018F8: lhu         $t2, 0x72($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0X72);
            goto L_8080193C;
    }
    goto skip_2;
    // 0x808018F8: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x808018FC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80801900: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80801904: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80801908: beq         $a0, $zero, L_8080191C
    if (ctx->r4 == 0) {
        // 0x8080190C: nop
    
            goto L_8080191C;
    }
    // 0x8080190C: nop

    // 0x80801910: jal         0x800863E8
    // 0x80801914: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80801914: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x80801918: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
L_8080191C:
    // 0x8080191C: jal         0x8010A570
    // 0x80801920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80801920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801928: jal         0x80101FDC
    // 0x8080192C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x8080192C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80801930: jal         0x80089CA8
    // 0x80801934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80801934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801938: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
L_8080193C:
    // 0x8080193C: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80801940: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80801944: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x80801948: beq         $at, $zero, L_80801D0C
    if (ctx->r1 == 0) {
        // 0x8080194C: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80801D0C;
    }
    // 0x8080194C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80801950: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X2198) << 16);
    // 0x80801954: addu        $at, $at, $t4
    gpr jr_addend_8080195C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80801958: lw          $t4, 0x2198($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1308, 0X2198));
    // 0x8080195C: jr          $t4
    // 0x80801960: nop

    switch (jr_addend_8080195C >> 2) {
        case 0: goto L_80801964; break;
        case 1: goto L_80801984; break;
        case 2: goto L_80801B94; break;
        case 3: goto L_80801D0C; break;
        case 4: goto L_80801C28; break;
        default: switch_error(__func__, 0x8080195C, 0x80802198);
    }
    // 0x80801960: nop

L_80801964:
    // 0x80801964: jal         0x80802020
    // 0x80801968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802020_chfactorytwinklies(rdram, ctx);
        goto after_7;
    // 0x80801968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080196C: beq         $v0, $zero, L_80801D0C
    if (ctx->r2 == 0) {
        // 0x80801970: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801D0C;
    }
    // 0x80801970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801974: jal         0x80101FDC
    // 0x80801978: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80801978: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8080197C: b           L_80801D10
    // 0x80801980: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
        goto L_80801D10;
    // 0x80801980: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
L_80801984:
    // 0x80801984: jal         0x80101F24
    // 0x80801988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_9;
    // 0x80801988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080198C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1308, 0X21C0) << 16);
    // 0x80801990: addiu       $a1, $a1, 0x21C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1308, 0X21C0));
    // 0x80801994: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801998: jal         0x800F3780
    // 0x8080199C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800F3780(rdram, ctx);
        goto after_10;
    // 0x8080199C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_10:
    // 0x808019A0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x808019A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019A8: jal         0x80101E14
    // 0x808019AC: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80101E14(rdram, ctx);
        goto after_11;
    // 0x808019AC: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_11:
    // 0x808019B0: beq         $v0, $zero, L_808019D4
    if (ctx->r2 == 0) {
        // 0x808019B4: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_808019D4;
    }
    // 0x808019B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808019B8: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x808019BC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1308, 0X2414) << 16);
    // 0x808019C0: addiu       $a3, $a3, 0x2414
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1308, 0X2414));
    // 0x808019C4: andi        $t5, $a1, 0x1
    ctx->r13 = ctx->r5 & 0X1;
    // 0x808019C8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x808019CC: jal         0x8010D930
    // 0x808019D0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_8010D930(rdram, ctx);
        goto after_12;
    // 0x808019D0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_12:
L_808019D4:
    // 0x808019D4: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808019D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019DC: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x808019E0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808019E4: bgez        $t8, L_80801A54
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808019E8: nop
    
            goto L_80801A54;
    }
    // 0x808019E8: nop

    // 0x808019EC: jal         0x80089BF0
    // 0x808019F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x808019F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_13:
    // 0x808019F4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x808019F8: jal         0x80801F5C
    // 0x808019FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801F5C_chfactorytwinklies(rdram, ctx);
        goto after_14;
    // 0x808019FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801A00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X21AC) << 16);
    // 0x80801A04: lwc1        $f4, 0x21AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X21AC));
    // 0x80801A08: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80801A0C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801A10: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A18: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x80801A1C: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    // 0x80801A20: jal         0x80102BF8
    // 0x80801A24: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    func_80102BF8(rdram, ctx);
        goto after_15;
    // 0x80801A24: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_15:
    // 0x80801A28: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801A2C: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80801A30: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x80801A34: ori         $a1, $a1, 0x1025
    ctx->r5 = ctx->r5 | 0X1025;
    // 0x80801A38: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A40: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80801A44: jal         0x8010C3A8
    // 0x80801A48: nop

    func_8010C3A8(rdram, ctx);
        goto after_16;
    // 0x80801A48: nop

    after_16:
    // 0x80801A4C: b           L_80801B40
    // 0x80801A50: nop

        goto L_80801B40;
    // 0x80801A50: nop

L_80801A54:
    // 0x80801A54: jal         0x80089F78
    // 0x80801A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_17;
    // 0x80801A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801A5C: beq         $v0, $zero, L_80801A94
    if (ctx->r2 == 0) {
        // 0x80801A60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A94;
    }
    // 0x80801A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A64: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80801A68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801A6C: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80801A70: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80801A74: addiu       $t9, $zero, 0x4802
    ctx->r25 = ADD32(0, 0X4802);
    // 0x80801A78: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801A7C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80801A80: jal         0x80089F90
    // 0x80801A84: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_18;
    // 0x80801A84: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_18:
    // 0x80801A88: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80801A8C: lhu         $t0, 0x6($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X6);
    // 0x80801A90: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
L_80801A94:
    // 0x80801A94: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80801A98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X21B0) << 16);
    // 0x80801A9C: lwc1        $f4, 0x21B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X21B0));
    // 0x80801AA0: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x80801AA4: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80801AA8: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80801AAC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80801AB0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80801AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AB8: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x80801ABC: jal         0x80089F88
    // 0x80801AC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_19;
    // 0x80801AC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_19:
    // 0x80801AC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801AC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801ACC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80801AD0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801AD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801AD8: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80801ADC: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x80801AE0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AE8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80801AEC: jal         0x80089F80
    // 0x80801AF0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_20;
    // 0x80801AF0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x80801AF4: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80801AF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801AFC: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80801B00: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801B04: lwc1        $f14, 0x30($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80801B08: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80801B0C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80801B10: jal         0x800F15F8
    // 0x80801B14: nop

    func_800F15F8(rdram, ctx);
        goto after_21;
    // 0x80801B14: nop

    after_21:
    // 0x80801B18: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80801B1C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80801B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B24: lw          $t5, 0x28($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X28);
    // 0x80801B28: addiu       $a1, $zero, 0x1325
    ctx->r5 = ADD32(0, 0X1325);
    // 0x80801B2C: sll         $t7, $t5, 18
    ctx->r15 = S32(ctx->r13 << 18);
    // 0x80801B30: bltz        $t7, L_80801B40
    if (SIGNED(ctx->r15) < 0) {
        // 0x80801B34: nop
    
            goto L_80801B40;
    }
    // 0x80801B34: nop

    // 0x80801B38: jal         0x8010C3A8
    // 0x80801B3C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    func_8010C3A8(rdram, ctx);
        goto after_22;
    // 0x80801B3C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    after_22:
L_80801B40:
    // 0x80801B40: jal         0x800D9078
    // 0x80801B44: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_23;
    // 0x80801B44: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_23:
    // 0x80801B48: beql        $v0, $zero, L_80801D10
    if (ctx->r2 == 0) {
        // 0x80801B4C: lw          $t0, 0x50($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X50);
            goto L_80801D10;
    }
    goto skip_3;
    // 0x80801B4C: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    skip_3:
    // 0x80801B50: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80801B54: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80801B58: beql        $a0, $zero, L_80801B70
    if (ctx->r4 == 0) {
        // 0x80801B5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B70;
    }
    goto skip_4;
    // 0x80801B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80801B60: jal         0x800863E8
    // 0x80801B64: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_24;
    // 0x80801B64: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_24:
    // 0x80801B68: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80801B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801B70:
    // 0x80801B70: jal         0x80101FDC
    // 0x80801B74: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_25;
    // 0x80801B74: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_25:
    // 0x80801B78: lbu         $t8, 0x64($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X64);
    // 0x80801B7C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X21B4) << 16);
    // 0x80801B80: lwc1        $f4, 0x21B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X21B4));
    // 0x80801B84: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80801B88: sb          $t9, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r25;
    // 0x80801B8C: b           L_80801D0C
    // 0x80801B90: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
        goto L_80801D0C;
    // 0x80801B90: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
L_80801B94:
    // 0x80801B94: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80801B98: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80801B9C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801BA0: sll         $t2, $t0, 12
    ctx->r10 = S32(ctx->r8 << 12);
    // 0x80801BA4: bltz        $t2, L_80801C08
    if (SIGNED(ctx->r10) < 0) {
        // 0x80801BA8: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_80801C08;
    }
    // 0x80801BA8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801BAC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801BB0: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80801BB4: jal         0x800F10B4
    // 0x80801BB8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_26;
    // 0x80801BB8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_26:
    // 0x80801BBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X21B8) << 16);
    // 0x80801BC0: lwc1        $f6, 0x21B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X21B8));
    // 0x80801BC4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80801BC8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801BCC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80801BD0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1308, 0X2428) << 16);
    // 0x80801BD4: bc1f        L_80801C08
    if (!c1cs) {
        // 0x80801BD8: nop
    
            goto L_80801C08;
    }
    // 0x80801BD8: nop

    // 0x80801BDC: lbu         $t3, 0x75($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X75);
    // 0x80801BE0: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80801BE4: addiu       $a3, $a3, 0x2428
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1308, 0X2428));
    // 0x80801BE8: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x80801BEC: andi        $t5, $a1, 0x1
    ctx->r13 = ctx->r5 & 0X1;
    // 0x80801BF0: sb          $t4, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r12;
    // 0x80801BF4: jal         0x8010D930
    // 0x80801BF8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    func_8010D930(rdram, ctx);
        goto after_27;
    // 0x80801BF8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_27:
    // 0x80801BFC: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80801C00: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80801C04: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_80801C08:
    // 0x80801C08: jal         0x8080207C
    // 0x80801C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080207C_chfactorytwinklies(rdram, ctx);
        goto after_28;
    // 0x80801C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80801C10: beql        $v0, $zero, L_80801D10
    if (ctx->r2 == 0) {
        // 0x80801C14: lw          $t0, 0x50($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X50);
            goto L_80801D10;
    }
    goto skip_5;
    // 0x80801C14: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    skip_5:
    // 0x80801C18: jal         0x800FFAB0
    // 0x80801C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_29;
    // 0x80801C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80801C20: b           L_80801D10
    // 0x80801C24: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
        goto L_80801D10;
    // 0x80801C24: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
L_80801C28:
    // 0x80801C28: jal         0x800D9078
    // 0x80801C2C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_30;
    // 0x80801C2C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_30:
    // 0x80801C30: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801C34: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80801C38: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801C3C: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80801C40: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801C44: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801C48: jal         0x800F12D4
    // 0x80801C4C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_31;
    // 0x80801C4C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_31:
    // 0x80801C50: jal         0x800D8FF8
    // 0x80801C54: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_32;
    // 0x80801C54: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_32:
    // 0x80801C58: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801C5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801C60: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80801C64: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801C68: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80801C6C: jal         0x800D8FF8
    // 0x80801C70: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_33;
    // 0x80801C70: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    after_33:
    // 0x80801C74: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801C78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801C7C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801C80: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801C84: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80801C88: jal         0x800D8FF8
    // 0x80801C8C: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_34;
    // 0x80801C8C: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    after_34:
    // 0x80801C90: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80801C94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801C98: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801C9C: lwc1        $f12, 0x38($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801CA0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80801CA4: jal         0x800F15F8
    // 0x80801CA8: nop

    func_800F15F8(rdram, ctx);
        goto after_35;
    // 0x80801CA8: nop

    after_35:
    // 0x80801CAC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80801CB0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80801CB4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80801CB8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801CBC: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x80801CC0: jal         0x800EFE50
    // 0x80801CC4: addiu       $a2, $v0, 0x1C
    ctx->r6 = ADD32(ctx->r2, 0X1C);
    func_800EFE50(rdram, ctx);
        goto after_36;
    // 0x80801CC4: addiu       $a2, $v0, 0x1C
    ctx->r6 = ADD32(ctx->r2, 0X1C);
    after_36:
    // 0x80801CC8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80801CCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801CD0: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801CD4: mul.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80801CD8: jal         0x80013970
    // 0x80801CDC: nop

    func_80013970(rdram, ctx);
        goto after_37;
    // 0x80801CDC: nop

    after_37:
    // 0x80801CE0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80801CE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801CE8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801CEC: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80801CF0: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80801CF4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80801CF8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80801CFC: beql        $t9, $zero, L_80801D10
    if (ctx->r25 == 0) {
        // 0x80801D00: lw          $t0, 0x50($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X50);
            goto L_80801D10;
    }
    goto skip_6;
    // 0x80801D00: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    skip_6:
    // 0x80801D04: jal         0x800FFAB0
    // 0x80801D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_38;
    // 0x80801D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
L_80801D0C:
    // 0x80801D0C: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
L_80801D10:
    // 0x80801D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D14: beql        $t0, $zero, L_80801D48
    if (ctx->r8 == 0) {
        // 0x80801D18: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80801D48;
    }
    goto skip_7;
    // 0x80801D18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x80801D1C: jal         0x80103DFC
    // 0x80801D20: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80103DFC(rdram, ctx);
        goto after_39;
    // 0x80801D20: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_39:
    // 0x80801D24: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801D28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801D2C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801D30: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801D34: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80801D38: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80801D3C: jal         0x800C8CB8
    // 0x80801D40: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    func_800C8CB8(rdram, ctx);
        goto after_40;
    // 0x80801D40: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    after_40:
    // 0x80801D44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801D48:
    // 0x80801D48: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801D4C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80801D50: jr          $ra
    // 0x80801D54: nop

    return;
    // 0x80801D54: nop

;}
RECOMP_FUNC void func_800F4B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4B20: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4B28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4B30: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4B34: jal         0x800A4E30
    // 0x800F4B38: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A4E30(rdram, ctx);
        goto after_0;
    // 0x800F4B38: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4B40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4B44: jr          $ra
    // 0x800F4B48: nop

    return;
    // 0x800F4B48: nop

;}
RECOMP_FUNC void func_80800020_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800028: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8080002C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800030: lh          $a1, 0x10($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X10);
    // 0x80800034: beq         $a1, $zero, L_80800058
    if (ctx->r5 == 0) {
        // 0x80800038: sll         $a0, $a1, 16
        ctx->r4 = S32(ctx->r5 << 16);
            goto L_80800058;
    }
    // 0x80800038: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x8080003C: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800040: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80800044: jal         0x800ADFE0
    // 0x80800048: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800ADFE0(rdram, ctx);
        goto after_0;
    // 0x80800048: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080004C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80800054: sh          $zero, 0x10($t8)
    MEM_H(0X10, ctx->r24) = 0;
L_80800058:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_80801F88_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F88: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801F8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801F90: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801F94: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801F98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801F9C: jal         0x80800000
    // 0x80801FA0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_80800000_ncpoddialog(rdram, ctx);
        goto after_0;
    // 0x80801FA0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80801FA4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80801FA8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80801FAC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80801FB0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80801FB4: jal         0x800EE780
    // 0x80801FB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EE780(rdram, ctx);
        goto after_1;
    // 0x80801FB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80801FBC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80801FC0: jal         0x800EF334
    // 0x80801FC4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800EF334(rdram, ctx);
        goto after_2;
    // 0x80801FC4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_2:
    // 0x80801FC8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801FCC: jal         0x800F1DF4
    // 0x80801FD0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x80801FD0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80801FD4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801FD8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80801FDC: jal         0x800F1828
    // 0x80801FE0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800F1828(rdram, ctx);
        goto after_4;
    // 0x80801FE0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80801FE4: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801FE8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801FEC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801FF0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80801FF4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80801FF8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80801FFC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80802000: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x80802004: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80802008: jal         0x800EEC30
    // 0x8080200C: nop

    func_800EEC30(rdram, ctx);
        goto after_5;
    // 0x8080200C: nop

    after_5:
    // 0x80802010: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80802014: lui         $a3, 0xBDCC
    ctx->r7 = S32(0XBDCC << 16);
    // 0x80802018: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080201C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80802020: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80802024: jal         0x800EE7B4
    // 0x80802028: addiu       $a0, $a0, 0x148
    ctx->r4 = ADD32(ctx->r4, 0X148);
    func_800EE7B4(rdram, ctx);
        goto after_6;
    // 0x80802028: addiu       $a0, $a0, 0x148
    ctx->r4 = ADD32(ctx->r4, 0X148);
    after_6:
    // 0x8080202C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80802030: jal         0x800EF04C
    // 0x80802034: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80802034: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_7:
    // 0x80802038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080203C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802040: jr          $ra
    // 0x80802044: nop

    return;
    // 0x80802044: nop

;}
RECOMP_FUNC void func_808034DC_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808034DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808034E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808034E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808034E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808034EC: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x808034F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808034F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808034F8: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x808034FC: bgez        $t9, L_8080352C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80803500: nop
    
            goto L_8080352C;
    }
    // 0x80803500: nop

    // 0x80803504: jal         0x800DF744
    // 0x80803508: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80803508: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8080350C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80803510: jal         0x800DF744
    // 0x80803514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80803514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80803518: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8080351C: jal         0x800DF744
    // 0x80803520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80803520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80803524: b           L_80803550
    // 0x80803528: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80803550;
    // 0x80803528: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080352C:
    // 0x8080352C: jal         0x800DF744
    // 0x80803530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80803530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80803534: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80803538: jal         0x800DF744
    // 0x8080353C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x8080353C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80803540: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80803544: jal         0x800DF744
    // 0x80803548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x80803548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080354C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80803550:
    // 0x80803550: jal         0x80101870
    // 0x80803554: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_6;
    // 0x80803554: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x80803558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080355C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803560: jr          $ra
    // 0x80803564: nop

    return;
    // 0x80803564: nop

;}
RECOMP_FUNC void func_8010C820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C824: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010C828: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8010C82C: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8010C830: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010C834: addiu       $t8, $t7, 0x1E
    ctx->r24 = ADD32(ctx->r15, 0X1E);
    // 0x8010C838: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8010C83C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010C840: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010C844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010C84C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8010C850: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010C854: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010C858: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8010C85C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8010C860: jal         0x8010C788
    // 0x8010C864: nop

    func_8010C788(rdram, ctx);
        goto after_0;
    // 0x8010C864: nop

    after_0:
    // 0x8010C868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C86C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C870: jr          $ra
    // 0x8010C874: nop

    return;
    // 0x8010C874: nop

;}
RECOMP_FUNC void bastick_func_8009F1A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F1A4: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009F1A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009F1AC: lbu         $t7, 0x64($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X64);
    // 0x8009F1B0: beq         $t7, $zero, L_8009F1C0
    if (ctx->r15 == 0) {
        // 0x8009F1B4: nop
    
            goto L_8009F1C0;
    }
    // 0x8009F1B4: nop

    // 0x8009F1B8: jr          $ra
    // 0x8009F1BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009F1BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009F1C0:
    // 0x8009F1C0: jr          $ra
    // 0x8009F1C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8009F1C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void chlakemonster_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808018DC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808018E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808018E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808018E8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808018EC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808018F0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808018F4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808018F8: jal         0x800B53A4
    // 0x808018FC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x808018FC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80801900: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801904: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801908: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080190C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801910: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80801914: nop

    // 0x80801918: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8080191C: jal         0x800BA568
    // 0x80801920: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    func_800BA568(rdram, ctx);
        goto after_1;
    // 0x80801920: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x80801924: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80801928: addiu       $a1, $a1, 0x6CC8
    ctx->r5 = ADD32(ctx->r5, 0X6CC8);
    // 0x8080192C: jal         0x800BA544
    // 0x80801930: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800BA544(rdram, ctx);
        goto after_2;
    // 0x80801930: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80801934: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801938: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080193C: jal         0x800DC298
    // 0x80801940: nop

    func_800DC298(rdram, ctx);
        goto after_3;
    // 0x80801940: nop

    after_3:
    // 0x80801944: beq         $v0, $zero, L_80801970
    if (ctx->r2 == 0) {
        // 0x80801948: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80801970;
    }
    // 0x80801948: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080194C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801950: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801954: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80801958: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8080195C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80801960: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80801964: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80801968: b           L_80801990
    // 0x8080196C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
        goto L_80801990;
    // 0x8080196C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
L_80801970:
    // 0x80801970: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801974: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801978: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8080197C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80801980: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x80801984: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80801988: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8080198C: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_80801990:
    // 0x80801990: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1748, 0X224C) << 16);
    // 0x80801994: addiu       $t9, $t9, 0x224C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1748, 0X224C));
    // 0x80801998: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080199C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808019A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808019A4: jal         0x800BABB8
    // 0x808019A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x808019A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x808019AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808019B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808019B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808019B8: jal         0x800BA1D0
    // 0x808019BC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_800BA1D0(rdram, ctx);
        goto after_5;
    // 0x808019BC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_5:
    // 0x808019C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808019C4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808019C8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808019CC: jr          $ra
    // 0x808019D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808019D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ncbadeflect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800004: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800008: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80800014: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800018: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8080001C: jal         0x80111094
    // 0x80800020: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80111094(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80800024: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80800028: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8080002C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800030: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800034: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800038: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8080003C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80800040: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800044: add.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80800048: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8080004C: nop

    // 0x80800050: bc1tl       L_80800170
    if (c1cs) {
        // 0x80800054: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800170;
    }
    goto skip_0;
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800058: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8080005C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800060: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80800064: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80800068: nop

    // 0x8080006C: bc1tl       L_80800170
    if (c1cs) {
        // 0x80800070: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800170;
    }
    goto skip_1;
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800074: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800078: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8080007C: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800080: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800084: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800088: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080008C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80800090: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800094: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800098: jal         0x800EFA4C
    // 0x8080009C: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x8080009C: nop

    after_1:
    // 0x808000A0: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808000A4: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808000A8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808000AC: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x808000B0: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808000B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000B8: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x808000BC: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808000C0: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x808000C4: add.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x808000C8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808000CC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x808000D0: add.s       $f20, $f18, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x808000D4: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x808000D8: nop

    // 0x808000DC: bc1tl       L_80800170
    if (c1cs) {
        // 0x808000E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800170;
    }
    goto skip_2;
    // 0x808000E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808000E4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808000E8: jal         0x8002DCA0
    // 0x808000EC: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x808000EC: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x808000F0: jal         0x800D8FF8
    // 0x808000F4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x808000F4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x808000F8: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x808000FC: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800100: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800104: jal         0x800F13F0
    // 0x80800108: sub.s       $f14, $f2, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f20.fl;
    func_800F13F0(rdram, ctx);
        goto after_4;
    // 0x80800108: sub.s       $f14, $f2, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f20.fl;
    after_4:
    // 0x8080010C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800110: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80800114: c.eq.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl == ctx->f18.fl;
    // 0x80800118: nop

    // 0x8080011C: bc1fl       L_8080014C
    if (!c1cs) {
        // 0x80800120: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_8080014C;
    }
    goto skip_3;
    // 0x80800120: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    skip_3:
    // 0x80800124: jal         0x800DC0C0
    // 0x80800128: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80800128: nop

    after_5:
    // 0x8080012C: jal         0x800DC0C0
    // 0x80800130: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800DC0C0(rdram, ctx);
        goto after_6;
    // 0x80800130: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_6:
    // 0x80800134: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800138: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080013C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800140: jal         0x800EFA4C
    // 0x80800144: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x80800144: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_7:
    // 0x80800148: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
L_8080014C:
    // 0x8080014C: jal         0x800EF368
    // 0x80800150: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800EF368(rdram, ctx);
        goto after_8;
    // 0x80800150: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_8:
    // 0x80800154: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800158: jal         0x800EF04C
    // 0x8080015C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x8080015C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_9:
    // 0x80800160: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800164: jal         0x801110C4
    // 0x80800168: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_801110C4(rdram, ctx);
        goto after_10;
    // 0x80800168: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_10:
    // 0x8080016C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800170:
    // 0x80800170: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800174: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void func_80800E44_sudeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E48: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800E4C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E54: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800E58: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80800E5C: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80800E60: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800E64: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800E68: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800E6C: sub.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80800E70: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80800E74: nop

    // 0x80800E78: bc1fl       L_80800E8C
    if (!c1cs) {
        // 0x80800E7C: add.s       $f10, $f0, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
            goto L_80800E8C;
    }
    goto skip_0;
    // 0x80800E7C: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    skip_0:
    // 0x80800E80: b           L_80800EBC
    // 0x80800E84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EBC;
    // 0x80800E84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800E88: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
L_80800E8C:
    // 0x80800E8C: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800E90: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800E94: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800E98: nop

    // 0x80800E9C: bc1fl       L_80800EB0
    if (!c1cs) {
        // 0x80800EA0: add.s       $f4, $f18, $f14
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
            goto L_80800EB0;
    }
    goto skip_1;
    // 0x80800EA0: add.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
    skip_1:
    // 0x80800EA4: b           L_80800EBC
    // 0x80800EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EBC;
    // 0x80800EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800EAC: add.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
L_80800EB0:
    // 0x80800EB0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800EB4: jal         0x800F0064
    // 0x80800EB8: nop

    func_800F0064(rdram, ctx);
        goto after_0;
    // 0x80800EB8: nop

    after_0:
L_80800EBC:
    // 0x80800EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EC4: jr          $ra
    // 0x80800EC8: nop

    return;
    // 0x80800EC8: nop

;}
RECOMP_FUNC void func_80027170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027170: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80027174: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027178: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002717C: nop

    // 0x80027180: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
    // 0x80027184: bltz        $a0, L_8002719C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80027188: nop
    
            goto L_8002719C;
    }
    // 0x80027188: nop

    // 0x8002718C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80027190: lwc1        $f6, 0x1CD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1CD0);
    // 0x80027194: b           L_800271AC
    // 0x80027198: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
        goto L_800271AC;
    // 0x80027198: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
L_8002719C:
    // 0x8002719C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800271A0: lwc1        $f8, 0x1CD4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1CD4);
    // 0x800271A4: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x800271A8: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_800271AC:
    // 0x800271AC: beq         $a0, $zero, L_800271E8
    if (ctx->r4 == 0) {
        // 0x800271B0: nop
    
            goto L_800271E8;
    }
    // 0x800271B0: nop

L_800271B4:
    // 0x800271B4: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800271B8: beq         $t6, $zero, L_800271D0
    if (ctx->r14 == 0) {
        // 0x800271BC: nop
    
            goto L_800271D0;
    }
    // 0x800271BC: nop

    // 0x800271C0: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800271C4: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800271C8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800271CC: swc1        $f18, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f18.u32l;
L_800271D0:
    // 0x800271D0: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800271D4: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800271D8: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800271DC: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800271E0: bne         $a0, $zero, L_800271B4
    if (ctx->r4 != 0) {
        // 0x800271E4: nop
    
            goto L_800271B4;
    }
    // 0x800271E4: nop

L_800271E8:
    // 0x800271E8: b           L_800271F8
    // 0x800271EC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
        goto L_800271F8;
    // 0x800271EC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800271F0: b           L_800271F8
    // 0x800271F4: nop

        goto L_800271F8;
    // 0x800271F4: nop

L_800271F8:
    // 0x800271F8: jr          $ra
    // 0x800271FC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800271FC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800840E0: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x800840E0);
    return;
    // 0x800840E4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800468_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080046C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800470: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800478: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8080047C: bgez        $t8, L_80800498
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800480: nop
    
            goto L_80800498;
    }
    // 0x80800480: nop

    // 0x80800484: jal         0x80089BD8
    // 0x80800488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080048C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80800490: b           L_80800498
    // 0x80800494: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
        goto L_80800498;
    // 0x80800494: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_80800498:
    // 0x80800498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080049C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004A0: jr          $ra
    // 0x808004A4: nop

    return;
    // 0x808004A4: nop

;}
RECOMP_FUNC void func_80800E84_sumultiscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E84: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800E88: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800E8C: jr          $ra
    // 0x80800E90: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80800E90: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void func_80800744_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800744: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800748: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080074C: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80800750: slti        $at, $a1, 0x151E
    ctx->r1 = SIGNED(ctx->r5) < 0X151E ? 1 : 0;
    // 0x80800754: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800758: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080075C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80800760: bne         $at, $zero, L_8080077C
    if (ctx->r1 != 0) {
        // 0x80800764: sw          $t6, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r14;
            goto L_8080077C;
    }
    // 0x80800764: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80800768: addiu       $at, $zero, 0x1553
    ctx->r1 = ADD32(0, 0X1553);
    // 0x8080076C: beq         $a1, $at, L_808008AC
    if (ctx->r5 == ctx->r1) {
        // 0x80800770: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008AC;
    }
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800774: b           L_808008D4
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008D4;
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080077C:
    // 0x8080077C: addiu       $t7, $a1, -0x1518
    ctx->r15 = ADD32(ctx->r5, -0X1518);
    // 0x80800780: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80800784: beq         $at, $zero, L_808008D0
    if (ctx->r1 == 0) {
        // 0x80800788: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808008D0;
    }
    // 0x80800788: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080078C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(800, 0XFD8) << 16);
    // 0x80800790: addu        $at, $at, $t7
    gpr jr_addend_80800798 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800794: lw          $t7, 0xFD8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(800, 0XFD8));
    // 0x80800798: jr          $t7
    // 0x8080079C: nop

    switch (jr_addend_80800798 >> 2) {
        case 0: goto L_808007A0; break;
        case 1: goto L_808007A8; break;
        case 2: goto L_8080082C; break;
        case 3: goto L_8080082C; break;
        case 4: goto L_80800838; break;
        case 5: goto L_80800860; break;
        default: switch_error(__func__, 0x80800798, 0x80800FD8);
    }
    // 0x8080079C: nop

L_808007A0:
    // 0x808007A0: jal         0x800DA544
    // 0x808007A4: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x808007A4: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_0:
L_808007A8:
    // 0x808007A8: jal         0x800DA544
    // 0x808007AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808007AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808007B0: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x808007B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007B8: bne         $v0, $zero, L_808007E8
    if (ctx->r2 != 0) {
        // 0x808007BC: nop
    
            goto L_808007E8;
    }
    // 0x808007BC: nop

    // 0x808007C0: jal         0x80800BD8
    // 0x808007C4: nop

    func_80800BD8_chhoneyb(rdram, ctx);
        goto after_2;
    // 0x808007C4: nop

    after_2:
    // 0x808007C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007CC: bne         $v0, $at, L_808007E0
    if (ctx->r2 != ctx->r1) {
        // 0x808007D0: addiu       $t9, $zero, 0x1520
        ctx->r25 = ADD32(0, 0X1520);
            goto L_808007E0;
    }
    // 0x808007D0: addiu       $t9, $zero, 0x1520
    ctx->r25 = ADD32(0, 0X1520);
    // 0x808007D4: addiu       $t8, $zero, 0x151F
    ctx->r24 = ADD32(0, 0X151F);
    // 0x808007D8: b           L_80800800
    // 0x808007DC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_80800800;
    // 0x808007DC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_808007E0:
    // 0x808007E0: b           L_80800800
    // 0x808007E4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_80800800;
    // 0x808007E4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_808007E8:
    // 0x808007E8: bne         $v0, $at, L_808007FC
    if (ctx->r2 != ctx->r1) {
        // 0x808007EC: addiu       $t1, $zero, 0x151B
        ctx->r9 = ADD32(0, 0X151B);
            goto L_808007FC;
    }
    // 0x808007EC: addiu       $t1, $zero, 0x151B
    ctx->r9 = ADD32(0, 0X151B);
    // 0x808007F0: addiu       $t0, $zero, 0x151A
    ctx->r8 = ADD32(0, 0X151A);
    // 0x808007F4: b           L_80800800
    // 0x808007F8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
        goto L_80800800;
    // 0x808007F8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_808007FC:
    // 0x808007FC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_80800800:
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800804: jal         0x80100094
    // 0x80800808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800814: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800818: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080081C: jal         0x8008A2C8
    // 0x80800820: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800820: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80800824: b           L_808008F8
    // 0x80800828: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
        goto L_808008F8;
    // 0x80800828: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_8080082C:
    // 0x8080082C: addiu       $t2, $zero, 0x151C
    ctx->r10 = ADD32(0, 0X151C);
    // 0x80800830: b           L_808008F4
    // 0x80800834: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_808008F4;
    // 0x80800834: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_80800838:
    // 0x80800838: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080083C: bne         $a2, $at, L_80800850
    if (ctx->r6 != ctx->r1) {
        // 0x80800840: addiu       $t5, $zero, 0x4E
        ctx->r13 = ADD32(0, 0X4E);
            goto L_80800850;
    }
    // 0x80800840: addiu       $t5, $zero, 0x4E
    ctx->r13 = ADD32(0, 0X4E);
    // 0x80800844: addiu       $t3, $zero, 0x151D
    ctx->r11 = ADD32(0, 0X151D);
    // 0x80800848: b           L_80800858
    // 0x8080084C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
        goto L_80800858;
    // 0x8080084C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80800850:
    // 0x80800850: addiu       $t4, $zero, 0x151E
    ctx->r12 = ADD32(0, 0X151E);
    // 0x80800854: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_80800858:
    // 0x80800858: b           L_808008F4
    // 0x8080085C: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
        goto L_808008F4;
    // 0x8080085C: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_80800860:
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800864: jal         0x80100094
    // 0x80800868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80800868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080086C: jal         0x80089FE0
    // 0x80800870: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800870: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    after_6:
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800878: jal         0x80100094
    // 0x8080087C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x8080087C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800884: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800888: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080088C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800890: jal         0x8008A2C8
    // 0x80800894: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x80800894: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080089C: jal         0x80102424
    // 0x808008A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x808008A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x808008A4: b           L_808008F8
    // 0x808008A8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
        goto L_808008F8;
    // 0x808008A8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_808008AC:
    // 0x808008AC: jal         0x80100094
    // 0x808008B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x808008B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B8: jal         0x8008A2C0
    // 0x808008BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x808008BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x808008C0: jal         0x8080011C
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080011C_chhoneyb(rdram, ctx);
        goto after_12;
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808008C8: b           L_808008F8
    // 0x808008CC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
        goto L_808008F8;
    // 0x808008CC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_808008D0:
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008D4:
    // 0x808008D4: jal         0x80100094
    // 0x808008D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_13;
    // 0x808008D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E0: jal         0x8008A2C0
    // 0x808008E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x808008E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008EC: jal         0x80102424
    // 0x808008F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x808008F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
L_808008F4:
    // 0x808008F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_808008F8:
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008FC: beq         $t6, $zero, L_8080090C
    if (ctx->r14 == 0) {
        // 0x80800900: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_8080090C;
    }
    // 0x80800900: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80800904: jal         0x80800018
    // 0x80800908: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80800018_chhoneyb(rdram, ctx);
        goto after_16;
    // 0x80800908: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_16:
L_8080090C:
    // 0x8080090C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800910: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800914: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800918: jr          $ra
    // 0x8080091C: nop

    return;
    // 0x8080091C: nop

;}
RECOMP_FUNC void func_80800D2C_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D38: addiu       $a0, $zero, 0xE2
    ctx->r4 = ADD32(0, 0XE2);
    // 0x80800D3C: jal         0x800DA9E4
    // 0x80800D40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_0;
    // 0x80800D40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800D44: bne         $v0, $zero, L_80800D60
    if (ctx->r2 != 0) {
        // 0x80800D48: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800D60;
    }
    // 0x80800D48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D4C: addiu       $a1, $zero, 0x11B5
    ctx->r5 = ADD32(0, 0X11B5);
    // 0x80800D50: jal         0x80800338
    // 0x80800D54: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_1;
    // 0x80800D54: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_1:
    // 0x80800D58: b           L_80800D64
    // 0x80800D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D64;
    // 0x80800D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D60:
    // 0x80800D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D64:
    // 0x80800D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D6C: jr          $ra
    // 0x80800D70: nop

    return;
    // 0x80800D70: nop

;}
RECOMP_FUNC void func_808016F0_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808016F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016F8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808016FC: andi        $t7, $a2, 0x2
    ctx->r15 = ctx->r6 & 0X2;
    // 0x80801700: bne         $a1, $t6, L_80801710
    if (ctx->r5 != ctx->r14) {
        // 0x80801704: nop
    
            goto L_80801710;
    }
    // 0x80801704: nop

    // 0x80801708: b           L_80801774
    // 0x8080170C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80801774;
    // 0x8080170C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80801710:
    // 0x80801710: beq         $t7, $zero, L_80801754
    if (ctx->r15 == 0) {
        // 0x80801714: andi        $t2, $a2, 0x1
        ctx->r10 = ctx->r6 & 0X1;
            goto L_80801754;
    }
    // 0x80801714: andi        $t2, $a2, 0x1
    ctx->r10 = ctx->r6 & 0X1;
    // 0x80801718: lhu         $t8, 0x18($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X18);
    // 0x8080171C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80801720: beq         $t9, $zero, L_80801754
    if (ctx->r25 == 0) {
        // 0x80801724: nop
    
            goto L_80801754;
    }
    // 0x80801724: nop

    // 0x80801728: jal         0x80106790
    // 0x8080172C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080172C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80801730: lw          $t0, 0x64($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X64);
    // 0x80801734: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80801738: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x8080173C: beq         $t1, $zero, L_8080174C
    if (ctx->r9 == 0) {
        // 0x80801740: nop
    
            goto L_8080174C;
    }
    // 0x80801740: nop

    // 0x80801744: b           L_80801774
    // 0x80801748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801774;
    // 0x80801748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080174C:
    // 0x8080174C: b           L_80801774
    // 0x80801750: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80801774;
    // 0x80801750: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80801754:
    // 0x80801754: beq         $t2, $zero, L_80801774
    if (ctx->r10 == 0) {
        // 0x80801758: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80801774;
    }
    // 0x80801758: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8080175C: lw          $t3, 0x24($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X24);
    // 0x80801760: srl         $t4, $t3, 22
    ctx->r12 = S32(U32(ctx->r11) >> 22);
    // 0x80801764: bne         $t4, $zero, L_80801774
    if (ctx->r12 != 0) {
        // 0x80801768: nop
    
            goto L_80801774;
    }
    // 0x80801768: nop

    // 0x8080176C: b           L_80801774
    // 0x80801770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801774;
    // 0x80801770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801774:
    // 0x80801774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080177C: jr          $ra
    // 0x80801780: nop

    return;
    // 0x80801780: nop

;}
RECOMP_FUNC void func_80800EC8_chminisubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EC8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800ECC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800ED0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800ED4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800ED8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800EDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800EE0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800EE4: beq         $t6, $at, L_80800F58
    if (ctx->r14 == ctx->r1) {
        // 0x80800EE8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800F58;
    }
    // 0x80800EE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800EEC: beq         $t6, $at, L_80800F80
    if (ctx->r14 == ctx->r1) {
        // 0x80800EF0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800F80;
    }
    // 0x80800EF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800EF4: bnel        $t6, $at, L_80801048
    if (ctx->r14 != ctx->r1) {
        // 0x80800EF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801048;
    }
    goto skip_0;
    // 0x80800EF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800EFC: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80800F00: bltz        $t7, L_80800F38
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800F04: nop
    
            goto L_80800F38;
    }
    // 0x80800F04: nop

    // 0x80800F08: jal         0x800E3980
    // 0x80800F0C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x80800F0C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F14: jal         0x80102D78
    // 0x80800F18: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x80800F18: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80800F1C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800F20: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800F24: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F2C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800F30: jal         0x80102BF8
    // 0x80800F34: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_2;
    // 0x80800F34: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_2:
L_80800F38:
    // 0x80800F38: jal         0x800DA298
    // 0x80800F3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800F3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80800F40: bne         $v0, $zero, L_80801044
    if (ctx->r2 != 0) {
        // 0x80800F44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801044;
    }
    // 0x80800F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F48: jal         0x80102424
    // 0x80800F4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800F4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800F50: b           L_80801048
    // 0x80800F54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801048;
    // 0x80800F54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F58:
    // 0x80800F58: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800F5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800F60: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F68: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800F6C: nop

    // 0x80800F70: bc1f        L_80800F80
    if (!c1cs) {
        // 0x80800F74: nop
    
            goto L_80800F80;
    }
    // 0x80800F74: nop

    // 0x80800F78: jal         0x80102424
    // 0x80800F7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800F7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_80800F80:
    // 0x80800F80: jal         0x8010D600
    // 0x80800F84: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8010D600(rdram, ctx);
        goto after_6;
    // 0x80800F84: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x80800F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F8C: jal         0x80102D78
    // 0x80800F90: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80102D78(rdram, ctx);
        goto after_7;
    // 0x80800F90: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_7:
    // 0x80800F94: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800F98: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800F9C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA4: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800FA8: jal         0x80102BF8
    // 0x80800FAC: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_8;
    // 0x80800FAC: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_8:
    // 0x80800FB0: jal         0x800D8FF8
    // 0x80800FB4: nop

    func_800D8FF8(rdram, ctx);
        goto after_9;
    // 0x80800FB4: nop

    after_9:
    // 0x80800FB8: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800FBC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800FC0: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x80800FC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800FC8: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800FCC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80800FD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800FD4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800FD8: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800FDC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80800FE0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800FE4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80800FE8: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    // 0x80800FEC: jal         0x80013970
    // 0x80800FF0: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    func_80013970(rdram, ctx);
        goto after_10;
    // 0x80800FF0: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_10:
    // 0x80800FF4: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800FF8: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800FFC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80801000: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801004: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80801008: jal         0x800D9078
    // 0x8080100C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    func_800D9078(rdram, ctx);
        goto after_11;
    // 0x8080100C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    after_11:
    // 0x80801010: bnel        $v0, $zero, L_80801038
    if (ctx->r2 != 0) {
        // 0x80801014: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801038;
    }
    goto skip_1;
    // 0x80801014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80801018: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080101C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801020: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80801024: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80801028: jal         0x8010C9B0
    // 0x8080102C: nop

    func_8010C9B0(rdram, ctx);
        goto after_12;
    // 0x8080102C: nop

    after_12:
    // 0x80801030: beq         $v0, $zero, L_80801044
    if (ctx->r2 == 0) {
        // 0x80801034: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801044;
    }
    // 0x80801034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801038:
    // 0x80801038: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x8080103C: jal         0x80801058
    // 0x80801040: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801058_chminisubgame(rdram, ctx);
        goto after_13;
    // 0x80801040: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
L_80801044:
    // 0x80801044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801048:
    // 0x80801048: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080104C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801050: jr          $ra
    // 0x80801054: nop

    return;
    // 0x80801054: nop

;}
RECOMP_FUNC void func_80801928_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801928: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080192C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801930: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801938: jal         0x80100094
    // 0x8080193C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080193C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801940: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
    // 0x80801944: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801948: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x8080194C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80801950: jal         0x80106790
    // 0x80801954: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801954: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80801958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080195C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80801960: jal         0x80801258
    // 0x80801964: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80801258_chdodgemcontrol(rdram, ctx);
        goto after_2;
    // 0x80801964: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x80801968: jal         0x80801214
    // 0x8080196C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801214_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x8080196C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801970: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80801974: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80801978: or          $t7, $s0, $zero
    ctx->r15 = ctx->r16 | 0;
    // 0x8080197C: lhu         $t9, 0x6E($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X6E);
    // 0x80801980: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80801984: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x80801988: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x8080198C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80801990: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x80801994: sh          $t1, 0x6E($v1)
    MEM_H(0X6E, ctx->r3) = ctx->r9;
    // 0x80801998: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8080199C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808019A0: addu        $t5, $v0, $s0
    ctx->r13 = ADD32(ctx->r2, ctx->r16);
    // 0x808019A4: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x808019A8: sw          $zero, 0x10($t3)
    MEM_W(0X10, ctx->r11) = 0;
    // 0x808019AC: sb          $t4, 0x30($t5)
    MEM_B(0X30, ctx->r13) = ctx->r12;
    // 0x808019B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808019B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808019B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808019BC: jr          $ra
    // 0x808019C0: nop

    return;
    // 0x808019C0: nop

;}
RECOMP_FUNC void chcaveofhorrorsdoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(828, 0X1C0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(828, 0X1C0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(828, 0X1C0));
;}
RECOMP_FUNC void func_80802218_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802218: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080221C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802220: jal         0x80100094
    // 0x80802224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802228: jal         0x800D8FF8
    // 0x8080222C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080222C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802230: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80802234: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802238: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080223C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80802240: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80802244: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80802248: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8080224C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80802250: jal         0x800F15F8
    // 0x80802254: nop

    func_800F15F8(rdram, ctx);
        goto after_2;
    // 0x80802254: nop

    after_2:
    // 0x80802258: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080225C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80802260: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80802264: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80802268: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080226C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80802270: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x80802274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802278: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080227C: jr          $ra
    // 0x80802280: nop

    return;
    // 0x80802280: nop

;}
RECOMP_FUNC void _subaddietaxi_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4F8: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A4F8);
    return;
    // 0x8008A4FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800DC5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC5BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DC5C0: addiu       $v0, $v0, -0x36B8
    ctx->r2 = ADD32(ctx->r2, -0X36B8);
    // 0x800DC5C4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DC5C8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800DC5CC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800DC5D0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800DC5D4: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800DC5D8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800DC5DC: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x800DC5E0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DC5E4: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800DC5E8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800DC5EC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800DC5F0: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800DC5F4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800DC5F8: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800DC5FC: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DC600: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800DC604: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800DC608: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800DC60C: lwc1        $f10, 0x8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800DC610: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800DC614: jr          $ra
    // 0x800DC618: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x800DC618: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void bskazshock_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800044: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080004C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800050: jal         0x8008CABC
    // 0x80800054: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800054: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800058: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080005C: jal         0x800832E0
    // 0x80800060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800064: jal         0x8008AF24
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: jal         0x8008AED4
    // 0x80800074: addiu       $a1, $zero, 0x27C
    ctx->r5 = ADD32(0, 0X27C);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a1, $zero, 0x27C
    ctx->r5 = ADD32(0, 0X27C);
    after_3:
    // 0x80800078: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8080007C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800080: jal         0x8008B1C8
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x8008B1BC
    // 0x80800090: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80800090: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_5:
    // 0x80800094: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80800098: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: jal         0x8008B1D4
    // 0x808000A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x808000A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x8008B134
    // 0x808000B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x808000B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808000B4: jal         0x8008B064
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808000BC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x808000C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808000D0: jal         0x8009FFD8
    // 0x808000D4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x808000D4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x808000D8: jal         0x8009EF04
    // 0x808000DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_distance(rdram, ctx);
        goto after_10;
    // 0x808000DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x808000E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000E4: nop

    // 0x808000E8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808000EC: nop

    // 0x808000F0: bc1t        L_8080010C
    if (c1cs) {
        // 0x808000F4: nop
    
            goto L_8080010C;
    }
    // 0x808000F4: nop

    // 0x808000F8: jal         0x8009EEB8
    // 0x808000FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_11;
    // 0x808000FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80800100: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800104: jal         0x8009C914
    // 0x80800108: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_12;
    // 0x80800108: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
L_8080010C:
    // 0x8080010C: jal         0x8009C990
    // 0x80800110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_13;
    // 0x80800110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800114: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800118: jal         0x8009B9C0
    // 0x8080011C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_14;
    // 0x8080011C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800120: jal         0x800834B0
    // 0x80800124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x80800124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800128: jal         0x8009C990
    // 0x8080012C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_16;
    // 0x8080012C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800130: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800134: jal         0x8009BB00
    // 0x80800138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x8080013C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800140: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800144: jal         0x8009BA68
    // 0x80800148: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800148: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x8080014C: jal         0x800C2E04
    // 0x80800150: nop

    func_800C2E04(rdram, ctx);
        goto after_19;
    // 0x80800150: nop

    after_19:
    // 0x80800154: sb          $v0, 0x164($s1)
    MEM_B(0X164, ctx->r17) = ctx->r2;
    // 0x80800158: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8080015C: jal         0x800C3418
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C3418(rdram, ctx);
        goto after_20;
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80800164: jal         0x800C2E40
    // 0x80800168: lbu         $a0, 0x164($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X164);
    func_800C2E40(rdram, ctx);
        goto after_21;
    // 0x80800168: lbu         $a0, 0x164($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X164);
    after_21:
    // 0x8080016C: lbu         $a0, 0x164($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X164);
    // 0x80800170: jal         0x800C330C
    // 0x80800174: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_22;
    // 0x80800174: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_22:
    // 0x80800178: lbu         $a0, 0x164($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X164);
    // 0x8080017C: jal         0x800C301C
    // 0x80800180: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    func_800C301C(rdram, ctx);
        goto after_23;
    // 0x80800180: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    after_23:
    // 0x80800184: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80800188: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8080018C: lui         $a3, 0xBF99
    ctx->r7 = S32(0XBF99 << 16);
    // 0x80800190: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800194: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800198: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8080019C: jal         0x800C3730
    // 0x808001A0: lbu         $a0, 0x164($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X164);
    func_800C3730(rdram, ctx);
        goto after_24;
    // 0x808001A0: lbu         $a0, 0x164($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X164);
    after_24:
    // 0x808001A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808001A8: sw          $t7, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r15;
    // 0x808001AC: sw          $zero, 0x160($s1)
    MEM_W(0X160, ctx->r17) = 0;
    // 0x808001B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001B4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808001B8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808001BC: jr          $ra
    // 0x808001C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808001C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8000060C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000060C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000614: jal         0x800016DC
    // 0x80000618: nop

    func_800016DC(rdram, ctx);
        goto after_0;
    // 0x80000618: nop

    after_0:
    // 0x8000061C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000624: jr          $ra
    // 0x80000628: nop

    return;
    // 0x80000628: nop

;}
RECOMP_FUNC void _chanemone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F48: syscall     263
    recomp_syscall_handler(rdram, ctx, 0x80085F48);
    return;
    // 0x80085F4C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void vector_update_pointers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2FB0: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800B2FB4: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800B2FB8: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800B2FBC: addiu       $a2, $a0, 0x10
    ctx->r6 = ADD32(ctx->r4, 0X10);
    // 0x800B2FC0: subu        $v0, $t6, $v1
    ctx->r2 = SUB32(ctx->r14, ctx->r3);
    // 0x800B2FC4: subu        $a1, $t7, $v1
    ctx->r5 = SUB32(ctx->r15, ctx->r3);
    // 0x800B2FC8: addu        $t8, $a2, $v0
    ctx->r24 = ADD32(ctx->r6, ctx->r2);
    // 0x800B2FCC: addu        $t9, $a2, $a1
    ctx->r25 = ADD32(ctx->r6, ctx->r5);
    // 0x800B2FD0: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x800B2FD4: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800B2FD8: jr          $ra
    // 0x800B2FDC: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    return;
    // 0x800B2FDC: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_80801DE0_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801DE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801DEC: jal         0x80100094
    // 0x80801DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801DF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801DF8: lwc1        $f4, 0x264($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X264);
    // 0x80801DFC: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    // 0x80801E00: addiu       $a1, $v0, 0x254
    ctx->r5 = ADD32(ctx->r2, 0X254);
    // 0x80801E04: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801E08: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80801E0C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80801E10: jal         0x80108528
    // 0x80801E14: nop

    func_80108528(rdram, ctx);
        goto after_1;
    // 0x80801E14: nop

    after_1:
    // 0x80801E18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801E1C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80801E20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801E24: jal         0x800862D8
    // 0x80801E28: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80801E28: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80801E2C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E30: addiu       $a0, $zero, 0x36E
    ctx->r4 = ADD32(0, 0X36E);
    // 0x80801E34: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80801E38: lwc1        $f8, 0x264($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X264);
    // 0x80801E3C: addiu       $a1, $v0, 0x254
    ctx->r5 = ADD32(ctx->r2, 0X254);
    // 0x80801E40: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801E44: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801E48: jal         0x80108528
    // 0x80801E4C: nop

    func_80108528(rdram, ctx);
        goto after_3;
    // 0x80801E4C: nop

    after_3:
    // 0x80801E50: jal         0x800DA298
    // 0x80801E54: addiu       $a0, $zero, 0x6AC
    ctx->r4 = ADD32(0, 0X6AC);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80801E54: addiu       $a0, $zero, 0x6AC
    ctx->r4 = ADD32(0, 0X6AC);
    after_4:
    // 0x80801E58: bne         $v0, $zero, L_80801E80
    if (ctx->r2 != 0) {
        // 0x80801E5C: nop
    
            goto L_80801E80;
    }
    // 0x80801E5C: nop

    // 0x80801E60: jal         0x800DA544
    // 0x80801E64: addiu       $a0, $zero, 0x6AC
    ctx->r4 = ADD32(0, 0X6AC);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80801E64: addiu       $a0, $zero, 0x6AC
    ctx->r4 = ADD32(0, 0X6AC);
    after_5:
    // 0x80801E68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801E6C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80801E70: jal         0x80802A00
    // 0x80801E74: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_6;
    // 0x80801E74: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_6:
    // 0x80801E78: b           L_80801E94
    // 0x80801E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801E94;
    // 0x80801E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801E80:
    // 0x80801E80: jal         0x80802A9C
    // 0x80801E84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80802A9C_chinflatableboss(rdram, ctx);
        goto after_7;
    // 0x80801E84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80801E88: jal         0x80801EA0
    // 0x80801E8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80801EA0_chinflatableboss(rdram, ctx);
        goto after_8;
    // 0x80801E8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80801E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801E94:
    // 0x80801E94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801E98: jr          $ra
    // 0x80801E9C: nop

    return;
    // 0x80801E9C: nop

;}
RECOMP_FUNC void func_80101EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101EE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80101EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101EEC: jal         0x80104248
    // 0x80101EF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80101EF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80101EF4: beq         $v0, $zero, L_80101F14
    if (ctx->r2 == 0) {
        // 0x80101EF8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101F14;
    }
    // 0x80101EF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101EFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80101F00: jal         0x8008B10C
    // 0x80101F04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8008B10C(rdram, ctx);
        goto after_1;
    // 0x80101F04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80101F08: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80101F0C: jal         0x8008B2DC
    // 0x80101F10: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8008B2DC(rdram, ctx);
        goto after_2;
    // 0x80101F10: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
L_80101F14:
    // 0x80101F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101F18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80101F1C: jr          $ra
    // 0x80101F20: nop

    return;
    // 0x80101F20: nop

;}
RECOMP_FUNC void bskazmove_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003CC: jal         0x8009EF04
    // 0x808003D0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    bastick_distance(rdram, ctx);
        goto after_0;
    // 0x808003D0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808003D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808003D8: nop

    // 0x808003DC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808003E0: nop

    // 0x808003E4: bc1fl       L_80800404
    if (!c1cs) {
        // 0x808003E8: lui         $a1, 0x3EF0
        ctx->r5 = S32(0X3EF0 << 16);
            goto L_80800404;
    }
    goto skip_0;
    // 0x808003E8: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
    skip_0:
    // 0x808003EC: jal         0x8009C984
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003F8: jal         0x8009C914
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_2;
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800400: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
L_80800404:
    // 0x80800404: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: jal         0x800A2CE8
    // 0x80800410: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_3;
    // 0x80800410: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80800414: lui         $a1, 0x3F78
    ctx->r5 = S32(0X3F78 << 16);
    // 0x80800418: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: jal         0x800A2CE8
    // 0x80800424: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_4;
    // 0x80800424: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x80800428: jal         0x808000A0
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bskazmove_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800430: jal         0x8009EF10
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_6;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800438: beq         $v0, $zero, L_80800450
    if (ctx->r2 == 0) {
        // 0x8080043C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800450;
    }
    // 0x8080043C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800440: beq         $v0, $at, L_8080046C
    if (ctx->r2 == ctx->r1) {
        // 0x80800444: addiu       $t7, $zero, 0xC7
        ctx->r15 = ADD32(0, 0XC7);
            goto L_8080046C;
    }
    // 0x80800444: addiu       $t7, $zero, 0xC7
    ctx->r15 = ADD32(0, 0XC7);
    // 0x80800448: b           L_80800470
    // 0x8080044C: nop

        goto L_80800470;
    // 0x8080044C: nop

L_80800450:
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: jal         0x8009BCD4
    // 0x80800458: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_7;
    // 0x80800458: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_7:
    // 0x8080045C: beq         $v0, $zero, L_80800470
    if (ctx->r2 == 0) {
        // 0x80800460: addiu       $t6, $zero, 0xBB
        ctx->r14 = ADD32(0, 0XBB);
            goto L_80800470;
    }
    // 0x80800460: addiu       $t6, $zero, 0xBB
    ctx->r14 = ADD32(0, 0XBB);
    // 0x80800464: b           L_80800470
    // 0x80800468: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_80800470;
    // 0x80800468: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8080046C:
    // 0x8080046C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800470:
    // 0x80800470: jal         0x8008E39C
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E39C(rdram, ctx);
        goto after_8;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800478: beq         $v0, $zero, L_80800484
    if (ctx->r2 == 0) {
        // 0x8080047C: addiu       $t8, $zero, 0xC7
        ctx->r24 = ADD32(0, 0XC7);
            goto L_80800484;
    }
    // 0x8080047C: addiu       $t8, $zero, 0xC7
    ctx->r24 = ADD32(0, 0XC7);
    // 0x80800480: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800484:
    // 0x80800484: jal         0x8008DD04
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_9;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080048C: beq         $v0, $zero, L_8080049C
    if (ctx->r2 == 0) {
        // 0x80800490: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080049C;
    }
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800494: addiu       $t9, $zero, 0xDF
    ctx->r25 = ADD32(0, 0XDF);
    // 0x80800498: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_8080049C:
    // 0x8080049C: jal         0x800919F4
    // 0x808004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_10;
    // 0x808004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808004A4: beq         $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x808004A8: nop
    
            goto L_808004C0;
    }
    // 0x808004A8: nop

    // 0x808004AC: jal         0x8008E39C
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E39C(rdram, ctx);
        goto after_11;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808004B4: bne         $v0, $zero, L_808004C0
    if (ctx->r2 != 0) {
        // 0x808004B8: addiu       $t0, $zero, 0xDD
        ctx->r8 = ADD32(0, 0XDD);
            goto L_808004C0;
    }
    // 0x808004B8: addiu       $t0, $zero, 0xDD
    ctx->r8 = ADD32(0, 0XDD);
    // 0x808004BC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_808004C0:
    // 0x808004C0: jal         0x8008E39C
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E39C(rdram, ctx);
        goto after_12;
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808004C8: beq         $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x808004CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E0;
    }
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: jal         0x8080025C
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080025C_bskazmove(rdram, ctx);
        goto after_13;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808004D8: b           L_808004F0
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808004F0;
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004E0:
    // 0x808004E0: jal         0x808001C4
    // 0x808004E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808001C4_bskazmove(rdram, ctx);
        goto after_14;
    // 0x808004E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x808004E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004F0:
    // 0x808004F0: jal         0x80091A58
    // 0x808004F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_15;
    // 0x808004F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_15:
    // 0x808004F8: beq         $v0, $zero, L_8080054C
    if (ctx->r2 == 0) {
        // 0x808004FC: nop
    
            goto L_8080054C;
    }
    // 0x808004FC: nop

    // 0x80800500: jal         0x800832F0
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800508: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080050C: jal         0x8009BB00
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800514: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800518: nop

    // 0x8080051C: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800520: nop

    // 0x80800524: bc1f        L_8080054C
    if (!c1cs) {
        // 0x80800528: nop
    
            goto L_8080054C;
    }
    // 0x80800528: nop

    // 0x8080052C: jal         0x8008D790
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D790(rdram, ctx);
        goto after_18;
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800534: beq         $v0, $zero, L_8080054C
    if (ctx->r2 == 0) {
        // 0x80800538: nop
    
            goto L_8080054C;
    }
    // 0x80800538: nop

    // 0x8080053C: jal         0x80084978
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_12(rdram, ctx);
        goto after_19;
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800544: b           L_80800598
    // 0x80800548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800598;
    // 0x80800548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080054C:
    // 0x8080054C: jal         0x8008DF18
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_20;
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800554: beq         $v0, $zero, L_80800568
    if (ctx->r2 == 0) {
        // 0x80800558: nop
    
            goto L_80800568;
    }
    // 0x80800558: nop

    // 0x8080055C: jal         0x800848B0
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_21;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800564: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800568:
    // 0x80800568: jal         0x8008E35C
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_22;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800570: beq         $v0, $zero, L_80800580
    if (ctx->r2 == 0) {
        // 0x80800574: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800580;
    }
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: addiu       $t1, $zero, 0x15D
    ctx->r9 = ADD32(0, 0X15D);
    // 0x8080057C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80800580:
    // 0x80800580: jal         0x800A02DC
    // 0x80800584: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800A02DC(rdram, ctx);
        goto after_23;
    // 0x80800584: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_23:
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080058C: jal         0x8009E5C8
    // 0x80800590: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_24;
    // 0x80800590: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_24:
    // 0x80800594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800598:
    // 0x80800598: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080059C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005A0: jr          $ra
    // 0x808005A4: nop

    return;
    // 0x808005A4: nop

;}
RECOMP_FUNC void glhittableDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B4: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x808003B8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x808003BC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x808003C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808003C4: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2742, 0X530) << 16);
    // 0x808003C8: addiu       $t9, $t9, 0x530
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2742, 0X530));
    // 0x808003CC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808003D0: andi        $t0, $a0, 0xFFFF
    ctx->r8 = ctx->r4 & 0XFFFF;
    // 0x808003D4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x808003D8: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x808003DC: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x808003E0: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x808003E4: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x808003E8: sll         $t4, $t3, 27
    ctx->r12 = S32(ctx->r11 << 27);
    // 0x808003EC: sll         $t7, $t6, 27
    ctx->r15 = S32(ctx->r14 << 27);
    // 0x808003F0: srl         $t8, $t7, 29
    ctx->r24 = S32(U32(ctx->r15) >> 29);
    // 0x808003F4: srl         $t5, $t4, 29
    ctx->r13 = S32(U32(ctx->r12) >> 29);
    // 0x808003F8: jr          $ra
    // 0x808003FC: or          $v0, $t5, $t8
    ctx->r2 = ctx->r13 | ctx->r24;
    return;
    // 0x808003FC: or          $v0, $t5, $t8
    ctx->r2 = ctx->r13 | ctx->r24;
;}
RECOMP_FUNC void func_808009D0_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808009D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808009DC: jal         0x8009C128
    // 0x808009E0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808009E0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808009E4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808009E8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808009EC: lw          $a1, 0x188($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X188);
    // 0x808009F0: jal         0x800EF04C
    // 0x808009F4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x808009F4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_1:
    // 0x808009F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009FC: jal         0x800A34AC
    // 0x80800A00: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800A34AC(rdram, ctx);
        goto after_2;
    // 0x80800A00: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80800A04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A08: addiu       $a1, $zero, 0x40D
    ctx->r5 = ADD32(0, 0X40D);
    // 0x80800A0C: jal         0x8009DF58
    // 0x80800A10: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DF58(rdram, ctx);
        goto after_3;
    // 0x80800A10: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x80800A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A1C: jr          $ra
    // 0x80800A20: nop

    return;
    // 0x80800A20: nop

;}
RECOMP_FUNC void func_80800664_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080066C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0X10C4) << 16);
    // 0x80800670: lui         $a3, 0x3F05
    ctx->r7 = S32(0X3F05 << 16);
    // 0x80800674: ori         $a3, $a3, 0x1EB8
    ctx->r7 = ctx->r7 | 0X1EB8;
    // 0x80800678: addiu       $a2, $a2, 0x10C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0X10C4));
    // 0x8080067C: jal         0x80089D20
    // 0x80800680: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800680: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080068C: jr          $ra
    // 0x80800690: nop

    return;
    // 0x80800690: nop

;}
