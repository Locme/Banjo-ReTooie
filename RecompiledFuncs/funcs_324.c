#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800EFED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFED0: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EFED4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EFED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFEDC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800EFEE0: nop

    // 0x800EFEE4: bc1f        L_800EFEF0
    if (!c1cs) {
        // 0x800EFEE8: nop
    
            goto L_800EFEF0;
    }
    // 0x800EFEE8: nop

    // 0x800EFEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFEF0:
    // 0x800EFEF0: beq         $v0, $zero, L_800EFFAC
    if (ctx->r2 == 0) {
        // 0x800EFEF4: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFEF4: nop

    // 0x800EFEF8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EFEFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFF00: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800EFF04: nop

    // 0x800EFF08: bc1f        L_800EFF14
    if (!c1cs) {
        // 0x800EFF0C: nop
    
            goto L_800EFF14;
    }
    // 0x800EFF0C: nop

    // 0x800EFF10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFF14:
    // 0x800EFF14: beq         $v0, $zero, L_800EFFAC
    if (ctx->r2 == 0) {
        // 0x800EFF18: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFF18: nop

    // 0x800EFF1C: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EFF20: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EFF24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFF28: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800EFF2C: nop

    // 0x800EFF30: bc1f        L_800EFF3C
    if (!c1cs) {
        // 0x800EFF34: nop
    
            goto L_800EFF3C;
    }
    // 0x800EFF34: nop

    // 0x800EFF38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFF3C:
    // 0x800EFF3C: beq         $v0, $zero, L_800EFFAC
    if (ctx->r2 == 0) {
        // 0x800EFF40: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFF40: nop

    // 0x800EFF44: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EFF48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFF4C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800EFF50: nop

    // 0x800EFF54: bc1f        L_800EFF60
    if (!c1cs) {
        // 0x800EFF58: nop
    
            goto L_800EFF60;
    }
    // 0x800EFF58: nop

    // 0x800EFF5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFF60:
    // 0x800EFF60: beq         $v0, $zero, L_800EFFAC
    if (ctx->r2 == 0) {
        // 0x800EFF64: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFF64: nop

    // 0x800EFF68: lwc1        $f0, 0x8($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EFF6C: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EFF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFF74: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800EFF78: nop

    // 0x800EFF7C: bc1f        L_800EFF88
    if (!c1cs) {
        // 0x800EFF80: nop
    
            goto L_800EFF88;
    }
    // 0x800EFF80: nop

    // 0x800EFF84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFF88:
    // 0x800EFF88: beq         $v0, $zero, L_800EFFAC
    if (ctx->r2 == 0) {
        // 0x800EFF8C: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFF8C: nop

    // 0x800EFF90: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EFF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFF98: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800EFF9C: nop

    // 0x800EFFA0: bc1f        L_800EFFAC
    if (!c1cs) {
        // 0x800EFFA4: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFFA4: nop

    // 0x800EFFA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFFAC:
    // 0x800EFFAC: jr          $ra
    // 0x800EFFB0: nop

    return;
    // 0x800EFFB0: nop

;}
RECOMP_FUNC void chbaddiesetup_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080037C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800380: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800384: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800388: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080038C: jal         0x800A5D60
    // 0x80800390: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800A5D60(rdram, ctx);
        goto after_0;
    // 0x80800390: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800394: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800398: jal         0x80800000
    // 0x8080039C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800000_chbaddiesetup(rdram, ctx);
        goto after_1;
    // 0x8080039C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808003A0: beq         $v0, $zero, L_8080045C
    if (ctx->r2 == 0) {
        // 0x808003A4: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8080045C;
    }
    // 0x808003A4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A8: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x808003AC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x808003B0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808003B4: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x808003B8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x808003BC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x808003C0: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    // 0x808003C4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x808003C8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x808003CC: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x808003D0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x808003D4: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x808003D8: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x808003DC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x808003E0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808003E4: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x808003E8: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x808003EC: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x808003F0: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    // 0x808003F4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x808003F8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x808003FC: sll         $t1, $t4, 5
    ctx->r9 = S32(ctx->r12 << 5);
    // 0x80800400: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x80800404: sw          $t3, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r11;
    // 0x80800408: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x8080040C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800410: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800414: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x80800418: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8080041C: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x80800420: lbu         $t1, 0x4($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4);
    // 0x80800424: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80800428: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8080042C: sll         $t3, $t1, 5
    ctx->r11 = S32(ctx->r9 << 5);
    // 0x80800430: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80800434: sw          $t4, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r12;
    // 0x80800438: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x8080043C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800440: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80800444: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x80800448: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8080044C: sw          $t6, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r14;
    // 0x80800450: lbu         $t1, 0x4($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4);
    // 0x80800454: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80800458: sb          $t2, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r10;
L_8080045C:
    // 0x8080045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800460: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void _ncba1p_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893C8: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x800893C8);
    return;
    // 0x800893CC: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _ncbaspline_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893C0: syscall     776
    recomp_syscall_handler(rdram, ctx, 0x800893C0);
    return;
    // 0x800893C4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void chmolehill_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080075C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800764: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800768: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080076C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800770: beql        $a1, $t7, L_808007DC
    if (ctx->r5 == ctx->r15) {
        // 0x80800774: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007DC;
    }
    goto skip_0;
    // 0x80800774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800778: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080077C: jal         0x80102424
    // 0x80800780: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800780: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800784: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800788: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080078C: lhu         $t8, 0x72($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X72);
    // 0x80800790: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800794: bnel        $t9, $at, L_808007BC
    if (ctx->r25 != ctx->r1) {
        // 0x80800798: lw          $a0, 0x3C($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X3C);
            goto L_808007BC;
    }
    goto skip_1;
    // 0x80800798: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    skip_1:
    // 0x8080079C: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    // 0x808007A0: beql        $a0, $zero, L_808007BC
    if (ctx->r4 == 0) {
        // 0x808007A4: lw          $a0, 0x3C($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X3C);
            goto L_808007BC;
    }
    goto skip_2;
    // 0x808007A4: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    skip_2:
    // 0x808007A8: jal         0x800FFA88
    // 0x808007AC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800FFA88(rdram, ctx);
        goto after_1;
    // 0x808007AC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808007B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808007B4: sw          $zero, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = 0;
    // 0x808007B8: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
L_808007BC:
    // 0x808007BC: beql        $a0, $zero, L_808007DC
    if (ctx->r4 == 0) {
        // 0x808007C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007DC;
    }
    goto skip_3;
    // 0x808007C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x808007C4: jal         0x80106790
    // 0x808007C8: nop

    func_80106790(rdram, ctx);
        goto after_2;
    // 0x808007C8: nop

    after_2:
    // 0x808007CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007D0: jal         0x80086900
    // 0x808007D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _chmoley_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808007D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808007D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007DC:
    // 0x808007DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007E0: jr          $ra
    // 0x808007E4: nop

    return;
    // 0x808007E4: nop

;}
RECOMP_FUNC void func_8008E37C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E37C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E384: jal         0x800A0FE4
    // 0x8008E388: nop

    func_800A0FE4(rdram, ctx);
        goto after_0;
    // 0x8008E388: nop

    after_0:
    // 0x8008E38C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E394: jr          $ra
    // 0x8008E398: nop

    return;
    // 0x8008E398: nop

;}
RECOMP_FUNC void _chfiregen_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A10: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x80086A10);
    return;
    // 0x80086A14: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_800CA688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA688: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CA68C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800CA690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA698: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CA69C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800CA6A0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800CA6A4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800CA6A8: jal         0x800EFA4C
    // 0x800CA6AC: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800CA6AC: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x800CA6B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA6B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA6B8: jr          $ra
    // 0x800CA6BC: nop

    return;
    // 0x800CA6BC: nop

;}
RECOMP_FUNC void _bsvan_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841A0: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x800841A0);
    return;
    // 0x800841A4: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084090: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x80084090);
    return;
    // 0x80084094: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080042C_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080042C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800430: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800434: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800438: jal         0x80800114
    // 0x8080043C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800114_bsvanswim(rdram, ctx);
        goto after_0;
    // 0x8080043C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800444: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x80800448: jal         0x8008CB3C
    // 0x8080044C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080044C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_1:
    // 0x80800450: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800454: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800460: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800464: jal         0x8009FFD8
    // 0x80800468: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800468: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800474: jal         0x8009C99C
    // 0x80800478: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80800478: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_3:
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: jal         0x8009B9B0
    // 0x80800484: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800484: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080048C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800490: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800494: jr          $ra
    // 0x80800498: nop

    return;
    // 0x80800498: nop

