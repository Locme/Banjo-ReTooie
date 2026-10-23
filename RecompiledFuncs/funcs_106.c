#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chplatuegrill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877A8: syscall     623
    recomp_syscall_handler(rdram, ctx, 0x800877A8);
    return;
    // 0x800877AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800E76A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E76A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E76A8: addiu       $v0, $v0, -0x2A80
    ctx->r2 = ADD32(ctx->r2, -0X2A80);
    // 0x800E76AC: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x800E76B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E76B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E76B8: beql        $a1, $t6, L_800E776C
    if (ctx->r5 == ctx->r14) {
        // 0x800E76BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E776C;
    }
    goto skip_0;
    // 0x800E76BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E76C0: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
    // 0x800E76C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E76C8: jal         0x800E765C
    // 0x800E76CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800E765C(rdram, ctx);
        goto after_0;
    // 0x800E76CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E76D0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800E76D4: lui         $t8, 0xFC11
    ctx->r24 = S32(0XFC11 << 16);
    // 0x800E76D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E76DC: beq         $a1, $zero, L_800E7704
    if (ctx->r5 == 0) {
        // 0x800E76E0: ori         $t8, $t8, 0x9623
        ctx->r24 = ctx->r24 | 0X9623;
            goto L_800E7704;
    }
    // 0x800E76E0: ori         $t8, $t8, 0x9623
    ctx->r24 = ctx->r24 | 0X9623;
    // 0x800E76E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E76E8: beq         $a1, $at, L_800E7724
    if (ctx->r5 == ctx->r1) {
        // 0x800E76EC: lui         $t1, 0xFCFF
        ctx->r9 = S32(0XFCFF << 16);
            goto L_800E7724;
    }
    // 0x800E76EC: lui         $t1, 0xFCFF
    ctx->r9 = S32(0XFCFF << 16);
    // 0x800E76F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E76F4: beq         $a1, $at, L_800E7748
    if (ctx->r5 == ctx->r1) {
        // 0x800E76F8: lui         $t4, 0xFCFF
        ctx->r12 = S32(0XFCFF << 16);
            goto L_800E7748;
    }
    // 0x800E76F8: lui         $t4, 0xFCFF
    ctx->r12 = S32(0XFCFF << 16);
    // 0x800E76FC: b           L_800E776C
    // 0x800E7700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E776C;
    // 0x800E7700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E7704:
    // 0x800E7704: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E7708: lui         $t9, 0xFF2F
    ctx->r25 = S32(0XFF2F << 16);
    // 0x800E770C: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800E7710: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800E7714: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800E7718: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800E771C: b           L_800E7768
    // 0x800E7720: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_800E7768;
    // 0x800E7720: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800E7724:
    // 0x800E7724: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E7728: lui         $t2, 0xFF0C
    ctx->r10 = S32(0XFF0C << 16);
    // 0x800E772C: ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // 0x800E7730: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800E7734: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800E7738: ori         $t1, $t1, 0x9403
    ctx->r9 = ctx->r9 | 0X9403;
    // 0x800E773C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800E7740: b           L_800E7768
    // 0x800E7744: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
        goto L_800E7768;
    // 0x800E7744: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
L_800E7748:
    // 0x800E7748: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E774C: lui         $t5, 0xFFFD
    ctx->r13 = S32(0XFFFD << 16);
    // 0x800E7750: ori         $t5, $t5, 0xF6FB
    ctx->r13 = ctx->r13 | 0XF6FB;
    // 0x800E7754: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800E7758: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800E775C: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x800E7760: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800E7764: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_800E7768:
    // 0x800E7768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E776C:
    // 0x800E776C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E7770: jr          $ra
    // 0x800E7774: nop

    return;
    // 0x800E7774: nop

;}
RECOMP_FUNC void chquiz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080653C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2484, 0X7684) << 16);
    // 0x80806540: jr          $ra
    // 0x80806544: addiu       $v0, $v0, 0x7684
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7684));
    return;
    // 0x80806544: addiu       $v0, $v0, 0x7684
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7684));
    // 0x80806548: nop

    // 0x8080654C: nop

;}
RECOMP_FUNC void func_80020C08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020C08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80020C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020C10: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80020C14: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80020C18: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80020C1C: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x80020C20: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80020C24: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80020C28: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80020C2C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80020C30: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80020C34: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80020C38: beq         $t9, $zero, L_80020C5C
    if (ctx->r25 == 0) {
        // 0x80020C3C: nop
    
            goto L_80020C5C;
    }
    // 0x80020C3C: nop

    // 0x80020C40: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80020C44: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x80020C48: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80020C4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80020C50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80020C54: jal         0x80026500
    // 0x80020C58: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x80020C58: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_0:
L_80020C5C:
    // 0x80020C5C: b           L_80020C64
    // 0x80020C60: nop

        goto L_80020C64;
    // 0x80020C60: nop

L_80020C64:
    // 0x80020C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020C68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80020C6C: jr          $ra
    // 0x80020C70: nop

    return;
    // 0x80020C70: nop

;}
RECOMP_FUNC void func_80801188_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080118C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801190: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801198: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080119C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x808011A0: jal         0x800B26F0
    // 0x808011A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800B26F0(rdram, ctx);
        goto after_0;
    // 0x808011A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808011A8: beq         $v0, $zero, L_808011C8
    if (ctx->r2 == 0) {
        // 0x808011AC: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_808011C8;
    }
    // 0x808011AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808011B0: lbu         $t7, 0x70($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X70);
    // 0x808011B4: lbu         $t9, 0x71($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X71);
    // 0x808011B8: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x808011BC: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x808011C0: sb          $t8, 0x70($a2)
    MEM_B(0X70, ctx->r6) = ctx->r24;
    // 0x808011C4: sb          $t0, 0x71($a2)
    MEM_B(0X71, ctx->r6) = ctx->r8;
L_808011C8:
    // 0x808011C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011D0: jr          $ra
    // 0x808011D4: nop

    return;
    // 0x808011D4: nop

;}
RECOMP_FUNC void func_800A5BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5BE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5BEC: jal         0x80085920
    // 0x800A5BF0: addiu       $a0, $a0, 0x7110
    ctx->r4 = ADD32(ctx->r4, 0X7110);
    _chbaddieDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800A5BF0: addiu       $a0, $a0, 0x7110
    ctx->r4 = ADD32(ctx->r4, 0X7110);
    after_0:
    // 0x800A5BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5BF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5BFC: jr          $ra
    // 0x800A5C00: nop

    return;
    // 0x800A5C00: nop

;}
RECOMP_FUNC void func_800A3274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3274: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3278: jr          $ra
    // 0x800A327C: lbu         $v0, 0x29($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X29);
    return;
    // 0x800A327C: lbu         $v0, 0x29($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X29);
;}
RECOMP_FUNC void _chfiregen_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869B0: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869B0);
    return;
    // 0x800869B4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8001980C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001980C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019814: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019818: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001981C: beq         $a3, $zero, L_80019834
    if (ctx->r7 == 0) {
        // 0x80019820: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80019834;
    }
    // 0x80019820: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80019824: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80019828: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8001982C: jal         0x80019C84
    // 0x80019830: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    mlMtxTranslate(rdram, ctx);
        goto after_0;
    // 0x80019830: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    after_0:
L_80019834:
    // 0x80019834: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019838: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001983C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80019840: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80019844: nop

    // 0x80019848: bc1tl       L_80019864
    if (c1cs) {
        // 0x8001984C: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80019864;
    }
    goto skip_0;
    // 0x8001984C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80019850: div.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80019854: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80019858: jal         0x80019D30
    // 0x8001985C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    mlMtxScale_xyz(rdram, ctx);
        goto after_1;
    // 0x8001985C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_1:
    // 0x80019860: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_80019864:
    // 0x80019864: beql        $t6, $zero, L_8001989C
    if (ctx->r14 == 0) {
        // 0x80019868: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_8001989C;
    }
    goto skip_1;
    // 0x80019868: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x8001986C: lwc1        $f12, 0x8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80019870: jal         0x8001907C
    // 0x80019874: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    mlMtxRotRoll(rdram, ctx);
        goto after_2;
    // 0x80019874: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_2:
    // 0x80019878: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8001987C: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80019880: jal         0x80018F50
    // 0x80019884: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    mlMtxRotPitch(rdram, ctx);
        goto after_3;
    // 0x80019884: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_3:
    // 0x80019888: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8001988C: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80019890: jal         0x80018FE8
    // 0x80019894: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    mlMtxRotYaw(rdram, ctx);
        goto after_4;
    // 0x80019894: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_4:
    // 0x80019898: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_8001989C:
    // 0x8001989C: beql        $t9, $zero, L_800198C8
    if (ctx->r25 == 0) {
        // 0x800198A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800198C8;
    }
    goto skip_2;
    // 0x800198A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800198A4: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800198A8: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800198AC: lwc1        $f14, 0x4($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800198B0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800198B4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800198B8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800198BC: jal         0x80019C84
    // 0x800198C0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    mlMtxTranslate(rdram, ctx);
        goto after_5;
    // 0x800198C0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_5:
    // 0x800198C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800198C8:
    // 0x800198C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800198CC: jr          $ra
    // 0x800198D0: nop

    return;
    // 0x800198D0: nop

;}
RECOMP_FUNC void cosection_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0xAF
    ctx->r2 = ADD32(0, 0XAF);
    return;
    // 0x80800004: addiu       $v0, $zero, 0xAF
    ctx->r2 = ADD32(0, 0XAF);
;}
RECOMP_FUNC void _bsjig_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831D8: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x800831D8);
    return;
    // 0x800831DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void boot___osExceptionPreamble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8080042C_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080042C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800434: jal         0x8009E6EC
    // 0x80800438: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800438: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080043C: jal         0x80801BB4
    // 0x80800440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801BB4_bsbfly(rdram, ctx);
        goto after_1;
    // 0x80800440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080044C: jr          $ra
    // 0x80800450: nop

    return;
    // 0x80800450: nop

;}
RECOMP_FUNC void func_80090734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009073C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090740: jal         0x800F54E4
    // 0x80090744: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090744: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80090748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009074C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80090750: jal         0x800F8300
    // 0x80090754: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F8300(rdram, ctx);
        goto after_1;
    // 0x80090754: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80090758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009075C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090760: jr          $ra
    // 0x80090764: nop

    return;
    // 0x80090764: nop

;}
RECOMP_FUNC void func_800A95C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A95C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A95C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A95CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A95D0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A95D4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A95D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A95DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A95E0: addiu       $s2, $s2, 0x76F0
    ctx->r18 = ADD32(ctx->r18, 0X76F0);
    // 0x800A95E4: addiu       $s0, $s0, 0x76D0
    ctx->r16 = ADD32(ctx->r16, 0X76D0);
    // 0x800A95E8: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A95EC:
    // 0x800A95EC: beq         $v0, $zero, L_800A9620
    if (ctx->r2 == 0) {
        // 0x800A95F0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800A9620;
    }
    // 0x800A95F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800A95F4: jal         0x800CA384
    // 0x800A95F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800CA384(rdram, ctx);
        goto after_0;
    // 0x800A95F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
    // 0x800A95FC: beq         $v0, $s1, L_800A9620
    if (ctx->r2 == ctx->r17) {
        // 0x800A9600: sw          $v0, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->r2;
            goto L_800A9620;
    }
    // 0x800A9600: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800A9604: jal         0x800A8984
    // 0x800A9608: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    func_800A8984(rdram, ctx);
        goto after_1;
    // 0x800A9608: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_1:
    // 0x800A960C: bnel        $v0, $s1, L_800A9624
    if (ctx->r2 != ctx->r17) {
        // 0x800A9610: lw          $a0, 0x58($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X58);
            goto L_800A9624;
    }
    goto skip_0;
    // 0x800A9610: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    skip_0:
    // 0x800A9614: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x800A9618: jal         0x800A88C4
    // 0x800A961C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_800A88C4(rdram, ctx);
        goto after_2;
    // 0x800A961C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
L_800A9620:
    // 0x800A9620: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
