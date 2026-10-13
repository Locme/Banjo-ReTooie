#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800A5BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5BBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5BC0: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x800A5BC4: jr          $ra
    // 0x800A5BC8: lbu         $v0, 0xA($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA);
    return;
    // 0x800A5BC8: lbu         $v0, 0xA($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA);
;}
RECOMP_FUNC void anctrl_setSubrange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B1D4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008B1D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008B1DC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8008B1E0: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8008B1E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008B1E8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8008B1EC: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x8008B1F0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8008B1F4: nop

    // 0x8008B1F8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008B1FC: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8008B200: bc1t        L_8008B22C
    if (c1cs) {
        // 0x8008B204: swc1        $f10, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
            goto L_8008B22C;
    }
    // 0x8008B204: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x8008B208: trunc.w.s   $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8008B20C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8008B210: nop

    // 0x8008B214: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8008B218: nop

    // 0x8008B21C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008B220: sub.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8008B224: jr          $ra
    // 0x8008B228: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8008B228: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
L_8008B22C:
    // 0x8008B22C: swc1        $f14, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f14.u32l;
    // 0x8008B230: jr          $ra
    // 0x8008B234: nop

    return;
    // 0x8008B234: nop

;}
RECOMP_FUNC void baflameline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080030C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800310: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800314: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800318: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080031C: jal         0x800EFD24
    // 0x80800320: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80800320: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80800324: lw          $a0, 0x84($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84);
    // 0x80800328: jal         0x800EFD24
    // 0x8080032C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8080032C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x80800330: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800334: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800338: lw          $t6, 0x84($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X84);
    // 0x8080033C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80800340: jal         0x800B53A4
    // 0x80800344: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x80800344: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
    after_2:
    // 0x80800348: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    // 0x8080034C: sw          $v0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r2;
    // 0x80800350: lw          $t8, 0x84($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X84);
    // 0x80800354: jal         0x800B5534
    // 0x80800358: lw          $a0, 0x1C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X1C);
    func_800B5534(rdram, ctx);
        goto after_3;
    // 0x80800358: lw          $a0, 0x1C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X1C);
    after_3:
    // 0x8080035C: jal         0x800BF8E4
    // 0x80800360: nop

    func_800BF8E4(rdram, ctx);
        goto after_4;
    // 0x80800360: nop

    after_4:
    // 0x80800364: blezl       $v0, L_808003A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800368: lw          $t2, 0x84($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X84);
            goto L_808003A8;
    }
    goto skip_0;
    // 0x80800368: lw          $t2, 0x84($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X84);
    skip_0:
    // 0x8080036C: jal         0x800C8A98
    // 0x80800370: nop

    func_800C8A98(rdram, ctx);
        goto after_5;
    // 0x80800370: nop

    after_5:
    // 0x80800374: lw          $t9, 0x84($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X84);
    // 0x80800378: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8080037C: sw          $v0, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r2;
    // 0x80800380: lw          $t0, 0x84($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X84);
    // 0x80800384: jal         0x800C8F64
    // 0x80800388: lw          $a0, 0x24($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X24);
    func_800C8F64(rdram, ctx);
        goto after_6;
    // 0x80800388: lw          $a0, 0x24($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X24);
    after_6:
    // 0x8080038C: lw          $t1, 0x84($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X84);
    // 0x80800390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800394: jal         0x800C8FE0
    // 0x80800398: lw          $a0, 0x24($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X24);
    func_800C8FE0(rdram, ctx);
        goto after_7;
    // 0x80800398: lw          $a0, 0x24($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X24);
    after_7:
    // 0x8080039C: b           L_808003AC
    // 0x808003A0: nop

        goto L_808003AC;
    // 0x808003A0: nop

    // 0x808003A4: lw          $t2, 0x84($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X84);
L_808003A8:
    // 0x808003A8: sw          $zero, 0x24($t2)
    MEM_W(0X24, ctx->r10) = 0;
L_808003AC:
    // 0x808003AC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(520, 0X784) << 16);
    // 0x808003B0: addiu       $a2, $a2, 0x784
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(520, 0X784));
    // 0x808003B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003B8: jal         0x800C4350
    // 0x808003BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_8;
    // 0x808003BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808003C0: lw          $t3, 0x84($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X84);
    // 0x808003C4: sb          $v0, 0x20($t3)
    MEM_B(0X20, ctx->r11) = ctx->r2;
    // 0x808003C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003D4: jr          $ra
    // 0x808003D8: nop

    return;
    // 0x808003D8: nop

;}
RECOMP_FUNC void func_80805B8C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805B8C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80805B90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80805B94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80805B98: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA090) << 16);
    // 0x80805B9C: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80805BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805BA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80805BA8: addiu       $a2, $a2, -0x5F70
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA090));
    // 0x80805BAC: bc1f        L_80805BE8
    if (!c1cs) {
        // 0x80805BB0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80805BE8;
    }
    // 0x80805BB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80805BB4: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA084) << 16);
    // 0x80805BB8: addiu       $a2, $a2, -0x5F7C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA084));
    // 0x80805BBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80805BC0: jal         0x80805C1C
    // 0x80805BC4: lui         $a3, 0xC2B4
    ctx->r7 = S32(0XC2B4 << 16);
    func_80805C1C_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80805BC4: lui         $a3, 0xC2B4
    ctx->r7 = S32(0XC2B4 << 16);
    after_0:
    // 0x80805BC8: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA0A8) << 16);
    // 0x80805BCC: addiu       $a2, $a2, -0x5F58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA0A8));
    // 0x80805BD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80805BD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80805BD8: jal         0x80805C1C
    // 0x80805BDC: lui         $a3, 0x42B4
    ctx->r7 = S32(0X42B4 << 16);
    func_80805C1C_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80805BDC: lui         $a3, 0x42B4
    ctx->r7 = S32(0X42B4 << 16);
    after_1:
    // 0x80805BE0: b           L_80805C10
    // 0x80805BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805C10;
    // 0x80805BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805BE8:
    // 0x80805BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80805BEC: jal         0x80805C1C
    // 0x80805BF0: lui         $a3, 0xC2B4
    ctx->r7 = S32(0XC2B4 << 16);
    func_80805C1C_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80805BF0: lui         $a3, 0xC2B4
    ctx->r7 = S32(0XC2B4 << 16);
    after_2:
    // 0x80805BF4: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA09C) << 16);
    // 0x80805BF8: addiu       $a2, $a2, -0x5F64
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA09C));
    // 0x80805BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80805C00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80805C04: jal         0x80805C1C
    // 0x80805C08: lui         $a3, 0x42B4
    ctx->r7 = S32(0X42B4 << 16);
    func_80805C1C_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80805C08: lui         $a3, 0x42B4
    ctx->r7 = S32(0X42B4 << 16);
    after_3:
    // 0x80805C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805C10:
    // 0x80805C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80805C14: jr          $ra
    // 0x80805C18: nop

    return;
    // 0x80805C18: nop

;}
RECOMP_FUNC void func_80800328_chamazonstadiumguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800328: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080032C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800330: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80800334: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800338: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080033C: beq         $a1, $at, L_80800414
    if (ctx->r5 == ctx->r1) {
        // 0x80800340: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800414;
    }
    // 0x80800340: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800344: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80800348: beq         $a1, $at, L_80800448
    if (ctx->r5 == ctx->r1) {
        // 0x8080034C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800448;
    }
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800354: beq         $a1, $at, L_8080037C
    if (ctx->r5 == ctx->r1) {
        // 0x80800358: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080037C;
    }
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800360: beq         $a1, $at, L_80800390
    if (ctx->r5 == ctx->r1) {
        // 0x80800364: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1900, 0X760) << 16);
            goto L_80800390;
    }
    // 0x80800364: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1900, 0X760) << 16);
    // 0x80800368: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080036C: beq         $a1, $at, L_808003A4
    if (ctx->r5 == ctx->r1) {
        // 0x80800370: nop
    
            goto L_808003A4;
    }
    // 0x80800370: nop

    // 0x80800374: b           L_80800474
    // 0x80800378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800474;
    // 0x80800378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080037C:
    // 0x8080037C: lh          $a1, 0x28($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X28);
    // 0x80800380: jal         0x80800488
    // 0x80800384: lh          $a2, 0x2A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2A);
    func_80800488_chamazonstadiumguard(rdram, ctx);
        goto after_0;
    // 0x80800384: lh          $a2, 0x2A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2A);
    after_0:
    // 0x80800388: b           L_80800474
    // 0x8080038C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800474;
    // 0x8080038C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800390:
    // 0x80800390: addiu       $a0, $a0, 0x760
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1900, 0X760));
    // 0x80800394: jal         0x80088090
    // 0x80800398: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800398: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8080039C: b           L_80800474
    // 0x808003A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800474;
    // 0x808003A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A4:
    // 0x808003A4: jal         0x80088848
    // 0x808003A8: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808003A8: nop

    after_2:
    // 0x808003AC: beq         $v0, $zero, L_808003C4
    if (ctx->r2 == 0) {
        // 0x808003B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C4;
    }
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: jal         0x80102424
    // 0x808003B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808003B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x808003BC: b           L_80800474
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800474;
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C4:
    // 0x808003C4: jal         0x800EA090
    // 0x808003C8: nop

    func_800EA090(rdram, ctx);
        goto after_4;
    // 0x808003C8: nop

    after_4:
    // 0x808003CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003D0: bne         $v0, $at, L_80800470
    if (ctx->r2 != ctx->r1) {
        // 0x808003D4: lui         $v0, 0x8080
        ctx->r2 = S32(RELOC_HI16(1900, 0X6B0) << 16);
            goto L_80800470;
    }
    // 0x808003D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1900, 0X6B0) << 16);
    // 0x808003D8: addiu       $v0, $v0, 0x6B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1900, 0X6B0));
    // 0x808003DC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x808003E8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808003EC: jal         0x80103014
    // 0x808003F0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    func_80103014(rdram, ctx);
        goto after_5;
    // 0x808003F0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: jal         0x801020DC
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_801020DC(rdram, ctx);
        goto after_6;
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: jal         0x80102424
    // 0x80800408: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800408: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_7:
    // 0x8080040C: b           L_80800474
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800474;
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800414:
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080041C: jal         0x800897C0
    // 0x80800420: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x80800420: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_8:
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: jal         0x80100094
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800434: lui         $a1, 0x4282
    ctx->r5 = S32(0X4282 << 16);
    // 0x80800438: jal         0x800897E8
    // 0x8080043C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_10;
    // 0x8080043C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_10:
    // 0x80800440: b           L_80800474
    // 0x80800444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800474;
    // 0x80800444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800448:
    // 0x80800448: jal         0x80100094
    // 0x8080044C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x8080044C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800450: beq         $v0, $zero, L_80800470
    if (ctx->r2 == 0) {
        // 0x80800454: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800470;
    }
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: jal         0x800897C8
    // 0x8080045C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_12;
    // 0x8080045C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800460: b           L_80800474
    // 0x80800464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800474;
    // 0x80800464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800468: b           L_80800474
    // 0x8080046C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800474;
    // 0x8080046C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800470:
    // 0x80800470: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800474:
    // 0x80800474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800478: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080047C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800480: jr          $ra
    // 0x80800484: nop

    return;
    // 0x80800484: nop

