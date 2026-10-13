#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8009FBE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FBE8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009FBEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009FBF0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8009FBF4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8009FBF8: jal         0x8009C128
    // 0x8009FBFC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009FBFC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8009FC00: jal         0x800A4C48
    // 0x8009FC04: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800A4C48(rdram, ctx);
        goto after_1;
    // 0x8009FC04: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8009FC08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009FC0C: jal         0x800CA7E4
    // 0x8009FC10: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800CA7E4(rdram, ctx);
        goto after_2;
    // 0x8009FC10: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x8009FC14: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8009FC18: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8009FC1C: jal         0x800EFB24
    // 0x8009FC20: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x8009FC20: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x8009FC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009FC28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8009FC2C: jr          $ra
    // 0x8009FC30: nop

    return;
    // 0x8009FC30: nop

;}
RECOMP_FUNC void func_800932CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800932CC: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x800932D0: lbu         $t6, 0xC4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC4);
    // 0x800932D4: beq         $a1, $t6, L_800932F8
    if (ctx->r5 == ctx->r14) {
        // 0x800932D8: nop
    
            goto L_800932F8;
    }
    // 0x800932D8: nop

    // 0x800932DC: beql        $a1, $zero, L_800932F8
    if (ctx->r5 == 0) {
        // 0x800932E0: sb          $a1, 0xC4($v0)
        MEM_B(0XC4, ctx->r2) = ctx->r5;
            goto L_800932F8;
    }
    goto skip_0;
    // 0x800932E0: sb          $a1, 0xC4($v0)
    MEM_B(0XC4, ctx->r2) = ctx->r5;
    skip_0:
    // 0x800932E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800932E8: nop

    // 0x800932EC: swc1        $f4, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f4.u32l;
    // 0x800932F0: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x800932F4: sb          $a1, 0xC4($v0)
    MEM_B(0XC4, ctx->r2) = ctx->r5;
L_800932F8:
    // 0x800932F8: jr          $ra
    // 0x800932FC: nop

    return;
    // 0x800932FC: nop

;}
RECOMP_FUNC void bacough_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x80800040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800044: jal         0x8080005C
    // 0x80800048: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    bacough_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800048: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    after_0:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082550: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082550);
    return;
    // 0x80082554: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800B7EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7EA0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B7EA4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B7EA8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B7EAC: jal         0x800D674C
    // 0x800B7EB0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x800B7EB0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800B7EB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B7EB8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800B7EBC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800B7EC0: addiu       $t9, $sp, 0x38
    ctx->r25 = ADD32(ctx->r29, 0X38);
    // 0x800B7EC4: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x800B7EC8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800B7ECC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800B7ED0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800B7ED4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800B7ED8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800B7EDC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B7EE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B7EE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B7EE8: jal         0x800AF614
    // 0x800B7EEC: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    func_800AF614(rdram, ctx);
        goto after_1;
    // 0x800B7EEC: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_1:
    // 0x800B7EF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B7EF4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B7EF8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800B7EFC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B7F00: addiu       $v0, $v0, -0x7D40
    ctx->r2 = ADD32(ctx->r2, -0X7D40);
    // 0x800B7F04: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B7F08: sb          $t1, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r9;
    // 0x800B7F0C: jr          $ra
    // 0x800B7F10: sb          $t2, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r10;
    return;
    // 0x800B7F10: sb          $t2, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r10;
;}
RECOMP_FUNC void func_800C3730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3734: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3738: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C373C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3744: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C3748: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C374C: beq         $t6, $zero, L_800C3788
    if (ctx->r14 == 0) {
        // 0x800C3750: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_800C3788;
    }
    // 0x800C3750: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C3754: jal         0x800C1414
    // 0x800C3758: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3758: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    after_0:
    // 0x800C375C: lhu         $t7, 0x7A($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X7A);
    // 0x800C3760: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C3764: andi        $t8, $t7, 0xFC3F
    ctx->r24 = ctx->r15 & 0XFC3F;
    // 0x800C3768: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x800C376C: sh          $t9, 0x7A($v0)
    MEM_H(0X7A, ctx->r2) = ctx->r25;
    // 0x800C3770: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3774: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x800C3778: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C377C: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x800C3780: jal         0x800C31DC
    // 0x800C3784: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800C31DC(rdram, ctx);
        goto after_1;
    // 0x800C3784: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_800C3788:
    // 0x800C3788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C378C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3790: jr          $ra
    // 0x800C3794: nop

    return;
    // 0x800C3794: nop

;}
RECOMP_FUNC void func_800E249C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E249C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E24A0: jr          $ra
    // 0x800E24A4: sw          $a0, -0x2B6C($at)
    MEM_W(-0X2B6C, ctx->r1) = ctx->r4;
    return;
    // 0x800E24A4: sw          $a0, -0x2B6C($at)
    MEM_W(-0X2B6C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800E204C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E204C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E2050: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E2054: addiu       $v1, $v1, -0x2B90
    ctx->r3 = ADD32(ctx->r3, -0X2B90);
    // 0x800E2058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E205C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E2060: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800E2064: lh          $t1, 0x4($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X4);
    // 0x800E2068: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800E206C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E2070: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800E2074: beql        $t0, $t1, L_800E2088
    if (ctx->r8 == ctx->r9) {
        // 0x800E2078: lh          $v0, 0x2($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X2);
            goto L_800E2088;
    }
    goto skip_0;
    // 0x800E2078: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    skip_0:
    // 0x800E207C: bnel        $t0, $zero, L_800E20D0
    if (ctx->r8 != 0) {
        // 0x800E2080: mtc1        $t0, $f10
        ctx->f10.u32l = ctx->r8;
            goto L_800E20D0;
    }
    goto skip_1;
    // 0x800E2080: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    skip_1:
    // 0x800E2084: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
L_800E2088:
    // 0x800E2088: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x800E208C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E2090: beql        $v0, $t8, L_800E20A4
    if (ctx->r2 == ctx->r24) {
        // 0x800E2094: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800E20A4;
    }
    goto skip_2;
    // 0x800E2094: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x800E2098: bnel        $v0, $zero, L_800E20D0
    if (ctx->r2 != 0) {
        // 0x800E209C: mtc1        $t0, $f10
        ctx->f10.u32l = ctx->r8;
            goto L_800E20D0;
    }
    goto skip_3;
    // 0x800E209C: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    skip_3:
    // 0x800E20A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800E20A4:
    // 0x800E20A4: lwc1        $f4, 0x2C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800E20A8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800E20AC: nop

    // 0x800E20B0: bc1fl       L_800E20D0
    if (!c1cs) {
        // 0x800E20B4: mtc1        $t0, $f10
        ctx->f10.u32l = ctx->r8;
            goto L_800E20D0;
    }
    goto skip_4;
    // 0x800E20B4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    skip_4:
    // 0x800E20B8: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800E20BC: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800E20C0: nop

    // 0x800E20C4: bc1tl       L_800E2170
    if (c1cs) {
        // 0x800E20C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800E2170;
    }
    goto skip_5;
    // 0x800E20C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x800E20CC: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
L_800E20D0:
    // 0x800E20D0: lwc1        $f8, 0x2C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800E20D4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800E20D8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E20DC: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x800E20E0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800E20E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E20E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E20EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E20F0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800E20F4: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800E20F8: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x800E20FC: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800E2100: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E2104: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800E2108: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E210C: addiu       $a0, $a0, -0x2B58
    ctx->r4 = ADD32(ctx->r4, -0X2B58);
    // 0x800E2110: div.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800E2114: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800E2118: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800E211C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800E2120: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E2124: div.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800E2128: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800E212C: jal         0x800F26B0
    // 0x800E2130: nop

    func_800F26B0(rdram, ctx);
        goto after_0;
    // 0x800E2130: nop

    after_0:
    // 0x800E2134: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E2138: addiu       $a0, $a0, -0x2B58
    ctx->r4 = ADD32(ctx->r4, -0X2B58);
    // 0x800E213C: jal         0x8002ED00
    // 0x800E2140: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800E2140: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x800E2144: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E2148: lui         $t5, 0xDA38
    ctx->r13 = S32(0XDA38 << 16);
    // 0x800E214C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800E2150: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800E2154: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800E2158: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800E215C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800E2160: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800E2164: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x800E2168: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800E216C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E2170:
    // 0x800E2170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E2174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E2178: jr          $ra
    // 0x800E217C: nop

    return;
    // 0x800E217C: nop

;}
RECOMP_FUNC void chdoormake_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006EC: jal         0x80100094
    // 0x808006F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006F4: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x808006F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006FC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800700: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800704: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800708: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8080070C: nop

    // 0x80800710: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
    // 0x80800714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080071C: jr          $ra
    // 0x80800720: nop

    return;
    // 0x80800720: nop

