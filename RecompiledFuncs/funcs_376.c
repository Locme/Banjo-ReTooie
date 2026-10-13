#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801B10_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B18: jal         0x808000F0
    // 0x80801B1C: nop

    func_808000F0_bswasher(rdram, ctx);
        goto after_0;
    // 0x80801B1C: nop

    after_0:
    // 0x80801B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B28: jr          $ra
    // 0x80801B2C: nop

    return;
    // 0x80801B2C: nop

;}
RECOMP_FUNC void _fxrain_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088928: syscall     710
    recomp_syscall_handler(rdram, ctx, 0x80088928);
    return;
    // 0x8008892C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80803448_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803448: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080344C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803450: jal         0x800D8FF8
    // 0x80803454: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80803454: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803458: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8080345C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80803460: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80803464: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80803468: jal         0x800EE7F8
    // 0x8080346C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080346C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80803470: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80803474: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803478: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080347C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80803480: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80803484: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80803488: jal         0x800EE7F8
    // 0x8080348C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080348C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80803490: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80803494: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80803498: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080349C: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x808034A0: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x808034A4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808034A8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808034AC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808034B0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x808034B4: jal         0x800BEF00
    // 0x808034B8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_800BEF00(rdram, ctx);
        goto after_3;
    // 0x808034B8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x808034BC: beq         $v0, $zero, L_808034DC
    if (ctx->r2 == 0) {
        // 0x808034C0: lw          $v1, 0x48($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X48);
            goto L_808034DC;
    }
    // 0x808034C0: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x808034C4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808034C8: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808034CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808034D0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808034D4: nop

    // 0x808034D8: bc1f        L_80803504
    if (!c1cs) {
        // 0x808034DC: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_80803504;
    }
L_808034DC:
    // 0x808034DC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808034E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808034E4: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808034E8: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x808034EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808034F0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808034F4: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808034F8: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x808034FC: b           L_80803504
    // 0x80803500: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
        goto L_80803504;
    // 0x80803500: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
L_80803504:
    // 0x80803504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803508: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080350C: jr          $ra
    // 0x80803510: nop

    return;
    // 0x80803510: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083700: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083700);
    return;
    // 0x80083704: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_8008B768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B768: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008B76C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008B770: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008B774: addiu       $s2, $s2, 0x6CC0
    ctx->r18 = ADD32(ctx->r18, 0X6CC0);
    // 0x8008B778: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8008B77C: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x8008B780: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B784: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008B788: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8008B78C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008B790: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008B794: beq         $at, $zero, L_8008B808
    if (ctx->r1 == 0) {
        // 0x8008B798: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8008B808;
    }
    // 0x8008B798: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008B79C: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // 0x8008B7A0: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
L_8008B7A4:
    // 0x8008B7A4: beql        $t6, $zero, L_8008B7FC
    if (ctx->r14 == 0) {
        // 0x8008B7A8: addiu       $s0, $s0, 0x6
        ctx->r16 = ADD32(ctx->r16, 0X6);
            goto L_8008B7FC;
    }
    goto skip_0;
    // 0x8008B7A8: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    skip_0:
    // 0x8008B7AC: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8008B7B0: jal         0x800DFCC0
    // 0x8008B7B4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_800DFCC0(rdram, ctx);
        goto after_0;
    // 0x8008B7B4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_0:
    // 0x8008B7B8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8008B7BC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8008B7C0: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x8008B7C4: subu        $t7, $s0, $a0
    ctx->r15 = SUB32(ctx->r16, ctx->r4);
    // 0x8008B7C8: div         $zero, $t7, $s1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r17)));
    // 0x8008B7CC: mflo        $v1
    ctx->r3 = lo;
    // 0x8008B7D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008B7D4: bne         $s1, $zero, L_8008B7E0
    if (ctx->r17 != 0) {
        // 0x8008B7D8: nop
    
            goto L_8008B7E0;
    }
    // 0x8008B7D8: nop

    // 0x8008B7DC: break       7
    do_break(2148055004);
L_8008B7E0:
    // 0x8008B7E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008B7E4: bne         $s1, $at, L_8008B7F8
    if (ctx->r17 != ctx->r1) {
        // 0x8008B7E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008B7F8;
    }
    // 0x8008B7E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008B7EC: bne         $t7, $at, L_8008B7F8
    if (ctx->r15 != ctx->r1) {
        // 0x8008B7F0: nop
    
            goto L_8008B7F8;
    }
    // 0x8008B7F0: nop

    // 0x8008B7F4: break       6
    do_break(2148055028);
L_8008B7F8:
    // 0x8008B7F8: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
L_8008B7FC:
    // 0x8008B7FC: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8008B800: bnel        $at, $zero, L_8008B7A4
    if (ctx->r1 != 0) {
        // 0x8008B804: lh          $t6, 0x4($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X4);
            goto L_8008B7A4;
    }
    goto skip_1;
    // 0x8008B804: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    skip_1:
L_8008B808:
    // 0x8008B808: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x8008B80C: beql        $at, $zero, L_8008B81C
    if (ctx->r1 == 0) {
        // 0x8008B810: sll         $s0, $v1, 2
        ctx->r16 = S32(ctx->r3 << 2);
            goto L_8008B81C;
    }
    goto skip_2;
    // 0x8008B810: sll         $s0, $v1, 2
    ctx->r16 = S32(ctx->r3 << 2);
    skip_2:
    // 0x8008B814: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x8008B818: sll         $s0, $v1, 2
    ctx->r16 = S32(ctx->r3 << 2);
L_8008B81C:
    // 0x8008B81C: subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // 0x8008B820: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x8008B824: jal         0x8001B208
    // 0x8008B828: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    heap_realloc(rdram, ctx);
        goto after_1;
    // 0x8008B828: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8008B82C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008B830: addu        $t9, $s0, $v0
    ctx->r25 = ADD32(ctx->r16, ctx->r2);
    // 0x8008B834: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8008B838: sw          $t9, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r25;
    // 0x8008B83C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008B840: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B844: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B848: jr          $ra
    // 0x8008B84C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8008B84C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800D39D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D39D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D39D4: jr          $ra
    // 0x800D39D8: sb          $a0, -0x4C0E($at)
    MEM_B(-0X4C0E, ctx->r1) = ctx->r4;
    return;
    // 0x800D39D8: sb          $a0, -0x4C0E($at)
    MEM_B(-0X4C0E, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void inflate_fixed_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CA2C: sw          $ra, 0xA44($sp)
    MEM_W(0XA44, ctx->r29) = ctx->r31;
    // 0x8001CA30: sw          $s6, 0xA74($sp)
    MEM_W(0XA74, ctx->r29) = ctx->r22;
    // 0x8001CA34: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x8001CA38: addiu       $s6, $s6, -0x38F0
    ctx->r22 = ADD32(ctx->r22, -0X38F0);
    // 0x8001CA3C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001CA40: addiu       $a0, $a0, -0x38EC
    ctx->r4 = ADD32(ctx->r4, -0X38EC);
    // 0x8001CA44: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001CA48: addiu       $a1, $a1, -0x2F28
    ctx->r5 = ADD32(ctx->r5, -0X2F28);
    // 0x8001CA4C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8001CA50: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8001CA54: jal         0x8001CF00
    // 0x8001CA58: nop

    inflate_codes_recomp(rdram, ctx);
        goto after_0;
    // 0x8001CA58: nop

    after_0:
    // 0x8001CA5C: lw          $s6, 0xA74($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XA74);
    // 0x8001CA60: lw          $ra, 0xA44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA44);
    // 0x8001CA64: jr          $ra
    // 0x8001CA68: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x8001CA68: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080000C_chtntblockage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080001C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800020: bnel        $t7, $at, L_8080007C
    if (ctx->r15 != ctx->r1) {
        // 0x80800024: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080007C;
    }
    goto skip_0;
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800028: jal         0x800D8FF8
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800030: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800038: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080003C: lwc1        $f4, 0x58($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X58);
    // 0x80800040: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(900, 0X288) << 16);
    // 0x80800044: addiu       $a1, $a1, 0x288
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(900, 0X288));
    // 0x80800048: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8080004C: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    // 0x80800050: swc1        $f6, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f6.u32l;
    // 0x80800054: lwc1        $f10, 0x58($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X58);
    // 0x80800058: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8080005C: nop

    // 0x80800060: bc1fl       L_8080007C
    if (!c1cs) {
        // 0x80800064: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080007C;
    }
    goto skip_1;
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800068: jal         0x800C4AF0
    // 0x8080006C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C4AF0(rdram, ctx);
        goto after_1;
    // 0x8080006C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800070: jal         0x800FFAB0
    // 0x80800074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080007C:
    // 0x8080007C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void func_80802BE0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802BE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80802BEC: jal         0x80100094
    // 0x80802BF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802BF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802BF4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80802BF8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x80802BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802C00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802C04: jr          $ra
    // 0x80802C08: nop

    return;
    // 0x80802C08: nop