L_800A9624:
    // 0x800A9624: beql        $a0, $zero, L_800A963C
    if (ctx->r4 == 0) {
        // 0x800A9628: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A963C;
    }
    goto skip_1;
    // 0x800A9628: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x800A962C: jal         0x80110068
    // 0x800A9630: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80110068(rdram, ctx);
        goto after_3;
    // 0x800A9630: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x800A9634: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x800A9638: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800A963C:
    // 0x800A963C: bnel        $s0, $s2, L_800A95EC
    if (ctx->r16 != ctx->r18) {
        // 0x800A9640: lw          $v0, 0x38($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X38);
            goto L_800A95EC;
    }
    goto skip_2;
    // 0x800A9640: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    skip_2:
    // 0x800A9644: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A9648: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A964C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9650: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A9654: jr          $ra
    // 0x800A9658: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A9658: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _vpwibble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089018: syscall     756
    recomp_syscall_handler(rdram, ctx, 0x80089018);
    return;
    // 0x8008901C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chmole_mine_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1600, 0XE0) << 16);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1600, 0XE0));
    return;
    // 0x808000BC: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1600, 0XE0));
;}
RECOMP_FUNC void func_80800048_chsunlightspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080004C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800054: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080005C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800060: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800064: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80800068: beq         $at, $zero, L_808003F0
    if (ctx->r1 == 0) {
        // 0x8080006C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808003F0;
    }
    // 0x8080006C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800070: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2244, 0X840) << 16);
    // 0x80800074: addu        $at, $at, $t8
    gpr jr_addend_8080007C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800078: lw          $t8, 0x840($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2244, 0X840));
    // 0x8080007C: jr          $t8
    // 0x80800080: nop

    switch (jr_addend_8080007C >> 2) {
        case 0: goto L_808003F0; break;
        case 1: goto L_80800084; break;
        case 2: goto L_808000A4; break;
        case 3: goto L_808000E4; break;
        case 4: goto L_8080013C; break;
        case 5: goto L_808001B4; break;
        case 6: goto L_8080026C; break;
        case 7: goto L_808002C4; break;
        case 8: goto L_808003F0; break;
        default: switch_error(__func__, 0x8080007C, 0x80800840);
    }
    // 0x80800080: nop

L_80800084:
    // 0x80800084: jal         0x800DA298
    // 0x80800088: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800088: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_0:
    // 0x8080008C: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x80800090: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: jal         0x80800404
    // 0x80800098: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800404_chsunlightspell(rdram, ctx);
        goto after_1;
    // 0x80800098: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8080009C: b           L_808003F4
    // 0x808000A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003F4;
    // 0x808000A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000A4:
    // 0x808000A4: jal         0x80800668
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800668_chsunlightspell(rdram, ctx);
        goto after_2;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x80800704
    // 0x808000B4: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_80800704_chsunlightspell(rdram, ctx);
        goto after_3;
    // 0x808000B4: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_3:
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: jal         0x80100094
    // 0x808000C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808000C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808000C4: jal         0x80089918
    // 0x808000C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_5;
    // 0x808000C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808000CC: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x808000D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x80800404
    // 0x808000D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800404_chsunlightspell(rdram, ctx);
        goto after_6;
    // 0x808000D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x808000DC: b           L_808003F4
    // 0x808000E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003F4;
    // 0x808000E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000E4:
    // 0x808000E4: jal         0x80800668
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800668_chsunlightspell(rdram, ctx);
        goto after_7;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x80800704
    // 0x808000F4: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_80800704_chsunlightspell(rdram, ctx);
        goto after_8;
    // 0x808000F4: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_8:
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: jal         0x80100094
    // 0x80800100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800104: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800108: jal         0x80089868
    // 0x8080010C: lui         $a1, 0x4090
    ctx->r5 = S32(0X4090 << 16);
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_10;
    // 0x8080010C: lui         $a1, 0x4090
    ctx->r5 = S32(0X4090 << 16);
    after_10:
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: jal         0x80100094
    // 0x80800118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80800118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8080011C: jal         0x80089918
    // 0x80800120: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_12;
    // 0x80800120: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x80800124: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x80800128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x80800404
    // 0x80800130: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800404_chsunlightspell(rdram, ctx);
        goto after_13;
    // 0x80800130: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_13:
    // 0x80800134: b           L_808003F4
    // 0x80800138: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003F4;
    // 0x80800138: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080013C:
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x80100094
    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_14;
    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800148: jal         0x80089910
    // 0x8080014C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_26(rdram, ctx);
        goto after_15;
    // 0x8080014C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x80800150: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800154: jal         0x80800668
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800668_chsunlightspell(rdram, ctx);
        goto after_16;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080015C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800160: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800164: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800168: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080016C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800170: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80800174: jal         0x800F12D4
    // 0x80800178: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_17;
    // 0x80800178: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_17:
    // 0x8080017C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800180: jal         0x80800704
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800704_chsunlightspell(rdram, ctx);
        goto after_18;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: jal         0x80100094
    // 0x80800190: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_19;
    // 0x80800190: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800194: jal         0x80089918
    // 0x80800198: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_20;
    // 0x80800198: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x8080019C: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x80800404
    // 0x808001A8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800404_chsunlightspell(rdram, ctx);
        goto after_21;
    // 0x808001A8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_21:
    // 0x808001AC: b           L_808003F4
    // 0x808001B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003F4;
    // 0x808001B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001B4:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: jal         0x80100094
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_22;
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x808001C0: jal         0x80089910
    // 0x808001C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_26(rdram, ctx);
        goto after_23;
    // 0x808001C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x808001C8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808001CC: jal         0x80800668
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800668_chsunlightspell(rdram, ctx);
        goto after_24;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808001D4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808001D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001E0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808001E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001E8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x808001EC: jal         0x800F12D4
    // 0x808001F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F12D4(rdram, ctx);
        goto after_25;
    // 0x808001F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_25:
    // 0x808001F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001F8: jal         0x80800704
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800704_chsunlightspell(rdram, ctx);
        goto after_26;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800200: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800204: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800208: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080020C: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x80800210: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800214: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800218: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080021C: jal         0x800F12D4
    // 0x80800220: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F12D4(rdram, ctx);
        goto after_27;
    // 0x80800220: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_27:
    // 0x80800224: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2244, 0X890) << 16);
    // 0x80800228: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8080022C: addiu       $a3, $a3, 0x890
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2244, 0X890));
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800238: jal         0x80089D50
    // 0x8080023C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_28;
    // 0x8080023C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_28:
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x80100094
    // 0x80800248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_29;
    // 0x80800248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x8080024C: jal         0x80089918
    // 0x80800250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_30;
    // 0x80800250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
    // 0x80800254: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x80800258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: jal         0x80800404
    // 0x80800260: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800404_chsunlightspell(rdram, ctx);
        goto after_31;
    // 0x80800260: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_31:
    // 0x80800264: b           L_808003F4
    // 0x80800268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003F4;
    // 0x80800268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080026C:
    // 0x8080026C: jal         0x80800668
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800668_chsunlightspell(rdram, ctx);
        goto after_32;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: jal         0x80800704
    // 0x8080027C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_80800704_chsunlightspell(rdram, ctx);
        goto after_33;
    // 0x8080027C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_33:
    // 0x80800280: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2244, 0X890) << 16);
    // 0x80800284: addiu       $a3, $a3, 0x890
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2244, 0X890));
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800290: jal         0x80089D50
    // 0x80800294: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_34;
    // 0x80800294: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_34:
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080029C: jal         0x80100094
    // 0x808002A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_35;
    // 0x808002A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x808002A4: jal         0x80089918
    // 0x808002A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_36;
    // 0x808002A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_36:
    // 0x808002AC: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x808002B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: jal         0x80800404
    // 0x808002B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800404_chsunlightspell(rdram, ctx);
        goto after_37;
    // 0x808002B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_37:
    // 0x808002BC: b           L_808003F4
    // 0x808002C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003F4;
    // 0x808002C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002C4:
    // 0x808002C4: jal         0x80800668
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800668_chsunlightspell(rdram, ctx);
        goto after_38;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: jal         0x80800704
    // 0x808002D4: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_80800704_chsunlightspell(rdram, ctx);
        goto after_39;
    // 0x808002D4: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_39:
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: jal         0x80100094
    // 0x808002E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_40;
    // 0x808002E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x808002E4: jal         0x80089910
    // 0x808002E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_26(rdram, ctx);
        goto after_41;
    // 0x808002E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_41:
    // 0x808002EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002F4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808002F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002FC: sub.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800300: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800304: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2244, 0X890) << 16);
    // 0x80800308: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080030C: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80800310: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80800314: addiu       $a3, $a3, 0x890
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2244, 0X890));
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800320: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800324: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800328: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8080032C: nop

    // 0x80800330: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800334: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800338: nop

    // 0x8080033C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80800340: beql        $t0, $zero, L_80800390
    if (ctx->r8 == 0) {
        // 0x80800344: mfc1        $t0, $f18
        ctx->r8 = (int32_t)ctx->f18.u32l;
            goto L_80800390;
    }
    goto skip_0;
    // 0x80800344: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x80800348: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080034C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800350: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800354: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80800358: nop

    // 0x8080035C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80800360: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800364: nop

    // 0x80800368: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8080036C: bne         $t0, $zero, L_80800384
    if (ctx->r8 != 0) {
        // 0x80800370: nop
    
            goto L_80800384;
    }
    // 0x80800370: nop

    // 0x80800374: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80800378: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080037C: b           L_8080039C
    // 0x80800380: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8080039C;
    // 0x80800380: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80800384:
    // 0x80800384: b           L_8080039C
    // 0x80800388: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8080039C;
    // 0x80800388: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8080038C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
L_80800390:
    // 0x80800390: nop

    // 0x80800394: bltz        $t0, L_80800384
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800398: nop
    
            goto L_80800384;
    }
    // 0x80800398: nop

L_8080039C:
    // 0x8080039C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808003A0: jal         0x80089D50
    // 0x808003A4: sb          $t0, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r8;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_42;
    // 0x808003A4: sb          $t0, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r8;
    after_42:
    // 0x808003A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2244, 0X864) << 16);
    // 0x808003AC: lwc1        $f6, 0x864($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2244, 0X864));
    // 0x808003B0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808003BC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808003C0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808003C4: jal         0x80089D38
    // 0x808003C8: nop

    _subaddieaudioloop_entrypoint_1(rdram, ctx);
        goto after_43;
    // 0x808003C8: nop

    after_43:
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: jal         0x80100094
    // 0x808003D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_44;
    // 0x808003D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_44:
    // 0x808003D8: jal         0x80089918
    // 0x808003DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_45;
    // 0x808003DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_45:
    // 0x808003E0: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x808003E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: jal         0x80800404
    // 0x808003EC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800404_chsunlightspell(rdram, ctx);
        goto after_46;
    // 0x808003EC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_46:
L_808003F0:
    // 0x808003F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003F4:
    // 0x808003F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808003FC: jr          $ra
    // 0x80800400: nop

    return;
    // 0x80800400: nop

;}
RECOMP_FUNC void chwumbawigwam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801070: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2272, 0X116C) << 16);
    // 0x80801074: jr          $ra
    // 0x80801078: addiu       $v0, $v0, 0x116C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2272, 0X116C));
    return;
    // 0x80801078: addiu       $v0, $v0, 0x116C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2272, 0X116C));
    // 0x8080107C: nop

