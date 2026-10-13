#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bskazshoessuckspline_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080039C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808003A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808003A4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808003A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808003AC: jal         0x80095738
    // 0x808003B0: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x808003B0: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_0:
    // 0x808003B4: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x808003B8: nop
    
            goto L_808003F0;
    }
    // 0x808003B8: nop

    // 0x808003BC: jal         0x80084FE0
    // 0x808003C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808003C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808003C4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003C8: bne         $v0, $at, L_808003F0
    if (ctx->r2 != ctx->r1) {
        // 0x808003CC: nop
    
            goto L_808003F0;
    }
    // 0x808003CC: nop

    // 0x808003D0: jal         0x800850A0
    // 0x808003D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bashoessuck_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808003D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808003D8: jal         0x8009EF10
    // 0x808003DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getZone(rdram, ctx);
        goto after_3;
    // 0x808003DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x808003E0: blezl       $v0, L_8080040C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808003E4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080040C;
    }
    goto skip_0;
    // 0x808003E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x808003E8: b           L_80800408
    // 0x808003EC: addiu       $s0, $zero, 0x188
    ctx->r16 = ADD32(0, 0X188);
        goto L_80800408;
    // 0x808003EC: addiu       $s0, $zero, 0x188
    ctx->r16 = ADD32(0, 0X188);
L_808003F0:
    // 0x808003F0: jal         0x8008DD04
    // 0x808003F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008DD04(rdram, ctx);
        goto after_4;
    // 0x808003F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x808003F8: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x808003FC: addiu       $s0, $zero, 0xBB
        ctx->r16 = ADD32(0, 0XBB);
            goto L_80800408;
    }
    // 0x808003FC: addiu       $s0, $zero, 0xBB
    ctx->r16 = ADD32(0, 0XBB);
    // 0x80800400: b           L_80800408
    // 0x80800404: addiu       $s0, $zero, 0xDF
    ctx->r16 = ADD32(0, 0XDF);
        goto L_80800408;
    // 0x80800404: addiu       $s0, $zero, 0xDF
    ctx->r16 = ADD32(0, 0XDF);
L_80800408:
    // 0x80800408: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8080040C:
    // 0x8080040C: jal         0x8009E5C8
    // 0x80800410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x80800410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800418: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080041C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800420: jr          $ra
    // 0x80800424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D38: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D38);
    return;
    // 0x80087D3C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_800BD97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD97C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BD980: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800BD984: lwc1        $f0, -0x7BB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7BB0);
    // 0x800BD988: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800BD98C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BD990: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800BD994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD998: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800BD99C: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
L_800BD9A0:
    // 0x800BD9A0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800BD9A4: bltzl       $v1, L_800BD9D0
    if (SIGNED(ctx->r3) < 0) {
        // 0x800BD9A8: mtc1        $v1, $f16
        ctx->f16.u32l = ctx->r3;
            goto L_800BD9D0;
    }
    goto skip_0;
    // 0x800BD9A8: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    skip_0:
    // 0x800BD9AC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800BD9B0: nop

    // 0x800BD9B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BD9B8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800BD9BC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BD9C0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800BD9C4: b           L_800BD9F0
    // 0x800BD9C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_800BD9F0;
    // 0x800BD9C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800BD9CC: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
L_800BD9D0:
    // 0x800BD9D0: nop

    // 0x800BD9D4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BD9D8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BD9DC: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800BD9E0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800BD9E4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800BD9E8: nop

    // 0x800BD9EC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_800BD9F0:
    // 0x800BD9F0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BD9F4: bne         $v0, $a0, L_800BD9A0
    if (ctx->r2 != ctx->r4) {
        // 0x800BD9F8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800BD9A0;
    }
    // 0x800BD9F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800BD9FC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BDA00: addiu       $v1, $v1, -0x7BF0
    ctx->r3 = ADD32(ctx->r3, -0X7BF0);
    // 0x800BDA04: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800BDA08: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x800BDA0C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800BDA10: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BDA14: bne         $at, $zero, L_800BDA78
    if (ctx->r1 != 0) {
        // 0x800BDA18: nop
    
            goto L_800BDA78;
    }
    // 0x800BDA18: nop

    // 0x800BDA1C: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800BDA20: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800BDA24: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800BDA28: bne         $at, $zero, L_800BDA78
    if (ctx->r1 != 0) {
        // 0x800BDA2C: nop
    
            goto L_800BDA78;
    }
    // 0x800BDA2C: nop

    // 0x800BDA30: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x800BDA34: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BDA38: bne         $at, $zero, L_800BDA78
    if (ctx->r1 != 0) {
        // 0x800BDA3C: nop
    
            goto L_800BDA78;
    }
    // 0x800BDA3C: nop

    // 0x800BDA40: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    // 0x800BDA44: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BDA48: bne         $at, $zero, L_800BDA78
    if (ctx->r1 != 0) {
        // 0x800BDA4C: nop
    
            goto L_800BDA78;
    }
    // 0x800BDA4C: nop

    // 0x800BDA50: lw          $t4, 0x14($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X14);
    // 0x800BDA54: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BDA58: bne         $at, $zero, L_800BDA78
    if (ctx->r1 != 0) {
        // 0x800BDA5C: nop
    
            goto L_800BDA78;
    }
    // 0x800BDA5C: nop

    // 0x800BDA60: lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X18);
    // 0x800BDA64: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800BDA68: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BDA6C: slt         $at, $t5, $a1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800BDA70: beq         $at, $zero, L_800BDA80
    if (ctx->r1 == 0) {
        // 0x800BDA74: addiu       $a1, $sp, 0x3C
        ctx->r5 = ADD32(ctx->r29, 0X3C);
            goto L_800BDA80;
    }
    // 0x800BDA74: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
L_800BDA78:
    // 0x800BDA78: b           L_800BDAC4
    // 0x800BDA7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BDAC4;
    // 0x800BDA7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BDA80:
    // 0x800BDA80: jal         0x800EFB58
    // 0x800BDA84: addiu       $a2, $a2, -0x7BEC
    ctx->r6 = ADD32(ctx->r6, -0X7BEC);
    func_800EFB58(rdram, ctx);
        goto after_0;
    // 0x800BDA84: addiu       $a2, $a2, -0x7BEC
    ctx->r6 = ADD32(ctx->r6, -0X7BEC);
    after_0:
    // 0x800BDA88: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BDA8C: addiu       $v1, $v1, -0x7BF0
    ctx->r3 = ADD32(ctx->r3, -0X7BF0);
    // 0x800BDA90: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    // 0x800BDA94: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800BDA98: lw          $t2, 0x1C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X1C);
    // 0x800BDA9C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800BDAA0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDAA4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800BDAA8: mflo        $t8
    ctx->r24 = lo;
    // 0x800BDAAC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800BDAB0: nop

    // 0x800BDAB4: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDAB8: mflo        $t3
    ctx->r11 = lo;
    // 0x800BDABC: addu        $v0, $t0, $t3
    ctx->r2 = ADD32(ctx->r8, ctx->r11);
    // 0x800BDAC0: nop

L_800BDAC4:
    // 0x800BDAC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDAC8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800BDACC: jr          $ra
    // 0x800BDAD0: nop

    return;
    // 0x800BDAD0: nop

;}
RECOMP_FUNC void sccustom_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080074C: jal         0x808004C8
    // 0x80800750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808004C8_sccustom(rdram, ctx);
        goto after_0;
    // 0x80800750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800754: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800758: jal         0x808006C4
    // 0x8080075C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808006C4_sccustom(rdram, ctx);
        goto after_1;
    // 0x8080075C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800768: jr          $ra
    // 0x8080076C: nop

    return;
    // 0x8080076C: nop

;}
RECOMP_FUNC void _chfactorymagnet_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874D0: syscall     579
    recomp_syscall_handler(rdram, ctx, 0x800874D0);
    return;
    // 0x800874D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chwandglow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087300: syscall     549
    recomp_syscall_handler(rdram, ctx, 0x80087300);
    return;
    // 0x80087304: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _subaddieaudioloop_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D48: syscall     810
    recomp_syscall_handler(rdram, ctx, 0x80089D48);
    return;
    // 0x80089D4C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80101DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101DAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101DB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101DB4: jal         0x80104248
    // 0x80101DB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80101DB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80101DBC: beq         $v0, $zero, L_80101DCC
    if (ctx->r2 == 0) {
        // 0x80101DC0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101DCC;
    }
    // 0x80101DC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101DC4: jal         0x8008B4A8
    // 0x80101DC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8008B4A8(rdram, ctx);
        goto after_1;
    // 0x80101DC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80101DCC:
    // 0x80101DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101DD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101DD4: jr          $ra
    // 0x80101DD8: nop

    return;
    // 0x80101DD8: nop

;}
RECOMP_FUNC void func_80015D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015D14: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x80015D18: lh          $t7, 0xA($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XA);
    // 0x80015D1C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80015D20: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80015D24: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80015D28: lh          $t8, -0x6648($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6648);
    // 0x80015D2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015D30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80015D34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80015D38: beq         $t8, $zero, L_80015D4C
    if (ctx->r24 == 0) {
        // 0x80015D3C: div.s       $f2, $f6, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
            goto L_80015D4C;
    }
    // 0x80015D3C: div.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80015D40: lwc1        $f16, 0x1710($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1710);
    // 0x80015D44: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80015D48: nop

L_80015D4C:
    // 0x80015D4C: jr          $ra
    // 0x80015D50: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80015D50: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80015D54: nop

    // 0x80015D58: nop

    // 0x80015D5C: nop

