#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808035C4_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808035C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808035C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808035CC: jal         0x80106790
    // 0x808035D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808035D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808035D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808035D8: jal         0x80100094
    // 0x808035DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808035DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808035E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808035E4: jal         0x800EE7F8
    // 0x808035E8: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808035E8: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    after_2:
    // 0x808035EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808035F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808035F4: jr          $ra
    // 0x808035F8: nop

    return;
    // 0x808035F8: nop

;}
RECOMP_FUNC void func_808009BC_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009BC: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x808009C0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x808009C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1024, 0XE2C) << 16);
    // 0x808009C8: lwc1        $f4, 0xE2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1024, 0XE2C));
    // 0x808009CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808009D0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x808009D4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x808009D8: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x808009DC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808009E0: addiu       $t6, $t6, -0x14C0
    ctx->r14 = ADD32(ctx->r14, -0X14C0);
    // 0x808009E4: addiu       $a3, $s2, 0x4
    ctx->r7 = ADD32(ctx->r18, 0X4);
    // 0x808009E8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808009EC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808009F0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808009F4: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x808009F8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808009FC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800A00: addiu       $a0, $zero, 0x35D
    ctx->r4 = ADD32(0, 0X35D);
    // 0x80800A04: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80800A08: jal         0x80089C48
    // 0x80800A0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddiefind_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800A0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800A10: blez        $v0, L_80800A84
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800A14: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80800A84;
    }
    // 0x80800A14: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800A18: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800A1C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800A20: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80800A24: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_80800A28:
    // 0x80800A28: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80800A2C: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80800A30: jal         0x800F2100
    // 0x80800A34: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x80800A34: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_1:
    // 0x80800A38: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800A3C: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80800A40: addiu       $t4, $sp, 0x70
    ctx->r12 = ADD32(ctx->r29, 0X70);
    // 0x80800A44: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x80800A48: bc1f        L_80800A74
    if (!c1cs) {
        // 0x80800A4C: addu        $a0, $t3, $t4
        ctx->r4 = ADD32(ctx->r11, ctx->r12);
            goto L_80800A74;
    }
    // 0x80800A4C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80800A50: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80800A54: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x80800A58: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80800A5C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80800A60: addiu       $t2, $sp, 0x70
    ctx->r10 = ADD32(ctx->r29, 0X70);
    // 0x80800A64: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x80800A68: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800A6C: b           L_80800A78
    // 0x80800A70: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
        goto L_80800A78;
    // 0x80800A70: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
L_80800A74:
    // 0x80800A74: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80800A78:
    // 0x80800A78: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x80800A7C: bnel        $at, $zero, L_80800A28
    if (ctx->r1 != 0) {
        // 0x80800A80: lw          $t7, 0x0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X0);
            goto L_80800A28;
    }
    goto skip_0;
    // 0x80800A80: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    skip_0:
L_80800A84:
    // 0x80800A84: beq         $s1, $zero, L_80800BAC
    if (ctx->r17 == 0) {
        // 0x80800A88: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800BAC;
    }
    // 0x80800A88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800A8C: jal         0x800DC128
    // 0x80800A90: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80800A90: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800A94: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80800A98: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x80800A9C: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x80800AA0: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80800AA4: jal         0x800EE7F8
    // 0x80800AA8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800AA8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x80800AAC: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x80800AB0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800AB4: jal         0x800EE7F8
    // 0x80800AB8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800AB8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x80800ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AC0: jal         0x800EE7F8
    // 0x80800AC4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800AC4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_5:
    // 0x80800AC8: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800ACC: lwc1        $f0, 0x48($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X48);
    // 0x80800AD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800AD4: swc1        $f10, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f10.u32l;
    // 0x80800AD8: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800ADC: lhu         $v0, 0x76($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X76);
    // 0x80800AE0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE8: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x80800AEC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80800AF0: bgez        $t7, L_80800B04
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800AF4: cvt.s.w     $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80800B04;
    }
    // 0x80800AF4: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800AF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800AFC: nop

    // 0x80800B00: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_80800B04:
    // 0x80800B04: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80800B08: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800B0C: lhu         $t8, 0x76($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X76);
    // 0x80800B10: andi        $t2, $v0, 0x7F
    ctx->r10 = ctx->r2 & 0X7F;
    // 0x80800B14: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80800B18: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80800B1C: sll         $t1, $t9, 7
    ctx->r9 = S32(ctx->r25 << 7);
    // 0x80800B20: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80800B24: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80800B28: sh          $t3, 0x76($s2)
    MEM_H(0X76, ctx->r18) = ctx->r11;
    // 0x80800B2C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800B30: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80800B34: beql        $t5, $zero, L_80800B84
    if (ctx->r13 == 0) {
        // 0x80800B38: mfc1        $t5, $f4
        ctx->r13 = (int32_t)ctx->f4.u32l;
            goto L_80800B84;
    }
    goto skip_1;
    // 0x80800B38: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x80800B3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B40: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800B44: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800B48: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800B4C: nop

    // 0x80800B50: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800B54: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80800B58: nop

    // 0x80800B5C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80800B60: bne         $t5, $zero, L_80800B78
    if (ctx->r13 != 0) {
        // 0x80800B64: nop
    
            goto L_80800B78;
    }
    // 0x80800B64: nop

    // 0x80800B68: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80800B6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800B70: b           L_80800B90
    // 0x80800B74: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80800B90;
    // 0x80800B74: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80800B78:
    // 0x80800B78: b           L_80800B90
    // 0x80800B7C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80800B90;
    // 0x80800B7C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80800B80: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
L_80800B84:
    // 0x80800B84: nop

    // 0x80800B88: bltz        $t5, L_80800B78
    if (SIGNED(ctx->r13) < 0) {
        // 0x80800B8C: nop
    
            goto L_80800B78;
    }
    // 0x80800B8C: nop

L_80800B90:
    // 0x80800B90: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x80800B94: sll         $t8, $t5, 7
    ctx->r24 = S32(ctx->r13 << 7);
    // 0x80800B98: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80800B9C: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x80800BA0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800BA4: jal         0x80103014
    // 0x80800BA8: sh          $t1, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r9;
    func_80103014(rdram, ctx);
        goto after_6;
    // 0x80800BA8: sh          $t1, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r9;
    after_6:
L_80800BAC:
    // 0x80800BAC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800BB0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800BB4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800BB8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800BBC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BC0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800BC4: jr          $ra
    // 0x80800BC8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80800BC8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800B422C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B422C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B4230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4234: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B4238: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800B423C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800B4240: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800B4244: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x800B4248: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800B424C: beq         $t8, $zero, L_800B4280
    if (ctx->r24 == 0) {
        // 0x800B4250: sw          $t8, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r24;
            goto L_800B4280;
    }
    // 0x800B4250: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800B4254: lh          $a2, 0x2($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X2);
    // 0x800B4258: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800B425C: jal         0x800B3B08
    // 0x800B4260: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_800B3B08(rdram, ctx);
        goto after_0;
    // 0x800B4260: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_0:
    // 0x800B4264: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B4268: jal         0x800B3EDC
    // 0x800B426C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800B3EDC(rdram, ctx);
        goto after_1;
    // 0x800B426C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x800B4270: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800B4274: sh          $zero, 0x2($a3)
    MEM_H(0X2, ctx->r7) = 0;
    // 0x800B4278: lh          $t0, 0x2($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X2);
    // 0x800B427C: sh          $t0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r8;
L_800B4280:
    // 0x800B4280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B4288: jr          $ra
    // 0x800B428C: nop

    return;
    // 0x800B428C: nop

;}
RECOMP_FUNC void chclimbbase_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800398: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(680, 0X418) << 16);
    // 0x8080039C: jr          $ra
    // 0x808003A0: addiu       $v0, $v0, 0x418
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(680, 0X418));
    return;
    // 0x808003A0: addiu       $v0, $v0, 0x418
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(680, 0X418));
    // 0x808003A4: nop

    // 0x808003A8: nop

    // 0x808003AC: nop

;}
RECOMP_FUNC void bscrashout_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080028C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800290: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800294: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800298: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080029C: jal         0x800D8FF8
    // 0x808002A0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808002A0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808002A4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808002A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002AC: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    // 0x808002B0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808002B4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808002B8: jal         0x800F1574
    // 0x808002BC: nop

    func_800F1574(rdram, ctx);
        goto after_1;
    // 0x808002BC: nop

    after_1:
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: jal         0x8009B9B0
    // 0x808002C8: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808002C8: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_2:
    // 0x808002CC: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808002D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002D4: beq         $v0, $at, L_808002F4
    if (ctx->r2 == ctx->r1) {
        // 0x808002D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808002F4;
    }
    // 0x808002D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002DC: beq         $v0, $at, L_8080034C
    if (ctx->r2 == ctx->r1) {
        // 0x808002E0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080034C;
    }
    // 0x808002E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808002E4: beq         $v0, $at, L_80800364
    if (ctx->r2 == ctx->r1) {
        // 0x808002E8: nop
    
            goto L_80800364;
    }
    // 0x808002E8: nop

    // 0x808002EC: b           L_8080038C
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080038C;
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002F4:
    // 0x808002F4: jal         0x80800000
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bscrashout(rdram, ctx);
        goto after_3;
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002FC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800300: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800304: jal         0x8008CB10
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080030C: beq         $v0, $zero, L_8080032C
    if (ctx->r2 == 0) {
        // 0x80800310: nop
    
            goto L_8080032C;
    }
    // 0x80800310: nop

    // 0x80800314: jal         0x800A1718
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_5;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080031C: bne         $v0, $zero, L_8080032C
    if (ctx->r2 != 0) {
        // 0x80800320: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080032C;
    }
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: jal         0x808000B0
    // 0x80800328: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808000B0_bscrashout(rdram, ctx);
        goto after_6;
    // 0x80800328: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