;}
RECOMP_FUNC void func_808004D8_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004E4: jal         0x80106790
    // 0x808004E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808004E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808004EC: lbu         $v1, 0x79($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X79);
    // 0x808004F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808004F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808004F8: srl         $t6, $v1, 4
    ctx->r14 = S32(U32(ctx->r3) >> 4);
    // 0x808004FC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800500: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80800504: andi        $t0, $v1, 0xFF0F
    ctx->r8 = ctx->r3 & 0XFF0F;
    // 0x80800508: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x8080050C: andi        $a0, $t1, 0xFF
    ctx->r4 = ctx->r9 & 0XFF;
    // 0x80800510: srl         $t2, $a0, 4
    ctx->r10 = S32(U32(ctx->r4) >> 4);
    // 0x80800514: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80800518: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8080051C: sb          $t1, 0x79($v0)
    MEM_B(0X79, ctx->r2) = ctx->r9;
    // 0x80800520: bgez        $t2, L_80800534
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800524: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800534;
    }
    // 0x80800524: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800528: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080052C: nop

    // 0x80800530: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800534:
    // 0x80800534: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800538: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080053C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X18E8) << 16);
    // 0x80800540: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800544: swc1        $f16, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f16.u32l;
    // 0x80800548: lwc1        $f18, 0x18E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X18E8));
    // 0x8080054C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800550: bne         $a0, $at, L_808005BC
    if (ctx->r4 != ctx->r1) {
        // 0x80800554: swc1        $f18, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->f18.u32l;
            goto L_808005BC;
    }
    // 0x80800554: swc1        $f18, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f18.u32l;
    // 0x80800558: jal         0x800DA298
    // 0x8080055C: addiu       $a0, $zero, 0x9EE
    ctx->r4 = ADD32(0, 0X9EE);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080055C: addiu       $a0, $zero, 0x9EE
    ctx->r4 = ADD32(0, 0X9EE);
    after_1:
    // 0x80800560: bne         $v0, $zero, L_808005B4
    if (ctx->r2 != 0) {
        // 0x80800564: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005B4;
    }
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: jal         0x80100094
    // 0x80800570: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800570: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800574: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800584: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    // 0x80800588: jal         0x8008A2D0
    // 0x8080058C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x8080058C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_3:
    // 0x80800590: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800594: addiu       $t4, $zero, 0x62
    ctx->r12 = ADD32(0, 0X62);
    // 0x80800598: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080059C: addiu       $a1, $zero, 0xFF3
    ctx->r5 = ADD32(0, 0XFF3);
    // 0x808005A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005A4: jal         0x8008A208
    // 0x808005A8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808005A8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808005AC: b           L_808005C0
    // 0x808005B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005C0;
    // 0x808005B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005B4:
    // 0x808005B4: jal         0x8080000C
    // 0x808005B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080000C_chlagoonufoint(rdram, ctx);
        goto after_5;
    // 0x808005B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_808005BC:
    // 0x808005BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005C0:
    // 0x808005C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005C8: jr          $ra
    // 0x808005CC: nop

    return;
    // 0x808005CC: nop

;}
RECOMP_FUNC void func_80800168_chcauldronentrydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080016C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800174: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800178: beq         $a1, $at, L_80800194
    if (ctx->r5 == ctx->r1) {
        // 0x8080017C: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800194;
    }
    // 0x8080017C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800180: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80800184: beq         $a1, $at, L_808001B8
    if (ctx->r5 == ctx->r1) {
        // 0x80800188: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808001B8;
    }
    // 0x80800188: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080018C: b           L_808001EC
    // 0x80800190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001EC;
    // 0x80800190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800194:
    // 0x80800194: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80800198: jal         0x800FC6B0
    // 0x8080019C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_800FC6B0(rdram, ctx);
        goto after_0;
    // 0x8080019C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001A0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808001A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808001A8: jal         0x80086248
    // 0x808001AC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808001AC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x808001B0: b           L_808001F0
    // 0x808001B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001F0;
    // 0x808001B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001B8:
    // 0x808001B8: jal         0x800EC75C
    // 0x808001BC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800EC75C(rdram, ctx);
        goto after_2;
    // 0x808001BC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x808001C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808001C4: jal         0x800862B8
    // 0x808001C8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _chelectricfence_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808001C8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x808001CC: jal         0x8010A570
    // 0x808001D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x808001D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x808001D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2004, 0X514) << 16);
    // 0x808001D8: lwc1        $f4, 0x514($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2004, 0X514));
    // 0x808001DC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808001E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001E4: b           L_808001EC
    // 0x808001E8: swc1        $f4, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f4.u32l;
        goto L_808001EC;
    // 0x808001E8: swc1        $f4, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f4.u32l;
L_808001EC:
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001F0:
    // 0x808001F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
RECOMP_FUNC void bamum_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D4: jal         0x80800008
    // 0x808001D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800008_bamum(rdram, ctx);
        goto after_0;
    // 0x808001D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001E0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001E4: jal         0x8009ADF0
    // 0x808001E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009ADF0(rdram, ctx);
        goto after_1;
    // 0x808001E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DD0: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DD0);
    return;
    // 0x80082DD4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80090C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090C28: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80090C2C: jr          $ra
    // 0x80090C30: sb          $a1, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r5;
    return;
    // 0x80090C30: sb          $a1, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_8009D3A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D3A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009D3AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D3B0: jal         0x8009D2F0
    // 0x8009D3B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_0;
    // 0x8009D3B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x8009D3B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D3BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009D3C0: jr          $ra
    // 0x8009D3C4: nop

    return;
    // 0x8009D3C4: nop

    // 0x8009D3C8: nop

    // 0x8009D3CC: nop

;}
RECOMP_FUNC void func_80103EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103EF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103EFC: jal         0x80103328
    // 0x80103F00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103328(rdram, ctx);
        goto after_0;
    // 0x80103F00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80103F04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80103F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103F0C: lh          $t6, 0x8A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8A);
    // 0x80103F10: lh          $t7, 0x88($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X88);
    // 0x80103F14: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80103F18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103F1C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80103F20: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80103F24: nop

    // 0x80103F28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80103F2C: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80103F30: jr          $ra
    // 0x80103F34: nop

    return;
    // 0x80103F34: nop

;}
RECOMP_FUNC void _bashoessuck_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085088: syscall     149
    recomp_syscall_handler(rdram, ctx, 0x80085088);
    return;
    // 0x8008508C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void badeathmatch_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080045C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800460: lw          $a2, 0x158($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X158);
    // 0x80800464: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x80800468: lbu         $t6, 0x21($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X21);
    // 0x8080046C: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x80800470: beql        $t6, $zero, L_808004A4
    if (ctx->r14 == 0) {
        // 0x80800474: lh          $v1, 0x0($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X0);
            goto L_808004A4;
    }
    goto skip_0;
    // 0x80800474: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    skip_0:
    // 0x80800478: jal         0x80085300
    // 0x8080047C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _batimer_get(rdram, ctx);
        goto after_0;
    // 0x8080047C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_0:
    // 0x80800480: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800484: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800488: nop

    // 0x8080048C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800490: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800494: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80800498: b           L_808004C4
    // 0x8080049C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004C4;
    // 0x8080049C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004A0: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
L_808004A4:
    // 0x808004A4: lh          $a0, 0x10($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X10);
    // 0x808004A8: bgezl       $v1, L_808004BC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x808004AC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_808004BC;
    }
    goto skip_1;
    // 0x808004AC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    skip_1:
    // 0x808004B0: b           L_808004BC
    // 0x808004B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_808004BC;
    // 0x808004B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808004B8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_808004BC:
    // 0x808004BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808004C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004C4:
    // 0x808004C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004C8: jr          $ra
    // 0x808004CC: nop

    return;
    // 0x808004CC: nop

;}
RECOMP_FUNC void func_80800030_chpotogoldbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800034: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800038: bne         $a1, $at, L_80800058
    if (ctx->r5 != ctx->r1) {
        // 0x8080003C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800058;
    }
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    // 0x80800044: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800048: jal         0x80101180
    // 0x8080004C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x8080004C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800050: b           L_80800060
    // 0x80800054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800060;
    // 0x80800054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800058:
    // 0x80800058: jal         0x80085820
    // 0x8080005C: nop

    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x8080005C: nop

    after_1:
L_80800060:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void chcrystalbaddie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1384, 0X664) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x664
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1384, 0X664));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x664
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1384, 0X664));
;}
RECOMP_FUNC void sucoaster_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808017E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808017E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808017EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808017F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808017F4: jal         0x80100094
    // 0x808017F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808017F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808017FC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801804: jal         0x80802594
    // 0x80801808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80802594_sucoaster(rdram, ctx);
        goto after_1;
    // 0x80801808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8080180C: beq         $v0, $zero, L_80801840
    if (ctx->r2 == 0) {
        // 0x80801810: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801840;
    }
    // 0x80801810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801814: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801818: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080181C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80801820: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801824: jal         0x800DC178
    // 0x80801828: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80801828: nop

    after_2:
    // 0x8080182C: jal         0x800D9058
    // 0x80801830: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800D9058(rdram, ctx);
        goto after_3;
    // 0x80801830: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    tooie_enemy_attack_timer(rdram, ctx);
    // 0x80801834: sb          $v0, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r2;
    // 0x80801838: b           L_808018A0
    // 0x8080183C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808018A0;
    // 0x8080183C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801840:
    // 0x80801840: jal         0x8080202C
    // 0x80801844: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080202C_sucoaster(rdram, ctx);
        goto after_4;
    // 0x80801844: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80801848: beq         $v0, $zero, L_80801878
    if (ctx->r2 == 0) {
        // 0x8080184C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801878;
    }
    // 0x8080184C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801850: jal         0x808015F8
    // 0x80801854: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808015F8_sucoaster(rdram, ctx);
        goto after_5;
    // 0x80801854: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80801858: beql        $v0, $zero, L_8080187C
    if (ctx->r2 == 0) {
        // 0x8080185C: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8080187C;
    }
    goto skip_0;
    // 0x8080185C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_0:
    // 0x80801860: jal         0x80089F00
    // 0x80801864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suchase_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80801864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801868: beql        $v0, $zero, L_8080187C
    if (ctx->r2 == 0) {
        // 0x8080186C: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8080187C;
    }
    goto skip_1;
    // 0x8080186C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_1:
    // 0x80801870: b           L_808018A0
    // 0x80801874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808018A0;
    // 0x80801874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801878:
    // 0x80801878: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_8080187C:
    // 0x8080187C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801880: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80801884: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801888: jal         0x800DC178
    // 0x8080188C: nop

    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x8080188C: nop

    after_7:
    // 0x80801890: jal         0x800D9058
    // 0x80801894: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800D9058(rdram, ctx);
        goto after_8;
    // 0x80801894: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_8:
    tooie_enemy_attack_timer(rdram, ctx);
    // 0x80801898: sb          $v0, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r2;
    // 0x8080189C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018A0:
    // 0x808018A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808018A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808018A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808018AC: jr          $ra
    // 0x808018B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808018B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800F1DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1DF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F1DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1DFC: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1E00: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800F1E04: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F1E08: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F1E0C: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F1E10: jal         0x80013B7C
    // 0x800F1E14: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80013B7C(rdram, ctx);
        goto after_0;
    // 0x800F1E14: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x800F1E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F1E20: jr          $ra
    // 0x800F1E24: nop

    return;
    // 0x800F1E24: nop

;}
RECOMP_FUNC void func_80800158_chbadbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080015C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800160: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800168: jal         0x801022E4
    // 0x8080016C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x8080016C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x80800170: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x80800174: beq         $v0, $at, L_808001E0
    if (ctx->r2 == ctx->r1) {
        // 0x80800178: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E0;
    }
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: addiu       $at, $zero, 0x1C7
    ctx->r1 = ADD32(0, 0X1C7);
    // 0x80800180: bne         $v0, $at, L_808001F8
    if (ctx->r2 != ctx->r1) {
        // 0x80800184: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F8;
    }
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: lui         $a1, 0x3EF5
    ctx->r5 = S32(0X3EF5 << 16);
    // 0x8080018C: jal         0x80101E14
    // 0x80800190: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x80800190: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    after_1:
    // 0x80800194: bne         $v0, $zero, L_808001AC
    if (ctx->r2 != 0) {
        // 0x80800198: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001AC;
    }
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: lui         $a1, 0x3F7A
    ctx->r5 = S32(0X3F7A << 16);
    // 0x808001A0: jal         0x80101E14
    // 0x808001A4: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x808001A4: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    after_2:
    // 0x808001A8: beq         $v0, $zero, L_808001C0
    if (ctx->r2 == 0) {
        // 0x808001AC: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1760, 0XAEC) << 16);
            goto L_808001C0;
    }
L_808001AC:
    // 0x808001AC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1760, 0XAEC) << 16);
    // 0x808001B0: addiu       $a2, $a2, 0xAEC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1760, 0XAEC));
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: jal         0x80089D18
    // 0x808001BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808001BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