;}
RECOMP_FUNC void func_80015860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015860: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80015864: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80015868: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8001586C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80015870: jr          $ra
    // 0x80015874: sh          $t6, -0x6888($at)
    MEM_H(-0X6888, ctx->r1) = ctx->r14;
    return;
    // 0x80015874: sh          $t6, -0x6888($at)
    MEM_H(-0X6888, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80093700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093700: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093704: jr          $ra
    // 0x80093708: sb          $a1, 0x19($t6)
    MEM_B(0X19, ctx->r14) = ctx->r5;
    return;
    // 0x80093708: sb          $a1, 0x19($t6)
    MEM_B(0X19, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _idbounce_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CC8: syscall     733
    recomp_syscall_handler(rdram, ctx, 0x80088CC8);
    return;
    // 0x80088CCC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void suquiz_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x808007EC: lw          $a1, 0x7614($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7614);
    // 0x808007F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007F8: jal         0x800EE7F8
    // 0x808007FC: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808007FC: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x80800800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800808: jr          $ra
    // 0x8080080C: nop

    return;
    // 0x8080080C: nop

;}
RECOMP_FUNC void func_800A2D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A2D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2D78: lw          $t6, 0x124($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X124);
    // 0x800A2D7C: jal         0x800889E0
    // 0x800A2D80: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _fxstep_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800A2D80: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800A2D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A2D8C: jr          $ra
    // 0x800A2D90: nop

    return;
    // 0x800A2D90: nop

;}
RECOMP_FUNC void _subaddiefind_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C78: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C78);
    return;
    // 0x80089C7C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_800E9438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9438: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E943C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800E9440: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800E9444: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E9448: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E944C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800E9450: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800E9454: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800E9458: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E945C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800E9460: jal         0x8001ACCC
    // 0x800E9464: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800E9464: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_0:
    // 0x800E9468: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E946C: addiu       $s5, $s5, -0x2970
    ctx->r21 = ADD32(ctx->r21, -0X2970);
    // 0x800E9470: lh          $t6, 0x4650($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X4650);
    // 0x800E9474: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800E9478: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800E947C: blez        $t6, L_800E94B8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800E9480: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_800E94B8;
    }
    // 0x800E9480: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800E9484: addiu       $s2, $s2, 0x2560
    ctx->r18 = ADD32(ctx->r18, 0X2560);
L_800E9488:
    // 0x800E9488: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E948C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E9490: jal         0x800E9340
    // 0x800E9494: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800E9340(rdram, ctx);
        goto after_1;
    // 0x800E9494: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_1:
    // 0x800E9498: lh          $t8, 0x4650($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X4650);
    // 0x800E949C: sh          $s1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r17;
    // 0x800E94A0: lh          $t7, 0xE($s3)
    ctx->r15 = MEM_H(ctx->r19, 0XE);
    // 0x800E94A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800E94A8: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800E94AC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800E94B0: bne         $at, $zero, L_800E9488
    if (ctx->r1 != 0) {
        // 0x800E94B4: addu        $s1, $s1, $t7
        ctx->r17 = ADD32(ctx->r17, ctx->r15);
            goto L_800E9488;
    }
    // 0x800E94B4: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
L_800E94B8:
    // 0x800E94B8: jal         0x8001B084
    // 0x800E94BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    heap_free(rdram, ctx);
        goto after_2;
    // 0x800E94BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x800E94C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800E94C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E94C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E94CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800E94D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800E94D4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800E94D8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800E94DC: jr          $ra
    // 0x800E94E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800E94E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800A0E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0E64: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800A0E68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A0E6C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800A0E70: jal         0x80096544
    // 0x800A0E74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80096544(rdram, ctx);
        goto after_0;
    // 0x800A0E74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800A0E78: beq         $v0, $zero, L_800A0FB8
    if (ctx->r2 == 0) {
        // 0x800A0E7C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800A0FB8;
    }
    // 0x800A0E7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0E80: lwc1        $f12, 0x5490($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5490);
    // 0x800A0E84: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x800A0E88: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A0E8C: jal         0x800DC178
    // 0x800A0E90: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x800A0E90: nop

    after_1:
    // 0x800A0E94: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800A0E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0E9C: jal         0x8009DBF0
    // 0x800A0EA0: addiu       $a1, $zero, 0x409
    ctx->r5 = ADD32(0, 0X409);
    func_8009DBF0(rdram, ctx);
        goto after_2;
    // 0x800A0EA0: addiu       $a1, $zero, 0x409
    ctx->r5 = ADD32(0, 0X409);
    after_2:
    // 0x800A0EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0EA8: jal         0x8009C128
    // 0x800A0EAC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x800A0EAC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x800A0EB0: jal         0x800964DC
    // 0x800A0EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800964DC(rdram, ctx);
        goto after_4;
    // 0x800A0EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800A0EB8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800A0EBC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800A0EC0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800A0EC4: jal         0x80088AE8
    // 0x800A0EC8: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    _fxsplash_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x800A0EC8: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    after_5:
    // 0x800A0ECC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A0ED0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800A0ED4: jal         0x800889A0
    // 0x800A0ED8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _fxripple_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x800A0ED8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x800A0EDC: addiu       $t6, $zero, 0x15E
    ctx->r14 = ADD32(0, 0X15E);
    // 0x800A0EE0: addiu       $t7, $zero, 0x1F4
    ctx->r15 = ADD32(0, 0X1F4);
    // 0x800A0EE4: addiu       $t8, $zero, 0x15E
    ctx->r24 = ADD32(0, 0X15E);
    // 0x800A0EE8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800A0EEC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A0EF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A0EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0EF8: addiu       $a1, $zero, -0x15E
    ctx->r5 = ADD32(0, -0X15E);
    // 0x800A0EFC: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x800A0F00: jal         0x800BA930
    // 0x800A0F04: addiu       $a3, $zero, -0x15E
    ctx->r7 = ADD32(0, -0X15E);
    func_800BA930(rdram, ctx);
        goto after_7;
    // 0x800A0F04: addiu       $a3, $zero, -0x15E
    ctx->r7 = ADD32(0, -0X15E);
    after_7:
    // 0x800A0F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0F0C: jal         0x800BA22C
    // 0x800A0F10: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800BA22C(rdram, ctx);
        goto after_8;
    // 0x800A0F10: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_8:
    // 0x800A0F14: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x800A0F18: addiu       $t0, $zero, 0x320
    ctx->r8 = ADD32(0, 0X320);
    // 0x800A0F1C: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
    // 0x800A0F20: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800A0F24: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800A0F28: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800A0F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0F30: addiu       $a1, $zero, -0x96
    ctx->r5 = ADD32(0, -0X96);
    // 0x800A0F34: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x800A0F38: jal         0x800BA930
    // 0x800A0F3C: addiu       $a3, $zero, -0x96
    ctx->r7 = ADD32(0, -0X96);
    func_800BA930(rdram, ctx);
        goto after_9;
    // 0x800A0F3C: addiu       $a3, $zero, -0x96
    ctx->r7 = ADD32(0, -0X96);
    after_9:
    // 0x800A0F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0F44: jal         0x800BA22C
    // 0x800A0F48: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800BA22C(rdram, ctx);
        goto after_10;
    // 0x800A0F48: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_10:
    // 0x800A0F4C: jal         0x800889D8
    // 0x800A0F50: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    _fxsplash25d_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x800A0F50: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_11:
    // 0x800A0F54: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800A0F58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A0F5C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A0F60: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800A0F64: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x800A0F68: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A0F6C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800A0F70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800A0F74: jal         0x800889D0
    // 0x800A0F78: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    _fxairbub_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x800A0F78: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x800A0F7C: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x800A0F80: addiu       $t3, $zero, -0x96
    ctx->r11 = ADD32(0, -0X96);
    // 0x800A0F84: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x800A0F88: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A0F8C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A0F90: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A0F94: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A0F98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A0F9C: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x800A0FA0: addiu       $a2, $zero, -0xFA
    ctx->r6 = ADD32(0, -0XFA);
    // 0x800A0FA4: jal         0x800BA930
    // 0x800A0FA8: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    func_800BA930(rdram, ctx);
        goto after_13;
    // 0x800A0FA8: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    after_13:
    // 0x800A0FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0FB0: jal         0x800BA22C
    // 0x800A0FB4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800BA22C(rdram, ctx);
        goto after_14;
    // 0x800A0FB4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_14:
L_800A0FB8:
    // 0x800A0FB8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0FBC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800A0FC0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800A0FC4: jr          $ra
    // 0x800A0FC8: nop

    return;
    // 0x800A0FC8: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C50: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C50);
    return;
    // 0x80082C54: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_808008E4_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008EC: jal         0x80800114
    // 0x808008F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800114_bsvanswim(rdram, ctx);
        goto after_0;
    // 0x808008F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008F4: jal         0x80082FE0
    // 0x808008F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808008F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808008FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800904: jr          $ra
    // 0x80800908: nop

    return;
    // 0x80800908: nop

;}
RECOMP_FUNC void _sufade_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A900: syscall     855
    recomp_syscall_handler(rdram, ctx, 0x8008A900);
    return;
    // 0x8008A904: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _suquiz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7D8: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A7D8);
    return;
    // 0x8008A7DC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800324_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800324: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800328: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080032C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800330: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800334: jal         0x80100094
    // 0x80800338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080033C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: jal         0x80100094
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080034C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800350: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800354: jal         0x800897D8
    // 0x80800358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8080035C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800360: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800364: jal         0x8008A0E8
    // 0x80800368: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800368: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_3:
    // 0x8080036C: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80800370: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800374: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800378: jal         0x8008A0E8
    // 0x8080037C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x8080037C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    after_4:
    // 0x80800380: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80800384: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800388: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8080038C: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x80800390: jal         0x8008A0E8
    // 0x80800394: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800394: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_5:
    // 0x80800398: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8080039C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808003A0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808003A4: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    // 0x808003A8: jal         0x8008A0E8
    // 0x808003AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808003AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_6:
    // 0x808003B0: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x808003B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808003B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808003BC: jal         0x8008A0E8
    // 0x808003C0: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808003C0: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    after_7:
    // 0x808003C4: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x808003C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808003CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x808003D0: jal         0x8008A0E8
    // 0x808003D4: addiu       $a2, $a2, 0x24
    ctx->r6 = ADD32(ctx->r6, 0X24);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808003D4: addiu       $a2, $a2, 0x24
    ctx->r6 = ADD32(ctx->r6, 0X24);
    after_8:
    // 0x808003D8: jal         0x808012C8
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808012C8_chboilerboss(rdram, ctx);
        goto after_9;
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003E0: jal         0x80801628
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801628_chboilerboss(rdram, ctx);
        goto after_10;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808003E8: jal         0x80802114
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802114_chboilerboss(rdram, ctx);
        goto after_11;
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808003F0: jal         0x808023C8
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808023C8_chboilerboss(rdram, ctx);
        goto after_12;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808003F8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808003FC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800400: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800404: sltiu       $at, $t8, 0xD
    ctx->r1 = ctx->r24 < 0XD ? 1 : 0;
    // 0x80800408: beq         $at, $zero, L_80800894
    if (ctx->r1 == 0) {
        // 0x8080040C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800894;
    }
    // 0x8080040C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800410: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2890) << 16);
    // 0x80800414: addu        $at, $at, $t8
    gpr jr_addend_8080041C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800418: lw          $t8, 0x2890($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(932, 0X2890));
    // 0x8080041C: jr          $t8
    // 0x80800420: nop

    switch (jr_addend_8080041C >> 2) {
        case 0: goto L_80800894; break;
        case 1: goto L_80800424; break;
        case 2: goto L_80800454; break;
        case 3: goto L_80800894; break;
        case 4: goto L_8080049C; break;
        case 5: goto L_808004BC; break;
        case 6: goto L_80800624; break;
        case 7: goto L_808006D4; break;
        case 8: goto L_80800784; break;
        case 9: goto L_80800534; break;
        case 10: goto L_80800844; break;
        case 11: goto L_80800894; break;
        case 12: goto L_80800894; break;
        default: switch_error(__func__, 0x8080041C, 0x80802890);
    }
    // 0x80800420: nop

