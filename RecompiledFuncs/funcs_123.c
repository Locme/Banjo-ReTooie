#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80101BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101BA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80101BAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80101BB0: jal         0x800DF744
    // 0x80101BB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80101BB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80101BB8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80101BBC: jal         0x800DF744
    // 0x80101BC0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80101BC0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80101BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101BC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101BCC: jr          $ra
    // 0x80101BD0: nop

    return;
    // 0x80101BD0: nop

    // 0x80101BD4: nop

    // 0x80101BD8: nop

    // 0x80101BDC: nop

;}
RECOMP_FUNC void func_800BF3E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF3E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BF3E8: addiu       $v1, $v1, -0x7A50
    ctx->r3 = ADD32(ctx->r3, -0X7A50);
    // 0x800BF3EC: lhu         $v0, 0x5A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X5A);
    // 0x800BF3F0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800BF3F4: bnel        $t6, $zero, L_800BF410
    if (ctx->r14 != 0) {
        // 0x800BF3F8: lhu         $v0, 0x5C($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X5C);
            goto L_800BF410;
    }
    goto skip_0;
    // 0x800BF3F8: lhu         $v0, 0x5C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X5C);
    skip_0:
    // 0x800BF3FC: lbu         $v0, 0x77($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X77);
    // 0x800BF400: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800BF404: beq         $t7, $zero, L_800BF418
    if (ctx->r15 == 0) {
        // 0x800BF408: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800BF418;
    }
    // 0x800BF408: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800BF40C: lhu         $v0, 0x5C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X5C);
L_800BF410:
    // 0x800BF410: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800BF414: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800BF418:
    // 0x800BF418: jr          $ra
    // 0x800BF41C: nop

    return;
    // 0x800BF41C: nop

;}
RECOMP_FUNC void func_8080039C_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080039C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003A8: jal         0x8009E710
    // 0x808003AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_0;
    // 0x808003AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808003B8: jal         0x8009CA70
    // 0x808003BC: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x808003BC: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    after_1:
    // 0x808003C0: bnel        $v0, $zero, L_80800470
    if (ctx->r2 != 0) {
        // 0x808003C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800470;
    }
    goto skip_0;
    // 0x808003C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808003C8: jal         0x80084BF0
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808003D0: jal         0x80084570
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babee_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003D8: lui         $a1, 0x45BB
    ctx->r5 = S32(0X45BB << 16);
    // 0x808003DC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x808003E0: lui         $a3, 0x463B
    ctx->r7 = S32(0X463B << 16);
    // 0x808003E4: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x808003E8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808003EC: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808003F0: jal         0x80084578
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babee_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x80093360
    // 0x80800400: lui         $a1, 0x4282
    ctx->r5 = S32(0X4282 << 16);
    func_80093360(rdram, ctx);
        goto after_5;
    // 0x80800400: lui         $a1, 0x4282
    ctx->r5 = S32(0X4282 << 16);
    after_5:
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800408: jal         0x8009C908
    // 0x8080040C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_6;
    // 0x8080040C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800418: jal         0x8009C554
    // 0x8080041C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_7;
    // 0x8080041C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_7:
    // 0x80800420: jal         0x80084C68
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_20(rdram, ctx);
        goto after_8;
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: jal         0x8009BCB4
    // 0x80800430: lui         $a1, 0xC396
    ctx->r5 = S32(0XC396 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_9;
    // 0x80800430: lui         $a1, 0xC396
    ctx->r5 = S32(0XC396 << 16);
    after_9:
    // 0x80800434: lui         $a1, 0xC2C7
    ctx->r5 = S32(0XC2C7 << 16);
    // 0x80800438: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080043C: jal         0x8009BCC4
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_10;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800444: jal         0x800845A0
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baboost_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: jal         0x800845A8
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baboost_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800458: jal         0x800847A0
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babuzz_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800464: jal         0x80084D08
    // 0x80800468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_18(rdram, ctx);
        goto after_14;
    // 0x80800468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8080046C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800470:
    // 0x80800470: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800478: jr          $ra
    // 0x8080047C: nop

    return;
    // 0x8080047C: nop

;}
RECOMP_FUNC void func_800B956C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B956C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800B9570: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B9574: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800B9578: addiu       $s1, $s1, 0x7128
    ctx->r17 = ADD32(ctx->r17, 0X7128);
    // 0x800B957C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800B9580: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B9584: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800B9588: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800B958C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B9590: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B9594: beq         $t6, $zero, L_800B9780
    if (ctx->r14 == 0) {
        // 0x800B9598: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800B9780;
    }
    // 0x800B9598: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B959C: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800B95A0: beql        $t7, $zero, L_800B9784
    if (ctx->r15 == 0) {
        // 0x800B95A4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800B9784;
    }
    goto skip_0;
    // 0x800B95A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800B95A8: jal         0x800A7180
    // 0x800B95AC: nop

    func_800A7180(rdram, ctx);
        goto after_0;
    // 0x800B95AC: nop

    after_0:
    // 0x800B95B0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800B95B4: jal         0x800D674C
    // 0x800B95B8: addiu       $a0, $zero, 0x9F4
    ctx->r4 = ADD32(0, 0X9F4);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x800B95B8: addiu       $a0, $zero, 0x9F4
    ctx->r4 = ADD32(0, 0X9F4);
    after_1:
    // 0x800B95BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B95C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B95C4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800B95C8: addiu       $a1, $a1, 0x7154
    ctx->r5 = ADD32(ctx->r5, 0X7154);
    // 0x800B95CC: jal         0x800E39A8
    // 0x800B95D0: addiu       $a0, $a0, 0x7148
    ctx->r4 = ADD32(ctx->r4, 0X7148);
    func_800E39A8(rdram, ctx);
        goto after_2;
    // 0x800B95D0: addiu       $a0, $a0, 0x7148
    ctx->r4 = ADD32(ctx->r4, 0X7148);
    after_2:
    // 0x800B95D4: lw          $t8, 0xC($s4)
    ctx->r24 = MEM_W(ctx->r20, 0XC);
    // 0x800B95D8: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x800B95DC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800B95E0: sw          $t0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->r8;
    // 0x800B95E4: lw          $t1, 0x10($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X10);
    // 0x800B95E8: addu        $s0, $s4, $t1
    ctx->r16 = ADD32(ctx->r20, ctx->r9);
    // 0x800B95EC: jal         0x800B2354
    // 0x800B95F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2354(rdram, ctx);
        goto after_3;
    // 0x800B95F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800B95F4: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x800B95F8: lw          $s2, 0x0($s5)
    ctx->r18 = MEM_W(ctx->r21, 0X0);
    // 0x800B95FC: lui         $t2, 0xDB06
    ctx->r10 = S32(0XDB06 << 16);
    // 0x800B9600: ori         $t2, $t2, 0x4
    ctx->r10 = ctx->r10 | 0X4;
    // 0x800B9604: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x800B9608: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x800B960C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x800B9610: jal         0x8002E330
    // 0x800B9614: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800B9614: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    after_4:
    // 0x800B9618: lui         $t3, 0xDB06
    ctx->r11 = S32(0XDB06 << 16);
    // 0x800B961C: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x800B9620: ori         $t3, $t3, 0x8
    ctx->r11 = ctx->r11 | 0X8;
    // 0x800B9624: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800B9628: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800B962C: lh          $t4, 0x8($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X8);
    // 0x800B9630: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800B9634: addu        $a0, $s4, $t4
    ctx->r4 = ADD32(ctx->r20, ctx->r12);
    // 0x800B9638: jal         0x8002E330
    // 0x800B963C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x800B963C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_5:
    // 0x800B9640: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800B9644: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800B9648: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800B964C: lui         $t5, 0xD9FF
    ctx->r13 = S32(0XD9FF << 16);
    // 0x800B9650: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x800B9654: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B9658: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800B965C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800B9660: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800B9664: lui         $t8, 0x12
    ctx->r24 = S32(0X12 << 16);
    // 0x800B9668: addiu       $t8, $t8, -0x5970
    ctx->r24 = ADD32(ctx->r24, -0X5970);
    // 0x800B966C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800B9670: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800B9674: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x800B9678: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800B967C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800B9680: ori         $t9, $t9, 0xC
    ctx->r25 = ctx->r25 | 0XC;
    // 0x800B9684: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800B9688: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800B968C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B9690: addiu       $a0, $a0, -0x5950
    ctx->r4 = ADD32(ctx->r4, -0X5950);
    // 0x800B9694: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B9698: jal         0x8002E330
    // 0x800B969C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x800B969C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    after_6:
    // 0x800B96A0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800B96A4: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
    // 0x800B96A8: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x800B96AC: sw          $s2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r18;
    // 0x800B96B0: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x800B96B4: lw          $t0, 0x4($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X4);
    // 0x800B96B8: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800B96BC: multu       $t3, $s3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B96C0: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x800B96C4: sw          $t1, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->r9;
    // 0x800B96C8: lw          $s0, 0x1C($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X1C);
    // 0x800B96CC: addiu       $s4, $zero, 0x18
    ctx->r20 = ADD32(0, 0X18);
    // 0x800B96D0: addiu       $s2, $s5, 0x4
    ctx->r18 = ADD32(ctx->r21, 0X4);
    // 0x800B96D4: mflo        $t4
    ctx->r12 = lo;
    // 0x800B96D8: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x800B96DC: sltu        $at, $s0, $t5
    ctx->r1 = ctx->r16 < ctx->r13 ? 1 : 0;
    // 0x800B96E0: beq         $at, $zero, L_800B9780
    if (ctx->r1 == 0) {
        // 0x800B96E4: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800B9780;
    }
    // 0x800B96E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B96E8:
    // 0x800B96E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800B96EC: jal         0x800B97A4
    // 0x800B96F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800B97A4(rdram, ctx);
        goto after_7;
    // 0x800B96F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800B96F4: bnel        $v0, $zero, L_800B975C
    if (ctx->r2 != 0) {
        // 0x800B96F8: lw          $t1, 0x4($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X4);
            goto L_800B975C;
    }
    goto skip_1;
    // 0x800B96F8: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    skip_1:
    // 0x800B96FC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800B9700: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800B9704: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800B9708: nop

    // 0x800B970C: bc1fl       L_800B975C
    if (!c1cs) {
        // 0x800B9710: lw          $t1, 0x4($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X4);
            goto L_800B975C;
    }
    goto skip_2;
    // 0x800B9710: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    skip_2:
    // 0x800B9714: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800B9718: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x800B971C: subu        $t8, $s0, $t7
    ctx->r24 = SUB32(ctx->r16, ctx->r15);
    // 0x800B9720: div         $zero, $t8, $s4
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r20)));
    // 0x800B9724: mflo        $a0
    ctx->r4 = lo;
    // 0x800B9728: bne         $s4, $zero, L_800B9734
    if (ctx->r20 != 0) {
        // 0x800B972C: nop
    
            goto L_800B9734;
    }
    // 0x800B972C: nop

    // 0x800B9730: break       7
    do_break(2148243248);
