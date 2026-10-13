#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void scinfobar_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800530: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80800534: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800538: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8080053C: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80800540: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800544: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800548: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080054C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800550: sh          $a1, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r5;
    // 0x80800554: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800558: div.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080055C: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x80800560: jr          $ra
    // 0x80800564: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x80800564: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void glhittableDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080008C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800090: jal         0x80800174
    // 0x80800094: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    glhittableDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800094: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800098: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080009C: bne         $v0, $at, L_808000AC
    if (ctx->r2 != ctx->r1) {
        // 0x808000A0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_808000AC;
    }
    // 0x808000A0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808000A4: b           L_808000E0
    // 0x808000A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000E0;
    // 0x808000A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000AC:
    // 0x808000AC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x808000B0: bne         $v0, $at, L_808000C0
    if (ctx->r2 != ctx->r1) {
        // 0x808000B4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808000C0;
    }
    // 0x808000B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808000B8: b           L_808000E0
    // 0x808000BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000E0;
    // 0x808000BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C0:
    // 0x808000C0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808000C4: jal         0x800EB2DC
    // 0x808000C8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800EB2DC(rdram, ctx);
        goto after_1;
    // 0x808000C8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x808000CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000D4: jal         0x800EB2DC
    // 0x808000D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EB2DC(rdram, ctx);
        goto after_2;
    // 0x808000D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808000DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000E0:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_80016A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016A74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80016A78: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80016A7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80016A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016A84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80016A88: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80016A8C: jal         0x80016068
    // 0x80016A90: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_80016068(rdram, ctx);
        goto after_0;
    // 0x80016A90: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80016A94: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016A98: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016A9C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016AA0: nop

    // 0x80016AA4: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80016AA8: jal         0x8002DCA0
    // 0x80016AAC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80016AAC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x80016AB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80016AB4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80016AB8: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016ABC: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80016AC0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016AC4: bc1tl       L_80016AE4
    if (c1cs) {
        // 0x80016AC8: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_80016AE4;
    }
    goto skip_0;
    // 0x80016AC8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80016ACC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80016AD0: jal         0x80013B70
    // 0x80016AD4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80013B70(rdram, ctx);
        goto after_2;
    // 0x80016AD4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80016AD8: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80016ADC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80016AE0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80016AE4:
    // 0x80016AE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016AE8: beql        $v0, $zero, L_80016B18
    if (ctx->r2 == 0) {
        // 0x80016AEC: lwc1        $f16, 0x18($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80016B18;
    }
    goto skip_1;
    // 0x80016AEC: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x80016AF0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80016AF4: nop

    // 0x80016AF8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80016AFC: nop

    // 0x80016B00: bc1fl       L_80016B14
    if (!c1cs) {
        // 0x80016B04: swc1        $f2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
            goto L_80016B14;
    }
    goto skip_2;
    // 0x80016B04: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    skip_2:
    // 0x80016B08: b           L_80016B14
    // 0x80016B0C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_80016B14;
    // 0x80016B0C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80016B10: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_80016B14:
    // 0x80016B14: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
L_80016B18:
    // 0x80016B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016B1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80016B20: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80016B24: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80016B28: jr          $ra
    // 0x80016B2C: nop

    return;
    // 0x80016B2C: nop

;}
RECOMP_FUNC void bainvisible_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080044C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800450: lw          $a1, 0xA8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XA8);
    // 0x80800454: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800458: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080045C: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x80800460: jal         0x80800000
    // 0x80800464: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800000_bainvisible(rdram, ctx);
        goto after_0;
    // 0x80800464: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800468: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080046C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800470: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800474: jal         0x80800000
    // 0x80800478: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_80800000_bainvisible(rdram, ctx);
        goto after_1;
    // 0x80800478: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_1:
    // 0x8080047C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800480: jal         0x80091788
    // 0x80800484: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bastatetimer_clear(rdram, ctx);
        goto after_2;
    // 0x80800484: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x80800488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080048C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800490: jr          $ra
    // 0x80800494: nop

    return;
    // 0x80800494: nop

;}
RECOMP_FUNC void func_80801D0C_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801D10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801D18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801D1C: jal         0x80100094
    // 0x80801D20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801D20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801D24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801D28: addiu       $a0, $zero, 0x298
    ctx->r4 = ADD32(0, 0X298);
    // 0x80801D2C: jal         0x801084B0
    // 0x80801D30: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x80801D30: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80801D34: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801D38: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80801D3C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801D40: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80801D44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801D48: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    // 0x80801D4C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80801D50: jal         0x8008A490
    // 0x80801D54: sw          $t8, 0xA0($t9)
    MEM_W(0XA0, ctx->r25) = ctx->r24;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80801D54: sw          $t8, 0xA0($t9)
    MEM_W(0XA0, ctx->r25) = ctx->r24;
    after_2:
    // 0x80801D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D5C: jal         0x8010A800
    // 0x80801D60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_3;
    // 0x80801D60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80801D64: jal         0x8010A570
    // 0x80801D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80801D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801D6C: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80801D70: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80801D74: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801D78: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x80801D7C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80801D80: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80801D84: jal         0x8008A0E0
    // 0x80801D88: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80801D88: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_5:
    // 0x80801D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801D94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801D98: jr          $ra
    // 0x80801D9C: nop

    return;
    // 0x80801D9C: nop

;}
RECOMP_FUNC void func_80800554_chappearfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800554: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800558: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080055C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800560: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800564: jal         0x80100094
    // 0x80800568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080056C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80800570: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80800574: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800578: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8080057C: beql        $at, $zero, L_8080068C
    if (ctx->r1 == 0) {
        // 0x80800580: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080068C;
    }
    goto skip_0;
    // 0x80800580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800584: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80800588: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080058C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1188, 0X954) << 16);
    // 0x80800590: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800594: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80800598: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8080059C: addu        $s0, $v0, $t9
    ctx->r16 = ADD32(ctx->r2, ctx->r25);
    // 0x808005A0: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x808005A4: jal         0x800DC178
    // 0x808005A8: lwc1        $f14, 0x954($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1188, 0X954));
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808005A8: lwc1        $f14, 0x954($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1188, 0X954));
    after_1:
    // 0x808005AC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808005B0: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    // 0x808005B4: addiu       $a1, $zero, 0x15E
    ctx->r5 = ADD32(0, 0X15E);
    // 0x808005B8: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x808005BC: jal         0x800DC128
    // 0x808005C0: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x808005C0: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    after_2:
    // 0x808005C4: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x808005C8: lh          $t3, 0xA($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XA);
    // 0x808005CC: lh          $t2, 0x8($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X8);
    // 0x808005D0: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x808005D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005D8: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x808005DC: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x808005E0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808005E4: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x808005E8: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x808005EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808005F0: jal         0x800F10B4
    // 0x808005F4: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808005F4: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_3:
    // 0x808005F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1188, 0X958) << 16);
    // 0x808005FC: lwc1        $f12, 0x958($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1188, 0X958));
    // 0x80800600: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1188, 0X95C) << 16);
    // 0x80800604: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800608: jal         0x800DC178
    // 0x8080060C: lwc1        $f14, 0x95C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1188, 0X95C));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x8080060C: lwc1        $f14, 0x95C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1188, 0X95C));
    after_4:
    // 0x80800610: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800614: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800618: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080061C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800620: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800624: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80800628: nop

    // 0x8080062C: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x80800630: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x80800634: jal         0x800DC298
    // 0x80800638: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    func_800DC298(rdram, ctx);
        goto after_5;
    // 0x80800638: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    after_5:
    // 0x8080063C: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80800640: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1188, 0X960) << 16);
    // 0x80800644: lwc1        $f12, 0x960($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1188, 0X960));
    // 0x80800648: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1188, 0X964) << 16);
    // 0x8080064C: jal         0x800DC178
    // 0x80800650: lwc1        $f14, 0x964($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1188, 0X964));
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800650: lwc1        $f14, 0x964($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1188, 0X964));
    after_6:
    // 0x80800654: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800658: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080065C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800660: jal         0x800DC178
    // 0x80800664: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800664: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    after_7:
    // 0x80800668: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8080066C: addiu       $a0, $zero, -0xC8
    ctx->r4 = ADD32(0, -0XC8);
    // 0x80800670: jal         0x800DC128
    // 0x80800674: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_800DC128(rdram, ctx);
        goto after_8;
    // 0x80800674: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_8:
    // 0x80800678: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x8080067C: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x80800680: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80800684: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
    // 0x80800688: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080068C:
    // 0x8080068C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800690: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800694: jr          $ra
    // 0x80800698: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800698: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800C00_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C00: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800C04: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80800C08: lbu         $t0, 0x762C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X762C);
    // 0x80800C0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C18: jal         0x800F54E4
    // 0x80800C1C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800C1C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_0:
    // 0x80800C20: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(780, 0X10B0) << 16);
    // 0x80800C24: lw          $t6, 0x10B0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(780, 0X10B0));
    // 0x80800C28: addiu       $a3, $zero, -0x2
    ctx->r7 = ADD32(0, -0X2);
    // 0x80800C2C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80800C30: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800C34: beq         $a3, $t6, L_80800C80
    if (ctx->r7 == ctx->r14) {
        // 0x80800C38: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800C80;
    }
    // 0x80800C38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C3C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(780, 0X10B0) << 16);
    // 0x80800C40: addiu       $a1, $t7, 0x10B0
    ctx->r5 = ADD32(ctx->r15, (int16_t)RELOC_LO16(780, 0X10B0));
    // 0x80800C44: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80800C48: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80800C4C:
    // 0x80800C4C: bnel        $t1, $v1, L_80800C70
    if (ctx->r9 != ctx->r3) {
        // 0x80800C50: lw          $v1, 0xC($a1)
        ctx->r3 = MEM_W(ctx->r5, 0XC);
            goto L_80800C70;
    }
    goto skip_0;
    // 0x80800C50: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
    skip_0:
    // 0x80800C54: lbu         $t8, 0x4($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X4);
    // 0x80800C58: beql        $t0, $t8, L_80800C84
    if (ctx->r8 == ctx->r24) {
        // 0x80800C5C: sll         $t3, $a2, 2
        ctx->r11 = S32(ctx->r6 << 2);
            goto L_80800C84;
    }
    goto skip_1;
    // 0x80800C5C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    skip_1:
    // 0x80800C60: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80800C64: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80800C68: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x80800C6C: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
