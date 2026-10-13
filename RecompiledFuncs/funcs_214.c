#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800D3C_susplinet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D3C: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80800D40: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800D44: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800D48: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800D4C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800D50: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800D54: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800D58: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800D5C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800D60: lh          $t6, 0x34($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X34);
    // 0x80800D64: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x80800D68: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800D6C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800D70: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80800D74: lh          $t8, 0x30($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X30);
    // 0x80800D78: lh          $t9, 0x4E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4E);
    // 0x80800D7C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80800D80: addu        $s1, $a0, $t8
    ctx->r17 = ADD32(ctx->r4, ctx->r24);
    // 0x80800D84: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80800D88: addu        $t1, $s1, $t0
    ctx->r9 = ADD32(ctx->r17, ctx->r8);
    // 0x80800D8C: lh          $t2, -0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, -0X2);
    // 0x80800D90: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
    // 0x80800D94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800D98: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80800D9C: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x80800DA0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800DA4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80800DA8: nop

    // 0x80800DAC: bc1fl       L_80800DC0
    if (!c1cs) {
        // 0x80800DB0: lh          $t3, 0x0($s1)
        ctx->r11 = MEM_H(ctx->r17, 0X0);
            goto L_80800DC0;
    }
    goto skip_0;
    // 0x80800DB0: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    skip_0:
    // 0x80800DB4: b           L_80800DE0
    // 0x80800DB8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
        goto L_80800DE0;
    // 0x80800DB8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800DBC: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
L_80800DC0:
    // 0x80800DC0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80800DC4: nop

    // 0x80800DC8: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800DCC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80800DD0: nop

    // 0x80800DD4: bc1fl       L_80800DE4
    if (!c1cs) {
        // 0x80800DD8: lbu         $t4, 0x51($s3)
        ctx->r12 = MEM_BU(ctx->r19, 0X51);
            goto L_80800DE4;
    }
    goto skip_1;
    // 0x80800DD8: lbu         $t4, 0x51($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X51);
    skip_1:
    // 0x80800DDC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_80800DE0:
    // 0x80800DE0: lbu         $t4, 0x51($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X51);
L_80800DE4:
    // 0x80800DE4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800DE8: blezl       $t4, L_80800E20
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80800DEC: lbu         $t8, 0x52($s3)
        ctx->r24 = MEM_BU(ctx->r19, 0X52);
            goto L_80800E20;
    }
    goto skip_2;
    // 0x80800DEC: lbu         $t8, 0x52($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X52);
    skip_2:
    // 0x80800DF0: lh          $t5, 0x36($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X36);
L_80800DF4:
    // 0x80800DF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800DF8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800DFC: addu        $t6, $t5, $s3
    ctx->r14 = ADD32(ctx->r13, ctx->r19);
    // 0x80800E00: sw          $t6, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r14;
    // 0x80800E04: lbu         $t7, 0x51($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X51);
    // 0x80800E08: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80800E0C: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800E10: bnel        $at, $zero, L_80800DF4
    if (ctx->r1 != 0) {
        // 0x80800E14: lh          $t5, 0x36($v0)
        ctx->r13 = MEM_H(ctx->r2, 0X36);
            goto L_80800DF4;
    }
    goto skip_3;
    // 0x80800E14: lh          $t5, 0x36($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X36);
    skip_3:
    // 0x80800E18: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800E1C: lbu         $t8, 0x52($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X52);
L_80800E20:
    // 0x80800E20: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80800E24: addiu       $s0, $sp, 0xBC
    ctx->r16 = ADD32(ctx->r29, 0XBC);
    // 0x80800E28: blezl       $t8, L_80800E5C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80800E2C: lh          $t2, 0x4E($s3)
        ctx->r10 = MEM_H(ctx->r19, 0X4E);
            goto L_80800E5C;
    }
    goto skip_4;
    // 0x80800E2C: lh          $t2, 0x4E($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X4E);
    skip_4:
    // 0x80800E30: lh          $t9, 0x3E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X3E);
L_80800E34:
    // 0x80800E34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800E38: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80800E3C: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x80800E40: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80800E44: lbu         $t1, 0x52($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X52);
    // 0x80800E48: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800E4C: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800E50: bnel        $at, $zero, L_80800E34
    if (ctx->r1 != 0) {
        // 0x80800E54: lh          $t9, 0x3E($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X3E);
            goto L_80800E34;
    }
    goto skip_5;
    // 0x80800E54: lh          $t9, 0x3E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X3E);
    skip_5:
    // 0x80800E58: lh          $t2, 0x4E($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X4E);
L_80800E5C:
    // 0x80800E5C: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80800E60: bnel        $at, $zero, L_808010C4
    if (ctx->r1 != 0) {
        // 0x80800E64: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808010C4;
    }
    goto skip_6;
    // 0x80800E64: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_6:
    // 0x80800E68: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800E6C: jal         0x80800620
    // 0x80800E70: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_80800620_susplinet(rdram, ctx);
        goto after_0;
    // 0x80800E70: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_0:
    // 0x80800E74: lh          $t4, 0xB2($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB2);
    // 0x80800E78: lh          $t3, 0xB0($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XB0);
    // 0x80800E7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800E80: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80800E84: beq         $t3, $t4, L_80800ECC
    if (ctx->r11 == ctx->r12) {
        // 0x80800E88: addu        $t6, $s1, $t5
        ctx->r14 = ADD32(ctx->r17, ctx->r13);
            goto L_80800ECC;
    }
    // 0x80800E88: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x80800E8C: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x80800E90: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80800E94: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80800E98: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x80800E9C: bnel        $t9, $v0, L_80800ED0
    if (ctx->r25 != ctx->r2) {
        // 0x80800EA0: sb          $zero, 0x53($s3)
        MEM_B(0X53, ctx->r19) = 0;
            goto L_80800ED0;
    }
    goto skip_7;
    // 0x80800EA0: sb          $zero, 0x53($s3)
    MEM_B(0X53, ctx->r19) = 0;
    skip_7:
    // 0x80800EA4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80800EA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800EAC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800EB0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800EB4: jal         0x80800214
    // 0x80800EB8: nop

    susplinet_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800EB8: nop

    after_1:
    // 0x80800EBC: beq         $v0, $zero, L_80800ECC
    if (ctx->r2 == 0) {
        // 0x80800EC0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80800ECC;
    }
    // 0x80800EC0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800EC4: b           L_80800ED0
    // 0x80800EC8: sb          $t0, 0x53($s3)
    MEM_B(0X53, ctx->r19) = ctx->r8;
        goto L_80800ED0;
    // 0x80800EC8: sb          $t0, 0x53($s3)
    MEM_B(0X53, ctx->r19) = ctx->r8;
L_80800ECC:
    // 0x80800ECC: sb          $zero, 0x53($s3)
    MEM_B(0X53, ctx->r19) = 0;
