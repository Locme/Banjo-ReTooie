#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void baswim_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800404: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800408: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080040C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800410: jal         0x808003B8
    // 0x80800414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808003B8_baswim(rdram, ctx);
        goto after_0;
    // 0x80800414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800418: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x8080041C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800420: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800424: jal         0x800F1214
    // 0x80800428: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    func_800F1214(rdram, ctx);
        goto after_1;
    // 0x80800428: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_1:
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: jal         0x80084C90
    // 0x80800434: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    _bafpctrl_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800434: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800438: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8080043C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800440: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800444: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(624, 0X5C4) << 16);
    // 0x80800448: lwc1        $f14, 0x5C4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(624, 0X5C4));
    // 0x8080044C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800450: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800454: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800458: jal         0x800F10B4
    // 0x8080045C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x8080045C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80800460: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800464: lui         $a2, 0x3FCC
    ctx->r6 = S32(0X3FCC << 16);
    // 0x80800468: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080046C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800478: jal         0x8009BFE4
    // 0x8080047C: nop

    func_8009BFE4(rdram, ctx);
        goto after_4;
    // 0x8080047C: nop

    after_4:
    // 0x80800480: jal         0x8009EF34
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getY(rdram, ctx);
        goto after_5;
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800488: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080048C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800490: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800494: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800498: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080049C: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x808004A0: bc1fl       L_808004E4
    if (!c1cs) {
        // 0x808004A4: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_808004E4;
    }
    goto skip_0;
    // 0x808004A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x808004A8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808004AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004B0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808004B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004B8: lui         $a3, 0x4389
    ctx->r7 = S32(0X4389 << 16);
    // 0x808004BC: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x808004C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808004C4: jal         0x800F10B4
    // 0x808004C8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x808004C8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x808004CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004D0: jal         0x8009BF5C
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BF5C(rdram, ctx);
        goto after_7;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808004D8: b           L_80800500
    // 0x808004DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800500;
    // 0x808004DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_808004E4:
    // 0x808004E4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808004E8: jal         0x800F10B4
    // 0x808004EC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x808004EC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x808004F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004F4: jal         0x8009BF5C
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BF5C(rdram, ctx);
        goto after_9;
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808004FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800500:
    // 0x80800500: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800504: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800508: jr          $ra
    // 0x8080050C: nop

    return;
    // 0x8080050C: nop

;}
RECOMP_FUNC void func_808017C4_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808017C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808017CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808017D4: jal         0x800DC298
    // 0x808017D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x808017D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808017DC: beq         $v0, $zero, L_808017F4
    if (ctx->r2 == 0) {
        // 0x808017E0: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808017F4;
    }
    // 0x808017E0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808017E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808017E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808017EC: b           L_80801800
    // 0x808017F0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
        goto L_80801800;
    // 0x808017F0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
L_808017F4:
    // 0x808017F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808017F8: nop

    // 0x808017FC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
L_80801800:
    // 0x80801800: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801804: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801808: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080180C: jal         0x800DC178
    // 0x80801810: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80801810: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80801814: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80801818: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080181C: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80801820: jal         0x80801D8C
    // 0x80801824: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    func_80801D8C_chhoopswoop(rdram, ctx);
        goto after_2;
    // 0x80801824: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x80801828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080182C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801830: jr          $ra
    // 0x80801834: nop

    return;
    // 0x80801834: nop

;}
RECOMP_FUNC void func_808004C0_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004C8: jal         0x80800000
    // 0x808004CC: nop

    func_80800000_bsbansnooze(rdram, ctx);
        goto after_0;
    // 0x808004CC: nop

    after_0:
    // 0x808004D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004D8: jr          $ra
    // 0x808004DC: nop

    return;
    // 0x808004DC: nop

;}
RECOMP_FUNC void func_80803D54_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803D54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803D58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803D5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803D60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803D64: beq         $a1, $zero, L_80803D88
    if (ctx->r5 == 0) {
        // 0x80803D68: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80803D88;
    }
    // 0x80803D68: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80803D6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803D70: beq         $a1, $at, L_80803DA8
    if (ctx->r5 == ctx->r1) {
        // 0x80803D74: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80803DA8;
    }
    // 0x80803D74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803D78: beq         $a1, $at, L_80803DC8
    if (ctx->r5 == ctx->r1) {
        // 0x80803D7C: nop
    
            goto L_80803DC8;
    }
    // 0x80803D7C: nop

    // 0x80803D80: b           L_80803DE8
    // 0x80803D84: nop

        goto L_80803DE8;
    // 0x80803D84: nop

L_80803D88:
    // 0x80803D88: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C34) << 16);
    // 0x80803D8C: lwc1        $f12, 0x4C34($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C34));
    // 0x80803D90: jal         0x800DC298
    // 0x80803D94: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80803D94: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80803D98: beq         $v0, $zero, L_80803DE8
    if (ctx->r2 == 0) {
        // 0x80803D9C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80803DE8;
    }
    // 0x80803D9C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80803DA0: b           L_80803E04
    // 0x80803DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803E04;
    // 0x80803DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803DA8:
    // 0x80803DA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C38) << 16);
    // 0x80803DAC: lwc1        $f12, 0x4C38($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C38));
    // 0x80803DB0: jal         0x800DC298
    // 0x80803DB4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x80803DB4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80803DB8: beq         $v0, $zero, L_80803DE8
    if (ctx->r2 == 0) {
        // 0x80803DBC: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80803DE8;
    }
    // 0x80803DBC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80803DC0: b           L_80803E04
    // 0x80803DC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803E04;
    // 0x80803DC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803DC8:
    // 0x80803DC8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C3C) << 16);
    // 0x80803DCC: lwc1        $f12, 0x4C3C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C3C));
    // 0x80803DD0: jal         0x800DC298
    // 0x80803DD4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800DC298(rdram, ctx);
        goto after_2;
    // 0x80803DD4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80803DD8: beq         $v0, $zero, L_80803DE8
    if (ctx->r2 == 0) {
        // 0x80803DDC: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80803DE8;
    }
    // 0x80803DDC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80803DE0: b           L_80803E04
    // 0x80803DE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803E04;
    // 0x80803DE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803DE8:
    // 0x80803DE8: bne         $s0, $s0, L_80803E00
    if (ctx->r16 != ctx->r16) {
        // 0x80803DEC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80803E00;
    }
L_80803DEC:
    // 0x80803DEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80803DF0: jal         0x800DC128
    // 0x80803DF4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x80803DF4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80803DF8: beq         $v0, $s0, L_80803DEC
    if (ctx->r2 == ctx->r16) {
        // 0x80803DFC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80803DEC;
    }
    // 0x80803DFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80803E00:
    // 0x80803E00: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80803E04:
    // 0x80803E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803E08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803E0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803E10: jr          $ra
    // 0x80803E14: nop

    return;
    // 0x80803E14: nop

;}
RECOMP_FUNC void func_8080086C_chpufferfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080086C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800874: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800878: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080087C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800880: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800884: jal         0x80102424
    // 0x80800888: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800888: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8080088C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800890: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800894: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800898: beq         $a1, $v1, L_808008C8
    if (ctx->r5 == ctx->r3) {
        // 0x8080089C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808008C8;
    }
    // 0x8080089C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008A4: beq         $a1, $at, L_808008D4
    if (ctx->r5 == ctx->r1) {
        // 0x808008A8: nop
    
            goto L_808008D4;
    }
    // 0x808008A8: nop

    // 0x808008AC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x808008B0: beq         $a1, $v1, L_808008EC
    if (ctx->r5 == ctx->r3) {
        // 0x808008B4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808008EC;
    }
    // 0x808008B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808008B8: beq         $a1, $at, L_808008FC
    if (ctx->r5 == ctx->r1) {
        // 0x808008BC: nop
    
            goto L_808008FC;
    }
    // 0x808008BC: nop

    // 0x808008C0: b           L_80800930
    // 0x808008C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800930;
    // 0x808008C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008C8:
    // 0x808008C8: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x808008CC: b           L_8080092C
    // 0x808008D0: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
        goto L_8080092C;
    // 0x808008D0: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
L_808008D4:
    // 0x808008D4: bnel        $v0, $v1, L_80800930
    if (ctx->r2 != ctx->r3) {
        // 0x808008D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800930;
    }
    goto skip_0;
    // 0x808008D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808008DC: jal         0x80101EE4
    // 0x808008E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101EE4(rdram, ctx);
        goto after_1;
    // 0x808008E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x808008E4: b           L_80800930
    // 0x808008E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800930;
    // 0x808008E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008EC:
    // 0x808008EC: lwc1        $f0, 0x34($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X34);
    // 0x808008F0: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808008F4: b           L_8080092C
    // 0x808008F8: swc1        $f6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f6.u32l;
        goto L_8080092C;
    // 0x808008F8: swc1        $f6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f6.u32l;
L_808008FC:
    // 0x808008FC: bne         $v0, $v1, L_80800914
    if (ctx->r2 != ctx->r3) {
        // 0x80800900: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_80800914;
    }
    // 0x80800900: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800904: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800908: jal         0x80101EE4
    // 0x8080090C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80101EE4(rdram, ctx);
        goto after_2;
    // 0x8080090C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800910: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800914:
    // 0x80800914: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800918: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080091C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800920: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800924: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    // 0x80800928: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
L_8080092C:
    // 0x8080092C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800930:
    // 0x80800930: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800934: jr          $ra
    // 0x80800938: nop

    return;
    // 0x80800938: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BB8: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BB8);
    return;
    // 0x80087BBC: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_800E95AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E95AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E95B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E95B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E95B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E95BC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800E95C0: jal         0x8001211C
    // 0x800E95C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x800E95C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_0:
    // 0x800E95C8: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x800E95CC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800E95D0: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x800E95D4: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x800E95D8: addu        $ra, $ra, $t5
    ctx->r31 = ADD32(ctx->r31, ctx->r13);
    // 0x800E95DC: lw          $v1, 0x351C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X351C);
    // 0x800E95E0: lw          $ra, 0x3514($ra)
    ctx->r31 = MEM_W(ctx->r31, 0X3514);
    // 0x800E95E4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800E95E8: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800E95EC: slt         $at, $v1, $ra
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x800E95F0: beq         $at, $zero, L_800E969C
    if (ctx->r1 == 0) {
        // 0x800E95F4: sll         $t6, $v1, 1
        ctx->r14 = S32(ctx->r3 << 1);
            goto L_800E969C;
    }
    // 0x800E95F4: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800E95F8: addiu       $t7, $t7, -0x2970
    ctx->r15 = ADD32(ctx->r15, -0X2970);
    // 0x800E95FC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800E9600: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800E9604: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800E9608: addiu       $t0, $t0, -0x2970
    ctx->r8 = ADD32(ctx->r8, -0X2970);
    // 0x800E960C: addiu       $t2, $t2, 0x2560
    ctx->r10 = ADD32(ctx->r10, 0X2560);
    // 0x800E9610: addiu       $t3, $t3, 0x2650
    ctx->r11 = ADD32(ctx->r11, 0X2650);
    // 0x800E9614: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800E9618: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800E961C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_800E9620:
    // 0x800E9620: lh          $a2, 0x190($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X190);
    // 0x800E9624: addu        $t8, $t0, $a3
    ctx->r24 = ADD32(ctx->r8, ctx->r7);
    // 0x800E9628: beql        $t1, $a2, L_800E9690
    if (ctx->r9 == ctx->r6) {
        // 0x800E962C: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800E9690;
    }
    goto skip_0;
    // 0x800E962C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_0:
    // 0x800E9630: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800E9634: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x800E9638: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x800E963C: bnel        $t9, $zero, L_800E9690
    if (ctx->r25 != 0) {
        // 0x800E9640: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800E9690;
    }
    goto skip_1;
    // 0x800E9640: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_1:
    // 0x800E9644: lw          $t8, 0x50($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X50);
    // 0x800E9648: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x800E964C: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x800E9650: sltu        $at, $s1, $t9
    ctx->r1 = ctx->r17 < ctx->r25 ? 1 : 0;
    // 0x800E9654: beq         $at, $zero, L_800E968C
    if (ctx->r1 == 0) {
        // 0x800E9658: addu        $t8, $t2, $t7
        ctx->r24 = ADD32(ctx->r10, ctx->r15);
            goto L_800E968C;
    }
    // 0x800E9658: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x800E965C: lh          $t6, 0x230($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X230);
    // 0x800E9660: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800E9664: addu        $v1, $t0, $t5
    ctx->r3 = ADD32(ctx->r8, ctx->r13);
    // 0x800E9668: addu        $a0, $t6, $t9
    ctx->r4 = ADD32(ctx->r14, ctx->r25);
    // 0x800E966C: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x800E9670: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x800E9674: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800E9678: sb          $t4, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r12;
    // 0x800E967C: sh          $t1, 0x190($a1)
    MEM_H(0X190, ctx->r5) = ctx->r9;
    // 0x800E9680: lw          $t9, 0x4EC8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4EC8);
    // 0x800E9684: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x800E9688: sw          $t7, 0x4EC8($v1)
    MEM_W(0X4EC8, ctx->r3) = ctx->r15;
