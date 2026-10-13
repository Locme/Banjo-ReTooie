#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080041C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080041C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800420: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800424: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800428: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080042C: jal         0x808026F8
    // 0x80800430: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_808026F8_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80800430: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800438: jal         0x80100094
    // 0x8080043C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080043C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800440: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: jal         0x80102424
    // 0x8080044C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x8080044C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800450: jal         0x801022E4
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_3;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800458: addiu       $at, $zero, 0x429
    ctx->r1 = ADD32(0, 0X429);
    // 0x8080045C: beq         $v0, $at, L_80800484
    if (ctx->r2 == ctx->r1) {
        // 0x80800460: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800484;
    }
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800464: addiu       $at, $zero, 0x42B
    ctx->r1 = ADD32(0, 0X42B);
    // 0x80800468: beq         $v0, $at, L_808004A8
    if (ctx->r2 == ctx->r1) {
        // 0x8080046C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808004A8;
    }
    // 0x8080046C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800470: addiu       $at, $zero, 0x42D
    ctx->r1 = ADD32(0, 0X42D);
    // 0x80800474: beq         $v0, $at, L_808004D8
    if (ctx->r2 == ctx->r1) {
        // 0x80800478: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_808004D8;
    }
    // 0x80800478: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8080047C: b           L_808004E0
    // 0x80800480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004E0;
    // 0x80800480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800484:
    // 0x80800484: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800488: jal         0x808008C0
    // 0x8080048C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x8080048C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800498: jal         0x808008C0
    // 0x8080049C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x8080049C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x808004A0: b           L_808004E0
    // 0x808004A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004E0;
    // 0x808004A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004A8:
    // 0x808004A8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808004B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808004B8: jal         0x808008C0
    // 0x808004BC: sh          $t6, 0x80($t7)
    MEM_H(0X80, ctx->r15) = ctx->r14;
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x808004BC: sh          $t6, 0x80($t7)
    MEM_H(0X80, ctx->r15) = ctx->r14;
    after_6:
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004C8: jal         0x808008C0
    // 0x808004CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x808004CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x808004D0: b           L_808004E0
    // 0x808004D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004E0;
    // 0x808004D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004D8:
    // 0x808004D8: sh          $zero, 0x80($t8)
    MEM_H(0X80, ctx->r24) = 0;
    // 0x808004DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004E0:
    // 0x808004E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004E8: jr          $ra
    // 0x808004EC: nop

    return;
    // 0x808004EC: nop

;}
RECOMP_FUNC void func_808002D0_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808002D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808002DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002E0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x808002E4: jal         0x8009C128
    // 0x808002E8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808002E8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x808002EC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808002F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002F4: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002FC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800300: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800304: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800308: jal         0x8009FBB0
    // 0x8080030C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    func_8009FBB0(rdram, ctx);
        goto after_1;
    // 0x8080030C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800310: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80800314: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80800318: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8080031C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800320: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80800324: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800328: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080032C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800330: addiu       $a1, $zero, -0x1E
    ctx->r5 = ADD32(0, -0X1E);
    // 0x80800334: addiu       $a2, $zero, -0x1E
    ctx->r6 = ADD32(0, -0X1E);
    // 0x80800338: jal         0x800BA930
    // 0x8080033C: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    func_800BA930(rdram, ctx);
        goto after_2;
    // 0x8080033C: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    after_2:
    // 0x80800340: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800344: jal         0x800BA22C
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080034C: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800350: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800354: nop

    // 0x80800358: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8080035C: nop

    // 0x80800360: bc1f        L_808003A4
    if (!c1cs) {
        // 0x80800364: nop
    
            goto L_808003A4;
    }
    // 0x80800364: nop

    // 0x80800368: jal         0x800F2100
    // 0x8080036C: nop

    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x8080036C: nop

    after_4:
    // 0x80800370: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(408, 0X9A0) << 16);
    // 0x80800374: lwc1        $f16, 0x9A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(408, 0X9A0));
    // 0x80800378: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080037C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800380: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800384: jal         0x800F0E00
    // 0x80800388: nop

    func_800F0E00(rdram, ctx);
        goto after_5;
    // 0x80800388: nop

    after_5:
    // 0x8080038C: lwc1        $f18, 0x16C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80800398: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    // 0x8080039C: jal         0x8009BA58
    // 0x808003A0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x808003A0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_6:
L_808003A4:
    // 0x808003A4: jal         0x8008E078
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_7;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808003AC: beq         $v0, $zero, L_808003B8
    if (ctx->r2 == 0) {
        // 0x808003B0: addiu       $t9, $zero, 0x10F
        ctx->r25 = ADD32(0, 0X10F);
            goto L_808003B8;
    }
    // 0x808003B0: addiu       $t9, $zero, 0x10F
    ctx->r25 = ADD32(0, 0X10F);
    // 0x808003B4: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_808003B8:
    // 0x808003B8: jal         0x8008E35C
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_8;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808003C0: bne         $v0, $zero, L_808003CC
    if (ctx->r2 != 0) {
        // 0x808003C4: addiu       $t0, $zero, 0x10C
        ctx->r8 = ADD32(0, 0X10C);
            goto L_808003CC;
    }
    // 0x808003C4: addiu       $t0, $zero, 0x10C
    ctx->r8 = ADD32(0, 0X10C);
    // 0x808003C8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_808003CC:
    // 0x808003CC: jal         0x8009BB50
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_9;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808003D8: addiu       $t1, $zero, 0x10F
    ctx->r9 = ADD32(0, 0X10F);
    // 0x808003DC: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x808003E0: nop

    // 0x808003E4: bc1f        L_808003F0
    if (!c1cs) {
        // 0x808003E8: nop
    
            goto L_808003F0;
    }
    // 0x808003E8: nop

    // 0x808003EC: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_808003F0:
    // 0x808003F0: jal         0x80083F70
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bstnt_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x8009E5C8
    // 0x80800400: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x80800400: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x80800404: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800408: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080040C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800410: jr          $ra
    // 0x80800414: nop

    return;
    // 0x80800414: nop

;}
RECOMP_FUNC void func_8009B7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B7C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B7C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B7C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009B7CC: jal         0x8009B9B0
    // 0x8009B7D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_0;
    // 0x8009B7D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x8009B7D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009B7D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009B7DC: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B7E0: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
    // 0x8009B7E4: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B7E8: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8009B7EC: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x8009B7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B7F8: jr          $ra
    // 0x8009B7FC: nop

    return;
    // 0x8009B7FC: nop

