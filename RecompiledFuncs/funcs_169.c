#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bsrest_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004E4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(344, 0X910) << 16);
    // 0x808004E8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808004EC: jr          $ra
    // 0x808004F0: lw          $v0, 0x910($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(344, 0X910));
    return;
    // 0x808004F0: lw          $v0, 0x910($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(344, 0X910));
;}
RECOMP_FUNC void suegg_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800A80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A84: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800A88: jal         0x80100094
    // 0x80800A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A90: lbu         $v1, 0x38($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X38);
    // 0x80800A94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A98: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800A9C: beq         $v1, $at, L_80800AD4
    if (ctx->r3 == ctx->r1) {
        // 0x80800AA0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800AD4;
    }
    // 0x80800AA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800AA4: bne         $v1, $at, L_80800AC8
    if (ctx->r3 != ctx->r1) {
        // 0x80800AA8: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_80800AC8;
    }
    // 0x80800AA8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800AAC: lui         $a2, 0x458C
    ctx->r6 = S32(0X458C << 16);
    // 0x80800AB0: sb          $t6, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r14;
    // 0x80800AB4: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ABC: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    // 0x80800AC0: jal         0x8008A790
    // 0x80800AC4: lui         $a3, 0x44AF
    ctx->r7 = S32(0X44AF << 16);
    _sumissilehome_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800AC4: lui         $a3, 0x44AF
    ctx->r7 = S32(0X44AF << 16);
    after_1:
L_80800AC8:
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ACC: jal         0x8008A798
    // 0x80800AD0: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    _sumissilehome_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800AD0: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    after_2:
L_80800AD4:
    // 0x80800AD4: jal         0x8008A480
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800ADC: jal         0x80800064
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800064_suegg(rdram, ctx);
        goto after_4;
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800AE4: jal         0x80800D04
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    suegg_entrypoint_22(rdram, ctx);
        goto after_5;
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800AEC: jal         0x800D8FF8
    // 0x80800AF0: nop

    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x80800AF0: nop

    after_6:
    // 0x80800AF4: lwc1        $f4, 0x30($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800AF8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800AFC: swc1        $f6, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f6.u32l;
    // 0x80800B00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B04: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800B08: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800B0C: jr          $ra
    // 0x80800B10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800B10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800DC740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC740: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800DC744: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DC748: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DC74C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DC750: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x800DC754: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DC758: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800DC75C: beq         $t6, $zero, L_800DC838
    if (ctx->r14 == 0) {
        // 0x800DC760: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_800DC838;
    }
    // 0x800DC760: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800DC764: jal         0x800DC580
    // 0x800DC768: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800DC580(rdram, ctx);
        goto after_0;
    // 0x800DC768: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x800DC76C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800DC770: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800DC774: jal         0x80018E1C
    // 0x800DC778: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    mlMtx_push_translation(rdram, ctx);
        goto after_1;
    // 0x800DC778: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800DC77C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC780: jal         0x80018FE8
    // 0x800DC784: lwc1        $f12, -0x3154($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3154);
    mlMtxRotYaw(rdram, ctx);
        goto after_2;
    // 0x800DC784: lwc1        $f12, -0x3154($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3154);
    after_2:
    // 0x800DC788: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x800DC78C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC790: bne         $t7, $zero, L_800DC7A0
    if (ctx->r15 != 0) {
        // 0x800DC794: nop
    
            goto L_800DC7A0;
    }
    // 0x800DC794: nop

    // 0x800DC798: jal         0x80018F50
    // 0x800DC79C: lwc1        $f12, -0x3158($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3158);
    mlMtxRotPitch(rdram, ctx);
        goto after_3;
    // 0x800DC79C: lwc1        $f12, -0x3158($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3158);
    after_3:
L_800DC7A0:
    // 0x800DC7A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC7A4: jal         0x80019148
    // 0x800DC7A8: lwc1        $f12, -0x36B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X36B8);
    mlMtxScale(rdram, ctx);
        goto after_4;
    // 0x800DC7A8: lwc1        $f12, -0x36B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X36B8);
    after_4:
    // 0x800DC7AC: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800DC7B0: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DC7B4: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800DC7B8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800DC7BC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800DC7C0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800DC7C4: jal         0x80019C84
    // 0x800DC7C8: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    mlMtxTranslate(rdram, ctx);
        goto after_5;
    // 0x800DC7C8: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_5:
    // 0x800DC7CC: jal         0x80018C28
    // 0x800DC7D0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_6;
    // 0x800DC7D0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x800DC7D4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800DC7D8: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800DC7DC: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x800DC7E0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800DC7E4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800DC7E8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800DC7EC: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x800DC7F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DC7F4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800DC7F8: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x800DC7FC: addiu       $t2, $t1, 0x40
    ctx->r10 = ADD32(ctx->r9, 0X40);
    // 0x800DC800: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x800DC804: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
    // 0x800DC808: jal         0x800DE2A4
    // 0x800DC80C: addu        $a1, $s1, $t3
    ctx->r5 = ADD32(ctx->r17, ctx->r11);
    func_800DE2A4(rdram, ctx);
        goto after_7;
    // 0x800DC80C: addu        $a1, $s1, $t3
    ctx->r5 = ADD32(ctx->r17, ctx->r11);
    after_7:
    // 0x800DC810: jal         0x80018DAC
    // 0x800DC814: nop

    mlMtxPop(rdram, ctx);
        goto after_8;
    // 0x800DC814: nop

    after_8:
    // 0x800DC818: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800DC81C: lui         $t5, 0xD838
    ctx->r13 = S32(0XD838 << 16);
    // 0x800DC820: ori         $t5, $t5, 0x2
    ctx->r13 = ctx->r13 | 0X2;
    // 0x800DC824: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800DC828: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800DC82C: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x800DC830: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800DC834: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800DC838:
    // 0x800DC838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DC83C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DC840: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DC844: jr          $ra
    // 0x800DC848: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800DC848: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80802858_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802858: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080285C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80802860: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802864: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80802868: beq         $a1, $at, L_80802884
    if (ctx->r5 == ctx->r1) {
        // 0x8080286C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80802884;
    }
    // 0x8080286C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80802870: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80802874: beq         $a1, $at, L_80802A18
    if (ctx->r5 == ctx->r1) {
        // 0x80802878: lh          $v0, 0x28($sp)
        ctx->r2 = MEM_H(ctx->r29, 0X28);
            goto L_80802A18;
    }
    // 0x80802878: lh          $v0, 0x28($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X28);
    // 0x8080287C: b           L_80802B00
    // 0x80802880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802B00;
    // 0x80802880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802884:
    // 0x80802884: lh          $v0, 0x28($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X28);
    // 0x80802888: slti        $at, $v0, 0x14FC
    ctx->r1 = SIGNED(ctx->r2) < 0X14FC ? 1 : 0;
    // 0x8080288C: bne         $at, $zero, L_808028D0
    if (ctx->r1 != 0) {
        // 0x80802890: addiu       $t6, $v0, -0x1554
        ctx->r14 = ADD32(ctx->r2, -0X1554);
            goto L_808028D0;
    }
    // 0x80802890: addiu       $t6, $v0, -0x1554
    ctx->r14 = ADD32(ctx->r2, -0X1554);
    // 0x80802894: slti        $at, $v0, 0x150C
    ctx->r1 = SIGNED(ctx->r2) < 0X150C ? 1 : 0;
    // 0x80802898: bne         $at, $zero, L_808028BC
    if (ctx->r1 != 0) {
        // 0x8080289C: sltiu       $at, $t6, 0x11
        ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
            goto L_808028BC;
    }
    // 0x8080289C: sltiu       $at, $t6, 0x11
    ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
    // 0x808028A0: beq         $at, $zero, L_80802AFC
    if (ctx->r1 == 0) {
        // 0x808028A4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80802AFC;
    }
    // 0x808028A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808028A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3A1C) << 16);
    // 0x808028AC: addu        $at, $at, $t6
    gpr jr_addend_808028B4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808028B0: lw          $t6, 0x3A1C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(772, 0X3A1C));
    // 0x808028B4: jr          $t6
    // 0x808028B8: nop

    switch (jr_addend_808028B4 >> 2) {
        case 0: goto L_80802908; break;
        case 1: goto L_80802980; break;
        case 2: goto L_80802AFC; break;
        case 3: goto L_80802AFC; break;
        case 4: goto L_80802AFC; break;
        case 5: goto L_80802AFC; break;
        case 6: goto L_80802AFC; break;
        case 7: goto L_80802AFC; break;
        case 8: goto L_80802AFC; break;
        case 9: goto L_80802AFC; break;
        case 10: goto L_808029CC; break;
        case 11: goto L_808028F4; break;
        case 12: goto L_808028F4; break;
        case 13: goto L_808029CC; break;
        case 14: goto L_808029CC; break;
        case 15: goto L_808029CC; break;
        case 16: goto L_808029CC; break;
        default: switch_error(__func__, 0x808028B4, 0x80803A1C);
    }
    // 0x808028B8: nop

L_808028BC:
    // 0x808028BC: addiu       $at, $zero, 0x150B
    ctx->r1 = ADD32(0, 0X150B);
    // 0x808028C0: beql        $v0, $at, L_808029AC
    if (ctx->r2 == ctx->r1) {
        // 0x808028C4: lh          $t0, 0x2A($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X2A);
            goto L_808029AC;
    }
    goto skip_0;
    // 0x808028C4: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    skip_0:
    // 0x808028C8: b           L_80802AFC
    // 0x808028CC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
        goto L_80802AFC;
    // 0x808028CC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
L_808028D0:
    // 0x808028D0: addiu       $at, $zero, 0x14F9
    ctx->r1 = ADD32(0, 0X14F9);
    // 0x808028D4: beq         $v0, $at, L_808028F4
    if (ctx->r2 == ctx->r1) {
        // 0x808028D8: addiu       $at, $zero, 0x14FA
        ctx->r1 = ADD32(0, 0X14FA);
            goto L_808028F4;
    }
    // 0x808028D8: addiu       $at, $zero, 0x14FA
    ctx->r1 = ADD32(0, 0X14FA);
    // 0x808028DC: beq         $v0, $at, L_80802994
    if (ctx->r2 == ctx->r1) {
        // 0x808028E0: addiu       $at, $zero, 0x14FB
        ctx->r1 = ADD32(0, 0X14FB);
            goto L_80802994;
    }
    // 0x808028E0: addiu       $at, $zero, 0x14FB
    ctx->r1 = ADD32(0, 0X14FB);
    // 0x808028E4: beql        $v0, $at, L_808029AC
    if (ctx->r2 == ctx->r1) {
        // 0x808028E8: lh          $t0, 0x2A($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X2A);
            goto L_808029AC;
    }
    goto skip_1;
    // 0x808028E8: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    skip_1:
    // 0x808028EC: b           L_80802B00
    // 0x808028F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802B00;
    // 0x808028F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808028F4:
    // 0x808028F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808028F8: jal         0x80801E4C
    // 0x808028FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801E4C_chjiggygamenew(rdram, ctx);
        goto after_0;
    // 0x808028FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802900: b           L_80802B00
    // 0x80802904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802B00;
    // 0x80802904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802908:
    // 0x80802908: lh          $t7, 0x2A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2A);
    // 0x8080290C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802910: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802914: bne         $t7, $at, L_80802970
    if (ctx->r15 != ctx->r1) {
        // 0x80802918: nop
    
            goto L_80802970;
    }
    // 0x80802918: nop

    // 0x8080291C: addiu       $a0, $zero, 0xD74
    ctx->r4 = ADD32(0, 0XD74);
    // 0x80802920: jal         0x800DA298
    // 0x80802924: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80802924: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80802928: bne         $v0, $zero, L_80802960
    if (ctx->r2 != 0) {
        // 0x8080292C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80802960;
    }
    // 0x8080292C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802930: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80802934: addiu       $t9, $zero, 0x97
    ctx->r25 = ADD32(0, 0X97);
    // 0x80802938: addiu       $a1, $zero, 0x1555
    ctx->r5 = ADD32(0, 0X1555);
    // 0x8080293C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80802940: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802944: addiu       $a2, $zero, 0x4C7
    ctx->r6 = ADD32(0, 0X4C7);
    // 0x80802948: jal         0x8008A208
    // 0x8080294C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x8080294C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80802950: jal         0x800DA544
    // 0x80802954: addiu       $a0, $zero, 0xD74
    ctx->r4 = ADD32(0, 0XD74);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80802954: addiu       $a0, $zero, 0xD74
    ctx->r4 = ADD32(0, 0XD74);
    after_3:
    // 0x80802958: b           L_80802B00
    // 0x8080295C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802B00;
    // 0x8080295C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802960:
    // 0x80802960: jal         0x80801E4C
    // 0x80802964: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801E4C_chjiggygamenew(rdram, ctx);
        goto after_4;
    // 0x80802964: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80802968: b           L_80802B00
    // 0x8080296C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802B00;
    // 0x8080296C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802970:
    // 0x80802970: jal         0x80801E4C
    // 0x80802974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801E4C_chjiggygamenew(rdram, ctx);
        goto after_5;
    // 0x80802974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80802978: b           L_80802B00
    // 0x8080297C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802B00;
    // 0x8080297C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802980:
    // 0x80802980: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802984: jal         0x80801E4C
    // 0x80802988: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801E4C_chjiggygamenew(rdram, ctx);
        goto after_6;
    // 0x80802988: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080298C: b           L_80802B00
    // 0x80802990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802B00;
    // 0x80802990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802994:
    // 0x80802994: jal         0x8008A6E0
    // 0x80802998: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _sujiggy_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80802998: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_7:
    // 0x8080299C: jal         0x80800B88
    // 0x808029A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800B88_chjiggygamenew(rdram, ctx);
        goto after_8;
    // 0x808029A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x808029A4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808029A8: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
L_808029AC:
    // 0x808029AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808029B0: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x808029B4: bne         $t0, $at, L_808029C4
    if (ctx->r8 != ctx->r1) {
        // 0x808029B8: addiu       $t2, $zero, 0x8
        ctx->r10 = ADD32(0, 0X8);
            goto L_808029C4;
    }
    // 0x808029B8: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x808029BC: b           L_80802AFC
    // 0x808029C0: sw          $t1, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r9;
        goto L_80802AFC;
    // 0x808029C0: sw          $t1, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r9;
