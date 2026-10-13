#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808010C4_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808010C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808010CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808010D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808010D4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808010D8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x808010DC: jal         0x8008A0E0
    // 0x808010E0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808010E0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x808010E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808010E8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808010EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010F0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808010F4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x808010F8: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x808010FC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80801100: jal         0x80800F60
    // 0x80801104: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_80800F60_chevilmumbo(rdram, ctx);
        goto after_1;
    // 0x80801104: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80801108: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080110C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801110: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801114: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1676, 0X42D0) << 16);
    // 0x80801118: addiu       $t6, $t6, 0x42D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1676, 0X42D0));
    // 0x8080111C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801120: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801124: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801128: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8080112C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801130: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80801134: jal         0x800BABB8
    // 0x80801138: nop

    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80801138: nop

    after_2:
    // 0x8080113C: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801140: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80801144: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801148: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080114C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801150: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801154: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801158: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080115C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801160: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80801164: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80801168: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8080116C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80801170: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x80801174: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80801178: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x8080117C: jal         0x800BA77C
    // 0x80801180: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_3;
    // 0x80801180: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    after_3:
    // 0x80801184: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801188: jal         0x800BA22C
    // 0x8080118C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_4;
    // 0x8080118C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80801190: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X42F4) << 16);
    // 0x80801194: addiu       $a2, $a2, 0x42F4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X42F4));
    // 0x80801198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080119C: jal         0x80089D18
    // 0x808011A0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808011A0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x808011A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808011A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808011AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808011B0: jr          $ra
    // 0x808011B4: nop

    return;
    // 0x808011B4: nop

;}
RECOMP_FUNC void func_800DBF38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBF38: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800DBF3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DBF40: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800DBF44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DBF48: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800DBF4C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800DBF50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBF54: addu        $a1, $a3, $t7
    ctx->r5 = ADD32(ctx->r7, ctx->r15);
    // 0x800DBF58: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800DBF5C: jal         0x800EE904
    // 0x800DBF60: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x800DBF60: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800DBF64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DBF68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DBF6C: jr          $ra
    // 0x800DBF70: nop

    return;
    // 0x800DBF70: nop

;}
RECOMP_FUNC void bsdronelook_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800134: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800138: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080013C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800144: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80800148: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8080014C: lui         $at, 0xC282
    ctx->r1 = S32(0XC282 << 16);
    // 0x80800150: bc1fl       L_80800174
    if (!c1cs) {
        // 0x80800154: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80800174;
    }
    goto skip_0;
    // 0x80800154: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x80800158: lui         $at, 0x4392
    ctx->r1 = S32(0X4392 << 16);
    // 0x8080015C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800160: jal         0x800F0E00
    // 0x80800164: nop

    func_800F0E00(rdram, ctx);
        goto after_0;
    // 0x80800164: nop

    after_0:
    // 0x80800168: b           L_808001A8
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001A8;
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800170: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80800174:
    // 0x80800174: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800178: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8080017C: nop

    // 0x80800180: bc1fl       L_8080019C
    if (!c1cs) {
        // 0x80800184: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_8080019C;
    }
    goto skip_1;
    // 0x80800184: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_1:
    // 0x80800188: jal         0x800F0E00
    // 0x8080018C: nop

    func_800F0E00(rdram, ctx);
        goto after_1;
    // 0x8080018C: nop

    after_1:
    // 0x80800190: b           L_808001A8
    // 0x80800194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001A8;
    // 0x80800194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800198: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_8080019C:
    // 0x8080019C: jal         0x800F13F0
    // 0x808001A0: nop

    func_800F13F0(rdram, ctx);
        goto after_2;
    // 0x808001A0: nop

    after_2:
    // 0x808001A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001A8:
    // 0x808001A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void func_8010E4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E4C4: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8010E4C8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8010E4CC: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x8010E4D0: addiu       $s6, $s6, 0x7060
    ctx->r22 = ADD32(ctx->r22, 0X7060);
    // 0x8010E4D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010E4D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8010E4DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010E4E0: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x8010E4E4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8010E4E8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8010E4EC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8010E4F0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8010E4F4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8010E4F8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8010E4FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8010E500: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8010E504: jal         0x800DF8B4
    // 0x8010E508: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_800DF8B4(rdram, ctx);
        goto after_0;
    // 0x8010E508: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_0:
    // 0x8010E50C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8010E510: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x8010E514: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8010E518: addu        $s5, $t7, $v0
    ctx->r21 = ADD32(ctx->r15, ctx->r2);
    // 0x8010E51C: jal         0x800DF8CC
    // 0x8010E520: addiu       $s5, $s5, 0x18
    ctx->r21 = ADD32(ctx->r21, 0X18);
    func_800DF8CC(rdram, ctx);
        goto after_1;
    // 0x8010E520: addiu       $s5, $s5, 0x18
    ctx->r21 = ADD32(ctx->r21, 0X18);
    after_1:
    // 0x8010E524: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8010E528: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x8010E52C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8010E530: jal         0x800DF8BC
    // 0x8010E534: addu        $fp, $t9, $v0
    ctx->r30 = ADD32(ctx->r25, ctx->r2);
    func_800DF8BC(rdram, ctx);
        goto after_2;
    // 0x8010E534: addu        $fp, $t9, $v0
    ctx->r30 = ADD32(ctx->r25, ctx->r2);
    after_2:
    // 0x8010E538: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8010E53C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8010E540: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E544: addu        $t3, $v1, $s1
    ctx->r11 = ADD32(ctx->r3, ctx->r17);
    // 0x8010E548: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8010E54C: lbu         $t4, 0x11($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X11);
    // 0x8010E550: mflo        $t1
    ctx->r9 = lo;
    // 0x8010E554: addu        $s3, $t1, $v0
    ctx->r19 = ADD32(ctx->r9, ctx->r2);
    // 0x8010E558: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x8010E55C: multu       $s1, $a0
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E560: mflo        $t2
    ctx->r10 = lo;
    // 0x8010E564: addu        $s7, $t2, $s3
    ctx->r23 = ADD32(ctx->r10, ctx->r19);
    // 0x8010E568: beq         $t4, $zero, L_8010E764
    if (ctx->r12 == 0) {
        // 0x8010E56C: or          $s4, $s7, $zero
        ctx->r20 = ctx->r23 | 0;
            goto L_8010E764;
    }
    // 0x8010E56C: or          $s4, $s7, $zero
    ctx->r20 = ctx->r23 | 0;
    // 0x8010E570: sltu        $at, $s3, $s7
    ctx->r1 = ctx->r19 < ctx->r23 ? 1 : 0;
    // 0x8010E574: lw          $v0, 0x4($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X4);
    // 0x8010E578: lw          $v1, 0x8($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X8);
    // 0x8010E57C: beq         $at, $zero, L_8010E59C
    if (ctx->r1 == 0) {
        // 0x8010E580: lw          $a0, 0xC($s6)
        ctx->r4 = MEM_W(ctx->r22, 0XC);
            goto L_8010E59C;
    }
    // 0x8010E580: lw          $a0, 0xC($s6)
    ctx->r4 = MEM_W(ctx->r22, 0XC);
L_8010E584:
    // 0x8010E584: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8010E588: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x8010E58C: sh          $v0, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r2;
    // 0x8010E590: sh          $v1, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r3;
    // 0x8010E594: bne         $at, $zero, L_8010E584
    if (ctx->r1 != 0) {
        // 0x8010E598: sh          $a0, -0x6($s0)
        MEM_H(-0X6, ctx->r16) = ctx->r4;
            goto L_8010E584;
    }
    // 0x8010E598: sh          $a0, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r4;
L_8010E59C:
    // 0x8010E59C: lw          $s2, 0x18($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X18);
    // 0x8010E5A0: lw          $t5, 0x1C($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X1C);
    // 0x8010E5A4: sltu        $at, $s2, $t5
    ctx->r1 = ctx->r18 < ctx->r13 ? 1 : 0;
    // 0x8010E5A8: beql        $at, $zero, L_8010E6CC
    if (ctx->r1 == 0) {
        // 0x8010E5AC: sltu        $at, $s3, $s7
        ctx->r1 = ctx->r19 < ctx->r23 ? 1 : 0;
            goto L_8010E6CC;
    }
    goto skip_0;
    // 0x8010E5AC: sltu        $at, $s3, $s7
    ctx->r1 = ctx->r19 < ctx->r23 ? 1 : 0;
    skip_0:
    // 0x8010E5B0: lbu         $t6, 0x10($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X10);
L_8010E5B4:
    // 0x8010E5B4: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x8010E5B8: or          $s1, $fp, $zero
    ctx->r17 = ctx->r30 | 0;
    // 0x8010E5BC: beq         $t6, $zero, L_8010E5E0
    if (ctx->r14 == 0) {
        // 0x8010E5C0: lw          $a0, 0xB0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XB0);
            goto L_8010E5E0;
    }
    // 0x8010E5C0: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x8010E5C4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8010E5C8: jal         0x8010E3C4
    // 0x8010E5CC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8010E3C4(rdram, ctx);
        goto after_3;
    // 0x8010E5CC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x8010E5D0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8010E5D4: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8010E5D8: b           L_8010E608
    // 0x8010E5DC: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
        goto L_8010E608;
    // 0x8010E5DC: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
L_8010E5E0:
    // 0x8010E5E0: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8010E5E4: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8010E5E8: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8010E5EC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8010E5F0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8010E5F4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8010E5F8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8010E5FC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8010E600: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x8010E604: nop

L_8010E608:
    // 0x8010E608: sltu        $at, $s3, $s7
    ctx->r1 = ctx->r19 < ctx->r23 ? 1 : 0;
    // 0x8010E60C: lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XC);
    // 0x8010E610: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x8010E614: beq         $at, $zero, L_8010E6B4
    if (ctx->r1 == 0) {
        // 0x8010E618: lw          $a1, 0x14($s2)
        ctx->r5 = MEM_W(ctx->r18, 0X14);
            goto L_8010E6B4;
    }
    // 0x8010E618: lw          $a1, 0x14($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X14);
L_8010E61C:
    // 0x8010E61C: lb          $t1, 0x2($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X2);
    // 0x8010E620: lb          $t3, 0x0($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X0);
    // 0x8010E624: lb          $t6, 0x1($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1);
    // 0x8010E628: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E62C: mflo        $t2
    ctx->r10 = lo;
    // 0x8010E630: nop

    // 0x8010E634: nop

    // 0x8010E638: multu       $a2, $t3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E63C: mflo        $t4
    ctx->r12 = lo;
    // 0x8010E640: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8010E644: nop

    // 0x8010E648: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E64C: mflo        $t7
    ctx->r15 = lo;
    // 0x8010E650: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x8010E654: blezl       $v0, L_8010E6A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8010E658: addiu       $s0, $s0, 0xA
        ctx->r16 = ADD32(ctx->r16, 0XA);
            goto L_8010E6A8;
    }
    goto skip_1;
    // 0x8010E658: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    skip_1:
    // 0x8010E65C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E660: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8010E664: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x8010E668: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x8010E66C: mflo        $t9
    ctx->r25 = lo;
    // 0x8010E670: sra         $t1, $t9, 15
    ctx->r9 = S32(SIGNED(ctx->r25) >> 15);
    // 0x8010E674: addu        $t3, $t8, $t1
    ctx->r11 = ADD32(ctx->r24, ctx->r9);
    // 0x8010E678: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E67C: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
    // 0x8010E680: mflo        $t4
    ctx->r12 = lo;
    // 0x8010E684: sra         $t6, $t4, 15
    ctx->r14 = S32(SIGNED(ctx->r12) >> 15);
    // 0x8010E688: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x8010E68C: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E690: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x8010E694: mflo        $t9
    ctx->r25 = lo;
    // 0x8010E698: sra         $t8, $t9, 15
    ctx->r24 = S32(SIGNED(ctx->r25) >> 15);
    // 0x8010E69C: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8010E6A0: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    // 0x8010E6A4: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
L_8010E6A8:
    // 0x8010E6A8: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x8010E6AC: bne         $at, $zero, L_8010E61C
    if (ctx->r1 != 0) {
        // 0x8010E6B0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8010E61C;
    }
    // 0x8010E6B0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8010E6B4:
    // 0x8010E6B4: lw          $t3, 0x1C($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X1C);
    // 0x8010E6B8: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x8010E6BC: sltu        $at, $s2, $t3
    ctx->r1 = ctx->r18 < ctx->r11 ? 1 : 0;
    // 0x8010E6C0: bnel        $at, $zero, L_8010E5B4
    if (ctx->r1 != 0) {
        // 0x8010E6C4: lbu         $t6, 0x10($s6)
        ctx->r14 = MEM_BU(ctx->r22, 0X10);
            goto L_8010E5B4;
    }
    goto skip_2;
    // 0x8010E6C4: lbu         $t6, 0x10($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X10);
    skip_2:
    // 0x8010E6C8: sltu        $at, $s3, $s7
    ctx->r1 = ctx->r19 < ctx->r23 ? 1 : 0;
L_8010E6CC:
    // 0x8010E6CC: beql        $at, $zero, L_8010E7C8
    if (ctx->r1 == 0) {
        // 0x8010E6D0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8010E7C8;
    }
    goto skip_3;
    // 0x8010E6D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_3:
L_8010E6D4:
    // 0x8010E6D4: lbu         $t4, 0x6($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X6);
    // 0x8010E6D8: lh          $t2, 0x0($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X0);
    // 0x8010E6DC: multu       $t4, $t2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E6E0: mflo        $v0
    ctx->r2 = lo;
    // 0x8010E6E4: sra         $t6, $v0, 8
    ctx->r14 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8010E6E8: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8010E6EC: bne         $at, $zero, L_8010E6F8
    if (ctx->r1 != 0) {
        // 0x8010E6F0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8010E6F8;
    }
    // 0x8010E6F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8010E6F4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8010E6F8:
    // 0x8010E6F8: sb          $v0, 0xC($s5)
    MEM_B(0XC, ctx->r21) = ctx->r2;
    // 0x8010E6FC: lh          $t9, 0x2($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X2);
    // 0x8010E700: lbu         $t5, 0x7($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X7);
    // 0x8010E704: multu       $t5, $t9
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E708: mflo        $v0
    ctx->r2 = lo;
    // 0x8010E70C: sra         $t7, $v0, 8
    ctx->r15 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8010E710: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x8010E714: bne         $at, $zero, L_8010E720
    if (ctx->r1 != 0) {
        // 0x8010E718: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8010E720;
    }
    // 0x8010E718: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8010E71C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8010E720:
    // 0x8010E720: sb          $v0, 0xD($s5)
    MEM_B(0XD, ctx->r21) = ctx->r2;
    // 0x8010E724: lh          $t1, 0x4($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X4);
    // 0x8010E728: lbu         $t8, 0x8($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X8);
    // 0x8010E72C: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    // 0x8010E730: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E734: mflo        $v0
    ctx->r2 = lo;
    // 0x8010E738: sra         $t3, $v0, 8
    ctx->r11 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8010E73C: slti        $at, $t3, 0x100
    ctx->r1 = SIGNED(ctx->r11) < 0X100 ? 1 : 0;
    // 0x8010E740: bne         $at, $zero, L_8010E74C
    if (ctx->r1 != 0) {
        // 0x8010E744: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_8010E74C;
    }
    // 0x8010E744: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8010E748: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8010E74C:
    // 0x8010E74C: sltu        $at, $s3, $s4
    ctx->r1 = ctx->r19 < ctx->r20 ? 1 : 0;
    // 0x8010E750: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x8010E754: bne         $at, $zero, L_8010E6D4
    if (ctx->r1 != 0) {
        // 0x8010E758: sb          $v0, -0x2($s5)
        MEM_B(-0X2, ctx->r21) = ctx->r2;
            goto L_8010E6D4;
    }
    // 0x8010E758: sb          $v0, -0x2($s5)
    MEM_B(-0X2, ctx->r21) = ctx->r2;
    // 0x8010E75C: b           L_8010E7C8
    // 0x8010E760: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8010E7C8;
    // 0x8010E760: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8010E764:
    // 0x8010E764: sltu        $at, $s3, $s7
    ctx->r1 = ctx->r19 < ctx->r23 ? 1 : 0;
    // 0x8010E768: lw          $v0, 0x4($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X4);
    // 0x8010E76C: lw          $v1, 0x8($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X8);
    // 0x8010E770: beq         $at, $zero, L_8010E7C4
    if (ctx->r1 == 0) {
        // 0x8010E774: lw          $a0, 0xC($s6)
        ctx->r4 = MEM_W(ctx->r22, 0XC);
            goto L_8010E7C4;
    }
    // 0x8010E774: lw          $a0, 0xC($s6)
    ctx->r4 = MEM_W(ctx->r22, 0XC);
L_8010E778:
    // 0x8010E778: lbu         $t4, 0x6($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X6);
    // 0x8010E77C: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    // 0x8010E780: sltu        $at, $s3, $s4
    ctx->r1 = ctx->r19 < ctx->r20 ? 1 : 0;
    // 0x8010E784: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E788: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x8010E78C: mflo        $t2
    ctx->r10 = lo;
    // 0x8010E790: sra         $t6, $t2, 8
    ctx->r14 = S32(SIGNED(ctx->r10) >> 8);
    // 0x8010E794: sb          $t6, -0x4($s5)
    MEM_B(-0X4, ctx->r21) = ctx->r14;
    // 0x8010E798: lbu         $t5, -0x3($s3)
    ctx->r13 = MEM_BU(ctx->r19, -0X3);
    // 0x8010E79C: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E7A0: mflo        $t9
    ctx->r25 = lo;
    // 0x8010E7A4: sra         $t7, $t9, 8
    ctx->r15 = S32(SIGNED(ctx->r25) >> 8);
    // 0x8010E7A8: sb          $t7, -0x3($s5)
    MEM_B(-0X3, ctx->r21) = ctx->r15;
    // 0x8010E7AC: lbu         $t8, -0x2($s3)
    ctx->r24 = MEM_BU(ctx->r19, -0X2);
    // 0x8010E7B0: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E7B4: mflo        $t1
    ctx->r9 = lo;
    // 0x8010E7B8: sra         $t3, $t1, 8
    ctx->r11 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8010E7BC: bne         $at, $zero, L_8010E778
    if (ctx->r1 != 0) {
        // 0x8010E7C0: sb          $t3, -0x2($s5)
        MEM_B(-0X2, ctx->r21) = ctx->r11;
            goto L_8010E778;
    }
    // 0x8010E7C0: sb          $t3, -0x2($s5)
    MEM_B(-0X2, ctx->r21) = ctx->r11;
L_8010E7C4:
    // 0x8010E7C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8010E7C8:
    // 0x8010E7C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010E7CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8010E7D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8010E7D4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8010E7D8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8010E7DC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8010E7E0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8010E7E4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8010E7E8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8010E7EC: jr          $ra
    // 0x8010E7F0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8010E7F0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void _gsworldDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B58: syscall     726
    recomp_syscall_handler(rdram, ctx, 0x80088B58);
    return;
    // 0x80088B5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800EBB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBB94: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EBB98: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EBB9C: addiu       $v0, $v0, 0x2EE9
    ctx->r2 = ADD32(ctx->r2, 0X2EE9);
    // 0x800EBBA0: addiu       $v1, $v1, 0x2ED0
    ctx->r3 = ADD32(ctx->r3, 0X2ED0);
L_800EBBA4:
    // 0x800EBBA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800EBBA8: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800EBBAC: bne         $at, $zero, L_800EBBA4
    if (ctx->r1 != 0) {
        // 0x800EBBB0: sb          $zero, 0x257F($v1)
        MEM_B(0X257F, ctx->r3) = 0;
            goto L_800EBBA4;
    }
    // 0x800EBBB0: sb          $zero, 0x257F($v1)
    MEM_B(0X257F, ctx->r3) = 0;
    // 0x800EBBB4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EBBB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EBBBC: addiu       $v0, $v0, 0x5450
    ctx->r2 = ADD32(ctx->r2, 0X5450);
    // 0x800EBBC0: addiu       $v1, $v1, 0x2ED0
    ctx->r3 = ADD32(ctx->r3, 0X2ED0);
L_800EBBC4:
    // 0x800EBBC4: lhu         $t8, 0x42($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X42);
    // 0x800EBBC8: lhu         $t0, 0x72($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X72);
    // 0x800EBBCC: lhu         $t2, 0xA2($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XA2);
    // 0x800EBBD0: lhu         $t6, 0x12($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X12);
    // 0x800EBBD4: addiu       $v1, $v1, 0xC0
    ctx->r3 = ADD32(ctx->r3, 0XC0);
    // 0x800EBBD8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800EBBDC: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800EBBE0: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800EBBE4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800EBBE8: sh          $t3, -0x1E($v1)
    MEM_H(-0X1E, ctx->r3) = ctx->r11;
    // 0x800EBBEC: sh          $t1, -0x4E($v1)
    MEM_H(-0X4E, ctx->r3) = ctx->r9;
    // 0x800EBBF0: sh          $t9, -0x7E($v1)
    MEM_H(-0X7E, ctx->r3) = ctx->r25;
    // 0x800EBBF4: bne         $v1, $v0, L_800EBBC4
    if (ctx->r3 != ctx->r2) {
        // 0x800EBBF8: sh          $t7, -0xAE($v1)
        MEM_H(-0XAE, ctx->r3) = ctx->r15;
            goto L_800EBBC4;
    }
    // 0x800EBBF8: sh          $t7, -0xAE($v1)
    MEM_H(-0XAE, ctx->r3) = ctx->r15;
    // 0x800EBBFC: jr          $ra
    // 0x800EBC00: nop

    return;
    // 0x800EBC00: nop

;}
RECOMP_FUNC void func_800EF934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EF938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EF93C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800EF940: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EF944: jal         0x800137AC
    // 0x800EF948: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800137AC(rdram, ctx);
        goto after_0;
    // 0x800EF948: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800EF94C: jal         0x800137C4
    // 0x800EF950: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800137C4(rdram, ctx);
        goto after_1;
    // 0x800EF950: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800EF954: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800EF958: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EF95C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800EF960: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EF964: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EF968: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EF96C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800EF970: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800EF974: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800EF978: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EF97C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EF980: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800EF984: add.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800EF988: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800EF98C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800EF990: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EF994: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x800EF998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EF99C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EF9A0: jr          $ra
    // 0x800EF9A4: nop

    return;
    // 0x800EF9A4: nop

;}
RECOMP_FUNC void func_8009E53C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E53C: lw          $t6, 0x114($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X114);
    // 0x8009E540: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8009E544: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8009E548: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009E54C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8009E550: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8009E554: jr          $ra
    // 0x8009E558: swc1        $f12, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f12.u32l;
    return;
    // 0x8009E558: swc1        $f12, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f12.u32l;
;}
RECOMP_FUNC void sumumbofx_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007BC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808007C0: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x808007C4: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x808007C8: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x808007CC: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x808007D0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808007D4: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x808007D8: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x808007DC: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x808007E0: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x808007E4: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x808007E8: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x808007EC: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x808007F0: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x808007F4: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x808007F8: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x808007FC: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800800: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800804: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800808: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8080080C: jal         0x808013B4
    // 0x80800810: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    sumumbofx_entrypoint_26(rdram, ctx);
        goto after_0;
    // 0x80800810: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800814: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80800818: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x8080081C: lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X88);
    // 0x80800820: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800824: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80800828: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080082C: addu        $s0, $s4, $t6
    ctx->r16 = ADD32(ctx->r20, ctx->r14);
    // 0x80800830: slt         $at, $s1, $s6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80800834: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800838: addiu       $s0, $s0, 0x64
    ctx->r16 = ADD32(ctx->r16, 0X64);
    // 0x8080083C: beq         $at, $zero, L_80800988
    if (ctx->r1 == 0) {
        // 0x80800840: or          $s2, $s1, $zero
        ctx->r18 = ctx->r17 | 0;
            goto L_80800988;
    }
    // 0x80800840: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80800844: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x80800848: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8080084C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800850: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800854: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X14A8) << 16);
    // 0x80800858: lwc1        $f26, 0x14A8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X14A8));
    // 0x8080085C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800860: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800864: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800868: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8080086C: lw          $s7, 0x8C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X8C);
    // 0x80800870: lw          $s5, 0x90($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X90);
    // 0x80800874: lw          $s3, 0x94($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X94);
L_80800878:
    // 0x80800878: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8080087C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800880: jal         0x8080060C
    // 0x80800884: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8080060C_sumumbofx(rdram, ctx);
        goto after_1;
    // 0x80800884: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800888: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080088C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800890: addiu       $s1, $s0, 0x10
    ctx->r17 = ADD32(ctx->r16, 0X10);
    // 0x80800894: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800898: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080089C: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x808008A0: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808008A4: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x808008A8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x808008AC: nop

    // 0x808008B0: bc1fl       L_808008E0
    if (!c1cs) {
        // 0x808008B4: lwc1        $f18, 0x0($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
            goto L_808008E0;
    }
    goto skip_0;
    // 0x808008B4: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x808008B8: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    // 0x808008BC: lw          $v0, 0x60($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X60);
    // 0x808008C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008C4: srl         $t7, $v0, 25
    ctx->r15 = S32(U32(ctx->r2) >> 25);
    // 0x808008C8: beql        $fp, $t7, L_808008E0
    if (ctx->r30 == ctx->r15) {
        // 0x808008CC: lwc1        $f18, 0x0($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
            goto L_808008E0;
    }
    goto skip_1;
    // 0x808008CC: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x808008D0: beql        $t7, $at, L_808008E0
    if (ctx->r15 == ctx->r1) {
        // 0x808008D4: lwc1        $f18, 0x0($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
            goto L_808008E0;
    }
    goto skip_2;
    // 0x808008D4: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x808008D8: swc1        $f24, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f24.u32l;
    // 0x808008DC: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
L_808008E0:
    // 0x808008E0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808008E4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x808008E8: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x808008EC: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808008F0: c.lt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl < ctx->f0.fl;
    // 0x808008F4: nop

    // 0x808008F8: bc1fl       L_8080090C
    if (!c1cs) {
        // 0x808008FC: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_8080090C;
    }
    goto skip_3;
    // 0x808008FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_3:
    // 0x80800900: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x80800904: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800908: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_8080090C:
    // 0x8080090C: jal         0x800EEB9C
    // 0x80800910: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    func_800EEB9C(rdram, ctx);
        goto after_2;
    // 0x80800910: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    after_2:
    // 0x80800914: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800918: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080091C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80800920: jal         0x800EF04C
    // 0x80800924: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80800924: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x80800928: beq         $s3, $zero, L_80800948
    if (ctx->r19 == 0) {
        // 0x8080092C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800948;
    }
    // 0x8080092C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800930: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800934: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80800938: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8080093C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800940: jal         0x800EF5A0
    // 0x80800944: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_4;
    // 0x80800944: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
L_80800948:
    // 0x80800948: beq         $s5, $zero, L_80800958
    if (ctx->r21 == 0) {
        // 0x8080094C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800958;
    }
    // 0x8080094C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800950: jal         0x800EF04C
    // 0x80800954: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800954: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
L_80800958:
    // 0x80800958: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800960: c.lt.s      $f16, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f16.fl < ctx->f28.fl;
    // 0x80800964: nop

    // 0x80800968: bc1fl       L_80800980
    if (!c1cs) {
        // 0x8080096C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800980;
    }
    goto skip_4;
    // 0x8080096C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x80800970: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x80800974: jal         0x808003E4
    // 0x80800978: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_808003E4_sumumbofx(rdram, ctx);
        goto after_6;
    // 0x80800978: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_6:
    // 0x8080097C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80800980:
    // 0x80800980: bne         $s2, $s6, L_80800878
    if (ctx->r18 != ctx->r22) {
        // 0x80800984: addiu       $s0, $s0, 0x2C
        ctx->r16 = ADD32(ctx->r16, 0X2C);
            goto L_80800878;
    }
    // 0x80800984: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