;}
RECOMP_FUNC void func_8001DEE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DEE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001DEEC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001DEF0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001DEF4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001DEF8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001DEFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001DF00: jal         0x80016928
    // 0x8001DF04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80016928(rdram, ctx);
        goto after_0;
    // 0x8001DF04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8001DF08: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8001DF0C: addiu       $s2, $s2, -0x2488
    ctx->r18 = ADD32(ctx->r18, -0X2488);
    // 0x8001DF10: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x8001DF14: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8001DF18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8001DF1C: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x8001DF20: addiu       $s3, $s3, -0x2768
    ctx->r19 = ADD32(ctx->r19, -0X2768);
    // 0x8001DF24: addiu       $s4, $s4, -0x2490
    ctx->r20 = ADD32(ctx->r20, -0X2490);
    // 0x8001DF28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8001DF2C:
    // 0x8001DF2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001DF30: jal         0x8002E1F0
    // 0x8001DF34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8001DF34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8001DF38: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x8001DF3C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8001DF40: lh          $s1, 0x0($s4)
    ctx->r17 = MEM_H(ctx->r20, 0X0);
    // 0x8001DF44: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001DF48: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
    // 0x8001DF4C: lh          $t8, -0x248E($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X248E);
    // 0x8001DF50: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001DF54: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8001DF58: sh          $t8, -0x2490($at)
    MEM_H(-0X2490, ctx->r1) = ctx->r24;
    // 0x8001DF5C: lh          $t9, -0x248C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X248C);
    // 0x8001DF60: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001DF64: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8001DF68: sh          $t9, -0x248E($at)
    MEM_H(-0X248E, ctx->r1) = ctx->r25;
    // 0x8001DF6C: lh          $t0, -0x248A($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X248A);
    // 0x8001DF70: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8001DF74: sh          $t0, -0x248C($at)
    MEM_H(-0X248C, ctx->r1) = ctx->r8;
    // 0x8001DF78: lh          $t1, -0x2488($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X2488);
    // 0x8001DF7C: jal         0x80016934
    // 0x8001DF80: sh          $t1, -0x248A($at)
    MEM_H(-0X248A, ctx->r1) = ctx->r9;
    func_80016934(rdram, ctx);
        goto after_2;
    // 0x8001DF80: sh          $t1, -0x248A($at)
    MEM_H(-0X248A, ctx->r1) = ctx->r9;
    after_2:
    // 0x8001DF84: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8001DF88: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001DF8C: jal         0x8001B798
    // 0x8001DF90: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_8001B798(rdram, ctx);
        goto after_3;
    // 0x8001DF90: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_3:
    // 0x8001DF94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001DF98: jal         0x8001E048
    // 0x8001DF9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    cic_send_challenge(rdram, ctx);
        goto after_4;
    // 0x8001DF9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8001DFA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001DFA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001DFA8: jal         0x8002E1F0
    // 0x8001DFAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8001DFAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8001DFB0: jal         0x8001E11C
    // 0x8001DFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    cic_read_response(rdram, ctx);
        goto after_6;
    // 0x8001DFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8001DFB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001DFBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001DFC0: jal         0x8002E1F0
    // 0x8001DFC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x8001DFC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x8001DFC8: jal         0x80016934
    // 0x8001DFCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80016934(rdram, ctx);
        goto after_8;
    // 0x8001DFCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x8001DFD0: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8001DFD4: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001DFD8: jal         0x8001B798
    // 0x8001DFDC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_8001B798(rdram, ctx);
        goto after_9;
    // 0x8001DFDC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_9:
    // 0x8001DFE0: jal         0x8001E170
    // 0x8001DFE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001E170(rdram, ctx);
        goto after_10;
    // 0x8001DFE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x8001DFE8: b           L_8001DF2C
    // 0x8001DFEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_8001DF2C;
    // 0x8001DFEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001DFF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DFF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DFF8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DFFC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001E000: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001E004: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001E008: jr          $ra
    // 0x8001E00C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001E00C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void chsquits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1456, 0X6D8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x6D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6D8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x6D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6D8));
;}
RECOMP_FUNC void func_808023F8_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808023F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808023FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802400: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802404: lhu         $t6, 0x64($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X64);
    // 0x80802408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080240C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80802410: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80802414: beql        $t7, $zero, L_8080246C
    if (ctx->r15 == 0) {
        // 0x80802418: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080246C;
    }
    goto skip_0;
    // 0x80802418: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080241C: jal         0x800EE7F8
    // 0x80802420: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80802420: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80802424: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80802428: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4534) << 16);
    // 0x8080242C: lwc1        $f4, 0x4534($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4534));
    // 0x80802430: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x80802434: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80802438: lui         $a2, 0x453B
    ctx->r6 = S32(0X453B << 16);
    // 0x8080243C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80802440: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80802444: jal         0x800F10B4
    // 0x80802448: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80802448: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8080244C: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80802450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802454: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80802458: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080245C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80802460: jal         0x80085770
    // 0x80802464: nop

    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80802464: nop

    after_2:
    // 0x80802468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080246C:
    // 0x8080246C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802470: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802474: jr          $ra
    // 0x80802478: nop

    return;
    // 0x80802478: nop

;}
RECOMP_FUNC void func_80801970_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801978: jal         0x80800448
    // 0x8080197C: nop

    bstrexsmall_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080197C: nop

    after_0:
    // 0x80801980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801984: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801988: jr          $ra
    // 0x8080198C: nop

    return;
    // 0x8080198C: nop

