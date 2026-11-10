#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80014ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014ED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80014ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014EDC: jal         0x80014F38
    // 0x80014EE0: nop

    func_80014F38(rdram, ctx);
        goto after_0;
    // 0x80014EE0: nop

    after_0:
    // 0x80014EE4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80014EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014EEC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014EF0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80014EF4: lw          $v0, -0x7080($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7080);
    // 0x80014EF8: jr          $ra
    // 0x80014EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80014EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void baanim_isAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CB10: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008CB14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CB18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CB1C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CB20: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8008CB24: jal         0x8008B348
    // 0x8008CB28: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    anctrl_isAt(rdram, ctx);
        goto after_0;
    // 0x8008CB28: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CB34: jr          $ra
    // 0x8008CB38: nop

    return;
    // 0x8008CB38: nop

;}
RECOMP_FUNC void bsmumswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800348: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080034C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800350: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800354: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80800358: jal         0x8009C128
    // 0x8080035C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8080035C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80800360: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800364: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800368: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800374: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800378: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x8080037C: jal         0x8009FBB0
    // 0x80800380: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    func_8009FBB0(rdram, ctx);
        goto after_1;
    // 0x80800380: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800384: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80800388: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8080038C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80800390: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800394: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80800398: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080039C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003A4: addiu       $a1, $zero, -0x1E
    ctx->r5 = ADD32(0, -0X1E);
    // 0x808003A8: addiu       $a2, $zero, -0x1E
    ctx->r6 = ADD32(0, -0X1E);
    // 0x808003AC: jal         0x800BA930
    // 0x808003B0: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    func_800BA930(rdram, ctx);
        goto after_2;
    // 0x808003B0: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    after_2:
    // 0x808003B4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808003B8: jal         0x800BA22C
    // 0x808003BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x808003BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808003C0: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808003C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808003C8: nop

    // 0x808003CC: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x808003D0: nop

    // 0x808003D4: bc1f        L_80800418
    if (!c1cs) {
        // 0x808003D8: nop
    
            goto L_80800418;
    }
    // 0x808003D8: nop

    // 0x808003DC: jal         0x800F2100
    // 0x808003E0: nop

    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x808003E0: nop

    after_4:
    // 0x808003E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(332, 0XB20) << 16);
    // 0x808003E8: lwc1        $f16, 0xB20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(332, 0XB20));
    // 0x808003EC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808003F0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003F4: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808003F8: jal         0x800F0E00
    // 0x808003FC: nop

    func_800F0E00(rdram, ctx);
        goto after_5;
    // 0x808003FC: nop

    after_5:
    // 0x80800400: lwc1        $f18, 0x16C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800408: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8080040C: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    // 0x80800410: jal         0x8009BA58
    // 0x80800414: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x80800414: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_6:
L_80800418:
    // 0x80800418: jal         0x8008E078
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_7;
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800420: beq         $v0, $zero, L_8080042C
    if (ctx->r2 == 0) {
        // 0x80800424: addiu       $t9, $zero, 0xF0
        ctx->r25 = ADD32(0, 0XF0);
            goto L_8080042C;
    }
    // 0x80800424: addiu       $t9, $zero, 0xF0
    ctx->r25 = ADD32(0, 0XF0);
    // 0x80800428: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_8080042C:
    // 0x8080042C: jal         0x8008E35C
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_8;
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800434: bne         $v0, $zero, L_80800440
    if (ctx->r2 != 0) {
        // 0x80800438: addiu       $t0, $zero, 0xE5
        ctx->r8 = ADD32(0, 0XE5);
            goto L_80800440;
    }
    // 0x80800438: addiu       $t0, $zero, 0xE5
    ctx->r8 = ADD32(0, 0XE5);
    // 0x8080043C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_80800440:
    // 0x80800440: jal         0x8009BB50
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_9;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800448: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080044C: addiu       $t1, $zero, 0xF0
    ctx->r9 = ADD32(0, 0XF0);
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80800458: nop

    // 0x8080045C: bc1f        L_80800468
    if (!c1cs) {
        // 0x80800460: nop
    
            goto L_80800468;
    }
    // 0x80800460: nop

    // 0x80800464: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_80800468:
    // 0x80800468: jal         0x8009E5C8
    // 0x8080046C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x8080046C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x80800470: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800474: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800478: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8080047C: jr          $ra
    // 0x80800480: nop

    return;
    // 0x80800480: nop

;}
RECOMP_FUNC void func_80800320_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800324: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800328: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080032C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800330: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800334: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800338: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080033C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80800340: jal         0x80100094
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800348: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8080034C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800350: slti        $at, $a2, 0x58
    ctx->r1 = SIGNED(ctx->r6) < 0X58 ? 1 : 0;
    // 0x80800354: bne         $at, $zero, L_80800370
    if (ctx->r1 != 0) {
        // 0x80800358: addiu       $t6, $a2, -0x2E
        ctx->r14 = ADD32(ctx->r6, -0X2E);
            goto L_80800370;
    }
    // 0x80800358: addiu       $t6, $a2, -0x2E
    ctx->r14 = ADD32(ctx->r6, -0X2E);
    // 0x8080035C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800360: beq         $a2, $at, L_8080048C
    if (ctx->r6 == ctx->r1) {
        // 0x80800364: nop
    
            goto L_8080048C;
    }
    // 0x80800364: nop

    // 0x80800368: b           L_808004A8
    // 0x8080036C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004A8;
    // 0x8080036C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800370:
    // 0x80800370: slti        $at, $a2, 0x3E
    ctx->r1 = SIGNED(ctx->r6) < 0X3E ? 1 : 0;
    // 0x80800374: bne         $at, $zero, L_8080038C
    if (ctx->r1 != 0) {
        // 0x80800378: addiu       $at, $zero, 0x57
        ctx->r1 = ADD32(0, 0X57);
            goto L_8080038C;
    }
    // 0x80800378: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x8080037C: beq         $a2, $at, L_80800460
    if (ctx->r6 == ctx->r1) {
        // 0x80800380: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800460;
    }
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: b           L_808004A8
    // 0x80800388: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004A8;
    // 0x80800388: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080038C:
    // 0x8080038C: sltiu       $at, $t6, 0x10
    ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
    // 0x80800390: beq         $at, $zero, L_8080049C
    if (ctx->r1 == 0) {
        // 0x80800394: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080049C;
    }
    // 0x80800394: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800398: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1016, 0X1E78) << 16);
    // 0x8080039C: addu        $at, $at, $t6
    gpr jr_addend_808003A4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808003A0: lw          $t6, 0x1E78($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1016, 0X1E78));
    // 0x808003A4: jr          $t6
    // 0x808003A8: nop

    switch (jr_addend_808003A4 >> 2) {
        case 0: goto L_808003AC; break;
        case 1: goto L_808003C8; break;
        case 2: goto L_808003E4; break;
        case 3: goto L_8080049C; break;
        case 4: goto L_80800414; break;
        case 5: goto L_8080049C; break;
        case 6: goto L_8080049C; break;
        case 7: goto L_8080049C; break;
        case 8: goto L_8080049C; break;
        case 9: goto L_8080049C; break;
        case 10: goto L_8080049C; break;
        case 11: goto L_8080049C; break;
        case 12: goto L_8080049C; break;
        case 13: goto L_8080049C; break;
        case 14: goto L_8080049C; break;
        case 15: goto L_80800400; break;
        default: switch_error(__func__, 0x808003A4, 0x80801E78);
    }
    // 0x808003A8: nop

L_808003AC:
    // 0x808003AC: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x808003B0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808003B4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808003B8: jal         0x80800910
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800910_chhoopswoop(rdram, ctx);
        goto after_1;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003C0: b           L_808004A8
    // 0x808003C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004A8;
    // 0x808003C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C8:
    // 0x808003C8: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x808003CC: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808003D0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808003D4: jal         0x80800C9C
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C9C_chhoopswoop(rdram, ctx);
        goto after_2;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808003DC: b           L_808004A8
    // 0x808003E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004A8;
    // 0x808003E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003E4:
    // 0x808003E4: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x808003E8: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808003EC: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808003F0: jal         0x80800C04
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C04_chhoopswoop(rdram, ctx);
        goto after_3;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003F8: b           L_808004AC
    // 0x808003FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004AC;
    // 0x808003FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800400:
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: jal         0x80800D28
    // 0x80800408: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800D28_chhoopswoop(rdram, ctx);
        goto after_4;
    // 0x80800408: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8080040C: b           L_808004A8
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004A8;
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800414:
    // 0x80800414: jal         0x800D395C
    // 0x80800418: nop

    func_800D395C(rdram, ctx);
        goto after_5;
    // 0x80800418: nop

    after_5:
    // 0x8080041C: beq         $v0, $zero, L_8080042C
    if (ctx->r2 == 0) {
        // 0x80800420: addiu       $a2, $zero, 0x46
        ctx->r6 = ADD32(0, 0X46);
            goto L_8080042C;
    }
    // 0x80800420: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80800424: b           L_80800430
    // 0x80800428: addiu       $a1, $zero, 0x1119
    ctx->r5 = ADD32(0, 0X1119);
        goto L_80800430;
    // 0x80800428: addiu       $a1, $zero, 0x1119
    ctx->r5 = ADD32(0, 0X1119);
L_8080042C:
    // 0x8080042C: addiu       $a1, $zero, 0x10C1
    ctx->r5 = ADD32(0, 0X10C1);
L_80800430:
    // 0x80800430: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800434: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x80800438: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080043C: jal         0x8008A208
    // 0x80800440: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800440: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80800444: jal         0x800F54E4
    // 0x80800448: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800448: nop

    after_7:
    // 0x8080044C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800450: jal         0x800F82D4
    // 0x80800454: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_8;
    // 0x80800454: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800458: b           L_808004A8
    // 0x8080045C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004A8;
    // 0x8080045C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800460:
    // 0x80800460: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800464: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800468: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8080046C: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x80800470: and         $t9, $a3, $at
    ctx->r25 = ctx->r7 & ctx->r1;
    // 0x80800474: srl         $a3, $t9, 16
    ctx->r7 = S32(U32(ctx->r25) >> 16);
    // 0x80800478: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8080047C: jal         0x8008A2B8
    // 0x80800480: addiu       $a1, $v1, 0x4C4
    ctx->r5 = ADD32(ctx->r3, 0X4C4);
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800480: addiu       $a1, $v1, 0x4C4
    ctx->r5 = ADD32(ctx->r3, 0X4C4);
    after_9:
    // 0x80800484: b           L_808004AC
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004AC;
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080048C:
    // 0x8080048C: jal         0x808004BC
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004BC_chhoopswoop(rdram, ctx);
        goto after_10;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800494: b           L_808004A8
    // 0x80800498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004A8;
    // 0x80800498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080049C:
    // 0x8080049C: b           L_808004A8
    // 0x808004A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004A8;
    // 0x808004A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808004A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004A8:
    // 0x808004A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004AC:
    // 0x808004AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004B4: jr          $ra
    // 0x808004B8: nop

    return;
    // 0x808004B8: nop

