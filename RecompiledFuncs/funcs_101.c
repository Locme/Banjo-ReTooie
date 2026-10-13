#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800DE4_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800DE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800DF0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800DF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800DF8: jal         0x80100094
    // 0x80800DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E00: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800E04: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800E08: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800E0C: beq         $a0, $zero, L_80800E24
    if (ctx->r4 == 0) {
        // 0x80800E10: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800E24;
    }
    // 0x80800E10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E14: beq         $a0, $at, L_80800E94
    if (ctx->r4 == ctx->r1) {
        // 0x80800E18: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80800E94;
    }
    // 0x80800E18: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800E1C: b           L_80800EA4
    // 0x80800E20: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800EA4;
    // 0x80800E20: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800E24:
    // 0x80800E24: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80800E28: jal         0x800D0A9C
    // 0x80800E2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x80800E2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800E30: bne         $v0, $zero, L_80800E80
    if (ctx->r2 != 0) {
        // 0x80800E34: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_80800E80;
    }
    // 0x80800E34: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E38: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x80800E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E40: addiu       $a1, $v1, 0x24
    ctx->r5 = ADD32(ctx->r3, 0X24);
    // 0x80800E44: slti        $at, $t6, 0x32
    ctx->r1 = SIGNED(ctx->r14) < 0X32 ? 1 : 0;
    // 0x80800E48: bne         $at, $zero, L_80800E80
    if (ctx->r1 != 0) {
        // 0x80800E4C: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_80800E80;
    }
    // 0x80800E4C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800E50: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800E54: jal         0x8008A2C8
    // 0x80800E58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800E58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80800E5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800E60: addiu       $t7, $zero, 0x99
    ctx->r15 = ADD32(0, 0X99);
    // 0x80800E64: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800E68: addiu       $a1, $zero, 0x140B
    ctx->r5 = ADD32(0, 0X140B);
    // 0x80800E6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800E70: jal         0x8008A208
    // 0x80800E74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800E74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80800E78: b           L_80800EA4
    // 0x80800E7C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800EA4;
    // 0x80800E7C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800E80:
    // 0x80800E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E84: jal         0x80800018
    // 0x80800E88: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800018_chwaspnestgame(rdram, ctx);
        goto after_4;
    // 0x80800E88: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x80800E8C: b           L_80800EA4
    // 0x80800E90: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800EA4;
    // 0x80800E90: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800E94:
    // 0x80800E94: jal         0x80800018
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800018_chwaspnestgame(rdram, ctx);
        goto after_5;
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800E9C: b           L_80800EA4
    // 0x80800EA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800EA4;
    // 0x80800EA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800EA4:
    // 0x80800EA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800EA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800EAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800EB0: jr          $ra
    // 0x80800EB4: nop

    return;
    // 0x80800EB4: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C18: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C18);
    return;
    // 0x80082C1C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800A84_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A84: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800A88: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800A8C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800A90: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800A94: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800A98: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800A9C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800AA0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80800AA4: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800AA8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800AAC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800AB0: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800AB4: bgez        $t8, L_80800BF4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800AB8: lui         $s1, 0x8080
        ctx->r17 = S32(RELOC_HI16(1860, 0X12DC) << 16);
            goto L_80800BF4;
    }
    // 0x80800AB8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1860, 0X12DC) << 16);
    // 0x80800ABC: addiu       $s1, $s1, 0x12DC
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1860, 0X12DC));
L_80800AC0:
    // 0x80800AC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800AC4: jal         0x80101E14
    // 0x80800AC8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x80800AC8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x80800ACC: beq         $v0, $zero, L_80800BE4
    if (ctx->r2 == 0) {
        // 0x80800AD0: sll         $t9, $s0, 1
        ctx->r25 = S32(ctx->r16 << 1);
            goto L_80800BE4;
    }
    // 0x80800AD0: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x80800AD4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1860, 0X12D0) << 16);
    // 0x80800AD8: addiu       $s4, $sp, 0x54
    ctx->r20 = ADD32(ctx->r29, 0X54);
    // 0x80800ADC: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x80800AE0: lh          $a1, 0x12D0($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1860, 0X12D0));
    // 0x80800AE4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80800AE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800AEC: jal         0x8008A0E0
    // 0x80800AF0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800AF0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x80800AF4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800AF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800AFC: lwc1        $f4, 0x48($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X48);
    // 0x80800B00: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800B04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800B08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800B0C: jal         0x800136E4
    // 0x80800B10: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80800B10: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x80800B14: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800B18: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B1C: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80800B20: jal         0x800136E4
    // 0x80800B24: add.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f16.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x80800B24: add.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f16.fl;
    after_3:
    // 0x80800B28: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1860, 0X12F4) << 16);
    // 0x80800B2C: lh          $t0, 0x12F4($t0)
    ctx->r8 = MEM_H(ctx->r8, (int16_t)RELOC_LO16(1860, 0X12F4));
    // 0x80800B30: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80800B34: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80800B38: beq         $s3, $t0, L_80800BF4
    if (ctx->r19 == ctx->r8) {
        // 0x80800B3C: lui         $s1, 0x8080
        ctx->r17 = S32(RELOC_HI16(1860, 0X12F4) << 16);
            goto L_80800BF4;
    }
    // 0x80800B3C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1860, 0X12F4) << 16);
    // 0x80800B40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B44: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1860, 0X12FC) << 16);
    // 0x80800B48: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800B4C: addiu       $s2, $s2, 0x12FC
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1860, 0X12FC));
    // 0x80800B50: addiu       $s1, $s1, 0x12F4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1860, 0X12F4));
    // 0x80800B54: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
L_80800B58:
    // 0x80800B58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B5C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800B60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B64: jal         0x800BABB8
    // 0x80800B68: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800B68: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_4:
    // 0x80800B6C: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800B70: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800B74: addiu       $t4, $zero, 0x140
    ctx->r12 = ADD32(0, 0X140);
    // 0x80800B78: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80800B7C: addiu       $t7, $zero, 0x320
    ctx->r15 = ADD32(0, 0X320);
    // 0x80800B80: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B84: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800B88: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800B8C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800B90: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800B94: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80800B98: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x80800B9C: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80800BA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BA4: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x80800BA8: addiu       $a3, $zero, 0x258
    ctx->r7 = ADD32(0, 0X258);
    // 0x80800BAC: jal         0x800BA994
    // 0x80800BB0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_800BA994(rdram, ctx);
        goto after_5;
    // 0x80800BB0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_5:
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB8: jal         0x800BA670
    // 0x80800BBC: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    func_800BA670(rdram, ctx);
        goto after_6;
    // 0x80800BBC: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    after_6:
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC4: jal         0x800BA22C
    // 0x80800BC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x80800BC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800BCC: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x80800BD0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80800BD4: bnel        $s3, $t8, L_80800B58
    if (ctx->r19 != ctx->r24) {
        // 0x80800BD8: mfc1        $a3, $f20
        ctx->r7 = (int32_t)ctx->f20.u32l;
            goto L_80800B58;
    }
    goto skip_0;
    // 0x80800BD8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    skip_0:
    // 0x80800BDC: b           L_80800BF8
    // 0x80800BE0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80800BF8;
    // 0x80800BE0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800BE4:
    // 0x80800BE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800BE8: sltiu       $at, $s0, 0x6
    ctx->r1 = ctx->r16 < 0X6 ? 1 : 0;
    // 0x80800BEC: bne         $at, $zero, L_80800AC0
    if (ctx->r1 != 0) {
        // 0x80800BF0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800AC0;
    }
    // 0x80800BF0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80800BF4:
    // 0x80800BF4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800BF8:
    // 0x80800BF8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80800BFC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800C00: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80800C04: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800C08: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800C0C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800C10: jr          $ra
    // 0x80800C14: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800C14: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void idflame_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080046C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800470: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800474: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800478: jal         0x800D8FF8
    // 0x8080047C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080047C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800480: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800484: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80800488: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080048C: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80800490: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80800494: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800498: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080049C: addiu       $a2, $a2, -0x71E0
    ctx->r6 = ADD32(ctx->r6, -0X71E0);
    // 0x808004A0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808004A4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x808004A8: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x808004AC: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808004B0: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x808004B4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x808004B8: nop

    // 0x808004BC: slti        $at, $v0, 0x2001
    ctx->r1 = SIGNED(ctx->r2) < 0X2001 ? 1 : 0;
    // 0x808004C0: bne         $at, $zero, L_808004E8
    if (ctx->r1 != 0) {
        // 0x808004C4: lui         $at, 0x4600
        ctx->r1 = S32(0X4600 << 16);
            goto L_808004E8;
    }
    // 0x808004C4: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808004C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004CC: nop

    // 0x808004D0: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x808004D4: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x808004D8: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808004DC: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808004E0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x808004E4: nop

L_808004E8:
    // 0x808004E8: lbu         $t8, 0xA($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XA);
    // 0x808004EC: sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    // 0x808004F0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x808004F4: bltz        $t8, L_80800528
    if (SIGNED(ctx->r24) < 0) {
        // 0x808004F8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800528;
    }
    // 0x808004F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808004FC: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