L_808029C4:
    // 0x808029C4: b           L_80802AFC
    // 0x808029C8: sw          $t2, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r10;
        goto L_80802AFC;
    // 0x808029C8: sw          $t2, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r10;
L_808029CC:
    // 0x808029CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808029D0: jal         0x80800B88
    // 0x808029D4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80800B88_chjiggygamenew(rdram, ctx);
        goto after_9;
    // 0x808029D4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_9:
    // 0x808029D8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x808029DC: lw          $a0, 0x6C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X6C);
    // 0x808029E0: andi        $t4, $a0, 0x1FF
    ctx->r12 = ctx->r4 & 0X1FF;
    // 0x808029E4: jal         0x8008A760
    // 0x808029E8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    _sujiggy_entrypoint_25(rdram, ctx);
        goto after_10;
    // 0x808029E8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_10:
    // 0x808029EC: lh          $t5, 0x2A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2A);
    // 0x808029F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808029F4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808029F8: bne         $t5, $at, L_80802A0C
    if (ctx->r13 != ctx->r1) {
        // 0x808029FC: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_80802A0C;
    }
    // 0x808029FC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80802A00: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80802A04: b           L_80802AFC
    // 0x80802A08: sw          $t6, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r14;
        goto L_80802AFC;
    // 0x80802A08: sw          $t6, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r14;
L_80802A0C:
    // 0x80802A0C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80802A10: b           L_80802AFC
    // 0x80802A14: sw          $t8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r24;
        goto L_80802AFC;
    // 0x80802A14: sw          $t8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r24;
L_80802A18:
    // 0x80802A18: slti        $at, $v0, 0x14FC
    ctx->r1 = SIGNED(ctx->r2) < 0X14FC ? 1 : 0;
    // 0x80802A1C: bne         $at, $zero, L_80802A60
    if (ctx->r1 != 0) {
        // 0x80802A20: addiu       $t0, $v0, -0x1554
        ctx->r8 = ADD32(ctx->r2, -0X1554);
            goto L_80802A60;
    }
    // 0x80802A20: addiu       $t0, $v0, -0x1554
    ctx->r8 = ADD32(ctx->r2, -0X1554);
    // 0x80802A24: slti        $at, $v0, 0x14FD
    ctx->r1 = SIGNED(ctx->r2) < 0X14FD ? 1 : 0;
    // 0x80802A28: bne         $at, $zero, L_80802A4C
    if (ctx->r1 != 0) {
        // 0x80802A2C: sltiu       $at, $t0, 0x11
        ctx->r1 = ctx->r8 < 0X11 ? 1 : 0;
            goto L_80802A4C;
    }
    // 0x80802A2C: sltiu       $at, $t0, 0x11
    ctx->r1 = ctx->r8 < 0X11 ? 1 : 0;
    // 0x80802A30: beq         $at, $zero, L_80802AFC
    if (ctx->r1 == 0) {
        // 0x80802A34: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80802AFC;
    }
    // 0x80802A34: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80802A38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3A60) << 16);
    // 0x80802A3C: addu        $at, $at, $t0
    gpr jr_addend_80802A44 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80802A40: lw          $t0, 0x3A60($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(772, 0X3A60));
    // 0x80802A44: jr          $t0
    // 0x80802A48: nop

    switch (jr_addend_80802A44 >> 2) {
        case 0: goto L_80802A88; break;
        case 1: goto L_80802AFC; break;
        case 2: goto L_80802AFC; break;
        case 3: goto L_80802AFC; break;
        case 4: goto L_80802AFC; break;
        case 5: goto L_80802AFC; break;
        case 6: goto L_80802AFC; break;
        case 7: goto L_80802AFC; break;
        case 8: goto L_80802AFC; break;
        case 9: goto L_80802AFC; break;
        case 10: goto L_80802AFC; break;
        case 11: goto L_80802AFC; break;
        case 12: goto L_80802AE4; break;
        case 13: goto L_80802AA8; break;
        case 14: goto L_80802AE4; break;
        case 15: goto L_80802AD4; break;
        case 16: goto L_80802AA8; break;
        default: switch_error(__func__, 0x80802A44, 0x80803A60);
    }
    // 0x80802A48: nop

L_80802A4C:
    // 0x80802A4C: addiu       $at, $zero, 0x14FC
    ctx->r1 = ADD32(0, 0X14FC);
    // 0x80802A50: beql        $v0, $at, L_80802A80
    if (ctx->r2 == ctx->r1) {
        // 0x80802A54: lw          $v0, 0x2C($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X2C);
            goto L_80802A80;
    }
    goto skip_2;
    // 0x80802A54: lw          $v0, 0x2C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X2C);
    skip_2:
    // 0x80802A58: b           L_80802B00
    // 0x80802A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802B00;
    // 0x80802A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802A60:
    // 0x80802A60: addiu       $at, $zero, 0x14F9
    ctx->r1 = ADD32(0, 0X14F9);
    // 0x80802A64: beq         $v0, $at, L_80802A98
    if (ctx->r2 == ctx->r1) {
        // 0x80802A68: addiu       $at, $zero, 0x14FA
        ctx->r1 = ADD32(0, 0X14FA);
            goto L_80802A98;
    }
    // 0x80802A68: addiu       $at, $zero, 0x14FA
    ctx->r1 = ADD32(0, 0X14FA);
    // 0x80802A6C: beq         $v0, $at, L_80802A7C
    if (ctx->r2 == ctx->r1) {
        // 0x80802A70: addiu       $at, $zero, 0x14FB
        ctx->r1 = ADD32(0, 0X14FB);
            goto L_80802A7C;
    }
    // 0x80802A70: addiu       $at, $zero, 0x14FB
    ctx->r1 = ADD32(0, 0X14FB);
    // 0x80802A74: bnel        $v0, $at, L_80802B00
    if (ctx->r2 != ctx->r1) {
        // 0x80802A78: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802B00;
    }
    goto skip_3;
    // 0x80802A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
L_80802A7C:
    // 0x80802A7C: lw          $v0, 0x2C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X2C);
L_80802A80:
    // 0x80802A80: b           L_80802B00
    // 0x80802A84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80802B00;
    // 0x80802A84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80802A88:
    // 0x80802A88: jal         0x8008A730
    // 0x80802A8C: nop

    _sujiggy_entrypoint_19(rdram, ctx);
        goto after_11;
    // 0x80802A8C: nop

    after_11:
    // 0x80802A90: b           L_80802B04
    // 0x80802A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B04;
    // 0x80802A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802A98:
    // 0x80802A98: jal         0x8008A758
    // 0x80802A9C: nop

    _sujiggy_entrypoint_24(rdram, ctx);
        goto after_12;
    // 0x80802A9C: nop

    after_12:
    // 0x80802AA0: b           L_80802B04
    // 0x80802AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B04;
    // 0x80802AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802AA8:
    // 0x80802AA8: lh          $t1, 0x2A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2A);
    // 0x80802AAC: beql        $t1, $zero, L_80802AC8
    if (ctx->r9 == 0) {
        // 0x80802AB0: lw          $v0, 0x6C($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X6C);
            goto L_80802AC8;
    }
    goto skip_4;
    // 0x80802AB0: lw          $v0, 0x6C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X6C);
    skip_4:
    // 0x80802AB4: jal         0x8008A758
    // 0x80802AB8: nop

    _sujiggy_entrypoint_24(rdram, ctx);
        goto after_13;
    // 0x80802AB8: nop

    after_13:
    // 0x80802ABC: b           L_80802B04
    // 0x80802AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B04;
    // 0x80802AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802AC4: lw          $v0, 0x6C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X6C);
L_80802AC8:
    // 0x80802AC8: andi        $t2, $v0, 0x1FF
    ctx->r10 = ctx->r2 & 0X1FF;
    // 0x80802ACC: b           L_80802B00
    // 0x80802AD0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_80802B00;
    // 0x80802AD0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80802AD4:
    // 0x80802AD4: jal         0x8008A758
    // 0x80802AD8: nop

    _sujiggy_entrypoint_24(rdram, ctx);
        goto after_14;
    // 0x80802AD8: nop

    after_14:
    // 0x80802ADC: b           L_80802B04
    // 0x80802AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B04;
    // 0x80802AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802AE4:
    // 0x80802AE4: jal         0x8008A758
    // 0x80802AE8: nop

    _sujiggy_entrypoint_24(rdram, ctx);
        goto after_15;
    // 0x80802AE8: nop

    after_15:
    // 0x80802AEC: b           L_80802B04
    // 0x80802AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B04;
    // 0x80802AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802AF4: b           L_80802B00
    // 0x80802AF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802B00;
    // 0x80802AF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802AFC:
    // 0x80802AFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802B00:
    // 0x80802B00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802B04:
    // 0x80802B04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802B08: jr          $ra
    // 0x80802B0C: nop

    return;
    // 0x80802B0C: nop

;}
RECOMP_FUNC void func_8080063C_chrainbow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080063C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80800640: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800644: mtc1        $a1, $f28
    ctx->f28.u32l = ctx->r5;
    // 0x80800648: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8080064C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80800650: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80800654: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800658: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8080065C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80800660: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80800664: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80800668: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8080066C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80800670: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80800674: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800678: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8080067C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800680: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800684: blez        $a2, L_808007F8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800688: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_808007F8;
    }
    // 0x80800688: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8080068C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800690: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800694: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800698: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8080069C: addiu       $s6, $sp, 0x90
    ctx->r22 = ADD32(ctx->r29, 0X90);
    // 0x808006A0: addiu       $s5, $sp, 0x9C
    ctx->r21 = ADD32(ctx->r29, 0X9C);
    // 0x808006A4: addiu       $s3, $sp, 0x84
    ctx->r19 = ADD32(ctx->r29, 0X84);
L_808006A8:
    // 0x808006A8: jal         0x800DC0C0
    // 0x808006AC: nop

    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x808006AC: nop

    after_0:
    // 0x808006B0: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x808006B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808006B8: jal         0x800F1214
    // 0x808006BC: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    func_800F1214(rdram, ctx);
        goto after_1;
    // 0x808006BC: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    after_1:
    // 0x808006C0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808006C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808006C8: jal         0x800DC128
    // 0x808006CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x808006CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x808006D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808006D4: jal         0x80103EAC
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_3;
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808006DC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808006E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808006E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808006E8: sub.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x808006EC: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x808006F0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808006F4: jal         0x800EEC70
    // 0x808006F8: nop

    func_800EEC70(rdram, ctx);
        goto after_4;
    // 0x808006F8: nop

    after_4:
    // 0x808006FC: lwc1        $f0, 0x9C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80800700: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800704: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800708: jal         0x800F1214
    // 0x8080070C: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
    func_800F1214(rdram, ctx);
        goto after_5;
    // 0x8080070C: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
    after_5:
    // 0x80800710: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800718: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8080071C: jal         0x80103EF4
    // 0x80800720: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    func_80103EF4(rdram, ctx);
        goto after_6;
    // 0x80800720: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80800724: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80800728: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8080072C: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x80800730: jal         0x800F1214
    // 0x80800734: lui         $a2, 0x4387
    ctx->r6 = S32(0X4387 << 16);
    func_800F1214(rdram, ctx);
        goto after_7;
    // 0x80800734: lui         $a2, 0x4387
    ctx->r6 = S32(0X4387 << 16);
    after_7:
    // 0x80800738: jal         0x800138D0
    // 0x8080073C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800138D0(rdram, ctx);
        goto after_8;
    // 0x8080073C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_8:
    // 0x80800740: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800744: jal         0x80103EF4
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_9;
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080074C: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x80800750: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800754: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80800758: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8080075C: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x80800760: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800764: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800768: neg.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = -ctx->f10.fl;
    // 0x8080076C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80800770: jal         0x800F1214
    // 0x80800774: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    func_800F1214(rdram, ctx);
        goto after_10;
    // 0x80800774: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x80800778: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8080077C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800780: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800784: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800788: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8080078C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800790: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800794: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x80800798: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080079C: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808007A0: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x808007A4: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x808007A8: mtc1        $s1, $f18
    ctx->f18.u32l = ctx->r17;
    // 0x808007AC: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808007B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808007B4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808007B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007BC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808007C0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808007C4: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x808007C8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x808007CC: jal         0x800EEC70
    // 0x808007D0: nop

    func_800EEC70(rdram, ctx);
        goto after_11;
    // 0x808007D0: nop

    after_11:
    // 0x808007D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808007D8: jal         0x800EF04C
    // 0x808007DC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x808007DC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_12:
    // 0x808007E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808007E4: jal         0x808005E0
    // 0x808007E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808005E0_chrainbow(rdram, ctx);
        goto after_13;
    // 0x808007E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x808007EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808007F0: bne         $s2, $s4, L_808006A8
    if (ctx->r18 != ctx->r20) {
        // 0x808007F4: nop
    
            goto L_808006A8;
    }
    // 0x808007F4: nop

L_808007F8:
    // 0x808007F8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x808007FC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800800: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800804: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800808: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080080C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800810: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80800814: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80800818: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8080081C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80800820: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80800824: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80800828: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8080082C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80800830: jr          $ra
    // 0x80800834: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80800834: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_8080061C_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080061C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800620: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800624: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800628: jal         0x80800114
    // 0x8080062C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800114_bsvanswim(rdram, ctx);
        goto after_0;
    // 0x8080062C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800630: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800634: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080063C: jal         0x8008CB3C
    // 0x80800640: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800640: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_1:
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: jal         0x8008CA4C
    // 0x8080064C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008CA4C(rdram, ctx);
        goto after_2;
    // 0x8080064C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800650: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800654: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080065C: jal         0x8008C9BC
    // 0x80800660: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_3;
    // 0x80800660: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_3:
    // 0x80800664: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(431, 0X974) << 16);
    // 0x80800668: lwc1        $f4, 0x974($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(431, 0X974));
    // 0x8080066C: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800670: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x8080067C: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80800680: jal         0x8008C9F0
    // 0x80800684: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_4;
    // 0x80800684: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: jal         0x8009C908
    // 0x80800690: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_5;
    // 0x80800690: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800698: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x8080069C: jal         0x8009C99C
    // 0x808006A0: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_6;
    // 0x808006A0: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_6:
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: jal         0x8009D2D8
    // 0x808006AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D2D8(rdram, ctx);
        goto after_7;
    // 0x808006AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B4: jal         0x8009B800
    // 0x808006B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baphysics_set_type(rdram, ctx);
        goto after_8;
    // 0x808006B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808006BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006C8: jr          $ra
    // 0x808006CC: nop

    return;
    // 0x808006CC: nop