;}
RECOMP_FUNC void func_80800104_chtransparencypot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800108: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x8080010C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800110: bne         $a1, $at, L_80800130
    if (ctx->r5 != ctx->r1) {
        // 0x80800114: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800130;
    }
    // 0x80800114: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800118: lhu         $a1, 0x1A($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X1A);
    // 0x8080011C: srl         $t7, $a1, 5
    ctx->r15 = S32(U32(ctx->r5) >> 5);
    // 0x80800120: jal         0x80800148
    // 0x80800124: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_80800148_chtransparencypot(rdram, ctx);
        goto after_0;
    // 0x80800124: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_0:
    // 0x80800128: b           L_80800138
    // 0x8080012C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800138;
    // 0x8080012C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800130:
    // 0x80800130: b           L_80800138
    // 0x80800134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800138;
    // 0x80800134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800138:
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080013C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void func_801048E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801048E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801048E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801048EC: lwc1        $f0, 0x6440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6440);
    // 0x801048F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801048F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801048F8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x801048FC: lb          $t6, 0x0($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X0);
    // 0x80104900: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80104904: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80104908: nop

    // 0x8010490C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80104910: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80104914: beql        $v0, $a0, L_80104948
    if (ctx->r2 == ctx->r4) {
        // 0x80104918: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80104948;
    }
    goto skip_0;
    // 0x80104918: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x8010491C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80104920:
    // 0x80104920: lb          $t6, 0x1($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X1);
    // 0x80104924: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80104928: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8010492C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80104930: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80104934: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80104938: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8010493C: bnel        $v0, $a0, L_80104920
    if (ctx->r2 != ctx->r4) {
        // 0x80104940: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80104920;
    }
    goto skip_1;
    // 0x80104940: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_1:
    // 0x80104944: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80104948:
    // 0x80104948: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8010494C: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x80104950: jr          $ra
    // 0x80104954: nop

    return;
    // 0x80104954: nop

;}
RECOMP_FUNC void func_800D22E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D22E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D22E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D22E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D22EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D22F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D22F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D22F8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800D22FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D2300: jal         0x800D21F0
    // 0x800D2304: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    func_800D21F0(rdram, ctx);
        goto after_0;
    // 0x800D2304: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    after_0:
    // 0x800D2308: bgez        $v0, L_800D231C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D230C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D231C;
    }
    // 0x800D230C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D2310: jal         0x800D225C
    // 0x800D2314: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    func_800D225C(rdram, ctx);
        goto after_1;
    // 0x800D2314: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    after_1:
    // 0x800D2318: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D231C:
    // 0x800D231C: bgez        $v0, L_800D2330
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D2320: nop
    
            goto L_800D2330;
    }
    // 0x800D2320: nop

    // 0x800D2324: jal         0x800D22C8
    // 0x800D2328: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    func_800D22C8(rdram, ctx);
        goto after_2;
    // 0x800D2328: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    after_2:
    // 0x800D232C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D2330:
    // 0x800D2330: bltzl       $v0, L_800D2384
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D2334: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D2384;
    }
    goto skip_0;
    // 0x800D2334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800D2338: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800D233C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D2340: lbu         $a2, 0x1($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X1);
    // 0x800D2344: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800D2348: lbu         $a3, 0x2($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X2);
    // 0x800D234C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800D2350: jal         0x800FA708
    // 0x800D2354: nop

    func_800FA708(rdram, ctx);
        goto after_3;
    // 0x800D2354: nop

    after_3:
    // 0x800D2358: beq         $v0, $zero, L_800D2380
    if (ctx->r2 == 0) {
        // 0x800D235C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_800D2380;
    }
    // 0x800D235C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800D2360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2364: jal         0x800FA9B4
    // 0x800D2368: lh          $a1, 0x6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X6);
    func_800FA9B4(rdram, ctx);
        goto after_4;
    // 0x800D2368: lh          $a1, 0x6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X6);
    after_4:
    // 0x800D236C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800D2370: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x800D2374: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D2378: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800D237C: sh          $t7, -0x4D40($at)
    MEM_H(-0X4D40, ctx->r1) = ctx->r15;
L_800D2380:
    // 0x800D2380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D2384:
    // 0x800D2384: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800D2388: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D238C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D2390: jr          $ra
    // 0x800D2394: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D2394: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800974_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800974: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080097C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800980: jal         0x8009C128
    // 0x80800984: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800984: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800988: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080098C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800990: lw          $a1, 0x188($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X188);
    // 0x80800994: jal         0x800EF04C
    // 0x80800998: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x80800998: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_1:
    // 0x8080099C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009A0: jal         0x800A34AC
    // 0x808009A4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800A34AC(rdram, ctx);
        goto after_2;
    // 0x808009A4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x808009A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009AC: addiu       $a1, $zero, 0x40D
    ctx->r5 = ADD32(0, 0X40D);
    // 0x808009B0: jal         0x8009DF58
    // 0x808009B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DF58(rdram, ctx);
        goto after_3;
    // 0x808009B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x808009B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009C0: jr          $ra
    // 0x808009C4: nop

    return;
    // 0x808009C4: nop

;}
RECOMP_FUNC void func_80801B9C_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801BA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801BA4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80801BA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801BAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801BB0: beq         $a1, $at, L_80801C80
    if (ctx->r5 == ctx->r1) {
        // 0x80801BB4: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80801C80;
    }
    // 0x80801BB4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801BB8: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80801BBC: beq         $a1, $at, L_80801BE0
    if (ctx->r5 == ctx->r1) {
        // 0x80801BC0: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80801BE0;
    }
    // 0x80801BC0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801BC4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80801BC8: beq         $a1, $at, L_80801BF4
    if (ctx->r5 == ctx->r1) {
        // 0x80801BCC: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_80801BF4;
    }
    // 0x80801BCC: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x80801BD0: beql        $a1, $at, L_80801C40
    if (ctx->r5 == ctx->r1) {
        // 0x80801BD4: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80801C40;
    }
    goto skip_0;
    // 0x80801BD4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80801BD8: b           L_80801CD0
    // 0x80801BDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801CD0;
    // 0x80801BDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801BE0:
    // 0x80801BE0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(776, 0X207C) << 16);
    // 0x80801BE4: jal         0x800C4AF0
    // 0x80801BE8: addiu       $a1, $a1, 0x207C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(776, 0X207C));
    func_800C4AF0(rdram, ctx);
        goto after_0;
    // 0x80801BE8: addiu       $a1, $a1, 0x207C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(776, 0X207C));
    after_0:
    // 0x80801BEC: b           L_80801CD0
    // 0x80801BF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801CD0;
    // 0x80801BF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801BF4:
    // 0x80801BF4: jal         0x8008A0B0
    // 0x80801BF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _subaddiemulti_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80801BF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80801BFC: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80801C00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801C04: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801C08: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80801C0C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80801C10: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80801C14: jal         0x80086468
    // 0x80801C18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _chscorepoints_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80801C18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801C1C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801C20: jal         0x80801260
    // 0x80801C24: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80801260_chwaspnestgame(rdram, ctx);
        goto after_3;
    // 0x80801C24: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80801C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C2C: jal         0x80801364
    // 0x80801C30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801364_chwaspnestgame(rdram, ctx);
        goto after_4;
    // 0x80801C30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80801C34: b           L_80801CD0
    // 0x80801C38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801CD0;
    // 0x80801C38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801C3C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80801C40:
    // 0x80801C40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C48: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80801C4C: bne         $t7, $at, L_80801C64
    if (ctx->r15 != ctx->r1) {
        // 0x80801C50: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80801C64;
    }
    // 0x80801C50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80801C54: jal         0x80801364
    // 0x80801C58: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801364_chwaspnestgame(rdram, ctx);
        goto after_5;
    // 0x80801C58: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80801C5C: b           L_80801CD0
    // 0x80801C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801CD0;
    // 0x80801C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C64:
    // 0x80801C64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801C68: bne         $v0, $at, L_80801CCC
    if (ctx->r2 != ctx->r1) {
        // 0x80801C6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CCC;
    }
    // 0x80801C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C70: jal         0x80801364
    // 0x80801C74: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80801364_chwaspnestgame(rdram, ctx);
        goto after_6;
    // 0x80801C74: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_6:
    // 0x80801C78: b           L_80801CD0
    // 0x80801C7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801CD0;
    // 0x80801C7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C80:
    // 0x80801C80: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801C84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C8C: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x80801C90: beq         $t8, $at, L_80801CA4
    if (ctx->r24 == ctx->r1) {
        // 0x80801C94: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_80801CA4;
    }
    // 0x80801C94: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80801C98: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801C9C: bne         $t8, $at, L_80801CB4
    if (ctx->r24 != ctx->r1) {
        // 0x80801CA0: nop
    
            goto L_80801CB4;
    }
    // 0x80801CA0: nop

L_80801CA4:
    // 0x80801CA4: jal         0x8010DD20
    // 0x80801CA8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_8010DD20(rdram, ctx);
        goto after_7;
    // 0x80801CA8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x80801CAC: b           L_80801CD0
    // 0x80801CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801CD0;
    // 0x80801CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801CB4:
    // 0x80801CB4: jal         0x801015D0
    // 0x80801CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_8;
    // 0x80801CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801CBC: b           L_80801CD0
    // 0x80801CC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801CD0;
    // 0x80801CC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801CC4: b           L_80801CD0
    // 0x80801CC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801CD0;
    // 0x80801CC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801CCC:
    // 0x80801CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801CD0:
    // 0x80801CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801CD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801CDC: jr          $ra
    // 0x80801CE0: nop

    return;
    // 0x80801CE0: nop

;}
RECOMP_FUNC void func_800CA668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA668: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA66C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA670: jal         0x800EE7F8
    // 0x800CA674: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800CA674: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x800CA678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA67C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA680: jr          $ra
    // 0x800CA684: nop

    return;
    // 0x800CA684: nop