L_80800424:
    // 0x80800424: jal         0x808017F0
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017F0_chboilerboss(rdram, ctx);
        goto after_13;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080042C: jal         0x80101DDC
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_14;
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800434: beq         $v0, $zero, L_80800444
    if (ctx->r2 == 0) {
        // 0x80800438: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800444;
    }
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080043C: jal         0x80800F34
    // 0x80800440: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_15;
    // 0x80800440: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
L_80800444:
    // 0x80800444: jal         0x80801C24
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C24_chboilerboss(rdram, ctx);
        goto after_16;
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080044C: b           L_80800894
    // 0x80800450: nop

        goto L_80800894;
    // 0x80800450: nop

L_80800454:
    // 0x80800454: jal         0x80101DDC
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_17;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080045C: beq         $v0, $zero, L_80800894
    if (ctx->r2 == 0) {
        // 0x80800460: nop
    
            goto L_80800894;
    }
    // 0x80800460: nop

    // 0x80800464: jal         0x800F54E4
    // 0x80800468: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x80800468: nop

    after_18:
    // 0x8080046C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800470: jal         0x800F82D4
    // 0x80800474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_19;
    // 0x80800474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: addiu       $a1, $zero, 0xF97
    ctx->r5 = ADD32(0, 0XF97);
    // 0x80800480: jal         0x8080238C
    // 0x80800484: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_8080238C_chboilerboss(rdram, ctx);
        goto after_20;
    // 0x80800484: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_20:
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: jal         0x80800F34
    // 0x80800490: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_21;
    // 0x80800490: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_21:
    // 0x80800494: b           L_80800894
    // 0x80800498: nop

        goto L_80800894;
    // 0x80800498: nop

L_8080049C:
    // 0x8080049C: jal         0x80105834
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_22;
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808004A4: jal         0x808013C4
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808013C4_chboilerboss(rdram, ctx);
        goto after_23;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808004AC: jal         0x80801CE8
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CE8_chboilerboss(rdram, ctx);
        goto after_24;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808004B4: b           L_80800894
    // 0x808004B8: nop

        goto L_80800894;
    // 0x808004B8: nop

L_808004BC:
    // 0x808004BC: jal         0x80105834
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_25;
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808004C4: jal         0x80801CE8
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CE8_chboilerboss(rdram, ctx);
        goto after_26;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808004CC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808004D0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808004D4: jal         0x80101E14
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_27;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808004DC: beq         $v0, $zero, L_80800514
    if (ctx->r2 == 0) {
        // 0x808004E0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800514;
    }
    // 0x808004E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808004E8: jal         0x800DC298
    // 0x808004EC: nop

    func_800DC298(rdram, ctx);
        goto after_28;
    // 0x808004EC: nop

    after_28:
    // 0x808004F0: beq         $v0, $zero, L_80800504
    if (ctx->r2 == 0) {
        // 0x808004F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800504;
    }
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B34) << 16);
    // 0x808004FC: b           L_8080050C
    // 0x80800500: addiu       $a2, $a2, 0x2B34
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B34));
        goto L_8080050C;
    // 0x80800500: addiu       $a2, $a2, 0x2B34
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B34));
L_80800504:
    // 0x80800504: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B40) << 16);
    // 0x80800508: addiu       $a2, $a2, 0x2B40
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B40));
L_8080050C:
    // 0x8080050C: jal         0x80089D18
    // 0x80800510: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_29;
    // 0x80800510: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_29:
L_80800514:
    // 0x80800514: jal         0x80101DDC
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_30;
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8080051C: beq         $v0, $zero, L_80800894
    if (ctx->r2 == 0) {
        // 0x80800520: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800894;
    }
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: jal         0x80800F34
    // 0x80800528: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_31;
    // 0x80800528: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_31:
    // 0x8080052C: b           L_80800894
    // 0x80800530: nop

        goto L_80800894;
    // 0x80800530: nop

L_80800534:
    // 0x80800534: jal         0x80101DDC
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_32;
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x8080053C: beq         $v0, $zero, L_8080054C
    if (ctx->r2 == 0) {
        // 0x80800540: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080054C;
    }
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: jal         0x80800F34
    // 0x80800548: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_33;
    // 0x80800548: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_33:
L_8080054C:
    // 0x8080054C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800550: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800554: jal         0x80101E14
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_34;
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8080055C: beq         $v0, $zero, L_80800600
    if (ctx->r2 == 0) {
        // 0x80800560: nop
    
            goto L_80800600;
    }
    // 0x80800560: nop

    // 0x80800564: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800568: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080056C: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x80800570: sll         $t0, $v0, 20
    ctx->r8 = S32(ctx->r2 << 20);
    // 0x80800574: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x80800578: sll         $t3, $v0, 19
    ctx->r11 = S32(ctx->r2 << 19);
    // 0x8080057C: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x80800580: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80800584: sll         $t6, $v0, 18
    ctx->r14 = S32(ctx->r2 << 18);
    // 0x80800588: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8080058C: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x80800590: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x80800594: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80800598: jal         0x800CEAD0
    // 0x8080059C: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    func_800CEAD0(rdram, ctx);
        goto after_35;
    // 0x8080059C: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    after_35:
    // 0x808005A0: beq         $v0, $zero, L_808005CC
    if (ctx->r2 == 0) {
        // 0x808005A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005CC;
    }
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: jal         0x800DA544
    // 0x808005AC: addiu       $a0, $zero, 0x670
    ctx->r4 = ADD32(0, 0X670);
    func_800DA544(rdram, ctx);
        goto after_36;
    // 0x808005AC: addiu       $a0, $zero, 0x670
    ctx->r4 = ADD32(0, 0X670);
    after_36:
    // 0x808005B0: lui         $a2, 0x5015
    ctx->r6 = S32(0X5015 << 16);
    // 0x808005B4: ori         $a2, $a2, 0x2F9
    ctx->r6 = ctx->r6 | 0X2F9;
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005BC: jal         0x8080221C
    // 0x808005C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080221C_chboilerboss(rdram, ctx);
        goto after_37;
    // 0x808005C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x808005C4: b           L_808005DC
    // 0x808005C8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
        goto L_808005DC;
    // 0x808005C8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
L_808005CC:
    // 0x808005CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005D0: jal         0x8080221C
    // 0x808005D4: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    func_8080221C_chboilerboss(rdram, ctx);
        goto after_38;
    // 0x808005D4: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_38:
    // 0x808005D8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
L_808005DC:
    // 0x808005DC: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(932, 0X2B5C) << 16);
    // 0x808005E0: addiu       $t3, $t3, 0x2B5C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(932, 0X2B5C));
    // 0x808005E4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x808005E8: addu        $v0, $t1, $t3
    ctx->r2 = ADD32(ctx->r9, ctx->r11);
    // 0x808005EC: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808005F0: jal         0x800DC178
    // 0x808005F4: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    func_800DC178(rdram, ctx);
        goto after_39;
    // 0x808005F4: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    after_39:
    // 0x808005F8: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x808005FC: swc1        $f0, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f0.u32l;
L_80800600:
    // 0x80800600: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2D2C) << 16);
    // 0x80800604: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80800608: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080060C: addiu       $a2, $a2, 0x2D2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2D2C));
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: jal         0x80089D20
    // 0x80800618: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_40;
    // 0x80800618: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_40:
    // 0x8080061C: b           L_80800894
    // 0x80800620: nop

        goto L_80800894;
    // 0x80800620: nop

L_80800624:
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800628: jal         0x80100094
    // 0x8080062C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_41;
    // 0x8080062C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_41:
    // 0x80800630: jal         0x800897D0
    // 0x80800634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suexpression_entrypoint_9(rdram, ctx);
        goto after_42;
    // 0x80800634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_42:
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080063C: jal         0x80101E14
    // 0x80800640: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_43;
    // 0x80800640: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_43:
    // 0x80800644: beq         $v0, $zero, L_80800698
    if (ctx->r2 == 0) {
        // 0x80800648: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800698;
    }
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800650: jal         0x80801464
    // 0x80800654: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_80801464_chboilerboss(rdram, ctx);
        goto after_44;
    // 0x80800654: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_44:
    // 0x80800658: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(932, 0X2AB0) << 16);
    // 0x8080065C: addiu       $t4, $t4, 0x2AB0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(932, 0X2AB0));
    // 0x80800660: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800664: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800668: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8080066C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800670: jal         0x800BBCB8
    // 0x80800674: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_800BBCB8(rdram, ctx);
        goto after_45;
    // 0x80800674: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_45:
    // 0x80800678: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B14) << 16);
    // 0x8080067C: addiu       $a2, $a2, 0x2B14
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B14));
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: jal         0x80089D18
    // 0x80800688: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_46;
    // 0x80800688: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_46:
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: jal         0x80108B04
    // 0x80800694: addiu       $a1, $zero, 0x223
    ctx->r5 = ADD32(0, 0X223);
    func_80108B04(rdram, ctx);
        goto after_47;
    // 0x80800694: addiu       $a1, $zero, 0x223
    ctx->r5 = ADD32(0, 0X223);
    after_47:
L_80800698:
    // 0x80800698: jal         0x80101DDC
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_48;
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x808006A0: beq         $v0, $zero, L_808006B0
    if (ctx->r2 == 0) {
        // 0x808006A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006B0;
    }
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: jal         0x80800F34
    // 0x808006AC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_49;
    // 0x808006AC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_49:
L_808006B0:
    // 0x808006B0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B08) << 16);
    // 0x808006B4: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x808006B8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808006BC: addiu       $a2, $a2, 0x2B08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B08));
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C4: jal         0x80089D20
    // 0x808006C8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_50;
    // 0x808006C8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_50:
    // 0x808006CC: b           L_80800894
    // 0x808006D0: nop

        goto L_80800894;
    // 0x808006D0: nop

L_808006D4:
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D8: jal         0x80100094
    // 0x808006DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_51;
    // 0x808006DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_51:
    // 0x808006E0: jal         0x800897D0
    // 0x808006E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suexpression_entrypoint_9(rdram, ctx);
        goto after_52;
    // 0x808006E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_52:
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006EC: jal         0x80101E14
    // 0x808006F0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_53;
    // 0x808006F0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_53:
    // 0x808006F4: beq         $v0, $zero, L_80800748
    if (ctx->r2 == 0) {
        // 0x808006F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800748;
    }
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006FC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800700: jal         0x808014F4
    // 0x80800704: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_808014F4_chboilerboss(rdram, ctx);
        goto after_54;
    // 0x80800704: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_54:
    // 0x80800708: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(932, 0X2AB0) << 16);
    // 0x8080070C: addiu       $t6, $t6, 0x2AB0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(932, 0X2AB0));
    // 0x80800710: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800714: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800718: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080071C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800720: jal         0x800BBCB8
    // 0x80800724: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_800BBCB8(rdram, ctx);
        goto after_55;
    // 0x80800724: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_55:
    // 0x80800728: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B14) << 16);
    // 0x8080072C: addiu       $a2, $a2, 0x2B14
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B14));
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: jal         0x80089D18
    // 0x80800738: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_56;
    // 0x80800738: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_56:
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800740: jal         0x80108B04
    // 0x80800744: addiu       $a1, $zero, 0x224
    ctx->r5 = ADD32(0, 0X224);
    func_80108B04(rdram, ctx);
        goto after_57;
    // 0x80800744: addiu       $a1, $zero, 0x224
    ctx->r5 = ADD32(0, 0X224);
    after_57:
L_80800748:
    // 0x80800748: jal         0x80101DDC
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_58;
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80800750: beq         $v0, $zero, L_80800760
    if (ctx->r2 == 0) {
        // 0x80800754: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800760;
    }
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: jal         0x80800F34
    // 0x8080075C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_59;
    // 0x8080075C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_59:
L_80800760:
    // 0x80800760: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B08) << 16);
    // 0x80800764: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80800768: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080076C: addiu       $a2, $a2, 0x2B08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B08));
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800774: jal         0x80089D20
    // 0x80800778: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_60;
    // 0x80800778: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_60:
    // 0x8080077C: b           L_80800894
    // 0x80800780: nop

        goto L_80800894;
    // 0x80800780: nop

L_80800784:
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800788: jal         0x80100094
    // 0x8080078C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_61;
    // 0x8080078C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_61:
    // 0x80800790: jal         0x800897D0
    // 0x80800794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suexpression_entrypoint_9(rdram, ctx);
        goto after_62;
    // 0x80800794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_62:
    // 0x80800798: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8080079C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808007A0: jal         0x80101E14
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_63;
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x808007A8: beq         $v0, $zero, L_8080080C
    if (ctx->r2 == 0) {
        // 0x808007AC: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_8080080C;
    }
    // 0x808007AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808007B0: jal         0x800EE7F8
    // 0x808007B4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_64;
    // 0x808007B4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_64:
    // 0x808007B8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808007BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007C0: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808007C4: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(932, 0X2D38) << 16);
    // 0x808007C8: addiu       $t5, $t5, 0x2D38
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(932, 0X2D38));
    // 0x808007CC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808007D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808007D4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808007D8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x808007DC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x808007E0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808007E4: jal         0x800BBCB8
    // 0x808007E8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800BBCB8(rdram, ctx);
        goto after_65;
    // 0x808007E8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_65:
    // 0x808007EC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B14) << 16);
    // 0x808007F0: addiu       $a2, $a2, 0x2B14
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B14));
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F8: jal         0x80089D18
    // 0x808007FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_66;
    // 0x808007FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_66:
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800804: jal         0x80108B04
    // 0x80800808: addiu       $a1, $zero, 0x225
    ctx->r5 = ADD32(0, 0X225);
    func_80108B04(rdram, ctx);
        goto after_67;
    // 0x80800808: addiu       $a1, $zero, 0x225
    ctx->r5 = ADD32(0, 0X225);
    after_67:
L_8080080C:
    // 0x8080080C: jal         0x80101DDC
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_68;
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
    // 0x80800814: beq         $v0, $zero, L_80800824
    if (ctx->r2 == 0) {
        // 0x80800818: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800824;
    }
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080081C: jal         0x80800F34
    // 0x80800820: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_69;
    // 0x80800820: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_69:
L_80800824:
    // 0x80800824: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B08) << 16);
    // 0x80800828: addiu       $a2, $a2, 0x2B08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B08));
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800830: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800834: jal         0x80089D20
    // 0x80800838: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_70;
    // 0x80800838: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_70:
    // 0x8080083C: b           L_80800894
    // 0x80800840: nop

        goto L_80800894;
    // 0x80800840: nop

L_80800844:
    // 0x80800844: jal         0x800F54E4
    // 0x80800848: nop

    func_800F54E4(rdram, ctx);
        goto after_71;
    // 0x80800848: nop

    after_71:
    // 0x8080084C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800850: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800854: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800858: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080085C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800860: lui         $a2, 0x43AA
    ctx->r6 = S32(0X43AA << 16);
    // 0x80800864: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800868: jal         0x800F4EC8
    // 0x8080086C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_72;
    // 0x8080086C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_72:
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: jal         0x8008A4C8
    // 0x80800878: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _subaddieDll_entrypoint_7(rdram, ctx);
        goto after_73;
    // 0x80800878: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_73:
    // 0x8080087C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(932, 0X2D60) << 16);
    // 0x80800880: addiu       $a3, $a3, 0x2D60
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(932, 0X2D60));
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800888: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080088C: jal         0x80089D50
    // 0x80800890: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_74;
    // 0x80800890: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_74:
L_80800894:
    // 0x80800894: jal         0x808025DC
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808025DC_chboilerboss(rdram, ctx);
        goto after_75;
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_75:
    // 0x8080089C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008A4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x808008A8: jr          $ra
    // 0x808008AC: nop

    return;
    // 0x808008AC: nop

;}
RECOMP_FUNC void func_8080052C_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080052C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800530: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800534: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800538: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080053C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800540: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800544: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80800548: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x8080054C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800550: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800554: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800558: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080055C: jal         0x80100094
    // 0x80800560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800564: addiu       $s0, $v0, 0x154
    ctx->r16 = ADD32(ctx->r2, 0X154);
    // 0x80800568: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8080056C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80800570: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800574: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800578: jal         0x80100094
    // 0x8080057C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080057C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800580: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1172, 0X11F4) << 16);
    // 0x80800584: addiu       $s1, $v1, 0x11F4
    ctx->r17 = ADD32(ctx->r3, (int16_t)RELOC_LO16(1172, 0X11F4));
    // 0x80800588: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8080058C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800590: beq         $t6, $zero, L_80800694
    if (ctx->r14 == 0) {
        // 0x80800594: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800694;
    }
    // 0x80800594: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800598:
    // 0x80800598: jal         0x80800B40
    // 0x8080059C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800B40_chcoderoombits(rdram, ctx);
        goto after_2;
    // 0x8080059C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808005A0: bnel        $v0, $zero, L_80800684
    if (ctx->r2 != 0) {
        // 0x808005A4: lw          $t7, 0xC($s1)
        ctx->r15 = MEM_W(ctx->r17, 0XC);
            goto L_80800684;
    }
    goto skip_0;
    // 0x808005A4: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    skip_0:
    // 0x808005A8: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x808005AC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x808005B0: lbu         $t7, 0x0($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X0);
    // 0x808005B4: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x808005B8: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x808005BC: beql        $t7, $t0, L_808005D0
    if (ctx->r15 == ctx->r8) {
        // 0x808005C0: lbu         $v0, 0xA($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0XA);
            goto L_808005D0;
    }
    goto skip_1;
    // 0x808005C0: lbu         $v0, 0xA($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XA);
    skip_1:
    // 0x808005C4: b           L_80800680
    // 0x808005C8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_80800680;
    // 0x808005C8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x808005CC: lbu         $v0, 0xA($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XA);
L_808005D0:
    // 0x808005D0: beq         $v0, $zero, L_808005EC
    if (ctx->r2 == 0) {
        // 0x808005D4: nop
    
            goto L_808005EC;
    }
    // 0x808005D4: nop

    // 0x808005D8: lbu         $t1, 0x19($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X19);
    // 0x808005DC: bne         $t1, $zero, L_808005EC
    if (ctx->r9 != 0) {
        // 0x808005E0: nop
    
            goto L_808005EC;
    }
    // 0x808005E0: nop

    // 0x808005E4: b           L_80800680
    // 0x808005E8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_80800680;
    // 0x808005E8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_808005EC:
    // 0x808005EC: bne         $v0, $zero, L_80800608
    if (ctx->r2 != 0) {
        // 0x808005F0: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_80800608;
    }
    // 0x808005F0: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x808005F4: lbu         $t2, 0x19($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X19);
    // 0x808005F8: beq         $t2, $zero, L_80800608
    if (ctx->r10 == 0) {
        // 0x808005FC: nop
    
            goto L_80800608;
    }
    // 0x808005FC: nop

    // 0x80800600: b           L_80800680
    // 0x80800604: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_80800680;
    // 0x80800604: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_80800608:
    // 0x80800608: beql        $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x8080060C: addiu       $s6, $zero, 0x1
        ctx->r22 = ADD32(0, 0X1);
            goto L_8080061C;
    }
    goto skip_2;
    // 0x8080060C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    skip_2:
    // 0x80800610: b           L_8080061C
    // 0x80800614: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
        goto L_8080061C;
    // 0x80800614: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80800618: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_8080061C:
    // 0x8080061C: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
    // 0x80800620: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x80800624: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80800628: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8080062C: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x80800630: bnel        $t8, $zero, L_80800658
    if (ctx->r24 != 0) {
        // 0x80800634: lbu         $t9, 0xA($s1)
        ctx->r25 = MEM_BU(ctx->r17, 0XA);
            goto L_80800658;
    }
    goto skip_3;
    // 0x80800634: lbu         $t9, 0xA($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XA);
    skip_3:
    // 0x80800638: jal         0x808004B8
    // 0x8080063C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_808004B8_chcoderoombits(rdram, ctx);
        goto after_3;
    // 0x8080063C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x80800640: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800644: jal         0x8080077C
    // 0x80800648: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080077C_chcoderoombits(rdram, ctx);
        goto after_4;
    // 0x80800648: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8080064C: b           L_80800754
    // 0x80800650: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80800754;
    // 0x80800650: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800654: lbu         $t9, 0xA($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XA);