;}
RECOMP_FUNC void chjigsawdance_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x808002E4: nop

    // 0x808002E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002EC: jr          $ra
    // 0x808002F0: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x808002F0: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void chdiggerbossdeflect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1552, 0X40) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1552, 0X40));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1552, 0X40));
;}
RECOMP_FUNC void func_80801CF0_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801CF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801CF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801CFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801D00: jal         0x8008A0A0
    // 0x80801D04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _subaddiemulti_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801D04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80801D08: jal         0x80088368
    // 0x80801D0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80801D0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_1:
    // 0x80801D10: blezl       $v0, L_80801D44
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801D14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801D44;
    }
    goto skip_0;
    // 0x80801D14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80801D18:
    // 0x80801D18: jal         0x800F53D0
    // 0x80801D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x80801D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801D20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801D24: jal         0x800946C4
    // 0x80801D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800946C4(rdram, ctx);
        goto after_3;
    // 0x80801D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801D2C: jal         0x80088368
    // 0x80801D30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80801D30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_4:
    // 0x80801D34: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801D38: bne         $at, $zero, L_80801D18
    if (ctx->r1 != 0) {
        // 0x80801D3C: nop
    
            goto L_80801D18;
    }
    // 0x80801D3C: nop

    // 0x80801D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801D44:
    // 0x80801D44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801D48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D4C: jr          $ra
    // 0x80801D50: nop

    return;
    // 0x80801D50: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088868: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088868);
    return;
    // 0x8008886C: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void func_80800528_chsquits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800528: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8080052C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80800530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800534: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80800538: nop

    // 0x8080053C: bc1f        L_8080055C
    if (!c1cs) {
        // 0x80800540: nop
    
            goto L_8080055C;
    }
    // 0x80800540: nop

    // 0x80800544: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x80800548: nop

    // 0x8080054C: bc1f        L_8080055C
    if (!c1cs) {
        // 0x80800550: nop
    
            goto L_8080055C;
    }
    // 0x80800550: nop

    // 0x80800554: jr          $ra
    // 0x80800558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080055C:
    // 0x8080055C: jr          $ra
    // 0x80800560: nop

    return;
    // 0x80800560: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080104C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801050: jal         0x80800234
    // 0x80801054: nop

    func_80800234_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x80801054: nop

    after_0:
    // 0x80801058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080105C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801060: jr          $ra
    // 0x80801064: nop

    return;
    // 0x80801064: nop

;}
RECOMP_FUNC void _ncfixposrot_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089248: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x80089248);
    return;
    // 0x8008924C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800F822C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F822C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800F8230: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800F8234: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8238: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F823C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8244: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F8248: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800F824C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800F8250: jal         0x80084D50
    // 0x800F8254: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _bahold_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x800F8254: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F8258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F825C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8260: jr          $ra
    // 0x800F8264: nop

    return;
    // 0x800F8264: nop

;}
RECOMP_FUNC void func_80800024_chbigterrysbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800028: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800030: jal         0x800D395C
    // 0x80800034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D395C(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800038: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080003C: jal         0x800DA298
    // 0x80800040: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    after_1:
    // 0x80800044: jal         0x800F54E4
    // 0x80800048: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800048: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800050: jal         0x800F64A4
    // 0x80800054: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_3:
    // 0x80800058: bnel        $v0, $zero, L_80800070
    if (ctx->r2 != 0) {
        // 0x8080005C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800070;
    }
    goto skip_0;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800060: jal         0x80088848
    // 0x80800064: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800064: nop

    after_4:
    // 0x80800068: beq         $v0, $zero, L_80800078
    if (ctx->r2 == 0) {
        // 0x8080006C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800078;
    }
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800070:
    // 0x80800070: jal         0x80101FDC
    // 0x80800074: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800074: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_80800078:
    // 0x80800078: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8080007C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800088: jal         0x8010A800
    // 0x8080008C: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    func_8010A800(rdram, ctx);
        goto after_6;
    // 0x8080008C: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    after_6:
    // 0x80800090: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800094: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800098: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8080009C: addiu       $t6, $zero, 0x802
    ctx->r14 = ADD32(0, 0X802);
    // 0x808000A0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x808000A4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808000A8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808000AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808000B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808000BC: jal         0x80086898
    // 0x808000C0: lui         $a3, 0xC3C8
    ctx->r7 = S32(0XC3C8 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808000C0: lui         $a3, 0xC3C8
    ctx->r7 = S32(0XC3C8 << 16);
    after_7:
    // 0x808000C4: beq         $v0, $zero, L_808000F0
    if (ctx->r2 == 0) {
        // 0x808000C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F0;
    }
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x800868A8
    // 0x808000D0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x808000D0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_8:
    // 0x808000D4: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808000D8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808000DC: jal         0x800868B0
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_9;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x800868C0
    // 0x808000EC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_10;
    // 0x808000EC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_10:
L_808000F0:
    // 0x808000F0: jal         0x80088848
    // 0x808000F4: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_11;
    // 0x808000F4: nop

    after_11:
    // 0x808000F8: bne         $v0, $zero, L_8080011C
    if (ctx->r2 != 0) {
        // 0x808000FC: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_8080011C;
    }
    // 0x808000FC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800100: beq         $t8, $zero, L_8080011C
    if (ctx->r24 == 0) {
        // 0x80800104: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_8080011C;
    }
    // 0x80800104: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800108: bne         $t9, $zero, L_8080011C
    if (ctx->r25 != 0) {
        // 0x8080010C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080011C;
    }
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800114: jal         0x8010108C
    // 0x80800118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_12;
    // 0x80800118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
L_8080011C:
    // 0x8080011C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800120: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void func_800E42E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E42E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E42E8: jr          $ra
    // 0x800E42EC: sw          $a0, -0x2AF8($at)
    MEM_W(-0X2AF8, ctx->r1) = ctx->r4;
    return;
    // 0x800E42EC: sw          $a0, -0x2AF8($at)
    MEM_W(-0X2AF8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _gccubesearch_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088308: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x80088308);
    return;
    // 0x8008830C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_800DFF64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFF64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DFF68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFF6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DFF70: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800DFF74: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800DFF78: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x800DFF7C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800DFF80: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x800DFF84: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800DFF88: jal         0x800EE7F8
    // 0x800DFF8C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800DFF8C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800DFF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFF94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DFF98: jr          $ra
    // 0x800DFF9C: nop

    return;
    // 0x800DFF9C: nop

;}
RECOMP_FUNC void plcamera_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: jal         0x800F5EF8
    // 0x8080013C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x8080013C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800140: jal         0x80110014
    // 0x80800144: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x80800144: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080014C: jal         0x80110770
    // 0x80800150: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80110770(rdram, ctx);
        goto after_2;
    // 0x80800150: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

;}
RECOMP_FUNC void func_80801534_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080153C: jal         0x80100094
    // 0x80801540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801544: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80801548: beql        $t6, $zero, L_8080155C
    if (ctx->r14 == 0) {
        // 0x8080154C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080155C;
    }
    goto skip_0;
    // 0x8080154C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801550: jal         0x801042D8
    // 0x80801554: addiu       $a0, $v0, 0x2
    ctx->r4 = ADD32(ctx->r2, 0X2);
    func_801042D8(rdram, ctx);
        goto after_1;
    // 0x80801554: addiu       $a0, $v0, 0x2
    ctx->r4 = ADD32(ctx->r2, 0X2);
    after_1:
    // 0x80801558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080155C:
    // 0x8080155C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801560: jr          $ra
    // 0x80801564: nop

    return;
    // 0x80801564: nop

;}
RECOMP_FUNC void func_808019C8_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808019CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808019D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808019D4: lui         $a2, 0x3F1E
    ctx->r6 = S32(0X3F1E << 16);
    // 0x808019D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808019DC: ori         $a2, $a2, 0xB852
    ctx->r6 = ctx->r6 | 0XB852;
    // 0x808019E0: jal         0x8008CB3C
    // 0x808019E4: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x808019E4: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_0:
    // 0x808019E8: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x808019EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808019F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808019F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808019FC: jal         0x8009FFD8
    // 0x80801A00: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80801A00: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80801A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A08: jal         0x800A0CF4
    // 0x80801A0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x80801A0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A14: jal         0x800A4DA4
    // 0x80801A18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800A4DA4(rdram, ctx);
        goto after_3;
    // 0x80801A18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80801A1C: jal         0x80800128
    // 0x80801A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800128_bskazfly(rdram, ctx);
        goto after_4;
    // 0x80801A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801A24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801A28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801A2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801A30: jr          $ra
    // 0x80801A34: nop

    return;
    // 0x80801A34: nop

;}
RECOMP_FUNC void func_80105DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105DFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80105E00: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80105E04: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80105E08: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80105E0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80105E10: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80105E14: lh          $t6, 0x90($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X90);
    // 0x80105E18: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80105E1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80105E20: bne         $t6, $zero, L_801060CC
    if (ctx->r14 != 0) {
        // 0x80105E24: addiu       $s2, $s2, 0x6ED0
        ctx->r18 = ADD32(ctx->r18, 0X6ED0);
            goto L_801060CC;
    }
    // 0x80105E24: addiu       $s2, $s2, 0x6ED0
    ctx->r18 = ADD32(ctx->r18, 0X6ED0);
    // 0x80105E28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80105E2C: jal         0x800B3044
    // 0x80105E30: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    freelist_next(rdram, ctx);
        goto after_0;
    // 0x80105E30: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80105E34: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80105E38: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80105E3C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80105E40: sh          $t7, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r15;
    // 0x80105E44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80105E48: jal         0x800888A0
    // 0x80105E4C: lhu         $a0, 0x14($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X14);
    _glidmake_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80105E4C: lhu         $a0, 0x14($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X14);
    after_1:
    // 0x80105E50: bne         $v0, $zero, L_80105E6C
    if (ctx->r2 != 0) {
        // 0x80105E54: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_80105E6C;
    }
    // 0x80105E54: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80105E58: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80105E5C: jal         0x800B32C0
    // 0x80105E60: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    freelist_erase(rdram, ctx);
        goto after_2;
    // 0x80105E60: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80105E64: b           L_801060CC
    // 0x80105E68: sh          $zero, 0x90($s0)
    MEM_H(0X90, ctx->r16) = 0;
        goto L_801060CC;
    // 0x80105E68: sh          $zero, 0x90($s0)
    MEM_H(0X90, ctx->r16) = 0;
