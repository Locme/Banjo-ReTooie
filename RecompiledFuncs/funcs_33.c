#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chcrate_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FA0: syscall     486
    recomp_syscall_handler(rdram, ctx, 0x80086FA0);
    return;
    // 0x80086FA4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F1828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1828: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F182C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1830: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800F1834: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F1838: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F183C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F1840: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F1844: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F1848: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x800F184C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1850: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800F1854: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F1858: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800F185C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F1860: jal         0x8002DCA0
    // 0x800F1864: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F1864: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_0:
    // 0x800F1868: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F186C: jal         0x80013B7C
    // 0x800F1870: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_80013B7C(rdram, ctx);
        goto after_1;
    // 0x800F1870: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_1:
    // 0x800F1874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1878: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F187C: jr          $ra
    // 0x800F1880: nop

    return;
    // 0x800F1880: nop

;}
RECOMP_FUNC void func_80800518_vplight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800518: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080051C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800520: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800524: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80800528: jal         0x800C8898
    // 0x8080052C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800C8898(rdram, ctx);
        goto after_0;
    // 0x8080052C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800530: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80800534: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800538: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8080053C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800540: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80800544: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800548: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080054C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800550: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80800554: nop

    // 0x80800558: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8080055C: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800560: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80800564: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800568: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8080056C: nop

    // 0x80800570: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80800574: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800578: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080057C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800580: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80800584: nop

    // 0x80800588: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    // 0x8080058C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800590: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800594: jr          $ra
    // 0x80800598: nop

    return;
    // 0x80800598: nop

;}
RECOMP_FUNC void fxrain_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800440: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800444: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80800448: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080044C: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x80800450: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8DC) << 16);
    // 0x80800454: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x80800458: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080045C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800460: lwc1        $f6, 0x8DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8DC));
    // 0x80800464: swc1        $f12, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f12.u32l;
    // 0x80800468: swc1        $f14, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f14.u32l;
    // 0x8080046C: swc1        $f6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f6.u32l;
    // 0x80800470: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80800474: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    // 0x80800478: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8080047C: jr          $ra
    // 0x80800480: swc1        $f10, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80800480: swc1        $f10, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void _subaddieskeleton_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0E0: syscall     828
    recomp_syscall_handler(rdram, ctx, 0x8008A0E0);
    return;
    // 0x8008A0E4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80014F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014F38: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014F3C: lh          $v0, -0x70A0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X70A0);
    // 0x80014F40: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80014F44: jr          $ra
    // 0x80014F48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x80014F48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void _badust_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849F0: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x800849F0);
    return;
    // 0x800849F4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808000E8_gztrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000F4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808000F8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808000FC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800100: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80800104: jal         0x808000B8
    // 0x80800108: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_808000B8_gztrace(rdram, ctx);
        goto after_0;
    // 0x80800108: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080010C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80800110: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800114: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80800118: addu        $t1, $s0, $t4
    ctx->r9 = ADD32(ctx->r16, ctx->r12);
    // 0x8080011C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80800120: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800124: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800128: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8080012C: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80800130: bne         $at, $zero, L_808001C4
    if (ctx->r1 != 0) {
        // 0x80800134: or          $t3, $t7, $zero
        ctx->r11 = ctx->r15 | 0;
            goto L_808001C4;
    }
    // 0x80800134: or          $t3, $t7, $zero
    ctx->r11 = ctx->r15 | 0;
    // 0x80800138: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8080013C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80800140: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80800144: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80800148: jal         0x80800038
    // 0x8080014C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    func_80800038_gztrace(rdram, ctx);
        goto after_1;
    // 0x8080014C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_1:
    // 0x80800150: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800154: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80800158: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8080015C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80800160: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800164: beq         $at, $zero, L_80800274
    if (ctx->r1 == 0) {
        // 0x80800168: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80800274;
    }
    // 0x80800168: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080016C: subu        $v0, $t1, $a2
    ctx->r2 = SUB32(ctx->r9, ctx->r6);
    // 0x80800170: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x80800174: beq         $t8, $zero, L_80800198
    if (ctx->r24 == 0) {
        // 0x80800178: addu        $a0, $t8, $a2
        ctx->r4 = ADD32(ctx->r24, ctx->r6);
            goto L_80800198;
    }
    // 0x80800178: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    // 0x8080017C: addu        $v1, $t2, $a2
    ctx->r3 = ADD32(ctx->r10, ctx->r6);
    // 0x80800180: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_80800184:
    // 0x80800184: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800188: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8080018C: bne         $a0, $a1, L_80800184
    if (ctx->r4 != ctx->r5) {
        // 0x80800190: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800184;
    }
    // 0x80800190: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800194: beq         $a1, $t1, L_80800274
    if (ctx->r5 == ctx->r9) {
        // 0x80800198: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_80800274;
    }
L_80800198:
    // 0x80800198: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8080019C: addu        $v1, $t2, $a1
    ctx->r3 = ADD32(ctx->r10, ctx->r5);
L_808001A0:
    // 0x808001A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808001A4: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x808001A8: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x808001AC: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x808001B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808001B4: bne         $a1, $a3, L_808001A0
    if (ctx->r5 != ctx->r7) {
        // 0x808001B8: sb          $v0, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = ctx->r2;
            goto L_808001A0;
    }
    // 0x808001B8: sb          $v0, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r2;
    // 0x808001BC: b           L_80800278
    // 0x808001C0: addu        $t6, $t2, $t1
    ctx->r14 = ADD32(ctx->r10, ctx->r9);
        goto L_80800278;
    // 0x808001C0: addu        $t6, $t2, $t1
    ctx->r14 = ADD32(ctx->r10, ctx->r9);
L_808001C4:
    // 0x808001C4: blez        $s0, L_80800234
    if (SIGNED(ctx->r16) <= 0) {
        // 0x808001C8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800234;
    }
    // 0x808001C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001CC: andi        $t0, $s0, 0x3
    ctx->r8 = ctx->r16 & 0X3;
    // 0x808001D0: beq         $t0, $zero, L_808001FC
    if (ctx->r8 == 0) {
        // 0x808001D4: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_808001FC;
    }
    // 0x808001D4: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x808001D8: addu        $v1, $t2, $zero
    ctx->r3 = ADD32(ctx->r10, 0);
    // 0x808001DC: addu        $a0, $t3, $zero
    ctx->r4 = ADD32(ctx->r11, 0);
L_808001E0:
    // 0x808001E0: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x808001E4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x808001E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808001EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808001F0: bne         $a2, $a1, L_808001E0
    if (ctx->r6 != ctx->r5) {
        // 0x808001F4: sb          $t9, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r25;
            goto L_808001E0;
    }
    // 0x808001F4: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x808001F8: beq         $a1, $s0, L_80800234
    if (ctx->r5 == ctx->r16) {
        // 0x808001FC: addu        $v1, $t2, $a1
        ctx->r3 = ADD32(ctx->r10, ctx->r5);
            goto L_80800234;
    }
L_808001FC:
    // 0x808001FC: addu        $v1, $t2, $a1
    ctx->r3 = ADD32(ctx->r10, ctx->r5);
    // 0x80800200: addu        $a0, $t3, $a1
    ctx->r4 = ADD32(ctx->r11, ctx->r5);
L_80800204:
    // 0x80800204: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x80800208: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8080020C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800210: sb          $t5, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r13;
    // 0x80800214: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x80800218: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080021C: sb          $t6, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r14;
    // 0x80800220: lbu         $t7, -0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, -0X2);
    // 0x80800224: sb          $t7, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r15;
    // 0x80800228: lbu         $t8, -0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, -0X1);
    // 0x8080022C: bne         $a1, $s0, L_80800204
    if (ctx->r5 != ctx->r16) {
        // 0x80800230: sb          $t8, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r24;
            goto L_80800204;
    }
    // 0x80800230: sb          $t8, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r24;
L_80800234:
    // 0x80800234: addu        $v1, $t2, $a1
    ctx->r3 = ADD32(ctx->r10, ctx->r5);
    // 0x80800238: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x8080023C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800240: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800244: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800248: subu        $a0, $v0, $t4
    ctx->r4 = SUB32(ctx->r2, ctx->r12);
    // 0x8080024C: beq         $at, $zero, L_80800274
    if (ctx->r1 == 0) {
        // 0x80800250: sb          $t9, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r25;
            goto L_80800274;
    }
    // 0x80800250: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x80800254: addu        $v0, $a0, $t3
    ctx->r2 = ADD32(ctx->r4, ctx->r11);
L_80800258:
    // 0x80800258: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x8080025C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800260: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80800264: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800268: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080026C: bne         $at, $zero, L_80800258
    if (ctx->r1 != 0) {
        // 0x80800270: sb          $t5, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r13;
            goto L_80800258;
    }
    // 0x80800270: sb          $t5, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r13;
L_80800274:
    // 0x80800274: addu        $t6, $t2, $t1
    ctx->r14 = ADD32(ctx->r10, ctx->r9);
L_80800278:
    // 0x80800278: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8080027C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800280: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800284: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800288: jr          $ra
    // 0x8080028C: nop

    return;
    // 0x8080028C: nop

;}
RECOMP_FUNC void _bskazstill_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083650: syscall     70
    recomp_syscall_handler(rdram, ctx, 0x80083650);
    return;
    // 0x80083654: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800D62E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D62E4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D62E8: lh          $t6, -0x419C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X419C);
    // 0x800D62EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D62F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D62F4: beql        $t6, $zero, L_800D636C
    if (ctx->r14 == 0) {
        // 0x800D62F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D636C;
    }
    goto skip_0;
    // 0x800D62F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D62FC: jal         0x800D6254
    // 0x800D6300: nop

    func_800D6254(rdram, ctx);
        goto after_0;
    // 0x800D6300: nop

    after_0:
    // 0x800D6304: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800D6308: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800D630C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D6310: addiu       $t8, $t8, -0x4800
    ctx->r24 = ADD32(ctx->r24, -0X4800);
    // 0x800D6314: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D6318: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800D631C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800D6320: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D6324: sll         $t0, $t9, 27
    ctx->r8 = S32(ctx->r25 << 27);
    // 0x800D6328: srl         $t1, $t0, 28
    ctx->r9 = S32(U32(ctx->r8) >> 28);
    // 0x800D632C: bne         $t1, $at, L_800D6360
    if (ctx->r9 != ctx->r1) {
        // 0x800D6330: nop
    
            goto L_800D6360;
    }
    // 0x800D6330: nop

    // 0x800D6334: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800D6338: sll         $t4, $t2, 14
    ctx->r12 = S32(ctx->r10 << 14);
    // 0x800D633C: bgez        $t4, L_800D6360
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800D6340: nop
    
            goto L_800D6360;
    }
    // 0x800D6340: nop

    // 0x800D6344: lhu         $t5, 0x8($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X8);
    // 0x800D6348: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800D634C: bne         $t6, $zero, L_800D6360
    if (ctx->r14 != 0) {
        // 0x800D6350: nop
    
            goto L_800D6360;
    }
    // 0x800D6350: nop

    // 0x800D6354: lbu         $t7, 0x9($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X9);
    // 0x800D6358: andi        $t8, $t7, 0xFFFD
    ctx->r24 = ctx->r15 & 0XFFFD;
    // 0x800D635C: sb          $t8, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r24;