L_808001C0:
    // 0x808001C0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1760, 0XB74) << 16);
    // 0x808001C4: addiu       $a1, $a1, 0xB74
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1760, 0XB74));
    // 0x808001C8: jal         0x80101E4C
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_4;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001D0: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001D4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808001F8;
    }
    // 0x808001D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808001D8: b           L_808001F8
    // 0x808001DC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
        goto L_808001F8;
    // 0x808001DC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_808001E0:
    // 0x808001E0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1760, 0XB64) << 16);
    // 0x808001E4: jal         0x80101E4C
    // 0x808001E8: addiu       $a1, $a1, 0xB64
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1760, 0XB64));
    func_80101E4C(rdram, ctx);
        goto after_5;
    // 0x808001E8: addiu       $a1, $a1, 0xB64
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1760, 0XB64));
    after_5:
    // 0x808001EC: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001F0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_808001F8;
    }
    // 0x808001F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808001F4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_808001F8:
    // 0x808001F8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x808001FC: addiu       $t9, $s0, 0x4
    ctx->r25 = ADD32(ctx->r16, 0X4);
    // 0x80800200: beql        $t8, $zero, L_80800288
    if (ctx->r24 == 0) {
        // 0x80800204: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800288;
    }
    goto skip_0;
    // 0x80800204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800208: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x8080020C: jal         0x800C3CE8
    // 0x80800210: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    func_800C3CE8(rdram, ctx);
        goto after_6;
    // 0x80800210: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_6:
    // 0x80800214: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800218: jal         0x800C301C
    // 0x8080021C: addiu       $a1, $zero, 0x447
    ctx->r5 = ADD32(0, 0X447);
    func_800C301C(rdram, ctx);
        goto after_7;
    // 0x8080021C: addiu       $a1, $zero, 0x447
    ctx->r5 = ADD32(0, 0X447);
    after_7:
    // 0x80800220: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800224: jal         0x800C3058
    // 0x80800228: addiu       $a1, $zero, 0x2EE0
    ctx->r5 = ADD32(0, 0X2EE0);
    func_800C3058(rdram, ctx);
        goto after_8;
    // 0x80800228: addiu       $a1, $zero, 0x2EE0
    ctx->r5 = ADD32(0, 0X2EE0);
    after_8:
    // 0x8080022C: jal         0x80101F24
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_9;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800234: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800238: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080023C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800240: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800244: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800248: jal         0x800C31DC
    // 0x8080024C: nop

    func_800C31DC(rdram, ctx);
        goto after_10;
    // 0x8080024C: nop

    after_10:
    // 0x80800250: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800254: jal         0x800C35E8
    // 0x80800258: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C35E8(rdram, ctx);
        goto after_11;
    // 0x80800258: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x8080025C: lui         $a2, 0x44BB
    ctx->r6 = S32(0X44BB << 16);
    // 0x80800260: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80800264: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800268: jal         0x800C3584
    // 0x8080026C: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_800C3584(rdram, ctx);
        goto after_12;
    // 0x8080026C: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_12:
    // 0x80800270: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800274: jal         0x800C330C
    // 0x80800278: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_13;
    // 0x80800278: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x8080027C: jal         0x800C3BDC
    // 0x80800280: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C3BDC(rdram, ctx);
        goto after_14;
    // 0x80800280: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_14:
    // 0x80800284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800288:
    // 0x80800288: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080028C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800290: jr          $ra
    // 0x80800294: nop

    return;
    // 0x80800294: nop

;}
RECOMP_FUNC void func_800A516C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A516C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A5174: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A5178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A517C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A5180: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800A5184: jal         0x800F18FC
    // 0x800A5188: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_800F18FC(rdram, ctx);
        goto after_0;
    // 0x800A5188: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800A518C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A5190: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800A5194: jal         0x800136E4
    // 0x800A5198: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x800A5198: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x800A519C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800A51A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A51A4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800A51A8: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800A51AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A51B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A51B4: jr          $ra
    // 0x800A51B8: nop

    return;
    // 0x800A51B8: nop

    // 0x800A51BC: nop

;}
RECOMP_FUNC void func_80093360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093360: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80093364: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093368: jr          $ra
    // 0x8009336C: swc1        $f12, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009336C: swc1        $f12, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800E58_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800E5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800E60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800E64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E68: jal         0x80101FDC
    // 0x80800E6C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800E6C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800E70: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800E74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800E78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(768, 0X1690) << 16);
    // 0x80800E7C: blez        $a1, L_80800EC4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80800E80: swc1        $f0, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
            goto L_80800EC4;
    }
    // 0x80800E80: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80800E84: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800E88: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800E8C: lwc1        $f2, 0x1690($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(768, 0X1690));
    // 0x80800E90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E94: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800E98: nop

    // 0x80800E9C: bc1fl       L_80800EC0
    if (!c1cs) {
        // 0x80800EA0: swc1        $f0, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
            goto L_80800EC0;
    }
    goto skip_0;
    // 0x80800EA0: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    skip_0:
    // 0x80800EA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800EA8: nop

    // 0x80800EAC: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80800EB0: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80800EB4: b           L_80800EC4
    // 0x80800EB8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
        goto L_80800EC4;
    // 0x80800EB8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80800EBC: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_80800EC0:
    // 0x80800EC0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
L_80800EC4:
    // 0x80800EC4: addiu       $t7, $a1, -0x2
    ctx->r15 = ADD32(ctx->r5, -0X2);
    // 0x80800EC8: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80800ECC: beq         $at, $zero, L_8080101C
    if (ctx->r1 == 0) {
        // 0x80800ED0: lwc1        $f2, 0x2C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8080101C;
    }
    // 0x80800ED0: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800ED4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800ED8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(768, 0X15A4) << 16);
    // 0x80800EDC: addu        $at, $at, $t7
    gpr jr_addend_80800EE4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800EE0: lw          $t7, 0x15A4($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(768, 0X15A4));
    // 0x80800EE4: jr          $t7
    // 0x80800EE8: nop

    switch (jr_addend_80800EE4 >> 2) {
        case 0: goto L_80800EEC; break;
        case 1: goto L_80800F1C; break;
        case 2: goto L_80800F58; break;
        case 3: goto L_80800F74; break;
        case 4: goto L_80800F84; break;
        case 5: goto L_80800FE8; break;
        default: switch_error(__func__, 0x80800EE4, 0x808015A4);
    }
    // 0x80800EE8: nop

L_80800EEC:
    // 0x80800EEC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EF4: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80800EF8: jal         0x80085708
    // 0x80800EFC: addiu       $a3, $zero, 0x6030
    ctx->r7 = ADD32(0, 0X6030);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800EFC: addiu       $a3, $zero, 0x6030
    ctx->r7 = ADD32(0, 0X6030);
    after_1:
    // 0x80800F00: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800F04: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80800F08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800F0C: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x80800F10: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x80800F14: b           L_8080101C
    // 0x80800F18: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
        goto L_8080101C;
    // 0x80800F18: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
L_80800F1C:
    // 0x80800F1C: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800F20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800F24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800F28: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x80800F2C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800F30: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(768, 0X16B0) << 16);
    // 0x80800F34: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800F38: addiu       $a1, $a1, 0x16B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(768, 0X16B0));
    // 0x80800F3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800F40: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800F44: jal         0x800189A8
    // 0x80800F48: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800189A8(rdram, ctx);
        goto after_2;
    // 0x80800F48: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80800F4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800F50: b           L_8080101C
    // 0x80800F54: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_8080101C;
    // 0x80800F54: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80800F58:
    // 0x80800F58: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800F5C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800F60: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x80800F64: jal         0x800FC660
    // 0x80800F68: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    func_800FC660(rdram, ctx);
        goto after_3;
    // 0x80800F68: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    after_3:
    // 0x80800F6C: b           L_80801020
    // 0x80800F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801020;
    // 0x80800F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F74:
    // 0x80800F74: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800F78: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80800F7C: b           L_8080101C
    // 0x80800F80: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_8080101C;
    // 0x80800F80: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_80800F84:
    // 0x80800F84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800F88: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80800F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F90: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80800F94: jal         0x80085708
    // 0x80800F98: addiu       $a3, $zero, 0x2030
    ctx->r7 = ADD32(0, 0X2030);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800F98: addiu       $a3, $zero, 0x2030
    ctx->r7 = ADD32(0, 0X2030);
    after_4:
    // 0x80800F9C: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800FA0: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800FA4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800FA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800FAC: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80800FB0: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800FB4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(768, 0X16E8) << 16);
    // 0x80800FB8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800FBC: addiu       $a1, $a1, 0x16E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(768, 0X16E8));
    // 0x80800FC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800FC4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800FC8: jal         0x800189A8
    // 0x80800FCC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800189A8(rdram, ctx);
        goto after_5;
    // 0x80800FCC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80800FD0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800FD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800FD8: jal         0x800FCAE0
    // 0x80800FDC: addiu       $a2, $zero, 0x1BC
    ctx->r6 = ADD32(0, 0X1BC);
    func_800FCAE0(rdram, ctx);
        goto after_6;
    // 0x80800FDC: addiu       $a2, $zero, 0x1BC
    ctx->r6 = ADD32(0, 0X1BC);
    after_6:
    // 0x80800FE0: b           L_80801020
    // 0x80800FE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801020;
    // 0x80800FE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800FE8:
    // 0x80800FE8: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800FEC: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    // 0x80800FF0: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x80800FF4: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x80800FF8: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x80800FFC: jal         0x80101180
    // 0x80801000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80801000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80801004: jal         0x800FFAB0
    // 0x80801008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80801008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080100C: jal         0x80089D40
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801014: jal         0x800FC74C
    // 0x80801018: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FC74C(rdram, ctx);
        goto after_10;
    // 0x80801018: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_10:
L_8080101C:
    // 0x8080101C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801020:
    // 0x80801020: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801024: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801028: jr          $ra
    // 0x8080102C: nop

    return;
    // 0x8080102C: nop

;}
RECOMP_FUNC void func_80800750_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080075C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800760: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800764: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800768: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x8080076C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800770: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80800774: beq         $v0, $zero, L_808007A0
    if (ctx->r2 == 0) {
        // 0x80800778: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_808007A0;
    }
    // 0x80800778: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080077C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800780: beq         $v0, $at, L_808007A8
    if (ctx->r2 == ctx->r1) {
        // 0x80800784: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808007A8;
    }
    // 0x80800784: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800788: beq         $v0, $at, L_808007A8
    if (ctx->r2 == ctx->r1) {
        // 0x8080078C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808007A8;
    }
    // 0x8080078C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800790: beql        $v0, $at, L_808007B8
    if (ctx->r2 == ctx->r1) {
        // 0x80800794: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_808007B8;
    }
    goto skip_0;
    // 0x80800794: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800798: b           L_808007C8
    // 0x8080079C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007C8;
    // 0x8080079C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007A0:
    // 0x808007A0: jal         0x800856B0
    // 0x808007A4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808007A4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
L_808007A8:
    // 0x808007A8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x808007AC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x808007B0: sw          $t8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r24;
    // 0x808007B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_808007B8:
    // 0x808007B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808007BC: jal         0x80085740
    // 0x808007C0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    _capod_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808007C0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808007C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007C8:
    // 0x808007C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007CC: jr          $ra
    // 0x808007D0: nop

    return;
    // 0x808007D0: nop

;}
RECOMP_FUNC void func_80800B64_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B64: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80800B68: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800B6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B70: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80800B74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B78: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800B7C: addiu       $t6, $t6, -0x384
    ctx->r14 = ADD32(ctx->r14, -0X384);
    // 0x80800B80: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800B84: addiu       $a0, $zero, 0x476
    ctx->r4 = ADD32(0, 0X476);
    // 0x80800B88: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800B8C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80800B90: jal         0x80089C48
    // 0x80800B94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddiefind_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800B94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800B98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B9C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    // 0x80800BA0: jr          $ra
    // 0x80800BA4: nop

    return;
    // 0x80800BA4: nop

;}
RECOMP_FUNC void func_800AB0BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB0BC: addiu       $sp, $sp, -0x1A0
    ctx->r29 = ADD32(ctx->r29, -0X1A0);
    // 0x800AB0C0: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800AB0C4: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x800AB0C8: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x800AB0CC: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800AB0D0: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800AB0D4: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800AB0D8: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800AB0DC: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800AB0E0: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800AB0E4: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800AB0E8: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x800AB0EC: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800AB0F0: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800AB0F4: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800AB0F8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800AB0FC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800AB100: sw          $a0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r4;
    // 0x800AB104: sw          $a1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r5;
    // 0x800AB108: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
    // 0x800AB10C: lhu         $t7, 0x14($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X14);
    // 0x800AB110: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800AB114: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x800AB118: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800AB11C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AB120: bgez        $t7, L_800AB138
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800AB124: cvt.s.w     $f20, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800AB138;
    }
    // 0x800AB124: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AB128: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AB12C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AB130: nop

    // 0x800AB134: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_800AB138:
    // 0x800AB138: addiu       $t8, $sp, 0x168
    ctx->r24 = ADD32(ctx->r29, 0X168);
    // 0x800AB13C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800AB140: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800AB144: addiu       $a2, $sp, 0x180
    ctx->r6 = ADD32(ctx->r29, 0X180);
    // 0x800AB148: jal         0x800AAFEC
    // 0x800AB14C: addiu       $a3, $sp, 0x174
    ctx->r7 = ADD32(ctx->r29, 0X174);
    func_800AAFEC(rdram, ctx);
        goto after_0;
    // 0x800AB14C: addiu       $a3, $sp, 0x174
    ctx->r7 = ADD32(ctx->r29, 0X174);
    after_0:
    // 0x800AB150: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
    // 0x800AB154: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AB158: addiu       $a0, $sp, 0x174
    ctx->r4 = ADD32(ctx->r29, 0X174);
    // 0x800AB15C: addiu       $s0, $sp, 0x180
    ctx->r16 = ADD32(ctx->r29, 0X180);
    // 0x800AB160: addiu       $a1, $sp, 0x18C
    ctx->r5 = ADD32(ctx->r29, 0X18C);
