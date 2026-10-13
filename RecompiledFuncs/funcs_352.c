#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800A0DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0DAC: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0DB0: jr          $ra
    // 0x800A0DB4: sb          $a1, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r5;
    return;
    // 0x800A0DB4: sb          $a1, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void gcdialogexec_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D5C: jal         0x80800164
    // 0x80801D60: nop

    func_80800164_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x80801D60: nop

    after_0:
    // 0x80801D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D6C: jr          $ra
    // 0x80801D70: nop

    return;
    // 0x80801D70: nop

;}
RECOMP_FUNC void func_8009D820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009D824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D828: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009D82C: jal         0x800DC0C0
    // 0x8009D830: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x8009D830: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009D834: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009D838: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009D83C: addiu       $a1, $zero, 0x586
    ctx->r5 = ADD32(0, 0X586);
    // 0x8009D840: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009D844: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8009D848: nop

    // 0x8009D84C: bc1f        L_8009D85C
    if (!c1cs) {
        // 0x8009D850: nop
    
            goto L_8009D85C;
    }
    // 0x8009D850: nop

    // 0x8009D854: b           L_8009D85C
    // 0x8009D858: addiu       $a1, $zero, 0x585
    ctx->r5 = ADD32(0, 0X585);
        goto L_8009D85C;
    // 0x8009D858: addiu       $a1, $zero, 0x585
    ctx->r5 = ADD32(0, 0X585);
L_8009D85C:
    // 0x8009D85C: jal         0x8009DE38
    // 0x8009D860: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_8009DE38(rdram, ctx);
        goto after_1;
    // 0x8009D860: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8009D864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009D86C: jr          $ra
    // 0x8009D870: nop

    return;
    // 0x8009D870: nop

;}
RECOMP_FUNC void func_80800058_chbigtopticket(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080005C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800060: jal         0x80101870
    // 0x80800064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080006C: lw          $a1, 0x7C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X7C);
    // 0x80800070: sll         $t6, $a1, 19
    ctx->r14 = S32(ctx->r5 << 19);
    // 0x80800074: jal         0x80103110
    // 0x80800078: srl         $a1, $t6, 31
    ctx->r5 = S32(U32(ctx->r14) >> 31);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800078: srl         $a1, $t6, 31
    ctx->r5 = S32(U32(ctx->r14) >> 31);
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
RECOMP_FUNC void _bsstand_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B30: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B30);
    return;
    // 0x80083B34: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bashoes_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085038: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085038);
    return;
    // 0x8008503C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80090F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090F38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090F3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80090F40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80090F44: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x80090F48: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80090F4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80090F50: jal         0x800DC0C0
    // 0x80090F54: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80090F54: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    after_0:
    // 0x80090F58: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80090F5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80090F60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090F64: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80090F68: nop

    // 0x80090F6C: bc1f        L_80090FA0
    if (!c1cs) {
        // 0x80090F70: nop
    
            goto L_80090FA0;
    }
    // 0x80090F70: nop

    // 0x80090F74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090F78: lwc1        $f12, 0x4D08($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4D08);
    // 0x80090F7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090F80: jal         0x800DC178
    // 0x80090F84: lwc1        $f14, 0x4D0C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X4D0C);
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80090F84: lwc1        $f14, 0x4D0C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X4D0C);
    after_1:
    // 0x80090F88: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x80090F8C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80090F90: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x80090F94: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x80090F98: b           L_8009101C
    // 0x80090F9C: sb          $t8, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r24;
        goto L_8009101C;
    // 0x80090F9C: sb          $t8, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r24;
L_80090FA0:
    // 0x80090FA0: lwc1        $f8, 0x4D10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4D10);
    // 0x80090FA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090FA8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80090FAC: nop

    // 0x80090FB0: bc1f        L_80090FF0
    if (!c1cs) {
        // 0x80090FB4: nop
    
            goto L_80090FF0;
    }
    // 0x80090FB4: nop

    // 0x80090FB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090FBC: lwc1        $f12, 0x4D14($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4D14);
    // 0x80090FC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80090FC4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80090FC8: jal         0x800DC178
    // 0x80090FCC: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80090FCC: nop

    after_2:
    // 0x80090FD0: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x80090FD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80090FD8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80090FDC: jal         0x800DC128
    // 0x80090FE0: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x80090FE0: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
    after_3:
    // 0x80090FE4: lw          $t1, 0x30($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X30);
    // 0x80090FE8: b           L_8009101C
    // 0x80090FEC: sb          $v0, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r2;
        goto L_8009101C;
    // 0x80090FEC: sb          $v0, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r2;
L_80090FF0:
    // 0x80090FF0: lwc1        $f12, 0x4D18($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4D18);
    // 0x80090FF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090FF8: jal         0x800DC178
    // 0x80090FFC: lwc1        $f14, 0x4D1C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X4D1C);
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80090FFC: lwc1        $f14, 0x4D1C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X4D1C);
    after_4:
    // 0x80091000: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
    // 0x80091004: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80091008: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8009100C: jal         0x800DC128
    // 0x80091010: swc1        $f0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f0.u32l;
    func_800DC128(rdram, ctx);
        goto after_5;
    // 0x80091010: swc1        $f0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f0.u32l;
    after_5:
    // 0x80091014: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x80091018: sb          $v0, 0xC($t3)
    MEM_B(0XC, ctx->r11) = ctx->r2;
L_8009101C:
    // 0x8009101C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80091020: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80091024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80091028: jr          $ra
    // 0x8009102C: nop

    return;
    // 0x8009102C: nop

;}
RECOMP_FUNC void _bssub_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D70: syscall     93
    recomp_syscall_handler(rdram, ctx, 0x80083D70);
    return;
    // 0x80083D74: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _sumultiscore_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899C0: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x800899C0);
    return;
    // 0x800899C4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80028A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028A28: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80028A2C: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80028A30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80028A34: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80028A38: nop

    // 0x80028A3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80028A40: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80028A44: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80028A48: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80028A4C: nop

    // 0x80028A50: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80028A54: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x80028A58: sra         $t0, $t9, 15
    ctx->r8 = S32(SIGNED(ctx->r25) >> 15);
    // 0x80028A5C: sh          $t0, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r8;
    // 0x80028A60: lh          $t1, 0xE($sp)
    ctx->r9 = MEM_H(ctx->r29, 0XE);
    // 0x80028A64: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80028A68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80028A6C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80028A70: nop

    // 0x80028A74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80028A78: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80028A7C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80028A80: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80028A84: nop

    // 0x80028A88: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    // 0x80028A8C: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80028A90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
L_80028A94:
    // 0x80028A94: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80028A98: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80028A9C: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80028AA0: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x80028AA4: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80028AA8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80028AAC: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x80028AB0: bne         $at, $zero, L_80028A94
    if (ctx->r1 != 0) {
        // 0x80028AB4: sw          $t8, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r24;
            goto L_80028A94;
    }
    // 0x80028AB4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80028AB8: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80028ABC: lh          $t9, 0xE($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XE);
    // 0x80028AC0: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80028AC4: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80028AC8: sh          $t9, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r25;
    // 0x80028ACC: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x80028AD0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80028AD4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80028AD8: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80028ADC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80028AE0: nop

    // 0x80028AE4: swc1        $f16, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f16.u32l;
    // 0x80028AE8: lh          $t5, 0xE($sp)
    ctx->r13 = MEM_H(ctx->r29, 0XE);
    // 0x80028AEC: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80028AF0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80028AF4: nop

    // 0x80028AF8: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80028AFC: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80028B00: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x80028B04: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x80028B08: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80028B0C: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x80028B10: beq         $at, $zero, L_80028B64
    if (ctx->r1 == 0) {
        // 0x80028B14: nop
    
            goto L_80028B64;
    }
    // 0x80028B14: nop

L_80028B18:
    // 0x80028B18: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80028B1C: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80028B20: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80028B24: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x80028B28: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80028B2C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80028B30: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80028B34: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80028B38: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80028B3C: addu        $t9, $a0, $t1
    ctx->r25 = ADD32(ctx->r4, ctx->r9);
    // 0x80028B40: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80028B44: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80028B48: nop

    // 0x80028B4C: sh          $t8, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r24;
    // 0x80028B50: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80028B54: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80028B58: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x80028B5C: bne         $at, $zero, L_80028B18
    if (ctx->r1 != 0) {
        // 0x80028B60: sw          $t3, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r11;
            goto L_80028B18;
    }
    // 0x80028B60: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
L_80028B64:
    // 0x80028B64: b           L_80028B6C
    // 0x80028B68: nop

        goto L_80028B6C;
    // 0x80028B68: nop

L_80028B6C:
    // 0x80028B6C: jr          $ra
    // 0x80028B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80028B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8010965C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010965C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80109660: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80109664: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80109668: jal         0x8008A010
    // 0x8010966C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiecustomhits_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8010966C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80109670: beql        $v0, $zero, L_801096BC
    if (ctx->r2 == 0) {
        // 0x80109674: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801096BC;
    }
    goto skip_0;
    // 0x80109674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80109678: jal         0x800B53A4
    // 0x8010967C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x8010967C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x80109680: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80109684: jal         0x80109524
    // 0x80109688: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80109524(rdram, ctx);
        goto after_2;
    // 0x80109688: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8010968C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80109690: jal         0x800BA3FC
    // 0x80109694: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800BA3FC(rdram, ctx);
        goto after_3;
    // 0x80109694: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80109698: jal         0x80109518
    // 0x8010969C: nop

    func_80109518(rdram, ctx);
        goto after_4;
    // 0x8010969C: nop

    after_4:
    // 0x801096A0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801096A4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801096A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801096AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801096B0: jal         0x800BABB8
    // 0x801096B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x801096B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x801096B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801096BC:
    // 0x801096BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801096C0: jr          $ra
    // 0x801096C4: nop

    return;
    // 0x801096C4: nop

;}
RECOMP_FUNC void func_800FFB74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFB74: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FFB78: lw          $t6, 0x5A50($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5A50);
    // 0x800FFB7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FFB80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FFB84: blez        $t6, L_800FFBD0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800FFB88: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800FFBD0;
    }
    // 0x800FFB88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FFB8C: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x800FFB90: jal         0x801067C4
    // 0x800FFB94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x800FFB94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800FFB98: beq         $v0, $zero, L_800FFBC8
    if (ctx->r2 == 0) {
        // 0x800FFB9C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FFBC8;
    }
    // 0x800FFB9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800FFBA0:
    // 0x800FFBA0: lw          $t7, 0x64($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X64);
    // 0x800FFBA4: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x800FFBA8: bgez        $t9, L_800FFBB8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800FFBAC: nop
    
            goto L_800FFBB8;
    }
    // 0x800FFBAC: nop

    // 0x800FFBB0: jal         0x800FFA3C
    // 0x800FFBB4: nop

    func_800FFA3C(rdram, ctx);
        goto after_1;
    // 0x800FFBB4: nop

    after_1:
L_800FFBB8:
    // 0x800FFBB8: jal         0x8010682C
    // 0x800FFBBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010682C(rdram, ctx);
        goto after_2;
    // 0x800FFBBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FFBC0: bne         $v0, $zero, L_800FFBA0
    if (ctx->r2 != 0) {
        // 0x800FFBC4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FFBA0;
    }
    // 0x800FFBC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800FFBC8:
    // 0x800FFBC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FFBCC: sw          $zero, 0x5A50($at)
    MEM_W(0X5A50, ctx->r1) = 0;
L_800FFBD0:
    // 0x800FFBD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFBD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FFBD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FFBDC: jr          $ra
    // 0x800FFBE0: nop

    return;
    // 0x800FFBE0: nop