L_80800C70:
    // 0x80800C70: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80800C74: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80800C78: bne         $a3, $v1, L_80800C4C
    if (ctx->r7 != ctx->r3) {
        // 0x80800C7C: nop
    
            goto L_80800C4C;
    }
    // 0x80800C7C: nop

L_80800C80:
    // 0x80800C80: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
L_80800C84:
    // 0x80800C84: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x80800C88: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(780, 0X10B0) << 16);
    // 0x80800C8C: addiu       $t4, $t4, 0x10B0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(780, 0X10B0));
    // 0x80800C90: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80800C94: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x80800C98: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA0: jal         0x80089F48
    // 0x80800CA4: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800CA4: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800CA8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800CAC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80800CB0: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80800CB4: addiu       $a3, $zero, -0x2
    ctx->r7 = ADD32(0, -0X2);
    // 0x80800CB8: sw          $a2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r6;
    // 0x80800CBC: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
    // 0x80800CC0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80800CC4: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80800CC8: beq         $a3, $v1, L_80800CEC
    if (ctx->r7 == ctx->r3) {
        // 0x80800CCC: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80800CEC;
    }
    // 0x80800CCC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80800CD0:
    // 0x80800CD0: beql        $t1, $v1, L_80800CF0
    if (ctx->r9 == ctx->r3) {
        // 0x80800CD4: lw          $t5, 0x28($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X28);
            goto L_80800CF0;
    }
    goto skip_2;
    // 0x80800CD4: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    skip_2:
    // 0x80800CD8: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
    // 0x80800CDC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80800CE0: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80800CE4: bne         $a3, $v1, L_80800CD0
    if (ctx->r7 != ctx->r3) {
        // 0x80800CE8: nop
    
            goto L_80800CD0;
    }
    // 0x80800CE8: nop

L_80800CEC:
    // 0x80800CEC: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
L_80800CF0:
    // 0x80800CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CF8: subu        $t6, $a2, $t5
    ctx->r14 = SUB32(ctx->r6, ctx->r13);
    // 0x80800CFC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800D00: jal         0x80800418
    // 0x80800D04: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    func_80800418_chwarppad(rdram, ctx);
        goto after_2;
    // 0x80800D04: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    after_2:
    // 0x80800D08: jal         0x80800380
    // 0x80800D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800380_chwarppad(rdram, ctx);
        goto after_3;
    // 0x80800D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800D10: beq         $v0, $zero, L_80800D20
    if (ctx->r2 == 0) {
        // 0x80800D14: addiu       $a1, $zero, 0x87
        ctx->r5 = ADD32(0, 0X87);
            goto L_80800D20;
    }
    // 0x80800D14: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    // 0x80800D18: b           L_80800D20
    // 0x80800D1C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
        goto L_80800D20;
    // 0x80800D1C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80800D20:
    // 0x80800D20: jal         0x80089CD0
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800D28: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80800D2C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80800D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D34: beql        $t1, $a1, L_80800D48
    if (ctx->r9 == ctx->r5) {
        // 0x80800D38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D48;
    }
    goto skip_3;
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800D3C: jal         0x80089F50
    // 0x80800D40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddiesect_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800D40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80800D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D48:
    // 0x80800D48: jal         0x8010A828
    // 0x80800D4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A828(rdram, ctx);
        goto after_6;
    // 0x80800D4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800D50: jal         0x800DA298
    // 0x80800D54: addiu       $a0, $zero, 0x9FE
    ctx->r4 = ADD32(0, 0X9FE);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800D54: addiu       $a0, $zero, 0x9FE
    ctx->r4 = ADD32(0, 0X9FE);
    after_7:
    // 0x80800D58: beql        $v0, $zero, L_80800E00
    if (ctx->r2 == 0) {
        // 0x80800D5C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E00;
    }
    goto skip_4;
    // 0x80800D5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800D60: jal         0x800EA090
    // 0x80800D64: nop

    func_800EA090(rdram, ctx);
        goto after_8;
    // 0x80800D64: nop

    after_8:
    // 0x80800D68: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
    // 0x80800D6C: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x80800D70: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(780, 0XE5C) << 16);
    // 0x80800D74: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x80800D78: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80800D7C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800D80: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80800D84: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80800D88: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800D8C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80800D90: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x80800D94: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80800D98: lbu         $t6, 0xE5C($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(780, 0XE5C));
    // 0x80800D9C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800DA0: bnel        $v0, $t6, L_80800E00
    if (ctx->r2 != ctx->r14) {
        // 0x80800DA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E00;
    }
    goto skip_5;
    // 0x80800DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80800DA8: jal         0x800EE7F8
    // 0x80800DAC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80800DAC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80800DB0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800DB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DB8: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800DBC: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800DC0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800DC4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800DC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800DCC: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800DD0: jal         0x800F608C
    // 0x80800DD4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    func_800F608C(rdram, ctx);
        goto after_10;
    // 0x80800DD4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x80800DD8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800DDC: jal         0x800F8294
    // 0x80800DE0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800F8294(rdram, ctx);
        goto after_11;
    // 0x80800DE0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_11:
    // 0x80800DE4: jal         0x800F497C
    // 0x80800DE8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800F497C(rdram, ctx);
        goto after_12;
    // 0x80800DE8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_12:
    // 0x80800DEC: jal         0x800C78CC
    // 0x80800DF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C78CC(rdram, ctx);
        goto after_13;
    // 0x80800DF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80800DF4: jal         0x800DA524
    // 0x80800DF8: addiu       $a0, $zero, 0x9FE
    ctx->r4 = ADD32(0, 0X9FE);
    func_800DA524(rdram, ctx);
        goto after_14;
    // 0x80800DF8: addiu       $a0, $zero, 0x9FE
    ctx->r4 = ADD32(0, 0X9FE);
    after_14:
    // 0x80800DFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E00:
    // 0x80800E00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E04: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800E08: jr          $ra
    // 0x80800E0C: nop

    return;
    // 0x80800E0C: nop

;}
RECOMP_FUNC void func_808002D0_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808002D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808002DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002E0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x808002E4: jal         0x8009C128
    // 0x808002E8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808002E8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x808002EC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808002F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002F4: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002FC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800300: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800304: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800308: jal         0x8009FBB0
    // 0x8080030C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    func_8009FBB0(rdram, ctx);
        goto after_1;
    // 0x8080030C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800310: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80800314: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80800318: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8080031C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800320: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80800324: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800328: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080032C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800330: addiu       $a1, $zero, -0x1E
    ctx->r5 = ADD32(0, -0X1E);
    // 0x80800334: addiu       $a2, $zero, -0x1E
    ctx->r6 = ADD32(0, -0X1E);
    // 0x80800338: jal         0x800BA930
    // 0x8080033C: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    func_800BA930(rdram, ctx);
        goto after_2;
    // 0x8080033C: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    after_2:
    // 0x80800340: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800344: jal         0x800BA22C
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080034C: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800350: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800354: nop

    // 0x80800358: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8080035C: nop

    // 0x80800360: bc1f        L_808003A4
    if (!c1cs) {
        // 0x80800364: nop
    
            goto L_808003A4;
    }
    // 0x80800364: nop

    // 0x80800368: jal         0x800F2100
    // 0x8080036C: nop

    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x8080036C: nop

    after_4:
    // 0x80800370: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(431, 0X970) << 16);
    // 0x80800374: lwc1        $f16, 0x970($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(431, 0X970));
    // 0x80800378: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080037C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800380: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800384: jal         0x800F0E00
    // 0x80800388: nop

    func_800F0E00(rdram, ctx);
        goto after_5;
    // 0x80800388: nop

    after_5:
    // 0x8080038C: lwc1        $f18, 0x16C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80800398: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    // 0x8080039C: jal         0x8009BA58
    // 0x808003A0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x808003A0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_6:
L_808003A4:
    // 0x808003A4: jal         0x8008E078
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_7;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808003AC: beq         $v0, $zero, L_808003B8
    if (ctx->r2 == 0) {
        // 0x808003B0: addiu       $t9, $zero, 0x11B
        ctx->r25 = ADD32(0, 0X11B);
            goto L_808003B8;
    }
    // 0x808003B0: addiu       $t9, $zero, 0x11B
    ctx->r25 = ADD32(0, 0X11B);
    // 0x808003B4: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_808003B8:
    // 0x808003B8: jal         0x8008E35C
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_8;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808003C0: bne         $v0, $zero, L_808003CC
    if (ctx->r2 != 0) {
        // 0x808003C4: addiu       $t0, $zero, 0x11A
        ctx->r8 = ADD32(0, 0X11A);
            goto L_808003CC;
    }
    // 0x808003C4: addiu       $t0, $zero, 0x11A
    ctx->r8 = ADD32(0, 0X11A);
    // 0x808003C8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_808003CC:
    // 0x808003CC: jal         0x8009BB50
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_9;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808003D8: addiu       $t1, $zero, 0x11B
    ctx->r9 = ADD32(0, 0X11B);
    // 0x808003DC: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x808003E0: nop

    // 0x808003E4: bc1f        L_808003F0
    if (!c1cs) {
        // 0x808003E8: nop
    
            goto L_808003F0;
    }
    // 0x808003E8: nop

    // 0x808003EC: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_808003F0:
    // 0x808003F0: jal         0x80084138
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsvan_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x8009E5C8
    // 0x80800400: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x80800400: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x80800404: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800408: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080040C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800410: jr          $ra
    // 0x80800414: nop

    return;
    // 0x80800414: nop