L_800B9734:
    // 0x800B9734: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9738: bne         $s4, $at, L_800B974C
    if (ctx->r20 != ctx->r1) {
        // 0x800B973C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B974C;
    }
    // 0x800B973C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B9740: bne         $t8, $at, L_800B974C
    if (ctx->r24 != ctx->r1) {
        // 0x800B9744: nop
    
            goto L_800B974C;
    }
    // 0x800B9744: nop

    // 0x800B9748: break       6
    do_break(2148243272);
L_800B974C:
    // 0x800B974C: jal         0x800B9108
    // 0x800B9750: nop

    func_800B9108(rdram, ctx);
        goto after_8;
    // 0x800B9750: nop

    after_8:
    // 0x800B9754: addiu       $s0, $s0, -0x18
    ctx->r16 = ADD32(ctx->r16, -0X18);
    // 0x800B9758: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
L_800B975C:
    // 0x800B975C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800B9760: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800B9764: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9768: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x800B976C: mflo        $t2
    ctx->r10 = lo;
    // 0x800B9770: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800B9774: sltu        $at, $s0, $t3
    ctx->r1 = ctx->r16 < ctx->r11 ? 1 : 0;
    // 0x800B9778: bnel        $at, $zero, L_800B96E8
    if (ctx->r1 != 0) {
        // 0x800B977C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800B96E8;
    }
    goto skip_3;
    // 0x800B977C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_3:
L_800B9780:
    // 0x800B9780: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B9784:
    // 0x800B9784: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B9788: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B978C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9790: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B9794: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800B9798: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800B979C: jr          $ra
    // 0x800B97A0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800B97A0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80801244_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801244: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801248: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080124C: jal         0x808009B0
    // 0x80801250: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_808009B0_bssub(rdram, ctx);
        goto after_0;
    // 0x80801250: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801254: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80801258: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080125C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801260: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801264: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801268: addiu       $a1, $zero, 0x130
    ctx->r5 = ADD32(0, 0X130);
    // 0x8080126C: jal         0x80085150
    // 0x80801270: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _baspin_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801270: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80801274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801278: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080127C: jr          $ra
    // 0x80801280: nop

    return;
    // 0x80801280: nop

;}
RECOMP_FUNC void _chalienkids_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086580: syscall     337
    recomp_syscall_handler(rdram, ctx, 0x80086580);
    return;
    // 0x80086584: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800BE09C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE09C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800BE0A0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800BE0A4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800BE0A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE0AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE0B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BE0B4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BE0B8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800BE0BC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800BE0C0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800BE0C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800BE0C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800BE0CC: addiu       $v0, $v0, -0x7BF0
    ctx->r2 = ADD32(ctx->r2, -0X7BF0);
    // 0x800BE0D0: lwc1        $f2, -0x7BB0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7BB0);
    // 0x800BE0D4: addiu       $a0, $a0, -0x7BE4
    ctx->r4 = ADD32(ctx->r4, -0X7BE4);
    // 0x800BE0D8: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x800BE0DC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_800BE0E0:
    // 0x800BE0E0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800BE0E4: bltzl       $v1, L_800BE108
    if (SIGNED(ctx->r3) < 0) {
        // 0x800BE0E8: mtc1        $v1, $f8
        ctx->f8.u32l = ctx->r3;
            goto L_800BE108;
    }
    goto skip_0;
    // 0x800BE0E8: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    skip_0:
    // 0x800BE0EC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800BE0F0: nop

    // 0x800BE0F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE0F8: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BE0FC: b           L_800BE11C
    // 0x800BE100: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
        goto L_800BE11C;
    // 0x800BE100: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800BE104: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
L_800BE108:
    // 0x800BE108: nop

    // 0x800BE10C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE110: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800BE114: nop

    // 0x800BE118: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
L_800BE11C:
    // 0x800BE11C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BE120: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800BE124: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800BE128: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800BE12C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800BE130: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BE134: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800BE138: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BE13C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800BE140: bne         $at, $zero, L_800BE0E0
    if (ctx->r1 != 0) {
        // 0x800BE144: sw          $t8, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = ctx->r24;
            goto L_800BE0E0;
    }
    // 0x800BE144: sw          $t8, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r24;
    // 0x800BE148: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800BE14C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BE150: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800BE154: blez        $t9, L_800BE284
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BE158: addiu       $s2, $s2, -0x7BF0
        ctx->r18 = ADD32(ctx->r18, -0X7BF0);
            goto L_800BE284;
    }
    // 0x800BE158: addiu       $s2, $s2, -0x7BF0
    ctx->r18 = ADD32(ctx->r18, -0X7BF0);
    // 0x800BE15C: lw          $t0, 0x28($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X28);
    // 0x800BE160: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800BE164: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800BE168: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800BE16C: beql        $at, $zero, L_800BE288
    if (ctx->r1 == 0) {
        // 0x800BE170: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800BE288;
    }
    goto skip_1;
    // 0x800BE170: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_1:
    // 0x800BE174: blezl       $t2, L_800BE288
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800BE178: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800BE288;
    }
    goto skip_2;
    // 0x800BE178: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_2:
    // 0x800BE17C: lw          $t3, 0x2C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X2C);
    // 0x800BE180: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800BE184: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800BE188: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800BE18C: beql        $at, $zero, L_800BE288
    if (ctx->r1 == 0) {
        // 0x800BE190: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800BE288;
    }
    goto skip_3;
    // 0x800BE190: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_3:
    // 0x800BE194: blezl       $a0, L_800BE288
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BE198: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800BE288;
    }
    goto skip_4;
    // 0x800BE198: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_4:
    // 0x800BE19C: lw          $t5, 0x30($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X30);
    // 0x800BE1A0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800BE1A4: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BE1A8: beql        $at, $zero, L_800BE288
    if (ctx->r1 == 0) {
        // 0x800BE1AC: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800BE288;
    }
    goto skip_5;
    // 0x800BE1AC: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_5:
    // 0x800BE1B0: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x800BE1B4: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800BE1B8: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x800BE1BC: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE1C0: addiu       $t1, $t2, -0x1
    ctx->r9 = ADD32(ctx->r10, -0X1);
    // 0x800BE1C4: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800BE1C8: mflo        $t8
    ctx->r24 = lo;
    // 0x800BE1CC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800BE1D0: nop

    // 0x800BE1D4: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE1D8: mflo        $t3
    ctx->r11 = lo;
    // 0x800BE1DC: addu        $s5, $t0, $t3
    ctx->r21 = ADD32(ctx->r8, ctx->r11);
    // 0x800BE1E0: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800BE1E4: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
L_800BE1E8:
    // 0x800BE1E8: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_800BE1EC:
    // 0x800BE1EC: slti        $at, $zero, 0x3
    ctx->r1 = SIGNED(0) < 0X3 ? 1 : 0;
    // 0x800BE1F0: beq         $at, $zero, L_800BE240
    if (ctx->r1 == 0) {
        // 0x800BE1F4: sw          $zero, 0x54($sp)
        MEM_W(0X54, ctx->r29) = 0;
            goto L_800BE240;
    }
    // 0x800BE1F4: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_800BE1F8:
    // 0x800BE1F8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800BE1FC: sll         $s0, $s1, 3
    ctx->r16 = S32(ctx->r17 << 3);
    // 0x800BE200: jal         0x800E9DCC
    // 0x800BE204: addu        $a0, $s0, $t4
    ctx->r4 = ADD32(ctx->r16, ctx->r12);
    func_800E9DCC(rdram, ctx);
        goto after_0;
    // 0x800BE204: addu        $a0, $s0, $t4
    ctx->r4 = ADD32(ctx->r16, ctx->r12);
    after_0:
    // 0x800BE208: beq         $v0, $zero, L_800BE224
    if (ctx->r2 == 0) {
        // 0x800BE20C: sll         $t7, $s3, 2
        ctx->r15 = S32(ctx->r19 << 2);
            goto L_800BE224;
    }
    // 0x800BE20C: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x800BE210: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800BE214: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x800BE218: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800BE21C: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800BE220: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_800BE224:
    // 0x800BE224: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x800BE228: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800BE22C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BE230: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800BE234: bne         $at, $zero, L_800BE1F8
    if (ctx->r1 != 0) {
        // 0x800BE238: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_800BE1F8;
    }
    // 0x800BE238: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800BE23C: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
L_800BE240:
    // 0x800BE240: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800BE244: addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
    // 0x800BE248: addiu       $s1, $s1, -0x3
    ctx->r17 = ADD32(ctx->r17, -0X3);
    // 0x800BE24C: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800BE250: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800BE254: bne         $at, $zero, L_800BE1EC
    if (ctx->r1 != 0) {
        // 0x800BE258: sw          $t2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r10;
            goto L_800BE1EC;
    }
    // 0x800BE258: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x800BE25C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800BE260: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x800BE264: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x800BE268: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x800BE26C: addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // 0x800BE270: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x800BE274: bne         $at, $zero, L_800BE1E8
    if (ctx->r1 != 0) {
        // 0x800BE278: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_800BE1E8;
    }
    // 0x800BE278: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800BE27C: b           L_800BE3D4
    // 0x800BE280: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800BE3D4;
    // 0x800BE280: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800BE284:
    // 0x800BE284: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
L_800BE288:
    // 0x800BE288: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BE28C: addiu       $s2, $s2, -0x7BF0
    ctx->r18 = ADD32(ctx->r18, -0X7BF0);
    // 0x800BE290: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800BE294: addiu       $v0, $t3, 0x2
    ctx->r2 = ADD32(ctx->r11, 0X2);
    // 0x800BE298: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BE29C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800BE2A0: beq         $at, $zero, L_800BE3D0
    if (ctx->r1 == 0) {
        // 0x800BE2A4: sw          $t4, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r12;
            goto L_800BE3D0;
    }
    // 0x800BE2A4: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
L_800BE2A8:
    // 0x800BE2A8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800BE2AC: bltzl       $t5, L_800BE3C0
    if (SIGNED(ctx->r13) < 0) {
        // 0x800BE2B0: lw          $t7, 0x4C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X4C);
            goto L_800BE3C0;
    }
    goto skip_6;
    // 0x800BE2B0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    skip_6:
    // 0x800BE2B4: lw          $t7, 0x28($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X28);
    // 0x800BE2B8: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800BE2BC: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BE2C0: beq         $at, $zero, L_800BE3BC
    if (ctx->r1 == 0) {
        // 0x800BE2C4: addiu       $t8, $t6, -0x1
        ctx->r24 = ADD32(ctx->r14, -0X1);
            goto L_800BE3BC;
    }
    // 0x800BE2C4: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x800BE2C8: addiu       $v1, $t6, 0x2
    ctx->r3 = ADD32(ctx->r14, 0X2);
    // 0x800BE2CC: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BE2D0: beq         $at, $zero, L_800BE3BC
    if (ctx->r1 == 0) {
        // 0x800BE2D4: sw          $t8, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r24;
            goto L_800BE3BC;
    }
    // 0x800BE2D4: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