;}
RECOMP_FUNC void func_80800748_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800748: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080074C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800750: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800754: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800758: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080075C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800760: jal         0x80100094
    // 0x80800764: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800764: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800768: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080076C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800770: slti        $at, $a3, 0x1347
    ctx->r1 = SIGNED(ctx->r7) < 0X1347 ? 1 : 0;
    // 0x80800774: bne         $at, $zero, L_808007B0
    if (ctx->r1 != 0) {
        // 0x80800778: addiu       $at, $zero, 0x1347
        ctx->r1 = ADD32(0, 0X1347);
            goto L_808007B0;
    }
    // 0x80800778: addiu       $at, $zero, 0x1347
    ctx->r1 = ADD32(0, 0X1347);
    // 0x8080077C: beq         $a3, $at, L_808009C0
    if (ctx->r7 == ctx->r1) {
        // 0x80800780: lw          $t5, 0x28($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X28);
            goto L_808009C0;
    }
    // 0x80800780: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80800784: addiu       $at, $zero, 0x1374
    ctx->r1 = ADD32(0, 0X1374);
    // 0x80800788: beq         $a3, $at, L_808009C0
    if (ctx->r7 == ctx->r1) {
        // 0x8080078C: addiu       $at, $zero, 0x1375
        ctx->r1 = ADD32(0, 0X1375);
            goto L_808009C0;
    }
    // 0x8080078C: addiu       $at, $zero, 0x1375
    ctx->r1 = ADD32(0, 0X1375);
    // 0x80800790: beq         $a3, $at, L_808009C0
    if (ctx->r7 == ctx->r1) {
        // 0x80800794: addiu       $at, $zero, 0x1376
        ctx->r1 = ADD32(0, 0X1376);
            goto L_808009C0;
    }
    // 0x80800794: addiu       $at, $zero, 0x1376
    ctx->r1 = ADD32(0, 0X1376);
    // 0x80800798: beq         $a3, $at, L_808009C0
    if (ctx->r7 == ctx->r1) {
        // 0x8080079C: addiu       $at, $zero, 0x1385
        ctx->r1 = ADD32(0, 0X1385);
            goto L_808009C0;
    }
    // 0x8080079C: addiu       $at, $zero, 0x1385
    ctx->r1 = ADD32(0, 0X1385);
    // 0x808007A0: beql        $a3, $at, L_808007F0
    if (ctx->r7 == ctx->r1) {
        // 0x808007A4: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_808007F0;
    }
    goto skip_0;
    // 0x808007A4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x808007A8: b           L_808009E0
    // 0x808007AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009E0;
    // 0x808007AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007B0:
    // 0x808007B0: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x808007B4: beq         $a3, $at, L_808008C4
    if (ctx->r7 == ctx->r1) {
        // 0x808007B8: addiu       $at, $zero, 0xCEC
        ctx->r1 = ADD32(0, 0XCEC);
            goto L_808008C4;
    }
    // 0x808007B8: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x808007BC: beq         $a3, $at, L_80800974
    if (ctx->r7 == ctx->r1) {
        // 0x808007C0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800974;
    }
    // 0x808007C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007C4: addiu       $at, $zero, 0x1344
    ctx->r1 = ADD32(0, 0X1344);
    // 0x808007C8: beq         $a3, $at, L_808007EC
    if (ctx->r7 == ctx->r1) {
        // 0x808007CC: addiu       $at, $zero, 0x1345
        ctx->r1 = ADD32(0, 0X1345);
            goto L_808007EC;
    }
    // 0x808007CC: addiu       $at, $zero, 0x1345
    ctx->r1 = ADD32(0, 0X1345);
    // 0x808007D0: beq         $a3, $at, L_80800888
    if (ctx->r7 == ctx->r1) {
        // 0x808007D4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800888;
    }
    // 0x808007D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007D8: addiu       $at, $zero, 0x1346
    ctx->r1 = ADD32(0, 0X1346);
    // 0x808007DC: beq         $a3, $at, L_8080098C
    if (ctx->r7 == ctx->r1) {
        // 0x808007E0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080098C;
    }
    // 0x808007E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007E4: b           L_808009E0
    // 0x808007E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009E0;
    // 0x808007E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007EC:
    // 0x808007EC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_808007F0:
    // 0x808007F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007F4: addiu       $a1, $v1, 0xAC
    ctx->r5 = ADD32(ctx->r3, 0XAC);
    // 0x808007F8: blez        $t6, L_8080084C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808007FC: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_8080084C;
    }
    // 0x808007FC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800800: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800804: addiu       $a1, $v1, 0xAC
    ctx->r5 = ADD32(ctx->r3, 0XAC);
    // 0x80800808: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8080080C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800810: jal         0x8008A2D0
    // 0x80800814: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800814: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80800818: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080081C: addiu       $t8, $zero, 0xA3
    ctx->r24 = ADD32(0, 0XA3);
    // 0x80800820: addiu       $a1, $zero, 0x1345
    ctx->r5 = ADD32(0, 0X1345);
    // 0x80800824: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800828: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080082C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800830: jal         0x8008A208
    // 0x80800834: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800834: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80800838: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080083C: jal         0x80108B04
    // 0x80800840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_3;
    // 0x80800840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800844: b           L_80800878
    // 0x80800848: nop

        goto L_80800878;
    // 0x80800848: nop

L_8080084C:
    // 0x8080084C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800850: jal         0x8008A2C8
    // 0x80800854: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800854: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80800858: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8080085C: addiu       $t0, $zero, 0xA3
    ctx->r8 = ADD32(0, 0XA3);
    // 0x80800860: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80800864: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800868: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080086C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800870: jal         0x8008A208
    // 0x80800874: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800874: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
L_80800878:
    // 0x80800878: jal         0x80088178
    // 0x8080087C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x8080087C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_6:
    // 0x80800880: b           L_808009E0
    // 0x80800884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009E0;
    // 0x80800884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800888:
    // 0x80800888: addiu       $a1, $v1, 0xAC
    ctx->r5 = ADD32(ctx->r3, 0XAC);
    // 0x8080088C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800890: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800894: jal         0x8008A2C8
    // 0x80800898: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800898: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x8080089C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808008A0: addiu       $t2, $zero, 0xA3
    ctx->r10 = ADD32(0, 0XA3);
    // 0x808008A4: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x808008A8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x808008AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808008B0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808008B4: jal         0x8008A208
    // 0x808008B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x808008B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x808008BC: b           L_808009E0
    // 0x808008C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009E0;
    // 0x808008C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008C4:
    // 0x808008C4: jal         0x800F54E4
    // 0x808008C8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x808008C8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_9:
    // 0x808008CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008D0: jal         0x800F82D4
    // 0x808008D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_10;
    // 0x808008D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808008D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008DC: jal         0x80101FDC
    // 0x808008E0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x808008E0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_11:
    // 0x808008E4: jal         0x800D395C
    // 0x808008E8: nop

    func_800D395C(rdram, ctx);
        goto after_12;
    // 0x808008E8: nop

    after_12:
    // 0x808008EC: beq         $v0, $zero, L_80800920
    if (ctx->r2 == 0) {
        // 0x808008F0: lw          $t4, 0x30($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X30);
            goto L_80800920;
    }
    // 0x808008F0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x808008F4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x808008F8: blez        $t3, L_80800910
    if (SIGNED(ctx->r11) <= 0) {
        // 0x808008FC: nop
    
            goto L_80800910;
    }
    // 0x808008FC: nop

    // 0x80800900: jal         0x80088188
    // 0x80800904: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80800904: nop

    after_13:
    // 0x80800908: b           L_808009E0
    // 0x8080090C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009E0;
    // 0x8080090C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800910:
    // 0x80800910: jal         0x80088180
    // 0x80800914: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_14;
    // 0x80800914: nop

    after_14:
    // 0x80800918: b           L_808009E0
    // 0x8080091C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009E0;
    // 0x8080091C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800920:
    // 0x80800920: blez        $t4, L_8080093C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80800924: addiu       $a0, $zero, 0x21A
        ctx->r4 = ADD32(0, 0X21A);
            goto L_8080093C;
    }
    // 0x80800924: addiu       $a0, $zero, 0x21A
    ctx->r4 = ADD32(0, 0X21A);
    // 0x80800928: addiu       $a0, $zero, 0x10A
    ctx->r4 = ADD32(0, 0X10A);
    // 0x8080092C: jal         0x80087A58
    // 0x80800930: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_15;
    // 0x80800930: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800934: b           L_808009E0
    // 0x80800938: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009E0;
    // 0x80800938: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080093C:
    // 0x8080093C: jal         0x80089C30
    // 0x80800940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x80800940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800944: beq         $v0, $zero, L_8080095C
    if (ctx->r2 == 0) {
        // 0x80800948: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080095C;
    }
    // 0x80800948: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080094C: jal         0x80089CA8
    // 0x80800950: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80800950: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_17:
    // 0x80800954: jal         0x8010A570
    // 0x80800958: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A570(rdram, ctx);
        goto after_18;
    // 0x80800958: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_18:
L_8080095C:
    // 0x8080095C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800960: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800964: jal         0x8008A2C0
    // 0x80800968: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x80800968: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    after_19:
    // 0x8080096C: b           L_808009E0
    // 0x80800970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009E0;
    // 0x80800970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800974:
    // 0x80800974: jal         0x8008A2C0
    // 0x80800978: addiu       $a1, $v1, 0xAC
    ctx->r5 = ADD32(ctx->r3, 0XAC);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x80800978: addiu       $a1, $v1, 0xAC
    ctx->r5 = ADD32(ctx->r3, 0XAC);
    after_20:
    // 0x8080097C: jal         0x808006C0
    // 0x80800980: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808006C0_chfactorytwinklies(rdram, ctx);
        goto after_21;
    // 0x80800980: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_21:
    // 0x80800984: b           L_808009E0
    // 0x80800988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009E0;
    // 0x80800988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080098C:
    // 0x8080098C: addiu       $a1, $v1, 0xAC
    ctx->r5 = ADD32(ctx->r3, 0XAC);
    // 0x80800990: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80800994: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800998: jal         0x8008A2D0
    // 0x8080099C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_22;
    // 0x8080099C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_22:
    // 0x808009A0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x808009A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808009A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808009AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808009B0: jal         0x800D1000
    // 0x808009B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_23;
    // 0x808009B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_23:
    // 0x808009B8: b           L_808009E0
    // 0x808009BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009E0;
    // 0x808009BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009C0:
    // 0x808009C0: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x808009C4: addiu       $t6, $zero, 0xA3
    ctx->r14 = ADD32(0, 0XA3);
    // 0x808009C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009CC: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x808009D0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x808009D4: jal         0x8008A208
    // 0x808009D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_24;
    // 0x808009D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_24:
    // 0x808009DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009E0:
    // 0x808009E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009E4: jr          $ra
    // 0x808009E8: nop

    return;
    // 0x808009E8: nop

;}
RECOMP_FUNC void _ncbastring_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089168: syscall     763
    recomp_syscall_handler(rdram, ctx, 0x80089168);
    return;
    // 0x8008916C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80802C48_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C50: jal         0x80106790
    // 0x80802C54: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802C54: nop

    after_0:
    // 0x80802C58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802C5C: jal         0x80100094
    // 0x80802C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80802C64: jal         0x80087DD0
    // 0x80802C68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_39(rdram, ctx);
        goto after_2;
    // 0x80802C68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80802C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802C74: jr          $ra
    // 0x80802C78: nop

    return;
    // 0x80802C78: nop

;}
RECOMP_FUNC void func_80800D48_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D48: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800D4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D50: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800D54: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800D58: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800D5C: jal         0x80100094
    // 0x80800D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D64: jal         0x800D8FF8
    // 0x80800D68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800D68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80800D6C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80800D70: jal         0x80800A28
    // 0x80800D74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800A28_chfishshootgame(rdram, ctx);
        goto after_2;
    // 0x80800D74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800D78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D7C: jal         0x80800A90
    // 0x80800D80: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80800A90_chfishshootgame(rdram, ctx);
        goto after_3;
    // 0x80800D80: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_3:
    // 0x80800D84: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800D88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800D8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800D94: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800D98: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80800D9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800DA0: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800DA4: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800DA8: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800DAC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800DB0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800DB4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800DB8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80800DBC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800DC0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800DC4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800DC8: jal         0x800EFA4C
    // 0x80800DCC: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800DCC: nop

    after_4:
    // 0x80800DD0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800DD4: lui         $a1, 0x43AA
    ctx->r5 = S32(0X43AA << 16);
    // 0x80800DD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800DDC: jal         0x8010C788
    // 0x80800DE0: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    func_8010C788(rdram, ctx);
        goto after_5;
    // 0x80800DE0: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    after_5:
    // 0x80800DE4: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x80800DE8: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800DEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800DF0: lui         $a1, 0x451C
    ctx->r5 = S32(0X451C << 16);
    // 0x80800DF4: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x80800DF8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800DFC: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800E00: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800E04: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80800E08: jal         0x8008FB10
    // 0x80800E0C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    func_8008FB10(rdram, ctx);
        goto after_6;
    // 0x80800E0C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80800E10: lhu         $t6, 0x72($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X72);
    // 0x80800E14: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800E18: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800E1C: sltiu       $at, $t8, 0xB
    ctx->r1 = ctx->r24 < 0XB ? 1 : 0;
    // 0x80800E20: beq         $at, $zero, L_808010DC
    if (ctx->r1 == 0) {
        // 0x80800E24: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808010DC;
    }
    // 0x80800E24: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800E28: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X1800) << 16);
    // 0x80800E2C: addu        $at, $at, $t8
    gpr jr_addend_80800E34 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800E30: lw          $t8, 0x1800($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(740, 0X1800));
    // 0x80800E34: jr          $t8
    // 0x80800E38: nop

    switch (jr_addend_80800E34 >> 2) {
        case 0: goto L_80800E3C; break;
        case 1: goto L_808010DC; break;
        case 2: goto L_80800F90; break;
        case 3: goto L_80800E4C; break;
        case 4: goto L_80800EF8; break;
        case 5: goto L_80800F44; break;
        case 6: goto L_8080105C; break;
        case 7: goto L_80800F6C; break;
        case 8: goto L_80800F5C; break;
        case 9: goto L_80801044; break;
        case 10: goto L_80800F44; break;
        default: switch_error(__func__, 0x80800E34, 0x80801800);
    }
    // 0x80800E38: nop