;}
RECOMP_FUNC void idwibble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800130: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800134: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x80800138: addu        $s4, $t6, $a1
    ctx->r20 = ADD32(ctx->r14, ctx->r5);
    // 0x8080013C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800140: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800144: sltu        $at, $a1, $s4
    ctx->r1 = ctx->r5 < ctx->r20 ? 1 : 0;
    // 0x80800148: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080014C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80800150: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800154: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800158: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8080015C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800160: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800164: beq         $at, $zero, L_808002F4
    if (ctx->r1 == 0) {
        // 0x80800168: sw          $a0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r4;
            goto L_808002F4;
    }
    // 0x80800168: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8080016C: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80800170: addiu       $s5, $sp, 0x40
    ctx->r21 = ADD32(ctx->r29, 0X40);
    // 0x80800174: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80800178: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
L_8080017C:
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800184: jal         0x80800000
    // 0x80800188: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80800000_idwibble(rdram, ctx);
        goto after_0;
    // 0x80800188: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x8080018C: lbu         $v0, 0x31($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X31);
    // 0x80800190: bne         $s3, $v0, L_808001C8
    if (ctx->r19 != ctx->r2) {
        // 0x80800194: nop
    
            goto L_808001C8;
    }
    // 0x80800194: nop

    // 0x80800198: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x8080019C: lh          $t8, 0x34($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X34);
    // 0x808001A0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808001A4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x808001A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001AC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808001B0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x808001B4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x808001B8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808001BC: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x808001C0: b           L_80800200
    // 0x808001C4: sh          $t0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r8;
        goto L_80800200;
    // 0x808001C4: sh          $t0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r8;
L_808001C8:
    // 0x808001C8: bnel        $s6, $v0, L_80800204
    if (ctx->r22 != ctx->r2) {
        // 0x808001CC: lbu         $t5, 0x32($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X32);
            goto L_80800204;
    }
    goto skip_0;
    // 0x808001CC: lbu         $t5, 0x32($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X32);
    skip_0:
    // 0x808001D0: lh          $t1, 0x2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X2);
    // 0x808001D4: lh          $t2, 0x34($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X34);
    // 0x808001D8: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x808001DC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x808001E0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808001E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808001E8: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x808001EC: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x808001F0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001F4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x808001F8: nop

    // 0x808001FC: sh          $t4, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r12;
L_80800200:
    // 0x80800200: lbu         $t5, 0x32($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X32);
L_80800204:
    // 0x80800204: bnel        $s3, $t5, L_80800284
    if (ctx->r19 != ctx->r13) {
        // 0x80800208: lbu         $t7, 0x33($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X33);
            goto L_80800284;
    }
    goto skip_1;
    // 0x80800208: lbu         $t7, 0x33($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X33);
    skip_1:
    // 0x8080020C: lbu         $t6, 0x30($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X30);
    // 0x80800210: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800214: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80800218: bgez        $t6, L_8080022C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080021C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8080022C;
    }
    // 0x8080021C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800220: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800224: nop

    // 0x80800228: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_8080022C:
    // 0x8080022C: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800230: lbu         $t8, 0xC($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0XC);
    // 0x80800234: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800238: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8080023C: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800240: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80800244: nop

    // 0x80800248: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080024C: mflo        $t9
    ctx->r25 = lo;
    // 0x80800250: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x80800254: sb          $t0, 0xC($s2)
    MEM_B(0XC, ctx->r18) = ctx->r8;
    // 0x80800258: lbu         $t1, 0xD($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XD);
    // 0x8080025C: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800260: mflo        $t2
    ctx->r10 = lo;
    // 0x80800264: sra         $t3, $t2, 8
    ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
    // 0x80800268: sb          $t3, 0xD($s2)
    MEM_B(0XD, ctx->r18) = ctx->r11;
    // 0x8080026C: lbu         $t4, 0xE($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0XE);
    // 0x80800270: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800274: mflo        $t5
    ctx->r13 = lo;
    // 0x80800278: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x8080027C: sb          $t6, 0xE($s2)
    MEM_B(0XE, ctx->r18) = ctx->r14;
    // 0x80800280: lbu         $t7, 0x33($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X33);
L_80800284:
    // 0x80800284: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800288: beql        $t7, $zero, L_808002E8
    if (ctx->r15 == 0) {
        // 0x8080028C: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_808002E8;
    }
    goto skip_2;
    // 0x8080028C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    skip_2:
    // 0x80800290: lh          $t8, 0x8($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X8);
    // 0x80800294: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800298: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8080029C: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x808002A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002A4: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x808002A8: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808002AC: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x808002B0: nop

    // 0x808002B4: sh          $t0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r8;
    // 0x808002B8: lh          $t1, 0xA($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XA);
    // 0x808002BC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808002C0: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808002C4: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x808002C8: mul.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808002CC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808002D0: add.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x808002D4: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808002D8: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x808002DC: nop

    // 0x808002E0: sh          $t3, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r11;
    // 0x808002E4: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_808002E8:
    // 0x808002E8: sltu        $at, $s1, $s4
    ctx->r1 = ctx->r17 < ctx->r20 ? 1 : 0;
    // 0x808002EC: bne         $at, $zero, L_8080017C
    if (ctx->r1 != 0) {
        // 0x808002F0: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_8080017C;
    }
    // 0x808002F0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_808002F4:
    // 0x808002F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808002F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800300: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800304: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800308: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8080030C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800310: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800314: jr          $ra
    // 0x80800318: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800318: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_808002A8_chweather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002B4: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x808002B8: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(732, 0X410) << 16);
    // 0x808002BC: addiu       $t1, $t1, 0x410
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(732, 0X410));
    // 0x808002C0: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x808002C4: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x808002C8: addiu       $t9, $t8, -0x204
    ctx->r25 = ADD32(ctx->r24, -0X204);
    // 0x808002CC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x808002D0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x808002D4: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x808002D8: lhu         $t3, 0x72($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X72);
    // 0x808002DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002E4: srl         $t4, $t3, 10
    ctx->r12 = S32(U32(ctx->r11) >> 10);
    // 0x808002E8: bnel        $t4, $at, L_80800314
    if (ctx->r12 != ctx->r1) {
        // 0x808002EC: lhu         $t6, 0x72($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X72);
            goto L_80800314;
    }
    goto skip_0;
    // 0x808002EC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x808002F0: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x808002F4: jalr        $t9
    // 0x808002F8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x808002F8: nop

    after_0:
    // 0x808002FC: beq         $v0, $zero, L_80800310
    if (ctx->r2 == 0) {
        // 0x80800300: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_80800310;
    }
    // 0x80800300: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: jal         0x80800138
    // 0x8080030C: lh          $a1, 0x0($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X0);
    func_80800138_chweather(rdram, ctx);
        goto after_1;
    // 0x8080030C: lh          $a1, 0x0($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X0);
    after_1:
L_80800310:
    // 0x80800310: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_80800314:
    // 0x80800314: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800318: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8080031C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800320: beql        $t7, $at, L_8080034C
    if (ctx->r15 == ctx->r1) {
        // 0x80800324: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080034C;
    }
    goto skip_1;
    // 0x80800324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800328: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800330: jalr        $t9
    // 0x80800334: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80800334: nop

    after_2:
    // 0x80800338: bne         $v0, $zero, L_80800348
    if (ctx->r2 != 0) {
        // 0x8080033C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800348;
    }
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x80800138
    // 0x80800344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800138_chweather(rdram, ctx);
        goto after_3;
    // 0x80800344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_80800348:
    // 0x80800348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080034C:
    // 0x8080034C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800350: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800354: jr          $ra
    // 0x80800358: nop

    return;
    // 0x80800358: nop

;}
RECOMP_FUNC void func_800A7A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7A20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A7A24: jal         0x800FE8EC
    // 0x800A7A28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800FE8EC(rdram, ctx);
        goto after_0;
    // 0x800A7A28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A7A2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7A34: addiu       $v0, $v0, 0x7630
    ctx->r2 = ADD32(ctx->r2, 0X7630);
    // 0x800A7A38: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800A7A3C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7A40: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A7A44: sb          $zero, 0x16($v0)
    MEM_B(0X16, ctx->r2) = 0;
    // 0x800A7A48: sb          $t6, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r14;
    // 0x800A7A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7A50: sh          $t7, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r15;
    // 0x800A7A54: jr          $ra
    // 0x800A7A58: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
    return;
    // 0x800A7A58: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void _bstnt_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F68: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083F68);
    return;
    // 0x80083F6C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8008FEF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FEF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FEF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FEF8: jal         0x800F54E4
    // 0x8008FEFC: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FEFC: nop

    after_0:
    // 0x8008FF00: jal         0x800F5AE0
    // 0x8008FF04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5AE0(rdram, ctx);
        goto after_1;
    // 0x8008FF04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FF08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FF0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FF10: jr          $ra
    // 0x8008FF14: nop

    return;
    // 0x8008FF14: nop

;}
RECOMP_FUNC void func_800FB808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB808: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FB80C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800FB810: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800FB814: addiu       $s1, $s1, 0x3E40
    ctx->r17 = ADD32(ctx->r17, 0X3E40);
    // 0x800FB818: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x800FB81C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800FB820: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800FB824: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800FB828: beq         $t6, $zero, L_800FB838
    if (ctx->r14 == 0) {
        // 0x800FB82C: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_800FB838;
    }
    // 0x800FB82C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800FB830: jal         0x800FB908
    // 0x800FB834: nop

    func_800FB908(rdram, ctx);
        goto after_0;
    // 0x800FB834: nop

    after_0:
L_800FB838:
    // 0x800FB838: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FB83C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800FB840: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x800FB844: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FB848: swc1        $f4, 0x59B4($at)
    MEM_W(0X59B4, ctx->r1) = ctx->f4.u32l;
    // 0x800FB84C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FB850: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FB854: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FB858: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FB85C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800FB860: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800FB864: addiu       $s2, $s2, 0x59B0
    ctx->r18 = ADD32(ctx->r18, 0X59B0);
    // 0x800FB868: addiu       $s0, $s0, 0x57D0
    ctx->r16 = ADD32(ctx->r16, 0X57D0);
    // 0x800FB86C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800FB870: swc1        $f6, 0x59B8($at)
    MEM_W(0X59B8, ctx->r1) = ctx->f6.u32l;
L_800FB874:
    // 0x800FB874: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    // 0x800FB878: sh          $s1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r17;
    // 0x800FB87C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800FB880: andi        $t9, $t8, 0xFF0F
    ctx->r25 = ctx->r24 & 0XFF0F;
    // 0x800FB884: sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    // 0x800FB888: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x800FB88C: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    // 0x800FB890: sb          $t9, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r25;
    // 0x800FB894: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800FB898: jal         0x800B3268
    // 0x800FB89C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    freelist_new(rdram, ctx);
        goto after_1;
    // 0x800FB89C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800FB8A0: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800FB8A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FB8A8: jal         0x800FB6E0
    // 0x800FB8AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800FB6E0(rdram, ctx);
        goto after_2;
    // 0x800FB8AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800FB8B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800FB8B4: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800FB8B8: addu        $v0, $s0, $t0
    ctx->r2 = ADD32(ctx->r16, ctx->r8);
    // 0x800FB8BC: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x800FB8C0: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    // 0x800FB8C4: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800FB8C8: sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
    // 0x800FB8CC: sw          $zero, 0x44($v0)
    MEM_W(0X44, ctx->r2) = 0;
    // 0x800FB8D0: sw          $zero, 0x40($v0)
    MEM_W(0X40, ctx->r2) = 0;
    // 0x800FB8D4: bne         $at, $zero, L_800FB874
    if (ctx->r1 != 0) {
        // 0x800FB8D8: sw          $zero, 0x3C($v0)
        MEM_W(0X3C, ctx->r2) = 0;
            goto L_800FB874;
    }
    // 0x800FB8D8: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800FB8DC: jal         0x800FE614
    // 0x800FB8E0: nop

    func_800FE614(rdram, ctx);
        goto after_3;
    // 0x800FB8E0: nop

    after_3:
    // 0x800FB8E4: jal         0x80017864
    // 0x800FB8E8: nop

    func_80017864(rdram, ctx);
        goto after_4;
    // 0x800FB8E8: nop

    after_4:
    // 0x800FB8EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800FB8F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800FB8F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800FB8F8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800FB8FC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800FB900: jr          $ra
    // 0x800FB904: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FB904: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808001A0_chfantasysafe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808001A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001AC: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808001B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001B4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808001B8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808001BC: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x808001C0: beq         $at, $zero, L_808005C0
    if (ctx->r1 == 0) {
        // 0x808001C4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808005C0;
    }
    // 0x808001C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808001C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2380, 0X940) << 16);
    // 0x808001CC: addu        $at, $at, $t8
    gpr jr_addend_808001D4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808001D0: lw          $t8, 0x940($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2380, 0X940));
    // 0x808001D4: jr          $t8
    // 0x808001D8: nop

    switch (jr_addend_808001D4 >> 2) {
        case 0: goto L_808001DC; break;
        case 1: goto L_80800208; break;
        case 2: goto L_8080036C; break;
        case 3: goto L_808003E0; break;
        case 4: goto L_80800468; break;
        case 5: goto L_8080047C; break;
        default: switch_error(__func__, 0x808001D4, 0x80800940);
    }
    // 0x808001D8: nop