;}
RECOMP_FUNC void _bahitspline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D60: syscall     135
    recomp_syscall_handler(rdram, ctx, 0x80084D60);
    return;
    // 0x80084D64: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bafly_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800980: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800988: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080098C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800990: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800994: jal         0x8008CABC
    // 0x80800998: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800998: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x8080099C: jal         0x8008B324
    // 0x808009A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_1;
    // 0x808009A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808009A4: beq         $v0, $zero, L_808009B0
    if (ctx->r2 == 0) {
        // 0x808009A8: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_808009B0;
    }
    // 0x808009A8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808009AC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808009B0:
    // 0x808009B0: jal         0x8008E078
    // 0x808009B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_isStable(rdram, ctx);
        goto after_2;
    // 0x808009B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808009B8: beq         $v0, $zero, L_808009C4
    if (ctx->r2 == 0) {
        // 0x808009BC: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_808009C4;
    }
    // 0x808009BC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808009C0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_808009C4:
    // 0x808009C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009C8: jal         0x8009E5C8
    // 0x808009CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x808009CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808009D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009D8: jr          $ra
    // 0x808009DC: nop

    return;
    // 0x808009DC: nop

;}
RECOMP_FUNC void func_800CB3FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB3FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB400: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CB404: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CB408: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800CB40C: addiu       $t8, $t8, -0x5490
    ctx->r24 = ADD32(ctx->r24, -0X5490);
    // 0x800CB410: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CB414: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800CB418: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800CB41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB420: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800CB424: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800CB428: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CB42C: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    // 0x800CB430: jal         0x800EE7F8
    // 0x800CB434: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800CB434: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800CB438: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB43C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800CB440: lh          $t9, 0x2C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2C);
    // 0x800CB444: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800CB448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB44C: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800CB450: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB454: jr          $ra
    // 0x800CB458: nop

    return;
    // 0x800CB458: nop

;}
RECOMP_FUNC void _bacough_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084618: syscall     117
    recomp_syscall_handler(rdram, ctx, 0x80084618);
    return;
    // 0x8008461C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800FA660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA660: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FA664: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FA668: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FA66C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800FA670: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800FA674: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FA678: addiu       $s1, $s1, 0x3DC0
    ctx->r17 = ADD32(ctx->r17, 0X3DC0);
    // 0x800FA67C: addiu       $s0, $s0, 0x3880
    ctx->r16 = ADD32(ctx->r16, 0X3880);
    // 0x800FA680: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
L_800FA684:
    // 0x800FA684: beql        $a0, $zero, L_800FA69C
    if (ctx->r4 == 0) {
        // 0x800FA688: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800FA69C;
    }
    goto skip_0;
    // 0x800FA688: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_0:
    // 0x800FA68C: jal         0x8008A588
    // 0x800FA690: nop

    _scinfobar_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800FA690: nop

    after_0:
    // 0x800FA694: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800FA698: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_800FA69C:
    // 0x800FA69C: bnel        $s0, $s1, L_800FA684
    if (ctx->r16 != ctx->r17) {
        // 0x800FA6A0: lw          $a0, 0x18($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X18);
            goto L_800FA684;
    }
    goto skip_1;
    // 0x800FA6A0: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    skip_1:
    // 0x800FA6A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FA6A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FA6AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FA6B0: jr          $ra
    // 0x800FA6B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FA6B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _bswasher_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843F0: syscall     109
    recomp_syscall_handler(rdram, ctx, 0x800843F0);
    return;
    // 0x800843F4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void chfantasytrashcanbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2352, 0X240) << 16);
    // 0x808001A0: jr          $ra
    // 0x808001A4: addiu       $v0, $v0, 0x240
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2352, 0X240));
    return;
    // 0x808001A4: addiu       $v0, $v0, 0x240
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2352, 0X240));
;}
RECOMP_FUNC void func_808009FC_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A04: jal         0x80800114
    // 0x80800A08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800114_bsmumswim(rdram, ctx);
        goto after_0;
    // 0x80800A08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A0C: jal         0x800839C8
    // 0x80800A10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800A10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A1C: jr          $ra
    // 0x80800A20: nop

    return;
    // 0x80800A20: nop

;}
RECOMP_FUNC void func_800F5B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5B0C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5B14: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5B1C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5B20: jal         0x8009CC68
    // 0x800F5B24: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009CC68(rdram, ctx);
        goto after_0;
    // 0x800F5B24: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5B30: jr          $ra
    // 0x800F5B34: nop

    return;
    // 0x800F5B34: nop

;}
RECOMP_FUNC void func_800C8070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8070: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C8074: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C8078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C807C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8080: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C8084: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800C8088: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C808C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x800C8090: jal         0x800C7FD4
    // 0x800C8094: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    func_800C7FD4(rdram, ctx);
        goto after_0;
    // 0x800C8094: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800C8098: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C809C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C80A0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800C80A4: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C80A8: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x800C80AC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800C80B0: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800C80B4: bc1fl       L_800C80D8
    if (!c1cs) {
        // 0x800C80B8: c.lt.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
            goto L_800C80D8;
    }
    goto skip_0;
    // 0x800C80B8: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    skip_0:
    // 0x800C80BC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800C80C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C80C4: bc1fl       L_800C80FC
    if (!c1cs) {
        // 0x800C80C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C80FC;
    }
    goto skip_1;
    // 0x800C80C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800C80CC: b           L_800C80F8
    // 0x800C80D0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
        goto L_800C80F8;
    // 0x800C80D0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800C80D4: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
L_800C80D8:
    // 0x800C80D8: nop

    // 0x800C80DC: bc1fl       L_800C80FC
    if (!c1cs) {
        // 0x800C80E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C80FC;
    }
    goto skip_2;
    // 0x800C80E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800C80E4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800C80E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C80EC: bc1fl       L_800C80FC
    if (!c1cs) {
        // 0x800C80F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C80FC;
    }
    goto skip_3;
    // 0x800C80F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800C80F4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
L_800C80F8:
    // 0x800C80F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C80FC:
    // 0x800C80FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8100: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800C8104: jr          $ra
    // 0x800C8108: nop

    return;
    // 0x800C8108: nop

;}
RECOMP_FUNC void _chbilldrillboulder_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F90: syscall     485
    recomp_syscall_handler(rdram, ctx, 0x80086F90);
    return;
    // 0x80086F94: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080206C_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080206C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802074: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80802078: jal         0x80100094
    // 0x8080207C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080207C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802080: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80802084: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80802088: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8080208C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80802090: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_80802094:
    // 0x80802094: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802098: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8080209C: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
L_808020A0:
    // 0x808020A0: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x808020A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808020A8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x808020AC: beq         $t6, $zero, L_808020B8
    if (ctx->r14 == 0) {
        // 0x808020B0: addu        $v1, $a1, $a0
        ctx->r3 = ADD32(ctx->r5, ctx->r4);
            goto L_808020B8;
    }
    // 0x808020B0: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x808020B4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_808020B8:
    // 0x808020B8: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x808020BC: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
    // 0x808020C0: beql        $t7, $zero, L_808020D0
    if (ctx->r15 == 0) {
        // 0x808020C4: lbu         $t8, 0x1($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X1);
            goto L_808020D0;
    }
    goto skip_0;
    // 0x808020C4: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    skip_0:
    // 0x808020C8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x808020CC: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
L_808020D0:
    // 0x808020D0: beql        $t8, $zero, L_808020E0
    if (ctx->r24 == 0) {
        // 0x808020D4: lbu         $t9, 0x2($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X2);
            goto L_808020E0;
    }
    goto skip_1;
    // 0x808020D4: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
    skip_1:
    // 0x808020D8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x808020DC: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
L_808020E0:
    // 0x808020E0: beql        $t9, $zero, L_808020F0
    if (ctx->r25 == 0) {
        // 0x808020E4: lbu         $t5, 0x3($v1)
        ctx->r13 = MEM_BU(ctx->r3, 0X3);
            goto L_808020F0;
    }
    goto skip_2;
    // 0x808020E4: lbu         $t5, 0x3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3);
    skip_2:
    // 0x808020E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x808020EC: lbu         $t5, 0x3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3);
L_808020F0:
    // 0x808020F0: beq         $t5, $zero, L_808020FC
    if (ctx->r13 == 0) {
        // 0x808020F4: nop
    
            goto L_808020FC;
    }
    // 0x808020F4: nop

    // 0x808020F8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_808020FC:
    // 0x808020FC: bne         $a3, $t1, L_808020A0
    if (ctx->r7 != ctx->r9) {
        // 0x80802100: addiu       $t0, $t0, 0x5
        ctx->r8 = ADD32(ctx->r8, 0X5);
            goto L_808020A0;
    }
    // 0x80802100: addiu       $t0, $t0, 0x5
    ctx->r8 = ADD32(ctx->r8, 0X5);
    // 0x80802104: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80802108: bne         $t2, $t4, L_80802094
    if (ctx->r10 != ctx->r12) {
        // 0x8080210C: addiu       $t3, $t3, 0x14
        ctx->r11 = ADD32(ctx->r11, 0X14);
            goto L_80802094;
    }
    // 0x8080210C: addiu       $t3, $t3, 0x14
    ctx->r11 = ADD32(ctx->r11, 0X14);
    // 0x80802110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802114: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802118: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8080211C: jr          $ra
    // 0x80802120: nop

    return;
    // 0x80802120: nop