L_80800500:
    // 0x80800500: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80800504: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800508: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8080050C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800510: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80800514: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x80800518: lbu         $t9, 0xA($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XA);
    // 0x8080051C: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800520: beql        $at, $zero, L_80800500
    if (ctx->r1 == 0) {
        // 0x80800524: lwc1        $f4, 0x5C($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
            goto L_80800500;
    }
    goto skip_0;
    // 0x80800524: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    skip_0:
L_80800528:
    // 0x80800528: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080052C: jal         0x80088660
    // 0x80800530: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800530: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080053C: jr          $ra
    // 0x80800540: nop

    return;
    // 0x80800540: nop

    // 0x80800544: nop

    // 0x80800548: nop

    // 0x8080054C: nop

;}
RECOMP_FUNC void func_80800C24_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C2C: jal         0x80100094
    // 0x80800C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800C38: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800C3C:
    // 0x80800C3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800C40: slti        $at, $a0, 0x1E
    ctx->r1 = SIGNED(ctx->r4) < 0X1E ? 1 : 0;
    // 0x80800C44: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800C48: bne         $at, $zero, L_80800C3C
    if (ctx->r1 != 0) {
        // 0x80800C4C: sb          $zero, 0x9B($v1)
        MEM_B(0X9B, ctx->r3) = 0;
            goto L_80800C3C;
    }
    // 0x80800C4C: sb          $zero, 0x9B($v1)
    MEM_B(0X9B, ctx->r3) = 0;
    // 0x80800C50: sb          $zero, 0xBA($v0)
    MEM_B(0XBA, ctx->r2) = 0;
    // 0x80800C54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800C58: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80800C5C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
L_80800C60:
    // 0x80800C60: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800C64: sb          $zero, 0xBB($v1)
    MEM_B(0XBB, ctx->r3) = 0;
    // 0x80800C68: sb          $zero, 0xBC($v1)
    MEM_B(0XBC, ctx->r3) = 0;
    // 0x80800C6C: sb          $zero, 0xBD($v1)
    MEM_B(0XBD, ctx->r3) = 0;
    // 0x80800C70: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800C74: bne         $a0, $a1, L_80800C60
    if (ctx->r4 != ctx->r5) {
        // 0x80800C78: sb          $zero, 0xB6($v1)
        MEM_B(0XB6, ctx->r3) = 0;
            goto L_80800C60;
    }
    // 0x80800C78: sb          $zero, 0xB6($v1)
    MEM_B(0XB6, ctx->r3) = 0;
    // 0x80800C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C84: jr          $ra
    // 0x80800C88: nop

    return;
    // 0x80800C88: nop

;}
RECOMP_FUNC void func_800E9048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9048: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E904C: jr          $ra
    // 0x800E9050: lh          $v0, 0x1CE0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X1CE0);
    return;
    // 0x800E9050: lh          $v0, 0x1CE0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X1CE0);
;}
RECOMP_FUNC void baeggfire_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004F0: jal         0x8009E0AC
    // 0x808004F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E0AC(rdram, ctx);
        goto after_0;
    // 0x808004F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808004F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800500: jr          $ra
    // 0x80800504: nop

    return;
    // 0x80800504: nop

;}
RECOMP_FUNC void func_80800098_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080009C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A0: lbu         $t6, 0x70($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X70);
    // 0x808000A4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000AC: andi        $t7, $t6, 0xFF01
    ctx->r15 = ctx->r14 & 0XFF01;
    // 0x808000B0: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x808000B4: beq         $t8, $at, L_808000DC
    if (ctx->r24 == ctx->r1) {
        // 0x808000B8: sb          $t7, 0x70($a0)
        MEM_B(0X70, ctx->r4) = ctx->r15;
            goto L_808000DC;
    }
    // 0x808000B8: sb          $t7, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r15;
    // 0x808000BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000C0: beq         $t8, $at, L_808000EC
    if (ctx->r24 == ctx->r1) {
        // 0x808000C4: lui         $a1, 0x4040
        ctx->r5 = S32(0X4040 << 16);
            goto L_808000EC;
    }
    // 0x808000C4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x808000C8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808000CC: beq         $t8, $at, L_80800108
    if (ctx->r24 == ctx->r1) {
        // 0x808000D0: lui         $a1, 0x4040
        ctx->r5 = S32(0X4040 << 16);
            goto L_80800108;
    }
    // 0x808000D0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x808000D4: b           L_80800120
    // 0x808000D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800120;
    // 0x808000D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000DC:
    // 0x808000DC: jal         0x8008A498
    // 0x808000E0: nop

    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000E0: nop

    after_0:
    // 0x808000E4: b           L_80800120
    // 0x808000E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800120;
    // 0x808000E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000EC:
    // 0x808000EC: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x808000F0: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x808000F4: addiu       $a3, $a3, 0x6398
    ctx->r7 = ADD32(ctx->r7, 0X6398);
    // 0x808000F8: jal         0x80800684
    // 0x808000FC: addiu       $a2, $a2, 0x69E8
    ctx->r6 = ADD32(ctx->r6, 0X69E8);
    func_80800684_chbanjoctrl(rdram, ctx);
        goto after_1;
    // 0x808000FC: addiu       $a2, $a2, 0x69E8
    ctx->r6 = ADD32(ctx->r6, 0X69E8);
    after_1:
    // 0x80800100: b           L_80800120
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800120;
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800108:
    // 0x80800108: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x8080010C: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80800110: addiu       $a3, $a3, 0x63A0
    ctx->r7 = ADD32(ctx->r7, 0X63A0);
    // 0x80800114: jal         0x80800684
    // 0x80800118: addiu       $a2, $a2, 0x6968
    ctx->r6 = ADD32(ctx->r6, 0X6968);
    func_80800684_chbanjoctrl(rdram, ctx);
        goto after_2;
    // 0x80800118: addiu       $a2, $a2, 0x6968
    ctx->r6 = ADD32(ctx->r6, 0X6968);
    after_2:
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800120:
    // 0x80800120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800124: jr          $ra
    // 0x80800128: nop

    return;
    // 0x80800128: nop

;}
RECOMP_FUNC void _badrone_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084890: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084890);
    return;
    // 0x80084894: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_8080086C_chboggyboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080086C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800870: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800874: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800878: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080087C: jal         0x80100094
    // 0x80800880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800884: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800888: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x8080088C: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x80800890: lui         $a1, 0x3FCC
    ctx->r5 = S32(0X3FCC << 16);
    // 0x80800894: bgezl       $t7, L_808008C0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800898: lhu         $t8, 0x72($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X72);
            goto L_808008C0;
    }
    goto skip_0;
    // 0x80800898: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x8080089C: jal         0x800D9154
    // 0x808008A0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_800D9154(rdram, ctx);
        goto after_1;
    // 0x808008A0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_1:
    // 0x808008A4: beq         $v0, $zero, L_808008BC
    if (ctx->r2 == 0) {
        // 0x808008A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008BC;
    }
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1532, 0XC18) << 16);
    // 0x808008B0: addiu       $a2, $a2, 0xC18
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1532, 0XC18));
    // 0x808008B4: jal         0x80089D18
    // 0x808008B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808008B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
L_808008BC:
    // 0x808008BC: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
L_808008C0:
    // 0x808008C0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C8: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808008CC: bne         $t9, $at, L_808008F8
    if (ctx->r25 != ctx->r1) {
        // 0x808008D0: addiu       $t4, $s0, 0x4
        ctx->r12 = ADD32(ctx->r16, 0X4);
            goto L_808008F8;
    }
    // 0x808008D0: addiu       $t4, $s0, 0x4
    ctx->r12 = ADD32(ctx->r16, 0X4);
    // 0x808008D4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x808008D8: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x808008DC: sll         $t3, $t1, 18
    ctx->r11 = S32(ctx->r9 << 18);
    // 0x808008E0: bltzl       $t3, L_80800968
    if (SIGNED(ctx->r11) < 0) {
        // 0x808008E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800968;
    }
    goto skip_1;
    // 0x808008E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808008E8: jal         0x800FFAB0
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008F0: b           L_80800968
    // 0x808008F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800968;
    // 0x808008F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008F8:
    // 0x808008F8: jal         0x80105834
    // 0x808008FC: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    func_80105834(rdram, ctx);
        goto after_4;
    // 0x808008FC: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_4:
    // 0x80800900: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800904: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800908: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x8080090C: jal         0x80089F18
    // 0x80800910: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800910: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_5:
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800918: jal         0x80105230
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_6;
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800920: jal         0x80105A5C
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_7;
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800928: beq         $v0, $zero, L_80800964
    if (ctx->r2 == 0) {
        // 0x8080092C: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_80800964;
    }
    // 0x8080092C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80800930: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800938: sll         $t8, $t6, 18
    ctx->r24 = S32(ctx->r14 << 18);
    // 0x8080093C: bgez        $t8, L_8080095C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800940: nop
    
            goto L_8080095C;
    }
    // 0x80800940: nop

    // 0x80800944: jal         0x80102424
    // 0x80800948: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800948: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_8:
    // 0x8080094C: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800950: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x80800954: b           L_80800964
    // 0x80800958: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
        goto L_80800964;
    // 0x80800958: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