;}
RECOMP_FUNC void func_80021820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021820: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80021824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021828: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002182C: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x80021830: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80021834: beq         $t7, $zero, L_8002186C
    if (ctx->r15 == 0) {
        // 0x80021838: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8002186C;
    }
    // 0x80021838: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8002183C:
    // 0x8002183C: jal         0x80020E74
    // 0x80021840: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80020E74(rdram, ctx);
        goto after_0;
    // 0x80021840: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x80021844: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80021848: lw          $a1, 0x11F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X11F4);
    // 0x8002184C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80021850: jal         0x80020E40
    // 0x80021854: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80020E40(rdram, ctx);
        goto after_1;
    // 0x80021854: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80021858: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002185C: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x80021860: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x80021864: bne         $t9, $zero, L_8002183C
    if (ctx->r25 != 0) {
        // 0x80021868: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_8002183C;
    }
    // 0x80021868: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8002186C:
    // 0x8002186C: b           L_80021874
    // 0x80021870: nop

        goto L_80021874;
    // 0x80021870: nop

L_80021874:
    // 0x80021874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021878: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002187C: jr          $ra
    // 0x80021880: nop

    return;
    // 0x80021880: nop

;}
RECOMP_FUNC void func_80800508_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080050C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800510: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800518: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x8080051C: addiu       $a1, $zero, 0x3BF
    ctx->r5 = ADD32(0, 0X3BF);
    // 0x80800520: srl         $t6, $a2, 7
    ctx->r14 = S32(U32(ctx->r6) >> 7);
    // 0x80800524: jal         0x80089C70
    // 0x80800528: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    _subaddiefind_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80800528: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_0:
    // 0x8080052C: jal         0x80106790
    // 0x80800530: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800530: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80800534: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800538: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8080053C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800540: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800544: jal         0x80101FDC
    // 0x80800548: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800548: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    after_2:
    // 0x8080054C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800550: jal         0x80103110
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800558: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8080055C: lbu         $t2, 0x70($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X70);
    // 0x80800560: lw          $t8, 0x70($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X70);
    // 0x80800564: andi        $t3, $t2, 0xFF01
    ctx->r11 = ctx->r10 & 0XFF01;
    // 0x80800568: srl         $t9, $t8, 25
    ctx->r25 = S32(U32(ctx->r24) >> 25);
    // 0x8080056C: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x80800570: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800574: sb          $t4, 0x70($s0)
    MEM_B(0X70, ctx->r16) = ctx->r12;
    // 0x80800578: lw          $v0, 0x70($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X70);
    // 0x8080057C: sll         $t5, $v0, 22
    ctx->r13 = S32(ctx->r2 << 22);
    // 0x80800580: srl         $t6, $t5, 26
    ctx->r14 = S32(U32(ctx->r13) >> 26);
    // 0x80800584: beql        $t6, $zero, L_808005AC
    if (ctx->r14 == 0) {
        // 0x80800588: lhu         $t3, 0x72($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X72);
            goto L_808005AC;
    }
    goto skip_0;
    // 0x80800588: lhu         $t3, 0x72($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x8080058C: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x80800590: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x80800594: andi        $t9, $t8, 0x3F0
    ctx->r25 = ctx->r24 & 0X3F0;
    // 0x80800598: andi        $t2, $t0, 0xFC0F
    ctx->r10 = ctx->r8 & 0XFC0F;
    // 0x8080059C: or          $t1, $t9, $t2
    ctx->r9 = ctx->r25 | ctx->r10;
    // 0x808005A0: b           L_808005B8
    // 0x808005A4: sh          $t1, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r9;
        goto L_808005B8;
    // 0x808005A4: sh          $t1, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r9;
    // 0x808005A8: lhu         $t3, 0x72($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X72);
L_808005AC:
    // 0x808005AC: andi        $t4, $t3, 0xFC0F
    ctx->r12 = ctx->r11 & 0XFC0F;
    // 0x808005B0: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x808005B4: sh          $t5, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r13;
L_808005B8:
    // 0x808005B8: jal         0x80107200
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80107200(rdram, ctx);
        goto after_4;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808005C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005CC: jr          $ra
    // 0x808005D0: nop

    return;
    // 0x808005D0: nop

;}
RECOMP_FUNC void _chklungospiral_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867A0: syscall     373
    recomp_syscall_handler(rdram, ctx, 0x800867A0);
    return;
    // 0x800867A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_chlagoonentrygate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x8008A738
    // 0x80800010: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _sujiggy_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800014: beq         $v0, $zero, L_80800024
    if (ctx->r2 == 0) {
        // 0x80800018: nop
    
            goto L_80800024;
    }
    // 0x80800018: nop

    // 0x8080001C: jal         0x800DA544
    // 0x80800020: addiu       $a0, $zero, 0x395
    ctx->r4 = ADD32(0, 0X395);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800020: addiu       $a0, $zero, 0x395
    ctx->r4 = ADD32(0, 0X395);
    after_1:
L_80800024:
    // 0x80800024: jal         0x800D3E40
    // 0x80800028: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D3E40(rdram, ctx);
        goto after_2;
    // 0x80800028: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x8080002C: beql        $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x80800030: addiu       $a3, $zero, 0x395
        ctx->r7 = ADD32(0, 0X395);
            goto L_80800060;
    }
    goto skip_0;
    // 0x80800030: addiu       $a3, $zero, 0x395
    ctx->r7 = ADD32(0, 0X395);
    skip_0:
    // 0x80800034: jal         0x80088840
    // 0x80800038: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80800038: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    after_3:
    // 0x8080003C: bne         $v0, $zero, L_8080005C
    if (ctx->r2 != 0) {
        // 0x80800040: addiu       $a3, $zero, -0x1
        ctx->r7 = ADD32(0, -0X1);
            goto L_8080005C;
    }
    // 0x80800040: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80800044: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800048: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080004C: jal         0x80101FDC
    // 0x80800050: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800050: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80800054: b           L_80800060
    // 0x80800058: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_80800060;
    // 0x80800058: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_8080005C:
    // 0x8080005C: addiu       $a3, $zero, 0x395
    ctx->r7 = ADD32(0, 0X395);
L_80800060:
    // 0x80800060: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800064: lui         $a1, 0xC316
    ctx->r5 = S32(0XC316 << 16);
    // 0x80800068: jal         0x80086880
    // 0x8080006C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chdoormake_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080006C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800070: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800074: jal         0x800868A8
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800080: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void func_800DB9FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB9FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DBA00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBA04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DBA08: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800DBA0C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800DBA10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DBA14: jal         0x800DB9D0
    // 0x800DBA18: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DB9D0(rdram, ctx);
        goto after_0;
    // 0x800DBA18: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800DBA1C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800DBA20: sll         $a0, $a1, 3
    ctx->r4 = S32(ctx->r5 << 3);
    // 0x800DBA24: addu        $t7, $v0, $a0
    ctx->r15 = ADD32(ctx->r2, ctx->r4);
    // 0x800DBA28: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800DBA2C: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x800DBA30: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x800DBA34: beql        $t8, $zero, L_800DBA74
    if (ctx->r24 == 0) {
        // 0x800DBA38: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DBA74;
    }
    goto skip_0;
    // 0x800DBA38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800DBA3C: lwc1        $f4, 0x38($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X38);
    // 0x800DBA40: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x800DBA44: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800DBA48: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800DBA4C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800DBA50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DBA54: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800DBA58: nop

    // 0x800DBA5C: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DBA60: mflo        $t5
    ctx->r13 = lo;
    // 0x800DBA64: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800DBA68: b           L_800DBA78
    // 0x800DBA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DBA78;
    // 0x800DBA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DBA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DBA74:
    // 0x800DBA74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DBA78:
    // 0x800DBA78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DBA7C: jr          $ra
    // 0x800DBA80: nop

    return;
    // 0x800DBA80: nop

;}
RECOMP_FUNC void func_80016038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016038: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001603C: addiu       $v0, $v0, -0x6540
    ctx->r2 = ADD32(ctx->r2, -0X6540);
    // 0x80016040: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80016044: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80016048: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8001604C: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x80016050: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80016054: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x80016058: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x8001605C: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x80016060: jr          $ra
    // 0x80016064: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    return;
    // 0x80016064: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
;}
RECOMP_FUNC void func_80800124_chdinoroargrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800128: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080012C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800130: beq         $a1, $at, L_8080015C
    if (ctx->r5 == ctx->r1) {
        // 0x80800134: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080015C;
    }
    // 0x80800134: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800138: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x8080013C: beq         $a1, $at, L_80800180
    if (ctx->r5 == ctx->r1) {
        // 0x80800140: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_80800180;
    }
    // 0x80800140: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80800144: beq         $a1, $at, L_80800180
    if (ctx->r5 == ctx->r1) {
        // 0x80800148: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800180;
    }
    // 0x80800148: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080014C: beq         $a1, $at, L_80800204
    if (ctx->r5 == ctx->r1) {
        // 0x80800150: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800204;
    }
    // 0x80800150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800154: b           L_80800218
    // 0x80800158: nop

        goto L_80800218;
    // 0x80800158: nop