;}
RECOMP_FUNC void func_80800038_idflasha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080003C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800040: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080004C: bne         $a1, $at, L_80800090
    if (ctx->r5 != ctx->r1) {
        // 0x80800050: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80800090;
    }
    // 0x80800050: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800054: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80800058: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8080005C: jal         0x800DC214
    // 0x80800060: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_800DC214(rdram, ctx);
        goto after_0;
    // 0x80800060: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_0:
    // 0x80800064: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80800068: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8080006C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2910, 0X2A0) << 16);
    // 0x80800070: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80800074: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80800078: lwc1        $f12, 0x2A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2910, 0X2A0));
    // 0x8080007C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2910, 0X2A4) << 16);
    // 0x80800080: jal         0x800DC264
    // 0x80800084: lwc1        $f14, 0x2A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2910, 0X2A4));
    func_800DC264(rdram, ctx);
        goto after_1;
    // 0x80800084: lwc1        $f14, 0x2A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2910, 0X2A4));
    after_1:
    // 0x80800088: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8080008C: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
L_80800090:
    // 0x80800090: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800094: bnel        $t9, $zero, L_80800100
    if (ctx->r25 != 0) {
        // 0x80800098: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80800100;
    }
    goto skip_0;
    // 0x80800098: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080009C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x808000A0: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x808000A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808000A8: blez        $v0, L_808000D8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808000AC: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_808000D8;
    }
    // 0x808000AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808000B0: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x808000B4: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x808000B8: beq         $at, $zero, L_808000D8
    if (ctx->r1 == 0) {
        // 0x808000BC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2910, 0X2A8) << 16);
            goto L_808000D8;
    }
    // 0x808000BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2910, 0X2A8) << 16);
    // 0x808000C0: lwc1        $f12, 0x2A8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2910, 0X2A8));
    // 0x808000C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2910, 0X2AC) << 16);
    // 0x808000C8: jal         0x800DC264
    // 0x808000CC: lwc1        $f14, 0x2AC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2910, 0X2AC));
    func_800DC264(rdram, ctx);
        goto after_2;
    // 0x808000CC: lwc1        $f14, 0x2AC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2910, 0X2AC));
    after_2:
    // 0x808000D0: b           L_808000FC
    // 0x808000D4: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
        goto L_808000FC;
    // 0x808000D4: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
L_808000D8:
    // 0x808000D8: jal         0x800DC214
    // 0x808000DC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    func_800DC214(rdram, ctx);
        goto after_3;
    // 0x808000DC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    after_3:
    // 0x808000E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808000E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000E8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808000EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000F0: jal         0x800DC264
    // 0x808000F4: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    func_800DC264(rdram, ctx);
        goto after_4;
    // 0x808000F4: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    after_4:
    // 0x808000F8: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
L_808000FC:
    // 0x808000FC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80800100:
    // 0x80800100: sw          $t1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r9;
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080010C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800238: jal         0x8080038C
    // 0x8080023C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gsmaker_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x8080023C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800248: jr          $ra
    // 0x8080024C: nop

    return;
    // 0x8080024C: nop

;}
RECOMP_FUNC void func_80802CE8_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802CEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802CF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802CF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80802CF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802CFC: jal         0x80100094
    // 0x80802D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802D04: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80802D08: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80802D0C: beql        $a0, $zero, L_80802D28
    if (ctx->r4 == 0) {
        // 0x80802D10: sw          $zero, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = 0;
            goto L_80802D28;
    }
    goto skip_0;
    // 0x80802D10: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    skip_0:
    // 0x80802D14: jal         0x80106790
    // 0x80802D18: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80802D18: nop

    after_1:
    // 0x80802D1C: b           L_80802D28
    // 0x80802D20: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_80802D28;
    // 0x80802D20: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80802D24: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80802D28:
    // 0x80802D28: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x80802D2C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80802D30: srl         $t6, $a1, 10
    ctx->r14 = S32(U32(ctx->r5) >> 10);
    // 0x80802D34: beq         $t6, $at, L_80802D74
    if (ctx->r14 == ctx->r1) {
        // 0x80802D38: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80802D74;
    }
    // 0x80802D38: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80802D3C: beq         $t6, $at, L_80802D54
    if (ctx->r14 == ctx->r1) {
        // 0x80802D40: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_80802D54;
    }
    // 0x80802D40: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80802D44: beq         $t6, $at, L_80802D64
    if (ctx->r14 == ctx->r1) {
        // 0x80802D48: nop
    
            goto L_80802D64;
    }
    // 0x80802D48: nop

    // 0x80802D4C: b           L_80802D80
    // 0x80802D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802D80;
    // 0x80802D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802D54:
    // 0x80802D54: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80802D58: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80802D5C: b           L_80802D7C
    // 0x80802D60: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_80802D7C;
    // 0x80802D60: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_80802D64:
    // 0x80802D64: jal         0x80800AB0
    // 0x80802D68: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80800AB0_chhandcart(rdram, ctx);
        goto after_2;
    // 0x80802D68: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80802D6C: b           L_80802D80
    // 0x80802D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802D80;
    // 0x80802D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802D74:
    // 0x80802D74: jal         0x80090708
    // 0x80802D78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_3;
    // 0x80802D78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
L_80802D7C:
    // 0x80802D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802D80:
    // 0x80802D80: jal         0x80102424
    // 0x80802D84: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80802D84: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80802D88: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x80802D8C: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80802D90: addiu       $t2, $t1, -0x5
    ctx->r10 = ADD32(ctx->r9, -0X5);
    // 0x80802D94: sltiu       $at, $t2, 0x16
    ctx->r1 = ctx->r10 < 0X16 ? 1 : 0;
    // 0x80802D98: beq         $at, $zero, L_808031B4
    if (ctx->r1 == 0) {
        // 0x80802D9C: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808031B4;
    }
    // 0x80802D9C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80802DA0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4520) << 16);
    // 0x80802DA4: addu        $at, $at, $t2
    gpr jr_addend_80802DAC = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80802DA8: lw          $t2, 0x4520($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4520));
    // 0x80802DAC: jr          $t2
    // 0x80802DB0: nop

    switch (jr_addend_80802DAC >> 2) {
        case 0: goto L_80802EC4; break;
        case 1: goto L_80802F08; break;
        case 2: goto L_80802F40; break;
        case 3: goto L_80802F58; break;
        case 4: goto L_80802FC0; break;
        case 5: goto L_80802FEC; break;
        case 6: goto L_808031B4; break;
        case 7: goto L_808031B4; break;
        case 8: goto L_808031B4; break;
        case 9: goto L_80803054; break;
        case 10: goto L_808030C4; break;
        case 11: goto L_80803064; break;
        case 12: goto L_808031B4; break;
        case 13: goto L_80803174; break;
        case 14: goto L_80802E74; break;
        case 15: goto L_80802E84; break;
        case 16: goto L_808031B4; break;
        case 17: goto L_808031B4; break;
        case 18: goto L_80802EB4; break;
        case 19: goto L_80802DB4; break;
        case 20: goto L_80802DC4; break;
        case 21: goto L_80802E20; break;
        default: switch_error(__func__, 0x80802DAC, 0x80804520);
    }
    // 0x80802DB0: nop

L_80802DB4:
    // 0x80802DB4: jal         0x8008A490
    // 0x80802DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80802DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802DBC: b           L_808031B4
    // 0x80802DC0: nop

        goto L_808031B4;
    // 0x80802DC0: nop

L_80802DC4:
    // 0x80802DC4: jal         0x8008FD70
    // 0x80802DC8: nop

    func_8008FD70(rdram, ctx);
        goto after_6;
    // 0x80802DC8: nop

    after_6:
    // 0x80802DCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802DD0: beq         $v0, $at, L_80802DFC
    if (ctx->r2 == ctx->r1) {
        // 0x80802DD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802DFC;
    }
    // 0x80802DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DD8: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80802DDC: bne         $v0, $at, L_80802E10
    if (ctx->r2 != ctx->r1) {
        // 0x80802DE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802E10;
    }
    // 0x80802DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DE8: addiu       $a1, $zero, 0xFA9
    ctx->r5 = ADD32(0, 0XFA9);
    // 0x80802DEC: jal         0x808023B4
    // 0x80802DF0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_7;
    // 0x80802DF0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_7:
    // 0x80802DF4: b           L_808031B4
    // 0x80802DF8: nop

        goto L_808031B4;
    // 0x80802DF8: nop

L_80802DFC:
    // 0x80802DFC: addiu       $a1, $zero, 0xF7F
    ctx->r5 = ADD32(0, 0XF7F);
    // 0x80802E00: jal         0x808023B4
    // 0x80802E04: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_8;
    // 0x80802E04: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_8:
    // 0x80802E08: b           L_808031B4
    // 0x80802E0C: nop

        goto L_808031B4;
    // 0x80802E0C: nop

L_80802E10:
    // 0x80802E10: jal         0x80802CE8
    // 0x80802E14: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_80802CE8_chhandcart(rdram, ctx);
        goto after_9;
    // 0x80802E14: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_9:
    // 0x80802E18: b           L_808031B4
    // 0x80802E1C: nop

        goto L_808031B4;
    // 0x80802E1C: nop