L_8080095C:
    // 0x8080095C: jal         0x800FFAB0
    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800964:
    // 0x80800964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800968:
    // 0x80800968: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080096C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800970: jr          $ra
    // 0x80800974: nop

    return;
    // 0x80800974: nop

;}
RECOMP_FUNC void chmole_lagoon_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1780, 0XF0) << 16);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1780, 0XF0));
    return;
    // 0x808000BC: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1780, 0XF0));
;}
RECOMP_FUNC void func_808009BC_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808009C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009C4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808009C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009D0: beq         $a1, $at, L_80800ACC
    if (ctx->r5 == ctx->r1) {
        // 0x808009D4: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800ACC;
    }
    // 0x808009D4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808009D8: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808009DC: beq         $a1, $at, L_80800AE0
    if (ctx->r5 == ctx->r1) {
        // 0x808009E0: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800AE0;
    }
    // 0x808009E0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808009E4: bne         $a1, $at, L_80800AF0
    if (ctx->r5 != ctx->r1) {
        // 0x808009E8: nop
    
            goto L_80800AF0;
    }
    // 0x808009E8: nop

    // 0x808009EC: jal         0x80088840
    // 0x808009F0: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x808009F0: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_0:
    // 0x808009F4: jal         0x80800968
    // 0x808009F8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80800968_chnastycavemen(rdram, ctx);
        goto after_1;
    // 0x808009F8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A00: jal         0x80105A9C
    // 0x80800A04: lui         $a1, 0x43DC
    ctx->r5 = S32(0X43DC << 16);
    func_80105A9C(rdram, ctx);
        goto after_2;
    // 0x80800A04: lui         $a1, 0x43DC
    ctx->r5 = S32(0X43DC << 16);
    after_2:
    // 0x80800A08: lbu         $t7, 0x95($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X95);
    // 0x80800A0C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A14: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800A18: bne         $a2, $zero, L_80800ABC
    if (ctx->r6 != 0) {
        // 0x80800A1C: sb          $t8, 0x95($s0)
        MEM_B(0X95, ctx->r16) = ctx->r24;
            goto L_80800ABC;
    }
    // 0x80800A1C: sb          $t8, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r24;
    // 0x80800A20: jal         0x800DA298
    // 0x80800A24: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800A24: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_3:
    // 0x80800A28: beq         $v0, $zero, L_80800A40
    if (ctx->r2 == 0) {
        // 0x80800A2C: nop
    
            goto L_80800A40;
    }
    // 0x80800A2C: nop

    // 0x80800A30: jal         0x800FFA88
    // 0x80800A34: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_4;
    // 0x80800A34: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80800A38: b           L_80800AFC
    // 0x80800A3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AFC;
    // 0x80800A3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A40:
    // 0x80800A40: jal         0x800F54E4
    // 0x80800A44: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800A44: nop

    after_5:
    // 0x80800A48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A4C: jal         0x800F640C
    // 0x80800A50: addiu       $a1, $zero, 0x1D9
    ctx->r5 = ADD32(0, 0X1D9);
    func_800F640C(rdram, ctx);
        goto after_6;
    // 0x80800A50: addiu       $a1, $zero, 0x1D9
    ctx->r5 = ADD32(0, 0X1D9);
    after_6:
    // 0x80800A54: bne         $v0, $zero, L_80800AF8
    if (ctx->r2 != 0) {
        // 0x80800A58: addiu       $a0, $zero, 0x1C0
        ctx->r4 = ADD32(0, 0X1C0);
            goto L_80800AF8;
    }
    // 0x80800A58: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    // 0x80800A5C: jal         0x80088280
    // 0x80800A60: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800A60: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800A64: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800A68: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800A6C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800A70: jal         0x80088C00
    // 0x80800A74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800A74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800A78: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800A7C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800A80: addiu       $a0, $zero, 0x1D9
    ctx->r4 = ADD32(0, 0X1D9);
    // 0x80800A84: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80800A88: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800A8C: srl         $t1, $t0, 23
    ctx->r9 = S32(U32(ctx->r8) >> 23);
    // 0x80800A90: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80800A94: bgez        $t1, L_80800AA8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800A98: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800AA8;
    }
    // 0x80800A98: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800A9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800AA0: nop

    // 0x80800AA4: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80800AA8:
    // 0x80800AA8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800AAC: jal         0x80108A30
    // 0x80800AB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80108A30(rdram, ctx);
        goto after_9;
    // 0x80800AB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80800AB4: b           L_80800AFC
    // 0x80800AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AFC;
    // 0x80800AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800ABC:
    // 0x80800ABC: jal         0x80800268
    // 0x80800AC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800268_chnastycavemen(rdram, ctx);
        goto after_10;
    // 0x80800AC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800AC4: b           L_80800AFC
    // 0x80800AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AFC;
    // 0x80800AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800ACC:
    // 0x80800ACC: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80800AD0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800AD4: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x80800AD8: b           L_80800AFC
    // 0x80800ADC: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
        goto L_80800AFC;
    // 0x80800ADC: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
L_80800AE0:
    // 0x80800AE0: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    // 0x80800AE4: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x80800AE8: b           L_80800AF8
    // 0x80800AEC: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
        goto L_80800AF8;
    // 0x80800AEC: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
L_80800AF0:
    // 0x80800AF0: b           L_80800AFC
    // 0x80800AF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800AFC;
    // 0x80800AF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AF8:
    // 0x80800AF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AFC:
    // 0x80800AFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800B08: jr          $ra
    // 0x80800B0C: nop

    return;
    // 0x80800B0C: nop

;}
RECOMP_FUNC void func_801127A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801127A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801127AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801127B0: jal         0x80112550
    // 0x801127B4: nop

    func_80112550(rdram, ctx);
        goto after_0;
    // 0x801127B4: nop

    after_0:
    // 0x801127B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801127BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801127C0: jr          $ra
    // 0x801127C4: nop

    return;
    // 0x801127C4: nop

;}
RECOMP_FUNC void func_8080095C_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080095C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800960: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800964: jr          $ra
    // 0x80800968: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80800968: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800D1C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1C70: jr          $ra
    // 0x800D1C74: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    return;
    // 0x800D1C74: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
;}
RECOMP_FUNC void _cosection_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087888: syscall     637
    recomp_syscall_handler(rdram, ctx, 0x80087888);
    return;
    // 0x8008788C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsstatue_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800BDC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(372, 0X15C0) << 16);
    // 0x80800BE0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800BE4: jr          $ra
    // 0x80800BE8: lw          $v0, 0x15C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15C0));
    return;
    // 0x80800BE8: lw          $v0, 0x15C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15C0));
;}
RECOMP_FUNC void func_800A5090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5090: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A5094: jr          $ra
    // 0x800A5098: lw          $v0, 0x3C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X3C);
    return;
    // 0x800A5098: lw          $v0, 0x3C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X3C);
;}
RECOMP_FUNC void chmumboskullfakearchpanellava_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1960, 0X228) << 16);
    // 0x80800150: jr          $ra
    // 0x80800154: addiu       $v0, $v0, 0x228
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1960, 0X228));
    return;
    // 0x80800154: addiu       $v0, $v0, 0x228
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1960, 0X228));
    // 0x80800158: nop

    // 0x8080015C: nop

;}
RECOMP_FUNC void _chcoderoomdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087030: syscall     495
    recomp_syscall_handler(rdram, ctx, 0x80087030);
    return;
    // 0x80087034: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsbansack_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826F0: syscall     7
    recomp_syscall_handler(rdram, ctx, 0x800826F0);
    return;
    // 0x800826F4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void chlakemonster_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801784: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1748, 0X2204) << 16);
    // 0x80801788: jr          $ra
    // 0x8080178C: addiu       $v0, $v0, 0x2204
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1748, 0X2204));
    return;
    // 0x8080178C: addiu       $v0, $v0, 0x2204
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1748, 0X2204));
;}
RECOMP_FUNC void _bsmum_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083820: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083820);
    return;
    // 0x80083824: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80112524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80112528: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8011252C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80112530: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80112534: lw          $a1, 0x30($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X30);
    // 0x80112538: jal         0x800EE7F8
    // 0x8011253C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8011253C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80112540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80112544: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80112548: jr          $ra
    // 0x8011254C: nop

    return;
    // 0x8011254C: nop

;}
RECOMP_FUNC void vpmodule_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080084C: lw          $t6, 0x2C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2C);
    // 0x80800850: addiu       $v1, $a0, 0x8
    ctx->r3 = ADD32(ctx->r4, 0X8);
    // 0x80800854: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800858: addu        $t0, $t7, $a0
    ctx->r8 = ADD32(ctx->r15, ctx->r4);
    // 0x8080085C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80800860: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x80800864: beql        $at, $zero, L_808008AC
    if (ctx->r1 == 0) {
        // 0x80800868: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808008AC;
    }
    goto skip_0;
    // 0x80800868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8080086C: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