;}
RECOMP_FUNC void fxegg_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800284: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800288: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080028C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800290: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800294: jal         0x80088970
    // 0x80800298: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    _fxdlsmoke_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800298: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080029C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808002A0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808002A4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808002A8: beq         $a1, $zero, L_80800328
    if (ctx->r5 == 0) {
        // 0x808002AC: lui         $a2, 0x3E19
        ctx->r6 = S32(0X3E19 << 16);
            goto L_80800328;
    }
    // 0x808002AC: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x808002B0: jal         0x800EFA20
    // 0x808002B4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x808002B4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_1:
    // 0x808002B8: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808002BC: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808002C0: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808002C4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808002C8: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808002CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808002D0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808002D4: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x808002D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002DC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808002E0: add.s       $f12, $f18, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x808002E4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808002E8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x808002EC: add.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x808002F0: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808002F4: sll         $t3, $a3, 16
    ctx->r11 = S32(ctx->r7 << 16);
    // 0x808002F8: trunc.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x808002FC: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80800300: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800304: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800308: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8080030C: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x80800310: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80800314: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80800318: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8080031C: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80800320: jal         0x800BA930
    // 0x80800324: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_800BA930(rdram, ctx);
        goto after_2;
    // 0x80800324: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_2:
L_80800328:
    // 0x80800328: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8080032C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2834, 0X614) << 16);
    // 0x80800330: addiu       $t7, $t7, 0x614
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2834, 0X614));
    // 0x80800334: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800338: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080033C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80800340: jal         0x800BABB8
    // 0x80800344: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80800344: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_3:
    // 0x80800348: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080034C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80800350: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800354: jr          $ra
    // 0x80800358: nop

    return;
    // 0x80800358: nop

;}
RECOMP_FUNC void func_801051C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801051C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801051CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801051D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801051D4: jal         0x80104544
    // 0x801051D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80104544(rdram, ctx);
        goto after_0;
    // 0x801051D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801051DC: bne         $v0, $zero, L_80105208
    if (ctx->r2 != 0) {
        // 0x801051E0: nop
    
            goto L_80105208;
    }
    // 0x801051E0: nop

    // 0x801051E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801051E8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801051EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801051F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801051F4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801051F8: jal         0x800EFA4C
    // 0x801051FC: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x801051FC: nop

    after_1:
    // 0x80105200: b           L_80105220
    // 0x80105204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80105220;
    // 0x80105204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80105208:
    // 0x80105208: jal         0x801043D8
    // 0x8010520C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_801043D8(rdram, ctx);
        goto after_2;
    // 0x8010520C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80105210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80105214: jal         0x801048E4
    // 0x80105218: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_801048E4(rdram, ctx);
        goto after_3;
    // 0x80105218: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8010521C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80105220:
    // 0x80105220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105228: jr          $ra
    // 0x8010522C: nop

    return;
    // 0x8010522C: nop

;}
RECOMP_FUNC void func_800C6920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6920: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C6924: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C6928: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C692C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C6930: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x800C6934: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C6938: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800C693C: jal         0x800C696C
    // 0x800C6940: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800C696C(rdram, ctx);
        goto after_0;
    // 0x800C6940: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800C6944: bne         $v0, $zero, L_800C6958
    if (ctx->r2 != 0) {
        // 0x800C6948: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_800C6958;
    }
    // 0x800C6948: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800C694C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C6950: nop

    // 0x800C6954: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
L_800C6958:
    // 0x800C6958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C695C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C6960: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C6964: jr          $ra
    // 0x800C6968: nop

    return;
    // 0x800C6968: nop

;}
RECOMP_FUNC void func_80800BE8_chstonedartgunhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BEC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BF4: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80800BF8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800BFC: jal         0x800EE7F8
    // 0x80800C00: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800C00: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80800C04: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800C08: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800C0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C10: nop

    // 0x80800C14: swc1        $f4, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f4.u32l;
    // 0x80800C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C20: jr          $ra
    // 0x80800C24: nop

    return;
    // 0x80800C24: nop

;}
RECOMP_FUNC void func_800C9A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9A38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9A3C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C9A40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C9A44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9A48: addiu       $a3, $a0, 0xC
    ctx->r7 = ADD32(ctx->r4, 0XC);
    // 0x800C9A4C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800C9A50: jal         0x800EEEA8
    // 0x800C9A54: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800EEEA8(rdram, ctx);
        goto after_0;
    // 0x800C9A54: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C9A58: beq         $v0, $zero, L_800C9A84
    if (ctx->r2 == 0) {
        // 0x800C9A5C: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_800C9A84;
    }
    // 0x800C9A5C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800C9A60: lh          $t6, 0x18($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18);
    // 0x800C9A64: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800C9A68: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800C9A6C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x800C9A70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C9A74: jal         0x8008A208
    // 0x800C9A78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x800C9A78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x800C9A7C: b           L_800C9AA0
    // 0x800C9A80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C9AA0;
    // 0x800C9A80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C9A84:
    // 0x800C9A84: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x800C9A88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800C9A8C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800C9A90: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x800C9A94: jal         0x8008A208
    // 0x800C9A98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x800C9A98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x800C9A9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C9AA0:
    // 0x800C9AA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C9AA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C9AA8: jr          $ra
    // 0x800C9AAC: nop

    return;
    // 0x800C9AAC: nop

;}
RECOMP_FUNC void func_80801930_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801930: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801934: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80801938: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080193C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801940: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801944: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801948: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080194C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80801950: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80801954: lui         $s3, 0x1
    ctx->r19 = S32(0X1 << 16);
    // 0x80801958: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080195C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80801960: ori         $s3, $s3, 0x86A0
    ctx->r19 = ctx->r19 | 0X86A0;
    // 0x80801964: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80801968: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8080196C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80801970: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80801974: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80801978:
    // 0x80801978: jal         0x8008A800
    // 0x8080197C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suquiz_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x8080197C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801980: bne         $v0, $zero, L_808019A4
    if (ctx->r2 != 0) {
        // 0x80801984: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_808019A4;
    }
    // 0x80801984: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80801988: jal         0x80801784
    // 0x8080198C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801784_chquiz(rdram, ctx);
        goto after_1;
    // 0x8080198C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80801990: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80801994: beql        $at, $zero, L_808019A8
    if (ctx->r1 == 0) {
        // 0x80801998: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808019A8;
    }
    goto skip_0;
    // 0x80801998: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8080199C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808019A0: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
L_808019A4:
    // 0x808019A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808019A8:
    // 0x808019A8: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x808019AC: bne         $at, $zero, L_80801978
    if (ctx->r1 != 0) {
        // 0x808019B0: nop
    
            goto L_80801978;
    }
    // 0x808019B0: nop

    // 0x808019B4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x808019B8: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x808019BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808019C0: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x808019C4: beql        $at, $zero, L_80801A30
    if (ctx->r1 == 0) {
        // 0x808019C8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80801A30;
    }
    goto skip_1;
    // 0x808019C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
L_808019CC:
    // 0x808019CC: jal         0x8008A800
    // 0x808019D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suquiz_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808019D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808019D4: bne         $v0, $zero, L_80801A20
    if (ctx->r2 != 0) {
        // 0x808019D8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80801A20;
    }
    // 0x808019D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808019DC: jal         0x80801784
    // 0x808019E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801784_chquiz(rdram, ctx);
        goto after_3;
    // 0x808019E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x808019E4: bnel        $v0, $s3, L_80801A24
    if (ctx->r2 != ctx->r19) {
        // 0x808019E8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801A24;
    }
    goto skip_2;
    // 0x808019E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x808019EC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x808019F0: beql        $s0, $t6, L_80801A24
    if (ctx->r16 == ctx->r14) {
        // 0x808019F4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801A24;
    }
    goto skip_3;
    // 0x808019F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x808019F8: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x808019FC: beql        $s0, $t7, L_80801A24
    if (ctx->r16 == ctx->r15) {
        // 0x80801A00: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801A24;
    }
    goto skip_4;
    // 0x80801A00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x80801A04: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x80801A08: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80801A0C: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x80801A10: beql        $s0, $t8, L_80801A24
    if (ctx->r16 == ctx->r24) {
        // 0x80801A14: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801A24;
    }
    goto skip_5;
    // 0x80801A14: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_5:
    // 0x80801A18: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x80801A1C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80801A20:
    // 0x80801A20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801A24:
    // 0x80801A24: bne         $s0, $s5, L_808019CC
    if (ctx->r16 != ctx->r21) {
        // 0x80801A28: nop
    
            goto L_808019CC;
    }
    // 0x80801A28: nop

    // 0x80801A2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801A30:
    // 0x80801A30: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80801A34: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801A3C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801A40: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801A44: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80801A48: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80801A4C: jr          $ra
    // 0x80801A50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801A50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800EBB5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBB5C: addiu       $t6, $zero, 0x6B7
    ctx->r14 = ADD32(0, 0X6B7);
    // 0x800EBB60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EBB64: jr          $ra
    // 0x800EBB68: sw          $t6, 0x546C($at)
    MEM_W(0X546C, ctx->r1) = ctx->r14;
    return;
    // 0x800EBB68: sw          $t6, 0x546C($at)
    MEM_W(0X546C, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void _sumumbofx_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089890: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089890);
    return;
    // 0x80089894: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800E119C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E119C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E11A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E11A4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800E11A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E11AC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800E11B0: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x800E11B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E11B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800E11BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800E11C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800E11C4: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800E11C8: jal         0x800EFA4C
    // 0x800E11CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800E11CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800E11D0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800E11D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E11D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E11DC: jal         0x800EF8BC
    // 0x800E11E0: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    func_800EF8BC(rdram, ctx);
        goto after_1;
    // 0x800E11E0: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x800E11E4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800E11E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E11EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E11F0: jal         0x800EF934
    // 0x800E11F4: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    func_800EF934(rdram, ctx);
        goto after_2;
    // 0x800E11F4: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    after_2:
    // 0x800E11F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800E11FC: jal         0x800EF04C
    // 0x800E1200: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x800E1200: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800E1204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1208: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E120C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800E1210: jr          $ra
    // 0x800E1214: nop

    return;
    // 0x800E1214: nop