L_808001DC:
    // 0x808001DC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2380, 0X9DC) << 16);
    // 0x808001E0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2380, 0X9AC) << 16);
    // 0x808001E4: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x808001E8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808001EC: addiu       $a3, $a3, 0x9AC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2380, 0X9AC));
    // 0x808001F0: addiu       $a2, $a2, 0x9DC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2380, 0X9DC));
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x8008A1F0
    // 0x808001FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808001FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80800200: b           L_808005C4
    // 0x80800204: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_808005C4;
    // 0x80800204: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800208:
    // 0x80800208: jal         0x800D90A4
    // 0x8080020C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x8080020C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800210: beq         $v0, $zero, L_80800330
    if (ctx->r2 == 0) {
        // 0x80800214: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800330;
    }
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x800DA298
    // 0x8080021C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080021C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_2:
    // 0x80800220: beq         $v0, $zero, L_80800230
    if (ctx->r2 == 0) {
        // 0x80800224: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80800230;
    }
    // 0x80800224: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800228: b           L_80800234
    // 0x8080022C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
        goto L_80800234;
    // 0x8080022C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80800230:
    // 0x80800230: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80800234:
    // 0x80800234: jal         0x800DA298
    // 0x80800238: addiu       $a0, $zero, 0x38A
    ctx->r4 = ADD32(0, 0X38A);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800238: addiu       $a0, $zero, 0x38A
    ctx->r4 = ADD32(0, 0X38A);
    after_3:
    // 0x8080023C: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x80800240: addiu       $a0, $zero, 0x389
        ctx->r4 = ADD32(0, 0X389);
            goto L_8080024C;
    }
    // 0x80800240: addiu       $a0, $zero, 0x389
    ctx->r4 = ADD32(0, 0X389);
    // 0x80800244: b           L_80800250
    // 0x80800248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800250;
    // 0x80800248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080024C:
    // 0x8080024C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800250:
    // 0x80800250: jal         0x800DA298
    // 0x80800254: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800254: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_4:
    // 0x80800258: beq         $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x8080025C: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_80800268;
    }
    // 0x8080025C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800260: b           L_8080026C
    // 0x80800264: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8080026C;
    // 0x80800264: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800268:
    // 0x80800268: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8080026C:
    // 0x8080026C: addiu       $a0, $zero, 0x38C
    ctx->r4 = ADD32(0, 0X38C);
    // 0x80800270: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80800274: jal         0x800DA298
    // 0x80800278: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800278: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_5:
    // 0x8080027C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800280: beq         $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x80800284: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_80800290;
    }
    // 0x80800284: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800288: b           L_80800294
    // 0x8080028C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800294;
    // 0x8080028C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800290:
    // 0x80800290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800294:
    // 0x80800294: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80800298: addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // 0x8080029C: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x808002A0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x808002A4: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x808002A8: bne         $at, $zero, L_808002F0
    if (ctx->r1 != 0) {
        // 0x808002AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F0;
    }
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808002C0: jal         0x80101FDC
    // 0x808002C4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x808002C4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_6:
    // 0x808002C8: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x808002CC: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x808002D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808002D8: addiu       $a1, $zero, 0x13DD
    ctx->r5 = ADD32(0, 0X13DD);
    // 0x808002DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002E0: jal         0x8008A208
    // 0x808002E4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808002E4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x808002E8: b           L_80800304
    // 0x808002EC: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
        goto L_80800304;
    // 0x808002EC: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
L_808002F0:
    // 0x808002F0: jal         0x80101FDC
    // 0x808002F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x808002F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808002F8: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x808002FC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80800300: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
L_80800304:
    // 0x80800304: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x80800308: jal         0x800DA544
    // 0x8080030C: addiu       $a0, $t7, 0x389
    ctx->r4 = ADD32(ctx->r15, 0X389);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x8080030C: addiu       $a0, $t7, 0x389
    ctx->r4 = ADD32(ctx->r15, 0X389);
    after_9:
    // 0x80800310: jal         0x80089D40
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800318: jal         0x800FC6B0
    // 0x8080031C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800FC6B0(rdram, ctx);
        goto after_11;
    // 0x8080031C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_11:
    // 0x80800320: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800324: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800328: b           L_808005C0
    // 0x8080032C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
        goto L_808005C0;
    // 0x8080032C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
L_80800330:
    // 0x80800330: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2380, 0X9F4) << 16);
    // 0x80800334: addiu       $a3, $a3, 0x9F4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2380, 0X9F4));
    // 0x80800338: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080033C: jal         0x80089D50
    // 0x80800340: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800340: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80800344: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800348: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080034C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800350: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800354: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    // 0x80800358: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080035C: jal         0x800F10B4
    // 0x80800360: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_13;
    // 0x80800360: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x80800364: b           L_808005C0
    // 0x80800368: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
        goto L_808005C0;
    // 0x80800368: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
L_8080036C:
    // 0x8080036C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800370: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800374: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80800378: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080037C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800380: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800384: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800388: jal         0x800F10B4
    // 0x8080038C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x8080038C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x80800390: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800394: jal         0x800D90A4
    // 0x80800398: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_15;
    // 0x80800398: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_15:
    // 0x8080039C: beq         $v0, $zero, L_808005C0
    if (ctx->r2 == 0) {
        // 0x808003A0: lui         $at, 0x42DC
        ctx->r1 = S32(0X42DC << 16);
            goto L_808005C0;
    }
    // 0x808003A0: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x808003A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003A8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808003AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808003B8: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x808003BC: jal         0x80101FDC
    // 0x808003C0: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    func_80101FDC(rdram, ctx);
        goto after_16;
    // 0x808003C0: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    after_16:
    // 0x808003C4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2380, 0X9D4) << 16);
    // 0x808003C8: addiu       $a2, $a2, 0x9D4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2380, 0X9D4));
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: jal         0x80089D18
    // 0x808003D4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x808003D4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_17:
    // 0x808003D8: b           L_808005C4
    // 0x808003DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_808005C4;
    // 0x808003DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808003E0:
    // 0x808003E0: jal         0x800D90A4
    // 0x808003E4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_18;
    // 0x808003E4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_18:
    // 0x808003E8: beq         $v0, $zero, L_80800428
    if (ctx->r2 == 0) {
        // 0x808003EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800428;
    }
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: jal         0x80101FDC
    // 0x808003F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x808003F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_19:
    // 0x808003FC: jal         0x800DA544
    // 0x80800400: addiu       $a0, $zero, 0x38D
    ctx->r4 = ADD32(0, 0X38D);
    func_800DA544(rdram, ctx);
        goto after_20;
    // 0x80800400: addiu       $a0, $zero, 0x38D
    ctx->r4 = ADD32(0, 0X38D);
    after_20:
    // 0x80800404: jal         0x80089D40
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080040C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2380, 0X9D4) << 16);
    // 0x80800410: addiu       $a2, $a2, 0x9D4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2380, 0X9D4));
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: jal         0x80089D18
    // 0x8080041C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_22;
    // 0x8080041C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_22:
    // 0x80800420: b           L_80800440
    // 0x80800424: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
        goto L_80800440;
    // 0x80800424: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_80800428:
    // 0x80800428: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2380, 0X9FC) << 16);
    // 0x8080042C: addiu       $a3, $a3, 0x9FC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2380, 0X9FC));
    // 0x80800430: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800434: jal         0x80089D50
    // 0x80800438: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_23;
    // 0x80800438: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_23:
    // 0x8080043C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_80800440:
    // 0x80800440: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800444: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800448: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080044C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800450: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800454: lui         $a3, 0x4364
    ctx->r7 = S32(0X4364 << 16);
    // 0x80800458: jal         0x800F10B4
    // 0x8080045C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_24;
    // 0x8080045C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_24:
    // 0x80800460: b           L_808005C0
    // 0x80800464: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
        goto L_808005C0;
    // 0x80800464: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
L_80800468:
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: jal         0x80103110
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_25;
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80800474: b           L_808005C4
    // 0x80800478: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_808005C4;
    // 0x80800478: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8080047C:
    // 0x8080047C: jal         0x800D91B8
    // 0x80800480: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D91B8(rdram, ctx);
        goto after_26;
    // 0x80800480: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_26:
    // 0x80800484: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x80800488: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080048C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2380, 0XA08) << 16);
    // 0x80800490: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800494: addiu       $a1, $a1, 0xA08
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2380, 0XA08));
    // 0x80800498: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080049C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x808004A0: mflo        $t8
    ctx->r24 = lo;
    // 0x808004A4: addu        $v0, $a1, $t8
    ctx->r2 = ADD32(ctx->r5, ctx->r24);
    // 0x808004A8: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808004AC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x808004B0: nop

    // 0x808004B4: bc1fl       L_80800550
    if (!c1cs) {
        // 0x808004B8: lwc1        $f8, 0x10($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80800550;
    }
    goto skip_0;
    // 0x808004B8: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x808004BC: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808004C0: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x808004C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808004C8: lui         $a0, 0x6653
    ctx->r4 = S32(0X6653 << 16);
    // 0x808004CC: mflo        $t1
    ctx->r9 = lo;
    // 0x808004D0: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x808004D4: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x808004D8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x808004DC: nop

    // 0x808004E0: bc1f        L_80800508
    if (!c1cs) {
        // 0x808004E4: nop
    
            goto L_80800508;
    }
    // 0x808004E4: nop

    // 0x808004E8: lui         $a0, 0x6653
    ctx->r4 = S32(0X6653 << 16);
    // 0x808004EC: jal         0x800C3F48
    // 0x808004F0: ori         $a0, $a0, 0x8CA0
    ctx->r4 = ctx->r4 | 0X8CA0;
    func_800C3F48(rdram, ctx);
        goto after_27;
    // 0x808004F0: ori         $a0, $a0, 0x8CA0
    ctx->r4 = ctx->r4 | 0X8CA0;
    after_27:
    // 0x808004F4: lui         $a0, 0x4CB3
    ctx->r4 = S32(0X4CB3 << 16);
    // 0x808004F8: jal         0x800C3F48
    // 0x808004FC: ori         $a0, $a0, 0x8CA1
    ctx->r4 = ctx->r4 | 0X8CA1;
    func_800C3F48(rdram, ctx);
        goto after_28;
    // 0x808004FC: ori         $a0, $a0, 0x8CA1
    ctx->r4 = ctx->r4 | 0X8CA1;
    after_28:
    // 0x80800500: b           L_80800514
    // 0x80800504: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
        goto L_80800514;
    // 0x80800504: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