L_800E968C:
    // 0x800E968C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800E9690:
    // 0x800E9690: slt         $at, $a3, $ra
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x800E9694: bne         $at, $zero, L_800E9620
    if (ctx->r1 != 0) {
        // 0x800E9698: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800E9620;
    }
    // 0x800E9698: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_800E969C:
    // 0x800E969C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E96A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E96A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E96A8: jr          $ra
    // 0x800E96AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800E96AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void subaddiedialog_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801304: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080130C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801310: sh          $a1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r5;
    // 0x80801314: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
    // 0x80801318: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8080131C: jal         0x8010114C
    // 0x80801320: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x80801320: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_0:
    // 0x80801324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801328: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080132C: jr          $ra
    // 0x80801330: nop

    return;
    // 0x80801330: nop

;}
RECOMP_FUNC void func_80801248_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801248: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080124C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801250: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801254: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801258: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080125C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801260: jal         0x8009BB24
    // 0x80801264: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009BB24(rdram, ctx);
        goto after_0;
    // 0x80801264: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80801268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080126C: jal         0x8008DF8C
    // 0x80801270: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_1;
    // 0x80801270: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_1:
    // 0x80801274: beq         $v0, $zero, L_80801280
    if (ctx->r2 == 0) {
        // 0x80801278: nop
    
            goto L_80801280;
    }
    // 0x80801278: nop

    // 0x8080127C: addiu       $s1, $zero, 0xDF
    ctx->r17 = ADD32(0, 0XDF);
L_80801280:
    // 0x80801280: jal         0x800D8FF8
    // 0x80801284: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80801284: nop

    after_2:
    // 0x80801288: lw          $v0, 0x188($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X188);
    // 0x8080128C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801290: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801294: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80801298: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8080129C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x808012A0: lw          $t6, 0x188($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X188);
    // 0x808012A4: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x808012A8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808012AC: nop

    // 0x808012B0: bc1f        L_808012C0
    if (!c1cs) {
        // 0x808012B4: nop
    
            goto L_808012C0;
    }
    // 0x808012B4: nop

    // 0x808012B8: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
    // 0x808012BC: addiu       $s1, $zero, 0x162
    ctx->r17 = ADD32(0, 0X162);
L_808012C0:
    // 0x808012C0: jal         0x80097E74
    // 0x808012C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097E74(rdram, ctx);
        goto after_3;
    // 0x808012C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808012C8: beq         $v0, $zero, L_808012D4
    if (ctx->r2 == 0) {
        // 0x808012CC: nop
    
            goto L_808012D4;
    }
    // 0x808012CC: nop

    // 0x808012D0: addiu       $s1, $zero, 0xBE
    ctx->r17 = ADD32(0, 0XBE);
L_808012D4:
    // 0x808012D4: jal         0x8008E078
    // 0x808012D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_4;
    // 0x808012D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808012DC: beq         $v0, $zero, L_808012F0
    if (ctx->r2 == 0) {
        // 0x808012E0: nop
    
            goto L_808012F0;
    }
    // 0x808012E0: nop

    // 0x808012E4: jal         0x8009FE58
    // 0x808012E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_5;
    // 0x808012E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808012EC: addiu       $s1, $zero, 0xBC
    ctx->r17 = ADD32(0, 0XBC);
L_808012F0:
    // 0x808012F0: jal         0x8008E35C
    // 0x808012F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_6;
    // 0x808012F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808012F8: beq         $v0, $zero, L_80801304
    if (ctx->r2 == 0) {
        // 0x808012FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801304;
    }
    // 0x808012FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801300: addiu       $s1, $zero, 0x15D
    ctx->r17 = ADD32(0, 0X15D);
L_80801304:
    // 0x80801304: jal         0x8009E5C8
    // 0x80801308: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80801308: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x8080130C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801310: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801314: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801318: jr          $ra
    // 0x8080131C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080131C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800A1450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1450: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A1454: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A1458: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A145C: addiu       $s0, $s0, 0x7090
    ctx->r16 = ADD32(ctx->r16, 0X7090);
    // 0x800A1460: lbu         $t6, 0x3($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3);
    // 0x800A1464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A1468: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800A146C: beql        $t6, $zero, L_800A1490
    if (ctx->r14 == 0) {
        // 0x800A1470: lbu         $t7, 0x0($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X0);
            goto L_800A1490;
    }
    goto skip_0;
    // 0x800A1470: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    skip_0:
    // 0x800A1474: jal         0x8008FD48
    // 0x800A1478: nop

    func_8008FD48(rdram, ctx);
        goto after_0;
    // 0x800A1478: nop

    after_0:
    // 0x800A147C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A1480: jal         0x800D5034
    // 0x800A1484: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800D5034(rdram, ctx);
        goto after_1;
    // 0x800A1484: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800A1488: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800A148C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
L_800A1490:
    // 0x800A1490: beql        $t7, $zero, L_800A14C4
    if (ctx->r15 == 0) {
        // 0x800A1494: lbu         $t0, 0x4($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X4);
            goto L_800A14C4;
    }
    goto skip_1;
    // 0x800A1494: lbu         $t0, 0x4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4);
    skip_1:
    // 0x800A1498: jal         0x80090128
    // 0x800A149C: nop

    func_80090128(rdram, ctx);
        goto after_2;
    // 0x800A149C: nop

    after_2:
    // 0x800A14A0: beql        $v0, $zero, L_800A14C0
    if (ctx->r2 == 0) {
        // 0x800A14A4: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_800A14C0;
    }
    goto skip_2;
    // 0x800A14A4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    skip_2:
    // 0x800A14A8: lbu         $t8, 0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2);
    // 0x800A14AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A14B0: bnel        $t8, $zero, L_800A14C0
    if (ctx->r24 != 0) {
        // 0x800A14B4: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_800A14C0;
    }
    goto skip_3;
    // 0x800A14B4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    skip_3:
    // 0x800A14B8: sb          $t9, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r25;
    // 0x800A14BC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_800A14C0:
    // 0x800A14C0: lbu         $t0, 0x4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4);
L_800A14C4:
    // 0x800A14C4: beql        $t0, $zero, L_800A14E4
    if (ctx->r8 == 0) {
        // 0x800A14C8: lbu         $t1, 0x1($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X1);
            goto L_800A14E4;
    }
    goto skip_4;
    // 0x800A14C8: lbu         $t1, 0x1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1);
    skip_4:
    // 0x800A14CC: jal         0x8008FD48
    // 0x800A14D0: nop

    func_8008FD48(rdram, ctx);
        goto after_3;
    // 0x800A14D0: nop

    after_3:
    // 0x800A14D4: jal         0x800A1240
    // 0x800A14D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A1240(rdram, ctx);
        goto after_4;
    // 0x800A14D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800A14DC: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x800A14E0: lbu         $t1, 0x1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1);
L_800A14E4:
    // 0x800A14E4: beq         $t1, $zero, L_800A1508
    if (ctx->r9 == 0) {
        // 0x800A14E8: nop
    
            goto L_800A1508;
    }
    // 0x800A14E8: nop

    // 0x800A14EC: jal         0x800C95D4
    // 0x800A14F0: nop

    func_800C95D4(rdram, ctx);
        goto after_5;
    // 0x800A14F0: nop

    after_5:
    // 0x800A14F4: beq         $v0, $zero, L_800A152C
    if (ctx->r2 == 0) {
        // 0x800A14F8: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800A152C;
    }
    // 0x800A14F8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800A14FC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800A1500: b           L_800A152C
    // 0x800A1504: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
        goto L_800A152C;
    // 0x800A1504: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_800A1508:
    // 0x800A1508: jal         0x8008FD48
    // 0x800A150C: nop

    func_8008FD48(rdram, ctx);
        goto after_6;
    // 0x800A150C: nop

    after_6:
    // 0x800A1510: jal         0x800D4E7C
    // 0x800A1514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D4E7C(rdram, ctx);
        goto after_7;
    // 0x800A1514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x800A1518: beq         $v0, $zero, L_800A152C
    if (ctx->r2 == 0) {
        // 0x800A151C: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_800A152C;
    }
    // 0x800A151C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800A1520: beq         $at, $zero, L_800A152C
    if (ctx->r1 == 0) {
        // 0x800A1524: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800A152C;
    }
    // 0x800A1524: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A1528: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_800A152C:
    // 0x800A152C: lbu         $t4, 0x7($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X7);
    // 0x800A1530: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A1534: beq         $t4, $zero, L_800A15D8
    if (ctx->r12 == 0) {
        // 0x800A1538: nop
    
            goto L_800A15D8;
    }
    // 0x800A1538: nop

    // 0x800A153C: jal         0x800A1624
    // 0x800A1540: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_800A1624(rdram, ctx);
        goto after_8;
    // 0x800A1540: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_8:
    // 0x800A1544: jal         0x800CE864
    // 0x800A1548: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CE864(rdram, ctx);
        goto after_9;
    // 0x800A1548: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x800A154C: jal         0x800CF7F4
    // 0x800A1550: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CF7F4(rdram, ctx);
        goto after_10;
    // 0x800A1550: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x800A1554: jal         0x800D2820
    // 0x800A1558: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    func_800D2820(rdram, ctx);
        goto after_11;
    // 0x800A1558: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    after_11:
    // 0x800A155C: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A1560: bnel        $v1, $zero, L_800A1578
    if (ctx->r3 != 0) {
        // 0x800A1564: lbu         $t5, 0x8($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X8);
            goto L_800A1578;
    }
    goto skip_5;
    // 0x800A1564: lbu         $t5, 0x8($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X8);
    skip_5:
    // 0x800A1568: jal         0x800D2820
    // 0x800A156C: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    func_800D2820(rdram, ctx);
        goto after_12;
    // 0x800A156C: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    after_12:
    // 0x800A1570: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A1574: lbu         $t5, 0x8($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X8);
L_800A1578:
    // 0x800A1578: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800A157C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A1580: beq         $t5, $at, L_800A15A0
    if (ctx->r13 == ctx->r1) {
        // 0x800A1584: addiu       $a0, $zero, 0xC9
        ctx->r4 = ADD32(0, 0XC9);
            goto L_800A15A0;
    }
    // 0x800A1584: addiu       $a0, $zero, 0xC9
    ctx->r4 = ADD32(0, 0XC9);
    // 0x800A1588: jal         0x800D284C
    // 0x800A158C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800D284C(rdram, ctx);
        goto after_13;
    // 0x800A158C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_13:
    // 0x800A1590: jal         0x800D2820
    // 0x800A1594: addiu       $a0, $zero, 0xC9
    ctx->r4 = ADD32(0, 0XC9);
    func_800D2820(rdram, ctx);
        goto after_14;
    // 0x800A1594: addiu       $a0, $zero, 0xC9
    ctx->r4 = ADD32(0, 0XC9);
    after_14:
    // 0x800A1598: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A159C: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