;}
RECOMP_FUNC void func_800A2C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2C84: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A2C88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2C8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A2C90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A2C94: jal         0x8009C128
    // 0x800A2C98: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800A2C98: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800A2C9C: lw          $t6, 0x124($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X124);
    // 0x800A2CA0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800A2CA4: jal         0x80088A10
    // 0x800A2CA8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _fxstep_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x800A2CA8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x800A2CAC: jal         0x80096628
    // 0x800A2CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096628(rdram, ctx);
        goto after_2;
    // 0x800A2CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A2CB4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A2CB8: jal         0x800964DC
    // 0x800A2CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800964DC(rdram, ctx);
        goto after_3;
    // 0x800A2CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800A2CC0: lw          $t7, 0x124($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X124);
    // 0x800A2CC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800A2CC8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A2CCC: jal         0x80088A08
    // 0x800A2CD0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _fxstep_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x800A2CD0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_4:
    // 0x800A2CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2CD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A2CDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800A2CE0: jr          $ra
    // 0x800A2CE4: nop

    return;
    // 0x800A2CE4: nop

;}
RECOMP_FUNC void _bsdronejump_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083110: syscall     44
    recomp_syscall_handler(rdram, ctx, 0x80083110);
    return;
    // 0x80083114: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void suexpression_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080004C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800050: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80800054: jal         0x80800CF4
    // 0x80800058: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800CF4_suexpression(rdram, ctx);
        goto after_0;
    // 0x80800058: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080005C: bne         $v0, $zero, L_8080006C
    if (ctx->r2 != 0) {
        // 0x80800060: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080006C;
    }
    // 0x80800060: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800064: b           L_80800070
    // 0x80800068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800070;
    // 0x80800068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080006C:
    // 0x8080006C: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
L_80800070:
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void chmonsterinterior_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1320, 0X1FA0) << 16);
    // 0x80800034: jr          $ra
    // 0x80800038: addiu       $v0, $v0, 0x1FA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1320, 0X1FA0));
    return;
    // 0x80800038: addiu       $v0, $v0, 0x1FA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1320, 0X1FA0));
;}
RECOMP_FUNC void cosectionstor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800004: sw          $zero, 0x7198($at)
    MEM_W(0X7198, ctx->r1) = 0;
    // 0x80800008: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8080000C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80800010: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800014: addiu       $v0, $v0, 0x75C0
    ctx->r2 = ADD32(ctx->r2, 0X75C0);
    // 0x80800018: addiu       $v1, $v1, 0x71A0
    ctx->r3 = ADD32(ctx->r3, 0X71A0);
    // 0x8080001C: sw          $zero, 0x719C($at)
    MEM_W(0X719C, ctx->r1) = 0;
L_80800020:
    // 0x80800020: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80800024: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x80800028: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x8080002C: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x80800030: bne         $v1, $v0, L_80800020
    if (ctx->r3 != ctx->r2) {
        // 0x80800034: sw          $zero, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = 0;
            goto L_80800020;
    }
    // 0x80800034: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void bswasher_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800AF8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(443, 0X1E30) << 16);
    // 0x80800AFC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B00: jr          $ra
    // 0x80800B04: lw          $v0, 0x1E30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E30));
    return;
    // 0x80800B04: lw          $v0, 0x1E30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E30));
;}
RECOMP_FUNC void func_800B9108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9108: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800B910C: addiu       $a3, $a3, 0x7128
    ctx->r7 = ADD32(ctx->r7, 0X7128);
    // 0x800B9110: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x800B9114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B9118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B911C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B9120: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B9124: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B9128: beq         $at, $zero, L_800B9160
    if (ctx->r1 == 0) {
        // 0x800B912C: sw          $t7, 0x4($a3)
        MEM_W(0X4, ctx->r7) = ctx->r15;
            goto L_800B9160;
    }
    // 0x800B912C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800B9130: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x800B9134: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9138: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800B913C: lw          $v0, 0x1C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X1C);
    // 0x800B9140: mflo        $t1
    ctx->r9 = lo;
    // 0x800B9144: addu        $a0, $v0, $t1
    ctx->r4 = ADD32(ctx->r2, ctx->r9);
    // 0x800B9148: nop

    // 0x800B914C: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9150: mflo        $t2
    ctx->r10 = lo;
    // 0x800B9154: addu        $a1, $v0, $t2
    ctx->r5 = ADD32(ctx->r2, ctx->r10);
    // 0x800B9158: jal         0x8001BBC8
    // 0x800B915C: nop

    aligned4_memcpy(rdram, ctx);
        goto after_0;
    // 0x800B915C: nop

    after_0:
L_800B9160:
    // 0x800B9160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B9168: jr          $ra
    // 0x800B916C: nop

    return;
    // 0x800B916C: nop

;}
RECOMP_FUNC void func_80800000_chscreenadjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x800D8FF8
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800018: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080001C: jal         0x80016068
    // 0x80800020: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80016068(rdram, ctx);
        goto after_1;
    // 0x80800020: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80800024: jal         0x800F2100
    // 0x80800028: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x80800028: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8080002C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(788, 0X420) << 16);
    // 0x80800030: lwc1        $f4, 0x420($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(788, 0X420));
    // 0x80800034: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800038: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080003C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800040: nop

    // 0x80800044: bc1fl       L_8080006C
    if (!c1cs) {
        // 0x80800048: lui         $at, 0xC200
        ctx->r1 = S32(0XC200 << 16);
            goto L_8080006C;
    }
    goto skip_0;
    // 0x80800048: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    skip_0:
    // 0x8080004C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800050: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80800054: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800058: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8080005C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800060: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80800064: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x80800068: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
L_8080006C:
    // 0x8080006C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800070: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800074: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80800078: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8080007C: nop

    // 0x80800080: bc1fl       L_80800094
    if (!c1cs) {
        // 0x80800084: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80800094;
    }
    goto skip_1;
    // 0x80800084: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x80800088: b           L_808000AC
    // 0x8080008C: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
        goto L_808000AC;
    // 0x8080008C: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
    // 0x80800090: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80800094:
    // 0x80800094: nop

    // 0x80800098: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8080009C: nop

    // 0x808000A0: bc1f        L_808000AC
    if (!c1cs) {
        // 0x808000A4: nop
    
            goto L_808000AC;
    }
    // 0x808000A4: nop

    // 0x808000A8: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
L_808000AC:
    // 0x808000AC: jal         0x800F2100
    // 0x808000B0: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x808000B0: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(788, 0X424) << 16);
    // 0x808000B8: lwc1        $f8, 0x424($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(788, 0X424));
    // 0x808000BC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808000C0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808000C4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808000C8: nop

    // 0x808000CC: bc1fl       L_808000F4
    if (!c1cs) {
        // 0x808000D0: lui         $at, 0xC220
        ctx->r1 = S32(0XC220 << 16);
            goto L_808000F4;
    }
    goto skip_2;
    // 0x808000D0: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    skip_2:
    // 0x808000D4: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808000D8: lui         $at, 0xC280
    ctx->r1 = S32(0XC280 << 16);
    // 0x808000DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808000E0: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808000E4: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x808000E8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x808000EC: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x808000F0: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
L_808000F4:
    // 0x808000F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808000F8: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808000FC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80800100: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800104: nop

    // 0x80800108: bc1fl       L_80800120
    if (!c1cs) {
        // 0x8080010C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80800120;
    }
    goto skip_3;
    // 0x8080010C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_3:
    // 0x80800110: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    // 0x80800114: b           L_8080013C
    // 0x80800118: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
        goto L_8080013C;
    // 0x80800118: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080011C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80800120:
    // 0x80800120: nop

    // 0x80800124: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800128: nop

    // 0x8080012C: bc1fl       L_80800140
    if (!c1cs) {
        // 0x80800130: lwc1        $f16, 0x18($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
            goto L_80800140;
    }
    goto skip_4;
    // 0x80800130: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    skip_4:
    // 0x80800134: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    // 0x80800138: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
L_8080013C:
    // 0x8080013C: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
L_80800140:
    // 0x80800140: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800144: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800148: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080014C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80800150: jal         0x800886F0
    // 0x80800154: nop

    _glglobalsettings_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800154: nop

    after_4:
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800160: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void func_80802998_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802998: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080299C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808029A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808029A4: lw          $a1, 0x20($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X20);
    // 0x808029A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808029AC: beql        $a1, $zero, L_80802A8C
    if (ctx->r5 == 0) {
        // 0x808029B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802A8C;
    }
    goto skip_0;
    // 0x808029B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808029B4: lh          $v0, 0x28($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X28);
    // 0x808029B8: bnel        $v0, $zero, L_808029D0
    if (ctx->r2 != 0) {
        // 0x808029BC: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_808029D0;
    }
    goto skip_1;
    // 0x808029BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_1:
    // 0x808029C0: lh          $t6, 0x2A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2A);
    // 0x808029C4: beql        $t6, $zero, L_80802A8C
    if (ctx->r14 == 0) {
        // 0x808029C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802A8C;
    }
    goto skip_2;
    // 0x808029C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808029CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_808029D0:
    // 0x808029D0: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808029D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808029D8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x808029DC: nop

    // 0x808029E0: bc1f        L_80802A60
    if (!c1cs) {
        // 0x808029E4: nop
    
            goto L_80802A60;
    }
    // 0x808029E4: nop

    // 0x808029E8: lh          $a2, 0x26($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X26);
    // 0x808029EC: lh          $t9, 0x2A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2A);
    // 0x808029F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x808029F4: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x808029F8: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808029FC: slt         $at, $t9, $a2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80802A00: beq         $at, $zero, L_80802A14
    if (ctx->r1 == 0) {
        // 0x80802A04: nop
    
            goto L_80802A14;
    }
    // 0x80802A04: nop

    // 0x80802A08: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x80802A0C: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x80802A10: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