L_80802E20:
    // 0x80802E20: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80802E24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80802E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802E30: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80802E34: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80802E38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802E3C: jal         0x801058C4
    // 0x80802E40: lh          $a1, 0xC($t3)
    ctx->r5 = MEM_H(ctx->r11, 0XC);
    func_801058C4(rdram, ctx);
        goto after_10;
    // 0x80802E40: lh          $a1, 0xC($t3)
    ctx->r5 = MEM_H(ctx->r11, 0XC);
    after_10:
    // 0x80802E44: jal         0x80802BC8
    // 0x80802E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BC8_chhandcart(rdram, ctx);
        goto after_11;
    // 0x80802E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80802E4C: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    // 0x80802E50: jal         0x800C01A8
    // 0x80802E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_12;
    // 0x80802E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80802E58: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80802E5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802E60: addiu       $a3, $zero, 0x28B0
    ctx->r7 = ADD32(0, 0X28B0);
    // 0x80802E64: jal         0x80085708
    // 0x80802E68: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_13;
    // 0x80802E68: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_13:
    // 0x80802E6C: b           L_808031B4
    // 0x80802E70: nop

        goto L_808031B4;
    // 0x80802E70: nop

L_80802E74:
    // 0x80802E74: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80802E78: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x80802E7C: b           L_808031B4
    // 0x80802E80: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_808031B4;
    // 0x80802E80: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80802E84:
    // 0x80802E84: jal         0x800DA544
    // 0x80802E88: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    func_800DA544(rdram, ctx);
        goto after_14;
    // 0x80802E88: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    after_14:
    // 0x80802E8C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80802E90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80802E94: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80802E98: addiu       $a2, $zero, 0x28B0
    ctx->r6 = ADD32(0, 0X28B0);
    // 0x80802E9C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80802EA0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80802EA4: jal         0x8080090C
    // 0x80802EA8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    func_8080090C_chhandcart(rdram, ctx);
        goto after_15;
    // 0x80802EA8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_15:
    // 0x80802EAC: b           L_808031B4
    // 0x80802EB0: nop

        goto L_808031B4;
    // 0x80802EB0: nop

L_80802EB4:
    // 0x80802EB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802EB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802EBC: b           L_808031B4
    // 0x80802EC0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808031B4;
    // 0x80802EC0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80802EC4:
    // 0x80802EC4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80802EC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802ECC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80802ED0: jal         0x80800998
    // 0x80802ED4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    func_80800998_chhandcart(rdram, ctx);
        goto after_16;
    // 0x80802ED4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    after_16:
    // 0x80802ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802EDC: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80802EE0: jal         0x808023B4
    // 0x80802EE4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_17;
    // 0x80802EE4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_17:
    // 0x80802EE8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80802EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802EF0: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80802EF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802EF8: jal         0x801058C4
    // 0x80802EFC: lh          $a1, 0xC($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XC);
    func_801058C4(rdram, ctx);
        goto after_18;
    // 0x80802EFC: lh          $a1, 0xC($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XC);
    after_18:
    // 0x80802F00: b           L_808031B4
    // 0x80802F04: nop

        goto L_808031B4;
    // 0x80802F04: nop

L_80802F08:
    // 0x80802F08: jal         0x800FDC28
    // 0x80802F0C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800FDC28(rdram, ctx);
        goto after_19;
    // 0x80802F0C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_19:
    // 0x80802F10: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80802F14: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80802F18: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x80802F1C: bgezl       $t0, L_80802F38
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80802F20: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80802F38;
    }
    goto skip_1;
    // 0x80802F20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x80802F24: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80802F28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802F2C: b           L_808031B4
    // 0x80802F30: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_808031B4;
    // 0x80802F30: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80802F34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80802F38:
    // 0x80802F38: b           L_808031B4
    // 0x80802F3C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
        goto L_808031B4;
    // 0x80802F3C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_80802F40:
    // 0x80802F40: jal         0x80800024
    // 0x80802F44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80800024_chhandcart(rdram, ctx);
        goto after_20;
    // 0x80802F44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_20:
    // 0x80802F48: jal         0x80090658
    // 0x80802F4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090658(rdram, ctx);
        goto after_21;
    // 0x80802F4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_21:
    // 0x80802F50: b           L_808031B4
    // 0x80802F54: nop

        goto L_808031B4;
    // 0x80802F54: nop

L_80802F58:
    // 0x80802F58: jal         0x80105AE8
    // 0x80802F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105AE8(rdram, ctx);
        goto after_22;
    // 0x80802F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80802F60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4578) << 16);
    // 0x80802F64: lwc1        $f10, 0x4578($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4578));
    // 0x80802F68: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80802F6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802F70: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80802F74: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80802F78: bc1f        L_80802FB0
    if (!c1cs) {
        // 0x80802F7C: nop
    
            goto L_80802FB0;
    }
    // 0x80802F7C: nop

    // 0x80802F80: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x80802F84: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80802F88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80802F8C: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x80802F90: bgez        $t3, L_80802FA0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80802F94: nop
    
            goto L_80802FA0;
    }
    // 0x80802F94: nop

    // 0x80802F98: b           L_80802FA0
    // 0x80802F9C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_80802FA0;
    // 0x80802F9C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80802FA0:
    // 0x80802FA0: jal         0x80800A24
    // 0x80802FA4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800A24_chhandcart(rdram, ctx);
        goto after_23;
    // 0x80802FA4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_23:
    // 0x80802FA8: b           L_808031B4
    // 0x80802FAC: nop

        goto L_808031B4;
    // 0x80802FAC: nop

L_80802FB0:
    // 0x80802FB0: jal         0x80800998
    // 0x80802FB4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    func_80800998_chhandcart(rdram, ctx);
        goto after_24;
    // 0x80802FB4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_24:
    // 0x80802FB8: b           L_808031B4
    // 0x80802FBC: nop

        goto L_808031B4;
    // 0x80802FBC: nop

L_80802FC0:
    // 0x80802FC0: jal         0x80800024
    // 0x80802FC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800024_chhandcart(rdram, ctx);
        goto after_25;
    // 0x80802FC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_25:
    // 0x80802FC8: jal         0x800FDC28
    // 0x80802FCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_26;
    // 0x80802FCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x80802FD0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80802FD4: jal         0x80800EE4
    // 0x80802FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800EE4_chhandcart(rdram, ctx);
        goto after_27;
    // 0x80802FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80802FDC: jal         0x80800214
    // 0x80802FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800214_chhandcart(rdram, ctx);
        goto after_28;
    // 0x80802FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80802FE4: b           L_808031B4
    // 0x80802FE8: nop

        goto L_808031B4;
    // 0x80802FE8: nop

L_80802FEC:
    // 0x80802FEC: jal         0x80105AE8
    // 0x80802FF0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80105AE8(rdram, ctx);
        goto after_29;
    // 0x80802FF0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_29:
    // 0x80802FF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X457C) << 16);
    // 0x80802FF8: lwc1        $f16, 0x457C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X457C));
    // 0x80802FFC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80803000: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803004: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80803008: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8080300C: bc1f        L_80803044
    if (!c1cs) {
        // 0x80803010: nop
    
            goto L_80803044;
    }
    // 0x80803010: nop

    // 0x80803014: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80803018: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080301C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803020: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x80803024: bgez        $t6, L_80803034
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80803028: nop
    
            goto L_80803034;
    }
    // 0x80803028: nop

    // 0x8080302C: b           L_80803034
    // 0x80803030: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80803034;
    // 0x80803030: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80803034:
    // 0x80803034: jal         0x80800A24
    // 0x80803038: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800A24_chhandcart(rdram, ctx);
        goto after_30;
    // 0x80803038: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_30:
    // 0x8080303C: b           L_808031B4
    // 0x80803040: nop

        goto L_808031B4;
    // 0x80803040: nop

L_80803044:
    // 0x80803044: jal         0x80800998
    // 0x80803048: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    func_80800998_chhandcart(rdram, ctx);
        goto after_31;
    // 0x80803048: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    after_31:
    // 0x8080304C: b           L_808031B4
    // 0x80803050: nop

        goto L_808031B4;
    // 0x80803050: nop

L_80803054:
    // 0x80803054: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80803058: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080305C: b           L_808031B4
    // 0x80803060: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_808031B4;
    // 0x80803060: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80803064:
    // 0x80803064: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80803068: jal         0x800D0A9C
    // 0x8080306C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_32;
    // 0x8080306C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80803070: beq         $v0, $zero, L_80803084
    if (ctx->r2 == 0) {
        // 0x80803074: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80803084;
    }
    // 0x80803074: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803078: addiu       $t7, $zero, 0xF88
    ctx->r15 = ADD32(0, 0XF88);
    // 0x8080307C: b           L_8080308C
    // 0x80803080: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_8080308C;
    // 0x80803080: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80803084:
    // 0x80803084: addiu       $t8, $zero, 0xF83
    ctx->r24 = ADD32(0, 0XF83);
    // 0x80803088: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8080308C:
    // 0x8080308C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80803090: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80803094: jal         0x80800858
    // 0x80803098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800858_chhandcart(rdram, ctx);
        goto after_33;
    // 0x80803098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_33:
    // 0x8080309C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808030A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808030A4: jal         0x808023B4
    // 0x808030A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_34;
    // 0x808030A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_34:
    // 0x808030AC: jal         0x800FDC28
    // 0x808030B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_35;
    // 0x808030B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_35:
    // 0x808030B4: jal         0x800FC660
    // 0x808030B8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC660(rdram, ctx);
        goto after_36;
    // 0x808030B8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_36:
    // 0x808030BC: b           L_808031B4
    // 0x808030C0: nop

        goto L_808031B4;
    // 0x808030C0: nop