L_80800658:
    // 0x80800658: bnel        $t9, $zero, L_80800684
    if (ctx->r25 != 0) {
        // 0x8080065C: lw          $t7, 0xC($s1)
        ctx->r15 = MEM_W(ctx->r17, 0XC);
            goto L_80800684;
    }
    goto skip_4;
    // 0x8080065C: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    skip_4:
    // 0x80800660: bne         $s2, $zero, L_80800680
    if (ctx->r18 != 0) {
        // 0x80800664: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800680;
    }
    // 0x80800664: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800668: lbu         $a1, 0x1($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0X1);
    // 0x8080066C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80800670: jal         0x80800D90
    // 0x80800674: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_80800D90_chcoderoombits(rdram, ctx);
        goto after_5;
    // 0x80800674: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_5:
    // 0x80800678: jal         0x800FC660
    // 0x8080067C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_6;
    // 0x8080067C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_6:
L_80800680:
    // 0x80800680: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
L_80800684:
    // 0x80800684: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80800688: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8080068C: bnel        $t7, $zero, L_80800598
    if (ctx->r15 != 0) {
        // 0x80800690: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800598;
    }
    goto skip_5;
    // 0x80800690: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_5:
L_80800694:
    // 0x80800694: lbu         $v0, 0x19($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X19);
    // 0x80800698: bne         $s7, $zero, L_808006B8
    if (ctx->r23 != 0) {
        // 0x8080069C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808006B8;
    }
    // 0x8080069C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006A0: beq         $s6, $zero, L_808006B8
    if (ctx->r22 == 0) {
        // 0x808006A4: nop
    
            goto L_808006B8;
    }
    // 0x808006A4: nop

    // 0x808006A8: beq         $v0, $zero, L_808006B8
    if (ctx->r2 == 0) {
        // 0x808006AC: nop
    
            goto L_808006B8;
    }
    // 0x808006AC: nop

    // 0x808006B0: jal         0x8080091C
    // 0x808006B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8080091C_chcoderoombits(rdram, ctx);
        goto after_7;
    // 0x808006B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_7:
L_808006B8:
    // 0x808006B8: beq         $s7, $zero, L_808006D8
    if (ctx->r23 == 0) {
        // 0x808006BC: nop
    
            goto L_808006D8;
    }
    // 0x808006BC: nop

    // 0x808006C0: bne         $s6, $zero, L_808006D8
    if (ctx->r22 != 0) {
        // 0x808006C4: nop
    
            goto L_808006D8;
    }
    // 0x808006C4: nop

    // 0x808006C8: jal         0x80800998
    // 0x808006CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80800998_chcoderoombits(rdram, ctx);
        goto after_8;
    // 0x808006CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x808006D0: jal         0x80800E28
    // 0x808006D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80800E28_chcoderoombits(rdram, ctx);
        goto after_9;
    // 0x808006D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_9:
L_808006D8:
    // 0x808006D8: bnel        $s6, $zero, L_80800750
    if (ctx->r22 != 0) {
        // 0x808006DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800750;
    }
    goto skip_6;
    // 0x808006DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x808006E0: bnel        $s7, $zero, L_80800750
    if (ctx->r23 != 0) {
        // 0x808006E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800750;
    }
    goto skip_7;
    // 0x808006E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x808006E8: jal         0x808004B8
    // 0x808006EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_808004B8_chcoderoombits(rdram, ctx);
        goto after_10;
    // 0x808006EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_10:
    // 0x808006F0: bnel        $s0, $zero, L_80800750
    if (ctx->r16 != 0) {
        // 0x808006F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800750;
    }
    goto skip_8;
    // 0x808006F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_8:
    // 0x808006F8: jal         0x800FC660
    // 0x808006FC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_11;
    // 0x808006FC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_11:
    // 0x80800700: jal         0x800DA298
    // 0x80800704: addiu       $a0, $zero, 0x668
    ctx->r4 = ADD32(0, 0X668);
    func_800DA298(rdram, ctx);
        goto after_12;
    // 0x80800704: addiu       $a0, $zero, 0x668
    ctx->r4 = ADD32(0, 0X668);
    after_12:
    // 0x80800708: bnel        $v0, $zero, L_80800750
    if (ctx->r2 != 0) {
        // 0x8080070C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800750;
    }
    goto skip_9;
    // 0x8080070C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_9:
    // 0x80800710: jal         0x800DA544
    // 0x80800714: addiu       $a0, $zero, 0x668
    ctx->r4 = ADD32(0, 0X668);
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x80800714: addiu       $a0, $zero, 0x668
    ctx->r4 = ADD32(0, 0X668);
    after_13:
    // 0x80800718: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8080071C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800720: addiu       $a1, $zero, 0x115A
    ctx->r5 = ADD32(0, 0X115A);
    // 0x80800724: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800728: jal         0x8008A208
    // 0x8080072C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x8080072C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80800730: jal         0x800F54E4
    // 0x80800734: nop

    func_800F54E4(rdram, ctx);
        goto after_15;
    // 0x80800734: nop

    after_15:
    // 0x80800738: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080073C: jal         0x800F7F98
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_16;
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800744: b           L_80800750
    // 0x80800748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800750;
    // 0x80800748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080074C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800750:
    // 0x80800750: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800754:
    // 0x80800754: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800758: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080075C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800760: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800764: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800768: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8080076C: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80800770: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80800774: jr          $ra
    // 0x80800778: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800778: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80106A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106A20: jr          $ra
    // 0x80106A24: nop

    return;
    // 0x80106A24: nop

;}
RECOMP_FUNC void suegg_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800368: jal         0x80106790
    // 0x8080036C: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080036C: nop

    after_0:
    // 0x80800370: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800374: jal         0x80100094
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800380: lh          $v0, 0x3A($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X3A);
    // 0x80800384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800388: jr          $ra
    // 0x8080038C: nop

    return;
    // 0x8080038C: nop

;}
RECOMP_FUNC void func_80800000_bsjump(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $a1, 0x3F68
    ctx->r5 = S32(0X3F68 << 16);
    // 0x8080000C: lui         $a2, 0x3F8B
    ctx->r6 = S32(0X3F8B << 16);
    // 0x80800010: ori         $a2, $a2, 0x851F
    ctx->r6 = ctx->r6 | 0X851F;
    // 0x80800014: jal         0x8009D7A4
    // 0x80800018: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    func_8009D7A4(rdram, ctx);
        goto after_0;
    // 0x80800018: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    after_0:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void _suspline_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DE0: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DE0);
    return;
    // 0x80089DE4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_8080009C_suquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x808000A0: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x808000A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x808000A8: sll         $t7, $a2, 3
    ctx->r15 = S32(ctx->r6 << 3);
    // 0x808000AC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x808000B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3370, 0X1054) << 16);
    // 0x808000B4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808000BC: jr          $ra
    // 0x808000C0: lwc1        $f0, 0x1054($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3370, 0X1054));
    return;
    // 0x808000C0: lwc1        $f0, 0x1054($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3370, 0X1054));
;}
RECOMP_FUNC void _badrone_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848C8: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800848C8);
    return;
    // 0x800848CC: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void func_80801410_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801410: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801418: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080141C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801420: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80801424: lbu         $t6, 0x1C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1C);
    // 0x80801428: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080142C: addiu       $t7, $zero, 0x260
    ctx->r15 = ADD32(0, 0X260);
    // 0x80801430: beql        $t6, $zero, L_8080147C
    if (ctx->r14 == 0) {
        // 0x80801434: lbu         $t2, 0x1D($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X1D);
            goto L_8080147C;
    }
    goto skip_0;
    // 0x80801434: lbu         $t2, 0x1D($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1D);
    skip_0:
    // 0x80801438: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8080143C: lh          $t8, 0x28($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X28);
    // 0x80801440: addiu       $a0, $zero, 0xB59
    ctx->r4 = ADD32(0, 0XB59);
    // 0x80801444: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80801448: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8080144C: addiu       $t1, $t0, 0x340
    ctx->r9 = ADD32(ctx->r8, 0X340);
    // 0x80801450: jal         0x800D674C
    // 0x80801454: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80801454: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    after_0:
    // 0x80801458: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080145C: jal         0x800E8C58
    // 0x80801460: lbu         $a0, 0x1C($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1C);
    func_800E8C58(rdram, ctx);
        goto after_1;
    // 0x80801460: lbu         $a0, 0x1C($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1C);
    after_1:
    // 0x80801464: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801468: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080146C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801470: jal         0x800E30E0
    // 0x80801474: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_800E30E0(rdram, ctx);
        goto after_2;
    // 0x80801474: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x80801478: lbu         $t2, 0x1D($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1D);