;}
RECOMP_FUNC void func_80800064_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800068: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800074: jal         0x8009EF1C
    // 0x80800078: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800078: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080007C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800080: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: beq         $t6, $zero, L_808000B8
    if (ctx->r14 == 0) {
        // 0x8080008C: nop
    
            goto L_808000B8;
    }
    // 0x8080008C: nop

    // 0x80800090: jal         0x800919F4
    // 0x80800094: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_held(rdram, ctx);
        goto after_1;
    // 0x80800094: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x80800098: beq         $v0, $zero, L_808000B8
    if (ctx->r2 == 0) {
        // 0x8080009C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000B8;
    }
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: jal         0x8009B9B0
    // 0x808000A4: lui         $a1, 0x44AF
    ctx->r5 = S32(0X44AF << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808000A4: lui         $a1, 0x44AF
    ctx->r5 = S32(0X44AF << 16);
    after_2:
    // 0x808000A8: jal         0x80085110
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basnowball_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000B0: b           L_808000FC
    // 0x808000B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000FC;
    // 0x808000B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000B8:
    // 0x808000B8: jal         0x8009EF10
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_4;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000C0: bne         $v0, $zero, L_808000DC
    if (ctx->r2 != 0) {
        // 0x808000C4: lwc1        $f12, 0x24($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
            goto L_808000DC;
    }
    // 0x808000C4: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x8009B9B0
    // 0x808000D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x808000D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x808000D4: b           L_808000FC
    // 0x808000D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000FC;
    // 0x808000D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000DC:
    // 0x808000DC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808000E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000E4: jal         0x800F1214
    // 0x808000E8: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    func_800F1214(rdram, ctx);
        goto after_6;
    // 0x808000E8: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    after_6:
    // 0x808000EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000F0: jal         0x8009B9B0
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000FC:
    // 0x808000FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800100: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_800D7050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7050: beq         $a1, $zero, L_800D7094
    if (ctx->r5 == 0) {
        // 0x800D7054: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800D7094;
    }
    // 0x800D7054: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D7058: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D705C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800D7060: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D7064: addiu       $t7, $t7, -0x4800
    ctx->r15 = ADD32(ctx->r15, -0X4800);
    // 0x800D7068: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D706C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800D7070: lhu         $t8, 0xA($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XA);
    // 0x800D7074: lbu         $t3, 0xA($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0XA);
    // 0x800D7078: srl         $t9, $t8, 12
    ctx->r25 = S32(U32(ctx->r24) >> 12);
    // 0x800D707C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800D7080: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x800D7084: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x800D7088: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800D708C: jr          $ra
    // 0x800D7090: sb          $t5, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r13;
    return;
    // 0x800D7090: sb          $t5, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r13;
L_800D7094:
    // 0x800D7094: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800D7098: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D709C: addiu       $t7, $t7, -0x4800
    ctx->r15 = ADD32(ctx->r15, -0X4800);
    // 0x800D70A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D70A4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800D70A8: lhu         $t8, 0xA($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XA);
    // 0x800D70AC: lbu         $t2, 0xA($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XA);
    // 0x800D70B0: srl         $t9, $t8, 12
    ctx->r25 = S32(U32(ctx->r24) >> 12);
    // 0x800D70B4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800D70B8: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x800D70BC: andi        $t4, $t2, 0xFF0F
    ctx->r12 = ctx->r10 & 0XFF0F;
    // 0x800D70C0: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800D70C4: sb          $t5, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r13;
    // 0x800D70C8: jr          $ra
    // 0x800D70CC: nop

    return;
    // 0x800D70CC: nop

;}
RECOMP_FUNC void func_80106DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106DF8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80106DFC: jal         0x800B3268
    // 0x80106E00: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    freelist_new(rdram, ctx);
        goto after_0;
    // 0x80106E00: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80106E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106E08: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106E0C: sw          $v0, 0x6F00($at)
    MEM_W(0X6F00, ctx->r1) = ctx->r2;
    // 0x80106E10: jr          $ra
    // 0x80106E14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106E14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800634_chlensflare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800638: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080063C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800640: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800644: bne         $a1, $at, L_80800664
    if (ctx->r5 != ctx->r1) {
        // 0x80800648: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800664;
    }
    // 0x80800648: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080064C: jal         0x800E8714
    // 0x80800650: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E8714(rdram, ctx);
        goto after_0;
    // 0x80800650: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800654: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800658: sb          $v0, 0x50($t6)
    MEM_B(0X50, ctx->r14) = ctx->r2;
    // 0x8080065C: b           L_80800668
    // 0x80800660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800668;
    // 0x80800660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800664:
    // 0x80800664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800668:
    // 0x80800668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080066C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800670: jr          $ra
    // 0x80800674: nop

    return;
    // 0x80800674: nop

;}
RECOMP_FUNC void func_800C0FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0FD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C0FDC: addiu       $v1, $v1, -0x7500
    ctx->r3 = ADD32(ctx->r3, -0X7500);
    // 0x800C0FE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C0FE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C0FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0FEC: bne         $v0, $zero, L_800C100C
    if (ctx->r2 != 0) {
        // 0x800C0FF0: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800C100C;
    }
    // 0x800C0FF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C0FF4: jal         0x800D6E54
    // 0x800C0FF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800D6E54(rdram, ctx);
        goto after_0;
    // 0x800C0FF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x800C0FFC: jal         0x800FFD10
    // 0x800C1000: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FFD10(rdram, ctx);
        goto after_1;
    // 0x800C1000: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x800C1004: b           L_800C1014
    // 0x800C1008: nop

        goto L_800C1014;
    // 0x800C1008: nop

L_800C100C:
    // 0x800C100C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800C1010: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800C1014:
    // 0x800C1014: jal         0x80014F00
    // 0x800C1018: nop

    func_80014F00(rdram, ctx);
        goto after_2;
    // 0x800C1018: nop

    after_2:
    // 0x800C101C: jal         0x8001A0A8
    // 0x800C1020: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8001A0A8(rdram, ctx);
        goto after_3;
    // 0x800C1020: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_3:
    // 0x800C1024: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C1028: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800C102C: jal         0x800C0BC0
    // 0x800C1030: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800C0BC0(rdram, ctx);
        goto after_4;
    // 0x800C1030: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x800C1034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C103C: jr          $ra
    // 0x800C1040: nop

    return;
    // 0x800C1040: nop

;}
RECOMP_FUNC void func_8001E7B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E7B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E7B8: jr          $ra
    // 0x8001E7BC: sh          $a0, -0x2480($at)
    MEM_H(-0X2480, ctx->r1) = ctx->r4;
    return;
    // 0x8001E7BC: sh          $a0, -0x2480($at)
    MEM_H(-0X2480, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void suspline_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D10: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800D14: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80800D18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800D1C: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80800D20: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800D24: multu       $a0, $t8
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800D28: mflo        $v0
    ctx->r2 = lo;
    // 0x80800D2C: addiu       $v0, $v0, 0x8C
    ctx->r2 = ADD32(ctx->r2, 0X8C);
    // 0x80800D30: jr          $ra
    // 0x80800D34: nop

    return;
    // 0x80800D34: nop

;}
RECOMP_FUNC void func_800B8CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8CF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8CF4: jr          $ra
    // 0x800B8CF8: swc1        $f12, -0x7D2C($at)
    MEM_W(-0X7D2C, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800B8CF8: swc1        $f12, -0x7D2C($at)
    MEM_W(-0X7D2C, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void bsstonehead_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801190: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801194: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(376, 0X1690) << 16);
    // 0x80801198: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080119C: jr          $ra
    // 0x808011A0: lw          $v0, 0x1690($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1690));
    return;
    // 0x808011A0: lw          $v0, 0x1690($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1690));
;}
RECOMP_FUNC void func_808010D4_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808010D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808010DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808010E0: jal         0x808001FC
    // 0x808010E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001FC_bsstatue(rdram, ctx);
        goto after_0;
    // 0x808010E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808010E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010EC: addiu       $a1, $zero, 0x1EE
    ctx->r5 = ADD32(0, 0X1EE);
    // 0x808010F0: jal         0x8008CB3C
    // 0x808010F4: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808010F4: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_1:
    // 0x808010F8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808010FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801108: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080110C: jal         0x8009FFD8
    // 0x80801110: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801110: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801118: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x8080111C: jal         0x8009C99C
    // 0x80801120: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80801120: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_3:
    // 0x80801124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801128: jal         0x8009B9B0
    // 0x8080112C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x8080112C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80801130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801134: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801138: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080113C: jr          $ra
    // 0x80801140: nop

    return;
    // 0x80801140: nop