L_80800870:
    // 0x80800870: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800874: addu        $t1, $a1, $t9
    ctx->r9 = ADD32(ctx->r5, ctx->r25);
    // 0x80800878: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8080087C: addu        $v0, $t2, $a1
    ctx->r2 = ADD32(ctx->r10, ctx->r5);
    // 0x80800880: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80800884: bnel        $a2, $t3, L_8080089C
    if (ctx->r6 != ctx->r11) {
        // 0x80800888: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8080089C;
    }
    goto skip_1;
    // 0x80800888: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    skip_1:
    // 0x8080088C: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
    // 0x80800890: jr          $ra
    // 0x80800894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800898: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_8080089C:
    // 0x8080089C: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x808008A0: bnel        $at, $zero, L_80800870
    if (ctx->r1 != 0) {
        // 0x808008A4: lh          $t8, 0x2($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X2);
            goto L_80800870;
    }
    goto skip_2;
    // 0x808008A4: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    skip_2:
    // 0x808008A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008AC:
    // 0x808008AC: jr          $ra
    // 0x808008B0: nop

    return;
    // 0x808008B0: nop

    // 0x808008B4: nop

    // 0x808008B8: nop

    // 0x808008BC: nop

;}
RECOMP_FUNC void func_800EDC64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDC64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EDC68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EDC6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EDC70: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EDC74: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800EDC78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EDC7C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x800EDC80: sb          $t6, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r14;
    // 0x800EDC84: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x800EDC88: swc1        $f14, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f14.u32l;
    // 0x800EDC8C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x800EDC90: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EDC94: sh          $zero, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = 0;
    // 0x800EDC98: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800EDC9C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800EDCA0: jal         0x800ED964
    // 0x800EDCA4: sh          $t7, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r15;
    func_800ED964(rdram, ctx);
        goto after_0;
    // 0x800EDCA4: sh          $t7, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r15;
    after_0:
    // 0x800EDCA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EDCAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EDCB0: jr          $ra
    // 0x800EDCB4: nop

    return;
    // 0x800EDCB4: nop

;}
RECOMP_FUNC void func_808007EC_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808007F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808007FC: jal         0x800B53A4
    // 0x80800800: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800800: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80800804: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800808: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080080C: jal         0x800BA3FC
    // 0x80800810: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800BA3FC(rdram, ctx);
        goto after_1;
    // 0x80800810: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800814: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80800818: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1064, 0XC98) << 16);
    // 0x8080081C: addiu       $t6, $t6, 0xC98
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1064, 0XC98));
    // 0x80800820: lw          $a3, 0x38($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X38);
    // 0x80800824: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800828: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080082C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800830: jal         0x800BABB8
    // 0x80800834: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800834: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x80800838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080083C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800840: jr          $ra
    // 0x80800844: nop

    return;
    // 0x80800844: nop

;}
RECOMP_FUNC void _bswasher_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084400: syscall     109
    recomp_syscall_handler(rdram, ctx, 0x80084400);
    return;
    // 0x80084404: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800840F0: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x800840F0);
    return;
    // 0x800840F4: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_800F9184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9184: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F9188: lbu         $v0, 0x54FA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X54FA);
    // 0x800F918C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F9190: jr          $ra
    // 0x800F9194: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x800F9194: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void _mlspline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890D8: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x800890D8);
    return;
    // 0x800890DC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801A6C_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A6C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80801A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A78: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1312, 0X2790) << 16);
    // 0x80801A7C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80801A80: addiu       $a2, $a2, 0x2790
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1312, 0X2790));
    // 0x80801A84: jal         0x80089D20
    // 0x80801A88: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801A88: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80801A8C: beq         $v0, $zero, L_80801AB4
    if (ctx->r2 == 0) {
        // 0x80801A90: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801AB4;
    }
    // 0x80801A90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801A94: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80801A98: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801A9C: jal         0x800E15CC
    // 0x80801AA0: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_1;
    // 0x80801AA0: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_1:
    // 0x80801AA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801AA8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80801AAC: jal         0x80018820
    // 0x80801AB0: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    func_80018820(rdram, ctx);
        goto after_2;
    // 0x80801AB0: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_2:
L_80801AB4:
    // 0x80801AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801ABC: jr          $ra
    // 0x80801AC0: nop

    return;
    // 0x80801AC0: nop

;}
RECOMP_FUNC void func_80800000_chwaterfallgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80086240
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80800014: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800018: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x8080001C: lhu         $t6, 0x72($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X72);
    // 0x80800020: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80800024: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x80800028: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080002C: bnel        $t7, $at, L_80800080
    if (ctx->r15 != ctx->r1) {
        // 0x80800030: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800080;
    }
    goto skip_0;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800034: jal         0x8010CB0C
    // 0x80800038: addiu       $a3, $zero, -0x15E
    ctx->r7 = ADD32(0, -0X15E);
    func_8010CB0C(rdram, ctx);
        goto after_1;
    // 0x80800038: addiu       $a3, $zero, -0x15E
    ctx->r7 = ADD32(0, -0X15E);
    after_1:
    // 0x8080003C: beql        $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x80800040: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800080;
    }
    goto skip_1;
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800044: jal         0x800DA544
    // 0x80800048: addiu       $a0, $zero, 0x503
    ctx->r4 = ADD32(0, 0X503);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a0, $zero, 0x503
    ctx->r4 = ADD32(0, 0X503);
    after_2:
    // 0x8080004C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800054: jal         0x800CE928
    // 0x80800058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE928(rdram, ctx);
        goto after_3;
    // 0x80800058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8080005C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800060: jal         0x800CE88C
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_4;
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800068: jal         0x800FC660
    // 0x8080006C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC660(rdram, ctx);
        goto after_5;
    // 0x8080006C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_5:
    // 0x80800070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800074: jal         0x80103110
    // 0x80800078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_6;
    // 0x80800078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800080:
    // 0x80800080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void chhotwaterpoolbits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080056C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800574: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800578: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080057C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800580: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800584: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800588: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080058C: jal         0x80106790
    // 0x80800590: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800590: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80800594: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800598: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8080059C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x808005A0: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808005A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808005A8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808005AC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x808005B0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x808005B4: nop

    // 0x808005B8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x808005BC: beql        $t0, $zero, L_8080060C
    if (ctx->r8 == 0) {
        // 0x808005C0: mfc1        $t0, $f6
        ctx->r8 = (int32_t)ctx->f6.u32l;
            goto L_8080060C;
    }
    goto skip_0;
    // 0x808005C0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x808005C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808005CC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808005D0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x808005D4: nop

    // 0x808005D8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808005DC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x808005E0: nop

    // 0x808005E4: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x808005E8: bne         $t0, $zero, L_80800600
    if (ctx->r8 != 0) {
        // 0x808005EC: nop
    
            goto L_80800600;
    }
    // 0x808005EC: nop

    // 0x808005F0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x808005F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808005F8: b           L_80800618
    // 0x808005FC: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80800618;
    // 0x808005FC: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80800600:
    // 0x80800600: b           L_80800618
    // 0x80800604: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80800618;
    // 0x80800604: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80800608: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
L_8080060C:
    // 0x8080060C: nop

    // 0x80800610: bltz        $t0, L_80800600
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800614: nop
    
            goto L_80800600;
    }
    // 0x80800614: nop

L_80800618:
    // 0x80800618: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8080061C: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80800620: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80800624: andi        $t7, $t0, 0xFF
    ctx->r15 = ctx->r8 & 0XFF;
    // 0x80800628: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080062C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80800630: addu        $t2, $t5, $s0
    ctx->r10 = ADD32(ctx->r13, ctx->r16);
    // 0x80800634: sltu        $at, $s0, $t2
    ctx->r1 = ctx->r16 < ctx->r10 ? 1 : 0;
    // 0x80800638: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8080063C: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x80800640: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x80800644: beq         $at, $zero, L_808006A8
    if (ctx->r1 == 0) {
        // 0x80800648: sra         $t1, $t9, 16
        ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
            goto L_808006A8;
    }
    // 0x80800648: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
L_8080064C:
    // 0x8080064C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800658: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8080065C:
    // 0x8080065C: lw          $t6, 0x28($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X28);
    // 0x80800660: lbu         $t7, 0xC($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XC);
    // 0x80800664: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800668: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8080066C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800670: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800674: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80800678: mflo        $t8
    ctx->r24 = lo;
    // 0x8080067C: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x80800680: bne         $v1, $a3, L_8080065C
    if (ctx->r3 != ctx->r7) {
        // 0x80800684: sb          $t9, 0xB($a0)
        MEM_B(0XB, ctx->r4) = ctx->r25;
            goto L_8080065C;
    }
    // 0x80800684: sb          $t9, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r25;
    // 0x80800688: sb          $t0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r8;
    // 0x8080068C: lh          $t3, 0x2($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X2);
    // 0x80800690: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800694: sltu        $at, $s0, $t2
    ctx->r1 = ctx->r16 < ctx->r10 ? 1 : 0;
    // 0x80800698: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x8080069C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808006A0: bne         $at, $zero, L_8080064C
    if (ctx->r1 != 0) {
        // 0x808006A4: sh          $t4, -0xE($s0)
        MEM_H(-0XE, ctx->r16) = ctx->r12;
            goto L_8080064C;
    }
    // 0x808006A4: sh          $t4, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r12;