;}
RECOMP_FUNC void func_800E9320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9328: jal         0x800E90D8
    // 0x800E932C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800E90D8(rdram, ctx);
        goto after_0;
    // 0x800E932C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800E9330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9338: jr          $ra
    // 0x800E933C: nop

    return;
    // 0x800E933C: nop

;}
RECOMP_FUNC void _Ldtob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800361E0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800361E4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800361E8: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800361EC: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800361F0: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800361F4: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800361F8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800361FC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80036200: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80036204: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80036208: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x8003620C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80036210: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80036214: addiu       $s2, $sp, 0xA0
    ctx->r18 = ADD32(ctx->r29, 0XA0);
    // 0x80036218: bgez        $v0, L_8003622C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003621C: ldc1        $f20, 0x0($a0)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
            goto L_8003622C;
    }
    // 0x8003621C: ldc1        $f20, 0x0($a0)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
    // 0x80036220: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80036224: b           L_80036250
    // 0x80036228: sw          $t6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r14;
        goto L_80036250;
    // 0x80036228: sw          $t6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r14;
L_8003622C:
    // 0x8003622C: bne         $v0, $zero, L_80036250
    if (ctx->r2 != 0) {
        // 0x80036230: lbu         $t7, 0xC7($sp)
        ctx->r15 = MEM_BU(ctx->r29, 0XC7);
            goto L_80036250;
    }
    // 0x80036230: lbu         $t7, 0xC7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XC7);
    // 0x80036234: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80036238: beq         $t7, $at, L_80036248
    if (ctx->r15 == ctx->r1) {
        // 0x8003623C: sw          $t7, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r15;
            goto L_80036248;
    }
    // 0x8003623C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80036240: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80036244: bne         $t7, $at, L_80036250
    if (ctx->r15 != ctx->r1) {
        // 0x80036248: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80036250;
    }
L_80036248:
    // 0x80036248: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003624C: sw          $t8, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r24;
L_80036250:
    // 0x80036250: addiu       $a0, $sp, 0x8A
    ctx->r4 = ADD32(ctx->r29, 0X8A);
    // 0x80036254: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80036258: jal         0x80036670
    // 0x8003625C: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    static_13_80036670(rdram, ctx);
        goto after_0;
    // 0x8003625C: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    after_0:
    // 0x80036260: blez        $v0, L_800362A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80036264: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800362A0;
    }
    // 0x80036264: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80036268: bne         $v0, $at, L_8003627C
    if (ctx->r2 != ctx->r1) {
        // 0x8003626C: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_8003627C;
    }
    // 0x8003626C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80036270: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80036274: b           L_80036280
    // 0x80036278: addiu       $a1, $a1, 0x1FF8
    ctx->r5 = ADD32(ctx->r5, 0X1FF8);
        goto L_80036280;
    // 0x80036278: addiu       $a1, $a1, 0x1FF8
    ctx->r5 = ADD32(ctx->r5, 0X1FF8);
L_8003627C:
    // 0x8003627C: addiu       $a1, $a1, 0x1FFC
    ctx->r5 = ADD32(ctx->r5, 0X1FFC);
L_80036280:
    // 0x80036280: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
    // 0x80036284: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80036288: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8003628C: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x80036290: jal         0x80032AD8
    // 0x80036294: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x80036294: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_1:
    // 0x80036298: b           L_80036648
    // 0x8003629C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80036648;
    // 0x8003629C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800362A0:
    // 0x800362A0: bne         $v0, $zero, L_800362B0
    if (ctx->r2 != 0) {
        // 0x800362A4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800362B0;
    }
    // 0x800362A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800362A8: b           L_8003662C
    // 0x800362AC: sh          $zero, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = 0;
        goto L_8003662C;
    // 0x800362AC: sh          $zero, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = 0;
L_800362B0:
    // 0x800362B0: mtc1        $zero, $f23
    ctx->f_odd[(23 - 1) * 2] = 0;
    // 0x800362B4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800362B8: lbu         $t0, 0xC7($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XC7);
    // 0x800362BC: lh          $t1, 0x8A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X8A);
    // 0x800362C0: c.lt.d      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.d < ctx->f22.d;
    // 0x800362C4: addiu       $at, $zero, 0x7597
    ctx->r1 = ADD32(0, 0X7597);
    // 0x800362C8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800362CC: addiu       $s2, $sp, 0xA1
    ctx->r18 = ADD32(ctx->r29, 0XA1);
    // 0x800362D0: bc1f        L_800362DC
    if (!c1cs) {
        // 0x800362D4: sw          $t0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r8;
            goto L_800362DC;
    }
    // 0x800362D4: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800362D8: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_800362DC:
    // 0x800362DC: multu       $t1, $at
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800362E0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800362E4: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x800362E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800362EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800362F0: mflo        $t2
    ctx->r10 = lo;
    // 0x800362F4: nop

    // 0x800362F8: nop

    // 0x800362FC: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80036300: mflo        $t3
    ctx->r11 = lo;
    // 0x80036304: addiu       $t4, $t3, -0x4
    ctx->r12 = ADD32(ctx->r11, -0X4);
    // 0x80036308: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8003630C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80036310: bgez        $t6, L_80036374
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80036314: sh          $t4, 0x8A($sp)
        MEM_H(0X8A, ctx->r29) = ctx->r12;
            goto L_80036374;
    }
    // 0x80036314: sh          $t4, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r12;
    // 0x80036318: sll         $t8, $t4, 16
    ctx->r24 = S32(ctx->r12 << 16);
    // 0x8003631C: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80036320: subu        $a0, $t7, $t9
    ctx->r4 = SUB32(ctx->r15, ctx->r25);
    // 0x80036324: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80036328: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x8003632C: negu        $t1, $v0
    ctx->r9 = SUB32(0, ctx->r2);
    // 0x80036330: blez        $v0, L_800363E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80036334: sh          $t1, 0x8A($sp)
        MEM_H(0X8A, ctx->r29) = ctx->r9;
            goto L_800363E4;
    }
    // 0x80036334: sh          $t1, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r9;
    // 0x80036338: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8003633C: addiu       $a0, $a0, 0x1FB0
    ctx->r4 = ADD32(ctx->r4, 0X1FB0);
L_80036340:
    // 0x80036340: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80036344: beq         $t2, $zero, L_80036360
    if (ctx->r10 == 0) {
        // 0x80036348: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80036360;
    }
    // 0x80036348: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8003634C: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x80036350: addu        $t5, $a0, $t3
    ctx->r13 = ADD32(ctx->r4, ctx->r11);
    // 0x80036354: ldc1        $f4, 0x0($t5)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r13, 0X0);
    // 0x80036358: mul.d       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x8003635C: nop

L_80036360:
    // 0x80036360: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80036364: bgtz        $t6, L_80036340
    if (SIGNED(ctx->r14) > 0) {
        // 0x80036368: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80036340;
    }
    // 0x80036368: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003636C: b           L_800363E8
    // 0x80036370: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
        goto L_800363E8;
    // 0x80036370: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_80036374:
    // 0x80036374: lh          $t4, 0x8A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X8A);
    // 0x80036378: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8003637C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80036380: blez        $t4, L_800363E4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80036384: andi        $t8, $t4, 0xFFFC
        ctx->r24 = ctx->r12 & 0XFFFC;
            goto L_800363E4;
    }
    // 0x80036384: andi        $t8, $t4, 0xFFFC
    ctx->r24 = ctx->r12 & 0XFFFC;
    // 0x80036388: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x8003638C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80036390: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80036394: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80036398: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8003639C: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800363A0: sh          $t8, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r24;
    // 0x800363A4: blez        $t0, L_800363E0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800363A8: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800363E0;
    }
    // 0x800363A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800363AC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800363B0: addiu       $a0, $a0, 0x1FB0
    ctx->r4 = ADD32(ctx->r4, 0X1FB0);
L_800363B4:
    // 0x800363B4: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800363B8: beq         $t1, $zero, L_800363D4
    if (ctx->r9 == 0) {
        // 0x800363BC: sra         $t5, $v0, 1
        ctx->r13 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800363D4;
    }
    // 0x800363BC: sra         $t5, $v0, 1
    ctx->r13 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800363C0: sll         $t2, $v1, 3
    ctx->r10 = S32(ctx->r3 << 3);
    // 0x800363C4: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x800363C8: ldc1        $f6, 0x0($t3)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r11, 0X0);
    // 0x800363CC: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800363D0: nop