L_8080147C:
    // 0x8080147C: beql        $t2, $zero, L_8080151C
    if (ctx->r10 == 0) {
        // 0x80801480: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080151C;
    }
    goto skip_1;
    // 0x80801480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801484: jal         0x800D674C
    // 0x80801488: addiu       $a0, $zero, 0xB57
    ctx->r4 = ADD32(0, 0XB57);
    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x80801488: addiu       $a0, $zero, 0xB57
    ctx->r4 = ADD32(0, 0XB57);
    after_3:
    // 0x8080148C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801490: jal         0x800E8C58
    // 0x80801494: lbu         $a0, 0x1D($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1D);
    func_800E8C58(rdram, ctx);
        goto after_4;
    // 0x80801494: lbu         $a0, 0x1D($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1D);
    after_4:
    // 0x80801498: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x8080149C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808014A0: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x808014A4: lh          $t4, 0x24($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X24);
    // 0x808014A8: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x808014AC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x808014B0: addiu       $t7, $t6, 0x340
    ctx->r15 = ADD32(ctx->r14, 0X340);
    // 0x808014B4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x808014B8: lh          $a1, 0xA($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XA);
    // 0x808014BC: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    // 0x808014C0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x808014C4: negu        $at, $a0
    ctx->r1 = SUB32(0, ctx->r4);
    // 0x808014C8: sll         $a0, $at, 2
    ctx->r4 = S32(ctx->r1 << 2);
    // 0x808014CC: jal         0x800E2568
    // 0x808014D0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_800E2568(rdram, ctx);
        goto after_5;
    // 0x808014D0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_5:
    // 0x808014D4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808014D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808014DC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808014E0: jal         0x800E30E0
    // 0x808014E4: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_800E30E0(rdram, ctx);
        goto after_6;
    // 0x808014E4: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x808014E8: addiu       $t0, $zero, 0x448
    ctx->r8 = ADD32(0, 0X448);
    // 0x808014EC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x808014F0: lh          $t1, 0x26($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X26);
    // 0x808014F4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808014F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808014FC: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80801500: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80801504: addiu       $t4, $t3, 0x340
    ctx->r12 = ADD32(ctx->r11, 0X340);
    // 0x80801508: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8080150C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801510: jal         0x800E30E0
    // 0x80801514: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_800E30E0(rdram, ctx);
        goto after_7;
    // 0x80801514: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_7:
    // 0x80801518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080151C:
    // 0x8080151C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801520: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801524: jr          $ra
    // 0x80801528: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801528: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800287FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800287FC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80028800: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80028804: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80028808: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002880C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80028810: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80028814: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80028818: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x8002881C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80028820: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80028824: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80028828: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8002882C: nop

    // 0x80028830: bc1f        L_80028850
    if (!c1cs) {
        // 0x80028834: nop
    
            goto L_80028850;
    }
    // 0x80028834: nop

    // 0x80028838: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002883C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80028840: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80028844: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80028848: b           L_80028858
    // 0x8002884C: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
        goto L_80028858;
    // 0x8002884C: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
L_80028850:
    // 0x80028850: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80028854: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
L_80028858:
    // 0x80028858: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002885C: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x80028860: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80028864: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80028868: nop

    // 0x8002886C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80028870: nop

    // 0x80028874: bc1f        L_80028888
    if (!c1cs) {
        // 0x80028878: nop
    
            goto L_80028888;
    }
    // 0x80028878: nop

    // 0x8002887C: neg.s       $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = -ctx->f4.fl;
    // 0x80028880: b           L_80028888
    // 0x80028884: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
        goto L_80028888;
    // 0x80028884: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
L_80028888:
    // 0x80028888: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002888C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80028890: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80028894: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80028898: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x8002889C: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800288A0: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800288A4: mul.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800288A8: b           L_800288B8
    // 0x800288AC: nop

        goto L_800288B8;
    // 0x800288AC: nop

    // 0x800288B0: b           L_800288B8
    // 0x800288B4: nop

        goto L_800288B8;
    // 0x800288B4: nop

L_800288B8:
    // 0x800288B8: jr          $ra
    // 0x800288BC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800288BC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80803208_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080320C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803210: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1240, 0X3D38) << 16);
    // 0x80803214: jal         0x80105230
    // 0x80803218: addiu       $a1, $a1, 0x3D38
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1240, 0X3D38));
    func_80105230(rdram, ctx);
        goto after_0;
    // 0x80803218: addiu       $a1, $a1, 0x3D38
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1240, 0X3D38));
    after_0:
    // 0x8080321C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803224: jr          $ra
    // 0x80803228: nop

    return;
    // 0x80803228: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887B0: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x800887B0);
    return;
    // 0x800887B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801F5C_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F5C: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80801F60: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x80801F64: beql        $v0, $zero, L_80801F84
    if (ctx->r2 == 0) {
        // 0x80801F68: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80801F84;
    }
    goto skip_0;
    // 0x80801F68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80801F6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801F70: beql        $v0, $at, L_80801F90
    if (ctx->r2 == ctx->r1) {
        // 0x80801F74: lui         $at, 0x442F
        ctx->r1 = S32(0X442F << 16);
            goto L_80801F90;
    }
    goto skip_1;
    // 0x80801F74: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    skip_1:
    // 0x80801F78: b           L_80801F9C
    // 0x80801F7C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
        goto L_80801F9C;
    // 0x80801F7C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80801F80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80801F84:
    // 0x80801F84: jr          $ra
    // 0x80801F88: nop

    return;
    // 0x80801F88: nop

    // 0x80801F8C: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
L_80801F90:
    // 0x80801F90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801F94: jr          $ra
    // 0x80801F98: nop

    return;
    // 0x80801F98: nop

L_80801F9C:
    // 0x80801F9C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801FA0: nop

    // 0x80801FA4: jr          $ra
    // 0x80801FA8: nop

    return;
    // 0x80801FA8: nop

;}
RECOMP_FUNC void func_800B5B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5B88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B5B8C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B5B90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B5B94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B5B98: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B5B9C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800B5BA0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B5BA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B5BA8: addiu       $s2, $s2, -0x7E87
    ctx->r18 = ADD32(ctx->r18, -0X7E87);
    // 0x800B5BAC: addiu       $s1, $s1, -0x5A3E
    ctx->r17 = ADD32(ctx->r17, -0X5A3E);
    // 0x800B5BB0: addiu       $s0, $s0, -0x7EAF
    ctx->r16 = ADD32(ctx->r16, -0X7EAF);
L_800B5BB4:
    // 0x800B5BB4: jal         0x800B5758
    // 0x800B5BB8: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    func_800B5758(rdram, ctx);
        goto after_0;
    // 0x800B5BB8: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    after_0:
    // 0x800B5BBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5BC0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800B5BC4: bne         $s0, $s2, L_800B5BB4
    if (ctx->r16 != ctx->r18) {
        // 0x800B5BC8: sb          $v0, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r2;
            goto L_800B5BB4;
    }
    // 0x800B5BC8: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // 0x800B5BCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B5BD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B5BD4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5BD8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B5BDC: jr          $ra
    // 0x800B5BE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B5BE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800D27A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D27A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D27A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D27AC: jal         0x800D21D0
    // 0x800D27B0: nop

    func_800D21D0(rdram, ctx);
        goto after_0;
    // 0x800D27B0: nop

    after_0:
    // 0x800D27B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D27B8: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x800D27BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D27C0: jr          $ra
    // 0x800D27C4: nop

    return;
    // 0x800D27C4: nop

;}
RECOMP_FUNC void func_800F6A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6A38: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6A3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6A40: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6A44: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6A48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F6A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6A50: jal         0x8008E35C
    // 0x800F6A54: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    player_inWater(rdram, ctx);
        goto after_0;
    // 0x800F6A54: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6A58: bne         $v0, $zero, L_800F6A68
    if (ctx->r2 != 0) {
        // 0x800F6A5C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F6A68;
    }
    // 0x800F6A5C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6A60: b           L_800F6A94
    // 0x800F6A64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F6A94;
    // 0x800F6A64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F6A68:
    // 0x800F6A68: jal         0x800966BC
    // 0x800F6A6C: nop

    func_800966BC(rdram, ctx);
        goto after_1;
    // 0x800F6A6C: nop

    after_1:
    // 0x800F6A70: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x800F6A74: ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
    // 0x800F6A78: and         $t7, $v0, $v1
    ctx->r15 = ctx->r2 & ctx->r3;
    // 0x800F6A7C: bnel        $v1, $t7, L_800F6A90
    if (ctx->r3 != ctx->r15) {
        // 0x800F6A80: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800F6A90;
    }
    goto skip_0;
    // 0x800F6A80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_0:
    // 0x800F6A84: b           L_800F6A90
    // 0x800F6A88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800F6A90;
    // 0x800F6A88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800F6A8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800F6A90:
    // 0x800F6A90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800F6A94:
    // 0x800F6A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6A98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6A9C: jr          $ra
    // 0x800F6AA0: nop

    return;
    // 0x800F6AA0: nop

;}
RECOMP_FUNC void _ncbawaypoint_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089468: syscall     780
    recomp_syscall_handler(rdram, ctx, 0x80089468);
    return;
    // 0x8008946C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800F4C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4C24: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4C28: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F4C2C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800F4C30: lw          $t7, 0x5490($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5490);
    // 0x800F4C34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F4C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4C3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F4C40: jal         0x800F6D24
    // 0x800F4C44: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_800F6D24(rdram, ctx);
        goto after_0;
    // 0x800F4C44: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x800F4C48: beq         $v0, $zero, L_800F4C58
    if (ctx->r2 == 0) {
        // 0x800F4C4C: nop
    
            goto L_800F4C58;
    }
    // 0x800F4C4C: nop

    // 0x800F4C50: b           L_800F4CB0
    // 0x800F4C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4CB0;
    // 0x800F4C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F4C58:
    // 0x800F4C58: jal         0x800F68B8
    // 0x800F4C5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F68B8(rdram, ctx);
        goto after_1;
    // 0x800F4C5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800F4C60: beq         $v0, $zero, L_800F4C70
    if (ctx->r2 == 0) {
        // 0x800F4C64: nop
    
            goto L_800F4C70;
    }
    // 0x800F4C64: nop

    // 0x800F4C68: b           L_800F4CB0
    // 0x800F4C6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4CB0;
    // 0x800F4C6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F4C70:
    // 0x800F4C70: jal         0x800F6CC8
    // 0x800F4C74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F6CC8(rdram, ctx);
        goto after_2;
    // 0x800F4C74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800F4C78: beq         $v0, $zero, L_800F4C88
    if (ctx->r2 == 0) {
        // 0x800F4C7C: nop
    
            goto L_800F4C88;
    }
    // 0x800F4C7C: nop

    // 0x800F4C80: b           L_800F4CB0
    // 0x800F4C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4CB0;
    // 0x800F4C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F4C88:
    // 0x800F4C88: jal         0x8009E6F8
    // 0x800F4C8C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    bs_getCurrentState(rdram, ctx);
        goto after_3;
    // 0x800F4C8C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x800F4C90: addiu       $at, $zero, 0xED
    ctx->r1 = ADD32(0, 0XED);
    // 0x800F4C94: beq         $v0, $at, L_800F4CA4
    if (ctx->r2 == ctx->r1) {
        // 0x800F4C98: addiu       $at, $zero, 0x157
        ctx->r1 = ADD32(0, 0X157);
            goto L_800F4CA4;
    }
    // 0x800F4C98: addiu       $at, $zero, 0x157
    ctx->r1 = ADD32(0, 0X157);
    // 0x800F4C9C: bnel        $v0, $at, L_800F4CB0
    if (ctx->r2 != ctx->r1) {
        // 0x800F4CA0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F4CB0;
    }
    goto skip_0;
    // 0x800F4CA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_800F4CA4:
    // 0x800F4CA4: b           L_800F4CB0
    // 0x800F4CA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4CB0;
    // 0x800F4CA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F4CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F4CB0:
    // 0x800F4CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4CB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F4CB8: jr          $ra
    // 0x800F4CBC: nop

    return;
    // 0x800F4CBC: nop