L_800BE2D8:
    // 0x800BE2D8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800BE2DC: bltzl       $t9, L_800BE3A4
    if (SIGNED(ctx->r25) < 0) {
        // 0x800BE2E0: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_800BE3A4;
    }
    goto skip_7;
    // 0x800BE2E0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    skip_7:
    // 0x800BE2E4: lw          $t2, 0x2C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X2C);
    // 0x800BE2E8: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x800BE2EC: addiu       $t1, $a0, 0x2
    ctx->r9 = ADD32(ctx->r4, 0X2);
    // 0x800BE2F0: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BE2F4: beq         $at, $zero, L_800BE3A0
    if (ctx->r1 == 0) {
        // 0x800BE2F8: slt         $at, $v0, $t1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_800BE3A0;
    }
    // 0x800BE2F8: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800BE2FC: beql        $at, $zero, L_800BE3A4
    if (ctx->r1 == 0) {
        // 0x800BE300: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_800BE3A4;
    }
    goto skip_8;
    // 0x800BE300: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    skip_8:
L_800BE304:
    // 0x800BE304: bltz        $v0, L_800BE37C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800BE308: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_800BE37C;
    }
    // 0x800BE308: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800BE30C: lw          $t0, 0x30($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X30);
    // 0x800BE310: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800BE314: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BE318: beql        $at, $zero, L_800BE380
    if (ctx->r1 == 0) {
        // 0x800BE31C: lw          $v0, 0x54($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X54);
            goto L_800BE380;
    }
    goto skip_9;
    // 0x800BE31C: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    skip_9:
    // 0x800BE320: lw          $t3, 0x20($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X20);
    // 0x800BE324: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800BE328: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x800BE32C: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE330: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800BE334: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800BE338: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800BE33C: mflo        $t4
    ctx->r12 = lo;
    // 0x800BE340: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800BE344: nop

    // 0x800BE348: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE34C: mflo        $t9
    ctx->r25 = lo;
    // 0x800BE350: addu        $s1, $t7, $t9
    ctx->r17 = ADD32(ctx->r15, ctx->r25);
    // 0x800BE354: sll         $s0, $s1, 3
    ctx->r16 = S32(ctx->r17 << 3);
    // 0x800BE358: jal         0x800E9DCC
    // 0x800BE35C: addu        $a0, $s0, $t2
    ctx->r4 = ADD32(ctx->r16, ctx->r10);
    func_800E9DCC(rdram, ctx);
        goto after_1;
    // 0x800BE35C: addu        $a0, $s0, $t2
    ctx->r4 = ADD32(ctx->r16, ctx->r10);
    after_1:
    // 0x800BE360: beq         $v0, $zero, L_800BE37C
    if (ctx->r2 == 0) {
        // 0x800BE364: sll         $t3, $s3, 2
        ctx->r11 = S32(ctx->r19 << 2);
            goto L_800BE37C;
    }
    // 0x800BE364: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x800BE368: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800BE36C: addu        $t4, $s4, $t3
    ctx->r12 = ADD32(ctx->r20, ctx->r11);
    // 0x800BE370: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800BE374: addu        $t0, $s0, $t1
    ctx->r8 = ADD32(ctx->r16, ctx->r9);
    // 0x800BE378: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
L_800BE37C:
    // 0x800BE37C: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
L_800BE380:
    // 0x800BE380: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800BE384: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BE388: addiu       $t5, $a0, 0x2
    ctx->r13 = ADD32(ctx->r4, 0X2);
    // 0x800BE38C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800BE390: bne         $at, $zero, L_800BE304
    if (ctx->r1 != 0) {
        // 0x800BE394: nop
    
            goto L_800BE304;
    }
    // 0x800BE394: nop

    // 0x800BE398: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800BE39C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_800BE3A0:
    // 0x800BE3A0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_800BE3A4:
    // 0x800BE3A4: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800BE3A8: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BE3AC: bne         $at, $zero, L_800BE2D8
    if (ctx->r1 != 0) {
        // 0x800BE3B0: sw          $t8, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r24;
            goto L_800BE2D8;
    }
    // 0x800BE3B0: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800BE3B4: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x800BE3B8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_800BE3BC:
    // 0x800BE3BC: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
L_800BE3C0:
    // 0x800BE3C0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800BE3C4: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BE3C8: bne         $at, $zero, L_800BE2A8
    if (ctx->r1 != 0) {
        // 0x800BE3CC: sw          $t9, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r25;
            goto L_800BE2A8;
    }
    // 0x800BE3CC: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_800BE3D0:
    // 0x800BE3D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800BE3D4:
    // 0x800BE3D4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800BE3D8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800BE3DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800BE3E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800BE3E4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE3E8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800BE3EC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800BE3F0: jr          $ra
    // 0x800BE3F4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800BE3F4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8080063C_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080063C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800640: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800644: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800648: jal         0x80100094
    // 0x8080064C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080064C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800650: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800654: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800658: lwc1        $f14, 0x18($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X18);
    // 0x8080065C: jal         0x800F1DCC
    // 0x80800660: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80800660: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80800664: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800668: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080066C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800670: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800674: jal         0x8008FFBC
    // 0x80800678: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    func_8008FFBC(rdram, ctx);
        goto after_2;
    // 0x80800678: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8080067C: jal         0x800EF030
    // 0x80800680: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EF030(rdram, ctx);
        goto after_3;
    // 0x80800680: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80800684: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800688: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080068C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800690: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800694: lui         $a2, 0x459C
    ctx->r6 = S32(0X459C << 16);
    // 0x80800698: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8080069C: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x808006A0: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x808006A4: jal         0x800F10B4
    // 0x808006A8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808006A8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x808006AC: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808006B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006B4: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808006B8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808006BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808006C0: jr          $ra
    // 0x808006C4: add.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f2.fl;
    return;
    // 0x808006C4: add.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f2.fl;
;}
RECOMP_FUNC void func_800CBBE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBBE0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CBBE4: lw          $t7, -0x516C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X516C);
    // 0x800CBBE8: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800CBBEC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CBBF0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CBBF4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800CBBF8: jr          $ra
    // 0x800CBBFC: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    return;
    // 0x800CBBFC: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
;}
RECOMP_FUNC void func_8080036C_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080036C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800374: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2168, 0XF90) << 16);
    // 0x80800378: addiu       $a2, $a2, 0xF90
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2168, 0XF90));
    // 0x8080037C: jal         0x80089D18
    // 0x80800380: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800380: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void _idworldmake_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F28: syscall     749
    recomp_syscall_handler(rdram, ctx, 0x80088F28);
    return;
    // 0x80088F2C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F8B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8B38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8B40: jal         0x800F88A0
    // 0x800F8B44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F88A0(rdram, ctx);
        goto after_0;
    // 0x800F8B44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F8B48: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F8B4C: jal         0x800EE7F8
    // 0x800F8B50: addiu       $a1, $v0, 0x30
    ctx->r5 = ADD32(ctx->r2, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800F8B50: addiu       $a1, $v0, 0x30
    ctx->r5 = ADD32(ctx->r2, 0X30);
    after_1:
    // 0x800F8B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8B5C: jr          $ra
    // 0x800F8B60: nop

    return;
    // 0x800F8B60: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A88: jal         0x800BF704
    // 0x80801A8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x80801A8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801A90: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801A94: sw          $t6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r14;
    // 0x80801A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AA0: jr          $ra
    // 0x80801AA4: nop

    return;
    // 0x80801AA4: nop

;}
RECOMP_FUNC void func_800ADD80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADD80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ADD84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ADD88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ADD8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800ADD90: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800ADD94: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ADD98: jal         0x800AE080
    // 0x800ADD9C: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x800ADD9C: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    after_0:
    // 0x800ADDA0: lh          $s0, 0x4($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X4);
    // 0x800ADDA4: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800ADDA8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800ADDAC: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    // 0x800ADDB0: slt         $at, $t6, $s0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800ADDB4: beq         $at, $zero, L_800ADDD4
    if (ctx->r1 == 0) {
        // 0x800ADDB8: sll         $a1, $s0, 6
        ctx->r5 = S32(ctx->r16 << 6);
            goto L_800ADDD4;
    }
    // 0x800ADDB8: sll         $a1, $s0, 6
    ctx->r5 = S32(ctx->r16 << 6);
    // 0x800ADDBC: jal         0x8001B710
    // 0x800ADDC0: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    func_8001B710(rdram, ctx);
        goto after_1;
    // 0x800ADDC0: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    after_1:
    // 0x800ADDC4: lh          $t7, 0x4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4);
    // 0x800ADDC8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800ADDCC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800ADDD0: lh          $s0, 0x4($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X4);
L_800ADDD4:
    // 0x800ADDD4: sll         $t9, $s0, 6
    ctx->r25 = S32(ctx->r16 << 6);
    // 0x800ADDD8: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x800ADDDC: addu        $s1, $t9, $v1
    ctx->r17 = ADD32(ctx->r25, ctx->r3);
    // 0x800ADDE0: addiu       $s1, $s1, 0x50
    ctx->r17 = ADD32(ctx->r17, 0X50);
    // 0x800ADDE4: jal         0x80019CD4
    // 0x800ADDE8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80019CD4(rdram, ctx);
        goto after_2;
    // 0x800ADDE8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x800ADDEC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800ADDF0: addiu       $s0, $v1, 0x50
    ctx->r16 = ADD32(ctx->r3, 0X50);
    // 0x800ADDF4: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800ADDF8: beql        $at, $zero, L_800ADE1C
    if (ctx->r1 == 0) {
        // 0x800ADDFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800ADE1C;
    }
    goto skip_0;
    // 0x800ADDFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_800ADE00:
    // 0x800ADE00: jal         0x80018AD0
    // 0x800ADE04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mlMtxGet(rdram, ctx);
        goto after_3;
    // 0x800ADE04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800ADE08: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x800ADE0C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800ADE10: bne         $at, $zero, L_800ADE00
    if (ctx->r1 != 0) {
        // 0x800ADE14: nop
    
            goto L_800ADE00;
    }
    // 0x800ADE14: nop

    // 0x800ADE18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800ADE1C:
    // 0x800ADE1C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ADE20: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ADE24: jr          $ra
    // 0x800ADE28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ADE28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsmummove_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800010: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800014: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800018: jr          $ra
    // 0x8080001C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080001C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80801CB4_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801CB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CBC: jal         0x80800238
    // 0x80801CC0: nop

    func_80800238_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801CC0: nop

    after_0:
    // 0x80801CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801CC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801CCC: jr          $ra
    // 0x80801CD0: nop

    return;
    // 0x80801CD0: nop

;}
RECOMP_FUNC void func_8009DDD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DDD0: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009DDD4: jr          $ra
    // 0x8009DDD8: lbu         $v0, 0x2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2);
    return;
    // 0x8009DDD8: lbu         $v0, 0x2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2);
;}
RECOMP_FUNC void func_8002207C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002207C: jr          $ra
    // 0x80022080: nop

    return;
    // 0x80022080: nop