L_800A15A0:
    // 0x800A15A0: bne         $a1, $zero, L_800A15D8
    if (ctx->r5 != 0) {
        // 0x800A15A4: nop
    
            goto L_800A15D8;
    }
    // 0x800A15A4: nop

    // 0x800A15A8: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
    // 0x800A15AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A15B0: sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
    // 0x800A15B4: bnel        $v0, $at, L_800A15D8
    if (ctx->r2 != ctx->r1) {
        // 0x800A15B8: sb          $zero, 0x6($s0)
        MEM_B(0X6, ctx->r16) = 0;
            goto L_800A15D8;
    }
    goto skip_6;
    // 0x800A15B8: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    skip_6:
    // 0x800A15BC: jal         0x800A1240
    // 0x800A15C0: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    func_800A1240(rdram, ctx);
        goto after_15;
    // 0x800A15C0: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    after_15:
    // 0x800A15C4: jal         0x800A1294
    // 0x800A15C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A1294(rdram, ctx);
        goto after_16;
    // 0x800A15C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x800A15CC: b           L_800A15D8
    // 0x800A15D0: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
        goto L_800A15D8;
    // 0x800A15D0: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // 0x800A15D4: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
L_800A15D8:
    // 0x800A15D8: jal         0x80090128
    // 0x800A15DC: nop

    func_80090128(rdram, ctx);
        goto after_17;
    // 0x800A15DC: nop

    after_17:
    // 0x800A15E0: beq         $v0, $zero, L_800A1604
    if (ctx->r2 == 0) {
        // 0x800A15E4: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_800A1604;
    }
    // 0x800A15E4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800A15E8: beql        $t6, $zero, L_800A1608
    if (ctx->r14 == 0) {
        // 0x800A15EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A1608;
    }
    goto skip_7;
    // 0x800A15EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x800A15F0: lbu         $t7, 0x5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5);
    // 0x800A15F4: bnel        $t7, $zero, L_800A1608
    if (ctx->r15 != 0) {
        // 0x800A15F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A1608;
    }
    goto skip_8;
    // 0x800A15F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x800A15FC: jal         0x800A1294
    // 0x800A1600: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A1294(rdram, ctx);
        goto after_18;
    // 0x800A1600: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
L_800A1604:
    // 0x800A1604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A1608:
    // 0x800A1608: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A160C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A1610: jr          $ra
    // 0x800A1614: nop

    return;
    // 0x800A1614: nop

;}
RECOMP_FUNC void bastick_popZone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EF60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EF64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EF68: lw          $v0, 0x128($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X128);
    // 0x8009EF6C: lbu         $t6, 0x66($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X66);
    // 0x8009EF70: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8009EF74: sb          $t7, 0x66($v0)
    MEM_B(0X66, ctx->r2) = ctx->r15;
    // 0x8009EF78: lw          $v0, 0x128($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X128);
    // 0x8009EF7C: lbu         $t8, 0x66($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X66);
    // 0x8009EF80: addiu       $a0, $v0, 0x38
    ctx->r4 = ADD32(ctx->r2, 0X38);
    // 0x8009EF84: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8009EF88: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8009EF8C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8009EF90: jal         0x8009EF40
    // 0x8009EF94: addu        $a1, $v0, $t9
    ctx->r5 = ADD32(ctx->r2, ctx->r25);
    __bastick_zoneCopy(rdram, ctx);
        goto after_0;
    // 0x8009EF94: addu        $a1, $v0, $t9
    ctx->r5 = ADD32(ctx->r2, ctx->r25);
    after_0:
    // 0x8009EF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EF9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009EFA0: jr          $ra
    // 0x8009EFA4: nop

    return;
    // 0x8009EFA4: nop

;}
RECOMP_FUNC void func_8009BADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BADC: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BAE0: jr          $ra
    // 0x8009BAE4: lwc1        $f0, 0x34($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X34);
    return;
    // 0x8009BAE4: lwc1        $f0, 0x34($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X34);
;}
RECOMP_FUNC void _chdodgemcontrol_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CF8: syscall     445
    recomp_syscall_handler(rdram, ctx, 0x80086CF8);
    return;
    // 0x80086CFC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F4A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4A2C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4A34: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4A3C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4A40: jal         0x80084850
    // 0x800F4A44: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _badrone_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x800F4A44: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4A50: jr          $ra
    // 0x800F4A54: nop

    return;
    // 0x800F4A54: nop

;}
RECOMP_FUNC void func_80801344_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080134C: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x80801350: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801354: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    // 0x80801358: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x8080135C: beq         $t6, $zero, L_80801384
    if (ctx->r14 == 0) {
        // 0x80801360: nop
    
            goto L_80801384;
    }
    // 0x80801360: nop

    // 0x80801364: beq         $t6, $at, L_80801384
    if (ctx->r14 == ctx->r1) {
        // 0x80801368: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801384;
    }
    // 0x80801368: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080136C: beq         $t6, $at, L_80801384
    if (ctx->r14 == ctx->r1) {
        // 0x80801370: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801384;
    }
    // 0x80801370: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801374: beq         $t6, $at, L_80801394
    if (ctx->r14 == ctx->r1) {
        // 0x80801378: addiu       $a0, $zero, 0xC3
        ctx->r4 = ADD32(0, 0XC3);
            goto L_80801394;
    }
    // 0x80801378: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    // 0x8080137C: b           L_808013A0
    // 0x80801380: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
        goto L_808013A0;
    // 0x80801380: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
L_80801384:
    // 0x80801384: jal         0x800D2748
    // 0x80801388: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    func_800D2748(rdram, ctx);
        goto after_0;
    // 0x80801388: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    after_0:
    // 0x8080138C: b           L_808013A0
    // 0x80801390: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
        goto L_808013A0;
    // 0x80801390: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
L_80801394:
    // 0x80801394: jal         0x800D2748
    // 0x80801398: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_800D2748(rdram, ctx);
        goto after_1;
    // 0x80801398: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_1:
    // 0x8080139C: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
L_808013A0:
    // 0x808013A0: jal         0x800D2748
    // 0x808013A4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_800D2748(rdram, ctx);
        goto after_2;
    // 0x808013A4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_2:
    // 0x808013A8: addiu       $a0, $zero, 0xC5
    ctx->r4 = ADD32(0, 0XC5);
    // 0x808013AC: jal         0x800D2748
    // 0x808013B0: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    func_800D2748(rdram, ctx);
        goto after_3;
    // 0x808013B0: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_3:
    // 0x808013B4: addiu       $a0, $zero, 0xC6
    ctx->r4 = ADD32(0, 0XC6);
    // 0x808013B8: jal         0x800D2748
    // 0x808013BC: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    func_800D2748(rdram, ctx);
        goto after_4;
    // 0x808013BC: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_4:
    // 0x808013C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013C8: jr          $ra
    // 0x808013CC: nop

    return;
    // 0x808013CC: nop

;}
RECOMP_FUNC void _bafly_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C60: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C60);
    return;
    // 0x80084C64: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_8080072C_charmouredcaveman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080072C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800730: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1116, 0XBCC) << 16);
    // 0x80800734: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800738: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080073C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800740: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800744: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800748: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080074C: addiu       $t7, $t7, 0xBCC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1116, 0XBCC));
    // 0x80800750: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800754: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800758: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x8080075C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800760: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800764: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80800768: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8080076C: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1116, 0XBDC) << 16);
    // 0x80800770: addiu       $t2, $t2, 0xBDC
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1116, 0XBDC));
    // 0x80800774: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x80800778: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8080077C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80800780: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80800784: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x80800788: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8080078C: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80800790: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80800794: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x80800798: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1116, 0XBEC) << 16);
    // 0x8080079C: addiu       $t8, $t8, 0xBEC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1116, 0XBEC));
    // 0x808007A0: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x808007A4: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x808007A8: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x808007AC: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x808007B0: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x808007B4: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1116, 0XBF4) << 16);
    // 0x808007B8: addiu       $t3, $t3, 0xBF4
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1116, 0XBF4));
    // 0x808007BC: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x808007C0: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x808007C4: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x808007C8: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x808007CC: addiu       $t4, $sp, 0x40
    ctx->r12 = ADD32(ctx->r29, 0X40);
    // 0x808007D0: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x808007D4: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x808007D8: lbu         $t7, 0x5F($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X5F);
    // 0x808007DC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808007E0: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    // 0x808007E4: bne         $t7, $zero, L_808007FC
    if (ctx->r15 != 0) {
        // 0x808007E8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808007FC;
    }
    // 0x808007E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007EC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1116, 0XBFC) << 16);
    // 0x808007F0: jal         0x800C4350
    // 0x808007F4: addiu       $a2, $a2, 0xBFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1116, 0XBFC));
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x808007F4: addiu       $a2, $a2, 0xBFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1116, 0XBFC));
    after_0:
    // 0x808007F8: sb          $v0, 0x5F($s4)
    MEM_B(0X5F, ctx->r20) = ctx->r2;
L_808007FC:
    // 0x808007FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800800: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800804: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
    // 0x80800808: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_8080080C:
    // 0x8080080C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800810: jal         0x80101E14
    // 0x80800814: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x80800814: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x80800818: beq         $v0, $zero, L_80800884
    if (ctx->r2 == 0) {
        // 0x8080081C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800884;
    }
    // 0x8080081C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800820: sll         $s1, $s0, 1
    ctx->r17 = S32(ctx->r16 << 1);
    // 0x80800824: addu        $a1, $sp, $s1
    ctx->r5 = ADD32(ctx->r29, ctx->r17);
    // 0x80800828: lh          $a1, 0x48($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X48);
    // 0x8080082C: jal         0x800C301C
    // 0x80800830: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    func_800C301C(rdram, ctx);
        goto after_2;
    // 0x80800830: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    after_2:
    // 0x80800834: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1116, 0XAD0) << 16);
    // 0x80800838: lwc1        $f12, 0xAD0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1116, 0XAD0));
    // 0x8080083C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1116, 0XAD4) << 16);
    // 0x80800840: jal         0x800DC178
    // 0x80800844: lwc1        $f14, 0xAD4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1116, 0XAD4));
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800844: lwc1        $f14, 0xAD4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1116, 0XAD4));
    after_3:
    // 0x80800848: addu        $t6, $sp, $s2
    ctx->r14 = ADD32(ctx->r29, ctx->r18);
    // 0x8080084C: lwc1        $f4, 0x50($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X50);
    // 0x80800850: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    // 0x80800854: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800858: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080085C: jal         0x800C31DC
    // 0x80800860: nop

    func_800C31DC(rdram, ctx);
        goto after_4;
    // 0x80800860: nop

    after_4:
    // 0x80800864: addu        $a1, $sp, $s1
    ctx->r5 = ADD32(ctx->r29, ctx->r17);
    // 0x80800868: lh          $a1, 0x40($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X40);
    // 0x8080086C: jal         0x800C3058
    // 0x80800870: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    func_800C3058(rdram, ctx);
        goto after_5;
    // 0x80800870: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    after_5:
    // 0x80800874: jal         0x800C3BDC
    // 0x80800878: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    func_800C3BDC(rdram, ctx);
        goto after_6;
    // 0x80800878: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    after_6:
    // 0x8080087C: b           L_80800894
    // 0x80800880: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800894;
    // 0x80800880: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800884:
    // 0x80800884: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800888: bne         $s0, $s3, L_8080080C
    if (ctx->r16 != ctx->r19) {
        // 0x8080088C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8080080C;
    }
    // 0x8080088C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800890: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800894:
    // 0x80800894: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800898: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080089C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808008A0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808008A4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808008A8: jr          $ra
    // 0x808008AC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808008AC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8080193C_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080193C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801944: jal         0x80800128
    // 0x80801948: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800128_bsbfly(rdram, ctx);
        goto after_0;
    // 0x80801948: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080194C: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x80801950: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80801954: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080195C: jal         0x80084C30
    // 0x80801960: addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    _bafly_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80801960: addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    after_1:
    // 0x80801964: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801968: jal         0x800A0CF4
    // 0x8080196C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x8080196C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801978: jr          $ra
    // 0x8080197C: nop

    return;
    // 0x8080197C: nop