L_80800508:
    // 0x80800508: jal         0x800C3F48
    // 0x8080050C: ori         $a0, $a0, 0x8CA1
    ctx->r4 = ctx->r4 | 0X8CA1;
    func_800C3F48(rdram, ctx);
        goto after_29;
    // 0x8080050C: ori         $a0, $a0, 0x8CA1
    ctx->r4 = ctx->r4 | 0X8CA1;
    after_29:
    // 0x80800510: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
L_80800514:
    // 0x80800514: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2380, 0XA08) << 16);
    // 0x80800518: addiu       $t5, $t5, 0xA08
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2380, 0XA08));
    // 0x8080051C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80800520: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80800524: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80800528: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8080052C: lbu         $t7, 0x8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8);
    // 0x80800530: lbu         $t0, 0x79($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X79);
    // 0x80800534: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800538: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8080053C: andi        $t1, $t0, 0xFF0F
    ctx->r9 = ctx->r8 & 0XFF0F;
    // 0x80800540: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800544: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
    // 0x80800548: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8080054C: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
L_80800550:
    // 0x80800550: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800554: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800558: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8080055C: jal         0x800F12D4
    // 0x80800560: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F12D4(rdram, ctx);
        goto after_30;
    // 0x80800560: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_30:
    // 0x80800564: lui         $at, 0x4364
    ctx->r1 = S32(0X4364 << 16);
    // 0x80800568: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080056C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800570: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800574: jal         0x800F1214
    // 0x80800578: lui         $a2, 0x43B4
    ctx->r6 = S32(0X43B4 << 16);
    func_800F1214(rdram, ctx);
        goto after_31;
    // 0x80800578: lui         $a2, 0x43B4
    ctx->r6 = S32(0X43B4 << 16);
    after_31:
    // 0x8080057C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800580: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800584: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800588: jal         0x800F1214
    // 0x8080058C: lui         $a2, 0x42DC
    ctx->r6 = S32(0X42DC << 16);
    func_800F1214(rdram, ctx);
        goto after_32;
    // 0x8080058C: lui         $a2, 0x42DC
    ctx->r6 = S32(0X42DC << 16);
    after_32:
    // 0x80800590: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800594: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800598: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080059C: jal         0x800F1214
    // 0x808005A0: lui         $a2, 0x43B4
    ctx->r6 = S32(0X43B4 << 16);
    func_800F1214(rdram, ctx);
        goto after_33;
    // 0x808005A0: lui         $a2, 0x43B4
    ctx->r6 = S32(0X43B4 << 16);
    after_33:
    // 0x808005A4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2380, 0XA98) << 16);
    // 0x808005A8: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x808005AC: addiu       $a3, $a3, 0xA98
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2380, 0XA98));
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808005B8: jal         0x80089D50
    // 0x808005BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_34;
    // 0x808005BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_34:
L_808005C0:
    // 0x808005C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808005C4:
    // 0x808005C4: jal         0x8010262C
    // 0x808005C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010262C(rdram, ctx);
        goto after_35;
    // 0x808005C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_35:
    // 0x808005CC: beq         $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x808005D0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080061C;
    }
    // 0x808005D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808005D8: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x808005DC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005E0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x808005E4: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808005E8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808005EC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808005F0: jal         0x800E0AFC
    // 0x808005F4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_36;
    // 0x808005F4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_36:
    // 0x808005F8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808005FC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800600: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80800604: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800608: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8080060C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800610: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800614: jal         0x800E0AFC
    // 0x80800618: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_37;
    // 0x80800618: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_37:
L_8080061C:
    // 0x8080061C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800620: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800624: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800628: jr          $ra
    // 0x8080062C: nop

    return;
    // 0x8080062C: nop

;}
RECOMP_FUNC void func_800CF494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF494: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CF498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF49C: jal         0x800D3E40
    // 0x800CF4A0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800D3E40(rdram, ctx);
        goto after_0;
    // 0x800CF4A0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_0:
    // 0x800CF4A4: bnel        $v0, $zero, L_800CF574
    if (ctx->r2 != 0) {
        // 0x800CF4A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF574;
    }
    goto skip_0;
    // 0x800CF4A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CF4AC: jal         0x800CEAA8
    // 0x800CF4B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CEAA8(rdram, ctx);
        goto after_1;
    // 0x800CF4B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800CF4B4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800CF4B8: addiu       $a1, $a1, -0x4EA0
    ctx->r5 = ADD32(ctx->r5, -0X4EA0);
    // 0x800CF4BC: lh          $v1, 0x8($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X8);
    // 0x800CF4C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CF4C4: beq         $v1, $zero, L_800CF4D4
    if (ctx->r3 == 0) {
        // 0x800CF4C8: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_800CF4D4;
    }
    // 0x800CF4C8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x800CF4CC: b           L_800CF570
    // 0x800CF4D0: sh          $t6, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r14;
        goto L_800CF570;
    // 0x800CF4D0: sh          $t6, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r14;
L_800CF4D4:
    // 0x800CF4D4: blez        $v0, L_800CF570
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CF4D8: addiu       $t7, $zero, 0x9
        ctx->r15 = ADD32(0, 0X9);
            goto L_800CF570;
    }
    // 0x800CF4D8: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x800CF4DC: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800CF4E0: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800CF4E4: jal         0x800CF67C
    // 0x800CF4E8: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    func_800CF67C(rdram, ctx);
        goto after_2;
    // 0x800CF4E8: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    after_2:
    // 0x800CF4EC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800CF4F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF4F4: jal         0x800CE88C
    // 0x800CF4F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_3;
    // 0x800CF4F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800CF4FC: jal         0x800CF640
    // 0x800CF500: nop

    func_800CF640(rdram, ctx);
        goto after_4;
    // 0x800CF500: nop

    after_4:
    // 0x800CF504: jal         0x800CEF00
    // 0x800CF508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800CEF00(rdram, ctx);
        goto after_5;
    // 0x800CF508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800CF50C: jal         0x800CF6D0
    // 0x800CF510: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800CF6D0(rdram, ctx);
        goto after_6;
    // 0x800CF510: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x800CF514: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF518: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF51C: jal         0x800CE8D8
    // 0x800CF520: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800CE8D8(rdram, ctx);
        goto after_7;
    // 0x800CF520: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_7:
    // 0x800CF524: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800CF528: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CF52C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF530: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CF534: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800CF538: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800CF53C: jal         0x800CE980
    // 0x800CF540: nop

    func_800CE980(rdram, ctx);
        goto after_8;
    // 0x800CF540: nop

    after_8:
    // 0x800CF544: jal         0x800F54E4
    // 0x800CF548: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x800CF548: nop

    after_9:
    // 0x800CF54C: jal         0x800F6604
    // 0x800CF550: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6604(rdram, ctx);
        goto after_10;
    // 0x800CF550: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x800CF554: beql        $v0, $zero, L_800CF574
    if (ctx->r2 == 0) {
        // 0x800CF558: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF574;
    }
    goto skip_1;
    // 0x800CF558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800CF55C: jal         0x800F54E4
    // 0x800CF560: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x800CF560: nop

    after_11:
    // 0x800CF564: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CF568: jal         0x800F7B9C
    // 0x800CF56C: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    func_800F7B9C(rdram, ctx);
        goto after_12;
    // 0x800CF56C: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    after_12:
L_800CF570:
    // 0x800CF570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CF574:
    // 0x800CF574: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CF578: jr          $ra
    // 0x800CF57C: nop

    return;
    // 0x800CF57C: nop

;}
RECOMP_FUNC void func_8010B1F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B1F4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8010B1F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010B1FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010B200: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010B204: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8010B208: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8010B20C: jal         0x8010C460
    // 0x8010B210: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_8010C460(rdram, ctx);
        goto after_0;
    // 0x8010B210: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B214: jal         0x800D8FF8
    // 0x8010B218: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8010B218: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8010B21C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8010B220: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8010B224: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010B228: jal         0x800EE7F8
    // 0x8010B22C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8010B22C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x8010B230: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8010B234: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010B238: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8010B23C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8010B240: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010B244: jal         0x800EE7F8
    // 0x8010B248: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x8010B248: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8010B24C: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8010B250: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8010B254: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8010B258: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8010B25C: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8010B260: jal         0x800F13F0
    // 0x8010B264: nop

    func_800F13F0(rdram, ctx);
        goto after_4;
    // 0x8010B264: nop

    after_4:
    // 0x8010B268: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010B26C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010B270: addiu       $a2, $a2, 0x6F40
    ctx->r6 = ADD32(ctx->r6, 0X6F40);
    // 0x8010B274: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8010B278: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8010B27C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8010B280: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8010B284: jal         0x800BEF00
    // 0x8010B288: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_5;
    // 0x8010B288: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_5:
    // 0x8010B28C: beq         $v0, $zero, L_8010B2D8
    if (ctx->r2 == 0) {
        // 0x8010B290: lui         $at, 0x4496
        ctx->r1 = S32(0X4496 << 16);
            goto L_8010B2D8;
    }
    // 0x8010B290: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x8010B294: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010B298: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8010B29C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x8010B2A0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8010B2A4: jal         0x800EE7F8
    // 0x8010B2A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x8010B2A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x8010B2AC: lh          $t6, 0x8E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8E);
    // 0x8010B2B0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8010B2B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010B2B8: beq         $t6, $zero, L_8010B2D0
    if (ctx->r14 == 0) {
        // 0x8010B2BC: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_8010B2D0;
    }
    // 0x8010B2BC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010B2C0: addiu       $a1, $a1, 0x6F40
    ctx->r5 = ADD32(ctx->r5, 0X6F40);
    // 0x8010B2C4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8010B2C8: jal         0x801045AC
    // 0x8010B2CC: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    func_801045AC(rdram, ctx);
        goto after_7;
    // 0x8010B2CC: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    after_7:
L_8010B2D0:
    // 0x8010B2D0: b           L_8010B31C
    // 0x8010B2D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010B31C;
    // 0x8010B2D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010B2D8:
    // 0x8010B2D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010B2DC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8010B2E0: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8010B2E4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010B2E8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8010B2EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010B2F0: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8010B2F4: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x8010B2F8: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8010B2FC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010B300: jal         0x8010C3E8
    // 0x8010B304: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    func_8010C3E8(rdram, ctx);
        goto after_8;
    // 0x8010B304: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x8010B308: beql        $v0, $zero, L_8010B31C
    if (ctx->r2 == 0) {
        // 0x8010B30C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010B31C;
    }
    goto skip_0;
    // 0x8010B30C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8010B310: b           L_8010B31C
    // 0x8010B314: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8010B31C;
    // 0x8010B314: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8010B318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010B31C:
    // 0x8010B31C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B320: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010B324: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8010B328: jr          $ra
    // 0x8010B32C: nop

    return;
    // 0x8010B32C: nop