L_8080015C:
    // 0x8080015C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x80800160: bne         $a2, $at, L_80800178
    if (ctx->r6 != ctx->r1) {
        // 0x80800164: addiu       $a0, $zero, 0xA22
        ctx->r4 = ADD32(0, 0XA22);
            goto L_80800178;
    }
    // 0x80800164: addiu       $a0, $zero, 0xA22
    ctx->r4 = ADD32(0, 0XA22);
    // 0x80800168: jal         0x800DA544
    // 0x8080016C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x8080016C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800170: jal         0x800FFAB0
    // 0x80800174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80800178:
    // 0x80800178: b           L_80800218
    // 0x8080017C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800218;
    // 0x8080017C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800180:
    // 0x80800180: lwc1        $f0, 0x28($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X28);
    // 0x80800184: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2064, 0X250) << 16);
    // 0x80800188: addiu       $v1, $v1, 0x250
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2064, 0X250));
    // 0x8080018C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800190: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80800194: nop

    // 0x80800198: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8080019C: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x808001A0: beq         $v0, $zero, L_808001FC
    if (ctx->r2 == 0) {
        // 0x808001A4: nop
    
            goto L_808001FC;
    }
    // 0x808001A4: nop

    // 0x808001A8: bne         $a1, $v0, L_808001F0
    if (ctx->r5 != ctx->r2) {
        // 0x808001AC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808001F0;
    }
    // 0x808001AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001B4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x808001B8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x808001BC: swc1        $f8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f8.u32l;
    // 0x808001C0: lwc1        $f10, 0x28($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X28);
    // 0x808001C4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808001C8: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x808001CC: nop

    // 0x808001D0: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x808001D4: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x808001D8: bne         $t2, $zero, L_808001FC
    if (ctx->r10 != 0) {
        // 0x808001DC: nop
    
            goto L_808001FC;
    }
    // 0x808001DC: nop

    // 0x808001E0: jal         0x800FC63C
    // 0x808001E4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800FC63C(rdram, ctx);
        goto after_2;
    // 0x808001E4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x808001E8: b           L_80800218
    // 0x808001EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800218;
    // 0x808001EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001F0:
    // 0x808001F0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808001F4: nop

    // 0x808001F8: swc1        $f18, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f18.u32l;
L_808001FC:
    // 0x808001FC: b           L_80800218
    // 0x80800200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800218;
    // 0x80800200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800204:
    // 0x80800204: lbu         $t3, 0x79($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X79);
    // 0x80800208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080020C: andi        $t4, $t3, 0xFFFB
    ctx->r12 = ctx->r11 & 0XFFFB;
    // 0x80800210: b           L_80800218
    // 0x80800214: sb          $t4, 0x79($a3)
    MEM_B(0X79, ctx->r7) = ctx->r12;
        goto L_80800218;
    // 0x80800214: sb          $t4, 0x79($a3)
    MEM_B(0X79, ctx->r7) = ctx->r12;
L_80800218:
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080021C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void boot_inflate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800007AC: sw          $ra, 0xA6C($sp)
    MEM_W(0XA6C, ctx->r29) = ctx->r31;
    // 0x800007B0: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x800007B4: addiu       $gp, $zero, 0x0
    ctx->r28 = ADD32(0, 0X0);
    // 0x800007B8: addiu       $fp, $zero, 0x0
    ctx->r30 = ADD32(0, 0X0);
L_800007BC:
    // 0x800007BC: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800007C0: jal         0x8000080C
    // 0x800007C4: addiu       $a0, $sp, 0xA70
    ctx->r4 = ADD32(ctx->r29, 0XA70);
    boot_inflate_block(rdram, ctx);
        goto after_0;
    // 0x800007C4: addiu       $a0, $sp, 0xA70
    ctx->r4 = ADD32(ctx->r29, 0XA70);
    after_0:
    // 0x800007C8: bne         $v0, $zero, L_80000800
    if (ctx->r2 != 0) {
        // 0x800007CC: lw          $t3, 0xA70($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XA70);
            goto L_80000800;
    }
    // 0x800007CC: lw          $t3, 0xA70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA70);
    // 0x800007D0: beq         $t3, $zero, L_800007BC
    if (ctx->r11 == 0) {
        // 0x800007D4: slti        $at, $fp, 0x8
        ctx->r1 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
            goto L_800007BC;
    }
    // 0x800007D4: slti        $at, $fp, 0x8
    ctx->r1 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
    // 0x800007D8: bne         $at, $zero, L_800007F0
    if (ctx->r1 != 0) {
        // 0x800007DC: nop
    
            goto L_800007F0;
    }
    // 0x800007DC: nop

L_800007E0:
    // 0x800007E0: addiu       $fp, $fp, -0x8
    ctx->r30 = ADD32(ctx->r30, -0X8);
    // 0x800007E4: slti        $at, $fp, 0x8
    ctx->r1 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
    // 0x800007E8: beq         $at, $zero, L_800007E0
    if (ctx->r1 == 0) {
        // 0x800007EC: addiu       $s7, $s7, -0x1
        ctx->r23 = ADD32(ctx->r23, -0X1);
            goto L_800007E0;
    }
    // 0x800007EC: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
L_800007F0:
    // 0x800007F0: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    // 0x800007F4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800007F8: addiu       $t3, $t3, 0x6F48
    ctx->r11 = ADD32(ctx->r11, 0X6F48);
    // 0x800007FC: sw          $s7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r23;
L_80000800:
    // 0x80000800: lw          $ra, 0xA6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA6C);
    // 0x80000804: jr          $ra
    // 0x80000808: nop

    return;
    // 0x80000808: nop

;}
RECOMP_FUNC void func_8080102C_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080102C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801034: jal         0x808004CC
    // 0x80801038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexsmall_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080103C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801040: jal         0x800845D8
    // 0x80801044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801048: lui         $a2, 0x3F30
    ctx->r6 = S32(0X3F30 << 16);
    // 0x8080104C: ori         $a2, $a2, 0xA3D7
    ctx->r6 = ctx->r6 | 0XA3D7;
    // 0x80801050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801054: jal         0x800845E0
    // 0x80801058: addiu       $a1, $zero, 0x147
    ctx->r5 = ADD32(0, 0X147);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80801058: addiu       $a1, $zero, 0x147
    ctx->r5 = ADD32(0, 0X147);
    after_2:
    // 0x8080105C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801064: jr          $ra
    // 0x80801068: nop

    return;
    // 0x80801068: nop

;}
RECOMP_FUNC void _bscarry_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E70: syscall     31
    recomp_syscall_handler(rdram, ctx, 0x80082E70);
    return;
    // 0x80082E74: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void basnowball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
;}
RECOMP_FUNC void bafpctrl_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F68: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800F6C: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x80800F70: beql        $t7, $zero, L_80800F84
    if (ctx->r15 == 0) {
        // 0x80800F74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F84;
    }
    goto skip_0;
    // 0x80800F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800F78: jal         0x80800D38
    // 0x80800F7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bafpctrl_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800F7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F84:
    // 0x80800F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F88: jr          $ra
    // 0x80800F8C: nop

    return;
    // 0x80800F8C: nop