L_8080032C:
    // 0x8080032C: jal         0x8008CAEC
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_7;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800334: beq         $v0, $zero, L_80800388
    if (ctx->r2 == 0) {
        // 0x80800338: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800388;
    }
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: jal         0x808000B0
    // 0x80800340: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808000B0_bscrashout(rdram, ctx);
        goto after_8;
    // 0x80800340: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800344: b           L_8080038C
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080038C;
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080034C:
    // 0x8080034C: jal         0x8008CAEC
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_9;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800354: beq         $v0, $zero, L_80800388
    if (ctx->r2 == 0) {
        // 0x80800358: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800388;
    }
    // 0x80800358: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080035C: b           L_80800388
    // 0x80800360: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_80800388;
    // 0x80800360: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800364:
    // 0x80800364: jal         0x80800000
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bscrashout(rdram, ctx);
        goto after_10;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: jal         0x800852F0
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_11;
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800378: beql        $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x8080037C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080038C;
    }
    goto skip_0;
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800380: jal         0x80085200
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_80800388:
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080038C:
    // 0x8080038C: jal         0x8009E5C8
    // 0x80800390: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x80800390: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x80800394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080039C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void func_80801D58_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801D64: lw          $a3, 0x50($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X50);
    // 0x80801D68: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80801D6C: beq         $a3, $zero, L_80801D84
    if (ctx->r7 == 0) {
        // 0x80801D70: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80801D84;
    }
    // 0x80801D70: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801D74: jal         0x800863E8
    // 0x80801D78: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801D78: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80801D7C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80801D80: sw          $v0, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r2;
L_80801D84:
    // 0x80801D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D8C: jr          $ra
    // 0x80801D90: nop

    return;
    // 0x80801D90: nop

;}
RECOMP_FUNC void _basub_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851D8: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851D8);
    return;
    // 0x800851DC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void subaddieDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: jal         0x8080007C
    // 0x80800068: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    subaddieDll_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800068: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void ncbaclimb_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800710_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800718: lw          $t6, 0x164($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X164);
    // 0x8080071C: beq         $t6, $zero, L_8080072C
    if (ctx->r14 == 0) {
        // 0x80800720: nop
    
            goto L_8080072C;
    }
    // 0x80800720: nop

    // 0x80800724: b           L_8080074C
    // 0x80800728: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080074C;
    // 0x80800728: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080072C:
    // 0x8080072C: jal         0x8008E39C
    // 0x80800730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E39C(rdram, ctx);
        goto after_0;
    // 0x80800730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800734: beq         $v0, $zero, L_80800744
    if (ctx->r2 == 0) {
        // 0x80800738: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800744;
    }
    // 0x80800738: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080073C: b           L_8080074C
    // 0x80800740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080074C;
    // 0x80800740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800744:
    // 0x80800744: jal         0x80091A30
    // 0x80800748: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_1;
    // 0x80800748: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_8080074C:
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800754: jr          $ra
    // 0x80800758: nop

    return;
    // 0x80800758: nop

;}
RECOMP_FUNC void bscarry_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800780: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800784: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(132, 0X7F0) << 16);
    // 0x80800788: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080078C: jr          $ra
    // 0x80800790: lw          $v0, 0x7F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(132, 0X7F0));
    return;
    // 0x80800790: lw          $v0, 0x7F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(132, 0X7F0));
    // 0x80800794: nop

    // 0x80800798: nop

    // 0x8080079C: nop

;}
RECOMP_FUNC void _chattract_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BF8: syscall     208
    recomp_syscall_handler(rdram, ctx, 0x80085BF8);
    return;
    // 0x80085BFC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void idlight_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800238: jr          $ra
    // 0x8080023C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080023C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _chfactorylinkgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087548: syscall     587
    recomp_syscall_handler(rdram, ctx, 0x80087548);
    return;
    // 0x8008754C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808002C8_glrtc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808002CC: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x808002D0: lhu         $t9, 0x6($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6);
    // 0x808002D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808002D8: and         $v0, $t7, $a1
    ctx->r2 = ctx->r15 & ctx->r5;
    // 0x808002DC: and         $a2, $t9, $a1
    ctx->r6 = ctx->r25 & ctx->r5;
    // 0x808002E0: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x808002E4: andi        $t2, $a2, 0xFFFF
    ctx->r10 = ctx->r6 & 0XFFFF;
    // 0x808002E8: subu        $t3, $t2, $t8
    ctx->r11 = SUB32(ctx->r10, ctx->r24);
    // 0x808002EC: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x808002F0: mflo        $t4
    ctx->r12 = lo;
    // 0x808002F4: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x808002F8: lhu         $t9, 0x4($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X4);
    // 0x808002FC: and         $t5, $t4, $a1
    ctx->r13 = ctx->r12 & ctx->r5;
    // 0x80800300: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x80800304: subu        $t2, $t2, $t5
    ctx->r10 = SUB32(ctx->r10, ctx->r13);
    // 0x80800308: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8080030C: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80800310: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    // 0x80800314: jr          $ra
    // 0x80800318: sh          $t3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r11;
    return;
    // 0x80800318: sh          $t3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r11;
;}
RECOMP_FUNC void func_80028B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028B74: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80028B78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80028B7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80028B80: nop

    // 0x80028B84: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
    // 0x80028B88: bltz        $a0, L_80028BA0
    if (SIGNED(ctx->r4) < 0) {
        // 0x80028B8C: nop
    
            goto L_80028BA0;
    }
    // 0x80028B8C: nop

    // 0x80028B90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80028B94: lwc1        $f6, 0x1D18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1D18);
    // 0x80028B98: b           L_80028BB0
    // 0x80028B9C: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
        goto L_80028BB0;
    // 0x80028B9C: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
L_80028BA0:
    // 0x80028BA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80028BA4: lwc1        $f8, 0x1D1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1D1C);
    // 0x80028BA8: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x80028BAC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_80028BB0:
    // 0x80028BB0: beq         $a0, $zero, L_80028BEC
    if (ctx->r4 == 0) {
        // 0x80028BB4: nop
    
            goto L_80028BEC;
    }
    // 0x80028BB4: nop

L_80028BB8:
    // 0x80028BB8: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x80028BBC: beq         $t6, $zero, L_80028BD4
    if (ctx->r14 == 0) {
        // 0x80028BC0: nop
    
            goto L_80028BD4;
    }
    // 0x80028BC0: nop

    // 0x80028BC4: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80028BC8: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80028BCC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80028BD0: swc1        $f18, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f18.u32l;
L_80028BD4:
    // 0x80028BD4: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80028BD8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80028BDC: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x80028BE0: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80028BE4: bne         $a0, $zero, L_80028BB8
    if (ctx->r4 != 0) {
        // 0x80028BE8: nop
    
            goto L_80028BB8;
    }
    // 0x80028BE8: nop

L_80028BEC:
    // 0x80028BEC: b           L_80028BFC
    // 0x80028BF0: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
        goto L_80028BFC;
    // 0x80028BF0: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80028BF4: b           L_80028BFC
    // 0x80028BF8: nop

        goto L_80028BFC;
    // 0x80028BF8: nop

L_80028BFC:
    // 0x80028BFC: jr          $ra
    // 0x80028C00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80028C00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void _baduo_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849A8: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x800849A8);
    return;
    // 0x800849AC: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_80800AEC_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800AF8: jal         0x80100094
    // 0x80800AFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800AFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B00: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800B04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B08: jal         0x800EE7F8
    // 0x80800B0C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800B0C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80800B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B18: jr          $ra
    // 0x80800B1C: nop

    return;
    // 0x80800B1C: nop

;}
RECOMP_FUNC void func_808000F8_chtempleinternaldoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800100: jal         0x80086240
    // 0x80800104: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800104: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080010C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800110: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800114: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800118: bnel        $t7, $at, L_8080012C
    if (ctx->r15 != ctx->r1) {
        // 0x8080011C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080012C;
    }
    goto skip_0;
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800120: jal         0x800868B8
    // 0x80800124: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    _chdoormake_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800124: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_1:
    // 0x80800128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080012C:
    // 0x8080012C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800130: jr          $ra
    // 0x80800134: nop

    return;
    // 0x80800134: nop