L_808006A8:
    // 0x808006A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808006B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808006B4: jr          $ra
    // 0x808006B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808006B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _subaddietaxi_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A528: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A528);
    return;
    // 0x8008A52C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void cheggclockwork_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800488: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2104, 0X8C0) << 16);
    // 0x8080048C: jr          $ra
    // 0x80800490: addiu       $v0, $v0, 0x8C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2104, 0X8C0));
    return;
    // 0x80800490: addiu       $v0, $v0, 0x8C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2104, 0X8C0));
;}
RECOMP_FUNC void func_808005C0_bsbbilldrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C8: jal         0x800D8FF8
    // 0x808005CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808005CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005D4: lwc1        $f6, 0x170($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X170);
    // 0x808005D8: lwc1        $f4, 0x16C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X16C);
    // 0x808005DC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808005E0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808005E4: swc1        $f10, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f10.u32l;
    // 0x808005E8: jal         0x8009328C
    // 0x808005EC: lw          $a1, 0x16C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X16C);
    func_8009328C(rdram, ctx);
        goto after_1;
    // 0x808005EC: lw          $a1, 0x16C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X16C);
    after_1:
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005F8: jr          $ra
    // 0x808005FC: nop

    return;
    // 0x808005FC: nop

;}
RECOMP_FUNC void func_808017B0_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017B8: jal         0x800A4E30
    // 0x808017BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A4E30(rdram, ctx);
        goto after_0;
    // 0x808017BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808017C0: jal         0x800A042C
    // 0x808017C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A042C(rdram, ctx);
        goto after_1;
    // 0x808017C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808017C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808017CC: jal         0x800A0CF4
    // 0x808017D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x808017D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808017D4: jal         0x8008E95C
    // 0x808017D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E95C(rdram, ctx);
        goto after_3;
    // 0x808017D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808017DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808017E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808017E4: jr          $ra
    // 0x808017E8: nop

    return;
    // 0x808017E8: nop

;}
RECOMP_FUNC void func_8002BAAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BAAC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002BAB0: bne         $a2, $zero, L_8002BAEC
    if (ctx->r6 != 0) {
        // 0x8002BAB4: nop
    
            goto L_8002BAEC;
    }
    // 0x8002BAB4: nop

    // 0x8002BAB8: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
    // 0x8002BABC: nop

    // 0x8002BAC0: bc1f        L_8002BAE0
    if (!c1cs) {
        // 0x8002BAC4: nop
    
            goto L_8002BAE0;
    }
    // 0x8002BAC4: nop

    // 0x8002BAC8: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x8002BACC: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x8002BAD0: b           L_8002BCB4
    // 0x8002BAD4: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_8002BCB4;
    // 0x8002BAD4: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x8002BAD8: b           L_8002BAEC
    // 0x8002BADC: nop

        goto L_8002BAEC;
    // 0x8002BADC: nop

L_8002BAE0:
    // 0x8002BAE0: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x8002BAE4: b           L_8002BCB4
    // 0x8002BAE8: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
        goto L_8002BCB4;
    // 0x8002BAE8: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
L_8002BAEC:
    // 0x8002BAEC: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x8002BAF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BAF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002BAF8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002BAFC: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8002BB00: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x8002BB04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BB08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002BB0C: nop

    // 0x8002BB10: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x8002BB14: nop

    // 0x8002BB18: bc1f        L_8002BB2C
    if (!c1cs) {
        // 0x8002BB1C: nop
    
            goto L_8002BB2C;
    }
    // 0x8002BB1C: nop

    // 0x8002BB20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BB24: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002BB28: nop

L_8002BB2C:
    // 0x8002BB2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002BB30: nop

    // 0x8002BB34: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x8002BB38: nop

    // 0x8002BB3C: bc1f        L_8002BB50
    if (!c1cs) {
        // 0x8002BB40: nop
    
            goto L_8002BB50;
    }
    // 0x8002BB40: nop

    // 0x8002BB44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BB48: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002BB4C: nop

L_8002BB50:
    // 0x8002BB50: sub.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x8002BB54: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8002BB58: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002BB5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002BB60: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8002BB64: nop

    // 0x8002BB68: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8002BB6C: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
    // 0x8002BB70: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8002BB74: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8002BB78: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8002BB7C: nop

    // 0x8002BB80: sh          $t8, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r24;
    // 0x8002BB84: lh          $t9, 0xE($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XE);
    // 0x8002BB88: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8002BB8C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8002BB90: nop

    // 0x8002BB94: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002BB98: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8002BB9C: swc1        $f16, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f16.u32l;
    // 0x8002BBA0: lh          $t0, 0xE($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XE);
    // 0x8002BBA4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8002BBA8: sh          $t1, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r9;
    // 0x8002BBAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BBB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002BBB4: lwc1        $f18, 0x0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002BBB8: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8002BBBC: swc1        $f8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f8.u32l;
    // 0x8002BBC0: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002BBC4: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002BBC8: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8002BBCC: nop

    // 0x8002BBD0: sh          $t3, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r11;
    // 0x8002BBD4: lh          $t4, 0xE($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XE);
    // 0x8002BBD8: lh          $t5, 0xC($sp)
    ctx->r13 = MEM_H(ctx->r29, 0XC);
    // 0x8002BBDC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8002BBE0: sh          $t6, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r14;
    // 0x8002BBE4: lh          $t7, 0xC($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XC);
    // 0x8002BBE8: lwc1        $f16, 0x0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002BBEC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8002BBF0: nop

    // 0x8002BBF4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002BBF8: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8002BBFC: swc1        $f8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f8.u32l;
    // 0x8002BC00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002BC04: lwc1        $f4, 0x1D84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1D84);
    // 0x8002BC08: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002BC0C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002BC10: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8002BC14: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002BC18: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002BC1C: nop

    // 0x8002BC20: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8002BC24: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002BC28: nop

    // 0x8002BC2C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x8002BC30: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8002BC34: beq         $t9, $zero, L_8002BC88
    if (ctx->r25 == 0) {
        // 0x8002BC38: nop
    
            goto L_8002BC88;
    }
    // 0x8002BC38: nop

    // 0x8002BC3C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002BC40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002BC44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002BC48: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8002BC4C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002BC50: nop

    // 0x8002BC54: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002BC58: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002BC5C: nop

    // 0x8002BC60: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x8002BC64: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8002BC68: bne         $t9, $zero, L_8002BC80
    if (ctx->r25 != 0) {
        // 0x8002BC6C: nop
    
            goto L_8002BC80;
    }
    // 0x8002BC6C: nop

    // 0x8002BC70: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8002BC74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002BC78: b           L_8002BC98
    // 0x8002BC7C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8002BC98;
    // 0x8002BC7C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8002BC80:
    // 0x8002BC80: b           L_8002BC98
    // 0x8002BC84: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8002BC98;
    // 0x8002BC84: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_8002BC88:
    // 0x8002BC88: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8002BC8C: nop

    // 0x8002BC90: bltz        $t9, L_8002BC80
    if (SIGNED(ctx->r25) < 0) {
        // 0x8002BC94: nop
    
            goto L_8002BC80;
    }
    // 0x8002BC94: nop

L_8002BC98:
    // 0x8002BC98: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002BC9C: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x8002BCA0: nop

    // 0x8002BCA4: b           L_8002BCB4
    // 0x8002BCA8: lh          $v0, 0xE($sp)
    ctx->r2 = MEM_H(ctx->r29, 0XE);
        goto L_8002BCB4;
    // 0x8002BCA8: lh          $v0, 0xE($sp)
    ctx->r2 = MEM_H(ctx->r29, 0XE);
    // 0x8002BCAC: b           L_8002BCB4
    // 0x8002BCB0: nop

        goto L_8002BCB4;
    // 0x8002BCB0: nop

L_8002BCB4:
    // 0x8002BCB4: jr          $ra
    // 0x8002BCB8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002BCB8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void _chfantasydrillfield_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875F8: syscall     595
    recomp_syscall_handler(rdram, ctx, 0x800875F8);
    return;
    // 0x800875FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80016ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016ED0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80016ED4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80016ED8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80016EDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016EE0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80016EE4: bne         $a1, $at, L_80016F38
    if (ctx->r5 != ctx->r1) {
        // 0x80016EE8: sw          $a1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r5;
            goto L_80016F38;
    }
    // 0x80016EE8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80016EEC: lbu         $t7, 0x43($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X43);
    // 0x80016EF0: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80016EF4: addiu       $t9, $t9, -0x6060
    ctx->r25 = ADD32(ctx->r25, -0X6060);
    // 0x80016EF8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80016EFC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80016F00: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80016F04: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80016F08: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80016F0C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80016F10: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80016F14: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x80016F18: lh          $t0, 0x26C($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X26C);
    // 0x80016F1C: beql        $a1, $t0, L_80016F30
    if (ctx->r5 == ctx->r8) {
        // 0x80016F20: lw          $t1, 0x44($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X44);
            goto L_80016F30;
    }
    goto skip_0;
    // 0x80016F20: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80016F24: jal         0x80024E90
    // 0x80016F28: addiu       $a0, $s0, 0x1E0
    ctx->r4 = ADD32(ctx->r16, 0X1E0);
    func_80024E90(rdram, ctx);
        goto after_0;
    // 0x80016F28: addiu       $a0, $s0, 0x1E0
    ctx->r4 = ADD32(ctx->r16, 0X1E0);
    after_0:
    // 0x80016F2C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_80016F30:
    // 0x80016F30: b           L_8001705C
    // 0x80016F34: sh          $t1, 0x26C($s0)
    MEM_H(0X26C, ctx->r16) = ctx->r9;
        goto L_8001705C;
    // 0x80016F34: sh          $t1, 0x26C($s0)
    MEM_H(0X26C, ctx->r16) = ctx->r9;