;}
RECOMP_FUNC void func_808048AC_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808048AC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808048B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808048B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808048B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808048BC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    // 0x808048C0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808048C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808048C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808048CC: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    // 0x808048D0: jal         0x8008A000
    // 0x808048D4: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    _subaddiecustomhits_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808048D4: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_0:
    // 0x808048D8: beql        $v0, $zero, L_808049C0
    if (ctx->r2 == 0) {
        // 0x808048DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808049C0;
    }
    goto skip_0;
    // 0x808048DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808048E0: jal         0x80106790
    // 0x808048E4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808048E4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x808048E8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808048EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808048F0: jal         0x80100094
    // 0x808048F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808048F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808048F8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808048FC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80804900: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80804904: jal         0x800EE780
    // 0x80804908: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    func_800EE780(rdram, ctx);
        goto after_3;
    // 0x80804908: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_3:
    // 0x8080490C: jal         0x808049D4
    // 0x80804910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808049D4_chdragonbrothers(rdram, ctx);
        goto after_4;
    // 0x80804910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80804914: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80804918: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8080491C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X5900) << 16);
    // 0x80804920: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80804924: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x80804928: lb          $t8, 0x60($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X60);
    // 0x8080492C: addiu       $a2, $a2, 0x5900
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5900));
    // 0x80804930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804934: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80804938: sb          $t9, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r25;
    // 0x8080493C: jal         0x80089D18
    // 0x80804940: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80804940: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80804944: jal         0x800FFAB0
    // 0x80804948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80804948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080494C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80804950: lhu         $t1, 0x72($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X72);
    // 0x80804954: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80804958: addiu       $t3, $t2, -0x7
    ctx->r11 = ADD32(ctx->r10, -0X7);
    // 0x8080495C: sltiu       $at, $t3, 0x7
    ctx->r1 = ctx->r11 < 0X7 ? 1 : 0;
    // 0x80804960: beq         $at, $zero, L_80804994
    if (ctx->r1 == 0) {
        // 0x80804964: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80804994;
    }
    // 0x80804964: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80804968: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5374) << 16);
    // 0x8080496C: addu        $at, $at, $t3
    gpr jr_addend_80804974 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80804970: lw          $t3, 0x5374($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5374));
    // 0x80804974: jr          $t3
    // 0x80804978: nop

    switch (jr_addend_80804974 >> 2) {
        case 0: goto L_8080497C; break;
        case 1: goto L_8080497C; break;
        case 2: goto L_8080497C; break;
        case 3: goto L_8080497C; break;
        case 4: goto L_8080497C; break;
        case 5: goto L_8080497C; break;
        case 6: goto L_8080497C; break;
        default: switch_error(__func__, 0x80804974, 0x80805374);
    }
    // 0x80804978: nop

L_8080497C:
    // 0x8080497C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80804980: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    // 0x80804984: jal         0x8010114C
    // 0x80804988: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_8010114C(rdram, ctx);
        goto after_7;
    // 0x80804988: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x8080498C: b           L_808049C0
    // 0x80804990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808049C0;
    // 0x80804990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804994:
    // 0x80804994: lhu         $t5, 0x76($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X76);
    // 0x80804998: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8080499C: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x808049A0: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x808049A4: lb          $v1, 0x8($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X8);
    // 0x808049A8: blez        $v1, L_808049B4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x808049AC: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_808049B4;
    }
    // 0x808049AC: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x808049B0: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
L_808049B4:
    // 0x808049B4: b           L_808049C0
    // 0x808049B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808049C0;
    // 0x808049B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808049BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808049C0:
    // 0x808049C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808049C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808049C8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808049CC: jr          $ra
    // 0x808049D0: nop

    return;
    // 0x808049D0: nop

;}
RECOMP_FUNC void func_80800B58_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B60: jal         0x800D1A04
    // 0x80800B64: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    func_800D1A04(rdram, ctx);
        goto after_0;
    // 0x80800B64: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_0:
    // 0x80800B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B70: jr          $ra
    // 0x80800B74: nop

    return;
    // 0x80800B74: nop

;}
RECOMP_FUNC void func_80800344_fxstep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080034C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800350: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800354: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800358: jal         0x80800000
    // 0x8080035C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800000_fxstep(rdram, ctx);
        goto after_0;
    // 0x8080035C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800360: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800364: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800368: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8080036C: beq         $t6, $zero, L_8080038C
    if (ctx->r14 == 0) {
        // 0x80800370: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8080038C;
    }
    // 0x80800370: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800374: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800378: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080037C: jal         0x80800210
    // 0x80800380: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800210_fxstep(rdram, ctx);
        goto after_1;
    // 0x80800380: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800384: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800388: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_8080038C:
    // 0x8080038C: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80800390: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800394: beql        $v0, $zero, L_808003A8
    if (ctx->r2 == 0) {
        // 0x80800398: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003A8;
    }
    goto skip_0;
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080039C: jalr        $v0
    // 0x808003A0: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x808003A0: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    after_2:
    // 0x808003A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003A8:
    // 0x808003A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003AC: jr          $ra
    // 0x808003B0: nop

    return;
    // 0x808003B0: nop

;}
RECOMP_FUNC void func_808006CC_chjigsaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006D4: jal         0x800D395C
    // 0x808006D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800D395C(rdram, ctx);
        goto after_0;
    // 0x808006D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006DC: beq         $v0, $zero, L_808006F4
    if (ctx->r2 == 0) {
        // 0x808006E0: nop
    
            goto L_808006F4;
    }
    // 0x808006E0: nop

    // 0x808006E4: jal         0x800FFAB0
    // 0x808006E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x808006E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808006EC: b           L_8080073C
    // 0x808006F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080073C;
    // 0x808006F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006F4:
    // 0x808006F4: jal         0x8008A230
    // 0x808006F8: nop

    _subaddiedialog_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x808006F8: nop

    after_2:
    // 0x808006FC: beq         $v0, $zero, L_80800738
    if (ctx->r2 == 0) {
        // 0x80800700: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800738;
    }
    // 0x80800700: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800704: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800708: addiu       $t6, $zero, 0x6F
    ctx->r14 = ADD32(0, 0X6F);
    // 0x8080070C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800710: addiu       $a1, $zero, 0xD0A
    ctx->r5 = ADD32(0, 0XD0A);
    // 0x80800714: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800718: jal         0x8008A208
    // 0x8080071C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x8080071C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_3:
    // 0x80800720: beql        $v0, $zero, L_8080073C
    if (ctx->r2 == 0) {
        // 0x80800724: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080073C;
    }
    goto skip_0;
    // 0x80800724: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800728: jal         0x80088178
    // 0x8080072C: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x8080072C: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    after_4:
    // 0x80800730: jal         0x800FFAB0
    // 0x80800734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
L_80800738:
    // 0x80800738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080073C:
    // 0x8080073C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800740: jr          $ra
    // 0x80800744: nop

    return;
    // 0x80800744: nop

;}
RECOMP_FUNC void func_800BA22C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA22C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BA230: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800BA234: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800BA238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BA23C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800BA240: blez        $a1, L_800BA278
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800BA244: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800BA278;
    }
    // 0x800BA244: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BA248: lw          $a1, 0x90($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X90);
L_800BA24C:
    // 0x800BA24C: lw          $t6, 0x94($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X94);
    // 0x800BA250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BA254: addiu       $t7, $a1, 0x3C
    ctx->r15 = ADD32(ctx->r5, 0X3C);
    // 0x800BA258: sltu        $at, $a1, $t6
    ctx->r1 = ctx->r5 < ctx->r14 ? 1 : 0;
    // 0x800BA25C: beql        $at, $zero, L_800BA270
    if (ctx->r1 == 0) {
        // 0x800BA260: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800BA270;
    }
    goto skip_0;
    // 0x800BA260: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x800BA264: jal         0x800B9B50
    // 0x800BA268: sw          $t7, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r15;
    func_800B9B50(rdram, ctx);
        goto after_0;
    // 0x800BA268: sw          $t7, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r15;
    after_0:
    // 0x800BA26C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_800BA270:
    // 0x800BA270: bgtzl       $s1, L_800BA24C
    if (SIGNED(ctx->r17) > 0) {
        // 0x800BA274: lw          $a1, 0x90($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X90);
            goto L_800BA24C;
    }
    goto skip_1;
    // 0x800BA274: lw          $a1, 0x90($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X90);
    skip_1:
L_800BA278:
    // 0x800BA278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA27C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800BA280: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800BA284: jr          $ra
    // 0x800BA288: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800BA288: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800FA010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA010: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800FA014: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800FA018: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FA01C: addiu       $v0, $v0, 0x3DC0
    ctx->r2 = ADD32(ctx->r2, 0X3DC0);
    // 0x800FA020: addiu       $v1, $v1, 0x3880
    ctx->r3 = ADD32(ctx->r3, 0X3880);
L_800FA024:
    // 0x800FA024: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x800FA028: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800FA02C: bne         $at, $zero, L_800FA024
    if (ctx->r1 != 0) {
        // 0x800FA030: sb          $zero, -0xC($v1)
        MEM_B(-0XC, ctx->r3) = 0;
            goto L_800FA024;
    }
    // 0x800FA030: sb          $zero, -0xC($v1)
    MEM_B(-0XC, ctx->r3) = 0;
    // 0x800FA034: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800FA038: addiu       $v1, $v1, 0x3DC0
    ctx->r3 = ADD32(ctx->r3, 0X3DC0);
    // 0x800FA03C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FA040:
    // 0x800FA040: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x800FA044: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800FA048: sltiu       $at, $v0, 0xA
    ctx->r1 = ctx->r2 < 0XA ? 1 : 0;
    // 0x800FA04C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800FA050: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800FA054: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FA058: bne         $at, $zero, L_800FA040
    if (ctx->r1 != 0) {
        // 0x800FA05C: add.s       $f0, $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
            goto L_800FA040;
    }
    // 0x800FA05C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800FA060: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800FA064: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800FA068: addiu       $a1, $a1, 0x3DC0
    ctx->r5 = ADD32(ctx->r5, 0X3DC0);
    // 0x800FA06C: addiu       $v1, $v1, 0x3880
    ctx->r3 = ADD32(ctx->r3, 0X3880);
    // 0x800FA070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800FA074:
    // 0x800FA074: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x800FA078: andi        $a0, $v0, 0x1
    ctx->r4 = ctx->r2 & 0X1;
    // 0x800FA07C: beq         $a0, $zero, L_800FA094
    if (ctx->r4 == 0) {
        // 0x800FA080: subu        $t7, $a2, $v0
        ctx->r15 = SUB32(ctx->r6, ctx->r2);
            goto L_800FA094;
    }
    // 0x800FA080: subu        $t7, $a2, $v0
    ctx->r15 = SUB32(ctx->r6, ctx->r2);
    // 0x800FA084: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x800FA088: sb          $zero, 0xA($v1)
    MEM_B(0XA, ctx->r3) = 0;
    // 0x800FA08C: b           L_800FA098
    // 0x800FA090: andi        $a0, $v0, 0x1
    ctx->r4 = ctx->r2 & 0X1;
        goto L_800FA098;
    // 0x800FA090: andi        $a0, $v0, 0x1
    ctx->r4 = ctx->r2 & 0X1;
L_800FA094:
    // 0x800FA094: sb          $t7, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r15;
L_800FA098:
    // 0x800FA098: beq         $a0, $zero, L_800FA0A8
    if (ctx->r4 == 0) {
        // 0x800FA09C: addiu       $t8, $v0, -0x2
        ctx->r24 = ADD32(ctx->r2, -0X2);
            goto L_800FA0A8;
    }
    // 0x800FA09C: addiu       $t8, $v0, -0x2
    ctx->r24 = ADD32(ctx->r2, -0X2);
    // 0x800FA0A0: b           L_800FA0AC
    // 0x800FA0A4: sb          $t8, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r24;
        goto L_800FA0AC;
    // 0x800FA0A4: sb          $t8, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r24;