L_800D6360:
    // 0x800D6360: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D6364: sh          $zero, -0x419C($at)
    MEM_H(-0X419C, ctx->r1) = 0;
    // 0x800D6368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D636C:
    // 0x800D636C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D6370: jr          $ra
    // 0x800D6374: nop

    return;
    // 0x800D6374: nop

;}
RECOMP_FUNC void _gcmapDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088100: syscall     672
    recomp_syscall_handler(rdram, ctx, 0x80088100);
    return;
    // 0x80088104: xori        $t0, $zero, 0x4
    ctx->r8 = 0 ^ 0X4;
;}
RECOMP_FUNC void sucoasterfly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800CF4: slti        $at, $a1, 0x39
    ctx->r1 = SIGNED(ctx->r5) < 0X39 ? 1 : 0;
    // 0x80800CF8: bne         $at, $zero, L_80800D2C
    if (ctx->r1 != 0) {
        // 0x80800CFC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800D2C;
    }
    // 0x80800CFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D00: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x80800D04: beq         $a1, $at, L_80800E24
    if (ctx->r5 == ctx->r1) {
        // 0x80800D08: addiu       $at, $zero, 0x8F
        ctx->r1 = ADD32(0, 0X8F);
            goto L_80800E24;
    }
    // 0x80800D08: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x80800D0C: beq         $a1, $at, L_80800DD0
    if (ctx->r5 == ctx->r1) {
        // 0x80800D10: addiu       $at, $zero, 0x94
        ctx->r1 = ADD32(0, 0X94);
            goto L_80800DD0;
    }
    // 0x80800D10: addiu       $at, $zero, 0x94
    ctx->r1 = ADD32(0, 0X94);
    // 0x80800D14: beq         $a1, $at, L_80800E4C
    if (ctx->r5 == ctx->r1) {
        // 0x80800D18: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800E4C;
    }
    // 0x80800D18: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800D1C: beq         $a1, $at, L_80800E98
    if (ctx->r5 == ctx->r1) {
        // 0x80800D20: nop
    
            goto L_80800E98;
    }
    // 0x80800D20: nop

    // 0x80800D24: b           L_80800EE0
    // 0x80800D28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EE0;
    // 0x80800D28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D2C:
    // 0x80800D2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D30: beq         $a1, $at, L_80800D60
    if (ctx->r5 == ctx->r1) {
        // 0x80800D34: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800D60;
    }
    // 0x80800D34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D38: beq         $a1, $at, L_80800D70
    if (ctx->r5 == ctx->r1) {
        // 0x80800D3C: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_80800D70;
    }
    // 0x80800D3C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80800D40: beq         $a1, $at, L_80800E04
    if (ctx->r5 == ctx->r1) {
        // 0x80800D44: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_80800E04;
    }
    // 0x80800D44: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80800D48: beq         $a1, $at, L_80800E14
    if (ctx->r5 == ctx->r1) {
        // 0x80800D4C: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_80800E14;
    }
    // 0x80800D4C: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80800D50: beq         $a1, $at, L_80800EA8
    if (ctx->r5 == ctx->r1) {
        // 0x80800D54: nop
    
            goto L_80800EA8;
    }
    // 0x80800D54: nop

    // 0x80800D58: b           L_80800EE0
    // 0x80800D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EE0;
    // 0x80800D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D60:
    // 0x80800D60: jal         0x808014AC
    // 0x80800D64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_0;
    // 0x80800D64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800D68: b           L_80800EE0
    // 0x80800D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EE0;
    // 0x80800D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D70:
    // 0x80800D70: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800D74: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800D78: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800D7C: beql        $t7, $at, L_80800EE0
    if (ctx->r15 == ctx->r1) {
        // 0x80800D80: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800EE0;
    }
    goto skip_0;
    // 0x80800D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800D84: jal         0x8008A4A8
    // 0x80800D88: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800D88: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800D8C: bne         $v0, $zero, L_80800EDC
    if (ctx->r2 != 0) {
        // 0x80800D90: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800EDC;
    }
    // 0x80800D90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800D94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D98: jal         0x80107070
    // 0x80800D9C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80107070(rdram, ctx);
        goto after_2;
    // 0x80800D9C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800DA0: bne         $v0, $zero, L_80800EDC
    if (ctx->r2 != 0) {
        // 0x80800DA4: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800EDC;
    }
    // 0x80800DA4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800DA8: jal         0x80089CA8
    // 0x80800DAC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800DAC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800DB0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800DB4: jal         0x808014AC
    // 0x80800DB8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_4;
    // 0x80800DB8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_4:
    // 0x80800DBC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800DC0: lbu         $t8, 0x64($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X64);
    // 0x80800DC4: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80800DC8: b           L_80800EDC
    // 0x80800DCC: sb          $t9, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r25;
        goto L_80800EDC;
    // 0x80800DCC: sb          $t9, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r25;
L_80800DD0:
    // 0x80800DD0: bnel        $a2, $zero, L_80800EE0
    if (ctx->r6 != 0) {
        // 0x80800DD4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800EE0;
    }
    goto skip_1;
    // 0x80800DD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800DD8: lbu         $t3, 0x77($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X77);
    // 0x80800DDC: lbu         $t1, 0x64($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X64);
    // 0x80800DE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800DE4: andi        $t4, $t3, 0xFFF0
    ctx->r12 = ctx->r11 & 0XFFF0;
    // 0x80800DE8: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80800DEC: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x80800DF0: sb          $t2, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r10;
    // 0x80800DF4: jal         0x808014AC
    // 0x80800DF8: sb          $t5, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r13;
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_5;
    // 0x80800DF8: sb          $t5, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r13;
    after_5:
    // 0x80800DFC: b           L_80800EE0
    // 0x80800E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EE0;
    // 0x80800E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E04:
    // 0x80800E04: jal         0x80802080
    // 0x80800E08: nop

    func_80802080_sucoasterfly(rdram, ctx);
        goto after_6;
    // 0x80800E08: nop

    after_6:
    // 0x80800E0C: b           L_80800EE0
    // 0x80800E10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EE0;
    // 0x80800E10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E14:
    // 0x80800E14: jal         0x80802128
    // 0x80800E18: nop

    func_80802128_sucoasterfly(rdram, ctx);
        goto after_7;
    // 0x80800E18: nop

    after_7:
    // 0x80800E1C: b           L_80800EE0
    // 0x80800E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EE0;
    // 0x80800E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E24:
    // 0x80800E24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E28: jal         0x8008A4B0
    // 0x80800E2C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800E2C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_8:
    // 0x80800E30: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800E34: jal         0x80107070
    // 0x80800E38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_9;
    // 0x80800E38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800E3C: bnel        $v0, $zero, L_80800EE0
    if (ctx->r2 != 0) {
        // 0x80800E40: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800EE0;
    }
    goto skip_2;
    // 0x80800E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80800E44: b           L_80800EE0
    // 0x80800E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EE0;
    // 0x80800E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E4C:
    // 0x80800E4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E50: jal         0x80100094
    // 0x80800E54: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x80800E54: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_10:
    // 0x80800E58: bne         $v0, $zero, L_80800E68
    if (ctx->r2 != 0) {
        // 0x80800E5C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800E68;
    }
    // 0x80800E5C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800E60: b           L_80800EE0
    // 0x80800E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EE0;
    // 0x80800E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E68:
    // 0x80800E68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800E6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E70: jal         0x80100094
    // 0x80800E74: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80800E74: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x80800E78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E7C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800E80: jal         0x800897F0
    // 0x80800E84: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    _suexpression_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x80800E84: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_12:
    // 0x80800E88: jal         0x80101010
    // 0x80800E8C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80101010(rdram, ctx);
        goto after_13;
    // 0x80800E8C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_13:
    // 0x80800E90: b           L_80800EE0
    // 0x80800E94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EE0;
    // 0x80800E94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E98:
    // 0x80800E98: jal         0x80089F60
    // 0x80800E9C: nop

    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x80800E9C: nop

    after_14:
    // 0x80800EA0: b           L_80800EE0
    // 0x80800EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EE0;
    // 0x80800EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EA8:
    // 0x80800EA8: jal         0x80100094
    // 0x80800EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_15;
    // 0x80800EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80800EB0: lbu         $a0, 0x11($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X11);
    // 0x80800EB4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800EB8: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x80800EBC: jal         0x8008A278
    // 0x80800EC0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterflydata_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x80800EC0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_16:
    // 0x80800EC4: jal         0x80101074
    // 0x80800EC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80101074(rdram, ctx);
        goto after_17;
    // 0x80800EC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x80800ECC: b           L_80800EE0
    // 0x80800ED0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80800EE0;
    // 0x80800ED0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800ED4: b           L_80800EE0
    // 0x80800ED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EE0;
    // 0x80800ED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EDC:
    // 0x80800EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EE0:
    // 0x80800EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800EE8: jr          $ra
    // 0x80800EEC: nop

    return;
    // 0x80800EEC: nop

;}
RECOMP_FUNC void _gldbDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888B8: syscall     708
    recomp_syscall_handler(rdram, ctx, 0x800888B8);
    return;
    // 0x800888BC: xori        $t0, $zero, 0x8
    ctx->r8 = 0 ^ 0X8;
;}
RECOMP_FUNC void subaddiefade_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: lbu         $t6, 0x9B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9B);
    // 0x80800070: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x80800074: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80800078: bne         $at, $zero, L_80800088
    if (ctx->r1 != 0) {
        // 0x8080007C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800088;
    }
    // 0x8080007C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800080: b           L_80800088
    // 0x80800084: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_80800088;
    // 0x80800084: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80800088:
    // 0x80800088: bgez        $v1, L_80800098
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8080008C: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_80800098;
    }
    // 0x8080008C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80800090: jr          $ra
    // 0x80800094: sb          $zero, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = 0;
    return;
    // 0x80800094: sb          $zero, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = 0;