L_800363D4:
    // 0x800363D4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800363D8: bgtz        $t5, L_800363B4
    if (SIGNED(ctx->r13) > 0) {
        // 0x800363DC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800363B4;
    }
    // 0x800363DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800363E0:
    // 0x800363E0: div.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f0.d);
L_800363E4:
    // 0x800363E4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_800363E8:
    // 0x800363E8: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800363EC: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x800363F0: bne         $t6, $at, L_80036404
    if (ctx->r14 != ctx->r1) {
        // 0x800363F4: addiu       $t8, $zero, 0x30
        ctx->r24 = ADD32(0, 0X30);
            goto L_80036404;
    }
    // 0x800363F4: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x800363F8: lh          $a1, 0x8A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X8A);
    // 0x800363FC: b           L_80036404
    // 0x80036400: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
        goto L_80036404;
    // 0x80036400: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_80036404:
    // 0x80036404: lw          $t7, 0x24($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X24);
    // 0x80036408: addu        $s5, $a1, $t7
    ctx->r21 = ADD32(ctx->r5, ctx->r15);
    // 0x8003640C: slti        $at, $s5, 0x14
    ctx->r1 = SIGNED(ctx->r21) < 0X14 ? 1 : 0;
    // 0x80036410: bne         $at, $zero, L_8003641C
    if (ctx->r1 != 0) {
        // 0x80036414: nop
    
            goto L_8003641C;
    }
    // 0x80036414: nop

    // 0x80036418: addiu       $s5, $zero, 0x13
    ctx->r21 = ADD32(0, 0X13);
L_8003641C:
    // 0x8003641C: blez        $s5, L_800364E4
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80036420: sb          $t8, 0xA0($sp)
        MEM_B(0XA0, ctx->r29) = ctx->r24;
            goto L_800364E4;
    }
    // 0x80036420: sb          $t8, 0xA0($sp)
    MEM_B(0XA0, ctx->r29) = ctx->r24;
    // 0x80036424: c.lt.d      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.d < ctx->f20.d;
    // 0x80036428: addiu       $s4, $zero, 0x30
    ctx->r20 = ADD32(0, 0X30);
    // 0x8003642C: addiu       $s3, $sp, 0x64
    ctx->r19 = ADD32(ctx->r29, 0X64);
    // 0x80036430: bc1fl       L_800364E8
    if (!c1cs) {
        // 0x80036434: lh          $t5, 0x8A($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X8A);
            goto L_800364E8;
    }
    goto skip_0;
    // 0x80036434: lh          $t5, 0x8A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X8A);
    skip_0:
    // 0x80036438: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
L_8003643C:
    // 0x8003643C: addiu       $s5, $s5, -0x8
    ctx->r21 = ADD32(ctx->r21, -0X8);
    // 0x80036440: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80036444: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x80036448: blez        $s5, L_8003646C
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8003644C: nop
    
            goto L_8003646C;
    }
    // 0x8003644C: nop

    // 0x80036450: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x80036454: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80036458: ldc1        $f4, 0x2008($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X2008);
    // 0x8003645C: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80036460: sub.d       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f20.d - ctx->f16.d;
    // 0x80036464: mul.d       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80036468: nop

L_8003646C:
    // 0x8003646C: blez        $s1, L_800364B4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80036470: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_800364B4;
    }
    // 0x80036470: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80036474: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x80036478: bltz        $s0, L_800364B4
    if (SIGNED(ctx->r16) < 0) {
        // 0x8003647C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800364B4;
    }
    // 0x8003647C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80036480:
    // 0x80036480: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80036484: jal         0x800376F0
    // 0x80036488: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x80036488: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_2:
    // 0x8003648C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80036490: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80036494: addiu       $t1, $t0, 0x30
    ctx->r9 = ADD32(ctx->r8, 0X30);
    // 0x80036498: sb          $t1, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r9;
    // 0x8003649C: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800364A0: blezl       $s1, L_800364B8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800364A4: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800364B8;
    }
    goto skip_1;
    // 0x800364A4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_1:
    // 0x800364A8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800364AC: bgezl       $s0, L_80036480
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800364B0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80036480;
    }
    goto skip_2;
    // 0x800364B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_2:
L_800364B4:
    // 0x800364B4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_800364B8:
    // 0x800364B8: bltz        $s0, L_800364CC
    if (SIGNED(ctx->r16) < 0) {
        // 0x800364BC: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800364CC;
    }
L_800364BC:
    // 0x800364BC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800364C0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800364C4: bgez        $s0, L_800364BC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800364C8: sb          $s4, 0x0($s2)
        MEM_B(0X0, ctx->r18) = ctx->r20;
            goto L_800364BC;
    }
    // 0x800364C8: sb          $s4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r20;
L_800364CC:
    // 0x800364CC: blez        $s5, L_800364E4
    if (SIGNED(ctx->r21) <= 0) {
        // 0x800364D0: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_800364E4;
    }
    // 0x800364D0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800364D4: c.lt.d      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.d < ctx->f20.d;
    // 0x800364D8: nop

    // 0x800364DC: bc1tl       L_8003643C
    if (c1cs) {
        // 0x800364E0: trunc.w.d   $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
            goto L_8003643C;
    }
    goto skip_3;
    // 0x800364E0: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
    skip_3:
L_800364E4:
    // 0x800364E4: lh          $t5, 0x8A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X8A);
L_800364E8:
    // 0x800364E8: lbu         $t4, 0xA1($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XA1);
    // 0x800364EC: addiu       $t3, $sp, 0xA0
    ctx->r11 = ADD32(ctx->r29, 0XA0);
    // 0x800364F0: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800364F4: subu        $s5, $s2, $t3
    ctx->r21 = SUB32(ctx->r18, ctx->r11);
    // 0x800364F8: addiu       $t6, $t5, 0x7
    ctx->r14 = ADD32(ctx->r13, 0X7);
    // 0x800364FC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80036500: sh          $t6, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r14;
    // 0x80036504: bne         $v0, $t4, L_8003652C
    if (ctx->r2 != ctx->r12) {
        // 0x80036508: addiu       $s2, $sp, 0xA1
        ctx->r18 = ADD32(ctx->r29, 0XA1);
            goto L_8003652C;
    }
    // 0x80036508: addiu       $s2, $sp, 0xA1
    ctx->r18 = ADD32(ctx->r29, 0XA1);
    // 0x8003650C: lh          $t7, 0x8A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8A);
L_80036510:
    // 0x80036510: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80036514: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80036518: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8003651C: sh          $t8, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r24;
    // 0x80036520: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x80036524: beql        $v0, $t9, L_80036510
    if (ctx->r2 == ctx->r25) {
        // 0x80036528: lh          $t7, 0x8A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X8A);
            goto L_80036510;
    }
    goto skip_4;
    // 0x80036528: lh          $t7, 0x8A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8A);
    skip_4:
L_8003652C:
    // 0x8003652C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80036530: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80036534: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x80036538: bne         $t0, $at, L_8003654C
    if (ctx->r8 != ctx->r1) {
        // 0x8003653C: lw          $t1, 0x50($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X50);
            goto L_8003654C;
    }
    // 0x8003653C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80036540: lh          $a1, 0x8A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X8A);
    // 0x80036544: b           L_8003656C
    // 0x80036548: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8003656C;
    // 0x80036548: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8003654C:
    // 0x8003654C: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80036550: beq         $t1, $at, L_80036560
    if (ctx->r9 == ctx->r1) {
        // 0x80036554: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_80036560;
    }
    // 0x80036554: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x80036558: bne         $t1, $at, L_80036568
    if (ctx->r9 != ctx->r1) {
        // 0x8003655C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80036568;
    }
    // 0x8003655C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036560:
    // 0x80036560: b           L_80036568
    // 0x80036564: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80036568;
    // 0x80036564: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036568:
    // 0x80036568: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8003656C:
    // 0x8003656C: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x80036570: addu        $a3, $a1, $t3
    ctx->r7 = ADD32(ctx->r5, ctx->r11);
    // 0x80036574: sll         $t5, $a3, 16
    ctx->r13 = S32(ctx->r7 << 16);
    // 0x80036578: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8003657C: slt         $at, $s5, $a3
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80036580: beq         $at, $zero, L_80036594
    if (ctx->r1 == 0) {
        // 0x80036584: nop
    
            goto L_80036594;
    }
    // 0x80036584: nop

    // 0x80036588: sll         $a3, $s5, 16
    ctx->r7 = S32(ctx->r21 << 16);
    // 0x8003658C: sra         $t4, $a3, 16
    ctx->r12 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80036590: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