L_80800988:
    // 0x80800988: lw          $s5, 0x90($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X90);
    // 0x8080098C: addiu       $a0, $s4, 0x1C
    ctx->r4 = ADD32(ctx->r20, 0X1C);
    // 0x80800990: beql        $s5, $zero, L_808009A4
    if (ctx->r21 == 0) {
        // 0x80800994: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_808009A4;
    }
    goto skip_5;
    // 0x80800994: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_5:
    // 0x80800998: jal         0x800EE7F8
    // 0x8080099C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080099C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_7:
    // 0x808009A0: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_808009A4:
    // 0x808009A4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808009A8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808009AC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x808009B0: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x808009B4: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x808009B8: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x808009BC: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x808009C0: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x808009C4: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x808009C8: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x808009CC: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x808009D0: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x808009D4: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x808009D8: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x808009DC: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x808009E0: jr          $ra
    // 0x808009E4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x808009E4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8002A150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A150: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x8002A154: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x8002A158: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8002A15C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002A160: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002A164: sb          $zero, 0x2($t8)
    MEM_B(0X2, ctx->r24) = 0;
    // 0x8002A168: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x8002A16C: sll         $t0, $a1, 3
    ctx->r8 = S32(ctx->r5 << 3);
    // 0x8002A170: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8002A174: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8002A178: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8002A17C: sb          $zero, 0x6($t1)
    MEM_B(0X6, ctx->r9) = 0;
    // 0x8002A180: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x8002A184: sll         $t4, $a1, 3
    ctx->r12 = S32(ctx->r5 << 3);
    // 0x8002A188: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x8002A18C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8002A190: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x8002A194: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8002A198: sb          $t2, 0x3($t5)
    MEM_B(0X3, ctx->r13) = ctx->r10;
    // 0x8002A19C: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x8002A1A0: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x8002A1A4: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8002A1A8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002A1AC: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x8002A1B0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002A1B4: sb          $t6, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r14;
    // 0x8002A1B8: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x8002A1BC: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8002A1C0: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x8002A1C4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8002A1C8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8002A1CC: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8002A1D0: sb          $t0, 0x4($t4)
    MEM_B(0X4, ctx->r12) = ctx->r8;
    // 0x8002A1D4: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x8002A1D8: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x8002A1DC: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x8002A1E0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002A1E4: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x8002A1E8: sb          $zero, 0x8($t7)
    MEM_B(0X8, ctx->r15) = 0;
    // 0x8002A1EC: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x8002A1F0: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8002A1F4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8002A1F8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8002A1FC: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x8002A200: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x8002A204: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
    // 0x8002A208: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x8002A20C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A210: sll         $t0, $a1, 3
    ctx->r8 = S32(ctx->r5 << 3);
    // 0x8002A214: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002A218: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8002A21C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8002A220: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x8002A224: swc1        $f4, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f4.u32l;
    // 0x8002A228: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x8002A22C: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x8002A230: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x8002A234: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002A238: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x8002A23C: sb          $zero, 0x10($t7)
    MEM_B(0X10, ctx->r15) = 0;
    // 0x8002A240: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x8002A244: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x8002A248: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8002A24C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002A250: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8002A254: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x8002A258: sb          $t6, 0x9($t1)
    MEM_B(0X9, ctx->r9) = ctx->r14;
    // 0x8002A25C: lw          $t0, 0x60($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X60);
    // 0x8002A260: sll         $t4, $a1, 3
    ctx->r12 = S32(ctx->r5 << 3);
    // 0x8002A264: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x8002A268: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8002A26C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8002A270: addu        $t2, $t0, $t4
    ctx->r10 = ADD32(ctx->r8, ctx->r12);
    // 0x8002A274: sb          $t3, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r11;
    // 0x8002A278: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x8002A27C: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x8002A280: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8002A284: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002A288: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8002A28C: sb          $zero, 0xB($t9)
    MEM_B(0XB, ctx->r25) = 0;
    // 0x8002A290: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x8002A294: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8002A298: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8002A29C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002A2A0: addu        $t1, $t8, $t6
    ctx->r9 = ADD32(ctx->r24, ctx->r14);
    // 0x8002A2A4: sb          $zero, 0x7($t1)
    MEM_B(0X7, ctx->r9) = 0;
    // 0x8002A2A8: lw          $t0, 0x60($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X60);
    // 0x8002A2AC: sll         $t4, $a1, 3
    ctx->r12 = S32(ctx->r5 << 3);
    // 0x8002A2B0: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x8002A2B4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8002A2B8: addu        $t3, $t0, $t4
    ctx->r11 = ADD32(ctx->r8, ctx->r12);
    // 0x8002A2BC: sb          $zero, 0x13($t3)
    MEM_B(0X13, ctx->r11) = 0;
    // 0x8002A2C0: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x8002A2C4: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x8002A2C8: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x8002A2CC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002A2D0: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x8002A2D4: sb          $zero, 0x12($t7)
    MEM_B(0X12, ctx->r15) = 0;
    // 0x8002A2D8: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x8002A2DC: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x8002A2E0: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8002A2E4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002A2E8: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x8002A2EC: sb          $zero, 0x11($t6)
    MEM_B(0X11, ctx->r14) = 0;
    // 0x8002A2F0: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x8002A2F4: sll         $t0, $a1, 3
    ctx->r8 = S32(ctx->r5 << 3);
    // 0x8002A2F8: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8002A2FC: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8002A300: addu        $t4, $t1, $t0
    ctx->r12 = ADD32(ctx->r9, ctx->r8);
    // 0x8002A304: sb          $zero, 0x32($t4)
    MEM_B(0X32, ctx->r12) = 0;
    // 0x8002A308: jr          $ra
    // 0x8002A30C: nop

    return;
    // 0x8002A30C: nop

;}
RECOMP_FUNC void func_808005B0_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808005B4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808005B8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808005BC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x808005C0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808005C4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808005C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808005CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808005D0: jal         0x80100094
    // 0x808005D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808005D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005D8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808005DC: jal         0x800883A8
    // 0x808005E0: addiu       $s5, $v0, 0x14
    ctx->r21 = ADD32(ctx->r2, 0X14);
    _gcstatusDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x808005E0: addiu       $s5, $v0, 0x14
    ctx->r21 = ADD32(ctx->r2, 0X14);
    after_1:
    // 0x808005E4: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x808005E8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808005EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808005F0: blez        $t6, L_80800640
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808005F4: nop
    
            goto L_80800640;
    }
    // 0x808005F4: nop

L_808005F8:
    // 0x808005F8: jal         0x800F53D0
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800600: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800604: jal         0x80088378
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcstatusDll_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080060C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800610: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800614: jal         0x800842A8
    // 0x80800618: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    _bsfirstp_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800618: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_4:
    // 0x8080061C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800620: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800624: jal         0x800842B0
    // 0x80800628: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    _bsfirstp_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800628: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x8080062C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80800630: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800634: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800638: bne         $at, $zero, L_808005F8
    if (ctx->r1 != 0) {
        // 0x8080063C: nop
    
            goto L_808005F8;
    }
    // 0x8080063C: nop

L_80800640:
    // 0x80800640: jal         0x80089980
    // 0x80800644: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _sumultiscore_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800644: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x80800648: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080064C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800654: jal         0x80089988
    // 0x80800658: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800658: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x8080065C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800660: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800664: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800668: jal         0x80089988
    // 0x8080066C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x8080066C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80800670: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800674: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800678: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080067C: jal         0x80089988
    // 0x80800680: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80800680: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80800684: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800688: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080068C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800690: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800694: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800698: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8080069C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808006A0: jr          $ra
    // 0x808006A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808006A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bskazshock_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083550: syscall     66
    recomp_syscall_handler(rdram, ctx, 0x80083550);
    return;
    // 0x80083554: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080073C_chpowerhutwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080073C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800740: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800744: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800748: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080074C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800750: beq         $a1, $at, L_8080076C
    if (ctx->r5 == ctx->r1) {
        // 0x80800754: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8080076C;
    }
    // 0x80800754: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800758: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080075C: beq         $a1, $at, L_808007CC
    if (ctx->r5 == ctx->r1) {
        // 0x80800760: nop
    
            goto L_808007CC;
    }
    // 0x80800760: nop

    // 0x80800764: b           L_80800868
    // 0x80800768: nop

        goto L_80800868;
    // 0x80800768: nop

L_8080076C:
    // 0x8080076C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800770: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x80800774: bne         $t7, $at, L_808007C4
    if (ctx->r15 != ctx->r1) {
        // 0x80800778: nop
    
            goto L_808007C4;
    }
    // 0x80800778: nop

    // 0x8080077C: jal         0x80085710
    // 0x80800780: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800780: nop

    after_0:
    // 0x80800784: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080078C: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x80800790: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    // 0x80800794: jal         0x80085708
    // 0x80800798: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800798: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x8080079C: addiu       $a0, $zero, 0x39E
    ctx->r4 = ADD32(0, 0X39E);
    // 0x808007A0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808007A4: jal         0x80101180
    // 0x808007A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x808007A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808007AC: addiu       $a0, $zero, 0x39F
    ctx->r4 = ADD32(0, 0X39F);
    // 0x808007B0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808007B4: jal         0x80101180
    // 0x808007B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x808007B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808007BC: b           L_80800880
    // 0x808007C0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800880;
    // 0x808007C0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808007C4:
    // 0x808007C4: b           L_80800880
    // 0x808007C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800880;
    // 0x808007C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808007CC:
    // 0x808007CC: jal         0x800DA298
    // 0x808007D0: addiu       $a0, $zero, 0xEC
    ctx->r4 = ADD32(0, 0XEC);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808007D0: addiu       $a0, $zero, 0xEC
    ctx->r4 = ADD32(0, 0XEC);
    after_4:
    // 0x808007D4: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x808007D8: bnel        $a1, $zero, L_808007F0
    if (ctx->r5 != 0) {
        // 0x808007DC: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_808007F0;
    }
    goto skip_0;
    // 0x808007DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    skip_0:
    // 0x808007E0: jal         0x80088848
    // 0x808007E4: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x808007E4: nop

    after_5:
    // 0x808007E8: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x808007EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
L_808007F0:
    // 0x808007F0: sltiu       $t9, $a1, 0x1
    ctx->r25 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x808007F4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x808007F8: jal         0x800BF744
    // 0x808007FC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800BF744(rdram, ctx);
        goto after_6;
    // 0x808007FC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_6:
    // 0x80800800: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800804: jal         0x800BF744
    // 0x80800808: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800BF744(rdram, ctx);
        goto after_7;
    // 0x80800808: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x8080080C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800810: jal         0x80100094
    // 0x80800814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x80800814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800818: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080081C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800820: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80800824: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800828: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x8080082C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800830: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800834: jal         0x800F10B4
    // 0x80800838: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x80800838: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x8080083C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800840: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x80800844: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800848: bne         $t0, $zero, L_80800860
    if (ctx->r8 != 0) {
        // 0x8080084C: nop
    
            goto L_80800860;
    }
    // 0x8080084C: nop

    // 0x80800850: jal         0x80800890
    // 0x80800854: nop

    func_80800890_chpowerhutwitchy(rdram, ctx);
        goto after_10;
    // 0x80800854: nop

    after_10:
    // 0x80800858: b           L_80800868
    // 0x8080085C: nop

        goto L_80800868;
    // 0x8080085C: nop

L_80800860:
    // 0x80800860: jal         0x808009FC
    // 0x80800864: nop

    func_808009FC_chpowerhutwitchy(rdram, ctx);
        goto after_11;
    // 0x80800864: nop

    after_11:
L_80800868:
    // 0x80800868: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1080, 0XB14) << 16);
    // 0x8080086C: addiu       $a3, $a3, 0xB14
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1080, 0XB14));
    // 0x80800870: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800874: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800878: jal         0x80086050
    // 0x8080087C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _chpowerhut_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x8080087C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_12:
L_80800880:
    // 0x80800880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800884: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800888: jr          $ra
    // 0x8080088C: nop

    return;
    // 0x8080088C: nop

;}
RECOMP_FUNC void func_800F5E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5E50: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5E54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5E58: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5E60: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5E64: jal         0x800966E0
    // 0x800F5E68: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800966E0(rdram, ctx);
        goto after_0;
    // 0x800F5E68: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5E74: jr          $ra
    // 0x800F5E78: nop

    return;
    // 0x800F5E78: nop

;}
RECOMP_FUNC void _chhotwaterpoolbits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086440: syscall     323
    recomp_syscall_handler(rdram, ctx, 0x80086440);
    return;
    // 0x80086444: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void fxegg_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808004C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808004C4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808004C8: jal         0x800B5BE4
    // 0x808004CC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x808004CC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x808004D0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808004D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004D8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808004DC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808004E0: addiu       $a3, $zero, 0x9E0
    ctx->r7 = ADD32(0, 0X9E0);
    // 0x808004E4: jal         0x80800410
    // 0x808004E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80800410_fxegg(rdram, ctx);
        goto after_1;
    // 0x808004E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x808004EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004F4: jr          $ra
    // 0x808004F8: nop

    return;
    // 0x808004F8: nop

;}
RECOMP_FUNC void func_808007C4_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808007C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808007D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007D8: jal         0x80100094
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007E0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808007E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808007E8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808007EC: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x808007F0: sltiu       $at, $t8, 0x10
    ctx->r1 = ctx->r24 < 0X10 ? 1 : 0;
    // 0x808007F4: beq         $at, $zero, L_808008A0
    if (ctx->r1 == 0) {
        // 0x808007F8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808008A0;
    }
    // 0x808007F8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808007FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3D30) << 16);
    // 0x80800800: addu        $at, $at, $t8
    gpr jr_addend_80800808 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800804: lw          $t8, 0x3D30($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3D30));
    // 0x80800808: jr          $t8
    // 0x8080080C: nop

    switch (jr_addend_80800808 >> 2) {
        case 0: goto L_8080084C; break;
        case 1: goto L_808008A0; break;
        case 2: goto L_80800810; break;
        case 3: goto L_808008A0; break;
        case 4: goto L_808008A0; break;
        case 5: goto L_8080085C; break;
        case 6: goto L_808008A0; break;
        case 7: goto L_80800884; break;
        case 8: goto L_8080086C; break;
        case 9: goto L_808008A0; break;
        case 10: goto L_808008A0; break;
        case 11: goto L_808008A0; break;
        case 12: goto L_808008A0; break;
        case 13: goto L_808008A0; break;
        case 14: goto L_808008A0; break;
        case 15: goto L_8080085C; break;
        default: switch_error(__func__, 0x80800808, 0x80803D30);
    }
    // 0x8080080C: nop

L_80800810:
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800814: jal         0x80800774
    // 0x80800818: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80800774_chevilmumbo(rdram, ctx);
        goto after_1;
    // 0x80800818: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8080081C: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800820: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x80800824: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800828: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x8080082C: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x80800830: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800834: jal         0x800861A0
    // 0x80800838: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800838: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8080083C: jal         0x800FDC28
    // 0x80800840: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_3;
    // 0x80800840: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800844: b           L_808008A0
    // 0x80800848: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
        goto L_808008A0;
    // 0x80800848: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_8080084C:
    // 0x8080084C: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    // 0x80800850: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x80800854: b           L_808008A0
    // 0x80800858: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
        goto L_808008A0;
    // 0x80800858: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
L_8080085C:
    // 0x8080085C: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80800860: andi        $t4, $t3, 0xFFDF
    ctx->r12 = ctx->r11 & 0XFFDF;
    // 0x80800864: b           L_808008A0
    // 0x80800868: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
        goto L_808008A0;
    // 0x80800868: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