;}
RECOMP_FUNC void func_80801118_chdinofamilymother(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080111C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801124: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801128: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080112C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80801130: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x80801134: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80801138: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080113C: beq         $v0, $zero, L_80801160
    if (ctx->r2 == 0) {
        // 0x80801140: ori         $t8, $a2, 0x10
        ctx->r24 = ctx->r6 | 0X10;
            goto L_80801160;
    }
    // 0x80801140: ori         $t8, $a2, 0x10
    ctx->r24 = ctx->r6 | 0X10;
    // 0x80801144: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801148: beq         $v0, $at, L_80801170
    if (ctx->r2 == ctx->r1) {
        // 0x8080114C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801170;
    }
    // 0x8080114C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801150: beql        $v0, $at, L_80801180
    if (ctx->r2 == ctx->r1) {
        // 0x80801154: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80801180;
    }
    goto skip_0;
    // 0x80801154: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801158: b           L_80801190
    // 0x8080115C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801190;
    // 0x8080115C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801160:
    // 0x80801160: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80801164: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    // 0x80801168: jal         0x800856B0
    // 0x8080116C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080116C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_0:
L_80801170:
    // 0x80801170: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80801174: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80801178: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x8080117C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80801180:
    // 0x80801180: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801184: jal         0x800856D0
    // 0x80801188: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80801188: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8080118C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801190:
    // 0x80801190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801194: jr          $ra
    // 0x80801198: nop

    return;
    // 0x80801198: nop

;}
RECOMP_FUNC void defragment_overlays(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081BEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80081BF0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80081BF4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80081BF8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80081BFC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80081C00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081C04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081C08: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80081C0C: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x80081C10: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80081C14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80081C18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80081C1C: sw          $t6, 0x6CBC($at)
    MEM_W(0X6CBC, ctx->r1) = ctx->r14;
    // 0x80081C20: addiu       $s4, $s4, 0x7C60
    ctx->r20 = ADD32(ctx->r20, 0X7C60);
    // 0x80081C24: addiu       $s3, $s3, 0x6738
    ctx->r19 = ADD32(ctx->r19, 0X6738);
    // 0x80081C28: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80081C2C: addiu       $s5, $zero, 0xF
    ctx->r21 = ADD32(0, 0XF);
L_80081C30:
    // 0x80081C30: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80081C34: lw          $t7, 0x7C68($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7C68);
    // 0x80081C38: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80081C3C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80081C40: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80081C44: sw          $t8, 0x7C68($at)
    MEM_W(0X7C68, ctx->r1) = ctx->r24;
    // 0x80081C48: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80081C4C: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80081C50: bne         $at, $zero, L_80081C5C
    if (ctx->r1 != 0) {
        // 0x80081C54: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_80081C5C;
    }
    // 0x80081C54: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80081C58: sw          $zero, 0x7C68($at)
    MEM_W(0X7C68, ctx->r1) = 0;
L_80081C5C:
    // 0x80081C5C: lw          $t0, 0x7C68($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7C68);
    // 0x80081C60: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80081C64: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x80081C68: lw          $s0, 0x0($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X0);
    // 0x80081C6C: beql        $s0, $zero, L_80081CF4
    if (ctx->r16 == 0) {
        // 0x80081C70: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80081CF4;
    }
    goto skip_0;
    // 0x80081C70: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80081C74: lbu         $v0, 0xF($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XF);
    // 0x80081C78: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x80081C7C: bnel        $t3, $zero, L_80081CF4
    if (ctx->r11 != 0) {
        // 0x80081C80: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80081CF4;
    }
    goto skip_1;
    // 0x80081C80: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80081C84: lh          $t4, 0x32($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X32);
    // 0x80081C88: andi        $t5, $v0, 0x10
    ctx->r13 = ctx->r2 & 0X10;
    // 0x80081C8C: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80081C90: bne         $at, $zero, L_80081CB8
    if (ctx->r1 != 0) {
        // 0x80081C94: nop
    
            goto L_80081CB8;
    }
    // 0x80081C94: nop

    // 0x80081C98: jal         0x8001BB58
    // 0x80081C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    is_prev_free(rdram, ctx);
        goto after_0;
    // 0x80081C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80081CA0: beq         $v0, $zero, L_80081CF0
    if (ctx->r2 == 0) {
        // 0x80081CA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80081CF0;
    }
    // 0x80081CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80081CA8: jal         0x800819E4
    // 0x80081CAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ovl_unload(rdram, ctx);
        goto after_1;
    // 0x80081CAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80081CB0: b           L_80081CF4
    // 0x80081CB4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80081CF4;
    // 0x80081CB4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80081CB8:
    // 0x80081CB8: bnel        $t5, $zero, L_80081CF4
    if (ctx->r13 != 0) {
        // 0x80081CBC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80081CF4;
    }
    goto skip_2;
    // 0x80081CBC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x80081CC0: jal         0x8001BAFC
    // 0x80081CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    defrag(rdram, ctx);
        goto after_2;
    // 0x80081CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80081CC8: beq         $v0, $s0, L_80081CF0
    if (ctx->r2 == ctx->r16) {
        // 0x80081CCC: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80081CF0;
    }
    // 0x80081CCC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80081CD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80081CD4: jal         0x80082494
    // 0x80081CD8: subu        $a1, $v0, $s0
    ctx->r5 = SUB32(ctx->r2, ctx->r16);
    ovl_shift(rdram, ctx);
        goto after_3;
    // 0x80081CD8: subu        $a1, $v0, $s0
    ctx->r5 = SUB32(ctx->r2, ctx->r16);
    after_3:
    // 0x80081CDC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80081CE0: lw          $t6, 0x7C68($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7C68);
    // 0x80081CE4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80081CE8: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80081CEC: sw          $s1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r17;
L_80081CF0:
    // 0x80081CF0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80081CF4:
    // 0x80081CF4: bne         $s2, $s5, L_80081C30
    if (ctx->r18 != ctx->r21) {
        // 0x80081CF8: nop
    
            goto L_80081C30;
    }
    // 0x80081CF8: nop

    // 0x80081CFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80081D00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081D04: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80081D08: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80081D0C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80081D10: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80081D14: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80081D18: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80081D1C: sw          $zero, 0x6CBC($at)
    MEM_W(0X6CBC, ctx->r1) = 0;
    // 0x80081D20: jr          $ra
    // 0x80081D24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80081D24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bsrest_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083970: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x80083970);
    return;
    // 0x80083974: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8010052C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010052C: jr          $ra
    // 0x80100530: nop

    return;
    // 0x80100530: nop

;}
RECOMP_FUNC void _sueggmisc_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A348: syscall     837
    recomp_syscall_handler(rdram, ctx, 0x8008A348);
    return;
    // 0x8008A34C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008FDEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FDEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FDF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FDF4: jal         0x800F54E4
    // 0x8008FDF8: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FDF8: nop

    after_0:
    // 0x8008FDFC: jal         0x800F56D8
    // 0x8008FE00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F56D8(rdram, ctx);
        goto after_1;
    // 0x8008FE00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FE04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FE08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FE0C: jr          $ra
    // 0x8008FE10: nop

    return;
    // 0x8008FE10: nop

;}
RECOMP_FUNC void func_80801F1C_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801F20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801F24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801F28: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801F2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801F30: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801F34: jal         0x80100094
    // 0x80801F38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801F38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801F3C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80801F40: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801F44: addiu       $t7, $t6, -0x15C5
    ctx->r15 = ADD32(ctx->r14, -0X15C5);
    // 0x80801F48: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x80801F4C: beq         $at, $zero, L_80802010
    if (ctx->r1 == 0) {
        // 0x80801F50: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80802010;
    }
    // 0x80801F50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801F54: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(924, 0X21A8) << 16);
    // 0x80801F58: addu        $at, $at, $t7
    gpr jr_addend_80801F60 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801F5C: lw          $t7, 0x21A8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(924, 0X21A8));
    // 0x80801F60: jr          $t7
    // 0x80801F64: nop

    switch (jr_addend_80801F60 >> 2) {
        case 0: goto L_80801F68; break;
        case 1: goto L_80801FE8; break;
        case 2: goto L_80801FE8; break;
        case 3: goto L_80801FE8; break;
        case 4: goto L_80801FE8; break;
        case 5: goto L_80802010; break;
        case 6: goto L_80801F94; break;
        default: switch_error(__func__, 0x80801F60, 0x808021A8);
    }
    // 0x80801F64: nop

L_80801F68:
    // 0x80801F68: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(924, 0X2350) << 16);
    // 0x80801F6C: addiu       $a1, $a1, 0x2350
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X2350));
    // 0x80801F70: jal         0x80802090
    // 0x80801F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802090_chevilspirit(rdram, ctx);
        goto after_1;
    // 0x80801F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F7C: jal         0x80102424
    // 0x80801F80: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80801F80: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x80801F84: jal         0x80089CB8
    // 0x80801F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80801F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801F8C: b           L_80802014
    // 0x80801F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802014;
    // 0x80801F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F94:
    // 0x80801F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F98: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80801F9C: jal         0x80102424
    // 0x80801FA0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80801FA0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x80801FA4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FAC: jal         0x8008A2C0
    // 0x80801FB0: addiu       $a1, $v1, 0x40
    ctx->r5 = ADD32(ctx->r3, 0X40);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80801FB0: addiu       $a1, $v1, 0x40
    ctx->r5 = ADD32(ctx->r3, 0X40);
    after_5:
    // 0x80801FB4: jal         0x800F54E4
    // 0x80801FB8: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80801FB8: nop

    after_6:
    // 0x80801FBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801FC0: jal         0x800F82D4
    // 0x80801FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_7;
    // 0x80801FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80801FC8: jal         0x800F54E4
    // 0x80801FCC: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80801FCC: nop

    after_8:
    // 0x80801FD0: jal         0x800878F8
    // 0x80801FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _plcamera_entrypoint_8(rdram, ctx);
        goto after_9;
    // 0x80801FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80801FD8: jal         0x800DA544
    // 0x80801FDC: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    func_800DA544(rdram, ctx);
        goto after_10;
    // 0x80801FDC: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    after_10:
    // 0x80801FE0: b           L_80802014
    // 0x80801FE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802014;
    // 0x80801FE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801FE8:
    // 0x80801FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FEC: jal         0x80102424
    // 0x80801FF0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80801FF0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_11:
    // 0x80801FF4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801FF8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801FFC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80802000: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802004: jal         0x800DC178
    // 0x80802008: nop

    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80802008: nop

    after_12:
    // 0x8080200C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80802010:
    // 0x80802010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802014:
    // 0x80802014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802018: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080201C: jr          $ra
    // 0x80802020: nop

    return;
    // 0x80802020: nop