L_800FA0A8:
    // 0x800FA0A8: sb          $zero, 0xB($v1)
    MEM_B(0XB, ctx->r3) = 0;
L_800FA0AC:
    // 0x800FA0AC: lb          $t0, 0xA($v1)
    ctx->r8 = MEM_B(ctx->r3, 0XA);
    // 0x800FA0B0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800FA0B4: lb          $t4, 0xB($v1)
    ctx->r12 = MEM_B(ctx->r3, 0XB);
    // 0x800FA0B8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800FA0BC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800FA0C0: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800FA0C4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800FA0C8: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x800FA0CC: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800FA0D0: sb          $zero, -0x10($v1)
    MEM_B(-0X10, ctx->r3) = 0;
    // 0x800FA0D4: sb          $zero, -0xB($v1)
    MEM_B(-0XB, ctx->r3) = 0;
    // 0x800FA0D8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FA0DC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800FA0E0: sb          $zero, -0xA($v1)
    MEM_B(-0XA, ctx->r3) = 0;
    // 0x800FA0E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800FA0E8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800FA0EC: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800FA0F0: nop

    // 0x800FA0F4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800FA0F8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800FA0FC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800FA100: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x800FA104: nop

    // 0x800FA108: sh          $t2, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = ctx->r10;
    // 0x800FA10C: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800FA110: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800FA114: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800FA118: bne         $v1, $a1, L_800FA074
    if (ctx->r3 != ctx->r5) {
        // 0x800FA11C: sh          $t6, -0x14($v1)
        MEM_H(-0X14, ctx->r3) = ctx->r14;
            goto L_800FA074;
    }
    // 0x800FA11C: sh          $t6, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r14;
    // 0x800FA120: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800FA124: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FA128: jr          $ra
    // 0x800FA12C: sb          $t7, 0x57B0($at)
    MEM_B(0X57B0, ctx->r1) = ctx->r15;
    return;
    // 0x800FA12C: sb          $t7, 0x57B0($at)
    MEM_B(0X57B0, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void subaddietaxi_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800BB4: jal         0x8010410C
    // 0x80800BB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8010410C(rdram, ctx);
        goto after_0;
    // 0x80800BB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800BBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BC0: jal         0x801078DC
    // 0x80800BC4: addiu       $a1, $v0, 0x20
    ctx->r5 = ADD32(ctx->r2, 0X20);
    func_801078DC(rdram, ctx);
        goto after_1;
    // 0x80800BC4: addiu       $a1, $v0, 0x20
    ctx->r5 = ADD32(ctx->r2, 0X20);
    after_1:
    // 0x80800BC8: jal         0x80089C90
    // 0x80800BCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800BCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800BD0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80800BD4: bne         $v0, $at, L_80800BEC
    if (ctx->r2 != ctx->r1) {
        // 0x80800BD8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800BEC;
    }
    // 0x80800BD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BDC: jal         0x8008A4B0
    // 0x80800BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800BE4: b           L_80800BF0
    // 0x80800BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BF0;
    // 0x80800BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BEC:
    // 0x80800BEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BF0:
    // 0x80800BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BF8: jr          $ra
    // 0x80800BFC: nop

    return;
    // 0x80800BFC: nop

;}
RECOMP_FUNC void func_80800A50_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800A58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A5C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800A60: jal         0x80088078
    // 0x80800A64: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800A64: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800A68: beq         $v0, $zero, L_80800A94
    if (ctx->r2 == 0) {
        // 0x80800A6C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800A94;
    }
    // 0x80800A6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A70: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80800A74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800A7C: beq         $t6, $at, L_80800A8C
    if (ctx->r14 == ctx->r1) {
        // 0x80800A80: nop
    
            goto L_80800A8C;
    }
    // 0x80800A80: nop

    // 0x80800A84: jal         0x80800AE4
    // 0x80800A88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800AE4_chpawnbroker(rdram, ctx);
        goto after_1;
    // 0x80800A88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80800A8C:
    // 0x80800A8C: b           L_80800A98
    // 0x80800A90: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800A98;
    // 0x80800A90: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800A94:
    // 0x80800A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A98:
    // 0x80800A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AA0: jr          $ra
    // 0x80800AA4: nop

    return;
    // 0x80800AA4: nop

;}
RECOMP_FUNC void bainput_should_rotate_camera_left(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097B78: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80097B7C: jal         0x800979D8
    // 0x80097B80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    static_16_800979D8(rdram, ctx);
        goto after_0;
    // 0x80097B80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80097B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097B8C: jr          $ra
    // 0x80097B90: nop

    return;
    // 0x80097B90: nop

;}
RECOMP_FUNC void capod_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800438: jal         0x8008FFE8
    // 0x8080043C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x8080043C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80800440: beq         $v0, $zero, L_80800458
    if (ctx->r2 == 0) {
        // 0x80800444: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800458;
    }
    // 0x80800444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800448: jal         0x800895A0
    // 0x8080044C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _ncpod_entrypoint_28(rdram, ctx);
        goto after_1;
    // 0x8080044C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800450: b           L_80800460
    // 0x80800454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800460;
    // 0x80800454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800458:
    // 0x80800458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800460:
    // 0x80800460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void _baeggfire_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B48: syscall     129
    recomp_syscall_handler(rdram, ctx, 0x80084B48);
    return;
    // 0x80084B4C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800B94_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B94: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800B98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800BA0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800BA4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800BA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BAC: lw          $v0, 0x28($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X28);
    // 0x80800BB0: sll         $t7, $v0, 18
    ctx->r15 = S32(ctx->r2 << 18);
    // 0x80800BB4: sll         $t9, $v0, 19
    ctx->r25 = S32(ctx->r2 << 19);
    // 0x80800BB8: sll         $t1, $v0, 20
    ctx->r9 = S32(ctx->r2 << 20);
    // 0x80800BBC: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80800BC0: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80800BC4: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x80800BC8: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80800BCC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80800BD0: jal         0x801015D0
    // 0x80800BD4: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x80800BD4: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    after_0:
    // 0x80800BD8: jal         0x808010F4
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808010F4_chboilerboss(rdram, ctx);
        goto after_1;
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800BE0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80800BE4: beql        $t3, $zero, L_80800C10
    if (ctx->r11 == 0) {
        // 0x80800BE8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800C10;
    }
    goto skip_0;
    // 0x80800BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_0:
    // 0x80800BEC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80800BF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800BF4: beq         $t4, $zero, L_80800C04
    if (ctx->r12 == 0) {
        // 0x80800BF8: nop
    
            goto L_80800C04;
    }
    // 0x80800BF8: nop

    // 0x80800BFC: b           L_80800C10
    // 0x80800C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800C10;
    // 0x80800C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800C04:
    // 0x80800C04: b           L_80800C10
    // 0x80800C08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80800C10;
    // 0x80800C08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800C0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800C10:
    // 0x80800C10: jal         0x800DF744
    // 0x80800C14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800C14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x80800C18: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800C1C: jal         0x800DF744
    // 0x80800C20: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800C20: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x80800C24: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800C28: jal         0x800DF744
    // 0x80800C2C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x80800C2C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x80800C30: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80800C34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C38: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800C3C: beq         $t5, $zero, L_80800C5C
    if (ctx->r13 == 0) {
        // 0x80800C40: nop
    
            goto L_80800C5C;
    }
    // 0x80800C40: nop

    // 0x80800C44: beq         $t6, $zero, L_80800C54
    if (ctx->r14 == 0) {
        // 0x80800C48: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800C54;
    }
    // 0x80800C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800C4C: b           L_80800C5C
    // 0x80800C50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800C5C;
    // 0x80800C50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800C54:
    // 0x80800C54: b           L_80800C5C
    // 0x80800C58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80800C5C;
    // 0x80800C58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800C5C:
    // 0x80800C5C: jal         0x800DF744
    // 0x80800C60: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x80800C60: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_5:
    // 0x80800C64: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80800C68: jal         0x800DF744
    // 0x80800C6C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800DF744(rdram, ctx);
        goto after_6;
    // 0x80800C6C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x80800C70: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800C74: jal         0x800DF744
    // 0x80800C78: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x80800C78: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x80800C7C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800C80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C84: beq         $t7, $zero, L_80800C94
    if (ctx->r15 == 0) {
        // 0x80800C88: nop
    
            goto L_80800C94;
    }
    // 0x80800C88: nop

    // 0x80800C8C: b           L_80800C94
    // 0x80800C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800C94;
    // 0x80800C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800C94:
    // 0x80800C94: jal         0x800DF744
    // 0x80800C98: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800DF744(rdram, ctx);
        goto after_8;
    // 0x80800C98: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_8:
    // 0x80800C9C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800CA0: jal         0x800DF744
    // 0x80800CA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800DF744(rdram, ctx);
        goto after_9;
    // 0x80800CA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x80800CA8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80800CAC: jal         0x800DF744
    // 0x80800CB0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800DF744(rdram, ctx);
        goto after_10;
    // 0x80800CB0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x80800CB4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80800CB8: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x80800CBC: sll         $t1, $t9, 20
    ctx->r9 = S32(ctx->r25 << 20);
    // 0x80800CC0: bgezl       $t1, L_80800D40
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800CC4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800D40;
    }
    goto skip_1;
    // 0x80800CC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800CC8: jal         0x800B2768
    // 0x80800CCC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800B2768(rdram, ctx);
        goto after_11;
    // 0x80800CCC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_11:
    // 0x80800CD0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CD8: jal         0x80103CDC
    // 0x80800CDC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80103CDC(rdram, ctx);
        goto after_12;
    // 0x80800CDC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_12:
    // 0x80800CE0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800CE4: jal         0x800B2840
    // 0x80800CE8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800B2840(rdram, ctx);
        goto after_13;
    // 0x80800CE8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_13:
    // 0x80800CEC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800CF0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80800CF4: jal         0x800AE0E8
    // 0x80800CF8: lh          $a0, 0x10($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X10);
    func_800AE0E8(rdram, ctx);
        goto after_14;
    // 0x80800CF8: lh          $a0, 0x10($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X10);
    after_14:
    // 0x80800CFC: beql        $v0, $zero, L_80800D2C
    if (ctx->r2 == 0) {
        // 0x80800D00: lbu         $a0, 0x98($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X98);
            goto L_80800D2C;
    }
    goto skip_2;
    // 0x80800D00: lbu         $a0, 0x98($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X98);
    skip_2:
    // 0x80800D04: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80800D08: jal         0x800AE080
    // 0x80800D0C: lh          $a0, 0x10($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X10);
    func_800AE080(rdram, ctx);
        goto after_15;
    // 0x80800D0C: lh          $a0, 0x10($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X10);
    after_15:
    // 0x80800D10: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800D14: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D18: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800D1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800D20: jal         0x80087998
    // 0x80800D24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    _dbmorph_entrypoint_4(rdram, ctx);
        goto after_16;
    // 0x80800D24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_16:
    // 0x80800D28: lbu         $a0, 0x98($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X98);