L_80800ED0:
    // 0x80800ED0: lh          $t1, 0xB0($sp)
    ctx->r9 = MEM_H(ctx->r29, 0XB0);
    // 0x80800ED4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800ED8: lh          $t2, 0xB2($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XB2);
    // 0x80800EDC: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800EE0: lh          $t4, 0xB4($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB4);
    // 0x80800EE4: lh          $t5, 0xB6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0XB6);
    // 0x80800EE8: lbu         $t6, 0x51($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X51);
    // 0x80800EEC: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
    // 0x80800EF0: or          $s4, $s3, $zero
    ctx->r20 = ctx->r19 | 0;
    // 0x80800EF4: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
    // 0x80800EF8: mflo        $v1
    ctx->r3 = lo;
    // 0x80800EFC: nop

    // 0x80800F00: nop

    // 0x80800F04: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800F08: mflo        $a0
    ctx->r4 = lo;
    // 0x80800F0C: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80800F10: nop

    // 0x80800F14: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800F18: mflo        $a1
    ctx->r5 = lo;
    // 0x80800F1C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800F20: nop

    // 0x80800F24: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800F28: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80800F2C: mflo        $a2
    ctx->r6 = lo;
    // 0x80800F30: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80800F34: blezl       $t6, L_80801030
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800F38: lbu         $t9, 0x52($s3)
        ctx->r25 = MEM_BU(ctx->r19, 0X52);
            goto L_80801030;
    }
    goto skip_8;
    // 0x80800F38: lbu         $t9, 0x52($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X52);
    skip_8:
    // 0x80800F3C: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x80800F40: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80800F44: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80800F48: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_80800F4C:
    // 0x80800F4C: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80800F50: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800F54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F58: jal         0x800EE7F8
    // 0x80800F5C: addu        $a1, $t9, $v0
    ctx->r5 = ADD32(ctx->r25, ctx->r2);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800F5C: addu        $a1, $t9, $v0
    ctx->r5 = ADD32(ctx->r25, ctx->r2);
    after_2:
    // 0x80800F60: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800F64: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80800F68: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80800F6C: jal         0x800EE7F8
    // 0x80800F70: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800F70: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_3:
    // 0x80800F74: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80800F78: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80800F7C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80800F80: jal         0x800EE7F8
    // 0x80800F84: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800F84: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    after_4:
    // 0x80800F88: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80800F8C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80800F90: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x80800F94: jal         0x800EE7F8
    // 0x80800F98: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800F98: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_5:
    // 0x80800F9C: bne         $s2, $zero, L_80800FC8
    if (ctx->r18 != 0) {
        // 0x80800FA0: lw          $t3, 0xDC($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XDC);
            goto L_80800FC8;
    }
    // 0x80800FA0: lw          $t3, 0xDC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XDC);
    // 0x80800FA4: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x80800FA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800FAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800FB0: beq         $t7, $at, L_80800FC8
    if (ctx->r15 == ctx->r1) {
        // 0x80800FB4: addiu       $a2, $sp, 0xB0
        ctx->r6 = ADD32(ctx->r29, 0XB0);
            goto L_80800FC8;
    }
    // 0x80800FB4: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x80800FB8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80800FBC: jal         0x808007D0
    // 0x80800FC0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_808007D0_susplinet(rdram, ctx);
        goto after_6;
    // 0x80800FC0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_6:
    // 0x80800FC4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80800FC8:
    // 0x80800FC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800FCC: jal         0x808000FC
    // 0x80800FD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_808000FC_susplinet(rdram, ctx);
        goto after_7;
    // 0x80800FD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80800FD4: beq         $v0, $zero, L_80800FE4
    if (ctx->r2 == 0) {
        // 0x80800FD8: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80800FE4;
    }
    // 0x80800FD8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800FDC: jal         0x800F0EF0
    // 0x80800FE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F0EF0(rdram, ctx);
        goto after_8;
    // 0x80800FE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
L_80800FE4:
    // 0x80800FE4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800FE8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800FEC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800FF0: jal         0x800890F8
    // 0x80800FF4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    _mlspline_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80800FF4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_9:
    // 0x80800FF8: bne         $s2, $zero, L_80801010
    if (ctx->r18 != 0) {
        // 0x80800FFC: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80801010;
    }
    // 0x80800FFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80801000: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80801004: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801008: jal         0x80089118
    // 0x8080100C: addiu       $a3, $s4, 0x18
    ctx->r7 = ADD32(ctx->r20, 0X18);
    _mlspline_entrypoint_8(rdram, ctx);
        goto after_10;
    // 0x8080100C: addiu       $a3, $s4, 0x18
    ctx->r7 = ADD32(ctx->r20, 0X18);
    after_10:
L_80801010:
    // 0x80801010: lbu         $t8, 0x51($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X51);
    // 0x80801014: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80801018: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080101C: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80801020: bne         $at, $zero, L_80800F4C
    if (ctx->r1 != 0) {
        // 0x80801024: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_80800F4C;
    }
    // 0x80801024: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80801028: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8080102C: lbu         $t9, 0x52($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X52);
L_80801030:
    // 0x80801030: addiu       $s0, $sp, 0xBC
    ctx->r16 = ADD32(ctx->r29, 0XBC);
    // 0x80801034: addiu       $s1, $s3, 0x24
    ctx->r17 = ADD32(ctx->r19, 0X24);
    // 0x80801038: blez        $t9, L_808010C0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8080103C: addiu       $s4, $sp, 0x9C
        ctx->r20 = ADD32(ctx->r29, 0X9C);
            goto L_808010C0;
    }
    // 0x8080103C: addiu       $s4, $sp, 0x9C
    ctx->r20 = ADD32(ctx->r29, 0X9C);
L_80801040:
    // 0x80801040: lh          $t0, 0xB0($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XB0);
    // 0x80801044: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80801048: lh          $t4, 0xB2($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB2);
    // 0x8080104C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80801050: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80801054: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80801058: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8080105C: lh          $t3, 0xB4($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XB4);
    // 0x80801060: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80801064: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x80801068: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8080106C: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80801070: lh          $t9, 0xB6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XB6);
    // 0x80801074: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80801078: swc1        $f16, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f16.u32l;
    // 0x8080107C: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80801080: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80801084: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80801088: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x8080108C: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80801090: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80801094: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80801098: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8080109C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x808010A0: jal         0x80089120
    // 0x808010A4: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    _mlspline_entrypoint_9(rdram, ctx);
        goto after_11;
    // 0x808010A4: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x808010A8: lbu         $t2, 0x52($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X52);
    // 0x808010AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808010B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808010B4: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x808010B8: bne         $at, $zero, L_80801040
    if (ctx->r1 != 0) {
        // 0x808010BC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80801040;
    }
    // 0x808010BC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_808010C0:
    // 0x808010C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808010C4:
    // 0x808010C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808010C8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808010CC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808010D0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808010D4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808010D8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808010DC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808010E0: jr          $ra
    // 0x808010E4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x808010E4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_80800C08_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800C14: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800C18: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800C1C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800C20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C24: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800C28: beq         $t6, $zero, L_80800C4C
    if (ctx->r14 == 0) {
        // 0x80800C2C: addiu       $a1, $zero, 0x18
        ctx->r5 = ADD32(0, 0X18);
            goto L_80800C4C;
    }
    // 0x80800C2C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80800C30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C34: beq         $t6, $at, L_80800C5C
    if (ctx->r14 == ctx->r1) {
        // 0x80800C38: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C5C;
    }
    // 0x80800C38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C3C: beql        $t6, $at, L_80800C8C
    if (ctx->r14 == ctx->r1) {
        // 0x80800C40: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800C8C;
    }
    goto skip_0;
    // 0x80800C40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800C44: b           L_80800C98
    // 0x80800C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C98;
    // 0x80800C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C4C:
    // 0x80800C4C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800C50: jal         0x800856B0
    // 0x80800C54: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800C54: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800C58: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80800C5C:
    // 0x80800C5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800C60: jal         0x800856E0
    // 0x80800C64: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800C64: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800C68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C6C: lhu         $t7, 0x6E($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800C70: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800C74: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80800C78: jal         0x80800A84
    // 0x80800C7C: sh          $t9, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r25;
    func_80800A84_chbottlesfamily(rdram, ctx);
        goto after_2;
    // 0x80800C7C: sh          $t9, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r25;
    after_2:
    // 0x80800C80: jal         0x800880B8
    // 0x80800C84: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800C84: nop

    after_3:
    // 0x80800C88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80800C8C:
    // 0x80800C8C: jal         0x800856D8
    // 0x80800C90: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800C90: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C98:
    // 0x80800C98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C9C: jr          $ra
    // 0x80800CA0: nop

    return;
    // 0x80800CA0: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080144C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801450: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(104, 0X14E0) << 16);
    // 0x80801454: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801458: jr          $ra
    // 0x8080145C: lw          $v0, 0x14E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14E0));
    return;
    // 0x8080145C: lw          $v0, 0x14E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14E0));