L_80105E6C:
    // 0x80105E6C: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    // 0x80105E70: jal         0x800B2D70
    // 0x80105E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    vector_new(rdram, ctx);
        goto after_3;
    // 0x80105E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80105E78: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80105E7C: jal         0x80088880
    // 0x80105E80: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    _glidmake_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80105E80: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_4:
    // 0x80105E84: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80105E88: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80105E8C: addiu       $s1, $v0, 0x2
    ctx->r17 = ADD32(ctx->r2, 0X2);
    // 0x80105E90: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80105E94: blezl       $t9, L_801060D0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80105E98: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801060D0;
    }
    goto skip_0;
    // 0x80105E98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_80105E9C:
    // 0x80105E9C: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    // 0x80105EA0: slti        $at, $a1, 0x65
    ctx->r1 = SIGNED(ctx->r5) < 0X65 ? 1 : 0;
    // 0x80105EA4: bne         $at, $zero, L_80105ECC
    if (ctx->r1 != 0) {
        // 0x80105EA8: slti        $at, $a1, 0xC8
        ctx->r1 = SIGNED(ctx->r5) < 0XC8 ? 1 : 0;
            goto L_80105ECC;
    }
    // 0x80105EA8: slti        $at, $a1, 0xC8
    ctx->r1 = SIGNED(ctx->r5) < 0XC8 ? 1 : 0;
    // 0x80105EAC: beq         $at, $zero, L_80105ECC
    if (ctx->r1 == 0) {
        // 0x80105EB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80105ECC;
    }
    // 0x80105EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105EB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80105EB8: addiu       $a3, $a1, -0x64
    ctx->r7 = ADD32(ctx->r5, -0X64);
    // 0x80105EBC: jal         0x80106320
    // 0x80105EC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_5;
    // 0x80105EC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80105EC4: b           L_801060AC
    // 0x80105EC8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_801060AC;
    // 0x80105EC8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80105ECC:
    // 0x80105ECC: slti        $at, $a1, 0xC8
    ctx->r1 = SIGNED(ctx->r5) < 0XC8 ? 1 : 0;
    // 0x80105ED0: bne         $at, $zero, L_80105EF8
    if (ctx->r1 != 0) {
        // 0x80105ED4: slti        $at, $a1, 0x12C
        ctx->r1 = SIGNED(ctx->r5) < 0X12C ? 1 : 0;
            goto L_80105EF8;
    }
    // 0x80105ED4: slti        $at, $a1, 0x12C
    ctx->r1 = SIGNED(ctx->r5) < 0X12C ? 1 : 0;
    // 0x80105ED8: beq         $at, $zero, L_80105EF8
    if (ctx->r1 == 0) {
        // 0x80105EDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80105EF8;
    }
    // 0x80105EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105EE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80105EE4: addiu       $a3, $a1, -0xC8
    ctx->r7 = ADD32(ctx->r5, -0XC8);
    // 0x80105EE8: jal         0x80106320
    // 0x80105EEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_6;
    // 0x80105EEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80105EF0: b           L_801060AC
    // 0x80105EF4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_801060AC;
    // 0x80105EF4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80105EF8:
    // 0x80105EF8: slti        $at, $a1, 0x12C
    ctx->r1 = SIGNED(ctx->r5) < 0X12C ? 1 : 0;
    // 0x80105EFC: bne         $at, $zero, L_80105F24
    if (ctx->r1 != 0) {
        // 0x80105F00: slti        $at, $a1, 0x190
        ctx->r1 = SIGNED(ctx->r5) < 0X190 ? 1 : 0;
            goto L_80105F24;
    }
    // 0x80105F00: slti        $at, $a1, 0x190
    ctx->r1 = SIGNED(ctx->r5) < 0X190 ? 1 : 0;
    // 0x80105F04: beq         $at, $zero, L_80105F24
    if (ctx->r1 == 0) {
        // 0x80105F08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80105F24;
    }
    // 0x80105F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105F0C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80105F10: addiu       $a3, $a1, -0x12C
    ctx->r7 = ADD32(ctx->r5, -0X12C);
    // 0x80105F14: jal         0x80106320
    // 0x80105F18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_7;
    // 0x80105F18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80105F1C: b           L_801060AC
    // 0x80105F20: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_801060AC;
    // 0x80105F20: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80105F24:
    // 0x80105F24: slti        $at, $a1, 0x190
    ctx->r1 = SIGNED(ctx->r5) < 0X190 ? 1 : 0;
    // 0x80105F28: bne         $at, $zero, L_80105F50
    if (ctx->r1 != 0) {
        // 0x80105F2C: slti        $at, $a1, 0x1F4
        ctx->r1 = SIGNED(ctx->r5) < 0X1F4 ? 1 : 0;
            goto L_80105F50;
    }
    // 0x80105F2C: slti        $at, $a1, 0x1F4
    ctx->r1 = SIGNED(ctx->r5) < 0X1F4 ? 1 : 0;
    // 0x80105F30: beq         $at, $zero, L_80105F50
    if (ctx->r1 == 0) {
        // 0x80105F34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80105F50;
    }
    // 0x80105F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105F38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80105F3C: addiu       $a3, $a1, -0x190
    ctx->r7 = ADD32(ctx->r5, -0X190);
    // 0x80105F40: jal         0x80106320
    // 0x80105F44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_8;
    // 0x80105F44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80105F48: b           L_801060AC
    // 0x80105F4C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_801060AC;
    // 0x80105F4C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80105F50:
    // 0x80105F50: slti        $at, $a1, 0x1F4
    ctx->r1 = SIGNED(ctx->r5) < 0X1F4 ? 1 : 0;
    // 0x80105F54: bne         $at, $zero, L_80105F7C
    if (ctx->r1 != 0) {
        // 0x80105F58: slti        $at, $a1, 0x258
        ctx->r1 = SIGNED(ctx->r5) < 0X258 ? 1 : 0;
            goto L_80105F7C;
    }
    // 0x80105F58: slti        $at, $a1, 0x258
    ctx->r1 = SIGNED(ctx->r5) < 0X258 ? 1 : 0;
    // 0x80105F5C: beq         $at, $zero, L_80105F7C
    if (ctx->r1 == 0) {
        // 0x80105F60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80105F7C;
    }
    // 0x80105F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105F64: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80105F68: addiu       $a3, $a1, -0x1F4
    ctx->r7 = ADD32(ctx->r5, -0X1F4);
    // 0x80105F6C: jal         0x80106320
    // 0x80105F70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_9;
    // 0x80105F70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x80105F74: b           L_801060AC
    // 0x80105F78: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_801060AC;
    // 0x80105F78: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80105F7C:
    // 0x80105F7C: slti        $at, $a1, 0x258
    ctx->r1 = SIGNED(ctx->r5) < 0X258 ? 1 : 0;
    // 0x80105F80: bne         $at, $zero, L_80105FA8
    if (ctx->r1 != 0) {
        // 0x80105F84: slti        $at, $a1, 0x2BC
        ctx->r1 = SIGNED(ctx->r5) < 0X2BC ? 1 : 0;
            goto L_80105FA8;
    }
    // 0x80105F84: slti        $at, $a1, 0x2BC
    ctx->r1 = SIGNED(ctx->r5) < 0X2BC ? 1 : 0;
    // 0x80105F88: beq         $at, $zero, L_80105FA8
    if (ctx->r1 == 0) {
        // 0x80105F8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80105FA8;
    }
    // 0x80105F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105F90: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80105F94: addiu       $a3, $a1, -0x258
    ctx->r7 = ADD32(ctx->r5, -0X258);
    // 0x80105F98: jal         0x80106320
    // 0x80105F9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_10;
    // 0x80105F9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_10:
    // 0x80105FA0: b           L_801060AC
    // 0x80105FA4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_801060AC;
    // 0x80105FA4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80105FA8:
    // 0x80105FA8: slti        $at, $a1, 0x2BC
    ctx->r1 = SIGNED(ctx->r5) < 0X2BC ? 1 : 0;
    // 0x80105FAC: bne         $at, $zero, L_80105FD4
    if (ctx->r1 != 0) {
        // 0x80105FB0: slti        $at, $a1, 0x320
        ctx->r1 = SIGNED(ctx->r5) < 0X320 ? 1 : 0;
            goto L_80105FD4;
    }
    // 0x80105FB0: slti        $at, $a1, 0x320
    ctx->r1 = SIGNED(ctx->r5) < 0X320 ? 1 : 0;
    // 0x80105FB4: beq         $at, $zero, L_80105FD4
    if (ctx->r1 == 0) {
        // 0x80105FB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80105FD4;
    }
    // 0x80105FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105FBC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80105FC0: addiu       $a3, $a1, -0x2BC
    ctx->r7 = ADD32(ctx->r5, -0X2BC);
    // 0x80105FC4: jal         0x80106320
    // 0x80105FC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_11;
    // 0x80105FC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x80105FCC: b           L_801060AC
    // 0x80105FD0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_801060AC;
    // 0x80105FD0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80105FD4:
    // 0x80105FD4: slti        $at, $a1, 0x320
    ctx->r1 = SIGNED(ctx->r5) < 0X320 ? 1 : 0;
    // 0x80105FD8: bne         $at, $zero, L_80106000
    if (ctx->r1 != 0) {
        // 0x80105FDC: slti        $at, $a1, 0x384
        ctx->r1 = SIGNED(ctx->r5) < 0X384 ? 1 : 0;
            goto L_80106000;
    }
    // 0x80105FDC: slti        $at, $a1, 0x384
    ctx->r1 = SIGNED(ctx->r5) < 0X384 ? 1 : 0;
    // 0x80105FE0: beq         $at, $zero, L_80106000
    if (ctx->r1 == 0) {
        // 0x80105FE4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80106000;
    }
    // 0x80105FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105FE8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80105FEC: addiu       $a3, $a1, -0x320
    ctx->r7 = ADD32(ctx->r5, -0X320);
    // 0x80105FF0: jal         0x80106320
    // 0x80105FF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_12;
    // 0x80105FF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_12:
    // 0x80105FF8: b           L_801060AC
    // 0x80105FFC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_801060AC;
    // 0x80105FFC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80106000:
    // 0x80106000: slti        $at, $a1, 0x384
    ctx->r1 = SIGNED(ctx->r5) < 0X384 ? 1 : 0;
    // 0x80106004: bne         $at, $zero, L_8010602C
    if (ctx->r1 != 0) {
        // 0x80106008: slti        $at, $a1, 0x3E8
        ctx->r1 = SIGNED(ctx->r5) < 0X3E8 ? 1 : 0;
            goto L_8010602C;
    }
    // 0x80106008: slti        $at, $a1, 0x3E8
    ctx->r1 = SIGNED(ctx->r5) < 0X3E8 ? 1 : 0;
    // 0x8010600C: beq         $at, $zero, L_8010602C
    if (ctx->r1 == 0) {
        // 0x80106010: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010602C;
    }
    // 0x80106010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106014: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80106018: addiu       $a3, $a1, -0x384
    ctx->r7 = ADD32(ctx->r5, -0X384);
    // 0x8010601C: jal         0x80106320
    // 0x80106020: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_13;
    // 0x80106020: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x80106024: b           L_801060AC
    // 0x80106028: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_801060AC;
    // 0x80106028: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_8010602C:
    // 0x8010602C: slti        $at, $a1, 0x4B0
    ctx->r1 = SIGNED(ctx->r5) < 0X4B0 ? 1 : 0;
    // 0x80106030: bne         $at, $zero, L_80106058
    if (ctx->r1 != 0) {
        // 0x80106034: slti        $at, $a1, 0x6A4
        ctx->r1 = SIGNED(ctx->r5) < 0X6A4 ? 1 : 0;
            goto L_80106058;
    }
    // 0x80106034: slti        $at, $a1, 0x6A4
    ctx->r1 = SIGNED(ctx->r5) < 0X6A4 ? 1 : 0;
    // 0x80106038: beq         $at, $zero, L_80106058
    if (ctx->r1 == 0) {
        // 0x8010603C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80106058;
    }
    // 0x8010603C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106040: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80106044: addiu       $a3, $a1, -0x4B0
    ctx->r7 = ADD32(ctx->r5, -0X4B0);
    // 0x80106048: jal         0x80106320
    // 0x8010604C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_14;
    // 0x8010604C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_14:
    // 0x80106050: b           L_801060AC
    // 0x80106054: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_801060AC;
    // 0x80106054: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80106058:
    // 0x80106058: slti        $at, $a1, 0x6A4
    ctx->r1 = SIGNED(ctx->r5) < 0X6A4 ? 1 : 0;
    // 0x8010605C: bne         $at, $zero, L_80106084
    if (ctx->r1 != 0) {
        // 0x80106060: slti        $at, $a1, 0x708
        ctx->r1 = SIGNED(ctx->r5) < 0X708 ? 1 : 0;
            goto L_80106084;
    }
    // 0x80106060: slti        $at, $a1, 0x708
    ctx->r1 = SIGNED(ctx->r5) < 0X708 ? 1 : 0;
    // 0x80106064: beq         $at, $zero, L_80106084
    if (ctx->r1 == 0) {
        // 0x80106068: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80106084;
    }
    // 0x80106068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010606C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80106070: addiu       $a3, $a1, -0x6A4
    ctx->r7 = ADD32(ctx->r5, -0X6A4);
    // 0x80106074: jal         0x80106320
    // 0x80106078: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_15;
    // 0x80106078: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_15:
    // 0x8010607C: b           L_801060AC
    // 0x80106080: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_801060AC;
    // 0x80106080: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80106084:
    // 0x80106084: slti        $at, $a1, 0x76C
    ctx->r1 = SIGNED(ctx->r5) < 0X76C ? 1 : 0;
    // 0x80106088: bne         $at, $zero, L_801060A8
    if (ctx->r1 != 0) {
        // 0x8010608C: slti        $at, $a1, 0x7D0
        ctx->r1 = SIGNED(ctx->r5) < 0X7D0 ? 1 : 0;
            goto L_801060A8;
    }
    // 0x8010608C: slti        $at, $a1, 0x7D0
    ctx->r1 = SIGNED(ctx->r5) < 0X7D0 ? 1 : 0;
    // 0x80106090: beq         $at, $zero, L_801060A8
    if (ctx->r1 == 0) {
        // 0x80106094: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801060A8;
    }
    // 0x80106094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106098: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8010609C: addiu       $a3, $a1, -0x76C
    ctx->r7 = ADD32(ctx->r5, -0X76C);
    // 0x801060A0: jal         0x80106320
    // 0x801060A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80106320(rdram, ctx);
        goto after_16;
    // 0x801060A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
L_801060A8:
    // 0x801060A8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_801060AC:
    // 0x801060AC: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x801060B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801060B4: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x801060B8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x801060BC: addu        $s1, $s1, $t1
    ctx->r17 = ADD32(ctx->r17, ctx->r9);
    // 0x801060C0: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801060C4: bne         $at, $zero, L_80105E9C
    if (ctx->r1 != 0) {
        // 0x801060C8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80105E9C;
    }
    // 0x801060C8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_801060CC:
    // 0x801060CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801060D0:
    // 0x801060D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801060D4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801060D8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801060DC: jr          $ra
    // 0x801060E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801060E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_808015A0_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808015A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808015A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808015AC: jal         0x8008CABC
    // 0x808015B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808015B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808015B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808015B8: jal         0x808009B0
    // 0x808015BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009B0_bssub(rdram, ctx);
        goto after_1;
    // 0x808015BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808015C0: jal         0x8008B264
    // 0x808015C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_getIndex(rdram, ctx);
        goto after_2;
    // 0x808015C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808015C8: addiu       $at, $zero, 0x12E
    ctx->r1 = ADD32(0, 0X12E);
    // 0x808015CC: bne         $v0, $at, L_808015E8
    if (ctx->r2 != ctx->r1) {
        // 0x808015D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015E8;
    }
    // 0x808015D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808015D8: jal         0x8008B1BC
    // 0x808015DC: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x808015DC: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_3:
    // 0x808015E0: b           L_808015F4
    // 0x808015E4: nop

        goto L_808015F4;
    // 0x808015E4: nop

L_808015E8:
    // 0x808015E8: addiu       $a1, $zero, 0x12E
    ctx->r5 = ADD32(0, 0X12E);
    // 0x808015EC: jal         0x8008CB3C
    // 0x808015F0: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_4;
    // 0x808015F0: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    after_4:
L_808015F4:
    // 0x808015F4: jal         0x800909CC
    // 0x808015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_5;
    // 0x808015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808015FC: jal         0x80800000
    // 0x80801600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bssub(rdram, ctx);
        goto after_6;
    // 0x80801600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801608: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080160C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801610: jr          $ra
    // 0x80801614: nop

    return;
    // 0x80801614: nop

;}
RECOMP_FUNC void badata_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800944: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800948: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8080094C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800950: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800958: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X2378) << 16);
    // 0x8080095C: jal         0x808006AC
    // 0x80800960: addiu       $a1, $a1, 0x2378
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X2378));
    func_808006AC_badata(rdram, ctx);
        goto after_0;
    // 0x80800960: addiu       $a1, $a1, 0x2378
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X2378));
    after_0:
    // 0x80800964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800968: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080096C: jr          $ra
    // 0x80800970: nop

    return;
    // 0x80800970: nop