;}
RECOMP_FUNC void func_808014F4_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808014F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808014FC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801504: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801508: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080150C: jal         0x80100094
    // 0x80801510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801518: jal         0x800EE7F8
    // 0x8080151C: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080151C: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    after_1:
    // 0x80801520: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801524: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801528: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080152C: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80801530: jal         0x800136E4
    // 0x80801534: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80801534: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x80801538: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080153C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801540: jal         0x800EF1B8
    // 0x80801544: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x80801544: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_3:
    // 0x80801548: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8080154C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801550: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801554: jal         0x800EF1B8
    // 0x80801558: lw          $a1, 0x48($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x80801558: lw          $a1, 0x48($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X48);
    after_4:
    // 0x8080155C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801560: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801564: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801568: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8080156C: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80801570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801574: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080157C: jr          $ra
    // 0x80801580: nop

    return;
    // 0x80801580: nop

;}
RECOMP_FUNC void func_80800694_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800694: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080069C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808006A0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0X10D8) << 16);
    // 0x808006A4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1012, 0X10F0) << 16);
    // 0x808006A8: addiu       $a3, $a3, 0x10F0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1012, 0X10F0));
    // 0x808006AC: addiu       $a2, $a2, 0x10D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0X10D8));
    // 0x808006B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006B4: jal         0x80089D28
    // 0x808006B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808006B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0X10CC) << 16);
    // 0x808006C0: addiu       $a2, $a2, 0x10CC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0X10CC));
    // 0x808006C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006C8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808006CC: jal         0x80089D20
    // 0x808006D0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808006D0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x808006D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0X10E4) << 16);
    // 0x808006D8: addiu       $a2, $a2, 0x10E4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0X10E4));
    // 0x808006DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808006E4: jal         0x80089D20
    // 0x808006E8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808006E8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_2:
    // 0x808006EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006F4: jr          $ra
    // 0x808006F8: nop

    return;
    // 0x808006F8: nop

;}
RECOMP_FUNC void func_80113320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113320: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80113324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80113328: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8011332C: jal         0x800EE7F8
    // 0x80113330: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80113330: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80113334: jal         0x80110840
    // 0x80113338: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80110840(rdram, ctx);
        goto after_1;
    // 0x80113338: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x8011333C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80113340: jal         0x800F5B64
    // 0x80113344: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5B64(rdram, ctx);
        goto after_2;
    // 0x80113344: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x80113348: lui         $a3, 0x86
    ctx->r7 = S32(0X86 << 16);
    // 0x8011334C: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80113350: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80113354: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80113358: jal         0x800C6A7C
    // 0x8011335C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800C6A7C(rdram, ctx);
        goto after_3;
    // 0x8011335C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80113360: beq         $v0, $zero, L_80113370
    if (ctx->r2 == 0) {
        // 0x80113364: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80113370;
    }
    // 0x80113364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113368: b           L_80113374
    // 0x8011336C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80113374;
    // 0x8011336C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80113370:
    // 0x80113370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80113374:
    // 0x80113374: jr          $ra
    // 0x80113378: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80113378: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bapulse_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: lw          $v0, 0xE8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE8);
    // 0x80800014: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800018: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080001C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800020: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800024: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80800028: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8080002C: jal         0x800F10B4
    // 0x80800030: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80800030: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_80800000_chtoxicroombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80800008: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800010: beq         $a1, $at, L_80800170
    if (ctx->r5 == ctx->r1) {
        // 0x80800014: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800170;
    }
    // 0x80800014: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800018: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080001C: beq         $a1, $at, L_80800180
    if (ctx->r5 == ctx->r1) {
        // 0x80800020: lui         $t1, 0x8080
        ctx->r9 = S32(RELOC_HI16(2308, 0XF00) << 16);
            goto L_80800180;
    }
    // 0x80800020: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2308, 0XF00) << 16);
    // 0x80800024: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800028: bne         $a1, $at, L_808001C4
    if (ctx->r5 != ctx->r1) {
        // 0x8080002C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808001C4;
    }
    // 0x8080002C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800030: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80800034: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2308, 0XFA0) << 16);
    // 0x80800038: addiu       $a2, $a2, 0xFA0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2308, 0XFA0));
    // 0x8080003C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800040: jal         0x80089D18
    // 0x80800044: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800048: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8080004C: addiu       $at, $zero, 0x884
    ctx->r1 = ADD32(0, 0X884);
    // 0x80800050: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2308, 0XF0C) << 16);
    // 0x80800054: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800058: addiu       $t0, $t0, 0xF0C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2308, 0XF0C));
    // 0x8080005C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800060: lhu         $t8, 0x14($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X14);
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800068: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080006C: bne         $t8, $at, L_808000E0
    if (ctx->r24 != ctx->r1) {
        // 0x80800070: addiu       $a3, $zero, 0x5
        ctx->r7 = ADD32(0, 0X5);
            goto L_808000E0;
    }
    // 0x80800070: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800074: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2308, 0XF54) << 16);
    // 0x80800078: addiu       $t9, $t9, 0xF54
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2308, 0XF54));
    // 0x8080007C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800080: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800088: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080008C: jal         0x800BBCB8
    // 0x80800090: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80800090: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x80800094: jal         0x800DA298
    // 0x80800098: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800098: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_2:
    // 0x8080009C: bnel        $v0, $zero, L_80800160
    if (ctx->r2 != 0) {
        // 0x808000A0: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800160;
    }
    goto skip_0;
    // 0x808000A0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x808000A4: jal         0x800DA544
    // 0x808000A8: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x808000A8: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_3:
    // 0x808000AC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808000B0: jal         0x80108B04
    // 0x808000B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_4;
    // 0x808000B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000B8: addiu       $a0, $zero, 0x3A7
    ctx->r4 = ADD32(0, 0X3A7);
    // 0x808000BC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808000C0: jal         0x80101180
    // 0x808000C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x808000C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x808000C8: addiu       $a0, $zero, 0x3EB
    ctx->r4 = ADD32(0, 0X3EB);
    // 0x808000CC: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x808000D0: jal         0x80101180
    // 0x808000D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x808000D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808000D8: b           L_80800160
    // 0x808000DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_80800160;
    // 0x808000DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_808000E0:
    // 0x808000E0: jal         0x800BBCB8
    // 0x808000E4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800BBCB8(rdram, ctx);
        goto after_7;
    // 0x808000E4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_7:
    // 0x808000E8: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x808000EC: jal         0x800D0A9C
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_8;
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808000F4: bnel        $v0, $zero, L_80800160
    if (ctx->r2 != 0) {
        // 0x808000F8: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800160;
    }
    goto skip_1;
    // 0x808000F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x808000FC: jal         0x808004F0
    // 0x80800100: nop

    func_808004F0_chtoxicroombits(rdram, ctx);
        goto after_9;
    // 0x80800100: nop

    after_9:
    // 0x80800104: jal         0x808004C8
    // 0x80800108: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    func_808004C8_chtoxicroombits(rdram, ctx);
        goto after_10;
    // 0x80800108: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    after_10:
    // 0x8080010C: jal         0x808004F0
    // 0x80800110: nop

    func_808004F0_chtoxicroombits(rdram, ctx);
        goto after_11;
    // 0x80800110: nop

    after_11:
    // 0x80800114: bne         $v0, $zero, L_80800154
    if (ctx->r2 != 0) {
        // 0x80800118: nop
    
            goto L_80800154;
    }
    // 0x80800118: nop

    // 0x8080011C: jal         0x800FC6B0
    // 0x80800120: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC6B0(rdram, ctx);
        goto after_12;
    // 0x80800120: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_12:
    // 0x80800124: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80800128: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080012C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800130: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800134: jal         0x800D1000
    // 0x80800138: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_13;
    // 0x80800138: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x8080013C: addiu       $a0, $zero, 0x3EB
    ctx->r4 = ADD32(0, 0X3EB);
    // 0x80800140: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x80800144: jal         0x80101180
    // 0x80800148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80101180(rdram, ctx);
        goto after_14;
    // 0x80800148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x8080014C: b           L_80800160
    // 0x80800150: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_80800160;
    // 0x80800150: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80800154:
    // 0x80800154: jal         0x800FC6B0
    // 0x80800158: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_15;
    // 0x80800158: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_15:
    // 0x8080015C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80800160:
    // 0x80800160: jal         0x80086E20
    // 0x80800164: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _chskeletonexplode_entrypoint_7(rdram, ctx);
        goto after_16;
    // 0x80800164: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_16:
    // 0x80800168: b           L_808001C4
    // 0x8080016C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001C4;
    // 0x8080016C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800170:
    // 0x80800170: jal         0x800FFA88
    // 0x80800174: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_17;
    // 0x80800174: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    after_17:
    // 0x80800178: b           L_808001C4
    // 0x8080017C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001C4;
    // 0x8080017C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800180:
    // 0x80800180: addiu       $t1, $t1, 0xF00
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2308, 0XF00));
    // 0x80800184: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80800188: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080018C: addiu       $a0, $zero, 0x178
    ctx->r4 = ADD32(0, 0X178);
    // 0x80800190: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80800194: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80800198: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080019C: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x808001A0: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x808001A4: jal         0x80108474
    // 0x808001A8: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    func_80108474(rdram, ctx);
        goto after_18;
    // 0x808001A8: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    after_18:
    // 0x808001AC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808001B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001B4: nop

    // 0x808001B8: swc1        $f4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f4.u32l;
    // 0x808001BC: b           L_808001C4
    // 0x808001C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001C4;
    // 0x808001C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001C4:
    // 0x808001C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001CC: jr          $ra
    // 0x808001D0: nop

    return;
    // 0x808001D0: nop

;}
RECOMP_FUNC void gcdialogcamera_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080066C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800670: jal         0x808002E4
    // 0x80800674: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800674: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800678: jal         0x808005F8
    // 0x8080067C: nop

    gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080067C: nop

    after_1:
    // 0x80800680: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800684: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800688: bnel        $t6, $at, L_8080069C
    if (ctx->r14 != ctx->r1) {
        // 0x8080068C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8080069C;
    }
    goto skip_0;
    // 0x8080068C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800690: jal         0x800856C8
    // 0x80800694: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    _capod_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800694: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_2:
    // 0x80800698: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_8080069C:
    // 0x8080069C: jal         0x800856D8
    // 0x808006A0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x808006A0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808006A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006AC: jr          $ra
    // 0x808006B0: nop

    return;
    // 0x808006B0: nop

;}
RECOMP_FUNC void func_80019480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019480: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80019484: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80019488: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8001948C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80019490: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80019494: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80019498: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8001949C: addiu       $a0, $a0, -0x4350
    ctx->r4 = ADD32(ctx->r4, -0X4350);
    // 0x800194A0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x800194A4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800194A8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800194AC: beq         $v1, $a2, L_800194F4
    if (ctx->r3 == ctx->r6) {
        // 0x800194B0: lw          $t6, 0x0($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X0);
            goto L_800194F4;
    }
    // 0x800194B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
L_800194B4:
    // 0x800194B4: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x800194B8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800194BC: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800194C0: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800194C4: mul.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800194C8: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800194CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800194D0: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800194D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800194D8: mul.s       $f10, $f20, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x800194DC: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800194E0: add.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800194E4: add.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800194E8: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800194EC: bne         $v1, $a2, L_800194B4
    if (ctx->r3 != ctx->r6) {
        // 0x800194F0: lw          $t6, 0x0($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X0);
            goto L_800194B4;
    }
    // 0x800194F0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
L_800194F4:
    // 0x800194F4: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x800194F8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800194FC: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80019500: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80019504: mul.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80019508: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8001950C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80019510: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80019514: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80019518: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001951C: mul.s       $f10, $f20, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80019520: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80019524: add.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80019528: add.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001952C: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x80019530: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80019534: jr          $ra
    // 0x80019538: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80019538: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80020C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020C90: jr          $ra
    // 0x80020C94: nop

    return;
    // 0x80020C94: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B6C: jal         0x80800AD8
    // 0x80800B70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800AD8_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800B70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B74: bne         $v0, $zero, L_80800B84
    if (ctx->r2 != 0) {
        // 0x80800B78: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800B84;
    }
    // 0x80800B78: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800B7C: b           L_80800B94
    // 0x80800B80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B94;
    // 0x80800B80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B84:
    // 0x80800B84: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80800B88: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800B8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800B90: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_80800B94:
    // 0x80800B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B9C: jr          $ra
    // 0x80800BA0: nop

    return;
    // 0x80800BA0: nop