L_80036594:
    // 0x80036594: blez        $a3, L_8003662C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80036598: slt         $at, $a3, $s5
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_8003662C;
    }
    // 0x80036598: slt         $at, $a3, $s5
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8003659C: beq         $at, $zero, L_800365BC
    if (ctx->r1 == 0) {
        // 0x800365A0: addu        $v0, $a3, $s2
        ctx->r2 = ADD32(ctx->r7, ctx->r18);
            goto L_800365BC;
    }
    // 0x800365A0: addu        $v0, $a3, $s2
    ctx->r2 = ADD32(ctx->r7, ctx->r18);
    // 0x800365A4: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800365A8: slti        $at, $t7, 0x35
    ctx->r1 = SIGNED(ctx->r15) < 0X35 ? 1 : 0;
    // 0x800365AC: bnel        $at, $zero, L_800365C0
    if (ctx->r1 != 0) {
        // 0x800365B0: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_800365C0;
    }
    goto skip_5;
    // 0x800365B0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    skip_5:
    // 0x800365B4: b           L_800365C4
    // 0x800365B8: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_800365C4;
    // 0x800365B8: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_800365BC:
    // 0x800365BC: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_800365C0:
    // 0x800365C0: addu        $v0, $a3, $s2
    ctx->r2 = ADD32(ctx->r7, ctx->r18);
L_800365C4:
    // 0x800365C4: lbu         $t8, -0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X1);
    // 0x800365C8: addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // 0x800365CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800365D0: bne         $a1, $t8, L_800365F8
    if (ctx->r5 != ctx->r24) {
        // 0x800365D4: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_800365F8;
    }
    // 0x800365D4: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x800365D8: addu        $v0, $v1, $s2
    ctx->r2 = ADD32(ctx->r3, ctx->r18);
L_800365DC:
    // 0x800365DC: lbu         $t1, -0x1($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0X1);
    // 0x800365E0: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800365E4: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x800365E8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800365EC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800365F0: beq         $a0, $t1, L_800365DC
    if (ctx->r4 == ctx->r9) {
        // 0x800365F4: sra         $a3, $t9, 16
        ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
            goto L_800365DC;
    }
    // 0x800365F4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
L_800365F8:
    // 0x800365F8: bne         $a0, $at, L_8003660C
    if (ctx->r4 != ctx->r1) {
        // 0x800365FC: addu        $v0, $s2, $v1
        ctx->r2 = ADD32(ctx->r18, ctx->r3);
            goto L_8003660C;
    }
    // 0x800365FC: addu        $v0, $s2, $v1
    ctx->r2 = ADD32(ctx->r18, ctx->r3);
    // 0x80036600: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80036604: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80036608: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_8003660C:
    // 0x8003660C: bgez        $v1, L_8003662C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80036610: lh          $t4, 0x8A($sp)
        ctx->r12 = MEM_H(ctx->r29, 0X8A);
            goto L_8003662C;
    }
    // 0x80036610: lh          $t4, 0x8A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X8A);
    // 0x80036614: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80036618: sll         $t5, $a3, 16
    ctx->r13 = S32(ctx->r7 << 16);
    // 0x8003661C: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x80036620: sh          $t7, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r15;
    // 0x80036624: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80036628: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8003662C:
    // 0x8003662C: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    // 0x80036630: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x80036634: lbu         $a1, 0xC7($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XC7);
    // 0x80036638: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8003663C: jal         0x80036728
    // 0x80036640: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    static_13_80036728(rdram, ctx);
        goto after_3;
    // 0x80036640: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_3:
    // 0x80036644: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80036648:
    // 0x80036648: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8003664C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80036650: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80036654: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80036658: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8003665C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80036660: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80036664: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80036668: jr          $ra
    // 0x8003666C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8003666C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void suspline_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800204: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80800208: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8080020C: lh          $t8, 0x70($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X70);
    // 0x80800210: jr          $ra
    // 0x80800214: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    return;
    // 0x80800214: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
;}
RECOMP_FUNC void func_800ADE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADE50: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800ADE54: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800ADE58: lh          $t6, 0x4($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X4);
    // 0x800ADE5C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800ADE60: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800ADE64: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800ADE68: beq         $v1, $t6, L_800ADE78
    if (ctx->r3 == ctx->r14) {
        // 0x800ADE6C: addiu       $a1, $a0, 0x50
        ctx->r5 = ADD32(ctx->r4, 0X50);
            goto L_800ADE78;
    }
    // 0x800ADE6C: addiu       $a1, $a0, 0x50
    ctx->r5 = ADD32(ctx->r4, 0X50);
    // 0x800ADE70: b           L_800ADEB8
    // 0x800ADE74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ADEB8;
    // 0x800ADE74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ADE78:
    // 0x800ADE78: sll         $t7, $v1, 6
    ctx->r15 = S32(ctx->r3 << 6);
    // 0x800ADE7C: addu        $a3, $t7, $a0
    ctx->r7 = ADD32(ctx->r15, ctx->r4);
    // 0x800ADE80: addiu       $a3, $a3, 0x50
    ctx->r7 = ADD32(ctx->r7, 0X50);
    // 0x800ADE84: sltu        $at, $a1, $a3
    ctx->r1 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x800ADE88: beql        $at, $zero, L_800ADEB8
    if (ctx->r1 == 0) {
        // 0x800ADE8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800ADEB8;
    }
    goto skip_0;
    // 0x800ADE8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_800ADE90:
    // 0x800ADE90: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x800ADE94: bnel        $s0, $t8, L_800ADEA8
    if (ctx->r16 != ctx->r24) {
        // 0x800ADE98: addiu       $a1, $a1, 0x40
        ctx->r5 = ADD32(ctx->r5, 0X40);
            goto L_800ADEA8;
    }
    goto skip_1;
    // 0x800ADE98: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    skip_1:
    // 0x800ADE9C: b           L_800ADEB8
    // 0x800ADEA0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800ADEB8;
    // 0x800ADEA0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800ADEA4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
L_800ADEA8:
    // 0x800ADEA8: sltu        $at, $a1, $a3
    ctx->r1 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x800ADEAC: bne         $at, $zero, L_800ADE90
    if (ctx->r1 != 0) {
        // 0x800ADEB0: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_800ADE90;
    }
    // 0x800ADEB0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800ADEB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ADEB8:
    // 0x800ADEB8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800ADEBC: jr          $ra
    // 0x800ADEC0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800ADEC0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8080064C_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080064C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800654: jal         0x80082FF0
    // 0x80800658: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800658: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080065C: jal         0x80800000
    // 0x80800660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bsbansnooze(rdram, ctx);
        goto after_1;
    // 0x80800660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080066C: jr          $ra
    // 0x80800670: nop

    return;
    // 0x80800670: nop

;}
RECOMP_FUNC void func_808030A4_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808030A4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808030A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808030AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808030B0: jal         0x80100094
    // 0x808030B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808030B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808030B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808030BC: lh          $t6, 0x46($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X46);
    // 0x808030C0: beql        $t6, $zero, L_8080314C
    if (ctx->r14 == 0) {
        // 0x808030C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080314C;
    }
    goto skip_0;
    // 0x808030C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808030C8: jal         0x800F54E4
    // 0x808030CC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808030CC: nop

    after_1:
    // 0x808030D0: jal         0x80087908
    // 0x808030D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _plcamera_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808030D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808030D8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x808030DC: beq         $v0, $at, L_808030F0
    if (ctx->r2 == ctx->r1) {
        // 0x808030E0: lw          $a1, 0x38($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X38);
            goto L_808030F0;
    }
    // 0x808030E0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808030E4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808030E8: b           L_80803148
    // 0x808030EC: sh          $zero, 0x46($t7)
    MEM_H(0X46, ctx->r15) = 0;
        goto L_80803148;
    // 0x808030EC: sh          $zero, 0x46($t7)
    MEM_H(0X46, ctx->r15) = 0;
L_808030F0:
    // 0x808030F0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808030F4: jal         0x800EE7F8
    // 0x808030F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808030F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x808030FC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80803100: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803104: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80803108: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080310C: jal         0x800F54E4
    // 0x80803110: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80803110: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80803114: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803118: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8080311C: jal         0x80087900
    // 0x80803120: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _plcamera_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80803120: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_5:
    // 0x80803124: jal         0x800F54E4
    // 0x80803128: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80803128: nop

    after_6:
    // 0x8080312C: jal         0x800F5EF8
    // 0x80803130: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_7;
    // 0x80803130: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80803134: jal         0x80110014
    // 0x80803138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_8;
    // 0x80803138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x8080313C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803140: jal         0x80116088
    // 0x80803144: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80116088(rdram, ctx);
        goto after_9;
    // 0x80803144: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_9:
L_80803148:
    // 0x80803148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080314C:
    // 0x8080314C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80803150: jr          $ra
    // 0x80803154: nop

    return;
    // 0x80803154: nop