;}
RECOMP_FUNC void func_808008B0_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808008B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808008BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808008C4: jal         0x80100094
    // 0x808008C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008CC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808008D0: jal         0x80800000
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chfantasycannon(rdram, ctx);
        goto after_1;
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808008D8: beq         $v0, $zero, L_8080092C
    if (ctx->r2 == 0) {
        // 0x808008DC: nop
    
            goto L_8080092C;
    }
    // 0x808008DC: nop

    // 0x808008E0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808008E4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808008E8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808008EC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808008F0: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x808008F4: beq         $at, $zero, L_80800910
    if (ctx->r1 == 0) {
        // 0x808008F8: addiu       $a2, $s1, 0x18
        ctx->r6 = ADD32(ctx->r17, 0X18);
            goto L_80800910;
    }
    // 0x808008F8: addiu       $a2, $s1, 0x18
    ctx->r6 = ADD32(ctx->r17, 0X18);
    // 0x808008FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800900: jal         0x800856A8
    // 0x80800904: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    _capod_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800904: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    after_2:
    // 0x80800908: b           L_808009A8
    // 0x8080090C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009A8;
    // 0x8080090C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800910:
    // 0x80800910: jal         0x800A516C
    // 0x80800914: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800A516C(rdram, ctx);
        goto after_3;
    // 0x80800914: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800918: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080091C: jal         0x800856A8
    // 0x80800920: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    _capod_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800920: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x80800924: b           L_808009A8
    // 0x80800928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009A8;
    // 0x80800928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080092C:
    // 0x8080092C: jal         0x800F54E4
    // 0x80800930: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800930: nop

    after_5:
    // 0x80800934: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800938: jal         0x800F5A00
    // 0x8080093C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F5A00(rdram, ctx);
        goto after_6;
    // 0x8080093C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x80800940: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800944: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800948: jal         0x800EEB40
    // 0x8080094C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EEB40(rdram, ctx);
        goto after_7;
    // 0x8080094C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80800950: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800954: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800958: jal         0x800EEB40
    // 0x8080095C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_8;
    // 0x8080095C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800960: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800964: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080096C: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800970: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    // 0x80800974: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800978: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8080097C: jal         0x800EFE50
    // 0x80800980: nop

    func_800EFE50(rdram, ctx);
        goto after_9;
    // 0x80800980: nop

    after_9:
    // 0x80800984: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x80800988: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080098C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800990: jal         0x800A516C
    // 0x80800994: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800A516C(rdram, ctx);
        goto after_10;
    // 0x80800994: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_10:
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080099C: jal         0x800856A8
    // 0x808009A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _capod_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x808009A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
    // 0x808009A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009A8:
    // 0x808009A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808009AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808009B0: jr          $ra
    // 0x808009B4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808009B4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8080057C_chicekeydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080057C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800580: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800584: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800588: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080058C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800590: jal         0x80101870
    // 0x80800594: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800594: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800598: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080059C: beql        $a0, $zero, L_80800624
    if (ctx->r4 == 0) {
        // 0x808005A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800624;
    }
    goto skip_0;
    // 0x808005A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808005A4: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x808005A8: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808005AC: bgezl       $t8, L_80800624
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808005B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800624;
    }
    goto skip_1;
    // 0x808005B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808005B4: jal         0x80106790
    // 0x808005B8: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808005B8: nop

    after_1:
    // 0x808005BC: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
    // 0x808005C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C8: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x808005CC: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
    // 0x808005D0: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    // 0x808005D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808005D8: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x808005DC: slti        $at, $t3, 0x6
    ctx->r1 = SIGNED(ctx->r11) < 0X6 ? 1 : 0;
    // 0x808005E0: bnel        $at, $zero, L_8080060C
    if (ctx->r1 != 0) {
        // 0x808005E4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080060C;
    }
    goto skip_2;
    // 0x808005E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x808005E8: jal         0x8008A0D8
    // 0x808005EC: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    _subaddieskeleton_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808005EC: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x808005F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808005F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005F8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808005FC: jal         0x800136E4
    // 0x80800600: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x80800600: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_3:
    // 0x80800604: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x80800608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8080060C:
    // 0x8080060C: jal         0x80101870
    // 0x80800610: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101870(rdram, ctx);
        goto after_4;
    // 0x80800610: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800614: lbu         $t4, 0x65($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X65);
    // 0x80800618: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x8080061C: sb          $t5, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r13;
    // 0x80800620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800624:
    // 0x80800624: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800628: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080062C: jr          $ra
    // 0x80800630: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800630: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800BF8_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C00: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800C04: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800C08: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800C0C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800C10: bgez        $t8, L_80800C28
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800C14: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800C28;
    }
    // 0x80800C14: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800C18: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800C1C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C20: b           L_80800C38
    // 0x80800C24: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
        goto L_80800C38;
    // 0x80800C24: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
L_80800C28:
    // 0x80800C28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800C2C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C30: nop

    // 0x80800C34: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
L_80800C38:
    // 0x80800C38: jal         0x800EEB40
    // 0x80800C3C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_800EEB40(rdram, ctx);
        goto after_0;
    // 0x80800C3C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80800C40: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800C44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C48: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800C4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C54: mul.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80800C58: nop

    // 0x80800C5C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800C60: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800C64: nop

    // 0x80800C68: bc1f        L_80800C74
    if (!c1cs) {
        // 0x80800C6C: nop
    
            goto L_80800C74;
    }
    // 0x80800C6C: nop

    // 0x80800C70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C74:
    // 0x80800C74: jr          $ra
    // 0x80800C78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800C78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808006F4_bstaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808006F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800700: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800704: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80800708: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8080070C: jal         0x800852F0
    // 0x80800710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x80800710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800718: jal         0x80085300
    // 0x8080071C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_1;
    // 0x8080071C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800720: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800724: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80800728: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080072C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800730: jal         0x800D2498
    // 0x80800734: nop

    func_800D2498(rdram, ctx);
        goto after_2;
    // 0x80800734: nop

    after_2:
    // 0x80800738: jal         0x80800524
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800524_bstaxi(rdram, ctx);
        goto after_3;
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800740: jal         0x8001210C
    // 0x80800744: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_4;
    // 0x80800744: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800748: beql        $v0, $zero, L_80800798
    if (ctx->r2 == 0) {
        // 0x8080074C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800798;
    }
    goto skip_0;
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800750: jal         0x800B5BE4
    // 0x80800754: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800B5BE4(rdram, ctx);
        goto after_5;
    // 0x80800754: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_5:
    // 0x80800758: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800760: jal         0x800F3BB0
    // 0x80800764: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800F3BB0(rdram, ctx);
        goto after_6;
    // 0x80800764: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x80800768: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(392, 0X2140) << 16);
    // 0x8080076C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800770: addiu       $t7, $t7, 0x2140
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(392, 0X2140));
    // 0x80800774: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800778: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080077C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800780: jal         0x800BABB8
    // 0x80800784: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800784: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x80800788: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080078C: jal         0x800BA22C
    // 0x80800790: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_8;
    // 0x80800790: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800798:
    // 0x80800798: jal         0x80085330
    // 0x8080079C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isZero(rdram, ctx);
        goto after_9;
    // 0x8080079C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808007A0: beq         $v0, $zero, L_808007BC
    if (ctx->r2 == 0) {
        // 0x808007A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007BC;
    }
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808007AC: addiu       $t9, $zero, 0x2F
    ctx->r25 = ADD32(0, 0X2F);
    // 0x808007B0: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x808007B4: b           L_808007D8
    // 0x808007B8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_808007D8;
    // 0x808007B8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_808007BC:
    // 0x808007BC: jal         0x80091A58
    // 0x808007C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_10;
    // 0x808007C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_10:
    // 0x808007C4: beq         $v0, $zero, L_808007D8
    if (ctx->r2 == 0) {
        // 0x808007C8: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_808007D8;
    }
    // 0x808007C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808007CC: addiu       $t1, $zero, 0x2F
    ctx->r9 = ADD32(0, 0X2F);
    // 0x808007D0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x808007D4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_808007D8:
    // 0x808007D8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x808007DC: beql        $t2, $zero, L_808007F0
    if (ctx->r10 == 0) {
        // 0x808007E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007F0;
    }
    goto skip_1;
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808007E4: jal         0x80800420
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800420_bstaxi(rdram, ctx);
        goto after_11;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007F0:
    // 0x808007F0: jal         0x8009E5C8
    // 0x808007F4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x808007F4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_12:
    // 0x808007F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800800: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800804: jr          $ra
    // 0x80800808: nop

    return;
    // 0x80800808: nop

;}
RECOMP_FUNC void func_800D61B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D61B4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D61B8: addiu       $t6, $t6, -0x4800
    ctx->r14 = ADD32(ctx->r14, -0X4800);
    // 0x800D61BC: subu        $t7, $a0, $t6
    ctx->r15 = SUB32(ctx->r4, ctx->r14);
    // 0x800D61C0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800D61C4: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800D61C8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800D61CC: addiu       $a3, $a3, -0x419E
    ctx->r7 = ADD32(ctx->r7, -0X419E);
    // 0x800D61D0: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x800D61D4: mflo        $t8
    ctx->r24 = lo;
    // 0x800D61D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D61DC: subu        $v0, $v1, $t8
    ctx->r2 = SUB32(ctx->r3, ctx->r24);
    // 0x800D61E0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D61E4: blez        $v0, L_800D620C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D61E8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D620C;
    }
    // 0x800D61E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D61EC: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x800D61F0: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800D61F4: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800D61F8: jal         0x8001BC68
    // 0x800D61FC: addiu       $a1, $a0, 0xC
    ctx->r5 = ADD32(ctx->r4, 0XC);
    aligned4_memmove(rdram, ctx);
        goto after_0;
    // 0x800D61FC: addiu       $a1, $a0, 0xC
    ctx->r5 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800D6200: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800D6204: addiu       $a3, $a3, -0x419E
    ctx->r7 = ADD32(ctx->r7, -0X419E);
    // 0x800D6208: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
L_800D620C:
    // 0x800D620C: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x800D6210: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x800D6214: lh          $t0, 0x0($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X0);
    // 0x800D6218: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800D621C: addiu       $t2, $t2, -0x4800
    ctx->r10 = ADD32(ctx->r10, -0X4800);
    // 0x800D6220: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800D6224: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800D6228: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800D622C: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x800D6230: lbu         $t3, 0x3($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X3);
    // 0x800D6234: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    // 0x800D6238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D623C: andi        $t4, $t3, 0xFFE1
    ctx->r12 = ctx->r11 & 0XFFE1;
    // 0x800D6240: ori         $t7, $t6, 0xFFFC
    ctx->r15 = ctx->r14 | 0XFFFC;
    // 0x800D6244: sb          $t4, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r12;
    // 0x800D6248: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x800D624C: jr          $ra
    // 0x800D6250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D6250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80803BE8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803BE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803BEC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80803BF0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80803BF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803BF8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80803BFC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80803C00: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80803C04: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80803C08: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80803C0C: jal         0x80100094
    // 0x80803C10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803C10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803C14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80803C18: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80803C1C: beq         $s1, $at, L_80803C30
    if (ctx->r17 == ctx->r1) {
        // 0x80803C20: sh          $s0, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r16;
            goto L_80803C30;
    }
    // 0x80803C20: sh          $s0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r16;
    // 0x80803C24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803C28: jal         0x80800180
    // 0x80803C2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80803C2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