L_8080086C:
    // 0x8080086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800874: jal         0x8010A800
    // 0x80800878: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_8010A800(rdram, ctx);
        goto after_4;
    // 0x80800878: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_4:
    // 0x8080087C: b           L_808008A0
    // 0x80800880: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
        goto L_808008A0;
    // 0x80800880: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_80800884:
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800888: jal         0x8010A590
    // 0x8080088C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_8010A590(rdram, ctx);
        goto after_5;
    // 0x8080088C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x80800890: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800894: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800898: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8080089C: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_808008A0:
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808008A8: jal         0x80102424
    // 0x808008AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808008AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_6:
    // 0x808008B0: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x808008B4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808008B8: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808008BC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x808008C0: sltiu       $at, $t0, 0x15
    ctx->r1 = ctx->r8 < 0X15 ? 1 : 0;
    // 0x808008C4: beq         $at, $zero, L_80800C3C
    if (ctx->r1 == 0) {
        // 0x808008C8: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800C3C;
    }
    // 0x808008C8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808008CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3D70) << 16);
    // 0x808008D0: addu        $at, $at, $t0
    gpr jr_addend_808008D8 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808008D4: lw          $t0, 0x3D70($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3D70));
    // 0x808008D8: jr          $t0
    // 0x808008DC: nop

    switch (jr_addend_808008D8 >> 2) {
        case 0: goto L_80800948; break;
        case 1: goto L_80800938; break;
        case 2: goto L_80800C3C; break;
        case 3: goto L_80800990; break;
        case 4: goto L_80800974; break;
        case 5: goto L_80800C3C; break;
        case 6: goto L_808009A0; break;
        case 7: goto L_808009B0; break;
        case 8: goto L_80800A28; break;
        case 9: goto L_808009E4; break;
        case 10: goto L_80800B70; break;
        case 11: goto L_80800B28; break;
        case 12: goto L_808009A0; break;
        case 13: goto L_80800A90; break;
        case 14: goto L_80800B90; break;
        case 15: goto L_80800BFC; break;
        case 16: goto L_80800C3C; break;
        case 17: goto L_80800AFC; break;
        case 18: goto L_80800A54; break;
        case 19: goto L_80800C20; break;
        case 20: goto L_808008E0; break;
        default: switch_error(__func__, 0x808008D8, 0x80803D70);
    }
    // 0x808008DC: nop

L_808008E0:
    // 0x808008E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x808008E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808008E8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X427C) << 16);
    // 0x808008EC: sb          $v0, 0x84($v1)
    MEM_B(0X84, ctx->r3) = ctx->r2;
    // 0x808008F0: sb          $a2, 0x85($v1)
    MEM_B(0X85, ctx->r3) = ctx->r6;
    // 0x808008F4: sb          $v0, 0x86($v1)
    MEM_B(0X86, ctx->r3) = ctx->r2;
    // 0x808008F8: sb          $a2, 0x87($v1)
    MEM_B(0X87, ctx->r3) = ctx->r6;
    // 0x808008FC: sb          $v0, 0x88($v1)
    MEM_B(0X88, ctx->r3) = ctx->r2;
    // 0x80800900: sb          $v0, 0x89($v1)
    MEM_B(0X89, ctx->r3) = ctx->r2;
    // 0x80800904: sb          $a2, 0x8A($v1)
    MEM_B(0X8A, ctx->r3) = ctx->r6;
    // 0x80800908: sb          $v0, 0x8B($v1)
    MEM_B(0X8B, ctx->r3) = ctx->r2;
    // 0x8080090C: sb          $v0, 0x8C($v1)
    MEM_B(0X8C, ctx->r3) = ctx->r2;
    // 0x80800910: sb          $v0, 0x8D($v1)
    MEM_B(0X8D, ctx->r3) = ctx->r2;
    // 0x80800914: addiu       $a1, $a1, 0x427C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X427C));
    // 0x80800918: jal         0x800EE7F8
    // 0x8080091C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080091C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800920: jal         0x80800774
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800774_chevilmumbo(rdram, ctx);
        goto after_8;
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800928: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x8080092C: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x80800930: b           L_80800C3C
    // 0x80800934: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
        goto L_80800C3C;
    // 0x80800934: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
L_80800938:
    // 0x80800938: jal         0x80800300
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800300_chevilmumbo(rdram, ctx);
        goto after_9;
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800940: b           L_80800C40
    // 0x80800944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C40;
    // 0x80800944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800948:
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080094C: jal         0x80100094
    // 0x80800950: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x80800950: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800954: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800958: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080095C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800960: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800964: jal         0x800897E8
    // 0x80800968: nop

    _suexpression_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x80800968: nop

    after_11:
    // 0x8080096C: b           L_80800C40
    // 0x80800970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C40;
    // 0x80800970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800974:
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800978: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080097C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80800980: jal         0x808001F4
    // 0x80800984: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808001F4_chevilmumbo(rdram, ctx);
        goto after_12;
    // 0x80800984: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x80800988: b           L_80800C40
    // 0x8080098C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C40;
    // 0x8080098C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800990:
    // 0x80800990: lbu         $t5, 0x74($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X74);
    // 0x80800994: ori         $t6, $t5, 0x20
    ctx->r14 = ctx->r13 | 0X20;
    // 0x80800998: b           L_80800C3C
    // 0x8080099C: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
        goto L_80800C3C;
    // 0x8080099C: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
L_808009A0:
    // 0x808009A0: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
    // 0x808009A4: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x808009A8: b           L_80800C3C
    // 0x808009AC: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
        goto L_80800C3C;
    // 0x808009AC: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
L_808009B0:
    // 0x808009B0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X414C) << 16);
    // 0x808009B4: addiu       $a2, $a2, 0x414C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X414C));
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009BC: jal         0x80089D18
    // 0x808009C0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x808009C0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x808009C4: lw          $t1, 0x6C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X6C);
    // 0x808009C8: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    // 0x808009CC: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x808009D0: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x808009D4: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x808009D8: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x808009DC: b           L_80800C3C
    // 0x808009E0: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
        goto L_80800C3C;
    // 0x808009E0: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
L_808009E4:
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E8: jal         0x8010A800
    // 0x808009EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_14;
    // 0x808009EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x808009F0: lui         $a1, 0x3F2D
    ctx->r5 = S32(0X3F2D << 16);
    // 0x808009F4: ori         $a1, $a1, 0x4FDF
    ctx->r5 = ctx->r5 | 0X4FDF;
    // 0x808009F8: jal         0x80101EE4
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101EE4(rdram, ctx);
        goto after_15;
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A04: jal         0x80101CDC
    // 0x80800A08: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80101CDC(rdram, ctx);
        goto after_16;
    // 0x80800A08: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_16:
    // 0x80800A0C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4140) << 16);
    // 0x80800A10: addiu       $a2, $a2, 0x4140
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4140));
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A18: jal         0x80089D18
    // 0x80800A1C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x80800A1C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_17:
    // 0x80800A20: b           L_80800C40
    // 0x80800A24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C40;
    // 0x80800A24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A28:
    // 0x80800A28: lbu         $t7, 0x93($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X93);
    // 0x80800A2C: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80800A30: beql        $at, $zero, L_80800A48
    if (ctx->r1 == 0) {
        // 0x80800A34: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800A48;
    }
    goto skip_0;
    // 0x80800A34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x80800A38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800A3C: b           L_80800C3C
    // 0x80800A40: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800C3C;
    // 0x80800A40: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800A44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800A48:
    // 0x80800A48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A4C: b           L_80800C3C
    // 0x80800A50: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800C3C;
    // 0x80800A50: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800A54:
    // 0x80800A54: lbu         $t8, 0x93($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X93);
    // 0x80800A58: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x80800A5C: beq         $at, $zero, L_80800A70
    if (ctx->r1 == 0) {
        // 0x80800A60: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80800A70;
    }
    // 0x80800A60: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800A64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A68: b           L_80800A80
    // 0x80800A6C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800A80;
    // 0x80800A6C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800A70:
    // 0x80800A70: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800A74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800A78: nop

    // 0x80800A7C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800A80:
    // 0x80800A80: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    // 0x80800A84: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x80800A88: b           L_80800C3C
    // 0x80800A8C: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
        goto L_80800C3C;
    // 0x80800A8C: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
L_80800A90:
    // 0x80800A90: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800A94: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800A98: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800A9C: jal         0x800EE7F8
    // 0x80800AA0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_18;
    // 0x80800AA0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_18:
    // 0x80800AA4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800AA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800AAC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800AB0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800AB4: jal         0x800DC298
    // 0x80800AB8: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    func_800DC298(rdram, ctx);
        goto after_19;
    // 0x80800AB8: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    after_19:
    // 0x80800ABC: beq         $v0, $zero, L_80800AE0
    if (ctx->r2 == 0) {
        // 0x80800AC0: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80800AE0;
    }
    // 0x80800AC0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800AC4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4190) << 16);
    // 0x80800AC8: addiu       $a2, $a2, 0x4190
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4190));
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD0: jal         0x80089D18
    // 0x80800AD4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_20;
    // 0x80800AD4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_20:
    // 0x80800AD8: b           L_80800C40
    // 0x80800ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C40;
    // 0x80800ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AE0:
    // 0x80800AE0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4198) << 16);
    // 0x80800AE4: addiu       $a2, $a2, 0x4198
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4198));
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AEC: jal         0x80089D18
    // 0x80800AF0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x80800AF0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_21:
    // 0x80800AF4: b           L_80800C40
    // 0x80800AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C40;
    // 0x80800AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AFC:
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B00: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80800B04: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80800B08: jal         0x808001F4
    // 0x80800B0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808001F4_chevilmumbo(rdram, ctx);
        goto after_22;
    // 0x80800B0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_22:
    // 0x80800B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B14: addiu       $a1, $zero, 0x11E5
    ctx->r5 = ADD32(0, 0X11E5);
    // 0x80800B18: jal         0x80800354
    // 0x80800B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800354_chevilmumbo(rdram, ctx);
        goto after_23;
    // 0x80800B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x80800B20: b           L_80800C40
    // 0x80800B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C40;
    // 0x80800B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B28:
    // 0x80800B28: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800B2C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4140) << 16);
    // 0x80800B30: addiu       $a2, $a2, 0x4140
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4140));
    // 0x80800B34: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800B38: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800B3C: jal         0x80089D18
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800B44: jal         0x80800670
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800670_chevilmumbo(rdram, ctx);
        goto after_25;
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800B4C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800B50: jal         0x800F1DF4
    // 0x80800B54: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800F1DF4(rdram, ctx);
        goto after_26;
    // 0x80800B54: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_26:
    // 0x80800B58: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B60: jal         0x80101CDC
    // 0x80800B64: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80101CDC(rdram, ctx);
        goto after_27;
    // 0x80800B64: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_27:
    // 0x80800B68: b           L_80800C40
    // 0x80800B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C40;
    // 0x80800B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B70:
    // 0x80800B70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B78: jal         0x8010A570
    // 0x80800B7C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    func_8010A570(rdram, ctx);
        goto after_28;
    // 0x80800B7C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    after_28:
    // 0x80800B80: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800B84: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x80800B88: b           L_80800C3C
    // 0x80800B8C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_80800C3C;
    // 0x80800B8C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_80800B90:
    // 0x80800B90: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800B94: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X41C0) << 16);
    // 0x80800B98: addiu       $a2, $a2, 0x41C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X41C0));
    // 0x80800B9C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800BA0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA8: jal         0x80089D18
    // 0x80800BAC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_29;
    // 0x80800BAC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_29:
    // 0x80800BB0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800BB4: jal         0x80090734
    // 0x80800BB8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090734(rdram, ctx);
        goto after_30;
    // 0x80800BB8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_30:
    // 0x80800BBC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800BC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800BCC: jal         0x80800144
    // 0x80800BD0: sb          $zero, 0x92($v1)
    MEM_B(0X92, ctx->r3) = 0;
    func_80800144_chevilmumbo(rdram, ctx);
        goto after_31;
    // 0x80800BD0: sb          $zero, 0x92($v1)
    MEM_B(0X92, ctx->r3) = 0;
    after_31:
    // 0x80800BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BD8: addiu       $a1, $zero, 0x11E1
    ctx->r5 = ADD32(0, 0X11E1);
    // 0x80800BDC: jal         0x80800354
    // 0x80800BE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800354_chevilmumbo(rdram, ctx);
        goto after_32;
    // 0x80800BE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_32:
    // 0x80800BE4: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800BE8: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80800BEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800BF0: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
    // 0x80800BF4: b           L_80800C3C
    // 0x80800BF8: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
        goto L_80800C3C;
    // 0x80800BF8: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
L_80800BFC:
    // 0x80800BFC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X41C0) << 16);
    // 0x80800C00: addiu       $a2, $a2, 0x41C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X41C0));
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C08: jal         0x80089D18
    // 0x80800C0C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_33;
    // 0x80800C0C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_33:
    // 0x80800C10: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80800C14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C18: b           L_80800C3C
    // 0x80800C1C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800C3C;
    // 0x80800C1C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800C20:
    // 0x80800C20: lbu         $t4, 0x95($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X95);
    // 0x80800C24: beq         $t4, $zero, L_80800C34
    if (ctx->r12 == 0) {
        // 0x80800C28: nop
    
            goto L_80800C34;
    }
    // 0x80800C28: nop

    // 0x80800C2C: jal         0x80800290
    // 0x80800C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800290_chevilmumbo(rdram, ctx);
        goto after_34;
    // 0x80800C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
L_80800C34:
    // 0x80800C34: jal         0x800FDC28
    // 0x80800C38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_35;
    // 0x80800C38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_35:
L_80800C3C:
    // 0x80800C3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C40:
    // 0x80800C40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800C48: jr          $ra
    // 0x80800C4C: nop

    return;
    // 0x80800C4C: nop

;}
RECOMP_FUNC void func_808000AC_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808000B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808000BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808000C4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808000C8: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x808000CC: beql        $a3, $zero, L_80800138
    if (ctx->r7 == 0) {
        // 0x808000D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800138;
    }
    goto skip_0;
    // 0x808000D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000D4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x808000D8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x808000DC: addiu       $s2, $a0, 0xE0
    ctx->r18 = ADD32(ctx->r4, 0XE0);
    // 0x808000E0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x808000E4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808000E8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808000EC: addu        $s1, $t9, $a3
    ctx->r17 = ADD32(ctx->r25, ctx->r7);
    // 0x808000F0: sltu        $at, $a3, $s1
    ctx->r1 = ctx->r7 < ctx->r17 ? 1 : 0;
    // 0x808000F4: beq         $at, $zero, L_8080011C
    if (ctx->r1 == 0) {
        // 0x808000F8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080011C;
    }
    // 0x808000F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808000FC:
    // 0x808000FC: jal         0x800B422C
    // 0x80800100: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800B422C(rdram, ctx);
        goto after_0;
    // 0x80800100: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_0:
    // 0x80800104: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80800108: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x8080010C: bnel        $at, $zero, L_808000FC
    if (ctx->r1 != 0) {
        // 0x80800110: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808000FC;
    }
    goto skip_1;
    // 0x80800110: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x80800114: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80800118: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