;}
RECOMP_FUNC void gsattract_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800268: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8080026C: jr          $ra
    // 0x80800270: sb          $t6, 0x5470($at)
    MEM_B(0X5470, ctx->r1) = ctx->r14;
    return;
    // 0x80800270: sb          $t6, 0x5470($at)
    MEM_B(0X5470, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80801AE4_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AE4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80801AE8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80801AEC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80801AF0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80801AF4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80801AF8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80801AFC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80801B00: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80801B04: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80801B08: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80801B0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801B10: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801B14: jal         0x80100094
    // 0x80801B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801B1C: addiu       $s7, $sp, 0x58
    ctx->r23 = ADD32(ctx->r29, 0X58);
    // 0x80801B20: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80801B24: jal         0x8010D254
    // 0x80801B28: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x80801B28: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x80801B2C: lh          $t6, 0x2($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2);
    // 0x80801B30: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80801B34: or          $s5, $s3, $zero
    ctx->r21 = ctx->r19 | 0;
    // 0x80801B38: blez        $t6, L_80801BF4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80801B3C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1060, 0X2A14) << 16);
            goto L_80801BF4;
    }
    // 0x80801B3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X2A14) << 16);
    // 0x80801B40: lwc1        $f20, 0x2A14($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1060, 0X2A14));
    // 0x80801B44: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x80801B48: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80801B4C:
    // 0x80801B4C: sh          $t7, 0xF4($s5)
    MEM_H(0XF4, ctx->r21) = ctx->r15;
    // 0x80801B50: addiu       $s4, $fp, -0x1
    ctx->r20 = ADD32(ctx->r30, -0X1);
    // 0x80801B54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80801B58:
    // 0x80801B58: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    // 0x80801B5C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80801B60: jal         0x800DC128
    // 0x80801B64: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80801B64: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    after_2:
    // 0x80801B68: bltz        $s4, L_80801B98
    if (SIGNED(ctx->r20) < 0) {
        // 0x80801B6C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80801B98;
    }
    // 0x80801B6C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801B70: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x80801B74: addu        $a0, $s3, $v1
    ctx->r4 = ADD32(ctx->r19, ctx->r3);
L_80801B78:
    // 0x80801B78: lh          $t8, 0xF4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XF4);
    // 0x80801B7C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x80801B80: bne         $v0, $t8, L_80801B90
    if (ctx->r2 != ctx->r24) {
        // 0x80801B84: nop
    
            goto L_80801B90;
    }
    // 0x80801B84: nop

    // 0x80801B88: b           L_80801B98
    // 0x80801B8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80801B98;
    // 0x80801B8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80801B90:
    // 0x80801B90: bgez        $v1, L_80801B78
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80801B94: addiu       $a0, $a0, -0x2
        ctx->r4 = ADD32(ctx->r4, -0X2);
            goto L_80801B78;
    }
    // 0x80801B94: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
L_80801B98:
    // 0x80801B98: beq         $s0, $zero, L_80801BD4
    if (ctx->r16 == 0) {
        // 0x80801B9C: nop
    
            goto L_80801BD4;
    }
    // 0x80801B9C: nop

    // 0x80801BA0: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801BA4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80801BA8: mflo        $t9
    ctx->r25 = lo;
    // 0x80801BAC: addu        $a1, $s3, $t9
    ctx->r5 = ADD32(ctx->r19, ctx->r25);
    // 0x80801BB0: jal         0x800EEB40
    // 0x80801BB4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x80801BB4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x80801BB8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80801BBC: nop

    // 0x80801BC0: bc1fl       L_80801BD4
    if (!c1cs) {
        // 0x80801BC4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80801BD4;
    }
    goto skip_0;
    // 0x80801BC4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x80801BC8: b           L_80801BD4
    // 0x80801BCC: sh          $s2, 0xF4($s5)
    MEM_H(0XF4, ctx->r21) = ctx->r18;
        goto L_80801BD4;
    // 0x80801BCC: sh          $s2, 0xF4($s5)
    MEM_H(0XF4, ctx->r21) = ctx->r18;
    // 0x80801BD0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80801BD4:
    // 0x80801BD4: beql        $s0, $zero, L_80801B58
    if (ctx->r16 == 0) {
        // 0x80801BD8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801B58;
    }
    goto skip_1;
    // 0x80801BD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
    // 0x80801BDC: lh          $t0, 0x2($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X2);
    // 0x80801BE0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80801BE4: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x80801BE8: slt         $at, $fp, $t0
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80801BEC: bnel        $at, $zero, L_80801B4C
    if (ctx->r1 != 0) {
        // 0x80801BF0: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_80801B4C;
    }
    goto skip_2;
    // 0x80801BF0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_2:
L_80801BF4:
    // 0x80801BF4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80801BF8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801BFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801C00: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80801C04: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80801C08: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80801C0C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80801C10: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80801C14: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80801C18: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80801C1C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80801C20: jr          $ra
    // 0x80801C24: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80801C24: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void bafly_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B6C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800B70: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800B74: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800B78: jal         0x8008CABC
    // 0x80800B7C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800B7C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800B80: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800B84: jal         0x8008E078
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_1;
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B8C: beq         $v0, $zero, L_80800B98
    if (ctx->r2 == 0) {
        // 0x80800B90: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_80800B98;
    }
    // 0x80800B90: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800B94: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800B98:
    // 0x80800B98: jal         0x8008B324
    // 0x80800B9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_2;
    // 0x80800B9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800BA0: beql        $v0, $zero, L_80800BE0
    if (ctx->r2 == 0) {
        // 0x80800BA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BE0;
    }
    goto skip_0;
    // 0x80800BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800BA8: jal         0x8008DD04
    // 0x80800BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_3;
    // 0x80800BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800BB0: bnel        $v0, $zero, L_80800BCC
    if (ctx->r2 != 0) {
        // 0x80800BB4: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_80800BCC;
    }
    goto skip_1;
    // 0x80800BB4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80800BB8: jal         0x8009650C
    // 0x80800BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009650C(rdram, ctx);
        goto after_4;
    // 0x80800BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800BC0: beql        $v0, $zero, L_80800BE0
    if (ctx->r2 == 0) {
        // 0x80800BC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BE0;
    }
    goto skip_2;
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800BC8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
L_80800BCC:
    // 0x80800BCC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800BD0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80800BD4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BD8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800BE0:
    // 0x80800BE0: jal         0x8009E5C8
    // 0x80800BE4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x80800BE4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80800BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800BF4: jr          $ra
    // 0x80800BF8: nop

    return;
    // 0x80800BF8: nop

;}
RECOMP_FUNC void func_800B7E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7E38: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7E3C: lw          $a0, -0x7D50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D50);
    // 0x800B7E40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7E48: beq         $a0, $zero, L_800B7E58
    if (ctx->r4 == 0) {
        // 0x800B7E4C: nop
    
            goto L_800B7E58;
    }
    // 0x800B7E4C: nop

    // 0x800B7E50: jal         0x80088968
    // 0x800B7E54: nop

    _fxleaves_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x800B7E54: nop

    after_0:
L_800B7E58:
    // 0x800B7E58: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7E5C: lw          $a0, -0x7D4C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D4C);
    // 0x800B7E60: beq         $a0, $zero, L_800B7E70
    if (ctx->r4 == 0) {
        // 0x800B7E64: nop
    
            goto L_800B7E70;
    }
    // 0x800B7E64: nop

    // 0x800B7E68: jal         0x80088928
    // 0x800B7E6C: nop

    _fxrain_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x800B7E6C: nop

    after_1:
L_800B7E70:
    // 0x800B7E70: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800B7E74: lw          $t6, 0x7128($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7128);
    // 0x800B7E78: beql        $t6, $zero, L_800B7E8C
    if (ctx->r14 == 0) {
        // 0x800B7E7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B7E8C;
    }
    goto skip_0;
    // 0x800B7E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B7E80: jal         0x800B9170
    // 0x800B7E84: nop

    func_800B9170(rdram, ctx);
        goto after_2;
    // 0x800B7E84: nop

    after_2:
    // 0x800B7E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B7E8C:
    // 0x800B7E8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7E90: jr          $ra
    // 0x800B7E94: nop

    return;
    // 0x800B7E94: nop

    // 0x800B7E98: nop

    // 0x800B7E9C: nop

;}
RECOMP_FUNC void func_800BE9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE9E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BE9E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE9EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BE9F0: jal         0x800BE7F8
    // 0x800BE9F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BE7F8(rdram, ctx);
        goto after_0;
    // 0x800BE9F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800BE9F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE9FC: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    // 0x800BEA00: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x800BEA04: beql        $t6, $zero, L_800BEA18
    if (ctx->r14 == 0) {
        // 0x800BEA08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BEA18;
    }
    goto skip_0;
    // 0x800BEA08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BEA0C: jal         0x80087F90
    // 0x800BEA10: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _gcmapsects_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x800BEA10: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800BEA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BEA18:
    // 0x800BEA18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BEA1C: jr          $ra
    // 0x800BEA20: nop

    return;
    // 0x800BEA20: nop