L_80800098:
    // 0x80800098: bne         $at, $zero, L_808000A8
    if (ctx->r1 != 0) {
        // 0x8080009C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808000A8;
    }
    // 0x8080009C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808000A0: b           L_808000A8
    // 0x808000A4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_808000A8;
    // 0x808000A4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_808000A8:
    // 0x808000A8: sb          $v1, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r3;
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_8001A2D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A2D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A2D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A2D8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A2DC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A2E0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001A2E4: sh          $zero, -0x4128($at)
    MEM_H(-0X4128, ctx->r1) = 0;
    // 0x8001A2E8: addiu       $a1, $a1, -0x4108
    ctx->r5 = ADD32(ctx->r5, -0X4108);
    // 0x8001A2EC: addiu       $a0, $a0, -0x4120
    ctx->r4 = ADD32(ctx->r4, -0X4120);
    // 0x8001A2F0: jal         0x8002E070
    // 0x8001A2F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8001A2F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8001A2F8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A2FC: addiu       $a0, $a0, -0x4120
    ctx->r4 = ADD32(ctx->r4, -0X4120);
    // 0x8001A300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A304: jal         0x8002EAD0
    // 0x8001A308: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8001A308: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8001A30C: jal         0x80014C40
    // 0x8001A310: nop

    func_80014C40(rdram, ctx);
        goto after_2;
    // 0x8001A310: nop

    after_2:
    // 0x8001A314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A31C: jr          $ra
    // 0x8001A320: nop

    return;
    // 0x8001A320: nop

;}
RECOMP_FUNC void func_800F6308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6308: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F630C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6310: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F6314: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F6318: jal         0x800A8FDC
    // 0x800F631C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800A8FDC(rdram, ctx);
        goto after_0;
    // 0x800F631C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800F6320: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F6324: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800F6328: jal         0x800A907C
    // 0x800F632C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800A907C(rdram, ctx);
        goto after_1;
    // 0x800F632C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x800F6330: jal         0x800F43A8
    // 0x800F6334: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F43A8(rdram, ctx);
        goto after_2;
    // 0x800F6334: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800F6338: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800F633C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6340: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800F6344: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800F6348: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800F634C: sw          $v0, 0x5490($at)
    MEM_W(0X5490, ctx->r1) = ctx->r2;
    // 0x800F6350: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F6354: jal         0x80091BF0
    // 0x800F6358: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bakey_setControllerIndex(rdram, ctx);
        goto after_3;
    // 0x800F6358: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x800F635C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6360: jal         0x800F452C
    // 0x800F6364: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800F452C(rdram, ctx);
        goto after_4;
    // 0x800F6364: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x800F6368: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800F636C: jal         0x800A92A8
    // 0x800F6370: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A92A8(rdram, ctx);
        goto after_5;
    // 0x800F6370: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x800F6374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6378: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800F637C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6380: jr          $ra
    // 0x800F6384: nop

    return;
    // 0x800F6384: nop

;}
RECOMP_FUNC void func_808065F4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808065F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808065F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808065FC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80806600: lbu         $t6, 0x79($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X79);
    // 0x80806604: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(804, 0X7DB0) << 16);
    // 0x80806608: lw          $a0, 0x2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C);
    // 0x8080660C: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80806610: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80806614: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80806618: lh          $a1, 0x7DB0($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(804, 0X7DB0));
    // 0x8080661C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80806620: jal         0x80802640
    // 0x80806624: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802640_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80806624: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80806628: jal         0x800AA240
    // 0x8080662C: nop

    func_800AA240(rdram, ctx);
        goto after_1;
    // 0x8080662C: nop

    after_1:
    // 0x80806630: beq         $v0, $zero, L_808066B4
    if (ctx->r2 == 0) {
        // 0x80806634: nop
    
            goto L_808066B4;
    }
    // 0x80806634: nop

    // 0x80806638: jal         0x800AA0D0
    // 0x8080663C: nop

    func_800AA0D0(rdram, ctx);
        goto after_2;
    // 0x8080663C: nop

    after_2:
    // 0x80806640: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80806644: bne         $v0, $at, L_8080665C
    if (ctx->r2 != ctx->r1) {
        // 0x80806648: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080665C;
    }
    // 0x80806648: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080664C: jal         0x800AA074
    // 0x80806650: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800AA074(rdram, ctx);
        goto after_3;
    // 0x80806650: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_3:
    // 0x80806654: b           L_8080668C
    // 0x80806658: nop

        goto L_8080668C;
    // 0x80806658: nop

L_8080665C:
    // 0x8080665C: jal         0x808066CC
    // 0x80806660: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_808066CC_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80806660: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_4:
    // 0x80806664: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80806668: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8080666C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80806670: bnel        $v0, $v1, L_8080668C
    if (ctx->r2 != ctx->r3) {
        // 0x80806674: sw          $t0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r8;
            goto L_8080668C;
    }
    goto skip_0;
    // 0x80806674: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    skip_0:
    // 0x80806678: jal         0x800AA074
    // 0x8080667C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_800AA074(rdram, ctx);
        goto after_5;
    // 0x8080667C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_5:
    // 0x80806680: b           L_8080668C
    // 0x80806684: nop

        goto L_8080668C;
    // 0x80806684: nop

    // 0x80806688: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_8080668C:
    // 0x8080668C: jal         0x800AA00C
    // 0x80806690: nop

    func_800AA00C(rdram, ctx);
        goto after_6;
    // 0x80806690: nop

    after_6:
    // 0x80806694: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806698: jal         0x80805474
    // 0x8080669C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_80805474_chgameselect(rdram, ctx);
        goto after_7;
    // 0x8080669C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_7:
    // 0x808066A0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808066A4: jal         0x80803D00
    // 0x808066A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80803D00_chgameselect(rdram, ctx);
        goto after_8;
    // 0x808066A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808066AC: b           L_808066C0
    // 0x808066B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808066C0;
    // 0x808066B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808066B4:
    // 0x808066B4: jal         0x80806744
    // 0x808066B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80806744_chgameselect(rdram, ctx);
        goto after_9;
    // 0x808066B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x808066BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808066C0:
    // 0x808066C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808066C4: jr          $ra
    // 0x808066C8: nop

    return;
    // 0x808066C8: nop

;}
RECOMP_FUNC void _ncbadolly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089370: syscall     775
    recomp_syscall_handler(rdram, ctx, 0x80089370);
    return;
    // 0x80089374: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void subaddiebounce_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8080000C: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80800010: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800014: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800018: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8080001C: addiu       $a1, $a3, 0x18
    ctx->r5 = ADD32(ctx->r7, 0X18);
    // 0x80800020: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    // 0x80800024: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x80800028: bc1t        L_80800040
    if (c1cs) {
        // 0x8080002C: nop
    
            goto L_80800040;
    }
    // 0x8080002C: nop

    // 0x80800030: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80800034: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80800038: nop

    // 0x8080003C: bc1f        L_80800084
    if (!c1cs) {
        // 0x80800040: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(3162, 0X270) << 16);
            goto L_80800084;
    }
L_80800040:
    // 0x80800040: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3162, 0X270) << 16);
    // 0x80800044: lwc1        $f12, 0x270($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3162, 0X270));
    // 0x80800048: lwc1        $f8, 0x34($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8080004C: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80800050: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80800054: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80800058: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8080005C: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800060: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800064: nop

    // 0x80800068: bc1t        L_80800040
    if (c1cs) {
        // 0x8080006C: nop
    
            goto L_80800040;
    }
    // 0x8080006C: nop

    // 0x80800070: lwc1        $f18, 0x1C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80800074: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x80800078: nop

    // 0x8080007C: bc1t        L_80800040
    if (c1cs) {
        // 0x80800080: nop
    
            goto L_80800040;
    }
    // 0x80800080: nop

L_80800084:
    // 0x80800084: addiu       $a0, $a3, 0x28
    ctx->r4 = ADD32(ctx->r7, 0X28);
    // 0x80800088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080008C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80800090: jal         0x800EFB24
    // 0x80800094: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x80800094: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80800098: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080009C: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808000A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000A8: div.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x808000AC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808000B0: jal         0x800EF334
    // 0x808000B4: nop

    func_800EF334(rdram, ctx);
        goto after_1;
    // 0x808000B4: nop

    after_1:
    // 0x808000B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808000BC: lwc1        $f8, 0x24($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X24);
    // 0x808000C0: swc1        $f8, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f8.u32l;
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082578: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082578);
    return;
    // 0x8008257C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_801017D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801017D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801017D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801017D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801017DC: jal         0x801039E4
    // 0x801017E0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_801039E4(rdram, ctx);
        goto after_0;
    // 0x801017E0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x801017E4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x801017E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801017EC: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x801017F0: jal         0x8010108C
    // 0x801017F4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8010108C(rdram, ctx);
        goto after_1;
    // 0x801017F4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x801017F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801017FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80101800: jr          $ra
    // 0x80101804: nop

    return;
    // 0x80101804: nop

;}
RECOMP_FUNC void func_80803AF0_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803AF0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80803AF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803AF8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80803AFC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80803B00: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80803B04: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80803B08: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80803B0C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80803B10: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80803B14: jal         0x80800DAC
    // 0x80803B18: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80800DAC_chflysaucer(rdram, ctx);
        goto after_0;
    // 0x80803B18: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80803B1C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80803B20: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80803B24: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80803B28: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80803B2C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1692, 0X46C4) << 16);
    // 0x80803B30: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80803B34: addiu       $a3, $a3, 0x46C4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1692, 0X46C4));
    // 0x80803B38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80803B3C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80803B40: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80803B44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80803B48: jal         0x808039B8
    // 0x80803B4C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_808039B8_chflysaucer(rdram, ctx);
        goto after_1;
    // 0x80803B4C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80803B50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803B54: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80803B58: jr          $ra
    // 0x80803B5C: nop

    return;
    // 0x80803B5C: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801EEC: jal         0x8080061C
    // 0x80801EF0: nop

    func_8080061C_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80801EF0: nop

    after_0:
    // 0x80801EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801EF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801EFC: jr          $ra
    // 0x80801F00: nop

    return;
    // 0x80801F00: nop

;}
RECOMP_FUNC void _glglobaldata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885A8: syscall     694
    recomp_syscall_handler(rdram, ctx, 0x800885A8);
    return;
    // 0x800885AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800EB0_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EB8: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80800EBC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800EC0: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x80800EC4: bltz        $t8, L_80800EE0
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800EC8: nop
    
            goto L_80800EE0;
    }
    // 0x80800EC8: nop

    // 0x80800ECC: lw          $t9, 0x64($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X64);
    // 0x80800ED0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800ED4: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x80800ED8: bgez        $t1, L_80800EE8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800EDC: nop
    
            goto L_80800EE8;
    }
    // 0x80800EDC: nop