L_80803C30:
    // 0x80803C30: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80803C34: beq         $s0, $at, L_80803C60
    if (ctx->r16 == ctx->r1) {
        // 0x80803C38: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80803C60;
    }
    // 0x80803C38: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80803C3C: beq         $s0, $at, L_80803CAC
    if (ctx->r16 == ctx->r1) {
        // 0x80803C40: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_80803CAC;
    }
    // 0x80803C40: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80803C44: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80803C48: beq         $s0, $at, L_80803CF0
    if (ctx->r16 == ctx->r1) {
        // 0x80803C4C: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_80803CF0;
    }
    // 0x80803C4C: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x80803C50: beq         $s0, $at, L_80803D50
    if (ctx->r16 == ctx->r1) {
        // 0x80803C54: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_80803D50;
    }
    // 0x80803C54: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80803C58: b           L_80803DB0
    // 0x80803C5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803DB0;
    // 0x80803C5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803C60:
    // 0x80803C60: jal         0x80802228
    // 0x80803C64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80803C64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80803C68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803C6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803C70: jal         0x80805448
    // 0x80803C74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80803C74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80803C78: jal         0x80802228
    // 0x80803C7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80803C7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80803C80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803C84: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80803C88: jal         0x80805448
    // 0x80803C8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80803C8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80803C90: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80803C94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80803C98: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80803C9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803CA0: swc1        $f2, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f2.u32l;
    // 0x80803CA4: b           L_80803DAC
    // 0x80803CA8: swc1        $f4, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f4.u32l;
        goto L_80803DAC;
    // 0x80803CA8: swc1        $f4, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f4.u32l;
L_80803CAC:
    // 0x80803CAC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80803CB0:
    // 0x80803CB0: jal         0x80802228
    // 0x80803CB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80803CB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80803CB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803CBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803CC0: jal         0x80805448
    // 0x80803CC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x80803CC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80803CC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80803CCC: bne         $s0, $s1, L_80803CB0
    if (ctx->r16 != ctx->r17) {
        // 0x80803CD0: nop
    
            goto L_80803CB0;
    }
    // 0x80803CD0: nop

    // 0x80803CD4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80803CD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803CDC: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x80803CE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803CE4: swc1        $f6, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f6.u32l;
    // 0x80803CE8: b           L_80803DAC
    // 0x80803CEC: swc1        $f8, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f8.u32l;
        goto L_80803DAC;
    // 0x80803CEC: swc1        $f8, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f8.u32l;
L_80803CF0:
    // 0x80803CF0: jal         0x80802228
    // 0x80803CF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80803CF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x80803CF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803D00: jal         0x80805448
    // 0x80803D04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80803D04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80803D08: jal         0x80802228
    // 0x80803D0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x80803D0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x80803D10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803D14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80803D18: jal         0x80805448
    // 0x80803D1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x80803D1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80803D20: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80803D24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803D28: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80803D2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80803D30: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80803D34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803D38: swc1        $f0, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->f0.u32l;
    // 0x80803D3C: swc1        $f0, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->f0.u32l;
    // 0x80803D40: swc1        $f2, 0x3C($s3)
    MEM_W(0X3C, ctx->r19) = ctx->f2.u32l;
    // 0x80803D44: swc1        $f2, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f2.u32l;
    // 0x80803D48: b           L_80803DAC
    // 0x80803D4C: swc1        $f10, 0x38($s3)
    MEM_W(0X38, ctx->r19) = ctx->f10.u32l;
        goto L_80803DAC;
    // 0x80803D4C: swc1        $f10, 0x38($s3)
    MEM_W(0X38, ctx->r19) = ctx->f10.u32l;
L_80803D50:
    // 0x80803D50: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80803D54:
    // 0x80803D54: jal         0x80802228
    // 0x80803D58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x80803D58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x80803D5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803D60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803D64: jal         0x80805448
    // 0x80803D68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_13;
    // 0x80803D68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80803D6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80803D70: bne         $s0, $s1, L_80803D54
    if (ctx->r16 != ctx->r17) {
        // 0x80803D74: nop
    
            goto L_80803D54;
    }
    // 0x80803D74: nop

    // 0x80803D78: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80803D7C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803D80: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80803D84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80803D88: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80803D8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803D90: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x80803D94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803D98: swc1        $f0, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->f0.u32l;
    // 0x80803D9C: swc1        $f0, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->f0.u32l;
    // 0x80803DA0: swc1        $f16, 0x3C($s3)
    MEM_W(0X3C, ctx->r19) = ctx->f16.u32l;
    // 0x80803DA4: swc1        $f18, 0x38($s3)
    MEM_W(0X38, ctx->r19) = ctx->f18.u32l;
    // 0x80803DA8: swc1        $f4, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f4.u32l;
L_80803DAC:
    // 0x80803DAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803DB0:
    // 0x80803DB0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80803DB4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80803DB8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80803DBC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80803DC0: jr          $ra
    // 0x80803DC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80803DC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080097C_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080097C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800984: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080098C: jal         0x8008CABC
    // 0x80800990: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800990: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800994: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800998: jal         0x800852C0
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808009A0: jal         0x800852C8
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808009A8: jal         0x800852D0
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B4: jal         0x800852B8
    // 0x808009B8: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x808009B8: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_4:
    // 0x808009BC: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
    // 0x808009C0: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x808009C4: jal         0x8008B348
    // 0x808009C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x808009C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808009CC: beq         $v0, $zero, L_808009E8
    if (ctx->r2 == 0) {
        // 0x808009D0: lui         $a2, 0x3FF3
        ctx->r6 = S32(0X3FF3 << 16);
            goto L_808009E8;
    }
    // 0x808009D0: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x808009D4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808009D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009DC: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    // 0x808009E0: jal         0x8009DF18
    // 0x808009E4: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DF18(rdram, ctx);
        goto after_6;
    // 0x808009E4: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_6:
L_808009E8:
    // 0x808009E8: lui         $a1, 0x3F2B
    ctx->r5 = S32(0X3F2B << 16);
    // 0x808009EC: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x808009F0: jal         0x8008B348
    // 0x808009F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x808009F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x808009F8: beq         $v0, $zero, L_80800A14
    if (ctx->r2 == 0) {
        // 0x808009FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A14;
    }
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A00: lui         $a2, 0x3FD9
    ctx->r6 = S32(0X3FD9 << 16);
    // 0x80800A04: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800A08: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    // 0x80800A0C: jal         0x8009DF18
    // 0x80800A10: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DF18(rdram, ctx);
        goto after_8;
    // 0x80800A10: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_8:
L_80800A14:
    // 0x80800A14: jal         0x80085280
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800A1C: beq         $v0, $zero, L_80800A4C
    if (ctx->r2 == 0) {
        // 0x80800A20: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800A4C;
    }
    // 0x80800A20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A28: beq         $v0, $at, L_80800A74
    if (ctx->r2 == ctx->r1) {
        // 0x80800A2C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A74;
    }
    // 0x80800A2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A30: beq         $v0, $at, L_80800A68
    if (ctx->r2 == ctx->r1) {
        // 0x80800A34: addiu       $t7, $zero, 0x2C
        ctx->r15 = ADD32(0, 0X2C);
            goto L_80800A68;
    }
    // 0x80800A34: addiu       $t7, $zero, 0x2C
    ctx->r15 = ADD32(0, 0X2C);
    // 0x80800A38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A3C: beq         $v0, $at, L_80800A70
    if (ctx->r2 == ctx->r1) {
        // 0x80800A40: addiu       $t8, $zero, 0x19
        ctx->r24 = ADD32(0, 0X19);
            goto L_80800A70;
    }
    // 0x80800A40: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    // 0x80800A44: b           L_80800A74
    // 0x80800A48: nop

        goto L_80800A74;
    // 0x80800A48: nop

L_80800A4C:
    // 0x80800A4C: lui         $a1, 0x3EF5
    ctx->r5 = S32(0X3EF5 << 16);
    // 0x80800A50: jal         0x8008B348
    // 0x80800A54: ori         $a1, $a1, 0x4C98
    ctx->r5 = ctx->r5 | 0X4C98;
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x80800A54: ori         $a1, $a1, 0x4C98
    ctx->r5 = ctx->r5 | 0X4C98;
    after_10:
    // 0x80800A58: beq         $v0, $zero, L_80800A74
    if (ctx->r2 == 0) {
        // 0x80800A5C: addiu       $t6, $zero, 0x2B
        ctx->r14 = ADD32(0, 0X2B);
            goto L_80800A74;
    }
    // 0x80800A5C: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x80800A60: b           L_80800A74
    // 0x80800A64: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_80800A74;
    // 0x80800A64: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800A68:
    // 0x80800A68: b           L_80800A74
    // 0x80800A6C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80800A74;
    // 0x80800A6C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800A70:
    // 0x80800A70: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800A74:
    // 0x80800A74: jal         0x8009803C
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_8009803C(rdram, ctx);
        goto after_11;
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800A7C: beq         $v0, $zero, L_80800A88
    if (ctx->r2 == 0) {
        // 0x80800A80: addiu       $t9, $zero, 0x157
        ctx->r25 = ADD32(0, 0X157);
            goto L_80800A88;
    }
    // 0x80800A80: addiu       $t9, $zero, 0x157
    ctx->r25 = ADD32(0, 0X157);
    // 0x80800A84: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800A88:
    // 0x80800A88: jal         0x80085278
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800A90: beq         $v0, $zero, L_80800A9C
    if (ctx->r2 == 0) {
        // 0x80800A94: addiu       $t0, $zero, 0x2D
        ctx->r8 = ADD32(0, 0X2D);
            goto L_80800A9C;
    }
    // 0x80800A94: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x80800A98: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80800A9C:
    // 0x80800A9C: jal         0x8008E35C
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_13;
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800AA4: bne         $v0, $zero, L_80800AB4
    if (ctx->r2 != 0) {
        // 0x80800AA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AB4;
    }
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AAC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800AB0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80800AB4:
    // 0x80800AB4: jal         0x8009E5C8
    // 0x80800AB8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_14;
    // 0x80800AB8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x80800ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800AC8: jr          $ra
    // 0x80800ACC: nop

    return;
    // 0x80800ACC: nop