L_800AB164:
    // 0x800AB164: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800AB168: addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // 0x800AB16C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AB170: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AB174: nop

    // 0x800AB178: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AB17C: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x800AB180: nop

    // 0x800AB184: bc1t        L_800AB1B0
    if (c1cs) {
        // 0x800AB188: nop
    
            goto L_800AB1B0;
    }
    // 0x800AB188: nop

    // 0x800AB18C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800AB190: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AB194: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800AB198: nop

    // 0x800AB19C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AB1A0: c.le.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl <= ctx->f6.fl;
    // 0x800AB1A4: nop

    // 0x800AB1A8: bc1f        L_800AB1B8
    if (!c1cs) {
        // 0x800AB1AC: nop
    
            goto L_800AB1B8;
    }
    // 0x800AB1AC: nop

L_800AB1B0:
    // 0x800AB1B0: b           L_800AB820
    // 0x800AB1B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AB820;
    // 0x800AB1B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AB1B8:
    // 0x800AB1B8: bne         $v0, $a1, L_800AB164
    if (ctx->r2 != ctx->r5) {
        // 0x800AB1BC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800AB164;
    }
    // 0x800AB1BC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AB1C0: addiu       $t2, $sp, 0x190
    ctx->r10 = ADD32(ctx->r29, 0X190);
    // 0x800AB1C4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800AB1C8: lw          $a0, 0x1A0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A0);
    // 0x800AB1CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AB1D0: addiu       $a2, $sp, 0x174
    ctx->r6 = ADD32(ctx->r29, 0X174);
    // 0x800AB1D4: jal         0x800AA7FC
    // 0x800AB1D8: addiu       $a3, $sp, 0x198
    ctx->r7 = ADD32(ctx->r29, 0X198);
    func_800AA7FC(rdram, ctx);
        goto after_1;
    // 0x800AB1D8: addiu       $a3, $sp, 0x198
    ctx->r7 = ADD32(ctx->r29, 0X198);
    after_1:
    // 0x800AB1DC: lw          $v0, 0x198($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X198);
    // 0x800AB1E0: lw          $t3, 0x190($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X190);
    // 0x800AB1E4: addiu       $s7, $sp, 0x114
    ctx->r23 = ADD32(ctx->r29, 0X114);
    // 0x800AB1E8: addiu       $s6, $sp, 0x13C
    ctx->r22 = ADD32(ctx->r29, 0X13C);
    // 0x800AB1EC: sltu        $at, $v0, $t3
    ctx->r1 = ctx->r2 < ctx->r11 ? 1 : 0;
    // 0x800AB1F0: beq         $at, $zero, L_800AB7FC
    if (ctx->r1 == 0) {
        // 0x800AB1F4: sw          $v0, 0x194($sp)
        MEM_W(0X194, ctx->r29) = ctx->r2;
            goto L_800AB7FC;
    }
    // 0x800AB1F4: sw          $v0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r2;
    // 0x800AB1F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB1FC: lwc1        $f30, 0x5614($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X5614);
    // 0x800AB200: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AB204: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800AB208: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB20C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800AB210: lwc1        $f24, 0x5618($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5618);
    // 0x800AB214: addiu       $s5, $sp, 0x148
    ctx->r21 = ADD32(ctx->r29, 0X148);
    // 0x800AB218: addiu       $s3, $sp, 0xA8
    ctx->r19 = ADD32(ctx->r29, 0XA8);
    // 0x800AB21C: addiu       $s2, $sp, 0xD4
    ctx->r18 = ADD32(ctx->r29, 0XD4);
L_800AB220:
    // 0x800AB220: lw          $t4, 0x194($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X194);
    // 0x800AB224: lw          $t7, 0x1A0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A0);
    // 0x800AB228: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800AB22C: lhu         $t9, 0x10($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X10);
    // 0x800AB230: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x800AB234: lhu         $t2, 0x2($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X2);
    // 0x800AB238: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800AB23C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800AB240: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800AB244: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AB248: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AB24C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800AB250: addu        $v0, $t8, $t1
    ctx->r2 = ADD32(ctx->r24, ctx->r9);
    // 0x800AB254: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800AB258: addiu       $s1, $v0, 0x18
    ctx->r17 = ADD32(ctx->r2, 0X18);
    // 0x800AB25C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800AB260: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800AB264: sltu        $at, $s1, $t4
    ctx->r1 = ctx->r17 < ctx->r12 ? 1 : 0;
    // 0x800AB268: beq         $at, $zero, L_800AB7E4
    if (ctx->r1 == 0) {
        // 0x800AB26C: sw          $t4, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r12;
            goto L_800AB7E4;
    }
    // 0x800AB26C: sw          $t4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r12;
    // 0x800AB270: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
L_800AB274:
    // 0x800AB274: lw          $t6, 0x1B4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1B4);
    // 0x800AB278: lw          $v0, 0x1A4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1A4);
    // 0x800AB27C: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x800AB280: bne         $t7, $zero, L_800AB7D0
    if (ctx->r15 != 0) {
        // 0x800AB284: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_800AB7D0;
    }
    // 0x800AB284: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800AB288: lhu         $t9, 0x0($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X0);
    // 0x800AB28C: lhu         $t1, 0x2($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X2);
    // 0x800AB290: lhu         $t3, 0x4($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X4);
    // 0x800AB294: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x800AB298: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    // 0x800AB29C: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x800AB2A0: lw          $t5, 0x180($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X180);
    // 0x800AB2A4: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800AB2A8: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800AB2AC: addu        $a1, $t2, $v0
    ctx->r5 = ADD32(ctx->r10, ctx->r2);
    // 0x800AB2B0: addu        $a2, $t4, $v0
    ctx->r6 = ADD32(ctx->r12, ctx->r2);
    // 0x800AB2B4: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AB2B8: lh          $a3, 0x0($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X0);
    // 0x800AB2BC: beq         $at, $zero, L_800AB2D8
    if (ctx->r1 == 0) {
        // 0x800AB2C0: lh          $t0, 0x0($a2)
        ctx->r8 = MEM_H(ctx->r6, 0X0);
            goto L_800AB2D8;
    }
    // 0x800AB2C0: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x800AB2C4: slt         $at, $a3, $t5
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AB2C8: beq         $at, $zero, L_800AB2D8
    if (ctx->r1 == 0) {
        // 0x800AB2CC: slt         $at, $t0, $t5
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
            goto L_800AB2D8;
    }
    // 0x800AB2CC: slt         $at, $t0, $t5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AB2D0: bnel        $at, $zero, L_800AB7D4
    if (ctx->r1 != 0) {
        // 0x800AB2D4: lw          $t1, 0x154($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X154);
            goto L_800AB7D4;
    }
    goto skip_0;
    // 0x800AB2D4: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    skip_0:
L_800AB2D8:
    // 0x800AB2D8: lw          $t6, 0x174($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X174);
    // 0x800AB2DC: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AB2E0: beq         $at, $zero, L_800AB2F8
    if (ctx->r1 == 0) {
        // 0x800AB2E4: slt         $at, $t6, $a3
        ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800AB2F8;
    }
    // 0x800AB2E4: slt         $at, $t6, $a3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800AB2E8: beq         $at, $zero, L_800AB2F8
    if (ctx->r1 == 0) {
        // 0x800AB2EC: slt         $at, $t6, $t0
        ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800AB2F8;
    }
    // 0x800AB2EC: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800AB2F0: bnel        $at, $zero, L_800AB7D4
    if (ctx->r1 != 0) {
        // 0x800AB2F4: lw          $t1, 0x154($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X154);
            goto L_800AB7D4;
    }
    goto skip_1;
    // 0x800AB2F4: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    skip_1:
L_800AB2F8:
    // 0x800AB2F8: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800AB2FC: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800AB300: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800AB304: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AB308: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800AB30C: lw          $t9, 0x178($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X178);
    // 0x800AB310: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AB314: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x800AB318: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AB31C: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x800AB320: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x800AB324: lh          $v1, 0x2($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X2);
    // 0x800AB328: lh          $a3, 0x2($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X2);
    // 0x800AB32C: lh          $t0, 0x2($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X2);
    // 0x800AB330: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AB334: beq         $at, $zero, L_800AB348
    if (ctx->r1 == 0) {
        // 0x800AB338: slt         $at, $a3, $t7
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
            goto L_800AB348;
    }
    // 0x800AB338: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AB33C: beq         $at, $zero, L_800AB348
    if (ctx->r1 == 0) {
        // 0x800AB340: slt         $at, $t0, $t7
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r15) ? 1 : 0;
            goto L_800AB348;
    }
    // 0x800AB340: slt         $at, $t0, $t7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AB344: bne         $at, $zero, L_800AB7D0
    if (ctx->r1 != 0) {
        // 0x800AB348: slt         $at, $t9, $v1
        ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800AB7D0;
    }
L_800AB348:
    // 0x800AB348: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AB34C: beq         $at, $zero, L_800AB364
    if (ctx->r1 == 0) {
        // 0x800AB350: slt         $at, $t9, $a3
        ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800AB364;
    }
    // 0x800AB350: slt         $at, $t9, $a3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800AB354: beq         $at, $zero, L_800AB364
    if (ctx->r1 == 0) {
        // 0x800AB358: slt         $at, $t9, $t0
        ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800AB364;
    }
    // 0x800AB358: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800AB35C: bnel        $at, $zero, L_800AB7D4
    if (ctx->r1 != 0) {
        // 0x800AB360: lw          $t1, 0x154($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X154);
            goto L_800AB7D4;
    }
    goto skip_2;
    // 0x800AB360: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    skip_2:
L_800AB364:
    // 0x800AB364: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800AB368: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800AB36C: lw          $t8, 0x188($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X188);
    // 0x800AB370: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AB374: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800AB378: lw          $t1, 0x17C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X17C);
    // 0x800AB37C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AB380: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    // 0x800AB384: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AB388: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x800AB38C: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    // 0x800AB390: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x800AB394: lh          $a3, 0x4($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X4);
    // 0x800AB398: lh          $t0, 0x4($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X4);
    // 0x800AB39C: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AB3A0: beq         $at, $zero, L_800AB3B4
    if (ctx->r1 == 0) {
        // 0x800AB3A4: slt         $at, $a3, $t8
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r24) ? 1 : 0;
            goto L_800AB3B4;
    }
    // 0x800AB3A4: slt         $at, $a3, $t8
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AB3A8: beq         $at, $zero, L_800AB3B4
    if (ctx->r1 == 0) {
        // 0x800AB3AC: slt         $at, $t0, $t8
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
            goto L_800AB3B4;
    }
    // 0x800AB3AC: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AB3B0: bne         $at, $zero, L_800AB7D0
    if (ctx->r1 != 0) {
        // 0x800AB3B4: slt         $at, $t1, $v1
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800AB7D0;
    }
L_800AB3B4:
    // 0x800AB3B4: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AB3B8: beq         $at, $zero, L_800AB3D0
    if (ctx->r1 == 0) {
        // 0x800AB3BC: slt         $at, $t1, $a3
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800AB3D0;
    }
    // 0x800AB3BC: slt         $at, $t1, $a3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800AB3C0: beq         $at, $zero, L_800AB3D0
    if (ctx->r1 == 0) {
        // 0x800AB3C4: slt         $at, $t1, $t0
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800AB3D0;
    }
    // 0x800AB3C4: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800AB3C8: bnel        $at, $zero, L_800AB7D4
    if (ctx->r1 != 0) {
        // 0x800AB3CC: lw          $t1, 0x154($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X154);
            goto L_800AB7D4;
    }
    goto skip_3;
    // 0x800AB3CC: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    skip_3:
L_800AB3D0:
    // 0x800AB3D0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800AB3D4: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800AB3D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800AB3DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AB3E0: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800AB3E4: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800AB3E8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800AB3EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AB3F0: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x800AB3F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AB3F8: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x800AB3FC: jal         0x800EFB24
    // 0x800AB400: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x800AB400: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x800AB404: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800AB408: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x800AB40C: jal         0x800EFB24
    // 0x800AB410: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x800AB410: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_3:
    // 0x800AB414: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AB418: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AB41C: jal         0x800EE97C
    // 0x800AB420: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800EE97C(rdram, ctx);
        goto after_4;
    // 0x800AB420: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_4:
    // 0x800AB424: jal         0x800F2100
    // 0x800AB428: lwc1        $f12, 0xD4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD4);
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x800AB428: lwc1        $f12, 0xD4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD4);
    after_5:
    // 0x800AB42C: c.lt.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl < ctx->f0.fl;
    // 0x800AB430: nop

    // 0x800AB434: bc1tl       L_800AB470
    if (c1cs) {
        // 0x800AB438: lwc1        $f4, 0xD4($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
            goto L_800AB470;
    }
    goto skip_4;
    // 0x800AB438: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    skip_4:
    // 0x800AB43C: jal         0x800F2100
    // 0x800AB440: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x800AB440: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    after_6:
    // 0x800AB444: c.lt.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl < ctx->f0.fl;
    // 0x800AB448: nop

    // 0x800AB44C: bc1tl       L_800AB470
    if (c1cs) {
        // 0x800AB450: lwc1        $f4, 0xD4($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
            goto L_800AB470;
    }
    goto skip_5;
    // 0x800AB450: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    skip_5:
    // 0x800AB454: jal         0x800F2100
    // 0x800AB458: lwc1        $f12, 0xDC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XDC);
    mlAbsF(rdram, ctx);
        goto after_7;
    // 0x800AB458: lwc1        $f12, 0xDC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XDC);
    after_7:
    // 0x800AB45C: c.lt.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl < ctx->f0.fl;
    // 0x800AB460: nop

    // 0x800AB464: bc1fl       L_800AB494
    if (!c1cs) {
        // 0x800AB468: addiu       $a0, $sp, 0x130
        ctx->r4 = ADD32(ctx->r29, 0X130);
            goto L_800AB494;
    }
    goto skip_6;
    // 0x800AB468: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    skip_6:
    // 0x800AB46C: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
L_800AB470:
    // 0x800AB470: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800AB474: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800AB478: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800AB47C: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800AB480: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x800AB484: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800AB488: swc1        $f10, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f10.u32l;
    // 0x800AB48C: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x800AB490: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
L_800AB494:
    // 0x800AB494: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800AB498: jal         0x800EFB24
    // 0x800AB49C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x800AB49C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_8:
    // 0x800AB4A0: addiu       $a0, $sp, 0x124
    ctx->r4 = ADD32(ctx->r29, 0X124);
    // 0x800AB4A4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800AB4A8: jal         0x800EFB24
    // 0x800AB4AC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFB24(rdram, ctx);
        goto after_9;
    // 0x800AB4AC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_9:
    // 0x800AB4B0: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    // 0x800AB4B4: jal         0x800EEAA4
    // 0x800AB4B8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_10;
    // 0x800AB4B8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_10:
    // 0x800AB4BC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800AB4C0: addiu       $a0, $sp, 0x124
    ctx->r4 = ADD32(ctx->r29, 0X124);
    // 0x800AB4C4: jal         0x800EEAA4
    // 0x800AB4C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_11;
    // 0x800AB4C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_11:
    // 0x800AB4CC: c.le.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl <= ctx->f20.fl;
    // 0x800AB4D0: nop

    // 0x800AB4D4: bc1fl       L_800AB4F0
    if (!c1cs) {
        // 0x800AB4D8: c.le.s      $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl <= ctx->f26.fl;
            goto L_800AB4F0;
    }
    goto skip_7;
    // 0x800AB4D8: c.le.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl <= ctx->f26.fl;
    skip_7:
    // 0x800AB4DC: c.le.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl <= ctx->f0.fl;
    // 0x800AB4E0: nop

    // 0x800AB4E4: bc1tl       L_800AB7D4
    if (c1cs) {
        // 0x800AB4E8: lw          $t1, 0x154($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X154);
            goto L_800AB7D4;
    }
    goto skip_8;
    // 0x800AB4E8: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    skip_8:
    // 0x800AB4EC: c.le.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl <= ctx->f26.fl;
L_800AB4F0:
    // 0x800AB4F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800AB4F4: bc1fl       L_800AB510
    if (!c1cs) {
        // 0x800AB4F8: lw          $t2, 0x8($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X8);
            goto L_800AB510;
    }
    goto skip_9;
    // 0x800AB4F8: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    skip_9:
    // 0x800AB4FC: c.le.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl <= ctx->f26.fl;
    // 0x800AB500: nop

    // 0x800AB504: bc1tl       L_800AB7D4
    if (c1cs) {
        // 0x800AB508: lw          $t1, 0x154($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X154);
            goto L_800AB7D4;
    }
    goto skip_10;
    // 0x800AB508: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    skip_10:
    // 0x800AB50C: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
L_800AB510:
    // 0x800AB510: sll         $t3, $t2, 15
    ctx->r11 = S32(ctx->r10 << 15);
    // 0x800AB514: bgez        $t3, L_800AB550
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800AB518: nop
    
            goto L_800AB550;
    }
    // 0x800AB518: nop

    // 0x800AB51C: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800AB520: nop

    // 0x800AB524: bc1f        L_800AB550
    if (!c1cs) {
        // 0x800AB528: nop
    
            goto L_800AB550;
    }
    // 0x800AB528: nop

    // 0x800AB52C: lwc1        $f22, 0xD4($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800AB530: lwc1        $f20, 0xD8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800AB534: lwc1        $f18, 0xDC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800AB538: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    // 0x800AB53C: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x800AB540: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
    // 0x800AB544: swc1        $f22, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f22.u32l;
    // 0x800AB548: swc1        $f20, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f20.u32l;
    // 0x800AB54C: swc1        $f18, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f18.u32l;
L_800AB550:
    // 0x800AB550: jal         0x800EEAA4
    // 0x800AB554: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_12;
    // 0x800AB554: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_12:
    // 0x800AB558: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
    // 0x800AB55C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AB560: jal         0x800EEAA4
    // 0x800AB564: addiu       $a1, $sp, 0x168
    ctx->r5 = ADD32(ctx->r29, 0X168);
    func_800EEAA4(rdram, ctx);
        goto after_13;
    // 0x800AB564: addiu       $a1, $sp, 0x168
    ctx->r5 = ADD32(ctx->r29, 0X168);
    after_13:
    // 0x800AB568: c.le.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl <= ctx->f0.fl;
    // 0x800AB56C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800AB570: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AB574: bc1tl       L_800AB7D4
    if (c1cs) {
        // 0x800AB578: lw          $t1, 0x154($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X154);
            goto L_800AB7D4;
    }
    goto skip_11;
    // 0x800AB578: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    skip_11:
    // 0x800AB57C: jal         0x800EEAA4
    // 0x800AB580: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_14;
    // 0x800AB580: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_14:
    // 0x800AB584: add.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x800AB588: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800AB58C: div.s       $f20, $f6, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800AB590: c.le.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl <= ctx->f26.fl;
    // 0x800AB594: nop

    // 0x800AB598: bc1tl       L_800AB7D4
    if (c1cs) {
        // 0x800AB59C: lw          $t1, 0x154($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X154);
            goto L_800AB7D4;
    }
    goto skip_12;
    // 0x800AB59C: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    skip_12:
    // 0x800AB5A0: c.le.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl <= ctx->f20.fl;
    // 0x800AB5A4: lwc1        $f8, 0x168($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB5A8: bc1tl       L_800AB7D4
    if (c1cs) {
        // 0x800AB5AC: lw          $t1, 0x154($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X154);
            goto L_800AB7D4;
    }
    goto skip_13;
    // 0x800AB5AC: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    skip_13:
    // 0x800AB5B0: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AB5B4: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800AB5B8: lwc1        $f8, 0x16C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB5BC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800AB5C0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AB5C4: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AB5C8: lwc1        $f4, 0x4($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800AB5CC: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x800AB5D0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AB5D4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AB5D8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AB5DC: lwc1        $f4, 0x8($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800AB5E0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800AB5E4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AB5E8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800AB5EC: jal         0x800EFA4C
    // 0x800AB5F0: nop

    func_800EFA4C(rdram, ctx);
        goto after_15;
    // 0x800AB5F0: nop

    after_15:
    // 0x800AB5F4: jal         0x800F2100
    // 0x800AB5F8: lwc1        $f12, 0xD4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD4);
    mlAbsF(rdram, ctx);
        goto after_16;
    // 0x800AB5F8: lwc1        $f12, 0xD4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD4);
    after_16:
    // 0x800AB5FC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800AB600: jal         0x800F2100
    // 0x800AB604: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    mlAbsF(rdram, ctx);
        goto after_17;
    // 0x800AB604: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    after_17:
    // 0x800AB608: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AB60C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800AB610: bc1f        L_800AB620
    if (!c1cs) {
        // 0x800AB614: nop
    
            goto L_800AB620;
    }
    // 0x800AB614: nop

    // 0x800AB618: b           L_800AB620
    // 0x800AB61C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800AB620;
    // 0x800AB61C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AB620:
    // 0x800AB620: jal         0x800F2100
    // 0x800AB624: lwc1        $f12, 0xDC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XDC);
    mlAbsF(rdram, ctx);
        goto after_18;
    // 0x800AB624: lwc1        $f12, 0xDC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XDC);
    after_18:
    // 0x800AB628: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800AB62C: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x800AB630: lwc1        $f12, 0x0($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800AB634: jal         0x800F2100
    // 0x800AB638: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_19;
    // 0x800AB638: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_19:
    // 0x800AB63C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AB640: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AB644: bc1fl       L_800AB654
    if (!c1cs) {
        // 0x800AB648: addiu       $v0, $s0, 0x1
        ctx->r2 = ADD32(ctx->r16, 0X1);
            goto L_800AB654;
    }
    goto skip_14;
    // 0x800AB648: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    skip_14:
    // 0x800AB64C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800AB650: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_800AB654:
    // 0x800AB654: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800AB658: mfhi        $t6
    ctx->r14 = hi;
    // 0x800AB65C: sll         $v0, $t6, 2
    ctx->r2 = S32(ctx->r14 << 2);
    // 0x800AB660: addu        $t9, $s7, $v0
    ctx->r25 = ADD32(ctx->r23, ctx->r2);
    // 0x800AB664: addu        $t8, $s3, $v0
    ctx->r24 = ADD32(ctx->r19, ctx->r2);
    // 0x800AB668: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800AB66C: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800AB670: addu        $t1, $s5, $v0
    ctx->r9 = ADD32(ctx->r21, ctx->r2);
    // 0x800AB674: addu        $t2, $s6, $v0
    ctx->r10 = ADD32(ctx->r22, ctx->r2);
    // 0x800AB678: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AB67C: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x800AB680: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x800AB684: addiu       $a0, $sp, 0x108
    ctx->r4 = ADD32(ctx->r29, 0X108);
    // 0x800AB688: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800AB68C: jal         0x800EFA4C
    // 0x800AB690: nop

    func_800EFA4C(rdram, ctx);
        goto after_20;
    // 0x800AB690: nop

    after_20:
    // 0x800AB694: addiu       $v0, $s0, 0x2
    ctx->r2 = ADD32(ctx->r16, 0X2);
    // 0x800AB698: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AB69C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800AB6A0: mfhi        $t3
    ctx->r11 = hi;
    // 0x800AB6A4: sll         $v0, $t3, 2
    ctx->r2 = S32(ctx->r11 << 2);
    // 0x800AB6A8: addu        $t5, $s7, $v0
    ctx->r13 = ADD32(ctx->r23, ctx->r2);
    // 0x800AB6AC: addu        $t6, $s3, $v0
    ctx->r14 = ADD32(ctx->r19, ctx->r2);
    // 0x800AB6B0: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800AB6B4: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800AB6B8: addu        $t7, $s5, $v0
    ctx->r15 = ADD32(ctx->r21, ctx->r2);
    // 0x800AB6BC: addu        $t9, $s6, $v0
    ctx->r25 = ADD32(ctx->r22, ctx->r2);
    // 0x800AB6C0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800AB6C4: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x800AB6C8: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x800AB6CC: addiu       $a0, $sp, 0xFC
    ctx->r4 = ADD32(ctx->r29, 0XFC);
    // 0x800AB6D0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800AB6D4: jal         0x800EFA4C
    // 0x800AB6D8: nop

    func_800EFA4C(rdram, ctx);
        goto after_21;
    // 0x800AB6D8: nop

    after_21:
    // 0x800AB6DC: lwc1        $f12, 0x104($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800AB6E0: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800AB6E4: lwc1        $f16, 0x110($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800AB6E8: lwc1        $f20, 0x100($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800AB6EC: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800AB6F0: lwc1        $f22, 0x108($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800AB6F4: lwc1        $f24, 0xFC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800AB6F8: mul.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800AB6FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB700: mul.s       $f10, $f22, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x800AB704: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AB708: mul.s       $f4, $f16, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x800AB70C: div.s       $f14, $f28, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f28.fl, ctx->f8.fl);
    // 0x800AB710: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800AB714: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800AB718: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    // 0x800AB71C: nop

    // 0x800AB720: bc1t        L_800AB738
    if (c1cs) {
        // 0x800AB724: nop
    
            goto L_800AB738;
    }
    // 0x800AB724: nop

    // 0x800AB728: c.lt.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl < ctx->f2.fl;
    // 0x800AB72C: nop

    // 0x800AB730: bc1f        L_800AB740
    if (!c1cs) {
        // 0x800AB734: nop
    
            goto L_800AB740;
    }
    // 0x800AB734: nop