L_8080011C:
    // 0x8080011C: jal         0x8001B084
    // 0x80800120: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    heap_free(rdram, ctx);
        goto after_1;
    // 0x80800120: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80800124: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80800128: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8080012C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80800130: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x80800134: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800138:
    // 0x80800138: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080013C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800140: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800144: jr          $ra
    // 0x80800148: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800148: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _gcgoto_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A58: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087A58);
    return;
    // 0x80087A5C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bswasher_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800700: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800704: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(443, 0X1E10) << 16);
    // 0x80800708: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080070C: jr          $ra
    // 0x80800710: lw          $v0, 0x1E10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E10));
    return;
    // 0x80800710: lw          $v0, 0x1E10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E10));
;}
RECOMP_FUNC void gcegg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2678, 0X200) << 16);
    // 0x8080007C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2678, 0X270) << 16);
    // 0x80800080: addiu       $v0, $v0, 0x270
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2678, 0X270));
    // 0x80800084: addiu       $v1, $v1, 0x200
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2678, 0X200));
    // 0x80800088: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
L_8080008C:
    // 0x8080008C: bnel        $a0, $t6, L_808000A0
    if (ctx->r4 != ctx->r14) {
        // 0x80800090: lh          $t7, 0x12($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X12);
            goto L_808000A0;
    }
    goto skip_0;
    // 0x80800090: lh          $t7, 0x12($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X12);
    skip_0:
    // 0x80800094: jr          $ra
    // 0x80800098: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    return;
    // 0x80800098: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x8080009C: lh          $t7, 0x12($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X12);
L_808000A0:
    // 0x808000A0: bnel        $a0, $t7, L_808000B4
    if (ctx->r4 != ctx->r15) {
        // 0x808000A4: lh          $t8, 0x20($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X20);
            goto L_808000B4;
    }
    goto skip_1;
    // 0x808000A4: lh          $t8, 0x20($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X20);
    skip_1:
    // 0x808000A8: jr          $ra
    // 0x808000AC: lbu         $v0, 0x16($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X16);
    return;
    // 0x808000AC: lbu         $v0, 0x16($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X16);
    // 0x808000B0: lh          $t8, 0x20($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X20);
L_808000B4:
    // 0x808000B4: bnel        $a0, $t8, L_808000C8
    if (ctx->r4 != ctx->r24) {
        // 0x808000B8: lh          $t9, 0x2E($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X2E);
            goto L_808000C8;
    }
    goto skip_2;
    // 0x808000B8: lh          $t9, 0x2E($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2E);
    skip_2:
    // 0x808000BC: jr          $ra
    // 0x808000C0: lbu         $v0, 0x24($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X24);
    return;
    // 0x808000C0: lbu         $v0, 0x24($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X24);
    // 0x808000C4: lh          $t9, 0x2E($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2E);
L_808000C8:
    // 0x808000C8: bnel        $a0, $t9, L_808000DC
    if (ctx->r4 != ctx->r25) {
        // 0x808000CC: addiu       $v1, $v1, 0x38
        ctx->r3 = ADD32(ctx->r3, 0X38);
            goto L_808000DC;
    }
    goto skip_3;
    // 0x808000CC: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    skip_3:
    // 0x808000D0: jr          $ra
    // 0x808000D4: lbu         $v0, 0x32($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X32);
    return;
    // 0x808000D4: lbu         $v0, 0x32($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X32);
    // 0x808000D8: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
L_808000DC:
    // 0x808000DC: bnel        $v1, $v0, L_8080008C
    if (ctx->r3 != ctx->r2) {
        // 0x808000E0: lh          $t6, 0x4($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X4);
            goto L_8080008C;
    }
    goto skip_4;
    // 0x808000E0: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    skip_4:
    // 0x808000E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void _capod_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085718: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x80085718);
    return;
    // 0x8008571C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void gcmapDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2646, 0XF10) << 16);
    // 0x80800050: addiu       $v0, $v1, 0xF10
    ctx->r2 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2646, 0XF10));
    // 0x80800054: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80800058: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2646, 0XF10) << 16);
    // 0x8080005C: addiu       $t7, $t7, 0xF10
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2646, 0XF10));
    // 0x80800060: beql        $t6, $zero, L_80800090
    if (ctx->r14 == 0) {
        // 0x80800064: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800090;
    }
    goto skip_0;
    // 0x80800064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800068: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
L_8080006C:
    // 0x8080006C: bnel        $a0, $v1, L_80800080
    if (ctx->r4 != ctx->r3) {
        // 0x80800070: lh          $v1, 0xE($v0)
        ctx->r3 = MEM_H(ctx->r2, 0XE);
            goto L_80800080;
    }
    goto skip_1;
    // 0x80800070: lh          $v1, 0xE($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XE);
    skip_1:
    // 0x80800074: jr          $ra
    // 0x80800078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080007C: lh          $v1, 0xE($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XE);
L_80800080:
    // 0x80800080: addiu       $v0, $v0, 0xE
    ctx->r2 = ADD32(ctx->r2, 0XE);
    // 0x80800084: bne         $v1, $zero, L_8080006C
    if (ctx->r3 != 0) {
        // 0x80800088: nop
    
            goto L_8080006C;
    }
    // 0x80800088: nop

    // 0x8080008C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800090:
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void func_80800688_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8080068C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800690: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800694: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800698: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080069C: jal         0x8001211C
    // 0x808006A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x808006A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x808006A4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1668, 0X1020) << 16);
    // 0x808006A8: addiu       $a0, $a0, 0x1020
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1668, 0X1020));
    // 0x808006AC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808006B0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808006B4: jal         0x80089C50
    // 0x808006B8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    _subaddiefind_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808006B8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x808006BC: blez        $v0, L_80800718
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808006C0: lw          $a3, 0x38($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X38);
            goto L_80800718;
    }
    // 0x808006C0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x808006C4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808006C8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x808006CC: addu        $a2, $t7, $a0
    ctx->r6 = ADD32(ctx->r15, ctx->r4);
    // 0x808006D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_808006D4:
    // 0x808006D4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808006D8: beql        $s1, $v0, L_80800710
    if (ctx->r17 == ctx->r2) {
        // 0x808006DC: sltu        $at, $a0, $a2
        ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
            goto L_80800710;
    }
    goto skip_0;
    // 0x808006DC: sltu        $at, $a0, $a2
    ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
    skip_0:
    // 0x808006E0: lw          $v1, 0x54($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X54);
    // 0x808006E4: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808006E8: bnel        $at, $zero, L_80800710
    if (ctx->r1 != 0) {
        // 0x808006EC: sltu        $at, $a0, $a2
        ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
            goto L_80800710;
    }
    goto skip_1;
    // 0x808006EC: sltu        $at, $a0, $a2
    ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
    skip_1:
    // 0x808006F0: lhu         $t8, 0x64($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X64);
    // 0x808006F4: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x808006F8: beql        $t9, $zero, L_80800710
    if (ctx->r25 == 0) {
        // 0x808006FC: sltu        $at, $a0, $a2
        ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
            goto L_80800710;
    }
    goto skip_2;
    // 0x808006FC: sltu        $at, $a0, $a2
    ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
    skip_2:
    // 0x80800700: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80800704: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80800708: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8080070C: sltu        $at, $a0, $a2
    ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
L_80800710:
    // 0x80800710: bnel        $at, $zero, L_808006D4
    if (ctx->r1 != 0) {
        // 0x80800714: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_808006D4;
    }
    goto skip_3;
    // 0x80800714: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_3:
L_80800718:
    // 0x80800718: bne         $s0, $zero, L_80800728
    if (ctx->r16 != 0) {
        // 0x8080071C: lw          $t0, 0x48($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X48);
            goto L_80800728;
    }
    // 0x8080071C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80800720: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x80800724: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
L_80800728:
    // 0x80800728: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080072C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800730: jal         0x800888C8
    // 0x80800734: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800734: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x80800738: jal         0x800FFA88
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFA88(rdram, ctx);
        goto after_3;
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800744: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800748: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080074C: jr          $ra
    // 0x80800750: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80800750: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void chboilerid_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1084, 0XD5C) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xD5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1084, 0XD5C));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xD5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1084, 0XD5C));
;}
RECOMP_FUNC void func_800F6DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6DE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6DE8: jal         0x80082828
    // 0x800F6DEC: nop

    _bsbabykaz_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x800F6DEC: nop

    after_0:
    // 0x800F6DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6DF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6DF8: jr          $ra
    // 0x800F6DFC: nop

    return;
    // 0x800F6DFC: nop

;}
RECOMP_FUNC void func_80800530_chamazonstadiumguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800538: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080053C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800540: jal         0x8010CAC0
    // 0x80800544: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8010CAC0(rdram, ctx);
        goto after_0;
    // 0x80800544: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_0:
    // 0x80800548: beql        $v0, $zero, L_808005C0
    if (ctx->r2 == 0) {
        // 0x8080054C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005C0;
    }
    goto skip_0;
    // 0x8080054C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800550: jal         0x8010D284
    // 0x80800554: nop

    func_8010D284(rdram, ctx);
        goto after_1;
    // 0x80800554: nop

    after_1:
    // 0x80800558: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080055C: beql        $v0, $at, L_808005C0
    if (ctx->r2 == ctx->r1) {
        // 0x80800560: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005C0;
    }
    goto skip_1;
    // 0x80800560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800564: jal         0x8010D284
    // 0x80800568: nop

    func_8010D284(rdram, ctx);
        goto after_2;
    // 0x80800568: nop

    after_2:
    // 0x8080056C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800570: beql        $v0, $at, L_808005C0
    if (ctx->r2 == ctx->r1) {
        // 0x80800574: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005C0;
    }
    goto skip_2;
    // 0x80800574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800578: jal         0x8010D278
    // 0x8080057C: nop

    func_8010D278(rdram, ctx);
        goto after_3;
    // 0x8080057C: nop

    after_3:
    // 0x80800580: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800584: bne         $v0, $at, L_808005B4
    if (ctx->r2 != ctx->r1) {
        // 0x80800588: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808005B4;
    }
    // 0x80800588: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080058C: jal         0x800DA298
    // 0x80800590: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800590: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    after_4:
    // 0x80800594: beq         $v0, $zero, L_808005A4
    if (ctx->r2 == 0) {
        // 0x80800598: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_808005A4;
    }
    // 0x80800598: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080059C: b           L_808005A4
    // 0x808005A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_808005A4;
    // 0x808005A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_808005A4:
    // 0x808005A4: jal         0x80102424
    // 0x808005A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x808005A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x808005AC: b           L_808005C0
    // 0x808005B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808005C0;
    // 0x808005B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005B4:
    // 0x808005B4: jal         0x80102424
    // 0x808005B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808005B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808005BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005C0:
    // 0x808005C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005C4: jr          $ra
    // 0x808005C8: nop

    return;
    // 0x808005C8: nop

;}
RECOMP_FUNC void func_800D3104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3104: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800D3108: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800D310C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800D3110: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D3114: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800D3118: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800D311C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800D3120: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800D3124: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800D3128: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D312C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D3130: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D3134: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D3138: jal         0x800EB800
    // 0x800D313C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800EB800(rdram, ctx);
        goto after_0;
    // 0x800D313C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x800D3140: jal         0x800E3980
    // 0x800D3144: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    func_800E3980(rdram, ctx);
        goto after_1;
    // 0x800D3144: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    after_1:
    // 0x800D3148: addiu       $s6, $sp, 0xA8
    ctx->r22 = ADD32(ctx->r29, 0XA8);
    // 0x800D314C: jal         0x800E3958
    // 0x800D3150: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800E3958(rdram, ctx);
        goto after_2;
    // 0x800D3150: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x800D3154: addiu       $s1, $sp, 0x98
    ctx->r17 = ADD32(ctx->r29, 0X98);
    // 0x800D3158: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D315C: jal         0x800BD64C
    // 0x800D3160: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    func_800BD64C(rdram, ctx);
        goto after_3;
    // 0x800D3160: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    after_3:
    // 0x800D3164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D3168: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D316C: jal         0x800EFB58
    // 0x800D3170: addiu       $a2, $s3, 0x4
    ctx->r6 = ADD32(ctx->r19, 0X4);
    func_800EFB58(rdram, ctx);
        goto after_4;
    // 0x800D3170: addiu       $a2, $s3, 0x4
    ctx->r6 = ADD32(ctx->r19, 0X4);
    after_4:
    // 0x800D3174: addiu       $s2, $sp, 0x8C
    ctx->r18 = ADD32(ctx->r29, 0X8C);
    // 0x800D3178: jal         0x800EFD3C
    // 0x800D317C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFD3C(rdram, ctx);
        goto after_5;
    // 0x800D317C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x800D3180: lw          $a1, 0x28($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X28);
    // 0x800D3184: lw          $a2, 0x2C($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X2C);
    // 0x800D3188: lw          $a3, 0x30($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X30);
    // 0x800D318C: addiu       $s5, $sp, 0x80
    ctx->r21 = ADD32(ctx->r29, 0X80);
    // 0x800D3190: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D3194: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800D3198: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800D319C: jal         0x800EFA88
    // 0x800D31A0: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    func_800EFA88(rdram, ctx);
        goto after_6;
    // 0x800D31A0: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    after_6:
    // 0x800D31A4: jal         0x800BCC58
    // 0x800D31A8: nop

    func_800BCC58(rdram, ctx);
        goto after_7;
    // 0x800D31A8: nop

    after_7:
    // 0x800D31AC: bne         $v0, $zero, L_800D3264
    if (ctx->r2 != 0) {
        // 0x800D31B0: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800D3264;
    }
    // 0x800D31B0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800D31B4: jal         0x800F2100
    // 0x800D31B8: lwc1        $f12, 0xA8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA8);
    mlAbsF(rdram, ctx);
        goto after_8;
    // 0x800D31B8: lwc1        $f12, 0xA8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA8);
    after_8:
    // 0x800D31BC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800D31C0: jal         0x800F2100
    // 0x800D31C4: lwc1        $f12, 0xAC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XAC);
    mlAbsF(rdram, ctx);
        goto after_9;
    // 0x800D31C4: lwc1        $f12, 0xAC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XAC);
    after_9:
    // 0x800D31C8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800D31CC: nop

    // 0x800D31D0: bc1f        L_800D31E0
    if (!c1cs) {
        // 0x800D31D4: nop
    
            goto L_800D31E0;
    }
    // 0x800D31D4: nop

    // 0x800D31D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800D31DC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800D31E0:
    // 0x800D31E0: jal         0x800F2100
    // 0x800D31E4: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    mlAbsF(rdram, ctx);
        goto after_10;
    // 0x800D31E4: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    after_10:
    // 0x800D31E8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800D31EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D31F0: bc1fl       L_800D3200
    if (!c1cs) {
        // 0x800D31F4: sll         $s0, $s4, 2
        ctx->r16 = S32(ctx->r20 << 2);
            goto L_800D3200;
    }
    goto skip_0;
    // 0x800D31F4: sll         $s0, $s4, 2
    ctx->r16 = S32(ctx->r20 << 2);
    skip_0:
    // 0x800D31F8: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800D31FC: sll         $s0, $s4, 2
    ctx->r16 = S32(ctx->r20 << 2);