;}
RECOMP_FUNC void func_80801BA8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801BAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801BB0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80801BB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801BB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801BBC: beq         $a1, $at, L_80801CB8
    if (ctx->r5 == ctx->r1) {
        // 0x80801BC0: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80801CB8;
    }
    // 0x80801BC0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801BC4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80801BC8: beq         $a1, $at, L_80801D18
    if (ctx->r5 == ctx->r1) {
        // 0x80801BCC: addiu       $at, $zero, 0x21
        ctx->r1 = ADD32(0, 0X21);
            goto L_80801D18;
    }
    // 0x80801BCC: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80801BD0: beq         $a1, $at, L_80801D2C
    if (ctx->r5 == ctx->r1) {
        // 0x80801BD4: addiu       $v0, $sp, 0x30
        ctx->r2 = ADD32(ctx->r29, 0X30);
            goto L_80801D2C;
    }
    // 0x80801BD4: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80801BD8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801BDC: bne         $a1, $at, L_80801D54
    if (ctx->r5 != ctx->r1) {
        // 0x80801BE0: nop
    
            goto L_80801D54;
    }
    // 0x80801BE0: nop

    // 0x80801BE4: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x80801BE8: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(804, 0X80A8) << 16);
    // 0x80801BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801BF0: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80801BF4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80801BF8: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80801BFC: jal         0x801032B0
    // 0x80801C00: lhu         $a1, -0x7F58($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(804, 0X80A8));
    func_801032B0(rdram, ctx);
        goto after_0;
    // 0x80801C00: lhu         $a1, -0x7F58($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(804, 0X80A8));
    after_0:
    // 0x80801C04: jal         0x80104248
    // 0x80801C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_1;
    // 0x80801C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801C0C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801C10: jal         0x8008B304
    // 0x80801C14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B304(rdram, ctx);
        goto after_2;
    // 0x80801C14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801C18: jal         0x801039E4
    // 0x80801C1C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_3;
    // 0x80801C1C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80801C20: jal         0x800B27E0
    // 0x80801C24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_4;
    // 0x80801C24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80801C28: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80801C2C: jal         0x8008AEDC
    // 0x80801C30: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8008AEDC(rdram, ctx);
        goto after_5;
    // 0x80801C30: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80801C34: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80801C38: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801C3C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801C40: jal         0x8008C200
    // 0x80801C44: lh          $a0, 0x10($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X10);
    func_8008C200(rdram, ctx);
        goto after_6;
    // 0x80801C44: lh          $a0, 0x10($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X10);
    after_6:
    // 0x80801C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C4C: jal         0x80102424
    // 0x80801C50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80801C50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80801C54: lbu         $a1, 0x79($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X79);
    // 0x80801C58: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801C5C: srl         $t0, $a1, 4
    ctx->r8 = S32(U32(ctx->r5) >> 4);
    // 0x80801C60: beq         $t0, $at, L_80801C78
    if (ctx->r8 == ctx->r1) {
        // 0x80801C64: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80801C78;
    }
    // 0x80801C64: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80801C68: beq         $t0, $at, L_80801C98
    if (ctx->r8 == ctx->r1) {
        // 0x80801C6C: nop
    
            goto L_80801C98;
    }
    // 0x80801C6C: nop

    // 0x80801C70: b           L_80801D60
    // 0x80801C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801D60;
    // 0x80801C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C78:
    // 0x80801C78: jal         0x80088138
    // 0x80801C7C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80801C7C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_8:
    // 0x80801C80: bne         $v0, $zero, L_80801D5C
    if (ctx->r2 != 0) {
        // 0x80801C84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801D5C;
    }
    // 0x80801C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C88: jal         0x80089C98
    // 0x80801C8C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80801C8C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_9:
    // 0x80801C90: b           L_80801D60
    // 0x80801C94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801D60;
    // 0x80801C94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C98:
    // 0x80801C98: jal         0x80088140
    // 0x80801C9C: nop

    _gcfrontend_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80801C9C: nop

    after_10:
    // 0x80801CA0: bne         $v0, $zero, L_80801D5C
    if (ctx->r2 != 0) {
        // 0x80801CA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801D5C;
    }
    // 0x80801CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CA8: jal         0x80089C98
    // 0x80801CAC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80801CAC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_11:
    // 0x80801CB0: b           L_80801D60
    // 0x80801CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801D60;
    // 0x80801CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801CB8:
    // 0x80801CB8: lbu         $t2, 0x79($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X79);
    // 0x80801CBC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80801CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801CC4: srl         $t3, $t2, 4
    ctx->r11 = S32(U32(ctx->r10) >> 4);
    // 0x80801CC8: bne         $t1, $t3, L_80801CD8
    if (ctx->r9 != ctx->r11) {
        // 0x80801CCC: nop
    
            goto L_80801CD8;
    }
    // 0x80801CCC: nop

    // 0x80801CD0: b           L_80801CD8
    // 0x80801CD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80801CD8;
    // 0x80801CD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80801CD8:
    // 0x80801CD8: jal         0x80802070
    // 0x80801CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802070_chgameselect(rdram, ctx);
        goto after_12;
    // 0x80801CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801CE0: lbu         $t5, 0x79($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X79);
    // 0x80801CE4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80801CE8: lui         $a0, 0x8081
    ctx->r4 = S32(RELOC_HI16(804, 0X80AA) << 16);
    // 0x80801CEC: srl         $t6, $t5, 4
    ctx->r14 = S32(U32(ctx->r13) >> 4);
    // 0x80801CF0: bne         $t4, $t6, L_80801D5C
    if (ctx->r12 != ctx->r14) {
        // 0x80801CF4: sll         $t7, $t4, 2
        ctx->r15 = S32(ctx->r12 << 2);
            goto L_80801D5C;
    }
    // 0x80801CF4: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80801CF8: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80801CFC: lh          $a0, -0x7F56($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(804, 0X80AA));
    // 0x80801D00: bltzl       $a0, L_80801D60
    if (SIGNED(ctx->r4) < 0) {
        // 0x80801D04: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801D60;
    }
    goto skip_0;
    // 0x80801D04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80801D08: jal         0x80803D00
    // 0x80801D0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80803D00_chgameselect(rdram, ctx);
        goto after_13;
    // 0x80801D0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x80801D10: b           L_80801D60
    // 0x80801D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801D60;
    // 0x80801D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801D18:
    // 0x80801D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D1C: jal         0x80801D74
    // 0x80801D20: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80801D74_chgameselect(rdram, ctx);
        goto after_14;
    // 0x80801D20: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_14:
    // 0x80801D24: b           L_80801D60
    // 0x80801D28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801D60;
    // 0x80801D28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801D2C:
    // 0x80801D2C: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x80801D30: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x80801D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D38: srl         $t9, $t8, 4
    ctx->r25 = S32(U32(ctx->r24) >> 4);
    // 0x80801D3C: bne         $t9, $t0, L_80801D54
    if (ctx->r25 != ctx->r8) {
        // 0x80801D40: nop
    
            goto L_80801D54;
    }
    // 0x80801D40: nop

    // 0x80801D44: jal         0x808020CC
    // 0x80801D48: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    func_808020CC_chgameselect(rdram, ctx);
        goto after_15;
    // 0x80801D48: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    after_15:
    // 0x80801D4C: b           L_80801D60
    // 0x80801D50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801D60;
    // 0x80801D50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801D54:
    // 0x80801D54: b           L_80801D60
    // 0x80801D58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801D60;
    // 0x80801D58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801D5C:
    // 0x80801D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801D60:
    // 0x80801D60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801D68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801D6C: jr          $ra
    // 0x80801D70: nop

    return;
    // 0x80801D70: nop

;}
RECOMP_FUNC void badrone_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080027C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800280: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800284: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080028C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800290: lw          $a0, 0x54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54);
    // 0x80800294: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800298: jal         0x800EE7F8
    // 0x8080029C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080029C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x808002A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002A4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808002A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808002AC: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x808002B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808002B4: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x808002B8: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x808002BC: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x808002C0: lw          $t9, 0x54($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X54);
    // 0x808002C4: jal         0x800846E8
    // 0x808002C8: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
    _badata_entrypoint_21(rdram, ctx);
        goto after_1;
    // 0x808002C8: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
    after_1:
    // 0x808002CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002D0: jal         0x8009E5C8
    // 0x808002D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x808002D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x808002D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void chdodgemcontrol_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804998: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1752, 0X4FAC) << 16);
    // 0x8080499C: jr          $ra
    // 0x808049A0: addiu       $v0, $v0, 0x4FAC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1752, 0X4FAC));
    return;
    // 0x808049A0: addiu       $v0, $v0, 0x4FAC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1752, 0X4FAC));
    // 0x808049A4: nop

    // 0x808049A8: nop

    // 0x808049AC: nop

;}
RECOMP_FUNC void _suspline_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DC0: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DC0);
    return;
    // 0x80089DC4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_808064F4_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808064F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808064F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808064FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80806500: jal         0x800EB854
    // 0x80806504: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EB854(rdram, ctx);
        goto after_0;
    // 0x80806504: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80806508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080650C: bne         $v0, $zero, L_80806524
    if (ctx->r2 != 0) {
        // 0x80806510: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80806524;
    }
    // 0x80806510: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80806514: jal         0x801018A4
    // 0x80806518: nop

    func_801018A4(rdram, ctx);
        goto after_1;
    // 0x80806518: nop

    after_1:
    // 0x8080651C: b           L_80806530
    // 0x80806520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80806530;
    // 0x80806520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806524:
    // 0x80806524: jal         0x808002F0
    // 0x80806528: nop

    func_808002F0_chquiz(rdram, ctx);
        goto after_2;
    // 0x80806528: nop

    after_2:
    // 0x8080652C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806530:
    // 0x80806530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806534: jr          $ra
    // 0x80806538: nop

    return;
    // 0x80806538: nop

;}
RECOMP_FUNC void func_8002597C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002597C: addiu       $sp, $sp, -0x3D8
    ctx->r29 = ADD32(ctx->r29, -0X3D8);
    // 0x80025980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025984: sw          $a0, 0x3D8($sp)
    MEM_W(0X3D8, ctx->r29) = ctx->r4;
    // 0x80025988: sw          $a1, 0x3DC($sp)
    MEM_W(0X3DC, ctx->r29) = ctx->r5;
    // 0x8002598C: sw          $a2, 0x3E0($sp)
    MEM_W(0X3E0, ctx->r29) = ctx->r6;
    // 0x80025990: sw          $a3, 0x3E4($sp)
    MEM_W(0X3E4, ctx->r29) = ctx->r7;
    // 0x80025994: lw          $t6, 0x3D8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3D8);
    // 0x80025998: addiu       $a0, $sp, 0x1F0
    ctx->r4 = ADD32(ctx->r29, 0X1F0);
    // 0x8002599C: jal         0x80024EE0
    // 0x800259A0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_80024EE0(rdram, ctx);
        goto after_0;
    // 0x800259A0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800259A4: lw          $t7, 0x3E0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3E0);
    // 0x800259A8: sw          $zero, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = 0;
    // 0x800259AC: beq         $t7, $zero, L_800259F8
    if (ctx->r15 == 0) {
        // 0x800259B0: nop
    
            goto L_800259F8;
    }
    // 0x800259B0: nop

L_800259B4:
    // 0x800259B4: lw          $t9, 0x1E8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1E8);
    // 0x800259B8: lw          $t8, 0x3DC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3DC);
    // 0x800259BC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800259C0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800259C4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800259C8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800259CC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800259D0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800259D4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800259D8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800259DC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800259E0: lw          $t2, 0x1E8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1E8);
    // 0x800259E4: lw          $t4, 0x3E0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3E0);
    // 0x800259E8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800259EC: sltu        $at, $t3, $t4
    ctx->r1 = ctx->r11 < ctx->r12 ? 1 : 0;
    // 0x800259F0: bne         $at, $zero, L_800259B4
    if (ctx->r1 != 0) {
        // 0x800259F4: sw          $t3, 0x1E8($sp)
        MEM_W(0X1E8, ctx->r29) = ctx->r11;
            goto L_800259B4;
    }
    // 0x800259F4: sw          $t3, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->r11;
L_800259F8:
    // 0x800259F8: lw          $t5, 0x1F4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1F4);
    // 0x800259FC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80025A00: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
    // 0x80025A04: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80025A08: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
    // 0x80025A0C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80025A10: lw          $t9, 0x3D8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3D8);
    // 0x80025A14: sw          $zero, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = 0;
    // 0x80025A18: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80025A1C: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80025A20: beq         $t0, $zero, L_80025ABC
    if (ctx->r8 == 0) {
        // 0x80025A24: nop
    
            goto L_80025ABC;
    }
    // 0x80025A24: nop