;}
RECOMP_FUNC void _gcstatusDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088318: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088318);
    return;
    // 0x8008831C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chjollyroger_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F58: syscall     264
    recomp_syscall_handler(rdram, ctx, 0x80085F58);
    return;
    // 0x80085F5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800028_chdinoroargrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080002C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800030: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800034: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80800038: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2064, 0X250) << 16);
    // 0x8080003C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800040: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800044: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800048: nop

    // 0x8080004C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800050: lbu         $t8, 0x250($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(2064, 0X250));
    // 0x80800054: bne         $t8, $zero, L_808000E8
    if (ctx->r24 != 0) {
        // 0x80800058: nop
    
            goto L_808000E8;
    }
    // 0x80800058: nop

    // 0x8080005C: jal         0x80102F44
    // 0x80800060: nop

    func_80102F44(rdram, ctx);
        goto after_0;
    // 0x80800060: nop

    after_0:
    // 0x80800064: bne         $v0, $zero, L_808000D8
    if (ctx->r2 != 0) {
        // 0x80800068: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D8;
    }
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: jal         0x80101FDC
    // 0x80800070: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800070: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800074: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2064, 0X240) << 16);
    // 0x80800078: lwc1        $f8, 0x240($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2064, 0X240));
    // 0x8080007C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800080: addiu       $a2, $zero, 0x4C
    ctx->r6 = ADD32(0, 0X4C);
    // 0x80800084: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    // 0x80800088: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x8080008C: jal         0x80085708
    // 0x80800090: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800090: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_2:
    // 0x80800094: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x80800098: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080009C: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000A0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808000A4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808000A8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808000AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808000B8: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x808000BC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808000C0: jal         0x80086898
    // 0x808000C4: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808000C4: nop

    after_3:
    // 0x808000C8: beq         $v0, $zero, L_808000D8
    if (ctx->r2 == 0) {
        // 0x808000CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D8;
    }
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x800868C0
    // 0x808000D4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x808000D4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_4:
L_808000D8:
    // 0x808000D8: jal         0x80086240
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000E0: b           L_80800114
    // 0x808000E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800114;
    // 0x808000E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000E8:
    // 0x808000E8: jal         0x8010C710
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C710(rdram, ctx);
        goto after_6;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000F0: lui         $at, 0xC
    ctx->r1 = S32(0XC << 16);
    // 0x808000F4: ori         $at, $at, 0x5C11
    ctx->r1 = ctx->r1 | 0X5C11;
    // 0x808000F8: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x808000FC: bnel        $at, $zero, L_80800114
    if (ctx->r1 != 0) {
        // 0x80800100: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800114;
    }
    goto skip_0;
    // 0x80800100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800104: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800108: nop

    // 0x8080010C: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80800110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800114:
    // 0x80800114: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void func_80802BE0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802BE0: jr          $ra
    // 0x80802BE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80802BE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _chflysaucerdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D20: syscall     448
    recomp_syscall_handler(rdram, ctx, 0x80086D20);
    return;
    // 0x80086D24: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bstalk_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DC0: syscall     95
    recomp_syscall_handler(rdram, ctx, 0x80083DC0);
    return;
    // 0x80083DC4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800F8804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8804: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F880C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8814: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F8818: jal         0x8009CD70
    // 0x800F881C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009CD70(rdram, ctx);
        goto after_0;
    // 0x800F881C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F8820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8828: jr          $ra
    // 0x800F882C: nop

    return;
    // 0x800F882C: nop

;}
RECOMP_FUNC void func_800C2E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2E04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C2E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2E0C: jal         0x800C145C
    // 0x800C2E10: nop

    func_800C145C(rdram, ctx);
        goto after_0;
    // 0x800C2E10: nop

    after_0:
    // 0x800C2E14: bne         $v0, $zero, L_800C2E24
    if (ctx->r2 != 0) {
        // 0x800C2E18: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_800C2E24;
    }
    // 0x800C2E18: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x800C2E1C: b           L_800C2E30
    // 0x800C2E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C2E30;
    // 0x800C2E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C2E24:
    // 0x800C2E24: jal         0x800C2C4C
    // 0x800C2E28: sb          $a0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r4;
    func_800C2C4C(rdram, ctx);
        goto after_1;
    // 0x800C2E28: sb          $a0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r4;
    after_1:
    // 0x800C2E2C: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
L_800C2E30:
    // 0x800C2E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2E34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C2E38: jr          $ra
    // 0x800C2E3C: nop

    return;
    // 0x800C2E3C: nop

;}
RECOMP_FUNC void func_80801E90_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801E98: jal         0x80100094
    // 0x80801E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801EA0: lbu         $t6, 0x1CD($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1CD);
    // 0x80801EA4: beql        $t6, $zero, L_80801EC0
    if (ctx->r14 == 0) {
        // 0x80801EA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801EC0;
    }
    goto skip_0;
    // 0x80801EA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801EAC: jal         0x80085710
    // 0x80801EB0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80801EB0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801EB4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801EB8: sb          $zero, 0x1CD($v1)
    MEM_B(0X1CD, ctx->r3) = 0;
    // 0x80801EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801EC0:
    // 0x80801EC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801EC4: jr          $ra
    // 0x80801EC8: nop

    return;
    // 0x80801EC8: nop

;}
RECOMP_FUNC void chlavahand_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801218: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2332, 0X1418) << 16);
    // 0x8080121C: jr          $ra
    // 0x80801220: addiu       $v0, $v0, 0x1418
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2332, 0X1418));
    return;
    // 0x80801220: addiu       $v0, $v0, 0x1418
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2332, 0X1418));
    // 0x80801224: nop

    // 0x80801228: nop

    // 0x8080122C: nop

;}
RECOMP_FUNC void func_800CB8F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB8F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB8F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB8F8: jal         0x800CB890
    // 0x800CB8FC: nop

    func_800CB890(rdram, ctx);
        goto after_0;
    // 0x800CB8FC: nop

    after_0:
    // 0x800CB900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB908: jr          $ra
    // 0x800CB90C: nop

    return;
    // 0x800CB90C: nop

;}
RECOMP_FUNC void chvolcanobits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1264, 0X122C) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x122C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1264, 0X122C));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x122C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1264, 0X122C));
;}
RECOMP_FUNC void _chfirefx_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086160: syscall     281
    recomp_syscall_handler(rdram, ctx, 0x80086160);
    return;
    // 0x80086164: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800B3494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3494: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800B3498: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800B349C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800B34A0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800B34A4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800B34A8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800B34AC: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800B34B0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800B34B4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800B34B8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800B34BC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800B34C0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800B34C4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800B34C8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800B34CC: addiu       $t6, $a0, 0x18
    ctx->r14 = ADD32(ctx->r4, 0X18);
    // 0x800B34D0: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x800B34D4: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800B34D8: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x800B34DC: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x800B34E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B34E4: jal         0x800C8760
    // 0x800B34E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8760(rdram, ctx);
        goto after_0;
    // 0x800B34E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800B34EC: beq         $v0, $zero, L_800B367C
    if (ctx->r2 == 0) {
        // 0x800B34F0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800B367C;
    }
    // 0x800B34F0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800B34F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B34F8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800B34FC: addiu       $s6, $sp, 0x68
    ctx->r22 = ADD32(ctx->r29, 0X68);
    // 0x800B3500: addiu       $s5, $sp, 0x8C
    ctx->r21 = ADD32(ctx->r29, 0X8C);
    // 0x800B3504: addiu       $s4, $sp, 0x80
    ctx->r20 = ADD32(ctx->r29, 0X80);
    // 0x800B3508: addiu       $s1, $sp, 0x74
    ctx->r17 = ADD32(ctx->r29, 0X74);
    // 0x800B350C: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
L_800B3510:
    // 0x800B3510: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B3514: jal         0x800C8800
    // 0x800B3518: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800C8800(rdram, ctx);
        goto after_1;
    // 0x800B3518: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x800B351C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B3520: jal         0x800C8898
    // 0x800B3524: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_800C8898(rdram, ctx);
        goto after_2;
    // 0x800B3524: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_2:
    // 0x800B3528: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B352C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800B3530: jal         0x800EFB24
    // 0x800B3534: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x800B3534: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_3:
    // 0x800B3538: jal         0x800EEF94
    // 0x800B353C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EEF94(rdram, ctx);
        goto after_4;
    // 0x800B353C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x800B3540: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B3544: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800B3548: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x800B354C: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x800B3550: nop

    // 0x800B3554: bc1tl       L_800B3668
    if (c1cs) {
        // 0x800B3558: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800B3668;
    }
    goto skip_0;
    // 0x800B3558: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x800B355C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B3560: jal         0x800B3390
    // 0x800B3564: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800B3390(rdram, ctx);
        goto after_5;
    // 0x800B3564: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_5:
    // 0x800B3568: beq         $v0, $zero, L_800B3664
    if (ctx->r2 == 0) {
        // 0x800B356C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800B3664;
    }
    // 0x800B356C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800B3570: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x800B3574: div.s       $f0, $f24, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800B3578: addiu       $v1, $sp, 0x8C
    ctx->r3 = ADD32(ctx->r29, 0X8C);
    // 0x800B357C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B3580: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B3584: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B3588: sltu        $at, $v1, $s0
    ctx->r1 = ctx->r3 < ctx->r16 ? 1 : 0;
    // 0x800B358C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B3590: beql        $at, $zero, L_800B35B8
    if (ctx->r1 == 0) {
        // 0x800B3594: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800B35B8;
    }
    goto skip_1;
    // 0x800B3594: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    skip_1:
L_800B3598:
    // 0x800B3598: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800B359C: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B35A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B35A4: sltu        $at, $v1, $s0
    ctx->r1 = ctx->r3 < ctx->r16 ? 1 : 0;
    // 0x800B35A8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B35AC: bne         $at, $zero, L_800B3598
    if (ctx->r1 != 0) {
        // 0x800B35B0: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800B3598;
    }
    // 0x800B35B0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B35B4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800B35B8:
    // 0x800B35B8: swc1        $f18, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800B35BC: sub.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x800B35C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B35C4: jal         0x800C8900
    // 0x800B35C8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800C8900(rdram, ctx);
        goto after_6;
    // 0x800B35C8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_6:
    // 0x800B35CC: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B35D0: addiu       $a0, $s2, 0xC
    ctx->r4 = ADD32(ctx->r18, 0XC);
    // 0x800B35D4: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x800B35D8: nop

    // 0x800B35DC: bc1fl       L_800B35F8
    if (!c1cs) {
        // 0x800B35E0: sub.s       $f18, $f20, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f2.fl;
            goto L_800B35F8;
    }
    goto skip_2;
    // 0x800B35E0: sub.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f2.fl;
    skip_2:
    // 0x800B35E4: jal         0x800EE830
    // 0x800B35E8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EE830(rdram, ctx);
        goto after_7;
    // 0x800B35E8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_7:
    // 0x800B35EC: b           L_800B3668
    // 0x800B35F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_800B3668;
    // 0x800B35F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B35F4: sub.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f2.fl;
L_800B35F8:
    // 0x800B35F8: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B35FC: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800B3600: addiu       $v0, $sp, 0x68
    ctx->r2 = ADD32(ctx->r29, 0X68);
    // 0x800B3604: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B3608: sub.s       $f0, $f24, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x800B360C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B3610: beq         $v0, $s1, L_800B3644
    if (ctx->r2 == ctx->r17) {
        // 0x800B3614: lw          $t7, -0x4($v0)
        ctx->r15 = MEM_W(ctx->r2, -0X4);
            goto L_800B3644;
    }
    // 0x800B3614: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
L_800B3618:
    // 0x800B3618: mtc1        $t7, $f20
    ctx->f20.u32l = ctx->r15;
    // 0x800B361C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B3620: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B3624: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800B3628: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B362C: trunc.w.s   $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x800B3630: mfc1        $t9, $f20
    ctx->r25 = (int32_t)ctx->f20.u32l;
    // 0x800B3634: nop

    // 0x800B3638: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x800B363C: bne         $v0, $s1, L_800B3618
    if (ctx->r2 != ctx->r17) {
        // 0x800B3640: lw          $t7, -0x4($v0)
        ctx->r15 = MEM_W(ctx->r2, -0X4);
            goto L_800B3618;
    }
    // 0x800B3640: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
L_800B3644:
    // 0x800B3644: mtc1        $t7, $f20
    ctx->f20.u32l = ctx->r15;
    // 0x800B3648: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B364C: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800B3650: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B3654: trunc.w.s   $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x800B3658: mfc1        $t9, $f20
    ctx->r25 = (int32_t)ctx->f20.u32l;
    // 0x800B365C: nop

    // 0x800B3660: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
L_800B3664:
    // 0x800B3664: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800B3668:
    // 0x800B3668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B366C: jal         0x800C878C
    // 0x800B3670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800C878C(rdram, ctx);
        goto after_8;
    // 0x800B3670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x800B3674: bne         $v0, $zero, L_800B3510
    if (ctx->r2 != 0) {
        // 0x800B3678: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800B3510;
    }
    // 0x800B3678: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_800B367C:
    // 0x800B367C: jal         0x800B3784
    // 0x800B3680: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800B3784(rdram, ctx);
        goto after_9;
    // 0x800B3680: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_9:
    // 0x800B3684: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800B3688: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800B368C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800B3690: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800B3694: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800B3698: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800B369C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800B36A0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800B36A4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800B36A8: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800B36AC: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800B36B0: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800B36B4: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800B36B8: jr          $ra
    // 0x800B36BC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800B36BC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_80800718_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800718: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080071C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800720: jal         0x80106790
    // 0x80800724: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800724: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80800728: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080072C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800730: jal         0x80101FDC
    // 0x80800734: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800734: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800738: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080073C: jal         0x80103110
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800744: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800748: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080074C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800754: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80800758: jal         0x80100074
    // 0x8080075C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    func_80100074(rdram, ctx);
        goto after_3;
    // 0x8080075C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    after_3:
    // 0x80800760: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800764: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800768: jal         0x80088FA0
    // 0x8080076C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    _mlwave_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8080076C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_4:
    // 0x80800770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800774: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800778: jr          $ra
    // 0x8080077C: nop

    return;
    // 0x8080077C: nop

;}
RECOMP_FUNC void func_80804A64_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804A64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80804A68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804A6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804A70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80804A74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804A78: jal         0x8009E6EC
    // 0x80804A7C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80804A7C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80804A80: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x80804A84: bne         $v0, $at, L_80804AE0
    if (ctx->r2 != ctx->r1) {
        // 0x80804A88: nop
    
            goto L_80804AE0;
    }
    // 0x80804A88: nop

    // 0x80804A8C: jal         0x800A3404
    // 0x80804A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_1;
    // 0x80804A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80804A94: bnel        $v0, $zero, L_80804AF4
    if (ctx->r2 != 0) {
        // 0x80804A98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804AF4;
    }
    goto skip_0;
    // 0x80804A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80804A9C: jal         0x80807EEC
    // 0x80804AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807EEC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80804AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80804AA4: jal         0x8009E6F8
    // 0x80804AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_3;
    // 0x80804AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80804AAC: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80804AB0: bne         $v0, $at, L_80804ACC
    if (ctx->r2 != ctx->r1) {
        // 0x80804AB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804ACC;
    }
    // 0x80804AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804ABC: jal         0x80800888
    // 0x80804AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800888_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80804AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80804AC4: b           L_80804AD8
    // 0x80804AC8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
        goto L_80804AD8;
    // 0x80804AC8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80804ACC:
    // 0x80804ACC: jal         0x80800888
    // 0x80804AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800888_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80804AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80804AD4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80804AD8:
    // 0x80804AD8: b           L_80804AF0
    // 0x80804ADC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80804AF0;
    // 0x80804ADC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80804AE0:
    // 0x80804AE0: jal         0x80805994
    // 0x80804AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsfirstp_entrypoint_26(rdram, ctx);
        goto after_6;
    // 0x80804AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80804AE8: b           L_80804B00
    // 0x80804AEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804B00;
    // 0x80804AEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804AF0:
    // 0x80804AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804AF4:
    // 0x80804AF4: jal         0x8009E830
    // 0x80804AF8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009E830(rdram, ctx);
        goto after_7;
    // 0x80804AF8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80804AFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804B00:
    // 0x80804B00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804B04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80804B08: jr          $ra
    // 0x80804B0C: nop

    return;
    // 0x80804B0C: nop

;}
RECOMP_FUNC void _chpotogoldbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875F0: syscall     594
    recomp_syscall_handler(rdram, ctx, 0x800875F0);
    return;
    // 0x800875F4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800000_bskazspring(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009EF1C
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800014: jal         0x8009EF10
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080001C: beq         $v0, $zero, L_8080004C
    if (ctx->r2 == 0) {
        // 0x80800020: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080004C;
    }
    // 0x80800020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800024: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800028: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080002C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800030: jal         0x800F1214
    // 0x80800034: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800F1214(rdram, ctx);
        goto after_2;
    // 0x80800034: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_2:
    // 0x80800038: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080003C: jal         0x8009B9B0
    // 0x80800040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800044: b           L_80800058
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800058;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080004C:
    // 0x8080004C: jal         0x8009B9B0
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_80800150_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800158: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8080015C: jal         0x80100094
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800164: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800168: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8080016C: jal         0x80100094
    // 0x80800170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800174: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80800178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080017C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800180: jal         0x800897D8
    // 0x80800184: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800184: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x80800188: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8080018C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800190: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800194: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80800198: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080019C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001A0: jal         0x80089F18
    // 0x808001A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808001A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x808001A8: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x808001AC: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x808001B0: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808001B4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x808001B8: sltiu       $at, $t0, 0xB
    ctx->r1 = ctx->r8 < 0XB ? 1 : 0;
    // 0x808001BC: beq         $at, $zero, L_80800620
    if (ctx->r1 == 0) {
        // 0x808001C0: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800620;
    }
    // 0x808001C0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808001C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1860, 0X10E0) << 16);
    // 0x808001C8: addu        $at, $at, $t0
    gpr jr_addend_808001D0 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808001CC: lw          $t0, 0x10E0($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1860, 0X10E0));
    // 0x808001D0: jr          $t0
    // 0x808001D4: nop

    switch (jr_addend_808001D0 >> 2) {
        case 0: goto L_808001D8; break;
        case 1: goto L_80800234; break;
        case 2: goto L_8080027C; break;
        case 3: goto L_80800304; break;
        case 4: goto L_8080036C; break;
        case 5: goto L_8080042C; break;
        case 6: goto L_80800444; break;
        case 7: goto L_80800620; break;
        case 8: goto L_80800454; break;
        case 9: goto L_80800464; break;
        case 10: goto L_80800570; break;
        default: switch_error(__func__, 0x808001D0, 0x808010E0);
    }
    // 0x808001D4: nop