L_800D3200:
    // 0x800D3200: addu        $v0, $s6, $s0
    ctx->r2 = ADD32(ctx->r22, ctx->r16);
    // 0x800D3204: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800D3208: addu        $t6, $s1, $s0
    ctx->r14 = ADD32(ctx->r17, ctx->r16);
    // 0x800D320C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800D3210: nop

    // 0x800D3214: bc1fl       L_800D3230
    if (!c1cs) {
        // 0x800D3218: addiu       $t9, $sp, 0xAC
        ctx->r25 = ADD32(ctx->r29, 0XAC);
            goto L_800D3230;
    }
    goto skip_1;
    // 0x800D3218: addiu       $t9, $sp, 0xAC
    ctx->r25 = ADD32(ctx->r29, 0XAC);
    skip_1:
    // 0x800D321C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800D3220: addu        $t8, $s5, $s0
    ctx->r24 = ADD32(ctx->r21, ctx->r16);
    // 0x800D3224: b           L_800D3264
    // 0x800D3228: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_800D3264;
    // 0x800D3228: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800D322C: addiu       $t9, $sp, 0xAC
    ctx->r25 = ADD32(ctx->r29, 0XAC);
L_800D3230:
    // 0x800D3230: bne         $v0, $t9, L_800D3254
    if (ctx->r2 != ctx->r25) {
        // 0x800D3234: addu        $t0, $s1, $s0
        ctx->r8 = ADD32(ctx->r17, ctx->r16);
            goto L_800D3254;
    }
    // 0x800D3234: addu        $t0, $s1, $s0
    ctx->r8 = ADD32(ctx->r17, ctx->r16);
    // 0x800D3238: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800D323C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D3240: jal         0x800F0E28
    // 0x800D3244: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_800F0E28(rdram, ctx);
        goto after_11;
    // 0x800D3244: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_11:
    // 0x800D3248: addu        $t1, $s2, $s0
    ctx->r9 = ADD32(ctx->r18, ctx->r16);
    // 0x800D324C: b           L_800D3264
    // 0x800D3250: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
        goto L_800D3264;
    // 0x800D3250: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_800D3254:
    // 0x800D3254: addu        $t2, $s1, $s0
    ctx->r10 = ADD32(ctx->r17, ctx->r16);
    // 0x800D3258: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800D325C: addu        $t4, $s2, $s0
    ctx->r12 = ADD32(ctx->r18, ctx->r16);
    // 0x800D3260: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_800D3264:
    // 0x800D3264: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800D3268: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800D326C: addiu       $s2, $sp, 0x80
    ctx->r18 = ADD32(ctx->r29, 0X80);
    // 0x800D3270: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
    // 0x800D3274: addiu       $s1, $sp, 0x8C
    ctx->r17 = ADD32(ctx->r29, 0X8C);
    // 0x800D3278: addiu       $s4, $sp, 0x98
    ctx->r20 = ADD32(ctx->r29, 0X98);
L_800D327C:
    // 0x800D327C: jal         0x800E42C0
    // 0x800D3280: nop

    func_800E42C0(rdram, ctx);
        goto after_12;
    // 0x800D3280: nop

    after_12:
    // 0x800D3284: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800D3288: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800D328C: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800D3290: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800D3294: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800D3298: nop

    // 0x800D329C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D32A0: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800D32A4: nop

    // 0x800D32A8: bc1f        L_800D32E0
    if (!c1cs) {
        // 0x800D32AC: nop
    
            goto L_800D32E0;
    }
    // 0x800D32AC: nop

    // 0x800D32B0: jal         0x800E42C0
    // 0x800D32B4: nop

    func_800E42C0(rdram, ctx);
        goto after_13;
    // 0x800D32B4: nop

    after_13:
    // 0x800D32B8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800D32BC: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800D32C0: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800D32C4: nop

    // 0x800D32C8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D32CC: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D32D0: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800D32D4: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800D32D8: nop

    // 0x800D32DC: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
L_800D32E0:
    // 0x800D32E0: jal         0x800E42C0
    // 0x800D32E4: nop

    func_800E42C0(rdram, ctx);
        goto after_14;
    // 0x800D32E4: nop

    after_14:
    // 0x800D32E8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800D32EC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800D32F0: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800D32F4: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800D32F8: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800D32FC: nop

    // 0x800D3300: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D3304: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800D3308: nop

    // 0x800D330C: bc1fl       L_800D3348
    if (!c1cs) {
        // 0x800D3310: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800D3348;
    }
    goto skip_2;
    // 0x800D3310: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_2:
    // 0x800D3314: jal         0x800E42C0
    // 0x800D3318: nop

    func_800E42C0(rdram, ctx);
        goto after_15;
    // 0x800D3318: nop

    after_15:
    // 0x800D331C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800D3320: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800D3324: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800D3328: nop

    // 0x800D332C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D3330: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D3334: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800D3338: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800D333C: nop

    // 0x800D3340: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800D3344: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800D3348:
    // 0x800D3348: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800D334C: bne         $s1, $s4, L_800D327C
    if (ctx->r17 != ctx->r20) {
        // 0x800D3350: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800D327C;
    }
    // 0x800D3350: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800D3354: addiu       $a0, $s3, 0x34
    ctx->r4 = ADD32(ctx->r19, 0X34);
    // 0x800D3358: jal         0x800EB5E0
    // 0x800D335C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EB5E0(rdram, ctx);
        goto after_16;
    // 0x800D335C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_16:
    // 0x800D3360: jal         0x800BDC5C
    // 0x800D3364: nop

    func_800BDC5C(rdram, ctx);
        goto after_17;
    // 0x800D3364: nop

    after_17:
    // 0x800D3368: lw          $s5, 0x8C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X8C);
    // 0x800D336C: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x800D3370: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800D3374: slt         $at, $t7, $s5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800D3378: bne         $at, $zero, L_800D346C
    if (ctx->r1 != 0) {
        // 0x800D337C: addiu       $s7, $sp, 0x58
        ctx->r23 = ADD32(ctx->r29, 0X58);
            goto L_800D346C;
    }
    // 0x800D337C: addiu       $s7, $sp, 0x58
    ctx->r23 = ADD32(ctx->r29, 0X58);
    // 0x800D3380: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x800D3384: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x800D3388: lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X90);
L_800D338C:
    // 0x800D338C: slt         $at, $v1, $s2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800D3390: bnel        $at, $zero, L_800D345C
    if (ctx->r1 != 0) {
        // 0x800D3394: lw          $t4, 0x80($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X80);
            goto L_800D345C;
    }
    goto skip_3;
    // 0x800D3394: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    skip_3:
    // 0x800D3398: lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X94);
L_800D339C:
    // 0x800D339C: sll         $s4, $s5, 3
    ctx->r20 = S32(ctx->r21 << 3);
    // 0x800D33A0: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800D33A4: bnel        $at, $zero, L_800D344C
    if (ctx->r1 != 0) {
        // 0x800D33A8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800D344C;
    }
    goto skip_4;
    // 0x800D33A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x800D33AC: lw          $t8, 0x20($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X20);
L_800D33B0:
    // 0x800D33B0: lw          $t4, 0x1C($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X1C);
    // 0x800D33B4: lw          $t7, 0x4($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4);
    // 0x800D33B8: multu       $t8, $s1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D33BC: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800D33C0: addu        $t8, $t7, $s5
    ctx->r24 = ADD32(ctx->r15, ctx->r21);
    // 0x800D33C4: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x800D33C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800D33CC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800D33D0: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
    // 0x800D33D4: multu       $s2, $t4
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D33D8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800D33DC: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x800D33E0: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x800D33E4: lw          $t1, 0xC($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XC);
    // 0x800D33E8: addu        $t3, $t2, $s4
    ctx->r11 = ADD32(ctx->r10, ctx->r20);
    // 0x800D33EC: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x800D33F0: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800D33F4: mflo        $t5
    ctx->r13 = lo;
    // 0x800D33F8: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800D33FC: addu        $s0, $t3, $t6
    ctx->r16 = ADD32(ctx->r11, ctx->r14);
    // 0x800D3400: jal         0x800E9DCC
    // 0x800D3404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9DCC(rdram, ctx);
        goto after_18;
    // 0x800D3404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x800D3408: beq         $v0, $zero, L_800D3430
    if (ctx->r2 == 0) {
        // 0x800D340C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D3430;
    }
    // 0x800D340C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3410: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800D3414: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800D3418: jal         0x800D2F44
    // 0x800D341C: addiu       $a3, $sp, 0xB4
    ctx->r7 = ADD32(ctx->r29, 0XB4);
    func_800D2F44(rdram, ctx);
        goto after_19;
    // 0x800D341C: addiu       $a3, $sp, 0xB4
    ctx->r7 = ADD32(ctx->r29, 0XB4);
    after_19:
    // 0x800D3420: beq         $v0, $zero, L_800D3430
    if (ctx->r2 == 0) {
        // 0x800D3424: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D3430;
    }
    // 0x800D3424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3428: jal         0x800EB5E0
    // 0x800D342C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EB5E0(rdram, ctx);
        goto after_20;
    // 0x800D342C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_20:
L_800D3430:
    // 0x800D3430: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x800D3434: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D3438: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800D343C: beql        $at, $zero, L_800D33B0
    if (ctx->r1 == 0) {
        // 0x800D3440: lw          $t8, 0x20($s3)
        ctx->r24 = MEM_W(ctx->r19, 0X20);
            goto L_800D33B0;
    }
    goto skip_5;
    // 0x800D3440: lw          $t8, 0x20($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X20);
    skip_5:
    // 0x800D3444: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x800D3448: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D344C:
    // 0x800D344C: slt         $at, $v1, $s2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800D3450: beql        $at, $zero, L_800D339C
    if (ctx->r1 == 0) {
        // 0x800D3454: lw          $s1, 0x94($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X94);
            goto L_800D339C;
    }
    goto skip_6;
    // 0x800D3454: lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X94);
    skip_6:
    // 0x800D3458: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
L_800D345C:
    // 0x800D345C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800D3460: slt         $at, $t4, $s5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800D3464: beql        $at, $zero, L_800D338C
    if (ctx->r1 == 0) {
        // 0x800D3468: lw          $s2, 0x90($sp)
        ctx->r18 = MEM_W(ctx->r29, 0X90);
            goto L_800D338C;
    }
    goto skip_7;
    // 0x800D3468: lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X90);
    skip_7:
L_800D346C:
    // 0x800D346C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800D3470: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800D3474: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D3478: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D347C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D3480: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D3484: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D3488: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800D348C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800D3490: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800D3494: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800D3498: jr          $ra
    // 0x800D349C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800D349C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_800F682C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F682C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6834: jal         0x800F6D24
    // 0x800F6838: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F6D24(rdram, ctx);
        goto after_0;
    // 0x800F6838: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F683C: beq         $v0, $zero, L_800F684C
    if (ctx->r2 == 0) {
        // 0x800F6840: nop
    
            goto L_800F684C;
    }
    // 0x800F6840: nop

    // 0x800F6844: b           L_800F68A8
    // 0x800F6848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F68A8;
    // 0x800F6848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F684C:
    // 0x800F684C: jal         0x800F6478
    // 0x800F6850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F6478(rdram, ctx);
        goto after_1;
    // 0x800F6850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800F6854: bne         $v0, $zero, L_800F6864
    if (ctx->r2 != 0) {
        // 0x800F6858: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_800F6864;
    }
    // 0x800F6858: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800F685C: b           L_800F68A8
    // 0x800F6860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F68A8;
    // 0x800F6860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F6864:
    // 0x800F6864: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800F6868: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F686C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F6870: jal         0x8009BD44
    // 0x800F6874: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009BD44(rdram, ctx);
        goto after_2;
    // 0x800F6874: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_2:
    // 0x800F6878: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F687C: bne         $v0, $at, L_800F688C
    if (ctx->r2 != ctx->r1) {
        // 0x800F6880: nop
    
            goto L_800F688C;
    }
    // 0x800F6880: nop

    // 0x800F6884: b           L_800F68A8
    // 0x800F6888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F68A8;
    // 0x800F6888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F688C:
    // 0x800F688C: jal         0x800F6C1C
    // 0x800F6890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F6C1C(rdram, ctx);
        goto after_3;
    // 0x800F6890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800F6894: bnel        $v0, $zero, L_800F68A8
    if (ctx->r2 != 0) {
        // 0x800F6898: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F68A8;
    }
    goto skip_0;
    // 0x800F6898: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800F689C: b           L_800F68A8
    // 0x800F68A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F68A8;
    // 0x800F68A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F68A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F68A8:
    // 0x800F68A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F68AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F68B0: jr          $ra
    // 0x800F68B4: nop

    return;
    // 0x800F68B4: nop

;}
RECOMP_FUNC void func_808034C4_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808034C4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808034C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808034CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808034D0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808034D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808034D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808034DC: jal         0x80100094
    // 0x808034E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808034E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808034E4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808034E8: jal         0x80082660
    // 0x808034EC: lh          $a0, 0xC0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XC0);
    _anseq_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808034EC: lh          $a0, 0xC0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XC0);
    after_1:
    // 0x808034F0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x808034F4: lhu         $t6, 0x76($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X76);
    // 0x808034F8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1732, 0X4160) << 16);
    // 0x808034FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803500: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80803504: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80803508: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8080350C: lw          $t9, 0x4160($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(1732, 0X4160));
    // 0x80803510: jal         0x8010588C
    // 0x80803514: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    func_8010588C(rdram, ctx);
        goto after_2;
    // 0x80803514: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    after_2:
    // 0x80803518: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8080351C: andi        $t1, $t0, 0x100
    ctx->r9 = ctx->r8 & 0X100;
    // 0x80803520: beql        $t1, $zero, L_80803538
    if (ctx->r9 == 0) {
        // 0x80803524: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_80803538;
    }
    goto skip_0;
    // 0x80803524: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x80803528: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080352C: nop

    // 0x80803530: swc1        $f4, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f4.u32l;
    // 0x80803534: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
L_80803538:
    // 0x80803538: sll         $t3, $t2, 15
    ctx->r11 = S32(ctx->r10 << 15);
    // 0x8080353C: bgezl       $t3, L_80803550
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80803540: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80803550;
    }
    goto skip_1;
    // 0x80803540: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x80803544: jal         0x80803F7C
    // 0x80803548: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80803F7C_chintrochar(rdram, ctx);
        goto after_3;
    // 0x80803548: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x8080354C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