L_80800EE0:
    // 0x80800EE0: b           L_80800F38
    // 0x80800EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F38;
    // 0x80800EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EE8:
    // 0x80800EE8: jal         0x800EA068
    // 0x80800EEC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EA068(rdram, ctx);
        goto after_0;
    // 0x80800EEC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800EF0: beq         $v0, $zero, L_80800F00
    if (ctx->r2 == 0) {
        // 0x80800EF4: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800F00;
    }
    // 0x80800EF4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800EF8: b           L_80800F38
    // 0x80800EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F38;
    // 0x80800EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F00:
    // 0x80800F00: addiu       $a0, $a1, 0x28
    ctx->r4 = ADD32(ctx->r5, 0X28);
    // 0x80800F04: jal         0x800D9078
    // 0x80800F08: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80800F08: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800F0C: beq         $v0, $zero, L_80800F34
    if (ctx->r2 == 0) {
        // 0x80800F10: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800F34;
    }
    // 0x80800F10: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800F14: lhu         $t2, 0x64($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X64);
    // 0x80800F18: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80800F1C: beql        $t3, $zero, L_80800F38
    if (ctx->r11 == 0) {
        // 0x80800F20: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800F38;
    }
    goto skip_0;
    // 0x80800F20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800F24: jal         0x80089CA8
    // 0x80800F28: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800F28: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80800F2C: b           L_80800F38
    // 0x80800F30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F38;
    // 0x80800F30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F34:
    // 0x80800F34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F38:
    // 0x80800F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F40: jr          $ra
    // 0x80800F44: nop

    return;
    // 0x80800F44: nop

;}
RECOMP_FUNC void func_8080160C_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080160C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801614: jal         0x808002D4
    // 0x80801618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080161C: jal         0x800839C8
    // 0x80801620: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80801620: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080162C: jr          $ra
    // 0x80801630: nop

    return;
    // 0x80801630: nop

;}
RECOMP_FUNC void func_80806CF8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806CF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806CFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806D00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80806D04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80806D08: jal         0x80100094
    // 0x80806D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806D10: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80806D14: addiu       $a0, $zero, 0x4F2
    ctx->r4 = ADD32(0, 0X4F2);
    // 0x80806D18: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80806D1C: bnel        $t6, $zero, L_80806D78
    if (ctx->r14 != 0) {
        // 0x80806D20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80806D78;
    }
    goto skip_0;
    // 0x80806D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80806D24: jal         0x801084B0
    // 0x80806D28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x80806D28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80806D2C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80806D30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806D34: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80806D38: jal         0x8008A0D0
    // 0x80806D3C: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80806D3C: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x80806D40: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80806D44: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80806D48: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80806D4C: lbu         $a0, 0x5E($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X5E);
    // 0x80806D50: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80806D54: sb          $t9, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r25;
    // 0x80806D58: blez        $a0, L_80806D68
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80806D5C: sw          $t8, 0x64($v1)
        MEM_W(0X64, ctx->r3) = ctx->r24;
            goto L_80806D68;
    }
    // 0x80806D5C: sw          $t8, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r24;
    // 0x80806D60: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x80806D64: sb          $t0, 0x5E($v1)
    MEM_B(0X5E, ctx->r3) = ctx->r8;
L_80806D68:
    // 0x80806D68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806D6C: jal         0x80800180
    // 0x80806D70: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80806D70: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_3:
    // 0x80806D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806D78:
    // 0x80806D78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806D7C: jr          $ra
    // 0x80806D80: nop

    return;
    // 0x80806D80: nop

;}
RECOMP_FUNC void func_80800DA8_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800DAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DB0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800DB4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800DB8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800DBC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800DC0: jal         0x80100094
    // 0x80800DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800DCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800DD0: jal         0x80102424
    // 0x80800DD4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800DD4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800DD8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DDC: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80800DE0: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x80800DE4: beq         $at, $zero, L_8080108C
    if (ctx->r1 == 0) {
        // 0x80800DE8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080108C;
    }
    // 0x80800DE8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800DEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X24BC) << 16);
    // 0x80800DF0: addu        $at, $at, $t7
    gpr jr_addend_80800DF8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800DF4: lw          $t7, 0x24BC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1312, 0X24BC));
    // 0x80800DF8: jr          $t7
    // 0x80800DFC: nop

    switch (jr_addend_80800DF8 >> 2) {
        case 0: goto L_80800E00; break;
        case 1: goto L_80800E28; break;
        case 2: goto L_8080108C; break;
        case 3: goto L_80800E54; break;
        case 4: goto L_8080108C; break;
        case 5: goto L_80800F9C; break;
        case 6: goto L_80800EC0; break;
        case 7: goto L_80800F5C; break;
        case 8: goto L_8080108C; break;
        case 9: goto L_80800FBC; break;
        case 10: goto L_80800EF4; break;
        case 11: goto L_80800F88; break;
        case 12: goto L_8080108C; break;
        case 13: goto L_80800FBC; break;
        case 14: goto L_80800F28; break;
        case 15: goto L_80800F88; break;
        case 16: goto L_8080108C; break;
        case 17: goto L_80800FBC; break;
        case 18: goto L_80800FD4; break;
        case 19: goto L_80800F88; break;
        case 20: goto L_8080108C; break;
        case 21: goto L_80801008; break;
        case 22: goto L_8080103C; break;
        case 23: goto L_80801074; break;
        default: switch_error(__func__, 0x80800DF8, 0x808024BC);
    }
    // 0x80800DFC: nop

L_80800E00:
    // 0x80800E00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800E04: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800E08: jal         0x80801E24
    // 0x80800E0C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80801E24_chstatueboss(rdram, ctx);
        goto after_2;
    // 0x80800E0C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_2:
    // 0x80800E10: addiu       $a0, $zero, 0x450
    ctx->r4 = ADD32(0, 0X450);
    // 0x80800E14: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800E18: jal         0x80101180
    // 0x80800E1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x80800E1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800E20: b           L_80801090
    // 0x80800E24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801090;
    // 0x80800E24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E28:
    // 0x80800E28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800E2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E30: jal         0x80801E24
    // 0x80800E34: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80801E24_chstatueboss(rdram, ctx);
        goto after_4;
    // 0x80800E34: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_4:
    // 0x80800E38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800E3C: jal         0x80108B04
    // 0x80800E40: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x80800E40: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800E44: jal         0x800FDC28
    // 0x80800E48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_6;
    // 0x80800E48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80800E4C: b           L_80801090
    // 0x80800E50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801090;
    // 0x80800E50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E54:
    // 0x80800E54: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800E58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800E5C:
    // 0x80800E5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800E60: jal         0x80801640
    // 0x80800E64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801640_chstatueboss(rdram, ctx);
        goto after_7;
    // 0x80800E64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80800E68: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800E6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800E70: bnel        $s0, $at, L_80800E5C
    if (ctx->r16 != ctx->r1) {
        // 0x80800E74: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800E5C;
    }
    goto skip_0;
    // 0x80800E74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80800E78: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x80800E7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800E80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800E84: jal         0x800861A0
    // 0x80800E88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800E88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80800E8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800E90: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800E94: jal         0x80801E24
    // 0x80800E98: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80801E24_chstatueboss(rdram, ctx);
        goto after_9;
    // 0x80800E98: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_9:
    // 0x80800E9C: addiu       $a0, $zero, 0x449
    ctx->r4 = ADD32(0, 0X449);
    // 0x80800EA0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800EA4: jal         0x80101180
    // 0x80800EA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_10;
    // 0x80800EA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80800EAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800EB0: jal         0x80108B04
    // 0x80800EB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80108B04(rdram, ctx);
        goto after_11;
    // 0x80800EB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80800EB8: b           L_80801090
    // 0x80800EBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801090;
    // 0x80800EBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800EC0:
    // 0x80800EC0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800EC4: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80800EC8: sh          $t8, 0x84($s0)
    MEM_H(0X84, ctx->r16) = ctx->r24;
    // 0x80800ECC: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800ED0: lw          $a3, 0x70($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X70);
    // 0x80800ED4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800ED8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800EDC: addiu       $a1, $zero, 0x7C8
    ctx->r5 = ADD32(0, 0X7C8);
    // 0x80800EE0: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    // 0x80800EE4: jal         0x80086680
    // 0x80800EE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _chexploder_entrypoint_5(rdram, ctx);
        goto after_12;
    // 0x80800EE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80800EEC: b           L_80801090
    // 0x80800EF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801090;
    // 0x80800EF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800EF4:
    // 0x80800EF4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80800EF8: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80800EFC: sh          $t9, 0x84($s0)
    MEM_H(0X84, ctx->r16) = ctx->r25;
    // 0x80800F00: lwc1        $f6, 0x38($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800F04: lw          $a3, 0x74($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X74);
    // 0x80800F08: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800F0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F10: addiu       $a1, $zero, 0x7C9
    ctx->r5 = ADD32(0, 0X7C9);
    // 0x80800F14: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    // 0x80800F18: jal         0x80086680
    // 0x80800F1C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _chexploder_entrypoint_5(rdram, ctx);
        goto after_13;
    // 0x80800F1C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x80800F20: b           L_80801090
    // 0x80800F24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801090;
    // 0x80800F24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F28:
    // 0x80800F28: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80800F2C: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80800F30: sh          $t0, 0x84($s0)
    MEM_H(0X84, ctx->r16) = ctx->r8;
    // 0x80800F34: lwc1        $f8, 0x38($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800F38: lw          $a3, 0x78($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X78);
    // 0x80800F3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800F40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F44: addiu       $a1, $zero, 0x7CA
    ctx->r5 = ADD32(0, 0X7CA);
    // 0x80800F48: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    // 0x80800F4C: jal         0x80086680
    // 0x80800F50: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_5(rdram, ctx);
        goto after_14;
    // 0x80800F50: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x80800F54: b           L_80801090
    // 0x80800F58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801090;
    // 0x80800F58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F5C:
    // 0x80800F5C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800F60: addiu       $t1, $zero, 0xB2
    ctx->r9 = ADD32(0, 0XB2);
    // 0x80800F64: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800F68: addiu       $a1, $zero, 0xF35
    ctx->r5 = ADD32(0, 0XF35);
    // 0x80800F6C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800F70: jal         0x8008A208
    // 0x80800F74: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80800F74: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    after_15:
    // 0x80800F78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F7C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800F80: jal         0x80801E24
    // 0x80800F84: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80801E24_chstatueboss(rdram, ctx);
        goto after_16;
    // 0x80800F84: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_16:
L_80800F88:
    // 0x80800F88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F8C: jal         0x80108B04
    // 0x80800F90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_17;
    // 0x80800F90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800F94: b           L_80801090
    // 0x80800F98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801090;
    // 0x80800F98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F9C:
    // 0x80800F9C: jal         0x800FDC28
    // 0x80800FA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FDC28(rdram, ctx);
        goto after_18;
    // 0x80800FA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_18:
    // 0x80800FA4: jal         0x800DA544
    // 0x80800FA8: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_800DA544(rdram, ctx);
        goto after_19;
    // 0x80800FA8: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_19:
    // 0x80800FAC: jal         0x80088178
    // 0x80800FB0: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_20;
    // 0x80800FB0: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_20:
    // 0x80800FB4: jal         0x80801E90
    // 0x80800FB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801E90_chstatueboss(rdram, ctx);
        goto after_21;
    // 0x80800FB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
L_80800FBC:
    // 0x80800FBC: jal         0x8010A590
    // 0x80800FC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010A590(rdram, ctx);
        goto after_22;
    // 0x80800FC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x80800FC4: jal         0x80800D30
    // 0x80800FC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800D30_chstatueboss(rdram, ctx);
        goto after_23;
    // 0x80800FC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x80800FCC: b           L_80801090
    // 0x80800FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801090;
    // 0x80800FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800FD4:
    // 0x80800FD4: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80800FD8: jal         0x8010A570
    // 0x80800FDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010A570(rdram, ctx);
        goto after_24;
    // 0x80800FDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_24:
    // 0x80800FE0: lwc1        $f10, 0x38($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800FE4: lw          $a3, 0x7C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X7C);
    // 0x80800FE8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800FEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FF0: addiu       $a1, $zero, 0x7CB
    ctx->r5 = ADD32(0, 0X7CB);
    // 0x80800FF4: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    // 0x80800FF8: jal         0x80086680
    // 0x80800FFC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _chexploder_entrypoint_5(rdram, ctx);
        goto after_25;
    // 0x80800FFC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_25:
    // 0x80801000: b           L_80801090
    // 0x80801004: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801090;
    // 0x80801004: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801008:
    // 0x80801008: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080100C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80801010: jal         0x80801E24
    // 0x80801014: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80801E24_chstatueboss(rdram, ctx);
        goto after_26;
    // 0x80801014: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_26:
    // 0x80801018: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8080101C: addiu       $t2, $zero, 0xB2
    ctx->r10 = ADD32(0, 0XB2);
    // 0x80801020: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801024: addiu       $a1, $zero, 0xF36
    ctx->r5 = ADD32(0, 0XF36);
    // 0x80801028: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8080102C: jal         0x8008A208
    // 0x80801030: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_27;
    // 0x80801030: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    after_27:
    // 0x80801034: b           L_80801090
    // 0x80801038: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801090;
    // 0x80801038: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080103C:
    // 0x8080103C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1312, 0X27C8) << 16);
    // 0x80801040: addiu       $a2, $a2, 0x27C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1312, 0X27C8));
    // 0x80801044: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801048: jal         0x80089D18
    // 0x8080104C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_28;
    // 0x8080104C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_28:
    // 0x80801050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801054: jal         0x800CE88C
    // 0x80801058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_29;
    // 0x80801058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x8080105C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801060: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80801064: jal         0x800CE8D8
    // 0x80801068: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800CE8D8(rdram, ctx);
        goto after_30;
    // 0x80801068: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_30:
    // 0x8080106C: b           L_80801090
    // 0x80801070: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801090;
    // 0x80801070: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801074:
    // 0x80801074: lbu         $t3, 0x65($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X65);
    // 0x80801078: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8080107C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801080: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x80801084: sb          $t4, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r12;
    // 0x80801088: swc1        $f16, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f16.u32l;
L_8080108C:
    // 0x8080108C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801090:
    // 0x80801090: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801094: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801098: jr          $ra
    // 0x8080109C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080109C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800090_chdiggerbossbattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800094: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800098: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080009C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808000A4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1496, 0X338) << 16);
    // 0x808000A8: addiu       $a3, $a3, 0x338
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1496, 0X338));
    // 0x808000AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000B0: jal         0x80089D50
    // 0x808000B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x808000B8: jal         0x800D9078
    // 0x808000BC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x808000BC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x808000C0: beq         $v0, $zero, L_8080015C
    if (ctx->r2 == 0) {
        // 0x808000C4: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_8080015C;
    }
    // 0x808000C4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808000C8: jal         0x800EE7F8
    // 0x808000CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808000CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808000D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000D8: jal         0x800DC298
    // 0x808000DC: nop

    func_800DC298(rdram, ctx);
        goto after_3;
    // 0x808000DC: nop

    after_3:
    // 0x808000E0: beq         $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x808000E4: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808000F8;
    }
    // 0x808000E4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808000E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808000F0: b           L_80800104
    // 0x808000F4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
        goto L_80800104;
    // 0x808000F4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_808000F8:
    // 0x808000F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808000FC: nop

    // 0x80800100: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_80800104:
    // 0x80800104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800108: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8080010C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x80800110: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800114: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800118: jal         0x800EF1B8
    // 0x8080011C: nop

    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x8080011C: nop

    after_4:
    // 0x80800120: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800124: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800128: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800134: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800138: jal         0x800862B8
    // 0x8080013C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    _chelectricfence_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x8080013C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80800140: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800144: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800148: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080014C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800150: jal         0x800DC178
    // 0x80800154: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800154: nop

    after_6:
    // 0x80800158: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_8080015C:
    // 0x8080015C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800164: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800168: jr          $ra
    // 0x8080016C: nop

    return;
    // 0x8080016C: nop

;}
RECOMP_FUNC void func_80103F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103F38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103F3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80103F40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80103F44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80103F48: jal         0x80103328
    // 0x80103F4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80103328(rdram, ctx);
        goto after_0;
    // 0x80103F4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80103F50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80103F54: beql        $a0, $zero, L_80103F84
    if (ctx->r4 == 0) {
        // 0x80103F58: lhu         $t6, 0x68($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X68);
            goto L_80103F84;
    }
    goto skip_0;
    // 0x80103F58: lhu         $t6, 0x68($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X68);
    skip_0:
    // 0x80103F5C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80103F60: jal         0x800EE88C
    // 0x80103F64: addiu       $a1, $a1, 0x1E
    ctx->r5 = ADD32(ctx->r5, 0X1E);
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x80103F64: addiu       $a1, $a1, 0x1E
    ctx->r5 = ADD32(ctx->r5, 0X1E);
    after_1:
    // 0x80103F68: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80103F6C: jal         0x800EF334
    // 0x80103F70: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_800EF334(rdram, ctx);
        goto after_2;
    // 0x80103F70: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80103F74: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80103F78: jal         0x800EF04C
    // 0x80103F7C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80103F7C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80103F80: lhu         $t6, 0x68($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X68);
L_80103F84:
    // 0x80103F84: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80103F88: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80103F8C: bgez        $t6, L_80103FA0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80103F90: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80103FA0;
    }
    // 0x80103F90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80103F94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80103F98: nop

    // 0x80103F9C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80103FA0:
    // 0x80103FA0: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80103FA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80103FA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103FAC: mul.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80103FB0: jr          $ra
    // 0x80103FB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80103FB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800B2C_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B3C: addiu       $a1, $zero, 0x12E
    ctx->r5 = ADD32(0, 0X12E);
    // 0x80800B40: jal         0x8008CB3C
    // 0x80800B44: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80800B44: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    after_0:
    // 0x80800B48: jal         0x80800000
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bssub(rdram, ctx);
        goto after_1;
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B54: jal         0x80084EE8
    // 0x80800B58: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _bamovethrust_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800B58: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800B5C: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800B60: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800B64: jal         0x80084EF0
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovethrust_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800B6C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800B70: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800B74: jal         0x800851D8
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basub_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B80: jal         0x800851E8
    // 0x80800B84: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _basub_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x80800B84: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x80800B88: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800B8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800B90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800B94: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B9C: addiu       $a1, $zero, 0x130
    ctx->r5 = ADD32(0, 0X130);
    // 0x80800BA0: jal         0x80085150
    // 0x80800BA4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _baspin_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800BA4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x80800BA8: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800BAC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB4: jal         0x80085338
    // 0x80800BB8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    _batimer_set(rdram, ctx);
        goto after_7;
    // 0x80800BB8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_7:
    // 0x80800BBC: jal         0x800FC660
    // 0x80800BC0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800FC660(rdram, ctx);
        goto after_8;
    // 0x80800BC0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_8:
    // 0x80800BC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800BC8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800BCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800BD0: jr          $ra
    // 0x80800BD4: nop

    return;
    // 0x80800BD4: nop

;}
RECOMP_FUNC void func_808040F4_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808040F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808040F8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808040FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804100: bne         $a1, $at, L_80804118
    if (ctx->r5 != ctx->r1) {
        // 0x80804104: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80804118;
    }
    // 0x80804104: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80804108: jal         0x80804230
    // 0x8080410C: nop

    func_80804230_chweldarboss(rdram, ctx);
        goto after_0;
    // 0x8080410C: nop

    after_0:
    // 0x80804110: b           L_8080411C
    // 0x80804114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080411C;
    // 0x80804114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804118:
    // 0x80804118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080411C:
    // 0x8080411C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804124: jr          $ra
    // 0x80804128: nop

    return;
    // 0x80804128: nop

;}
RECOMP_FUNC void func_80800EF4_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800F00: jal         0x80800110
    // 0x80800F04: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80800110_chchuffy(rdram, ctx);
        goto after_0;
    // 0x80800F04: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80800F08: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1700, 0X247C) << 16);
    // 0x80800F0C: addiu       $t0, $t0, 0x247C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1700, 0X247C));
    // 0x80800F10: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80800F14: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x80800F18: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x80800F1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800F20: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800F24: beq         $t8, $at, L_80800F44
    if (ctx->r24 == ctx->r1) {
        // 0x80800F28: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800F44;
    }
    // 0x80800F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F2C: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x80800F30: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80800F34: lh          $a2, 0x4($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X4);
    // 0x80800F38: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800F3C: jal         0x80085708
    // 0x80800F40: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800F40: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    after_1:
L_80800F44:
    // 0x80800F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F4C: jr          $ra
    // 0x80800F50: nop

    return;
    // 0x80800F50: nop