L_808001D8:
    // 0x808001D8: jal         0x80800E64
    // 0x808001DC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800E64_chamazongoldhordeofficial(rdram, ctx);
        goto after_4;
    // 0x808001DC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_4:
    // 0x808001E0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x808001E4: addiu       $at, $zero, -0x3E7
    ctx->r1 = ADD32(0, -0X3E7);
    // 0x808001E8: lh          $a1, 0x8($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X8);
    // 0x808001EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808001F0: bnel        $a1, $at, L_8080020C
    if (ctx->r5 != ctx->r1) {
        // 0x808001F4: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_8080020C;
    }
    goto skip_0;
    // 0x808001F4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x808001F8: jal         0x8008A4F0
    // 0x808001FC: addiu       $a1, $a3, 0x8
    ctx->r5 = ADD32(ctx->r7, 0X8);
    _subaddieDll_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x808001FC: addiu       $a1, $a3, 0x8
    ctx->r5 = ADD32(ctx->r7, 0X8);
    after_5:
    // 0x80800200: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80800204: lh          $a1, 0x8($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X8);
    // 0x80800208: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_8080020C:
    // 0x8080020C: jal         0x80800F40
    // 0x80800210: lh          $a2, 0xA($a3)
    ctx->r6 = MEM_H(ctx->r7, 0XA);
    func_80800F40_chamazongoldhordeofficial(rdram, ctx);
        goto after_6;
    // 0x80800210: lh          $a2, 0xA($a3)
    ctx->r6 = MEM_H(ctx->r7, 0XA);
    after_6:
    // 0x80800214: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x80800218: nop
    
            goto L_80800224;
    }
    // 0x80800218: nop

    // 0x8080021C: jal         0x80800E18
    // 0x80800220: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800E18_chamazongoldhordeofficial(rdram, ctx);
        goto after_7;
    // 0x80800220: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_7:
L_80800224:
    // 0x80800224: jal         0x80800C60
    // 0x80800228: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800C60_chamazongoldhordeofficial(rdram, ctx);
        goto after_8;
    // 0x80800228: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_8:
    // 0x8080022C: b           L_80800624
    // 0x80800230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800624;
    // 0x80800230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800234:
    // 0x80800234: jal         0x80800E64
    // 0x80800238: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800E64_chamazongoldhordeofficial(rdram, ctx);
        goto after_9;
    // 0x80800238: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_9:
    // 0x8080023C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80800240: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800244: lbu         $t3, 0x67($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X67);
    // 0x80800248: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8080024C: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x80800250: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    // 0x80800254: jal         0x80800F40
    // 0x80800258: lh          $a2, 0x2A($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2A);
    func_80800F40_chamazongoldhordeofficial(rdram, ctx);
        goto after_10;
    // 0x80800258: lh          $a2, 0x2A($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2A);
    after_10:
    // 0x8080025C: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x80800260: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_8080026C;
    }
    // 0x80800260: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800264: jal         0x80102424
    // 0x80800268: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800268: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
L_8080026C:
    // 0x8080026C: jal         0x80800C60
    // 0x80800270: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800C60_chamazongoldhordeofficial(rdram, ctx);
        goto after_12;
    // 0x80800270: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_12:
    // 0x80800274: b           L_80800624
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800624;
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080027C:
    // 0x8080027C: jal         0x80800E64
    // 0x80800280: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800E64_chamazongoldhordeofficial(rdram, ctx);
        goto after_13;
    // 0x80800280: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_13:
    // 0x80800284: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80800288: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8080028C: lbu         $t5, 0x67($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X67);
    // 0x80800290: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80800294: lbu         $t7, 0x58($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X58);
    // 0x80800298: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8080029C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808002A0: nop

    // 0x808002A4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002A8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808002AC: jal         0x80102924
    // 0x808002B0: nop

    func_80102924(rdram, ctx);
        goto after_14;
    // 0x808002B0: nop

    after_14:
    // 0x808002B4: jal         0x800D8FF8
    // 0x808002B8: nop

    func_800D8FF8(rdram, ctx);
        goto after_15;
    // 0x808002B8: nop

    after_15:
    // 0x808002BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808002C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002C4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808002C8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808002CC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808002D0: jal         0x80102B2C
    // 0x808002D4: nop

    func_80102B2C(rdram, ctx);
        goto after_16;
    // 0x808002D4: nop

    after_16:
    // 0x808002D8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808002DC: jal         0x80102CF4
    // 0x808002E0: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_80102CF4(rdram, ctx);
        goto after_17;
    // 0x808002E0: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_17:
    // 0x808002E4: beq         $v0, $zero, L_808002F4
    if (ctx->r2 == 0) {
        // 0x808002E8: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_808002F4;
    }
    // 0x808002E8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808002EC: jal         0x80102424
    // 0x808002F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x808002F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_18:
L_808002F4:
    // 0x808002F4: jal         0x80800C60
    // 0x808002F8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800C60_chamazongoldhordeofficial(rdram, ctx);
        goto after_19;
    // 0x808002F8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_19:
    // 0x808002FC: b           L_80800624
    // 0x80800300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800624;
    // 0x80800300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800304:
    // 0x80800304: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800308: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1860, 0X1288) << 16);
    // 0x8080030C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1860, 0X12A0) << 16);
    // 0x80800310: addiu       $a3, $a3, 0x12A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1860, 0X12A0));
    // 0x80800314: addiu       $a2, $a2, 0x1288
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1860, 0X1288));
    // 0x80800318: jal         0x80089D28
    // 0x8080031C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x8080031C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_20:
    // 0x80800320: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800324: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1860, 0X1294) << 16);
    // 0x80800328: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1860, 0X12BC) << 16);
    // 0x8080032C: addiu       $a3, $a3, 0x12BC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1860, 0X12BC));
    // 0x80800330: addiu       $a2, $a2, 0x1294
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1860, 0X1294));
    // 0x80800334: jal         0x80089D28
    // 0x80800338: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80800338: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_21:
    // 0x8080033C: jal         0x80800A84
    // 0x80800340: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800A84_chamazongoldhordeofficial(rdram, ctx);
        goto after_22;
    // 0x80800340: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_22:
    // 0x80800344: jal         0x80101DDC
    // 0x80800348: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80101DDC(rdram, ctx);
        goto after_23;
    // 0x80800348: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_23:
    // 0x8080034C: beq         $v0, $zero, L_8080035C
    if (ctx->r2 == 0) {
        // 0x80800350: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_8080035C;
    }
    // 0x80800350: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800354: jal         0x80102424
    // 0x80800358: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_24;
    // 0x80800358: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_24:
L_8080035C:
    // 0x8080035C: jal         0x80800C60
    // 0x80800360: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800C60_chamazongoldhordeofficial(rdram, ctx);
        goto after_25;
    // 0x80800360: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_25:
    // 0x80800364: b           L_80800624
    // 0x80800368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800624;
    // 0x80800368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080036C:
    // 0x8080036C: jal         0x80800E64
    // 0x80800370: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800E64_chamazongoldhordeofficial(rdram, ctx);
        goto after_26;
    // 0x80800370: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_26:
    // 0x80800374: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80800378: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8080037C: lbu         $t9, 0x67($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X67);
    // 0x80800380: lh          $t2, 0x6A($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6A);
    // 0x80800384: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80800388: lbu         $t1, 0x58($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X58);
    // 0x8080038C: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x80800390: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x80800394: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80800398: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x8080039C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x808003A0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x808003A4: nop

    // 0x808003A8: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808003AC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808003B0: jal         0x80102924
    // 0x808003B4: nop

    func_80102924(rdram, ctx);
        goto after_27;
    // 0x808003B4: nop

    after_27:
    // 0x808003B8: jal         0x800D8FF8
    // 0x808003BC: nop

    func_800D8FF8(rdram, ctx);
        goto after_28;
    // 0x808003BC: nop

    after_28:
    // 0x808003C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1860, 0X110C) << 16);
    // 0x808003C4: lwc1        $f16, 0x110C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1860, 0X110C));
    // 0x808003C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808003CC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808003D0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808003D4: jal         0x80102B2C
    // 0x808003D8: nop

    func_80102B2C(rdram, ctx);
        goto after_29;
    // 0x808003D8: nop

    after_29:
    // 0x808003DC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808003E0: jal         0x80102CF4
    // 0x808003E4: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_80102CF4(rdram, ctx);
        goto after_30;
    // 0x808003E4: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_30:
    // 0x808003E8: beq         $v0, $zero, L_8080041C
    if (ctx->r2 == 0) {
        // 0x808003EC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8080041C;
    }
    // 0x808003EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003F0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x808003F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808003F8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x808003FC: lh          $t6, 0x6A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6A);
    // 0x80800400: bnel        $v1, $t6, L_80800414
    if (ctx->r3 != ctx->r14) {
        // 0x80800404: sh          $v1, 0x6A($v0)
        MEM_H(0X6A, ctx->r2) = ctx->r3;
            goto L_80800414;
    }
    goto skip_1;
    // 0x80800404: sh          $v1, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r3;
    skip_1:
    // 0x80800408: b           L_80800414
    // 0x8080040C: sh          $t7, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r15;
        goto L_80800414;
    // 0x8080040C: sh          $t7, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r15;
    // 0x80800410: sh          $v1, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r3;