L_800AB738:
    // 0x800AB738: b           L_800AB7D0
    // 0x800AB73C: lwc1        $f24, 0x561C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X561C);
        goto L_800AB7D0;
    // 0x800AB73C: lwc1        $f24, 0x561C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X561C);
L_800AB740:
    // 0x800AB740: mul.s       $f8, $f18, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800AB744: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB748: mul.s       $f10, $f22, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800AB74C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AB750: mul.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800AB754: c.lt.s      $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl < ctx->f26.fl;
    // 0x800AB758: nop

    // 0x800AB75C: bc1t        L_800AB790
    if (c1cs) {
        // 0x800AB760: nop
    
            goto L_800AB790;
    }
    // 0x800AB760: nop

    // 0x800AB764: c.lt.s      $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f28.fl < ctx->f12.fl;
    // 0x800AB768: nop

    // 0x800AB76C: bc1t        L_800AB790
    if (c1cs) {
        // 0x800AB770: nop
    
            goto L_800AB790;
    }
    // 0x800AB770: nop

    // 0x800AB774: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800AB778: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800AB77C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800AB780: c.lt.s      $f28, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f28.fl < ctx->f6.fl;
    // 0x800AB784: nop

    // 0x800AB788: bc1f        L_800AB798
    if (!c1cs) {
        // 0x800AB78C: nop
    
            goto L_800AB798;
    }
    // 0x800AB78C: nop

L_800AB790:
    // 0x800AB790: b           L_800AB7D0
    // 0x800AB794: lwc1        $f24, 0x5620($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5620);
        goto L_800AB7D0;
    // 0x800AB794: lwc1        $f24, 0x5620($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5620);
L_800AB798:
    // 0x800AB798: jal         0x800EE7F8
    // 0x800AB79C: sw          $s1, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r17;
    func_800EE7F8(rdram, ctx);
        goto after_22;
    // 0x800AB79C: sw          $s1, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r17;
    after_22:
    // 0x800AB7A0: lw          $a0, 0x1B0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1B0);
    // 0x800AB7A4: jal         0x800EE7F8
    // 0x800AB7A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_23;
    // 0x800AB7A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_23:
    // 0x800AB7AC: addiu       $t8, $sp, 0x168
    ctx->r24 = ADD32(ctx->r29, 0X168);
    // 0x800AB7B0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800AB7B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AB7B8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800AB7BC: addiu       $a2, $sp, 0x180
    ctx->r6 = ADD32(ctx->r29, 0X180);
    // 0x800AB7C0: jal         0x800AAFEC
    // 0x800AB7C4: addiu       $a3, $sp, 0x174
    ctx->r7 = ADD32(ctx->r29, 0X174);
    func_800AAFEC(rdram, ctx);
        goto after_24;
    // 0x800AB7C4: addiu       $a3, $sp, 0x174
    ctx->r7 = ADD32(ctx->r29, 0X174);
    after_24:
    // 0x800AB7C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB7CC: lwc1        $f24, 0x5624($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5624);
L_800AB7D0:
    // 0x800AB7D0: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
L_800AB7D4:
    // 0x800AB7D4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800AB7D8: sltu        $at, $s1, $t1
    ctx->r1 = ctx->r17 < ctx->r9 ? 1 : 0;
    // 0x800AB7DC: bnel        $at, $zero, L_800AB274
    if (ctx->r1 != 0) {
        // 0x800AB7E0: lw          $t5, 0x8($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X8);
            goto L_800AB274;
    }
    goto skip_15;
    // 0x800AB7E0: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    skip_15:
L_800AB7E4:
    // 0x800AB7E4: lw          $t2, 0x194($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X194);
    // 0x800AB7E8: lw          $t4, 0x190($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X190);
    // 0x800AB7EC: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800AB7F0: sltu        $at, $t3, $t4
    ctx->r1 = ctx->r11 < ctx->r12 ? 1 : 0;
    // 0x800AB7F4: bne         $at, $zero, L_800AB220
    if (ctx->r1 != 0) {
        // 0x800AB7F8: sw          $t3, 0x194($sp)
        MEM_W(0X194, ctx->r29) = ctx->r11;
            goto L_800AB220;
    }
    // 0x800AB7F8: sw          $t3, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r11;
L_800AB7FC:
    // 0x800AB7FC: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x800AB800: beql        $t5, $zero, L_800AB814
    if (ctx->r13 == 0) {
        // 0x800AB804: lw          $a0, 0x160($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X160);
            goto L_800AB814;
    }
    goto skip_16;
    // 0x800AB804: lw          $a0, 0x160($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X160);
    skip_16:
    // 0x800AB808: jal         0x800EF2A0
    // 0x800AB80C: lw          $a0, 0x1B0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1B0);
    func_800EF2A0(rdram, ctx);
        goto after_25;
    // 0x800AB80C: lw          $a0, 0x1B0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1B0);
    after_25:
    // 0x800AB810: lw          $a0, 0x160($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X160);
L_800AB814:
    // 0x800AB814: jal         0x800AA3B4
    // 0x800AB818: lw          $a1, 0x1A4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1A4);
    func_800AA3B4(rdram, ctx);
        goto after_26;
    // 0x800AB818: lw          $a1, 0x1A4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1A4);
    after_26:
    // 0x800AB81C: lw          $v0, 0x160($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X160);
L_800AB820:
    // 0x800AB820: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x800AB824: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800AB828: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800AB82C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800AB830: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800AB834: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800AB838: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x800AB83C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800AB840: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800AB844: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800AB848: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800AB84C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800AB850: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800AB854: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800AB858: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x800AB85C: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x800AB860: jr          $ra
    // 0x800AB864: addiu       $sp, $sp, 0x1A0
    ctx->r29 = ADD32(ctx->r29, 0X1A0);
    return;
    // 0x800AB864: addiu       $sp, $sp, 0x1A0
    ctx->r29 = ADD32(ctx->r29, 0X1A0);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_49(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D48: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D48);
    return;
    // 0x80082D4C: addi        $t0, $zero, 0xC4
    ctx->r8 = ADD32(0, 0XC4);
;}
RECOMP_FUNC void _chtrashcangame_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087698: syscall     604
    recomp_syscall_handler(rdram, ctx, 0x80087698);
    return;
    // 0x8008769C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801638_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801638: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8080163C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1608, 0X50CC) << 16);
    // 0x80801640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801644: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80801648: addiu       $t6, $t6, 0x50CC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1608, 0X50CC));
    // 0x8080164C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80801650: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801654: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80801658: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x8080165C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80801660: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801664: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80801668: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8080166C: jal         0x80089C50
    // 0x80801670: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    _subaddiefind_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80801670: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801674: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x80801678: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x8080167C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80801680: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    // 0x80801684: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80801688: blez        $v0, L_8080170C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080168C: sw          $zero, 0x0($a3)
        MEM_W(0X0, ctx->r7) = 0;
            goto L_8080170C;
    }
    // 0x8080168C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80801690: addu        $a0, $t3, $v1
    ctx->r4 = ADD32(ctx->r11, ctx->r3);
    // 0x80801694: addiu       $t0, $zero, 0x29E
    ctx->r8 = ADD32(0, 0X29E);
    // 0x80801698: addiu       $a2, $zero, 0x1B8
    ctx->r6 = ADD32(0, 0X1B8);
    // 0x8080169C: addiu       $a1, $zero, 0x155
    ctx->r5 = ADD32(0, 0X155);
    // 0x808016A0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
L_808016A4:
    // 0x808016A4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808016A8: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x808016AC: lw          $v0, 0x6C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X6C);
    // 0x808016B0: sll         $t5, $v0, 11
    ctx->r13 = S32(ctx->r2 << 11);
    // 0x808016B4: srl         $t8, $t5, 20
    ctx->r24 = S32(U32(ctx->r13) >> 20);
    // 0x808016B8: beql        $t8, $a1, L_808016DC
    if (ctx->r24 == ctx->r5) {
        // 0x808016BC: lw          $t7, 0x4($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X4);
            goto L_808016DC;
    }
    goto skip_0;
    // 0x808016BC: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    skip_0:
    // 0x808016C0: beql        $t8, $a2, L_808016FC
    if (ctx->r24 == ctx->r6) {
        // 0x808016C4: lw          $t2, 0xC($a3)
        ctx->r10 = MEM_W(ctx->r7, 0XC);
            goto L_808016FC;
    }
    goto skip_1;
    // 0x808016C4: lw          $t2, 0xC($a3)
    ctx->r10 = MEM_W(ctx->r7, 0XC);
    skip_1:
    // 0x808016C8: beql        $t8, $t0, L_808016EC
    if (ctx->r24 == ctx->r8) {
        // 0x808016CC: lw          $t9, 0x8($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X8);
            goto L_808016EC;
    }
    goto skip_2;
    // 0x808016CC: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    skip_2:
    // 0x808016D0: b           L_80801704
    // 0x808016D4: nop

        goto L_80801704;
    // 0x808016D4: nop

    // 0x808016D8: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
L_808016DC:
    // 0x808016DC: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x808016E0: b           L_80801704
    // 0x808016E4: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
        goto L_80801704;
    // 0x808016E4: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x808016E8: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
L_808016EC:
    // 0x808016EC: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x808016F0: b           L_80801704
    // 0x808016F4: sw          $t3, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r11;
        goto L_80801704;
    // 0x808016F4: sw          $t3, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r11;
    // 0x808016F8: lw          $t2, 0xC($a3)
    ctx->r10 = MEM_W(ctx->r7, 0XC);
L_808016FC:
    // 0x808016FC: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80801700: sw          $t4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r12;
L_80801704:
    // 0x80801704: bnel        $at, $zero, L_808016A4
    if (ctx->r1 != 0) {
        // 0x80801708: lw          $t4, 0x0($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X0);
            goto L_808016A4;
    }
    goto skip_3;
    // 0x80801708: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    skip_3:
L_8080170C:
    // 0x8080170C: lw          $t5, 0xC($a3)
    ctx->r13 = MEM_W(ctx->r7, 0XC);
    // 0x80801710: lw          $t8, 0x4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4);
    // 0x80801714: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x80801718: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x8080171C: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80801720: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80801724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801728: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8080172C: jr          $ra
    // 0x80801730: nop

    return;
    // 0x80801730: nop

;}
RECOMP_FUNC void func_800D8F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8F40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D8F44: jr          $ra
    // 0x800D8F48: addiu       $v0, $v0, -0x3FD0
    ctx->r2 = ADD32(ctx->r2, -0X3FD0);
    return;
    // 0x800D8F48: addiu       $v0, $v0, -0x3FD0
    ctx->r2 = ADD32(ctx->r2, -0X3FD0);
    // 0x800D8F4C: nop