;}
RECOMP_FUNC void _chnutsnbolts_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864E0: syscall     332
    recomp_syscall_handler(rdram, ctx, 0x800864E0);
    return;
    // 0x800864E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80014E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014E6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80014E70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014E74: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x80014E78: ori         $a1, $a1, 0x1D80
    ctx->r5 = ctx->r5 | 0X1D80;
    // 0x80014E7C: jal         0x80014E10
    // 0x80014E80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80014E10(rdram, ctx);
        goto after_0;
    // 0x80014E80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80014E84: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014E88: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x80014E8C: sw          $v0, -0x7080($at)
    MEM_W(-0X7080, ctx->r1) = ctx->r2;
    // 0x80014E90: ori         $a1, $a1, 0x1D80
    ctx->r5 = ctx->r5 | 0X1D80;
    // 0x80014E94: jal         0x80014E10
    // 0x80014E98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80014E10(rdram, ctx);
        goto after_1;
    // 0x80014E98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80014E9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014EA0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80014EA4: sw          $v0, -0x707C($at)
    MEM_W(-0X707C, ctx->r1) = ctx->r2;
    // 0x80014EA8: ori         $a1, $a1, 0xEC0
    ctx->r5 = ctx->r5 | 0XEC0;
    // 0x80014EAC: jal         0x80014E10
    // 0x80014EB0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80014E10(rdram, ctx);
        goto after_2;
    // 0x80014EB0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80014EB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014EB8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014EBC: sw          $v0, -0x7078($at)
    MEM_W(-0X7078, ctx->r1) = ctx->r2;
    // 0x80014EC0: jr          $ra
    // 0x80014EC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80014EC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void bsstonehead_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080115C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801160: jal         0x80085158
    // 0x80801164: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _baspin_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801164: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80801168: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080116C: bne         $v0, $at, L_80801178
    if (ctx->r2 != ctx->r1) {
        // 0x80801170: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80801178;
    }
    // 0x80801170: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801174: addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
L_80801178:
    // 0x80801178: jal         0x8009E5C8
    // 0x8080117C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x8080117C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801184: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801188: jr          $ra
    // 0x8080118C: nop

    return;
    // 0x8080118C: nop

;}
RECOMP_FUNC void chbaddiesetup_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800578: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080057C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800580: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800584: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800588: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080058C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800590: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800598: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080059C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005A0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808005A4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x808005A8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x808005AC: jal         0x80108474
    // 0x808005B0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_80108474(rdram, ctx);
        goto after_0;
    // 0x808005B0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x808005B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005BC: jr          $ra
    // 0x808005C0: nop

    return;
    // 0x808005C0: nop

;}
RECOMP_FUNC void func_8009EA4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EA50: jr          $ra
    // 0x8009EA54: lbu         $v0, 0x7074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7074);
    return;
    // 0x8009EA54: lbu         $v0, 0x7074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7074);
;}
RECOMP_FUNC void chmolehill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080051C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800524: jal         0x80106790
    // 0x80800528: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800528: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080052C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800530: addiu       $a0, $zero, 0x18F
    ctx->r4 = ADD32(0, 0X18F);
    // 0x80800534: jal         0x801084B0
    // 0x80800538: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x80800538: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8080053C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800540: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800544: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080054C: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
    // 0x80800550: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800554: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80800558: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    // 0x8080055C: jal         0x80108944
    // 0x80800560: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80108944(rdram, ctx);
        goto after_2;
    // 0x80800560: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800564: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800568: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080056C: lhu         $a1, 0x72($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X72);
    // 0x80800570: srl         $t1, $a1, 10
    ctx->r9 = S32(U32(ctx->r5) >> 10);
    // 0x80800574: jal         0x80086900
    // 0x80800578: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    _chmoley_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800578: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_3:
    // 0x8080057C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800580: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800584: jr          $ra
    // 0x80800588: nop

    return;
    // 0x80800588: nop

;}
RECOMP_FUNC void _bskazflamethrower_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083348: syscall     56
    recomp_syscall_handler(rdram, ctx, 0x80083348);
    return;
    // 0x8008334C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800D54_sumultiscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800D58: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800D5C: jr          $ra
    // 0x80800D60: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80800D60: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void func_8080077C_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080077C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800780: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800784: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800788: jal         0x80082FE8
    // 0x8080078C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080078C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800790: jal         0x80800694
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsbabykaz_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800798: jal         0x80084488
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808007A0: beql        $v0, $zero, L_808007C8
    if (ctx->r2 == 0) {
        // 0x808007A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808007C8;
    }
    goto skip_0;
    // 0x808007A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808007A8: jal         0x80084800
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808007B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007B4: beq         $v0, $at, L_808007C4
    if (ctx->r2 == ctx->r1) {
        // 0x808007B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007C4;
    }
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007BC: jal         0x8009E5C8
    // 0x808007C0: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x808007C0: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    after_4:
L_808007C4:
    // 0x808007C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007C8:
    // 0x808007C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007D0: jr          $ra
    // 0x808007D4: nop

    return;
    // 0x808007D4: nop

;}
RECOMP_FUNC void func_808003CC_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003D4: jal         0x800EA05C
    // 0x808003D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808003D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003DC: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
    // 0x808003E0: bne         $v0, $at, L_808003F0
    if (ctx->r2 != ctx->r1) {
        // 0x808003E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003F0;
    }
    // 0x808003E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E8: b           L_8080040C
    // 0x808003EC: addiu       $v0, $zero, 0x11AA
    ctx->r2 = ADD32(0, 0X11AA);
        goto L_8080040C;
    // 0x808003EC: addiu       $v0, $zero, 0x11AA
    ctx->r2 = ADD32(0, 0X11AA);
L_808003F0:
    // 0x808003F0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808003F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1688, 0X266E) << 16);
    // 0x808003F8: lw          $t7, 0x6C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X6C);
    // 0x808003FC: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80800400: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80800404: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80800408: lh          $v0, 0x266E($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1688, 0X266E));
L_8080040C:
    // 0x8080040C: jr          $ra
    // 0x80800410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bsvan_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084190: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084190);
    return;
    // 0x80084194: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_808002D4_basetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002E0: jal         0x8009E97C
    // 0x808002E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E97C(rdram, ctx);
        goto after_0;
    // 0x808002E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: jal         0x800917A8
    // 0x808002F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_set(rdram, ctx);
        goto after_1;
    // 0x808002F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808002F8: jal         0x8009E988
    // 0x808002FC: nop

    func_8009E988(rdram, ctx);
        goto after_2;
    // 0x808002FC: nop

    after_2:
    // 0x80800300: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: jal         0x800917A8
    // 0x8080030C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bastatetimer_set(rdram, ctx);
        goto after_3;
    // 0x8080030C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800310: jal         0x8009EA64
    // 0x80800314: nop

    func_8009EA64(rdram, ctx);
        goto after_4;
    // 0x80800314: nop

    after_4:
    // 0x80800318: beq         $v0, $zero, L_8080033C
    if (ctx->r2 == 0) {
        // 0x8080031C: nop
    
            goto L_8080033C;
    }
    // 0x8080031C: nop

    // 0x80800320: jal         0x80084748
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_33(rdram, ctx);
        goto after_5;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080032C: jal         0x8009E5C8
    // 0x80800330: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x80800330: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80800334: b           L_80800378
    // 0x80800338: nop

        goto L_80800378;
    // 0x80800338: nop

L_8080033C:
    // 0x8080033C: jal         0x8009EA20
    // 0x80800340: nop

    func_8009EA20(rdram, ctx);
        goto after_7;
    // 0x80800340: nop

    after_7:
    // 0x80800344: beq         $v0, $zero, L_8080035C
    if (ctx->r2 == 0) {
        // 0x80800348: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080035C;
    }
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080034C: jal         0x8009E5C8
    // 0x80800350: addiu       $a1, $zero, 0x11E
    ctx->r5 = ADD32(0, 0X11E);
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80800350: addiu       $a1, $zero, 0x11E
    ctx->r5 = ADD32(0, 0X11E);
    after_8:
    // 0x80800354: b           L_80800378
    // 0x80800358: nop

        goto L_80800378;
    // 0x80800358: nop

L_8080035C:
    // 0x8080035C: jal         0x80800008
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_basetup(rdram, ctx);
        goto after_9;
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800364: jal         0x80084758
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_35(rdram, ctx);
        goto after_10;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: jal         0x8009E5C8
    // 0x80800374: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x80800374: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