L_80016F38:
    // 0x80016F38: lbu         $t2, 0x43($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X43);
    // 0x80016F3C: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80016F40: addiu       $t4, $t4, -0x6060
    ctx->r12 = ADD32(ctx->r12, -0X6060);
    // 0x80016F44: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80016F48: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80016F4C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80016F50: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80016F54: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80016F58: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80016F5C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80016F60: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x80016F64: lh          $t5, 0x26C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X26C);
    // 0x80016F68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80016F6C: beq         $t5, $at, L_80016F7C
    if (ctx->r13 == ctx->r1) {
        // 0x80016F70: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_80016F7C;
    }
    // 0x80016F70: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80016F74: jal         0x80016ED0
    // 0x80016F78: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80016ED0(rdram, ctx);
        goto after_1;
    // 0x80016F78: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
L_80016F7C:
    // 0x80016F7C: jal         0x800305B0
    // 0x80016F80: nop

    osGetTime_recomp(rdram, ctx);
        goto after_2;
    // 0x80016F80: nop

    after_2:
    // 0x80016F84: lw          $t7, 0x20C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20C);
    // 0x80016F88: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80016F8C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80016F90: beql        $t7, $zero, L_80016FB0
    if (ctx->r15 == 0) {
        // 0x80016F94: lw          $t9, 0x44($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X44);
            goto L_80016FB0;
    }
    goto skip_1;
    // 0x80016F94: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    skip_1:
L_80016F98:
    // 0x80016F98: jal         0x800305B0
    // 0x80016F9C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x80016F9C: nop

    after_3:
    // 0x80016FA0: lw          $t8, 0x20C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20C);
    // 0x80016FA4: bne         $t8, $zero, L_80016F98
    if (ctx->r24 != 0) {
        // 0x80016FA8: nop
    
            goto L_80016F98;
    }
    // 0x80016FA8: nop

    // 0x80016FAC: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_80016FB0:
    // 0x80016FB0: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x80016FB4: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80016FB8: sh          $t9, 0x26C($s0)
    MEM_H(0X26C, ctx->r16) = ctx->r25;
    // 0x80016FBC: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x80016FC0: lh          $a0, 0x26C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X26C);
    // 0x80016FC4: jal         0x80016DA0
    // 0x80016FC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016DA0(rdram, ctx);
        goto after_4;
    // 0x80016FC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80016FCC: lh          $a0, 0x26C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X26C);
    // 0x80016FD0: jal         0x800D674C
    // 0x80016FD4: addiu       $a0, $a0, 0x1DDD
    ctx->r4 = ADD32(ctx->r4, 0X1DDD);
    func_800D674C(rdram, ctx);
        goto after_5;
    // 0x80016FD4: addiu       $a0, $a0, 0x1DDD
    ctx->r4 = ADD32(ctx->r4, 0X1DDD);
    after_5:
    // 0x80016FD8: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    // 0x80016FDC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80016FE0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80016FE4: jal         0x80024EE0
    // 0x80016FE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80024EE0(rdram, ctx);
        goto after_6;
    // 0x80016FE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80016FEC: addiu       $a0, $s0, 0x1E0
    ctx->r4 = ADD32(ctx->r16, 0X1E0);
    // 0x80016FF0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80016FF4: jal         0x80025E80
    // 0x80016FF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80025E80(rdram, ctx);
        goto after_7;
    // 0x80016FF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_7:
    // 0x80016FFC: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x80017000: jal         0x80017850
    // 0x80017004: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80017850(rdram, ctx);
        goto after_8;
    // 0x80017004: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_8:
    // 0x80017008: lh          $a0, 0x26C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X26C);
    // 0x8001700C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80017010: beql        $a0, $at, L_80017034
    if (ctx->r4 == ctx->r1) {
        // 0x80017014: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80017034;
    }
    goto skip_2;
    // 0x80017014: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80017018: jal         0x800FCDB4
    // 0x8001701C: nop

    func_800FCDB4(rdram, ctx);
        goto after_9;
    // 0x8001701C: nop

    after_9:
    // 0x80017020: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80017024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80017028: jal         0x800178C4
    // 0x8001702C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800178C4(rdram, ctx);
        goto after_10;
    // 0x8001702C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_10:
    // 0x80017030: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80017034:
    // 0x80017034: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80017038: jal         0x80017D74
    // 0x8001703C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_80017D74(rdram, ctx);
        goto after_11;
    // 0x8001703C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_11:
    // 0x80017040: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80017044: jal         0x80025ED0
    // 0x80017048: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    func_80025ED0(rdram, ctx);
        goto after_12;
    // 0x80017048: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    after_12:
    // 0x8001704C: jal         0x80025F20
    // 0x80017050: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80025F20(rdram, ctx);
        goto after_13;
    // 0x80017050: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x80017054: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80017058: sb          $t6, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r14;
L_8001705C:
    // 0x8001705C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80017060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017064: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80017068: jr          $ra
    // 0x8001706C: nop

    return;
    // 0x8001706C: nop

;}
RECOMP_FUNC void func_8080241C_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080241C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80802420: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80802424: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80802428: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8080242C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80802430: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80802434: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80802438: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080243C: jal         0x80100094
    // 0x80802440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802444: jal         0x80088848
    // 0x80802448: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80802448: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_1:
    // 0x8080244C: addiu       $a0, $s4, 0x4
    ctx->r4 = ADD32(ctx->r20, 0X4);
    // 0x80802450: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4288) << 16);
    // 0x80802454: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80802458: addiu       $a1, $a1, 0x4288
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4288));
    // 0x8080245C: jal         0x800EE7F8
    // 0x80802460: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80802460: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_2:
    // 0x80802464: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x80802468: jal         0x800D0A9C
    // 0x8080246C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_3;
    // 0x8080246C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80802470: beq         $v0, $zero, L_808024A8
    if (ctx->r2 == 0) {
        // 0x80802474: lw          $t6, 0x40($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X40);
            goto L_808024A8;
    }
    // 0x80802474: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80802478: bnel        $t6, $zero, L_808024AC
    if (ctx->r14 != 0) {
        // 0x8080247C: addiu       $a0, $zero, 0x226
        ctx->r4 = ADD32(0, 0X226);
            goto L_808024AC;
    }
    goto skip_0;
    // 0x8080247C: addiu       $a0, $zero, 0x226
    ctx->r4 = ADD32(0, 0X226);
    skip_0:
    // 0x80802480: jal         0x800D395C
    // 0x80802484: nop

    func_800D395C(rdram, ctx);
        goto after_4;
    // 0x80802484: nop

    after_4:
    // 0x80802488: bnel        $v0, $zero, L_808024AC
    if (ctx->r2 != 0) {
        // 0x8080248C: addiu       $a0, $zero, 0x226
        ctx->r4 = ADD32(0, 0X226);
            goto L_808024AC;
    }
    goto skip_1;
    // 0x8080248C: addiu       $a0, $zero, 0x226
    ctx->r4 = ADD32(0, 0X226);
    skip_1:
    // 0x80802490: jal         0x800861A8
    // 0x80802494: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80802494: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80802498: jal         0x800FFAB0
    // 0x8080249C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x8080249C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x808024A0: b           L_808025FC
    // 0x808024A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808025FC;
    // 0x808024A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808024A8:
    // 0x808024A8: addiu       $a0, $zero, 0x226
    ctx->r4 = ADD32(0, 0X226);
L_808024AC:
    // 0x808024AC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808024B0: jal         0x800882C0
    // 0x808024B4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x808024B4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_7:
    // 0x808024B8: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x808024BC: sb          $v0, 0x91($s3)
    MEM_B(0X91, ctx->r19) = ctx->r2;
    // 0x808024C0: blez        $t7, L_808024F4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808024C4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808024F4;
    }
    // 0x808024C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808024C8: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x808024CC: addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