L_80802A14:
    // 0x80802A14: jal         0x80087BE0
    // 0x80802A18: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    _gczoombox_entrypoint_32(rdram, ctx);
        goto after_0;
    // 0x80802A18: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802A1C: lh          $a2, 0x26($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X26);
    // 0x80802A20: lw          $a0, 0x23C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X23C);
    // 0x80802A24: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x80802A28: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80802A2C: jal         0x80088720
    // 0x80802A30: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80802A30: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_1:
    // 0x80802A34: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80802A38: jal         0x80087B20
    // 0x80802A3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gczoombox_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80802A3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80802A40: lbu         $t4, 0x1D($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1D);
    // 0x80802A44: lh          $a2, 0x26($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X26);
    // 0x80802A48: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80802A4C: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x80802A50: sb          $t5, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r13;
    // 0x80802A54: sh          $a2, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r6;
    // 0x80802A58: b           L_80802A88
    // 0x80802A5C: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
        goto L_80802A88;
    // 0x80802A5C: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
L_80802A60:
    // 0x80802A60: jal         0x80087AF8
    // 0x80802A64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80802A64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80802A68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802A6C: bnel        $v0, $at, L_80802A8C
    if (ctx->r2 != ctx->r1) {
        // 0x80802A70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802A8C;
    }
    goto skip_3;
    // 0x80802A70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80802A74: jal         0x800D8FF8
    // 0x80802A78: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80802A78: nop

    after_4:
    // 0x80802A7C: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80802A80: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80802A84: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_80802A88:
    // 0x80802A88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802A8C:
    // 0x80802A8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802A90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802A94: jr          $ra
    // 0x80802A98: nop

    return;
    // 0x80802A98: nop

;}
RECOMP_FUNC void func_800CB7C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB7C4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800CB7C8: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800CB7CC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800CB7D0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800CB7D4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800CB7D8: lw          $t9, -0x548C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X548C);
    // 0x800CB7DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB7E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB7E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CB7E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CB7EC: jalr        $t9
    // 0x800CB7F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CB7F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800CB7F4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800CB7F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CB7FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800CB800: jalr        $t9
    // 0x800CB804: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CB804: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800CB808: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CB80C: bne         $v0, $at, L_800CB828
    if (ctx->r2 != ctx->r1) {
        // 0x800CB810: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800CB828;
    }
    // 0x800CB810: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CB814: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800CB818: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    // 0x800CB81C: jal         0x800FC63C
    // 0x800CB820: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800FC63C(rdram, ctx);
        goto after_2;
    // 0x800CB820: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x800CB824: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800CB828:
    // 0x800CB828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB82C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB830: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CB834: jr          $ra
    // 0x800CB838: nop

    return;
    // 0x800CB838: nop

    // 0x800CB83C: nop

;}
RECOMP_FUNC void func_80014A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014A54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80014A58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014A5C: jal         0x8001DCA0
    // 0x80014A60: nop

    __osGetSR_2(rdram, ctx);
        goto after_0;
    // 0x80014A60: nop

    after_0:
    // 0x80014A64: andi        $t6, $v0, 0x1000
    ctx->r14 = ctx->r2 & 0X1000;
    // 0x80014A68: bnel        $t6, $zero, L_80014A7C
    if (ctx->r14 != 0) {
        // 0x80014A6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80014A7C;
    }
    goto skip_0;
    // 0x80014A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80014A70: jal         0x800149BC
    // 0x80014A74: nop

    func_800149BC(rdram, ctx);
        goto after_1;
    // 0x80014A74: nop

    after_1:
    // 0x80014A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80014A7C:
    // 0x80014A7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80014A80: jr          $ra
    // 0x80014A84: nop

    return;
    // 0x80014A84: nop

;}
RECOMP_FUNC void sumultiscore_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008F8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x808008FC: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80800900: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800904: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800908: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080090C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80800910: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x80800914: addu        $t9, $a0, $t1
    ctx->r25 = ADD32(ctx->r4, ctx->r9);
    // 0x80800918: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8080091C: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x80800920: lw          $t4, 0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4);
    // 0x80800924: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800928: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x8080092C: lw          $t7, 0x160($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X160);
    // 0x80800930: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80800934: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80800938: addu        $t0, $t3, $v0
    ctx->r8 = ADD32(ctx->r11, ctx->r2);
    // 0x8080093C: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x80800940: addiu       $t0, $t0, 0x40
    ctx->r8 = ADD32(ctx->r8, 0X40);
    // 0x80800944: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800948: beq         $t7, $zero, L_80800978
    if (ctx->r15 == 0) {
        // 0x8080094C: addiu       $v1, $v1, 0x40
        ctx->r3 = ADD32(ctx->r3, 0X40);
            goto L_80800978;
    }
    // 0x8080094C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x80800950: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x80800954: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x80800958: lbu         $t5, 0x6($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X6);
    // 0x8080095C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800960: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x80800964: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80800968: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x8080096C: addu        $a1, $t4, $a0
    ctx->r5 = ADD32(ctx->r12, ctx->r4);
    // 0x80800970: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80800974: sb          $t5, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r13;
L_80800978:
    // 0x80800978: sw          $a2, 0x160($v0)
    MEM_W(0X160, ctx->r2) = ctx->r6;
    // 0x8080097C: lbu         $t7, 0x1($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1);
    // 0x80800980: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800984: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80800988: sb          $t7, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r15;
    // 0x8080098C: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80800990: sw          $a3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r7;
    // 0x80800994: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(3154, 0X14B0) << 16);
    // 0x80800998: swc1        $f4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f4.u32l;
    // 0x8080099C: lbu         $t8, 0x6($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X6);
    // 0x808009A0: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x808009A4: sb          $t8, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r24;
    // 0x808009A8: bne         $t1, $at, L_808009F0
    if (ctx->r9 != ctx->r1) {
        // 0x808009AC: sb          $zero, 0x6($t0)
        MEM_B(0X6, ctx->r8) = 0;
            goto L_808009F0;
    }
    // 0x808009AC: sb          $zero, 0x6($t0)
    MEM_B(0X6, ctx->r8) = 0;
    // 0x808009B0: lw          $t9, 0x14B0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(3154, 0X14B0));
    // 0x808009B4: sb          $zero, 0x4($v1)
    MEM_B(0X4, ctx->r3) = 0;
    // 0x808009B8: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x808009BC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808009C0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x808009C4: jal         0x800F53D0
    // 0x808009C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x808009C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x808009CC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808009D0: jal         0x80085540
    // 0x808009D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _badeathmatch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808009D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808009D8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808009DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808009E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808009E4: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // 0x808009E8: sb          $zero, 0x5($v1)
    MEM_B(0X5, ctx->r3) = 0;
    // 0x808009EC: swc1        $f6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f6.u32l;
L_808009F0:
    // 0x808009F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009F8: jr          $ra
    // 0x808009FC: nop

    return;
    // 0x808009FC: nop

;}
RECOMP_FUNC void func_80800920_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800920: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800924: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800928: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080092C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800930: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800934: jal         0x80100094
    // 0x80800938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080093C: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x80800940: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1140, 0X2AAC) << 16);
    // 0x80800944: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800948: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x8080094C: bltz        $t8, L_80800DB0
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800950: addiu       $t9, $t9, 0x2AAC
        ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1140, 0X2AAC));
            goto L_80800DB0;
    }
    // 0x80800950: addiu       $t9, $t9, 0x2AAC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1140, 0X2AAC));
    // 0x80800954: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800958: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8080095C: lbu         $a0, 0x9($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X9);
    // 0x80800960: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800964: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800968: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080096C: bc1fl       L_8080097C
    if (!c1cs) {
        // 0x80800970: sw          $t9, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r25;
            goto L_8080097C;
    }
    goto skip_0;
    // 0x80800970: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    skip_0:
    // 0x80800974: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800978: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
L_8080097C:
    // 0x8080097C: lw          $t0, 0x70($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X70);
    // 0x80800980: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80800984: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80800988: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8080098C: jal         0x80089D60
    // 0x80800990: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    _subaddieaudioloop_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800990: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_1:
    // 0x80800994: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1140, 0X2A9C) << 16);
    // 0x80800998: sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // 0x8080099C: addiu       $t2, $t2, 0x2A9C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1140, 0X2A9C));
    // 0x808009A0: lbu         $a0, 0x8($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X8);
    // 0x808009A4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808009A8: lw          $t3, 0x70($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X70);
    // 0x808009AC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808009B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808009B4: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x808009B8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808009BC: jal         0x80089D60
    // 0x808009C0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    _subaddieaudioloop_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808009C0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_2:
    // 0x808009C4: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808009C8: beq         $a0, $zero, L_808009D8
    if (ctx->r4 == 0) {
        // 0x808009CC: sb          $v0, 0x8($s1)
        MEM_B(0X8, ctx->r17) = ctx->r2;
            goto L_808009D8;
    }
    // 0x808009CC: sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // 0x808009D0: jal         0x800C31DC
    // 0x808009D4: lw          $a1, 0x28($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X28);
    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x808009D4: lw          $a1, 0x28($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X28);
    after_3:
L_808009D8:
    // 0x808009D8: jal         0x800D9078
    // 0x808009DC: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    func_800D9078(rdram, ctx);
        goto after_4;
    // 0x808009DC: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    after_4:
    // 0x808009E0: jal         0x800D9078
    // 0x808009E4: addiu       $a0, $s1, 0x20
    ctx->r4 = ADD32(ctx->r17, 0X20);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x808009E4: addiu       $a0, $s1, 0x20
    ctx->r4 = ADD32(ctx->r17, 0X20);
    after_5:
    // 0x808009E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808009EC: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x808009F0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808009F4: nop

    // 0x808009F8: bc1f        L_80800B20
    if (!c1cs) {
        // 0x808009FC: nop
    
            goto L_80800B20;
    }
    // 0x808009FC: nop

    // 0x80800A00: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800A04: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80800A08: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800A0C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80800A10: nop

    // 0x80800A14: bc1fl       L_80800AE4
    if (!c1cs) {
        // 0x80800A18: lw          $a0, 0x14($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X14);
            goto L_80800AE4;
    }
    goto skip_1;
    // 0x80800A18: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    skip_1:
    // 0x80800A1C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800A20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A24: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x80800A28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800A2C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800A30: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800A34: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800A38: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800A3C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800A40: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800A44: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800A48: jal         0x8010CFBC
    // 0x80800A4C: nop

    func_8010CFBC(rdram, ctx);
        goto after_6;
    // 0x80800A4C: nop

    after_6:
    // 0x80800A50: beql        $v0, $zero, L_80800AE4
    if (ctx->r2 == 0) {
        // 0x80800A54: lw          $a0, 0x14($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X14);
            goto L_80800AE4;
    }
    goto skip_2;
    // 0x80800A54: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    skip_2:
    // 0x80800A58: jal         0x800F54E4
    // 0x80800A5C: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800A5C: nop

    after_7:
    // 0x80800A60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A64: jal         0x800F7B9C
    // 0x80800A68: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800F7B9C(rdram, ctx);
        goto after_8;
    // 0x80800A68: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_8:
    // 0x80800A6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A70: bnel        $v0, $at, L_80800AE4
    if (ctx->r2 != ctx->r1) {
        // 0x80800A74: lw          $a0, 0x14($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X14);
            goto L_80800AE4;
    }
    goto skip_3;
    // 0x80800A74: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    skip_3:
    // 0x80800A78: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800A7C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800A80: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800A84: bgezl       $t9, L_80800AA0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800A88: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800AA0;
    }
    goto skip_4;
    // 0x80800A88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_4:
    // 0x80800A8C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800A90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A94: b           L_80800AA8
    // 0x80800A98: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
        goto L_80800AA8;
    // 0x80800A98: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80800A9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800AA0:
    // 0x80800AA0: nop

    // 0x80800AA4: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
L_80800AA8:
    // 0x80800AA8: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80800AAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X277C) << 16);
    // 0x80800AB0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800AB4: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x80800AB8: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x80800ABC: lwc1        $f8, 0x277C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X277C));
    // 0x80800AC0: jal         0x800F54E4
    // 0x80800AC4: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x80800AC4: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    after_9:
    // 0x80800AC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800ACC: jal         0x800F57F0
    // 0x80800AD0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800F57F0(rdram, ctx);
        goto after_10;
    // 0x80800AD0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_10:
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD8: jal         0x800862B8
    // 0x80800ADC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    _chelectricfence_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800ADC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_11:
    // 0x80800AE0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
L_80800AE4:
    // 0x80800AE4: jal         0x800C8CB8
    // 0x80800AE8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800C8CB8(rdram, ctx);
        goto after_12;
    // 0x80800AE8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x80800AEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X2780) << 16);
    // 0x80800AF0: jal         0x800DC298
    // 0x80800AF4: lwc1        $f12, 0x2780($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X2780));
    func_800DC298(rdram, ctx);
        goto after_13;
    // 0x80800AF4: lwc1        $f12, 0x2780($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X2780));
    after_13:
    // 0x80800AF8: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80800AFC: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x80800B00: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(1140, 0X2890) << 16);
    // 0x80800B04: addiu       $t4, $t4, 0x2890
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(1140, 0X2890));
    // 0x80800B08: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80800B0C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x80800B10: jal         0x800C8E84
    // 0x80800B14: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    func_800C8E84(rdram, ctx);
        goto after_14;
    // 0x80800B14: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    after_14:
    // 0x80800B18: b           L_80800B34
    // 0x80800B1C: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
        goto L_80800B34;
    // 0x80800B1C: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
L_80800B20:
    // 0x80800B20: beq         $v0, $zero, L_80800B30
    if (ctx->r2 == 0) {
        // 0x80800B24: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800B30;
    }
    // 0x80800B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B28: jal         0x800C8FE0
    // 0x80800B2C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    func_800C8FE0(rdram, ctx);
        goto after_15;
    // 0x80800B2C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    after_15:
L_80800B30:
    // 0x80800B30: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
L_80800B34:
    // 0x80800B34: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x80800B38: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800B3C: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80800B40: beq         $at, $zero, L_80800D34
    if (ctx->r1 == 0) {
        // 0x80800B44: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800D34;
    }
    // 0x80800B44: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800B48: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X2784) << 16);
    // 0x80800B4C: addu        $at, $at, $t7
    gpr jr_addend_80800B54 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800B50: lw          $t7, 0x2784($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1140, 0X2784));
    // 0x80800B54: jr          $t7
    // 0x80800B58: nop

    switch (jr_addend_80800B54 >> 2) {
        case 0: goto L_80800B5C; break;
        case 1: goto L_80800C00; break;
        case 2: goto L_80800C68; break;
        case 3: goto L_80800C90; break;
        case 4: goto L_80800D1C; break;
        case 5: goto L_80800D34; break;
        default: switch_error(__func__, 0x80800B54, 0x80802784);
    }
    // 0x80800B58: nop

L_80800B5C:
    // 0x80800B5C: jal         0x800D9078
    // 0x80800B60: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_16;
    // 0x80800B60: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_16:
    // 0x80800B64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800B6C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800B70: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800B74: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800B78: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800B7C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800B80: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800B84: jal         0x800F12D4
    // 0x80800B88: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F12D4(rdram, ctx);
        goto after_17;
    // 0x80800B88: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_17:
    // 0x80800B8C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80800B90: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800B94: jal         0x800EE88C
    // 0x80800B98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE88C(rdram, ctx);
        goto after_18;
    // 0x80800B98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_18:
    // 0x80800B9C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800BA0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800BA4: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x80800BA8: jal         0x800EFE50
    // 0x80800BAC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_800EFE50(rdram, ctx);
        goto after_19;
    // 0x80800BAC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_19:
    // 0x80800BB0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80800BB4: beql        $t8, $zero, L_80800D38
    if (ctx->r24 == 0) {
        // 0x80800BB8: lw          $t5, 0x64($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X64);
            goto L_80800D38;
    }
    goto skip_5;
    // 0x80800BB8: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    skip_5:
    // 0x80800BBC: jal         0x8008A498
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC8: addiu       $a1, $s1, 0x34
    ctx->r5 = ADD32(ctx->r17, 0X34);
    // 0x80800BCC: jal         0x80089F70
    // 0x80800BD0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_21;
    // 0x80800BD0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_21:
    // 0x80800BD4: jal         0x80089F60
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_22;
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800BDC: jal         0x80107200
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80107200(rdram, ctx);
        goto after_23;
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE8: jal         0x80801160
    // 0x80800BEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801160_chfactoryrobot(rdram, ctx);
        goto after_24;
    // 0x80800BEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_24:
    // 0x80800BF0: lbu         $t0, 0x64($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X64);
    // 0x80800BF4: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80800BF8: b           L_80800D34
    // 0x80800BFC: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
        goto L_80800D34;
    // 0x80800BFC: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
L_80800C00:
    // 0x80800C00: jal         0x80801278
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801278_chfactoryrobot(rdram, ctx);
        goto after_25;
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800C08: beq         $v0, $zero, L_80800D34
    if (ctx->r2 == 0) {
        // 0x80800C0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D34;
    }
    // 0x80800C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C10: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1140, 0X2A8C) << 16);
    // 0x80800C14: addiu       $a2, $a2, 0x2A8C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1140, 0X2A8C));
    // 0x80800C18: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800C1C: jal         0x80089D20
    // 0x80800C20: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x80800C20: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_26:
    // 0x80800C24: jal         0x80101DDC
    // 0x80800C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_27;
    // 0x80800C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800C2C: beq         $v0, $zero, L_80800D34
    if (ctx->r2 == 0) {
        // 0x80800C30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D34;
    }
    // 0x80800C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C34: jal         0x80801160
    // 0x80800C38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801160_chfactoryrobot(rdram, ctx);
        goto after_28;
    // 0x80800C38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_28:
    // 0x80800C3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800C40: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C44: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800C48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C4C: jal         0x800DC178
    // 0x80800C50: nop

    func_800DC178(rdram, ctx);
        goto after_29;
    // 0x80800C50: nop

    after_29:
    // 0x80800C54: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800C58: jal         0x80801C7C
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C7C_chfactoryrobot(rdram, ctx);
        goto after_30;
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800C60: b           L_80800D38
    // 0x80800C64: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
        goto L_80800D38;
    // 0x80800C64: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
L_80800C68:
    // 0x80800C68: jal         0x80801278
    // 0x80800C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801278_chfactoryrobot(rdram, ctx);
        goto after_31;
    // 0x80800C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800C70: beql        $v0, $zero, L_80800D38
    if (ctx->r2 == 0) {
        // 0x80800C74: lw          $t5, 0x64($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X64);
            goto L_80800D38;
    }
    goto skip_6;
    // 0x80800C74: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    skip_6:
    // 0x80800C78: jal         0x80801BB0
    // 0x80800C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801BB0_chfactoryrobot(rdram, ctx);
        goto after_32;
    // 0x80800C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800C80: jal         0x80801A80
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A80_chfactoryrobot(rdram, ctx);
        goto after_33;
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80800C88: b           L_80800D38
    // 0x80800C8C: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
        goto L_80800D38;
    // 0x80800C8C: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