L_80800E3C:
    // 0x80800E3C: jal         0x808009C0
    // 0x80800E40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808009C0_chfishshootgame(rdram, ctx);
        goto after_7;
    // 0x80800E40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80800E44: b           L_808010E0
    // 0x80800E48: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
        goto L_808010E0;
    // 0x80800E48: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
L_80800E4C:
    // 0x80800E4C: jal         0x800CEAD0
    // 0x80800E50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_8;
    // 0x80800E50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80800E54: beq         $v0, $zero, L_80800E70
    if (ctx->r2 == 0) {
        // 0x80800E58: lwc1        $f10, 0x50($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
            goto L_80800E70;
    }
    // 0x80800E58: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800E5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800E60: jal         0x808003B0
    // 0x80800E64: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_808003B0_chfishshootgame(rdram, ctx);
        goto after_9;
    // 0x80800E64: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_9:
    // 0x80800E68: b           L_808010E0
    // 0x80800E6C: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
        goto L_808010E0;
    // 0x80800E6C: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
L_80800E70:
    // 0x80800E70: lwc1        $f8, 0x58($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80800E74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800E78: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800E7C: swc1        $f16, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f16.u32l;
    // 0x80800E80: lwc1        $f18, 0x58($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80800E84: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800E88: nop

    // 0x80800E8C: bc1f        L_808010DC
    if (!c1cs) {
        // 0x80800E90: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808010DC;
    }
    // 0x80800E90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800E94:
    // 0x80800E94: jal         0x800DC128
    // 0x80800E98: lh          $a1, 0x34($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X34);
    func_800DC128(rdram, ctx);
        goto after_10;
    // 0x80800E98: lh          $a1, 0x34($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X34);
    after_10:
    // 0x80800E9C: lh          $t9, 0x32($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X32);
    // 0x80800EA0: beql        $v0, $t9, L_80800E94
    if (ctx->r2 == ctx->r25) {
        // 0x80800EA4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800E94;
    }
    goto skip_0;
    // 0x80800EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x80800EA8: sh          $v0, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r2;
    // 0x80800EAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800EB0: jal         0x80108B04
    // 0x80800EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_11;
    // 0x80800EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800EB8: jal         0x800CEA60
    // 0x80800EBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEA60(rdram, ctx);
        goto after_12;
    // 0x80800EBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x80800EC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800EC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800EC8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800ECC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800ED0: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x80800ED4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800ED8: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800EDC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800EE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800EE4: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80800EE8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800EEC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800EF0: b           L_808010DC
    // 0x80800EF4: swc1        $f6, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f6.u32l;
        goto L_808010DC;
    // 0x80800EF4: swc1        $f6, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f6.u32l;
L_80800EF8:
    // 0x80800EF8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800EFC: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800F00: jal         0x80101E14
    // 0x80800F04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x80800F04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800F08: beql        $v0, $zero, L_808010E0
    if (ctx->r2 == 0) {
        // 0x80800F0C: lw          $a0, 0x3C($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X3C);
            goto L_808010E0;
    }
    goto skip_1;
    // 0x80800F0C: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    skip_1:
    // 0x80800F10: jal         0x800FC6B0
    // 0x80800F14: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_14;
    // 0x80800F14: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_14:
    // 0x80800F18: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    // 0x80800F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F20: jal         0x800FCAE0
    // 0x80800F24: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    func_800FCAE0(rdram, ctx);
        goto after_15;
    // 0x80800F24: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    after_15:
    // 0x80800F28: jal         0x800FCA90
    // 0x80800F2C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800FCA90(rdram, ctx);
        goto after_16;
    // 0x80800F2C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_16:
    // 0x80800F30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F34: jal         0x808003B0
    // 0x80800F38: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808003B0_chfishshootgame(rdram, ctx);
        goto after_17;
    // 0x80800F38: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_17:
    // 0x80800F3C: b           L_808010E0
    // 0x80800F40: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
        goto L_808010E0;
    // 0x80800F40: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
L_80800F44:
    // 0x80800F44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F48: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800F4C: jal         0x80800C78
    // 0x80800F50: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_80800C78_chfishshootgame(rdram, ctx);
        goto after_18;
    // 0x80800F50: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_18:
    // 0x80800F54: b           L_808010E0
    // 0x80800F58: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
        goto L_808010E0;
    // 0x80800F58: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
L_80800F5C:
    // 0x80800F5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F60: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80800F64: jal         0x80800C78
    // 0x80800F68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_80800C78_chfishshootgame(rdram, ctx);
        goto after_19;
    // 0x80800F68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_19:
L_80800F6C:
    // 0x80800F6C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(740, 0X19C8) << 16);
    // 0x80800F70: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(740, 0X19B8) << 16);
    // 0x80800F74: addiu       $a3, $a3, 0x19B8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(740, 0X19B8));
    // 0x80800F78: addiu       $a2, $a2, 0x19C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(740, 0X19C8));
    // 0x80800F7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F80: jal         0x80089D28
    // 0x80800F84: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x80800F84: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_20:
    // 0x80800F88: b           L_808010E0
    // 0x80800F8C: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
        goto L_808010E0;
    // 0x80800F8C: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
L_80800F90:
    // 0x80800F90: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x80800F94: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800F98: jal         0x80101E14
    // 0x80800F9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101E14(rdram, ctx);
        goto after_21;
    // 0x80800F9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x80800FA0: beql        $v0, $zero, L_80800FB4
    if (ctx->r2 == 0) {
        // 0x80800FA4: lui         $a1, 0x3F4C
        ctx->r5 = S32(0X3F4C << 16);
            goto L_80800FB4;
    }
    goto skip_2;
    // 0x80800FA4: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    skip_2:
    // 0x80800FA8: jal         0x808001F0
    // 0x80800FAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808001F0_chfishshootgame(rdram, ctx);
        goto after_22;
    // 0x80800FAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x80800FB0: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
L_80800FB4:
    // 0x80800FB4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800FB8: jal         0x80101E14
    // 0x80800FBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101E14(rdram, ctx);
        goto after_23;
    // 0x80800FBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x80800FC0: beq         $v0, $zero, L_80800FD4
    if (ctx->r2 == 0) {
        // 0x80800FC4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800FD4;
    }
    // 0x80800FC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FC8: lui         $a1, 0x3F8C
    ctx->r5 = S32(0X3F8C << 16);
    // 0x80800FCC: jal         0x808002E8
    // 0x80800FD0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_808002E8_chfishshootgame(rdram, ctx);
        goto after_24;
    // 0x80800FD0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_24:
L_80800FD4:
    // 0x80800FD4: jal         0x80101F24
    // 0x80800FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101F24(rdram, ctx);
        goto after_25;
    // 0x80800FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x80800FDC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X182C) << 16);
    // 0x80800FE0: lwc1        $f10, 0x182C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(740, 0X182C));
    // 0x80800FE4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800FE8: nop

    // 0x80800FEC: bc1fl       L_80801020
    if (!c1cs) {
        // 0x80800FF0: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_80801020;
    }
    goto skip_3;
    // 0x80800FF0: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    skip_3:
    // 0x80800FF4: jal         0x80101F24
    // 0x80800FF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101F24(rdram, ctx);
        goto after_26;
    // 0x80800FF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x80800FFC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X1830) << 16);
    // 0x80801000: lwc1        $f16, 0x1830($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(740, 0X1830));
    // 0x80801004: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80801008: nop

    // 0x8080100C: bc1fl       L_80801020
    if (!c1cs) {
        // 0x80801010: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_80801020;
    }
    goto skip_4;
    // 0x80801010: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    skip_4:
    // 0x80801014: jal         0x80800C24
    // 0x80801018: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800C24_chfishshootgame(rdram, ctx);
        goto after_27;
    // 0x80801018: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x8080101C: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
L_80801020:
    // 0x80801020: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80801024: jal         0x80101E14
    // 0x80801028: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101E14(rdram, ctx);
        goto after_28;
    // 0x80801028: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_28:
    // 0x8080102C: beq         $v0, $zero, L_808010DC
    if (ctx->r2 == 0) {
        // 0x80801030: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808010DC;
    }
    // 0x80801030: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801034: jal         0x808003B0
    // 0x80801038: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808003B0_chfishshootgame(rdram, ctx);
        goto after_29;
    // 0x80801038: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_29:
    // 0x8080103C: b           L_808010E0
    // 0x80801040: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
        goto L_808010E0;
    // 0x80801040: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
L_80801044:
    // 0x80801044: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801048: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8080104C: jal         0x80800C78
    // 0x80801050: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_80800C78_chfishshootgame(rdram, ctx);
        goto after_30;
    // 0x80801050: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_30:
    // 0x80801054: b           L_808010E0
    // 0x80801058: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
        goto L_808010E0;
    // 0x80801058: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
L_8080105C:
    // 0x8080105C: jal         0x80101F24
    // 0x80801060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101F24(rdram, ctx);
        goto after_31;
    // 0x80801060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_31:
    // 0x80801064: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X1834) << 16);
    // 0x80801068: lwc1        $f18, 0x1834($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(740, 0X1834));
    // 0x8080106C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80801070: nop

    // 0x80801074: bc1fl       L_80801088
    if (!c1cs) {
        // 0x80801078: lui         $a1, 0x3F66
        ctx->r5 = S32(0X3F66 << 16);
            goto L_80801088;
    }
    goto skip_5;
    // 0x80801078: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    skip_5:
    // 0x8080107C: jal         0x80800C24
    // 0x80801080: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800C24_chfishshootgame(rdram, ctx);
        goto after_32;
    // 0x80801080: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_32:
    // 0x80801084: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
L_80801088:
    // 0x80801088: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x8080108C: jal         0x80101E14
    // 0x80801090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101E14(rdram, ctx);
        goto after_33;
    // 0x80801090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_33:
    // 0x80801094: beq         $v0, $zero, L_808010A4
    if (ctx->r2 == 0) {
        // 0x80801098: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808010A4;
    }
    // 0x80801098: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080109C: jal         0x808002E8
    // 0x808010A0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_808002E8_chfishshootgame(rdram, ctx);
        goto after_34;
    // 0x808010A0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_34:
L_808010A4:
    // 0x808010A4: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808010A8: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x808010AC: jal         0x80101E14
    // 0x808010B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101E14(rdram, ctx);
        goto after_35;
    // 0x808010B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_35:
    // 0x808010B4: beql        $v0, $zero, L_808010E0
    if (ctx->r2 == 0) {
        // 0x808010B8: lw          $a0, 0x3C($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X3C);
            goto L_808010E0;
    }
    goto skip_6;
    // 0x808010B8: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    skip_6:
    // 0x808010BC: lbu         $t0, 0x30($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X30);
    // 0x808010C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808010C4: beq         $t0, $zero, L_808010D4
    if (ctx->r8 == 0) {
        // 0x808010C8: nop
    
            goto L_808010D4;
    }
    // 0x808010C8: nop

    // 0x808010CC: b           L_808010D4
    // 0x808010D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_808010D4;
    // 0x808010D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_808010D4:
    // 0x808010D4: jal         0x808003B0
    // 0x808010D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808003B0_chfishshootgame(rdram, ctx);
        goto after_36;
    // 0x808010D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_36:
L_808010DC:
    // 0x808010DC: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