L_808030C4:
    // 0x808030C4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x808030C8: jal         0x80090658
    // 0x808030CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090658(rdram, ctx);
        goto after_37;
    // 0x808030CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_37:
    // 0x808030D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808030D4: jal         0x80090734
    // 0x808030D8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80090734(rdram, ctx);
        goto after_38;
    // 0x808030D8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_38:
    // 0x808030DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808030E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808030E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808030E8: jal         0x80800858
    // 0x808030EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800858_chhandcart(rdram, ctx);
        goto after_39;
    // 0x808030EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_39:
    // 0x808030F0: jal         0x80800090
    // 0x808030F4: nop

    func_80800090_chhandcart(rdram, ctx);
        goto after_40;
    // 0x808030F4: nop

    after_40:
    // 0x808030F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808030FC: beq         $v0, $at, L_80803118
    if (ctx->r2 == ctx->r1) {
        // 0x80803100: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_80803118;
    }
    // 0x80803100: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80803104: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803108: beq         $v0, $at, L_8080313C
    if (ctx->r2 == ctx->r1) {
        // 0x8080310C: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_8080313C;
    }
    // 0x8080310C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80803110: b           L_80803160
    // 0x80803114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80803160;
    // 0x80803114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803118:
    // 0x80803118: jal         0x800D0A9C
    // 0x8080311C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_41;
    // 0x8080311C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_41:
    // 0x80803120: beq         $v0, $zero, L_80803134
    if (ctx->r2 == 0) {
        // 0x80803124: addiu       $t0, $zero, 0xF82
        ctx->r8 = ADD32(0, 0XF82);
            goto L_80803134;
    }
    // 0x80803124: addiu       $t0, $zero, 0xF82
    ctx->r8 = ADD32(0, 0XF82);
    // 0x80803128: addiu       $t9, $zero, 0xF87
    ctx->r25 = ADD32(0, 0XF87);
    // 0x8080312C: b           L_8080315C
    // 0x80803130: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
        goto L_8080315C;
    // 0x80803130: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_80803134:
    // 0x80803134: b           L_8080315C
    // 0x80803138: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
        goto L_8080315C;
    // 0x80803138: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_8080313C:
    // 0x8080313C: jal         0x800D0A9C
    // 0x80803140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_42;
    // 0x80803140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_42:
    // 0x80803144: beq         $v0, $zero, L_80803158
    if (ctx->r2 == 0) {
        // 0x80803148: addiu       $t2, $zero, 0xF84
        ctx->r10 = ADD32(0, 0XF84);
            goto L_80803158;
    }
    // 0x80803148: addiu       $t2, $zero, 0xF84
    ctx->r10 = ADD32(0, 0XF84);
    // 0x8080314C: addiu       $t1, $zero, 0xF89
    ctx->r9 = ADD32(0, 0XF89);
    // 0x80803150: b           L_8080315C
    // 0x80803154: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
        goto L_8080315C;
    // 0x80803154: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
L_80803158:
    // 0x80803158: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
L_8080315C:
    // 0x8080315C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803160:
    // 0x80803160: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80803164: jal         0x808023B4
    // 0x80803168: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_43;
    // 0x80803168: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_43:
    // 0x8080316C: b           L_808031B4
    // 0x80803170: nop

        goto L_808031B4;
    // 0x80803170: nop

L_80803174:
    // 0x80803174: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80803178: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080317C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803180: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80803184: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80803188: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8080318C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803190: jal         0x801058C4
    // 0x80803194: lh          $a1, 0xC($t3)
    ctx->r5 = MEM_H(ctx->r11, 0XC);
    func_801058C4(rdram, ctx);
        goto after_44;
    // 0x80803194: lh          $a1, 0xC($t3)
    ctx->r5 = MEM_H(ctx->r11, 0XC);
    after_44:
    // 0x80803198: jal         0x80802BC8
    // 0x8080319C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BC8_chhandcart(rdram, ctx);
        goto after_45;
    // 0x8080319C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x808031A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808031A4: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x808031A8: addiu       $a2, $zero, 0x20B0
    ctx->r6 = ADD32(0, 0X20B0);
    // 0x808031AC: jal         0x8080090C
    // 0x808031B0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    func_8080090C_chhandcart(rdram, ctx);
        goto after_46;
    // 0x808031B0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_46:
L_808031B4:
    // 0x808031B4: jal         0x80800F4C
    // 0x808031B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F4C_chhandcart(rdram, ctx);
        goto after_47;
    // 0x808031B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x808031BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808031C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808031C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808031C8: jr          $ra
    // 0x808031CC: nop

    return;
    // 0x808031CC: nop

;}
RECOMP_FUNC void func_8008BEB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BEB4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008BEB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008BEBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008BEC0: lbu         $v0, 0x1B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1B);
    // 0x8008BEC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008BEC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008BECC: bnel        $v0, $at, L_8008BF20
    if (ctx->r2 != ctx->r1) {
        // 0x8008BED0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008BF20;
    }
    goto skip_0;
    // 0x8008BED0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x8008BED4: lbu         $t6, 0x1D($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1D);
    // 0x8008BED8: bnel        $t6, $zero, L_8008BF20
    if (ctx->r14 != 0) {
        // 0x8008BEDC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008BF20;
    }
    goto skip_1;
    // 0x8008BEDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x8008BEE0: jal         0x8008BC94
    // 0x8008BEE4: nop

    func_8008BC94(rdram, ctx);
        goto after_0;
    // 0x8008BEE4: nop

    after_0:
    // 0x8008BEE8: beql        $v0, $zero, L_8008BF34
    if (ctx->r2 == 0) {
        // 0x8008BEEC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8008BF34;
    }
    goto skip_2;
    // 0x8008BEEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_2:
    // 0x8008BEF0: lbu         $t7, 0x8($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X8);
    // 0x8008BEF4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008BEF8: beql        $t7, $zero, L_8008BF0C
    if (ctx->r15 == 0) {
        // 0x8008BEFC: sb          $t8, 0x8($s0)
        MEM_B(0X8, ctx->r16) = ctx->r24;
            goto L_8008BF0C;
    }
    goto skip_3;
    // 0x8008BEFC: sb          $t8, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r24;
    skip_3:
    // 0x8008BF00: b           L_8008BF0C
    // 0x8008BF04: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
        goto L_8008BF0C;
    // 0x8008BF04: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // 0x8008BF08: sb          $t8, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r24;
L_8008BF0C:
    // 0x8008BF0C: jal         0x8008BC4C
    // 0x8008BF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BC4C(rdram, ctx);
        goto after_1;
    // 0x8008BF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8008BF14: b           L_8008BF34
    // 0x8008BF18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_8008BF34;
    // 0x8008BF18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008BF1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8008BF20:
    // 0x8008BF20: bnel        $v0, $at, L_8008BF34
    if (ctx->r2 != ctx->r1) {
        // 0x8008BF24: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8008BF34;
    }
    goto skip_4;
    // 0x8008BF24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_4:
    // 0x8008BF28: jal         0x8008BC2C
    // 0x8008BF2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BC2C(rdram, ctx);
        goto after_2;
    // 0x8008BF2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8008BF30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8008BF34:
    // 0x8008BF34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008BF38: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8008BF3C: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x8008BF40: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8008BF44: nop

    // 0x8008BF48: bc1t        L_8008BF5C
    if (c1cs) {
        // 0x8008BF4C: nop
    
            goto L_8008BF5C;
    }
    // 0x8008BF4C: nop

    // 0x8008BF50: lbu         $t9, 0x1A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1A);
    // 0x8008BF54: beq         $t9, $zero, L_8008BFE0
    if (ctx->r25 == 0) {
        // 0x8008BF58: nop
    
            goto L_8008BFE0;
    }
    // 0x8008BF58: nop

L_8008BF5C:
    // 0x8008BF5C: jal         0x8008BCB4
    // 0x8008BF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BCB4(rdram, ctx);
        goto after_3;
    // 0x8008BF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008BF64: beq         $v0, $zero, L_8008BFE0
    if (ctx->r2 == 0) {
        // 0x8008BF68: nop
    
            goto L_8008BFE0;
    }
    // 0x8008BF68: nop

    // 0x8008BF6C: lbu         $t0, 0x1D($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1D);
    // 0x8008BF70: bne         $t0, $zero, L_8008BFE0
    if (ctx->r8 != 0) {
        // 0x8008BF74: nop
    
            goto L_8008BFE0;
    }
    // 0x8008BF74: nop

    // 0x8008BF78: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x8008BF7C: jal         0x800D674C
    // 0x8008BF80: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    func_800D674C(rdram, ctx);
        goto after_4;
    // 0x8008BF80: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    after_4:
    // 0x8008BF84: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8008BF88: jal         0x8008BD74
    // 0x8008BF8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD74(rdram, ctx);
        goto after_5;
    // 0x8008BF8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8008BF90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008BF94: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x8008BF98: lbu         $a2, 0x1E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1E);
    // 0x8008BF9C: jal         0x800E0170
    // 0x8008BFA0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800E0170(rdram, ctx);
        goto after_6;
    // 0x8008BFA0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_6:
    // 0x8008BFA4: jal         0x8008BD1C
    // 0x8008BFA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD1C(rdram, ctx);
        goto after_7;
    // 0x8008BFA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8008BFAC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8008BFB0: jal         0x8008BD3C
    // 0x8008BFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD3C(rdram, ctx);
        goto after_8;
    // 0x8008BFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8008BFB8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8008BFBC: jal         0x8008BD74
    // 0x8008BFC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD74(rdram, ctx);
        goto after_9;
    // 0x8008BFC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8008BFC4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8008BFC8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008BFCC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8008BFD0: jal         0x800DFD64
    // 0x8008BFD4: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800DFD64(rdram, ctx);
        goto after_10;
    // 0x8008BFD4: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_10:
    // 0x8008BFD8: b           L_8008C028
    // 0x8008BFDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008C028;
    // 0x8008BFDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008BFE0:
    // 0x8008BFE0: jal         0x800D674C
    // 0x8008BFE4: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    func_800D674C(rdram, ctx);
        goto after_11;
    // 0x8008BFE4: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    after_11:
    // 0x8008BFE8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8008BFEC: jal         0x8008BD1C
    // 0x8008BFF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD1C(rdram, ctx);
        goto after_12;
    // 0x8008BFF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8008BFF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008BFF8: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x8008BFFC: lbu         $a2, 0x1E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1E);
    // 0x8008C000: jal         0x800E0170
    // 0x8008C004: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800E0170(rdram, ctx);
        goto after_13;
    // 0x8008C004: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_13:
    // 0x8008C008: lbu         $t1, 0x1D($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1D);
    // 0x8008C00C: beql        $t1, $zero, L_8008C028
    if (ctx->r9 == 0) {
        // 0x8008C010: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008C028;
    }
    goto skip_5;
    // 0x8008C010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8008C014: lh          $t2, 0x18($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X18);
    // 0x8008C018: beql        $t2, $zero, L_8008C028
    if (ctx->r10 == 0) {
        // 0x8008C01C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008C028;
    }
    goto skip_6;
    // 0x8008C01C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8008C020: sb          $zero, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = 0;
    // 0x8008C024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008C028:
    // 0x8008C028: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C02C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008C030: jr          $ra
    // 0x8008C034: nop

    return;
    // 0x8008C034: nop