;}
RECOMP_FUNC void func_80013818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013818: mul.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8001381C: lui         $at, 0x4B00
    ctx->r1 = S32(0X4B00 << 16);
    // 0x80013820: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80013824: addiu       $t1, $t1, -0x2C60
    ctx->r9 = ADD32(ctx->r9, -0X2C60);
    // 0x80013828: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001382C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80013830: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80013834: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80013838: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8001383C: mul.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80013840: nop

    // 0x80013844: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80013848: round.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = lroundf(ctx->f4.fl);
    // 0x8001384C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80013850: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013854: lwc1        $f6, 0x16D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X16D8);
    // 0x80013858: andi        $t2, $a0, 0xFFF
    ctx->r10 = ctx->r4 & 0XFFF;
    // 0x8001385C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80013860: srl         $t0, $a0, 10
    ctx->r8 = S32(U32(ctx->r4) >> 10);
    // 0x80013864: andi        $t0, $t0, 0x1FFC
    ctx->r8 = ctx->r8 & 0X1FFC;
    // 0x80013868: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001386C: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80013870: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80013874: lwc1        $f12, 0x4($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80013878: addiu       $t0, $t0, 0x800
    ctx->r8 = ADD32(ctx->r8, 0X800);
    // 0x8001387C: andi        $t0, $t0, 0x1FFC
    ctx->r8 = ctx->r8 & 0X1FFC;
    // 0x80013880: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80013884: sub.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80013888: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x8001388C: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80013890: addiu       $t3, $t3, -0x3370
    ctx->r11 = ADD32(ctx->r11, -0X3370);
    // 0x80013894: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80013898: add.s       $f2, $f12, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8001389C: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800138A0: lwc1        $f12, 0x4($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800138A4: swc1        $f2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f2.u32l;
    // 0x800138A8: sub.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x800138AC: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800138B0: add.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x800138B4: jr          $ra
    // 0x800138B8: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
    return;
    // 0x800138B8: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80800A0C_chbeanstalkseed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800A14: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800A18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A20: beq         $a1, $at, L_80800A44
    if (ctx->r5 == ctx->r1) {
        // 0x80800A24: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800A44;
    }
    // 0x80800A24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800A28: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x80800A2C: beq         $a1, $at, L_80800A64
    if (ctx->r5 == ctx->r1) {
        // 0x80800A30: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800A64;
    }
    // 0x80800A30: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800A34: beq         $a1, $at, L_80800A94
    if (ctx->r5 == ctx->r1) {
        // 0x80800A38: addiu       $a0, $a2, 0x28
        ctx->r4 = ADD32(ctx->r6, 0X28);
            goto L_80800A94;
    }
    // 0x80800A38: addiu       $a0, $a2, 0x28
    ctx->r4 = ADD32(ctx->r6, 0X28);
    // 0x80800A3C: b           L_80800B58
    // 0x80800A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B58;
    // 0x80800A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A44:
    // 0x80800A44: jal         0x80085710
    // 0x80800A48: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800A48: nop

    after_0:
    // 0x80800A4C: addiu       $a0, $zero, 0x40E
    ctx->r4 = ADD32(0, 0X40E);
    // 0x80800A50: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x80800A54: jal         0x80101180
    // 0x80800A58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_1;
    // 0x80800A58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800A5C: b           L_80800B58
    // 0x80800A60: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800B58;
    // 0x80800A60: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800A64:
    // 0x80800A64: lhu         $t6, 0x72($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X72);
    // 0x80800A68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800A70: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800A74: bne         $t7, $at, L_80800A8C
    if (ctx->r15 != ctx->r1) {
        // 0x80800A78: nop
    
            goto L_80800A8C;
    }
    // 0x80800A78: nop

    // 0x80800A7C: jal         0x80800804
    // 0x80800A80: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800804_chbeanstalkseed(rdram, ctx);
        goto after_2;
    // 0x80800A80: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80800A84: b           L_80800B58
    // 0x80800A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A8C:
    // 0x80800A8C: b           L_80800B58
    // 0x80800A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B58;
    // 0x80800A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A94:
    // 0x80800A94: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80800A98: jal         0x800EE7F8
    // 0x80800A9C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800A9C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800AA0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800AA4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XBBC) << 16);
    // 0x80800AA8: lwc1        $f4, 0xBBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XBBC));
    // 0x80800AAC: lwc1        $f6, 0x38($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X38);
    // 0x80800AB0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XBC0) << 16);
    // 0x80800AB4: lwc1        $f10, 0xBC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XBC0));
    // 0x80800AB8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800ABC: lwc1        $f18, 0x2C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x80800AC0: lhu         $v0, 0x76($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X76);
    // 0x80800AC4: srl         $t8, $v0, 7
    ctx->r24 = S32(U32(ctx->r2) >> 7);
    // 0x80800AC8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80800ACC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800AD0: slti        $at, $t8, 0x33
    ctx->r1 = SIGNED(ctx->r24) < 0X33 ? 1 : 0;
    // 0x80800AD4: addiu       $a0, $v0, 0x325
    ctx->r4 = ADD32(ctx->r2, 0X325);
    // 0x80800AD8: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80800ADC: beq         $at, $zero, L_80800AF0
    if (ctx->r1 == 0) {
        // 0x80800AE0: swc1        $f4, 0x2C($a2)
        MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
            goto L_80800AF0;
    }
    // 0x80800AE0: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x80800AE4: slti        $at, $t8, 0x35
    ctx->r1 = SIGNED(ctx->r24) < 0X35 ? 1 : 0;
    // 0x80800AE8: beq         $at, $zero, L_80800B50
    if (ctx->r1 == 0) {
        // 0x80800AEC: nop
    
            goto L_80800B50;
    }
    // 0x80800AEC: nop

L_80800AF0:
    // 0x80800AF0: jal         0x800DA298
    // 0x80800AF4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800AF4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_4:
    // 0x80800AF8: beq         $v0, $zero, L_80800B14
    if (ctx->r2 == 0) {
        // 0x80800AFC: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800B14;
    }
    // 0x80800AFC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800B00: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800B04: jal         0x80800804
    // 0x80800B08: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800804_chbeanstalkseed(rdram, ctx);
        goto after_5;
    // 0x80800B08: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80800B0C: b           L_80800B58
    // 0x80800B10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800B10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B14:
    // 0x80800B14: lhu         $a0, 0x76($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X76);
    // 0x80800B18: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800B1C: srl         $t9, $a0, 7
    ctx->r25 = S32(U32(ctx->r4) >> 7);
    // 0x80800B20: jal         0x800DA298
    // 0x80800B24: addiu       $a0, $t9, 0x323
    ctx->r4 = ADD32(ctx->r25, 0X323);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800B24: addiu       $a0, $t9, 0x323
    ctx->r4 = ADD32(ctx->r25, 0X323);
    after_6:
    // 0x80800B28: beq         $v0, $zero, L_80800B44
    if (ctx->r2 == 0) {
        // 0x80800B2C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800B44;
    }
    // 0x80800B2C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800B30: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800B34: jal         0x80800804
    // 0x80800B38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800804_chbeanstalkseed(rdram, ctx);
        goto after_7;
    // 0x80800B38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800B3C: b           L_80800B58
    // 0x80800B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B44:
    // 0x80800B44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800B48: jal         0x80800804
    // 0x80800B4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800804_chbeanstalkseed(rdram, ctx);
        goto after_8;
    // 0x80800B4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_80800B50:
    // 0x80800B50: b           L_80800B58
    // 0x80800B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B58:
    // 0x80800B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B60: jr          $ra
    // 0x80800B64: nop

    return;
    // 0x80800B64: nop

;}
RECOMP_FUNC void _chstarspinnerctrl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E00: syscall     245
    recomp_syscall_handler(rdram, ctx, 0x80085E00);
    return;
    // 0x80085E04: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void susplinet_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080120C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801210: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801214: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801218: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080121C: sh          $a1, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r5;
    // 0x80801220: sb          $a2, 0x51($a0)
    MEM_B(0X51, ctx->r4) = ctx->r6;
    // 0x80801224: sb          $a3, 0x52($a0)
    MEM_B(0X52, ctx->r4) = ctx->r7;
    // 0x80801228: sb          $zero, 0x50($a0)
    MEM_B(0X50, ctx->r4) = 0;
    // 0x8080122C: sh          $zero, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = 0;
    // 0x80801230: sb          $zero, 0x58($a0)
    MEM_B(0X58, ctx->r4) = 0;
    // 0x80801234: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x80801238: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x8080123C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801240: jal         0x8080111C
    // 0x80801244: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8080111C_susplinet(rdram, ctx);
        goto after_0;
    // 0x80801244: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080124C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801250: lh          $t6, 0x32($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X32);
    // 0x80801254: lh          $t7, 0x34($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X34);
    // 0x80801258: addu        $t0, $a0, $t6
    ctx->r8 = ADD32(ctx->r4, ctx->r14);
    // 0x8080125C: blez        $s0, L_808012DC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80801260: addu        $t1, $a0, $t7
        ctx->r9 = ADD32(ctx->r4, ctx->r15);
            goto L_808012DC;
    }
    // 0x80801260: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x80801264: andi        $a0, $s0, 0x3
    ctx->r4 = ctx->r16 & 0X3;
    // 0x80801268: beq         $a0, $zero, L_8080129C
    if (ctx->r4 == 0) {
        // 0x8080126C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8080129C;
    }
    // 0x8080126C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801270: sll         $a3, $zero, 1
    ctx->r7 = S32(0 << 1);
    // 0x80801274: addu        $v0, $t0, $a3
    ctx->r2 = ADD32(ctx->r8, ctx->r7);
    // 0x80801278: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x8080127C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80801280:
    // 0x80801280: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80801284: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80801288: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x8080128C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80801290: bne         $a2, $a1, L_80801280
    if (ctx->r6 != ctx->r5) {
        // 0x80801294: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80801280;
    }
    // 0x80801294: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80801298: beq         $a1, $s0, L_808012DC
    if (ctx->r5 == ctx->r16) {
        // 0x8080129C: sll         $a3, $a1, 1
        ctx->r7 = S32(ctx->r5 << 1);
            goto L_808012DC;
    }
L_8080129C:
    // 0x8080129C: sll         $a3, $a1, 1
    ctx->r7 = S32(ctx->r5 << 1);
    // 0x808012A0: addu        $v0, $t0, $a3
    ctx->r2 = ADD32(ctx->r8, ctx->r7);
    // 0x808012A4: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x808012A8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_808012AC:
    // 0x808012AC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x808012B0: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x808012B4: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x808012B8: sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
    // 0x808012BC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x808012C0: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
    // 0x808012C4: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x808012C8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808012CC: sh          $a0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r4;
    // 0x808012D0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x808012D4: bne         $a1, $s0, L_808012AC
    if (ctx->r5 != ctx->r16) {
        // 0x808012D8: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_808012AC;
    }
    // 0x808012D8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_808012DC:
    // 0x808012DC: jal         0x800DA524
    // 0x808012E0: addiu       $a0, $zero, 0x644
    ctx->r4 = ADD32(0, 0X644);
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x808012E0: addiu       $a0, $zero, 0x644
    ctx->r4 = ADD32(0, 0X644);
    after_1:
    // 0x808012E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808012E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808012EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808012F0: jr          $ra
    // 0x808012F4: nop

    return;
    // 0x808012F4: nop

    // 0x808012F8: nop

    // 0x808012FC: nop

;}
RECOMP_FUNC void func_800F57F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F57F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F57F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F57F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F57FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5800: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5804: jal         0x800F3B90
    // 0x800F5808: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F3B90(rdram, ctx);
        goto after_0;
    // 0x800F5808: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F580C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5814: jr          $ra
    // 0x800F5818: nop

    return;
    // 0x800F5818: nop

;}
RECOMP_FUNC void func_80803E94_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803E94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80803E98: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80803E9C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80803EA0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80803EA4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80803EA8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80803EAC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80803EB0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80803EB4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80803EB8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80803EBC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80803EC0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80803EC4: jal         0x80088718
    // 0x80803EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80803EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80803ECC: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80803ED0: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80803ED4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80803ED8: jal         0x80088720
    // 0x80803EDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80803EDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80803EE0: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80803EE4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80803EE8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80803EEC: beq         $t7, $zero, L_80803F60
    if (ctx->r15 == 0) {
        // 0x80803EF0: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80803F60;
    }
    // 0x80803EF0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80803EF4: addiu       $s5, $zero, 0x7E
    ctx->r21 = ADD32(0, 0X7E);
    // 0x80803EF8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80803EFC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80803F00:
    // 0x80803F00: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80803F04: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80803F08: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x80803F0C: bne         $s5, $v0, L_80803F48
    if (ctx->r21 != ctx->r2) {
        // 0x80803F10: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803F48;
    }
    // 0x80803F10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803F14: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80803F18: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80803F1C: jal         0x800E6DB4
    // 0x80803F20: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_2;
    // 0x80803F20: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    after_2:
    // 0x80803F24: lbu         $t0, 0x0($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X0);
    // 0x80803F28: beql        $t0, $zero, L_80803F54
    if (ctx->r8 == 0) {
        // 0x80803F2C: lbu         $t2, 0x1($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X1);
            goto L_80803F54;
    }
    goto skip_0;
    // 0x80803F2C: lbu         $t2, 0x1($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1);
    skip_0:
    // 0x80803F30: lbu         $t1, 0x1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1);
L_80803F34:
    // 0x80803F34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80803F38: bnel        $t1, $zero, L_80803F34
    if (ctx->r9 != 0) {
        // 0x80803F3C: lbu         $t1, 0x1($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X1);
            goto L_80803F34;
    }
    goto skip_1;
    // 0x80803F3C: lbu         $t1, 0x1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1);
    skip_1:
    // 0x80803F40: b           L_80803F54
    // 0x80803F44: lbu         $t2, 0x1($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1);
        goto L_80803F54;
    // 0x80803F44: lbu         $t2, 0x1($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1);
L_80803F48:
    // 0x80803F48: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80803F4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80803F50: lbu         $t2, 0x1($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1);
L_80803F54:
    // 0x80803F54: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80803F58: bnel        $t2, $zero, L_80803F00
    if (ctx->r10 != 0) {
        // 0x80803F5C: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_80803F00;
    }
    goto skip_2;
    // 0x80803F5C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    skip_2:
L_80803F60:
    // 0x80803F60: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80803F64: jal         0x80088728
    // 0x80803F68: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80803F68: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80803F6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80803F70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80803F74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80803F78: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80803F7C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80803F80: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80803F84: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80803F88: jr          $ra
    // 0x80803F8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80803F8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void sccustom_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008E0: jal         0x8080084C
    // 0x808008E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080084C_sccustom(rdram, ctx);
        goto after_0;
    // 0x808008E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008EC: jal         0x808006C4
    // 0x808008F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808006C4_sccustom(rdram, ctx);
        goto after_1;
    // 0x808008F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808008F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008FC: jr          $ra
    // 0x80800900: nop

    return;
    // 0x80800900: nop

    // 0x80800904: nop

    // 0x80800908: nop

    // 0x8080090C: nop