;}
RECOMP_FUNC void _gcdialogexec_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E28: syscall     658
    recomp_syscall_handler(rdram, ctx, 0x80087E28);
    return;
    // 0x80087E2C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800798_chworlddoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800798: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080079C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007A4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808007A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808007B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808007B4: jal         0x800EE7F8
    // 0x808007B8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808007B8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x808007BC: jal         0x80103EAC
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_1;
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808007C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808007CC: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x808007D0: jal         0x800EF214
    // 0x808007D4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    func_800EF214(rdram, ctx);
        goto after_2;
    // 0x808007D4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    after_2:
    // 0x808007D8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808007DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808007E8: beq         $t6, $at, L_808008C0
    if (ctx->r14 == ctx->r1) {
        // 0x808007EC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808008C0;
    }
    // 0x808007EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808007F0: beq         $t6, $at, L_8080080C
    if (ctx->r14 == ctx->r1) {
        // 0x808007F4: lui         $a3, 0x38D1
        ctx->r7 = S32(0X38D1 << 16);
            goto L_8080080C;
    }
    // 0x808007F4: lui         $a3, 0x38D1
    ctx->r7 = S32(0X38D1 << 16);
    // 0x808007F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808007FC: beq         $t6, $at, L_808008D0
    if (ctx->r14 == ctx->r1) {
        // 0x80800800: lui         $a3, 0x437F
        ctx->r7 = S32(0X437F << 16);
            goto L_808008D0;
    }
    // 0x80800800: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800804: b           L_8080090C
    // 0x80800808: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_8080090C;
    // 0x80800808: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_8080080C:
    // 0x8080080C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2476, 0X988) << 16);
    // 0x80800810: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800814: lwc1        $f14, 0x988($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2476, 0X988));
    // 0x80800818: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080081C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800820: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800824: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800828: ori         $a3, $a3, 0xB717
    ctx->r7 = ctx->r7 | 0XB717;
    // 0x8080082C: jal         0x800F10B4
    // 0x80800830: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800830: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800834: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800838: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2476, 0X98C) << 16);
    // 0x8080083C: lwc1        $f14, 0x98C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2476, 0X98C));
    // 0x80800840: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800844: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800848: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8080084C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800850: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800854: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800858: jal         0x800F10B4
    // 0x8080085C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x8080085C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80800860: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800868: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8080086C: jal         0x800DF830
    // 0x80800870: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    func_800DF830(rdram, ctx);
        goto after_5;
    // 0x80800870: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    after_5:
    // 0x80800874: jal         0x800D674C
    // 0x80800878: addiu       $a0, $zero, 0x8CB
    ctx->r4 = ADD32(0, 0X8CB);
    func_800D674C(rdram, ctx);
        goto after_6;
    // 0x80800878: addiu       $a0, $zero, 0x8CB
    ctx->r4 = ADD32(0, 0X8CB);
    after_6:
    // 0x8080087C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800880: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800884: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    // 0x80800888: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8080088C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800890: jal         0x800DE498
    // 0x80800894: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800DE498(rdram, ctx);
        goto after_7;
    // 0x80800894: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_7:
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080089C: jal         0x80101870
    // 0x808008A0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80101870(rdram, ctx);
        goto after_8;
    // 0x808008A0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x808008A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2476, 0X9F8) << 16);
    // 0x808008A8: addiu       $a2, $a2, 0x9F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2476, 0X9F8));
    // 0x808008AC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808008B0: jal         0x800B99CC
    // 0x808008B4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800B99CC(rdram, ctx);
        goto after_9;
    // 0x808008B4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_9:
    // 0x808008B8: b           L_8080090C
    // 0x808008BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_8080090C;
    // 0x808008BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_808008C0:
    // 0x808008C0: jal         0x80101870
    // 0x808008C4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80101870(rdram, ctx);
        goto after_10;
    // 0x808008C4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_10:
    // 0x808008C8: b           L_8080090C
    // 0x808008CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_8080090C;
    // 0x808008CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_808008D0:
    // 0x808008D0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808008D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808008D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808008DC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808008E0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808008E4: jal         0x800F10B4
    // 0x808008E8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x808008E8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_11:
    // 0x808008EC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808008F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2476, 0X9F8) << 16);
    // 0x808008F4: addiu       $a2, $a2, 0x9F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2476, 0X9F8));
    // 0x808008F8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808008FC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800900: jal         0x800B99CC
    // 0x80800904: nop

    func_800B99CC(rdram, ctx);
        goto after_12;
    // 0x80800904: nop

    after_12:
    // 0x80800908: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_8080090C:
    // 0x8080090C: jal         0x800EE7F8
    // 0x80800910: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x80800910: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_13:
    // 0x80800914: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800918: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080091C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800920: jr          $ra
    // 0x80800924: nop

    return;
    // 0x80800924: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800118: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8080011C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80800120: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3354, 0X8E0) << 16);
    // 0x80800124: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800128: jr          $ra
    // 0x8080012C: lbu         $v0, 0x8E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8E0));
    return;
    // 0x8080012C: lbu         $v0, 0x8E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8E0));
;}
RECOMP_FUNC void func_8080000C_chcrystalbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x80100094
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800028: jal         0x80089F70
    // 0x8080002C: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800038: nop

    // 0x8080003C: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80800040: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void suegg_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808006D4: jal         0x80088638
    // 0x808006D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _glhittableDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x808006D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x808006DC: beql        $v0, $zero, L_80800718
    if (ctx->r2 == 0) {
        // 0x808006E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800718;
    }
    goto skip_0;
    // 0x808006E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808006E4: jal         0x80088650
    // 0x808006E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _glhittableDll_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808006E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808006EC: beql        $v0, $zero, L_80800718
    if (ctx->r2 == 0) {
        // 0x808006F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800718;
    }
    goto skip_1;
    // 0x808006F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808006F4: jal         0x80106790
    // 0x808006F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x808006F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808006FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800700: jal         0x80100094
    // 0x80800704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800708: lbu         $t7, 0x39($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X39);
    // 0x8080070C: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80800710: sb          $t8, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r24;
    // 0x80800714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800718:
    // 0x80800718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080071C: jr          $ra
    // 0x80800720: nop

    return;
    // 0x80800720: nop

;}
RECOMP_FUNC void func_80800298_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080029C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002A4: jal         0x80100094
    // 0x808002A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002AC: lw          $a2, 0x94($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X94);
    // 0x808002B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002B8: beql        $a2, $zero, L_808002E4
    if (ctx->r6 == 0) {
        // 0x808002BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002E4;
    }
    goto skip_0;
    // 0x808002BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002C0: jal         0x80100094
    // 0x808002C4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808002C4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x808002C8: lbu         $t6, 0x99($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X99);
    // 0x808002CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D0: beql        $t6, $zero, L_808002E4
    if (ctx->r14 == 0) {
        // 0x808002D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002E4;
    }
    goto skip_1;
    // 0x808002D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808002D8: jal         0x80087C98
    // 0x808002DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808002DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x808002E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002E4:
    // 0x808002E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002E8: jr          $ra
    // 0x808002EC: nop

    return;
    // 0x808002EC: nop

;}
RECOMP_FUNC void func_80800000_chminelightswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: beq         $a1, $at, L_80800024
    if (ctx->r5 == ctx->r1) {
        // 0x8080000C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800024;
    }
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800014: beq         $a1, $at, L_80800044
    if (ctx->r5 == ctx->r1) {
        // 0x80800018: nop
    
            goto L_80800044;
    }
    // 0x80800018: nop

    // 0x8080001C: b           L_80800070
    // 0x80800020: nop

        goto L_80800070;
    // 0x80800020: nop

L_80800024:
    // 0x80800024: jal         0x800DA298
    // 0x80800028: addiu       $a0, $zero, 0x673
    ctx->r4 = ADD32(0, 0X673);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a0, $zero, 0x673
    ctx->r4 = ADD32(0, 0X673);
    after_0:
    // 0x8080002C: bne         $v0, $zero, L_80800080
    if (ctx->r2 != 0) {
        // 0x80800030: addiu       $a0, $zero, 0xCF
        ctx->r4 = ADD32(0, 0XCF);
            goto L_80800080;
    }
    // 0x80800030: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    // 0x80800034: jal         0x800887D8
    // 0x80800038: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800038: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_1:
    // 0x8080003C: b           L_80800084
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800084;
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800044:
    // 0x80800044: jal         0x800DA298
    // 0x80800048: addiu       $a0, $zero, 0x673
    ctx->r4 = ADD32(0, 0X673);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a0, $zero, 0x673
    ctx->r4 = ADD32(0, 0X673);
    after_2:
    // 0x8080004C: bnel        $v0, $zero, L_80800084
    if (ctx->r2 != 0) {
        // 0x80800050: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800084;
    }
    goto skip_0;
    // 0x80800050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800054: jal         0x800DA544
    // 0x80800058: addiu       $a0, $zero, 0x673
    ctx->r4 = ADD32(0, 0X673);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800058: addiu       $a0, $zero, 0x673
    ctx->r4 = ADD32(0, 0X673);
    after_3:
    // 0x8080005C: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    // 0x80800060: jal         0x800887D8
    // 0x80800064: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800064: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_4:
    // 0x80800068: b           L_80800084
    // 0x8080006C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800084;
    // 0x8080006C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800070:
    // 0x80800070: jal         0x80085820
    // 0x80800074: nop

    _chswitch_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800074: nop

    after_5:
    // 0x80800078: b           L_80800088
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800088;
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800080:
    // 0x80800080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800084:
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800088:
    // 0x80800088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void func_800EEAD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEAD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EEAD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EEADC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EEAE0: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EEAE4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EEAE8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800EEAEC: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EEAF0: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EEAF4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800EEAF8: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EEAFC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x800EEB00: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EEB04: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EEB08: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800EEB0C: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EEB10: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EEB14: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800EEB18: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800EEB1C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EEB20: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800EEB24: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800EEB28: jal         0x8002DCA0
    // 0x800EEB2C: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800EEB2C: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_0:
    // 0x800EEB30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EEB34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800EEB38: jr          $ra
    // 0x800EEB3C: nop

    return;
    // 0x800EEB3C: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089520: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089520);
    return;
    // 0x80089524: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_8001C1C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C1C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C1C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C1C8: jal         0x8001D1E0
    // 0x8001C1CC: nop

    func_8001D1E0(rdram, ctx);
        goto after_0;
    // 0x8001C1CC: nop

    after_0:
    // 0x8001C1D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C1D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C1D8: jr          $ra
    // 0x8001C1DC: nop

    return;
    // 0x8001C1DC: nop