;}
RECOMP_FUNC void _baduo_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084988: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084988);
    return;
    // 0x8008498C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void _subaddiepalette_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A080: syscall     825
    recomp_syscall_handler(rdram, ctx, 0x8008A080);
    return;
    // 0x8008A084: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800A4C_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A54: jal         0x808001DC
    // 0x80800A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001DC_bsswim(rdram, ctx);
        goto after_0;
    // 0x80800A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A5C: jal         0x800839C8
    // 0x80800A60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800A60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A6C: jr          $ra
    // 0x80800A70: nop

    return;
    // 0x80800A70: nop

;}
RECOMP_FUNC void func_800AE290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE290: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800AE294: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AE298: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x800AE29C: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800AE2A0: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x800AE2A4: sll         $a0, $t6, 16
    ctx->r4 = S32(ctx->r14 << 16);
    // 0x800AE2A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800AE2AC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800AE2B0: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE2B4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800AE2B8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800AE2BC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800AE2C0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800AE2C4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800AE2C8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800AE2CC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800AE2D0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800AE2D4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800AE2D8: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x800AE2DC: jal         0x800AE080
    // 0x800AE2E0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x800AE2E0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x800AE2E4: lh          $s2, 0x4($s3)
    ctx->r18 = MEM_H(ctx->r19, 0X4);
    // 0x800AE2E8: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800AE2EC: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800AE2F0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800AE2F4: slt         $at, $t8, $s2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800AE2F8: beq         $at, $zero, L_800AE320
    if (ctx->r1 == 0) {
        // 0x800AE2FC: sra         $t9, $a0, 16
        ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
            goto L_800AE320;
    }
    // 0x800AE2FC: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE300: sll         $a1, $s2, 6
    ctx->r5 = S32(ctx->r18 << 6);
    // 0x800AE304: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x800AE308: jal         0x8001B710
    // 0x800AE30C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_8001B710(rdram, ctx);
        goto after_1;
    // 0x800AE30C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x800AE310: lh          $t0, 0x4($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X4);
    // 0x800AE314: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800AE318: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800AE31C: lh          $s2, 0x4($s3)
    ctx->r18 = MEM_H(ctx->r19, 0X4);
L_800AE320:
    // 0x800AE320: sll         $t2, $s2, 6
    ctx->r10 = S32(ctx->r18 << 6);
    // 0x800AE324: addu        $s4, $t2, $v0
    ctx->r20 = ADD32(ctx->r10, ctx->r2);
    // 0x800AE328: addiu       $s4, $s4, 0x50
    ctx->r20 = ADD32(ctx->r20, 0X50);
    // 0x800AE32C: addiu       $s0, $v0, 0x50
    ctx->r16 = ADD32(ctx->r2, 0X50);
    // 0x800AE330: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x800AE334: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x800AE338: beq         $at, $zero, L_800AE3DC
    if (ctx->r1 == 0) {
        // 0x800AE33C: addiu       $s1, $s3, 0x8
        ctx->r17 = ADD32(ctx->r19, 0X8);
            goto L_800AE3DC;
    }
    // 0x800AE33C: addiu       $s1, $s3, 0x8
    ctx->r17 = ADD32(ctx->r19, 0X8);
    // 0x800AE340: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x800AE344: addiu       $s7, $sp, 0x5C
    ctx->r23 = ADD32(ctx->r29, 0X5C);
    // 0x800AE348: addiu       $s6, $sp, 0x68
    ctx->r22 = ADD32(ctx->r29, 0X68);
    // 0x800AE34C: addiu       $s3, $sp, 0x84
    ctx->r19 = ADD32(ctx->r29, 0X84);
    // 0x800AE350: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
L_800AE354:
    // 0x800AE354: lh          $a1, 0xC($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XC);
    // 0x800AE358: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x800AE35C: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x800AE360: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800AE364: jal         0x800DFB7C
    // 0x800AE368: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_800DFB7C(rdram, ctx);
        goto after_2;
    // 0x800AE368: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_2:
    // 0x800AE36C: lh          $v0, 0xE($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XE);
    // 0x800AE370: addiu       $v1, $s5, 0x50
    ctx->r3 = ADD32(ctx->r21, 0X50);
    // 0x800AE374: subu        $t3, $s0, $v1
    ctx->r11 = SUB32(ctx->r16, ctx->r3);
    // 0x800AE378: bne         $fp, $v0, L_800AE390
    if (ctx->r30 != ctx->r2) {
        // 0x800AE37C: sra         $t4, $t3, 6
        ctx->r12 = S32(SIGNED(ctx->r11) >> 6);
            goto L_800AE390;
    }
    // 0x800AE37C: sra         $t4, $t3, 6
    ctx->r12 = S32(SIGNED(ctx->r11) >> 6);
    // 0x800AE380: jal         0x80019CD4
    // 0x800AE384: nop

    func_80019CD4(rdram, ctx);
        goto after_3;
    // 0x800AE384: nop

    after_3:
    // 0x800AE388: b           L_800AE3A4
    // 0x800AE38C: nop

        goto L_800AE3A4;
    // 0x800AE38C: nop

L_800AE390:
    // 0x800AE390: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x800AE394: beq         $t4, $t5, L_800AE3A4
    if (ctx->r12 == ctx->r13) {
        // 0x800AE398: sll         $t6, $v0, 6
        ctx->r14 = S32(ctx->r2 << 6);
            goto L_800AE3A4;
    }
    // 0x800AE398: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x800AE39C: jal         0x80018EFC
    // 0x800AE3A0: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    mlMtxSet(rdram, ctx);
        goto after_4;
    // 0x800AE3A0: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_4:
L_800AE3A4:
    // 0x800AE3A4: jal         0x800D9C4C
    // 0x800AE3A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800D9C4C(rdram, ctx);
        goto after_5;
    // 0x800AE3A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x800AE3AC: bne         $v0, $zero, L_800AE3C4
    if (ctx->r2 != 0) {
        // 0x800AE3B0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800AE3C4;
    }
    // 0x800AE3B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AE3B4: jal         0x800D9CE8
    // 0x800AE3B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800D9CE8(rdram, ctx);
        goto after_6;
    // 0x800AE3B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
    // 0x800AE3BC: jal         0x80019BB8
    // 0x800AE3C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80019BB8(rdram, ctx);
        goto after_7;
    // 0x800AE3C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
L_800AE3C4:
    // 0x800AE3C4: jal         0x80018AD0
    // 0x800AE3C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mlMtxGet(rdram, ctx);
        goto after_8;
    // 0x800AE3C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800AE3CC: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x800AE3D0: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x800AE3D4: bne         $at, $zero, L_800AE354
    if (ctx->r1 != 0) {
        // 0x800AE3D8: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_800AE354;
    }
    // 0x800AE3D8: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_800AE3DC:
    // 0x800AE3DC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800AE3E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800AE3E4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800AE3E8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800AE3EC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800AE3F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800AE3F4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800AE3F8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800AE3FC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE400: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800AE404: jr          $ra
    // 0x800AE408: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800AE408: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void boot_inflate_stored(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000CB4: mfc1        $t2, $f17
    ctx->r10 = (int32_t)ctx->f_odd[(17 - 1) * 2];
    // 0x80000CB8: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80000CBC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80000CC0: andi        $t3, $fp, 0x7
    ctx->r11 = ctx->r30 & 0X7;
    // 0x80000CC4: srlv        $gp, $gp, $t3
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r11 & 31));
    // 0x80000CC8: subu        $fp, $fp, $t3
    ctx->r30 = SUB32(ctx->r30, ctx->r11);
    // 0x80000CCC: slti        $at, $fp, 0x10
    ctx->r1 = SIGNED(ctx->r30) < 0X10 ? 1 : 0;
    // 0x80000CD0: beq         $at, $zero, L_80000CF8
    if (ctx->r1 == 0) {
        // 0x80000CD4: nop
    
            goto L_80000CF8;
    }
    // 0x80000CD4: nop

    // 0x80000CD8: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_80000CDC:
    // 0x80000CDC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80000CE0: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x80000CE4: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x80000CE8: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80000CEC: slti        $at, $fp, 0x10
    ctx->r1 = SIGNED(ctx->r30) < 0X10 ? 1 : 0;
    // 0x80000CF0: bnel        $at, $zero, L_80000CDC
    if (ctx->r1 != 0) {
        // 0x80000CF4: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_80000CDC;
    }
    goto skip_0;
    // 0x80000CF4: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_0:
L_80000CF8:
    // 0x80000CF8: andi        $t3, $gp, 0xFFFF
    ctx->r11 = ctx->r28 & 0XFFFF;
    // 0x80000CFC: srl         $gp, $gp, 16
    ctx->r28 = S32(U32(ctx->r28) >> 16);
    // 0x80000D00: addiu       $fp, $fp, -0x10
    ctx->r30 = ADD32(ctx->r30, -0X10);
    // 0x80000D04: slti        $at, $fp, 0x10
    ctx->r1 = SIGNED(ctx->r30) < 0X10 ? 1 : 0;
    // 0x80000D08: beq         $at, $zero, L_80000D30
    if (ctx->r1 == 0) {
        // 0x80000D0C: nop
    
            goto L_80000D30;
    }
    // 0x80000D0C: nop

    // 0x80000D10: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_80000D14:
    // 0x80000D14: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80000D18: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x80000D1C: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x80000D20: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80000D24: slti        $at, $fp, 0x10
    ctx->r1 = SIGNED(ctx->r30) < 0X10 ? 1 : 0;
    // 0x80000D28: bnel        $at, $zero, L_80000D14
    if (ctx->r1 != 0) {
        // 0x80000D2C: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_80000D14;
    }
    goto skip_1;
    // 0x80000D2C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_1:
L_80000D30:
    // 0x80000D30: nor         $t5, $gp, $zero
    ctx->r13 = ~(ctx->r28 | 0);
    // 0x80000D34: andi        $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 & 0XFFFF;
    // 0x80000D38: bne         $t3, $t5, L_80000DD4
    if (ctx->r11 != ctx->r13) {
        // 0x80000D3C: srl         $gp, $gp, 16
        ctx->r28 = S32(U32(ctx->r28) >> 16);
            goto L_80000DD4;
    }
    // 0x80000D3C: srl         $gp, $gp, 16
    ctx->r28 = S32(U32(ctx->r28) >> 16);
    // 0x80000D40: addiu       $fp, $fp, -0x10
    ctx->r30 = ADD32(ctx->r30, -0X10);
    // 0x80000D44: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80000D48: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80000D4C: beq         $at, $zero, L_80000DD4
    if (ctx->r1 == 0) {
        // 0x80000D50: addu        $t5, $t7, $t2
        ctx->r13 = ADD32(ctx->r15, ctx->r10);
            goto L_80000DD4;
    }
    // 0x80000D50: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x80000D54: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x80000D58: beq         $t3, $zero, L_80000DC8
    if (ctx->r11 == 0) {
        // 0x80000D5C: addiu       $t3, $t3, -0x1
        ctx->r11 = ADD32(ctx->r11, -0X1);
            goto L_80000DC8;
    }
    // 0x80000D5C: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
L_80000D60:
    // 0x80000D60: slti        $at, $fp, 0x8
    ctx->r1 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
    // 0x80000D64: beq         $at, $zero, L_80000D8C
    if (ctx->r1 == 0) {
        // 0x80000D68: nop
    
            goto L_80000D8C;
    }
    // 0x80000D68: nop

    // 0x80000D6C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_80000D70:
    // 0x80000D70: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80000D74: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x80000D78: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x80000D7C: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80000D80: slti        $at, $fp, 0x8
    ctx->r1 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
    // 0x80000D84: bnel        $at, $zero, L_80000D70
    if (ctx->r1 != 0) {
        // 0x80000D88: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_80000D70;
    }
    goto skip_2;
    // 0x80000D88: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_2:
L_80000D8C:
    // 0x80000D8C: sb          $gp, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r28;
    // 0x80000D90: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80000D94: lw          $v0, 0xA84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA84);
    // 0x80000D98: andi        $v1, $gp, 0xFF
    ctx->r3 = ctx->r28 & 0XFF;
    // 0x80000D9C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80000DA0: sw          $v0, 0xA84($sp)
    MEM_W(0XA84, ctx->r29) = ctx->r2;
    // 0x80000DA4: andi        $v0, $v0, 0x17
    ctx->r2 = ctx->r2 & 0X17;
    // 0x80000DA8: sllv        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3 << (ctx->r2 & 31));
    // 0x80000DAC: lw          $v0, 0xA88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA88);
    // 0x80000DB0: xor         $v0, $v0, $v1
    ctx->r2 = ctx->r2 ^ ctx->r3;
    // 0x80000DB4: sw          $v0, 0xA88($sp)
    MEM_W(0XA88, ctx->r29) = ctx->r2;
    // 0x80000DB8: srl         $gp, $gp, 8
    ctx->r28 = S32(U32(ctx->r28) >> 8);
    // 0x80000DBC: addiu       $fp, $fp, -0x8
    ctx->r30 = ADD32(ctx->r30, -0X8);
    // 0x80000DC0: bne         $t3, $zero, L_80000D60
    if (ctx->r11 != 0) {
        // 0x80000DC4: addiu       $t3, $t3, -0x1
        ctx->r11 = ADD32(ctx->r11, -0X1);
            goto L_80000D60;
    }
    // 0x80000DC4: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
L_80000DC8:
    // 0x80000DC8: mtc1        $t2, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r10;
    // 0x80000DCC: jr          $ra
    // 0x80000DD0: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x80000DD0: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_80000DD4:
    // 0x80000DD4: jr          $ra
    // 0x80000DD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80000DD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800C5A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5A10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C5A14: bne         $a1, $at, L_800C5A20
    if (ctx->r5 != ctx->r1) {
        // 0x800C5A18: addiu       $t6, $zero, 0x5
        ctx->r14 = ADD32(0, 0X5);
            goto L_800C5A20;
    }
    // 0x800C5A18: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800C5A1C: sb          $t6, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r14;
L_800C5A20:
    // 0x800C5A20: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800C5A24: bne         $a1, $at, L_800C5A30
    if (ctx->r5 != ctx->r1) {
        // 0x800C5A28: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800C5A30;
    }
    // 0x800C5A28: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C5A2C: sb          $t7, 0x92($a0)
    MEM_B(0X92, ctx->r4) = ctx->r15;
L_800C5A30:
    // 0x800C5A30: jr          $ra
    // 0x800C5A34: sb          $a1, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r5;
    return;
    // 0x800C5A34: sb          $a1, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _chmusicmenu_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E68: syscall     463
    recomp_syscall_handler(rdram, ctx, 0x80086E68);
    return;
    // 0x80086E6C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800EF4_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800F00: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80800F04: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800F08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800F0C: jal         0x800A5800
    // 0x80800F10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800A5800(rdram, ctx);
        goto after_0;
    // 0x80800F10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800F14: jal         0x80085580
    // 0x80800F18: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800F18: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800F1C: jal         0x80085590
    // 0x80800F20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800F20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F2C: jr          $ra
    // 0x80800F30: nop

    return;
    // 0x80800F30: nop

;}
RECOMP_FUNC void func_800C7A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A60: jr          $ra
    // 0x800C7A64: nop

    return;
    // 0x800C7A64: nop

;}
RECOMP_FUNC void chblink_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080030C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800314: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80800318: jal         0x8001B754
    // 0x8080031C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B754(rdram, ctx);
        goto after_0;
    // 0x8080031C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x80800320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800328: jr          $ra
    // 0x8080032C: nop

    return;
    // 0x8080032C: nop

;}
RECOMP_FUNC void baeggaim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801DA0_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DA0: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x80801DA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801DA8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801DAC: lui         $at, 0x432B
    ctx->r1 = S32(0X432B << 16);
    // 0x80801DB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801DB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801DB8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80801DBC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80801DC0: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80801DC4: jal         0x800DF410
    // 0x80801DC8: lh          $a0, 0x2A($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2A);
    func_800DF410(rdram, ctx);
        goto after_0;
    // 0x80801DC8: lh          $a0, 0x2A($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2A);
    after_0:
    // 0x80801DCC: jal         0x800D674C
    // 0x80801DD0: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80801DD0: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_1:
    // 0x80801DD4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801DD8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80801DDC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801DE0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80801DE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80801DE8: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    // 0x80801DEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801DF0: jal         0x800DF944
    // 0x80801DF4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800DF944(rdram, ctx);
        goto after_2;
    // 0x80801DF4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x80801DF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801DFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801E00: jr          $ra
    // 0x80801E04: nop

    return;
    // 0x80801E04: nop

;}
RECOMP_FUNC void _chbounce_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858E8: syscall     180
    recomp_syscall_handler(rdram, ctx, 0x800858E8);
    return;
    // 0x800858EC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808094F4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808094F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808094F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808094FC: jal         0x80809540
    // 0x80809500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80809540_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80809500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80809504: beq         $v0, $zero, L_80809528
    if (ctx->r2 == 0) {
        // 0x80809508: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80809528;
    }
    // 0x80809508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080950C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80809510: beq         $v0, $at, L_80809530
    if (ctx->r2 == ctx->r1) {
        // 0x80809514: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80809530;
    }
    // 0x80809514: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80809518: beq         $v0, $at, L_80809530
    if (ctx->r2 == ctx->r1) {
        // 0x8080951C: nop
    
            goto L_80809530;
    }
    // 0x8080951C: nop

    // 0x80809520: b           L_80809538
    // 0x80809524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80809538;
    // 0x80809524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80809528:
    // 0x80809528: b           L_80809538
    // 0x8080952C: addiu       $v0, $zero, 0xCA
    ctx->r2 = ADD32(0, 0XCA);
        goto L_80809538;
    // 0x8080952C: addiu       $v0, $zero, 0xCA
    ctx->r2 = ADD32(0, 0XCA);
L_80809530:
    // 0x80809530: b           L_80809538
    // 0x80809534: addiu       $v0, $zero, 0xD1
    ctx->r2 = ADD32(0, 0XD1);
        goto L_80809538;
    // 0x80809534: addiu       $v0, $zero, 0xD1
    ctx->r2 = ADD32(0, 0XD1);
L_80809538:
    // 0x80809538: jr          $ra
    // 0x8080953C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080953C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800F14AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F14AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F14B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F14B4: jal         0x800F1434
    // 0x800F14B8: nop

    func_800F1434(rdram, ctx);
        goto after_0;
    // 0x800F14B8: nop

    after_0:
    // 0x800F14BC: jal         0x800F1434
    // 0x800F14C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F1434(rdram, ctx);
        goto after_1;
    // 0x800F14C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x800F14C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F14C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F14CC: jr          $ra
    // 0x800F14D0: nop

    return;
    // 0x800F14D0: nop

;}
RECOMP_FUNC void func_800D8F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8F50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D8F54: lwc1        $f0, 0x5D10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D10);
    // 0x800D8F58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D8F5C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800D8F60: nop

    // 0x800D8F64: bc1f        L_800D8F78
    if (!c1cs) {
        // 0x800D8F68: nop
    
            goto L_800D8F78;
    }
    // 0x800D8F68: nop

    // 0x800D8F6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D8F70: jr          $ra
    // 0x800D8F74: swc1        $f12, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800D8F74: swc1        $f12, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->f12.u32l;
L_800D8F78:
    // 0x800D8F78: swc1        $f0, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->f0.u32l;
    // 0x800D8F7C: jr          $ra
    // 0x800D8F80: nop

    return;
    // 0x800D8F80: nop