;}
RECOMP_FUNC void func_8080105C_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080105C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801060: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801064: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801068: ori         $t6, $a2, 0x6
    ctx->r14 = ctx->r6 | 0X6;
    // 0x8080106C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801070: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801074: jal         0x80800FF0
    // 0x80801078: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    func_80800FF0_chflysaucer(rdram, ctx);
        goto after_0;
    // 0x80801078: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_0:
    // 0x8080107C: bne         $v0, $zero, L_8080108C
    if (ctx->r2 != 0) {
        // 0x80801080: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_8080108C;
    }
    // 0x80801080: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80801084: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80801088: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_8080108C:
    // 0x8080108C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80801090: addiu       $t0, $t9, -0x10C6
    ctx->r8 = ADD32(ctx->r25, -0X10C6);
    // 0x80801094: sltiu       $at, $t0, 0x23
    ctx->r1 = ctx->r8 < 0X23 ? 1 : 0;
    // 0x80801098: beq         $at, $zero, L_808010F4
    if (ctx->r1 == 0) {
        // 0x8080109C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_808010F4;
    }
    // 0x8080109C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808010A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3EA0) << 16);
    // 0x808010A4: addu        $at, $at, $t0
    gpr jr_addend_808010AC = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808010A8: lw          $t0, 0x3EA0($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3EA0));
    // 0x808010AC: jr          $t0
    // 0x808010B0: nop

    switch (jr_addend_808010AC >> 2) {
        case 0: goto L_808010B4; break;
        case 1: goto L_808010B4; break;
        case 2: goto L_808010B4; break;
        case 3: goto L_808010B4; break;
        case 4: goto L_808010F4; break;
        case 5: goto L_808010F4; break;
        case 6: goto L_808010F4; break;
        case 7: goto L_808010F4; break;
        case 8: goto L_808010F4; break;
        case 9: goto L_808010F4; break;
        case 10: goto L_808010F4; break;
        case 11: goto L_808010F4; break;
        case 12: goto L_808010F4; break;
        case 13: goto L_808010F4; break;
        case 14: goto L_808010F4; break;
        case 15: goto L_808010F4; break;
        case 16: goto L_808010F4; break;
        case 17: goto L_808010F4; break;
        case 18: goto L_808010F4; break;
        case 19: goto L_808010F4; break;
        case 20: goto L_808010F4; break;
        case 21: goto L_808010CC; break;
        case 22: goto L_808010E4; break;
        case 23: goto L_808010CC; break;
        case 24: goto L_808010E4; break;
        case 25: goto L_808010F4; break;
        case 26: goto L_808010F4; break;
        case 27: goto L_808010F4; break;
        case 28: goto L_808010B4; break;
        case 29: goto L_808010B4; break;
        case 30: goto L_808010B4; break;
        case 31: goto L_808010B4; break;
        case 32: goto L_808010B4; break;
        case 33: goto L_808010B4; break;
        case 34: goto L_808010B4; break;
        default: switch_error(__func__, 0x808010AC, 0x80803EA0);
    }
    // 0x808010B0: nop

L_808010B4:
    // 0x808010B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808010BC: jal         0x80800388
    // 0x808010C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800388_chflysaucer(rdram, ctx);
        goto after_1;
    // 0x808010C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x808010C4: b           L_808010F8
    // 0x808010C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_808010F8;
    // 0x808010C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808010CC:
    // 0x808010CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808010D4: jal         0x80800388
    // 0x808010D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800388_chflysaucer(rdram, ctx);
        goto after_2;
    // 0x808010D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808010DC: b           L_808010F8
    // 0x808010E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_808010F8;
    // 0x808010E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808010E4:
    // 0x808010E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808010EC: jal         0x80800388
    // 0x808010F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800388_chflysaucer(rdram, ctx);
        goto after_3;
    // 0x808010F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_808010F4:
    // 0x808010F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808010F8:
    // 0x808010F8: addiu       $t1, $zero, 0x41
    ctx->r9 = ADD32(0, 0X41);
    // 0x808010FC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801100: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801104: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80801108: jal         0x8008A208
    // 0x8080110C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x8080110C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80801110: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80801114: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x80801118: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
    // 0x8080111C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801120: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801124: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801128: jr          $ra
    // 0x8080112C: nop

    return;
    // 0x8080112C: nop

;}
RECOMP_FUNC void func_80110014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110014: jr          $ra
    // 0x80110018: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    return;
    // 0x80110018: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
;}
RECOMP_FUNC void badata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006FC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800700: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080070C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X1EF8) << 16);
    // 0x80800710: jal         0x808006AC
    // 0x80800714: addiu       $a1, $a1, 0x1EF8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1EF8));
    func_808006AC_badata(rdram, ctx);
        goto after_0;
    // 0x80800714: addiu       $a1, $a1, 0x1EF8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1EF8));
    after_0:
    // 0x80800718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080071C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800720: jr          $ra
    // 0x80800724: nop

    return;
    // 0x80800724: nop

;}
RECOMP_FUNC void func_800A71E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A71E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A71E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A71E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A71EC: jal         0x800D58CC
    // 0x800A71F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800D58CC(rdram, ctx);
        goto after_0;
    // 0x800A71F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800A71F4: jal         0x8001A570
    // 0x800A71F8: nop

    func_8001A570(rdram, ctx);
        goto after_1;
    // 0x800A71F8: nop

    after_1:
    // 0x800A71FC: jal         0x8001B840
    // 0x800A7200: nop

    func_8001B840(rdram, ctx);
        goto after_2;
    // 0x800A7200: nop

    after_2:
    // 0x800A7204: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A7208: addiu       $s1, $zero, 0xF
    ctx->r17 = ADD32(0, 0XF);
L_800A720C:
    // 0x800A720C: jal         0x8001B518
    // 0x800A7210: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001B518(rdram, ctx);
        goto after_3;
    // 0x800A7210: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800A7214: jal         0x800DF874
    // 0x800A7218: nop

    func_800DF874(rdram, ctx);
        goto after_4;
    // 0x800A7218: nop

    after_4:
    // 0x800A721C: jal         0x80087840
    // 0x800A7220: nop

    _cosectionstor_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x800A7220: nop

    after_5:
    // 0x800A7224: jal         0x800C9484
    // 0x800A7228: nop

    func_800C9484(rdram, ctx);
        goto after_6;
    // 0x800A7228: nop

    after_6:
    // 0x800A722C: jal         0x800B5E3C
    // 0x800A7230: nop

    func_800B5E3C(rdram, ctx);
        goto after_7;
    // 0x800A7230: nop

    after_7:
    // 0x800A7234: jal         0x800D58AC
    // 0x800A7238: nop

    func_800D58AC(rdram, ctx);
        goto after_8;
    // 0x800A7238: nop

    after_8:
    // 0x800A723C: jal         0x800E4C7C
    // 0x800A7240: nop

    func_800E4C7C(rdram, ctx);
        goto after_9;
    // 0x800A7240: nop

    after_9:
    // 0x800A7244: jal         0x800CA174
    // 0x800A7248: nop

    func_800CA174(rdram, ctx);
        goto after_10;
    // 0x800A7248: nop

    after_10:
    // 0x800A724C: jal         0x800FCD5C
    // 0x800A7250: nop

    func_800FCD5C(rdram, ctx);
        goto after_11;
    // 0x800A7250: nop

    after_11:
    // 0x800A7254: jal         0x800A9D00
    // 0x800A7258: nop

    func_800A9D00(rdram, ctx);
        goto after_12;
    // 0x800A7258: nop

    after_12:
    // 0x800A725C: jal         0x800C9484
    // 0x800A7260: nop

    func_800C9484(rdram, ctx);
        goto after_13;
    // 0x800A7260: nop

    after_13:
    // 0x800A7264: jal         0x800B4380
    // 0x800A7268: nop

    func_800B4380(rdram, ctx);
        goto after_14;
    // 0x800A7268: nop

    after_14:
    // 0x800A726C: jal         0x8008BA5C
    // 0x800A7270: nop

    func_8008BA5C(rdram, ctx);
        goto after_15;
    // 0x800A7270: nop

    after_15:
    // 0x800A7274: jal         0x800DA1E0
    // 0x800A7278: nop

    func_800DA1E0(rdram, ctx);
        goto after_16;
    // 0x800A7278: nop

    after_16:
    // 0x800A727C: jal         0x800D15CC
    // 0x800A7280: nop

    func_800D15CC(rdram, ctx);
        goto after_17;
    // 0x800A7280: nop

    after_17:
    // 0x800A7284: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A7288: bne         $s0, $s1, L_800A720C
    if (ctx->r16 != ctx->r17) {
        // 0x800A728C: nop
    
            goto L_800A720C;
    }
    // 0x800A728C: nop

    // 0x800A7290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7294: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A7298: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A729C: jr          $ra
    // 0x800A72A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A72A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800F7018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7018: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F701C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7020: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7024: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7028: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F702C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7030: jal         0x8009E6F8
    // 0x800F7034: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800F7034: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7038: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F703C: jal         0x8009CBDC
    // 0x800F7040: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8009CBDC(rdram, ctx);
        goto after_1;
    // 0x800F7040: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800F7044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7048: xori        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 ^ 0X8;
    // 0x800F704C: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F7050: jr          $ra
    // 0x800F7054: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F7054: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void gcmapsects_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800D60: bne         $a0, $at, L_80800D70
    if (ctx->r4 != ctx->r1) {
        // 0x80800D64: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800D70;
    }
    // 0x80800D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D68: b           L_80800DB8
    // 0x80800D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DB8;
    // 0x80800D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D70:
    // 0x80800D70: jal         0x800BF704
    // 0x80800D74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x80800D74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D78: lbu         $t6, 0x77($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X77);
    // 0x80800D7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800D84: bne         $t6, $zero, L_80800D94
    if (ctx->r14 != 0) {
        // 0x80800D88: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_80800D94;
    }
    // 0x80800D88: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80800D8C: b           L_80800DB8
    // 0x80800D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DB8;
    // 0x80800D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D94:
    // 0x80800D94: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80800D98: lw          $t7, 0x68($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X68);
    // 0x80800D9C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800DA0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80800DA4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80800DA8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80800DAC: lw          $v0, 0x4C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X4C);
    // 0x80800DB0: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    // 0x80800DB4: srl         $v0, $t0, 31
    ctx->r2 = S32(U32(ctx->r8) >> 31);
L_80800DB8:
    // 0x80800DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DC0: jr          $ra
    // 0x80800DC4: nop

    return;
    // 0x80800DC4: nop

;}
RECOMP_FUNC void func_80800C84_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800C8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800C94: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800C98: jal         0x800886D8
    // 0x80800C9C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    _glglobalsettings_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800C9C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800CA0: jal         0x800E41CC
    // 0x80800CA4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800E41CC(rdram, ctx);
        goto after_1;
    // 0x80800CA4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800CA8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800CAC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800CB0: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800CB4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800CB8: jal         0x800E3C8C
    // 0x80800CBC: nop

    func_800E3C8C(rdram, ctx);
        goto after_2;
    // 0x80800CBC: nop

    after_2:
    // 0x80800CC0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800CC4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1636, 0X1578) << 16);
    // 0x80800CC8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1636, 0X1560) << 16);
    // 0x80800CCC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800CD0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80800CD4: sll         $v0, $t6, 2
    ctx->r2 = S32(ctx->r14 << 2);
    // 0x80800CD8: addiu       $t8, $t8, 0x1560
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1636, 0X1560));
    // 0x80800CDC: addiu       $t7, $t7, 0x1578
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1636, 0X1578));
    // 0x80800CE0: addu        $a0, $v0, $t7
    ctx->r4 = ADD32(ctx->r2, ctx->r15);
    // 0x80800CE4: jal         0x800E39D8
    // 0x80800CE8: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    func_800E39D8(rdram, ctx);
        goto after_3;
    // 0x80800CE8: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    after_3:
    // 0x80800CEC: jal         0x800E3CE8
    // 0x80800CF0: nop

    func_800E3CE8(rdram, ctx);
        goto after_4;
    // 0x80800CF0: nop

    after_4:
    // 0x80800CF4: jal         0x800E44FC
    // 0x80800CF8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800E44FC(rdram, ctx);
        goto after_5;
    // 0x80800CF8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800CFC: jal         0x800E7C28
    // 0x80800D00: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800E7C28(rdram, ctx);
        goto after_6;
    // 0x80800D00: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80800D04: jal         0x800E7CF4
    // 0x80800D08: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800E7CF4(rdram, ctx);
        goto after_7;
    // 0x80800D08: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800D0C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800D10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D14: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800D18: lhu         $v0, 0x72($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X72);
    // 0x80800D1C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800D20: srl         $t0, $v0, 10
    ctx->r8 = S32(U32(ctx->r2) >> 10);
    // 0x80800D24: beq         $t0, $at, L_80800D50
    if (ctx->r8 == ctx->r1) {
        // 0x80800D28: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800D50;
    }
    // 0x80800D28: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800D2C: beq         $t0, $at, L_80800D88
    if (ctx->r8 == ctx->r1) {
        // 0x80800D30: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_80800D88;
    }
    // 0x80800D30: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800D34: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800D38: beq         $t0, $at, L_80800DC4
    if (ctx->r8 == ctx->r1) {
        // 0x80800D3C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800DC4;
    }
    // 0x80800D3C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800D40: beql        $t0, $at, L_80800DC8
    if (ctx->r8 == ctx->r1) {
        // 0x80800D44: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800DC8;
    }
    goto skip_0;
    // 0x80800D44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80800D48: b           L_80800DD8
    // 0x80800D4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_80800DD8;
    // 0x80800D4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80800D50:
    // 0x80800D50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D54: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800D58: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800D5C: lwc1        $f12, 0x34($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X34);
    // 0x80800D60: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800D64: jal         0x800F10B4
    // 0x80800D68: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800D68: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80800D6C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800D70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800D74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1636, 0X155C) << 16);
    // 0x80800D78: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800D7C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800D80: b           L_80800DD4
    // 0x80800D84: swc1        $f10, 0x155C($at)
    MEM_W((int16_t)RELOC_LO16(1636, 0X155C), ctx->r1) = ctx->f10.u32l;
        goto L_80800DD4;
    // 0x80800D84: swc1        $f10, 0x155C($at)
    MEM_W((int16_t)RELOC_LO16(1636, 0X155C), ctx->r1) = ctx->f10.u32l;