L_80800378:
    // 0x80800378: jal         0x80800080
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800080_basetup(rdram, ctx);
        goto after_12;
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800388: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void func_80800000_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800010: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800014: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800020: bnel        $t7, $at, L_80800048
    if (ctx->r15 != ctx->r1) {
        // 0x80800024: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800048;
    }
    goto skip_0;
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800028: jal         0x80087CC8
    // 0x8080002C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800030: jal         0x80090708
    // 0x80800034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_1;
    // 0x80800034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: jal         0x8010A828
    // 0x80800040: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A828(rdram, ctx);
        goto after_2;
    // 0x80800040: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800048:
    // 0x80800048: jal         0x80102424
    // 0x8080004C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x8080004C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800050: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x80800054: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800058: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080005C: srl         $t8, $a1, 10
    ctx->r24 = S32(U32(ctx->r5) >> 10);
    // 0x80800060: beq         $t8, $at, L_80800090
    if (ctx->r24 == ctx->r1) {
        // 0x80800064: addiu       $a1, $zero, 0xF96
        ctx->r5 = ADD32(0, 0XF96);
            goto L_80800090;
    }
    // 0x80800064: addiu       $a1, $zero, 0xF96
    ctx->r5 = ADD32(0, 0XF96);
    // 0x80800068: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080006C: beq         $t8, $at, L_808000AC
    if (ctx->r24 == ctx->r1) {
        // 0x80800070: addiu       $a1, $zero, 0xD80
        ctx->r5 = ADD32(0, 0XD80);
            goto L_808000AC;
    }
    // 0x80800070: addiu       $a1, $zero, 0xD80
    ctx->r5 = ADD32(0, 0XD80);
    // 0x80800074: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800078: beq         $t8, $at, L_808000EC
    if (ctx->r24 == ctx->r1) {
        // 0x8080007C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808000EC;
    }
    // 0x8080007C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800080: beq         $t8, $at, L_808000CC
    if (ctx->r24 == ctx->r1) {
        // 0x80800084: addiu       $a1, $zero, 0x12C5
        ctx->r5 = ADD32(0, 0X12C5);
            goto L_808000CC;
    }
    // 0x80800084: addiu       $a1, $zero, 0x12C5
    ctx->r5 = ADD32(0, 0X12C5);
    // 0x80800088: b           L_808001E8
    // 0x8080008C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001E8;
    // 0x8080008C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800090:
    // 0x80800090: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800094: addiu       $t9, $zero, 0x42
    ctx->r25 = ADD32(0, 0X42);
    // 0x80800098: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080009C: jal         0x8008A208
    // 0x808000A0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808000A0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808000A4: b           L_808001E8
    // 0x808000A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001E8;
    // 0x808000A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000AC:
    // 0x808000AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000B0: addiu       $t0, $zero, 0x42
    ctx->r8 = ADD32(0, 0X42);
    // 0x808000B4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808000B8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808000BC: jal         0x8008A208
    // 0x808000C0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808000C0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808000C4: b           L_808001E8
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001E8;
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000CC:
    // 0x808000CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000D0: addiu       $t1, $zero, 0x42
    ctx->r9 = ADD32(0, 0X42);
    // 0x808000D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808000D8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808000DC: jal         0x8008A208
    // 0x808000E0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808000E0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x808000E4: b           L_808001E8
    // 0x808000E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001E8;
    // 0x808000E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000EC:
    // 0x808000EC: jal         0x8080070C
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080070C_chchuffycont(rdram, ctx);
        goto after_7;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000F4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808000F8: addiu       $t2, $zero, 0x184B
    ctx->r10 = ADD32(0, 0X184B);
    // 0x808000FC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800100: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800104: addiu       $a2, $a2, 0x7DB0
    ctx->r6 = ADD32(ctx->r6, 0X7DB0);
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800110: jal         0x80087CB8
    // 0x80800114: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800114: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x80100094
    // 0x80800120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800124: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800128: jal         0x80090708
    // 0x8080012C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_10;
    // 0x8080012C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x80800130: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800134: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80800138: bne         $at, $zero, L_80800148
    if (ctx->r1 != 0) {
        // 0x8080013C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800148;
    }
    // 0x8080013C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800140: b           L_80800148
    // 0x80800144: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_80800148;
    // 0x80800144: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80800148:
    // 0x80800148: jal         0x80087CD8
    // 0x8080014C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x8080014C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_11:
    // 0x80800150: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800154: jal         0x80087CE0
    // 0x80800158: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80800158: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x8080015C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800160: jal         0x80087CE8
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_13;
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: jal         0x8080046C
    // 0x80800170: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8080046C_chchuffycont(rdram, ctx);
        goto after_14;
    // 0x80800170: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_14:
    // 0x80800174: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800178: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080017C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800184: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800188: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8080018C: jal         0x80087D08
    // 0x80800190: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _gcnewoption_entrypoint_14(rdram, ctx);
        goto after_15;
    // 0x80800190: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x80800194: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1704, 0XB10) << 16);
    // 0x80800198: lwc1        $f6, 0xB10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1704, 0XB10));
    // 0x8080019C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001A8: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x808001AC: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x808001B0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x808001B4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808001B8: jal         0x80087DD8
    // 0x808001BC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_16;
    // 0x808001BC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x808001C0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808001C4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808001C8: jal         0x80087DE8
    // 0x808001CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _gcnewoption_entrypoint_42(rdram, ctx);
        goto after_17;
    // 0x808001CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_17:
    // 0x808001D0: jal         0x80087CF0
    // 0x808001D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x808001D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: jal         0x8010A828
    // 0x808001E0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8010A828(rdram, ctx);
        goto after_19;
    // 0x808001E0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_19:
    // 0x808001E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001E8:
    // 0x808001E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001F0: jr          $ra
    // 0x808001F4: nop

    return;
    // 0x808001F4: nop

;}
RECOMP_FUNC void chflysaucer_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803838: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1692, 0X4668) << 16);
    // 0x8080383C: jr          $ra
    // 0x80803840: addiu       $v0, $v0, 0x4668
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1692, 0X4668));
    return;
    // 0x80803840: addiu       $v0, $v0, 0x4668
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1692, 0X4668));
;}
RECOMP_FUNC void _chmonsterinterior_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086540: syscall     336
    recomp_syscall_handler(rdram, ctx, 0x80086540);
    return;
    // 0x80086544: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chfantasylakebits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087668: syscall     602
    recomp_syscall_handler(rdram, ctx, 0x80087668);
    return;
    // 0x8008766C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800AA8_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AB0: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80800AB4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800AB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800ABC: beql        $t6, $zero, L_80800AD8
    if (ctx->r14 == 0) {
        // 0x80800AC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800AD8;
    }
    goto skip_0;
    // 0x80800AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800AC4: jal         0x800856B8
    // 0x80800AC8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800AC8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800ACC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800AD0: sw          $zero, 0x28($a1)
    MEM_W(0X28, ctx->r5) = 0;
    // 0x80800AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800AD8:
    // 0x80800AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800ADC: jr          $ra
    // 0x80800AE0: nop

    return;
    // 0x80800AE0: nop

;}
RECOMP_FUNC void func_80110790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110798: jal         0x800EE7F8
    // 0x8011079C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8011079C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_0:
    // 0x801107A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801107A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801107A8: jr          $ra
    // 0x801107AC: nop

    return;
    // 0x801107AC: nop

;}
RECOMP_FUNC void func_80800124_chcheatopage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800128: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8080012C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800130: beq         $a1, $at, L_8080015C
    if (ctx->r5 == ctx->r1) {
        // 0x80800134: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080015C;
    }
    // 0x80800134: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800138: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8080013C: beq         $a1, $at, L_80800168
    if (ctx->r5 == ctx->r1) {
        // 0x80800140: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_80800168;
    }
    // 0x80800140: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800144: bne         $a1, $at, L_80800178
    if (ctx->r5 != ctx->r1) {
        // 0x80800148: nop
    
            goto L_80800178;
    }
    // 0x80800148: nop

    // 0x8080014C: jal         0x80800194
    // 0x80800150: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800194_chcheatopage(rdram, ctx);
        goto after_0;
    // 0x80800150: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800154: b           L_80800184
    // 0x80800158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800184;
    // 0x80800158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080015C:
    // 0x8080015C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: b           L_80800180
    // 0x80800164: sw          $t6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r14;
        goto L_80800180;
    // 0x80800164: sw          $t6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r14;
L_80800168:
    // 0x80800168: lbu         $t8, 0x65($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X65);
    // 0x8080016C: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80800170: b           L_80800180
    // 0x80800174: sb          $t9, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r25;
        goto L_80800180;
    // 0x80800174: sb          $t9, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r25;