;}
RECOMP_FUNC void chdinotraindoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001BC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2048, 0X1D0) << 16);
    // 0x808001C0: jr          $ra
    // 0x808001C4: addiu       $v0, $v0, 0x1D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2048, 0X1D0));
    return;
    // 0x808001C4: addiu       $v0, $v0, 0x1D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2048, 0X1D0));
    // 0x808001C8: nop

    // 0x808001CC: nop

;}
RECOMP_FUNC void chcrusher_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1624, 0XCC8) << 16);
    // 0x808008F4: jr          $ra
    // 0x808008F8: addiu       $v0, $v0, 0xCC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1624, 0XCC8));
    return;
    // 0x808008F8: addiu       $v0, $v0, 0xCC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1624, 0XCC8));
;}
RECOMP_FUNC void _dbvpl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879A8: syscall     644
    recomp_syscall_handler(rdram, ctx, 0x800879A8);
    return;
    // 0x800879AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F53A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F53A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F53A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F53AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F53B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F53B4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F53B8: jal         0x8008E938
    // 0x800F53BC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008E938(rdram, ctx);
        goto after_0;
    // 0x800F53BC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F53C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F53C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F53C8: jr          $ra
    // 0x800F53CC: nop

    return;
    // 0x800F53CC: nop

;}
RECOMP_FUNC void _subaddiedialog_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1D8: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A1D8);
    return;
    // 0x8008A1DC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800E7F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7F60: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E7F64: addiu       $v1, $v1, -0x2A30
    ctx->r3 = ADD32(ctx->r3, -0X2A30);
    // 0x800E7F68: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x800E7F6C: lh          $v0, 0xE($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XE);
    // 0x800E7F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E7F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7F78: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800E7F7C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800E7F80: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
    // 0x800E7F84: sh          $v0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r2;
    // 0x800E7F88: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // 0x800E7F8C: lh          $a3, 0x7752($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X7752);
    // 0x800E7F90: lh          $a2, 0x7750($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X7750);
    // 0x800E7F94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800E7F98: jal         0x800E7FB0
    // 0x800E7F9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800E7FB0(rdram, ctx);
        goto after_0;
    // 0x800E7F9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800E7FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E7FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E7FA8: jr          $ra
    // 0x800E7FAC: nop

    return;
    // 0x800E7FAC: nop

;}
RECOMP_FUNC void chpickups_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(700, 0X790) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x790
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X790));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x790
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X790));
;}
RECOMP_FUNC void baboost_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800B7448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7448: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800B744C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800B7450: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B7454: addiu       $s2, $s2, -0x7E80
    ctx->r18 = ADD32(ctx->r18, -0X7E80);
    // 0x800B7458: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800B745C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800B7460: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800B7464: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800B7468: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800B746C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800B7470: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800B7474: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800B7478: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800B747C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800B7480: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800B7484: beq         $a1, $zero, L_800B7950
    if (ctx->r5 == 0) {
        // 0x800B7488: sdc1        $f20, 0x20($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
            goto L_800B7950;
    }
    // 0x800B7488: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800B748C: jal         0x800B2928
    // 0x800B7490: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    vector_size(rdram, ctx);
        goto after_0;
    // 0x800B7490: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800B7494: blez        $v0, L_800B7950
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B7498: nop
    
            goto L_800B7950;
    }
    // 0x800B7498: nop

    // 0x800B749C: jal         0x800E79E8
    // 0x800B74A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800E79E8(rdram, ctx);
        goto after_1;
    // 0x800B74A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x800B74A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B74A8: jal         0x800E7988
    // 0x800B74AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800E7988(rdram, ctx);
        goto after_2;
    // 0x800B74AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800B74B0: jal         0x800B28C4
    // 0x800B74B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    vector_begin(rdram, ctx);
        goto after_3;
    // 0x800B74B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_3:
    // 0x800B74B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B74BC: jal         0x800B296C
    // 0x800B74C0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    vector_end(rdram, ctx);
        goto after_4;
    // 0x800B74C0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_4:
    // 0x800B74C4: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800B74C8: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x800B74CC: beq         $at, $zero, L_800B7940
    if (ctx->r1 == 0) {
        // 0x800B74D0: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_800B7940;
    }
    // 0x800B74D0: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800B74D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B74D8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800B74DC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800B74E0: addiu       $s6, $sp, 0x84
    ctx->r22 = ADD32(ctx->r29, 0X84);
    // 0x800B74E4: addiu       $s5, $sp, 0x88
    ctx->r21 = ADD32(ctx->r29, 0X88);
    // 0x800B74E8: lhu         $a0, 0x6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X6);
L_800B74EC:
    // 0x800B74EC: srl         $t6, $a0, 12
    ctx->r14 = S32(U32(ctx->r4) >> 12);
    // 0x800B74F0: jal         0x800D3724
    // 0x800B74F4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800D3724(rdram, ctx);
        goto after_5;
    // 0x800B74F4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_5:
    // 0x800B74F8: beq         $v0, $zero, L_800B792C
    if (ctx->r2 == 0) {
        // 0x800B74FC: sw          $v0, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r2;
            goto L_800B792C;
    }
    // 0x800B74FC: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x800B7500: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x800B7504: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B7508: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B750C: nop

    // 0x800B7510: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B7514: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x800B7518: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x800B751C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800B7520: nop

    // 0x800B7524: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B7528: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x800B752C: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x800B7530: sll         $t2, $t0, 21
    ctx->r10 = S32(ctx->r8 << 21);
    // 0x800B7534: bgezl       $t2, L_800B7898
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B7538: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800B7898;
    }
    goto skip_0;
    // 0x800B7538: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
    // 0x800B753C: lhu         $a0, 0x6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X6);
    // 0x800B7540: srl         $t3, $a0, 12
    ctx->r11 = S32(U32(ctx->r4) >> 12);
    // 0x800B7544: jal         0x800D35BC
    // 0x800B7548: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800D35BC(rdram, ctx);
        goto after_6;
    // 0x800B7548: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_6:
    // 0x800B754C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800B7550: jal         0x800E7188
    // 0x800B7554: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    func_800E7188(rdram, ctx);
        goto after_7;
    // 0x800B7554: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    after_7:
    // 0x800B7558: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x800B755C: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7560: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B7564: addiu       $a1, $a1, -0x59E0
    ctx->r5 = ADD32(ctx->r5, -0X59E0);
    // 0x800B7568: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B756C: mflo        $t5
    ctx->r13 = lo;
    // 0x800B7570: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800B7574: jal         0x800E7828
    // 0x800B7578: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
    func_800E7828(rdram, ctx);
        goto after_8;
    // 0x800B7578: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
    after_8:
    // 0x800B757C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B7580: jal         0x800E7778
    // 0x800B7584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800E7778(rdram, ctx);
        goto after_9;
    // 0x800B7584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800B7588: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B758C: jal         0x800E76A4
    // 0x800B7590: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800E76A4(rdram, ctx);
        goto after_10;
    // 0x800B7590: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x800B7594: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B7598: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B759C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B75A0: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800B75A4: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B75A8: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B75AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B75B0: bgez        $s3, L_800B75C0
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800B75B4: sra         $t7, $s3, 1
        ctx->r15 = S32(SIGNED(ctx->r19) >> 1);
            goto L_800B75C0;
    }
    // 0x800B75B4: sra         $t7, $s3, 1
    ctx->r15 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800B75B8: addiu       $at, $s3, 0x1
    ctx->r1 = ADD32(ctx->r19, 0X1);
    // 0x800B75BC: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800B75C0:
    // 0x800B75C0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800B75C4: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800B75C8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B75CC: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B75D0: add.s       $f0, $f6, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800B75D4: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800B75D8: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800B75DC: add.s       $f12, $f10, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x800B75E0: bc1fl       L_800B75F4
    if (!c1cs) {
        // 0x800B75E4: mov.s       $f2, $f22
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
            goto L_800B75F4;
    }
    goto skip_1;
    // 0x800B75E4: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
    skip_1:
    // 0x800B75E8: b           L_800B75F4
    // 0x800B75EC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_800B75F4;
    // 0x800B75EC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800B75F0: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
L_800B75F4:
    // 0x800B75F4: c.lt.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl < ctx->f12.fl;
    // 0x800B75F8: nop

    // 0x800B75FC: bc1fl       L_800B7610
    if (!c1cs) {
        // 0x800B7600: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_800B7610;
    }
    goto skip_2;
    // 0x800B7600: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_2:
    // 0x800B7604: b           L_800B7610
    // 0x800B7608: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800B7610;
    // 0x800B7608: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800B760C: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_800B7610:
    // 0x800B7610: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B7614: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B7618: nop

    // 0x800B761C: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800B7620: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B7624: nop

    // 0x800B7628: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800B762C: beql        $t9, $zero, L_800B767C
    if (ctx->r25 == 0) {
        // 0x800B7630: mfc1        $t9, $f16
        ctx->r25 = (int32_t)ctx->f16.u32l;
            goto L_800B767C;
    }
    goto skip_3;
    // 0x800B7630: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x800B7634: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B7638: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B763C: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800B7640: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B7644: nop

    // 0x800B7648: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B764C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B7650: nop

    // 0x800B7654: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800B7658: bne         $t9, $zero, L_800B7670
    if (ctx->r25 != 0) {
        // 0x800B765C: nop
    
            goto L_800B7670;
    }
    // 0x800B765C: nop

    // 0x800B7660: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x800B7664: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B7668: b           L_800B7688
    // 0x800B766C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800B7688;
    // 0x800B766C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800B7670:
    // 0x800B7670: b           L_800B7688
    // 0x800B7674: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800B7688;
    // 0x800B7674: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800B7678: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
L_800B767C:
    // 0x800B767C: nop

    // 0x800B7680: bltz        $t9, L_800B7670
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B7684: nop
    
            goto L_800B7670;
    }
    // 0x800B7684: nop

L_800B7688:
    // 0x800B7688: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B768C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800B7690: andi        $t0, $t9, 0x3FF
    ctx->r8 = ctx->r25 & 0X3FF;
    // 0x800B7694: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B7698: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B769C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B76A0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800B76A4: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x800B76A8: cvt.w.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800B76AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B76B0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B76B4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B76B8: nop

    // 0x800B76BC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800B76C0: beql        $t4, $zero, L_800B7710
    if (ctx->r12 == 0) {
        // 0x800B76C4: mfc1        $t4, $f18
        ctx->r12 = (int32_t)ctx->f18.u32l;
            goto L_800B7710;
    }
    goto skip_4;
    // 0x800B76C4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    skip_4:
    // 0x800B76C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B76CC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800B76D0: sub.s       $f18, $f2, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x800B76D4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B76D8: nop

    // 0x800B76DC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B76E0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B76E4: nop

    // 0x800B76E8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800B76EC: bne         $t4, $zero, L_800B7704
    if (ctx->r12 != 0) {
        // 0x800B76F0: nop
    
            goto L_800B7704;
    }
    // 0x800B76F0: nop

    // 0x800B76F4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800B76F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B76FC: b           L_800B771C
    // 0x800B7700: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800B771C;
    // 0x800B7700: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800B7704:
    // 0x800B7704: b           L_800B771C
    // 0x800B7708: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800B771C;
    // 0x800B7708: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B770C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
L_800B7710:
    // 0x800B7710: nop

    // 0x800B7714: bltz        $t4, L_800B7704
    if (SIGNED(ctx->r12) < 0) {
        // 0x800B7718: nop
    
            goto L_800B7704;
    }
    // 0x800B7718: nop