;}
RECOMP_FUNC void func_800C6E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6E20: jal         0x800DA298
    // 0x800C6E24: addiu       $a0, $a0, 0xEE
    ctx->r4 = ADD32(ctx->r4, 0XEE);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x800C6E24: addiu       $a0, $a0, 0xEE
    ctx->r4 = ADD32(ctx->r4, 0XEE);
    after_0:
    // 0x800C6E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6E2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C6E30: jr          $ra
    // 0x800C6E34: nop

    return;
    // 0x800C6E34: nop

;}
RECOMP_FUNC void _fxmumbo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088998: syscall     714
    recomp_syscall_handler(rdram, ctx, 0x80088998);
    return;
    // 0x8008899C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080118C_subaddiedialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080118C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801194: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80801198: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080119C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808011A0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808011A4: jal         0x8010D254
    // 0x808011A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x808011A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x808011AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808011B0: jal         0x800F1DF4
    // 0x808011B4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F1DF4(rdram, ctx);
        goto after_1;
    // 0x808011B4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808011B8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x808011BC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x808011C0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808011C4: jal         0x800F1DCC
    // 0x808011C8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x808011C8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x808011CC: jal         0x800F2100
    // 0x808011D0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x808011D0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x808011D4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x808011D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808011DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011E0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x808011E4: nop

    // 0x808011E8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808011EC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808011F0: nop

    // 0x808011F4: bc1f        L_80801200
    if (!c1cs) {
        // 0x808011F8: nop
    
            goto L_80801200;
    }
    // 0x808011F8: nop

    // 0x808011FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801200:
    // 0x80801200: jr          $ra
    // 0x80801204: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801204: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800F00A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F00A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F00A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F00AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800F00B0: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800F00B4: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800F00B8: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800F00BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800F00C0: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800F00C4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F00C8: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F00CC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F00D0: nop

    // 0x800F00D4: bc1t        L_800F00F0
    if (c1cs) {
        // 0x800F00D8: nop
    
            goto L_800F00F0;
    }
    // 0x800F00D8: nop

    // 0x800F00DC: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800F00E0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800F00E4: nop

    // 0x800F00E8: bc1f        L_800F00F8
    if (!c1cs) {
        // 0x800F00EC: nop
    
            goto L_800F00F8;
    }
    // 0x800F00EC: nop

L_800F00F0:
    // 0x800F00F0: b           L_800F0120
    // 0x800F00F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0120;
    // 0x800F00F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F00F8:
    // 0x800F00F8: jal         0x800EFC7C
    // 0x800F00FC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_800EFC7C(rdram, ctx);
        goto after_0;
    // 0x800F00FC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800F0100: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F0104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F0108: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800F010C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800F0110: nop

    // 0x800F0114: bc1fl       L_800F0124
    if (!c1cs) {
        // 0x800F0118: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F0124;
    }
    goto skip_0;
    // 0x800F0118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800F011C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F0120:
    // 0x800F0120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F0124:
    // 0x800F0124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F0128: jr          $ra
    // 0x800F012C: nop

    return;
    // 0x800F012C: nop

;}
RECOMP_FUNC void _gccubesearch_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882D8: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882D8);
    return;
    // 0x800882DC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _ncfixposrot_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089238: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x80089238);
    return;
    // 0x8008923C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_8080093C_chswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080093C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800940: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800944: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080094C: jal         0x800CB854
    // 0x80800950: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800CB854(rdram, ctx);
        goto after_0;
    // 0x80800950: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800954: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800958: bnel        $v0, $at, L_808009B8
    if (ctx->r2 != ctx->r1) {
        // 0x8080095C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808009B8;
    }
    goto skip_0;
    // 0x8080095C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800960: jal         0x80100120
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100120(rdram, ctx);
        goto after_1;
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800968: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x8080096C: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80800970: bltzl       $t8, L_808009B8
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800974: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808009B8;
    }
    goto skip_1;
    // 0x80800974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800978: jal         0x800DA298
    // 0x8080097C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080097C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x80800980: beq         $v0, $zero, L_808009B4
    if (ctx->r2 == 0) {
        // 0x80800984: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009B4;
    }
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800988: jal         0x80102424
    // 0x8080098C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x8080098C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800990: jal         0x80102204
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102204(rdram, ctx);
        goto after_4;
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800998: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080099C: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808009A0: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x808009A4: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x808009A8: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x808009AC: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x808009B0: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
L_808009B4:
    // 0x808009B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009B8:
    // 0x808009B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009C0: jr          $ra
    // 0x808009C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808009C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void _bsdronewaitbabykaz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083198: syscall     49
    recomp_syscall_handler(rdram, ctx, 0x80083198);
    return;
    // 0x8008319C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800824_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800824: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800828: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080082C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800830: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800834: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800838: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080083C: jal         0x800F5D70
    // 0x80800840: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800F5D70(rdram, ctx);
        goto after_0;
    // 0x80800840: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800844: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800848: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080084C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800850: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800854: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800858: nop

    // 0x8080085C: bc1fl       L_808008CC
    if (!c1cs) {
        // 0x80800860: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008CC;
    }
    goto skip_0;
    // 0x80800860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800864: lwc1        $f0, 0x8($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80800868: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080086C: lwc1        $f2, 0x1C($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80800870: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800874: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x80800878: nop

    // 0x8080087C: bc1fl       L_808008CC
    if (!c1cs) {
        // 0x80800880: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008CC;
    }
    goto skip_1;
    // 0x80800880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800884: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80800888: nop

    // 0x8080088C: bc1f        L_808008A4
    if (!c1cs) {
        // 0x80800890: nop
    
            goto L_808008A4;
    }
    // 0x80800890: nop

    // 0x80800894: jal         0x8080025C
    // 0x80800898: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8080025C_chbanjoctrl(rdram, ctx);
        goto after_1;
    // 0x80800898: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8080089C: b           L_808008CC
    // 0x808008A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008CC;
    // 0x808008A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008A4:
    // 0x808008A4: jal         0x800F6720
    // 0x808008A8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F6720(rdram, ctx);
        goto after_2;
    // 0x808008A8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x808008AC: beql        $v0, $zero, L_808008CC
    if (ctx->r2 == 0) {
        // 0x808008B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008CC;
    }
    goto skip_2;
    // 0x808008B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x808008B4: jal         0x800F54E4
    // 0x808008B8: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808008B8: nop

    after_3:
    // 0x808008BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008C0: jal         0x800F7B9C
    // 0x808008C4: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_800F7B9C(rdram, ctx);
        goto after_4;
    // 0x808008C4: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_4:
    // 0x808008C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008CC:
    // 0x808008CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808008D0: jr          $ra
    // 0x808008D4: nop

    return;
    // 0x808008D4: nop

;}
RECOMP_FUNC void func_80801F74_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F74: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80801F78: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80801F7C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80801F80: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80801F84: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80801F88: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80801F8C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80801F90: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80801F94: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80801F98: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801F9C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801FA0: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80801FA4: jal         0x80100094
    // 0x80801FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801FAC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80801FB0: jal         0x8010CD28
    // 0x80801FB4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    func_8010CD28(rdram, ctx);
        goto after_1;
    // 0x80801FB4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_1:
    // 0x80801FB8: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80801FBC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80801FC0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801FC4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80801FC8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80801FCC: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1312, 0X264C) << 16);
    // 0x80801FD0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80801FD4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801FD8: addiu       $s3, $s3, 0x264C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1312, 0X264C));
    // 0x80801FDC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801FE0: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x80801FE4: addiu       $s2, $sp, 0x70
    ctx->r18 = ADD32(ctx->r29, 0X70);
    // 0x80801FE8: addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
L_80801FEC:
    // 0x80801FEC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801FF0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80801FF4: jal         0x800EEB9C
    // 0x80801FF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEB9C(rdram, ctx);
        goto after_2;
    // 0x80801FF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80801FFC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80802000: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802004: jal         0x800EF04C
    // 0x80802008: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80802008: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x8080200C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80802010: trunc.w.s   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x80802014: addiu       $a0, $zero, 0x448
    ctx->r4 = ADD32(0, 0X448);
    // 0x80802018: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080201C: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80802020: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80802024: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80802028: jal         0x80108528
    // 0x8080202C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    func_80108528(rdram, ctx);
        goto after_4;
    // 0x8080202C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80802030: swc1        $f20, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f20.u32l;
    // 0x80802034: lwc1        $f10, 0xC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80802038: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080203C: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x80802040: bne         $s0, $s4, L_80801FEC
    if (ctx->r16 != ctx->r20) {
        // 0x80802044: swc1        $f10, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
            goto L_80801FEC;
    }
    // 0x80802044: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x80802048: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8080204C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1312, 0X2668) << 16);
    // 0x80802050: addiu       $a2, $a2, 0x2668
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1312, 0X2668));
    // 0x80802054: jal         0x80089D18
    // 0x80802058: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80802058: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_5:
    // 0x8080205C: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80802060: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802068: jal         0x800D1254
    // 0x8080206C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800D1254(rdram, ctx);
        goto after_6;
    // 0x8080206C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80802070: jal         0x800D395C
    // 0x80802074: nop

    func_800D395C(rdram, ctx);
        goto after_7;
    // 0x80802074: nop

    after_7:
    // 0x80802078: beq         $v0, $zero, L_80802094
    if (ctx->r2 == 0) {
        // 0x8080207C: addiu       $a0, $zero, 0x450
        ctx->r4 = ADD32(0, 0X450);
            goto L_80802094;
    }
    // 0x8080207C: addiu       $a0, $zero, 0x450
    ctx->r4 = ADD32(0, 0X450);
    // 0x80802080: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80802084: jal         0x80800DA8
    // 0x80802088: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_8;
    // 0x80802088: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_8:
    // 0x8080208C: b           L_808020AC
    // 0x80802090: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
        goto L_808020AC;
    // 0x80802090: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