;}
RECOMP_FUNC void gccubesearch_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B30: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800B34: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800B38: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800B3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B40: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80800B44: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800B48: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800B4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800B50: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800B54: jal         0x800BE554
    // 0x80800B58: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800BE554(rdram, ctx);
        goto after_0;
    // 0x80800B58: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80800B5C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800B60: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800B64: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
    // 0x80800B68: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800B6C: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800B70: bnel        $at, $zero, L_80800C78
    if (ctx->r1 != 0) {
        // 0x80800B74: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_80800C78;
    }
    goto skip_0;
    // 0x80800B74: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x80800B78: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
L_80800B7C:
    // 0x80800B7C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800B80: jal         0x800D2E90
    // 0x80800B84: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    func_800D2E90(rdram, ctx);
        goto after_1;
    // 0x80800B84: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    after_1:
    // 0x80800B88: beq         $v0, $zero, L_80800C58
    if (ctx->r2 == 0) {
        // 0x80800B8C: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800C58;
    }
    // 0x80800B8C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B90: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800B94: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x80800B98: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80800B9C: slt         $at, $t7, $a0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80800BA0: bnel        $at, $zero, L_80800C5C
    if (ctx->r1 != 0) {
        // 0x80800BA4: lw          $v0, 0x50($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X50);
            goto L_80800C5C;
    }
    goto skip_1;
    // 0x80800BA4: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    skip_1:
    // 0x80800BA8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_80800BAC:
    // 0x80800BAC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800BB0: bne         $at, $zero, L_80800C40
    if (ctx->r1 != 0) {
        // 0x80800BB4: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_80800C40;
    }
    // 0x80800BB4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80800BB8: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
L_80800BBC:
    // 0x80800BBC: jal         0x800BDAD4
    // 0x80800BC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800BDAD4(rdram, ctx);
        goto after_2;
    // 0x80800BC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x80800BC4: beq         $v0, $zero, L_80800C24
    if (ctx->r2 == 0) {
        // 0x80800BC8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800C24;
    }
    // 0x80800BC8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800BCC: jal         0x800E9D68
    // 0x80800BD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E9D68(rdram, ctx);
        goto after_3;
    // 0x80800BD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800BD4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800BD8: jal         0x800E9D90
    // 0x80800BDC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800E9D90(rdram, ctx);
        goto after_4;
    // 0x80800BDC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80800BE0: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80800BE4: beq         $at, $zero, L_80800C24
    if (ctx->r1 == 0) {
        // 0x80800BE8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800C24;
    }
    // 0x80800BE8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800BEC: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
L_80800BF0:
    // 0x80800BF0: srl         $t9, $t8, 21
    ctx->r25 = S32(U32(ctx->r24) >> 21);
    // 0x80800BF4: bnel        $s1, $t9, L_80800C18
    if (ctx->r17 != ctx->r25) {
        // 0x80800BF8: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_80800C18;
    }
    goto skip_2;
    // 0x80800BF8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_2:
    // 0x80800BFC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80800C00: beq         $v0, $zero, L_80800C0C
    if (ctx->r2 == 0) {
        // 0x80800C04: nop
    
            goto L_80800C0C;
    }
    // 0x80800C04: nop

    // 0x80800C08: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
L_80800C0C:
    // 0x80800C0C: b           L_80800C88
    // 0x80800C10: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80800C88;
    // 0x80800C10: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800C14: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_80800C18:
    // 0x80800C18: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80800C1C: bnel        $at, $zero, L_80800BF0
    if (ctx->r1 != 0) {
        // 0x80800C20: lw          $t8, 0x10($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X10);
            goto L_80800BF0;
    }
    goto skip_3;
    // 0x80800C20: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    skip_3:
L_80800C24:
    // 0x80800C24: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80800C28: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80800C2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800C30: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800C34: beq         $at, $zero, L_80800BBC
    if (ctx->r1 == 0) {
        // 0x80800C38: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_80800BBC;
    }
    // 0x80800C38: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80800C3C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_80800C40:
    // 0x80800C40: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80800C44: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800C48: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80800C4C: beql        $at, $zero, L_80800BAC
    if (ctx->r1 == 0) {
        // 0x80800C50: lw          $v0, 0x44($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X44);
            goto L_80800BAC;
    }
    goto skip_4;
    // 0x80800C50: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x80800C54: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
L_80800C58:
    // 0x80800C58: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
L_80800C5C:
    // 0x80800C5C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80800C60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800C64: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800C68: beql        $at, $zero, L_80800B7C
    if (ctx->r1 == 0) {
        // 0x80800C6C: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_80800B7C;
    }
    goto skip_5;
    // 0x80800C6C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    skip_5:
    // 0x80800C70: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800C74: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_80800C78:
    // 0x80800C78: beql        $v0, $zero, L_80800C88
    if (ctx->r2 == 0) {
        // 0x80800C7C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800C88;
    }
    goto skip_6;
    // 0x80800C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x80800C80: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80800C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C88:
    // 0x80800C88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C8C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800C90: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800C94: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C98: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800C9C: jr          $ra
    // 0x80800CA0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800CA0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_55(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D78: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D78);
    return;
    // 0x80082D7C: addi        $t0, $zero, 0xDC
    ctx->r8 = ADD32(0, 0XDC);
;}
RECOMP_FUNC void func_80800834_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800834: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800838: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080083C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800840: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800844: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800848: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080084C: jal         0x80100094
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800854: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80800858: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080085C: lbu         $t6, 0x38($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X38);
    // 0x80800860: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80800864: beql        $at, $zero, L_80800A08
    if (ctx->r1 == 0) {
        // 0x80800868: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800A08;
    }
    goto skip_0;
    // 0x80800868: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080086C: jal         0x800EEFD4
    // 0x80800870: addiu       $a0, $v1, 0x18
    ctx->r4 = ADD32(ctx->r3, 0X18);
    func_800EEFD4(rdram, ctx);
        goto after_1;
    // 0x80800870: addiu       $a0, $v1, 0x18
    ctx->r4 = ADD32(ctx->r3, 0X18);
    after_1:
    // 0x80800874: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1392, 0X1ACC) << 16);
    // 0x80800878: lwc1        $f4, 0x1ACC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1392, 0X1ACC));
    // 0x8080087C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800880: nop

    // 0x80800884: bc1tl       L_80800A08
    if (c1cs) {
        // 0x80800888: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800A08;
    }
    goto skip_1;
    // 0x80800888: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8080088C: lbu         $v0, 0x13($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X13);
    // 0x80800890: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800894: beq         $v0, $at, L_808008BC
    if (ctx->r2 == ctx->r1) {
        // 0x80800898: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808008BC;
    }
    // 0x80800898: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080089C: beq         $v0, $at, L_80800910
    if (ctx->r2 == ctx->r1) {
        // 0x808008A0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800910;
    }
    // 0x808008A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808008A4: beq         $v0, $at, L_80800964
    if (ctx->r2 == ctx->r1) {
        // 0x808008A8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800964;
    }
    // 0x808008A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808008AC: beq         $v0, $at, L_808009B8
    if (ctx->r2 == ctx->r1) {
        // 0x808008B0: nop
    
            goto L_808009B8;
    }
    // 0x808008B0: nop

    // 0x808008B4: b           L_80800A08
    // 0x808008B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800A08;
    // 0x808008B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008BC:
    // 0x808008BC: jal         0x800B5BE4
    // 0x808008C0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800B5BE4(rdram, ctx);
        goto after_2;
    // 0x808008C0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_2:
    // 0x808008C4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808008C8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1392, 0X1BB0) << 16);
    // 0x808008CC: addiu       $t7, $t7, 0x1BB0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1392, 0X1BB0));
    // 0x808008D0: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x808008D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808008D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808008E0: jal         0x800BABB8
    // 0x808008E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x808008E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808008E8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1392, 0X1BD8) << 16);
    // 0x808008EC: addiu       $t8, $t8, 0x1BD8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1392, 0X1BD8));
    // 0x808008F0: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x808008F4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808008F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808008FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800900: jal         0x800BABB8
    // 0x80800904: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800904: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800908: b           L_80800A08
    // 0x8080090C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800A08;
    // 0x8080090C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800910:
    // 0x80800910: jal         0x800B5BE4
    // 0x80800914: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800B5BE4(rdram, ctx);
        goto after_5;
    // 0x80800914: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_5:
    // 0x80800918: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080091C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1392, 0X1BB0) << 16);
    // 0x80800920: addiu       $t9, $t9, 0x1BB0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1392, 0X1BB0));
    // 0x80800924: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x80800928: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080092C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800930: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800934: jal         0x800BABB8
    // 0x80800938: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800938: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8080093C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1392, 0X1BE4) << 16);
    // 0x80800940: addiu       $t0, $t0, 0x1BE4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1392, 0X1BE4));
    // 0x80800944: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x80800948: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080094C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800950: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800954: jal         0x800BABB8
    // 0x80800958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8080095C: b           L_80800A08
    // 0x80800960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800A08;
    // 0x80800960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800964:
    // 0x80800964: jal         0x800B5BE4
    // 0x80800968: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800B5BE4(rdram, ctx);
        goto after_8;
    // 0x80800968: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_8:
    // 0x8080096C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800970: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1392, 0X1BB0) << 16);
    // 0x80800974: addiu       $t1, $t1, 0x1BB0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1392, 0X1BB0));
    // 0x80800978: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x8080097C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800980: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800984: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800988: jal         0x800BABB8
    // 0x8080098C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_9;
    // 0x8080098C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80800990: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1392, 0X1BF0) << 16);
    // 0x80800994: addiu       $t2, $t2, 0x1BF0
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1392, 0X1BF0));
    // 0x80800998: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x8080099C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808009A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808009A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808009A8: jal         0x800BABB8
    // 0x808009AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_10;
    // 0x808009AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x808009B0: b           L_80800A08
    // 0x808009B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800A08;
    // 0x808009B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009B8:
    // 0x808009B8: jal         0x800B5BE4
    // 0x808009BC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800B5BE4(rdram, ctx);
        goto after_11;
    // 0x808009BC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_11:
    // 0x808009C0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808009C4: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1392, 0X1BB0) << 16);
    // 0x808009C8: addiu       $t3, $t3, 0x1BB0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1392, 0X1BB0));
    // 0x808009CC: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x808009D0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808009D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808009DC: jal         0x800BABB8
    // 0x808009E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_12;
    // 0x808009E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x808009E4: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(1392, 0X1C00) << 16);
    // 0x808009E8: addiu       $t4, $t4, 0x1C00
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(1392, 0X1C00));
    // 0x808009EC: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x808009F0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808009F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808009F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808009FC: jal         0x800BABB8
    // 0x80800A00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_13;
    // 0x80800A00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80800A04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A08:
    // 0x80800A08: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A0C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800A10: jr          $ra
    // 0x80800A14: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800A14: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80107388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010738C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107390: jal         0x80100368
    // 0x80107394: nop

    func_80100368(rdram, ctx);
        goto after_0;
    // 0x80107394: nop

    after_0:
    // 0x80107398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010739C: lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X44);
    // 0x801073A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801073A4: jr          $ra
    // 0x801073A8: nop

    return;
    // 0x801073A8: nop