L_80803550:
    // 0x80803550: sll         $t5, $t4, 14
    ctx->r13 = S32(ctx->r12 << 14);
    // 0x80803554: bgez        $t5, L_80803588
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80803558: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80803588;
    }
    // 0x80803558: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080355C: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
L_80803560:
    // 0x80803560: jal         0x80106790
    // 0x80803564: lw          $a0, 0x104($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X104);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80803564: lw          $a0, 0x104($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X104);
    after_4:
    // 0x80803568: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080356C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80803570: jal         0x80803F24
    // 0x80803574: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80803F24_chintrochar(rdram, ctx);
        goto after_5;
    // 0x80803574: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80803578: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080357C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803580: bne         $s0, $at, L_80803560
    if (ctx->r16 != ctx->r1) {
        // 0x80803584: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80803560;
    }
    // 0x80803584: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80803588:
    // 0x80803588: jal         0x801022E4
    // 0x8080358C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801022E4(rdram, ctx);
        goto after_6;
    // 0x8080358C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80803590: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80803594: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80803598: lw          $t7, 0xC8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC8);
    // 0x8080359C: beq         $v0, $t7, L_808035B0
    if (ctx->r2 == ctx->r15) {
        // 0x808035A0: nop
    
            goto L_808035B0;
    }
    // 0x808035A0: nop

    // 0x808035A4: sw          $v0, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r2;
    // 0x808035A8: jal         0x8080071C
    // 0x808035AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8080071C_chintrochar(rdram, ctx);
        goto after_7;
    // 0x808035AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
L_808035B0:
    // 0x808035B0: jal         0x80104248
    // 0x808035B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80104248(rdram, ctx);
        goto after_8;
    // 0x808035B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x808035B8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808035BC: jal         0x80082658
    // 0x808035C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _anseq_entrypoint_8(rdram, ctx);
        goto after_9;
    // 0x808035C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x808035C4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x808035C8: lh          $a0, 0xC2($t8)
    ctx->r4 = MEM_H(ctx->r24, 0XC2);
    // 0x808035CC: beql        $a0, $zero, L_808035E0
    if (ctx->r4 == 0) {
        // 0x808035D0: lw          $t9, 0x5C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X5C);
            goto L_808035E0;
    }
    goto skip_2;
    // 0x808035D0: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x808035D4: jal         0x800857B8
    // 0x808035D8: nop

    _chblink_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x808035D8: nop

    after_10:
    // 0x808035DC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
L_808035E0:
    // 0x808035E0: lh          $a0, 0xC4($t9)
    ctx->r4 = MEM_H(ctx->r25, 0XC4);
    // 0x808035E4: beq         $a0, $zero, L_808035F4
    if (ctx->r4 == 0) {
        // 0x808035E8: nop
    
            goto L_808035F4;
    }
    // 0x808035E8: nop

    // 0x808035EC: jal         0x800857B8
    // 0x808035F0: nop

    _chblink_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x808035F0: nop

    after_11:
L_808035F4:
    // 0x808035F4: jal         0x800859C0
    // 0x808035F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _chanim_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x808035F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x808035FC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80803600: sll         $t1, $t0, 12
    ctx->r9 = S32(ctx->r8 << 12);
    // 0x80803604: bgezl       $t1, L_80803628
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80803608: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_80803628;
    }
    goto skip_3;
    // 0x80803608: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x8080360C: jal         0x800DA298
    // 0x80803610: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80803610: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_13:
    // 0x80803614: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80803618: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8080361C: jal         0x80085980
    // 0x80803620: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _chanim_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x80803620: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_14:
    // 0x80803624: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
L_80803628:
    // 0x80803628: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x8080362C: beq         $t3, $zero, L_80803694
    if (ctx->r11 == 0) {
        // 0x80803630: sll         $t4, $t2, 13
        ctx->r12 = S32(ctx->r10 << 13);
            goto L_80803694;
    }
    // 0x80803630: sll         $t4, $t2, 13
    ctx->r12 = S32(ctx->r10 << 13);
    // 0x80803634: bgez        $t4, L_8080367C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80803638: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080367C;
    }
    // 0x80803638: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080363C: jal         0x8008FFE8
    // 0x80803640: nop

    func_8008FFE8(rdram, ctx);
        goto after_15;
    // 0x80803640: nop

    after_15:
    // 0x80803644: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80803648: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080364C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803650: jal         0x8010FFB0
    // 0x80803654: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_8010FFB0(rdram, ctx);
        goto after_16;
    // 0x80803654: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_16:
    // 0x80803658: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080365C: jal         0x80100094
    // 0x80803660: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_17;
    // 0x80803660: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80803664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803668: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8080366C: jal         0x800897D8
    // 0x80803670: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_18;
    // 0x80803670: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
    // 0x80803674: b           L_80803698
    // 0x80803678: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
        goto L_80803698;
    // 0x80803678: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
L_8080367C:
    // 0x8080367C: jal         0x80100094
    // 0x80803680: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_19;
    // 0x80803680: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80803684: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803688: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8080368C: jal         0x800897D8
    // 0x80803690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_20;
    // 0x80803690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
L_80803694:
    // 0x80803694: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
L_80803698:
    // 0x80803698: lh          $a0, 0xC6($t5)
    ctx->r4 = MEM_H(ctx->r13, 0XC6);
    // 0x8080369C: beq         $a0, $zero, L_808036BC
    if (ctx->r4 == 0) {
        // 0x808036A0: nop
    
            goto L_808036BC;
    }
    // 0x808036A0: nop

    // 0x808036A4: jal         0x8001B798
    // 0x808036A8: nop

    func_8001B798(rdram, ctx);
        goto after_21;
    // 0x808036A8: nop

    after_21:
    // 0x808036AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808036B0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x808036B4: jal         0x800897D8
    // 0x808036B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_22;
    // 0x808036B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
L_808036BC:
    // 0x808036BC: jal         0x80089C90
    // 0x808036C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_23;
    // 0x808036C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_23:
    // 0x808036C4: bne         $v0, $zero, L_808036DC
    if (ctx->r2 != 0) {
        // 0x808036C8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808036DC;
    }
    // 0x808036C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808036CC: lbu         $t7, 0x65($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X65);
    // 0x808036D0: andi        $t6, $t7, 0xFFFE
    ctx->r14 = ctx->r15 & 0XFFFE;
    // 0x808036D4: b           L_808036FC
    // 0x808036D8: sb          $t6, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r14;
        goto L_808036FC;
    // 0x808036D8: sb          $t6, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r14;
L_808036DC:
    // 0x808036DC: lw          $t8, 0x64($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X64);
    // 0x808036E0: lbu         $t3, 0x65($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X65);
    // 0x808036E4: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x808036E8: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x808036EC: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x808036F0: andi        $t2, $t3, 0xFFFE
    ctx->r10 = ctx->r11 & 0XFFFE;
    // 0x808036F4: or          $t4, $t1, $t2
    ctx->r12 = ctx->r9 | ctx->r10;
    // 0x808036F8: sb          $t4, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r12;
L_808036FC:
    // 0x808036FC: lhu         $t5, 0x76($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X76);
    // 0x80803700: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X416C) << 16);
    // 0x80803704: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80803708: srl         $t7, $t5, 7
    ctx->r15 = S32(U32(ctx->r13) >> 7);
    // 0x8080370C: sll         $t6, $t7, 5
    ctx->r14 = S32(ctx->r15 << 5);
    // 0x80803710: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80803714: lwc1        $f0, 0x416C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X416C));
    // 0x80803718: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8080371C: nop

    // 0x80803720: bc1fl       L_80803738
    if (!c1cs) {
        // 0x80803724: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80803738;
    }
    goto skip_4;
    // 0x80803724: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80803728: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080372C: jal         0x80085770
    // 0x80803730: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_24;
    // 0x80803730: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    after_24:
    // 0x80803734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803738:
    // 0x80803738: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080373C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80803740: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80803744: jr          $ra
    // 0x80803748: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80803748: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80801508_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080150C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801510: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801514: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801518: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8080151C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801520: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80801524: beq         $v0, $zero, L_80801548
    if (ctx->r2 == 0) {
        // 0x80801528: addiu       $a1, $zero, 0x13
        ctx->r5 = ADD32(0, 0X13);
            goto L_80801548;
    }
    // 0x80801528: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x8080152C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801530: beq         $v0, $at, L_80801560
    if (ctx->r2 == ctx->r1) {
        // 0x80801534: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801560;
    }
    // 0x80801534: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801538: beql        $v0, $at, L_8080155C
    if (ctx->r2 == ctx->r1) {
        // 0x8080153C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8080155C;
    }
    goto skip_0;
    // 0x8080153C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x80801540: b           L_80801574
    // 0x80801544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801574;
    // 0x80801544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801548:
    // 0x80801548: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8080154C: jal         0x800856B0
    // 0x80801550: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801550: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801554: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80801558: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_8080155C:
    // 0x8080155C: sw          $t6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r14;
L_80801560:
    // 0x80801560: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80801564: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801568: jal         0x800856D0
    // 0x8080156C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080156C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801574:
    // 0x80801574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801578: jr          $ra
    // 0x8080157C: nop

    return;
    // 0x8080157C: nop

;}
RECOMP_FUNC void func_800C3BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3BDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C3BE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C3BE4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3BE8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3BEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3BF0: beq         $t6, $zero, L_800C3CD4
    if (ctx->r14 == 0) {
        // 0x800C3BF4: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800C3CD4;
    }
    // 0x800C3BF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C3BF8: jal         0x800C1414
    // 0x800C3BFC: sb          $t6, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r14;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3BFC: sb          $t6, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r14;
    after_0:
    // 0x800C3C00: lw          $t7, 0x78($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X78);
    // 0x800C3C04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C3C08: sll         $t9, $t7, 29
    ctx->r25 = S32(ctx->r15 << 29);
    // 0x800C3C0C: bgez        $t9, L_800C3C1C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800C3C10: nop
    
            goto L_800C3C1C;
    }
    // 0x800C3C10: nop

    // 0x800C3C14: jal         0x800FEC60
    // 0x800C3C18: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800FEC60(rdram, ctx);
        goto after_1;
    // 0x800C3C18: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
L_800C3C1C:
    // 0x800C3C1C: jal         0x800C39D0
    // 0x800C3C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C39D0(rdram, ctx);
        goto after_2;
    // 0x800C3C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800C3C24: bnel        $v0, $zero, L_800C3C40
    if (ctx->r2 != 0) {
        // 0x800C3C28: lhu         $t0, 0x7A($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X7A);
            goto L_800C3C40;
    }
    goto skip_0;
    // 0x800C3C28: lhu         $t0, 0x7A($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X7A);
    skip_0:
    // 0x800C3C2C: jal         0x800C42E0
    // 0x800C3C30: lh          $a0, 0x58($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X58);
    func_800C42E0(rdram, ctx);
        goto after_3;
    // 0x800C3C30: lh          $a0, 0x58($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X58);
    after_3:
    // 0x800C3C34: beql        $v0, $zero, L_800C3CD8
    if (ctx->r2 == 0) {
        // 0x800C3C38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C3CD8;
    }
    goto skip_1;
    // 0x800C3C38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800C3C3C: lhu         $t0, 0x7A($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X7A);
L_800C3C40:
    // 0x800C3C40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C3C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C3C48: srl         $t1, $t0, 13
    ctx->r9 = S32(U32(ctx->r8) >> 13);
    // 0x800C3C4C: bnel        $t1, $at, L_800C3C80
    if (ctx->r9 != ctx->r1) {
        // 0x800C3C50: lw          $t5, 0x78($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X78);
            goto L_800C3C80;
    }
    goto skip_2;
    // 0x800C3C50: lw          $t5, 0x78($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X78);
    skip_2:
    // 0x800C3C54: jal         0x800C13A0
    // 0x800C3C58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C13A0(rdram, ctx);
        goto after_4;
    // 0x800C3C58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x800C3C5C: lw          $t2, 0x78($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X78);
    // 0x800C3C60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C3C64: sll         $t3, $t2, 19
    ctx->r11 = S32(ctx->r10 << 19);
    // 0x800C3C68: srl         $t4, $t3, 29
    ctx->r12 = S32(U32(ctx->r11) >> 29);
    // 0x800C3C6C: bne         $t4, $at, L_800C3C9C
    if (ctx->r12 != ctx->r1) {
        // 0x800C3C70: nop
    
            goto L_800C3C9C;
    }
    // 0x800C3C70: nop

    // 0x800C3C74: b           L_800C3CD8
    // 0x800C3C78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800C3CD8;
    // 0x800C3C78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3C7C: lw          $t5, 0x78($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X78);
L_800C3C80:
    // 0x800C3C80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C3C84: sll         $t6, $t5, 19
    ctx->r14 = S32(ctx->r13 << 19);
    // 0x800C3C88: srl         $t7, $t6, 29
    ctx->r15 = S32(U32(ctx->r14) >> 29);
    // 0x800C3C8C: bne         $t7, $at, L_800C3C9C
    if (ctx->r15 != ctx->r1) {
        // 0x800C3C90: nop
    
            goto L_800C3C9C;
    }
    // 0x800C3C90: nop

    // 0x800C3C94: jal         0x800C3CE8
    // 0x800C3C98: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    func_800C3CE8(rdram, ctx);
        goto after_5;
    // 0x800C3C98: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    after_5:
L_800C3C9C:
    // 0x800C3C9C: jal         0x800C15BC
    // 0x800C3CA0: nop

    func_800C15BC(rdram, ctx);
        goto after_6;
    // 0x800C3CA0: nop

    after_6:
    // 0x800C3CA4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C3CA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C3CAC: jal         0x8002EC20
    // 0x800C3CB0: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_7;
    // 0x800C3CB0: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_7:
    // 0x800C3CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C3CB8: jal         0x800C16F8
    // 0x800C3CBC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C16F8(rdram, ctx);
        goto after_8;
    // 0x800C3CBC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x800C3CC0: jal         0x800C1D80
    // 0x800C3CC4: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    func_800C1D80(rdram, ctx);
        goto after_9;
    // 0x800C3CC4: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    after_9:
    // 0x800C3CC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C3CCC: jal         0x8002EC20
    // 0x800C3CD0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_10;
    // 0x800C3CD0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_10:
L_800C3CD4:
    // 0x800C3CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C3CD8:
    // 0x800C3CD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C3CDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C3CE0: jr          $ra
    // 0x800C3CE4: nop

    return;
    // 0x800C3CE4: nop