L_80802094:
    // 0x80802094: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80802098: jal         0x80101180
    // 0x8080209C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_9;
    // 0x8080209C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x808020A0: jal         0x800FFAB0
    // 0x808020A4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808020A4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_10:
    // 0x808020A8: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
L_808020AC:
    // 0x808020AC: jal         0x800FFA88
    // 0x808020B0: lw          $a0, 0x8C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8C);
    func_800FFA88(rdram, ctx);
        goto after_11;
    // 0x808020B0: lw          $a0, 0x8C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8C);
    after_11:
    // 0x808020B4: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x808020B8: sw          $zero, 0x8C($t8)
    MEM_W(0X8C, ctx->r24) = 0;
    // 0x808020BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x808020C0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x808020C4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x808020C8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x808020CC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x808020D0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808020D4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808020D8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808020DC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808020E0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808020E4: jr          $ra
    // 0x808020E8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808020E8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80800124_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800128: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800130: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800134: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800138: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080013C: jal         0x80100094
    // 0x80800140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800144: lhu         $t6, 0x72($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X72);
    // 0x80800148: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080014C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800150: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800154: sltiu       $at, $t8, 0xC
    ctx->r1 = ctx->r24 < 0XC ? 1 : 0;
    // 0x80800158: beq         $at, $zero, L_80800414
    if (ctx->r1 == 0) {
        // 0x8080015C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800414;
    }
    // 0x8080015C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800160: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X22D0) << 16);
    // 0x80800164: addu        $at, $at, $t8
    gpr jr_addend_8080016C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800168: lw          $t8, 0x22D0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2336, 0X22D0));
    // 0x8080016C: jr          $t8
    // 0x80800170: nop

    switch (jr_addend_8080016C >> 2) {
        case 0: goto L_80800174; break;
        case 1: goto L_808001CC; break;
        case 2: goto L_80800414; break;
        case 3: goto L_80800254; break;
        case 4: goto L_808002C4; break;
        case 5: goto L_80800414; break;
        case 6: goto L_80800338; break;
        case 7: goto L_80800414; break;
        case 8: goto L_80800414; break;
        case 9: goto L_80800414; break;
        case 10: goto L_80800414; break;
        case 11: goto L_808003CC; break;
        default: switch_error(__func__, 0x8080016C, 0x808022D0);
    }
    // 0x80800170: nop

L_80800174:
    // 0x80800174: jal         0x80801A7C
    // 0x80800178: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80801A7C_chpotogoldgame(rdram, ctx);
        goto after_1;
    // 0x80800178: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8080017C: jal         0x800DA298
    // 0x80800180: addiu       $a0, $zero, 0x9F6
    ctx->r4 = ADD32(0, 0X9F6);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800180: addiu       $a0, $zero, 0x9F6
    ctx->r4 = ADD32(0, 0X9F6);
    after_2:
    // 0x80800184: beq         $v0, $zero, L_80800414
    if (ctx->r2 == 0) {
        // 0x80800188: nop
    
            goto L_80800414;
    }
    // 0x80800188: nop

    // 0x8080018C: jal         0x800DA298
    // 0x80800190: addiu       $a0, $zero, 0x9F7
    ctx->r4 = ADD32(0, 0X9F7);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800190: addiu       $a0, $zero, 0x9F7
    ctx->r4 = ADD32(0, 0X9F7);
    after_3:
    // 0x80800194: beq         $v0, $zero, L_80800414
    if (ctx->r2 == 0) {
        // 0x80800198: nop
    
            goto L_80800414;
    }
    // 0x80800198: nop

    // 0x8080019C: jal         0x800DA298
    // 0x808001A0: addiu       $a0, $zero, 0x9F8
    ctx->r4 = ADD32(0, 0X9F8);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808001A0: addiu       $a0, $zero, 0x9F8
    ctx->r4 = ADD32(0, 0X9F8);
    after_4:
    // 0x808001A4: beq         $v0, $zero, L_80800414
    if (ctx->r2 == 0) {
        // 0x808001A8: nop
    
            goto L_80800414;
    }
    // 0x808001A8: nop

    // 0x808001AC: jal         0x800DA298
    // 0x808001B0: addiu       $a0, $zero, 0x9F9
    ctx->r4 = ADD32(0, 0X9F9);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808001B0: addiu       $a0, $zero, 0x9F9
    ctx->r4 = ADD32(0, 0X9F9);
    after_5:
    // 0x808001B4: beq         $v0, $zero, L_80800414
    if (ctx->r2 == 0) {
        // 0x808001B8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800414;
    }
    // 0x808001B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808001BC: jal         0x80800434
    // 0x808001C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_6;
    // 0x808001C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808001C4: b           L_80800414
    // 0x808001C8: nop

        goto L_80800414;
    // 0x808001C8: nop

L_808001CC:
    // 0x808001CC: jal         0x80801A7C
    // 0x808001D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80801A7C_chpotogoldgame(rdram, ctx);
        goto after_7;
    // 0x808001D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x808001D4: beq         $v0, $zero, L_80800414
    if (ctx->r2 == 0) {
        // 0x808001D8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800414;
    }
    // 0x808001D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808001DC: lbu         $a1, 0x64($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X64);
    // 0x808001E0: lbu         $a2, 0x65($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X65);
    // 0x808001E4: lbu         $a3, 0x66($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X66);
    // 0x808001E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808001EC: jal         0x808013BC
    // 0x808001F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_808013BC_chpotogoldgame(rdram, ctx);
        goto after_8;
    // 0x808001F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x808001F4: lbu         $t9, 0x65($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X65);
    // 0x808001F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808001FC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80800200: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80800204: bne         $t1, $at, L_80800414
    if (ctx->r9 != ctx->r1) {
        // 0x80800208: sb          $t0, 0x65($s1)
        MEM_B(0X65, ctx->r17) = ctx->r8;
            goto L_80800414;
    }
    // 0x80800208: sb          $t0, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r8;
    // 0x8080020C: lbu         $t2, 0x66($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X66);
    // 0x80800210: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80800214: sb          $zero, 0x65($s1)
    MEM_B(0X65, ctx->r17) = 0;
    // 0x80800218: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8080021C: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80800220: bne         $v0, $t4, L_80800414
    if (ctx->r2 != ctx->r12) {
        // 0x80800224: sb          $t3, 0x66($s1)
        MEM_B(0X66, ctx->r17) = ctx->r11;
            goto L_80800414;
    }
    // 0x80800224: sb          $t3, 0x66($s1)
    MEM_B(0X66, ctx->r17) = ctx->r11;
    // 0x80800228: lbu         $t5, 0x64($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X64);
    // 0x8080022C: sb          $zero, 0x66($s1)
    MEM_B(0X66, ctx->r17) = 0;
    // 0x80800230: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800234: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80800238: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8080023C: bne         $v0, $t7, L_80800414
    if (ctx->r2 != ctx->r15) {
        // 0x80800240: sb          $t6, 0x64($s1)
        MEM_B(0X64, ctx->r17) = ctx->r14;
            goto L_80800414;
    }
    // 0x80800240: sb          $t6, 0x64($s1)
    MEM_B(0X64, ctx->r17) = ctx->r14;
    // 0x80800244: jal         0x80800434
    // 0x80800248: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_9;
    // 0x80800248: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x8080024C: b           L_80800414
    // 0x80800250: nop

        goto L_80800414;
    // 0x80800250: nop