L_80800D2C:
    // 0x80800D2C: lbu         $a1, 0x99($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X99);
    // 0x80800D30: lbu         $a2, 0x9A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9A);
    // 0x80800D34: jal         0x800DF5D8
    // 0x80800D38: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800DF5D8(rdram, ctx);
        goto after_17;
    // 0x80800D38: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_17:
    // 0x80800D3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D40:
    // 0x80800D40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800D44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800D48: jr          $ra
    // 0x80800D4C: nop

    return;
    // 0x80800D4C: nop

;}
RECOMP_FUNC void func_808005F4_chbanjocurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808005F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005FC: jal         0x80800000
    // 0x80800600: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    func_80800000_chbanjocurrent(rdram, ctx);
        goto after_0;
    // 0x80800600: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800604: beql        $v0, $zero, L_8080079C
    if (ctx->r2 == 0) {
        // 0x80800608: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080079C;
    }
    goto skip_0;
    // 0x80800608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080060C: jal         0x800F54E4
    // 0x80800610: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800610: nop

    after_1:
    // 0x80800614: jal         0x800D8FF8
    // 0x80800618: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800618: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_2:
    // 0x8080061C: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x80800620: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800624: lhu         $t6, 0x76($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X76);
    // 0x80800628: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080062C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800630: bgez        $t7, L_80800644
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800634: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800644;
    }
    // 0x80800634: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800638: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080063C: nop

    // 0x80800640: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800644:
    // 0x80800644: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800648: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080064C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800650: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80800654: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800658: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8080065C: jal         0x8008FF94
    // 0x80800660: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    func_8008FF94(rdram, ctx);
        goto after_3;
    // 0x80800660: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    after_3:
    // 0x80800664: beq         $v0, $zero, L_80800798
    if (ctx->r2 == 0) {
        // 0x80800668: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800798;
    }
    // 0x80800668: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080066C: bnel        $v0, $at, L_808006E0
    if (ctx->r2 != ctx->r1) {
        // 0x80800670: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808006E0;
    }
    goto skip_1;
    // 0x80800670: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x80800674: jal         0x800F5E7C
    // 0x80800678: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800F5E7C(rdram, ctx);
        goto after_4;
    // 0x80800678: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x8080067C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800680: jal         0x800F5F7C
    // 0x80800684: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800F5F7C(rdram, ctx);
        goto after_5;
    // 0x80800684: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_5:
    // 0x80800688: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080068C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800690: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800694: sub.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80800698: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080069C: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x808006A0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x808006A4: bc1tl       L_8080079C
    if (c1cs) {
        // 0x808006A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080079C;
    }
    goto skip_2;
    // 0x808006A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x808006AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808006B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(756, 0X7C0) << 16);
    // 0x808006B8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808006BC: nop

    // 0x808006C0: bc1f        L_808006CC
    if (!c1cs) {
        // 0x808006C4: nop
    
            goto L_808006CC;
    }
    // 0x808006C4: nop

    // 0x808006C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_808006CC:
    // 0x808006CC: lwc1        $f4, 0x7C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(756, 0X7C0));
    // 0x808006D0: mul.s       $f18, $f12, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x808006D4: b           L_808006E8
    // 0x808006D8: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
        goto L_808006E8;
    // 0x808006D8: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808006DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_808006E0:
    // 0x808006E0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808006E4: nop

L_808006E8:
    // 0x808006E8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808006EC: jal         0x800F5E50
    // 0x808006F0: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    func_800F5E50(rdram, ctx);
        goto after_6;
    // 0x808006F0: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x808006F4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x808006F8: lui         $at, 0x7800
    ctx->r1 = S32(0X7800 << 16);
    // 0x808006FC: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800700: and         $t8, $v1, $at
    ctx->r24 = ctx->r3 & ctx->r1;
    // 0x80800704: srl         $v1, $t8, 27
    ctx->r3 = S32(U32(ctx->r24) >> 27);
    // 0x80800708: beql        $v1, $zero, L_8080079C
    if (ctx->r3 == 0) {
        // 0x8080070C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080079C;
    }
    goto skip_3;
    // 0x8080070C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80800710: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80800714: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80800718: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8080071C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800720: lwc1        $f8, 0x48($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X48);
    // 0x80800724: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80800728: nop

    // 0x8080072C: bc1fl       L_8080079C
    if (!c1cs) {
        // 0x80800730: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080079C;
    }
    goto skip_4;
    // 0x80800730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80800734: jal         0x80090794
    // 0x80800738: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    func_80090794(rdram, ctx);
        goto after_7;
    // 0x80800738: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    after_7:
    // 0x8080073C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80800740: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800744: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800748: jal         0x80800514
    // 0x8080074C: lw          $a2, 0x58($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X58);
    func_80800514_chbanjocurrent(rdram, ctx);
        goto after_8;
    // 0x8080074C: lw          $a2, 0x58($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X58);
    after_8:
    // 0x80800750: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800754: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800758: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080075C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800760: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800764: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80800768: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080076C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800770: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800774: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800778: nop

    // 0x8080077C: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80800780: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800784: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800788: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8080078C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80800790: jal         0x800907C0
    // 0x80800794: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    func_800907C0(rdram, ctx);
        goto after_9;
    // 0x80800794: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_9:
L_80800798:
    // 0x80800798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080079C:
    // 0x8080079C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808007A0: jr          $ra
    // 0x808007A4: nop

    return;
    // 0x808007A4: nop

    // 0x808007A8: nop

    // 0x808007AC: nop

;}
RECOMP_FUNC void func_800B5824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5824: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B5828: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B582C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B5830: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B5834: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800B5838: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B583C: addiu       $s1, $s1, 0x7F34
    ctx->r17 = ADD32(ctx->r17, 0X7F34);
    // 0x800B5840: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800B5844: addiu       $s2, $zero, 0x2D
    ctx->r18 = ADD32(0, 0X2D);
L_800B5848:
    // 0x800B5848: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x800B584C: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x800B5850: beql        $t7, $zero, L_800B5864
    if (ctx->r15 == 0) {
        // 0x800B5854: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5864;
    }
    goto skip_0;
    // 0x800B5854: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800B5858: jal         0x800B58D4
    // 0x800B585C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800B58D4(rdram, ctx);
        goto after_0;
    // 0x800B585C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x800B5860: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5864:
    // 0x800B5864: bne         $s0, $s2, L_800B5848
    if (ctx->r16 != ctx->r18) {
        // 0x800B5868: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800B5848;
    }
    // 0x800B5868: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800B586C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B5870: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B5874: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5878: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B587C: jr          $ra
    // 0x800B5880: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B5880: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808008D0_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008D8: jal         0x8008CABC
    // 0x808008DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808008DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2DF4) << 16);
    // 0x808008E4: lwc1        $f4, 0x2DF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2DF4));
    // 0x808008E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2DF8) << 16);
    // 0x808008EC: lwc1        $f6, 0x2DF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2DF8));
    // 0x808008F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808008F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808008F8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x808008FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800900: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80800904: jal         0x80084FE0
    // 0x80800908: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800908: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8080090C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800910: beq         $v0, $at, L_80800930
    if (ctx->r2 == ctx->r1) {
        // 0x80800914: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800930;
    }
    // 0x80800914: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800918: beq         $v0, $at, L_80800940
    if (ctx->r2 == ctx->r1) {
        // 0x8080091C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800940;
    }
    // 0x8080091C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800920: beq         $v0, $at, L_80800948
    if (ctx->r2 == ctx->r1) {
        // 0x80800924: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800948;
    }
    // 0x80800924: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800928: b           L_808009A4
    // 0x8080092C: lui         $a1, 0x3E58
    ctx->r5 = S32(0X3E58 << 16);
        goto L_808009A4;
    // 0x8080092C: lui         $a1, 0x3E58
    ctx->r5 = S32(0X3E58 << 16);
L_80800930:
    // 0x80800930: jal         0x80085078
    // 0x80800934: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _bashoes_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800934: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800938: b           L_808009D0
    // 0x8080093C: nop

        goto L_808009D0;
    // 0x8080093C: nop

L_80800940:
    // 0x80800940: b           L_808009D0
    // 0x80800944: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
        goto L_808009D0;
    // 0x80800944: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80800948:
    // 0x80800948: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2DFC) << 16);
    // 0x8080094C: lwc1        $f0, 0x2DFC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2DFC));
    // 0x80800950: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2E00) << 16);
    // 0x80800954: lwc1        $f8, 0x2E00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2E00));
    // 0x80800958: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080095C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800960: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800964: jal         0x8008B348
    // 0x80800968: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x80800968: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8080096C: beql        $v0, $zero, L_80800980
    if (ctx->r2 == 0) {
        // 0x80800970: lui         $a1, 0x3E36
        ctx->r5 = S32(0X3E36 << 16);
            goto L_80800980;
    }
    goto skip_0;
    // 0x80800970: lui         $a1, 0x3E36
    ctx->r5 = S32(0X3E36 << 16);
    skip_0:
    // 0x80800974: jal         0x80085070
    // 0x80800978: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _bashoes_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800978: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x8080097C: lui         $a1, 0x3E36
    ctx->r5 = S32(0X3E36 << 16);
L_80800980:
    // 0x80800980: ori         $a1, $a1, 0x9446
    ctx->r5 = ctx->r5 | 0X9446;
    // 0x80800984: jal         0x8008B348
    // 0x80800988: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x80800988: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x8080098C: beq         $v0, $zero, L_808009D0
    if (ctx->r2 == 0) {
        // 0x80800990: nop
    
            goto L_808009D0;
    }
    // 0x80800990: nop

    // 0x80800994: jal         0x80085068
    // 0x80800998: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _bashoes_entrypoint_18(rdram, ctx);
        goto after_6;
    // 0x80800998: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x8080099C: b           L_808009D0
    // 0x808009A0: nop

        goto L_808009D0;
    // 0x808009A0: nop

L_808009A4:
    // 0x808009A4: jal         0x8008B348
    // 0x808009A8: ori         $a1, $a1, 0x9375
    ctx->r5 = ctx->r5 | 0X9375;
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x808009A8: ori         $a1, $a1, 0x9375
    ctx->r5 = ctx->r5 | 0X9375;
    after_7:
    // 0x808009AC: bne         $v0, $zero, L_808009C8
    if (ctx->r2 != 0) {
        // 0x808009B0: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808009C8;
    }
    // 0x808009B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808009B4: lui         $a1, 0x3F36
    ctx->r5 = S32(0X3F36 << 16);
    // 0x808009B8: jal         0x8008B348
    // 0x808009BC: ori         $a1, $a1, 0x24DD
    ctx->r5 = ctx->r5 | 0X24DD;
    anctrl_isAt(rdram, ctx);
        goto after_8;
    // 0x808009BC: ori         $a1, $a1, 0x24DD
    ctx->r5 = ctx->r5 | 0X24DD;
    after_8:
    // 0x808009C0: beq         $v0, $zero, L_808009D0
    if (ctx->r2 == 0) {
        // 0x808009C4: nop
    
            goto L_808009D0;
    }
    // 0x808009C4: nop

L_808009C8:
    // 0x808009C8: jal         0x800849D0
    // 0x808009CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _badust_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808009CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_9:
L_808009D0:
    // 0x808009D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2E04) << 16);
    // 0x808009D4: lwc1        $f16, 0x2E04($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2E04));
    // 0x808009D8: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808009DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808009E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009E4: jal         0x800F13C4
    // 0x808009E8: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    func_800F13C4(rdram, ctx);
        goto after_10;
    // 0x808009E8: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_10:
    // 0x808009EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808009F0: jal         0x8008B348
    // 0x808009F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_11;
    // 0x808009F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x808009F8: beq         $v0, $zero, L_80800A08
    if (ctx->r2 == 0) {
        // 0x808009FC: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800A08;
    }
    // 0x808009FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A00: jal         0x808000DC
    // 0x80800A04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000DC_bsbtrot(rdram, ctx);
        goto after_12;
    // 0x80800A04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
L_80800A08:
    // 0x80800A08: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2E08) << 16);
    // 0x80800A0C: lwc1        $f4, 0x2E08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2E08));
    // 0x80800A10: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800A14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A18: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800A1C: jal         0x800F13C4
    // 0x80800A20: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    func_800F13C4(rdram, ctx);
        goto after_13;
    // 0x80800A20: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_13:
    // 0x80800A24: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800A28: jal         0x8008B348
    // 0x80800A2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_14;
    // 0x80800A2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x80800A30: beq         $v0, $zero, L_80800A40
    if (ctx->r2 == 0) {
        // 0x80800A34: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800A40;
    }
    // 0x80800A34: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A38: jal         0x808000DC
    // 0x80800A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808000DC_bsbtrot(rdram, ctx);
        goto after_15;
    // 0x80800A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
L_80800A40:
    // 0x80800A40: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800A44: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800A48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A4C: beq         $t7, $zero, L_80800A78
    if (ctx->r15 == 0) {
        // 0x80800A50: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A78;
    }
    // 0x80800A50: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A58: jal         0x800A2CE8
    // 0x80800A5C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800A2CE8(rdram, ctx);
        goto after_16;
    // 0x80800A5C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_16:
    // 0x80800A60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A64: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800A68: jal         0x800A2CE8
    // 0x80800A6C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_17;
    // 0x80800A6C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_17:
    // 0x80800A70: b           L_80800A94
    // 0x80800A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A94;
    // 0x80800A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A78:
    // 0x80800A78: jal         0x800A2D2C
    // 0x80800A7C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2D2C(rdram, ctx);
        goto after_18;
    // 0x80800A7C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_18:
    // 0x80800A80: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A84: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800A88: jal         0x800A2D2C
    // 0x80800A8C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2D2C(rdram, ctx);
        goto after_19;
    // 0x80800A8C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_19:
    // 0x80800A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A94:
    // 0x80800A94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A98: jr          $ra
    // 0x80800A9C: nop

    return;
    // 0x80800A9C: nop

;}
RECOMP_FUNC void func_80081724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008172C: jal         0x80081744
    // 0x80081730: nop

    func_80081744(rdram, ctx);
        goto after_0;
    // 0x80081730: nop

    after_0:
    // 0x80081734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008173C: jr          $ra
    // 0x80081740: nop

    return;
    // 0x80081740: nop

;}
RECOMP_FUNC void func_8080011C_babackpack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800120: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800124: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800128: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080012C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800130: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80800134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080013C: jal         0x8009272C
    // 0x80800140: swc1        $f12, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f12.u32l;
    func_8009272C(rdram, ctx);
        goto after_0;
    // 0x80800140: swc1        $f12, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f12.u32l;
    after_0:
    // 0x80800144: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x80800148: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8080014C: bnel        $t7, $zero, L_8080016C
    if (ctx->r15 != 0) {
        // 0x80800150: lw          $t9, 0x0($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X0);
            goto L_8080016C;
    }
    goto skip_0;
    // 0x80800150: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80800154: jal         0x800DBFF8
    // 0x80800158: nop

    func_800DBFF8(rdram, ctx);
        goto after_1;
    // 0x80800158: nop

    after_1:
    // 0x8080015C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80800160: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x80800164: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x80800168: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
L_8080016C:
    // 0x8080016C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80800170: bnel        $t9, $zero, L_80800184
    if (ctx->r25 != 0) {
        // 0x80800174: lbu         $t1, 0x8($v1)
        ctx->r9 = MEM_BU(ctx->r3, 0X8);
            goto L_80800184;
    }
    goto skip_1;
    // 0x80800174: lbu         $t1, 0x8($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X8);
    skip_1:
    // 0x80800178: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8080017C: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x80800180: lbu         $t1, 0x8($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X8);
L_80800184:
    // 0x80800184: bnel        $t1, $zero, L_8080020C
    if (ctx->r9 != 0) {
        // 0x80800188: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080020C;
    }
    goto skip_2;
    // 0x80800188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8080018C: jal         0x808000E0
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    babackpack_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800194: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800198: jal         0x800B26F0
    // 0x8080019C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B26F0(rdram, ctx);
        goto after_3;
    // 0x8080019C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808001A0: beql        $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x808001A4: lw          $t4, 0x14($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X14);
            goto L_808001BC;
    }
    goto skip_3;
    // 0x808001A4: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    skip_3:
    // 0x808001A8: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x808001AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808001B0: b           L_808001C0
    // 0x808001B4: sb          $t2, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r10;
        goto L_808001C0;
    // 0x808001B4: sb          $t2, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r10;
    // 0x808001B8: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
L_808001BC:
    // 0x808001BC: sb          $zero, 0xA($t4)
    MEM_B(0XA, ctx->r12) = 0;
L_808001C0:
    // 0x808001C0: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: lbu         $t6, 0xA($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XA);
    // 0x808001CC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x808001D0: jal         0x800A25D0
    // 0x808001D4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    func_800A25D0(rdram, ctx);
        goto after_4;
    // 0x808001D4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_4:
    // 0x808001D8: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x808001DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808001E0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808001E4: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x808001E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808001EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808001F0: jal         0x80100D24
    // 0x808001F4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80100D24(rdram, ctx);
        goto after_5;
    // 0x808001F4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_5:
    // 0x808001F8: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x808001FC: sb          $v0, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r2;
    // 0x80800200: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x80800204: sb          $zero, 0x9($t0)
    MEM_B(0X9, ctx->r8) = 0;
    // 0x80800208: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080020C:
    // 0x8080020C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800210: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
RECOMP_FUNC void _sucoasterhit_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A328: syscall     836
    recomp_syscall_handler(rdram, ctx, 0x8008A328);
    return;
    // 0x8008A32C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bamovegoto_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080026C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800270: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800274: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800278: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080027C: lw          $s0, 0xC8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0XC8);
    // 0x80800280: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800284: lbu         $t6, 0x54($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X54);
    // 0x80800288: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x8080028C: beq         $at, $zero, L_808005CC
    if (ctx->r1 == 0) {
        // 0x80800290: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808005CC;
    }
    // 0x80800290: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800294: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(548, 0X5E0) << 16);
    // 0x80800298: addu        $at, $at, $t6
    gpr jr_addend_808002A0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080029C: lw          $t6, 0x5E0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(548, 0X5E0));
    // 0x808002A0: jr          $t6
    // 0x808002A4: nop

    switch (jr_addend_808002A0 >> 2) {
        case 0: goto L_808005CC; break;
        case 1: goto L_808005CC; break;
        case 2: goto L_808002A8; break;
        case 3: goto L_80800330; break;
        case 4: goto L_8080049C; break;
        case 5: goto L_808004BC; break;
        case 6: goto L_808005CC; break;
        default: switch_error(__func__, 0x808002A0, 0x808005E0);
    }
    // 0x808002A4: nop

L_808002A8:
    // 0x808002A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002AC: jal         0x8009C128
    // 0x808002B0: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808002B0: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x808002B4: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x808002B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002BC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808002C0: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x808002C4: addiu       $a1, $s0, 0x64
    ctx->r5 = ADD32(ctx->r16, 0X64);
    // 0x808002C8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x808002CC: nop

    // 0x808002D0: bc1tl       L_80800300
    if (c1cs) {
        // 0x808002D4: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800300;
    }
    goto skip_0;
    // 0x808002D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x808002D8: jal         0x800EFB24
    // 0x808002DC: addiu       $a2, $s0, 0x58
    ctx->r6 = ADD32(ctx->r16, 0X58);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x808002DC: addiu       $a2, $s0, 0x58
    ctx->r6 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x808002E0: jal         0x800EEFFC
    // 0x808002E4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_800EEFFC(rdram, ctx);
        goto after_2;
    // 0x808002E4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x808002E8: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x808002EC: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x808002F0: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808002F4: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x808002F8: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x808002FC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800300:
    // 0x80800300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800308: jal         0x8009BA9C
    // 0x8080030C: swc1        $f14, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f14.u32l;
    func_8009BA9C(rdram, ctx);
        goto after_3;
    // 0x8080030C: swc1        $f14, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f14.u32l;
    after_3:
    // 0x80800310: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800314: jal         0x8009B9B0
    // 0x80800318: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800318: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x8080031C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800320: jal         0x80800000
    // 0x80800324: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800000_bamovegoto(rdram, ctx);
        goto after_5;
    // 0x80800324: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800328: b           L_808005D0
    // 0x8080032C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005D0;
    // 0x8080032C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800330:
    // 0x80800330: jal         0x800D8FF8
    // 0x80800334: nop

    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x80800334: nop

    after_6:
    // 0x80800338: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x8080033C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800340: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800344: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80800348: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080034C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800350: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80800354: swc1        $f18, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f18.u32l;
    // 0x80800358: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x8080035C: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80800360: lw          $a2, 0x70($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X70);
    // 0x80800364: jal         0x800F10B4
    // 0x80800368: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800368: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x8080036C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80800370: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x80800374: lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X80);
    // 0x80800378: beq         $v0, $zero, L_80800394
    if (ctx->r2 == 0) {
        // 0x8080037C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800394;
    }
    // 0x8080037C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800380: jalr        $v0
    // 0x80800384: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x80800384: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_8:
    // 0x80800388: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8080038C: b           L_80800398
    // 0x80800390: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
        goto L_80800398;
    // 0x80800390: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
L_80800394:
    // 0x80800394: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
L_80800398:
    // 0x80800398: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080039C: jal         0x800EE7F8
    // 0x808003A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x808003A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x808003A4: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x808003A8: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808003AC: lwc1        $f14, 0x58($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808003B0: jal         0x800F1214
    // 0x808003B4: lw          $a2, 0x64($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X64);
    func_800F1214(rdram, ctx);
        goto after_10;
    // 0x808003B4: lw          $a2, 0x64($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X64);
    after_10:
    // 0x808003B8: lw          $t7, 0xC8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC8);
    // 0x808003BC: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x808003C0: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x808003C4: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808003C8: lwc1        $f14, 0x5C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x808003CC: jal         0x800F1214
    // 0x808003D0: lw          $a2, 0x68($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X68);
    func_800F1214(rdram, ctx);
        goto after_11;
    // 0x808003D0: lw          $a2, 0x68($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X68);
    after_11:
    // 0x808003D4: lw          $t8, 0xC8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC8);
    // 0x808003D8: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
    // 0x808003DC: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x808003E0: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808003E4: lwc1        $f14, 0x60($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X60);
    // 0x808003E8: jal         0x800F1214
    // 0x808003EC: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    func_800F1214(rdram, ctx);
        goto after_12;
    // 0x808003EC: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    after_12:
    // 0x808003F0: lw          $t9, 0xC8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC8);
    // 0x808003F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003F8: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x808003FC: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x80800400: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80800404: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800408: beql        $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x8080040C: addiu       $a0, $s0, 0x10
        ctx->r4 = ADD32(ctx->r16, 0X10);
            goto L_80800420;
    }
    goto skip_1;
    // 0x8080040C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    skip_1:
    // 0x80800410: jalr        $v0
    // 0x80800414: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_13;
    // 0x80800414: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    after_13:
    // 0x80800418: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x8080041C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