L_80800D88:
    // 0x80800D88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800D8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D90: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800D94: lwc1        $f12, 0x34($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X34);
    // 0x80800D98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800D9C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800DA0: jal         0x800F10B4
    // 0x80800DA4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x80800DA4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_9:
    // 0x80800DA8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800DAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800DB0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1636, 0X155C) << 16);
    // 0x80800DB4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800DB8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800DBC: b           L_80800DD4
    // 0x80800DC0: swc1        $f18, 0x155C($at)
    MEM_W((int16_t)RELOC_LO16(1636, 0X155C), ctx->r1) = ctx->f18.u32l;
        goto L_80800DD4;
    // 0x80800DC0: swc1        $f18, 0x155C($at)
    MEM_W((int16_t)RELOC_LO16(1636, 0X155C), ctx->r1) = ctx->f18.u32l;
L_80800DC4:
    // 0x80800DC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800DC8:
    // 0x80800DC8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800DCC: nop

    // 0x80800DD0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
L_80800DD4:
    // 0x80800DD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80800DD8:
    // 0x80800DD8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800DDC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800DE0: nop

    // 0x80800DE4: bc1fl       L_80800E24
    if (!c1cs) {
        // 0x80800DE8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800E24;
    }
    goto skip_1;
    // 0x80800DE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80800DEC: jal         0x800DF830
    // 0x80800DF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_10;
    // 0x80800DF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x80800DF4: jal         0x800D674C
    // 0x80800DF8: addiu       $a0, $zero, 0x9A1
    ctx->r4 = ADD32(0, 0X9A1);
    func_800D674C(rdram, ctx);
        goto after_11;
    // 0x80800DF8: addiu       $a0, $zero, 0x9A1
    ctx->r4 = ADD32(0, 0X9A1);
    after_11:
    // 0x80800DFC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1636, 0X1548) << 16);
    // 0x80800E00: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1636, 0X1554) << 16);
    // 0x80800E04: addiu       $a2, $a2, 0x1554
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1636, 0X1554));
    // 0x80800E08: addiu       $a1, $a1, 0x1548
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1636, 0X1548));
    // 0x80800E0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E10: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800E14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800E18: jal         0x800DE498
    // 0x80800E1C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800DE498(rdram, ctx);
        goto after_12;
    // 0x80800E1C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_12:
    // 0x80800E20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800E24:
    // 0x80800E24: jal         0x80101870
    // 0x80800E28: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101870(rdram, ctx);
        goto after_13;
    // 0x80800E28: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x80800E2C: jal         0x800E4208
    // 0x80800E30: nop

    func_800E4208(rdram, ctx);
        goto after_14;
    // 0x80800E30: nop

    after_14:
    // 0x80800E34: jal         0x800E44FC
    // 0x80800E38: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800E44FC(rdram, ctx);
        goto after_15;
    // 0x80800E38: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x80800E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E44: jr          $ra
    // 0x80800E48: nop

    return;
    // 0x80800E48: nop

;}
RECOMP_FUNC void func_8009E388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E388: jr          $ra
    // 0x8009E38C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8009E38C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _gczoombox_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BF8: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BF8);
    return;
    // 0x80087BFC: addi        $t0, $zero, 0x8C
    ctx->r8 = ADD32(0, 0X8C);
;}
RECOMP_FUNC void chdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80800028
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800028_chdoor(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: jal         0x8080050C
    // 0x80800014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080050C_chdoor(rdram, ctx);
        goto after_1;
    // 0x80800014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void func_800A7A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7A5C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A7A60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7A64: jr          $ra
    // 0x800A7A68: sb          $t6, 0x7648($at)
    MEM_B(0X7648, ctx->r1) = ctx->r14;
    return;
    // 0x800A7A68: sb          $t6, 0x7648($at)
    MEM_B(0X7648, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8009E7AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E7AC: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E7B0: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8009E7B4: lw          $t7, 0x120($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X120);
    // 0x8009E7B8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8009E7BC: lw          $t8, 0x120($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X120);
    // 0x8009E7C0: jr          $ra
    // 0x8009E7C4: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
    return;
    // 0x8009E7C4: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
;}
RECOMP_FUNC void func_80800000_badata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009E6F8
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800014: jal         0x800A3274
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080001C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80800020: sltiu       $at, $t6, 0x13
    ctx->r1 = ctx->r14 < 0X13 ? 1 : 0;
    // 0x80800024: beq         $at, $zero, L_80800248
    if (ctx->r1 == 0) {
        // 0x80800028: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800248;
    }
    // 0x80800028: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080002C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(473, 0XFC0) << 16);
    // 0x80800030: addu        $at, $at, $t6
    gpr jr_addend_80800038 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800034: lw          $t6, 0xFC0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(473, 0XFC0));
    // 0x80800038: jr          $t6
    // 0x8080003C: nop

    switch (jr_addend_80800038 >> 2) {
        case 0: goto L_80800248; break;
        case 1: goto L_80800040; break;
        case 2: goto L_80800248; break;
        case 3: goto L_80800248; break;
        case 4: goto L_80800248; break;
        case 5: goto L_80800048; break;
        case 6: goto L_80800070; break;
        case 7: goto L_80800078; break;
        case 8: goto L_80800240; break;
        case 9: goto L_80800080; break;
        case 10: goto L_80800148; break;
        case 11: goto L_80800220; break;
        case 12: goto L_808001E8; break;
        case 13: goto L_80800208; break;
        case 14: goto L_80800210; break;
        case 15: goto L_80800218; break;
        case 16: goto L_80800228; break;
        case 17: goto L_80800230; break;
        case 18: goto L_80800238; break;
        default: switch_error(__func__, 0x80800038, 0x80800FC0);
    }
    // 0x8080003C: nop

L_80800040:
    // 0x80800040: b           L_80800378
    // 0x80800044: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800378;
    // 0x80800044: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800048:
    // 0x80800048: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080004C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800050: jal         0x8009CA70
    // 0x80800054: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    func_8009CA70(rdram, ctx);
        goto after_2;
    // 0x80800054: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    after_2:
    // 0x80800058: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x8080005C: nop
    
            goto L_80800068;
    }
    // 0x8080005C: nop

    // 0x80800060: b           L_80800378
    // 0x80800064: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
        goto L_80800378;
    // 0x80800064: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_80800068:
    // 0x80800068: b           L_80800378
    // 0x8080006C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80800378;
    // 0x8080006C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80800070:
    // 0x80800070: b           L_80800378
    // 0x80800074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800378;
    // 0x80800074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800078:
    // 0x80800078: b           L_80800378
    // 0x8080007C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_80800378;
    // 0x8080007C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_80800080:
    // 0x80800080: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800084: jal         0x8009E71C
    // 0x80800088: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_8009E71C(rdram, ctx);
        goto after_3;
    // 0x80800088: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_3:
    // 0x8080008C: beq         $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
        // 0x80800090: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080009C;
    }
    // 0x80800090: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800094: b           L_80800378
    // 0x80800098: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80800378;
    // 0x80800098: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8080009C:
    // 0x8080009C: jal         0x8009E71C
    // 0x808000A0: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_8009E71C(rdram, ctx);
        goto after_4;
    // 0x808000A0: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_4:
    // 0x808000A4: beq         $v0, $zero, L_808000B4
    if (ctx->r2 == 0) {
        // 0x808000A8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808000B4;
    }
    // 0x808000A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000AC: b           L_80800378
    // 0x808000B0: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
        goto L_80800378;
    // 0x808000B0: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_808000B4:
    // 0x808000B4: jal         0x8009E71C
    // 0x808000B8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8009E71C(rdram, ctx);
        goto after_5;
    // 0x808000B8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_5:
    // 0x808000BC: beq         $v0, $zero, L_808000CC
    if (ctx->r2 == 0) {
        // 0x808000C0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808000CC;
    }
    // 0x808000C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000C4: b           L_80800378
    // 0x808000C8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
        goto L_80800378;
    // 0x808000C8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_808000CC:
    // 0x808000CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D0: jal         0x8009CA70
    // 0x808000D4: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    func_8009CA70(rdram, ctx);
        goto after_6;
    // 0x808000D4: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_6:
    // 0x808000D8: beq         $v0, $zero, L_808000E8
    if (ctx->r2 == 0) {
        // 0x808000DC: nop
    
            goto L_808000E8;
    }
    // 0x808000DC: nop

    // 0x808000E0: b           L_80800378
    // 0x808000E4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_80800378;
    // 0x808000E4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_808000E8:
    // 0x808000E8: jal         0x8008E35C
    // 0x808000EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_inWater(rdram, ctx);
        goto after_7;
    // 0x808000EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x808000F0: beq         $v0, $zero, L_80800140
    if (ctx->r2 == 0) {
        // 0x808000F4: nop
    
            goto L_80800140;
    }
    // 0x808000F4: nop

    // 0x808000F8: jal         0x800F8B88
    // 0x808000FC: nop

    func_800F8B88(rdram, ctx);
        goto after_8;
    // 0x808000FC: nop

    after_8:
    // 0x80800100: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800104: bne         $v0, $at, L_80800114
    if (ctx->r2 != ctx->r1) {
        // 0x80800108: nop
    
            goto L_80800114;
    }
    // 0x80800108: nop

    // 0x8080010C: b           L_80800378
    // 0x80800110: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
        goto L_80800378;
    // 0x80800110: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
L_80800114:
    // 0x80800114: jal         0x800F40EC
    // 0x80800118: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F40EC(rdram, ctx);
        goto after_9;
    // 0x80800118: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x8080011C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800120: beq         $v0, $at, L_80800138
    if (ctx->r2 == ctx->r1) {
        // 0x80800124: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800138;
    }
    // 0x80800124: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800128: bne         $v0, $at, L_80800138
    if (ctx->r2 != ctx->r1) {
        // 0x8080012C: nop
    
            goto L_80800138;
    }
    // 0x8080012C: nop

    // 0x80800130: b           L_80800378
    // 0x80800134: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80800378;
    // 0x80800134: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80800138:
    // 0x80800138: b           L_80800378
    // 0x8080013C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800378;
    // 0x8080013C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800140:
    // 0x80800140: b           L_80800378
    // 0x80800144: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80800378;
    // 0x80800144: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80800148:
    // 0x80800148: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080014C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800150: jal         0x8009CA70
    // 0x80800154: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_8009CA70(rdram, ctx);
        goto after_10;
    // 0x80800154: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_10:
    // 0x80800158: beq         $v0, $zero, L_80800168
    if (ctx->r2 == 0) {
        // 0x8080015C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800168;
    }
    // 0x8080015C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: b           L_80800378
    // 0x80800164: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
        goto L_80800378;
    // 0x80800164: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