;}
RECOMP_FUNC void func_80800524_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800524: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800528: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080052C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800530: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800534: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800538: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080053C: jal         0x80100094
    // 0x80800540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800544: addiu       $t6, $zero, 0x9DD
    ctx->r14 = ADD32(0, 0X9DD);
    // 0x80800548: sw          $t6, 0x2A8($v0)
    MEM_W(0X2A8, ctx->r2) = ctx->r14;
    // 0x8080054C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800550: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80800554: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800558:
    // 0x80800558: jal         0x80800410
    // 0x8080055C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800410_chchuffy(rdram, ctx);
        goto after_1;
    // 0x8080055C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800560: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800564: bnel        $s0, $s1, L_80800558
    if (ctx->r16 != ctx->r17) {
        // 0x80800568: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800558;
    }
    goto skip_0;
    // 0x80800568: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x8080056C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80800570: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80800574: lbu         $t8, 0xA($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XA);
    // 0x80800578: andi        $t9, $t8, 0xFF07
    ctx->r25 = ctx->r24 & 0XFF07;
    // 0x8080057C: ori         $t0, $t9, 0x18
    ctx->r8 = ctx->r25 | 0X18;
    // 0x80800580: sb          $t0, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r8;
    // 0x80800584: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800588: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080058C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800590: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800594: jr          $ra
    // 0x80800598: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800598: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808006C0_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C8: jal         0x8008A098
    // 0x808006CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiemulti_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808006CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006D4: jal         0x80101FDC
    // 0x808006D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x808006D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808006DC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808006E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808006E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808006E8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808006EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808006F0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808006F4: jal         0x800CE8D8
    // 0x808006F8: nop

    func_800CE8D8(rdram, ctx);
        goto after_2;
    // 0x808006F8: nop

    after_2:
    // 0x808006FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800700: jal         0x800CE88C
    // 0x80800704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_3;
    // 0x80800704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800708: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X2180) << 16);
    // 0x8080070C: lwc1        $f6, 0x2180($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X2180));
    // 0x80800710: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800714: addiu       $a0, $zero, 0x6A7
    ctx->r4 = ADD32(0, 0X6A7);
    // 0x80800718: jal         0x800DA298
    // 0x8080071C: swc1        $f6, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f6.u32l;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x8080071C: swc1        $f6, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f6.u32l;
    after_4:
    // 0x80800720: beq         $v0, $zero, L_80800730
    if (ctx->r2 == 0) {
        // 0x80800724: nop
    
            goto L_80800730;
    }
    // 0x80800724: nop

    // 0x80800728: jal         0x8008A0A8
    // 0x8080072C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    _subaddiemulti_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x8080072C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_5:
L_80800730:
    // 0x80800730: jal         0x800FDC28
    // 0x80800734: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800FDC28(rdram, ctx);
        goto after_6;
    // 0x80800734: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_6:
    // 0x80800738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080073C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800740: jr          $ra
    // 0x80800744: nop

    return;
    // 0x80800744: nop

;}
RECOMP_FUNC void func_80800428_choctopus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800428: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080042C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800430: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800434: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800438: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x8080043C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800440: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800444: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800448: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x8080044C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80800450: jal         0x800CB854
    // 0x80800454: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    func_800CB854(rdram, ctx);
        goto after_0;
    // 0x80800454: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    after_0:
    // 0x80800458: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8080045C: xori        $v1, $v0, 0x5
    ctx->r3 = ctx->r2 ^ 0X5;
    // 0x80800460: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800464: bne         $t9, $zero, L_80800470
    if (ctx->r25 != 0) {
        // 0x80800468: sw          $v1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r3;
            goto L_80800470;
    }
    // 0x80800468: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8080046C: beq         $v1, $zero, L_8080052C
    if (ctx->r3 == 0) {
        // 0x80800470: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080052C;
    }
L_80800470:
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: jal         0x80100094
    // 0x80800478: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800478: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080047C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800480: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800484: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800488: srl         $t0, $v1, 10
    ctx->r8 = S32(U32(ctx->r3) >> 10);
    // 0x8080048C: beq         $t0, $at, L_808004A8
    if (ctx->r8 == ctx->r1) {
        // 0x80800490: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A8;
    }
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800494: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800498: beql        $t0, $at, L_80800520
    if (ctx->r8 == ctx->r1) {
        // 0x8080049C: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80800520;
    }
    goto skip_0;
    // 0x8080049C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    skip_0:
    // 0x808004A0: b           L_80800530
    // 0x808004A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800530;
    // 0x808004A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004A8:
    // 0x808004A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004AC: jal         0x80102424
    // 0x808004B0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808004B0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: jal         0x8008A4B0
    // 0x808004BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808004BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808004C0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808004C4: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x808004C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808004D0: beq         $a2, $zero, L_808004E0
    if (ctx->r6 == 0) {
        // 0x808004D4: swc1        $f4, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
            goto L_808004E0;
    }
    // 0x808004D4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x808004D8: jal         0x80089818
    // 0x808004DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_4;
    // 0x808004DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
L_808004E0:
    // 0x808004E0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808004E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1028, 0X8C0) << 16);
    // 0x808004E8: addiu       $a2, $a2, 0x8C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1028, 0X8C0));
    // 0x808004EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808004F0: jal         0x80089D18
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808004F8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x808004FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: bne         $t1, $zero, L_8080052C
    if (ctx->r9 != 0) {
        // 0x80800508: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1028, 0X98C) << 16);
            goto L_8080052C;
    }
    // 0x80800508: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1028, 0X98C) << 16);
    // 0x8080050C: jal         0x80089D18
    // 0x80800510: addiu       $a2, $a2, 0x98C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1028, 0X98C));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800510: addiu       $a2, $a2, 0x98C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1028, 0X98C));
    after_6:
    // 0x80800514: b           L_80800530
    // 0x80800518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800530;
    // 0x80800518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080051C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_80800520:
    // 0x80800520: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800524: nop

    // 0x80800528: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_8080052C:
    // 0x8080052C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800530:
    // 0x80800530: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800534: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void _bsbabykaz_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827E8: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x800827E8);
    return;
    // 0x800827EC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void bstaxi_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080151C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801520: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801524: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801528: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080152C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80801530: jal         0x8009D3A8
    // 0x80801534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x80801534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801538: lui         $a1, 0x3F01
    ctx->r5 = S32(0X3F01 << 16);
    // 0x8080153C: ori         $a1, $a1, 0x5B57
    ctx->r5 = ctx->r5 | 0X5B57;
    // 0x80801540: jal         0x8008CB10
    // 0x80801544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x80801544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801548: beq         $v0, $zero, L_80801564
    if (ctx->r2 == 0) {
        // 0x8080154C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801564;
    }
    // 0x8080154C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801550: jal         0x80084538
    // 0x80801554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_2;
    // 0x80801554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080155C: jal         0x800A0CD0
    // 0x80801560: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_3;
    // 0x80801560: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80801564:
    // 0x80801564: lui         $a1, 0x3EF5
    ctx->r5 = S32(0X3EF5 << 16);
    // 0x80801568: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x8080156C: jal         0x8008CB10
    // 0x80801570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80801570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801574: beq         $v0, $zero, L_808015A4
    if (ctx->r2 == 0) {
        // 0x80801578: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015A4;
    }
    // 0x80801578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080157C: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80801580: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80801584: addiu       $t6, $zero, 0x55F0
    ctx->r14 = ADD32(0, 0X55F0);
    // 0x80801588: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x8080158C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801590: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801594: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80801598: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080159C: jal         0x8009DEC0
    // 0x808015A0: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    func_8009DEC0(rdram, ctx);
        goto after_5;
    // 0x808015A0: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    after_5:
L_808015A4:
    // 0x808015A4: jal         0x8008CAC8
    // 0x808015A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_6;
    // 0x808015A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808015AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1F30) << 16);
    // 0x808015B0: lwc1        $f4, 0x1F30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(392, 0X1F30));
    // 0x808015B4: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x808015B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015BC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808015C0: nop

    // 0x808015C4: bc1f        L_808015D0
    if (!c1cs) {
        // 0x808015C8: nop
    
            goto L_808015D0;
    }
    // 0x808015C8: nop

    // 0x808015CC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_808015D0:
    // 0x808015D0: jal         0x8009E5C8
    // 0x808015D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x808015D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x808015D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808015DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808015E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808015E4: jr          $ra
    // 0x808015E8: nop

    return;
    // 0x808015E8: nop

;}
RECOMP_FUNC void func_80800000_chjrinnlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lw          $a1, 0x58($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X58);
    // 0x8080000C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800010: beq         $a1, $zero, L_80800028
    if (ctx->r5 == 0) {
        // 0x80800014: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800028;
    }
    // 0x80800014: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800018: jal         0x800C8B84
    // 0x8080001C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800020: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: sw          $zero, 0x58($a2)
    MEM_W(0X58, ctx->r6) = 0;
L_80800028:
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void func_800A3394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3394: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3398: jr          $ra
    // 0x800A339C: lwc1        $f0, 0x24($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X24);
    return;
    // 0x800A339C: lwc1        $f0, 0x24($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X24);
;}
RECOMP_FUNC void func_80800604_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800604: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800608: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080060C: jal         0x808001E0
    // 0x80800610: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800610: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800614: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80800618: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080061C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800620: jal         0x8008CB3C
    // 0x80800624: addiu       $a1, $zero, 0xBB
    ctx->r5 = ADD32(0, 0XBB);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800624: addiu       $a1, $zero, 0xBB
    ctx->r5 = ADD32(0, 0XBB);
    after_1:
    // 0x80800628: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8080062C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800630: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800634: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800638: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080063C: jal         0x8009FFD8
    // 0x80800640: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800640: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80800644: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800648: sw          $zero, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = 0;
    // 0x8080064C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800650: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800654: jr          $ra
    // 0x80800658: nop

    return;
    // 0x80800658: nop

;}
RECOMP_FUNC void func_80800464_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800464: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800468: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080046C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800470: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800474: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800478: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080047C: jal         0x80100094
    // 0x80800480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800484: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80800488: addiu       $v1, $v1, 0x7610
    ctx->r3 = ADD32(ctx->r3, 0X7610);
    // 0x8080048C: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x80800490: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80800494: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800498: bnel        $s0, $t6, L_808005C4
    if (ctx->r16 != ctx->r14) {
        // 0x8080049C: lbu         $t4, 0x0($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X0);
            goto L_808005C4;
    }
    goto skip_0;
    // 0x8080049C: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    skip_0:
    // 0x808004A0: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x808004A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1636, 0X12BC) << 16);
    // 0x808004A8: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1636, 0X11B4) << 16);
    // 0x808004AC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x808004B0: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x808004B4: lb          $v0, 0x12BC($v0)
    ctx->r2 = MEM_B(ctx->r2, (int16_t)RELOC_LO16(1636, 0X12BC));
    // 0x808004B8: addiu       $s2, $s2, 0x11B4
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1636, 0X11B4));
    // 0x808004BC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x808004C0: bltz        $v0, L_80800538
    if (SIGNED(ctx->r2) < 0) {
        // 0x808004C4: addiu       $a1, $v0, 0x1B86
        ctx->r5 = ADD32(ctx->r2, 0X1B86);
            goto L_80800538;
    }
    // 0x808004C4: addiu       $a1, $v0, 0x1B86
    ctx->r5 = ADD32(ctx->r2, 0X1B86);
    // 0x808004C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004CC: jal         0x80088718
    // 0x808004D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808004D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x808004D4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808004D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808004DC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