L_808010E0:
    // 0x808010E0: beql        $a0, $zero, L_80801100
    if (ctx->r4 == 0) {
        // 0x808010E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801100;
    }
    goto skip_7;
    // 0x808010E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x808010E8: jal         0x80106790
    // 0x808010EC: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    func_80106790(rdram, ctx);
        goto after_37;
    // 0x808010EC: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    after_37:
    // 0x808010F0: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x808010F4: jal         0x800EE7F8
    // 0x808010F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_38;
    // 0x808010F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_38:
    // 0x808010FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801100:
    // 0x80801100: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801104: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801108: jr          $ra
    // 0x8080110C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8080110C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _chcaveofhorrorsdoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C48: syscall     212
    recomp_syscall_handler(rdram, ctx, 0x80085C48);
    return;
    // 0x80085C4C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80107200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107200: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80107204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107208: jal         0x80106F30
    // 0x8010720C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80106F30(rdram, ctx);
        goto after_0;
    // 0x8010720C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80107210: beq         $v0, $zero, L_80107298
    if (ctx->r2 == 0) {
        // 0x80107214: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80107298;
    }
    // 0x80107214: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80107218: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8010721C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80107220: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80107224: jal         0x800EE940
    // 0x80107228: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800EE940(rdram, ctx);
        goto after_1;
    // 0x80107228: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8010722C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80107230: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80107234: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80107238: lw          $t6, 0x70($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X70);
    // 0x8010723C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80107240: sll         $t7, $t6, 22
    ctx->r15 = S32(ctx->r14 << 22);
    // 0x80107244: srl         $t8, $t7, 26
    ctx->r24 = S32(U32(ctx->r15) >> 26);
    // 0x80107248: srl         $t9, $v0, 8
    ctx->r25 = S32(U32(ctx->r2) >> 8);
    // 0x8010724C: xor         $t0, $t8, $t9
    ctx->r8 = ctx->r24 ^ ctx->r25;
    // 0x80107250: sll         $t1, $t0, 20
    ctx->r9 = S32(ctx->r8 << 20);
    // 0x80107254: srl         $t2, $t1, 12
    ctx->r10 = S32(U32(ctx->r9) >> 12);
    // 0x80107258: xor         $t3, $t2, $v0
    ctx->r11 = ctx->r10 ^ ctx->r2;
    // 0x8010725C: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80107260: lw          $t4, 0x70($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X70);
    // 0x80107264: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    // 0x80107268: srl         $t5, $t4, 25
    ctx->r13 = S32(U32(ctx->r12) >> 25);
    // 0x8010726C: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x80107270: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x80107274: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80107278: sh          $t0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r8;
    // 0x8010727C: lwc1        $f4, 0x48($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X48);
    // 0x80107280: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x80107284: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x80107288: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8010728C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80107290: nop

    // 0x80107294: sh          $t2, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r10;
L_80107298:
    // 0x80107298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010729C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801072A0: jr          $ra
    // 0x801072A4: nop

    return;
    // 0x801072A4: nop

;}
RECOMP_FUNC void func_80800DD8_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800DDC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DE0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800DE4: jal         0x80800234
    // 0x80800DE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bssnowball_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800DE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800DEC: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800DF0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF8: jal         0x8008CB3C
    // 0x80800DFC: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800DFC: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    after_1:
    // 0x80800E00: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800E04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E10: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800E14: jal         0x8009FFD8
    // 0x80800E18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800E18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800E1C: jal         0x80800164
    // 0x80800E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bssnowball(rdram, ctx);
        goto after_3;
    // 0x80800E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E28: jal         0x8009B9B0
    // 0x80800E2C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800E2C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800E30: jal         0x800909CC
    // 0x80800E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_5;
    // 0x80800E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800E38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800E3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E44: jr          $ra
    // 0x80800E48: nop

    return;
    // 0x80800E48: nop

;}
RECOMP_FUNC void bsbabykaz_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808014E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014E4: jal         0x800844A8
    // 0x808014E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bababykaz_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808014E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808014EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014F4: jr          $ra
    // 0x808014F8: nop

    return;
    // 0x808014F8: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085608: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085608);
    return;
    // 0x8008560C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_800A587C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A587C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A5880: lw          $v1, -0x6AC0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6AC0);
    // 0x800A5884: lw          $t6, 0x30($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X30);
    // 0x800A5888: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800A588C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800A5890: jr          $ra
    // 0x800A5894: lbu         $v0, 0x3C($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X3C);
    return;
    // 0x800A5894: lbu         $v0, 0x3C($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X3C);
;}
RECOMP_FUNC void func_800F2320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2320: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F2324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F2328: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F232C: jal         0x800F2100
    // 0x800F2330: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x800F2330: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800F2334: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800F2338: lwc1        $f12, 0x4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800F233C: jal         0x800F2100
    // 0x800F2340: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800F2340: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800F2344: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F2348: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x800F234C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F2350: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F2354: nop

    // 0x800F2358: bc1fl       L_800F236C
    if (!c1cs) {
        // 0x800F235C: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_800F236C;
    }
    goto skip_0;
    // 0x800F235C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_0:
    // 0x800F2360: b           L_800F236C
    // 0x800F2364: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_800F236C;
    // 0x800F2364: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x800F2368: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_800F236C:
    // 0x800F236C: lwc1        $f6, 0x5EE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5EE0);
    // 0x800F2370: add.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x800F2374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F2378: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800F237C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F2380: jr          $ra
    // 0x800F2384: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    return;
    // 0x800F2384: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
;}
RECOMP_FUNC void func_8080101C_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080101C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801020: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801024: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080102C: jal         0x80100094
    // 0x80801030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801034: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801038: jal         0x80105834
    // 0x8080103C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_1;
    // 0x8080103C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801040: jal         0x80803208
    // 0x80801044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803208_chklungo(rdram, ctx);
        goto after_2;
    // 0x80801044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801048: jal         0x80801910
    // 0x8080104C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801910_chklungo(rdram, ctx);
        goto after_3;
    // 0x8080104C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801050: jal         0x80105A5C
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_4;
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801058: beql        $v0, $zero, L_808010B8
    if (ctx->r2 == 0) {
        // 0x8080105C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808010B8;
    }
    goto skip_0;
    // 0x8080105C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801060: jal         0x80802558
    // 0x80801064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802558_chklungo(rdram, ctx);
        goto after_5;
    // 0x80801064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801068: jal         0x800D395C
    // 0x8080106C: nop

    func_800D395C(rdram, ctx);
        goto after_6;
    // 0x8080106C: nop

    after_6:
    // 0x80801070: beq         $v0, $zero, L_80801088
    if (ctx->r2 == 0) {
        // 0x80801074: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801088;
    }
    // 0x80801074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801078: jal         0x80088180
    // 0x8080107C: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x8080107C: nop

    after_7:
    // 0x80801080: b           L_808010AC
    // 0x80801084: nop

        goto L_808010AC;
    // 0x80801084: nop

L_80801088:
    // 0x80801088: jal         0x80100094
    // 0x8080108C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x8080108C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80801090: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80801094: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801098: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    // 0x8080109C: bne         $t6, $at, L_808010AC
    if (ctx->r14 != ctx->r1) {
        // 0x808010A0: nop
    
            goto L_808010AC;
    }
    // 0x808010A0: nop

    // 0x808010A4: jal         0x800887D8
    // 0x808010A8: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_9;
    // 0x808010A8: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    after_9:
L_808010AC:
    // 0x808010AC: jal         0x800FFAB0
    // 0x808010B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808010B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808010B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_808010B8:
    // 0x808010B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808010BC: beql        $a0, $zero, L_808010D0
    if (ctx->r4 == 0) {
        // 0x808010C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808010D0;
    }
    goto skip_1;
    // 0x808010C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808010C4: jal         0x800897D8
    // 0x808010C8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_11;
    // 0x808010C8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_11:
    // 0x808010CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808010D0:
    // 0x808010D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808010D8: jr          $ra
    // 0x808010DC: nop

    return;
    // 0x808010DC: nop

;}
RECOMP_FUNC void func_800AA1A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA1A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AA1A4: addiu       $v0, $v0, 0x7780
    ctx->r2 = ADD32(ctx->r2, 0X7780);
    // 0x800AA1A8: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800AA1AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AA1B0: sb          $t6, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r14;
    // 0x800AA1B4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800AA1B8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800AA1BC: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800AA1C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA1C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA1C8: sh          $zero, 0x778E($at)
    MEM_H(0X778E, ctx->r1) = 0;
    // 0x800AA1CC: sh          $zero, 0x778C($at)
    MEM_H(0X778C, ctx->r1) = 0;
    // 0x800AA1D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA1D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA1D8: sh          $zero, 0x7790($at)
    MEM_H(0X7790, ctx->r1) = 0;
    // 0x800AA1DC: jal         0x800AA148
    // 0x800AA1E0: sh          $zero, 0x7792($at)
    MEM_H(0X7792, ctx->r1) = 0;
    func_800AA148(rdram, ctx);
        goto after_0;
    // 0x800AA1E0: sh          $zero, 0x7792($at)
    MEM_H(0X7792, ctx->r1) = 0;
    after_0:
    // 0x800AA1E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AA1E8: jal         0x80088168
    // 0x800AA1EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcfrontend_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x800AA1EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800AA1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA1F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA1F8: jr          $ra
    // 0x800AA1FC: nop

    return;
    // 0x800AA1FC: nop

;}
RECOMP_FUNC void bsledge_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080123C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801240: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(304, 0X1398) << 16);
    // 0x80801244: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801248: jr          $ra
    // 0x8080124C: lw          $v0, 0x1398($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X1398));
    return;
    // 0x8080124C: lw          $v0, 0x1398($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X1398));
;}
RECOMP_FUNC void _chmolehill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086910: syscall     397
    recomp_syscall_handler(rdram, ctx, 0x80086910);
    return;
    // 0x80086914: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsmumswim_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083910: syscall     81
    recomp_syscall_handler(rdram, ctx, 0x80083910);
    return;
    // 0x80083914: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_801000D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801000D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801000DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801000E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801000E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801000E8: jal         0x80100094
    // 0x801000EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x801000EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x801000F0: bne         $v0, $zero, L_80100104
    if (ctx->r2 != 0) {
        // 0x801000F4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80100104;
    }
    // 0x801000F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801000F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801000FC: jal         0x80100074
    // 0x80100100: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x80100100: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80100104:
    // 0x80100104: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80100108: jal         0x80100094
    // 0x8010010C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x8010010C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80100110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100118: jr          $ra
    // 0x8010011C: nop

    return;
    // 0x8010011C: nop

;}
RECOMP_FUNC void _gcsectionDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088250: syscall     677
    recomp_syscall_handler(rdram, ctx, 0x80088250);
    return;
    // 0x80088254: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800CE3F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE3F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE3F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CE3FC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800CE400: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800CE404: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800CE408: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800CE40C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800CE410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE414: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800CE418: lh          $a0, -0x55D0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X55D0);
    // 0x800CE41C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CE420: jal         0x800D2498
    // 0x800CE424: lh          $a1, 0xA($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XA);
    func_800D2498(rdram, ctx);
        goto after_0;
    // 0x800CE424: lh          $a1, 0xA($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XA);
    after_0:
    // 0x800CE428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE42C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE430: jr          $ra
    // 0x800CE434: nop

    return;
    // 0x800CE434: nop

;}
RECOMP_FUNC void _chfactorytwinklies_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086510: syscall     333
    recomp_syscall_handler(rdram, ctx, 0x80086510);
    return;
    // 0x80086514: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080073C_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080073C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800748: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x8080074C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80800750: bltzl       $t9, L_808007A4
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800754: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007A4;
    }
    goto skip_0;
    // 0x80800754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800758: beq         $a1, $zero, L_80800774
    if (ctx->r5 == 0) {
        // 0x8080075C: nop
    
            goto L_80800774;
    }
    // 0x8080075C: nop

    // 0x80800760: jal         0x800878A0
    // 0x80800764: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800764: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080076C: jal         0x800F7B9C
    // 0x80800770: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    func_800F7B9C(rdram, ctx);
        goto after_1;
    // 0x80800770: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    after_1:
L_80800774:
    // 0x80800774: jal         0x800F54E4
    // 0x80800778: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800778: nop

    after_2:
    // 0x8080077C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800780: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800784: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800788: jal         0x800F8300
    // 0x8080078C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800F8300(rdram, ctx);
        goto after_3;
    // 0x8080078C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_3:
    // 0x80800790: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800794: lbu         $t2, 0x65($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X65);
    // 0x80800798: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x8080079C: sb          $t3, 0x65($t0)
    MEM_B(0X65, ctx->r8) = ctx->r11;
    // 0x808007A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007A4:
    // 0x808007A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007A8: jr          $ra
    // 0x808007AC: nop

    return;
    // 0x808007AC: nop

;}
RECOMP_FUNC void func_80800B30_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800B3C: jal         0x80100094
    // 0x80800B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B44: lh          $t6, 0x32($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X32);
    // 0x80800B48: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800B4C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800B50: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800B54: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800B58: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80800B5C: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x80800B60: jal         0x800EE88C
    // 0x80800B64: addiu       $a1, $a1, 0x36
    ctx->r5 = ADD32(ctx->r5, 0X36);
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x80800B64: addiu       $a1, $a1, 0x36
    ctx->r5 = ADD32(ctx->r5, 0X36);
    after_1:
    // 0x80800B68: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80800B6C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800B70: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800B74: jal         0x800DC178
    // 0x80800B78: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800B78: nop

    after_2:
    // 0x80800B7C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800B80: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B84: addiu       $a0, $zero, 0x1BF
    ctx->r4 = ADD32(0, 0X1BF);
    // 0x80800B88: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80800B8C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B94: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800B98: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x80800B9C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80800BA0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800BA4: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80800BA8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800BAC: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80800BB0: nop

    // 0x80800BB4: bc1fl       L_80800BC8
    if (!c1cs) {
        // 0x80800BB8: lwc1        $f0, 0x4($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
            goto L_80800BC8;
    }
    goto skip_0;
    // 0x80800BB8: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x80800BBC: b           L_80800BDC
    // 0x80800BC0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
        goto L_80800BDC;
    // 0x80800BC0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80800BC4: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
L_80800BC8:
    // 0x80800BC8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800BCC: nop

    // 0x80800BD0: bc1f        L_80800BDC
    if (!c1cs) {
        // 0x80800BD4: nop
    
            goto L_80800BDC;
    }
    // 0x80800BD4: nop

    // 0x80800BD8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
L_80800BDC:
    // 0x80800BDC: jal         0x80108528
    // 0x80800BE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80108528(rdram, ctx);
        goto after_3;
    // 0x80800BE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80800BE4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800BE8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BEC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800BF0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80800BF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800BF8: sw          $t0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r8;
    // 0x80800BFC: lwc1        $f16, 0x18($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800C00: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800C04: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80800C08: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80800C0C: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80800C10: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
    // 0x80800C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800C1C: jr          $ra
    // 0x80800C20: nop

    return;
    // 0x80800C20: nop

;}
RECOMP_FUNC void chboilerid_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808005CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808005D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808005D4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808005D8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808005DC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808005E0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808005E4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808005E8: jal         0x80106790
    // 0x808005EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808005EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x808005F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005F4: jal         0x80100094
    // 0x808005F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808005F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808005FC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800600: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800604: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800608: addu        $s3, $t7, $s0
    ctx->r19 = ADD32(ctx->r15, ctx->r16);
    // 0x8080060C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80800610: beq         $at, $zero, L_80800634
    if (ctx->r1 == 0) {
        // 0x80800614: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800634;
    }
L_80800614:
    // 0x80800614: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800618: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080061C: jal         0x8080079C
    // 0x80800620: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8080079C_chboilerid(rdram, ctx);
        goto after_2;
    // 0x80800620: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x80800624: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800628: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8080062C: bne         $at, $zero, L_80800614
    if (ctx->r1 != 0) {
        // 0x80800630: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800614;
    }
    // 0x80800630: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80800634:
    // 0x80800634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800638: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080063C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800640: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800644: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800648: jr          $ra
    // 0x8080064C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080064C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chfactoryroofbits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874B8: syscall     578
    recomp_syscall_handler(rdram, ctx, 0x800874B8);
    return;
    // 0x800874BC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _fxspgold_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AD0: syscall     721
    recomp_syscall_handler(rdram, ctx, 0x80088AD0);
    return;
    // 0x80088AD4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080049C_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080049C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004AC: jal         0x8008CABC
    // 0x808004B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808004B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x808004B4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808004B8: jal         0x8001210C
    // 0x808004BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_1;
    // 0x808004BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    ctx->r2 = tooie_paced_frame_mask(rdram, (uint32_t)ctx->r2, 7, 1);
    // 0x808004C0: bne         $v0, $zero, L_808004F4
    if (ctx->r2 != 0) {
        // 0x808004C4: nop
    
            goto L_808004F4;
    }
    // 0x808004C4: nop

    // 0x808004C8: jal         0x800DC0C0
    // 0x808004CC: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x808004CC: nop

    after_2:
    // 0x808004D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808004E0: nop

    // 0x808004E4: bc1f        L_808004F4
    if (!c1cs) {
        // 0x808004E8: nop
    
            goto L_808004F4;
    }
    // 0x808004E8: nop

    // 0x808004EC: jal         0x8009FC34
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009FC34(rdram, ctx);
        goto after_3;
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808004F4:
    // 0x808004F4: jal         0x8001210C
    // 0x808004F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_4;
    // 0x808004F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_4:
    ctx->r2 = tooie_paced_frame_mask(rdram, (uint32_t)ctx->r2, 7, 1);
    // 0x808004FC: bnel        $v0, $zero, L_80800534
    if (ctx->r2 != 0) {
        // 0x80800500: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_80800534;
    }
    goto skip_0;
    // 0x80800500: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_0:
    // 0x80800504: jal         0x800DC0C0
    // 0x80800508: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80800508: nop

    after_5:
    // 0x8080050C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800510: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800514: nop

    // 0x80800518: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8080051C: nop

    // 0x80800520: bc1fl       L_80800534
    if (!c1cs) {
        // 0x80800524: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_80800534;
    }
    goto skip_1;
    // 0x80800524: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_1:
    // 0x80800528: jal         0x80800000
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsvanswim(rdram, ctx);
        goto after_6;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800530: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80800534:
    // 0x80800534: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800538: jal         0x8008B348
    // 0x8080053C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x8080053C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80800540: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800544: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800570;
    }
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800548: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x8080054C: lui         $a3, 0x3F93
    ctx->r7 = S32(0X3F93 << 16);
    // 0x80800550: addiu       $t6, $zero, 0x3E80
    ctx->r14 = ADD32(0, 0X3E80);
    // 0x80800554: addiu       $t7, $zero, 0x3E80
    ctx->r15 = ADD32(0, 0X3E80);
    // 0x80800558: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080055C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800560: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800564: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800568: jal         0x8009DEC0
    // 0x8080056C: addiu       $a1, $zero, 0x46F
    ctx->r5 = ADD32(0, 0X46F);
    func_8009DEC0(rdram, ctx);
        goto after_8;
    // 0x8080056C: addiu       $a1, $zero, 0x46F
    ctx->r5 = ADD32(0, 0X46F);
    after_8:
L_80800570:
    // 0x80800570: jal         0x8009EF10
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_9;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800578: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080057C: bne         $v0, $at, L_80800588
    if (ctx->r2 != ctx->r1) {
        // 0x80800580: addiu       $t8, $zero, 0x11C
        ctx->r24 = ADD32(0, 0X11C);
            goto L_80800588;
    }
    // 0x80800580: addiu       $t8, $zero, 0x11C
    ctx->r24 = ADD32(0, 0X11C);
    // 0x80800584: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80800588:
    // 0x80800588: jal         0x8008E35C
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_10;
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800590: bne         $v0, $zero, L_8080059C
    if (ctx->r2 != 0) {
        // 0x80800594: addiu       $t9, $zero, 0x11A
        ctx->r25 = ADD32(0, 0X11A);
            goto L_8080059C;
    }
    // 0x80800594: addiu       $t9, $zero, 0x11A
    ctx->r25 = ADD32(0, 0X11A);
    // 0x80800598: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8080059C:
    // 0x8080059C: jal         0x80096500
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096500(rdram, ctx);
        goto after_11;
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808005A4: beq         $v0, $zero, L_808005C0
    if (ctx->r2 == 0) {
        // 0x808005A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005C0;
    }
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: jal         0x80091A58
    // 0x808005B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_12;
    // 0x808005B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_12:
    // 0x808005B4: beq         $v0, $zero, L_808005C0
    if (ctx->r2 == 0) {
        // 0x808005B8: addiu       $t0, $zero, 0x115
        ctx->r8 = ADD32(0, 0X115);
            goto L_808005C0;
    }
    // 0x808005B8: addiu       $t0, $zero, 0x115
    ctx->r8 = ADD32(0, 0X115);
    // 0x808005BC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_808005C0:
    // 0x808005C0: jal         0x80084138
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsvan_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005CC: jal         0x8009E5C8
    // 0x808005D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_14;
    // 0x808005D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_14:
    // 0x808005D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005E0: jr          $ra
    // 0x808005E4: nop

    return;
    // 0x808005E4: nop

;}
RECOMP_FUNC void func_8080000C_chdiggerground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800024: bgezl       $t8, L_80800060
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800028: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800060;
    }
    goto skip_0;
    // 0x80800028: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080002C: jal         0x80100094
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800034: bne         $v0, $zero, L_80800054
    if (ctx->r2 != 0) {
        // 0x80800038: nop
    
            goto L_80800054;
    }
    // 0x80800038: nop

    // 0x8080003C: jal         0x808000C4
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C4_chdiggerground(rdram, ctx);
        goto after_1;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    // 0x8080004C: jal         0x8010108C
    // 0x80800050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_2;
    // 0x80800050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80800054:
    // 0x80800054: jal         0x8008A108
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080005C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800060:
    // 0x80800060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void _idtwinklea_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088EB0: syscall     746
    recomp_syscall_handler(rdram, ctx, 0x80088EB0);
    return;
    // 0x80088EB4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808012DC_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808012E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808012E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808012E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808012EC: jal         0x8080076C
    // 0x808012F0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_8080076C_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x808012F0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808012F4: jal         0x8080078C
    // 0x808012F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080078C_bskaztorpedo(rdram, ctx);
        goto after_1;
    // 0x808012F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808012FC: jal         0x8080016C
    // 0x80801300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080016C_bskaztorpedo(rdram, ctx);
        goto after_2;
    // 0x80801300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801304: jal         0x8080024C
    // 0x80801308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080024C_bskaztorpedo(rdram, ctx);
        goto after_3;
    // 0x80801308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080130C: jal         0x808002E0
    // 0x80801310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002E0_bskaztorpedo(rdram, ctx);
        goto after_4;
    // 0x80801310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801314: jal         0x808011A4
    // 0x80801318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808011A4_bskaztorpedo(rdram, ctx);
        goto after_5;
    // 0x80801318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080131C: jal         0x80800034
    // 0x80801320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800034_bskaztorpedo(rdram, ctx);
        goto after_6;
    // 0x80801320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801324: jal         0x80800000
    // 0x80801328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskaztorpedo(rdram, ctx);
        goto after_7;
    // 0x80801328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080132C: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x80801330: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801334: addiu       $t6, $zero, 0x154
    ctx->r14 = ADD32(0, 0X154);
    // 0x80801338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080133C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801340: nop

    // 0x80801344: bc1f        L_80801350
    if (!c1cs) {
        // 0x80801348: nop
    
            goto L_80801350;
    }
    // 0x80801348: nop

    // 0x8080134C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80801350:
    // 0x80801350: jal         0x8009E5C8
    // 0x80801354: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80801354: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80801358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080135C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801360: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801364: jr          $ra
    // 0x80801368: nop

    return;
    // 0x80801368: nop