L_80800C90:
    // 0x80800C90: jal         0x80801278
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801278_chfactoryrobot(rdram, ctx);
        goto after_34;
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800C98: beq         $v0, $zero, L_80800D34
    if (ctx->r2 == 0) {
        // 0x80800C9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D34;
    }
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1140, 0X2A8C) << 16);
    // 0x80800CA4: addiu       $a2, $a2, 0x2A8C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1140, 0X2A8C));
    // 0x80800CA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800CAC: jal         0x80089D20
    // 0x80800CB0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_35;
    // 0x80800CB0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_35:
    // 0x80800CB4: jal         0x80101DDC
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_36;
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800CBC: beq         $v0, $zero, L_80800D34
    if (ctx->r2 == 0) {
        // 0x80800CC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D34;
    }
    // 0x80800CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC4: jal         0x80801160
    // 0x80800CC8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801160_chfactoryrobot(rdram, ctx);
        goto after_37;
    // 0x80800CC8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_37:
    // 0x80800CCC: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800CD0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800CD4: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80800CD8: bgezl       $t4, L_80800D04
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800CDC: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80800D04;
    }
    goto skip_7;
    // 0x80800CDC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_7:
    // 0x80800CE0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800CE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800CE8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800CEC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800CF0: jal         0x800DC178
    // 0x80800CF4: nop

    func_800DC178(rdram, ctx);
        goto after_38;
    // 0x80800CF4: nop

    after_38:
    // 0x80800CF8: b           L_80800D34
    // 0x80800CFC: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800D34;
    // 0x80800CFC: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800D00: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80800D04:
    // 0x80800D04: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800D08: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800D0C: jal         0x800DC178
    // 0x80800D10: nop

    func_800DC178(rdram, ctx);
        goto after_39;
    // 0x80800D10: nop

    after_39:
    // 0x80800D14: b           L_80800D34
    // 0x80800D18: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800D34;
    // 0x80800D18: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800D1C:
    // 0x80800D1C: jal         0x80801278
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801278_chfactoryrobot(rdram, ctx);
        goto after_40;
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80800D24: beql        $v0, $zero, L_80800D38
    if (ctx->r2 == 0) {
        // 0x80800D28: lw          $t5, 0x64($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X64);
            goto L_80800D38;
    }
    goto skip_8;
    // 0x80800D28: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    skip_8:
    // 0x80800D2C: jal         0x80801B3C
    // 0x80800D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B3C_chfactoryrobot(rdram, ctx);
        goto after_41;
    // 0x80800D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
L_80800D34:
    // 0x80800D34: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
L_80800D38:
    // 0x80800D38: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80800D3C: bltzl       $t7, L_80800DB4
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800D40: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800DB4;
    }
    goto skip_9;
    // 0x80800D40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x80800D44: lh          $t8, 0x18($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X18);
    // 0x80800D48: beql        $t8, $zero, L_80800DB4
    if (ctx->r24 == 0) {
        // 0x80800D4C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800DB4;
    }
    goto skip_10;
    // 0x80800D4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x80800D50: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800D54: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80800D58: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800D5C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80800D60: nop

    // 0x80800D64: bc1fl       L_80800DB4
    if (!c1cs) {
        // 0x80800D68: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800DB4;
    }
    goto skip_11;
    // 0x80800D68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_11:
    // 0x80800D6C: jal         0x800EEB40
    // 0x80800D70: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EEB40(rdram, ctx);
        goto after_42;
    // 0x80800D70: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_42:
    // 0x80800D74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X279C) << 16);
    // 0x80800D78: lwc1        $f4, 0x279C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X279C));
    // 0x80800D7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D80: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800D84: nop

    // 0x80800D88: bc1fl       L_80800DB4
    if (!c1cs) {
        // 0x80800D8C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800DB4;
    }
    goto skip_12;
    // 0x80800D8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x80800D90: jal         0x800C8FE0
    // 0x80800D94: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    func_800C8FE0(rdram, ctx);
        goto after_43;
    // 0x80800D94: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    after_43:
    // 0x80800D98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X27A0) << 16);
    // 0x80800D9C: lwc1        $f12, 0x27A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27A0));
    // 0x80800DA0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X27A4) << 16);
    // 0x80800DA4: jal         0x800DC178
    // 0x80800DA8: lwc1        $f14, 0x27A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27A4));
    func_800DC178(rdram, ctx);
        goto after_44;
    // 0x80800DA8: lwc1        $f14, 0x27A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27A4));
    after_44:
    // 0x80800DAC: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_80800DB0:
    // 0x80800DB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800DB4:
    // 0x80800DB4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DB8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800DBC: jr          $ra
    // 0x80800DC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800DC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8080093C_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080093C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800944: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800948: jal         0x800839E8
    // 0x8080094C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080094C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800950: beq         $v0, $zero, L_80800964
    if (ctx->r2 == 0) {
        // 0x80800954: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800964;
    }
    // 0x80800954: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800958: jal         0x800839B0
    // 0x8080095C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x8080095C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800960: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800964:
    // 0x80800964: jal         0x8009E5C8
    // 0x80800968: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800968: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080096C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800970: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800974: jr          $ra
    // 0x80800978: nop

    return;
    // 0x80800978: nop

;}
RECOMP_FUNC void func_800EC3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC3E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC3EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC3F0: lhu         $a1, 0x14($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X14);
    // 0x800EC3F4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800EC3F8: beq         $a1, $zero, L_800EC408
    if (ctx->r5 == 0) {
        // 0x800EC3FC: nop
    
            goto L_800EC408;
    }
    // 0x800EC3FC: nop

    // 0x800EC400: bne         $a1, $at, L_800EC410
    if (ctx->r5 != ctx->r1) {
        // 0x800EC404: nop
    
            goto L_800EC410;
    }
    // 0x800EC404: nop

L_800EC408:
    // 0x800EC408: b           L_800EC418
    // 0x800EC40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EC418;
    // 0x800EC40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EC410:
    // 0x800EC410: jal         0x800D674C
    // 0x800EC414: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x800EC414: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_800EC418:
    // 0x800EC418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EC41C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EC420: jr          $ra
    // 0x800EC424: nop

    return;
    // 0x800EC424: nop

;}
RECOMP_FUNC void chfreezy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800388: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080038C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800390: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800394: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800398: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080039C: jal         0x80106790
    // 0x808003A0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808003A0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808003A4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808003A8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808003AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003B0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x808003B4: jal         0x80086E38
    // 0x808003B8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    _chnewfreezy_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808003B8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x808003BC: bne         $v0, $zero, L_808003D8
    if (ctx->r2 != 0) {
        // 0x808003C0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808003D8;
    }
    // 0x808003C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003C4: addiu       $a0, $zero, 0x363
    ctx->r4 = ADD32(0, 0X363);
    // 0x808003C8: jal         0x801084B0
    // 0x808003CC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_801084B0(rdram, ctx);
        goto after_2;
    // 0x808003CC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x808003D0: b           L_808003E4
    // 0x808003D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_808003E4;
    // 0x808003D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808003D8:
    // 0x808003D8: jal         0x80106790
    // 0x808003DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x808003DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x808003E0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_808003E4:
    // 0x808003E4: beq         $s0, $zero, L_80800438
    if (ctx->r16 == 0) {
        // 0x808003E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800438;
    }
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: jal         0x80100094
    // 0x808003F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808003F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808003F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003F8: jal         0x8008A028
    // 0x808003FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808003FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800408: jal         0x8080044C
    // 0x8080040C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_8080044C_chfreezy(rdram, ctx);
        goto after_6;
    // 0x8080040C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80800410: jal         0x8010A848
    // 0x80800414: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8010A848(rdram, ctx);
        goto after_7;
    // 0x80800414: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800418: lbu         $t9, 0x79($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X79);
    // 0x8080041C: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80800420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800424: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x80800428: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8080042C: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
    // 0x80800430: jal         0x8010A828
    // 0x80800434: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8010A828(rdram, ctx);
        goto after_8;
    // 0x80800434: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_8:
L_80800438:
    // 0x80800438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080043C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800440: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800444: jr          $ra
    // 0x80800448: nop

    return;
    // 0x80800448: nop

;}
RECOMP_FUNC void gcegg_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80800110: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800114: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800118: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2678, 0X206) << 16);
    // 0x8080011C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800120: jr          $ra
    // 0x80800124: lh          $v0, 0x206($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2678, 0X206));
    return;
    // 0x80800124: lh          $v0, 0x206($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2678, 0X206));
;}
RECOMP_FUNC void func_80800174_chjujubagfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080017C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800180: jal         0x80100094
    // 0x80800184: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800184: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800188: beq         $v0, $zero, L_80800198
    if (ctx->r2 == 0) {
        // 0x8080018C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800198;
    }
    // 0x8080018C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800190: jal         0x80089848
    // 0x80800194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800198:
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080019C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void bsmumcast_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080018C: jal         0x8008E95C
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E95C(rdram, ctx);
        goto after_0;
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800194: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800198: jal         0x800A0DA0
    // 0x8080019C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0DA0(rdram, ctx);
        goto after_1;
    // 0x8080019C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808001A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001A4: jal         0x800A0DAC
    // 0x808001A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0DAC(rdram, ctx);
        goto after_2;
    // 0x808001A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808001AC: jal         0x80083800
    // 0x808001B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsmum_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808001B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808001B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001BC: jr          $ra
    // 0x808001C0: nop

    return;
    // 0x808001C0: nop

;}
RECOMP_FUNC void _bamovegoto_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084DC0: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084DC0);
    return;
    // 0x80084DC4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _baeggsetup_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A78: syscall     126
    recomp_syscall_handler(rdram, ctx, 0x80084A78);
    return;
    // 0x80084A7C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