L_80800420:
    // 0x80800420: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800424: jal         0x800EFB24
    // 0x80800428: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_800EFB24(rdram, ctx);
        goto after_14;
    // 0x80800428: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_14:
    // 0x8080042C: jal         0x800D8FF8
    // 0x80800430: nop

    func_800D8FF8(rdram, ctx);
        goto after_15;
    // 0x80800430: nop

    after_15:
    // 0x80800434: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800438: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080043C: lw          $a0, 0xC8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC8);
    // 0x80800440: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800444: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80800448: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080044C: jal         0x800EF334
    // 0x80800450: nop

    func_800EF334(rdram, ctx);
        goto after_16;
    // 0x80800450: nop

    after_16:
    // 0x80800454: lw          $a0, 0xC8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC8);
    // 0x80800458: jal         0x800EEF94
    // 0x8080045C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EEF94(rdram, ctx);
        goto after_17;
    // 0x8080045C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_17:
    // 0x80800460: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800464: jal         0x8009B9B0
    // 0x80800468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x8080046C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800470: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800474: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800478: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080047C: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80800480: nop

    // 0x80800484: bc1fl       L_808005D0
    if (!c1cs) {
        // 0x80800488: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808005D0;
    }
    goto skip_2;
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8080048C: jal         0x80800000
    // 0x80800490: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800000_bamovegoto(rdram, ctx);
        goto after_19;
    // 0x80800490: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_19:
    // 0x80800494: b           L_808005D0
    // 0x80800498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005D0;
    // 0x80800498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080049C:
    // 0x8080049C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004A0: jal         0x8009C128
    // 0x808004A4: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    func_8009C128(rdram, ctx);
        goto after_20;
    // 0x808004A4: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    after_20:
    // 0x808004A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004AC: jal         0x80800000
    // 0x808004B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800000_bamovegoto(rdram, ctx);
        goto after_21;
    // 0x808004B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_21:
    // 0x808004B4: b           L_808005D0
    // 0x808004B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005D0;
    // 0x808004B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004BC:
    // 0x808004BC: jal         0x800D8FF8
    // 0x808004C0: nop

    func_800D8FF8(rdram, ctx);
        goto after_22;
    // 0x808004C0: nop

    after_22:
    // 0x808004C4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808004C8: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x808004CC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808004D0: addiu       $a1, $s0, 0x64
    ctx->r5 = ADD32(ctx->r16, 0X64);
    // 0x808004D4: jal         0x800EFB24
    // 0x808004D8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_23;
    // 0x808004D8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_23:
    // 0x808004DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808004E0: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: jal         0x800EEFFC
    // 0x808004EC: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    func_800EEFFC(rdram, ctx);
        goto after_24;
    // 0x808004EC: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_24:
    // 0x808004F0: lw          $t0, 0xC8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC8);
    // 0x808004F4: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808004F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004FC: lwc1        $f2, 0x78($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X78);
    // 0x80800500: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80800504: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80800508: nop

    // 0x8080050C: bc1fl       L_80800528
    if (!c1cs) {
        // 0x80800510: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_80800528;
    }
    goto skip_3;
    // 0x80800510: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_3:
    // 0x80800514: jal         0x80800000
    // 0x80800518: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800000_bamovegoto(rdram, ctx);
        goto after_25;
    // 0x80800518: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_25:
    // 0x8080051C: b           L_80800534
    // 0x80800520: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
        goto L_80800534;
    // 0x80800520: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800524: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_80800528:
    // 0x80800528: jal         0x800EF368
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF368(rdram, ctx);
        goto after_26;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800530: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
L_80800534:
    // 0x80800534: lw          $t1, 0xC8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC8);
    // 0x80800538: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
    // 0x8080053C: lw          $t2, 0xC8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC8);
    // 0x80800540: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800544: swc1        $f10, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f10.u32l;
    // 0x80800548: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x8080054C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800550: lbu         $t3, 0x56($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X56);
    // 0x80800554: beql        $t3, $zero, L_80800598
    if (ctx->r11 == 0) {
        // 0x80800558: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_80800598;
    }
    goto skip_4;
    // 0x80800558: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    skip_4:
    // 0x8080055C: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800560: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800564: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800568: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8080056C: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x80800570: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x80800574: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800578: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8080057C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800580: nop

    // 0x80800584: bc1fl       L_80800598
    if (!c1cs) {
        // 0x80800588: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_80800598;
    }
    goto skip_5;
    // 0x80800588: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    skip_5:
    // 0x8080058C: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80800590: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x80800594: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
L_80800598:
    // 0x80800598: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8080059C: jal         0x800EFA20
    // 0x808005A0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_800EFA20(rdram, ctx);
        goto after_27;
    // 0x808005A0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_27:
    // 0x808005A4: lw          $a0, 0xC8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC8);
    // 0x808005A8: jal         0x800EEF94
    // 0x808005AC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EEF94(rdram, ctx);
        goto after_28;
    // 0x808005AC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_28:
    // 0x808005B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005B4: jal         0x8009B9B0
    // 0x808005B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_29;
    // 0x808005B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
    // 0x808005BC: lw          $s0, 0xC8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC8);
    // 0x808005C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808005C4: jal         0x800EF04C
    // 0x808005C8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_30;
    // 0x808005C8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_30:
L_808005CC:
    // 0x808005CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005D0:
    // 0x808005D0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808005D4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808005D8: jr          $ra
    // 0x808005DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x808005DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void chaliendad_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1364, 0X2674) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2674
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1364, 0X2674));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2674
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1364, 0X2674));
;}
RECOMP_FUNC void _bstrexlarge_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084038: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084038);
    return;
    // 0x8008403C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _baswim_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085290: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x80085290);
    return;
    // 0x80085294: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80801B9C_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801BA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801BA4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X2824) << 16);
    // 0x80801BA8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1364, 0X25C0) << 16);
    // 0x80801BAC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80801BB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801BB4: addiu       $a3, $a3, 0x25C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1364, 0X25C0));
    // 0x80801BB8: addiu       $a2, $a2, 0x2824
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X2824));
    // 0x80801BBC: jal         0x8008A1F0
    // 0x80801BC0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80801BC0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80801BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801BC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801BCC: jr          $ra
    // 0x80801BD0: nop

    return;
    // 0x80801BD0: nop

;}
RECOMP_FUNC void _subaddiecustomhits_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A018: syscall     822
    recomp_syscall_handler(rdram, ctx, 0x8008A018);
    return;
    // 0x8008A01C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void sufreezy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: jal         0x80800000
    // 0x80800044: nop

    sufreezy_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800044: nop

    after_0:
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_8001A2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A2B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A2B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A2B8: jal         0x80013D10
    // 0x8001A2BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80013D10(rdram, ctx);
        goto after_0;
    // 0x8001A2BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8001A2C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A2C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A2C8: jr          $ra
    // 0x8001A2CC: nop

    return;
    // 0x8001A2CC: nop

;}
RECOMP_FUNC void func_800E6DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6DB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E6DB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E6DBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E6DC0: jal         0x800E6DD8
    // 0x800E6DC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800E6DD8(rdram, ctx);
        goto after_0;
    // 0x800E6DC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800E6DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E6DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E6DD0: jr          $ra
    // 0x800E6DD4: nop

    return;
    // 0x800E6DD4: nop

;}
RECOMP_FUNC void _bavan_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085370: syscall     159
    recomp_syscall_handler(rdram, ctx, 0x80085370);
    return;
    // 0x80085374: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chklungoforcefield_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1248, 0X400) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1248, 0X400));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1248, 0X400));
;}
RECOMP_FUNC void chpowerhutwitchy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1080, 0XBB8) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xBB8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1080, 0XBB8));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xBB8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1080, 0XBB8));
;}
RECOMP_FUNC void func_80804FB4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804FB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804FBC: jal         0x80807C8C
    // 0x80804FC0: nop

    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804FC0: nop

    after_0:
    // 0x80804FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804FCC: jr          $ra
    // 0x80804FD0: nop

    return;
    // 0x80804FD0: nop

;}
RECOMP_FUNC void func_808002A0_chpumproomswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808002A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002B0: beq         $a1, $at, L_808002CC
    if (ctx->r5 == ctx->r1) {
        // 0x808002B4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808002CC;
    }
    // 0x808002B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002B8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808002BC: beq         $a1, $at, L_80800338
    if (ctx->r5 == ctx->r1) {
        // 0x808002C0: nop
    
            goto L_80800338;
    }
    // 0x808002C0: nop

    // 0x808002C4: b           L_80800360
    // 0x808002C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800360;
    // 0x808002C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002CC:
    // 0x808002CC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808002D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002D4: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x808002D8: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808002DC: bnel        $t8, $at, L_80800360
    if (ctx->r24 != ctx->r1) {
        // 0x808002E0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800360;
    }
    goto skip_0;
    // 0x808002E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808002E4: jal         0x800DA298
    // 0x808002E8: addiu       $a0, $zero, 0x9E6
    ctx->r4 = ADD32(0, 0X9E6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808002E8: addiu       $a0, $zero, 0x9E6
    ctx->r4 = ADD32(0, 0X9E6);
    after_0:
    // 0x808002EC: beql        $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x808002F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800360;
    }
    goto skip_1;
    // 0x808002F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808002F4: jal         0x800DA298
    // 0x808002F8: addiu       $a0, $zero, 0x9E7
    ctx->r4 = ADD32(0, 0X9E7);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808002F8: addiu       $a0, $zero, 0x9E7
    ctx->r4 = ADD32(0, 0X9E7);
    after_1:
    // 0x808002FC: beq         $v0, $zero, L_8080035C
    if (ctx->r2 == 0) {
        // 0x80800300: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080035C;
    }
    // 0x80800300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800304: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80800308: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080030C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800310: jal         0x80101FDC
    // 0x80800314: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800314: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x80800318: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800324: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800328: jal         0x80085708
    // 0x8080032C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x8080032C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x80800330: b           L_80800360
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800360;
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800338:
    // 0x80800338: jal         0x80085710
    // 0x8080033C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x8080033C: nop

    after_4:
    // 0x80800340: addiu       $a0, $zero, 0xE1
    ctx->r4 = ADD32(0, 0XE1);
    // 0x80800344: jal         0x800887D8
    // 0x80800348: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800348: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_5:
    // 0x8080034C: b           L_80800360
    // 0x80800350: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800360;
    // 0x80800350: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80800354: b           L_80800360
    // 0x80800358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800360;
    // 0x80800358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080035C:
    // 0x8080035C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800360:
    // 0x80800360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800368: jr          $ra
    // 0x8080036C: nop

    return;
    // 0x8080036C: nop

;}