;}
RECOMP_FUNC void func_808008D8_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008E8: jal         0x8009E74C
    // 0x808008EC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x808008EC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x808008F0: bne         $v0, $zero, L_8080099C
    if (ctx->r2 != 0) {
        // 0x808008F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080099C;
    }
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808008FC: jal         0x800947EC
    // 0x80800900: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_1;
    // 0x80800900: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800908: jal         0x800961AC
    // 0x8080090C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_2;
    // 0x8080090C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800910: jal         0x8009BC34
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BC34(rdram, ctx);
        goto after_3;
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080091C: jal         0x8009BF5C
    // 0x80800920: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_4;
    // 0x80800920: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800928: jal         0x8009C4CC
    // 0x8080092C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_5;
    // 0x8080092C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800930: jal         0x8009C000
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C000(rdram, ctx);
        goto after_6;
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800938: jal         0x8009C570
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_resetAngularVelocity(rdram, ctx);
        goto after_7;
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800940: jal         0x8009F1E0
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_8;
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800948: jal         0x80095A40
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_9;
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800954: jal         0x80095964
    // 0x80800958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80095964(rdram, ctx);
        goto after_10;
    // 0x80800958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800960: jal         0x80093360
    // 0x80800964: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_11;
    // 0x80800964: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x80800968: jal         0x800851C8
    // 0x8080096C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basub_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x8080096C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800974: jal         0x800910BC
    // 0x80800978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800910BC(rdram, ctx);
        goto after_13;
    // 0x80800978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800980: jal         0x80084D08
    // 0x80800984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafpctrl_entrypoint_18(rdram, ctx);
        goto after_14;
    // 0x80800984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800988: jal         0x8009E474
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_15;
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800994: jal         0x80092864
    // 0x80800998: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_16;
    // 0x80800998: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_16:
L_8080099C:
    // 0x8080099C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009A8: jr          $ra
    // 0x808009AC: nop

    return;
    // 0x808009AC: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80800164: jr          $ra
    // 0x80800168: lbu         $v0, -0x4BF7($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X4BF7);
    return;
    // 0x80800168: lbu         $v0, -0x4BF7($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X4BF7);
;}
RECOMP_FUNC void func_808003DC_chfactorytoxicpools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003E4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808003E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003F0: beq         $a1, $at, L_8080041C
    if (ctx->r5 == ctx->r1) {
        // 0x808003F4: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8080041C;
    }
    // 0x808003F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808003F8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808003FC: beq         $a1, $at, L_80800468
    if (ctx->r5 == ctx->r1) {
        // 0x80800400: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800468;
    }
    // 0x80800400: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800404: bne         $a1, $at, L_80800484
    if (ctx->r5 != ctx->r1) {
        // 0x80800408: nop
    
            goto L_80800484;
    }
    // 0x80800408: nop

    // 0x8080040C: jal         0x808004A4
    // 0x80800410: nop

    func_808004A4_chfactorytoxicpools(rdram, ctx);
        goto after_0;
    // 0x80800410: nop

    after_0:
    // 0x80800414: b           L_80800490
    // 0x80800418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800490;
    // 0x80800418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080041C:
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: jal         0x80100094
    // 0x80800424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800428: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: jal         0x80103110
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800438: jal         0x8010A570
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800440: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800444: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800448: jal         0x800F54E4
    // 0x8080044C: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x8080044C: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    after_4:
    // 0x80800450: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800454: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800458: jal         0x800F8300
    // 0x8080045C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800F8300(rdram, ctx);
        goto after_5;
    // 0x8080045C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800460: b           L_80800490
    // 0x80800464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800490;
    // 0x80800464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800468:
    // 0x80800468: jal         0x80085710
    // 0x8080046C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_6;
    // 0x8080046C: nop

    after_6:
    // 0x80800470: addiu       $a0, $zero, 0x1A7
    ctx->r4 = ADD32(0, 0X1A7);
    // 0x80800474: jal         0x800887D8
    // 0x80800478: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x80800478: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_7:
    // 0x8080047C: b           L_80800490
    // 0x80800480: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800490;
    // 0x80800480: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800484:
    // 0x80800484: b           L_80800490
    // 0x80800488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800490;
    // 0x80800488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080048C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800490:
    // 0x80800490: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800494: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800498: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080049C: jr          $ra
    // 0x808004A0: nop

    return;
    // 0x808004A0: nop

;}
RECOMP_FUNC void chexploder_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801A24: jal         0x80100094
    // 0x80801A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801A2C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A30: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
    // 0x80801A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A3C: jr          $ra
    // 0x80801A40: nop

    return;
    // 0x80801A40: nop

;}
RECOMP_FUNC void _chfactoryempspell_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087520: syscall     584
    recomp_syscall_handler(rdram, ctx, 0x80087520);
    return;
    // 0x80087524: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsfirstp_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808049F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808049F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808049FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80804A00: jal         0x800F53D0
    // 0x80804A04: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x80804A04: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80804A08: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80804A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804A10: jal         0x8009E5C8
    // 0x80804A14: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80804A14: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_1:
    // 0x80804A18: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80804A1C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80804A20: sw          $t6, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = ctx->r14;
    // 0x80804A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804A28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804A2C: jr          $ra
    // 0x80804A30: nop

    return;
    // 0x80804A30: nop

;}
RECOMP_FUNC void func_8010682C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010682C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80106830: lw          $a1, 0x6EE0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6EE0);
    // 0x80106834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010683C: bne         $a1, $zero, L_8010684C
    if (ctx->r5 != 0) {
        // 0x80106840: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8010684C;
    }
    // 0x80106840: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80106844: b           L_80106898
    // 0x80106848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80106898;
    // 0x80106848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010684C:
    // 0x8010684C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80106850: jal         0x800B2928
    // 0x80106854: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    vector_size(rdram, ctx);
        goto after_0;
    // 0x80106854: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80106858: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8010685C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106860: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80106864: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80106868: bne         $at, $zero, L_80106878
    if (ctx->r1 != 0) {
        // 0x8010686C: nop
    
            goto L_80106878;
    }
    // 0x8010686C: nop

    // 0x80106870: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80106874: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80106878:
    // 0x80106878: blez        $v1, L_80106898
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8010687C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80106898;
    }
    // 0x8010687C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80106880: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x80106884: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x80106888: jal         0x800B28CC
    // 0x8010688C: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    vector_at(rdram, ctx);
        goto after_1;
    // 0x8010688C: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    after_1:
    // 0x80106890: b           L_8010689C
    // 0x80106894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010689C;
    // 0x80106894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106898:
    // 0x80106898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010689C:
    // 0x8010689C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801068A0: jr          $ra
    // 0x801068A4: nop

    return;
    // 0x801068A4: nop