L_80800414:
    // 0x80800414: jal         0x80102424
    // 0x80800418: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80102424(rdram, ctx);
        goto after_31;
    // 0x80800418: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_31:
L_8080041C:
    // 0x8080041C: jal         0x80800C60
    // 0x80800420: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800C60_chamazongoldhordeofficial(rdram, ctx);
        goto after_32;
    // 0x80800420: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_32:
    // 0x80800424: b           L_80800624
    // 0x80800428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800624;
    // 0x80800428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080042C:
    // 0x8080042C: jal         0x80800C60
    // 0x80800430: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800C60_chamazongoldhordeofficial(rdram, ctx);
        goto after_33;
    // 0x80800430: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_33:
    // 0x80800434: jal         0x80800E94
    // 0x80800438: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800E94_chamazongoldhordeofficial(rdram, ctx);
        goto after_34;
    // 0x80800438: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_34:
    // 0x8080043C: b           L_80800624
    // 0x80800440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800624;
    // 0x80800440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800444:
    // 0x80800444: jal         0x8010CEAC
    // 0x80800448: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8010CEAC(rdram, ctx);
        goto after_35;
    // 0x80800448: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_35:
    // 0x8080044C: b           L_80800624
    // 0x80800450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800624;
    // 0x80800450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800454:
    // 0x80800454: jal         0x8010CEAC
    // 0x80800458: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8010CEAC(rdram, ctx);
        goto after_36;
    // 0x80800458: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_36:
    // 0x8080045C: b           L_80800624
    // 0x80800460: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800624;
    // 0x80800460: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800464:
    // 0x80800464: jal         0x800F54E4
    // 0x80800468: nop

    func_800F54E4(rdram, ctx);
        goto after_37;
    // 0x80800468: nop

    after_37:
    // 0x8080046C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800470: jal         0x8010CEAC
    // 0x80800474: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8010CEAC(rdram, ctx);
        goto after_38;
    // 0x80800474: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_38:
    // 0x80800478: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8080047C: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x80800480: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x80800484: bltzl       $t1, L_80800624
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800488: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800624;
    }
    goto skip_2;
    // 0x80800488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080048C: jal         0x800F5F7C
    // 0x80800490: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800F5F7C(rdram, ctx);
        goto after_39;
    // 0x80800490: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_39:
    // 0x80800494: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800498: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080049C: nop

    // 0x808004A0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808004A4: nop

    // 0x808004A8: bc1fl       L_80800624
    if (!c1cs) {
        // 0x808004AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800624;
    }
    goto skip_3;
    // 0x808004AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808004B0: jal         0x800F56AC
    // 0x808004B4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800F56AC(rdram, ctx);
        goto after_40;
    // 0x808004B4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_40:
    // 0x808004B8: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x808004BC: beq         $v0, $at, L_80800620
    if (ctx->r2 == ctx->r1) {
        // 0x808004C0: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80800620;
    }
    // 0x808004C0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808004C4: jal         0x800F64A4
    // 0x808004C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_41;
    // 0x808004C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_41:
    // 0x808004CC: beql        $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x808004D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800624;
    }
    goto skip_4;
    // 0x808004D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x808004D4: jal         0x8010CD28
    // 0x808004D8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8010CD28(rdram, ctx);
        goto after_42;
    // 0x808004D8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_42:
    // 0x808004DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004E0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808004E4: jal         0x800EEB9C
    // 0x808004E8: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_43;
    // 0x808004E8: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    after_43:
    // 0x808004EC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x808004F0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808004F4: jal         0x800EF04C
    // 0x808004F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_44;
    // 0x808004F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_44:
    // 0x808004FC: jal         0x8008F8B0
    // 0x80800500: nop

    func_8008F8B0(rdram, ctx);
        goto after_45;
    // 0x80800500: nop

    after_45:
    // 0x80800504: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80800508: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8080050C: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800510: jal         0x8008F904
    // 0x80800514: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    func_8008F904(rdram, ctx);
        goto after_46;
    // 0x80800514: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    after_46:
    // 0x80800518: jal         0x8008F8D8
    // 0x8080051C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_47;
    // 0x8080051C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_47:
    // 0x80800520: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800524: jal         0x8008F990
    // 0x80800528: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_8008F990(rdram, ctx);
        goto after_48;
    // 0x80800528: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_48:
    // 0x8080052C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800530: jal         0x80100094
    // 0x80800534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_49;
    // 0x80800534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_49:
    // 0x80800538: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8080053C: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    // 0x80800540: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80800544: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x80800548: jal         0x8008A2D0
    // 0x8080054C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_50;
    // 0x8080054C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_50:
    // 0x80800550: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800554: jal         0x80102424
    // 0x80800558: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_51;
    // 0x80800558: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_51:
    // 0x8080055C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80800560: lbu         $t5, 0x65($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X65);
    // 0x80800564: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x80800568: b           L_80800620
    // 0x8080056C: sb          $t6, 0x65($t3)
    MEM_B(0X65, ctx->r11) = ctx->r14;
        goto L_80800620;
    // 0x8080056C: sb          $t6, 0x65($t3)
    MEM_B(0X65, ctx->r11) = ctx->r14;
L_80800570:
    // 0x80800570: jal         0x8010CEAC
    // 0x80800574: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8010CEAC(rdram, ctx);
        goto after_52;
    // 0x80800574: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_52:
    // 0x80800578: jal         0x80800E94
    // 0x8080057C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800E94_chamazongoldhordeofficial(rdram, ctx);
        goto after_53;
    // 0x8080057C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_53:
    // 0x80800580: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800584: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800588: addiu       $a2, $zero, 0x1D9
    ctx->r6 = ADD32(0, 0X1D9);
    // 0x8080058C: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x80800590: jal         0x800902E4
    // 0x80800594: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800902E4(rdram, ctx);
        goto after_54;
    // 0x80800594: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_54:
    // 0x80800598: jal         0x8008FE14
    // 0x8080059C: nop

    func_8008FE14(rdram, ctx);
        goto after_55;
    // 0x8080059C: nop

    after_55:
    // 0x808005A0: addiu       $at, $zero, 0x1D9
    ctx->r1 = ADD32(0, 0X1D9);
    // 0x808005A4: bnel        $v0, $at, L_80800624
    if (ctx->r2 != ctx->r1) {
        // 0x808005A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800624;
    }
    goto skip_5;
    // 0x808005A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x808005AC: jal         0x80090818
    // 0x808005B0: nop

    func_80090818(rdram, ctx);
        goto after_56;
    // 0x808005B0: nop

    after_56:
    // 0x808005B4: beql        $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x808005B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800624;
    }
    goto skip_6;
    // 0x808005B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x808005BC: jal         0x8010CD28
    // 0x808005C0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8010CD28(rdram, ctx);
        goto after_57;
    // 0x808005C0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_57:
    // 0x808005C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005C8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808005CC: jal         0x800EEB9C
    // 0x808005D0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_58;
    // 0x808005D0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_58:
    // 0x808005D4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x808005D8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808005DC: jal         0x800EF04C
    // 0x808005E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_59;
    // 0x808005E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_59:
    // 0x808005E4: jal         0x80090768
    // 0x808005E8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_80090768(rdram, ctx);
        goto after_60;
    // 0x808005E8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_60:
    // 0x808005EC: jal         0x800DA544
    // 0x808005F0: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    func_800DA544(rdram, ctx);
        goto after_61;
    // 0x808005F0: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_61:
    // 0x808005F4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x808005F8: addiu       $t8, $zero, 0x31
    ctx->r24 = ADD32(0, 0X31);
    // 0x808005FC: addiu       $a1, $zero, 0xF2D
    ctx->r5 = ADD32(0, 0XF2D);
    // 0x80800600: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800604: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800608: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080060C: jal         0x8008A208
    // 0x80800610: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_62;
    // 0x80800610: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    after_62:
    // 0x80800614: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800618: jal         0x80102424
    // 0x8080061C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_63;
    // 0x8080061C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_63:
L_80800620:
    // 0x80800620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800624:
    // 0x80800624: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800628: jr          $ra
    // 0x8080062C: nop

    return;
    // 0x8080062C: nop

;}
RECOMP_FUNC void func_808004A0_chjigsaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808004A4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808004A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004AC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808004B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808004C0: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x808004C4: jal         0x800EFA4C
    // 0x808004C8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x808004C8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x808004CC: jal         0x80101970
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101970(rdram, ctx);
        goto after_1;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808004D4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x808004D8: addiu       $a0, $a0, 0x15D0
    ctx->r4 = ADD32(ctx->r4, 0X15D0);
    // 0x808004DC: jal         0x800DF47C
    // 0x808004E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_2;
    // 0x808004E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808004E4: jal         0x8010347C
    // 0x808004E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_3;
    // 0x808004E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808004EC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808004F0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808004F4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808004F8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808004FC: jal         0x800DE448
    // 0x80800500: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_4;
    // 0x80800500: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80800504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800508: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080050C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800510: jr          $ra
    // 0x80800514: nop

    return;
    // 0x80800514: nop

;}
RECOMP_FUNC void func_80105634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010563C: lw          $v0, 0x7C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X7C);
    // 0x80105640: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80105644: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80105648: andi        $t6, $v0, 0xFFF
    ctx->r14 = ctx->r2 & 0XFFF;
    // 0x8010564C: beq         $t6, $zero, L_8010567C
    if (ctx->r14 == 0) {
        // 0x80105650: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_8010567C;
    }
    // 0x80105650: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80105654: lw          $a0, 0x6EC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EC0);
    // 0x80105658: jal         0x800B32C0
    // 0x8010565C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    freelist_erase(rdram, ctx);
        goto after_0;
    // 0x8010565C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80105660: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80105664: lhu         $t7, 0x7E($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X7E);
    // 0x80105668: lbu         $t9, 0x77($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X77);
    // 0x8010566C: andi        $t8, $t7, 0xF000
    ctx->r24 = ctx->r15 & 0XF000;
    // 0x80105670: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80105674: sh          $t8, 0x7E($a2)
    MEM_H(0X7E, ctx->r6) = ctx->r24;
    // 0x80105678: sb          $t0, 0x77($a2)
    MEM_B(0X77, ctx->r6) = ctx->r8;
L_8010567C:
    // 0x8010567C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105684: jr          $ra
    // 0x80105688: nop

    return;
    // 0x80105688: nop

;}
RECOMP_FUNC void func_800921E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800921E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800921E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800921E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800921EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800921F0: lw          $t7, 0x50($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X50);
    // 0x800921F4: jal         0x8009C2A0
    // 0x800921F8: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_8009C2A0(rdram, ctx);
        goto after_0;
    // 0x800921F8: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_0:
    // 0x800921FC: jal         0x800EEEA8
    // 0x80092200: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EEEA8(rdram, ctx);
        goto after_1;
    // 0x80092200: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80092204: beq         $v0, $zero, L_80092214
    if (ctx->r2 == 0) {
        // 0x80092208: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80092214;
    }
    // 0x80092208: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009220C: jal         0x8009C128
    // 0x80092210: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x80092210: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
L_80092214:
    // 0x80092214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009221C: jr          $ra
    // 0x80092220: nop

    return;
    // 0x80092220: nop

;}
RECOMP_FUNC void _chfootwear_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087780: syscall     620
    recomp_syscall_handler(rdram, ctx, 0x80087780);
    return;
    // 0x80087784: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800A2D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2D94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2D98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2D9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A2DA0: jal         0x800889E8
    // 0x800A2DA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _fxstep_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800A2DA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800A2DA8: lw          $t6, 0x124($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X124);
    // 0x800A2DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2DB0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800A2DB4: jal         0x800A2EDC
    // 0x800A2DB8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    func_800A2EDC(rdram, ctx);
        goto after_1;
    // 0x800A2DB8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    after_1:
    // 0x800A2DBC: jal         0x800D3948
    // 0x800A2DC0: nop

    func_800D3948(rdram, ctx);
        goto after_2;
    // 0x800A2DC0: nop

    after_2:
    // 0x800A2DC4: lw          $t7, 0x124($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X124);
    // 0x800A2DC8: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800A2DCC: jal         0x800889F8
    // 0x800A2DD0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _fxstep_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x800A2DD0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_3:
    // 0x800A2DD4: lw          $t8, 0x124($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X124);
    // 0x800A2DD8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A2DDC: addiu       $a1, $a1, 0x2A00
    ctx->r5 = ADD32(ctx->r5, 0X2A00);
    // 0x800A2DE0: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    // 0x800A2DE4: jal         0x80088A00
    // 0x800A2DE8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _fxstep_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x800A2DE8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_4:
    // 0x800A2DEC: lw          $t9, 0x124($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X124);
    // 0x800A2DF0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800A2DF4: addiu       $a1, $a1, 0x2848
    ctx->r5 = ADD32(ctx->r5, 0X2848);
    // 0x800A2DF8: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    // 0x800A2DFC: jal         0x80088A18
    // 0x800A2E00: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _fxstep_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x800A2E00: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_5:
    // 0x800A2E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2E08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A2E0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A2E10: jr          $ra
    // 0x800A2E14: nop

    return;
    // 0x800A2E14: nop

;}
RECOMP_FUNC void func_80800C18_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C20: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800C24: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1932, 0X111C) << 16);
    // 0x80800C28: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1932, 0X1144) << 16);
    // 0x80800C2C: addiu       $a3, $a3, 0x1144
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1932, 0X1144));
    // 0x80800C30: addiu       $a2, $a2, 0x111C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1932, 0X111C));
    // 0x80800C34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800C38: jal         0x80089D28
    // 0x80800C3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800C3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C40: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1932, 0X112C) << 16);
    // 0x80800C44: addiu       $a2, $a2, 0x112C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1932, 0X112C));
    // 0x80800C48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C4C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C50: jal         0x80089D20
    // 0x80800C54: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800C54: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    after_1:
    // 0x80800C58: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1932, 0X1138) << 16);
    // 0x80800C5C: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x80800C60: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800C64: addiu       $a2, $a2, 0x1138
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1932, 0X1138));
    // 0x80800C68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C6C: jal         0x80089D20
    // 0x80800C70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800C70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C7C: jr          $ra
    // 0x80800C80: nop

    return;
    // 0x80800C80: nop

;}
RECOMP_FUNC void func_808003E0_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003EC: jal         0x800C6DA0
    // 0x808003F0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    func_800C6DA0(rdram, ctx);
        goto after_0;
    // 0x808003F0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_0:
    // 0x808003F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003F8: jal         0x800A0CF4
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_1;
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800400: jal         0x800A4E30
    // 0x80800404: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_2;
    // 0x80800404: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080040C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800410: jr          $ra
    // 0x80800414: nop

    return;
    // 0x80800414: nop

;}
RECOMP_FUNC void _chminegrilldoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871B0: syscall     532
    recomp_syscall_handler(rdram, ctx, 0x800871B0);
    return;
    // 0x800871B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chfactorytwinklies_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1308, 0X22A8) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x22A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X22A8));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x22A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X22A8));
;}
RECOMP_FUNC void func_80102844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102844: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80102848: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010284C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80102850: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80102854: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80102858: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8010285C: jal         0x80102D78
    // 0x80102860: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80102D78(rdram, ctx);
        goto after_0;
    // 0x80102860: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80102864: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80102868: jal         0x80102924
    // 0x8010286C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102924(rdram, ctx);
        goto after_1;
    // 0x8010286C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80102870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80102874: jal         0x80102B2C
    // 0x80102878: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80102B2C(rdram, ctx);
        goto after_2;
    // 0x80102878: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8010287C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80102880: jal         0x80102CF4
    // 0x80102884: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_80102CF4(rdram, ctx);
        goto after_3;
    // 0x80102884: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_3:
    // 0x80102888: beq         $v0, $zero, L_801028AC
    if (ctx->r2 == 0) {
        // 0x8010288C: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_801028AC;
    }
    // 0x8010288C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80102890: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80102894: beq         $a1, $at, L_801028A4
    if (ctx->r5 == ctx->r1) {
        // 0x80102898: nop
    
            goto L_801028A4;
    }
    // 0x80102898: nop

    // 0x8010289C: jal         0x80102424
    // 0x801028A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x801028A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_801028A4:
    // 0x801028A4: b           L_801028B0
    // 0x801028A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801028B0;
    // 0x801028A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801028AC:
    // 0x801028AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801028B0:
    // 0x801028B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801028B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801028B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801028BC: jr          $ra
    // 0x801028C0: nop

    return;
    // 0x801028C0: nop