L_80025A28:
    // 0x80025A28: lw          $t1, 0x1EC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1EC);
    // 0x80025A2C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80025A30: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x80025A34: lw          $t3, 0x208($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X208);
    // 0x80025A38: addu        $t4, $sp, $t2
    ctx->r12 = ADD32(ctx->r29, ctx->r10);
    // 0x80025A3C: sw          $t3, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r11;
    // 0x80025A40: lw          $t5, 0x1EC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1EC);
    // 0x80025A44: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80025A48: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x80025A4C: lw          $t7, 0x288($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X288);
    // 0x80025A50: addu        $t9, $sp, $t6
    ctx->r25 = ADD32(ctx->r29, ctx->r14);
    // 0x80025A54: sw          $t7, 0xA8($t9)
    MEM_W(0XA8, ctx->r25) = ctx->r15;
    // 0x80025A58: lw          $t8, 0x1EC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1EC);
    // 0x80025A5C: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x80025A60: lbu         $t0, 0x308($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X308);
    // 0x80025A64: addu        $t1, $sp, $t8
    ctx->r9 = ADD32(ctx->r29, ctx->r24);
    // 0x80025A68: sb          $t0, 0x128($t1)
    MEM_B(0X128, ctx->r9) = ctx->r8;
    // 0x80025A6C: lw          $t3, 0x1EC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1EC);
    // 0x80025A70: addu        $t2, $sp, $t3
    ctx->r10 = ADD32(ctx->r29, ctx->r11);
    // 0x80025A74: lbu         $t2, 0x328($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X328);
    // 0x80025A78: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x80025A7C: sb          $t2, 0x148($t4)
    MEM_B(0X148, ctx->r12) = ctx->r10;
    // 0x80025A80: lw          $t5, 0x1EC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1EC);
    // 0x80025A84: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80025A88: addu        $t6, $sp, $t7
    ctx->r14 = ADD32(ctx->r29, ctx->r15);
    // 0x80025A8C: lw          $t6, 0x348($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X348);
    // 0x80025A90: addu        $t9, $sp, $t7
    ctx->r25 = ADD32(ctx->r29, ctx->r15);
    // 0x80025A94: sw          $t6, 0x168($t9)
    MEM_W(0X168, ctx->r25) = ctx->r14;
    // 0x80025A98: lw          $t0, 0x1EC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1EC);
    // 0x80025A9C: lw          $t1, 0x3D8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3D8);
    // 0x80025AA0: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x80025AA4: sw          $t8, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->r24;
    // 0x80025AA8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80025AAC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80025AB0: sltu        $at, $t8, $t3
    ctx->r1 = ctx->r24 < ctx->r11 ? 1 : 0;
    // 0x80025AB4: bne         $at, $zero, L_80025A28
    if (ctx->r1 != 0) {
        // 0x80025AB8: nop
    
            goto L_80025A28;
    }
    // 0x80025AB8: nop

L_80025ABC:
    // 0x80025ABC: addiu       $a0, $sp, 0x1F0
    ctx->r4 = ADD32(ctx->r29, 0X1F0);
    // 0x80025AC0: addiu       $a1, $sp, 0x3C8
    ctx->r5 = ADD32(ctx->r29, 0X3C8);
    // 0x80025AC4: jal         0x80025084
    // 0x80025AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80025084(rdram, ctx);
        goto after_1;
    // 0x80025AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80025ACC: lh          $t4, 0x3C8($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3C8);
    // 0x80025AD0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80025AD4: bne         $t4, $at, L_80025BC8
    if (ctx->r12 != ctx->r1) {
        // 0x80025AD8: nop
    
            goto L_80025BC8;
    }
    // 0x80025AD8: nop

    // 0x80025ADC: lw          $t5, 0x3D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3D4);
    // 0x80025AE0: lw          $t7, 0x3E4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3E4);
    // 0x80025AE4: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x80025AE8: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x80025AEC: bne         $at, $zero, L_80025BC8
    if (ctx->r1 != 0) {
        // 0x80025AF0: nop
    
            goto L_80025BC8;
    }
    // 0x80025AF0: nop

    // 0x80025AF4: lw          $t9, 0x3E0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3E0);
    // 0x80025AF8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80025AFC: sltu        $at, $t6, $t0
    ctx->r1 = ctx->r14 < ctx->r8 ? 1 : 0;
    // 0x80025B00: beq         $at, $zero, L_80025BC8
    if (ctx->r1 == 0) {
        // 0x80025B04: nop
    
            goto L_80025BC8;
    }
    // 0x80025B04: nop

    // 0x80025B08: lw          $t1, 0x3D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3D4);
    // 0x80025B0C: lw          $t8, 0x3E4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3E4);
    // 0x80025B10: lw          $t5, 0x3DC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3DC);
    // 0x80025B14: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x80025B18: subu        $t3, $t2, $t8
    ctx->r11 = SUB32(ctx->r10, ctx->r24);
    // 0x80025B1C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80025B20: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80025B24: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80025B28: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80025B2C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80025B30: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80025B34: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80025B38: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80025B3C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80025B40: bne         $t9, $zero, L_80025BC8
    if (ctx->r25 != 0) {
        // 0x80025B44: nop
    
            goto L_80025BC8;
    }
    // 0x80025B44: nop

    // 0x80025B48: lw          $t6, 0x3D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3D4);
    // 0x80025B4C: lw          $t1, 0x3E4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3E4);
    // 0x80025B50: lw          $t3, 0x3DC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3DC);
    // 0x80025B54: sra         $t0, $t6, 8
    ctx->r8 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80025B58: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80025B5C: sll         $t8, $t2, 3
    ctx->r24 = S32(ctx->r10 << 3);
    // 0x80025B60: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x80025B64: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80025B68: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x80025B6C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80025B70: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x80025B74: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80025B78: addiu       $t4, $sp, 0x1C
    ctx->r12 = ADD32(ctx->r29, 0X1C);
    // 0x80025B7C: addiu       $t6, $t4, 0x1C8
    ctx->r14 = ADD32(ctx->r12, 0X1C8);
    // 0x80025B80: addu        $t5, $t3, $t8
    ctx->r13 = ADD32(ctx->r11, ctx->r24);
L_80025B84:
    // 0x80025B84: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x80025B88: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80025B8C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80025B90: sw          $t9, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r25;
    // 0x80025B94: lw          $t7, -0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, -0X8);
    // 0x80025B98: sw          $t7, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r15;
    // 0x80025B9C: lw          $t9, -0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, -0X4);
    // 0x80025BA0: bne         $t4, $t6, L_80025B84
    if (ctx->r12 != ctx->r14) {
        // 0x80025BA4: sw          $t9, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r25;
            goto L_80025B84;
    }
    // 0x80025BA4: sw          $t9, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r25;
    // 0x80025BA8: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x80025BAC: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80025BB0: lw          $t0, 0x1E8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1E8);
    // 0x80025BB4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80025BB8: bgtz        $t1, L_80025BC8
    if (SIGNED(ctx->r9) > 0) {
        // 0x80025BBC: sw          $t1, 0x1E8($sp)
        MEM_W(0X1E8, ctx->r29) = ctx->r9;
            goto L_80025BC8;
    }
    // 0x80025BBC: sw          $t1, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->r9;
    // 0x80025BC0: b           L_80025BE0
    // 0x80025BC4: nop

        goto L_80025BE0;
    // 0x80025BC4: nop

L_80025BC8:
    // 0x80025BC8: lh          $t2, 0x3C8($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3C8);
    // 0x80025BCC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80025BD0: bne         $t2, $at, L_800259F8
    if (ctx->r10 != ctx->r1) {
        // 0x80025BD4: nop
    
            goto L_800259F8;
    }
    // 0x80025BD4: nop

    // 0x80025BD8: b           L_80025BE0
    // 0x80025BDC: nop

        goto L_80025BE0;
    // 0x80025BDC: nop

L_80025BE0:
    // 0x80025BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025BE4: addiu       $sp, $sp, 0x3D8
    ctx->r29 = ADD32(ctx->r29, 0X3D8);
    // 0x80025BE8: jr          $ra
    // 0x80025BEC: nop

    return;
    // 0x80025BEC: nop

;}
RECOMP_FUNC void func_800E9BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9BF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9BF8: bltz        $a1, L_800E9C10
    if (SIGNED(ctx->r5) < 0) {
        // 0x800E9BFC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800E9C10;
    }
    // 0x800E9BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9C00: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800E9C04: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800E9C08: bne         $at, $zero, L_800E9C18
    if (ctx->r1 != 0) {
        // 0x800E9C0C: nop
    
            goto L_800E9C18;
    }
    // 0x800E9C0C: nop

L_800E9C10:
    // 0x800E9C10: b           L_800E9C34
    // 0x800E9C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E9C34;
    // 0x800E9C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E9C18:
    // 0x800E9C18: jal         0x800E9D68
    // 0x800E9C1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800E9D68(rdram, ctx);
        goto after_0;
    // 0x800E9C1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E9C20: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9C24: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800E9C28: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x800E9C2C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E9C30: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
L_800E9C34:
    // 0x800E9C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9C38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9C3C: jr          $ra
    // 0x800E9C40: nop

    return;
    // 0x800E9C40: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802440: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80802444: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80802448: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8080244C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80802450: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80802454: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80802458: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8080245C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80802460: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80802464: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80802468: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8080246C: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x80802470: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80802474: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80802478: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x8080247C: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80802480: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80802484: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x80802488: bne         $t6, $zero, L_80802498
    if (ctx->r14 != 0) {
        // 0x8080248C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80802498;
    }
    // 0x8080248C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80802490: b           L_8080257C
    // 0x80802494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080257C;
    // 0x80802494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802498:
    // 0x80802498: jal         0x800BEB58
    // 0x8080249C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEB58(rdram, ctx);
        goto after_0;
    // 0x8080249C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808024A0: lbu         $t7, 0x77($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X77);
    // 0x808024A4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x808024A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808024AC: blez        $t7, L_80802578
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808024B0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80802578;
    }
    // 0x808024B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808024B4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808024B8: lw          $s7, 0x88($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X88);
    // 0x808024BC: lw          $s6, 0x84($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X84);
    // 0x808024C0: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x808024C4: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
L_808024C8:
    // 0x808024C8: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x808024CC: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x808024D0: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x808024D4: bgezl       $t1, L_80802564
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808024D8: lbu         $t6, 0x77($s1)
        ctx->r14 = MEM_BU(ctx->r17, 0X77);
            goto L_80802564;
    }
    goto skip_0;
    // 0x808024D8: lbu         $t6, 0x77($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X77);
    skip_0:
    // 0x808024DC: jal         0x800D674C
    // 0x808024E0: lhu         $a0, 0x40($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X40);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x808024E0: lhu         $a0, 0x40($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X40);
    after_1:
    // 0x808024E4: beq         $v0, $zero, L_80802560
    if (ctx->r2 == 0) {
        // 0x808024E8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80802560;
    }
    // 0x808024E8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808024EC: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    // 0x808024F0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x808024F4: jal         0x800D62E4
    // 0x808024F8: lhu         $a0, 0x40($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X40);
    func_800D62E4(rdram, ctx);
        goto after_2;
    // 0x808024F8: lhu         $a0, 0x40($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X40);
    after_2:
    // 0x808024FC: jal         0x800B2720
    // 0x80802500: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800B2720(rdram, ctx);
        goto after_3;
    // 0x80802500: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80802504: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80802508: jal         0x800B2840
    // 0x8080250C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800B2840(rdram, ctx);
        goto after_4;
    // 0x8080250C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80802510: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x80802514: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80802518: sw          $s7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r23;
    // 0x8080251C: sw          $s6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r22;
    // 0x80802520: sw          $s5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r21;
    // 0x80802524: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80802528: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // 0x8080252C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80802530: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80802534: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080253C: addu        $a2, $t4, $s0
    ctx->r6 = ADD32(ctx->r12, ctx->r16);
    // 0x80802540: jal         0x800AC848
    // 0x80802544: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    func_800AC848(rdram, ctx);
        goto after_5;
    // 0x80802544: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_5:
    // 0x80802548: beq         $v0, $zero, L_80802560
    if (ctx->r2 == 0) {
        // 0x8080254C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80802560;
    }
    // 0x8080254C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80802550: jal         0x800BEB58
    // 0x80802554: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800BEB58(rdram, ctx);
        goto after_6;
    // 0x80802554: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80802558: b           L_8080257C
    // 0x8080255C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_8080257C;
    // 0x8080255C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_80802560:
    // 0x80802560: lbu         $t6, 0x77($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X77);
L_80802564:
    // 0x80802564: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80802568: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x8080256C: slt         $at, $s4, $t6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80802570: bnel        $at, $zero, L_808024C8
    if (ctx->r1 != 0) {
        // 0x80802574: lw          $t8, 0x68($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X68);
            goto L_808024C8;
    }
    goto skip_1;
    // 0x80802574: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    skip_1:
L_80802578:
    // 0x80802578: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_8080257C:
    // 0x8080257C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80802580: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80802584: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80802588: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8080258C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80802590: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80802594: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80802598: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8080259C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x808025A0: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x808025A4: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x808025A8: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x808025AC: jr          $ra
    // 0x808025B0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808025B0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80800634_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800634: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800638: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080063C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1204, 0XA44) << 16);
    // 0x80800640: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1204, 0X8F0) << 16);
    // 0x80800644: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80800648: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080064C: addiu       $a3, $a3, 0x8F0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1204, 0X8F0));
    // 0x80800650: addiu       $a2, $a2, 0xA44
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1204, 0XA44));
    // 0x80800654: jal         0x8008A1F0
    // 0x80800658: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800658: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8080065C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800660: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800664: jr          $ra
    // 0x80800668: nop

    return;
    // 0x80800668: nop

;}
RECOMP_FUNC void func_80029FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029FA0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80029FA4: lbu         $t7, 0x35($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X35);
    // 0x80029FA8: lw          $t6, 0x60($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X60);
    // 0x80029FAC: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x80029FB0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80029FB4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80029FB8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80029FBC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80029FC0: lbu         $t0, 0x3($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X3);
    // 0x80029FC4: lbu         $t2, 0xD4($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XD4);
    // 0x80029FC8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80029FCC: addiu       $t4, $t3, -0x40
    ctx->r12 = ADD32(ctx->r11, -0X40);
    // 0x80029FD0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80029FD4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80029FD8: blez        $t5, L_80029FE8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80029FDC: nop
    
            goto L_80029FE8;
    }
    // 0x80029FDC: nop

    // 0x80029FE0: b           L_80029FEC
    // 0x80029FE4: nop

        goto L_80029FEC;
    // 0x80029FE4: nop

L_80029FE8:
    // 0x80029FE8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80029FEC:
    // 0x80029FEC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80029FF0: slti        $at, $t7, 0x7F
    ctx->r1 = SIGNED(ctx->r15) < 0X7F ? 1 : 0;
    // 0x80029FF4: beq         $at, $zero, L_8002A004
    if (ctx->r1 == 0) {
        // 0x80029FF8: nop
    
            goto L_8002A004;
    }
    // 0x80029FF8: nop

    // 0x80029FFC: b           L_8002A00C
    // 0x8002A000: nop

        goto L_8002A00C;
    // 0x8002A000: nop