;}
RECOMP_FUNC void func_808002D8_chflysaucercrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E0: lbu         $a2, 0x5F($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X5F);
    // 0x808002E4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808002E8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002EC: bne         $a2, $zero, L_80800318
    if (ctx->r6 != 0) {
        // 0x808002F0: andi        $a0, $a2, 0xFF
        ctx->r4 = ctx->r6 & 0XFF;
            goto L_80800318;
    }
    // 0x808002F0: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x808002F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1696, 0XDD0) << 16);
    // 0x808002F8: addiu       $a2, $a2, 0xDD0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1696, 0XDD0));
    // 0x808002FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800300: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80800304: jal         0x800C4350
    // 0x80800308: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x80800308: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080030C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800310: b           L_80800338
    // 0x80800314: sb          $v0, 0x5F($a3)
    MEM_B(0X5F, ctx->r7) = ctx->r2;
        goto L_80800338;
    // 0x80800314: sb          $v0, 0x5F($a3)
    MEM_B(0X5F, ctx->r7) = ctx->r2;
L_80800318:
    // 0x80800318: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8080031C: jal         0x800C31DC
    // 0x80800320: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800C31DC(rdram, ctx);
        goto after_1;
    // 0x80800320: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800324: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800328: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080032C: lbu         $a0, 0x5F($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X5F);
    // 0x80800330: jal         0x800C4350
    // 0x80800334: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    func_800C4350(rdram, ctx);
        goto after_2;
    // 0x80800334: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    after_2:
L_80800338:
    // 0x80800338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080033C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800340: jr          $ra
    // 0x80800344: nop

    return;
    // 0x80800344: nop

;}
RECOMP_FUNC void func_800A56A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A56A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A56A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A56AC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A56B0: addiu       $s2, $s2, -0x6AC0
    ctx->r18 = ADD32(ctx->r18, -0X6AC0);
    // 0x800A56B4: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800A56B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A56BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A56C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A56C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A56C8: beq         $a1, $zero, L_800A5770
    if (ctx->r5 == 0) {
        // 0x800A56CC: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800A5770;
    }
    // 0x800A56CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A56D0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800A56D4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x800A56D8: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
L_800A56DC:
    // 0x800A56DC: addu        $t6, $a1, $s1
    ctx->r14 = ADD32(ctx->r5, ctx->r17);
    // 0x800A56E0: lh          $a0, 0x1E($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X1E);
    // 0x800A56E4: beql        $a0, $zero, L_800A5714
    if (ctx->r4 == 0) {
        // 0x800A56E8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800A5714;
    }
    goto skip_0;
    // 0x800A56E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800A56EC: jal         0x8001B754
    // 0x800A56F0: sll         $s3, $s0, 2
    ctx->r19 = S32(ctx->r16 << 2);
    func_8001B754(rdram, ctx);
        goto after_0;
    // 0x800A56F0: sll         $s3, $s0, 2
    ctx->r19 = S32(ctx->r16 << 2);
    after_0:
    // 0x800A56F4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800A56F8: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800A56FC: sh          $zero, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = 0;
    // 0x800A5700: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A5704: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x800A5708: sw          $zero, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = 0;
    // 0x800A570C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800A5710: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800A5714:
    // 0x800A5714: bne         $s0, $s4, L_800A56DC
    if (ctx->r16 != ctx->r20) {
        // 0x800A5718: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800A56DC;
    }
    // 0x800A5718: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800A571C: lw          $t1, 0x38($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X38);
    // 0x800A5720: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A5724: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A5728: bltz        $t1, L_800A5764
    if (SIGNED(ctx->r9) < 0) {
        // 0x800A572C: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_800A5764;
    }
    // 0x800A572C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A5730: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800A5734: addu        $t2, $a1, $v0
    ctx->r10 = ADD32(ctx->r5, ctx->r2);
L_800A5738:
    // 0x800A5738: sb          $zero, 0x3C($t2)
    MEM_B(0X3C, ctx->r10) = 0;
    // 0x800A573C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A5740: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A5744: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800A5748: sb          $a0, 0x3D($t4)
    MEM_B(0X3D, ctx->r12) = ctx->r4;
    // 0x800A574C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800A5750: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800A5754: lw          $t5, 0x38($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X38);
    // 0x800A5758: slt         $at, $t5, $v1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A575C: beql        $at, $zero, L_800A5738
    if (ctx->r1 == 0) {
        // 0x800A5760: addu        $t2, $a1, $v0
        ctx->r10 = ADD32(ctx->r5, ctx->r2);
            goto L_800A5738;
    }
    goto skip_1;
    // 0x800A5760: addu        $t2, $a1, $v0
    ctx->r10 = ADD32(ctx->r5, ctx->r2);
    skip_1:
L_800A5764:
    // 0x800A5764: sw          $t6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r14;
    // 0x800A5768: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800A576C: sw          $zero, 0x34($t7)
    MEM_W(0X34, ctx->r15) = 0;
L_800A5770:
    // 0x800A5770: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5774: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A5778: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A577C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A5780: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A5784: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A5788: jr          $ra
    // 0x800A578C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A578C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chtntbox_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F58: syscall     481
    recomp_syscall_handler(rdram, ctx, 0x80086F58);
    return;
    // 0x80086F5C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gsmaker_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080013C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800140: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800144: jal         0x8001ACCC
    // 0x80800148: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x80800148: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_0:
    // 0x8080014C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800150: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80800154: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800158: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x8080015C: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x80800160: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x80800164: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    // 0x80800168: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x8080016C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800170: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80800174: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x80800178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080017C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void func_80800118_chdiggergroundgen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8080011C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800120: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80800124: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800128: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8080012C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80800130: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80800134: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80800138: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8080013C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80800140: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80800144: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800148: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080014C: jal         0x80100094
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800154: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80800158: jal         0x8010CD28
    // 0x8080015C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8010CD28(rdram, ctx);
        goto after_1;
    // 0x8080015C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80800160: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800164: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800168: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080016C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800170: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800174: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800178: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8080017C: addiu       $s1, $s3, 0x4
    ctx->r17 = ADD32(ctx->r19, 0X4);
    // 0x80800180: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80800184: addiu       $s0, $sp, 0x94
    ctx->r16 = ADD32(ctx->r29, 0X94);
L_80800188:
    // 0x80800188: jal         0x800DC0C0
    // 0x8080018C: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x8080018C: nop

    after_2:
    // 0x80800190: mul.s       $f12, $f0, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80800194: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80800198: jal         0x800F2094
    // 0x8080019C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    func_800F2094(rdram, ctx);
        goto after_3;
    // 0x8080019C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    after_3:
    // 0x808001A0: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x808001A4: nop

    // 0x808001A8: bc1t        L_80800188
    if (c1cs) {
        // 0x808001AC: nop
    
            goto L_80800188;
    }
    // 0x808001AC: nop

    // 0x808001B0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808001B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001B8: jal         0x800DC178
    // 0x808001BC: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808001BC: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    after_4:
    // 0x808001C0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x800EE7F8
    // 0x808001CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808001CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x808001D0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808001D4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808001D8: jal         0x800EF1B8
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001E0: lw          $a1, 0x70($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X70);
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001EC: srl         $t6, $a1, 25
    ctx->r14 = S32(U32(ctx->r5) >> 25);
    // 0x808001F0: jal         0x800CC338
    // 0x808001F4: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    func_800CC338(rdram, ctx);
        goto after_7;
    // 0x808001F4: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    after_7:
    // 0x808001F8: beq         $v0, $s2, L_80800188
    if (ctx->r2 == ctx->r18) {
        // 0x808001FC: nop
    
            goto L_80800188;
    }
    // 0x808001FC: nop

    // 0x80800200: addiu       $s1, $sp, 0x84
    ctx->r17 = ADD32(ctx->r29, 0X84);
    // 0x80800204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800208: jal         0x800EE7F8
    // 0x8080020C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x8080020C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80800210: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x80800214: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800218: jal         0x800EE7F8
    // 0x8080021C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x8080021C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80800220: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800224: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800228: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8080022C: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80800230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800234: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800238: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8080023C: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x80800240: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800244: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x80800248: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x8080024C: jal         0x800BEF00
    // 0x80800250: lw          $a3, 0x14($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_10;
    // 0x80800250: lw          $a3, 0x14($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X14);
    after_10:
    // 0x80800254: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80800258: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8080025C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800260: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x80800264: jal         0x800EE7F8
    // 0x80800268: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80800268: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_11:
    // 0x8080026C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800270: jal         0x80108B04
    // 0x80800274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_12;
    // 0x80800274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800278: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080027C: jal         0x80101FDC
    // 0x80800280: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x80800280: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x80800284: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(860, 0X4E0) << 16);
    // 0x80800288: lwc1        $f18, 0x4E0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(860, 0X4E0));
    // 0x8080028C: swc1        $f18, 0x58($s3)
    MEM_W(0X58, ctx->r19) = ctx->f18.u32l;
    // 0x80800290: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80800294: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80800298: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8080029C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x808002A0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x808002A4: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x808002A8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x808002AC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x808002B0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x808002B4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808002B8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808002BC: jr          $ra
    // 0x808002C0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x808002C0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void _subaddiefade_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CD0: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CD0);
    return;
    // 0x80089CD4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800CF4_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800CF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D00: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800D04: jal         0x80102FDC
    // 0x80800D08: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800D08: nop

    after_0:
    // 0x80800D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800D18: jr          $ra
    // 0x80800D1C: nop

    return;
    // 0x80800D1C: nop

;}
RECOMP_FUNC void func_80804F38_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804F38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804F3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804F40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804F44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80804F48: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80804F4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804F50: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80804F54: sltiu       $at, $v0, 0xC
    ctx->r1 = ctx->r2 < 0XC ? 1 : 0;
    // 0x80804F58: beq         $at, $zero, L_80805194
    if (ctx->r1 == 0) {
        // 0x80804F5C: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80805194;
    }
    // 0x80804F5C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80804F60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7D08) << 16);
    // 0x80804F64: addu        $at, $at, $t6
    gpr jr_addend_80804F6C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80804F68: lw          $t6, 0x7D08($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(804, 0X7D08));
    // 0x80804F6C: jr          $t6
    // 0x80804F70: nop

    switch (jr_addend_80804F6C >> 2) {
        case 0: goto L_80804F74; break;
        case 1: goto L_80804FF0; break;
        case 2: goto L_80805044; break;
        case 3: goto L_8080510C; break;
        case 4: goto L_80805194; break;
        case 5: goto L_80805168; break;
        case 6: goto L_80805168; break;
        case 7: goto L_80805168; break;
        case 8: goto L_808050FC; break;
        case 9: goto L_80805194; break;
        case 10: goto L_808050C4; break;
        case 11: goto L_808050E0; break;
        default: switch_error(__func__, 0x80804F6C, 0x80807D08);
    }
    // 0x80804F70: nop