;}
RECOMP_FUNC void func_80013788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013788: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8001378C: addiu       $t0, $t0, -0x3370
    ctx->r8 = ADD32(ctx->r8, -0X3370);
    // 0x80013790: jr          $ra
    // 0x80013794: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    return;
    // 0x80013794: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
;}
RECOMP_FUNC void _chprisonbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FE8: syscall     491
    recomp_syscall_handler(rdram, ctx, 0x80086FE8);
    return;
    // 0x80086FEC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chchompaslunch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1548, 0X3E0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x3E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1548, 0X3E0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x3E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1548, 0X3E0));
;}
RECOMP_FUNC void chbaddieDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000A8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808000AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808000B0: lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X4);
    // 0x808000B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808000BC: blezl       $v1, L_80800208
    if (SIGNED(ctx->r3) <= 0) {
        // 0x808000C0: sb          $zero, 0x4($s0)
        MEM_B(0X4, ctx->r16) = 0;
            goto L_80800208;
    }
    goto skip_0;
    // 0x808000C0: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    skip_0:
    // 0x808000C4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_808000C8:
    // 0x808000C8: addu        $v0, $t6, $s1
    ctx->r2 = ADD32(ctx->r14, ctx->r17);
    // 0x808000CC: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x808000D0: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x808000D4: beq         $at, $zero, L_808001F0
    if (ctx->r1 == 0) {
        // 0x808000D8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808001F0;
    }
    // 0x808000D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(716, 0X220) << 16);
    // 0x808000E0: addu        $at, $at, $t7
    gpr jr_addend_808000E8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808000E4: lw          $t7, 0x220($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(716, 0X220));
    // 0x808000E8: jr          $t7
    // 0x808000EC: nop

    switch (jr_addend_808000E8 >> 2) {
        case 0: goto L_808000F0; break;
        case 1: goto L_80800108; break;
        case 2: goto L_80800124; break;
        case 3: goto L_80800144; break;
        case 4: goto L_80800164; break;
        case 5: goto L_80800188; break;
        case 6: goto L_808001B8; break;
        default: switch_error(__func__, 0x808000E8, 0x80800220);
    }
    // 0x808000EC: nop

L_808000F0:
    // 0x808000F0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x808000F4: jalr        $t9
    // 0x808000F8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x808000F8: nop

    after_0:
    // 0x808000FC: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x80800100: b           L_808001F4
    // 0x80800104: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x80800104: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_80800108:
    // 0x80800108: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8080010C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80800110: jalr        $t9
    // 0x80800114: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80800114: nop

    after_1:
    // 0x80800118: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x8080011C: b           L_808001F4
    // 0x80800120: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x80800120: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_80800124:
    // 0x80800124: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800128: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8080012C: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80800130: jalr        $t9
    // 0x80800134: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80800134: nop

    after_2:
    // 0x80800138: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x8080013C: b           L_808001F4
    // 0x80800140: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x80800140: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_80800144:
    // 0x80800144: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800148: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8080014C: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80800150: jalr        $t9
    // 0x80800154: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80800154: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    after_3:
    // 0x80800158: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x8080015C: b           L_808001F4
    // 0x80800160: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x80800160: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_80800164:
    // 0x80800164: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800168: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8080016C: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80800170: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x80800174: jalr        $t9
    // 0x80800178: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80800178: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    after_4:
    // 0x8080017C: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x80800180: b           L_808001F4
    // 0x80800184: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x80800184: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_80800188:
    // 0x80800188: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x8080018C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80800190: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80800194: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x80800198: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    // 0x8080019C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808001A0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x808001A4: jalr        $t9
    // 0x808001A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x808001A8: nop

    after_5:
    // 0x808001AC: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x808001B0: b           L_808001F4
    // 0x808001B4: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x808001B4: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_808001B8:
    // 0x808001B8: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x808001BC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x808001C0: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x808001C4: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x808001C8: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    // 0x808001CC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808001D0: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x808001D4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808001D8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x808001DC: jalr        $t9
    // 0x808001E0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x808001E0: nop

    after_6:
    // 0x808001E4: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x808001E8: b           L_808001F4
    // 0x808001EC: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x808001EC: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_808001F0:
    // 0x808001F0: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_808001F4:
    // 0x808001F4: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x808001F8: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808001FC: bnel        $at, $zero, L_808000C8
    if (ctx->r1 != 0) {
        // 0x80800200: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_808000C8;
    }
    goto skip_1;
    // 0x80800200: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80800204: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
L_80800208:
    // 0x80800208: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080020C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800210: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800214: jr          $ra
    // 0x80800218: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800218: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080021C: nop

;}
RECOMP_FUNC void func_8080025C_chLagoonInnBlockedWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800260: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800264: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080026C: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80800270: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800274: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800278: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080027C: jal         0x800EE7F8
    // 0x80800280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800284: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800288: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080028C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800290: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2020, 0X3E8) << 16);
    // 0x80800294: lwc1        $f16, 0x3E8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2020, 0X3E8));
    // 0x80800298: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080029C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2020, 0X528) << 16);
    // 0x808002A0: addiu       $t6, $t6, 0x528
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2020, 0X528));
    // 0x808002A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002A8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x808002AC: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808002B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002B8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808002BC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x808002C0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808002C4: jal         0x800BBCB8
    // 0x808002C8: nop

    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x808002C8: nop

    after_1:
    // 0x808002CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2020, 0X3EC) << 16);
    // 0x808002D0: lwc1        $f6, 0x3EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2020, 0X3EC));
    // 0x808002D4: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808002D8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2020, 0X4C8) << 16);
    // 0x808002DC: addiu       $t7, $t7, 0x4C8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2020, 0X4C8));
    // 0x808002E0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808002E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808002E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002F0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x808002F4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808002F8: jal         0x800BBCB8
    // 0x808002FC: nop

    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x808002FC: nop

    after_2:
    // 0x80800300: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2020, 0X54C) << 16);
    // 0x80800304: addiu       $t8, $t8, 0x54C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2020, 0X54C));
    // 0x80800308: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8080030C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800310: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800314: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800318: jal         0x800BBCB8
    // 0x8080031C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x8080031C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_3:
    // 0x80800320: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2020, 0X3F0) << 16);
    // 0x80800324: lwc1        $f10, 0x3F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2020, 0X3F0));
    // 0x80800328: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x8080032C: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x80800330: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x80800334: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80800338: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8080033C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800348: addiu       $a2, $zero, -0x28
    ctx->r6 = ADD32(0, -0X28);
    // 0x8080034C: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x80800350: jal         0x80109704
    // 0x80800354: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80109704(rdram, ctx);
        goto after_4;
    // 0x80800354: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80800358: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2020, 0X514) << 16);
    // 0x8080035C: addiu       $a2, $a2, 0x514
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2020, 0X514));
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x80089D18
    // 0x80800368: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800368: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x8080036C: jal         0x800FFAB0
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800374: addiu       $a0, $zero, 0x488
    ctx->r4 = ADD32(0, 0X488);
    // 0x80800378: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080037C: jal         0x80101180
    // 0x80800380: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80800380: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800384: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800388: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8080038C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800390: jr          $ra
    // 0x80800394: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800394: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_808000BC_chpumproomswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808000C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000D4: beq         $a1, $at, L_80800138
    if (ctx->r5 == ctx->r1) {
        // 0x808000D8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800138;
    }
    // 0x808000D8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808000DC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000E0: bnel        $a1, $at, L_8080014C
    if (ctx->r5 != ctx->r1) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080014C;
    }
    goto skip_0;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808000E8: lhu         $t7, 0x76($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X76);
    // 0x808000EC: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808000F8: bne         $t8, $at, L_80800108
    if (ctx->r24 != ctx->r1) {
        // 0x808000FC: addiu       $v0, $zero, 0x7B8
        ctx->r2 = ADD32(0, 0X7B8);
            goto L_80800108;
    }
    // 0x808000FC: addiu       $v0, $zero, 0x7B8
    ctx->r2 = ADD32(0, 0X7B8);
    // 0x80800100: b           L_80800108
    // 0x80800104: addiu       $v0, $zero, 0x7B9
    ctx->r2 = ADD32(0, 0X7B9);
        goto L_80800108;
    // 0x80800104: addiu       $v0, $zero, 0x7B9
    ctx->r2 = ADD32(0, 0X7B9);
L_80800108:
    // 0x80800108: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8080010C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80800110: jal         0x801032B0
    // 0x80800114: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    func_801032B0(rdram, ctx);
        goto after_0;
    // 0x80800114: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    after_0:
    // 0x80800118: jal         0x800DA298
    // 0x8080011C: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080011C: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    after_1:
    // 0x80800120: beq         $v0, $zero, L_80800148
    if (ctx->r2 == 0) {
        // 0x80800124: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800148;
    }
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x80103110
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800130: b           L_8080014C
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080014C;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800138:
    // 0x80800138: addiu       $a0, $zero, 0x3D2
    ctx->r4 = ADD32(0, 0X3D2);
    // 0x8080013C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800140: jal         0x80101180
    // 0x80800144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x80800144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_80800148:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080014C:
    // 0x8080014C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800150: jal         0x80085820
    // 0x80800154: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800154: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void func_80800280_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800288: jal         0x800DA298
    // 0x8080028C: nop

    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080028C: nop

    after_0:
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