L_8002A004:
    // 0x8002A004: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x8002A008: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_8002A00C:
    // 0x8002A00C: b           L_8002A01C
    // 0x8002A010: lbu         $v0, 0x7($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X7);
        goto L_8002A01C;
    // 0x8002A010: lbu         $v0, 0x7($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X7);
    // 0x8002A014: b           L_8002A01C
    // 0x8002A018: nop

        goto L_8002A01C;
    // 0x8002A018: nop

L_8002A01C:
    // 0x8002A01C: jr          $ra
    // 0x8002A020: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002A020: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void _gcgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A48: syscall     651
    recomp_syscall_handler(rdram, ctx, 0x80087A48);
    return;
    // 0x80087A4C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void sukickball_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800CBC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800CC0: jal         0x80100094
    // 0x80800CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800CC8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CCC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800CD0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80800CD4: sb          $t6, 0x34($t8)
    MEM_B(0X34, ctx->r24) = ctx->r14;
    // 0x80800CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CE0: jr          $ra
    // 0x80800CE4: nop

    return;
    // 0x80800CE4: nop

;}
RECOMP_FUNC void func_80025ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025ED0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025ED8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80025EDC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80025EE0: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80025EE4: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80025EE8: lh          $t7, 0x2E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2E);
    // 0x80025EEC: sh          $t7, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r15;
    // 0x80025EF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80025EF4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80025EF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025EFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80025F00: jal         0x80026500
    // 0x80025F04: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x80025F04: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x80025F08: b           L_80025F10
    // 0x80025F0C: nop

        goto L_80025F10;
    // 0x80025F0C: nop

L_80025F10:
    // 0x80025F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025F14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80025F18: jr          $ra
    // 0x80025F1C: nop

    return;
    // 0x80025F1C: nop

;}
RECOMP_FUNC void func_8001D5C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D5C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D5C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D5CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001D5D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001D5D4: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8001D5D8: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x8001D5DC: sra         $t9, $v0, 3
    ctx->r25 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8001D5E0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8001D5E4: andi        $t0, $t9, 0xF8
    ctx->r8 = ctx->r25 & 0XF8;
    // 0x8001D5E8: andi        $t2, $t1, 0xF8
    ctx->r10 = ctx->r9 & 0XF8;
    // 0x8001D5EC: sh          $t0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r8;
    // 0x8001D5F0: sh          $t2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r10;
    // 0x8001D5F4: lbu         $v1, 0x3($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X3);
    // 0x8001D5F8: sra         $t7, $v0, 8
    ctx->r15 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8001D5FC: andi        $a3, $t7, 0xF8
    ctx->r7 = ctx->r15 & 0XF8;
    // 0x8001D600: beql        $v1, $zero, L_8001D68C
    if (ctx->r3 == 0) {
        // 0x8001D604: lhu         $t0, 0x24($sp)
        ctx->r8 = MEM_HU(ctx->r29, 0X24);
            goto L_8001D68C;
    }
    goto skip_0;
    // 0x8001D604: lhu         $t0, 0x24($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X24);
    skip_0:
    // 0x8001D608: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8001D60C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001D610: bgez        $v1, L_8001D624
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001D614: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001D624;
    }
    // 0x8001D614: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001D618: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D61C: nop

    // 0x8001D620: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001D624:
    // 0x8001D624: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8001D628: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D62C: lbu         $a1, 0x0($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X0);
    // 0x8001D630: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x8001D634: mul.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8001D638: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001D63C: jal         0x8001D4C4
    // 0x8001D640: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_8001D4C4(rdram, ctx);
        goto after_0;
    // 0x8001D640: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8001D644: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D648: andi        $t4, $v0, 0xF8
    ctx->r12 = ctx->r2 & 0XF8;
    // 0x8001D64C: sh          $t4, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r12;
    // 0x8001D650: lbu         $a0, 0x25($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X25);
    // 0x8001D654: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D658: jal         0x8001D4C4
    // 0x8001D65C: lbu         $a1, 0x1($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X1);
    func_8001D4C4(rdram, ctx);
        goto after_1;
    // 0x8001D65C: lbu         $a1, 0x1($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X1);
    after_1:
    // 0x8001D660: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D664: andi        $t6, $v0, 0xF8
    ctx->r14 = ctx->r2 & 0XF8;
    // 0x8001D668: sh          $t6, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r14;
    // 0x8001D66C: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x8001D670: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D674: jal         0x8001D4C4
    // 0x8001D678: lbu         $a1, 0x2($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X2);
    func_8001D4C4(rdram, ctx);
        goto after_2;
    // 0x8001D678: lbu         $a1, 0x2($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X2);
    after_2:
    // 0x8001D67C: andi        $t8, $v0, 0xF8
    ctx->r24 = ctx->r2 & 0XF8;
    // 0x8001D680: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    // 0x8001D684: lhu         $a3, 0x26($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X26);
    // 0x8001D688: lhu         $t0, 0x24($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X24);
L_8001D68C:
    // 0x8001D68C: lhu         $t3, 0x22($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X22);
    // 0x8001D690: sll         $t9, $a3, 8
    ctx->r25 = S32(ctx->r7 << 8);
    // 0x8001D694: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8001D698: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001D69C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8001D6A0: sra         $t4, $t3, 2
    ctx->r12 = S32(SIGNED(ctx->r11) >> 2);
    // 0x8001D6A4: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8001D6A8: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8001D6AC: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x8001D6B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D6B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D6B8: jr          $ra
    // 0x8001D6BC: nop

    return;
    // 0x8001D6BC: nop

;}
RECOMP_FUNC void func_800F798C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F798C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7990: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7994: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7998: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F799C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F79A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F79A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F79A8: jal         0x8009AD20
    // 0x800F79AC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD20(rdram, ctx);
        goto after_0;
    // 0x800F79AC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F79B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F79B4: jal         0x8009AD2C
    // 0x800F79B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8009AD2C(rdram, ctx);
        goto after_1;
    // 0x800F79B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800F79BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F79C0: jal         0x8009E7C8
    // 0x800F79C4: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F79C4: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_2:
    // 0x800F79C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F79CC: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F79D0: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F79D4: jr          $ra
    // 0x800F79D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F79D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800B811C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B811C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B8120: lui         $t8, 0x12
    ctx->r24 = S32(0X12 << 16);
    // 0x800B8124: addiu       $t8, $t8, -0x5998
    ctx->r24 = ADD32(ctx->r24, -0X5998);
    // 0x800B8128: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B812C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B8130: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800B8134: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8138: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B813C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B8140: jr          $ra
    // 0x800B8144: sb          $zero, -0x7D3B($at)
    MEM_B(-0X7D3B, ctx->r1) = 0;
    return;
    // 0x800B8144: sb          $zero, -0x7D3B($at)
    MEM_B(-0X7D3B, ctx->r1) = 0;
;}
RECOMP_FUNC void _bsblongleg_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A18: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A18);
    return;
    // 0x80082A1C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800EE8E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE8E8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EE8EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800EE8F0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800EE8F4: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800EE8F8: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EE8FC: jr          $ra
    // 0x800EE900: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800EE900: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void _ncbafixpos_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089350: syscall     774
    recomp_syscall_handler(rdram, ctx, 0x80089350);
    return;
    // 0x80089354: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808033A0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808033A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808033A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808033A8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808033AC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x808033B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808033B4: jal         0x80100094
    // 0x808033B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808033B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808033BC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x808033C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808033C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808033C8: beq         $a3, $zero, L_808033F0
    if (ctx->r7 == 0) {
        // 0x808033CC: addiu       $t6, $zero, 0x14
        ctx->r14 = ADD32(0, 0X14);
            goto L_808033F0;
    }
    // 0x808033CC: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x808033D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808033D4: beq         $a3, $at, L_808033FC
    if (ctx->r7 == ctx->r1) {
        // 0x808033D8: addiu       $t7, $zero, 0x14
        ctx->r15 = ADD32(0, 0X14);
            goto L_808033FC;
    }
    // 0x808033D8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x808033DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808033E0: beq         $a3, $at, L_80803408
    if (ctx->r7 == ctx->r1) {
        // 0x808033E4: addiu       $t8, $zero, 0x14
        ctx->r24 = ADD32(0, 0X14);
            goto L_80803408;
    }
    // 0x808033E4: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x808033E8: b           L_80803414
    // 0x808033EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803414;
    // 0x808033EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808033F0:
    // 0x808033F0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x808033F4: b           L_80803414
    // 0x808033F8: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
        goto L_80803414;
    // 0x808033F8: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
L_808033FC:
    // 0x808033FC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80803400: b           L_80803414
    // 0x80803404: addiu       $v0, $v1, 0x53
    ctx->r2 = ADD32(ctx->r3, 0X53);
        goto L_80803414;
    // 0x80803404: addiu       $v0, $v1, 0x53
    ctx->r2 = ADD32(ctx->r3, 0X53);
L_80803408:
    // 0x80803408: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8080340C: b           L_80803414
    // 0x80803410: addiu       $v0, $v1, 0x56
    ctx->r2 = ADD32(ctx->r3, 0X56);
        goto L_80803414;
    // 0x80803410: addiu       $v0, $v1, 0x56
    ctx->r2 = ADD32(ctx->r3, 0X56);
L_80803414:
    // 0x80803414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080341C: jr          $ra
    // 0x80803420: nop

    return;
    // 0x80803420: nop

;}
RECOMP_FUNC void func_80800000_chfantasybounce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: lui         $a1, 0xC62C
    ctx->r5 = S32(0XC62C << 16);
    // 0x80800010: lui         $a2, 0x4604
    ctx->r6 = S32(0X4604 << 16);
    // 0x80800014: lui         $a3, 0xC614
    ctx->r7 = S32(0XC614 << 16);
    // 0x80800018: ori         $a3, $a3, 0x9236
    ctx->r7 = ctx->r7 | 0X9236;
    // 0x8080001C: ori         $a2, $a2, 0xCA00
    ctx->r6 = ctx->r6 | 0XCA00;
    // 0x80800020: ori         $a1, $a1, 0x8A36
    ctx->r5 = ctx->r5 | 0X8A36;
    // 0x80800024: jal         0x800EFA4C
    // 0x80800028: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_808011E4_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808011E8: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808011EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011F0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808011F4: beq         $a1, $at, L_8080153C
    if (ctx->r5 == ctx->r1) {
        // 0x808011F8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080153C;
    }
    // 0x808011F8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808011FC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80801200: beq         $a1, $at, L_80801224
    if (ctx->r5 == ctx->r1) {
        // 0x80801204: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80801224;
    }
    // 0x80801204: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80801208: beq         $a1, $at, L_8080149C
    if (ctx->r5 == ctx->r1) {
        // 0x8080120C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080149C;
    }
    // 0x8080120C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801210: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80801214: beq         $a1, $at, L_808014EC
    if (ctx->r5 == ctx->r1) {
        // 0x80801218: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_808014EC;
    }
    // 0x80801218: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080121C: b           L_808015C8
    // 0x80801220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808015C8;
    // 0x80801220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801224:
    // 0x80801224: lbu         $t6, 0x79($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X79);
    // 0x80801228: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x8080122C: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80801230: ori         $t8, $t7, 0x30
    ctx->r24 = ctx->r15 | 0X30;
    // 0x80801234: sb          $t8, 0x79($a3)
    MEM_B(0X79, ctx->r7) = ctx->r24;
    // 0x80801238: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8080123C: slti        $at, $v0, 0x1436
    ctx->r1 = SIGNED(ctx->r2) < 0X1436 ? 1 : 0;
    // 0x80801240: bne         $at, $zero, L_80801274
    if (ctx->r1 != 0) {
        // 0x80801244: addiu       $t0, $v0, -0x13E0
        ctx->r8 = ADD32(ctx->r2, -0X13E0);
            goto L_80801274;
    }
    // 0x80801244: addiu       $t0, $v0, -0x13E0
    ctx->r8 = ADD32(ctx->r2, -0X13E0);
    // 0x80801248: addiu       $at, $zero, 0x1437
    ctx->r1 = ADD32(0, 0X1437);
    // 0x8080124C: beq         $v0, $at, L_808013D4
    if (ctx->r2 == ctx->r1) {
        // 0x80801250: addiu       $at, $zero, 0x1454
        ctx->r1 = ADD32(0, 0X1454);
            goto L_808013D4;
    }
    // 0x80801250: addiu       $at, $zero, 0x1454
    ctx->r1 = ADD32(0, 0X1454);
    // 0x80801254: beq         $v0, $at, L_8080148C
    if (ctx->r2 == ctx->r1) {
        // 0x80801258: addiu       $at, $zero, 0x1455
        ctx->r1 = ADD32(0, 0X1455);
            goto L_8080148C;
    }
    // 0x80801258: addiu       $at, $zero, 0x1455
    ctx->r1 = ADD32(0, 0X1455);
    // 0x8080125C: beq         $v0, $at, L_8080148C
    if (ctx->r2 == ctx->r1) {
        // 0x80801260: addiu       $at, $zero, 0x1456
        ctx->r1 = ADD32(0, 0X1456);
            goto L_8080148C;
    }
    // 0x80801260: addiu       $at, $zero, 0x1456
    ctx->r1 = ADD32(0, 0X1456);
    // 0x80801264: beq         $v0, $at, L_8080148C
    if (ctx->r2 == ctx->r1) {
        // 0x80801268: nop
    
            goto L_8080148C;
    }
    // 0x80801268: nop

    // 0x8080126C: b           L_808015C8
    // 0x80801270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801274:
    // 0x80801274: slti        $at, $v0, 0x1416
    ctx->r1 = SIGNED(ctx->r2) < 0X1416 ? 1 : 0;
    // 0x80801278: bne         $at, $zero, L_8080129C
    if (ctx->r1 != 0) {
        // 0x8080127C: addiu       $t9, $v0, -0x1411
        ctx->r25 = ADD32(ctx->r2, -0X1411);
            goto L_8080129C;
    }
    // 0x8080127C: addiu       $t9, $v0, -0x1411
    ctx->r25 = ADD32(ctx->r2, -0X1411);
    // 0x80801280: addiu       $at, $zero, 0x1434
    ctx->r1 = ADD32(0, 0X1434);
    // 0x80801284: beq         $v0, $at, L_808012F8
    if (ctx->r2 == ctx->r1) {
        // 0x80801288: addiu       $at, $zero, 0x1435
        ctx->r1 = ADD32(0, 0X1435);
            goto L_808012F8;
    }
    // 0x80801288: addiu       $at, $zero, 0x1435
    ctx->r1 = ADD32(0, 0X1435);
    // 0x8080128C: beql        $v0, $at, L_808012FC
    if (ctx->r2 == ctx->r1) {
        // 0x80801290: lh          $t1, 0x2($v1)
        ctx->r9 = MEM_H(ctx->r3, 0X2);
            goto L_808012FC;
    }
    goto skip_0;
    // 0x80801290: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    skip_0:
    // 0x80801294: b           L_808015C8
    // 0x80801298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080129C:
    // 0x8080129C: slti        $at, $v0, 0x13ED
    ctx->r1 = SIGNED(ctx->r2) < 0X13ED ? 1 : 0;
    // 0x808012A0: bne         $at, $zero, L_808012C4
    if (ctx->r1 != 0) {
        // 0x808012A4: sltiu       $at, $t9, 0x5
        ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
            goto L_808012C4;
    }
    // 0x808012A4: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x808012A8: beq         $at, $zero, L_80801494
    if (ctx->r1 == 0) {
        // 0x808012AC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80801494;
    }
    // 0x808012AC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808012B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2F10) << 16);
    // 0x808012B4: addu        $at, $at, $t9
    gpr jr_addend_808012BC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808012B8: lw          $t9, 0x2F10($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2F10));
    // 0x808012BC: jr          $t9
    // 0x808012C0: nop

    switch (jr_addend_808012BC >> 2) {
        case 0: goto L_80801340; break;
        case 1: goto L_8080132C; break;
        case 2: goto L_8080139C; break;
        case 3: goto L_80801408; break;
        case 4: goto L_80801464; break;
        default: switch_error(__func__, 0x808012BC, 0x80802F10);
    }
    // 0x808012C0: nop