;}
RECOMP_FUNC void _ncfixposrot_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089218: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x80089218);
    return;
    // 0x8008921C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _gccubesearch_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088288: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x80088288);
    return;
    // 0x8008828C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void fxgenlist_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2850, 0X5C) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2850, 0X5C));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2850, 0X5C));
;}
RECOMP_FUNC void chminelobbydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2196, 0X1F0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2196, 0X1F0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2196, 0X1F0));
;}
RECOMP_FUNC void func_80800054_chbottlesdead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800060: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800068: jal         0x800DF744
    // 0x8080006C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x8080006C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800074: jal         0x80101870
    // 0x80800078: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80800078: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void func_80803D00_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803D00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80803D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803D08: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80803D0C: sh          $a1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r5;
    // 0x80803D10: sh          $a0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r4;
    // 0x80803D14: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80803D18: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    // 0x80803D1C: jal         0x80101180
    // 0x80803D20: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x80803D20: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_0:
    // 0x80803D24: bnel        $v0, $zero, L_80803D54
    if (ctx->r2 != 0) {
        // 0x80803D28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80803D54;
    }
    goto skip_0;
    // 0x80803D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80803D2C: jal         0x800A5800
    // 0x80803D30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800A5800(rdram, ctx);
        goto after_1;
    // 0x80803D30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80803D34: jal         0x80085580
    // 0x80803D38: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80803D38: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80803D3C: jal         0x80085590
    // 0x80803D40: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80803D40: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80803D44: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80803D48: jal         0x800E39D8
    // 0x80803D4C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800E39D8(rdram, ctx);
        goto after_4;
    // 0x80803D4C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x80803D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803D54:
    // 0x80803D54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80803D58: jr          $ra
    // 0x80803D5C: nop

    return;
    // 0x80803D5C: nop

;}
RECOMP_FUNC void func_80801A50_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801A5C: jal         0x80109F08
    // 0x80801A60: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_80109F08(rdram, ctx);
        goto after_0;
    // 0x80801A60: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_0:
    // 0x80801A64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801A68: lbu         $t6, 0x7A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7A);
    // 0x80801A6C: andi        $t7, $t6, 0xFF3F
    ctx->r15 = ctx->r14 & 0XFF3F;
    // 0x80801A70: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80801A74: sb          $t8, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r24;
    // 0x80801A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A80: jr          $ra
    // 0x80801A84: nop

    return;
    // 0x80801A84: nop

;}
RECOMP_FUNC void _babackpack_get_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844E8: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x800844E8);
    return;
    // 0x800844EC: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _chexploder_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086678: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x80086678);
    return;
    // 0x8008667C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bsbswim_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AB8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801ABC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1F78) << 16);
    // 0x80801AC0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801AC4: jr          $ra
    // 0x80801AC8: lw          $v0, 0x1F78($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1F78));
    return;
    // 0x80801AC8: lw          $v0, 0x1F78($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1F78));
;}
RECOMP_FUNC void bsbanpackwhack_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000BC: jal         0x80095774
    // 0x808000C0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    baflag_clear(rdram, ctx);
        goto after_0;
    // 0x808000C0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_0:
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: jal         0x80084538
    // 0x808000CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_1;
    // 0x808000CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x800A0CD0
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_2;
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808000DC: jal         0x8009BC90
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_3;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000E4: jal         0x8009E474
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_4;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void func_80800CBC_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800CC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800CCC: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80800CD0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800CD4: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800CD8: bgezl       $t9, L_80800CF8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800CDC: addiu       $a0, $zero, 0x36
        ctx->r4 = ADD32(0, 0X36);
            goto L_80800CF8;
    }
    goto skip_0;
    // 0x80800CDC: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    skip_0:
    // 0x80800CE0: jal         0x80085710
    // 0x80800CE4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800CE4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800CE8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800CEC: ori         $t0, $a3, 0x2000
    ctx->r8 = ctx->r7 | 0X2000;
    // 0x80800CF0: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x80800CF4: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
L_80800CF8:
    // 0x80800CF8: jal         0x80088840
    // 0x80800CFC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800CFC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800D00: beq         $v0, $zero, L_80800D10
    if (ctx->r2 == 0) {
        // 0x80800D04: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800D10;
    }
    // 0x80800D04: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800D08: ori         $t1, $a3, 0x800
    ctx->r9 = ctx->r7 | 0X800;
    // 0x80800D0C: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
L_80800D10:
    // 0x80800D10: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80800D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D18: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D1C: jal         0x80085708
    // 0x80800D20: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800D20: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_2:
    // 0x80800D24: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80800D28: lbu         $t5, 0x65($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X65);
    // 0x80800D2C: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x80800D30: sb          $t6, 0x65($t3)
    MEM_B(0X65, ctx->r11) = ctx->r14;
    // 0x80800D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D3C: jr          $ra
    // 0x80800D40: nop

    return;
    // 0x80800D40: nop

;}
RECOMP_FUNC void func_80800A28_chdinofamilyfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A28: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800A2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800A30: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800A34: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800A38: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800A3C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800A40: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80800A44: jal         0x800B53A4
    // 0x80800A48: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800A48: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800A4C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A50: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800A54: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80800A58: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80800A5C: jal         0x800EEC30
    // 0x80800A60: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    func_800EEC30(rdram, ctx);
        goto after_1;
    // 0x80800A60: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_1:
    // 0x80800A64: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800A68: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    // 0x80800A6C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80800A70: jal         0x800EEC30
    // 0x80800A74: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    func_800EEC30(rdram, ctx);
        goto after_2;
    // 0x80800A74: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    after_2:
    // 0x80800A78: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800A7C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800A80: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800A84: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800A88: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A90: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800A94: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800A98: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800A9C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800AA0: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800AA4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800AA8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800AAC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800AB0: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x80800AB4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800AB8: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80800ABC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80800AC0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800AC4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80800AC8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80800ACC: sll         $t3, $a3, 16
    ctx->r11 = S32(ctx->r7 << 16);
    // 0x80800AD0: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80800AD4: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80800AD8: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800ADC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800AE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800AE4: jal         0x800BA930
    // 0x80800AE8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_800BA930(rdram, ctx);
        goto after_3;
    // 0x80800AE8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_3:
    // 0x80800AEC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800AF0: jal         0x800EF334
    // 0x80800AF4: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    func_800EF334(rdram, ctx);
        goto after_4;
    // 0x80800AF4: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    after_4:
    // 0x80800AF8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800AFC: jal         0x800EF334
    // 0x80800B00: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    func_800EF334(rdram, ctx);
        goto after_5;
    // 0x80800B00: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    after_5:
    // 0x80800B04: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800B08: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800B0C: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800B10: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800B14: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800B18: addiu       $t9, $zero, -0x190
    ctx->r25 = ADD32(0, -0X190);
    // 0x80800B1C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800B20: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800B24: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800B28: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800B2C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800B30: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80800B34: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800B38: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80800B3C: sll         $t5, $a3, 16
    ctx->r13 = S32(ctx->r7 << 16);
    // 0x80800B40: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80800B44: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80800B48: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B50: addiu       $a2, $zero, -0xC8
    ctx->r6 = ADD32(0, -0XC8);
    // 0x80800B54: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800B58: jal         0x800BA450
    // 0x80800B5C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_800BA450(rdram, ctx);
        goto after_6;
    // 0x80800B5C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_6:
    // 0x80800B60: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80800B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B68: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80800B6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800B74: jal         0x800BABB8
    // 0x80800B78: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800B78: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_7:
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B80: jal         0x800BA22C
    // 0x80800B84: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_800BA22C(rdram, ctx);
        goto after_8;
    // 0x80800B84: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_8:
    // 0x80800B88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B8C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800B90: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800B94: jr          $ra
    // 0x80800B98: nop

    return;
    // 0x80800B98: nop

    // 0x80800B9C: nop