L_80800168:
    // 0x80800168: jal         0x8009CBDC
    // 0x8080016C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8009CBDC(rdram, ctx);
        goto after_11;
    // 0x8080016C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_11:
    // 0x80800170: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800174: bne         $v0, $at, L_80800184
    if (ctx->r2 != ctx->r1) {
        // 0x80800178: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800184;
    }
    // 0x80800178: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080017C: b           L_80800378
    // 0x80800180: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800378;
    // 0x80800180: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800184:
    // 0x80800184: jal         0x80091538
    // 0x80800188: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_get(rdram, ctx);
        goto after_12;
    // 0x80800188: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x8080018C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800190: nop

    // 0x80800194: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800198: nop

    // 0x8080019C: bc1t        L_808001AC
    if (c1cs) {
        // 0x808001A0: nop
    
            goto L_808001AC;
    }
    // 0x808001A0: nop

    // 0x808001A4: b           L_80800378
    // 0x808001A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800378;
    // 0x808001A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001AC:
    // 0x808001AC: jal         0x800F8B88
    // 0x808001B0: nop

    func_800F8B88(rdram, ctx);
        goto after_13;
    // 0x808001B0: nop

    after_13:
    // 0x808001B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001B8: bne         $v0, $at, L_808001C8
    if (ctx->r2 != ctx->r1) {
        // 0x808001BC: nop
    
            goto L_808001C8;
    }
    // 0x808001BC: nop

    // 0x808001C0: b           L_80800378
    // 0x808001C4: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
        goto L_80800378;
    // 0x808001C4: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_808001C8:
    // 0x808001C8: jal         0x8008E35C
    // 0x808001CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_inWater(rdram, ctx);
        goto after_14;
    // 0x808001CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_14:
    // 0x808001D0: beq         $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808001D4: nop
    
            goto L_808001E0;
    }
    // 0x808001D4: nop

    // 0x808001D8: b           L_80800378
    // 0x808001DC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
        goto L_80800378;
    // 0x808001DC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_808001E0:
    // 0x808001E0: b           L_80800378
    // 0x808001E4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_80800378;
    // 0x808001E4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_808001E8:
    // 0x808001E8: jal         0x8008E35C
    // 0x808001EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_inWater(rdram, ctx);
        goto after_15;
    // 0x808001EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_15:
    // 0x808001F0: beq         $v0, $zero, L_80800200
    if (ctx->r2 == 0) {
        // 0x808001F4: nop
    
            goto L_80800200;
    }
    // 0x808001F4: nop

    // 0x808001F8: b           L_80800378
    // 0x808001FC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_80800378;
    // 0x808001FC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80800200:
    // 0x80800200: b           L_80800378
    // 0x80800204: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_80800378;
    // 0x80800204: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_80800208:
    // 0x80800208: b           L_80800378
    // 0x8080020C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_80800378;
    // 0x8080020C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_80800210:
    // 0x80800210: b           L_80800378
    // 0x80800214: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80800378;
    // 0x80800214: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80800218:
    // 0x80800218: b           L_80800378
    // 0x8080021C: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_80800378;
    // 0x8080021C: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_80800220:
    // 0x80800220: b           L_80800378
    // 0x80800224: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_80800378;
    // 0x80800224: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_80800228:
    // 0x80800228: b           L_80800378
    // 0x8080022C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80800378;
    // 0x8080022C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80800230:
    // 0x80800230: b           L_80800378
    // 0x80800234: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_80800378;
    // 0x80800234: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_80800238:
    // 0x80800238: b           L_80800378
    // 0x8080023C: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
        goto L_80800378;
    // 0x8080023C: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_80800240:
    // 0x80800240: b           L_80800378
    // 0x80800244: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
        goto L_80800378;
    // 0x80800244: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_80800248:
    // 0x80800248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080024C: jal         0x8009CBDC
    // 0x80800250: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8009CBDC(rdram, ctx);
        goto after_16;
    // 0x80800250: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_16:
    // 0x80800254: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800258: bne         $v0, $at, L_80800268
    if (ctx->r2 != ctx->r1) {
        // 0x8080025C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800268;
    }
    // 0x8080025C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800260: b           L_80800378
    // 0x80800264: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
        goto L_80800378;
    // 0x80800264: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
L_80800268:
    // 0x80800268: jal         0x8009CBDC
    // 0x8080026C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8009CBDC(rdram, ctx);
        goto after_17;
    // 0x8080026C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_17:
    // 0x80800270: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800274: bne         $v0, $at, L_80800284
    if (ctx->r2 != ctx->r1) {
        // 0x80800278: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800284;
    }
    // 0x80800278: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080027C: b           L_80800378
    // 0x80800280: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_80800378;
    // 0x80800280: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_80800284:
    // 0x80800284: jal         0x8009CBDC
    // 0x80800288: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8009CBDC(rdram, ctx);
        goto after_18;
    // 0x80800288: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_18:
    // 0x8080028C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800290: bne         $v0, $at, L_808002A0
    if (ctx->r2 != ctx->r1) {
        // 0x80800294: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808002A0;
    }
    // 0x80800294: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800298: b           L_80800378
    // 0x8080029C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80800378;
    // 0x8080029C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_808002A0:
    // 0x808002A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A4: jal         0x8009CA70
    // 0x808002A8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8009CA70(rdram, ctx);
        goto after_19;
    // 0x808002A8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_19:
    // 0x808002AC: beq         $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x808002B0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808002BC;
    }
    // 0x808002B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002B4: b           L_80800378
    // 0x808002B8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80800378;
    // 0x808002B8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_808002BC:
    // 0x808002BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808002C0: jal         0x8009CA70
    // 0x808002C4: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    func_8009CA70(rdram, ctx);
        goto after_20;
    // 0x808002C4: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_20:
    // 0x808002C8: beq         $v0, $zero, L_808002D8
    if (ctx->r2 == 0) {
        // 0x808002CC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808002D8;
    }
    // 0x808002CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002D0: b           L_80800378
    // 0x808002D4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_80800378;
    // 0x808002D4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_808002D8:
    // 0x808002D8: jal         0x80091538
    // 0x808002DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_get(rdram, ctx);
        goto after_21;
    // 0x808002DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_21:
    // 0x808002E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808002E4: nop

    // 0x808002E8: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x808002EC: nop

    // 0x808002F0: bc1t        L_80800300
    if (c1cs) {
        // 0x808002F4: nop
    
            goto L_80800300;
    }
    // 0x808002F4: nop

    // 0x808002F8: b           L_80800378
    // 0x808002FC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80800378;
    // 0x808002FC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80800300:
    // 0x80800300: jal         0x8009EA4C
    // 0x80800304: nop

    func_8009EA4C(rdram, ctx);
        goto after_22;
    // 0x80800304: nop

    after_22:
    // 0x80800308: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080030C: bne         $v0, $at, L_8080031C
    if (ctx->r2 != ctx->r1) {
        // 0x80800310: nop
    
            goto L_8080031C;
    }
    // 0x80800310: nop

    // 0x80800314: b           L_80800378
    // 0x80800318: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80800378;
    // 0x80800318: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8080031C:
    // 0x8080031C: jal         0x800F3ED0
    // 0x80800320: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F3ED0(rdram, ctx);
        goto after_23;
    // 0x80800320: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_23:
    // 0x80800324: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800328: bne         $v0, $at, L_80800338
    if (ctx->r2 != ctx->r1) {
        // 0x8080032C: nop
    
            goto L_80800338;
    }
    // 0x8080032C: nop

    // 0x80800330: b           L_80800378
    // 0x80800334: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_80800378;
    // 0x80800334: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_80800338:
    // 0x80800338: jal         0x8008E35C
    // 0x8080033C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_inWater(rdram, ctx);
        goto after_24;
    // 0x8080033C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_24:
    // 0x80800340: beql        $v0, $zero, L_80800378
    if (ctx->r2 == 0) {
        // 0x80800344: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80800378;
    }
    goto skip_0;
    // 0x80800344: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    skip_0:
    // 0x80800348: jal         0x800F40EC
    // 0x8080034C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F40EC(rdram, ctx);
        goto after_25;
    // 0x8080034C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_25:
    // 0x80800350: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800354: beq         $v0, $at, L_8080036C
    if (ctx->r2 == ctx->r1) {
        // 0x80800358: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080036C;
    }
    // 0x80800358: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080035C: bne         $v0, $at, L_8080036C
    if (ctx->r2 != ctx->r1) {
        // 0x80800360: nop
    
            goto L_8080036C;
    }
    // 0x80800360: nop

    // 0x80800364: b           L_80800378
    // 0x80800368: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80800378;
    // 0x80800368: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8080036C:
    // 0x8080036C: b           L_80800378
    // 0x80800370: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800378;
    // 0x80800370: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80800374: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80800378:
    // 0x80800378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080037C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

;}
RECOMP_FUNC void func_808007DC_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007E8: jal         0x80082FE8
    // 0x808007EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808007EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808007F0: jal         0x80800300
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800300_bswasher(rdram, ctx);
        goto after_1;
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007F8: jal         0x80084800
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800800: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800804: bne         $v0, $at, L_80800894
    if (ctx->r2 != ctx->r1) {
        // 0x80800808: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800894;
    }
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080080C: jal         0x800852F0
    // 0x80800810: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_decrement(rdram, ctx);
        goto after_3;
    // 0x80800810: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800818: jal         0x80091A58
    // 0x8080081C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_4;
    // 0x8080081C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800820: beq         $v0, $zero, L_80800894
    if (ctx->r2 == 0) {
        // 0x80800824: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800894;
    }
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800828: jal         0x80085330
    // 0x8080082C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_isZero(rdram, ctx);
        goto after_5;
    // 0x8080082C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800830: beq         $v0, $zero, L_80800894
    if (ctx->r2 == 0) {
        // 0x80800834: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800894;
    }
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800838: lui         $a2, 0x3F86
    ctx->r6 = S32(0X3F86 << 16);
    // 0x8080083C: lui         $a3, 0x3F93
    ctx->r7 = S32(0X3F93 << 16);
    // 0x80800840: addiu       $t6, $zero, 0x4E20
    ctx->r14 = ADD32(0, 0X4E20);
    // 0x80800844: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800848: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x8080084C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800850: jal         0x8009DBB0
    // 0x80800854: addiu       $a1, $zero, 0x573
    ctx->r5 = ADD32(0, 0X573);
    func_8009DBB0(rdram, ctx);
        goto after_6;
    // 0x80800854: addiu       $a1, $zero, 0x573
    ctx->r5 = ADD32(0, 0X573);
    after_6:
    // 0x80800858: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x8080085C: lui         $a3, 0x3F73
    ctx->r7 = S32(0X3F73 << 16);
    // 0x80800860: addiu       $t7, $zero, 0x4E20
    ctx->r15 = ADD32(0, 0X4E20);
    // 0x80800864: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800868: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x8080086C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: jal         0x8009DBB0
    // 0x80800878: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    func_8009DBB0(rdram, ctx);
        goto after_7;
    // 0x80800878: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    after_7:
    // 0x8080087C: jal         0x80085428
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawasher_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800888: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080088C: jal         0x80085338
    // 0x80800890: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _batimer_set(rdram, ctx);
        goto after_9;
    // 0x80800890: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_9:
L_80800894:
    // 0x80800894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800898: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080089C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008A0: jr          $ra
    // 0x808008A4: nop

    return;
    // 0x808008A4: nop