;}
RECOMP_FUNC void func_800907C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800907C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800907C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800907C8: jal         0x800F54E4
    // 0x800907CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800907CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800907D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800907D4: jal         0x800F8418
    // 0x800907D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F8418(rdram, ctx);
        goto after_1;
    // 0x800907D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800907DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800907E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800907E4: jr          $ra
    // 0x800907E8: nop

    return;
    // 0x800907E8: nop

;}
RECOMP_FUNC void idbounce_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80800DDC: addiu       $v0, $v0, 0x5480
    ctx->r2 = ADD32(ctx->r2, 0X5480);
    // 0x80800DE0: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80800DE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DEC: beql        $t6, $zero, L_80800E18
    if (ctx->r14 == 0) {
        // 0x80800DF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800E18;
    }
    goto skip_0;
    // 0x80800DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800DF4: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x80800DF8: bnel        $t7, $zero, L_80800E18
    if (ctx->r15 != 0) {
        // 0x80800DFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800E18;
    }
    goto skip_1;
    // 0x80800DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800E00: jal         0x800F54E4
    // 0x80800E04: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800E04: nop

    after_0:
    // 0x80800E08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E0C: jal         0x800F83E4
    // 0x80800E10: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    func_800F83E4(rdram, ctx);
        goto after_1;
    // 0x80800E10: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    after_1:
    // 0x80800E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E18:
    // 0x80800E18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E1C: jr          $ra
    // 0x80800E20: nop

    return;
    // 0x80800E20: nop

    // 0x80800E24: nop

    // 0x80800E28: nop

    // 0x80800E2C: nop

;}
RECOMP_FUNC void boot___osDisableInt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80802250_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802250: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802258: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080225C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802260: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80802264: jal         0x80100094
    // 0x80802268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080226C: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80802270: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80802274: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80802278: jal         0x8008A800
    // 0x8080227C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _suquiz_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x8080227C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80802280: beql        $v0, $zero, L_8080229C
    if (ctx->r2 == 0) {
        // 0x80802284: lhu         $t7, 0x76($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X76);
            goto L_8080229C;
    }
    goto skip_0;
    // 0x80802284: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
    skip_0:
    // 0x80802288: jal         0x800FFAB0
    // 0x8080228C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080228C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802290: b           L_80802424
    // 0x80802294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802424;
    // 0x80802294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802298: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
L_8080229C:
    // 0x8080229C: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808022A0: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x808022A4: beq         $at, $zero, L_808023BC
    if (ctx->r1 == 0) {
        // 0x808022A8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808023BC;
    }
    // 0x808022A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808022AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X65AC) << 16);
    // 0x808022B0: addu        $at, $at, $t8
    gpr jr_addend_808022B8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808022B4: lw          $t8, 0x65AC($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X65AC));
    // 0x808022B8: jr          $t8
    // 0x808022BC: nop

    switch (jr_addend_808022B8 >> 2) {
        case 0: goto L_80802334; break;
        case 1: goto L_80802314; break;
        case 2: goto L_808022C0; break;
        case 3: goto L_80802344; break;
        case 4: goto L_8080235C; break;
        case 5: goto L_80802374; break;
        case 6: goto L_808023A4; break;
        default: switch_error(__func__, 0x808022B8, 0x808065AC);
    }
    // 0x808022BC: nop

L_808022C0:
    // 0x808022C0: jal         0x800DA298
    // 0x808022C4: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808022C4: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_3:
    // 0x808022C8: beq         $v0, $zero, L_808022E0
    if (ctx->r2 == 0) {
        // 0x808022CC: nop
    
            goto L_808022E0;
    }
    // 0x808022CC: nop

    // 0x808022D0: jal         0x800FFAB0
    // 0x808022D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x808022D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808022D8: b           L_80802424
    // 0x808022DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802424;
    // 0x808022DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808022E0:
    // 0x808022E0: jal         0x800857B0
    // 0x808022E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _chblink_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808022E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x808022E8: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x808022EC: jal         0x800857B0
    // 0x808022F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chblink_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808022F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x808022F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2484, 0X7328) << 16);
    // 0x808022F8: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x808022FC: addiu       $a2, $a2, 0x7328
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2484, 0X7328));
    // 0x80802300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802304: jal         0x808021C8
    // 0x80802308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808021C8_chquiz(rdram, ctx);
        goto after_7;
    // 0x80802308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8080230C: b           L_808023C8
    // 0x80802310: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
        goto L_808023C8;
    // 0x80802310: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
L_80802314:
    // 0x80802314: jal         0x800857B0
    // 0x80802318: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _chblink_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80802318: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x8080231C: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80802320: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x80802324: lbu         $t0, 0x64($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X64);
    // 0x80802328: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8080232C: b           L_808023C4
    // 0x80802330: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
        goto L_808023C4;
    // 0x80802330: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
L_80802334:
    // 0x80802334: lbu         $t3, 0x64($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X64);
    // 0x80802338: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x8080233C: b           L_808023C4
    // 0x80802340: sb          $t4, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r12;
        goto L_808023C4;
    // 0x80802340: sb          $t4, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r12;
L_80802344:
    // 0x80802344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080234C: jal         0x808021C8
    // 0x80802350: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_808021C8_chquiz(rdram, ctx);
        goto after_9;
    // 0x80802350: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80802354: b           L_808023C8
    // 0x80802358: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
        goto L_808023C8;
    // 0x80802358: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
L_8080235C:
    // 0x8080235C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802364: jal         0x808021C8
    // 0x80802368: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_808021C8_chquiz(rdram, ctx);
        goto after_10;
    // 0x80802368: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x8080236C: b           L_808023C8
    // 0x80802370: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
        goto L_808023C8;
    // 0x80802370: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
L_80802374:
    // 0x80802374: jal         0x800857B0
    // 0x80802378: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _chblink_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80802378: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_11:
    // 0x8080237C: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80802380: jal         0x800857B0
    // 0x80802384: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chblink_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80802384: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80802388: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x8080238C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802390: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80802394: jal         0x808021C8
    // 0x80802398: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_808021C8_chquiz(rdram, ctx);
        goto after_13;
    // 0x80802398: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x8080239C: b           L_808023C8
    // 0x808023A0: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
        goto L_808023C8;
    // 0x808023A0: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
L_808023A4:
    // 0x808023A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808023AC: jal         0x808021C8
    // 0x808023B0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_808021C8_chquiz(rdram, ctx);
        goto after_14;
    // 0x808023B0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_14:
    // 0x808023B4: b           L_808023C8
    // 0x808023B8: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
        goto L_808023C8;
    // 0x808023B8: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
L_808023BC:
    // 0x808023BC: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x808023C0: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
L_808023C4:
    // 0x808023C4: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
L_808023C8:
    // 0x808023C8: srl         $t5, $a0, 7
    ctx->r13 = S32(U32(ctx->r4) >> 7);
    // 0x808023CC: jal         0x80800000
    // 0x808023D0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_80800000_chquiz(rdram, ctx);
        goto after_15;
    // 0x808023D0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_15:
    // 0x808023D4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x808023D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023DC: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x808023E0: jal         0x80103140
    // 0x808023E4: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    func_80103140(rdram, ctx);
        goto after_16;
    // 0x808023E4: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    after_16:
    // 0x808023E8: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x808023EC: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x808023F0: jal         0x80800070
    // 0x808023F4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80800070_chquiz(rdram, ctx);
        goto after_17;
    // 0x808023F4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_17:
    // 0x808023F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808023FC: jal         0x80102FDC
    // 0x80802400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_18;
    // 0x80802400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80802404: jal         0x80802004
    // 0x80802408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802004_chquiz(rdram, ctx);
        goto after_19;
    // 0x80802408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080240C: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x80802410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802414: srl         $t8, $a1, 10
    ctx->r24 = S32(U32(ctx->r5) >> 10);
    // 0x80802418: jal         0x80102424
    // 0x8080241C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_80102424(rdram, ctx);
        goto after_20;
    // 0x8080241C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_20:
    // 0x80802420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802424:
    // 0x80802424: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80802428: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080242C: jr          $ra
    // 0x80802430: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80802430: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C8E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8E84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8E88: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C8E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8E90: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C8E94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8E98: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8E9C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800C8EA0: jal         0x800B28CC
    // 0x800C8EA4: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C8EA4: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    after_0:
    // 0x800C8EA8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8EAC: lbu         $t6, 0xA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XA);
    // 0x800C8EB0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800C8EB4: bnel        $t6, $v1, L_800C8EE0
    if (ctx->r14 != ctx->r3) {
        // 0x800C8EB8: sb          $v1, 0xA($v0)
        MEM_B(0XA, ctx->r2) = ctx->r3;
            goto L_800C8EE0;
    }
    goto skip_0;
    // 0x800C8EB8: sb          $v1, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r3;
    skip_0:
    // 0x800C8EBC: lbu         $t7, 0xB($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XB);
    // 0x800C8EC0: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x800C8EC4: bnel        $t7, $t8, L_800C8EE0
    if (ctx->r15 != ctx->r24) {
        // 0x800C8EC8: sb          $v1, 0xA($v0)
        MEM_B(0XA, ctx->r2) = ctx->r3;
            goto L_800C8EE0;
    }
    goto skip_1;
    // 0x800C8EC8: sb          $v1, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r3;
    skip_1:
    // 0x800C8ECC: lbu         $t9, 0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XC);
    // 0x800C8ED0: lw          $t0, 0x8($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X8);
    // 0x800C8ED4: beql        $t9, $t0, L_800C8EFC
    if (ctx->r25 == ctx->r8) {
        // 0x800C8ED8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8EFC;
    }
    goto skip_2;
    // 0x800C8ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800C8EDC: sb          $v1, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r3;
L_800C8EE0:
    // 0x800C8EE0: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x800C8EE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C8EE8: sb          $t1, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r9;
    // 0x800C8EEC: lw          $t2, 0x8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X8);
    // 0x800C8EF0: sb          $t3, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r11;
    // 0x800C8EF4: sb          $t2, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r10;
    // 0x800C8EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8EFC:
    // 0x800C8EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8F00: jr          $ra
    // 0x800C8F04: nop

    return;
    // 0x800C8F04: nop

;}
RECOMP_FUNC void func_80802234_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080223C: jal         0x800EA05C
    // 0x80802240: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80802240: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802244: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
    // 0x80802248: bne         $v0, $at, L_80802260
    if (ctx->r2 != ctx->r1) {
        // 0x8080224C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80802260;
    }
    // 0x8080224C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80802250: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80802254: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802258: b           L_80802270
    // 0x8080225C: swc1        $f4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f4.u32l;
        goto L_80802270;
    // 0x8080225C: swc1        $f4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f4.u32l;
L_80802260:
    // 0x80802260: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802264: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802268: nop

    // 0x8080226C: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
L_80802270:
    // 0x80802270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802278: jr          $ra
    // 0x8080227C: nop

    return;
    // 0x8080227C: nop

;}
RECOMP_FUNC void func_800E8C08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8C08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8C0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E8C10: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800E8C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8C18: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8C1C: jal         0x800B32C0
    // 0x800E8C20: lw          $a0, -0x2980($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2980);
    freelist_erase(rdram, ctx);
        goto after_0;
    // 0x800E8C20: lw          $a0, -0x2980($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2980);
    after_0:
    // 0x800E8C24: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8C28: jal         0x800B3204
    // 0x800E8C2C: lw          $a0, -0x2980($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2980);
    freelist_used_count(rdram, ctx);
        goto after_1;
    // 0x800E8C2C: lw          $a0, -0x2980($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2980);
    after_1:
    // 0x800E8C30: bne         $v0, $zero, L_800E8C48
    if (ctx->r2 != 0) {
        // 0x800E8C34: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800E8C48;
    }
    // 0x800E8C34: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8C38: jal         0x800B3248
    // 0x800E8C3C: lw          $a0, -0x2980($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2980);
    freelist_free(rdram, ctx);
        goto after_2;
    // 0x800E8C3C: lw          $a0, -0x2980($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2980);
    after_2:
    // 0x800E8C40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E8C44: sw          $zero, -0x2980($at)
    MEM_W(-0X2980, ctx->r1) = 0;
L_800E8C48:
    // 0x800E8C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8C50: jr          $ra
    // 0x800E8C54: nop

    return;
    // 0x800E8C54: nop

;}