;}
RECOMP_FUNC void func_800F7700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7700: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7704: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7708: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F770C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7710: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7718: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F771C: jal         0x8009AD20
    // 0x800F7720: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD20(rdram, ctx);
        goto after_0;
    // 0x800F7720: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7724: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7728: jal         0x8009AD44
    // 0x800F772C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8009AD44(rdram, ctx);
        goto after_1;
    // 0x800F772C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800F7730: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7734: jal         0x8009E7C8
    // 0x800F7738: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F7738: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_2:
    // 0x800F773C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7740: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F7744: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F7748: jr          $ra
    // 0x800F774C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F774C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8080166C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080166C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801670: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801674: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801678: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080167C: jal         0x8008CABC
    // 0x80801680: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801680: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80801684: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80801688: jal         0x80800164
    // 0x8080168C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bstnt(rdram, ctx);
        goto after_1;
    // 0x8080168C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801694: jal         0x80091A30
    // 0x80801698: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_2;
    // 0x80801698: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x8080169C: beql        $v0, $zero, L_808016D0
    if (ctx->r2 == 0) {
        // 0x808016A0: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_808016D0;
    }
    goto skip_0;
    // 0x808016A0: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_0:
    // 0x808016A4: jal         0x8009BB50
    // 0x808016A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_3;
    // 0x808016A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808016AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808016B0: nop

    // 0x808016B4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808016B8: nop

    // 0x808016BC: bc1fl       L_808016D0
    if (!c1cs) {
        // 0x808016C0: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_808016D0;
    }
    goto skip_1;
    // 0x808016C0: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_1:
    // 0x808016C4: jal         0x8009BC6C
    // 0x808016C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_4;
    // 0x808016C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808016CC: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_808016D0:
    // 0x808016D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016D4: beq         $v0, $zero, L_80801704
    if (ctx->r2 == 0) {
        // 0x808016D8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80801704;
    }
    // 0x808016D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808016DC: beq         $v0, $at, L_8080175C
    if (ctx->r2 == ctx->r1) {
        // 0x808016E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080175C;
    }
    // 0x808016E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808016E8: beq         $v0, $at, L_80801784
    if (ctx->r2 == ctx->r1) {
        // 0x808016EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801784;
    }
    // 0x808016EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808016F4: beq         $v0, $at, L_808017C0
    if (ctx->r2 == ctx->r1) {
        // 0x808016F8: nop
    
            goto L_808017C0;
    }
    // 0x808016F8: nop

    // 0x808016FC: b           L_8080183C
    // 0x80801700: nop

        goto L_8080183C;
    // 0x80801700: nop

L_80801704:
    // 0x80801704: jal         0x8008DF8C
    // 0x80801708: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_5;
    // 0x80801708: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_5:
    // 0x8080170C: beq         $v0, $zero, L_80801730
    if (ctx->r2 == 0) {
        // 0x80801710: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801730;
    }
    // 0x80801710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801714: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80801718: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080171C: jal         0x8008CF1C
    // 0x80801720: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_6;
    // 0x80801720: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x80801724: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801728: b           L_8080183C
    // 0x8080172C: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_8080183C;
    // 0x8080172C: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80801730:
    // 0x80801730: jal         0x8008B324
    // 0x80801734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_7;
    // 0x80801734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80801738: beq         $v0, $zero, L_8080183C
    if (ctx->r2 == 0) {
        // 0x8080173C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080183C;
    }
    // 0x8080173C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801740: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80801744: ori         $a1, $a1, 0xA7F0
    ctx->r5 = ctx->r5 | 0XA7F0;
    // 0x80801748: jal         0x8008CF1C
    // 0x8080174C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_8;
    // 0x8080174C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_8:
    // 0x80801750: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801754: b           L_8080183C
    // 0x80801758: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_8080183C;
    // 0x80801758: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_8080175C:
    // 0x8080175C: jal         0x8008DF8C
    // 0x80801760: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_9;
    // 0x80801760: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_9:
    // 0x80801764: beq         $v0, $zero, L_8080183C
    if (ctx->r2 == 0) {
        // 0x80801768: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080183C;
    }
    // 0x80801768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080176C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80801770: jal         0x8008CF1C
    // 0x80801774: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_10;
    // 0x80801774: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_10:
    // 0x80801778: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8080177C: b           L_8080183C
    // 0x80801780: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_8080183C;
    // 0x80801780: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_80801784:
    // 0x80801784: jal         0x8009D3A8
    // 0x80801788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_11;
    // 0x80801788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8080178C: jal         0x8008E078
    // 0x80801790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_12;
    // 0x80801790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801794: beq         $v0, $zero, L_8080183C
    if (ctx->r2 == 0) {
        // 0x80801798: nop
    
            goto L_8080183C;
    }
    // 0x80801798: nop

    // 0x8080179C: jal         0x800A2EAC
    // 0x808017A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2EAC(rdram, ctx);
        goto after_13;
    // 0x808017A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808017A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017A8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808017AC: jal         0x8008CF1C
    // 0x808017B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_14;
    // 0x808017B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_14:
    // 0x808017B4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x808017B8: b           L_8080183C
    // 0x808017BC: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
        goto L_8080183C;
    // 0x808017BC: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
L_808017C0:
    // 0x808017C0: jal         0x8009BB5C
    // 0x808017C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_15;
    // 0x808017C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808017C8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808017CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808017D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017D4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808017D8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808017DC: jal         0x8009B9B0
    // 0x808017E0: nop

    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x808017E0: nop

    after_16:
    // 0x808017E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017E8: jal         0x8009D2D8
    // 0x808017EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_17;
    // 0x808017EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x808017F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017F4: jal         0x8009D3A8
    // 0x808017F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_18;
    // 0x808017F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x808017FC: jal         0x8008B324
    // 0x80801800: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_19;
    // 0x80801800: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_19:
    // 0x80801804: beq         $v0, $zero, L_8080183C
    if (ctx->r2 == 0) {
        // 0x80801808: nop
    
            goto L_8080183C;
    }
    // 0x80801808: nop

    // 0x8080180C: jal         0x8009BB5C
    // 0x80801810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_20;
    // 0x80801810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801814: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801818: addiu       $t0, $zero, 0x108
    ctx->r8 = ADD32(0, 0X108);
    // 0x8080181C: addiu       $t1, $zero, 0x10C
    ctx->r9 = ADD32(0, 0X10C);
    // 0x80801820: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80801824: nop

    // 0x80801828: bc1fl       L_8080183C
    if (!c1cs) {
        // 0x8080182C: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_8080183C;
    }
    goto skip_2;
    // 0x8080182C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    skip_2:
    // 0x80801830: b           L_8080183C
    // 0x80801834: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
        goto L_8080183C;
    // 0x80801834: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80801838: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_8080183C:
    // 0x8080183C: jal         0x8009BB50
    // 0x80801840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_21;
    // 0x80801840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80801844: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80801848: nop

    // 0x8080184C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80801850: nop

    // 0x80801854: bc1f        L_80801870
    if (!c1cs) {
        // 0x80801858: nop
    
            goto L_80801870;
    }
    // 0x80801858: nop

    // 0x8080185C: jal         0x8008E35C
    // 0x80801860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_22;
    // 0x80801860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80801864: beq         $v0, $zero, L_80801870
    if (ctx->r2 == 0) {
        // 0x80801868: addiu       $t2, $zero, 0x111
        ctx->r10 = ADD32(0, 0X111);
            goto L_80801870;
    }
    // 0x80801868: addiu       $t2, $zero, 0x111
    ctx->r10 = ADD32(0, 0X111);
    // 0x8080186C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80801870:
    // 0x80801870: jal         0x808014B0
    // 0x80801874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstnt_entrypoint_8(rdram, ctx);
        goto after_23;
    // 0x80801874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80801878: beq         $v0, $zero, L_80801884
    if (ctx->r2 == 0) {
        // 0x8080187C: addiu       $t3, $zero, 0x10E
        ctx->r11 = ADD32(0, 0X10E);
            goto L_80801884;
    }
    // 0x8080187C: addiu       $t3, $zero, 0x10E
    ctx->r11 = ADD32(0, 0X10E);
    // 0x80801880: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_80801884:
    // 0x80801884: jal         0x8008E078
    // 0x80801888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_24;
    // 0x80801888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8080188C: beq         $v0, $zero, L_808018A8
    if (ctx->r2 == 0) {
        // 0x80801890: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808018A8;
    }
    // 0x80801890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801894: jal         0x80091A58
    // 0x80801898: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_25;
    // 0x80801898: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_25:
    // 0x8080189C: beq         $v0, $zero, L_808018A8
    if (ctx->r2 == 0) {
        // 0x808018A0: addiu       $t4, $zero, 0x107
        ctx->r12 = ADD32(0, 0X107);
            goto L_808018A8;
    }
    // 0x808018A0: addiu       $t4, $zero, 0x107
    ctx->r12 = ADD32(0, 0X107);
    // 0x808018A4: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
L_808018A8:
    // 0x808018A8: jal         0x80800F94
    // 0x808018AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstnt_entrypoint_4(rdram, ctx);
        goto after_26;
    // 0x808018AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808018B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018B4: jal         0x8009E5C8
    // 0x808018B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_27;
    // 0x808018B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_27:
    // 0x808018BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808018C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808018C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808018C8: jr          $ra
    // 0x808018CC: nop

    return;
    // 0x808018CC: nop

;}