L_80804F74:
    // 0x80804F74: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80804F78: jal         0x80802BE8
    // 0x80804F7C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80802BE8_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804F7C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80804F80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80804F84: jal         0x80088320
    // 0x80804F88: addiu       $a0, $a3, 0x2
    ctx->r4 = ADD32(ctx->r7, 0X2);
    _gcstatusDll_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80804F88: addiu       $a0, $a3, 0x2
    ctx->r4 = ADD32(ctx->r7, 0X2);
    after_1:
    // 0x80804F8C: jal         0x808068E8
    // 0x80804F90: nop

    func_808068E8_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80804F90: nop

    after_2:
    // 0x80804F94: jal         0x808069C8
    // 0x80804F98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808069C8_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80804F98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80804F9C: jal         0x80806A30
    // 0x80804FA0: nop

    func_80806A30_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80804FA0: nop

    after_4:
    // 0x80804FA4: jal         0x80806A88
    // 0x80804FA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80806A88_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80804FA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80804FAC: jal         0x80088360
    // 0x80804FB0: nop

    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80804FB0: nop

    after_6:
    // 0x80804FB4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80804FB8: beql        $at, $zero, L_80804FE0
    if (ctx->r1 == 0) {
        // 0x80804FBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804FE0;
    }
    goto skip_0;
    // 0x80804FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80804FC0: jal         0x80088380
    // 0x80804FC4: nop

    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_7;
    // 0x80804FC4: nop

    after_7:
    // 0x80804FC8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80804FCC: bnel        $v0, $at, L_80804FE0
    if (ctx->r2 != ctx->r1) {
        // 0x80804FD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804FE0;
    }
    goto skip_1;
    // 0x80804FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80804FD4: jal         0x80088330
    // 0x80804FD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80804FD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80804FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804FE0:
    // 0x80804FE0: jal         0x80805474
    // 0x80804FE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80805474_chgameselect(rdram, ctx);
        goto after_9;
    // 0x80804FE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80804FE8: b           L_808051A4
    // 0x80804FEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x80804FEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804FF0:
    // 0x80804FF0: beq         $a3, $zero, L_80805014
    if (ctx->r7 == 0) {
        // 0x80804FF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805014;
    }
    // 0x80804FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804FF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804FFC: beq         $a3, $at, L_80805024
    if (ctx->r7 == ctx->r1) {
        // 0x80805000: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80805024;
    }
    // 0x80805000: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805004: beq         $a3, $at, L_80805034
    if (ctx->r7 == ctx->r1) {
        // 0x80805008: nop
    
            goto L_80805034;
    }
    // 0x80805008: nop

    // 0x8080500C: b           L_808051A4
    // 0x80805010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x80805010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805014:
    // 0x80805014: jal         0x80805BFC
    // 0x80805018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80805BFC_chgameselect(rdram, ctx);
        goto after_10;
    // 0x80805018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8080501C: b           L_808051A4
    // 0x80805020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x80805020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805024:
    // 0x80805024: jal         0x80806408
    // 0x80805028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80806408_chgameselect(rdram, ctx);
        goto after_11;
    // 0x80805028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080502C: b           L_808051A4
    // 0x80805030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x80805030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805034:
    // 0x80805034: jal         0x80806540
    // 0x80805038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80806540_chgameselect(rdram, ctx);
        goto after_12;
    // 0x80805038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080503C: b           L_808051A4
    // 0x80805040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x80805040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805044:
    // 0x80805044: sw          $a3, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r7;
    // 0x80805048: jal         0x80088160
    // 0x8080504C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _gcfrontend_entrypoint_6(rdram, ctx);
        goto after_13;
    // 0x8080504C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_13:
    // 0x80805050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805054: beq         $v0, $at, L_8080507C
    if (ctx->r2 == ctx->r1) {
        // 0x80805058: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080507C;
    }
    // 0x80805058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080505C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805060: beq         $v0, $at, L_8080508C
    if (ctx->r2 == ctx->r1) {
        // 0x80805064: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080508C;
    }
    // 0x80805064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805068: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080506C: beq         $v0, $at, L_808050A0
    if (ctx->r2 == ctx->r1) {
        // 0x80805070: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808050A0;
    }
    // 0x80805070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805074: b           L_808050B4
    // 0x80805078: nop

        goto L_808050B4;
    // 0x80805078: nop

L_8080507C:
    // 0x8080507C: jal         0x80805CD8
    // 0x80805080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80805CD8_chgameselect(rdram, ctx);
        goto after_14;
    // 0x80805080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80805084: b           L_808051A4
    // 0x80805088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x80805088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080508C:
    // 0x8080508C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80805090: jal         0x8080537C
    // 0x80805094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080537C_chgameselect(rdram, ctx);
        goto after_15;
    // 0x80805094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80805098: b           L_808051A4
    // 0x8080509C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x8080509C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808050A0:
    // 0x808050A0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x808050A4: jal         0x8080537C
    // 0x808050A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080537C_chgameselect(rdram, ctx);
        goto after_16;
    // 0x808050A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x808050AC: b           L_808051A4
    // 0x808050B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x808050B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808050B4:
    // 0x808050B4: jal         0x80803BE8
    // 0x808050B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803BE8_chgameselect(rdram, ctx);
        goto after_17;
    // 0x808050B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808050BC: b           L_808051A4
    // 0x808050C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x808050C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808050C4:
    // 0x808050C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808050C8: jal         0x80805F30
    // 0x808050CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80805F30_chgameselect(rdram, ctx);
        goto after_18;
    // 0x808050CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_18:
    // 0x808050D0: jal         0x80803BE8
    // 0x808050D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803BE8_chgameselect(rdram, ctx);
        goto after_19;
    // 0x808050D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808050D8: b           L_808051A4
    // 0x808050DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x808050DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808050E0:
    // 0x808050E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808050E4: jal         0x80805FCC
    // 0x808050E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80805FCC_chgameselect(rdram, ctx);
        goto after_20;
    // 0x808050E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_20:
    // 0x808050EC: jal         0x80803BE8
    // 0x808050F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803BE8_chgameselect(rdram, ctx);
        goto after_21;
    // 0x808050F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808050F4: b           L_808051A4
    // 0x808050F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x808050F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808050FC:
    // 0x808050FC: jal         0x80806744
    // 0x80805100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80806744_chgameselect(rdram, ctx);
        goto after_22;
    // 0x80805100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80805104: b           L_808051A4
    // 0x80805108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x80805108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080510C:
    // 0x8080510C: beq         $a3, $zero, L_80805124
    if (ctx->r7 == 0) {
        // 0x80805110: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80805124;
    }
    // 0x80805110: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805114: beq         $a3, $at, L_80805134
    if (ctx->r7 == ctx->r1) {
        // 0x80805118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805134;
    }
    // 0x80805118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080511C: b           L_80805144
    // 0x80805120: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
        goto L_80805144;
    // 0x80805120: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80805124:
    // 0x80805124: jal         0x808061A8
    // 0x80805128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808061A8_chgameselect(rdram, ctx);
        goto after_23;
    // 0x80805128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x8080512C: b           L_808051A4
    // 0x80805130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x80805130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805134:
    // 0x80805134: jal         0x80806834
    // 0x80805138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80806834_chgameselect(rdram, ctx);
        goto after_24;
    // 0x80805138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8080513C: b           L_808051A4
    // 0x80805140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x80805140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805144:
    // 0x80805144: jal         0x80805ECC
    // 0x80805148: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80805ECC_chgameselect(rdram, ctx);
        goto after_25;
    // 0x80805148: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_25:
    // 0x8080514C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80805150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805154: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80805158: jal         0x8080537C
    // 0x8080515C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    func_8080537C_chgameselect(rdram, ctx);
        goto after_26;
    // 0x8080515C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    after_26:
    // 0x80805160: b           L_808051A4
    // 0x80805164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x80805164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805168:
    // 0x80805168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080516C: addiu       $a1, $v0, -0x4
    ctx->r5 = ADD32(ctx->r2, -0X4);
    // 0x80805170: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80805174: jal         0x80806068
    // 0x80805178: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80806068_chgameselect(rdram, ctx);
        goto after_27;
    // 0x80805178: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_27:
    // 0x8080517C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80805180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805184: jal         0x808051B4
    // 0x80805188: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808051B4_chgameselect(rdram, ctx);
        goto after_28;
    // 0x80805188: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_28:
    // 0x8080518C: b           L_808051A4
    // 0x80805190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808051A4;
    // 0x80805190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805194:
    // 0x80805194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805198: jal         0x80800478
    // 0x8080519C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800478_chgameselect(rdram, ctx);
        goto after_29;
    // 0x8080519C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x808051A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808051A4:
    // 0x808051A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808051A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808051AC: jr          $ra
    // 0x808051B0: nop

    return;
    // 0x808051B0: nop

;}
RECOMP_FUNC void subaddieDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080033C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800340: jal         0x80106790
    // 0x80800344: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800344: nop

    after_0:
    // 0x80800348: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080034C: jal         0x8010A570
    // 0x80800350: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x80800350: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800358: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8080035C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800360: jr          $ra
    // 0x80800364: nop

    return;
    // 0x80800364: nop

;}
RECOMP_FUNC void chblink_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800330: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800334: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800338: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080033C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80800340: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800344: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800348: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8080034C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800350: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800354: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800358: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8080035C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800360: jal         0x8001B798
    // 0x80800364: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80800364: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x80800368: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080036C: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(692, 0X580) << 16);
    // 0x80800370: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800374: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800378: addiu       $s2, $s2, 0x580
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(692, 0X580));
    // 0x8080037C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800380: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
    // 0x80800384: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
    // 0x80800388: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8080038C: lw          $v0, 0x24($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X24);