;}
RECOMP_FUNC void _chevilmumbo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BB8: syscall     426
    recomp_syscall_handler(rdram, ctx, 0x80086BB8);
    return;
    // 0x80086BBC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800028_ncbajig(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: jal         0x80112524
    // 0x80800034: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800034: nop

    after_0:
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080003C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void bskazdie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800090: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800094: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800098: jal         0x8008CABC
    // 0x8080009C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080009C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000A0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808000A4: jal         0x800832E0
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000AC: jal         0x8008AF24
    // 0x808000B0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x808000B0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x808000B4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808000B8: jal         0x8008B1A0
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_3;
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808000C0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808000C4: jal         0x8008AED4
    // 0x808000C8: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x808000C8: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    after_4:
    // 0x808000CC: lui         $a2, 0x3E7B
    ctx->r6 = S32(0X3E7B << 16);
    // 0x808000D0: ori         $a2, $a2, 0xE76D
    ctx->r6 = ctx->r6 | 0XE76D;
    // 0x808000D4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808000D8: jal         0x8008B1D4
    // 0x808000DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x808000DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x808000E0: lui         $a1, 0x406C
    ctx->r5 = S32(0X406C << 16);
    // 0x808000E4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808000E8: jal         0x8008B1BC
    // 0x808000EC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x808000EC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_6:
    // 0x808000F0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808000F4: jal         0x8008B134
    // 0x808000F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x808000F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808000FC: jal         0x8008B064
    // 0x80800100: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x80800100: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_8:
    // 0x80800104: jal         0x80085208
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080010C: lui         $a1, 0x3FE6
    ctx->r5 = S32(0X3FE6 << 16);
    // 0x80800110: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800114: jal         0x8009D820
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D820(rdram, ctx);
        goto after_10;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x8009C128
    // 0x80800124: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_8009C128(rdram, ctx);
        goto after_11;
    // 0x80800124: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_11:
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x800A32C4
    // 0x80800130: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800A32C4(rdram, ctx);
        goto after_12;
    // 0x80800130: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_12:
    // 0x80800134: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800138: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080013C: jal         0x800F1E6C
    // 0x80800140: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800F1E6C(rdram, ctx);
        goto after_13;
    // 0x80800140: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_13:
    // 0x80800144: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800148: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080014C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800150: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800154: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    // 0x80800158: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8080015C: jal         0x800136E4
    // 0x80800160: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_14;
    // 0x80800160: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_14:
    // 0x80800164: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800168: jal         0x8009C914
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_15;
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800170: jal         0x8009C974
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_16;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: jal         0x8009B9B0
    // 0x80800180: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800180: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_17:
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x8009B9C0
    // 0x8080018C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_18;
    // 0x8080018C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_18:
    // 0x80800190: jal         0x8009BB00
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800198: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: jal         0x8009BA68
    // 0x808001A4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_20;
    // 0x808001A4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_20:
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x8008CA4C
    // 0x808001B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_21;
    // 0x808001B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: jal         0x8009C908
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_22;
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: jal         0x8009D2D8
    // 0x808001C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009D2D8(rdram, ctx);
        goto after_23;
    // 0x808001C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_23:
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x8009B800
    // 0x808001D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baphysics_set_type(rdram, ctx);
        goto after_24;
    // 0x808001D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_24:
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: jal         0x8009BA58
    // 0x808001E0: lui         $a1, 0x43FF
    ctx->r5 = S32(0X43FF << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_25;
    // 0x808001E0: lui         $a1, 0x43FF
    ctx->r5 = S32(0X43FF << 16);
    after_25:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x8009BCB4
    // 0x808001EC: lui         $a1, 0xC4AF
    ctx->r5 = S32(0XC4AF << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_26;
    // 0x808001EC: lui         $a1, 0xC4AF
    ctx->r5 = S32(0XC4AF << 16);
    after_26:
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808001F8: jal         0x8009BFE4
    // 0x808001FC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_27;
    // 0x808001FC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_27:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x800A4DFC
    // 0x80800208: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A4DFC(rdram, ctx);
        goto after_28;
    // 0x80800208: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_28:
    // 0x8080020C: jal         0x800A4CA8
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_29;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800214: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800218: jal         0x80089288
    // 0x8080021C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _ncbadie_entrypoint_3(rdram, ctx);
        goto after_30;
    // 0x8080021C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_30:
    // 0x80800220: jal         0x800A0180
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0180(rdram, ctx);
        goto after_31;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800230: jal         0x80085338
    // 0x80800234: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    _batimer_set(rdram, ctx);
        goto after_32;
    // 0x80800234: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_32:
    // 0x80800238: jal         0x8008E944
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_33;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80800240: jal         0x8009514C
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_34;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800248: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x8080024C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800254: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800258: jr          $ra
    // 0x8080025C: nop

    return;
    // 0x8080025C: nop

;}
RECOMP_FUNC void func_80114BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114BDC: jal         0x8001ACCC
    // 0x80114BE0: addiu       $a0, $zero, 0x9C
    ctx->r4 = ADD32(0, 0X9C);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x80114BE0: addiu       $a0, $zero, 0x9C
    ctx->r4 = ADD32(0, 0X9C);
    after_0:
    // 0x80114BE4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80114BE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80114BEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80114BF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80114BF4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80114BF8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80114BFC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80114C00: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x80114C04: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80114C08: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80114C0C: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x80114C10: sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
    // 0x80114C14: sb          $zero, 0x50($v0)
    MEM_B(0X50, ctx->r2) = 0;
    // 0x80114C18: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x80114C1C: sb          $zero, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = 0;
    // 0x80114C20: sw          $zero, 0x60($v0)
    MEM_W(0X60, ctx->r2) = 0;
    // 0x80114C24: sb          $zero, 0x68($v0)
    MEM_B(0X68, ctx->r2) = 0;
    // 0x80114C28: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80114C2C: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x80114C30: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80114C34: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
    // 0x80114C38: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80114C3C: sb          $zero, 0x74($v1)
    MEM_B(0X74, ctx->r3) = 0;
    // 0x80114C40: sw          $zero, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = 0;
    // 0x80114C44: sb          $zero, 0x68($v1)
    MEM_B(0X68, ctx->r3) = 0;
    // 0x80114C48: sw          $zero, 0x60($v1)
    MEM_W(0X60, ctx->r3) = 0;
    // 0x80114C4C: sb          $zero, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = 0;
    // 0x80114C50: sw          $zero, 0x54($v1)
    MEM_W(0X54, ctx->r3) = 0;
    // 0x80114C54: sw          $zero, 0x48($v1)
    MEM_W(0X48, ctx->r3) = 0;
    // 0x80114C58: sb          $zero, 0x50($v1)
    MEM_B(0X50, ctx->r3) = 0;
    // 0x80114C5C: swc1        $f0, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f0.u32l;
    // 0x80114C60: swc1        $f0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f0.u32l;
    // 0x80114C64: swc1        $f0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f0.u32l;
    // 0x80114C68: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x80114C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114C74: jr          $ra
    // 0x80114C78: nop

    return;
    // 0x80114C78: nop

;}
RECOMP_FUNC void func_80802384_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802384: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80802388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080238C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80802390: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80802394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802398: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080239C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808023A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808023A4: jal         0x800DC178
    // 0x808023A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x808023A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808023AC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808023B0: jal         0x800136E4
    // 0x808023B4: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x808023B4: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_1:
    // 0x808023B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808023BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808023C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808023C4: lh          $t6, 0x10($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X10);
    // 0x808023C8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808023CC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808023D0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x808023D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808023D8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808023DC: jal         0x80089F90
    // 0x808023E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x808023E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808023E4: bne         $v0, $zero, L_808023F4
    if (ctx->r2 != 0) {
        // 0x808023E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808023F4;
    }
    // 0x808023E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808023EC: b           L_808023F8
    // 0x808023F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808023F8;
    // 0x808023F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808023F4:
    // 0x808023F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808023F8:
    // 0x808023F8: jr          $ra
    // 0x808023FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808023FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bsdronewaitbabykaz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800124: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800128: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8080012C: jal         0x800878A0
    // 0x80800130: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _plsu_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800130: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800134: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800138: bne         $v0, $at, L_8080014C
    if (ctx->r2 != ctx->r1) {
        // 0x8080013C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8080014C;
    }
    // 0x8080013C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800140: jal         0x80084750
    // 0x80800144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _badata_entrypoint_34(rdram, ctx);
        goto after_1;
    // 0x80800144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800148: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8080014C:
    // 0x8080014C: jal         0x8009E5C8
    // 0x80800150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

    // 0x80800164: nop

    // 0x80800168: nop

    // 0x8080016C: nop

;}
RECOMP_FUNC void func_800D1ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1ACC: addiu       $t6, $a0, -0x40
    ctx->r14 = ADD32(ctx->r4, -0X40);
    // 0x800D1AD0: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x800D1AD4: beq         $at, $zero, L_800D1B28
    if (ctx->r1 == 0) {
        // 0x800D1AD8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800D1B28;
    }
    // 0x800D1AD8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D1ADC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D1AE0: addu        $at, $at, $t6
    gpr jr_addend_800D1AE8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D1AE4: lw          $t6, 0x5AE0($at)
    ctx->r14 = ADD32(ctx->r1, 0X5AE0);
    // 0x800D1AE8: jr          $t6
    // 0x800D1AEC: nop

    switch (jr_addend_800D1AE8 >> 2) {
        case 0: goto L_800D1AF0; break;
        case 1: goto L_800D1AF8; break;
        case 2: goto L_800D1B00; break;
        case 3: goto L_800D1B08; break;
        case 4: goto L_800D1B10; break;
        case 5: goto L_800D1B28; break;
        case 6: goto L_800D1B18; break;
        case 7: goto L_800D1B20; break;
        default: switch_error(__func__, 0x800D1AE8, 0x80125AE0);
    }
    // 0x800D1AEC: nop

L_800D1AF0:
    // 0x800D1AF0: jr          $ra
    // 0x800D1AF4: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    return;
    // 0x800D1AF4: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_800D1AF8:
    // 0x800D1AF8: jr          $ra
    // 0x800D1AFC: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    return;
    // 0x800D1AFC: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_800D1B00:
    // 0x800D1B00: jr          $ra
    // 0x800D1B04: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    return;
    // 0x800D1B04: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_800D1B08:
    // 0x800D1B08: jr          $ra
    // 0x800D1B0C: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x800D1B0C: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_800D1B10:
    // 0x800D1B10: jr          $ra
    // 0x800D1B14: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x800D1B14: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800D1B18:
    // 0x800D1B18: jr          $ra
    // 0x800D1B1C: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    return;
    // 0x800D1B1C: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_800D1B20:
    // 0x800D1B20: jr          $ra
    // 0x800D1B24: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x800D1B24: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800D1B28:
    // 0x800D1B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D1B2C: jr          $ra
    // 0x800D1B30: nop

    return;
    // 0x800D1B30: nop