;}
RECOMP_FUNC void _ncba1p_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089400: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x80089400);
    return;
    // 0x80089404: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bskazflamethrower_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083350: syscall     56
    recomp_syscall_handler(rdram, ctx, 0x80083350);
    return;
    // 0x80083354: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F2388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2388: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F238C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800F2390: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F2394: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800F2398: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F239C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F23A0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800F23A4: jr          $ra
    // 0x800F23A8: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800F23A8: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_8080003C_ncbafixpos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: jal         0x80110840
    // 0x80800048: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x80800048: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080004C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800050: jal         0x800F5628
    // 0x80800054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5628(rdram, ctx);
        goto after_1;
    // 0x80800054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800058: jal         0x800F71D4
    // 0x8080005C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F71D4(rdram, ctx);
        goto after_2;
    // 0x8080005C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800060: beq         $v0, $zero, L_80800078
    if (ctx->r2 == 0) {
        // 0x80800064: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800078;
    }
    // 0x80800064: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800068: jal         0x800F5E7C
    // 0x8080006C: nop

    func_800F5E7C(rdram, ctx);
        goto after_3;
    // 0x8080006C: nop

    after_3:
    // 0x80800070: b           L_80800084
    // 0x80800074: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800084;
    // 0x80800074: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800078:
    // 0x80800078: jal         0x800F5628
    // 0x8080007C: nop

    func_800F5628(rdram, ctx);
        goto after_4;
    // 0x8080007C: nop

    after_4:
    // 0x80800080: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800084:
    // 0x80800084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800088: jal         0x80115460
    // 0x8080008C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_80115460(rdram, ctx);
        goto after_5;
    // 0x8080008C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800094: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800098: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080009C: jr          $ra
    // 0x808000A0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    return;
    // 0x808000A0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
;}
RECOMP_FUNC void func_80800540_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800548: jal         0x800EA05C
    // 0x8080054C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080054C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800550: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x80800554: beq         $v0, $at, L_8080056C
    if (ctx->r2 == ctx->r1) {
        // 0x80800558: addiu       $at, $zero, 0x12D
        ctx->r1 = ADD32(0, 0X12D);
            goto L_8080056C;
    }
    // 0x80800558: addiu       $at, $zero, 0x12D
    ctx->r1 = ADD32(0, 0X12D);
    // 0x8080055C: beq         $v0, $at, L_8080057C
    if (ctx->r2 == ctx->r1) {
        // 0x80800560: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_8080057C;
    }
    // 0x80800560: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800564: b           L_80800590
    // 0x80800568: lhu         $v0, 0x76($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X76);
        goto L_80800590;
    // 0x80800568: lhu         $v0, 0x76($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X76);
L_8080056C:
    // 0x8080056C: jal         0x80800328
    // 0x80800570: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800328_chfriendlystonehead(rdram, ctx);
        goto after_1;
    // 0x80800570: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800574: b           L_80800670
    // 0x80800578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800670;
    // 0x80800578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080057C:
    // 0x8080057C: jal         0x80800444
    // 0x80800580: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800444_chfriendlystonehead(rdram, ctx);
        goto after_2;
    // 0x80800580: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800584: b           L_80800670
    // 0x80800588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800670;
    // 0x80800588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080058C: lhu         $v0, 0x76($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X76);
L_80800590:
    // 0x80800590: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1876, 0X908) << 16);
    // 0x80800594: addiu       $t9, $t9, 0x908
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1876, 0X908));
    // 0x80800598: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x8080059C: addiu       $v0, $t7, -0x1
    ctx->r2 = ADD32(ctx->r15, -0X1);
    // 0x808005A0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x808005A4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x808005A8: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x808005AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005B0: jal         0x800F54E4
    // 0x808005B4: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808005B4: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    after_3:
    // 0x808005B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005BC: jal         0x800F64A4
    // 0x808005C0: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    func_800F64A4(rdram, ctx);
        goto after_4;
    // 0x808005C0: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_4:
    // 0x808005C4: beq         $v0, $zero, L_808005D8
    if (ctx->r2 == 0) {
        // 0x808005C8: lhu         $v1, 0x26($sp)
        ctx->r3 = MEM_HU(ctx->r29, 0X26);
            goto L_808005D8;
    }
    // 0x808005C8: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x808005CC: addiu       $t0, $zero, 0xF5A
    ctx->r8 = ADD32(0, 0XF5A);
    // 0x808005D0: b           L_808005E4
    // 0x808005D4: sh          $t0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r8;
        goto L_808005E4;
    // 0x808005D4: sh          $t0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r8;
L_808005D8:
    // 0x808005D8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x808005DC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x808005E0: sh          $t2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r10;
L_808005E4:
    // 0x808005E4: addiu       $at, $zero, 0xF30
    ctx->r1 = ADD32(0, 0XF30);
    // 0x808005E8: bne         $v1, $at, L_80800640
    if (ctx->r3 != ctx->r1) {
        // 0x808005EC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80800640;
    }
    // 0x808005EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808005F0: addiu       $a0, $zero, 0x32B
    ctx->r4 = ADD32(0, 0X32B);
    // 0x808005F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005F8: jal         0x800DA564
    // 0x808005FC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800DA564(rdram, ctx);
        goto after_5;
    // 0x808005FC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_5:
    // 0x80800600: bne         $v0, $zero, L_80800620
    if (ctx->r2 != 0) {
        // 0x80800604: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800620;
    }
    // 0x80800604: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800608: jal         0x800DC128
    // 0x8080060C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_6;
    // 0x8080060C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800610: addiu       $a0, $zero, 0x32B
    ctx->r4 = ADD32(0, 0X32B);
    // 0x80800614: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x80800618: jal         0x800DA7A8
    // 0x8080061C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_7;
    // 0x8080061C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
L_80800620:
    // 0x80800620: addiu       $a0, $zero, 0x32B
    ctx->r4 = ADD32(0, 0X32B);
    // 0x80800624: jal         0x800DA564
    // 0x80800628: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_8;
    // 0x80800628: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8080062C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80800630: addu        $v1, $t3, $v0
    ctx->r3 = ADD32(ctx->r11, ctx->r2);
    // 0x80800634: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80800638: andi        $t4, $v1, 0xFFFF
    ctx->r12 = ctx->r3 & 0XFFFF;
    // 0x8080063C: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_80800640:
    // 0x80800640: lhu         $t5, 0x24($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X24);
    // 0x80800644: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1876, 0X99C) << 16);
    // 0x80800648: sh          $v1, 0x99C($at)
    MEM_H((int16_t)RELOC_LO16(1876, 0X99C), ctx->r1) = ctx->r3;
    // 0x8080064C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1876, 0X9A4) << 16);
    // 0x80800650: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800654: sh          $t5, 0x9A4($at)
    MEM_H((int16_t)RELOC_LO16(1876, 0X9A4), ctx->r1) = ctx->r13;
    // 0x80800658: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1876, 0X99E) << 16);
    // 0x8080065C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1876, 0X998) << 16);
    // 0x80800660: sh          $v1, 0x99E($at)
    MEM_H((int16_t)RELOC_LO16(1876, 0X99E), ctx->r1) = ctx->r3;
    // 0x80800664: addiu       $a2, $a2, 0x998
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1876, 0X998));
    // 0x80800668: jal         0x8008A1E8
    // 0x8080066C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x8080066C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_9:
L_80800670:
    // 0x80800670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800674: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800678: jr          $ra
    // 0x8080067C: nop

    return;
    // 0x8080067C: nop

;}
RECOMP_FUNC void func_800A8168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8168: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A816C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8170: jr          $ra
    // 0x800A8174: sh          $t6, 0x7634($at)
    MEM_H(0X7634, ctx->r1) = ctx->r14;
    return;
    // 0x800A8174: sh          $t6, 0x7634($at)
    MEM_H(0X7634, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80800000_sccustom_big(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3382, 0X3F0) << 16);
    // 0x80800010: jal         0x800E73D4
    // 0x80800014: addiu       $a0, $a0, 0x3F0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3382, 0X3F0));
    func_800E73D4(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $a0, 0x3F0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3382, 0X3F0));
    after_0:
    // 0x80800018: jal         0x8008A618
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _scinfobar_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800020: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3382, 0X3F0) << 16);
    // 0x80800024: addiu       $a0, $a0, 0x3F0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3382, 0X3F0));
    // 0x80800028: jal         0x800E6DB4
    // 0x8080002C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_2;
    // 0x8080002C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3382, 0X3F0) << 16);
    // 0x80800038: addiu       $v0, $v0, 0x3F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3382, 0X3F0));
    // 0x8080003C: jr          $ra
    // 0x80800040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800F6438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6438: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F643C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800F6440: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x800F6444: lw          $a1, 0x5490($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5490);
    // 0x800F6448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F644C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6450: bne         $a1, $zero, L_800F6460
    if (ctx->r5 != 0) {
        // 0x800F6454: nop
    
            goto L_800F6460;
    }
    // 0x800F6454: nop

    // 0x800F6458: b           L_800F6468
    // 0x800F645C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F6468;
    // 0x800F645C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F6460:
    // 0x800F6460: jal         0x800F4244
    // 0x800F6464: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F4244(rdram, ctx);
        goto after_0;
    // 0x800F6464: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_800F6468:
    // 0x800F6468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F646C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6470: jr          $ra
    // 0x800F6474: nop

    return;
    // 0x800F6474: nop

;}
RECOMP_FUNC void bastick_func_8009F2A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F2A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009F2A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F2AC: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x8009F2B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009F2B4: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8009F2B8: jal         0x8009F1C8
    // 0x8009F2BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_0;
    // 0x8009F2BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8009F2C0: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x8009F2C4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8009F2C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009F2CC: jal         0x8009F1C8
    // 0x8009F2D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bastick_setZoneMax(rdram, ctx);
        goto after_1;
    // 0x8009F2D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8009F2D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009F2D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8009F2DC: jal         0x8009F1C8
    // 0x8009F2E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_2;
    // 0x8009F2E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x8009F2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F2E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009F2EC: jr          $ra
    // 0x8009F2F0: nop

    return;
    // 0x8009F2F0: nop

;}
RECOMP_FUNC void _chmonsterinterior_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086548: syscall     336
    recomp_syscall_handler(rdram, ctx, 0x80086548);
    return;
    // 0x8008654C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084078: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x80084078);
    return;
    // 0x8008407C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80029E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029E68: lbu         $t7, 0x35($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X35);
    // 0x80029E6C: lw          $t6, 0x60($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X60);
    // 0x80029E70: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80029E74: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80029E78: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80029E7C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80029E80: lbu         $t1, 0x6($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X6);
    // 0x80029E84: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80029E88: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80029E8C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80029E90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80029E94: lwc1        $f4, 0x7C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X7C);
    // 0x80029E98: lbu         $t4, 0x35($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X35);
    // 0x80029E9C: lw          $t3, 0x60($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X60);
    // 0x80029EA0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80029EA4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80029EA8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80029EAC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80029EB0: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80029EB4: lbu         $t6, 0x6($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X6);
    // 0x80029EB8: lwc1        $f4, 0x80($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X80);
    // 0x80029EBC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80029EC0: andi        $t8, $t6, 0x7F
    ctx->r24 = ctx->r14 & 0X7F;
    // 0x80029EC4: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80029EC8: nop

    // 0x80029ECC: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80029ED0: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80029ED4: nop

    // 0x80029ED8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80029EDC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80029EE0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80029EE4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80029EE8: nop

    // 0x80029EEC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80029EF0: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x80029EF4: slti        $at, $t5, 0x80
    ctx->r1 = SIGNED(ctx->r13) < 0X80 ? 1 : 0;
    // 0x80029EF8: bne         $at, $zero, L_80029F08
    if (ctx->r1 != 0) {
        // 0x80029EFC: nop
    
            goto L_80029F08;
    }
    // 0x80029EFC: nop

    // 0x80029F00: b           L_80029F0C
    // 0x80029F04: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
        goto L_80029F0C;
    // 0x80029F04: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
L_80029F08:
    // 0x80029F08: lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X10);
L_80029F0C:
    // 0x80029F0C: bgez        $a3, L_80029F1C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80029F10: nop
    
            goto L_80029F1C;
    }
    // 0x80029F10: nop

    // 0x80029F14: b           L_80029F3C
    // 0x80029F18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80029F3C;
    // 0x80029F18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80029F1C:
    // 0x80029F1C: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x80029F20: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x80029F24: bne         $at, $zero, L_80029F34
    if (ctx->r1 != 0) {
        // 0x80029F28: nop
    
            goto L_80029F34;
    }
    // 0x80029F28: nop

    // 0x80029F2C: b           L_80029F38
    // 0x80029F30: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
        goto L_80029F38;
    // 0x80029F30: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
L_80029F34:
    // 0x80029F34: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
L_80029F38:
    // 0x80029F38: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_80029F3C:
    // 0x80029F3C: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80029F40: or          $v0, $a2, $t6
    ctx->r2 = ctx->r6 | ctx->r14;
    // 0x80029F44: b           L_80029F54
    // 0x80029F48: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80029F54;
    // 0x80029F48: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80029F4C: b           L_80029F54
    // 0x80029F50: nop

        goto L_80029F54;
    // 0x80029F50: nop