L_808024D0:
    // 0x808024D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808024D4: jal         0x800EE88C
    // 0x808024D8: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    func_800EE88C(rdram, ctx);
        goto after_8;
    // 0x808024D8: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    after_8:
    // 0x808024DC: lbu         $t8, 0x91($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X91);
    // 0x808024E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808024E4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x808024E8: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x808024EC: bne         $at, $zero, L_808024D0
    if (ctx->r1 != 0) {
        // 0x808024F0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_808024D0;
    }
    // 0x808024F0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_808024F4:
    // 0x808024F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808024F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808024FC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80802500: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802504: swc1        $f4, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->f4.u32l;
    // 0x80802508: sb          $s0, 0x84($s3)
    MEM_B(0X84, ctx->r19) = ctx->r16;
    // 0x8080250C: sb          $zero, 0x85($s3)
    MEM_B(0X85, ctx->r19) = 0;
    // 0x80802510: sb          $s0, 0x86($s3)
    MEM_B(0X86, ctx->r19) = ctx->r16;
    // 0x80802514: sb          $s0, 0x87($s3)
    MEM_B(0X87, ctx->r19) = ctx->r16;
    // 0x80802518: sb          $s0, 0x88($s3)
    MEM_B(0X88, ctx->r19) = ctx->r16;
    // 0x8080251C: sb          $s0, 0x89($s3)
    MEM_B(0X89, ctx->r19) = ctx->r16;
    // 0x80802520: sb          $s0, 0x8A($s3)
    MEM_B(0X8A, ctx->r19) = ctx->r16;
    // 0x80802524: sb          $s0, 0x8B($s3)
    MEM_B(0X8B, ctx->r19) = ctx->r16;
    // 0x80802528: sb          $s0, 0x8C($s3)
    MEM_B(0X8C, ctx->r19) = ctx->r16;
    // 0x8080252C: sb          $s0, 0x8D($s3)
    MEM_B(0X8D, ctx->r19) = ctx->r16;
    // 0x80802530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802534: jal         0x800897C0
    // 0x80802538: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x80802538: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_9:
    // 0x8080253C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80802540: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802544: bne         $t9, $zero, L_80802554
    if (ctx->r25 != 0) {
        // 0x80802548: nop
    
            goto L_80802554;
    }
    // 0x80802548: nop

    // 0x8080254C: jal         0x80108B04
    // 0x80802550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_10;
    // 0x80802550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
L_80802554:
    // 0x80802554: jal         0x800DA524
    // 0x80802558: addiu       $a0, $zero, 0xA32
    ctx->r4 = ADD32(0, 0XA32);
    func_800DA524(rdram, ctx);
        goto after_11;
    // 0x80802558: addiu       $a0, $zero, 0xA32
    ctx->r4 = ADD32(0, 0XA32);
    after_11:
    // 0x8080255C: jal         0x800DA524
    // 0x80802560: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    func_800DA524(rdram, ctx);
        goto after_12;
    // 0x80802560: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    after_12:
    // 0x80802564: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80802568: sb          $t0, 0x93($s3)
    MEM_B(0X93, ctx->r19) = ctx->r8;
    // 0x8080256C: sb          $zero, 0x92($s3)
    MEM_B(0X92, ctx->r19) = 0;
    // 0x80802570: jal         0x800DA298
    // 0x80802574: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80802574: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    after_13:
    // 0x80802578: lbu         $t4, 0x65($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X65);
    // 0x8080257C: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x80802580: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x80802584: andi        $t5, $t4, 0xFFF7
    ctx->r13 = ctx->r12 & 0XFFF7;
    // 0x80802588: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x8080258C: sb          $t6, 0x65($s4)
    MEM_B(0X65, ctx->r20) = ctx->r14;
    // 0x80802590: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80802594: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802598: beq         $t7, $zero, L_808025B0
    if (ctx->r15 == 0) {
        // 0x8080259C: nop
    
            goto L_808025B0;
    }
    // 0x8080259C: nop

    // 0x808025A0: jal         0x808007C4
    // 0x808025A4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_14;
    // 0x808025A4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_14:
    // 0x808025A8: b           L_808025FC
    // 0x808025AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808025FC;
    // 0x808025AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808025B0:
    // 0x808025B0: jal         0x800DA298
    // 0x808025B4: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x808025B4: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    after_15:
    // 0x808025B8: beq         $v0, $zero, L_808025F0
    if (ctx->r2 == 0) {
        // 0x808025BC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_808025F0;
    }
    // 0x808025BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808025C0: jal         0x80800774
    // 0x808025C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80800774_chevilmumbo(rdram, ctx);
        goto after_16;
    // 0x808025C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_16:
    // 0x808025C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808025CC: jal         0x808007C4
    // 0x808025D0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_17;
    // 0x808025D0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_17:
    // 0x808025D4: sb          $s0, 0x96($s3)
    MEM_B(0X96, ctx->r19) = ctx->r16;
    // 0x808025D8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X427C) << 16);
    // 0x808025DC: addiu       $a1, $a1, 0x427C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X427C));
    // 0x808025E0: jal         0x800EE7F8
    // 0x808025E4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_18;
    // 0x808025E4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_18:
    // 0x808025E8: b           L_808025FC
    // 0x808025EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808025FC;
    // 0x808025EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808025F0:
    // 0x808025F0: jal         0x808007C4
    // 0x808025F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_19;
    // 0x808025F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x808025F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808025FC:
    // 0x808025FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802600: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80802604: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80802608: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080260C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80802610: jr          $ra
    // 0x80802614: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80802614: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void bskazmove_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800298: jal         0x800832E8
    // 0x8080029C: nop

    _bskaz_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080029C: nop

    after_0:
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002A8: jr          $ra
    // 0x808002AC: nop

    return;
    // 0x808002AC: nop

;}
RECOMP_FUNC void _bafly_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BF0: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084BF0);
    return;
    // 0x80084BF4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800078_chbounce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080007C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800080: jal         0x800DC0C0
    // 0x80800084: nop

    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80800084: nop

    after_0:
    // 0x80800088: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8080008C: jal         0x80088238
    // 0x80800090: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    _gclevel_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800090: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x80800094: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800098: jal         0x80088238
    // 0x8080009C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    _gclevel_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080009C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_2:
    // 0x808000A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808000A4: jal         0x800D3E40
    // 0x808000A8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800D3E40(rdram, ctx);
        goto after_3;
    // 0x808000A8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_3:
    // 0x808000AC: beq         $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x808000B0: nop
    
            goto L_808000BC;
    }
    // 0x808000B0: nop

    // 0x808000B4: b           L_80800180
    // 0x808000B8: addiu       $v0, $zero, 0x229
    ctx->r2 = ADD32(0, 0X229);
        goto L_80800180;
    // 0x808000B8: addiu       $v0, $zero, 0x229
    ctx->r2 = ADD32(0, 0X229);
L_808000BC:
    // 0x808000BC: jal         0x800EA068
    // 0x808000C0: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    func_800EA068(rdram, ctx);
        goto after_4;
    // 0x808000C0: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    after_4:
    // 0x808000C4: beql        $v0, $zero, L_808000D8
    if (ctx->r2 == 0) {
        // 0x808000C8: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_808000D8;
    }
    goto skip_0;
    // 0x808000C8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x808000CC: b           L_80800180
    // 0x808000D0: addiu       $v0, $zero, 0x229
    ctx->r2 = ADD32(0, 0X229);
        goto L_80800180;
    // 0x808000D0: addiu       $v0, $zero, 0x229
    ctx->r2 = ADD32(0, 0X229);
    // 0x808000D4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_808000D8:
    // 0x808000D8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808000DC: bne         $v0, $zero, L_808000F4
    if (ctx->r2 != 0) {
        // 0x808000E0: nop
    
            goto L_808000F4;
    }
    // 0x808000E0: nop

    // 0x808000E4: bne         $t6, $zero, L_808000F4
    if (ctx->r14 != 0) {
        // 0x808000E8: nop
    
            goto L_808000F4;
    }
    // 0x808000E8: nop

    // 0x808000EC: b           L_80800180
    // 0x808000F0: addiu       $v0, $zero, 0x229
    ctx->r2 = ADD32(0, 0X229);
        goto L_80800180;
    // 0x808000F0: addiu       $v0, $zero, 0x229
    ctx->r2 = ADD32(0, 0X229);
L_808000F4:
    // 0x808000F4: beq         $v0, $zero, L_80800134
    if (ctx->r2 == 0) {
        // 0x808000F8: addiu       $a0, $zero, 0x31
        ctx->r4 = ADD32(0, 0X31);
            goto L_80800134;
    }
    // 0x808000F8: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x808000FC: jal         0x800DA9E4
    // 0x80800100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_5;
    // 0x80800100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800104: bne         $v0, $zero, L_80800114
    if (ctx->r2 != 0) {
        // 0x80800108: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80800114;
    }
    // 0x80800108: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080010C: b           L_80800180
    // 0x80800110: addiu       $v0, $zero, 0x197
    ctx->r2 = ADD32(0, 0X197);
        goto L_80800180;
    // 0x80800110: addiu       $v0, $zero, 0x197
    ctx->r2 = ADD32(0, 0X197);
L_80800114:
    // 0x80800114: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFB0) << 16);
    // 0x80800118: lwc1        $f6, 0xFB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0XFB0));
    // 0x8080011C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800120: nop

    // 0x80800124: bc1fl       L_80800138
    if (!c1cs) {
        // 0x80800128: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80800138;
    }
    goto skip_1;
    // 0x80800128: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080012C: b           L_80800180
    // 0x80800130: addiu       $v0, $zero, 0x197
    ctx->r2 = ADD32(0, 0X197);
        goto L_80800180;
    // 0x80800130: addiu       $v0, $zero, 0x197
    ctx->r2 = ADD32(0, 0X197);