;}
RECOMP_FUNC void func_80101934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010193C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80101940: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80101944: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x80101948: beq         $t6, $zero, L_80101960
    if (ctx->r14 == 0) {
        // 0x8010194C: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_80101960;
    }
    // 0x8010194C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80101950: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80101954: lw          $t9, 0x43E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X43E8);
    // 0x80101958: jalr        $t9
    // 0x8010195C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8010195C: nop

    after_0:
L_80101960:
    // 0x80101960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101964: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101968: jr          $ra
    // 0x8010196C: nop

    return;
    // 0x8010196C: nop

;}
RECOMP_FUNC void basudie_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800488: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080048C: jal         0x800852F0
    // 0x80800490: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x80800490: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80800494: beql        $v0, $zero, L_808004A8
    if (ctx->r2 == 0) {
        // 0x80800498: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004A8;
    }
    goto skip_0;
    // 0x80800498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080049C: jal         0x80800000
    // 0x808004A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    basudie_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808004A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808004A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004A8:
    // 0x808004A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004AC: jr          $ra
    // 0x808004B0: nop

    return;
    // 0x808004B0: nop

;}
RECOMP_FUNC void bsmum_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080054C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800550: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(308, 0X1140) << 16);
    // 0x80800554: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800558: jr          $ra
    // 0x8080055C: lw          $v0, 0x1140($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1140));
    return;
    // 0x8080055C: lw          $v0, 0x1140($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1140));
;}
RECOMP_FUNC void func_808008A4_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008B4: jal         0x8008CABC
    // 0x808008B8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808008B8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808008BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808008C0: jal         0x800852C0
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808008C8: jal         0x800852C8
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808008D0: jal         0x800852D0
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008D8: lui         $a1, 0x3F03
    ctx->r5 = S32(0X3F03 << 16);
    // 0x808008DC: ori         $a1, $a1, 0x126F
    ctx->r5 = ctx->r5 | 0X126F;
    // 0x808008E0: jal         0x8008B348
    // 0x808008E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x808008E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808008E8: beq         $v0, $zero, L_80800900
    if (ctx->r2 == 0) {
        // 0x808008EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800900;
    }
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F0: jal         0x800852B8
    // 0x808008F4: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x808008F4: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_5:
    // 0x808008F8: b           L_80800910
    // 0x808008FC: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
        goto L_80800910;
    // 0x808008FC: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
L_80800900:
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800904: jal         0x800852B8
    // 0x80800908: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800908: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_6:
    // 0x8080090C: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
L_80800910:
    // 0x80800910: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80800914: jal         0x8008B348
    // 0x80800918: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x80800918: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x8080091C: beq         $v0, $zero, L_80800938
    if (ctx->r2 == 0) {
        // 0x80800920: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800938;
    }
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800924: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x80800928: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080092C: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    // 0x80800930: jal         0x8009DF18
    // 0x80800934: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DF18(rdram, ctx);
        goto after_8;
    // 0x80800934: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_8:
L_80800938:
    // 0x80800938: lui         $a1, 0x3F2B
    ctx->r5 = S32(0X3F2B << 16);
    // 0x8080093C: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80800940: jal         0x8008B348
    // 0x80800944: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x80800944: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x80800948: beq         $v0, $zero, L_80800964
    if (ctx->r2 == 0) {
        // 0x8080094C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800964;
    }
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800950: lui         $a2, 0x3FD9
    ctx->r6 = S32(0X3FD9 << 16);
    // 0x80800954: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800958: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    // 0x8080095C: jal         0x8009DF18
    // 0x80800960: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DF18(rdram, ctx);
        goto after_10;
    // 0x80800960: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_10:
L_80800964:
    // 0x80800964: jal         0x80085280
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080096C: beq         $v0, $zero, L_808009A0
    if (ctx->r2 == 0) {
        // 0x80800970: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808009A0;
    }
    // 0x80800970: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800974: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800978: beq         $v0, $at, L_808009BC
    if (ctx->r2 == ctx->r1) {
        // 0x8080097C: addiu       $t7, $zero, 0x81
        ctx->r15 = ADD32(0, 0X81);
            goto L_808009BC;
    }
    // 0x8080097C: addiu       $t7, $zero, 0x81
    ctx->r15 = ADD32(0, 0X81);
    // 0x80800980: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800984: beq         $v0, $at, L_808009C4
    if (ctx->r2 == ctx->r1) {
        // 0x80800988: addiu       $t8, $zero, 0x82
        ctx->r24 = ADD32(0, 0X82);
            goto L_808009C4;
    }
    // 0x80800988: addiu       $t8, $zero, 0x82
    ctx->r24 = ADD32(0, 0X82);
    // 0x8080098C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800990: beq         $v0, $at, L_808009C8
    if (ctx->r2 == ctx->r1) {
        // 0x80800994: nop
    
            goto L_808009C8;
    }
    // 0x80800994: nop

    // 0x80800998: b           L_808009C8
    // 0x8080099C: nop

        goto L_808009C8;
    // 0x8080099C: nop

L_808009A0:
    // 0x808009A0: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x808009A4: jal         0x8008B348
    // 0x808009A8: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    anctrl_isAt(rdram, ctx);
        goto after_12;
    // 0x808009A8: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    after_12:
    // 0x808009AC: beq         $v0, $zero, L_808009C8
    if (ctx->r2 == 0) {
        // 0x808009B0: addiu       $t6, $zero, 0x2B
        ctx->r14 = ADD32(0, 0X2B);
            goto L_808009C8;
    }
    // 0x808009B0: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x808009B4: b           L_808009C8
    // 0x808009B8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_808009C8;
    // 0x808009B8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808009BC:
    // 0x808009BC: b           L_808009C8
    // 0x808009C0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_808009C8;
    // 0x808009C0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808009C4:
    // 0x808009C4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808009C8:
    // 0x808009C8: jal         0x80085278
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808009D0: beq         $v0, $zero, L_808009DC
    if (ctx->r2 == 0) {
        // 0x808009D4: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_808009DC;
    }
    // 0x808009D4: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x808009D8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_808009DC:
    // 0x808009DC: jal         0x8008E35C
    // 0x808009E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_14;
    // 0x808009E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808009E4: bne         $v0, $zero, L_808009F4
    if (ctx->r2 != 0) {
        // 0x808009E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009F4;
    }
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009EC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808009F0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_808009F4:
    // 0x808009F4: jal         0x8009E5C8
    // 0x808009F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x808009F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x808009FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A08: jr          $ra
    // 0x80800A0C: nop

    return;
    // 0x80800A0C: nop