L_808012C4:
    // 0x808012C4: sltiu       $at, $t0, 0xD
    ctx->r1 = ctx->r8 < 0XD ? 1 : 0;
    // 0x808012C8: beq         $at, $zero, L_80801494
    if (ctx->r1 == 0) {
        // 0x808012CC: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80801494;
    }
    // 0x808012CC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808012D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2F24) << 16);
    // 0x808012D4: addu        $at, $at, $t0
    gpr jr_addend_808012DC = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808012D8: lw          $t0, 0x2F24($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2F24));
    // 0x808012DC: jr          $t0
    // 0x808012E0: nop

    switch (jr_addend_808012DC >> 2) {
        case 0: goto L_8080148C; break;
        case 1: goto L_8080148C; break;
        case 2: goto L_808012E4; break;
        case 3: goto L_8080148C; break;
        case 4: goto L_8080148C; break;
        case 5: goto L_80801354; break;
        case 6: goto L_808013B0; break;
        case 7: goto L_80801368; break;
        case 8: goto L_808013D4; break;
        case 9: goto L_808013D4; break;
        case 10: goto L_8080141C; break;
        case 11: goto L_80801478; break;
        case 12: goto L_80801430; break;
        default: switch_error(__func__, 0x808012DC, 0x80802F24);
    }
    // 0x808012E0: nop

L_808012E4:
    // 0x808012E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808012E8: jal         0x8080094C
    // 0x808012EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_0;
    // 0x808012EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x808012F0: b           L_808015C8
    // 0x808012F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x808012F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808012F8:
    // 0x808012F8: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
L_808012FC:
    // 0x808012FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801300: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80801304: bne         $t1, $at, L_8080131C
    if (ctx->r9 != ctx->r1) {
        // 0x80801308: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080131C;
    }
    // 0x80801308: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080130C: jal         0x8080094C
    // 0x80801310: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_1;
    // 0x80801310: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80801314: b           L_808015C8
    // 0x80801318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080131C:
    // 0x8080131C: jal         0x8080094C
    // 0x80801320: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_2;
    // 0x80801320: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x80801324: b           L_808015C8
    // 0x80801328: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801328: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080132C:
    // 0x8080132C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801330: jal         0x8080094C
    // 0x80801334: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_3;
    // 0x80801334: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80801338: b           L_808015C8
    // 0x8080133C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x8080133C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801340:
    // 0x80801340: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801344: jal         0x8080094C
    // 0x80801348: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_4;
    // 0x80801348: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x8080134C: b           L_808015C8
    // 0x80801350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801354:
    // 0x80801354: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801358: jal         0x8080094C
    // 0x8080135C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_5;
    // 0x8080135C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_5:
    // 0x80801360: b           L_808015C8
    // 0x80801364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801368:
    // 0x80801368: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    // 0x8080136C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801370: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80801374: bne         $t2, $at, L_8080138C
    if (ctx->r10 != ctx->r1) {
        // 0x80801378: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080138C;
    }
    // 0x80801378: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080137C: jal         0x8080094C
    // 0x80801380: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_6;
    // 0x80801380: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x80801384: b           L_808015C8
    // 0x80801388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080138C:
    // 0x8080138C: jal         0x8080094C
    // 0x80801390: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_7;
    // 0x80801390: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_7:
    // 0x80801394: b           L_808015C8
    // 0x80801398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080139C:
    // 0x8080139C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808013A0: jal         0x8080094C
    // 0x808013A4: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_8;
    // 0x808013A4: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_8:
    // 0x808013A8: b           L_808015C8
    // 0x808013AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x808013AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808013B0:
    // 0x808013B0: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    // 0x808013B4: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    // 0x808013B8: jal         0x800C01A8
    // 0x808013BC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_800C01A8(rdram, ctx);
        goto after_9;
    // 0x808013BC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_9:
    // 0x808013C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808013C4: jal         0x8080094C
    // 0x808013C8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_10;
    // 0x808013C8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_10:
    // 0x808013CC: b           L_808015C8
    // 0x808013D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x808013D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808013D4:
    // 0x808013D4: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x808013D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808013DC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x808013E0: bne         $t3, $at, L_808013F8
    if (ctx->r11 != ctx->r1) {
        // 0x808013E4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808013F8;
    }
    // 0x808013E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808013E8: jal         0x8080094C
    // 0x808013EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_11;
    // 0x808013EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_11:
    // 0x808013F0: b           L_808015C8
    // 0x808013F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x808013F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808013F8:
    // 0x808013F8: jal         0x8080094C
    // 0x808013FC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_12;
    // 0x808013FC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_12:
    // 0x80801400: b           L_808015C8
    // 0x80801404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801408:
    // 0x80801408: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080140C: jal         0x8080094C
    // 0x80801410: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_13;
    // 0x80801410: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_13:
    // 0x80801414: b           L_808015C8
    // 0x80801418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080141C:
    // 0x8080141C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801420: jal         0x8080094C
    // 0x80801424: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_14;
    // 0x80801424: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_14:
    // 0x80801428: b           L_808015C8
    // 0x8080142C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x8080142C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801430:
    // 0x80801430: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x80801434: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801438: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x8080143C: bne         $t4, $at, L_80801454
    if (ctx->r12 != ctx->r1) {
        // 0x80801440: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80801454;
    }
    // 0x80801440: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801444: jal         0x8080094C
    // 0x80801448: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_15;
    // 0x80801448: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_15:
    // 0x8080144C: b           L_808015C8
    // 0x80801450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801454:
    // 0x80801454: jal         0x8080094C
    // 0x80801458: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_16;
    // 0x80801458: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_16:
    // 0x8080145C: b           L_808015C8
    // 0x80801460: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801460: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801464:
    // 0x80801464: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801468: jal         0x8080094C
    // 0x8080146C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_17;
    // 0x8080146C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_17:
    // 0x80801470: b           L_808015C8
    // 0x80801474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801478:
    // 0x80801478: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080147C: jal         0x8080094C
    // 0x80801480: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_18;
    // 0x80801480: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_18:
    // 0x80801484: b           L_808015C8
    // 0x80801488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080148C:
    // 0x8080148C: jal         0x80802D38
    // 0x80801490: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80802D38_chfantasyathlete(rdram, ctx);
        goto after_19;
    // 0x80801490: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_19:
L_80801494:
    // 0x80801494: b           L_808015C8
    // 0x80801498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080149C:
    // 0x8080149C: jal         0x80103EF4
    // 0x808014A0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_80103EF4(rdram, ctx);
        goto after_20;
    // 0x808014A0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_20:
    // 0x808014A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808014A8: jal         0x80103EAC
    // 0x808014AC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80103EAC(rdram, ctx);
        goto after_21;
    // 0x808014AC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x808014B0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808014B4: jal         0x80103EAC
    // 0x808014B8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80103EAC(rdram, ctx);
        goto after_22;
    // 0x808014B8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x808014BC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808014C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808014C4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808014C8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x808014CC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808014D0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808014D4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808014D8: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x808014DC: jal         0x80088090
    // 0x808014E0: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x808014E0: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_23:
    // 0x808014E4: b           L_808015C8
    // 0x808014E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x808014E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808014EC:
    // 0x808014EC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x808014F0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808014F4: andi        $t5, $a0, 0xFFFF
    ctx->r13 = ctx->r4 & 0XFFFF;
    // 0x808014F8: and         $t6, $a2, $at
    ctx->r14 = ctx->r6 & ctx->r1;
    // 0x808014FC: srl         $a1, $t6, 16
    ctx->r5 = S32(U32(ctx->r14) >> 16);
    // 0x80801500: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80801504: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80801508: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8080150C: jal         0x80088078
    // 0x80801510: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_24;
    // 0x80801510: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_24:
    // 0x80801514: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80801518: beq         $v0, $zero, L_80801534
    if (ctx->r2 == 0) {
        // 0x8080151C: lw          $a3, 0x38($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X38);
            goto L_80801534;
    }
    // 0x8080151C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80801520: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801524: jal         0x80802C94
    // 0x80801528: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80802C94_chfantasyathlete(rdram, ctx);
        goto after_25;
    // 0x80801528: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_25:
    // 0x8080152C: b           L_808015C8
    // 0x80801530: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808015C8;
    // 0x80801530: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80801534:
    // 0x80801534: b           L_808015C8
    // 0x80801538: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x80801538: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080153C:
    // 0x8080153C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801540: jal         0x801015D0
    // 0x80801544: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_801015D0(rdram, ctx);
        goto after_26;
    // 0x80801544: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_26:
    // 0x80801548: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8080154C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2388, 0X3034) << 16);
    // 0x80801550: lhu         $t8, 0x72($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X72);
    // 0x80801554: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80801558: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8080155C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80801560: lhu         $t1, 0x3034($t1)
    ctx->r9 = MEM_HU(ctx->r9, (int16_t)RELOC_LO16(2388, 0X3034));
    // 0x80801564: addiu       $t2, $t1, -0x3F9
    ctx->r10 = ADD32(ctx->r9, -0X3F9);
    // 0x80801568: sltiu       $at, $t2, 0x8
    ctx->r1 = ctx->r10 < 0X8 ? 1 : 0;
    // 0x8080156C: beq         $at, $zero, L_808015C0
    if (ctx->r1 == 0) {
        // 0x80801570: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808015C0;
    }
    // 0x80801570: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80801574: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2F58) << 16);
    // 0x80801578: addu        $at, $at, $t2
    gpr jr_addend_80801580 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8080157C: lw          $t2, 0x2F58($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2F58));
    // 0x80801580: jr          $t2
    // 0x80801584: nop

    switch (jr_addend_80801580 >> 2) {
        case 0: goto L_80801588; break;
        case 1: goto L_80801588; break;
        case 2: goto L_808015A8; break;
        case 3: goto L_808015A8; break;
        case 4: goto L_80801588; break;
        case 5: goto L_80801588; break;
        case 6: goto L_808015A8; break;
        case 7: goto L_808015A8; break;
        default: switch_error(__func__, 0x80801580, 0x80802F58);
    }
    // 0x80801584: nop

L_80801588:
    // 0x80801588: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8080158C: jal         0x800DF744
    // 0x80801590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_27;
    // 0x80801590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80801594: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801598: jal         0x800DF744
    // 0x8080159C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_28;
    // 0x8080159C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x808015A0: b           L_808015C8
    // 0x808015A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x808015A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808015A8:
    // 0x808015A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808015AC: jal         0x800DF744
    // 0x808015B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_29;
    // 0x808015B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x808015B4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808015B8: jal         0x800DF744
    // 0x808015BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_30;
    // 0x808015BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_30:
L_808015C0:
    // 0x808015C0: b           L_808015C8
    // 0x808015C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C8;
    // 0x808015C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808015C8:
    // 0x808015C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808015CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808015D0: jr          $ra
    // 0x808015D4: nop

    return;
    // 0x808015D4: nop

;}
RECOMP_FUNC void func_80800078_chsounder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: jr          $ra
    // 0x8080007C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080007C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800B0D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0D50: jr          $ra
    // 0x800B0D54: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    return;
    // 0x800B0D54: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
;}
RECOMP_FUNC void func_80015FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015FFC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80016000: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80016004: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80016008: addiu       $t7, $t7, -0x6620
    ctx->r15 = ADD32(ctx->r15, -0X6620);
    // 0x8001600C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80016010: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80016014: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x80016018: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8001601C: lw          $t9, 0x28($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X28);
    // 0x80016020: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80016024: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x80016028: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    // 0x8001602C: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x80016030: jr          $ra
    // 0x80016034: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    return;
    // 0x80016034: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void func_80096568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009656C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096570: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80096574: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096578: jal         0x800C6744
    // 0x8009657C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C6744(rdram, ctx);
        goto after_0;
    // 0x8009657C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80096580: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80096584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096588: andi        $t8, $v0, 0x1F00
    ctx->r24 = ctx->r2 & 0X1F00;
    // 0x8009658C: xor         $v0, $t7, $t8
    ctx->r2 = ctx->r15 ^ ctx->r24;
    // 0x80096590: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80096594: jr          $ra
    // 0x80096598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80096598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