;}
RECOMP_FUNC void func_808000E0_chweldarbossdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000F0: bne         $a1, $at, L_80800124
    if (ctx->r5 != ctx->r1) {
        // 0x808000F4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800124;
    }
    // 0x808000F4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808000F8: lhu         $a1, 0x76($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X76);
    // 0x808000FC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80800100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800104: srl         $t6, $a1, 7
    ctx->r14 = S32(U32(ctx->r5) >> 7);
    // 0x80800108: addiu       $a1, $t6, 0x837
    ctx->r5 = ADD32(ctx->r14, 0X837);
    // 0x8080010C: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x80800110: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80800114: jal         0x80103140
    // 0x80800118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80800118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8080011C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800120: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800124:
    // 0x80800124: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800128: jal         0x80086248
    // 0x8080012C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080012C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void _gcstatusDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088338: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088338);
    return;
    // 0x8008833C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800C6840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6840: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C6844: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C6848: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C684C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C6850: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C6854: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C6858: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C685C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C6860: addiu       $s2, $a0, 0x1C
    ctx->r18 = ADD32(ctx->r4, 0X1C);
    // 0x800C6864: addiu       $s3, $zero, 0x24
    ctx->r19 = ADD32(0, 0X24);
L_800C6868:
    // 0x800C6868: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C686C: jal         0x800EE7F8
    // 0x800C6870: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800C6870: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800C6874: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800C6878: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800C687C: bne         $s0, $s3, L_800C6868
    if (ctx->r16 != ctx->r19) {
        // 0x800C6880: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_800C6868;
    }
    // 0x800C6880: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x800C6884: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C6888: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C688C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C6890: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6894: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C6898: jr          $ra
    // 0x800C689C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C689C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8008FF18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FF18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FF1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FF20: jal         0x800F54E4
    // 0x8008FF24: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FF24: nop

    after_0:
    // 0x8008FF28: jal         0x800F5B0C
    // 0x8008FF2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5B0C(rdram, ctx);
        goto after_1;
    // 0x8008FF2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FF34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FF38: jr          $ra
    // 0x8008FF3C: nop

    return;
    // 0x8008FF3C: nop

;}
RECOMP_FUNC void _bstalk_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DA0: syscall     95
    recomp_syscall_handler(rdram, ctx, 0x80083DA0);
    return;
    // 0x80083DA4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_42(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DE8: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DE8);
    return;
    // 0x80087DEC: addi        $t0, $zero, 0xA8
    ctx->r8 = ADD32(0, 0XA8);
;}
RECOMP_FUNC void func_800C1860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1860: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1868: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x800C186C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C1870: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800C1874: sll         $t7, $t6, 19
    ctx->r15 = S32(ctx->r14 << 19);
    // 0x800C1878: srl         $t8, $t7, 29
    ctx->r24 = S32(U32(ctx->r15) >> 29);
    // 0x800C187C: bnel        $t8, $at, L_800C18BC
    if (ctx->r24 != ctx->r1) {
        // 0x800C1880: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C18BC;
    }
    goto skip_0;
    // 0x800C1880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C1884: jal         0x800C13B0
    // 0x800C1888: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800C13B0(rdram, ctx);
        goto after_0;
    // 0x800C1888: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C188C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C1890: jal         0x800C1210
    // 0x800C1894: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C1210(rdram, ctx);
        goto after_1;
    // 0x800C1894: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x800C1898: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800C189C: lbu         $v0, 0x79($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X79);
    // 0x800C18A0: beql        $v0, $zero, L_800C18BC
    if (ctx->r2 == 0) {
        // 0x800C18A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C18BC;
    }
    goto skip_1;
    // 0x800C18A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800C18A8: jal         0x800C1448
    // 0x800C18AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C1448(rdram, ctx);
        goto after_2;
    // 0x800C18AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800C18B0: jal         0x800DC4D4
    // 0x800C18B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DC4D4(rdram, ctx);
        goto after_3;
    // 0x800C18B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800C18B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C18BC:
    // 0x800C18BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C18C0: jr          $ra
    // 0x800C18C4: nop

    return;
    // 0x800C18C4: nop

;}
RECOMP_FUNC void func_80803EF4_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803EF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803EFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803F00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80803F04: jal         0x80106790
    // 0x80803F08: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80803F08: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80803F0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80803F10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803F14: jal         0x80089AC8
    // 0x80803F18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80803F18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80803F1C: beq         $v0, $zero, L_80803F3C
    if (ctx->r2 == 0) {
        // 0x80803F20: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_80803F3C;
    }
    // 0x80803F20: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80803F24: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80803F28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80803F2C: jal         0x800F5A00
    // 0x80803F30: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80803F30: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_2:
    // 0x80803F34: b           L_80803F64
    // 0x80803F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80803F64;
    // 0x80803F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803F3C:
    // 0x80803F3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80803F40: jal         0x80089AD8
    // 0x80803F44: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80803F44: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x80803F48: jal         0x80106790
    // 0x80803F4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80803F4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80803F50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80803F54: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80803F58: jal         0x800EE7F8
    // 0x80803F5C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80803F5C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_5:
    // 0x80803F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803F64:
    // 0x80803F64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803F68: jr          $ra
    // 0x80803F6C: nop

    return;
    // 0x80803F6C: nop

;}
RECOMP_FUNC void ncbapivot_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: jr          $ra
    // 0x80800094: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800094: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800C1044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C104C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C1050: jal         0x800EA34C
    // 0x800C1054: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800EA34C(rdram, ctx);
        goto after_0;
    // 0x800C1054: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C1058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C105C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1060: jr          $ra
    // 0x800C1064: nop

    return;
    // 0x800C1064: nop

    // 0x800C1068: nop

    // 0x800C106C: nop

;}
RECOMP_FUNC void func_80800B7C_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B84: jal         0x8080021C
    // 0x80800B88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080021C_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x80800B88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B8C: jal         0x800839C8
    // 0x80800B90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800B90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B9C: jr          $ra
    // 0x80800BA0: nop

    return;
    // 0x80800BA0: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842C8: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842C8);
    return;
    // 0x800842CC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _chfootwear_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087760: syscall     620
    recomp_syscall_handler(rdram, ctx, 0x80087760);
    return;
    // 0x80087764: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800BFCC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFCC4: jr          $ra
    // 0x800BFCC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800BFCC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BFCCC: nop

;}
RECOMP_FUNC void _subaddielink_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A038: syscall     823
    recomp_syscall_handler(rdram, ctx, 0x8008A038);
    return;
    // 0x8008A03C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080011C_chwandglow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800120: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800124: beq         $a1, $at, L_80800150
    if (ctx->r5 == ctx->r1) {
        // 0x80800128: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80800150;
    }
    // 0x80800128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080012C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800130: beq         $a1, $at, L_80800168
    if (ctx->r5 == ctx->r1) {
        // 0x80800134: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800168;
    }
    // 0x80800134: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800138: beq         $a1, $at, L_80800180
    if (ctx->r5 == ctx->r1) {
        // 0x8080013C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800180;
    }
    // 0x8080013C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800140: beql        $a1, $at, L_808001EC
    if (ctx->r5 == ctx->r1) {
        // 0x80800144: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_808001EC;
    }
    goto skip_0;
    // 0x80800144: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x80800148: b           L_808001F8
    // 0x8080014C: lbu         $t9, 0x72($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X72);
        goto L_808001F8;
    // 0x8080014C: lbu         $t9, 0x72($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X72);
L_80800150:
    // 0x80800150: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800154: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2164, 0X400) << 16);
    // 0x80800158: lwc1        $f16, 0x400($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2164, 0X400));
    // 0x8080015C: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
    // 0x80800160: b           L_808001F4
    // 0x80800164: swc1        $f16, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f16.u32l;
        goto L_808001F4;
    // 0x80800164: swc1        $f16, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f16.u32l;
L_80800168:
    // 0x80800168: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080016C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800170: nop

    // 0x80800174: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80800178: b           L_808001F4
    // 0x8080017C: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
        goto L_808001F4;
    // 0x8080017C: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
L_80800180:
    // 0x80800180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800184: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800188: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080018C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2164, 0X404) << 16);
    // 0x80800190: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80800194: lwc1        $f8, 0x404($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2164, 0X404));
    // 0x80800198: lwc1        $f12, 0x2C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8080019C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001A0: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808001A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001AC: jal         0x800F10B4
    // 0x808001B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x808001B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x808001B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808001B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001C0: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x808001C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2164, 0X408) << 16);
    // 0x808001C8: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x808001CC: bc1fl       L_808001F8
    if (!c1cs) {
        // 0x808001D0: lbu         $t9, 0x72($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X72);
            goto L_808001F8;
    }
    goto skip_1;
    // 0x808001D0: lbu         $t9, 0x72($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X72);
    skip_1:
    // 0x808001D4: lwc1        $f16, 0x28($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X28);
    // 0x808001D8: lwc1        $f18, 0x408($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2164, 0X408));
    // 0x808001DC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808001E0: b           L_808001F4
    // 0x808001E4: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
        goto L_808001F4;
    // 0x808001E4: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x808001E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_808001EC:
    // 0x808001EC: nop

    // 0x808001F0: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
L_808001F4:
    // 0x808001F4: lbu         $t9, 0x72($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X72);
L_808001F8:
    // 0x808001F8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x808001FC: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x80800200: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800204: sb          $t1, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r9;
    // 0x80800208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080020C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void func_8080124C_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080124C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801254: jal         0x808001A8
    // 0x80801258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsvan_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080125C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801260: jal         0x800845D8
    // 0x80801264: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801264: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80801268: lui         $a2, 0x3F03
    ctx->r6 = S32(0X3F03 << 16);
    // 0x8080126C: ori         $a2, $a2, 0x46DC
    ctx->r6 = ctx->r6 | 0X46DC;
    // 0x80801270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801274: jal         0x800845E0
    // 0x80801278: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80801278: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    after_2:
    // 0x8080127C: jal         0x8008CABC
    // 0x80801280: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_3;
    // 0x80801280: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80801284: lui         $a1, 0x3DD2
    ctx->r5 = S32(0X3DD2 << 16);
    // 0x80801288: ori         $a1, $a1, 0x1FF3
    ctx->r5 = ctx->r5 | 0X1FF3;
    // 0x8080128C: jal         0x8008B10C
    // 0x80801290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B10C(rdram, ctx);
        goto after_4;
    // 0x80801290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80801294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080129C: jr          $ra
    // 0x808012A0: nop

    return;
    // 0x808012A0: nop

;}
RECOMP_FUNC void _chmumbopad_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C68: syscall     437
    recomp_syscall_handler(rdram, ctx, 0x80086C68);
    return;
    // 0x80086C6C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