L_80800390:
    // 0x80800390: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80800394: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80800398: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080039C: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x808003A0: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x808003A4: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x808003A8: beql        $s0, $s4, L_808003F8
    if (ctx->r16 == ctx->r20) {
        // 0x808003AC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808003F8;
    }
    goto skip_0;
    // 0x808003AC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x808003B0: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808003B4: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    // 0x808003B8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x808003BC: mflo        $t1
    ctx->r9 = lo;
    // 0x808003C0: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x808003C4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x808003C8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x808003CC: nop

    // 0x808003D0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808003D4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808003D8: jal         0x800F1214
    // 0x808003DC: nop

    func_800F1214(rdram, ctx);
        goto after_1;
    // 0x808003DC: nop

    after_1:
    // 0x808003E0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808003EC: jal         0x800DF744
    // 0x808003F0: nop

    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808003F0: nop

    after_2:
    // 0x808003F4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_808003F8:
    // 0x808003F8: bnel        $s1, $s6, L_80800390
    if (ctx->r17 != ctx->r22) {
        // 0x808003FC: lw          $v0, 0x24($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X24);
            goto L_80800390;
    }
    goto skip_1;
    // 0x808003FC: lw          $v0, 0x24($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X24);
    skip_1:
    // 0x80800400: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800404: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800408: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080040C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800410: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800414: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800418: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8080041C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80800420: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80800424: jr          $ra
    // 0x80800428: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800428: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080042C: nop

;}
RECOMP_FUNC void func_8080A250_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080A250: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x8080A254: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080A258: lw          $v1, 0x260($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X260);
    // 0x8080A25C: beql        $v1, $zero, L_8080A27C
    if (ctx->r3 == 0) {
        // 0x8080A260: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8080A27C;
    }
    goto skip_0;
    // 0x8080A260: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8080A264: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080A268: beq         $v1, $at, L_8080A2B4
    if (ctx->r3 == ctx->r1) {
        // 0x8080A26C: nop
    
            goto L_8080A2B4;
    }
    // 0x8080A26C: nop

    // 0x8080A270: b           L_8080A2BC
    // 0x8080A274: addiu       $v1, $v0, 0x254
    ctx->r3 = ADD32(ctx->r2, 0X254);
        goto L_8080A2BC;
    // 0x8080A274: addiu       $v1, $v0, 0x254
    ctx->r3 = ADD32(ctx->r2, 0X254);
    // 0x8080A278: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8080A27C:
    // 0x8080A27C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080A280: addiu       $v1, $v0, 0x254
    ctx->r3 = ADD32(ctx->r2, 0X254);
    // 0x8080A284: lwc1        $f4, 0x4C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8080A288: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080A28C: nop

    // 0x8080A290: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080A294: swc1        $f8, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f8.u32l;
    // 0x8080A298: lwc1        $f10, 0x4C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8080A29C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8080A2A0: nop

    // 0x8080A2A4: bc1fl       L_8080A2EC
    if (!c1cs) {
        // 0x8080A2A8: lw          $t6, 0x14($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X14);
            goto L_8080A2EC;
    }
    goto skip_1;
    // 0x8080A2A8: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
    skip_1:
    // 0x8080A2AC: b           L_8080A2E8
    // 0x8080A2B0: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
        goto L_8080A2E8;
    // 0x8080A2B0: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
L_8080A2B4:
    // 0x8080A2B4: b           L_8080A2E8
    // 0x8080A2B8: addiu       $v1, $v0, 0x254
    ctx->r3 = ADD32(ctx->r2, 0X254);
        goto L_8080A2E8;
    // 0x8080A2B8: addiu       $v1, $v0, 0x254
    ctx->r3 = ADD32(ctx->r2, 0X254);
L_8080A2BC:
    // 0x8080A2BC: lwc1        $f0, 0x4C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8080A2C0: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8080A2C4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080A2C8: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8080A2CC: swc1        $f16, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f16.u32l;
    // 0x8080A2D0: lwc1        $f18, 0x4C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8080A2D4: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8080A2D8: nop

    // 0x8080A2DC: bc1fl       L_8080A2EC
    if (!c1cs) {
        // 0x8080A2E0: lw          $t6, 0x14($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X14);
            goto L_8080A2EC;
    }
    goto skip_2;
    // 0x8080A2E0: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
    skip_2:
    // 0x8080A2E4: swc1        $f2, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f2.u32l;
L_8080A2E8:
    // 0x8080A2E8: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
L_8080A2EC:
    // 0x8080A2EC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8080A2F0: beql        $t6, $zero, L_8080A33C
    if (ctx->r14 == 0) {
        // 0x8080A2F4: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8080A33C;
    }
    goto skip_3;
    // 0x8080A2F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_3:
    // 0x8080A2F8: lwc1        $f4, 0x48($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X48);
    // 0x8080A2FC: lwc1        $f6, 0x4C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8080A300: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080A304: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080A308: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080A30C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8080A310: swc1        $f8, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f8.u32l;
    // 0x8080A314: lwc1        $f10, 0x48($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X48);
    // 0x8080A318: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8080A31C: nop

    // 0x8080A320: bc1fl       L_8080A330
    if (!c1cs) {
        // 0x8080A324: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8080A330;
    }
    goto skip_4;
    // 0x8080A324: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_4:
    // 0x8080A328: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x8080A32C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8080A330:
    // 0x8080A330: b           L_8080A36C
    // 0x8080A334: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
        goto L_8080A36C;
    // 0x8080A334: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8080A338: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8080A33C:
    // 0x8080A33C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8080A340: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080A344: lwc1        $f16, 0x48($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X48);
    // 0x8080A348: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8080A34C: swc1        $f4, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f4.u32l;
    // 0x8080A350: lwc1        $f6, 0x48($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X48);
    // 0x8080A354: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8080A358: nop

    // 0x8080A35C: bc1fl       L_8080A36C
    if (!c1cs) {
        // 0x8080A360: lw          $v0, 0x14($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X14);
            goto L_8080A36C;
    }
    goto skip_5;
    // 0x8080A360: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    skip_5:
    // 0x8080A364: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x8080A368: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
L_8080A36C:
    // 0x8080A36C: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x8080A370: bnel        $v0, $t7, L_8080A38C
    if (ctx->r2 != ctx->r15) {
        // 0x8080A374: sw          $zero, 0xC($v1)
        MEM_W(0XC, ctx->r3) = 0;
            goto L_8080A38C;
    }
    goto skip_6;
    // 0x8080A374: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    skip_6:
    // 0x8080A378: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x8080A37C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8080A380: b           L_8080A390
    // 0x8080A384: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_8080A390;
    // 0x8080A384: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x8080A388: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
L_8080A38C:
    // 0x8080A38C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
L_8080A390:
    // 0x8080A390: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x8080A394: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8080A398: bne         $at, $zero, L_8080A3B0
    if (ctx->r1 != 0) {
        // 0x8080A39C: nop
    
            goto L_8080A3B0;
    }
    // 0x8080A39C: nop

    // 0x8080A3A0: lw          $t1, 0x14($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X14);
    // 0x8080A3A4: bne         $t1, $zero, L_8080A3B0
    if (ctx->r9 != 0) {
        // 0x8080A3A8: nop
    
            goto L_8080A3B0;
    }
    // 0x8080A3A8: nop

    // 0x8080A3AC: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
L_8080A3B0:
    // 0x8080A3B0: jr          $ra
    // 0x8080A3B4: nop

    return;
    // 0x8080A3B4: nop

    // 0x8080A3B8: nop

    // 0x8080A3BC: nop

;}
RECOMP_FUNC void cheggsplode_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808005B0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808005B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808005C0: jal         0x801084B0
    // 0x808005C4: addiu       $a0, $zero, 0x2B2
    ctx->r4 = ADD32(0, 0X2B2);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x808005C4: addiu       $a0, $zero, 0x2B2
    ctx->r4 = ADD32(0, 0X2B2);
    after_0:
    // 0x808005C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005D0: jal         0x80100094
    // 0x808005D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808005D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808005D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005DC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808005E0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808005E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808005E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808005EC: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x808005F0: sh          $a0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r4;
    // 0x808005F4: beq         $a0, $at, L_80800628
    if (ctx->r4 == ctx->r1) {
        // 0x808005F8: sw          $a2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r6;
            goto L_80800628;
    }
    // 0x808005F8: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x808005FC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800600: bnel        $a0, $at, L_80800650
    if (ctx->r4 != ctx->r1) {
        // 0x80800604: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800650;
    }
    goto skip_0;
    // 0x80800604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800608: lbu         $t6, 0x72($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X72);
    // 0x8080060C: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800610: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800614: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x80800618: ori         $t8, $t7, 0xC
    ctx->r24 = ctx->r15 | 0XC;
    // 0x8080061C: sb          $t8, 0x72($v1)
    MEM_B(0X72, ctx->r3) = ctx->r24;
    // 0x80800620: b           L_8080064C
    // 0x80800624: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
        goto L_8080064C;
    // 0x80800624: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
L_80800628:
    // 0x80800628: lbu         $t9, 0x72($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X72);
    // 0x8080062C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800630: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x80800634: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x80800638: sb          $t1, 0x72($v1)
    MEM_B(0X72, ctx->r3) = ctx->r9;
    // 0x8080063C: jal         0x80800548
    // 0x80800640: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80800548_cheggsplode(rdram, ctx);
        goto after_2;
    // 0x80800640: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800644: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800648: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
L_8080064C:
    // 0x8080064C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800650:
    // 0x80800650: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800654: jr          $ra
    // 0x80800658: nop

    return;
    // 0x80800658: nop

;}
RECOMP_FUNC void func_800B42FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B42FC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4300: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4304: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B4308: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B430C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4310: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B4314: mflo        $a0
    ctx->r4 = lo;
    // 0x800B4318: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B431C: jal         0x8001ACCC
    // 0x800B4320: nop

    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800B4320: nop

    after_0:
    // 0x800B4324: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B4328: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800B432C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B4330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B4334: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    // 0x800B4338: jal         0x800B39E8
    // 0x800B433C: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    func_800B39E8(rdram, ctx);
        goto after_1;
    // 0x800B433C: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    after_1:
    // 0x800B4340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4344: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4348: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B434C: jr          $ra
    // 0x800B4350: nop

    return;
    // 0x800B4350: nop