;}
RECOMP_FUNC void chglowbo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E10: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1628, 0X1540) << 16);
    // 0x80800E14: jr          $ra
    // 0x80800E18: addiu       $v0, $v0, 0x1540
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1628, 0X1540));
    return;
    // 0x80800E18: addiu       $v0, $v0, 0x1540
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1628, 0X1540));
;}
RECOMP_FUNC void func_800DD65C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD65C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800DD660: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DD664: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DD668: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800DD66C: lh          $t6, 0xA($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XA);
    // 0x800DD670: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DD674: jal         0x80018BA8
    // 0x800DD678: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    mlMtx_get_stack_pointer(rdram, ctx);
        goto after_0;
    // 0x800DD678: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    after_0:
    // 0x800DD67C: lh          $t7, 0xE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE);
    // 0x800DD680: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DD684: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800DD688: beq         $t7, $zero, L_800DD6B8
    if (ctx->r15 == 0) {
        // 0x800DD68C: nop
    
            goto L_800DD6B8;
    }
    // 0x800DD68C: nop

    // 0x800DD690: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800DD694: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    // 0x800DD698: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800DD69C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800DD6A0: beq         $t0, $zero, L_800DD6B8
    if (ctx->r8 == 0) {
        // 0x800DD6A4: nop
    
            goto L_800DD6B8;
    }
    // 0x800DD6A4: nop

    // 0x800DD6A8: lh          $a2, 0xC($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC);
    // 0x800DD6AC: jal         0x8010F070
    // 0x800DD6B0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8010F070(rdram, ctx);
        goto after_1;
    // 0x800DD6B0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x800DD6B4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_800DD6B8:
    // 0x800DD6B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DD6BC: lw          $v0, -0x313C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X313C);
    // 0x800DD6C0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800DD6C4: beql        $v0, $zero, L_800DD6D8
    if (ctx->r2 == 0) {
        // 0x800DD6C8: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_800DD6D8;
    }
    goto skip_0;
    // 0x800DD6C8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x800DD6CC: jalr        $v0
    // 0x800DD6D0: lh          $a2, 0xC($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x800DD6D0: lh          $a2, 0xC($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC);
    after_2:
    // 0x800DD6D4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_800DD6D8:
    // 0x800DD6D8: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    // 0x800DD6DC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800DD6E0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800DD6E4: lw          $t1, -0x36A0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X36A0);
    // 0x800DD6E8: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x800DD6EC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800DD6F0: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800DD6F4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800DD6F8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800DD6FC: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    // 0x800DD700: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800DD704: jal         0x8002E330
    // 0x800DD708: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800DD708: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x800DD70C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800DD710: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800DD714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD718: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DD71C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800DD720: jr          $ra
    // 0x800DD724: nop

    return;
    // 0x800DD724: nop

;}
RECOMP_FUNC void func_8080080C_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080080C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800810: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800814: jal         0x8080055C
    // 0x80800818: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bsbabykaz_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800818: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080081C: lui         $a2, 0x3EC2
    ctx->r6 = S32(0X3EC2 << 16);
    // 0x80800820: ori         $a2, $a2, 0x8F5C
    ctx->r6 = ctx->r6 | 0X8F5C;
    // 0x80800824: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800828: jal         0x8008CB3C
    // 0x8080082C: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080082C: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    after_1:
    // 0x80800830: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800834: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800838: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080083C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800840: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800844: jal         0x8009FFD8
    // 0x80800848: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800848: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8080084C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800850: sw          $zero, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = 0;
    // 0x80800854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080085C: jr          $ra
    // 0x80800860: nop

    return;
    // 0x80800860: nop

;}
RECOMP_FUNC void func_808010DC_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808010E8: jal         0x808009C8
    // 0x808010EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808009C8_bskazfly(rdram, ctx);
        goto after_0;
    // 0x808010EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808010F0: jal         0x80800188
    // 0x808010F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800188_bskazfly(rdram, ctx);
        goto after_1;
    // 0x808010F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808010F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801100: jr          $ra
    // 0x80801104: nop

    return;
    // 0x80801104: nop

;}
RECOMP_FUNC void chanim_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001BC: jal         0x80100094
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001C4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x808001C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808001CC: beql        $t6, $zero, L_808001E8
    if (ctx->r14 == 0) {
        // 0x808001D0: sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
            goto L_808001E8;
    }
    goto skip_0;
    // 0x808001D0: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    skip_0:
    // 0x808001D4: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x808001D8: jal         0x80082640
    // 0x808001DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _anseq_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808001DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001E0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_808001E8:
    // 0x808001E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001F0: jr          $ra
    // 0x808001F4: nop

    return;
    // 0x808001F4: nop

;}
RECOMP_FUNC void func_80800154_chlavaarchgrill3switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800158: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080015C: addiu       $t6, $zero, 0x62
    ctx->r14 = ADD32(0, 0X62);
    // 0x80800160: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800164: jal         0x80800020
    // 0x80800168: addiu       $a3, $zero, 0x61
    ctx->r7 = ADD32(0, 0X61);
    func_80800020_chlavaarchgrill3switches(rdram, ctx);
        goto after_0;
    // 0x80800168: addiu       $a3, $zero, 0x61
    ctx->r7 = ADD32(0, 0X61);
    after_0:
    // 0x8080016C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void idwater_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800054: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800058: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8080005C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800060: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800064: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80800068: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x8080006C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800070: jal         0x800DC264
    // 0x80800074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC264(rdram, ctx);
        goto after_0;
    // 0x80800074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080007C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800080: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80800084: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800088: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x8080008C: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x80800090: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800094: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x80800098: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x8080009C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000A0: swc1        $f12, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f12.u32l;
    // 0x808000A4: swc1        $f12, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f12.u32l;
    // 0x808000A8: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x808000AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void func_800A4E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4E30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4E38: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A4E3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A4E40: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x800A4E44: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x800A4E48: lbu         $v0, 0x6($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X6);
    // 0x800A4E4C: beq         $v0, $at, L_800A4E64
    if (ctx->r2 == ctx->r1) {
        // 0x800A4E50: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800A4E64;
    }
    // 0x800A4E50: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A4E54: beql        $v0, $at, L_800A4E68
    if (ctx->r2 == ctx->r1) {
        // 0x800A4E58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A4E68;
    }
    goto skip_0;
    // 0x800A4E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A4E5C: jal         0x800A3F14
    // 0x800A4E60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A3F14(rdram, ctx);
        goto after_0;
    // 0x800A4E60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
L_800A4E64:
    // 0x800A4E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A4E68:
    // 0x800A4E68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4E6C: jr          $ra
    // 0x800A4E70: nop

    return;
    // 0x800A4E70: nop

;}
RECOMP_FUNC void _capod_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856D8: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856D8);
    return;
    // 0x800856DC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bstrexlarge_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800894: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800898: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(412, 0X19A0) << 16);
    // 0x8080089C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808008A0: jr          $ra
    // 0x808008A4: lw          $v0, 0x19A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X19A0));
    return;
    // 0x808008A4: lw          $v0, 0x19A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X19A0));
;}
RECOMP_FUNC void _bsstatue_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BA8: syscall     91
    recomp_syscall_handler(rdram, ctx, 0x80083BA8);
    return;
    // 0x80083BAC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _gcstatusDll_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883B0: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x800883B0);
    return;
    // 0x800883B4: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void bsfirstp_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800068: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x8080006C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800070: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800074: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800078: jal         0x80802484
    // 0x8080007C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80802484_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080007C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80800080: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800084: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80800088: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080008C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800090: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800094: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80800098: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8080009C: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x808000A0: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x808000A4: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    // 0x808000A8: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x808000AC: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x808000B0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808000B4: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x808000B8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x808000BC: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x808000C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000C4: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x808000C8: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808000CC: jal         0x8080800C
    // 0x808000D0: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    func_8080800C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808000D0: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    after_1:
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void func_800B38A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B38A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B38AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B38B0: jal         0x800EE830
    // 0x800B38B4: nop

    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x800B38B4: nop

    after_0:
    // 0x800B38B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B38BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B38C0: jr          $ra
    // 0x800B38C4: nop

    return;
    // 0x800B38C4: nop