L_80800134:
    // 0x80800134: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_80800138:
    // 0x80800138: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x8080013C: beql        $t7, $zero, L_80800180
    if (ctx->r15 == 0) {
        // 0x80800140: addiu       $v0, $zero, 0x229
        ctx->r2 = ADD32(0, 0X229);
            goto L_80800180;
    }
    goto skip_2;
    // 0x80800140: addiu       $v0, $zero, 0x229
    ctx->r2 = ADD32(0, 0X229);
    skip_2:
    // 0x80800144: jal         0x800DA9E4
    // 0x80800148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_6;
    // 0x80800148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080014C: bne         $v0, $zero, L_8080015C
    if (ctx->r2 != 0) {
        // 0x80800150: lwc1        $f8, 0x24($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8080015C;
    }
    // 0x80800150: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800154: b           L_80800180
    // 0x80800158: addiu       $v0, $zero, 0x196
    ctx->r2 = ADD32(0, 0X196);
        goto L_80800180;
    // 0x80800158: addiu       $v0, $zero, 0x196
    ctx->r2 = ADD32(0, 0X196);
L_8080015C:
    // 0x8080015C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFB4) << 16);
    // 0x80800160: lwc1        $f10, 0xFB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0XFB4));
    // 0x80800164: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800168: nop

    // 0x8080016C: bc1fl       L_80800180
    if (!c1cs) {
        // 0x80800170: addiu       $v0, $zero, 0x229
        ctx->r2 = ADD32(0, 0X229);
            goto L_80800180;
    }
    goto skip_3;
    // 0x80800170: addiu       $v0, $zero, 0x229
    ctx->r2 = ADD32(0, 0X229);
    skip_3:
    // 0x80800174: b           L_80800180
    // 0x80800178: addiu       $v0, $zero, 0x196
    ctx->r2 = ADD32(0, 0X196);
        goto L_80800180;
    // 0x80800178: addiu       $v0, $zero, 0x196
    ctx->r2 = ADD32(0, 0X196);
    // 0x8080017C: addiu       $v0, $zero, 0x229
    ctx->r2 = ADD32(0, 0X229);
L_80800180:
    // 0x80800180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800184: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void func_80114CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114CD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114CDC: jal         0x8001BAFC
    // 0x80114CE0: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x80114CE0: nop

    after_0:
    // 0x80114CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114CEC: jr          $ra
    // 0x80114CF0: nop

    return;
    // 0x80114CF0: nop

;}
RECOMP_FUNC void func_808001CC_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808001D0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808001D4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x808001D8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808001DC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x808001E0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x808001E4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x808001E8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x808001EC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x808001F0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808001F4: jal         0x80100094
    // 0x808001F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001FC: jal         0x800D8FF8
    // 0x80800200: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800200: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_1:
    // 0x80800204: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800208: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2220, 0XCA0) << 16);
    // 0x8080020C: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800210: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800214: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800218: lui         $a3, 0x3D08
    ctx->r7 = S32(0X3D08 << 16);
    // 0x8080021C: ori         $a3, $a3, 0x6595
    ctx->r7 = ctx->r7 | 0X6595;
    // 0x80800220: swc1        $f6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f6.u32l;
    // 0x80800224: lwc1        $f8, 0xCA0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2220, 0XCA0));
    // 0x80800228: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8080022C: jal         0x800F10B4
    // 0x80800230: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800230: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800234: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x80800238: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8080023C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800240: jal         0x8008A418
    // 0x80800244: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _suegg_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800244: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80800248: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8080024C: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800250: addiu       $s0, $s3, 0x4
    ctx->r16 = ADD32(ctx->r19, 0X4);
    // 0x80800254: addiu       $s2, $sp, 0x64
    ctx->r18 = ADD32(ctx->r29, 0X64);
    // 0x80800258: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x8080025C: nop

    // 0x80800260: bc1fl       L_808002A4
    if (!c1cs) {
        // 0x80800264: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808002A4;
    }
    goto skip_0;
    // 0x80800264: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80800268: add.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f22.fl;
L_8080026C:
    // 0x8080026C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800270: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800274: jal         0x800EE7F8
    // 0x80800278: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800278: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
    after_4:
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800284: jal         0x80088A88
    // 0x80800288: lw          $a2, 0x38($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X38);
    _fxegg_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800288: lw          $a2, 0x38($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X38);
    after_5:
    // 0x8080028C: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800290: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80800294: nop

    // 0x80800298: bc1tl       L_8080026C
    if (c1cs) {
        // 0x8080029C: add.s       $f10, $f0, $f22
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f22.fl;
            goto L_8080026C;
    }
    goto skip_1;
    // 0x8080029C: add.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f22.fl;
    skip_1:
    // 0x808002A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808002A4:
    // 0x808002A4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808002A8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808002AC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808002B0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x808002B4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x808002B8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x808002BC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x808002C0: jr          $ra
    // 0x808002C4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x808002C4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80804110_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804118: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x8080411C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80804120: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80804124: bne         $t6, $at, L_80804134
    if (ctx->r14 != ctx->r1) {
        // 0x80804128: nop
    
            goto L_80804134;
    }
    // 0x80804128: nop

    // 0x8080412C: b           L_80804134
    // 0x80804130: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
        goto L_80804134;
    // 0x80804130: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
L_80804134:
    // 0x80804134: jal         0x80804170
    // 0x80804138: nop

    func_80804170_chquiz(rdram, ctx);
        goto after_0;
    // 0x80804138: nop

    after_0:
    // 0x8080413C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804144: jr          $ra
    // 0x80804148: nop

    return;
    // 0x80804148: nop

;}
RECOMP_FUNC void _chhoopswoop_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085EF8: syscall     259
    recomp_syscall_handler(rdram, ctx, 0x80085EF8);
    return;
    // 0x80085EFC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808006A0_chflowerbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808006A4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808006A8: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x808006AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808006B0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808006B4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808006B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006BC: jal         0x80103DFC
    // 0x808006C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80103DFC(rdram, ctx);
        goto after_0;
    // 0x808006C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x808006C4: jal         0x800B53A4
    // 0x808006C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x808006C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x808006CC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1388, 0XCCC) << 16);
    // 0x808006D0: addiu       $t6, $t6, 0xCCC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1388, 0XCCC));
    // 0x808006D4: lw          $a3, 0x38($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X38);
    // 0x808006D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808006E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808006E8: jal         0x800BABB8
    // 0x808006EC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808006EC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x808006F0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1388, 0XD18) << 16);
    // 0x808006F4: addiu       $t7, $t7, 0xD18
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1388, 0XD18));
    // 0x808006F8: lw          $a3, 0x38($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X38);
    // 0x808006FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800708: jal         0x800BABB8
    // 0x8080070C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x8080070C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_3:
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800714: jal         0x800BA22C
    // 0x80800718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_4;
    // 0x80800718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080071C: jal         0x800B53A4
    // 0x80800720: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800B53A4(rdram, ctx);
        goto after_5;
    // 0x80800720: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80800724: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1388, 0XCCC) << 16);
    // 0x80800728: addiu       $t8, $t8, 0xCCC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1388, 0XCCC));
    // 0x8080072C: lw          $a3, 0x38($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X38);
    // 0x80800730: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800734: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800738: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080073C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800740: jal         0x800BABB8
    // 0x80800744: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800744: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_6:
    // 0x80800748: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1388, 0XCF0) << 16);
    // 0x8080074C: addiu       $t9, $t9, 0xCF0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1388, 0XCF0));
    // 0x80800750: lw          $a3, 0x38($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X38);
    // 0x80800754: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080075C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800760: jal         0x800BABB8
    // 0x80800764: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800764: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_7:
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080076C: jal         0x800BA22C
    // 0x80800770: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BA22C(rdram, ctx);
        goto after_8;
    // 0x80800770: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800774: jal         0x800B53A4
    // 0x80800778: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800B53A4(rdram, ctx);
        goto after_9;
    // 0x80800778: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_9:
    // 0x8080077C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1388, 0XCCC) << 16);
    // 0x80800780: addiu       $t0, $t0, 0xCCC
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1388, 0XCCC));
    // 0x80800784: lw          $a3, 0x38($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X38);
    // 0x80800788: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080078C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800790: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800794: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800798: jal         0x800BABB8
    // 0x8080079C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800BABB8(rdram, ctx);
        goto after_10;
    // 0x8080079C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_10:
    // 0x808007A0: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1388, 0XD04) << 16);
    // 0x808007A4: addiu       $t1, $t1, 0xD04
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1388, 0XD04));
    // 0x808007A8: lw          $a3, 0x38($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X38);
    // 0x808007AC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808007B8: jal         0x800BABB8
    // 0x808007BC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800BABB8(rdram, ctx);
        goto after_11;
    // 0x808007BC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_11:
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C4: jal         0x800BA22C
    // 0x808007C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BA22C(rdram, ctx);
        goto after_12;
    // 0x808007C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x808007CC: lbu         $t2, 0x65($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X65);
    // 0x808007D0: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x808007D4: sb          $t3, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r11;
    // 0x808007D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808007DC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808007E0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808007E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007E8: jr          $ra
    // 0x808007EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808007EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