L_800B771C:
    // 0x800B771C: andi        $t5, $t4, 0x3FF
    ctx->r13 = ctx->r12 & 0X3FF;
    // 0x800B7720: sll         $t6, $t5, 14
    ctx->r14 = S32(ctx->r13 << 14);
    // 0x800B7724: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x800B7728: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B772C: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B7730: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B7734: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B7738: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B773C: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800B7740: c.lt.s      $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f24.fl < ctx->f12.fl;
    // 0x800B7744: nop

    // 0x800B7748: bc1fl       L_800B775C
    if (!c1cs) {
        // 0x800B774C: mov.s       $f2, $f22
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
            goto L_800B775C;
    }
    goto skip_5;
    // 0x800B774C: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
    skip_5:
    // 0x800B7750: b           L_800B775C
    // 0x800B7754: sub.s       $f2, $f12, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f24.fl;
        goto L_800B775C;
    // 0x800B7754: sub.s       $f2, $f12, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f24.fl;
    // 0x800B7758: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
L_800B775C:
    // 0x800B775C: sub.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x800B7760: c.lt.s      $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f24.fl < ctx->f12.fl;
    // 0x800B7764: nop

    // 0x800B7768: bc1fl       L_800B777C
    if (!c1cs) {
        // 0x800B776C: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_800B777C;
    }
    goto skip_6;
    // 0x800B776C: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_6:
    // 0x800B7770: b           L_800B777C
    // 0x800B7774: sub.s       $f0, $f12, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f24.fl;
        goto L_800B777C;
    // 0x800B7774: sub.s       $f0, $f12, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f24.fl;
    // 0x800B7778: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_800B777C:
    // 0x800B777C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B7780: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B7784: nop

    // 0x800B7788: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800B778C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B7790: nop

    // 0x800B7794: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800B7798: beql        $t9, $zero, L_800B77E8
    if (ctx->r25 == 0) {
        // 0x800B779C: mfc1        $t9, $f8
        ctx->r25 = (int32_t)ctx->f8.u32l;
            goto L_800B77E8;
    }
    goto skip_7;
    // 0x800B779C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    skip_7:
    // 0x800B77A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B77A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B77A8: sub.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800B77AC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B77B0: nop

    // 0x800B77B4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B77B8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B77BC: nop

    // 0x800B77C0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800B77C4: bne         $t9, $zero, L_800B77DC
    if (ctx->r25 != 0) {
        // 0x800B77C8: nop
    
            goto L_800B77DC;
    }
    // 0x800B77C8: nop

    // 0x800B77CC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800B77D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B77D4: b           L_800B77F4
    // 0x800B77D8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800B77F4;
    // 0x800B77D8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800B77DC:
    // 0x800B77DC: b           L_800B77F4
    // 0x800B77E0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800B77F4;
    // 0x800B77E0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800B77E4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
L_800B77E8:
    // 0x800B77E8: nop

    // 0x800B77EC: bltz        $t9, L_800B77DC
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B77F0: nop
    
            goto L_800B77DC;
    }
    // 0x800B77F0: nop

L_800B77F4:
    // 0x800B77F4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B77F8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800B77FC: andi        $t0, $t9, 0x3FF
    ctx->r8 = ctx->r25 & 0X3FF;
    // 0x800B7800: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B7804: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B7808: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B780C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B7810: cvt.w.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800B7814: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B7818: nop

    // 0x800B781C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800B7820: beql        $t4, $zero, L_800B7870
    if (ctx->r12 == 0) {
        // 0x800B7824: mfc1        $t4, $f10
        ctx->r12 = (int32_t)ctx->f10.u32l;
            goto L_800B7870;
    }
    goto skip_8;
    // 0x800B7824: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    skip_8:
    // 0x800B7828: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B782C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800B7830: sub.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800B7834: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B7838: nop

    // 0x800B783C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B7840: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B7844: nop

    // 0x800B7848: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800B784C: bne         $t4, $zero, L_800B7864
    if (ctx->r12 != 0) {
        // 0x800B7850: nop
    
            goto L_800B7864;
    }
    // 0x800B7850: nop

    // 0x800B7854: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800B7858: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B785C: b           L_800B787C
    // 0x800B7860: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800B787C;
    // 0x800B7860: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800B7864:
    // 0x800B7864: b           L_800B787C
    // 0x800B7868: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800B787C;
    // 0x800B7868: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B786C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
L_800B7870:
    // 0x800B7870: nop

    // 0x800B7874: bltz        $t4, L_800B7864
    if (SIGNED(ctx->r12) < 0) {
        // 0x800B7878: nop
    
            goto L_800B7864;
    }
    // 0x800B7878: nop

L_800B787C:
    // 0x800B787C: andi        $t5, $t4, 0x3FF
    ctx->r13 = ctx->r12 & 0X3FF;
    // 0x800B7880: sll         $t2, $t5, 14
    ctx->r10 = S32(ctx->r13 << 14);
    // 0x800B7884: or          $t6, $t1, $t2
    ctx->r14 = ctx->r9 | ctx->r10;
    // 0x800B7888: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B788C: jal         0x800E7694
    // 0x800B7890: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    func_800E7694(rdram, ctx);
        goto after_11;
    // 0x800B7890: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    after_11:
    // 0x800B7894: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_800B7898:
    // 0x800B7898: jal         0x800B71F4
    // 0x800B789C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800B71F4(rdram, ctx);
        goto after_12;
    // 0x800B789C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x800B78A0: jal         0x800B7174
    // 0x800B78A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B7174(rdram, ctx);
        goto after_13;
    // 0x800B78A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800B78A8: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800B78AC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800B78B0: bnel        $t7, $zero, L_800B78D4
    if (ctx->r15 != 0) {
        // 0x800B78B4: lwc1        $f16, 0x8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
            goto L_800B78D4;
    }
    goto skip_9;
    // 0x800B78B4: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    skip_9:
    // 0x800B78B8: lbu         $t8, 0x1D($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X1D);
    // 0x800B78BC: bnel        $t8, $zero, L_800B78D4
    if (ctx->r24 != 0) {
        // 0x800B78C0: lwc1        $f16, 0x8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
            goto L_800B78D4;
    }
    goto skip_10;
    // 0x800B78C0: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    skip_10:
    // 0x800B78C4: lbu         $t9, 0x1C($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X1C);
    // 0x800B78C8: beql        $t9, $zero, L_800B7930
    if (ctx->r25 == 0) {
        // 0x800B78CC: lw          $t6, 0x78($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X78);
            goto L_800B7930;
    }
    goto skip_11;
    // 0x800B78CC: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    skip_11:
    // 0x800B78D0: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
L_800B78D4:
    // 0x800B78D4: addu        $t0, $v0, $s0
    ctx->r8 = ADD32(ctx->r2, ctx->r16);
    // 0x800B78D8: lbu         $a1, 0x0($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X0);
    // 0x800B78DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B78E0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800B78E4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800B78E8: jal         0x800B62CC
    // 0x800B78EC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800B62CC(rdram, ctx);
        goto after_14;
    // 0x800B78EC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_14:
    // 0x800B78F0: lw          $t3, 0x4($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X4);
    // 0x800B78F4: beql        $t3, $zero, L_800B7930
    if (ctx->r11 == 0) {
        // 0x800B78F8: lw          $t6, 0x78($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X78);
            goto L_800B7930;
    }
    goto skip_12;
    // 0x800B78F8: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    skip_12:
    // 0x800B78FC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800B7900: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B7904: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x800B7908: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800B790C: bnel        $t5, $zero, L_800B78D4
    if (ctx->r13 != 0) {
        // 0x800B7910: lwc1        $f16, 0x8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
            goto L_800B78D4;
    }
    goto skip_13;
    // 0x800B7910: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    skip_13:
    // 0x800B7914: lbu         $t1, 0x1D($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X1D);
    // 0x800B7918: bnel        $t1, $zero, L_800B78D4
    if (ctx->r9 != 0) {
        // 0x800B791C: lwc1        $f16, 0x8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
            goto L_800B78D4;
    }
    goto skip_14;
    // 0x800B791C: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    skip_14:
    // 0x800B7920: lbu         $t2, 0x1C($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X1C);
    // 0x800B7924: bnel        $t2, $zero, L_800B78D4
    if (ctx->r10 != 0) {
        // 0x800B7928: lwc1        $f16, 0x8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
            goto L_800B78D4;
    }
    goto skip_15;
    // 0x800B7928: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    skip_15:
L_800B792C:
    // 0x800B792C: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
L_800B7930:
    // 0x800B7930: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x800B7934: sltu        $at, $s1, $t6
    ctx->r1 = ctx->r17 < ctx->r14 ? 1 : 0;
    // 0x800B7938: bnel        $at, $zero, L_800B74EC
    if (ctx->r1 != 0) {
        // 0x800B793C: lhu         $a0, 0x6($s1)
        ctx->r4 = MEM_HU(ctx->r17, 0X6);
            goto L_800B74EC;
    }
    goto skip_16;
    // 0x800B793C: lhu         $a0, 0x6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X6);
    skip_16:
L_800B7940:
    // 0x800B7940: jal         0x800E7A4C
    // 0x800B7944: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800E7A4C(rdram, ctx);
        goto after_15;
    // 0x800B7944: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_15:
    // 0x800B7948: jal         0x800B28B8
    // 0x800B794C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    vector_clear(rdram, ctx);
        goto after_16;
    // 0x800B794C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_16:
L_800B7950:
    // 0x800B7950: jal         0x800B7A98
    // 0x800B7954: nop

    func_800B7A98(rdram, ctx);
        goto after_17;
    // 0x800B7954: nop

    after_17:
    // 0x800B7958: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800B795C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800B7960: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800B7964: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800B7968: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800B796C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800B7970: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800B7974: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800B7978: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800B797C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800B7980: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800B7984: jr          $ra
    // 0x800B7988: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800B7988: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800E72E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E72E0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800E72E4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800E72E8: beq         $t6, $zero, L_800E731C
    if (ctx->r14 == 0) {
        // 0x800E72EC: nop
    
            goto L_800E731C;
    }
    // 0x800E72EC: nop

    // 0x800E72F0: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800E72F4: slti        $at, $v1, 0x61
    ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
L_800E72F8:
    // 0x800E72F8: bne         $at, $zero, L_800E730C
    if (ctx->r1 != 0) {
        // 0x800E72FC: slti        $at, $v1, 0x7B
        ctx->r1 = SIGNED(ctx->r3) < 0X7B ? 1 : 0;
            goto L_800E730C;
    }
    // 0x800E72FC: slti        $at, $v1, 0x7B
    ctx->r1 = SIGNED(ctx->r3) < 0X7B ? 1 : 0;
    // 0x800E7300: beq         $at, $zero, L_800E730C
    if (ctx->r1 == 0) {
        // 0x800E7304: addiu       $t7, $v1, -0x20
        ctx->r15 = ADD32(ctx->r3, -0X20);
            goto L_800E730C;
    }
    // 0x800E7304: addiu       $t7, $v1, -0x20
    ctx->r15 = ADD32(ctx->r3, -0X20);
    // 0x800E7308: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_800E730C:
    // 0x800E730C: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x800E7310: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E7314: bnel        $v1, $zero, L_800E72F8
    if (ctx->r3 != 0) {
        // 0x800E7318: slti        $at, $v1, 0x61
        ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
            goto L_800E72F8;
    }
    goto skip_0;
    // 0x800E7318: slti        $at, $v1, 0x61
    ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
    skip_0:
L_800E731C:
    // 0x800E731C: jr          $ra
    // 0x800E7320: nop

    return;
    // 0x800E7320: nop

;}
RECOMP_FUNC void func_80800098_chfairgroundworker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080009C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A0: jal         0x8008A108
    // 0x808000A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _sucoaster_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808000A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(840, 0X264) << 16);
    // 0x808000B0: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x808000B4: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808000B8: bgezl       $t8, L_808000F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000F0;
    }
    goto skip_0;
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000C0: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x808000C4: lwc1        $f6, 0x264($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(840, 0X264));
    // 0x808000C8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(840, 0X428) << 16);
    // 0x808000CC: addiu       $t9, $t9, 0x428
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(840, 0X428));
    // 0x808000D0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808000D4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808000D8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808000DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808000E0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x808000E4: jal         0x80085780
    // 0x808000E8: nop

    _chbadshad_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808000E8: nop

    after_1:
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F0:
    // 0x808000F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