;}
RECOMP_FUNC void changlerbossdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1412, 0X110) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x110
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1412, 0X110));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x110
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1412, 0X110));
;}
RECOMP_FUNC void idflasha_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: jr          $ra
    // 0x80800124: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800124: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void cadbio_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003B8: jal         0x800A5630
    // 0x808003BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A5630(rdram, ctx);
        goto after_0;
    // 0x808003BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x808003C8: jal         0x800825F0
    // 0x808003CC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    _gsmaker_entrypoint_21(rdram, ctx);
        goto after_1;
    // 0x808003CC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808003D0: bne         $v0, $zero, L_808003DC
    if (ctx->r2 != 0) {
        // 0x808003D4: addiu       $t6, $zero, 0x7D
        ctx->r14 = ADD32(0, 0X7D);
            goto L_808003DC;
    }
    // 0x808003D4: addiu       $t6, $zero, 0x7D
    ctx->r14 = ADD32(0, 0X7D);
    // 0x808003D8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808003DC:
    // 0x808003DC: jal         0x800A5608
    // 0x808003E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800A5608(rdram, ctx);
        goto after_2;
    // 0x808003E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: jal         0x800825C8
    // 0x808003EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x808003EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808003F0: bnel        $v0, $zero, L_80800418
    if (ctx->r2 != 0) {
        // 0x808003F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800418;
    }
    goto skip_0;
    // 0x808003F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_808003F8:
    // 0x808003F8: jal         0x80800000
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_cadbio(rdram, ctx);
        goto after_4;
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: jal         0x800825C8
    // 0x80800408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_5;
    // 0x80800408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080040C: beq         $v0, $zero, L_808003F8
    if (ctx->r2 == 0) {
        // 0x80800410: nop
    
            goto L_808003F8;
    }
    // 0x80800410: nop

    // 0x80800414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800418:
    // 0x80800418: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080041C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800420: jr          $ra
    // 0x80800424: nop

    return;
    // 0x80800424: nop

    // 0x80800428: nop

    // 0x8080042C: nop

;}
RECOMP_FUNC void ncpoducam_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017B0: jal         0x800EE7F8
    // 0x808017B4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808017B4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_0:
    // 0x808017B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808017BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808017C0: jr          $ra
    // 0x808017C4: nop

    return;
    // 0x808017C4: nop

    // 0x808017C8: nop

    // 0x808017CC: nop

;}
RECOMP_FUNC void _sueggmove_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A470: syscall     842
    recomp_syscall_handler(rdram, ctx, 0x8008A470);
    return;
    // 0x8008A474: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _chlagoonfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DC8: syscall     457
    recomp_syscall_handler(rdram, ctx, 0x80086DC8);
    return;
    // 0x80086DCC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800EF214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF214: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EF218: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EF21C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EF220: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EF224: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EF228: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800EF22C: jal         0x800137AC
    // 0x800EF230: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800137AC(rdram, ctx);
        goto after_0;
    // 0x800EF230: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x800EF234: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800EF238: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800EF23C: jal         0x800137C4
    // 0x800EF240: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_800137C4(rdram, ctx);
        goto after_1;
    // 0x800EF240: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800EF244: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800EF248: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800EF24C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800EF250: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800EF254: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x800EF258: jal         0x800137F4
    // 0x800EF25C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_800137F4(rdram, ctx);
        goto after_2;
    // 0x800EF25C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x800EF260: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EF264: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800EF268: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800EF26C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800EF270: jal         0x80013788
    // 0x800EF274: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    func_80013788(rdram, ctx);
        goto after_3;
    // 0x800EF274: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x800EF278: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EF27C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800EF280: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800EF284: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800EF288: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x800EF28C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EF290: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EF294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800EF298: jr          $ra
    // 0x800EF29C: nop

    return;
    // 0x800EF29C: nop

;}
RECOMP_FUNC void plsu_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808000C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808000CC: jal         0x800F5898
    // 0x808000D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_0;
    // 0x808000D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x808000D4: blezl       $v0, L_8080011C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808000D8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8080011C;
    }
    goto skip_0;
    // 0x808000D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
L_808000DC:
    // 0x808000DC: jal         0x800F6BE4
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_1;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000E4: beq         $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000E8: nop
    
            goto L_80800104;
    }
    // 0x808000E8: nop

    // 0x808000EC: jal         0x800F5410
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F5410(rdram, ctx);
        goto after_2;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000F4: bne         $v0, $s1, L_80800104
    if (ctx->r2 != ctx->r17) {
        // 0x808000F8: nop
    
            goto L_80800104;
    }
    // 0x808000F8: nop

    // 0x808000FC: b           L_8080011C
    // 0x80800100: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8080011C;
    // 0x80800100: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80800104:
    // 0x80800104: jal         0x800F5898
    // 0x80800108: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_3;
    // 0x80800108: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_3:
    // 0x8080010C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800110: bne         $at, $zero, L_808000DC
    if (ctx->r1 != 0) {
        // 0x80800114: nop
    
            goto L_808000DC;
    }
    // 0x80800114: nop

    // 0x80800118: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8080011C:
    // 0x8080011C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800120: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800124: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800128: jr          $ra
    // 0x8080012C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080012C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _bswalk_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084280: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084280);
    return;
    // 0x80084284: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_80800000_bscrashout(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: lui         $a1, 0x3EBB
    ctx->r5 = S32(0X3EBB << 16);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: jal         0x8008CB10
    // 0x80800018: ori         $a1, $a1, 0x573F
    ctx->r5 = ctx->r5 | 0X573F;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80800018: ori         $a1, $a1, 0x573F
    ctx->r5 = ctx->r5 | 0X573F;
    after_0:
    // 0x8080001C: beq         $v0, $zero, L_80800034
    if (ctx->r2 == 0) {
        // 0x80800020: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800034;
    }
    // 0x80800020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800024: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80800028: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080002C: jal         0x8009DB04
    // 0x80800030: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DB04(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_1:
L_80800034:
    // 0x80800034: lui         $a1, 0x3F2F
    ctx->r5 = S32(0X3F2F << 16);
    // 0x80800038: ori         $a1, $a1, 0xAACE
    ctx->r5 = ctx->r5 | 0XAACE;
    // 0x8080003C: jal         0x8008CB10
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800044: beq         $v0, $zero, L_80800074
    if (ctx->r2 == 0) {
        // 0x80800048: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800074;
    }
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800050: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800054: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80800058: jal         0x8009DB04
    // 0x8080005C: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DB04(rdram, ctx);
        goto after_3;
    // 0x8080005C: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_3:
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: addiu       $a1, $zero, 0x427
    ctx->r5 = ADD32(0, 0X427);
    // 0x80800068: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080006C: jal         0x8009DB04
    // 0x80800070: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DB04(rdram, ctx);
        goto after_4;
    // 0x80800070: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_4:
L_80800074:
    // 0x80800074: jal         0x8008CAC8
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_5;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080007C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(148, 0X3C0) << 16);
    // 0x80800080: lwc1        $f4, 0x3C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(148, 0X3C0));
    // 0x80800084: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800088: nop

    // 0x8080008C: bc1fl       L_808000A0
    if (!c1cs) {
        // 0x80800090: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000A0;
    }
    goto skip_0;
    // 0x80800090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800094: jal         0x80084A10
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A0:
    // 0x808000A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void func_8010B94C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B94C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B954: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010B958: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010B95C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010B960: jal         0x800D8FF8
    // 0x8010B964: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8010B964: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B968: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8010B96C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8010B970: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8010B974: jal         0x800EF174
    // 0x8010B978: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    func_800EF174(rdram, ctx);
        goto after_1;
    // 0x8010B978: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    after_1:
    // 0x8010B97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B988: jr          $ra
    // 0x8010B98C: nop

    return;
    // 0x8010B98C: nop

;}
RECOMP_FUNC void _glidmake_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888A0: syscall     707
    recomp_syscall_handler(rdram, ctx, 0x800888A0);
    return;
    // 0x800888A4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chevilmumbo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803980: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1676, 0X4544) << 16);
    // 0x80803984: jr          $ra
    // 0x80803988: addiu       $v0, $v0, 0x4544
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1676, 0X4544));
    return;
    // 0x80803988: addiu       $v0, $v0, 0x4544
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1676, 0X4544));
;}
RECOMP_FUNC void baroll_resetAngularVelocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C578: lui         $a1, 0x442F
    ctx->r5 = S32(0X442F << 16);
    // 0x8009C57C: jal         0x8009C554
    // 0x8009C580: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_0;
    // 0x8009C580: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    after_0:
    // 0x8009C584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C58C: jr          $ra
    // 0x8009C590: nop

    return;
    // 0x8009C590: nop

;}
RECOMP_FUNC void func_80800308_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800308: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080030C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800310: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800314: jal         0x8009E6EC
    // 0x80800318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080031C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80800320: beq         $v0, $at, L_80800344
    if (ctx->r2 == ctx->r1) {
        // 0x80800324: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800344;
    }
    // 0x80800324: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800328: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x8080032C: beq         $v0, $at, L_80800364
    if (ctx->r2 == ctx->r1) {
        // 0x80800330: addiu       $at, $zero, 0x8D
        ctx->r1 = ADD32(0, 0X8D);
            goto L_80800364;
    }
    // 0x80800330: addiu       $at, $zero, 0x8D
    ctx->r1 = ADD32(0, 0X8D);
    // 0x80800334: beq         $v0, $at, L_8080034C
    if (ctx->r2 == ctx->r1) {
        // 0x80800338: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8080034C;
    }
    // 0x80800338: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080033C: b           L_808003D4
    // 0x80800340: nop

        goto L_808003D4;
    // 0x80800340: nop

L_80800344:
    // 0x80800344: b           L_808003DC
    // 0x80800348: sw          $t6, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r14;
        goto L_808003DC;
    // 0x80800348: sw          $t6, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r14;
L_8080034C:
    // 0x8080034C: sw          $t7, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r15;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: jal         0x8009E830
    // 0x80800358: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x80800358: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8080035C: b           L_808003E0
    // 0x80800360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003E0;
    // 0x80800360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800364:
    // 0x80800364: lw          $t8, 0x160($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X160);
    // 0x80800368: bnel        $t8, $zero, L_808003E0
    if (ctx->r24 != 0) {
        // 0x8080036C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003E0;
    }
    goto skip_0;
    // 0x8080036C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800370: jal         0x8008E40C
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E40C(rdram, ctx);
        goto after_2;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800378: beql        $v0, $zero, L_808003E0
    if (ctx->r2 == 0) {
        // 0x8080037C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003E0;
    }
    goto skip_1;
    // 0x8080037C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800380: jal         0x8009E6F8
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_3;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800388: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8080038C: beq         $v0, $at, L_808003A0
    if (ctx->r2 == ctx->r1) {
        // 0x80800390: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A0;
    }
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800398: bnel        $v0, $at, L_808003E0
    if (ctx->r2 != ctx->r1) {
        // 0x8080039C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003E0;
    }
    goto skip_2;
    // 0x8080039C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_808003A0:
    // 0x808003A0: jal         0x80099A7C
    // 0x808003A4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80099A7C(rdram, ctx);
        goto after_4;
    // 0x808003A4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x800850A8
    // 0x808003B0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _bashoessuck_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x808003B0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x808003B4: beq         $v0, $zero, L_808003DC
    if (ctx->r2 == 0) {
        // 0x808003B8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_808003DC;
    }
    // 0x808003B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808003BC: sw          $t9, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r25;
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: jal         0x8009E5C8
    // 0x808003C8: addiu       $a1, $zero, 0x17C
    ctx->r5 = ADD32(0, 0X17C);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x808003C8: addiu       $a1, $zero, 0x17C
    ctx->r5 = ADD32(0, 0X17C);
    after_6:
    // 0x808003CC: b           L_808003E0
    // 0x808003D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003E0;
    // 0x808003D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003D4:
    // 0x808003D4: jal         0x80099B94
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_7;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_808003DC:
    // 0x808003DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003E0:
    // 0x808003E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003E8: jr          $ra
    // 0x808003EC: nop

    return;
    // 0x808003EC: nop

;}