L_80029F54:
    // 0x80029F54: jr          $ra
    // 0x80029F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80029F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _ncbaspline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893A8: syscall     776
    recomp_syscall_handler(rdram, ctx, 0x800893A8);
    return;
    // 0x800893AC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DCA0: jr          $ra
    // 0x8002DCA4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x8002DCA4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void func_80800654_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800654: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080065C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800660: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800664: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800668: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8080066C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800670: jal         0x8008A0E8
    // 0x80800674: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800674: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800678: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080067C: jal         0x80102424
    // 0x80800680: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800680: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800684: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800688: lbu         $t7, 0x65($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X65);
    // 0x8080068C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800690: sb          $t8, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r24;
    // 0x80800694: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800698: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8080069C: sltiu       $at, $t0, 0xD
    ctx->r1 = ctx->r8 < 0XD ? 1 : 0;
    // 0x808006A0: beq         $at, $zero, L_808007F0
    if (ctx->r1 == 0) {
        // 0x808006A4: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_808007F0;
    }
    // 0x808006A4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808006A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X141C) << 16);
    // 0x808006AC: addu        $at, $at, $t0
    gpr jr_addend_808006B4 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808006B0: lw          $t0, 0x141C($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1284, 0X141C));
    // 0x808006B4: jr          $t0
    // 0x808006B8: nop

    switch (jr_addend_808006B4 >> 2) {
        case 0: goto L_808006BC; break;
        case 1: goto L_808006BC; break;
        case 2: goto L_808006CC; break;
        case 3: goto L_808006F0; break;
        case 4: goto L_80800708; break;
        case 5: goto L_80800720; break;
        case 6: goto L_80800750; break;
        case 7: goto L_80800768; break;
        case 8: goto L_80800780; break;
        case 9: goto L_80800798; break;
        case 10: goto L_808007B0; break;
        case 11: goto L_808007C8; break;
        case 12: goto L_808007E0; break;
        default: switch_error(__func__, 0x808006B4, 0x8080141C);
    }
    // 0x808006B8: nop

L_808006BC:
    // 0x808006BC: lbu         $t1, 0x65($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X65);
    // 0x808006C0: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x808006C4: b           L_808007F0
    // 0x808006C8: sb          $t2, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r10;
        goto L_808007F0;
    // 0x808006C8: sb          $t2, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r10;
L_808006CC:
    // 0x808006CC: addiu       $a0, $zero, 0x328
    ctx->r4 = ADD32(0, 0X328);
    // 0x808006D0: jal         0x800DA544
    // 0x808006D4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x808006D4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_2:
    // 0x808006D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808006DC: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x808006E0: jal         0x80800CBC
    // 0x808006E4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800CBC_chdippy(rdram, ctx);
        goto after_3;
    // 0x808006E4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_3:
    // 0x808006E8: b           L_808007F4
    // 0x808006EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007F4;
    // 0x808006EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006F0:
    // 0x808006F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808006F4: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x808006F8: jal         0x80800CBC
    // 0x808006FC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800CBC_chdippy(rdram, ctx);
        goto after_4;
    // 0x808006FC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_4:
    // 0x80800700: b           L_808007F4
    // 0x80800704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007F4;
    // 0x80800704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800708:
    // 0x80800708: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080070C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x80800710: jal         0x80800CBC
    // 0x80800714: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800CBC_chdippy(rdram, ctx);
        goto after_5;
    // 0x80800714: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_5:
    // 0x80800718: b           L_808007F4
    // 0x8080071C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007F4;
    // 0x8080071C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800720:
    // 0x80800720: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800724: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x80800728: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x8080072C: jal         0x80800CBC
    // 0x80800730: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80800CBC_chdippy(rdram, ctx);
        goto after_6;
    // 0x80800730: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_6:
    // 0x80800734: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1284, 0X1610) << 16);
    // 0x80800738: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080073C: addiu       $a2, $a2, 0x1610
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1284, 0X1610));
    // 0x80800740: jal         0x80089D18
    // 0x80800744: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800744: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_7:
    // 0x80800748: b           L_808007F4
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007F4;
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800750:
    // 0x80800750: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800754: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x80800758: jal         0x80800CBC
    // 0x8080075C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800CBC_chdippy(rdram, ctx);
        goto after_8;
    // 0x8080075C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_8:
    // 0x80800760: b           L_808007F4
    // 0x80800764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007F4;
    // 0x80800764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800768:
    // 0x80800768: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080076C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x80800770: jal         0x80800CBC
    // 0x80800774: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800CBC_chdippy(rdram, ctx);
        goto after_9;
    // 0x80800774: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_9:
    // 0x80800778: b           L_808007F4
    // 0x8080077C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007F4;
    // 0x8080077C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800780:
    // 0x80800780: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800784: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x80800788: jal         0x80800CBC
    // 0x8080078C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800CBC_chdippy(rdram, ctx);
        goto after_10;
    // 0x8080078C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_10:
    // 0x80800790: b           L_808007F4
    // 0x80800794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007F4;
    // 0x80800794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800798:
    // 0x80800798: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080079C: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x808007A0: jal         0x80800CBC
    // 0x808007A4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800CBC_chdippy(rdram, ctx);
        goto after_11;
    // 0x808007A4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_11:
    // 0x808007A8: b           L_808007F4
    // 0x808007AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007F4;
    // 0x808007AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007B0:
    // 0x808007B0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808007B4: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x808007B8: jal         0x80800CBC
    // 0x808007BC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800CBC_chdippy(rdram, ctx);
        goto after_12;
    // 0x808007BC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_12:
    // 0x808007C0: b           L_808007F4
    // 0x808007C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007F4;
    // 0x808007C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007C8:
    // 0x808007C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808007CC: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x808007D0: jal         0x80800CBC
    // 0x808007D4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800CBC_chdippy(rdram, ctx);
        goto after_13;
    // 0x808007D4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_13:
    // 0x808007D8: b           L_808007F4
    // 0x808007DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007F4;
    // 0x808007DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007E0:
    // 0x808007E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808007E4: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x808007E8: jal         0x80800CBC
    // 0x808007EC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800CBC_chdippy(rdram, ctx);
        goto after_14;
    // 0x808007EC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_14:
L_808007F0:
    // 0x808007F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007F4:
    // 0x808007F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007F8: jr          $ra
    // 0x808007FC: nop

    return;
    // 0x808007FC: nop