L_808004E0:
    // 0x808004E0: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x808004E4: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x808004E8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x808004EC: jal         0x80088720
    // 0x808004F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808004F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x808004F4: beq         $v0, $zero, L_8080050C
    if (ctx->r2 == 0) {
        // 0x808004F8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8080050C;
    }
    // 0x808004F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004FC: jal         0x800E715C
    // 0x80800500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E715C(rdram, ctx);
        goto after_3;
    // 0x80800500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800504: b           L_80800520
    // 0x80800508: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80800520;
    // 0x80800508: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8080050C:
    // 0x8080050C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1636, 0X11B0) << 16);
    // 0x80800510: addiu       $a1, $a1, 0x11B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1636, 0X11B0));
    // 0x80800514: jal         0x800E715C
    // 0x80800518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E715C(rdram, ctx);
        goto after_4;
    // 0x80800518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8080051C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80800520:
    // 0x80800520: bne         $s2, $s0, L_808004E0
    if (ctx->r18 != ctx->r16) {
        // 0x80800524: addiu       $s1, $s1, 0x80
        ctx->r17 = ADD32(ctx->r17, 0X80);
            goto L_808004E0;
    }
    // 0x80800524: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x80800528: jal         0x80088728
    // 0x8080052C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x8080052C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800530: b           L_80800558
    // 0x80800534: nop

        goto L_80800558;
    // 0x80800534: nop

L_80800538:
    // 0x80800538: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8080053C:
    // 0x8080053C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800540: jal         0x800E715C
    // 0x80800544: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800E715C(rdram, ctx);
        goto after_6;
    // 0x80800544: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x80800548: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x8080054C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80800550: bne         $s0, $at, L_8080053C
    if (ctx->r16 != ctx->r1) {
        // 0x80800554: addiu       $s1, $s1, 0x80
        ctx->r17 = ADD32(ctx->r17, 0X80);
            goto L_8080053C;
    }
    // 0x80800554: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
L_80800558:
    // 0x80800558: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8080055C: lbu         $t0, 0x7610($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X7610);
    // 0x80800560: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1636, 0X12BD) << 16);
    // 0x80800564: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800568: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8080056C: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80800570: lb          $a1, 0x12BD($a1)
    ctx->r5 = MEM_B(ctx->r5, (int16_t)RELOC_LO16(1636, 0X12BD));
    // 0x80800574: addiu       $a1, $a1, 0x1B88
    ctx->r5 = ADD32(ctx->r5, 0X1B88);
    // 0x80800578: jal         0x80088718
    // 0x8080057C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x8080057C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_7:
    // 0x80800580: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80800584: lbu         $t2, 0x7610($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7610);
    // 0x80800588: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1636, 0X12BE) << 16);
    // 0x8080058C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800590: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80800594: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x80800598: jal         0x80088720
    // 0x8080059C: lb          $a1, 0x12BE($a1)
    ctx->r5 = MEM_B(ctx->r5, (int16_t)RELOC_LO16(1636, 0X12BE));
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x8080059C: lb          $a1, 0x12BE($a1)
    ctx->r5 = MEM_B(ctx->r5, (int16_t)RELOC_LO16(1636, 0X12BE));
    after_8:
    // 0x808005A0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808005A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808005A8: jal         0x800E715C
    // 0x808005AC: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    func_800E715C(rdram, ctx);
        goto after_9;
    // 0x808005AC: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_9:
    // 0x808005B0: jal         0x80088728
    // 0x808005B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x808005B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x808005B8: b           L_808006F8
    // 0x808005BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006F8;
    // 0x808005BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005C0: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
L_808005C4:
    // 0x808005C4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1636, 0X1204) << 16);
    // 0x808005C8: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1636, 0X11BC) << 16);
    // 0x808005CC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x808005D0: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x808005D4: lb          $v0, 0x1204($v0)
    ctx->r2 = MEM_B(ctx->r2, (int16_t)RELOC_LO16(1636, 0X1204));
    // 0x808005D8: addiu       $s2, $s2, 0x11BC
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1636, 0X11BC));
    // 0x808005DC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x808005E0: bltz        $v0, L_80800658
    if (SIGNED(ctx->r2) < 0) {
        // 0x808005E4: addiu       $a1, $v0, 0x1B68
        ctx->r5 = ADD32(ctx->r2, 0X1B68);
            goto L_80800658;
    }
    // 0x808005E4: addiu       $a1, $v0, 0x1B68
    ctx->r5 = ADD32(ctx->r2, 0X1B68);
    // 0x808005E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005EC: jal         0x80088718
    // 0x808005F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x808005F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_11:
    // 0x808005F4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808005F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808005FC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
L_80800600:
    // 0x80800600: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x80800604: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80800608: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8080060C: jal         0x80088720
    // 0x80800610: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80800610: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x80800614: beq         $v0, $zero, L_8080062C
    if (ctx->r2 == 0) {
        // 0x80800618: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8080062C;
    }
    // 0x80800618: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080061C: jal         0x800E715C
    // 0x80800620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E715C(rdram, ctx);
        goto after_13;
    // 0x80800620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800624: b           L_80800640
    // 0x80800628: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80800640;
    // 0x80800628: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8080062C:
    // 0x8080062C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1636, 0X11B8) << 16);
    // 0x80800630: addiu       $a1, $a1, 0x11B8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1636, 0X11B8));
    // 0x80800634: jal         0x800E715C
    // 0x80800638: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E715C(rdram, ctx);
        goto after_14;
    // 0x80800638: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8080063C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80800640:
    // 0x80800640: bne         $s2, $s0, L_80800600
    if (ctx->r18 != ctx->r16) {
        // 0x80800644: addiu       $s1, $s1, 0x80
        ctx->r17 = ADD32(ctx->r17, 0X80);
            goto L_80800600;
    }
    // 0x80800644: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x80800648: jal         0x80088728
    // 0x8080064C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x8080064C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x80800650: b           L_80800678
    // 0x80800654: nop

        goto L_80800678;
    // 0x80800654: nop

L_80800658:
    // 0x80800658: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8080065C:
    // 0x8080065C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800660: jal         0x800E715C
    // 0x80800664: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800E715C(rdram, ctx);
        goto after_16;
    // 0x80800664: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x80800668: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x8080066C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80800670: bne         $s0, $at, L_8080065C
    if (ctx->r16 != ctx->r1) {
        // 0x80800674: addiu       $s1, $s1, 0x80
        ctx->r17 = ADD32(ctx->r17, 0X80);
            goto L_8080065C;
    }
    // 0x80800674: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
L_80800678:
    // 0x80800678: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8080067C: lbu         $a1, 0x7610($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7610);
    // 0x80800680: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800684: addiu       $a1, $a1, 0x1B6F
    ctx->r5 = ADD32(ctx->r5, 0X1B6F);
    // 0x80800688: jal         0x80088718
    // 0x8080068C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x8080068C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_17:
    // 0x80800690: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80800694: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800698: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8080069C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x808006A0: addiu       $s0, $s0, 0x100
    ctx->r16 = ADD32(ctx->r16, 0X100);
L_808006A4:
    // 0x808006A4: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x808006A8: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x808006AC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x808006B0: jal         0x80088720
    // 0x808006B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_18;
    // 0x808006B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_18:
    // 0x808006B8: beq         $v0, $zero, L_808006D0
    if (ctx->r2 == 0) {
        // 0x808006BC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808006D0;
    }
    // 0x808006BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808006C0: jal         0x800E715C
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E715C(rdram, ctx);
        goto after_19;
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808006C8: b           L_808006E4
    // 0x808006CC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_808006E4;
    // 0x808006CC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_808006D0:
    // 0x808006D0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1636, 0X11C0) << 16);
    // 0x808006D4: addiu       $a1, $a1, 0x11C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1636, 0X11C0));
    // 0x808006D8: jal         0x800E715C
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E715C(rdram, ctx);
        goto after_20;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808006E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_808006E4:
    // 0x808006E4: bne         $s2, $s1, L_808006A4
    if (ctx->r18 != ctx->r17) {
        // 0x808006E8: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_808006A4;
    }
    // 0x808006E8: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x808006EC: jal         0x80088728
    // 0x808006F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x808006F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_21:
    // 0x808006F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006F8:
    // 0x808006F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808006FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800700: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800704: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800708: jr          $ra
    // 0x8080070C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080070C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800CEB08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEB08: lb          $t6, 0x12($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X12);
    // 0x800CEB0C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CEB10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CEB14: beq         $t6, $zero, L_800CEB4C
    if (ctx->r14 == 0) {
        // 0x800CEB18: nop
    
            goto L_800CEB4C;
    }
    // 0x800CEB18: nop

    // 0x800CEB1C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800CEB20: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x800CEB24: nop

    // 0x800CEB28: bc1f        L_800CEB4C
    if (!c1cs) {
        // 0x800CEB2C: nop
    
            goto L_800CEB4C;
    }
    // 0x800CEB2C: nop

    // 0x800CEB30: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800CEB34: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x800CEB38: nop

    // 0x800CEB3C: bc1f        L_800CEB4C
    if (!c1cs) {
        // 0x800CEB40: nop
    
            goto L_800CEB4C;
    }
    // 0x800CEB40: nop

    // 0x800CEB44: jr          $ra
    // 0x800CEB48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800CEB48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CEB4C:
    // 0x800CEB4C: jr          $ra
    // 0x800CEB50: nop

    return;
    // 0x800CEB50: nop

;}
RECOMP_FUNC void func_808001B0_chdrawbridgeswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808001B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001C4: bne         $a1, $at, L_808001E4
    if (ctx->r5 != ctx->r1) {
        // 0x808001C8: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_808001E4;
    }
    // 0x808001C8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808001CC: addiu       $a0, $zero, 0x395
    ctx->r4 = ADD32(0, 0X395);
    // 0x808001D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808001D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001D8: jal         0x80101180
    // 0x808001DC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x808001DC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808001E0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_808001E4:
    // 0x808001E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808001EC: jal         0x80085820
    // 0x808001F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808001F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808001F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001FC: jr          $ra
    // 0x80800200: nop

    return;
    // 0x80800200: nop