L_80800178:
    // 0x80800178: b           L_80800184
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800184;
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800180:
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800184:
    // 0x80800184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void func_808008A4_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808008A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808008AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808008B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008B4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x808008B8: jal         0x800852F0
    // 0x808008BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x808008BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008C0: beq         $v0, $zero, L_8080090C
    if (ctx->r2 == 0) {
        // 0x808008C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080090C;
    }
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008CC: jal         0x80085338
    // 0x808008D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _batimer_set(rdram, ctx);
        goto after_1;
    // 0x808008D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x808008D4: jal         0x800A1718
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_2;
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808008DC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808008E0: jal         0x800A1760
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1760(rdram, ctx);
        goto after_3;
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008E8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808008EC: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808008F0: beql        $at, $zero, L_80800910
    if (ctx->r1 == 0) {
        // 0x808008F4: lbu         $v0, 0x15C($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X15C);
            goto L_80800910;
    }
    goto skip_0;
    // 0x808008F4: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    skip_0:
    // 0x808008F8: jal         0x800FC660
    // 0x808008FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x808008FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_4:
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800904: jal         0x800A17A8
    // 0x80800908: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A17A8(rdram, ctx);
        goto after_5;
    // 0x80800908: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_8080090C:
    // 0x8080090C: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
L_80800910:
    // 0x80800910: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800914: beql        $v0, $zero, L_808009B0
    if (ctx->r2 == 0) {
        // 0x80800918: lui         $a1, 0x3F7D
        ctx->r5 = S32(0X3F7D << 16);
            goto L_808009B0;
    }
    goto skip_1;
    // 0x80800918: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    skip_1:
    // 0x8080091C: bne         $v0, $at, L_8080092C
    if (ctx->r2 != ctx->r1) {
        // 0x80800920: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(49, 0XA34) << 16);
            goto L_8080092C;
    }
    // 0x80800920: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(49, 0XA34) << 16);
    // 0x80800924: b           L_80800934
    // 0x80800928: lwc1        $f0, 0xA34($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(49, 0XA34));
        goto L_80800934;
    // 0x80800928: lwc1        $f0, 0xA34($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(49, 0XA34));
L_8080092C:
    // 0x8080092C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(49, 0XA38) << 16);
    // 0x80800930: lwc1        $f0, 0xA38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(49, 0XA38));
L_80800934:
    // 0x80800934: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800938: jal         0x8008CB10
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800940: beq         $v0, $zero, L_80800970
    if (ctx->r2 == 0) {
        // 0x80800944: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800970;
    }
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800948: lui         $a2, 0x3F6E
    ctx->r6 = S32(0X3F6E << 16);
    // 0x8080094C: lui         $a3, 0x3F8A
    ctx->r7 = S32(0X3F8A << 16);
    // 0x80800950: addiu       $t7, $zero, 0x4E20
    ctx->r15 = ADD32(0, 0X4E20);
    // 0x80800954: addiu       $t8, $zero, 0x55F0
    ctx->r24 = ADD32(0, 0X55F0);
    // 0x80800958: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8080095C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800960: ori         $a3, $a3, 0x3D71
    ctx->r7 = ctx->r7 | 0X3D71;
    // 0x80800964: ori         $a2, $a2, 0x147B
    ctx->r6 = ctx->r6 | 0X147B;
    // 0x80800968: jal         0x8009DEC0
    // 0x8080096C: addiu       $a1, $zero, 0x441
    ctx->r5 = ADD32(0, 0X441);
    func_8009DEC0(rdram, ctx);
        goto after_7;
    // 0x8080096C: addiu       $a1, $zero, 0x441
    ctx->r5 = ADD32(0, 0X441);
    after_7:
L_80800970:
    // 0x80800970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800974: jal         0x8008CB10
    // 0x80800978: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x80800978: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_8:
    // 0x8080097C: beq         $v0, $zero, L_808009AC
    if (ctx->r2 == 0) {
        // 0x80800980: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009AC;
    }
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800984: lui         $a2, 0x3F6E
    ctx->r6 = S32(0X3F6E << 16);
    // 0x80800988: lui         $a3, 0x3F8A
    ctx->r7 = S32(0X3F8A << 16);
    // 0x8080098C: addiu       $t9, $zero, 0x4E20
    ctx->r25 = ADD32(0, 0X4E20);
    // 0x80800990: addiu       $t0, $zero, 0x55F0
    ctx->r8 = ADD32(0, 0X55F0);
    // 0x80800994: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800998: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080099C: ori         $a3, $a3, 0x3D71
    ctx->r7 = ctx->r7 | 0X3D71;
    // 0x808009A0: ori         $a2, $a2, 0x147B
    ctx->r6 = ctx->r6 | 0X147B;
    // 0x808009A4: jal         0x8009DFD4
    // 0x808009A8: addiu       $a1, $zero, 0x442
    ctx->r5 = ADD32(0, 0X442);
    func_8009DFD4(rdram, ctx);
        goto after_9;
    // 0x808009A8: addiu       $a1, $zero, 0x442
    ctx->r5 = ADD32(0, 0X442);
    after_9:
L_808009AC:
    // 0x808009AC: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
L_808009B0:
    // 0x808009B0: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x808009B4: jal         0x8008CB10
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_10;
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808009BC: beq         $v0, $zero, L_808009CC
    if (ctx->r2 == 0) {
        // 0x808009C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009CC;
    }
    // 0x808009C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x808009C8: sb          $t1, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r9;
L_808009CC:
    // 0x808009CC: jal         0x80091A30
    // 0x808009D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_11;
    // 0x808009D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808009D4: beq         $v0, $zero, L_808009E0
    if (ctx->r2 == 0) {
        // 0x808009D8: addiu       $t2, $zero, 0x172
        ctx->r10 = ADD32(0, 0X172);
            goto L_808009E0;
    }
    // 0x808009D8: addiu       $t2, $zero, 0x172
    ctx->r10 = ADD32(0, 0X172);
    // 0x808009DC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_808009E0:
    // 0x808009E0: jal         0x8008E35C
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_12;
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808009E8: beq         $v0, $zero, L_808009F8
    if (ctx->r2 == 0) {
        // 0x808009EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009F8;
    }
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F0: addiu       $t3, $zero, 0x4C
    ctx->r11 = ADD32(0, 0X4C);
    // 0x808009F4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_808009F8:
    // 0x808009F8: jal         0x8009E5C8
    // 0x808009FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x808009FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x80800A00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800A04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800A0C: jr          $ra
    // 0x80800A10: nop

    return;
    // 0x80800A10: nop

;}
RECOMP_FUNC void func_808005F4_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800600: jal         0x800910BC
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800910BC(rdram, ctx);
        goto after_0;
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800608: jal         0x80800104
    // 0x8080060C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800104_bsbswim(rdram, ctx);
        goto after_1;
    // 0x8080060C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800618: jr          $ra
    // 0x8080061C: nop

    return;
    // 0x8080061C: nop

;}
RECOMP_FUNC void func_800A8AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8AF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A8AF4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A8AF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A8AFC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A8B00: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A8B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A8B08: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800A8B0C: jal         0x80015D14
    // 0x800A8B10: lw          $a0, 0x7688($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7688);
    func_80015D14(rdram, ctx);
        goto after_0;
    // 0x800A8B10: lw          $a0, 0x7688($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7688);
    after_0:
    // 0x800A8B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A8B18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A8B1C: jr          $ra
    // 0x800A8B20: nop

    return;
    // 0x800A8B20: nop

;}
RECOMP_FUNC void basnowball_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800458: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080045C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800460: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800464: jal         0x80085458
    // 0x80800468: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bawobble_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800468: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080046C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800470: lw          $t6, 0x110($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X110);
    // 0x80800474: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80800478: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080047C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x80800480: lw          $t7, 0x110($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X110);
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080048C: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80800490: lw          $t8, 0x110($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X110);
    // 0x80800494: sb          $zero, 0x2D($t8)
    MEM_B(0X2D, ctx->r24) = 0;
    // 0x80800498: lw          $t9, 0x110($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X110);
    // 0x8080049C: jal         0x80800008
    // 0x808004A0: sb          $zero, 0x2C($t9)
    MEM_B(0X2C, ctx->r25) = 0;
    func_80800008_basnowball(rdram, ctx);
        goto after_1;
    // 0x808004A0: sb          $zero, 0x2C($t9)
    MEM_B(0X2C, ctx->r25) = 0;
    after_1:
    // 0x808004A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808004A8: lw          $t0, 0x110($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X110);
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004B4: swc1        $f0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f0.u32l;
    // 0x808004B8: lw          $t1, 0x110($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X110);
    // 0x808004BC: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x808004C0: lw          $t2, 0x110($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X110);
    // 0x808004C4: jal         0x80800150
    // 0x808004C8: sb          $zero, 0x14($t2)
    MEM_B(0X14, ctx->r10) = 0;
    func_80800150_basnowball(rdram, ctx);
        goto after_2;
    // 0x808004C8: sb          $zero, 0x14($t2)
    MEM_B(0X14, ctx->r10) = 0;
    after_2:
    // 0x808004CC: lw          $t3, 0x110($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X110);
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004D8: jal         0x808001B8
    // 0x808004DC: sb          $zero, 0x28($t3)
    MEM_B(0X28, ctx->r11) = 0;
    func_808001B8_basnowball(rdram, ctx);
        goto after_3;
    // 0x808004DC: sb          $zero, 0x28($t3)
    MEM_B(0X28, ctx->r11) = 0;
    after_3:
    // 0x808004E0: lw          $t4, 0x110($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X110);
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: jal         0x80093230
    // 0x808004EC: lw          $a1, 0x1C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X1C);
    func_80093230(rdram, ctx);
        goto after_4;
    // 0x808004EC: lw          $a1, 0x1C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X1C);
    after_4:
    // 0x808004F0: jal         0x8009E4AC
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_5;
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808004F8: lw          $t5, 0x110($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X110);
    // 0x808004FC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800500: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800504: lwc1        $f8, 0x1C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080050C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800510: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800514: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800518: jal         0x8009E55C
    // 0x8080051C: nop

    func_8009E55C(rdram, ctx);
        goto after_6;
    // 0x8080051C: nop

    after_6:
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800528: jal         0x8009E55C
    // 0x8080052C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_7;
    // 0x8080052C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_7:
    // 0x80800530: jal         0x808000C0
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C0_basnowball(rdram, ctx);
        goto after_8;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800538: jal         0x80800110
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800110_basnowball(rdram, ctx);
        goto after_9;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800544: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800548: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080054C: jr          $ra
    // 0x80800550: nop

    return;
    // 0x80800550: nop