L_80800254:
    // 0x80800254: lw          $t8, 0x64($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X64);
    // 0x80800258: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    // 0x8080025C: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800260: bgez        $t0, L_80800414
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800264: nop
    
            goto L_80800414;
    }
    // 0x80800264: nop

    // 0x80800268: jal         0x80089C30
    // 0x8080026C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x8080026C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800270: bne         $v0, $zero, L_80800414
    if (ctx->r2 != 0) {
        // 0x80800274: nop
    
            goto L_80800414;
    }
    // 0x80800274: nop

    // 0x80800278: lbu         $t1, 0x65($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X65);
    // 0x8080027C: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x80800280: jal         0x800F54E4
    // 0x80800284: sb          $t2, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r10;
    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x80800284: sb          $t2, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r10;
    after_11:
    // 0x80800288: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8080028C: ori         $a1, $a1, 0x220
    ctx->r5 = ctx->r5 | 0X220;
    // 0x80800290: jal         0x800F64A4
    // 0x80800294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F64A4(rdram, ctx);
        goto after_12;
    // 0x80800294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x80800298: beq         $v0, $zero, L_808002B4
    if (ctx->r2 == 0) {
        // 0x8080029C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808002B4;
    }
    // 0x8080029C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002A4: jal         0x80800434
    // 0x808002A8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_13;
    // 0x808002A8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_13:
    // 0x808002AC: b           L_80800414
    // 0x808002B0: nop

        goto L_80800414;
    // 0x808002B0: nop

L_808002B4:
    // 0x808002B4: jal         0x80800434
    // 0x808002B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_14;
    // 0x808002B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_14:
    // 0x808002BC: b           L_80800414
    // 0x808002C0: nop

        goto L_80800414;
    // 0x808002C0: nop

L_808002C4:
    // 0x808002C4: lbu         $t3, 0x64($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X64);
    // 0x808002C8: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x808002CC: beq         $at, $zero, L_80800414
    if (ctx->r1 == 0) {
        // 0x808002D0: nop
    
            goto L_80800414;
    }
    // 0x808002D0: nop

    // 0x808002D4: jal         0x808011DC
    // 0x808002D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_808011DC_chpotogoldgame(rdram, ctx);
        goto after_15;
    // 0x808002D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_15:
    // 0x808002DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808002E0: lbu         $a1, 0x64($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X64);
L_808002E4:
    // 0x808002E4: lbu         $a3, 0x66($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X66);
    // 0x808002E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808002EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808002F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002F4: jal         0x808013BC
    // 0x808002F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_808013BC_chpotogoldgame(rdram, ctx);
        goto after_16;
    // 0x808002F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_16:
    // 0x808002FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800300: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800304: bnel        $s0, $at, L_808002E4
    if (ctx->r16 != ctx->r1) {
        // 0x80800308: lbu         $a1, 0x64($s1)
        ctx->r5 = MEM_BU(ctx->r17, 0X64);
            goto L_808002E4;
    }
    goto skip_0;
    // 0x80800308: lbu         $a1, 0x64($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X64);
    skip_0:
    // 0x8080030C: lbu         $t4, 0x66($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X66);
    // 0x80800310: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80800314: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80800318: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8080031C: bne         $v0, $t6, L_80800414
    if (ctx->r2 != ctx->r14) {
        // 0x80800320: sb          $t5, 0x66($s1)
        MEM_B(0X66, ctx->r17) = ctx->r13;
            goto L_80800414;
    }
    // 0x80800320: sb          $t5, 0x66($s1)
    MEM_B(0X66, ctx->r17) = ctx->r13;
    // 0x80800324: lbu         $t7, 0x64($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X64);
    // 0x80800328: sb          $zero, 0x66($s1)
    MEM_B(0X66, ctx->r17) = 0;
    // 0x8080032C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80800330: b           L_80800414
    // 0x80800334: sb          $t8, 0x64($s1)
    MEM_B(0X64, ctx->r17) = ctx->r24;
        goto L_80800414;
    // 0x80800334: sb          $t8, 0x64($s1)
    MEM_B(0X64, ctx->r17) = ctx->r24;
L_80800338:
    // 0x80800338: jal         0x80801244
    // 0x8080033C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80801244_chpotogoldgame(rdram, ctx);
        goto after_17;
    // 0x8080033C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x80800340: jal         0x8080206C
    // 0x80800344: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8080206C_chpotogoldgame(rdram, ctx);
        goto after_18;
    // 0x80800344: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_18:
    // 0x80800348: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080034C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80800350: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800354: jal         0x800D2498
    // 0x80800358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_19;
    // 0x80800358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x8080035C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80800360: bne         $s0, $at, L_80800414
    if (ctx->r16 != ctx->r1) {
        // 0x80800364: nop
    
            goto L_80800414;
    }
    // 0x80800364: nop

    // 0x80800368: jal         0x800CEA84
    // 0x8080036C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEA84(rdram, ctx);
        goto after_20;
    // 0x8080036C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x80800370: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800374: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800378: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080037C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800380: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80800384: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800388: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8080038C: jal         0x800D395C
    // 0x80800390: sw          $t0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r8;
    func_800D395C(rdram, ctx);
        goto after_21;
    // 0x80800390: sw          $t0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r8;
    after_21:
    // 0x80800394: beq         $v0, $zero, L_808003B0
    if (ctx->r2 == 0) {
        // 0x80800398: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808003B0;
    }
    // 0x80800398: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080039C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808003A0: jal         0x80800434
    // 0x808003A4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_22;
    // 0x808003A4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_22:
    // 0x808003A8: b           L_808003BC
    // 0x808003AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_808003BC;
    // 0x808003AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_808003B0:
    // 0x808003B0: jal         0x80800434
    // 0x808003B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_23;
    // 0x808003B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_23:
    // 0x808003B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_808003BC:
    // 0x808003BC: jal         0x800CE88C
    // 0x808003C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_24;
    // 0x808003C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x808003C4: b           L_80800414
    // 0x808003C8: nop

        goto L_80800414;
    // 0x808003C8: nop

L_808003CC:
    // 0x808003CC: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x808003D0: jal         0x8010CB84
    // 0x808003D4: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8010CB84(rdram, ctx);
        goto after_25;
    // 0x808003D4: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_25:
    // 0x808003D8: bne         $v0, $zero, L_80800414
    if (ctx->r2 != 0) {
        // 0x808003DC: nop
    
            goto L_80800414;
    }
    // 0x808003DC: nop

    // 0x808003E0: jal         0x800F54E4
    // 0x808003E4: nop

    func_800F54E4(rdram, ctx);
        goto after_26;
    // 0x808003E4: nop

    after_26:
    // 0x808003E8: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x808003EC: ori         $a1, $a1, 0x220
    ctx->r5 = ctx->r5 | 0X220;
    // 0x808003F0: jal         0x800F64A4
    // 0x808003F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F64A4(rdram, ctx);
        goto after_27;
    // 0x808003F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_27:
    // 0x808003F8: bne         $v0, $zero, L_80800414
    if (ctx->r2 != 0) {
        // 0x808003FC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800414;
    }
    // 0x808003FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800400: jal         0x80108B04
    // 0x80800404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_28;
    // 0x80800404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x80800408: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080040C: jal         0x80800434
    // 0x80800410: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_29;
    // 0x80800410: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_29:
L_80800414:
    // 0x80800414: jal         0x80801558
    // 0x80800418: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80801558_chpotogoldgame(rdram, ctx);
        goto after_30;
    // 0x80800418: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_30:
    // 0x8080041C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800420: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800424: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800428: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080042C: jr          $ra
    // 0x80800430: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800430: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800EB800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB800: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EB804: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800EB808: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800EB80C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800EB810: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800EB814: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EB818: addiu       $s1, $s1, 0x2E9C
    ctx->r17 = ADD32(ctx->r17, 0X2E9C);
    // 0x800EB81C: addiu       $s0, $s0, 0x2E80
    ctx->r16 = ADD32(ctx->r16, 0X2E80);
    // 0x800EB820: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800EB824:
    // 0x800EB824: beql        $a0, $zero, L_800EB838
    if (ctx->r4 == 0) {
        // 0x800EB828: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800EB838;
    }
    goto skip_0;
    // 0x800EB828: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800EB82C: jal         0x800B28B8
    // 0x800EB830: nop

    vector_clear(rdram, ctx);
        goto after_0;
    // 0x800EB830: nop

    after_0:
    // 0x800EB834: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800EB838:
    // 0x800EB838: bnel        $s0, $s1, L_800EB824
    if (ctx->r16 != ctx->r17) {
        // 0x800EB83C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800EB824;
    }
    goto skip_1;
    // 0x800EB83C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800EB840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EB844: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800EB848: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800EB84C: jr          $ra
    // 0x800EB850: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800EB850: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8080008C_chbigtopticket(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800090: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800094: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80800098: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080009C: beq         $a1, $at, L_808000F8
    if (ctx->r5 == ctx->r1) {
        // 0x808000A0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_808000F8;
    }
    // 0x808000A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A4: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x808000A8: bne         $a1, $at, L_80800100
    if (ctx->r5 != ctx->r1) {
        // 0x808000AC: addiu       $a0, $zero, 0x19F
        ctx->r4 = ADD32(0, 0X19F);
            goto L_80800100;
    }
    // 0x808000AC: addiu       $a0, $zero, 0x19F
    ctx->r4 = ADD32(0, 0X19F);
    // 0x808000B0: jal         0x8008A298
    // 0x808000B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _sudialog_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808000B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x808000B8: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x808000BC: jal         0x800D0BD4
    // 0x808000C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800D0BD4(rdram, ctx);
        goto after_1;
    // 0x808000C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x808000C4: jal         0x800D1844
    // 0x808000C8: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    func_800D1844(rdram, ctx);
        goto after_2;
    // 0x808000C8: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_2:
    // 0x808000CC: jal         0x800FC6B0
    // 0x808000D0: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    func_800FC6B0(rdram, ctx);
        goto after_3;
    // 0x808000D0: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_3:
    // 0x808000D4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000D8: jal         0x800888C8
    // 0x808000DC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808000DC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_4:
    // 0x808000E0: jal         0x8010A570
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000E8: jal         0x800FFAB0
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000F0: b           L_8080010C
    // 0x808000F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080010C;
    // 0x808000F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000F8:
    // 0x808000F8: b           L_80800108
    // 0x808000FC: sw          $a2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r6;
        goto L_80800108;
    // 0x808000FC: sw          $a2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r6;