;}
RECOMP_FUNC void idworld_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000DC: jal         0x80800000
    // 0x808000E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800000_idworld(rdram, ctx);
        goto after_0;
    // 0x808000E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x808000E4: beq         $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000F4;
    }
    // 0x808000E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000EC: b           L_808000F8
    // 0x808000F0: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
        goto L_808000F8;
    // 0x808000F0: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
L_808000F4:
    // 0x808000F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808000F8:
    // 0x808000F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808000FC: jr          $ra
    // 0x80800100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808017D4_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808017D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808017DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808017E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808017E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808017E8: jal         0x80100094
    // 0x808017EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808017EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808017F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808017F4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808017F8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808017FC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801800: bnel        $t7, $at, L_80801814
    if (ctx->r15 != ctx->r1) {
        // 0x80801804: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801814;
    }
    goto skip_0;
    // 0x80801804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801808: jal         0x8010A570
    // 0x8080180C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x8080180C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801814:
    // 0x80801814: jal         0x80102424
    // 0x80801818: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80801818: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8080181C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801820: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801824: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x80801828: beq         $t8, $at, L_808018DC
    if (ctx->r24 == ctx->r1) {
        // 0x8080182C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808018DC;
    }
    // 0x8080182C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801830: beq         $t8, $at, L_808018CC
    if (ctx->r24 == ctx->r1) {
        // 0x80801834: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808018CC;
    }
    // 0x80801834: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80801838: beq         $t8, $at, L_80801850
    if (ctx->r24 == ctx->r1) {
        // 0x8080183C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80801850;
    }
    // 0x8080183C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80801840: beq         $t8, $at, L_8080186C
    if (ctx->r24 == ctx->r1) {
        // 0x80801844: nop
    
            goto L_8080186C;
    }
    // 0x80801844: nop

    // 0x80801848: b           L_808018E8
    // 0x8080184C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018E8;
    // 0x8080184C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801850:
    // 0x80801850: jal         0x80800EF4
    // 0x80801854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800EF4_chchuffy(rdram, ctx);
        goto after_3;
    // 0x80801854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801858: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X2318) << 16);
    // 0x8080185C: lwc1        $f4, 0x2318($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X2318));
    // 0x80801860: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80801864: b           L_808018E4
    // 0x80801868: swc1        $f4, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f4.u32l;
        goto L_808018E4;
    // 0x80801868: swc1        $f4, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f4.u32l;
L_8080186C:
    // 0x8080186C: jal         0x800DA298
    // 0x80801870: addiu       $a0, $zero, 0x6B7
    ctx->r4 = ADD32(0, 0X6B7);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80801870: addiu       $a0, $zero, 0x6B7
    ctx->r4 = ADD32(0, 0X6B7);
    after_4:
    // 0x80801874: addiu       $a0, $zero, 0x6E4
    ctx->r4 = ADD32(0, 0X6E4);
    // 0x80801878: jal         0x800DA3B8
    // 0x8080187C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_5;
    // 0x8080187C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80801880: addiu       $a0, $zero, 0x6B7
    ctx->r4 = ADD32(0, 0X6B7);
    // 0x80801884: jal         0x800DA9E4
    // 0x80801888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_6;
    // 0x80801888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8080188C: beql        $v0, $zero, L_808018AC
    if (ctx->r2 == 0) {
        // 0x80801890: lbu         $t0, 0x74($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X74);
            goto L_808018AC;
    }
    goto skip_1;
    // 0x80801890: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
    skip_1:
    // 0x80801894: jal         0x800EA05C
    // 0x80801898: nop

    func_800EA05C(rdram, ctx);
        goto after_7;
    // 0x80801898: nop

    after_7:
    // 0x8080189C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808018A0: jal         0x800887D8
    // 0x808018A4: addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x808018A4: addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    after_8:
    // 0x808018A8: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
L_808018AC:
    // 0x808018AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018B0: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x808018B4: jal         0x80800F54
    // 0x808018B8: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
    func_80800F54_chchuffy(rdram, ctx);
        goto after_9;
    // 0x808018B8: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
    after_9:
    // 0x808018BC: jal         0x808001DC
    // 0x808018C0: nop

    func_808001DC_chchuffy(rdram, ctx);
        goto after_10;
    // 0x808018C0: nop

    after_10:
    // 0x808018C4: b           L_808018E8
    // 0x808018C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018E8;
    // 0x808018C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018CC:
    // 0x808018CC: jal         0x8010A590
    // 0x808018D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_11;
    // 0x808018D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808018D4: b           L_808018E8
    // 0x808018D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018E8;
    // 0x808018D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018DC:
    // 0x808018DC: jal         0x8010A590
    // 0x808018E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_12;
    // 0x808018E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_808018E4:
    // 0x808018E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018E8:
    // 0x808018E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808018EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808018F0: jr          $ra
    // 0x808018F4: nop

    return;
    // 0x808018F4: nop

;}
RECOMP_FUNC void func_80800144_chmole_maya(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: jr          $ra
    // 0x80800148: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800148: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800909CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800909CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800909D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800909D4: jal         0x8009097C
    // 0x800909D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009097C(rdram, ctx);
        goto after_0;
    // 0x800909D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800909DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800909E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800909E4: jr          $ra
    // 0x800909E8: nop

    return;
    // 0x800909E8: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D98: jal         0x8080061C
    // 0x80800D9C: nop

    func_8080061C_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80800D9C: nop

    after_0:
    // 0x80800DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DA8: jr          $ra
    // 0x80800DAC: nop

    return;
    // 0x80800DAC: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089568: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089568);
    return;
    // 0x8008956C: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_80801040_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801044: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80801048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080104C: beq         $a1, $at, L_80801068
    if (ctx->r5 == ctx->r1) {
        // 0x80801050: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801068;
    }
    // 0x80801050: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801054: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80801058: beq         $a1, $at, L_8080108C
    if (ctx->r5 == ctx->r1) {
        // 0x8080105C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080108C;
    }
    // 0x8080105C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801060: b           L_8080109C
    // 0x80801064: nop

        goto L_8080109C;
    // 0x80801064: nop

L_80801068:
    // 0x80801068: jal         0x80101080
    // 0x8080106C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x8080106C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801074: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801078: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    // 0x8080107C: jal         0x8080079C
    // 0x80801080: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    func_8080079C_chmusicmenu(rdram, ctx);
        goto after_1;
    // 0x80801080: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    after_1:
    // 0x80801084: b           L_8080109C
    // 0x80801088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080109C;
    // 0x80801088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080108C:
    // 0x8080108C: jal         0x80800930
    // 0x80801090: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800930_chmusicmenu(rdram, ctx);
        goto after_2;
    // 0x80801090: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801094: b           L_8080109C
    // 0x80801098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080109C;
    // 0x80801098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080109C:
    // 0x8080109C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010A4: jr          $ra
    // 0x808010A8: nop

    return;
    // 0x808010A8: nop

;}
RECOMP_FUNC void func_80800C60_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C60: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800C64: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800C68: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800C6C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800C70: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800C74: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800C78: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800C7C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800C80: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80800C84: addiu       $a1, $zero, 0x413
    ctx->r5 = ADD32(0, 0X413);
    // 0x80800C88: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800C8C: jal         0x8009DB04
    // 0x80800C90: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DB04(rdram, ctx);
        goto after_0;
    // 0x80800C90: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_0:
    // 0x80800C94: jal         0x8009D9D4
    // 0x80800C98: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    func_8009D9D4(rdram, ctx);
        goto after_1;
    // 0x80800C98: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_1:
    // 0x80800C9C: addiu       $s2, $sp, 0x54
    ctx->r18 = ADD32(ctx->r29, 0X54);
    // 0x80800CA0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800CA4: jal         0x8009C128
    // 0x80800CA8: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x80800CA8: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_2:
    // 0x80800CAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800CB0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800CB4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(380, 0X17A0) << 16);
    // 0x80800CB8: addiu       $t6, $t6, 0x17A0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(380, 0X17A0));
    // 0x80800CBC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800CC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800CC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800CC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CCC: jal         0x800BBCB8
    // 0x80800CD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800CD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80800CD4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(380, 0X1840) << 16);
    // 0x80800CD8: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(380, 0X172C) << 16);
    // 0x80800CDC: addiu       $s3, $s3, 0x172C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(380, 0X172C));
    // 0x80800CE0: addiu       $s1, $s1, 0x1840
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(380, 0X1840));
    // 0x80800CE4: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x80800CE8: addiu       $s4, $sp, 0x88
    ctx->r20 = ADD32(ctx->r29, 0X88);