;}
RECOMP_FUNC void func_80800160_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800168: jal         0x80090128
    // 0x8080016C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090128(rdram, ctx);
        goto after_0;
    // 0x8080016C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800170: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x80800174: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8080024C;
    }
    // 0x80800174: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800178: addiu       $a0, $a1, 0x18
    ctx->r4 = ADD32(ctx->r5, 0X18);
    // 0x8080017C: jal         0x8008FE68
    // 0x80800180: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8008FE68(rdram, ctx);
        goto after_1;
    // 0x80800180: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800184: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800188: lhu         $t6, 0x72($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X72);
    // 0x8080018C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800190: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800194: sltiu       $at, $t8, 0xC
    ctx->r1 = ctx->r24 < 0XC ? 1 : 0;
    // 0x80800198: beq         $at, $zero, L_8080024C
    if (ctx->r1 == 0) {
        // 0x8080019C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8080024C;
    }
    // 0x8080019C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808001A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1236, 0X1220) << 16);
    // 0x808001A4: addu        $at, $at, $t8
    gpr jr_addend_808001AC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808001A8: lw          $t8, 0x1220($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1236, 0X1220));
    // 0x808001AC: jr          $t8
    // 0x808001B0: nop

    switch (jr_addend_808001AC >> 2) {
        case 0: goto L_8080024C; break;
        case 1: goto L_808001B4; break;
        case 2: goto L_808001C4; break;
        case 3: goto L_808001D4; break;
        case 4: goto L_808001D4; break;
        case 5: goto L_808001E4; break;
        case 6: goto L_808001F4; break;
        case 7: goto L_80800204; break;
        case 8: goto L_80800214; break;
        case 9: goto L_80800224; break;
        case 10: goto L_80800234; break;
        case 11: goto L_80800244; break;
        default: switch_error(__func__, 0x808001AC, 0x80801220);
    }
    // 0x808001B0: nop

L_808001B4:
    // 0x808001B4: jal         0x8080025C
    // 0x808001B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8080025C_chbanjoctrl(rdram, ctx);
        goto after_2;
    // 0x808001B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x808001BC: b           L_80800250
    // 0x808001C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800250;
    // 0x808001C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001C4:
    // 0x808001C4: jal         0x808003F8
    // 0x808001C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_808003F8_chbanjoctrl(rdram, ctx);
        goto after_3;
    // 0x808001C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x808001CC: b           L_80800250
    // 0x808001D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800250;
    // 0x808001D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001D4:
    // 0x808001D4: jal         0x80800728
    // 0x808001D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800728_chbanjoctrl(rdram, ctx);
        goto after_4;
    // 0x808001D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x808001DC: b           L_80800250
    // 0x808001E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800250;
    // 0x808001E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001E4:
    // 0x808001E4: jal         0x80800ADC
    // 0x808001E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800ADC_chbanjoctrl(rdram, ctx);
        goto after_5;
    // 0x808001E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
    // 0x808001EC: b           L_80800250
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800250;
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001F4:
    // 0x808001F4: jal         0x80800B18
    // 0x808001F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800B18_chbanjoctrl(rdram, ctx);
        goto after_6;
    // 0x808001F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_6:
    // 0x808001FC: b           L_80800250
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800250;
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800204:
    // 0x80800204: jal         0x80800D04
    // 0x80800208: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800D04_chbanjoctrl(rdram, ctx);
        goto after_7;
    // 0x80800208: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_7:
    // 0x8080020C: b           L_80800250
    // 0x80800210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800250;
    // 0x80800210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800214:
    // 0x80800214: jal         0x80800D50
    // 0x80800218: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800D50_chbanjoctrl(rdram, ctx);
        goto after_8;
    // 0x80800218: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_8:
    // 0x8080021C: b           L_80800250
    // 0x80800220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800250;
    // 0x80800220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800224:
    // 0x80800224: jal         0x80800DF8
    // 0x80800228: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800DF8_chbanjoctrl(rdram, ctx);
        goto after_9;
    // 0x80800228: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_9:
    // 0x8080022C: b           L_80800250
    // 0x80800230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800250;
    // 0x80800230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800234:
    // 0x80800234: jal         0x808010FC
    // 0x80800238: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_808010FC_chbanjoctrl(rdram, ctx);
        goto after_10;
    // 0x80800238: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_10:
    // 0x8080023C: b           L_80800250
    // 0x80800240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800250;
    // 0x80800240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800244:
    // 0x80800244: jal         0x80801088
    // 0x80800248: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80801088_chbanjoctrl(rdram, ctx);
        goto after_11;
    // 0x80800248: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_11:
L_8080024C:
    // 0x8080024C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800250:
    // 0x80800250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800254: jr          $ra
    // 0x80800258: nop

    return;
    // 0x80800258: nop

;}
RECOMP_FUNC void func_800A526C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A526C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5274: jal         0x800F54E4
    // 0x800A5278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800A5278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A527C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A5280: jal         0x800878E0
    // 0x800A5284: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _plcamera_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x800A5284: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A5288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A528C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5290: jr          $ra
    // 0x800A5294: nop

    return;
    // 0x800A5294: nop

;}
RECOMP_FUNC void func_80800000_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800010: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800014: jal         0x80100094
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080001C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800020: lbu         $v1, 0x24($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X24);
    // 0x80800024: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800028: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8080002C: beq         $v1, $zero, L_80800050
    if (ctx->r3 == 0) {
        // 0x80800030: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800050;
    }
    // 0x80800030: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800034: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800038: beq         $v1, $at, L_80800058
    if (ctx->r3 == ctx->r1) {
        // 0x8080003C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800058;
    }
    // 0x8080003C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800040: beql        $v1, $at, L_80800084
    if (ctx->r3 == ctx->r1) {
        // 0x80800044: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800084;
    }
    goto skip_0;
    // 0x80800044: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800048: b           L_80800090
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800090;
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800050:
    // 0x80800050: jal         0x800856B0
    // 0x80800054: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800054: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
L_80800058:
    // 0x80800058: jal         0x800856E0
    // 0x8080005C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x8080005C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800060: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800064: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800068: sb          $t7, 0x24($t8)
    MEM_B(0X24, ctx->r24) = ctx->r15;
    // 0x8080006C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800070: jal         0x800880A8
    // 0x80800074: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800074: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x80800078: jal         0x800880B8
    // 0x8080007C: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x8080007C: nop

    after_4:
    // 0x80800080: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80800084:
    // 0x80800084: jal         0x800856D8
    // 0x80800088: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80800088: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800090:
    // 0x80800090: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_80801258_chglowbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801258: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080125C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80801260: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801264: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801268: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8080126C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80801270: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80801274: lwc1        $f20, 0x2C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80801278: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080127C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801280: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801284: jal         0x800EE7F8
    // 0x80801288: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80801288: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x8080128C: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80801290: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801294: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801298: nop

    // 0x8080129C: bc1tl       L_808012C0
    if (c1cs) {
        // 0x808012A0: mtc1        $zero, $f22
        ctx->f22.u32l = 0;
            goto L_808012C0;
    }
    goto skip_0;
    // 0x808012A0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    skip_0:
    // 0x808012A4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808012A8: nop

    // 0x808012AC: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x808012B0: nop

    // 0x808012B4: bc1fl       L_8080130C
    if (!c1cs) {
        // 0x808012B8: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_8080130C;
    }
    goto skip_1;
    // 0x808012B8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x808012BC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
L_808012C0:
    // 0x808012C0: jal         0x800D8FF8
    // 0x808012C4: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808012C4: nop

    after_1:
    // 0x808012C8: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808012CC: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808012D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808012D4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808012D8: add.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x808012DC: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x808012E0: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x808012E4: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808012E8: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x808012EC: nop

    // 0x808012F0: bc1tl       L_808012C0
    if (c1cs) {
        // 0x808012F4: mtc1        $zero, $f22
        ctx->f22.u32l = 0;
            goto L_808012C0;
    }
    goto skip_2;
    // 0x808012F4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    skip_2:
    // 0x808012F8: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x808012FC: nop

    // 0x80801300: bc1tl       L_808012C0
    if (c1cs) {
        // 0x80801304: mtc1        $zero, $f22
        ctx->f22.u32l = 0;
            goto L_808012C0;
    }
    goto skip_3;
    // 0x80801304: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    skip_3:
    // 0x80801308: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_8080130C:
    // 0x8080130C: jal         0x800EFB8C
    // 0x80801310: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EFB8C(rdram, ctx);
        goto after_2;
    // 0x80801310: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x80801314: blez        $s1, L_80801334
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80801318: swc1        $f0, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
            goto L_80801334;
    }
    // 0x80801318: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8080131C: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80801320: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801324: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801328: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8080132C: b           L_80801338
    // 0x80801330: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
        goto L_80801338;
    // 0x80801330: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
L_80801334:
    // 0x80801334: swc1        $f22, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f22.u32l;
L_80801338:
    // 0x80801338: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080133C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80801340: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80801344: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80801348: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8080134C: jr          $ra
    // 0x80801350: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801350: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800E9C_chfirefx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800EA8: jal         0x80100094
    // 0x80800EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800EB0: jal         0x8008A040
    // 0x80800EB4: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800EB4: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    after_1:
    // 0x80800EB8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800EBC: beq         $v0, $zero, L_80800ED8
    if (ctx->r2 == 0) {
        // 0x80800EC0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800ED8;
    }
    // 0x80800EC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800EC4: lhu         $t6, 0x72($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X72);
    // 0x80800EC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800ECC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800ED0: beq         $t7, $at, L_80800EE8
    if (ctx->r15 == ctx->r1) {
        // 0x80800ED4: nop
    
            goto L_80800EE8;
    }
    // 0x80800ED4: nop

L_80800ED8:
    // 0x80800ED8: jal         0x80800AA8
    // 0x80800EDC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800AA8_chfirefx(rdram, ctx);
        goto after_2;
    // 0x80800EDC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80800EE0: b           L_80800EF4
    // 0x80800EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800EF4;
    // 0x80800EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800EE8:
    // 0x80800EE8: jal         0x8080116C
    // 0x80800EEC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8080116C_chfirefx(rdram, ctx);
        goto after_3;
    // 0x80800EEC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x80800EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800EF4:
    // 0x80800EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EF8: jr          $ra
    // 0x80800EFC: nop

    return;
    // 0x80800EFC: nop

;}
RECOMP_FUNC void _bareact_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F98: syscall     145
    recomp_syscall_handler(rdram, ctx, 0x80084F98);
    return;
    // 0x80084F9C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