;}
RECOMP_FUNC void func_808018AC_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808018B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808018B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808018B8: jal         0x8080000C
    // 0x808018BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8080000C_bstrexlarge(rdram, ctx);
        goto after_0;
    // 0x808018BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808018C0: jal         0x8080081C
    // 0x808018C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808018C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808018C8: jal         0x808004B4
    // 0x808018CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bstrexlarge(rdram, ctx);
        goto after_2;
    // 0x808018CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808018D0: lui         $a1, 0x3F65
    ctx->r5 = S32(0X3F65 << 16);
    // 0x808018D4: ori         $a1, $a1, 0xCFAB
    ctx->r5 = ctx->r5 | 0XCFAB;
    // 0x808018D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018DC: jal         0x800A2D2C
    // 0x808018E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2D2C(rdram, ctx);
        goto after_3;
    // 0x808018E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x808018E4: lui         $a1, 0x3ECB
    ctx->r5 = S32(0X3ECB << 16);
    // 0x808018E8: ori         $a1, $a1, 0x9F56
    ctx->r5 = ctx->r5 | 0X9F56;
    // 0x808018EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018F0: jal         0x800A2D2C
    // 0x808018F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2D2C(rdram, ctx);
        goto after_4;
    // 0x808018F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x808018F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801900: jal         0x808002E0
    // 0x80801904: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808002E0_bstrexlarge(rdram, ctx);
        goto after_5;
    // 0x80801904: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80801908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080190C: jal         0x8009E5C8
    // 0x80801910: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x80801910: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80801914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801918: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080191C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801920: jr          $ra
    // 0x80801924: nop

    return;
    // 0x80801924: nop

;}
RECOMP_FUNC void func_808000D8_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000E4: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000EC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000F0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808000F4: sltiu       $at, $t8, 0xE
    ctx->r1 = ctx->r24 < 0XE ? 1 : 0;
    // 0x808000F8: beq         $at, $zero, L_80800360
    if (ctx->r1 == 0) {
        // 0x808000FC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800360;
    }
    // 0x808000FC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800100: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X13D0) << 16);
    // 0x80800104: addu        $at, $at, $t8
    gpr jr_addend_8080010C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800108: lw          $t8, 0x13D0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1284, 0X13D0));
    // 0x8080010C: jr          $t8
    // 0x80800110: nop

    switch (jr_addend_8080010C >> 2) {
        case 0: goto L_80800114; break;
        case 1: goto L_80800360; break;
        case 2: goto L_80800124; break;
        case 3: goto L_80800190; break;
        case 4: goto L_80800360; break;
        case 5: goto L_808001F8; break;
        case 6: goto L_80800224; break;
        case 7: goto L_80800360; break;
        case 8: goto L_80800268; break;
        case 9: goto L_80800294; break;
        case 10: goto L_808002D8; break;
        case 11: goto L_80800360; break;
        case 12: goto L_80800314; break;
        case 13: goto L_80800340; break;
        default: switch_error(__func__, 0x8080010C, 0x808013D0);
    }
    // 0x80800110: nop

L_80800114:
    // 0x80800114: jal         0x80800530
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800530_chdippy(rdram, ctx);
        goto after_0;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080011C: b           L_80800364
    // 0x80800120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800364;
    // 0x80800120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800124:
    // 0x80800124: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800128: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080012C: jal         0x80101E14
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800134: beq         $v0, $zero, L_8080014C
    if (ctx->r2 == 0) {
        // 0x80800138: addiu       $a0, $zero, 0x18B9
        ctx->r4 = ADD32(0, 0X18B9);
            goto L_8080014C;
    }
    // 0x80800138: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x8080013C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800140: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800144: jal         0x800861A0
    // 0x80800148: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800148: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
L_8080014C:
    // 0x8080014C: jal         0x80800800
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800800_chdippy(rdram, ctx);
        goto after_3;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800154: jal         0x80101DDC
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_4;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080015C: beq         $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x80800160: addiu       $a1, $zero, 0x17E9
        ctx->r5 = ADD32(0, 0X17E9);
            goto L_80800360;
    }
    // 0x80800160: addiu       $a1, $zero, 0x17E9
    ctx->r5 = ADD32(0, 0X17E9);
    // 0x80800164: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800168: addiu       $t9, $zero, 0xAC
    ctx->r25 = ADD32(0, 0XAC);
    // 0x8080016C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800170: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800174: jal         0x8008A208
    // 0x80800178: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800178: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: jal         0x80800654
    // 0x80800184: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800654_chdippy(rdram, ctx);
        goto after_6;
    // 0x80800184: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80800188: b           L_80800364
    // 0x8080018C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800364;
    // 0x8080018C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800190:
    // 0x80800190: jal         0x80800948
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800948_chdippy(rdram, ctx);
        goto after_7;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800198: jal         0x80101DDC
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_8;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001A0: beql        $v0, $zero, L_80800364
    if (ctx->r2 == 0) {
        // 0x808001A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800364;
    }
    goto skip_0;
    // 0x808001A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808001A8: jal         0x800DA298
    // 0x808001AC: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808001AC: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    after_9:
    // 0x808001B0: beq         $v0, $zero, L_808001CC
    if (ctx->r2 == 0) {
        // 0x808001B4: addiu       $a1, $zero, 0x17EA
        ctx->r5 = ADD32(0, 0X17EA);
            goto L_808001CC;
    }
    // 0x808001B4: addiu       $a1, $zero, 0x17EA
    ctx->r5 = ADD32(0, 0X17EA);
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x80800654
    // 0x808001C0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800654_chdippy(rdram, ctx);
        goto after_10;
    // 0x808001C0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_10:
    // 0x808001C4: b           L_80800364
    // 0x808001C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800364;
    // 0x808001C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001CC:
    // 0x808001CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001D0: addiu       $t0, $zero, 0xAC
    ctx->r8 = ADD32(0, 0XAC);
    // 0x808001D4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808001D8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808001DC: jal         0x8008A208
    // 0x808001E0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x808001E0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_11:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x80800654
    // 0x808001EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800654_chdippy(rdram, ctx);
        goto after_12;
    // 0x808001EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_12:
    // 0x808001F0: b           L_80800364
    // 0x808001F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800364;
    // 0x808001F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001F8:
    // 0x808001F8: jal         0x80101DDC
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_13;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800200: beql        $v0, $zero, L_80800364
    if (ctx->r2 == 0) {
        // 0x80800204: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800364;
    }
    goto skip_1;
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800208: jal         0x80800D44
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D44_chdippy(rdram, ctx);
        goto after_14;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: jal         0x80800654
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800654_chdippy(rdram, ctx);
        goto after_15;
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x8080021C: b           L_80800364
    // 0x80800220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800364;
    // 0x80800220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800224:
    // 0x80800224: jal         0x80800990
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800990_chdippy(rdram, ctx);
        goto after_16;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080022C: jal         0x80101DDC
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_17;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800234: beq         $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x80800238: addiu       $a1, $zero, 0x17EB
        ctx->r5 = ADD32(0, 0X17EB);
            goto L_80800360;
    }
    // 0x80800238: addiu       $a1, $zero, 0x17EB
    ctx->r5 = ADD32(0, 0X17EB);
    // 0x8080023C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800240: addiu       $t1, $zero, 0xAC
    ctx->r9 = ADD32(0, 0XAC);
    // 0x80800244: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800248: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8080024C: jal         0x8008A208
    // 0x80800250: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x80800250: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_18:
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: jal         0x80800654
    // 0x8080025C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800654_chdippy(rdram, ctx);
        goto after_19;
    // 0x8080025C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_19:
    // 0x80800260: b           L_80800364
    // 0x80800264: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800364;
    // 0x80800264: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800268:
    // 0x80800268: jal         0x80101DDC
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_20;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800270: beql        $v0, $zero, L_80800364
    if (ctx->r2 == 0) {
        // 0x80800274: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800364;
    }
    goto skip_2;
    // 0x80800274: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800278: jal         0x80800D44
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D44_chdippy(rdram, ctx);
        goto after_21;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: jal         0x80800654
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800654_chdippy(rdram, ctx);
        goto after_22;
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x8080028C: b           L_80800364
    // 0x80800290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800364;
    // 0x80800290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800294:
    // 0x80800294: jal         0x808009D8
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009D8_chdippy(rdram, ctx);
        goto after_23;
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x8080029C: jal         0x80101DDC
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_24;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808002A4: beq         $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x808002A8: addiu       $a1, $zero, 0x17EC
        ctx->r5 = ADD32(0, 0X17EC);
            goto L_80800360;
    }
    // 0x808002A8: addiu       $a1, $zero, 0x17EC
    ctx->r5 = ADD32(0, 0X17EC);
    // 0x808002AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002B0: addiu       $t2, $zero, 0xAC
    ctx->r10 = ADD32(0, 0XAC);
    // 0x808002B4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808002B8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808002BC: jal         0x8008A208
    // 0x808002C0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_25;
    // 0x808002C0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_25:
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C8: jal         0x80800654
    // 0x808002CC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800654_chdippy(rdram, ctx);
        goto after_26;
    // 0x808002CC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_26:
    // 0x808002D0: b           L_80800364
    // 0x808002D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800364;
    // 0x808002D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002D8:
    // 0x808002D8: jal         0x80101DDC
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_27;
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808002E0: beq         $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x808002E4: addiu       $a1, $zero, 0x17ED
        ctx->r5 = ADD32(0, 0X17ED);
            goto L_80800360;
    }
    // 0x808002E4: addiu       $a1, $zero, 0x17ED
    ctx->r5 = ADD32(0, 0X17ED);
    // 0x808002E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002EC: addiu       $t3, $zero, 0xAC
    ctx->r11 = ADD32(0, 0XAC);
    // 0x808002F0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808002F4: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808002F8: jal         0x8008A208
    // 0x808002FC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_28;
    // 0x808002FC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_28:
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: jal         0x80800654
    // 0x80800308: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800654_chdippy(rdram, ctx);
        goto after_29;
    // 0x80800308: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_29:
    // 0x8080030C: b           L_80800364
    // 0x80800310: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800364;
    // 0x80800310: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800314:
    // 0x80800314: jal         0x80101DDC
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_30;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8080031C: beql        $v0, $zero, L_80800364
    if (ctx->r2 == 0) {
        // 0x80800320: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800364;
    }
    goto skip_3;
    // 0x80800320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800324: jal         0x80800D44
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D44_chdippy(rdram, ctx);
        goto after_31;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800330: jal         0x80800654
    // 0x80800334: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800654_chdippy(rdram, ctx);
        goto after_32;
    // 0x80800334: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80800338: b           L_80800364
    // 0x8080033C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800364;
    // 0x8080033C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800340:
    // 0x80800340: jal         0x80800990
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800990_chdippy(rdram, ctx);
        goto after_33;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80800348: jal         0x80101DDC
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_34;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800350: beq         $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800360;
    }
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x80800654
    // 0x8080035C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80800654_chdippy(rdram, ctx);
        goto after_35;
    // 0x8080035C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_35:
L_80800360:
    // 0x80800360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800364:
    // 0x80800364: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800368: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080036C: jr          $ra
    // 0x80800370: nop

    return;
    // 0x80800370: nop