L_80800CEC:
    // 0x80800CEC: jal         0x800B53A4
    // 0x80800CF0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800B53A4(rdram, ctx);
        goto after_4;
    // 0x80800CF0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_4:
    // 0x80800CF4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80800CF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CFC: jal         0x800BA670
    // 0x80800D00: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    func_800BA670(rdram, ctx);
        goto after_5;
    // 0x80800D00: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    after_5:
    // 0x80800D04: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800D08: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800D0C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80800D10: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800D14: jal         0x800BABB8
    // 0x80800D18: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800D18: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_6:
    // 0x80800D1C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800D20: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x80800D24: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80800D28: bne         $at, $zero, L_80800CEC
    if (ctx->r1 != 0) {
        // 0x80800D2C: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_80800CEC;
    }
    // 0x80800D2C: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80800D30: jal         0x8008E35C
    // 0x80800D34: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    player_inWater(rdram, ctx);
        goto after_7;
    // 0x80800D34: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_7:
    // 0x80800D38: beq         $v0, $zero, L_80800DB8
    if (ctx->r2 == 0) {
        // 0x80800D3C: addiu       $s0, $sp, 0x60
        ctx->r16 = ADD32(ctx->r29, 0X60);
            goto L_80800DB8;
    }
    // 0x80800D3C: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x80800D40: jal         0x800964DC
    // 0x80800D44: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    func_800964DC(rdram, ctx);
        goto after_8;
    // 0x80800D44: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_8:
    // 0x80800D48: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800D4C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800D50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800D54: jal         0x800889D0
    // 0x80800D58: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    _fxairbub_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800D58: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_9:
    // 0x80800D5C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(380, 0X17CC) << 16);
    // 0x80800D60: addiu       $t7, $t7, 0x17CC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(380, 0X17CC));
    // 0x80800D64: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800D68: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800D6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D70: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800D74: jal         0x800BABB8
    // 0x80800D78: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800BABB8(rdram, ctx);
        goto after_10;
    // 0x80800D78: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_10:
    // 0x80800D7C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(380, 0X1748) << 16);
    // 0x80800D80: addiu       $s1, $s1, 0x1748
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(380, 0X1748));
    // 0x80800D84: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x80800D88: addiu       $s3, $sp, 0x88
    ctx->r19 = ADD32(ctx->r29, 0X88);
L_80800D8C:
    // 0x80800D8C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800D90: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800D94: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80800D98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800D9C: jal         0x800BABB8
    // 0x80800DA0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800BABB8(rdram, ctx);
        goto after_11;
    // 0x80800DA0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_11:
    // 0x80800DA4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800DA8: bne         $s0, $s3, L_80800D8C
    if (ctx->r16 != ctx->r19) {
        // 0x80800DAC: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_80800D8C;
    }
    // 0x80800DAC: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80800DB0: b           L_80800DE8
    // 0x80800DB4: nop

        goto L_80800DE8;
    // 0x80800DB4: nop

L_80800DB8:
    // 0x80800DB8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(380, 0X1774) << 16);
    // 0x80800DBC: addiu       $s1, $s1, 0x1774
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(380, 0X1774));
    // 0x80800DC0: addiu       $s3, $sp, 0x88
    ctx->r19 = ADD32(ctx->r29, 0X88);
L_80800DC4:
    // 0x80800DC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800DC8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800DCC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80800DD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800DD4: jal         0x800BABB8
    // 0x80800DD8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800BABB8(rdram, ctx);
        goto after_12;
    // 0x80800DD8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_12:
    // 0x80800DDC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800DE0: bne         $s0, $s3, L_80800DC4
    if (ctx->r16 != ctx->r19) {
        // 0x80800DE4: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_80800DC4;
    }
    // 0x80800DE4: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
L_80800DE8:
    // 0x80800DE8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(380, 0X1840) << 16);
    // 0x80800DEC: addiu       $s1, $s1, 0x1840
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(380, 0X1840));
    // 0x80800DF0: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x80800DF4: addiu       $s2, $sp, 0x88
    ctx->r18 = ADD32(ctx->r29, 0X88);
L_80800DF8:
    // 0x80800DF8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800DFC: jal         0x800BA22C
    // 0x80800E00: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_800BA22C(rdram, ctx);
        goto after_13;
    // 0x80800E00: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_13:
    // 0x80800E04: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800E08: bne         $s0, $s2, L_80800DF8
    if (ctx->r16 != ctx->r18) {
        // 0x80800E0C: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80800DF8;
    }
    // 0x80800E0C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80800E10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800E14: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800E18: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800E1C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E20: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800E24: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800E28: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800E2C: jr          $ra
    // 0x80800E30: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800E30: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_808008DC_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808008E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808008EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808008F0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808008F4: jal         0x80100094
    // 0x808008F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800900: jal         0x80800734
    // 0x80800904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800734_chclockworkmouse(rdram, ctx);
        goto after_1;
    // 0x80800904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800908: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080090C: lbu         $t7, 0xFA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XFA);
    // 0x80800910: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80800914: beq         $at, $zero, L_80800958
    if (ctx->r1 == 0) {
        // 0x80800918: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800958;
    }
    // 0x80800918: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080091C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X36A8) << 16);
    // 0x80800920: addu        $at, $at, $t7
    gpr jr_addend_80800928 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800924: lw          $t7, 0x36A8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1564, 0X36A8));
    // 0x80800928: jr          $t7
    // 0x8080092C: nop

    switch (jr_addend_80800928 >> 2) {
        case 0: goto L_80800930; break;
        case 1: goto L_8080093C; break;
        case 2: goto L_8080093C; break;
        case 3: goto L_8080093C; break;
        case 4: goto L_80800948; break;
        default: switch_error(__func__, 0x80800928, 0x808036A8);
    }
    // 0x8080092C: nop

L_80800930:
    // 0x80800930: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800934: jal         0x80800700
    // 0x80800938: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800700_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x80800938: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
L_8080093C:
    // 0x8080093C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800940: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80800944: sb          $t8, 0xFA($t9)
    MEM_B(0XFA, ctx->r25) = ctx->r24;
L_80800948:
    // 0x80800948: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080094C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800950: jal         0x80085740
    // 0x80800954: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800954: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
L_80800958:
    // 0x80800958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080095C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800960: jr          $ra
    // 0x80800964: nop

    return;
    // 0x80800964: nop

;}