;}
RECOMP_FUNC void func_800F51F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F51F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F51F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F51F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F51FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5200: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5204: jal         0x80093504
    // 0x800F5208: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80093504(rdram, ctx);
        goto after_0;
    // 0x800F5208: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F520C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5214: jr          $ra
    // 0x800F5218: nop

    return;
    // 0x800F5218: nop

;}
RECOMP_FUNC void _badeathmatch_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085550: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x80085550);
    return;
    // 0x80085554: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _gcdialogexec_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E38: syscall     658
    recomp_syscall_handler(rdram, ctx, 0x80087E38);
    return;
    // 0x80087E3C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bafpctrl_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EAC: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800EB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800EB4: lbu         $v0, 0x10($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X10);
    // 0x80800EB8: beq         $v0, $at, L_80800F10
    if (ctx->r2 == ctx->r1) {
        // 0x80800EBC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800F10;
    }
    // 0x80800EBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800EC0: beq         $v0, $at, L_80800ED8
    if (ctx->r2 == ctx->r1) {
        // 0x80800EC4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800ED8;
    }
    // 0x80800EC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800EC8: beq         $v0, $at, L_80800EF8
    if (ctx->r2 == ctx->r1) {
        // 0x80800ECC: nop
    
            goto L_80800EF8;
    }
    // 0x80800ECC: nop

    // 0x80800ED0: b           L_80800F14
    // 0x80800ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F14;
    // 0x80800ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800ED8:
    // 0x80800ED8: jal         0x80800E30
    // 0x80800EDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800E30_bafpctrl(rdram, ctx);
        goto after_0;
    // 0x80800EDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800EE0: beq         $v0, $zero, L_80800F10
    if (ctx->r2 == 0) {
        // 0x80800EE4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800F10;
    }
    // 0x80800EE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800EE8: jal         0x80800D38
    // 0x80800EEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bafpctrl_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80800EEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800EF0: b           L_80800F14
    // 0x80800EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F14;
    // 0x80800EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800EF8:
    // 0x80800EF8: jal         0x80800970
    // 0x80800EFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800970_bafpctrl(rdram, ctx);
        goto after_2;
    // 0x80800EFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800F00: beq         $v0, $zero, L_80800F10
    if (ctx->r2 == 0) {
        // 0x80800F04: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800F10;
    }
    // 0x80800F04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F08: jal         0x80800D38
    // 0x80800F0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bafpctrl_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x80800F0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_80800F10:
    // 0x80800F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F14:
    // 0x80800F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F18: jr          $ra
    // 0x80800F1C: nop

    return;
    // 0x80800F1C: nop

;}
RECOMP_FUNC void _bscarry_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E80: syscall     31
    recomp_syscall_handler(rdram, ctx, 0x80082E80);
    return;
    // 0x80082E84: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8001E204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E204: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E208: jr          $ra
    // 0x8001E20C: lbu         $v0, -0x2487($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2487);
    return;
    // 0x8001E20C: lbu         $v0, -0x2487($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2487);
;}
RECOMP_FUNC void sujiggy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F0: addiu       $a0, $zero, 0x35C
    ctx->r4 = ADD32(0, 0X35C);
    // 0x808000F4: jal         0x800DA564
    // 0x808000F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x808000F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void _gcstatusDll_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088388: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088388);
    return;
    // 0x8008838C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_800F16AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F16AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F16B0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800F16B4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800F16B8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800F16BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800F16C0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800F16C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F16C8: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800F16CC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800F16D0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800F16D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800F16D8: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800F16DC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800F16E0: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_800F16E4:
    // 0x800F16E4: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F16E8: jal         0x800F1DCC
    // 0x800F16EC: lwc1        $f14, 0x0($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X0);
    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x800F16EC: lwc1        $f14, 0x0($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x800F16F0: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800F16F4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F16F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800F16FC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800F1700: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800F1704: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800F1708: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F170C: bne         $s1, $s4, L_800F16E4
    if (ctx->r17 != ctx->r20) {
        // 0x800F1710: swc1        $f8, -0x4($s3)
        MEM_W(-0X4, ctx->r19) = ctx->f8.u32l;
            goto L_800F16E4;
    }
    // 0x800F1710: swc1        $f8, -0x4($s3)
    MEM_W(-0X4, ctx->r19) = ctx->f8.u32l;
    // 0x800F1714: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800F1718: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800F171C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F1720: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800F1724: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800F1728: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800F172C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800F1730: jr          $ra
    // 0x800F1734: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800F1734: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80016810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016810: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80016814: lw          $t6, -0x6088($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6088);
    // 0x80016818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001681C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016820: bne         $t6, $at, L_80016854
    if (ctx->r14 != ctx->r1) {
        // 0x80016824: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80016854;
    }
    // 0x80016824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016828: jal         0x80016934
    // 0x8001682C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80016934(rdram, ctx);
        goto after_0;
    // 0x8001682C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80016830: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80016834: jal         0x8002E900
    // 0x80016838: addiu       $a0, $a0, -0x6458
    ctx->r4 = ADD32(ctx->r4, -0X6458);
    osStopThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80016838: addiu       $a0, $a0, -0x6458
    ctx->r4 = ADD32(ctx->r4, -0X6458);
    after_1:
    // 0x8001683C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80016840: jal         0x8002FF90
    // 0x80016844: addiu       $a0, $a0, -0x64A0
    ctx->r4 = ADD32(ctx->r4, -0X64A0);
    osContStartReadData_recomp(rdram, ctx);
        goto after_2;
    // 0x80016844: addiu       $a0, $a0, -0x64A0
    ctx->r4 = ADD32(ctx->r4, -0X64A0);
    after_2:
    // 0x80016848: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001684C: jal         0x8002E510
    // 0x80016850: addiu       $a0, $a0, -0x6458
    ctx->r4 = ADD32(ctx->r4, -0X6458);
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x80016850: addiu       $a0, $a0, -0x6458
    ctx->r4 = ADD32(ctx->r4, -0X6458);
    after_3:
L_80016854:
    // 0x80016854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001685C: jr          $ra
    // 0x80016860: nop

    return;
    // 0x80016860: nop

;}
RECOMP_FUNC void func_80800340_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800348: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080034C: jal         0x80100094
    // 0x80800350: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800350: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800354: jal         0x80800DB4
    // 0x80800358: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800DB4_chfactoryworkerdirty(rdram, ctx);
        goto after_1;
    // 0x80800358: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800364: jr          $ra
    // 0x80800368: nop

    return;
    // 0x80800368: nop

;}
RECOMP_FUNC void func_800DC4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC4D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC4D8: beq         $a0, $zero, L_800DC4F8
    if (ctx->r4 == 0) {
        // 0x800DC4DC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800DC4F8;
    }
    // 0x800DC4DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC4E0: jal         0x80020760
    // 0x800DC4E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80020760(rdram, ctx);
        goto after_0;
    // 0x800DC4E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800DC4E8: beq         $v0, $zero, L_800DC4F8
    if (ctx->r2 == 0) {
        // 0x800DC4EC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800DC4F8;
    }
    // 0x800DC4EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DC4F0: jal         0x80020A60
    // 0x800DC4F4: nop

    func_80020A60(rdram, ctx);
        goto after_1;
    // 0x800DC4F4: nop

    after_1:
L_800DC4F8:
    // 0x800DC4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC4FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC500: jr          $ra
    // 0x800DC504: nop

    return;
    // 0x800DC504: nop

;}