;}
RECOMP_FUNC void _chexploder_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866B8: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x800866B8);
    return;
    // 0x800866BC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void gccubesearch_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800128: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080012C: jal         0x808000CC
    // 0x80800130: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    gccubesearch_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800130: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800134: bne         $v0, $zero, L_80800144
    if (ctx->r2 != 0) {
        // 0x80800138: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800144;
    }
    // 0x80800138: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080013C: b           L_80800150
    // 0x80800140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800150;
    // 0x80800140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800144:
    // 0x80800144: jal         0x800EE84C
    // 0x80800148: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EE84C(rdram, ctx);
        goto after_1;
    // 0x80800148: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8080014C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800150:
    // 0x80800150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800154: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800158: jr          $ra
    // 0x8080015C: nop

    return;
    // 0x8080015C: nop

;}
RECOMP_FUNC void _bskazfly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083378: syscall     57
    recomp_syscall_handler(rdram, ctx, 0x80083378);
    return;
    // 0x8008337C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chfreezy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1044, 0X700) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x700
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1044, 0X700));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x700
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1044, 0X700));
;}
RECOMP_FUNC void func_808000C8_bsblongleg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D8: jal         0x80091554
    // 0x808000DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_getPrevious(rdram, ctx);
        goto after_0;
    // 0x808000DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808000E0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x80091538
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_get(rdram, ctx);
        goto after_1;
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808000F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: jal         0x80084430
    // 0x808000FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _baalarm_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800100: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80800104: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x800915E8
    // 0x80800110: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_isAt(rdram, ctx);
        goto after_3;
    // 0x80800110: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800114: beq         $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x80800118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800128;
    }
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: addiu       $a1, $zero, 0x3EB
    ctx->r5 = ADD32(0, 0X3EB);
    // 0x80800120: jal         0x8009DE38
    // 0x80800124: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_4;
    // 0x80800124: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
L_80800128:
    // 0x80800128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080012C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800130: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

;}
RECOMP_FUNC void _ncbastring_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089150: syscall     763
    recomp_syscall_handler(rdram, ctx, 0x80089150);
    return;
    // 0x80089154: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chchuffy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1700, 0X2434) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2434
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1700, 0X2434));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2434
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1700, 0X2434));
;}
RECOMP_FUNC void func_800E6A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6A00: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800E6A04: jr          $ra
    // 0x800E6A08: lbu         $v0, 0x75E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X75E0);
    return;
    // 0x800E6A08: lbu         $v0, 0x75E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X75E0);
    // 0x800E6A0C: nop

;}
RECOMP_FUNC void func_80800944_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800944: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800948: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080094C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800950: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800954: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800958: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8080095C: jal         0x80101E14
    // 0x80800960: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x80800960: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800964: beq         $v0, $zero, L_80800A8C
    if (ctx->r2 == 0) {
        // 0x80800968: addiu       $s1, $sp, 0x34
        ctx->r17 = ADD32(ctx->r29, 0X34);
            goto L_80800A8C;
    }
    // 0x80800968: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x8080096C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800970: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800974: jal         0x800EE7F8
    // 0x80800978: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800978: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x8080097C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X1520) << 16);
    // 0x80800980: addiu       $a2, $a2, 0x1520
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X1520));
    // 0x80800984: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800988: jal         0x80089D18
    // 0x8080098C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080098C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800990: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800994: jal         0x800889A0
    // 0x80800998: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _fxripple_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800998: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8080099C: jal         0x800889D8
    // 0x808009A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _fxsplash25d_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808009A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x808009A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009A8: jal         0x80088AE8
    // 0x808009AC: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    _fxsplash_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808009AC: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    after_5:
    // 0x808009B0: addiu       $t6, $zero, 0x15E
    ctx->r14 = ADD32(0, 0X15E);
    // 0x808009B4: addiu       $t7, $zero, 0x1F4
    ctx->r15 = ADD32(0, 0X1F4);
    // 0x808009B8: addiu       $t8, $zero, 0x15E
    ctx->r24 = ADD32(0, 0X15E);
    // 0x808009BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009C0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808009C4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808009C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009D0: addiu       $a1, $zero, -0x15E
    ctx->r5 = ADD32(0, -0X15E);
    // 0x808009D4: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x808009D8: jal         0x800BA930
    // 0x808009DC: addiu       $a3, $zero, -0x15E
    ctx->r7 = ADD32(0, -0X15E);
    func_800BA930(rdram, ctx);
        goto after_6;
    // 0x808009DC: addiu       $a3, $zero, -0x15E
    ctx->r7 = ADD32(0, -0X15E);
    after_6:
    // 0x808009E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E4: jal         0x800BA22C
    // 0x808009E8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x808009E8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_7:
    // 0x808009EC: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x808009F0: addiu       $t0, $zero, 0x320
    ctx->r8 = ADD32(0, 0X320);
    // 0x808009F4: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
    // 0x808009F8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x808009FC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800A00: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A08: addiu       $a1, $zero, -0x96
    ctx->r5 = ADD32(0, -0X96);
    // 0x80800A0C: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80800A10: jal         0x800BA930
    // 0x80800A14: addiu       $a3, $zero, -0x96
    ctx->r7 = ADD32(0, -0X96);
    func_800BA930(rdram, ctx);
        goto after_8;
    // 0x80800A14: addiu       $a3, $zero, -0x96
    ctx->r7 = ADD32(0, -0X96);
    after_8:
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A1C: jal         0x800BA22C
    // 0x80800A20: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800BA22C(rdram, ctx);
        goto after_9;
    // 0x80800A20: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_9:
    // 0x80800A24: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800A28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A2C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800A30: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80800A34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A38: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800A3C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80800A40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800A44: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80800A48: jal         0x800889D0
    // 0x80800A4C: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    _fxairbub_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800A4C: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    after_10:
    // 0x80800A50: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x80800A54: addiu       $t4, $zero, -0x96
    ctx->r12 = ADD32(0, -0X96);
    // 0x80800A58: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x80800A5C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A60: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80800A64: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80800A68: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800A6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A70: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x80800A74: addiu       $a2, $zero, -0xFA
    ctx->r6 = ADD32(0, -0XFA);
    // 0x80800A78: jal         0x800BA930
    // 0x80800A7C: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    func_800BA930(rdram, ctx);
        goto after_11;
    // 0x80800A7C: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    after_11:
    // 0x80800A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A84: jal         0x800BA22C
    // 0x80800A88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BA22C(rdram, ctx);
        goto after_12;
    // 0x80800A88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
L_80800A8C:
    // 0x80800A8C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A90: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800A94: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800A98: jr          $ra
    // 0x80800A9C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800A9C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bsfirstp_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804F14: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80804F18: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB520) << 16);
    // 0x80804F1C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80804F20: jr          $ra
    // 0x80804F24: lw          $v0, -0x4AE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB520));
    return;
    // 0x80804F24: lw          $v0, -0x4AE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB520));
;}
RECOMP_FUNC void func_80800978_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080097C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800980: jal         0x80800FAC
    // 0x80800984: nop

    func_80800FAC_chboggyfatboy(rdram, ctx);
        goto after_0;
    // 0x80800984: nop

    after_0:
    // 0x80800988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080098C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800990: jr          $ra
    // 0x80800994: nop

    return;
    // 0x80800994: nop

;}
RECOMP_FUNC void func_808087F0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808087F0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808087F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808087F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808087FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80808800: jal         0x80100094
    // 0x80808804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80808804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808808: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8080880C: jal         0x808086A8
    // 0x80808810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808086A8_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80808810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80808814: beq         $v0, $zero, L_80808898
    if (ctx->r2 == 0) {
        // 0x80808818: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_80808898;
    }
    // 0x80808818: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8080881C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808820: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80808824: jal         0x8008A0D0
    // 0x80808828: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80808828: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x8080882C: beq         $v0, $zero, L_80808898
    if (ctx->r2 == 0) {
        // 0x80808830: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_80808898;
    }
    // 0x80808830: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80808834: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80808838: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8080883C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808840: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80808844: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80808848: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8080884C: jal         0x8008A0D0
    // 0x80808850: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80808850: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80808854: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80808858: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080885C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80808860: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80808864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808868: jal         0x800EFE50
    // 0x8080886C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    func_800EFE50(rdram, ctx);
        goto after_4;
    // 0x8080886C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_4:
    // 0x80808870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808874: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80808878: jal         0x800EF1B8
    // 0x8080887C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_5;
    // 0x8080887C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_5:
    // 0x80808880: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80808884: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80808888: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080888C: lwc1        $f10, 0x8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80808890: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80808894: swc1        $f18, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f18.u32l;
L_80808898:
    // 0x80808898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080889C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808088A0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808088A4: jr          $ra
    // 0x808088A8: nop

    return;
    // 0x808088A8: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: beq         $a0, $zero, L_8080051C
    if (ctx->r4 == 0) {
        // 0x8080050C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8080051C;
    }
    // 0x8080050C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800510: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800514: jr          $ra
    // 0x80800518: sb          $zero, 0x75F3($at)
    MEM_B(0X75F3, ctx->r1) = 0;
    return;
    // 0x80800518: sb          $zero, 0x75F3($at)
    MEM_B(0X75F3, ctx->r1) = 0;
L_8080051C:
    // 0x8080051C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800520: sb          $t6, 0x75F3($at)
    MEM_B(0X75F3, ctx->r1) = ctx->r14;
    // 0x80800524: jr          $ra
    // 0x80800528: nop

    return;
    // 0x80800528: nop

;}
RECOMP_FUNC void func_80800240_chjamjarsdummy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800248: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x8080024C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80800250: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1568, 0X32C) << 16);
    // 0x80800254: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800258: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8080025C: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80800260: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    // 0x80800264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800268: jal         0x80103140
    // 0x8080026C: lhu         $a1, 0x32C($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1568, 0X32C));
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x8080026C: lhu         $a1, 0x32C($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1568, 0X32C));
    after_0:
    // 0x80800270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800274: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1568, 0X32E) << 16);
    // 0x80800278: lw          $t0, 0x6C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X6C);
    // 0x8080027C: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x80800280: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800284: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x80800288: jal         0x80102424
    // 0x8080028C: lh          $a1, 0x32E($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1568, 0X32E));
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080028C: lh          $a1, 0x32E($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1568, 0X32E));
    after_1:
    // 0x80800290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800294: jal         0x80800000
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_chjamjarsdummy(rdram, ctx);
        goto after_2;
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080029C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void _bsmumswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800838F8: syscall     81
    recomp_syscall_handler(rdram, ctx, 0x800838F8);
    return;
    // 0x800838FC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800128_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080012C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800130: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800134: jal         0x8009EF1C
    // 0x80800138: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800138: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080013C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800140: jal         0x8009EF10
    // 0x80800144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800148: bne         $v0, $zero, L_80800164
    if (ctx->r2 != 0) {
        // 0x8080014C: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80800164;
    }
    // 0x8080014C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800154: jal         0x8009B9B0
    // 0x80800158: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800158: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x8080015C: b           L_80800190
    // 0x80800160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800190;
    // 0x80800160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800164:
    // 0x80800164: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800168: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080016C: jal         0x800F1214
    // 0x80800170: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800170: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_3:
    // 0x80800174: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800178: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080017C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800180: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800184: jal         0x8009B9B0
    // 0x80800188: nop

    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800188: nop

    after_4:
    // 0x8080018C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800190:
    // 0x80800190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800194: jr          $ra
    // 0x80800198: nop

    return;
    // 0x80800198: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084318: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084318);
    return;
    // 0x8008431C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_80800158_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080015C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800160: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800168: beq         $a1, $at, L_808001E4
    if (ctx->r5 == ctx->r1) {
        // 0x8080016C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_808001E4;
    }
    // 0x8080016C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800170: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800174: beq         $a1, $at, L_808001A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800178: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_808001A8;
    }
    // 0x80800178: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080017C: beq         $a1, $at, L_80800198
    if (ctx->r5 == ctx->r1) {
        // 0x80800180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800198;
    }
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800188: beql        $a1, $at, L_80800234
    if (ctx->r5 == ctx->r1) {
        // 0x8080018C: lw          $t1, 0x3C($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X3C);
            goto L_80800234;
    }
    goto skip_0;
    // 0x8080018C: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    skip_0:
    // 0x80800190: b           L_80800260
    // 0x80800194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800260;
    // 0x80800194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800198:
    // 0x80800198: jal         0x80800680
    // 0x8080019C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800680_chhellterskelter(rdram, ctx);
        goto after_0;
    // 0x8080019C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808001A0: b           L_80800260
    // 0x808001A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x808001A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001A8:
    // 0x808001A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001AC: bne         $a2, $at, L_808001DC
    if (ctx->r6 != ctx->r1) {
        // 0x808001B0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(964, 0X7A0) << 16);
            goto L_808001DC;
    }
    // 0x808001B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(964, 0X7A0) << 16);
    // 0x808001B4: jal         0x80085728
    // 0x808001B8: lwc1        $f12, 0x7A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(964, 0X7A0));
    _capod_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x808001B8: lwc1        $f12, 0x7A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(964, 0X7A0));
    after_1:
    // 0x808001BC: beq         $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001C0: nop
    
            goto L_808001DC;
    }
    // 0x808001C0: nop

    // 0x808001C4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: addiu       $a1, $zero, 0x210
    ctx->r5 = ADD32(0, 0X210);
    // 0x808001D0: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808001D4: jal         0x80108B04
    // 0x808001D8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x808001D8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_2:
L_808001DC:
    // 0x808001DC: b           L_80800260
    // 0x808001E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800260;
    // 0x808001E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808001E4:
    // 0x808001E4: addiu       $a0, $zero, 0x6A1
    ctx->r4 = ADD32(0, 0X6A1);
    // 0x808001E8: jal         0x800DA9E4
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_3;
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808001F0: bne         $v0, $zero, L_80800210
    if (ctx->r2 != 0) {
        // 0x808001F4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800210;
    }
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800200: jal         0x80085708
    // 0x80800204: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800204: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_4:
    // 0x80800208: b           L_80800260
    // 0x8080020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x8080020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800210:
    // 0x80800210: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: addiu       $a1, $zero, 0x210
    ctx->r5 = ADD32(0, 0X210);
    // 0x8080021C: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800220: jal         0x80108B04
    // 0x80800224: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x80800224: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_5:
    // 0x80800228: b           L_80800260
    // 0x8080022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x8080022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800230: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
L_80800234:
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: addiu       $a1, $zero, 0x210
    ctx->r5 = ADD32(0, 0X210);
    // 0x8080023C: bnel        $t1, $zero, L_80800260
    if (ctx->r9 != 0) {
        // 0x80800240: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800260;
    }
    goto skip_1;
    // 0x80800240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800244: jal         0x80089C70
    // 0x80800248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiefind_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8080024C: b           L_80800260
    // 0x80800250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x80800250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800254: b           L_80800260
    // 0x80800258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800260;
    // 0x80800258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080025C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800260:
    // 0x80800260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