L_80800100:
    // 0x80800100: b           L_8080010C
    // 0x80800104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080010C;
    // 0x80800104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800108:
    // 0x80800108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080010C:
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800114: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void func_8080065C_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080065C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800660: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800664: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800668: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080066C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800670: jal         0x80095738
    // 0x80800674: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x80800674: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80800678: beq         $v0, $zero, L_80800690
    if (ctx->r2 == 0) {
        // 0x8080067C: nop
    
            goto L_80800690;
    }
    // 0x8080067C: nop

    // 0x80800680: jal         0x8009B7C0
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_1;
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800688: b           L_8080069C
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080069C;
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800690:
    // 0x80800690: jal         0x80800E64
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsmum_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080069C:
    // 0x8080069C: jal         0x8009BB24
    // 0x808006A0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009BB24(rdram, ctx);
        goto after_3;
    // 0x808006A0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x808006A4: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808006A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: beq         $v0, $zero, L_808006C8
    if (ctx->r2 == 0) {
        // 0x808006B4: nop
    
            goto L_808006C8;
    }
    // 0x808006B4: nop

    // 0x808006B8: beql        $v0, $at, L_808006E0
    if (ctx->r2 == ctx->r1) {
        // 0x808006BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006E0;
    }
    goto skip_0;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808006C0: b           L_808006E0
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006E0;
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006C8:
    // 0x808006C8: jal         0x8008DF8C
    // 0x808006CC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_4;
    // 0x808006CC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_4:
    // 0x808006D0: beq         $v0, $zero, L_808006DC
    if (ctx->r2 == 0) {
        // 0x808006D4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808006DC;
    }
    // 0x808006D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808006D8: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_808006DC:
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006E0:
    // 0x808006E0: jal         0x80095748
    // 0x808006E4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isFalse(rdram, ctx);
        goto after_5;
    // 0x808006E4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_5:
    // 0x808006E8: beq         $v0, $zero, L_8080071C
    if (ctx->r2 == 0) {
        // 0x808006EC: nop
    
            goto L_8080071C;
    }
    // 0x808006EC: nop

    // 0x808006F0: jal         0x8008E260
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_6;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808006F8: beq         $v0, $zero, L_80800704
    if (ctx->r2 == 0) {
        // 0x808006FC: addiu       $t7, $zero, 0xEE
        ctx->r15 = ADD32(0, 0XEE);
            goto L_80800704;
    }
    // 0x808006FC: addiu       $t7, $zero, 0xEE
    ctx->r15 = ADD32(0, 0XEE);
    // 0x80800700: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80800704:
    // 0x80800704: jal         0x8008E35C
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_7;
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080070C: beq         $v0, $zero, L_80800734
    if (ctx->r2 == 0) {
        // 0x80800710: addiu       $t8, $zero, 0xF4
        ctx->r24 = ADD32(0, 0XF4);
            goto L_80800734;
    }
    // 0x80800710: addiu       $t8, $zero, 0xF4
    ctx->r24 = ADD32(0, 0XF4);
    // 0x80800714: b           L_80800734
    // 0x80800718: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_80800734;
    // 0x80800718: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8080071C:
    // 0x8080071C: jal         0x8008E35C
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_8;
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800724: beq         $v0, $zero, L_80800734
    if (ctx->r2 == 0) {
        // 0x80800728: nop
    
            goto L_80800734;
    }
    // 0x80800728: nop

    // 0x8080072C: jal         0x800A046C
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A046C(rdram, ctx);
        goto after_9;
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800734:
    // 0x80800734: jal         0x8008E078
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_10;
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080073C: beql        $v0, $zero, L_80800770
    if (ctx->r2 == 0) {
        // 0x80800740: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800770;
    }
    goto skip_1;
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800744: jal         0x8009FE58
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_11;
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080074C: lui         $a3, 0x3F26
    ctx->r7 = S32(0X3F26 << 16);
    // 0x80800750: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: addiu       $a1, $zero, 0xBD
    ctx->r5 = ADD32(0, 0XBD);
    // 0x8080075C: jal         0x8008CD30
    // 0x80800760: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    baanim_playForDuration_onceSmoothStartingAt(rdram, ctx);
        goto after_12;
    // 0x80800760: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_12:
    // 0x80800764: addiu       $t9, $zero, 0xEF
    ctx->r25 = ADD32(0, 0XEF);
    // 0x80800768: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800770:
    // 0x80800770: jal         0x8009E5C8
    // 0x80800774: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x80800774: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_13:
    // 0x80800778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080077C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800780: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800784: jr          $ra
    // 0x80800788: nop

    return;
    // 0x80800788: nop

;}
RECOMP_FUNC void func_800C9D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9D64: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C9D68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9D6C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C9D70: jal         0x800C9DE4
    // 0x800C9D74: addiu       $a1, $a1, 0x54F8
    ctx->r5 = ADD32(ctx->r5, 0X54F8);
    func_800C9DE4(rdram, ctx);
        goto after_0;
    // 0x800C9D74: addiu       $a1, $a1, 0x54F8
    ctx->r5 = ADD32(ctx->r5, 0X54F8);
    after_0:
    // 0x800C9D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9D7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9D80: jr          $ra
    // 0x800C9D84: nop

    return;
    // 0x800C9D84: nop

;}
RECOMP_FUNC void func_808002B8_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002C4: jal         0x8009EF1C
    // 0x808002C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x808002C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: jal         0x8009EF10
    // 0x808002D4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x808002D4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x808002D8: beq         $v0, $zero, L_808002FC
    if (ctx->r2 == 0) {
        // 0x808002DC: lwc1        $f12, 0x24($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
            goto L_808002FC;
    }
    // 0x808002DC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808002E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002E4: beq         $v0, $at, L_80800310
    if (ctx->r2 == ctx->r1) {
        // 0x808002E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800310;
    }
    // 0x808002E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002EC: beql        $v0, $at, L_80800338
    if (ctx->r2 == ctx->r1) {
        // 0x808002F0: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_80800338;
    }
    goto skip_0;
    // 0x808002F0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    skip_0:
    // 0x808002F4: b           L_80800354
    // 0x808002F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800354;
    // 0x808002F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002FC:
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: jal         0x8009B9B0
    // 0x80800304: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800304: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800308: b           L_80800354
    // 0x8080030C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800354;
    // 0x8080030C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800310:
    // 0x80800310: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800314: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800318: jal         0x800F1214
    // 0x8080031C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x8080031C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_3:
    // 0x80800320: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800324: jal         0x8009B9B0
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080032C: b           L_80800354
    // 0x80800330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800354;
    // 0x80800330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800334: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
L_80800338:
    // 0x80800338: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080033C: jal         0x800F1214
    // 0x80800340: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    func_800F1214(rdram, ctx);
        goto after_5;
    // 0x80800340: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    after_5:
    // 0x80800344: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800348: jal         0x8009B9B0
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800354:
    // 0x80800354: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800358: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080035C: jr          $ra
    // 0x80800360: nop

    return;
    // 0x80800360: nop

;}
RECOMP_FUNC void func_808002F8_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800300: jal         0x800DA524
    // 0x80800304: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x80800304: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_0:
    // 0x80800308: jal         0x800DA524
    // 0x8080030C: addiu       $a0, $zero, 0x426
    ctx->r4 = ADD32(0, 0X426);
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x8080030C: addiu       $a0, $zero, 0x426
    ctx->r4 = ADD32(0, 0X426);
    after_1:
    // 0x80800310: jal         0x800DA524
    // 0x80800314: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x80800314: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_2:
    // 0x80800318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080031C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800320: jr          $ra
    // 0x80800324: nop

    return;
    // 0x80800324: nop

;}