;}
RECOMP_FUNC void _chfantasylakebits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087660: syscall     602
    recomp_syscall_handler(rdram, ctx, 0x80087660);
    return;
    // 0x80087664: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80803BE8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803BF0: jal         0x800AA074
    // 0x80803BF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800AA074(rdram, ctx);
        goto after_0;
    // 0x80803BF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803BF8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80803BFC: jal         0x800AA054
    // 0x80803C00: lw          $a0, 0x54($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X54);
    func_800AA054(rdram, ctx);
        goto after_1;
    // 0x80803C00: lw          $a0, 0x54($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X54);
    after_1:
    // 0x80803C04: jal         0x800AA120
    // 0x80803C08: nop

    func_800AA120(rdram, ctx);
        goto after_2;
    // 0x80803C08: nop

    after_2:
    // 0x80803C0C: lui         $v1, 0x8081
    ctx->r3 = S32(RELOC_HI16(804, 0X83A0) << 16);
    // 0x80803C10: lui         $a0, 0x8081
    ctx->r4 = S32(RELOC_HI16(804, 0X83C8) << 16);
    // 0x80803C14: addiu       $a0, $a0, -0x7C38
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(804, 0X83C8));
    // 0x80803C18: addiu       $v1, $v1, -0x7C60
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(804, 0X83A0));
    // 0x80803C1C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_80803C20:
    // 0x80803C20: bnel        $v0, $t7, L_80803C40
    if (ctx->r2 != ctx->r15) {
        // 0x80803C24: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80803C40;
    }
    goto skip_0;
    // 0x80803C24: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    skip_0:
    // 0x80803C28: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x80803C2C: jalr        $t9
    // 0x80803C30: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80803C30: nop

    after_3:
    // 0x80803C34: b           L_80803C48
    // 0x80803C38: nop

        goto L_80803C48;
    // 0x80803C38: nop

    // 0x80803C3C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80803C40:
    // 0x80803C40: bnel        $v1, $a0, L_80803C20
    if (ctx->r3 != ctx->r4) {
        // 0x80803C44: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_80803C20;
    }
    goto skip_1;
    // 0x80803C44: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_80803C48:
    // 0x80803C48: jal         0x80803B3C
    // 0x80803C4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80803B3C_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80803C4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80803C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803C54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803C58: jr          $ra
    // 0x80803C5C: nop

    return;
    // 0x80803C5C: nop

;}
RECOMP_FUNC void func_808006BC_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808006C8: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x808006CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006D4: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    // 0x808006D8: lw          $t7, 0x18C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18C);
    // 0x808006DC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x808006E0: addiu       $a1, $a1, 0x31B0
    ctx->r5 = ADD32(ctx->r5, 0X31B0);
    // 0x808006E4: swc1        $f4, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f4.u32l;
    // 0x808006E8: lw          $t8, 0x18C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18C);
    // 0x808006EC: jal         0x8008C9D8
    // 0x808006F0: swc1        $f0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f0.u32l;
    func_8008C9D8(rdram, ctx);
        goto after_0;
    // 0x808006F0: swc1        $f0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f0.u32l;
    after_0:
    // 0x808006F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006FC: jr          $ra
    // 0x80800700: nop

    return;
    // 0x80800700: nop

;}
RECOMP_FUNC void func_8010C3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C3E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C3EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C3F0: jal         0x800BECCC
    // 0x8010C3F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800BECCC(rdram, ctx);
        goto after_0;
    // 0x8010C3F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010C3F8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8010C3FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010C400: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010C404: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    // 0x8010C408: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8010C40C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8010C410: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010C414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010C418: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8010C41C: nop

    // 0x8010C420: bc1f        L_8010C450
    if (!c1cs) {
        // 0x8010C424: nop
    
            goto L_8010C450;
    }
    // 0x8010C424: nop

    // 0x8010C428: jal         0x8010108C
    // 0x8010C42C: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    func_8010108C(rdram, ctx);
        goto after_1;
    // 0x8010C42C: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    after_1:
    // 0x8010C430: blez        $v0, L_8010C440
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8010C434: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8010C440;
    }
    // 0x8010C434: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010C438: b           L_8010C450
    // 0x8010C43C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010C450;
    // 0x8010C43C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010C440:
    // 0x8010C440: jal         0x800FFAB0
    // 0x8010C444: nop

    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8010C444: nop

    after_2:
    // 0x8010C448: b           L_8010C450
    // 0x8010C44C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010C450;
    // 0x8010C44C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010C450:
    // 0x8010C450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C458: jr          $ra
    // 0x8010C45C: nop

    return;
    // 0x8010C45C: nop

;}
RECOMP_FUNC void _chfiregen_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869D8: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869D8);
    return;
    // 0x800869DC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _basudie_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085260: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085260);
    return;
    // 0x80085264: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_8080070C_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080070C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800710: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800714: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800718: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080071C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800720: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800724: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800728: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080072C: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_80800730:
    // 0x80800730: jal         0x808006A4
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006A4_chchuffycont(rdram, ctx);
        goto after_0;
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800738: beq         $v0, $zero, L_80800744
    if (ctx->r2 == 0) {
        // 0x8080073C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800744;
    }
    // 0x8080073C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800740: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800744:
    // 0x80800744: bne         $s0, $s2, L_80800730
    if (ctx->r16 != ctx->r18) {
        // 0x80800748: nop
    
            goto L_80800730;
    }
    // 0x80800748: nop

    // 0x8080074C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800750: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800754: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800758: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080075C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800760: jr          $ra
    // 0x80800764: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800764: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C368C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C368C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3694: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3698: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C369C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C36A0: beq         $t6, $zero, L_800C36E4
    if (ctx->r14 == 0) {
        // 0x800C36A4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C36E4;
    }
    // 0x800C36A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C36A8: jal         0x800C1414
    // 0x800C36AC: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C36AC: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    after_0:
    // 0x800C36B0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C36B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C36B8: beq         $t7, $zero, L_800C36D0
    if (ctx->r15 == 0) {
        // 0x800C36BC: nop
    
            goto L_800C36D0;
    }
    // 0x800C36BC: nop

    // 0x800C36C0: jal         0x800C13A0
    // 0x800C36C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C13A0(rdram, ctx);
        goto after_1;
    // 0x800C36C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x800C36C8: b           L_800C36DC
    // 0x800C36CC: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
        goto L_800C36DC;
    // 0x800C36CC: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
L_800C36D0:
    // 0x800C36D0: jal         0x800C13B0
    // 0x800C36D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C13B0(rdram, ctx);
        goto after_2;
    // 0x800C36D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x800C36D8: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
L_800C36DC:
    // 0x800C36DC: jal         0x800C33DC
    // 0x800C36E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800C33DC(rdram, ctx);
        goto after_3;
    // 0x800C36E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_800C36E4:
    // 0x800C36E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C36E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C36EC: jr          $ra
    // 0x800C36F0: nop

    return;
    // 0x800C36F0: nop

;}
RECOMP_FUNC void _badeathmatch_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085548: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x80085548);
    return;
    // 0x8008554C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void basnowball_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003E4: jal         0x80800008
    // 0x808003E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800008_basnowball(rdram, ctx);
        goto after_0;
    // 0x808003E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003EC: jal         0x8009E474
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_1;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: jal         0x80095774
    // 0x808003FC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x808003FC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_2:
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: jal         0x80093230
    // 0x80800408: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80093230(rdram, ctx);
        goto after_3;
    // 0x80800408: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x8080040C: jal         0x80095A40
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_4;
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: jal         0x8009590C
    // 0x8080041C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009590C(rdram, ctx);
        goto after_5;
    // 0x8080041C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800420: jal         0x80085450
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawobble_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800428: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080042C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800434: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800438: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080043C: jal         0x800A4D6C
    // 0x80800440: nop

    func_800A4D6C(rdram, ctx);
        goto after_7;
    // 0x80800440: nop

    after_7:
    // 0x80800444: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800448: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080044C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800450: jr          $ra
    // 0x80800454: nop

    return;
    // 0x80800454: nop