;}
RECOMP_FUNC void _suexpressjoint_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089760: syscall     794
    recomp_syscall_handler(rdram, ctx, 0x80089760);
    return;
    // 0x80089764: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _glsplinefind_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088490: syscall     687
    recomp_syscall_handler(rdram, ctx, 0x80088490);
    return;
    // 0x80088494: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chLagoonInnBlockedWall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800250: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2020, 0X480) << 16);
    // 0x80800254: jr          $ra
    // 0x80800258: addiu       $v0, $v0, 0x480
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2020, 0X480));
    return;
    // 0x80800258: addiu       $v0, $v0, 0x480
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2020, 0X480));
;}
RECOMP_FUNC void bashoes_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009DC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808009E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009E4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808009E8: jal         0x8009C128
    // 0x808009EC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808009EC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x808009F0: jal         0x8009BB5C
    // 0x808009F4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8009BB5C(rdram, ctx);
        goto after_1;
    // 0x808009F4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x808009F8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808009FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A00: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800A04: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800A08: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80800A0C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80800A10: jal         0x800F10B4
    // 0x80800A14: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800A14: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800A18: jal         0x80090010
    // 0x80800A1C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80090010(rdram, ctx);
        goto after_3;
    // 0x80800A1C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80800A20: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800A24: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800A28: jal         0x800EFCD8
    // 0x80800A2C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800EFCD8(rdram, ctx);
        goto after_4;
    // 0x80800A2C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800A30: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800A34: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800A38: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800A3C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800A40: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80800A44: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800A48: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800A4C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800A50: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800A54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A58: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(592, 0XBD4) << 16);
    // 0x80800A5C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800A60: addiu       $t6, $t6, 0xBD4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(592, 0XBD4));
    // 0x80800A64: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80800A68: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800A6C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80800A70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800A74: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800A78: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A80: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800A84: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800A88: jal         0x800BBCB8
    // 0x80800A8C: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x80800A8C: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x80800A90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A94: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800A98: jr          $ra
    // 0x80800A9C: nop

    return;
    // 0x80800A9C: nop

;}
RECOMP_FUNC void _chbounce_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085900: syscall     180
    recomp_syscall_handler(rdram, ctx, 0x80085900);
    return;
    // 0x80085904: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_808009D8_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009E0: beq         $a2, $zero, L_80800A04
    if (ctx->r6 == 0) {
        // 0x808009E4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80800A04;
    }
    // 0x808009E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808009E8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808009EC: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    // 0x808009F0: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    // 0x808009F4: jal         0x801032B0
    // 0x808009F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801032B0(rdram, ctx);
        goto after_0;
    // 0x808009F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009FC: b           L_80800A1C
    // 0x80800A00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80800A1C;
    // 0x80800A00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800A04:
    // 0x80800A04: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800A08: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    // 0x80800A0C: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    // 0x80800A10: jal         0x80103140
    // 0x80800A14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103140(rdram, ctx);
        goto after_1;
    // 0x80800A14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800A18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800A1C:
    // 0x80800A1C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A20: addiu       $at, $zero, 0x789
    ctx->r1 = ADD32(0, 0X789);
    // 0x80800A24: beq         $t8, $at, L_80800A3C
    if (ctx->r24 == ctx->r1) {
        // 0x80800A28: addiu       $at, $zero, 0x78A
        ctx->r1 = ADD32(0, 0X78A);
            goto L_80800A3C;
    }
    // 0x80800A28: addiu       $at, $zero, 0x78A
    ctx->r1 = ADD32(0, 0X78A);
    // 0x80800A2C: beq         $t8, $at, L_80800A4C
    if (ctx->r24 == ctx->r1) {
        // 0x80800A30: nop
    
            goto L_80800A4C;
    }
    // 0x80800A30: nop

    // 0x80800A34: b           L_80800A58
    // 0x80800A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A58;
    // 0x80800A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A3C:
    // 0x80800A3C: jal         0x8010A3E8
    // 0x80800A40: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_8010A3E8(rdram, ctx);
        goto after_2;
    // 0x80800A40: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_2:
    // 0x80800A44: b           L_80800A58
    // 0x80800A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A58;
    // 0x80800A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A4C:
    // 0x80800A4C: jal         0x8010A3E8
    // 0x80800A50: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8010A3E8(rdram, ctx);
        goto after_3;
    // 0x80800A50: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x80800A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A58:
    // 0x80800A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A5C: jr          $ra
    // 0x80800A60: nop

    return;
    // 0x80800A60: nop

    // 0x80800A64: nop

    // 0x80800A68: nop

    // 0x80800A6C: nop

;}
RECOMP_FUNC void func_80012F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F60: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80012F64: jr          $ra
    // 0x80012F68: addiu       $v0, $v0, 0x695C
    ctx->r2 = ADD32(ctx->r2, 0X695C);
    return;
    // 0x80012F68: addiu       $v0, $v0, 0x695C
    ctx->r2 = ADD32(ctx->r2, 0X695C);
;}
RECOMP_FUNC void func_8009CCA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CCA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009CCA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CCAC: lw          $v0, 0xF0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CCB0: lbu         $v1, 0x80($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X80);
    // 0x8009CCB4: beq         $v1, $zero, L_8009CCEC
    if (ctx->r3 == 0) {
        // 0x8009CCB8: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8009CCEC;
    }
    // 0x8009CCB8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8009CCBC: sb          $t6, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r14;
    // 0x8009CCC0: lw          $t7, 0xF0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CCC4: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x8009CCC8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8009CCCC: lbu         $t8, 0x80($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X80);
    // 0x8009CCD0: bnel        $t8, $zero, L_8009CCF0
    if (ctx->r24 != 0) {
        // 0x8009CCD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009CCF0;
    }
    goto skip_0;
    // 0x8009CCD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8009CCD8: jal         0x8009BDAC
    // 0x8009CCDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009BDAC(rdram, ctx);
        goto after_0;
    // 0x8009CCDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009CCE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009CCE4: lw          $t9, 0xF0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CCE8: sb          $zero, 0x81($t9)
    MEM_B(0X81, ctx->r25) = 0;
L_8009CCEC:
    // 0x8009CCEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CCF0:
    // 0x8009CCF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009CCF4: jr          $ra
    // 0x8009CCF8: nop

    return;
    // 0x8009CCF8: nop

;}
RECOMP_FUNC void func_800EA124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA12C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800EA130: jal         0x80088B78
    // 0x800EA134: addiu       $a0, $a0, 0x2DC0
    ctx->r4 = ADD32(ctx->r4, 0X2DC0);
    _gsworldDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800EA134: addiu       $a0, $a0, 0x2DC0
    ctx->r4 = ADD32(ctx->r4, 0X2DC0);
    after_0:
    // 0x800EA138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA13C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA140: jr          $ra
    // 0x800EA144: nop

    return;
    // 0x800EA144: nop

;}
RECOMP_FUNC void func_808000B0_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B8: jal         0x8009EF1C
    // 0x808000BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x808000BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000C0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x808000C4: jal         0x8009EF10
    // 0x808000C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x808000C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808000CC: bne         $v0, $zero, L_808000E8
    if (ctx->r2 != 0) {
        // 0x808000D0: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_808000E8;
    }
    // 0x808000D0: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808000D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000D8: jal         0x8009B9B0
    // 0x808000DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808000DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808000E0: b           L_80800108
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800108;
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000E8:
    // 0x808000E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808000EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000F0: jal         0x800F1214
    // 0x808000F4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x808000F4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_3:
    // 0x808000F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000FC: jal         0x8009B9B0
    // 0x80800100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800108:
    // 0x80800108: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_808008DC_susubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008E4: jal         0x800D3948
    // 0x808008E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x808008E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008EC: beq         $v0, $zero, L_8080091C
    if (ctx->r2 == 0) {
        // 0x808008F0: nop
    
            goto L_8080091C;
    }
    // 0x808008F0: nop

    // 0x808008F4: jal         0x800F6438
    // 0x808008F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x808008F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808008FC: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800900: beq         $t6, $zero, L_80800930
    if (ctx->r14 == 0) {
        // 0x80800904: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800930;
    }
    // 0x80800904: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800908: jal         0x800A9420
    // 0x8080090C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A9420(rdram, ctx);
        goto after_2;
    // 0x8080090C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800910: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800914: b           L_80800930
    // 0x80800918: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80800930;
    // 0x80800918: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8080091C:
    // 0x8080091C: jal         0x800F54E4
    // 0x80800920: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800920: nop

    after_3:
    // 0x80800924: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800928: xor         $v0, $v0, $t8
    ctx->r2 = ctx->r2 ^ ctx->r24;
    // 0x8080092C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80800930:
    // 0x80800930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800938: jr          $ra
    // 0x8080093C: nop

    return;
    // 0x8080093C: nop

;}
RECOMP_FUNC void func_800F5CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5CC0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5CC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5CD0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5CD4: jal         0x8009EEAC
    // 0x800F5CD8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    bastick_getAngle(rdram, ctx);
        goto after_0;
    // 0x800F5CD8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5CE4: jr          $ra
    // 0x800F5CE8: nop

    return;
    // 0x800F5CE8: nop

;}
RECOMP_FUNC void func_808071D8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808071D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808071DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808071E0: jal         0x80091E6C
    // 0x808071E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80091E6C(rdram, ctx);
        goto after_0;
    // 0x808071E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808071E8: jal         0x800827D0
    // 0x808071EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808071EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808071F0: jal         0x80807C8C
    // 0x808071F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808071F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808071F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808071FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807200: jr          $ra
    // 0x80807204: nop

    return;
    // 0x80807204: nop

;}
RECOMP_FUNC void func_800DC548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC54C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC550: jal         0x800E9320
    // 0x800DC554: nop

    func_800E9320(rdram, ctx);
        goto after_0;
    // 0x800DC554: nop

    after_0:
    // 0x800DC558: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800DC55C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DC560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DC564: bne         $t6, $at, L_800DC574
    if (ctx->r14 != ctx->r1) {
        // 0x800DC568: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DC574;
    }
    // 0x800DC568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC56C: b           L_800DC574
    // 0x800DC570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DC574;
    // 0x800DC570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DC574:
    // 0x800DC574: jr          $ra
    // 0x800DC578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800DC578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC57C: nop

;}