;}
RECOMP_FUNC void ncbaspline_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A18: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x80800A1C: lw          $v0, 0x28($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X28);
    // 0x80800A20: slti        $t7, $v0, 0x1
    ctx->r15 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x80800A24: jr          $ra
    // 0x80800A28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80800A28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800A2C: nop

;}
RECOMP_FUNC void func_800FE8AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE8AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800FE8B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE8B4: jr          $ra
    // 0x800FE8B8: sb          $t6, 0x59D8($at)
    MEM_B(0X59D8, ctx->r1) = ctx->r14;
    return;
    // 0x800FE8B8: sb          $t6, 0x59D8($at)
    MEM_B(0X59D8, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80803420_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803428: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080342C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80803430: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80803434: jal         0x80100094
    // 0x80803438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080343C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80803440: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803444: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80803448: bne         $t6, $at, L_8080346C
    if (ctx->r14 != ctx->r1) {
        // 0x8080344C: nop
    
            goto L_8080346C;
    }
    // 0x8080344C: nop

    // 0x80803450: lw          $a1, 0x64($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X64);
    // 0x80803454: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80803458: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x8080345C: jal         0x800BD268
    // 0x80803460: srl         $a1, $t8, 30
    ctx->r5 = S32(U32(ctx->r24) >> 30);
    func_800BD268(rdram, ctx);
        goto after_1;
    // 0x80803460: srl         $a1, $t8, 30
    ctx->r5 = S32(U32(ctx->r24) >> 30);
    after_1:
    // 0x80803464: b           L_80803474
    // 0x80803468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803474;
    // 0x80803468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080346C:
    // 0x8080346C: b           L_80803474
    // 0x80803470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803474;
    // 0x80803470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803474:
    // 0x80803474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080347C: jr          $ra
    // 0x80803480: nop

    return;
    // 0x80803480: nop

;}
RECOMP_FUNC void func_80800E10_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800E1C: jal         0x800839E8
    // 0x80800E20: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800E20: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800E24: beq         $v0, $zero, L_80800E38
    if (ctx->r2 == 0) {
        // 0x80800E28: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E38;
    }
    // 0x80800E28: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E2C: jal         0x800839B0
    // 0x80800E30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800E30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800E34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800E38:
    // 0x80800E38: jal         0x8009E5C8
    // 0x80800E3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800E3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E48: jr          $ra
    // 0x80800E4C: nop

    return;
    // 0x80800E4C: nop

;}
RECOMP_FUNC void func_80800000_chwitchytents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800EA05C
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: addiu       $at, $zero, 0x124
    ctx->r1 = ADD32(0, 0X124);
    // 0x80800014: bnel        $v0, $at, L_80800028
    if (ctx->r2 != ctx->r1) {
        // 0x80800018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800028;
    }
    goto skip_0;
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080001C: jal         0x8010A624
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A624(rdram, ctx);
        goto after_1;
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800028:
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void func_8001C1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C1E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C1E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001C1EC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8001C1F0: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x8001C1F4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8001C1F8: lui         $a2, 0x8001
    ctx->r6 = S32(0X8001 << 16);
    // 0x8001C1FC: addiu       $a2, $a2, -0x1800
    ctx->r6 = ADD32(ctx->r6, -0X1800);
    // 0x8001C200: jal         0x8001C324
    // 0x8001C204: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8001C324(rdram, ctx);
        goto after_0;
    // 0x8001C204: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8001C208: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C20C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001C210: addiu       $a1, $a1, -0x3900
    ctx->r5 = ADD32(ctx->r5, -0X3900);
    // 0x8001C214: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8001C218: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8001C21C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8001C220: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x8001C224: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x8001C228: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8001C22C: beq         $t0, $zero, L_8001C244
    if (ctx->r8 == 0) {
        // 0x8001C230: sw          $t9, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r25;
            goto L_8001C244;
    }
    // 0x8001C230: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8001C234: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8001C238: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x8001C23C: b           L_8001C248
    // 0x8001C240: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
        goto L_8001C248;
    // 0x8001C240: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
L_8001C244:
    // 0x8001C244: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
L_8001C248:
    // 0x8001C248: jal         0x8001D30C
    // 0x8001C24C: nop

    func_8001D30C(rdram, ctx);
        goto after_1;
    // 0x8001C24C: nop

    after_1:
    // 0x8001C250: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8001C254: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x8001C258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C25C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001C264: jr          $ra
    // 0x8001C268: nop

    return;
    // 0x8001C268: nop

;}
RECOMP_FUNC void func_800A7130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7138: jal         0x80106790
    // 0x800A713C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x800A713C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A7140: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7144: lbu         $t9, 0x65($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X65);
    // 0x800A7148: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800A714C: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x800A7150: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800A7154: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
    // 0x800A7158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A715C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7160: jr          $ra
    // 0x800A7164: nop

    return;
    // 0x800A7164: nop

;}
RECOMP_FUNC void func_800E0CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0CB4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800E0CB8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800E0CBC: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800E0CC0: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800E0CC4: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800E0CC8: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800E0CCC: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800E0CD0: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800E0CD4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800E0CD8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800E0CDC: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800E0CE0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800E0CE4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800E0CE8: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800E0CEC: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x800E0CF0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800E0CF4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800E0CF8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800E0CFC: blez        $t7, L_800E0E5C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800E0D00: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800E0E5C;
    }
    // 0x800E0D00: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800E0D04: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800E0D08: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800E0D0C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800E0D10: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E0D14: or          $s7, $t6, $zero
    ctx->r23 = ctx->r14 | 0;
    // 0x800E0D18: addiu       $s6, $sp, 0x78
    ctx->r22 = ADD32(ctx->r29, 0X78);
    // 0x800E0D1C: addiu       $s5, $sp, 0x5C
    ctx->r21 = ADD32(ctx->r29, 0X5C);
    // 0x800E0D20: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
    // 0x800E0D24: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
L_800E0D28:
    // 0x800E0D28: addu        $v0, $t8, $s4
    ctx->r2 = ADD32(ctx->r24, ctx->r20);
    // 0x800E0D2C: lbu         $t9, 0x10($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X10);
    // 0x800E0D30: bnel        $s7, $t9, L_800E0E48
    if (ctx->r23 != ctx->r25) {
        // 0x800E0D34: lh          $t1, 0x4($s3)
        ctx->r9 = MEM_H(ctx->r19, 0X4);
            goto L_800E0E48;
    }
    goto skip_0;
    // 0x800E0D34: lh          $t1, 0x4($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X4);
    skip_0:
    // 0x800E0D38: lbu         $t0, 0x11($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X11);
    // 0x800E0D3C: bnel        $t0, $zero, L_800E0E48
    if (ctx->r8 != 0) {
        // 0x800E0D40: lh          $t1, 0x4($s3)
        ctx->r9 = MEM_H(ctx->r19, 0X4);
            goto L_800E0E48;
    }
    goto skip_1;
    // 0x800E0D40: lh          $t1, 0x4($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X4);
    skip_1:
    // 0x800E0D44: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800E0D48: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800E0D4C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800E0D50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E0D54: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800E0D58: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x800E0D5C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800E0D60: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x800E0D64: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800E0D68: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x800E0D6C: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    // 0x800E0D70: bc1fl       L_800E0D90
    if (!c1cs) {
        // 0x800E0D74: c.lt.s      $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
            goto L_800E0D90;
    }
    goto skip_2;
    // 0x800E0D74: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    skip_2:
    // 0x800E0D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E0D7C: jal         0x800D952C
    // 0x800E0D80: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800D952C(rdram, ctx);
        goto after_0;
    // 0x800E0D80: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_0:
    // 0x800E0D84: b           L_800E0E60
    // 0x800E0D88: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_800E0E60;
    // 0x800E0D88: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800E0D8C: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
L_800E0D90:
    // 0x800E0D90: nop

    // 0x800E0D94: bc1fl       L_800E0E10
    if (!c1cs) {
        // 0x800E0D98: c.lt.s      $f24, $f20
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
            goto L_800E0E10;
    }
    goto skip_3;
    // 0x800E0D98: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    skip_3:
    // 0x800E0D9C: jal         0x800D952C
    // 0x800E0DA0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800D952C(rdram, ctx);
        goto after_1;
    // 0x800E0DA0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x800E0DA4: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x800E0DA8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E0DAC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800E0DB0: bc1fl       L_800E0DD8
    if (!c1cs) {
        // 0x800E0DB4: neg.s       $f4, $f20
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
            goto L_800E0DD8;
    }
    goto skip_4;
    // 0x800E0DB4: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    skip_4:
    // 0x800E0DB8: neg.s       $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = -ctx->f20.fl;
    // 0x800E0DBC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800E0DC0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800E0DC4: jal         0x800D9AD4
    // 0x800E0DC8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800D9AD4(rdram, ctx);
        goto after_2;
    // 0x800E0DC8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x800E0DCC: b           L_800E0DEC
    // 0x800E0DD0: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
        goto L_800E0DEC;
    // 0x800E0DD0: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800E0DD4: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
L_800E0DD8:
    // 0x800E0DD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E0DDC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800E0DE0: jal         0x800D9888
    // 0x800E0DE4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800D9888(rdram, ctx);
        goto after_3;
    // 0x800E0DE4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_3:
    // 0x800E0DE8: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
L_800E0DEC:
    // 0x800E0DEC: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800E0DF0: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800E0DF4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x800E0DF8: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800E0DFC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800E0E00: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800E0E04: b           L_800E0E44
    // 0x800E0E08: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
        goto L_800E0E44;
    // 0x800E0E08: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800E0E0C: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
L_800E0E10:
    // 0x800E0E10: nop

    // 0x800E0E14: bc1fl       L_800E0E48
    if (!c1cs) {
        // 0x800E0E18: lh          $t1, 0x4($s3)
        ctx->r9 = MEM_H(ctx->r19, 0X4);
            goto L_800E0E48;
    }
    goto skip_5;
    // 0x800E0E18: lh          $t1, 0x4($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X4);
    skip_5:
    // 0x800E0E1C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800E0E20: jal         0x800EF334
    // 0x800E0E24: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EF334(rdram, ctx);
        goto after_4;
    // 0x800E0E24: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x800E0E28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E0E2C: jal         0x800D952C
    // 0x800E0E30: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800D952C(rdram, ctx);
        goto after_5;
    // 0x800E0E30: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
    // 0x800E0E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E0E38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E0E3C: jal         0x800D9470
    // 0x800E0E40: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800D9470(rdram, ctx);
        goto after_6;
    // 0x800E0E40: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_6:
L_800E0E44:
    // 0x800E0E44: lh          $t1, 0x4($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X4);
L_800E0E48:
    // 0x800E0E48: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800E0E4C: addiu       $s4, $s4, 0x14
    ctx->r20 = ADD32(ctx->r20, 0X14);
    // 0x800E0E50: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800E0E54: bnel        $at, $zero, L_800E0D28
    if (ctx->r1 != 0) {
        // 0x800E0E58: lw          $t8, 0x0($s3)
        ctx->r24 = MEM_W(ctx->r19, 0X0);
            goto L_800E0D28;
    }
    goto skip_6;
    // 0x800E0E58: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    skip_6:
L_800E0E5C:
    // 0x800E0E5C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_800E0E60:
    // 0x800E0E60: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800E0E64: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800E0E68: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800E0E6C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800E0E70: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800E0E74: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800E0E78: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800E0E7C: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800E0E80: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800E0E84: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x800E0E88: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x800E0E8C: jr          $ra
    // 0x800E0E90: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800E0E90: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void _gctransitionDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881A8: syscall     674
    recomp_syscall_handler(rdram, ctx, 0x800881A8);
    return;
    // 0x800881AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