;}
RECOMP_FUNC void _bscarry_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E88: syscall     31
    recomp_syscall_handler(rdram, ctx, 0x80082E88);
    return;
    // 0x80082E8C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void gczoomboxdata_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080037C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800380: jal         0x80800310
    // 0x80800384: nop

    gczoomboxdata_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800384: nop

    after_0:
    // 0x80800388: beq         $v0, $zero, L_8080039C
    if (ctx->r2 == 0) {
        // 0x8080038C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080039C;
    }
    // 0x8080038C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800390: addiu       $at, $zero, 0xBAE
    ctx->r1 = ADD32(0, 0XBAE);
    // 0x80800394: bnel        $v0, $at, L_808003A8
    if (ctx->r2 != ctx->r1) {
        // 0x80800398: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808003A8;
    }
    goto skip_0;
    // 0x80800398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_8080039C:
    // 0x8080039C: b           L_808003A8
    // 0x808003A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003A8;
    // 0x808003A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A8:
    // 0x808003A8: jr          $ra
    // 0x808003AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808003AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800890_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800890: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800894: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800898: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x8080089C: addiu       $t9, $t8, -0x1AA
    ctx->r25 = ADD32(ctx->r24, -0X1AA);
    // 0x808008A0: sltiu       $at, $t9, 0x9
    ctx->r1 = ctx->r25 < 0X9 ? 1 : 0;
    // 0x808008A4: beq         $at, $zero, L_808008E8
    if (ctx->r1 == 0) {
        // 0x808008A8: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808008E8;
    }
    // 0x808008A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808008AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X14DC) << 16);
    // 0x808008B0: addu        $at, $at, $t9
    gpr jr_addend_808008B8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808008B4: lw          $t9, 0x14DC($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1588, 0X14DC));
    // 0x808008B8: jr          $t9
    // 0x808008BC: nop

    switch (jr_addend_808008B8 >> 2) {
        case 0: goto L_808008C0; break;
        case 1: goto L_808008E8; break;
        case 2: goto L_808008C8; break;
        case 3: goto L_808008E8; break;
        case 4: goto L_808008D0; break;
        case 5: goto L_808008E8; break;
        case 6: goto L_808008D8; break;
        case 7: goto L_808008E8; break;
        case 8: goto L_808008E0; break;
        default: switch_error(__func__, 0x808008B8, 0x808014DC);
    }
    // 0x808008BC: nop

L_808008C0:
    // 0x808008C0: jr          $ra
    // 0x808008C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808008C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008C8:
    // 0x808008C8: jr          $ra
    // 0x808008CC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x808008CC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_808008D0:
    // 0x808008D0: jr          $ra
    // 0x808008D4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x808008D4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_808008D8:
    // 0x808008D8: jr          $ra
    // 0x808008DC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x808008DC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_808008E0:
    // 0x808008E0: jr          $ra
    // 0x808008E4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    return;
    // 0x808008E4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_808008E8:
    // 0x808008E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x808008EC: jr          $ra
    // 0x808008F0: nop

    return;
    // 0x808008F0: nop

;}
RECOMP_FUNC void chnutsnbolts_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1304, 0XE28) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xE28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1304, 0XE28));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xE28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1304, 0XE28));
;}
RECOMP_FUNC void sujiggy_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808001E8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808001EC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x808001F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3354, 0X8F2) << 16);
    // 0x808001F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808001F8: jr          $ra
    // 0x808001FC: lbu         $v0, 0x8F2($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8F2));
    return;
    // 0x808001FC: lbu         $v0, 0x8F2($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8F2));
;}
RECOMP_FUNC void func_801040A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801040A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801040AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801040B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801040B4: jal         0x800AE080
    // 0x801040B8: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x801040B8: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_0:
    // 0x801040BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801040C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801040C4: jr          $ra
    // 0x801040C8: nop

    return;
    // 0x801040C8: nop

    // 0x801040CC: nop

;}
RECOMP_FUNC void func_800BF4A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF4A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BF4A8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BF4AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BF4B0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BF4B4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BF4B8: addiu       $t7, $t7, -0x7A50
    ctx->r15 = ADD32(ctx->r15, -0X7A50);
    // 0x800BF4BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BF4C0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800BF4C4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800BF4C8: beq         $t8, $zero, L_800BF4D4
    if (ctx->r24 == 0) {
        // 0x800BF4CC: nop
    
            goto L_800BF4D4;
    }
    // 0x800BF4CC: nop

    // 0x800BF4D0: sb          $a1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r5;
L_800BF4D4:
    // 0x800BF4D4: jr          $ra
    // 0x800BF4D8: nop

    return;
    // 0x800BF4D8: nop

;}
RECOMP_FUNC void func_800A4978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4978: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A497C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A4980: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4984: jal         0x800F40EC
    // 0x800A4988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F40EC(rdram, ctx);
        goto after_0;
    // 0x800A4988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800A498C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A4990: beq         $v0, $at, L_800A49A0
    if (ctx->r2 == ctx->r1) {
        // 0x800A4994: nop
    
            goto L_800A49A0;
    }
    // 0x800A4994: nop

    // 0x800A4998: b           L_800A4A00
    // 0x800A499C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A4A00;
    // 0x800A499C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A49A0:
    // 0x800A49A0: jal         0x800A3274
    // 0x800A49A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x800A49A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A49A8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800A49AC: beq         $v0, $at, L_800A49C4
    if (ctx->r2 == ctx->r1) {
        // 0x800A49B0: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_800A49C4;
    }
    // 0x800A49B0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800A49B4: beq         $v0, $at, L_800A49E4
    if (ctx->r2 == ctx->r1) {
        // 0x800A49B8: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_800A49E4;
    }
    // 0x800A49B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800A49BC: b           L_800A49E4
    // 0x800A49C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_800A49E4;
    // 0x800A49C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_800A49C4:
    // 0x800A49C4: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800A49C8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800A49CC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800A49D0: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x800A49D4: beq         $t6, $zero, L_800A49E4
    if (ctx->r14 == 0) {
        // 0x800A49D8: nop
    
            goto L_800A49E4;
    }
    // 0x800A49D8: nop

    // 0x800A49DC: b           L_800A49E4
    // 0x800A49E0: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
        goto L_800A49E4;
    // 0x800A49E0: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
L_800A49E4:
    // 0x800A49E4: jal         0x800A3F14
    // 0x800A49E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3F14(rdram, ctx);
        goto after_2;
    // 0x800A49E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A49EC: jal         0x800A4878
    // 0x800A49F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4878(rdram, ctx);
        goto after_3;
    // 0x800A49F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800A49F4: jal         0x800A4190
    // 0x800A49F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4190(rdram, ctx);
        goto after_4;
    // 0x800A49F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800A49FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A4A00:
    // 0x800A4A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A4A04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4A08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A4A0C: jr          $ra
    // 0x800A4A10: nop

    return;
    // 0x800A4A10: nop

;}
